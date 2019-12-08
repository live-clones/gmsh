// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "PViewDataGModel.h"
#include "MVertex.h"
#include "MElement.h"
#include "Numeric.h"
#include "StringUtils.h"
#include "OS.h"
#include "Context.h"
#include "polynomialBasis.h"
#include "pyramidalBasis.h"
#include "BasisFactory.h"
#include "CGNSCommon.h"
#include "CGNSConventions.h"

#if defined(HAVE_LIBCGNS)


namespace {


// types for high-order node transformation (CPEX0045)
typedef std::vector<fullMatrix<double> > ZoneSolutionTransfo;
typedef std::map<std::string, ZoneSolutionTransfo> Family2SolutionTransfo;


#ifdef HAVE_LIBCGNS_CPEX0045
int readSolutionInterpolation(int fileIndex, int baseIndex, int familyIndex,
                              int interpIndex, ZoneSolutionTransfo &cgns2MshLag)
{
  int cgnsErr;

  // read solution interpolation tranformation info
  char interpName[CGNS_MAX_STR_LEN];
  ElementType_t cgnsType;
  int order, orderTime;
  InterpolationType_t interpType;
  cgnsErr = cg_solution_interpolation_read(fileIndex, baseIndex, familyIndex,
                                           interpIndex, interpName, &cgnsType,
                                           &order, &orderTime, &interpType);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);
  if(interpType != ParametricLagrange) {
    Msg::Error("Interpolation type %i not supported in solution CGNS reader",
               interpType);
    return 0;
  }
  if(orderTime != 0) {
    Msg::Error("Non-constant time interpolation not supported in solution "
               "CGNS reader");
    return 0;
  }

  // get number of user interpolation points
  int nbPt;
  cgnsErr = cg_solution_lagrange_interpolation_size(cgnsType, order, orderTime,
                                                    &nbPt);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);

  // read user interpolation points (parametric coordinates)
  std::vector<double> u(nbPt), v(nbPt), w(nbPt), t(orderTime+1);
  cgnsErr = cg_solution_interpolation_points_read(fileIndex, baseIndex,
                                                  familyIndex, interpIndex,
                                                  u.data(), v.data(), w.data(),
                                                  t.data());
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);
  
  // get Gmsh type from CGNS "base" type and order
  const int baseMshType = cgns2MshEltType(cgnsType);
  const int parentMshType = ElementType::getParentType(baseMshType);
  const int mshType = ElementType::getType(parentMshType, order, false);
  
  // get Gmsh interpolation points
  const nodalBasis *basis = BasisFactory::getNodalBasis(mshType);
  const fullMatrix<double> &mshPts = basis->getReferenceNodes();
  if(nbPt != mshPts.size1()) {
    Msg::Error("Internal error: number of interpolation points is different "
                "between CGNS and Gmsh for Gmsh element %i (parent type %i)",
                mshType, ElementType::getParentType(mshType));
    return 0;
  }
  std::vector<double> uMsh(nbPt), vMsh(nbPt), wMsh(nbPt);
  msh2CgnsReferenceElement(mshType, mshPts, uMsh, vMsh, wMsh);

  // compute transformation matrix from monomial to CGNS Lagrange coefficients,
  // i.e. the inverse transposed Vandermonde matrix of CGNS interpolation points
  // in the monomial basis
  fullMatrix<double> mono2CGNSLag(nbPt, nbPt);
  evalMonomialBasis(mshType, u, v, w, mono2CGNSLag);
  mono2CGNSLag.invertInPlace();

  // evaluate CGNS Lagrange base functions at Gmsh points
  fullMatrix<double> monoVal(nbPt, nbPt), lagVal(nbPt, nbPt);
  evalMonomialBasis(mshType, uMsh, vMsh, wMsh, monoVal);
  mono2CGNSLag.mult(monoVal, lagVal);

  // transformation matrix from CGNS to Gmsh Lagrange coefficients
  lagVal.transposeInPlace();
  cgns2MshLag[mshType] = lagVal;

  return 1;
}
#endif


int readSolutionTransfo(int fileIndex, int baseIndex,
                        Family2SolutionTransfo &allSolutionTransfo)
{
#ifdef HAVE_LIBCGNS_CPEX0045
  int cgnsErr;

  // read number of families
  int nbFam;
  cgnsErr = cg_nfamilies(fileIndex, baseIndex, &nbFam);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);

  // loop over families
  for(int iFam = 1; iFam <= nbFam; iFam++) {
    // read number of element interpolation transformations
    int nbInterp;
    cgnsErr = cg_nsolution_interpolation_read(fileIndex, baseIndex, iFam,
                                              &nbInterp);
    if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);
    if(nbInterp == 0) continue;

    // read family name
    char famName[CGNS_MAX_STR_LEN];
    int nbFamBC, nbGeoRef;
    cgnsErr = cg_family_read(fileIndex, baseIndex, iFam, famName, &nbFamBC,
                             &nbGeoRef);
    if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);

    // read element interpolation transformations
    ZoneSolutionTransfo &cgns2MshLag = allSolutionTransfo[std::string(famName)];
    cgns2MshLag.resize(NofValidElementTypes);
    for(int iInterp = 1; iInterp <= nbInterp; iInterp++) {
      int err = readSolutionInterpolation(fileIndex, baseIndex, iFam, iInterp,
                                          cgns2MshLag);
      if(err == 0) return 0;
    }
  }

  return 1;
#else
  return 1;
#endif
}


void getSolutionDataNode(int zoneIndex, int nbNode,
                      const std::vector<std::vector<MVertex *> > &vertPerZone,
                         std::vector<cgsize_t> solEntSet,
                         const std::vector<double> &data,
                         stepData<double> *step, double &dataMin,
                         double &dataMax)
{
  step->resizeData(nbNode);
  
  for(int iNode = 0; iNode < nbNode; iNode++) {
    const cgsize_t nodeInd = (solEntSet.size() > 0) ? solEntSet[iNode] : iNode;
    const int nodeNum = vertPerZone[zoneIndex][nodeInd]->getNum();
    double *d = step->getData(nodeNum, true, 1);
    *d = data[iNode];
    step->setMin(std::min(step->getMin(), *d));
    step->setMax(std::max(step->getMax(), *d));
    dataMin = std::min(dataMin, *d);
    dataMax = std::max(dataMax, *d);
  }
}


void getSolutionDataElement(int zoneIndex, int nbElt,
                        const std::vector<std::vector<MElement *> > &eltPerZone,
                            std::vector<cgsize_t> solEntSet,
                            const std::vector<double> &data,
                            stepData<double> *step, double &dataMin,
                            double &dataMax)
{
  step->resizeData(nbElt);
  
  for(int iElt = 0; iElt < nbElt; iElt++) {
    const cgsize_t eltInd = (solEntSet.size() > 0) ? solEntSet[iElt] : iElt;
    const int eltNum = eltPerZone[zoneIndex][eltInd]->getNum();
    double *d = step->getData(eltNum, true, 1);
    *d = data[iElt];
    step->setMin(std::min(step->getMin(), *d));
    step->setMax(std::max(step->getMax(), *d));
    dataMin = std::min(dataMin, *d);
    dataMax = std::max(dataMax, *d);
  }
}


void getInterpolationMat(int parentType, int order,
                         const fullMatrix<double>* &coeffMat,
                         const fullMatrix<double>* &monoMat)
{
  // get nodal basis
  const int mshType = ElementType::getType(parentType, order);
  const nodalBasis *basis = BasisFactory::getNodalBasis(mshType);

  // try to get interpolation matrices from polynomial basis, if it fails then
  // try from pyramidal basis
  const polynomialBasis *fs = dynamic_cast<const polynomialBasis *>(basis);
  if(fs) {
    coeffMat = &(fs->coefficients);
    monoMat = &(fs->monomials);
  }
  else {
    const pyramidalBasis *fs = dynamic_cast<const pyramidalBasis *>(basis);
    if(fs) {
      coeffMat = &(fs->coefficients);
      monoMat = &(fs->monomials);
    }
    else {
      coeffMat = 0;
      monoMat = 0;
    }
  }
}


void getSolutionDataElementNode(int zoneIndex, int order, int nbElt,
                                const ZoneSolutionTransfo *zoneSolTransfo,
                        const std::vector<std::vector<MElement *> > &eltPerZone,
                                std::vector<cgsize_t> solEntSet,
                                const std::vector<double> &data,
                                stepData<double> *step, double &dataMin,
                                double &dataMax,
                                std::vector<std::pair<int, int> >
                                  &ordersByParentType)
{
  step->resizeData(nbElt);

  // loop over elements
  int iStartEltData = 0;
  std::vector<bool> hasInterpolMat(100, false);
  for(int iElt = 0; iElt < nbElt; iElt++) {
    // get element type
    const cgsize_t eltInd = (solEntSet.size() > 0) ? solEntSet[iElt] : iElt;
    MElement *me = eltPerZone[zoneIndex][eltInd];
    const int eltNum = me->getNum();
    const int parentMshType = me->getType();
    const int orderGeo = me->getPolynomialOrder();
    ordersByParentType[parentMshType] = std::make_pair(orderGeo, order);
    int mshType = ElementType::getType(parentMshType, order, false);
    const int nbEltNode = ElementType::getNumVertices(mshType);

    // element node transformation if specified (CPEX0045)
    const fullMatrix<double> *transfoMat = 0;
    if((mshType != MSH_PNT) && (zoneSolTransfo != 0) &&
        (zoneSolTransfo->size() > 0)) {
      transfoMat = &((*zoneSolTransfo)[mshType]);
    }

    // values at element nodes for data read (source) and step data (dest.)
    double *eltData = const_cast<double*>(&(data[iStartEltData]));
    double *stepData = step->getData(eltNum, true, nbEltNode);
    
    // compute values at element nodes in step data
    if(transfoMat == 0) {
      // no basis specified: just reorder values from CGNS to Gmsh ordering
      const std::vector<int> &cgns2Msh = cgns2MshNodeIndex(mshType);
      for(int i = 0; i < nbEltNode; i++) stepData[cgns2Msh[i]] = eltData[i];
    }
    else {
      // transform from specified basis to Gmsh Lagrangian basis
      const fullVector<double> dataVec(eltData, nbEltNode);
      fullVector<double> stepDataVec(stepData, nbEltNode);
      transfoMat->mult(dataVec, stepDataVec);
    }

    // update bounds (faster here than in finalize)
    for(int iEltNode = 0; iEltNode < nbEltNode; iEltNode++) {
      const double &val = stepData[iEltNode];
      step->setMin(std::min(step->getMin(), val));
      step->setMax(std::max(step->getMax(), val));
      dataMin = std::min(dataMin, val);
      dataMax = std::max(dataMax, val);
    }

    iStartEltData += nbEltNode;
  }
}


bool readZoneSolution(const std::pair<std::string, std::string> &solFieldName,
                      int fileIndex, int baseIndex, int zoneIndex,
                      int zoneSolIndex, PViewDataGModel::DataType dataType,
                      const ZoneSolutionTransfo *zoneSolTransfo,
                      const std::vector<std::vector<MVertex *> > &vertPerZone,
                      const std::vector<std::vector<MElement *> > &eltPerZone,
                      stepData<double> *step, double &dataMin, double &dataMax,
                      std::vector<std::pair<int, int> > &ordersByParentType)
{
  int cgnsErr;

  // check FlowSolution name
  char rawSolName[CGNS_MAX_STR_LEN];
  GridLocation_t location;
  cgnsErr = cg_sol_info(fileIndex, baseIndex, zoneIndex, zoneSolIndex, rawSolName,
                        &location);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);
  if(std::string(rawSolName) != solFieldName.first) return true;

  // get number of values
  char zoneName[CGNS_MAX_STR_LEN];
  cgsize_t zoneSize[9];
  cgnsErr = cg_zone_read(fileIndex, baseIndex, zoneIndex, zoneName, zoneSize);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);

  // read solution size
  int dataDim;
  cgsize_t solSize[3];
  cgnsErr = cg_sol_size(fileIndex, baseIndex, zoneIndex, zoneSolIndex, &dataDim,
                        solSize);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);
  const cgsize_t dataSize = solSize[0];

  // get solution order
  int order = 1;
#ifdef HAVE_LIBCGNS_CPEX0045
  int orderTime;
  cgnsErr = cg_sol_interpolation_order_read(fileIndex, baseIndex, zoneIndex,
                                            zoneSolIndex, &order, &orderTime);
#endif

  // read point range if it exists
  std::vector<cgsize_t> solEntSet;
  PointSetType_t ptSetType;
  cgsize_t ptSetSize;
  cgnsErr = cg_sol_ptset_info(fileIndex, baseIndex, zoneIndex, zoneSolIndex,
                              &ptSetType, &ptSetSize);
  if(cgnsErr != CG_NODE_NOT_FOUND) {
    if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);
    if(ptSetSize > 0) {
      solEntSet.resize(ptSetSize);
      cgnsErr = cg_sol_ptset_read(fileIndex, baseIndex, zoneIndex, zoneSolIndex,
                                  solEntSet.data());
      if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);
      if(ptSetType == PointRange) {           // DBGTT: TODO: structured grids
        cgsize_t rangeMin = solEntSet[0]-1, rangeMax = solEntSet[1]-1;
        cgsize_t nbVal = rangeMax-rangeMin+1;
        solEntSet.resize(nbVal);
        for(cgsize_t i = 0; i < nbVal; i++) solEntSet[i] = rangeMin+i;
      }
      else if(ptSetType == PointList) {
        for(cgsize_t i = 0; i < ptSetSize; i++) solEntSet[i]--;
      }
      else {
        Msg::Warning("PointSetType %i not supported in CGNS solution reader",
                    ptSetType);
        return false;
      }
    }
  }

  // get number of fields in this FlowSolution
  int nbField;
  cgnsErr = cg_nfields(fileIndex, baseIndex, zoneIndex, zoneSolIndex, &nbField);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);
  
  // get field data
  for(int iField = 1; iField <= nbField; iField++) {
    // field name
    DataType_t cgnsDataType;
    char rawFieldName[CGNS_MAX_STR_LEN];
    cgnsErr = cg_field_info(fileIndex, baseIndex, zoneIndex, zoneSolIndex, iField,
                            &cgnsDataType, rawFieldName);
    if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);
    if(std::string(rawFieldName) != solFieldName.second) continue;

    // read field data
    cgsize_t rangeMin[3] = {1, 0, 0}, rangeMax[3] = {dataSize, 0, 0};
    std::vector<double> data(dataSize);
    cgnsErr = cg_field_read(fileIndex, baseIndex, zoneIndex, zoneSolIndex,
                            rawFieldName, RealDouble, rangeMin, rangeMax,
                            static_cast<void *>(data.data()));
    if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);
    
    // scan through data to populate step (possibly converting from custom
    // nodal set) and compute min/max (faster here than in finalize)
    if(dataType == PViewDataGModel::NodeData) {
      getSolutionDataNode(zoneIndex, zoneSize[0], vertPerZone, solEntSet, data,
                          step, dataMin, dataMax);
    }
    else if(dataType == PViewDataGModel::ElementData) {
      getSolutionDataElement(zoneIndex, zoneSize[1], eltPerZone, solEntSet, data,
                             step, dataMin, dataMax);
    }
    else if(dataType == PViewDataGModel::ElementNodeData) {
      getSolutionDataElementNode(zoneIndex, order, zoneSize[1], zoneSolTransfo,
                                 eltPerZone, solEntSet, data, step, dataMin,
                                 dataMax, ordersByParentType);
    }
  }

  return true;
}


} // namespace


bool PViewDataGModel::readCGNS(const std::pair<std::string,
                                               std::string> &solFieldName,
                               const std::string &fileName, int index,
                               int fileIndex, int baseIndex,
                        const std::vector<std::vector<MVertex *> > &vertPerZone,
                        const std::vector<std::vector<MElement *> > &eltPerZone)
{
  // create step if needed
  if(_steps.empty()) {
     _steps.push_back(new stepData<double>(GModel::current(), 1));
    _steps.back()->setFileIndex(-1);
    _steps.back()->setTime(0.);
  }

  // update step data
  _steps.back()->fillEntities();
  _steps.back()->computeBoundingBox();
  _steps.back()->setFileName(fileName);

  int cgnsErr;

  // read high-order node transformation (CPEX0045)
  Family2SolutionTransfo allSolutionTransfo;
  int err = readSolutionTransfo(fileIndex, baseIndex, allSolutionTransfo);
  if(err == 0) return false;

  // data structure to store geometrical and solution orders by parent type
  // (used to set interpolation matrices later)
  static const std::pair<int, int> dumOrders(-1, -1);
  std::vector<std::pair<int, int> > ordersByParentType(MSH_MAX_NUM, dumOrders);

  // read number of zones
  int nbZone = 0;
  cgnsErr = cg_nzones(fileIndex, baseIndex, &nbZone);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);

  // loop over zones
  for(int iZone = 1; iZone <= nbZone; iZone++) {
    // read family name and retrieve solution node transformations (CPEX0045)
    const ZoneSolutionTransfo *zoneSolTransfo = 0;
    cgnsErr = cg_goto(fileIndex, baseIndex, "Zone_t", iZone, "end");
    if(cgnsErr != CG_OK) err = cgnsError(__FILE__, __LINE__, fileIndex);
    char famName[CGNS_MAX_STR_LEN];
    cgnsErr = cg_famname_read(famName);
    if(cgnsErr != CG_NODE_NOT_FOUND) {
      if(cgnsErr == CG_OK) {
        Family2SolutionTransfo::const_iterator it =
                                allSolutionTransfo.find(std::string(famName));
        if(it != allSolutionTransfo.end()) zoneSolTransfo = &(it->second);
      }
      else err = cgnsError(__FILE__, __LINE__, fileIndex);
    }

    // get number of flow solutions in zone
    int nbZoneSol;
    cgnsErr = cg_nsols(fileIndex, baseIndex, iZone, &nbZoneSol);
    if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);

    // loop over solution fields in each zone
    for(int iZoneSol = 1; iZoneSol <= nbZoneSol; iZoneSol++) {
      bool ok = readZoneSolution(solFieldName, fileIndex, baseIndex, iZone,
                                 iZoneSol, getType(), zoneSolTransfo,
                                 vertPerZone, eltPerZone, _steps.back(), _min,
                                 _max, ordersByParentType);
      if(!ok) return false;
    }
  }

  // set interpolation matrices if needed (only for ElementBased solutions)
  for(int parentType = 0; parentType < TYPE_MAX_NUM; parentType++) {
    const int &orderGeo = ordersByParentType[parentType].first;
    const int &order = ordersByParentType[parentType].second;
    if(orderGeo != -1) {
      // element interpolation
      const fullMatrix<double> *coeffMatGeo, *monoMatGeo;
      getInterpolationMat(parentType, orderGeo, coeffMatGeo, monoMatGeo);

      // solution interpolation
      const fullMatrix<double> *coeffMatSol, *monoMatSol;
      getInterpolationMat(parentType, order, coeffMatSol, monoMatSol);
      
      // set interpolation in view
      setInterpolationMatrices(parentType, *coeffMatSol, *monoMatSol,
                               *coeffMatGeo, *monoMatGeo);
    }
  }

  finalize(false);
  return true;
}


#else


bool PViewDataGModel::readCGNS(const std::pair<std::string,
                                               std::string> &solFieldName,
                               const std::string &fileName,  int index,
                               int fileIndex, int baseIndex,
                        const std::vector<std::vector<MVertex *> > &vertPerZone,
                        const std::vector<std::vector<MElement *> > &eltPerZone)
{
  return false;
}


#endif
