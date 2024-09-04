// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Matti Pellikka <matti.pellikka@gmail.com>.

#ifndef HOMOLOGY_H
#define HOMOLOGY_H

#include <sstream>
#include "CellComplex.h"
#include "ChainComplex.h"
#include "Chain.h"
#include "OS.h"
#include "GModel.h"
#include "Options.h"

#if defined(HAVE_KBIPACK)

std::vector<int> vecN0(int n);

// Interface class for homology computation in Gmsh
class Homology {
private:
  // the Gmsh model for homology computation
  GModel *_model;

  // domain and the relative subdomain of the homology computation
  // physical group IDs
  std::vector<int> _domain;
  std::vector<int> _subdomain;
  std::vector<int> _nondomain;
  std::vector<int> _nonsubdomain;
  std::vector<int> _imdomain;
  // corresponding geometrical entities
  std::vector<GEntity *> _domainEntities;
  std::vector<GEntity *> _subdomainEntities;
  std::vector<GEntity *> _nondomainEntities;
  std::vector<GEntity *> _nonsubdomainEntities;
  std::vector<GEntity *> _immuneEntities;

  // save original cell complex
  bool _saveOrig;

  // use cell combining
  int _combine;
  // use cell omit
  bool _omit;
  // use chain smoothning
  bool _smoothen;
  // corecution heuristic
  int _heuristic;

  // file name to store the results
  std::string _fileName;

  // cell complex of the domain
  CellComplex *_cellComplex;

  // whether representatives of (co)homology bases are available
  bool _homologyComputed[4];
  bool _cohomologyComputed[4];

  // resulting betti numbers and chains
  int _betti[4];
  std::vector<Chain<int> *> _chains[4];
  std::vector<Chain<int> *> _cochains[4];

  typedef std::map<Cell *, int, CellPtrLessThan>::iterator citer;

  void _getEntities(const std::vector<int> &physicalGroups,
                    std::vector<GEntity *> &entities);
  void _getElements(const std::vector<GEntity *> &entities,
                    std::vector<MElement *> &elements);

  // create a string describing the generator
  std::string _getDomainString(const std::vector<int> &domain,
                               const std::vector<int> &subdomain) const;

  // construct the cell complex
  void _createCellComplex();

  // create and store a chain from homology solver result
  void _createChain(std::map<Cell *, int, CellPtrLessThan> &preChain,
                    const std::string &name, bool co);

  void _deleteChains(std::vector<int> dim = vecN0(4));
  void _deleteCochains(std::vector<int> dim = vecN0(4));

  std::vector<int> _addToModel(int dim, bool co, bool post,
                               int physicalNumRequest) const;

public:
  // Determine domain and relative subdomain of (co)homology computation
  Homology(GModel *model, const std::vector<int> &physicalDomain,
           const std::vector<int> &physicalSubdomain,
           const std::vector<int> &physicalIm, bool saveOrig = true,
           int combine = 3, bool omit = true, bool smoothen = true,
           int heuristic = 1);
  ~Homology();

  GModel *getModel() const { return _model; }
  void setFileName(const std::string &fileName) { _fileName = fileName; }

  void getDomain(std::vector<int> &domain) const { domain = _domain; }
  void getSubdomain(std::vector<int> &subdomain) const
  {
    subdomain = _subdomain;
  }

  // find the bases of (co)homology spaces
  // if dim is not provided,, find 0-,1-,2-,3-(co)homology spaces bases
  // otherwise only find those indicated in dim
  void findHomologyBasis(std::vector<int> dim = vecN0(4));
  void findCohomologyBasis(std::vector<int> dim = vecN0(4));

  // find a homology and cohomology basis pair such that
  // the incidence matrix of the bases is an identity matrix
  // if master==0, homology basis determines the cohomology basis
  // if dim is not provided, find 0-,1-,2-,3-(co)homology spaces bases
  // otherwise only find those indicated in dim
  void findCompatibleBasisPair(int master = 0, std::vector<int> dim = vecN0(4));

  // is the (co)homology in given dimensions already compited
  // if dim is not provided, return true only if computed in all dimensions
  bool isHomologyComputed(std::vector<int> dim = vecN0(4)) const;
  bool isCohomologyComputed(std::vector<int> dim = vecN0(4)) const;

  // add chains to Gmsh model
  // dim: only add dim-chains if dim != -1
  // post: create a post-processing view
  // physicalNumRequest: number the chains starting from this if available
  // returns physical group numbers
  std::vector<int> addChainsToModel(int dim = -1, bool post = true,
                                    int physicalNumRequest = -1) const;
  std::vector<int> addCochainsToModel(int dim = -1, bool post = true,
                                      int physicalNumRequest = -1) const;

  // get representative chains of a (co)homology space basis
  void getHomologyBasis(int dim, std::vector<Chain<int> > &hom);
  void getCohomologyBasis(int dim, std::vector<Chain<int> > &coh);

  // find Betti numbers
  // faster than finding bases for (co)homology spaces
  void findBettiNumbers();

  // are Betti numbers computed
  bool isBettiComputed() const;

  // get a Betti number
  int betti(int dim);

  // get the Euler characteristic
  int eulerCharacteristic();

  // write the generators to a file
  bool writeBasisMSH(bool binary = false);

  // store dim-dimensional cells of cellComplex as a physical group
  // in _model, for debugging
  void storeCells(CellComplex *cellComplex, int dim);
};

#endif

#endif
