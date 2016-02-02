// Gmsh - Copyright (C) 1997-2015 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include <stdlib.h>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "Octree.h"
#include "discreteDiskFace.h"
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
#include "../Numeric/BasisFactory.h" // for derivatives 

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
  GFace(GEntity::model(),0), _parent (gf)
{
  triangles = mesh;
  uv_kdtree = NULL;
  kdtree = NULL;
  // checkOrientation(); // mark, need to check after parametrization ? --> no ! (3D, cf. Seb)
  buildAllNodes();
  getBoundingEdges();
  orderVertices(_totLength, _U0, _coords);
  parametrize();
  buildOct();
  putOnView();
}

void discreteDiskFace::getBoundingEdges()
{
  // allEdges contains all edges of the boundary
  std::set<MEdge,Less_Edge> allEdges;

  for(unsigned int i = 0; i < getNumMeshElements(); ++i){
    MElement *e = getMeshElement(i);
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
{ // mark ?
  SBoundingBox3d bb;
  int count = 0;  
  
  for(unsigned int i = 0; i < triangles.size(); ++i){
    MTriangle *t = triangles[i];
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

  for(unsigned int i = 0; i < triangles.size(); ++i){
    MTriangle *t = triangles[i];
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

    
    /*
    SVector3 dXdxi (_ddft[count].v2 - _ddft[count].v1); // constant
    SVector3 dXdeta(_ddft[count].v3 - _ddft[count].v1); // constant
    firstElemDerivatives[(MElement*)t] = Pair<SVector3,SVector3>(dXdxi,dXdeta);
    */
    

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
    

    // build ANN kdtree
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
  allTri.insert(allTri.end(), triangles.begin(), triangles.end() );    
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
  

  //build ANN kdtree
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
 
  for(size_t i = 0; i < triangles.size(); ++i){
    MTriangle *t = triangles[i];

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
  /*
  convexCombinationTerm mappingU(0,1,&ONE);
  convexCombinationTerm mappingV(0,1,&ONE);
  */
  for(unsigned int i = 0; i < triangles.size(); ++i){
    SElement se(triangles[i]);
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

// ------

void discreteDiskFace::getTriangleUV(const double u,const double v,discreteDiskFaceTriangle **mt, double &_u, double &_v)const{ // does it change with higher order ?  no, I don't think 

  double uv[3] = {u,v,0.};
  *mt = (discreteDiskFaceTriangle*) Octree_Search(uv,oct);

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

  
  SPoint3 p = dt->v1*(1.-U-V) + dt->v2*U + dt->v3*V;

  return GPoint(p.x(),p.y(),p.z(),_parent,par);
}

// (x;y;z) |-> (u;v)
SPoint2 discreteDiskFace::parFromPoint(const MVertex* v)
{
  double xyz[3] = {v->x(),v->y(),v->z()};
  double uvw[3] = {0.,0.,0.};
  
  unsigned int i;
  for(i = 0; i<triangles.size(); ++i){ // loop on every mesh triangles

    MTriangle* t = _ddft[i].tri;
    
    t->xyz2uvw(xyz,uvw); // (x;y;z) |-> (xsi,eta) [ref triangle]

    if (t->isInside(uvw[0],uvw[1],uvw[2])){ // the mesh vertex belongs to this triangle

      discreteDiskFaceTriangle* theTri = &_ddft[i];
 
      SPoint3 p = theTri->p1*(1-uvw[0]-uvw[1]) + theTri->p2*uvw[0] + theTri->p3*uvw[1];
      
      double U = p.x();
      double V = p.y();

      break;
      return SPoint2(U,V);     

    }

  }

  if (i==triangles.size())
    Msg::Error("discreteDiskFace::parFromPoint << no triangle contains this vertex !");
  
  
  return SPoint2(0.,0.);
}

SVector3 discreteDiskFace::normal(const SPoint2 &param) const
{
    return SVector3();
}

double discreteDiskFace::curvatureMax(const SPoint2 &param) const
{

    return false;
}

double discreteDiskFace::curvatures(const SPoint2 &param, SVector3 *dirMax, SVector3 *dirMin,
                                double *curvMax, double *curvMin) const
{
    return false;  
}


Pair<SVector3, SVector3> discreteDiskFace::firstDer(const SPoint2 &param) const
{

  double U,V;
  discreteDiskFaceTriangle* ddft;
  getTriangleUV(param.x(),param.y(),&ddft,U,V);


  MTriangle* tri = NULL;
  if (ddft) tri = ddft->tri;
  else Msg::Error("discreteDiskFace::firstDer << triangle not found");

  /*
  const nodalBasis* base = BasisFactory::getNodalBasis(MSH_TRI_3);
  double grads[2][3];
  double mat[2][2];
  double inv[2][2];
  base->df(U,V,0.,grads);

  for (int i=0; i<2; i++)
    for (int j=0; j<2; j++)
      mat[i][j] = grads[i][j];

  inv2x2(mat,inv);

  SVector3 dXdxi = firstElemDerivatives[tri].first();
  SVector3 dXdeta = firstElemDerivatives[tri].second();

  SVector3 dXdu = dXdxi*inv[0][0] + dXdeta*inv[1][0];
  SVector3 dXdv = dXdxi*inv[0][1] + dXdeta*inv[1][1];
  */

  
  SVector3 dXdu1 = firstDerivatives[tri->getVertex(0)].first();
  SVector3 dXdu2 = firstDerivatives[tri->getVertex(1)].first();
  SVector3 dXdu3 = firstDerivatives[tri->getVertex(2)].first();
  SVector3 dXdv1 = firstDerivatives[tri->getVertex(0)].second();
  SVector3 dXdv2 = firstDerivatives[tri->getVertex(1)].second();
  SVector3 dXdv3 = firstDerivatives[tri->getVertex(2)].second();
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
  for(unsigned int i = 0; i < getNumMeshElements(); ++i){
    MElement *e = getMeshElement(i);
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
 
