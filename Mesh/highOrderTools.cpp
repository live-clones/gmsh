// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Koen Hillewaert
//

#include "GmshConfig.h"

#if defined(HAVE_SOLVER)

#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "MPoint.h"
#include "HighOrder.h"
#include "meshGFaceOptimize.h"
#include "highOrderTools.h"
#include "GFace.h"
#include "GRegion.h"
#include "GeomMeshMatcher.h"
#include "Context.h"
#include "Numeric.h"
#include "dofManager.h"
#include "elasticityTerm.h"
#include "linearSystemCSR.h"
#include "linearSystemFull.h"
#include "linearSystemPETSc.h"
#include "OS.h"

#define SQU(a)      ((a)*(a))

void highOrderTools::moveToStraightSidedLocation(MElement *e) const
{
  for(int i = 0; i < e->getNumVertices(); i++){
    MVertex *v = e->getVertex(i);
    std::map<MVertex*,SVector3>::const_iterator it = _straightSidedLocation.find(v);
    if (it != _straightSidedLocation.end()){
      //      printf("move %d : %g %g -> %g %g\n",v->getNum(),v->x() ,v->y() ,  it->second.x() ,  it->second.y() );
      v->x() = it->second.x();
      v->y() = it->second.y();
      v->z() = it->second.z();
    }
  }
}


void highOrderTools::ensureMinimumDistorsion(MElement *e, double threshold)
{
  double dist = e->distoShapeMeasure();
  if (dist > threshold) return;
  double a1 = 0., a2 = 1.0, x[1000][3], X[1000][3] ;
  for(int i = 0; i < e->getNumVertices(); i++){
    MVertex *v = e->getVertex(i);
    x[i][0] = v->x();
    x[i][1] = v->y();
    x[i][2] = v->z();
    std::map<MVertex*,SVector3>::const_iterator it = _straightSidedLocation.find(v);
    if (it != _straightSidedLocation.end()){
      X[i][0] = it->second.x();
      X[i][1] = it->second.y();
      X[i][2] = it->second.z();
    }
    else {
      X[i][0] = v->x();
      X[i][1] = v->y();
      X[i][2] = v->z();
    }
  }
  // a == 0 -> straight
  // a == 1 -> curved
  int ITER = 1;
  while(1){
    double a = 0.5*(a1+a2);
    if (ITER > 10) a = 0.;
    for(int i = 0; i < e->getNumVertices(); i++){
      MVertex *v = e->getVertex(i);
      v->x() = a * x[i][0] + (1.-a) * X[i][0];
      v->y() = a * x[i][1] + (1.-a) * X[i][1];
      v->z() = a * x[i][2] + (1.-a) * X[i][2];
    }
    double dist = e->distoShapeMeasure();
    //    printf("a = %g dist = %g\n",a,dist);
    //    getchar();
    if (dist > 0 && fabs(dist-threshold) < .05)break;
    if (dist < threshold)a2 = a;
    else a1 = a;
    if (a > .99 || a < .01) break;
    ++ITER;
  }
  //  printf("element done\n");
}


static void getDistordedElements(const std::vector<MElement*> &v,
				 const double & threshold,
				 std::vector<MElement*> &d,
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

static void addOneLayer(const std::vector<MElement*> &v,
                        std::vector<MElement*> &d,
                        std::vector<MElement*> &layer)
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


double highOrderTools::applySmoothingTo(GFace *gf, double tres, bool mixed)
{
  if (!gf){
    Msg::Error("Cannot smooth that face");
    return -1;
  }
  std::vector<MElement*> v;
  v.insert(v.begin(), gf->triangles.begin(),gf->triangles.end());
  v.insert(v.begin(), gf->quadrangles.begin(),gf->quadrangles.end());
  //  applySmoothingTo(v,gf);
  return applySmoothingTo(v,tres, mixed);
}


void highOrderTools::ensureMinimumDistorsion (double threshold)
{
  std::vector<MElement*> v;
  if (_dim == 2){
    for (GModel::fiter fit = _gm->firstFace(); fit != _gm->lastFace(); ++fit) {
      v.insert(v.begin(), (*fit)->triangles.begin(),(*fit)->triangles.end());
      v.insert(v.begin(), (*fit)->quadrangles.begin(),(*fit)->quadrangles.end());
    }
  }
  else if (_dim == 3){
    for (GModel::riter rit = _gm->firstRegion(); rit != _gm->lastRegion(); ++rit) {
      v.insert(v.begin(), (*rit)->hexahedra.begin(),(*rit)->hexahedra.end());
      v.insert(v.begin(), (*rit)->tetrahedra.begin(),(*rit)->tetrahedra.end());
      v.insert(v.begin(), (*rit)->prisms.begin(),(*rit)->prisms.end());
    }
  }
  ensureMinimumDistorsion(v,threshold);
}


/*
   void highOrderTools::applySmoothingTo(GRegion *gr)
   {
   std::vector<MElement*> v;
   v.insert(v.begin(), gr->tetrahedra.begin(),gr->tetrahedra.end());
   v.insert(v.begin(), gr->hexahedra.begin(),gr->hexahedra.end());
   v.insert(v.begin(), gr->prisms.begin(),gr->prisms.end());
   Msg::Info("Smoothing high order mesh : model region %d (%d elements)", gr->tag(),
   v.size());
   applySmoothingTo(v,gr);
   }
   */

void highOrderTools::computeMetricInfo(GFace *gf,
    MElement *e,
    fullMatrix<double> &J,
    fullMatrix<double> &JT,
    fullVector<double> &D)
{
  int nbNodes = e->getNumVertices();
  //  printf("ELEMENT --\n");
  for (int j = 0; j < nbNodes; j++){
    SPoint2 param;
    bool success = reparamMeshVertexOnFace(e->getVertex(j), gf, param);
    //    printf("%g %g vs %g %g %g\n",param.x(),param.y(),
    //	   e->getVertex(j)->x(),e->getVertex(j)->y(),e->getVertex(j)->z());

    Pair<SVector3,SVector3> der = gf->firstDer(param);    

    int XJ = j;
    int YJ = j + nbNodes;
    int ZJ = j + 2 * nbNodes;
    int UJ = j;
    int VJ = j + nbNodes;
    J(XJ,UJ) = der.first().x();
    J(YJ,UJ) = der.first().y();
    J(ZJ,UJ) = der.first().z();
    J(XJ,VJ) = der.second().x();
    J(YJ,VJ) = der.second().y();
    J(ZJ,VJ) = der.second().z();

    JT(UJ,XJ) = der.first().x();
    JT(UJ,YJ) = der.first().y();
    JT(UJ,ZJ) = der.first().z();
    JT(VJ,XJ) = der.second().x();
    JT(VJ,YJ) = der.second().y();
    JT(VJ,ZJ) = der.second().z();

    SVector3 ss = getSSL(e->getVertex(j));
    GPoint gp = gf->point(param);      
    D(XJ) = (gp.x() - ss.x());
    D(YJ) = (gp.y() - ss.y());
    D(ZJ) = (gp.z() - ss.z());
    /*
    printf("point %d on %d %d dx = %g %g %g --> %g %g %g --> %g %g %g \n",e->getVertex(j)->getIndex(),
	   e->getVertex(j)->onWhat()->dim(),e->getVertex(j)->onWhat()->tag(),
	   D(XJ),D(YJ),D(ZJ),
	   ss.x(),ss.y(),ss.z(),
	   e->getVertex(j)->x(),e->getVertex(j)->y(),e->getVertex(j)->z());
    */
    
  }
}

void highOrderTools::applySmoothingTo(std::vector<MElement*> & all, GFace *gf)
{
#ifdef HAVE_TAUCS
  linearSystemCSRTaucs<double> *lsys = new linearSystemCSRTaucs<double>;
#else
  linearSystemPETSc<double> *lsys = new  linearSystemPETSc<double>;
#endif
  // compute the straight sided positions of high order nodes that are
  // on the edges of the face in the UV plane
  dofManager<double> myAssembler(lsys);
  elasticityTerm El(0, 1.0, .33, _tag);
  std::vector<MElement*> layer, v;
  double minD;
  getDistordedElements(all, CTX::instance()->mesh.smoothDistoTreshold, v, minD);
  int numBad = v.size();
  const int nbLayers = CTX::instance()->mesh.smoothNLayers;
  for (int i = 0; i < nbLayers; i++){
    addOneLayer(all, v, layer);
    v.insert(v.end(), layer.begin(), layer.end());
  }

  if (!v.size()) return;
  Msg::Info("Smoothing high order mesh : model face %d (%d elements considered in the elastic analogy, worst mapping %12.5E, %3d bad elements)", gf->tag(),
            v.size(),minD,numBad);

  addOneLayer(all, v, layer);
  std::set<MVertex*>::iterator it;
  std::set<MVertex*> verticesToMove;

  // on the last layer, fix displacement to 0
  for (unsigned int i = 0; i < layer.size(); i++){
    for (int j = 0; j < layer[i]->getNumVertices(); j++){
      MVertex *vert = layer[i]->getVertex(j);
      myAssembler.fixVertex(vert, 0, _tag, 0);
      myAssembler.fixVertex(vert, 1, _tag, 0);
    }
  }

  // fix all vertices that cannot move
  for (unsigned int i = 0; i < v.size(); i++){
    moveToStraightSidedLocation(v[i]);
    for (int j = 0; j < v[i]->getNumVertices(); j++){
      MVertex *vert = v[i]->getVertex(j);
      if (vert->onWhat()->dim() < 2){
	double du = 0, dv = 0;
        myAssembler.fixVertex(vert, 0, _tag, du);
        myAssembler.fixVertex(vert, 1, _tag, dv);
      }
    }
  }

  // number the other DOFs
  for (unsigned int i = 0; i < v.size(); i++){
    for (int j = 0; j < v[i]->getNumVertices(); j++){
      MVertex *vert = v[i]->getVertex(j);
      myAssembler.numberVertex(vert, 0, _tag);
      myAssembler.numberVertex(vert, 1, _tag);
      verticesToMove.insert(vert);
    }
  }

  double dx0 = smooth_metric_(v, gf, myAssembler, verticesToMove, El);
  double dx = dx0;
  Msg::Debug(" dx0 = %12.5E", dx0);
  int iter = 0;
  while(1){
    double dx2 = smooth_metric_(v, gf, myAssembler, verticesToMove, El);
    Msg::Debug(" dx2  = %12.5E", dx2);
    if (fabs(dx2 - dx) < 1.e-4 * dx0)break;
    if (iter++ > 2)break;
    dx = dx2;
  }

  for (it = verticesToMove.begin(); it != verticesToMove.end(); ++it){
    SPoint2 param;
    if ((*it)->onWhat()->dim() == 2){
      reparamMeshVertexOnFace(*it, gf, param);
      GPoint gp = gf->point(param);
      (*it)->x() = gp.x();
      (*it)->y() = gp.y();
      (*it)->z() = gp.z();
      _targetLocation[*it] = SVector3(gp.x(), gp.y(), gp.z());
    }
    else{
      SVector3 p =  getTL(*it);
      //      printf("%12.5E %12.5E %12.5E %d %d\n",p.x(),p.y(),p.z(),(*it)->onWhat()->dim(),(*it)->onWhat()->tag());
      (*it)->x() = p.x();
      (*it)->y() = p.y();
      (*it)->z() = p.z();
    }
  }
  delete lsys;
}

double highOrderTools::smooth_metric_(std::vector<MElement*>  & v,
    GFace *gf,
    dofManager<double> &myAssembler,
    std::set<MVertex*> &verticesToMove,
    elasticityTerm &El)
{
  std::set<MVertex*>::iterator it;
  double dx = 0.0;

  //  printf("size %d\n",myAssembler.sizeOfR());

  if (myAssembler.sizeOfR()){

    // while convergence -------------------------------------------------------
    for (unsigned int i = 0; i < v.size(); i++){
      MElement *e = v[i];
      int nbNodes = e->getNumVertices();
      const int n2 = 2 * nbNodes;
      const int n3 = 3 * nbNodes;

      fullMatrix<double> K33(n3, n3);
      fullMatrix<double> K22(n2, n2);
      fullMatrix<double> J32(n3, n2);
      fullMatrix<double> J23(n2, n3);
      fullVector<double> D3(n3);
      fullVector<double> R2(n2);
      fullMatrix<double> J23K33(n2, n3);
      K33.setAll(0.0);
      SElement se(e);
      El.elementMatrix(&se, K33);
      computeMetricInfo(gf, e, J32, J23, D3);
      J23K33.gemm(J23, K33, 1, 0);
      K22.gemm(J23K33, J32, 1, 0);
      //      K33.print("K33");
      //      K22.print("K22");
      J23K33.mult(D3, R2);
      //      R2.print("hopla");
      for (int j = 0; j < n2; j++){
        Dof RDOF = El.getLocalDofR(&se, j);
        myAssembler.assemble(RDOF, -R2(j));
        for (int k = 0; k < n2; k++){
          Dof CDOF = El.getLocalDofC(&se, k);
          myAssembler.assemble(RDOF, CDOF, K22(j, k));
        }
      }
    }
    myAssembler.systemSolve();
    // for all element, compute detJ at integration points --> material law
    // end while convergence -------------------------------------------------------

    for (it = verticesToMove.begin(); it != verticesToMove.end(); ++it){
      if ((*it)->onWhat()->dim() == 2){
	SPoint2 param;
	reparamMeshVertexOnFace((*it), gf, param);
	SPoint2 dparam;
	myAssembler.getDofValue((*it), 0, _tag, dparam[0]);
	myAssembler.getDofValue((*it), 1, _tag, dparam[1]);
	//      printf("%g %g -- %g %g\n",dparam[0],dparam[1],param[0],param[1]);
	SPoint2 newp = param+dparam;
	dx += newp.x() * newp.x() + newp.y() * newp.y();
	(*it)->setParameter(0, newp.x());
	(*it)->setParameter(1, newp.y());
      }
    }
    myAssembler.systemClear();
  }

  return dx;
}


highOrderTools::highOrderTools (GModel *gm) : _gm(gm), _dim(2), _tag(111)
{
  computeStraightSidedPositions();
}

highOrderTools::highOrderTools (GModel *gm, GModel *mesh, int order) : _gm(gm), _dim(2), _tag(111)
{
  GeomMeshMatcher::instance()->forceTomatch(gm,mesh,1.e-5);
  GeomMeshMatcher::instance()->destroy();
  SetOrderN(gm, order, false, false);
  computeStraightSidedPositions();
}

void highOrderTools::computeStraightSidedPositions ()
{
  _clean();
  // compute straigh sided positions that are actually X,Y,Z positions
  // that are NOT always on curves and surfaces

  // points classified on model vertices shall not move !
  for(GModel::viter it = _gm->firstVertex(); it != _gm->lastVertex(); ++it){
    if ((*it)->points.size()){
      MPoint *p = (*it)->points[0];
      MVertex *v = p->getVertex(0);
      _straightSidedLocation [v] = SVector3((*it)->x(),(*it)->y(),(*it)->z());
      _targetLocation [v] = SVector3((*it)->x(),(*it)->y(),(*it)->z());
    }
  }

  //  printf("coucou2\n");
  // compute stright sided positions of vertices that are classified on model edges
  for(GModel::eiter it = _gm->firstEdge(); it != _gm->lastEdge(); ++it){
    for (int i=0;i<(*it)->lines.size();i++){
      MLine *l = (*it)->lines[i];
      int N = l->getNumVertices()-2;
      SVector3 p0((*it)->lines[i]->getVertex(0)->x(),
          (*it)->lines[i]->getVertex(0)->y(),
          (*it)->lines[i]->getVertex(0)->z());
      SVector3 p1((*it)->lines[i]->getVertex(1)->x(),
          (*it)->lines[i]->getVertex(1)->y(),
          (*it)->lines[i]->getVertex(1)->z());

      for (int j=1;j<=N;j++){
        const double xi = (double)(j)/(N+1);
        //	printf("xi = %g\n",xi);
        const SVector3 straightSidedPoint   = p0 *(1.-xi) + p1*xi;
        MVertex *v = (*it)->lines[i]->getVertex(j+1);
        if (_straightSidedLocation.find(v) == _straightSidedLocation.end()){
          _straightSidedLocation   [v] = straightSidedPoint;
          _targetLocation[v] = SVector3(v->x(),v->y(),v->z());
        }
      }
    }
  }

  //  printf("coucou3\n");
  // compute stright sided positions of vertices that are classified on model faces
  for(GModel::fiter it = _gm->firstFace(); it != _gm->lastFace(); ++it){
    for (int i=0;i<(*it)->mesh_vertices.size();i++){
      MVertex *v = (*it)->mesh_vertices[i];
      _targetLocation[v] = SVector3(v->x(),v->y(),v->z());
    }

    for (int i=0;i<(*it)->triangles.size();i++){
      MTriangle *t = (*it)->triangles[i];
      MFace face = t->getFace(0);
      const polynomialBasis* fs = t->getFunctionSpace();
      for (int j=0;j<t->getNumVertices();j++){
        if (t->getVertex(j)->onWhat() == *it){
          const double t1 = fs->points(j, 0);
          const double t2 = fs->points(j, 1);
          SPoint3 pc = face.interpolate(t1, t2);
          _straightSidedLocation [t->getVertex(j)] =
            SVector3(pc.x(),pc.y(),pc.z());
        }
      }
    }
    for (int i=0;i<(*it)->quadrangles.size();i++){
      //      printf("coucou quad %d\n",i);
      MQuadrangle *q = (*it)->quadrangles[i];
      MFace face = q->getFace(0);
      const polynomialBasis* fs = q->getFunctionSpace();
      for (int j=0;j<q->getNumVertices();j++){
        if (q->getVertex(j)->onWhat() == *it){
          const double t1 = fs->points(j, 0);
          const double t2 = fs->points(j, 1);
          SPoint3 pc = face.interpolate(t1, t2);
          _straightSidedLocation [q->getVertex(j)] =
            SVector3(pc.x(),pc.y(),pc.z());
        }
      }
    }
  }

  for(GModel::riter it = _gm->firstRegion(); it != _gm->lastRegion(); ++it){
    for (int i=0;i<(*it)->mesh_vertices.size();i++){
      MVertex *v = (*it)->mesh_vertices[i];
      _targetLocation[v] = SVector3(v->x(),v->y(),v->z());
    }
    for (int i=0;i<(*it)->tetrahedra.size();i++){
      _dim = 3;
      MTetrahedron *t = (*it)->tetrahedra[i];
      MTetrahedron t_1 ((*it)->tetrahedra[i]->getVertex(0),
          (*it)->tetrahedra[i]->getVertex(1),
          (*it)->tetrahedra[i]->getVertex(2),
          (*it)->tetrahedra[i]->getVertex(3));
      const polynomialBasis* fs = t->getFunctionSpace();
      for (int j=0;j<t->getNumVertices();j++){
        if (t->getVertex(j)->onWhat() == *it){
          double t1 = fs->points(j, 0);
          double t2 = fs->points(j, 1);
          double t3 = fs->points(j, 2);
          SPoint3 pc; t_1.pnt(t1, t2, t3,pc);
          _straightSidedLocation [t->getVertex(j)] =
            SVector3(pc.x(),pc.y(),pc.z());
        }
      }
    }
    for (int i=0;i<(*it)->hexahedra.size();i++){
      _dim = 3;
      MHexahedron *h = (*it)->hexahedra[i];
      MHexahedron h_1 ((*it)->hexahedra[i]->getVertex(0),
          (*it)->hexahedra[i]->getVertex(1),
          (*it)->hexahedra[i]->getVertex(2),
          (*it)->hexahedra[i]->getVertex(3),
          (*it)->hexahedra[i]->getVertex(4),
          (*it)->hexahedra[i]->getVertex(5),
          (*it)->hexahedra[i]->getVertex(6),
          (*it)->hexahedra[i]->getVertex(7));
      const polynomialBasis* fs = h->getFunctionSpace();
      for (int j=0;j<h->getNumVertices();j++){
        if (h->getVertex(j)->onWhat() == *it){
          double t1 = fs->points(j, 0);
          double t2 = fs->points(j, 1);
          double t3 = fs->points(j, 2);
          SPoint3 pc; h_1.pnt(t1, t2, t3,pc);
          _straightSidedLocation [h->getVertex(j)] =
            SVector3(pc.x(),pc.y(),pc.z());
        }
      }
    }
  }

  Msg::Info("highOrderTools has been set up : %d nodes are considered",_straightSidedLocation.size());
}

// apply a displacement that does not create elements that are
// distorted over a value "thres"
double highOrderTools::apply_incremental_displacement (double max_incr,
    std::vector<MElement*> & v,
    bool mixed,
    double thres,
    char *meshName,
    std::vector<MElement*> & disto)
{
#ifdef HAVE_PETSC
  // assume that the mesh is OK, yet already curved
  //linearSystemCSRTaucs<double> *lsys = new linearSystemCSRTaucs<double>;
  linearSystemPETSc<double> *lsys = new  linearSystemPETSc<double>;
  lsys->setParameter("petscOptions","-pc_type ilu");
  lsys->setParameter("petscOptions","-ksp_monitor");

  dofManager<double> myAssembler(lsys);
  elasticityMixedTerm El_mixed (0, 1.0, .333, _tag);
  elasticityTerm El (0, 1.0, .333, _tag);

  std::set<MVertex*> _vertices;

  //+++++++++ Boundary Conditions & Numbering +++++++++++++++++++++++++++++++
  // fix all dof that correspond to vertices on the boundary
  // the value is equal
  for (unsigned int i = 0; i < v.size(); i++){
    for (int j = 0; j < v[i]->getNumVertices(); j++){
      MVertex *vert = v[i]->getVertex(j);
      _vertices.insert(vert);
    }
  }

  //+++++++++ Fix d tr(eps) = 0 +++++++++++++++++++++++++++++++
  if (mixed){
    for (unsigned int i = 0; i < disto.size(); i++){
      for (int j = 0; j < disto[i]->getNumVertices(); j++){
        MVertex *vert = disto[i]->getVertex(j);
        myAssembler.fixVertex(vert, 4, _tag, 0.0);
      }
    }
  }

  printf("coucou1\n");

  for (std::set<MVertex*>::iterator it = _vertices.begin(); it != _vertices.end(); ++it){
    MVertex *vert = *it;
    std::map<MVertex*,SVector3>::iterator itt = _targetLocation.find(vert);
    // impose displacement @ boundary
    //    if (!(vert->onWhat()->geomType()  == GEntity::Line
    //	  && vert->onWhat()->tag()  == 2)){
    if (itt != _targetLocation.end() && vert->onWhat()->dim() < _dim){
      //		printf("fixing motion of vertex %d to %g %g\n",vert->getNum(),itt->second.x()-vert->x(),itt->second.y()-vert->y());
      myAssembler.fixVertex(vert, 0, _tag, itt->second.x()-vert->x());
      myAssembler.fixVertex(vert, 1, _tag, itt->second.y()-vert->y());
      myAssembler.fixVertex(vert, 2, _tag, itt->second.z()-vert->z());
    }
    // ensure we do not touch any vertex that is on the boundary
    else if (vert->onWhat()->dim() < _dim){
      myAssembler.fixVertex(vert, 0, _tag, 0);
      myAssembler.fixVertex(vert, 1, _tag, 0);
      myAssembler.fixVertex(vert, 2, _tag, 0);
    }
    //    }
    if (_dim == 2)myAssembler.fixVertex(vert, 2, _tag, 0);
    // number vertices
    myAssembler.numberVertex(vert, 0, _tag);
    myAssembler.numberVertex(vert, 1, _tag);
    myAssembler.numberVertex(vert, 2, _tag);
    if (mixed){
      myAssembler.numberVertex(vert, 3, _tag);
      myAssembler.numberVertex(vert, 4, _tag);
    }
  }

  printf("coucou2\n");

  //+++++++++ Assembly  & Solve ++++++++++++++++++++++++++++++++++++
  if (myAssembler.sizeOfR()){
    // assembly of the elasticity term on the
    double t1 = Cpu();
    for (unsigned int i = 0; i < v.size(); i++){
      SElement se(v[i]);
      if (mixed)El_mixed.addToMatrix(myAssembler, &se);
      else El.addToMatrix(myAssembler, &se);
    }
    double t2 = Cpu();
    // solve the system
    printf("coucou3 %12.5E\n", t2-t1);
    lsys->systemSolve();
    double t3 = Cpu();
    printf("coucou4 %12.5E\n", t3-t2);
  }

  //+++++++++ Move vertices @ maximum ++++++++++++++++++++++++++++++++++++
  FILE *fd = fopen ("d.msh","w");
  fprintf(fd,"$MeshFormat\n2 0 8\n$EndMeshFormat\n$NodeData\n1\n\"tr(sigma)\"\n1\n0.0\n3\n1\n3\n%d\n", (int) _vertices.size());
  for (std::set<MVertex*>::iterator it = _vertices.begin(); it != _vertices.end(); ++it){
    double ax, ay, az;
    myAssembler.getDofValue(*it, 0, _tag, ax);
    myAssembler.getDofValue(*it, 1, _tag, ay);
    myAssembler.getDofValue(*it, 2, _tag, az);
    (*it)->x() += max_incr*ax;
    (*it)->y() += max_incr*ay;
    (*it)->z() += max_incr*az;
    fprintf(fd,"%d %g %g %g\n",(*it)->getIndex(), ax,ay,az);
  }
  fprintf(fd,"$EndNodeData\n");
  fclose(fd);

  //+------------------- Check now if elements are ok ---------------+++++++

  (*_vertices.begin())->onWhat()->model()->writeMSH(meshName);

  printf("coucou5\n");

  double percentage = max_incr * 100.;
  while(1){
    std::vector<MElement*> disto;
    double minD;
    getDistordedElements(v, 0.5, disto, minD);
    if (minD < thres){
      percentage -= 10.;
      for (std::set<MVertex*>::iterator it = _vertices.begin(); it != _vertices.end(); ++it){
        double ax, ay, az;
        myAssembler.getDofValue(*it, 0, _tag, ax);
        myAssembler.getDofValue(*it, 1, _tag, ay);
        myAssembler.getDofValue(*it, 2, _tag, az);
        (*it)->x() -= .1*ax;
        (*it)->y() -= .1*ay;
        (*it)->z() -= .1*az;
      }
    }
    else break;
  }
  printf("coucou6\n");

  delete lsys;
  return percentage;
#endif
  return 0.0;
}

// uncurve elements that are invalid
void highOrderTools::ensureMinimumDistorsion(std::vector<MElement*> &all,
    double threshold)
{
  for(int tries = 0; tries < 100; tries++){
    double minD;
    std::vector<MElement*> disto;
    getDistordedElements(all, threshold, disto, minD);
    if (disto.empty()) break;
    Msg::Info("Fixing %d bad curved elements (worst disto %g)", disto.size(), minD);
    for (int i = 0; i < disto.size(); i++){
      ensureMinimumDistorsion(disto[i], threshold);
    }
  }
}

double highOrderTools::applySmoothingTo (std::vector<MElement*> &all,
					 double threshold, bool mixed)
{
  int ITER = 0;
  double minD, FACT = 1.0;
  std::vector<MElement*> disto;
  // move the points to their straight sided locations
  for (unsigned int i = 0; i < all.size(); i++)
    moveToStraightSidedLocation(all[i]);
  // apply the displacement

  _gm->writeMSH("straightSided.msh");

  printf("argh\n");

  char sm[] = "sm.msh";
  double percentage_of_what_is_left = apply_incremental_displacement (1., all, mixed, -100000000, sm, all);
  //  ensureMinimumDistorsion (all, threshold);
  return 1.;

  double percentage = 0.0;
  while(1){
    char NN[256];
    sprintf(NN,"smoothing-%d.msh",ITER++);
    double percentage_of_what_is_left = apply_incremental_displacement (1.,all, mixed, threshold,NN,all);
    percentage += (1.-percentage) * percentage_of_what_is_left/100.;
    Msg::Info("The smoother was able to do %3d percent of the motion",(int)(percentage*100.));
    if (percentage_of_what_is_left == 0.0) break;
    else if (percentage_of_what_is_left == 100.)break;
  }

  getDistordedElements(all, 0.3, disto, minD);
  Msg::Info("iter %d : %d elements / %d distorted  min Disto = %g ",ITER,
	    all.size(), disto.size(), minD);
  return percentage;
}

extern void printJacobians(GModel *m, const char *nm);
void highOrderTools::makePosViewWithJacobians (const char *fn){
  printJacobians(_gm,fn);
}

#endif

