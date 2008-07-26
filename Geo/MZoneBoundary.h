// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// MZoneBoundary.h - Copyright (C) 2008 S. Guzik, C. Geuzaine, J.-F. Remacle
#ifndef _MZONEBOUNDARY_H_
#define _MZONEBOUNDARY_H_


/*******************************************************************************
 *
 * - The classes in this file are used to determine connectivity between
 *   multiple zones and, eventually, the domain boundary vertices
 *
 ******************************************************************************/

#include "MZone.h"


/*==============================================================================
 * Required types
 *============================================================================*/

/*--------------------------------------------------------------------*
 * Internal zone connectivity
 *--------------------------------------------------------------------*/

//--Interface between two zones for connectivity

struct ZonePair
{
  int zone1;
  int zone2;
  ZonePair(const int _zone1, const int _zone2) 
  {
    if(_zone1 < zone2) {
      zone1 = _zone1;
      zone2 = _zone2;
    }
    else {
      zone1 = _zone2;
      zone2 = _zone1;
    }
  }
};

inline bool operator==(const ZonePair &zpA, const ZonePair &zpB)
{
   return (zpA.zone1 == zpB.zone1 && zpA.zone2 == zpB.zone2);
}

// Less than for std::map
struct Less_ZonePair
  : public std::binary_function<ZonePair, ZonePair, bool> 
{
  bool operator()(const ZonePair &zpA, const ZonePair &zpB) const
  {
    if(zpA.zone1 < zpB.zone1) return true;
    if(zpA.zone1 > zpB.zone1) return false;
    if(zpA.zone2 < zpB.zone2) return true;
    return false;
  }
};

//--Definition of the zone connectivity (a vector of vertex pairs for 2 zones).

struct ZoneConnectivity
{
  // Internal structures
  struct VertexPair                     // Pairs of vertices.  Ordered based on
                                        // zone indices.
  {
    MVertex *vertex;
    int vertexIndex1;
    int vertexIndex2;
    // Constructors
    VertexPair()
      : vertex(0), vertexIndex1(0), vertexIndex2(0)
    { }
    VertexPair(MVertex *const _vertex,
               const unsigned zone1, const unsigned zone2,
               const unsigned _vertexIndex1, const unsigned _vertexIndex2)
      : vertex(_vertex)
    {
      if(zone1 < zone2) {
        vertexIndex1 = _vertexIndex1;
        vertexIndex2 = _vertexIndex2;
      }
      else {
        vertexIndex1 = _vertexIndex2;
        vertexIndex2 = _vertexIndex1;
      }
    }
  };
  // Data
  std::vector<VertexPair> vertexPairVec;
  // Constructor
  ZoneConnectivity()
  {
    vertexPairVec.reserve(32);  // Avoid small reallocations
  }
};

//--Output type for zone connectivity

typedef std::map<ZonePair, ZoneConnectivity, Less_ZonePair> ZoneConnMap;

/*--------------------------------------------------------------------*
 * Boundaries at the domain extent
 *--------------------------------------------------------------------*/

struct VertexBoundary 
{
  int zoneIndex;
  int bcPatchIndex;
  SVector3 normal;
  MVertex *vertex;
  int vertexIndex;
  // Constructors
  VertexBoundary()
    : vertex(0), vertexIndex(0)
  { }
  VertexBoundary(const int _zoneIndex, const int _bcPatchIndex,
                 const SVector3 &_normal, MVertex *const _vertex,
                 const int _vertexIndex)
    : zoneIndex(_zoneIndex), bcPatchIndex(_bcPatchIndex), normal(_normal),
    vertex(_vertex), vertexIndex(_vertexIndex)
  { }
};

typedef std::vector<VertexBoundary> ZoneBoVec;

//--Function object for sorting the ZoneBoVec vector by zone and then BC patch
//--index

struct ZoneBoVecSort
{
  bool operator()(const int i0, const int i1)
  {
    if(zoneBoVec[i0].zoneIndex == zoneBoVec[i1].zoneIndex)
      return zoneBoVec[i0].bcPatchIndex < zoneBoVec[i1].bcPatchIndex;
    return zoneBoVec[i0].zoneIndex < zoneBoVec[i1].zoneIndex;
  }
  ZoneBoVecSort(const ZoneBoVec &_zoneBoVec)
    : zoneBoVec(_zoneBoVec)
  { }
 private:
  const ZoneBoVec &zoneBoVec;
};


/*******************************************************************************
 *
 * class: MZoneBoundary
 *
 * Purpose
 * =======
 *
 *   Determines the connectivity between zones (internal boundaries) and
 *   vertices/elements at the extent of the domain (external boundaries)
 *
 *   Template parameters:
 *     DIM              - dimension of the problem
 *
 * Notes
 * =====
 *
 *   - explicitly instantiated in 'MZoneBoundary.cpp'
 *   - this class uses some explicit memory management.  Call preInit() before
 *     constructing any class MZoneBoundary and postDestroy() after all
 *     MZoneBoundary classes have been destroyed.
 *
 ******************************************************************************/

template <unsigned DIM>
class MZoneBoundary
{


/*==============================================================================
 * Internal types
 *============================================================================*/

 private:

//--Type of face (MEdge or MFace)

  typedef typename DimTr<DIM>::FaceT FaceT;

//--Data stored for connectivity of vertices

  template<typename FaceT>
  struct GlobalVertexData
  {
    struct FaceDataB
    {
      FaceT face;
      MElement *parentElement;
      int parentFace;
      int faceIndex;
      int zoneIndex;
      FaceDataB(const int _zoneIndex,
                const typename MZone<DIM>::BoFaceMap::const_iterator bFMapIt)
        : face(bFMapIt->first), parentElement(bFMapIt->second.parentElement),
        parentFace(bFMapIt->second.parentFace),
        faceIndex(bFMapIt->second.faceIndex), zoneIndex(_zoneIndex)
      { }
//     private:  // Default constructor should be private ... but currently
                 // fails on some compilers (earlier versions of g++?)
      // The default constructor is required by 'set_offsets()' in
      // class 'FaceAllocator'.  This is invoked by preInit() below.
      FaceDataB();
      friend class CCon::FaceAllocator<FaceDataB>;
    };
    struct ZoneData
    {
      int vertexIndex;
      int zoneIndex;
      ZoneData(const int _vertexIndex, const int _zoneIndex)
        : vertexIndex(_vertexIndex), zoneIndex(_zoneIndex)
      { }
//     private:  // Default constructor should be private ... but currently
                 // fails on some compilers (earlier versions of g++?)
      // The default constructor is required by 'set_offsets()' in
      // class 'FaceAllocator'.  This is invoked by preInit() below.
      ZoneData() { };
      friend class CCon::FaceAllocator<ZoneData>;
    };
    CCon::FaceVector<FaceDataB> faces;
    CCon::FaceVector<ZoneData> zoneData;
                                        // A 'FaceVector' is not strictly
                                        // optimized for the vertices but should
                                        // still work quite well.
    // Constructor
    GlobalVertexData() { }
  };

  typedef std::map<const MVertex*, GlobalVertexData<FaceT>,
    std::less<const MVertex*> > GlobalBoVertexMap;


/*==============================================================================
 * Member functions
 *============================================================================*/

 public:

//--Reset the database

  void clear()
  {
    globalBoVertMap.clear();
  }

//--Add a zone to the global map of boundary vertices and return connectivity
//--between zones.

  int interiorBoundaryVertices(const int newZoneIndex, const MZone<DIM> &mZone,
                               ZoneConnMap &zoneConnMap);
  
//--Return exterior boundary vertices (unconnected vertices at the extent of the
//--domain

  int exteriorBoundaryVertices(ZoneBoVec &zoneBoVec);

//--Memory management

  static void preInit()
  {
    CCon::FaceVector<typename GlobalVertexData<FaceT>::FaceDataB>
      ::init_memory();
    CCon::FaceVector<typename GlobalVertexData<FaceT>::ZoneData>::init_memory();
  }
  static void postDestroy()
  {
    CCon::FaceVector<typename GlobalVertexData<FaceT>::FaceDataB>
      ::release_memory();
    CCon::FaceVector<typename GlobalVertexData<FaceT>::ZoneData>
      ::release_memory();
  }


/*==============================================================================
 * Member data
 *============================================================================*/

private:

//--Data members

  GlobalBoVertexMap globalBoVertMap;    // Map of unconnected boundary vertices
                                        // for the entire domain

};


#endif
