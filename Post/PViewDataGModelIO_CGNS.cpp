// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
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
                                int interpIndex,
                                ZoneSolutionTransfo &cgns2MshLag)
  {
    int cgnsErr;

    // read solution interpolation tranformation info
    char interpName[CGNS_MAX_STR_LEN];
    CGNS_ENUMT(ElementType_t) cgnsType;
    int order, orderTime;
    CGNS_ENUMT(InterpolationType_t) interpType;
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
    cgnsErr = cg_solution_lagrange_interpolation_size(cgnsType, order,
                                                      orderTime, &nbPt);
    if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);

    // read user interpolation points (parametric coordinates)
    std::vector<double> u(nbPt), v(nbPt), w(nbPt), t(orderTime + 1);
    cgnsErr = cg_solution_interpolation_points_read(
      fileIndex, baseIndex, familyIndex, interpIndex, u.data(), v.data(),
      w.data(), t.data());
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

    // compute transformation matrix from monomial to CGNS Lagrange
    // coefficients, i.e. the inverse transposed Vandermonde matrix of CGNS
    // interpolation points in the monomial basis
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
      cgnsErr =
        cg_nsolution_interpolation_read(fileIndex, baseIndex, iFam, &nbInterp);
      if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);
      if(nbInterp == 0) continue;

      // read family name
      char famName[CGNS_MAX_STR_LEN];
      int nbFamBC, nbGeoRef;
      cgnsErr = cg_family_read(fileIndex, baseIndex, iFam, famName, &nbFamBC,
                               &nbGeoRef);
      if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);

      // read element interpolation transformations
      ZoneSolutionTransfo &cgns2MshLag =
        allSolutionTransfo[std::string(famName)];
      cgns2MshLag.resize(MSH_MAX_NUM);
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

  void getSolutionDataNode(
    int zoneIndex, const std::vector<std::vector<MVertex *> > &vertPerZone,
    std::vector<cgsize_t> solEntSet, const std::vector<double> &data,
    stepData<double> *step, double &dataMin, double &dataMax)
  {
    // allocate data storage
    const int nbNode = solEntSet.size();
    step->resizeData(nbNode);

    // loop over vertices to store data and update bounds (faster here than in
    // finalize)
    for(int iNode = 0; iNode < nbNode; iNode++) {
      const cgsize_t nodeInd = solEntSet[iNode];
      const int nodeNum = vertPerZone[zoneIndex][nodeInd]->getNum();
      double *d = step->getData(nodeNum, true, 1);
      *d = data[iNode];
      step->setMin(std::min(step->getMin(), *d));
      step->setMax(std::max(step->getMax(), *d));
      dataMin = std::min(dataMin, *d);
      dataMax = std::max(dataMax, *d);
    }
  }

  void getSolutionDataElement(
    int zoneIndex, const std::vector<std::vector<MElement *> > &eltPerZone,
    std::vector<cgsize_t> solEntSet, const std::vector<double> &data,
    stepData<double> *step, double &dataMin, double &dataMax)
  {
    // allocate data storage
    const int nbElt = solEntSet.size();
    step->resizeData(nbElt);

    // loop over elements to store data and update bounds (faster here than in
    // finalize)
    for(int iElt = 0; iElt < nbElt; iElt++) {
      const cgsize_t eltInd = solEntSet[iElt];
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
                           const fullMatrix<double> *&coeffMat,
                           const fullMatrix<double> *&monoMat)
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
        coeffMat = nullptr;
        monoMat = nullptr;
      }
    }
  }

  void getSolutionDataElementNode(
    int zoneIndex, int order, const ZoneSolutionTransfo *zoneSolTransfo,
    const std::vector<std::vector<MElement *> > &eltPerZone,
    std::vector<cgsize_t> solEntSet, const std::vector<double> &data,
    stepData<double> *step, double &dataMin, double &dataMax,
    std::vector<std::pair<int, int> > &ordersByParentType)
  {
    // allocate data storage
    const int nbElt = solEntSet.size();
    step->resizeData(nbElt);

    // loop over elements
    int iStartEltData = 0;
    std::vector<bool> hasInterpolMat(100, false);
    for(int iElt = 0; iElt < nbElt; iElt++) {
      // get element type
      const cgsize_t eltInd = solEntSet[iElt];
      MElement *me = eltPerZone[zoneIndex][eltInd];
      const int eltNum = me->getNum();
      const int parentMshType = me->getType();
      const int orderGeo = me->getPolynomialOrder();
      ordersByParentType[parentMshType] = std::make_pair(orderGeo, order);
      int mshType = ElementType::getType(parentMshType, order, false);
      const int nbEltNode = ElementType::getNumVertices(mshType);

      // element node transformation if specified (CPEX0045)
      const fullMatrix<double> *transfoMat = nullptr;
      if((mshType != MSH_PNT) && (zoneSolTransfo != nullptr) &&
         (zoneSolTransfo->size() > 0)) {
        transfoMat = &((*zoneSolTransfo)[mshType]);
      }

      // values at element nodes for data read (source) and step data (dest.)
      double *eltData = const_cast<double *>(&(data[iStartEltData]));
      double *stepData = step->getData(eltNum, true, nbEltNode);

      // compute values at element nodes in step data
      if(transfoMat == nullptr) {
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

  int getEntInZone(int fileIndex, int baseIndex, int zoneIndex,
                   int zoneSolIndex, bool isStructured, int dim,
                   const cgsize_t *zoneEntSize, cgsize_t *solReadRange,
                   std::vector<cgsize_t> &solEntSet)
  {
    // compute range and number of values to read in solution
    cgsize_t nbVal = 0;
    if(isStructured) {
      for(int i = 0; i < dim; i++) {
        solReadRange[i] = 1;
        solReadRange[i + dim] = zoneEntSize[i];
      }
      if(dim == 2)
        nbVal = StructuredIndexing<2>::nbEntInRange(solReadRange);
      else if(dim == 3)
        nbVal = StructuredIndexing<3>::nbEntInRange(solReadRange);
    }
    else {
      solReadRange[0] = 1;
      solReadRange[1] = zoneEntSize[0];
      nbVal = UnstructuredIndexing::nbEntInRange(solReadRange);
    }

    // fill set of entities
    solEntSet.resize(nbVal);
    for(cgsize_t i = 0; i < nbVal; i++) solEntSet[i] = i;

    return 1;
  }

  int getEntInPtSet(int fileIndex, int baseIndex, int zoneIndex,
                    int zoneSolIndex, bool isStructured, int dim,
                    CGNS_ENUMT(PointSetType_t) ptSetType, cgsize_t ptSetSize,
                    const cgsize_t *zoneEntSize, cgsize_t *solReadRange,
                    std::vector<cgsize_t> &solEntSet)
  {
    int cgnsErr;

    // read point set
    std::vector<cgsize_t> ptSet;
    ptSet.resize(ptSetSize);
    cgnsErr = cg_sol_ptset_read(fileIndex, baseIndex, zoneIndex, zoneSolIndex,
                                ptSet.data());
    if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);

    // get number of values and entities to read in solution
    if(ptSetType == CGNS_ENUMV(PointRange)) {
      if(isStructured) {
        for(int i = 0; i < dim; i++) {
          solReadRange[i] = 1;
          solReadRange[i + dim] = ptSet[i + dim] - ptSet[i] + 1;
        }
        if(dim == 2) {
          cgsize_t nbVal = StructuredIndexing<2>::nbEntInRange(ptSet.data());
          solEntSet.resize(nbVal);
          StructuredIndexing<2>::entFromRange(ptSet.data(), zoneEntSize,
                                              solEntSet);
        }
        else if(dim == 3) {
          cgsize_t nbVal = StructuredIndexing<3>::nbEntInRange(ptSet.data());
          solEntSet.resize(nbVal);
          StructuredIndexing<3>::entFromRange(ptSet.data(), zoneEntSize,
                                              solEntSet);
        }
        else {
          Msg::Error("Dimension %i not supported in CGNS solution reader", dim);
          return false;
        }
      }
      else {
        solReadRange[0] = 1;
        solReadRange[1] = ptSet[1] - ptSet[0] + 1;
        cgsize_t nbVal = UnstructuredIndexing::nbEntInRange(ptSet.data());
        solEntSet.resize(nbVal);
        UnstructuredIndexing::entFromRange(ptSet.data(), solEntSet);
      }
    }
    else if(ptSetType == CGNS_ENUMV(PointList)) {
      solReadRange[0] = 1;
      solReadRange[1] = ptSet.size();
      if(isStructured) {
        const cgsize_t nbVal = ptSet.size() / dim;
        solEntSet.resize(nbVal);
        if(dim == 2) {
          StructuredIndexing<2>::entFromList(ptSet, zoneEntSize, solEntSet);
        }
        else if(dim == 3) {
          StructuredIndexing<3>::entFromList(ptSet, zoneEntSize, solEntSet);
        }
        else {
          Msg::Error("Dimension %i not supported in CGNS solution reader", dim);
          return false;
        }
      }
      else {
        solEntSet.resize(ptSet.size());
        UnstructuredIndexing::entFromList(ptSet, solEntSet);
      }
    }
    else {
      Msg::Warning("PointSetType %i not supported in CGNS solution reader",
                   ptSetType);
      return false;
    }

    return 1;
  }

  bool readZoneSolution(const std::pair<std::string, std::string> &solFieldName,
                        int fileIndex, int baseIndex, int zoneIndex,
                        int zoneSolIndex, PViewDataGModel::DataType dataType,
                        const ZoneSolutionTransfo *zoneSolTransfo,
                        const std::vector<std::vector<MVertex *> > &vertPerZone,
                        const std::vector<std::vector<MElement *> > &eltPerZone,
                        stepData<double> *step, double &dataMin,
                        double &dataMax,
                        std::vector<std::pair<int, int> > &ordersByParentType)
  {
    int cgnsErr;

    // check FlowSolution name
    char rawSolName[CGNS_MAX_STR_LEN];
    CGNS_ENUMT(GridLocation_t) location;
    cgnsErr = cg_sol_info(fileIndex, baseIndex, zoneIndex, zoneSolIndex,
                          rawSolName, &location);
    if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);
    if(std::string(rawSolName) != solFieldName.first) return true;

    // get zone dimension and type
    int dim;
    CGNS_ENUMT(ZoneType_t) zoneType;
    cgnsErr = cg_cell_dim(fileIndex, baseIndex, &dim);
    if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);
    cgnsErr = cg_zone_type(fileIndex, baseIndex, zoneIndex, &zoneType);
    if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);
    const bool isStructured = (zoneType == CGNS_ENUMV(Structured));

    // get total number of vertices and elements in zone
    char zoneName[CGNS_MAX_STR_LEN];
    cgsize_t zoneSize[9];
    cgnsErr = cg_zone_read(fileIndex, baseIndex, zoneIndex, zoneName, zoneSize);
    if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);

    // type and total number of entities (either vertices or elements) in zone
    const bool nodeOrEltData = (dataType == PViewDataGModel::NodeData);
    const cgsize_t *zoneEntSize = nodeOrEltData ? zoneSize :
                                  isStructured  ? zoneSize + dim :
                                                  zoneSize + 1;

    // get solution order
    int order = 1;
#ifdef HAVE_LIBCGNS_CPEX0045
    int orderTime;
    cgnsErr = cg_sol_interpolation_order_read(fileIndex, baseIndex, zoneIndex,
                                              zoneSolIndex, &order, &orderTime);
#endif

    // read point range if it exists, otherwise use all entities
    // (vertices/elements) in zone
    std::vector<cgsize_t> solEntSet;
    CGNS_ENUMT(PointSetType_t) ptSetType;
    cgsize_t ptSetSize;
    cgsize_t solReadRange[6];
    cgnsErr = cg_sol_ptset_info(fileIndex, baseIndex, zoneIndex, zoneSolIndex,
                                &ptSetType, &ptSetSize);
    if((cgnsErr != CG_NODE_NOT_FOUND) && (cgnsErr != CG_OK)) {
      return cgnsError(__FILE__, __LINE__, fileIndex);
    }
    if((cgnsErr == CG_NODE_NOT_FOUND) || (ptSetSize == 0)) { // no point range
      int err =
        getEntInZone(fileIndex, baseIndex, zoneIndex, zoneSolIndex,
                     isStructured, dim, zoneEntSize, solReadRange, solEntSet);
      if(err == 0) return 0;
    }
    else { // point set is specified
      int err = getEntInPtSet(fileIndex, baseIndex, zoneIndex, zoneSolIndex,
                              isStructured, dim, ptSetType, ptSetSize,
                              zoneEntSize, solReadRange, solEntSet);
      if(err == 0) return 0;
    }

    // if ElementNodeData (CPEX0045, only unstructured), read data size from
    // field (assuming no rind), otherwise use number of entities as data size
    cgsize_t dataSize = 0;
    cgsize_t solReadRangeMin[3] = {1, 1, 1};
    cgsize_t solReadRangeMax[3] = {0, 0, 0};
    if(dataType == PViewDataGModel::ElementNodeData) {
      int dataDim;
      cgsize_t solSize[3];
      cgnsErr = cg_sol_size(fileIndex, baseIndex, zoneIndex, zoneSolIndex,
                            &dataDim, solSize);
      if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);
      dataSize = solSize[0];
      solReadRangeMax[0] = solSize[0];
    }
    else {
      dataSize = solEntSet.size();
      const int indDim = isStructured ? dim : 1;
      // std::copy(solReadRange, solReadRange+indDim, solReadRangeMin);
      std::copy(solReadRange + indDim, solReadRange + 2 * indDim,
                solReadRangeMax);
    }

    // get number of fields in this FlowSolution
    int nbField;
    cgnsErr =
      cg_nfields(fileIndex, baseIndex, zoneIndex, zoneSolIndex, &nbField);
    if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);

    // get field data
    for(int iField = 1; iField <= nbField; iField++) {
      // field name
      CGNS_ENUMT(DataType_t) cgnsDataType;
      char rawFieldName[CGNS_MAX_STR_LEN];
      cgnsErr = cg_field_info(fileIndex, baseIndex, zoneIndex, zoneSolIndex,
                              iField, &cgnsDataType, rawFieldName);
      if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);
      if(std::string(rawFieldName) != solFieldName.second) continue;

      // read field data
      std::vector<double> data(dataSize);
      cgnsErr =
        cg_field_read(fileIndex, baseIndex, zoneIndex, zoneSolIndex,
                      rawFieldName, CGNS_ENUMV(RealDouble), solReadRangeMin,
                      solReadRangeMax, static_cast<void *>(data.data()));
      if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);

      // scan through data to populate step (possibly converting from custom
      // nodal set) and compute min/max (faster here than in finalize)
      if(dataType == PViewDataGModel::NodeData) {
        getSolutionDataNode(zoneIndex, vertPerZone, solEntSet, data, step,
                            dataMin, dataMax);
      }
      else if(dataType == PViewDataGModel::ElementData) {
        getSolutionDataElement(zoneIndex, eltPerZone, solEntSet, data, step,
                               dataMin, dataMax);
      }
      else if(dataType == PViewDataGModel::ElementNodeData) {
        getSolutionDataElementNode(zoneIndex, order, zoneSolTransfo, eltPerZone,
                                   solEntSet, data, step, dataMin, dataMax,
                                   ordersByParentType);
      }
    }

    return true;
  }

} // namespace

bool PViewDataGModel::readCGNS(
  const std::pair<std::string, std::string> &solFieldName,
  const std::string &fileName, int index, int fileIndex, int baseIndex,
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
    const ZoneSolutionTransfo *zoneSolTransfo = nullptr;
    cgnsErr = cg_goto(fileIndex, baseIndex, "Zone_t", iZone, "end");
    if(cgnsErr != CG_OK) err = cgnsError(__FILE__, __LINE__, fileIndex);
    char famName[CGNS_MAX_STR_LEN];
    cgnsErr = cg_famname_read(famName);
    if(cgnsErr != CG_NODE_NOT_FOUND) {
      if(cgnsErr == CG_OK) {
        auto it = allSolutionTransfo.find(std::string(famName));
        if(it != allSolutionTransfo.end()) zoneSolTransfo = &(it->second);
      }
      else
        err = cgnsError(__FILE__, __LINE__, fileIndex);
    }

    // get number of flow solutions in zone
    int nbZoneSol;
    cgnsErr = cg_nsols(fileIndex, baseIndex, iZone, &nbZoneSol);
    if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);

    // loop over solution fields in each zone
    for(int iZoneSol = 1; iZoneSol <= nbZoneSol; iZoneSol++) {
      bool ok =
        readZoneSolution(solFieldName, fileIndex, baseIndex, iZone, iZoneSol,
                         getType(), zoneSolTransfo, vertPerZone, eltPerZone,
                         _steps.back(), _min, _max, ordersByParentType);
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

bool PViewDataGModel::readCGNS(
  const std::pair<std::string, std::string> &solFieldName,
  const std::string &fileName, int index, int fileIndex, int baseIndex,
  const std::vector<std::vector<MVertex *> > &vertPerZone,
  const std::vector<std::vector<MElement *> > &eltPerZone)
{
  return false;
}

#endif
