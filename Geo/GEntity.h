#ifndef _GENTITY_H_
#define _GENTITY_H_

// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include <list>
#include <vector>
#include <string>
#include "Range.h"
#include "SPoint3.h"
#include "SBoundingBox3d.h"
#include "GmshDefines.h"

class GModel;
class GVertex;
class GEdge;
class GFace;
class GRegion;
class MVertex;
class MRep;

// A geometric model entity.
class GEntity {
 private:
  // All entities are owned by a GModel
  GModel *_model;
  
  // The tag (the number) of this entity
  int _tag;
  
  // The visibility and the selection flag
  char _visible, _selection;
  
  // The color of the entity (ignored if set to transparent blue)
  unsigned int _color;
  
 public:

  // All known native model types
  enum ModelType {
    UnknownModel,
    GmshModel,
    FourierModel,
    OpenCascadeModel
  };

  // All known entity types
  enum GeomType {
    Unknown,
    Point,
    BoundaryLayerPoint,
    Line,
    Circle,
    Ellipse,
    BSpline,
    Bezier,
    ParametricCurve,
    BoundaryLayerCurve,
    DiscreteCurve,
    Plane,
    Nurb,
    Cylinder,
    Sphere,
    Cone,
    Torus,
    RuledSurface,
    ParametricSurface,
    ProjectionFace,
    BSplineSurface,
    BoundaryLayerSurface,
    DiscreteSurface,
    Volume,
    DiscreteVolume
  };

  // Returns a string describing the entity type
  virtual std::string getTypeString()
  {
    const char *name[] = {
      "Unknown",
      "Point",
      "Boundary layer point",
      "Line",
      "Circle",
      "Ellipse",
      "BSpline",
      "Bezier",
      "Parametric curve",
      "Boundary layer curve",
      "Discrete curve",
      "Plane",
      "Nurb",
      "Cylinder",
      "Sphere",
      "Cone",
      "Torus",
      "Ruled surface",
      "Parametric surface",
      "Projection surface",
      "BSpline surface",
      "Boundary layer surface",
      "Discrete surface",
      "Volume",
      "Discrete volume"
    };
    unsigned int type = (unsigned int)geomType();
    if(type >= sizeof(name) / sizeof(name[0]))
      return "Undefined";
    else
      return name[type];
  }

  GEntity(GModel *m, int t);

  virtual ~GEntity();

  // Spatial dimension of the entity 
  virtual int dim() const { throw; }

  // Regions that bound this entity or that this entity bounds.
  virtual std::list<GRegion*> regions() const { throw; }

  // Faces that bound this entity or that this entity bounds.
  virtual std::list<GFace*> faces() const { throw; }

  // Edges that bound this entity or that this entity bounds.
  virtual std::list<GEdge*> edges() const { throw; }

  // Vertices that bound this entity.
  virtual std::list<GVertex*> vertices() const { throw; }

  /// Underlying geometric representation of this entity.
  virtual GeomType geomType() const { throw; }

  // True if parametric space is continuous in the "dim" direction.
  virtual bool continuous(int dim) const { return true; }

  // True if entity is periodic in the "dim" direction.
  virtual bool periodic(int dim) const { return false; }

  // True if there are parametric degeneracies in the "dim" direction.
  virtual bool degenerate(int dim) const { return false; }

  // Parametric bounds of the entity in the "i" direction.
  virtual Range<double> parBounds(int i) const { throw; }

  // Modeler tolerance for the entity.
  virtual double tolerance() const { return 1.e-14; }

  // True if the entity contains the given point to within tolerance.
  virtual int containsPoint(const SPoint3 &pt) const { throw; }

  // Get the native type of the particular representation
  virtual ModelType getNativeType() const { return UnknownModel;}

  // Get the native pointer of the particular representation
  virtual void * getNativePtr() const { throw; }

  // The model owning this entity.
  GModel *model() const { return _model; }

  // The tag of the entity
  int tag() const { return _tag; }
  void setTag(int tag) { _tag = tag; }

  // The bounding box
  virtual SBoundingBox3d bounds() const { throw; }

  // Get the visibility flag
  virtual char getVisibility();

  // Set the visibility flag
  virtual void setVisibility(char val, bool recursive=false){ _visible = val; }

  // Get the selection flag
  virtual char getSelection(){ return _selection; }

  // Set the selection flag
  virtual void setSelection(char val){ _selection = val; }

  // Get the color
  virtual unsigned int getColor(){ return _color; }

  // Set the color
  virtual void setColor(unsigned color){ _color = color; }

  // Returns true if we should use this color to represent the entity
  virtual bool useColor();

  // Returns an information string for the entity
  virtual std::string getInfoString();

  // Returns a type-specific additional information string
  virtual std::string getAdditionalInfoString() { return std::string(""); }

  // Resets the mesh attributes to default values
  virtual void resetMeshAttributes() { return; }

  // The mesh vertices uniquely owned by the entity
  std::vector<MVertex*> mesh_vertices;

  // The physical entitites (if any) that contain this entity
  std::vector<int> physicals;

  // A representation of the mesh of the entity
  MRep *meshRep;
};

class GEntityLessThan {
 public:
  bool operator()(const GEntity *ent1, const GEntity *ent2) const
  {
    return ent1->tag() < ent2->tag();
  }
};

#endif
