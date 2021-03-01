// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Matti Pellikka <matti.pellikka@gmail.com>.

#include "Homology.h"
#include "fullMatrix.h"

#if defined(HAVE_KBIPACK)

Homology::Homology(GModel *model, const std::vector<int> &physicalDomain,
                   const std::vector<int> &physicalSubdomain,
                   const std::vector<int> &physicalImdomain, bool saveOrig,
                   int combine, bool omit, bool smoothen, int heuristic)
  : _model(model), _domain(physicalDomain), _subdomain(physicalSubdomain),
    _imdomain(physicalImdomain), _saveOrig(saveOrig), _combine(combine),
    _omit(omit), _smoothen(smoothen), _heuristic(heuristic),
    _cellComplex(nullptr)
{
  _fileName = "";

  // default to the whole model
  if(_domain.empty()) {
    int dim = _model->getDim();
    std::vector<GEntity *> entities;
    _model->getEntities(entities);
    for(auto it = entities.begin(); it != entities.end(); it++) {
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

  for(std::size_t i = 0; i < 4; i++) {
    _homologyComputed[i] = false;
    _cohomologyComputed[i] = false;
    _betti[i] = -1;
  }

  if(abs(_heuristic) > 1) _heuristic = 0;
}

std::vector<int> vecN0(int n)
{
  std::vector<int> v;
  v.reserve(n);
  for(int i = 0; i < n; i++) v.push_back(i);
  return v;
}

void Homology::_getEntities(const std::vector<int> &physicalGroups,
                            std::vector<GEntity *> &entities)
{
  entities.clear();
  std::map<int, std::vector<GEntity *> > groups[4];
  _model->getPhysicalGroups(groups);

  for(std::size_t i = 0; i < physicalGroups.size(); i++) {
    for(int j = 0; j < 4; j++) {
      auto it = groups[j].find(physicalGroups.at(i));
      if(it != groups[j].end()) {
        std::vector<GEntity *> physicalGroup = (*it).second;
        for(std::size_t k = 0; k < physicalGroup.size(); k++) {
          entities.push_back(physicalGroup.at(k));
        }
      }
    }
  }
}

void Homology::_getElements(const std::vector<GEntity *> &entities,
                            std::vector<MElement *> &elements)
{
  elements.clear();
  for(std::size_t j = 0; j < entities.size(); j++) {
    for(std::size_t i = 0; i < entities.at(j)->getNumMeshElements(); i++) {
      MElement *element = entities.at(j)->getMeshElement(i);
      elements.push_back(element);
    }
  }
}

void Homology::_createCellComplex()
{
  Msg::StatusBar(true, "Creating cell complex...");
  double t1 = Cpu(), w1 = TimeOfDay();

  if(_domainEntities.empty()) Msg::Error("Domain is empty");
  if(_subdomainEntities.empty()) Msg::Info("Subdomain is empty");

  std::vector<MElement *> domainElements;
  std::vector<MElement *> subdomainElements;
  std::vector<MElement *> nondomainElements;
  std::vector<MElement *> nonsubdomainElements;
  std::vector<MElement *> immuneElements;

  _getElements(_domainEntities, domainElements);
  _getElements(_subdomainEntities, subdomainElements);
  _getElements(_nondomainEntities, nondomainElements);
  _getElements(_nonsubdomainEntities, nonsubdomainElements);
  _getElements(_immuneEntities, immuneElements);

  if(_cellComplex != nullptr) delete _cellComplex;
  _cellComplex = new CellComplex(_model, domainElements, subdomainElements,
                                 nondomainElements, nonsubdomainElements,
                                 immuneElements, _saveOrig);

  if(_cellComplex->getSize(0) == 0) {
    Msg::Error("Cell Complex is empty: check the domain and the mesh");
  }
  double t2 = Cpu(), w2 = TimeOfDay();
  Msg::StatusBar(true, "Done creating cell complex (Wall %gs, CPU %gs)",
                 w2 - w1, t2 - t1);
  Msg::Info("%d volumes, %d faces, %d edges, and %d vertices",
            _cellComplex->getSize(3), _cellComplex->getSize(2),
            _cellComplex->getSize(1), _cellComplex->getSize(0));
}

void Homology::_deleteChains(std::vector<int> dim)
{
  for(std::size_t j = 0; j < dim.size(); j++) {
    int d = dim.at(j);
    if(d < 0 || d > 3) continue;
    for(std::size_t i = 0; i < _chains[d].size(); i++) {
      delete _chains[d].at(i);
    }
    _chains[d].clear();
    _homologyComputed[d] = false;
  }
}

void Homology::_deleteCochains(std::vector<int> dim)
{
  for(std::size_t j = 0; j < dim.size(); j++) {
    int d = dim.at(j);
    if(d < 0 || d > 3) continue;
    for(std::size_t i = 0; i < _cochains[d].size(); i++) {
      delete _cochains[d].at(i);
    }
    _cochains[d].clear();
    _cohomologyComputed[d] = false;
  }
}

Homology::~Homology()
{
  if(_cellComplex != nullptr) delete _cellComplex;
  _deleteChains();
  _deleteCochains();
}

void Homology::findHomologyBasis(std::vector<int> dim)
{
  double t0 = Cpu(), w0 = TimeOfDay();
  std::string domain = _getDomainString(_domain, _subdomain);
  Msg::Info("");
  Msg::Info("To compute domain (%s) homology spaces", domain.c_str());

  if(dim.empty()) {
    findBettiNumbers();
    return;
  }

  if(_cellComplex == nullptr) _createCellComplex();
  if(_cellComplex->isReduced()) _cellComplex->restoreComplex();

  Msg::StatusBar(true, "Reducing cell complex...");

  double t1 = Cpu(), w1 = TimeOfDay();
  double size1 = _cellComplex->getSize(-1);
  _cellComplex->reduceComplex(_combine, _omit);

  if(_combine > 1 && !_smoothen) {
    for(int i = 1; i <= 3; i++) {
      if(!std::binary_search(dim.begin(), dim.end(), i)) {
        _cellComplex->cocombine(i - 1);
      }
    }
  }

  double t2 = Cpu(), w2 = TimeOfDay();
  double size2 = _cellComplex->getSize(-1);
  Msg::StatusBar(true, "Done reducing cell complex (Wall %gs, CPU %gs, %g%%)",
                 w2 - w1, t2 - t1, (1. - size2 / size1) * 100.);
  Msg::Info("%d volumes, %d faces, %d edges, and %d vertices",
            _cellComplex->getSize(3), _cellComplex->getSize(2),
            _cellComplex->getSize(1), _cellComplex->getSize(0));

  Msg::StatusBar(true, "Computing homology space bases...");
  t1 = Cpu();
  w1 = TimeOfDay();
  ChainComplex chainComplex = ChainComplex(_cellComplex);
  chainComplex.computeHomology();
  t2 = Cpu();
  w2 = TimeOfDay();
  Msg::StatusBar(true,
                 "Done computing homology space bases (Wall %gs, CPU %gs)",
                 w2 - w1, t2 - t1);

  _deleteChains(dim);
  for(int j = 0; j < 4; j++) {
    _betti[j] = 0;
    std::string dimension = convertInt(j);
    for(int i = 1; i <= chainComplex.getBasisSize(j, 3); i++) {
      std::string generator = convertInt(i);

      std::string name = "H_" + dimension + domain + generator;
      std::map<Cell *, int, CellPtrLessThan> chain;
      chainComplex.getBasisChain(chain, i, j, 3, _smoothen);
      int torsion = chainComplex.getTorsion(j, i);
      if(!chain.empty()) {
        _createChain(chain, name, false);
        _betti[j] = _betti[j] + 1;
        if(torsion != 1) {
          Msg::Warning("H_%d %d has torsion coefficient %d!", j, i, torsion);
        }
      }
    }
  }

  if(_fileName != "") writeBasisMSH();

  Msg::Info("Ranks of domain (%s) homology spaces:", domain.c_str());
  Msg::Info("H_0 = %d", _betti[0]);
  Msg::Info("H_1 = %d", _betti[1]);
  Msg::Info("H_2 = %d", _betti[2]);
  Msg::Info("H_3 = %d", _betti[3]);

  double t3 = Cpu(), w3 = TimeOfDay();
  Msg::Info("Done computing (%s) homology spaces (Wall %gs, CPU %gs)",
            domain.c_str(), w3 - w0, t3 - t0);
  Msg::StatusBar(false, "H_0: %d, H_1: %d, H_2: %d, H_3: %d", _betti[0],
                 _betti[1], _betti[2], _betti[3]);

  for(std::size_t i = 0; i < dim.size(); i++) {
    int d = dim.at(i);
    if(d >= 0 && d < 4) _homologyComputed[d] = true;
  }
}

void Homology::findCohomologyBasis(std::vector<int> dim)
{
  double t0 = Cpu(), w0 = TimeOfDay();
  std::string domain = _getDomainString(_domain, _subdomain);
  Msg::Info("");
  Msg::Info("To compute domain (%s) cohomology spaces", domain.c_str());

  if(dim.empty()) {
    findBettiNumbers();
    return;
  }

  if(_cellComplex == nullptr) _createCellComplex();
  if(_cellComplex->isReduced()) _cellComplex->restoreComplex();

  Msg::StatusBar(true, "Reducing cell complex...");

  double t1 = Cpu(), w1 = TimeOfDay();
  double size1 = _cellComplex->getSize(-1);

  _cellComplex->coreduceComplex(_combine, _omit, _heuristic);

  std::sort(dim.begin(), dim.end());
  if(_combine > 1) {
    for(int i = 2; i >= 0; i--) {
      if(!std::binary_search(dim.begin(), dim.end(), i)) {
        _cellComplex->combine(i + 1);
      }
    }
  }

  double t2 = Cpu(), w2 = TimeOfDay();
  double size2 = _cellComplex->getSize(-1);

  Msg::StatusBar(true, "Done reducing cell complex (Wall %gs, CPU %gs, %g %%)",
                 w2 - w1, t2 - t1, (1. - size2 / size1) * 100.);
  Msg::Info("%d volumes, %d faces, %d edges, and %d vertices",
            _cellComplex->getSize(3), _cellComplex->getSize(2),
            _cellComplex->getSize(1), _cellComplex->getSize(0));

  Msg::StatusBar(true, "Computing cohomology space bases ...");
  t1 = Cpu();
  w1 = TimeOfDay();
  ChainComplex chainComplex = ChainComplex(_cellComplex);
  chainComplex.computeHomology(true);
  t2 = Cpu();
  w2 = TimeOfDay();
  Msg::StatusBar(true,
                 "Done computing cohomology space bases (Wall %gs, CPU %gs)",
                 w2 - w1, t2 - t1);

  _deleteCochains(dim);
  for(int i = 0; i < 4; i++) _betti[i] = 0;
  for(int j = 3; j > -1; j--) {
    std::string dimension = convertInt(j);

    for(int i = 1; i <= chainComplex.getBasisSize(j, 3); i++) {
      std::string generator = convertInt(i);

      std::string name = "H^" + dimension + domain + generator;
      std::map<Cell *, int, CellPtrLessThan> chain;
      chainComplex.getBasisChain(chain, i, j, 3, false);
      int torsion = chainComplex.getTorsion(j, i);
      if(!chain.empty()) {
        _createChain(chain, name, true);
        _betti[j] = _betti[j] + 1;
        if(torsion != 1) {
          Msg::Warning("H^%d %d has torsion coefficient %d!", j, i, torsion);
        }
      }
    }
  }

  if(_fileName != "") writeBasisMSH();

  Msg::Info("Ranks of domain (%s) cohomology spaces:", domain.c_str());
  Msg::Info("H^0 = %d", _betti[0]);
  Msg::Info("H^1 = %d", _betti[1]);
  Msg::Info("H^2 = %d", _betti[2]);
  Msg::Info("H^3 = %d", _betti[3]);

  double t3 = Cpu(), w3 = TimeOfDay();
  Msg::Info("Done computing (%s) cohomology spaces (Wall %gs, CPU %gs)",
            domain.c_str(), w3 - w0, t3 - t0);
  Msg::StatusBar(false, "H^0: %d, H^1: %d, H^2: %d, H^3: %d", _betti[0],
                 _betti[1], _betti[2], _betti[3]);

  for(std::size_t i = 0; i < dim.size(); i++) {
    int d = dim.at(i);
    if(d >= 0 && d < 4) _cohomologyComputed[d] = true;
  }
}

bool Homology::isBettiComputed() const
{
  bool computed = true;
  for(int i = 0; i < 4; i++) {
    if(_betti[i] == -1) computed = false;
  }
  return computed;
}

bool Homology::isHomologyComputed(std::vector<int> dim) const
{
  bool computed = true;
  for(std::size_t i = 0; i < dim.size(); i++) {
    int d = dim.at(i);
    if(d < 0 || d > 3) continue;
    computed = computed && _homologyComputed[d];
  }
  return computed;
}

bool Homology::isCohomologyComputed(std::vector<int> dim) const
{
  bool computed = true;
  for(std::size_t i = 0; i < dim.size(); i++) {
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
  for(std::size_t idim = 0; idim < dim.size(); idim++) {
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
    fullMatrix<double> m(n, n);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(master == 0)
          m(i, j) = incidence(*_cochains[d].at(i), *_chains[d].at(j));
        else
          m(i, j) = incidence(*_chains[d].at(i), *_cochains[d].at(j));
      }
    }

    int det = m.determinant();
    if(abs(det) != 1 || !m.invertInPlace()) {
      Msg::Warning("Cannot produce compatible %d-(co)homology bases.", d);
      Msg::Debug("Incidence matrix: ");
      for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) Msg::Debug("(%d, %d) = %d", i, j, m(i, j));
      continue;
    }

    std::vector<Chain<int> *> newBasis(n);

    if(master == 0) {
      for(int i = 0; i < n; i++) {
        newBasis.at(i) = new Chain<int>();
        for(int j = 0; j < n; j++) {
          *newBasis.at(i) += (int)m(i, j) * (*_cochains[d].at(j));
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
          *newBasis.at(i) += (int)m(i, j) * (*_chains[d].at(j));
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

std::vector<int> Homology::_addToModel(int dim, bool co, bool post,
                                       int physicalNumRequest) const
{
  std::vector<int> physicals;
  if(dim < 0 || dim > 3) return physicals;
  int pgnum = -1;
  if(!co) {
    for(std::size_t i = 0; i < _chains[dim].size(); i++) {
      if(physicalNumRequest != -1)
        pgnum = physicalNumRequest + i;
      else
        pgnum = -1;
      physicals.push_back(
        _chains[dim].at(i)->addToModel(this->getModel(), post, pgnum));
    }
  }
  else {
    for(std::size_t i = 0; i < _cochains[dim].size(); i++) {
      if(physicalNumRequest != -1)
        pgnum = physicalNumRequest + i;
      else
        pgnum = -1;
      physicals.push_back(
        _cochains[dim].at(i)->addToModel(this->getModel(), post, pgnum));
    }
  }
  if(!physicals.empty()) {
    std::vector<int> empty;
    std::string span = _getDomainString(physicals, empty);
    std::string domain = _getDomainString(_domain, _subdomain);
    if(!co)
      Msg::Info("Span H_%d(%s) = %s", dim, domain.c_str(), span.c_str());
    else
      Msg::Info("Span H^%d(%s) = %s", dim, domain.c_str(), span.c_str());
  }
  return physicals;
}

std::vector<int> Homology::addChainsToModel(int dim, bool post,
                                            int physicalNumRequest) const
{
  std::vector<int> physicals;
  if(dim > -1 && !_homologyComputed[dim])
    Msg::Warning("%d-Homology is not computed", dim);
  if(dim == -1) {
    for(int j = 0; j < 4; j++) {
      std::vector<int> p = _addToModel(j, false, post, physicalNumRequest);
      physicals.insert(physicals.end(), p.begin(), p.end());
    }
  }
  else if(dim > -1 && dim < 4) {
    physicals = _addToModel(dim, false, post, physicalNumRequest);
  }
  return physicals;
}

std::vector<int> Homology::addCochainsToModel(int dim, bool post,
                                              int physicalNumRequest) const
{
  std::vector<int> physicals;
  if(dim > -1 && !_cohomologyComputed[dim])
    Msg::Warning("%d-Cohomology is not computed", dim);
  if(dim == -1) {
    for(int j = 0; j < 4; j++) {
      std::vector<int> p = _addToModel(j, true, post, physicalNumRequest);
      physicals.insert(physicals.end(), p.begin(), p.end());
    }
  }
  else if(dim > -1 && dim < 4) {
    physicals = _addToModel(dim, true, post, physicalNumRequest);
  }
  return physicals;
}

void Homology::getHomologyBasis(int dim, std::vector<Chain<int> > &hom)
{
  if(dim < 0 || dim > 3) return;
  if(!_homologyComputed[dim]) findHomologyBasis();

  hom.resize(_chains[dim].size());
  for(std::size_t i = 0; i < _chains[dim].size(); i++)
    hom[i] = *_chains[dim].at(i);
}

void Homology::getCohomologyBasis(int dim, std::vector<Chain<int> > &coh)
{
  if(dim < 0 || dim > 3) return;
  if(!_cohomologyComputed[dim]) findCohomologyBasis();

  coh.resize(_cochains[dim].size());
  for(std::size_t i = 0; i < _cochains[dim].size(); i++)
    coh[i] = *_cochains[dim].at(i);
}

void Homology::findBettiNumbers()
{
  if(!isBettiComputed()) {
    if(_cellComplex == nullptr) _createCellComplex();
    if(_cellComplex->isReduced()) _cellComplex->restoreComplex();

    Msg::StatusBar(true, "Reducing cell complex...");
    double t1 = Cpu(), w1 = TimeOfDay();
    double size1 = _cellComplex->getSize(-1);

    _cellComplex->bettiReduceComplex();

    double t2 = Cpu(), w2 = TimeOfDay();
    double size2 = _cellComplex->getSize(-1);

    Msg::StatusBar(true,
                   "Done reducing cell complex (Wall %gs, CPU %gs, %g %%)",
                   w2 - w1, t2 - t1, (1. - size2 / size1) * 100.);
    Msg::Info("%d volumes, %d faces, %d edges, and %d vertices",
              _cellComplex->getSize(3), _cellComplex->getSize(2),
              _cellComplex->getSize(1), _cellComplex->getSize(0));

    Msg::StatusBar(true, "Computing betti numbers...");
    t1 = Cpu();
    w1 = TimeOfDay();
    ChainComplex chainComplex = ChainComplex(_cellComplex);
    chainComplex.computeHomology();

    for(int i = 0; i < 4; i++) _betti[i] = chainComplex.getBasisSize(i, 3);

    t2 = Cpu();
    w2 = TimeOfDay();
    Msg::StatusBar(true, "Betti numbers computed (Wall %gs, CPU %gs)", w2 - w1,
                   t2 - t1);
  }

  std::string domain = _getDomainString(_domain, _subdomain);
  Msg::Info("Domain %s Betti numbers:", domain.c_str());
  Msg::Info("b0 = %d", _betti[0]);
  Msg::Info("b1 = %d", _betti[1]);
  Msg::Info("b2 = %d", _betti[2]);
  Msg::Info("b3 = %d", _betti[3]);

  Msg::StatusBar(false, "b0: %d, b1: %d, b2: %d, b3: %d", _betti[0], _betti[1],
                 _betti[2], _betti[3]);
}

int Homology::betti(int dim)
{
  if(dim < 0 || dim > 3) return 0;
  if(_betti[dim] != -1) return _betti[dim];

  findBettiNumbers();
  return _betti[dim];
}

int Homology::eulerCharacteristic()
{
  if(_cellComplex == nullptr) _createCellComplex();
  return _cellComplex->eulerCharacteristic();
}

void Homology::_createChain(std::map<Cell *, int, CellPtrLessThan> &preChain,
                            const std::string &name, bool co)
{
  Chain<int> *chain = new Chain<int>();
  chain->setName(name);

  for(auto cit = preChain.begin(); cit != preChain.end(); cit++) {
    Cell *cell = cit->first;
    int coeff = cit->second;
    if(coeff == 0) continue;

    std::vector<MVertex *> v;
    cell->getMeshVertices(v);
    chain->addElemChain(ElemChain(cell->getDim(), v), coeff);
  }
  if(co)
    _cochains[chain->getDim()].push_back(chain);
  else
    _chains[chain->getDim()].push_back(chain);
}

std::string Homology::_getDomainString(const std::vector<int> &domain,
                                       const std::vector<int> &subdomain) const
{
  std::string domainString = "{";
  if(domain.empty())
    domainString += "0";
  else {
    for(std::size_t i = 0; i < domain.size(); i++) {
      std::string temp = convertInt(domain.at(i));
      domainString += temp;
      if(domain.size() - 1 > i) { domainString += ","; }
    }
  }
  domainString += "}";

  if(!subdomain.empty()) {
    domainString += ",{";
    for(std::size_t i = 0; i < subdomain.size(); i++) {
      std::string temp = convertInt(subdomain.at(i));
      domainString += temp;
      if(subdomain.size() - 1 > i) { domainString += ","; }
    }
    domainString += "}";
  }

  return domainString;
}

bool Homology::writeBasisMSH(bool binary)
{
  if(_fileName.empty()) return false;
  if(!_model->writeMSH(_fileName, 2.0, binary)) return false;
  Msg::Info("Wrote homology computation results to %s", _fileName.c_str());
  return true;
}

void Homology::storeCells(CellComplex *cellComplex, int dim)
{
  std::vector<MElement *> elements;
  MElementFactory factory;

  for(auto cit = cellComplex->firstCell(dim); cit != cellComplex->lastCell(dim);
      cit++) {
    Cell *cell = *cit;
    std::map<Cell *, int, CellPtrLessThan> cells;
    cell->getCells(cells);
    for(auto it = cells.begin(); it != cells.end(); it++) {
      Cell *subCell = it->first;
      std::vector<MVertex *> v;
      subCell->getMeshVertices(v);

      MElement *e = factory.create(subCell->getTypeMSH(), v);
      elements.push_back(e);
    }
  }

  int max[4];
  for(int i = 0; i < 4; i++) max[i] = _model->getMaxElementaryNumber(i);
  int entityNum = *std::max_element(max, max + 4) + 1;
  for(int i = 0; i < 4; i++) max[i] = _model->getMaxPhysicalNumber(i);
  int physicalNum = *std::max_element(max, max + 4) + 1;

  std::map<int, std::vector<MElement *> > entityMap;
  entityMap[entityNum] = elements;
  std::map<int, std::map<int, std::string> > physicalMap;
  std::map<int, std::string> physicalInfo;
  physicalInfo[physicalNum] = "Cell Complex";
  physicalMap[entityNum] = physicalInfo;

  _model->storeChain(dim, entityMap, physicalMap);
  _model->setPhysicalName("Cell Complex", dim, physicalNum);
}

#endif
