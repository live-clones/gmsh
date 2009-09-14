// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _DOF_MANAGER_H_
#define _DOF_MANAGER_H_

#include <vector>
#include <string>
#include <map>

class gmshLinearSystem;

class Dof{
 private:
  // v(x) = \sum_f \sum_i v_{fi} s^f_i(x)
  long int _entity; // "i": node, edge, group, etc.
  int _type; // "f": basis function type index, etc.

 public:
  Dof(long int entity, int type) : _entity(entity), _type(type) {}
  inline long int getEntity() const { return _entity; }
  inline int getType() const { return _type; }
};

template<class dataVec, class dataMat>
class DofAffineConstraint{
 public:
  std::vector<std::pair<Dof, dataMat> > linear;
  dataVec shift;
};

// data=float, double, complex<double>, smallVec<double>, smallVec<complex<double> >...
template <class dataVec, class dataMat>
class DofManager{
 private:
  // general affine constraint on sub-blocks, treated by adding
  // equations:
  //   dataMat * DofVec = \sum_i dataMat_i * DofVec_i + dataVec
  std::map<std::pair<Dof, dataMat>, DofAffineConstraint> constraint;

  // fixations on full blocks, treated by eliminating equations:
  //   DofVec = dataVec
  std::map<Dof, dataVec> fixed, initial;

  // numbering of unknown dof blocks
  std::map<Dof, long int> unknown;

  // associatations
  std::map<Dof, Dof> associatedWith;

 private:
  // linear system(s):
  std::vector<gmshLinearSystem<dataMat>*> linearSystems;

 public:
  DofManager(/* linAlgOptions &opt */){}
  dataVec getDofValue(long int entity, int type) const;
  void createFixedDof(long int entity, int type, const dataVec &value);
};

/*
class termOfFormulation{
 public:
  // hard-coded OR not!
};

class field{
 private:
  std::string _name;

  // unique mapping between dofs and names:
  static std::map<int, std::string> _names;
  static int typeFromName(std::string name);
  static std::string nameFromType(int type);

  // size of a dof block
  static int blockSizeFromType(int type);

  // doit pouvoir etre evalu

