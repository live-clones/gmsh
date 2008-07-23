// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// MZone.h - Copyright (C) 2008 S. Guzik, C. Geuzaine, J.-F. Remacle
#ifndef _MZONE_H_
#define _MZONE_H_


/*******************************************************************************
 *
 * The classes in this file are used to define and generate representations of
 * zones.
 *
 ******************************************************************************/

#include <map>
#include <vector>
#include "MElement.h"
#include "GFace.h"
#include "GRegion.h"
#include "MEdgeHash.h"
#include "MFaceHash.h"
#include "CustomContainer.h"

// #define HAVE_HASH_MAP

#if defined(HAVE_HASH_MAP)
#include "HashMap.h"
#endif


/*==============================================================================
 * Forward declarations
 *============================================================================*/

template <unsigned DIM>
class MZoneBoundary;


/*==============================================================================
 * Required types
 *============================================================================*/

//--Record of unique elements

struct ElemData
{
  MElement *element;
  int index;
  ElemData(MElement *const _element)
    : element(_element), index(0)
  { }
};

typedef std::vector<ElemData> ElementVec;

//--Record of unique vertices

typedef std::map<MVertex*, int, std::less<MVertex*> > VertexMap;

//--Data for each face.  Ultimately, only faces on the boundary of the zone are
//--stored.  Value type for 'BoFaceMap'.

struct FaceData
{
  MElement *parentElement;
  int parentFace;
  int parentElementIndex;
  int faceIndex;
  FaceData(MElement *const _parentElement, const int _parentFace,
           const int _parentElementIndex)
    : parentElement(_parentElement), parentFace(_parentFace),
    parentElementIndex(_parentElementIndex), faceIndex(0)
  { }
};

//--Provides information and boundary faces connected to a vertex.  Value type
//--for 'BoVertexMap'

template <typename BFMapIt>
struct ZoneVertexData
{
  CCon::FaceVector<BFMapIt> faces; // Vector optimized for storing faces
  int index;
};

/*--------------------------------------------------------------------*
 * User I/O
 *--------------------------------------------------------------------*/

struct ElementConnectivity
{
  std::vector<int> connectivity;
  int numElem;
  int numBoElem;
  int iConn;
  // Constructor
  ElementConnectivity()
    : numElem(0), numBoElem(0), iConn(0)
  { }
  // Member functions
  void add_to_connectivity(const int i)
  {
    connectivity[iConn++] = i;
  }
  void clear()
  {
    connectivity.clear();
    numElem = 0;
    numBoElem = 0;
    iConn = 0;
  }
};

//--Output type for zone element connectivity

typedef std::vector<ElementConnectivity> ElementConnectivityVec;

//--Output type for vertices in the zone

typedef std::vector<MVertex*> VertexVec;


/*==============================================================================
 * Traits classes - that just perform compile-time checks for valid argument
 * types
 *============================================================================*/

//--This traits class checks for valid types of entities and iterators.

// NOTE:  If the compiler sent you here, you're using an invalid entity and/or
// invalid iterator.  Valid pairs are shown below.
template <typename Ent, typename Iter> struct ValidEntityIterator;
template <> struct ValidEntityIterator<GFace, GFace*>
{ typedef void Type; };
template <> struct ValidEntityIterator<GFace, GEntity*>
{ typedef void Type; };
template <> struct ValidEntityIterator<GRegion, GRegion*>
{ typedef void Type; };
template <> struct ValidEntityIterator<GRegion, GEntity*>
{ typedef void Type; };


/*==============================================================================
 * Traits classes - that return information about a type
 *============================================================================*/

//--Traits based on the dimension

template <unsigned DIM> struct DimTr;
template <> struct DimTr<2>
{
  typedef MEdge FaceT;
  typedef GFace EntityT;
};
template <> struct DimTr<3>
{
  typedef MFace FaceT;
  typedef GRegion EntityT;
};

//--This traits class describes the number of dimension-based 'FaceT' in an
//--primary element type

template <typename Elem> struct ElemFaceTr;
template <> struct ElemFaceTr<MTriangle>    { enum { numFaceT =  3 }; };
template <> struct ElemFaceTr<MQuadrangle>  { enum { numFaceT =  4 }; };
template <> struct ElemFaceTr<MTetrahedron> { enum { numFaceT =  4 }; };
template <> struct ElemFaceTr<MHexahedron>  { enum { numFaceT =  6 }; };
template <> struct ElemFaceTr<MPrism>       { enum { numFaceT =  5 }; };
template <> struct ElemFaceTr<MPyramid>     { enum { numFaceT =  5 }; };

//--This traits class gives the number of element types in entity Ent

template <typename Ent> struct EntTr;
template <> struct EntTr<GFace>
{
  typedef MEdge FaceT;
  enum { numElemTypes = 2 };
};
template <> struct EntTr<GRegion>
{
  typedef MFace FaceT;
  enum { numElemTypes = 4 };
};

//--This traits class gives iterator types and begin and end iterators for
//--element type number N in entity Ent.

template <typename Ent, int N> struct EntElemTr;
template <> struct EntElemTr<GFace, 1> {
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
template <> struct EntElemTr<GFace, 2> {
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
template <> struct EntElemTr<GRegion, 1> {
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
template <> struct EntElemTr<GRegion, 2> {
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
template <> struct EntElemTr<GRegion, 3> {
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
template <> struct EntElemTr<GRegion, 4> {
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
template <> struct FaceTr<MEdge> {
  typedef std::map<MEdge, FaceData, Less_Edge> BoFaceMap;
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
template <> struct FaceTr<MFace> {
  typedef std::map<MFace, FaceData, Less_Face> BoFaceMap;
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


/*******************************************************************************
 *
 * class: MZone
 *
 * Purpose
 * =======
 *
 *   Generates a definition of a zone based on entities and/or partitions.
 *
 *   Template parameters:
 *     DIM              - dimension of the problem
 *
 * Notes
 * =====
 *
 *   - explicitly instantiated in 'MZone.cpp'
 *
 ******************************************************************************/

template <unsigned DIM>
class MZone
{


/*==============================================================================
 * Internal types
 *============================================================================*/

 private:
  typedef typename DimTr<DIM>::FaceT FaceT;
  typedef typename FaceTr<FaceT>::BoFaceMap BoFaceMap;
  typedef typename std::map<const MVertex*,
    ZoneVertexData<typename BoFaceMap::const_iterator>,
    std::less<const MVertex*> > BoVertexMap;


/*==============================================================================
 * Member functions
 *============================================================================*/

 public:

//--Default constructor.

  MZone()
    : numBoVert(0)
  {
    elemVec.reserve(8192);
  }

/*--------------------------------------------------------------------*
 * Elements added from entities.
 * Note: It is much easier to keep these in the .cpp file but that
 *   requries explicit instantiations for each Ent and EntIter.
 *   Currently, instantiations only exist for containers of type:
 *     vector
 *   More can be added as required at the end of MZone.cpp
 *--------------------------------------------------------------------*/

//--Add all elements in a container of entities.  The specific type of entity
//--is not known and must be specified as parameter 'Ent'.

  template <typename Ent, typename EntIter>
  void add_elements_in_entities(EntIter begin, EntIter end,
                                const int partition = -1);

//--Add elements in a single entity.

  template <typename Ent, typename EntPtr>
  void add_elements_in_entity(EntPtr entity, const int partition = -1);
  

/*--------------------------------------------------------------------*
 * Reset the database
 *--------------------------------------------------------------------*/

  void clear() 
  {
    elemVec.clear();
    vertMap.clear();
    boFaceMap.clear();
    boVertMap.clear();
    zoneVertVec.clear();
    for(int i = 0; i != MSH_NUM_TYPE; ++i) {
      zoneElemConn[i].clear();
    }
    numBoVert = 0;
  }

/*--------------------------------------------------------------------*
 * Process/query the zone - only after all elements have been added!
 *--------------------------------------------------------------------*/

//--Compute the zone data

  int zoneData();

//--Total number of elements

  int totalElements() const 
  {
    int numElem = 0;
    for(int iElemType = 0; iElemType != MSH_NUM_TYPE; ++iElemType)
      numElem += zoneElemConn[iElemType].numElem;
    return numElem;
  }

//--Number of element types

  int numElementTypes() const
  {
    int numElemType = 0;
    for(int iElemType = 0; iElemType != MSH_NUM_TYPE; ++iElemType)
      if(zoneElemConn[iElemType].numElem > 0) ++numElemType;
    return numElemType;
  }


/*==============================================================================
 * Member data
 *============================================================================*/

 private:

//--Data members

  ElementVec elemVec;                   // Set of unique elements
  VertexMap vertMap;                    // Set of unique vertices and associated
                                        // numbers in the zone
  BoFaceMap boFaceMap;                  // Map of boundary faces
  BoVertexMap boVertMap;                // Map of boundary vertices

 public:

  // I/O
  VertexVec zoneVertVec;
  ElementConnectivity zoneElemConn[MSH_NUM_TYPE];
                                        // Connectivity for each type of element
  int numBoVert;


/*==============================================================================
 * Friends
 *============================================================================*/

  friend class MZoneBoundary<DIM>;

};

#endif
