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
  private:
  
  unsigned int _ne;                           /*The number of elements*/
  
  unsigned int _nn;                           /*The number of nodes*/
  
  unsigned int _dim;                          /*The dimension of the mesh*/
  
  unsigned int *_eind;                        /*The list of nodes belonging to the ith element of the
                                              mesh are stored in consecutive locations of eind 
                                              starting at position eptr[i] up to (but not including) 
                                              position eptr[i+1]. The size of the eind array is of
                                              size equal to the sum of the number of nodes in all the 
                                              elements of the mesh.*/
  
  unsigned int *_eptr;                        /*The size of the eptr array is n + 1, where n is
                                              the number of elements in the mesh.*/
  
  unsigned int *_xadj;                        /*The metis graph structure*/
  
  
  unsigned int *_adjncy;                      /*The metis graph structure*/
  
  MElement** _element;                        /*Elements corresponding to each graph elements
                                              in eptr*/
  
  int* _vertex;                               /*Vertices corresponding to each graph vertices
                                               in eptr*/
  
  unsigned int *_vwgt;                        /*The width associated to each elements of eptr*/
  
  unsigned int *_partition;                   /*The partitions output from the partitioner*/

  public:
  
  Graph() : _ne(0), _nn(0), _dim(0), _eind(NULL), _eptr(NULL), _xadj(NULL), _adjncy(NULL), _element(NULL), _vertex(NULL), _vwgt(NULL), _partition(NULL)
  { }
  
  void fillDefaultWeights()
  {
    _vwgt = new unsigned int[_ne];
    for(unsigned int i = 0; i < _ne; i++)
    {
      if(_element[i] == NULL)
      {
        _vwgt[i] = 1;
        continue;
      }
      switch (_element[i]->getType())
      {
        case TYPE_TRI:
          _vwgt[i] = CTX::instance()->mesh.part_triWeight;
          break;
        case TYPE_QUA:
          _vwgt[i] = CTX::instance()->mesh.part_quaWeight;
          break;
        case TYPE_TET:
          _vwgt[i] = CTX::instance()->mesh.part_tetWeight;
          break;
        case TYPE_PYR:
          _vwgt[i] = CTX::instance()->mesh.part_pyrWeight;
          break;
        case TYPE_PRI:
          _vwgt[i] = CTX::instance()->mesh.part_priWeight;
          break;
        case TYPE_HEX:
          _vwgt[i] = CTX::instance()->mesh.part_hexWeight;
          break;
        default:
          _vwgt[i] = 1;
          break;
      }
    }
  }
  
  ~Graph()
  {
    clear();
  }
  
  unsigned int ne() const { return _ne; };
  unsigned int nn() const { return _nn; };
  unsigned int dim() const { return _dim; };
  unsigned int eind(unsigned int i) const { return _eind[i]; };
  unsigned int *eind() const { return _eind; };
  unsigned int eptr(unsigned int i) const { return _eptr[i]; };
  unsigned int *eptr() const { return _eptr; };
  unsigned int xadj(unsigned int i) const { return _xadj[i]; };
  unsigned int *xadj() const { return _xadj; };
  unsigned int adjncy(unsigned int i) const { return _adjncy[i]; };
  unsigned int *adjncy() const { return _adjncy; };
  MElement* element(unsigned int i) const { return _element[i]; };
  int vertex(unsigned int i) const { return _vertex[i]; };
  unsigned int *vwgt() const { return _vwgt; };
  unsigned int partition(unsigned int i) const { return _partition[i]; };
  unsigned int *partition() const { return _partition; };
  
  void ne(unsigned int ne) { _ne = ne; };
  void nn(unsigned int nn) { _nn = nn; };
  void dim(unsigned int dim) { _dim = dim; };
  void eindResize(unsigned int size)
  {
    _eind = new unsigned int[size];
    for(unsigned int i = 0; i < size; i++) _eind[i] = 0;
  }
  void eind(unsigned int i, unsigned int eind) { _eind[i] = eind; };
  void eptrResize(unsigned int size)
  {
    _eptr = new unsigned int[size];
    for(unsigned int i = 0; i < size; i++) _eptr[i] = 0;
  }
  void eptr(unsigned int i, unsigned int eptr) { _eptr[i] = eptr; };
  void xadjResize(unsigned int size)
  {
    _xadj = new unsigned int[size];
    for(unsigned int i = 0; i < size; i++) _xadj[i] = 0;
  }
  void xadj(unsigned int i, unsigned int xadj) { _xadj[i] = xadj; };
  void adjncyResize(unsigned int size)
  {
    _adjncy = new unsigned int[size];
    for(unsigned int i = 0; i < size; i++) _adjncy[i] = 0;
  }
  void adjncy(unsigned int i, unsigned int adjncy) { _adjncy[i] = adjncy; };
  void elementResize(unsigned int size)
  {
    _element = new MElement*[size];
    for(unsigned int i = 0; i < size; i++) _element[i] = NULL;
  }
  void element(unsigned int i, MElement* element) { _element[i] = element; };
  void vertexResize(unsigned int size)
  {
    _vertex = new int[size];
    for(unsigned int i = 0; i < size; i++) _vertex[i] = -1;
  }
  void vertex(unsigned int i, int vertex) { _vertex[i] = vertex; };
  void vwgt(unsigned int *vwgt) { _vwgt = vwgt; };
  void partition(unsigned int *partition) { _partition = partition; };
  
  void clear()
  {
    if(_eind != NULL)
    {
      delete[] _eind;
      _eind = NULL;
    }
    if(_eptr != NULL)
    {
      delete[] _eptr;
      _eptr = NULL;
    }
    if(_xadj != NULL)
    {
      delete[] _xadj;
      _xadj = NULL;
    }
    if(_adjncy != NULL)
    {
      delete[] _adjncy;
      _adjncy = NULL;
    }
    if(_element != NULL)
    {
      delete[] _element;
      _element = NULL;
    }
    if(_vertex != NULL)
    {
      delete[] _vertex;
      _vertex = NULL;
    }
    if(_vwgt != NULL)
    {
      delete[] _vwgt;
      _vwgt = NULL;
    }
    if(_partition != NULL)
    {
      delete[] _partition;
      _partition = NULL;
    }
  }
  
};

#endif
