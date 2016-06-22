// Gmsh - Copyright (C) 1997-2015 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include <queue> // #mark
#include <stdlib.h>
#include "GmshConfig.h"

#if defined(HAVE_SOLVER) && defined(HAVE_ANN)

#include "GmshMessage.h"
#include "Octree.h"
#include "discreteDiskFace.h"
#include "discreteEdge.h"
#include "MTriangle.h"
#include "MEdge.h"
#include "Geo.h"
#include "Context.h"
#include "OS.h"
#include "ANN/ANN.h"
#include "linearSystemCSR.h"
#include "dofManager.h"
#include "laplaceTerm.h"
#include "convexLaplaceTerm.h"
#include "convexCombinationTerm.h"  // #FIXME

#include "qualityMeasuresJacobian.h" // #temporary?

static inline void functionShapes(int p, double Xi[2], double* phi)
{
  switch(p){

  case 1:
    phi[0] = 1. - Xi[0] - Xi[1];
    phi[1] = Xi[0];
    phi[2] = Xi[1];
    break;

  case 2:
    phi[0] = 1. - 3.*(Xi[0]+Xi[1]) + 2.*(Xi[0]+Xi[1])*(Xi[0]+Xi[1]);
    phi[1] = Xi[0]*(2.*Xi[0]-1);
    phi[2] = Xi[1]*(2.*Xi[1]-1);
    phi[3] = 4.*Xi[0]*(1.-Xi[0]-Xi[1]);
    phi[4] = 4.*Xi[0]*Xi[1];
    phi[5] = 4.*Xi[1]*(1.-Xi[0]-Xi[1]);
    break;

  default:
    Msg::Error("(discreteDiskFace) static inline functionShapes, only first "
               "and second order available; order %d requested.", p);
    break;
  }
}

static inline void derivativeShapes(int p, double Xi[2], double phi[6][2])
{
  switch(p){

  case 1:
    phi[0][0] = -1. ; phi[0][1] = -1.;
    phi[1][0] = 1.  ; phi[1][1] = 0.;
    phi[2][0] = 0.  ; phi[2][1] = 1.;
    break;

  case 2:
    phi[0][0] = -3. + 4.*(Xi[0]+Xi[1])   ; phi[0][1] = -3. + 4.*(Xi[0]+Xi[1]);
    phi[1][0] = 4.*Xi[0] - 1.            ; phi[1][1] = 0.;
    phi[2][0] = 0.                       ; phi[2][1] = 4.*Xi[1] - 1.;
    phi[3][0] = 4. - 8.*Xi[0] - 4.*Xi[1] ; phi[3][1] = -4.*Xi[0];
    phi[4][0] = 4.*Xi[1]                 ; phi[4][1] = 4.*Xi[0];
    phi[5][0] = -4.*Xi[1]                ; phi[5][1] = 4. - 4.*Xi[0] - 8.*Xi[1];
    break;

  default:
    Msg::Error("(discreteDiskFace) static inline derivativeShapes, only first and "
               "second order available; order %d requested.",p);
    break;
  }
}

static inline bool uv2xi(discreteDiskFaceTriangle* my_ddft, double U[2], double Xi[2])
{
  double M[2][2], R[2];
  const SPoint3 p0 = my_ddft->p[0];
  const SPoint3 p1 = my_ddft->p[1];
  const SPoint3 p2 = my_ddft->p[2];
  M[0][0] = p1.x() - p0.x();
  M[0][1] = p2.x() - p0.x();
  M[1][0] = p1.y() - p0.y();
  M[1][1] = p2.y() - p0.y();
  R[0] = (U[0] - p0.x());
  R[1] = (U[1] - p0.y());
  sys2x2(M, R, Xi);

  if (my_ddft->tri->getPolynomialOrder() == 2){

    int iter = 1, maxiter = 20;
    double error = 1., tol = 1.e-6;
    while (error > tol && iter < maxiter){// Newton-Raphson

      double fs[6];// phi_i
      functionShapes(2,Xi,fs);
      double ds[6][2];// dPhi_i/dXi_j
      derivativeShapes(2,Xi,ds);

      double un[2] = {0.,0.};
      double jac[2][2] = {{0.,0.},{0.,0.}}; // d(u,v)/d(xi,eta)
      for (int i=0; i<6; i++){
	double ui[2] = {my_ddft->p[i].x(),my_ddft->p[i].y()};
	for(int k=0; k<2; k++){
	  un[k] += ui[k] * fs[i];
	  for (int j=0; j<2; j++)
	    jac[k][j] += ui[k] * ds[i][j];
	}
      }

      double inv[2][2];
      inv2x2(jac,inv);
      double xin[2] = {Xi[0],Xi[1]};
      error = 0.;
      for (int i=0; i<2; i++){
	for (int j=0; j<2; j++)
	  xin[i] += inv[i][j] * (U[j] - un[j]);
	error += (xin[i] - Xi[i])*(xin[i] - Xi[i]);
      }

      error = sqrt(error);
      Xi[0] = xin[0];
      Xi[1] = xin[1];
      iter++;

    } // end Newton-Raphson
    if (iter == maxiter){
      return false;
    }
  }// end order 2
  return true;
}

// The three following things are mandatory to manipulate octrees (octree in (u;v)).
static void discreteDiskFaceBB(void *a, double*mmin, double*mmax)
{
  discreteDiskFaceTriangle *t = (discreteDiskFaceTriangle *)a;

  mmin[0] = std::min(std::min(t->p[0].x(), t->p[1].x()), t->p[2].x());
  mmin[1] = std::min(std::min(t->p[0].y(), t->p[1].y()), t->p[2].y());
  mmax[0] = std::max(std::max(t->p[0].x(), t->p[1].x()), t->p[2].x());
  mmax[1] = std::max(std::max(t->p[0].y(), t->p[1].y()), t->p[2].y());

  if (t->tri->getPolynomialOrder() == 2){
    for (int i=3; i<6; i++){
      int j = i==5 ? 0 : i-2;
      double du = t->p[i].x() - (t->p[i-3].x() + t->p[j].x())/2.;
      double dv = t->p[i].y() - (t->p[i-3].y() + t->p[j].y())/2.;
      mmin[0] = std::min(mmin[0],t->p[i].x()+du);
      mmin[1] = std::min(mmin[1],t->p[i].y()+dv);
      mmax[0] = std::max(mmax[0],t->p[i].x()+du);
      mmax[1] = std::max(mmax[1],t->p[i].y()+dv);
    }
  }
  mmin[2] = -1;
  mmax[2] = 1;
}

static void discreteDiskFaceCentroid(void *a, double*c)
{
  discreteDiskFaceTriangle *t = (discreteDiskFaceTriangle *)a;
  c[0] = (t->p[0].x() + t->p[1].x() + t->p[2].x()) / 3.0;
  c[1] = (t->p[0].y() + t->p[1].y() + t->p[2].y()) / 3.0;
  c[2] = 0.0;
}

static int discreteDiskFaceInEle(void *a, double*c)// # mark
{
  discreteDiskFaceTriangle *t = (discreteDiskFaceTriangle *)a;
  double Xi[2];
  double U[2] = {c[0],c[1]};
  bool ok = uv2xi(t,U,Xi);
  double eps = 1e-8;

  if(ok && Xi[0] > -eps && Xi[1] > -eps && 1. - Xi[0] - Xi[1] > -eps)
    return 1;

  return 0;
}

static bool orderVertices(const double &tot_length, const std::vector<MVertex*> &l,
                          std::vector<double> &coord)
{ // called once by constructor ; organize the vertices for the linear system
  // expressing the mapping
  coord.clear();
  coord.push_back(0.);

  MVertex* first = l[0];

  for(unsigned int i=1; i < l.size(); i++){

    MVertex* next = l[i];

    const double length = sqrt( (next->x() - first->x()) * (next->x() - first->x()) +
				(next->y() - first->y()) * (next->y() - first->y()) +
				(next->z() - first->z()) * (next->z() - first->z()) );

    coord.push_back(coord[coord.size()-1] + length / tot_length);
    
    first = next;

  }
  return true;
}

/*BUILDER*/
discreteDiskFace::discreteDiskFace(GFace *gf, triangulation* diskTriangulation,
                                   int p, std::vector<GFace*> *CAD) :
  GFace(gf->model(),123), _parent (gf), _ddft(NULL), oct(NULL)
{
  initialTriangulation = diskTriangulation;
  std::vector<MElement*> mesh = diskTriangulation->tri;
  _order = p;
  _N = (p+1)*(p+2)/2;
  discrete_triangles.resize(mesh.size());
  std::map<MVertex*,MVertex*> v2v;// mesh vertex |-> face vertex
  std::map<MEdge,MVertex*,Less_Edge> ed2nodes; // edge to interior node(s)
  for (unsigned int i=0;i<mesh.size();i++){ // triangle by triangle
    std::vector<MVertex*> vs; // MTriangle vertices
    for (unsigned int j=0; j<3; j++){ // loop over vertices AND edges of the current triangle
      MVertex *v = mesh[i]->getVertex(j);// firstly, edge vertices
      if (v->onWhat()->dim() == 2) {
	std::map<MVertex*,MVertex*> :: iterator it = v2v.find(v);
	if (it == v2v.end()){
	  MFaceVertex *vv;
	  if (!CAD) vv  = new MFaceVertex ( v->x(),  v->y(),  v->z(), v->onWhat(), 0, 0);
	  else{
	    GFace *cad = (*CAD)[i];
	    if(cad != v->onWhat())
              Msg::Fatal("Line %d FILE %s : erroneous cad list",__LINE__,__FILE__);
	    double pu,pv; v->getParameter(0,pu);v->getParameter(1,pv);
	    vv  = new MFaceVertex ( v->x(),  v->y(),  v->z(), v->onWhat(), pu, pv);
	  }
	  v2v[v] = vv;
	  discrete_vertices.push_back(vv);
	  vs.push_back(vv);
	}
	else vs.push_back(it->second);
      }
      else if (v->onWhat()->dim() == 1){
	if (v->onWhat()->geomType() == DiscreteCurve){
	  discreteEdge *de = dynamic_cast<discreteEdge*> (v->onWhat());
	  vs.push_back(de->getGeometricalVertex(v));
	}
	else vs.push_back(v);
      }
      else vs.push_back(v);          
    }
    if (_order == 2) {// then, interior nodes :-)
      for (unsigned int ie=0; ie<3; ie++){ // firstly, edge interior nodes :-)
	MEdge me = mesh[i]->getEdge(ie); // check if edge already visited
	std::map<MEdge,MVertex*,Less_Edge>::iterator it = ed2nodes.find(me);
	if(it == ed2nodes.end()){
	  SPoint3 c = me.barycenter();
	  MVertex* mv = new MVertex(c.x(),c.y(),c.z(),gf);
	  vs.push_back(mv);
	  discrete_vertices.push_back(mv);
	  ed2nodes[me]=mv;
	}
	else vs.push_back(it->second);	
      }
    }// end order == 2
    if (_order==1)
      discrete_triangles[i] = new MTriangle (vs);
    else if (_order==2)
      discrete_triangles[i] = new MTriangle6 (vs);
        
  }// end loop over triangles
  geoTriangulation = new triangulation(discrete_triangles,gf);
  allNodes = geoTriangulation->vert;
  _totLength = geoTriangulation->bord.rbegin()->first;
  _U0 = geoTriangulation->bord.rbegin()->second;
  orderVertices(_totLength, _U0, _coords);
  parametrize(false);
  buildOct(CAD);
  
  if (!checkOrientationUV()){
    Msg::Info("discreteDiskFace:: parametrization is not one-to-one; fixing "
              "the discrete system.");
    parametrize(true);
    buildOct(CAD);    
  }
  
  putOnView(true,false);
  printParamMesh();
  if(!checkOrientationUV()) Msg::Fatal("discreteDiskFace:: failing to fix the discrete system");
}
/*end BUILDER*/

discreteDiskFace::~discreteDiskFace()
{
  triangles.clear();
  if (_ddft) delete[] _ddft;
  if (oct) Octree_Delete(oct);
  if(geoTriangulation) delete geoTriangulation;
}

void discreteDiskFace::buildOct(std::vector<GFace*> *CAD) const
{
  if (oct)Octree_Delete(oct);

  double origin[3] = {-1.01,-1.01,-1.0};
  double ssize[3] = {2.02,2.02,2.0};
  const int maxElePerBucket = 15;
  oct = Octree_Create(maxElePerBucket, origin, ssize, discreteDiskFaceBB,
		      discreteDiskFaceCentroid, discreteDiskFaceInEle);

  _ddft = new discreteDiskFaceTriangle[discrete_triangles.size()];

  //  if (CAD) printf("------------->  %ld %ld\n",CAD->size(),discrete_triangles.size());

  for(unsigned int i = 0; i < discrete_triangles.size(); ++i){
    MElement *t = discrete_triangles[i];
    discreteDiskFaceTriangle* my_ddft = &_ddft[i];
    my_ddft->p.resize(_N);
    for(int io=0; io<_N; io++)
      my_ddft->p[io] = coordinates[t->getVertex(io)];

    my_ddft->gf = CAD ? (*CAD)[i] : _parent;
    my_ddft->tri = t;

    Octree_Insert(my_ddft, oct);
  }
  Octree_Arrange(oct);
}

bool discreteDiskFace::parametrize(bool one2one) const
{ // #improveme

  if (one2one)
    Msg::Info("Parametrizing surface %d with 'one-to-one map'", tag());
  else
    Msg::Info("Parametrizing surface %d with 'harmonic map'", tag());

  linearSystem<double> *lsys_u;
  linearSystem<double> *lsys_v;

  lsys_u = new linearSystemCSRTaucs<double>; // taucs :-)
  lsys_v = new linearSystemCSRTaucs<double>; // taucs :-)

  dofManager<double> myAssemblerU(lsys_u);   // hashing
  dofManager<double> myAssemblerV(lsys_v);

  for(size_t i = 0; i < _U0.size(); i++){
    MVertex *v = _U0[i];
    const double theta = 2 * M_PI * _coords[i];
    if(i%_order==0){
      myAssemblerU.fixVertex(v, 0, 1,cos(theta));
      myAssemblerV.fixVertex(v, 0, 1,sin(theta));
    }
    else{//#TEST
      myAssemblerU.fixVertex(v, 0, 1,1./_order*((_order-(i%_order))*cos(2*M_PI*_coords[i-(i%_order)])+(i%_order)*cos(2*M_PI*_coords[i+(_order-(i%_order))])));
      myAssemblerV.fixVertex(v, 0, 1,1./_order*((_order-(i%_order))*sin(2*M_PI*_coords[i-(i%_order)])+(i%_order)*sin(2*M_PI*_coords[i+(_order-(i%_order))])));
    }
  }

  for(size_t i = 0; i < discrete_triangles.size(); ++i){
    MElement *t = discrete_triangles[i];
    for(int j=0; j<t->getNumVertices(); j++){
      myAssemblerU.numberVertex(t->getVertex(j), 0, 1);
      myAssemblerV.numberVertex(t->getVertex(j), 0, 1);
    }
  }

  Msg::Debug("Creating term %d dofs numbered %d fixed",
	     myAssemblerU.sizeOfR() + myAssemblerV.sizeOfR(),
             myAssemblerU.sizeOfF() + myAssemblerV.sizeOfF());

  double t1 = Cpu();

  simpleFunction<double> ONE(1.0);

  if (one2one){
    convexLaplaceTerm mappingU(0, 1, &ONE);
    convexLaplaceTerm mappingV(0, 1, &ONE);

    for(unsigned int i = 0; i < discrete_triangles.size(); ++i){
      SElement se(discrete_triangles[i]);
      mappingU.addToMatrix(myAssemblerU, &se);
      mappingV.addToMatrix(myAssemblerV, &se);
    }
  }
  else{
    laplaceTerm mappingU(0, 1, &ONE);
    laplaceTerm mappingV(0, 1, &ONE);

    for(unsigned int i = 0; i < discrete_triangles.size(); ++i){
      SElement se(discrete_triangles[i]);
      mappingU.addToMatrix(myAssemblerU, &se);
      mappingV.addToMatrix(myAssemblerV, &se);
    }
  }

  double t2 = Cpu();
  Msg::Debug("Assembly done in %8.3f seconds", t2 - t1);
  lsys_u->systemSolve();
  lsys_v->systemSolve();
  Msg::Debug("Systems solved");
  for(std::set<MVertex *>::iterator itv = allNodes.begin(); itv !=allNodes.end() ; ++itv){
    MVertex *v = *itv;
    double value_U, value_V;
    myAssemblerU.getDofValue(v, 0, 1, value_U);
    myAssemblerV.getDofValue(v, 0, 1, value_V);
    std::map<MVertex*,SPoint3>::iterator itf = coordinates.find(v);
    if(itf == coordinates.end()){
      SPoint3 p(0, 0, 0);
      p[0] = value_U;
      p[1] = value_V;
      coordinates[v] = p;
    }
    else{
      itf->second[0]= value_U;
      itf->second[1]= value_V;
    }
  }

  delete lsys_u;
  delete lsys_v;

  return true;
}

void discreteDiskFace::getTriangleUV(const double u,const double v,
				     discreteDiskFaceTriangle **mt,
				     double &_xi, double &_eta)const{
  double uv[3] = {u,v,0.};
  *mt = (discreteDiskFaceTriangle*) Octree_Search(uv,oct);
  if (!(*mt)) return;

  double Xi[2];
  double U[2] = {u,v};
  bool pass = uv2xi(*mt,U,Xi);
  if (!pass){
    Msg::Error("discreteDiskFace::getTriangleUV(), didn't find the reference coordinate (xi;eta) for (u;v)=(%f;%f)",u,v);
    return;
  }
  _xi = Xi[0];
  _eta = Xi[1];
}

bool discreteDiskFace::checkOrientationUV()
{
  discreteDiskFaceTriangle *ct;

  if(_order==1){
    double initial, current; // initial and current orientation
    ct = &_ddft[0];
    double p1[2] = {ct->p[0].x(), ct->p[0].y()};
    double p2[2] = {ct->p[1].x(), ct->p[1].y()};
    double p3[2] = {ct->p[2].x(), ct->p[2].y()};
    initial = robustPredicates::orient2d(p1, p2, p3);
    unsigned int i=1;
    for (; i<discrete_triangles.size(); i++){
      ct = &_ddft[i];
      p1[0] = ct->p[0].x(); p1[1] = ct->p[0].y();
      p2[0] = ct->p[1].x(); p2[1] = ct->p[1].y();
      p3[0] = ct->p[2].x(); p3[1] = ct->p[2].y();
      current = robustPredicates::orient2d(p1, p2, p3);
      if(initial*current < 0.) {
	Msg::Error("Triangle UV %d has not the correct orientation",i+1);
	return false;
	break;
      }
    }
    return true;
  }
  else{
    double min, max;
    std::vector<MVertex*> localVertices;
    localVertices.resize(_N);
    for(unsigned int i=0; i<discrete_triangles.size(); i++){
      ct = &_ddft[i];
      for(int j=0; j<_N; j++)
	localVertices[j] = new MVertex(ct->p[j].x(),ct->p[j].y(),0.);
      MTriangle6 mt6(localVertices);
      jacobianBasedQuality::minMaxJacobianDeterminant(&mt6,min,max);
      for(int j=0; j<_N; j++)
	delete localVertices[j];
      if (min < 0){
	return false;
	break;
      }
    }
    return true;
  }
}

// (u;v) |-> < (x;y;z); GFace; (u;v) >
GPoint discreteDiskFace::point(const double par1, const double par2) const
{
  double xi,eta;
  double par[2] = {par1,par2};
  discreteDiskFaceTriangle* dt = NULL;
  getTriangleUV(par1,par2,&dt,xi,eta);// return Xi,Eta
  double Xi[2] = {xi,eta};
  if (!dt) {
    GPoint gp = GPoint(1.e22,1.e22,1.e22,_parent,par);
    gp.setNoSuccess();
    return gp;
  }

  std::vector<double> eval(_N);
  functionShapes(_order,Xi,&eval[0]);
  double X=0,Y=0,Z=0;
  for(int io=0; io<_N; io++){
    X += dt->tri->getVertex(io)->x()*eval[io];
    Y += dt->tri->getVertex(io)->y()*eval[io];
    Z += dt->tri->getVertex(io)->z()*eval[io];
  }
  return GPoint(X,Y,Z,_parent,par);
}

SPoint2 discreteDiskFace::parFromVertex(MVertex *v) const
{
  if (v->onWhat() == this){
    double uu,vv;
    v->getParameter(0,uu);
    v->getParameter(1,vv);
    return SPoint2(uu,vv);
  }

  std::map<MVertex*,SPoint3>::iterator it = coordinates.find(v);
  if(it != coordinates.end()) return SPoint2(it->second.x(),it->second.y());
  // The 1D mesh has been re-done
  if (v->onWhat()->dim()==1){
    if (v->onWhat()->geomType() == DiscreteCurve){
      discreteEdge *de = dynamic_cast<discreteEdge*> (v->onWhat());
      if (de){
	MVertex *v1,*v2;
	double xi;
	de->interpolateInGeometry (v,&v1,&v2,xi); // modify
	std::map<MVertex*,SPoint3>::iterator it1 = coordinates.find(v1);
	std::map<MVertex*,SPoint3>::iterator it2 = coordinates.find(v2);
	if(it1 == coordinates.end()) Msg::Fatal("FIXME TO DO %d %s",__LINE__,__FILE__);
	if(it2 == coordinates.end()) Msg::Fatal("FIXME TO DO %d %s",__LINE__,__FILE__);
	return SPoint2(it1->second.x(),it1->second.y()) * (1.-xi) +
	  SPoint2(it2->second.x(),it2->second.y()) * xi; // modify
      }
    }
    Msg::Fatal("FIXME TO DO %d %s",__LINE__,__FILE__);
  }
  else if (v->onWhat()->dim()==0)
    Msg::Fatal("discreteDiskFace::parFromVertex vertex classified on a model "
               "vertex that is not part of the face");

  return SPoint2(0,0);
}

SVector3 discreteDiskFace::normal(const SPoint2 &param) const
{
  return GFace::normal(param);
}

double discreteDiskFace::curvatureMax(const SPoint2 &param) const
{
  throw;
  return false;
}

double discreteDiskFace::curvatures(const SPoint2 &param, SVector3 *dirMax, SVector3 *dirMin,
				    double *curvMax, double *curvMin) const
{
  throw;
  return false;
}

Pair<SVector3, SVector3> discreteDiskFace::firstDer(const SPoint2 &param) const
{
  double xi,eta;
  discreteDiskFaceTriangle* ddft = NULL;
  getTriangleUV(param.x(),param.y(),&ddft,xi,eta);

  MElement* tri = NULL;
  if (ddft) tri = ddft->tri;
  else {
    Msg::Warning("discreteDiskFace::firstDer << triangle not found %g %g",param[0],param[1]);
    return Pair<SVector3, SVector3>(SVector3(1,0,0), SVector3(0,1,0));
  }

  double Xi[2] = {xi,eta};
  double df[6][2];
  derivativeShapes(_order,Xi,df);
  double dxdxi[3][2] = {{0.,0.},{0.,0.},{0.,0.}};

  double dudxi[2][2] = {{0.,0.},{0.,0.}};

  for (int io=0; io<_N; io++){

    double X = tri->getVertex(io)->x();
    double Y = tri->getVertex(io)->y();
    double Z = tri->getVertex(io)->z();

    double U = ddft->p[io].x();
    double V = ddft->p[io].y();

    dxdxi[0][0] += X*df[io][0];
    dxdxi[0][1] += X*df[io][1];

    dxdxi[1][0] += Y*df[io][0];
    dxdxi[1][1] += Y*df[io][1];

    dxdxi[2][0] += Z*df[io][0];
    dxdxi[2][1] += Z*df[io][1];

    dudxi[0][0] += U*df[io][0];
    dudxi[0][1] += U*df[io][1];

    dudxi[1][0] += V*df[io][0];
    dudxi[1][1] += V*df[io][1];

  }

  double dxidu[2][2];
  inv2x2(dudxi,dxidu);

  double dxdu[3][2];

  for (int i=0;i<3;i++){
    for (int j=0;j<2;j++){
      dxdu[i][j]=0.;
      for (int k=0;k<2;k++){
	dxdu[i][j] += dxdxi[i][k]*dxidu[k][j];
      }
    }
  }

  return Pair<SVector3, SVector3>(SVector3(dxdu[0][0],dxdu[1][0],dxdu[2][0]),
				  SVector3(dxdu[0][1],dxdu[1][1],dxdu[2][1]));
}

void discreteDiskFace::secondDer(const SPoint2 &param,
				 SVector3 *dudu, SVector3 *dvdv, SVector3 *dudv) const
{ // cf Sauvage's thesis
  return;
}

void discreteDiskFace::putOnView(bool Xu, bool Ux)
{

  char mybuffer [64];
  
  FILE *view_u=NULL, *view_v=NULL, *UVx=NULL, *UVy=NULL, *UVz=NULL;

  

  if(Xu){
   
    sprintf(mybuffer, "param_u_part%d_order%d.pos",
	    initialTriangulation->idNum,_order);
    view_u = Fopen(mybuffer,"w");

    sprintf(mybuffer, "param_v_part%d_order%d.pos",
	    initialTriangulation->idNum,_order);
    view_v = Fopen(mybuffer,"w");
  }
  if(Ux){

    sprintf(mybuffer, "UVx_part%d_order%d.pos",
	    initialTriangulation->idNum,_order);
  
    UVx = Fopen(mybuffer,"w");

    sprintf(mybuffer, "UVy_part%d_order%d.pos",
	    initialTriangulation->idNum,_order);
    UVy = Fopen(mybuffer,"w");

    sprintf(mybuffer, "UVz_part%d_order%d.pos",
	    initialTriangulation->idNum,_order);
    UVz = Fopen(mybuffer,"w");
  }
  
  if((Xu && view_u && view_v) || (Ux && UVx && UVy && UVz)){
    if(Xu){
      fprintf(view_u,"View \"u(X)\"{\n");
      fprintf(view_v,"View \"v(X)\"{\n");
    }
    if(Ux){
      fprintf(UVx,"View \"x(U)\"{\n");
      fprintf(UVy,"View \"y(U)\"{\n");
      fprintf(UVz,"View \"z(U)\"{\n");
    }
    for (unsigned int i=0; i<discrete_triangles.size(); i++){
      discreteDiskFaceTriangle* my_ddft = &_ddft[i];
      if (_order == 1){
	if(Xu){
	  fprintf(view_u,"ST(");
	  fprintf(view_v,"ST(");
	}
	if(Ux){
	  fprintf(UVx,"ST(");
	  fprintf(UVy,"ST(");
	  fprintf(UVz,"ST(");
	}
      }
      else{
	if(Xu){
	  fprintf(view_u,"ST%d(",_order);
	  fprintf(view_v,"ST%d(",_order);
	}
	if(Ux){
	  fprintf(UVx,"ST%d(",_order);
	  fprintf(UVy,"ST%d(",_order);
	  fprintf(UVz,"ST%d(",_order);
	}
      }
      for (int j=0; j<_N-1; j++){
	if(Xu){
	  fprintf(view_u,"%g,%g,%g,",my_ddft->tri->getVertex(j)->x(),
		  my_ddft->tri->getVertex(j)->y(),my_ddft->tri->getVertex(j)->z());
	  fprintf(view_v,"%g,%g,%g,",my_ddft->tri->getVertex(j)->x(),
		  my_ddft->tri->getVertex(j)->y(),my_ddft->tri->getVertex(j)->z());
	}
	if(Ux){
	  fprintf(UVx,"%g,%g,%g,",my_ddft->p[j].x(),my_ddft->p[j].y(),0.);
	  fprintf(UVy,"%g,%g,%g,",my_ddft->p[j].x(),my_ddft->p[j].y(),0.);
	  fprintf(UVz,"%g,%g,%g,",my_ddft->p[j].x(),my_ddft->p[j].y(),0.);
	}
      }
      if(Xu){
	fprintf(view_u,"%g,%g,%g){",my_ddft->tri->getVertex(_N-1)->x(),
		my_ddft->tri->getVertex(_N-1)->y(),my_ddft->tri->getVertex(_N-1)->z());
	fprintf(view_v,"%g,%g,%g){",my_ddft->tri->getVertex(_N-1)->x(),
		my_ddft->tri->getVertex(_N-1)->y(),my_ddft->tri->getVertex(_N-1)->z());
      }
      if(Ux){
	fprintf(UVx,"%g,%g,%g){",my_ddft->p[_N-1].x(),my_ddft->p[_N-1].y(),0.);
	fprintf(UVy,"%g,%g,%g){",my_ddft->p[_N-1].x(),my_ddft->p[_N-1].y(),0.);
	fprintf(UVz,"%g,%g,%g){",my_ddft->p[_N-1].x(),my_ddft->p[_N-1].y(),0.);
      }
      for (int j=0; j<_N-1; j++){
	if(Xu){
	  fprintf(view_u,"%g,",my_ddft->p[j].x());
	  fprintf(view_v,"%g,",my_ddft->p[j].y());
	}
	if(Ux){
	  fprintf(UVx,"%g,",my_ddft->tri->getVertex(j)->x());
	  fprintf(UVy,"%g,",my_ddft->tri->getVertex(j)->y());
	  fprintf(UVz,"%g,",my_ddft->tri->getVertex(j)->z());
	}
      }
      if(Xu){
	fprintf(view_u,"%g};\n",my_ddft->p[_N-1].x());
	fprintf(view_v,"%g};\n",my_ddft->p[_N-1].y());
      }
      if(Ux){
	fprintf(UVx,"%g};\n",my_ddft->tri->getVertex(_N-1)->x());
	fprintf(UVy,"%g};\n",my_ddft->tri->getVertex(_N-1)->y());
	fprintf(UVz,"%g};\n",my_ddft->tri->getVertex(_N-1)->z());
      }
    }
    if(Xu){
      fprintf(view_u,"};\n");
      fprintf(view_v,"};\n");
    }
    if(Ux){
      fprintf(UVx,"};\n");
      fprintf(UVy,"};\n");
      fprintf(UVz,"};\n");
    }
    if(Xu){
      fclose(view_u);
      fclose(view_v);
    }
    if(Ux){
      fclose(UVx);
      fclose(UVy);
      fclose(UVz);
    }
  }
}

// useful for mesh generators
// Intersection of a circle and a plane
GPoint discreteDiskFace::intersectionWithCircle(const SVector3 &n1, const SVector3 &n2,
						const SVector3 &p, const double &d,
						double uv[2]) const
{
  SVector3 n = crossprod(n1,n2);
  n.normalize();
  for (int i=-1;i<(int)discrete_triangles.size();i++){
    discreteDiskFaceTriangle *ct = NULL;
    double U,V;
    if (i == -1) getTriangleUV(uv[0],uv[1], &ct, U,V);
    else ct = &_ddft[i];
    if (!ct) continue;
    // we have two planes, defined with n1,n2 and t1,t2
    // we have then a direction m = (n1 x n2) x (t1 x t2)
    // and a point p that defines a straight line
    // the point is situated in the half plane defined
    // by direction n1 and point p (exclude the one on the
    // other side)
    SVector3 v0(ct->tri->getVertex(0)->x(),ct->tri->getVertex(0)->y(),
                ct->tri->getVertex(0)->z());
    SVector3 v1(ct->tri->getVertex(1)->x(),ct->tri->getVertex(1)->y(),
                ct->tri->getVertex(1)->z());
    SVector3 v2(ct->tri->getVertex(2)->x(),ct->tri->getVertex(2)->y(),
                ct->tri->getVertex(2)->z());
    SVector3 t1  = v1 - v0;
    SVector3 t2  = v2 - v0;
    // let us first compute point q to be the intersection
    // of the plane of the triangle with the line L = p + t n1
    // Compute w = t1 x t2 = (a,b,c) and write a point of the plabe as
    // X(x,y,z) = ax + by + cz - (v1_x a + v1_y b + v1_z * c) = 0
    // Then
    // a (p_x + t n1_x) + a (p_y + t n1_y) + c (p_z + t n1_z) -
    //    (v1_x a + v1_y b + v1_z * c) = 0
    // gives t
    SVector3 w = crossprod(t1,t2);
    double t = d;
    // if everything is not coplanar ...
    if (fabs(dot(n1,w)) > 1.e-12){
      t = dot(v0-p,w)/dot(n1,w);
    }
    SVector3 q = p + n1*t;
    // consider the line that intersects both planes in its
    // parametric form
    // X(x,y,z) = q + t m
    // We have now to intersect that line with the sphere
    // (x-p_x)^2 + (y-p_y)^2 + (z-p_z)^2 = d^2
    // Inserting the parametric form of the line into the sphere gives
    // (t m_x + q_x - p_x)^2 + (t m_y + q_y - p_y)^2  + (t m_z + q_z - p_z)^2  = d^2
    //  t^2 (m_x^2 + m_y^2 + m_z^2) + 2 t (m_x (q_x - p_x) + m_y (q_y - p_z) +
    //   m_z (q_z - p_z)) + ((q_x - p_x)^2 + (q_y - p_y)^2 + (q_z - p_z)^2 - d^2) = 0
    // t^2 m^2 + 2 t (m . (q-p)) + ((q-p)^2 - d^2) = 0
    // Let us call ta and tb the two roots
    // they correspond to two points s_1 = q + ta m and s_2 = q + tb m
    // we choose the one that corresponds to (s_i - p) . n1 > 0
    SVector3 m = crossprod(w,n);

    const double a = dot(m,m);
    const double b = 2*dot(m,q-p);
    const double c = dot(q-p,q-p) - d*d;
    const double delta = b*b-4*a*c;
    if (delta >= 0){
      const double ta = (-b + sqrt(delta)) / (2.*a);
      const double tb = (-b - sqrt(delta)) / (2.*a);
      SVector3 s1 = q + m * ta;
      SVector3 s2 = q + m * tb;
      SVector3 s;
      if (dot(s1-p,n1) > 0){
	s = s1;
      }
      else if (dot(s2-p,n1) > 0){
	s = s2;
      }
      else continue;

      // we have now to look if the point is inside the triangle
      // s = v1 + u t1 + v t2
      // we know the system has a solution because s is in the plane
      // defined by v1 and v2 we solve then
      // (s - v1) . t1 = u t1^2    + v t2 . t1
      // (s - v1) . t2 = u t1 . t2 + v t2^2

      double mat[2][2], b[2],uv[2];
      mat[0][0] = dot(t1,t1);
      mat[1][1] = dot(t2,t2);
      mat[0][1] = mat[1][0] = dot(t1,t2);
      b[0] = dot(s-v0,t1) ;
      b[1] = dot(s-v0,t2) ;
      sys2x2(mat,b,uv);
      // check now if the point is inside the triangle
      if (uv[0] >= -1.e-6 && uv[1] >= -1.e-6 &&
	  1.-uv[0]-uv[1] >= -1.e-6 ) {
	SVector3 pp =
	  ct->p[0] * ( 1.-uv[0]-uv[1] ) +
	  ct->p[1] * uv[0] +
	  ct->p[2] * uv[1] ;
	return GPoint(s.x(),s.y(),s.z(),this,pp);
      }
    }
  }
  GPoint pp(0);
  pp.setNoSuccess();
  Msg::Debug("ARGG no success intersection circle");
  return pp;
}

void discreteDiskFace::printParamMesh()
{
  std::map<MVertex*,int> mv2int;
  char buffer[16];
  sprintf(buffer,"param_mesh%d.msh",initialTriangulation->idNum);
  FILE* pmesh = Fopen(buffer,"w");
  int count = 1;
  fprintf(pmesh,"$MeshFormat\n2.2 0 8\n$EndMeshFormat\n$Nodes\n%u\n",(unsigned int)allNodes.size());
  for(std::set<MVertex*>::iterator it = allNodes.begin(); it!=allNodes.end(); ++it){
    fprintf(pmesh,"%d %f %f 0\n",count,(coordinates[(*it)]).x(),(coordinates[(*it)]).y());
    mv2int[*it] = count;
    count++;
  }
  fprintf(pmesh,"$EndNodes\n$Elements\n%u\n",(unsigned int)discrete_triangles.size());
  for(unsigned int i=0; i<discrete_triangles.size(); i++){
    MElement* tri = discrete_triangles[i];
    int p;
    _order == 1 ? p=2 : p=9;
      fprintf(pmesh,"%d %d 2 0 0",i+1,p);
    for(int j=0; j<_N; j++){
      MVertex* mv = tri->getVertex(j);
      fprintf(pmesh," %d",mv2int[mv]);
    }
    fprintf(pmesh,"\n");
  }
  fprintf(pmesh,"$EndElements\n");
  fclose(pmesh);
}

#endif
