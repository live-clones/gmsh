#ifndef NGINTERFACE
#define NGINTERFACE

/**************************************************************************/
/* File:   nginterface.hh                                                 */
/* Author: Joachim Schoeberl                                              */
/* Date:   20. Nov. 99                                                    */
/**************************************************************************/

/*
  
  Application program interface to Netgen
  

 */


// max number of nodes per element
#define NG_ELEMENT_MAXPOINTS 12

// max number of nodes per surface element
#define NG_SURFACE_ELEMENT_MAXPOINTS 6



// implemented element types:
enum NG_ELEMENT_TYPE { 
  NG_SEGM = 1, NG_SEGM3 = 2,
  NG_TRIG = 10, NG_QUAD=11, NG_TRIG6 = 12, NG_QUAD6 = 13,
  NG_TET = 20, NG_TET10 = 21, 
  NG_PYRAMID = 22, NG_PRISM = 23, NG_PRISM12 = 24,
  NG_HEX = 25
};

typedef double NG_POINT[3];  // coordinates
typedef int NG_EDGE[2];      // initial point, end point
typedef int NG_FACE[4];      // points, last one is 0 for trig


#ifdef __cplusplus
extern "C" {
#endif
  
  // load geomtry from file 
  void Ng_LoadGeometry (char * filename);
  
  // load netgen mesh
  void Ng_LoadMesh (char * filename);


  // space dimension (2 or 3)
  int Ng_GetDimension ();

  // number of mesh points
  int Ng_GetNP ();
  
  // number of mesh vertices (differs from GetNP for 2nd order elements)
  int Ng_GetNV ();
  
  // number of mesh elements
  int Ng_GetNE ();
  
  // number of surface triangles
  int Ng_GetNSE ();
  
  // Get Point coordintes, index from 1 .. np
  void Ng_GetPoint (int pi, double * p);
  
  // Get Element Points
  NG_ELEMENT_TYPE Ng_GetElement (int ei, int * epi, int * np = 0);

  // Get Element Type
  NG_ELEMENT_TYPE Ng_GetElementType (int ei);

  // Get sub-domain of element ei
  int Ng_GetElementIndex (int ei);

  // Get Material of element ei
  char * Ng_GetElementMaterial (int ei);

  // Get Surface Element Points
  NG_ELEMENT_TYPE Ng_GetSurfaceElement (int ei, int * epi, int * np = 0);

  // Get Surface Element Index
  int Ng_GetSurfaceElementIndex (int ei);
  
  // Get normal vector of surface element node
  void Ng_GetNormalVector (int sei, int locpi, double * nv);     
  

  // Find element of point, returns local coordinates
  int Ng_FindElementOfPoint (double * p, double * lami);
  

  /// Curved Elemens:
  /// xi..local coordinates
  /// x ..global coordinates
  /// dxdxi...D x D Jacobian matrix (row major storage)
  void Ng_GetElementTransformation (int ei, const double * xi, 
				    double * x, double * dxdxi);

  /// Curved Elemens:
  /// xi..local coordinates
  /// x ..global coordinates
  /// dxdxi...D x D-1 Jacobian matrix (row major storage)
  void Ng_GetSurfaceElementTransformation (int sei, const double * xi, double * x, double * dxdxi);

  
  // Mark element for refinement
  void Ng_SetRefinementFlag (int ei, int flag);
  void Ng_SetSurfaceRefinementFlag (int sei, int flag);

  // Do local refinement
  enum NG_REFINEMENT_TYPE { NG_REFINE_H = 0, NG_REFINE_P = 1, NG_REFINE_HP = 2 };
  void Ng_Refine (NG_REFINEMENT_TYPE reftype);

  // Use second order elements
  void Ng_SecondOrder ();
  void Ng_HighOrder (int order);
  void Ng_HPRefinement (int levels);


  // Topology and coordinate information of master element:

  int Ng_ME_GetNVertices (NG_ELEMENT_TYPE et);
  int Ng_ME_GetNEdges (NG_ELEMENT_TYPE et);
  int Ng_ME_GetNFaces (NG_ELEMENT_TYPE et);

  const NG_POINT * Ng_ME_GetVertices (NG_ELEMENT_TYPE et);
  const NG_EDGE * Ng_ME_GetEdges (NG_ELEMENT_TYPE et);
  const NG_FACE * Ng_ME_GetFaces (NG_ELEMENT_TYPE et);

  int Ng_GetNEdges();
  int Ng_GetNFaces();

  
  int Ng_GetElement_Edges (int elnr, int * edges, int * orient = 0);
  int Ng_GetElement_Faces (int elnr, int * faces, int * orient = 0);

  int Ng_GetSurfaceElement_Edges (int selnr, int * edges, int * orient = 0);
  int Ng_GetSurfaceElement_Face (int selnr, int * orient = 0);

  int Ng_GetFace_Vertices (int fnr, int * vert);
  void Ng_GetEdge_Vertices (int ednr, int * vert);
  int Ng_GetFace_Edges (int fnr, int * edge);

  int Ng_GetElementOrder (int enr);

  // Multilevel functions:

  // number of levels:
  int Ng_GetNLevels ();
  // get two parent nodes of node ni
  void Ng_GetParentNodes (int ni, int * parents);

  // get parent element (first child has always same number)
  int Ng_GetParentElement (int ei);

  // get parent surface element (first child has always same number)
  int Ng_GetParentSElement (int ei);

  // representant of anisotropic cluster
  int Ng_GetClusterRepVertex (int vi);
  int Ng_GetClusterRepEdge (int edi);
  int Ng_GetClusterRepFace (int fai);
  int Ng_GetClusterRepElement (int eli);


  void Ng_SurfaceElementTransformation (int eli, double x, double y, 
					double * p3d, double * jacobian);
  
namespace netgen {
#include "../visualization/soldata.hpp"
}

  enum Ng_SolutionType
  { NG_SOLUTION_NODAL = 1, 
    NG_SOLUTION_ELEMENT = 2, 
    NG_SOLUTION_SURFACE_ELEMENT = 3, 
    NG_SOLUTION_NONCONTINUOUS = 4,
    NG_SOLUTION_SURFACE_NONCONTINUOUS = 5,
    NG_SOLUTION_VIRTUAL_FUNCTION = 6,
    NG_SOLUTION_MARKED_ELEMENTS = 10,
    NG_SOLUTION_ELEMENT_ORDER = 11
  };
  
  struct Ng_SolutionData
  {
    char * name;      // name of gridfunction
    double * data;    // solution values
    int components;   // relevant (double) components in solution vector
    int dist;         // # doubles per entry alignment! 
    int iscomplex;    // complex vector ? 
    bool draw_surface;
    bool draw_volume;
    int order;        // order of elements, only partially supported 
    Ng_SolutionType soltype;  // type of solution function
    netgen::SolutionData * solclass;
  };
  
  // initialize solution data with default arguments
  void Ng_InitSolutionData (Ng_SolutionData * soldata);
  // set solution data
  void Ng_SetSolutionData (Ng_SolutionData * soldata);
  // redraw 
  void Ng_Redraw();
  //
  void Ng_SetVisualizationParameter (const char * name, 
				     const char * value);


  // number of periodic vertices  
  int Ng_GetNPeriodicVertices ();
  // pairs should be an integer array of 2*npairs
  void Ng_GetPeriodicVertices (int * pairs);


#ifdef __cplusplus
}
#endif

#endif
