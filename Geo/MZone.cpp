// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// MZone.cpp - Copyright (C) 2008 S. Guzik, C. Geuzaine, J.-F. Remacle

#include <iostream> // DBG
#include "MZone.h"

/*==============================================================================
 * Forward declarations
 *============================================================================*/

template <unsigned DIM, int N = DimTr<DIM>::numElemTypes>
struct ParseEntity;


/*******************************************************************************
 *
 * Routines from class MZone
 *
 ******************************************************************************/


/*==============================================================================
 *
 * Routine: add_elements_in_entities
 *
 * Purpose
 * =======
 *
 *   Adds all (or only those of the right partition) elements in a container of
 *   entities to the zone.
 *
 * I/O
 * ===
 *
 *   <Ent>              - The specific type of entity
 *   <EntIter>          - The type of iterator for the entities
 *   begin              - (I) Iterator to first entity
 *   end                - (I) Iterator to last entity
 *   partition          - (I) >  0 - only add elements of this partition to the
 *                                   zone
 *                            = -1 - add all elements to the zone (default
 *                                   value)
 *
 *============================================================================*/

template <unsigned DIM>
template <typename EntIter>
void MZone<DIM>::add_elements_in_entities
(EntIter begin, EntIter end, const int partition)
{

  // Check the Ent and EntIter types
  // NOTE:  If the compiler sent you here, you're using an invalid entity as a
  // template parameter and/or and invalid iterator.  See struct
  // 'ValidEntityIterator' in 'MZone.h' for valid types
//   typedef typename ValidEntityIterator<Ent, typename EntIter::value_type>
//     ::Type Check;
  typedef typename DimTr<DIM>::EntityT Ent;

  // Find the neighbours of each vertex, edge, and face
  for(EntIter itEnt = begin; itEnt != end; ++itEnt) {
    ParseEntity<DIM>::eval(static_cast<Ent*>(*itEnt), boFaceMap, elemVec,
                           vertMap, zoneElemConn, partition);
  }

}


/*==============================================================================
 *
 * Routine: add_elements_in_entity
 *
 * Purpose
 * =======
 *
 *   Adds all (or only those of the right partition) elements in a single entity
 *   to the zone.
 *
 * I/O
 * ===
 *
 *   entity             - (I) Pointer to the entity
 *   partition          - (I) >  0 - only add elements of this partition to the
 *                                   zone
 *                            = -1 - add all elements to the zone (default
 *                                   value)
 *
 * Notes
 * =====
 *
 *   - The entity pointer must be of a specific type (not a base class).
 *
 *============================================================================*/

template <unsigned DIM>
template <typename EntPtr>
void MZone<DIM>::add_elements_in_entity
(EntPtr entity, const int partition)
{

//   // Check the type of EntPtr (it must not be GEntity*)
//   // NOTE:  If the compiler sent you here, you're using an invalid entity as a
//   // pointer.  See struct ValidEntityIterator in 'MZone.h' for valid types.
//   typedef typename ValidEntityIterator<Ent, EntPtr>::Type Check;
  typedef typename DimTr<DIM>::EntityT Ent;

  // Find the neighbours of each vertex, edge, and face
  ParseEntity<DIM>::eval(static_cast<Ent*>(entity), boFaceMap, elemVec,
                         vertMap, zoneElemConn, partition);

}


/*==============================================================================
 *
 * Routine: zoneData
 *
 * Purpose
 * =======
 *
 *   Processes all the elements in a zone.  Stores vertices and element
 *   connectivity.  Records boundary vertices for use with class
 *   'MZoneBoundary'.  Both the vertices and elements are ordered with boundary
 *   vertices/elements first.
 *
 *============================================================================*/

template <unsigned DIM>
int MZone<DIM>::zoneData()
{

  if(elemVec.size() == 0) return 1;

  // Resize output arrays
  zoneVertVec.resize(vertMap.size());

//--Label boundary vertices and start building output vector of vertices.
//--Also record boundary faces that contain a boundary vertex.

  std::vector<MVertex*> faceVertices;
  unsigned cVert = 0;
  for(typename BoFaceMap::iterator fMapIt = boFaceMap.begin();
      fMapIt != boFaceMap.end(); ++fMapIt) {
    // Get all the vertices on the face
    FaceTr<FaceT>::getAllFaceVertices
      (elemVec[fMapIt->second.parentElementIndex].element,
       fMapIt->second.parentFace, faceVertices);
    const int nVert = faceVertices.size();
    for(int iVert = 0; iVert != nVert; ++iVert) {
      int &index = vertMap[faceVertices[iVert]];
      // Label the boundary vertices
      if(index == 0) {
        zoneVertVec[cVert] = faceVertices[iVert];
        index = ++cVert;
      }
      // Record boundary faces that belong to boundary vertices
      ZoneVertexData<typename BoFaceMap::const_iterator> &boVertData =
        boVertMap[faceVertices[iVert]];
      // const_cast is okay, the keys to 'boFaceMap' will not be changed
      boVertData.faces.push_back(fMapIt);
      boVertData.index = index;
    }
  }
  numBoVert = cVert;

//--Label interior vertices and complete output vector of vertices

  const VertexMap::const_iterator vMapEnd = vertMap.end();
  for(VertexMap::iterator vMapIt = vertMap.begin();
      vMapIt != vMapEnd; ++vMapIt) {
    if(vMapIt->second == 0) {  // Vertex in zone interior
      zoneVertVec[cVert] = vMapIt->first;
      vMapIt->second = ++cVert;
    }
  }

//--Initialize the connectivity array for the various types of elements.  Note
//--that 'iElemType' is MSH_TYPE-1.

  int numUsedElemType = 0;
  for(int iElemType = 0; iElemType != MSH_NUM_TYPE; ++iElemType) {
    if(zoneElemConn[iElemType].numElem > 0) {
      zoneElemConn[iElemType].connectivity.resize
        (zoneElemConn[iElemType].numElem*MElement::getInfoMSH(iElemType+1));
      // Members numBoElem, and iConn should be set to zero via the constructor
      // or a clear
    }
  }

//--The elements are added to the connectivity in two loops.  The first loop
//--looks for boundary elements.  The second loop adds the remaining interior
//--elements.

  unsigned cElem = 1;
  const ElementVec::const_iterator eVecEnd = elemVec.end();
  for(ElementVec::iterator eVecIt = elemVec.begin(); eVecIt != eVecEnd;
      ++eVecIt) {
    // It is sufficient to check the primary vertices to see if this element
    // is on the boundary
    const int nPVert = eVecIt->element->getNumPrimaryVertices();
    for(int iPVert = 0; iPVert != nPVert; ++iPVert) {
      if(vertMap[eVecIt->element->getVertex(iPVert)] <= numBoVert) {
        // The element index
        eVecIt->index = cElem++;
        // The type of element
        const int iElemType = eVecIt->element->getTypeForMSH() - 1;
        // Increment number of boundary elements of this type
        ++zoneElemConn[iElemType].numBoElem;
        // Load connectivity for this element type
        const int nVert = eVecIt->element->getNumVertices();
        for(int iVert = 0; iVert != nVert; ++iVert) {
          zoneElemConn[iElemType].add_to_connectivity
            (vertMap[eVecIt->element->getVertex(iVert)]);
        }
        break;
      }
    }
  }

//--Now loop through all elements again and do same thing for all elements with
//--index set to 0

  for(ElementVec::iterator eVecIt = elemVec.begin(); eVecIt != eVecEnd;
      ++eVecIt) {
    if(eVecIt->index == 0) {
      // The element index
      eVecIt->index == cElem++;
      // The type of element
      const int iElemType = eVecIt->element->getTypeForMSH() - 1;
      // Load connectivity for this element type
      const int nVert = eVecIt->element->getNumVertices();
      for(int iVert = 0; iVert != nVert; ++iVert) {
        zoneElemConn[iElemType].add_to_connectivity
          (vertMap[eVecIt->element->getVertex(iVert)]);
      }
    }
  }

//**If we are going to write the boundary element faces, we need to update
//**.parentElementIndex from "index in elemVec" to "elemVec[iParent].index.
//**This is the index of the parent element local to the zone.

//--Clean-up for containers that are no longer required.  Only 'boVertMap' is
//--still required but 'boFaceMap' is also retained because it contains the
//--faces referenced by 'boVertMap'.

  elemVec.clear();
  vertMap.clear();
  return 0;

}


/*******************************************************************************
 *
 * Template meta-programming classes
 *
 ******************************************************************************/

/*--------------------------------------------------------------------*
 * This class uses traits to determine the element types in an entity
 * and iterate over them.  A template meta-programming loop is used to
 * iterate over the types of elements.  So within the class, we are
 * simply examining one type of element of a specific dimension in one
 * specific entity.
 *--------------------------------------------------------------------*/

//--Entry point

template <unsigned DIM, int N>
struct ParseEntity
{
  typedef typename DimTr<DIM>::EntityT Ent;  // The type of entity
  typedef typename DimTr<DIM>::FaceT FaceT;  // The type/dimension of face
  typedef typename LFaceTr<FaceT>::BoFaceMap BoFaceMap; // The corresponding map
  typedef typename DimElemTr<DIM, N>::Elem Elem;  // The type of primary element
  typedef typename DimElemTr<DIM, N>::ConstElementIterator ConstElementIterator;
  static void eval(const Ent *const entity,
                   BoFaceMap &boFaceMap,
                   ElementVec &elemVec,
                   VertexMap &vertMap,
                   ElementConnectivity *zoneElemConn,
                   const int partition)
  {
    ConstElementIterator elemEnd = DimElemTr<DIM, N>::end(entity);
    for(ConstElementIterator itElem = DimElemTr<DIM, N>::begin(entity);
        itElem != elemEnd; ++itElem) {
      if(partition < 0 || (*itElem)->getPartition() == partition) {
        // Unique list of elements
        const unsigned eVecIndex = elemVec.size();
        elemVec.push_back(ElemData(*itElem));
        ++zoneElemConn[(*itElem)->getTypeForMSH() - 1].numElem;
        // Unique list of vertices
        const int nVert = (*itElem)->getNumVertices();
        for(int iVert = 0; iVert != nVert; ++iVert)
          vertMap[(*itElem)->getVertex(iVert)] = 0;  // Unlabelled
        // Maintain list of (base element) faces with only one bounding element.
        for(int iFace = 0; iFace != ElemFaceTr<DIM, Elem>::numFaceT;
            ++iFace) {
          FaceT face = FaceTr<FaceT>::template getFace<Elem>(*itElem, iFace);
          std::pair<typename BoFaceMap::iterator, bool> insBoFaceMap =
            boFaceMap.insert(std::pair<FaceT, FaceData>
                             (face, FaceData(*itElem, iFace, eVecIndex)));
          if(!insBoFaceMap.second) {
            // The face already exists and is therefore bounded on both sides
            // by elements.  Not a boundary face so delete.
            boFaceMap.erase(insBoFaceMap.first);
          }
        }
      }
    }
    // Next element type in the entity
    ParseEntity<DIM, N-1>::eval(entity, boFaceMap, elemVec, vertMap,
                                zoneElemConn, partition);
  }
};

//--Terminate loop when N = 1

template <unsigned DIM>
struct ParseEntity<DIM, 1>
{
  typedef typename DimTr<DIM>::EntityT Ent;  // The type of entity
  typedef typename DimTr<DIM>::FaceT FaceT;  // The type/dimension of face
  typedef typename LFaceTr<FaceT>::BoFaceMap BoFaceMap; // The corresponding map
  typedef typename DimElemTr<DIM, 1>::Elem Elem;  // The type of primary element
  typedef typename DimElemTr<DIM, 1>::ConstElementIterator ConstElementIterator;
  static void eval(const Ent *const entity,
                   BoFaceMap &boFaceMap,
                   ElementVec &elemVec,
                   VertexMap &vertMap,
                   ElementConnectivity *zoneElemConn,
                   const int partition)
  {
    ConstElementIterator elemEnd = DimElemTr<DIM, 1>::end(entity);
    for(ConstElementIterator itElem = DimElemTr<DIM, 1>::begin(entity);
        itElem != elemEnd; ++itElem) {
      if(partition < 0 || (*itElem)->getPartition() == partition) {
        // Unique list of elements
        const unsigned eVecIndex = elemVec.size();
        elemVec.push_back(ElemData(*itElem));
        ++zoneElemConn[(*itElem)->getTypeForMSH() - 1].numElem;
        // Unique list of vertices
        const int nVert = (*itElem)->getNumVertices();
        for(int iVert = 0; iVert != nVert; ++iVert)
          vertMap[(*itElem)->getVertex(iVert)] = 0;  // Unlabelled
        // Maintain list of (base element) faces with only one bounding element.
        for(int iFace = 0; iFace != ElemFaceTr<DIM, Elem>::numFaceT;
            ++iFace) {
          FaceT face = FaceTr<FaceT>::template getFace<Elem>(*itElem, iFace);
          std::pair<typename BoFaceMap::iterator, bool> insBoFaceMap =
            boFaceMap.insert(std::pair<FaceT, FaceData>
                             (face, FaceData(*itElem, iFace, eVecIndex)));
          if(!insBoFaceMap.second) {
            // The face already exists and is therefore bounded on both sides
            // by elements.  Not a boundary face so delete.
            boFaceMap.erase(insBoFaceMap.first);
          }
        }
      }
    }
  }
};


/*******************************************************************************
 *
 * Explicit instantiations of class MZone
 *
 ******************************************************************************/

//--All the non-template routines in the class

template class MZone<2>;
template class MZone<3>;

//--Explicit instantiations of the routines for adding elements from a
//--container of entities

// Vector container
template void MZone<2>::add_elements_in_entities
<std::vector<GEntity*>::const_iterator>
(std::vector<GEntity*>::const_iterator begin,
 std::vector<GEntity*>::const_iterator end, const int partition);

template void MZone<3>::add_elements_in_entities
<std::vector<GEntity*>::const_iterator>
(std::vector<GEntity*>::const_iterator begin,
 std::vector<GEntity*>::const_iterator end, const int partition);

//--Explicit instantiations of the routines for adding elements from a single
//--entity

template void MZone<2>::add_elements_in_entity
<GFace*>
(GFace* entity, const int partition);

template void MZone<3>::add_elements_in_entity
<GRegion*>
(GRegion* entity, const int partition);
