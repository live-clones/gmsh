#include "FunctionSpaceScalar.h"

FunctionSpaceScalar::FunctionSpaceScalar(GroupOfElement& goe,
                                         const Basis& basis){
  scalar = true;
  build(goe, basis);
}

FunctionSpaceScalar::~FunctionSpaceScalar(void){
  // Done by FunctionSpace
}

double FunctionSpaceScalar::
interpolate(const MElement& element,
            const std::vector<double>& coef,
            const fullVector<double>& xyz) const{
  /*
  // Const Cast For MElement //
  MElement& eelement =
    const_cast<MElement&>(element);

  // Get Reference coordinate //
  double phys[3] = {xyz(0), xyz(1), xyz(2)};
  double uvw[3];
  double abc[3];

  eelement.xyz2uvw(phys, uvw);

  // Compute coordinate in abc Space //
  std::vector<size_t> order = (*basis)[0]->getFunctionOrdering(element);
  double abcMat[3][3];
  double abcPnt[3][3];

  element.getNode(0, abcPnt[0][0], abcPnt[0][1], abcPnt[0][2]);
  element.getNode(1, abcPnt[1][0], abcPnt[1][1], abcPnt[1][2]);
  element.getNode(2, abcPnt[2][0], abcPnt[2][1], abcPnt[2][2]);

  std::cout << order[0] << " | "
            << order[1] << " | "
            << order[2] << std::endl;

  abcMat[0][0] = abcPnt[0][0];
  abcMat[0][1] = abcPnt[1][0];
  abcMat[0][2] = abcPnt[2][0];

  abcMat[1][0] = abcPnt[0][1];
  abcMat[1][1] = abcPnt[1][1];
  abcMat[1][2] = abcPnt[2][1];

  abcMat[2][0] = abcPnt[0][2];
  abcMat[2][1] = abcPnt[1][2];
  abcMat[2][2] = abcPnt[2][2];

  for(size_t i = 0; i < 3; i++){
    for(size_t j = 0; j < 3; j++)
      std::cout << abcMat[i][j] << "\t";
    std::cout << std::endl;
  }
  std::cout << std::endl;

  double phiUVW[3];
  element.getShapeFunctions(uvw[0], uvw[1], uvw[2], phiUVW);

  size_t trueOrder[3];

  for(size_t i = 0; i < 3; i++){
    size_t idx;

    for(idx = 0; order[idx] != i; idx++)
      ;

    trueOrder[i] = idx;
  }

  abc[0] =
    abcMat[0][0] * phiUVW[trueOrder[0]] +
    abcMat[0][1] * phiUVW[trueOrder[1]] +
    abcMat[0][2] * phiUVW[trueOrder[2]];

  abc[1] =
    abcMat[1][0] * phiUVW[trueOrder[0]] +
    abcMat[1][1] * phiUVW[trueOrder[1]] +
    abcMat[1][2] * phiUVW[trueOrder[2]];

  abc[2] =
    abcMat[2][0] * phiUVW[trueOrder[0]] +
    abcMat[2][1] * phiUVW[trueOrder[1]] +
    abcMat[2][2] * phiUVW[trueOrder[2]];

  uvw[0] = abc[0];
  uvw[1] = abc[1];
  uvw[2] = abc[2];
  */

  // Get ABC Space coordinate //
  double abc[3];
  (*basis)[0]->mapFromXYZtoABC(element, xyz, abc);

  // Get Basis Functions //
  const unsigned int nFun = (*basis)[0]->getNFunction();
  fullMatrix<double>  fun(nFun, 1);

  (*basis)[0]->getFunctions(fun, element, abc[0], abc[1], abc[2]);

  // Interpolate (in Reference Place) //
  double val = 0;

  for(unsigned int i = 0; i < nFun; i++)
    val += fun(i, 0) * coef[i];

  // Return Interpolated Value //
  return val;
}

double FunctionSpaceScalar::
interpolateInRefSpace(const MElement& element,
                      const std::vector<double>& coef,
                      const fullVector<double>& uvw) const{

  // Get Basis Functions //
  const unsigned int nFun = (*basis)[0]->getNFunction();
  fullMatrix<double>  fun(nFun, 1);

  (*basis)[0]->getFunctions(fun, element, uvw(0), uvw(1), uvw(2));

  // Interpolate (in Reference Place) //
  double val = 0;

  for(unsigned int i = 0; i < nFun; i++)
    val += fun(i, 0) * coef[i];

  // Return Interpolated Value //
  return val;
}
