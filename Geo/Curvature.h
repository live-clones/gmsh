// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _CURVATUREL_H_
#define _CURVATURE_H_

#include "GModel.h"
#include "STensor3.h"

#include<map>
#include<vector>

class Curvature
{
private:

    //-----------------------------------------
    // TYPEDEFS

    typedef std::vector<GEntity*> GEntityList;
    typedef std::vector<GFace*> GFaceList;
    typedef std::map<int, GEntityList >::iterator GEntityIter;
    typedef std::map<int, GFaceList >::iterator GFaceIter;

    //-----------------------------------------
    // MEMBER VARIABLES

    //Map definition
    std::map<int, int> _VertexToInt;
    std::map<int, int> _ElementToInt;

    //Model and list of selected entities with give physical tag:
    GModel* _model;    

    GEntityList _ptFinalEntityList;

    //Averaged vertex normals
    std::vector<SVector3> _VertexNormal;

    //Curvature Tensor per mesh vertex
    std::vector<STensor3> _CurveTensor;

    //Area of a triangle element:
    std::vector<double> _TriangleArea;

    //Area around a mesh vertex:
    std::vector<double> _VertexArea;

    std::vector<double> _VertexCurve;


    //-----------------------------------------
    // PRIVATE METHODS

    void initializeMap();
    void computeVertexNormals();
    void curvatureTensor();



public:

  //-----------------------------------------
  // PUBLIC METHODS
  //Constructor
  Curvature(GModel* model);

  //Destructor
  ~Curvature();

  void retrievePhysicalSurfaces(const std::string & face_tag);
  void computeCurvature();
  void writeToFile( const std::string & filename);



};


#endif
