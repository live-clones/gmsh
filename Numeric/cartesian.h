#ifndef _CARTESIAN_H_
#define _CARTESIAN_H_

#include <set>
#include <map>
#include <vector>
#include <stdio.h>
#include "SVector3.h"
#include "SPoint3.h"

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
  // map of stored nodal values, index by the linear index
  // (i + (_Nxi+1) * j + (_Nxi+1) * (_Neta+1) * k)
  typename std::map<int, scalar> _nodalValues;
  // mapping from linear node index to unique node tags
  std::map<int, int> _nodeTags;
  // level of the box (coarset box has highest level; finest box has
  // level==1)
  int _level;
  // pointer to a finer (refined by 2) level box (if any)
  cartesianBox<scalar> *_childBox;
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
  int getNxi(){ return _Nxi; }
  int getNeta(){ return _Neta; }
  int getNzeta(){ return _Nzeta; }
  cartesianBox<scalar> *getChildBox(){ return _childBox; }
  int getLevel(){ return _level; }
  typedef std::set<int>::const_iterator cellIter;
  cellIter activeCellsBegin(){ return _activeCells.begin(); }
  cellIter activeCellsEnd(){ return _activeCells.end(); }
  typedef typename std::map<int, scalar>::iterator valIter;
  valIter nodalValuesBegin(){ return _nodalValues.begin(); }
  valIter nodalValuesEnd(){ return _nodalValues.end(); }
  void setNodalValue(int i, scalar s){ _nodalValues[i] = s; }
  void getCellValues(int t, std::vector<scalar> &values)
  {
    int i, j, k;
    getCellIJK(t, i, j, k);
    for(int I = 0; I < 2; I++)
      for(int J = 0; J < 2; J++)
        for(int K = 0; K < 2; K++){
          typename std::map<int, scalar>::iterator it = 
            _nodalValues.find(getNodeIndex(i + I, j + J, k + K));
          if(it != _nodalValues.end())
            values.push_back(it->second);
          else{
            Msg::Error("Could not find value i,j,k=%d,%d,%d for cell %d\n", 
                       i + I, j + J, k + K, t);
            values.push_back(0.);
          }
        }
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
  SPoint3 getNodeCoordinates(const int &t) const
  {
    int i, j, k;
    getNodeIJK(t, i, j, k);
    const double xi = i * _dxi / _Nxi;
    const double eta = j * _deta / _Neta;
    const double zeta = k * _dzeta / _Nzeta;
    SVector3 D = xi * _xiAxis + eta * _etaAxis + zeta * _zetaAxis;
    return SPoint3(_X + D.x(), _Y + D.y(), _Z + D.z());
  }
  void insertActiveCell(const int &t){ _activeCells.insert(t); }
  void eraseActiveCell(const int &t){ _activeCells.erase(t); }
  void eraseActiveCell(std::set<int>::iterator t){ _activeCells.erase(t); }
  bool activeCellExists(const int &t)
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
    std::set<int>::const_iterator it = _activeCells.begin();
    for( ; it != _activeCells.end() ; ++it){
      const int &t = *it;
      int i, j, k;
      getCellIJK(t, i, j, k);
      for (int I = 0; I < 2; I++)
        for (int J = 0; J < 2; J++)
          for (int K = 0; K < 2; K++)
            _nodalValues[getNodeIndex(i + I, j + J, k + K)] = 0.;
    }
    if(_childBox) _childBox->createNodalValues();
  }
  void writeMSH(const std::string &filename, bool simplex=false, 
                bool writeNodalValues=true) const
  {
    FILE *f = fopen(filename.c_str(), "w");
    if(!f){
      Msg::Error("Could not open file '%s'", filename.c_str());
      return;
    }
    fprintf(f, "$MeshFormat\n2.1 0 8\n$EndMeshFormat\n");
    {
      fprintf(f, "$Nodes\n%d\n", (int)_nodalValues.size());
      typename std::map<int, scalar>::const_iterator it = _nodalValues.begin();
      for ( ; it != _nodalValues.end(); ++it){
        SPoint3 p = getNodeCoordinates(it->first);
        fprintf(f, "%d %g %g %g\n", it->first, p.x(), p.y(), p.z());
      }    
      fprintf(f, "$EndNodes\n");
    }
    {
      int coeff = simplex ? 6 : 1;
      fprintf(f,"$Elements\n%d\n", coeff * (int)_activeCells.size());
      std::set<int>::const_iterator it = _activeCells.begin();
      for ( ; it != _activeCells.end(); ++it){
        int i, j, k;
        getCellIJK(*it, i, j, k);
        if(!simplex){
          fprintf(f, "%d 5 3 1 1 1", *it);
          fprintf(f, " %d", getNodeIndex(i, j, k));
          fprintf(f, " %d", getNodeIndex(i + 1, j, k));
          fprintf(f, " %d", getNodeIndex(i + 1, j + 1, k));
          fprintf(f, " %d", getNodeIndex(i, j + 1, k));
          fprintf(f, " %d", getNodeIndex(i, j, k + 1));
          fprintf(f, " %d", getNodeIndex(i + 1, j, k + 1));
          fprintf(f, " %d", getNodeIndex(i + 1, j + 1, k + 1));
          fprintf(f, " %d", getNodeIndex(i, j + 1, k + 1));
          fprintf(f, "\n");
        }
        else{
          // Elt1
          fprintf(f, "%d 4 3 1 1 1", *it);
          fprintf(f, " %d", getNodeIndex(i, j + 1, k));
          fprintf(f, " %d", getNodeIndex(i, j + 1, k + 1));
          fprintf(f, " %d", getNodeIndex(i + 1, j, k + 1));
          fprintf(f, " %d", getNodeIndex(i + 1, j + 1, k + 1));
          fprintf(f, "\n");
          // Elt2
          fprintf(f, "%d 4 3 1 1 1", *it + 1);
          fprintf(f, " %d", getNodeIndex(i, j + 1, k));
          fprintf(f, " %d", getNodeIndex(i + 1, j + 1, k + 1));
          fprintf(f, " %d", getNodeIndex(i + 1, j, k + 1));
          fprintf(f, " %d", getNodeIndex(i + 1, j + 1, k));
          fprintf(f, "\n");
          // Elt3
          fprintf(f, "%d 4 3 1 1 1", *it + 2);
          fprintf(f, " %d", getNodeIndex(i, j + 1, k));
          fprintf(f, " %d", getNodeIndex(i, j, k + 1));
          fprintf(f, " %d", getNodeIndex(i + 1, j, k + 1));
          fprintf(f, " %d", getNodeIndex(i, j + 1, k + 1));
          fprintf(f, "\n");
          // Elt4
          fprintf(f, "%d 4 3 1 1 1", *it + 3);
          fprintf(f, " %d", getNodeIndex(i, j + 1, k));
          fprintf(f, " %d", getNodeIndex(i + 1, j + 1, k));
          fprintf(f, " %d", getNodeIndex(i + 1, j, k + 1));
          fprintf(f, " %d", getNodeIndex(i + 1, j, k));
          fprintf(f, "\n");
          // Elt5
          fprintf(f, "%d 4 3 1 1 1", *it + 4);
          fprintf(f, " %d", getNodeIndex(i, j + 1, k));
          fprintf(f, " %d", getNodeIndex(i + 1, j, k));
          fprintf(f, " %d", getNodeIndex(i + 1, j, k + 1));
          fprintf(f, " %d", getNodeIndex(i, j, k));
          fprintf(f, "\n");
          // Elt6
          fprintf(f, "%d 4 3 1 1 1", *it + 5);
          fprintf(f, " %d", getNodeIndex(i, j + 1, k));
          fprintf(f, " %d", getNodeIndex(i, j, k));
          fprintf(f, " %d", getNodeIndex(i + 1, j, k + 1));
          fprintf(f, " %d", getNodeIndex(i, j, k + 1));
          fprintf(f, "\n");
        }
      }    
      fprintf(f,"$EndElements\n");    
      if(_childBox)
        _childBox->writeMSH(filename + "_2", simplex, writeNodalValues);
    }
    if(writeNodalValues){
      fprintf(f,"$NodeData\n1\n\"distance\"\n 1\n 0.0\n3\n0\n 1\n %d\n",
              (int)_nodalValues.size());
      typename std::map<int, scalar>::const_iterator it = _nodalValues.begin();
      for( ; it != _nodalValues.end(); ++it)
        fprintf(f, "%d %g\n", it->first, it->second);
      fprintf(f, "$EndNodeData\n");
    }
    fclose(f);
  }
  void writeNodalValues(const std::string &filename) const
  {
    FILE *f = fopen(filename.c_str(), "w");
    fprintf(f, "%d\n", (int)_nodalValues.size());
    typename std::map<int, scalar>::const_iterator it = _nodalValues.begin();
    for( ; it != _nodalValues.end(); ++it)
      fprintf(f, "%d %g\n", it->first, it->second);
    fclose(f);
  }
};

#endif
