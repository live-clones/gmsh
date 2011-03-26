// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
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
    if(_zone1 < _zone2) {
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
               const int zone1, const int zone2,
               const int _vertexIndex1, const int _vertexIndex2)
      : vertex(_vertex),
        vertexIndex1(_vertexIndex1), vertexIndex2(_vertexIndex2)
    {
      if(zone2 < zone1) {
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
    vertexPairVec.reserve(32);  // Avoid small reallocations by push_back()
  }
};

struct ZoneConnectivityByElem
{
  // Internal structures
  struct ElementPair                    // Pairs of elements.  Ordered based on
                                        // zone indices
  {
    int elemIndex1;
    int elemIndex2;
    // Constructors
    ElementPair()
      : elemIndex1(0), elemIndex2(0)
    { }
    ElementPair(const int zone1, const int zone2,
                const int _elemIndex1, const int _elemIndex2)
      : elemIndex1(_elemIndex1), elemIndex2(_elemIndex2)
    {
      if(zone2 < zone1) {
        elemIndex1 = _elemIndex2;
        elemIndex2 = _elemIndex1;
      }
    }
  };
  // Data
  std::vector<ElementPair> elemPairVec;
  // Constructor
  ZoneConnectivityByElem()
  {
    elemPairVec.reserve(32);  // Avoid small reallocations by push_back()
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

struct ElementBoundary
{
  int zoneIndex;
  int bcPatchIndex;
  SVector3 normal;
  int elemIndex;
  // Constructors
  ElementBoundary()
    : elemIndex(0)
  { }
  ElementBoundary(const int _zoneIndex, const int _bcPatchIndex,
                  const SVector3 &_normal, const int _elemIndex)
    : zoneIndex(_zoneIndex), bcPatchIndex(_bcPatchIndex), normal(_normal),
      elemIndex(_elemIndex)
  { }
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

//--Type of face (MEdge or MFace)

 private:

  typedef typename DimTr<DIM>::FaceT FaceT;

//--Data stored for connectivity of vertices

 public:

  template<typename FaceT>
  struct GlobalVertexData
  {
    struct FaceDataB
    {
      // NBN: cannot use a FaceT object in FaceVector. 
      // class FaceT has embedded std::vector objects;
      // custom allocator for FaceVector<T> does not call ctors,
      // but std:: dtors will try to delete _v, _si
      // 
      // Simple fix: use a pointer to FaceT, then build the 
      // FaceT object once the FaceDataB structure has been 
      // safely added to the container (push_back)

    //FaceT  face;      // NBN: FaceT contains std:: containers 
      FaceT* face;      // NBN: use FaceT* (then init in two steps)

      MElement *parentElement;
      int parentFace;
      int faceIndex;
      int zoneIndex;
      FaceDataB(const int _zoneIndex,
                const typename MZone<DIM>::BoFaceMap::const_iterator bFMapIt)
        : 
      //face(bFMapIt->first), 
        face(NULL),   // NBN: need to load this after insertion into container
        parentElement(bFMapIt->second.parentElement),
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
      ZoneData() 
        : vertexIndex(0), zoneIndex(0)    // NBN: init members
      { }
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

 private:

  typedef std::map<const MVertex*, GlobalVertexData<FaceT>,
    std::less<const MVertex*> > GlobalBoVertexMap;


/*==============================================================================
 * Member functions
 *============================================================================*/

 public:

//--Reset the database

  void clear()
  {
    // NBN: using FaceT* so need to dealloc:
    int icount = 0;
    GlobalBoVertexMap::iterator itEnd = globalBoVertMap.end();
    for (GlobalBoVertexMap::iterator itBoV = globalBoVertMap.begin(); 
          itBoV != itEnd; ++itBoV)
    {
      // ... clear the faces
      typename GlobalVertexData<FaceT>& ref = itBoV->second;
      size_t nf = ref.faces.size();
      for (int i=0; i<nf; ++i) {
        ++ icount;
        FaceT* p = ref.faces[i].face;
        if (p) {
          delete (p);
          p = NULL;
        }
      }
    }
    Msg::Info("cleared %d faces.", icount);

    // finally, clear the container
    globalBoVertMap.clear();
  }

//--Add a zone to the global map of boundary vertices and return connectivity
//--between zones.

  int interiorBoundaryVertices(const int newZoneIndex, const MZone<DIM> &mZone,
                               ZoneConnMap &zoneConnMap);
  
//--Return exterior boundary vertices (unconnected vertices at the extent of the
//--domain

  int exteriorBoundaryVertices(const int normalSource, ZoneBoVec &zoneBoVec);

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
