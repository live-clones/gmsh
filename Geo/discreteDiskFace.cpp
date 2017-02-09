// Gmsh - Copyright (C) 1997-2015 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include <queue>
#include <stdlib.h>
#include "GmshConfig.h"

#if defined(HAVE_SOLVER) && defined(HAVE_ANN)

#include "GmshMessage.h"
#include "Octree.h"
#include "discreteDiskFace.h"
#include "discreteEdge.h"
#include "MTriangle.h"
#include "MEdge.h"
#include "GModelIO_GEO.h"
#include "Context.h"
#include "OS.h"
#include "ANN/ANN.h"
#include "convexCombinationTerm.h"

#if defined(HAVE_MESH)
#include "qualityMeasuresJacobian.h"
#endif

#if defined(HAVE_MUMPS)
#include "linearSystemMUMPS.h"
#endif


#if defined(HAVE_OPTHOM)
#include "OptHomRun.h"
#include "MeshQualityOptimizer.h"
#endif

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
  double eps = 1e-6;

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
  GFace(gf->model(),diskTriangulation->idNum), _parent (gf), _ddft(NULL), oct(NULL)
{
  initialTriangulation = diskTriangulation;
  std::vector<MElement*> mesh = diskTriangulation->tri;
  _order = p;
  _n = (p+1)*(p+2)/2;
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
  geoTriangulation = new triangulation(tag(),discrete_triangles,gf);
  geoTriangulation->fillingHoles = diskTriangulation->fillingHoles;
  allNodes = geoTriangulation->vert;
  _totLength = geoTriangulation->bord.rbegin()->first;
  _U0 = geoTriangulation->bord.rbegin()->second;
  orderVertices(_totLength, _U0, _coords);
  parametrize();
  buildOct(CAD);
  //putOnView(gf->tag(),diskTriangulation->idNum,true,true);
  //printParamMesh();
}
/*end BUILDER*/

discreteDiskFace::~discreteDiskFace()
{
  triangles.clear();
  if (_ddft) delete[] _ddft;
  if (oct) Octree_Delete(oct);
  if (geoTriangulation) delete geoTriangulation;
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
  int c = 0;
  for(unsigned int i = 0; i < discrete_triangles.size(); ++i){

    MElement *t = discrete_triangles[i];
    discreteDiskFaceTriangle* my_ddft = &_ddft[c++];
    my_ddft->p.resize(_n);
    for(int io=0; io<_n; io++)
      my_ddft->p[io] = coordinates[t->getVertex(io)];

    my_ddft->gf = CAD ? (*CAD)[i] : _parent;
    my_ddft->tri = t;

    Octree_Insert(my_ddft, oct);

  }
  Octree_Arrange(oct);
}


bool discreteDiskFace::parametrize() const
{ // #improveme

  linearSystem<double> * lsys_u, *lsys_v;


#ifdef HAVE_MUMPS
  lsys_u = new linearSystemMUMPS<double>;
  lsys_v = new linearSystemMUMPS<double>;
#else
  linearSystemCSRGmm<double> * lsys_u1 = new linearSystemCSRGmm<double>;
  linearSystemCSRGmm<double> * lsys_v1 = new linearSystemCSRGmm<double>;
  lsys_u1->setGmres(1);
  lsys_v1->setGmres(1);
  lsys_u=lsys_u1;
  lsys_v=lsys_v1;
#endif
  dofManager<double> myAssemblerU(lsys_u);   // hashing
  dofManager<double> myAssemblerV(lsys_v);

  for(size_t i = 0; i < _U0.size(); i++){
    MVertex *v = _U0[i];
    const double theta = 2 * M_PI * _coords[i];
    myAssemblerU.fixVertex(v, 0, 1,cos(theta));
    myAssemblerV.fixVertex(v, 0, 1,sin(theta));
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
  convexCombinationTerm mappingU(0, 1, &ONE);
  convexCombinationTerm mappingV(0, 1, &ONE);

  for(unsigned int i = 0; i < discrete_triangles.size(); ++i){
    SElement se(discrete_triangles[i]);
    mappingU.addToMatrix(myAssemblerU, &se);
    mappingV.addToMatrix(myAssemblerV, &se);
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
  Msg::Debug("Systems saved");

  delete lsys_u;
  delete lsys_v;

  Msg::Debug("Systems deleted");
  return true;
}



void discreteDiskFace::getTriangleUV(const double u,const double v,
				     discreteDiskFaceTriangle **mt,
				     double &_xi, double &_eta)const{
  double uv[3] = {u,v,0.};
  *mt = (discreteDiskFaceTriangle*) Octree_Search(uv,oct);
  if (!(*mt)) {
    for (unsigned int i=0; i<discrete_triangles.size()-geoTriangulation->fillingHoles.size(); i++){
      discreteDiskFaceTriangle *ct = &_ddft[i];
      double Xi[2];
      int xxx = discreteDiskFaceInEle(ct, Xi);
      if (xxx) {
	*mt = ct;
	_xi = Xi[0];
	_eta = Xi[1];
	return;
      }
    }
    Msg::Debug("discreteDiskFace::getTriangleUV(), didn't find the reference coordinate (xi;eta) for (u;v)=(%f;%f) among %d triangles",u,v,discrete_triangles.size()-geoTriangulation->fillingHoles.size());
    return;
  }

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
    double current; // initial and current orientation
    ct = &_ddft[0];
    double p1[2] = {ct->p[0].x(), ct->p[0].y()};
    double p2[2] = {ct->p[1].x(), ct->p[1].y()};
    double p3[2] = {ct->p[2].x(), ct->p[2].y()};
    unsigned int nbP = 0;
    unsigned int nbM = 0;
    for (unsigned int i=0; i<discrete_triangles.size(); i++){
      ct = &_ddft[i];
      p1[0] = ct->p[0].x(); p1[1] = ct->p[0].y();
      p2[0] = ct->p[1].x(); p2[1] = ct->p[1].y();
      p3[0] = ct->p[2].x(); p3[1] = ct->p[2].y();
      current = robustPredicates::orient2d(p1, p2, p3);
      if(current < 0.) nbM++;
      else nbP++;
    }
    if (nbP*nbM){
      Msg::Info("Map %d of the atlas : Triangles have different orientations (%d + / %d -)",tag(),nbP,nbM);
      return false;
    }
    return true;
  }
  else{
#if defined(HAVE_MESH)
    double min, max;
    std::vector<MVertex*> localVertices;
    localVertices.resize(_n);
    for(unsigned int i=0; i<discrete_triangles.size()-geoTriangulation->fillingHoles.size(); i++){
      ct = &_ddft[i];
      for(int j=0; j<_n; j++)
	localVertices[j] = new MVertex(ct->p[j].x(),ct->p[j].y(),0.);
      MTriangle6 mt6(localVertices);
      jacobianBasedQuality::minMaxJacobianDeterminant(&mt6,min,max);
      for(int j=0; j<_n; j++)
	delete localVertices[j];
      if (min < 0){
	return false;
	break;
      }
    }
#endif
    return true;
  }
}

// for second order parameterization
void discreteDiskFace::optimize()
{ // #improve . . .
#if defined(HAVE_OPTHOM)

  // parameters for mesh optimization
  // -- high order
  OptHomParameters optParams;
  optParams.dim = 2;
  optParams.optPassMax = 100;
  optParams.TMAX = 300;
  optParams.fixBndNodes = true;
  optParams.optPrimSurfMesh = true;
  optParams.BARRIER_MIN = 1e-3;
  optParams.BARRIER_MAX = 1e3;
  optParams.strategy = 0;
  // -- linear
  MeshQualOptParameters opt;
  opt.dim = 2;
  opt.fixBndNodes = true;

  //creating the "geometry" of the parametrization, and its corresponding mesh
  // -- generation of parametric nodes
  std::map<SPoint3,MVertex*> sp2mv;
  std::vector<MElement*> paramTriangles;
  for(std::map<MVertex*,SPoint3>::iterator it=coordinates.begin(); it!= coordinates.end(); ++it)
    sp2mv[it->second] = new MVertex(it->second.x(),it->second.y(),0.);
  // -- generation of parametric triangles
  paramTriangles.resize(discrete_triangles.size() - geoTriangulation->fillingHoles.size());
  for(unsigned int i=0; i<discrete_triangles.size() -geoTriangulation->fillingHoles.size(); i++){
    discreteDiskFaceTriangle* ct = &_ddft[i];
    std::vector<MVertex*> mv;
    mv.resize(ct->tri->getNumVertices());
    for (int j=0; j<ct->tri->getNumVertices(); j++)
      mv[j] = sp2mv[ct->p[j]];
    if(_order==1)
      paramTriangles[i] = new MTriangle(mv);
    else
      paramTriangles[i] = new MTriangle6(mv);
  }
  // -- generation of the parametric topology #mark what about the GFace for the GModel ?
  std::map<int,std::vector<MElement*> > e2e;// entity to element
  e2e[0] = paramTriangles;
  std::vector<int> v;
  v.push_back(0);
  std::map<int,std::vector<int> > e2p;// entity to physical
  e2p[0] = v;
  std::set<MVertex*> todelete;
  GModel* paramDisk = GModel::createGModel(e2e,e2p);
  // ---- discrete vertex
  std::set<GFace*, GEntityLessThan>::iterator it = paramDisk->firstFace();
  GFace *dgf = *it;
  discreteVertex *dv = new discreteVertex(paramDisk,paramDisk->getMaxElementaryNumber(0)+1);
  sp2mv[coordinates[_U0[0]]]->setEntity(dv);
  dv->mesh_vertices.push_back(sp2mv[coordinates[_U0[0]]]);
  todelete.insert(sp2mv[coordinates[_U0[0]]]);
  paramDisk->add(dv);
  // ---- discrete edge
  discreteEdge *de = new discreteEdge(paramDisk,paramDisk->getMaxElementaryNumber(1)+1,dv,dv);
  paramDisk->add(de);
  std::vector<MLine*> lines;
  for(unsigned int i=1; i<_U0.size(); i++){
    sp2mv[coordinates[_U0[i]]]->setEntity(de);
    de->mesh_vertices.push_back(sp2mv[coordinates[_U0[i]]]);
    todelete.insert(sp2mv[coordinates[_U0[i]]]);
    lines.push_back(new MLine(sp2mv[coordinates[_U0[i-1]]],sp2mv[coordinates[_U0[i]]]));
  }
  lines.push_back(new MLine(sp2mv[coordinates[_U0[_U0.size()-1]]],sp2mv[coordinates[_U0[0]]]));
  de->setTopo(lines);
  de->createGeometry();// !!!! setTopo ... MLine's



  // optimization
  if(_order >1)
    HighOrderMeshOptimizer(paramDisk, optParams);
  else
    MeshQualityOptimizer(paramDisk,opt);




  // update the parametrization
  paramTriangles = e2e[0];
  for(unsigned int i=0; i< paramTriangles.size(); i++){
    discreteDiskFaceTriangle* ct = &_ddft[i];
    MElement* tri = paramTriangles[i];
    for(int j=0; j<ct->tri->getNumVertices(); j++){
      MVertex* mv = tri->getVertex(j);
      SPoint3 p(mv->x(), mv->y(), 0);
      coordinates[ct->tri->getVertex(j)] = p;
      ct->p[j] = p;
    }
  }

  // update GFace's mesh_vertices
  std::vector<MVertex*> newMV;
  for(unsigned int imv=0; imv<dgf->mesh_vertices.size(); imv++){
    MVertex* current = dgf->mesh_vertices[imv];
    std::set<MVertex*>::iterator itmv = todelete.find(current);
    if (itmv==todelete.end()) newMV.push_back(current);
  }
  dgf->mesh_vertices.clear();
  dgf->mesh_vertices = newMV;

  // cleaning
  delete paramDisk;

#endif
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

  std::vector<double> eval(_n);
  functionShapes(_order,Xi,&eval[0]);
  double X=0,Y=0,Z=0;
  for(int io=0; io<_n; io++){
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

  for (int io=0; io<_n; io++){

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

void discreteDiskFace::putOnView(int iFace, int iMap, bool Xu, bool Ux)
{// #improveme  using built-in methods

  char mybuffer [64];

  FILE *view_u=NULL, *view_v=NULL, *UVx=NULL, *UVy=NULL, *UVz=NULL;



  if(Xu){
    sprintf(mybuffer, "param_u_gface%d_part%d_order%d.pos",
	    iFace, iMap,_order);
    view_u = Fopen(mybuffer,"w");

    sprintf(mybuffer, "param_v_gface%d_part%d_order%d.pos",
	    iFace, iMap,_order);
    view_v = Fopen(mybuffer,"w");
  }
  if(Ux){

    sprintf(mybuffer, "UVx_gface%d_part%d_order%d.pos",
	    iFace, iMap,_order);

    UVx = Fopen(mybuffer,"w");

    sprintf(mybuffer, "UVy_gface%d_part%d_order%d.pos",
	    iFace, iMap,_order);
    UVy = Fopen(mybuffer,"w");

    sprintf(mybuffer, "UVz_gface%d_part%d_order%d.pos",
	    iFace, iMap,_order);
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
    for (unsigned int i=0; i<discrete_triangles.size()-geoTriangulation->fillingHoles.size(); i++){
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
      for (int j=0; j<_n-1; j++){
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
	fprintf(view_u,"%g,%g,%g){",my_ddft->tri->getVertex(_n-1)->x(),
		my_ddft->tri->getVertex(_n-1)->y(),my_ddft->tri->getVertex(_n-1)->z());
	fprintf(view_v,"%g,%g,%g){",my_ddft->tri->getVertex(_n-1)->x(),
		my_ddft->tri->getVertex(_n-1)->y(),my_ddft->tri->getVertex(_n-1)->z());
      }
      if(Ux){
	fprintf(UVx,"%g,%g,%g){",my_ddft->p[_n-1].x(),my_ddft->p[_n-1].y(),0.);
	fprintf(UVy,"%g,%g,%g){",my_ddft->p[_n-1].x(),my_ddft->p[_n-1].y(),0.);
	fprintf(UVz,"%g,%g,%g){",my_ddft->p[_n-1].x(),my_ddft->p[_n-1].y(),0.);
      }
      for (int j=0; j<_n-1; j++){
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
	fprintf(view_u,"%g};\n",my_ddft->p[_n-1].x());
	fprintf(view_v,"%g};\n",my_ddft->p[_n-1].y());
      }
      if(Ux){
	fprintf(UVx,"%g};\n",my_ddft->tri->getVertex(_n-1)->x());
	fprintf(UVy,"%g};\n",my_ddft->tri->getVertex(_n-1)->y());
	fprintf(UVz,"%g};\n",my_ddft->tri->getVertex(_n-1)->z());
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
//FILE *allProblems = NULL;
//void openProblemsON(void){
//  allProblems = fopen ("op.pos","w");
//}
//void openProblemsOFF(void){
//  fclose(allProblems);
//  allProblems = NULL;
//}

GPoint discreteDiskFace::intersectionWithCircle(const SVector3 &n1, const SVector3 &n2,
						const SVector3 &p, const double &R,
						double uv[2]) const
{


  SVector3 n = crossprod(n1,n2);
  n.normalize();
  //  printf("n %g %g %g\n",n.x(), n.y(), n.z());
  const int N = (int)(discrete_triangles.size()-geoTriangulation->fillingHoles.size());
  for (int i=-1;i<N;i++){
    discreteDiskFaceTriangle *ct = NULL;
    double U,V;
    if (i == -1) getTriangleUV(uv[0],uv[1], &ct, U,V);
    else ct = &_ddft[i];
    if (!ct) continue;
    SVector3 v0(ct->tri->getVertex(0)->x(),ct->tri->getVertex(0)->y(),
                ct->tri->getVertex(0)->z());
    SVector3 v1(ct->tri->getVertex(1)->x(),ct->tri->getVertex(1)->y(),
                ct->tri->getVertex(1)->z());
    SVector3 v2(ct->tri->getVertex(2)->x(),ct->tri->getVertex(2)->y(),
                ct->tri->getVertex(2)->z());
    SVector3 t1  = v1 - v0;
    SVector3 t2  = v2 - v0;
    SVector3 t = crossprod(t1,t2);
    t.normalize();
    SVector3 d = crossprod(n,t);
    if (d.norm() < 1.e-12) continue;
    d.normalize();
    double rhs[2] = {dot(n,p), dot(v0,t)};
    double r[2];
    double m[2][2];
    SVector3 x0(0,0,0);
    m[0][0] = n.y();
    m[0][1] = n.z();
    m[1][0] = t.y();
    m[1][1] = t.z();
    if (fabs(det2x2(m)) > 1.e-12){
      sys2x2(m,rhs,r);
      x0 = SVector3(0,r[0],r[1]);
    }
    else {
      m[0][0] = n.x();
      m[0][1] = n.z();
      m[1][0] = t.x();
      m[1][1] = t.z();
      if (fabs(det2x2(m)) > 1.e-12){
	sys2x2(m,rhs,r);
	x0 = SVector3(r[0],0,r[1]);
      }
      else {
	m[0][0] = n.x();
	m[0][1] = n.y();
	m[1][0] = t.x();
	m[1][1] = t.y();
	if (sys2x2(m,rhs,r))	{
	  x0 = SVector3(r[0],r[1],0);
	}
	else{
	  //	  printf("mauvaise pioche\n");
	  continue;
	}
      }
    }

    const double a = 1.0;
    const double b = -2*dot(d,p-x0);
    const double c = dot(p-x0,p-x0) - R*R;
    const double delta = b*b-4*a*c;
    if (delta >= 0){
      double sign = (dot(n2,d) > 0)? 1.0:-1.0;
      const double ta = (-b + sign*sqrt(delta)) / (2.*a);
      const double tb = (-b - sign*sqrt(delta)) / (2.*a);
      SVector3 s[2] = {x0 + d * ta, x0 + d * tb};
      for (int IT=0;IT<2;IT++){
	double mat[2][2], b[2],uv[2];
	mat[0][0] = dot(t1,t1);
	mat[1][1] = dot(t2,t2);
	mat[0][1] = mat[1][0] = dot(t1,t2);
	b[0] = dot(s[IT]-v0,t1) ;
	b[1] = dot(s[IT]-v0,t2) ;
	sys2x2(mat,b,uv);
	// check now if the point is inside the triangle
	if (uv[0] >= -1.e-6 && uv[1] >= -1.e-6 &&
	    1.-uv[0]-uv[1] >= -1.e-6 ) {
	  SVector3 pp =
	    ct->p[0] * ( 1.-uv[0]-uv[1] ) +
	    ct->p[1] * uv[0] +
	    ct->p[2] * uv[1] ;
	  return GPoint(s[IT].x(),s[IT].y(),s[IT].z(),this,pp);
	}
      }
    }
  }
  GPoint pp(0);
  pp.setNoSuccess();
  Msg::Debug("ARGG no success intersection circle");
  //  Msg::Info("ARGG no success intersection circle");
  //  printf("Point(1) = {%g,%g,%g};\n",p.x(),p.y(),p.z());
  //  printf("Point(2) = {%g,%g,%g};\n",p.x()+d*n1.x(),p.y()+d*n1.y(),p.z()+d*n1.z());
  //  printf("Point(3) = {%g,%g,%g};\n",p.x()+d*n2.x(),p.y()+d*n2.y(),p.z()+d*n2.z());

  //  //  printf("Circle(4) = {2,1,3};\n");
  //  printf("{%g,%g,%g};\n",n1.x(),n1.y(),n1.z());
  //  printf("{%g,%g,%g};\n",n2.x(),n2.y(),n2.z());
  //  printf("coucou --> \n");
  //  if (allProblems){
  //    fprintf(allProblems,"VP(%g,%g,%g){%g,%g,%g};\n",p.x(),p.y(),p.z(),R*n2.x(),R*n2.y(),R*n2.z());
  //  }
  //  getchar();
  return pp;
}


GPoint discreteDiskFace::intersectionWithCircle2(const SVector3 &n1, const SVector3 &n2,
						const SVector3 &p, const double &d,
						double uv[2]) const
{

  // n2 is exterior
  SVector3 n = crossprod(n1,n2);
  n.normalize();
  for (int i=-1;i<(int)(discrete_triangles.size()-geoTriangulation->fillingHoles.size());i++){
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
      double sign = (dot(n2,m) > 0)? 1.0:-1.0;
      const double ta = (-b + sign*sqrt(delta)) / (2.*a);
      const double tb = (-b - sign*sqrt(delta)) / (2.*a);
      SVector3 s[2] =  {q + m * ta, q + m * tb};
      for (int IT=0;IT<2;IT++){
	double mat[2][2], b[2],uv[2];
	mat[0][0] = dot(t1,t1);
	mat[1][1] = dot(t2,t2);
	mat[0][1] = mat[1][0] = dot(t1,t2);
	b[0] = dot(s[IT]-v0,t1) ;
	b[1] = dot(s[IT]-v0,t2) ;
	sys2x2(mat,b,uv);
	// check now if the point is inside the triangle
	if (uv[0] >= -1.e-6 && uv[1] >= -1.e-6 &&
	    1.-uv[0]-uv[1] >= -1.e-6 ) {
	  SVector3 pp =
	    ct->p[0] * ( 1.-uv[0]-uv[1] ) +
	    ct->p[1] * uv[0] +
	    ct->p[2] * uv[1] ;
	  return GPoint(s[IT].x(),s[IT].y(),s[IT].z(),this,pp);
	}
      }
    }
  }
  GPoint pp(0);
  pp.setNoSuccess();
  //  Msg::Debug("ARGG no success intersection circle");
    Msg::Info("ARGG no success intersection circle");
  //  printf("Point(1) = {%g,%g,%g};\n",p.x(),p.y(),p.z());
  //  printf("Point(2) = {%g,%g,%g};\n",p.x()+d*n1.x(),p.y()+d*n1.y(),p.z()+d*n1.z());
  //  printf("Point(3) = {%g,%g,%g};\n",p.x()+d*n2.x(),p.y()+d*n2.y(),p.z()+d*n2.z());

  //  //  printf("Circle(4) = {2,1,3};\n");
  //  printf("{%g,%g,%g};\n",n1.x(),n1.y(),n1.z());
  //  printf("{%g,%g,%g};\n",n2.x(),n2.y(),n2.z());
  //  printf("coucou --> \n");
    //  if (allProblems){
    //    fprintf(allProblems,"VP(%g,%g,%g){%g,%g,%g};\n",p.x(),p.y(),p.z(),d*n2.x(),d*n2.y(),d*n2.z());
    //  }
  //  getchar();
  return pp;
}

// computes some kind of maximal distance in a mesh

static void addTo (std::map<MVertex*, std::vector<MElement*> > &v2t, MVertex *v, MElement *t)
{
  std::map<MVertex*, std::vector<MElement*> > :: iterator it = v2t.find(v);
  if (it == v2t.end()){
    std::vector<MElement*> tt; tt.push_back(t);
    v2t[v] = tt;
  }
  else it->second.push_back(t);
}

static void update(std::map<MVertex*,double> &Close, MVertex *v2, double d)
{
  std::map<MVertex*,double>::iterator it = Close.find(v2);
  if (it == Close.end())Close[v2] = d;
  else if (it->second > d) it->second=d;
  //  printf("DISTANCE COMPUTED %lf\n",d);

}

static MEdge getEdge (MElement *t, MVertex *v)
{
  for (int i=0;i<3;i++)
    if (t->getVertex(i) == v) return t->getEdge((i+1)%3);
  return MEdge();
}

/* #warning
static double computeDistanceLinePoint (MVertex *v1, MVertex *v2, MVertex *v){

  SVector3 U  = v2->point() - v1->point();
  SVector3 BA = v2->point() - v->point();

  SVector3 xx = crossprod(U,BA);
  return xx.norm() / U.norm();

}
*/
inline double computeDistance (MVertex *v1, double d1, MVertex *v2, double d2, MVertex *v){

  //       o------------a
  //
  //
  //    x
  //

  // x^2 + y^2 = d_1^2
  // (x-a)^2 + y^2 = d_2^2
  // 2ax - a^2 = d_1^2 - d_2^2

  //  printf("%p %p %p\n",v1,v2,v);

  return std::min(d2+v2->distance(v),d1+v1->distance(v));




  double a = v2->distance(v1);

  // center (seed) to compute the distance (put it down)
  double x0 = 0.5*(d1*d1-d2*d2+a*a)/a;
  double y0 = -sqrt ( d1*d1 - x0*x0);
  //  printf("a %g x0 %g %g d %g %g\n",a,x0,y0,d1,d2);

  // compute coordinates of v in the same system
  d1 = v1->distance(v);
  d2 = v2->distance(v);
  double xv = 0.5*(d1*d1-d2*d2+a*a)/a;
  double yv = +sqrt ( d1*d1 - x0*x0);
  return sqrt ((x0-xv)*(x0-xv)+(y0-yv)*(y0-yv));
}

std::map<MVertex*,double>::iterator closest (std::map<MVertex*,double> &Close)
{
  std::map<MVertex*,double>::iterator itClose;
  double c = 1.e22;
  for (std::map<MVertex*,double>::iterator it = Close.begin(); it != Close.end(); ++it){
    if (it->second < c){
      c = it->second;
      itClose = it;
    }
  }
  return itClose;
}

double triangulation::geodesicDistance ()
{
  if (bord.empty())return 1.e22;
  std::map<MVertex*, std::vector<MElement*> > v2t;
  for (size_t i=0;i<tri.size();++i){
    addTo (v2t, tri[i]->getVertex(0),tri[i]);
    addTo (v2t, tri[i]->getVertex(1),tri[i]);
    addTo (v2t, tri[i]->getVertex(2),tri[i]);
  }

  //  printf("computing geodesic distance with %d triangles and %d vertices\n",
  //	 tri.size(),v2t.size());

  std::map<MVertex*,double> Fixed;
  std::map<MVertex*,double> Close;

  unsigned int N = bord.rbegin()->second.size() ;
  for (unsigned int i = 0; i< N ; i++)
    Fixed[bord.rbegin()->second[i]]=0.0;

  //  printf("starting with %d vertices on the boundary\n",Fixed.size());

  for (size_t i=0;i<tri.size();++i){
    MVertex *v0 = tri[i]->getVertex(0);
    MVertex *v1 = tri[i]->getVertex(1);
    MVertex *v2 = tri[i]->getVertex(2);

    std::map<MVertex*,double>::iterator it0 = Fixed.find(v0);
    std::map<MVertex*,double>::iterator it1 = Fixed.find(v1);
    std::map<MVertex*,double>::iterator it2 = Fixed.find(v2);

    if (it0 != Fixed.end() && it1 != Fixed.end() && it2 == Fixed.end()){
      //double d = computeDistanceLinePoint (v0,v1,v2);
      double d = computeDistance (v0,0.0,v1,0.0,v2);
      update(Close,v2,d);
    }
    else if (it0 != Fixed.end() && it2 != Fixed.end() && it1 == Fixed.end()){
      //double d = computeDistanceLinePoint (v0,v2,v1);
      double d = computeDistance (v0,0.0,v2,0.0,v1);
      update(Close,v1,d);
    }
    else if (it2 != Fixed.end() && it1 != Fixed.end() && it0 == Fixed.end()){
      //double d = computeDistanceLinePoint (v2,v1,v0);
      double d = computeDistance (v2,0.0,v1,0.0,v0);
      update(Close,v0,d);
    }
  }

  //  printf("starting with %d vertices on the closed set\n",Close.size());
  double CLOSEST = 0.0;
  while(1){
    if (Close.empty())break;
    std::map<MVertex*,double>::iterator it = closest (Close);
    CLOSEST = it->second;
    //    printf ("CLOSEST = %lf\n",it->second);
    Fixed[it->first]=it->second;
    Close.erase(it);
    std::vector<MElement*> &ts = v2t[it->first];
    //    printf("%d elements around\n",ts.size());

    for (unsigned int i=0;i<ts.size();i++){
      MEdge ed = getEdge (ts[i],it->first);
      std::map<MVertex*,double>::iterator it0 = Fixed.find(ed.getVertex(0));
      std::map<MVertex*,double>::iterator it1 = Fixed.find(ed.getVertex(1));
      //      printf("coucou %p %p\n",ed.getVertex(0),ed.getVertex(1));
      if (it0 != Fixed.end() && it1 == Fixed.end()){
	double d = computeDistance (it->first,it->second,it0->first,it0->second,ed.getVertex(1));
	//	printf("neigh %d fixed 0 --> d = %g\n",i,d);
	update(Close, ed.getVertex(1), d);
      }
      else if (it1 != Fixed.end() && it0 == Fixed.end()){
	double d = computeDistance (it->first,it->second,it1->first,it1->second,ed.getVertex(0));
	//	printf("neigh %d fixed 1 --> d = %g\n",i,d);
	update(Close, ed.getVertex(0), d);
      }
    }
    //    printf("%d %d\n",Fixed.size(),v2t.size());
    if (Fixed.size() == v2t.size())break;
  }


  char name[256];
  sprintf(name,"geodesicDistance%d.pos",iter);
  FILE *f = fopen(name,"w");
  fprintf(f,"View \"%d\"{\n",iter);
  for (unsigned int i=0;i<tri.size();i++){
    double d0 = Fixed[tri[i]->getVertex(0)];
    double d1 = Fixed[tri[i]->getVertex(1)];
    double d2 = Fixed[tri[i]->getVertex(2)];
    fprintf(f,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
	    tri[i]->getVertex(0)->x(),tri[i]->getVertex(0)->y(),tri[i]->getVertex(0)->z(),
	    tri[i]->getVertex(1)->x(),tri[i]->getVertex(1)->y(),tri[i]->getVertex(1)->z(),
	    tri[i]->getVertex(2)->x(),tri[i]->getVertex(2)->y(),tri[i]->getVertex(2)->z(),d0,d1,d2);

  }
  fprintf(f,"};\n");
  fclose(f);


  return CLOSEST;
}

void discreteDiskFace::printAtlasMesh()
{
#if defined(HAVE_SOLVER) && defined(HAVE_ANN)
  std::map<MVertex*,int> mv2int;
  char buffer[256];
  sprintf(buffer,"atlas_mesh%d.msh",initialTriangulation->idNum);
  FILE* pmesh = Fopen(buffer,"w");

  std::set<MVertex*> meshvertices;

  for(unsigned int i=0; i<initialTriangulation->tri.size(); ++i){
      MElement* tri = initialTriangulation->tri[i];
      for(unsigned int j=0; j<3; j++)
	if (meshvertices.find(tri->getVertex(j))==meshvertices.end()) meshvertices.insert(tri->getVertex(j));
  }

  fprintf(pmesh,"$MeshFormat\n2.2 0 8\n$EndMeshFormat\n$Nodes\n%u\n",(unsigned int)meshvertices.size());
  int count = 1;
  for(std::set<MVertex*>::iterator it = meshvertices.begin(); it!=meshvertices.end(); ++it){
    fprintf(pmesh,"%d %f %f %f\n",count,(*it)->x(),(*it)->y(),(*it)->z());
    mv2int[*it] = count;
    count++;
  }
  fprintf(pmesh,"$EndNodes\n$Elements\n%u\n",(unsigned int)initialTriangulation->tri.size()-initialTriangulation->fillingHoles.size());
  unsigned int mycount = 0;//#####
  for(unsigned int i=0; i<initialTriangulation->tri.size(); i++){
        std::set<int>::iterator it = initialTriangulation->fillingHoles.find(i);
	//if (it == initialTriangulation->fillingHoles.end()){

	  MElement* tri = initialTriangulation->tri[i];
	  fprintf(pmesh,"%d 2 2 0 %d",mycount+1,initialTriangulation->idNum);//#####
	  for(int j=0; j<3; j++){
	    MVertex* mv = tri->getVertex(j);
	    fprintf(pmesh," %d",mv2int[mv]);
	  }
	  fprintf(pmesh,"\n");
	  mycount++;//###
	  //}
  }
  fprintf(pmesh,"$EndElements\n");
  fclose(pmesh);
#endif
}

void discreteDiskFace::printParamMesh()
{
  std::map<MVertex*,int> mv2int;
  char buffer[256];
  sprintf(buffer,"param_mesh%d.msh",tag());
  FILE* pmesh = fopen(buffer,"w");
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
    for(int j=0; j<_n; j++){
      MVertex* mv = tri->getVertex(j);
      fprintf(pmesh," %d",mv2int[mv]);
    }
    fprintf(pmesh,"\n");
  }
  fprintf(pmesh,"$EndElements\n");
  fclose(pmesh);
}

#endif
