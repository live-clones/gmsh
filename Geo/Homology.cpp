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
		   std::vector<int> physicalSubdomain, bool save0N,
		   bool combine, bool omit, bool smoothen) :
  _model(model), _domain(physicalDomain), _subdomain(physicalSubdomain),
  _save0N(save0N), _combine(combine), _omit(omit), _smoothen(smoothen)
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
  _maxdomain = 0;
  _maxnum = 0;
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
					      subdomainElements);

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

Homology::~Homology()
{
  for(std::map<int, Chain*>::iterator it = _basisChains.begin();
      it != _basisChains.end(); it++) delete it->second;
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
  int omitted = cellComplex->reduceComplex(_combine, _omit);

  double t2 = Cpu();
  Msg::StatusBar(2, true, "Done reducing cell complex (%g s)", t2 - t1);
  Msg::Info("%d volumes, %d faces, %d edges and %d vertices",
            cellComplex->getSize(3), cellComplex->getSize(2),
	    cellComplex->getSize(1), cellComplex->getSize(0));

  Msg::StatusBar(2, true, "Computing homology spaces...");
  t1 = Cpu();
  ChainComplex chains = ChainComplex(cellComplex);
  chains.computeHomology();
  t2 = Cpu();
  Msg::StatusBar(2, true, "Done computing homology spaces (%g s)", t2 - t1);

  int dim = cellComplex->getDim();

  int HRank[4];
  for(int j = 0; j < 4; j++){
    HRank[j] = 0;
    std::string dimension = "";
    convert(j, dimension);
    for(int i = 1; i <= chains.getBasisSize(j, 3); i++){

      std::string generator = "";
      convert(i, generator);

      std::string name = "H" + dimension + domainString + generator;
      std::map<Cell*, int, Less_Cell> protoChain;
      chains.getBasisChain(protoChain, i, j, 3, _smoothen);
      Chain* chain = new Chain(protoChain, cellComplex, ++_maxdomain, name,
			       chains.getTorsion(j,i));
      if(chain->getSize() == 0) {
	delete chain;
	_maxdomain--;
	continue;
      }
      HRank[j] = HRank[j] + 1;
      if(chain->getTorsion() != 1){
	Msg::Warning("H%d %d has torsion coefficient %d!",
		     j, i, chain->getTorsion());
      }
      // FIXME: Cell* and CellComplex* pointers should not outlive
      // the objects, don't store Chains containing them for now
      //_basisChains[chain->createPGroup()] = chain;
      if(!_save0N && (j != 0 && j != dim)) chain->createPGroup();
      delete chain;
    }
  }

  if(_fileName != "") writeGeneratorsMSH();

  if(ownComplex) delete cellComplex;

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
  int omitted = cellComplex->coreduceComplex(_combine, _omit);
  double t2 = Cpu();

  Msg::StatusBar(2, true, "Done reducing cell complex (%g s)", t2 - t1);
  Msg::Info("%d volumes, %d faces, %d edges and %d vertices",
            cellComplex->getSize(3), cellComplex->getSize(2),
	    cellComplex->getSize(1), cellComplex->getSize(0));

  Msg::StatusBar(2, true, "Computing homology spaces...");
  t1 = Cpu();
  ChainComplex chains = ChainComplex(cellComplex);
  chains.transposeHMatrices();
  chains.computeHomology(true);
  t2 = Cpu();
  Msg::StatusBar(2, true, "Done computing homology spaces (%g s)", t2- t1);

  int dim = cellComplex->getDim();

  int HRank[4];
  for(int i = 0; i < 4; i++) HRank[i] = 0;
  for(int j = 3; j > -1; j--){
    std::string dimension = "";
    convert(dim-j, dimension);

    for(int i = 1; i <= chains.getBasisSize(j, 3); i++){

      std::string generator = "";
      convert(i, generator);

      std::string name = "H" + dimension + "*" +
	getDomainString(_domain, _subdomain) + generator;
      std::map<Cell*, int, Less_Cell> protoChain;
      chains.getBasisChain(protoChain, i, j, 3, _smoothen);
      Chain* chain = new Chain(protoChain, cellComplex, ++_maxdomain, name,
			       chains.getTorsion(j,i));
      if(chain->getSize() == 0) {
	delete chain;
	--_maxdomain;
	continue;
      }

      HRank[dim-j] = HRank[dim-j] + 1;
      if(chain->getTorsion() != 1){
	Msg::Warning("H%d* %d has torsion coefficient %d!",
		     dim-j, i, chain->getTorsion());
      }
      // FIXME: Cell* and CellComplex* pointers should not outlive
      // the objects, don't store Chains containing them for now
      //_basisChains[chain->createPGroup()] = chain;
      if(!_save0N && (j != 0 && j != dim)) chain->createPGroup();
      delete chain;
    }
  }

  if(_fileName != "") writeGeneratorsMSH();

  if(ownComplex) delete cellComplex;

  Msg::Info("Ranks of homology spaces for the dual cell complex:");
  Msg::Info("H0* = %d", HRank[0]);
  Msg::Info("H1* = %d", HRank[1]);
  Msg::Info("H2* = %d", HRank[2]);
  Msg::Info("H3* = %d", HRank[3]);
  if(omitted != 0) Msg::Info("The computation of %d highest dimension dual generators was omitted", omitted);

  Msg::StatusBar(2, false, "H0*: %d, H1*: %d, H2*: %d, H3*: %d",
		 HRank[0], HRank[1], HRank[2], HRank[3]);
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
    fprintf(fp, "%d %d \n", cell->getIndex(), coeff );
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
    std::vector<MVertex*> v;
    cell->getMeshVertices(v);

    MElement* e = factory.create(cell->getTypeMSH(), v);
    if(cell->getDim() > 0 && coeff < 0) e->revert(); // flip orientation
    elements.push_back(e);

    // if cell coefficient is other than -1 or 1, add multiple
    // identical MElements to the physical group
    for(int i = 1; i < abs(coeff); i++) {
      MElement* ecopy = factory.create(cell->getTypeMSH(), v);
      if(cell->getDim() > 0 && coeff < 0) ecopy->revert();
      elements.push_back(ecopy);
    }

    std::vector<double> coeffs (1,abs(coeff));
    data[e->getNum()] = coeffs;
  }

  int max[4];
  for(int i = 0; i < 4; i++)
    max[i] = this->getCellComplex()->getModel()->getMaxElementaryNumber(i);
  int entityNum = *std::max_element(max,max+4) + 1;
  for(int i = 0; i < 4; i++)
    max[i] = this->getCellComplex()->getModel()->getMaxPhysicalNumber(i);
  int physicalNum = *std::max_element(max,max+4) + 1;
  setNum(physicalNum);

  std::map<int, std::vector<MElement*> > entityMap;
  entityMap[entityNum] = elements;
  std::map<int, std::map<int, std::string> > physicalMap;
  std::map<int, std::string> physicalInfo;
  physicalInfo[physicalNum] = getName();
  physicalMap[entityNum] = physicalInfo;

  if(!data.empty()){
    GModel* m = this->getCellComplex()->getModel();
    m->storeChain(getDim(), entityMap, physicalMap);
    m->setPhysicalName(getName(), getDim(), physicalNum);

#if defined(HAVE_POST)
    // create PView for instant visualization
    std::string pnum = "";
    convert(physicalNum, pnum);
    std::string postname = pnum + ": " + getName();
    PView* view = new PView(postname, "ElementData", m, data, 0, 1);
    // the user should be interested about the orientations
    int size = 30;
    PViewOptions* opt = view->getOptions();
    if(opt->tangents == 0) opt->tangents = size;
    if(opt->normals == 0) opt->normals = size;
    view->setOptions(opt);
#endif
  }

  return physicalNum;
}


Chain::Chain(std::map<Cell*, int, Less_Cell>& chain,
	     CellComplex* cellComplex, int num,
	     std::string name, int torsion)
{
  _cells = chain;
  if(!_cells.empty()) _dim = firstCell()->first->getDim();
  else _dim = 0;
  _name = name;
  _num = num;
  _cellComplex = cellComplex;
  _torsion = torsion;
  eraseNullCells();
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

#endif

