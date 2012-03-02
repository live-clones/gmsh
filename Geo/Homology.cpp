// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributed by Matti Pellikka <matti.pellikka@tut.fi>.

#include "Homology.h"

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewOptions.h"
#endif

#if defined(HAVE_KBIPACK)

Homology::Homology(GModel* model, std::vector<int> physicalDomain,
		   std::vector<int> physicalSubdomain,
                   bool saveOrig,
		   bool combine, bool omit, bool smoothen) :
  _model(model), _domain(physicalDomain), _subdomain(physicalSubdomain),
  _saveOrig(saveOrig),
  _combine(combine), _omit(omit), _smoothen(smoothen)
{
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
                                         std::vector<GEntity*>& subdomainEntities)
{
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

  CellComplex* cellComplex =  new CellComplex(_model,
					      domainElements,
					      subdomainElements,
                                              _saveOrig);

  if(cellComplex->getSize(0) == 0){
    Msg::Error("Cell Complex is empty: check the domain and the mesh");
  }
  double t2 = Cpu();
  Msg::StatusBar(2, true, "Done creating cell complex (%g s)", t2 - t1);
  Msg::Info("%d volumes, %d faces, %d edges and %d vertices",
            cellComplex->getSize(3), cellComplex->getSize(2),
	    cellComplex->getSize(1), cellComplex->getSize(0));
  return cellComplex;
}

CellComplex* Homology::createCellComplex()
{
  return createCellComplex(_domainEntities, _subdomainEntities);
}

Homology::~Homology()
{
  for(unsigned int i = 0; i < _chains.size(); i++)
    delete _chains.at(i);
}

void Homology::findHomologyBasis(CellComplex* cellComplex)
{
  bool ownComplex = false;
  if(cellComplex==NULL){
    cellComplex = createCellComplex(_domainEntities,
				    _subdomainEntities);
    ownComplex = true;
  }

  Msg::StatusBar(2, true, "Reducing cell complex...");

  double t1 = Cpu();
  int omitted = cellComplex->reduceComplex(_combine, _omit);

  double t2 = Cpu();
  Msg::StatusBar(2, true, "Done reducing cell complex (%g s)", t2 - t1);
  Msg::Info("%d volumes, %d faces, %d edges and %d vertices",
            cellComplex->getSize(3), cellComplex->getSize(2),
	    cellComplex->getSize(1), cellComplex->getSize(0));

  Msg::StatusBar(2, true, "Computing homology space basis ...");
  t1 = Cpu();
  ChainComplex chainComplex = ChainComplex(cellComplex);
  chainComplex.computeHomology();
  t2 = Cpu();
  Msg::StatusBar(2, true, "Done computing homology space basis (%g s)", t2 - t1);

  int dim = cellComplex->getDim();
  std::string domain = _getDomainString(_domain, _subdomain);
  int HRank[4];
  for(int j = 0; j < 4; j++){
    HRank[j] = 0;
    std::string dimension = "";
    convert(j, dimension);
    for(int i = 1; i <= chainComplex.getBasisSize(j, 3); i++){

      std::string generator = "";
      convert(i, generator);

      std::string name = "H" + dimension + domain + generator;
      std::map<Cell*, int, Less_Cell> chain;
      chainComplex.getBasisChain(chain, i, j, 3, _smoothen);
      int torsion = chainComplex.getTorsion(j,i);
      if(!chain.empty()) {
        _createChain(chain, name);
        HRank[j] = HRank[j] + 1;
        if(torsion != 1){
          Msg::Warning("H%d %d has torsion coefficient %d!",
                       j, i, torsion);
        }
      }
    }
  }

  if(_fileName != "") writeBasisMSH();

  if(ownComplex) delete cellComplex;

  Msg::Info("Ranks of domain %shomology spaces:", domain.c_str());
  Msg::Info("H0 = %d", HRank[0]);
  Msg::Info("H1 = %d", HRank[1]);
  Msg::Info("H2 = %d", HRank[2]);
  Msg::Info("H3 = %d", HRank[3]);
  if(omitted != 0) Msg::Info("The computation of basis elements in the highest dimension was omitted");

  Msg::StatusBar(2, false, "H0: %d, H1: %d, H2: %d, H3: %d",
		 HRank[0], HRank[1], HRank[2], HRank[3]);
}

void Homology::findCohomologyBasis(CellComplex* cellComplex)
{
  bool ownComplex = false;
  if(cellComplex==NULL){
    cellComplex = createCellComplex(_domainEntities,
				    _subdomainEntities);
    ownComplex = true;
  }

  Msg::StatusBar(2, true, "Reducing cell complex...");

  double t1 = Cpu();
  int omitted = cellComplex->coreduceComplex(_combine, _omit);
  double t2 = Cpu();

  Msg::StatusBar(2, true, "Done reducing cell complex (%g s)", t2 - t1);
  Msg::Info("%d volumes, %d faces, %d edges and %d vertices",
            cellComplex->getSize(3), cellComplex->getSize(2),
	    cellComplex->getSize(1), cellComplex->getSize(0));

  Msg::StatusBar(2, true, "Computing cohomology space basis ...");
  t1 = Cpu();
  ChainComplex chainComplex = ChainComplex(cellComplex);
  chainComplex.transposeHMatrices();
  chainComplex.computeHomology(true);
  t2 = Cpu();
  Msg::StatusBar(2, true, "Done computing cohomology space basis (%g s)", t2- t1);

  int dim = cellComplex->getDim();
  std::string domain = _getDomainString(_domain, _subdomain);
  int HRank[4];
  for(int i = 0; i < 4; i++) HRank[i] = 0;
  for(int j = 3; j > -1; j--){
    std::string dimension = "";
    convert(j, dimension);

    for(int i = 1; i <= chainComplex.getBasisSize(j, 3); i++){

      std::string generator = "";
      convert(i, generator);

      std::string name = "H" + dimension + "*" +
	domain + generator;
      std::map<Cell*, int, Less_Cell> chain;
      chainComplex.getBasisChain(chain, i, j, 3, _smoothen);
      int torsion = chainComplex.getTorsion(j,i);
      if(!chain.empty()) {
        _createChain(chain, name);
        HRank[j] = HRank[j] + 1;
        if(torsion != 1){
          Msg::Warning("H%d* %d has torsion coefficient %d!", j, i, torsion);
        }
      }
    }
  }

  if(_fileName != "") writeBasisMSH();

  if(ownComplex) delete cellComplex;

  Msg::Info("Ranks of domain %scohomology spaces:", domain.c_str());
  Msg::Info("H0* = %d", HRank[0]);
  Msg::Info("H1* = %d", HRank[1]);
  Msg::Info("H2* = %d", HRank[2]);
  Msg::Info("H3* = %d", HRank[3]);
  if(omitted != 0) Msg::Info("The computation of basis elements in the highest dimension was omitted");

  Msg::StatusBar(2, false, "H0*: %d, H1*: %d, H2*: %d, H3*: %d",
		 HRank[0], HRank[1], HRank[2], HRank[3]);
}

void Homology::addChainsToModel(int dim, bool post)
{
  for(unsigned int i = 0; i < _chains.size(); i++) {
    if(dim != -1 && _chains.at(i)->getDim() == dim)
      _chains.at(i)->addToModel(this->getModel(), post);
    else if(dim == -1) _chains.at(i)->addToModel(this->getModel(), post);
  }
}

void Homology::_createChain(std::map<Cell*, int, Less_Cell>& preChain,
                            std::string name)
{
  Chain<int>* chain = new Chain<int>();
  chain->setName(name);

  for(citer cit = preChain.begin(); cit != preChain.end(); cit++){
    Cell* cell = cit->first;
    int coeff = cit->second;
    if(coeff == 0) continue;

    std::vector<MVertex*> v;
    cell->getMeshVertices(v);
    chain->addElemChain(ElemChain(cell->getDim(), v), coeff);
  }
  _chains.push_back(chain);
}

std::string Homology::_getDomainString(const std::vector<int>& domain,
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

bool Homology::writeBasisMSH(bool binary)
{
  if(_fileName.empty()) return false;
  if(!_model->writeMSH(_fileName, 2.0, binary)) return false;
  Msg::Info("Wrote homology computation results to %s", _fileName.c_str());
  return true;
}

void Homology::storeCells(CellComplex* cellComplex, int dim)
{
  std::vector<MElement*> elements;
  MElementFactory factory;

  for(CellComplex::citer cit = cellComplex->firstCell(dim);
      cit != cellComplex->lastCell(dim); cit++){
    Cell* cell = *cit;

    std::map<Cell*, int, Less_Cell > cells;
    cell->getCells(cells);
    for(Cell::citer it = cells.begin(); it != cells.end(); it++){
      Cell* subCell = it->first;

      std::vector<MVertex*> v;
      cell->getMeshVertices(v);

      MElement* e = factory.create(cell->getTypeMSH(), v);
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

#endif

