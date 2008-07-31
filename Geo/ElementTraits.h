// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// ElementTraits.h - Copyright (C) 2008 S. Guzik, C. Geuzaine, J.-F. Remacle
#ifndef _ELEMENTTRAITS_H_
#define _ELEMENTTRAITS_H_

#include "MElement.h"
#include "GEdge.h"
#include "GFace.h"
#include "GRegion.h"


/*******************************************************************************
 *
 * - The classes in this file define traits for elements
 *
 ******************************************************************************/

//--Traits based on the dimension

template <unsigned DIM> struct DimTr;
template <> struct DimTr<1>
{
  typedef GEdge EntityT;
  enum { numElemTypes = 1 };
};
template <> struct DimTr<2>
{
  typedef MEdge FaceT;
  typedef GFace EntityT;
  enum { numElemTypes = 2 };
};
template <> struct DimTr<3>
{
  typedef MFace FaceT;
  typedef GRegion EntityT;
  enum { numElemTypes = 4 };
};

//--This traits class describes the number of dimension-based 'FaceT' in an
//--primary element type

template <unsigned DIM, typename Elem> struct ElemFaceTr;
template <> struct ElemFaceTr<2, MLine>        { enum { numFaceT =  1 }; };
template <> struct ElemFaceTr<2, MTriangle>    { enum { numFaceT =  3 }; };
template <> struct ElemFaceTr<2, MQuadrangle>  { enum { numFaceT =  4 }; };
template <> struct ElemFaceTr<3, MTriangle>    { enum { numFaceT =  1 }; };
template <> struct ElemFaceTr<3, MQuadrangle>  { enum { numFaceT =  1 }; };
template <> struct ElemFaceTr<3, MTetrahedron> { enum { numFaceT =  4 }; };
template <> struct ElemFaceTr<3, MHexahedron>  { enum { numFaceT =  6 }; };
template <> struct ElemFaceTr<3, MPrism>       { enum { numFaceT =  5 }; };
template <> struct ElemFaceTr<3, MPyramid>     { enum { numFaceT =  5 }; };

//--This traits class gives iterator types and begin and end iterators for
//--element type number N in an entity of dimension DIM

template <unsigned DIM, int N> struct DimElemTr;
template <> struct DimElemTr<1, 1> {
  typedef MLine Elem;
  typedef std::vector<MLine*>::const_iterator ConstElementIterator;
  static ConstElementIterator begin(const GEdge *const gEdge)
  {
    return gEdge->lines.begin();
  }
  static ConstElementIterator end(const GEdge *const gEdge)
  {
    return gEdge->lines.end();
  }
};
template <> struct DimElemTr<2, 1> {
  typedef MQuadrangle Elem;
  typedef std::vector<MQuadrangle*>::const_iterator ConstElementIterator;
  static ConstElementIterator begin(const GFace *const gFace)
  {
    return gFace->quadrangles.begin();
  }
  static ConstElementIterator end(const GFace *const gFace)
  {
    return gFace->quadrangles.end();
  }
};
template <> struct DimElemTr<2, 2> {
  typedef MTriangle Elem;
  typedef std::vector<MTriangle*>::const_iterator ConstElementIterator;
  static ConstElementIterator begin(const GFace *const gFace)
  {
    return gFace->triangles.begin();
  }
  static ConstElementIterator end(const GFace *const gFace)
  {
    return gFace->triangles.end();
  }
};
template <> struct DimElemTr<3, 1> {
  typedef MPyramid Elem;
  typedef std::vector<MPyramid*>::const_iterator ConstElementIterator;
  static ConstElementIterator begin(const GRegion *const gRegion)
  {
    return gRegion->pyramids.begin();
  }
  static ConstElementIterator end(const GRegion *const gRegion)
  {
    return gRegion->pyramids.end();
  }
};
template <> struct DimElemTr<3, 2> {
  typedef MPrism Elem;
  typedef std::vector<MPrism*>::const_iterator ConstElementIterator;
  static ConstElementIterator begin(const GRegion *const gRegion)
  {
    return gRegion->prisms.begin();
  }
  static ConstElementIterator end(const GRegion *const gRegion)
  {
    return gRegion->prisms.end();
  }
};
template <> struct DimElemTr<3, 3> {
  typedef MHexahedron Elem;
  typedef std::vector<MHexahedron*>::const_iterator ConstElementIterator;
  static ConstElementIterator begin(const GRegion *const gRegion)
  {
    return gRegion->hexahedra.begin();
  }
  static ConstElementIterator end(const GRegion *const gRegion)
  {
    return gRegion->hexahedra.end();
  }
};
template <> struct DimElemTr<3, 4> {
  typedef MTetrahedron Elem;
  typedef std::vector<MTetrahedron*>::const_iterator ConstElementIterator;
  static ConstElementIterator begin(const GRegion *const gRegion)
  {
    return gRegion->tetrahedra.begin();
  }
  static ConstElementIterator end(const GRegion *const gRegion)
  {
    return gRegion->tetrahedra.end();
  }
};

//--Traits/policy class based on dimension of a face.

template <typename FaceT> struct FaceTr;
template <> struct FaceTr<MEdge>
{
  template <typename Elem>
  static MEdge getFace(Elem *const element, const int iFace)
  {
    return element->getEdge(iFace);  // Primary element
  }
  static void getAllFaceVertices(MElement *const element, const int iFace,
                                 std::vector<MVertex*> &v)
  {
    element->getEdgeVertices(iFace, v);  // Any element
  }
};
template <> struct FaceTr<MFace>
{
  template <typename Elem>
  static MFace getFace(Elem *const element, const int iFace)
  {
    return element->getFace(iFace);  // Primary element
  }
  static void getAllFaceVertices(MElement *const element, const int iFace,
                                 std::vector<MVertex*> &v)
  {
    element->getFaceVertices(iFace, v);  // Any element
  }
};

#endif
