// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// CustomContainer.h - Copyright (C) 2008 S. Guzik, C. Geuzaine, J.-F. Remacle

#ifndef _CUSTOMCONTAINER_H_
#define _CUSTOMCONTAINER_H_

#include <cstdlib>
#include <cstring>

#include "GmshMessage.h"

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

namespace CCon  // "Custom Container"
{

template <typename T>
class Block;


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

template <typename T>
class Pool
{

 public:

  // Constructor
  Pool(const unsigned _blockSize = 128)
    : tailBlock(0), tailElement(0), blockSize(_blockSize), numUsedElement(0)
  { }

  // Destructor
  ~Pool()
  {
    delete_all_blocks();
  }

  // Get an element
  void *get()
  {
    if(!tailElement) create_block();
    void *const rval = tailElement;
    tailElement =  static_cast<T*>(tailElement->get_pool_prev());
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
    if(numUsedElement == 0) delete_all_blocks();
    else Msg::Debug("Request to delete pool with used elements in "
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
    for(int n = back; n--; ) {
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
  Pool(const Pool&);
  Pool &operator=(const Pool&);

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

template <typename T>
class Block
{

  // Data
  Block *const prev;
  T *array;

  // Constructor
  Block(Block *const _prev, const unsigned blockSize)
    : prev(_prev)
  {
    array = static_cast<T*>(std::malloc(sizeof(T)*blockSize));
  }

  // Destructor
  ~Block()
  {
    std::free(array);
  }

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
 * Memory for the above sizes are pooled for reuse.  Larger sizes are permitted
 * and will be allocated using 'new' and 'delete'.
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
 *     using the handle and an offset.  This is mostly cautionary as the offset
 *     is normally expected to be zero.
 *   - No per-object data is stored as per normal requirements for allocators.
 *     Critical OpenMP sections are defined since multiple threads can access
 *     the allocator.
 *   - If set_offsets is to be used, T must have a default constructor.
 *
 *============================================================================*/

template <typename T>
class FaceAllocator
{

 public:

  // Memory structures
  struct Face2
  {
    T faces[2];
    void set_pool_prev(void *const p)
    {
      *reinterpret_cast<void**>(faces) = p;
    }
    void *get_pool_prev()
    {
      return *reinterpret_cast<void**>(faces);
    }
    ptrdiff_t get_offset() const
    {
      return reinterpret_cast<const char*>(this) -
        reinterpret_cast<const char*>(faces);
    }
  };
  struct Face6
  {
    T faces[6];
    void set_pool_prev(void *const p)
    {
      *reinterpret_cast<void**>(faces) = p;
    }
    void *get_pool_prev()
    {
      return *reinterpret_cast<void**>(faces);
    }
    ptrdiff_t get_offset() const
    {
      return reinterpret_cast<const char*>(this) -
        reinterpret_cast<const char*>(faces);
    }
  };
  struct Face8
  {
    T faces[8];
    void set_pool_prev(void *const p) 
    {
      *reinterpret_cast<void**>(faces) = p;
    }
    void *get_pool_prev()
    {
      return *reinterpret_cast<void**>(faces);
    }
    ptrdiff_t get_offset() const
    {
      return reinterpret_cast<const char*>(this) -
        reinterpret_cast<const char*>(faces);
    }
  };
  struct Face16
  {
    T faces[16];
    void set_pool_prev(void *const p) 
    {
      *reinterpret_cast<void**>(faces) = p;
    }
    void *get_pool_prev()
    {
      return *reinterpret_cast<void**>(faces);
    }
    ptrdiff_t get_offset() const
    {
      return reinterpret_cast<const char*>(this) -
        reinterpret_cast<const char*>(faces);
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
#pragma omp critical (FaceAllocator_allocate)
    {
      switch(nCapacity) {
      case 0:
        faces = 0;
        break;
      case 2:
        {
          Face2 *f2 = static_cast<Face2*>(face2Pool.get());
          faces = f2->faces;
        }
        break;
      case 6:
        {
          Face6 *f6 = static_cast<Face6*>(face6Pool.get());
          faces = f6->faces;
        }
        break;
      case 8:
        {
          Face8 *f8 = static_cast<Face8*>(face8Pool.get());
          faces = f8->faces;
        }
        break;
      case 16:
        {
          Face16 *f16 = static_cast<Face16*>(face16Pool.get());
          faces = f16->faces;
        }
        break;
      default:
        {
          faces = static_cast<T*>(std::malloc(sizeof(T)*nCapacity +
                                              sizeof(void*)));
        }
        break;
      }
    }
//omp: end critical
  }

  // Grow the array of faces by 2, 6, 8, and then 2*nUsed.  Pools are used for
  // arrays with size 2, 6, and 8.
  void grow(unsigned short &nCapacity, T *&faces)
  {
#pragma omp critical (FaceAllocator_grow)
    {
      switch(nCapacity) {
      case 0:
        {
          Face2 *f2 = static_cast<Face2*>(face2Pool.get());
          faces = f2->faces;
          nCapacity = 2;
        }
        break;
      case 2:
        {
          Face6 *f6 = static_cast<Face6*>(face6Pool.get());
          std::memcpy(f6->faces, faces, 2*sizeof(T));
          Face2 *f2 = reinterpret_cast<Face2*>(faces + offset2);
          face2Pool.remit(f2);
          faces = f6->faces;
          nCapacity = 6;
        }
        break;
      case 6:
        {
          Face8 *f8 = static_cast<Face8*>(face8Pool.get());
          std::memcpy(f8->faces, faces, 6*sizeof(T));
          Face6 *f6 = reinterpret_cast<Face6*>(faces + offset6);
          face6Pool.remit(f6);
          faces = f8->faces;
          nCapacity = 8;
        }
        break;
      case 8:
        {
          Face16 *f16 = static_cast<Face16*>(face16Pool.get());
          std::memcpy(f16->faces, faces, 8*sizeof(T));
          Face8 *f8 = reinterpret_cast<Face8*>(faces + offset8);
          face8Pool.remit(f8);
          faces = f16->faces;
          nCapacity = 16;
        }
        break;
      // Allocate outside pool for more than 16 faces
      case 16:
        {
          Face16 *f16 = reinterpret_cast<Face16*>(faces + offset16);
          faces = static_cast<T*>(std::malloc(sizeof(T)*32 + sizeof(void*)));
          std::memcpy(faces, f16->faces, 16*sizeof(T));
          face16Pool.remit(f16);
          nCapacity = 32;
        }
        break;
      default:
        {
          T *newFace = static_cast<T*>(std::malloc(sizeof(T)*2*nCapacity +
                                                   sizeof(void*)));
          std::memcpy(newFace, faces, nCapacity*sizeof(T));
          std::free(faces);
          faces = newFace;
          nCapacity *= 2;
        }
        break;
      }
    }
//omp: end critical
  }

  // Deallocate an array
  void deallocate(unsigned short &nCapacity, T *const faces)
  {
#pragma omp critical (FaceAllocator_deallocate)
    {
      switch(nCapacity) {
      case 0:
        break;
      case 2:
        {
          Face2 *const f2 = reinterpret_cast<Face2*>(faces + offset2);
          face2Pool.remit(f2);
        }
        break;
      case 6:
        {
          Face6 *const f6 = reinterpret_cast<Face6*>(faces + offset6);
          face6Pool.remit(f6);
        }
        break;
      case 8:
        {
          Face8 *const f8 = reinterpret_cast<Face8*>(faces + offset8);
          face8Pool.remit(f8);
        }
        break;
      case 16:
        {
          Face16 *const f16 = reinterpret_cast<Face16*>(faces + offset16);
          face16Pool.remit(f16);
        }
        break;
      default:
        {
          std::free(faces);
        }
        break;
      }
    }
//omp: end critical
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
template <typename T>
ptrdiff_t FaceAllocator<T>::offset2 = 0;
template <typename T>
ptrdiff_t FaceAllocator<T>::offset6 = 0;
template <typename T>
ptrdiff_t FaceAllocator<T>::offset8 = 0;
template <typename T>
ptrdiff_t FaceAllocator<T>::offset16 = 0;


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

template <typename T>
class FaceVector : public FaceAllocator<T>
{

 public:

  // Constructor
  FaceVector() : _size(0), _capacity(0) { }
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
  void erase(const int i)
  {
    faces[i] = faces[--_size];
  }

  // Vector size and capacity
  unsigned size() const { return _size; }
  unsigned capacity() const { return _capacity; }

  // Memory managment
  // Init sets offsets to ensure pointers can be recovered.  It should be called
  // once before using FaceVector<T>
  static void init_memory() { FaceAllocator<T>::set_offsets(); }
  // This releases memory used by the pools if no pool elements are in use.  It
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

}  // End of namespace CCon

#endif
