
#if defined(_OPENMP)
#include <omp.h>
#endif
#include <set>
#include <vector>
#include "GmshDefines.h"
#include "Context.h"
#include "GModel.h"
#include "MElement.h"
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
    if (type == 1 && (_e.size() == 4 || _e.size() == 3 || _e.size() == 5)){
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
    GPoint gp = gf->closestPoint(p,uv);
    double dx = sqrt ((gp.x()-center->x())*(gp.x()-center->x())+
		      (gp.y()-center->y())*(gp.y()-center->y())+
		      (gp.z()-center->z())*(gp.z()-center->z()));			
    center->setXYZ(gp.x(),gp.y(),gp.z());
    center->setParameter(0,gp.u());
    center->setParameter(1,gp.v());
    return dx;
  }
};


void meshWinslow1d (GEdge * ge, int nIter, Field *f) {
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

void meshWinslow2d (GFace * gf, int nIter, Field *f) {
  v2t_cont adj;
  buildVertexToElement(gf->triangles, adj);
  buildVertexToElement(gf->quadrangles, adj);
  v2t_cont::iterator it = adj.begin();

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
    for (size_t i=0;i<temp.size();i++)
      meshWinslow2d (temp[i],nIter/4, f);
    
  }
}
