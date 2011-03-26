// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributed by Matti Pellikka <matti.pellikka@tut.fi>.
 
#include "Homology.h"

#if defined(HAVE_POST)
#include "PView.h"
#endif

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
  Msg::StatusBar(2, true, "Creating cell complex...");
  double t1 = Cpu();

  
  if(domainEntities.empty()) Msg::Error("Domain is empty");
  if(subdomainEntities.empty()) Msg::Info("Subdomain is empty");
  
  std::vector<MElement*> domainElements;
  std::vector<MElement*> subdomainElements;
  for(unsigned int j=0; j < domainEntities.size(); j++) {
    for(unsigned int i=0; i < domainEntities.at(j)->getNumMeshElements(); i++){
      MElement* element = domainEntities.at(j)->getMeshElement(i);
      domainElements.push_back(element);
    }
  }
  for(unsigned int j=0; j < subdomainEntities.size(); j++) {
    for(unsigned int i=0; i < subdomainEntities.at(j)->getNumMeshElements();
	i++){
      MElement* element = subdomainEntities.at(j)->getMeshElement(i);
      subdomainElements.push_back(element);
    }
  }

  CellComplex* cellComplex =  new CellComplex(domainElements, 
					      subdomainElements);

  if(cellComplex->getSize(0) == 0){ 
    Msg::Error("Cell Complex is empty!");
    Msg::Error("Check the domain & the mesh");
  }
  double t2 = Cpu();
  Msg::StatusBar(2, true, "Done creating cell complex (%g s)", t2 - t1);
  Msg::Info("%d volumes, %d faces, %d edges and %d vertices",
            cellComplex->getSize(3), cellComplex->getSize(2), 
	    cellComplex->getSize(1), cellComplex->getSize(0));
  return cellComplex;
}

Homology::~Homology()
{ 
  
}

void Homology::findGenerators(CellComplex* cellComplex)
{
  bool ownComplex = false;
  if(cellComplex==NULL){
    cellComplex = createCellComplex(_domainEntities, 
				    _subdomainEntities);
    ownComplex = true;
  }
  std::string domainString = getDomainString(_domain, _subdomain);

  Msg::StatusBar(2, true, "Reducing cell complex...");

  double t1 = Cpu();
  int omitted = cellComplex->reduceComplex();
  
  double t2 = Cpu();
  Msg::StatusBar(2, true, "Done reducing cell complex (%g s)", t2 - t1);
  Msg::Info("%d volumes, %d faces, %d edges and %d vertices",
            cellComplex->getSize(3), cellComplex->getSize(2), 
	    cellComplex->getSize(1), cellComplex->getSize(0));
  
  Msg::StatusBar(2, true, "Computing homology spaces...");
  t1 = Cpu();
  ChainComplex* chains = new ChainComplex(cellComplex);
  chains->computeHomology();
  t2 = Cpu();
  Msg::StatusBar(2, true, "Done computing homology spaces (%g s)", t2 - t1);
  
  int HRank[4];
  for(int j = 0; j < 4; j++){
    HRank[j] = 0;
    std::string dimension = "";
    convert(j, dimension);
    for(int i = 1; i <= chains->getBasisSize(j, 3); i++){
      
      std::string generator = "";
      convert(i, generator);
      
      std::string name = "H" + dimension + domainString + generator;
      std::map<Cell*, int, Less_Cell> protoChain;
      chains->getBasisChain(protoChain, i, j, 3, true);
      Chain* chain = new Chain(protoChain, cellComplex, _model, name, 
			       chains->getTorsion(j,i));      
      if(chain->getSize() == 0) {
	delete chain;
	continue;
      }
      HRank[j] = HRank[j] + 1;
      if(chain->getTorsion() != 1){
	Msg::Warning("H%d %d has torsion coefficient %d!", 
		     j, i, chain->getTorsion());
      }
      _generators.push_back(chain->createPGroup());
      delete chain;
    }
  }
  
  if(_fileName != "") writeGeneratorsMSH();
  
  if(ownComplex) delete cellComplex;
  delete chains;
  
  Msg::Info("Ranks of homology spaces for primal cell complex:");
  Msg::Info("H0 = %d", HRank[0]);
  Msg::Info("H1 = %d", HRank[1]);
  Msg::Info("H2 = %d", HRank[2]);
  Msg::Info("H3 = %d", HRank[3]);
  if(omitted != 0) Msg::Info("The computation of generators in the highest dimension was omitted");
  
  Msg::StatusBar(2, false, "H0: %d, H1: %d, H2: %d, H3: %d", 
		 HRank[0], HRank[1], HRank[2], HRank[3]);
}

void Homology::findDualGenerators(CellComplex* cellComplex)
{ 
  bool ownComplex = false;
  if(cellComplex==NULL){
    cellComplex = createCellComplex(_domainEntities, 
				    _subdomainEntities);
    ownComplex = true;
  }

  Msg::StatusBar(2, true, "Reducing cell complex...");
  
  double t1 = Cpu();
  int omitted = cellComplex->coreduceComplex();
  double t2 = Cpu();
  
  Msg::StatusBar(2, true, "Done reducing cell complex (%g s)", t2 - t1);
  Msg::Info("%d volumes, %d faces, %d edges and %d vertices",
            cellComplex->getSize(3), cellComplex->getSize(2), 
	    cellComplex->getSize(1), cellComplex->getSize(0));
   
  Msg::StatusBar(2, true, "Computing homology spaces...");
  t1 = Cpu();
  ChainComplex* chains = new ChainComplex(cellComplex);
  chains->transposeHMatrices();
  chains->computeHomology(true);
  t2 = Cpu();
  Msg::StatusBar(2, true, "Done computing homology spaces (%g s)", t2- t1);
  
  int dim = cellComplex->getDim();
 
  int HRank[4];
  for(int i = 0; i < 4; i++) HRank[i] = 0;
  for(int j = 3; j > -1; j--){
    std::string dimension = "";
    convert(dim-j, dimension);

    for(int i = 1; i <= chains->getBasisSize(j, 3); i++){
      
      std::string generator = "";
      convert(i, generator);
      
      std::string name = "H" + dimension + "*" + 
	getDomainString(_domain, _subdomain) + generator;
      std::map<Cell*, int, Less_Cell> protoChain;
      chains->getBasisChain(protoChain, i, j, 3);
      Chain* chain = new Chain(protoChain, cellComplex, _model, name, 
			       chains->getTorsion(j,i));
      if(chain->getSize() == 0) {
	delete chain;
	continue;
      }
      _generators.push_back(chain->createPGroup());
      HRank[dim-j] = HRank[dim-j] + 1;
      if(chain->getTorsion() != 1){ 
	Msg::Warning("H%d* %d has torsion coefficient %d!", 
		     dim-j, i, chain->getTorsion());
      }     
    }
  }

  if(_fileName != "") writeGeneratorsMSH();

  if(ownComplex) delete cellComplex;
  delete chains;
  
  Msg::Info("Ranks of homology spaces for the dual cell complex:");
  Msg::Info("H0* = %d", HRank[0]);
  Msg::Info("H1* = %d", HRank[1]);
  Msg::Info("H2* = %d", HRank[2]);
  Msg::Info("H3* = %d", HRank[3]);
  if(omitted != 0) Msg::Info("The computation of %d highest dimension dual generators was omitted", omitted);
  
  Msg::StatusBar(2, false, "H0*: %d, H1*: %d, H2*: %d, H3*: %d", 
		 HRank[0], HRank[1], HRank[2], HRank[3]);
}

void Homology::findHomSequence(){
  CellComplex* cellComplex = createCellComplex(_domainEntities, 
					       _subdomainEntities);
  Msg::StatusBar(2, true, "Reducing cell complex...");

  double t1 = Cpu();
  cellComplex->reduceComplex();
  double t2 = Cpu();

  Msg::StatusBar(2, true, "Done reducing cell complex (%g s)", t2 - t1);
  Msg::Info("%d volumes, %d faces, %d edges and %d vertices",
            cellComplex->getSize(3), cellComplex->getSize(2), 
	    cellComplex->getSize(1), cellComplex->getSize(0));
  
  Msg::StatusBar(2, true, "Computing homology spaces...");
  t1 = Cpu();
  
  ChainComplex* subcomplex = new ChainComplex(cellComplex, 2);
  ChainComplex* complex = new ChainComplex(cellComplex, 1);
  ChainComplex* relcomplex = new ChainComplex(cellComplex, 0);

  subcomplex->computeHomology();
  complex->computeHomology();
  relcomplex->computeHomology();  

  t2 = Cpu();
  Msg::StatusBar(2, true, "Done compuring homology spaces (%g s)", t2 - t1);

  Msg::StatusBar(2, true, "Computing homology sequence...");
  HomologySequence* seq = new HomologySequence(subcomplex, 
					       complex, relcomplex);
  t1 = Cpu();
  Msg::StatusBar(2, true, "Done computing homology sequence (%g s)", t1 - t2);
  
  for(int task = 0; task < 3; task++){
    ChainComplex* chains;

    std::string domainString = "";
    std::vector<int> empty;
    if(task == 0) {
      chains = subcomplex;
      domainString = getDomainString(_subdomain, empty);
    }
    else if(task == 1) {
      chains = complex;
      domainString = getDomainString(_domain, empty);
    }
    else{
      chains = relcomplex;
      domainString = getDomainString(_domain, _subdomain);
    }
    
    int HRank[4];
    for(int j = 0; j < 4; j++){
      HRank[j] = 0;
      std::string dimension = "";
      convert(j, dimension);
      for(int i = 1; i <= chains->getBasisSize(j, 3); i++){
	
	std::string generator = "";
	convert(i, generator);
      
	std::string name = "H" + dimension + domainString + generator;
	std::map<Cell*, int, Less_Cell> protoChain;
	chains->getBasisChain(protoChain, i, j, 3, true);
	Chain* chain = new Chain(protoChain, cellComplex, _model, name, 
				 chains->getTorsion(j,i));
	if(chain->getSize() == 0) {
	  delete chain;
	  continue;
	}
	HRank[j] = HRank[j] + 1;
	if(chain->getTorsion() != 1){
	  Msg::Warning("H%d %d has torsion coefficient %d!", 
		       j, i, chain->getTorsion());
	}
	_generators.push_back(chain->createPGroup());
	delete chain;
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

    Msg::StatusBar(2, false, "H0: %d, H1: %d, H2: %d, H3: %d",
		   HRank[0], HRank[1], HRank[2], HRank[3]);
  }

  delete subcomplex;
  delete complex;
  delete relcomplex;

  if(_fileName != "") writeGeneratorsMSH();
  delete cellComplex;
  delete seq;
}

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
  Msg::Info("Wrote homology computation results to %s", _fileName.c_str());
  return true;
}
Chain::Chain(std::set<Cell*, Less_Cell> cells, std::vector<int> coeffs, 
	     CellComplex* cellComplex, GModel* model,
	     std::string name, int torsion)
{  
  int i = 0;
  for(std::set<Cell*, Less_Cell>::iterator cit = cells.begin();
      cit != cells.end(); cit++){
    Cell* cell = *cit;
    _dim = cell->getDim();
    if((int)coeffs.size() > i){
      if(coeffs.at(i) != 0){
        std::map<Cell*, int, Less_Cell > subCells;
	cell->getCells(subCells);
        for(Cell::citer it = subCells.begin(); it != subCells.end(); it++){
          Cell* subCell = (*it).first;
          int coeff = (*it).second;
          _cells.insert( std::make_pair(subCell, coeffs.at(i)*coeff));
        }
      }
      i++;
    }
    
  }
  _name = name;
  _cellComplex = cellComplex;
  _torsion = torsion;
  _model = model;
  
}

void Homology::storeCells(CellComplex* cellComplex, int dim)
{
  std::vector<MElement*> elements;

  for(CellComplex::citer cit = cellComplex->firstCell(dim); 
      cit != cellComplex->lastCell(dim); cit++){
    Cell* cell = *cit;
    
    std::map<Cell*, int, Less_Cell > cells;
    cell->getCells(cells);
    for(Cell::citer it = cells.begin(); it != cells.end(); it++){
      Cell* subCell = it->first;
      
      MElement* e = subCell->getImageMElement();
      subCell->setDeleteImage(false);
      elements.push_back(e);
    }
  }

  int max[4];
  for(int i = 0; i < 4; i++) max[i] = _model->getMaxElementaryNumber(i);
  int entityNum = *std::max_element(max,max+4) + 1;
  for(int i = 0; i < 4; i++) max[i] = _model->getMaxPhysicalNumber(i);
  int physicalNum = *std::max_element(max,max+4) + 1;

  std::map<int, std::vector<MElement*> > entityMap;
  entityMap[entityNum] = elements;
  std::map<int, std::map<int, std::string> > physicalMap;
  std::map<int, std::string> physicalInfo;
  physicalInfo[physicalNum]="Cell Complex";
  physicalMap[entityNum] = physicalInfo;

  _model->storeChain(dim, entityMap, physicalMap);
  _model->setPhysicalName("Cell Complex", dim, physicalNum);
}

Chain::Chain(std::map<Cell*, int, Less_Cell>& chain, 
	     CellComplex* cellComplex, GModel* model,
	     std::string name, int torsion)
{  
  _cells = chain;
  if(!_cells.empty()) _dim = firstCell()->first->getDim();
  else _dim = 0;
  _name = name;
  _cellComplex = cellComplex;
  _torsion = torsion;
  _model = model; 
  eraseNullCells();
}

int Chain::writeChainMSH(const std::string &name)
{  
  if(getSize() == 0) return 1;
  
  FILE *fp = fopen(name.c_str(), "a");
  if(!fp){
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }
 
  fprintf(fp, "\n$ElementData\n");
  
  fprintf(fp, "1 \n");
  fprintf(fp, "\"%s\" \n", getName().c_str());
  fprintf(fp, "1 \n");
  fprintf(fp, "0.0 \n");
  fprintf(fp, "4 \n");
  fprintf(fp, "0 \n");
  fprintf(fp, "1 \n");
  fprintf(fp, "%d \n", getSize());
  fprintf(fp, "0 \n");
  
  for(citer cit = _cells.begin(); cit != _cells.end(); cit++){
    Cell* cell = (*cit).first;
    int coeff = (*cit).second;
    fprintf(fp, "%d %d \n", cell->getImageMElement()->getNum(), coeff );
  }
  
  fprintf(fp, "$EndElementData\n");
  fclose(fp);
  
  return 1;
}

int Chain::createPGroup()
{  
  std::vector<MElement*> elements;
  std::map<int, std::vector<double> > data;
  MElementFactory factory;

  for(citer cit = _cells.begin(); cit != _cells.end(); cit++){
    Cell* cell = (*cit).first;
    int coeff = (*cit).second;

    MElement* e = cell->getImageMElement();
    std::vector<MVertex*> v;
    for(int i = 0; i < e->getNumVertices(); i++){
      v.push_back(e->getVertex(i));
    }
    MElement* ne = factory.create(e->getTypeForMSH(), v, 0, e->getPartition());
    
    if(cell->getDim() > 0 && coeff < 0) ne->revert(); // flip orientation
    for(int i = 0; i < abs(coeff); i++) elements.push_back(ne);    

    std::vector<double> coeffs (1,abs(coeff));
    data[ne->getNum()] = coeffs;
  }
  
  int max[4];
  for(int i = 0; i < 4; i++) max[i] = _model->getMaxElementaryNumber(i);
  int entityNum = *std::max_element(max,max+4) + 1;
  for(int i = 0; i < 4; i++) max[i] = _model->getMaxPhysicalNumber(i);
  int physicalNum = *std::max_element(max,max+4) + 1;
  setNum(physicalNum);
  
  std::map<int, std::vector<MElement*> > entityMap;
  entityMap[entityNum] = elements;
  std::map<int, std::map<int, std::string> > physicalMap;
  std::map<int, std::string> physicalInfo;
  physicalInfo[physicalNum]=getName();
  physicalMap[entityNum] = physicalInfo;
  
  // hide mesh
  /*opt_mesh_points(0, GMSH_SET, 0);
  opt_mesh_lines(0, GMSH_SET, 0);
  opt_mesh_triangles(0, GMSH_SET, 0);
  opt_mesh_quadrangles(0, GMSH_SET, 0);
  opt_mesh_tetrahedra(0, GMSH_SET, 0);
  opt_mesh_hexahedra(0, GMSH_SET, 0);
  opt_mesh_prisms(0, GMSH_SET, 0);
  opt_mesh_pyramids(0, GMSH_SET, 0);*/

  // show post-processing normals, tangents and element boundaries
  //opt_view_normals(0, GMSH_SET, 20);
  //opt_view_tangents(0, GMSH_SET, 20);
  //opt_view_show_element(0, GMSH_SET, 1);
  
  if(!data.empty()){
    _model->storeChain(getDim(), entityMap, physicalMap);
    _model->setPhysicalName(getName(), getDim(), physicalNum);
#if defined(HAVE_POST)    
    // create PView for visualization
    new PView(getName(), "ElementData", getGModel(), data, 0, 1);
#endif
  }
   
  return physicalNum;
}


void Chain::removeCell(Cell* cell) 
{
  citer it = _cells.find(cell);
  if(it != _cells.end()){
    (*it).second = 0;
  }
  return;
}

void Chain::addCell(Cell* cell, int coeff) 
{
  std::pair<citer,bool> insert = _cells.insert( std::make_pair( cell, coeff));
  if(!insert.second && (*insert.first).second == 0){
    (*insert.first).second = coeff; 
  }
  else if (!insert.second && (*insert.first).second != 0){
    Msg::Debug("Error: invalid chain smoothening add!");
  }
  return;
}

bool Chain::hasCell(Cell* c)
{
  citer it = _cells.find(c);
  if(it != _cells.end() && (*it).second != 0) return true;
  return false;
}
   
Cell* Chain::findCell(Cell* c)
{
  citer it = _cells.find(c);
  if(it != _cells.end() && (*it).second != 0) return (*it).first;
  return NULL;
}

int Chain::getCoeff(Cell* c)
{
  citer it = _cells.find(c);
  if(it != _cells.end()) return (*it).second;
  return 0;
}

void Chain::eraseNullCells()
{
  std::vector<Cell*> toRemove;
  for(citer cit = _cells.begin(); cit != _cells.end(); cit++){
    if(cit->second == 0) toRemove.push_back(cit->first);
  }
  for(unsigned int i = 0; i < toRemove.size(); i++) _cells.erase(toRemove[i]);
  return;
}

void Chain::deImmuneCells()
{
  for(citer cit = _cells.begin(); cit != _cells.end(); cit++){
    Cell* cell = (*cit).first;
    cell->setImmune(false);
  }
}

#endif

