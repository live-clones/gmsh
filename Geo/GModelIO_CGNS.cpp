// Copyright (C) 2006 S. Guzik, C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include <string.h>
#include <iostream>  // DBG
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "GModel.h"
#include "Message.h"
#include "MElement.h"
#include "MNeighbour.h"
#include "MVertex.h"

#if defined(HAVE_LIBCGNS)

#include <cgnslib.h>

int cgnsErr(const int cgIndexFile = -1)
{
  Msg::Error(cg_get_error());
  if(cgIndexFile != -1)
    if(cg_close(cgIndexFile)) Msg::Error("Even unable to close CGNS file");
  return 0;
}


/*==============================================================================
 * File scope structures used for CGNS I/O
 *============================================================================*/

//--Structure describing the zones sharing a vertex or element

struct ZoneConn_t {
  unsigned int indexZone;               // Index of the zone
  unsigned int indexConn;               // Index of the vertex or element used
                                        // to describe the connectivity
  ZoneConn_t(const unsigned int iz, const unsigned int ic) :
    indexZone(iz), indexConn(ic) { }
};

//--Class to make C style CGNS name strings act like C++ types

class CgnsNameStr {
  private:
  char name[33];
  public:
  // Constructors
  CgnsNameStr() { name[0] = '\0'; }
  CgnsNameStr(const char *const cstr) {
    std::strncpy(name, cstr, 32);
    name[32] = '\0';
  }
  CgnsNameStr(const CgnsNameStr& cgs) { std::strcpy(name, cgs.name); }
  // Assignment
  CgnsNameStr& operator=(const CgnsNameStr& cgs) {
    if ( &cgs != this ) {
      std::strcpy(name, cgs.name);
    }
    return *this;
  }
  CgnsNameStr& operator=(const char *const cstr) {
    std::strncpy(name, cstr, 32);
    name[32] = '\0';
    return *this;
  }
  // Return the C string
  char *c_str() { return name; }
  const char *c_str() const { return name; }
};


/*==============================================================================
 *
 * Routine readCGNS
 *
 * Purpose
 * =======
 *
 *   
 *
 * I/O
 * ===
 *
 *   name               - (I) file name
 *
 *============================================================================*/

int GModel::readCGNS(const std::string &name)
{
  return 1;
}


/*==============================================================================
 *
 * Routine writeCGNS
 *
 * Purpose
 * =======
 *
 *   Writes out mesh in CGNS format
 *
 * I/O
 * ===
 *
 *   name               - (I) file name
 *   scalingFactor      - (I) scaling for coordinates
 *
 *============================================================================*/

int GModel::writeCGNS(const std::string &name, double scalingFactor)
{

//----- Type definitions -----//

  typedef std::map<int, std::vector<GEntity*> >::iterator zone_iterator;
  typedef std::vector<MTriangle*>::const_iterator const_triangle_iterator;
  typedef std::vector<MQuadrangle*>::const_iterator const_quadrangle_iterator;
  typedef std::list<MVertex*> BoundaryVertList;
  typedef std::set<MVertex*> InteriorVertSet;
  typedef std::list<MElement*> BoundaryElemList;
  typedef std::set<MElement*> InteriorElemSet;

//----- Parameters -----//

  enum {
    vertex,
    edge,
    face,
    region
  };

  int meshDim = 0;                      // Dimension of the mesh
  std::map<int, std::vector<GEntity*> > groups[4];
                                        // vector of entities that belong to
                                        // each physical group (in each
                                        // dimension)
  std::multimap<MVertex*, ZoneConn_t> sharedVertex;
                                        // map of shared vertices describing the
                                        // zones that share it and the index of
                                        // the vertex in each of the zones.
//   std::multimap<MEdge, ZoneConn_t> sharedEdge;
//   std::multimap<MFace, ZoneConn_t> sharedFace;
  MNeighbour meshNeighbours;            // Database of neighbours (computed for
                                        // each zone)

//--Get a list of groups in each dimension and each of the entities in that
//--group.  The groups will define the zones.  If no 2D or 3D groups exist, just
//--store all mesh elements in one zone.

  getPhysicalGroups(groups);
  if(groups[face].size() + groups[region].size() == 0) {
    // If there are no 2D or 3D physical groups, save all elements in one zone.
    // Pretend that there is one physical group ecompassing all the elements.
    for(riter it = firstRegion(); it != lastRegion(); ++it)
      if((*it)->tetrahedra.size() + (*it)->hexahedra.size() +
         (*it)->prisms.size() + (*it)->pyramids.size() > 0)
        groups[region][1].push_back(*it);
    if(!groups[region].size()) {
      // No 3D elements were found.  Look for 2D elements.
      for(fiter it = firstFace(); it != lastFace(); ++it)
        if((*it)->triangles.size() + (*it)->quadrangles.size() > 0)
          groups[face][1].push_back(*it);
      if(!groups[face].size()) {
        Msg::Error("No mesh elements were found");
        return 0;
      }
    }
  }

//--Open the file and get ready to write the zones

  // Will this be a 2D or 3D mesh?
  if(groups[region].size()) meshDim = 3;
  else meshDim = 2;

  // open the file
  int cgIndexFile;
  if(cg_open(name.c_str(), MODE_WRITE, &cgIndexFile)) return cgnsErr();

  // write the base node
  int cgIndexBase;
  if(cg_base_write(cgIndexFile, "Base_0000", 2, 2, &cgIndexBase))
    return cgnsErr();

  // write information about who generated the mesh
  if(cg_goto(cgIndexFile, cgIndexBase, "end")) return(cgnsErr());
  if(cg_descriptor_write("About", "Created by Gmsh")) return cgnsErr();

  unsigned int indexZone = 0;           // Index of a zone
  const unsigned int nZone = groups[face].size() + groups[region].size();
                                        // Total number of zones
  std::vector<CgnsNameStr> zoneName(nZone);
                                        // zone names
  std::vector<BoundaryVertList> zoneBoundaryVert(nZone);

/*--------------------------------------------------------------------*
 * Write the 3D zone information
 *--------------------------------------------------------------------*/

// TODO: add

/*--------------------------------------------------------------------*
 * Write the 2D zone information
 *--------------------------------------------------------------------*/

  for(zone_iterator itZone = groups[face].begin(); itZone != groups[face].end();
      ++itZone) {
    const int nFace = itZone->second.size();
    std::cout << "Working on zone " << indexZone+1 << "  " << itZone->first
              << std::endl;
    std::sprintf(zoneName[indexZone].c_str(), "Zone_%d\0", indexZone+1);

//--Compute the mesh neighbours for this group

    meshNeighbours.add_elements_in_entities<GFace>(itZone->second.begin(),
                                                   itZone->second.end());

//--Load interior lists with all vertices and all elements

    unsigned int numTri3 = 0;
    unsigned int numTri6 = 0;
    unsigned int numQuad4 = 0;
    unsigned int numQuad8 = 0;
    unsigned int numQuad9 = 0;

    InteriorVertSet interiorVert;
    BoundaryElemList boundaryElem;
    InteriorElemSet interiorElem;

    for(unsigned int iFace = 0; iFace != nFace; ++iFace) {
      GFace* face = static_cast<GFace*>(itZone->second[iFace]);
      const std::vector<MTriangle*>::const_iterator itEndTri =
        face->triangles.end();
      for(std::vector<MTriangle*>::const_iterator itTri =
            face->triangles.begin(); itTri != itEndTri ; ++itTri) {
        interiorElem.insert(*itTri);
        interiorVert.insert((*itTri)->getVertex(0));
        interiorVert.insert((*itTri)->getVertex(1));
        interiorVert.insert((*itTri)->getVertex(2));
        switch ( (*itTri)->getTypeForMSH() ) {
        case MSH_TRI_3:
          ++numTri3;
          break;
        case MSH_TRI_6:
          ++numTri6;
          interiorVert.insert((*itTri)->getVertex(3));
          interiorVert.insert((*itTri)->getVertex(4));
          interiorVert.insert((*itTri)->getVertex(5));
          break;
        }
      }
      const std::vector<MQuadrangle*>::const_iterator itEndQuad =
        face->quadrangles.end();
      for(std::vector<MQuadrangle*>::const_iterator itQuad =
            face->quadrangles.begin(); itQuad != itEndQuad ; ++itQuad) {
        interiorElem.insert(*itQuad);
        interiorVert.insert((*itQuad)->getVertex(0));
        interiorVert.insert((*itQuad)->getVertex(1));
        interiorVert.insert((*itQuad)->getVertex(2));
        interiorVert.insert((*itQuad)->getVertex(3));
        switch ( (*itQuad)->getTypeForMSH() ) {
        case MSH_QUA_4:
          ++numQuad4;
          break;
        case MSH_QUA_8:
          ++numQuad8;
          interiorVert.insert((*itQuad)->getVertex(4));
          interiorVert.insert((*itQuad)->getVertex(5));
          interiorVert.insert((*itQuad)->getVertex(6));
          interiorVert.insert((*itQuad)->getVertex(7));
          break;
        case MSH_QUA_9:
          ++numQuad9;
          interiorVert.insert((*itQuad)->getVertex(4));
          interiorVert.insert((*itQuad)->getVertex(5));
          interiorVert.insert((*itQuad)->getVertex(6));
          interiorVert.insert((*itQuad)->getVertex(7));
          interiorVert.insert((*itQuad)->getVertex(8));
          break;
        }
      }
    }

//--Check edges for zone boundaries and move vertices and elements from interior
//--sets to boundary lists

    const MNeighbour::Edge_const_iterator itEndEdge =
      meshNeighbours.edge_end();
    for(MNeighbour::Edge_const_iterator itEdge = meshNeighbours.edge_begin();
        itEdge != itEndEdge; ++itEdge) {
      if(itEdge.num_neighbours() == 1) {  // Boundary edge
        // Find the boundary element
        MElement *element;
        meshNeighbours.edge_neighbours(itEdge, &element);
        // Move primary vertices from interior to boundary
        InteriorVertSet::iterator itVert =
          interiorVert.find(itEdge->getVertex(0));
        if(itVert != interiorVert.end()) {
          zoneBoundaryVert[indexZone].push_back(*itVert);
          interiorVert.erase(itVert);
        }
        itVert = interiorVert.find(itEdge->getVertex(1));
        if(itVert != interiorVert.end()) {
          zoneBoundaryVert[indexZone].push_back(*itVert);
          interiorVert.erase(itVert);
        }
        // If this is a higher-order element, find the edge on the boundary
        // and then the mid-edge vertex
        if(element->getNumVertices() != element->getNumPrimaryVertices()) {
          // Second-order element
          int iEPE = 0;
          while(element->getEdge(iEPE) != *itEdge) ++iEPE;
          // Add mid-vertex on edge iEPE
          itVert = interiorVert.find
            (element->getVertex(iEPE + element->getNumPrimaryVertices()));
          if(itVert != interiorVert.end()) {
            zoneBoundaryVert[indexZone].push_back(*itVert);
            interiorVert.erase(itVert);
          }
        }
      }
    }

//--Loop through all the boundary vertices

    int numVert = 1;
    BoundaryVertList::const_iterator itEndBVert =
      zoneBoundaryVert[indexZone].end();
    {
      MElement **boElem = new MElement*[meshNeighbours.max_vertex_neighbours()];
      for(BoundaryVertList::iterator itVert =
            zoneBoundaryVert[indexZone].begin(); itVert != itEndBVert;
          ++itVert) {
        // Any elements with a vertex in the boundary vertex list should be
        // moved to the boundary element list.
        const int nElem = meshNeighbours.vertex_neighbours(*itVert, boElem);
        for(int iElem = 0; iElem != nElem; ++iElem) {
          InteriorElemSet::iterator itElem = interiorElem.find(boElem[iElem]);
          if(itElem != interiorElem.end()) {
            boundaryElem.push_back(boElem[iElem]);
            interiorElem.erase(itElem);
          }
        }
        // Renumber the boundary vertices
        (*itVert)->setNum(numVert);
        // Add all boundary vertices to the map of shared vertices
        sharedVertex.insert(std::make_pair(*itVert, ZoneConn_t(indexZone,
                                                               numVert)));
        ++numVert;
      }
      delete[] boElem;
    }

//--Renumber the interior mesh vertices

    InteriorVertSet::const_iterator itEndIVert = interiorVert.end();
    for(InteriorVertSet::iterator itVert = interiorVert.begin();
        itVert != itEndIVert; ++itVert) (*itVert)->setNum(numVert++);

//--Write the zone node

    int cgIndexZone;
    int cgZoneSize[3];
    cgZoneSize[0] = zoneBoundaryVert[indexZone].size() + interiorVert.size();
    cgZoneSize[1] = boundaryElem.size() + interiorElem.size();
    cgZoneSize[2] = zoneBoundaryVert[indexZone].size();
    if(cg_zone_write(cgIndexFile, cgIndexBase, zoneName[indexZone].c_str(),
                     cgZoneSize, Unstructured, &cgIndexZone)) return cgnsErr();

//--Write the grid node

    int cgIndexGrid;
    if(cg_grid_write(cgIndexFile, cgIndexBase, cgIndexZone, "GridCoordinates",
                     &cgIndexGrid)) return cgnsErr();

//--Write the grid coordinates
    
    {
      std::vector<double> coordx(cgZoneSize[0]);
      std::vector<double> coordy(cgZoneSize[1]);
      int iVert = 0;
      for(BoundaryVertList::const_iterator itVert =
            zoneBoundaryVert[indexZone].begin(); itVert != itEndBVert;
          ++itVert) {
        coordx[iVert] = (*itVert)->x()*scalingFactor;
        coordy[iVert] = (*itVert)->y()*scalingFactor;
        ++iVert;
      }
      for(InteriorVertSet::const_iterator itVert = interiorVert.begin();
          itVert != itEndIVert; ++itVert) {
        coordx[iVert] = (*itVert)->x()*scalingFactor;
        coordy[iVert] = (*itVert)->y()*scalingFactor;
        ++iVert;
      }      
      int cgIndexCoord;
      if(cg_coord_write(cgIndexFile, cgIndexBase, cgIndexZone, RealDouble,
                        "CoordinateX", &coordx[0], &cgIndexCoord))
        return cgnsErr();
      if(cg_coord_write(cgIndexFile, cgIndexBase, cgIndexZone, RealDouble,
                        "CoordinateY", &coordy[0], &cgIndexCoord))
        return cgnsErr();
    }

//--Write out the element connectivity
    
    {
      int mixedElem = -1;
      int numVPE;
      int numElemData = 0;
      ElementType_t cgElemType;
      if(numTri3) {
        ++mixedElem;
        numVPE = 3;
        numElemData += numTri3*3;
        cgElemType = TRI_3;
      }
      if(numTri6) {
        ++mixedElem;
        numVPE = 6;
        numElemData += numTri6*6;
        cgElemType = TRI_6;
      }
      if(numQuad4) {
        ++mixedElem;
        numVPE = 4;
        numElemData += numQuad4*4;
        cgElemType = QUAD_4;
      }
      if(numQuad8) {
        ++mixedElem;
        numVPE = 8;
        numElemData += numQuad8*8;
        cgElemType = QUAD_8;
      }
      if(numQuad9) {
        ++mixedElem;
        numVPE = 9;
        numElemData += numQuad9*9;
        cgElemType = QUAD_9;
      }
      if(mixedElem) {
        numVPE = 0;
        numElemData += cgZoneSize[1];
        cgElemType = MIXED;
      }

      std::vector<int> elementConn(numElemData);
      int iElemData = 0;

      // Load boundary elements
      BoundaryElemList::const_iterator itEndBElem = boundaryElem.end();
      if(mixedElem) {
        for(BoundaryElemList::const_iterator itElem = boundaryElem.begin();
            itElem != itEndBElem; ++itElem) {
          switch((*itElem)->getTypeForMSH()) {
          case MSH_TRI_3:
            elementConn[iElemData++] = TRI_3;
            break;
          case MSH_TRI_6:
            elementConn[iElemData++] = TRI_6;
            break;
          case MSH_QUA_4:
            elementConn[iElemData++] = QUAD_4;
            break;
          case MSH_QUA_8:
            elementConn[iElemData++] = QUAD_8;
            break;
          case MSH_QUA_9:
            elementConn[iElemData++] = QUAD_9;
            break;
          }
          const int nVPE = (*itElem)->getNumVertices();
          for(int iVPE = 0; iVPE != nVPE; ++iVPE)
            elementConn[iElemData++] = (*itElem)->getVertex(iVPE)->getNum();
        }
      }
      else {
        const int nVPE = numVPE;
        for(BoundaryElemList::const_iterator itElem = boundaryElem.begin();
            itElem != itEndBElem; ++itElem)
          for(int iVPE = 0; iVPE != nVPE; ++iVPE)
            elementConn[iElemData++] = (*itElem)->getVertex(iVPE)->getNum();
      }

      // Load interior elements
      InteriorElemSet::const_iterator itEndIElem = interiorElem.end();
      if(mixedElem) {
        for(InteriorElemSet::const_iterator itElem = interiorElem.begin();
            itElem != itEndIElem; ++itElem) {
          switch((*itElem)->getTypeForMSH()) {
          case MSH_TRI_3:
            elementConn[iElemData++] = TRI_3;
            break;
          case MSH_TRI_6:
            elementConn[iElemData++] = TRI_6;
            break;
          case MSH_QUA_4:
            elementConn[iElemData++] = QUAD_4;
            break;
          case MSH_QUA_8:
            elementConn[iElemData++] = QUAD_8;
            break;
          case MSH_QUA_9:
            elementConn[iElemData++] = QUAD_9;
            break;
          }
          const int nVPE = (*itElem)->getNumVertices();
          for(int iVPE = 0; iVPE != nVPE; ++iVPE)
            elementConn[iElemData++] = (*itElem)->getVertex(iVPE)->getNum();
        }
      }
      else {
        const int nVPE = numVPE;
        for(InteriorElemSet::const_iterator itElem = interiorElem.begin();
            itElem != itEndIElem; ++itElem)
          for(int iVPE = 0; iVPE != nVPE; ++iVPE)
            elementConn[iElemData++] = (*itElem)->getVertex(iVPE)->getNum();
      }

      // Write to CGNS file
      int cgIndexSection;
      if(cg_section_write(cgIndexFile, cgIndexBase, cgIndexZone, "Section_Main",
                          cgElemType, 1, cgZoneSize[1], boundaryElem.size(),
                          &elementConn[0], &cgIndexSection)) return cgnsErr();
    }

    meshNeighbours.clear();
    ++indexZone;

  }

//--Close the file

  if(cg_close(cgIndexFile)) return cgnsErr();

  std::cout << "Done\n";
  return 1;
}

#else

int GModel::readCGNS(const std::string &name)
{
  Msg::Error("This version of Gmsh was compiled without CGNS support");
  return 0;
}

int GModel::writeCGNS(const std::string &name, double scalingFactor)
{
  Msg::Error("This version of Gmsh was compiled without CGNS support");
  return 0;
}

#endif

