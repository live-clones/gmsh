// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// MZoneBoundary.cpp - Copyright (C) 2008 S. Guzik, C. Geuzaine, J.-F. Remacle

#include "GmshConfig.h"

#if defined(HAVE_LIBCGNS)

#define DEBUG_FaceT 0       // NBN: toggle reporting of face insertions

#include <iostream> // DBG
#include <limits> // ?

#include "MZoneBoundary.h"
#include "GmshMessage.h"

//--Types at local scope

enum {
  NormalSourceGeometry = 1,
  NormalSourceElement = 2
};


/*******************************************************************************
 *
 * class BCPatchIndex
 *
 * Purpose
 * =======
 *
 *   Keeps track of the BC patch index for each entity index.  Many entities
 *   may share the same patch index and this class enables multiple entities to
 *   share the same index.
 *
 ******************************************************************************/

class BCPatchIndex
{
  struct PatchData 
  {
    int index;
    std::vector<int> eTagVec;
    PatchData(int eTag1)
      : index(eTag1), eTagVec(1, eTag1)
    { }
  };

  typedef std::list<PatchData> PatchDataList;
  typedef PatchDataList::iterator PatchDataListIt;

  typedef std::map<int, PatchDataListIt> PatchMap;
  typedef PatchMap::value_type PatchMapVal;
  typedef PatchMap::iterator PatchMapIt;
  typedef std::pair<PatchMapIt, bool> PatchMapIns;

  // Data
  PatchDataList patchData;
  PatchMap patch;
  bool sharedPatch;

  PatchMapIt _add(const int eTag)
  {
    PatchMapIns insPatch = patch.insert(PatchMapVal(eTag, PatchDataListIt()));
    if(insPatch.second) {
      insPatch.first->second =
        patchData.insert(patchData.end(), PatchData(eTag));
    }
    return insPatch.first;
  }

 public:

  BCPatchIndex()
    : sharedPatch(false)
  { }

  // Add an entity tag
  void add(const int eTag) { _add(eTag); }

  // Add two entity tags which must be given the same patch index
  void addPair(const int eTag1, const int eTag2)
  {
    sharedPatch = true;
    PatchMapIt patch1 = _add(eTag1);
    PatchMapIt patch2 = _add(eTag2);
    if(patch1->second != patch2->second) {
      PatchData &PD1 = *(patch1->second);
      PatchData &PD2 = *(patch2->second);
      const int nTag = PD2.eTagVec.size();
      for(int iTag = 0; iTag != nTag; ++iTag) {
        // Move tag from PD2 to PD1
        const int tag = PD2.eTagVec[iTag];
        PD1.eTagVec.push_back(tag);
        // Update value in 'patch' for this tag
        if(tag != eTag2) patch[tag] = patch1->second;
      }
      patchData.erase(patch2->second);
      patch2->second = patch1->second;
    }
  }

  // Once all entity tags have been added, generate patch indices
  void generatePatchIndices()
  {
//     if(sharedPatch) {  // Don't renumber if not shared to preserve entity
//                        // numbers.  Mostly useful for debugging.
      int c = 0;
      for(PatchDataListIt pDIt = patchData.begin(); pDIt != patchData.end();
          ++pDIt) pDIt->index = c++;
//     }
  }

  // Get the patch index for an entity (generate patch indices first)
  int getIndex(const int eTag) { return patch[eTag]->index; }

};


/*******************************************************************************
 *
 * Routine updateBoVec
 *
 * Purpose
 * =======
 *
 *   This routine basically tries to determine the normal for each boundary
 *   vertex.  Attempts are made to get the normal from the geometry.  If this
 *   fails, an average of the relavent mesh elements is used.
 *
 *   Specializations exist for 2-D and 3-D.
 *
 *   If a vertex lies on a lower dimension entity (GVertex in 2-D, GVertex or
 *   GEdge in 3-D), multiple BC patches will be written in case the normals are
 *   different for the multiple GEdges (2-D) or GFaces (3-D) that connect to the
 *   vertex.  In 2-D, if the angle between the normals is less than (1deg?), the
 *   patches are merged.  This has not yet been implemented in 3D (see notes in
 *   the 3D specialization below).
 *
 *   Normally, BC patches are numbered based on the entities.  If entities are
 *   merged, class 'BCPatchIndex' is used to give the same patch index to
 *   multiple entities.
 *
 * I/O
 * ===
 *
 *   normalSource       - (I) source for normals
 *   vertex             - (I) vertex to add to zoneBoVec and to find the normal
 *                            at
 *   zoneIndex          - (I)
 *   vertIndex          - (I) index of the vertex in the zone
 *   faces              - (I) all boundary faces connected to the vertex
 *   zoneBoVec          - (O) updated with domain boundary information for the
 *                            vertex
 *   patch              - (O) record BC patch index for an entity
 *   warnNormFromElem   - (I) whether a warning about obtaining normals from
 *                            elements has already been given. 
 *                        (O) set to true if warning given in this call
 *
 * Notes
 * =====
 *
 *   - 'getNormalFromElements' is at the bottom.  In that case, normals are
 *     determined from the elements and not the geometry.
 *   - 'vertex' is the key to 'globalBoVertMap'.  It will not change so the
 *     const_cast used below is okay.
 *
 ******************************************************************************/

template <unsigned DIM, typename FaceT>
void updateBoVec
(const int normalSource, const MVertex *const vertex, const int zoneIndex,
 const int vertIndex,
 const CCon::FaceVector<typename MZoneBoundary<DIM>::template
 GlobalVertexData<FaceT>::FaceDataB> &faces, ZoneBoVec &zoneBoVec,
 BCPatchIndex &patch, bool &warnNormFromElem);


/*******************************************************************************
 *
 * Routine updateBoVec - SPECIALIZED for 2D
 *
 ******************************************************************************/

//--"Contained" routines


/*==============================================================================
 *
 * Routine edge_normal
 *
 * Purpose
 * =======
 *
 *   Gives the edge normal.  Used only by routine updateBoVec<2, MEdge>.
 *
 * I/O
 * ===
 *
 *   vertex             - (I) The vertex to find the normal at
 *   zoneIndex          - (I) Zone being worked on
 *   edge               - (I) The geometry edge upon which the vertex resides
 *                            and from which the normal will be determined
 *   faces              - (I) All faces on the boundary connected to 'vertex'
 *   boNormal           - (O) The normal to the boundary face (edge in 2D)
 *   onlyFace           - (I) If >= 0, only use this face to determine the
 *                            interior vertex and normal to the mesh plane.
 *   returns            - (O) 0 - success
 *                            1 - no parameter found on edge for vertex
 *
 *============================================================================*/

int edge_normal
(const MVertex *const vertex, const int zoneIndex, const GEdge *const gEdge,
 const CCon::FaceVector<MZoneBoundary<2>::GlobalVertexData<MEdge>::FaceDataB>
 &faces, SVector3 &boNormal, const int onlyFace = -1)
{

  double par=0.0;
  // Note: const_cast used to match MVertex.cpp interface
  if(!reparamMeshVertexOnEdge(vertex, gEdge, par)) return 1;

  const SVector3 tangent(gEdge->firstDer(par));
                                        // Tangent to the boundary face
  SPoint3 interior(0., 0., 0.);         // An interior point
  SVector3 meshPlaneNormal(0.);         // This normal is perpendicular to the
                                        // plane of the mesh

  // The interior point and mesh plane normal are computed from all elements in
  // the zone.
  int cFace = 0;
  int iFace = 0;
  int nFace = faces.size();
  if ( onlyFace >= 0 ) {
    iFace = onlyFace;
    nFace = onlyFace + 1;
  }
  for(; iFace != nFace; ++iFace) {
    if(faces[iFace].zoneIndex == zoneIndex) {
      ++cFace;
      interior += faces[iFace].parentElement->barycenter();
      // Make sure all the planes go in the same direction
      //**Required?
      SVector3 mpnt = faces[iFace].parentElement->getFace(0).normal();
      if(dot(mpnt, meshPlaneNormal) < 0.) mpnt.negate();
      meshPlaneNormal += mpnt;
    }
  }
  interior /= cFace;
  // Normal to the boundary edge (but unknown direction)
  boNormal = crossprod(tangent, meshPlaneNormal);
  boNormal.normalize();
  // Direction vector from vertex to interior (inwards).  The normal should
  // point in the same direction.
  if(dot(boNormal, SVector3(vertex->point(), interior)) < 0.)
    boNormal.negate();
  return 0;

}


/*==============================================================================
 *
 * Routine updateBoVec<2, MEdge>
 *
 *============================================================================*/

template <>
void updateBoVec<2, MEdge>
(const int normalSource, const MVertex *const vertex, const int zoneIndex,
 const int vertIndex,
 const CCon::FaceVector<MZoneBoundary<2>::GlobalVertexData<MEdge>::FaceDataB>
 &faces, ZoneBoVec &zoneBoVec, BCPatchIndex &patch, bool &warnNormFromElem)
{

  GEntity *ent;
  if(normalSource == NormalSourceElement) goto getNormalFromElements;
  ent = vertex->onWhat();
  if(ent == 0) {
    goto getNormalFromElements;
    // No entity: try to find a normal from the faces
  }
  else {
    switch(ent->dim()) {
    case 0:

/*--------------------------------------------------------------------*
 * In this case, there are possibly two GEdges from this zone
 * connected to the vertex.  If the angle between the two edges is
 * significant, the BC patch will be split and this vertex will be
 * written in both patches with different normals.  If the angle is
 * small, or only one GEdge belongs to this zone, then the vertex will
 * only be written to one patch.
 *--------------------------------------------------------------------*/

      {
        // Get the edge entities that are connected to the vertex
        std::list<GEdge*> gEdgeList = ent->edges();
        // Find edge entities that are connected to elements in the zone
        std::vector<std::pair<GEdge*, int> > useGEdge;
        const int nFace = faces.size();
        for(int iFace = 0; iFace != nFace; ++iFace) {
          if(zoneIndex == faces[iFace].zoneIndex) {
            MEdge mEdge = faces[iFace].parentElement->getEdge
                (faces[iFace].parentFace);
            // Get the other vertex on the mesh edge.
            MVertex *vertex2 = mEdge.getMinVertex();
            if(vertex2 == vertex) vertex2 = mEdge.getMaxVertex();
            // Check if the entity associated with vertex2 is a line and
            // is also connected to vertex.  If so, add it to the container of
            // edge entities that will be used to determine the normal
            GEntity *const ent2 = vertex2->onWhat();
            if(ent2->dim() == 1) {
              useGEdge.push_back(std::pair<GEdge*, int>
                                 (static_cast<GEdge*>(ent2), iFace));
            }
          }
        }

//--'useGEdge' now contains the edge entities that will be used to determine
//--the normals

        switch(useGEdge.size()) {

        case 0:
//           goto getNormalFromElements;
          // We probably don't want BC data if none of the faces attatched to
          // this vertex and in this zone are on the boundary.
          break;

        case 1:
          {
            const GEdge *const gEdge =
              static_cast<const GEdge*>(useGEdge[0].first);
            SVector3 boNormal;
            if(edge_normal(vertex, zoneIndex, gEdge, faces, boNormal))
               goto getNormalFromElements;
            zoneBoVec.push_back(VertexBoundary(zoneIndex, gEdge->tag(),
                                               boNormal,
                                               const_cast<MVertex*>(vertex),
                                               vertIndex));
            patch.add(gEdge->tag());
          }
          break;

        case 2:
          {
            // Get the first normal
            const GEdge *const gEdge1 =
              static_cast<const GEdge*>(useGEdge[0].first);
            SVector3 boNormal1;
            if(edge_normal(vertex, zoneIndex, gEdge1, faces, boNormal1,
                           useGEdge[0].second))
              goto getNormalFromElements;

            // Get the second normal
            const GEdge *const gEdge2 =
              static_cast<const GEdge*>(useGEdge[1].first);
            SVector3 boNormal2;
            if(edge_normal(vertex, zoneIndex, gEdge2, faces, boNormal2,
                           useGEdge[1].second))
              goto getNormalFromElements;

            if(dot(boNormal1, boNormal2) < 0.98) {

//--Write 2 separate patches

              zoneBoVec.push_back(VertexBoundary(zoneIndex, gEdge1->tag(),
                                                 boNormal1,
                                                 const_cast<MVertex*>(vertex),
                                                 vertIndex));
              patch.add(gEdge1->tag());
              zoneBoVec.push_back(VertexBoundary(zoneIndex, gEdge2->tag(),
                                                 boNormal2,
                                                 const_cast<MVertex*>(vertex),
                                                 vertIndex));
              patch.add(gEdge2->tag());
            }
            else {

//--Write one patch

              boNormal1 += boNormal2;
              boNormal1 *= 0.5;
              zoneBoVec.push_back(VertexBoundary(zoneIndex, gEdge1->tag(),
                                                 boNormal1,
                                                 const_cast<MVertex*>(vertex),
                                                 vertIndex));
              patch.addPair(gEdge1->tag(), gEdge2->tag());
            }
          }
          break;

        default:
          Msg::Error("Internal error based on 2-D boundary assumptions (file "
                     "\'MZoneBoundary.cpp').  Boundary vertices may be "
                     "incorrect");
          break;
        }
      }
      break;
    case 1:

/*--------------------------------------------------------------------*
 * The vertex exists on an edge and belongs to only 1 BC patch.
 *--------------------------------------------------------------------*/

      {
        SVector3 boNormal;
        if(edge_normal(vertex, zoneIndex, static_cast<const GEdge*>(ent), faces,
                       boNormal))
          goto getNormalFromElements;
        zoneBoVec.push_back(VertexBoundary(zoneIndex, ent->tag(), boNormal,
                                           const_cast<MVertex*>(vertex),
                                           vertIndex));
        patch.add(ent->tag());
      }
      break;

    default:
      goto getNormalFromElements;
    }
  }
  return;

 getNormalFromElements: ;

/*--------------------------------------------------------------------*
 * Geometry information cannot be used - generate normals from the
 * elements
 *--------------------------------------------------------------------*/

  {
    if(warnNormFromElem && normalSource == 1) {
      Msg::Warning("Some or all boundary normals were determined from mesh "
                   "elements instead of from the geometry");
      warnNormFromElem = false;
    }
    // The mesh plane normal is computed from all elements attached to the
    // vertex
    SVector3 meshPlaneNormal(0.);       // This normal is perpendicular to the
                                        // plane of the mesh
    const int nFace = faces.size();
    for(int iFace = 0; iFace != nFace; ++iFace) {
      if(faces[iFace].zoneIndex == zoneIndex) {
      // Make sure all the planes go in the same direction
      //**Required?
        SVector3 mpnt = faces[iFace].parentElement->getFace(0).normal();
        if(dot(mpnt, meshPlaneNormal) < 0.) mpnt.negate();
        meshPlaneNormal += mpnt;
      }
    }
    // Sum the normals from each element.  The tangent is computed from all
    // faces in the zone attached to the vertex and is weighted by the length of
    // the edge.  Each tangent has to be converted independently into an
    // inwards-pointing normal.
    SVector3 boNormal(0.);
    for(int iFace = 0; iFace != nFace; ++iFace) {
      if(faces[iFace].zoneIndex == zoneIndex) {
        const SVector3 tangent = faces[iFace].parentElement->getEdge
          (faces[iFace].parentFace).tangent();
        // Normal to the boundary (unknown direction)
        SVector3 bnt = crossprod(tangent, meshPlaneNormal);
        // Inwards normal
        const SVector3 inwards(vertex->point(),
                               faces[iFace].parentElement->barycenter());
        if(dot(bnt, inwards) < 0.) bnt.negate();
        boNormal += bnt;
      }
    }
    boNormal.normalize();
    zoneBoVec.push_back(VertexBoundary(zoneIndex, 0, boNormal,
                                       const_cast<MVertex*>(vertex),
                                       vertIndex));
    patch.add(0);
  }
}


/*******************************************************************************
 *
 * Routine updateBoVec - SPECIALIZED for 3D
 *
 * Notes
 * =====
 *
 *   - Merging two entities into a single patch is more difficult in 3D because,
 *     while in 2D, edge entities are separated by a single vertex, in 3D
 *     entities are separated by a number of vertices, each of which may force
 *     splitting of the patch.  Merging of entities into a single patch has not
 *     yet been implemented, but the best way to accomplish this is probably to
 *     split all entities into separate patches and then record which pairs of
 *     entities cannot be merged.  Later, all others can be merged and
 *     'zoneBoVec' updated accordingly.
 *
 ******************************************************************************/

template <>
void updateBoVec<3, MFace>
(const int normalSource, const MVertex *const vertex, const int zoneIndex,
 const int vertIndex,
 const CCon::FaceVector<MZoneBoundary<3>::GlobalVertexData<MFace>::FaceDataB>
 &faces, ZoneBoVec &zoneBoVec, BCPatchIndex &patch, bool &warnNormFromElem)
{

  GEntity *ent;
  if(normalSource == NormalSourceElement) goto getNormalFromElements;
  ent = vertex->onWhat();
  if(ent == 0) {
    goto getNormalFromElements;
    // No entity: try to find a normal from the faces
  }
  else {
    switch(ent->dim()) {
    case 0:
    case 1:

/*--------------------------------------------------------------------*
 * In this case, there are possibly multiple GFaces from this zone
 * connected to the vertex.  One patch for each GFace will be written.
 *--------------------------------------------------------------------*/

      {

//--Get a list of face entities connected to 'ent'

        std::list<GFace*> gFaceList;
        switch(ent->dim()) {
        case 0:
          {
            std::list<GEdge*> gEdgeList = ent->edges();
            std::list<GFace*> gFaceList;
            for(std::list<GEdge*>::const_iterator gEIt = gEdgeList.begin();
                gEIt != gEdgeList.end(); ++gEIt) {
              std::list<GFace*> alist = (*gEIt)->faces();
              gFaceList.splice(gFaceList.end(), alist);
            }
            // Remove duplicates
            gFaceList.sort();
            gFaceList.unique();
          }
          break;
        case 1:
          gFaceList = ent->faces();
          break;
        }

//--Get a list of face entities connected to the 'vertex' that are also in the
//--zone

        std::list<const GFace*> useGFace;
        std::list<GEdge*> gEdgeList;
        const int nFace = faces.size();
        for(int iFace = 0; iFace != nFace; ++iFace) {
          if(zoneIndex == faces[iFace].zoneIndex) {
            bool matchedFace = false;
            MFace mFace = faces[iFace].parentElement->getFace
              (faces[iFace].parentFace);
            const int nVOnF = mFace.getNumVertices();
            int vertexOnF;              // The index of 'vertex' in the face
            for(int iVOnF = 0; iVOnF != nVOnF; ++iVOnF) {
              const MVertex *const vertex2 = mFace.getVertex(iVOnF);
              if(vertex == vertex2) vertexOnF = iVOnF;
              else {
                const GEntity *const ent2 = vertex2->onWhat();
                if(ent2->dim() == 2) {
                  matchedFace = true;
                  useGFace.push_back(static_cast<const GFace*>(ent2));
                  break;
                }
              }
            }
            // Triangle MElements are a total P.I.T.A.:
            // - If the original 'ent' is a vertex, one MVertex can be on the
            //   GVertex, and the other two on GEdges, and then the MElement is
            //   still on the GFace.
            // - If the original 'ent' is an edge, one MVertex can be on the
            //   original GEdge, another on a GVertex, and the final on another
            //   GEdge, and then the MElement is still on the GFace.  There is
            //   also the unlikely case where the two other MVertex are both on
            //   edges ... and the MElement is still on the GFace.
            if(!matchedFace && (3 == nVOnF)) {
              const MVertex *vertex2;
              const MVertex *vertex3;
              switch(vertexOnF) {
              case 0:
                vertex2 = mFace.getVertex(1);
                vertex3 = mFace.getVertex(2);
                break;
              case 1:
                vertex2 = mFace.getVertex(0);
                vertex3 = mFace.getVertex(2);
                break;
              case 2:
                vertex2 = mFace.getVertex(0);
                vertex3 = mFace.getVertex(1);
                break;
              }
              const GEntity *const ent2 = vertex2->onWhat();
              const GEntity *const ent3 = vertex3->onWhat();
              if(ent2->dim() == 1 && ent3->dim() == 1) {
                // Which GFace is bounded by edges ent2 and ent3?
                for(std::list<GFace*>::const_iterator gFIt = gFaceList.begin();
                    gFIt != gFaceList.end(); ++gFIt) {
                  gEdgeList = (*gFIt)->edges();
                  if((std::find(gEdgeList.begin(), gEdgeList.end(), ent2)
                      != gEdgeList.end()) &&
                     (std::find(gEdgeList.begin(), gEdgeList.end(), ent3)
                      != gEdgeList.end())) {
                    // Edges ent2 and ent3 bound this face
                    useGFace.push_back(*gFIt);
                    break;
                  }
                }
              }
              else if(ent->dim() == 1 && (ent2->dim() + ent3->dim() == 1)) {
                const GEntity *entCmp;
                if(ent2->dim() == 1) entCmp = ent2;
                else entCmp = ent3;
                // Which GFace is bounded by entCmp
                for(std::list<GFace*>::const_iterator gFIt = gFaceList.begin();
                    gFIt != gFaceList.end(); ++gFIt) {
                  gEdgeList = (*gFIt)->edges();
                  if(std::find(gEdgeList.begin(), gEdgeList.end(), entCmp)
                     != gEdgeList.end()) {
                    // Edge entCmp and the original edge bound this face
                    useGFace.push_back(*gFIt);
                    break;
                  }
                }
              }
            }  // Stupid triangles
          }  // End if face in zone
        }  // End loop over faces
        // Duplicates are a possibility, remove
        useGFace.sort();
        useGFace.unique();

//--'useGFace' now contains the face entities that connect to vertex.  A BC
//--patch will be written for each of them.

        for(std::list<const GFace*>::const_iterator gFIt = useGFace.begin();
            gFIt != useGFace.end(); ++gFIt) {

          SPoint2 par;
          if(!reparamMeshVertexOnFace(vertex, *gFIt, par))
            goto getNormalFromElements;  // :P  After all that!

          SVector3 boNormal = (*gFIt)->normal(par);
          SPoint3 interior(0., 0., 0.);
          int cFace = 0;
          const int nFace = faces.size();
          for(int iFace = 0; iFace != nFace; ++iFace) {
            if(faces[iFace].zoneIndex == zoneIndex) {
              ++cFace;
              interior += faces[iFace].parentElement->barycenter();
            }
          }
          interior /= cFace;
          if(dot(boNormal, SVector3(vertex->point(), interior)) < 0.)
            boNormal.negate();

          zoneBoVec.push_back(VertexBoundary(zoneIndex, (*gFIt)->tag(),
                                             boNormal,
                                             const_cast<MVertex*>(vertex),
                                             vertIndex));
          patch.add((*gFIt)->tag());
        }
      }
      break;
    case 2:

/*--------------------------------------------------------------------*
 * The vertex exists on a face and belongs to only 1 BC patch.
 *--------------------------------------------------------------------*/

      {
        const GFace *const gFace = static_cast<const GFace*>(ent);
        SPoint2 par;
        if(!reparamMeshVertexOnFace(vertex, gFace, par))
          goto getNormalFromElements;

        SVector3 boNormal = static_cast<const GFace*>(ent)->normal(par);
        SPoint3 interior(0., 0., 0.);
          int cFace = 0;
        const int nFace = faces.size();
        for(int iFace = 0; iFace != nFace; ++iFace) {
          if(faces[iFace].zoneIndex == zoneIndex) {
            ++cFace;
            interior += faces[iFace].parentElement->barycenter();
          }
        }
        interior /= cFace;
        if(dot(boNormal, SVector3(vertex->point(), interior)) < 0.)
          boNormal.negate();

        zoneBoVec.push_back(VertexBoundary(zoneIndex, gFace->tag(), boNormal,
                                           const_cast<MVertex*>(vertex),
                                           vertIndex));
        patch.add(gFace->tag());
      }
      break;
    default:
      goto getNormalFromElements;
    }
  }
  return;

 getNormalFromElements: ;

/*--------------------------------------------------------------------*
 * Geometry information cannot be used - generate normals from the
 * elements
 *--------------------------------------------------------------------*/

  {
    if(warnNormFromElem && normalSource == 1) {
      Msg::Warning("Some or all boundary normals were determined from mesh "
                   "elements instead of from the geometry");
      warnNormFromElem = false;
    }
    // Sum the normals from each element connected to the vertex and in the
    // zone.  Each normal has to be converted independently into an inwards-
    // pointing normal.
    //**Weight each normal by the area of the boundary element?
    SVector3 boNormal(0.);
    const int nFace = faces.size();
    for(int iFace = 0; iFace != nFace; ++iFace) {
      if(faces[iFace].zoneIndex == zoneIndex) {
        // Normal to the boundary (unknown direction)
        SVector3 bnt = faces[iFace].parentElement->getFace
          (faces[iFace].parentFace).normal();
        // Inwards normal
        const SVector3 inwards(vertex->point(),
                               faces[iFace].parentElement->barycenter());
        if(dot(bnt, inwards) < 0.) bnt.negate();
        boNormal += bnt;
      }
    }
    boNormal.normalize();
    zoneBoVec.push_back(VertexBoundary(zoneIndex, 0, boNormal,
                                       const_cast<MVertex*>(vertex),
                                       vertIndex));
    patch.add(0);
  }

}


/*******************************************************************************
 *
 * Routines from class MZoneBoundary
 *
 ******************************************************************************/


/*==============================================================================
 *
 * Routine: interiorBoundaryVertices
 *
 * Purpose
 * =======
 *
 *   Adds a zone to the class.  The boundary vertices from the zone are matched
 *   against existing vertices in the class and "currently known" connectivity
 *   for the zone is returned as output.  Records of boundary vertices with
 *   incomplete connectivity are maintained.
 *
 * I/O
 * ===
 *
 *   newZoneIndex       - (I) Index of the new zone (a unique index used to
 *                            internally label a zone
 *   mZone              - (I) A description of a zone processed using the
 *                            MZone class.
 *   zoneConnMap        - (O) Currently known connectivity for this zone
 *
 *============================================================================*/

template <unsigned DIM>
int MZoneBoundary<DIM>::interiorBoundaryVertices
(const int newZoneIndex, const MZone<DIM> &mZone, ZoneConnMap &zoneConnMap)
{

  if(mZone.boVertMap.size() == 0) return 1;
  zoneConnMap.clear();

  // Loop over all the boundary vertices in 'mZone'
  for(typename MZone<DIM>::BoVertexMap::const_iterator vMapIt =
        mZone.boVertMap.begin(); vMapIt != mZone.boVertMap.end(); ++vMapIt) {

//--Find or insert this vertex into the global map

//     bool debug = false;
//     if(vMapIt->first->x() == 1. && vMapIt->first->y() == 0.) {
//       std::cout << "Working with vertex(1, 0): " << vMapIt->first
//                 << " for zone " << newZoneIndex << std::endl;
//       debug = true;
//     }
    std::pair<typename GlobalBoVertexMap::iterator, bool> insGblBoVertMap =
      globalBoVertMap.insert(std::pair<const MVertex*, GlobalVertexData<FaceT> >
                             (vMapIt->first, GlobalVertexData<FaceT>()));
    GlobalVertexData<FaceT> &globalVertData = insGblBoVertMap.first->second;
                                        // Ref. to the global boundary vertex
                                        // data
    const ZoneVertexData<typename MZone<DIM>::BoFaceMap::const_iterator>
      &zoneVertData = vMapIt->second;   // Ref. to boundary vertex data for a
                                        // zone
    if(insGblBoVertMap.second) {

//--A new vertex was inserted

      // Copy faces
      const int nFace = zoneVertData.faces.size();
      int iCount=0;
      for(int iFace = 0; iFace != nFace; ++iFace) {

#if (0)
        // NBN: changing the member object for a pointer means 
        // we need to do the following in two steps (see below)

        globalVertData.faces.push_back
          (typename GlobalVertexData<FaceT>::FaceDataB
           (newZoneIndex, zoneVertData.faces[iFace]));

#else
        // Using FaceAllocator<T> with face2Pool, the std constructors 
        // are not called, so FaceDataB std members are incomplete.

        // By replacing the FaceT member with FaceT* we fix the issue of 
        // auto-deleting "un-constructed" containers.  Here, the simple 
        // data type (pointer) member is allocated in the ctor, then we
        // create and store its FaceT object once the FaceDataB object 
        // is safely in the container.
        //
        // Note: we must now make sure to delete these pointers.
        // See adjusted version of MZoneBoundary::clear();

        // Step 1: append new FaceDataB<> object
        typename GlobalVertexData<FaceT>::FaceDataB& tFDB = 
          globalVertData.faces.push_back
              (typename GlobalVertexData<FaceT>::FaceDataB
              (newZoneIndex, zoneVertData.faces[iFace]) );
        
        // Step 2: construct its internal face object
        tFDB.face = new FaceT(zoneVertData.faces[iFace]->first);

      #if (DEBUG_FaceT)
        if (! tFDB.face) {
          Msg::Info("MZoneBoundary<DIM>::interiorBoundaryVertices, failed to alloc face object");
        } else {
          int nv = tFDB.face->getNumVertices();
          Msg::Info("interiorBoundaryVertices: allocated FaceT object %5d with %d verts", ++iCount, nv);
        }
      #endif


#endif
      }

      // Copy information about the vertex in the zone
      globalVertData.zoneData.push_back
        (typename GlobalVertexData<FaceT>::ZoneData
         (zoneVertData.index, newZoneIndex));
    }
    else {

//--This vertex already exists and zone connectivity must be determined

      // Add to the zone connectivity
      const int nPrevZone = globalVertData.zoneData.size();
      for(int iPrevZone = 0; iPrevZone != nPrevZone; ++iPrevZone) {
        ZoneConnectivity &zoneConn =
          zoneConnMap[ZonePair(globalVertData.zoneData[iPrevZone].zoneIndex,
                               newZoneIndex)];
        zoneConn.vertexPairVec.push_back
          (ZoneConnectivity::VertexPair
           // const_cast okay, no changes to keys in 'globalBoVertMap'
           (const_cast<MVertex*>(insGblBoVertMap.first->first),
            globalVertData.zoneData[iPrevZone].zoneIndex,
            newZoneIndex,
            globalVertData.zoneData[iPrevZone].vertexIndex,
            zoneVertData.index));
      }

      // Update the list of faces attached to this vertex
      unsigned nGFace = globalVertData.faces.size();
                                        // This is the number of faces searched
                                        // from 'globalVertData'.  It will only
                                        // decrease if the size() is less.
                                        // Since a FaceVector swaps the last
                                        // element into the erased index, this
                                        // implies that if new faces are added,
                                        // then old ones deleted, some of the
                                        // faces from zoneVertData may also be
                                        // searched.  This is okay since they
                                        // are all unique.
      const typename MZone<DIM>::BoFaceMap::const_iterator *zFace =
        &zoneVertData.faces[0];
      for(int nZFace = zoneVertData.faces.size(); nZFace--;) {
        bool foundMatch = false;
        for(int iGFace = 0; iGFace != nGFace; ++iGFace) 
        {
          // NBN: face is now a pointer, so need to de-reference
        //if((*zFace)->first ==  globalVertData.faces[iGFace].face ) 
          if((*zFace)->first == *(globalVertData.faces[iGFace].face)) {
            foundMatch = true;
            // Faces match - delete from 'globalVertData'.
            globalVertData.faces.erase(iGFace);
            // Erasing from the FaceVector swaps the last element into this
            // index.  We only decrease nGFace if the size is less.
            nGFace = std::min(globalVertData.faces.size(), nGFace);
            break;
          }
        }
        if(!foundMatch) {
          // New face - add to 'globalVertData'
          globalVertData.faces.push_back
            (typename GlobalVertexData<FaceT>::FaceDataB(newZoneIndex, *zFace));
        }
        ++zFace;
      }

      // If there are no more faces, connectivity for this vertex is complete
      // and it may be deleted.
      if(globalVertData.faces.size() == 0) {
        globalBoVertMap.erase(insGblBoVertMap.first);
      }
      else {
        // Update the list of zones attached to this vertex
        globalVertData.zoneData.push_back
          (typename GlobalVertexData<FaceT>::ZoneData
           (zoneVertData.index, newZoneIndex));
      }
    }
  }  // End loop over boundary vertices

  return 0;

}


/*==============================================================================
 *
 * Routine: exteriorBoundaryVertices
 *
 * Purpose
 * =======
 *
 *   Writes out the remaining unconnected boundary vertices.  These are assumed
 *   to be at the extent of the domain.
 *
 * I/O
 * ===
 *
 *   normalSource       - (I) Source for normals if the are requested.
 *                            0 - do not obtain normals
 *                            1 - geometry
 *                            2 - elements
 *                            Note that if normals cannot be found from the
 *                            geometry, the elements will be used.
 *   zoneBoMap          - (O) boundary vertices for all zones.
 *
 * Notes
 * =====
 *
 *   - Should only be called after all zones have been added via
 *     'interior_boundary_vertices'
 *   - Unless normals are obtained from the geometry, all boundary vertices will
 *     be written to one patch
 *
 ******************************************************************************/

template <unsigned DIM>
int MZoneBoundary<DIM>::exteriorBoundaryVertices
(const int normalSource, ZoneBoVec &zoneBoVec)
{

  if(globalBoVertMap.size() == 0) return 1;

  zoneBoVec.clear();
  zoneBoVec.reserve(3*globalBoVertMap.size()/2);

  BCPatchIndex patch;                   // Provides a BC patch index for each
                                        // entity
  bool warnNormFromElem = true;         // A warning that normals were
                                        // determined from elements.  This
                                        // warning is only give once (after
                                        // which the flag is set to false)

  const typename GlobalBoVertexMap::const_iterator vMapEnd =
    globalBoVertMap.end();
  for(typename GlobalBoVertexMap::const_iterator vMapIt =
        globalBoVertMap.begin(); vMapIt != vMapEnd; ++vMapIt) {
    const int nZone = vMapIt->second.zoneData.size();
    for(int iZone = 0; iZone != nZone; ++iZone) {
      const typename GlobalVertexData<FaceT>::ZoneData &zoneData =
        vMapIt->second.zoneData[iZone]; // Ref. to data stored for this zone

//--Try to find an outwards normal for this vertex

      if(normalSource) {
        updateBoVec<DIM, FaceT>(normalSource, vMapIt->first, zoneData.zoneIndex,
                                zoneData.vertexIndex, vMapIt->second.faces,
                                zoneBoVec, patch, warnNormFromElem);
      }
      else {
        // Keys to 'globalBoVertMap' will not change so const_cast is okay.
        zoneBoVec.push_back(VertexBoundary(zoneData.zoneIndex, 0, SVector3(0.),
                                           const_cast<MVertex*>(vMapIt->first),
                                           zoneData.vertexIndex));
      }
    }
  }

  // If normals were written from the geometry, zoneBoVec currently stores
  // entities in bcPatchIndex.  Update with the actual patch index.  Why? -
  // because two entities may have been merged if the interface between them is
  // continuous.
  if(normalSource == NormalSourceGeometry) {
    patch.generatePatchIndices();
    const int nBoVert = zoneBoVec.size();
    for(int iBoVert = 0; iBoVert != nBoVert; ++iBoVert) {
      zoneBoVec[iBoVert].bcPatchIndex =
        patch.getIndex(zoneBoVec[iBoVert].bcPatchIndex);
    }
  }

  return 0;

}


/*******************************************************************************
 *
 * Specialization of constructor
 * MZoneBoundary<DIM>::GlobalVertexData<FaceT>::FaceDataB::FaceDataB()
 * - Note that these dummy constructors are only required by
 *   FaceAllocator<T>::set_offsets()
 *   [with T = MZoneBoundary<DIM>::GlobalVertexData<FaceT>::FaceDataB]
 *
 ******************************************************************************/

template<>
template<>
MZoneBoundary<2>::GlobalVertexData<MEdge>::FaceDataB::FaceDataB()
  : 
  //face(0, 0),         // NBN: replaced this MEdge object
    face(NULL),         // NBN: with a pointer to MEdge
    parentElement(0),   // NBN: also, init members
    parentFace(0),
    faceIndex(0),
    zoneIndex(0)
{ }

template<>
template<>
MZoneBoundary<3>::GlobalVertexData<MFace>::FaceDataB::FaceDataB()
   : 
  //face(0, 0, 0),      // NBN: replaced this MFace object
    face(NULL),         // NBN: with a pointer to MFace
    parentElement(0),   // NBN: also, init members
    parentFace(0),
    faceIndex(0),
    zoneIndex(0)
{ }


/*******************************************************************************
 *
 * Explicit instantiations of class MZoneBoundary
 *
 ******************************************************************************/

template class MZoneBoundary<2>;
template class MZoneBoundary<3>;

#endif
