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

#if defined(HAVE_KBIPACK)

template <class TTypeA, class TTypeB>
  bool convert(const TTypeA& input, TTypeB& output ){
  std::stringstream stream;
  stream << input;
  stream >> output;
  return stream.good();
}


class Homology
{
 private:
  
  // base cell complex and the model of the homology computation
  CellComplex* _cellComplex;
  GModel* _model;

  // domain and the relative subdomain of the homology computation
  std::vector<int> _domain;
  std::vector<int> _subdomain;
  
  // generator chains
  std::vector<Chain*> _generators[4];
  
  std::string _fileName;
 
 public:
  
  Homology(GModel* model, std::vector<int> physicalDomain,
	   std::vector<int> physicalSubdomain);
  ~Homology();
  
  void setFileName(std::string fileName) { _fileName = fileName; }

  // Find the generators/duals of homology spaces,
  // or just compute the ranks of homology spaces
  void findGenerators();
  void findDualGenerators();
  void computeBettiNumbers();
  
  bool swapSubdomain() { return _cellComplex->swapSubdomain(); }
  
  // Restore the cell complex to its original state before cell reductions
  void restoreHomology();
   
  // Create a string describing the generator
  std::string getDomainString();
  
  // create PViews of the generators and save the chain mesh elements
  // to the mesh of the model
  void createPViews();
  // write the generators to a file
  bool writeGeneratorsMSH(bool binary=false);
  bool writeBettiNumbers() { 
    return _cellComplex->writeBettiNumbers(_fileName); }

};

#endif

#endif
