#include "BasisLagrange.h"

using namespace std;

BasisLagrange::BasisLagrange(void){
  scalar = true;

  preEvaluated     = false;
  preEvaluatedGrad = false;

  preEvaluatedFunction     = NULL;
  preEvaluatedGradFunction = NULL;
}

BasisLagrange::~BasisLagrange(void){
  if(preEvaluated)
    delete preEvaluatedFunction;

  if(preEvaluatedGrad)
    delete preEvaluatedGradFunction;
}

/*
static bool
sortPredicate(const std::pair<size_t, size_t>& a,
              const std::pair<size_t, size_t>& b){
  return a.second < b.second;
}

static vector<int> reducedNodeId(const MElement& element){
  const size_t nVertex = element.getNumPrimaryVertices();
  vector<pair<size_t, size_t> > vertexGlobalId(nVertex);

  for(size_t i = 0; i < nVertex; i++){
    vertexGlobalId[i].first  = i;
    vertexGlobalId[i].second = element.getVertex(i)->getNum();
  }

  std::sort(vertexGlobalId.begin(), vertexGlobalId.end(), sortPredicate);

  vector<int> vertexReducedId(nVertex);

  for(size_t i = 0; i < nVertex; i++)
    vertexReducedId[vertexGlobalId[i].first] = i;

  return vertexReducedId;
}

static size_t matchClosure(vector<int>& reduced,
                           nodalBasis::clCont& closures){

  const size_t nNode = reduced.size();
  const size_t nPerm = closures.size();

  size_t i = 0;
  bool   match = false;

  while(i < nPerm && !match){
    match = true;

    for(size_t j = 0; j < nNode && match; j++)
      if(reduced[j] != closures[i][j])
         match = false;

    if(!match)
      i++;
  }

  return i;
}

void BasisLagrange::mapFromXYZtoABC(const MElement& element,
                                    const fullVector<double>& xyz,
                                    double abc[3]) const{
}

vector<size_t> BasisLagrange::
getFunctionOrdering(const MElement& element) const{

  static bool once = true;

  if(once){
    for(size_t i = 0; i < lBasis->fullClosures.size(); i++){
      vector<int>& closure = lBasis->fullClosures[i];

      for(size_t j =0; j < closure.size(); j++)
        cout << closure[j] << "\t";
      cout << endl;
    }

    once = false;
  }


  vector<int> rNodeId = reducedNodeId(element);
  const size_t closureId = matchClosure(rNodeId, lBasis->fullClosures);

  vector<int>& closure = lBasis->fullClosures[closureId];

  vector<size_t> myClosure(closure.size());

  for(size_t i = 0; i < closure.size(); i++)
    myClosure[i] = closure[i];

  return myClosure;

  vector<size_t> c(10);

  if(closureId == 0){
    c[0] = 0;
    c[1] = 1;
    c[2] = 2;
    c[3] = 3;
    c[4] = 4;
    c[5] = 5;
    c[6] = 6;
    c[7] = 8; // 7;
    c[8] = 7; // 8;
    c[9] = 9;
  }

  else{
    c[0] = 2;
    c[1] = 0;
    c[2] = 1;
    c[3] = 8; // 7;
    c[4] = 7; // 8;
    c[5] = 3;
    c[6] = 4;
    c[7] = 5;
    c[8] = 6;
    c[9] = 9;
  }

  return c;
}
*/
void BasisLagrange::
getFunctions(fullMatrix<double>& retValues,
             const MElement& element,
             double u, double v, double w) const{

  // Fill Matrix //
  fullMatrix<double> tmp;
  fullMatrix<double> point(1, 3);
  point(0, 0) = u;
  point(0, 1) = v;
  point(0, 2) = w;

  lBasis->f(point, tmp);

  // Transpose 'tmp': otherwise not coherent with df !!
  retValues = tmp.transpose();
}

void BasisLagrange::
getFunctions(fullMatrix<double>& retValues,
             size_t orientation,
             double u, double v, double w) const{

  // Fill Matrix //
  fullMatrix<double> tmp;
  fullMatrix<double> point(1, 3);
  point(0, 0) = u;
  point(0, 1) = v;
  point(0, 2) = w;

  lBasis->f(point, tmp);

  // Transpose 'tmp': otherwise not coherent with df !!
  retValues = tmp.transpose();
}

void BasisLagrange::preEvaluateFunctions(const fullMatrix<double>& point) const{
  // Delete if older //
  if(preEvaluated)
    delete preEvaluatedFunction;

  // Fill Matrix //
  fullMatrix<double> tmp;
  lBasis->f(point, tmp);

  // Transpose 'tmp': otherwise not coherent with df !!
  preEvaluatedFunction = new fullMatrix<double>(tmp.transpose());

  // PreEvaluated //
  preEvaluated = true;
}

void BasisLagrange::
preEvaluateDerivatives(const fullMatrix<double>& point) const{
  // Delete if older //
  if(preEvaluatedGrad)
    delete preEvaluatedGradFunction;

  // Alloc //
  preEvaluatedGradFunction = new fullMatrix<double>;

  // Fill Matrix //
  lBasis->df(point, *preEvaluatedGradFunction);

  // PreEvaluated //
  preEvaluatedGrad = true;
}

const fullMatrix<double>&
BasisLagrange::getPreEvaluatedFunctions(const MElement& element) const{
  return *preEvaluatedFunction;
}

const fullMatrix<double>&
BasisLagrange::getPreEvaluatedDerivatives(const MElement& element) const{
  return *preEvaluatedGradFunction;
}

const fullMatrix<double>&
BasisLagrange::getPreEvaluatedFunctions(size_t orientation) const{
  return *preEvaluatedFunction;
}

const fullMatrix<double>&
BasisLagrange::getPreEvaluatedDerivatives(size_t orientation) const{
  return *preEvaluatedGradFunction;
}

vector<double> BasisLagrange::
project(const MElement& element,
        const vector<double>& coef,
        const FunctionSpaceScalar& fSpace){

  // Init New Coefs //
  const size_t size = lPoint->size1();
  const size_t dim  = lPoint->size2();

  vector<double> newCoef(size);

  // Interpolation at Lagrange Points //
  for(size_t i = 0; i < size; i++){
    fullVector<double> uvw(3);

    if(dim > 0)
      uvw(0) = (*lPoint)(i, 0);
    else
      uvw(0) = 0;

    if(dim > 1)
      uvw(1) = (*lPoint)(i, 1);
    else
      uvw(1) = 0;

    if(dim > 2)
      uvw(2) = (*lPoint)(i, 2);
    else
      uvw(2) = 0;

    newCoef[i] = fSpace.interpolateInRefSpace(element,
                                              coef,
                                              uvw);
  }

  // Return ;
  return newCoef;
}

vector<fullVector<double> > BasisLagrange::
project(const MElement& element,
        const vector<double>& coef,
        const FunctionSpaceVector& fSpace){

  // Init New Coefs //
  const size_t size = lPoint->size1();
  vector<fullVector<double> > newCoef(size);

  // Interpolation at Lagrange Points //
  for(size_t i = 0; i < size; i++){
    fullVector<double> uvw(3);

    if(dim > 0)
      uvw(0) = (*lPoint)(i, 0);
    else
      uvw(0) = 0;

    if(dim > 1)
      uvw(1) = (*lPoint)(i, 1);
    else
      uvw(1) = 0;

    if(dim > 2)
      uvw(2) = (*lPoint)(i, 2);
    else
      uvw(2) = 0;

    newCoef[i] = fSpace.interpolateInRefSpace(element,
                                              coef,
                                              uvw);
  }

  // Return ;
  return newCoef;
}

std::string BasisLagrange::toString(void) const{
  return std::string("BasisLagrange::toString() not Implemented");
}
