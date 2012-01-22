// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
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
#include <set>
#include <string>
#include "Field.h"
#include "MEdge.h"
class GModel;
class GFace;
class MLine;
class MVertex;
class GEntity;
class MTriangle;   
class discreteEdge;
class discreteFace;

#if defined(HAVE_ANN)
#include <ANN/ANN.h>
class ANNkd_tree;

// A branch of a 1D tree
struct Branch{
  int tag;
  std::vector<MLine*> lines;
  double length;
  MVertex *vB;
  MVertex *vE;
  std::vector<Branch> children;
  double minRad;
  double maxRad;
};

// This class takes as input A 1D mesh which is the centerline
// of a tubular 2D surface mesh
// It computes a mesh size field function of the distance to the centerlines
// and a cross field that is the direction of the centerline 
// It splits the tubular structure in many mesh partitions
// along planes perpendicuar to the centerlines 

class Centerline : public Field{

 protected: 
  GModel *current;
  ANNkd_tree *kdtree; 
  ANNpointArray nodes;
  ANNidxArray index;
  ANNdistArray dist;
  GModel *mod;
  std::string fileName;

  //all (unique) lines of centerlines
  std::vector<MLine*> lines;
  //the stuctured tree of the centerlines
  std::vector<Branch> edges;
  //the radius of the surface mesh at a given line
  std::map<MLine*,double> radiusl;
  //the junctions of the tree
  std::set<MVertex*> junctions;
  //some colors (int) for all points and lines
  std::map<MVertex*,int> colorp;
  std::map<MLine*,int> colorl;

  //the tubular surface mesh
  std::vector<MTriangle*> triangles;
  //the lines cut of the tubular mesh by planes
  std::set<MEdge,Less_Edge> theCut;
  std::set<MVertex*> theCutV;

  //discrete edes and faces created by the cut
  std::vector<discreteEdge*> discEdges;
  std::vector<discreteFace*> discFaces;

 public:
  Centerline(std::string fileName);
  Centerline();
  ~Centerline();

  virtual bool isotropic () const {return false;}
  virtual const char *getName()
  {
    return "centerline Field";
  }
  virtual std::string getDescription()
  {
    return "The value of this field is the distance to the centerline.\n\n"
" You should specify a fileName that contains the centerline."
" The centerline of a surface can be obtained with the open source software vmtk (http://www.vmtk.org/)"
" using the following script:\n\n"
"vmtk vmtkcenterlines -seedselector openprofiles -ifile mysurface.stl -ofile centerlines.vtp --pipe vmtksurfacewriter -ifile centerlines.vtp -ofile centerlines.vtk\n";
  }

  //isotropic operator for mesh size field function of distance to centerline
  double operator() (double x, double y, double z, GEntity *ge=0);
  //anisotropic operator
  void operator() (double x, double y, double z, SMetric3 &metr, GEntity *ge=0);

  //import the 1D mesh of the centerlines (in vtk format)
  //and fill the vector of lines
  void importFile(std::string fileName);

  //refine the 1D mesh to have many points on the 1D centerlines 
  //for annKDTree distance computations
  void buildKdTree();

  //Creates the branch structure (topology, connectivity) from the 
  //vector of lines
  void createBranches(int maxN);

  //Computes for the Branches the min and maxRadius of the tubular structure
  //this function needs the current GModel
  void computeRadii();

  //Computes for each MLine the minRadius
  void distanceToLines();

  // Cut the mesh in different parts of small aspect ratio
  void splitMesh();

  // Cut the tubular structure with a disk
  // perpendicular to the tubular structure
  void cutByDisk(SVector3 &pt, SVector3 &dir, double &maxRad);

  //create discrete Edge
  void createEdge(std::set<MEdge,Less_Edge> &newCut);
  void createFaces(std::vector<std::vector<MTriangle*> > &faces);

  //Print for debugging
  void printSplit() const;
 


};
#endif

#endif
