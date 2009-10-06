// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributed by Matti Pellikka.
 

#include "Homology.h"
#include "ChainComplex.h"
#include "OS.h"

#if defined(HAVE_KBIPACK)
Homology::Homology(GModel* model, std::vector<int> physicalDomain, std::vector<int> physicalSubdomain){
  
  _model = model;
  _combine = true;
  _omit = 1;
  
  Msg::Info("Creating a Cell Complex...");
  double t1 = Cpu();
  
  std::map<int, std::vector<GEntity*> > groups[4];
  model->getPhysicalGroups(groups);
  
  
  std::map<int, std::vector<GEntity*> >::iterator it;
  std::vector<GEntity*> domainEntities;
  std::vector<GEntity*> subdomainEntities;
    
  for(unsigned int i = 0; i < physicalDomain.size(); i++){
    for(int j = 0; j < 4; j++){
      it = groups[j].find(physicalDomain.at(i));
      if(it != groups[j].end()){
        std::vector<GEntity*> physicalGroup = (*it).second;
        for(unsigned int k = 0; k < physicalGroup.size(); k++){
          domainEntities.push_back(physicalGroup.at(k));
        }
      }
    }
  }
  for(unsigned int i = 0; i < physicalSubdomain.size(); i++){           
    for(int j = 0; j < 4; j++){
      it = groups[j].find(physicalSubdomain.at(i));
      if(it != groups[j].end()){
        std::vector<GEntity*> physicalGroup = (*it).second;
        for(unsigned int k = 0; k < physicalGroup.size(); k++){
          subdomainEntities.push_back(physicalGroup.at(k));
        }
        
      }
    }
  }
  
  if(domainEntities.empty()) Msg::Warning("Domain is empty.");
  if(subdomainEntities.empty()) Msg::Info("Subdomain is empty.");
  
  
  _cellComplex =  new CellComplex(domainEntities, subdomainEntities);
  
  if(_cellComplex->getSize(0) == 0){ 
    Msg::Error("Cell Complex is empty!");
    Msg::Error("Check the domain & the mesh.");
    return;
  }
  double t2 = Cpu();
  Msg::Info("Cell Complex complete (%g s).", t2 - t1);
  Msg::Info("%d volumes, %d faces, %d edges and %d vertices.",
            _cellComplex->getSize(3), _cellComplex->getSize(2), _cellComplex->getSize(1), _cellComplex->getSize(0));
  
}


void Homology::findGenerators(std::string fileName){
  
  
  
  Msg::Info("Reducing Cell Complex...");
  double t1 = Cpu();
  //_cellComplex->printEuler();
  int omitted = _cellComplex->reduceComplex(_omit);
  //_cellComplex->printEuler();
  
  _cellComplex->emptyTrash();
  
  if(getCombine()){
    _cellComplex->combine(3);
    _cellComplex->reduction(2);
    _cellComplex->combine(2);
    _cellComplex->reduction(1);
    _cellComplex->combine(1);
  }
  _cellComplex->checkCoherence();
  //_cellComplex->printEuler();
  
  _cellComplex->emptyTrash();
  
  double t2 = Cpu();
  Msg::Info("Cell Complex reduction complete (%g s).", t2 - t1);
  Msg::Info("%d volumes, %d faces, %d edges and %d vertices.",
            _cellComplex->getSize(3), _cellComplex->getSize(2), _cellComplex->getSize(1), _cellComplex->getSize(0));

  //for(int i = 0; i < 4; i++) { printf("Dim %d: \n", i); _cellComplex->printComplex(i); }
  
  _cellComplex->writeComplexMSH(fileName);
  
  Msg::Info("Computing homology groups...");
  t1 = Cpu();
  ChainComplex* chains = new ChainComplex(_cellComplex);
  chains->computeHomology();
  t2 = Cpu();
  Msg::Info("Homology Computation complete (%g s).", t2 - t1);
   
  int HRank[4];
  for(int j = 0; j < 4; j++){
    HRank[j] = 0;
    std::string dimension;
    convert(j, dimension);
    for(int i = 1; i <= chains->getBasisSize(j); i++){
      
      std::string generator;
      convert(i, generator);
      
      std::string name = dimension + "D Generator " + generator;
      Chain* chain = new Chain(_cellComplex->getCells(j), chains->getCoeffVector(j,i), _cellComplex, name, chains->getTorsion(j,i));
      chain->writeChainMSH(fileName);
      if(chain->getSize() != 0) {
        HRank[j] = HRank[j] + 1;
        if(chain->getTorsion() != 1) Msg::Warning("%dD Generator %d has torsion coefficient %d!", j, i, chain->getTorsion());
      }
      delete chain;
    }
    if(j == _cellComplex->getDim() && _cellComplex->getNumOmitted() > 0){
      for(int i = 0; i < _cellComplex->getNumOmitted(); i++){
        std::string generator;
        convert(i+1, generator);
        std::string name = dimension + "D Generator " + generator;
        std::vector<int> coeffs (_cellComplex->getOmitted(i).size(),1);
        Chain* chain = new Chain(_cellComplex->getOmitted(i), coeffs, _cellComplex, name, 1);
        chain->writeChainMSH(fileName);
        if(chain->getSize() != 0) HRank[j] = HRank[j] + 1;
        delete chain;
        
      }
    }
    
    
  }
  
  Msg::Info("Ranks of homology groups for primal cell complex:");
  Msg::Info("H0 = %d", HRank[0]);
  Msg::Info("H1 = %d", HRank[1]);
  Msg::Info("H2 = %d", HRank[2]);
  Msg::Info("H3 = %d", HRank[3]);
  if(omitted != 0) Msg::Info("The computation of generators in %d highest dimensions was omitted.", _omit);
  
  Msg::Info("Wrote results to %s.", fileName.c_str());
  printf("Wrote results to %s. \n", fileName.c_str());
  
  delete chains;
  
  printf("H0 = %d \n", HRank[0]);
  printf("H1 = %d \n", HRank[1]);
  printf("H2 = %d \n", HRank[2]);
  printf("H3 = %d \n", HRank[3]);
  
  return;
}

void Homology::findDualGenerators(std::string fileName){
  
  //for(int i = 0; i < 4; i++) { printf("Dim %d: \n", i); _cellComplex->printComplex(i); }
  
  Msg::Info("Reducing Cell Complex...");
  double t1 = Cpu();
  int omitted = _cellComplex->coreduceComplex(_omit);
  _cellComplex->emptyTrash();
  
  /*
  _cellComplex->makeDualComplex();
  int omitted = _cellComplex->reduceComplex(_omit);
  if(getCombine()){
    _cellComplex->combine(3);
    _cellComplex->combine(2);
    _cellComplex->combine(1);
  }
  _cellComplex->makeDualComplex();
  */
  
  if(getCombine()){
    _cellComplex->cocombine(0);
    _cellComplex->cocombine(1);
    _cellComplex->cocombine(2);
  }
  
  _cellComplex->emptyTrash();
  
  _cellComplex->checkCoherence();
  double t2 = Cpu();
  Msg::Info("Cell Complex reduction complete (%g s).", t2 - t1);
  Msg::Info("%d volumes, %d faces, %d edges and %d vertices.",
            _cellComplex->getSize(3), _cellComplex->getSize(2), _cellComplex->getSize(1), _cellComplex->getSize(0));
 
  
  
  _cellComplex->writeComplexMSH(fileName);
  
  Msg::Info("Computing homology groups...");
  t1 = Cpu();
  ChainComplex* chains = new ChainComplex(_cellComplex);
  chains->transposeHMatrices();
  chains->computeHomology(true);
  t2 = Cpu();
  Msg::Info("Homology Computation complete (%g s).", t2- t1);
  
  int dim = _cellComplex->getDim();
 
  
  
  int HRank[4];
  for(int i = 0; i < 4; i++) HRank[i] = 0;
  for(int j = 3; j > -1; j--){
    std::string dimension;
    convert(dim-j, dimension);

    for(int i = 1; i <= chains->getBasisSize(j); i++){
      
      std::string generator;
      convert(i, generator);
      
      std::string name = dimension + "D Dual generator " + generator;
      Chain* chain = new Chain(_cellComplex->getCells(j), chains->getCoeffVector(j,i), _cellComplex, name, chains->getTorsion(j,i));
      chain->writeChainMSH(fileName);
      if(chain->getSize() != 0){
        HRank[dim-j] = HRank[dim-j] + 1;
        if(chain->getTorsion() != 1) Msg::Warning("%dD Dual generator %d has torsion coefficient %d!", j, i, chain->getTorsion());
      }
      delete chain;
            
    }
    
    
    if(j == 0 && _cellComplex->getNumOmitted() > 0){
      for(int i = 0; i < _cellComplex->getNumOmitted(); i++){
        std::string generator;
        convert(i+1, generator);
        std::string name = dimension + "D Dual generator " + generator;
        std::vector<int> coeffs (_cellComplex->getOmitted(i).size(),1);
        Chain* chain = new Chain(_cellComplex->getOmitted(i), coeffs, _cellComplex, name, 1);
        chain->writeChainMSH(fileName);
        if(chain->getSize() != 0) HRank[dim-j] = HRank[dim-j] + 1;
        delete chain;
        
      }
    }
    
    
  }
   
  Msg::Info("Ranks of homology groups for dual cell complex:");
  Msg::Info("H0 = %d", HRank[0]);
  Msg::Info("H1 = %d", HRank[1]);
  Msg::Info("H2 = %d", HRank[2]);
  Msg::Info("H3 = %d", HRank[3]);
  if(omitted != 0) Msg::Info("The computation of %d highest dimension dual generators was omitted.", _omit);
  
  Msg::Info("Wrote results to %s.", fileName.c_str());
  printf("Wrote results to %s. \n", fileName.c_str());
  
  delete chains;
  
  printf("H0 = %d \n", HRank[0]);
  printf("H1 = %d \n", HRank[1]);
  printf("H2 = %d \n", HRank[2]);
  printf("H3 = %d \n", HRank[3]);
  
  return;
}

void Homology::computeBettiNumbers(){
  
  Msg::Info("Running coreduction...");
  double t1 = Cpu();
  _cellComplex->computeBettiNumbers();
  double t2 = Cpu();
  Msg::Info("Betti number computation complete (%g s).", t2- t1);

  Msg::Info("b0 = %d \n", _cellComplex->getBettiNumber(0));
  Msg::Info("b1 = %d \n", _cellComplex->getBettiNumber(1));
  Msg::Info("b2 = %d \n", _cellComplex->getBettiNumber(2));
  Msg::Info("b3 = %d \n", _cellComplex->getBettiNumber(3));
  
  return;
}
  
#endif
