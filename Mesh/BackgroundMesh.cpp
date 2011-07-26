// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshMessage.h"
#include "BackgroundMesh.h"
#include "Numeric.h"
#include "Context.h"
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "GModel.h"
#include "Field.h"
#include "MElement.h"
#include "MElementOctree.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MVertex.h"

#if defined(HAVE_SOLVER)
#include "dofManager.h"
#include "laplaceTerm.h"
#include "linearSystemGMM.h"
#include "linearSystemCSR.h"
#include "linearSystemFull.h"
#include "linearSystemPETSc.h"
#endif

// computes the characteristic length of the mesh at a vertex in order
// to have the geometry captured with accuracy. A parameter called
// CTX::instance()->mesh.minCircPoints tells the minimum number of points per
// radius of curvature

SMetric3 buildMetricTangentToCurve (SVector3 &t, double curvature, double &lambda)
{
  lambda = 1.e22;
  if (curvature == 0.0)return SMetric3(1.e-22);
  SVector3 a;
  if (t(0) <= t(1) && t(0) <= t(2)){
    a = SVector3(1,0,0);
  } 
  else if (t(1) <= t(0) && t(1) <= t(2)){
    a = SVector3(0,1,0);
  } 
  else{
    a = SVector3(0,0,1);
  }
  SVector3 b = crossprod (t,a);
  SVector3 c = crossprod (b,t);
  b.normalize();
  c.normalize();
  t.normalize();
  lambda =  ((2 * M_PI) /( fabs(curvature) *  CTX::instance()->mesh.minCircPoints ) );

  SMetric3 curvMetric (1./(lambda*lambda),1.e-10,1.e-10,t,b,c);
    //SMetric3 curvMetric (1./(lambda*lambda));
  return curvMetric;
}

SMetric3 max_edge_curvature_metric(const GVertex *gv, double &length)
{
  SMetric3 val (1.e-12);
  length = 1.e22;
  std::list<GEdge*> l_edges = gv->edges();
  for (std::list<GEdge*>::const_iterator ite = l_edges.begin(); 
       ite != l_edges.end(); ++ite){
    GEdge *_myGEdge = *ite;
    Range<double> range = _myGEdge->parBounds(0);      
    SMetric3 cc;
    double l;
    if (gv == _myGEdge->getBeginVertex()) {
      SVector3 t = _myGEdge->firstDer(range.low());
      t.normalize();
      cc = buildMetricTangentToCurve(t,_myGEdge->curvature(range.low()),l);
    }
    else {
      SVector3 t = _myGEdge->firstDer(range.high());
      t.normalize();
      cc = buildMetricTangentToCurve(t,_myGEdge->curvature(range.high()),l);
    }
    val = intersection(val,cc);
    length = std::min(length,l);
  }
  return val;
}

SMetric3 max_edge_curvature_metric(const GEdge *ge, double u, double &l)
{
  SVector3 t =  ge->firstDer(u);
  t.normalize();
  return buildMetricTangentToCurve(t,ge->curvature(u),l);  
}

static double max_edge_curvature(const GVertex *gv)
{
  double val = 0;
  std::list<GEdge*> l_edges = gv->edges();
  for (std::list<GEdge*>::const_iterator ite = l_edges.begin(); 
       ite != l_edges.end(); ++ite){
    GEdge *_myGEdge = *ite;
    Range<double> range = _myGEdge->parBounds(0);      
    double cc;
    if (gv == _myGEdge->getBeginVertex()) cc = _myGEdge->curvature(range.low());
    else cc = _myGEdge->curvature(range.high());
    val = std::max(val, cc);
  }
  return val;
}

static double max_surf_curvature(const GEdge *ge, double u)
{
  double val = 0;
  std::list<GFace *> faces = ge->faces();
  std::list<GFace *>::iterator it = faces.begin();
  while(it != faces.end()){
    if ((*it)->geomType() != GEntity::CompoundSurface &&
	(*it)->geomType() != GEntity::DiscreteSurface){
      SPoint2 par = ge->reparamOnFace((*it), u, 1);
      double cc = (*it)->curvature(par);
      val = std::max(cc, val);
    }
    ++it;
  }  
  return val;
}

static double max_surf_curvature(const GVertex *gv)
{
  double val = 0;
  std::list<GEdge*> l_edges = gv->edges();
  for (std::list<GEdge*>::const_iterator ite = l_edges.begin(); 
       ite != l_edges.end(); ++ite){
    GEdge *_myGEdge = *ite;
    Range<double> bounds = _myGEdge->parBounds(0);
    if (gv == _myGEdge->getBeginVertex())
      val = std::max(val, max_surf_curvature(_myGEdge, bounds.low()));
    else
      val = std::max(val, max_surf_curvature(_myGEdge, bounds.high()));
  }
  return val;
}

static SMetric3 metric_based_on_surface_curvature(const GFace *gf, double u, double v)
{
  if (gf->geomType() == GEntity::Plane)return SMetric3(1.e-6);
  double cmax, cmin;
  SVector3 dirMax,dirMin;
  cmax = gf->curvatures(SPoint2(u, v),&dirMax, &dirMin, &cmax,&cmin);
  if (cmin == 0)cmin =1.e-5;
  if (cmax == 0)cmax =1.e-5;
  double lambda2 =  ((2 * M_PI) /( fabs(cmax) *  CTX::instance()->mesh.minCircPoints ) );
  double lambda1 =  ((2 * M_PI) /( fabs(cmin) *  CTX::instance()->mesh.minCircPoints ) );
  SVector3 Z = crossprod(dirMax,dirMin);

  lambda1 = std::max(lambda1, CTX::instance()->mesh.lcMin);
  lambda2 = std::max(lambda2, CTX::instance()->mesh.lcMin);
  lambda1 = std::min(lambda1, CTX::instance()->mesh.lcMax);
  lambda2 = std::min(lambda2, CTX::instance()->mesh.lcMax);
  /*  if (gf->tag() == 36  || gf->tag() == 62)
    printf("%g %g -- %g %g -- %g %g %g --  %g %g %g -- %g %g %g -- %g %g\n",u,v,cmax,cmin,
	   dirMax.x(),dirMax.y(),dirMax.z(),
	   dirMin.x(),dirMin.y(),dirMin.z(),
	   Z.x(),Z.y(),Z.z(),
	   lambda1,lambda2);
  */
  SMetric3 curvMetric (1./(lambda1*lambda1),1./(lambda2*lambda2),1.e-5, 
		       dirMin, dirMax, Z );
  return curvMetric;
}

static SMetric3 metric_based_on_surface_curvature(const GEdge *ge, double u)
{
  SMetric3 mesh_size(1.e-05);
  std::list<GFace *> faces = ge->faces();
  std::list<GFace *>::iterator it = faces.begin();
  int count = 0;
  while(it != faces.end()){
    if ( ((*it)->geomType() != GEntity::CompoundSurface) && ((*it)->geomType() != GEntity::DiscreteSurface) ){
      SPoint2 par = ge->reparamOnFace((*it), u, 1);
      SMetric3 m = metric_based_on_surface_curvature (*it, par.x(), par.y());
      if (!count) mesh_size = m;
      else mesh_size = intersection(mesh_size, m);
      count++;
    }
    ++it;
  }  
  double Crv = ge->curvature(u);
  double lambda =  ((2 * M_PI) /( fabs(Crv) *  CTX::instance()->mesh.minCircPoints ) );
  SMetric3 curvMetric (1./(lambda*lambda));
  return intersection(mesh_size,curvMetric);
}

static SMetric3 metric_based_on_surface_curvature(const GVertex *gv)
{
  SMetric3 mesh_size(1.e-5);
  std::list<GEdge*> l_edges = gv->edges();
  for (std::list<GEdge*>::const_iterator ite = l_edges.begin(); 
       ite != l_edges.end(); ++ite){
    GEdge *_myGEdge = *ite;
    Range<double> bounds = _myGEdge->parBounds(0);
    if (gv == _myGEdge->getBeginVertex())
      mesh_size = intersection
        (mesh_size,
         metric_based_on_surface_curvature(_myGEdge, bounds.low()));
    else
      mesh_size = intersection
        (mesh_size, 
         metric_based_on_surface_curvature(_myGEdge, bounds.high()));
  }
  return mesh_size;
}

// the mesh vertex is classified on a model vertex.  we compute the
// maximum of the curvature of model faces surrounding this point if
// it is classified on a model edge, we do the same for all model
// faces surrounding it if it is on a model face, we compute the
// curvature at this location

static double LC_MVertex_CURV(GEntity *ge, double U, double V)
{

  double Crv = 0;
  switch(ge->dim()){
  case 0:        
    Crv = max_edge_curvature((const GVertex *)ge);
    Crv = std::max(max_surf_curvature((const GVertex *)ge), Crv);
    //Crv = max_surf_curvature((const GVertex *)ge);
    break;
  case 1:
    {
      GEdge *ged = (GEdge *)ge;
      Crv = ged->curvature(U)*2;
      Crv = std::max(Crv, max_surf_curvature(ged, U));
      //Crv = max_surf_curvature(ged, U);      
    }
    break;
  case 2:
    {
      GFace *gf = (GFace *)ge;
      Crv = gf->curvature(SPoint2(U, V));
    }
    break;
  }
 
  double lc = Crv > 0 ? 2 * M_PI / Crv / CTX::instance()->mesh.minCircPoints : MAX_LC;
  return lc;
}

static SMetric3 LC_MVertex_CURV_ANISO(GEntity *ge, double U, double V)
{
  //std::cout << "I'm in LC_MVertex_CURV_ANISO" << std::endl;
  //std::cout << "The dimension of the entity is: "<< ge->dim() << std::endl;
  switch(ge->dim()){
  //std::cout << "The dimension of the entity is: "<< ge->dim() << std::endl;
  case 0: return metric_based_on_surface_curvature((const GVertex *)ge);
  case 1: return metric_based_on_surface_curvature((const GEdge *)ge, U);
  case 2: return metric_based_on_surface_curvature((const GFace *)ge, U, V);
  }
  Msg::Error("Curvature control impossible to compute for a volume!");
  return SMetric3();
}

// compute the mesh size at a given vertex due to prescribed sizes at
// mesh vertices
static double LC_MVertex_PNTS(GEntity *ge, double U, double V)
{
  switch(ge->dim()){
  case 0:
    {
      GVertex *gv = (GVertex *)ge;
      double lc = gv->prescribedMeshSizeAtVertex();
      // FIXME we might want to remove this to make all lc treatment consistent
      if(lc >= MAX_LC) return CTX::instance()->lc / 10.;
      return lc;
    }
  case 1:
    {
      GEdge *ged = (GEdge *)ge;
      GVertex *v1 = ged->getBeginVertex();
      GVertex *v2 = ged->getEndVertex();
      if (v1 && v2){
        Range<double> range = ged->parBounds(0);      
        double a = (U - range.low()) / (range.high() - range.low()); 
        double lc = (1 - a) * v1->prescribedMeshSizeAtVertex() +
          (a) * v2->prescribedMeshSizeAtVertex() ;
        // FIXME we might want to remove this to make all lc treatment consistent
        if(lc >= MAX_LC) return CTX::instance()->lc / 10.;
        return lc;
      }
      else 
        return MAX_LC; 
    }
  default:
    return MAX_LC;
  }
}

// This is the only function that is used by the meshers
double BGM_MeshSize(GEntity *ge, double U, double V, 
                    double X, double Y, double Z)
{
  // default lc (mesh size == size of the model)
  double l1 = CTX::instance()->lc;

  // lc from points
  double l2 = MAX_LC;
  if(CTX::instance()->mesh.lcFromPoints && ge->dim() < 2) 
    l2 = LC_MVertex_PNTS(ge, U, V);
  
  // lc from curvature
  double l3 = MAX_LC;
  if(CTX::instance()->mesh.lcFromCurvature && ge->dim() < 3)
    l3 = LC_MVertex_CURV(ge, U, V);
  
  // lc from fields
  double l4 = MAX_LC;
  FieldManager *fields = ge->model()->getFields();
  if(fields->background_field > 0){
    Field *f = fields->get(fields->background_field);
    //printf("field %p %s %d %p\n",f,f->getName(),fields->size(), ge->model());
    if(f) l4 = (*f)(X, Y, Z, ge);
    //printf("X Y Z =%g %g %g L4=%g L3=%g L2=%g L1=%g\n", X, Y, Z, l4, l3, l2, l1);
  }

  // take the minimum, then constrain by lcMin and lcMax
  double lc = std::min(std::min(std::min(l1, l2), l3), l4);
  lc = std::max(lc, CTX::instance()->mesh.lcMin);
  lc = std::min(lc, CTX::instance()->mesh.lcMax);
 
  if(lc <= 0.){
    Msg::Error("Wrong mesh element size lc = %g (lcmin = %g, lcmax = %g)",
               lc, CTX::instance()->mesh.lcMin, CTX::instance()->mesh.lcMax);
    lc = l1;
  }

  //printf("BGM X Y Z =%g %g %g L4=%g L3=%g L2=%g L1=%g LC=%g LFINAL=%g \n", X, Y, Z, l4, l3, l2, l1, lc , lc* CTX::instance()->mesh.lcFactor);

  return lc * CTX::instance()->mesh.lcFactor;
}


// anisotropic version of the background field
// for now, only works with bamg in 2D, work
// in progress

SMetric3 BGM_MeshMetric(GEntity *ge, 
                        double U, double V, 
                        double X, double Y, double Z)
{
  // default lc (mesh size == size of the model)
  double l1 = CTX::instance()->lc;

  // lc from points            
  double l2 = MAX_LC;
  if(CTX::instance()->mesh.lcFromPoints && ge->dim() < 2) 
    l2 = LC_MVertex_PNTS(ge, U, V);
  
  // lc from curvature
  SMetric3 l3(1./(MAX_LC*MAX_LC));
  if(CTX::instance()->mesh.lcFromCurvature && ge->dim() < 3)
    l3 = LC_MVertex_CURV_ANISO(ge, U, V);

  // lc from fields
  SMetric3 l4(1./(MAX_LC*MAX_LC));
  FieldManager *fields = ge->model()->getFields();
  if(fields->background_field > 0){
    Field *f = fields->get(fields->background_field);
    if(f){
      if (!f->isotropic())
        (*f)(X, Y, Z, l4,ge);
      else{
	double L = (*f)(X, Y, Z, ge);
        l4 = SMetric3(1/(L*L));
      }
    }
  }
  
  // take the minimum, then constrain by lcMin and lcMax
  double lc = std::min(l1, l2);
  lc = std::max(lc, CTX::instance()->mesh.lcMin);
  lc = std::min(lc, CTX::instance()->mesh.lcMax);

  if(lc <= 0.){
    Msg::Error("Wrong mesh element size lc = %g (lcmin = %g, lcmax = %g)",
               lc, CTX::instance()->mesh.lcMin, CTX::instance()->mesh.lcMax);
    lc = l1;
  }
  
  SMetric3 LC(1./(lc*lc));
  SMetric3 m = intersection(intersection (l4, LC),l3);
  //  printf("%g %g %g %g %g %g\n",m(0,0),m(1,1),m(2,2),m(0,1),m(0,2),m(1,2));
  return m;
  //  return lc * CTX::instance()->mesh.lcFactor;
}

bool Extend1dMeshIn2dSurfaces()
{
  return CTX::instance()->mesh.lcExtendFromBoundary ? true : false;
}

bool Extend2dMeshIn3dVolumes()
{
  return CTX::instance()->mesh.lcExtendFromBoundary ? true : false;
}

// ---------- backgroundMesh class -----------

void backgroundMesh::set(GFace *gf)
{
  if (_current) delete _current;
  _current = new backgroundMesh(gf);
}

void backgroundMesh::unset()
{
  if (_current) delete _current;
  _current = 0;
}

backgroundMesh::backgroundMesh(GFace *_gf)
{
  // create a bunch of triangles on the parametric space
  // those triangles are local to the backgroundMesh so that
  // they do not depend on the actual mesh that can be deleted

  for (unsigned int i = 0; i < _gf->triangles.size(); i++){
    MTriangle *e = _gf->triangles[i];
    MVertex *news[3];
    for (int j=0;j<3;j++){
      std::map<MVertex*,MVertex*>::iterator it = _3Dto2D.find(e->getVertex(j));
      MVertex *newv =0;
      if (it == _3Dto2D.end()){
        SPoint2 p;
        bool success = reparamMeshVertexOnFace(e->getVertex(j), _gf, p);       
        newv = new MVertex (p.x(), p.y(), 0.0);
        _vertices.push_back(newv);
        _3Dto2D[e->getVertex(j)] = newv;
        _2Dto3D[newv] = e->getVertex(j);
      }
      else newv = it->second;
      news[j] = newv;
    }
    _triangles.push_back(new MTriangle(news[0],news[1],news[2]));
  }

  // build a search structure
  _octree = new MElementOctree(_triangles); 

  // compute the mesh sizes at nodes
  if (CTX::instance()->mesh.lcFromPoints)
    propagate1dMesh(_gf);
  else {
    std::map<MVertex*, MVertex*>::iterator itv2 = _2Dto3D.begin();
    for ( ; itv2 != _2Dto3D.end(); ++itv2){
      _sizes[itv2->first] = MAX_LC;
    }
  }
  // ensure that other criteria are fullfilled 
  updateSizes(_gf);

  // compute optimal mesh orientations
  propagatecrossField(_gf);

  _3Dto2D.clear();
  _2Dto3D.clear();
}

backgroundMesh::~backgroundMesh()
{
  for (unsigned int i = 0; i < _vertices.size(); i++) delete _vertices[i];
  for (unsigned int i = 0; i < _triangles.size(); i++) delete _triangles[i];
  delete _octree;
}

static void propagateValuesOnFace (GFace *_gf, 				  
				   std::map<MVertex*,double> &dirichlet)
{
  linearSystem<double> *_lsys = 0;
#if defined(HAVE_PETSC) && !defined(HAVE_TAUCS)
  _lsys = new linearSystemPETSc<double>;
#elif defined(HAVE_GMM) && !defined(HAVE_TAUCS)
  linearSystemGmm<double> *_lsysb = new linearSystemGmm<double>;
  _lsysb->setGmres(1);
  _lsys = _lsysb;
#elif defined(HAVE_TAUCS) 
  _lsys = new linearSystemCSRTaucs<double>;
#else
  _lsys = new linearSystemFull<double>;
#endif

  dofManager<double> myAssembler(_lsys);

  // fix boundary conditions
  std::map<MVertex*, double>::iterator itv = dirichlet.begin();
  for ( ; itv != dirichlet.end(); ++itv){
    myAssembler.fixVertex(itv->first, 0, 1, itv->second);
  }


  // Number vertices
  std::set<MVertex*> vs;
  for (unsigned int k = 0; k < _gf->triangles.size(); k++)
    for (int j=0;j<3;j++)vs.insert(_gf->triangles[k]->getVertex(j));
  for (unsigned int k = 0; k < _gf->quadrangles.size(); k++)
    for (int j=0;j<4;j++)vs.insert(_gf->quadrangles[k]->getVertex(j));
  for (std::set<MVertex*>::iterator it = vs.begin(); it != vs.end(); ++it)
    myAssembler.numberVertex(*it, 0, 1);

  // Assemble
  simpleFunction<double> ONE(1.0);
  laplaceTerm l(0, 1, &ONE);
  for (unsigned int k = 0; k < _gf->triangles.size(); k++){
    MTriangle *t = _gf->triangles[k];
    SElement se(t);
    l.addToMatrix(myAssembler, &se);    
  }

  // Solve
  _lsys->systemSolve();

  // save solution
  for (std::set<MVertex*>::iterator it = vs.begin(); it != vs.end(); ++it){
    myAssembler.getDofValue(*it, 0, 1, dirichlet[*it]);
  }
  
  delete _lsys;
}

void replaceMeshCompound(GFace *gf, std::list<GEdge*> &edges)
{
  std::list<GEdge*> e = gf->edges();
  //Replace edges by their compounds
  std::set<GEdge*> mySet;
  std::list<GEdge*>::iterator it = e.begin();
  while(it != e.end()){
    if((*it)->getCompound()){
      mySet.insert((*it)->getCompound());
    }
    else{ 
      mySet.insert(*it);
    }
    ++it;
  }
  edges.clear();
  edges.insert(edges.begin(), mySet.begin(), mySet.end());
}

void backgroundMesh::propagate1dMesh(GFace *_gf)
{
  std::list<GEdge*> e;// = _gf->edges();
  replaceMeshCompound(_gf, e);
  std::list<GEdge*>::const_iterator it = e.begin();
  std::map<MVertex*,double> sizes;
  
  for( ; it != e.end(); ++it ){
    if (!(*it)->isSeam(_gf)){
      for(unsigned int i = 0; i < (*it)->lines.size(); i++ ){
        MVertex *v1 = (*it)->lines[i]->getVertex(0);
        MVertex *v2 = (*it)->lines[i]->getVertex(1);
	//	printf("%g %g %g\n",v1->x(),v1->y(),v1->z());
        double d = sqrt((v1->x() - v2->x()) * (v1->x() - v2->x()) +
                        (v1->y() - v2->y()) * (v1->y() - v2->y()) +
                        (v1->z() - v2->z()) * (v1->z()  -v2->z()));
        for (int k=0;k<2;k++){
          MVertex *v = (*it)->lines[i]->getVertex(k);
          std::map<MVertex*, double>::iterator itv = sizes.find(v);
          if (itv == sizes.end())
            sizes[v] = log(d);
          else 
            itv->second = 0.5 * (itv->second + log(d));
        }      
      }
    }
  }

  propagateValuesOnFace(_gf,sizes);

  std::map<MVertex*,MVertex*>::iterator itv2 = _2Dto3D.begin();
  for ( ; itv2 != _2Dto3D.end(); ++itv2){
    MVertex *v_2D = itv2->first;
    MVertex *v_3D = itv2->second;
    _sizes[v_2D] = exp(sizes[v_3D]);
  }
}

// C R O S S   F I E L D S 

crossField2d::crossField2d(MVertex* v, GEdge* ge)
{
  double p;
  bool success = reparamMeshVertexOnEdge(v, ge, p); 
  if (!success){
    Msg::Warning("cannot reparametrize a point in crossField");
    _angle = 0;
    return;
  }
  SVector3 t = ge->firstDer (p);
  t.normalize();
  _angle = atan2 (t.y(),t.x());
  crossField2d::normalizeAngle (_angle);
}

void backgroundMesh::propagatecrossField(GFace *_gf)
{
  std::map<MVertex*,double> _cosines4,_sines4;

  std::list<GEdge*> e;// = _gf->edges();

  replaceMeshCompound(_gf, e);

  std::list<GEdge*>::const_iterator it = e.begin();
  
  for( ; it != e.end(); ++it ){
    if (!(*it)->isSeam(_gf)){
      for(unsigned int i = 0; i < (*it)->lines.size(); i++ ){
	MVertex *v[2];
        v[0] = (*it)->lines[i]->getVertex(0);
        v[1] = (*it)->lines[i]->getVertex(1);
	SPoint2 p1,p2;	
	bool success = reparamMeshEdgeOnFace(v[0],v[1],_gf,p1,p2);
	double angle = atan2 ( p1.y()-p2.y() , p1.x()-p2.x() );
	//double angle = atan2 ( v[0]->y()-v[1]->y() , v[0]->x()- v[1]->x() );
	//double angle = atan2 ( v0->y()-v1->y() , v0->x()- v1->x() );
	crossField2d::normalizeAngle (angle);
	for (int i=0;i<2;i++){
	  std::map<MVertex*,double>::iterator itc = _cosines4.find(v[i]);
	  std::map<MVertex*,double>::iterator its = _sines4.find(v[i]);
	  if (itc != _cosines4.end()){
	    itc->second  = 0.5*(itc->second + cos(4*angle));   
	    its->second  = 0.5*(its->second + sin(4*angle));   
	  }
	  else {
	    _cosines4[v[i]] = cos(4*angle);
	    _sines4[v[i]] = sin(4*angle);
	  }
	}
      }
    }
  }

  // ------------------------------------------------------------
  // -------- Force Smooth Transition ---------------------------
  // ------------------------------------------------------------
  const int nbSmooth = 0;
  const double threshold_angle = 2. * M_PI/180.;
  for (int SMOOTH_ITER = 0 ; SMOOTH_ITER < nbSmooth ; SMOOTH_ITER++){
    it = e.begin();
    for( ; it != e.end(); ++it ){
      if (!(*it)->isSeam(_gf)){
	for(unsigned int i = 0; i < (*it)->lines.size(); i++ ){
	  MVertex *v[2];
	  v[0] = (*it)->lines[i]->getVertex(0);
	  v[1] = (*it)->lines[i]->getVertex(1);
	  double cos40 = _cosines4[v[0]];
	  double cos41 = _cosines4[v[1]];
	  double sin40 = _sines4[v[0]];
	  double sin41 = _sines4[v[1]];
	  double angle0 = atan2 (sin40,cos40)/4.;
	  double angle1 = atan2 (sin41,cos41)/4.;
	  if (fabs(angle0 - angle1) >  threshold_angle ){
	    double angle0_new = angle0 - (angle0-angle1) * 0.1;
	    double angle1_new = angle1 + (angle0-angle1) * 0.1;
	    //	    printf("%g %g -- %g %g\n",angle0,angle1,angle0_new,angle1_new);
	    _cosines4[v[0]] = cos(4*angle0_new);
	    _sines4[v[0]] = sin(4*angle0_new);	    
	    _cosines4[v[1]] = cos(4*angle1_new);
	    _sines4[v[1]] = sin(4*angle1_new);	    
	  }
	}
      }
    }
  }
  // ------------------------------------------------------------


  propagateValuesOnFace(_gf,_cosines4);
  propagateValuesOnFace(_gf,_sines4);

  std::map<MVertex*,MVertex*>::iterator itv2 = _2Dto3D.begin();
  for ( ; itv2 != _2Dto3D.end(); ++itv2){
    MVertex *v_2D = itv2->first;
    MVertex *v_3D = itv2->second;
    double angle = atan2(_sines4[v_3D],_cosines4[v_3D]) / 4.0;
    crossField2d::normalizeAngle (angle);
    _angles[v_2D] = angle;
  }

}

void backgroundMesh::updateSizes(GFace *_gf)
{
  std::map<MVertex*,double>::iterator itv = _sizes.begin();
  for ( ; itv != _sizes.end(); ++itv){    
    SPoint2 p;
    MVertex *v = _2Dto3D[itv->first];
    double lc;
    if (v->onWhat()->dim() == 0){
      lc = BGM_MeshSize(v->onWhat(), 0,0,v->x(),v->y(),v->z());
    }
    else if (v->onWhat()->dim() == 1){
      double u;
      v->getParameter(0, u);
      lc = BGM_MeshSize(v->onWhat(), u, 0, v->x(), v->y(), v->z());
    }
    else{
      bool success = reparamMeshVertexOnFace(v, _gf, p);       
      lc = BGM_MeshSize(_gf, p.x(), p.y(), v->x(), v->y(), v->z());
    }
    //    printf("2D -- %g %g 3D -- %g %g\n",p.x(),p.y(),v->x(),v->y());
    itv->second = std::min(lc,itv->second);
    itv->second = std::max(itv->second, CTX::instance()->mesh.lcMin);
    itv->second = std::min(itv->second, CTX::instance()->mesh.lcMax);
  }  
}

double backgroundMesh::operator() (double u, double v, double w) const
{
  double uv[3] = {u, v, w};
  double uv2[3];
  //  return 1.0;
  MElement *e = _octree->find(u, v, w, 2, true);
  if (!e) {
    Msg::Error("cannot find %g %g", u, v);
    return -1000.0;
  }
  e->xyz2uvw(uv, uv2);
  std::map<MVertex*,double>::const_iterator itv1 = _sizes.find(e->getVertex(0));
  std::map<MVertex*,double>::const_iterator itv2 = _sizes.find(e->getVertex(1));
  std::map<MVertex*,double>::const_iterator itv3 = _sizes.find(e->getVertex(2));
  return itv1->second * (1-uv2[0]-uv2[1]) + itv2->second * uv2[0] + itv3->second * uv2[1];
}

double backgroundMesh::getAngle(double u, double v, double w) const
{
  double uv[3] = {u, v, w};
  double uv2[3];
  //  return 1.0;
  MElement *e = _octree->find(u, v, w, 2, true);
  if (!e) {
    Msg::Error("cannot find %g %g", u, v);
    return 0.0;
  }
  e->xyz2uvw(uv, uv2);
  std::map<MVertex*,double>::const_iterator itv1 = _angles.find(e->getVertex(0));
  std::map<MVertex*,double>::const_iterator itv2 = _angles.find(e->getVertex(1));
  std::map<MVertex*,double>::const_iterator itv3 = _angles.find(e->getVertex(2));

  double cos4 = cos (4*itv1->second) * (1-uv2[0]-uv2[1]) + 
    cos (4*itv2->second) * uv2[0] + 
    cos (4*itv3->second) * uv2[1] ;
  double sin4 = sin (4*itv1->second) * (1-uv2[0]-uv2[1]) + 
    sin (4*itv2->second) * uv2[0] + 
    sin (4*itv3->second) * uv2[1] ;
  double angle = atan2(sin4,cos4)/4.0;
  crossField2d::normalizeAngle (angle);

  return angle;
}

void backgroundMesh::print(const std::string &filename, GFace *gf,
                           const std::map<MVertex*,double> &_whatToPrint) const
{
  FILE *f = fopen (filename.c_str(),"w");
  fprintf(f,"View \"Background Mesh\"{\n");
  for(unsigned int i=0;i<_triangles.size();i++){
    MVertex *v1 = _triangles[i]->getVertex(0);
    MVertex *v2 = _triangles[i]->getVertex(1);
    MVertex *v3 = _triangles[i]->getVertex(2);
    std::map<MVertex*,double>::const_iterator itv1 = _whatToPrint.find(v1);
    std::map<MVertex*,double>::const_iterator itv2 = _whatToPrint.find(v2);
    std::map<MVertex*,double>::const_iterator itv3 = _whatToPrint.find(v3);
    if (!gf){
      fprintf(f,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g) {%g,%g,%g};\n",
              v1->x(),v1->y(),v1->z(),
              v2->x(),v2->y(),v2->z(),
              v3->x(),v3->y(),v3->z(),itv1->second,itv2->second,itv3->second);
    }
    else {
      /*
      GPoint p1 = gf->point(SPoint2(v1->x(),v1->y()));
      GPoint p2 = gf->point(SPoint2(v2->x(),v2->y()));
      GPoint p3 = gf->point(SPoint2(v3->x(),v3->y()));
      fprintf(f,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g) {%g,%g,%g};\n",
              p1.x(),p1.y(),p1.z(),
              p2.x(),p2.y(),p2.z(),
              p3.x(),p3.y(),p3.z(),itv1->second,itv2->second,itv3->second);
      */
      fprintf(f,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g) {%g,%g,%g};\n",
              v1->x(),v1->y(),v1->z(),
              v2->x(),v2->y(),v2->z(),
              v3->x(),v3->y(),v3->z(),
              itv1->second,itv2->second,itv3->second);
    }

  }
  fprintf(f,"};\n");
  fclose(f);
}

MElementOctree* backgroundMesh::get_octree(){
  return _octree;
}

backgroundMesh* backgroundMesh::_current = 0;
