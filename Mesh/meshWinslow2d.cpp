
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
#include "discreteFace.h"
#include "MVertex.h"
#include "MEdge.h"
#include "MLine.h"
#include "meshWinslow2d.h"
// #include "meshSurfaceProjection.h"
// #include "meshOctreeLibOL.h"
#include "meshGFaceOptimize.h"
#include "Field.h"
#include "geolog.h"
#include "qmt_utils.hpp"

// Some shortcuts
#define P(x) {cout << x << endl;}
#define H(x) P(#x << ": " << (x))
#define FR(i,a,b) for (int i=(a); i<(b); i++)
#define F(i,n) FR(i,0,n)
#define FIT(it,v) for (auto it = (v).begin(); it != (v).end(); it++)
#define DR(i,a,b) for (int i=(b); i-->(a);)
#define D(i,n) DR(i,0,n)
#define S(s) (int)(s).size()
#define ALL(v) v.begin(), v.end()
#define MI(a,v) a = min(a,v)
#define MA(a,v) a = max(a,v)
#define V vector
#define pb push_back
#define mt make_tuple

using namespace std;


int BLOB = 1;

static GPoint CLOSESTPOINT (GFace *gf, const SPoint3 &p, double uv[2], GEntity::GeomType GT){
  //  if (GT == GEntity::DiscreteSurface){
  //    return GPoint(p.x(),p.y(),p.z(),gf,0,0);
  //  }
  return gf->closestPoint(p,uv);
}

static GPoint CLOSESTPOINT (GEdge *ge, const SPoint3 &p, double u){
  return ge->closestPoint(p,u);
}

// SHOULD BE FASTER
template <class ITERATOR> 
static std::vector<MVertex*> buildBoundary (ITERATOR beg, ITERATOR end){
  std::vector<MEdge> eds,veds;

  for (ITERATOR ite = beg; ite != end;++ite){
    for (size_t j=0;j<(size_t)(*ite)->getNumEdges();j++){
      eds.push_back((*ite)->getEdge(j));
    }
  }
  MEdgeLessThan melt;
  std::sort(eds.begin(),eds.end(), melt);
  for(size_t i=0;i<eds.size();i++){
    if (i != eds.size()-1 && eds[i] == eds[i+1])i++;
    else veds.push_back(eds[i]);
  }
  
  std::vector<std::vector<MVertex *> > vsorted;
  SortEdgeConsecutive(veds, vsorted);
  if (vsorted.size() != 1){
    std::vector<MVertex *> empty;
    return empty;
  }

  return vsorted[0];
}


// -------------------------------------------------------------------------------------------
//  BIG FUNCTION : COULD BE MADE SMALLER BUT EASY TO READ
//



// -------------------------------------------------------------------------------------------

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

  if (vsorted.size() != 1) {
    Msg::Error("vertex with elements that are disconnected, %li lists", vsorted.size());
    for (size_t i = 0; i < vsorted.size(); ++i) {
      for (MVertex* vv: vsorted[i]) {
        GeoLog::add(SVector3(vv->point()),double(i),"!vertex_disco_elts");
      }
    }
    GeoLog::flush();
  }
  
  // start with a corner
  std::vector<MVertex *> result;
  if (vsorted.empty())return result;
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

// Determine stencil class given elements.
// 1: quads only
// 2: triangles only
// 3: quads and triangles only
// 4: other element types are present
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
  ;
  winslowStencil (MVertex *v,
		  const std::vector<MElement*> &_e,
		  GFace *gf = NULL) : elements (_e)
  {
    type = classOfStencil(_e);
    if (type == 1 && _e.size() >= 3){
      stencil  = build_crown (v, _e);
      ptsStencil.resize(stencil.size());
      center = v;            
    }
    else{
      Msg::Error("weird class of stencil %d %lu",type,_e.size());
      GeoLog::add(SVector3(v->point()),double(0),"!weird_stencil");
      GeoLog::flush();
    }
  }  

  bool computeParameters (GFace *gf, std::vector<SPoint2> &ptsStencilParam){
    ptsStencilParam.resize(stencil.size());    
    for (size_t i=0; i< stencil.size();i++){
      if (stencil[i]->onWhat() != gf)return false;
      if (!reparamMeshVertexOnFace(stencil[i],gf,ptsStencilParam[i])){
	return false;
      }	  
    }
    return true;
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

  // parameter space sm
  SPoint2 new3dPosition4quadsParam (GFace *gf, std::vector<SPoint2> &ptsStencilParam){
    /* simple unit stencil */
    double hx = 1.;
    double hy = 1.; 
    
    SPoint2 p;
    center->getParameter(0, p[0]);
    center->getParameter(1, p[1]);
    
    Pair<SVector3, SVector3> t = gf->firstDer(p);

    SVector3 dudu,dvdv,dudv;
    gf->secondDer(p, dudu, dvdv,dudv);

    const int order[8] = {7,1,3,5,0,6,2,4};
       
    /* Grid Generation §9 page 23 */

    const double dudxi  = 1./hx * (ptsStencilParam[order[0]].x() - ptsStencilParam[order[2]].x());
    const double dudeta = 1./hy * (ptsStencilParam[order[1]].x() - ptsStencilParam[order[3]].x());
    const double dvdxi  = 1./hx * (ptsStencilParam[order[0]].y() - ptsStencilParam[order[2]].y());
    const double dvdeta = 1./hy * (ptsStencilParam[order[1]].y() - ptsStencilParam[order[3]].y());
    const double J = dudxi*dvdeta-dudeta*dvdxi;

    const double gbar11 = dot(t.first(),t.first());
    const double gbar12 = dot(t.first(),t.second());
    const double gbar22 = dot(t.second(),t.second());
    const double Jbar = sqrt (gbar11*gbar22-gbar12*gbar12);    
    
    const double g11 = gbar11*dudxi*dudxi + 2*gbar12*dudxi*dvdxi+gbar22*dvdxi*dvdxi;
    const double g22 = gbar11*dudeta*dudeta + 2*gbar12*dudeta*dvdeta+gbar22*dvdeta*dvdeta;
    const double g12 = gbar11*dudxi*dudeta + gbar12*(dudxi*dvdeta+dudeta*dvdxi)+gbar22*dvdxi*dvdeta;
      
    
    const double gbar11u = 2*dot(t.first(),dudu);
    const double gbar11v = 2*dot(t.first(),dudv);    
    const double gbar22u = 2*dot(t.second(),dudv);
    const double gbar22v = 2*dot(t.second(),dvdv);
    const double gbar12u = dot(t.first(),dudv) + dot(t.second(),dudu);
    const double gbar12v = dot(t.first(),dvdv) + dot(t.second(),dudv);
    
    const double uip1j = ptsStencilParam[order[0]].x();  
    const double uim1j = ptsStencilParam[order[2]].x();  
    const double uijp1 = ptsStencilParam[order[1]].x();  
    const double uijm1 = ptsStencilParam[order[3]].x();  
    const double uip1jp1 = ptsStencilParam[order[4]].x();  
    const double uim1jp1 = ptsStencilParam[order[6]].x();  
    const double uim1jm1 = ptsStencilParam[order[7]].x();  
    const double uip1jm1 = ptsStencilParam[order[5]].x();  
    
    const double vip1j = ptsStencilParam[order[0]].y();  
    const double vim1j = ptsStencilParam[order[2]].y();  
    const double vijp1 = ptsStencilParam[order[1]].y();  
    const double vijm1 = ptsStencilParam[order[3]].y();  
    const double vip1jp1 = ptsStencilParam[order[4]].y();  
    const double vim1jp1 = ptsStencilParam[order[6]].y();  
    const double vim1jm1 = ptsStencilParam[order[7]].y();  
    const double vip1jm1 = ptsStencilParam[order[5]].y();  

    const double Jbaru = (1./(2*Jbar))*(gbar11*gbar22u+gbar22*gbar11u-2*gbar12*gbar12u);
    const double Jbarv = (1./(2*Jbar))*(gbar11*gbar22v+gbar22*gbar11v-2*gbar12*gbar12v);

    const double Delta2u = (1./(Jbar))*(Jbar*(gbar22u-gbar12v)-(gbar22*Jbaru-gbar12*Jbarv));
    const double Delta2v = (1./(Jbar))*(Jbar*(gbar11v-gbar12u)-(gbar11*Jbarv-gbar12*Jbaru));

    //    printf("G = %g %g %g  Gbar %g %g %g\n",g11,g22,g12,gbar11,gbar22,gbar12);
    
    // formulas 9.26a and 9.26b
    double uij = (1./(4*(g11+g22))) * (2*g22*(uip1j+uim1j) + 2*g11*(uijp1+uijm1)-2*g12*(uip1jp1-uim1jp1-uip1jm1+uim1jm1) - 2*J*J*Delta2u); 
    double vij = (1./(4*(g11+g22))) * (2*g22*(vip1j+vim1j) + 2*g11*(vijp1+vijm1)-2*g12*(vip1jp1-vim1jp1-vip1jm1+vim1jm1) - 2*J*J*Delta2v); 
    
    //    uij = 0.25*(uip1j+uim1j+uijp1+uijm1);
    //    vij = 0.25*(vip1j+vim1j+vijp1+vijm1);
    
    SPoint2 pp (uij,vij);
    
    return pp*1.1-p*.1;
    
  }
  
  SPoint3 new3dPosition4quads (){
    for (size_t i=0;i<stencil.size();i++)
      ptsStencil[i] = SVector3(stencil[i]->x(),stencil[i]->y(),stencil[i]->z());
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
    SVector3 u_xy = 1./(4.*hx*hy) * ((ptsStencil[order[4]]-ptsStencil[order[6]]) +
				     (ptsStencil[order[7]]-ptsStencil[order[5]]));
    
    /* 2. Compute the "winslow new position" */
    double denom = 2. * alpha_0 / (hx*hx) + 2. * alpha_1 / (hy*hy);
    SVector3 newPos = 1. / denom * (
				    alpha_0/(hx*hx) * (ptsStencil[order[0]] + ptsStencil[order[2]])
				    + alpha_1/(hy*hy) * (ptsStencil[order[1]] + ptsStencil[order[3]])
				    - 2. * beta * u_xy
				    );
    const double w = 1.7;
    SPoint3 p (w*newPos.x()+(1.-w)*center->x(),w*newPos.y()+(1.-w)*center->y(),w*newPos.z()+(1.-w)*center->z());
    return p;
  }
  
  double smooth (GEdge *ge){
    
    if (ge->geomType() == GEntity::DiscreteCurve){
      return 0;
    }
    
    if (stencil.empty())return 0;
    SPoint3 p;    
    if (type == 1 && stencil.size() == 8){
      p = new3dPosition4quads();
    }
    else {
      return 0;
    }
    double u ; center->getParameter(0,u);

    
    GPoint gp = CLOSESTPOINT(ge,p,u);
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


  double smooth (GFace *gf, GEntity::GeomType GT, double radius, SPoint3 &c, size_t& cache, 
      bool spProjectOnCAD = false){
    if (stencil.empty())return 0;
    SPoint3 p;    
    //    printf("coucou1\n");
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
    //    printf("coucou2\n");
    double uv[2] ; center->getParameter(0,uv[0]);center->getParameter(1,uv[1]);
    double dx;
    //    printf("coucou3\n");
    if (GT == GEntity::Plane){
      dx = sqrt ((p.x()-center->x())*(p.x()-center->x())+
          (p.y()-center->y())*(p.y()-center->y())+
          (p.z()-center->z())*(p.z()-center->z()));			
      center->setXYZ(p.x(),p.y(),p.z());
    }
    else if (GT == GEntity::Sphere){
      SVector3 vv = p - c;
      vv.normalize();
      vv *= radius;
      p= SPoint3(c.x() + vv.x(),c.y() + vv.y(),c.z() + vv.z());
      dx = sqrt ((p.x()-center->x())*(p.x()-center->x())+
          (p.y()-center->y())*(p.y()-center->y())+
          (p.z()-center->z())*(p.z()-center->z()));			
      center->setXYZ(p.x(),p.y(),p.z());
    }
    else {
      GPoint gp = CLOSESTPOINT(gf,p,uv, GT);
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
  // return;
  nIter = 1000;
  std::vector<GFace*> faces = ge->faces();
  if (faces.size() != 2)return;
  
  v2t_cont adj;
  buildVertexToElement(faces[0]->triangles, adj);
  buildVertexToElement(faces[0]->quadrangles, adj);
  if (faces.size() == 2){
    buildVertexToElement(faces[1]->triangles, adj);
    buildVertexToElement(faces[1]->quadrangles, adj);
  }
  
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
    if (dx < .001*dx0) break;
  }     
}


void meshWinslow2d (GFace  * gf, const std::vector<MQuadrangle*>& quads, 
    const std::vector<MVertex*>& freeVertices, int nIter, Field *f, bool remove) {
  if (gf->triangles.size())return;
  Msg::Debug("winslow 2D on %li quads, %li free vertices (face %i), %i iterations ...", quads.size(), freeVertices.size(),
	     gf->tag(), nIter);
  GEntity::GeomType GT = gf->geomType();
  
  // allowProjections (gf);
  
  v2t_cont adj;
  buildVertexToElement(quads, adj);

  
  std::vector<winslowStencil> stencils;

  double radius;
  SPoint3 c;
  if (GT == GEntity::Sphere){
    gf->isSphere(radius, c) ;
  }

  for (MVertex* v: freeVertices) {
    auto it = adj.find(v);
    if (it == adj.end()) continue;
    if (v->onWhat() == gf) { 
      const std::vector<MElement *> &e = it->second;
      winslowStencil st (v, e, gf);
      stencils.push_back(st);
    }
    ++it;
  }
  
  double dx0;
  std::vector<size_t> cache_tris(stencils.size(),(size_t)-1);
  for (int i=0;i<nIter;i++){
    // bool spProjectOnCAD = (sp && (95 * i > 100 * nIter));
    bool spProjectOnCAD = false;
    double dx = 0;
    for (size_t j=0;j<stencils.size();j++){
      double xx = stencils[j].smooth(gf,GT,radius,c,cache_tris[j], spProjectOnCAD);
      dx += xx ;
    }
    if (i == 0)dx0 = dx;
    if (dx < .002*dx0) break;
  }  
}

void meshWinslow2d (GFace * gf, int nIter, Field *f, bool remove) {
  if (gf->triangles.size())return;
  GEntity::GeomType GT = gf->geomType();

  // for (size_t i=0;i<gf->mesh_vertices.size();i++){
  //   double u,v;
  //   gf->mesh_vertices[i]->getParameter(0,u);
  //   gf->mesh_vertices[i]->getParameter(1,v);
  //   if (u == 0 && v == 0){
  //     double uv[2];
  //     SPoint3 xxx (gf->mesh_vertices[i]->x(),gf->mesh_vertices[i]->y(),gf->mesh_vertices[i]->z());
  //     GPoint gp = gf->closestPoint(xxx,uv);
  //     gf->mesh_vertices[i]->setParameter(0,gp.u());
  //     gf->mesh_vertices[i]->setParameter(1,gp.v());
  //   }
  // }    

  
  // allowProjections (gf);
  
  v2t_cont adj;
  buildVertexToElement(gf->quadrangles, adj);
  v2t_cont::iterator it = adj.begin();

  std::vector<winslowStencil> stencils;

  double radius;
  SPoint3 c;
  if (GT == GEntity::Plane){
    nIter = 1000;
  }
  if (GT == GEntity::Sphere){
    nIter = 1000;
    gf->isSphere(radius, c) ;
  }
  
  while(it != adj.end()) {
    MVertex *v = it->first;
    if (v->onWhat() == gf) {      
      const std::vector<MElement *> &e = it->second;
      winslowStencil st (v, e, gf);
      stencils.push_back(st);
    }
    ++it;
  }
  
  std::vector<size_t> cache_tris(stencils.size(),(size_t)-1);
  double dx0;
  for (int i=0;i<nIter;i++){
    double dx = 0;
    // bool spProjectOnCAD = (sp && (95 * i > 100 * nIter));
    bool spProjectOnCAD = false;
    for (size_t j=0;j<stencils.size();j++){
      double xx = stencils[j].smooth(gf,GT,radius,c,cache_tris[j], spProjectOnCAD);
      dx += xx ;
      //      printf("%lu %12.5E\n",j, xx);
    }
    if (i == 0)dx0 = dx;
    if (dx < .002*dx0 || i == nIter-1) {
      DBG(i,nIter,dx,dx0);
      break;
    }
    //    printf("%12.5E %12.5E\n",dx,dx0);
  }  
}


void meshWinslow2d (GModel * gm, int nIter, Field *f) {
  std::vector<GFace*> temp;
  std::vector<GEdge*> tempe;
  temp.insert(temp.begin(), gm->firstFace(), gm->lastFace());
  tempe.insert(tempe.begin(), gm->firstEdge(), gm->lastEdge());

  for(size_t i=0;i<temp.size();i++){
    printf("face %d --> %lu quads\n",temp[i]->tag(),temp[i]->quadrangles.size());
    // allowProjections (temp[i]);
  }
  
  int sIter = nIter/4;
  sIter = 10;

  for (int NIT = 0;NIT<4;NIT++){  
    for (size_t i=0;i<tempe.size();i++)
      meshWinslow1d (tempe[i],sIter, f); 


#if defined(_OPENMP)
#pragma omp parallel for schedule(dynamic)
#endif
    for (size_t i=0;i<temp.size();i++){
      meshWinslow2d (temp[i],sIter, f, false);
    }
    // return;
  }

  return;  
}
