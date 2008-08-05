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
 * Traits classes - that return information about a type
 *============================================================================*/

template <typename FaceT> struct LFaceTr;
template <> struct LFaceTr<MEdge> 
{
  typedef std::map<MEdge, FaceData, Less_Edge> BoFaceMap;
};
template <> struct LFaceTr<MFace> 
{
  typedef std::map<MFace, FaceData, Less_Face> BoFaceMap;
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
 *   - this class uses some explicit memory management.  Call preInit() before
 *     constructing any class MZone and postDestroy() after all MZone classes
 *     have been destroyed.
 *
 ******************************************************************************/

template <unsigned DIM>
class MZone
{


/*==============================================================================
 * Internal types
 *============================================================================*/

 public:
  typedef typename DimTr<DIM>::FaceT FaceT;
  typedef typename LFaceTr<FaceT>::BoFaceMap BoFaceMap;
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

  template <typename EntIter>
  void add_elements_in_entities(EntIter begin, EntIter end,
                                const int partition = -1);

//--Add elements in a single entity.

  template <typename EntPtr>
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
  
//--Memory management

  static void preInit()
  {
    CCon::FaceVector<typename BoFaceMap::const_iterator>::init_memory();
  }
  static void postDestroy()
  {
    CCon::FaceVector<typename BoFaceMap::const_iterator>::release_memory();
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
