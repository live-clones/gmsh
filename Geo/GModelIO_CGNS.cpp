// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// GModelIO_CGNS.cpp - Copyright (C) 2008 S. Guzik, C. Geuzaine, J.-F. Remacle

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "CGNSOptions.h"

#if defined(HAVE_LIBCGNS)

#ifdef _OPENMP
#include <omp.h>
#else
#define omp_get_num_threads() 1
#define omp_get_thread_num() 0
#define omp_lock_t int
#define omp_init_lock(x)
#define omp_set_lock(x)
#define omp_unset_lock(x)
#define omp_destroy_lock(x)
#endif

#include <cstring>
#include <iostream>  // DBG
#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <queue>

#include "MZone.h"
#include "MZoneBoundary.h"

#include <cgnslib.h>

//--Error function for the CGNS library

int cgnsErr(const int cgIndexFile = -1)
{
  Msg::Error("Error detected by CGNS library\n");
  Msg::Error(cg_get_error());
  if(cgIndexFile != -1)
    if(cg_close(cgIndexFile)) Msg::Error("Unable to close CGNS file");
  return 0;
}


/*==============================================================================
 * Required types
 *============================================================================*/

typedef std::map<int, std::vector<GEntity*> > PhysGroupMap;
                                        // Type providing a vector of entities
                                        // for a physical group index

//--Class to gather elements that belong to a partition.  This class mimics a
//--GEntity class.

class DummyPartitionEntity : public GEntity
{
 public:
  DummyPartitionEntity()
    : GEntity(0, 0)
  { }

  // number of types of elements
  int getNumElementTypes() const { return 1; }
  void getNumMeshElements(unsigned *const c) const
  {
    c[0] += elements.size();
  }

  // get the start of the array of a type of element
  MElement *const *getStartElementType(int type) const
  {
    return &elements[0];
  }

  std::vector<MElement*> elements;
};

//--Class to make C style CGNS name strings act like C++ types

class CGNSNameStr
{
 private:
  char name[33];
 public:
  // Constructors
  CGNSNameStr() { name[0] = '\0'; }
  CGNSNameStr(const char *const cstr)
  {
    std::strncpy(name, cstr, 32);
    name[32] = '\0';
  }
  CGNSNameStr(std::string &s)
  {
    std::strncpy(name, s.c_str(), 32);
    name[32] = '\0';
  }
  CGNSNameStr(const int d, const char *const fmt = "%d") 
  {
    std::sprintf(name, fmt, d);
  }
  CGNSNameStr(const CGNSNameStr& cgs) { std::strcpy(name, cgs.name); }
  // Assignment
  CGNSNameStr &operator=(const CGNSNameStr& cgs)
  {
    if ( &cgs != this ) {
      std::strcpy(name, cgs.name);
    }
    return *this;
  }
  CGNSNameStr &operator=(const char *const cstr)
  {
    std::strncpy(name, cstr, 32);
    name[32] = '\0';
    return *this;
  }
  // Return the C string
  char *c_str() { return name; }
  const char *c_str() const { return name; }
};

//--Provides a CGNS element type for a MSH element type and indicates the order
//--in which the CGNS elements are to be written:
//    3D first-order elements
//    3D second-order elements
//    2D first-order elements
//    2D second-order elements
//    1D first-order elements
//    1D second-order elements
//    MSH_NUM_TYPE+1 is used to place non-cgns elements last.
static const int msh2cgns[MSH_NUM_TYPE][2] = {
  {BAR_2,          16},
  {TRI_3,          11},
  {QUAD_4,         12},
  {TETRA_4,         1},
  {HEXA_8,          4},
  {PENTA_6,         3},
  {PYRA_5,          2},
  {BAR_3,          17},
  {TRI_6,          13},
  {QUAD_9,         15},
  {TETRA_10,        5},
  {HEXA_27,        10},
  {PENTA_18,        8},
  {PYRA_14,         6},
  {-1, MSH_NUM_TYPE+1},  // MSH_PNT (NODE in CGNS but not used herein)
  {QUAD_8,         14},
  {HEXA_20,         9},
  {PENTA_15,        7},
  {-1, MSH_NUM_TYPE+1},  // MSH_PYR_13
  {-1, MSH_NUM_TYPE+1},  // MSH_TRI_9
  {-1, MSH_NUM_TYPE+1},  // MSH_TRI_10
  {-1, MSH_NUM_TYPE+1},  // MSH_TRI_12
  {-1, MSH_NUM_TYPE+1},  // MSH_TRI_15
  {-1, MSH_NUM_TYPE+1},  // MSH_TRI_15I
  {-1, MSH_NUM_TYPE+1},  // MSH_TRI_21
  {-1, MSH_NUM_TYPE+1},  // MSH_LIN_4
  {-1, MSH_NUM_TYPE+1},  // MSH_LIN_5
  {-1, MSH_NUM_TYPE+1},  // MSH_LIN_6
  {-1, MSH_NUM_TYPE+1},  // MSH_TET_20
  {-1, MSH_NUM_TYPE+1},  // MSH_TET_35
  {-1, MSH_NUM_TYPE+1},  // MSH_TET_56
  {-1, MSH_NUM_TYPE+1},  // MSH_TET_34
  {-1, MSH_NUM_TYPE+1}   // MSH_TET_52
};

//--This functor allows for sorting of the element types according to the
//--"write-order" in array 'msh2cgns'

struct ElemSortCGNSType
{
  bool operator()(const int t0, const int t1)
  {
    if(zoneElemConn[t0].numElem > 0 && zoneElemConn[t1].numElem > 0)
      return msh2cgns[t0][1] < msh2cgns[t1][1];
    else if(zoneElemConn[t0].numElem > 0)
      return true;
    else
      return false;
  }
  ElemSortCGNSType(const ElementConnectivity *const _zoneElemConn)
    : zoneElemConn(_zoneElemConn)
  { }
 private:
  const ElementConnectivity *const zoneElemConn;
};


/*==============================================================================
 * Forward declarations
 *============================================================================*/

template <unsigned DIM>
int write_CGNS_zones(GModel &model, const int zoneDefinition, const int numZone,
                     const CGNSOptions &options, const double scalingFactor,
                     const int vectorDim, const PhysGroupMap &group,
                     const int cgIndexFile, const int cgIndexBase);


/*******************************************************************************
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
 ******************************************************************************/

int GModel::readCGNS(const std::string &name)
{
  return 1;
}


/*******************************************************************************
 *
 * Routine writeCGNS
 *
 * Purpose
 * =======
 *
 *   Writes out the mesh in CGNS format
 *
 * I/O
 * ===
 *
 *   name               - (I) file name
 *   zoneDefinition     - (I) how to define a zone
 *   options            - (I) options specific to CGNS
 *   scalingFactor      - (I) scaling for coordinates
 *
 ******************************************************************************/

int GModel::writeCGNS(const std::string &name, int zoneDefinition,
                      const CGNSOptions &options, double scalingFactor)
{

  enum {
    vertex = 0,
    edge   = 1,
    face   = 2,
    region = 3
  };

  PhysGroupMap groups[4];               // vector of entities that belong to
                                        // each physical group (in each
                                        // dimension)
  std::vector<DummyPartitionEntity> partitions;
                                        // Dummy entities that store the
                                        // elements in each partition
  int numZone;
  int meshDim;

  Msg::Warning("CGNS I/O is at an \"alpha\" software stage");

  switch(zoneDefinition) {
  case 1:  // By partition

//--Group the elements of each partition into a dummy entity.  Pointers to the
//--entities are then made available in groups[DIM][0].

    {
      numZone = meshPartitions.size();
      if(numZone == 0) zoneDefinition = 0;
      else {
        partitions.resize(numZone);
        for(int i = 0; i != numZone; ++i)
          partitions[i].elements.reserve(getMaxPartitionSize());
        unsigned numElem[5];
        meshDim = getNumMeshElements(numElem);
        // Load the dummy entities with the elements in each partition
        switch(meshDim) {
        case 3:
          for(riter it = firstRegion(); it != lastRegion(); ++it) {
            numElem[0] = 0; numElem[1] = 0; numElem[2] = 0; numElem[3] = 0;
            numElem[4] = 0;
            (*it)->getNumMeshElements(numElem);
            const int nType = (*it)->getNumElementTypes();
            for(int iType = 0; iType != nType; ++iType) {
              MElement *const *element = (*it)->getStartElementType(iType);
              const int nElem = numElem[iType];
              for(int iElem = 0; iElem != nElem; ++iElem) {
                partitions[element[iElem]->getPartition() - 1].elements
                  .push_back(element[iElem]);
              }
            }
          }
          break;
        case 2:
          for(fiter it = firstFace(); it != lastFace(); ++it) {
            numElem[0] = 0; numElem[1] = 0; numElem[2] = 0; numElem[3] = 0;
            numElem[4] = 0;
            (*it)->getNumMeshElements(numElem);
            const int nType = (*it)->getNumElementTypes();
            for(int iType = 0; iType != nType; ++iType) {
              MElement *const *element = (*it)->getStartElementType(iType);
              const int nElem = numElem[iType];
              for(int iElem = 0; iElem != nElem; ++iElem) {
                partitions[element[iElem]->getPartition() - 1].elements
                  .push_back(element[iElem]);
              }
            }
          }
          break;
        default:
          Msg::Error("No mesh elements were found");
          return 0;
        }
        // Place pointers to the entities in the 'groups' object
        std::vector<GEntity*> &ents = groups[meshDim][0];
        ents.resize(numZone);
        for(int iPart = 0; iPart != numZone; ++iPart)
          ents[iPart] = &partitions[iPart];
      }
    }
    break;
  case 2:  // By physical

//--Get a list of groups in each dimension and each of the entities in that
//--group.

    getPhysicalGroups(groups);
    if(groups[region].size()) {
      numZone = groups[region].size();
      meshDim = 3;
    }
    else if(groups[face].size()) {
      numZone = groups[face].size();
      meshDim = 2;
    }
    else {
      zoneDefinition = 0;  // Use single zone
    }
    break;
  }

//--For a single zone, put all the entities for a dimension into groups[DIM][0]

  if(zoneDefinition == 0) {
    numZone = 1;
    unsigned numElem[5];
    numElem[0] = 0; numElem[1] = 0; numElem[2] = 0; numElem[3] = 0; numElem[4] = 0;
    meshDim = getNumMeshElements(numElem);
    switch(meshDim) {
    case 3:
      {
        groups[region].clear();
        std::vector<GEntity*> &ents = groups[region][0];
        ents.resize(getNumRegions());
        int iEnt = 0;
        for(riter it = firstRegion(); it != lastRegion(); ++it)
          ents[iEnt++] = *it;
      }
      break;
    case 2:
      {
        groups[face].clear();
        std::vector<GEntity*> &ents = groups[face][0];
        ents.resize(getNumFaces());
        int iEnt = 0;
        for(fiter it = firstFace(); it != lastFace(); ++it)
          ents[iEnt++] = *it;
      }
      break;
    default:
      Msg::Error("No mesh elements were found");
      return 0;
    }
  }

/*--------------------------------------------------------------------*
 * Summary of three possibilities for the 'zoneDefinition':
 * 0) single zone: all the entities are placed in physical 0.  All the
 *    entities form the zone.
 * 1) defined by partitions:  all the entities are place in physical
 *    0.  Each entity is a zone.
 * 2) defined by physicals:  all the entities in a physical form a
 *    zone.
 *--------------------------------------------------------------------*/

//--Open the file and get ready to write the zones

  // Get the dimension of a vector in the mesh
  int vectorDim = 3;
  if(meshDim == 2) vectorDim = options.vectorDim;

  // open the file
  int cgIndexFile;
  if(cg_open(name.c_str(), MODE_WRITE, &cgIndexFile)) return cgnsErr();

  // write the base node
  int cgIndexBase;
  if(cg_base_write(cgIndexFile, options.baseName.c_str(), meshDim, meshDim,
                   &cgIndexBase))
    return cgnsErr();

  // write information about who generated the mesh
  if(cg_goto(cgIndexFile, cgIndexBase, "end")) return(cgnsErr());
  if(cg_descriptor_write("About", "Created by Gmsh")) return cgnsErr();

  switch(meshDim) {
  case 2:
    MZone<2>::preInit();
    write_CGNS_zones<2>(*this, zoneDefinition, numZone, options, scalingFactor,
                        vectorDim, groups[face], cgIndexFile, cgIndexBase);
    MZone<2>::postDestroy();
    break;
  case 3:
    MZone<3>::preInit();
    write_CGNS_zones<3>(*this, zoneDefinition, numZone, options, scalingFactor,
                        vectorDim, groups[region], cgIndexFile, cgIndexBase);
    MZone<3>::postDestroy();
    break;
  }

//--Close the file

  if(cg_close(cgIndexFile)) return cgnsErr();

  return 0;
}


/*******************************************************************************
 *
 * Routine tranlateElementMSH2CGNS
 *
 * Purpose
 * =======
 *
 *   Rewrites the mesh connectivity using CGNS node ordering
 *
 * I/O
 * ===
 *
 *   zoneElemConn       - (I) connectivity for the zone using gmsh node ordering
 *                            (see MElement.h)
 *                        (O) connectivity using CGNS node ordering
 *   
 ******************************************************************************/

void translateElementMSH2CGNS(ElementConnectivity *const zoneElemConn)
{
  const int maxVPE = 27;
  // Location to write a MSH_TET_10 vertex to get a CGNS TETRA_10
  static const int trTET10[10] = {
    0, 1, 2, 3, 4, 5, 6, 7, 9, 8
  };
  // Location to write a MSH_HEX_20 vertex to get a CGNS HEXA_20
  static const int trHEX20[20] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 11, 12, 9, 13, 10, 14, 15, 16, 19, 17, 18
  };
  // Location to write a MSH_HEX_27 vertex to get a CGNS HEXA_27
  static const int trHEX27[27] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 11, 12, 9, 13, 10, 14, 15, 16, 19, 17, 18,
    20, 21, 24, 22, 23, 25, 26
  };
  // Location to write a MSH_PRI_15 vertex to get a CGNS PENTA_15
  static const int trPRI15[15] = {
    0, 1, 2, 3, 4, 5, 6, 8, 9, 7, 10, 11, 12, 14, 13
  };
  // Location to write a MSH_PRI_18 vertex to get a CGNS PENTA_18
  static const int trPRI18[18] = {
    0, 1, 2, 3, 4, 5, 6, 8, 9, 7, 10, 11, 12, 14, 13,
    15, 17, 16
  };
  // Location to write a MSH_PYR_13 vertex to get a CGNS PYRA_13
  // PYRA_13 are not in the CGNS standard but if ever added they would have the
  // same ordering as PYRA_14
  static const int trPYR13[13] = {
    0, 1, 2, 3, 4, 5, 8, 9, 6, 10, 7, 11, 12
  };
  // Location to write a MSH_PYR_14 vertex to get a CGNS PYRA_14
  static const int trPYR14[14] = {
    0, 1, 2, 3, 4, 5, 8, 9, 6, 10, 7, 11, 12,
    13
  };

  int tmp[maxVPE];
  for(int iElemType = 0; iElemType != MSH_NUM_TYPE; ++iElemType) {
    int numVPE;
    const int *tr;
    if(zoneElemConn[iElemType].numElem > 0) {
      switch(iElemType + 1) {
      case MSH_TET_10:
          numVPE = 10;
          tr = trTET10;
        break;
      case MSH_HEX_20:
          numVPE = 20;
          tr = trHEX20;
        break;
      case MSH_HEX_27:
          numVPE = 27;
          tr = trHEX27;
        break;
      case MSH_PRI_15:
          numVPE = 15;
          tr = trPRI15;
        break;
      case MSH_PRI_18:
          numVPE = 18;
          tr = trPRI18;
        break;
      case MSH_PYR_13:  // Although not in the CGNS standard, I assume it would
                        // be the same as PYRA_14 if ever added
          numVPE = 13;
          tr = trPYR13;
        break;
      case MSH_PYR_14:
          numVPE = 14;
          tr = trPYR14;
        break;
      default:
        numVPE = 0;
        tr = 0;
        break;
      }
      if(numVPE > 0) {
        int *aConn = &zoneElemConn[iElemType].connectivity[0];
        for(int n = zoneElemConn[iElemType].numElem; n--; ) {
          std::memcpy(tmp, aConn, numVPE*sizeof(int));
          for(int iV = 0; iV != numVPE; ++iV) aConn[tr[iV]] = tmp[iV];
          aConn += numVPE;
        }
      }
    }
  }
}

/*******************************************************************************
 *
 * Routine expand_name
 *
 * Purpose
 * =======
 *
 *   Expands variables in a string 's' that are supported by the CGNS I/O.  's'
 *   is overwritten with the expanded string.
 *
 *   - &I[0][%width]% expands into 'index'.  Normally 'index' is assumed to have
 *     C numbering and therefore 1 is added to it.  Option [0] prevents the
 *     addition of the one.  Option [%width] sets the width of the index to
 *     'width' and pads with leading zeros.
 *   - &N& expands to 'name'.
 *
 ******************************************************************************/

void expand_name(std::string &s, const int index, const char *const name)
{  
  std::string::size_type r1 = s.find('&');
  // Look for and replace "&-&" sub-strings
  while(r1 != std::string::npos) {
    const std::string::size_type r2 = s.find('&', r1+1);
    if(r2 == std::string::npos) {
      s.replace(r1, s.length()-r1, "");
    }
    else {
      const int rn = r2 - r1 + 1;
      switch(s[r1+1]) {
      case 'I':
        // &I[0][%width]&
        {
          int iplus = 1;
          if(s[r1+2] == '0') iplus = 0;
          char fmt[6] = "%d";
          const std::string::size_type f = s.find('%', r1+1);
          if(f != std::string::npos && f < r2) {
            int w = std::atoi(s.substr(f+1, r2-f-1).c_str());
            if(w > 0 && w < 33) std::sprintf(fmt, "%%0%dd", w);
          }
          s.replace(r1, rn, CGNSNameStr(index+iplus, fmt).c_str());
          break;
        }
      case 'N':
        // &N&
        s.replace(r1, rn, name);
        break;
      default:
        s.replace(r1, rn, "");
      }
    }
    if(s.length() > 1024) s = "";  // idiot/recursive check
    r1 = s.find('&');
  }

}


/*******************************************************************************
 *
 * Routine get_zone_definition
 *
 * Purpose
 * =======
 *
 *   Defines the next zone based on physicals or partitions and provides a name
 *   for the zone
 *
 * I/O
 * ===
 *
 *   model              - (I) gmsh model
 *   zoneDefinition     - (I) how to define the zone (see enum in code)
 *   numZone            - (I) Number of zones in the domain
 *   options            - (I) options for CGNS I/O
 *   meshDim            - (I) dimension of the mesh elements
 *   group              - (I) the group of physicals used to define the mesh
 *   globalZoneIndex    - (I/O)
 *   globalPhysicalIt   - (I/O) a global scope iterator to the physicals
 *   zoneIndex          - (O) index of the zone
 *   partition          - (O) partition of the zone
 *   physicalItBegin    - (O) begin physical for defining the zone
 *   physicalItEnd      - (O) end physical for defining the zone
 *   zoneName           - (O) name of the zone
 *
 ******************************************************************************/

int get_zone_definition(GModel &model, const int zoneDefinition,
                        const int numZone, const CGNSOptions &options,
                        const int meshDim,
                        const PhysGroupMap &group, int &globalZoneIndex,
                        PhysGroupMap::const_iterator &globalPhysicalIt,
                        int &zoneIndex, int &partition,
                        PhysGroupMap::const_iterator &physicalItBegin,
                        PhysGroupMap::const_iterator &physicalItEnd,
                        CGNSNameStr &zoneName)
{

  int status = 0;
  const char *_zoneName = "Partition";

//--Get indices for the zonex

#pragma omp critical (get_zone_definition)
  {
    if(globalZoneIndex >= numZone) status = 1;
    else {
      switch(zoneDefinition) {
      case 0:  // Single zone
        partition = -1;
        physicalItBegin = group.begin();
        physicalItEnd = group.end();
        break;
      case 1:  // Zone defined by partition
        partition = globalZoneIndex;
        physicalItBegin = group.begin();
        physicalItEnd = group.end();
        break;
      case 2:  // Zone defined by physical
        partition = -1;
        _zoneName = model.getPhysicalName(meshDim, globalPhysicalIt->first)
           .c_str();
        physicalItBegin = globalPhysicalIt++;
        physicalItEnd = globalPhysicalIt;
        break;
      }
      zoneIndex = globalZoneIndex++;
    }
  }
//omp: end critical

//--Set the name for the zone

  if(status == 0) {
    std::string s = options.zoneName;
    expand_name(s, zoneIndex, _zoneName);
    if(s.length() == 0) {  // If empty
      s = "Zone_";
      s += CGNSNameStr(zoneIndex+1).c_str();
    }
    zoneName = s.c_str();
  }

  return status;

}


/*******************************************************************************
 *
 * Routine write_CGNS_zone
 *
 * Purpose
 * =======
 *
 *   Writes the CGNS zones, splitting up the work between several processors if
 *   threads are enabled.
 *
 * I/O
 * ===
 *
 *   model              - (I) 
 *   zoneDefinition     - (I) how to define a zone
 *   options            - (I) CGNS specific options
 *   scalingFactor
 *   vectorDim          - (I) Dimensions of a vector (must be 3 for a 3D mesh,
 *                            may be 2 or 3 for a 2D mesh)
 *   group              - (I) Group of physicals and associated entities
 *   cgIndexFile        - (I) index of the CGNS file node
 *   cgIndexBase        - (I) index of the CGNS base node
 *
 ******************************************************************************/

/*--------------------------------------------------------------------*
 * Required types
 *--------------------------------------------------------------------*/

//--A task for a thread

template <unsigned DIM>
struct ZoneTask 
{
  MZone<DIM> zone;
  CGNSNameStr zoneName;
  int zoneIndex;
  int status;                           // 0 - free
                                        // 1 - zone processed and waiting in
                                        //     queue to be written
                                        // 2 - zone defined and boundaries
                                        //     processed
  int indexInOwner;
  ZoneTask() : status(0), indexInOwner(0) { }
  void change_status(const int _status) 
  {
#pragma omp atomic
    status = _status;
  }
};

//--Information about a zone

struct ZoneInfo 
{
  CGNSNameStr name;
  int cgIndex;
  ZoneInfo() : cgIndex(-1) { }
};

template <unsigned DIM>
int write_CGNS_zones(GModel &model, const int zoneDefinition, const int numZone,
                     const CGNSOptions &options, const double scalingFactor,
                     const int vectorDim, const PhysGroupMap &group,
                     const int cgIndexFile, const int cgIndexBase)
{

//--Shared data

  int threadsWorking = omp_get_num_threads();
                                        // Semaphore for working threads
  omp_lock_t threadWLock;
  std::queue<ZoneTask<DIM>*> zoneQueue; // Queue for zones that have been
                                        // defined and are ready to be written
  omp_lock_t queueLock;
  // Next two are locked by an omp critical
  int globalZoneIndex = 0;
  PhysGroupMap::const_iterator globalPhysicalIt = group.begin();

//--Initialize omp locks

  omp_init_lock(&threadWLock);
  omp_init_lock(&queueLock);

//**Spawn threads

  {

//--Master thread (primary task is to define boundary connections and perform
//--I/O but can also process a zone if idle)

    if(omp_get_thread_num() == 0) {
      ZoneTask<DIM> zoneTask;
      MZoneBoundary<DIM> mZoneBoundary;
      ZoneConnMap zoneConnMap;          // Zone connectivity that is generated
                                        // whenever a zone is added to
                                        // mZoneBoundary
      std::vector<ZoneInfo> zoneInfo; zoneInfo.resize(16);
      std::vector<double> dBuffer;      // Buffer for double-precision data
      std::vector<int> iBuffer1, iBuffer2;
                                        // Buffers for integer data
      int interfaceIndex = 0;           // Index for interfaces

      while (threadsWorking || zoneQueue.size()) {
        if (zoneQueue.size()) {

/*--------------------------------------------------------------------*
 * Write the zone in the queue
 *--------------------------------------------------------------------*/

          ZoneTask<DIM> *const writeTask = zoneQueue.front();
          MZone<DIM> *const writeZone = &writeTask->zone;

//--Write the zone

          // Write the zone node
          int cgIndexZone;
          int cgZoneSize[3];
          cgZoneSize[0] = writeZone->zoneVertVec.size();  // Number of vertices
#ifdef CGNS_TEST1
          // Count all the sub-elements in a Triangle 10
          cgZoneSize[1] = 0;
          for(int iElemType = 0; iElemType != MSH_NUM_TYPE; ++iElemType) {
            switch(iElemType) {
            case MSH_TRI_10-1:
              cgZoneSize[1] += writeZone->zoneElemConn[MSH_TRI_10-1].numElem*9;
              break;
            default:
              cgZoneSize[1] += writeZone->zoneElemConn[iElemType].numElem;
              break;
            }
          }
#else
          cgZoneSize[1] = writeZone->totalElements();  // Number of elements
#endif
          cgZoneSize[2] = writeZone->numBoVert;  // Number of boundary vertices
          if(cg_zone_write(cgIndexFile, cgIndexBase,
                           writeTask->zoneName.c_str(), cgZoneSize,
                           Unstructured, &cgIndexZone))
            return cgnsErr();
          // Manually maintain the size of the 'zoneInfo vector'.  'push_back'
          // is not used because the elements are in order of 'zoneIndex'
          if(writeTask->zoneIndex >= zoneInfo.size())
            zoneInfo.resize(std::max(2*static_cast<int>(zoneInfo.size()),
                                     writeTask->zoneIndex));
          zoneInfo[writeTask->zoneIndex].name = writeTask->zoneName;
          zoneInfo[writeTask->zoneIndex].cgIndex = cgIndexZone;

          // Write the grid node
          int cgIndexGrid;
          if(cg_grid_write(cgIndexFile, cgIndexBase, cgIndexZone,
                           "GridCoordinates", &cgIndexGrid))
            return cgnsErr();

          // Write the grid coordinates
          int cgIndexCoord;
          dBuffer.resize(cgZoneSize[0]);
          // x
          for(int i = 0; i != cgZoneSize[0]; ++i) 
              dBuffer[i] = writeZone->zoneVertVec[i]->x()*scalingFactor;
          if(cg_coord_write(cgIndexFile, cgIndexBase, cgIndexZone, RealDouble,
                            "CoordinateX", &dBuffer[0], &cgIndexCoord))
            return cgnsErr();
          // y
          for(int i = 0; i != cgZoneSize[0]; ++i)
            dBuffer[i] = writeZone->zoneVertVec[i]->y()*scalingFactor;
          if(cg_coord_write(cgIndexFile, cgIndexBase, cgIndexZone, RealDouble,
                            "CoordinateY", &dBuffer[0], &cgIndexCoord))
            return cgnsErr();
          // z
          if(vectorDim == 3) {
            for(int i = 0; i != cgZoneSize[0]; ++i)
              dBuffer[i] = writeZone->zoneVertVec[i]->z()*scalingFactor;
            if(cg_coord_write(cgIndexFile, cgIndexBase, cgIndexZone, RealDouble,
                              "CoordinateZ", &dBuffer[0], &cgIndexCoord))
              return cgnsErr();
          }

          // Obtain indices sorted in the order the CGNS elements will be
          // written
          int indexElemType[MSH_NUM_TYPE];
          for(int i = 0; i != MSH_NUM_TYPE; ++i) indexElemType[i] = i;
          std::sort<int*, ElemSortCGNSType>
            (indexElemType, indexElemType + MSH_NUM_TYPE,
             ElemSortCGNSType(writeZone->zoneElemConn));

          // Write the element connectivity
          const int numElemType = writeZone->numElementTypes();
          int iElemSection = 0;
          for(int iElemType = 0; iElemType != numElemType; ++iElemType) {
            const int typeMSHm1 = indexElemType[iElemType];  // typeMSH-1
            const int typeCGNS = msh2cgns[typeMSHm1][0];
            const char *elemName;
            MElement::getInfoMSH(typeMSHm1+1, &elemName);
#ifdef CGNS_TEST1
            if(typeMSHm1 == MSH_TRI_10-1) {
              const int nElem3o = writeZone->zoneElemConn[20].numElem;
              const int nElem1o = nElem3o*9;
              std::vector<int> subConn(nElem1o*3);
              int iV = 0;
              for(int iElem3o = 0; iElem3o != nElem3o; ++iElem3o) {
                int *elem3o =
                  &writeZone->zoneElemConn[20].connectivity[iElem3o*10];
                subConn[iV++] = elem3o[9];
                subConn[iV++] = elem3o[8];
                subConn[iV++] = elem3o[3];
                subConn[iV++] = elem3o[5];
                subConn[iV++] = elem3o[9];
                subConn[iV++] = elem3o[4];
                subConn[iV++] = elem3o[6];
                subConn[iV++] = elem3o[7];
                subConn[iV++] = elem3o[9];
                subConn[iV++] = elem3o[3];
                subConn[iV++] = elem3o[4];
                subConn[iV++] = elem3o[9];
                subConn[iV++] = elem3o[9];
                subConn[iV++] = elem3o[5];
                subConn[iV++] = elem3o[6];
                subConn[iV++] = elem3o[8];
                subConn[iV++] = elem3o[9];
                subConn[iV++] = elem3o[7];
                subConn[iV++] = elem3o[0];
                subConn[iV++] = elem3o[3];
                subConn[iV++] = elem3o[8];
                subConn[iV++] = elem3o[4];
                subConn[iV++] = elem3o[1];
                subConn[iV++] = elem3o[5];
                subConn[iV++] = elem3o[7];
                subConn[iV++] = elem3o[6];
                subConn[iV++] = elem3o[2];
              }
              elemName = "Sub-Triangle 10";
              int cgIndexSection;
              if(cg_section_write
                 (cgIndexFile, cgIndexBase, cgIndexZone, elemName,
                  TRI_3, iElemSection + 1,
                  nElem1o + iElemSection,
                  writeZone->zoneElemConn[20].numBoElem*9 + iElemSection,
                  &subConn[0], &cgIndexSection))
                return cgnsErr();
              ++iElemSection;
            }
            else
#endif
            if(typeCGNS == -1) {
              // This type is not supported in CGNS
              Msg::Warning("Element type %s is not supported in CGNS and "
                               "has not been written to the file", elemName);
            }
            else {
              int cgIndexSection;
              if(cg_section_write
                 (cgIndexFile, cgIndexBase, cgIndexZone, elemName,
                  static_cast<ElementType_t>(typeCGNS), iElemSection + 1,
                  writeZone->zoneElemConn[typeMSHm1].numElem + iElemSection,
                  writeZone->zoneElemConn[typeMSHm1].numBoElem + iElemSection,
                  &writeZone->zoneElemConn[typeMSHm1].connectivity[0],
                  &cgIndexSection))
                return cgnsErr();
              ++iElemSection;
            }
          }

//--Process interior connectivity

          mZoneBoundary.interiorBoundaryVertices(writeTask->zoneIndex,
                                                 *writeZone, zoneConnMap);
          // Write the connectivity for each zone pair
          const ZoneConnMap::const_iterator gCEnd = zoneConnMap.end();
          for(ZoneConnMap::const_iterator gCIt = zoneConnMap.begin();
              gCIt != gCEnd; ++gCIt) {
            const int nVert = gCIt->second.vertexPairVec.size();
            iBuffer1.resize(nVert);
            iBuffer2.resize(nVert);
            for(int iVert = 0; iVert != nVert; ++iVert) {
              const ZoneConnectivity::VertexPair &vp =
                gCIt->second.vertexPairVec[iVert];
              iBuffer1[iVert] = vp.vertexIndex1;
              iBuffer2[iVert] = vp.vertexIndex2;
            }
            int cgIndexInterface;
            std::string interfaceName = options.interfaceName;
            expand_name(interfaceName, interfaceIndex++, "Interface");
            if(interfaceName.length() == 0) {
              interfaceName = "Interface_";
              interfaceName += CGNSNameStr(interfaceIndex).c_str();
            }
            // In the first zone
            if(cg_conn_write
               (cgIndexFile, cgIndexBase, zoneInfo[gCIt->first.zone1].cgIndex,
                interfaceName.c_str(), Vertex, Abutting1to1, PointList, nVert,
                &iBuffer1[0], zoneInfo[gCIt->first.zone2].name.c_str(),
                Unstructured, PointListDonor, Integer, nVert, &iBuffer2[0],
                &cgIndexInterface))
              return cgnsErr();
            // In the second zone
            if(cg_conn_write
               (cgIndexFile, cgIndexBase, zoneInfo[gCIt->first.zone2].cgIndex,
                interfaceName.c_str(), Vertex, Abutting1to1, PointList, nVert,
                &iBuffer2[0], zoneInfo[gCIt->first.zone1].name.c_str(),
                Unstructured, PointListDonor, Integer, nVert, &iBuffer1[0],
                &cgIndexInterface))
              return cgnsErr();
          }

//--Pop from the queue

          omp_set_lock(&queueLock);
          zoneQueue.pop();
          omp_unset_lock(&queueLock);

//--Task finished

          writeTask->change_status(0);
        }

/*--------------------------------------------------------------------*
 * No zones waiting in the queue, process a zone
 *--------------------------------------------------------------------*/

        else {
          PhysGroupMap::const_iterator physicalItBegin;
          PhysGroupMap::const_iterator physicalItEnd;
          int zoneIndex;
          int partition;
          if(get_zone_definition
             (model, zoneDefinition, numZone, options, DIM, group,
              globalZoneIndex, globalPhysicalIt, zoneTask.zoneIndex, partition,
              physicalItBegin, physicalItEnd, zoneTask.zoneName)) {
            omp_set_lock(&threadWLock);
            --threadsWorking;
            omp_unset_lock(&threadWLock);
          }
          else {
            zoneTask.zone.clear();
            // Loop through all physical in the zone definition
            for(PhysGroupMap::const_iterator physicalIt = physicalItBegin;
                physicalIt != physicalItEnd; ++physicalIt) {
              // Add elements from all entities in the physical with defined
              // partition number
              if(partition == -1) {
                zoneTask.zone.template add_elements_in_entities
                  <typename std::vector<GEntity*>::const_iterator>
                  (physicalIt->second.begin(), physicalIt->second.end());
              }
              else {
                zoneTask.zone.template add_elements_in_entities
                  <typename std::vector<GEntity*>::const_iterator>
                  (physicalIt->second.begin() + partition,
                   physicalIt->second.begin() + (partition+1));
              }
            }
            // Process the zone
            zoneTask.zone.zoneData();
            translateElementMSH2CGNS(zoneTask.zone.zoneElemConn);
            // Add to the queue to get written
            zoneTask.change_status(1);
            omp_set_lock(&queueLock);
            zoneQueue.push(&zoneTask);
            omp_unset_lock(&queueLock);
          }
        }
      }  // End master thread loop

/*--------------------------------------------------------------------*
 * Write the remaining unconnected vertices as boundary conditions
 *--------------------------------------------------------------------*/

      if(options.writeBC) {
        ZoneBoVec zoneBoVec;            // from 'MZoneBoundary.h'
        if(mZoneBoundary.exteriorBoundaryVertices
           (options.normalSource, zoneBoVec) == 0) {

          // Sort by zone index and then entity index
          const int numBoVert = zoneBoVec.size();
          std::vector<int> iZBV(numBoVert);
          for(int i = 0; i != numBoVert; ++i) iZBV[i] = i;
          std::sort<int*, ZoneBoVecSort>(&iZBV[0], &iZBV[numBoVert],
                                         ZoneBoVecSort(zoneBoVec));

          dBuffer.reserve(1024);
          iBuffer1.reserve(1024);

          int iVert = 0;
          while(iVert != numBoVert) {
            dBuffer.clear();
            iBuffer1.clear();
            const int zoneIndex = zoneBoVec[iZBV[iVert]].zoneIndex;
            const int patchIndex = zoneBoVec[iZBV[iVert]].bcPatchIndex;
            const int iVertStart = iVert;
            while(iVert != numBoVert &&
                  zoneBoVec[iZBV[iVert]].zoneIndex == zoneIndex &&
                  zoneBoVec[iZBV[iVert]].bcPatchIndex == patchIndex) {
              VertexBoundary &vertBo = zoneBoVec[iZBV[iVert]];
              dBuffer.push_back(vertBo.normal[0]);
              dBuffer.push_back(vertBo.normal[1]);
              if(vectorDim == 3) dBuffer.push_back(vertBo.normal[2]);
              iBuffer1.push_back(vertBo.vertexIndex);
              ++iVert;
            }
            const int numBCVert = iVert - iVertStart;

            int cgIndexBoco;
            std::string patchName = options.patchName;
            expand_name(patchName, patchIndex, "Patch");
            if(patchName.length() == 0) {
              patchName = "Patch_";
              patchName += CGNSNameStr(patchIndex+1).c_str();
            }
            if(cg_boco_write(cgIndexFile, cgIndexBase,
                             zoneInfo[zoneIndex].cgIndex, patchName.c_str(),
                             BCTypeNull, PointList, numBCVert, &iBuffer1[0],
                             &cgIndexBoco))
              return cgnsErr();

            if(options.normalSource) {
              int normalIndex;
              if(cg_boco_normal_write(cgIndexFile, cgIndexBase,
                                      zoneInfo[zoneIndex].cgIndex, cgIndexBoco,
                                      &normalIndex, 1, RealDouble, &dBuffer[0]))
                return cgnsErr();
            }
          }
        }
      }

//       std::cout << "Leaving master thread\n";  // DBG
    }  // End master thread instructions

  }  // End omp parallel section

//--Destroy omp locks

  omp_destroy_lock(&threadWLock);
  omp_destroy_lock(&queueLock);

}

#else

int GModel::readCGNS(const std::string &name)
{
  Msg::Error("This version of Gmsh was compiled without CGNS support");
  return 0;
}

int GModel::writeCGNS(const std::string &name, int zoneDefinition,
                      const CGNSOptions &options, double scalingFactor)
{
  Msg::Error("This version of Gmsh was compiled without CGNS support");
  return 0;
}

#endif
