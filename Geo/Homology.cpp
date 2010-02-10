// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributed by Matti Pellikka <matti.pellikka@tut.fi>.
 

#include "Homology.h"
#include "ChainComplex.h"
#include "OS.h"

#if defined(HAVE_KBIPACK)

Homology::Homology(GModel* model, std::vector<int> physicalDomain, 
		   std::vector<int> physicalSubdomain)
{ 
  _model = model; 
  _domain = physicalDomain;
  _subdomain = physicalSubdomain;
  
  Msg::Info("Creating a Cell Complex...");
  Msg::StatusBar(1, false, "Cell Complex...");
  Msg::StatusBar(2, false, "");
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
            _cellComplex->getSize(3), _cellComplex->getSize(2), 
	    _cellComplex->getSize(1), _cellComplex->getSize(0));
  Msg::StatusBar(2, false, "%d V, %d F, %d E, %d V.",
		 _cellComplex->getSize(3), _cellComplex->getSize(2), 
		 _cellComplex->getSize(1), _cellComplex->getSize(0));          
  
}

Homology::~Homology(){ 
  delete _cellComplex; 
    for(int i = 0; i < 4; i++) {
      for(int j = 0; j < _generators[i].size(); j++){
        Chain* chain = _generators[i].at(j);
        //_model->deletePhysicalGroup(chain->getDim(), chain->getNum());
        delete chain;
    }
  }
}

void Homology::findGenerators(std::string fileName)
{
  Msg::Info("Reducing the Cell Complex...");
  Msg::StatusBar(1, false, "Reducing...");
  double t1 = Cpu();

  int omitted = _cellComplex->reduceComplex();
  
  _cellComplex->combine(3);
  _cellComplex->reduction(2);
  _cellComplex->combine(2);
  _cellComplex->reduction(1);
  _cellComplex->combine(1);
  
  _cellComplex->checkCoherence();
  
  double t2 = Cpu();
  Msg::Info("Cell Complex reduction complete (%g s).", t2 - t1);
  Msg::Info("%d volumes, %d faces, %d edges and %d vertices.",
            _cellComplex->getSize(3), _cellComplex->getSize(2), 
	    _cellComplex->getSize(1), _cellComplex->getSize(0));
  Msg::StatusBar(2, false, "%d V, %d F, %d E, %d N.",
		 _cellComplex->getSize(3), _cellComplex->getSize(2), 
		 _cellComplex->getSize(1), _cellComplex->getSize(0));
  
  Msg::Info("Computing homology spaces...");
  Msg::StatusBar(1, false, "Computing...");
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
      
      std::string name = "H" + dimension + getDomainString()  + generator;
      Chain* chain = new Chain(_cellComplex->getCells(j), 
			       chains->getCoeffVector(j,i), 
			       _cellComplex, _model, name, 
			       chains->getTorsion(j,i));
      t1 = Cpu();
      int start = chain->getSize();
      chain->smoothenChain();
      t2 = Cpu();
      Msg::Info("Smoothened H%d %d from %d cells to %d cells (%g s).", 
		j, i, start, chain->getSize(), t2 - t1);
      if(chain->getSize() != 0) {
        HRank[j] = HRank[j] + 1;
        if(chain->getTorsion() != 1){
	  Msg::Warning("H%d %d has torsion coefficient %d!", 
		       j, i, chain->getTorsion());
	}
      }
      _generators[j].push_back(chain);
    }
    if(j == _cellComplex->getDim() && _cellComplex->getNumOmitted() > 0){
      for(int i = 0; i < _cellComplex->getNumOmitted(); i++){
        std::string generator;
        convert(i+1, generator);
        std::string name = "H" + dimension + getDomainString() + generator;
        std::vector<int> coeffs (_cellComplex->getOmitted(i).size(),1);
        Chain* chain = new Chain(_cellComplex->getOmitted(i), coeffs, 
				 _cellComplex, _model, name, 1);
        if(chain->getSize() != 0) HRank[j] = HRank[j] + 1;
        _generators[j].push_back(chain);
      }
    }
  }
  
  createPViews();
  if(fileName != "") writeGeneratorsMSH(fileName);
  
  Msg::Info("Ranks of homology spaces for primal cell complex:");
  Msg::Info("H0 = %d", HRank[0]);
  Msg::Info("H1 = %d", HRank[1]);
  Msg::Info("H2 = %d", HRank[2]);
  Msg::Info("H3 = %d", HRank[3]);
  if(omitted != 0) Msg::Info("The computation of generators in the highest dimension was omitted.");
  
  delete chains;
  
  Msg::Debug("H0 = %d \n", HRank[0]);
  Msg::Debug("H1 = %d \n", HRank[1]);
  Msg::Debug("H2 = %d \n", HRank[2]);
  Msg::Debug("H3 = %d \n", HRank[3]);

  Msg::StatusBar(1, false, "Homology");
  Msg::StatusBar(2, false, "H0: %d, H1: %d, H2: %d, H3: %d.", 
		 HRank[0], HRank[1], HRank[2], HRank[3]);

  return;
}

void Homology::findDualGenerators(std::string fileName)
{ 
  Msg::Info("Reducing Cell Complex...");
  Msg::StatusBar(1, false, "Reducing...");
  double t1 = Cpu();
  int omitted = _cellComplex->coreduceComplex();
  
  _cellComplex->cocombine(0);
  _cellComplex->coreduction(1);
  _cellComplex->cocombine(1);
  _cellComplex->coreduction(2);
  _cellComplex->cocombine(2);
  _cellComplex->coreduction(3);
  
  _cellComplex->checkCoherence();
  double t2 = Cpu();
  Msg::Info("Cell Complex reduction complete (%g s).", t2 - t1);
  Msg::Info("%d volumes, %d faces, %d edges and %d vertices.",
            _cellComplex->getSize(3), _cellComplex->getSize(2), 
	    _cellComplex->getSize(1), _cellComplex->getSize(0));
  Msg::StatusBar(2, false, "%d V, %d F, %d E, %d N.",
		 _cellComplex->getSize(3), _cellComplex->getSize(2), 
		 _cellComplex->getSize(1), _cellComplex->getSize(0));
   
  Msg::Info("Computing homology spaces...");
  Msg::StatusBar(1, false, "Computing...");
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
      
      std::string name = "H" + dimension + "*" + getDomainString() + generator;
      Chain* chain = new Chain(_cellComplex->getCells(j), 
			       chains->getCoeffVector(j,i), _cellComplex, 
			       _model, name, chains->getTorsion(j,i));
      _generators[dim-j].push_back(chain);
      if(chain->getSize() != 0){
        HRank[dim-j] = HRank[dim-j] + 1;
        if(chain->getTorsion() != 1){ 
	  Msg::Warning("H%d* %d has torsion coefficient %d!", 
		       dim-j, i, chain->getTorsion());
	}
      }     
    }
    
    
    if(j == 0 && _cellComplex->getNumOmitted() > 0){
      for(int i = 0; i < _cellComplex->getNumOmitted(); i++){
        std::string generator;
        convert(i+1, generator);
        std::string name 
	  = "H" + dimension + "*" + getDomainString() + generator;
        std::vector<int> coeffs (_cellComplex->getOmitted(i).size(),1);
        Chain* chain = new Chain(_cellComplex->getOmitted(i), coeffs, 
				 _cellComplex, _model, name, 1);
        _generators[dim-j].push_back(chain);
        if(chain->getSize() != 0) HRank[dim-j] = HRank[dim-j] + 1;
      }
    }
    
    
  }
   
  createPViews();
  if(fileName != "") writeGeneratorsMSH(fileName);
  
  Msg::Info("Ranks of homology spaces for the dual cell complex:");
  Msg::Info("H0* = %d", HRank[0]);
  Msg::Info("H1* = %d", HRank[1]);
  Msg::Info("H2* = %d", HRank[2]);
  Msg::Info("H3* = %d", HRank[3]);
  if(omitted != 0) Msg::Info("The computation of %d highest dimension dual generators was omitted.", omitted);
  
  delete chains;
  
  Msg::Debug("H0* = %d \n", HRank[0]);
  Msg::Debug("H1* = %d \n", HRank[1]);
  Msg::Debug("H2* = %d \n", HRank[2]);
  Msg::Debug("H3* = %d \n", HRank[3]);

  Msg::StatusBar(1, false, "Homology");
  Msg::StatusBar(2, false, "H0*: %d, H1*: %d, H2*: %d, H3*: %d.", 
		 HRank[0], HRank[1], HRank[2], HRank[3]);

  return;
}

void Homology::computeBettiNumbers()
{  
  Msg::Info("Running coreduction...");
  Msg::StatusBar(1, false, "Computing...");
  double t1 = Cpu();
  _cellComplex->computeBettiNumbers();
  double t2 = Cpu();
  Msg::Info("Betti number computation complete (%g s).", t2- t1);

  Msg::Info("H0 = %d", _cellComplex->getBettiNumber(0));
  Msg::Info("H1 = %d", _cellComplex->getBettiNumber(1));
  Msg::Info("H2 = %d", _cellComplex->getBettiNumber(2));
  Msg::Info("H3 = %d", _cellComplex->getBettiNumber(3));

  Msg::StatusBar(1, false, "Homology");
  Msg::StatusBar(2, false, "H0: %d, H1: %d, H2: %d, H3: %d.", 
		 _cellComplex->getBettiNumber(0), 
		 _cellComplex->getBettiNumber(1), 
		 _cellComplex->getBettiNumber(2), 
		 _cellComplex->getBettiNumber(3));
  return;
}

void Homology::restoreHomology() 
{ 
  _cellComplex->restoreComplex();
  for(int i = 0; i < 4; i++) _generators[i].clear();
}

std::string Homology::getDomainString() 
{
  std::string domainString = "({";
  for(unsigned int i = 0; i < _domain.size(); i++){
    std::string temp = "";
    convert(_domain.at(i),temp);
    domainString += temp;
    if (_domain.size()-1 > i){ 
      domainString += ", ";
    }
  }
  domainString += "}";
  
  if(!_subdomain.empty()){
    domainString += ", {";
       
    for(unsigned int i = 0; i < _subdomain.size(); i++){
      std::string temp = "";
      convert(_subdomain.at(i),temp);
      domainString += temp;
      if (_subdomain.size()-1 > i){
        domainString += ", ";
      }
    } 
    domainString += "}";
    
  }
  domainString += ") ";
  return domainString;
}

void Homology::createPViews()
{
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < _generators[i].size(); j++){
      Chain* chain = _generators[i].at(j);
      chain->createPView();
    }
  }
}

bool Homology::writeGeneratorsMSH(std::string fileName, bool binary)
{
  if(!_model->writeMSH(fileName, 2.0, binary)) return false;
  Msg::Info("Wrote homology computation results to %s.", fileName.c_str());
  Msg::Debug("Wrote homology computation results to %s. \n", 
	     fileName.c_str());  
  return true;
}

#endif
