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
  // corresponding geometrical entities
  std::vector<GEntity*> _domainEntities;
  std::vector<GEntity*> _subdomainEntities;

  // use cell combining
  bool _combine;
  // use cell omit
  bool _omit;
  // use chain smoothning
  bool _smoothen;

  // save chains of 0 and highest dimension
  bool _save0N;
  // save original cell complex
  bool _saveOrig;

  // file name to store the results
  std::string _fileName;

  typedef std::map<Cell*, int, Less_Cell>::iterator citer;

  // create a string describing the generator
  std::string _getDomainString(const std::vector<int>& domain,
			      const std::vector<int>& subdomain);

  // remove cells with coefficient 0
  int _eraseNullCells(std::map<Cell*, int, Less_Cell>& chain);

  // create a Gmsh physical group from a chain
  void _createPhysicalGroup(std::map<Cell*, int, Less_Cell>& chain, std::string name);

 public:

  Homology(GModel* model, std::vector<int> physicalDomain,
	   std::vector<int> physicalSubdomain,
           bool save0N=false, bool saveOrig=true,
	   bool combine=true, bool omit=true, bool smoothen=true);
  ~Homology();

  // create a cell complex from a mesh in geometrical entities of Gmsh
  CellComplex* createCellComplex(std::vector<GEntity*>& domainEntities,
				 std::vector<GEntity*>& subdomainEntities);
  CellComplex* createCellComplex();

  GModel* getModel() const { return _model; }
  void setFileName(std::string fileName) { _fileName = fileName; }

  // find the generators/dual generarators  of homology spaces,
  void findHomologyBasis(CellComplex* cellComplex=NULL);
  void findCohomologyBasis(CellComplex* cellComplex=NULL);

  // write the generators to a file
  bool writeBasisMSH(bool binary=false);

  // store dim-dimensional cells of cellComplex as a physical group
  // in _model, for debugging
  void storeCells(CellComplex* cellComplex, int dim);
};

#endif

#endif
