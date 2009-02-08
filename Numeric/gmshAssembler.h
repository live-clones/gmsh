// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GMSH_ASSEMBLER_H_
#define _GMSH_ASSEMBLER_H_

#include <map>
#include <vector>
#include "gmshLinearSystem.h"

class MVertex;
class MElement;

struct gmshDofKey{
  MVertex *v;
  int comp;
  int field;
  gmshDofKey (MVertex *V, int iComp , int iField)
    : v(V), comp(iComp), field(iField) {} 
  bool operator < (const gmshDofKey& d) const
  {
    if (v < d.v) return true;
    if (v > d.v) return false;
    if (comp < d.comp) return true;
    if (comp > d.comp) return false;
    if (field < d.field) return true;
    return false;
  }
};

class gmshAssembler {
  std::map<gmshDofKey, int>    numbering;
  std::map<gmshDofKey, double> fixed;
  std::map<gmshDofKey, std::vector<std::pair<gmshDofKey,double> > > constraints;
  gmshLinearSystem<double> *lsys;
public:
  gmshAssembler(gmshLinearSystem<double> *l) : lsys(l) {}
  inline void constraintVertex(MVertex*v, int iComp, int iField,
                               std::vector<MVertex*> &verts,
                               std::vector<double> &coeffs)
  {
    std::vector<std::pair<gmshDofKey, double> > constraint;
    gmshDofKey key(v, iComp, iField);
    for (unsigned int i = 0; i < verts.size(); i++){
      gmshDofKey key2(verts[i], iComp, iField);
      constraint.push_back(std::make_pair(key2, coeffs[i]));
    }
    constraints[key] = constraint;
  }
  inline void numberVertex(MVertex*v, int iComp, int iField)
  {
    gmshDofKey key(v, iComp, iField);
    if (fixed.find(key) != fixed.end()) return;
    if (constraints.find(key) != constraints.end()) return;
    std::map<gmshDofKey, int>::iterator it = numbering.find(key);
    if (it == numbering.end()){
      int size = numbering.size();
      numbering[key] = size;
    }
  }
  inline void numberVertex(MVertex*v, int iComp, int iField, int iField2)
  {
    gmshDofKey key(v, iComp, iField);
    gmshDofKey key2(v, iComp, iField2);
    if (fixed.find(key) != fixed.end()) return;
    if (fixed.find(key2) != fixed.end()) return;
    if (constraints.find(key) != constraints.end()) return;
    std::map<gmshDofKey, int> :: iterator it = numbering.find(key);
    if (it == numbering.end()){
      int size = numbering.size();
      numbering[key] = size;
    }
  }
  inline void fixVertex(MVertex*v, int iComp, int iField, double val)
  {
    fixed[gmshDofKey(v, iComp, iField)] = val;
  }
  inline double getDofValue(MVertex*v, int iComp, int iField) const
  {
    gmshDofKey key(v, iComp, iField);
    {
      std::map<gmshDofKey, double>::const_iterator it = fixed.find(key);
      if (it != fixed.end()) return it->second;
    }
    {
      std::map<gmshDofKey, int>::const_iterator it = numbering.find(key);
      if (it != numbering.end())
	return lsys->getFromSolution(it->second);
    }
    {
      std::map<gmshDofKey, std::vector<std::pair<gmshDofKey,double> > >::
        const_iterator itConstr = constraints.find(key);
      if (itConstr != constraints.end()){
	double val = 0;
	for (unsigned int i = 0; i < itConstr->second.size(); i++){
	  const gmshDofKey &dofKeyConstr = itConstr->second[i].first;
	  double valConstr = itConstr->second[i].second;
	  val += getDofValue(dofKeyConstr.v, dofKeyConstr.comp, dofKeyConstr.field)
	    * valConstr;
	}
	return val;
      }
    }
    return 0.0;
  }
  void assemble(MVertex *vR , int iCompR, int iFieldR,
                MVertex *vC , int iCompC, int iFieldC,
                double val);
  void assemble(MVertex *vR , int iCompR, int iFieldR,
                double val);
  int sizeOfR() const { return numbering.size(); }
  int sizeOfF() const { return fixed.size(); }
};

#endif
