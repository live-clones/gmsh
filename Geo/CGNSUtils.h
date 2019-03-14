// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// CGNSUtils.h - Copyright (C) 2008 S. Guzik, C. Geuzaine, J.-F. Remacle

// FIXME: the contents of this file will be removed in a future release of Gmsh.

#ifndef CGNS_UTILS_H
#define CGNS_UTILS_H

#include <map>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cstddef>

#include "MElement.h"
#include "GFace.h"
#include "GRegion.h"
#include "MEdgeHash.h"
#include "MFaceHash.h"
#include "GmshMessage.h"

// FIXME: This code is faaaar too complicated for what it does - as is the whole
// CGNS mess. Until we rewrite this whole thing, let's quiet GCC about the
// reinterpret_casts dereferencing type-punned pointer, which will break
// strict-aliasing rules:

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"

/*******************************************************************************
 *
 * This lightweight pool class attempts to reduce memory usage by having the
 * unused elements save links to each other using whatever memory they have
 * available.
 *
 * The elements (type T) need to implement the member functions:
 *
 * void set_pool_prev(void *const)  - save an address
 * void *get_pool_prev()            - return the saved address
 *
 * For example,
 *
 *----------*

struct Box
{
   int i;
   int j;
   void set_pool_prev(void *const p)
   {
      *reinterpret_cast<void**>(&i) = p;
   }
   void *get_pool_prev()
   {
      return *reinterpret_cast<void**>(&i);
   }
};

 *----------*
 *
 * Ensure that the memory used for each type T is at least 64 bits and note
 * that this Pool does not do any construction or destruction of the elements.
 *
 ******************************************************************************/

namespace CCon // "Custom Container"
{

  template <typename T> class Block;

  /*==============================================================================
   *
   * Class Pool
   *
   * Purpose
   * =======
   *
   *   Interface to the pool
   *
   *============================================================================*/

  template <typename T> class Pool {
  public:
    // Constructor
    Pool(const unsigned _blockSize = 128)
      : tailBlock(0), tailElement(0), blockSize(_blockSize), numUsedElement(0)
    {
    }

    // Destructor
    ~Pool() { delete_all_blocks(); }

    // Get an element
    void *get()
    {
      if(!tailElement) create_block();
      void *const rval = tailElement;
      tailElement = static_cast<T *>(tailElement->get_pool_prev());
      ++numUsedElement;
      return rval;
    }

    // Return an element
    void remit(T *const elem)
    {
      elem->set_pool_prev(tailElement);
      tailElement = elem;
      --numUsedElement;
    }

    // Free memory used by the pool
    void free_memory()
    {
      if(numUsedElement == 0)
        delete_all_blocks();
      else
        Msg::Debug("Request to delete pool with used elements in "
                   "CustomContainer.h");
    }

  private:
    // Data
    Block<T> *tailBlock;
    T *tailElement;
    unsigned blockSize;
    unsigned numUsedElement;

    // Create a new block
    void create_block()
    {
      tailBlock = new Block<T>(tailBlock, blockSize);
      const unsigned back = blockSize - 1;
      tailBlock->array[back].set_pool_prev(tailElement);
      tailElement = &tailBlock->array[back];
      for(int n = back; n--;) {
        T *const prev = tailElement--;
        tailElement->set_pool_prev(prev);
      }
    }

    // Delete all blocks
    void delete_all_blocks()
    {
      while(tailBlock) {
        Block<T> *const block = tailBlock;
        tailBlock = block->prev;
        delete block;
      }
      tailElement = 0;
    }

    // Copy and assignment are not permitted
    Pool(const Pool &);
    Pool &operator=(const Pool &);
  };

  /*==============================================================================
   *
   * Class Block
   *
   * Purpose
   * =======
   *
   *   Implements a block of uninitialized memory for type T
   *
   *============================================================================*/

  template <typename T> class Block {
    // Data
    Block *const prev;
    T *array;

    // Constructor
    Block(Block *const _prev, const unsigned blockSize) : prev(_prev)
    {
      array = static_cast<T *>(std::malloc(sizeof(T) * blockSize));
    }

    // Destructor
    ~Block() { std::free(array); }

    friend class Pool<T>;
  };

  /*******************************************************************************
   *
   * This allocator-like class is used to implement many small vectors which are
   * sized according to the number of boundary vertices commonly expected to
   * connect to a vertex in 2D and 3D zones:
   *   2 - expected faces for vertex on zone edge in 2D
   *   6 - expected faces for vertex on zone face in 3D
   *   8 - overflow faces for vertex on zone face in 3D
   *  16 - approximate faces for vertices on zone edges and corners in 3D
   * Memory for the above sizes are pooled for reuse.  Larger sizes are
   *permitted and will be allocated using 'new' and 'delete'.
   *
   ******************************************************************************/

  /*==============================================================================
   *
   * Class FaceAllocator
   *
   * Purpose
   * =======
   *
   *   Lightweight allocator for class FaceVector
   *
   * Notes
   * =====
   *
   *   - This lightweight allocator expects only primitive types.  Constructors
   *     and destructors are not called for type T.
   *   - The memory is encapsulated in the Face* structures.  Handles to these
   *     structures use the data array.  A pointer to the structure is regained
   *     using the handle and an offset.  This is mostly cautionary as the
   *offset is normally expected to be zero.
   *   - No per-object data is stored as per normal requirements for allocators.
   *     Critical OpenMP sections are defined since multiple threads can access
   *     the allocator.
   *   - If set_offsets is to be used, T must have a default constructor.
   *
   *============================================================================*/

  template <typename T> class FaceAllocator {
  public:
    // Memory structures
    struct Face2 {
      T faces[2];
      void set_pool_prev(void *const p)
      {
        *reinterpret_cast<void **>(faces) = p;
      }
      void *get_pool_prev() { return *reinterpret_cast<void **>(faces); }
      ptrdiff_t get_offset() const
      {
        return reinterpret_cast<const char *>(this) -
               reinterpret_cast<const char *>(faces);
      }
    };
    struct Face6 {
      T faces[6];
      void set_pool_prev(void *const p)
      {
        *reinterpret_cast<void **>(faces) = p;
      }
      void *get_pool_prev() { return *reinterpret_cast<void **>(faces); }
      ptrdiff_t get_offset() const
      {
        return reinterpret_cast<const char *>(this) -
               reinterpret_cast<const char *>(faces);
      }
    };
    struct Face8 {
      T faces[8];
      void set_pool_prev(void *const p)
      {
        *reinterpret_cast<void **>(faces) = p;
      }
      void *get_pool_prev() { return *reinterpret_cast<void **>(faces); }
      ptrdiff_t get_offset() const
      {
        return reinterpret_cast<const char *>(this) -
               reinterpret_cast<const char *>(faces);
      }
    };
    struct Face16 {
      T faces[16];
      void set_pool_prev(void *const p)
      {
        *reinterpret_cast<void **>(faces) = p;
      }
      void *get_pool_prev() { return *reinterpret_cast<void **>(faces); }
      ptrdiff_t get_offset() const
      {
        return reinterpret_cast<const char *>(this) -
               reinterpret_cast<const char *>(faces);
      }
    };

    // Set offsets
    static void set_offsets()
    {
      Face2 f2;
      offset2 = f2.get_offset();
      Face6 f6;
      offset6 = f6.get_offset();
      Face8 f8;
      offset8 = f8.get_offset();
      Face16 f16;
      offset16 = f16.get_offset();
    }

    // Release memory used by the pools
    static void free_pool_memory()
    {
      face2Pool.free_memory();
      face6Pool.free_memory();
      face8Pool.free_memory();
      face16Pool.free_memory();
    }

    // Allocate the array
    void allocate(const unsigned short nCapacity, T *&faces)
    {
#if defined(_OPENMP)
#pragma omp critical(FaceAllocator_allocate)
#endif
      {
        switch(nCapacity) {
        case 0: faces = 0; break;
        case 2: {
          Face2 *f2 = static_cast<Face2 *>(face2Pool.get());
          faces = f2->faces;
        } break;
        case 6: {
          Face6 *f6 = static_cast<Face6 *>(face6Pool.get());
          faces = f6->faces;
        } break;
        case 8: {
          Face8 *f8 = static_cast<Face8 *>(face8Pool.get());
          faces = f8->faces;
        } break;
        case 16: {
          Face16 *f16 = static_cast<Face16 *>(face16Pool.get());
          faces = f16->faces;
        } break;
        default: {
          faces = static_cast<T *>(
            std::malloc(sizeof(T) * nCapacity + sizeof(void *)));
        } break;
        }
      }
      // omp: end critical
    }

    // Grow the array of faces by 2, 6, 8, and then 2*nUsed.  Pools are used for
    // arrays with size 2, 6, and 8.
    void grow(unsigned short &nCapacity, T *&faces)
    {
#if defined(_OPENMP)
#pragma omp critical(FaceAllocator_grow)
#endif
      {
        switch(nCapacity) {
        case 0: {
          Face2 *f2 = static_cast<Face2 *>(face2Pool.get());
          faces = f2->faces;
          nCapacity = 2;
        } break;
        case 2: {
          Face6 *f6 = static_cast<Face6 *>(face6Pool.get());
          std::memcpy(f6->faces, faces, 2 * sizeof(T));
          Face2 *f2 = reinterpret_cast<Face2 *>(faces + offset2);
          face2Pool.remit(f2);
          faces = f6->faces;
          nCapacity = 6;
        } break;
        case 6: {
          Face8 *f8 = static_cast<Face8 *>(face8Pool.get());
          std::memcpy(f8->faces, faces, 6 * sizeof(T));
          Face6 *f6 = reinterpret_cast<Face6 *>(faces + offset6);
          face6Pool.remit(f6);
          faces = f8->faces;
          nCapacity = 8;
        } break;
        case 8: {
          Face16 *f16 = static_cast<Face16 *>(face16Pool.get());
          std::memcpy(f16->faces, faces, 8 * sizeof(T));
          Face8 *f8 = reinterpret_cast<Face8 *>(faces + offset8);
          face8Pool.remit(f8);
          faces = f16->faces;
          nCapacity = 16;
        } break;
        // Allocate outside pool for more than 16 faces
        case 16: {
          Face16 *f16 = reinterpret_cast<Face16 *>(faces + offset16);
          faces =
            static_cast<T *>(std::malloc(sizeof(T) * 32 + sizeof(void *)));
          std::memcpy(faces, f16->faces, 16 * sizeof(T));
          face16Pool.remit(f16);
          nCapacity = 32;
        } break;
        default: {
          T *newFace = static_cast<T *>(
            std::malloc(sizeof(T) * 2 * nCapacity + sizeof(void *)));
          std::memcpy(newFace, faces, nCapacity * sizeof(T));
          std::free(faces);
          faces = newFace;
          nCapacity *= 2;
        } break;
        }
      }
      // omp: end critical
    }

    // Deallocate an array
    void deallocate(unsigned short &nCapacity, T *const faces)
    {
#if defined(_OPENMP)
#pragma omp critical(FaceAllocator_deallocate)
#endif
      {
        switch(nCapacity) {
        case 0: break;
        case 2: {
          Face2 *const f2 = reinterpret_cast<Face2 *>(faces + offset2);
          face2Pool.remit(f2);
        } break;
        case 6: {
          Face6 *const f6 = reinterpret_cast<Face6 *>(faces + offset6);
          face6Pool.remit(f6);
        } break;
        case 8: {
          Face8 *const f8 = reinterpret_cast<Face8 *>(faces + offset8);
          face8Pool.remit(f8);
        } break;
        case 16: {
          Face16 *const f16 = reinterpret_cast<Face16 *>(faces + offset16);
          face16Pool.remit(f16);
        } break;
        default: {
          std::free(faces);
        } break;
        }
      }
      // omp: end critical
      nCapacity = 0;
    }

  private:
    // Data
    static Pool<Face2> face2Pool;
    static Pool<Face6> face6Pool;
    static Pool<Face8> face8Pool;
    static Pool<Face16> face16Pool;
    static ptrdiff_t offset2;
    static ptrdiff_t offset6;
    static ptrdiff_t offset8;
    static ptrdiff_t offset16;
  };

  // Definitions for static data members of class FaceAllocator
  template <typename T>
  Pool<typename FaceAllocator<T>::Face2> FaceAllocator<T>::face2Pool;
  template <typename T>
  Pool<typename FaceAllocator<T>::Face6> FaceAllocator<T>::face6Pool;
  template <typename T>
  Pool<typename FaceAllocator<T>::Face8> FaceAllocator<T>::face8Pool;
  template <typename T>
  Pool<typename FaceAllocator<T>::Face16> FaceAllocator<T>::face16Pool;
  template <typename T> ptrdiff_t FaceAllocator<T>::offset2 = 0;
  template <typename T> ptrdiff_t FaceAllocator<T>::offset6 = 0;
  template <typename T> ptrdiff_t FaceAllocator<T>::offset8 = 0;
  template <typename T> ptrdiff_t FaceAllocator<T>::offset16 = 0;

  /*******************************************************************************
   *
   * This class is like a std::vector but optimized for small vectors containing
   * elements with only primitive data.
   *
   ******************************************************************************/

  /*==============================================================================
   *
   * Class FaceVector
   *
   * Purpose
   * =======
   *
   *   Lightweight small vectors
   *
   * Notes
   * =====
   *
   *   - The only way to add elements is by 'push_back'
   *   - Erasing may reorder the elements.
   *   - T must only contain primitive types
   *   - init_memory() should be called before constructing any class
   *     FaceVector<T> and release_memory() should be called after all classes
   *     FaceVector<T> have been destroyed.  These routines explictly manage
   *     memory used by pools in the allocator.
   *
   *============================================================================*/

  template <typename T> class FaceVector : public FaceAllocator<T> {
  protected:
    using FaceAllocator<T>::deallocate;
    using FaceAllocator<T>::grow;

  public:
    // Constructor
    FaceVector() : _size(0), _capacity(0) {}
    // Unlike std::vector, the following sets the capacity to 'n'.  The size is
    // still 0.
    FaceVector(const unsigned short n) : _size(0)
    {
      _capacity = valid_capacity(n);
      allocate(_capacity, faces);
    }

    // Destructor
    ~FaceVector() { deallocate(_capacity, faces); }

    // Index the vector
    const T &operator[](const int i) const { return faces[i]; }
    T &operator[](const int i) { return faces[i]; }

    // Add element to end
    T &push_back(const T val)
    {
      if(_size == _capacity) grow(_capacity, faces);
      return faces[_size++] = val;
    }

    // Just increment the size (push an empty element)
    T &push_empty()
    {
      if(_size == _capacity) grow(_capacity, faces);
      return faces[_size++];
    }

    // Erase an element
    void erase(const int i) { faces[i] = faces[--_size]; }

    // Vector size and capacity
    unsigned size() const { return _size; }
    unsigned capacity() const { return _capacity; }

    // Memory managment
    // Init sets offsets to ensure pointers can be recovered.  It should be
    // called once before using FaceVector<T>
    static void init_memory() { FaceAllocator<T>::set_offsets(); }
    // This releases memory used by the pools if no pool elements are in use. It
    // should be called after use of FaceVector<T> is finished and all
    // FaceVector<T> classes have been destroyed.
    static void release_memory() { FaceAllocator<T>::free_pool_memory(); }

  private:
    // Data
    T *faces;
    unsigned short _size;
    unsigned short _capacity;

    // Get a valid capacity size (returns n above 16)
    unsigned valid_capacity(unsigned n) const
    {
      if(n == 0) return 0;
      if(n <= 2) return 2;
      if(n <= 6) return 6;
      if(n <= 8) return 8;
      if(n <= 16) return 16;
      return n;
    }
  };

} // End of namespace CCon

#pragma GCC diagnostic pop

/*******************************************************************************
 *
 * The classes in this file are used to define and generate representations of
 * zones.
 *
 ******************************************************************************/

/*==============================================================================
 * Forward declarations
 *============================================================================*/

template <unsigned DIM> class MZoneBoundary;

/*==============================================================================
 * Required types
 *============================================================================*/

//--Record of unique elements

struct ElemData {
  MElement *element;
  int index;
  ElemData(MElement *const _element) : element(_element), index(0) {}
};

typedef std::vector<ElemData> ElementVec;

//--Record of unique vertices

typedef std::map<MVertex *, int, std::less<MVertex *> > VertexMap;

//--Data for each face.  Ultimately, only faces on the boundary of the zone are
//--stored.  Value type for 'BoFaceMap'.

struct FaceData {
  MElement *parentElement;
  int parentFace;
  int parentElementIndex;
  int faceIndex;
  FaceData(MElement *const _parentElement, const int _parentFace,
           const int _parentElementIndex)
    : parentElement(_parentElement), parentFace(_parentFace),
      parentElementIndex(_parentElementIndex), faceIndex(0)
  {
  }
};

//--Provides information and boundary faces connected to a vertex.  Value type
//--for 'BoVertexMap'

template <typename BFMapIt> struct ZoneVertexData {
  CCon::FaceVector<BFMapIt> faces; // Vector optimized for storing faces
  int index;
};

/*--------------------------------------------------------------------*
 * User I/O
 *--------------------------------------------------------------------*/

struct ElementConnectivity {
  std::vector<int> connectivity;
  int numElem;
  int numBoElem;
  int iConn;
  // Constructor
  ElementConnectivity() : numElem(0), numBoElem(0), iConn(0) {}
  // Member functions
  void add_to_connectivity(const int i) { connectivity[iConn++] = i; }
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

typedef std::vector<MVertex *> VertexVec;

/*==============================================================================
 * Traits classes - that return information about a type
 *============================================================================*/

template <typename FaceT> struct LFaceTr;
template <> struct LFaceTr<MEdge> {
  typedef std::map<MEdge, FaceData, Less_Edge> BoFaceMap;
};
template <> struct LFaceTr<MFace> {
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

template <unsigned DIM> class MZone {
  /*==============================================================================
   * Internal types
   *============================================================================*/

public:
  typedef typename DimTr<DIM>::FaceT FaceT;
  typedef typename LFaceTr<FaceT>::BoFaceMap BoFaceMap;
  typedef typename std::map<const MVertex *,
                            ZoneVertexData<typename BoFaceMap::const_iterator>,
                            std::less<const MVertex *> >
    BoVertexMap;

  /*==============================================================================
   * Member functions
   *============================================================================*/

public:
  //--Default constructor.

  MZone() : numBoVert(0) { elemVec.reserve(8192); }

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
    for(int i = 0; i != MSH_MAX_NUM; ++i) {
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
    for(int iElemType = 0; iElemType != MSH_MAX_NUM; ++iElemType)
      numElem += zoneElemConn[iElemType].numElem;
    return numElem;
  }

  //--Number of element types

  int numElementTypes() const
  {
    int numElemType = 0;
    for(int iElemType = 0; iElemType != MSH_MAX_NUM; ++iElemType)
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

  ElementVec elemVec; // Set of unique elements
  VertexMap vertMap; // Set of unique vertices and associated
                     // numbers in the zone
  BoFaceMap boFaceMap; // Map of boundary faces
  BoVertexMap boVertMap; // Map of boundary vertices

public:
  // I/O
  VertexVec zoneVertVec;
  ElementConnectivity zoneElemConn[MSH_MAX_NUM];
  // Connectivity for each type of element
  int numBoVert;

  /*==============================================================================
   * Friends
   *============================================================================*/

  friend class MZoneBoundary<DIM>;
};

/*******************************************************************************
 *
 * - The classes in this file are used to determine connectivity between
 *   multiple zones and, eventually, the domain boundary vertices
 *
 ******************************************************************************/

/*==============================================================================
 * Required types
 *============================================================================*/

/*--------------------------------------------------------------------*
 * Internal zone connectivity
 *--------------------------------------------------------------------*/

//--Interface between two zones for connectivity

struct ZonePair {
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
struct Less_ZonePair : public std::binary_function<ZonePair, ZonePair, bool> {
  bool operator()(const ZonePair &zpA, const ZonePair &zpB) const
  {
    if(zpA.zone1 < zpB.zone1) return true;
    if(zpA.zone1 > zpB.zone1) return false;
    if(zpA.zone2 < zpB.zone2) return true;
    return false;
  }
};

//--Definition of the zone connectivity (a vector of vertex pairs for 2 zones).

struct ZoneConnectivity {
  // Internal structures
  struct VertexPair // Pairs of vertices.  Ordered based on
                    // zone indices.
  {
    MVertex *vertex;
    int vertexIndex1;
    int vertexIndex2;
    // Constructors
    VertexPair() : vertex(0), vertexIndex1(0), vertexIndex2(0) {}
    VertexPair(MVertex *const _vertex, const int zone1, const int zone2,
               const int _vertexIndex1, const int _vertexIndex2)
      : vertex(_vertex), vertexIndex1(_vertexIndex1),
        vertexIndex2(_vertexIndex2)
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
    vertexPairVec.reserve(32); // Avoid small reallocations by push_back()
  }
};

struct ZoneConnectivityByElem {
  // Internal structures
  struct ElementPair // Pairs of elements.  Ordered based on
                     // zone indices
  {
    int elemIndex1;
    int elemIndex2;
    // Constructors
    ElementPair() : elemIndex1(0), elemIndex2(0) {}
    ElementPair(const int zone1, const int zone2, const int _elemIndex1,
                const int _elemIndex2)
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
    elemPairVec.reserve(32); // Avoid small reallocations by push_back()
  }
};

//--Output type for zone connectivity

typedef std::map<ZonePair, ZoneConnectivity, Less_ZonePair> ZoneConnMap;

/*--------------------------------------------------------------------*
 * Boundaries at the domain extent
 *--------------------------------------------------------------------*/

struct VertexBoundary {
  int zoneIndex;
  int bcPatchIndex;
  SVector3 normal;
  MVertex *vertex;
  int vertexIndex;
  // Constructors
  VertexBoundary() : vertex(0), vertexIndex(0) {}
  VertexBoundary(const int _zoneIndex, const int _bcPatchIndex,
                 const SVector3 &_normal, MVertex *const _vertex,
                 const int _vertexIndex)
    : zoneIndex(_zoneIndex), bcPatchIndex(_bcPatchIndex), normal(_normal),
      vertex(_vertex), vertexIndex(_vertexIndex)
  {
  }
};

typedef std::vector<VertexBoundary> ZoneBoVec;

//--Function object for sorting the ZoneBoVec vector by zone and then BC patch
//--index

struct ZoneBoVecSort {
  bool operator()(const int i0, const int i1)
  {
    if(zoneBoVec[i0].zoneIndex == zoneBoVec[i1].zoneIndex)
      return zoneBoVec[i0].bcPatchIndex < zoneBoVec[i1].bcPatchIndex;
    return zoneBoVec[i0].zoneIndex < zoneBoVec[i1].zoneIndex;
  }
  ZoneBoVecSort(const ZoneBoVec &_zoneBoVec) : zoneBoVec(_zoneBoVec) {}

private:
  const ZoneBoVec &zoneBoVec;
};

struct ElementBoundary {
  int zoneIndex;
  int bcPatchIndex;
  SVector3 normal;
  int elemIndex;
  // Constructors
  ElementBoundary() : elemIndex(0) {}
  ElementBoundary(const int _zoneIndex, const int _bcPatchIndex,
                  const SVector3 &_normal, const int _elemIndex)
    : zoneIndex(_zoneIndex), bcPatchIndex(_bcPatchIndex), normal(_normal),
      elemIndex(_elemIndex)
  {
  }
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

template <unsigned DIM> class MZoneBoundary {
  /*==============================================================================
   * Internal types
   *============================================================================*/

  //--Type of face (MEdge or MFace)

private:
  typedef typename DimTr<DIM>::FaceT FaceT;

  //--Data stored for connectivity of vertices

public:
  template <typename FaceT> struct GlobalVertexData {
    struct FaceDataB {
      // NBN: cannot use a FaceT object in FaceVector.
      // class FaceT has embedded std::vector objects;
      // custom allocator for FaceVector<T> does not call ctors,
      // but std:: dtors will try to delete _v, _si
      //
      // Simple fix: use a pointer to FaceT, then build the
      // FaceT object once the FaceDataB structure has been
      // safely added to the container (push_back)

      // FaceT  face;      // NBN: FaceT contains std:: containers
      FaceT *face; // NBN: use FaceT* (then init in two steps)

      MElement *parentElement;
      int parentFace;
      int faceIndex;
      int zoneIndex;
      FaceDataB(const int _zoneIndex,
                const typename MZone<DIM>::BoFaceMap::const_iterator bFMapIt)
        : // face(bFMapIt->first),
          face(NULL), // NBN: need to load this after insertion into container
          parentElement(bFMapIt->second.parentElement),
          parentFace(bFMapIt->second.parentFace),
          faceIndex(bFMapIt->second.faceIndex), zoneIndex(_zoneIndex)
      {
      }
      //     private:  // Default constructor should be private ... but
      //     currently
      // fails on some compilers (earlier versions of g++?)
      // The default constructor is required by 'set_offsets()' in
      // class 'FaceAllocator'.  This is invoked by preInit() below.
      FaceDataB();
      friend class CCon::FaceAllocator<FaceDataB>;
    };
    struct ZoneData {
      int vertexIndex;
      int zoneIndex;
      ZoneData(const int _vertexIndex, const int _zoneIndex)
        : vertexIndex(_vertexIndex), zoneIndex(_zoneIndex)
      {
      }
      //     private:  // Default constructor should be private ... but
      //     currently
      // fails on some compilers (earlier versions of g++?)
      // The default constructor is required by 'set_offsets()' in
      // class 'FaceAllocator'.  This is invoked by preInit() below.
      ZoneData() : vertexIndex(0), zoneIndex(0) // NBN: init members
      {
      }
      friend class CCon::FaceAllocator<ZoneData>;
    };
    CCon::FaceVector<FaceDataB> faces;
    CCon::FaceVector<ZoneData> zoneData;
    // A 'FaceVector' is not strictly
    // optimized for the vertices but should
    // still work quite well.
    // Constructor
    GlobalVertexData() {}
  };

private:
  typedef std::map<const MVertex *, GlobalVertexData<FaceT>,
                   std::less<const MVertex *> >
    GlobalBoVertexMap;

  /*==============================================================================
   * Member functions
   *============================================================================*/

public:
  //--Reset the database

  void clear()
  {
    // NBN: using FaceT* so need to dealloc:
    int icount = 0;
    typename GlobalBoVertexMap::iterator itEnd = globalBoVertMap.end();
    for(typename GlobalBoVertexMap::iterator itBoV = globalBoVertMap.begin();
        itBoV != itEnd; ++itBoV) {
      // ... clear the faces
      GlobalVertexData<FaceT> &ref = itBoV->second;
      std::size_t nf = ref.faces.size();
      for(std::size_t i = 0; i < nf; ++i) {
        ++icount;
        FaceT *p = ref.faces[i].face;
        if(p) {
          delete(p);
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

  //--Return exterior boundary vertices (unconnected vertices at the extent of
  //the
  //--domain

  int exteriorBoundaryVertices(const int normalSource, ZoneBoVec &zoneBoVec);

  //--Memory management

  static void preInit()
  {
    CCon::FaceVector<
      typename GlobalVertexData<FaceT>::FaceDataB>::init_memory();
    CCon::FaceVector<typename GlobalVertexData<FaceT>::ZoneData>::init_memory();
  }
  static void postDestroy()
  {
    CCon::FaceVector<
      typename GlobalVertexData<FaceT>::FaceDataB>::release_memory();
    CCon::FaceVector<
      typename GlobalVertexData<FaceT>::ZoneData>::release_memory();
  }

  /*==============================================================================
   * Member data
   *============================================================================*/

private:
  //--Data members

  GlobalBoVertexMap globalBoVertMap; // Map of unconnected boundary vertices
                                     // for the entire domain
};

#endif
