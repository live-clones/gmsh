// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Koen Hillewaert
//

#include "HighOrder.h"
#include "meshGFaceOptimize.h"
#include "gmshSmoothHighOrder.h"
#include "gmshAssembler.h"
#include "gmshLaplace.h"
#include "gmshElasticity.h"
#include "gmshLinearSystemGmm.h"
#include "GFace.h"
#include "GRegion.h"
#include "Context.h"
#include "Numeric.h"

#define SQU(a)      ((a)*(a))

extern Context_T CTX;

void getDistordedElements(const std::vector<MElement*>  & v, 
                          const double & threshold,
                          std::vector<MElement*>  & d,
                          double &minD)
{
  d.clear();
  minD = 1;
  for (unsigned int i = 0; i < v.size(); i++){
    const double disto = v[i]->distoShapeMeasure();
    if (disto < threshold)
      d.push_back(v[i]);
    minD = std::min(minD, disto);
  }
}

void addOneLayer(const std::vector<MElement*>  & v, 
                 std::vector<MElement*>  & d ,
                 std::vector<MElement*>  & layer )
{
  std::set<MVertex*> all;
  for (unsigned int i = 0; i < d.size(); i++){
    MElement *e = d[i];
    int n = e->getNumPrimaryVertices();
    for (int j = 0; j < n; j++){
      all.insert(e->getVertex(j));
    }
  }

  layer.clear();

  std::sort(d.begin(), d.end());

  for (unsigned int i = 0; i < v.size(); i++){
    MElement *e = v[i];
    bool found = std::binary_search(d.begin(), d.end(), e);
    // element is not yet there
    if (!found){
      int n = e->getNumPrimaryVertices();
      for (int j = 0; j < n; j++){
	MVertex *vert = e->getVertex(j);
	if (all.find(vert) != all.end()){
	  layer.push_back(e);
	  j = n;
	}
      }
    }
  }
}

void gmshHighOrderSmoother::smooth(GFace *gf)
{
  std::vector<MElement*> v;

  v.insert(v.begin(), gf->triangles.begin(),gf->triangles.end());
  v.insert(v.begin(), gf->quadrangles.begin(),gf->quadrangles.end());
  Msg::Info("Smoothing high order mesh : model face %d (%d elements)", gf->tag(),
	    v.size());
  smooth(v);
}

void gmshHighOrderSmoother::smooth(GRegion *gr)
{
  std::vector<MElement*> v;
  v.insert(v.begin(), gr->tetrahedra.begin(),gr->tetrahedra.end());
  v.insert(v.begin(), gr->hexahedra.begin(),gr->hexahedra.end());
  v.insert(v.begin(), gr->prisms.begin(),gr->prisms.end());
  Msg::Info("Smoothing high order mesh : model region %d (%d elements)", gr->tag(),
	    v.size());
  smooth(v);
}

void gmshHighOrderSmoother::smooth ( std::vector<MElement*>  & all)
{
  gmshLinearSystemGmm *lsys = new gmshLinearSystemGmm;
  gmshAssembler myAssembler(lsys);
  gmshElasticityTerm El(0,1.0,.333,getTag());     
  
  std::vector<MElement*> v, layer;

  double minD;

  getDistordedElements ( all, 0.5, v,minD);

  //  printf("%d elements / %d distorted  min Disto = %g\n",all.size(),v.size(), minD);

  if (!v.size()) return;

  const int nbLayers = 2;
  for (int i=0;i<nbLayers;i++){
    addOneLayer ( all, v, layer);
    v.insert(v.end(),layer.begin(),layer.end());
  }

  // 3 -> .4
  printf("%d elements after adding %d layers\n", v.size(), nbLayers);

  addOneLayer(all, v, layer);

  //  printf("%d elements in the next layer\n",layer.size());


  for (unsigned int i = 0; i < layer.size(); i++){
    for (int j = 0; j < layer[i]->getNumVertices(); j++){
      MVertex *vert = layer[i]->getVertex(j);
      myAssembler.fixVertex(vert, 0, getTag(), 0);
      myAssembler.fixVertex(vert, 1, getTag(), 0);
      myAssembler.fixVertex(vert, 2, getTag(), 0);
    }
  }
  

  std::map<MVertex*,SVector3>::iterator it;
  std::map<MVertex*,SVector3> verticesToMove;

  //  printf("%d vertices \n", _displ.size());

  for (unsigned int i = 0; i < v.size(); i++){
    for (int j = 0; j < v[i]->getNumVertices(); j++){
      MVertex *vert = v[i]->getVertex(j);
      //      printf("%d %d %d v\n",i,j,v[i]->getNumVertices());
      it = _displ.find(vert);
      if (it != _displ.end()){
	myAssembler.fixVertex ( vert , 0 , getTag() , vert->x()-it->second.x());
	myAssembler.fixVertex ( vert , 1 , getTag() , vert->y()-it->second.y());
	myAssembler.fixVertex ( vert , 2 , getTag() , vert->z()-it->second.z());
	//	printf("%g %g vs %g %g\n", it->second.x(), it->second.y(),vert->x(),vert->y());
	verticesToMove[vert] = it->second;
      }
      // ensure we do not touch any vertex that is on the boundary
      else if (vert->onWhat()->dim() < _dim){
	myAssembler.fixVertex ( vert , 0 , getTag() , 0);
	myAssembler.fixVertex ( vert , 1 , getTag() , 0);
	myAssembler.fixVertex ( vert , 2 , getTag() , 0);
      }
    }
  }
  
  // move back high order nodes to their straight sided 
  // location
  for (it = verticesToMove.begin()  ; it != verticesToMove.end() ; ++it){
    it->first->x() = it->second.x();
    it->first->y() = it->second.y();
    it->first->z() = it->second.z();
  }
  
  // number the other DOFs
  for (unsigned int i = 0; i < v.size(); i++){
    for (int j = 0; j < v[i]->getNumVertices(); j++){
      MVertex *vert = v[i]->getVertex(j);
      myAssembler.numberVertex(vert, 0, getTag());
      myAssembler.numberVertex(vert, 1, getTag());
      myAssembler.numberVertex(vert, 2, getTag());
      // gather all vertices that are supposed to move
      verticesToMove[vert] = SVector3(0.0,0.0,0.0);
    } 
  }

  //  Msg::Info("%d vertices FIXED %d NUMBERED", myAssembler.sizeOfF()
  //	    , myAssembler.sizeOfR());

  if (myAssembler.sizeOfR()){

    // assembly of the elasticity term on the
    // set of elements
    El.addToMatrix(myAssembler,v); 
    
    // solve the system
    lsys->systemSolve();
  }

  // move the nodes that were involved in the process
  // to their new lcation
  for (it = verticesToMove.begin()  ; it != verticesToMove.end() ; ++it){
    it->first->x() =  it->first->x() + myAssembler.getDofValue (it->first, 0 ,getTag());  
    it->first->y() =  it->first->y() + myAssembler.getDofValue (it->first, 1 ,getTag());  
    it->first->z() =  it->first->z() + myAssembler.getDofValue (it->first, 2 ,getTag());  
    //    printf("%g %g\n", myAssembler.getDofValue (it->first, 0 ,getTag()), myAssembler.getDofValue (it->first, 1 ,getTag()));
  }

  // delete matrices and vectors

  double minD2;
  getDistordedElements ( v, 0.5, layer,minD2);

  printf("Smooting efficiency %g -> %g\n",minD,minD2);


  delete lsys;
  
}

////////////////////////////////////////////////////////////////////////////////
// OLD STUFF : STILL USED ?
////////////////////////////////////////////////////////////////////////////////

bool straightLine(std::vector<MVertex*> &l, MVertex *n1, MVertex *n2)
{
  // x = a * t + b
  // x1 = b
  // x2 = a + b
  for(unsigned int i = 0; i < l.size(); i++){
    MVertex *v = l[i];
    double b = n1->x();
    double a = n2->x() - b;
    double t = (v->x() - b) / a;
    double by = n1->y();
    double ay = n2->y() - by;
    double y = ay * t + by;
    if(fabs(y-v->y()) > 1.e-07 * CTX.lc){
      return false;      
    }
  }
  return true;
}

void getMinMaxJac (MTriangle *t, double &minJ, double &maxJ)
{
  double mat[2][3];  
  int n = 3;
  t->getPrimaryJacobian(0, 0, 0, mat);
   //t->getJacobian(0, 0, 0, mat);
  double v1[3] = {mat[0][0], mat[0][1], mat[0][2]};
  double v2[3] = {mat[1][0], mat[1][1], mat[1][2]};
  double normal1[3], normal[3];
  prodve(v1, v2, normal1);
  double nn = sqrt(SQU(normal1[0]) + SQU(normal1[1]) + SQU(normal1[2]));
  for(int i = 0; i < n; i++){
    for(int k = 0; k < n - i; k++){
      t->getJacobian((double)i / (n - 1), (double)k / (n - 1), 0, mat);
      double v1b[3] = {mat[0][0], mat[0][1], mat[0][2]};
      double v2b[3] = {mat[1][0], mat[1][1], mat[1][2]};
      prodve(v1b, v2b, normal);
      double sign; 
      prosca(normal1, normal, &sign);
      double det = norm3(normal) * (sign > 0 ? 1. : -1.) / nn;
      minJ = std::min(1. / det, std::min(det, minJ));
      maxJ = std::max(det, maxJ);
    }
  }
}

struct smoothVertexDataHO{
  MVertex *v;
  GFace *gf;
  std::vector<MTriangle*> ts;
}; 

struct smoothVertexDataHON{
  std::vector<MVertex*> v;
  GFace *gf;
  std::vector<MTriangle*> ts;
}; 

double smoothing_objective_function_HighOrder(double U, double V, MVertex *v, 
                                              std::vector<MTriangle*> &ts, GFace *gf)
{
  GPoint gp = gf->point(U, V);
  const double oldX = v->x();
  const double oldY = v->y();
  const double oldZ = v->z();

  v->x() = gp.x();
  v->y() = gp.y();
  v->z() = gp.z();

  double minJ =  1.e22;
  double maxJ = -1.e22;
  for (unsigned int i = 0; i < ts.size(); i++){
    getMinMaxJac (ts[i], minJ, maxJ);
  }
  v->x() = oldX;
  v->y() = oldY;
  v->z() = oldZ;
  
  return -minJ;
}


void deriv_smoothing_objective_function_HighOrder(double U, double V, 
                                                  double &F, double &dFdU,
                                                  double &dFdV, void *data)
{
  smoothVertexDataHO *svd = (smoothVertexDataHO*)data;
  MVertex *v = svd->v;
  const double LARGE = -1.e5;
  const double SMALL = 1./LARGE;
  F   = smoothing_objective_function_HighOrder(U, V, v, svd->ts, svd->gf);
  double F_U = smoothing_objective_function_HighOrder(U + SMALL, V, v, svd->ts, svd->gf);
  double F_V = smoothing_objective_function_HighOrder(U, V + SMALL, v, svd->ts, svd->gf);
  dFdU = (F_U - F) * LARGE;
  dFdV = (F_V - F) * LARGE;
}

double smooth_obj_HighOrder(double U, double V, void *data)
{
  smoothVertexDataHO *svd = (smoothVertexDataHO*)data;
  return  smoothing_objective_function_HighOrder(U, V, svd->v, svd->ts, svd->gf); 
}

double smooth_obj_HighOrderN(double *uv, void *data)
{
  smoothVertexDataHON *svd = (smoothVertexDataHON*)data;
  double oldX[10],oldY[10],oldZ[10];
  for (unsigned int i = 0; i < svd->v.size(); i++){
    GPoint gp = svd->gf->point(uv[2 * i], uv[2 * i + 1]);
    oldX[i] = svd->v[i]->x();
    oldY[i] = svd->v[i]->y();
    oldZ[i] = svd->v[i]->z();
    svd->v[i]->x() = gp.x();
    svd->v[i]->y() = gp.y();
    svd->v[i]->z() = gp.z();
  }
  double minJ =  1.e22;
  double maxJ = -1.e22;
  for(unsigned int i = 0; i < svd->ts.size(); i++){
    getMinMaxJac (svd->ts[i], minJ, maxJ);
  }
  for(unsigned int i = 0; i < svd->v.size(); i++){
    svd->v[i]->x() = oldX[i];
    svd->v[i]->y() = oldY[i];
    svd->v[i]->z() = oldZ[i];
  }
  return -minJ;
}

void deriv_smoothing_objective_function_HighOrderN(double *uv, double *dF, 
                                                   double &F, void *data)
{
  const double LARGE = -1.e2;
  const double SMALL = 1. / LARGE;
  smoothVertexDataHON *svd = (smoothVertexDataHON*)data;
  F = smooth_obj_HighOrderN(uv, data);
  for (unsigned int i = 0; i < svd->v.size(); i++){
    uv[i] += SMALL;
    dF[i] = (smooth_obj_HighOrderN(uv, data) - F) * LARGE;
    uv[i] -= SMALL;
  }
}

void optimizeNodeLocations(GFace *gf, smoothVertexDataHON &vdN, double eps = .2)
{
  if(!vdN.v.size()) return;
  double uv[20];
  for (unsigned int i = 0; i < vdN.v.size(); i++){
    if (!vdN.v[i]->getParameter(0, uv[2 * i])){
      Msg::Error("Node location optimization failed");
      return;
    }
    if (!vdN.v[i]->getParameter(1, uv[2 * i + 1])){
      Msg::Error("Node location optimization failed");
      return;
    }
  }

  double F = -smooth_obj_HighOrderN(uv, &vdN);
  if (F < eps){
    double val;
    minimize_N(2 * vdN.v.size(), 
               smooth_obj_HighOrderN, 
               deriv_smoothing_objective_function_HighOrderN, 
               &vdN, 1, uv,val);
    double Fafter = -smooth_obj_HighOrderN(uv, &vdN);
    printf("%12.5E %12.5E\n", F, Fafter);
    if (F < Fafter){
      for (unsigned int i = 0; i < vdN.v.size(); i++){
        vdN.v[i]->setParameter(0, uv[2 * i]);
        vdN.v[i]->setParameter(1, uv[2 * i + 1]);
        GPoint gp = gf->point(uv[2 * i], uv[2 * i + 1]);
        vdN.v[i]->x() = gp.x();
        vdN.v[i]->y() = gp.y();
        vdN.v[i]->z() = gp.z();
      }
    }     
  }
}

double angle3Points ( MVertex *p1, MVertex *p2, MVertex *p3 )
{
  SVector3 a(p1->x()-p2->x(),p1->y()-p2->y(),p1->z()-p2->z());
  SVector3 b(p3->x()-p2->x(),p3->y()-p2->y(),p3->z()-p2->z());
  SVector3 c = crossprod(a,b);
  double sinA = c.norm();
  double cosA = dot(a,b);
  //  printf("%d %d %d -> %g %g\n",p1->iD,p2->iD,p3->iD,cosA,sinA);
  return atan2 (sinA,cosA);  
}

/*
A curvilinear edge smooth and swap
*/

typedef std::map<std::pair<MVertex*, MVertex*>, std::vector<MElement*> > edge2tris;

void localHarmonicMapping(GModel *gm, 
			  MTriangle *t1 , 
			  MTriangle *t2,
			  MVertex *n1,
			  MVertex *n2,
			  MVertex *n3,
			  MVertex *n4,
// 			  SPoint2 &np1,
// 			  SPoint2 &np2,
// 			  SPoint2 &np3,
// 			  SPoint2 &np4,
			  std::vector<MVertex*> &e1,
			  std::vector<MVertex*> &e2,
			  std::vector<MVertex*> &e3,
			  std::vector<MVertex*> &e4,
// 			  std::vector<SPoint2> &ep1,
// 			  std::vector<SPoint2> &ep2,
// 			  std::vector<SPoint2> &ep3,
// 			  std::vector<SPoint2> &ep4
			  std::vector<MVertex*> &e) {
  
  gmshLinearSystemGmm *lsys = new gmshLinearSystemGmm;
  gmshAssembler myAssembler(lsys);
  gmshLaplaceTerm Laplace (gm,1.0,0);     
  
  myAssembler.fixVertex ( n1 , 0 , 0 , -1.0);
  myAssembler.fixVertex ( n2 , 0 , 0 , -1.0);
  myAssembler.fixVertex ( n3 , 0 , 0 ,  1.0);
  myAssembler.fixVertex ( n4 , 0 , 0 ,  1.0);
  for (unsigned int i = 0; i < e1.size(); i++) myAssembler.fixVertex(e1[i], 0, 0, -1.0);
  for (unsigned int i = 0; i < e3.size(); i++) myAssembler.fixVertex(e3[i], 0, 0,  1.0);
  Laplace.addToMatrix(myAssembler,t1); 
  Laplace.addToMatrix(myAssembler,t2);   
  lsys->systemSolve();

  gmshLinearSystemGmm *lsys1 = new gmshLinearSystemGmm;
  gmshAssembler myAssembler1(lsys1);
  gmshLaplaceTerm Laplace1 (gm,1.0,1);     
  
  myAssembler1.fixVertex ( n2 , 0 , 1 , -1.0);
  myAssembler1.fixVertex ( n3 , 0 , 1 , -1.0);
  myAssembler1.fixVertex ( n4 , 0 , 1 ,  1.0);
  myAssembler1.fixVertex ( n1 , 0 , 1 ,  1.0);
  for (unsigned int i = 0; i < e2.size(); i++) myAssembler1.fixVertex(e2[i], 0, 1, -1.0);
  for (unsigned int i = 0; i < e4.size(); i++) myAssembler1.fixVertex(e4[i], 0, 1,  1.0);  
  Laplace1.addToMatrix(myAssembler1,t1); 
  Laplace1.addToMatrix(myAssembler1,t2);   
  lsys1->systemSolve();

  // now we have the stable high order harmonic mapping 
  // we have to find points locations of vertices in e
  // that have coordinates (\xi, \xi) 

  // this can be done by evaluating the 

  for (unsigned int i = 0; i < e.size();  i++){
    MVertex *v = e[i];
    const double U =  myAssembler.getDofValue  (v, 0 ,0);
    const double V =  myAssembler1.getDofValue (v, 0 ,1);
    printf("point %g %g -> %g %g\n",v->x(),v->y(),U,V);
    // we are in t1
    if (U >= V){
      const double ut = U;
    }
  }


  delete lsys ;  
  delete lsys1;  
}

void optimizeHighOrderMeshInternalNodes(GFace *gf)
{
  for(unsigned int i = 0; i < gf->triangles.size(); i++){
    MTriangle *t = gf->triangles[i];
    smoothVertexDataHON vdN;
    int start = t->getNumVertices() - t->getNumFaceVertices();
    for (int j=start;j<t->getNumVertices();j++)
      vdN.v.push_back(t->getVertex(j));
    vdN.gf = gf;
    vdN.ts.push_back(t);
    optimizeNodeLocations(gf, vdN, .9);
  }
}

bool optimizeHighOrderMesh(GFace *gf, edgeContainer &edgeVertices)
{
  v2t_cont adjv;
  buildVertexToTriangle(gf->triangles, adjv);

  typedef std::map<std::pair<MVertex*, MVertex*>, std::vector<MElement*> > edge2tris;
  edge2tris e2t;
  for(unsigned int i = 0; i < gf->triangles.size(); i++){
    MTriangle *t = gf->triangles[i];
    for(int j = 0; j < t->getNumEdges(); j++){
      MEdge edge = t->getEdge(j);
      std::pair<MVertex*, MVertex*> p(edge.getMinVertex(), edge.getMaxVertex());
      e2t[p].push_back(t);
    }
  }
  /*
  v2t_cont :: iterator it = adjv.begin();      
  while (it != adjv.end()){
    MVertex *ver= it->first;
    GEntity *ge = ver->onWhat();
    if (ge->dim() == 2){
      double initu,initv;
      ver->getParameter(0, initu);
      ver->getParameter(1, initv);        

      smoothVertexDataHON vdN;
      vdN.ts = it->second;
      for (int i=0;i<vdN.ts.size();i++){
        MTriangle *t = vdN.ts[i];
      }

      vdN.v = e;
      vdN.gf = gf;

      double val;      
      double F = -smooth_obj_HighOrder(initu,initv, &vd);
      if (F < .2){
        minimize_2(smooth_obj_HighOrder, 
             deriv_smoothing_objective_function_HighOrder, &vd, 1, initu,initv,val);
        double Fafter = -smooth_obj_HighOrder(initu,initv, &vd);
        if (F < Fafter){
          success = true;
          ver->setParameter(0,initu);
          ver->setParameter(1,initv);
          GPoint gp = gf->point(initu,initv);
          ver->x() = gp.x();
          ver->y() = gp.y();
          ver->z() = gp.z();  
        }
      }                         
    }
    ++it;
  }
  */
  bool success = false;
  
  for(edge2tris::iterator it = e2t.begin(); it != e2t.end(); ++it){
    std::pair<MVertex*, MVertex*> edge = it->first;
    std::vector<MVertex*> e;
    std::vector<MElement*> triangles = it->second;
    if(triangles.size() == 2){
      MVertex *n2 = edge.first; 
      MVertex *n4 = edge.second;
      MTriangle *t1 = (MTriangle*)triangles[0];
      MTriangle *t2 = (MTriangle*)triangles[1];
      if(n2 < n4)
        e = edgeVertices[std::make_pair<MVertex*, MVertex*> (n2, n4)];
      else
        e = edgeVertices[std::make_pair<MVertex*, MVertex*> (n4, n2)];

      if (e.size() < 5){
        smoothVertexDataHON vdN;
        vdN.v = e;
        vdN.gf = gf;
        vdN.ts.clear();
        vdN.ts.push_back(t1);
        vdN.ts.push_back(t2);   
        optimizeNodeLocations(gf, vdN);
      }
    }
  }

  return success;
}

static void parametricCoordinates(MVertex *v, GFace *gf, double &uu, double &vv)
{
  SPoint2 param;
  reparamMeshVertexOnFace(v, gf, param);
  uu = param[0];
  vv = param[1];
}

static void getParametricCoordnates ( GFace *gf, 
                                      std::vector<MVertex*> &e,
                                      std::vector<SPoint2> &param)
{
  param.clear();
  for (unsigned int i = 0; i < e.size(); i++){
    double U,V;
    parametricCoordinates(e[i] , gf, U, V); 
    param.push_back(SPoint2(U,V));
  }
}

static void curvilinearEdgeSwap (GFace *gf, 
				 //				 int nPts,
				 edgeContainer &edgeVertices,
				 edge2tris::iterator &it,
				 edge2tris &e2t)
{
  std::pair<MVertex*, MVertex*> edge = it->first;
  std::vector<MElement*> triangles   = it->second;
  if(triangles.size() == 2){
      MVertex *n2 = edge.first; 
      MVertex *n4 = edge.second;
      MTriangle *t1 = (MTriangle*)triangles[0];
      MTriangle *t2 = (MTriangle*)triangles[1];
      MVertex *n1 = t1->getOtherVertex(n2, n4);
      MVertex *n3 = t2->getOtherVertex(n2, n4);
      std::vector<MVertex*> e1 = edgeVertices[std::make_pair<MVertex*, MVertex*>(std::min(n1, n2),std::max(n1, n2))];
      std::vector<MVertex*> e2 = edgeVertices[std::make_pair<MVertex*, MVertex*>(std::min(n2, n3),std::max(n2, n3))];
      std::vector<MVertex*> e3 = edgeVertices[std::make_pair<MVertex*, MVertex*>(std::min(n3, n4),std::max(n3, n4))];
      std::vector<MVertex*> e4 = edgeVertices[std::make_pair<MVertex*, MVertex*>(std::min(n4, n1),std::max(n4, n1))];
      std::vector<MVertex*> e  = edgeVertices[std::make_pair<MVertex*, MVertex*>(std::min(n2, n4),std::max(n2, n4))];
      //      std::vector<MVertex*> enew; 
      //      MLine temp (n1,n3);
      // should not add the nodes n the GFace here
      //      getEdgeVertices(gf,&temp, enew, false, nPts);
      // get the parametric coordinates of the 
      std::vector<SPoint2> ep1;  getParametricCoordnates (gf,e1,ep1);
      std::vector<SPoint2> ep2;  getParametricCoordnates (gf,e2,ep2);
      std::vector<SPoint2> ep3;  getParametricCoordnates (gf,e3,ep3);
      std::vector<SPoint2> ep4;  getParametricCoordnates (gf,e4,ep4);
      std::vector<SPoint2> ep;  getParametricCoordnates (gf,e ,ep );
      //      std::vector<SPoint2> epnew;  getParametricCoordnates (gf,enew,epnew);      
      localHarmonicMapping(gf->model(),t1,t2,n1,n2,n3,n4,e1,e2,e3,e4,e); 
  }
}

bool smoothInternalEdgesb(GFace *gf, edgeContainer &edgeVertices)
{
  typedef std::map<std::pair<MVertex*, MVertex*>, std::vector<MElement*> > edge2tris;
  edge2tris e2t;
  for(unsigned int i = 0; i < gf->triangles.size(); i++){
    MTriangle *t = gf->triangles[i];
    for(int j = 0; j < t->getNumEdges(); j++){
      MEdge edge = t->getEdge(j);
      std::pair<MVertex*, MVertex*> p(edge.getMinVertex(), edge.getMaxVertex());
      e2t[p].push_back(t);
    }
  }

  for(edge2tris::iterator it = e2t.begin(); it != e2t.end(); ++it){
    curvilinearEdgeSwap (gf,edgeVertices,it,e2t);
  }
  return true;
}

bool smoothInternalEdges(GFace *gf, edgeContainer &edgeVertices)
{
  typedef std::map<std::pair<MVertex*, MVertex*>, std::vector<MElement*> > edge2tris;
  edge2tris e2t;
  for(unsigned int i = 0; i < gf->triangles.size(); i++){
    MTriangle *t = gf->triangles[i];
    for(int j = 0; j < t->getNumEdges(); j++){
      MEdge edge = t->getEdge(j);
      std::pair<MVertex*, MVertex*> p(edge.getMinVertex(), edge.getMaxVertex());
      e2t[p].push_back(t);
    }
  }

  bool success = false;

  const int NBST = 10;

  for(edge2tris::iterator it = e2t.begin(); it != e2t.end(); ++it){
    std::pair<MVertex*, MVertex*> edge = it->first;
    std::vector<MVertex*> e1, e2, e3, e4, e;
    std::vector<MElement*> triangles = it->second;
    if(triangles.size() == 2){
      MVertex *n2 = edge.first; 
      MVertex *n4 = edge.second;
      MTriangle *t1 = (MTriangle*)triangles[0];
      MTriangle *t2 = (MTriangle*)triangles[1];
      MVertex *n1 = t1->getOtherVertex(n2, n4);
      MVertex *n3 = t2->getOtherVertex(n2, n4);
      
      double ang1 = angle3Points(n1,n2,n3);
      double ang2 = angle3Points(n2,n3,n4);
      double ang3 = angle3Points(n3,n4,n1);
      double ang4 = angle3Points(n4,n1,n2);
      const double angleLimit = 3*M_PI/4.;

      if (ang1 < angleLimit && ang2 < angleLimit && ang3 < angleLimit && ang4 < angleLimit){
	if(n1 < n2)
	  e1 = edgeVertices[std::make_pair<MVertex*, MVertex*>(n1, n2)];
	else
	  e1 = edgeVertices[std::make_pair<MVertex*, MVertex*>(n2, n1)];
	if(n2 < n3)
	  e2 = edgeVertices[std::make_pair<MVertex*, MVertex*>(n2, n3)];
	else
	  e2 = edgeVertices[std::make_pair<MVertex*, MVertex*>(n3, n2)];
	if(n3 < n4)
	  e3 = edgeVertices[std::make_pair<MVertex*, MVertex*>(n3, n4)];
	else
	  e3 = edgeVertices[std::make_pair<MVertex*, MVertex*>(n4, n3)];
	if(n4 < n1)
	  e4 = edgeVertices[std::make_pair<MVertex*, MVertex*>(n4, n1)];
	else
	  e4 = edgeVertices[std::make_pair<MVertex*, MVertex*>(n1, n4)];
	if(n2 < n4)
	  e = edgeVertices[std::make_pair<MVertex*, MVertex*>(n2, n4)];
	else
	  e = edgeVertices[std::make_pair<MVertex*, MVertex*>(n4, n2)];
	
	if((!straightLine(e1, n1, n2) || !straightLine(e2, n2, n3) ||
	    !straightLine(e3, n3, n4) || !straightLine(e4, n4, n1))){
	  
	  double Unew[NBST][10],Vnew[NBST][10];
	  double Xold[10],Yold[10],Zold[10];
	  
	  for(unsigned int i = 0; i < e.size(); i++){
	    Xold[i] = e[i]->x();
	    Yold[i] = e[i]->y();
	    Zold[i] = e[i]->z();
	  }
	  
	  double minJ = 1.e22;
	  double maxJ = -1.e22;       
	  getMinMaxJac (t1, minJ, maxJ);
	  getMinMaxJac (t2, minJ, maxJ);
	  int kopt = -1; 
	  for (int k=0;k<NBST;k++){
	    double relax = (k+1)/(double)NBST;
	    for(unsigned int i = 0; i < e.size(); i++){
	      double v = (double)(i + 1) / (e.size() + 1);
	      double u = 1. - v;
	      MVertex *vert  = (n2 < n4) ? e[i] : e[e.size() - i - 1];
	      MVertex *vert1 = (n1 < n2) ? e1[e1.size() - i - 1] : e1[i];
	      MVertex *vert3 = (n3 < n4) ? e3[i] : e3[e3.size() - i - 1];
	      MVertex *vert4 = (n4 < n1) ? e4[e4.size() - i - 1] : e4[i];
	      MVertex *vert2 = (n2 < n3) ? e2[i] : e2[e2.size() - i - 1];	    
	      double U1,V1,U2,V2,U3,V3,U4,V4,U,V,nU1,nV1,nU2,nV2,nU3,nV3,nU4,nV4;
	      parametricCoordinates(vert , gf, U, V);
	      parametricCoordinates(vert1, gf, U1, V1);
	      parametricCoordinates(vert2, gf, U2, V2);
	      parametricCoordinates(vert3, gf, U3, V3);
	      parametricCoordinates(vert4, gf, U4, V4);
	      parametricCoordinates(n1, gf, nU1, nV1);
	      parametricCoordinates(n2, gf, nU2, nV2);
	      parametricCoordinates(n3, gf, nU3, nV3);
	      parametricCoordinates(n4, gf, nU4, nV4);
	      
	      Unew[k][i] = U + relax * ((1.-u) * U4 + u * U2 +
					(1.-v) * U1 + v * U3 -
					((1.-u)*(1.-v) * nU1 
					 + u * (1.-v) * nU2 
					 + u * v * nU3 
					 + (1.-u) * v * nU4) - U);
	      Vnew[k][i] = V + relax * ((1.-u) * V4 + u * V2 +
					(1.-v) * V1 + v * V3 -
					((1.-u)*(1.-v) * nV1 
					 + u * (1.-v) * nV2 
					 + u * v * nV3 
					 + (1.-u) * v * nV4) - V);
	      GPoint gp = gf->point(Unew[k][i],Vnew[k][i]);
	      vert->x() = gp.x();
	      vert->y() = gp.y();
	      vert->z() = gp.z();
	    }
	    double minJloc = 1.e22;
	    double maxJloc = -1.e22;          
	    getMinMaxJac(t1, minJloc, maxJloc);
	    getMinMaxJac(t2, minJloc, maxJloc);
	    //	  printf("relax = %g min %g max %g\n",relax,minJloc,maxJloc);
	    
	    if (minJloc > minJ){
	      kopt = k;
	      minJ = minJloc;
	    }
	  }
	  //	kopt = 1;
	  if (kopt == -1){
	    for(unsigned int i = 0; i < e.size(); i++){
	      e[i]->x() = Xold[i];
	      e[i]->y() = Yold[i];
	      e[i]->z() = Zold[i];
	    }      
	  }
	  else{
	    success = true;
	    for(unsigned int i = 0; i < e.size(); i++){
	      MVertex *vert  = (n2 < n4) ? e[i] : e[e.size() - i - 1];
	      vert->setParameter(0,Unew[kopt][i]);
	      vert->setParameter(1,Vnew[kopt][i]);
	      GPoint gp = gf->point(Unew[kopt][i],Vnew[kopt][i]);
	      vert->x() = gp.x();
	      vert->y() = gp.y();
	      vert->z() = gp.z();
	    }      
	  }
	}
      }
    }
  }    
  return success;
}
