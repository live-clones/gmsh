
#if defined(_OPENMP)
#include <omp.h>
#endif
#include <set>
#include <vector>
#include "GmshDefines.h"
#include "Context.h"
#include "GModel.h"
#include "MElement.h"
#include "MQuadrangle.h"
#include "GFace.h"
#include "MVertex.h"
#include "MEdge.h"
#include "meshWinslow2d.h"
#include "meshGFaceOptimize.h"

static std::vector<MVertex*> build_crown (MVertex *v, const std::vector<MElement*> &_e){
  //  printf("building crown %lu %lu\n",v->getNum(),_e.size());
  std::vector<MEdge> veds;
  std::set<MVertex*> connected;
  for (size_t i=0;i<_e.size();i++){
    //    printf("%lu %lu %lu %lu \n",_e[i]->getVertex(0)->getNum(),_e[i]->getVertex(1)->getNum(),_e[i]->getVertex(2)->getNum(),_e[i]->getVertex(3)->getNum());
    for (size_t j=0;j<_e[i]->getNumEdges();j++){
      MEdge ed = _e[i]->getEdge(j);
      if (ed.getVertex(0) != v && ed.getVertex(1) != v)	veds.push_back(ed);
      else if (ed.getVertex(0) == v)connected.insert(ed.getVertex(1));
      else if (ed.getVertex(1) == v)connected.insert(ed.getVertex(0));      
    }
  }
  std::vector<std::vector<MVertex *> > vsorted;
  SortEdgeConsecutive(veds, vsorted);

  // start with a corner
  std::vector<MVertex *> result;
  vsorted[0].resize( vsorted[0].size()-1);
  if (connected.find(vsorted[0][0]) != connected.end()){
    for (size_t i=0;i<vsorted[0].size();i++)result.push_back(vsorted[0][(i+1)%vsorted[0].size()]);
  }
  else result = vsorted[0];

  //  for (size_t i=0;i<result.size();i++)
  //    printf("%lu ",result[i]->getNum());
  //  printf("\n");

  //  getchar();
  return result;
}

int classOfStencil(const std::vector<MElement *> &e) {
  size_t ntri = 0, nqua = 0, nelse = 0;
  for (size_t i=0;i<e.size();i++){
    if (e[i]->getTypeForMSH() == MSH_TRI_3)ntri++;
    else if (e[i]->getTypeForMSH() == MSH_QUA_4)nqua++;
    else nelse++;
  }
  if (nqua == e.size())return 1;
  if (ntri  == e.size())return 2;
  if (ntri + nqua == e.size())return 3;
  if (nelse != 0) return 4;
  return 5;
}

class winslowStencil{
public:
  int type;
  MVertex * center;
  std::vector<MVertex *> stencil;
  const std::vector<MElement*> elements;
  std::vector<SVector3> ptsStencil;
  winslowStencil (MVertex *v,  const std::vector<MElement*> &_e) : elements (_e)
  {
    type = classOfStencil(_e);
    if (type == 1 && (_e.size() == 4 || _e.size() == 3 || _e.size() == 5 || _e.size() == 6 || _e.size() == 7)){
      stencil  = build_crown (v, _e);
      ptsStencil.resize(stencil.size());
      center = v;            
    }
  }  
  SPoint3 new3dPositionCentroid (){
    double x=0,y=0,z=0;
    for (size_t i=0;i<stencil.size();i++){
      x += stencil[i]->x();
      y += stencil[i]->y();
      z += stencil[i]->z();
    }
    x /= stencil.size();
    y /= stencil.size();
    z /= stencil.size();
    return SPoint3(x,y,z);
  }

  SPoint3 new3dPosition4quads (){
    for (size_t i=0;i<stencil.size();i++)ptsStencil[i] = SVector3(stencil[i]->x(),stencil[i]->y(),stencil[i]->z());
    /* Stencil:
     *   6---1---4
     *   |   |   |
     *   2--- ---0
     *   |   |   |
     *   7---3---5
     */
    
    //      const int order[8] = {4,1,6,2,7,3,5,0};
    const int order[8] = {7,1,3,5,0,6,2,4};
   
    /* warning: 2D stencil but 3D coordinates */
    double hx = 1.;
    double hy = 1.; 
    
    /* 1. Compute the winslow coefficients (alpha_i, beta_i in the Karman paper) */
    /*    a. Compute first order derivatives of the position */
    SVector3 r_i[2];
    r_i[0] = 1./hx * (ptsStencil[order[0]] - ptsStencil[order[2]]);
    r_i[1] = 1./hy * (ptsStencil[order[1]] - ptsStencil[order[3]]);
    /*    b. Compute the alpha_i coefficients */
    double alpha_0 = dot(r_i[1],r_i[1]);
    double alpha_1 = dot(r_i[0],r_i[0]);
    /*    c. Compute the beta coefficient */
    double beta =  dot(r_i[0],r_i[1]);
    
    /* cross derivative */
    SVector3 u_xy = 1./(4.*hx*hy) * ((ptsStencil[order[4]]-ptsStencil[order[6]]) + (ptsStencil[order[7]]-ptsStencil[order[5]]));
    
    /* 2. Compute the "winslow new position" */
    double denom = 2. * alpha_0 / (hx*hx) + 2. * alpha_1 / (hy*hy);
    SVector3 newPos = 1. / denom * (
				    alpha_0/(hx*hx) * (ptsStencil[order[0]] + ptsStencil[order[2]])
				    + alpha_1/(hy*hy) * (ptsStencil[order[1]] + ptsStencil[order[3]])
				    - 2. * beta * u_xy
				    );
    SPoint3 p (newPos.x(),newPos.y(),newPos.z());
    return p;
  }
  
  double smooth (GEdge *ge){    
    SPoint3 p;    
    if (type == 1 && stencil.size() == 8){
      p = new3dPosition4quads();
    }
    else {
      return 0;
    }
    double u ; center->getParameter(0,u);

    GPoint gp = ge->closestPoint(p,u);
    if (!gp.succeeded()){
      return 0;
    }
    double dx = sqrt ((gp.x()-center->x())*(gp.x()-center->x())+
		      (gp.y()-center->y())*(gp.y()-center->y())+
		      (gp.z()-center->z())*(gp.z()-center->z()));			
    center->setXYZ(gp.x(),gp.y(),gp.z());
    center->setParameter(0,gp.u());
    center->setParameter(1,gp.v());
    return dx;
  }


  double smooth (GFace *gf){
    SPoint3 p;    
    if (type == 1 && stencil.size() == 8){
      p = new3dPosition4quads();
    }
    else if (type == 1 && stencil.size() == 6){
      p = new3dPositionCentroid();
    }
    else if (type == 1 && stencil.size() == 10){
      p = new3dPositionCentroid();
    }
    else {
      return 0;
    }
    double uv[2] ; center->getParameter(0,uv[0]);center->getParameter(1,uv[1]);
    double dx;
    if (gf->geomType() == GEntity::Plane){
      dx = sqrt ((p.x()-center->x())*(p.x()-center->x())+
		 (p.y()-center->y())*(p.y()-center->y())+
		 (p.z()-center->z())*(p.z()-center->z()));			
      center->setXYZ(p.x(),p.y(),p.z());
    }
    else {
      GPoint gp = gf->closestPoint(p,uv);
      if (!gp.succeeded()){
	printf("coucou\n");
	return 0;
      }
      dx = sqrt ((gp.x()-center->x())*(gp.x()-center->x())+
		 (gp.y()-center->y())*(gp.y()-center->y())+
		 (gp.z()-center->z())*(gp.z()-center->z()));			
      center->setXYZ(gp.x(),gp.y(),gp.z());
      center->setParameter(0,gp.u());
      center->setParameter(1,gp.v());
    }
    return dx;
  }
};


void meshWinslow1d (GEdge * ge, int nIter, Field *f) {
  nIter = 1;
  std::vector<GFace*> faces = ge->faces();
  if (faces.size() != 2)return;
  
  v2t_cont adj;
  buildVertexToElement(faces[0]->triangles, adj);
  buildVertexToElement(faces[0]->quadrangles, adj);
  buildVertexToElement(faces[1]->triangles, adj);
  buildVertexToElement(faces[1]->quadrangles, adj);
  
  std::vector<winslowStencil> stencils;
  
  for (size_t i = 0; i<ge->mesh_vertices.size();i++){
    MEdgeVertex *v = dynamic_cast<MEdgeVertex*> (ge->mesh_vertices[i]);
    if (v){
      const std::vector<MElement *> &e = adj[v];
      winslowStencil st (v, e);
      stencils.push_back(st);      
    }
  }

  double dx0;
  for (int i=0;i<nIter;i++){
    double dx = 0;
    for (size_t j=0;j<stencils.size();j++){
      dx += stencils[j].smooth(ge);
    }
    if (i == 0)dx0 = dx;
    if (dx < .1*dx0) break;
  }     
}

void removeFromAdjacencyList (MElement*e,  v2t_cont &adj){

  //  printf("element %lu (%lu,%lu,%lu,%lu)\n",e->getNum(),e->getVertex(0)->getNum(),
  //	 e->getVertex(1)->getNum(), e->getVertex(2)->getNum(), e->getVertex(3)->getNum());
  for (size_t i=0;i<e->getNumVertices();i++){
    v2t_cont::iterator iti = adj.find(e->getVertex(i));
    if (iti != adj.end()){
      //      int index = -1;
      //      for (size_t j=0;j<iti->second.size();j++){
      //	if (iti->second[j] == e){
      //	  index = j;
      //	}
      //      }      
      //      printf("%lu %d ",iti->second.size(), index);
      iti->second.erase(std::remove(iti->second.begin(),iti->second.end(),e),iti->second.end());
      //      printf("%lu\n ",iti->second.size());
    }
  }
}

void addToAdjacencyList (MElement*e,  v2t_cont &adj){
  for (size_t i=0;i<e->getNumVertices();i++){
    v2t_cont::iterator iti = adj.find(e->getVertex(i));
    if (iti != adj.end())iti->second.push_back(e);
    else {
      std::vector<MElement*> els;
      els.push_back(e);
      adj[e->getVertex(i)] =els;
    }
  }
}

int removeValence6Nodes(GFace * gf, v2t_cont &adj) {

  int nbDone=0;
  v2t_cont::iterator it = adj.begin();
  while(it != adj.end()) {
    MVertex *v = it->first;
    if (v->onWhat() == gf) {
      const std::vector<MElement *> e = it->second;
      if (e.size() == 6){
	winslowStencil st (v, e);
	std::vector<MVertex *> crown = st.stencil;
	int valences [12];
	int n4 = 0;
	int n3 = 0;
	int index3[12];
	for (int i=0;i<12;i++){
	  v2t_cont::iterator iti = adj.find(crown[i]);
	  if (iti != adj.end()){
	    valences[i] = iti->second.size();
	    if (valences[i] == 3) index3[n3++] = i;
	    if (valences[i] == 4) n4++;
	    //	    printf("%d ",valences[i]);
	  }
	}
	if (n3 + n4 == 12 && n3 < 3){
	  int start = index3[0];
	  double uv[2] = {0,0};
	  double x12 = 0.5*(v->x() + crown[(start+3)%12]->x());
	  double y12 = 0.5*(v->y() + crown[(start+3)%12]->y());
	  double z12 = 0.5*(v->z() + crown[(start+3)%12]->z());
	  double x13 = 0.5*(v->x() + crown[(start+9)%12]->x());
	  double y13 = 0.5*(v->y() + crown[(start+9)%12]->y());
	  double z13 = 0.5*(v->z() + crown[(start+9)%12]->z());
	  GPoint p0 = gf->closestPoint(SPoint3(x12,y12,z12),uv);
	  GPoint p1 = gf->closestPoint(SPoint3(x13,y13,z13),uv);
      
	  MFaceVertex *v12 = new MFaceVertex (p0.x(),p0.y(),p0.z(),gf,p0.u(),p0.v()); 
	  MFaceVertex *v13 = new MFaceVertex (p1.x(),p1.y(),p1.z(),gf,p1.u(),p1.v()); 
	  
	  if (n3 == 1 || (index3[1]-index3[0])%2 == 0){
	    gf->mesh_vertices.push_back(v12);
	    gf->mesh_vertices.push_back(v13);
	    int t[8][4] = {
	      {0,1,12,14},
	      {1,2,3,12},
	      {12,3,4,5},
	      {14,12,5,6},
	      {13,14,6,7},
	      {9,13,7,8},
	      {10,11,13,9},
	      {11,0,14,13}
	    };
	    crown.push_back(v12);
	    crown.push_back(v13);
	    crown.push_back(v);
	    
	    for (int i=0;i<6;i++){
	      MQuadrangle *q = dynamic_cast<MQuadrangle*>(e[i]);	      
	      if (!q)Msg::Error ("A non quad is present in the list of quad of face %lu",gf->tag());
	      gf->quadrangles.erase (std::remove(gf->quadrangles.begin(),gf->quadrangles.end(),q),gf->quadrangles.end());
	      removeFromAdjacencyList (e[i],  adj);
	    }	    	    
	    for (int i=0;i<8;i++){
	      int index0 = t[i][0] < 12 ? (start+ t[i][0])%12 : t[i][0];
	      int index1 = t[i][1] < 12 ? (start+ t[i][1])%12 : t[i][1];
	      int index2 = t[i][2] < 12 ? (start+ t[i][2])%12 : t[i][2];
	      int index3 = t[i][3] < 12 ? (start+ t[i][3])%12 : t[i][3];
	      //	      printf("%lu %d %d %d %d\n",crown.size(),index0,index1,index2,index3);
	      MQuadrangle *q = new MQuadrangle (crown[index0],crown[index1],crown[index2],crown[index3]);
	      gf->quadrangles.push_back(q);
	      addToAdjacencyList (q,  adj);
	    }
	    nbDone++;
	    //	    break;
	  }
	  else if (n3 == 2){
	  }
	}
	else {
	  printf ("valence 6 node %lu found with %d vertices of valence 3 and %d vertices of valence 4 \n",v->getNum(),n3,n4);
	}
      }
    }
    ++it;    
  }
  if (nbDone)Msg::Info ("Removing %d valence 6 nodes ", nbDone);
  return nbDone;
}


void meshWinslow2d (GFace * gf, int nIter, Field *f, bool remove) {

  nIter = 1;
  v2t_cont adj;
  buildVertexToElement(gf->triangles, adj);
  buildVertexToElement(gf->quadrangles, adj);
  v2t_cont::iterator it = adj.begin();

  if (remove) removeValence6Nodes(gf, adj);

  std::vector<winslowStencil> stencils;

  while(it != adj.end()) {
    MVertex *v = it->first;
    if (v->onWhat() == gf) {      
      const std::vector<MElement *> &e = it->second;
      winslowStencil st (v, e);
      stencils.push_back(st);
    }
    ++it;
  }
  
  double dx0;
  for (int i=0;i<nIter;i++){
    double dx = 0;
    for (size_t j=0;j<stencils.size();j++){
      dx += stencils[j].smooth(gf);
    }
    if (i == 0)dx0 = dx;
    if (dx < .1*dx0) break;
  }  
}



void meshWinslow2d (GModel * gm, int nIter, Field *f) {
  std::vector<GFace *> temp;
  temp.insert(temp.begin(), gm->firstFace(), gm->lastFace());
  std::vector<GEdge *> tempe;
  tempe.insert(tempe.begin(), gm->firstEdge(), gm->lastEdge());
  
  Msg::Info ("Winslow Smoothing the mesh");

  for (int NIT = 0;NIT<4;NIT++){  
    for (size_t i=0;i<tempe.size();i++)
      meshWinslow1d (tempe[i],nIter/4, f);    

#if defined(_OPENMP)
#pragma omp parallel for schedule(dynamic)
#endif
    for (size_t i=0;i<temp.size();i++){
      meshWinslow2d (temp[i],nIter/4, f, true);
    }
  }
}
