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
    "basis chains of homology and cohomology spaces. Functionality:\n\n"

    "1. (co)homology basis transformation:\n "
    "'TransformationMatrix': Integer matrix of the transformation.\n "
    "'PhysicalGroupsOfOperatedChains': (Co)chains of a (co)homology space basis to be transformed.\n "
    "Results a new (co)chain basis that is an integer cobination of the given basis. \n\n"

    "2. Make basis representations of a homology space and a cohomology space "
    "compatible: \n"
    "'PhysicalGroupsOfOperatedChains': Chains of a homology space basis.\n"
    "'PhysicalGroupsOfOperatedChains2': Cochains of a cohomology space basis.\n"
    "Results a new basis for the homology space such that the incidence matrix of the new basis and the basis of the cohomology space is the identity matrix.\n\n"

    "Options:\n"
    "'PhysicalGroupsToTraceResults': Trace the resulting cochains to the given physical groups.\n"
    "'NameForResultChains': Post-processing view name prefix for the results.\n"
    "'ApplyBoundaryOperatorToResults': Apply boundary operator to the resulting chains.\n";

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

  if(!m.invertInPlace()){
    Msg::Error("Matrix is not unimodular");
    return false;
  }

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      matrix.at(i*n+j) = m(i,j);
  return true;
}

PView *GMSH_HomologyPostProcessingPlugin::execute(PView *v)
{
  std::string matrixString = HomologyPostProcessingOptions_String[0].def;
  std::string opString1 = HomologyPostProcessingOptions_String[1].def;
  std::string opString2 = HomologyPostProcessingOptions_String[2].def;
  std::string cname = HomologyPostProcessingOptions_String[4].def;
  std::string traceString = HomologyPostProcessingOptions_String[3].def;
  int bd = (int)HomologyPostProcessingOptions_Number[0].def;

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
     (int)basisPhysicals.size() != cols &&
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

  std::vector<Chain<int> > curBasis;
  for(unsigned int i = 0; i < basisPhysicals.size(); i++){
    curBasis.push_back(Chain<int>(m, basisPhysicals.at(i)));
  }
  if(curBasis.empty()) {
    Msg::Error("No operated chains given");
    return 0;
  }
  int dim = curBasis.at(0).getDim();

  std::vector<Chain<int> > curBasis2;
  for(unsigned int i = 0; i < basisPhysicals2.size(); i++){
    curBasis2.push_back(Chain<int>(m, basisPhysicals2.at(i)));
  }

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
    int det = detIntegerMatrix(matrix);
    if(det != 1 && det != -1)
      Msg::Warning("Incidence matrix is not unimodular (det = %d)", det);
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
    for(unsigned int i = 0; i < newBasis.size(); i++)
      newBasis.at(i) = newBasis.at(i).getTrace(m, tracePhysicals);
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
