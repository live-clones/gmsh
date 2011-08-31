// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
// 
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
// 
// Contributed by Matti Pellikka <matti.pellikka@tut.fi>.

#ifndef _HOMOLOGY_H_
#define _HOMOLOGY_H_

#include <sstream>
#include "CellComplex.h"
#include "ChainComplex.h"
#include "OS.h"
#include "GModel.h"
#include "Options.h"

#if defined(HAVE_KBIPACK)

template <class TTypeA, class TTypeB>
  bool convert(const TTypeA& input, TTypeB& output ){
  std::stringstream stream;
  stream << input;
  stream >> output;
  return stream.good();
}

class Chain;

// Interface class for homology computation in Gmsh
class Homology
{
 private:
  
  // the Gmsh model for homology computation
  GModel* _model;

  // domain and the relative subdomain of the homology computation
  // physical group IDs
  std::vector<int> _domain;
  std::vector<int> _subdomain;
  // corresponding geometrical entities
  std::vector<GEntity*> _domainEntities;
  std::vector<GEntity*> _subdomainEntities;  

  // use cell combining
  bool _combine;
  // use cell omit
  bool _omit;
  // use chain smoothning
  bool _smoothen;

  int _maxdomain;
  int _maxnum;

  // file name to store the results
  std::string _fileName;
 
  std::map<int, Chain*> _basisChains;

 public:
  
  Homology(GModel* model, std::vector<int> physicalDomain,
	   std::vector<int> physicalSubdomain, 
	   bool combine=true, bool omit=true, bool smoothen=true);
  ~Homology();
  
  // create a cell complex from a mesh in geometrical entities of Gmsh
  CellComplex* createCellComplex(std::vector<GEntity*>& domainEntities,
				 std::vector<GEntity*>& subdomainEntities);
  CellComplex* createCellComplex() { 
    return createCellComplex(_domainEntities, _subdomainEntities); }

  void setFileName(std::string fileName) { _fileName = fileName; }

  // find the generators/dual generarators  of homology spaces,
  void findGenerators(CellComplex* cellComplex=NULL);
  void findDualGenerators(CellComplex* cellComplex=NULL);

  // experimental
  void findHomSequence() {}
  void computeRanks() {}  
   
  // create a string describing the generator
  std::string getDomainString(const std::vector<int>& domain,
			      const std::vector<int>& subdomain);
  
  // write the generators to a file
  bool writeGeneratorsMSH(bool binary=false);
  // store dim-dimensional cells of cellComplex as a physical group
  // in _model, for debugging
  void storeCells(CellComplex* cellComplex, int dim);

  GModel* getModel() const { return _model; }

};

// A class representing a chain.
// Used to store generators of the homology spaces and visualize them in Gmsh.
class Chain {
  
 private:
  // cells and their coefficients in this chain
  std::map< Cell*, int, Less_Cell > _cells;
  // name of the chain (optional)
  std::string _name;
  // physical group number of the chain
  int _num;
  // cell complex this chain belongs to
  CellComplex* _cellComplex;
   
  // torsion coefficient
  int _torsion;
  
  int _dim;
  
 public:
  Chain(std::map<Cell*, int, Less_Cell>& chain,
        CellComplex* cellComplex, int num,
        std::string name="Chain", int torsion=0);

  typedef std::map<Cell*, int, Less_Cell>::iterator citer;
  citer firstCell() {return _cells.begin(); }
  citer lastCell() {return _cells.end(); }

  int getTorsion() const { return _torsion; }
  int getDim() const { return _dim; }
  CellComplex* getCellComplex() const { return _cellComplex; }
  void getCells(std::map<Cell*, int, Less_Cell> cells) const { 
    cells = _cells; }
  
  // erase cells from the chain with zero coefficient
  void eraseNullCells();
  
  // number of cells in this chain 
  int getSize() const { return _cells.size();}
  
  // get/set chain name
  std::string getName() const { return _name; }
  void setName(std::string name) { _name=name; }
  // get/set physical group number
  int getNum() const { return _num; }
  void setNum(int num) { _num=num; }
  
  // append this chain to a MSH ASCII file as $ElementData
  // for debugging only
  int writeChainMSH(const std::string &name);

  // create a Gmsh physical group from this chain.
  int createPGroup();
  
};

#endif

#endif
