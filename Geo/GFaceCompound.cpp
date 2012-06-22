// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Emilie Marchandise
//

#include "GmshConfig.h"
#include "GmshDefines.h"
#include "GFaceCompound.h"
#include "GEdgeCompound.h"
#include "intersectCurveSurface.h"

#if defined(HAVE_SOLVER)

#include "Options.h"
#include "MLine.h"
#include "MTriangle.h"
#include "Numeric.h"
#include "OS.h"
#include "Octree.h"
#include "SBoundingBox3d.h"
#include "SPoint3.h"
#include "polynomialBasis.h"
#include "robustPredicates.h"
#include "MElementCut.h"
#include "dofManager.h"
#include "laplaceTerm.h"
#include "crossConfTerm.h"
#include "convexCombinationTerm.h"
#include "diagBCTerm.h"
#include "linearSystemGMM.h"
#include "linearSystemCSR.h"
#include "linearSystemFull.h"
#include "linearSystemPETSc.h"
#include "CreateFile.h"
#include "Context.h"
#include "discreteFace.h"
#include "eigenSolver.h"
#include "multiscaleLaplace.h"
#include "GRbf.h"
#include "Curvature.h"
#include "MPoint.h"
#include "Numeric.h"
#include "meshGFace.h"
#if defined(HAVE_ANN)
#include <ANN/ANN.h>
#endif

static void fixEdgeToValue(GEdge *ed, double value, dofManager<double> &myAssembler)
{
  myAssembler.fixVertex(ed->getBeginVertex()->mesh_vertices[0], 0, 1, value);
  myAssembler.fixVertex(ed->getEndVertex()->mesh_vertices[0], 0, 1, value);
  for(unsigned int i = 0; i < ed->mesh_vertices.size(); i++){
    myAssembler.fixVertex(ed->mesh_vertices[i], 0, 1, value);
  }
}

/*
static void printBound(std::vector<MVertex*> &l, int tag)
{
  char name[256];
  sprintf(name, "myBOUND%d.pos", tag);
  FILE * xyz = fopen(name,"w");
  fprintf(xyz,"View \"\"{\n");
  for(unsigned int i = 0; i < l.size(); i++){
    MVertex *v = l[i];
    fprintf(xyz,"SP(%g,%g,%g){%d};\n", v->x(), v->y(), v->z(), i);
  }
  fprintf(xyz,"};\n");
  fclose(xyz);
}
*/

static bool orderVertices(const std::list<GEdge*> &e, std::vector<MVertex*> &l,
                          std::vector<double> &coord)
{
  l.clear();
  coord.clear();

  std::list<GEdge*>::const_iterator it = e.begin();
  std::list<MLine*> temp;
  double tot_length = 0;
  for( ; it != e.end(); ++it ){
    for(unsigned int i = 0; i < (*it)->lines.size(); i++ ){
      temp.push_back((*it)->lines[i]);
      MVertex *v0 = (*it)->lines[i]->getVertex(0);
      MVertex *v1 = (*it)->lines[i]->getVertex(1);
      const double length = sqrt((v0->x() - v1->x()) * (v0->x() - v1->x()) +
                                 (v0->y() - v1->y()) * (v0->y() - v1->y()) +
                                 (v0->z() - v1->z()) * (v0->z() - v1->z()));
      tot_length += length;
    }
  }

  MVertex *first_v = (*temp.begin())->getVertex(0);
  MVertex *current_v = (*temp.begin())->getVertex(1);

  l.push_back(first_v);
  coord.push_back(0.0);
  temp.erase(temp.begin());

  while(temp.size()){
    bool found = false;
    for(std::list<MLine*>::iterator itl = temp.begin(); itl != temp.end(); ++itl){
      MLine *ll = *itl;
      MVertex *v0 = ll->getVertex(0);
      MVertex *v1 = ll->getVertex(1);
      if(v0 == current_v){
        found = true;
        l.push_back(current_v);
        current_v = v1;
        temp.erase(itl);
        const double length = sqrt((v0->x() - v1->x()) * (v0->x() - v1->x()) +
                                   (v0->y() - v1->y()) * (v0->y() - v1->y()) +
                                   (v0->z() - v1->z()) * (v0->z() - v1->z()));
        coord.push_back(coord[coord.size()-1] + length / tot_length);
        break;
      }
      else if(v1 == current_v){
        found = true;
        l.push_back(current_v);
        current_v = v0;
        temp.erase(itl);
        const double length = sqrt((v0->x() - v1->x()) * (v0->x() - v1->x()) +
                                   (v0->y() - v1->y()) * (v0->y() - v1->y()) +
                                   (v0->z() - v1->z()) * (v0->z() - v1->z()));
        coord.push_back(coord[coord.size()-1] + length / tot_length);
        break;
      }
    }
    if(!found) return false;
  }

  return true;
}

static bool computeCGKernelPolygon(std::map<MVertex*,SPoint3> &coordinates,
                                   std::vector<MVertex*> &cavV,
                                   double &ucg, double &vcg)
{
  ucg = 0.0;
  vcg = 0.0;

  // place at CG KERNEL polygon

  int nbPts = cavV.size();
  fullMatrix<double> u(100,2);
  int i = 0;
  for(std::vector<MVertex*>::iterator it = cavV.begin(); it != cavV.end(); it++){
    SPoint3 vsp = coordinates[*it];
    u(i,0) = vsp[0];
    u(i,1) = vsp[1];
    i++;
  }
  double eps = -5.e-7;
  int N = nbPts;

  std::set<int> setP;
  for(int k = 0; k < nbPts; k++) setP.insert(k);

  if(nbPts > 3){
    for(int i = 0; i < nbPts - 2; i++){
      int next = i + 1;
      double x1, x2, y1, y2;
      x1 = u(i, 0); y1 = u(i, 1);
      x2 = u(next, 0); y2 = u(next, 1);
      for(int j = i + 2; j < nbPts; j++){
        int jnext = j + 1;
        if(j == nbPts - 1) jnext = 0;
        double x3, x4, y3, y4, x,y;
        double a, b, c, d;
        x3 = u(j, 0); y3 = u(j, 1);
        x4 = u(jnext, 0); y4 = u(jnext, 1);
        a = (y2 - y1) / (x2 - x1);
        c = (y4 - y3) / (x4 - x3);
        b = y1 - a * x1;
        d = y3 - c * x3;
        if(fabs(a - c) > 1.e-5 && x2 !=x1 && x4 != x3 && jnext != i){
          x = (d - b) / (a - c);
          y = a * x + b;
          bool exist= false;
          for(unsigned int k = 1; k < setP.size(); k++){
            if(x == u(k, 0) && y == u(k, 1)) exist = true;
          }
          if(!exist){
            u(N, 0) = x; u(N, 1) = y;
            setP.insert(N);
            N++;
          }
        }
      }
    }

    int nbAll = setP.size();
    for(int i = 0; i <nbPts; i++){
      int next = i + 1;
      if(next == nbPts) next = 0;
      double p1[2] = {u(next, 0) - u(i, 0), u(next, 1) - u(i, 1)};
      for(int k = 0; k < nbAll; k++){
        double p2[2] = {u(k, 0) - u(i, 0), u(k, 1) - u(i, 1)};
        double crossProd = p1[0] * p2[1] - p2[0] * p1[1];
        if(crossProd <  eps){
          setP.erase(k);
        }
      }
    }
  }

  int nbFinal = setP.size();
  if(nbFinal > 0){
    for(std::set<int>::iterator it =setP.begin(); it != setP.end(); it++){
      ucg += u(*it,0);
      vcg += u(*it,1);
    }
    ucg /= nbFinal;
    vcg /= nbFinal;
    return true;
  }
  else{
    return false;
  }
}

static void myPolygon(std::vector<MElement*> &vTri, std::vector<MVertex*> &vPoly)
{
  std::vector<MEdge> ePoly;
  for(unsigned int i = 0; i  < vTri.size() ; i++) {
    MTriangle *t = (MTriangle*) vTri[i];
    for(int iEdge = 0; iEdge < 3; iEdge++) {
      MEdge tmp_edge =  t->getEdge(iEdge);
      if(std::find(ePoly.begin(), ePoly.end(), tmp_edge) == ePoly.end())
        ePoly.push_back(tmp_edge);
      else
        ePoly.erase(std::find(ePoly.begin(), ePoly.end(),tmp_edge));
    }
  }

  std::vector<MEdge>::iterator ite= ePoly.begin() ;
  MVertex *vINIT = ite->getVertex(0);
  vPoly.push_back(vINIT);
  vPoly.push_back(ite->getVertex(1));
  ePoly.erase(ite);

  while(!ePoly.empty()){
    ite = ePoly.begin() ;
    while(ite != ePoly.end()){
      MVertex *vB = ite->getVertex(0);
      MVertex *vE = ite->getVertex(1);
      if(vB == vPoly.back()){
	if(vE != vINIT) vPoly.push_back(vE);
	ePoly.erase(ite);
      }
      else if(vE == vPoly.back()){
	if(vB != vINIT) vPoly.push_back(vB);
	ePoly.erase(ite);
      }
      else ite++;
    }
  }
}

static double normalUV(MTriangle *t, std::map<MVertex*, SPoint3> &vCoord)
{
  SPoint3 v0 = vCoord[t->getVertex(0)];
  SPoint3 v1 = vCoord[t->getVertex(1)];
  SPoint3 v2 = vCoord[t->getVertex(2)];
  double p0[2] = {v0[0], v0[1]};
  double p1[2] = {v1[0], v1[1]};
  double p2[2] = {v2[0], v2[1]};
  double normal =  robustPredicates::orient2d(p0, p1, p2);

  // SVector3 P0 (v0.x(),v0.y(), 0.0);
  // SVector3 P1 (v1.x(),v1.y(), 0.0);
  // SVector3 P2 (v2.x(),v2.y(), 0.0);
  // double normal2 = crossprod(P1-P0,P2-P1).z();
  // if (normal != 0.0) normal /= std::abs(normal);

  return normal;
}

static bool checkCavity(std::vector<MElement*> &vTri, std::map<MVertex*, SPoint3> &vCoord)
{
  bool badCavity = false;

  unsigned int nbV = vTri.size();
  double a_old = 0.0, a_new;
  for(unsigned int i = 0; i < nbV; ++i){
    a_new = normalUV((MTriangle*) vTri[i], vCoord);
    if(i == 0) a_old=a_new;
    if(a_new*a_old < 0.0) badCavity = true;
  }
  return badCavity;
}

static bool closedCavity(MVertex *v, std::vector<MElement*> &vTri)
{
  std::set<MVertex *> vs;
  for (unsigned int i = 0; i < vTri.size(); i++){
    MElement *t = vTri[i];
    for (int j = 0; j < t->getNumVertices(); j++){
      MVertex *vv = t->getVertex(j);
      if (vv != v){
        if (vs.find(vv) == vs.end())vs.insert(vv);
        else vs.erase(vv);
      }
    }
  }
  return vs.empty();
}

static MVertex* findVertexInTri(v2t_cont &adjv, MVertex *v0, MVertex *v1,
				std::map<MVertex*, SPoint3> &vCoord, double nTot,
				bool &inverted)
{
  MVertex *v2 = 0;
  v2t_cont :: iterator it0 = adjv.find(v0);
  std::vector<MElement*> vTri0 = it0->second;
  MElement *myTri = 0;
  for (unsigned int j = 0; j < vTri0.size(); j++){
    MVertex *vt0  = vTri0[j]->getVertex(0);
    MVertex *vt1  = vTri0[j]->getVertex(1);
    MVertex *vt2  = vTri0[j]->getVertex(2);
    bool found0 = (vt0==v0 || vt1 ==v0 || vt2 ==v0) ? true: false;
    bool found1 = (vt0==v1 || vt1 ==v1 || vt2 ==v1) ? true: false;
    if (found0 && found1) { myTri = vTri0[j]; break; }
  }
  if(!myTri) return 0;
  for (unsigned int j = 0; j < 3; j++){
    MVertex *vj = myTri->getVertex(j);
    if (vj!=v0 && vj!=v1) { v2 = vj; break;}
  }
  double normTri = normalUV((MTriangle*)myTri, vCoord);
  if (nTot*normTri < 0.0) inverted = true;
  else inverted = false;

  return v2;
}

static MTriangle* findInvertedTri(v2t_cont &adjv, MVertex*v0, MVertex*v1, MVertex*v2,
                                  std::map<MVertex*, SPoint3> &vCoord, double nTot)
{
  v2t_cont::iterator it = adjv.find(v1);
  std::vector<MElement*> vTri = it->second;
  MTriangle *myTri=NULL;
  for (unsigned int j = 0; j < vTri.size(); j++){
    double normTri = normalUV((MTriangle*)vTri[j], vCoord);
    if (nTot * normTri < 0.0) {
      MVertex *vt0  = vTri[j]->getVertex(0);
      MVertex *vt1  = vTri[j]->getVertex(1);
      MVertex *vt2  = vTri[j]->getVertex(2);
      bool found0 = (vt0==v0 || vt1 ==v0 || vt2 ==v0) ? true: false;
      bool found2 = (vt0==v2 || vt1 ==v2 || vt2 ==v2) ? true: false;
      if (!found0 && !found2) { myTri = (MTriangle*)vTri[j]; break; }
    }
  }

  return myTri;
}

void GFaceCompound::orientFillTris(std::list<MTriangle*> loopfillTris) const
{
  // check normal orientations of loopfillTris
  bool invertTris = false;
  std::map<MEdge, std::set<MTriangle*>, Less_Edge > edge2tris;
  for(std::list<MTriangle*>::iterator t = loopfillTris.begin();
      t != loopfillTris.end(); t++){
    for (int j = 0; j < 3; j++){
      MEdge me = (*t)->getEdge(j);
      std::map<MEdge, std::set<MTriangle*, std::less<MTriangle*> >,
	       Less_Edge >::iterator it = edge2tris.find(me);
      if (it == edge2tris.end()) {
	std::set<MTriangle*, std::less<MTriangle*> > mySet;
	mySet.insert(*t);
	edge2tris.insert(std::make_pair(me, mySet));
      }
      else{
	std::set<MTriangle*, std::less<MTriangle*> > mySet = it->second;
	mySet.insert(*t);
	it->second = mySet;
      }
    }
  }

  int iE, si, iE2, si2;
  std::list<GFace*>::const_iterator itf = _compound.begin();
  for( ; itf != _compound.end(); ++itf){
    for(unsigned int i = 0; i < (*itf)->triangles.size(); ++i){
      MTriangle *t = (*itf)->triangles[i];
      for (int j = 0; j < 3; j++){
	MEdge me = t->getEdge(j);
	std::map<MEdge, std::set<MTriangle*>, Less_Edge >::iterator it =
	  edge2tris.find(me);
	if(it != edge2tris.end()){
	  t->getEdgeInfo(me, iE,si);
	  MTriangle* t2 = *((it->second).begin());
	  t2->getEdgeInfo(me,iE2,si2);
	  if(si == si2) {
	    invertTris = true;
	    break;
	  }
	}
      }
    }
  }
  if (invertTris){
    for (std::list<MTriangle*>::iterator it = loopfillTris.begin();
           it != loopfillTris.end(); it++ )
	(*it)->revert();
  }

  fillTris.insert(fillTris.begin(),loopfillTris.begin(),loopfillTris.end());
}

void GFaceCompound::printFillTris() const
{
  if(!CTX::instance()->mesh.saveAll) return;

  if (fillTris.size() > 0){
    char name[256];
    std::list<GFace*>::const_iterator itf = _compound.begin();
    sprintf(name, "fillTris-%d.pos", tag());
    FILE * ftri = fopen(name,"w");
    fprintf(ftri,"View \"\"{\n");
    for (std::list<MTriangle*>::iterator it2 = fillTris.begin();
	 it2 !=fillTris.end(); it2++ ){
      MTriangle *t = (*it2);
      fprintf(ftri,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
	      t->getVertex(0)->x(), t->getVertex(0)->y(), t->getVertex(0)->z(),
	      t->getVertex(1)->x(), t->getVertex(1)->y(), t->getVertex(1)->z(),
	      t->getVertex(2)->x(), t->getVertex(2)->y(), t->getVertex(2)->z(),
	      1., 1., 1.);
    }
    fprintf(ftri,"};\n");
    fclose(ftri);
  }
}

void GFaceCompound::fillNeumannBCS_Plane() const
{
#if defined(HAVE_MESH)

  Msg::Debug("Meshing %d interior holes with planes ", _interior_loops.size()-1);

  fillTris.clear();
  fillNodes.clear();

  if (_interior_loops.size()==1 && _type != SQUARE) return;

  GModel::current()->setFactory("Gmsh");
  //GModel::current()->setFactory("OpenCASCADE");
  std::vector<std::vector<GFace *> > myFaceLoops;
  std::vector<GFace *> myFaces;
  for(std::list<std::list<GEdge*> >::const_iterator iloop = _interior_loops.begin();
      iloop != _interior_loops.end(); iloop++){
    std::list<MTriangle*> loopfillTris;
    std::list<GEdge*> loop = *iloop;
    if (loop != _U0 ){
      std::vector<std::vector<GEdge *> > myEdgeLoops;
      std::vector<GEdge*> myEdges;
      myEdgeLoops.clear();
      myEdges.clear();
      for (std::list<GEdge*>::iterator itl = loop.begin(); itl != loop.end(); itl++){
	myEdges.push_back(*itl);
      }
      myEdgeLoops.push_back(myEdges);
      GFace *newFace =  GModel::current()->addPlanarFace(myEdgeLoops);
      fillFaces.push_back(newFace);
      int meshingAlgo = CTX::instance()->mesh.algo2d;
      int recombine = CTX::instance()->mesh.recombineAll;
      opt_mesh_algo2d(0, GMSH_SET, 1.0); //mesh adapt
      opt_mesh_recombine_all(0, GMSH_SET, 0.0); //no recombination
      meshGFace mgf;
      mgf(newFace,false);
      opt_mesh_algo2d(0, GMSH_SET, meshingAlgo);
      opt_mesh_recombine_all(0, GMSH_SET, recombine);
      for(unsigned int i = 0; i < newFace->triangles.size(); ++i){
	loopfillTris.push_back(newFace->triangles[i]);
	fillNodes.insert(newFace->triangles[i]->getVertex(0));
	fillNodes.insert(newFace->triangles[i]->getVertex(1));
	fillNodes.insert(newFace->triangles[i]->getVertex(2));
      }
      orientFillTris(loopfillTris);
    }
  }

  printFillTris();
#endif
}

void GFaceCompound::fillNeumannBCS() const
{
  fillTris.clear();
  fillNodes.clear();

  // closed interior loops
  for(std::list<std::list<GEdge*> >::const_iterator iloop = _interior_loops.begin();
      iloop != _interior_loops.end(); iloop++){
    std::list<MTriangle*> loopfillTris;
    std::list<GEdge*> loop = *iloop;
    if (loop != _U0 ){
      std::vector<MVertex*> orderedLoop;
      std::vector<double> coordsLoop;
      orderVertices(*iloop, orderedLoop, coordsLoop);
      int nbLoop = orderedLoop.size();

      //--- center of Neumann interior loop
      int nb = 0;
      double x=0.;
      double y=0.;
      double z=0.;
      // EMI- TODO FIND KERNEL OF POLYGON AND PLACE AT CG KERNEL !
      // IF NO KERNEL -> DO NOT FILL TRIS
      for(int i = 0; i < nbLoop; ++i){
	MVertex *v0 = orderedLoop[i];
	MVertex *v1 = (i==nbLoop-1) ? orderedLoop[0]: orderedLoop[i+1];
	x += .5*(v0->x() + v1->x());
	y += .5*(v0->y() + v1->y());
	z += .5*(v0->z() + v1->z());
	nb++;
      }
      x/=nb; y/=nb;  z/=nb;
      MVertex *c = new MVertex(x, y, z);

      //--- create new triangles
      for(int i = 0; i < nbLoop; ++i){
	MVertex *v0 = orderedLoop[i];
	MVertex *v1 = (i==nbLoop-1) ? orderedLoop[0]: orderedLoop[i+1];

	double k = 1. / 3.; double kk = 2. / 3.;
	MVertex *v2 = new MVertex(kk * v0->x() + k * c->x(),
                                  kk * v0->y() + k * c->y(),
                                  kk * v0->z() + k * c->z());
	MVertex *v3 = new MVertex(kk * v1->x() + k * c->x(),
                                  kk * v1->y() + k * c->y(),
                                  kk * v1->z() + k * c->z());
	MVertex *v4 = new MVertex(k * v0->x() + kk * c->x(),
                                  k * v0->y() + kk * c->y(),
                                  k * v0->z() + kk * c->z());
	MVertex *v5 = new MVertex(k * v1->x() + kk * c->x(),
                                  k * v1->y() + kk * c->y(),
                                  k * v1->z() + kk * c->z());
	fillNodes.insert(c); fillNodes.insert(v2); fillNodes.insert(v3);
	fillNodes.insert(v4); fillNodes.insert(v5);
	loopfillTris.push_back(new MTriangle(v0, v2, v3));
	loopfillTris.push_back(new MTriangle(v2, v5, v3));
	loopfillTris.push_back(new MTriangle(v2, v4, v5));
	loopfillTris.push_back(new MTriangle(v4, c, v5));
	loopfillTris.push_back(new MTriangle(v0, v3, v1));
      }
    }
    orientFillTris(loopfillTris);
  }

  printFillTris();
}

bool GFaceCompound::trivial() const
{
  return false;
  if(_compound.size() == 1 &&
     (*(_compound.begin()))->getNativeType() == GEntity::OpenCascadeModel &&
     (*(_compound.begin()))->geomType() != GEntity::DiscreteSurface &&
     _mapping != CONFORMAL){
    if ((*(_compound.begin()))->periodic(0) ||
	(*(_compound.begin()))->periodic(1) ) return false;
    return true;
  }
  return false;
}

// For the conformal map the linear system cannot guarantee there is
// no overlapping of triangles
bool GFaceCompound::checkOverlap(std::vector<MVertex *> &vert) const
{
  vert.clear();
  bool has_overlap = false;
  double EPS = 1.e-2;
  for(std::list<std::list<GEdge*> >::const_iterator iloop = _interior_loops.begin();
      iloop != _interior_loops.end(); iloop++){
    std::list<GEdge*> loop = *iloop;
    std::vector<MVertex*> orderedLoop;
    if (loop != _U0 ){
      std::vector<double> coordsLoop;
      orderVertices(*iloop, orderedLoop, coordsLoop);
    }
    else orderedLoop = _ordered;
    int nbLoop = orderedLoop.size();

    for(int i = 0; i < nbLoop-1; ++i){
      SPoint3 p1 = coordinates[orderedLoop[i]];
      SPoint3 p2 = coordinates[orderedLoop[i+1]];
      int maxSize = (i==0) ? nbLoop-2: nbLoop-1;
      for(int k = i+2; k < maxSize; ++k){
	SPoint3 q1 = coordinates[orderedLoop[k]];
	SPoint3 q2 = coordinates[orderedLoop[k+1]];
	double x[2];
	int inters = intersection_segments (p1,p2,q1,q2,x);
	if (inters && x[1] > EPS && x[1] < 1.-EPS){
	  has_overlap = true;
	  MVertex *v1 = orderedLoop[i];
	  MVertex *v2 = orderedLoop[k];
	  std::set<MVertex *>::iterator it1 = ov.find(v1);
	  std::set<MVertex *>::iterator it2 = ov.find(v2);
	  vert.push_back(v1);
	  vert.push_back(v2);
	  return has_overlap;
	}
      }
    }

  }

  if (has_overlap ) {
    Msg::Debug("Overlap for compound face %d", this->tag());
  }

  return has_overlap;
}

// check if the discrete harmonic map is correct by checking that all
// the mapped triangles have the same normal orientation
bool GFaceCompound::checkOrientation(int iter, bool moveBoundaries) const
{
  std::list<GFace*>::const_iterator it = _compound.begin();
  double a_old = 0.0, a_new=0.0;
  bool oriented = true;
  int count = 0;
  double nTot = 0.0;
  for( ; it != _compound.end(); ++it){
    for(unsigned int i = 0; i < (*it)->triangles.size(); ++i){
      a_new = normalUV((*it)->triangles[i], coordinates);
      if(count == 0) a_old=a_new;
      nTot += a_new;
      if(a_new*a_old < 0.0){
        oriented = false;
        break;
      }
      count++;
    }
  }

  int iterMax = 15;
  if(!oriented && iter < iterMax){
    if (moveBoundaries){
      if (iter ==0) Msg::Info("--- Flipping : moving boundaries.");
      Msg::Debug("--- Moving Boundary - iter %d -",iter);
      convexBoundary(nTot/fabs(nTot));
      printStuff(iter);
      return checkOrientation(iter+1, moveBoundaries);
    }
    else if (!moveBoundaries){
      if (iter ==0) Msg::Info("--- Flipping : applying cavity checks.");
      Msg::Debug("--- Cavity Check - iter %d -",iter);
      bool success = one2OneMap();
      if (success) return checkOrientation(iter+1);
    }
  }
  else if (iter > 0 && iter < iterMax){
    Msg::Info("--- Flipping : no more flips (%d iter)", iter);
  }

  return oriented;
}

void GFaceCompound::convexBoundary(double nTot) const
{
#if defined(HAVE_MESH)
  if(adjv.size() == 0){
    std::vector<MTriangle*> allTri;
    std::list<GFace*>::const_iterator it = _compound.begin();
    for( ; it != _compound.end(); ++it){
      allTri.insert(allTri.end(), (*it)->triangles.begin(), (*it)->triangles.end() );
    }
    buildVertexToTriangle(allTri, adjv);
  }

  for(std::list<std::list<GEdge*> >::const_iterator it = _interior_loops.begin();
      it != _interior_loops.end(); it++){

    double s = 1.0;
    std::vector<MVertex*> oVert;
    std::vector<double> coords;
    if (*it == _U0){
      oVert = _ordered;
    }
    else {
      s = -1.0;
      orderVertices(*it, oVert,coords);
    }

    // find normal of ordered loop
    MVertex *v0 = oVert[0];
    MVertex *v1 = oVert[1];
    bool inverted;
    MVertex *v2 = findVertexInTri(adjv, v0,v1,coordinates, nTot, inverted);
    if (inverted) s *= -1.0 ;
    SPoint3 uv0 = coordinates[v0];
    SPoint3 uv1 = coordinates[v1];
    SPoint3 uv2 = coordinates[v2];
    SVector3 P0 (uv0.x(),uv0.y(), 0.0);
    SVector3 P1 (uv1.x(),uv1.y(), 0.0);
    SVector3 P2 (uv2.x(),uv2.y(), 0.0);
    double myN = s*crossprod(P1-P0,P2-P1).z();
    SVector3 N (0,0,myN/fabs(myN));

    // start the loop
    int nbInv = 0;
    int nbInvTri = 0;
    for(unsigned int i = 0; i < oVert.size(); i++){

      MVertex *v0 = oVert[i];
      MVertex *v1, *v2;
      if (i == oVert.size()-2){
	v1 = oVert[i+1];
	v2 = oVert[0];
      }
      else if (i == oVert.size()-1){
	v1= oVert[0];
	v2= oVert[1];
      }
      else{
	v1 = oVert[i+1];
	v2 = oVert[i+2];
      }

      SPoint3 uv0 = coordinates[v0];
      SPoint3 uv1 = coordinates[v1];
      SPoint3 uv2 = coordinates[v2];
      SVector3 P0 (uv0.x(),uv0.y(), uv0.z());
      SVector3 P1 (uv1.x(),uv1.y(), uv1.z());
      SVector3 P2 (uv2.x(),uv2.y(), uv2.z());

      SVector3 dir1 = P1-P0;
      SVector3 dir2 = P2-P1;
      SVector3 dir3 = crossprod(dir1,dir2);
      double rot = dot(N, (1./norm(dir3))*dir3);

      bool inverted;
      MVertex *v2t = findVertexInTri(adjv, v0,v1, coordinates, nTot, inverted);

      if (rot < 0.0 && inverted){
	SVector3 a = P1-P0;
	SVector3 b = P2-P0;
	double a_para = dot(a,b)/norm(b);
	SVector3 P3,P1b;
	P3= P0 + (a_para/norm(b))*b;
	P1b = P1 + 1.2*(P3-P1);
	SPoint3 uv1_new(P1b.x(),P1b.y(),P1b.z());
	coordinates[v1] = uv1_new;
      }
      else if (rot > 0.0 && inverted){
	nbInv++;
	SPoint3 uv2t = coordinates[v2t];
	SVector3 P2t (uv2t.x(),uv2t.y(), uv2t.z());
	SVector3 a = P1-P0;
	SVector3 b = P2t-P0;
	double b_para = dot(a,b)/norm(a);
	SVector3 P3,P2b;
	P3= P0 + (b_para/norm(a))*a;
	P2b = P2t + 1.3*(P3-P2t);
	SPoint3 uv2_new(P2b.x(),P2b.y(),P2b.z());
	coordinates[v2t] = uv2_new;
      }

      MTriangle *tinv = findInvertedTri(adjv, v0,v1,v2, coordinates, nTot);
      if (tinv){
	nbInvTri++;
	MVertex *i0 = NULL;
	MVertex *i1 = NULL;
	for (unsigned int j = 0; j < 3; j++){
	  MVertex *vj = tinv->getVertex(j);
	  if (vj!=v1 && i0 == NULL) i0 = vj;
	  else if (vj!=v1 && i1 ==NULL ) i1 = vj;
	}
	MVertex *i2 = v1;
	SPoint3 uv0 = coordinates[i0];
	SPoint3 uv1 = coordinates[i1];
	SPoint3 uv2 = coordinates[i2];
	SVector3 P0 (uv0.x(),uv0.y(), uv0.z());
	SVector3 P1 (uv1.x(),uv1.y(), uv1.z());
	SVector3 P2 (uv2.x(),uv2.y(), uv2.z());
	SVector3 a = P1-P0;
	SVector3 b = P2-P0;
	double b_para = dot(a,b)/norm(a);
	SVector3 P3,P2b;
	P3= P0 + (b_para/norm(a))*a;
	P2b = P2 + 1.2*(P3-P2);
	SPoint3 uv2_new(P2b.x(),P2b.y(),P2b.z());
	coordinates[i2] = uv2_new;
      }

    }
  }
#endif
}

bool GFaceCompound::one2OneMap() const
{
#if defined(HAVE_MESH)
  if(adjv.size() == 0){
    std::vector<MTriangle*> allTri;
    std::list<GFace*>::const_iterator it = _compound.begin();
    for( ; it != _compound.end(); ++it){
      allTri.insert(allTri.end(), (*it)->triangles.begin(), (*it)->triangles.end() );
    }
    buildVertexToTriangle(allTri, adjv);
  }

  int nbRepair = 0;
  int nbCav = 0;
  for(v2t_cont::iterator it = adjv.begin(); it!= adjv.end(); ++it){
    MVertex *v = it->first;
    SPoint2 p = getCoordinates(v);
    std::vector<MElement*> vTri = it->second;
    std::map<MVertex*,SPoint3> vCoord;
    for (unsigned int j = 0; j < vTri.size(); j++){
      for (int k = 0; k < vTri[j]->getNumVertices(); k++){
        MVertex *vk = vTri[j]->getVertex(k);
        SPoint2 pt2 =  getCoordinates(vk);
	vCoord[vk] = SPoint3(pt2[0], pt2[1], 0.0);
      }
    }
    bool badCavity = checkCavity(vTri, vCoord);
    bool innerCavity = closedCavity(v,vTri);

    if( badCavity && innerCavity ){
      nbCav++;
      double u_cg, v_cg;
      std::vector<MVertex*> cavV;
      myPolygon(vTri, cavV);
      bool success = computeCGKernelPolygon(coordinates, cavV, u_cg, v_cg);
      if (success){
	nbRepair++;
	SPoint3 p_cg(u_cg,v_cg,0.0);
	coordinates[v] = p_cg;
      }
    }
  }
  if (nbRepair == 0) return false;
  else return true;
#endif
}

bool GFaceCompound::parametrize() const
{
  if (_compound.size() > 1) coherencePatches();

  bool paramOK = true;
  if(oct) return paramOK;
  if(trivial()) return paramOK;

  if (_mapping != RBF)
    coordinates.clear();

  computeNormals();

  if(allNodes.empty()) buildAllNodes();

  if (_type != SQUARE){
    bool success = orderVertices(_U0, _ordered, _coords);
    if(!success) {
      Msg::Error("Could not order vertices on boundary");
      return false;
    }
  }

  fillNeumannBCS_Plane();
  //fillNeumannBCS();

  // Convex parametrization
  if (_mapping == CONVEX){
    Msg::Info("Parametrizing surface %d with 'convex map'", tag());
    parametrize(ITERU,CONVEX);
    parametrize(ITERV,CONVEX);
    if (_type==MEANPLANE){
      checkOrientation(0, true);
      // _type = ALREADYFIXED;
      // parametrize(ITERU,CONVEX);
      // parametrize(ITERV,CONVEX);
      // checkOrientation(0, true);
    }
  }
  // Laplace parametrization
  else if (_mapping == HARMONIC){
    Msg::Info("Parametrizing surface %d with 'harmonic map'", tag());
    parametrize(ITERU,HARMONIC);
    parametrize(ITERV,HARMONIC);
    if (_type == MEANPLANE) checkOrientation(0, true);
  }
  // Conformal map parametrization
  else if (_mapping == CONFORMAL){
    std::vector<MVertex *> vert;
    bool oriented;
    if (_type == SPECTRAL){
      Msg::Info("Parametrizing surface %d with 'spectral conformal map'", tag());
      parametrize_conformal_spectral();
    }
    else if (_type == FE){
      Msg::Info("Parametrizing surface %d with 'FE conformal map'", tag());
      parametrize_conformal(0, NULL, NULL);
    }
    //printStuff(55);
    oriented = checkOrientation(0, true);
    //printStuff(77);
    if (_type==SPECTRAL &&  (!oriented  || checkOverlap(vert)) ){
      Msg::Warning("!!! parametrization switched to 'FE conformal' map");
      parametrize_conformal(0, NULL, NULL);
      oriented = checkOrientation(0, true);
    }
    if (!oriented || checkOverlap(vert)){
      Msg::Warning("$$$ parametrization switched to 'convex' map");
      _type  = UNITCIRCLE;
      parametrize(ITERU,CONVEX);
      parametrize(ITERV,CONVEX);
    }
  }
  // Radial-Basis Function parametrization
  else if (_mapping == RBF){
    Msg::Debug("Parametrizing surface %d with 'RBF' ", tag());
    int variableEps = 0;
    int radFunInd = 1; // 1 MQ RBF , 0 GA
    double sizeBox = getSizeH();
    /*
    fullMatrix<double> Oper(3*allNodes.size(),3*allNodes.size());
    _rbf = new GRbf(sizeBox, variableEps, radFunInd, _normals, allNodes, _ordered);
    _rbf->RbfLapSurface_global_CPM_high_2(_rbf->getXYZ(), _rbf->getN(), Oper);
    _rbf->solveHarmonicMap(Oper, _ordered, _coords, coordinates);
    */
    fullMatrix<double> Oper(3*allNodes.size(),3*allNodes.size());

    _rbf = new GRbf(sizeBox, variableEps, radFunInd, _normals, allNodes, _ordered);

    linearSystemPETSc<double> sys;
    #if 1
    _rbf->RbfLapSurface_local_CPM_sparse(_ordered, false, _rbf->getXYZ(), _rbf->getN(), sys);
    _rbf->solveHarmonicMap_sparse(sys, _rbf->getXYZ().size1()* 3,_ordered, _coords, coordinates);
    #else
    _rbf->RbfLapSurface_local_CPM(false, _rbf->getXYZ(), _rbf->getN(), Oper);
    _rbf->solveHarmonicMap(Oper,_ordered, _coords, coordinates);
    #endif
  }

  buildOct();

  if (_mapping != RBF){
    if (!checkOrientation(0)){
      Msg::Info("### parametrization switched to 'convex map' onto circle");
      printStuff(33);
      _type = UNITCIRCLE;
      coordinates.clear();
      Octree_Delete(oct);
      parametrize(ITERU,CONVEX);
      parametrize(ITERV,CONVEX);
      checkOrientation(0);
      buildOct();
    }
  }

  for (unsigned int i= 0; i< fillFaces.size(); i++){
    GModel::current()->remove(fillFaces[i]);
  }

  return paramOK;
}

void GFaceCompound::getBoundingEdges()
{
  for(std::list<GFace*>::iterator it = _compound.begin(); it != _compound.end(); ++it){
    (*it)->setCompound(this);
  }

  std::set<GEdge*> _unique;
  getUniqueEdges(_unique);

  l_edges.clear();

  if(_U0.size()){
    // in case the bounding edges are explicitely given
    std::list<GEdge*>::const_iterator it = _U0.begin();
    for( ; it != _U0.end() ; ++it){
      l_edges.push_back(*it);
      (*it)->addFace(this);
    }
    if (_V0.size() && _U1.size() && _V1.size()){
      it = _V0.begin();
      for( ; it != _V0.end() ; ++it){
	l_edges.push_back(*it);
	(*it)->addFace(this);
      }
      it = _U1.begin();
      for( ; it != _U1.end() ; ++it){
	l_edges.push_back(*it);
	(*it)->addFace(this);
      }
      it = _V1.begin();
      for( ; it != _V1.end() ; ++it){
	l_edges.push_back(*it);
	(*it)->addFace(this);
      }
    }
    std::list<GEdge*> loop;
    computeALoop(_unique, loop);
    while(!_unique.empty())  computeALoop(_unique,loop);
  }
  else{
    // in case the bounding edges are NOT explicitely given
    std::set<GEdge*>::iterator itf = _unique.begin();
    for( ; itf != _unique.end(); ++itf){
      l_edges.push_back(*itf);
      (*itf)->addFace(this);
    }
    std::list<GEdge*> loop;
    computeALoop(_unique,loop);
    while(!_unique.empty())  computeALoop(_unique, loop);

    // assign Derichlet BC (_U0) to boundary with largest size
    double maxSize = 0.0;
    for(std::list<std::list<GEdge*> >::iterator it = _interior_loops.begin();
        it != _interior_loops.end(); it++){
      double size = getSizeBB(*it);
      if (size > maxSize) {
	_U0 = *it;
	maxSize = size;
      }
    }
  }
}

double GFaceCompound::getSizeH() const
{
  SBoundingBox3d bb;
  for(std::set<MVertex *>::iterator itv = allNodes.begin();
      itv != allNodes.end() ; ++itv){
    SPoint3 pt((*itv)->x(),(*itv)->y(), (*itv)->z());
    bb +=pt;
  }

  double H = norm(SVector3(bb.max(), bb.min()));

  return H;
}

double GFaceCompound::getSizeBB(const std::list<GEdge* > &elist) const
{
  SBoundingBox3d bboxD;
  std::list<GEdge*>::const_iterator it = elist.begin();
  for(; it != elist.end(); it++){
    bboxD += (*it)->bounds();
  }
  double D = norm(SVector3(bboxD.max(), bboxD.min()));

  return D;
}

void GFaceCompound::getUniqueEdges(std::set<GEdge*> &_unique)
{
  _unique.clear();

  // in case the bounding edges are not given Boundary { {} };
  std::multiset<GEdge*> _touched;
  std::list<GFace*>::iterator it = _compound.begin();
  for( ; it != _compound.end(); ++it){
    std::list<GEdge*> ed = (*it)->edges();
    std::list<GEdge*>::iterator ite = ed.begin();
    for( ; ite != ed.end(); ++ite){
      _touched.insert(*ite);
    }
  }
  it = _compound.begin();
  for( ; it != _compound.end(); ++it){
    std::list<GEdge*> ed = (*it)->edges();
    std::list<GEdge*>::iterator ite = ed.begin();
    for( ; ite != ed.end() ; ++ite){
      if(!(*ite)->degenerate(0) && _touched.count(*ite) == 1){
        _unique.insert(*ite);
      }
    }
  }
}

void GFaceCompound::computeALoop(std::set<GEdge*> &_unique, std::list<GEdge*> &loop)
{
  std::list<GEdge*> _loop;

  if (_unique.empty()) return;

  while(!_unique.empty()) {
    std::set<GEdge*>::iterator it = _unique.begin();
    GVertex *vB = (*it)->getBeginVertex();
    GVertex *vE = (*it)->getEndVertex();
    _loop.push_back(*it);
    _unique.erase(it);

    bool found = false;
    for(int i = 0; i < 2; i++) {
      for(std::set<GEdge*>::iterator itx = _unique.begin();
          itx != _unique.end(); ++itx){
        GVertex *v1 = (*itx)->getBeginVertex();
        GVertex *v2 = (*itx)->getEndVertex();

        std::set<GEdge*>::iterator itp;
        if(v1 == vE){
          _loop.push_back(*itx);
          itp = itx;
          itx++;
          _unique.erase(itp);
          vE = v2;
          i = -1;
        }
        else if(v2 == vE){
          _loop.push_back(*itx);
          itp = itx;
          itx++;
          _unique.erase(itp);
          vE = v1;
          i=-1;
        }
        if(itx == _unique.end()) break;
      }

      if(vB == vE) {
        found = true;
        break;
      }

      if(_unique.empty())  break;

      GVertex *temp = vB;
      vB = vE;
      vE = temp;
    }

    if(found == true) break;

    it++;
  }

  loop = _loop;
  _interior_loops.push_back(loop);
}

GFaceCompound::GFaceCompound(GModel *m, int tag, std::list<GFace*> &compound,
			     std::list<GEdge*> &U0, typeOfCompound toc,
                             int allowPartition,
			     linearSystem<double>* lsys)
  : GFace(m, tag), _compound(compound), _U0(U0), oct(0), octNew(0),
    _lsys(lsys), _toc(toc), _allowPartition(allowPartition)
{
  ONE = new simpleFunction<double>(1.0);
  MONE = new simpleFunction<double>(-1.0);

  for(std::list<GFace*>::iterator it = _compound.begin(); it != _compound.end(); ++it){
    if(!(*it)){
      Msg::Error("Incorrect face in compound surface %d\n", tag);
      return;
    }
  }

  getBoundingEdges();


  _mapping = HARMONIC;
  _type = UNITCIRCLE;
  if(toc == RADIAL_BASIS)   _mapping = RBF;
  else if (toc == HARMONIC_PLANE) _type = MEANPLANE;
  else if (toc == CONVEX_CIRCLE)  _mapping = CONVEX;
  else if (toc == CONVEX_PLANE){
    _mapping = CONVEX;
    _type = MEANPLANE;
  }
  else if(toc == CONFORMAL_SPECTRAL) {
    _mapping = CONFORMAL;
    _type = SPECTRAL;
  }
  else if(toc == CONFORMAL_FE) {
    _mapping = CONFORMAL;
    _type = FE;
  }

  nbSplit = 0;
  fillTris.clear();

#if defined(HAVE_ANN)
  uv_kdtree = NULL;
  nodes = NULL;
  index = new ANNidx[2];
  dist  = new ANNdist[2];
#endif
}

GFaceCompound::GFaceCompound(GModel *m, int tag, std::list<GFace*> &compound,
			     std::list<GEdge*> &U0, std::list<GEdge*> &V0,
			     std::list<GEdge*> &U1, std::list<GEdge*> &V1,
			     typeOfCompound toc,
			     int allowPartition,
			     linearSystem<double>* lsys)
  : GFace(m, tag), _compound(compound), _U0(U0), _V0(V0), _U1(U1), _V1(V1),
    oct(0), octNew(0), _lsys(lsys), _toc(toc), _allowPartition(allowPartition)
{
  ONE = new simpleFunction<double>(1.0);
  MONE = new simpleFunction<double>(-1.0);

  for(std::list<GFace*>::iterator it = _compound.begin(); it != _compound.end(); ++it){
    if(!(*it)){
      Msg::Error("Incorrect face in compound surface %d\n", tag);
      return;
    }
  }

  getBoundingEdges();

  _mapping = HARMONIC;
  _type = UNITCIRCLE;
  if(toc == RADIAL_BASIS)   _mapping = RBF;
  else if (toc == HARMONIC_PLANE) _type = MEANPLANE;
  else if (toc == CONVEX_CIRCLE)  _mapping = CONVEX;
  else if (toc == CONVEX_PLANE){
    _mapping = CONVEX;
    _type = MEANPLANE;
  }
  if(toc == CONFORMAL_SPECTRAL) {
    _mapping = CONFORMAL;
    _type = SPECTRAL;
  }
  else if(toc == CONFORMAL_FE) {
    _mapping = CONFORMAL;
    _type = FE;
  }
  else if(toc == HARMONIC_SQUARE && _U0.size() && _V0.size() && _U1.size() && _V1.size()) {
    _type = SQUARE;
  }

  nbSplit = 0;
  fillTris.clear();

#if defined(HAVE_ANN)
  uv_kdtree = NULL;
  nodes = NULL;
  index = new ANNidx[2];
  dist  = new ANNdist[2];
#endif
}

GFaceCompound::~GFaceCompound()
{
  for (unsigned int i = 0; i < myParamVert.size(); i++) delete myParamVert[i];
  for (unsigned int i = 0; i < myParamElems.size(); i++) delete myParamElems[i];

  if(oct){
    Octree_Delete(oct);
    delete [] _gfct;
  }
  if(octNew) delete(octNew);
  if (_lsys)delete _lsys;
  delete ONE;
  delete MONE;
#if defined(HAVE_ANN)
  if(uv_kdtree) delete uv_kdtree;
  if(nodes) annDeallocPts(nodes);
  delete[]index;
  delete[]dist;
#endif

}

SPoint2 GFaceCompound::getCoordinates(MVertex *v) const
{
  if(trivial()){
    SPoint2 param;
    reparamMeshVertexOnFace(v, (*(_compound.begin())),param);
    return param;
  }

  std::map<MVertex*,SPoint3>::iterator it = coordinates.find(v);

  if(it != coordinates.end()){
    return SPoint2(it->second.x(),it->second.y());
  }
  else{

    //if(v->onWhat()->dim() == 1){
      double tGlob, tLoc;
      double tL, tR;
      int iEdge;

      // getParameter Point
      v->getParameter(0, tGlob);

      //find compound Edge
      GEdgeCompound *gec = dynamic_cast<GEdgeCompound*>(v->onWhat());

      if(gec){
	// compute local parameter on Edge
	gec->getLocalParameter(tGlob,iEdge,tLoc);
	std::vector<GEdge*> gev = gec->getCompounds();
	GEdge *ge = gev[iEdge];

	// left and right vertex of the Edge
	MVertex *v0 = ge->getBeginVertex()->mesh_vertices[0];
	MVertex *v1 = ge->getEndVertex()->mesh_vertices[0];
	std::map<MVertex*,SPoint3>::iterator itL = coordinates.find(v0);
	std::map<MVertex*,SPoint3>::iterator itR = coordinates.find(v1);

	// for the Edge, find the left and right vertices of the initial
	// 1D mesh and interpolate to find (u,v)
	MVertex *vL = v0;
	MVertex *vR = v1;
	double tB = ge->parBounds(0).low();
	double tE = ge->parBounds(0).high();
	int j = 0;
	tL=tB;
	bool found = false;
	while(j < (int)ge->mesh_vertices.size()){
	  vR = ge->mesh_vertices[j];
          if(vR->getPolynomialOrder() > 1){ j++; continue; }
	  vR->getParameter(0,tR);
	  if(!vR->getParameter(0,tR)) {
	    Msg::Error("Vertex vr %p not an MEdgeVertex", vR);
	    return SPoint2();
	  }
	  if(tLoc > tL && tLoc < tR){
	    found = true;
	    itR = coordinates.find(vR);
	    if(itR == coordinates.end()){
	      Msg::Error("Vertex %p (%g %g %g) not found", vR, vR->x(), vR->y(), vR->z());
              return SPoint2(0,0);
	    }
	    break;
	  }
	  else{
	    itL = coordinates.find(vR);
	    vL = vR;
	    tL = tR;
	  }
	  j++;
	}
	if(!found) {
	  vR = v1;
	  tR = tE;
	}

	// linear interpolation between tL and tR
	double uloc, vloc;
	uloc = itL->second.x() + (tLoc-tL)/(tR-tL) * (itR->second.x()-itL->second.x());
	vloc = itL->second.y() + (tLoc-tL)/(tR-tL) * (itR->second.y()-itL->second.y());
	return SPoint2(uloc,vloc);
      }

    // }
    // else if(v->onWhat()->dim() == 2){
    //   Msg::Debug("Get coordinates of Compound Face cannot find vertex");
    // }

  }

  // never here
  return SPoint2(0, 0);
}

void GFaceCompound::parametrize(iterationStep step, typeOfMapping tom) const
{
  linearSystem<double> *lsys = 0;
  if (_lsys) lsys = _lsys;
  else{
    if (tom==HARMONIC){
#if defined(HAVE_TAUCS)
      lsys = new linearSystemCSRTaucs<double>;
#elif defined(HAVE_PETSC) && !defined(HAVE_TAUCS)
      lsys = new linearSystemPETSc<double>;
#elif defined(HAVE_GMM) && !defined(HAVE_TAUCS)
      linearSystemGmm<double> *lsysb = new linearSystemGmm<double>;
      lsysb->setGmres(1);
      lsys = lsysb;
#else
      lsys = new linearSystemFull<double>;
#endif
    }
    else if (tom==CONVEX){
#if defined(HAVE_PETSC)
      lsys = new linearSystemPETSc<double>;
#elif defined(HAVE_GMM)
      linearSystemGmm<double> *lsysb = new linearSystemGmm<double>;
      lsysb->setGmres(1);
      lsys = lsysb;
#else
      lsys = new linearSystemFull<double>;
#endif
    }
  }

  dofManager<double> myAssembler(lsys);

  if(_type == UNITCIRCLE){
    for(unsigned int i = 0; i < _ordered.size(); i++){
      MVertex *v = _ordered[i];
      const double theta = 2 * M_PI * _coords[i];
      if(step == ITERU) myAssembler.fixVertex(v, 0, 1, cos(theta));
      else if(step == ITERV) myAssembler.fixVertex(v, 0, 1, sin(theta));
    }
  }
  else if(_type == SQUARE){
    if(step == ITERU){
      std::list<GEdge*>::const_iterator it = _U0.begin();
      for( ; it != _U0.end(); ++it){
	fixEdgeToValue(*it, 0.0, myAssembler);
      }
      it = _U1.begin();
      for( ; it != _U1.end(); ++it){
	fixEdgeToValue(*it, 1.0, myAssembler);
      }
    }
    else if(step == ITERV){
      std::list<GEdge*>::const_iterator it = _V0.begin();
      for( ; it != _V0.end(); ++it){
	fixEdgeToValue(*it, 0.0, myAssembler);
      }
      it = _V1.begin();
      for( ; it != _V1.end(); ++it){
	fixEdgeToValue(*it, 1.0, myAssembler);
      }
    }
  }
  else if (_type == MEANPLANE){
    std::vector<SPoint3> points, pointsProj, pointsUV;
    SPoint3 ptCG(0.0, 0.0, 0.0);
    for(unsigned int i = 0; i < _ordered.size(); i++){
      MVertex *v = _ordered[i];
      points.push_back(SPoint3(v->x(), v->y(), v->z()));
      ptCG[0] += v->x();
      ptCG[1] += v->y();
      ptCG[2] += v->z();
    }

    ptCG /= points.size();
    mean_plane meanPlane;
    computeMeanPlaneSimple(points, meanPlane);
    projectPointsToPlane(points, pointsProj, meanPlane);
    transformPointsIntoOrthoBasis(pointsProj, pointsUV, ptCG, meanPlane);

    for(unsigned int i = 0; i < pointsUV.size(); i++){
      MVertex *v = _ordered[i];
      if(step == ITERU) myAssembler.fixVertex(v, 0, 1, pointsUV[i][0]);
      else if(step == ITERV) myAssembler.fixVertex(v, 0, 1, pointsUV[i][1]);
    }
  }
  else if (_type == ALREADYFIXED){
    printf("already fixed boundaries \n");
    for(unsigned int i = 0; i < _ordered.size(); i++){
      MVertex *v = _ordered[i];
      SPoint3 uv = coordinates[v];
      if(step == ITERU) myAssembler.fixVertex(v, 0, 1, uv[0]);
      else if(step == ITERV) myAssembler.fixVertex(v, 0, 1, uv[1]);
    }
  }
  else{
    Msg::Error("Unknown type of parametrization");
    return;
  }

  std::list<GFace*>::const_iterator it = _compound.begin();
  for( ; it != _compound.end(); ++it){
    for(unsigned int i = 0; i < (*it)->triangles.size(); ++i){
      MTriangle *t = (*it)->triangles[i];
      myAssembler.numberVertex(t->getVertex(0), 0, 1);
      myAssembler.numberVertex(t->getVertex(1), 0, 1);
      myAssembler.numberVertex(t->getVertex(2), 0, 1);
    }
  }

  for (std::list<MTriangle*>::iterator it2 = fillTris.begin(); it2 !=fillTris.end(); it2++ ){
    MTriangle *t = (*it2);
    myAssembler.numberVertex(t->getVertex(0), 0, 1);
    myAssembler.numberVertex(t->getVertex(1), 0, 1);
    myAssembler.numberVertex(t->getVertex(2), 0, 1);
  }

  Msg::Debug("Creating term %d dofs numbered %d fixed",
             myAssembler.sizeOfR(), myAssembler.sizeOfF());

  double t1 = Cpu();

  femTerm<double> *mapping;
  if (tom == HARMONIC)
    mapping = new laplaceTerm(0, 1, ONE);
  else
    mapping = new convexCombinationTerm(0, 1, ONE);

  it = _compound.begin();
  for( ; it != _compound.end() ; ++it){
    for(unsigned int i = 0; i < (*it)->triangles.size(); ++i){
      SElement se((*it)->triangles[i]);
      mapping->addToMatrix(myAssembler, &se);
    }
  }

  for (std::list<MTriangle*>::iterator it2 = fillTris.begin(); it2 !=fillTris.end(); it2++ ){
    SElement se((*it2));
    mapping->addToMatrix(myAssembler, &se);
  }

  double t2 = Cpu();
  Msg::Debug("Assembly done in %8.3f seconds", t2 - t1);
  lsys->systemSolve();
  Msg::Debug("System solved");

  for(std::set<MVertex *>::iterator itv = allNodes.begin(); itv !=allNodes.end() ; ++itv){
    MVertex *v = *itv;
    double value;
    myAssembler.getDofValue(v, 0, 1, value);
    std::map<MVertex*,SPoint3>::iterator itf = coordinates.find(v);
    if(itf == coordinates.end()){
      SPoint3 p(0, 0, 0);
      p[step] = value;
      coordinates[v] = p;
    }
    else{
      itf->second[step]= value;
    }
  }

  if (_lsys)
    lsys->clear();
  else
    delete lsys;
}

bool GFaceCompound::parametrize_conformal_spectral() const
{
#if !defined(HAVE_PETSC) && !defined(HAVE_SLEPC)
  Msg::Warning("Slepc not installed: parametrization switched to 'FE conformal' map");
  return parametrize_conformal(0, NULL, NULL);
#else

  linearSystem <double> *lsysA  = new linearSystemPETSc<double>;
  linearSystem <double> *lsysB  = new linearSystemPETSc<double>;
  dofManager<double> myAssembler(lsysA, lsysB);

  myAssembler.setCurrentMatrix("A");
  for(std::set<MVertex *>::iterator itv = allNodes.begin(); itv !=allNodes.end() ; ++itv){
    MVertex *v = *itv;
    myAssembler.numberVertex(v, 0, 1);
    myAssembler.numberVertex(v, 0, 2);
  }

  // for(std::set<MVertex *>::iterator itv = fillNodes.begin(); itv !=fillNodes.end() ; ++itv){
  //   MVertex *v = *itv;
  //   myAssembler.numberVertex(v, 0, 1);
  //   myAssembler.numberVertex(v, 0, 2);
  // }

  laplaceTerm laplace1(model(), 1, ONE);
  laplaceTerm laplace2(model(), 2, ONE);
  crossConfTerm cross12(model(), 1, 2, ONE);
  crossConfTerm cross21(model(), 2, 1, MONE);
  std::list<GFace*>::const_iterator it = _compound.begin();
  for( ; it != _compound.end() ; ++it){
    for(unsigned int i = 0; i < (*it)->triangles.size(); ++i){
      SElement se((*it)->triangles[i]);
      laplace1.addToMatrix(myAssembler, &se);
      laplace2.addToMatrix(myAssembler, &se);
      cross12.addToMatrix(myAssembler, &se);
      cross21.addToMatrix(myAssembler, &se);
    }
  }

  // for (std::list<MTriangle*>::iterator it2 = fillTris.begin(); it2 != fillTris.end(); it2++){
  //   SElement se((*it2));
  //   laplace1.addToMatrix(myAssembler, &se);
  //   laplace2.addToMatrix(myAssembler, &se);
  //   cross12.addToMatrix(myAssembler, &se);
  //   cross21.addToMatrix(myAssembler, &se);
  // }

  double epsilon = 1.e-6;
  for(std::set<MVertex *>::iterator itv = allNodes.begin(); itv !=allNodes.end() ; ++itv){
    MVertex *v = *itv;
    if (std::find(_ordered.begin(), _ordered.end(), v) == _ordered.end() ){
      myAssembler.assemble(v, 0, 1, v, 0, 1,  epsilon);
      myAssembler.assemble(v, 0, 2, v, 0, 2,  epsilon);
    }
  }
  for(std::set<MVertex *>::iterator itv = fillNodes.begin(); itv !=fillNodes.end() ; ++itv){
    MVertex *v = *itv;
    if (std::find(_ordered.begin(), _ordered.end(), v) == _ordered.end() ){
      myAssembler.assemble(v, 0, 1, v, 0, 1,  epsilon);
      myAssembler.assemble(v, 0, 2, v, 0, 2,  epsilon);
    }
  }

  myAssembler.setCurrentMatrix("B");

  // mettre max NC contraintes par bord
  int NB = _ordered.size();
  int NC = std::min(30,NB);
  int jump = (int) NB/NC;
  int nbLoop = (int) NB/jump ;
  for (int i = 0; i< nbLoop; i++){
    MVertex *v1 = _ordered[i*jump];
    myAssembler.assemble(v1, 0, 1, v1, 0, 1,  1.0);
    myAssembler.assemble(v1, 0, 2, v1, 0, 2,  1.0);
    for (int j = 0; j< nbLoop; j++){
      MVertex *v2 = _ordered[j*jump];
      myAssembler.assemble(v1, 0, 1, v2, 0, 1,  -1./NC);
      myAssembler.assemble(v1, 0, 2, v2, 0, 2,  -1./NC);
    }
  }

  // FIXME: force non-hermitian. For some reason (roundoff errors?)
  // on some machines and for some meshes slepc complains about bad IP
  // norm otherwise
  eigenSolver eig(&myAssembler, "B" , "A", false);

  bool converged = eig.solve(1, "largest");

  if(converged) {
    double Linfty = 0.0;
    int k = 0;
    std::vector<std::complex<double> > &ev = eig.getEigenVector(0);
    for(std::set<MVertex *>::iterator itv = allNodes.begin(); itv !=allNodes.end() ; ++itv){
      double paramu = ev[k].real();
      double paramv = ev[k+1].real();
      Linfty=std::max(Linfty, sqrt(paramu*paramu+paramv*paramv));
      k = k+2;
    }
    k = 0;
    for(std::set<MVertex *>::iterator itv = allNodes.begin(); itv !=allNodes.end() ; ++itv){
      MVertex *v = *itv;
      double paramu = ev[k].real()/Linfty;
      double paramv = ev[k+1].real()/Linfty;
      coordinates[v] = SPoint3(paramu,paramv,0.0);
      k = k+2;
    }
    delete lsysA;
    delete lsysB;
  }
  else{
    Msg::Warning("Slepc not converged: parametrization switched to 'FE conformal' map");
    return parametrize_conformal(0,NULL,NULL);
  }

  std::vector<MVertex *> vert;
  return checkOverlap(vert);
#endif
}

bool GFaceCompound::parametrize_conformal(int iter, MVertex *v1, MVertex *v2) const
{
  linearSystem<double> *lsys = 0;
#if defined(HAVE_PETSC) && !defined(HAVE_TAUCS)
  lsys = new linearSystemPETSc<double>;
#elif defined(HAVE_GMM) && !defined(HAVE_TAUCS)
  linearSystemGmm<double> *lsysb = new linearSystemGmm<double>;
  lsysb->setGmres(1);
  lsys = lsysb;
#elif defined(HAVE_TAUCS)
  lsys = new linearSystemCSRTaucs<double>;
#else
  lsys = new linearSystemFull<double>;
#endif

  dofManager<double> myAssembler(lsys);

  if(!v1) v1 = _ordered[0];
  if(!v2) v2 = _ordered[(int)ceil((double)_ordered.size()/2.)];
  myAssembler.fixVertex(v1, 0, 1, 1.);
  myAssembler.fixVertex(v1, 0, 2, 0.);
  myAssembler.fixVertex(v2, 0, 1, -1.);
  myAssembler.fixVertex(v2, 0, 2, 0.);

  std::list<GFace*>::const_iterator it = _compound.begin();
  for( ; it != _compound.end(); ++it){
    for(unsigned int i = 0; i < (*it)->triangles.size(); ++i){
      MTriangle *t = (*it)->triangles[i];
      myAssembler.numberVertex(t->getVertex(0), 0, 1);
      myAssembler.numberVertex(t->getVertex(1), 0, 1);
      myAssembler.numberVertex(t->getVertex(2), 0, 1);
      myAssembler.numberVertex(t->getVertex(0), 0, 2);
      myAssembler.numberVertex(t->getVertex(1), 0, 2);
      myAssembler.numberVertex(t->getVertex(2), 0, 2);
    }
  }
  for (std::list<MTriangle*>::iterator it2 = fillTris.begin();
       it2 !=fillTris.end(); it2++){
    MTriangle *t = (*it2);
    myAssembler.numberVertex(t->getVertex(0), 0, 1);
    myAssembler.numberVertex(t->getVertex(1), 0, 1);
    myAssembler.numberVertex(t->getVertex(2), 0, 1);
    myAssembler.numberVertex(t->getVertex(0), 0, 2);
    myAssembler.numberVertex(t->getVertex(1), 0, 2);
    myAssembler.numberVertex(t->getVertex(2), 0, 2);
  }

  laplaceTerm laplace1(model(), 1, ONE);
  laplaceTerm laplace2(model(), 2, ONE);
  crossConfTerm cross12(model(), 1, 2, ONE);
  crossConfTerm cross21(model(), 2, 1, MONE);
  it = _compound.begin();
  for( ; it != _compound.end() ; ++it){
    for(unsigned int i = 0; i < (*it)->triangles.size(); ++i){
      SElement se((*it)->triangles[i]);
      laplace1.addToMatrix(myAssembler, &se);
      laplace2.addToMatrix(myAssembler, &se);
      cross12.addToMatrix(myAssembler, &se);
      cross21.addToMatrix(myAssembler, &se);
    }
  }
  for (std::list<MTriangle*>::iterator it2 = fillTris.begin();
       it2 != fillTris.end(); it2++ ){
    SElement se((*it2));
    laplace1.addToMatrix(myAssembler, &se);
    laplace2.addToMatrix(myAssembler, &se);
    cross12.addToMatrix(myAssembler, &se);
    cross21.addToMatrix(myAssembler, &se);
  }

  Msg::Debug("Assembly done");
  lsys->systemSolve();
  Msg::Debug("System solved");

  for(std::set<MVertex *>::iterator itv = allNodes.begin();
      itv != allNodes.end() ; ++itv){
    MVertex *v = *itv;
    double value1, value2;
    myAssembler.getDofValue(v, 0, 1, value1);
    myAssembler.getDofValue(v, 0, 2, value2);
    coordinates[v] = SPoint3(value1,value2,0.0);
  }

  delete lsys;

  // check for overlap and compute new mapping with new pinned
  // vertices
  std::vector<MVertex *> vert;
  bool hasOverlap = checkOverlap(vert);
  return hasOverlap;
  // if ( hasOverlap && iter < 3){
  //   Msg::Info("Loop FE conformal iter (%d) v1=%d v2=%d", iter,
  //             vert[0]->getNum(), vert[1]->getNum());
  //   printStuff(100+iter);
  //   return hasOverlap = parametrize_conformal(iter+1, vert[0],vert[1]);
  // }
  // else{
  //   return hasOverlap;
  // }
}

void GFaceCompound::computeNormals(std::map<MVertex*,SVector3> &normals) const
{
  computeNormals ();
  normals = _normals;
}

void GFaceCompound::computeNormals() const
{
  _normals.clear();
  std::list<GFace*>::const_iterator it = _compound.begin();
  double J[3][3];
  for( ; it != _compound.end() ; ++it){
    for(unsigned int i = 0; i < (*it)->triangles.size(); ++i){
      MTriangle *t = (*it)->triangles[i];
      t->getJacobian(0, 0, 0, J);
      SVector3 n (J[2][0], J[2][1], J[2][2]);
      n.normalize();
      for(int j = 0; j < 3; j++){
        std::map<MVertex*, SVector3>::iterator itn = _normals.find(t->getVertex(j));
        if(itn == _normals.end())_normals[t->getVertex(j)] = n;
        else itn->second += n;
      }
    }
  }
  std::map<MVertex*,SVector3>::iterator itn = _normals.begin();
  for( ; itn != _normals.end() ; ++itn) itn->second.normalize();
}

double GFaceCompound::curvatureMax(const SPoint2 &param) const
{
  if(!oct) parametrize();
  if(trivial()) {
    return (*(_compound.begin()))->curvatureMax(param);
  }

  double U, V;
  GFaceCompoundTriangle *lt;
  getTriangle(param.x(), param.y(), &lt, U,V);

  if(!lt) return 0.0;

  if(lt->gf && lt->gf->geomType() != GEntity::DiscreteSurface) {
    SPoint2 pv = lt->gfp1*(1.-U-V) + lt->gfp2*U + lt->gfp3*V;
    return lt->gf->curvatureMax(pv);
  }
  else if (lt->gf->geomType() == GEntity::DiscreteSurface) {
    Curvature& curvature = Curvature::getInstance();
    if( !Curvature::valueAlreadyComputed() ) {
      Msg::Info("Need to compute discrete curvature for isotropic remesh (in GFace)");
      Curvature::typeOfCurvature type = Curvature::RUSIN;
      curvature.computeCurvature(model(), type);
    }
    double c0,c1,c2;
    curvature.triangleNodalValues(lt->tri,c0, c1, c2, 1);
    double cv = (1-U-V)*c0 + U*c1 + V*c2;
    return cv;
  }

  return 0.;
}

double GFaceCompound::curvatures(const SPoint2 &param, SVector3 *dirMax, SVector3 *dirMin,
                                 double *curvMax, double *curvMin) const
{
  if(!oct) parametrize();
  if(trivial()) {
    return (*(_compound.begin()))->curvatures(param, dirMax,dirMin, curvMax, curvMin);
  }

  double U, V;
  GFaceCompoundTriangle *lt;
  getTriangle(param.x(), param.y(), &lt, U,V);

  if(!lt) return 0.0;

  if(lt->gf && lt->gf->geomType() != GEntity::DiscreteSurface){
    SPoint2 pv = lt->gfp1*(1.-U-V) + lt->gfp2*U + lt->gfp3*V;
    return lt->gf->curvatures(pv, dirMax,dirMin, curvMax, curvMin);
  }
  else if (lt->gf->geomType() == GEntity::DiscreteSurface){
    Curvature& curvature = Curvature::getInstance();
    if( !Curvature::valueAlreadyComputed() ) {
      Msg::Info("Need to compute discrete curvature for anisotropic remesh (in GFace)");
      Curvature::typeOfCurvature type = Curvature::RUSIN; //RBF
      curvature.computeCurvature(model(), type);
    }

    double cMin[3];
    double cMax[3];
    SVector3 dMin[3];
    SVector3 dMax[3];
    curvature.triangleNodalValuesAndDirections(lt->tri, dMax, dMin, cMax, cMin, 0);
    //curvature.triangleNodalValuesAndDirections(lt->tri, dMax, dMin, cMax, cMin, 1);

    *dirMax = (1-U-V)*dMax[0] + U*dMax[1] + V*dMax[2];
    *dirMin = (1-U-V)*dMin[0] + U*dMin[1] + V*dMin[2];
    *curvMax = (1-U-V)*cMax[0] + U*cMax[1] + V*cMax[2];
    *curvMin = (1-U-V)*cMin[0] + U*cMin[1] + V*cMin[2];

    return *curvMax;
  }
  return 0.;
}

double GFaceCompound::locCurvature(MTriangle *t, double u, double v) const
{
  SVector3 n1 = _normals[t->getVertex(0)];
  SVector3 n2 = _normals[t->getVertex(1)];
  SVector3 n3 = _normals[t->getVertex(2)];
  double val[9] = {n1.x(), n2.x(), n3.x(),
                   n1.y(), n2.y(), n3.y(),
                   n1.z(), n2.z(), n3.z()};
  return fabs(t->interpolateDiv(val, u, v, 3));
}

SPoint2 GFaceCompound::parFromVertex(MVertex *v) const
{
  double U=0.0,V=0.0;
  if(v->onWhat()->dim()==2){// && meshStatistics.status == GFace::DONE) {
    v->getParameter(0, U);
    v->getParameter(1, V);
  }
  if (v->onWhat()->dim()==1 ||
     (v->onWhat()->dim()==2  && U == -1 && V==-1)){ //if MFaceVertex created on edge in bunin
    SPoint2 sp = getCoordinates(v);
    U = sp.x();
    V = sp.y();
  }
  if (v->onWhat()->dim()==0){
    SPoint2 sp = parFromPoint(SPoint3(v->x(), v->y(), v->z()));
    U = sp.x();
    V = sp.y();
  }
  return SPoint2(U,V);

}
SPoint2 GFaceCompound::parFromPoint(const SPoint3 &p, bool onSurface) const
{
  if(!oct) parametrize();

  std::map<SPoint3,SPoint3>::const_iterator it = _coordPoints.find(p);
  SPoint3 sp = it->second;

  return SPoint2(sp.x(), sp.y());
}

GPoint GFaceCompound::pointInRemeshedOctree(double par1, double par2) const
{
  //printf("in remeshed oct for par =%g %g\n", par1,par2);

  //if not meshed yet
  if (meshStatistics.status != GFace::DONE || triangles.size()+quadrangles.size() == 0) {
    GPoint gp (3,3,0,this);
    gp.setNoSuccess();
    return gp;
  }

  //create new octree with new mesh elements
  if(!octNew){
    //FILE * of = fopen("myOCTREE.pos","w");
    //fprintf(of, "View \"\"{\n");

    std::vector<MElement *> myElems;
    for (unsigned int i = 0; i < triangles.size(); i++) myElems.push_back(triangles[i]);
    for (unsigned int i = 0; i < quadrangles.size(); i++) myElems.push_back(quadrangles[i]);

    std::set<SPoint2> myBCNodes;
    for (unsigned int i = 0; i < myElems.size(); i++){
      MElement *e = myElems[i];
      MVertex *news[4];
      for (int j = 0; j < e->getNumVertices(); j++){
	MVertex *v = e->getVertex(j);
	std::map<MVertex*,MVertex*>::iterator it = _3Dto2D.find(v);
	MVertex *newv =0;
	if (it == _3Dto2D.end()){
	  SPoint2 p = parFromVertex(v);
	  newv = new MVertex (p.x(), p.y(), 0.0);
	  myParamVert.push_back(newv);
	  _3Dto2D[v] = newv;
	  _2Dto3D[newv] = v;
	  if(v->onWhat()->dim()<2) myBCNodes.insert(p);
	}
	else newv = it->second;
	news[j] = newv;
      }

      if(e->getType() == TYPE_TRI)
  	myParamElems.push_back(new MTriangle(news[0],news[1],news[2],e->getNum()));
      else if (e->getType() == TYPE_QUA) {
  	myParamElems.push_back(new MQuadrangle(news[0],news[1],news[2],news[3],e->getNum()));
	// fprintf(of, "SQ(%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g,%g};\n",
	// 	news[0]->x(), news[0]->y(), news[0]->z(),
	// 	news[1]->x(), news[1]->y(), news[1]->z(),
	// 	news[2]->x(), news[2]->y(), news[2]->z(),
	// 	news[3]->x(), news[3]->y(), news[3]->z(),
	// 	(double)e->getNum(), (double)e->getNum(), (double)e->getNum(), (double)e->getNum());
      }
    }

    octNew = new MElementOctree(myParamElems);

    //build kdtree boundary nodes in parametric space
#if defined(HAVE_ANN)
    nodes = annAllocPts(myBCNodes.size(), 3);
    std::set<SPoint2>::iterator itp = myBCNodes.begin();
    int ind = 0;
    while (itp != myBCNodes.end()){
      SPoint2 pt = *itp;
      //fprintf(of, "SP(%g,%g,%g){%g};\n", pt.x(), pt.y(), 0.0, 10000);
      nodes[ind][0] = pt.x();
      nodes[ind][1] = pt.y();
      nodes[ind][2] = 0.0;
      itp++; ind++;
    }
    uv_kdtree = new ANNkd_tree(nodes, myBCNodes.size(), 3);
#endif
    //fprintf(of,"};\n");
    //fclose(of);
  }

  //now use new octree to find point
  double uvw[3]={par1,par2, 0.0};
  double UV[3];
  double initialTol = MElement::getTolerance();
  MElement::setTolerance(1.e-2);
  MElement *e = octNew->find(par1,par2, 0.0,-1,false);
  MElement::setTolerance(initialTol);
  if (e){
    e->xyz2uvw(uvw,UV);
    double valX[8], valY[8], valZ[8];
    for (int i=0;i<e->getNumPrimaryVertices();i++){
      MVertex *v = _2Dto3D[e->getVertex(i)];
      valX[i] = v->x();
      valY[i] = v->y();
      valZ[i] = v->z();
    }
    GPoint gp;
    gp.x() = e->interpolate(valX,UV[0],UV[1],UV[2]);
    gp.y() = e->interpolate(valY,UV[0],UV[1],UV[2]);
    gp.z() = e->interpolate(valZ,UV[0],UV[1],UV[2]);
    //printf("found point in new octree (UV=%g %g) %g %g %g (E=%D)\n",par1, par2, gp.x(), gp.y(), gp.z(), e->getNum());
    return gp;
  }
  //if element not found in new octree find closest point
  else{
    //printf("point not found on octnew --> look closest point with kdtree \n");
    GPoint gp(50,50,50);
#if defined(HAVE_ANN)
    double pt[3] = {par1,par2,0.0};
    uv_kdtree->annkSearch(pt, 2, index, dist);
    SPoint3  p1(nodes[index[0]][0], nodes[index[0]][1], nodes[index[0]][2]);
    SPoint3  p2(nodes[index[1]][0], nodes[index[1]][1], nodes[index[1]][2]);
    SPoint3 pnew; double d;
    signedDistancePointLine(p1,p2, SPoint3(par1,par2,0.0), d, pnew);
    //printf("p1=%g %g p2=%g %g \n", p1.x(), p1.y(), p2.x(), p2.y());
    //printf("UV=%g %g UVnew =%g %g \n", par1,par2, pnew.x(), pnew.y());

    double uvw[3]={pnew.x(),pnew.y(), 0.0};
    double UV[3];
    MElement *e = octNew->find(pnew.x(), pnew.y(), 0.0,-1,true);
    if(!e)    e = octNew->find(p1.x(), p1.y(), 0.0,-1,true);
    if( e){
      e->xyz2uvw(uvw,UV);
      double valX[8], valY[8], valZ[8];
      for (int i=0;i<e->getNumPrimaryVertices();i++){
	MVertex *v = _2Dto3D[e->getVertex(i)];
	valX[i] = v->x();
	valY[i] = v->y();
	valZ[i] = v->z();
      }
      gp.x() = e->interpolate(valX,UV[0],UV[1],UV[2]);
      gp.y() = e->interpolate(valY,UV[0],UV[1],UV[2]);
      gp.z() = e->interpolate(valZ,UV[0],UV[1],UV[2]);
      //printf("found closest point (UV=%g %g) %g %g %g \n",pnew.x(), pnew.y(), gp.y(), gp.z());
    }
    else{
      Msg::Error("Point not found in kdtree");
      gp.setNoSuccess();
    }
#else
    gp.setNoSuccess();
#endif

    if (gp.succeeded()) return gp;
    else{
      Msg::Error("NOT found point with ANN %g %g", par1, par2);
      GPoint gp (30,30,30,this);
      gp.setNoSuccess();
      return gp;
    }
  }
}

GPoint GFaceCompound::point(double par1, double par2) const
{
  if(trivial()){
    return (*(_compound.begin()))->point(par1,par2);
  }

  if(!oct) parametrize();

  double U,V;
  double par[2] = {par1,par2};
  GFaceCompoundTriangle *lt;
  getTriangle(par1, par2, &lt, U,V);
  if(!lt && _mapping != RBF){
    //printf("POINT no success %d tris %d quad \n", triangles.size(), quadrangles.size());
    GPoint gp = pointInRemeshedOctree(par1,par2);
    return gp;
  }
  else if (!lt && _mapping == RBF){
    if (fabs(par1) > 1 || fabs(par2) > 1){
      GPoint gp (0,0,0,this);
      gp.setNoSuccess();
      return gp;
    }
    double x, y, z;
    SVector3 dXdu, dXdv;
    _rbf->UVStoXYZ(par1, par2,x,y,z, dXdu, dXdv);
    return GPoint(x,y,z);
  }

  if (lt->gf->geomType() != GEntity::DiscreteSurface){
    SPoint2 pParam = lt->gfp1*(1.-U-V) + lt->gfp2*U + lt->gfp3*V;
    GPoint pp = lt->gf->point(pParam);
    return GPoint(pp.x(),pp.y(),pp.z(),this,par);
  }

  const bool LINEARMESH = true; //false
  if(LINEARMESH){
    // linear Lagrange mesh
    SPoint3 p = lt->v1*(1.-U-V) + lt->v2*U + lt->v3*V;
    return GPoint(p.x(),p.y(),p.z(),this,par);
  }
  else{
    // curved PN triangle
    const SVector3 n1 = _normals[lt->tri->getVertex(0)];
    const SVector3 n2 = _normals[lt->tri->getVertex(1)];
    const SVector3 n3 = _normals[lt->tri->getVertex(2)];

    SVector3 b300, b030, b003;
    SVector3 b210, b120, b021, b012, b102, b201, E, VV, b111;
    b300 = lt->v1;
    b030 = lt->v2;
    b003 = lt->v3;

    // tagged PN triangles (sigma=1)
    double theta = 0.0;
    SVector3 d1 = lt->v1+.33*(1-theta)*(lt->v2-lt->v1);
    SVector3 d2 = lt->v2+.33*(1-theta)*(lt->v1-lt->v2);
    SVector3 X1 = 1/norm(n1)*n1;
    SVector3 X2 = 1/norm(n2)*n2;
    b210 = d1 - dot(X1,d1-lt->v1)*X1;
    b120 = d2 - dot(X2,d2-lt->v2)*X2;
    SVector3 d3 = lt->v2+.33*(1-theta)*(lt->v3-lt->v2);
    SVector3 d4 = lt->v3+.33*(1-theta)*(lt->v2-lt->v3);
    SVector3 X3 = 1/norm(n2)*n2;
    SVector3 X4 = 1/norm(n3)*n3;
    b021 = d3 - dot(X3,d3-lt->v2)*X3;
    b012 = d4 - dot(X4,d4-lt->v3)*X4;
    SVector3 d5 = lt->v3+.33*(1-theta)*(lt->v1-lt->v3);
    SVector3 d6 = lt->v1+.33*(1-theta)*(lt->v3-lt->v1);
    SVector3 X5 = 1/norm(n3)*n3;
    SVector3 X6 = 1/norm(n1)*n1;
    b102 = d5 - dot(X5,d5-lt->v3)*X5;
    b201 = d6 - dot(X6,d6-lt->v1)*X6;

    E=(b210+b120+b021+b012+b102+b201)*0.16667;
    VV=(lt->v1+lt->v2+lt->v3)*0.333;
    b111=E+(E-VV)*0.5;

    double W = 1-U-V;
    SVector3 point = b300*W*W*W+b030*U*U*U+b003*V*V*V+
      b210*3.*W*W*U+b120*3.*W*U*U+b201*3.*W*W*V+
      b021*3.*U*U*V+b102*3.*W*V*V+b012*3.*U*V*V+
      b111*6.*W*U*V;

    SPoint3 PP(point.x(), point.y(), point.z());
    return GPoint(PP.x(),PP.y(),PP.z(),this,par);
  }
}

Pair<SVector3,SVector3> GFaceCompound::firstDer(const SPoint2 &param) const
{
  if(!oct) parametrize();

  if(trivial())
    return (*(_compound.begin()))->firstDer(param);

  double U, V;
  GFaceCompoundTriangle *lt;
  getTriangle(param.x(), param.y(), &lt, U,V);
  if(!lt && _mapping != RBF)
    return Pair<SVector3, SVector3>(SVector3(1, 0, 0), SVector3(0, 1, 0));
  else if (!lt && _mapping == RBF){
    double x, y, z;
    SVector3 dXdu, dXdv  ;
    _rbf->UVStoXYZ(param.x(), param.y(), x, y, z, dXdu, dXdv);
    return Pair<SVector3, SVector3>(dXdu, dXdv);
  }

  double mat[2][2] = {{lt->p2.x() - lt->p1.x(), lt->p3.x() - lt->p1.x()},
                      {lt->p2.y() - lt->p1.y(), lt->p3.y() - lt->p1.y()}};
  double inv[2][2];
  double det = inv2x2(mat,inv);
  if (!det && _mapping == RBF){
    double x, y, z;
    SVector3 dXdu, dXdv  ;
    _rbf->UVStoXYZ(param.x(), param.y(), x, y, z, dXdu, dXdv);
    return Pair<SVector3, SVector3>(dXdu, dXdv);
  }

  SVector3 dXdxi(lt->v2 - lt->v1);
  SVector3 dXdeta(lt->v3 - lt->v1);

  SVector3 dXdu(dXdxi * inv[0][0] + dXdeta * inv[1][0]);
  SVector3 dXdv(dXdxi * inv[0][1] + dXdeta * inv[1][1]);

  return Pair<SVector3, SVector3>(dXdu, dXdv);
}

void GFaceCompound::secondDer(const SPoint2 &param,
                              SVector3 *dudu, SVector3 *dvdv, SVector3 *dudv) const
{
  if(!oct) parametrize();
  //leave debug here (since outputScalarField calls curvatureDiv)
  Msg::Debug("Computation of the second derivatives is not implemented for compound faces");
}

static void GFaceCompoundBB(void *a, double*mmin, double*mmax)
{
  GFaceCompoundTriangle *t = (GFaceCompoundTriangle *)a;
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

static void GFaceCompoundCentroid(void *a, double*c)
{
  GFaceCompoundTriangle *t = (GFaceCompoundTriangle *)a;
  c[0] = (t->p1.x() + t->p2.x() + t->p3.x()) / 3.0;
  c[1] = (t->p1.y() + t->p2.y() + t->p3.y()) / 3.0;
  c[2] = 0.0;
}

static int GFaceCompoundInEle(void *a, double*c)
{
  GFaceCompoundTriangle *t = (GFaceCompoundTriangle *)a;
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
  if(X[0] > -eps && X[1] > -eps && 1. - X[0] - X[1] > -eps){
    return 1;
  }
  return 0;
}

void GFaceCompound::getTriangle(double u, double v,
                                GFaceCompoundTriangle **lt,
                                double &_u, double &_v) const
{
  double uv[3] = {u, v, 0};
  // if (_mapping == RBF){
  //   std::list<void*> l;
  //   Octree_SearchAll(uv, oct, &l);
  //   if (l.size() > 1 || l.size() == 0){
  //     GFaceCompoundTriangle *gfct = NULL;
  //     *lt = gfct;
  //     return;
  //   }
  //   else{
  //     std::list<void*>::iterator it = l.begin();
  //     *lt = (GFaceCompoundTriangle*)(*it);
  //   }
  // }

  *lt = (GFaceCompoundTriangle*)Octree_Search(uv, oct);

  // if(!(*lt)) {
  //     for(int i=0;i<nbT;i++){
  //       if(GFaceCompoundInEle (&_gfct[i],uv)){
  //      *lt = &_gfct[i];
  //      break;
  //       }
  //     }
  // }
  if(!(*lt)){
    return;
  }

  double M[2][2],X[2],R[2];
  const SPoint3 p0 = (*lt)->p1;
  const SPoint3 p1 = (*lt)->p2;
  const SPoint3 p2 = (*lt)->p3;
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

void GFaceCompound::buildOct() const
{
  SBoundingBox3d bb;
  int count = 0;
  std::list<GFace*>::const_iterator it = _compound.begin();

  for( ; it != _compound.end() ; ++it){
    for(unsigned int i = 0; i < (*it)->triangles.size(); ++i){
      MTriangle *t = (*it)->triangles[i];
      for(int j = 0; j < 3; j++){
        std::map<MVertex*,SPoint3>::const_iterator itj = coordinates.find(t->getVertex(j));
        _coordPoints.insert(std::make_pair(t->getVertex(j)->point(), itj->second));
        bb += SPoint3(itj->second.x(),itj->second.y(),0.0);
      }
      count++;
    }
  }

  // make bounding box larger up to (absolute) geometrical tolerance
  double eps = 0.0; //CTX::instance()->geom.tolerance;
  SPoint3 bbmin = bb.min(), bbmax = bb.max(), bbeps(eps, eps, eps);
  bbmin -= bbeps;
  bbmax += bbeps;
  double origin[3] = {bbmin.x(), bbmin.y(), bbmin.z()};
  double ssize[3] = {bbmax.x() - bbmin.x(),
                     bbmax.y() - bbmin.y(),
                     bbmax.z() - bbmin.z()};

  _gfct = new GFaceCompoundTriangle[count];
  const int maxElePerBucket = 15;
  oct = Octree_Create(maxElePerBucket, origin, ssize, GFaceCompoundBB,
                      GFaceCompoundCentroid, GFaceCompoundInEle);

  it = _compound.begin();
  count = 0;

  for( ; it != _compound.end() ; ++it){
    for(unsigned int i = 0; i < (*it)->triangles.size(); ++i){
      MTriangle *t = (*it)->triangles[i];
      std::map<MVertex*,SPoint3>::const_iterator it0 =
        coordinates.find(t->getVertex(0));
      std::map<MVertex*,SPoint3>::const_iterator it1 =
        coordinates.find(t->getVertex(1));
      std::map<MVertex*,SPoint3>::const_iterator it2 =
        coordinates.find(t->getVertex(2));
      _gfct[count].p1 = it0->second;
      _gfct[count].p2 = it1->second;
      _gfct[count].p3 = it2->second;
      if((*it)->geomType() != GEntity::DiscreteSurface){
	// take care of the seam !!!!
	if (t->getVertex(0)->onWhat()->dim() == 2){
	  reparamMeshEdgeOnFace(t->getVertex(0), t->getVertex(1), *it,
                                _gfct[count].gfp1, _gfct[count].gfp2);
	  reparamMeshEdgeOnFace(t->getVertex(0), t->getVertex(2), *it,
                                _gfct[count].gfp1, _gfct[count].gfp3);
	}
	else if (t->getVertex(1)->onWhat()->dim() == 2){
	  reparamMeshEdgeOnFace(t->getVertex(1), t->getVertex(0), *it,
                                _gfct[count].gfp2, _gfct[count].gfp1);
	  reparamMeshEdgeOnFace(t->getVertex(1), t->getVertex(2), *it,
                                _gfct[count].gfp2, _gfct[count].gfp3);
	}
	else if (t->getVertex(2)->onWhat()->dim() == 2){
	  reparamMeshEdgeOnFace(t->getVertex(2), t->getVertex(0), *it,
                                _gfct[count].gfp3, _gfct[count].gfp1);
	  reparamMeshEdgeOnFace(t->getVertex(2), t->getVertex(1), *it,
                                _gfct[count].gfp3, _gfct[count].gfp2);
	}
	else {
	  reparamMeshVertexOnFace(t->getVertex(0), *it, _gfct[count].gfp1);
	  reparamMeshVertexOnFace(t->getVertex(1), *it, _gfct[count].gfp2);
	  reparamMeshVertexOnFace(t->getVertex(2), *it, _gfct[count].gfp3);
	}
      }
      _gfct[count].v1 = SPoint3(t->getVertex(0)->x(), t->getVertex(0)->y(),
                                t->getVertex(0)->z());
      _gfct[count].v2 = SPoint3(t->getVertex(1)->x(), t->getVertex(1)->y(),
                                t->getVertex(1)->z());
      _gfct[count].v3 = SPoint3(t->getVertex(2)->x(), t->getVertex(2)->y(),
                                t->getVertex(2)->z());
      _gfct[count].gf = *it;
      _gfct[count].tri = t;
      Octree_Insert(&_gfct[count], oct);
      count++;
    }
  }
  nbT = count;
  Octree_Arrange(oct);

  printStuff();
}

bool GFaceCompound::checkTopology() const
{
  if (_mapping == RBF) return true;

  bool correctTopo = true;
  if(allNodes.empty()) buildAllNodes();

  int Nb = _interior_loops.size();
  int G  = genusGeom() ;

  double H = getSizeH();
  double D = H;
  if (_interior_loops.size() > 0)    D =  getSizeBB(_U0);
  int AR1 = (int) checkAspectRatio();
  int AR2 = (int) floor(H/D+0.5);
  int AR = std::max(AR1, AR2);

  if (G != 0 || Nb < 1){
    correctTopo = false;
    nbSplit = std::max(G+2, 2);
    Msg::Warning("Wrong topology: Genus=%d, Nb boundaries=%d, AR=%g", G, Nb, H/D);
    if (_allowPartition){
      Msg::Info("-----------------------------------------------------------");
      Msg::Info("--- Split surface %d in %d parts with Multilevel Mesh partitioner",
                tag(), nbSplit);
    }
    else{
      Msg::Fatal("For remeshing your geometry, you should enable the automatic "
                 "remeshing algorithm. Add 'Mesh.RemeshAlgorithm=1;' in your "
                 "geo file or through the Fltk window (Options > Mesh > General)");
    }
  }
  else if (G == 0 && AR > AR_MAX){
    correctTopo = false;
    Msg::Warning("Wrong topology: Aspect ratio is too high AR=%d (AR1=%d AR2=%d)", AR, AR1, AR2);
    if (_allowPartition == 1){
      nbSplit = -2;
      Msg::Info("-----------------------------------------------------------");
      Msg::Info("--- Split surface %d in 2 parts with Laplacian Mesh partitioner",
                tag());
    }
    else if (_allowPartition == 2){
      nbSplit = 2;
      Msg::Info("-----------------------------------------------------------");
      Msg::Info("--- Split surface %d in %d parts with Multilevel Mesh partitioner",
                tag(), nbSplit);
    }
    else if (_allowPartition == 0){
      Msg::Debug("The geometrical aspect ratio of your geometry is quite high.\n "
		 "You should enable partitioning of the mesh by activating the\n"
		 "automatic remeshing algorithm. Add 'Mesh.RemeshAlgorithm=1;'\n "
		 "in your geo file or through the Fltk window (Options > Mesh >\n "
		 "General)");
    }
  }
  else{
    Msg::Debug("Correct topology: Genus=%d and Nb boundaries=%d, AR=%g", G, Nb, H/D);
  }

  return correctTopo;
}

double GFaceCompound::checkAspectRatio() const
{

  if(allNodes.empty()) buildAllNodes();

  double limit =  1.e-20;
  double areaMin = 1.e20;
  double area3D = 0.0;
  int nb = 0;
  std::list<GFace*>::const_iterator it = _compound.begin();
  for( ; it != _compound.end() ; ++it){
    for(unsigned int i = 0; i < (*it)->triangles.size(); ++i){
      MTriangle *t = (*it)->triangles[i];
      std::vector<MVertex *> v(3);
      for(int k = 0; k < 3; k++){
        v[k] = t->getVertex(k);
      }
      std::map<MVertex*,SPoint3>::const_iterator it0 = coordinates.find(v[0]);
      std::map<MVertex*,SPoint3>::const_iterator it1 = coordinates.find(v[1]);
      std::map<MVertex*,SPoint3>::const_iterator it2 = coordinates.find(v[2]);
      double p0[3] = {v[0]->x(), v[0]->y(), v[0]->z()};
      double p1[3] = {v[1]->x(), v[1]->y(), v[1]->z()};
      double p2[3] = {v[2]->x(), v[2]->y(), v[2]->z()};
      double a_3D = fabs(triangle_area(p0, p1, p2));
      area3D += a_3D;
      double q0[3] = {it0->second.x(), it0->second.y(), 0.0};
      double q1[3] = {it1->second.x(), it1->second.y(), 0.0};
      double q2[3] = {it2->second.x(), it2->second.y(), 0.0};
      double a_2D = fabs(triangle_area(q0, q1, q2));
      if (a_2D > limit) nb++;
      areaMin = std::min(areaMin,a_2D);
    }
  }

  std::list<GEdge*>::const_iterator it0 = _U0.begin();
  double tot_length = 0.0;
  for( ; it0 != _U0.end(); ++it0 )
    for(unsigned int i = 0; i < (*it0)->lines.size(); i++ )
      tot_length += (*it0)->lines[i]->getLength();

  double AR = M_PI*area3D/(tot_length*tot_length);

  if (areaMin > 0 && areaMin < limit && nb > 3) {
    Msg::Warning("Too small triangles in mapping (a_2D=%g)", areaMin);
  }
  else {
    Msg::Debug("Geometrical aspect ratio is OK  :-)");
  }

  return AR;
}

void GFaceCompound::coherencePatches() const
{
  if (_mapping == RBF) return;
  Msg::Info("Re-orient all %d compound patches normals coherently",
            _compound.size());

  std::map<MEdge, std::set<MElement*>, Less_Edge > edge2elems;
  std::vector<MElement*> allElems;
  std::list<GFace*>::const_iterator it = _compound.begin();
  for( ; it != _compound.end() ; ++it){
    for(unsigned int i = 0; i < (*it)->getNumMeshElements(); ++i){
      MElement *t =  (*it)->getMeshElement(i);
      allElems.push_back(t);
      for (int j = 0; j <  t->getNumEdges(); j++){
	MEdge me = t->getEdge(j);
	std::map<MEdge, std::set<MElement*, std::less<MElement*> >,
		 Less_Edge >::iterator it = edge2elems.find(me);
	if (it == edge2elems.end()) {
	  std::set<MElement*, std::less<MElement*> > mySet;
	  mySet.insert(t);
	  edge2elems.insert(std::make_pair(me, mySet));
	}
	else{
	  std::set<MElement*, std::less<MElement*> > mySet = it->second;
	  mySet.insert(t);
	  it->second = mySet;
	}
    }
  }
}

  std::set<MElement* , std::less<MElement*> > touched;
  int iE, si, iE2, si2;
  touched.insert(allElems[0]);
  while(touched.size() != allElems.size()){
    for(unsigned int i = 0; i < allElems.size(); i++){
      MElement *t = allElems[i];
      std::set<MElement*, std::less<MElement*> >::iterator it2 = touched.find(t);
      if(it2 != touched.end()){
	for (int j = 0; j <  t->getNumEdges(); j++){
	  MEdge me = t->getEdge(j);
	  t->getEdgeInfo(me, iE,si);
	  std::map<MEdge, std::set<MElement*>, Less_Edge >::iterator it =
	    edge2elems.find(me);
	  std::set<MElement*, std::less<MElement*> > mySet = it->second;
	  for(std::set<MElement*, std::less<MElement*> >::iterator itt = mySet.begin();
	      itt != mySet.end(); itt++){
	    if (*itt != t){
	      (*itt)->getEdgeInfo(me,iE2,si2);
	      if(si == si2) { (*itt)->revert();}
	      touched.insert(*itt);
	    }
	  }
	}
      }
    }
  }
}

void GFaceCompound::coherenceNormals()
{
  Msg::Info("Re-orient all %d face normals coherently", getNumMeshElements());

  std::map<MEdge, std::set<MElement*>, Less_Edge > edge2elems;
  for(unsigned int i = 0; i <  getNumMeshElements(); i++){
    MElement *t =  getMeshElement(i);
    for (int j = 0; j <  t->getNumEdges(); j++){
      MEdge me = t->getEdge(j);
      std::map<MEdge, std::set<MElement*, std::less<MElement*> >,
        Less_Edge >::iterator it = edge2elems.find(me);
      if (it == edge2elems.end()) {
        std::set<MElement*, std::less<MElement*> > mySet;
        mySet.insert(t);
        edge2elems.insert(std::make_pair(me, mySet));
      }
      else{
        std::set<MElement*, std::less<MElement*> > mySet = it->second;
        mySet.insert(t);
        it->second = mySet;
      }
    }
  }

  std::set<MElement* , std::less<MElement*> > touched;
  int iE, si, iE2, si2;
  touched.insert(getMeshElement(0));
  while(touched.size() != getNumMeshElements()){
    for(unsigned int i = 0; i < getNumMeshElements(); i++){
      MElement *t = getMeshElement(i);
      std::set<MElement*, std::less<MElement*> >::iterator it2 = touched.find(t);
      if(it2 != touched.end()){
        for (int j = 0; j <  t->getNumEdges(); j++){
          MEdge me = t->getEdge(j);
          t->getEdgeInfo(me, iE,si);
          std::map<MEdge, std::set<MElement*>, Less_Edge >::iterator it =
            edge2elems.find(me);
          std::set<MElement*, std::less<MElement*> > mySet = it->second;
          for(std::set<MElement*, std::less<MElement*> >::iterator itt = mySet.begin();
              itt != mySet.end(); itt++){
            if (*itt != t){
              (*itt)->getEdgeInfo(me,iE2,si2);
              if(si == si2)  (*itt)->revert();
              touched.insert(*itt);
            }
          }
        }
      }
    }
  }
}

void GFaceCompound::buildAllNodes() const
{
  std::list<GFace*>::const_iterator it = _compound.begin();
  for( ; it != _compound.end() ; ++it){
    for(unsigned int i = 0; i < (*it)->triangles.size(); ++i){
      MTriangle *t = (*it)->triangles[i];
      for(int j = 0; j < 3; j++){
        allNodes.insert(t->getVertex(j));
      }
    }
  }
}

int GFaceCompound::genusGeom() const
{
  std::list<GFace*>::const_iterator it = _compound.begin();
  std::set<MEdge, Less_Edge> es;
  std::set<MVertex*> vs;
  int N = 0;
  for( ; it != _compound.end() ; ++it){
    for(unsigned int i = 0; i < (*it)->triangles.size(); ++i){
      N++;
      MTriangle *e = (*it)->triangles[i];
      for(int j = 0; j < e->getNumVertices(); j++){
	vs.insert(e->getVertex(j));
      }
      for(int j = 0; j < e->getNumEdges(); j++){
	es.insert(e->getEdge(j));
      }
    }
  }
  int poincare = vs.size() - es.size() + N;

  return (int)(-poincare + 2 - _interior_loops.size())/2;
}

void GFaceCompound::printStuff(int iNewton) const
{
  if(!CTX::instance()->mesh.saveAll) return;

  std::list<GFace*>::const_iterator it = _compound.begin();

  char name0[256], name1[256], name2[256], name3[256];
  char name4[256], name5[256], name6[256];
  char name7[256];
  sprintf(name0, "UVAREA-%d.pos", tag()); //(*it)->tag()
  sprintf(name1, "UVX-%d_%d.pos", tag(), iNewton);
  sprintf(name2, "UVY-%d_%d.pos", tag(), iNewton);
  sprintf(name3, "UVZ-%d_%d.pos", tag(), iNewton);
  sprintf(name4, "XYZU-%d_%d.pos", tag(), iNewton);
  sprintf(name5, "XYZV-%d_%d.pos", tag(), iNewton);
  sprintf(name6, "XYZC-%d.pos", tag());

  sprintf(name7, "UVM-%d.pos", (*it)->tag());

  //FILE * uva = fopen(name0,"w");
  FILE * uvx = fopen(name1,"w");
  FILE * uvy = fopen(name2,"w");
  FILE * uvz = fopen(name3,"w");
  FILE * xyzu = fopen(name4,"w");
  FILE * xyzv = fopen(name5,"w");
  //FILE * xyzc = fopen(name6,"w");
  //FILE * uvm = fopen(name7,"w");

  //fprintf(uva, "View \"\"{\n");
  fprintf(uvx, "View \"\"{\n");
  fprintf(uvy, "View \"\"{\n");
  fprintf(uvz, "View \"\"{\n");
  fprintf(xyzu, "View \"\"{\n");
  fprintf(xyzv, "View \"\"{\n");
  //fprintf(xyzc, "View \"\"{\n");
  //fprintf(uvm, "View \"\"{\n");

  for( ; it != _compound.end() ; ++it){
    for(unsigned int i = 0; i < (*it)->triangles.size(); ++i){
      MTriangle *t = (*it)->triangles[i];
      std::map<MVertex*,SPoint3>::const_iterator it0 =
        coordinates.find(t->getVertex(0));
      std::map<MVertex*,SPoint3>::const_iterator it1 =
        coordinates.find(t->getVertex(1));
      std::map<MVertex*,SPoint3>::const_iterator it2 =
        coordinates.find(t->getVertex(2));
      fprintf(xyzv, "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
              t->getVertex(0)->x(), t->getVertex(0)->y(), t->getVertex(0)->z(),
              t->getVertex(1)->x(), t->getVertex(1)->y(), t->getVertex(1)->z(),
              t->getVertex(2)->x(), t->getVertex(2)->y(), t->getVertex(2)->z(),
              it0->second.y(),it1->second.y(),it2->second.y());
      fprintf(xyzu, "ST(%22.15E,%22.15E,%22.15E,%22.15E,%22.15E,%22.15E,%22.15E,"
              "%22.15E,%22.15E){%22.15E,%22.15E,%22.15E};\n",
              t->getVertex(0)->x(), t->getVertex(0)->y(), t->getVertex(0)->z(),
              t->getVertex(1)->x(), t->getVertex(1)->y(), t->getVertex(1)->z(),
              t->getVertex(2)->x(), t->getVertex(2)->y(), t->getVertex(2)->z(),
              it0->second.x(),it1->second.x(),it2->second.x());
      // double K1 = locCurvature(t,it0->second.x(),it0->second.y());
      // double K2 = locCurvature(t,it1->second.x(),it1->second.y());
      // double K3 = locCurvature(t,it2->second.x(),it2->second.y());
      // fprintf(xyzc,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
      //         t->getVertex(0)->x(), t->getVertex(0)->y(), t->getVertex(0)->z(),
      //         t->getVertex(1)->x(), t->getVertex(1)->y(), t->getVertex(1)->z(),
      //         t->getVertex(2)->x(), t->getVertex(2)->y(), t->getVertex(2)->z(),
      //         K1, K2, K3);

      // double p0[3] = {t->getVertex(0)->x(), t->getVertex(0)->y(), t->getVertex(0)->z()};
      // double p1[3] = {t->getVertex(1)->x(), t->getVertex(1)->y(), t->getVertex(1)->z()};
      // double p2[3] = {t->getVertex(2)->x(), t->getVertex(2)->y(), t->getVertex(2)->z()};
      // double a_3D = fabs(triangle_area(p0, p1, p2));
      // double q0[3] = {it0->second.x(), it0->second.y(), 0.0};
      // double q1[3] = {it1->second.x(), it1->second.y(), 0.0};
      // double q2[3] = {it2->second.x(), it2->second.y(), 0.0};
      // double a_2D = fabs(triangle_area(q0, q1, q2));
      // double area = (a_3D/a_2D); //*(a_3D/a_2D);
      // Pair<SVector3, SVector3> der = this->firstDer(SPoint2(it0->second.x(),
      //                                                       it0->second.y()));
      // double metric0e = dot(der.first(), der.first());
      // double metric0f = dot(der.second()*(1./norm(der.second())),
      //                       der.first()*(1./norm(der.first())));
      // double metric0g = dot(der.second(), der.second());
      // Pair<SVector3, SVector3> der1 = this->firstDer(SPoint2(it1->second.x(),
      //                                                        it1->second.y()));
      // double metric1e = dot(der1.first(), der1.first());
      // double metric1f = dot(der1.second()*(1/norm(der1.second())),
      //                       der1.first()*(1./norm(der1.first())));
      // double metric1g = dot(der1.second(), der1.second());
      // Pair<SVector3, SVector3> der2 = this->firstDer(SPoint2(it2->second.x(),
      //                                                        it2->second.y()));
      // double metric2e = dot(der2.first(),  der2.first());
      // double metric2f = dot(der2.second()*(1./norm(der2.second())),
      //                       der2.first()*(1./norm(der2.first())));
      // double metric2g = dot(der2.second(), der2.second());

      // double mat0[2][2], eig0[2];
      // double mat1[2][2], eig1[2];
      // double mat2[2][2], eig2[2];
      // mat0[0][0]  = metric0e;  mat0[0][1]  =  metric0f;
      // mat0[1][0]  =  metric0f;  mat0[1][1]  =  metric0g;
      // eigenvalue2x2(mat0, eig0);
      // mat1[0][0]  = metric1e;  mat1[0][1]  = metric1f;
      // mat1[1][0]  = metric1f;  mat1[1][1]  = metric1g;
      // eigenvalue2x2(mat1, eig1);
      // mat2[0][0]  = metric2e;  mat2[0][1]  = metric2f;
      // mat2[1][0]  = metric2f;  mat2[1][1]  = metric2g;
      // eigenvalue2x2(mat2, eig2);

      // double disp0 = sqrt(.5*(eig0[0]*eig0[0]+ (eig0[1]*eig0[1])));
      // double disp1 = sqrt(.5*(eig1[0]*eig1[0]+ (eig1[1]*eig1[1])));
      // double disp2 = sqrt(.5*(eig2[0]*eig2[0]+ (eig2[1]*eig2[1])));
      // double mdisp = .333*(disp0+disp1+disp2);
      // fprintf(uva, "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
      //         it0->second.x(), it0->second.y(), 0.0,
      //         it1->second.x(), it1->second.y(), 0.0,
      //         it2->second.x(), it2->second.y(), 0.0,
      //         area, area, area);

      // fprintf(uvm, "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
      //         it0->second.x(), it0->second.y(), 0.0,
      //         it1->second.x(), it1->second.y(), 0.0,
      //         it2->second.x(), it2->second.y(), 0.0,
      // 	      mdisp, mdisp, mdisp);

      fprintf(uvx, "ST(%22.15E,%22.15E,%22.15E,%22.15E,%22.15E,%22.15E,%22.15E,"
              "%22.15E,%22.15E){%22.15E,%22.15E,%22.15E};\n",
              it0->second.x(), it0->second.y(), 0.0,
              it1->second.x(), it1->second.y(), 0.0,
              it2->second.x(), it2->second.y(), 0.0,
              t->getVertex(0)->x(), t->getVertex(1)->x(), t->getVertex(2)->x());
      fprintf(uvy, "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
              it0->second.x(), it0->second.y(), 0.0,
              it1->second.x(), it1->second.y(), 0.0,
              it2->second.x(), it2->second.y(), 0.0,
              t->getVertex(0)->y(), t->getVertex(1)->y(), t->getVertex(2)->y());
      fprintf(uvz, "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
              it0->second.x(), it0->second.y(), 0.0,
              it1->second.x(), it1->second.y(), 0.0,
              it2->second.x(), it2->second.y(), 0.0,
              t->getVertex(0)->z(), t->getVertex(1)->z(), t->getVertex(2)->z());
    }
  }
  // fprintf(uva,"};\n");
  // fclose(uva);
  fprintf(uvx,"};\n");
  fclose(uvx);
  fprintf(uvy,"};\n");
  fclose(uvy);
  fprintf(uvz,"};\n");
  fclose(uvz);
  fprintf(xyzu,"};\n");
  fclose(xyzu);
  fprintf(xyzv,"};\n");
  fclose(xyzv);
  // fprintf(xyzc,"};\n");
  // fclose(xyzc);
  // fprintf(uvm,"};\n");
  // fclose(uvm);
}

// useful for mesh generators ----------------------------------------
// Intersection of a circle and a plane
GPoint GFaceCompound::intersectionWithCircle(const SVector3 &n1, const SVector3 &n2,
                                             const SVector3 &p, const double &d,
                                             double uv[2]) const
{
  SVector3 n = crossprod(n1,n2);
  n.normalize();
  for (int i=-1;i<nbT;i++){
    GFaceCompoundTriangle *ct;
    double U,V;
    if (i == -1) getTriangle(uv[0],uv[1], &ct, U,V);
    else ct = &_gfct[i];
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
    // a (p_x + t n1_x) + a (p_y + t n1_y) + c (p_z + t n1_z) - (v1_x a + v1_y b + v1_z * c) = 0
    // gives t

    SVector3 w = crossprod(t1,t2);
    double t = dot(ct->v1-p,w)/dot(n1,w);
    SVector3 q = p + n1*t;

    // consider the line that intersects both planes in its
    // parametric form
    // X(x,y,z) = q + t m
    // We have now to intersect that line with the sphere
    // (x-p_x)^2 + (y-p_y)^2 + (z-p_z)^2 = d^2
    // Inserting the parametric form of the line into the sphere gives
    // (t m_x + q_x - p_x)^2 + (t m_y + q_y - p_y)^2  + (t m_z + q_z - p_z)^2  = d^2
    //  t^2 (m_x^2 + m_y^2 + m_z^2) + 2 t (m_x (q_x - p_x) + m_y (q_y - p_z) + m_z (q_z - p_z)) + ((q_x - p_x)^2 + (q_y - p_y)^2 + (q_z - p_z)^2 - d^2) = 0
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
	//	GPoint ttt = point(pp.x(),pp.y());
	//	printf("%g %g %g vs %g %g %g\n",ttt.x(),ttt.y(),ttt.z(),s.x(),s.y(),s.z());
	//	printf("%d/%d\n",i,nbT);
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
