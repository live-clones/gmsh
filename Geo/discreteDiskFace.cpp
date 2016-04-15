
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
#include "convexCombinationTerm.h"  // #
#include "BasisFactory.h"

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
    Msg::Error("(discreteDiskFace) static inline functionShapes, only first and second order available; order %d requested.",p);
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
    Msg::Error("(discreteDiskFace) static inline derivativeShapes, only first and second order available; order %d requested.",p);
    break;
  }

}

static inline bool uv2xi(discreteDiskFaceTriangle* my_ddft, double U[2], double Xi[2]){

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
    else{
      return true;
    }
  }// end order 2
  return true;
}


// The three things that are mandatory to manipulate octrees (octree in (u;v)).
static void discreteDiskFaceBB(void *a, double*mmin, double*mmax)
{ // called once  by buildOct()
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
{ // called once  by buildOct()
  discreteDiskFaceTriangle *t = (discreteDiskFaceTriangle *)a;
  c[0] = (t->p[0].x() + t->p[1].x() + t->p[2].x()) / 3.0;
  c[1] = (t->p[0].y() + t->p[1].y() + t->p[2].y()) / 3.0;
  c[2] = 0.0;
}

static int discreteDiskFaceInEle(void *a, double*c)// # mark
{ // called once  by buildOct()

  discreteDiskFaceTriangle *t = (discreteDiskFaceTriangle *)a;
  double Xi[2];
  double U[2] = {c[0],c[1]};
  bool ok = uv2xi(t,U,Xi);
  double eps = 1e-8;

  if(ok && Xi[0] > -eps && Xi[1] > -eps && 1. - Xi[0] - Xi[1] > -eps)
    return 1;

  return 0;
}

static bool orderVertices(const double &tot_length, const std::vector<MVertex*> &l, std::vector<double> &coord)
{ // called once by constructor ; organize the vertices for the linear system expressing the mapping
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
discreteDiskFace::discreteDiskFace(GFace *gf, std::vector<MTriangle*> &mesh, int p) :
  GFace(gf->model(),123), _parent (gf),_ddft(NULL), oct(NULL)
{
  _order = p;
  _N = (p+1)*(p+2)/2;

  int tagElementOrder;
  switch (_order){
  case 1:
    tagElementOrder = MSH_TRI_3;
    break;
  case 2:
    tagElementOrder = MSH_TRI_6;
    break;
  default:
    tagElementOrder = -1;
    Msg::Error("discreteDiskFace:: only p=1 or p=2 allowed");
  }
  //mynodalbasis = BasisFactory::getNodalBasis(tagElementOrder);

  std::map<MVertex*,MVertex*> v2v;// mesh vertex |-> face vertex
  std::map<MEdge,MVertex*,Less_Edge> ed2nodes; // edge to interior node(s)
  for (unsigned int i=0;i<mesh.size();i++){ // triangle by triangle

    std::vector<MVertex*> vs; // MTriangle vertices
    for (unsigned int j=0; j<3; j++){ // loop over vertices AND edges of the current triangle

      MVertex *v = mesh[i]->getVertex(j);// firstly, edge vertices
      if (v->onWhat() == gf) {
	std::map<MVertex*,MVertex*> :: iterator it = v2v.find(v);
	if (it == v2v.end()){
	  MFaceVertex *vv = new MFaceVertex ( v->x(),  v->y(),  v->z(), this, 0, 0);
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
	else Msg::Fatal("fatality");
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
	else{
	  vs.push_back(it->second);
	}
      }
    }// end order == 2
    if (_order==1)
      discrete_triangles.push_back(new MTriangle (vs));
    else if (_order==2)
      discrete_triangles.push_back(new MTriangle6 (vs));
  }// end loop over triangles

  buildAllNodes();
  getBoundingEdges();
  orderVertices(_totLength, _U0, _coords);
  
  parametrize(false);
  buildOct();

  if (!checkOrientationUV()){
    parametrize(true);
    buildOct();
  }
  
  putOnView();
}

discreteDiskFace::~discreteDiskFace() 
{
  triangles.clear();
  if (_ddft)delete[] _ddft;
  if (oct)Octree_Delete(oct);
}



void discreteDiskFace::getBoundingEdges()
{

  // first of all, all the triangles have to be oriented in the same way
  std::map<MEdge,std::vector<MElement*>,Less_Edge> ed2tri; // edge to 1 or 2 triangle(s)

  for(unsigned int i = 0; i < discrete_triangles.size(); ++i){
    MElement *e = discrete_triangles[i];
    for(int j = 0; j <  e->getNumEdges() ; j++){
      MEdge ed = e->getEdge(j);
      ed2tri[ed].push_back(e);
    }
  }

  // element to its neighbors
  std::map<MElement*,std::vector<MElement*> > neighbors;
  for (unsigned int i=0; i<discrete_triangles.size(); ++i){
    MElement* e = discrete_triangles[i];
    for(int j=0; j<e->getNumEdges(); j++){ // #improveme: efficiency could be improved by setting neighbors mutually
      std::vector<MElement*> my_mt = ed2tri[e->getEdge(j)];
      if (my_mt.size() > 1){// my_mt.size() = {1;2}
	MElement* neighTri  = my_mt[0] == e ? my_mt[1] : my_mt[0];
	neighbors[e].push_back(neighTri);
      }
    }
  }

  // queue: first in, first out
  std::queue<MElement*> checkList; // element for reference orientation
  std::queue< std::vector<MElement*> > checkLists; // corresponding neighbor element to be checked for its orientation
  std::queue<MElement*> my_todo; // todo list
  std::map<MElement*,bool> check_todo; // help to complete todo list

  my_todo.push(discrete_triangles[0]);
  check_todo[discrete_triangles[0]]=true;
  while(!my_todo.empty()){

    MElement* myMT = my_todo.front();
    my_todo.pop();

    std::vector<MElement*> myV = neighbors[myMT];
    std::vector<MElement*> myInsertion;

    checkList.push(myMT);

    for(unsigned int i=0; i<myV.size(); ++i){
      if (check_todo.find(myV[i]) == check_todo.end()){
	myInsertion.push_back(myV[i]);
	check_todo[myV[i]] = true;
	my_todo.push(myV[i]);
      }
    }
    checkLists.push(myInsertion);
  }// end while


  while(!checkList.empty() && !checkLists.empty()){
    MElement* current = checkList.front();
    checkList.pop();
    std::vector<MElement*> neigs = checkLists.front();
    checkLists.pop();
    for (unsigned int i=0; i<neigs.size(); i++){
      bool myCond = false;
      for (unsigned int k=0; k<3; k++){
	for (unsigned int j=0; j<3; j++){
	  if (current->getVertex(k) == neigs[i]->getVertex(j)){
	    myCond = true;
	    if (!(current->getVertex(k!=2 ?k+1 : 0 ) == neigs[i]->getVertex(j!=0 ? j-1 : 2) ||
		  current->getVertex(k!=0 ?k-1 : 2 ) == neigs[i]->getVertex(j!=2 ? j+1 : 0))){
	      neigs[i]->reverse();
	      std::cout << "discreteDiskFace: triangle " << neigs[i]->getNum() << " has been reoriented." << std::endl;
	    }
	    break;
	  }
	}
	if (myCond)
	  break;
      }
    } // end for unsigned int i
  } // end while


  // now, it is possible to identify the border(s) of the triangulation
  // allEdges contains all edges of the boundary
  std::set<MEdge,Less_Edge> allEdges;

  for(unsigned int i = 0; i < discrete_triangles.size(); ++i){
    MElement *e = discrete_triangles[i];
    for(int j = 0; j <  e->getNumEdges() ; j++){
      MEdge ed = e->getEdge(j);
      std::set<MEdge,Less_Edge>::iterator it = allEdges.find(ed);
      if (it == allEdges.end()) allEdges.insert(ed);
      else allEdges.erase(it);
    }
  }

  std::map<MVertex*,std::vector<MVertex*> > firstNode2Edge;
  for (std::set<MEdge>::iterator ie = allEdges.begin(); ie != allEdges.end() ; ++ie) {
    MEdge ed = *ie;

    std::vector<MElement *> vectri = ed2tri[ed];
    MElement* tri = vectri[0]; // boundary edge: only one triangle :-)

    std::vector<MVertex*> vecver;
    tri->getEdgeVertices(edgeLocalNum(tri,ed),vecver);
    MVertex *first = vecver[0];
    MVertex *last = vecver[1];
    vecver.erase(vecver.begin());
    vecver.erase(vecver.begin());

    std::map<MVertex*,std::vector<MVertex*> >::iterator im = firstNode2Edge.find(first);
    if (im != firstNode2Edge.end()) Msg::Fatal("Incorrect topology in discreteDiskFace %d", tag());

    firstNode2Edge[first] = vecver;
    firstNode2Edge[first].push_back(last);
  }

  while (!firstNode2Edge.empty()) { // quid 'firstNode2Edge' is not empty but 'in' within the map ?
    std::vector<MVertex*> loop;
    double length = 0.;

    std::map<MVertex*,std::vector<MVertex*> >::iterator in = firstNode2Edge.begin();
    while(in != firstNode2Edge.end()) {
      MVertex *first = in->first;
      std::vector<MVertex*>  myV = in->second;

      loop.push_back(first);

      MVertex* previous = first;

      for(unsigned int i=0; i<=myV.size()-1; i++){

	MVertex* current = myV[i];

	loop.push_back(current);

	length += sqrt( (current->x()-previous->x()) * (current->x()-previous->x()) +
			(current->y()-previous->y()) * (current->y()-previous->y()) +
			(current->z()-previous->z()) * (current->z()-previous->z()) );

	_loops.insert(std::make_pair(length,loop)); // it shouldn't be possible to have twice the same length ? actually, it is possible, but quite seldom #fixme ----> multimap ?

	previous = current;

      }
      firstNode2Edge.erase(in);
      in = firstNode2Edge.find(previous);
    }// end while in
  } // end while firstNode2Edge

    // dirichlet BC
  _U0  = _loops.rbegin()->second;
  _totLength = _loops.rbegin()->first;
}


void discreteDiskFace::buildOct() const
{
  if (oct)Octree_Delete(oct);

  double origin[3] = {-1.01,-1.01,-1.0};
  double ssize[3] = {2.02,2.02,2.0};
  const int maxElePerBucket = 15;
  oct = Octree_Create(maxElePerBucket, origin, ssize, discreteDiskFaceBB,
                      discreteDiskFaceCentroid, discreteDiskFaceInEle);

  _ddft = new discreteDiskFaceTriangle[discrete_triangles.size()];
  for(unsigned int i = 0; i < discrete_triangles.size(); ++i){
    MTriangle *t = discrete_triangles[i];
    discreteDiskFaceTriangle* my_ddft = &_ddft[i];

    for(int io=0; io<_N; io++)
      my_ddft->p[io] = coordinates[t->getVertex(io)];

    my_ddft->gf = _parent;
    my_ddft->tri = t;

    Octree_Insert(my_ddft, oct);
  }
  Octree_Arrange(oct);
}


bool discreteDiskFace::parametrize(bool one2one) const
{ // mark, to improve

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
    myAssemblerU.fixVertex(v, 0, 1, cos(theta));
    myAssemblerV.fixVertex(v, 0, 1, sin(theta));
  }

  for(size_t i = 0; i < discrete_triangles.size(); ++i){
    MTriangle *t = discrete_triangles[i];
    for(int j=0; j<t->getNumVertices(); j++){
      myAssemblerU.numberVertex(t->getVertex(j), 0, 1);
      myAssemblerV.numberVertex(t->getVertex(j), 0, 1);
    }
  }


  Msg::Debug("Creating term %d dofs numbered %d fixed",
             myAssemblerU.sizeOfR() + myAssemblerV.sizeOfR(), myAssemblerU.sizeOfF() + myAssemblerV.sizeOfF());

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
  uv2xi(*mt,U,Xi);
  _xi = Xi[0];
  _eta = Xi[1];
}

bool discreteDiskFace::checkOrientationUV(){

  double initial, current; // initial and current orientation
  discreteDiskFaceTriangle *ct;
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
    if(initial*current < 0.) break;
  }
  if(i < discrete_triangles.size())
    return false;
  //    Msg::Error("discreteDiskFace: The parametrization is not one-to-one :-(");
  else
    return true;
}

// (u;v) |-> < (x;y;z); GFace; (u;v) >
GPoint discreteDiskFace::point(const double par1, const double par2) const
{
  double xi,eta;
  double par[2] = {par1,par2};
  discreteDiskFaceTriangle* dt;
  getTriangleUV(par1,par2,&dt,xi,eta);// return Xi,Eta
  double Xi[2] = {xi,eta};
  if (!dt) {
    GPoint gp = GPoint(1.e22,1.e22,1.e22,_parent,par);
    gp.setNoSuccess();
    return gp;
  }

  //polynomialBasis myPolynomial = polynomialBasis(dt->tri->getTypeForMSH());
  std::vector<double> eval(_N);
  //mynodalbasis->f(U,V,0.,eval);//#mark
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
  else if (v->onWhat()->dim()==0){
    Msg::Fatal("discreteDiskFace::parFromVertex vertex classified on a model vertex that is not part of the face");
  }
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
  discreteDiskFaceTriangle* ddft;
  getTriangleUV(param.x(),param.y(),&ddft,xi,eta);

  MTriangle* tri = NULL;
  if (ddft) tri = ddft->tri;
  else {
    Msg::Warning("discreteDiskFace::firstDer << triangle not found %g %g",param[0],param[1]);
    return Pair<SVector3, SVector3>(SVector3(1,0,0), SVector3(0,1,0));
  }

  double Xi[2] = {xi,eta};
  double df[6][2];
  //mynodalbasis->df(U,V,0.,df);
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

void discreteDiskFace::buildAllNodes()
{
  // allNodes contains all mesh-nodes
  for(unsigned int i = 0; i < discrete_triangles.size(); ++i){
    MElement *e = discrete_triangles[i];
    for(int j = 0; j <  e->getNumVertices() ; j++){
      MVertex* ev = e->getVertex(j);
      std::set<MVertex*>::iterator it = allNodes.find(ev); // several times the same nodes !
      if (it == allNodes.end()) allNodes.insert (ev);
    }
  }
}


void discreteDiskFace::putOnView()
{

  FILE* view_u = Fopen("param_u.pos","w");
  FILE* view_v = Fopen("param_v.pos","w");
  FILE* UVxyz = Fopen("UVxyz.pos","w");
  if(view_u && view_v){
    fprintf(view_u,"View \"paramU\"{\n");
    fprintf(view_v,"View \"paramV\"{\n");
    fprintf(UVxyz,"View \"Uxyz\"{\n");
    for (unsigned int i=0; i<discrete_triangles.size(); i++){
      discreteDiskFaceTriangle* my_ddft = &_ddft[i];
      if (_order == 1){
	fprintf(view_u,"ST(");
	fprintf(view_v,"ST(");
	fprintf(UVxyz,"ST(");
      }
      else{
	fprintf(view_u,"ST%d(",_order);
	fprintf(view_v,"ST%d(",_order);
	fprintf(UVxyz,"ST%d(",_order);
      }
      for (int j=0; j<_N-1; j++){
	fprintf(view_u,"%g,%g,%g,",my_ddft->tri->getVertex(j)->x(),my_ddft->tri->getVertex(j)->y(),my_ddft->tri->getVertex(j)->z());
	fprintf(view_v,"%g,%g,%g,",my_ddft->tri->getVertex(j)->x(),my_ddft->tri->getVertex(j)->y(),my_ddft->tri->getVertex(j)->z());
	fprintf(UVxyz,"%g,%g,%g,",my_ddft->p[j].x(),my_ddft->p[j].y(),0.);
      }
      fprintf(view_u,"%g,%g,%g){",my_ddft->tri->getVertex(_N-1)->x(),my_ddft->tri->getVertex(_N-1)->y(),my_ddft->tri->getVertex(_N-1)->z());
      fprintf(view_v,"%g,%g,%g){",my_ddft->tri->getVertex(_N-1)->x(),my_ddft->tri->getVertex(_N-1)->y(),my_ddft->tri->getVertex(_N-1)->z());
      fprintf(UVxyz,"%g,%g,%g){",my_ddft->p[_N-1].x(),my_ddft->p[_N-1].y(),0.);
      for (int j=0; j<_N-1; j++){
	fprintf(view_u,"%g,",my_ddft->p[j].x());
	fprintf(view_v,"%g,",my_ddft->p[j].y());
	fprintf(UVxyz,"%g,",sqrt(my_ddft->tri->getVertex(j)->x()*my_ddft->tri->getVertex(j)->x()+my_ddft->tri->getVertex(j)->z()*my_ddft->tri->getVertex(j)->z()+my_ddft->tri->getVertex(j)->y()*my_ddft->tri->getVertex(j)->y()));
      }
      fprintf(view_u,"%g};\n",my_ddft->p[_N-1].x());
      fprintf(view_v,"%g};\n",my_ddft->p[_N-1].y());
      fprintf(UVxyz,"%g};\n",sqrt(my_ddft->tri->getVertex(_N-1)->x()*my_ddft->tri->getVertex(_N-1)->x()+my_ddft->tri->getVertex(_N-1)->z()*my_ddft->tri->getVertex(_N-1)->z()+my_ddft->tri->getVertex(_N-1)->y()*my_ddft->tri->getVertex(_N-1)->y()));
    }
    fprintf(view_u,"};\n");
    fprintf(view_v,"};\n");
    fprintf(UVxyz,"};\n");
    fclose(view_u);
    fclose(view_v);
    fclose(UVxyz);
  }

  /*
#ifdef HAVE_POST
  std::map<int, std::vector<double> > u;
  std::map<int, std::vector<double> > v;
  for(std::set<MVertex*>::iterator iv = allNodes.begin(); iv!=allNodes.end(); ++iv){
    MVertex *p = *iv;
    u[p->getNum()].push_back(coordinates[p].x());
    v[p->getNum()].push_back(coordinates[p].y());
  }
  PView* view_u = new PView("u", "NodeData", GModel::current(), u);
  PView* view_v = new PView("v", "NodeData", GModel::current(), v);
  view_u->setChanged(true);
  view_v->setChanged(true);
  view_u->write("param_u.msh", 5);
  view_v->write("param_v.msh", 5);
  delete view_u;
  delete view_v;
#else
  Msg::Error("discreteDiskFace: cannot export without post module")
#endif
  */
}

// useful for mesh generators ----------------------------------------
// Intersection of a circle and a plane
GPoint discreteDiskFace::intersectionWithCircle(const SVector3 &n1, const SVector3 &n2,
						const SVector3 &p, const double &d,
						double uv[2]) const
{
  SVector3 n = crossprod(n1,n2);
  n.normalize();
  for (int i=-1;i<(int)discrete_triangles.size();i++){
    discreteDiskFaceTriangle *ct;
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
    SVector3 v0(ct->tri->getVertex(0)->x(),ct->tri->getVertex(0)->y(),ct->tri->getVertex(0)->z());
    SVector3 v1(ct->tri->getVertex(1)->x(),ct->tri->getVertex(1)->y(),ct->tri->getVertex(1)->z());
    SVector3 v2(ct->tri->getVertex(2)->x(),ct->tri->getVertex(2)->y(),ct->tri->getVertex(2)->z());
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


#endif
