// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _MAKE_SIMPLEX_H_
#define _MAKE_SIMPLEX_H_

#include "Plugin.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterMakeSimplexPlugin();
}

class GMSH_MakeSimplexPlugin : public GMSH_PostPlugin
{
public:
  GMSH_MakeSimplexPlugin(){}
  std::string getName() const { return "MakeSimplex"; }
  std::string getShortHelp() const
  {
    return "Transform quad/hex/prisms into tri/tets";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber* getOption(int iopt);  
  PView *execute(PView *);
};

class MakeSimplex{
 private:
  // how many nodes in the element to decompose
  int _numNodes;
  // how many field components
  int _numComponents;
  // how many time steps
  int _numTimeSteps;
  // create a simplex
  void reorder(int map[4], int n,
               double *x, double *y, double *z, double *val,
               double *xn, double *yn, double *zn, double *valn);
 public:
  // default constructor
  MakeSimplex(int numNodes, int numComponents, int numTimeSteps=1);
  // the number of simplices into which the element is decomposed
  int numSimplices();
  // the number of nodes of the simplex
  int numSimplexNodes();
  // returns the i-th simplex in the decomposition
  void decompose(int num, 
                 double *x, double *y, double *z, double *val,
                 double *xn, double *yn, double *zn, double *valn);
};

#endif
