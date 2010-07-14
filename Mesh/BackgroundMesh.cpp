// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
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
#include "MElementOctree.h"
#include "MElement.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MVertex.h"
#include "Octree.h"

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
    if ((*it)->geomType() != GEntity::CompoundSurface){
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
  if (gf->tag() == 36  || gf->tag() == 62)
    printf("%g %g -- %g %g -- %g %g %g --  %g %g %g -- %g %g %g -- %g %g\n",u,v,cmax,cmin,
	   dirMax.x(),dirMax.y(),dirMax.z(),
	   dirMin.x(),dirMin.y(),dirMin.z(),
	   Z.x(),Z.y(),Z.z(),
	   lambda1,lambda2);
  
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
    if ((*it)->geomType() != GEntity::CompoundSurface){
      SPoint2 par = ge->reparamOnFace((*it), u, 1);
      SMetric3 m = metric_based_on_surface_curvature (*it, par.x(), par.y());
      if (!count) mesh_size = m;
      else mesh_size = intersection ( mesh_size, m);    
      if ( ge->tag() == 197)
	printf("edge %d face %d g %g %g -> %g %g %g\n",ge->tag(),(*it)->tag(),
	       m(0,0),m(1,1),m(2,2),mesh_size(0,0),mesh_size(1,1),mesh_size(2,2));
      count++;
    }
    ++it;
  }  
  return mesh_size;
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
      mesh_size = intersection ( mesh_size, 
				 metric_based_on_surface_curvature (_myGEdge, bounds.low()));    
    else
      mesh_size = intersection ( mesh_size, 
				 metric_based_on_surface_curvature (_myGEdge, bounds.high()));  }
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
    //    Crv = max_edge_curvature((const GVertex *)ge);
    //    Crv = std::max(max_surf_curvature((const GVertex *)ge), Crv);
    Crv = max_surf_curvature((const GVertex *)ge);
    break;
  case 1:
    {
      GEdge *ged = (GEdge *)ge;
      //      Crv = ged->curvature(U)*2;
      //      Crv = std::max(Crv, max_surf_curvature(ged, U));
      Crv = max_surf_curvature(ged, U);      
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
  switch(ge->dim()){
  case 0:        
    {
      SMetric3 m = metric_based_on_surface_curvature((const GVertex *)ge);
      //      printf("0d\n");
      return m;
    }
    break;
  case 1:
    {
      SMetric3 m = metric_based_on_surface_curvature((const GEdge *)ge,U);
      //      printf("1d %g %g %g\n",m(0,0),m(1,1),m(2,2));
      return m;
    }
    break;
  case 2:
    {
      return metric_based_on_surface_curvature((const GFace *)ge,U,V);
    }
    break;
  }
  Msg::Fatal("curvature control impossible to compute for a volume !");
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
  FieldManager *fields = GModel::current()->getFields();
  if(fields->background_field > 0){
    Field *f = fields->get(fields->background_field);
    if(f) l4 = (*f)(X, Y, Z, ge);
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
  FieldManager *fields = GModel::current()->getFields();
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
  _octree = buildMElementOctree(_triangles); 
  if (CTX::instance()->mesh.lcFromPoints)
    propagate1dMesh(_gf);
  else {
    std::map<MVertex*, MVertex*>::iterator itv2 = _2Dto3D.begin();
    for ( ; itv2 != _2Dto3D.end(); ++itv2){
      _sizes[itv2->first] = MAX_LC;
    }
  }
  updateSizes(_gf);
  _3Dto2D.clear();
  _2Dto3D.clear();
}

backgroundMesh::~backgroundMesh()
{
  for (unsigned int i = 0; i < _vertices.size(); i++) delete _vertices[i];
  for (unsigned int i = 0; i < _triangles.size(); i++) delete _triangles[i];
  delete _octree;
}

void backgroundMesh::propagate1dMesh(GFace *_gf)
{
#if defined(HAVE_SOLVER)
  std::list<GEdge*> e = _gf->edges();
  std::list<GEdge*>::const_iterator it = e.begin();
  std::map<MVertex*,double> sizes;
  
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
  
  for( ; it != e.end(); ++it ){
    if (!(*it)->isSeam(_gf)){
      for(unsigned int i = 0; i < (*it)->lines.size(); i++ ){
        MVertex *v1 = (*it)->lines[i]->getVertex(0);
        MVertex *v2 = (*it)->lines[i]->getVertex(1);
        double d = sqrt((v1->x() - v2->x()) * (v1->x() - v2->x()) +
                        (v1->y() - v2->y()) * (v1->y() - v2->y()) +
                        (v1->z() - v2->z()) * (v1->z()  -v2->z()));
        for (int k=0;k<2;k++){
          MVertex *v = (*it)->lines[i]->getVertex(k);
          std::map<MVertex*, double>::iterator itv = sizes.find(v);
          if (itv == sizes.end())
            sizes[v] = d;
          else 
            itv->second = 0.5 * (itv->second + d);
        }      
      }
    }
  }
  std::map<MVertex*, double>::iterator itv = sizes.begin();
  for ( ; itv != sizes.end(); ++itv){
    myAssembler.fixVertex(itv->first, 0, 1, itv->second);
  }

  simpleFunction<double> ONE(1.0);
  laplaceTerm l(0, 1, &ONE);

  for (unsigned int k = 0; k < _gf->triangles.size(); k++){
    MTriangle *t = _gf->triangles[k];
    myAssembler.numberVertex(t->getVertex(0), 0, 1);
    myAssembler.numberVertex(t->getVertex(1), 0, 1);
    myAssembler.numberVertex(t->getVertex(2), 0, 1); 
  }
  
  for (unsigned int k = 0; k < _gf->triangles.size(); k++){
    MTriangle *t = _gf->triangles[k];
    SElement se(t);
    l.addToMatrix(myAssembler, &se);    
  }
  _lsys->systemSolve();

  std::map<MVertex*,MVertex*>::iterator itv2 = _2Dto3D.begin();
  for ( ; itv2 != _2Dto3D.end(); ++itv2){
    MVertex *v_2D = itv2->first;
    MVertex *v_3D = itv2->second;
    myAssembler.getDofValue(v_3D, 0, 1, _sizes[v_2D]);
  }
  delete _lsys;
#endif
}

void backgroundMesh::updateSizes(GFace *_gf)
{
#if defined(HAVE_SOLVER)
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
  // return;
  // now do some diffusion

  std::list<GEdge*> e = _gf->edges();
  std::list<GEdge*>::const_iterator it = e.begin();

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
  
  // M (U^{t+1} - U^{t})/DT  + K U^{t+1} = 0 

  for( ; it != e.end(); ++it ){
    if (!(*it)->isSeam(_gf)){
      for(unsigned int i = 0; i < (*it)->lines.size(); i++ ){
        MVertex *v1 = (*it)->lines[i]->getVertex(0);
        MVertex *v2 = (*it)->lines[i]->getVertex(1);
        MVertex *v1_2D = _3Dto2D[ v1 ]; 
        MVertex *v2_2D = _3Dto2D[ v2 ]; 
        
        myAssembler.fixVertex(v1, 0, 1, _sizes[v1_2D]);
        myAssembler.fixVertex(v2, 0, 1, _sizes[v2_2D]);
      }
    }
  }

  double DT = 0.01;
  simpleFunction<double> ONEOVERDT(1.0/DT);
  simpleFunction<double> ONE(1.0);
  helmholtzTerm<double> diffusionTerm(0,1, 1, &ONE,&ONEOVERDT);
  helmholtzTerm<double> massTerm(0,1, 1, 0,&ONEOVERDT);

  for (unsigned int k= 0; k< _gf->triangles.size(); k++){
    MTriangle *t = _gf->triangles[k];
    myAssembler.numberVertex(t->getVertex(0), 0, 1);
    myAssembler.numberVertex(t->getVertex(1), 0, 1);
    myAssembler.numberVertex(t->getVertex(2), 0, 1); 
  }
  fullMatrix<double> mass_matrix(3,3);
  for (unsigned int k= 0; k< _gf->getNumMeshElements(); k++){
    MElement *e = _gf->getMeshElement(k);
    SElement se(e);
    diffusionTerm.addToMatrix(myAssembler, &se);  
    massTerm.elementMatrix(&se,mass_matrix);
    for (int i = 0; i < e->getNumVertices();i++){
      double TERM = 0.0;
      for (int j = 0; j < e->getNumVertices();j++){
        MVertex *v_2D = _3Dto2D[ e->getVertex(j) ];     
        TERM+=_sizes[v_2D] * mass_matrix(i,j);
      }
      myAssembler.assemble(e->getVertex(i),0,1,TERM);
    }
  }
  _lsys->systemSolve();

  std::map<MVertex*,MVertex*>::iterator itv2 = _2Dto3D.begin();
  for ( ; itv2 != _2Dto3D.end(); ++itv2){
    MVertex *v_2D = itv2->first;
    MVertex *v_3D = itv2->second;
    myAssembler.getDofValue(v_3D, 0, 1, _sizes[v_2D]);
  }
  delete _lsys;
#endif
}

double backgroundMesh::operator() (double u, double v, double w) const
{
  double uv[3] = {u, v, w};
  double uv2[3];
  //  return 1.0;
  MElement *e = (MElement*)Octree_Search(uv, _octree);
  if (!e) {
    Msg::Error("cannot find %g %g",u,v);
    return 1.0;
  }
  e->xyz2uvw (uv,uv2);
  std::map<MVertex*,double>::const_iterator itv1 = _sizes.find(e->getVertex(0));
  std::map<MVertex*,double>::const_iterator itv2 = _sizes.find(e->getVertex(1));
  std::map<MVertex*,double>::const_iterator itv3 = _sizes.find(e->getVertex(2));
  return itv1->second * (1-uv2[0]-uv2[1]) + itv2->second * uv2[0] + itv3->second * uv2[1];
}

void backgroundMesh::print (const std::string &filename, GFace *gf) const
{
  FILE *f = fopen (filename.c_str(),"w");
  fprintf(f,"View \"Background Mesh\"{\n");
  for(unsigned int i=0;i<_triangles.size();i++){
    MVertex *v1 = _triangles[i]->getVertex(0);
    MVertex *v2 = _triangles[i]->getVertex(1);
    MVertex *v3 = _triangles[i]->getVertex(2);
    std::map<MVertex*,double>::const_iterator itv1 = _sizes.find(v1);
    std::map<MVertex*,double>::const_iterator itv2 = _sizes.find(v2);
    std::map<MVertex*,double>::const_iterator itv3 = _sizes.find(v3);
    if (!gf){
      fprintf(f,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g) {%g,%g,%g};\n",
              v1->x(),v1->y(),v1->z(),
              v2->x(),v2->y(),v2->z(),
              v3->x(),v3->y(),v3->z(),itv1->second,itv2->second,itv3->second);
    }
    else {
      GPoint p1 = gf->point(SPoint2(v1->x(),v1->y()));
      GPoint p2 = gf->point(SPoint2(v2->x(),v2->y()));
      GPoint p3 = gf->point(SPoint2(v3->x(),v3->y()));
      fprintf(f,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g) {%g,%g,%g};\n",
              p1.x(),p1.y(),p1.z(),
              p2.x(),p2.y(),p2.z(),
              p3.x(),p3.y(),p3.z(),itv1->second,itv2->second,itv3->second);
    }

  }
  fprintf(f,"};\n");
  fclose(f);
}

backgroundMesh* backgroundMesh::_current = 0;
