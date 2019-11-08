// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshMessage.h"
#include "MVertex.h"
#include "MElement.h"
#include "BasisFactory.h"
#include "ElementType.h"
#include "CGNSCommon.h"
#include "CGNSConventions.h"
#include "CGNSZone.h"
#include "CGNSZoneStruct.h"
#include "CGNSZoneUnstruct.h"
#include "CGNSRead.h"

#if defined(HAVE_LIBCGNS)


namespace {


int evalMonomialBasis(int mshType, const fullMatrix<double> &uvw,
                      fullMatrix<double> &val)
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
  int nbPt = uvw.size1();
  if(parentType == TYPE_PNT) {
    val(0, 0) = 1.;
  }
  else if(parentType == TYPE_LIN) {
    for(int iPt = 0; iPt < nbPt; iPt++) {
      val(0, iPt) = 1.;
      for(int i = 1; i <= order; i++) val(i, iPt) = uvw(iPt, 0) * val(i-1, iPt); 
    }
  }
  else if(parentType == TYPE_TRI) {
    for(int iPt = 0; iPt < nbPt; iPt++) {
      int iSF = 0;
      for(int i = 0; i <= order; i++) {
        for (int j = 0; j <= i; j++) {
          const int &u = uvw(iPt, 0), &v = uvw(iPt, 1);
          val(iSF, iPt) = std::pow(u, i-j) * std::pow(v, j);
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
          const int &u = uvw(iPt, 0), &v = uvw(iPt, 1);
          val(iSF, iPt) = std::pow(u, i) * std::pow(v, j);
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
            const int &u = uvw(iPt, 0), &v = uvw(iPt, 1), &w = uvw(iPt, 2);
            val(iSF, iPt) = std::pow(u, i-j-k) * std::pow(v, k) *
                            std::pow(w, j);
            iSF++;
          }
        }
      }
    }
  }
  // else if(parentType == TYPE_PYR) {
  // }
  else if(parentType == TYPE_PRI) {
    for(int iPt = 0; iPt < nbPt; iPt++) {
      int iSF = 0;
      for(int i = 0; i <= order; i++) {
        for (int j = 0; j <= i; j++) {
          for (int k = 0; j <= order; k++) {
            const int &u = uvw(iPt, 0), &v = uvw(iPt, 1), &w = uvw(iPt, 2);
            val(iSF, iPt) = std::pow(u, i-j) * std::pow(v, j) * std::pow(w, k);  // TODO: to be clarified
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
            const int &u = uvw(iPt, 0), &v = uvw(iPt, 1), &w = uvw(iPt, 2);
            val(iSF, iPt) = std::pow(u, i) * std::pow(v, j) * std::pow(w, k);
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
                             int interpIndex,
                             std::vector<fullMatrix<double> > &cgns2MshLag)
{
  int cgnsErr;

  // read element interpolation tranformation info
  char interpName[CGNS_MAX_STR_LEN];
  ElementType_t cgnsType;
  cgnsErr = cg_element_interpolation_read(fileIndex, baseIndex, familyIndex,
                                          interpIndex, interpName, &cgnsType);
  if(cgnsErr != CG_OK) return cgnsError();

  // get number of user interpolation points
  int nbPt;
  cgnsErr = cg_element_lagrange_interpolation_size(cgnsType, &nbPt);
  if(cgnsErr != CG_OK) return cgnsError();

  // read user interpolation points (parametric coordinates)
  std::vector<double> u(nbPt), v(nbPt), w(nbPt);
  cgnsErr = cg_element_interpolation_points_read(fileIndex, baseIndex,
                                                 familyIndex, interpIndex,
                                                 u.data(), v.data(), w.data());
  if(cgnsErr != CG_OK) return cgnsError();
  
  // get Gmsh interpolation points
  const int mshType = cgns2MshEltType(cgnsType);
  const int dim = ElementType::getDimension(mshType);
  const nodalBasis *basis = BasisFactory::getNodalBasis(mshType);
  const fullMatrix<double> &mshPts = basis->getReferenceNodes();
  if(nbPt != mshPts.size1()) {
    Msg::Error("Internal error: number of interpolation points is different "
                "between CGNS and Gmsh for Gmsh element %i (parent type %i)",
                mshType, ElementType::getParentType(mshType));
    return 0;
  }

  // compute transformation matrix from monomial to CGNS Lagrange coefficients,
  // i.e. the inverse transposed Vandermonde matrix of CGNS interpolation points
  // in the monomial basis
  fullMatrix<double> cgnsPts(nbPt, dim);
  for(int iPt = 0; iPt < nbPt; iPt++) {
    cgnsPts(iPt, 0) = u[iPt];
    if(dim > 1) cgnsPts(iPt, 1) = v[iPt];
    if(dim > 2) cgnsPts(iPt, 2) = w[iPt];
  }
  fullMatrix<double> mono2CGNSLag(nbPt, nbPt);
  evalMonomialBasis(mshType, cgnsPts, mono2CGNSLag);
  mono2CGNSLag.invertInPlace();

  // evaluate CGNS Lagrange base functions at Gmsh points
  fullMatrix<double> monoVal(nbPt, nbPt), lagVal;
  evalMonomialBasis(mshType, mshPts, monoVal);
  mono2CGNSLag.mult(monoVal, lagVal);

  // transformation matrix from CGNS to Gmsh Lagrange coefficients
  lagVal.transposeInPlace();
  cgns2MshLag[cgnsType] = lagVal;

  return 1;
}


}  // namespace


double readScale()
{
  double scale = 1.;

  MassUnits_t mass;
  LengthUnits_t length;
  TimeUnits_t time;
  TemperatureUnits_t temperature;
  AngleUnits_t angle;
  cg_units_read(&mass, &length, &time, &temperature, &angle);

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

  return scale;
}


int readHOPointInfo(int fileIndex, int baseIndex,
                    std::map<std::string,
                             std::vector<fullMatrix<double> > > &pointTransfo)
{
  int cgnsErr;

  // read number of families
  int nbFam;
  cgnsErr = cg_nfamilies(fileIndex, baseIndex, &nbFam);
  if(cgnsErr != CG_OK) return cgnsError();

  // sweep over families
  for(int iFam = 1; iFam <= nbFam; iFam++) {
    // read number of element interpolation transformations
    int nbInterp;
    cgnsErr = cg_nelement_interpolation_read(fileIndex, baseIndex, iFam,
                                             &nbInterp);
    if(cgnsErr != CG_OK) return cgnsError();
    if(nbInterp == 0) continue;

    // TODO: read family name
    std::string famName = "";

    // read element interpolation transformations
    std::vector<fullMatrix<double> > &cgns2MshLag = pointTransfo[famName];
    cgns2MshLag.resize(NofValidElementTypes);
    for(int iInterp = 1; iInterp <= nbInterp; iInterp++) {
      int err = readElementInterpolation(fileIndex, baseIndex, iFam, iInterp,
                                         cgns2MshLag);
      if(err == 0) return 0;
    }
  }

  return 1;
}


int createZones(int fileIndex, int baseIndex, int meshDim,
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
    if(cgnsErr != CG_OK) return cgnsError();
    
    // create zone
    int err;
    if (zoneType == Structured) {
      if(meshDim == 2) {
        allZones[iZone] = new CGNSZoneStruct<2>(fileIndex, baseIndex, iZone,
                                                meshDim, startNode, err);
      }
      if(meshDim == 3) {
        allZones[iZone] = new CGNSZoneStruct<3>(fileIndex, baseIndex, iZone,
                                                meshDim, startNode, err);
      }
    }
    else if (zoneType == Unstructured) {
      allZones[iZone] = new CGNSZoneUnstruct(fileIndex, baseIndex, iZone,
                                             meshDim, startNode, err);
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


#endif // HAVE_LIBCGNS
