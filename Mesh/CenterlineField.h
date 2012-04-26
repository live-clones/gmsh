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
#include "meshGFaceDelaunayInsertion.h"
class GModel;
class GFace;
class MLine;
class MVertex;
class GEntity;
class MTriangle;   
class discreteEdge;
class discreteFace;
class MElement;
class SPoint3;

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

#if defined(HAVE_ANN)
#include <ANN/ANN.h>
class ANNkd_tree;

// This class takes as input A 1D mesh which is the centerline
// of a tubular 2D surface mesh
// It computes a mesh size field function of the distance to the centerlines
// and a cross field that is the direction of the centerline 
// It splits the tubular structure in many mesh partitions
// along planes perpendicuar to the centerlines 

class Centerline : public Field{

 protected: 
  GModel *current; //current GModel
  GModel *mod; //centerline GModel
  GModel *split; //split GModel
  ANNkd_tree *kdtree, *kdtreeR; 
  ANNpointArray nodes, nodesR;
  ANNidxArray index;
  ANNdistArray dist;
  std::string fileName;
  int nbPoints;
  double recombine;
  int NF, NV, NE, NR;
  int is_cut, is_closed, is_extruded;
  double hLayer;
  int nbElemLayer;

  //inlet point
  SPoint3 ptin;
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
  
  void cleanMesh();

  //isotropic operator for mesh size field function of distance to centerline
  double operator() (double x, double y, double z, GEntity *ge=0);
  //anisotropic operator
  void operator() (double x, double y, double z, SMetric3 &metr, GEntity *ge=0);

  //temporary operator where v1, v2 and v3 are three orthonormal directions
  void operator()(double x,double y,double z,SVector3& v1,SVector3& v2,SVector3& v3,GEntity* ge=0);
	
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
  void distanceToSurface();

  //actions
  void run();

  // Cut the mesh in different parts of small aspect ratio
  void cutMesh();
  //Create In and Outlet Planar Faces
  void createClosedVolume(GEdge *gin, std::vector<GEdge*> boundEdges);
  //extrude outer wall
  void extrudeBoundaryLayerWall(GEdge *gin, std::vector<GEdge*> boundEdges);

  // Cut the tubular structure with a disk
  // perpendicular to the tubular structure
  bool cutByDisk(SVector3 &pt, SVector3 &dir, double &maxRad);

  //create discrete faces
  void createFaces();
  void createSplitCompounds();

  //Print for debugging
  void printSplit() const;
 
};
#else
class Centerline : public Field{

 public:
  Centerline(std::string fileName){ Msg::Error("Gmsh has to be compiled with ANN support to use CenterlineFields");}
  Centerline(){ Msg::Error("Gmsh has to be compiled with ANN support to use CenterlineFields");}
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
  
  void cleanMesh();

  //isotropic operator for mesh size field function of distance to centerline
  double operator() (double x, double y, double z, GEntity *ge=0);
  //anisotropic operator
  void operator() (double x, double y, double z, SMetric3 &metr, GEntity *ge=0);

  //temporary operator where v1, v2 and v3 are three orthonormal directions
  void operator()(double x,double y,double z,SVector3& v1,SVector3& v2,SVector3& v3,GEntity* ge=0);

};

#endif

#endif
