
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
#include "Field.h"

static std::vector<MVertex*> build_crown (MVertex *v, const std::vector<MElement*> &_e){
  //  printf("building crown %lu %lu\n",v->getNum(),_e.size());
  std::vector<MEdge> veds;
  std::set<MVertex*> connected;
  for (size_t i=0;i<(size_t)_e.size();i++){
    //    printf("%lu %lu %lu %lu \n",_e[i]->getVertex(0)->getNum(),_e[i]->getVertex(1)->getNum(),_e[i]->getVertex(2)->getNum(),_e[i]->getVertex(3)->getNum());
    for (size_t j=0;j<(size_t)_e[i]->getNumEdges();j++){
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
  if (vsorted[0].size() > 1) vsorted[0].resize( vsorted[0].size()-1);
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
    return 0;
    if (stencil.empty())return 0;
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
    if (stencil.empty())return 0;
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


int removeNodeWithTwoTriangles(GFace * gf, v2t_cont &adj) {

  int nbDone=0;
  v2t_cont::iterator it = adj.begin();
  while(it != adj.end()) {
    MVertex *v = it->first;
    if (v->onWhat() == gf) {
      const std::vector<MElement *> e = it->second;
      int ntri = 0;
      int nqua = 0;
      int indextri[12];
      for (size_t i=0;i<e.size();i++){
	if (e[i]->getTypeForMSH() == MSH_TRI_3)indextri[ntri++] = i;
	else if (e[i]->getTypeForMSH() == MSH_QUA_4)indextri[nqua++] = i;
      }
      if (ntri == 2 && nqua == 3){
	winslowStencil st (v, e);	
      }
    }
  }
  return nbDone;
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

  if (gf->triangles.size())return;
  Msg::Info ("Winslow Smoothing face %lu",gf->tag());
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

static MVertex* next_vertex (GFace *gf, MVertex *prev, MVertex *current, v2t_cont &adj){
  v2t_cont::iterator it = adj.find(current);
  const std::vector<MElement *> e = it->second;
  if (current->onWhat() != gf || e.size() != 4)return NULL;
  winslowStencil st (current, e);
  std::vector<MVertex *> &crown = st.stencil;
  for (size_t i=0;i<crown.size();i++){
    if (crown[i] == prev)return crown[(i+4)%8];    
  }
  return NULL;
}

static void printEdge (int num, MVertex *v1, MVertex *v2, FILE *f){
  fprintf(f,"SL(%g,%g,%g,%g,%g,%g) {%d,%d};\n",
	  v1->x(),v1->y(),v1->z(),
	  v2->x(),v2->y(),v2->z(),num,num);
}

static void printVertex (int num, MVertex *v1, FILE *f){
  fprintf(f,"SP(%g,%g,%g) {%d};\n",
	  v1->x(),v1->y(),v1->z(),num);
}


static std::vector<MVertex*> buildBoundary (std::set<MElement*> &_e){
  std::set<MEdge,MEdgeLessThan> eds;
  for (std::set<MElement*>::iterator ite = _e.begin(); ite != _e.end();++ite){
    for (size_t j=0;j<(size_t)(*ite)->getNumEdges();j++){
      MEdge ed =(*ite)->getEdge(j);
      std::set<MEdge,MEdgeLessThan> :: iterator it = eds.find(ed);
      if (it == eds.end())eds.insert(ed);
      else eds.erase(it);
    }
  }
  std::vector<MEdge> veds;
  veds.insert(veds.begin(),eds.begin(),eds.end());
  std::vector<std::vector<MVertex *> > vsorted;
  SortEdgeConsecutive(veds, vsorted);
  return vsorted[0];
}

static MVertex* countSing (  std::set<MElement*> &cavity,
			     std::map<MVertex *, int, MVertexPtrLessThan> &sing,
			     int &nb){
  nb = 0;
  MVertex *theSing = NULL;
  for (std::map<MVertex *, int, MVertexPtrLessThan>::iterator it = sing.begin(); it != sing.end() ; ++it){
    double uvw[3];
    //    GVertex *gv = dynamic_cast<GVertex*> (it->first->onWhat());
    //    if (gv){
    //      if (gv->tag() == 24)printf("%12.5E %12.5E  vs %12.5E %12.5E \n",
    //				 it->first->x(),it->first->y(), gv->x(),gv->y());
    //    }
    double xyz[3] = {it->first->x(),it->first->y(),it->first->z()};
    for (std::set<MElement*>::iterator ite = cavity.begin(); ite != cavity.end(); ++ite){
      (*ite)->xyz2uvw(xyz,uvw);
      if ((*ite)->isInside(uvw[0],uvw[1],uvw[2])){
	theSing = it->first;
	nb++;
      }
    }
  }
  if (nb == 1) return theSing;
  return NULL;
}

static int nbSing (std::vector<MVertex*> &bnd,
		   std::set<MElement*> & cavity,
		   v2t_cont &adj){
  int n = 0;
  std::set<MVertex*, MVertexPtrLessThan> internal;
  for (std::set<MElement*>::iterator it = cavity.begin(); it != cavity.end() ; ++it)
    for (size_t i=0;i<(*it)->getNumVertices(); i++)
      if (std::find(bnd.begin(), bnd.end(),(*it)->getVertex(i))==bnd.end())
	internal.insert((*it)->getVertex(i));

  for (std::set<MVertex*, MVertexPtrLessThan>::iterator it = internal.begin(); it != internal.end() ; ++it){
    v2t_cont::iterator itvv = adj.find(*it);
    if (itvv->second.size() != 4)n++;
  }
  return n;

}

static bool cavityMeshable (v2t_cont &adj,
			    std::vector<MVertex*> &bnd,
			    std::set<MElement*> & cavity,
			    int index){
  std::vector<int> corners;
  for (size_t i=0;i<bnd.size();i++){
    v2t_cont::iterator it = adj.find(bnd[i]);
    int outside = 0;
    for (size_t j=0;j<it->second.size();j++){
      if (cavity.find(it->second[j]) == cavity.end()) outside ++;
    }
    if (outside == 3 && bnd[i]->onWhat()->dim() ==2)corners.push_back(i);
    else if (outside == 1 && bnd[i]->onWhat()->dim() ==1)corners.push_back(i);
    else if (outside == 0 && bnd[i]->onWhat()->dim() ==0)corners.push_back(i);
  }
  if (corners.size() == index && index == 3){
    return true;
  }
  else if (corners.size() == index && index == 5){
    return true;
  }
  else if (corners.size() == index && index == 4){
    int n0 = corners[1]-corners[0];
    int n1 = corners[2]-corners[1];
    int n2 = corners[3]-corners[2];
    int n3 = bnd.size() - n0 - n1 - n2;
    if (n0 == n2 && n1 == n3)
      return true;
  }
  return false;
}

static bool removeConcaveCorners (v2t_cont &adj,
				  std::vector<MVertex*> &bnd,
				  std::set<MElement*> & cavity){
  bool ok = true;
  //  return ok;
  int iter = 0;
  while (1){
    std::vector<MElement*> toAdd;
    for (size_t i=0;i<bnd.size();i++){
      v2t_cont::iterator it = adj.find(bnd[i]);
      int n_outside = 0;
      MElement *e = NULL;
      for (size_t j=0;j<it->second.size();j++){
	if (cavity.find(it->second[j]) == cavity.end()){
	  e = it->second[j];
	  n_outside ++;
	}
      }
      if (n_outside == 1){
	for (int j=0;j<4;j++){
	  it = adj.find(e->getVertex(j));
	  if (it->second.size() != 4)ok = false;
	}
	toAdd.push_back(e);
      }
    }
    if (toAdd.empty())break;
    cavity.insert(toAdd.begin(), toAdd.end());
    bnd = buildBoundary (cavity);
    if (iter++ > 5) return false;
  }
  return ok;
}
				  

static bool buildCavity (GFace *gf,
			 MVertex *v, v2t_cont &adj,
			 std::map<MVertex *, int, MVertexPtrLessThan> &sing,
			 std::vector<MVertex*> &bnd,
			 std::set<MElement*> & cavity,
			 int &index,
			 MVertex **theSing) {

  bnd.clear();
  cavity.clear();
  v2t_cont::iterator it = adj.find(v);
  cavity.insert(it->second.begin(), it->second.end());
  int iter = 0;
  int maxiter = 4;
  while (iter++ < maxiter){    
    bnd = buildBoundary (cavity);
    int ns;
    *theSing = countSing (cavity, sing, ns);    
    index = *theSing ? sing [*theSing] : -1 ;
    if (ns == 0)index = 4;
    bool allCornersGood = true;

    for (size_t	i=0; i<bnd.size();i++){
      v2t_cont::iterator itvv = adj.find(bnd[i]);
      if ((bnd[i]->onWhat()->dim() == 2 && itvv->second.size() != 4) ||
	  (bnd[i]->onWhat()->dim() == 1 && itvv->second.size() != 2) ||
	  (bnd[i]->onWhat()->dim() == 0 && itvv->second.size() != 1)) allCornersGood = false;
    }    
    //int nn = nbSing (bnd, cavity, adj);

    if (allCornersGood)
      allCornersGood = removeConcaveCorners (adj,bnd,cavity);
    
    if (allCornersGood && index >= 0){
      if (cavityMeshable(adj,bnd,cavity, index))
	return true;
    }
    
    for (size_t	i=0; i<bnd.size();i++){
      v2t_cont::iterator itvv = adj.find(bnd[i]);
      cavity.insert(itvv->second.begin(), itvv->second.end());
    }
  }
  return false;
}

static void printVector (const std::vector<MVertex*> &v){
  for (size_t i=0;i<v.size();i++)printf("%lu ",v[i]->getNum());
  printf("\n");
}

static std::vector<MVertex*> reverseVector (const std::vector<MVertex*> &v){
  std::vector<MVertex*> r;
  for (size_t i=0;i<v.size();i++)r.push_back(v[v.size() - 1 - i]);
  return r;
}

static std::vector<MVertex*> createVertices (GFace* gf, MVertex *v1, MVertex *v2, int n) {
  std::vector<MVertex*> r;
  r.push_back(v1);
  for (int i=1;i<n;i++){
    double xi = (double)i/n;
    SPoint3 p ((1.-xi)*v1->x()+xi*v2->x(),(1.-xi)*v1->y()+xi*v2->y(),(1.-xi)*v1->z()+xi*v2->z());
    double uv[2] = {0,0};
    GPoint pp = gf->closestPoint(p,uv);
    MVertex *vNew = new MFaceVertex(pp.x(),pp.y(),pp.z(),gf,pp.u(),pp.v());
    gf->mesh_vertices.push_back(vNew);
    r.push_back(vNew);
  }
  r.push_back(v2);
  return r;
}

static void createQuadPatch (GFace* gf,
			     const std::vector<MVertex*> &s0,
			     const std::vector<MVertex*> &s1,
			     const std::vector<MVertex*> &s2,
			     const std::vector<MVertex*> &s3,
			     std::vector<MQuadrangle*> &newQuads){
  /*
   printVector(s0);
    printVector(s1);
    printVector(s2);
    printVector(s3);
  */
  std::vector< std::vector<MVertex*> > grid;
  grid.push_back(s0);
  std::vector<MVertex*> s3r = reverseVector(s3);
  for (size_t i=1;i<s3r.size()-1;i++){
    grid.push_back(createVertices(gf,s3r[i],s1[i],s0.size()-1));
  }
  grid.push_back(reverseVector(s2));

  
  for (size_t i=0;i<grid.size()-1;i++){
    for (size_t j=0;j<grid[i].size()-1;j++){
      MQuadrangle *q = new MQuadrangle (grid[i][j],grid[i+1][j],grid[i+1][j+1],grid[i][j+1]);
      newQuads.push_back(q);
      gf->quadrangles.push_back(q);
    }
  }    
}



static int remeshCavity (GFace *gf,
			 int index,
			 std::set<MElement*> &cavity,
			 std::vector<MVertex*> &bnd,
			 v2t_cont &adj,
			 std::map<MVertex*,int> &newSings){

  // look for corners
  std::vector<int> corners;
  for (size_t i=0;i<bnd.size();i++){
    v2t_cont::iterator it = adj.find(bnd[i]);
    int outside = 0;
    for (size_t j=0;j<it->second.size();j++){
      if (cavity.find(it->second[j]) == cavity.end()) outside ++;
    }
    if (outside == 3 && bnd[i]->onWhat()->dim() ==2)corners.push_back(i);
    else if (outside == 1 && bnd[i]->onWhat()->dim() ==1)corners.push_back(i);
    else if (outside == 0 && bnd[i]->onWhat()->dim() ==0)corners.push_back(i);
  }

  //      a1   a0
  //    1----o--------2
  // a2 |    |      / a2
  //    o----x----o
  //    |        /
  // a0 |      /
  //    |    / a1
  //    |  /   
  //     0
  //    a0 + a2 = n0
  //    a0 + a1 = n1
  //    a1 + a2 = n2
  //    --> a0 = 1/2 (n0+n1-n2)
  //    --> a1 = 1/2 (n1+n2-n0)
  //    --> a2 = 1/2 (n0+n2-n1)

  if (corners.size() == index && index == 3){
    int n0 = corners[1]-corners[0];
    int n1 = corners[2]-corners[1];
    int n2 = bnd.size() + corners[0]-corners[2];
    int a0 = (n0+n1-n2)/2;
    int a1 = (n1+n2-n0)/2;
    int a2 = (n0+n2-n1)/2;

    
    if (a0 == a1 && a0 == a2)return 1;
    
    if (a0+a2 != n0 || a0+a1 != n1 || a1+a2 != n2){
      printf("coucou %d %d %d\n",a0,a1,a2);
      return -1;
    }
    
    std::vector<MVertex*> vec_0_01; for (size_t i=0;i<=a0;i++)vec_0_01.push_back(bnd[(corners[0]+i)%bnd.size()]);
    std::vector<MVertex*> vec_01_1; for (size_t i=0;i<=a2;i++)vec_01_1.push_back(bnd[(corners[0]+a0+i)%bnd.size()]);
    std::vector<MVertex*> vec_1_12; for (size_t i=0;i<=a1;i++)vec_1_12.push_back(bnd[(corners[0]+a0+a2+i)%bnd.size()]);
    std::vector<MVertex*> vec_12_2; for (size_t i=0;i<=a0;i++)vec_12_2.push_back(bnd[(corners[0]+a0+a2+a1+i)%bnd.size()]);
    std::vector<MVertex*> vec_2_02; for (size_t i=0;i<=a2;i++)vec_2_02.push_back(bnd[(corners[0]+a0+a2+a1+a0+i)%bnd.size()]);
    std::vector<MVertex*> vec_02_0; for (size_t i=0;i<=a1;i++)vec_02_0.push_back(bnd[(corners[0]+a0+a2+a1+a0+a2+i)%bnd.size()]);


    double x=0,y=0,z=0;
    for (size_t i=0;i<bnd.size();i++){
      x += bnd[i]->x();
      y += bnd[i]->y();
      z += bnd[i]->z();
    }
    SPoint3 p (x/bnd.size(),y/bnd.size(),z/bnd.size());
    double uv[2] = {0,0};
    GPoint pp = gf->closestPoint(p,uv);
    MVertex *sing = new MFaceVertex(pp.x(),pp.y(),pp.z(),gf,pp.u(),pp.v());
    gf->mesh_vertices.push_back(sing);
    printf("found one triangular patch %lu to remesh %d %d %d %d %d %d %d %d %d %lu\n",
	   sing->getNum(), n0,n1,n2,a0,a1,a2,corners[0],corners[1],corners[2],bnd.size());

    newSings[sing] = index;
    
    /*    printVector(vec_0_01);
    printVector(vec_01_1);
    printVector(vec_1_12);
    printVector(vec_12_2);
    printVector(vec_2_02);
    printVector(vec_02_0);*/
    
    std::vector<MVertex*> vec_01_sing = createVertices (gf, vec_01_1[0], sing, a1);
    std::vector<MVertex*> vec_12_sing = createVertices (gf, vec_12_2[0], sing, a2);
    std::vector<MVertex*> vec_02_sing = createVertices (gf, vec_02_0[0], sing, a0);
    /*
    printVector(vec_01_sing);
    printVector(vec_12_sing);
    printVector(vec_02_sing);
    */
    
    std::vector<MQuadrangle*> newQuads;
    createQuadPatch (gf, vec_0_01, vec_01_sing, reverseVector(vec_02_sing), vec_02_0, newQuads);
    createQuadPatch (gf, vec_01_1, vec_1_12, vec_12_sing, reverseVector(vec_01_sing), newQuads);
    createQuadPatch (gf, vec_12_2, vec_2_02, vec_02_sing, reverseVector(vec_12_sing), newQuads);

    for (std::set<MElement*>::iterator it = cavity.begin(); it != cavity.end() ; ++it){
      MQuadrangle *q = dynamic_cast<MQuadrangle*>(*it);	      
      if (!q)Msg::Error ("A non quad is present in the list of quad of face %lu",gf->tag());
      gf->quadrangles.erase (std::remove(gf->quadrangles.begin(),gf->quadrangles.end(),q),gf->quadrangles.end());
      removeFromAdjacencyList(*it,adj);
    }
    for (size_t i=0;i<newQuads.size();i++){
      addToAdjacencyList (newQuads[i],adj);
    }
    return 1;
  }
  // 5 patch --> one singularity
  else if (corners.size() == index && index == 5){
    int n0 = corners[1]-corners[0];
    int n1 = corners[2]-corners[1];
    int n2 = corners[3]-corners[2];
    int n3 = corners[4]-corners[3];
    int n4 = bnd.size() - n0 - n1 - n2 - n3;
    
    //a0 + a1 = n0
    //a2 + a3 = n1
    //a1 + a4 = n2  
    //a0 + a3 = n3
    //a2 + a4 = n4
    // 1 1 0 0 0 
    // 0 0 1 1 0 
    // 0 1 0 0 1 
    // 1 0 0 1 0 
    // 0 0 1 0 1 

    
    int a0 = (n0-n1-n2+n3+n4)/2;
    int a1 = (n0+n1+n2-n3-n4)/2;
    int a2 = (n0+n1-n2-n3+n4)/2;
    int a3 = (-n0+n1+n2+n3-n4)/2;
    int a4 = (-n0-n1+n2+n3+n4)/2;

    if (a0 == a1 && a0 == a2 && a0 == a3 && a0 == a4 && cavity.size() == 5*a0*a0)return 1;

    if (a0 <=0 || a1 <=0 || a2 <=0 || a3 <=0 || a4 <=0)return 0;
    
    if (a0+a1-n0 ||
	a2+a3-n1 ||
	a1+a4-n2 ||
	a0+a3-n3 ||
	a2+a4-n4)
      {
	printf("--> n's %d %d %d %d %d\n",n0,n1,n2,n3,n4);
	printf("--> a's %d %d %d %d %d\n",a0,a1,a2,a3,a4);
	printf("5 patch found but impossible to mesh\n");
	return -1;
      }  
    else
      {
	printf("5 patch found %d %d %d %d %d\n",a0,a1,a2,a3,a4);
      }


    std::vector<MVertex*> vec_0_01; for (size_t i=0;i<=a0;i++)vec_0_01.push_back(bnd[(corners[0]+i)%bnd.size()]);
    std::vector<MVertex*> vec_01_1; for (size_t i=0;i<=a1;i++)vec_01_1.push_back(bnd[(corners[0]+a0+i)%bnd.size()]);
    std::vector<MVertex*> vec_1_12; for (size_t i=0;i<=a2;i++)vec_1_12.push_back(bnd[(corners[0]+a0+a1+i)%bnd.size()]);
    std::vector<MVertex*> vec_12_2; for (size_t i=0;i<=a3;i++)vec_12_2.push_back(bnd[(corners[0]+a0+a1+a2+i)%bnd.size()]);
    std::vector<MVertex*> vec_2_23; for (size_t i=0;i<=a1;i++)vec_2_23.push_back(bnd[(corners[0]+a0+a1+a2+a3+i)%bnd.size()]);
    std::vector<MVertex*> vec_23_3; for (size_t i=0;i<=a4;i++)vec_23_3.push_back(bnd[(corners[0]+a0+a1+a2+a3+a1+i)%bnd.size()]);
    std::vector<MVertex*> vec_3_34; for (size_t i=0;i<=a3;i++)vec_3_34.push_back(bnd[(corners[0]+a0+a1+a2+a3+a1+a4+i)%bnd.size()]);
    std::vector<MVertex*> vec_34_4; for (size_t i=0;i<=a0;i++)vec_34_4.push_back(bnd[(corners[0]+a0+a1+a2+a3+a1+a4+a3+i)%bnd.size()]);
    std::vector<MVertex*> vec_4_04; for (size_t i=0;i<=a4;i++)vec_4_04.push_back(bnd[(corners[0]+a0+a1+a2+a3+a1+a4+a3+a0+i)%bnd.size()]);
    std::vector<MVertex*> vec_04_0; for (size_t i=0;i<=a2;i++)vec_04_0.push_back(bnd[(corners[0]+a0+a1+a2+a3+a1+a4+a3+a0+a4+i)%bnd.size()]);

    double x=0,y=0,z=0;
    for (size_t i=0;i<bnd.size();i++){
      x += bnd[i]->x();
      y += bnd[i]->y();
      z += bnd[i]->z();
    }
    SPoint3 p (x/bnd.size(),y/bnd.size(),z/bnd.size());
    double uv[2] = {0,0};
    GPoint pp = gf->closestPoint(p,uv);
    MVertex *sing = new MFaceVertex(pp.x(),pp.y(),pp.z(),gf,pp.u(),pp.v());
    gf->mesh_vertices.push_back(sing);

    newSings[sing] = index;

    std::vector<MVertex*> vec_01_sing = createVertices (gf, vec_01_1[0], sing, a2);
    std::vector<MVertex*> vec_12_sing = createVertices (gf, vec_12_2[0], sing, a1);
    std::vector<MVertex*> vec_23_sing = createVertices (gf, vec_23_3[0], sing, a3);
    std::vector<MVertex*> vec_34_sing = createVertices (gf, vec_34_4[0], sing, a4);
    std::vector<MVertex*> vec_04_sing = createVertices (gf, vec_04_0[0], sing, a0);
    /*
    printVector(vec_01_sing);
    printVector(vec_12_sing);
    printVector(vec_02_sing);
    */
    
    std::vector<MQuadrangle*> newQuads;
    createQuadPatch (gf, vec_0_01, vec_01_sing, reverseVector(vec_04_sing), vec_04_0, newQuads);
    createQuadPatch (gf, vec_01_1, vec_1_12, vec_12_sing, reverseVector(vec_01_sing), newQuads);
    createQuadPatch (gf, vec_12_2, vec_2_23, vec_23_sing, reverseVector(vec_12_sing), newQuads);
    createQuadPatch (gf, vec_23_3, vec_3_34, vec_34_sing, reverseVector(vec_23_sing), newQuads);
    createQuadPatch (gf, vec_34_4, vec_4_04, vec_04_sing, reverseVector(vec_34_sing), newQuads);
        
    for (std::set<MElement*>::iterator it = cavity.begin(); it != cavity.end() ; ++it){
      MQuadrangle *q = dynamic_cast<MQuadrangle*>(*it);	      
      if (!q)Msg::Error ("A non quad is present in the list of quad of face %lu",gf->tag());
      gf->quadrangles.erase (std::remove(gf->quadrangles.begin(),gf->quadrangles.end(),q),gf->quadrangles.end());
      removeFromAdjacencyList(*it,adj);
    }
    for (size_t i=0;i<newQuads.size();i++){
      addToAdjacencyList (newQuads[i],adj);
    }
    return 1;
  }
  else if (corners.size() == index && index == 4){
    int n0 = corners[1]-corners[0];
    int n1 = corners[2]-corners[1];
    int n2 = corners[3]-corners[2];
    int n3 = bnd.size() - n0 - n1 - n2;

    if (n0 == n2 && n1 == n3){    
      printf("found a cavity with 4 corners %d %d\n",n0,n1);
      std::vector<MVertex*> vec_0_1; for (size_t i=0;i<=n0;i++)vec_0_1.push_back(bnd[(corners[0]+i)%bnd.size()]);
      std::vector<MVertex*> vec_1_2; for (size_t i=0;i<=n1;i++)vec_1_2.push_back(bnd[(corners[0]+n0+i)%bnd.size()]);
      std::vector<MVertex*> vec_2_3; for (size_t i=0;i<=n2;i++)vec_2_3.push_back(bnd[(corners[0]+n0+n1+i)%bnd.size()]);
      std::vector<MVertex*> vec_3_0; for (size_t i=0;i<=n3;i++)vec_3_0.push_back(bnd[(corners[0]+n0+n1+n2+i)%bnd.size()]);
      std::vector<MQuadrangle*> newQuads;
      createQuadPatch (gf, vec_0_1, vec_1_2, vec_2_3, vec_3_0, newQuads);
      for (std::set<MElement*>::iterator it = cavity.begin(); it != cavity.end() ; ++it){
	MQuadrangle *q = dynamic_cast<MQuadrangle*>(*it);	      
	if (!q)Msg::Error ("A non quad is present in the list of quad of face %lu",gf->tag());
	gf->quadrangles.erase (std::remove(gf->quadrangles.begin(),gf->quadrangles.end(),q),gf->quadrangles.end());
	removeFromAdjacencyList(*it,adj);
      }
      for (size_t i=0;i<newQuads.size();i++){
	addToAdjacencyList (newQuads[i],adj);
      }
      return 1;
    }
  }
  return 0;
}

void computeSingularitesThroughCrossField (GFace * gf,  v2t_cont &adj, Field *f, 
					   std::map<MVertex *, int, MVertexPtrLessThan> &sing){
  
  std::map<MVertex*, double, MVertexPtrLessThan> sizes;
  v2t_cont::iterator it = adj.begin();
  while(it != adj.end()) {
    MVertex *v = it->first;
    SVector3 t1;
    (*f)(v->x(), v->y(), v->z(), t1, gf);
    sizes[v] = t1.norm();
    ++it;
  }
  
  it = adj.begin();
  while(it != adj.end()) {
    MVertex *v = it->first;
    const std::vector<MElement *> &e = it->second;
    if (v->onWhat() == gf && e.size() != 0) {
      double L = sizes[v];
      std::set<MElement*> ee; ee.insert(e.begin(),e.end());
      std::vector<MVertex*> b = buildBoundary (ee);
      bool MIN = true, MAX = true;
      for (size_t i = 0 ; i < b.size(); i++){
	double li = sizes[b[i]];
	if (li > L) MAX = false;
	if (li < L) MIN = false;	
      }
      if (MIN && !MAX)sing[v] = 3;
      if (MAX && !MIN)sing[v] = 5;
    }
    ++it;
  }
  printf("%lu singularities found\n",sing.size());
}



// -------------------------------------------
static void bunin (GFace * gf, std::map<MVertex *, int, MVertexPtrLessThan> sing, std::map<MVertex*,int> &newSings, Field *cross_field) {
  FILE *f = fopen ("cavities.pos","w");
  fprintf(f,"View \"\"{\n");
  v2t_cont adj;
  buildVertexToElement(gf->quadrangles, adj);
  v2t_cont::iterator it = adj.begin();
  int iter = 0;


  if (sing.empty()) computeSingularitesThroughCrossField (gf,  adj, cross_field, sing);
  
  removeValence6Nodes(gf, adj);
  
  std::set<MVertex*, MVertexPtrLessThan> sing_;
  while(it != adj.end()) {
    MVertex *v = it->first;
    const std::vector<MElement *> e = it->second;
    if (v->onWhat() == gf && e.size() != 4 && e.size() != 0) {
      sing_.insert(v);
    }
    ++it;
  }

  Msg::Info("Found %d singularities",sing_.size());

  int count = 0;
  for ( std::set<MVertex*>::iterator itv = sing_.begin() ; itv != sing_.end() ; ++itv) {
    MVertex *v = *itv;
    it = adj.find(v);
    const std::vector<MElement *> e = it->second;
    if (v->onWhat() == gf && e.size() != 4 && e.size() != 0) {
      // compute a cavity that contains ONE "true" singularity
      // but possibly more "mesh singularities" --> just keep one at
      // thet end and replace the singularity by the remaining mesh
      // one
      std::vector<MVertex*> bnd;
      std::set<MElement*> cavity ;
      int index;
      MVertex *theSing = NULL;
      bool success = buildCavity (gf,v,adj, sing, bnd, cavity, index,&theSing);
      if (success){	
	// periodic
	bnd.resize(bnd.size() -1);
	remeshCavity (gf, index, cavity, bnd, adj, newSings);	
	if (success && theSing)sing.erase(theSing);
	//	if (success){
	int tag = success ? count:-count;
	for (size_t i=0;i<bnd.size();i++){
	  fprintf(f,"SL(%g,%g,%g,%g,%g,%g){%d,%d};\n",
		  bnd[i]->x(),bnd[i]->y(),bnd[i]->z(),	  
		  bnd[i+1]->x(),bnd[(i+1)%bnd.size()]->y(),bnd[(i+1)%bnd.size()]->z(),tag,tag);
	}
	count ++;
      }
    }
  }
  fprintf(f,"};\n");
  fclose(f);
}
// -------------------------------------------



void computeLayout (GFace * gf, FILE *f) {

  v2t_cont adj;
  buildVertexToElement(gf->triangles, adj);
  buildVertexToElement(gf->quadrangles, adj);
  v2t_cont::iterator it = adj.begin();
  int numSep = 1;
  
  while(it != adj.end()) {
    MVertex *v = it->first;
    const std::vector<MElement *> e = it->second;
    if (v->onWhat() == gf && e.size() != 4) {
      winslowStencil st (v, e);
      std::vector<MVertex *> &crown = st.stencil;
      printVertex (e.size(), v,f);
      for (int i=1;i<crown.size();i+=2){
	MVertex *prec    = v;
	MVertex *current = crown[i];
	MVertex *next  = NULL;
	printEdge   (numSep, prec, current,f);
	while (1){
	  next = next_vertex (gf, prec, current, adj);
	  if (!next)break;
	  prec = current;
	  current = next;
	  printEdge (numSep, prec, current,f);
	}
	numSep++;
      }      
    }
    ++it;
  }
}


static void findPhysicalGroupsForSingularities(GModel *gm,
                                               std::map<MVertex *, int, MVertexPtrLessThan> &temp)
{
 
  std::map<int, std::vector<GEntity *> > groups[4];
  gm->getPhysicalGroups(groups);
  for(std::map<int, std::vector<GEntity *> >::iterator it = groups[0].begin();
      it != groups[0].end(); ++it) {
    std::string name = gm->getPhysicalName(0, it->first);
    if(name == "SINGULARITY_OF_INDEX_THREE") {
      for(size_t j = 0; j < it->second.size(); j++) {
	if(!it->second[j]->mesh_vertices.empty())
	  temp[it->second[j]->mesh_vertices[0]] = 3;
      }
    }
    else if(name == "SINGULARITY_OF_INDEX_FIVE") {
      for(size_t j = 0; j < it->second.size(); j++) {
	if(!it->second[j]->mesh_vertices.empty())
	  temp[it->second[j]->mesh_vertices[0]] = 5;
      }
    }
  }
}


void meshWinslow2d (GModel * gm, int nIter, Field *f) {


  FieldManager *fields = gm->getFields();
  Field *cross_field = NULL;
  if(fields->getBackgroundField() > 0) {        
    cross_field = fields->get(fields->getBackgroundField());
    if(cross_field->numComponents() != 3) {// we hae a true scaled cross fields !!
      Msg::Error ("Packing of Parallelograms require a scaled cross field");
      Msg::Error ("Do first gmsh yourmeshname.msh -crossfield to create yourmeshname_scaled_crossfield.pos");
      Msg::Error ("Then do yourmeshname.geo -bgm yourmeshname_scaled_crossfield.pos");
      return;
    }
  }
  else {
    Msg::Error ("Packing of Parallelograms require a scaled cross field");
    Msg::Error ("Do first gmsh yourmeshname.msh -crossfield to create yourmeshname_scaled_crossfield.pos");
    Msg::Error ("Then do yourmeshname.geo -bgm yourmeshname_scaled_crossfield.pos");
    return;
  }


  std::vector<GFace *> temp;
  temp.insert(temp.begin(), gm->firstFace(), gm->lastFace());
  std::vector<GEdge *> tempe;
  tempe.insert(tempe.begin(), gm->firstEdge(), gm->lastEdge());
  
  Msg::Info ("Winslow Smoothing the mesh");

  gm->writeMSH("before_bunin.msh", 4.0, false, true);
  
  std::map<MVertex*,int> newSings;
  {
    std::map<MVertex *, int, MVertexPtrLessThan> s;
    //    findPhysicalGroupsForSingularities(gm,s);
    for (size_t i=0;i<temp.size();i++){
      bunin (temp[i], s, newSings, cross_field) ;
    }
  }
  gm->writeMSH("after_bunin.msh", 4.0, false, true);

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


  
  //  return;
  std::string name = gm->getName()+"_layout.pos";
  FILE *_f = fopen(name.c_str(),"w");
  fprintf(_f,"View\"Layout\"{\n");
  for (size_t i=0;i<temp.size();i++)
    computeLayout (temp[i], _f);
  for (std::map<MVertex*,int>::iterator it = newSings.begin() ; it != newSings.end(); ++it){
    fprintf(_f,"SP(%g,%g,%g){9999};\n",it->first->x(),it->first->y(),it->first->z());
  }

  fprintf(_f,"};\n");
  fclose(_f); 
}
