// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _CARTESIAN_H_
#define _CARTESIAN_H_

#include <set>
#include <map>
#include <vector>
#include <stdio.h>
#include "SVector3.h"
#include "SPoint3.h"
#include "GmshMessage.h"
#include "MHexahedron.h"
#include "MVertex.h"

// A cartesian grid that encompasses an oriented 3-D box, with values
// stored at vertices:
//
//               j
//   +---+---+---+---+---+---+
//   |   |   |   |   |   |   |
// i +---+---+-(i,j)-+---+---+
//   |   |   |   |   |   |   |
//   +---+---+---+---+---+---+
//
//   Nodal values and active hexahedral cells are stored and
//   referenced by a linear index (i + N * j)
//   
//   The (i,j) cell has nodes (i,j), (i+1,j), (i+1,j+1) and (i,j+1)
template <class scalar>
class cartesianBox {
 private:
  // number of subdivisions along the xi-, eta- and zeta-axis
  int _Nxi, _Neta, _Nzeta;  
  // origin of the grid and spacing along xi, eta and zeta
  double _X, _Y, _Z, _dxi, _deta, _dzeta;
  // xi-, eta- and zeta-axis directions
  SVector3 _xiAxis, _etaAxis, _zetaAxis;
  // set of active cells; the value stored for cell (i,j,k) is the
  // linear index (i + _Nxi * j + _Nxi *_Neta * k)
  std::set<int> _activeCells;
  // map of stored nodal values, indexed by the linear index (i +
  // (_Nxi+1) * j + (_Nxi+1) * (_Neta+1) * k). Along with the value is
  // stored a node tag (used for global numbering of the nodes across
  // the grid levels)
  typename std::map<int, std::pair<scalar, int> > _nodalValues;
  // level of the box (coarsest box has highest level; finest box has
  // level==1)
  int _level;
  // pointer to a finer (refined by 2) level box, if any
  cartesianBox<scalar> *_childBox;
  int _getNumNodes()
  {
    int n = 0;
    for(valIter it = _nodalValues.begin(); it != _nodalValues.end(); it++)
      if(it->second.second > 0) n++;
    if(_childBox) n += _childBox->_getNumNodes();
    return n;
  }
  void _printNodes(FILE *f)
  {
    for (valIter it = _nodalValues.begin(); it != _nodalValues.end(); ++it){
      if(it->second.second > 0){
        SPoint3 p = getNodeCoordinates(it->first);
        fprintf(f, "%d %g %g %g\n", it->second.second, p.x(), p.y(), p.z());
      }
    }
    if(_childBox) _childBox->_printNodes(f);
  }
  int _getNumElements(bool simplex)
  {
    int coeff = simplex ? 6 : 1;
    int n = _activeCells.size() * coeff;
    if(_childBox) n += _childBox->_getNumElements(simplex);
    return n;
  }
  void _printElements(FILE *f, bool simplex, int startingNum=1)
  {
    int num = startingNum;
    for(cellIter it = _activeCells.begin(); it != _activeCells.end(); ++it){
      int i, j, k;
      getCellIJK(*it, i, j, k);
      if(!simplex){
        fprintf(f, "%d 5 3 1 1 1 %d %d %d %d %d %d %d %d\n", num++,
                std::abs(getNodeTag(getNodeIndex(i, j, k))),
                std::abs(getNodeTag(getNodeIndex(i + 1, j, k))),
                std::abs(getNodeTag(getNodeIndex(i + 1, j + 1, k))),
                std::abs(getNodeTag(getNodeIndex(i, j + 1, k))),
                std::abs(getNodeTag(getNodeIndex(i, j, k + 1))),
                std::abs(getNodeTag(getNodeIndex(i + 1, j, k + 1))),
                std::abs(getNodeTag(getNodeIndex(i + 1, j + 1, k + 1))),
                std::abs(getNodeTag(getNodeIndex(i, j + 1, k + 1))));
      }
      else{
        int idx[6][4] = { 
          {getNodeIndex(i, j + 1, k),     getNodeIndex(i, j + 1, k + 1),
           getNodeIndex(i + 1, j, k + 1), getNodeIndex(i + 1, j + 1, k + 1)},
          {getNodeIndex(i, j + 1, k),     getNodeIndex(i + 1, j + 1, k + 1),
           getNodeIndex(i + 1, j, k + 1), getNodeIndex(i + 1, j + 1, k)},
          {getNodeIndex(i, j + 1, k),     getNodeIndex(i, j, k + 1),
           getNodeIndex(i + 1, j, k + 1), getNodeIndex(i, j + 1, k + 1)},
          {getNodeIndex(i, j + 1, k),     getNodeIndex(i + 1, j + 1, k),
           getNodeIndex(i + 1, j, k + 1), getNodeIndex(i + 1, j, k)},
          {getNodeIndex(i, j + 1, k),     getNodeIndex(i + 1, j, k),
           getNodeIndex(i + 1, j, k + 1), getNodeIndex(i, j, k)},
          {getNodeIndex(i, j + 1, k),     getNodeIndex(i, j, k),
           getNodeIndex(i + 1, j, k + 1), getNodeIndex(i, j, k + 1)}
        };
        for(int ii = 0; ii < 6; ii++){
          fprintf(f, "%d 4 3 1 1 1 %d %d %d %d\n", num++,
                  std::abs(getNodeTag(idx[ii][0])), std::abs(getNodeTag(idx[ii][1])),
                  std::abs(getNodeTag(idx[ii][2])), std::abs(getNodeTag(idx[ii][3])));
        }
      }
    }
    if(_childBox) _childBox->_printElements(f, simplex, num);
  }
  void _printValues(FILE *f)
  {
    for(valIter it = _nodalValues.begin(); it != _nodalValues.end(); ++it){
      if(it->second.second > 0)
        fprintf(f, "%d %g\n", it->second.second, it->second.first);
    }
    if(_childBox) _childBox->_printValues(f);
  }
 public:
  cartesianBox(double X, double Y, double Z, 
               const SVector3 &dxi, const SVector3 &deta, const SVector3 &dzeta, 
               int Nxi, int Neta, int Nzeta, int level=1)
    : _X(X), _Y(Y), _Z(Z), 
      _dxi(norm(dxi)), _deta(norm(deta)), _dzeta(norm(dzeta)), 
      _xiAxis(dxi), _etaAxis(deta), _zetaAxis(dzeta),
      _Nxi(Nxi), _Neta(Neta), _Nzeta(Nzeta), _level(level), _childBox(0)
  {
    _xiAxis.normalize();
    _etaAxis.normalize();
    _zetaAxis.normalize();
    if(level > 1)
      _childBox = new cartesianBox<scalar>(X, Y, Z, dxi, deta, dzeta,
                                           2 * Nxi, 2 * Neta, 2 * Nzeta,
                                           level - 1);
  }
  double getLC(){ return sqrt(_dxi * _dxi + _deta * _deta + _dzeta * _dzeta); }
  int getNxi(){ return _Nxi; }
  int getNeta(){ return _Neta; }
  int getNzeta(){ return _Nzeta; }
  cartesianBox<scalar> *getChildBox(){ return _childBox; }
  int getLevel(){ return _level; }
  typedef std::set<int>::const_iterator cellIter;
  cellIter activeCellsBegin(){ return _activeCells.begin(); }
  cellIter activeCellsEnd(){ return _activeCells.end(); }
  typedef typename std::map<int, std::pair<scalar, int> >::iterator valIter;
  valIter nodalValuesBegin(){ return _nodalValues.begin(); }
  valIter nodalValuesEnd(){ return _nodalValues.end(); }
  void setNodalValue(int i, scalar s){ _nodalValues[i].first = s; }
  void getNodalValuesForCell(int t, std::vector<scalar> &values)
  {
    int i, j, k;
    getCellIJK(t, i, j, k);
    for(int I = 0; I < 2; I++)
      for(int J = 0; J < 2; J++)
        for(int K = 0; K < 2; K++){
          valIter it = _nodalValues.find(getNodeIndex(i + I, j + J, k + K));
          if(it != _nodalValues.end())
            values.push_back(it->second.first);
          else{
            Msg::Error("Could not find value i,j,k=%d,%d,%d for cell %d", 
                       i + I, j + J, k + K, t);
            values.push_back(0.);
          }
        }
  }
  double getValueContainingPoint(double x, double y, double z) 
  {

    SVector3 DP (x - _X, y - _Y, z - _Z);
    double xa = dot(DP, _xiAxis);
    double ya = dot(DP, _etaAxis);
    double za = dot(DP, _zetaAxis);

    int t = getCellContainingPoint(x, y,z);
    int i, j, k;
    getCellIJK(t, i, j, k);

    //printf("xyz = %g %g %g \n",x, y, z);
    //printf("ijk =%d %d %d \n", i, j, k);

    valIter it1 = _nodalValues.find(getNodeIndex(i, j, k));
    valIter it2 = _nodalValues.find(getNodeIndex(i + 1, j, k));
    valIter it3 = _nodalValues.find(getNodeIndex(i + 1, j + 1, k));
    valIter it4 = _nodalValues.find(getNodeIndex(i, j + 1, k));
    valIter it5 = _nodalValues.find(getNodeIndex(i, j, k + 1));
    valIter it6 = _nodalValues.find(getNodeIndex(i + 1, j, k + 1));
    valIter it7 = _nodalValues.find(getNodeIndex(i + 1, j + 1, k + 1));
    valIter it8 = _nodalValues.find(getNodeIndex(i, j + 1, k + 1));

    if(it1 == _nodalValues.end()) return _childBox->getValueContainingPoint(x,y,z);
    if(it2 == _nodalValues.end()) return _childBox->getValueContainingPoint(x,y,z);
    if(it3 == _nodalValues.end()) return _childBox->getValueContainingPoint(x,y,z);
    if(it4 == _nodalValues.end()) return _childBox->getValueContainingPoint(x,y,z);
    if(it5 == _nodalValues.end()) return _childBox->getValueContainingPoint(x,y,z);
    if(it6 == _nodalValues.end()) return _childBox->getValueContainingPoint(x,y,z);
    if(it7 == _nodalValues.end()) return _childBox->getValueContainingPoint(x,y,z);
    if(it8 == _nodalValues.end()) return _childBox->getValueContainingPoint(x,y,z);

    double vals[8];
    vals[0]  = it1->second.first;
    vals[1]  = it2->second.first;
    vals[2]  = it3->second.first;
    vals[3]  = it4->second.first;
    vals[4]  = it5->second.first;
    vals[5]  = it6->second.first;
    vals[6]  = it7->second.first;
    vals[7]  = it8->second.first;
    //for (int i= 0; i< 8; i++) printf("vals %d = %g \n", i, vals[i]);

    SPoint3 p1 = getNodeCoordinates(it1->first);
    SPoint3 p2 = getNodeCoordinates(it2->first);
    SPoint3 p3 = getNodeCoordinates(it3->first);
    SPoint3 p4 = getNodeCoordinates(it4->first);
    SPoint3 p5 = getNodeCoordinates(it5->first);
    SPoint3 p6 = getNodeCoordinates(it6->first);
    SPoint3 p7 = getNodeCoordinates(it7->first);
    SPoint3 p8 = getNodeCoordinates(it8->first);

    MVertex *v1 = new MVertex(p1.x(), p1.y(), p1.z());
    MVertex *v2 = new MVertex(p2.x(), p2.y(), p2.z());
    MVertex *v3 = new MVertex(p3.x(), p3.y(), p3.z());
    MVertex *v4 = new MVertex(p4.x(), p4.y(), p4.z());
    MVertex *v5 = new MVertex(p5.x(), p5.y(), p5.z());
    MVertex *v6 = new MVertex(p6.x(), p6.y(), p6.z());
    MVertex *v7 = new MVertex(p7.x(), p7.y(), p7.z());
    MVertex *v8 = new MVertex(p8.x(), p8.y(), p8.z());

    MHexahedron *newElem = new MHexahedron(v1, v2, v3, v4, v5, v6, v7, v8);
    double uvw[3];
    double xyz[3] = {x,y,z};
    newElem->xyz2uvw(xyz, uvw);
    //printf("uvw =%g %g %g \n", uvw[0],uvw[1],uvw[2]);
    double val = newElem->interpolate(vals, uvw[0], uvw[1], uvw[2]);
    
    delete newElem;
    delete v1;
    delete v2;
    delete v3;
    delete v4;
    delete v5;
    delete v6;
    delete v7;
    delete v8;

    return val;
  }
  int getCellContainingPoint(double x, double y, double z) const
  {
    // P = P_0 + xi * _vdx + eta * _vdy + zeta *vdz
    // DP = P-P_0 * _vdx = xi
    SVector3 DP (x - _X, y - _Y, z - _Z);
    double xi = dot(DP, _xiAxis);
    double eta = dot(DP, _etaAxis);
    double zeta = dot(DP, _zetaAxis);    
    int i = xi / _dxi * _Nxi;
    int j = eta / _deta * _Neta;
    int k = zeta / _dzeta * _Nzeta;
    if (i < 0) i = 0; if (i >= _Nxi) i = _Nxi - 1;
    if (j < 0) j = 0; if (j >= _Neta) j = _Neta - 1;
    if (k < 0) k = 0; if (k >= _Nzeta) k = _Nzeta - 1;
    return getCellIndex(i, j, k);
  }
  SPoint3 getNodeCoordinates(int t) const
  {
    int i, j, k;
    getNodeIJK(t, i, j, k);
    const double xi = i * _dxi / _Nxi;
    const double eta = j * _deta / _Neta;
    const double zeta = k * _dzeta / _Nzeta;
    SVector3 D = xi * _xiAxis + eta * _etaAxis + zeta * _zetaAxis;
    return SPoint3(_X + D.x(), _Y + D.y(), _Z + D.z());
  }
  void insertActiveCell(int t){ _activeCells.insert(t); }
  void eraseActiveCell(int t){ _activeCells.erase(t); }
  bool activeCellExists(int t)
  {
    return (_activeCells.find(t) != _activeCells.end()); 
  }
  int getCellIndex(int i, int j, int k) const 
  {
    return i + _Nxi * j + _Nxi *_Neta * k;
  }
  int getNodeIndex(int i, int j, int k) const 
  {
    return i + (_Nxi+1) * j + (_Nxi+1) * (_Neta+1) * k;
  }
  int getNodeTag(int index)
  {
    valIter it = _nodalValues.find(index);
    if(it != _nodalValues.end()) return it->second.second;
    else return 0;
  }
  void getCellIJK(int index, int &i, int &j, int &k) const 
  {
    k = index / (_Nxi * _Neta);
    j = (index - k * (_Nxi * _Neta)) / _Nxi;
    i = (index - k * (_Nxi * _Neta) - j * _Nxi);
  }
  void getNodeIJK(int index, int &i, int &j, int &k) const
  {
    k = index / ((_Nxi + 1) * (_Neta + 1));
    j = (index - k * ((_Nxi + 1) * (_Neta + 1))) / (_Nxi + 1);
    i = (index - k * ((_Nxi + 1) * (_Neta + 1)) - j * (_Nxi + 1));
  }
  void createNodalValues()
  {
    for(cellIter it = _activeCells.begin(); it != _activeCells.end(); ++it){
      const int &t = *it;
      int i, j, k;
      getCellIJK(t, i, j, k);
      for (int I = 0; I < 2; I++)
        for (int J = 0; J < 2; J++)
          for (int K = 0; K < 2; K++)
            _nodalValues[getNodeIndex(i + I, j + J, k + K)] = 
              std::pair<scalar, int>(0., 0);
    }
    if(_childBox) _childBox->createNodalValues();
  }
  void renumberNodes(int startingNum=1, cartesianBox<scalar> *parent=0)
  {
    int num = startingNum;
    for(valIter it = _nodalValues.begin(); it != _nodalValues.end(); it++){
      int i, j, k;
      getNodeIJK(it->first, i, j, k);
      if(!parent || i % 2 || j % 2 || k % 2)
        it->second.second = num++;
      else{
        int tag = parent->getNodeTag(parent->getNodeIndex(i / 2, j / 2, k / 2));
        if(!tag) // FIXME! not sure why this can happen, but it does (bug?)
          it->second.second = num++;
        else // the node exists in the coarset grid: store it with negative sign
          it->second.second = -std::abs(tag);
      }
    }
    if(_childBox) _childBox->renumberNodes(num, this);
  }
  void writeMSH(const std::string &fileName, bool simplex=false, 
                bool writeNodalValues=true)
  {
    FILE *f = fopen(fileName.c_str(), "w");
    if(!f){
      Msg::Error("Could not open file '%s'", fileName.c_str());
      return;
    }
    int numNodes = _getNumNodes(), numElements = _getNumElements(simplex);
    Msg::Info("Writing '%s' (%d nodes, %d elements)", fileName.c_str(), 
              numNodes, numElements);
    fprintf(f, "$MeshFormat\n2.1 0 8\n$EndMeshFormat\n");
    fprintf(f, "$Nodes\n%d\n", numNodes);
    _printNodes(f);
    fprintf(f, "$EndNodes\n");
    fprintf(f,"$Elements\n%d\n", numElements);
    _printElements(f, simplex);
    fprintf(f,"$EndElements\n");    
    if(writeNodalValues){
      fprintf(f,"$NodeData\n1\n\"distance\"\n1\n0.0\n3\n0\n1\n%d\n", numNodes);
      _printValues(f);
      fprintf(f, "$EndNodeData\n");
    }
    fclose(f);
  }
};

#endif
