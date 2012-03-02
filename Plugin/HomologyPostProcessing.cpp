// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributed by Matti Pellikka <matti.pellikka@tut.fi>.

#include <stdlib.h>
#include <string>
#include <iostream>
#include <sstream>
#include "Gmsh.h"
#include "GmshConfig.h"
#include "GModel.h"
#include "Chain.h"
#include "HomologyPostProcessing.h"

#if defined(HAVE_KBIPACK)

StringXNumber HomologyPostProcessingOptions_Number[] = {
  {GMSH_FULLRC, "DimensionOfChains", NULL, 1},
  {GMSH_FULLRC, "ApplyBoundaryOperatorToResults", NULL, 0}
};

StringXString HomologyPostProcessingOptions_String[] = {
  {GMSH_FULLRC, "TransformationMatrix", NULL, "1, 0; 0, 1"},
  {GMSH_FULLRC, "PhysicalGroupsOfOperatedChains", NULL, "1, 2"},
  {GMSH_FULLRC, "PhysicalGroupsOfOperatedChains2", NULL, ""},
  {GMSH_FULLRC, "PhysicalGroupsToTraceResults", NULL, ""},
  {GMSH_FULLRC, "NameForResultChains", NULL, "c"},
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterHomologyPostProcessingPlugin()
  {
    return new GMSH_HomologyPostProcessingPlugin();
  }
}

std::string GMSH_HomologyPostProcessingPlugin::getHelp() const
{
  return "Plugin(HomologyPostProcessing) operates on representative "
    "basis chains of homology and cohomology spaces.\n\n"

    "Define the physical groups of chains and their dimension "
    "to be transformed by the "
    "given integer transformation matrix. Number of matrix columns must "
    "equal to the number of chains given. The resulting "
    "chains are thus integer combinations of the given chains. ";
}

int GMSH_HomologyPostProcessingPlugin::getNbOptions() const
{
  return sizeof(HomologyPostProcessingOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_HomologyPostProcessingPlugin::getOption(int iopt)
{
  return &HomologyPostProcessingOptions_Number[iopt];
}

int GMSH_HomologyPostProcessingPlugin::getNbOptionsStr() const
{
  return sizeof(HomologyPostProcessingOptions_String) / sizeof(StringXString);
}

StringXString *GMSH_HomologyPostProcessingPlugin::getOptionStr(int iopt)
{
  return &HomologyPostProcessingOptions_String[iopt];
}

bool GMSH_HomologyPostProcessingPlugin::parseStringOpt
(int stringOpt, std::vector<int>& intList)
{
  std::string list = HomologyPostProcessingOptions_String[stringOpt].def;
  intList.clear();

  int n;
  char a;
  std::istringstream ss(list);
  while(ss >> n){
    intList.push_back(n);
    if(ss >> a){
      if(a != ',') {
        Msg::Error("Unexpected character \'%c\' while parsing \'%s\'", a,
                   HomologyPostProcessingOptions_String[stringOpt].str);
        return false;
      }
    }
  }
  return true;
}

void GMSH_HomologyPostProcessingPlugin::createChains
(int dim, GModel* m,
 const std::vector<GEntity*>& chainEntities,
 const std::vector<std::string>& chainNames,
 std::vector<Chain<int> >& chains)
{
  for(unsigned int i = 0; i < chainEntities.size(); i++) {
    GEntity* e = chainEntities.at(i);
    Chain<int> chain;
    for(unsigned int j = 0; j < e->getNumMeshElements(); j++) {
      chain.addMeshElement(e->getMeshElement(j));
    }
    chains.push_back(chain);
    chains.at(i).setName(chainNames.at(i));
  }
}

int GMSH_HomologyPostProcessingPlugin::detIntegerMatrix
(std::vector<int>& matrix)
{
  int n = sqrt(matrix.size());
  fullMatrix<double> m(n,n);
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      m(i,j) = matrix.at(i*n+j);

  return m.determinant();
}

bool GMSH_HomologyPostProcessingPlugin::invertIntegerMatrix
(std::vector<int>& matrix)
{
  int n = sqrt(matrix.size());
  fullMatrix<double> m(n,n);
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      m(i,j) = matrix.at(i*n+j);

  if(!m.invertInPlace())
    Msg::Error("Matrix is not unimodular");

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      matrix.at(i*n+j) = m(i,j);
}

PView *GMSH_HomologyPostProcessingPlugin::execute(PView *v)
{
  std::string matrixString = HomologyPostProcessingOptions_String[0].def;
  std::string opString1 = HomologyPostProcessingOptions_String[1].def;
  std::string opString2 = HomologyPostProcessingOptions_String[2].def;
  std::string cname = HomologyPostProcessingOptions_String[4].def;
  std::string traceString = HomologyPostProcessingOptions_String[3].def;
  int dim = (int)HomologyPostProcessingOptions_Number[0].def;
  int bd = (int)HomologyPostProcessingOptions_Number[1].def;

  if(dim < 0 || dim > 3) {
    Msg::Error("Invalid cell dimension %d", dim);
    return 0;
  }

  GModel* m = GModel::current();

  int n;
  char a;
  int cols = 0;
  int col = 0;
  std::vector<int> matrix;
  if(matrixString != "I") {
    std::istringstream ss(matrixString);
    while(ss >> n){
      matrix.push_back(n);
      col++;
      if(ss >> a){
        if(a != ',' && a != ';') {
          Msg::Error("Unexpected character \'%c\' while parsing \'%s\'", a,
                     HomologyPostProcessingOptions_String[0].str);
          return 0;
        }
        if(a == ';') {
          if(cols != 0 && cols != col) {
            Msg::Error("Number of columns must match (%d != %d)", cols, col);
            return 0;
          }
          cols = col;
          col = 0;
        }
      }
    }
    if(cols != 0 && cols != col && col != 0) {
      Msg::Error("Number of columns must match (%d != %d)", cols, col);
      return 0;
    }
    if(cols == 0) cols = col;
  }

  int rows = 0;
  if(!matrix.empty()) {
    rows = matrix.size()/cols;
    if((int)matrix.size() % cols != 0) {
      Msg::Error("Number of matrix rows and columns aren't compatible (residual: %d)",
                 (int)matrix.size() % cols);
      return 0;
    }
  }

  std::vector<int> basisPhysicals;
  if(!parseStringOpt(1, basisPhysicals)) return 0;
  std::vector<int> basisPhysicals2;
  if(!parseStringOpt(2, basisPhysicals2)) return 0;

  if(matrixString != "I" &&
     basisPhysicals.size() != cols &&
     basisPhysicals2.empty()) {
    Msg::Error("Number of matrix columns and operated chains must match (%d != %d)", cols, basisPhysicals.size());
    return 0;
  }
  else if(matrixString == "I") {
    cols = basisPhysicals.size();
    rows = cols;
    matrix = std::vector<int>(cols*cols, 0);
    for(int i = 0; i < cols; i++)
      matrix.at(i*cols+i) = 1;
  }

  if(!basisPhysicals2.empty() &&
     basisPhysicals.size() != basisPhysicals2.size()) {
    Msg::Error("Number of operated chains must match (%d != %d)",
               basisPhysicals.size(), basisPhysicals2.size());
    return 0;
  }

  std::vector<int> tracePhysicals;
  if(!parseStringOpt(3, tracePhysicals)) return 0;

  std::vector<GEntity*> basisEntities;
  std::vector<GEntity*> basisEntities2;
  std::map<int, std::vector<GEntity*> > groups[4];
  m->getPhysicalGroups(groups);
  std::map<int, std::vector<GEntity*> >::iterator it;

  std::vector<std::string> curBasisNames;
  for(unsigned int i = 0; i < basisPhysicals.size(); i++){
    curBasisNames.push_back(m->getPhysicalName(dim, basisPhysicals.at(i)));
    it = groups[dim].find(basisPhysicals.at(i));
    if(it != groups[dim].end()){
      std::vector<GEntity*> physicalGroup = it->second;
      for(unsigned int k = 0; k < physicalGroup.size(); k++){
        basisEntities.push_back(physicalGroup.at(k));
        break;
      }
    }
    else {
      Msg::Error("%d-dimensional physical group %d does not exist",
                 dim, basisPhysicals.at(i));
      return 0;
    }
  }
  std::vector<std::string> curBasisNames2;
  for(unsigned int i = 0; i < basisPhysicals2.size(); i++){
    curBasisNames2.push_back(m->getPhysicalName(dim, basisPhysicals2.at(i)));
    it = groups[dim].find(basisPhysicals2.at(i));
    if(it != groups[dim].end()){
      std::vector<GEntity*> physicalGroup = it->second;
      for(unsigned int k = 0; k < physicalGroup.size(); k++){
        basisEntities2.push_back(physicalGroup.at(k));
        break;
      }
    }
    else {
      Msg::Error("%d-dimensional physical group %d does not exist",
                 dim, basisPhysicals2.at(i));
      return 0;
    }
  }

  std::vector<Chain<int> > curBasis;
  createChains(dim, m, basisEntities, curBasisNames, curBasis);
  std::vector<Chain<int> > curBasis2;
  createChains(dim, m, basisEntities2, curBasisNames2, curBasis2);


  if(!curBasis2.empty()) {
    rows = curBasis2.size();
    cols = curBasis.size();
    matrix = std::vector<int>(rows*cols, 0);
    for(int i = 0; i < rows; i++)
      for(int j = 0; j < cols; j++)
        matrix.at(i*cols+j) = incidence(curBasis2.at(i), curBasis.at(j));
  }

  if(!curBasis2.empty())
    Msg::Debug("Incidence matrix: ");
  else
    Msg::Debug("Transformation matrix: ");
  for(int i = 0; i < rows; i++)
    for(int j = 0; j < cols; j++)
      Msg::Debug("(%d, %d) = %d", i, j, matrix.at(i*cols+j));

  std::vector<Chain<int> > newBasis(rows, Chain<int>());
  if(!curBasis2.empty()) {
    Msg::Info("Computing new basis %d-chains such that the incidence matrix of %d-chain bases %s and %s is the indentity matrix",
              dim, dim, opString1.c_str(), opString2.c_str());
    if(!invertIntegerMatrix(matrix)) return 0;
    for(int i = 0; i < rows; i++)
      for(int j = 0; j < cols; j++)
        newBasis.at(i) += matrix.at(i*cols+j)*curBasis2.at(j); }
  else {
    Msg::Info("Applying transformation matrix [%s] to %d-chains %s",
              matrixString.c_str(), dim, opString1.c_str());
    if(rows == cols) {
      int det = detIntegerMatrix(matrix);
      if(det != 1 && det != -1)
      Msg::Warning("Transformation matrix is not unimodular (det = %d)", det);
    }
    for(int i = 0; i < rows; i++)
      for(int j = 0; j < cols; j++)
        newBasis.at(i) += matrix.at(i*cols+j)*curBasis.at(j);

  }

  if(bd) {
    Msg::Info("Applying boundary operator to the result %d-chains", dim);
    for(unsigned int i = 0; i < newBasis.size(); i++)
      newBasis.at(i) = newBasis.at(i).getBoundary();
  }

  if(!tracePhysicals.empty()) {
    Msg::Info("Taking trace of result %d-chains to domain %s",
              dim, traceString.c_str());
    std::vector<GEntity*> traceEntities;
    for(unsigned int i = 0; i < tracePhysicals.size(); i++){
      bool found = false;
      for(int j = 0; j < 4; j++){
        it = groups[j].find(tracePhysicals.at(i));
        if(it != groups[j].end()){
          found = true;
          std::vector<GEntity*> physicalGroup = it->second;
          for(unsigned int k = 0; k < physicalGroup.size(); k++){
            traceEntities.push_back(physicalGroup.at(k));
          }
        }
      }
      if(!found) {
        Msg::Error("Physical group %d does not exist",
                   tracePhysicals.at(i));
        return 0;
      }
    }
    for(unsigned int i = 0; i < newBasis.size(); i++)
      newBasis.at(i) = newBasis.at(i).getTrace(traceEntities);
    ElemChain::clearVertexCache();
  }

  std::string dims = "";
  std::string nums = "";
  for(unsigned int i = 0; i < newBasis.size(); i++) {
    convert(newBasis.at(i).getDim(), dims);
    convert(i+1, nums);
    newBasis.at(i).setName("C" + dims + " " + cname + nums);
    newBasis.at(i).addToModel(m);
  }

  return 0;
}

#endif
