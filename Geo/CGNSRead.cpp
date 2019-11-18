// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshMessage.h"
#include "MVertex.h"
#include "MElement.h"
#include "BergotBasis.h"
#include "BasisFactory.h"
#include "ElementType.h"
#include "GEntity.h"
#include "CGNSCommon.h"
#include "CGNSConventions.h"
#include "CGNSZone.h"
#include "CGNSZoneStruct.h"
#include "CGNSZoneUnstruct.h"
#include "CGNSRead.h"

#if defined(HAVE_LIBCGNS)


namespace {


#ifdef HAVE_LIBCGNS_CPEX0045


int evalMonomialBasis(int mshType, const std::vector<double> &u,
                      const std::vector<double> &v,
                      const std::vector<double> &w, fullMatrix<double> &val)
{
  // get parent type and order
  const int parentType = ElementType::getParentType(mshType);
  const int order = ElementType::getOrder(mshType);
  
  // get serendipity
  const int serend = ElementType::getSerendipity(mshType);
  if(serend > 1) {
    Msg::Error("Serendipity elements are not supported in CPEX0045 mode in "
               "CGNS reader");
    return 0;
  }

  // compute values of monomials at given points
  int nbPt = u.size();
  if(parentType == TYPE_PNT) {
    val(0, 0) = 1.;
  }
  else if(parentType == TYPE_LIN) {
    for(int iPt = 0; iPt < nbPt; iPt++) {
      val(0, iPt) = 1.;
      for(int i = 1; i <= order; i++) val(i, iPt) = u[iPt] * val(i-1, iPt); 
    }
  }
  else if(parentType == TYPE_TRI) {
    for(int iPt = 0; iPt < nbPt; iPt++) {
      int iSF = 0;
      for(int i = 0; i <= order; i++) {
        for (int j = 0; j <= i; j++) {
          val(iSF, iPt) = std::pow(u[iPt], i-j) * std::pow(v[iPt], j);
          iSF++;
        }
      }
    }
  }
  else if(parentType == TYPE_QUA) {
    for(int iPt = 0; iPt < nbPt; iPt++) {
      int iSF = 0;
      for(int i = 0; i <= order; i++) {
        for (int j = 0; j <= order; j++) {
          val(iSF, iPt) = std::pow(u[iPt], i) * std::pow(v[iPt], j);
          iSF++;
        }
      }
    }
  }
  else if(parentType == TYPE_TET) {
    for(int iPt = 0; iPt < nbPt; iPt++) {
      int iSF = 0;
      for(int i = 0; i <= order; i++) {
        for (int j = 0; j <= i; j++) {
          for (int k = 0; k <= i-j; k++) {
            val(iSF, iPt) = std::pow(u[iPt], i-j-k) * std::pow(v[iPt], k) *
                            std::pow(w[iPt], j);
            iSF++;
          }
        }
      }
    }
  }
  else if(parentType == TYPE_PYR) {
    int nbSF = ElementType::getNumVertices(mshType);
    BergotBasis bb(order);
    for(int iPt = 0; iPt < nbPt; iPt++) {
      double oneVal[385];
      const double ww = 0.5 * (w[iPt] + 1.);  // use Gmsh coord for BergotBasis 
      bb.f(u[iPt], v[iPt], ww, oneVal);
      for(int iSF = 0; iSF < nbSF; iSF++) val(iSF, iPt) = oneVal[iSF];
    }
  }
  else if(parentType == TYPE_PRI) {
    for(int iPt = 0; iPt < nbPt; iPt++) {
      int iSF = 0;
      for(int i = 0; i <= order; i++) {
        for (int j = 0; j <= i; j++) {
          for (int k = 0; k <= order; k++) {
            val(iSF, iPt) = std::pow(u[iPt], i-j) * std::pow(v[iPt], j) * std::pow(w[iPt], k);  // TODO: to be clarified
            iSF++;
          }
        }
      }
    }
  }
  else if(parentType == TYPE_HEX) {
    for(int iPt = 0; iPt < nbPt; iPt++) {
      int iSF = 0;
      for(int i = 0; i <= order; i++) {
        for (int j = 0; j <= order; j++) {
          for (int k = 0; k <= order; k++) {
            val(iSF, iPt) = std::pow(u[iPt], i) * std::pow(v[iPt], j) * std::pow(w[iPt], k);
            iSF++;
          }
        }
      }
    }
  }
  else {
    Msg::Error("Element of parent type %i is not supported in CPEX0045 mode "
               "in CGNS reader", parentType);
    return 0;
  }

  return 1;
}


int readElementInterpolation(int fileIndex, int baseIndex, int familyIndex,
                             int interpIndex, ZoneEltNodeTransfo &cgns2MshLag)
{
  int cgnsErr;

  // read element interpolation tranformation info
  char interpName[CGNS_MAX_STR_LEN];
  ElementType_t cgnsType;
  cgnsErr = cg_element_interpolation_read(fileIndex, baseIndex, familyIndex,
                                          interpIndex, interpName, &cgnsType);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);

  // get number of user interpolation points
  int nbPt;
  cgnsErr = cg_element_lagrange_interpolation_size(cgnsType, &nbPt);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);

  // read user interpolation points (parametric coordinates)
  std::vector<double> u(nbPt), v(nbPt), w(nbPt);
  cgnsErr = cg_element_interpolation_points_read(fileIndex, baseIndex,
                                                 familyIndex, interpIndex,
                                                 u.data(), v.data(), w.data());
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);
  
  // get Gmsh interpolation points
  const int mshType = cgns2MshEltType(cgnsType);
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


}  // namespace


int readScale(int fileIndex, int baseIndex, double &scale)
{
  int cgnsErr;
  
  scale = 1.;

  MassUnits_t mass;
  LengthUnits_t length;
  TimeUnits_t time;
  TemperatureUnits_t temperature;
  AngleUnits_t angle;
  cgnsErr = cg_goto(fileIndex, baseIndex, "end");
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);
  cgnsErr = cg_units_read(&mass, &length, &time, &temperature, &angle);
  if(cgnsErr == CG_NODE_NOT_FOUND) {
    Msg::Info("Length unit in CGNS file not defined, therefore not rescaling");
    return 1.;
  }
  else if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);

  switch(length) {
  case Centimeter:
    Msg::Info("Length unit in CGNS file is cm, rescaling");
    scale = 0.01;
    break;
  case Millimeter:
    Msg::Info("Length unit in CGNS file is mm, rescaling");
    scale = 0.001;
    break;
  case Foot:
    Msg::Info("Length unit in CGNS file is feet, rescaling");
    scale = 0.3048;
    break;
  case Inch:
    Msg::Info("Length unit in CGNS file is inch, rescaling");
    scale = 0.0254;
    break;
  case Meter:
    Msg::Info("Length unit in CGNS file is meter, not rescaling");
    break;
  case CG_Null:
  case CG_UserDefined:
  default:
    Msg::Info("Length unit in CGNS file not defined, therefore not rescaling");
    break;
  }

  return 1;
}


int readEltNodeTransfo(int fileIndex, int baseIndex,
                       Family2EltNodeTransfo &allEltNodeTransfo)
{
#ifdef HAVE_LIBCGNS_CPEX0045
  int cgnsErr;

  // read number of families
  int nbFam;
  cgnsErr = cg_nfamilies(fileIndex, baseIndex, &nbFam);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);

  // sweep over families
  for(int iFam = 1; iFam <= nbFam; iFam++) {
    // read number of element interpolation transformations
    int nbInterp;
    cgnsErr = cg_nelement_interpolation_read(fileIndex, baseIndex, iFam,
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
    ZoneEltNodeTransfo &cgns2MshLag = allEltNodeTransfo[std::string(famName)];
    cgns2MshLag.resize(NofValidElementTypes);
    for(int iInterp = 1; iInterp <= nbInterp; iInterp++) {
      int err = readElementInterpolation(fileIndex, baseIndex, iFam, iInterp,
                                         cgns2MshLag);
      if(err == 0) return 0;
    }
  }

  return 1;
#else
  return 1;
#endif
}


int createZones(int fileIndex, int baseIndex, int meshDim,
                const Family2EltNodeTransfo &allEltNodeTransfo,
                std::vector<CGNSZone *> &allZones,
                std::map<std::string, int> &name2Zone)
{
  const int nbZone = allZones.size() - 1;
  int cgnsErr;

  // sweep over zones
  cgsize_t startNode = 0;
  for(int iZone = 1; iZone <= nbZone; iZone++) {
    // read zone type
    ZoneType_t zoneType;
    cgnsErr = cg_zone_type(fileIndex, baseIndex, iZone, &zoneType);
    if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);
    
    // create zone
    int err;
    if (zoneType == Structured) {
      if(meshDim == 2) {
        allZones[iZone] = new CGNSZoneStruct<2>(fileIndex, baseIndex, iZone,
                                                meshDim, startNode,
                                                allEltNodeTransfo, err);
      }
      if(meshDim == 3) {
        allZones[iZone] = new CGNSZoneStruct<3>(fileIndex, baseIndex, iZone,
                                                meshDim, startNode,
                                                allEltNodeTransfo, err);
      }
    }
    else if (zoneType == Unstructured) {
      allZones[iZone] = new CGNSZoneUnstruct(fileIndex, baseIndex, iZone,
                                             meshDim, startNode,
                                             allEltNodeTransfo, err);
    }
    if(err == 0) return 0;

    // helper variables
    startNode += allZones[iZone]->nbNode();
    name2Zone[allZones[iZone]->name()] = iZone;
  }

  // read interface and periodicity info
  for(int iZone = 1; iZone <= nbZone; iZone++) {
      allZones[iZone]->readConnectivities(name2Zone, allZones);
  }

  return 1;
}


void setPeriodicityInEntities(const std::vector<CGNSZone *> &allZones)
{
  // data structure keeping track of connections between entities to avoid
  // two-way connections
  typedef std::set<std::pair<GEntity *, GEntity *> > EntConnect;
  EntConnect entCon;

  // loop over zones
  for(std::size_t iZone = 1; iZone < allZones.size(); iZone++) {
    CGNSZone *zone = allZones[iZone];
    // loop over periodic connections
    for(int iPer = 0; iPer < zone->nbPerConnect(); iPer++) {
      // loop over slave and master vertices
      const std::vector<MVertex *> &slaveVert = zone->slaveVert(iPer);
      const std::vector<MVertex *> &masterVert = zone->masterVert(iPer);
      for(std::size_t iV = 0; iV < slaveVert.size(); iV++) {
        // get slave and master entities
        MVertex *sVert = slaveVert[iV], *mVert = masterVert[iV];
        GEntity *sEnt = sVert->onWhat(), *mEnt = mVert->onWhat();
        
        // skip if inverse connection already exists 
        if(entCon.find(std::make_pair(mEnt, sEnt)) != entCon.end()) continue;
        entCon.insert(std::make_pair(sEnt, mEnt));

        // store corresponding vertices and set mesh master & transfo if needed
        sEnt->correspondingVertices[sVert] = mVert;
        if(sEnt->getMeshMaster() == sEnt) {
          sEnt->setMeshMaster(mEnt, zone->perTransfo(iPer));
        }
      }
    }
  }
}


#endif // HAVE_LIBCGNS
