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

Homology::Homology(GModel* model,
                   std::vector<int> physicalDomain,
		   std::vector<int> physicalSubdomain,
                   std::vector<int> physicalImdomain,
                   bool saveOrig,
		   int combine, bool omit, bool smoothen) :
  _model(model), _domain(physicalDomain), _subdomain(physicalSubdomain),
  _imdomain(physicalImdomain), _saveOrig(saveOrig),
  _combine(combine), _omit(omit), _smoothen(smoothen), _cellComplex(NULL)
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
  else {
    _getEntities(_domain, _domainEntities);
    _getEntities(_subdomain, _subdomainEntities);
    _getEntities(_nondomain, _nondomainEntities);
    _getEntities(_nonsubdomain, _nonsubdomainEntities);
    _getEntities(_imdomain, _immuneEntities);
  }

  for(unsigned int i = 0; i < 4; i++) {
    _homologyComputed[i] = false;
    _cohomologyComputed[i] = false;
    _betti[i] = -1;
  }
}

void Homology::_getEntities(const std::vector<int>& physicalGroups,
                            std::vector<GEntity*>& entities)
{
  entities.clear();
  std::map<int, std::vector<GEntity*> > groups[4];
  _model->getPhysicalGroups(groups);
  std::map<int, std::vector<GEntity*> >::iterator it;

  for(unsigned int i = 0; i < physicalGroups.size(); i++){
    for(int j = 0; j < 4; j++){
      it = groups[j].find(physicalGroups.at(i));
      if(it != groups[j].end()){
	std::vector<GEntity*> physicalGroup = (*it).second;
	for(unsigned int k = 0; k < physicalGroup.size(); k++){
	  entities.push_back(physicalGroup.at(k));
	}
      }
    }
  }
}

void Homology::_getElements(const std::vector<GEntity*>& entities,
                            std::vector<MElement*>& elements)
{
  elements.clear();
  for(unsigned int j=0; j < entities.size(); j++) {
    for(unsigned int i=0; i < entities.at(j)->getNumMeshElements(); i++){
      MElement* element = entities.at(j)->getMeshElement(i);
      elements.push_back(element);
    }
  }
}

void Homology::_createCellComplex()
{
  Msg::StatusBar(2, true, "Creating cell complex...");
  double t1 = Cpu();

  if(_domainEntities.empty()) Msg::Error("Domain is empty");
  if(_subdomainEntities.empty()) Msg::Info("Subdomain is empty");

  std::vector<MElement*> domainElements;
  std::vector<MElement*> subdomainElements;
  std::vector<MElement*> nondomainElements;
  std::vector<MElement*> nonsubdomainElements;
  std::vector<MElement*> immuneElements;

  _getElements(_domainEntities, domainElements);
  _getElements(_subdomainEntities, subdomainElements);
  _getElements(_nondomainEntities, nondomainElements);
  _getElements(_nonsubdomainEntities, nonsubdomainElements);
  _getElements(_immuneEntities, immuneElements);

  if(_cellComplex != NULL) delete _cellComplex;
  _cellComplex =  new CellComplex(_model,
                                  domainElements,
                                  subdomainElements,
                                  nondomainElements,
                                  nonsubdomainElements,
                                  immuneElements,
                                  _saveOrig);

  if(_cellComplex->getSize(0) == 0) {
    Msg::Error("Cell Complex is empty: check the domain and the mesh");
  }
  double t2 = Cpu();
  Msg::StatusBar(2, true, "Done creating cell complex (%g s)", t2 - t1);
  Msg::Info("%d volumes, %d faces, %d edges, and %d vertices",
            _cellComplex->getSize(3), _cellComplex->getSize(2),
	    _cellComplex->getSize(1), _cellComplex->getSize(0));
}

void Homology::_deleteChains(std::vector<int> dim)
{
  if(dim.empty()) {
    std::vector<int> alldim(4);
    for(int i = 0; i < 4; i++) alldim[i] = i;
    _deleteChains(alldim);
    return;
  }

  for(unsigned int j = 0; j < dim.size(); j ++) {
    int d = dim.at(j);
    if(d < 0 || d > 3) continue;
    for(unsigned int i = 0; i < _chains[d].size(); i++) {
      delete _chains[d].at(i);
    }
    _chains[d].clear();
    _homologyComputed[d] = false;
  }
}

void Homology::_deleteCochains(std::vector<int> dim)
{
  if(dim.empty()) {
    std::vector<int> alldim(4);
    for(int i = 0; i < 4; i++) alldim[i] = i;
    _deleteCochains(alldim);
    return;
  }

  for(unsigned int j = 0; j < dim.size(); j ++) {
    int d = dim.at(j);
    if(d < 0 || d > 3) continue;
    for(unsigned int i = 0; i < _cochains[d].size(); i++) {
      delete _cochains[d].at(i);
    }
    _cochains[d].clear();
    _cohomologyComputed[d] = false;
  }
}

Homology::~Homology()
{
  if(_cellComplex != NULL) delete _cellComplex;
  _deleteChains();
  _deleteCochains();
}

void Homology::findHomologyBasis(std::vector<int> dim)
{
  if(_cellComplex == NULL) _createCellComplex();
  if(_cellComplex->isReduced()) _cellComplex->restoreComplex();
  Msg::StatusBar(2, true, "Reducing cell complex...");

  double t1 = Cpu();
  int omitted = _cellComplex->reduceComplex(_combine, _omit);

  if(!dim.empty() && _combine > 1 && !_smoothen) {
    for(int i = 1; i <= 3;  i++) {
      if(!std::binary_search(dim.begin(), dim.end(), i)) {
        _cellComplex->cocombine(i-1);
      }
    }
  }

  double t2 = Cpu();
  Msg::StatusBar(2, true, "Done reducing cell complex (%g s)", t2 - t1);
  Msg::Info("%d volumes, %d faces, %d edges, and %d vertices",
            _cellComplex->getSize(3), _cellComplex->getSize(2),
	    _cellComplex->getSize(1), _cellComplex->getSize(0));

  Msg::StatusBar(2, true, "Computing homology space bases ...");
  t1 = Cpu();
  ChainComplex chainComplex = ChainComplex(_cellComplex);
  chainComplex.computeHomology();
  t2 = Cpu();
  Msg::StatusBar(2, true, "Done computing homology space bases (%g s)", t2 - t1);

  std::string domain = _getDomainString(_domain, _subdomain);
  _deleteChains(dim);
  for(int j = 0; j < 4; j++){
    _betti[j] = 0;
    std::string dimension = "";
    convert(j, dimension);
    for(int i = 1; i <= chainComplex.getBasisSize(j, 3); i++){

      std::string generator = "";
      convert(i, generator);

      std::string name = "H_" + dimension + domain + generator;
      std::map<Cell*, int, Less_Cell> chain;
      chainComplex.getBasisChain(chain, i, j, 3, _smoothen);
      int torsion = chainComplex.getTorsion(j,i);
      if(!chain.empty()) {
        _createChain(chain, name, false);
        _betti[j] = _betti[j] + 1;
        if(torsion != 1){
          Msg::Warning("H_%d %d has torsion coefficient %d!",
                       j, i, torsion);
        }
      }
    }
  }

  if(_fileName != "") writeBasisMSH();

  Msg::Info("Ranks of domain %shomology spaces:", domain.c_str());
  Msg::Info("H_0 = %d", _betti[0]);
  Msg::Info("H_1 = %d", _betti[1]);
  Msg::Info("H_2 = %d", _betti[2]);
  Msg::Info("H_3 = %d", _betti[3]);
  if(omitted != 0) Msg::Info("The computation of basis elements in the highest dimension was omitted");

  Msg::StatusBar(2, false, "H_0: %d, H_1: %d, H_2: %d, H_3: %d",
		 _betti[0], _betti[1], _betti[2], _betti[3]);

  if(dim.empty()) {
    for(unsigned int i = 0; i < 4; i++)
      _homologyComputed[i] = true;
  }
  else {
    for(unsigned int i = 0; i < dim.size(); i++)
      _homologyComputed[dim.at(i)] = true;
  }
}

void Homology::findCohomologyBasis(std::vector<int> dim)
{
  if(_cellComplex == NULL) _createCellComplex();
  if(_cellComplex->isReduced()) _cellComplex->restoreComplex();

  Msg::StatusBar(2, true, "Reducing cell complex...");

  double t1 = Cpu();

  int omitted = _cellComplex->coreduceComplex(_combine, _omit);

  std::sort(dim.begin(), dim.end());
  if(!dim.empty()  && _combine > 1) {
    for(int i = 2; i >= 0;  i--) {
      if(!std::binary_search(dim.begin(), dim.end(), i)) {
        _cellComplex->combine(i+1);
      }
    }
  }

  double t2 = Cpu();

  Msg::StatusBar(2, true, "Done reducing cell complex (%g s)", t2 - t1);
  Msg::Info("%d volumes, %d faces, %d edges, and %d vertices",
            _cellComplex->getSize(3), _cellComplex->getSize(2),
	    _cellComplex->getSize(1), _cellComplex->getSize(0));

  Msg::StatusBar(2, true, "Computing cohomology space bases ...");
  t1 = Cpu();
  ChainComplex chainComplex = ChainComplex(_cellComplex);
  chainComplex.transposeHMatrices();
  chainComplex.computeHomology(true);
  t2 = Cpu();
  Msg::StatusBar(2, true, "Done computing cohomology space bases (%g s)", t2- t1);

  std::string domain = _getDomainString(_domain, _subdomain);
  _deleteCochains(dim);
  for(int i = 0; i < 4; i++) _betti[i] = 0;
  for(int j = 3; j > -1; j--){
    std::string dimension = "";
    convert(j, dimension);

    for(int i = 1; i <= chainComplex.getBasisSize(j, 3); i++){

      std::string generator = "";
      convert(i, generator);

      std::string name = "H^" + dimension + domain + generator;
      std::map<Cell*, int, Less_Cell> chain;
      chainComplex.getBasisChain(chain, i, j, 3, false);
      int torsion = chainComplex.getTorsion(j,i);
      if(!chain.empty()) {
        _createChain(chain, name, true);
        _betti[j] = _betti[j] + 1;
        if(torsion != 1){
          Msg::Warning("H^%d %d has torsion coefficient %d!", j, i, torsion);
        }
      }
    }
  }

  if(_fileName != "") writeBasisMSH();

  Msg::Info("Ranks of domain %scohomology spaces:", domain.c_str());
  Msg::Info("H^0 = %d", _betti[0]);
  Msg::Info("H^1 = %d", _betti[1]);
  Msg::Info("H^2 = %d", _betti[2]);
  Msg::Info("H^3 = %d", _betti[3]);
  if(omitted != 0) Msg::Info("The computation of basis elements in the highest dimension was omitted");

  Msg::StatusBar(2, false, "H^0: %d, H^1: %d, H^2: %d, H^3: %d",
		 _betti[0], _betti[1], _betti[2], _betti[3]);

  if(dim.empty()) {
    for(unsigned int i = 0; i < 4; i++)
      _cohomologyComputed[i] = true;
  }
  else {
    for(unsigned int i = 0; i < dim.size(); i++)
      _cohomologyComputed[dim.at(i)] = true;
  }
}

bool Homology::isHomologyComputed(std::vector<int> dim)
{
  if(dim.empty()) return (_homologyComputed[0] &&
                          _homologyComputed[1] &&
                          _homologyComputed[2] &&
                          _homologyComputed[3]);

  bool computed = true;
  for(unsigned int i = 0; i < dim.size(); i++) {
    int d = dim.at(i);
    if(d < 0 || d > 3) continue;
    computed = computed && _homologyComputed[d];
  }
  return computed;
}

bool Homology::isCohomologyComputed(std::vector<int> dim)
{
  if(dim.empty()) return (_cohomologyComputed[0] &&
                          _cohomologyComputed[1] &&
                          _cohomologyComputed[2] &&
                          _cohomologyComputed[3]);

  bool computed = true;
  for(unsigned int i = 0; i < dim.size(); i++) {
    int d = dim.at(i);
    if(d < 0 || d > 3) continue;
    computed = computed && _cohomologyComputed[d];
  }
  return computed;
}

void Homology::findCompatibleBasisPair(int master, std::vector<int> dim)
{
  if(!this->isHomologyComputed(dim)) this->findHomologyBasis(dim);
  if(!this->isCohomologyComputed(dim)) this->findCohomologyBasis(dim);
  for(unsigned int idim = 0 ; idim < dim.size(); idim++) {
    int d = dim.at(idim);
    if(d < 1 || d > 2) continue;
    int n = this->betti(d);
    if(n < 2) continue;
    if((int)_chains[d].size() != n || (int)_cochains[d].size() != n) {
      Msg::Warning("Cannot produce compatible %d-(co)homology bases.", d);
      Msg::Debug("%d basis %d-chains and %d basis %d-cochains.",
                 (int)_chains[d].size(), d, (int)_cochains[d].size(), d);
      continue;
    }
    fullMatrix<double> m(n,n);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(master==0) m(i,j) = incidence(*_cochains[d].at(i), *_chains[d].at(j));
        else m(i,j) = incidence(*_chains[d].at(i), *_cochains[d].at(j));
      }
    }

    int det = m.determinant();
    if(abs(det) != 1 || !m.invertInPlace()) {
      Msg::Warning("Cannot produce compatible %d-(co)homology bases.", d);
      Msg::Debug("Incidence matrix: ");
      for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
          Msg::Debug("(%d, %d) = %d", i, j, m(i,j));
      continue;
    }

    std::vector<Chain<int>*> newBasis(n, NULL);

    if(master==0) {
      for(int i = 0; i < n; i++) {
        newBasis.at(i) = new Chain<int>();
        for(int j = 0; j < n; j++) {
          *newBasis.at(i) += (int)m(i,j)*(*_cochains[d].at(j));
        }
      }
      for(int i = 0; i < n; i++) {
        newBasis.at(i)->setName(_cochains[d].at(i)->getName());
        delete _cochains[d].at(i);
        _cochains[d].at(i) = newBasis.at(i);
      }
    }
    else {
      for(int i = 0; i < n; i++) {
        newBasis.at(i) = new Chain<int>();
        for(int j = 0; j < n; j++) {
          *newBasis.at(i) += (int)m(i,j)*(*_chains[d].at(j));
        }
      }
      for(int i = 0; i < n; i++) {
        newBasis.at(i)->setName(_chains[d].at(i)->getName());
        delete _chains[d].at(i);
        _chains[d].at(i) = newBasis.at(i);
      }
    }
  }
}

void Homology::addChainsToModel(int dim, bool post, int physicalNumRequest)
{
  int pgnum = -1;
  if(!_homologyComputed[dim])
    Msg::Warning("%d-Homology is not computed", dim);
  if(dim == -1) {
    for(int j = 0; j < 4; j++) {
      for(unsigned int i = 0; i < _chains[j].size(); i++) {
        if(physicalNumRequest != -1) pgnum = physicalNumRequest + i;
        else pgnum = -1;
        _chains[j].at(i)->addToModel(this->getModel(), post, pgnum);
      }
    }
  }
  else if (dim > -1 && dim < 4) {
    for(unsigned int i = 0; i < _chains[dim].size(); i++) {
      if(physicalNumRequest != -1) pgnum = physicalNumRequest + i;
      else pgnum = -1;
      _chains[dim].at(i)->addToModel(this->getModel(), post, pgnum);
    }
  }
}

void Homology::addCochainsToModel(int dim, bool post, int physicalNumRequest)
{
  int pgnum = -1;
  if(!_cohomologyComputed[dim])
    Msg::Warning("%d-Cohomology is not computed", dim);
  if(dim == -1) {
    for(int j = 0; j < 4; j++) {
      for(unsigned int i = 0; i < _cochains[j].size(); i++) {
        if(physicalNumRequest != -1) pgnum = physicalNumRequest + i;
        else pgnum = -1;
        _cochains[j].at(i)->addToModel(this->getModel(), post, pgnum);
      }
    }
  }
  else if (dim > -1 && dim < 4) {
    for(unsigned int i = 0; i < _cochains[dim].size(); i++) {
      if(physicalNumRequest != -1) pgnum = physicalNumRequest + i;
      else pgnum = -1;
      _cochains[dim].at(i)->addToModel(this->getModel(), post, pgnum);
    }
  }
}

void Homology::getHomologyBasis(int dim, std::vector<Chain<int> >& hom)
{
  if(dim < 0 || dim > 3) return;
  if(!_homologyComputed[dim]) findHomologyBasis();

  hom.resize(_chains[dim].size());
  for(unsigned int i = 0; i < _chains[dim].size(); i++)
    hom[i] = *_chains[dim].at(i);
}

void Homology::getCohomologyBasis(int dim, std::vector<Chain<int> >& coh)
{
  if(dim < 0 || dim > 3) return;
  if(!_cohomologyComputed[dim]) findCohomologyBasis();

  coh.resize(_cochains[dim].size());
  for(unsigned int i = 0; i < _cochains[dim].size(); i++)
    coh[i] = *_cochains[dim].at(i);
}

int Homology::betti(int dim)
{
  if(dim < 0 || dim > 3) return 0;
  if(_betti[dim] != -1) return _betti[dim];

  findHomologyBasis();
  return _betti[dim];
}

int Homology::eulerCharacteristic()
{
  if(_cellComplex == NULL) _createCellComplex();
  return _cellComplex->eulerCharacteristic();
}

void Homology::_createChain(std::map<Cell*, int, Less_Cell>& preChain,
                            std::string name, bool co)
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
  if(co) _cochains[chain->getDim()].push_back(chain);
  else _chains[chain->getDim()].push_back(chain);
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
      subCell->getMeshVertices(v);

      MElement* e = factory.create(subCell->getTypeMSH(), v);
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

