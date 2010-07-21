#ifndef _CARTESIAN_H_
#define _CARTESIAN_H_

#include <set>
#include <map>
#include <vector>
#include <stdio.h>
#include "SVector3.h"
#include "SPoint3.h"

// This is a cartesian mesh that encompasses an oriented box with NXI
// * NETA * NZETA hexaderal cells, with values stored at vertices

/*
  2-D example:

               j
   +---+---+---+---+---+---+
   |   |   |   |ij |   |   |
 i +---+---+---+---+---+---+
   |   |   |   |   |   |   |
   +---+---+---+---+---+---+

   Nodal values/active cells are stored and referenced by node/cell
   index, i.e., i+N*j

   The ij cell has nodes i;j , i+1;j , i+1;j+1, i;j+1
*/

template <class scalar>
class cartesianBox {
 private:  
  int _Nxi, _Neta, _Nzeta;  
  double _X, _Y, _Z, _dxi, _deta, _dzeta;
  SVector3 _xiAxis, _etaAxis, _zetaAxis;
  std::set<int> _activeCells;
  typename std::map<int, scalar> _nodalValues;
  int _level;
  cartesianBox<scalar> *_childBox;
 public:
  cartesianBox(double X, double Y, double Z, 
               const SVector3 &DXI, const SVector3 &DETA, const SVector3 &DZETA, 
               int NXI, int NETA, int NZETA, int level=1)
    : _X(X), _Y(Y), _Z(Z), 
      _dxi(norm(DXI)), _deta(norm(DETA)), _dzeta(norm(DZETA)), 
      _xiAxis(DXI), _etaAxis(DETA), _zetaAxis(DZETA),
      _Nxi(NXI), _Neta(NETA), _Nzeta(NZETA), _level(level), _childBox(0)
  {
    _xiAxis.normalize();
    _etaAxis.normalize();
    _zetaAxis.normalize();
    if(level > 1)
      _childBox = new cartesianBox<scalar>(X, Y, Z, DXI, DETA, DZETA,
                                           2 * NXI, 2 * NETA, 2 * NZETA,
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
  void getNodalValues(const int &t, std::vector<scalar> &ls_values)
  {
    // perhaps not optimal (lot of searches...)
    int i, j, k;
    getCellIJK(t, i, j, k);
    typename std::map<int, scalar>::iterator itNode;

    itNode = _nodalValues.find(getNodeIndex(i, j, k));
    ls_values.push_back(itNode->second);

    itNode = _nodalValues.find(getNodeIndex(i+1,j,k));
    ls_values.push_back(itNode->second);

    itNode = _nodalValues.find(getNodeIndex(i+1,j+1,k));
    ls_values.push_back(itNode->second);

    itNode = _nodalValues.find(getNodeIndex(i,j+1,k));
    ls_values.push_back(itNode->second);

    itNode = _nodalValues.find(getNodeIndex(i,j,k+1));
    ls_values.push_back(itNode->second);

    itNode = _nodalValues.find(getNodeIndex(i+1,j,k+1));
    ls_values.push_back(itNode->second);

    itNode = _nodalValues.find(getNodeIndex(i+1,j+1,k+1));
    ls_values.push_back(itNode->second);

    itNode = _nodalValues.find(getNodeIndex(i,j+1,k+1));
    ls_values.push_back(itNode->second);
  }
  inline int getCellContainingPoint(double x, double y, double z) const
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
  inline SPoint3 getNodeCoordinates(const int &t) const
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
  inline int getCellIndex(int i, int j, int k) const 
  {
    return i + _Nxi * j + _Nxi *_Neta * k;
  }
  inline int getNodeIndex(int i, int j, int k) const 
  {
    return i + (_Nxi+1) * j + (_Nxi+1) * (_Neta+1) * k;
  }
  inline void getCellIJK(int index, int &i, int &j, int &k) const 
  {
    k = index / (_Nxi * _Neta);
    j = (index - k * (_Nxi * _Neta)) / _Nxi;
    i = (index - k * (_Nxi * _Neta) - j * _Nxi);
  }
  inline void getNodeIJK(int index, int &i, int &j, int &k) const
  {
    k = index / ((_Nxi + 1) * (_Neta + 1));
    j = (index - k * ((_Nxi + 1) * (_Neta + 1))) / (_Nxi + 1);
    i = (index - k * ((_Nxi + 1) * (_Neta + 1)) - j * (_Nxi + 1));
  }
  inline void createNodalValues()
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
