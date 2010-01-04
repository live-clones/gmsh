// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _MESH_PARTITION_OBJECTS_H_
#define _MESH_PARTITION_OBJECTS_H_

#include <map>
#include <vector>
#include "MElement.h"
#include "GmshMessage.h"


/*******************************************************************************
 *
 * Class GrVertex
 *
 * Purpose
 * =======
 *
 *   Provides a graph vertex and edges (connected vertices)
 *
 ******************************************************************************/

class GrVertex
{
  int grEdge[6];
 public:
  const int index;                      // This is the creation index, *not* the
                                        // index in 'adjncy'
  int dualWeight;
 private:
  unsigned short size;
  unsigned short sizeC;                 // Complete size (all possible 'grEdge')
 public:
  GrVertex(const int _index, const unsigned short _size)
    : index(_index), size(0), sizeC(_size)
  { }
  void add(const int v) { grEdge[size++] = v; }
  unsigned write(std::vector<int> &vec) const
  {
    switch(size) {
    case 6:
      vec.push_back(grEdge[5]);
    case 5:
      vec.push_back(grEdge[4]);
    case 4:
      vec.push_back(grEdge[3]);
    case 3:
      vec.push_back(grEdge[2]);
    case 2:
      vec.push_back(grEdge[1]);
    case 1:
      vec.push_back(grEdge[0]);
    }
    return size;
  }
  bool complete() const { return size == sizeC; }
};

typedef std::map<MElement*, GrVertex> GrVertexMap;


/*******************************************************************************
 *
 * Class Graph
 *
 * Purpose
 * =======
 *
 *   Graph of the mesh for partitioning purposes
 *
 * Notes
 * =====
 *
 *   - A "graph vertex" is a mesh element.
 *   - A "graph edge" is a face between two elements.
 *
 ******************************************************************************/

class Graph
{
 public:
  std::vector<int> xadj;                // Indices into 'adjncy' for each graph
                                        // vertex
  std::vector<int> adjncy;              // Connectivity between graph vertex
                                        // xadj[i] and its neighbour graph
                                        // vertices.
  std::vector<int> vwgts;               // Weights assigned for each 
                                        // vertex
  std::vector<int> section;             // For separate partitioning of
                                        // different parts of the mesh
  std::vector<int> partition;           // The partitions output from the
                                        // partitioner
  std::vector<MElement*> element;       // The element corresponding to each
                                        // graph vertex in 'xadj'
 private:
  unsigned cIndex;                      // An index for created graph vertices
                                        // (used externally)
  unsigned numGrVert;                   // Number of graph vertices currently
                                        // stored.  This is incremented as graph
                                        // vertices are written to xadj;
  unsigned totalGrVert;                 // The total number of graph vertices
                                        // over all sections
  int *c2w;                             // This array is used to translate the
                                        // creation index of a graph vertex into
                                        // the write index.  The write index is
                                        // the location a vertex is written to
                                        // 'xadj'.  'adjcny' originally contains
                                        // creations indices and will need to be
                                        // translated.
  
 public:
  Graph()
    : cIndex(0), numGrVert(0), totalGrVert(0)
  { }
  Graph(const unsigned _totalGrVert, const unsigned totalGrEdge)
    : cIndex(0), numGrVert(0)
  {
    allocate(_totalGrVert, totalGrEdge);
  }
  // Get number of vertices
  int getNumVertex() const { return numGrVert; }
  // Get total number of vertices.  This should be used if the graph is not yet
  // built.
  int getTotalNumVertex() const { return totalGrVert; }
  // Reserve/resize memory for the graph
  void allocate(const unsigned _totalGrVert, const unsigned totalGrEdge)
  {
    totalGrVert = _totalGrVert;
    xadj.resize(_totalGrVert + 1);
    adjncy.reserve(2*totalGrEdge);
    vwgts.resize(_totalGrVert);
    partition.resize(_totalGrVert);
    element.resize(_totalGrVert);
    c2w = new int[_totalGrVert];
  }
  // Adds a graph vertex
  void add(const GrVertexMap::const_iterator &grVertMapIt)
  {
    const int i = numGrVert++;
    xadj[i] = adjncy.size();
    vwgts[i] = 1;
    grVertMapIt->second.write(adjncy);
    element[i] = grVertMapIt->first;
    // Translated vertex numbers start from 1
    c2w[grVertMapIt->second.index] = i + 1;
  }
  void fillWeights(std::vector<int> wgts)
  {
    int num = 0;
    for(std::vector<int>::iterator it = wgts.begin(); it != wgts.end(); it++){
      vwgts[num]= 1; //*it;
       num++;
    }
  }

  void markSection() { section.push_back(numGrVert); }
  // Returns the next index for a graph vertex
  int getNextIndex() { return cIndex++; }
  // Returns a write index for a given creation index
  int convertC2W(const int c) const { return c2w[c]; }
  // Close the adjacency arrays (also deletes c2w)
  void close() 
  {
    if(numGrVert != totalGrVert) {
      Msg::Warning("Internal error - Graph vertices are missing");
    }
    xadj[numGrVert] = adjncy.size();
    vwgts[numGrVert-1]=(int)(1.0);
    const int nAdj = adjncy.size();
    for(int i = 0; i != nAdj; ++i) adjncy[i] = c2w[adjncy[i]];
    delete[] c2w;
  }
  // If partition is stored as short, repopulate as int.  1 is also added since
  // Chaco numbers sections from 1.
  void short2int()
  {
    short *ps = reinterpret_cast<short*>(&partition[0]) + numGrVert;
    for(int i = numGrVert; i--;) partition[i] = *--ps + 1;
  }
};


/*******************************************************************************
 *
 * Struct BoElemGr
 *
 * Purpose
 * =======
 *
 *   Provides data for a vector of boundary elements (dimension DIM-1) and
 *   the corresponding graph vertex from which they should obtain a partition
 *   index from.  In other words this vector relates boundary elements to the
 *   interior elements.
 *
 ******************************************************************************/

struct BoElemGr
{
  MElement *elem;                       // The boundary element
  int grVert;                           // Vertex in the graph assigned to the
                                        // neighbour interior element
  BoElemGr(MElement *const _elem, const int _grVert)
    :
    elem(_elem), grVert(_grVert)
  { }
};

#endif
