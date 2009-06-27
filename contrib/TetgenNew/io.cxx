#ifndef tetgenioCXX
#define tetgenioCXX

#include "tetgen.h"

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// initialize()    Initialize all variables of 'tetgenio'.                   //
//                                                                           //
// It is called by the only class constructor 'tetgenio()' implicitly. Thus, //
// all variables are guaranteed to be initialized. Each array is initialized //
// to be a 'NULL' pointer, and its length is equal zero. Some variables have //
// their default value, 'firstnumber' equals zero, 'mesh_dim' equals 3,  and //
// 'numberofcorners' equals 4.  Another possible use of this routine is to   //
// call it before to re-use an object.                                       //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenio::initialize()
{
  firstnumber = 0;              // Default item index is numbered from Zero.
  mesh_dim = 3;                              // Default mesh dimension is 3.
  useindex = true;

  pointlist = (REAL *) NULL;
  pointattributelist = (REAL *) NULL;
  pointmtrlist = (REAL *) NULL;
  pointmarkerlist = (int *) NULL;
  numberofpoints = 0;
  numberofpointattributes = 0;
  numberofpointmtrs = 0;

  tetrahedronlist = (int *) NULL;
  tetrahedronattributelist = (REAL *) NULL;
  tetrahedronvolumelist = (REAL *) NULL;
  neighborlist = (int *) NULL;
  numberoftetrahedra = 0;
  numberofcorners = 4;                   // Default is 4 nodes per element.
  numberoftetrahedronattributes = 0;

  trifacelist = (int *) NULL;
  adjtetlist = (int *) NULL;
  trifacemarkerlist = (int *) NULL;
  numberoftrifaces = 0; 

  facetlist = (facet *) NULL;
  facetmarkerlist = (int *) NULL;
  numberoffacets = 0; 

  edgelist = (int *) NULL;
  edgemarkerlist = (int *) NULL;
  numberofedges = 0;

  holelist = (REAL *) NULL;
  numberofholes = 0;

  regionlist = (REAL *) NULL;
  numberofregions = 0;

  facetconstraintlist = (REAL *) NULL;
  numberoffacetconstraints = 0;
  segmentconstraintlist = (REAL *) NULL;
  numberofsegmentconstraints = 0;

  pbcgrouplist = (pbcgroup *) NULL;
  numberofpbcgroups = 0;

  vpointlist = (REAL *) NULL;
  vedgelist = (voroedge *) NULL;
  vfacetlist = (vorofacet *) NULL; 
  vcelllist = (int **) NULL; 
  numberofvpoints = 0;
  numberofvedges = 0;
  numberofvfacets = 0;
  numberofvcells = 0;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// deinitialize()    Free the memory allocated in 'tetgenio'.                //
//                                                                           //
// It is called by the class destructor '~tetgenio()' implicitly. Hence, the //
// occupied memory by arrays of an object will be automatically released on  //
// the deletion of the object. However, this routine assumes that the memory //
// is allocated by C++ memory allocation operator 'new', thus it is freed by //
// the C++ array deletor 'delete []'. If one uses the C/C++ library function //
// 'malloc()' to allocate memory for arrays, one has to free them with the   //
// 'free()' function, and call routine 'initialize()' once to disable this   //
// routine on deletion of the object.                                        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenio::deinitialize()
{
  facet *f;
  polygon *p;
  pbcgroup *pg;
  int i, j;

  if (pointlist != (REAL *) NULL) {
    delete [] pointlist;
  }
  if (pointattributelist != (REAL *) NULL) {
    delete [] pointattributelist;
  }
  if (pointmtrlist != (REAL *) NULL) {
    delete [] pointmtrlist;
  }
  if (pointmarkerlist != (int *) NULL) {
    delete [] pointmarkerlist;
  }

  if (tetrahedronlist != (int *) NULL) {
    delete [] tetrahedronlist;
  }
  if (tetrahedronattributelist != (REAL *) NULL) {
    delete [] tetrahedronattributelist;
  }
  if (tetrahedronvolumelist != (REAL *) NULL) {
    delete [] tetrahedronvolumelist;
  }
  if (neighborlist != (int *) NULL) {
    delete [] neighborlist;
  }

  if (trifacelist != (int *) NULL) {
    delete [] trifacelist;
  }
  if (adjtetlist != (int *) NULL) {
    delete [] adjtetlist;
  }
  if (trifacemarkerlist != (int *) NULL) {
    delete [] trifacemarkerlist;
  }

  if (edgelist != (int *) NULL) {
    delete [] edgelist;
  }
  if (edgemarkerlist != (int *) NULL) {
    delete [] edgemarkerlist;
  }

  if (facetlist != (facet *) NULL) {
    for (i = 0; i < numberoffacets; i++) {
      f = &facetlist[i];
      for (j = 0; j < f->numberofpolygons; j++) {
        p = &f->polygonlist[j];
        delete [] p->vertexlist;
      }
      delete [] f->polygonlist;
      if (f->holelist != (REAL *) NULL) {
        delete [] f->holelist;
      }
    }
    delete [] facetlist;
  }
  if (facetmarkerlist != (int *) NULL) {
    delete [] facetmarkerlist;
  }

  if (holelist != (REAL *) NULL) {
    delete [] holelist;
  }
  if (regionlist != (REAL *) NULL) {
    delete [] regionlist;
  }
  if (facetconstraintlist != (REAL *) NULL) {
    delete [] facetconstraintlist;
  }
  if (segmentconstraintlist != (REAL *) NULL) {
    delete [] segmentconstraintlist;
  }
  if (pbcgrouplist != (pbcgroup *) NULL) {
    for (i = 0; i < numberofpbcgroups; i++) {
      pg = &(pbcgrouplist[i]);
      if (pg->pointpairlist != (int *) NULL) {
        delete [] pg->pointpairlist;
      }
    }
    delete [] pbcgrouplist;
  }
  if (vpointlist != (REAL *) NULL) {
    delete [] vpointlist;
  }
  if (vedgelist != (voroedge *) NULL) {
    delete [] vedgelist;
  }
  if (vfacetlist != (vorofacet *) NULL) {
    for (i = 0; i < numberofvfacets; i++) {
      delete [] vfacetlist[i].elist;
    }
    delete [] vfacetlist;
  }
  if (vcelllist != (int **) NULL) {
    for (i = 0; i < numberofvcells; i++) {
      delete [] vcelllist[i];
    }
    delete [] vcelllist;
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// load_node_call()    Load a list of nodes.                                 //
//                                                                           //
// It is a support routine for routines: 'load_nodes()', 'load_poly()', and  //
// 'load_tetmesh()'.  'infile' is the file handle contains the node list. It //
// may point to a .node, or .poly or .smesh file.  'markers' indicates each  //
// node contains an additional marker (integer) or not. 'infilename' is the  //
// name of the file being read,  it is only appeared in error message.       //
//                                                                           //
// The 'firstnumber' (0 or 1) is automatically determined by the number of   //
// the first index of the first point.                                       //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenio::load_node_call(FILE* infile,int markers,const char* infilename)
{
  char inputline[INPUTLINESIZE];
  char *stringptr;
  REAL x, y, z, attrib;
  int firstnode, currentmarker;
  int index, attribindex;
  int i, j;

  // Initialize 'pointlist', 'pointattributelist', and 'pointmarkerlist'.
  pointlist = new REAL[numberofpoints * 3];
  if (pointlist == (REAL *) NULL) {
    printf("Error:  Out of memory.\n");
    terminatetetgen(1);
  }
  if (numberofpointattributes > 0) {
    pointattributelist = new REAL[numberofpoints * numberofpointattributes];
    if (pointattributelist == (REAL *) NULL) {
      printf("Error:  Out of memory.\n");
      terminatetetgen(1);
    }
  }
  if (markers) {
    pointmarkerlist = new int[numberofpoints];
    if (pointmarkerlist == (int *) NULL) {
      printf("Error:  Out of memory.\n");
      terminatetetgen(1);
    }
  }

  // Read the point section.
  index = 0;
  attribindex = 0;
  for (i = 0; i < numberofpoints; i++) {
    stringptr = readnumberline(inputline, infile, infilename);
    if (useindex) {
      if (i == 0) {
        firstnode = (int) strtol (stringptr, &stringptr, 0);
        if ((firstnode == 0) || (firstnode == 1)) {
          firstnumber = firstnode;
        }
      }
      stringptr = findnextnumber(stringptr);
    } // if (useindex)
    if (*stringptr == '\0') {
      printf("Error:  Point %d has no x coordinate.\n", firstnumber + i);
      break;
    }
    x = (REAL) strtod(stringptr, &stringptr);
    stringptr = findnextnumber(stringptr);
    if (*stringptr == '\0') {
      printf("Error:  Point %d has no y coordinate.\n", firstnumber + i);
      break;
    }
    y = (REAL) strtod(stringptr, &stringptr);
    if (mesh_dim == 3) {
      stringptr = findnextnumber(stringptr);
      if (*stringptr == '\0') {
        printf("Error:  Point %d has no z coordinate.\n", firstnumber + i);
        break;
      }
      z = (REAL) strtod(stringptr, &stringptr);
    } else {
      z = 0.0; // mesh_dim == 2;
    }
    pointlist[index++] = x;
    pointlist[index++] = y;
    pointlist[index++] = z;
    // Read the point attributes.
    for (j = 0; j < numberofpointattributes; j++) {
      stringptr = findnextnumber(stringptr);
      if (*stringptr == '\0') {
        attrib = 0.0;
      } else {
        attrib = (REAL) strtod(stringptr, &stringptr);
      }
      pointattributelist[attribindex++] = attrib;
    }
    if (markers) {
      // Read a point marker.
      stringptr = findnextnumber(stringptr);
      if (*stringptr == '\0') {
        currentmarker = 0;
      } else {
        currentmarker = (int) strtol (stringptr, &stringptr, 0);
      }
      pointmarkerlist[i] = currentmarker;
    }
  }
  if (i < numberofpoints) {
    // Failed to read points due to some error.
    delete [] pointlist;
    pointlist = (REAL *) NULL;
    if (markers) {
      delete [] pointmarkerlist;
      pointmarkerlist = (int *) NULL;
    }
    if (numberofpointattributes > 0) {
      delete [] pointattributelist;
      pointattributelist = (REAL *) NULL;
    }
    numberofpoints = 0;
    return false;
  }
  return true;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// load_node()    Load a list of nodes from a .node file.                    //
//                                                                           //
// 'filename' is the inputfile without suffix. The node list is in 'filename.//
// node'. On completion, the node list is returned in 'pointlist'.           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenio::load_node(const char* filename)
{
  FILE *infile;
  char innodefilename[FILENAMESIZE];
  char inputline[INPUTLINESIZE];
  char *stringptr;
  int markers;

  // Assembling the actual file names we want to open.
  strcpy(innodefilename, filename);
  strcat(innodefilename, ".node");

  // Try to open a .node file.
  infile = fopen(innodefilename, "r");
  if (infile == (FILE *) NULL) {
    printf("File I/O Error:  Cannot access file %s.\n", innodefilename);
    return false;
  }
  printf("Opening %s.\n", innodefilename);  
  // Read the first line of the file.
  stringptr = readnumberline(inputline, infile, innodefilename);
  // Is this list of points generated from rbox?
  stringptr = strstr(inputline, "rbox");
  if (stringptr == NULL) {
    // Read number of points, number of dimensions, number of point
    //   attributes, and number of boundary markers. 
    stringptr = inputline;
    numberofpoints = (int) strtol (stringptr, &stringptr, 0);
    stringptr = findnextnumber(stringptr);
    if (*stringptr == '\0') {
      mesh_dim = 3;
    } else {
      mesh_dim = (int) strtol (stringptr, &stringptr, 0);
    }
    stringptr = findnextnumber(stringptr);
    if (*stringptr == '\0') {
      numberofpointattributes = 0;
    } else {
      numberofpointattributes = (int) strtol (stringptr, &stringptr, 0);
    }
    stringptr = findnextnumber(stringptr);
    if (*stringptr == '\0') {
      markers = 0;
    } else {
      markers = (int) strtol (stringptr, &stringptr, 0);
    }
  } else {
    // It is a rbox (qhull) input file.
    stringptr = inputline;
    // Get the dimension.
    mesh_dim = (int) strtol (stringptr, &stringptr, 0);
    // Get the number of points.
    stringptr = readnumberline(inputline, infile, innodefilename);
    numberofpoints = (int) strtol (stringptr, &stringptr, 0);
    // There is no index column.
    useindex = 0;
  }

  if (numberofpoints < (mesh_dim + 1)) {
    printf("Input error:  TetGen needs at least %d points.\n", mesh_dim + 1);
    fclose(infile);
    return false;
  }

  // Load the list of nodes.
  if (!load_node_call(infile, markers, innodefilename)) {
    fclose(infile);
    return false;
  }
  fclose(infile);
  return true;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// load_pbc()    Load a list of pbc groups into 'pbcgrouplist'.              //
//                                                                           //
// 'filename' is the filename of the original inputfile without suffix. The  //
// pbc groups are found in file 'filename.pbc'.                              //
//                                                                           //
// This routine will be called both in load_poly() and load_tetmesh().       //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenio::load_pbc(const char* filename)
{
  FILE *infile;
  char pbcfilename[FILENAMESIZE];
  char inputline[INPUTLINESIZE];
  char *stringptr;
  pbcgroup *pg;
  int index, p1, p2;
  int i, j, k;

  // Pbc groups are saved in file "filename.pbc".
  strcpy(pbcfilename, filename);
  strcat(pbcfilename, ".pbc");
  infile = fopen(pbcfilename, "r");
  if (infile != (FILE *) NULL) {
    printf("Opening %s.\n", pbcfilename);
  } else {
    // No such file. Return.
    return false;
  }

  // Read the number of pbc groups.
  stringptr = readnumberline(inputline, infile, pbcfilename);
  numberofpbcgroups = (int) strtol (stringptr, &stringptr, 0);
  if (numberofpbcgroups == 0) {
    // It looks this file contains no point.
    fclose(infile);
    return false; 
  }
  // Initialize 'pbcgrouplist';
  pbcgrouplist = new pbcgroup[numberofpbcgroups];

  // Read the list of pbc groups.
  for (i = 0; i < numberofpbcgroups; i++) {
    pg = &(pbcgrouplist[i]);
    // Initialize pbcgroup i;
    pg->numberofpointpairs = 0;
    pg->pointpairlist = (int *) NULL;
    // Read 'fmark1', 'fmark2'.
    stringptr = readnumberline(inputline, infile, pbcfilename);
    if (*stringptr == '\0') break;
    pg->fmark1 = (int) strtol(stringptr, &stringptr, 0);
    stringptr = findnextnumber(stringptr);
    if (*stringptr == '\0') break;
    pg->fmark2 = (int) strtol(stringptr, &stringptr, 0);
    // Read 'transmat'.
    do {
      stringptr = readline(inputline, infile, NULL);
    } while ((*stringptr != '[') && (*stringptr != '\0'));
    if (*stringptr == '\0') break;
    for (j = 0; j < 4; j++) {
      for (k = 0; k < 4; k++) {
        // Read the entry of [j, k].
        stringptr = findnextnumber(stringptr);
        if (*stringptr == '\0') {
          // Try to read another line.
          stringptr = readnumberline(inputline, infile, pbcfilename);
          if (*stringptr == '\0') break;
        }
        pg->transmat[j][k] = (REAL) strtod(stringptr, &stringptr);
      }
      if (k < 4) break; // Not complete!
    }
    if (j < 4) break; // Not complete!
    // Read 'numberofpointpairs'.
    stringptr = readnumberline(inputline, infile, pbcfilename);
    if (*stringptr == '\0') break;
    pg->numberofpointpairs = (int) strtol(stringptr, &stringptr, 0);
    if (pg->numberofpointpairs > 0) {
      pg->pointpairlist = new int[pg->numberofpointpairs * 2];
      // Read the point pairs.
      index = 0;
      for (j = 0; j < pg->numberofpointpairs; j++) {
        stringptr = readnumberline(inputline, infile, pbcfilename);
        p1 = (int) strtol(stringptr, &stringptr, 0);
        stringptr = findnextnumber(stringptr);
        p2 = (int) strtol(stringptr, &stringptr, 0);
        pg->pointpairlist[index++] = p1;
        pg->pointpairlist[index++] = p2;
      }
    }
  }
  fclose(infile);

  if (i < numberofpbcgroups) {
    // Failed to read to additional points due to some error.
    delete [] pbcgrouplist;
    pbcgrouplist = (pbcgroup *) NULL;
    numberofpbcgroups = 0;
    return false;
  }
  return true;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// load_var()    Load variant constraints applied on facets, segments, nodes.//
//                                                                           //
// 'filename' is the filename of the original inputfile without suffix. The  //
// constraints are found in file 'filename.var'.                             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenio::load_var(const char* filename)
{
  FILE *infile;
  char varfilename[FILENAMESIZE];
  char inputline[INPUTLINESIZE];
  char *stringptr;
  int index;
  int i;

  // Variant constraints are saved in file "filename.var".
  strcpy(varfilename, filename);
  strcat(varfilename, ".var");
  infile = fopen(varfilename, "r");
  if (infile != (FILE *) NULL) {
    printf("Opening %s.\n", varfilename);
  } else {
    // No such file. Return.
    return false;
  }

  // Read the facet constraint section.
  stringptr = readnumberline(inputline, infile, varfilename);
  if (*stringptr != '\0') {
    numberoffacetconstraints = (int) strtol (stringptr, &stringptr, 0);
  } else {
    numberoffacetconstraints = 0;
  }
  if (numberoffacetconstraints > 0) {
    // Initialize 'facetconstraintlist'.
    facetconstraintlist = new REAL[numberoffacetconstraints * 2];
    index = 0;
    for (i = 0; i < numberoffacetconstraints; i++) {
      stringptr = readnumberline(inputline, infile, varfilename);
      stringptr = findnextnumber(stringptr);
      if (*stringptr == '\0') {
        printf("Error:  facet constraint %d has no facet marker.\n",
               firstnumber + i);
        break;
      } else {
        facetconstraintlist[index++] = (REAL) strtod(stringptr, &stringptr);
      }
      stringptr = findnextnumber(stringptr);
      if (*stringptr == '\0') {
        printf("Error:  facet constraint %d has no maximum area bound.\n",
               firstnumber + i);
        break;
      } else {
        facetconstraintlist[index++] = (REAL) strtod(stringptr, &stringptr);
      }
    }
    if (i < numberoffacetconstraints) {
      // This must be caused by an error.
      fclose(infile);
      return false;
    }
  }

  // Read the segment constraint section.
  stringptr = readnumberline(inputline, infile, varfilename);
  if (*stringptr != '\0') {
    numberofsegmentconstraints = (int) strtol (stringptr, &stringptr, 0);
  } else {
    numberofsegmentconstraints = 0;
  }
  if (numberofsegmentconstraints > 0) {
    // Initialize 'segmentconstraintlist'.
    segmentconstraintlist = new REAL[numberofsegmentconstraints * 3];
    index = 0;
    for (i = 0; i < numberofsegmentconstraints; i++) {
      stringptr = readnumberline(inputline, infile, varfilename);
      stringptr = findnextnumber(stringptr);
      if (*stringptr == '\0') {
        printf("Error:  segment constraint %d has no frist endpoint.\n",
               firstnumber + i);
        break;
      } else {
        segmentconstraintlist[index++] = (REAL) strtod(stringptr, &stringptr);
      }
      stringptr = findnextnumber(stringptr);
      if (*stringptr == '\0') {
        printf("Error:  segment constraint %d has no second endpoint.\n",
               firstnumber + i);
        break;
      } else {
        segmentconstraintlist[index++] = (REAL) strtod(stringptr, &stringptr);
      }
      stringptr = findnextnumber(stringptr);
      if (*stringptr == '\0') {
        printf("Error:  segment constraint %d has no maximum length bound.\n",
               firstnumber + i);
        break;
      } else {
        segmentconstraintlist[index++] = (REAL) strtod(stringptr, &stringptr);
      }
    }
    if (i < numberofsegmentconstraints) {
      // This must be caused by an error.
      fclose(infile);
      return false;
    }
  }

  fclose(infile);
  return true;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// load_mtr()    Load a size specification map from file.                    //
//                                                                           //
// 'filename' is the filename of the original inputfile without suffix. The  //
// size map is found in file 'filename.mtr'.                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenio::load_mtr(const char* filename)
{
  FILE *infile;
  char mtrfilename[FILENAMESIZE];
  char inputline[INPUTLINESIZE];
  char *stringptr;
  REAL mtr;
  int mtrindex;
  int i, j;

  strcpy(mtrfilename, filename);
  strcat(mtrfilename, ".mtr");
  infile = fopen(mtrfilename, "r");
  if (infile != (FILE *) NULL) {
    printf("Opening %s.\n", mtrfilename);
  } else {
    // No such file. Return.
    return false;
  }

  // Read number of points, number of columns (1, 3, or 6).
  stringptr = readnumberline(inputline, infile, mtrfilename);
  stringptr = findnextnumber(stringptr); // Skip number of points.
  if (*stringptr != '\0') {
    numberofpointmtrs = (int) strtol (stringptr, &stringptr, 0);
  }
  if (numberofpointmtrs == 0) {
    // Column number doesn't match. Set a default number (1).
    numberofpointmtrs = 1;
  }

  // Allocate space for pointmtrlist.
  pointmtrlist = new REAL[numberofpoints * numberofpointmtrs];
  if (pointmtrlist == (REAL *) NULL) {
    printf("Error:  Out of memory.\n");
    terminatetetgen(1);
  }
  mtrindex = 0;
  for (i = 0; i < numberofpoints; i++) {
    // Read metrics.
    stringptr = readnumberline(inputline, infile, mtrfilename);
    for (j = 0; j < numberofpointmtrs; j++) {
      if (*stringptr == '\0') {
        printf("Error:  Metric %d is missing value #%d in %s.\n",
               i + firstnumber, j + 1, mtrfilename);
        terminatetetgen(1);
      }
      mtr = (REAL) strtod(stringptr, &stringptr);
      pointmtrlist[mtrindex++] = mtr;
      stringptr = findnextnumber(stringptr);
    }
  }

  fclose(infile);
  return true;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// load_poly()    Load a piecewise linear complex from a .poly or .smesh.    //
//                                                                           //
// 'filename' is the inputfile without suffix. The PLC is in 'filename.poly' //
// or 'filename.smesh', and possibly plus 'filename.node' (when the first    //
// line of the file starts with a zero).                                     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenio::load_poly(const char* filename)
{
  FILE *infile, *polyfile;
  char innodefilename[FILENAMESIZE];
  char inpolyfilename[FILENAMESIZE];
  char insmeshfilename[FILENAMESIZE];
  char inputline[INPUTLINESIZE];
  char *stringptr, *infilename;
  int smesh, markers, currentmarker;
  int readnodefile, index;
  int i, j, k;

  // Assembling the actual file names we want to open.
  strcpy(innodefilename, filename);
  strcpy(inpolyfilename, filename);
  strcpy(insmeshfilename, filename);
  strcat(innodefilename, ".node");
  strcat(inpolyfilename, ".poly");
  strcat(insmeshfilename, ".smesh");

  // First assume it is a .poly file.
  smesh = 0;
  // Try to open a .poly file.
  polyfile = fopen(inpolyfilename, "r");
  if (polyfile == (FILE *) NULL) {
    // .poly doesn't exist! Try to open a .smesh file.
    polyfile = fopen(insmeshfilename, "r");
    if (polyfile == (FILE *) NULL) {
      printf("File I/O Error:  Cannot access file %s and %s.\n",
             inpolyfilename, insmeshfilename);
      return false;
    } else {
      printf("Opening %s.\n", insmeshfilename);
    }
    smesh = 1;
  } else {
    printf("Opening %s.\n", inpolyfilename);
  }
  // Initialize the default values.
  mesh_dim = 3;  // Three-dimemsional accoordinates.
  numberofpointattributes = 0;  // no point attribute.
  markers = 0;  // no boundary marker.
  // Read number of points, number of dimensions, number of point
  //   attributes, and number of boundary markers.
  stringptr = readnumberline(inputline, polyfile, inpolyfilename);
  numberofpoints = (int) strtol (stringptr, &stringptr, 0);
  stringptr = findnextnumber(stringptr);
  if (*stringptr != '\0') {
    mesh_dim = (int) strtol (stringptr, &stringptr, 0);      
  }
  stringptr = findnextnumber(stringptr);
  if (*stringptr != '\0') {
    numberofpointattributes = (int) strtol (stringptr, &stringptr, 0);
  }
  stringptr = findnextnumber(stringptr);
  if (*stringptr != '\0') {
    markers = (int) strtol (stringptr, &stringptr, 0);
  }
  if (numberofpoints > 0) {
    readnodefile = 0;
    if (smesh) {
      infilename = insmeshfilename;
    } else {
      infilename = inpolyfilename;
    } 
    infile = polyfile;
  } else {
    // If the .poly or .smesh file claims there are zero points, that
    //   means the points should be read from a separate .node file.
    readnodefile = 1;
    infilename = innodefilename;
  }

  if (readnodefile) {
    // Read the points from the .node file.
    printf("Opening %s.\n", innodefilename);
    infile = fopen(innodefilename, "r");
    if (infile == (FILE *) NULL) {
      printf("File I/O Error:  Cannot access file %s.\n", innodefilename);
      return false;
    }
    // Initialize the default values.
    mesh_dim = 3;  // Three-dimemsional accoordinates.
    numberofpointattributes = 0;  // no point attribute.
    markers = 0;  // no boundary marker.
    // Read number of points, number of dimensions, number of point
    //   attributes, and number of boundary markers.
    stringptr = readnumberline(inputline, infile, innodefilename);
    numberofpoints = (int) strtol (stringptr, &stringptr, 0);
    stringptr = findnextnumber(stringptr);
    if (*stringptr != '\0') {
      mesh_dim = (int) strtol (stringptr, &stringptr, 0);
    }
    stringptr = findnextnumber(stringptr);
    if (*stringptr != '\0') {
      numberofpointattributes = (int) strtol (stringptr, &stringptr, 0);
    }
    stringptr = findnextnumber(stringptr);
    if (*stringptr != '\0') {
      markers = (int) strtol (stringptr, &stringptr, 0);
    }
  }

  if ((mesh_dim != 3) && (mesh_dim != 2)) {
    printf("Input error:  TetGen only works for 2D & 3D point sets.\n");
    fclose(infile);
    return false;
  }
  if (numberofpoints < (mesh_dim + 1)) {
    printf("Input error:  TetGen needs at least %d points.\n", mesh_dim + 1);
    fclose(infile);
    return false;
  }

  // Load the list of nodes.
  if (!load_node_call(infile, markers, infilename)) {
    fclose(infile);
    return false;
  }

  if (readnodefile) {
    fclose(infile);
  }

  facet *f;
  polygon *p;

  if (mesh_dim == 3) {

    // Read number of facets and number of boundary markers.
    stringptr = readnumberline(inputline, polyfile, inpolyfilename);
    numberoffacets = (int) strtol (stringptr, &stringptr, 0);
    if (numberoffacets <= 0) {
      // No facet list, return.
      fclose(polyfile);
      return true;
    }
    stringptr = findnextnumber(stringptr);
    if (*stringptr == '\0') {
      markers = 0;  // no boundary marker.
    } else {
      markers = (int) strtol (stringptr, &stringptr, 0);
    }

    // Initialize the 'facetlist', 'facetmarkerlist'.
    facetlist = new facet[numberoffacets];
    if (markers == 1) {
      facetmarkerlist = new int[numberoffacets];
    }

    // Read data into 'facetlist', 'facetmarkerlist'.
    if (smesh == 0) {
      // Facets are in .poly file format.
      for (i = 1; i <= numberoffacets; i++) {
        f = &(facetlist[i - 1]);
        init(f);
        f->numberofholes = 0;
        currentmarker = 0;
        // Read number of polygons, number of holes, and a boundary marker.
        stringptr = readnumberline(inputline, polyfile, inpolyfilename);
        f->numberofpolygons = (int) strtol (stringptr, &stringptr, 0);
        stringptr = findnextnumber(stringptr);
        if (*stringptr != '\0') {
          f->numberofholes = (int) strtol (stringptr, &stringptr, 0);
          if (markers == 1) {
            stringptr = findnextnumber(stringptr);
            if (*stringptr != '\0') {
              currentmarker = (int) strtol(stringptr, &stringptr, 0);
            }
          }
        }
        // Initialize facetmarker if it needs.
        if (markers == 1) {
          facetmarkerlist[i - 1] = currentmarker; 
        }
        // Each facet should has at least one polygon.
        if (f->numberofpolygons <= 0) {
          printf("Error:  Wrong number of polygon in %d facet.\n", i);
          break; 
        }
        // Initialize the 'f->polygonlist'.
        f->polygonlist = new polygon[f->numberofpolygons];
        // Go through all polygons, read in their vertices.
        for (j = 1; j <= f->numberofpolygons; j++) {
          p = &(f->polygonlist[j - 1]);
          init(p);
          // Read number of vertices of this polygon.
          stringptr = readnumberline(inputline, polyfile, inpolyfilename);
          p->numberofvertices = (int) strtol(stringptr, &stringptr, 0);
          if (p->numberofvertices < 1) {
            printf("Error:  Wrong polygon %d in facet %d\n", j, i);
            break;
          }
          // Initialize 'p->vertexlist'.
          p->vertexlist = new int[p->numberofvertices];
          // Read all vertices of this polygon.
          for (k = 1; k <= p->numberofvertices; k++) {
            stringptr = findnextnumber(stringptr);
            if (*stringptr == '\0') {
              // Try to load another non-empty line and continue to read the
              //   rest of vertices.
              stringptr = readnumberline(inputline, polyfile, inpolyfilename);
              if (*stringptr == '\0') {
                printf("Error: Missing %d endpoints of polygon %d in facet %d",
                       p->numberofvertices - k, j, i);
                break;
              }
            }
            p->vertexlist[k - 1] = (int) strtol (stringptr, &stringptr, 0);
          }
        } 
        if (j <= f->numberofpolygons) {
          // This must be caused by an error. However, there're j - 1
          //   polygons have been read. Reset the 'f->numberofpolygon'.
          if (j == 1) {
            // This is the first polygon.
            delete [] f->polygonlist;
          }
          f->numberofpolygons = j - 1;
          // No hole will be read even it exists.
          f->numberofholes = 0;
          break;
        }
        // If this facet has hole pints defined, read them.
        if (f->numberofholes > 0) {
          // Initialize 'f->holelist'.
          f->holelist = new REAL[f->numberofholes * 3];
          // Read the holes' coordinates.
          index = 0;
          for (j = 1; j <= f->numberofholes; j++) {
            stringptr = readnumberline(inputline, polyfile, inpolyfilename);
            for (k = 1; k <= 3; k++) {
              stringptr = findnextnumber(stringptr);
              if (*stringptr == '\0') {
                printf("Error:  Hole %d in facet %d has no coordinates", j, i);
                break;
              }
              f->holelist[index++] = (REAL) strtod (stringptr, &stringptr);
            }
            if (k <= 3) {
              // This must be caused by an error.
              break;
            }
          }
          if (j <= f->numberofholes) {
            // This must be caused by an error.
            break;
          }
        }
      }
      if (i <= numberoffacets) {
        // This must be caused by an error.
        numberoffacets = i - 1;
        fclose(polyfile);
        return false;
      }
    } else { // poly == 0
      // Read the facets from a .smesh file.
      for (i = 1; i <= numberoffacets; i++) {
        f = &(facetlist[i - 1]);
        init(f);
        // Initialize 'f->facetlist'. In a .smesh file, each facetlist only
        //   contains exactly one polygon, no hole.
        f->numberofpolygons = 1;
        f->polygonlist = new polygon[f->numberofpolygons];
        p = &(f->polygonlist[0]);
        init(p);
        // Read number of vertices of this polygon.
        stringptr = readnumberline(inputline, polyfile, insmeshfilename);
        p->numberofvertices = (int) strtol (stringptr, &stringptr, 0);
        if (p->numberofvertices < 1) {
          printf("Error:  Wrong number of vertex in facet %d\n", i);
          break;
        }
        // Initialize 'p->vertexlist'.
        p->vertexlist = new int[p->numberofvertices];
        for (k = 1; k <= p->numberofvertices; k++) {
          stringptr = findnextnumber(stringptr);
          if (*stringptr == '\0') {
            // Try to load another non-empty line and continue to read the
            //   rest of vertices.
            stringptr = readnumberline(inputline, polyfile, inpolyfilename);
            if (*stringptr == '\0') {
              printf("Error:  Missing %d endpoints in facet %d",
                     p->numberofvertices - k, i);
              break;
            }
          }
          p->vertexlist[k - 1] = (int) strtol (stringptr, &stringptr, 0);
        }
        if (k <= p->numberofvertices) {
          // This must be caused by an error.
          break;
        }
        // Read facet's boundary marker at last.
        if (markers == 1) {
          stringptr = findnextnumber(stringptr);
          if (*stringptr == '\0') {
            currentmarker = 0;
          } else {
            currentmarker = (int) strtol(stringptr, &stringptr, 0);
          }
          facetmarkerlist[i - 1] = currentmarker;
        }
      }
      if (i <= numberoffacets) {
        // This must be caused by an error.
        numberoffacets = i - 1;
        fclose(polyfile);
        return false;
      }
    }

    // Read the hole section.
    stringptr = readnumberline(inputline, polyfile, inpolyfilename);
    if (*stringptr != '\0') {
      numberofholes = (int) strtol (stringptr, &stringptr, 0);
    } else {
      numberofholes = 0;
    }
    if (numberofholes > 0) {
      // Initialize 'holelist'.
      holelist = new REAL[numberofholes * 3];
      for (i = 0; i < 3 * numberofholes; i += 3) {
        stringptr = readnumberline(inputline, polyfile, inpolyfilename);
        stringptr = findnextnumber(stringptr);
        if (*stringptr == '\0') {
          printf("Error:  Hole %d has no x coord.\n", firstnumber + (i / 3));
          break;
        } else {
          holelist[i] = (REAL) strtod(stringptr, &stringptr);
        }
        stringptr = findnextnumber(stringptr);
        if (*stringptr == '\0') {
          printf("Error:  Hole %d has no y coord.\n", firstnumber + (i / 3));
          break;
        } else {
          holelist[i + 1] = (REAL) strtod(stringptr, &stringptr);
        }
        stringptr = findnextnumber(stringptr);
        if (*stringptr == '\0') {
          printf("Error:  Hole %d has no z coord.\n", firstnumber + (i / 3));
          break;
        } else {
          holelist[i + 2] = (REAL) strtod(stringptr, &stringptr);
        }
      }
      if (i < 3 * numberofholes) {
        // This must be caused by an error.
        fclose(polyfile);
        return false;
      }
    }

    // Read the region section.  The 'region' section is optional, if we
    //   don't reach the end-of-file, try read it in.
    stringptr = readnumberline(inputline, polyfile, NULL);
    if (stringptr != (char *) NULL && *stringptr != '\0') {
      numberofregions = (int) strtol (stringptr, &stringptr, 0);
    } else {
      numberofregions = 0;
    }
    if (numberofregions > 0) {
      // Initialize 'regionlist'.
      regionlist = new REAL[numberofregions * 5];
      index = 0;
      for (i = 0; i < numberofregions; i++) {
        stringptr = readnumberline(inputline, polyfile, inpolyfilename);
        stringptr = findnextnumber(stringptr);
        if (*stringptr == '\0') {
          printf("Error:  Region %d has no x coordinate.\n", firstnumber + i);
          break;
        } else {
          regionlist[index++] = (REAL) strtod(stringptr, &stringptr);
        }
        stringptr = findnextnumber(stringptr);
        if (*stringptr == '\0') {
          printf("Error:  Region %d has no y coordinate.\n", firstnumber + i);
          break;
        } else {
          regionlist[index++] = (REAL) strtod(stringptr, &stringptr);
        }
        stringptr = findnextnumber(stringptr);
        if (*stringptr == '\0') {
          printf("Error:  Region %d has no z coordinate.\n", firstnumber + i);
          break;
        } else {
          regionlist[index++] = (REAL) strtod(stringptr, &stringptr);
        }
        stringptr = findnextnumber(stringptr);
        if (*stringptr == '\0') {
          printf("Error:  Region %d has no region attrib.\n", firstnumber + i);
          break;
        } else {
          regionlist[index++] = (REAL) strtod(stringptr, &stringptr);
        }
        stringptr = findnextnumber(stringptr);
        if (*stringptr == '\0') {
          regionlist[index] = regionlist[index - 1];
        } else {
          regionlist[index] = (REAL) strtod(stringptr, &stringptr);
        }
        index++;
      }
      if (i < numberofregions) {
        // This must be caused by an error.
        fclose(polyfile);
        return false;
      }
    }

    /*// Read the edge (segment) section.  This section is optional, if we
    //   don't reach the end-of-file, try read it in.
    stringptr = readnumberline(inputline, polyfile, NULL);
    if (stringptr != (char *) NULL && *stringptr != '\0') {
      numberofedges = (int) strtol (stringptr, &stringptr, 0);
    } else {
      numberofedges = 0;
    }
    if (numberofedges > 0) {
      // Initialize 'edgelist'.
      edgelist = new int[numberofedges * 2];
      edgemarkerlist = new int[numberofedges];
      index = 0;
      for (i = 0; i < numberofedges; i++) {
        stringptr = readnumberline(inputline, polyfile, inpolyfilename);
        for (j = 0; j < 2; j++) {
          stringptr = findnextnumber(stringptr);
          if (*stringptr == '\0') {
            printf("Error:  Segment %d has no endpoint.\n", firstnumber + i);
            break;
          } else {
            edgelist[index++] = (int) strtol(stringptr, &stringptr, 0);
          }
        }
        if (j < 2) break;
        stringptr = findnextnumber(stringptr);
        if (*stringptr == '\0') {
          edgemarkerlist[i] = 0;  // Set a default segment marker.
        } else {
          edgemarkerlist[i] = (int) strtol(stringptr, &stringptr, 0);
        }
      }
      if (i < numberofedges) {
        // This must be caused by an error.
        fclose(polyfile);
        return false;
      }
    }
    */

  } else {

    // Read a PSLG from Triangle's poly file.
    assert(mesh_dim == 2);
    // A PSLG is a facet of a PLC.
    numberoffacets = 1;
    // Initialize the 'facetlist'.
    facetlist = new facet[numberoffacets];
    facetmarkerlist = (int *) NULL; // No facet markers.
    f = &(facetlist[0]);
    init(f);
    // Read number of segments.
    stringptr = readnumberline(inputline, polyfile, inpolyfilename);
    // Segments are degenerate polygons.
    f->numberofpolygons = (int) strtol (stringptr, &stringptr, 0);
    if (f->numberofpolygons > 0) {
      f->polygonlist = new polygon[f->numberofpolygons];
    }
    // Go through all segments, read in their vertices.
    for (j = 0; j < f->numberofpolygons; j++) {
      p = &(f->polygonlist[j]);
      init(p);
      // Read in a segment.
      stringptr = readnumberline(inputline, polyfile, inpolyfilename);
      stringptr = findnextnumber(stringptr); // Skip its index.
      p->numberofvertices = 2; // A segment always has two vertices.
      p->vertexlist = new int[p->numberofvertices];
      p->vertexlist[0] = (int) strtol (stringptr, &stringptr, 0);
      stringptr = findnextnumber(stringptr);
      p->vertexlist[1] = (int) strtol (stringptr, &stringptr, 0);
    }
    // Read number of holes.
    stringptr = readnumberline(inputline, polyfile, inpolyfilename);
    f->numberofholes = (int) strtol (stringptr, &stringptr, 0);
    if (f->numberofholes > 0) {
      // Initialize 'f->holelist'.
      f->holelist = new REAL[f->numberofholes * 3];
      // Read the holes' coordinates.
      for (j = 0; j < f->numberofholes; j++) {
        // Read a 2D hole point.
        stringptr = readnumberline(inputline, polyfile, inpolyfilename);
        stringptr = findnextnumber(stringptr); // Skip its index.
        f->holelist[j * 3] = (REAL) strtod (stringptr, &stringptr);
        stringptr = findnextnumber(stringptr);
        f->holelist[j * 3 + 1] = (REAL) strtod (stringptr, &stringptr);
        f->holelist[j * 3 + 2] = 0.0; // The z-coord.
      }
    }
    // The regions are skipped.

  }

  // End of reading poly/smesh file.
  fclose(polyfile);

  // Try to load a .var file if it exists.
  load_var(filename);
  // Try to load a .mtr file if it exists.
  load_mtr(filename);
  // Try to read a .pbc file if it exists.
  load_pbc(filename);

  return true;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// load_off()    Load a polyhedron described in a .off file.                 //
//                                                                           //
// The .off format is one of file formats of the Geomview, an interactive    //
// program for viewing and manipulating geometric objects.  More information //
// is available form: http://www.geomview.org.                               //
//                                                                           //
// 'filename' is a input filename with extension .off or without extension ( //
// the .off will be added in this case). On completion, the polyhedron is    //
// returned in 'pointlist' and 'facetlist'.                                  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenio::load_off(const char* filename)
{
  FILE *fp;
  tetgenio::facet *f;
  tetgenio::polygon *p;
  char infilename[FILENAMESIZE];
  char buffer[INPUTLINESIZE];
  char *bufferp;
  double *coord;
  int nverts = 0, iverts = 0;
  int nfaces = 0, ifaces = 0;
  int nedges = 0;
  int line_count = 0, i;

  strncpy(infilename, filename, 1024 - 1);
  infilename[FILENAMESIZE - 1] = '\0';
  if (infilename[0] == '\0') {
    printf("Error:  No filename.\n");
    return false;
  }
  if (strcmp(&infilename[strlen(infilename) - 4], ".off") != 0) {
    strcat(infilename, ".off");
  }

  if (!(fp = fopen(infilename, "r"))) {
    printf("File I/O Error:  Unable to open file %s\n", infilename);
    return false;
  }
  printf("Opening %s.\n", infilename);

  // OFF requires the index starts from '0'.
  firstnumber = 0;

  while ((bufferp = readline(buffer, fp, &line_count)) != NULL) {
    // Check section
    if (nverts == 0) {
      // Read header 
      bufferp = strstr(bufferp, "OFF");
      if (bufferp != NULL) {
        // Read mesh counts
        bufferp = findnextnumber(bufferp); // Skip field "OFF".
        if (*bufferp == '\0') {
          // Read a non-empty line.
          bufferp = readline(buffer, fp, &line_count);
        }
        if ((sscanf(bufferp, "%d%d%d", &nverts, &nfaces, &nedges) != 3) 
            || (nverts == 0)) {
          printf("Syntax error reading header on line %d in file %s\n",
                 line_count, infilename);
          fclose(fp);
          return false;
        }
        // Allocate memory for 'tetgenio'
        if (nverts > 0) {
          numberofpoints = nverts;
          pointlist = new REAL[nverts * 3];
        }
        if (nfaces > 0) {        
          numberoffacets = nfaces;
          facetlist = new tetgenio::facet[nfaces];
        }
      }
    } else if (iverts < nverts) {
      // Read vertex coordinates
      coord = &pointlist[iverts * 3];
      for (i = 0; i < 3; i++) {
        if (*bufferp == '\0') {
          printf("Syntax error reading vertex coords on line %d in file %s\n",
                 line_count, infilename);
          fclose(fp);
          return false;
        }
        coord[i] = (REAL) strtod(bufferp, &bufferp);
        bufferp = findnextnumber(bufferp);
      }
      iverts++;
    } else if (ifaces < nfaces) {
      // Get next face
      f = &facetlist[ifaces];
      init(f);      
      // In .off format, each facet has one polygon, no hole.
      f->numberofpolygons = 1;
      f->polygonlist = new tetgenio::polygon[1];
      p = &f->polygonlist[0];
      init(p);
      // Read the number of vertices, it should be greater than 0.
      p->numberofvertices = (int) strtol(bufferp, &bufferp, 0);
      if (p->numberofvertices == 0) {
        printf("Syntax error reading polygon on line %d in file %s\n",
               line_count, infilename);
        fclose(fp);
        return false;
      }
      // Allocate memory for face vertices
      p->vertexlist = new int[p->numberofvertices];
      for (i = 0; i < p->numberofvertices; i++) {
        bufferp = findnextnumber(bufferp);
        if (*bufferp == '\0') {
          printf("Syntax error reading polygon on line %d in file %s\n",
                 line_count, infilename);
          fclose(fp);
          return false;
        }
        p->vertexlist[i] = (int) strtol(bufferp, &bufferp, 0);
      }
      ifaces++;
    } else {
      // Should never get here
      printf("Found extra text starting at line %d in file %s\n", line_count,
             infilename);
      break;
    }
  }

  // Close file
  fclose(fp);

  // Check whether read all points
  if (iverts != nverts) {
    printf("Expected %d vertices, but read only %d vertices in file %s\n",
           nverts, iverts, infilename);
    return false;
  }

  // Check whether read all faces
  if (ifaces != nfaces) {
    printf("Expected %d faces, but read only %d faces in file %s\n",
           nfaces, ifaces, infilename);
    return false;
  }

  return true;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// load_ply()    Load a polyhedron described in a .ply file.                 //
//                                                                           //
// 'filename' is the file name with extension .ply or without extension (the //
// .ply will be added in this case).                                         //
//                                                                           //
// This is a simplified version of reading .ply files, which only reads the  //
// set of vertices and the set of faces. Other informations (such as color,  //
// material, texture, etc) in .ply file are ignored. Complete routines for   //
// reading and writing ,ply files are available from:                        //
//       http://www.cc.gatech.edu/projects/large_models/ply.html             //
// Except the header section,ply file format has exactly the same format for //
// listing vertices and polygons as off file format.                         //
//                                                                           //
// On completion, 'pointlist' and 'facetlist' together return the polyhedron.//
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenio::load_ply(const char* filename)
{
  FILE *fp;
  tetgenio::facet *f;
  tetgenio::polygon *p;
  char infilename[FILENAMESIZE];
  char buffer[INPUTLINESIZE];
  char *bufferp, *str;
  double *coord;
  int endheader = 0, format = 0;
  int nverts = 0, iverts = 0;
  int nfaces = 0, ifaces = 0;
  int line_count = 0, i;

  strncpy(infilename, filename, FILENAMESIZE - 1);
  infilename[FILENAMESIZE - 1] = '\0';
  if (infilename[0] == '\0') {
    printf("Error:  No filename.\n");
    return false;
  }
  if (strcmp(&infilename[strlen(infilename) - 4], ".ply") != 0) {
    strcat(infilename, ".ply");
  }

  if (!(fp = fopen(infilename, "r"))) {
    printf("Error:  Unable to open file %s\n", infilename);
    return false;
  }
  printf("Opening %s.\n", infilename);

  // PLY requires the index starts from '0'.
  firstnumber = 0;

  while ((bufferp = readline(buffer, fp, &line_count)) != NULL) {
    if (!endheader) {
      // Find if it is the keyword "end_header".
      str = strstr(bufferp, "end_header");
      // strstr() is case sensitive.
      if (!str) str = strstr(bufferp, "End_header");
      if (!str) str = strstr(bufferp, "End_Header");
      if (str) {
        // This is the end of the header section.
        endheader = 1; 
        continue;
      }
      // Parse the number of vertices and the number of faces.
      if (nverts == 0 || nfaces == 0) {
        // Find if it si the keyword "element".
        str = strstr(bufferp, "element");
        if (!str) str = strstr(bufferp, "Element");
        if (str) {
          bufferp = findnextfield(str);
          if (*bufferp == '\0') {
            printf("Syntax error reading element type on line%d in file %s\n",
                   line_count, infilename);
            fclose(fp);
            return false;
          }
          if (nverts == 0) {
            // Find if it is the keyword "vertex".
            str = strstr(bufferp, "vertex");
            if (!str) str = strstr(bufferp, "Vertex");
            if (str) {
              bufferp = findnextnumber(str);
              if (*bufferp == '\0') {
                printf("Syntax error reading vertex number on line");
                printf(" %d in file %s\n", line_count, infilename);
                fclose(fp);
                return false;
              }
              nverts = (int) strtol(bufferp, &bufferp, 0);
              // Allocate memory for 'tetgenio'
              if (nverts > 0) {
                numberofpoints = nverts;
                pointlist = new REAL[nverts * 3];
              }
            }
          }
          if (nfaces == 0) {
            // Find if it is the keyword "face".
            str = strstr(bufferp, "face");
            if (!str) str = strstr(bufferp, "Face");
            if (str) {
              bufferp = findnextnumber(str);
              if (*bufferp == '\0') {
                printf("Syntax error reading face number on line");
                printf(" %d in file %s\n", line_count, infilename);
                fclose(fp);
                return false;
              }
              nfaces = (int) strtol(bufferp, &bufferp, 0);
              // Allocate memory for 'tetgenio'
              if (nfaces > 0) {        
                numberoffacets = nfaces;
                facetlist = new tetgenio::facet[nfaces];
              }
            }
          }
        } // It is not the string "element". 
      }
      if (format == 0) {
        // Find the keyword "format".
        str = strstr(bufferp, "format");
        if (!str) str = strstr(bufferp, "Format");
        if (str) {
          format = 1;
          bufferp = findnextfield(str);
          // Find if it is the string "ascii".
          str = strstr(bufferp, "ascii");
          if (!str) str = strstr(bufferp, "ASCII");
          if (!str) {
            printf("This routine only reads ascii format of ply files.\n");
            printf("Hint: You can convert the binary to ascii format by\n");
            printf("  using the provided ply tools:\n");
            printf("  ply2ascii < %s > ascii_%s\n", infilename, infilename);
            fclose(fp);
            return false;
          }
        }
      }
    } else if (iverts < nverts) {
      // Read vertex coordinates
      coord = &pointlist[iverts * 3];
      for (i = 0; i < 3; i++) {
        if (*bufferp == '\0') {
          printf("Syntax error reading vertex coords on line %d in file %s\n",
                 line_count, infilename);
          fclose(fp);
          return false;
        }
        coord[i] = (REAL) strtod(bufferp, &bufferp);
        bufferp = findnextnumber(bufferp);
      }
      iverts++;
    } else if (ifaces < nfaces) {
      // Get next face
      f = &facetlist[ifaces];
      init(f);      
      // In .off format, each facet has one polygon, no hole.
      f->numberofpolygons = 1;
      f->polygonlist = new tetgenio::polygon[1];
      p = &f->polygonlist[0];
      init(p);
      // Read the number of vertices, it should be greater than 0.
      p->numberofvertices = (int) strtol(bufferp, &bufferp, 0);
      if (p->numberofvertices == 0) {
        printf("Syntax error reading polygon on line %d in file %s\n",
               line_count, infilename);
        fclose(fp);
        return false;
      }
      // Allocate memory for face vertices
      p->vertexlist = new int[p->numberofvertices];
      for (i = 0; i < p->numberofvertices; i++) {
        bufferp = findnextnumber(bufferp);
        if (*bufferp == '\0') {
          printf("Syntax error reading polygon on line %d in file %s\n",
                 line_count, infilename);
          fclose(fp);
          return false;
        }
        p->vertexlist[i] = (int) strtol(bufferp, &bufferp, 0);
      }
      ifaces++;
    } else {
      // Should never get here
      printf("Found extra text starting at line %d in file %s\n", line_count,
             infilename);
      break;
    }
  }

  // Close file
  fclose(fp);

  // Check whether read all points
  if (iverts != nverts) {
    printf("Expected %d vertices, but read only %d vertices in file %s\n",
           nverts, iverts, infilename);
    return false;
  }

  // Check whether read all faces
  if (ifaces != nfaces) {
    printf("Expected %d faces, but read only %d faces in file %s\n",
           nfaces, ifaces, infilename);
    return false;
  }

  return true;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// load_stl()    Load a surface mesh described in a .stl file.               //
//                                                                           //
// 'filename' is the file name with extension .stl or without extension (the //
// .stl will be added in this case).                                         //
//                                                                           //
// The .stl or stereolithography format is an ASCII or binary file used in   //
// manufacturing.  It is a list of the triangular surfaces that describe a   //
// computer generated solid model. This is the standard input for most rapid //
// prototyping machines.                                                     //
//                                                                           //
// On completion, 'pointlist' and 'facetlist' together return the polyhedron.//
// Note: After load_stl(), there exist many duplicated points in 'pointlist'.//
// They will be unified during the Delaunay tetrahedralization process.      //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenio::load_stl(const char* filename)
{
  FILE *fp;
  facet *f;
  polygon *p;
  char infilename[FILENAMESIZE];
  char buffer[INPUTLINESIZE];
  char *bufferp, *str;
  double *tmplist, *coord;
  int solid = 0;
  int maxverts = 1024, nverts = 0, iverts = 0;
  int nfaces = 0;
  int line_count = 0, i;

  strncpy(infilename, filename, FILENAMESIZE - 1);
  infilename[FILENAMESIZE - 1] = '\0';
  if (infilename[0] == '\0') {
    printf("Error:  No filename.\n");
    return false;
  }
  if (strcmp(&infilename[strlen(infilename) - 4], ".stl") != 0) {
    strcat(infilename, ".stl");
  }

  if (!(fp = fopen(infilename, "r"))) {
    printf("Error:  Unable to open file %s\n", infilename);
    return false;
  }
  printf("Opening %s.\n", infilename);

  // STL file has no number of points available. Use a list to read points.
  tmplist = (double *) malloc(sizeof(double) * 3 * maxverts); 

  while ((bufferp = readline(buffer, fp, &line_count)) != NULL) {
    // The ASCII .stl file must start with the lower case keyword solid and
    //   end with endsolid.
    if (solid == 0) {
      // Read header 
      bufferp = strstr(bufferp, "solid");
      if (bufferp != NULL) {
        solid = 1;
      }
    } else {
      // We're inside the block of the solid.
      str = bufferp;
      // Is this the end of the solid.
      bufferp = strstr(bufferp, "endsolid");
      if (bufferp != NULL) {
        solid = 0;
      } else {
        // Read the XYZ coordinates if it is a vertex.
        bufferp = str;
        bufferp = strstr(bufferp, "vertex");
        if (bufferp != NULL) {
	  // Check if we have enough memory.
	  if (nverts == maxverts) {
	    maxverts += 1024;
	    tmplist = (double *) realloc(tmplist, sizeof(double)*3*maxverts);
	  }
          coord = &(tmplist[nverts * 3]);
          for (i = 0; i < 3; i++) {
            bufferp = findnextnumber(bufferp);
            if (*bufferp == '\0') {
              printf("Syntax error reading vertex coords on line %d\n",
                     line_count);
              free(tmplist);
              fclose(fp);
              return false;
            }
            coord[i] = (REAL) strtod(bufferp, &bufferp);
          }
	  nverts++;
        }
      }
    }
  }
  fclose(fp);

  // nverts should be an integer times 3 (every 3 vertices denote a face).
  if (nverts == 0 || (nverts % 3 != 0)) {
    printf("Error:  Wrong number of vertices in file %s.\n", infilename);
    free(tmplist);
    return false;
  }
  numberofpoints = nverts;
  pointlist = new REAL[nverts * 3];
  for (i = 0; i < nverts; i++) {
    coord = &(tmplist[i * 3]);
    iverts = i * 3;
    pointlist[iverts] = (REAL) coord[0];
    pointlist[iverts + 1] = (REAL) coord[1];
    pointlist[iverts + 2] = (REAL) coord[2];
  }

  nfaces = (int) (nverts / 3);
  numberoffacets = nfaces;
  facetlist = new facet[nfaces];

  // Default use '1' as the array starting index.
  firstnumber = 1;
  iverts = firstnumber;
  for (i = 0; i < nfaces; i++) {
    f = &facetlist[i];
    init(f);      
    // In .stl format, each facet has one polygon, no hole.
    f->numberofpolygons = 1;
    f->polygonlist = new polygon[1];
    p = &f->polygonlist[0];
    init(p);
    // Each polygon has three vertices.
    p->numberofvertices = 3;
    p->vertexlist = new int[p->numberofvertices];
    p->vertexlist[0] = iverts;
    p->vertexlist[1] = iverts + 1;
    p->vertexlist[2] = iverts + 2;
    iverts += 3;
  }

  free(tmplist);
  return true;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// load_medit()    Load a surface mesh described in .mesh file.              //
//                                                                           //
// 'filename' is the file name with extension .mesh or without entension (   //
// the .mesh will be added in this case). .mesh is the file format of Medit, //
// a user-friendly interactive mesh viewing program.                         //
//                                                                           //
// This routine ONLY reads the sections containing vertices, triangles, and  //
// quadrilaters. Other sections (such as tetrahedra, edges, ...) are ignored.//
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenio::load_medit(const char* filename)
{
  FILE *fp;
  tetgenio::facet *tmpflist, *f;
  tetgenio::polygon *p;
  char infilename[FILENAMESIZE];
  char buffer[INPUTLINESIZE];
  char *bufferp, *str;
  double *coord;
  int *tmpfmlist;
  int dimension = 0;
  int nverts = 0;
  int nfaces = 0;
  int line_count = 0;
  int corners = 0; // 3 (triangle) or 4 (quad).
  int i, j;

  strncpy(infilename, filename, FILENAMESIZE - 1);
  infilename[FILENAMESIZE - 1] = '\0';
  if (infilename[0] == '\0') {
    printf("Error:  No filename.\n");
    return false;
  }
  if (strcmp(&infilename[strlen(infilename) - 5], ".mesh") != 0) {
    strcat(infilename, ".mesh");
  }
  
  if (!(fp = fopen(infilename, "r"))) {
    printf("Error:  Unable to open file %s\n", infilename);
    return false;
  }
  printf("Opening %s.\n", infilename);

  // Default uses the index starts from '1'.
  firstnumber = 1;

  while ((bufferp = readline(buffer, fp, &line_count)) != NULL) {
    if (*bufferp == '#') continue;  // A comment line is skipped.
    if (dimension == 0) {
      // Find if it is the keyword "Dimension".
      str = strstr(bufferp, "Dimension");
      if (!str) str = strstr(bufferp, "dimension");
      if (!str) str = strstr(bufferp, "DIMENSION");
      if (str) {
        // Read the dimensions
        bufferp = findnextnumber(str); // Skip field "Dimension".
        if (*bufferp == '\0') {
          // Read a non-empty line.
          bufferp = readline(buffer, fp, &line_count);
        }
        dimension = (int) strtol(bufferp, &bufferp, 0);
        if (dimension != 2 && dimension != 3) {
          printf("Unknown dimension in file on line %d in file %s\n",
                 line_count, infilename);
          fclose(fp);
          return false;
        }
        mesh_dim = dimension;
      }
    }
    if (nverts == 0) {
      // Find if it is the keyword "Vertices".
      str = strstr(bufferp, "Vertices");
      if (!str) str = strstr(bufferp, "vertices");
      if (!str) str = strstr(bufferp, "VERTICES");
      if (str) {
        // Read the number of vertices.
        bufferp = findnextnumber(str); // Skip field "Vertices".
        if (*bufferp == '\0') {
          // Read a non-empty line.
          bufferp = readline(buffer, fp, &line_count);
        }
        nverts = (int) strtol(bufferp, &bufferp, 0);
        // Allocate memory for 'tetgenio'
        if (nverts > 0) {
          numberofpoints = nverts;
          pointlist = new REAL[nverts * 3];
        }
        // Read the follwoing node list.
        for (i = 0; i < nverts; i++) {
          bufferp = readline(buffer, fp, &line_count);
          if (bufferp == NULL) {
            printf("Unexpected end of file on line %d in file %s\n",
                   line_count, infilename);
            fclose(fp);
            return false;
          }
          // Read vertex coordinates
          coord = &pointlist[i * 3];
          for (j = 0; j < 3; j++) {
            if (*bufferp == '\0') {
              printf("Syntax error reading vertex coords on line");
              printf(" %d in file %s\n", line_count, infilename);
              fclose(fp);
              return false;
            }
            if ((j < 2) || (dimension == 3)) {
              coord[j] = (REAL) strtod(bufferp, &bufferp);
            } else {
              assert((j == 2) && (dimension == 2));
              coord[j] = 0.0;
            }
            bufferp = findnextnumber(bufferp);
          }
        }
        continue;
      }
    } 
    if (nfaces == 0) {
      // Find if it is the keyword "Triangles" or "Quadrilaterals".
      corners = 0;
      str = strstr(bufferp, "Triangles");
      if (!str) str = strstr(bufferp, "triangles");
      if (!str) str = strstr(bufferp, "TRIANGLES");
      if (str) {
        corners = 3;
      } else {
        str = strstr(bufferp, "Quadrilaterals");
        if (!str) str = strstr(bufferp, "quadrilaterals");
        if (!str) str = strstr(bufferp, "QUADRILATERALS");
        if (str) {
          corners = 4;
        }
      }
      if (corners == 3 || corners == 4) {
        // Read the number of triangles (or quadrilaterals).
        bufferp = findnextnumber(str); // Skip field "Triangles".
        if (*bufferp == '\0') {
          // Read a non-empty line.
          bufferp = readline(buffer, fp, &line_count);
        }
        nfaces = strtol(bufferp, &bufferp, 0);
        // Allocate memory for 'tetgenio'
        if (nfaces > 0) {
          if (numberoffacets > 0) {
            // facetlist has already been allocated. Enlarge arrays.
            tmpflist = new tetgenio::facet[numberoffacets + nfaces];
            tmpfmlist = new int[numberoffacets + nfaces];
            // Copy the data of old arrays into new arrays.
            for (i = 0; i < numberoffacets; i++) {
              f = &(tmpflist[i]);
              tetgenio::init(f);
              *f = facetlist[i];
              tmpfmlist[i] = facetmarkerlist[i];
            }
            // Release old arrays.
            delete [] facetlist;
            delete [] facetmarkerlist;
            // Remember the new arrays.
            facetlist = tmpflist;
            facetmarkerlist = tmpfmlist;
          } else {
            // This is the first time to allocate facetlist.
            facetlist = new tetgenio::facet[nfaces];
            facetmarkerlist = new int[nfaces];
          }
        }
        // Read the following list of faces.
        for (i = numberoffacets; i < numberoffacets + nfaces; i++) {
          bufferp = readline(buffer, fp, &line_count);
          if (bufferp == NULL) {
            printf("Unexpected end of file on line %d in file %s\n",
                   line_count, infilename);
            fclose(fp);
            return false;
          }
          f = &facetlist[i];
          tetgenio::init(f);
          // In .mesh format, each facet has one polygon, no hole.
          f->numberofpolygons = 1;
          f->polygonlist = new tetgenio::polygon[1];
          p = &f->polygonlist[0];
          tetgenio::init(p);
          p->numberofvertices = corners;
          // Allocate memory for face vertices
          p->vertexlist = new int[p->numberofvertices];
          // Read the vertices of the face.
          for (j = 0; j < corners; j++) {
            if (*bufferp == '\0') {
              printf("Syntax error reading face on line %d in file %s\n",
                     line_count, infilename);
              fclose(fp);
              return false;
            }
            p->vertexlist[j] = (int) strtol(bufferp, &bufferp, 0);
            if (firstnumber == 1) {
              // Check if a '0' index appears.
              if (p->vertexlist[j] == 0) {
                // The first index is set to be 0.
                firstnumber = 0;
              }
            }
            bufferp = findnextnumber(bufferp);
          }
          // Read the marker of the face if it exists.
          facetmarkerlist[i] = 0;
          if (*bufferp != '\0') {
            facetmarkerlist[i] = (int) strtol(bufferp, &bufferp, 0);
          }
        }
        // Have read in a list of triangles/quads.
        numberoffacets += nfaces;
        nfaces = 0;
      }
    }
    // if (nverts > 0 && nfaces > 0) break; // Ignore other data.
  }

  // Close file
  fclose(fp);

  return true;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// load_vtk()    Load VTK surface mesh from file (.vtk ascii or binary).     //
//                                                                           //
// 'filename' is a string containing the file name with or without suffix.   //
//                                                                           //
// This function is contributed by user: Bryn Lloyd (May 7, 2007).           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void swapBytes(unsigned char* var, int size)
{
  int i = 0;
  int j = size - 1;
  char c;

  while (i < j) {
    c = var[i]; var[i] = var[j]; var[j] = c;
    i++, j--;
  }
}

bool testIsBigEndian()
{
  short word = 0x4321;
  if((*(char *)& word) != 0x21)
    return true;
  else 
    return false;
}

bool tetgenio::load_vtk(const char* filename)
{
  FILE *fp;
  tetgenio::facet *f;
  tetgenio::polygon *p;
  char infilename[FILENAMESIZE];
  char line[INPUTLINESIZE];
  char mode[128], id[256], fmt[64];
  char *bufferp;
  double *coord;
  float _x, _y, _z;
  int nverts = 0;
  int nfaces = 0;
  int line_count = 0;
  int dummy;
  int id1, id2, id3;
  int nn = -1;
  int nn_old = -1;
  int i, j;
  bool ImALittleEndian = !testIsBigEndian();

  strncpy(infilename, filename, FILENAMESIZE - 1);
  infilename[FILENAMESIZE - 1] = '\0';
  if (infilename[0] == '\0') {
    printf("Error:  No filename.\n");
    return false;
  }
  if (strcmp(&infilename[strlen(infilename) - 4], ".vtk") != 0) {
    strcat(infilename, ".vtk");
  }
  if (!(fp = fopen(infilename, "r"))) {
    printf("Error:  Unable to open file %s\n", infilename);
    return false;
  }
  printf("Opening %s.\n", infilename);

  // Default uses the index starts from '0'.
  firstnumber = 0;
  strcpy(mode, "BINARY");

  while((bufferp = readline(line, fp, &line_count)) != NULL) {
    if(strlen(line) == 0) continue;
    //swallow lines beginning with a comment sign or white space
    if(line[0] == '#' || line[0]=='\n' || line[0] == 10 || line[0] == 13 || 
       line[0] == 32) continue;

    sscanf(line, "%s", id);
    if(!strcmp(id, "ASCII")) {
      strcpy(mode, "ASCII");
    }

    if(!strcmp(id, "POINTS")) {
      sscanf(line, "%s %d %s", id, &nverts, fmt);
      if (nverts > 0) {
        numberofpoints = nverts;
        pointlist = new REAL[nverts * 3];
      }

      if(!strcmp(mode, "BINARY")) {
        for(i = 0; i < nverts; i++) {
          coord = &pointlist[i * 3];
          if(!strcmp(fmt, "double")) {
            fread((char*)(&(coord[0])), sizeof(double), 1, fp);
            fread((char*)(&(coord[1])), sizeof(double), 1, fp);
            fread((char*)(&(coord[2])), sizeof(double), 1, fp);
            if(ImALittleEndian){
              swapBytes((unsigned char *) &(coord[0]), sizeof(coord[0]));
              swapBytes((unsigned char *) &(coord[1]), sizeof(coord[1]));
              swapBytes((unsigned char *) &(coord[2]), sizeof(coord[2]));
            }
          } else if(!strcmp(fmt, "float")) {
            fread((char*)(&_x), sizeof(float), 1, fp);
            fread((char*)(&_y), sizeof(float), 1, fp);
            fread((char*)(&_z), sizeof(float), 1, fp);
            if(ImALittleEndian){
              swapBytes((unsigned char *) &_x, sizeof(_x));
              swapBytes((unsigned char *) &_y, sizeof(_y));
              swapBytes((unsigned char *) &_z, sizeof(_z));
            }
            coord[0] = double(_x);
            coord[1] = double(_y);
            coord[2] = double(_z);
          } else {
            printf("Error: Only float or double formats are supported!\n");
            return false;
          }
        }
      } else if(!strcmp(mode, "ASCII")) {
        for(i = 0; i < nverts; i++){
          bufferp = readline(line, fp, &line_count);
          if (bufferp == NULL) {
            printf("Unexpected end of file on line %d in file %s\n",
                   line_count, infilename);
            fclose(fp);
            return false;
          }
          // Read vertex coordinates
          coord = &pointlist[i * 3];
          for (j = 0; j < 3; j++) {
            if (*bufferp == '\0') {
              printf("Syntax error reading vertex coords on line");
              printf(" %d in file %s\n", line_count, infilename);
              fclose(fp);
              return false;
            }
            coord[j] = (REAL) strtod(bufferp, &bufferp);
            bufferp = findnextnumber(bufferp);
          }
        }
      }
      continue;
    }

    if(!strcmp(id, "POLYGONS")) {
      sscanf(line, "%s %d  %d", id, &nfaces, &dummy);
      if (nfaces > 0) {
        numberoffacets = nfaces;
        facetlist = new tetgenio::facet[nfaces];
      }

      if(!strcmp(mode, "BINARY")) {
        for(i = 0; i < nfaces; i++){
          fread((char*)(&nn), sizeof(int), 1, fp);
          if(ImALittleEndian){
            swapBytes((unsigned char *) &nn, sizeof(nn));
          }
          if (i == 0)
            nn_old = nn;
          if (nn != nn_old) {
            printf("Error:  No mixed cells are allowed.\n");
            return false;
          }

          if(nn == 3){
            fread((char*)(&id1), sizeof(int), 1, fp);
            fread((char*)(&id2), sizeof(int), 1, fp);
            fread((char*)(&id3), sizeof(int), 1, fp);
            if(ImALittleEndian){
              swapBytes((unsigned char *) &id1, sizeof(id1));
              swapBytes((unsigned char *) &id2, sizeof(id2));
              swapBytes((unsigned char *) &id3, sizeof(id3));
            }
            f = &facetlist[i];
            init(f);
            // In .off format, each facet has one polygon, no hole.
            f->numberofpolygons = 1;
            f->polygonlist = new tetgenio::polygon[1];
            p = &f->polygonlist[0];
            init(p);
            // Set number of vertices
            p->numberofvertices = 3;
            // Allocate memory for face vertices
            p->vertexlist = new int[p->numberofvertices];
            p->vertexlist[0] = id1;
            p->vertexlist[1] = id2;
            p->vertexlist[2] = id3;
          } else {
            printf("Error: Only triangles are supported\n");
            return false;
          }
        }
      } else if(!strcmp(mode, "ASCII")) {
        for(i = 0; i < nfaces; i++) {
          bufferp = readline(line, fp, &line_count);
          nn = (int) strtol(bufferp, &bufferp, 0);
          if (i == 0)
            nn_old = nn;
          if (nn != nn_old) {
            printf("Error:  No mixed cells are allowed.\n");
            return false;
          }

          if (nn == 3) {
            bufferp = findnextnumber(bufferp); // Skip the first field.
            id1 = (int) strtol(bufferp, &bufferp, 0);
            bufferp = findnextnumber(bufferp);
            id2 = (int) strtol(bufferp, &bufferp, 0);
            bufferp = findnextnumber(bufferp);
            id3 = (int) strtol(bufferp, &bufferp, 0);
            f = &facetlist[i];
            init(f);
            // In .off format, each facet has one polygon, no hole.
            f->numberofpolygons = 1;
            f->polygonlist = new tetgenio::polygon[1];
            p = &f->polygonlist[0];
            init(p);
            // Set number of vertices
            p->numberofvertices = 3;
            // Allocate memory for face vertices
            p->vertexlist = new int[p->numberofvertices];
            p->vertexlist[0] = id1;
            p->vertexlist[1] = id2;
            p->vertexlist[2] = id3;
          } else {
            printf("Error:  Only triangles are supported.\n");
            return false;
          }
        }
      }

      fclose(fp);
      return true;
    }

    if(!strcmp(id,"LINES") || !strcmp(id,"CELLS")){
      printf("Warning:  load_vtk(): cannot read formats LINES, CELLS.\n");
    }
  } // while ()

  return true;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// load_plc()    Load a piecewise linear complex from file.                  //
//                                                                           //
// This is main entrance for loading plcs from different file formats into   //
// tetgenio.  'filename' is the input file name without extention. 'object'  //
// indicates which file format is used to describ the plc.                   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenio::load_plc(const char* filename, int object)
{
  enum tetgenbehavior::objecttype type;

  type = (enum tetgenbehavior::objecttype) object;
  switch (type) {
  case tetgenbehavior::NODES:
    return load_node(filename);
  case tetgenbehavior::POLY:
    return load_poly(filename);
  case tetgenbehavior::OFF:
    return load_off(filename);
  case tetgenbehavior::PLY:
    return load_ply(filename);
  case tetgenbehavior::STL:
    return load_stl(filename);
  case tetgenbehavior::MEDIT:
    return load_medit(filename);
  case tetgenbehavior::VTK:
    return load_vtk(filename);
  default:
    return load_poly(filename);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// load_tetmesh()    Load a tetrahedral mesh from files.                     //
//                                                                           //
// 'filename' is the inputfile without suffix.  The nodes of the tetrahedral //
// mesh is in "filename.node",  the elements is in "filename.ele", if the    //
// "filename.face" and "filename.vol" exists, they will also be read.        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenio::load_tetmesh(const char* filename)
{
  FILE *infile;
  char innodefilename[FILENAMESIZE];
  char inelefilename[FILENAMESIZE];
  char infacefilename[FILENAMESIZE];
  char inedgefilename[FILENAMESIZE];
  char involfilename[FILENAMESIZE];
  char inputline[INPUTLINESIZE];
  char *stringptr, *infilename;
  REAL attrib, volume;
  int volelements;
  int markers, corner;
  int index, attribindex;
  int i, j;

  // Assembling the actual file names we want to open.
  strcpy(innodefilename, filename);
  strcpy(inelefilename, filename);
  strcpy(infacefilename, filename);
  strcpy(inedgefilename, filename);
  strcpy(involfilename, filename);
  strcat(innodefilename, ".node");
  strcat(inelefilename, ".ele");
  strcat(infacefilename, ".face");
  strcat(inedgefilename, ".edge");
  strcat(involfilename, ".vol");

  // Read the points from a .node file.
  infilename = innodefilename;
  printf("Opening %s.\n", infilename);
  infile = fopen(infilename, "r");
  if (infile == (FILE *) NULL) {
    printf("File I/O Error:  Cannot access file %s.\n", infilename);
    return false;
  }
  // Read the first line of the file.
  stringptr = readnumberline(inputline, infile, infilename); 
  // Is this list of points generated from rbox?
  stringptr = strstr(inputline, "rbox");
  if (stringptr == NULL) {
    // Read number of points, number of dimensions, number of point
    //   attributes, and number of boundary markers.
    stringptr = inputline;
    numberofpoints = (int) strtol (stringptr, &stringptr, 0);
    stringptr = findnextnumber(stringptr);
    if (*stringptr == '\0') {
      mesh_dim = 3;
    } else {
      mesh_dim = (int) strtol (stringptr, &stringptr, 0);
    }
    stringptr = findnextnumber(stringptr);
    if (*stringptr == '\0') {
      numberofpointattributes = 0;
    } else {
      numberofpointattributes = (int) strtol (stringptr, &stringptr, 0);
    }
    stringptr = findnextnumber(stringptr);
    if (*stringptr == '\0') {
      markers = 0;  // Default value.
    } else {
      markers = (int) strtol (stringptr, &stringptr, 0);
    }
  } else {
    // It is a rbox (qhull) input file.
    stringptr = inputline;
    // Get the dimension.
    mesh_dim = (int) strtol (stringptr, &stringptr, 0);
    // Get the number of points.
    stringptr = readnumberline(inputline, infile, infilename);
    numberofpoints = (int) strtol (stringptr, &stringptr, 0);
    // There is no index column.
    useindex = 0;
  }

  // Load the list of nodes.
  if (!load_node_call(infile, markers, infilename)) {
    fclose(infile);
    return false;
  }
  fclose(infile);

  // Read the elements from an .ele file.
  if (mesh_dim == 3) {
    infilename = inelefilename;
    infile = fopen(infilename, "r");
    if (infile != (FILE *) NULL) {
      printf("Opening %s.\n", infilename);
      // Read number of elements, number of corners (4 or 10), number of
      //   element attributes.
      stringptr = readnumberline(inputline, infile, infilename);
      numberoftetrahedra = (int) strtol (stringptr, &stringptr, 0);
      stringptr = findnextnumber(stringptr);
      if (*stringptr == '\0') {
        numberofcorners = 4;  // Default read 4 nodes per element.
      } else {
        numberofcorners = (int) strtol(stringptr, &stringptr, 0);
      }
      stringptr = findnextnumber(stringptr);
      if (*stringptr == '\0') {
        numberoftetrahedronattributes = 0; // Default no attribute.
      } else {
        numberoftetrahedronattributes = (int) strtol(stringptr, &stringptr, 0);
      }
      if (numberofcorners != 4 && numberofcorners != 10) {
        printf("Error:  Wrong number of corners %d (should be 4 or 10).\n", 
               numberofcorners);
        fclose(infile);
        return false;
      }
      // Allocate memory for tetrahedra.
      if (numberoftetrahedra > 0) {
        tetrahedronlist = new int[numberoftetrahedra * numberofcorners]; 
        if (tetrahedronlist == (int *) NULL) {
          printf("Error:  Out of memory.\n");
          terminatetetgen(1);
        }
        // Allocate memory for output tetrahedron attributes if necessary.
        if (numberoftetrahedronattributes > 0) {
          tetrahedronattributelist = new REAL[numberoftetrahedra *
                                          numberoftetrahedronattributes];
          if (tetrahedronattributelist == (REAL *) NULL) {
            printf("Error:  Out of memory.\n");
            terminatetetgen(1);
          }
        }
      }
      // Read the list of tetrahedra.
      index = 0;
      attribindex = 0;
      for (i = 0; i < numberoftetrahedra; i++) {
        // Read tetrahedron index and the tetrahedron's corners.
        stringptr = readnumberline(inputline, infile, infilename);
        for (j = 0; j < numberofcorners; j++) {
          stringptr = findnextnumber(stringptr);
          if (*stringptr == '\0') {
            printf("Error:  Tetrahedron %d is missing vertex %d in %s.\n",
                   i + firstnumber, j + 1, infilename);
            terminatetetgen(1);
          }
          corner = (int) strtol(stringptr, &stringptr, 0);
          if (corner < firstnumber || corner >= numberofpoints + firstnumber) {
            printf("Error:  Tetrahedron %d has an invalid vertex index.\n",
                   i + firstnumber);
            terminatetetgen(1);
          }
          tetrahedronlist[index++] = corner;
        }
        // Read the tetrahedron's attributes.
        for (j = 0; j < numberoftetrahedronattributes; j++) {
          stringptr = findnextnumber(stringptr);
          if (*stringptr == '\0') {
            attrib = 0.0;
          } else {
            attrib = (REAL) strtod(stringptr, &stringptr);
          }
          tetrahedronattributelist[attribindex++] = attrib;
        }
      }
      fclose(infile);
    }
  } // if (meshdim == 3)
  
  // Read the hullfaces or subfaces from a .face file if it exists.
  if (mesh_dim == 3) {
    infilename = infacefilename;
  } else {
    infilename = inelefilename;
  }
  infile = fopen(infilename, "r");
  if (infile != (FILE *) NULL) {
    printf("Opening %s.\n", infilename);
    // Read number of faces, boundary markers.
    stringptr = readnumberline(inputline, infile, infilename);
    numberoftrifaces = (int) strtol (stringptr, &stringptr, 0);
    stringptr = findnextnumber(stringptr);
    if (mesh_dim == 2) {
      // Skip a number.
      stringptr = findnextnumber(stringptr);
    }
    if (*stringptr == '\0') {
      markers = 0;  // Default there is no marker per face.
    } else {
      markers = (int) strtol (stringptr, &stringptr, 0);
    }
    if (numberoftrifaces > 0) {
      trifacelist = new int[numberoftrifaces * 3];
      if (trifacelist == (int *) NULL) {
        printf("Error:  Out of memory.\n");
        terminatetetgen(1);
      }
      if (markers) {
        trifacemarkerlist = new int[numberoftrifaces * 3];
        if (trifacemarkerlist == (int *) NULL) {
          printf("Error:  Out of memory.\n");
          terminatetetgen(1);
        }
      }
    }
    // Read the list of faces.
    index = 0;
    for (i = 0; i < numberoftrifaces; i++) {
      // Read face index and the face's three corners.
      stringptr = readnumberline(inputline, infile, infilename);
      for (j = 0; j < 3; j++) {
        stringptr = findnextnumber(stringptr);
        if (*stringptr == '\0') {
          printf("Error:  Face %d is missing vertex %d in %s.\n",
                 i + firstnumber, j + 1, infilename);
          terminatetetgen(1);
        }
        corner = (int) strtol(stringptr, &stringptr, 0);
        if (corner < firstnumber || corner >= numberofpoints + firstnumber) {
          printf("Error:  Face %d has an invalid vertex index.\n",
                 i + firstnumber);
          terminatetetgen(1);
        }
        trifacelist[index++] = corner;
      }
      // Read the boundary marker if it exists.
      if (markers) {
        stringptr = findnextnumber(stringptr);
        if (*stringptr == '\0') {
          attrib = 0.0;
        } else {
          attrib = (REAL) strtod(stringptr, &stringptr);
        }
        trifacemarkerlist[i] = (int) attrib;
      }
    }
    fclose(infile);
  }

  // Read the boundary edges from a .edge file if it exists.
  infilename = inedgefilename;
  infile = fopen(infilename, "r");
  if (infile != (FILE *) NULL) {
    printf("Opening %s.\n", infilename);
    // Read number of boundary edges.
    stringptr = readnumberline(inputline, infile, infilename);
    numberofedges = (int) strtol (stringptr, &stringptr, 0);
    if (numberofedges > 0) {
      edgelist = new int[numberofedges * 2];
      if (edgelist == (int *) NULL) {
        printf("Error:  Out of memory.\n");
        terminatetetgen(1);
      }
      stringptr = findnextnumber(stringptr);
      if (*stringptr == '\0') {
        markers = 0;  // Default value.
      } else {
        markers = (int) strtol (stringptr, &stringptr, 0);
      }
      if (markers > 0) {
        edgemarkerlist = new int[numberofedges];
      }
    }
    // Read the list of faces.
    index = 0;
    for (i = 0; i < numberofedges; i++) {
      // Read face index and the edge's two endpoints.
      stringptr = readnumberline(inputline, infile, infilename);
      for (j = 0; j < 2; j++) {
        stringptr = findnextnumber(stringptr);
        if (*stringptr == '\0') {
          printf("Error:  Edge %d is missing vertex %d in %s.\n",
                 i + firstnumber, j + 1, infilename);
          terminatetetgen(1);
        }
        corner = (int) strtol(stringptr, &stringptr, 0);
        if (corner < firstnumber || corner >= numberofpoints + firstnumber) {
          printf("Error:  Edge %d has an invalid vertex index.\n",
                 i + firstnumber);
          terminatetetgen(1);
        }
        edgelist[index++] = corner;
      }
      // Read the edge marker if it has.
      if (markers) {
        stringptr = findnextnumber(stringptr);
        edgemarkerlist[i] = (int) strtol(stringptr, &stringptr, 0);
      }
    }
    fclose(infile);
  }

  // Read the volume constraints from a .vol file if it exists.
  infilename = involfilename;
  infile = fopen(infilename, "r");
  if (infile != (FILE *) NULL) {
    printf("Opening %s.\n", infilename);
    // Read number of tetrahedra.
    stringptr = readnumberline(inputline, infile, infilename);
    volelements = (int) strtol (stringptr, &stringptr, 0);
    if (volelements != numberoftetrahedra) {
      printf("Warning:  %s and %s disagree on number of tetrahedra.\n",
             inelefilename, involfilename);
      volelements = 0;
    }
    if (volelements > 0) {
      tetrahedronvolumelist = new REAL[volelements];
      if (tetrahedronvolumelist == (REAL *) NULL) {
        printf("Error:  Out of memory.\n");
        terminatetetgen(1);
      }
    }
    // Read the list of volume constraints.
    for (i = 0; i < volelements; i++) {
      stringptr = readnumberline(inputline, infile, infilename);
      stringptr = findnextnumber(stringptr);
      if (*stringptr == '\0') {
        volume = -1.0; // No constraint on this tetrahedron.
      } else {
        volume = (REAL) strtod(stringptr, &stringptr);
      }
      tetrahedronvolumelist[i] = volume;
    }
    fclose(infile);
  }

  // Try to load a .mtr file if it exists.
  load_mtr(filename);
  // Try to read a .pbc file if it exists.
  load_pbc(filename);

  return true;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// load_voronoi()    Load a Voronoi diagram from files.                      //
//                                                                           //
// 'filename' is the inputfile without suffix.  The Voronoi diagram is read  //
// from files: filename.v.node, filename.v.edge, and filename.v.face.        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenio::load_voronoi(const char* filename)
{
  FILE *infile;
  char innodefilename[FILENAMESIZE];
  char inedgefilename[FILENAMESIZE];
  char inputline[INPUTLINESIZE];
  char *stringptr, *infilename;
  voroedge *vedge;
  REAL x, y, z;
  int firstnode, corner;
  int index;
  int i, j;

  // Assembling the actual file names we want to open.
  strcpy(innodefilename, filename);
  strcpy(inedgefilename, filename);
  strcat(innodefilename, ".v.node");
  strcat(inedgefilename, ".v.edge");

  // Read the points from a .v.node file.
  infilename = innodefilename;
  printf("Opening %s.\n", infilename);
  infile = fopen(infilename, "r");
  if (infile == (FILE *) NULL) {
    printf("File I/O Error:  Cannot access file %s.\n", infilename);
    return false;
  }
  // Read the first line of the file.
  stringptr = readnumberline(inputline, infile, infilename); 
  // Is this list of points generated from rbox?
  stringptr = strstr(inputline, "rbox");
  if (stringptr == NULL) {
    // Read number of points, number of dimensions, number of point
    //   attributes, and number of boundary markers.
    stringptr = inputline;
    numberofvpoints = (int) strtol (stringptr, &stringptr, 0);
    stringptr = findnextnumber(stringptr);
    if (*stringptr == '\0') {
      mesh_dim = 3;  // Default.
    } else {
      mesh_dim = (int) strtol (stringptr, &stringptr, 0);
    }
    useindex = 1;  // There is an index column.
  } else {
    // It is a rbox (qhull) input file.
    stringptr = inputline;
    // Get the dimension.
    mesh_dim = (int) strtol (stringptr, &stringptr, 0);
    // Get the number of points.
    stringptr = readnumberline(inputline, infile, infilename);
    numberofvpoints = (int) strtol (stringptr, &stringptr, 0);
    useindex = 0;  // No index column.
  }
  // Initialize 'vpointlist'.
  vpointlist = new REAL[numberofvpoints * 3];
  if (vpointlist == (REAL *) NULL) {
    printf("Error:  Out of memory.\n");
    terminatetetgen(1);
  }
  // Read the point section.
  index = 0;
  for (i = 0; i < numberofvpoints; i++) {
    stringptr = readnumberline(inputline, infile, infilename);
    if (useindex) {
      if (i == 0) {
        firstnode = (int) strtol (stringptr, &stringptr, 0);
        if ((firstnode == 0) || (firstnode == 1)) {
          firstnumber = firstnode;
        }
      }
      stringptr = findnextnumber(stringptr);
    } // if (useindex)
    if (*stringptr == '\0') {
      printf("Error:  Point %d has no x coordinate.\n", firstnumber + i);
      terminatetetgen(1);
    }
    x = (REAL) strtod(stringptr, &stringptr);
    stringptr = findnextnumber(stringptr);
    if (*stringptr == '\0') {
      printf("Error:  Point %d has no y coordinate.\n", firstnumber + i);
      terminatetetgen(1);
    }
    y = (REAL) strtod(stringptr, &stringptr);
    if (mesh_dim == 3) {
      stringptr = findnextnumber(stringptr);
      if (*stringptr == '\0') {
        printf("Error:  Point %d has no z coordinate.\n", firstnumber + i);
        terminatetetgen(1);
      }
      z = (REAL) strtod(stringptr, &stringptr);
    } else {
      z = 0.0; // mesh_dim == 2;
    }
    vpointlist[index++] = x;
    vpointlist[index++] = y;
    vpointlist[index++] = z;
  }
  fclose(infile);

  // Read the Voronoi edges from a .v.edge file if it exists.
  infilename = inedgefilename;
  infile = fopen(infilename, "r");
  if (infile != (FILE *) NULL) {
    printf("Opening %s.\n", infilename);
    // Read number of boundary edges.
    stringptr = readnumberline(inputline, infile, infilename);
    numberofvedges = (int) strtol (stringptr, &stringptr, 0);
    if (numberofvedges > 0) {
      vedgelist = new voroedge[numberofvedges];
    }
    // Read the list of faces.
    index = 0;
    for (i = 0; i < numberofvedges; i++) {
      // Read edge index and the edge's two endpoints.
      stringptr = readnumberline(inputline, infile, infilename);
      vedge = &(vedgelist[i]);
      for (j = 0; j < 2; j++) {
        stringptr = findnextnumber(stringptr);
        if (*stringptr == '\0') {
          printf("Error:  Edge %d is missing vertex %d in %s.\n",
                 i + firstnumber, j + 1, infilename);
          terminatetetgen(1);
        }
        corner = (int) strtol(stringptr, &stringptr, 0);
        j == 0 ? vedge->v1 = corner : vedge->v2 = corner;
      }
      if (vedge->v2 < 0) {
        for (j = 0; j < mesh_dim; j++) {
          stringptr = findnextnumber(stringptr);
          if (*stringptr == '\0') {
            printf("Error:  Edge %d is missing normal in %s.\n",
                   i + firstnumber, infilename);
            terminatetetgen(1);
          }
          vedge->vnormal[j] = (REAL) strtod(stringptr, &stringptr);
        }
        if (mesh_dim == 2) {
          vedge->vnormal[2] = 0.0;
        }
      } else {
        vedge->vnormal[0] = 0.0;
        vedge->vnormal[1] = 0.0;
        vedge->vnormal[2] = 0.0;
      }
    }
    fclose(infile);
  }

  return true;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// save_nodes()    Save points to a .node file.                              //
//                                                                           //
// 'filename' is a string containing the file name without suffix.           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenio::save_nodes(const char* filename)
{
  FILE *fout;
  char outnodefilename[FILENAMESIZE];
  char outmtrfilename[FILENAMESIZE];
  int i, j;

  sprintf(outnodefilename, "%s.node", filename);
  printf("Saving nodes to %s\n", outnodefilename);
  fout = fopen(outnodefilename, "w");
  fprintf(fout, "%d  %d  %d  %d\n", numberofpoints, mesh_dim,
          numberofpointattributes, pointmarkerlist != NULL ? 1 : 0);
  for (i = 0; i < numberofpoints; i++) {
    if (mesh_dim == 2) {
      fprintf(fout, "%d  %.16g  %.16g", i + firstnumber, pointlist[i * 3],
              pointlist[i * 3 + 1]);
    } else {
      fprintf(fout, "%d  %.16g  %.16g  %.16g", i + firstnumber,
              pointlist[i * 3], pointlist[i * 3 + 1], pointlist[i * 3 + 2]);
    }
    for (j = 0; j < numberofpointattributes; j++) {
      fprintf(fout, "  %.16g", 
              pointattributelist[i * numberofpointattributes + j]);
    }
    if (pointmarkerlist != NULL) {
      fprintf(fout, "  %d", pointmarkerlist[i]);
    }
    fprintf(fout, "\n");
  }
  fclose(fout);

  // If the point metrics exist, output them to a .mtr file.
  if ((numberofpointmtrs > 0) && (pointmtrlist != (REAL *) NULL)) {
    sprintf(outmtrfilename, "%s.mtr", filename);
    printf("Saving metrics to %s\n", outmtrfilename);
    fout = fopen(outmtrfilename, "w");
    fprintf(fout, "%d  %d\n", numberofpoints, numberofpointmtrs);
    for (i = 0; i < numberofpoints; i++) {
      for (j = 0; j < numberofpointmtrs; j++) {
        fprintf(fout, "%.16g ", pointmtrlist[i * numberofpointmtrs + j]);
      }
      fprintf(fout, "\n");
    }
    fclose(fout);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// save_elements()    Save elements to a .ele file.                          //
//                                                                           //
// 'filename' is a string containing the file name without suffix.           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenio::save_elements(const char* filename)
{
  FILE *fout;
  char outelefilename[FILENAMESIZE];
  int i, j;

  sprintf(outelefilename, "%s.ele", filename);
  printf("Saving elements to %s\n", outelefilename);
  fout = fopen(outelefilename, "w");
  if (mesh_dim == 3) {
    fprintf(fout, "%d  %d  %d\n", numberoftetrahedra, numberofcorners,
            numberoftetrahedronattributes);
    for (i = 0; i < numberoftetrahedra; i++) {
      fprintf(fout, "%d", i + firstnumber);
      for (j = 0; j < numberofcorners; j++) {
        fprintf(fout, "  %5d", tetrahedronlist[i * numberofcorners + j]);
      }
      for (j = 0; j < numberoftetrahedronattributes; j++) {
        fprintf(fout, "  %g",
          tetrahedronattributelist[i * numberoftetrahedronattributes + j]);
      }
      fprintf(fout, "\n");
    }
  } else {
    // Save a two-dimensional mesh.
    fprintf(fout, "%d  %d  %d\n", numberoftrifaces,3,trifacemarkerlist ? 1:0);
    for (i = 0; i < numberoftrifaces; i++) {
      fprintf(fout, "%d", i + firstnumber);
      for (j = 0; j < 3; j++) {
        fprintf(fout, "  %5d", trifacelist[i * 3 + j]);
      }
      if (trifacemarkerlist != NULL) {
        fprintf(fout, "  %d", trifacemarkerlist[i]);
      }
      fprintf(fout, "\n");
    }
  }

  fclose(fout);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// save_faces()    Save faces to a .face file.                               //
//                                                                           //
// 'filename' is a string containing the file name without suffix.           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenio::save_faces(const char* filename)
{
  FILE *fout;
  char outfacefilename[FILENAMESIZE];
  int i;

  sprintf(outfacefilename, "%s.face", filename);
  printf("Saving faces to %s\n", outfacefilename);
  fout = fopen(outfacefilename, "w");
  fprintf(fout, "%d  %d\n", numberoftrifaces, 
          trifacemarkerlist != NULL ? 1 : 0);
  for (i = 0; i < numberoftrifaces; i++) {
    fprintf(fout, "%d  %5d  %5d  %5d", i + firstnumber, trifacelist[i * 3],
            trifacelist[i * 3 + 1], trifacelist[i * 3 + 2]);
    if (trifacemarkerlist != NULL) {
      fprintf(fout, "  %d", trifacemarkerlist[i]);
    }
    fprintf(fout, "\n");
  }

  fclose(fout);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// save_edges()    Save egdes to a .edge file.                               //
//                                                                           //
// 'filename' is a string containing the file name without suffix.           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenio::save_edges(const char* filename)
{
  FILE *fout;
  char outedgefilename[FILENAMESIZE];
  int i;

  sprintf(outedgefilename, "%s.edge", filename);
  printf("Saving edges to %s\n", outedgefilename);
  fout = fopen(outedgefilename, "w");
  fprintf(fout, "%d  %d\n", numberofedges, edgemarkerlist != NULL ? 1 : 0);
  for (i = 0; i < numberofedges; i++) {
    fprintf(fout, "%d  %4d  %4d", i + firstnumber, edgelist[i * 2],
            edgelist[i * 2 + 1]);
    if (edgemarkerlist != NULL) {
      fprintf(fout, "  %d", edgemarkerlist[i]);
    }
    fprintf(fout, "\n");
  }

  fclose(fout);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// save_neighbors()    Save egdes to a .neigh file.                          //
//                                                                           //
// 'filename' is a string containing the file name without suffix.           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenio::save_neighbors(const char* filename)
{
  FILE *fout;
  char outneighborfilename[FILENAMESIZE];
  int i;

  sprintf(outneighborfilename, "%s.neigh", filename);
  printf("Saving neighbors to %s\n", outneighborfilename);
  fout = fopen(outneighborfilename, "w");
  fprintf(fout, "%d  %d\n", numberoftetrahedra, mesh_dim + 1);
  for (i = 0; i < numberoftetrahedra; i++) {
    if (mesh_dim == 2) {
      fprintf(fout, "%d  %5d  %5d  %5d", i + firstnumber,  neighborlist[i * 3],
              neighborlist[i * 3 + 1], neighborlist[i * 3 + 2]);
    } else {
      fprintf(fout, "%d  %5d  %5d  %5d  %5d", i + firstnumber,
              neighborlist[i * 4], neighborlist[i * 4 + 1],
              neighborlist[i * 4 + 2], neighborlist[i * 4 + 3]);
    }
    fprintf(fout, "\n");
  }

  fclose(fout);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// save_poly()    Save segments or facets to a .poly file.                   //
//                                                                           //
// 'filename' is a string containing the file name without suffix.  It only  //
// save the facets, holes and regions.  The nodes are saved in a .node file  //
// by routine save_nodes().                                                  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenio::save_poly(const char* filename)
{
  FILE *fout;
  facet *f;
  polygon *p;
  char outpolyfilename[FILENAMESIZE];
  int i, j, k;

  sprintf(outpolyfilename, "%s.poly", filename);
  printf("Saving poly to %s\n", outpolyfilename);
  fout = fopen(outpolyfilename, "w");

  // The zero indicates that the vertices are in a separate .node file.
  //   Followed by number of dimensions, number of vertex attributes,
  //   and number of boundary markers (zero or one).
  fprintf(fout, "%d  %d  %d  %d\n", 0, mesh_dim, numberofpointattributes,
          pointmarkerlist != NULL ? 1 : 0);

  // Save segments or facets.
  if (mesh_dim == 2) {
    // Number of segments, number of boundary markers (zero or one).
    fprintf(fout, "%d  %d\n", numberofedges, edgemarkerlist != NULL ? 1 : 0);
    for (i = 0; i < numberofedges; i++) {
      fprintf(fout, "%d  %4d  %4d", i + firstnumber, edgelist[i * 2],
              edgelist[i * 2 + 1]);
      if (edgemarkerlist != NULL) {
        fprintf(fout, "  %d", edgemarkerlist[i]);
      }
      fprintf(fout, "\n");
    }
  } else {
    // Number of facets, number of boundary markers (zero or one).
    fprintf(fout, "%d  %d\n", numberoffacets, facetmarkerlist != NULL ? 1 : 0);
    for (i = 0; i < numberoffacets; i++) {
      f = &(facetlist[i]);
      fprintf(fout, "%d  %d  %d  # %d\n", f->numberofpolygons,f->numberofholes,
            facetmarkerlist != NULL ? facetmarkerlist[i] : 0, i + firstnumber);
      // Output polygons of this facet.
      for (j = 0; j < f->numberofpolygons; j++) {
        p = &(f->polygonlist[j]);
        fprintf(fout, "%d  ", p->numberofvertices);
        for (k = 0; k < p->numberofvertices; k++) {
          if (((k + 1) % 10) == 0) {
            fprintf(fout, "\n  ");
          }
          fprintf(fout, "  %d", p->vertexlist[k]);
        }
        fprintf(fout, "\n");
      }
      // Output holes of this facet.
      for (j = 0; j < f->numberofholes; j++) {
        fprintf(fout, "%d  %.12g  %.12g  %.12g\n", j + firstnumber,
           f->holelist[j * 3], f->holelist[j * 3 + 1], f->holelist[j * 3 + 2]);
      }
    }
  }

  // Save holes.
  fprintf(fout, "%d\n", numberofholes);
  for (i = 0; i < numberofholes; i++) {
    // Output x, y coordinates.
    fprintf(fout, "%d  %.12g  %.12g", i + firstnumber, holelist[i * mesh_dim],
            holelist[i * mesh_dim + 1]);
    if (mesh_dim == 3) {
      // Output z coordinate.
      fprintf(fout, "  %.12g", holelist[i * mesh_dim + 2]);
    }
    fprintf(fout, "\n");
  }

  // Save regions.
  fprintf(fout, "%d\n", numberofregions);
  for (i = 0; i < numberofregions; i++) {
    if (mesh_dim == 2) {
      // Output the index, x, y coordinates, attribute (region number)
      //   and maximum area constraint (maybe -1).
      fprintf(fout, "%d  %.12g  %.12g  %.12g  %.12g\n", i + firstnumber,
              regionlist[i * 4], regionlist[i * 4 + 1],
              regionlist[i * 4 + 2], regionlist[i * 4 + 3]);
    } else {
      // Output the index, x, y, z coordinates, attribute (region number)
      //   and maximum volume constraint (maybe -1).
      fprintf(fout, "%d  %.12g  %.12g  %.12g  %.12g  %.12g\n", i + firstnumber,
              regionlist[i * 5], regionlist[i * 5 + 1],
              regionlist[i * 5 + 2], regionlist[i * 5 + 3],
              regionlist[i * 5 + 4]);
    }
  }

  fclose(fout);  
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// readline()   Read a nonempty line from a file.                            //
//                                                                           //
// A line is considered "nonempty" if it contains something more than white  //
// spaces.  If a line is considered empty, it will be dropped and the next   //
// line will be read, this process ends until reaching the end-of-file or a  //
// non-empty line.  Return NULL if it is the end-of-file, otherwise, return  //
// a pointer to the first non-whitespace character of the line.              //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

char* tetgenio::readline(char *string, FILE *infile, int *linenumber)
{
  char *result;

  // Search for a non-empty line.
  do {
    result = fgets(string, INPUTLINESIZE - 1, infile);
    if (linenumber) (*linenumber)++;
    if (result == (char *) NULL) {
      return (char *) NULL;
    }
    // Skip white spaces.
    while ((*result == ' ') || (*result == '\t')) result++;
    // If it's end of line, read another line and try again.
  } while (*result == '\0');
  return result;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// findnextfield()   Find the next field of a string.                        //
//                                                                           //
// Jumps past the current field by searching for whitespace or a comma, then //
// jumps past the whitespace or the comma to find the next field.            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

char* tetgenio::findnextfield(char *string)
{
  char *result;

  result = string;
  // Skip the current field.  Stop upon reaching whitespace or a comma.
  while ((*result != '\0') && (*result != ' ') &&  (*result != '\t') && 
         (*result != ',') && (*result != ';')) {
    result++;
  }
  // Now skip the whitespace or the comma, stop at anything else that looks
  //   like a character, or the end of a line. 
  while ((*result == ' ') || (*result == '\t') || (*result == ',') ||
         (*result == ';')) {
    result++;
  }
  return result;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// readnumberline()   Read a nonempty number line from a file.               //
//                                                                           //
// A line is considered "nonempty" if it contains something that looks like  //
// a number.  Comments (prefaced by `#') are ignored.                        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

char* tetgenio::readnumberline(char *string, FILE *infile, 
  const char *infilename)
{
  char *result;

  // Search for something that looks like a number.
  do {
    result = fgets(string, INPUTLINESIZE, infile);
    if (result == (char *) NULL) {
      if (infilename != (char *) NULL) {
        printf("  Error:  Unexpected end of file in %s.\n", infilename);
        terminatetetgen(1);
      }
      return result;
    }
    // Skip anything that doesn't look like a number, a comment, 
    //   or the end of a line. 
    while ((*result != '\0') && (*result != '#')
           && (*result != '.') && (*result != '+') && (*result != '-')
           && ((*result < '0') || (*result > '9'))) {
      result++;
    }
    // If it's a comment or end of line, read another line and try again.
  } while ((*result == '#') || (*result == '\0'));
  return result;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// findnextnumber()   Find the next field of a number string.                //
//                                                                           //
// Jumps past the current field by searching for whitespace or a comma, then //
// jumps past the whitespace or the comma to find the next field that looks  //
// like a number.                                                            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

char* tetgenio::findnextnumber(char *string)
{
  char *result;

  result = string;
  // Skip the current field.  Stop upon reaching whitespace or a comma.
  while ((*result != '\0') && (*result != '#') && (*result != ' ') && 
         (*result != '\t') && (*result != ',')) {
    result++;
  }
  // Now skip the whitespace and anything else that doesn't look like a
  //   number, a comment, or the end of a line. 
  while ((*result != '\0') && (*result != '#')
         && (*result != '.') && (*result != '+') && (*result != '-')
         && ((*result < '0') || (*result > '9'))) {
    result++;
  }
  // Check for a comment (prefixed with `#').
  if (*result == '#') {
    *result = '\0';
  }
  return result;
}

#endif // #ifndef tetgenioCXX