// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Orientation of a surface mesh with respect to the underlying geometry; see
// the comment on orientMeshGFace in meshGFace.h for why this is needed.

#include "GmshMessage.h"
#include "GModel.h"
#include "GFace.h"
#include "MVertex.h"
#include "MElement.h"
#include "SPoint2.h"
#include "SVector3.h"
#include "meshGFace.h"
#include "boundaryLayersData.h"

static bool getGFaceNormalFromVert(GFace *gf, MElement *el, SVector3 &nf)
{
  bool found = false;
  for(std::size_t iElV = 0; iElV < el->getNumVertices(); iElV++) {
    MVertex *v = el->getVertex(iElV);
    SPoint2 param;
    if(v->onWhat() == gf && v->getParameter(0, param[0]) &&
       v->getParameter(1, param[1])) {
      nf = gf->normal(param);
      found = true;
      break;
    }
  }
  return found;
}

static bool getGFaceNormalFromBary(GFace *gf, MElement *el, SVector3 &nf)
{
  SPoint2 param(0., 0.);
  bool ok = true;
  for(std::size_t j = 0; j < el->getNumVertices(); j++) {
    SPoint2 p;
    // FIXME: use inexact reparam because some vertices might not be exactly on
    // the surface after the 3D Delaunay
    ok = reparamMeshVertexOnFace(el->getVertex(j), gf, p, false);
    if(!ok) break;
    param += p;
  }
  if(ok) {
    param *= 1.0 / el->getNumVertices();
    nf = gf->normal(param);
  }
  return ok;
}

static void getGFaceOrientation(GFace *gf, BoundaryLayerColumns *blc,
                                bool existBL, bool fromVert, int &orientNonBL,
                                int &orientBL)
{
  for(std::size_t iEl = 0; iEl < gf->getNumMeshElements(); iEl++) {
    MElement *e = gf->getMeshElement(iEl);
    const bool isBLEl =
      existBL && (blc->_toFirst.find(e) != blc->_toFirst.end());
    SVector3 nf;
    // Check only if orientation of BL/non-BL el. not already known
    if((!isBLEl && orientNonBL == 0) || (isBLEl && orientBL == 0)) {
      const bool found = fromVert ? getGFaceNormalFromVert(gf, e, nf) :
                                    getGFaceNormalFromBary(gf, e, nf);
      if(found) {
        SVector3 ne = e->getFace(0).normal();
        const int orient = (dot(ne, nf) > 0.) ? 1 : -1;
        if(isBLEl)
          orientBL = orient;
        else
          orientNonBL = orient;
      }
    }
    // Stop when orientation found for non-BL and BL el.
    if((orientNonBL != 0) && (orientBL != 0)) break;
  }
}

void orientMeshGFace::operator()(GFace *gf)
{
  if(!gf->getNumMeshElements()) return;

  gf->model()->setCurrentMeshEntity(gf);

  if(gf->getMeshMaster() != gf) {
    // It's not clear if periodic meshes should be orientated according to the
    // orientation of the underlying CAD surface. Since we don't reorient
    // periodic curve meshes, let's also not reorient surface meshes for
    // now. This has implications for high-order periodic meshes: see comment in
    // FixPeriodicMesh().
  }
  else if(gf->isFullyDiscrete() ||
          gf->geomType() == GEntity::BoundaryLayerSurface) {
    // Don't do anything
  }
  else {
    // In old versions we checked the orientation by comparing the orientation
    // of a line element on the boundary w.r.t. its connected surface
    // element. This is probably better than what follows, but
    // * it failed when the 3D Delaunay changes the 1D mesh (since we don't
    //    recover it yet)
    // * it failed with OpenCASCADE geometries, where surface orientions do not
    //   seem to be consistent with the orientation of the bounding edges

    // Now: orient surface elements w.r.t. normal to geometric model.
    // Assumes that originally, orientation is consistent among boundary layer
    // (BL) elements, and orientation is consistent among non-BL elements, but
    // BL and non-BL elements can be oriented differently

    // Determine whether there is a boundary layer (BL)
    BoundaryLayerColumns *blc = gf->getColumns();
    const bool existBL = !blc->_toFirst.empty();

    // Get orientation of BL and non-BL elements.
    // First, try to get normal to GFace from vertices.
    // If it fails, try to get normal to GFace from element barycenter
    int orientNonBL = 0, orientBL = existBL ? 0 : 1;
    getGFaceOrientation(gf, blc, existBL, true, orientNonBL, orientBL);
    if((orientNonBL == 0) || (orientBL == 0))
      getGFaceOrientation(gf, blc, existBL, false, orientNonBL, orientBL);

    // Exit if could not determine orientation of both non-BL el. and BL el.
    if((orientNonBL == 0) && (orientBL == 0)) {
      Msg::Warning("Could not orient mesh in surface %d", gf->tag());
      return;
    }

    // Reverse BL and non-BL elements if needed
    if(existBL) { // If there is a BL, test BL/non-BL elements
      if((orientNonBL == -1) || (orientBL == -1)) {
        for(std::size_t iEl = 0; iEl < gf->getNumMeshElements(); iEl++) {
          MElement *e = gf->getMeshElement(iEl);
          // If el. outside of BL...
          if(blc->_toFirst.find(e) == blc->_toFirst.end()) {
            // ... reverse if needed
            if(orientNonBL == -1) e->reverse();
          }
          else { // If el. in BL ... reverse if needed
            if(orientBL == -1) e->reverse();
          }
        }
      }
    }
    else { // If no BL, reverse all elements if needed
      if(orientNonBL == -1) {
        for(std::size_t iEl = 0; iEl < gf->getNumMeshElements(); iEl++)
          gf->getMeshElement(iEl)->reverse();
      }
    }
  }

  // Apply user-specified mesh orientation constraints
  if(gf->meshAttributes.reverseMesh) {
    for(std::size_t k = 0; k < gf->getNumMeshElements(); k++)
      gf->getMeshElement(k)->reverse();
  }
}