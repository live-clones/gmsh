// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _MESH_PARTITION_OBJECTS_H_
#define _MESH_PARTITION_OBJECTS_H_

#include <map>
#include <vector>
#include "MElement.h"
#include "GmshMessage.h"
#include "Context.h"
#include "fullMatrix.h"


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
  std::vector<int> adjwgts;             // Weights assigned for each 
                                        // edge
  std::vector<int> section;             // For separate partitioning of
                                        // different parts of the mesh
  std::vector<int> partition;           // The partitions output from the
                                        // partitioner
  std::vector<MElement*> element;       // The element corresponding to each
                                        // graph vertex in 'xadj'
  fullMatrix<int> *loads;                // Matrix of loads on each partition
                                        
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
    adjwgts.reserve(2*totalGrEdge);
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
  void computeLoads(int numParts, int numCon){
    loads=new fullMatrix<int> (numParts,numCon);
    for(int i=0; i<numParts;i++){
      for(int j=0; j<partition.size(); j++){
        if(partition[j]==i){
          for(int k=0; k<numCon;k++){
            (*loads)(i, k)+=vwgts[j*numCon+k];
          }
        }
      }
    }
  }
  void checkLoads(int numParts,  int numCon){
    printf("******************************************************* \n");
    for(int i=0; i<numParts;i++){
      printf("------- PARTITION %d: [", i+1);
      for(int j=0; j<numCon; j++){
        printf(" %d", (*loads)(i, j));
      }
      printf("] -------\n");
    }
    printf("******************************************************* \n");
  }
  void fillWeights(std::vector<int> wgts)
  {
    int num = 0;
    for(std::vector<int>::iterator it = wgts.begin(); it != wgts.end(); it++){
      vwgts[num]= 1; //*it;
       num++;
    }
  }
  // Add multiple weights on vertices of the graph given in a map between original element Numbers and their corresponding vector of weights 
  void fillWithMultipleWeights(int ncon, std::map<int, std::vector<int> > weightMap)
  {
    std::vector<MElement*>::iterator eIt;
    vwgts.resize(element.size()*ncon);
    adjwgts.resize(adjncy.size());
    int localElNum=0;
    for(eIt=element.begin();eIt !=element.end();eIt++){
      for(int i=0; i<ncon; i++){
        vwgts[localElNum*ncon+i]=weightMap[(*eIt)->getNum()][i];
      }
      for(int j=xadj[localElNum];j<xadj[localElNum+1];j++){
        adjwgts[j]+=weightMap[(*eIt)->getNum()][0];
      }
      localElNum+=1;
    }
  }

  // Add weights per element, as defined in options 
  void fillDefaultWeights() 
  {
    std::vector<MElement*>::iterator eIt = element.begin();
    vwgts.resize(element.size());
    std::vector<int>::iterator wIt = vwgts.begin();
    for ( ; eIt != element.end() ; eIt++ , wIt++) {
      
      switch ((*eIt)->getType()) {
      case TYPE_TRI:
        *wIt = CTX::instance()->partitionOptions.triWeight;
        break;
      case TYPE_QUA:
        *wIt = CTX::instance()->partitionOptions.quaWeight;
        break;
      case TYPE_TET:
        *wIt = CTX::instance()->partitionOptions.tetWeight;
        break;
      case TYPE_PYR:
        *wIt = CTX::instance()->partitionOptions.pyrWeight;
        break;
      case TYPE_PRI:
        *wIt = CTX::instance()->partitionOptions.priWeight;
        break;
      case TYPE_HEX:
        *wIt = CTX::instance()->partitionOptions.hexWeight;
        break;
      default:
        *wIt = 1;
        break;
      }
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
