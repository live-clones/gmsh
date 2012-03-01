// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// GModelIO_CGNS.cpp - Copyright (C) 2008-2012 S. Guzik, B. Gorissen, C. Geuzaine, J.-F. Remacle

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
#include <math.h>

#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <unistd.h>

#include "gmshVertex.h"
#include "gmshRegion.h"
#include "Geo.h"
//#include "cgnsWindow.h"
//#include "manipWindow.h"
#include "extraDialogs.h"
#include "FlGui.h"
#include "Context.h"
#include "Options.h"

#include "MZone.h"
#include "MZoneBoundary.h"

#include <cgnslib.h>

using namespace std;

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



static MElement *createElementMSH(GModel *m, int num, int typeMSH, int reg, int part,
                                     std::vector<MVertex*> &v, std::map<int, std::vector<MElement*> > elements[10])
{
  /*
  if(CTX::instance()->mesh.switchElementTags) {
    int tmp = reg;
    reg = physical;
    physical = reg;
  }
  */
  MElementFactory factory;
  MElement *e = factory.create(typeMSH, v, num, part, false, 0, 0, 0);

  if(!e){
    Msg::Error("Unknown type of element %d", typeMSH);
    return NULL;
  }

  switch(e->getType()){
  case TYPE_PNT :
    elements[0][reg].push_back(e); break;
  case TYPE_LIN :
    elements[1][reg].push_back(e); break;
  case TYPE_TRI :
    elements[2][reg].push_back(e); break;
  case TYPE_QUA :
    elements[3][reg].push_back(e); break;
  case TYPE_TET :
    elements[4][reg].push_back(e); break;
  case TYPE_HEX :
    elements[5][reg].push_back(e); break;
  case TYPE_PRI :
    elements[6][reg].push_back(e); break;
  case TYPE_PYR :
    elements[7][reg].push_back(e); break;
  case TYPE_POLYG :
    elements[8][reg].push_back(e); break;
  case TYPE_POLYH :
    elements[9][reg].push_back(e); break;
  default : Msg::Error("Wrong type of element"); return NULL;
  }

  int dim = e->getDim();
  /*
  if(physical && (!physicals[dim].count(reg) || !physicals[dim][reg].count(physical)))
    physicals[dim][reg][physical] = "unnamed";
  */
  if(part) m->getMeshPartitions().insert(part);
  return e;
}

static int to1D(int i, int j, int k, int max_i, int max_j, int max_k) {
  return k*max_i*max_j + j*max_i + i;
}

static int getIndicesQuad(int i1, int i2, int i3, int i4, 
			  int j1, int j2, int j3, int j4,
			  int k1, int k2, int k3, int k4,
			  std::vector<int>& ind_i, std::vector<int>& ind_j, std::vector<int>& ind_k, int order, int f) {

  static const int offset[6][4][3] = {
    {{ 1, 1, 0}, { 1,-1, 0}, {-1,-1, 0}, {-1, 1, 0}},
    {{ 1, 1 ,0}, {-1, 1, 0}, {-1,-1, 0}, { 1,-1, 0}},
    {{ 1, 0, 1}, {-1, 0, 1}, {-1, 0,-1}, { 1, 0,-1}},
    {{ 1, 0, 1}, { 1, 0,-1}, {-1, 0,-1}, {-1, 0, 1}},
    {{ 0, 1, 1}, { 0, 1,-1}, { 0,-1,-1}, { 0,-1, 1}},
    {{ 0, 1, 1}, { 0,-1, 1}, { 0,-1,-1}, { 0, 1,-1}}
  };  

  int added = 0;

  if (order == 0) {
    ind_i.push_back(i1); ind_j.push_back(j1); ind_k.push_back(k1);
    return 1;
  }

  // corners
  ind_i.push_back(i1); ind_j.push_back(j1); ind_k.push_back(k1);
  ind_i.push_back(i2); ind_j.push_back(j2); ind_k.push_back(k2);
  ind_i.push_back(i3); ind_j.push_back(j3); ind_k.push_back(k3);
  ind_i.push_back(i4); ind_j.push_back(j4); ind_k.push_back(k4);  
  
  added += 4;
  
  // edge points
  if (order > 1) {
    // edge 1
    for (int v = 1; v < order; v++) {
      ind_i.push_back(i1+v*(i2-i1)/order); 
      ind_j.push_back(j1+v*(j2-j1)/order); 
      ind_k.push_back(k1+v*(k2-k1)/order);
      added++;
    }

    // edge 2
    for (int v = 1; v < order; v++) {
      ind_i.push_back(i2+v*(i3-i2)/order); 
      ind_j.push_back(j2+v*(j3-j2)/order); 
      ind_k.push_back(k2+v*(k3-k2)/order);
      added++;
    }

    // edge 3
    for (int v = 1; v < order; v++) {
      ind_i.push_back(i3+v*(i4-i3)/order); 
      ind_j.push_back(j3+v*(j4-j3)/order); 
      ind_k.push_back(k3+v*(k4-k3)/order);
      added++;
    }

    // edge 4
    for (int v = 1; v < order; v++) {
      ind_i.push_back(i4+v*(i1-i4)/order); 
      ind_j.push_back(j4+v*(j1-j4)/order); 
      ind_k.push_back(k4+v*(k1-k4)/order);
      added++;
    }
  
  /*
  int ioffset = (i3-i1)/abs(i2-i1);
  int joffset = (j3-j1)/abs(j2-j1);
  int koffset = (k3-k1)/abs(k2-k1);
  */
  added += getIndicesQuad(i1+offset[f][0][0], i2+offset[f][1][0], i3+offset[f][2][0], i4+offset[f][3][0],
			  j1+offset[f][0][1], j2+offset[f][1][1], j3+offset[f][2][1], j4+offset[f][3][1],
			  k1+offset[f][0][2], k2+offset[f][1][2], k3+offset[f][2][2], k4+offset[f][3][2],
			  ind_i, ind_j, ind_k, order-2, f);
  /**/
  }
  return added;
}

static int getIndicesFace(int i1, int i2, int i3, int i4, int j1, int j2, int j3, int j4, int k1, int k2, int k3, int k4, std::vector<int>& ind_i, std::vector<int>& ind_j, std::vector<int>& ind_k, int order, int f) {

  static const int offset[6][4][3] = {
    {{ 1, 1, 0}, { 1,-1, 0}, {-1,-1, 0}, {-1, 1, 0}},
    {{ 1, 0, 1}, {-1, 0, 1}, {-1, 0,-1}, { 1, 0,-1}},
    {{ 0, 1, 1}, { 0, 1,-1}, { 0,-1,-1}, { 0,-1, 1}},
    {{ 0, 1, 1}, { 0,-1, 1}, { 0,-1,-1}, { 0, 1,-1}},
    {{-1, 0, 1}, { 1, 0, 1}, { 1, 0,-1}, {-1, 0,-1}},
    {{ 1, 1 ,0}, {-1, 1, 0}, {-1,-1, 0}, { 1,-1, 0}}
  };  

  int added = 0;

  if (order == 0) {
    ind_i.push_back(i1); ind_j.push_back(j1); ind_k.push_back(k1);
    return 1;
  }

  // corners
  ind_i.push_back(i1); ind_j.push_back(j1); ind_k.push_back(k1);
  ind_i.push_back(i2); ind_j.push_back(j2); ind_k.push_back(k2);
  ind_i.push_back(i3); ind_j.push_back(j3); ind_k.push_back(k3);
  ind_i.push_back(i4); ind_j.push_back(j4); ind_k.push_back(k4);  
  
  added += 4;
  
  // edge points
  if (order > 1) {
    // edge 1
    for (int v = 1; v < order; v++) {
      ind_i.push_back(i1+(i2-i1)/order); 
      ind_j.push_back(j1+(j2-j1)/order); 
      ind_k.push_back(k1+(k2-k1)/order);
      added++;
    }

    // edge 2
    for (int v = 1; v < order; v++) {
      ind_i.push_back(i2+(i3-i2)/order); 
      ind_j.push_back(j2+(j3-j2)/order); 
      ind_k.push_back(k2+(k3-k2)/order);
      added++;
    }

    // edge 3
    for (int v = 1; v < order; v++) {
      ind_i.push_back(i3+(i4-i3)/order); 
      ind_j.push_back(j3+(j4-j3)/order); 
      ind_k.push_back(k3+(k4-k3)/order);
      added++;
    }

    // edge 4
    for (int v = 1; v < order; v++) {
      ind_i.push_back(i4+(i1-i4)/order); 
      ind_j.push_back(j4+(j1-j4)/order); 
      ind_k.push_back(k4+(k1-k4)/order);
      added++;
    }
  }
  /*
  int ioffset = (i3-i1)/abs(i2-i1);
  int joffset = (j3-j1)/abs(j2-j1);
  int koffset = (k3-k1)/abs(k2-k1);
  */
  added += getIndicesFace(i1+offset[f][0][0], i2-offset[f][1][0], i3-offset[f][2][0], i4+offset[f][3][0],
			  j1+offset[f][0][1], j2-offset[f][1][1], j3-offset[f][2][1], j4+offset[f][3][1],
			  k1+offset[f][0][2], k2-offset[f][1][2], k3-offset[f][2][2], k4+offset[f][3][2],
			  ind_i, ind_j, ind_k, order-2, f);
  /**/
  return added;
}

static void getIndices(int i, int j, int k, std::vector<int>& ind_i, std::vector<int>& ind_j, std::vector<int>& ind_k, int order, int startpoint=0) {

  static const int edges[12][2] = {
    {0, 1},
    {0, 3},
    {0, 4},
    {1, 2},
    {1, 5},
    {2, 3},
    {2, 6},
    {3, 7},
    {4, 5},
    {4, 7},
    {5, 6},
    {6, 7}
  };
  static const int faces[6][4] = {
    {0, 3, 2, 1},
    {0, 1, 5, 4},
    {0, 4, 7, 3},
    {1, 2, 6, 5},
    {2, 3, 7, 6},
    {4, 5, 6, 7}
  };

  static const int offset[6][4][3] = {
    {{ 1, 1, 0}, { 1,-1, 0}, {-1,-1, 0}, {-1, 1, 0}},
    {{ 1, 0, 1}, {-1, 0, 1}, {-1, 0,-1}, { 1, 0,-1}},
    {{ 0, 1, 1}, { 0, 1,-1}, { 0,-1,-1}, { 0,-1, 1}},
    {{ 0, 1, 1}, { 0,-1, 1}, { 0,-1,-1}, { 0, 1,-1}},
    {{-1, 0, 1}, { 1, 0, 1}, { 1, 0,-1}, {-1, 0,-1}},
    {{ 1, 1 ,0}, {-1, 1, 0}, {-1,-1, 0}, { 1,-1, 0}}
  };  


  if (order == 0) {
      ind_i.push_back(i); ind_j.push_back(j); ind_k.push_back(k);
      return;
  }

  // 8 principal points
  ind_i.push_back(i);       ind_j.push_back(j);       ind_k.push_back(k);
  ind_i.push_back(i+order); ind_j.push_back(j);       ind_k.push_back(k);
  ind_i.push_back(i+order); ind_j.push_back(j+order); ind_k.push_back(k);
  ind_i.push_back(i);       ind_j.push_back(j+order); ind_k.push_back(k);
  ind_i.push_back(i);       ind_j.push_back(j);       ind_k.push_back(k+order);
  ind_i.push_back(i+order); ind_j.push_back(j);       ind_k.push_back(k+order);
  ind_i.push_back(i+order); ind_j.push_back(j+order); ind_k.push_back(k+order);
  ind_i.push_back(i);       ind_j.push_back(j+order); ind_k.push_back(k+order);

  int initial_point = startpoint + 8;

  if (order > 1) {

    // edges
    for (int e = 0; e < 12; e++) {
      int p0_i = ind_i[startpoint+edges[e][0]];
      int p0_j = ind_j[startpoint+edges[e][0]];
      int p0_k = ind_k[startpoint+edges[e][0]];
      int p1_i = ind_i[startpoint+edges[e][1]];
      int p1_j = ind_j[startpoint+edges[e][1]];
      int p1_k = ind_k[startpoint+edges[e][1]];
      
      for (int v = 1; v < order; v++) {
	ind_i.push_back(p0_i + v*((p1_i-p0_i)/order));
	ind_j.push_back(p0_j + v*((p1_j-p0_j)/order));
	ind_k.push_back(p0_k + v*((p1_k-p0_k)/order));
	initial_point++;
      }
    }

    // faces
    for (int f = 0; f < 6; f++) {
      int i1 = ind_i[startpoint+faces[f][0]] + offset[f][0][0];
      int i2 = ind_i[startpoint+faces[f][1]] + offset[f][1][0];
      int i3 = ind_i[startpoint+faces[f][2]] + offset[f][2][0];
      int i4 = ind_i[startpoint+faces[f][3]] + offset[f][3][0];
      
      int j1 = ind_j[startpoint+faces[f][0]] + offset[f][0][1];
      int j2 = ind_j[startpoint+faces[f][1]] + offset[f][1][1];
      int j3 = ind_j[startpoint+faces[f][2]] + offset[f][2][1];
      int j4 = ind_j[startpoint+faces[f][3]] + offset[f][3][1];
      
      int k1 = ind_k[startpoint+faces[f][0]] + offset[f][0][2];
      int k2 = ind_k[startpoint+faces[f][1]] + offset[f][1][2];
      int k3 = ind_k[startpoint+faces[f][2]] + offset[f][2][2];
      int k4 = ind_k[startpoint+faces[f][3]] + offset[f][3][2];
      initial_point+= getIndicesFace(i1, i2, i3, i4,
				      j1, j2, j3, j4,
				      k1, k2, k3, k4,
				     ind_i, ind_j, ind_k,
				     order-2, f);
    }
    
    // interior
    getIndices(i+1,j+1,k+1, ind_i, ind_j, ind_k, order-2, initial_point);
  
  }
}

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

  cgsize_t isize[9];   
  char basename[33],zonename[33];
  std::map<int, std::vector<MElement*> > elements[10];


  // Open the CGNS file
  int index_file;
  if (cg_open(name.c_str(), CG_MODE_READ, &index_file)) {
    Msg::Error("Could not open file !");
    return 0;
  }

  // Get the number of bases
  int nBases;
  cg_nbases(index_file, &nBases);
  Msg::Debug("Found %i base(s).", nBases);
  if (nBases > 1) {
    Msg::Warning("Found %i bases in the file, but only the first one will be used to build mesh.", nBases);
  }
  int index_base = 1;

  // Get the number of zones
  int nZones;
  cg_nzones(index_file, index_base, &nZones);
  Msg::Debug("Found %i zone(s).", nZones);

  // Compute the maximum multigrid level
  int max_order = 8;

  // Creating MVertex
  std::map<int, MVertex*> vertexMap;
  int minVertex = 1;
  int maxVertex = 0;
  int vnum = 1;


  for (int index_zone = 1; index_zone <= nZones; index_zone++) {
    Msg::Debug("Reading zone to compute MG level %i.", index_zone);

    ZoneType_t zoneType;
    cg_zone_type(index_file, index_base, index_zone, &zoneType);
    if ( zoneType == Unstructured ) {
      Msg::Debug("Unstructured zone detected, skipping.");
      continue;
    }
    cgsize_t irmin[3];
    cgsize_t irmax[3];
    cgsize_t zoneSizes[9];
    char zoneName[35];
    cg_zone_read(index_file, index_base, index_zone, zoneName, zoneSizes);
    Msg::Debug("Zone name : %s.", zoneName);

    // Index bounds
    irmin[0] = 1; irmax[0] = zoneSizes[0];
    irmin[1] = 1; irmax[1] = zoneSizes[1];
    irmin[2] = 1; irmax[2] = zoneSizes[2];

    // Compute max multigrid level
    double ielem = irmax[0] - 1;
    double jelem = irmax[1] - 1;
    double kelem = irmax[2] - 1;
    int order = 1;
    bool done = false;
    while(fmod(ielem / 2.0, 1.0) == 0.0 && fmod(jelem / 2.0, 1.0) == 0.0 && fmod(kelem / 2.0, 1.0) == 0.0 and order < 5) {
	order*=2;
	ielem = ielem / 2.0;
	jelem = jelem / 2.0;
	kelem = kelem / 2.0;
    }
    max_order = min(order, max_order);
    
  }

  Msg::Debug("Maximum import order : %i", max_order);

  opt_mesh_cgns_import_order(0, GMSH_SET, max_order);;

  int order = CTX::instance()->mesh.cgnsImportOrder;
  if (CTX::instance()->batch == 0 &&  FlGui::instance()->available() && CTX::instance()->expertMode) {
    order = cgnsImport();
  } else {
    order = 1;
  }

  // for entity numbering
  int elementary_region = getNumRegions();
  int elementary_face = getNumFaces();
  int elementary_edge = getNumEdges();
  int elementary_vertex = getNumVertices();

  // Read the zones
  for (int index_zone = 1; index_zone <= nZones; index_zone++) {
    Msg::Debug("Reading zone %i.", index_zone);

    int offset = vnum;

    ZoneType_t zoneType;
    cg_zone_type(index_file, index_base, index_zone, &zoneType);
    if ( zoneType == Unstructured ) {
      Msg::Debug("Unstructured zone detected, skipping.");
      continue;
    }
    
    cgsize_t irmin[3];
    cgsize_t irmax[3];
    cgsize_t zoneSizes[9];
    char zoneName[35];
    cg_zone_read(index_file, index_base, index_zone, zoneName, zoneSizes);
    Msg::Debug("Zone name : %s.", zoneName);

    // Index bounds
    irmin[0] = 1; irmax[0] = zoneSizes[0];
    irmin[1] = 1; irmax[1] = zoneSizes[1];
    irmin[2] = 1; irmax[2] = zoneSizes[2];

    // Compute max multigrid level
    double ielem = irmax[0] - 1;
    double jelem = irmax[1] - 1;
    double kelem = irmax[2] - 1;
    
    int nnodesZone;
    int nelements;
    int nBoundaryVertices;
    nnodesZone        = zoneSizes[0]*zoneSizes[1]*zoneSizes[2];
    nelements         = zoneSizes[3]*zoneSizes[4]*zoneSizes[5];
    nBoundaryVertices = zoneSizes[6]*zoneSizes[7]*zoneSizes[8];
    Msg::Debug("%i nodes, %i elements, and %i vertices on the zone boundary.", nnodesZone, nelements, nBoundaryVertices);

    // Reading the coordinates
    int nCoords;
    cg_ncoords(index_file, index_base, index_zone, &nCoords);
    
    DataType_t dataType;
    char coordName[35];
    void* coord;
    double nodes[nnodesZone][nCoords];
    
    for ( int iCoord = 0; iCoord < nCoords; iCoord++ ) {
      if ( cg_coord_info(index_file, index_base, index_zone, iCoord+1, &dataType, coordName) ) {
	Msg::Error("Could not read coordinate %i.", iCoord+1);
	cg_close (index_file);
	return 0;
      }
      
      Msg::Debug("Reading coordinate %i : %s.", iCoord+1, coordName);

      switch(dataType) {
        case RealSingle:
	  Msg::Debug("        [Type is float]");
	  coord = new float[nnodesZone];
	  if ( cg_coord_read(index_file, index_base, index_zone, coordName, dataType, irmin, irmax, coord)) {
	    Msg::Error("Could not read coordinate %i.", iCoord+1);
	    cg_close(index_file);
	    return 0;
	  }
	  for (int iNode = 0; iNode < nnodesZone; iNode++) {
	    nodes[iNode][iCoord] = (double)((float*)coord)[iNode];
	  }
	  delete [] (float*)coord;
	  break;
        case RealDouble:
	  Msg::Debug("        [Type is double]");
	  coord = new double[nnodesZone];
	  if ( cg_coord_read(index_file, index_base, index_zone, coordName, dataType, irmin, irmax, coord)) {
	    Msg::Error("Could not read coordinate %i.", iCoord+1);
	    cg_close(index_file);
	    return 0;
	  }
	  for (int iNode = 0; iNode < nnodesZone; iNode++) {
	    nodes[iNode][iCoord] = ((double*) coord)[iNode];
	  }
	  delete [] (double*)coord;
	  break;
      }
    }

    for (int iNode = 0; iNode < nnodesZone; iNode++) {
      MVertex* mv = new MVertex(nodes[iNode][0], nodes[iNode][1], nodes[iNode][2], 0, vnum);
      minVertex = std::min(minVertex, vnum);
      maxVertex = std::max(maxVertex, vnum);
      vertexMap[vnum] = mv;
      vnum ++;
    }

    // Creating elements
    int num = 1;

    int type_hex = 5;
    int type_quad = 3;
    int type_line = 1;
    int type_pnt = 15;
    if (order == 2) {
      type_hex = 12;
      type_line = 8;
      type_quad = 10;
    }
    else if (order == 4){
      type_hex = 93;
      type_line = 27;
      type_quad = 37;
    }
    //else if (order == 8)
    //  type = 97;

    int num_elements = 0;
    elementary_region ++;
    int partition = 0;
    for (int i = 0; i < zoneSizes[3]; i+=order) {
      for (int j = 0; j < zoneSizes[4]; j+=order) {
	for (int k = 0; k < zoneSizes[5]; k+=order) {
	  std::vector<MVertex*> vertices;
	  std::vector<int> ind_i, ind_j, ind_k;

	  getIndices(i, j, k, ind_i, ind_j, ind_k, order);

	  for (int v = 0; v < ind_i.size(); v++) {
	    vertices.push_back(vertexMap[offset+to1D(ind_i[v], ind_j[v], ind_k[v],   irmax[0], irmax[1], irmax[2])]);
	  }
	  MElement* e = createElementMSH(this, num, type_hex, elementary_region,
					 partition, vertices, elements);
	  num_elements++;
	  num++;
	}
      }
    }
    
    // Create surface mesh
    std::map<int, std::vector<int*> > forbidden;

    int nconnectivity;
    cg_n1to1(index_file, index_base, index_zone, &nconnectivity);
    Msg::Debug("Found %i connectivity zones.", nconnectivity);
    for (int index_section = 1; index_section <= nconnectivity; index_section++) {

      printf("ping\n");

      char ConnectionName[30];
      char DonorName[30];
      cgsize_t range[6];
      cgsize_t donor_range[6];
      int transform[3];
      cg_1to1_read(index_file, index_base, index_zone,index_section,
		   ConnectionName, DonorName, range, donor_range, transform);
      

      // Checking on which face it is
      int face = 0;
      if (range[0] == range[3]) {
	if (range[0] == 1)
	  face = 4;
	else
	  face = 5;
      } else if (range[1] == range[4]) {
        if (range[1] == 1)
	  face = 2;
	else
	  face = 3;
      } else if (range[2] == range[5]) {
        if (range[2] == 1)
	  face = 0;
	else
	  face = 1;	
      }

      printf("Face %i\n", face);

      int* range_int = new int[6];

      // Do not ignore periodic boundaries when creating elements later on.
      float RotationCenter[3];
      float RotationAngle[3];
      float Translation[3];
      if (cg_1to1_periodic_read(index_file, index_base, index_zone, index_section,
				RotationCenter, RotationAngle, Translation) != CG_NODE_NOT_FOUND) {
	continue;
      }

      
      for (int r = 0; r < 6; r++) {	
	range_int[r] = (int)range[r];
	printf("%i ", range_int[r]);
      }
      forbidden[face].push_back(range_int);

      printf("\npong\n");
    }

    


    for(int face = 0; face < 6; face++) {
      int imin, imax, jmin, jmax, kmin, kmax;
      int igrow = order;
      int jgrow = order;
      int kgrow = order;
      int move[3][4];
      switch(face) {
      case 0:
       	imin = 0; imax = zoneSizes[3];
	jmin = 0; jmax = zoneSizes[4];
	kmin = 0; kmax = 1; kgrow = 0;
	move[0][0] = 0; move[0][1] = 0;     move[0][2] = igrow; move[0][3] = igrow;
	move[1][0] = 0; move[1][1] = jgrow; move[1][2] = jgrow; move[1][3] = 0;
	move[2][0] = 0; move[2][1] = 0;     move[2][2] = 0;     move[2][3] = 0;
	break;
      case 1:
	imin = 0; imax = zoneSizes[3];
	jmin = 0; jmax = zoneSizes[4];
	kmin = zoneSizes[2]-1; kmax = zoneSizes[2]; kgrow = 0;
	move[0][0] = 0; move[0][1] = igrow; move[0][2] = igrow; move[0][3] = 0;
	move[1][0] = 0; move[1][1] = 0;     move[1][2] = jgrow; move[1][3] = jgrow;
	move[2][0] = 0; move[2][1] = 0;     move[2][2] = 0;     move[2][3] = 0;
	break;
      case 2:
	imin = 0; imax = zoneSizes[3];
	jmin = 0; jmax = 1; jgrow = 0;
	kmin = 0; kmax = zoneSizes[5];
	move[0][0] = 0; move[0][1] = igrow; move[0][2] = igrow; move[0][3] = 0;
	move[1][0] = 0; move[1][1] = 0;     move[1][2] = 0; move[1][3] = 0;
	move[2][0] = 0; move[2][1] = 0;     move[2][2] = kgrow;     move[2][3] = kgrow;
	break;
      case 3:
	imin = 0; imax = zoneSizes[3];
	jmin = zoneSizes[1]-1; jmax = zoneSizes[1]; jgrow = 0;
	kmin = 0; kmax = zoneSizes[5];
	move[0][0] = 0; move[0][1] = 0; move[0][2] = igrow; move[0][3] = igrow;
	move[1][0] = 0; move[1][1] = 0;     move[1][2] = 0; move[1][3] = 0;
	move[2][0] = 0; move[2][1] = kgrow;     move[2][2] = kgrow;     move[2][3] = 0;
	break;
      case 4:
	imin = 0; imax = 1; igrow = 0;
	jmin = 0; jmax = zoneSizes[4];
	kmin = 0; kmax = zoneSizes[5];
	move[0][0] = 0; move[0][1] = 0; move[0][2] = 0; move[0][3] = 0;
	move[1][0] = 0; move[1][1] = 0; move[1][2] = jgrow; move[1][3] = jgrow;
	move[2][0] = 0; move[2][1] = kgrow;     move[2][2] = kgrow;     move[2][3] = 0;
	break;
      case 5:
	imin = zoneSizes[0]-1; imax = zoneSizes[0]; igrow = 0;
	jmin = 0; jmax = zoneSizes[4];
	kmin = 0; kmax = zoneSizes[5];
	move[0][0] = 0; move[0][1] = 0; move[0][2] = 0; move[0][3] = 0;
	move[1][0] = 0; move[1][1] = jgrow; move[1][2] = jgrow; move[1][3] = 0;
	move[2][0] = 0; move[2][1] = 0;     move[2][2] = kgrow;     move[2][3] = kgrow;
	break;
      }
      
      GRegion* gr = getRegionByTag(elementary_region);
      elementary_face++;
      num = 1;
      for (int i = imin; i < imax; i += order) {
	for (int j = jmin; j < jmax;  j += order) {
	  //printf("Creating surface element\n");
	  for (int k = kmin; k < kmax; k += order) {
	    
	    bool ok = true;
	    for (int ff=0; ff < forbidden[face].size(); ff++) {
	      int* lim = forbidden[face][ff];

	      if ((i >= fmin(lim[0], lim[3])-1 && i < fmax(lim[0], lim[3])-1) || (igrow == 0) ) {
		if ((j >= fmin(lim[1], lim[4])-1 && j < fmax(lim[1],lim[4])-1) || (jgrow == 0) ) {
		  if ((k >= fmin(lim[2], lim[5])-1 && k < fmax(lim[2], lim[5])-1) || (kgrow == 0) ) {
		    ok = false;
		  }
		}
	      }
	      //if (!ok) continue;

	    }
	    if (!ok) continue;

	    std::vector<MVertex*> vertices;
	    std::vector<int> ind_i, ind_j, ind_k;
	    
	    getIndicesQuad(i+move[0][0],i+move[0][1], i+move[0][2], i+move[0][3],
			   j+move[1][0],j+move[1][1], j+move[1][2], j+move[1][3],
			   k+move[2][0],k+move[2][1], k+move[2][2], k+move[2][3],
			   ind_i, ind_j, ind_k, order, face);

	    for (int v = 0; v < ind_i.size(); v++) {
	      vertices.push_back(vertexMap[offset+to1D(ind_i[v], ind_j[v], ind_k[v],   irmax[0], irmax[1], irmax[2])]);
	    }
	    MElement* e = createElementMSH(this, num, type_quad, elementary_face,
					   partition, vertices, elements);
	    num_elements++;
	    num++;	    
	  }
	}
      }
      GFace* gf = getFaceByTag(elementary_face);
      if (gf)
	gf->addRegion(gr);

      for (int ff = 0; ff < forbidden[face].size(); ff++)
	  delete[] forbidden[face][ff];
    }
  }

  // store the elements in their associated elementary entity. If the
  // entity does not exist, create a new (discrete) one.
  for(int i = 0; i < (int)(sizeof(elements) / sizeof(elements[0])); i++)
    _storeElementsInEntities(elements[i]);

  // associate the correct geometrical entity with each mesh vertex
  _associateEntityWithMeshVertices();

  // store the vertices in their associated geometrical entity
  _storeVerticesInEntities(vertexMap);

  removeDuplicateMeshVertices(1e-8);
  //createTopologyFromMesh();

  if ( cg_close (index_file) ) {
    Msg::Error("Couldnt close the file !");
    return 0;
  }
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
  int cgIndexFile=0;
  if(cg_open(name.c_str(), CG_MODE_WRITE, &cgIndexFile)) return cgnsErr();

  // write the base node
  int cgIndexBase=0;
  if(cg_base_write(cgIndexFile, options.baseName.c_str(), meshDim, meshDim, 
                   &cgIndexBase)) 
    return cgnsErr();

  // write information about who generated the mesh
  if(cg_goto(cgIndexFile, cgIndexBase, "end")) return(cgnsErr());
  if(cg_descriptor_write("About", "Created by Gmsh")) return cgnsErr();

  switch(meshDim) {
  case 2:
    MZone<2>::preInit();
    MZoneBoundary<2>::preInit();
    write_CGNS_zones<2>(*this, zoneDefinition, numZone, options, 
                        scalingFactor, vectorDim, groups[face], 
                        cgIndexFile, cgIndexBase);
    MZone<2>::postDestroy();
    MZoneBoundary<2>::postDestroy();
    break;
  case 3:
    MZone<3>::preInit();
    MZoneBoundary<3>::preInit();
    write_CGNS_zones<3>(*this, zoneDefinition, numZone, options, 
                        scalingFactor, vectorDim, groups[region], 
                        cgIndexFile, cgIndexBase);
    MZone<3>::postDestroy();
    MZoneBoundary<3>::postDestroy();
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
  // NBN: pass name to expand_name(): Zone_&N& ==> Zone_Fluid
  std::string zn;

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
      //_zoneName = model.getPhysicalName(meshDim, globalPhysicalIt->first).c_str();
        zn = model.getPhysicalName(meshDim, globalPhysicalIt->first);   // NBN:
        _zoneName = zn.c_str();   // NBN:
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
      std::vector<cgsize_t> iBuffer1, iBuffer2;
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
          int cgIndexZone=0;
          cgsize_t cgZoneSize[3]={0};
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
          {
            return cgnsErr();
          }
          // Manually maintain the size of the 'zoneInfo vector'.  'push_back'
          // is not used because the elements are in order of 'zoneIndex'
          if(writeTask->zoneIndex >= zoneInfo.size()) {
            zoneInfo.resize(std::max(2*static_cast<int>(zoneInfo.size()), 
                            writeTask->zoneIndex));
          }
          zoneInfo[writeTask->zoneIndex].name = writeTask->zoneName;
          zoneInfo[writeTask->zoneIndex].cgIndex = cgIndexZone;

          // Write the grid node
          int cgIndexGrid=0;
          if(cg_grid_write(cgIndexFile, cgIndexBase, cgIndexZone,
                           "GridCoordinates", &cgIndexGrid))
            return cgnsErr();

          // Write the grid coordinates
          int cgIndexCoord=0;
          dBuffer.resize(cgZoneSize[0]);

          // x-coordinates for this zone
          for (int i = 0; i != cgZoneSize[0]; ++i) {
            dBuffer[i] = writeZone->zoneVertVec[i]->x()*scalingFactor;
          }
          if(cg_coord_write(cgIndexFile, cgIndexBase, cgIndexZone, RealDouble,
                            "CoordinateX", &dBuffer[0], &cgIndexCoord))
            return cgnsErr();

          // y-coordinates for this zone
          for(int i = 0; i != cgZoneSize[0]; ++i) {
            dBuffer[i] = writeZone->zoneVertVec[i]->y()*scalingFactor;
          }
          if(cg_coord_write(cgIndexFile, cgIndexBase, cgIndexZone, RealDouble,
                            "CoordinateY", &dBuffer[0], &cgIndexCoord))
            return cgnsErr();

          // z-coordinates for this zone
          if(vectorDim == 3) {
            for(int i = 0; i != cgZoneSize[0]; ++i) {
              dBuffer[i] = writeZone->zoneVertVec[i]->z()*scalingFactor;
            }
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
              cgsize_t cgIndexSection;
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
                  (cgsize_t*)&writeZone->zoneElemConn[typeMSHm1].connectivity[0],
                  &cgIndexSection))
              {
                return cgnsErr();
              }
              ++iElemSection;
            }
          }

//--Process interior connectivity

          mZoneBoundary.interiorBoundaryVertices(writeTask->zoneIndex,
                                                 *writeZone, zoneConnMap);
          // Write the connectivity for each zone pair
          const ZoneConnMap::const_iterator gCEnd = zoneConnMap.end();
          for(ZoneConnMap::const_iterator gCIt = zoneConnMap.begin();
              gCIt != gCEnd; ++gCIt) 
          {
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
            {
              return cgnsErr();
            }
            // In the second zone
            if(cg_conn_write
               (cgIndexFile, cgIndexBase, zoneInfo[gCIt->first.zone2].cgIndex,
                interfaceName.c_str(), Vertex, Abutting1to1, PointList, nVert,
                &iBuffer2[0], zoneInfo[gCIt->first.zone1].name.c_str(),
                Unstructured, PointListDonor, Integer, nVert, &iBuffer1[0],
                &cgIndexInterface))
            {
              return cgnsErr();
            }
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
              physicalItBegin, physicalItEnd, zoneTask.zoneName)) 
          {
            omp_set_lock(&threadWLock);
            --threadsWorking;
            omp_unset_lock(&threadWLock);
          }
          else {
            zoneTask.zone.clear();
            // Loop through all physical in the zone definition
            for(PhysGroupMap::const_iterator physicalIt = physicalItBegin;
                physicalIt != physicalItEnd; ++physicalIt) 
            {
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

      if(options.writeBC) 
      {
        ZoneBoVec zoneBoVec;            // from 'MZoneBoundary.h'
        if(mZoneBoundary.exteriorBoundaryVertices
           (options.normalSource, zoneBoVec) == 0) 
        {
          // Sort by zone index and then entity index
          const int numBoVert = zoneBoVec.size();
          if (numBoVert>=1) 
          {
            Msg::Info("writing BoVerts...");

            std::vector<int> iZBV(numBoVert);
            for(int i = 0; i != numBoVert; ++i) iZBV[i] = i;
            std::sort<int*, ZoneBoVecSort>(&iZBV[0], &iZBV[numBoVert-1],
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
                    zoneBoVec[iZBV[iVert]].bcPatchIndex == patchIndex) 
              {
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
              {
                return cgnsErr();
              }

              if(options.normalSource) {
                int normalIndex;
                if(cg_boco_normal_write(cgIndexFile, cgIndexBase,
                                        zoneInfo[zoneIndex].cgIndex, cgIndexBoco,
                                        &normalIndex, 1, RealDouble, &dBuffer[0]))
                {
                  return cgnsErr();
                }
              }
            }
          }
        }
      }

      // NBN: MZoneBoundary defines no destructor, so force 
      // the deallocation of the new pointers with clear()
      mZoneBoundary.clear();
      Msg::Info("Leaving master thread");  // DBG

    }  // End master thread instructions
  }  // End omp parallel section

//--Destroy omp locks

  omp_destroy_lock(&threadWLock);
  omp_destroy_lock(&queueLock);

  return 0;
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
