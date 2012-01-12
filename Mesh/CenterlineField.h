// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Emilie Marchandise

#ifndef _CENTERLINEFIELD_H_
#define _CENTERLINEFIELD_H_

#include <vector>
#include <map>
#include <string>
#include "Field.h"
class GModel;
class MLine;
class MVertex;
class GEntity;

#if defined(HAVE_ANN)
#include <ANN/ANN.h>
class ANNkd_tree;

class Centerline : public Field{

  ANNkd_tree *kdtree; 
  ANNpointArray nodes;
  ANNidxArray index;
  ANNdistArray dist;
  GModel *mod;
  std::string fileName;

 public:
  Centerline(std::string fileName);
  Centerline();
  ~Centerline();

  void importFile(std::string fileName);

  virtual bool isotropic () const {return false;}
  virtual const char *getName()
  {
    return "centerline Field";
  }
  virtual std::string getDescription()
  {
    return "The value of this field is the distance to the centerline.\n\n"
" You should specify a fileName that contains the centerline.\n"
" The centerline of a surface can be obtained using the open source software vmtk\n\n"
" using the following script:\n\n"
"vmtk vmtkcenterlines -seedselector openprofiles -ifile mysurface.stl -ofile centerlines.vtp --pipe vmtksurfacewriter -ifile centerlines.vtp -ofile centerlines.vtk\n";
  }
  double operator() (double x, double y, double z, GEntity *ge=0);
  void operator() (double x, double y, double z, SMetric3 &metr, GEntity *ge=0);

  void printSplit() const;
  void buildKdTree();

  std::vector<MLine*> lines;
  std::map<MVertex*,int> color;

};
#endif

#endif
