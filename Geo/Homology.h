// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
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
#include "Chain.h"
#include "OS.h"
#include "GModel.h"
#include "Options.h"

#if defined(HAVE_KBIPACK)

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
  std::vector<int> _nondomain;
  std::vector<int> _nonsubdomain;
  std::vector<int> _imdomain;
  // corresponding geometrical entities
  std::vector<GEntity*> _domainEntities;
  std::vector<GEntity*> _subdomainEntities;
  std::vector<GEntity*> _nondomainEntities;
  std::vector<GEntity*> _nonsubdomainEntities;
  std::vector<GEntity*> _immuneEntities;

  // save original cell complex
  bool _saveOrig;

  // use cell combining
  int _combine;
  // use cell omit
  bool _omit;
  // use chain smoothning
  bool _smoothen;

  // file name to store the results
  std::string _fileName;

  // cell complex of the domain
  CellComplex* _cellComplex;

  bool _homologyComputed[4];
  bool _cohomologyComputed[4];

  // resulting betti numbers and chains
  int _betti[4];
  std::vector<Chain<int>*> _chains[4];
  std::vector<Chain<int>*> _cochains[4];

  typedef std::map<Cell*, int, Less_Cell>::iterator citer;

  void _getEntities(const std::vector<int>& physicalGroups,
                    std::vector<GEntity*>& entities);
  void _getElements(const std::vector<GEntity*>& entities,
                    std::vector<MElement*>& elements);

  // create a string describing the generator
  std::string _getDomainString(const std::vector<int>& domain,
                               const std::vector<int>& subdomain);

  // construct the cell complex
  void _createCellComplex();

  // create and store a chain from homology solver result
  void _createChain(std::map<Cell*, int, Less_Cell>& preChain,
                    std::string name, bool co);

  void _deleteChains(std::vector<int> dim=std::vector<int>());
  void _deleteCochains(std::vector<int> dim=std::vector<int>());

 public:

  // Determine domain and relative subdomain of (co)homology computation
  Homology(GModel* model,
           std::vector<int> physicalDomain,
	   std::vector<int> physicalSubdomain,
           std::vector<int> physicalIm,
           bool saveOrig=true,
	   int combine=2, bool omit=true, bool smoothen=true);
  ~Homology();

  GModel* getModel() const { return _model; }
  void setFileName(std::string fileName) { _fileName = fileName; }

  void getDomain(std::vector<int>& domain) { domain = _domain; }
  void getSubdomain(std::vector<int>& subdomain) { subdomain = _subdomain; }

  // find the bases of (co)homology spaces
  // if dim is empty, find 0-,1-,2-,3-(co)homology spaces bases
  // otherwise only find those indicated in dim
  void findHomologyBasis(std::vector<int> dim=std::vector<int>());
  void findCohomologyBasis(std::vector<int> dim=std::vector<int>());

  // find a homology and cohomology basis pair such that
  // the incidence matrix of the bases is an identity matrix
  // if master==0, homology basis determines the cohomology basis
  // if dim is empty, find 0-,1-,2-,3-(co)homology spaces bases
  // otherwise only find those indicated in dim
  void findCompatibleBasisPair(int master=0,
                               std::vector<int> dim=std::vector<int>());

  // is the (co)homology in given dimensions already compited
  // if dim is empty, return true only if computed in all dimensions
  bool isHomologyComputed(std::vector<int> dim=std::vector<int>());
  bool isCohomologyComputed(std::vector<int> dim=std::vector<int>());

  // add chains to Gmsh model
  // dim: only add dim-chains if dim != -1
  // post: create a post-processing view
  // physicalNumRequest: number the chains starting from this if available
  void addChainsToModel(int dim=-1, bool post=true, int physicalNumRequest=-1);
  void addCochainsToModel(int dim=-1, bool post=true, int physicalNumRequest=-1);

  // get representative chains of a (co)homology space basis
  void getHomologyBasis(int dim, std::vector<Chain<int> >& hom);
  void getCohomologyBasis(int dim, std::vector<Chain<int> >& coh);

  // get a Betti number
  int betti(int dim);

  // get the Euler characteristic
  int eulerCharacteristic();

  // write the generators to a file
  bool writeBasisMSH(bool binary=false);

  // store dim-dimensional cells of cellComplex as a physical group
  // in _model, for debugging
  void storeCells(CellComplex* cellComplex, int dim);
};

#endif

#endif
