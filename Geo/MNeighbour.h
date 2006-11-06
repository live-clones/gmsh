#ifndef _MNEIGHBOUR_H_
#define _MNEIGHBOUR_H_

// Copyright (C) 2006 S. Guzik, C. Geuzaine, J.-F. Remacle
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

/*******************************************************************************
 *
 * - The classes in this file construct a database of the elements that share
 *   the lower-dimensional bounding objects (e.g., vertex, edge, or face).
 *   These lower-dimensional objects are referred to in general as polytopes.
 * - Templated traits classes are used extensively to define the characteristics
 *   of the elements and the entities.
 *
 ******************************************************************************/

#include <algorithm>
#include <iterator>
#include <vector>
#include "MElement.h"
#include "GEdge.h"
#include "GFace.h"
#include "GRegion.h"
#include "GmshDefines.h"

// #define HAVE_HASH_MAP

#if defined(HAVE_HASH_MAP)
#include "HashMap.h"
#endif


/*==============================================================================
 * File scope types
 *============================================================================*/

namespace {

typedef std::list<MElement*> Neighbours;
typedef Neighbours::const_iterator NeighboursConstIterator;
typedef Neighbours::iterator NeighboursIterator;

struct Range_t
{
  int num;
  NeighboursIterator begin;
  Range_t() : num(0) { }
};

//--Use a hash map for neighbour lookup if possible, otherwise a map will do

#if defined(HAVE_HASH_MAP)
struct Hash_VertexPtr : public std::unary_function<MVertex*, size_t>
{
  size_t operator()(const MVertex *const v) const
  {
    return HashFNV1a<sizeof(MVertex*)>::eval(v);
  }
};
typedef HASH_MAP<MVertex*, Range_t, Hash_VertexPtr, std::equal_to<MVertex*> >
VertNRange;
typedef HASH_MAP<MEdge, Range_t, Hash_Edge, Equal_Edge> EdgeNRange;
typedef HASH_MAP<MFace, Range_t, Hash_Face, Equal_Face> FaceNRange;
#else
typedef std::map<MVertex*, Range_t, std::less<MVertex*> > VertNRange;
typedef std::map<MEdge, Range_t, Less_Edge> EdgeNRange;
typedef std::map<MFace, Range_t, Less_Face> FaceNRange;
#endif
typedef VertNRange::iterator VertNRangeIterator;
typedef VertNRange::const_iterator VertNRangeConstIterator;
typedef EdgeNRange::iterator EdgeNRangeIterator;
typedef EdgeNRange::const_iterator EdgeNRangeConstIterator;
typedef FaceNRange::iterator FaceNRangeIterator;
typedef FaceNRange::const_iterator FaceNRangeConstIterator;


/*==============================================================================
 * Traits classes - that just perform compile-time checks for valid argument
 * types
 *============================================================================*/

//--This traits class checks for a pointer and strips it

// NOTE:  If the compiler sent you here, you should be using a pointer.
template <typename T> struct StripPointer;
template <typename T> struct StripPointer<T*> { typedef T Type; };
    
//--This traits class checks for valid types of entities and iterators when the
//--entity is explicitly specified

// NOTE:  If the compiler sent you here, you're using an invalid entity and/or
// invalid iterator.  Valid pairs are shown below
template <typename Ent, typename Iter> struct ValidSpecEntityIterator;
template <> struct ValidSpecEntityIterator<GEdge, GEdge*>
{ typedef void Type; };
template <> struct ValidSpecEntityIterator<GEdge, GEntity*>
{ typedef void Type; };
template <> struct ValidSpecEntityIterator<GFace, GFace*>
{ typedef void Type; };
template <> struct ValidSpecEntityIterator<GFace, GEntity*>
{ typedef void Type; };
template <> struct ValidSpecEntityIterator<GRegion, GRegion*>
{ typedef void Type; };
template <> struct ValidSpecEntityIterator<GRegion, GEntity*>
{ typedef void Type; };

//--This traits class checks for valid types of entities and iterators when the
//--entity is not specified.  It also strips the pointer.

// NOTE:  If the compiler sent you here, you're using an invalid entity or
// iterator of entities
template <typename Iter> struct ValidEntityIterator;
template <> struct ValidEntityIterator<GEdge*>
{ typedef GEdge Type; };
template <> struct ValidEntityIterator<GFace*>
{ typedef GFace Type; };
template <> struct ValidEntityIterator<GRegion*>
{ typedef GRegion Type; };

//--This traits class checks for valid element types

// NOTE:  If the compiler sent you here, you're using an invalid iterator for an
// element.  What's listed here are NOT the only valid types.  Any iterator with
// a value type of a pointer to an element should work.
template <typename Elem_o1> struct ValidElement;
template <> struct ValidElement<MElement> { typedef void Type; };
template <> struct ValidElement<MLine> { typedef void Type; };
template <> struct ValidElement<MTriangle> { typedef void Type; };
template <> struct ValidElement<MQuadrangle> { typedef void Type; };
template <> struct ValidElement<MTetrahedron> { typedef void Type; };
template <> struct ValidElement<MHexahedron> { typedef void Type; };
template <> struct ValidElement<MPrism> { typedef void Type; };
template <> struct ValidElement<MPyramid> { typedef void Type; };


/*==============================================================================
 * Traits classes - that return information about a type
 *============================================================================*/

//--This traits class gives the first-order base type for a second-order element

template <typename Order2> struct ElemBaseOrder
{ typedef Order2 Order1; };
template <> struct ElemBaseOrder<MLine3>
{ typedef MLine Order1; };
template <> struct ElemBaseOrder<MTriangle6>
{ typedef MTriangle Order1; };
template <> struct ElemBaseOrder<MQuadrangle8>
{ typedef MQuadrangle Order1; };
template <> struct ElemBaseOrder<MQuadrangle9>
{ typedef MQuadrangle Order1; };
template <> struct ElemBaseOrder<MTetrahedron10>
{ typedef MTetrahedron Order1; };
template <> struct ElemBaseOrder<MHexahedron20>
{ typedef MHexahedron Order1; };
template <> struct ElemBaseOrder<MHexahedron27>
{ typedef MHexahedron Order1; };
template <> struct ElemBaseOrder<MPrism15>
{ typedef MPrism Order1; };
template <> struct ElemBaseOrder<MPrism18>
{ typedef MPrism Order1; };
template <> struct ElemBaseOrder<MPyramid13>
{ typedef MPyramid Order1; };
template <> struct ElemBaseOrder<MPyramid14>
{ typedef MPyramid Order1; };

//--This traits class describes describes the lower dimensional bounding
//--polytopes of a first-order element

template <typename Elem> struct ElemTr;
template <> struct ElemTr<MElement>
{ enum { numVertex = 0, numEdge = 0, numFace = 0 }; };
template <> struct ElemTr<MLine>
{ enum { numVertex = 2, numEdge = 0, numFace = 0 }; };
template <> struct ElemTr<MTriangle>
{ enum { numVertex = 3, numEdge = 3, numFace = 0 }; };
template <> struct ElemTr<MQuadrangle>
{ enum { numVertex = 4, numEdge = 4, numFace = 0 }; };
template <> struct ElemTr<MTetrahedron>
{ enum { numVertex = 4, numEdge = 6, numFace = 4 }; };
template <> struct ElemTr<MHexahedron>
{ enum { numVertex = 8, numEdge = 12, numFace = 6 }; };
template <> struct ElemTr<MPrism>
{ enum { numVertex = 6, numEdge = 9, numFace = 5 }; };
template <> struct ElemTr<MPyramid>
{ enum { numVertex = 5, numEdge = 8, numFace = 5 }; };

//--This traits class gives the number of element types in entity Ent

template <typename Ent> struct EntTr;
template <> struct EntTr<GEdge> { enum { numElemTypes = 1 }; };
template <> struct EntTr<GFace> { enum { numElemTypes = 2 }; };
template <> struct EntTr<GRegion> { enum { numElemTypes = 4 }; };

//--This traits class gives iterator types and begin and end iterators for
//--element type number N in entity Ent.

template <typename Ent, int N> struct EntElemTr;
template <> struct EntElemTr<GEdge, 1> {
  typedef MLine Elem;
  typedef std::vector<MLine*>::const_iterator ConstElementIterator;
  typedef std::vector<MLine*>::iterator ElementIterator;
  static ConstElementIterator begin(const GEdge *const edge)
  {
    return edge->lines.begin();
  }
  static ConstElementIterator end(const GEdge *const edge)
  {
    return edge->lines.end();
  }
};
template <> struct EntElemTr<GFace, 1> {
  typedef MQuadrangle Elem;
  typedef std::vector<MQuadrangle*>::const_iterator ConstElementIterator;
  typedef std::vector<MQuadrangle*>::iterator ElementIterator;
  static ConstElementIterator begin(const GFace *const face)
  {
    return face->quadrangles.begin();
  }
  static ConstElementIterator end(const GFace *const face)
  {
    return face->quadrangles.end();
  }
};
template <> struct EntElemTr<GFace, 2> {
  typedef MTriangle Elem;
  typedef std::vector<MTriangle*>::const_iterator ConstElementIterator;
  typedef std::vector<MTriangle*>::iterator ElementIterator;
  static ConstElementIterator begin(const GFace *const face)
  {
    return face->triangles.begin();
  }
  static ConstElementIterator end(const GFace *const face)
  {
    return face->triangles.end();
  }
};
template <> struct EntElemTr<GRegion, 1> {
  typedef MPyramid Elem;
  typedef std::vector<MPyramid*>::const_iterator ConstElementIterator;
  typedef std::vector<MPyramid*>::iterator ElementIterator;
  static ConstElementIterator begin(const GRegion *const region)
  {
    return region->pyramids.begin();
  }
  static ConstElementIterator end(const GRegion *const region)
  {
    return region->pyramids.end();
  }
};
template <> struct EntElemTr<GRegion, 2> {
  typedef MPrism Elem;
  typedef std::vector<MPrism*>::const_iterator ConstElementIterator;
  typedef std::vector<MPrism*>::iterator ElementIterator;
  static ConstElementIterator begin(const GRegion *const region)
  {
    return region->prisms.begin();
  }
  static ConstElementIterator end(const GRegion *const region)
  {
    return region->prisms.end();
  }
};
template <> struct EntElemTr<GRegion, 3> {
  typedef MHexahedron Elem;
  typedef std::vector<MHexahedron*>::const_iterator ConstElementIterator;
  typedef std::vector<MHexahedron*>::iterator ElementIterator;
  static ConstElementIterator begin(const GRegion *const region)
  {
    return region->hexahedra.begin();
  }
  static ConstElementIterator end(const GRegion *const region)
  {
    return region->hexahedra.end();
  }
};
template <> struct EntElemTr<GRegion, 4> {
  typedef MTetrahedron Elem;
  typedef std::vector<MTetrahedron*>::const_iterator ConstElementIterator;
  typedef std::vector<MTetrahedron*>::iterator ElementIterator;
  static ConstElementIterator begin(const GRegion *const region)
  {
    return region->tetrahedra.begin();
  }
  static ConstElementIterator end(const GRegion *const region)
  {
    return region->tetrahedra.end();
  }
};

//--This is a traits/policy class for the lower-dimension polytopes that bound
//--an element (i.e., vertex, edge, or face).  It returns the corresponding
//--range type and extracts from the element the function to get the polytope.
//--Note that MVertex is a pointer because it exists somewhere whereas MEdge and
//--MFace are constructed using MVertex's by getEdge() and getFace().

template <typename Polytope> struct PolytopeTr;
template <> struct PolytopeTr<MVertex*> {
  typedef VertNRange PolytopeNRange;
  typedef VertNRangeConstIterator PNRConstIterator;
  template <typename Elem>
  static MVertex *getPolytope(Elem *const element, const int nPolytope)
  {
    return element->getVertex(nPolytope);
  }
};
template <> struct PolytopeTr<MEdge> {
  typedef EdgeNRange PolytopeNRange;
  typedef EdgeNRangeConstIterator PNRConstIterator;
  template <typename Elem>
  static MEdge getPolytope(Elem *const element, const int nPolytope)
  {
    return element->getEdge(nPolytope);
  }
};
template <> struct PolytopeTr<MFace> {
  typedef FaceNRange PolytopeNRange;
  typedef FaceNRangeConstIterator PNRConstIterator;
  template <typename Elem>
  static MFace getPolytope(Elem *const element, const int nPolytope)
  {
    return element->getFace(nPolytope);
  }
};

}  // End of unnamed namespace


/*******************************************************************************
 *
 * class: PolytopeIterator
 *
 * Purpose
 * =======
 *
 *   Provides an iterator to iterate through the unique vertices, edges and,
 *   faces defined by the (hash_)maps.  An iterator to the (hash_)map has a
 *   value type of a (key, value) pair.  This iterator makes the container look
 *   like it only contains the bounding polytope.
 *
 * Constructors
 * ============
 *
 *   The class takes one template argument <Polytope> which should be either
 *   MVertex*, MEdge, or MFace.
 *
 *   PolytopeIterator()
 *                     -- default constructor
 *
 *   PolytopeIterator(const BaseIterator &baseIter_in)
 *                     -- the base iterator is the real iterator to the
 *                        (hash_)map
 *
 *   PolytopeIterator(const  PolytopeIterator &iter)
 *                     -- copy
 *
 * Destructor
 * ==========
 *
 *   ~PolytopeIterator -- synthesized
 *
 * Member Functions
 * ================
 *
 *   int num_neighbours()
 *                     -- returns number of elements sharing the polytope
 *
 * Operators
 * =========
 *
 *   Includes typical bidirectional iterator operators {=, ==, !=, *, ->, ++(),
 *   --(), ()++, ()--} with * and -> dereferencing to the polytope.
 *
 * Notes
 * =====
 *
 *   - Only constant iterators are supported.
 *   
 ******************************************************************************/

template<typename Polytope>
class PolytopeIterator  // Actually only a const_iterator
{

 public:

  // The base iterator iterates through the (hash_)maps defining the range of
  // element neighbours for a polytope
  typedef typename PolytopeTr<Polytope>::PNRConstIterator BaseIterator;
  typedef PolytopeIterator Self;

  // Standard traits
  typedef std::bidirectional_iterator_tag iterator_category;
  typedef Polytope value_type;
  typedef BaseIterator difference_type;
  typedef const Polytope* pointer;
  typedef const Polytope& reference;

//--Constructors

  PolytopeIterator() : baseIter() { }
  PolytopeIterator(const BaseIterator &baseIter_in) : baseIter(baseIter_in) { }
  PolytopeIterator(const PolytopeIterator &iter) : baseIter(iter.baseIter) { }
  PolytopeIterator& operator=(const PolytopeIterator& iter)
  {
    if(&iter != this) baseIter = iter.baseIter;
    return *this;
  }

//--Comparison

  bool operator==(const Self& iter) const { return baseIter == iter.baseIter; }
  bool operator!=(const Self& iter) const { return baseIter != iter.baseIter; }

//--Dereference and arrow operator

  reference operator*() const { return baseIter->first; }
  pointer operator->() const { return &baseIter->first; }

//--Increment

  // Prefix
  Self& operator++()
  {
    ++baseIter;
    return *this;
  }

  // Postfix
  Self operator++(int)
  {
    Self tmp = *this;
    ++*this;
    return tmp;
  }

//--Decrement

  // Prefix
  Self& operator--()
  {
    --baseIter;
    return *this;
  }

  // Postfix
  Self operator--(int)
  {
    Self tmp = *this;
    --*this;
    return tmp;
  }

//--Special

  int num_neighbours() { return baseIter->second.num; }

 private:
  NeighboursConstIterator begin_neighbours() { return baseIter->second.begin; }

//--Date members

  BaseIterator baseIter;

//--Friends

  friend class MNeighbour;

};


/*******************************************************************************
 *
 * class: MNeighbour
 *
 * Purpose
 * =======
 *
 *   Generates a database for quick lookup of elements sharing a
 *   MVertex*, MEdge, or MFace (referred to in general as polytopes.  I.e., a
 *   geometrical construct bounding the element with a lower dimension than the
 *   element).  The neighbour elements are stored in a list.  Maps or hash maps
 *   provide an index into the list for a given polytope.  In addition to the
 *   element neighbours, this class provides iterators to the unique vertices,
 *   edges, and faces in the database.
 *
 * Iterators
 * =========
 *
 *   Vertex_const_iterator
 *                     -- iterator to sequence of unique vertices
 *   Edge_const_iterator
 *                     -- iterator to sequence of unique edges
 *   Face_const_iterator
 *                     -- iterator to sequence of unique faces
 *
 * Constructors
 * ============
 *
 *   MNeighbour()      -- default constructor does nothing
 *
 * Destructor
 * ==========
 *
 *   ~MNeighbour()     -- synthesized
 *
 * Member Functions
 * ================
 *
 * Iterators
 * ---------
 *
 *   Vertex_const_iterator vertex_begin()
 *                     -- first unique vertex
 *
 *   Vertex_const_iterator vertex_end()
 *                     -- one-past-last unique vertex
 *
 *   Edeg_const_iterator edge_begin()
 *                     -- first unique edge
 *
 *   Edge_const_iterator edge_end()
 *                     -- one-past-last unique edge
 *
 *   Face_const_iterator face_begin()
 *                     -- first unique face
 *
 *   Face_const_iterator face_end()
 *                     -- one-past-last unique face
 *
 * Routines for adding elements
 * ----------------------------
 *
 *   The routines that generate a database of neighbours from container of
 *   entities (add_elements_in_entitie) require knowledge of the specific type
 *   of entity.  In cases where a container contains specific entities, the type
 *   need not be stated.  In cases where the container contains GEntity*, the
 *   user must state the actual entity type.  Extensive compile-time type
 *   checking is employed to make sure the routines are used correctly.
 *
 *   template <typename Ent, typename EntIter>
 *   void add_elements_in_entities(EntIter begin, EntIter end)
 *                     -- adds elements in entities to neighbours database.
 *                        Entity type <Ent> must be explicitly specified.  The
 *                        value type of the iterators must be a pointer to an
 *                        entity.  It is expected, but not required to be a
 *                        pointer to a GEntity.
 *     begin              (I) iterator/pointer to first entity pointer
 *     end                (I) iterator/pointer to one-past-last entity pointer
 *
 *   template <typename Ent, typename EntP>
 *   void add_elements_in_entities(EntP **pEnt, unsigned int n)
 *                     -- adds elements in entities to neighbours database.
 *                        Entity type <Ent> must be explicitly specified.  The
 *                        array element must be a pointer to an element.  It is
 *                        expected, but not required to be a pointer to a
 *                        GEntity.
 *     pEnt               (I) first entity in the array
 *     n                  (I) number of entities in the array
 *
 *   template <typename EntIter>
 *   void add_elements_in_entities(EntIter begin, EntIter end)
 *                     -- adds elements in entities to neighbours database.
 *                        The entity type must not be GEntity.  The value type
 *                        of the iterators must be a pointer to an entity.
 *     begin              (I) iterator/pointer to first entity pointer
 *     end                (I) iterator/pointer to one-past-last entity pointer
 *
 *   template <typename Ent>
 *   void add_elements_in_entities(Ent **pEnt, unsigned int n)
 *                     -- adds elements in entities to neighbours database.
 *                        The entity type must not be GEntity.  The array
 *                        element must be a pointer to an element.
 *     pEnt               (I) first entity in the array
 *     n                  (I) number of entities in the array
 *
 *   template <typename EntPtr>
 *   void add_elements_in_entity(EntPtr entity)
 *                     -- adds elements in a single entity to the neighbours
 *                        database.  The entity type must not be GEntity.  The
 *                        dereferenced quantity must be a pointer to an entity.
 *     entity             (I) pointer to an entity
 *
 *   The routines that generate a database of neighbours from containers of
 *   elements do not require the user to state the specific type of element.
 *   If the container constains a specific element pointer, compiler-time
 *   polymorphism is used.  If the container contains the base pointers
 *   MElement*, run-time switching based on element introspection is used.
 *
 *   template <typename ElemIter>
 *   void add_elements(ElemIter begin, ElemIter end)
 *                     -- adds elements from iterator sequence to the neighbours
 *                        database.
 *     begin              (I) iterator/pointer to first element pointer
 *     end                (I) iterator/pointer to one-past-last element pointer
 *
 *   template <typename Elem>
 *   void add_elements(Elem **pElem, const unsigned int n)
 *                     -- adds elements in an array to the neighbours database.
 *     pElem              (I) first element in the array
 *     n                  (I) number of elements in the array
 *
 *   void clear()      -- clears the neighbours database.  Use this before
 *                        constructing a new database of element neighbours.
 *                        Otherwise, new elements are added to the existing
 *                        database.
 *
 * Routines for querying the neighbours database
 * ---------------------------------------------
 *
 *   int max_vertex_neighbours()
 *                     -- returns max number of elements sharing a vertex.  This
 *                        is also the max number of elements sharing any
 *                        bounding polytope.
 *
 *   int max_edge_neighbours()
 *                     -- returns max number of elements sharing an edge.
 *
 *   int max_face_neighbours()
 *                     -- returns max number of elements sharing a face.
 *
 *   int vertex_neighbours(Vertex_const_iterator &itVert,
 *                          std::vector<MElement*> &vElem)
 *                     -- return all elements sharing a vertex
 *     itVert             (I) iterator to a unique vertex.  Avoids a find()
 *     vElem              (O) vector with elements loaded via push_back
 *     return             number of neighbour elements
 *
 *   int vertex_neighbours(Vertex_const_iterator &itVert, MElement **pElem)
 *                     -- return all elements sharing a vertex
 *     itVert             (I) iterator to a unique vertex.  Avoids a find()
 *     pElem              (O) array with elements loaded starting at pElem[0]
 *     return             number of neighbour elements
 *
 *   int vertex_neighbours(MVertex *const vertex, std::vector<MElement*> &vElem)
 *                     -- returns all elements sharing a vertex
 *     vertex             (I) pointer to vertex.  It must be found in (hash_)map
 *     vElem              (O) vector with elements loaded via push_back
 *     return             number of neighbour elements.  0 if vertex not found
 *
 *   int vertex_neighbours(MVertex *const vertex, MElement **pElem)
 *                     -- returns all elements sharing a vertex
 *     vertex             (I) pointer to vertex.  It must be found in (hash_)map
 *     pElem              (O) array with elements loaded starting at pElem[0]
 *     return             number of neighbour elements.  0 if vertex not found
 *
 *   int edge_neighbours(Edge_const_iterator &itEdge,
 *                        std::vector<MElement*> &vElem)
 *                     -- return all elements sharing a edge
 *     itEdge             (I) iterator to a unique edge.  Avoids a find()
 *     vElem              (O) vector with elements loaded via push_back
 *     return             number of neighbour elements
 *
 *   int edge_neighbours(Edge_const_iterator &itEdge, MElement **pElem)
 *                     -- return all elements sharing a edge
 *     itEdge             (I) iterator to a unique edge.  Avoids a find()
 *     pElem              (O) array with elements loaded starting at pElem[0]
 *     return             number of neighbour elements
 *
 *   int edge_neighbours(MEdge *const edge, std::vector<MElement*> &vElem)
 *                     -- returns all elements sharing a edge
 *     edge               (I) pointer to edge.  It must be found in (hash_)map
 *     vElem              (O) vector with elements loaded via push_back
 *     return             number of neighbour elements.  0 if edge not found
 *
 *   int edge_neighbours(MEdge *const edge, MElement **pElem)
 *                     -- returns all elements sharing a edge
 *     edge               (I) pointer to edge.  It must be found in (hash_)map
 *     pElem              (O) array with elements loaded starting at pElem[0]
 *     return             number of neighbour elements.  0 if edge not found
 *
 *   int face_neighbours(Face_const_iterator &itFace,
 *                        std::vector<MElement*> &vElem)
 *                     -- return all elements sharing a face
 *     itFace             (I) iterator to a unique face.  Avoids a find()
 *     vElem              (O) vector with elements loaded via push_back
 *     return             number of neighbour elements
 *
 *   int face_neighbours(Face_const_iterator &itFace, MElement **pElem)
 *                     -- return all elements sharing a face
 *     itFace             (I) iterator to a unique face.  Avoids a find()
 *     pElem              (O) array with elements loaded starting at pElem[0]
 *     return             number of neighbour elements
 *
 *   int face_neighbours(MFace *const face, std::vector<MElement*> &vElem)
 *                     -- returns all elements sharing a face
 *     face               (I) pointer to face.  It must be found in (hash_)map
 *     vElem              (O) vector with elements loaded via push_back
 *     return             number of neighbour elements.  0 if face not found
 *
 *   int face_neighbours(MFace *const face, MElement **pElem)
 *                     -- returns all elements sharing a face
 *     face               (I) pointer to face.  It must be found in (hash_)map
 *     pElem              (O) array with elements loaded starting at pElem[0]
 *     return             number of neighbour elements.  0 if face not found
 *
 *   int vertex_num_neighbours(MVertex *const vertex)
 *                     -- returns the number of elements sharing a vertex
 *
 *   int edge_num_neighbours(const MEdge& edge)
 *                     -- returns the number of elements sharing an edge
 *
 *   int face_num_neighbours(const MFace& face)
 *                     -- returns the number of elements sharing a face
 *
 *   template <typename Elem>
 *   int all_element_neighbours(Elem *const element,
 *                              std::vector<MElement*> &vElem,
 *                              const bool exclusive = true)
 *                     -- find all the elements connected to the given element
 *     element            (I) element to find neighbours to
 *     vElem              (O) vector with elements loaded via push_back
 *     exclusive          (I) T - exclude the given element in vElem
 *                            F - include the given element in vElem
 *     return             number of elements added to vElem
 *
 *   template <typename Elem>
 *   int all_element_neighbours(Elem *const element, MElement **pElem
 *                              const bool exclusive = true)
 *                     -- find all the elements connected to the given element
 *     element            (I) element to find neighbours to
 *     pElem              (O) array with elements loaded starting at pElem[0]
 *     exclusive          (I) T - exclude the given element in vElem
 *                            F - include the given element in vElem
 *     return             number of elements added to pElem
 *
 *   template <typename Elem>
 *   int all_element_edge_neighbours(Elem *const element,
 *                                   std::vector<MElement*> &vElem,
 *                                   const bool exclusive = true)
 *                     -- find all the elements connected to the edges of a
 *                        given element
 *     element            (I) element to find neighbours to
 *     vElem              (O) vector with elements loaded via push_back
 *     exclusive          (I) T - exclude the given element in vElem
 *                            F - include the given element in vElem
 *     return             number of elements added to vElem
 *
 *   template <typename Elem>
 *   int all_element_edge_neighbours(Elem *const element, MElement **pElem
 *                                   const bool exclusive = true)
 *                     -- find all the elements connected to the edges of a
 *                        given element
 *     element            (I) element to find neighbours to
 *     pElem              (O) array with elements loaded starting at pElem[0]
 *     exclusive          (I) T - exclude the given element in vElem
 *                            F - include the given element in vElem
 *     return             number of elements added to pElem
 *
 *   template <typename Elem>
 *   int all_element_face_neighbours(Elem *const element,
 *                                   std::vector<MElement*> &vElem,
 *                                   const bool exclusive = true)
 *                     -- find all the elements connected to the faces of a
 *                        given element
 *     element            (I) element to find neighbours to
 *     vElem              (O) vector with elements loaded via push_back
 *     exclusive          (I) T - exclude the given element in vElem
 *                            F - include the given element in vElem
 *     return             number of elements added to vElem
 *
 *   template <typename Elem>
 *   int all_element_face_neighbours(Elem *const element, MElement **pElem
 *                                   const bool exclusive = true)
 *                     -- find all the elements connected to the faces of a
 *                        given element
 *     element            (I) element to find neighbours to
 *     pElem              (O) array with elements loaded starting at pElem[0]
 *     exclusive          (I) T - exclude the given element in vElem
 *                            F - include the given element in vElem
 *     return             number of elements added to pElem
 *
 *   int element_vertex_neighbours(const MElement *const element,
 *                                 MVertex *const vertex,
 *                                 std::vector<MElement*> &vElem)
 *                     -- find all the elements connected to a vertex of a given
 *                        element.  This is the same as routine
 *                        vertex_neighbours except that the given element is
 *                        excluded from the result.
 *     element            (I) element to exclude
 *     vertex             (I) vertex to find element neighbours to
 *     vElem              (O) vector with elements loaded via push_back
 *     return             number of elements added to vElem
 *
 *   int element_vertex_neighbours(const MElement *const element,
 *                                 MVertex *const vertex, MElement **pElem)
 *                     -- find all the elements connected to a vertex of a given
 *                        element.  This is the same as routine
 *                        vertex_neighbours except that the given element is
 *                        excluded from the result.
 *     element            (I) element to exclude
 *     vertex             (I) vertex to find element neighbours to
 *     pElem              (O) array with elements loaded starting at pElem[0]
 *     return             number of elements added to pElem
 *
 *   int element_edge_neighbours(const MElement *const element,
 *                               const MEdge &edge,
 *                               std::vector<MElement*> &vElem)
 *                     -- find all the elements connected to an edge of a given
 *                        element.  This is the same as routine
 *                        edge_neighbours except that the given element is
 *                        excluded from the result.
 *     element            (I) element to exclude
 *     edge               (I) edge to find element neighbours to
 *     vElem              (O) vector with elements loaded via push_back
 *     return             number of elements added to vElem
 *
 *   int element_edge_neighbours(const MElement *const element,
 *                               const MEdge &edge, MElement **pElem)
 *                     -- find all the elements connected to an edge of a given
 *                        element.  This is the same as routine
 *                        edge_neighbours except that the given element is
 *                        excluded from the result.
 *     element            (I) element to exclude
 *     edge               (I) edge to find element neighbours to
 *     pElem              (O) array with elements loaded starting at pElem[0]
 *     return             number of elements added to pElem
 *
 *   MElement *element_face_neighbour(const MElement *const element,
 *                                    const MFace &face)
 *                     -- find the element connected to the face of a given
 *                        element.  Routine element_neighbour could also be
 *                        used.
 *     element            (I) element to find neighbour to
 *     face               (I) face to find element neighbour across
 *     return             the neighbour element or 0 if none found
 *
 *   MElement *element_neighbour(MElement *const element,
 *                               const int iPolytope)
 *                     -- find the neighbour element across the d-1 bounding
 *                        polytope.  E.g., for a triangle, find an element
 *                        across an edge.
 *     element            (I) element to find neighbour to
 *     iPolytope          (I) which polytope to find.  E.g., edge 1
 *     return             the neighbour element or 0 if none found
 *
 * Notes
 * =====
 *
 *   - Many of the query routines that have an element argument are specialized.
 *     If a specific element pointer is given, static (compile-time)
 *     polymorphism is used.  If a base element pointer is given, dynamic
 *     (run-time) polymorphism is used.  This is mostly experimental and may not
 *     have any tangible benefit.
 *
 * Example
 * =======
 *
 *------------------------------------------------------------------------------

  // Examples for adding elements from containers (the type of container doesn't
  // matter.

  MNeighbour meshNeighbour;

  std::list<GEntity*> faceEnt1;  // Assume known to be GFace type
  meshNeighbour.add_elements_in_entities<GFace>(faceEnt1.begin(),
                                                faceEnt1.end());

  std::vector<GFace*> faceEnt2;
  meshNeighbour.add_elements_in_entities(faceEnt2.begin(), faceEnt2.end());
  meshNeighbour.add_elements_in_entity(faceEnt2.begin());

  GEntity *faceEnt3[2];  // Assume known to be GFace type
  meshNeighbour.add_elements_in_entities<GFace>(faceEnt3, 2);

  GFace *faceEnt4[10];
  meshNeighbour.add_elements_in_entities(faceEnt4, 10);

  std::list<MElement*> elem1;
  // Run time introspection.  Elements can be mixed.
  meshNeighbour.add_elements(elem1.begin(), elem1.end());

  std::vector<MTriangle*> elem2;
  // Compile time introspection.
  meshNeighbour.add_elements(elem2.begin(), elem2.end());

  MElement *elem3[5];
  // Run time introspection.  Elements can be mixed.
  meshNeighbour.add_elements(elem3, 5);

  MQuadrangle *elem4[6];
  // Compile time introspection.
  meshNeighbour.add_elements(elem4, 6);

 *------------------------------------------------------------------------------
 *
 ******************************************************************************/

class MNeighbour
{


/*==============================================================================
 * Class scope types
 *============================================================================*/

 private:
  typedef std::set<MElement*, std::less<MElement*> > ElemSet;
  typedef ElemSet::const_iterator ElemSetConstIterator;


/*==============================================================================
 * Iterators
 *============================================================================*/

 public:

  // Iterators over polytopes
  typedef PolytopeIterator<MVertex*> Vertex_const_iterator;
  typedef PolytopeIterator<MEdge> Edge_const_iterator;
  typedef PolytopeIterator<MFace> Face_const_iterator;

  // Begin and end points for these iterators
  Vertex_const_iterator vertex_begin()
  {
    return Vertex_const_iterator(vertNRange.begin()); 
  }
  Vertex_const_iterator vertex_end()
  {
    return Vertex_const_iterator(vertNRange.end()); 
  }
  Edge_const_iterator edge_begin()
  {
    return Edge_const_iterator(edgeNRange.begin()); 
  }
  Edge_const_iterator edge_end()
  {
    return Edge_const_iterator(edgeNRange.end()); 
  }
  Face_const_iterator face_begin()
  {
    return Face_const_iterator(faceNRange.begin()); 
  }
  Face_const_iterator face_end()
  {
    return Face_const_iterator(faceNRange.end()); 
  }


/*==============================================================================
 * Template meta-programming classes
 *============================================================================*/

 private:

  template <typename Elem, typename Polytope, int NP>
  struct FindNeighbours;
  template <typename Ent, int N = EntTr<Ent>::numElemTypes>
  struct FindNeighboursInEntity;


/*==============================================================================
 * Public member functions and data
 *============================================================================*/

 public:

//--Default constructor.

  // The constructor cannot really do anything because the initialization
  // functions (find_neighbours_*) cannot perform template argument deduction.
  MNeighbour() : maxVertNeighbours(0), maxEdgeNeighbours(0),
    maxFaceNeighbours(0) { }

/*--------------------------------------------------------------------*
 * Elements added from entities.
 *--------------------------------------------------------------------*/

//--Compute database of neighbour elements.  The entity pointers may be of a
//--base or specific type and the call must state the specific type.

  template <typename Ent, typename EntIter>
  void add_elements_in_entities(EntIter begin, EntIter end) {

    // Check the Ent and EntIter types
    // NOTE:  If the compiler sent you here, you're using an invalid entity as a
    // template parameter and/or and invalid iterator.  See struct
    // ValidEntityIterator above for valid types
    typedef typename ValidSpecEntityIterator<Ent,
      typename EntIter::value_type>::Type Check;

    // Find the neighbours of each vertex, edge, and face
    for(EntIter itEnt = begin; itEnt != end; ++itEnt) {
      Ent *entity = static_cast<Ent*>(*itEnt);
      FindNeighboursInEntity<Ent>::eval(entity, vertNRange, edgeNRange,
                                        faceNRange, neighbours);
    }
    maxVertNeighbours = -1;
    maxEdgeNeighbours = -1;
    maxFaceNeighbours = -1;
  }

//--Same as the routine above except the arguments are pointers instead of
//--iterators.  Hence, value_type does not exist.

  template <typename Ent, typename EntP>
  void add_elements_in_entities(EntP **pEnt, unsigned int n) {

    // Check the Ent and EntP types
    // NOTE:  If the compiler sent you here, you're using an invalid entity as a
    // template parameter and/or invalid pointers. See struct
    // ValidEntityIterator above for valid types
    typedef typename ValidSpecEntityIterator<Ent, EntP*>::Type Check;

    // Find the neighbours of each vertex, edge, and face
    while(n--) {
      Ent *entity = static_cast<Ent*>(*pEnt++);
      FindNeighboursInEntity<Ent>::eval(entity, vertNRange, edgeNRange,
                                        faceNRange, neighbours);
    }
    maxVertNeighbours = -1;
    maxEdgeNeighbours = -1;
    maxFaceNeighbours = -1;
  }

//--Compute database of neighbour elements.  The entity pointers must be of a
//--specific type (not a base class).  The type of entity is determined from
//--Iterator::value_type and does not need to be stated.

  template <typename EntIter>
  void add_elements_in_entities(EntIter begin, EntIter end) {

    // Check the value type in EntIter (it must not be GEntity*)
    // NOTE:  If the compiler sent you here, you're using an invalid entity as a
    // template parameter and/or and invalid iterator for the constructor.  See
    // struct ValidEntityIterator above for valid types
    typedef typename ValidEntityIterator<typename EntIter::value_type>::
      Type Ent;

    // Find the neighbours of each vertex, edge, and face
    for(EntIter itEnt = begin; itEnt != end; ++itEnt) {
      FindNeighboursInEntity<Ent>::eval(*itEnt, vertNRange, edgeNRange,
                                        faceNRange, neighbours);
    }
    maxVertNeighbours = -1;
    maxEdgeNeighbours = -1;
    maxFaceNeighbours = -1;
  }

//--Same as the routine above except the arguments are pointers instead of
//--iterators.  Hence, value_type does not exist.

  template <typename Ent>
  void add_elements_in_entities(Ent **pEnt, unsigned int n) {

    // Check the type Ent (it must not be GEntity)
    // NOTE:  If the compiler sent you here, you're using an invalid entity as a
    // pointer See struct ValidEntityIterator above for valid types
    typedef typename ValidEntityIterator<Ent*>::Type Check;

    // Find the neighbours of each vertex, edge, and face
    while(n--) {
      FindNeighboursInEntity<Ent>::eval(*pEnt++, vertNRange, edgeNRange,
                                        faceNRange, neighbours);
    }
    maxVertNeighbours = -1;
    maxEdgeNeighbours = -1;
    maxFaceNeighbours = -1;
  }

//--Find neighbours from the elements attached to a pointer to a single entity.
//--The type of entity does not need to be stated.

  template <typename EntPtr>
  void add_elements_in_entity(EntPtr entity) {

    // Check the type of EntPtr (it must not be GEntity*)
    // NOTE:  If the compiler sent you here, you're using an invalid entity as a
    // pointer See struct ValidEntityIterator above for valid types
    typedef typename ValidEntityIterator<EntPtr>::Type Ent;

    // Find the neighbours of each vertex, edge, and face
    FindNeighboursInEntity<Ent>::eval(entity, vertNRange, edgeNRange,
                                      faceNRange, neighbours);
    maxVertNeighbours = -1;
    maxEdgeNeighbours = -1;
    maxFaceNeighbours = -1;
  }

/*--------------------------------------------------------------------*
 * Elements added directly
 *--------------------------------------------------------------------*/

//--Add elements from a container using iterators

  template <typename ElemIter>
  void add_elements(ElemIter begin, ElemIter end) {

    // Strip the pointer to the element type and convert it to first order
    typedef typename ElemBaseOrder<
      typename StripPointer<
        typename ElemIter::value_type
      >::Type
    >::Order1 Elem_1o;

    // Check for a valid type of element
    // NOTE:  If the compiler sent you here, you're using an invalid iterator.
    // The dereferenced object needs to be a pointer to an element.
    typedef typename ValidElement<Elem_1o>::Type Check;

    add_elements1<Elem_1o, ElemIter>(begin, end);
  }

//--Add elements from an array of pointers (value_type does not exist)

  template <typename Elem>
  void add_elements(Elem **pElem, const unsigned int n) {

    // Convert the element type to first order
    typedef typename ElemBaseOrder<Elem>::Order1 Elem_1o;

    // Check for a valid type of element
    // NOTE:  If the compiler sent you here, you're using an invalid pointer.
    // The dereferenced object needs to be a pointer to an element.
    typedef typename ValidElement<Elem_1o>::Type Check;

    add_elements1<Elem_1o, Elem**>(pElem, pElem+n);
  }

/*--------------------------------------------------------------------*
 * Reset the database
 *--------------------------------------------------------------------*/

  void clear() 
  {
    vertNRange.clear();
    edgeNRange.clear();
    faceNRange.clear();
    neighbours.clear();
    maxVertNeighbours = 0;
    maxEdgeNeighbours = 0;
    maxFaceNeighbours = 0;
  }

/*--------------------------------------------------------------------*
 * Query the database
 *--------------------------------------------------------------------*/

//--Get the max number of elements sharing a vertex, edge, or face

  int max_vertex_neighbours()
  {
     if ( maxVertNeighbours < 0 ) compute_max_vert_neighbours();
     return maxVertNeighbours;
  }
  int max_edge_neighbours()
  {
     if ( maxEdgeNeighbours < 0 ) compute_max_edge_neighbours();
     return maxEdgeNeighbours;
  }
  int max_face_neighbours()
  {
     if ( maxFaceNeighbours < 0 ) compute_max_face_neighbours();
     return maxFaceNeighbours;
  }

//--Return elements that share a vertex

  // From a vertex iterator
  int vertex_neighbours(Vertex_const_iterator &itVert,
                        std::vector<MElement*> &vElem) const
  {
    NeighboursConstIterator itElem = itVert.begin_neighbours();
    for(int n = itVert.num_neighbours(); n--;) vElem.push_back(*itElem++);
    return itVert.num_neighbours();
  }

  int vertex_neighbours(Vertex_const_iterator &itVert, MElement **pElem) const
  {
    NeighboursConstIterator itElem = itVert.begin_neighbours();
    for(int n = itVert.num_neighbours(); n--;) *pElem++ = *itElem++;
    return itVert.num_neighbours();
  }

  // From a vertex
  int vertex_neighbours(MVertex *const vertex,
                        std::vector<MElement*> &vElem) const
  {
    VertNRangeConstIterator itVert = vertNRange.find(vertex);
    if(itVert == vertNRange.end()) return 0;  // Vertex not found
    NeighboursConstIterator itElem = itVert->second.begin;
    for(int n = itVert->second.num; n--;) vElem.push_back(*itElem++);
    return itVert->second.num;
  }

  int vertex_neighbours(MVertex *const vertex, MElement **pElem) const
  {
    VertNRangeConstIterator itVert = vertNRange.find(vertex);
    if(itVert == vertNRange.end()) return 0;  // Vertex not found
    NeighboursConstIterator itElem = itVert->second.begin;
    for(int n = itVert->second.num; n--;) *pElem++ = *itElem++;
    return itVert->second.num;
  }

//--Return elements that share an edge

  // From an edge iterator
  int edge_neighbours(Edge_const_iterator &itEdge,
                      std::vector<MElement*> &vElem) const 
  {
    NeighboursConstIterator itElem = itEdge.begin_neighbours();
    for(int n = itEdge.num_neighbours(); n--;)
       vElem.push_back(*itElem++);
    return itEdge.num_neighbours();
  }

  int edge_neighbours(Edge_const_iterator &itEdge, MElement **pElem) const
  {
    NeighboursConstIterator itElem = itEdge.begin_neighbours();
    for(int n = itEdge.num_neighbours(); n--;)
       *pElem++ = *itElem++;
    return itEdge.num_neighbours();
  }

  // From an edge
  int edge_neighbours(const MEdge &edge, std::vector<MElement*> &vElem) const
  {
    EdgeNRangeConstIterator itEdge = edgeNRange.find(edge);
    if(itEdge == edgeNRange.end()) return 0;  // Edge not found
    NeighboursConstIterator itElem = itEdge->second.begin;
    for(int n = itEdge->second.num; n--;) vElem.push_back(*itElem++);
    return itEdge->second.num;
  }

  int edge_neighbours(const MEdge &edge, MElement **pElem) const
  {
    EdgeNRangeConstIterator itEdge = edgeNRange.find(edge);
    if(itEdge == edgeNRange.end()) return 0;  // Edge not found
    NeighboursConstIterator itElem = itEdge->second.begin;
    for(int n = itEdge->second.num; n--;) *pElem++ = *itElem++;
    return itEdge->second.num;
  }

//--Return elements that share a face

  // From a face iterator
  int face_neighbours(Face_const_iterator &itFace,
                      std::vector<MElement*> &vElem) const 
  {
    NeighboursConstIterator itElem = itFace.begin_neighbours();
    for(int n = itFace.num_neighbours(); n--;)
       vElem.push_back(*itElem++);
    return itFace.num_neighbours();
  }

  int face_neighbours(Face_const_iterator &itFace, MElement **pElem) const
  {
    NeighboursConstIterator itElem = itFace.begin_neighbours();
    for(int n = itFace.num_neighbours(); n--;)
       *pElem++ = *itElem++;
    return itFace.num_neighbours();
  }

  // From a face
  int face_neighbours(const MFace &face, std::vector<MElement*> &vElem) const
  {
    FaceNRangeConstIterator itFace = faceNRange.find(face);
    if(itFace == faceNRange.end()) return 0;  // Face not found
    NeighboursConstIterator itElem = itFace->second.begin;
    for(int n = itFace->second.num; n--;) vElem.push_back(*itElem++);
    return itFace->second.num;
  }

  int face_neighbours(const MFace &face, MElement **pElem) const
  {
    FaceNRangeConstIterator itFace = faceNRange.find(face);
    if(itFace == faceNRange.end()) return 0;  // Face not found
    NeighboursConstIterator itElem = itFace->second.begin;
    for(int n = itFace->second.num; n--;) *pElem++ = *itElem++;
    return itFace->second.num;
  }

//--Return the number of elements that share a vertex

  int vertex_num_neighbours(MVertex *const vertex) const
  {
    VertNRangeConstIterator itVert = vertNRange.find(vertex);
    if(itVert == vertNRange.end()) return 0;  // Vertex not found
    return itVert->second.num;
  }

//--Return the number of elements that share an edge

  int edge_num_neighbours(const MEdge& edge) const
  {
    EdgeNRangeConstIterator itEdge = edgeNRange.find(edge);
    if(itEdge == edgeNRange.end()) return 0;  // Edge not found
    return itEdge->second.num;
  }

//--Return the number of elements that share a face

  int face_num_neighbours(const MFace& face) const
  {
    FaceNRangeConstIterator itFace = faceNRange.find(face);
    if(itFace == faceNRange.end()) return 0;  // Face not found
    return itFace->second.num;
  }

//--Return all the elements connected to a given element (Note: these routines
//--have specializations - they are defined following the class)

  template <typename Elem>
  int all_element_neighbours(Elem *const element, std::vector<MElement*> &vElem,
                             const bool exclusive = true)
  {
    typedef typename ElemBaseOrder<Elem>::Order1 Elem_1o;
    element_neighbours1<Elem, MVertex*>(static_cast<Elem_1o*>(element),
                                        vertNRange, ElemTr<Elem_1o>::numVertex);
    if(exclusive) elemSet.erase(element);
    const ElemSetConstIterator itElemEnd = elemSet.end();
    for(ElemSetConstIterator itElem = elemSet.begin(); itElem != itElemEnd;
        ++itElem) vElem.push_back(*itElem);
    const int nElem = elemSet.size();
    elemSet.clear();
    return nElem;
  }

  template <typename Elem>
  int all_element_neighbours(Elem *const element, MElement **pElem,
                             const bool exclusive = true)
  {
    typedef typename ElemBaseOrder<Elem>::Order1 Elem_1o;
    element_neighbours1<Elem, MVertex*>(static_cast<Elem_1o*>(element),
                                        vertNRange, ElemTr<Elem_1o>::numVertex);
    if(exclusive) elemSet.erase(element);
    const ElemSetConstIterator itElemEnd = elemSet.end();
    for(ElemSetConstIterator itElem = elemSet.begin(); itElem != itElemEnd;
        ++itElem) *pElem++ = *itElem;
    const int nElem = elemSet.size();
    elemSet.clear();
    return nElem;
  }

//--Return all the elements connected to the edges of a given element (Note:
//--these routines have specializations - they are defined following the class)

  template <typename Elem>
  int all_element_edge_neighbours(Elem *const element,
                                  std::vector<MElement*> &vElem,
                                  const bool exclusive = true)
  {
    typedef typename ElemBaseOrder<Elem>::Order1 Elem_1o;
    element_neighbours1<Elem, MEdge>(static_cast<Elem_1o*>(element),
                                     edgeNRange, ElemTr<Elem_1o>::numEdge);
    if(exclusive) elemSet.erase(element);
    const ElemSetConstIterator itElemEnd = elemSet.end();
    for(ElemSetConstIterator itElem = elemSet.begin(); itElem != itElemEnd;
        ++itElem) vElem.push_back(*itElem);
    const int nElem = elemSet.size();
    elemSet.clear();
    return nElem;
  }

  template <typename Elem>
  int all_element_edge_neighbours(Elem *const element, MElement **pElem,
                                  const bool exclusive = true)
  {
    typedef typename ElemBaseOrder<Elem>::Order1 Elem_1o;
    element_neighbours1<Elem, MEdge>(static_cast<Elem_1o*>(element),
                                     edgeNRange, ElemTr<Elem_1o>::numEdge);
    if(exclusive) elemSet.erase(element);
    const ElemSetConstIterator itElemEnd = elemSet.end();
    for(ElemSetConstIterator itElem = elemSet.begin(); itElem != itElemEnd;
        ++itElem) *pElem++ = *itElem;
    const int nElem = elemSet.size();
    elemSet.clear();
    return nElem;
  }

//--Return all the elements connected to the faces of a given element (Note:
//--these routines have specializations - they are defined following the class)

  template <typename Elem>
  int all_element_face_neighbours(Elem *const element,
                                  std::vector<MElement*> &vElem,
                                  const bool exclusive = true)
  {
    typedef typename ElemBaseOrder<Elem>::Order1 Elem_1o;
    element_neighbours1<Elem, MFace>(static_cast<Elem_1o*>(element),
                                     faceNRange, ElemTr<Elem_1o>::numFace);
    if(exclusive) elemSet.erase(element);
    const ElemSetConstIterator itElemEnd = elemSet.end();
    for(ElemSetConstIterator itElem = elemSet.begin(); itElem != itElemEnd;
        ++itElem) vElem.push_back(*itElem);
    const int nElem = elemSet.size();
    elemSet.clear();
    return nElem;
  }

  template <typename Elem>
  int all_element_face_neighbours(Elem *const element, MElement **pElem,
                                  const bool exclusive = true)
  {
    typedef typename ElemBaseOrder<Elem>::Order1 Elem_1o;
    element_neighbours1<Elem, MFace>(static_cast<Elem_1o*>(element),
                                     faceNRange, ElemTr<Elem_1o>::numFace);
    if(exclusive) elemSet.erase(element);
    const ElemSetConstIterator itElemEnd = elemSet.end();
    for(ElemSetConstIterator itElem = elemSet.begin(); itElem != itElemEnd;
        ++itElem) *pElem++ = *itElem;
    const int nElem = elemSet.size();
    elemSet.clear();
    return nElem;
  }

//--Return elements connected to a specific vertex of a given element (Note:
//--these routines are the same as vertex_neighbours() except that the given
//--element is excluded)

  int element_vertex_neighbours(const MElement *const element,
                                MVertex *const vertex,
                                std::vector<MElement*> &vElem) const
  {
    VertNRangeConstIterator itVert = vertNRange.find(vertex);
    if(itVert == vertNRange.end()) return 0;  // Vertex not found
    NeighboursConstIterator itElem = itVert->second.begin;
    int n = itVert->second.num;
    while(*itElem != element) {
      vElem.push_back(*itElem++);
      --n;
    }
    ++itElem;
    for(--n; n--;) vElem.push_back(*itElem++);
    return itVert->second.num - 1;
  }

  int element_vertex_neighbours(const MElement *const element,
                                MVertex *const vertex, MElement **pElem) const
  {
    VertNRangeConstIterator itVert = vertNRange.find(vertex);
    if(itVert == vertNRange.end()) return 0;  // Vertex not found
    NeighboursConstIterator itElem = itVert->second.begin;
    int n = itVert->second.num;
    while(*itElem != element) {
      *pElem++ = *itElem++;
      --n;
    }
    ++itElem;
    for(--n; n--;) *pElem++ = *itElem++;
    return itVert->second.num - 1;
  }

//--Return elements connected to a specific edge of a given element (Note: these
//--routines are the same as edge_neighbours except that the given element is
//--excluded)

  int element_edge_neighbours(const MElement *const element, const MEdge &edge,
                              std::vector<MElement*> &vElem) const
  {
    EdgeNRangeConstIterator itEdge = edgeNRange.find(edge);
    if(itEdge == edgeNRange.end()) return 0;  // Edge not found
    NeighboursConstIterator itElem = itEdge->second.begin;
    int n = itEdge->second.num;
    while(*itElem != element) {
      vElem.push_back(*itElem++);
      --n;
    }
    ++itElem;
    for(--n; n--;) vElem.push_back(*itElem++);
    return itEdge->second.num - 1;
  }

  int element_edge_neighbours(const MElement *const element, const MEdge &edge,
                              MElement **pElem) const
  {
    EdgeNRangeConstIterator itEdge = edgeNRange.find(edge);
    if(itEdge == edgeNRange.end()) return 0;  // Edge not found
    NeighboursConstIterator itElem = itEdge->second.begin;
    int n = itEdge->second.num;
    while(*itElem != element) {
      *pElem++ = *itElem++;
      --n;
    }
    ++itElem;
    for(--n; n--;) *pElem++ = *itElem++;
    return itEdge->second.num - 1;
  }

//--Return the element connected to a specific face of a given element (Note:
//--this routine is similar to element_neighbour except less general)

  MElement *element_face_neighbour(const MElement *const element,
                                   const MFace &face) const
  {
    FaceNRangeConstIterator itFace = faceNRange.find(face);
    if(itFace == faceNRange.end()) return 0;  // Face not found
    NeighboursConstIterator itElem = itFace->second.begin;
    if(*itElem != element) return *itElem;
    if(itFace->second.num > 1) {
      ++itElem;
      if(*itElem != element) return *itElem;
    }
    return 0;
  }

//--Return the element neighbour across a d-1 polytope

  MElement *element_neighbour(MElement *const element,
                              const int iPolytope) const
  {
    int num;
    NeighboursConstIterator itElem;
    switch(element->getTypeForMSH()) {
    case MSH_LIN_2:
    case MSH_LIN_3:
      {
        MVertex *vertex = element->getVertex(iPolytope);
        VertNRangeConstIterator itVert = vertNRange.find(vertex);
        if(itVert == vertNRange.end()) return 0;
        num = itVert->second.num;
        itElem = itVert->second.begin;
      }
      break;
    case MSH_TRI_3:
    case MSH_TRI_6:
    case MSH_QUA_4:
    case MSH_QUA_8:
    case MSH_QUA_9:
      {
        MEdge edge = element->getEdge(iPolytope);
        EdgeNRangeConstIterator itEdge = edgeNRange.find(edge);
        if(itEdge == edgeNRange.end()) return 0;
        num = itEdge->second.num;
        itElem = itEdge->second.begin;
      }
      break;
    case MSH_TET_4:
    case MSH_TET_10:
    case MSH_HEX_8:
    case MSH_HEX_20:
    case MSH_HEX_27:
    case MSH_PRI_6:
    case MSH_PRI_15:
    case MSH_PRI_18:
    case MSH_PYR_5:
    case MSH_PYR_13:
    case MSH_PYR_14: {
        MFace face = element->getFace(iPolytope);
        FaceNRangeConstIterator itFace = faceNRange.find(face);
        if(itFace == faceNRange.end()) return 0;
        num = itFace->second.num;
        itElem = itFace->second.begin;
      }
      break;
    }
    if(*itElem != element) return *itElem;
    if(num > 1) {
      ++itElem;
      if(*itElem != element) return  *itElem;
    }
    return 0;
  }


/*==============================================================================
 * Private member functions and data
 *============================================================================*/

private:

//--Data members

  VertNRange vertNRange;                // Map of Vert. to indexes in neighbours
  EdgeNRange edgeNRange;                // Map of edge to indexes in neighbours
  FaceNRange faceNRange;                // Map of face to indexes in neighbours
  Neighbours neighbours;                // List of element neighbours
  ElemSet elemSet;                      // Buffer for finding unique elements
  int maxVertNeighbours;
  int maxEdgeNeighbours;
  int maxFaceNeighbours;

//--Working routine to determine the neighbours from elements (Note: Ideally
//--this class would use a specialization for MElement but partial
//--specialization is not currently permitted for member functions)

  template <typename Elem, typename ElemIter>
  void add_elements1(ElemIter begin, ElemIter end)
  {
    // Test if the type of element is known
    if(ElemTr<Elem>::numVertex) {  // 0 only for MElement
      // Find the neighbours of each vertex, edge, and face
      for(ElemIter itElem = begin; itElem != end; ++itElem)
        find_polytope_neighbours<Elem>(*itElem);
    }
    else {
      // We only have an iterator to an MElement* and have to check the type in
      // run-time.
      for(ElemIter itElem = begin; itElem != end; ++itElem) {
        switch((*itElem)->getTypeForMSH()) {
        case MSH_LIN_2:
        case MSH_LIN_3:
          find_polytope_neighbours<MLine>(*itElem);
          break;
        case MSH_TRI_3:
        case MSH_TRI_6:
          find_polytope_neighbours<MTriangle>(*itElem);
          break;
        case MSH_QUA_4:
        case MSH_QUA_8:
        case MSH_QUA_9:
          find_polytope_neighbours<MQuadrangle>(*itElem);
          break;
        case MSH_TET_4:
        case MSH_TET_10:
          find_polytope_neighbours<MTetrahedron>(*itElem);
          break;
        case MSH_HEX_8:
        case MSH_HEX_20:
        case MSH_HEX_27:
          find_polytope_neighbours<MHexahedron>(*itElem);
          break;
        case MSH_PRI_6:
        case MSH_PRI_15:
        case MSH_PRI_18:
          find_polytope_neighbours<MPrism>(*itElem);
          break;
        case MSH_PYR_5:
        case MSH_PYR_13:
        case MSH_PYR_14:
          find_polytope_neighbours<MPyramid>(*itElem);
          break;
        }
      }
    }
    maxVertNeighbours = -1;
    maxEdgeNeighbours = -1;
    maxFaceNeighbours = -1;
  }

//--Find the neighbours sharing each polytope

  template <typename Elem>
  void find_polytope_neighbours(MElement *element)
  {
    // Find neighbours for vertices
    FindNeighbours<Elem, MVertex*, ElemTr<Elem>::numVertex>::
      eval(static_cast<Elem*>(element), vertNRange, neighbours);
    // Find neighbours for edges
    FindNeighbours<Elem, MEdge, ElemTr<Elem>::numEdge>::
      eval(static_cast<Elem*>(element), edgeNRange, neighbours);
    // Find neighbours for faces
    FindNeighbours<Elem, MFace, ElemTr<Elem>::numFace>::
      eval(static_cast<Elem*>(element), faceNRange, neighbours);
  }

//--Compute max neighbours

  void compute_max_vert_neighbours()
  {
    maxVertNeighbours = 0;
    for(VertNRangeConstIterator itVert = vertNRange.begin();
        itVert != vertNRange.end(); ++itVert)
      maxVertNeighbours = std::max(maxVertNeighbours, itVert->second.num);
  }
  void compute_max_edge_neighbours()
  {
    maxEdgeNeighbours = 0;
    for(EdgeNRangeConstIterator itEdge = edgeNRange.begin();
        itEdge != edgeNRange.end(); ++itEdge)
      maxEdgeNeighbours = std::max(maxEdgeNeighbours, itEdge->second.num);
  }
  void compute_max_face_neighbours()
  {
    maxFaceNeighbours = 0;
    for(FaceNRangeConstIterator itFace = faceNRange.begin();
        itFace != faceNRange.end(); ++itFace)
      maxFaceNeighbours = std::max(maxFaceNeighbours, itFace->second.num);
  }

//--Work routine for finding all the element neighbours

  template <typename Elem, typename Polytope>
  void element_neighbours1(Elem *const element,
                           typename PolytopeTr<Polytope>::PolytopeNRange
                           &polytopeNRange, const int nVPE)
  {
    for(int iVPE = 0; iVPE != nVPE; ++iVPE) {
      Polytope polytope = PolytopeTr<Polytope>::getPolytope(element, iVPE);
      typename PolytopeTr<Polytope>::PNRConstIterator itPoly =
        polytopeNRange.find(polytope);
      if(itPoly != polytopeNRange.end()) {
        NeighboursConstIterator itElem = itPoly->second.begin;
        for(int n = itPoly->second.num; n--;)
          elemSet.insert(*itElem++);
      }
    }
  }

};


/*==============================================================================
 * Template meta-programming classes
 *============================================================================*/

/*--------------------------------------------------------------------
 * This is the main working routine for finding the elements sharing
 * a lower-dimension polytope (i.e, the structures bounding the
 * element: vertex, edge, or face).  It is templated for any type of
 * polytope and uses template meta-programming to unroll the loop over
 * the number of that type of polytope in the element.
 *--------------------------------------------------------------------*/

//--Entry point

template <typename Elem,                // Elem is the type of element
          typename Polytope,            // Polytope is a lower dimensional
                                        // bounding object (MVertex*, MEdge, or
                                        // MFace) of the element.  We want to
                                        // find the elements sharing a given
                                        // Polytope.
          int NP>                       // NP is an index through the number
                                        // of Polytope in the element (e.g.,
                                        // number of vertices)
struct MNeighbour::FindNeighbours
{
  typedef typename PolytopeTr<Polytope>::PolytopeNRange PolytopeNRange;
  static void eval(Elem *element, PolytopeNRange &polytopeNRange,
                   Neighbours &neighbours)
  {
    Polytope polytope = PolytopeTr<Polytope>::template
      getPolytope<Elem>(element, NP-1);
    Range_t &range = polytopeNRange[polytope];
    if(range.num == 0) range.begin = neighbours.end();
    range.begin = neighbours.insert(range.begin, element);
    ++range.num;
    FindNeighbours<Elem, Polytope, NP-1>::eval(element, polytopeNRange,
                                               neighbours);
  }
};

//--Terminate loop when NP == 1

template <typename Elem, typename Polytope>
struct MNeighbour::FindNeighbours<Elem, Polytope, 1>
{
  typedef typename PolytopeTr<Polytope>::PolytopeNRange PolytopeNRange;
  static void eval(Elem *element, PolytopeNRange &polytopeNRange,
                   Neighbours &neighbours)
  {
    Polytope polytope = PolytopeTr<Polytope>::template
      getPolytope<Elem>(element, 0);
    Range_t &range = polytopeNRange[polytope];
    if(range.num == 0) range.begin = neighbours.end();
    range.begin = neighbours.insert(range.begin, element);
    ++range.num;
  }
};

//--Nothing to do if the dimension of this polytope is equal to or greater than
//--that of the element (e.g., no faces (2D) in a 2D element).  This is
//--indicated by NP = 0.

template <typename Elem, typename Polytope>
struct MNeighbour::FindNeighbours<Elem, Polytope, 0>
{
  typedef typename PolytopeTr<Polytope>::PolytopeNRange PolytopeNRange;
  static void eval(Elem *element, PolytopeNRange &polytopeNRange,
                   Neighbours &neighbours) { }
};

/*--------------------------------------------------------------------*
 * This class uses traits to determine the element types in an entity
 * and iterate over them.  A template meta-programming loop is used to
 * iterate over the types of elements.
 *--------------------------------------------------------------------*/

//--Entry point

template <typename Ent, int N>
struct MNeighbour::FindNeighboursInEntity {
  typedef typename EntElemTr<Ent, N>::Elem Elem;
  static void eval(const Ent *const entity, VertNRange &vertNRange,
                   EdgeNRange &edgeNRange, FaceNRange &faceNRange,
                   Neighbours &neighbours)
  {
    for(typename EntElemTr<Ent, N>::ConstElementIterator itElem =
          EntElemTr<Ent, N>::begin(entity);
        itElem != EntElemTr<Ent, N>::end(entity); ++itElem) {
      // Find neighbours for vertices
      FindNeighbours<Elem, MVertex*, ElemTr<Elem>::numVertex>::
        eval(*itElem, vertNRange, neighbours);
      // Find neighbours for edges
      FindNeighbours<Elem, MEdge, ElemTr<Elem>::numEdge>::
        eval(*itElem, edgeNRange, neighbours);
      // Find neighbours for faces
      FindNeighbours<Elem, MFace, ElemTr<Elem>::numFace>::
        eval(*itElem, faceNRange, neighbours);
    }
    FindNeighboursInEntity<Ent, N-1>::eval(entity, vertNRange, edgeNRange,
                                           faceNRange, neighbours);
  }
};

//--Terminate loop when N = 1

template <typename Ent>
struct MNeighbour::FindNeighboursInEntity<Ent, 1> {
  typedef typename EntElemTr<Ent, 1>::Elem Elem;
  static void eval(const Ent *const entity, VertNRange &vertNRange,
                   EdgeNRange &edgeNRange, FaceNRange &faceNRange,
                   Neighbours &neighbours)
  {
    for(typename EntElemTr<Ent, 1>::ConstElementIterator itElem =
          EntElemTr<Ent, 1>::begin(entity);
        itElem != EntElemTr<Ent, 1>::end(entity); ++itElem) {
      // Find neighbours for vertices
      FindNeighbours<Elem, MVertex*, ElemTr<Elem>::numVertex>::
        eval(*itElem, vertNRange, neighbours);
      // Find neighbours for edges
      FindNeighbours<Elem, MEdge, ElemTr<Elem>::numEdge>::
        eval(*itElem, edgeNRange, neighbours);
      // Find neighbours for faces
      FindNeighbours<Elem, MFace, ElemTr<Elem>::numFace>::
        eval(*itElem, faceNRange, neighbours);
    }
  }
};


/*==============================================================================
 * Specializations for base elements - dynamic polymorphism
 *============================================================================*/

//--Return all the elements connected to a given element

template <>
inline int MNeighbour::all_element_neighbours<MElement>
(MElement *const element, std::vector<MElement*> &vElem, const bool exclusive)
{
  element_neighbours1<MElement, MVertex*>(element, vertNRange,
                                          element->getNumPrimaryVertices());
  if(exclusive) elemSet.erase(element);
  const ElemSetConstIterator itElemEnd = elemSet.end();
  for(ElemSetConstIterator itElem = elemSet.begin(); itElem != itElemEnd;
      ++itElem) vElem.push_back(*itElem);
  const int nElem = elemSet.size();
  elemSet.clear();
  return nElem;
}

template <>
inline int MNeighbour::all_element_neighbours<MElement>
(MElement *const element, MElement **pElem, const bool exclusive)
{
  element_neighbours1<MElement, MVertex*>(element, vertNRange,
                                          element->getNumPrimaryVertices());
  if(exclusive) elemSet.erase(element);
  const ElemSetConstIterator itElemEnd = elemSet.end();
  for(ElemSetConstIterator itElem = elemSet.begin(); itElem != itElemEnd;
      ++itElem) *pElem++ = *itElem;
  const int nElem = elemSet.size();
  elemSet.clear();
  return nElem;
}

//--Return all the elements connected to the edges of a given element

template <>
inline int MNeighbour::all_element_edge_neighbours<MElement>
(MElement *const element, std::vector<MElement*> &vElem, const bool exclusive)
{
  element_neighbours1<MElement, MEdge>(element, edgeNRange,
                                       element->getNumEdges());
  if(exclusive) elemSet.erase(element);
  const ElemSetConstIterator itElemEnd = elemSet.end();
  for(ElemSetConstIterator itElem = elemSet.begin(); itElem != itElemEnd;
      ++itElem) vElem.push_back(*itElem);
  const int nElem = elemSet.size();
  elemSet.clear();
  return nElem;
}

template <>
inline int MNeighbour::all_element_edge_neighbours<MElement>
(MElement *const element, MElement **pElem, const bool exclusive)
{
  element_neighbours1<MElement, MEdge>(element, edgeNRange,
                                       element->getNumEdges());
  if(exclusive) elemSet.erase(element);
  const ElemSetConstIterator itElemEnd = elemSet.end();
  for(ElemSetConstIterator itElem = elemSet.begin(); itElem != itElemEnd;
      ++itElem) *pElem++ = *itElem;
  const int nElem = elemSet.size();
  elemSet.clear();
  return nElem;
}

//--Return all the elements connected to the faces of a given element

template <>
inline int MNeighbour::all_element_face_neighbours<MElement>
(MElement *const element, std::vector<MElement*> &vElem, const bool exclusive)
{
  element_neighbours1<MElement, MFace>(element, faceNRange,
                                       element->getNumFaces());
  if(exclusive) elemSet.erase(element);
  const ElemSetConstIterator itElemEnd = elemSet.end();
  for(ElemSetConstIterator itElem = elemSet.begin(); itElem != itElemEnd;
      ++itElem) vElem.push_back(*itElem);
  const int nElem = elemSet.size();
  elemSet.clear();
  return nElem;
}

template <>
inline int MNeighbour::all_element_face_neighbours<MElement>
(MElement *const element, MElement **pElem, const bool exclusive)
{
  element_neighbours1<MElement, MFace>(element, faceNRange,
                                       element->getNumFaces());
  if(exclusive) elemSet.erase(element);
  const ElemSetConstIterator itElemEnd = elemSet.end();
  for(ElemSetConstIterator itElem = elemSet.begin(); itElem != itElemEnd;
      ++itElem) *pElem++ = *itElem;
  const int nElem = elemSet.size();
  elemSet.clear();
  return nElem;
}

#endif
