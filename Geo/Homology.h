// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
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
#include "PView.h"
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
  
  // the model of the homology computation
  GModel* _model;

  // domain and the relative subdomain of the homology computation
  std::vector<int> _domain;
  std::vector<int> _subdomain;
  std::vector<GEntity*> _domainEntities;
  std::vector<GEntity*> _subdomainEntities;  

  // physical group numbers of generator chains in model
  std::vector<int> _generators;

  std::string _fileName;
 
 public:
  
  Homology(GModel* model, std::vector<int> physicalDomain,
	   std::vector<int> physicalSubdomain);
  ~Homology();
  
  
  CellComplex* createCellComplex(std::vector<GEntity*>& domainEntities,
				 std::vector<GEntity*>& subdomainEntities);
  CellComplex* createCellComplex() { 
    return createCellComplex(_domainEntities, _subdomainEntities); }

  void setFileName(std::string fileName) { _fileName = fileName; }

  // Find the generators/duals of homology spaces,
  // or just compute the ranks of homology spaces
  void findGenerators(CellComplex* cellComplex=NULL);
  void findDualGenerators(CellComplex* cellComplex=NULL);

  void computeRanks() {}  
  void findHomSequence();

   
  // Create a string describing the generator
  std::string getDomainString(const std::vector<int>& domain,
			      const std::vector<int>& subdomain);
  
  // write the generators to a file
  bool writeGeneratorsMSH(bool binary=false);
  // store dim-dimensional cells of cellComplex as a pshysical group
  // in _model, for debugging
  void storeCells(CellComplex* cellComplex, int dim);

};

// A class representing a chain.
// Used to visualize generators of the homology groups.
class Chain{
  
 private:
  // cells and their coefficients in this chain
  std::map< Cell*, int, Less_Cell > _cells;
  // name of the chain (optional)
  std::string _name;
  // physical group number of the chain
  int _num;
  // cell complex this chain belongs to
  CellComplex* _cellComplex;
  GModel* _model;
   
  // torsion coefficient
  int _torsion;
  
  int _dim;
  
  bool deform(std::map<Cell*, int, Less_Cell> &cellsInChain, 
	      std::map<Cell*, int, Less_Cell> &cellsNotInChain);
  bool deformChain(std::pair<Cell*, int> cell, bool bend);
  
  
 public:
  Chain() {}
  Chain(std::set<Cell*, Less_Cell> cells, std::vector<int> coeffs, 
	CellComplex* cellComplex, GModel* model,
	std::string name="Chain", int torsion=0);
  Chain(std::map<Cell*, int, Less_Cell>& chain,
        CellComplex* cellComplex, GModel* model,
        std::string name="Chain", int torsion=0);
  Chain(Chain* chain){ 
    _cells = chain->getCells();
    _torsion = chain->getTorsion();
    _name = chain->getName();
    _cellComplex = chain->getCellComplex();
    _dim = chain->getDim();
    _model = chain->getGModel();
    _num = chain->getNum();
  }  
  typedef std::map<Cell*, int, Less_Cell>::iterator citer;
  citer firstCell() {return _cells.begin(); }
  citer lastCell() {return _cells.end(); }

  ~Chain() {} 

  // remove a cell from this chain
  void removeCell(Cell* cell);
   
  // add a cell to this chain
  void addCell(Cell* cell, int coeff);
  
  bool hasCell(Cell* c);
  Cell* findCell(Cell* c);
  int getCoeff(Cell* c);
  
  
  int getTorsion() { return _torsion; }
  int getDim() { return _dim; }
  CellComplex* getCellComplex() { return _cellComplex; }
  GModel* getGModel() { return _model; }
  std::map<Cell*, int, Less_Cell>  getCells() { return _cells; }
  
  // erase cells from the chain with zero coefficient
  void eraseNullCells();
   
  void deImmuneCells();
  
  // number of cells in this chain 
  int getSize() { return _cells.size();}
  
  // get/set chain name
  std::string getName() { return _name; }
  void setName(std::string name) { _name=name; }
  // get/set physical group number
  int getNum() { return _num; }
  void setNum(int num) { _num=num; }
  
  // make local deformations to the chain to make it smoother and smaller
  // (for primary complex chains only, not for dual chains represented 
  // by primary cells (yet).)
  void smoothenChain();
  
  // append this chain to a MSH ASCII file as $ElementData
  // for debugging only
  int writeChainMSH(const std::string &name);

  // create a physical group of this chain.
  int createPGroup();
  
};

#endif

#endif
