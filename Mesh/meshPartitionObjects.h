// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _MESH_PARTITION_OBJECTS_DEV_H_
#define _MESH_PARTITION_OBJECTS_DEV_H_

#include <map>
#include <vector>
#include "MElement.h"
#include "GmshMessage.h"
#include "Context.h"
#include "fullMatrix.h"


/*******************************************************************************
 *
 * Class Graph
 *
 * Purpose
 * =======
 *
 *   Graph of the mesh for partitioning purposes
 *
 *
 ******************************************************************************/

class Graph
{
 public:
  int ne;                                    /*The number of elements*/
  
  int nn;                                    /*The number of nodes*/
  
  int dim;                                   /*The dimension of the mesh*/
  
  int *eind;                                 /*The list of nodes belonging to the ith element of the
                                              mesh are stored in consecutive locations of eind 
                                              starting at position eptr[i] up to (but not including) 
                                              position eptr[i+1]. The size of the eind array is of
                                              size equal to the sum of the number of nodes in all the 
                                              elements of the mesh.*/
  
  int *eptr;                                 /*The size of the eptr array is n + 1, where n is 
                                              the number of elements in the mesh.*/
  
  int *adjncy;                               /*The structure that constain the element
                                              graph (dual graph)*/
  
  int *xadj;                                 /*The structure that constain the element 
                                              graph (dual graph)*/
  
  std::vector<MElement*> element;            /*The element corresponding to each graph element
                                              in eptr*/
  
  int *vwgt;                                 /*The width associated to each elements of eptr*/
  
  int *partition;                            /*The partitions output from the partitioner*/
  
 private:

 public:
  Graph() : ne(0), nn(0), dim(0), eind(NULL), eptr(NULL), adjncy(NULL), xadj(NULL), element(), vwgt(NULL), partition(NULL)
  { }
  
  void fillDefaultWeights()
  {
    vwgt = new int[ne];
    for(unsigned int i = 0; i < ne; i++)
    {
      switch (element[i]->getType())
      {
        case TYPE_TRI:
          vwgt[i] = CTX::instance()->partitionOptions.triWeight;
          break;
        case TYPE_QUA:
          vwgt[i] = CTX::instance()->partitionOptions.quaWeight;
          break;
        case TYPE_TET:
          vwgt[i] = CTX::instance()->partitionOptions.tetWeight;
          break;
        case TYPE_PYR:
          vwgt[i] = CTX::instance()->partitionOptions.pyrWeight;
          break;
        case TYPE_PRI:
          vwgt[i] = CTX::instance()->partitionOptions.priWeight;
          break;
        case TYPE_HEX:
          vwgt[i] = CTX::instance()->partitionOptions.hexWeight;
          break;
        default:
          vwgt[i] = 1;
          break;
      }
    }
  }
  
  ~Graph()
  {
    if(eind != NULL) delete[] eind;
    if(eptr != NULL) delete[] eptr;
    if(vwgt != NULL) delete[] vwgt;
    if(partition != NULL) delete[] partition;
    if(adjncy != NULL) delete[] adjncy;
    if(xadj != NULL) delete[] xadj;
  }
};

#endif
