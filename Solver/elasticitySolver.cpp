// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <string.h>
#include "GmshConfig.h"
#include "elasticityTerm.h"
#include "MTriangle.h"
#include "MTetrahedron.h"
#include "elasticitySolver.h"
#include "linearSystemCSR.h"
#include "linearSystemPETSc.h"
#include "linearSystemGMM.h"
#include "Numeric.h"

#if !defined(HAVE_NO_POST)
#include "PView.h"
#include "PViewData.h"

PView* elasticitySolver::buildDisplacementView (const std::string &postFileName){
  std::map<int, std::vector<double> > data;
  std::set<MVertex*> v;
  for (int i = 0; i < elasticFields.size(); ++i){
    groupOfElements::elementContainer::const_iterator it = elasticFields[i].g->begin();
    for ( ; it != elasticFields[i].g->end(); ++it){
      SElement se(*it);
      for (int j = 0; j < se.getNumNodalShapeFunctions(); ++j){
        v.insert(se.getVertex(j));
      }
    }
  }

  std::set<MVertex*>::iterator it = v.begin();
  for ( ; it != v.end(); ++it){
    std::vector<double> d;
    d.push_back(0); d.push_back(0); d.push_back(0);
    for (int i = 0; i < elasticFields.size(); ++i){
      const double E = (elasticFields[i]._enrichment) ?
                       (*elasticFields[i]._enrichment)((*it)->x(), (*it)->y(), (*it)->z()) : 1.0;	
      //      printf("%g %d \n",pAssembler->getDofValue(*it,0,elasticFields[i]._tag),elasticFields[i]._tag);
      d[0] += pAssembler->getDofValue(*it, 0, elasticFields[i]._tag) * E;
      d[1] += pAssembler->getDofValue(*it, 1, elasticFields[i]._tag) * E;
      d[2] += pAssembler->getDofValue(*it, 2, elasticFields[i]._tag) * E;
    }
    data[(*it)->getNum()] = d;
  }

  PView *pv = new PView (postFileName, "NodeData", pModel, data, 0.0);
  return pv;  
}

#else
PView* elasticitySolver::buildDisplacementView  (const std::string &postFileName)
{
  Msg::Error("Post-pro module not available");
  return 0;
}
#endif


static double vonMises(dofManager<double,double> *a, MElement *e, 
                       double u, double v, double w, 
                       double E, double nu, int _tag)
{
  double valx[256];
  double valy[256];
  double valz[256];
  for (int k = 0; k < e->getNumVertices(); k++){
    valx[k] = a->getDofValue(e->getVertex(k), 0, _tag);
    valy[k] = a->getDofValue(e->getVertex(k), 1, _tag);
    valz[k] = a->getDofValue(e->getVertex(k), 2, _tag);
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

  double s[9] = {sxx, sxy, sxz,
                 sxy, syy, syz,
                 sxz, syz, szz};

  return ComputeVonMises(s);
}

void elasticitySolver::setMesh(const std::string &meshFileName)
{
  pModel = new GModel();
  pModel->readMSH(meshFileName.c_str());
  _dim = pModel->getNumRegions() ? 3 : 2;
}

void elasticitySolver::readInputFile(const std::string &fn)
{
  FILE *f = fopen(fn.c_str(), "r");
  char what[256];
  while(!feof(f)){
    if(fscanf(f, "%s", what) != 1) return;
    // printf("%s\n", what);
    if (!strcmp(what, "ElasticDomain")){
      elasticField field;
      int physical;
      if(fscanf(f, "%d %lf %lf", &physical, &field._E, &field._nu) != 3) return;
      field._tag = _tag;
      //      printf("E %g nu %g\n",field._E,field._nu);
      field.g = new groupOfElements (_dim, physical);
      elasticFields.push_back(field);
    }
    else if (!strcmp(what, "Void")){
      //      elasticField field;
      //      create enrichment ...
      //      create the group ...
      //      assign a tag
      //      elasticFields.push_back(field);
    }
    else if (!strcmp(what, "NodalDisplacement")){
      double val;
      int node, comp;
      if(fscanf(f, "%d %d %lf", &node, &comp, &val) != 3) return;
      nodalDisplacements[ std::make_pair(node, comp) ] = val;    
    }
    else if (!strcmp(what, "EdgeDisplacement")){
      double val;
      int edge, comp;
      if(fscanf(f, "%d %d %lf", &edge, &comp, &val) != 3) return;
      edgeDisplacements[ std::make_pair(edge, comp) ] = val;    
    }
    else if (!strcmp(what, "FaceDisplacement")){
      double val;
      int face, comp;
      if(fscanf(f, "%d %d %lf", &face, &comp, &val) != 3) return;
      faceDisplacements[ std::make_pair(face, comp) ] = val;    
    }
    else if (!strcmp(what, "NodalForce")){
      double val1, val2, val3;
      int node;
      if(fscanf(f, "%d %lf %lf %lf", &node, &val1, &val2, &val3) != 4) return;
      nodalForces[node] = SVector3(val1, val2, val3);    
    }
    else if (!strcmp(what, "LineForce")){
      double val1, val2, val3;
      int node;
      if(fscanf(f, "%d %lf %lf %lf", &node, &val1, &val2, &val3) != 4) return;
      //printf("%d %lf %lf %lf\n", node, val1, val2, val3);
      lineForces[node] = SVector3(val1, val2, val3);    
    }
    else if (!strcmp(what, "FaceForce")){
      double val1, val2, val3;
      int face;
      if(fscanf(f, "%d %lf %lf %lf", &face, &val1, &val2, &val3) != 4) return;
      faceForces[face] = SVector3(val1, val2, val3);    
    }
    else if (!strcmp(what, "VolumeForce")){
      double val1, val2, val3;
      int volume;
      if(fscanf(f, "%d %lf %lf %lf", &volume, &val1, &val2, &val3) != 4) return;
      volumeForces[volume] = SVector3(val1, val2, val3);    
    }
    else if (!strcmp(what, "MeshFile")){
      char name[245];
      if(fscanf(f, "%s", name) != 1) return;
      setMesh(name);
    }
    else {
      Msg::Error("Invalid input : %s", what);
      return;
    }
  }
  fclose(f);
}

void elasticitySolver::solve()
{
#if defined(HAVE_TAUCS)
  linearSystemCSRTaucs<double> *lsys = new linearSystemCSRTaucs<double>;
#elif defined(HAVE_PETSC)
  linearSystemPETSc<double> *lsys = new linearSystemPETSc<double>;
#else
  linearSystemGmm<double> *lsys = new linearSystemGmm<double>;
  lsys->setNoisy(2);
#endif
  pAssembler = new dofManager<double, double>(lsys);

  std::map<int, std::vector<GEntity*> > groups[4];
  pModel->getPhysicalGroups(groups);

  // we first do all fixations. the behavior of the dofManager is to 
  // give priority to fixations : when a dof is fixed, it cannot be
  // numbered afterwards

  for (std::map<std::pair<int, int>, double>::iterator it = nodalDisplacements.begin();
       it != nodalDisplacements.end(); ++it){
    MVertex *v = pModel->getMeshVertexByTag(it->first.first);
    pAssembler->fixVertex(v, it->first.second, _tag, it->second);
    printf("-- Fixing node %3d comp %1d to %8.5f\n",
           it->first.first, it->first.second, it->second);
  }

  for (std::map<std::pair<int, int>, double>::iterator it = edgeDisplacements.begin();
       it != edgeDisplacements.end(); ++it){
    elasticityTerm El(pModel, 1, 1, _tag);
    El.dirichletNodalBC(it->first.first, 1, it->first.second, _tag,
                        simpleFunction<double>(it->second), *pAssembler);
    printf("-- Fixing edge %3d comp %1d to %8.5f\n",
           it->first.first, it->first.second, it->second);
  }

  for (std::map<std::pair<int, int>, double>::iterator it = faceDisplacements.begin();
       it != faceDisplacements.end(); ++it){
    elasticityTerm El(pModel, 1, 1, _tag);
    El.dirichletNodalBC(it->first.first, 2, it->first.second, _tag,
                        simpleFunction<double>(it->second), *pAssembler);
    printf("-- Fixing face %3d comp %1d to %8.5f\n",
           it->first.first, it->first.second, it->second);
  }

  // we number the nodes : when a node is numbered, it cannot be numbered
  // again with another number. so we loop over elements
  for (int i = 0; i < elasticFields.size(); ++i){
    groupOfElements::elementContainer::const_iterator it = elasticFields[i].g->begin();
    for ( ; it != elasticFields[i].g->end(); ++it){
      SElement se(*it);
      for (int j = 0; j < se.getNumNodalShapeFunctions(); ++j){
        pAssembler->numberVertex(se.getVertex(j), 0, elasticFields[i]._tag);
        pAssembler->numberVertex(se.getVertex(j), 1, elasticFields[i]._tag);
        pAssembler->numberVertex(se.getVertex(j), 2, elasticFields[i]._tag);	
      }
    }
  }

  // Now we start the assembly process
  // First build the force vector
  // Nodes at geometrical vertices
  for (std::map<int, SVector3 >::iterator it = nodalForces.begin();
       it != nodalForces.end(); ++it){
    int iVertex = it->first;
    SVector3 f = it->second;
    std::vector<GEntity*> ent = groups[0][iVertex];
    for (unsigned int i = 0; i < ent.size(); i++){
      pAssembler->assemble(ent[i]->mesh_vertices[0], 0, _tag, f.x());
      pAssembler->assemble(ent[i]->mesh_vertices[0], 1, _tag, f.y());
      pAssembler->assemble(ent[i]->mesh_vertices[0], 2, _tag, f.z());
      printf("-- Force on node %3d(%3d) : %8.5f %8.5f %8.5f\n",
             ent[i]->mesh_vertices[0]->getNum(), iVertex, f.x(), f.y(), f.z());
    }
  }

  // line forces
  for (std::map<int, SVector3 >::iterator it = lineForces.begin();
       it != lineForces.end(); ++it){
    elasticityTerm El(pModel, 1, 1, _tag);
    int iEdge = it->first;
    SVector3 f = it->second;
    El.neumannNodalBC(iEdge, 1, 0, _tag, simpleFunction<double>(f.x()), *pAssembler);
    El.neumannNodalBC(iEdge, 1, 1, _tag, simpleFunction<double>(f.y()), *pAssembler);
    El.neumannNodalBC(iEdge, 1, 2, _tag, simpleFunction<double>(f.z()), *pAssembler);
    printf("-- Force on edge %3d : %8.5f %8.5f %8.5f\n", iEdge, f.x(), f.y(), f.z());
  }

  // face forces
  for (std::map<int, SVector3 >::iterator it = faceForces.begin();
       it != faceForces.end(); ++it){
    elasticityTerm El(pModel, 1, 1, _tag);
    int iFace = it->first;
    SVector3 f = it->second;
    El.neumannNodalBC(iFace, 2, 0, _tag, simpleFunction<double>(f.x()), *pAssembler);
    El.neumannNodalBC(iFace, 2, 1, _tag, simpleFunction<double>(f.y()), *pAssembler);
    El.neumannNodalBC(iFace, 2, 2, _tag, simpleFunction<double>(f.z()), *pAssembler);
    printf("-- Force on face %3d : %8.5f %8.5f %8.5f\n", iFace, f.x(), f.y(), f.z());
  }

  // volume forces
  for (std::map<int, SVector3 >::iterator it = volumeForces.begin();
       it != volumeForces.end(); ++it){
    elasticityTerm El(pModel, 1, 1, _tag);
    int iVolume = it->first;
    SVector3 f = it->second;
    El.setVector(f);
    printf("-- Force on volume %3d : %8.5f %8.5f %8.5f\n", iVolume, f.x(), f.y(), f.z());
    std::vector<GEntity*> ent = groups[_dim][iVolume];
    for (unsigned int i = 0; i < ent.size(); i++){
      //   to do
      //      El.addToRightHandSide(*pAssembler, ent[i]);
    }
  }

  // assembling the stifness matrix
  for (int i = 0; i < elasticFields.size(); i++){
    SElement::setShapeEnrichement(elasticFields[i]._enrichment);
    for (int j = 0; j < elasticFields.size(); j++){
      elasticityTerm El(0, elasticFields[i]._E, elasticFields[i]._nu,
                        elasticFields[i]._tag, elasticFields[j]._tag);
      SElement::setTestEnrichement(elasticFields[j]._enrichment);
      //      printf("%d %d\n",elasticFields[i]._tag,elasticFields[j]._tag);
      El.addToMatrix(*pAssembler, *elasticFields[i].g, *elasticFields[j].g);      
    }
  }

  printf("-- done assembling!\n");
  //  for (int i=0;i<pAssembler->sizeOfR();i++){
    //    printf("%g ",lsys->getFromRightHandSide(i));
  //  }
  //  printf("\n");

  // solving
  lsys->systemSolve();
}
