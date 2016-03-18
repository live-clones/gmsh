// Gmsh - Copyright (C) 1997-2015 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

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

// The three things that are mandatory to manipulate octrees (octree in (u;v)).
static void discreteDiskFaceBB(void *a, double*mmin, double*mmax)
{ // called once  by buildOct()
  discreteDiskFaceTriangle *t = (discreteDiskFaceTriangle *)a;
  mmin[0] = std::min(std::min(t->p1.x(), t->p2.x()), t->p3.x());
  mmin[1] = std::min(std::min(t->p1.y(), t->p2.y()), t->p3.y());
  mmax[0] = std::max(std::max(t->p1.x(), t->p2.x()), t->p3.x());
  mmax[1] = std::max(std::max(t->p1.y(), t->p2.y()), t->p3.y());
  mmin[2] = -1;
  mmax[2] = 1;

  const double dx = mmax[0] - mmin[0];
  const double dy = mmax[1] - mmin[1];
  const double eps = 0.0;//1.e-12;
  mmin[0] -= eps*dx;
  mmin[1] -= eps*dy;
  mmax[0] += eps*dx;
  mmax[1] += eps*dy;
}

static void discreteDiskFaceCentroid(void *a, double*c)
{ // called once  by buildOct()
  discreteDiskFaceTriangle *t = (discreteDiskFaceTriangle *)a;
  c[0] = (t->p1.x() + t->p2.x() + t->p3.x()) / 3.0;
  c[1] = (t->p1.y() + t->p2.y() + t->p3.y()) / 3.0;
  c[2] = 0.0;
}

static int discreteDiskFaceInEle(void *a, double*c)
{ // called once  by buildOct()
  discreteDiskFaceTriangle *t = (discreteDiskFaceTriangle *)a;
  double M[2][2], R[2], X[2];
  const double eps = 1.e-8;
  const SPoint3 p0 = t->p1;
  const SPoint3 p1 = t->p2;
  const SPoint3 p2 = t->p3;
  M[0][0] = p1.x() - p0.x();
  M[0][1] = p2.x() - p0.x();
  M[1][0] = p1.y() - p0.y();
  M[1][1] = p2.y() - p0.y();
  R[0] = (c[0] - p0.x());
  R[1] = (c[1] - p0.y());
  sys2x2(M, R, X);
  if(X[0] > -eps && X[1] > -eps && 1. - X[0] - X[1] > -eps)
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
discreteDiskFace::discreteDiskFace(GFace *gf, std::vector<MTriangle*> &mesh) :
  GFace(gf->model(),123), _parent (gf)
{
  if (mesh.empty())return;
  std::map<MVertex*,MVertex*> v2v;
  for (unsigned int i=0;i<mesh.size();i++){
    MVertex *vs[3] = {NULL, NULL, NULL};
    for (int j=0;j<3;j++){
      MVertex *v = mesh[i]->getVertex(j);
      if (v->onWhat() == gf) {
	std::map<MVertex*,MVertex*> :: iterator it = v2v.find(v);
	if (it == v2v.end()){
	  MFaceVertex *vv = new MFaceVertex ( v->x(),  v->y(),  v->z(), this, 0, 0);
	  v2v[v] = vv;
	  discrete_vertices.push_back(vv);
	  vs[j] = vv;
	}
	else vs[j] = it->second;
      }
      else if (v->onWhat()->dim() == 1){
	if (v->onWhat()->geomType() == DiscreteCurve){
	  discreteEdge *de = dynamic_cast<discreteEdge*> (v->onWhat());
	  vs[j] = de->getGeometricalVertex(v);
	}
	else Msg::Fatal("fatality");
      }
      else vs[j] = v;
    }
    discrete_triangles.push_back(new MTriangle (vs[0], vs[1], vs[2]));
  }

  //  triangles = mesh;
  uv_kdtree = NULL;
  kdtree = NULL;
  // checkOrientation(); // mark, need to check after parametrization ? --> no ! (3D, cf. Seb)
  buildAllNodes();
  getBoundingEdges();
  orderVertices(_totLength, _U0, _coords);
  parametrize();
  buildOct();
  //  putOnView();
}


void discreteDiskFace::getBoundingEdges()
{
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

  std::map<MVertex*,MVertex*> edges; // useless ?
  std::map<MVertex*,MVertex*> firstNode2Edge;
  for (std::set<MEdge>::iterator ie = allEdges.begin(); ie != allEdges.end() ; ++ie) {
    MEdge ed = *ie;
    MVertex *first = ed.getVertex(0);
    MVertex *last  = ed.getVertex(1);

    std::map<MVertex*,MVertex*>::iterator im = firstNode2Edge.find(first);
    if (im != firstNode2Edge.end()) Msg::Fatal("Incorrect topology in discreteDiskFace %d", tag());

    firstNode2Edge[first] = last;
  }

  while (!firstNode2Edge.empty()) { // quid not empty but in within the map ?
    std::vector<MVertex*> loop;
    double length = 0.;
    std::map<MVertex*,MVertex*>::iterator in = firstNode2Edge.begin();
    while(in != firstNode2Edge.end()) {
      MVertex *first = in->first;
      MVertex *last  = in->second;
      length += sqrt( (last->x()-first->x()) * (last->x()-first->x()) +
		      (last->y()-first->y()) * (last->y()-first->y()) +
		      (last->z()-first->z()) * (last->z()-first->z()) );
      loop.push_back(first);
      firstNode2Edge.erase(in);
      in = firstNode2Edge.find(last);
    }
    _loops.insert(std::make_pair(length,loop)); // it shouldn't be possible to have twice the same length ? mark
  }


  // dirichlet BC
  _U0  = _loops.rbegin()->second;
  _totLength = _loops.rbegin()->first;
}

void discreteDiskFace::buildOct() const
{
  SBoundingBox3d bb;
  int count = 0;

  for(unsigned int i = 0; i < discrete_triangles.size(); ++i){
    MTriangle *t = discrete_triangles[i];
    //create bounding box
    for(int j = 0; j < 3; j++){
      std::map<MVertex*,SPoint3>::const_iterator itj = coordinates.find(t->getVertex(j));
      _coordPoints.insert(std::make_pair(t->getVertex(j)->point(), itj->second));// <tr(x;y;z);tr(u;v)>
      bb += SPoint3(itj->second.x(),itj->second.y(),0.0);
    }
    count++;
  }

  //ANN octree
  std::set<MVertex*> allVS; // ? useless ?
  ANNpointArray nodes = annAllocPts(count, 3);

  // make bounding box
  SPoint3 bbmin = bb.min(), bbmax = bb.max();
  double origin[3] = {bbmin.x(), bbmin.y(), bbmin.z()};
  double ssize[3] = {bbmax.x() - bbmin.x(),
                     bbmax.y() - bbmin.y(),
                     bbmax.z() - bbmin.z()};

  _ddft = new discreteDiskFaceTriangle[count];
  const int maxElePerBucket = 15;
  oct = Octree_Create(maxElePerBucket, origin, ssize, discreteDiskFaceBB,
                      discreteDiskFaceCentroid, discreteDiskFaceInEle);

  count = 0;

  for(unsigned int i = 0; i < discrete_triangles.size(); ++i){
    MTriangle *t = discrete_triangles[i];
    std::map<MVertex*,SPoint3>::const_iterator it0 =
      coordinates.find(t->getVertex(0));
    std::map<MVertex*,SPoint3>::const_iterator it1 =
      coordinates.find(t->getVertex(1));
    std::map<MVertex*,SPoint3>::const_iterator it2 =
      coordinates.find(t->getVertex(2));
    _ddft[count].p1 = it0->second;
    _ddft[count].p2 = it1->second;
    _ddft[count].p3 = it2->second;
    if(geomType() != GEntity::DiscreteDiskSurface){// CAD
      if (t->getVertex(0)->onWhat()->dim() == 2){
	reparamMeshEdgeOnFace(t->getVertex(0), t->getVertex(1), _parent,
			      _ddft[count].gfp1, _ddft[count].gfp2);
	reparamMeshEdgeOnFace(t->getVertex(0), t->getVertex(2), _parent,
			      _ddft[count].gfp1, _ddft[count].gfp3);
      }
      else if (t->getVertex(1)->onWhat()->dim() == 2){
	reparamMeshEdgeOnFace(t->getVertex(1), t->getVertex(0), _parent,
			      _ddft[count].gfp2, _ddft[count].gfp1);
	reparamMeshEdgeOnFace(t->getVertex(1), t->getVertex(2), _parent,
			      _ddft[count].gfp2, _ddft[count].gfp3);
      }
      else if (t->getVertex(2)->onWhat()->dim() == 2){
	reparamMeshEdgeOnFace(t->getVertex(2), t->getVertex(0), _parent,
			      _ddft[count].gfp3, _ddft[count].gfp1);
	reparamMeshEdgeOnFace(t->getVertex(2), t->getVertex(1), _parent,
			      _ddft[count].gfp3, _ddft[count].gfp2);
      }
      else {
	reparamMeshVertexOnFace(t->getVertex(0), _parent, _ddft[count].gfp1);
	reparamMeshVertexOnFace(t->getVertex(1), _parent, _ddft[count].gfp2);
	reparamMeshVertexOnFace(t->getVertex(2), _parent, _ddft[count].gfp3);
      }
    }
    _ddft[count].v1 = SPoint3(t->getVertex(0)->x(), t->getVertex(0)->y(),
			      t->getVertex(0)->z());
    _ddft[count].v2 = SPoint3(t->getVertex(1)->x(), t->getVertex(1)->y(),
			      t->getVertex(1)->z());
    _ddft[count].v3 = SPoint3(t->getVertex(2)->x(), t->getVertex(2)->y(),
			      t->getVertex(2)->z());
    _ddft[count].gf = _parent;
    _ddft[count].tri = t;


    //compute first derivatives for every triangle , to disappear (erase)
    double mat[2][2] = {{_ddft[count].p2.x() - _ddft[count].p1.x(),
			 _ddft[count].p3.x() - _ddft[count].p1.x()},
			{_ddft[count].p2.y() - _ddft[count].p1.y(),
			 _ddft[count].p3.y() - _ddft[count].p1.y()}}; // modified higher

    double inv[2][2];
    inv2x2(mat, inv);
    SVector3 dXdxi (_ddft[count].v2 - _ddft[count].v1); // constant
    SVector3 dXdeta(_ddft[count].v3 - _ddft[count].v1); // constant
    SVector3 dXdu(dXdxi * inv[0][0] + dXdeta * inv[1][0]); // to be modified for higher order
    SVector3 dXdv(dXdxi * inv[0][1] + dXdeta * inv[1][1]); // to be modified for higher order
    firstElemDerivatives[(MElement*)t] = Pair<SVector3,SVector3>(dXdu,dXdv);

    nodes[count][0] = (it0->second.x() + it1->second.x() + it2->second.x())/3.0 ;
    nodes[count][1] = (it0->second.y() + it1->second.y() + it2->second.y())/3.0 ;
    nodes[count][2] = 0.0;

    Octree_Insert(&_ddft[count], oct);
    count++;
  }

  Octree_Arrange(oct);

  // USELESS, laplacian
  //smooth first derivatives at vertices
  if(adjv.size() == 0){
    std::vector<MTriangle*> allTri;
    allTri.insert(allTri.end(), discrete_triangles.begin(), discrete_triangles.end() );
    buildVertexToTriangle(allTri, adjv);
  }
  for(v2t_cont::iterator it = adjv.begin(); it!= adjv.end(); ++it){
    MVertex *v = it->first;
    std::vector<MElement*> vTri = it->second;
    SVector3 dXdu(0.0), dXdv(0.0);
    int nbTri = vTri.size();
    for (int j = 0; j < nbTri; j++){ // elements's contribution for a vertex
      dXdu += firstElemDerivatives[vTri[j]].first();
      dXdv += firstElemDerivatives[vTri[j]].second();
    }
    dXdu *= 1./nbTri;
    dXdv *= 1./nbTri;
    firstDerivatives[v] = Pair<SVector3, SVector3>(dXdu, dXdv);
  }

  kdtree = new ANNkd_tree(nodes, count, 3);

}


bool discreteDiskFace::parametrize() const
{ // mark, to improve

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

    myAssemblerU.numberVertex(t->getVertex(0), 0, 1);
    myAssemblerU.numberVertex(t->getVertex(1), 0, 1);
    myAssemblerU.numberVertex(t->getVertex(2), 0, 1);

    myAssemblerV.numberVertex(t->getVertex(0), 0, 1);
    myAssemblerV.numberVertex(t->getVertex(1), 0, 1);
    myAssemblerV.numberVertex(t->getVertex(2), 0, 1);
  }


  Msg::Debug("Creating term %d dofs numbered %d fixed",
             myAssemblerU.sizeOfR() + myAssemblerV.sizeOfR(), myAssemblerU.sizeOfF() + myAssemblerV.sizeOfF());

  double t1 = Cpu();

  simpleFunction<double> ONE(1.0);

  convexLaplaceTerm mappingU(0, 1, &ONE);
  convexLaplaceTerm mappingV(0, 1, &ONE);

  for(unsigned int i = 0; i < discrete_triangles.size(); ++i){
    SElement se(discrete_triangles[i]);
    mappingU.addToMatrix(myAssemblerU, &se);
    mappingV.addToMatrix(myAssemblerV, &se);
  }


  //  lsys_v->printMatlab("testv.m");


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
				     double &_u, double &_v)const{
  double uv[3] = {u,v,0.};
  *mt = (discreteDiskFaceTriangle*) Octree_Search(uv,oct);
  if (!(*mt))return;

  double M[2][2],X[2],R[2];
  const SPoint3 p0 = (*mt)->p1;
  const SPoint3 p1 = (*mt)->p2;
  const SPoint3 p2 = (*mt)->p3;
  M[0][0] = p1.x() - p0.x();
  M[0][1] = p2.x() - p0.x();
  M[1][0] = p1.y() - p0.y();
  M[1][1] = p2.y() - p0.y();
  R[0] = (u - p0.x());
  R[1] = (v - p0.y());
  sys2x2(M, R, X);
  _u = X[0];
  _v = X[1];

}

// (u;v) |-> < (x;y;z); GFace; (u;v) >
GPoint discreteDiskFace::point(const double par1, const double par2) const
{

  double U,V;
  double par[2] = {par1,par2};
  discreteDiskFaceTriangle* dt;
  getTriangleUV(par1,par2,&dt,U,V);
  if (!dt) {
    GPoint gp = GPoint(1.e22,1.e22,1.e22,_parent,par);
    gp.setNoSuccess();
    return gp;
  }

  SPoint3 p = dt->v1*(1.-U-V) + dt->v2*U + dt->v3*V;

  return GPoint(p.x(),p.y(),p.z(),_parent,par);
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
	de->interpolateInGeometry (v,&v1,&v2,xi);
	std::map<MVertex*,SPoint3>::iterator it1 = coordinates.find(v1);
	std::map<MVertex*,SPoint3>::iterator it2 = coordinates.find(v2);
	if(it1 == coordinates.end()) Msg::Fatal("FIXME TO DO %d %s",__LINE__,__FILE__);
	if(it2 == coordinates.end()) Msg::Fatal("FIXME TO DO %d %s",__LINE__,__FILE__);
	return SPoint2(it1->second.x(),it1->second.y()) * (1.-xi) + 
	  SPoint2(it2->second.x(),it2->second.y()) * xi; 	
      }
    }
    Msg::Fatal("FIXME TO DO %d %s",__LINE__,__FILE__);
  }
  else if (v->onWhat()->dim()==0){
    Msg::Fatal("discreteDiskFace::parFromVertex vertex classified on a model vertex that is not part of the face");
  }

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

  double U,V;
  discreteDiskFaceTriangle* ddft;
  getTriangleUV(param.x(),param.y(),&ddft,U,V);

  MTriangle* tri = NULL;
  if (ddft) tri = ddft->tri;
  else {
    Msg::Warning("discreteDiskFace::firstDer << triangle not found %g %g",param[0],param[1]);
    return Pair<SVector3, SVector3>(SVector3(1,0,0), SVector3(0,1,0));
  }

  std::map<MVertex*, Pair<SVector3,SVector3> >::iterator it0 =
    firstDerivatives.find(tri->getVertex(0));
  if (it0 == firstDerivatives.end()) Msg::Fatal ("Vertex %d (0) has no firstDerivatives",
						 tri->getVertex(0)->getNum());
  std::map<MVertex*, Pair<SVector3,SVector3> >::iterator it1 =
    firstDerivatives.find(tri->getVertex(1));
  if (it1 == firstDerivatives.end()) Msg::Fatal ("Vertex %d (1) has no firstDerivatives",
						 tri->getVertex(1)->getNum());
  std::map<MVertex*, Pair<SVector3,SVector3> >::iterator it2 =
    firstDerivatives.find(tri->getVertex(2));
  if (it2 == firstDerivatives.end()) Msg::Fatal ("Vertex %d (2) has no firstDerivatives",
						 tri->getVertex(2)->getNum());


  SVector3 dXdu1 = it0->second.first();
  SVector3 dXdu2 = it1->second.first();
  SVector3 dXdu3 = it2->second.first();

  SVector3 dXdv1 = it0->second.second();
  SVector3 dXdv2 = it1->second.second();
  SVector3 dXdv3 = it2->second.second();

  SVector3 dXdu = dXdu1*(1.-U-V) + dXdu2*U + dXdu3*V;
  SVector3 dXdv = dXdv1*(1.-U-V) + dXdv2*U + dXdv3*V;


  return Pair<SVector3, SVector3>(dXdu,dXdv);

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
#ifdef HAVE_POST
  std::map<int, std::vector<double> > u;
  std::map<int, std::vector<double> > v;

  for(std::set<MVertex*>::iterator iv = allNodes.begin(); iv!=allNodes.end(); ++iv){
    MVertex *p = *iv;
    u[p->getNum()].push_back(coordinates[p].x());
    v[p->getNum()].push_back(coordinates[p].y());
  }
  PView* view_u = new PView("u", "NodeData", GModel::current(), u);
  PView* view_v = new PView("u", "NodeData", GModel::current(), v);
  view_u->setChanged(true);
  view_v->setChanged(true);
  view_u->write("param_u.msh", 5);
  view_v->write("param_v.msh", 5);
  delete view_u;
  delete view_v;
#else
  Msg::Error("discreteDiskFace: cannot export without post module")
#endif
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

    SVector3 t1  = ct->v2 - ct->v1;
    SVector3 t2  = ct->v3 - ct->v1;

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
      t = dot(ct->v1-p,w)/dot(n1,w);
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
      b[0] = dot(s-ct->v1,t1) ;
      b[1] = dot(s-ct->v1,t2) ;
      sys2x2(mat,b,uv);
      // check now if the point is inside the triangle
      if (uv[0] >= -1.e-6 && uv[1] >= -1.e-6 &&
	  1.-uv[0]-uv[1] >= -1.e-6 ) {
	SVector3 pp =
	  ct->p1 * ( 1.-uv[0]-uv[1] ) +
	  ct->p2 *uv[0] +
	  ct->p3 *uv[1] ;
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
