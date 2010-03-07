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
  _fileName = "";

  // default to the whole model
  if(_domain.empty()){
    int dim = _model->getDim();
    std::vector<GEntity*> entities;
    _model->getEntities(entities);
    for(std::vector<GEntity*>::iterator it = entities.begin();
        it != entities.end(); it++){
      if((*it)->dim() == dim) _domainEntities.push_back(*it);
    }
  }

  std::map<int, std::vector<GEntity*> > groups[4];
  model->getPhysicalGroups(groups);
  std::map<int, std::vector<GEntity*> >::iterator it;
  
  for(unsigned int i = 0; i < _domain.size(); i++){
    for(int j = 0; j < 4; j++){
      it = groups[j].find(_domain.at(i));
      if(it != groups[j].end()){
	std::vector<GEntity*> physicalGroup = (*it).second;
	for(unsigned int k = 0; k < physicalGroup.size(); k++){
	  _domainEntities.push_back(physicalGroup.at(k));
	}
      }
    }
  }
  for(unsigned int i = 0; i < _subdomain.size(); i++){           
    for(int j = 0; j < 4; j++){
      it = groups[j].find(_subdomain.at(i));
      if(it != groups[j].end()){
	std::vector<GEntity*> physicalGroup = (*it).second;
	for(unsigned int k = 0; k < physicalGroup.size(); k++){
	  _subdomainEntities.push_back(physicalGroup.at(k));
	}	  
      }
    }
  }
  
}

CellComplex* Homology::createCellComplex(std::vector<GEntity*>& domainEntities,
			    std::vector<GEntity*>& subdomainEntities){
  Msg::Info("Creating a Cell Complex...");
  Msg::StatusBar(1, false, "Cell Complex...");
  Msg::StatusBar(2, false, "");
  double t1 = Cpu();

  
  if(domainEntities.empty()) Msg::Error("Domain is empty.");
  if(subdomainEntities.empty()) Msg::Info("Subdomain is empty.");
  
  CellComplex* cellComplex =  new CellComplex(domainEntities, 
					      subdomainEntities);

  if(cellComplex->getSize(0) == 0){ 
    Msg::Error("Cell Complex is empty!");
    Msg::Error("Check the domain & the mesh.");
  }
  double t2 = Cpu();
  Msg::Info("Cell Complex complete (%g s).", t2 - t1);
  Msg::Info("%d volumes, %d faces, %d edges and %d vertices.",
            cellComplex->getSize(3), cellComplex->getSize(2), 
	    cellComplex->getSize(1), cellComplex->getSize(0));
  Msg::StatusBar(2, false, "%d V, %d F, %d E, %d V.",
		 cellComplex->getSize(3), cellComplex->getSize(2), 
		 cellComplex->getSize(1), cellComplex->getSize(0));
  return cellComplex;
}

Homology::~Homology()
{ 
  
}

void Homology::findGenerators(CellComplex* cellComplex, bool omit, 
			      std::string domainString)
{
  bool newComplex = false;
  if(cellComplex == NULL){
    cellComplex = createCellComplex(_domainEntities, _subdomainEntities);
    newComplex = true;
  }
  if(domainString == ""){
    domainString = getDomainString(_domain, _subdomain);
  }

  Msg::Info("Reducing the Cell Complex...");
  Msg::StatusBar(1, false, "Reducing...");
  double t1 = Cpu();

  printf("Cell Complex: \n %d volumes, %d faces, %d edges and %d vertices. \n",
	 cellComplex->getSize(3), cellComplex->getSize(2),
	 cellComplex->getSize(1), cellComplex->getSize(0));

  int omitted = cellComplex->reduceComplex(omit);

  printf(" %d volumes, %d faces, %d edges and %d vertices. \n",
         cellComplex->getSize(3), cellComplex->getSize(2),
         cellComplex->getSize(1), cellComplex->getSize(0));

  cellComplex->combine(3);
  cellComplex->reduction(2);
  cellComplex->combine(2);
  cellComplex->reduction(1);
  cellComplex->combine(1);

  printf(" %d volumes, %d faces, %d edges and %d vertices. \n",
	 cellComplex->getSize(3), cellComplex->getSize(2),
	 cellComplex->getSize(1), cellComplex->getSize(0));
  
  cellComplex->checkCoherence();
  
  double t2 = Cpu();
  Msg::Info("Cell Complex reduction complete (%g s).", t2 - t1);
  Msg::Info("%d volumes, %d faces, %d edges and %d vertices.",
            cellComplex->getSize(3), cellComplex->getSize(2), 
	    cellComplex->getSize(1), cellComplex->getSize(0));
  Msg::StatusBar(2, false, "%d V, %d F, %d E, %d N.",
		 cellComplex->getSize(3), cellComplex->getSize(2), 
		 cellComplex->getSize(1), cellComplex->getSize(0));
  
  Msg::Info("Computing homology spaces...");
  Msg::StatusBar(1, false, "Computing...");
  t1 = Cpu();
  ChainComplex* chains = new ChainComplex(cellComplex);
  chains->computeHomology();
  t2 = Cpu();
  Msg::Info("Homology Computation complete (%g s).", t2 - t1);
  
  int HRank[4];
  for(int j = 0; j < 4; j++){
    HRank[j] = 0;
    std::string dimension = "";
    convert(j, dimension);
    for(int i = 1; i <= chains->getBasisSize(j); i++){
      
      std::string generator = "";
      convert(i, generator);
      
      std::string name = "H" + dimension + domainString + generator;
      std::set<Cell*, Less_Cell> cells;
      cellComplex->getCells(cells, j);
      Chain* chain = new Chain(cells, 
			       chains->getCoeffVector(j,i), 
			       cellComplex, _model, name, 
			       chains->getTorsion(j,i));
      t1 = Cpu();
      int start = chain->getSize();
      //chain->smoothenChain();
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
      _generators[chain->createPGroup()] = chain;
    }
    if(j == cellComplex->getDim() && cellComplex->getNumOmitted() > 0){
      for(int i = 0; i < cellComplex->getNumOmitted(); i++){
        std::string generator;
        convert(i+1, generator);
        std::string name = "H" + dimension + domainString + generator;
        std::vector<int> coeffs (cellComplex->getOmitted(i).size(),1);
        Chain* chain = new Chain(cellComplex->getOmitted(i), coeffs, 
				 cellComplex, _model, name, 1);
        if(chain->getSize() != 0) HRank[j] = HRank[j] + 1;
	_generators[chain->createPGroup()] = chain;
      }
    }
  }
  
  if(_fileName != "") writeGeneratorsMSH();
  
  if(newComplex) delete cellComplex;
  delete chains;
  
  Msg::Info("Ranks of homology spaces for primal cell complex:");
  Msg::Info("H0 = %d", HRank[0]);
  Msg::Info("H1 = %d", HRank[1]);
  Msg::Info("H2 = %d", HRank[2]);
  Msg::Info("H3 = %d", HRank[3]);
  if(omitted != 0) Msg::Info("The computation of generators in the highest dimension was omitted.");
  
  Msg::StatusBar(1, false, "Homology");
  Msg::StatusBar(2, false, "H0: %d, H1: %d, H2: %d, H3: %d.", 
		 HRank[0], HRank[1], HRank[2], HRank[3]);
}

void Homology::findDualGenerators()
{ 
  CellComplex* cellComplex = createCellComplex(_domainEntities, 
					       _subdomainEntities);

  Msg::Info("Reducing Cell Complex...");
  Msg::StatusBar(1, false, "Reducing...");
  double t1 = Cpu();
  int omitted = cellComplex->coreduceComplex();
  
  cellComplex->cocombine(0);
  cellComplex->coreduction(1);
  cellComplex->cocombine(1);
  cellComplex->coreduction(2);
  cellComplex->cocombine(2);
  cellComplex->coreduction(3);
  cellComplex->checkCoherence();
  double t2 = Cpu();
  Msg::Info("Cell Complex reduction complete (%g s).", t2 - t1);
  Msg::Info("%d volumes, %d faces, %d edges and %d vertices.",
            cellComplex->getSize(3), cellComplex->getSize(2), 
	    cellComplex->getSize(1), cellComplex->getSize(0));
  Msg::StatusBar(2, false, "%d V, %d F, %d E, %d N.",
		 cellComplex->getSize(3), cellComplex->getSize(2), 
		 cellComplex->getSize(1), cellComplex->getSize(0));
   
  Msg::Info("Computing homology spaces...");
  Msg::StatusBar(1, false, "Computing...");
  t1 = Cpu();
  ChainComplex* chains = new ChainComplex(cellComplex);
  chains->transposeHMatrices();
  chains->computeHomology(true);
  t2 = Cpu();
  Msg::Info("Homology Computation complete (%g s).", t2- t1);
  
  int dim = cellComplex->getDim();
   
  int HRank[4];
  for(int i = 0; i < 4; i++) HRank[i] = 0;
  for(int j = 3; j > -1; j--){
    std::string dimension = "";
    convert(dim-j, dimension);

    for(int i = 1; i <= chains->getBasisSize(j); i++){
      
      std::string generator = "";
      convert(i, generator);
      
      std::string name = "H" + dimension + "*" + 
	getDomainString(_domain, _subdomain) + generator;
      std::set<Cell*, Less_Cell> cells;
      cellComplex->getCells(cells, j);
      Chain* chain = new Chain(cells, 
			       chains->getCoeffVector(j,i), cellComplex, 
			       _model, name, chains->getTorsion(j,i));
      _generators[chain->createPGroup()] = chain;
      if(chain->getSize() != 0){
        HRank[dim-j] = HRank[dim-j] + 1;
        if(chain->getTorsion() != 1){ 
	  Msg::Warning("H%d* %d has torsion coefficient %d!", 
		       dim-j, i, chain->getTorsion());
	}
      }     
    }
    
    
    if(j == 0 && cellComplex->getNumOmitted() > 0){
      for(int i = 0; i < cellComplex->getNumOmitted(); i++){
        std::string generator;
        convert(i+1, generator);
        std::string name 
	  = "H" + dimension + "*" + 
	  getDomainString(_domain, _subdomain) + generator;
        std::vector<int> coeffs (cellComplex->getOmitted(i).size(),1);
        Chain* chain = new Chain(cellComplex->getOmitted(i), coeffs, 
				 cellComplex, _model, name, 1);
	_generators[chain->createPGroup()] = chain;
        if(chain->getSize() != 0) HRank[dim-j] = HRank[dim-j] + 1;
      }
    }
  }

  if(_fileName != "") writeGeneratorsMSH();

  delete cellComplex;
  delete chains;
  
  Msg::Info("Ranks of homology spaces for the dual cell complex:");
  Msg::Info("H0* = %d", HRank[0]);
  Msg::Info("H1* = %d", HRank[1]);
  Msg::Info("H2* = %d", HRank[2]);
  Msg::Info("H3* = %d", HRank[3]);
  if(omitted != 0) Msg::Info("The computation of %d highest dimension dual generators was omitted.", omitted);
  
  Msg::StatusBar(1, false, "Homology");
  Msg::StatusBar(2, false, "H0*: %d, H1*: %d, H2*: %d, H3*: %d.", 
		 HRank[0], HRank[1], HRank[2], HRank[3]);
}

void Homology::computeBettiNumbers()
{  
  CellComplex* cellComplex = createCellComplex(_domainEntities, 
					       _subdomainEntities);
  
  Msg::Info("Running coreduction...");
  Msg::StatusBar(1, false, "Computing...");
  double t1 = Cpu();
  cellComplex->computeBettiNumbers();
  double t2 = Cpu();
  Msg::Info("Betti number computation complete (%g s).", t2- t1);

  Msg::Info("H0 = %d", cellComplex->getBettiNumber(0));
  Msg::Info("H1 = %d", cellComplex->getBettiNumber(1));
  Msg::Info("H2 = %d", cellComplex->getBettiNumber(2));
  Msg::Info("H3 = %d", cellComplex->getBettiNumber(3));

  Msg::StatusBar(1, false, "Homology");
  Msg::StatusBar(2, false, "H0: %d, H1: %d, H2: %d, H3: %d.", 
		 cellComplex->getBettiNumber(0), 
		 cellComplex->getBettiNumber(1), 
		 cellComplex->getBettiNumber(2), 
		 cellComplex->getBettiNumber(3));
  
  if(_fileName != "") cellComplex->writeBettiNumbers(_fileName);  
  delete cellComplex;
}

void Homology::findHomSequence(){

  CellComplex* cellComplex = new CellComplex(_domainEntities, 
					     _subdomainEntities);
  Msg::Info("Reducing the Cell Complex...");
  Msg::StatusBar(1, false, "Reducing...");
  double t1 = Cpu();

  printf("Cell Complex: \n %d volumes, %d faces, %d edges and %d vertices. \n",
	 cellComplex->getSize(3), cellComplex->getSize(2),
	 cellComplex->getSize(1), cellComplex->getSize(0));

  cellComplex->reduceComplex(false);

  printf(" %d volumes, %d faces, %d edges and %d vertices. \n",
         cellComplex->getSize(3), cellComplex->getSize(2),
         cellComplex->getSize(1), cellComplex->getSize(0));

  cellComplex->combine(3);
  cellComplex->reduction(2);
  cellComplex->combine(2);
  cellComplex->reduction(1);
  cellComplex->combine(1);

  cellComplex->storeCells(1);

  printf(" %d volumes, %d faces, %d edges and %d vertices. \n",
	 cellComplex->getSize(3), cellComplex->getSize(2),
	 cellComplex->getSize(1), cellComplex->getSize(0));
  
  cellComplex->checkCoherence();
  
  double t2 = Cpu();
  Msg::Info("Cell Complex reduction complete (%g s).", t2 - t1);
  Msg::Info("%d volumes, %d faces, %d edges and %d vertices.",
            cellComplex->getSize(3), cellComplex->getSize(2), 
	    cellComplex->getSize(1), cellComplex->getSize(0));
  Msg::StatusBar(2, false, "%d V, %d F, %d E, %d N.",
		 cellComplex->getSize(3), cellComplex->getSize(2), 
		 cellComplex->getSize(1), cellComplex->getSize(0));
  
  Msg::Info("Computing homology spaces...");
  Msg::StatusBar(1, false, "Computing...");
  t1 = Cpu();
  
  for(int task = 0; task < 3; task++){
    ChainComplex* chains = new ChainComplex(cellComplex, task);
    std::string domainString = "";
    std::vector<int> empty;
    if(task == 0) domainString = getDomainString(_domain, _subdomain);
    else if(task == 1) domainString = getDomainString(_domain, empty);
    else if(task == 2) domainString = getDomainString(_subdomain, empty);
    chains->computeHomology();
    t2 = Cpu();
    Msg::Info("Homology Computation complete (%g s).", t2 - t1);
    
    int HRank[4];
    for(int j = 0; j < 4; j++){
      HRank[j] = 0;
      std::string dimension = "";
      convert(j, dimension);
      for(int i = 1; i <= chains->getBasisSize(j); i++){
	
	std::string generator = "";
	convert(i, generator);
      
	std::string name = "H" + dimension + domainString + generator;
	std::set<Cell*, Less_Cell> cells;
	cellComplex->getCells(cells, j, task);
	Chain* chain = new Chain(cells, 
				 chains->getCoeffVector(j,i), 
				 cellComplex, _model, name, 
				 chains->getTorsion(j,i));
	t1 = Cpu();
	int start = chain->getSize();
	//chain->smoothenChain();
	t2 = Cpu();
	//Msg::Info("Smoothened H%d %d from %d cells to %d cells (%g s).", 
	//	  j, i, start, chain->getSize(), t2 - t1);
	if(chain->getSize() != 0) {
	  HRank[j] = HRank[j] + 1;
	  if(chain->getTorsion() != 1){
	  Msg::Warning("H%d %d has torsion coefficient %d!", 
		       j, i, chain->getTorsion());
	  }
	}
	_generators[chain->createPGroup()] = chain;
      }
      
    }
    if(task == 0){
      Msg::Info("Ranks of relative homology spaces:");
    }
    if(task == 1){
      Msg::Info("Ranks of absolute homology spaces:");
    }
    if(task == 2){
      Msg::Info("Ranks of absolute homology spaces of relative subdomain:");
    }
    Msg::Info("H0 = %d", HRank[0]);
    Msg::Info("H1 = %d", HRank[1]);
    Msg::Info("H2 = %d", HRank[2]);
    Msg::Info("H3 = %d", HRank[3]);

    Msg::StatusBar(1, false, "Homology");
    Msg::StatusBar(2, false, "H0: %d, H1: %d, H2: %d, H3: %d.",
		   HRank[0], HRank[1], HRank[2], HRank[3]);
    delete chains;
  }

  if(_fileName != "") writeGeneratorsMSH();
  delete cellComplex;  
}

/*void Homology::restoreHomology() 
{ 
  cellComplexy->restoreComplex();
  for(int i = 0; i < 4; i++) _generators[i].clear();
  }*/

std::string Homology::getDomainString(const std::vector<int>& domain,
				      const std::vector<int>& subdomain) 
{
  std::string domainString = "({";
  if(domain.empty()) domainString += "0";
  else{
    for(unsigned int i = 0; i < domain.size(); i++){
      std::string temp = "";
      convert(domain.at(i),temp);
      domainString += temp;
      if (domain.size()-1 > i){ 
	domainString += ", ";
      }
    }
  }
  domainString += "}";
  
  if(!subdomain.empty()){
    domainString += ", {";    
    for(unsigned int i = 0; i < subdomain.size(); i++){
      std::string temp = "";
      convert(subdomain.at(i),temp);
      domainString += temp;
      if (subdomain.size()-1 > i){
        domainString += ", ";
      }
    } 
    domainString += "}";
  }
  domainString += ") ";
  return domainString;
}

bool Homology::writeGeneratorsMSH(bool binary)
{
  if(_fileName.empty()) return false;
  if(!_model->writeMSH(_fileName, 2.0, binary)) return false;
  Msg::Info("Wrote homology computation results to %s.", _fileName.c_str());
  return true;
}

#endif
