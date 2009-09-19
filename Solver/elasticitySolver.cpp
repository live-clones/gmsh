// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <string.h>
#include "elasticityTerm.h"
#include "MTriangle.h"
#include "MTetrahedron.h"
#include "elasticitySolver.h"
#include "linearSystemTAUCS.h"
#include "Numeric.h"

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
  FILE *f = fopen (fn.c_str(),"r");
  char what[256];
  while(!feof(f)){
    fscanf(f, "%s", what);
    // printf("%s\n", what);
    if (!strcmp(what,"ElasticMaterial")){
      double E, nu;
      int physical;
      fscanf(f, "%d %lf %lf", &physical, &E, &nu);
      elasticConstants[physical] = std::make_pair(E, nu);    
    }
    else if (!strcmp(what, "NodalDisplacement")){
      double val;
      int node, comp;
      fscanf(f, "%d %d %lf", &node, &comp, &val);
      nodalDisplacements[ std::make_pair(node, comp) ] = val;    
    }
    else if (!strcmp(what, "EdgeDisplacement")){
      double val;
      int edge, comp;
      fscanf(f, "%d %d %lf", &edge, &comp, &val);
      edgeDisplacements[ std::make_pair(edge, comp) ] = val;    
    }
    else if (!strcmp(what, "FaceDisplacement")){
      double val;
      int face, comp;
      fscanf(f, "%d %d %lf", &face, &comp, &val);
      faceDisplacements[ std::make_pair(face, comp) ] = val;    
    }
    else if (!strcmp(what, "NodalForce")){
      double val1, val2, val3;
      int node;
      fscanf(f, "%d %lf %lf %lf", &node, &val1, &val2, &val3);
      nodalForces[node] = SVector3(val1, val2, val3);    
    }
    else if (!strcmp(what, "LineForce")){
      double val1, val2, val3;
      int node;
      fscanf(f, "%d %lf %lf %lf", &node, &val1, &val2, &val3);
      //printf("%d %lf %lf %lf\n", node, val1, val2, val3);
      lineForces[node] = SVector3(val1, val2, val3);    
    }
    else if (!strcmp(what, "FaceForce")){
      double val1, val2, val3;
      int face;
      fscanf(f, "%d %lf %lf %lf", &face, &val1, &val2, &val3);
      faceForces[face] = SVector3(val1, val2, val3);    
    }
    else if (!strcmp(what, "VolumeForce")){
      double val1, val2, val3;
      int volume;
      fscanf(f, "%d %lf %lf %lf", &volume, &val1, &val2, &val3);
      volumeForces[volume] = SVector3(val1, val2, val3);    
    }
    else if (!strcmp(what, "MeshFile")){
      char name[245];
      fscanf(f, "%s", name);
      setMesh(name);
    }
  }
  fclose(f);
}
  
void elasticitySolver::solve()
{
#ifdef HAVE_TAUCS
  linearSystemCSRTaucs<double> *lsys = new linearSystemCSRTaucs<double>;
#else
  linearSystemCSRGmm<double> *lsys = new linearSystemCSRGmm<double>;
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
    pAssembler-> fixVertex(v , it->first.second, _tag, it->second);    
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
  for (std::map<int, std::pair<double, double> >::iterator it = elasticConstants.begin();
       it != elasticConstants.end() ; it++){
    int physical = it->first;
    std::vector<MVertex *> v;     
    pModel->getMeshVerticesForPhysicalGroup(_dim, physical, v);
    printf("Physical %d, dim: %d, nb vert: %d\n", physical, _dim, v.size());
    for (unsigned int i = 0; i < v.size(); i++){  
      pAssembler->numberVertex (v[i], 0, _tag);  
      pAssembler->numberVertex (v[i], 1, _tag);  
      pAssembler->numberVertex (v[i], 2, _tag);  
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
      pAssembler-> assemble(ent[i]->mesh_vertices[0] , 0, _tag, f.x());
      pAssembler-> assemble(ent[i]->mesh_vertices[0] , 1, _tag, f.y());
      pAssembler-> assemble(ent[i]->mesh_vertices[0] , 2, _tag, f.z());
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
      El.addToRightHandSide(*pAssembler, ent[i]);
    }
  }
  
  // assembling the stifness matrix
  for (std::map<int, std::pair<double, double> > :: iterator it = elasticConstants.begin();
       it != elasticConstants.end() ; it++){
    int physical = it->first;
    double E = it->second.first;
    double nu = it->second.second;
    elasticityTerm El(0, E, nu, _tag);
    std::vector<GEntity*> ent = groups[_dim][physical];
    for (unsigned int i = 0; i < ent.size(); i++){
      El.addToMatrix(*pAssembler, ent[i]);
    }
  }

  // solving
  lsys->systemSolve();
}
