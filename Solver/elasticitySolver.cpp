// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <string.h>
#include "GmshConfig.h"
#include "elasticitySolver.h"
#include "linearSystemCSR.h"
#include "linearSystemPETSc.h"
#include "linearSystemGMM.h"
#include "linearSystemFull.h"
#include "Numeric.h"
#include "GModel.h"
#include "functionSpace.h"
#include "terms.h"
#include "solverAlgorithms.h"
#include "quadratureRules.h"
#include "solverField.h"
#include "MPoint.h"
#include "DILevelset.h"
#if defined(HAVE_POST)
#include "PView.h"
#include "PViewData.h"
#include "function.h"
#endif

static void printLinearSystem(linearSystemCSRTaucs<double> *lsys)
{
  int *startIndex;
  int *columns;
  double *values;
  lsys->getMatrix(startIndex, columns, values);
  for(int i = 0; i < lsys->getNbUnk(); i++){
    std::cout<<"a ";
    for(int j = 0; j < lsys->getNbUnk(); j++){
      double val = 0.;
      for(int k = startIndex[i]; k < startIndex[i+1]; k++){
        if(columns[k] == j) {val = values[k]; break;}
      }
      std::cout<< val <<" ";
    }
    std::cout<<std::endl;
  }std::cout<<std::endl;
  for(int i = 0; i < lsys->getNbUnk(); i++) {
    double val; lsys->getFromRightHandSide(i,val);
    std::cout<<"b "<<val<<std::endl;
  }std::cout<<std::endl;
  for(int i = 0; i < lsys->getNbUnk(); i++) {
    double val; lsys->getFromSolution(i,val);
    std::cout<<"x "<<val<<std::endl;
  }
}

void elasticitySolver::setMesh(const std::string &meshFileName)
{
  pModel = new GModel();
  pModel->readMSH(meshFileName.c_str());
  _dim = pModel->getNumRegions() ? 3 : 2;

  if (LagSpace) delete LagSpace;
  if (_dim==3) LagSpace=new VectorLagrangeFunctionSpace(_tag);
  if (_dim==2) LagSpace=new VectorLagrangeFunctionSpace(_tag,VectorLagrangeFunctionSpace::VECTOR_X,VectorLagrangeFunctionSpace::VECTOR_Y);

  if (LagrangeMultiplierSpace) delete LagrangeMultiplierSpace;
  LagrangeMultiplierSpace = new ScalarLagrangeFunctionSpace(_tag+1);
}

void elasticitySolver::solve()
{
  
  //linearSystemFull<double> *lsys = new linearSystemFull<double>;
  
#if defined(HAVE_TAUCS)
  linearSystemCSRTaucs<double> *lsys = new linearSystemCSRTaucs<double>;
#elif defined(HAVE_PETSC)
  linearSystemPETSc<double> *lsys = new linearSystemPETSc<double>;
#else
  linearSystemGmm<double> *lsys = new linearSystemGmm<double>;
  lsys->setNoisy(2);
#endif

  assemble(lsys);
  lsys->systemSolve();
  printf("-- done solving!\n");
  GaussQuadrature Integ_Bulk(GaussQuadrature::GradGrad);

//   printLinearSystem(lsys);

  double energ=0;
  for (unsigned int i = 0; i < elasticFields.size(); i++)
  {
    SolverField<SVector3> Field(pAssembler, LagSpace);
    IsotropicElasticTerm Eterm(Field,elasticFields[i]._E,elasticFields[i]._nu);
    BilinearTermToScalarTerm<SVector3,SVector3> Elastic_Energy_Term(Eterm);
    Assemble(Elastic_Energy_Term,elasticFields[i].g->begin(),elasticFields[i].g->end(),Integ_Bulk,energ);
  }
  printf("elastic energy=%f\n",energ);
}

void elasticitySolver::postSolve()
{
  GaussQuadrature Integ_Bulk(GaussQuadrature::GradGrad);

  double energ=0;
  for (unsigned int i = 0; i < elasticFields.size(); i++)
  {
    SolverField<SVector3> Field(pAssembler, LagSpace);
    IsotropicElasticTerm Eterm(Field,elasticFields[i]._E,elasticFields[i]._nu);
    BilinearTermToScalarTerm<SVector3,SVector3> Elastic_Energy_Term(Eterm);
    Assemble(Elastic_Energy_Term,elasticFields[i].g->begin(),elasticFields[i].g->end(),Integ_Bulk,energ);
  }
  printf("elastic energy=%f\n",energ);
}

void elasticitySolver::readInputFile(const std::string &fn)
{
  FILE *f = fopen(fn.c_str(), "r");
  char what[256];
  while(!feof(f)){
    if(fscanf(f, "%s", what) != 1) return;
    if(what[0]=='#'){
      /*
      char *line=NULL;
      size_t l = 0;
      int r = getline(&line,&l,f);
      free(line);
      */
    }
    else if (!strcmp(what, "ElasticDomain")){
      elasticField field;
      int physical;
      if(fscanf(f, "%d %lf %lf", &physical, &field._E, &field._nu) != 3) return;
      field._tag = _tag;
      field.g = new groupOfElements (_dim, physical);
      elasticFields.push_back(field);
    }
    else if (!strcmp(what, "LagrangeMultipliers")){
      LagrangeMultiplierField field;
      int physical;
      double d1, d2, d3, val;
      if(fscanf(f, "%d %lf %lf %lf %lf %lf %d", &physical, &field._tau,
        &d1, &d2, &d3, &val, &field._tag) != 7) return;
      field._tag = _tag;
      field._d = SVector3(d1, d2, d3);
      field._f = simpleFunction<double>(val);
      field.g = new groupOfElements (_dim - 1, physical);
      LagrangeMultiplierFields.push_back(field);
    }
    else if (!strcmp(what, "Void")){
      elasticField field;
      int physical;
      if(fscanf(f, "%d", &physical) != 1) return;
      field._E = field._nu = 0;
      field.g = new groupOfElements (_dim, physical);
      field._tag = 0;
      elasticFields.push_back(field);
    }
    else if (!strcmp(what, "NodeDisplacement")){
      double val;
      int node, comp;
      if(fscanf(f, "%d %d %lf", &node, &comp, &val) != 3) return;
      dirichletBC diri;
      diri.g = new groupOfElements (0, node);
      diri._f= new simpleFunction<double>(val);
      diri._comp=comp;
      diri._tag=node;
      diri.onWhat=BoundaryCondition::ON_VERTEX;
      allDirichlet.push_back(diri);
    }
    else if (!strcmp(what, "EdgeDisplacement")){
      double val;
      int edge, comp;
      if(fscanf(f, "%d %d %lf", &edge, &comp, &val) != 3) return;
      dirichletBC diri;
      diri.g = new groupOfElements (1, edge);
      diri._f= new simpleFunction<double>(val);
      diri._comp=comp;
      diri._tag=edge;
      diri.onWhat=BoundaryCondition::ON_EDGE;
      allDirichlet.push_back(diri);
    }
    else if (!strcmp(what, "FaceDisplacement")){
      double val;
      int face, comp;
      if(fscanf(f, "%d %d %lf", &face, &comp, &val) != 3) return;
      dirichletBC diri;
      diri.g = new groupOfElements (2, face);
      diri._f= new simpleFunction<double>(val);
      diri._comp=comp;
      diri._tag=face;
      diri.onWhat=BoundaryCondition::ON_FACE;
      allDirichlet.push_back(diri);
    }
    else if (!strcmp(what, "NodeForce")){
      double val1, val2, val3;
      int node;
      if(fscanf(f, "%d %lf %lf %lf", &node, &val1, &val2, &val3) != 4) return;
      neumannBC neu;
      neu.g = new groupOfElements (0, node);
      neu._f= new simpleFunction<SVector3>(SVector3(val1, val2, val3));
      neu._tag=node;
      neu.onWhat=BoundaryCondition::ON_VERTEX;
      allNeumann.push_back(neu);
    }
    else if (!strcmp(what, "EdgeForce")){
      double val1, val2, val3;
      int edge;
      if(fscanf(f, "%d %lf %lf %lf", &edge, &val1, &val2, &val3) != 4) return;
      neumannBC neu;
      neu.g = new groupOfElements (1, edge);
      neu._f= new simpleFunction<SVector3>(SVector3(val1, val2, val3));
      neu._tag=edge;
      neu.onWhat=BoundaryCondition::ON_EDGE;
      allNeumann.push_back(neu);
    }
    else if (!strcmp(what, "FaceForce")){
      double val1, val2, val3;
      int face;
      if(fscanf(f, "%d %lf %lf %lf", &face, &val1, &val2, &val3) != 4) return;
      neumannBC neu;
      neu.g = new groupOfElements (2, face);
      neu._f= new simpleFunction<SVector3>(SVector3(val1, val2, val3));
      neu._tag=face;
      neu.onWhat=BoundaryCondition::ON_FACE;
      allNeumann.push_back(neu);
    }
    else if (!strcmp(what, "VolumeForce")){
      double val1, val2, val3;
      int volume;
      if(fscanf(f, "%d %lf %lf %lf", &volume, &val1, &val2, &val3) != 4) return;
      neumannBC neu;
      neu.g = new groupOfElements (3, volume);
      neu._f= new simpleFunction<SVector3>(SVector3(val1, val2, val3));
      neu._tag=volume;
      neu.onWhat=BoundaryCondition::ON_VOLUME;
      allNeumann.push_back(neu);
    }
    else if (!strcmp(what, "MeshFile")){
      char name[245];
      if(fscanf(f, "%s", name) != 1) return;
      setMesh(name);
    }
    else if (!strcmp(what, "CutMeshPlane")){
      double a, b, c, d;
      if(fscanf(f, "%lf %lf %lf %lf", &a, &b, &c, &d) != 4) return;
      int tag=1;
      gLevelsetPlane ls(a,b,c,d,tag);
      pModel = pModel->buildCutGModel(&ls);
    }
    else if (!strcmp(what, "CutMeshSphere")){
      double x, y, z, r;
      if(fscanf(f, "%lf %lf %lf %lf", &x, &y, &z, &r) != 4) return;
      int tag=1;
      gLevelsetSphere ls(x,y,z,r,tag);
      pModel = pModel->buildCutGModel(&ls);
    }
    else {
      Msg::Error("Invalid input : '%s'", what);
//      return;
    }
  }
  fclose(f);
}


#if defined (HAVE_LUA)

void elasticitySolver::addDirichletBCLua (int dim, int entityId, int component, std::string luaFunctionName, lua_State *L) {
  dirichletBC diri;
  diri.g = new groupOfElements (dim, entityId);
  diri._f= new simpleFunctionLua<double>(L, luaFunctionName,0.);
  diri._comp=component;
  diri._tag=entityId;
  switch (dim) {
    case 0 : diri.onWhat=BoundaryCondition::ON_VERTEX; break;
    case 1 : diri.onWhat=BoundaryCondition::ON_EDGE; break;
    case 2 : diri.onWhat=BoundaryCondition::ON_FACE; break;
    default : return;
  }
  allDirichlet.push_back(diri);
}

void elasticitySolver::addNeumannBCLua (int dim, int entityId, std::string luaFunctionName, lua_State *L) {
  neumannBC neu;
  neu.g = new groupOfElements (dim, entityId);
  neu._f= new simpleFunctionLua<SVector3>(L, luaFunctionName, SVector3(0,0,0));
  neu._tag=entityId;
  switch (dim) {
    case 0 : neu.onWhat=BoundaryCondition::ON_VERTEX; break;
    case 1 : neu.onWhat=BoundaryCondition::ON_EDGE; break;
    case 2 : neu.onWhat=BoundaryCondition::ON_FACE; break;
    default : return;
  }
  allNeumann.push_back(neu);
}

#endif

void elasticitySolver::addDirichletBC (int dim, int entityId, int component, double value) {
  dirichletBC diri;
  diri.g = new groupOfElements (dim, entityId);
  diri._f= new simpleFunction<double>(value);
  diri._comp=component;
  diri._tag=entityId;
  switch (dim) {
    case 0 : diri.onWhat=BoundaryCondition::ON_VERTEX; break;
    case 1 : diri.onWhat=BoundaryCondition::ON_EDGE; break;
    case 2 : diri.onWhat=BoundaryCondition::ON_FACE; break;
    default : return;
  }
  allDirichlet.push_back(diri);
}


void elasticitySolver::addNeumannBC (int dim, int entityId, const std::vector<double> value) {
  if(value.size()!=3) return;
  neumannBC neu;
  neu.g = new groupOfElements (dim, entityId);
  neu._f= new simpleFunction<SVector3>(SVector3(value[0], value[1], value[2]));
  neu._tag=entityId;
  switch (dim) {
    case 0 : neu.onWhat=BoundaryCondition::ON_VERTEX; break;
    case 1 : neu.onWhat=BoundaryCondition::ON_EDGE; break;
    case 2 : neu.onWhat=BoundaryCondition::ON_FACE; break;
    default : return;
  }
  allNeumann.push_back(neu);
}



void elasticitySolver::addElasticDomain (int physical, double e, double nu){
  elasticField field;
  field._tag = _tag;
  field._E = e;
  field._nu = nu;
  field.g = new groupOfElements (_dim, physical);
  elasticFields.push_back(field);
}

elasticitySolver::elasticitySolver(GModel *model, int tag)
{
  pModel = model;
  _dim = pModel->getNumRegions() ? 3 : 2;
  _tag = tag;
  pAssembler = NULL;
  if (_dim==3) LagSpace=new VectorLagrangeFunctionSpace(_tag);
  if (_dim==2) LagSpace=new VectorLagrangeFunctionSpace(_tag,VectorLagrangeFunctionSpace::VECTOR_X,VectorLagrangeFunctionSpace::VECTOR_Y);
  LagrangeMultiplierSpace = new ScalarLagrangeFunctionSpace(_tag+1);
}

void elasticitySolver::assemble(linearSystem<double> *lsys)
{
  if (pAssembler) delete pAssembler;
  pAssembler = new dofManager<double>(lsys);

  // we first do all fixations. the behavior of the dofManager is to
  // give priority to fixations : when a dof is fixed, it cannot be
  // numbered afterwards

  // Dirichlet conditions
  for (unsigned int i = 0; i < allDirichlet.size(); i++)
  {
    FilterDofComponent filter(allDirichlet[i]._comp);
    FixNodalDofs(*LagSpace,allDirichlet[i].g->begin(),allDirichlet[i].g->end(),*pAssembler,*allDirichlet[i]._f,filter);
  }
  // LagrangeMultipliers
  for (unsigned int i = 0; i < LagrangeMultiplierFields.size(); ++i)
  {
    NumberDofs(*LagrangeMultiplierSpace, LagrangeMultiplierFields[i].g->begin(), LagrangeMultiplierFields[i].g->end(), *pAssembler);
  }
  // Elastic Fields
  for (unsigned int i = 0; i < elasticFields.size(); ++i)
  {
    if(elasticFields[i]._E != 0.)
      NumberDofs(*LagSpace, elasticFields[i].g->begin(), elasticFields[i].g->end(),*pAssembler);
  }
  // Voids
  for (unsigned int i = 0; i < elasticFields.size(); ++i)
  {
    if(elasticFields[i]._E == 0.)
      FixVoidNodalDofs(*LagSpace, elasticFields[i].g->begin(), elasticFields[i].g->end(), *pAssembler);
  }
  // Neumann conditions
  GaussQuadrature Integ_Boundary(GaussQuadrature::Val);
  std::cout <<  "Neumann BC"<< std::endl;
  for (unsigned int i = 0; i < allNeumann.size(); i++)
  {
    LoadTerm<SVector3> Lterm(*LagSpace,*allNeumann[i]._f);
    Assemble(Lterm,*LagSpace,allNeumann[i].g->begin(),allNeumann[i].g->end(),Integ_Boundary,*pAssembler);
  }
  // Assemble cross term, laplace term and rhs term for LM
  GaussQuadrature Integ_LagrangeMult(GaussQuadrature::ValVal);
  GaussQuadrature Integ_Laplace(GaussQuadrature::GradGrad);
  for (unsigned int i = 0; i < LagrangeMultiplierFields.size(); i++)
  {
    LagrangeMultiplierTerm LagTerm(*LagSpace, *LagrangeMultiplierSpace, LagrangeMultiplierFields[i]._d);
    Assemble(LagTerm, *LagSpace, *LagrangeMultiplierSpace,
             LagrangeMultiplierFields[i].g->begin(), LagrangeMultiplierFields[i].g->end(), Integ_LagrangeMult, *pAssembler);

    LaplaceTerm<double,double> LapTerm(*LagrangeMultiplierSpace, LagrangeMultiplierFields[i]._tau);
    Assemble(LapTerm, *LagrangeMultiplierSpace, LagrangeMultiplierFields[i].g->begin(), LagrangeMultiplierFields[i].g->end(), Integ_Laplace, *pAssembler);

    LoadTerm<double> Lterm(*LagrangeMultiplierSpace, LagrangeMultiplierFields[i]._f);
    Assemble(Lterm, *LagrangeMultiplierSpace, LagrangeMultiplierFields[i].g->begin(), LagrangeMultiplierFields[i].g->end(), Integ_Boundary, *pAssembler);
  }
  // Assemble elastic term for
  GaussQuadrature Integ_Bulk(GaussQuadrature::GradGrad);
  for (unsigned int i = 0; i < elasticFields.size(); i++)
  {
    IsotropicElasticTerm Eterm(*LagSpace,elasticFields[i]._E,elasticFields[i]._nu);
    Assemble(Eterm,*LagSpace,elasticFields[i].g->begin(),elasticFields[i].g->end(),Integ_Bulk,*pAssembler);
  }

  /*for (int i=0;i<pAssembler->sizeOfR();i++){
    for (int j=0;j<pAssembler->sizeOfR();j++){
      double d;lsys->getFromMatrix(i,j,d);
      printf("%12.5E ",d);
    }
    double d;lsys->getFromRightHandSide(i,d);
    printf(" |  %12.5E\n",d);
  }*/

  printf("nDofs=%d\n",pAssembler->sizeOfR());
  printf("nFixed=%d\n",pAssembler->sizeOfF());

}


#if defined(HAVE_POST)
static void deformation(dofManager<double> *a, MElement *e,
			double u, double v, double w, int _tag, double *eps){
  double valx[256];
  double valy[256];
  double valz[256];
  for (int k = 0; k < e->getNumVertices(); k++){
    a->getDofValue(e->getVertex(k), 0, _tag, valx[k]);
    a->getDofValue(e->getVertex(k), 1, _tag, valy[k]);
    a->getDofValue(e->getVertex(k), 2, _tag, valz[k]);
  }
  double gradux[3];
  double graduy[3];
  double graduz[3];
  e->interpolateGrad(valx, u, v, w, gradux);
  e->interpolateGrad(valy, u, v, w, graduy);
  e->interpolateGrad(valz, u, v, w, graduz);

  eps[0] = gradux[0];
  eps[1] = graduy[1];
  eps[2] = graduz[2];
  eps[3] = 0.5 * (gradux[1] + graduy[0]);
  eps[4] = 0.5 * (gradux[2] + graduz[0]);
  eps[5] = 0.5 * (graduy[2] + graduz[1]);
}

static double vonMises(dofManager<double> *a, MElement *e,
                       double u, double v, double w,
                       double E, double nu, int _tag){
  
  double valx[256];
  double valy[256];
  double valz[256];
  for (int k = 0; k < e->getNumVertices(); k++){
    a->getDofValue(e->getVertex(k), 0, _tag, valx[k]);
    a->getDofValue(e->getVertex(k), 1, _tag, valy[k]);
    a->getDofValue(e->getVertex(k), 2, _tag, valz[k]);
  }
  double gradux[3];
  double graduy[3];
  double graduz[3];
  e->interpolateGrad(valx, u, v, w, gradux);
  e->interpolateGrad(valy, u, v, w, graduy);
  e->interpolateGrad(valz, u, v, w, graduz);

  double eps[6] = {gradux[0], graduy[1], graduz[2],
                   0.5 * (gradux[1] + graduy[0]),
                   0.5 * (gradux[2] + graduz[0]),
                   0.5 * (graduy[2] + graduz[1])};
  double A = E / (1. + nu);
  double B = A * (nu / (1. - 2 * nu));
  double trace = eps[0] + eps[1] + eps[2] ;
  double sxx = A * eps[0] + B * trace;
  double syy = A * eps[1] + B * trace;
  double szz = A * eps[2] + B * trace;
  double sxy = A * eps[3];
  double sxz = A * eps[4];
  double syz = A * eps[5];

  double s[9] = {sxx, sxy, sxz, sxy, syy, syz,sxz, syz, szz};

  return ComputeVonMises(s);
}

void elasticitySolver::getSolutionOnElement (MElement *el, fullMatrix<double> &sol) {

}

PView* elasticitySolver::buildDisplacementView (const std::string postFileName)
{
  std::cout <<  "build Displacement View"<< std::endl;
  std::set<MVertex*> v;
  std::map<MVertex*,MElement*> vCut;
  for (unsigned int i = 0; i < elasticFields.size(); ++i)
  {
    if(elasticFields[i]._E == 0.) continue;
    for (groupOfElements::elementContainer::const_iterator it = elasticFields[i].g->begin(); it != elasticFields[i].g->end(); ++it){
      MElement *e=*it;
      if(e->getParent()) {
        for (int j = 0; j < e->getNumVertices(); ++j) {
          if(vCut.find(e->getVertex(j)) == vCut.end())
            vCut[e->getVertex(j)] = e->getParent();
        }
      }
      else {
        for (int j = 0; j < e->getNumVertices(); ++j)
          v.insert(e->getVertex(j));
      }
    }
  }
  std::map<int, std::vector<double> > data;
  SolverField<SVector3> Field(pAssembler, LagSpace);
  for (std::set<MVertex*>::iterator it = v.begin(); it != v.end(); ++it){
    SVector3 val;
    MPoint p(*it);
    Field.f(&p,0,0,0,val);
    std::vector<double> vec(3);vec[0]=val(0);vec[1]=val(1);vec[2]=val(2);
    data[(*it)->getNum()]=vec;
  }
  for (std::map<MVertex*,MElement*>::iterator it = vCut.begin(); it != vCut.end(); ++it){
    SVector3 val;
    double uvw[3];
    double xyz[3] = {it->first->x(), it->first->y(), it->first->z()};
    it->second->xyz2uvw(xyz, uvw);
    Field.f(it->second,uvw[0],uvw[1],uvw[2],val);
    std::vector<double> vec(3);vec[0]=val(0);vec[1]=val(1);vec[2]=val(2);
    data[it->first->getNum()]=vec;
  }
  PView *pv = new PView (postFileName, "NodeData", pModel, data, 0.0);
  return pv;
}

PView* elasticitySolver::buildStressesView (const std::string postFileName)
{
  std::cout <<  "build stresses view"<< std::endl;
  std::map<int, std::vector<double> > data;
  GaussQuadrature Integ_Bulk(GaussQuadrature::GradGrad);
  for (unsigned int i = 0; i < elasticFields.size(); ++i)
  {
    double E = elasticFields[i]._E;
    double nu = elasticFields[i]._nu;
    SolverField<SVector3> Field(pAssembler, LagSpace);
    IsotropicElasticTerm Eterm(Field,elasticFields[i]._E,elasticFields[i]._nu);
    BilinearTermToScalarTerm<SVector3,SVector3> Elastic_Energy_Term(Eterm);
    for (groupOfElements::elementContainer::const_iterator it = elasticFields[i].g->begin(); it != elasticFields[i].g->end(); ++it)
    {
      MElement *e=*it;
      int nbVertex = e->getNumVertices();
      std::vector<SVector3> val(nbVertex);
   
      double valx[256];
      double valy[256];
      double valz[256];
      for (int k = 0; k < nbVertex; k++){
	MVertex *v = e->getVertex(k);
	MPoint p(v);
	Field.f(&p,0,0,0,val[k]);
	valx[k] =val[k](0);
	valy[k] =val[k](1);
	valz[k] =val[k](2);
      }
    
      double gradux[3];
      double graduy[3];
      double graduz[3];
      double u=0.33, v=0.33, w=0.0;
      e->interpolateGrad(valx, u, v, w, gradux);
      e->interpolateGrad(valy, u, v, w, graduy);
      e->interpolateGrad(valz, u, v, w, graduz);

      double eps[6] = {gradux[0], graduy[1], graduz[2],
		       0.5 * (gradux[1] + graduy[0]),
		       0.5 * (gradux[2] + graduz[0]),
		       0.5 * (graduy[2] + graduz[1])};
      

      double A = E / (1. + nu);
      double B = A * (nu / (1. - 2 * nu));
      double trace = eps[0] + eps[1] + eps[2] ;
      double sxx = A * eps[0] + B * trace;
      double syy = A * eps[1] + B * trace;
      double szz = A * eps[2] + B * trace;
      double sxy = A * eps[3];
      double sxz = A * eps[4];
      double syz = A * eps[5];

      std::vector<double> vec(9);
      vec[0]=sxx; vec[1]=sxy; vec[2]=sxz; vec[3]=sxy; vec[4]=syy; vec[5]=syz; vec[6]=sxz; vec[7]=syz; vec[8]=szz;
     
      data[e->getNum()]=vec;
    }
  }
  PView *pv = new PView (postFileName, "ElementData", pModel, data, 0.0);
  return pv;

}

PView* elasticitySolver::buildLagrangeMultiplierView (const std::string postFileName)
{
  std::cout <<  "build Lagrange Multiplier View"<< std::endl;
  if(!LagrangeMultiplierSpace) return new PView();
  std::set<MVertex*> v;
  for (unsigned int i = 0; i < LagrangeMultiplierFields.size(); ++i)
  {
    for(groupOfElements::elementContainer::const_iterator it = LagrangeMultiplierFields[i].g->begin(); it != LagrangeMultiplierFields[i].g->end(); ++it)
    {
      MElement *e = *it;
      for (int j = 0; j < e->getNumVertices(); ++j) v.insert(e->getVertex(j));
    }
  }
  std::map<int, std::vector<double> > data;
  SolverField<double> Field(pAssembler, LagrangeMultiplierSpace);
  for(std::set<MVertex*>::iterator it = v.begin(); it != v.end(); ++it)
  {
    double val;
    MPoint p(*it);
    Field.f(&p, 0, 0, 0, val);
    std::vector<double> vec;
    vec.push_back(val);
    data[(*it)->getNum()] = vec;
  }
  PView *pv = new PView (postFileName, "NodeData", pModel, data, 0.0);
  return pv;
}


PView *elasticitySolver::buildElasticEnergyView(const std::string postFileName)
{
  std::cout <<  "build Elastic Energy View"<< std::endl;
  std::map<int, std::vector<double> > data;
  GaussQuadrature Integ_Bulk(GaussQuadrature::GradGrad);
  for (unsigned int i = 0; i < elasticFields.size(); ++i)
  {
    if(elasticFields[i]._E == 0.) continue;
    SolverField<SVector3> Field(pAssembler, LagSpace);
    IsotropicElasticTerm Eterm(Field,elasticFields[i]._E,elasticFields[i]._nu);
    BilinearTermToScalarTerm<SVector3,SVector3> Elastic_Energy_Term(Eterm);
    ScalarTermConstant One(1.0);
    for (groupOfElements::elementContainer::const_iterator it = elasticFields[i].g->begin(); it != elasticFields[i].g->end(); ++it)
    {
      MElement *e = *it;
      double energ;
      double vol;
      IntPt *GP;
      int npts=Integ_Bulk.getIntPoints(e,&GP);
      Elastic_Energy_Term.get(e,npts,GP,energ);
      One.get(e,npts,GP,vol);
      std::vector<double> vec;
      vec.push_back(energ/vol);
      data[e->getNum()]=vec;
    }
  }
  PView *pv = new PView (postFileName, "ElementData", pModel, data, 0.0);
  return pv;
}

PView *elasticitySolver::buildVonMisesView(const std::string postFileName)
{
  std::cout <<  "build elastic view"<< std::endl;
  std::map<int, std::vector<double> > data;
  GaussQuadrature Integ_Bulk(GaussQuadrature::GradGrad);
  for (unsigned int i = 0; i < elasticFields.size(); ++i)
  {
    SolverField<SVector3> Field(pAssembler, LagSpace);
    IsotropicElasticTerm Eterm(Field,elasticFields[i]._E,elasticFields[i]._nu);
    BilinearTermToScalarTerm<SVector3,SVector3> Elastic_Energy_Term(Eterm);
    for (groupOfElements::elementContainer::const_iterator it = elasticFields[i].g->begin(); it != elasticFields[i].g->end(); ++it)
    {
      MElement *e=*it;
      double energ;
      IntPt *GP;
      int npts=Integ_Bulk.getIntPoints(e,&GP);
      Elastic_Energy_Term.get(e,npts,GP,energ);
      std::vector<double> vec;
      vec.push_back(energ);
      data[(*it)->getNum()]=vec;
    }
  }
  PView *pv = new PView (postFileName, "ElementData", pModel, data, 0.0);
  return pv;
}


#else
PView* elasticitySolver::buildDisplacementView(const std::string postFileName)
{
  Msg::Error("Post-pro module not available");
  return 0;
}

PView* elasticitySolver::buildLagrangeMultiplierView (const std::string postFileName)
{
  Msg::Error("Post-pro module not available");
  return 0;
}

PView* elasticitySolver::buildElasticEnergyView(const std::string postFileName)
{
  Msg::Error("Post-pro module not available");
  return 0;
}

PView* elasticitySolver::buildVonMisesView(const std::string postFileName)
{
  Msg::Error("Post-pro module not available");
  return 0;
}
#endif


#if defined (HAVE_LUA)

#include "Bindings.h"
void elasticitySolverRegisterBindings(binding *b)
{
  classBinding *cb;
  cb = b->addClass<elasticitySolver> ("elasticitySolver");
  cb->setDescription("A class that enables to solve elasticity problems");

  methodBinding *cm;
  cm = cb->addMethod("read", &elasticitySolver::read);
  cm->setDescription ("reads an input file");
  cm->setArgNames("fileName",NULL);

  cm = cb->addMethod("postSolve", &elasticitySolver::postSolve);
  cm->setDescription (" ");

  cm = cb->addMethod("assemble", &elasticitySolver::assemble);
  cm->setDescription ("assembles the problem");
  cm->setArgNames ("linearSystem",NULL);

  cm = cb->addMethod("solve", &elasticitySolver::solve);
  cm->setDescription ("solve the problem");
  cm->setArgNames (NULL);

  cm = cb->addMethod("addDirichletBC", &elasticitySolver::addDirichletBC);
  cm->setDescription ("add a Dirichlet (displacement) boundary condition on a given entity");
  cm->setArgNames ("dim", "entityId", "component", "value", NULL);

  cm = cb->addMethod("addDirichletBCLua", &elasticitySolver::addDirichletBCLua);
  cm->setDescription ("add a Dirichlet (displacement) boundary condition on a given entity. The lua function takes x,y,z as arguments and return the displacement value.");
  cm->setArgNames ("dim", "entityId", "component", "luaFunctionName", NULL);

  cm = cb->addMethod("addNeumannBC", &elasticitySolver::addNeumannBC);
  cm->setDescription ("add a Neumann (force) boundary condition on a given entity. Size of value has to be 3.");
  cm->setArgNames ("dim", "entityId", "value", NULL);

  cm = cb->addMethod("addNeumannBCLua", &elasticitySolver::addNeumannBCLua);
  cm->setDescription ("add a Neumann (force) boundary condition on a given entity. The lua function takes x,y,z as arguments and return a vector with the 3 components of the force.");
  cm->setArgNames ("dim", "entityId", "luaFunctionName", NULL);

  cm = cb->addMethod("addElasticDomain", &elasticitySolver::addElasticDomain);
  cm->setDescription ("add an elastic region with parameters E and nu");
  cm->setArgNames ("tag", "E", "nu", NULL);

#if defined HAVE_POST

  cm = cb->addMethod ("buildVonMisesView", &elasticitySolver::buildVonMisesView);
  cm->setDescription ("create a new view.");
  cm->setArgNames ("fileName", NULL);

  cm = cb->addMethod ("buildDisplacementView", &elasticitySolver::buildDisplacementView);
  cm->setDescription ("create a new view.");
  cm->setArgNames ("fileName", NULL);

  cm = cb->addMethod ("buildStressesView", &elasticitySolver::buildStressesView);
  cm->setDescription ("create a new view.");
  cm->setArgNames ("fileName", NULL);

  cm = cb->addMethod ("buildLagrangeMultiplierView", &elasticitySolver::buildLagrangeMultiplierView);
  cm->setDescription ("create a new view.");
  cm->setArgNames ("fileName", NULL);

  cm = cb->addMethod ("buildElasticEnergyView", &elasticitySolver::buildElasticEnergyView);
  cm->setDescription ("create a new view.");
  cm->setArgNames ("fileName", NULL);

#endif

  cm = cb->setConstructor<elasticitySolver,GModel*,int>();
  cm->setDescription ("A new elasticitySolver. The parameter is the unknowns tag");
  cm->setArgNames("model","tag",NULL);
}

#endif
