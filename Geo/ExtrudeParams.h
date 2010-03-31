// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _EXTRUDE_PARAMS_H_
#define _EXTRUDE_PARAMS_H_

#include <vector>
#include <map>
#include <string>
#include "SmoothData.h"
#include "MElement.h"

// geo.Mode
#define EXTRUDED_ENTITY 1
#define COPIED_ENTITY 2

// geo.Type
#define TRANSLATE 1
#define ROTATE 2
#define TRANSLATE_ROTATE 3
#define BOUNDARY_LAYER 4

class ExtrudeParams{
public :
  class ExtrusionElementMap {
    private:
      ExtrudeParams* _parent;
      // maps source element to all extruded elements
      std::map<MElement*,std::vector<MElement*> > _extrudedElements;
    public:
      ExtrusionElementMap(ExtrudeParams* const parent);
      std::vector<MElement*>* getExtrudedElems(MElement* source);
      void addExtrudedElem(MElement* source,MElement* extrudedElem);
      void clear();
      bool empty();
      void propagatePartitionInformation(std::vector<int>* partitionSizes = NULL);
  } elementMap;
  static smooth_data *normals;
  ExtrudeParams(int Mode = EXTRUDED_ENTITY);
  void fill(int type,
            double T0, double T1, double T2,
            double A0, double A1, double A2,
            double X0, double X1, double X2, double angle);
  double u(int iLayer, int iElemLayer);
  void Extrude(int iLayer, int iElemLayer,
               double &dx, double &dy, double &dz);
  void Extrude(double t, double &x, double &y, double &z);
  void Rotate(double matr[3][3]);
  struct{
    bool ExtrudeMesh;
    bool Recombine;
    int NbLayer;
    std::vector<int> NbElmLayer;
    std::vector<double> hLayer;
    std::map<int, std::pair<double, std::vector<int> > > Holes;
  }mesh;
  struct{
    int Mode;
    int Type;
    int Source;
    double trans[3];
    double axe[3], pt[3], angle;
  }geo;
};

#endif
