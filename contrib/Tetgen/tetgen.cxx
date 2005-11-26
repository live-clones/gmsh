///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// TetGen                                                                    //
//                                                                           //
// A Quality Tetrahedral Mesh Generator and 3D Delaunay Triangulator         //
//                                                                           //
// Version 1.3.4                                                             //
// June 13, 2005                                                             //
//                                                                           //
// Copyright 2002, 2004, 2005                                                //
// Hang Si                                                                   //
// Rathausstr. 9, 10178 Berlin, Germany                                      //
// si@wias-berlin.de                                                         //
//                                                                           //
// You can obtain TetGen via internet: http://tetgen.berlios.de.  It may be  //
//   freely copied, modified, and redistributed under the copyright notices  //
//   given in the file LICENSE.                                              //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// tetgen.cxx                                                                //
//                                                                           //
// The C++ implementation file of the TetGen library.                        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "tetgen.h"

//
// Begin of class 'tetgenio' implementation
//

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

  pointlist = (REAL *) NULL;
  pointattributelist = (REAL *) NULL;
  addpointlist = (REAL *) NULL;
  pointmarkerlist = (int *) NULL;
  numberofpoints = 0;
  numberofpointattributes = 0;
  numberofaddpoints = 0;

  tetrahedronlist = (int *) NULL;
  tetrahedronattributelist = (REAL *) NULL;
  tetrahedronvolumelist = (REAL *) NULL;
  neighborlist = (int *) NULL;
  numberoftetrahedra = 0;
  numberofcorners = 4;                   // Default is 4 nodes per element.
  numberoftetrahedronattributes = 0;

  trifacelist = (int *) NULL;
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

  nodeconstraintlist = (REAL *) NULL;
  numberofnodeconstraints = 0;

  pbcgrouplist = (pbcgroup *) NULL;
  numberofpbcgroups = 0;
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
  if (addpointlist != (REAL *) NULL) {
    delete [] addpointlist;
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
  if (nodeconstraintlist != (REAL *) NULL) {
    delete [] nodeconstraintlist;
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

bool tetgenio::load_node_call(FILE* infile, int markers, char* infilename)
{
  char inputline[INPUTLINESIZE];
  char *stringptr;
  REAL x, y, z, attrib;
  int firstnode, currentmarker;
  int index, attribindex;
  int i, j;

  // Initialize 'pointlist', 'pointattributelist', and 'pointmarkerlist'.
  pointlist = new REAL[numberofpoints * mesh_dim];
  if (pointlist == (REAL *) NULL) {
    printf("Error:  Out of memory.\n");
    exit(1);
  }
  if (numberofpointattributes > 0) {
    pointattributelist = new REAL[numberofpoints * numberofpointattributes];
    if (pointattributelist == (REAL *) NULL) {
      printf("Error:  Out of memory.\n");
      exit(1);
    }
  }
  if (markers) {
    pointmarkerlist = new int[numberofpoints];
    if (pointmarkerlist == (int *) NULL) {
      printf("Error:  Out of memory.\n");
      exit(1);
    }
  }

  // Read the point section.
  index = 0;
  attribindex = 0;
  for (i = 0; i < numberofpoints; i++) {
    stringptr = readnumberline(inputline, infile, infilename);
    if (i == 0) {
      firstnode = (int) strtol (stringptr, &stringptr, 0);
      if ((firstnode == 0) || (firstnode == 1)) {
        firstnumber = firstnode;
      }
    }
    stringptr = findnextnumber(stringptr);
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
    stringptr = findnextnumber(stringptr);
    if (*stringptr == '\0') {
      printf("Error:  Point %d has no z coordinate.\n", firstnumber + i);
      break;
    }
    z = (REAL) strtod(stringptr, &stringptr);
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

bool tetgenio::load_node(char* filename)
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
  // Read number of points, number of dimensions, number of point
  //   attributes, and number of boundary markers.
  stringptr = readnumberline(inputline, infile, innodefilename);
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

  if (mesh_dim != 3) {
    printf("Error:  load_node() only works for 3D points.\n");
    fclose(infile);
    return false;
  }
  if (numberofpoints < 4) {
    printf("File I/O error:  There should have at least 4 points.\n");
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
// load_addnodes()    Load a list of additional nodes into 'addpointlists'.  //
//                                                                           //
// 'filename' is the filename of the original inputfile without suffix. The  //
// additional nodes are found in file 'filename-a.node'.                     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenio::load_addnodes(char* filename)
{
  FILE *infile;
  char addnodefilename[FILENAMESIZE];
  char inputline[INPUTLINESIZE];
  char *stringptr;
  REAL x, y, z;
  int index;
  int i;

  // Additional nodes are saved in file "filename-a.node".
  strcpy(addnodefilename, filename);
  strcat(addnodefilename, "-a.node");
  infile = fopen(addnodefilename, "r");
  if (infile != (FILE *) NULL) {
    printf("Opening %s.\n", addnodefilename);
  } else {
    // Strange! However, it is not a fatal error.
    printf("Warning:  Can't opening %s. Skipped.\n", addnodefilename);
    numberofaddpoints = 0;
    return false;
  }

  // Read the number of additional points.
  stringptr = readnumberline(inputline, infile, addnodefilename);
  numberofaddpoints = (int) strtol (stringptr, &stringptr, 0);
  if (numberofaddpoints == 0) {
    // It looks this file contains no point.
    fclose(infile);
    return false; 
  }
  // Initialize 'addpointlist';
  addpointlist = new REAL[numberofaddpoints * mesh_dim];
  if (addpointlist == (REAL *) NULL) {
    printf("Error:  Out of memory.\n");
    exit(1);
  }

  // Read the list of additional points.
  index = 0;
  for (i = 0; i < numberofaddpoints; i++) {
    stringptr = readnumberline(inputline, infile, addnodefilename);
    stringptr = findnextnumber(stringptr);
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
    stringptr = findnextnumber(stringptr);
    if (*stringptr == '\0') {
      printf("Error:  Point %d has no z coordinate.\n", firstnumber + i);
      break;
    }
    z = (REAL) strtod(stringptr, &stringptr);
    addpointlist[index++] = x;
    addpointlist[index++] = y;
    addpointlist[index++] = z;
  }
  fclose(infile);

  if (i < numberofaddpoints) {
    // Failed to read to additional points due to some error.
    delete [] addpointlist;
    addpointlist = (REAL *) NULL;
    numberofaddpoints = 0;
    return false;
  }
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

bool tetgenio::load_pbc(char* filename)
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
  if (pbcgrouplist == (pbcgroup *) NULL) {
    printf("Error:  Out of memory.\n");
    exit(1);
  }

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
// This routine will be called both in load_poly() and load_tetmesh().       //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenio::load_var(char* filename)
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

  // Read the node constraint section. It is optional.
  stringptr = readnumberline(inputline, infile, NULL);
  if (stringptr != (char *) NULL && *stringptr != '\0') {
    numberofnodeconstraints = (int) strtol (stringptr, &stringptr, 0);
  } else {
    numberofnodeconstraints = 0;
  }
  if (numberofnodeconstraints > 0) {
    // Initialize 'nodeconstraintlist'.
    nodeconstraintlist = new REAL[numberofnodeconstraints * 2];
    index = 0;
    for (i = 0; i < numberofnodeconstraints; i++) {
      stringptr = readnumberline(inputline, infile, varfilename);
      stringptr = findnextnumber(stringptr);
      if (*stringptr == '\0') {
        printf("Error:  node constraint %d has no node index.\n",
               firstnumber + i);
        break;
      } else {
        nodeconstraintlist[index++] = (REAL) strtod(stringptr, &stringptr);
      }
      stringptr = findnextnumber(stringptr);
      if (*stringptr == '\0') {
        printf("Error:  node constraint %d has no edge length bound.\n",
               firstnumber + i);
        break;
      } else {
        nodeconstraintlist[index++] = (REAL) strtod(stringptr, &stringptr);
      }
    }
    if (i < numberofnodeconstraints) {
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
// load_poly()    Load a piecewise linear complex from a .poly or .smesh.    //
//                                                                           //
// 'filename' is the inputfile without suffix. The PLC is in 'filename.poly' //
// or 'filename.smesh', and possibly plus 'filename.node' (when the first    //
// line of the file starts with a zero).                                     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenio::load_poly(char* filename)
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

  if (mesh_dim != 3) {
    printf("Error:  load_poly() only works for 3D points.\n");
    fclose(infile);
    return false;
  }
  if (numberofpoints < 4) {
    printf("File I/O error:  There should have at least 4 points.\n");
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

  facet *f;
  polygon *p;

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
              printf("Error:  Missing %d endpoints of polygon %d in facet %d",
                     p->numberofvertices - k, j, i);
              break;
            }
          }
          p->vertexlist[k - 1] = (int) strtol (stringptr, &stringptr, 0);
        }
      } 
      if (j <= f->numberofpolygons) {
        // This must be caused by an error. However, there're j - 1 polygons
        //   have been read. Reset the 'f->numberofpolygon'.
        if (j == 1) {
          // This is the first polygon.
          delete [] f->polygonlist;
        }
        f->numberofpolygons = j - 1;
        // No hole will be read even it exists.
        f->numberofholes = 0;
        break;
      }
      // If this facet has holes pints defined, read them.
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

  // Read the region section.  The 'region' section is optional, if we don't
  //   reach the end-of-file, try read it in.
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

  // End of reading poly/smesh file.
  fclose(polyfile);

  // Try to read a .pbc file if it exists.
  load_pbc(filename);

  // Try to load a .cons file if it exists.
  load_var(filename);

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

bool tetgenio::load_off(char* filename)
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
          assert(pointlist != NULL);
        }
        if (nfaces > 0) {        
          numberoffacets = nfaces;
          facetlist = new tetgenio::facet[nfaces];
          assert(facetlist);
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
// reading and writing ,ply files are available from: http://www.cc.gatech.  //
// edu/projects/large_models/ply.html.  Except the header section, ply file  //
// format has exactly the same format for listing vertices and polygons as   //
// off file format.                                                          //
//                                                                           //
// On completion, 'pointlist' and 'facetlist' together return the polyhedron.//
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenio::load_ply(char* filename)
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
                assert(pointlist != NULL);
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
                assert(facetlist);
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

bool tetgenio::load_stl(char* filename)
{
  FILE *fp;
  tetgenmesh::list *plist;
  tetgenio::facet *f;
  tetgenio::polygon *p;
  char infilename[FILENAMESIZE];
  char buffer[INPUTLINESIZE];
  char *bufferp, *str;
  double *coord;
  int solid = 0;
  int nverts = 0, iverts = 0;
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
  plist = new tetgenmesh::list(sizeof(double) * 3, NULL, 1024); 

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
          coord = (double *) plist->append(NULL);
          for (i = 0; i < 3; i++) {
            bufferp = findnextnumber(bufferp);
            if (*bufferp == '\0') {
              printf("Syntax error reading vertex coords on line %d\n",
                   line_count);
              delete plist;
              fclose(fp);
              return false;
            }
            coord[i] = (REAL) strtod(bufferp, &bufferp);
          }
        }
      }
    }
  }
  fclose(fp);

  nverts = plist->len();
  // nverts should be an integer times 3 (every 3 vertices denote a face).
  if (nverts == 0 || (nverts % 3 != 0)) {
    printf("Error:  Wrong number of vertices in file %s.\n", infilename);
    delete plist;
    return false;
  }
  numberofpoints = nverts;
  pointlist = new REAL[nverts * 3];
  assert(pointlist != NULL);
  for (i = 0; i < nverts; i++) {
    coord = (double *) (* plist)[i];
    iverts = i * 3;
    pointlist[iverts] = (REAL) coord[0];
    pointlist[iverts + 1] = (REAL) coord[1];
    pointlist[iverts + 2] = (REAL) coord[2];
  }

  nfaces = (int) (nverts / 3);
  numberoffacets = nfaces;
  facetlist = new tetgenio::facet[nfaces];
  assert(facetlist != NULL);

  // Default use '1' as the array starting index.
  firstnumber = 1;
  iverts = firstnumber;
  for (i = 0; i < nfaces; i++) {
    f = &facetlist[i];
    init(f);      
    // In .stl format, each facet has one polygon, no hole.
    f->numberofpolygons = 1;
    f->polygonlist = new tetgenio::polygon[1];
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

  delete plist;
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
// This routine ONLY reads the sections containing vertices and triangles,   //
// other sections (such as tetrahedra, edges, ...) are ignored.              //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenio::load_medit(char* filename)
{
  FILE *fp;
  tetgenio::facet *f;
  tetgenio::polygon *p;
  char infilename[FILENAMESIZE];
  char buffer[INPUTLINESIZE];
  char *bufferp, *str;
  double *coord;
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
          assert(pointlist != NULL);
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
            coord[j] = (REAL) strtod(bufferp, &bufferp);
            bufferp = findnextnumber(bufferp);
          }
        }
        continue;
      }
    } 
    if (nfaces == 0) {
      // Find if it is the keyword "Triangles" or "Quadrilaterals".
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
          numberoffacets = nfaces;
          facetlist = new tetgenio::facet[nfaces];
          assert(facetlist != NULL);
          facetmarkerlist = new int[nfaces];
          assert(facetmarkerlist != NULL);
        }
        // Read the following list of faces.
        for (i = 0; i < nfaces; i++) {
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
          assert(p->vertexlist != NULL);
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
        continue;
      }
    }
    if (nverts > 0 && nfaces > 0) break; // Ignore other data.
  }

  // Close file
  fclose(fp);

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

bool tetgenio::load_plc(char* filename, int object)
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

bool tetgenio::load_tetmesh(char* filename)
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
  // Read number of points, number of dimensions, number of point
  //   attributes, and number of boundary markers.
  stringptr = readnumberline(inputline, infile, infilename);
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

  if (mesh_dim != 3) {
    printf("Error:  load_tetmesh() only works for 3D points.\n");
    fclose(infile);
    return false;
  }
  if (numberofpoints < 4) {
    printf("File I/O error:  Input should has at least 4 points.\n");
    fclose(infile);
    return false;
  }

  // Load the list of nodes.
  if (!load_node_call(infile, markers, infilename)) {
    fclose(infile);
    return false;
  }

  // Read the elements from a .ele file.
  infilename = inelefilename;
  printf("Opening %s.\n", infilename);
  infile = fopen(infilename, "r");
  if (infile != (FILE *) NULL) {
    // Read number of elements, number of corners (4 or 10), number of
    //   element attributes.
    stringptr = readnumberline(inputline, infile, infilename);
    numberoftetrahedra = (int) strtol (stringptr, &stringptr, 0);
    stringptr = findnextnumber(stringptr);
    if (*stringptr == '\0') {
      numberofcorners = 4;  // Default read 4 nodes per element.
    } else {
      numberofcorners = (int) strtol (stringptr, &stringptr, 0);
    }
    stringptr = findnextnumber(stringptr);
    if (*stringptr == '\0') {
      numberoftetrahedronattributes = 0; // Default no attribute.
    } else {
      numberoftetrahedronattributes = (int) strtol (stringptr, &stringptr, 0);
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
        exit(1);
      }
      // Allocate memory for output tetrahedron attributes if necessary.
      if (numberoftetrahedronattributes > 0) {
        tetrahedronattributelist = new REAL[numberoftetrahedra *
                                        numberoftetrahedronattributes];
        if (tetrahedronattributelist == (REAL *) NULL) {
          printf("Error:  Out of memory.\n");
          exit(1);
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
          exit(1);
        }
        corner = (int) strtol(stringptr, &stringptr, 0);
        if (corner < firstnumber || corner >= numberofpoints + firstnumber) {
          printf("Error:  Tetrahedron %d has an invalid vertex index.\n",
                 i + firstnumber);
          exit(1);
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
  
  // Read the hullfaces or subfaces from a .face file if it exists.
  infilename = infacefilename;
  infile = fopen(infilename, "r");
  if (infile != (FILE *) NULL) {
    printf("Opening %s.\n", infilename);
    // Read number of faces, boundary markers.
    stringptr = readnumberline(inputline, infile, infilename);
    numberoftrifaces = (int) strtol (stringptr, &stringptr, 0);
    stringptr = findnextnumber(stringptr);
    if (*stringptr == '\0') {
      markers = 0;  // Default there is no marker per face.
    } else {
      markers = (int) strtol (stringptr, &stringptr, 0);
    }
    if (numberoftrifaces > 0) {
      trifacelist = new int[numberoftrifaces * 3];
      if (trifacelist == (int *) NULL) {
        printf("Error:  Out of memory.\n");
        exit(1);
      }
      if (markers) {
        trifacemarkerlist = new int[numberoftrifaces * 3];
        if (trifacemarkerlist == (int *) NULL) {
          printf("Error:  Out of memory.\n");
          exit(1);
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
          exit(1);
        }
        corner = (int) strtol(stringptr, &stringptr, 0);
        if (corner < firstnumber || corner >= numberofpoints + firstnumber) {
          printf("Error:  Face %d has an invalid vertex index.\n",
                 i + firstnumber);
          exit(1);
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
        exit(1);
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
          exit(1);
        }
        corner = (int) strtol(stringptr, &stringptr, 0);
        if (corner < firstnumber || corner >= numberofpoints + firstnumber) {
          printf("Error:  Edge %d has an invalid vertex index.\n",
                 i + firstnumber);
          exit(1);
        }
        edgelist[index++] = corner;
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
        exit(1);
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

  // Try to read a .pbc file if it exists.
  load_pbc(filename);

  // Try to load a .cons file if it exists.
  load_var(filename);

  return true;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// save_nodes()    Save points to a .node file.                              //
//                                                                           //
// 'filename' is a string containing the file name without suffix.           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenio::save_nodes(char* filename)
{
  FILE *fout;
  char outnodefilename[FILENAMESIZE];
  int i, j;

  sprintf(outnodefilename, "%s.node", filename);
  printf("Saving nodes to %s\n", outnodefilename);
  fout = fopen(outnodefilename, "w");
  fprintf(fout, "%d  %d  %d  %d\n", numberofpoints, mesh_dim,
          numberofpointattributes, pointmarkerlist != NULL ? 1 : 0);
  for (i = 0; i < numberofpoints; i++) {
    if (mesh_dim == 2) {
      fprintf(fout, "%d  %.16g  %.16g", i + firstnumber, pointlist[i * 2],
              pointlist[i * 2 + 1]);
    } else {
      fprintf(fout, "%d  %.16g  %.16g  %.16g", i + firstnumber,
              pointlist[i * 3], pointlist[i * 3 + 1], pointlist[i * 3 + 2]);
    }
    for (j = 0; j < numberofpointattributes; j++) {
      fprintf(fout, "  %.16g", 
              pointattributelist[i * numberofpointattributes+j]);
    }
    if (pointmarkerlist != NULL) {
      fprintf(fout, "  %d", pointmarkerlist[i]);
    }
    fprintf(fout, "\n");
  }

  fclose(fout);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// save_elements()    Save elements to a .ele file.                          //
//                                                                           //
// 'filename' is a string containing the file name without suffix.           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenio::save_elements(char* filename)
{
  FILE *fout;
  char outelefilename[FILENAMESIZE];
  int i, j;

  sprintf(outelefilename, "%s.ele", filename);
  printf("Saving elements to %s\n", outelefilename);
  fout = fopen(outelefilename, "w");
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

  fclose(fout);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// save_faces()    Save faces to a .face file.                               //
//                                                                           //
// 'filename' is a string containing the file name without suffix.           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenio::save_faces(char* filename)
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
            trifacelist[i * 3 + 1], trifacelist[i * 3 +2]);
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

void tetgenio::save_edges(char* filename)
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

void tetgenio::save_neighbors(char* filename)
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

void tetgenio::save_poly(char* filename)
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

char* tetgenio::readnumberline(char *string, FILE *infile, char *infilename)
{
  char *result;

  // Search for something that looks like a number.
  do {
    result = fgets(string, INPUTLINESIZE, infile);
    if (result == (char *) NULL) {
      if (infilename != (char *) NULL) {
        printf("  Error:  Unexpected end of file in %s.\n", infilename);
        exit(1);
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

//
// End of class 'tetgenio' implementation
//

static REAL PI = 3.14159265358979323846264338327950288419716939937510582;

//
// Begin of class 'tetgenbehavior' implementation
//

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// tetgenbehavior()    Initialize veriables of 'tetgenbehavior'.             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

tetgenbehavior::tetgenbehavior()
{
  // Initialize command line switches.
  plc = 0;
  refine = 0;
  quality = 0; 
  minratio = 2.0;
  goodratio = 0.0;
  minangle = 20.0;
  goodangle = 0.0;
  varvolume = 0;
  fixedvolume = 0;
  maxvolume = -1.0;
  regionattrib = 0;
  insertaddpoints = 0;
  detectinter = 0;
  zeroindex = 0;
  facesout = 0;
  edgesout = 0;
  neighout = 0;
  meditview = 0;
  gidview = 0;
  geomview = 0;
  order = 1;
  nobound = 0;
  nonodewritten = 0;
  noelewritten = 0;
  nofacewritten = 0;
  noiterationnum = 0;
  nobisect = 0;
  noflip = 0;
  steiner = -1;
  dofullperturb = 0;
  dopermute = 0;
  srandseed = 1;
  nomerge = 0;
  docheck = 0;
  quiet = 0;
  verbose = 0;
  useshelles = 0;
  epsilon = 1.0e-8;
  object = NONE;
  // Initialize strings
  commandline[0] = '\0';
  infilename[0] = '\0';
  outfilename[0] = '\0';
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// versioninfo()    Print the version information of TetGen.                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenbehavior::versioninfo()
{
  printf("Version 1.3.4 (Released on June 13, 2005).\n");
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// syntax()    Print list of command line switches and exit the program.     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenbehavior::syntax()
{
  printf("  tetgen [-pq__a__AriMS__T__dzjo_fengGOBNEFICQVvh] input_file\n");
  printf("    -p  Tetrahedralizes a piecewise linear complex.\n");
  printf("    -q  Quality mesh generation. A minimum radius-edge ratio may\n");
  printf("        be specified (default 2.0).\n");
  printf("    -a  Applies a maximum tetrahedron volume constraint.\n");
  printf("    -A  Assigns attributes to identify tetrahedra in certain ");
  printf("regions.\n");
  printf("    -r  Reconstructs and Refines a previously generated mesh.\n");
  printf("    -i  Inserts a list of additional points into mesh.\n");
  printf("    -M  Does not merge coplanar facets.\n");
  printf("    -S  Specifies maximum number of added Steiner points.\n");
  printf("    -T  Set a tolerance for coplanar test (default 1e-8).\n");
  printf("    -d  Detect intersections of PLC facets.\n");
  printf("    -z  Numbers all output items starting from zero.\n");
  printf("    -o2 Generates second-order subparametric elements.\n");
  printf("    -f  Outputs faces (including non-boundary faces) to .face ");
  printf("file.\n");
  printf("    -e  Outputs subsegments to .edge file.\n");
  printf("    -n  Outputs tetrahedra neighbors to .neigh file.\n");
  printf("    -g  Outputs mesh to .mesh file for viewing by Medit.\n");
  printf("    -G  Outputs mesh to .msh file for viewing by Gid.\n");
  printf("    -O  Outputs mesh to .off file for viewing by Geomview.\n");
  printf("    -B  Suppresses output of boundary information.\n");
  printf("    -N  Suppresses output of .node file.\n");
  printf("    -E  Suppresses output of .ele file.\n");
  printf("    -F  Suppresses output of .face file.\n");
  printf("    -I  Suppresses mesh iteration numbers.\n");
  printf("    -C  Checks the consistency of the final mesh.\n");
  printf("    -Q  Quiet:  No terminal output except errors.\n");
  printf("    -V  Verbose:  Detailed information, more terminal output.\n");
  printf("    -v  Prints the version information.\n");
  printf("    -h  Help:  A brief instruction for using TetGen.\n");
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// usage()    Print a brief instruction for using TetGen.                    //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenbehavior::usage()
{
  printf("TetGen\n");
  printf("A Quality Tetrahedral Mesh Generator and 3D Delaunay ");
  printf("Triangulator\n");
  versioninfo();
  printf("\n");
  printf("Copyright 2002, 2004, 2005\n");
  printf("Hang Si\n");
  printf("Rathausstr. 9, 10178 Berlin, Germany\n");
  printf("si@wias-berlin.de\n");
  printf("\n");
  printf("What Can TetGen Do?\n");
  printf("\n");
  printf("  TetGen generates exact Delaunay tetrahedralizations, exact\n");
  printf("  constrained Delaunay tetrahedralizations, and quality ");
  printf("tetrahedral\n  meshes. The latter are nicely graded and whose ");
  printf("tetrahedra have\n  radius-edge ratio bounded, thus are suitable ");
  printf("for finite element and\n  finite volume analysis.\n"); 
  printf("\n");
  printf("Command Line Syntax:\n");
  printf("\n");
  printf("  Below is the command line syntax of TetGen with a list of ");
  printf("short\n");
  printf("  descriptions. Underscores indicate that numbers may optionally\n");
  printf("  follow certain switches.  Do not leave any space between a ");
  printf("switch\n");
  printf("  and its numeric parameter.  \'input_file\' contains input data\n");
  printf("  depending on the switches you supplied which may be a ");
  printf("  piecewise\n");
  printf("  linear complex or a list of nodes.  File formats and detailed\n");
  printf("  description of command line switches are found in user's ");
  printf("manual.\n");
  printf("\n");
  syntax();
  printf("\n");
  printf("Examples of How to Use TetGen:\n");
  printf("\n");
  printf("  \'tetgen object\' reads vertices from object.node, and writes ");
  printf("their\n  Delaunay tetrahedralization to object.1.node and ");
  printf("object.1.ele.\n");
  printf("\n");
  printf("  \'tetgen -p object\' reads a PLC from object.poly or object.");
  printf("smesh (and\n  possibly object.node) and writes its constrained ");
  printf("Delaunay\n  tetrahedralization to object.1.node, object.1.ele and ");
  printf("object.1.face.\n");
  printf("\n");
  printf("  \'tetgen -pq1.414a.1 object\' reads a PLC from object.poly or\n");
  printf("  object.smesh (and possibly object.node), generates a mesh ");
  printf("whose\n  tetrahedra have radius-edge ratio smaller than 1.414 and ");
  printf("have volume\n  of 0.1 or less, and writes the mesh to ");
  printf("object.1.node, object.1.ele\n  and object.1.face.\n");
  printf("\n");
  printf("Please send bugs/comments to Hang Si <si@wias-berlin.de>\n");
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// parse_commandline()    Read the command line, identify switches, and set  //
//                        up options and file names.                         //
//                                                                           //
// 'argc' and 'argv' are the same parameters passed to the function main()   //
// of a C/C++ program. They together represent the command line user invoked //
// from an environment in which TetGen is running.                           //
//                                                                           //
// When TetGen is invoked from an environment. 'argc' is nonzero, switches   //
// and input filename should be supplied as zero-terminated strings in       //
// argv[0] through argv[argc - 1] and argv[0] shall be the name used to      //
// invoke TetGen, i.e. "tetgen".  Switches are previously started with a     //
// dash '-' to identify them from the input filename.                        //
//                                                                           //
// When TetGen is called from within another program. 'argc' is set to zero. //
// switches are given in one zero-terminated string (no previous dash is     //
// required.), and 'argv' is a pointer points to this string.  No input      //
// filename is required (usually the input data has been directly created by //
// user in the 'tetgenio' structure).  A default filename 'tetgen-tmpfile'   //
// will be created for debugging output purpose.                             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenbehavior::parse_commandline(int argc, char **argv)
{
  int startindex;
  int increment;
  int meshnumber;
  int i, j, k;
  char workstring[1024];

  // First determine the input style of the switches.
  if (argc == 0) {
    startindex = 0;                    // Switches are given without a dash.
    argc = 1;                    // For running the following for-loop once.
    commandline[0] = '\0';
  } else {
    startindex = 1;
    strcpy(commandline, argv[0]);
    strcat(commandline, " ");
  }
  
  for (i = startindex; i < argc; i++) {
    // Remember the command line switches.
    strcat(commandline, argv[i]);
    strcat(commandline, " ");
    if (startindex == 1) {
      // Is this string a filename?
      if (argv[i][0] != '-') {
        strncpy(infilename, argv[i], 1024 - 1);
        infilename[1024 - 1] = '\0';
        // Go to the next string directly.
        continue;                     
      }
    }
    // Parse the individual switch from the string.
    for (j = startindex; argv[i][j] != '\0'; j++) {
      if (argv[i][j] == 'p') {
        plc = 1;
      } else if (argv[i][j] == 'r') {
        refine = 1;
      } else if (argv[i][j] == 'q') {
        quality = 1;
        if (((argv[i][j + 1] >= '0') && (argv[i][j + 1] <= '9')) ||
            (argv[i][j + 1] == '.')) {
          k = 0;
          while (((argv[i][j + 1] >= '0') && (argv[i][j + 1] <= '9')) ||
                 (argv[i][j + 1] == '.')) {
            j++;
            workstring[k] = argv[i][j];
            k++;
          }
          workstring[k] = '\0';
          minratio = (REAL) strtod(workstring, (char **) NULL);
        } 
      } else if (argv[i][j] == 'a') {
        quality = 1;
        if (((argv[i][j + 1] >= '0') && (argv[i][j + 1] <= '9')) ||
            (argv[i][j + 1] == '.')) {
          fixedvolume = 1;
          k = 0;
          while (((argv[i][j + 1] >= '0') && (argv[i][j + 1] <= '9')) ||
                 (argv[i][j + 1] == '.') || (argv[i][j + 1] == 'e') ||
                 (argv[i][j + 1] == '-') || (argv[i][j + 1] == '+')) {
            j++;
            workstring[k] = argv[i][j];
            k++;
          }
          workstring[k] = '\0';
          maxvolume = (REAL) strtod(workstring, (char **) NULL);
        } else {
          varvolume = 1;
        }
      } else if (argv[i][j] == 'A') {
        regionattrib = 1;
      } else if (argv[i][j] == 'i') {
        insertaddpoints = 1;
      } else if (argv[i][j] == 'd') {
        detectinter = 1;
      } else if (argv[i][j] == 'z') {
        zeroindex = 1;
      } else if (argv[i][j] == 'f') {
        facesout = 1;
      } else if (argv[i][j] == 'e') {
        edgesout = 1;
      } else if (argv[i][j] == 'n') {
        neighout = 1;
      } else if (argv[i][j] == 'g') {
        meditview = 1;
      } else if (argv[i][j] == 'G') {
        gidview = 1;
      } else if (argv[i][j] == 'O') {
        geomview = 1;
      } else if (argv[i][j] == 'B') {
        nobound = 1;
      } else if (argv[i][j] == 'N') {
        nonodewritten = 1;
      } else if (argv[i][j] == 'E') {
        noelewritten = 1;
      } else if (argv[i][j] == 'F') {
        nofacewritten = 1;
      } else if (argv[i][j] == 'I') {
        noiterationnum = 1;
      } else if (argv[i][j] == 'o') {
        if (argv[i][j + 1] == '2') {
          j++;
          order = 2;
        }
      } else if (argv[i][j] == 'Y') {
        noflip = 1; // nobisect++;
      } else if (argv[i][j] == 'S') {
        if (((argv[i][j + 1] >= '0') && (argv[i][j + 1] <= '9')) ||
            (argv[i][j + 1] == '.')) {
          k = 0;
          while (((argv[i][j + 1] >= '0') && (argv[i][j + 1] <= '9')) ||
                 (argv[i][j + 1] == '.') || (argv[i][j + 1] == 'e') ||
                 (argv[i][j + 1] == '-') || (argv[i][j + 1] == '+')) {
            j++;
            workstring[k] = argv[i][j];
            k++;
          }
          workstring[k] = '\0';
          steiner = (int) strtol(workstring, (char **) NULL, 0);
        } 
      } else if (argv[i][j] == 'P') {
        dofullperturb = 1;
        /*
        dopermute = 1;
        if (((argv[i][j + 1] >= '0') && (argv[i][j + 1] <= '9')) ||
            (argv[i][j + 1] == '.')) {
          k = 0;
          while (((argv[i][j + 1] >= '0') && (argv[i][j + 1] <= '9')) ||
                 (argv[i][j + 1] == '.') || (argv[i][j + 1] == 'e') ||
                 (argv[i][j + 1] == '-') || (argv[i][j + 1] == '+')) {
            j++;
            workstring[k] = argv[i][j];
            k++;
          }
          workstring[k] = '\0';
          srandseed = (int) strtol(workstring, (char **) NULL, 0);
        }
        */ 
      } else if (argv[i][j] == 'M') {
        nomerge = 1;
      } else if (argv[i][j] == 'T') {
        if (((argv[i][j + 1] >= '0') && (argv[i][j + 1] <= '9')) ||
            (argv[i][j + 1] == '.')) {
          k = 0;
          while (((argv[i][j + 1] >= '0') && (argv[i][j + 1] <= '9')) ||
                 (argv[i][j + 1] == '.') || (argv[i][j + 1] == 'e') ||
                 (argv[i][j + 1] == '-') || (argv[i][j + 1] == '+')) {
            j++;
            workstring[k] = argv[i][j];
            k++;
          }
          workstring[k] = '\0';
          epsilon = (REAL) strtod(workstring, (char **) NULL);
        } 
      } else if (argv[i][j] == 'C') {
        docheck++;
      } else if (argv[i][j] == 'Q') {
        quiet = 1;
      } else if (argv[i][j] == 'V') {
        verbose++;
      } else if (argv[i][j] == 'v') {
        versioninfo();
        exit(0);
      } else if ((argv[i][j] == 'h') || (argv[i][j] == 'H') ||
                 (argv[i][j] == '?')) {
        usage();
        exit(0);
      } else {
        printf("Warning:  Unknown switch -%c.\n", argv[i][j]);
      }
    }
  }

  if (startindex == 0) {
    // Set a temporary filename for debugging output.
    strcpy(infilename, "tetgen-tmpfile");
  } else {
    if (infilename[0] == '\0') {
      // No input file name. Print the syntax and exit.
      syntax();
      exit(0);
    }
    // Recognize the object from file extension if it is available.
    if (!strcmp(&infilename[strlen(infilename) - 5], ".node")) {
      infilename[strlen(infilename) - 5] = '\0';
      object = NODES;
    } else if (!strcmp(&infilename[strlen(infilename) - 5], ".poly")) {
      infilename[strlen(infilename) - 5] = '\0';
      object = POLY;
      plc = 1;
    } else if (!strcmp(&infilename[strlen(infilename) - 6], ".smesh")) {
      infilename[strlen(infilename) - 6] = '\0';
      object = POLY;
      plc = 1;
    } else if (!strcmp(&infilename[strlen(infilename) - 4], ".off")) {
      infilename[strlen(infilename) - 4] = '\0';
      object = OFF;
      plc = 1;
    } else if (!strcmp(&infilename[strlen(infilename) - 4], ".ply")) {
      infilename[strlen(infilename) - 4] = '\0';
      object = PLY;
      plc = 1;
    } else if (!strcmp(&infilename[strlen(infilename) - 4], ".stl")) {
      infilename[strlen(infilename) - 4] = '\0';
      object = STL;
      plc = 1;
    } else if (!strcmp(&infilename[strlen(infilename) - 5], ".mesh")) {
      infilename[strlen(infilename) - 5] = '\0';
      object = MEDIT;
      plc = 1;
    } else if (!strcmp(&infilename[strlen(infilename) - 4], ".ele")) {
      infilename[strlen(infilename) - 4] = '\0';
      object = MESH;
      refine = 1;
    }
  }
  plc = plc || detectinter;
  useshelles = plc || refine || quality;
  goodratio = minratio;
  goodratio *= goodratio;

  // Detect improper combinations of switches.
  if (plc && refine) {
    printf("Error:  Switch -r cannot use together with -p.\n");
    return false;
  }
  if (refine && (plc || noiterationnum)) {
    printf("Error:  Switches %s cannot use together with -r.\n",
           "-p, -d, -c, and -I");
    return false;
  }
  if (detectinter && (quality || insertaddpoints || (order == 2) || neighout
      || docheck)) {
    printf("Error:  Switches %s cannot use together with -d.\n",
           "-q, -i, -o2, -n, and -C");
    return false;
  }

  // Be careful not to allocate space for element area constraints that 
  //   will never be assigned any value (other than the default -1.0).
  if (!refine && !plc) {
    varvolume = 0;
  }
  // Be careful not to add an extra attribute to each element unless the
  //   input supports it (PLC in, but not refining a preexisting mesh).
  if (refine || !plc) {
    regionattrib = 0;
  }
  // Calculate the goodangle for testing bad subfaces.
  goodangle = cos(minangle * PI / 180.0);
  goodangle *= goodangle;

  increment = 0;
  strcpy(workstring, infilename);
  j = 1;
  while (workstring[j] != '\0') {
    if ((workstring[j] == '.') && (workstring[j + 1] != '\0')) {
      increment = j + 1;
    }
    j++;
  }
  meshnumber = 0;
  if (increment > 0) {
    j = increment;
    do {
      if ((workstring[j] >= '0') && (workstring[j] <= '9')) {
        meshnumber = meshnumber * 10 + (int) (workstring[j] - '0');
      } else {
        increment = 0;
      }
      j++;
    } while (workstring[j] != '\0');
  }
  if (noiterationnum) {
    strcpy(outfilename, infilename);
  } else if (increment == 0) {
    strcpy(outfilename, infilename);
    strcat(outfilename, ".1");
  } else {
    workstring[increment] = '%';
    workstring[increment + 1] = 'd';
    workstring[increment + 2] = '\0';
    sprintf(outfilename, workstring, meshnumber + 1);
  }

  return true;
}

//
// End of class 'tetgenbehavior' implementation
//

//
// Begin of class 'tetgenmesh' implementation
//

//
// Begin of class 'list', 'memorypool' and 'link' implementation
//

// Following are predefined compare functions for primitive data types. 
//   These functions take two pointers of the corresponding date type,
//   perform the comparation. Return -1, 0 or 1 indicating the default
//   linear order of two operators.

// Compare two 'integers'.
int tetgenmesh::compare_2_ints(const void* x, const void* y) {
  if (* (int *) x < * (int *) y) {
    return -1;
  } else if (* (int *) x > * (int *) y) {
    return 1;
  } else {
    return 0;
  }
}

// Compare two 'longs'.  Note: in 64-bit machine the 'long' type is 64-bit
//   (8-byte) where the 'int' only 32-bit (4-byte).
int tetgenmesh::compare_2_longs(const void* x, const void* y) {
  if (* (long *) x < * (long *) y) {
    return -1;
  } else if (* (long *) x > * (long *) y) {
    return 1;
  } else {
    return 0;
  }
}

// Compare two 'unsigned longs'.
int tetgenmesh::compare_2_unsignedlongs(const void* x, const void* y) {
  if (* (unsigned long *) x < * (unsigned long *) y) {
    return -1;
  } else if (* (unsigned long *) x > * (unsigned long *) y) {
    return 1;
  } else {
    return 0;
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// set_compfunc()    Determine the size of primitive data types and set the  //
//                   corresponding predefined linear order functions.        //
//                                                                           //
// 'str' is a zero-end string indicating a primitive data type, like 'int',  //
// 'long' or 'unsigned long'.  Every string ending with a '*' is though as a //
// type of pointer and the type 'unsign long' is used for it.                //
//                                                                           //
// When the type of 'str' is determined, the size of this type (in byte) is  //
// returned in 'itbytes', and the pointer of corresponding predefined linear //
// order functions is returned in 'pcomp'.                                   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::set_compfunc(char* str, int* itbytes, compfunc* pcomp)
{
  // First figure out whether it is a pointer or not.
  if (str[strlen(str) - 1] == '*') {
    *itbytes = sizeof(unsigned long);
    *pcomp = &compare_2_unsignedlongs;
    return;
  }
  // Then determine other types.
  if (strcmp(str, "int") == 0) {
    *itbytes = sizeof(int);
    *pcomp = &compare_2_ints;
  } else if (strcmp(str, "long") == 0) {
    *itbytes = sizeof(long);
    *pcomp = &compare_2_longs;
  } else if (strcmp(str, "unsigned long") == 0) {
    *itbytes = sizeof(unsigned long);
    *pcomp = &compare_2_unsignedlongs;
  } else {
    // It is an unknown type.
    printf("Error in set_compfunc():  unknown type %s.\n", str);
    exit(1);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// listinit()    Initialize a list for storing a data type.                  //
//                                                                           //
// Determine the size of each item, set the maximum size allocated at onece, //
// set the expand size in case the list is full, and set the linear order    //
// function if it is provided (default is NULL).                             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::list::
listinit(int itbytes, compfunc pcomp, int mitems,int exsize)
{
  assert(itbytes > 0 && mitems > 0 && exsize > 0);

  itembytes = itbytes;
  comp = pcomp;
  maxitems = mitems;
  expandsize = exsize;
  base = (char *) malloc(maxitems * itembytes); 
  if (base == (char *) NULL) {
    printf("Error:  Out of memory.\n");
    exit(1);
  }
  items = 0;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// append()    Add a new item at the end of the list.                        //
//                                                                           //
// A new space at the end of this list will be allocated for storing the new //
// item. If the memory is not sufficient, reallocation will be performed. If //
// 'appitem' is not NULL, the contents of this pointer will be copied to the //
// new allocated space.  Returns the pointer to the new allocated space.     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void* tetgenmesh::list::append(void *appitem)
{
  // Do we have enough space?
  if (items == maxitems) {
    char* newbase = (char *) realloc(base, (maxitems + expandsize) * 
                                     itembytes);
    if (newbase == (char *) NULL) {
      printf("Error:  Out of memory.\n");
      exit(1);
    }
    base = newbase;
    maxitems += expandsize;
  }
  if (appitem != (void *) NULL) {
    memcpy(base + items * itembytes, appitem, itembytes);
  }
  items++;
  return (void *) (base + (items - 1) * itembytes);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// insert()    Insert an item before 'pos' (range from 0 to items - 1).      //
//                                                                           //
// A new space will be inserted at the position 'pos', that is, items lie    //
// after pos (including the item at pos) will be moved one space downwords.  //
// If 'insitem' is not NULL, its contents will be copied into the new        //
// inserted space. Return a pointer to the new inserted space.               //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void* tetgenmesh::list::insert(int pos, void* insitem)
{
  if (pos >= items) {
    return append(insitem);
  }
  // Do we have enough space.
  if (items == maxitems) {
    char* newbase = (char *) realloc(base, (maxitems + expandsize) *
                                     itembytes);
    if (newbase == (char *) NULL) {
      printf("Error:  Out of memory.\n");
      exit(1);
    }
    base = newbase;
    maxitems += expandsize;
  }
  // Do block move.
  memmove(base + (pos + 1) * itembytes,   // dest
          base + pos * itembytes,         // src
          (items - pos) * itembytes);     // size in bytes
  // Insert the item.
  if (insitem != (void *) NULL) {
    memcpy(base + pos * itembytes, insitem, itembytes);
  }
  items++;
  return (void *) (base + pos * itembytes);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// del()    Delete an item at 'pos' (range from 0 to items - 1).             //
//                                                                           //
// The space at 'pos' will be overlapped by other items, that is, items lie  //
// after pos will be moved one space upwords.                                //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::list::del(int pos)
{
  // If 'pos' is the last itemof the list, nothing need to do.
  if (pos >= 0 && pos < items - 1) {
    // Do block move.
    memmove(base + pos * itembytes,       // dest
            base + (pos + 1) * itembytes, // src
            (items - pos - 1) * itembytes);
  }
  if (items > 0) {
    items--;
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// hasitem()    Search in this list to find if 'checkitem' exists.           //
//                                                                           //
// This routine assumes that a linear order function has been set.  It loops //
// through the entire list, compares each item to 'checkitem'. If it exists, //
// return its position (between 0 to items - 1), otherwise, return -1.       //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

int tetgenmesh::list::hasitem(void* checkitem)
{
  int i;

  for (i = 0; i < items; i++) {
    if (comp != (compfunc) NULL) {
      if ((* comp)((void *)(base + i * itembytes), checkitem) == 0) {
        return i;
      }
    }
  }
  return -1;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// remove()    Remove an item (indicated by its pointer) from the list.      //
//                                                                           //
// If the list contains more than one copy of the pointer, only the first    //
// copy is removed.  The returned value is the index of the removed item.    //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

int  tetgenmesh::list::remove(void* remitem)
{
  int pos = hasitem(remitem);
  if (pos != -1) {
    del(pos);
  }
  return pos;
} 

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// sort()    Sort the items with respect to a linear order function.         //
//                                                                           //
// Uses QuickSort routines (qsort) of the standard C/C++ library (stdlib.h). //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::list::sort()
{
  qsort((void *) base, (size_t) items, (size_t) itembytes, comp);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// memorypool()   The constructors of memorypool.                            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

tetgenmesh::memorypool::memorypool()
{
  firstblock = nowblock = (void **) NULL;
  nextitem = (void *) NULL;
  deaditemstack = (void *) NULL;
  pathblock = (void **) NULL;
  pathitem = (void *) NULL;
  itemwordtype = POINTER;
  alignbytes = 0;
  itembytes = itemwords = 0;
  itemsperblock = 0;
  items = maxitems = 0l;
  unallocateditems = 0;
  pathitemsleft = 0;
}

tetgenmesh::memorypool::
memorypool(int bytecount, int itemcount, enum wordtype wtype, int alignment)
{
  poolinit(bytecount, itemcount, wtype, alignment);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// ~memorypool()   Free to the operating system all memory taken by a pool.  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

tetgenmesh::memorypool::~memorypool()
{
  while (firstblock != (void **) NULL) {
    nowblock = (void **) *(firstblock);
    free(firstblock);
    firstblock = nowblock;
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// poolinit()    Initialize a pool of memory for allocation of items.        //
//                                                                           //
// A `pool' is created whose records have size at least `bytecount'.  Items  //
// will be allocated in `itemcount'-item blocks.  Each item is assumed to be //
// a collection of words, and either pointers or floating-point values are   //
// assumed to be the "primary" word type.  (The "primary" word type is used  //
// to determine alignment of items.)  If `alignment' isn't zero, all items   //
// will be `alignment'-byte aligned in memory.  `alignment' must be either a //
// multiple or a factor of the primary word size;  powers of two are safe.   //
// `alignment' is normally used to create a few unused bits at the bottom of //
// each item's pointer, in which information may be stored.                  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::memorypool::
poolinit(int bytecount, int itemcount, enum wordtype wtype, int alignment)
{
  int wordsize;

  // Initialize values in the pool.
  itemwordtype = wtype;
  wordsize = (itemwordtype == POINTER) ? sizeof(void *) : sizeof(REAL);
  // Find the proper alignment, which must be at least as large as:
  //   - The parameter `alignment'.
  //   - The primary word type, to avoid unaligned accesses.
  //   - sizeof(void *), so the stack of dead items can be maintained
  //       without unaligned accesses.
  if (alignment > wordsize) {
    alignbytes = alignment;
  } else {
    alignbytes = wordsize;
  }
  if (sizeof(void *) > alignbytes) {
    alignbytes = sizeof(void *);
  }
  itemwords = ((bytecount + alignbytes - 1) /  alignbytes)
            * (alignbytes / wordsize);
  itembytes = itemwords * wordsize;
  itemsperblock = itemcount;

  // Allocate a block of items.  Space for `itemsperblock' items and one
  //   pointer (to point to the next block) are allocated, as well as space
  //   to ensure alignment of the items. 
  firstblock = (void **) malloc(itemsperblock * itembytes + sizeof(void *)
                                + alignbytes); 
  if (firstblock == (void **) NULL) {
    printf("Error:  Out of memory.\n");
    exit(1);
  }
  // Set the next block pointer to NULL.
  *(firstblock) = (void *) NULL;
  restart();
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// restart()   Deallocate all items in this pool.                            //
//                                                                           //
// The pool is returned to its starting state, except that no memory is      //
// freed to the operating system.  Rather, the previously allocated blocks   //
// are ready to be reused.                                                   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::memorypool::restart()
{
  unsigned long alignptr;

  items = 0;
  maxitems = 0;

  // Set the currently active block.
  nowblock = firstblock;
  // Find the first item in the pool.  Increment by the size of (void *).
  alignptr = (unsigned long) (nowblock + 1);
  // Align the item on an `alignbytes'-byte boundary.
  nextitem = (void *)
    (alignptr + (unsigned long) alignbytes -
     (alignptr % (unsigned long) alignbytes));
  // There are lots of unallocated items left in this block.
  unallocateditems = itemsperblock;
  // The stack of deallocated items is empty.
  deaditemstack = (void *) NULL;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// alloc()   Allocate space for an item.                                     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void* tetgenmesh::memorypool::alloc()
{
  void *newitem;
  void **newblock;
  unsigned long alignptr;

  // First check the linked list of dead items.  If the list is not 
  //   empty, allocate an item from the list rather than a fresh one.
  if (deaditemstack != (void *) NULL) {
    newitem = deaditemstack;                     // Take first item in list.
    deaditemstack = * (void **) deaditemstack;
  } else {
    // Check if there are any free items left in the current block.
    if (unallocateditems == 0) {
      // Check if another block must be allocated.
      if (*nowblock == (void *) NULL) {
        // Allocate a new block of items, pointed to by the previous block.
        newblock = (void **) malloc(itemsperblock * itembytes + sizeof(void *) 
                                    + alignbytes);
        if (newblock == (void **) NULL) {
          printf("Error:  Out of memory.\n");
          exit(1);
        }
        *nowblock = (void *) newblock;
        // The next block pointer is NULL.
        *newblock = (void *) NULL;
      }
      // Move to the new block.
      nowblock = (void **) *nowblock;
      // Find the first item in the block.
      //   Increment by the size of (void *).
      alignptr = (unsigned long) (nowblock + 1);
      // Align the item on an `alignbytes'-byte boundary.
      nextitem = (void *)
        (alignptr + (unsigned long) alignbytes -
         (alignptr % (unsigned long) alignbytes));
      // There are lots of unallocated items left in this block.
      unallocateditems = itemsperblock;
    }
    // Allocate a new item.
    newitem = nextitem;
    // Advance `nextitem' pointer to next free item in block.
    if (itemwordtype == POINTER) {
      nextitem = (void *) ((void **) nextitem + itemwords);
    } else {
      nextitem = (void *) ((REAL *) nextitem + itemwords);
    }
    unallocateditems--;
    maxitems++;
  }
  items++;
  return newitem;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// dealloc()   Deallocate space for an item.                                 //
//                                                                           //
// The deallocated space is stored in a queue for later reuse.               //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::memorypool::dealloc(void *dyingitem)
{
  // Push freshly killed item onto stack.
  *((void **) dyingitem) = deaditemstack;
  deaditemstack = dyingitem;
  items--;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// traversalinit()   Prepare to traverse the entire list of items.           //
//                                                                           //
// This routine is used in conjunction with traverse().                      //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::memorypool::traversalinit()
{
  unsigned long alignptr;

  // Begin the traversal in the first block.
  pathblock = firstblock;
  // Find the first item in the block.  Increment by the size of (void *).
  alignptr = (unsigned long) (pathblock + 1);
  // Align with item on an `alignbytes'-byte boundary.
  pathitem = (void *)
    (alignptr + (unsigned long) alignbytes -
     (alignptr % (unsigned long) alignbytes));
  // Set the number of items left in the current block.
  pathitemsleft = itemsperblock;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// traverse()   Find the next item in the list.                              //
//                                                                           //
// This routine is used in conjunction with traversalinit().  Be forewarned  //
// that this routine successively returns all items in the list, including   //
// deallocated ones on the deaditemqueue. It's up to you to figure out which //
// ones are actually dead.  It can usually be done more space-efficiently by //
// a routine that knows something about the structure of the item.           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void* tetgenmesh::memorypool::traverse()
{
  void *newitem;
  unsigned long alignptr;

  // Stop upon exhausting the list of items.
  if (pathitem == nextitem) {
    return (void *) NULL;
  }
  // Check whether any untraversed items remain in the current block.
  if (pathitemsleft == 0) {
    // Find the next block.
    pathblock = (void **) *pathblock;
    // Find the first item in the block.  Increment by the size of (void *).
    alignptr = (unsigned long) (pathblock + 1);
    // Align with item on an `alignbytes'-byte boundary.
    pathitem = (void *)
      (alignptr + (unsigned long) alignbytes -
       (alignptr % (unsigned long) alignbytes));
    // Set the number of items left in the current block.
    pathitemsleft = itemsperblock;
  }
  newitem = pathitem;
  // Find the next item in the block.
  if (itemwordtype == POINTER) {
    pathitem = (void *) ((void **) pathitem + itemwords);
  } else {
    pathitem = (void *) ((REAL *) pathitem + itemwords);
  }
  pathitemsleft--;
  return newitem;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// linkinit()    Initialize a link for storing items.                        //
//                                                                           //
// The input parameters are the size of each item, a pointer of a linear     //
// order function and the number of items allocating in one memory bulk.     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::link::linkinit(int bytecount, compfunc pcomp, int itemcount)
{
  assert(bytecount > 0 && itemcount > 0);  

  // Remember the real size of each item.
  linkitembytes = bytecount;
  // Set the linear order function for this link.
  comp = pcomp;

  // Call the constructor of 'memorypool' to initialize its variables.
  //   like: itembytes, itemwords, items, ... Each node has size
  //   bytecount + 2 * sizeof(void **), and total 'itemcount + 2' (because
  //   link has additional two nodes 'head' and 'tail').
  poolinit(bytecount + 2 * sizeof(void **), itemcount + 2, POINTER, 0);
  
  // Initial state of this link.
  head = (void **) alloc();
  tail = (void **) alloc();
  *head = (void *) tail;
  *(head + 1) = NULL;
  *tail = NULL;
  *(tail + 1) = (void *) head;
  nextlinkitem = *head;
  curpos = 1;
  linkitems = 0;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// clear()   Deallocate all nodes in this link.                              //
//                                                                           //
// The link is returned to its starting state, except that no memory is      //
// freed to the operating system.  Rather, the previously allocated blocks   //
// are ready to be reused.                                                   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::link::clear()
{
  // Reset the pool.
  restart();

  // Initial state of this link.
  head = (void **) alloc();
  tail = (void **) alloc();
  *head = (void *) tail;
  *(head + 1) = NULL;
  *tail = NULL;
  *(tail + 1) = (void *) head;
  nextlinkitem = *head;
  curpos = 1;
  linkitems = 0;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// move()    Causes 'nextlinkitem' to traverse the specified number of nodes,//
//           updates 'curpos' to be the node to which 'nextlinkitem' points. //
//                                                                           //
// 'numberofnodes' is a number indicating how many nodes need be traversed   //
// (not counter the current node) need be traversed. It may be positive(move //
// forward) or negative (move backward).  Return TRUE if it is successful.   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenmesh::link::move(int numberofnodes)
{
  void **nownode;
  int i;

  nownode = (void **) nextlinkitem;
  if (numberofnodes > 0) {
    // Move forward.
    i = 0;
    while ((i < numberofnodes) && *nownode) {
      nownode = (void **) *nownode;
      i++;
    }
    if (*nownode == NULL) return false;
    nextlinkitem = (void *) nownode;
    curpos += numberofnodes;
  } else if (numberofnodes < 0) {
    // Move backward.
    i = 0;
    numberofnodes = -numberofnodes;
    while ((i < numberofnodes) && *(nownode + 1)) {
      nownode = (void **) *(nownode + 1);
      i++;
    }
    if (*(nownode + 1) == NULL) return false;
    nextlinkitem = (void *) nownode;
    curpos -= numberofnodes;
  }
  return true;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// locate()    Locates the node at the specified position.                   //
//                                                                           //
// The number 'pos' (between 1 and 'linkitems') indicates the location. This //
// routine first decides the shortest path traversing from 'curpos' to 'pos',//
// i.e., from head, tail or 'curpos'.   Routine 'move()' is called to really //
// traverse the link. If success, 'nextlinkitem' points to the node, 'curpos'//
// and 'pos' are equal. Otherwise, return FALSE.                             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenmesh::link::locate(int pos)
{
  int headdist, taildist, curdist;
  int abscurdist, mindist;

  if (pos < 1 || pos > linkitems) return false;

  headdist = pos - 1;
  taildist = linkitems - pos;
  curdist = pos - curpos;
  abscurdist = curdist >= 0 ? curdist : -curdist;

  if (headdist > taildist) {
    if (taildist > abscurdist) {
      mindist = curdist;
    } else {
      // taildist <= abs(curdist)
      mindist = -taildist;
      goend();
    }
  } else {
    // headdist <= taildist
    if (headdist > abscurdist) {
      mindist = curdist;
    } else {
      // headdist <= abs(curdist)
      mindist = headdist;
      rewind();
    }
  }

  return move(mindist);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// add()    Add a node at the end of this link.                              //
//                                                                           //
// A new node is appended to the end of the link.  If 'newitem' is not NULL, //
// its conents will be copied to the data slot of the new node. Returns the  //
// pointer to the newest added node.                                         //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void* tetgenmesh::link::add(void* newitem)
{
  void **newnode = tail;
  if (newitem != (void *) NULL) {
    memcpy((void *)(newnode + 2), newitem, linkitembytes);
  }
  tail = (void **) alloc();
  *tail = NULL;
  *newnode = (void*) tail;
  *(tail + 1) = (void*) newnode;
  linkitems++;
  return (void *)(newnode + 2);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// insert()    Inserts a node before the specified position.                 //
//                                                                           //
// 'pos' (between 1 and 'linkitems') indicates the inserting position.  This //
// routine inserts a new node before the node of 'pos'.  If 'newitem' is not //
// NULL,  its conents will be copied into the data slot of the new node.  If //
// 'pos' is larger than 'linkitems', it is equal as 'add()'.  A pointer to   //
// the newest inserted item is returned.                                     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void* tetgenmesh::link::insert(int pos, void* insitem)
{
  if (!locate(pos)) {
    return add(insitem);
  }

  void **nownode = (void **) nextlinkitem;

  // Insert a node before 'nownode'.
  void **newnode = (void **) alloc();
  if (insitem != (void *) NULL) {
    memcpy((void *)(newnode + 2), insitem, linkitembytes);
  }

  *(void **)(*(nownode + 1)) = (void *) newnode;
  *newnode = (void *) nownode;
  *(newnode + 1) = *(nownode + 1);
  *(nownode + 1) = (void *) newnode;

  linkitems++;

  nextlinkitem = (void *) newnode;
  return (void *)(newnode + 2);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// del()    Delete a node containing the given pointer.                      //
//                                                                           //
// Returns a pointer of the deleted data. If you try to delete a non-existed //
// node (e.g. link is empty or a wrong index is given) return NULL.          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void* tetgenmesh::link::del(void* delitem)
{
  void **deadnode = (void **) ((void **) delitem - 2);
  
  // now delete the nownode
  void **nextnode = (void **) *deadnode;
  void **prevnode = (void **) *(deadnode + 1);
  *prevnode = (void *) nextnode;
  *(nextnode + 1) = (void *) prevnode;

  dealloc((void *) deadnode);
  linkitems--;

  nextlinkitem = (void *) nextnode;
  return (void *)(deadnode + 2);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// del()    Delete a node at the specified position.                         //
//                                                                           //
// 'pos' between 1 and 'linkitems'.  Returns a pointer of the deleted data.  //
// If you try to delete a non-existed node (e.g. link is empty or a wrong    //
// index is given) return NULL.                                              //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void* tetgenmesh::link::del(int pos)
{
  if (!locate(pos) || (linkitems == 0)) {
    return (void *) NULL;
  }
  return del((void *) ((void **) nextlinkitem + 2));
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// getitem()    The link traversal routine.                                  //
//                                                                           //
// Returns the node to which 'nextlinkitem' points. Returns a 'NULL' if the  //
// end of the link is reaching.  Both 'nextlinkitem' and 'curpos' will be    //
// updated after this operation.                                             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void* tetgenmesh::link::getitem()
{
  if (nextlinkitem == (void *) tail) return NULL;
  void **nownode = (void **) nextlinkitem;
  nextlinkitem = *nownode;
  curpos += 1;
  return (void *)(nownode + 2);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// getnitem()    Returns the node at a specified position.                   //
//                                                                           //
// 'pos' between 1 and 'linkitems'. After this operation, 'nextlinkitem' and //
// 'curpos' will be updated to indicate this node.                           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void* tetgenmesh::link::getnitem(int pos)
{
  if (!locate(pos)) return NULL;
  return (void *)((void **) nextlinkitem + 2);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// hasitem()    Search in this link to find if 'checkitem' exists.           //
//                                                                           //
// If 'checkitem' exists, return its position (between 1 to 'linkitems'),    //
// otherwise, return -1. This routine requires the linear order function has //
// been set.                                                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

int tetgenmesh::link::hasitem(void* checkitem)
{
  void *pathitem;
  int count;

  rewind();
  pathitem = getitem();
  count = 0;
  while (pathitem) {
    count ++;
    if (comp) {
      if ((* comp)(pathitem, checkitem) == 0) {
        return count;
      }
    } 
    pathitem = getitem();
  }
  return -1;
}

//
// End of class 'list', 'memorypool' and 'link' implementation
//

//
// Begin of mesh manipulation primitives
//

//
// Begin of tables initialization.
//

// For enumerating three edges of a triangle.

int tetgenmesh::plus1mod3[3] = {1, 2, 0};
int tetgenmesh::minus1mod3[3] = {2, 0, 1};

// Table 've' takes an edge version as input, returns the next edge version
//   in the same edge ring.

int tetgenmesh::ve[6] = { 2, 5, 4, 1, 0, 3 };

// Tables 'vo', 'vd' and 'va' take an edge version, return the positions of
//   the origin, destination and apex in the triangle.

int tetgenmesh::vo[6] = { 0, 1, 1, 2, 2, 0 };
int tetgenmesh::vd[6] = { 1, 0, 2, 1, 0, 2 };
int tetgenmesh::va[6] = { 2, 2, 0, 0, 1, 1 };

// The following tables are for tetrahedron primitives (operate on trifaces).

// For 'org()', 'dest()' and 'apex()'.  Use 'loc' as the first index and
//   'ver' as the second index.

int tetgenmesh::locver2org[4][6]  = {
  0, 1, 1, 2, 2, 0,
  0, 3, 3, 1, 1, 0,
  1, 3, 3, 2, 2, 1,
  2, 3, 3, 0, 0, 2 
};
int tetgenmesh::locver2dest[4][6] = { 
  1, 0, 2, 1, 0, 2,
  3, 0, 1, 3, 0, 1,
  3, 1, 2, 3, 1, 2,
  3, 2, 0, 3, 2, 0
};
int tetgenmesh::locver2apex[4][6] = { 
  2, 2, 0, 0, 1, 1,
  1, 1, 0, 0, 3, 3,
  2, 2, 1, 1, 3, 3,
  0, 0, 2, 2, 3, 3
};

// For oppo() primitives, use 'loc' as the index.

int tetgenmesh::loc2oppo[4] = { 3, 2, 0, 1 };

// For fnext() primitive.  Use 'loc' as the first index and 'ver' as the
//   second index. Returns a new 'loc' and new 'ver' in an array. (It is
//   only valid for edge version equals one of {0, 2, 4}.)

int tetgenmesh::locver2nextf[4][6][2] = {
  { {1, 5}, {-1, -1}, {2, 5}, {-1, -1}, {3, 5}, {-1, -1} },
  { {3, 3}, {-1, -1}, {2, 1}, {-1, -1}, {0, 1}, {-1, -1} },
  { {1, 3}, {-1, -1}, {3, 1}, {-1, -1}, {0, 3}, {-1, -1} },
  { {2, 3}, {-1, -1}, {1, 1}, {-1, -1}, {0, 5}, {-1, -1} }
};

//
// End of tables initialization.
//

// Some macros for convenience

#define Div2  >> 1
#define Mod2  & 01

// NOTE: These bit operators should only be used in macros below.

// Get orient(Range from 0 to 2) from face version(Range from 0 to 5).

#define Orient(V)   ((V) Div2)

// Determine edge ring(0 or 1) from face version(Range from 0 to 5).

#define EdgeRing(V) ((V) Mod2)

//
// Begin of primitives for tetrahedra
// 

// Each tetrahedron contains four pointers to its neighboring tetrahedra,
//   with face indices.  To save memory, both information are kept in a
//   single pointer. To make this possible, all tetrahedra are aligned to
//   eight-byte boundaries, so that the last three bits of each pointer are
//   zeros. A face index (in the range 0 to 3) is compressed into the last
//   two bits of each pointer by the function 'encode()'.  The function
//   'decode()' decodes a pointer, extracting a face index and a pointer to
//   the beginning of a tetrahedron.

inline void tetgenmesh::decode(tetrahedron ptr, triface& t) {
  t.loc = (int) ((unsigned long) (ptr) & (unsigned long) 3l);
  t.tet = (tetrahedron *) ((unsigned long) (ptr) & ~(unsigned long) 7l);
}

inline tetgenmesh::tetrahedron tetgenmesh::encode(triface& t) {
  return (tetrahedron) ((unsigned long) t.tet | (unsigned long) t.loc);
}

// sym() finds the abutting tetrahedron on the same face.

inline void tetgenmesh::sym(triface& t1, triface& t2) {
  tetrahedron ptr = t1.tet[t1.loc];
  decode(ptr, t2);
}

inline void tetgenmesh::symself(triface& t) {
  tetrahedron ptr = t.tet[t.loc];
  decode(ptr, t);
}

// Bond two tetrahedra together at their faces.

inline void tetgenmesh::bond(triface& t1, triface& t2) {
  t1.tet[t1.loc] = encode(t2);
  t2.tet[t2.loc] = encode(t1);
}

// Dissolve a bond (from one side).  Note that the other tetrahedron will
//   still think it is connected to this tetrahedron.  Usually, however,
//   the other tetrahedron is being deleted entirely, or bonded to another
//   tetrahedron, so it doesn't matter.

inline void tetgenmesh::dissolve(triface& t) {
  t.tet[t.loc] = (tetrahedron) dummytet;
}

// These primitives determine or set the origin, destination, apex or
//   opposition of a tetrahedron with respect to 'loc' and 'ver'.

inline tetgenmesh::point tetgenmesh::org(triface& t) {
  return (point) t.tet[locver2org[t.loc][t.ver] + 4];
}

inline tetgenmesh::point tetgenmesh::dest(triface& t) {
  return (point) t.tet[locver2dest[t.loc][t.ver] + 4];
}

inline tetgenmesh::point tetgenmesh::apex(triface& t) {
  return (point) t.tet[locver2apex[t.loc][t.ver] + 4];
}

inline tetgenmesh::point tetgenmesh::oppo(triface& t) {
  return (point) t.tet[loc2oppo[t.loc] + 4];
}

inline void tetgenmesh::setorg(triface& t, point pointptr) {
  t.tet[locver2org[t.loc][t.ver] + 4] = (tetrahedron) pointptr;
}

inline void tetgenmesh::setdest(triface& t, point pointptr) {
  t.tet[locver2dest[t.loc][t.ver] + 4] = (tetrahedron) pointptr;
}

inline void tetgenmesh::setapex(triface& t, point pointptr) {
  t.tet[locver2apex[t.loc][t.ver] + 4] = (tetrahedron) pointptr;
}

inline void tetgenmesh::setoppo(triface& t, point pointptr) {
  t.tet[loc2oppo[t.loc] + 4] = (tetrahedron) pointptr;
}

// These primitives were drived from Mucke's triangle-edge data structure
//   to change face-edge relation in a tetrahedron (esym, enext and enext2)
//   or between two tetrahedra (fnext).

// If e0 = e(i, j), e1 = e(j, i), that is e0 and e1 are the two directions
//   of the same undirected edge of a face. e0.sym() = e1 and vice versa.

inline void tetgenmesh::esym(triface& t1, triface& t2) {
  t2.tet = t1.tet;
  t2.loc = t1.loc;
  t2.ver = t1.ver + (EdgeRing(t1.ver) ? -1 : 1);
}

inline void tetgenmesh::esymself(triface& t) {
  t.ver += (EdgeRing(t.ver) ? -1 : 1);
}

// If e0 and e1 are both in the same edge ring of a face, e1 = e0.enext().

inline void tetgenmesh::enext(triface& t1, triface& t2) {
  t2.tet = t1.tet;
  t2.loc = t1.loc;
  t2.ver = ve[t1.ver];
}

inline void tetgenmesh::enextself(triface& t) {
  t.ver = ve[t.ver];
}

// enext2() is equal to e2 = e0.enext().enext()

inline void tetgenmesh::enext2(triface& t1, triface& t2) {
  t2.tet = t1.tet;
  t2.loc = t1.loc;
  t2.ver = ve[ve[t1.ver]];
}

inline void tetgenmesh::enext2self(triface& t) {
  t.ver = ve[ve[t.ver]];
}

// If f0 and f1 are both in the same face ring of a face, f1 = f0.fnext().
//   If f1 exists, return true. Otherwise, return false, i.e., f0 is a
//   boundary or hull face.

inline bool tetgenmesh::fnext(triface& t1, triface& t2) {
  return getnextface(&t1, &t2);
}

inline bool tetgenmesh::fnextself(triface& t) {
  return getnextface(&t, NULL);
}

// enextfnext() and enext2fnext() are combination primitives of enext(),
//   enext2() and fnext().

inline void tetgenmesh::enextfnext(triface& t1, triface& t2) {
  enext(t1, t2);
  fnextself(t2);
}

inline void tetgenmesh::enextfnextself(triface& t) {
  enextself(t);
  fnextself(t);
}

inline void tetgenmesh::enext2fnext(triface& t1, triface& t2) {
  enext2(t1, t2);
  fnextself(t2);
}

inline void tetgenmesh::enext2fnextself(triface& t) {
  enext2self(t);
  fnextself(t);
}

// Primitives to infect or cure a tetrahedron with the virus.   The last
//   third bit of the pointer is marked for infection.  These rely on the
//   assumption that all tetrahedron are aligned to eight-byte boundaries.

inline void tetgenmesh::infect(triface& t) {
  t.tet[0] = (tetrahedron) ((unsigned long) t.tet[0] | (unsigned long) 4l);
}

inline void tetgenmesh::uninfect(triface& t) {
  t.tet[0] = (tetrahedron) ((unsigned long) t.tet[0] & ~ (unsigned long) 4l);
}

// Test a tetrahedron for viral infection.

inline bool tetgenmesh::infected(triface& t) {
  return (((unsigned long) t.tet[0] & (unsigned long) 4l) != 0);
}

// Check or set a tetrahedron's attributes.

inline REAL tetgenmesh::elemattribute(tetrahedron* ptr, int attnum) {
  return ((REAL *) (ptr))[elemattribindex + attnum];
}

inline void tetgenmesh::
setelemattribute(tetrahedron* ptr, int attnum, REAL value){
  ((REAL *) (ptr))[elemattribindex + attnum] = value;
}

// Check or set a tetrahedron's maximum volume bound.

inline REAL tetgenmesh::volumebound(tetrahedron* ptr) {
  return ((REAL *) (ptr))[volumeboundindex];
}

inline void tetgenmesh::setvolumebound(tetrahedron* ptr, REAL value) {
  ((REAL *) (ptr))[volumeboundindex] = value;
}

//
// End of primitives for tetrahedra
//

//
// Begin of primitives for subfaces/subsegments
//

// Each subface contains three pointers to its neighboring subfaces, with
//   edge versions.  To save memory, both information are kept in a single
//   pointer. To make this possible, all subfaces are aligned to eight-byte
//   boundaries, so that the last three bits of each pointer are zeros. An
//   edge version (in the range 0 to 5) is compressed into the last three
//   bits of each pointer by 'sencode()'.  'sdecode()' decodes a pointer,
//   extracting an edge version and a pointer to the beginning of a subface.

inline void tetgenmesh::sdecode(shellface sptr, face& s) {
  s.shver = (int) ((unsigned long) (sptr) & (unsigned long) 7l);
  s.sh = (shellface *) ((unsigned long) (sptr) & ~ (unsigned long) 7l);
}

inline tetgenmesh::shellface tetgenmesh::sencode(face& s) {
  return (shellface) ((unsigned long) s.sh | (unsigned long) s.shver);
}

// spivot() finds the other subface (from this subface) that shares the
//   same edge.

inline void tetgenmesh::spivot(face& s1, face& s2) {
  shellface sptr = s1.sh[Orient(s1.shver)];
  sdecode(sptr, s2);
}

inline void tetgenmesh::spivotself(face& s) {
  shellface sptr = s.sh[Orient(s.shver)];
  sdecode(sptr, s);
}

// sbond() bonds two subfaces together, i.e., after bonding, both faces
//   are pointing to each other.

inline void tetgenmesh::sbond(face& s1, face& s2) {
  s1.sh[Orient(s1.shver)] = sencode(s2);
  s2.sh[Orient(s2.shver)] = sencode(s1);
}

// sbond1() only bonds s2 to s1, i.e., after bonding, s1 is pointing to s2,
//   but s2 is not pointing to s1.

inline void tetgenmesh::sbond1(face& s1, face& s2) {
  s1.sh[Orient(s1.shver)] = sencode(s2);
}

// Dissolve a subface bond (from one side).  Note that the other subface
//   will still think it's connected to this subface.

inline void tetgenmesh::sdissolve(face& s) {
  s.sh[Orient(s.shver)] = (shellface) dummysh;
}

// These primitives determine or set the origin, destination, or apex
//   of a subface with respect to the edge version.

inline tetgenmesh::point tetgenmesh::sorg(face& s) {
  return (point) s.sh[3 + vo[s.shver]];
}

inline tetgenmesh::point tetgenmesh::sdest(face& s) {
  return (point) s.sh[3 + vd[s.shver]];
}

inline tetgenmesh::point tetgenmesh::sapex(face& s) {
  return (point) s.sh[3 + va[s.shver]];
}

inline void tetgenmesh::setsorg(face& s, point pointptr) {
  s.sh[3 + vo[s.shver]] = (shellface) pointptr;
}

inline void tetgenmesh::setsdest(face& s, point pointptr) {
  s.sh[3 + vd[s.shver]] = (shellface) pointptr;
}

inline void tetgenmesh::setsapex(face& s, point pointptr) {
  s.sh[3 + va[s.shver]] = (shellface) pointptr;
}

// These primitives were drived from Mucke[2]'s triangle-edge data structure
//   to change face-edge relation in a subface (sesym, senext and senext2).

inline void tetgenmesh::sesym(face& s1, face& s2) {
  s2.sh = s1.sh;
  s2.shver = s1.shver + (EdgeRing(s1.shver) ? -1 : 1);
}

inline void tetgenmesh::sesymself(face& s) {
  s.shver += (EdgeRing(s.shver) ? -1 : 1);
}

inline void tetgenmesh::senext(face& s1, face& s2) {
  s2.sh = s1.sh;
  s2.shver = ve[s1.shver];
}

inline void tetgenmesh::senextself(face& s) { 
  s.shver = ve[s.shver]; 
}

inline void tetgenmesh::senext2(face& s1, face& s2) {
  s2.sh = s1.sh;
  s2.shver = ve[ve[s1.shver]];
}

inline void tetgenmesh::senext2self(face& s) {
  s.shver = ve[ve[s.shver]];
}

// If f0 and f1 are both in the same face ring, then f1 = f0.fnext(),

inline void tetgenmesh::sfnext(face& s1, face& s2) {
  getnextsface(&s1, &s2);
}

inline void tetgenmesh::sfnextself(face& s) {
  getnextsface(&s, NULL);
}

// These primitives read or set a pointer of the badface structure.  The
//   pointer is stored sh[11].

inline tetgenmesh::badface* tetgenmesh::shell2badface(face& s) {
  return (badface*) s.sh[11];
}

inline void tetgenmesh::setshell2badface(face& s, badface* value) {
  s.sh[11] = (shellface) value;
}

// Check or set a subface's maximum area bound.

inline REAL tetgenmesh::areabound(face& s) {
  return ((REAL *) (s.sh))[areaboundindex];
}

inline void tetgenmesh::setareabound(face& s, REAL value) {
  ((REAL *) (s.sh))[areaboundindex] = value;
}

// These two primitives read or set a shell marker.  Shell markers are used
//   to hold user boundary information.

inline int tetgenmesh::shellmark(face& s) { 
  return ((int *) (s.sh))[shmarkindex];
}

inline void tetgenmesh::setshellmark(face& s, int value) {
  ((int *) (s.sh))[shmarkindex] = value;
}

// These two primitives set or read the type of the subface or subsegment.

inline enum tetgenmesh::shestype tetgenmesh::shelltype(face& s) {
  return (enum shestype) ((int *) (s.sh))[shmarkindex + 1];
}

inline void tetgenmesh::setshelltype(face& s, enum shestype value) {
  ((int *) (s.sh))[shmarkindex + 1] = (int) value;
}

// These two primitives set or read the pbc group of the subface.

inline int tetgenmesh::shellpbcgroup(face& s) {
  return ((int *) (s.sh))[shmarkindex + 2];
}

inline void tetgenmesh::setshellpbcgroup(face& s, int value) {
  ((int *) (s.sh))[shmarkindex + 2] = value;
}

// Primitives to infect or cure a subface with the virus. These rely on the
//   assumption that all tetrahedra are aligned to eight-byte boundaries.

inline void tetgenmesh::sinfect(face& s) {
  s.sh[6] = (shellface) ((unsigned long) s.sh[6] | (unsigned long) 4l);
}

inline void tetgenmesh::suninfect(face& s) {
  s.sh[6] = (shellface)((unsigned long) s.sh[6] & ~(unsigned long) 4l);
}

// Test a subface for viral infection.

inline bool tetgenmesh::sinfected(face& s) {
  return (((unsigned long) s.sh[6] & (unsigned long) 4l) != 0);
}

//
// End of primitives for subfaces/subsegments
//

//
// Begin of primitives for interacting between tetrahedra and subfaces
//

// tspivot() finds a subface abutting on this tetrahdera.

inline void tetgenmesh::tspivot(triface& t, face& s) {
  shellface sptr = (shellface) t.tet[8 + t.loc];
  sdecode(sptr, s);
}

// stpivot() finds a tetrahedron abutting a subface.

inline void tetgenmesh::stpivot(face& s, triface& t) {
  tetrahedron ptr = (tetrahedron) s.sh[6 + EdgeRing(s.shver)];
  decode(ptr, t);
}

// tsbond() bond a tetrahedron to a subface.

inline void tetgenmesh::tsbond(triface& t, face& s) {
  t.tet[8 + t.loc] = (tetrahedron) sencode(s);
  s.sh[6 + EdgeRing(s.shver)] = (shellface) encode(t);
}

// tsdissolve() dissolve a bond (from the tetrahedron side).

inline void tetgenmesh::tsdissolve(triface& t) {
  t.tet[8 + t.loc] = (tetrahedron) dummysh;
}

// stdissolve() dissolve a bond (from the subface side).

inline void tetgenmesh::stdissolve(face& s) {
  s.sh[6 + EdgeRing(s.shver)] = (shellface) dummytet;
}

//
// End of primitives for interacting between tetrahedra and subfaces
//

//
// Begin of primitives for interacting between subfaces and subsegs
//

// sspivot() finds a subsegment abutting a subface.

inline void tetgenmesh::sspivot(face& s, face& edge) {
  shellface sptr = (shellface) s.sh[8 + Orient(s.shver)];
  sdecode(sptr, edge);
}

// ssbond() bond a subface to a subsegment.

inline void tetgenmesh::ssbond(face& s, face& edge) {
  s.sh[8 + Orient(s.shver)] = sencode(edge);
  edge.sh[0] = sencode(s);
}

// ssdisolve() dissolve a bond (from the subface side)

inline void tetgenmesh::ssdissolve(face& s) {
  s.sh[8 + Orient(s.shver)] = (shellface) dummysh;
}

//
// End of primitives for interacting between subfaces and subsegs
//

//
// Begin of primitives for points
//

inline int tetgenmesh::pointmark(point pt) { 
  return ((int *) (pt))[pointmarkindex]; 
}

inline void tetgenmesh::setpointmark(point pt, int value) {
  ((int *) (pt))[pointmarkindex] = value;
}

// These two primitives set and read the type of the point.

inline enum tetgenmesh::verttype tetgenmesh::pointtype(point pt) {
  return (enum verttype) ((int *) (pt))[pointmarkindex + 1];
}

inline void tetgenmesh::setpointtype(point pt, enum verttype value) {
  ((int *) (pt))[pointmarkindex + 1] = (int) value;
}

// These two primitives set and read a pointer to a tetrahedron.

inline tetgenmesh::tetrahedron tetgenmesh::point2tet(point pt) {
  return ((tetrahedron *) (pt))[point2simindex];
}

inline void tetgenmesh::setpoint2tet(point pt, tetrahedron value) {
  ((tetrahedron *) (pt))[point2simindex] = value;
}

// These two primitives set and read a pointer to a subface/subsegment.
//   Note: they use the same field as the above. Don't use them together.

inline tetgenmesh::shellface tetgenmesh::point2sh(point pt) {
  return (shellface) ((tetrahedron *) (pt))[point2simindex];
}

inline void tetgenmesh::setpoint2sh(point pt, shellface value) {
  ((tetrahedron *) (pt))[point2simindex] = (tetrahedron) value;
}

// These two primitives set and read a pointer to a point. 
//   Note: they use the same field as the above. Don't use them together.

inline tetgenmesh::point tetgenmesh::point2pt(point pt) {
  return (point) ((tetrahedron *) (pt))[point2simindex];
}

inline void tetgenmesh::setpoint2pt(point pt, point value) {
  ((tetrahedron *) (pt))[point2simindex] = (tetrahedron) value;
}

// These primitives set and read a pointer to its parent point. They're used
//   only in qulaity conforming Delaunay mesh algorithm.

inline tetgenmesh::point tetgenmesh::point2ppt(point pt) {
  return (point) ((tetrahedron *) (pt))[point2simindex + 1];
}

inline void tetgenmesh::setpoint2ppt(point pt, point value) {
  ((tetrahedron *) (pt))[point2simindex + 1] = (tetrahedron) value;
}

// These primitives set and read a pointer to its pbc point.

inline tetgenmesh::point tetgenmesh::point2pbcpt(point pt) {
  return (point) ((tetrahedron *) (pt))[point2pbcptindex];
}

inline void tetgenmesh::setpoint2pbcpt(point pt, point value) {
  ((tetrahedron *) (pt))[point2pbcptindex] = (tetrahedron) value;
}

// These primitives set and read a edge bound of this point.

inline REAL tetgenmesh::edgebound(point pt) {
  return ((REAL *) (pt))[edgeboundindex];
}

inline void tetgenmesh::setedgebound(point pt, REAL value) {
  ((REAL *) (pt))[edgeboundindex] = value;
}

// Get the pre-calculated lifting point of a facet (specified by its mark).  

inline tetgenmesh::point tetgenmesh::getliftpoint(int facetmark) {
  return (point) &liftpointarray[(facetmark - 1) * 3];
}

//
// End of primitives for points
//

//
// Begin of advanced primitives
//

// adjustedgering() adjusts the edge version so that it belongs to the
//   indicated edge ring.  The 'direction' only can be 0(CCW) or 1(CW).
//   If the edge is not in the wanted edge ring, reverse it.

inline void tetgenmesh::adjustedgering(triface& t, int direction) {
  if (EdgeRing(t.ver) != direction) {
    esymself(t);
  }
}

inline void tetgenmesh::adjustedgering(face& s, int direction) {
  if (EdgeRing(s.shver) != direction) {
    sesymself(s);
  }
}

// isdead() returns TRUE if the tetrahedron or subface has been dealloced.

inline bool tetgenmesh::isdead(triface* t) {
  if (t->tet == (tetrahedron *) NULL) return true;
  else return t->tet[4] == (tetrahedron) NULL;
}

inline bool tetgenmesh::isdead(face* s) {
  if (s->sh == (shellface *) NULL) return true;
  else return s->sh[3] == (shellface) NULL;
}

// isfacehaspoint() returns TRUE if the 'testpoint' is one of the vertices
//   of the subface 's'.

inline bool tetgenmesh::isfacehaspoint(face* s, point testpoint) {
  return (s->sh[3] == (shellface) testpoint) || 
         (s->sh[4] == (shellface) testpoint) ||
         (s->sh[5] == (shellface) testpoint);
}

// isfacehasedge() returns TRUE if the edge (given by its two endpoints) is
//   one of the three edges of the subface 's'.

inline bool tetgenmesh::isfacehasedge(face* s, point tend1, point tend2) {
  return (isfacehaspoint(s, tend1) && isfacehaspoint(s, tend2));
}

// issymexist() returns TRUE if the adjoining tetrahedron is not 'duumytet'.

inline bool tetgenmesh::issymexist(triface* t) {
  tetrahedron *ptr = (tetrahedron *) 
    ((unsigned long)(t->tet[t->loc]) & ~(unsigned long)7l);
  return ptr != dummytet;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// getnextface()    Get the successor of 'tface1' in the face ring.          //
//                                                                           //
// If 'tface1' is not a boundary (or hull) face, then its successor in the   //
// face ring exists. The successor is returned in 'tface2' if it is not a    //
// NULL, or the 'tface1' itself is used to return this face. On finish, the  //
// function returns TRUE.                                                    //
//                                                                           //
// If 'tface1' is a boundary (or hull) face, its successor does not exist.   //
// This case, return FALSE and 'tface1' remains unchanged.                   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenmesh::getnextface(triface* tface1, triface* tface2)
{
  point torg, tdest;
  int tloc, tver;

  // Where the next face locates, in 'tface1' or in its neigbhour? It can be
  //   quickly determined by checking the edge ring of 'tface1'.
  if (EdgeRing(tface1->ver) == CW) {
    // The next face is in the neigbhour of 'tface1'.
    if (!issymexist(tface1)) {
      // Hit outer space - The next face does not exist.
      return false;
    }
    torg = org(*tface1);
    tdest = dest(*tface1);
    if (tface2) {
      sym(*tface1, *tface2);
      findedge(tface2, torg, tdest);
    } else {
      symself(*tface1);
      findedge(tface1, torg, tdest);
    }
  } else {
    // The next face is in 'tface1'.
    if (tface2) {
      *tface2 = *tface1;
    }
  }

  if (tface2) {
    tloc = tface2->loc;
    tver = tface2->ver;
    tface2->loc = locver2nextf[tloc][tver][0];
    tface2->ver = locver2nextf[tloc][tver][1];
  } else {
    tloc = tface1->loc;
    tver = tface1->ver;
    tface1->loc = locver2nextf[tloc][tver][0];
    tface1->ver = locver2nextf[tloc][tver][1];
  }
  return true;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// getnextsface()    Finds the next subface in the face ring.                //
//                                                                           //
// For saving space in the data structure of subface, there only exists one  //
// face ring around a segment (see programming manual).  This routine imple- //
// ments the double face ring as desired in Muecke's data structure.         //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::getnextsface(face* s1, face* s2)
{
  face neighsh, spinsh;
  face testseg;

  sspivot(*s1, testseg);
  if (testseg.sh != dummysh) {
    testseg.shver = 0;
    if (sorg(testseg) == sorg(*s1)) {
      spivot(*s1, neighsh);
    } else {
      spinsh = *s1;
      do {
        neighsh = spinsh;
        spivotself(spinsh);
      } while (spinsh.sh != s1->sh);
    }
  } else {
    spivot(*s1, neighsh);
  }
  if (sorg(neighsh) != sorg(*s1)) {
    sesymself(neighsh);
  }
  if (s2 != (face *) NULL) {
    *s2 = neighsh;
  } else {
    *s1 = neighsh;
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// tsspivot()    Finds a subsegment abutting on a tetrahderon's edge.        //
//                                                                           //
// The edge is represented in the primary edge of 'checkedge'. If there is a //
// subsegment bonded at this edge, it is returned in handle 'checkseg', the  //
// edge direction of 'checkseg' is conformed to 'checkedge'. If there isn't, //
// set 'checkseg.sh = dummysh' to indicate it is not a subsegment.           //
//                                                                           //
// To find whether an edge of a tetrahedron is a subsegment or not. First we //
// need find a subface around this edge to see if it contains a subsegment.  //
// The reason is there is no direct connection between a tetrahedron and its //
// adjoining subsegments.                                                    //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::tsspivot(triface* checkedge, face* checkseg)
{
  triface spintet;
  face parentsh;
  point tapex;
  int hitbdry;

  spintet = *checkedge;
  tapex = apex(*checkedge);
  hitbdry = 0;
  do {
    tspivot(spintet, parentsh);
    if (parentsh.sh != dummysh) {
      // Find a subface!
      findedge(&parentsh, org(*checkedge), dest(*checkedge));
      sspivot(parentsh, *checkseg);
      if (checkseg->sh != dummysh) {
        // Find a subsegment! Correct its edge direction before return.
        if (sorg(*checkseg) != sorg(parentsh)) {
          sesymself(*checkseg);
        }
      }
      return;
    }
    if (!fnextself(spintet)) {
      hitbdry++;
      if (hitbdry < 2) {
        esym(*checkedge, spintet);
        if (!fnextself(spintet)) {
          hitbdry++;
        }
      }
    }
  } while ((apex(spintet) != tapex) && (hitbdry < 2));
  // Not find.
  checkseg->sh = dummysh;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// sstpivot()    Finds a tetrahedron abutting a subsegment.                  //
//                                                                           //
// This is the inverse operation of 'tsspivot()'.  One subsegment shared by  //
// arbitrary number of tetrahedron, the returned tetrahedron is not unique.  //
// The edge direction of the returned tetrahedron is conformed to the given  //
// subsegment.                                                               //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::sstpivot(face* checkseg, triface* retedge)
{
  face parentsh;

  // Get the subface which holds the subsegment.
  sdecode(checkseg->sh[0], parentsh);
  assert(parentsh.sh != dummysh);
  // Get a tetraheron to which the subface attches.
  stpivot(parentsh, *retedge);
  if (retedge->tet == dummytet) {
    sesymself(parentsh);
    stpivot(parentsh, *retedge);
    assert(retedge->tet != dummytet);
  }
  // Correct the edge direction before return.
  findedge(retedge, sorg(*checkseg), sdest(*checkseg));
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// findorg()    Finds a point in the given handle (tetrahedron or subface).  //
//                                                                           //
// If 'dorg' is a one of vertices of the given handle,  set the origin of    //
// this handle be that point and return TRUE.  Otherwise, return FALSE and   //
// 'tface' remains unchanged.                                                //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenmesh::findorg(triface* tface, point dorg)
{
  if (org(*tface) == dorg) {
    return true;
  } else { 
    if (dest(*tface) == dorg) {
      enextself(*tface);
      return true;
    } else {
      if (apex(*tface) == dorg) {
        enext2self(*tface);
        return true;
      } else {
        if (oppo(*tface) == dorg) {
          // Keep 'tface' referring to the same tet after fnext().
          adjustedgering(*tface, CCW);
          fnextself(*tface);
          enext2self(*tface);
          return true;
        } 
      }
    }
  }
  return false;
}

bool tetgenmesh::findorg(face* sface, point dorg)
{
  if (sorg(*sface) == dorg) {
    return true;
  } else {
    if (sdest(*sface) == dorg) {
      senextself(*sface);
      return true;
    } else {
      if (sapex(*sface) == dorg) {
        senext2self(*sface);
        return true;
      } 
    }
  }
  return false;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// findedge()    Find an edge in the given handle (tetrahedron or subface).  //
//                                                                           //
// The edge is given in two points 'eorg' and 'edest'.  It is assumed that   //
// the edge must exist in the given handle (tetrahedron or subface).  This   //
// routine sets the right edge version for the input handle.                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::findedge(triface* tface, point eorg, point edest)
{
  int i;

  for (i = 0; i < 3; i++) {
    if (org(*tface) == eorg) {
      if (dest(*tface) == edest) {
        // Edge is found, return.
        return;
      } 
    } else {
      if (org(*tface) == edest) {
        if (dest(*tface) == eorg) {
          // Edge is found, but need to inverse the direction.
          esymself(*tface);
          return;
        }
      }
    }
    enextself(*tface);
  }
  // It should not be here.
  assert(i < 3);
}

void tetgenmesh::findedge(face* sface, point eorg, point edest)
{
  int i;

  for (i = 0; i < 3; i++) {
    if (sorg(*sface) == eorg) {
      if (sdest(*sface) == edest) {
        // Edge is found, return.
        return;
      } 
    } else {
      if (sorg(*sface) == edest) {
        if (sdest(*sface) == eorg) {
          // Edge is found, but need to inverse the direction.
          sesymself(*sface);
          return;
        }
      }
    }
    senextself(*sface);
  }
  // It should not be here.
  assert(i < 3);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// findface()    Find the face has the given origin, destination and apex.   //
//                                                                           //
// On input, 'fface' is a handle which may contain the three corners or may  //
// not or may be dead.  On return, it represents exactly the face with the   //
// given origin, destination and apex.                                       //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::findface(triface *fface, point forg, point fdest, point fapex)
{
  triface spintet;
  enum finddirectionresult collinear;
  int hitbdry;

  if (!isdead(fface)) {
    // First check the easiest case, that 'fface' is just the right one.
    if (org(*fface) == forg && dest(*fface) == fdest && 
        apex(*fface) == fapex) return;
  } else {
    // The input handle is dead, use the 'recenttet' if it is alive.
    if (!isdead(&recenttet)) *fface = recenttet;
  }

  if (!isdead(fface)) {
    if (!findorg(fface, forg)) {
      // 'forg' is not a corner of 'fface', locate it.
      preciselocate(forg, fface);
    }
    // It is possible that forg is not found in a non-convex mesh.
    if (org(*fface) == forg) {
      collinear = finddirection(fface, fdest);
      if (collinear == RIGHTCOLLINEAR) {
        // fdest is just the destination.
      } else if (collinear == LEFTCOLLINEAR) {
        enext2self(*fface);
        esymself(*fface);
      } else if (collinear == TOPCOLLINEAR) {
        fnextself(*fface);
        enext2self(*fface);
        esymself(*fface);
      }
    }
    // It is possible taht fdest is not found in a non-convex mesh.
    if ((org(*fface) == forg) && (dest(*fface) == fdest)) {
      // Find the apex of 'fapex'.
      spintet = *fface;
      hitbdry = 0;
      do {
        if (apex(spintet) == fapex) {
          // We have done. Be careful the edge direction of 'spintet',
          //   it may reversed because of hitting boundary once.
          if (org(spintet) != org(*fface)) {
            esymself(spintet);
          }
          *fface = spintet;
          return;
        }
        if (!fnextself(spintet)) {
          hitbdry ++;
          if (hitbdry < 2) {
            esym(*fface, spintet);
            if (!fnextself(spintet)) {
              hitbdry ++;
            }
          }
        }
      } while (hitbdry < 2 && apex(spintet) != apex(*fface));
      // It is possible that fapex is not found in a non-convex mesh.
    }
  }

  if (isdead(fface) || (org(*fface) != forg) || (dest(*fface) != fdest) ||
      (apex(*fface) != fapex)) {
    // Too bad, the input handle is useless. We have to find a handle
    //   for 'fface' contains the 'forg' and 'fdest'. Here a brute force
    //   search is performed.
    if (b->verbose > 1) {
      printf("Warning in findface():  Perform a brute-force searching.\n");
    }
    enum verttype forgty, fdestty, fapexty;
    int share, i;
    forgty = pointtype(forg);
    fdestty = pointtype(fdest);
    fapexty = pointtype(fapex);
    setpointtype(forg, DEADVERTEX);
    setpointtype(fdest, DEADVERTEX);
    setpointtype(fapex, DEADVERTEX);
    tetrahedrons->traversalinit();
    fface->tet = tetrahedrontraverse();
    while (fface->tet != (tetrahedron *) NULL) {
      share = 0;
      for (i = 0; i < 4; i++) {
        if (pointtype((point) fface->tet[4 + i]) == DEADVERTEX) share ++;
      }
      if (share == 3) {
        // Found! Set the correct face and desired corners.
        if (pointtype((point) fface->tet[4]) != DEADVERTEX) {
          fface->loc = 2;
        } else if (pointtype((point) fface->tet[5]) != DEADVERTEX) {
          fface->loc = 3;
        } else if (pointtype((point) fface->tet[6]) != DEADVERTEX) {
          fface->loc = 1;
        } else { // pointtype((point) fface->tet[7]) != DEADVERTEX
          fface->loc = 0;
        }
        findedge(fface, forg, fdest);
        break;
      }
      fface->tet = tetrahedrontraverse();
    }
    setpointtype(forg, forgty);
    setpointtype(fdest, fdestty);
    setpointtype(fapex, fapexty);
    if (fface->tet == (tetrahedron *) NULL) {
      // It is impossible to reach here.
      printf("Internal error:  Fail to find the indicated face.\n");
      internalerror();
    }
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// getonextseg()    Get the next SEGMENT counterclockwise with the same org. //
//                                                                           //
// 's' is a subface. This routine reteuns the segment which is counterclock- //
// wise with the origin of s.                                                //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::getonextseg(face* s, face* lseg)
{
  face checksh, checkseg;
  point forg;

  forg = sorg(*s);
  checksh = *s;
  do {
    // Go to the edge at forg's left side.
    senext2self(checksh);
    // Check if there is a segment attaching this edge.
    sspivot(checksh, checkseg);
    if (checkseg.sh != dummysh) break;
    // No segment! Go to the neighbor of this subface.
    spivotself(checksh);
    // It should always meet a segment before come back.
    assert(checksh.sh != s->sh);
    if (sorg(checksh) != forg) {
      sesymself(checksh);
      assert(sorg(checksh) == forg);
    }
  } while (true);
  assert(checkseg.sh != dummysh);
  if (sorg(checkseg) != forg) sesymself(checkseg);
  *lseg = checkseg;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// getseghasorg()    Get the segment containing the given point.             //
//                                                                           //
// On input we know 'dorg' is an endpoint of the segment containing 'sseg'.  //
// This routine search along 'sseg' for the vertex 'dorg'. On return, 'sseg' //
// contains 'dorg' as its origin.                                            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::getseghasorg(face* sseg, point dorg)
{
  face nextseg;
  point checkpt;

  nextseg = *sseg;
  checkpt = sorg(nextseg);
  while ((checkpt != dorg) && (pointtype(checkpt) == FREESEGVERTEX)) {
    // Search dorg along the original direction of sseg.
    senext2self(nextseg);
    spivotself(nextseg);
    nextseg.shver = 0;
    if (sdest(nextseg) != checkpt) sesymself(nextseg);
    checkpt = sorg(nextseg);
  }
  if (checkpt == dorg) {
    *sseg = nextseg;
    return;
  }
  nextseg = *sseg;
  checkpt = sdest(nextseg);
  while ((checkpt != dorg) && (pointtype(checkpt) == FREESEGVERTEX)) {
    // Search dorg along the destinational direction of sseg.
    senextself(nextseg);
    spivotself(nextseg);
    nextseg.shver = 0;
    if (sorg(nextseg) != checkpt) sesymself(nextseg);
    checkpt = sdest(nextseg);
  }
  if (checkpt == dorg) {
    sesym(nextseg, *sseg);
    return;
  }
  // Should not be here.
  assert(0);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// getsubsegfarorg()    Get the origin of the parent segment of a subseg.    //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

tetgenmesh::point tetgenmesh::getsubsegfarorg(face* sseg)
{
  face prevseg;
  point checkpt;

  checkpt = sorg(*sseg);
  senext2(*sseg, prevseg);
  spivotself(prevseg);
  // Search dorg along the original direction of sseg.
  while (prevseg.sh != dummysh) {
    prevseg.shver = 0;
    if (sdest(prevseg) != checkpt) sesymself(prevseg);
    checkpt = sorg(prevseg);
    senext2self(prevseg);
    spivotself(prevseg);
  }
  return checkpt;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// getsubsegfardest()    Get the dest. of the parent segment of a subseg.    //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

tetgenmesh::point tetgenmesh::getsubsegfardest(face* sseg)
{
  face nextseg;
  point checkpt;

  checkpt = sdest(*sseg);
  senext(*sseg, nextseg);
  spivotself(nextseg);
  // Search dorg along the destinational direction of sseg.
  while (nextseg.sh != dummysh) {
    nextseg.shver = 0;
    if (sorg(nextseg) != checkpt) sesymself(nextseg);
    checkpt = sdest(nextseg);
    senextself(nextseg);
    spivotself(nextseg);
  }
  return checkpt;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// printtet()    Print out the details of a tetrahedron on screen.           //
//                                                                           //
// It's also used when the highest level of verbosity (`-VVV') is specified. //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::printtet(triface* tface)
{
  triface tmpface, prtface;
  point tmppt;
  face tmpsh;
  int facecount;

  printf("Tetra x%lx with loc(%i) and ver(%i):",
         (unsigned long)(tface->tet), tface->loc, tface->ver);
  if (infected(*tface)) {
    printf(" (infected)");
  }
  printf("\n");

  tmpface = *tface;
  facecount = 0;
  while(facecount < 4) {
    tmpface.loc = facecount;
    sym(tmpface, prtface);
    if(prtface.tet == dummytet) {
      printf("      [%i] Outer space.\n", facecount);
    } else {
      printf("      [%i] x%lx  loc(%i).", facecount,
             (unsigned long)(prtface.tet), prtface.loc);
      if (infected(prtface)) {
        printf(" (infected)");
      }
      printf("\n");
    }
    facecount ++;
  }

  tmppt = org(*tface);
  if(tmppt == (point) NULL) {
    printf("      Org [%i] NULL\n", locver2org[tface->loc][tface->ver]);
  } else {
    printf("      Org [%i] x%lx (%.12g,%.12g,%.12g) %d\n",
           locver2org[tface->loc][tface->ver], (unsigned long)(tmppt),
           tmppt[0], tmppt[1], tmppt[2], pointmark(tmppt));
  }
  tmppt = dest(*tface);
  if(tmppt == (point) NULL) {
    printf("      Dest[%i] NULL\n", locver2dest[tface->loc][tface->ver]);
  } else {
    printf("      Dest[%i] x%lx (%.12g,%.12g,%.12g) %d\n",
           locver2dest[tface->loc][tface->ver], (unsigned long)(tmppt),
           tmppt[0], tmppt[1], tmppt[2], pointmark(tmppt));
  }
  tmppt = apex(*tface);
  if(tmppt == (point) NULL) {
    printf("      Apex[%i] NULL\n", locver2apex[tface->loc][tface->ver]);
  } else {
    printf("      Apex[%i] x%lx (%.12g,%.12g,%.12g) %d\n",
           locver2apex[tface->loc][tface->ver], (unsigned long)(tmppt),
           tmppt[0], tmppt[1], tmppt[2], pointmark(tmppt));
  }
  tmppt = oppo(*tface);
  if(tmppt == (point) NULL) {
    printf("      Oppo[%i] NULL\n", loc2oppo[tface->loc]);
  } else {
    printf("      Oppo[%i] x%lx (%.12g,%.12g,%.12g) %d\n",
           loc2oppo[tface->loc], (unsigned long)(tmppt),
           tmppt[0], tmppt[1], tmppt[2], pointmark(tmppt));
  }

  if (b->useshelles) {
    tmpface = *tface;
    facecount = 0;
    while(facecount < 4) {
      tmpface.loc = facecount;
      tspivot(tmpface, tmpsh);
      if(tmpsh.sh != dummysh) {
        printf("      [%i] x%lx  ID(%i) ", facecount,
               (unsigned long)(tmpsh.sh), shellmark(tmpsh));
        if (sorg(tmpsh) == (point) NULL) {
          printf("(fake)");
        }
        printf("\n");
      }
      facecount ++;
    }
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// printsh()    Print out the details of a subface or subsegment on screen.  //
//                                                                           //
// It's also used when the highest level of verbosity (`-VVV') is specified. //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::printsh(face* sface)
{
  face prtsh;
  triface prttet;
  point printpoint;

  if (sapex(*sface) != NULL) {
    printf("subface x%lx, ver %d, mark %d:",
           (unsigned long)(sface->sh), sface->shver, shellmark(*sface));
  } else {
    printf("Subsegment x%lx, ver %d, mark %d:",
           (unsigned long)(sface->sh), sface->shver, shellmark(*sface));
  }
  if (sinfected(*sface)) {
    printf(" (infected)");
  }
  if (shell2badface(*sface)) {
    printf(" (queued)");
  }
  if (sapex(*sface) != NULL) {
    if (shelltype(*sface) == SHARPSUB) {
      printf(" (sharp)");
    } else if (shelltype(*sface) == SKINNYSUB) {
      printf(" (skinny)");
    }
  } else {
    if (shelltype(*sface) == SHARPSUB) {
      printf(" (sharp)");
    }
  }
  if (checkpbcs) {
    if (shellpbcgroup(*sface) >= 0) {
      printf(" (pbc %d)", shellpbcgroup(*sface));
    }
  }
  printf("\n");

  sdecode(sface->sh[0], prtsh);
  if (prtsh.sh == dummysh) {
    printf("      [0] = No shell\n");
  } else {
    printf("      [0] = x%lx  %d\n", (unsigned long)(prtsh.sh), prtsh.shver);
  }
  sdecode(sface->sh[1], prtsh);
  if (prtsh.sh == dummysh) {
    printf("      [1] = No shell\n");
  } else {
    printf("      [1] = x%lx  %d\n", (unsigned long)(prtsh.sh), prtsh.shver);
  }
  sdecode(sface->sh[2], prtsh);
  if (prtsh.sh == dummysh) {
    printf("      [2] = No shell\n");
  } else {
    printf("      [2] = x%lx  %d\n", (unsigned long)(prtsh.sh), prtsh.shver);
  }

  printpoint = sorg(*sface);
  if (printpoint == (point) NULL)
    printf("      Org [%d] = NULL\n", vo[sface->shver]);
  else
    printf("      Org [%d] = x%lx  (%.12g,%.12g,%.12g) %d\n",
           vo[sface->shver], (unsigned long)(printpoint), printpoint[0],
           printpoint[1], printpoint[2], pointmark(printpoint));
  printpoint = sdest(*sface);
  if (printpoint == (point) NULL)
    printf("      Dest[%d] = NULL\n", vd[sface->shver]);
  else
    printf("      Dest[%d] = x%lx  (%.12g,%.12g,%.12g) %d\n",
            vd[sface->shver], (unsigned long)(printpoint), printpoint[0],
            printpoint[1], printpoint[2], pointmark(printpoint));

  if (sapex(*sface) != NULL) {
    printpoint = sapex(*sface);
    if (printpoint == (point) NULL)
      printf("      Apex[%d] = NULL\n", va[sface->shver]);
    else
      printf("      Apex[%d] = x%lx  (%.12g,%.12g,%.12g) %d\n",
             va[sface->shver], (unsigned long)(printpoint), printpoint[0],
             printpoint[1], printpoint[2], pointmark(printpoint));

    decode(sface->sh[6], prttet);
    if (prttet.tet == dummytet) {
      printf("      [6] = Outer space\n");
    } else {
      printf("      [6] = x%lx  %d\n",
             (unsigned long)(prttet.tet), prttet.loc);
    }
    decode(sface->sh[7], prttet);
    if (prttet.tet == dummytet) {
      printf("      [7] = Outer space\n");
    } else {
      printf("      [7] = x%lx  %d\n",
             (unsigned long)(prttet.tet), prttet.loc);
    }

    sdecode(sface->sh[8], prtsh);
    if (prtsh.sh == dummysh) {
      printf("      [8] = No subsegment\n");
    } else {
      printf("      [8] = x%lx  %d\n",
             (unsigned long)(prtsh.sh), prtsh.shver);
    }
    sdecode(sface->sh[9], prtsh);
    if (prtsh.sh == dummysh) {
      printf("      [9] = No subsegment\n");
    } else {
      printf("      [9] = x%lx  %d\n",
             (unsigned long)(prtsh.sh), prtsh.shver);
    }
    sdecode(sface->sh[10], prtsh);
    if (prtsh.sh == dummysh) {
      printf("      [10]= No subsegment\n");
    } else {
      printf("      [10]= x%lx  %d\n",
             (unsigned long)(prtsh.sh), prtsh.shver);
    }
  } 
}

//
// End of advanced primitives
//

//
// End of mesh manipulation primitives
//

//
// Begin of mesh items searching routines
//

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// makepoint2tetmap()    Construct a mapping from points to tetrahedra.      //
//                                                                           //
// Traverses all the tetrahedra,  provides each corner of each tetrahedron   //
// with a pointer to that tetrahedera.  Some pointers will be overwritten by //
// other pointers because each point may be a corner of several tetrahedra,  //
// but in the end every point will point to a tetrahedron that contains it.  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::makepoint2tetmap()
{
  triface tetloop;
  point pointptr;

  if (b->verbose) {
    printf("  Constructing mapping from points to tetrahedra.\n");
  }

  tetrahedrons->traversalinit();
  tetloop.tet = tetrahedrontraverse();
  while (tetloop.tet != (tetrahedron *) NULL) {
    // Check all four points of the tetrahedron.
    tetloop.loc = 0;
    pointptr = org(tetloop);
    setpoint2tet(pointptr, encode(tetloop));
    pointptr = dest(tetloop);
    setpoint2tet(pointptr, encode(tetloop));
    pointptr = apex(tetloop);
    setpoint2tet(pointptr, encode(tetloop));
    pointptr = oppo(tetloop);
    setpoint2tet(pointptr, encode(tetloop));
    // Get the next tetrahedron in the list.
    tetloop.tet = tetrahedrontraverse();
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// makeindex2pointmap()    Create a map from index to vertices.              //
//                                                                           //
// 'idx2verlist' returns the created map.  Traverse all vertices, a pointer  //
// to each vertex is set into the array.  The pointer to the first vertex is //
// saved in 'idx2verlist[0]'.  Don't forget to minus 'in->firstnumber' when  //
// to get the vertex form its index.                                         //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::makeindex2pointmap(point*& idx2verlist)
{
  point pointloop;
  int idx;

  if (b->verbose) {
    printf("  Constructing mapping from indices to points.\n");
  }

  idx2verlist = new point[points->items];

  points->traversalinit();
  pointloop = pointtraverse();
  idx = 0;
  while (pointloop != (point) NULL) {
    idx2verlist[idx] = pointloop;
    idx++;
    pointloop = pointtraverse();
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// makesegmentmap()    Create a map from vertices (their indices) to         //
//                     segments incident at the same vertices.               //
//                                                                           //
// Two arrays 'idx2seglist' and 'segsperverlist' together return the map.    //
// They form a sparse matrix structure with size (n + 1) x (n + 1), n is the //
// number of segments.  idx2seglist contains row information and             //
// segsperverlist contains all (non-zero) elements.  The i-th entry of       //
// idx2seglist is the starting position of i-th row's (non-zero) elements in //
// segsperverlist.  The number of elements of i-th row is calculated by the  //
// (i+1)-th entry minus i-th entry of idx2seglist.                           //
//                                                                           //
// NOTE: These two arrays will be created inside this routine, don't forget  //
// to free them after using.                                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::
makesegmentmap(int*& idx2seglist, shellface**& segsperverlist)
{
  shellface *shloop;
  int i, j, k;

  if (b->verbose) {
    printf("  Constructing mapping from points to segments.\n");
  }

  // Create and initialize 'idx2seglist'.
  idx2seglist = new int[points->items + 1];
  for (i = 0; i < points->items + 1; i++) {
    idx2seglist[i] = 0;
  }

  // Loop the set of segments once, counter the number of segments sharing
  //   each vertex.
  subsegs->traversalinit();
  shloop = shellfacetraverse(subsegs);
  while (shloop != (shellface *) NULL) {
    // Increment the number of sharing segments for each endpoint.
    for (i = 0; i < 2; i++) {
      j = pointmark((point) shloop[3 + i]) - in->firstnumber;
      idx2seglist[j]++;
    }
    shloop = shellfacetraverse(subsegs);
  }

  // Calculate the total length of array 'facesperverlist'.
  j = idx2seglist[0];
  idx2seglist[0] = 0;  // Array starts from 0 element.
  for (i = 0; i < points->items; i++) {
    k = idx2seglist[i + 1];
    idx2seglist[i + 1] = idx2seglist[i] + j;
    j = k;
  }
  // The total length is in the last unit of idx2seglist.
  segsperverlist = new shellface*[idx2seglist[i]];
  // Loop the set of segments again, set the info. of segments per vertex.
  subsegs->traversalinit();
  shloop = shellfacetraverse(subsegs);
  while (shloop != (shellface *) NULL) {
    for (i = 0; i < 2; i++) {
      j = pointmark((point) shloop[3 + i]) - in->firstnumber;
      segsperverlist[idx2seglist[j]] = shloop;
      idx2seglist[j]++;
    }
    shloop = shellfacetraverse(subsegs);
  }
  // Contents in 'idx2seglist' are shifted, now shift them back.
  for (i = points->items - 1; i >= 0; i--) {
    idx2seglist[i + 1] = idx2seglist[i];
  }
  idx2seglist[0] = 0;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// makesubfacemap()    Create a map from vertices (their indices) to         //
//                     subfaces incident at the same vertices.               //
//                                                                           //
// Two arrays 'idx2facelist' and 'facesperverlist' together return the map.  //
// They form a sparse matrix structure with size (n + 1) x (n + 1), n is the //
// number of subfaces.  idx2facelist contains row information and            //
// facesperverlist contains all (non-zero) elements.  The i-th entry of      //
// idx2facelist is the starting position of i-th row's(non-zero) elements in //
// facesperverlist.  The number of elements of i-th row is calculated by the //
// (i+1)-th entry minus i-th entry of idx2facelist.                          //
//                                                                           //
// NOTE: These two arrays will be created inside this routine, don't forget  //
// to free them after using.                                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::
makesubfacemap(int*& idx2facelist, shellface**& facesperverlist)
{
  shellface *shloop;
  int i, j, k;

  if (b->verbose) {
    printf("  Constructing mapping from points to subfaces.\n");
  }

  // Create and initialize 'idx2facelist'.
  idx2facelist = new int[points->items + 1];
  for (i = 0; i < points->items + 1; i++) {
    idx2facelist[i] = 0;
  }

  // Loop the set of subfaces once, counter the number of subfaces sharing
  //   each vertex.
  subfaces->traversalinit();
  shloop = shellfacetraverse(subfaces);
  while (shloop != (shellface *) NULL) {
    // Increment the number of sharing segments for each endpoint.
    for (i = 0; i < 3; i++) {
      j = pointmark((point) shloop[3 + i]) - in->firstnumber;
      idx2facelist[j]++;
    }
    shloop = shellfacetraverse(subfaces);
  }

  // Calculate the total length of array 'facesperverlist'.
  j = idx2facelist[0];
  idx2facelist[0] = 0;  // Array starts from 0 element.
  for (i = 0; i < points->items; i++) {
    k = idx2facelist[i + 1];
    idx2facelist[i + 1] = idx2facelist[i] + j;
    j = k;
  }
  // The total length is in the last unit of idx2facelist.
  facesperverlist = new shellface*[idx2facelist[i]];
  // Loop the set of segments again, set the info. of segments per vertex.
  subfaces->traversalinit();
  shloop = shellfacetraverse(subfaces);
  while (shloop != (shellface *) NULL) {
    for (i = 0; i < 3; i++) {
      j = pointmark((point) shloop[3 + i]) - in->firstnumber;
      facesperverlist[idx2facelist[j]] = shloop;
      idx2facelist[j]++;
    }
    shloop = shellfacetraverse(subfaces);
  }
  // Contents in 'idx2facelist' are shifted, now shift them back.
  for (i = points->items - 1; i >= 0; i--) {
    idx2facelist[i + 1] = idx2facelist[i];
  }
  idx2facelist[0] = 0;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// maketetrahedronmap()    Create a map from vertices (their indices) to     //
//                         tetrahedra incident at the same vertices.         //
//                                                                           //
// Two arrays 'idx2tetlist' and 'tetsperverlist' together return the map.    //
// They form a sparse matrix structure with size (n + 1) x (n + 1), n is the //
// number of tetrahedra.  idx2tetlist contains row information and           //
// tetsperverlist contains all (non-zero) elements.  The i-th entry of       //
// idx2tetlist is the starting position of i-th row's (non-zero) elements in //
// tetsperverlist.  The number of elements of i-th row is calculated by the  //
// (i+1)-th entry minus i-th entry of idx2tetlist.                           //
//                                                                           //
// NOTE: These two arrays will be created inside this routine, don't forget  //
// to free them after using.                                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::
maketetrahedronmap(int*& idx2tetlist, tetrahedron**& tetsperverlist)
{
  tetrahedron *tetloop;
  int i, j, k;

  if (b->verbose) {
    printf("  Constructing mapping from points to tetrahedra.\n");
  }

  // Create and initialize 'idx2tetlist'.
  idx2tetlist = new int[points->items + 1];
  for (i = 0; i < points->items + 1; i++) {
    idx2tetlist[i] = 0;
  }

  // Loop the set of tetrahedra once, counter the number of tetrahedra
  //   sharing each vertex.
  tetrahedrons->traversalinit();
  tetloop = tetrahedrontraverse();
  while (tetloop != (tetrahedron *) NULL) {
    // Increment the number of sharing tetrahedra for each endpoint.
    for (i = 0; i < 4; i++) {
      j = pointmark((point) tetloop[4 + i]) - in->firstnumber;
      idx2tetlist[j]++;
    }
    tetloop = tetrahedrontraverse();
  }

  // Calculate the total length of array 'tetsperverlist'.
  j = idx2tetlist[0];
  idx2tetlist[0] = 0;  // Array starts from 0 element.
  for (i = 0; i < points->items; i++) {
    k = idx2tetlist[i + 1];
    idx2tetlist[i + 1] = idx2tetlist[i] + j;
    j = k;
  }
  // The total length is in the last unit of idx2tetlist.
  tetsperverlist = new tetrahedron*[idx2tetlist[i]];
  // Loop the set of tetrahedra again, set the info. of tet. per vertex.
  tetrahedrons->traversalinit();
  tetloop = tetrahedrontraverse();
  while (tetloop != (tetrahedron *) NULL) {
    for (i = 0; i < 4; i++) {
      j = pointmark((point) tetloop[4 + i]) - in->firstnumber;
      tetsperverlist[idx2tetlist[j]] = tetloop;
      idx2tetlist[j]++;
    }
    tetloop = tetrahedrontraverse();
  }
  // Contents in 'idx2tetlist' are shifted, now shift them back.
  for (i = points->items - 1; i >= 0; i--) {
    idx2tetlist[i + 1] = idx2tetlist[i];
  }
  idx2tetlist[0] = 0;
}

//
// End of mesh items searching routines
//

//
// Begin of linear algebra functions
//

// dot() returns the dot product: v1 dot v2.

inline REAL tetgenmesh::dot(REAL* v1, REAL* v2) 
{
  return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
}

// cross() computes the cross product: n = v1 cross v2.

inline void tetgenmesh::cross(REAL* v1, REAL* v2, REAL* n) 
{
  n[0] =   v1[1] * v2[2] - v2[1] * v1[2];
  n[1] = -(v1[0] * v2[2] - v2[0] * v1[2]);
  n[2] =   v1[0] * v2[1] - v2[0] * v1[1];
}

// initm44() initializes a 4x4 matrix.
void tetgenmesh::initm44(REAL a00, REAL a01, REAL a02, REAL a03,
                         REAL a10, REAL a11, REAL a12, REAL a13,
                         REAL a20, REAL a21, REAL a22, REAL a23,
                         REAL a30, REAL a31, REAL a32, REAL a33,
                         REAL M[4][4])
{
  M[0][0] = a00; M[0][1] = a01; M[0][2] = a02; M[0][3] = a03;
  M[1][0] = a10; M[1][1] = a11; M[1][2] = a12; M[1][3] = a13;
  M[2][0] = a20; M[2][1] = a21; M[2][2] = a22; M[2][3] = a23;
  M[3][0] = a30; M[3][1] = a31; M[3][2] = a32; M[3][3] = a33;
}

// m4xm4() multiplies 2 4x4 matrics:  m1 = m1 * m2.
void tetgenmesh::m4xm4(REAL m1[4][4], REAL m2[4][4])
{
  REAL tmp[4];
  int i, j;

  for (i = 0; i < 4; i++) {   // i-th row
    for (j = 0; j < 4; j++) { // j-th col
      tmp[j] = m1[i][0] * m2[0][j] + m1[i][1] * m2[1][j] 
             + m1[i][2] * m2[2][j] + m1[i][3] * m2[3][j];
    }
    for (j = 0; j < 4; j++) 
      m1[i][j] = tmp[j];
  }
}

// m4xv4() multiplies a 4x4 matrix and 4x1 vector: v2 = m * v1
void tetgenmesh::m4xv4(REAL v2[4], REAL m[4][4], REAL v1[4])
{
  v2[0] = m[0][0]*v1[0] + m[0][1]*v1[1] + m[0][2]*v1[2] + m[0][3]*v1[3];
  v2[1] = m[1][0]*v1[0] + m[1][1]*v1[1] + m[1][2]*v1[2] + m[1][3]*v1[3];
  v2[2] = m[2][0]*v1[0] + m[2][1]*v1[1] + m[2][2]*v1[2] + m[2][3]*v1[3];
  v2[3] = m[3][0]*v1[0] + m[3][1]*v1[1] + m[3][2]*v1[2] + m[3][3]*v1[3];
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// lu_decmp()    Compute the LU decomposition of a matrix.                   //
//                                                                           //
// Compute the LU decomposition of a (non-singular) square matrix A using    //
// partial pivoting and implicit row exchanges.  The result is:              //
//     A = P * L * U,                                                        //
// where P is a permutation matrix, L is unit lower triangular, and U is     //
// upper triangular.  The factored form of A is used in combination with     //
// 'lu_solve()' to solve linear equations: Ax = b, or invert a matrix.       //
//                                                                           //
// The inputs are a square matrix 'lu[N..n+N-1][N..n+N-1]', it's size is 'n'.//
// On output, 'lu' is replaced by the LU decomposition of a rowwise permuta- //
// tion of itself, 'ps[N..n+N-1]' is an output vector that records the row   //
// permutation effected by the partial pivoting, effectively,  'ps' array    //
// tells the user what the permutation matrix P is; 'd' is output as +1/-1   //
// depending on whether the number of row interchanges was even or odd,      //
// respectively.                                                             //
//                                                                           //
// Return true if the LU decomposition is successfully computed, otherwise,  //
// return false in case that A is a singular matrix.                         //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenmesh::lu_decmp(REAL lu[4][4], int n, int* ps, REAL* d, int N)
{
  REAL scales[4];
  REAL pivot, biggest, mult, tempf;
  int pivotindex = 0;
  int i, j, k;

  *d = 1.0;                                      // No row interchanges yet.

  for (i = N; i < n + N; i++) {                             // For each row.
    // Find the largest element in each row for row equilibration
    biggest = 0.0;
    for (j = N; j < n + N; j++)
      if (biggest < (tempf = fabs(lu[i][j])))
        biggest  = tempf;
    if (biggest != 0.0)
      scales[i] = 1.0 / biggest;
    else {
      scales[i] = 0.0;
      return false;                            // Zero row: singular matrix.
    }
    ps[i] = i;                                 // Initialize pivot sequence.
  }

  for (k = N; k < n + N - 1; k++) {                      // For each column.
    // Find the largest element in each column to pivot around.
    biggest = 0.0;
    for (i = k; i < n + N; i++) {
      if (biggest < (tempf = fabs(lu[ps[i]][k]) * scales[ps[i]])) {
        biggest = tempf;
        pivotindex = i;
      }
    }
    if (biggest == 0.0) {
      return false;                         // Zero column: singular matrix.
    }
    if (pivotindex != k) {                         // Update pivot sequence.
      j = ps[k];
      ps[k] = ps[pivotindex];
      ps[pivotindex] = j;
      *d = -(*d);                          // ...and change the parity of d.
    }

    // Pivot, eliminating an extra variable  each time
    pivot = lu[ps[k]][k];
    for (i = k + 1; i < n + N; i++) {
      lu[ps[i]][k] = mult = lu[ps[i]][k] / pivot;
      if (mult != 0.0) {
        for (j = k + 1; j < n + N; j++)
          lu[ps[i]][j] -= mult * lu[ps[k]][j];
      }
    }
  }

  // (lu[ps[n + N - 1]][n + N - 1] == 0.0) ==> A is singular.
  return lu[ps[n + N - 1]][n + N - 1] != 0.0;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// lu_solve()    Solves the linear equation:  Ax = b,  after the matrix A    //
//               has been decomposed into the lower and upper triangular     //
//               matrices L and U, where A = LU.                             //
//                                                                           //
// 'lu[N..n+N-1][N..n+N-1]' is input, not as the matrix 'A' but rather as    //
// its LU decomposition, computed by the routine 'lu_decmp'; 'ps[N..n+N-1]'  //
// is input as the permutation vector returned by 'lu_decmp';  'b[N..n+N-1]' //
// is input as the right-hand side vector, and returns with the solution     //
// vector. 'lu', 'n', and 'ps' are not modified by this routine and can be   //
// left in place for successive calls with different right-hand sides 'b'.   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::lu_solve(REAL lu[4][4], int n, int* ps, REAL* b, int N)
{
  int i, j;
  REAL X[4], dot;

  for (i = N; i < n + N; i++) X[i] = 0.0;

  // Vector reduction using U triangular matrix.
  for (i = N; i < n + N; i++) {
    dot = 0.0;
    for (j = N; j < i + N; j++)
      dot += lu[ps[i]][j] * X[j];
    X[i] = b[ps[i]] - dot;
  }

  // Back substitution, in L triangular matrix.
  for (i = n + N - 1; i >= N; i--) {
    dot = 0.0;
    for (j = i + 1; j < n + N; j++)
      dot += lu[ps[i]][j] * X[j];
    X[i] = (X[i] - dot) / lu[ps[i]][i];
  }

  for (i = N; i < n + N; i++) b[i] = X[i];
}

//
// End of linear algebra functions
//

//
// Begin of geometric tests
//

// All the following routines require the input objects are not degenerate.
//   i.e., a triangle must has three non-collinear corners; an edge must
//   has two identical endpoints.  Degenerate cases should have to detect
//   first and then handled as special cases.

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// edge_vert_col_inter()    Test whether an edge (ab) and a collinear vertex //
//                          (p) are intersecting or not.                     //
//                                                                           //
// Possible cases are p is coincident to a (p = a), or to b (p = b), or p is //
// inside ab (a < p < b), or outside ab (p < a or p > b). These cases can be //
// quickly determined by comparing the corresponding coords of a, b, and p   //
// (which are not all equal).                                                //
//                                                                           //
// The return value indicates one of the three cases: DISJOINT, SHAREVERTEX  //
// (p = a or p = b), and INTERSECT (a < p < b).                              //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

enum tetgenmesh::interresult tetgenmesh::
edge_vert_col_inter(REAL* A, REAL* B, REAL* P)
{
  int i = 0;
  do {
    if (A[i] < B[i]) {
      if (P[i] < A[i]) {
        return DISJOINT;
      } else if (P[i] > A[i]) {
        if (P[i] < B[i]) {
          return INTERSECT;
        } else if (P[i] > B[i]) {
          return DISJOINT;
        } else {
          // assert(P[i] == B[i]);
          return SHAREVERTEX;
        }
      } else {
        // assert(P[i] == A[i]);
        return SHAREVERTEX;
      }
    } else if (A[i] > B[i]) {
      if (P[i] < B[i]) {
        return DISJOINT;
      } else if (P[i] > B[i]) {
        if (P[i] < A[i]) {
          return INTERSECT;
        } else if (P[i] > A[i]) {
          return DISJOINT;
        } else {
          // assert(P[i] == A[i]);
          return SHAREVERTEX;
        }
      } else {
        // assert(P[i] == B[i]);
        return SHAREVERTEX;
      }
    }
    // i-th coordinates are equal, try i+1-th;
    i++;
  } while (i < 3);
  // Should never be here.
  assert(i >= 3);
  return DISJOINT;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// edge_edge_cop_inter()    Test whether two coplanar edges (ab, and pq) are //
//                          intersecting or not.                             //
//                                                                           //
// Possible cases are ab and pq are disjointed, or proper intersecting (int- //
// ersect at a point other than their endpoints), or both collinear and int- //
// ersecting, or sharing at a common endpoint, or are coincident.            //
//                                                                           //
// A reference point R is required, which is exactly not coplanar with these //
// two edges.  Since the caller knows these two edges are coplanar, it must  //
// be able to provide (or calculate) such a point.                           //
//                                                                           //
// The return value indicates one of the four cases: DISJOINT, SHAREVERTEX,  //
// SHAREEDGE, and INTERSECT.                                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

enum tetgenmesh::interresult tetgenmesh:: 
edge_edge_cop_inter(REAL* A, REAL* B, REAL* P, REAL* Q, REAL* R)
{
  REAL s1, s2, s3, s4;

  assert(R != NULL);
  
  s1 = orient3d(A, B, R, P);
  s2 = orient3d(A, B, R, Q);
  if (s1 * s2 > 0.0) {
    // Both p and q are at the same side of ab.
    return DISJOINT;
  }
  s3 = orient3d(P, Q, R, A);
  s4 = orient3d(P, Q, R, B);
  if (s3 * s4 > 0.0) {
    // Both a and b are at the same side of pq.
    return DISJOINT;
  }

  // Possible degenerate cases are:
  //   (1) Only one of p and q is collinear with ab;
  //   (2) Both p and q are collinear with ab;
  //   (3) Only one of a and b is collinear with pq. 
  enum interresult abp, abq;
  enum interresult pqa, pqb;

  if (s1 == 0.0) {
    // p is collinear with ab.
    abp = edge_vert_col_inter(A, B, P);
    if (abp == INTERSECT) {
      // p is inside ab.
      return INTERSECT;
    }
    if (s2 == 0.0) {
      // q is collinear with ab. Case (2).
      abq = edge_vert_col_inter(A, B, Q);
      if (abq == INTERSECT) {
        // q is inside ab.
        return INTERSECT;
      }
      if (abp == SHAREVERTEX && abq == SHAREVERTEX) {
        // ab and pq are identical.
        return SHAREEDGE;
      }
      pqa = edge_vert_col_inter(P, Q, A);
      if (pqa == INTERSECT) {
        // a is inside pq.
        return INTERSECT;
      }
      pqb = edge_vert_col_inter(P, Q, B);
      if (pqb == INTERSECT) {
        // b is inside pq.
        return INTERSECT;
      }
      if (abp == SHAREVERTEX || abq == SHAREVERTEX) {
        // either p or q is coincident with a or b.
        // ONLY one case is possible, otherwise, shoule be SHAREEDGE.
        assert(abp ^ abq);
        return SHAREVERTEX;
      }
      // The last case. They are disjointed.
      assert((abp == DISJOINT) && (abp == abq && abq == pqa && pqa == pqb));
      return DISJOINT;
    } else {
      // p is collinear with ab. Case (1).
      assert(abp == SHAREVERTEX || abp == DISJOINT);
      return abp;
    }
  }
  // p is NOT collinear with ab.
  if (s2 == 0.0) {
    // q is collinear with ab. Case (1).
    abq = edge_vert_col_inter(A, B, Q);
    assert(abq == SHAREVERTEX || abq == DISJOINT || abq == INTERSECT);
    return abq;
  }

  // We have found p and q are not collinear with ab. However, it is still
  //   possible that a or b is collinear with pq (ONLY one of a and b).
  if (s3 == 0.0) {
    // a is collinear with pq. Case (3).
    assert(s4 != 0.0);
    pqa = edge_vert_col_inter(P, Q, A);
    // This case should have been detected in above.
    assert(pqa != SHAREVERTEX);
    assert(pqa == INTERSECT || pqa == DISJOINT);
    return pqa;
  }
  if (s4 == 0.0) {
    // b is collinear with pq. Case (3).
    assert(s3 != 0.0);
    pqb = edge_vert_col_inter(P, Q, B);
    // This case should have been detected in above.
    assert(pqb != SHAREVERTEX);
    assert(pqb == INTERSECT || pqb == DISJOINT);
    return pqb;
  }

  // ab and pq are intersecting properly.
  return INTERSECT;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Notations                                                                 //
//                                                                           //
// Let ABC be the plane passes through a, b, and c;  ABC+ be the halfspace   //
// including the set of all points x, such that orient3d(a, b, c, x) > 0;    //
// ABC- be the other halfspace, such that for each point x in ABC-,          //
// orient3d(a, b, c, x) < 0.  For the set of x which are on ABC, orient3d(a, //
// b, c, x) = 0.                                                             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// tri_vert_copl_inter()    Test whether a triangle (abc) and a coplanar     //
//                          point (p) are intersecting or not.               //
//                                                                           //
// Possible cases are p is inside abc, or on an edge of, or coincident with  //
// a vertex of, or outside abc.                                              //
//                                                                           //
// A reference point R is required. R is exactly not coplanar with abc and p.//
// Since the caller knows they are coplanar, it must be able to provide (or  //
// calculate) such a point.                                                  //
//                                                                           //
// The return value indicates one of the four cases: DISJOINT, SHAREVERTEX,  //
// and INTERSECT.                                                            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

enum tetgenmesh::interresult tetgenmesh::
tri_vert_cop_inter(REAL* A, REAL* B, REAL* C, REAL* P, REAL* R)
{
  REAL s1, s2, s3;
  int sign;

  assert(R != (REAL *) NULL);

  // Adjust the orientation of a, b, c and r, so that we can assume that
  //   r is strictly in ABC- (i.e., r is above ABC wrt. right-hand rule).
  s1 = orient3d(A, B, C, R);
  assert(s1 != 0.0);
  sign = s1 < 0.0 ? 1 : -1;

  // Test starts from here.
  s1 = orient3d(A, B, R, P) * sign;
  if (s1 < 0.0) {
    // p is in ABR-.
    return DISJOINT;
  }
  s2 = orient3d(B, C, R, P) * sign;
  if (s2 < 0.0) {
    // p is in BCR-.
    return DISJOINT;
  }
  s3 = orient3d(C, A, R, P) * sign;
  if (s3 < 0.0) {
    // p is in CAR-.
    return DISJOINT;
  }
  if (s1 == 0.0) {
    // p is on ABR.
    if (s2 == 0.0) {
      // p is on BCR.
      assert(s3 > 0.0);
      // p is coincident with b.
      return SHAREVERTEX;
    }
    if (s3 == 0.0) {
      // p is on CAR.
      // p is coincident with a.
      return SHAREVERTEX;
    }
    // p is on edge ab.
    return INTERSECT;
  }
  // p is in ABR+.
  if (s2 == 0.0) {
    // p is on BCR.
    if (s3 == 0.0) {
      // p is on CAR.
      // p is coincident with c.
      return SHAREVERTEX;
    }
    // p is on edge bc.
    return INTERSECT;
  }
  if (s3 == 0.0) {
    // p is on CAR.
    // p is on edge ca.
    return INTERSECT;
  }

  // p is strictly inside abc.
  return INTERSECT;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// tri_edge_cop_inter()    Test whether a triangle (abc) and a coplanar edge //
//                         (pq) are intersecting or not.                     //
//                                                                           //
// A reference point R is required. R is exactly not coplanar with abc and   //
// pq.  Since the caller knows they are coplanar, it must be able to provide //
// (or calculate) such a point.                                              //
//                                                                           //
// The return value indicates one of the four cases: DISJOINT, SHAREVERTEX,  //
// SHAREEDGE, and INTERSECT.                                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

enum tetgenmesh::interresult tetgenmesh::
tri_edge_cop_inter(REAL* A, REAL* B, REAL* C, REAL* P, REAL* Q, REAL* R)
{
  enum interresult abpq, bcpq, capq;
  enum interresult abcp, abcq;

  // Test if pq is intersecting one of edges of abc.
  abpq = edge_edge_cop_inter(A, B, P, Q, R);
  if (abpq == INTERSECT || abpq == SHAREEDGE) {
    return abpq;
  }
  bcpq = edge_edge_cop_inter(B, C, P, Q, R);
  if (bcpq == INTERSECT || bcpq == SHAREEDGE) {
    return bcpq;
  }
  capq = edge_edge_cop_inter(C, A, P, Q, R);
  if (capq == INTERSECT || capq == SHAREEDGE) {
    return capq;
  }
  
  // Test if p and q is inside abc.
  abcp = tri_vert_cop_inter(A, B, C, P, R);
  if (abcp == INTERSECT) {
    return INTERSECT;
  }
  abcq = tri_vert_cop_inter(A, B, C, Q, R);
  if (abcq == INTERSECT) {
    return INTERSECT;
  }

  // Combine the test results of edge intersectings and triangle insides
  //   to detect whether abc and pq are sharing vertex or disjointed.
  if (abpq == SHAREVERTEX) {
    // p or q is coincident with a or b.
    assert(abcp ^ abcq);
    return SHAREVERTEX;
  }
  if (bcpq == SHAREVERTEX) {
    // p or q is coincident with b or c.
    assert(abcp ^ abcq);
    return SHAREVERTEX;
  }
  if (capq == SHAREVERTEX) {
    // p or q is coincident with c or a.
    assert(abcp ^ abcq);
    return SHAREVERTEX;
  }

  // They are disjointed.
  return DISJOINT;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// tri_edge_inter_tail()    Test whether a triangle (abc) and an edge (pq)   //
//                          are intersecting or not.                         //
//                                                                           //
// s1 and s2 are results of pre-performed orientation tests. s1 = orient3d(  //
// a, b, c, p); s2 = orient3d(a, b, c, q).  To separate this routine from    //
// tri_edge_inter() can save two orientation tests in tri_tri_inter().       //
//                                                                           //
// The return value indicates one of the four cases: DISJOINT, SHAREVERTEX,  //
// SHAREEDGE, and INTERSECT.                                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

enum tetgenmesh::interresult tetgenmesh::
tri_edge_inter_tail(REAL* A, REAL* B, REAL* C, REAL* P, REAL* Q, REAL s1,
                    REAL s2)
{
  REAL s3, s4, s5;
  int sign;

  if (s1 * s2 > 0.0) {
    // p, q are at the same halfspace of ABC, no intersection.
    return DISJOINT;
  }

  if (s1 * s2 < 0.0) {
    // p, q are both not on ABC (and not sharing vertices, edges of abc).
    // Adjust the orientation of a, b, c and p, so that we can assume that
    //   p is strictly in ABC-, and q is strictly in ABC+.
    sign = s1 < 0.0 ? 1 : -1;
    s3 = orient3d(A, B, P, Q) * sign;
    if (s3 < 0.0) {
      // q is at ABP-.
      return DISJOINT;
    }
    s4 = orient3d(B, C, P, Q) * sign;
    if (s4 < 0.0) {
      // q is at BCP-.
      return DISJOINT;
    }
    s5 = orient3d(C, A, P, Q) * sign;
    if (s5 < 0.0) {
      // q is at CAP-.
      return DISJOINT;
    }
    if (s3 == 0.0) {
      // q is on ABP.
      if (s4 == 0.0) {
        // q is on BCP (and q must in CAP+).
        assert(s5 > 0.0); 
        // pq intersects abc at vertex b.
        return SHAREVERTEX;
      }
      if (s5 == 0.0) {
        // q is on CAP (and q must in BCP+).
        // pq intersects abc at vertex a.
        return SHAREVERTEX;
      }
      // q in both BCP+ and CAP+.
      // pq crosses ab properly.
      return INTERSECT;
    }
    // q is in ABP+;
    if (s4 == 0.0) {
      // q is on BCP.
      if (s5 == 0.0) {
        // q is on CAP.
        // pq intersects abc at vertex c.
        return SHAREVERTEX;
      }
      // pq crosses bc properly.
      return INTERSECT;
    }
    // q is in BCP+;
    if (s5 == 0.0) {
      // q is on CAP.
      // pq crosses ca properly.
      return INTERSECT;
    }
    // q is in CAP+;
    // pq crosses abc properly.
    return INTERSECT;
  }

  if (s1 != 0.0 || s2 != 0.0) {
    // Either p or q is coplanar with abc. ONLY one of them is possible.
    if (s1 == 0.0) {
      // p is coplanar with abc, q can be used as reference point.
      assert(s2 != 0.0);
      return tri_vert_cop_inter(A, B, C, P, Q);
    } else {
      // q is coplanar with abc, p can be used as reference point.
      assert(s2 == 0.0);
      return tri_vert_cop_inter(A, B, C, Q, P);
    }
  }

  // pq is coplanar with abc.  Calculate a point which is exactly not
  //   coplanar with a, b, and c.
  REAL R[3], N[3];
  REAL ax, ay, az, bx, by, bz;
  
  ax = A[0] - B[0];
  ay = A[1] - B[1];
  az = A[2] - B[2];
  bx = A[0] - C[0];
  by = A[1] - C[1];
  bz = A[2] - C[2];
  N[0] = ay * bz - by * az;
  N[1] = az * bx - bz * ax;
  N[2] = ax * by - bx * ay;
  // The normal should not be a zero vector (otherwise, abc are collinear).
  assert((fabs(N[0]) + fabs(N[1]) + fabs(N[2])) > 0.0);
  // The reference point R is lifted from A to the normal direction with
  //   a distance d = average edge length of the triangle abc.
  R[0] = N[0] + A[0];
  R[1] = N[1] + A[1];
  R[2] = N[2] + A[2];
  // Becareful the case: if the non-zero component(s) in N is smaller than
  //   the machine epsilon (i.e., 2^(-16) for double), R will exactly equal
  //   to A due to the round-off error.  Do check if it is.
  if (R[0] == A[0] && R[1] == A[1] && R[2] == A[2]) {
    int i, j;
    for (i = 0; i < 3; i++) {
      assert (R[i] == A[i]);
      j = 2;
      do {
        if (N[i] > 0.0) {
          N[i] += (j * macheps);
        } else {
          N[i] -= (j * macheps);
        }
        R[i] = N[i] + A[i];
        j *= 2;
      } while (R[i] == A[i]);
    }
  }

  return tri_edge_cop_inter(A, B, C, P, Q, R);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// tri_edge_inter()    Test whether a triangle (abc) and an edge (pq) are    //
//                     intersecting or not.                                  //
//                                                                           //
// The return value indicates one of the four cases: DISJOINT, SHAREVERTEX,  //
// SHAREEDGE, and INTERSECT.                                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

enum tetgenmesh::interresult tetgenmesh::
tri_edge_inter(REAL* A, REAL* B, REAL* C, REAL* P, REAL* Q)
{
  REAL s1, s2;

  // Test the locations of p and q with respect to ABC.
  s1 = orient3d(A, B, C, P);
  s2 = orient3d(A, B, C, Q);

  return tri_edge_inter_tail(A, B, C, P, Q, s1, s2);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// tri_tri_inter()    Test whether two triangle (abc) and (opq) are          //
//                    intersecting or not.                                   //
//                                                                           //
// The return value indicates one of the five cases: DISJOINT, SHAREVERTEX,  //
// SHAREEDGE, SHAREFACE, and INTERSECT.                                      //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

enum tetgenmesh::interresult tetgenmesh::
tri_tri_inter(REAL* A, REAL* B, REAL* C, REAL* O, REAL* P, REAL* Q)
{
  REAL s_o, s_p, s_q;
  REAL s_a, s_b, s_c;

  s_o = orient3d(A, B, C, O);
  s_p = orient3d(A, B, C, P);
  s_q = orient3d(A, B, C, Q);
  if ((s_o * s_p > 0.0) && (s_o * s_q > 0.0)) {
    // o, p, q are all in the same halfspace of ABC.
    return DISJOINT;
  }

  s_a = orient3d(O, P, Q, A);
  s_b = orient3d(O, P, Q, B);
  s_c = orient3d(O, P, Q, C);
  if ((s_a * s_b > 0.0) && (s_a * s_c > 0.0)) {
    // a, b, c are all in the same halfspace of OPQ.
    return DISJOINT;
  }

  enum interresult abcop, abcpq, abcqo;
  int shareedge = 0;

  abcop = tri_edge_inter_tail(A, B, C, O, P, s_o, s_p);
  if (abcop == INTERSECT) {
    return INTERSECT;
  } else if (abcop == SHAREEDGE) {
    shareedge++;
  }
  abcpq = tri_edge_inter_tail(A, B, C, P, Q, s_p, s_q);
  if (abcpq == INTERSECT) {
    return INTERSECT;
  } else if (abcpq == SHAREEDGE) {
    shareedge++;
  }
  abcqo = tri_edge_inter_tail(A, B, C, Q, O, s_q, s_o);
  if (abcqo == INTERSECT) {
    return INTERSECT;
  } else if (abcqo == SHAREEDGE) {
    shareedge++;
  }
  if (shareedge == 3) {
    // opq are coincident with abc.
    return SHAREFACE;
  }
  // It is only possible either no share edge or one.
  assert(shareedge == 0 || shareedge == 1);

  // Continue to detect whether opq and abc are intersecting or not.
  enum interresult opqab, opqbc, opqca;

  opqab = tri_edge_inter_tail(O, P, Q, A, B, s_a, s_b);
  if (opqab == INTERSECT) {
    return INTERSECT;
  }
  opqbc = tri_edge_inter_tail(O, P, Q, B, C, s_b, s_c);
  if (opqbc == INTERSECT) {
    return INTERSECT;
  }
  opqca = tri_edge_inter_tail(O, P, Q, C, A, s_c, s_a);
  if (opqca == INTERSECT) {
    return INTERSECT;
  }

  // At this point, two triangles are not intersecting and not coincident.
  //   They may be share an edge, or share a vertex, or disjoint.
  if (abcop == SHAREEDGE) {
    assert(abcpq == SHAREVERTEX && abcqo == SHAREVERTEX);
    // op is coincident with an edge of abc.
    return SHAREEDGE;
  }
  if (abcpq == SHAREEDGE) {
    assert(abcop == SHAREVERTEX && abcqo == SHAREVERTEX);
    // pq is coincident with an edge of abc.
    return SHAREEDGE;
  }
  if (abcqo == SHAREEDGE) {
    assert(abcop == SHAREVERTEX && abcpq == SHAREVERTEX);
    // qo is coincident with an edge of abc.
    return SHAREEDGE;
  }

  // They may share a vertex or disjoint.
  if (abcop == SHAREVERTEX) {
    // o or p is coincident with a vertex of abc.
    if (abcpq == SHAREVERTEX) {
      // p is the coincident vertex.
      assert(abcqo != SHAREVERTEX);
    } else {
      // o is the coincident vertex.
      assert(abcqo == SHAREVERTEX);
    }
    return SHAREVERTEX;
  }
  if (abcpq == SHAREVERTEX) {
    // q is the coincident vertex.
    assert(abcqo == SHAREVERTEX);
    return SHAREVERTEX;
  }

  // They are disjoint.
  return DISJOINT;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// iscollinear()    Check if three points are approximately collinear.       //
//                                                                           //
// 'eps' is a relative error tolerance.  The collinearity is determined by   //
// the value q = cos(theta), where theta is the angle between two vectors    //
// A->B and A->C.  They're collinear if 1.0 - q <= epspp.                    //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenmesh::iscollinear(REAL* A, REAL* B, REAL* C, REAL eps)
{
  REAL abx, aby, abz;
  REAL acx, acy, acz;
  REAL Lv, Lw, dd;
  REAL d, q;

  abx = A[0] - B[0];
  aby = A[1] - B[1];
  abz = A[2] - B[2];
  acx = A[0] - C[0];
  acy = A[1] - C[1];
  acz = A[2] - C[2];
  Lv = abx * abx + aby * aby + abz * abz;
  Lw = acx * acx + acy * acy + acz * acz;
  dd = abx * acx + aby * acy + abz * acz;
  
  d = (dd * dd) / (Lv * Lw);
  if (d > 1.0) d = 1.0; // Rounding.
  q = 1.0 - sqrt(d); // Notice 0 < q < 1.0.
  
  return q <= eps;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// iscoplanar()    Check if four points are approximately coplanar.          //
//                                                                           //
// 'vol6' is six times of the signed volume of the tetrahedron formed by the //
// four points. 'eps' is the relative error tolerance.  The coplanarity is   //
// determined by the value: q = fabs(vol6) / L^3,  where L is the average    //
// edge length of the tet. They're coplanar if q <= eps.                     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenmesh::
iscoplanar(REAL* k, REAL* l, REAL* m, REAL* n, REAL vol6, REAL eps)
{
  REAL L, q;
  REAL x, y, z;  

  x = k[0] - l[0];
  y = k[1] - l[1];
  z = k[2] - l[2];
  L = sqrt(x * x + y * y + z * z);
  x = l[0] - m[0];
  y = l[1] - m[1];
  z = l[2] - m[2];
  L += sqrt(x * x + y * y + z * z);
  x = m[0] - k[0];
  y = m[1] - k[1];
  z = m[2] - k[2];
  L += sqrt(x * x + y * y + z * z);
  x = k[0] - n[0];
  y = k[1] - n[1];
  z = k[2] - n[2];
  L += sqrt(x * x + y * y + z * z);
  x = l[0] - n[0];
  y = l[1] - n[1];
  z = l[2] - n[2];
  L += sqrt(x * x + y * y + z * z);
  x = m[0] - n[0];
  y = m[1] - n[1];
  z = m[2] - n[2];
  L += sqrt(x * x + y * y + z * z);
  assert(L > 0.0);
  L /= 6.0;
  q = fabs(vol6) / (L * L * L);
  
  return q <= eps;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// iscospheric()    Check if five points are approximately coplanar.         //
//                                                                           //
// 'vol24' is the 24 times of the signed volume of the 4-dimensional simplex //
// formed by the five points. 'eps' is the relative tolerance. The cosphere  //
// case is determined by the value: q = fabs(vol24) / L^4,  where L is the   //
// average edge length of the simplex. They're cosphere if q <= eps.         //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenmesh::
iscospheric(REAL* k, REAL* l, REAL* m, REAL* n, REAL* o, REAL vol24, REAL eps)
{
  REAL L, q;

  // A 4D simplex has 10 edges.
  L = distance(k, l);
  L += distance(l, m);
  L += distance(m, k);
  L += distance(k, n);
  L += distance(l, n);
  L += distance(m, n);
  L += distance(k, o);
  L += distance(l, o);
  L += distance(m, o);
  L += distance(n, o);
  assert(L > 0.0);
  L /= 10.0;
  q = fabs(vol24) / (L * L * L * L);

  return q < eps;
}

//
// End of geometric tests
//

//
// Begin of Geometric quantities calculators
//

// distance() computs the Euclidean distance between two points.
inline REAL tetgenmesh::distance(REAL* p1, REAL* p2)
{
  return sqrt((p2[0] - p1[0]) * (p2[0] - p1[0]) +
              (p2[1] - p1[1]) * (p2[1] - p1[1]) +
              (p2[2] - p1[2]) * (p2[2] - p1[2]));
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// shortdistance()    Returns the shortest distance from point p to a line   //
//                    defined by two points e1 and e2.                       //
//                                                                           //
// First compute the projection length l_p of the vector v1 = p - e1 along   //
// the vector v2 = e2 - e1. Then Pythagoras' Theorem is used to compute the  //
// shortest distance.                                                        //
//                                                                           //
// This routine allows that p is collinear with the line. In this case, the  //
// return value is zero. The two points e1 and e2 should not be identical.   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

REAL tetgenmesh::shortdistance(REAL* p, REAL* e1, REAL* e2)
{
  REAL v1[3], v2[3];
  REAL len, l_p;

  v1[0] = e2[0] - e1[0];
  v1[1] = e2[1] - e1[1];
  v1[2] = e2[2] - e1[2];
  v2[0] = p[0] - e1[0];
  v2[1] = p[1] - e1[1];
  v2[2] = p[2] - e1[2];

  len = sqrt(dot(v1, v1));
  assert(len != 0.0);
  v1[0] /= len;
  v1[1] /= len;
  v1[2] /= len;
  l_p = dot(v1, v2);

  return sqrt(dot(v2, v2) - l_p * l_p);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// interiorangle()    Return the interior angle (0 - 2 * PI) between vectors //
//                    o->p1 and o->p2.                                       //
//                                                                           //
// 'n' is the normal of the plane containing face (o, p1, p2).  The interior //
// angle is the total angle rotating from o->p1 around n to o->p2.  Exchange //
// the position of p1 and p2 will get the complement angle of the other one. //
// i.e., interiorangle(o, p1, p2) = 2 * PI - interiorangle(o, p2, p1).  Set  //
// 'n' be NULL if you only want the interior angle between 0 - PI.           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

REAL tetgenmesh::interiorangle(REAL* o, REAL* p1, REAL* p2, REAL* n)
{
  REAL v1[3], v2[3], np[3];
  REAL theta, costheta, lenlen;
  REAL ori, len1, len2;

  // Get the interior angle (0 - PI) between o->p1, and o->p2.
  v1[0] = p1[0] - o[0];
  v1[1] = p1[1] - o[1];
  v1[2] = p1[2] - o[2];
  v2[0] = p2[0] - o[0];
  v2[1] = p2[1] - o[1];
  v2[2] = p2[2] - o[2];
  len1 = sqrt(dot(v1, v1));
  len2 = sqrt(dot(v2, v2));
  lenlen = len1 * len2;
  assert(lenlen != 0.0);
  costheta = dot(v1, v2) / lenlen;
  if (costheta > 1.0) {
    costheta = 1.0; // Roundoff. 
  } else if (costheta < -1.0) {
    costheta = -1.0; // Roundoff. 
  }
  theta = acos(costheta);
  if (n != NULL) {
    // Get a point above the face (o, p1, p2);
    np[0] = o[0] + n[0];
    np[1] = o[1] + n[1];
    np[2] = o[2] + n[2];
    // Adjust theta (0 - 2 * PI).
    ori = orient3d(p1, o, np, p2);
    if (ori > 0.0) {
      theta = 2 * PI - theta;
    }
  }

  return theta;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// projpt2edge()    Return the projection point from a point to an edge.     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::projpt2edge(REAL* p, REAL* e1, REAL* e2, REAL* prj)
{
  REAL v1[3], v2[3];
  REAL len, l_p;

  v1[0] = e2[0] - e1[0];
  v1[1] = e2[1] - e1[1];
  v1[2] = e2[2] - e1[2];
  v2[0] = p[0] - e1[0];
  v2[1] = p[1] - e1[1];
  v2[2] = p[2] - e1[2];

  len = sqrt(dot(v1, v1));
  assert(len != 0.0);
  v1[0] /= len;
  v1[1] /= len;
  v1[2] /= len;
  l_p = dot(v1, v2);

  prj[0] = e1[0] + l_p * v1[0];
  prj[1] = e1[1] + l_p * v1[1];
  prj[2] = e1[2] + l_p * v1[2];
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// projpt2face()    Return the projection point from a point to a face.      //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::projpt2face(REAL* p, REAL* f1, REAL* f2, REAL* f3, REAL* prj)
{
  REAL fnormal[3], v1[3];
  REAL len, dist;

  // Get the unit face normal.
  facenormal(f1, f2, f3, fnormal, &len);
  assert(len > 0.0);
  fnormal[0] /= len;
  fnormal[1] /= len;
  fnormal[2] /= len;
  // Get the vector v1 = |p - f1|.
  v1[0] = p[0] - f1[0];
  v1[1] = p[1] - f1[1];
  v1[2] = p[2] - f1[2];
  // Get the project distance.
  dist = dot(fnormal, v1);
  assert(fabs(dist) >= b->epsilon);
  
  // Get the project point.
  prj[0] = p[0] - dist * fnormal[0];
  prj[1] = p[1] - dist * fnormal[1];
  prj[2] = p[2] - dist * fnormal[2];
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// facenormal()    Calculate the normal of a face given by three points.     //
//                                                                           //
// In general, the face normal can be calculate by the cross product of any  //
// pair of the three edge vectors.  However, if the three points are nearly  //
// collinear, the rounding error may harm the result. To choose a good pair  //
// of vectors is helpful to reduce the error.                                //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::facenormal(REAL* pa, REAL* pb, REAL* pc, REAL* n, REAL* nlen)
{
  REAL v1[3], v2[3];

  v1[0] = pb[0] - pa[0];
  v1[1] = pb[1] - pa[1];
  v1[2] = pb[2] - pa[2];
  v2[0] = pc[0] - pa[0];
  v2[1] = pc[1] - pa[1];
  v2[2] = pc[2] - pa[2];

  cross(v1, v2, n);
  if (nlen != (REAL *) NULL) {
    *nlen = sqrt(dot(n, n));
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// edgeorthonormal()    Return the unit normal of an edge in a given plane.  //
//                                                                           //
// The edge is from e1 to e2,  the plane is defined by given an additional   //
// point op, which is non-collinear with the edge.  In addition, the side of //
// the edge in which op lies defines the positive position of the normal.    //
//                                                                           //
// Let v1 be the unit vector from e1 to e2, v2 be the unit edge vector from  //
// e1 to op, fn be the unit face normal calculated by fn = v1 x v2. Then the //
// unit edge normal of e1e2 pointing to op is n = fn x v1.  Note, we should  //
// not change the position of fn and v1, otherwise, we get the edge normal   //
// pointing to the other side of op.                                         //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::edgeorthonormal(REAL* e1, REAL* e2, REAL* op, REAL* n)
{
  REAL v1[3], v2[3], fn[3];
  REAL len;

  // Get the edge vector v1.
  v1[0] = e2[0] - e1[0];
  v1[1] = e2[1] - e1[1];
  v1[2] = e2[2] - e1[2];
  // Get the edge vector v2.
  v2[0] = op[0] - e1[0];
  v2[1] = op[1] - e1[1];
  v2[2] = op[2] - e1[2];
  // Get the face normal fn = v1 x v2.
  cross(v1, v2, fn);
  // Get the edge normal n pointing to op. n = fn x v1.
  cross(fn, v1, n);
  // Normalize the vector.
  len = sqrt(dot(n, n));
  n[0] /= len;
  n[1] /= len;
  n[2] /= len;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// facedihedral()    Return the dihedral angle (in radian) between two       //
//                   adjoining faces.                                        //
//                                                                           //
// 'pa', 'pb' are the shared edge of these two faces, 'pc1', and 'pc2' are   //
// apexes of these two faces.  Return the angle (between 0 to 2*pi) between  //
// the normal of face (pa, pb, pc1) and normal of face (pa, pb, pc2).        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

REAL tetgenmesh::facedihedral(REAL* pa, REAL* pb, REAL* pc1, REAL* pc2)
{
  REAL n1[3], n2[3];
  REAL n1len, n2len;
  REAL costheta, ori;
  REAL theta;

  facenormal(pa, pb, pc1, n1, &n1len);
  facenormal(pa, pb, pc2, n2, &n2len);
  costheta = dot(n1, n2) / (n1len * n2len);
  // Be careful rounding error!
  if (costheta > 1.0) {
    costheta = 1.0;
  } else if (costheta < -1.0) {
    costheta = -1.0;
  }
  theta = acos(costheta);
  ori = orient3d(pa, pb, pc1, pc2);
  if (ori > 0.0) {
    theta = 2 * PI - theta;
  }

  return theta;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// tetalldihedral()    Get all(six) dihedral angles in tetrahedron formed by //
//                     vertices a, b, c and d. Return by array adDihed[6].   //
//                                                                           //
// The order in which the dihedrals are assigned matters for computation of  //
// solid angles. The way they're currently set up, combining them as (0,1,2),//
// (0,3,4), (1,3,5), (2,4,5) gives (in order) solid angles at vertices a, b, //
// c and d.                                                                  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::
tetalldihedral(point pa, point pb, point pc, point pd, REAL dihed[6])
{
  REAL n0[3], n1[3], n2[3], n3[3];
  REAL n0len, n1len, n2len, n3len;
  REAL dotp;
  
  facenormal(pc, pb, pd, n0, &n0len);
  facenormal(pa, pc, pd, n1, &n1len);
  facenormal(pb, pa, pd, n2, &n2len);
  facenormal(pa, pb, pc, n3, &n3len);
  
  n0[0] /= n0len; n0[1] /= n0len; n0[2] /= n0len;
  n1[0] /= n1len; n1[1] /= n1len; n1[2] /= n1len;
  n2[0] /= n2len; n2[1] /= n2len; n2[2] /= n2len;
  n3[0] /= n3len; n3[1] /= n3len; n3[2] /= n3len;

  dotp = -dot(n0, n1);
  if (dotp > 1.) dotp = 1.;
  else if (dotp < -1.) dotp = -1.;
  dihed[5] = acos(dotp); // Edge CD

  dotp = -dot(n0, n2);
  if (dotp > 1.) dotp = 1.;
  else if (dotp < -1.) dotp = -1.;
  dihed[4] = acos(dotp); // Edge BD

  dotp = -dot(n0, n3);
  if (dotp > 1.) dotp = 1.;
  else if (dotp < -1.) dotp = -1.;
  dihed[3] = acos(dotp); // Edge BC

  dotp = -dot(n1, n2);
  if (dotp > 1.) dotp = 1.;
  else if (dotp < -1.) dotp = -1.;
  dihed[2] = acos(dotp); // Edge AD

  dotp = -dot(n1, n3);
  if (dotp > 1.) dotp = 1.;
  else if (dotp < -1.) dotp = -1.;
  dihed[1] = acos(dotp); // Edge AC

  dotp = -dot(n2, n3);
  if (dotp > 1.) dotp = 1.;
  else if (dotp < -1.) dotp = -1.;
  dihed[0] = acos(dotp); // Edge AB
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// circumsphere()    Calculate the smallest circumsphere (center and radius) //
//                   of the given three or four points.                      //
//                                                                           //
// The circumsphere of four points (a tetrahedron) is unique if they are not //
// degenerate. If 'pd = NULL', the smallest circumsphere of three points is  //
// the diametral sphere of the triangle if they are not degenerate.          //
//                                                                           //
// Return TRUE if the input points are not degenerate and the circumcenter   //
// and circumradius are returned in 'cent' and 'radius' respectively if they //
// are not NULLs. Otherwise, return FALSE indicated the points are degenrate.//
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenmesh::
circumsphere(REAL* pa, REAL* pb, REAL* pc, REAL* pd, REAL* cent, REAL* radius)
{
  REAL A[4][4], rhs[4], D;
  int indx[4];

  // Compute the coefficient matrix A (3x3).
  A[0][0] = pb[0] - pa[0];
  A[0][1] = pb[1] - pa[1];
  A[0][2] = pb[2] - pa[2];
  A[1][0] = pc[0] - pa[0];
  A[1][1] = pc[1] - pa[1];
  A[1][2] = pc[2] - pa[2];
  if (pd != NULL) {
    A[2][0] = pd[0] - pa[0];
    A[2][1] = pd[1] - pa[1]; 
    A[2][2] = pd[2] - pa[2];
  } else {
    cross(A[0], A[1], A[2]);
  }

  // Compute the right hand side vector b (3x1).
  rhs[0] = 0.5 * dot(A[0], A[0]);
  rhs[1] = 0.5 * dot(A[1], A[1]);
  if (pd != NULL) {
    rhs[2] = 0.5 * dot(A[2], A[2]);
  } else {
    rhs[2] = 0.0;
  }

  // Solve the 3 by 3 equations use LU decomposition with partial pivoting
  //   and backward and forward substitute..
  if (!lu_decmp(A, 3, indx, &D, 0)) {
    if (radius != (REAL *) NULL) *radius = 0.0;
    return false;
  }    
  lu_solve(A, 3, indx, rhs, 0);
  if (cent != (REAL *) NULL) {
    cent[0] = pa[0] + rhs[0];
    cent[1] = pa[1] + rhs[1];
    cent[2] = pa[2] + rhs[2];
  }
  if (radius != (REAL *) NULL) {
    *radius = sqrt(rhs[0] * rhs[0] + rhs[1] * rhs[1] + rhs[2] * rhs[2]);
  }
  return true;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// inscribedsphere()    Compute the radius and center of the biggest         //
//                      inscribed sphere of a given tetrahedron.             //
//                                                                           //
// The tetrahedron is given by its four points, it must not be degenerate.   //
// The center and radius are returned in 'cent' and 'radius' respectively if //
// they are not NULLs.                                                       //
//                                                                           //
// Geometrical fact. For any simplex in d dimension,                         //
//   r/h1 + r/h2 + ... r/hn = 1 (n <= d + 1);                                //
// where r is the radius of inscribed ball, and h is the height of each side //
// of the simplex. The value of 'r/h' is just the barycenter coordinates of  //
// each vertex of the simplex. Therefore, we can compute the radius and      //
// center of the smallest inscribed ball as following equations:             //
//   r = 1.0 / (1/h1 + 1/h2 + ... + 1/hn);          (1)                      //
//   C = r/h1 * P1 + r/h2 * P2 + ... + r/hn * Pn;   (2)                      //
// where C is the vector of center, P1, P2, .. Pn are vectors of vertices.   //
// Here (2) contains n linear equations with n variables.  (h, P) must be a  //
// pair, h is the height from P to its opposite face.                        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::
inscribedsphere(REAL* pa, REAL* pb, REAL* pc, REAL* pd, REAL* cent, 
                REAL* radius)
{
  REAL A[4][4], rhs[4], D;
  REAL N[3][4], H[4];  // Normals (colume vectors) and heights of each face.
  REAL rd;
  int indx[4], i, j;  

  // Compute the normals of 4 faces.
  A[0][0] = pa[0] - pd[0];
  A[0][1] = pa[1] - pd[1];
  A[0][2] = pa[2] - pd[2];
  A[1][0] = pb[0] - pd[0];
  A[1][1] = pb[1] - pd[1];
  A[1][2] = pb[2] - pd[2];
  A[2][0] = pc[0] - pd[0];
  A[2][1] = pc[1] - pd[1];
  A[2][2] = pc[2] - pd[2];
  // Compute inverse of matrix A, to get the 3 normals of 4 faces.
  lu_decmp(A, 3, indx, &D, 0);     // Decompose the matrix just once.
  for (j = 0; j < 3; j++) {
    for (i = 0; i < 3; i++) rhs[i] = 0.0;
    rhs[j] = -1.0;
    lu_solve(A, 3, indx, rhs, 0);
    for (i = 0; i < 3; i++) N[i][j] = rhs[i];
  }
  // Compute the last normal by summing 3 computed vectors, because sum over 
  //   a closed sufrace is 0.
  N[0][3] = - N[0][0] - N[0][1] - N[0][2];
  N[1][3] = - N[1][0] - N[1][1] - N[1][2];
  N[2][3] = - N[2][0] - N[2][1] - N[2][2];
  // Compute the length of  normals.
  for (i = 0; i < 4; i++) {
    // H[i] is the inverse of height of its corresponding face.
    H[i] = sqrt(N[0][i] * N[0][i] + N[1][i] * N[1][i] + N[2][i] * N[2][i]);
  }
  // Compute the radius use eq. (1).
  rd = 1.0 / (H[0] + H[1] + H[2] + H[3]);
  if (radius != (REAL*) NULL) *radius = rd;
  if (cent != (REAL*) NULL) {
    // Compute the center use eq. (2).
    cent[0] = rd * (H[0] * pa[0] + H[1] * pb[0] + H[2] * pc[0] + H[3] * pd[0]);
    cent[1] = rd * (H[0] * pa[1] + H[1] * pb[1] + H[2] * pc[1] + H[3] * pd[1]);
    cent[2] = rd * (H[0] * pa[2] + H[1] * pb[2] + H[2] * pc[2] + H[3] * pd[2]);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// rotatepoint()    Create a point by rotating an existing point.            //
//                                                                           //
// Create a 3D point by rotating point 'p' with an angle 'rotangle' (in arc  //
// degree) around a rotating axis given by a vector from point 'p1' to 'p2'. //
// The rotation is according with right-hand rule, i.e., use your right-hand //
// to grab the axis with your thumber pointing to its positive direction,    //
// your fingers indicate the rotating direction.                             //
//                                                                           //
// The rotating steps are the following:                                     //
//   1. Translate vector 'p1->p2' to origin, M1;                             //
//   2. Rotate vector around the Y-axis until it lies in the YZ plane, M2;   //
//   3. Rotate vector around the X-axis until it lies on the Z axis, M3;     //
//   4. Perform the rotation of 'p' around the z-axis, M4;                   //
//   5. Undo Step 3, M5;                                                     //
//   6. Undo Step 2, M6;                                                     //
//   7. Undo Step 1, M7;                                                     //
// Use matrix multiplication to combine the above sequences, we get:         //
//   p0' = T * p0, where T = M7 * M6 * M5 * M4 * M3 * M2 * M1                //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::rotatepoint(REAL* p, REAL rotangle, REAL* p1, REAL* p2)
{
  REAL T[4][4], pp0[4], p0t[4], p2t[4];
  REAL roty, rotx, alphaR, projlen;
  REAL dx, dy, dz;

  initm44(1, 0, 0, -p1[0],
          0, 1, 0, -p1[1],
          0, 0, 1, -p1[2],
          0, 0, 0, 1, T);
  pp0[0] = p[0]; pp0[1] = p[1]; pp0[2] = p[2]; pp0[3] = 1.0;
  m4xv4(p0t, T, pp0); // Step 1
  pp0[0] = p2[0]; pp0[1] = p2[1]; pp0[2] = p2[2]; pp0[3] = 1.0;
  m4xv4(p2t, T, pp0); // Step 1

  // Get the rotation angle around y-axis;
  dx = p2t[0];
  dz = p2t[2];
  projlen = sqrt(dx * dx + dz * dz);
  if (projlen <= (b->epsilon * 1e-2) * longest) {
    roty = 0;
  } else {
    roty = acos(dz / projlen);
    if (dx < 0) {
      roty = -roty;
    }
  }

  initm44(cos(-roty), 0, sin(-roty), 0,
          0, 1, 0, 0,
          -sin(-roty), 0, cos(-roty), 0,
          0, 0, 0, 1, T);
  pp0[0] = p0t[0]; pp0[1] = p0t[1]; pp0[2] = p0t[2]; pp0[3] = 1.0;
  m4xv4(p0t, T, pp0); // Step 2
  pp0[0] = p2t[0]; pp0[1] = p2t[1]; pp0[2] = p2t[2]; pp0[3] = 1.0;
  m4xv4(p2t, T, pp0); // Step 2

  // Get the rotation angle around x-axis
  dy = p2t[1];
  dz = p2t[2];
  projlen = sqrt(dy * dy + dz * dz);
  if (projlen <= (b->epsilon * 1e-2) * longest) {
    rotx = 0;
  } else {
    rotx = acos(dz / projlen);
    if (dy < 0) {
      rotx = -rotx;
    }
  }
    
  initm44(1, 0, 0, 0,
          0, cos(rotx), -sin(rotx), 0,
          0, sin(rotx), cos(rotx), 0,
          0, 0, 0, 1, T);
  pp0[0] = p0t[0]; pp0[1] = p0t[1]; pp0[2] = p0t[2]; pp0[3] = 1.0;
  m4xv4(p0t, T, pp0); // Step 3
  // pp0[0] = p2t[0]; pp0[1] = p2t[1]; pp0[2] = p2t[2]; pp0[3] = 1.0;
  // m4xv4(p2t, T, pp0); // Step 3

  alphaR = rotangle;
  initm44(cos(alphaR), -sin(alphaR), 0, 0,
          sin(alphaR), cos(alphaR), 0, 0,
          0, 0, 1, 0,
          0, 0, 0, 1, T);
  pp0[0] = p0t[0]; pp0[1] = p0t[1]; pp0[2] = p0t[2]; pp0[3] = 1.0;
  m4xv4(p0t, T, pp0); // Step 4

  initm44(1, 0, 0, 0,
          0, cos(-rotx), -sin(-rotx), 0,
          0, sin(-rotx), cos(-rotx), 0,
          0, 0, 0, 1, T);
  pp0[0] = p0t[0]; pp0[1] = p0t[1]; pp0[2] = p0t[2]; pp0[3] = 1.0;
  m4xv4(p0t, T, pp0); // Step 5

  initm44(cos(roty), 0, sin(roty), 0,
          0, 1, 0, 0,
          -sin(roty), 0, cos(roty), 0,
          0, 0, 0, 1, T);
  pp0[0] = p0t[0]; pp0[1] = p0t[1]; pp0[2] = p0t[2]; pp0[3] = 1.0;
  m4xv4(p0t, T, pp0); // Step 6

  initm44(1, 0, 0, p1[0],
          0, 1, 0, p1[1],
          0, 0, 1, p1[2],
          0, 0, 0, 1, T);
  pp0[0] = p0t[0]; pp0[1] = p0t[1]; pp0[2] = p0t[2]; pp0[3] = 1.0;
  m4xv4(p0t, T, pp0); // Step 7  

  p[0] = p0t[0];
  p[1] = p0t[1];
  p[2] = p0t[2];
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// spherelineint()    3D line sphere (or circle) intersection.               //
//                                                                           //
// The line is given by two points p1, and p2, the sphere is centered at c   //
// with radius r.  This function returns a pointer array p which first index //
// indicates the number of intersection point, followed by coordinate pairs. //
//                                                                           //
// The following code are adapted from: http://astronomy.swin.edu.au/pbourke //
// /geometry/sphereline. Paul Bourke pbourke@swin.edu.au                     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::spherelineint(REAL* p1, REAL* p2, REAL* C, REAL R, REAL p[7])
{
  REAL x1, y1, z1; //  P1 coordinates (point of line)
  REAL x2, y2, z2; //  P2 coordinates (point of line)
  REAL x3, y3, z3, r; //  P3 coordinates and radius (sphere)
  REAL a, b, c, mu, i ;

  x1 = p1[0]; y1 = p1[1]; z1 = p1[2];
  x2 = p2[0]; y2 = p2[1]; z2 = p2[2];
  x3 = C[0];  y3 = C[1];  z3 = C[2];
  r = R;
  
  a =   (x2 - x1) * (x2 - x1) 
      + (y2 - y1) * (y2 - y1) 
      + (z2 - z1) * (z2 - z1);
  b = 2 * ( (x2 - x1) * (x1 - x3)
          + (y2 - y1) * (y1 - y3)
          + (z2 - z1) * (z1 - z3) ) ;
  c =   (x3 * x3) + (y3 * y3) + (z3 * z3)
      + (x1 * x1) + (y1 * y1) + (z1 * z1)
      - 2 * (x3 * x1 + y3 * y1 + z3 * z1) - (r * r) ;
  i = b * b - 4 * a * c ;

  if (i < 0.0) {
    // no intersection
    p[0] = 0.0;
  } else if (i == 0.0) {
    // one intersection
    p[0] = 1.0;
    mu = -b / (2 * a) ;
    p[1] = x1 + mu * (x2 - x1);
    p[2] = y1 + mu * (y2 - y1);
    p[3] = z1 + mu * (z2 - z1);
  } else {
    assert(i > 0.0);
    // two intersections
    p[0] = 2.0;
    // first intersection
    mu = (-b + sqrt((b * b) - 4 * a * c)) / (2 * a);
    p[1] = x1 + mu * (x2 - x1);
    p[2] = y1 + mu * (y2 - y1);
    p[3] = z1 + mu * (z2 - z1);
    // second intersection
    mu = (-b - sqrt((b * b) - 4 * a * c)) / (2 * a);
    p[4] = x1 + mu * (x2 - x1);
    p[5] = y1 + mu * (y2 - y1);
    p[6] = z1 + mu * (z2 - z1);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// linelineint()    Calculate The shortest line between two lines in 3D.     //
//                                                                           //
// Two 3D lines generally don't intersect at a point, they may be parallel ( //
// no intersections), or they may be coincident (infinite intersections) but //
// most often only their projection onto a plane intersect.  When they don't //
// exactly intersect at a point they can be connected by a line segment, the //
// shortest line segment is unique and is often considered to be their inter-//
// section in 3D.                                                            //
//                                                                           //
// The following code are adapted from: http://astronomy.swin.edu.au/pbourke //
// /geometry/lineline3d. Paul Bourke pbourke@swin.edu.au                     //
//                                                                           //
// Calculate the line segment PaPb that is the shortest route between two    //
// lines P1P2 and P3P4. This function returns a pointer array p which first  //
// index indicates there exists solution or not, 0 means no solution, 1 meas //
// has solution followed by two coordinate pairs.                            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::linelineint(REAL *p1,REAL *p2, REAL *p3, REAL *p4, REAL p[7])
{
  REAL p13[3], p43[3], p21[3];
  REAL d1343, d4321, d1321, d4343, d2121;
  REAL numer, denom;
  REAL mua, mub;

  p13[0] = p1[0] - p3[0];
  p13[1] = p1[1] - p3[1];
  p13[2] = p1[2] - p3[2];
  p43[0] = p4[0] - p3[0];
  p43[1] = p4[1] - p3[1];
  p43[2] = p4[2] - p3[2];
  if (p43[0] == 0.0 && p43[1] == 0.0 && p43[2] == 0.0) {
    p[0] = 0.0;
    return;
  }

  p21[0] = p2[0] - p1[0];
  p21[1] = p2[1] - p1[1];
  p21[2] = p2[2] - p1[2];
  if (p21[0] == 0.0 && p21[1] == 0.0 && p21[2] == 0.0) {
    p[0] = 0.0;
    return;
  }

  d1343 = p13[0] * p43[0] + p13[1] * p43[1] + p13[2] * p43[2];
  d4321 = p43[0] * p21[0] + p43[1] * p21[1] + p43[2] * p21[2];
  d1321 = p13[0] * p21[0] + p13[1] * p21[1] + p13[2] * p21[2];
  d4343 = p43[0] * p43[0] + p43[1] * p43[1] + p43[2] * p43[2];
  d2121 = p21[0] * p21[0] + p21[1] * p21[1] + p21[2] * p21[2];

  denom = d2121 * d4343 - d4321 * d4321;
  if (denom == 0.0) {
    p[0] = 0.0;
    return;
  }
  numer = d1343 * d4321 - d1321 * d4343;
  mua = numer / denom;
  mub = (d1343 + d4321 * mua) / d4343;

  p[0] = 1.0;
  p[1] = p1[0] + mua * p21[0];
  p[2] = p1[1] + mua * p21[1];
  p[3] = p1[2] + mua * p21[2];
  p[4] = p3[0] + mub * p43[0];
  p[5] = p3[1] + mub * p43[1];
  p[6] = p3[2] + mub * p43[2];
}

//
// End of Geometric quantities calculators
//

//
// Begin of memory management routines
//

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// dummyinit()    Initialize the tetrahedron that fills "outer space" and    //
//                the omnipresent subface.                                   //
//                                                                           //
// The tetrahedron that fills "outer space" called 'dummytet', is pointed to //
// by every tetrahedron and subface on a boundary (be it outer or inner) of  //
// the tetrahedralization. Also, 'dummytet' points to one of the tetrahedron //
// on the convex hull(until the holes and concavities are carved), making it //
// possible to find a starting tetrahedron for point location.               //
//                                                                           //
// The omnipresent subface,'dummysh', is pointed to by every tetrahedron or  //
// subface that doesn't have a full complement of real subface to point to.  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::dummyinit(int tetwords, int shwords)
{
  unsigned long alignptr;

  // Set up 'dummytet', the 'tetrahedron' that occupies "outer space".
  dummytetbase = (tetrahedron *) new char[tetwords * sizeof(tetrahedron)
                                          + tetrahedrons->alignbytes];
  // Align 'dummytet' on a 'tetrahedrons->alignbytes'-byte boundary.
  alignptr = (unsigned long) dummytetbase;
  dummytet = (tetrahedron *)
    (alignptr + (unsigned long) tetrahedrons->alignbytes
     - (alignptr % (unsigned long) tetrahedrons->alignbytes));
  // Initialize the four adjoining tetrahedra to be "outer space". These
  //   will eventually be changed by various bonding operations, but their
  //   values don't really matter, as long as they can legally be
  //   dereferenced.
  dummytet[0] = (tetrahedron) dummytet;
  dummytet[1] = (tetrahedron) dummytet;
  dummytet[2] = (tetrahedron) dummytet;
  dummytet[3] = (tetrahedron) dummytet;
  // Four null vertex points.
  dummytet[4] = (tetrahedron) NULL;
  dummytet[5] = (tetrahedron) NULL;
  dummytet[6] = (tetrahedron) NULL;
  dummytet[7] = (tetrahedron) NULL;

  if (b->useshelles) {
    // Set up 'dummysh', the omnipresent "subface" pointed to by any
    //   tetrahedron side or subface end that isn't attached to a real
    //   subface.
    dummyshbase = (shellface *) new char[shwords * sizeof(shellface)
                                         + subfaces->alignbytes];
    // Align 'dummysh' on a 'subfaces->alignbytes'-byte boundary.
    alignptr = (unsigned long) dummyshbase;
    dummysh = (shellface *)
      (alignptr + (unsigned long) subfaces->alignbytes
       - (alignptr % (unsigned long) subfaces->alignbytes));
    // Initialize the three adjoining subfaces to be the omnipresent
    //   subface. These will eventually be changed by various bonding
    //   operations, but their values don't really matter, as long as they
    //   can legally be dereferenced.
    dummysh[0] = (shellface) dummysh;
    dummysh[1] = (shellface) dummysh;
    dummysh[2] = (shellface) dummysh;
    // Three null vertex points.
    dummysh[3] = (shellface) NULL;
    dummysh[4] = (shellface) NULL;
    dummysh[5] = (shellface) NULL;
    // Initialize the two adjoining tetrahedra to be "outer space".
    dummysh[6] = (shellface) dummytet;
    dummysh[7] = (shellface) dummytet;
    // Initialize the three adjoining subsegments to be "out boundary".
    dummysh[8]  = (shellface) dummysh;
    dummysh[9]  = (shellface) dummysh;
    dummysh[10] = (shellface) dummysh;
    // Initialize the pointer to badface structure.
    dummysh[11] = (shellface) NULL;
    // Initialize the four adjoining subfaces of 'dummytet' to be the
    //   omnipresent subface.
    dummytet[8 ] = (tetrahedron) dummysh;
    dummytet[9 ] = (tetrahedron) dummysh;
    dummytet[10] = (tetrahedron) dummysh;
    dummytet[11] = (tetrahedron) dummysh;
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// initializepools()    Calculate the sizes of the point, tetrahedron, and   //
//                      subface. Initialize their memory pools.              //
//                                                                           //
// This routine also computes the indices 'pointmarkindex', 'point2simindex',//
// and 'point2pbcptindex' used to find values within each point;  computes   //
// indices 'highorderindex', 'elemattribindex', and 'volumeboundindex' used  //
// to find values within each tetrahedron.                                   //
//                                                                           //
// There are two types of boundary elements, which are subfaces and subsegs, //
// they are stored in seperate pools. However, the data structures of them   //
// are the same.  A subsegment can be regarded as a degenerate subface, i.e.,//
// one of its three corners is not used. We set the apex of it be 'NULL' to  //
// distinguish it's a subsegment.                                            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::initializepools()
{
  enum wordtype wtype;
  int pointsize, elesize, shsize;

  // Default checkpbc = 0;
  if ((b->plc || b->refine) && (in->pbcgrouplist != NULL)) {
    checkpbcs = 1;
  }
  // Default varconstraint = 0;
  if (b->quality && (in->nodeconstraintlist || in->segmentconstraintlist ||
                     in->facetconstraintlist)) {
    varconstraint = 1;
  }

  // The index within each point at which the constraint is found, where the
  //   index is measured in REALs.
  edgeboundindex = 3 + in->numberofpointattributes;
  // The index within each point at which a element pointer is found. Ensure
  //   the index is aligned to a sizeof(tetrahedron)-byte address.
  point2simindex = ((edgeboundindex + varconstraint) * sizeof(REAL) +
                    sizeof(tetrahedron) - 1) / sizeof(tetrahedron);
  if (b->plc || b->refine) {
    // Increase the point size by one pointer points to a simplex, which
    //   may be one of the followings:
    //   - a tetrahedron containing it, read by point2tet();
    //   - a subface containing it, read by point2sh();
    //   - a (sharp) subsegment it relates, read by point2sh();
    //   - a (duplicated) point of it, read by point2pt();
    //   Optionally, increase the point size one pointer points another
    //   point (its parent, read by point2ppt()) when b->quality == 1.
    pointsize = (point2simindex + 1 + b->quality) * sizeof(tetrahedron);
    // The index within each point at which a pbc point is found.
    point2pbcptindex = (pointsize + sizeof(int) - 1) / sizeof(int);
    // Increase one pointer points to another point (its corresponding pbc
    //   point, read by point2pbcpt()) when checkpbcs == 1.
    pointsize = (point2pbcptindex + checkpbcs) * sizeof(int);
  } else {
    pointsize = point2simindex * sizeof(tetrahedron);
  }
  // The index within each point at which the boundary marker is found,
  //   Ensure the point marker is aligned to a sizeof(int)-byte address.
  pointmarkindex = (pointsize + sizeof(int) - 1) / sizeof(int);
  // Now point size is the ints (inidcated by pointmarkindex) plus:
  //   - an integer for boundary marker;
  //   - an integer for vertex type;
  pointsize = (pointmarkindex + 2) * sizeof(int);
  // Decide the wordtype used in vertex pool.
  wtype = (sizeof(REAL) >= sizeof(tetrahedron)) ? FLOATINGPOINT : POINTER;
  // Initialize the pool of vertices.
  points = new memorypool(pointsize, VERPERBLOCK, wtype, 0);

  // The number of bytes occupied by a tetrahedron.  There are four pointers
  //   to other tetrahedra, four pointers to corners, and possibly four
  //   pointers to subfaces.
  elesize = (8 + b->useshelles * 4) * sizeof(tetrahedron);
  // The index within each element at which its attributes are found, where
  //   the index is measured in REALs. 
  elemattribindex = (elesize + sizeof(REAL) - 1) / sizeof(REAL);
  // The index within each element at which the maximum voulme bound is
  //   found, where the index is measured in REALs.  Note that if the
  //   `b->regionattrib' flag is set, an additional attribute will be added.
  volumeboundindex = elemattribindex + in->numberoftetrahedronattributes
                   + b->regionattrib;
  // If element attributes or an constraint are needed, increase the number
  //   of bytes occupied by an element.
  if (b->varvolume) {
    elesize = (volumeboundindex + 1) * sizeof(REAL);
  } else if (in->numberoftetrahedronattributes + b->regionattrib > 0) {
    elesize = volumeboundindex * sizeof(REAL);
  }
  // If the high order elements are required (-o2 switch is used), an
  //   additional pointer pointed to the list of extra nodes is allocated
  //   for each element.
  if (b->order == 2) {
    highorderindex = (elesize + sizeof(int) - 1) / sizeof(int);
    elesize = (highorderindex + 1) * sizeof(int);
  }
  // If element neighbor graph is requested, make sure there's room to
  //   store an integer index in each element.  This integer index can
  //   occupy the same space as the subface pointers.
  if (b->neighout && (elesize <= 8 * sizeof(tetrahedron))) {
    elesize = 8 * sizeof(tetrahedron) + sizeof(int);
  }
  // Having determined the memory size of an element, initialize the pool.
  tetrahedrons = new memorypool(elesize, ELEPERBLOCK, POINTER, 8);

  if (b->useshelles) {
    // The number of bytes occupied by a subface.  The list of pointers
    //   stored in a subface are: three to other subfaces, three to corners,
    //   three to subsegments, two to tetrahedra, and one to a badface.
    shsize = 12 * sizeof(shellface);
    // The index within each subface at which the maximum area bound is
    //   found, where the index is measured in REALs.
    areaboundindex = (shsize + sizeof(REAL) - 1) / sizeof(REAL);
    // If -q switch is in use, increase the number of bytes occupied by
    //   a subface for saving maximum area bound.
    if (b->quality && varconstraint) {
      shsize = (areaboundindex + 1) * sizeof(REAL);
    } else {
      shsize = areaboundindex * sizeof(REAL);
    }
    // The index within subface at which the facet marker is found. Ensure
    //   the marker is aligned to a sizeof(int)-byte address.
    shmarkindex = (shsize + sizeof(int) - 1) / sizeof(int);
    // Increase the number of bytes by two or three integers, one for facet
    //   marker, one for shellface type, and optionally one for pbc group.
    shsize = (shmarkindex + 2 + checkpbcs) * sizeof(int);
    // Initialize the pool of subfaces. Each subface record is eight-byte
    //   aligned so it has room to store an edge version (from 0 to 5) in
    //   the least three bits.
    subfaces = new memorypool(shsize, SUBPERBLOCK, POINTER, 8);
    // Initialize the pool of subsegments. The subsegment's record is same
    //   with subface.
    subsegs = new memorypool(shsize, SUBPERBLOCK, POINTER, 8);
    // Initialize the "outer space" tetrahedron and omnipresent subface.
    dummyinit(tetrahedrons->itemwords, subfaces->itemwords);
  } else {
    // Initialize the "outer space" tetrahedron.
    dummyinit(tetrahedrons->itemwords, 0);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// tetrahedrondealloc()    Deallocate space for a tet., marking it dead.     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::tetrahedrondealloc(tetrahedron *dyingtetrahedron)
{
  // Set tetrahedron's vertices to NULL. This makes it possible to detect
  //   dead tetrahedra when traversing the list of all tetrahedra.
  dyingtetrahedron[4] = (tetrahedron) NULL;
  dyingtetrahedron[5] = (tetrahedron) NULL;
  dyingtetrahedron[6] = (tetrahedron) NULL;
  dyingtetrahedron[7] = (tetrahedron) NULL;
  tetrahedrons->dealloc((void *) dyingtetrahedron);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// tetrahedrontraverse()    Traverse the tetrahedra, skipping dead ones.     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

tetgenmesh::tetrahedron* tetgenmesh::tetrahedrontraverse()
{
  tetrahedron *newtetrahedron;

  do {
    newtetrahedron = (tetrahedron *) tetrahedrons->traverse();
    if (newtetrahedron == (tetrahedron *) NULL) {
      return (tetrahedron *) NULL;
    }
  } while (newtetrahedron[7] == (tetrahedron) NULL);      // Skip dead ones.
  return newtetrahedron;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// shellfacedealloc()    Deallocate space for a shellface, marking it dead.  //
//                       Used both for dealloc a subface and subsegment.     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::shellfacedealloc(memorypool *pool, shellface *dyingsh)
{
  // Set shellface's vertices to NULL. This makes it possible to detect dead
  //   shellfaces when traversing the list of all shellfaces.
  dyingsh[3] = (shellface) NULL;
  dyingsh[4] = (shellface) NULL;
  dyingsh[5] = (shellface) NULL;
  pool->dealloc((void *) dyingsh);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// shellfacetraverse()    Traverse the subfaces, skipping dead ones. Used    //
//                        for both subfaces and subsegments pool traverse.   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

tetgenmesh::shellface* tetgenmesh::shellfacetraverse(memorypool *pool)
{
  shellface *newshellface;

  do {
    newshellface = (shellface *) pool->traverse();
    if (newshellface == (shellface *) NULL) {
      return (shellface *) NULL;
    }
  } while (newshellface[3] == (shellface) NULL);          // Skip dead ones.
  return newshellface;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// badfacedealloc()    Deallocate space for a badface, marking it dead.      //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::badfacedealloc(memorypool *pool, badface *dying)
{
  // Set badface's forg to NULL. This makes it possible to detect dead
  //   ones when traversing the list of all items.
  dying->forg = (point) NULL;
  pool->dealloc((void *) dying);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// badfacetraverse()    Traverse the pools, skipping dead ones.              //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

tetgenmesh::badface* tetgenmesh::badfacetraverse(memorypool *pool)
{
  badface *newsh;

  do {
    newsh = (badface *) pool->traverse();
    if (newsh == (badface *) NULL) {
      return (badface *) NULL;
    }
  } while (newsh->forg == (point) NULL);               // Skip dead ones.
  return newsh;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// pointdealloc()    Deallocate space for a point, marking it dead.          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::pointdealloc(point dyingpoint)
{
  // Mark the point as dead. This  makes it possible to detect dead points
  //   when traversing the list of all points.
  setpointtype(dyingpoint, DEADVERTEX);
  points->dealloc((void *) dyingpoint);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// pointtraverse()    Traverse the points, skipping dead ones.               //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

tetgenmesh::point tetgenmesh::pointtraverse()
{
  point newpoint;

  do {
    newpoint = (point) points->traverse();
    if (newpoint == (point) NULL) {
      return (point) NULL;
    }
  } while (pointtype(newpoint) == DEADVERTEX);            // Skip dead ones.
  return newpoint;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// maketetrahedron()    Create a new tetrahedron.                            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::maketetrahedron(triface *newtet)
{
  newtet->tet = (tetrahedron *) tetrahedrons->alloc();
  // Initialize the four adjoining tetrahedra to be "outer space".
  newtet->tet[0] = (tetrahedron) dummytet;
  newtet->tet[1] = (tetrahedron) dummytet;
  newtet->tet[2] = (tetrahedron) dummytet;
  newtet->tet[3] = (tetrahedron) dummytet;
  // Four NULL vertices.
  newtet->tet[4] = (tetrahedron) NULL;
  newtet->tet[5] = (tetrahedron) NULL;
  newtet->tet[6] = (tetrahedron) NULL;
  newtet->tet[7] = (tetrahedron) NULL;
  // Initialize the four adjoining subfaces to be the omnipresent subface.
  if (b->useshelles) {
    newtet->tet[8 ] = (tetrahedron) dummysh;
    newtet->tet[9 ] = (tetrahedron) dummysh;
    newtet->tet[10] = (tetrahedron) dummysh;
    newtet->tet[11] = (tetrahedron) dummysh;
  }
  for (int i = 0; i < in->numberoftetrahedronattributes; i++) {
    setelemattribute(newtet->tet, i, 0.0);
  }
  if (b->varvolume) {
    setvolumebound(newtet->tet, -1.0);
  }
  // Initialize the location and version to be Zero.
  newtet->loc = 0;
  newtet->ver = 0;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// makeshellface()    Create a new shellface with version zero. Used for     //
//                    both subfaces and seusegments.                         //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::makeshellface(memorypool *pool, face *newface)
{
  newface->sh = (shellface *) pool->alloc();
  //Initialize the three adjoining subfaces to be the omnipresent subface.
  newface->sh[0] = (shellface) dummysh;
  newface->sh[1] = (shellface) dummysh;
  newface->sh[2] = (shellface) dummysh;
  // Three NULL vertices.
  newface->sh[3] = (shellface) NULL;
  newface->sh[4] = (shellface) NULL;
  newface->sh[5] = (shellface) NULL;
  // Initialize the two adjoining tetrahedra to be "outer space".
  newface->sh[6] = (shellface) dummytet;
  newface->sh[7] = (shellface) dummytet;
  // Initialize the three adjoining subsegments to be the omnipresent
  //   subsegments.
  newface->sh [8] = (shellface) dummysh;
  newface->sh [9] = (shellface) dummysh;
  newface->sh[10] = (shellface) dummysh;
  // Initialize the pointer to badface structure.
  newface->sh[11] = (shellface) NULL;
  if (b->quality && varconstraint) {
    // Initialize the maximum area bound.
    setareabound(*newface, 0.0);
  }
  // Set the boundary marker to zero.
  setshellmark(*newface, 0);
  // Set the type.
  setshelltype(*newface, NSHARPNSKINNY);
  if (checkpbcs) {
    // Set the pbcgroup be ivalid.
    setshellpbcgroup(*newface, -1);
  }
  // Initialize the version to be Zero.
  newface->shver = 0;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// makepoint()    Create a new point.                                        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::makepoint(point* pnewpoint)
{
  int ptmark, i;

  *pnewpoint = (point) points->alloc();
  // Initialize three coordinates.
  (*pnewpoint)[0] = 0.0;
  (*pnewpoint)[1] = 0.0;
  (*pnewpoint)[2] = 0.0;
  // Initialize the list of user-defined attributes.
  for (i = 0; i < in->numberofpointattributes; i++) {
    (*pnewpoint)[3 + i] = 0.0;
  }
  if (b->plc || b->refine) {
    // Initialize the point-to-tetrahedron filed.
    setpoint2tet(*pnewpoint, NULL);
    if (b->quality) {
      // Initialize the other pointer to its parent point.
      setpoint2ppt(*pnewpoint, NULL);
    }
    if (b->quality && varconstraint) {
      // Initialize the maximum edge length bound.
      setedgebound(*pnewpoint, 0.0);
    }
    if (checkpbcs) {
      // Initialize the other pointer to its pbc point.
      setpoint2pbcpt(*pnewpoint, NULL);
    }
  }
  // Initialize the point marker (starting from in->firstnumber).
  ptmark = (int) points->items - (in->firstnumber == 1 ? 0 : 1);
  setpointmark(*pnewpoint, ptmark);
  // Initialize the point type be UNUSEDVERTEX.
  setpointtype(*pnewpoint, UNUSEDVERTEX);
}

//
// End of memory management routines
//

//
// Begin of point location routines
//

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// randomnation()    Generate a random number between 0 and 'choices' - 1.   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

unsigned long tetgenmesh::randomnation(unsigned int choices)
{
  randomseed = (randomseed * 1366l + 150889l) % 714025l;
  return randomseed / (714025l / choices + 1);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// distance2()    Returns the square "distance" of a tetrahedron to point p. //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

REAL tetgenmesh::distance2(tetrahedron* tetptr, point p)
{
  point p1, p2, p3, p4;
  REAL dx, dy, dz;

  p1 = (point) tetptr[4];
  p2 = (point) tetptr[5];
  p3 = (point) tetptr[6];
  p4 = (point) tetptr[7];

  dx = p[0] - 0.25 * (p1[0] + p2[0] + p3[0] + p4[0]);
  dy = p[1] - 0.25 * (p1[1] + p2[1] + p3[1] + p4[1]);
  dz = p[2] - 0.25 * (p1[2] + p2[2] + p3[2] + p4[2]);

  return dx * dx + dy * dy + dz * dz;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// preciselocate()    Find a simplex containing a given point.               //
//                                                                           //
// This routine implements the simple Walk-through point location algorithm. //
// Begins its search from 'searchtet', assume there is a line segment L from //
// a vertex of 'searchtet' to the query point 'searchpt', and simply walk    //
// towards 'searchpt' by traversing all faces intersected by L.              //
//                                                                           //
// On completion, 'searchtet' is a tetrahedron that contains 'searchpt'. The //
// returned value indicates one of the following cases:                      //
//   - Returns ONVERTEX if the point lies on an existing vertex. 'searchtet' //
//     is a handle whose origin is the existing vertex.                      //
//   - Returns ONEDGE if the point lies on a mesh edge.  'searchtet' is a    //
//     handle whose primary edge is the edge on which the point lies.        //
//   - Returns ONFACE if the point lies strictly within a face. 'searchtet'  //
//     is a handle whose primary face is the face on which the point lies.   //
//   - Returns INTETRAHEDRON if the point lies strictly in a tetrahededron.  //
//     'searchtet' is a handle on the tetrahedron that contains the point.   //
//   - Returns OUTSIDE if the point lies outside the mesh. 'searchtet' is a  //
//     handle whose location is the face the point is to 'above' of.         //
//                                                                           //
// WARNING: This routine is designed for convex triangulations, and will not //
// generally work after the holes and concavities have been carved.          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

enum tetgenmesh::locateresult tetgenmesh::
preciselocate(point searchpt, triface* searchtet)
{
  triface backtracetet;
  triface walkthroface;
  point forg, fdest, fapex, toppo;
  REAL ori1, ori2, ori3, ori4;
  long tetnumber;
  int side;

  // 'searchtet' should be a valid tetrahedron.
  if (searchtet->tet == dummytet) {
    searchtet->loc = 0;
    symself(*searchtet);
    assert(searchtet->tet != dummytet);
  }
  assert(!isdead(searchtet));

  searchtet->ver = 0; // Keep in CCW edge ring.
  // Find a face of 'searchtet' such that the 'searchpt' lies strictly
  //   above it.  Such face should always exist.
  for (searchtet->loc = 0; searchtet->loc < 4; searchtet->loc++) {
    forg = org(*searchtet);
    fdest = dest(*searchtet);
    fapex = apex(*searchtet);
    ori1 = orient3d(forg, fdest, fapex, searchpt);
    if (ori1 < 0.0) break;
  }
  assert(searchtet->loc < 4);

  // Define 'tetnumber' for exit the loop when it's running endless.
  tetnumber = 0l;
  while (tetnumber <= tetrahedrons->items) {
    // Check if we are reaching the boundary of the triangulation.
    if (searchtet->tet == dummytet) {
      *searchtet = backtracetet;
      return OUTSIDE;
    }
    // Initialize the face for returning the walk-through face.
    walkthroface.tet = (tetrahedron *) NULL;
    // Adjust the edge ring, so that 'ori1 < 0.0' holds.
    searchtet->ver = 0;
    // 'toppo' remains unchange for the following orientation tests.
    toppo = oppo(*searchtet);
    // Check the three sides of 'searchtet' to find the face through which
    //   we can walk next.
    for (side = 0; side < 3; side++) {
      forg = org(*searchtet);
      fdest = dest(*searchtet);
      ori2 = orient3d(forg, fdest, toppo, searchpt);
      if (ori2 == 0.0) {
        // They are coplanar, check if 'searchpt' lies inside, or on an edge,
        //   or coindice with a vertex of face (forg, fdest, toppo). 
        fapex = apex(*searchtet);
        ori3 = orient3d(fdest, fapex, toppo, searchpt);
        if (ori3 < 0.0) {
          // Outside the face (fdest, fapex, toppo), walk through it.
          enextself(*searchtet);
          fnext(*searchtet, walkthroface);
          break;
        }
        ori4 = orient3d(fapex, forg, toppo, searchpt);
        if (ori4 < 0.0) {
          // Outside the face (fapex, forg, toppo), walk through it.
          enext2self(*searchtet);
          fnext(*searchtet, walkthroface);
          break;
        }
        // Remember, ori1 < 0.0, which means 'searchpt' will not on edge
        //   (forg, fdest) or on vertex forg or fdest.
        assert(ori1 < 0.0);
        // The rest possible cases are: 
        //   (1) 'searchpt' lies on edge (fdest, toppo);
        //   (2) 'searchpt' lies on edge (toppo, forg);
        //   (3) 'searchpt' coincident with toppo;
        //   (4) 'searchpt' lies inside face (forg, fdest, toppo).
        fnextself(*searchtet);
        if (ori3 == 0.0) {
          if (ori4 == 0.0) {
            // Case (4).
            enext2self(*searchtet);
            return ONVERTEX;
          } else {
            // Case (1).
            enextself(*searchtet);
            return ONEDGE;
          }
        }
        if (ori4 == 0.0) {
          // Case (2).
          enext2self(*searchtet);
          return ONEDGE;
        }
        // Case (4).
        return ONFACE;
      } else if (ori2 < 0.0) {
        // Outside the face (forg, fdest, toppo), walk through it.
        fnext(*searchtet, walkthroface);
        break;
      }
      // Go to check next side.
      enextself(*searchtet);
    }
    if (side >= 3) {
      // Found! Inside tetrahedron.
      return INTETRAHEDRON;
    }
    // We walk through the face 'walkthroface' and continue the searching.
    assert(walkthroface.tet != (tetrahedron *) NULL);
    // Store the face handle in 'backtracetet' before we take the real walk.
    //   So we are able to restore the handle to 'searchtet' if we are
    //   reaching the outer boundary.
    backtracetet = walkthroface;
    sym(walkthroface, *searchtet);    
    tetnumber++;
  }

  // Should never be here.
  // printf("Internal error in preciselocate(): Point location failed.\n");
  // internalerror();
  return OUTSIDE;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// locate()    Find a simplex containing a given point.                      //
//                                                                           //
// This routine implements Muecke's Jump-and-walk point location algorithm.  //
// It improves the simple walk-through by "jumping" to a good starting point //
// via random sampling.  Searching begins from one of handles:  the input    //
// 'searchtet', a recently encountered tetrahedron 'recenttet',  or from one //
// chosen from a random sample.  The choice is made by determining which one //
// 's barycenter is closest to the point we are searcing for.  Having chosen //
// the starting tetrahedron, the simple Walk-through algorithm is used to do //
// the real walking.                                                         //
//                                                                           //
// The return value indicates the location of the 'searchpt' (INTETRAHEDRON, //
// or ONFACE, ...). 'searchtet' is adjusted to a tetrahedron corresponding   //
// to that value. See the introduction part of preciselocate() for detail.   //
//                                                                           //
// WARNING: This routine is designed for convex triangulations, and will not //
// generally work after the holes and concavities have been carved.          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

enum tetgenmesh::locateresult tetgenmesh::
locate(point searchpt, triface *searchtet)
{
  tetrahedron *firsttet, *tetptr;
  void **sampleblock;
  long sampleblocks, samplesperblock, samplenum;
  long tetblocks, i, j;
  unsigned long alignptr;
  REAL searchdist, dist;

  // 'searchtet' should be a valid tetrahedron.
  if (isdead(searchtet)) {
    searchtet->tet = dummytet;
  }
  if (searchtet->tet == dummytet) {
    // This is an 'Outer Space' handle, get a hull tetrahedron.
    searchtet->loc = 0;
    symself(*searchtet);
  }
  assert(!isdead(searchtet));
  
  // Get the distance from the suggested starting tet to the point we seek.
  searchdist = distance2(searchtet->tet, searchpt);

  // If a recently encountered tetrahedron has been recorded and has not
  //   been deallocated, test it as a good starting point.
  if (!isdead(&recenttet) && (recenttet.tet != searchtet->tet)) {
    dist = distance2(recenttet.tet, searchpt);
    if (dist < searchdist) {
      *searchtet = recenttet;
      searchdist = dist;
    }
  }

  // Select "good" candidate using k random samples, taking the closest one.
  //   The number of random samples taken is proportional to the cube root
  //   of the number of tetrahedra in the mesh. The next bit of code assumes
  //   that the number of tetrahedra increases monotonically.
  while (SAMPLEFACTOR * samples * samples * samples < tetrahedrons->items) {
    samples++;
  }
  // Find how much blocks in current tet pool.
  tetblocks = (tetrahedrons->maxitems + ELEPERBLOCK - 1) / ELEPERBLOCK;
  // Find the average samles per block. Each block at least have 1 sample.
  samplesperblock = 1 + (samples / tetblocks);
  sampleblocks = samples / samplesperblock;
  sampleblock = tetrahedrons->firstblock;
  for (i = 0; i < sampleblocks; i++) {
    alignptr = (unsigned long) (sampleblock + 1);
    firsttet = (tetrahedron *)
               (alignptr + (unsigned long) tetrahedrons->alignbytes
               - (alignptr % (unsigned long) tetrahedrons->alignbytes));
    for (j = 0; j < samplesperblock; j++) {
      if (i == tetblocks - 1) {
        // This is the last block.
        samplenum = randomnation((int)
                      (tetrahedrons->maxitems - (i * ELEPERBLOCK)));
      } else {
        samplenum = randomnation(ELEPERBLOCK);
      }
      tetptr = (tetrahedron *)
               (firsttet + (samplenum * tetrahedrons->itemwords));
      if (tetptr[4] != (tetrahedron) NULL) {
        dist = distance2(tetptr, searchpt);
        if (dist < searchdist) {
          searchtet->tet = tetptr;
          searchdist = dist;
        }
      }
    }
    sampleblock = (void **) *sampleblock;
  }
  
  // Call simple walk-through to locate the point.
  return preciselocate(searchpt, searchtet); 
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// adjustlocate()    Adjust the precise location of a vertex.                //
//                                                                           //
// 'precise' is the value returned from preciselocate().  It indicates the   //
// exact location of the point 'searchpt' with respect to the tetrahedron    //
// 'searchtet'.  'epspp' is a given relative tolerance.                      //
//                                                                           //
// This routine re-evaluates the orientations of searchpt with respect to    //
// the four sides of searchtet. Detects the coplanarities by additinal tests //
// which are based on the given tolerance. If 'precise' is ONFACE or ONEDGE, //
// we can save one or two orientation tests.                                 //
//                                                                           //
// The return value indicates the location of the 'searchpt' (INTETRAHEDRON, //
// or ONFACE, ...). 'searchtet' is adjusted to a tetrahedron corresponding   //
// to that value. See the introduction part of preciselocate() for detail.   //
//                                                                           //
// WARNING:  This routine detect degenerate case using relative tolerance.   //
// It is better used after locate() or preciselocate().  For general inputs, //
// it may not able to tell the correct location.                             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

enum tetgenmesh::locateresult tetgenmesh::
adjustlocate(point searchpt, triface* searchtet, enum locateresult precise,
             REAL epspp)
{
  point torg, tdest, tapex, toppo;
  REAL s1, s2, s3, s4;

  // For the given 'searchtet', the orientations tests are:
  //  s1: (tdest, torg, tapex, searchpt);
  //  s2: (torg, tdest, toppo, searchpt);
  //  s3: (tdest, tapex, toppo, searchpt);
  //  s4: (tapex, torg, toppo, searchpt);
  adjustedgering(*searchtet, CCW);
  torg = org(*searchtet);
  tdest = dest(*searchtet);
  tapex = apex(*searchtet);
  toppo = oppo(*searchtet);

  switch (precise) {
  case ONVERTEX:
    // This case we don't need do any further test.
    return ONVERTEX;
  case ONEDGE:
    // (torg, tdest);
    s1 = 0.0;
    s2 = 0.0;
    break;
  case ONFACE:
    // (tdest, torg, tapex);
    s1 = 0.0;
    s2 = orient3d(torg, tdest, toppo, searchpt);
    break;
  default: // INTETRAHEDRON or OUTSIDE
    s1 = orient3d(tdest, torg, tapex, searchpt);
    s2 = orient3d(torg, tdest, toppo, searchpt);
  }
  
  if (s1 != 0.0) {
    if (iscoplanar(tdest, torg, tapex, searchpt, s1, epspp)) {
      s1 = 0.0;
    }
  }
  if (s1 < 0.0) {
    return OUTSIDE;
  }

  if (s2 != 0.0) {
    if (iscoplanar(torg, tdest, toppo, searchpt, s2, epspp)) {
      s2 = 0.0;
    }
  }
  if (s2 < 0.0) {
    fnextself(*searchtet);
    return OUTSIDE;
  }

  s3 = orient3d(tdest, tapex, toppo, searchpt);
  if (s3 != 0.0) {
    if (iscoplanar(tdest, tapex, toppo, searchpt, s3, epspp)) {
      s3 = 0.0;
    }
  }
  if (s3 < 0.0) {
    enextfnextself(*searchtet);
    return OUTSIDE;
  }

  s4 = orient3d(tapex, torg, toppo, searchpt);
  if (s4 != 0.0) {
    if (iscoplanar(tapex, torg, toppo, searchpt, s4, epspp)) {
      s4 = 0.0;
    }
  }
  if (s4 < 0.0) {
    enext2fnextself(*searchtet);
    return OUTSIDE;
  }

  // Determine degenerate cases.
  if (s1 == 0.0) {
    if (s2 == 0.0) {
      if (s3 == 0.0) {
        // On tdest.
        enextself(*searchtet);
        return ONVERTEX;
      }
      if (s4 == 0.0) {
        // On torg.
        return ONVERTEX;
      }
      // On edge (torg, tdest).
      return ONEDGE;
    }
    if (s3 == 0.0) {
      if (s4 == 0.0) {
        // On tapex.
        enext2self(*searchtet);
        return ONVERTEX;
      }
      // On edge (tdest, tapex).
      enextself(*searchtet);
      return ONEDGE;
    }
    if (s4 == 0.0) {
      // On edge (tapex, torg).
      enext2self(*searchtet);
      return ONEDGE;
    }
    // On face (torg, tdest, tapex).
    return ONFACE;
  }
  if (s2 == 0.0) {
    fnextself(*searchtet);
    if (s3 == 0.0) {
      if (s4 == 0.0) {
        // On toppo.
        enext2self(*searchtet);
        return ONVERTEX;
      }
      // On edge (tdest, toppo).
      enextself(*searchtet);
      return ONEDGE;
    }
    if (s4 == 0.0) {
      // On edge (toppo, torg).
      enext2self(*searchtet);
      return ONEDGE;
    }
    // On face (torg, tdest, toppo).
    return ONFACE;
  }
  if (s3 == 0.0) {
    enextfnextself(*searchtet);
    if (s4 == 0.0) {
      // On edge (tapex, toppo).
      enextself(*searchtet);
      return ONEDGE;
    }
    // On face (tdest, tapex, toppo).
    return ONFACE;
  }
  if (s4 == 0.0) {
    enext2fnextself(*searchtet);
    // On face (tapex, torg, toppo).
    return ONFACE;
  }

  // Inside tetrahedron.
  return INTETRAHEDRON;
}

//
// End of point location routines
//

//
// Begin of mesh transformation routines
//

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// categorizeface()    Determine the flip type of a given face.              //
//                                                                           //
// On input, 'horiz' represents the face we want to flip (you can imagine it //
// is parallel to the horizon).  Let the tetrahedron above it be abcd, where //
// abc is 'horiz'.                                                           //
//                                                                           //
// This routine determines the suitable type of flip operation for 'horiz'.  //
//   - Returns T23 if a 2-to-3 flip is applicable. 'horiz' is same as input. //
//   - Returns T32 if a 3-to-2 flip is applicable. 'horiz' is adjusted so    //
//     that the primary edge of 'horiz' is the flipable edge.                //
//   - Returns T22 if a 2-to-2 or 4-to-4 flip is applicable.  'horiz' is     //
//     adjusted so that the primary edge of 'horiz' is the flipable edge.    //
//   - Returns FORBIDDENFACE indicates although a 2-to-3 flip is applicable, //
//     but it is a subface and should not be flipped away.                   //
//   - Returns FORBIDDENEDGE indicates although a 3-to-2, or 2-to-2, or      //
//     4-to-4 flip is applicable, but the flipable edge is a subsegment and  //
//     should not be flipped away.  'horiz' is adjusted so that the primary  //
//     edge of 'horiz' is the flipable edge.                                 //
//   - Returns UNFLIPABLE indicates it is unflipable due to the absence of   //
//     a tetrahedron. 'horiz' is adjusted so that the primary edge of 'horiz'//
//     is the unflipable edge. Possibly, It is a subsegment.                 //
//   - Returns NONCONVEX indicates it is unflipable and is locally Delaunay. //
//                                                                           //
// Given a face abc, with two adjoining tetrahedra abcd and bace.  If abc is //
// flipable, i.e., T23, T32, T22 or T44, its flip type can be determined by  //
// doing five orientation tests: two tests for determining that d, e lie on  //
// the different sides of abc, three tests for determining if the edge de    //
// intersects the face abc.  However, if we use the neighbor information of  //
// the mesh data structure, we can reduce the five orientation tests to at   //
// most three tests, that is, the two tests for determining whether d and e  //
// lie on the different sides of abc can be saved.                           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

enum tetgenmesh::fliptype tetgenmesh::categorizeface(triface& horiz)
{
  triface symhoriz, casing;
  face checksh, checkseg;
  face cassh1, cassh2;
  point pa, pb, pc, pd, pe, pf, pg;
  point abdoppo, bcdoppo, cadoppo;
  REAL ori1, ori2, ori3;
  int adjtet;

  sym(horiz, symhoriz);
  if (symhoriz.tet == dummytet) {
    // A hull face is unflipable and locally Delaunay.
    return NONCONVEX;
  }
  
  adjustedgering(horiz, CCW);
  findedge(&symhoriz, dest(horiz), org(horiz));
  pa = org(horiz);
  pb = dest(horiz);
  pc = apex(horiz);
  pd = oppo(horiz);
  pe = oppo(symhoriz);

  // Find the number of adjacent tetrahedra of abc, which have d, e, and one
  //   of corners of abc as their corners. This number can be 0, 1 and 2.
  abdoppo = bcdoppo = cadoppo = (point) NULL;
  adjtet = 0;
  fnext(horiz, casing); // at edge 'ab'.
  symself(casing);
  if (casing.tet != dummytet) {
    abdoppo = oppo(casing);
    if (abdoppo == pe) adjtet++;
  }
  enextfnext(horiz, casing); // at edge 'bc'.
  symself(casing);
  if (casing.tet != dummytet) {
    bcdoppo = oppo(casing);
    if (bcdoppo == pe) adjtet++;
  }
  enext2fnext(horiz, casing); // at edge 'ca'.
  symself(casing);
  if (casing.tet != dummytet) {
    cadoppo = oppo(casing);
    if (cadoppo == pe) adjtet++;
  }
  
  if (adjtet == 0) {
    // No adjacent tetrahedron. Types T23, T22 and T44 are possible. 
    ori1 = orient3d(pa, pb, pd, pe);
    if (checksubfaces && ori1 != 0.0) {
      // Check if abd and abe are both boundary faces?
      fnext(horiz, casing);
      tspivot(casing, cassh1);
      fnext(symhoriz, casing);
      tspivot(casing, cassh2);
      if (cassh1.sh != dummysh && cassh2.sh != dummysh) {
        // abd and abe are both boundary faces. Check if ab is a segment.
        findedge(&cassh1, pa, pb);
        sspivot(cassh1, checkseg);
        if (checkseg.sh == dummysh) {
          // ab is not a segment - abd and abe belong to the same facet.
          //   The four points are forced to be coplanar.
          ori1 = 0.0;
        } else {
          // ab is a segment - abd and abe belong to two different facets.
          //   In principle, a, b, c and d can form a tetrahedron (since
          //   ori1 != 0.0).  However, we should avoid to create a very
          //   flat one which may induce to form a sequence of extremely
          //   badly-shaped or even wrong orientational tetrahedra. Hence,
          //   we use a larger epsilon to test if they're coplanar.
          if (iscoplanar(pa, pb, pd, pe, ori1, b->epsilon * 1e+2)) ori1 = 0.0;
        }
      } else {
        // abd and abe are not both boundary faces. Check if abd and bae
        //   are approximately coplanar with respect to the epsilon.
        if (iscoplanar(pa, pb, pd, pe, ori1, b->epsilon)) ori1 = 0.0;
      }
    }
    if (ori1 < 0.0) {
      // e lies above abd, unflipable, tet abde is not present.
#ifdef SELF_CHECK
      if (!nonconvex) {
        // abd and abe should not be hull faces, check it.
        fnext(horiz, casing);
        symself(casing);
        assert(casing.tet != dummytet);
        fnext(symhoriz, casing);
        symself(casing);
        assert(casing.tet != dummytet);
      }
#endif
      if (checksubfaces) {
        // The nonconvexbility may be casued by existing an subsegment.
        tsspivot(&horiz, &checkseg);
        if (checkseg.sh != dummysh) {
          return FORBIDDENEDGE;
        }
      }
      return UNFLIPABLE;
    }
    ori2 = orient3d(pb, pc, pd, pe);
    if (checksubfaces && ori2 != 0.0) {
      // Check if bcd and cbe are both boundary faces.
      enextfnext(horiz, casing);
      tspivot(casing, cassh1);
      enext2fnext(symhoriz, casing);
      tspivot(casing, cassh2);
      if (cassh1.sh != dummysh && cassh2.sh != dummysh) {
        // bcd and cbe are both boundary faces. Check if bc is a segment.
        findedge(&cassh1, pb, pc);
        sspivot(cassh1, checkseg);
        if (checkseg.sh == dummysh) {
          // bc is not a segment - bcd and cbe belong to the same facet.
          //   The four points are forced to be coplanar.
          ori2 = 0.0;
        } else {
          // bc is a segment - bcd and cbe belong to two different facets.
          //   In principle, b, c, d and e can form a tetrahedron (since
          //   ori2 != 0.0). Use a larger eps to test if they're coplanar.
          if (iscoplanar(pb, pc, pd, pe, ori2, b->epsilon * 1e+2)) ori2 = 0.0;
        } 
      } else {
        //  bcd and cbe are not both boundary faces. Check if bcd and cbe
        //   are approximately coplanar with respect to the epsilon.
        if (iscoplanar(pb, pc, pd, pe, ori2, b->epsilon)) ori2 = 0.0;
      }
    }
    if (ori2 < 0.0) {
      // e lies above bcd, unflipable, tet bcde is not present.
#ifdef SELF_CHECK
      if (!nonconvex) {
        // bcd and cbe should not be hull faces, check it.
        enextfnext(horiz, casing);
        symself(casing);
        assert(casing.tet != dummytet);
        enext2fnext(symhoriz, casing);
        symself(casing);
        assert(casing.tet != dummytet);
      }
#endif
      enextself(horiz);
      if (checksubfaces) {
        // The nonconvexbility may be casued by existing an subsegment.
        tsspivot(&horiz, &checkseg);
        if (checkseg.sh != dummysh) {
          return FORBIDDENEDGE;
        }
      }
      return UNFLIPABLE;
    } 
    ori3 = orient3d(pc, pa, pd, pe);
    if (checksubfaces && ori3 != 0.0) {
      // Check if cad and ace are both boundary faces.
      enext2fnext(horiz, casing);
      tspivot(casing, cassh1);
      enextfnext(symhoriz, casing);
      tspivot(casing, cassh2);
      if (cassh1.sh != dummysh && cassh2.sh != dummysh) {
        // cad and ace are both boundary faces. Check if ca is a segment.
        findedge(&cassh1, pc, pa);
        sspivot(cassh1, checkseg);
        if (checkseg.sh == dummysh) {
          // ca is not a segment - cad and ace belong to the same facet.
          //   The four points are forced to be coplanar.
          ori3 = 0.0;
        } else {
          // ca is a segment - cad and ace belong to two different facets.
          //   In principle, c, a, d and e can form a tetrahedron (since
          //   ori3 != 0.0). Use a larger eps to test if they're coplanar.
          if (iscoplanar(pc, pa, pd, pe, ori3, b->epsilon * 1e+2)) ori3 = 0.0;
        } 
      } else {
        // cad and ace are not both boundary faces. Check if cad and ace
        //   are approximately coplanar with respect to the epsilon.
        if (iscoplanar(pc, pa, pd, pe, ori3, b->epsilon)) ori3 = 0.0;
      }
    }
    if (ori3 < 0.0) {
      // e lies above cad, unflipable, tet cade is not present.
#ifdef SELF_CHECK
      if (!nonconvex) {
        // cad and ace should not be hull faces, check it.
        enext2fnext(horiz, casing);
        symself(casing);
        assert(casing.tet != dummytet);
        enextfnext(symhoriz, casing);
        symself(casing);
        assert(casing.tet != dummytet);
      }
#endif
      enext2self(horiz);
      if (checksubfaces) {
        // The nonconvexbility may be casued by existing an subsegment.
        tsspivot(&horiz, &checkseg);
        if (checkseg.sh != dummysh) {
          return FORBIDDENEDGE;
        }
      }
      return UNFLIPABLE;
    }
    if (ori1 == 0.0) {
      // e is coplanar with abd.
      if (ori2 * ori3 == 0.0) {
        // only one zero is possible.
        // assert(!(ori2 == 0.0 && ori3 == 0.0));
        // Three points (d, e, and a or b) are collinear, abc is unflipable
        //   and locally Delaunay.
        return NONCONVEX;
      }
    } else if (ori2 == 0.0) {
      // e is coplanar with bcd.
      if (ori1 * ori3 == 0.0) {
        // only one zero is possible.
        // assert(!(ori1 == 0.0 && ori3 == 0.0));
        // Three points (d, e, and b or c) are collinear, abc is unflipable
        //   and locally Delaunay.
        return NONCONVEX;
      }
      // Adjust 'horiz' and 'symhoriz' be the edge bc.
      enextself(horiz);
      enext2self(symhoriz);
    } else if (ori3 == 0.0) {
      // e is coplanar with cad.
      if (ori1 * ori2 == 0.0) {
        // only one zero is possible.
        // assert(!(ori1 == 0.0 && ori2 == 0.0));
        // Three points (d, e, and c or a) are collinear, abc is unflipable
        //   and locally Delaunay.
        return NONCONVEX;
      }
      // Adjust 'horiz' and 'symhoriz' be the edge ca.
      enext2self(horiz);
      enextself(symhoriz);
    } else {
      // e lies below all three faces, flipable.
      if (checksubfaces) {
        tspivot(horiz, checksh);
        if (checksh.sh != dummysh) {
          // To flip a subface is forbidden.
          return FORBIDDENFACE;
        }
      }
      return T23;
    }
    // Four points are coplanar, T22 or T44 is possible.
    if (checksubfaces) {
      tsspivot(&horiz, &checkseg);
      if (checkseg.sh != dummysh) {
        // To flip a subsegment is forbidden.
        return FORBIDDENEDGE;
      }
      tspivot(horiz, checksh);
      if (checksh.sh != dummysh) {
        // To flip a subface is forbidden.
        return FORBIDDENFACE;
      }
    }
    // Assume the four coplanar points are a, b, d, e, abd and abe are two
    //   coplanar faces. If both abd and abe are hull faces, flipable(T22).
    //   If they are interior faces, get the opposite tetrahedra abdf and
    //   abeg, if f = g, flipable (T44). Otherwise, unflipable.
    pf = pg = (point) NULL;
    fnext(horiz, casing);
    symself(casing);
    if (casing.tet != dummytet) {
      pf = oppo(casing);
    }
    fnext(symhoriz, casing);
    symself(casing);
    if (casing.tet != dummytet) {
      pg = oppo(casing);
    }
    if (pf == pg) {
      // Either T22 (pf == pg == NULL) or T44 (pf and pg) is possible.
      if (checksubfaces) {
        // Retreat the corner points a, b, and c.
        pa = org(horiz);
        pb = dest(horiz);
        pc = apex(horiz);
        // Be careful not to create an inverted tetrahedron. Check the case.
        ori1 = orient3d(pc, pd, pe, pa);
        if (ori1 <= 0) return NONCONVEX;
        ori1 = orient3d(pd, pc, pe, pb);
        if (ori1 <= 0) return NONCONVEX;
        if (pf != (point) NULL) {
          ori1 = orient3d(pd, pf, pe, pa);
          if (ori1 <= 0) return NONCONVEX;
          ori1 = orient3d(pf, pd, pe, pb);
          if (ori1 <= 0) return NONCONVEX;
        }
      }
      if (pf == (point) NULL) {
        // abd and abe are hull faces, flipable.
        return T22;
      } else {
        // abd and abe are interior faces, flipable.
        assert(pf != (point) NULL);
        return T44;
      }
    } else {
      // ab has more than four faces around it, unflipable.
      return UNFLIPABLE;
    }
  } else if (adjtet == 1) {
    // One of its three edges is locally non-convex. Type T32 is possible.
    // Adjust current configuration so that edge ab is non-convex.
    if (bcdoppo == pe) {
      // Edge bc is non-convex. Adjust 'horiz' and 'symhoriz' be edge bc.
      enextself(horiz);
      enext2self(symhoriz);
      pa = org(horiz);
      pb = dest(horiz);
      pc = apex(horiz);
    } else if (cadoppo == pe) {
      // Edge ca is non-convex. Adjust 'horiz' and 'symhoriz' be edge ca.
      enext2self(horiz);
      enextself(symhoriz);
      pa = org(horiz);
      pb = dest(horiz);
      pc = apex(horiz);
    } else {
      // Edge ab is non-convex.
      assert(abdoppo == pe);
    } // Now ab is the non-convex edge.
    // In order to be flipable, ab should cross face cde. Check it.
    ori1 = orient3d(pc, pd, pe, pa);
    if (checksubfaces && ori1 != 0.0) {
      // Check if cad and ace are both boundary faces.
      enext2fnext(horiz, casing);
      tspivot(casing, cassh1);
      enextfnext(symhoriz, casing);
      tspivot(casing, cassh2);
      if (cassh1.sh != dummysh && cassh2.sh != dummysh) {
        // cad and ace are both boundary faces. Check if ca is a segment.
        findedge(&cassh1, pc, pa);
        sspivot(cassh1, checkseg);
        if (checkseg.sh == dummysh) {
          // ca is not a segment. cad and ace belong to the same facet.
          //   The four points are forced to be coplanar.
          ori1 = 0.0;
        } else {
          // ca is a segment. cad and ace belong to different facets.
          //   In principle, c, d, e, and a can form a tetrahedron (since
          //   ori1 != 0.0).  However, we should avoid to create a very
          //   flat tet. Use a larger epsilon to test if they're coplanar.
          if (iscoplanar(pc, pd, pe, pa, ori1, b->epsilon * 1e+2)) ori1 = 0.0;
        }
      } else {
        // Check if c, d, e, and a are approximately coplanar.
        if (iscoplanar(pc, pd, pe, pa, ori1, b->epsilon)) ori1 = 0.0;
      }
    }
    if (ori1 <= 0.0) {
      // a lies above or is coplanar cde, abc is locally Delaunay.
      return NONCONVEX;
    }
    ori2 = orient3d(pd, pc, pe, pb);
    if (checksubfaces && ori2 != 0.0) {
      // Check if bcd and cbe are both boundary faces.
      enextfnext(horiz, casing);
      tspivot(casing, cassh1);
      enext2fnext(symhoriz, casing);
      tspivot(casing, cassh2);
      if (cassh1.sh != dummysh && cassh2.sh != dummysh) {
        // bcd and cbe are both boundary faces. Check if bc is a segment.
        findedge(&cassh1, pb, pc);
        sspivot(cassh1, checkseg);
        if (checkseg.sh == dummysh) {
          // bc is not a segment. bcd and cbe belong to the same facet.
          //   The four points are forced to be coplanar.
          ori2 = 0.0;
        } else {
          // bc is a segment. bcd and cbe belong to different facets.
          //   In principle, d, c, e, and b can form a tetrahedron (since
          //   ori2 != 0.0).  However, we should avoid to create a very
          //   flat tet. Use a larger epsilon to test if they're coplanar.
          if (iscoplanar(pd, pc, pe, pb, ori2, b->epsilon * 1e+2)) ori2 = 0.0;
        }
      } else {
        // Check if d, c, e, and b are approximately coplanar.
        if (iscoplanar(pd, pc, pe, pb, ori2, b->epsilon)) ori2 = 0.0;
      }
    }
    if (ori2 <= 0.0) {
      // b lies above dce, unflipable, and abc is locally Delaunay.
      return NONCONVEX;
    }
    // Edge ab crosses face cde properly.
    if (checksubfaces) {
      // If abc is subface, then ab must be a subsegment (because abde is
      //   a tetrahedron and ab crosses cde properly). 
      tsspivot(&horiz, &checkseg);
      if (checkseg.sh != dummysh) {
        // To flip a subsegment is forbidden.
        return FORBIDDENEDGE;
      }
      // Both abd and bae should not be subfaces (because they're not
      //   coplanar and ab is not a subsegment). However, they may be
      //   subfaces and belong to a facet (created during facet recovery),
      //   that is, abde is an invalid tetrahedron. Find this case out.
      fnext(horiz, casing);
      tspivot(casing, cassh1);
      fnext(symhoriz, casing);
      tspivot(casing, cassh2); 
      if (cassh1.sh != dummysh || cassh2.sh != dummysh) {
        // Unfortunately, they're subfaces. Corrections need be done here.
        printf("Warning:  A tetrahedron spans two subfaces of a facet.\n");
        // Temporarily, let it be there.
        return UNFLIPABLE;
      }
    }
    return T32;
  } else {
    assert(adjtet == 2);
    // The convex hull of {a, b, c, d, e} has only four vertices, abc is
    //   unflipable, furthermore, it is locally Delaunay.
    return NONCONVEX;
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// enqueueflipface(), enqueueflipedge()    Add a face or an edge to the end  //
//                                         of a queue.                       //
//                                                                           //
// This face or edge may be non-Delaunay and will be checked.  Corresponding //
// flip operation will be applied on it if it is non-Delaunay.  The vertices //
// of the face or edge are stored seperatly used to ensure the face or edge  //
// is still the same one when we save it.  Sometimes, other flipping will    //
// cause this face or edge be changed or dead.                               //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::enqueueflipface(triface& checkface, queue* flipqueue)
{
  badface *queface;

  queface = (badface *) flipqueue->push((void *) NULL);
  queface->tt = checkface;
  queface->forg = org(checkface);
  queface->fdest = dest(checkface);
  queface->fapex = apex(checkface);
}

void tetgenmesh::enqueueflipedge(face& checkedge, queue* flipqueue)
{
  badface *queface;

  queface = (badface *) flipqueue->push((void *) NULL);
  queface->ss = checkedge;
  queface->forg = sorg(checkedge);
  queface->fdest = sdest(checkedge);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// flip23()    Perform a 2-to-3 flip.                                        //
//                                                                           //
// On input, 'flipface' represents the face will be flipped.  Let it is abc, //
// the two tetrahedra sharing abc are abcd, bace. abc is not a subface.      //
//                                                                           //
// A 2-to-3 flip is to change two tetrahedra abcd, bace to three tetrahedra  //
// edab, edbc, and edca.  As a result, face abc has been removed and three   //
// new faces eda, edb and edc have been created.                             //
//                                                                           //
// On completion, 'flipface' returns edab.  If 'flipqueue' is not NULL, all  //
// possibly non-Delaunay faces are added into it.                            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::flip23(triface* flipface, queue* flipqueue)
{
  triface abcd, bace;                                  // Old configuration.
  triface oldabd, oldbcd, oldcad;
  triface abdcasing, bcdcasing, cadcasing;
  face abdsh, bcdsh, cadsh;
  triface oldbae, oldcbe, oldace;
  triface baecasing, cbecasing, acecasing;
  face baesh, cbesh, acesh;
  triface edab, edbc, edca;                            // New configuration.
  point pa, pb, pc, pd, pe;
  REAL attrib, volume;
  int i;

  abcd = *flipface;
  adjustedgering(abcd, CCW); // abcd represents edge ab.
  sym(abcd, bace);
  findedge(&bace, dest(abcd), org(abcd)); // bace represents edge ba.
  pa = org(abcd);
  pb = dest(abcd);
  pc = apex(abcd);
  pd = oppo(abcd);
  pe = oppo(bace);

  if (b->verbose > 2) {
    printf("    Do T23 on face (%d, %d, %d, %d).\n", pointmark(pa),
           pointmark(pb), pointmark(pc), pointmark(pd));
  }
  flip23s++;

#ifdef SELF_CHECK
  // Edge de must cross face abc properly.
  assert(orient3d(pa, pb, pd, pe) >= 0.0);
  assert(orient3d(pb, pc, pd, pe) >= 0.0);
  assert(orient3d(pc, pa, pd, pe) >= 0.0);
#endif

  // Storing the old configuration outside the convex hull.
  fnext(abcd, oldabd);
  enextfnext(abcd, oldbcd);
  enext2fnext(abcd, oldcad);
  fnext(bace, oldbae);
  enext2fnext(bace, oldcbe);
  enextfnext(bace, oldace);
  sym(oldabd, abdcasing);
  sym(oldbcd, bcdcasing);
  sym(oldcad, cadcasing);
  sym(oldbae, baecasing);
  sym(oldcbe, cbecasing);
  sym(oldace, acecasing);
  if (checksubfaces) {
    tspivot(oldabd, abdsh);
    tspivot(oldbcd, bcdsh);
    tspivot(oldcad, cadsh);
    tspivot(oldbae, baesh);
    tspivot(oldcbe, cbesh);
    tspivot(oldace, acesh);
  }

  // Creating the new configuration inside the convex hull.
  edab.tet = abcd.tet; // Update abcd to be edab.
  setorg (edab, pe);
  setdest(edab, pd);
  setapex(edab, pa);
  setoppo(edab, pb);
  edbc.tet = bace.tet; // Update bace to be edbc.
  setorg (edbc, pe);
  setdest(edbc, pd);
  setapex(edbc, pb);
  setoppo(edbc, pc);
  maketetrahedron(&edca); // Create edca.
  setorg (edca, pe);
  setdest(edca, pd);
  setapex(edca, pc);
  setoppo(edca, pa);
  // Set the element attributes of the new tetrahedron 'edca'.
  for (i = 0; i < in->numberoftetrahedronattributes; i++) {
    attrib = elemattribute(abcd.tet, i);
    setelemattribute(edca.tet, i, attrib);
  }
  // Set the volume constraint of the new tetrahedron 'edca' if the -ra
  //   switches are not used together. In -ra case, the various volume
  //   constraints can be spreaded very far.
  if (b->varvolume && !b->refine) {
    volume = volumebound(abcd.tet);
    setvolumebound(edca.tet, volume);
  }

  // Clear old bonds in edab(was abcd) and edbc(was bace).
  for (i = 0; i < 4; i ++) {
    edab.loc = i;
    dissolve(edab);
    edbc.loc = i;
    dissolve(edbc);
  }
  // Bond the faces inside the convex hull.
  edab.loc = 0;
  edca.loc = 1;
  bond(edab, edca);
  edab.loc = 1;
  edbc.loc = 0;
  bond(edab, edbc);
  edbc.loc = 1;
  edca.loc = 0;
  bond(edbc, edca);
  // Bond the faces on the convex hull.
  edab.loc = 2;
  bond(edab, abdcasing);
  edab.loc = 3;
  bond(edab, baecasing);
  edbc.loc = 2;
  bond(edbc, bcdcasing);
  edbc.loc = 3;
  bond(edbc, cbecasing);
  edca.loc = 2;
  bond(edca, cadcasing);
  edca.loc = 3;
  bond(edca, acecasing);  
  // There may exist subfaces that need to be bonded to new configuarton.
  if (checksubfaces) {
    // Clear old flags in edab(was abcd) and edbc(was bace).
    for (i = 0; i < 4; i ++) {
      edab.loc = i;
      tsdissolve(edab);
      edbc.loc = i;
      tsdissolve(edbc);
    }
    if (abdsh.sh != dummysh) {
      edab.loc = 2; 
      tsbond(edab, abdsh);
    }
    if (baesh.sh != dummysh) {
      edab.loc = 3; 
      tsbond(edab, baesh);
    }
    if (bcdsh.sh != dummysh) {
      edbc.loc = 2; 
      tsbond(edbc, bcdsh);
    }
    if (cbesh.sh != dummysh) {
      edbc.loc = 3; 
      tsbond(edbc, cbesh);
    }
    if (cadsh.sh != dummysh) {
      edca.loc = 2; 
      tsbond(edca, cadsh);
    }
    if (acesh.sh != dummysh) {
      edca.loc = 3; 
      tsbond(edca, acesh);
    }
  }

  edab.loc = 0;
  edbc.loc = 0;
  edca.loc = 0;
  if (b->verbose > 3) {
    printf("    Updating edab ");
    printtet(&edab);
    printf("    Updating edbc ");
    printtet(&edbc);
    printf("    Creating edca ");
    printtet(&edca);
  }

  if (flipqueue != (queue *) NULL) { 
    enextfnext(edab, abdcasing);
    enqueueflipface(abdcasing, flipqueue);
    enext2fnext(edab, baecasing);
    enqueueflipface(baecasing, flipqueue);
    enextfnext(edbc, bcdcasing);
    enqueueflipface(bcdcasing, flipqueue);
    enext2fnext(edbc, cbecasing);
    enqueueflipface(cbecasing, flipqueue);
    enextfnext(edca, cadcasing);
    enqueueflipface(cadcasing, flipqueue);
    enext2fnext(edca, acecasing);
    enqueueflipface(acecasing, flipqueue);  
  }

  // Save a live handle in 'recenttet'.
  recenttet = edbc;
  // Set the return handle be edab.
  *flipface = edab;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// flip32()    Perform a 3-to-2 flip.                                        //
//                                                                           //
// On input, 'flipface' represents the face will be flipped.  Let it is eda, //
// where edge ed is locally non-convex. Three tetrahedra sharing ed are edab,//
// edbc, and edca.  ed is not a subsegment.                                  //
//                                                                           //
// A 3-to-2 flip is to change the three tetrahedra edab, edbc, and edca into //
// another two tetrahedra abcd and bace.  As a result, the edge ed has been  //
// removed and the face abc has been created.                                //
//                                                                           //
// On completion, 'flipface' returns abcd.  If 'flipqueue' is not NULL, all  //
// possibly non-Delaunay faces are added into it.                            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::flip32(triface* flipface, queue* flipqueue)
{
  triface edab, edbc, edca;                            // Old configuration.
  triface oldabd, oldbcd, oldcad;
  triface abdcasing, bcdcasing, cadcasing;
  face abdsh, bcdsh, cadsh;
  triface oldbae, oldcbe, oldace;
  triface baecasing, cbecasing, acecasing;
  face baesh, cbesh, acesh;
  triface abcd, bace;                                  // New configuration.
  point pa, pb, pc, pd, pe;
  int i;

  edab = *flipface;
  adjustedgering(edab, CCW);
  fnext(edab, edbc);
  symself(edbc);
  findedge(&edbc, org(edab), dest(edab));
  fnext(edbc, edca);
  symself(edca);
  findedge(&edca, org(edab), dest(edab));
  pa = apex(edab);
  pb = oppo(edab);
  pc = oppo(edbc);
  pd = dest(edab);
  pe = org(edab);

  if (b->verbose > 2) {
    printf("    Do T32 on face (%d, %d, %d, %d).\n",
           pointmark(pe), pointmark(pd), pointmark(pa), pointmark(pb));
  }
  flip32s++;

#ifdef SELF_CHECK
  // Edge de must cross face abc properly.
  assert(orient3d(pa, pb, pc, pd) <= 0.0);
  assert(orient3d(pb, pa, pc, pe) <= 0.0);
#endif

  // Storing the old configuration outside the convex hull.
  enextfnext(edab, oldabd);
  enext2fnext(edab, oldbae);
  enextfnext(edbc, oldbcd);
  enext2fnext(edbc, oldcbe);
  enextfnext(edca, oldcad);
  enext2fnext(edca, oldace);
  sym(oldabd, abdcasing);
  sym(oldbcd, bcdcasing);
  sym(oldcad, cadcasing);
  sym(oldbae, baecasing);
  sym(oldcbe, cbecasing);
  sym(oldace, acecasing);
  if (checksubfaces) {
    tspivot(oldabd, abdsh);
    tspivot(oldbcd, bcdsh);
    tspivot(oldcad, cadsh);
    tspivot(oldbae, baesh);
    tspivot(oldcbe, cbesh);
    tspivot(oldace, acesh);
  }

  // Creating the new configuration inside the convex hull.
  abcd.tet = edab.tet; // Update edab to be abcd.
  setorg (abcd, pa);
  setdest(abcd, pb);
  setapex(abcd, pc);
  setoppo(abcd, pd);
  bace.tet = edbc.tet; // Update edbc to be bace.
  setorg (bace, pb);
  setdest(bace, pa);
  setapex(bace, pc);
  setoppo(bace, pe);
  // Dealloc a redundant tetrahedron (edca).
  tetrahedrondealloc(edca.tet); 

  // Clear the old bonds in abcd (was edab) and bace (was edbc).
  for (i = 0; i < 4; i ++) {
    abcd.loc = i;
    dissolve(abcd);
    bace.loc = i;
    dissolve(bace);
  }
  // Bond the inside face of the convex hull.
  abcd.loc = 0;
  bace.loc = 0;
  bond(abcd, bace);
  // Bond the outside faces of the convex hull.
  abcd.loc = 1;
  bond(abcd, abdcasing);
  abcd.loc = 2;
  bond(abcd, bcdcasing);
  abcd.loc = 3;
  bond(abcd, cadcasing);
  bace.loc = 1;
  bond(bace, baecasing);
  bace.loc = 3;
  bond(bace, cbecasing);
  bace.loc = 2;
  bond(bace, acecasing);
  if (checksubfaces) {
    // Clear old bonds in abcd(was edab) and bace(was edbc).
    for (i = 0; i < 4; i ++) {
      abcd.loc = i;
      tsdissolve(abcd);
      bace.loc = i;
      tsdissolve(bace);
    }
    if (abdsh.sh != dummysh) {
      abcd.loc = 1;
      tsbond(abcd, abdsh);
    }
    if (baesh.sh != dummysh) {
      bace.loc = 1;
      tsbond(bace, baesh);
    }
    if (bcdsh.sh != dummysh) {
      abcd.loc = 2;
      tsbond(abcd, bcdsh);
    }
    if (cbesh.sh != dummysh) {
      bace.loc = 3;
      tsbond(bace, cbesh);
    }
    if (cadsh.sh != dummysh) {
      abcd.loc = 3;
      tsbond(abcd, cadsh);
    }
    if (acesh.sh != dummysh) {
      bace.loc = 2;
      tsbond(bace, acesh);
    }
  }

  abcd.loc = 0;
  bace.loc = 0;
  if (b->verbose > 3) {
    printf("    Updating abcd ");
    printtet(&abcd);
    printf("    Updating bace ");
    printtet(&bace);
    printf("    Deleting edca ");
    printtet(&edca);
  }

  if (flipqueue != (queue *) NULL) { 
    fnext(abcd, abdcasing);
    enqueueflipface(abdcasing, flipqueue);
    fnext(bace, baecasing);
    enqueueflipface(baecasing, flipqueue);
    enextfnext(abcd, bcdcasing);
    enqueueflipface(bcdcasing, flipqueue);
    enextfnext(bace, cbecasing);
    enqueueflipface(cbecasing, flipqueue);
    enext2fnext(abcd, cadcasing);
    enqueueflipface(cadcasing, flipqueue);
    enext2fnext(bace, acecasing);
    enqueueflipface(acecasing, flipqueue);  
  }

  // Save a live handle in 'recenttet'.
  recenttet = abcd;
  // Set the return handle be abcd.
  *flipface = abcd;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// flip22()    Perform a 2-to-2 (or 4-to-4) flip.                            //
//                                                                           //
// On input, 'flipface' represents the face will be flipped.  Let it is abe, //
// ab is the flipable edge, the two tetrahedra sharing abe are abce and bade,//
// hence a, b, c and d are coplanar. If abc, bad are interior faces, the two //
// tetrahedra opposite to e are bacf and abdf.  ab is not a subsegment.      //
//                                                                           //
// A 2-to-2 flip is to change two tetrahedra abce and bade into another two  //
// tetrahedra dcae and cdbe. If bacf and abdf exist, they're changed to cdaf //
// and dcbf, thus a 4-to-4 flip.  As a result, two or four tetrahedra have   //
// rotated counterclockwise (using right-hand rule with thumb points to e):  //
// abce->dcae, bade->cdbe, and bacf->cdaf, abdf->dcbf.                       //
//                                                                           //
// If abc and bad are subfaces, a 2-to-2 flip is performed simultaneously by //
// calling routine flip22sub(), hence abc->dca, bad->cdb.  The edge rings of //
// the flipped subfaces dca and cdb have the same orientation as abc and bad.//
// Hence, they have the same orientation as other subfaces of the facet with //
// respect to the lift point of this facet.                                  //
//                                                                           //
// On completion, 'flipface' holds edge dc of tetrahedron dcae. 'flipqueue'  //
// contains all possibly non-Delaunay faces if it is not NULL.               //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::flip22(triface* flipface, queue* flipqueue)
{
  triface abce, bade;
  triface oldbce, oldcae, oldade, olddbe;
  triface bcecasing, caecasing, adecasing, dbecasing;
  face bcesh, caesh, adesh, dbesh;
  triface bacf, abdf;
  triface oldacf, oldcbf, oldbdf, olddaf;
  triface acfcasing, cbfcasing, bdfcasing, dafcasing;
  face acfsh, cbfsh, bdfsh, dafsh;
  face abc, bad;
  point pa, pb, pc, pd, pe, pf;
  int mirrorflag;

  adjustedgering(*flipface, CCW); // 'flipface' is bae.
  fnext(*flipface, abce);
  esymself(abce);
  adjustedgering(*flipface, CW); // 'flipface' is abe.
  fnext(*flipface, bade);
  assert(bade.tet != dummytet);
  esymself(bade);
  pa = org(abce);
  pb = dest(abce);
  pc = apex(abce);
  pd = apex(bade);
  pe = oppo(bade);
  assert(oppo(abce) == pe);
  sym(abce, bacf);
  mirrorflag = bacf.tet != dummytet;
  if (mirrorflag) {
    findedge(&bacf, pb, pa);
    sym(bade, abdf);
    assert(abdf.tet != dummytet);
    findedge(&abdf, pa, pb);
    pf = oppo(bacf);
    assert(oppo(abdf) == pf);
  } 

  if (b->verbose > 2) {
    printf("    Do %s on edge (%d, %d).\n", mirrorflag ? "T44" : "T22",
           pointmark(pa), pointmark(pb));
  }
  mirrorflag ? flip44s++ : flip22s++;

#ifdef SELF_CHECK
  // The quadrilateral formed by a, b, c, and d must be convex.
  assert(orient3d(pc, pd, pe, pa) <= 0.0);
  assert(orient3d(pd, pc, pe, pb) <= 0.0);
#endif
  
  // Save the old configuration at the convex hull.
  enextfnext(abce, oldbce);
  enext2fnext(abce, oldcae);
  enextfnext(bade, oldade);
  enext2fnext(bade, olddbe);
  sym(oldbce, bcecasing);
  sym(oldcae, caecasing);
  sym(oldade, adecasing);
  sym(olddbe, dbecasing);
  if (checksubfaces) {
    tspivot(oldbce, bcesh);
    tspivot(oldcae, caesh);
    tspivot(oldade, adesh);
    tspivot(olddbe, dbesh);
    tspivot(abce, abc);
    tspivot(bade, bad);
  }
  if (mirrorflag) {
    enextfnext(bacf, oldacf);
    enext2fnext(bacf, oldcbf);
    enextfnext(abdf, oldbdf);
    enext2fnext(abdf, olddaf);
    sym(oldacf, acfcasing);
    sym(oldcbf, cbfcasing);
    sym(oldbdf, bdfcasing);
    sym(olddaf, dafcasing);
    if (checksubfaces) {
      tspivot(oldacf, acfsh);
      tspivot(oldcbf, cbfsh);
      tspivot(oldbdf, bdfsh);
      tspivot(olddaf, dafsh);
    }
  }

  // Rotate abce, bade one-quarter turn counterclockwise.
  bond(oldbce, caecasing);
  bond(oldcae, adecasing);
  bond(oldade, dbecasing);
  bond(olddbe, bcecasing);
  if (checksubfaces) {
    // Check for subfaces and rebond them to the rotated tets.
    if (caesh.sh == dummysh) {
      tsdissolve(oldbce);
    } else {
      tsbond(oldbce, caesh);
    }
    if (adesh.sh == dummysh) {
      tsdissolve(oldcae);
    } else {
      tsbond(oldcae, adesh);
    }
    if (dbesh.sh == dummysh) {
      tsdissolve(oldade);
    } else {
      tsbond(oldade, dbesh);
    }
    if (bcesh.sh == dummysh) {
      tsdissolve(olddbe);
    } else {
      tsbond(olddbe, bcesh);
    }
  }
  if (mirrorflag) {
    // Rotate bacf, abdf one-quarter turn counterclockwise.
    bond(oldcbf, acfcasing);
    bond(oldacf, dafcasing);
    bond(olddaf, bdfcasing);
    bond(oldbdf, cbfcasing);
    if (checksubfaces) {
      // Check for subfaces and rebond them to the rotated tets.
      if (acfsh.sh == dummysh) {
        tsdissolve(oldcbf);
      } else {
        tsbond(oldcbf, acfsh);
      }
      if (dafsh.sh == dummysh) {
        tsdissolve(oldacf);
      } else {
        tsbond(oldacf, dafsh);
      }
      if (bdfsh.sh == dummysh) {
        tsdissolve(olddaf);
      } else {
        tsbond(olddaf, bdfsh);
      }
      if (cbfsh.sh == dummysh) {
        tsdissolve(oldbdf);
      } else {
        tsbond(oldbdf, cbfsh);
      }
    }
  }

  // New vertex assignments for the rotated tetrahedra.
  setorg(abce, pd); // Update abce to dcae
  setdest(abce, pc);
  setapex(abce, pa);
  setorg(bade, pc); // Update bade to cdbe
  setdest(bade, pd);
  setapex(bade, pb);
  if (mirrorflag) {
    setorg(bacf, pc); // Update bacf to cdaf
    setdest(bacf, pd);
    setapex(bacf, pa);
    setorg(abdf, pd); // Update abdf to dcbf
    setdest(abdf, pc);
    setapex(abdf, pb);
  }

  // Are there subfaces need to be flipped?
  if (checksubfaces && abc.sh != dummysh) {
    assert(bad.sh != dummysh);
    // Adjust the edge be ab, so the rotation of subfaces is according with
    //   the rotation of tetrahedra.
    findedge(&abc, pa, pb);
    // Flip an edge of two subfaces, ignore non-Delaunay edges.
    flip22sub(&abc, NULL);
  }

  if (b->verbose > 3) {
    printf("    Updating abce ");
    printtet(&abce);
    printf("    Updating bade ");
    printtet(&bade);
    if (mirrorflag) {
      printf("    Updating bacf ");
      printtet(&bacf);
      printf("    Updating abdf ");
      printtet(&abdf);
    }
  }

  if (flipqueue != (queue *) NULL) { 
    enextfnext(abce, bcecasing);
    enqueueflipface(bcecasing, flipqueue);
    enext2fnext(abce, caecasing);
    enqueueflipface(caecasing, flipqueue);
    enextfnext(bade, adecasing);
    enqueueflipface(adecasing, flipqueue);
    enext2fnext(bade, dbecasing);
    enqueueflipface(dbecasing, flipqueue);
    if (mirrorflag) {
      enextfnext(bacf, acfcasing);
      enqueueflipface(acfcasing, flipqueue);
      enext2fnext(bacf, cbfcasing);
      enqueueflipface(cbfcasing, flipqueue);
      enextfnext(abdf, bdfcasing);
      enqueueflipface(bdfcasing, flipqueue);
      enext2fnext(abdf, dafcasing);
      enqueueflipface(dafcasing, flipqueue);
    }
    // The two new faces dcae (abce), cdbe (bade) may still not be locally
    //   Delaunay, and may need be flipped (flip23).  On the other hand, in
    //   conforming Delaunay algorithm, two new subfaces dca (abc), and cdb
    //   (bad) may be non-conforming Delaunay, they need be queued if they
    //   are locally Delaunay but non-conforming Delaunay.
    enqueueflipface(abce, flipqueue);
    enqueueflipface(bade, flipqueue);
  }

  // Save a live handle in 'recenttet'.
  recenttet = abce;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// flip22sub()    Perform a 2-to-2 flip on a subface edge.                   //
//                                                                           //
// The flip edge is given by subface 'flipedge'.  Let it is abc, where ab is //
// the flipping edge.  The other subface is bad,  where a, b, c, d form a    //
// convex quadrilateral.  ab is not a subsegment.                            //
//                                                                           //
// A 2-to-2 subface flip is to change two subfaces abc and bad to another    //
// two subfaces dca and cdb.  Hence, edge ab has been removed and dc becomes //
// an edge. If a point e is above abc, this flip is equal to rotate abc and  //
// bad counterclockwise using right-hand rule with thumb points to e. It is  //
// important to know that the edge rings of the flipped subfaces dca and cdb //
// are keeping the same orientation as their original subfaces. So they have //
// the same orientation with respect to the lift point of this facet.        //
//                                                                           //
// During rotating, the face rings of the four edges bc, ca, ad, and de need //
// be re-connected. If the edge is not a subsegment, then its face ring has  //
// only two faces, a sbond() will bond them together. If it is a subsegment, //
// one should use sbond1() twice to bond two different handles to the rotat- //
// ing subface, one is predecssor (-casin), another is successor (-casout).  //
//                                                                           //
// If 'flipqueue' is not NULL, it returns four edges bc, ca, ad, de, which   //
// may be non-Delaunay.                                                      //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::flip22sub(face* flipedge, queue* flipqueue)
{
  face abc, bad;
  face oldbc, oldca, oldad, olddb;
  face bccasin, bccasout, cacasin, cacasout;
  face adcasin, adcasout, dbcasin, dbcasout;
  face bc, ca, ad, db;
  face spinsh;
  point pa, pb, pc, pd;

  abc = *flipedge;
  spivot(abc, bad);
  if (sorg(bad) != sdest(abc)) {
    sesymself(bad);
  }
  pa = sorg(abc);
  pb = sdest(abc);
  pc = sapex(abc);
  pd = sapex(bad);

  if (b->verbose > 2) {
    printf("    Flip sub edge (%d, %d).\n", pointmark(pa), pointmark(pb));
  }

  // Save the old configuration outside the quadrilateral.  
  senext(abc, oldbc);
  senext2(abc, oldca);
  senext(bad, oldad);
  senext2(bad, olddb);
  // Get the outside connection. Becareful if there is a subsegment on the
  //   quadrilateral, two casings (casin and casout) are needed to save for
  //   keeping the face link.
  spivot(oldbc, bccasout);
  sspivot(oldbc, bc);
  if (bc.sh != dummysh) {
    // 'bc' is a subsegment.
    assert(bccasout.sh != dummysh);
    if (oldbc.sh != bccasout.sh) {
      // 'oldbc' is not self-bonded.
      spinsh = bccasout;
      do {
        bccasin = spinsh;
        spivotself(spinsh);
      } while (spinsh.sh != oldbc.sh);
    } else {
      bccasout.sh = dummysh;
    }
    ssdissolve(oldbc);
  }
  spivot(oldca, cacasout);
  sspivot(oldca, ca);
  if (ca.sh != dummysh) {
    // 'ca' is a subsegment. 
    assert(cacasout.sh != dummysh);
    if (oldca.sh != cacasout.sh) {
      // 'oldca' is not self-bonded.
      spinsh = cacasout;
      do {
        cacasin = spinsh;
        spivotself(spinsh);
      } while (spinsh.sh != oldca.sh);
    } else {
      cacasout.sh = dummysh;
    }
    ssdissolve(oldca);
  }
  spivot(oldad, adcasout);
  sspivot(oldad, ad);
  if (ad.sh != dummysh) {
    // 'ad' is a subsegment. 
    assert(adcasout.sh != dummysh);
    if (oldad.sh != adcasout.sh) {
      // 'adcasout' is not self-bonded.
      spinsh = adcasout;
      do {
        adcasin = spinsh;
        spivotself(spinsh);
      } while (spinsh.sh != oldad.sh);
    } else {
      adcasout.sh = dummysh;
    }
    ssdissolve(oldad);
  }
  spivot(olddb, dbcasout);
  sspivot(olddb, db);
  if (db.sh != dummysh) {
    // 'db' is a subsegment.
    assert(dbcasout.sh != dummysh);
    if (olddb.sh != dbcasout.sh) {
      // 'dbcasout' is not self-bonded.
      spinsh = dbcasout;
      do {
        dbcasin = spinsh;
        spivotself(spinsh);
      } while (spinsh.sh != olddb.sh);
    } else {
      dbcasout.sh = dummysh;
    }
    ssdissolve(olddb);
  }

  // Rotate abc and bad one-quarter turn counterclockwise.
  if (ca.sh != dummysh) {
    if (cacasout.sh != dummysh) {
      sbond1(cacasin, oldbc);
      sbond1(oldbc, cacasout);
    } else {
      // Bond 'oldbc' to itself.
      sbond(oldbc, oldbc);
      // Make sure that dummysh always correctly bonded.
      dummysh[0] = sencode(oldbc);
    }
    ssbond(oldbc, ca);
  } else {
    sbond(oldbc, cacasout);
  }
  if (ad.sh != dummysh) {
    if (adcasout.sh != dummysh) {
      sbond1(adcasin, oldca);
      sbond1(oldca, adcasout);
    } else {
      // Bond 'oldca' to itself.
      sbond(oldca, oldca);
      // Make sure that dummysh always correctly bonded.
      dummysh[0] = sencode(oldca);
    }
    ssbond(oldca, ad);
  } else {
    sbond(oldca, adcasout);
  }
  if (db.sh != dummysh) {
    if (dbcasout.sh != dummysh) {
      sbond1(dbcasin, oldad);
      sbond1(oldad, dbcasout);
    } else {
      // Bond 'oldad' to itself.
      sbond(oldad, oldad);
      // Make sure that dummysh always correctly bonded.
      dummysh[0] = sencode(oldad);
    }
    ssbond(oldad, db);
  } else {
    sbond(oldad, dbcasout);
  }
  if (bc.sh != dummysh) {
    if (bccasout.sh != dummysh) {
      sbond1(bccasin, olddb);
      sbond1(olddb, bccasout);
    } else {
      // Bond 'olddb' to itself.
      sbond(olddb, olddb);
      // Make sure that dummysh always correctly bonded.
      dummysh[0] = sencode(olddb);
    }
    ssbond(olddb, bc);
  } else {
    sbond(olddb, bccasout);
  }

  // New vertex assignments for the rotated subfaces.
  setsorg(abc, pd);  // Update abc to dca.
  setsdest(abc, pc);
  setsapex(abc, pa);
  setsorg(bad, pc);  // Update bad to cdb.
  setsdest(bad, pd);
  setsapex(bad, pb);

  if (flipqueue != (queue *) NULL) {
    enqueueflipedge(bccasout, flipqueue);
    enqueueflipedge(cacasout, flipqueue);
    enqueueflipedge(adcasout, flipqueue);
    enqueueflipedge(dbcasout, flipqueue);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// flip()    Flips non-locally Delaunay faces in flipqueue until it is empty.//
//                                                                           //
// Assumpation:  Current tetrahedralization is non-Delaunay after inserting  //
// a point or performing a flip operation, all possibly non-Delaunay faces   //
// are in 'flipqueue'.                                                       //
//                                                                           //
// If 'plastflip' is not NULL,  it is used to return a stack of recently     //
// flipped faces.  This stack will be used to reverse the flips done in this //
// routine later for removing a newly inserted point because it encroaches   //
// any subfaces or subsegments.                                              //
//                                                                           //
// Flags 'chkencsegs', 'chkencsubs', and 'chkbadqual' are used for Delaunay  //
// refinement. If a face is determined to be locally Delaunay or unflipable, //
// 'chkencsegs' indicates to detect and queue encroach segment. 'chkencsubs' //
// demands to test and queue the bad quality or encroached subface. The tets //
// will be queued for quality check if 'chkbadqual' is TRUE.                 //
//                                                                           //
// The return value is the total number of flips done during this invocation.//
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

long tetgenmesh::
flip(queue* flipqueue, badface **plastflip, bool chkencsegs, bool chkencsubs,
     bool chkbadqual)
{
  badface *qface;
  badface *newflip;
  triface flipface, symface;
  face checkseg, checksh;
  enum fliptype fc;
  bool flipped;
  REAL sign, bakepsilon;
  long flipcount, maxfaces;
  int epscount, fcount;
  int i;

  if (b->verbose > 1) {
    printf("    Do flipface queue: %ld faces.\n", flipqueue->len());
  }

  flipcount = flip23s + flip32s + flip22s + flip44s;
  if (checksubfaces) {
    maxfaces = (4l * tetrahedrons->items + hullsize) / 2l;
    fcount = 0;
  }

  if (plastflip != (badface **) NULL) {
    // Initialize the stack of the flip sequence.
    flipstackers->restart();
    *plastflip = (badface *) NULL;
  }

  // Loop until the queue is empty.
  while (!flipqueue->empty()) {
    qface = (badface *) flipqueue->pop();
    flipface = qface->tt;
    // Check the validity of this face.
    if (isdead(&flipface) || flipface.tet == dummytet || 
        (org(flipface) != qface->forg) || 
        (dest(flipface) != qface->fdest) ||
        (apex(flipface) != qface->fapex) ||
        (oppo(flipface) == (point) NULL)) continue;
    flipped = false;
    sym(flipface, symface);
    // Only do check when the adjacent tet exists and it's not a "fake" tet.
    if (symface.tet != dummytet && oppo(symface) != (point) NULL) {
      // For positive orientation that insphere() test requires.
      adjustedgering(flipface, CW); 
      sign = insphere(org(flipface), dest(flipface), apex(flipface),
                      oppo(flipface), oppo(symface));
    } else {
      sign = -1.0; // A hull face is locally Delaunay.
    }
    if (sign > 0.0) {
      // 'flipface' is non-locally Delaunay, try to flip it.     
      if (checksubfaces) {
        fcount++;
        assert(fcount < maxfaces);
        bakepsilon = b->epsilon;
        epscount = 0;
        while (epscount < 32) {
          fc = categorizeface(flipface);
          if (fc == NONCONVEX) {
            b->epsilon *= 1e-1;
            epscount++;
            continue;
          }
          break;
        }
        b->epsilon = bakepsilon;
        if (epscount >= 32) {
          if (b->verbose) {
            printf("Warning:  Can't flip a degenerate tetrahedron.\n");
          }
          fc = NONCONVEX;
        }
      } else {
        fc = categorizeface(flipface);
        assert(fc != NONCONVEX);
      }
      switch (fc) {
      // The following face types are flipable.
      case T44:
      case T22:
        flip22(&flipface, flipqueue); 
        flipped = true;
        break;
      case T23:
        flip23(&flipface, flipqueue); 
        flipped = true;
        break;
      case T32:
        flip32(&flipface, flipqueue); 
        flipped = true;
        break;
      // The following face types are unflipable.
      case UNFLIPABLE:
        break;
      case FORBIDDENFACE:
        // Meet an encroaching subface, unflipable.
        break;
      case FORBIDDENEDGE:
        // Meet an encroaching subsegment, unflipable.
        break;
      // This case is only possible when the domain is nonconvex.
      case NONCONVEX:
        // assert(nonconvex);
        break;
      }
      if (plastflip != (badface **) NULL && flipped) { 
        // Push the flipped face into stack.
        newflip = (badface *) flipstackers->alloc();
        newflip->tt = flipface;
        newflip->key = (REAL) fc;
        newflip->forg = org(flipface);
        newflip->fdest = dest(flipface);
        newflip->fapex = apex(flipface);
        newflip->previtem = *plastflip;
        *plastflip = newflip;  
      }
    }
    if (!flipped) {
      if (chkencsegs) {
        assert(badsubsegs != (memorypool *) NULL);
        // Check for encroaching subsegments, add them into list.
        for (i = 0; i < 3; i++) {
          tsspivot(&flipface, &checkseg);
          if (checkseg.sh != dummysh) {
            if (!shell2badface(checkseg)) {
              if (varconstraint && (areabound(checkseg) > 0.0)) {
                checkseg4badqual(&checkseg, true);
              }
            }
            if (!shell2badface(checkseg)) {
              checkseg4encroach(&checkseg, NULL, NULL, true);
            }
          }
          enextself(flipface);
        }
      }
      if (chkencsubs) {
        assert(badsubfaces != (memorypool *) NULL);
        // Check for encroaching subface, add it into list.
        tspivot(flipface, checksh);
        if (checksh.sh != dummysh) {
          if (!shell2badface(checksh)) {
            checksub4badqual(&checksh, true);
          }
          if (!shell2badface(checksh)) {
            checksub4encroach(&checksh, NULL, true);
          }
        }
      }
      if (chkbadqual) {
        // Put the tetrahedra at both sides into list for quality check.
        qualchecktetlist->append(&flipface);
        if (symface.tet != dummytet) {
          qualchecktetlist->append(&symface);
        }
      }
    }
  }

  flipcount = flip23s + flip32s + flip22s + flip44s - flipcount;
  if (b->verbose > 1) {
    printf("    %ld flips.\n", flipcount);
  }

  return flipcount;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// undoflip()    Undo the most recent flip sequence induced by flip().       //
//                                                                           //
// 'lastflip' is the stack of recently flipped faces. Walks through the list //
// of flips, in the reverse of the order in which they were done, and undoes //
// them.                                                                     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::undoflip(badface *lastflip)
{
  enum fliptype fc;

  while (lastflip != (badface *) NULL) {
    // Get the right flipped face.
    findface(&lastflip->tt, lastflip->forg, lastflip->fdest, lastflip->fapex);
    fc = (enum fliptype) (int) lastflip->key;
    switch (fc) {
    case T23:
      // The reverse operation of T23 is T32.
      flip32(&lastflip->tt, NULL);
      break;
    case T32:
      // The reverse operation of T32 is T23.
      flip23(&lastflip->tt, NULL);
      break;
    case T22:
    case T44:
      // The reverse operation of T22 or T44 is again T22 or T44.
      flip22(&lastflip->tt, NULL);
      break;
    }
    // Go on and process the next transformation.
    lastflip = lastflip->previtem;
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// splittetrahedron()    Insert a point into a tetrahedron, split it into    //
//                       four tetrahedra.                                    //
//                                                                           //
// The tetrahedron is given by 'splittet'.  Let it is abcd.  The inserting   //
// point 'newpoint' v should lie strictly inside abcd.                       //
//                                                                           //
// Splitting a tetrahedron is to shrink abcd to abcv,  and create three new  //
// tetrahedra badv, cbdv, and acdv.                                          //
//                                                                           //
// On completion, 'splittet' returns abcv.  If 'flipqueue' is not NULL, it   //
// contains all possibly non-locally Delaunay faces.                         //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::
splittetrahedron(point newpoint, triface* splittet, queue* flipqueue)
{
  triface oldabd, oldbcd, oldcad;                      // Old configuration.
  triface abdcasing, bcdcasing, cadcasing;
  face abdsh, bcdsh, cadsh;
  triface abcv, badv, cbdv, acdv;                      // New configuration.
  point pa, pb, pc, pd;
  REAL attrib, volume;
  int i;

  abcv = *splittet;
  abcv.ver = 0;
  // Set the changed vertices and new tetrahedron.
  pa = org(abcv);
  pb = dest(abcv);
  pc = apex(abcv);
  pd = oppo(abcv);

  if (b->verbose > 1) {
    printf("  Inserting point %d in tetrahedron (%d, %d, %d, %d).\n",
           pointmark(newpoint), pointmark(pa), pointmark(pb), pointmark(pc),
           pointmark(pd));
  }

  fnext(abcv, oldabd);
  enextfnext(abcv, oldbcd);
  enext2fnext(abcv, oldcad);
  sym(oldabd, abdcasing);
  sym(oldbcd, bcdcasing);
  sym(oldcad, cadcasing);
  maketetrahedron(&badv);
  maketetrahedron(&cbdv);
  maketetrahedron(&acdv);

  // Set 'badv' vertices.
  setorg (badv, pb);
  setdest(badv, pa);
  setapex(badv, pd);
  setoppo(badv, newpoint);
  // Set 'cbdv' vertices.
  setorg (cbdv, pc);
  setdest(cbdv, pb);
  setapex(cbdv, pd);
  setoppo(cbdv, newpoint);
  // Set 'acdv' vertices.
  setorg (acdv, pa);
  setdest(acdv, pc);
  setapex(acdv, pd);
  setoppo(acdv, newpoint);
  // Set 'abcv' vertices
  setoppo(abcv, newpoint);

  // Set the element attributes of the new tetrahedra.
  for (i = 0; i < in->numberoftetrahedronattributes; i++) {
    attrib = elemattribute(abcv.tet, i);
    setelemattribute(badv.tet, i, attrib);
    setelemattribute(cbdv.tet, i, attrib);
    setelemattribute(acdv.tet, i, attrib);
  }
  // Set the volume constraint of the new tetrahedra.
  if (b->varvolume) {
    volume = volumebound(abcv.tet);
    setvolumebound(badv.tet, volume);
    setvolumebound(cbdv.tet, volume);
    setvolumebound(acdv.tet, volume);
  }

  // Bond the new triangles to the surrounding tetrahedron.
  bond(badv, abdcasing);
  bond(cbdv, bcdcasing);
  bond(acdv, cadcasing);
  // There may exist subfaces need to be bonded to the new tetrahedra.
  if (checksubfaces) {
    tspivot(oldabd, abdsh);
    if (abdsh.sh != dummysh) {
      tsdissolve(oldabd);
      tsbond(badv, abdsh);
    }
    tspivot(oldbcd, bcdsh);
    if (bcdsh.sh != dummysh) {
      tsdissolve(oldbcd);
      tsbond(cbdv, bcdsh);
    }
    tspivot(oldcad, cadsh);
    if (cadsh.sh != dummysh) {
      tsdissolve(oldcad);
      tsbond(acdv, cadsh);
    }
  }
  badv.loc = 3; 
  cbdv.loc = 2;
  bond(badv, cbdv);
  cbdv.loc = 3; 
  acdv.loc = 2;
  bond(cbdv, acdv);
  acdv.loc = 3; 
  badv.loc = 2;
  bond(acdv, badv);
  badv.loc = 1; 
  bond(badv, oldabd);
  cbdv.loc = 1; 
  bond(cbdv, oldbcd);
  acdv.loc = 1; 
  bond(acdv, oldcad);
  
  badv.loc = 0;
  cbdv.loc = 0;
  acdv.loc = 0;
  if (b->verbose > 3) {
    printf("    Updating abcv ");
    printtet(&abcv);
    printf("    Creating badv ");
    printtet(&badv);
    printf("    Creating cbdv ");
    printtet(&cbdv);
    printf("    Creating acdv ");
    printtet(&acdv);
  }

  if (flipqueue != (queue *) NULL) {
    enqueueflipface(abcv, flipqueue);
    enqueueflipface(badv, flipqueue);
    enqueueflipface(cbdv, flipqueue);
    enqueueflipface(acdv, flipqueue);
  }

  // Save a handle for quick point location.
  recenttet = abcv;
  // Set the return handle be abcv.
  *splittet = abcv;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// unsplittetrahedron()    Reverse the operation of inserting a point into a //
//                         tetrahedron, so as to remove the newly inserted   //
//                         point from the mesh.                              //
//                                                                           //
// Assume the origional tetrahedron is abcd, it was split by v into four     //
// tetrahedra abcv, badv, cbdv, and acdv. 'splittet' represents face abc of  //
// abcv (i.e., its opposite is v).                                           //
//                                                                           //
// Point v is removed by expanding abcv to abcd, deleting three tetrahedra   //
// badv, cbdv and acdv.  On return, point v is not deleted in this routine.  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::unsplittetrahedron(triface* splittet)
{
  triface abcv, badv, cbdv, acdv;
  triface oldabv, oldbcv, oldcav;
  triface badcasing, cbdcasing, acdcasing;
  face badsh, cbdsh, acdsh;

  abcv = *splittet;
  adjustedgering(abcv, CCW);  // for sure.
  fnext(abcv, oldabv);
  fnext(oldabv, badv);
  esymself(badv);
  enextfnext(abcv, oldbcv);
  fnext(oldbcv, cbdv);
  esymself(cbdv);
  enext2fnext(abcv, oldcav);
  fnext(oldcav, acdv);
  esymself(acdv);

  if (b->verbose > 1) {
    printf("  Removing point %d in tetrahedron (%d, %d, %d, %d).\n",
           pointmark(oppo(abcv)), pointmark(org(abcv)), pointmark(dest(abcv)),
           pointmark(apex(abcv)), pointmark(apex(badv)));
  }

  sym(badv, badcasing);
  tspivot(badv, badsh);
  sym(cbdv, cbdcasing);
  tspivot(cbdv, cbdsh);
  sym(acdv, acdcasing);
  tspivot(acdv, acdsh);

  // Expanding abcv to abcd.
  setoppo(abcv, apex(badv));
  bond(oldabv, badcasing);
  if (badsh.sh != dummysh) {
    tsbond(oldabv, badsh);
  }
  bond(oldbcv, cbdcasing);
  if (cbdsh.sh != dummysh) {
    tsbond(oldbcv, cbdsh);
  }
  bond(oldcav, acdcasing);
  if (acdsh.sh != dummysh) {
    tsbond(oldcav, acdsh);
  }

  // Delete the three split-out tetrahedra.
  tetrahedrondealloc(badv.tet);
  tetrahedrondealloc(cbdv.tet);
  tetrahedrondealloc(acdv.tet);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// splittetface()    Insert a point on a face of a mesh.                     //
//                                                                           //
// 'splittet' is the splitting face.  Let it is abcd, where abc is the face  //
// will be split. If abc is not a hull face, abce is the tetrahedron at the  //
// opposite of d.                                                            //
//                                                                           //
// To split face abc by a point v is to shrink the tetrahedra abcd to abvd,  //
// create two new tetrahedra bcvd, cavd.  If abc is not a hull face, shrink  //
// the tetrahedra bace to bave, create two new tetrahedra cbve, acve.        //
//                                                                           //
// If abc is a subface, it is split into three subfaces simultaneously by    //
// calling routine splitsubface(), hence, abv, bcv, cav.  The edge rings of  //
// the split subfaces have the same orientation as abc's.                    //
//                                                                           //
// On completion, 'splittet' returns abvd.  If 'flipqueue' is not NULL, it   //
// contains all possibly non-locally Delaunay faces.                         //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::
splittetface(point newpoint, triface* splittet, queue* flipqueue)
{
  triface abcd, bace;                                  // Old configuration.
  triface oldbcd, oldcad, oldace, oldcbe; 
  triface bcdcasing, cadcasing, acecasing, cbecasing;
  face abcsh, bcdsh, cadsh, acesh, cbesh;
  triface abvd, bcvd, cavd, bave, cbve, acve;          // New configuration.
  point pa, pb, pc, pd, pe;
  REAL attrib, volume;
  bool mirrorflag;
  int i;

  abcd = *splittet;
  // abcd.ver = 0; // Adjust to be CCW edge ring.
  adjustedgering(abcd, CCW);
  pa = org(abcd);
  pb = dest(abcd);
  pc = apex(abcd);
  pd = oppo(abcd);
  // Is there a second tetrahderon?
  mirrorflag = issymexist(&abcd);
  if (mirrorflag) {
    // This is an interior face.
    sym(abcd, bace);
    findedge(&bace, dest(abcd), org(abcd));
    pe = oppo(bace);
  }
  if (checksubfaces) {
    // Is there a subface need to be split together?
    tspivot(abcd, abcsh);
    if (abcsh.sh != dummysh) {
      // Exists! Keep the edge ab of both handles be the same.
      findedge(&abcsh, org(abcd), dest(abcd));
    }
  }

  if (b->verbose > 1) {
    printf("  Inserting point %d on face (%d, %d, %d).\n", pointmark(newpoint),
           pointmark(pa), pointmark(pb), pointmark(pc));
  }

#ifdef SELF_CHECK
    // Make sure no inversed tetrahedron has been created.
    assert(orient3d(pa, pb, pd, newpoint) >= 0.0);
    assert(orient3d(pb, pc, pd, newpoint) >= 0.0);
    assert(orient3d(pc, pa, pd, newpoint) >= 0.0);
#endif

  // Save the old configuration at faces bcd and cad.
  enextfnext(abcd, oldbcd);
  enext2fnext(abcd, oldcad);
  sym(oldbcd, bcdcasing);
  sym(oldcad, cadcasing);
  // Create two new tetrahedra.
  maketetrahedron(&bcvd);
  maketetrahedron(&cavd);
  if (mirrorflag) {
    // Save the old configuration at faces bce and cae.
    enextfnext(bace, oldace);
    enext2fnext(bace, oldcbe);
    sym(oldace, acecasing);
    sym(oldcbe, cbecasing);
    // Create two new tetrahedra.
    maketetrahedron(&acve);
    maketetrahedron(&cbve);
  } else {
    // Splitting a boundary face increases the number of boundary faces.
    hullsize += 2;
  }

  // Set vertices to the changed tetrahedron and new tetrahedra.
  abvd = abcd;  // Update 'abcd' to 'abvd'.
  setapex(abvd, newpoint);
  setorg (bcvd, pb);  // Set 'bcvd'.
  setdest(bcvd, pc);
  setapex(bcvd, newpoint);
  setoppo(bcvd, pd);
  setorg (cavd, pc);  // Set 'cavd'.
  setdest(cavd, pa);
  setapex(cavd, newpoint);
  setoppo(cavd, pd);
  // Set the element attributes of the new tetrahedra.
  for (i = 0; i < in->numberoftetrahedronattributes; i++) {
    attrib = elemattribute(abvd.tet, i);
    setelemattribute(bcvd.tet, i, attrib);
    setelemattribute(cavd.tet, i, attrib);
  }
  if (b->varvolume) {
    // Set the area constraint of the new tetrahedra.
    volume = volumebound(abvd.tet);
    setvolumebound(bcvd.tet, volume);
    setvolumebound(cavd.tet, volume);
  }
  if (mirrorflag) {
    bave = bace;  // Update 'bace' to 'bave'.
    setapex(bave, newpoint);
    setorg (acve, pa);  // Set 'acve'.
    setdest(acve, pc);
    setapex(acve, newpoint);
    setoppo(acve, pe);
    setorg (cbve, pc);  // Set 'cbve'.
    setdest(cbve, pb);
    setapex(cbve, newpoint);
    setoppo(cbve, pe);
    // Set the element attributes of the new tetrahedra.
    for (i = 0; i < in->numberoftetrahedronattributes; i++) {
      attrib = elemattribute(bave.tet, i);
      setelemattribute(acve.tet, i, attrib);
      setelemattribute(cbve.tet, i, attrib);
    }
    if (b->varvolume) {
      // Set the area constraint of the new tetrahedra.
      volume = volumebound(bave.tet);
      setvolumebound(acve.tet, volume);
      setvolumebound(cbve.tet, volume);
    }
  }

  // Bond the new tetrahedra to the surrounding tetrahedra.
  bcvd.loc = 1;
  bond(bcvd, bcdcasing); 
  cavd.loc = 1;
  bond(cavd, cadcasing); 
  bcvd.loc = 3;
  bond(bcvd, oldbcd);
  cavd.loc = 2;
  bond(cavd, oldcad);
  bcvd.loc = 2;
  cavd.loc = 3;
  bond(bcvd, cavd);  
  if (mirrorflag) {
    acve.loc = 1;
    bond(acve, acecasing);
    cbve.loc = 1;
    bond(cbve, cbecasing);
    acve.loc = 3;
    bond(acve, oldace);
    cbve.loc = 2;
    bond(cbve, oldcbe);
    acve.loc = 2;
    cbve.loc = 3;
    bond(acve, cbve);
    // Bond two new coplanar facets.
    bcvd.loc = 0;
    cbve.loc = 0;
    bond(bcvd, cbve);
    cavd.loc = 0;
    acve.loc = 0;
    bond(cavd, acve);
  }

  // There may exist subface needed to be bonded to the new tetrahedra.
  if (checksubfaces) {
    tspivot(oldbcd, bcdsh);
    if (bcdsh.sh != dummysh) {
      tsdissolve(oldbcd);
      bcvd.loc = 1;
      tsbond(bcvd, bcdsh);
    }
    tspivot(oldcad, cadsh);
    if (cadsh.sh != dummysh) {
      tsdissolve(oldcad);
      cavd.loc = 1;
      tsbond(cavd, cadsh);
    }
    if (mirrorflag) {
      tspivot(oldace, acesh);
      if (acesh.sh != dummysh) {
        tsdissolve(oldace);
        acve.loc = 1;
        tsbond(acve, acesh);
      }
      tspivot(oldcbe, cbesh);
      if (cbesh.sh != dummysh) {
        tsdissolve(oldcbe);
        cbve.loc = 1;
        tsbond(cbve, cbesh);
      }
    }
    // Is there a subface needs to be split together?
    if (abcsh.sh != dummysh) {
      // Split this subface 'abc' into three i.e, abv, bcv, cav.
      splitsubface(newpoint, &abcsh, (queue *) NULL);
    }  
  }

  // Save a handle for quick point location.
  recenttet = abvd;
  // Set the return handle be abvd.
  *splittet = abvd;

  bcvd.loc = 0;
  cavd.loc = 0;
  if (mirrorflag) {
    cbve.loc = 0;
    acve.loc = 0;
  }
  if (b->verbose > 3) {
    printf("    Updating abvd ");
    printtet(&abvd);
    printf("    Creating bcvd ");
    printtet(&bcvd);
    printf("    Creating cavd ");
    printtet(&cavd);
    if (mirrorflag) {
      printf("    Updating bave ");
      printtet(&bave);
      printf("    Creating cbve ");
      printtet(&cbve);
      printf("    Creating acve ");
      printtet(&acve);
    }
  }

  if (flipqueue != (queue *) NULL) {
    fnextself(abvd);
    enqueueflipface(abvd, flipqueue);
    fnextself(bcvd);
    enqueueflipface(bcvd, flipqueue);
    fnextself(cavd);
    enqueueflipface(cavd, flipqueue);
    if (mirrorflag) {
      fnextself(bave);
      enqueueflipface(bave, flipqueue);
      fnextself(cbve);
      enqueueflipface(cbve, flipqueue);
      fnextself(acve);
      enqueueflipface(acve, flipqueue);
    }
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// unsplittetface()    Reverse the operation of inserting a point on a face, //
//                     so as to remove the newly inserted point.             //
//                                                                           //
// Assume the original face is abc, the tetrahedron containing abc is abcd.  //
// If abc is not a hull face, bace is the tetrahedron at the opposite of d.  //
// After face abc was split by a point v, tetrahedron abcd had been split    //
// into three tetrahedra, abvd, bcvd, cavd, and bace (if it exists) had been //
// split into bave, cbve, acve. 'splittet' represents abvd (its apex is v).  //
//                                                                           //
// Point v is removed by expanding abvd to abcd, deleting two tetrahedra     //
// bcvd, cavd. Expanding bave(if it exists) to bace, deleting two tetrahedra //
// cbve, acve.  If abv is a subface, routine unsplitsubface() will be called //
// to reverse the operation of splitting a subface. On completion, point v   //
// is not deleted in this routine.                                           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::unsplittetface(triface* splittet)
{
  triface abvd, bcvd, cavd, bave, cbve, acve;
  triface oldbvd, oldvad, oldvbe, oldave;
  triface bcdcasing, cadcasing, cbecasing, acecasing;
  face bcdsh, cadsh, cbesh, acesh;
  face abvsh;
  bool mirrorflag;

  abvd = *splittet;
  adjustedgering(abvd, CCW); // for sure.
  enextfnext(abvd, oldbvd);
  fnext(oldbvd, bcvd);
  esymself(bcvd);
  enextself(bcvd);
  enext2fnext(abvd, oldvad);
  fnext(oldvad, cavd);
  esymself(cavd);
  enext2self(cavd);
  // Is there a second tetrahedron?
  sym(abvd, bave);
  mirrorflag = bave.tet != dummytet;
  if (mirrorflag) {
    findedge(&bave, dest(abvd), org(abvd));
    enextfnext(bave, oldave);  
    fnext(oldave, acve);
    esymself(acve);
    enextself(acve);
    enext2fnext(bave, oldvbe);  
    fnext(oldvbe, cbve);
    esymself(cbve);
    enext2self(cbve);
  } else {
    // Unsplit a hull face decrease the number of boundary faces.
    hullsize -= 2;
  }
  // Is there a subface at abv.
  tspivot(abvd, abvsh);
  if (abvsh.sh != dummysh) {
    // Exists! Keep the edge ab of both handles be the same.
    findedge(&abvsh, org(abvd), dest(abvd));
  }

  if (b->verbose > 1) {
    printf("  Removing point %d on face (%d, %d, %d).\n",
           pointmark(apex(abvd)), pointmark(org(abvd)), pointmark(dest(abvd)),
           pointmark(dest(bcvd)));
  }

  fnextself(bcvd); // bcvd has changed to bcdv.
  sym(bcvd, bcdcasing);
  tspivot(bcvd, bcdsh);
  fnextself(cavd); // cavd has changed to cadv.
  sym(cavd, cadcasing);
  tspivot(cavd, cadsh);
  if (mirrorflag) {
    fnextself(acve); // acve has changed to acev.
    sym(acve, acecasing);
    tspivot(acve, acesh);
    fnextself(cbve); // cbve has changed to cbev.
    sym(cbve, cbecasing);
    tspivot(cbve, cbesh);
  }

  // Expand abvd to abcd.
  setapex(abvd, dest(bcvd));
  bond(oldbvd, bcdcasing);
  if (bcdsh.sh != dummysh) {
    tsbond(oldbvd, bcdsh);
  }
  bond(oldvad, cadcasing);
  if (cadsh.sh != dummysh) {
    tsbond(oldvad, cadsh);
  }
  if (mirrorflag) {
    // Expanding bave to bace.
    setapex(bave, dest(acve));
    bond(oldave, acecasing);
    if (acesh.sh != dummysh) {
      tsbond(oldave, acesh);
    }
    bond(oldvbe, cbecasing);
    if (cbesh.sh != dummysh) {
      tsbond(oldvbe, cbesh);
    }
  }

  // Unsplit a subface if there exists.
  if (abvsh.sh != dummysh) {
    unsplitsubface(&abvsh);
  }

  // Delete the split-out tetrahedra.
  tetrahedrondealloc(bcvd.tet);
  tetrahedrondealloc(cavd.tet);
  if (mirrorflag) {
    tetrahedrondealloc(acve.tet);
    tetrahedrondealloc(cbve.tet);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// splitsubface()    Insert a point on a subface, split it into three.       //
//                                                                           //
// The subface is 'splitface'.  Let it is abc. The inserting point 'newpoint'//
// v should lie inside abc.  If the neighbor tetrahedra of abc exist, i.e.,  //
// abcd and bace, they should have been split by routine splittetface()      //
// before calling this routine, so the connection between the new tetrahedra //
// and new subfaces can be correctly set.                                    //
//                                                                           //
// To split subface abc by point v is to shrink abc to abv, create two new   //
// subfaces bcv and cav.  Set the connection between updated and new created //
// subfaces. If there is a subsegment at edge bc or ca, connection of new    //
// subface (bcv or cav) to its casing subfaces is a face link, 'casingin' is //
// the predecessor and 'casingout' is the successor. It is important to keep //
// the orientations of the edge rings of the updated and created subfaces be //
// the same as abc's. So they have the same orientation as other subfaces of //
// this facet with respect to the lift point of this facet.                  //
//                                                                           //
// On completion, 'splitface' returns abv.  If 'flipqueue' is not NULL, it   //
// returns all possibly non-Delaunay edges.                                  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::
splitsubface(point newpoint, face* splitface, queue* flipqueue)
{
  triface abvd, bcvd, cavd, bave, cbve, acve;
  face abc, oldbc, oldca, bc, ca, spinsh;
  face bccasin, bccasout, cacasin, cacasout;
  face abv, bcv, cav;
  point pa, pb, pc;
  
  abc = *splitface;
  // The newly created subfaces will have the same edge ring as abc.
  adjustedgering(abc, CCW);
  pa = sorg(abc);
  pb = sdest(abc);
  pc = sapex(abc);

  if (b->verbose > 1) {
    printf("  Inserting point %d on subface (%d, %d, %d).\n",
           pointmark(newpoint), pointmark(pa), pointmark(pb), pointmark(pc));
  }

  // Save the old configuration at edge bc and ca.  Subsegments may appear
  //   at both sides, save the face links and dissolve them.
  senext(abc, oldbc);
  senext2(abc, oldca);
  spivot(oldbc, bccasout);
  sspivot(oldbc, bc);
  if (bc.sh != dummysh) {
    if (oldbc.sh != bccasout.sh) {
      // 'oldbc' is not self-bonded.
      spinsh = bccasout;
      do {
        bccasin = spinsh;
        spivotself(spinsh);
      } while (spinsh.sh != oldbc.sh);
    } else {
      bccasout.sh = dummysh;
    }
    ssdissolve(oldbc);
  } 
  spivot(oldca, cacasout);
  sspivot(oldca, ca);
  if (ca.sh != dummysh) {
    if (oldca.sh != cacasout.sh) {
      // 'oldca' is not self-bonded.
      spinsh = cacasout;
      do {
        cacasin = spinsh;
        spivotself(spinsh);
      } while (spinsh.sh != oldca.sh);
    } else {
      cacasout.sh = dummysh;
    }
    ssdissolve(oldca);
  }
  // Create two new subfaces.
  makeshellface(subfaces, &bcv);
  makeshellface(subfaces, &cav);

  // Set the vertices of changed and new subfaces.
  abv = abc;  // Update 'abc' to 'abv'.
  setsapex(abv, newpoint);
  setsorg(bcv, pb);  // Set 'bcv'.
  setsdest(bcv, pc);
  setsapex(bcv, newpoint);
  setsorg(cav, pc);  // Set 'cav'.
  setsdest(cav, pa);
  setsapex(cav, newpoint);
  if (b->quality && varconstraint) {
    // Copy yhr area bound into the new subfaces.
    setareabound(bcv, areabound(abv));
    setareabound(cav, areabound(abv));
  }
  // Copy the boundary mark into the new subfaces.
  setshellmark(bcv, shellmark(abv));
  setshellmark(cav, shellmark(abv));  
  // Copy the subface type into the new subfaces.
  setshelltype(bcv, shelltype(abv));
  setshelltype(cav, shelltype(abv));
  if (checkpbcs) {
    // Copy the pbcgroup into the new subfaces.
    setshellpbcgroup(bcv, shellpbcgroup(abv));
    setshellpbcgroup(cav, shellpbcgroup(abv));
  }
  // Bond the new subfaces to the surrounding subfaces.
  if (bc.sh != dummysh) {
    if (bccasout.sh != dummysh) {
      sbond1(bccasin, bcv);
      sbond1(bcv, bccasout);
    } else {
      // Bond 'bcv' to itsself.
      sbond(bcv, bcv);
    }
    ssbond(bcv, bc);
  } else {
    sbond(bcv, bccasout);
  }
  if (ca.sh != dummysh) {
    if (cacasout.sh != dummysh) {
      sbond1(cacasin, cav);
      sbond1(cav, cacasout);
    } else {
      // Bond 'cav' to itself.
      sbond(cav, cav);
    }
    ssbond(cav, ca);
  } else {
    sbond(cav, cacasout);
  }
  senext2self(bcv);
  sbond(bcv, oldbc);
  senextself(cav);
  sbond(cav, oldca);
  senext2self(bcv);
  senextself(cav);
  sbond(bcv, cav);

  // Bond the new subfaces to the new tetrahedra if they exist.
  stpivot(abv, abvd);
  if (abvd.tet != dummytet) {
    // Get two new tetrahedra and their syms.
    findedge(&abvd, sorg(abv), sdest(abv));
    enextfnext(abvd, bcvd);
    assert(bcvd.tet != dummytet);
    fnextself(bcvd);
    enext2fnext(abvd, cavd);
    assert(cavd.tet != dummytet);
    fnextself(cavd);
    // Bond two new subfaces to the two new tetrahedra.
    tsbond(bcvd, bcv);
    tsbond(cavd, cav);
  }
  // Set the connection at the other sides if the tetrahedra exist.
  sesymself(abv);  // bav
  stpivot(abv, bave);
  if (bave.tet != dummytet) {
    sesymself(bcv);  // cbv
    sesymself(cav);  // acv
    // Get two new tetrahedra and their syms.
    findedge(&bave, sorg(abv), sdest(abv));
    enextfnext(bave, acve);
    assert(acve.tet != dummytet);
    fnextself(acve);
    enext2fnext(bave, cbve);
    assert(cbve.tet != dummytet);
    fnextself(cbve);
    // Bond two new subfaces to the two new tetrahedra.
    tsbond(acve, cav);
    tsbond(cbve, bcv);
  }

  bcv.shver = 0;
  cav.shver = 0;
  if (b->verbose > 3) {
    printf("    Updating abv ");
    printsh(&abv);
    printf("    Creating bcv ");
    printsh(&bcv);
    printf("    Creating cav ");
    printsh(&cav);
  }

  if (flipqueue != (queue *) NULL) {
    enqueueflipedge(abv, flipqueue);
    enqueueflipedge(bcv, flipqueue);
    enqueueflipedge(cav, flipqueue);
  }

  // Set the return handle be abv.
  *splitface = abv;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// unsplitsubface()    Reverse the operation of inserting a point on a       //
//                     subface, so as to remove the newly inserted point.    //
//                                                                           //
// Assume the original subface is abc, it was split by a point v into three  //
// subfaces abv, bcv and cav.  'splitsh' represents abv.                     //
//                                                                           //
// To remove point v is to expand abv to abc, delete bcv and cav. If edge bc //
// or ca is a subsegment,  the connection at a subsegment is a subface link, //
// '-casin' and '-casout' are used to save the predecessor and successor of  //
// bcv or cav.  On completion, point v is not deleted in this routine.       //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::unsplitsubface(face* splitsh)
{
  face abv, bcv, cav;
  face oldbv, oldva, bc, ca, spinsh;
  face bccasin, bccasout, cacasin, cacasout;

  abv = *splitsh;
  senext(abv, oldbv);
  spivot(oldbv, bcv);
  if (sorg(bcv) != sdest(oldbv)) {
    sesymself(bcv);
  }
  senextself(bcv);
  senext2(abv, oldva);
  spivot(oldva, cav);
  if (sorg(cav) != sdest(oldva)) {
    sesymself(cav);
  }
  senext2self(cav);

  if (b->verbose > 1) {
    printf("  Removing point %d on subface (%d, %d, %d).\n",
           pointmark(sapex(abv)), pointmark(sorg(abv)), pointmark(sdest(abv)),
           pointmark(sdest(bcv)));
  }

  spivot(bcv, bccasout);
  sspivot(bcv, bc);
  if (bc.sh != dummysh) {
    if (bcv.sh != bccasout.sh) {
      // 'bcv' is not self-bonded.
      spinsh = bccasout;
      do {
        bccasin = spinsh;
        spivotself(spinsh);
      } while (spinsh.sh != bcv.sh);
    } else {
      bccasout.sh = dummysh;
    }
  }
  spivot(cav, cacasout);
  sspivot(cav, ca);
  if (ca.sh != dummysh) {
    if (cav.sh != cacasout.sh) {
      // 'cav' is not self-bonded.
      spinsh = cacasout;
      do {
       cacasin = spinsh;
       spivotself(spinsh);
      } while (spinsh.sh != cav.sh);
    } else {
      cacasout.sh = dummysh;
    }
  }

  // Expand abv to abc.
  setsapex(abv, sdest(bcv));
  if (bc.sh != dummysh) {
    if (bccasout.sh != dummysh) {
      sbond1(bccasin, oldbv);
      sbond1(oldbv, bccasout);
    } else {
      // Bond 'oldbv' to itself.
      sbond(oldbv, oldbv);
    }
    ssbond(oldbv, bc);
  } else {
    sbond(oldbv, bccasout);
  } 
  if (ca.sh != dummysh) {
    if (cacasout.sh != dummysh) {
      sbond1(cacasin, oldva);
      sbond1(oldva, cacasout);
    } else {
      // Bond 'oldva' to itself.
      sbond(oldva, oldva);
    }
    ssbond(oldva, ca);
  } else {
    sbond(oldva, cacasout);
  }

  // Delete two split-out subfaces.
  shellfacedealloc(subfaces, bcv.sh);
  shellfacedealloc(subfaces, cav.sh);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// splittetedge()    Insert a point on an edge of the mesh.                  //
//                                                                           //
// The edge is given by 'splittet'. Assume its four corners are a, b, n1 and //
// n2, where ab is the edge will be split. Around ab may exist any number of //
// tetrahedra. For convenience, they're ordered in a sequence following the  //
// right-hand rule with your thumb points from a to b. Let the vertex set of //
// these tetrahedra be {a, b, n1, n2, ..., n(i)}. NOTE the tetrahedra around //
// ab may not connect to each other (can only happen when ab is a subsegment,//
// hence some faces abn(i) are subfaces).  If ab is a subsegment, abn1 must  //
// be a subface.                                                             //
//                                                                           //
// To split edge ab by a point v is to split all tetrahedra containing ab by //
// v.  More specifically, for each such tetrahedron, an1n2b, it is shrunk to //
// an1n2v, and a new tetrahedra bn2n1v is created. If ab is a subsegment, or //
// some faces of the splitting tetrahedra are subfaces, they must be split   //
// either by calling routine 'splitsubedge()'.                               //
//                                                                           //
// On completion, 'splittet' returns avn1n2.  If 'flipqueue' is not NULL, it //
// returns all faces which may become non-Delaunay after this operation.     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::
splittetedge(point newpoint, triface* splittet, queue* flipqueue)
{
  triface *bots, *newtops;
  triface oldtop, topcasing;
  triface spintet, tmpbond0, tmpbond1;
  face abseg, splitsh, topsh, spinsh;
  point pa, pb, n1, n2;
  REAL attrib, volume;
  int wrapcount, hitbdry;
  int i, j;

  if (checksubfaces) {
    // Is there a subsegment need to be split together?
    tsspivot(splittet, &abseg);
    if (abseg.sh != dummysh) {
      abseg.shver = 0;
      // Orient the edge direction of 'splittet' be abseg.
      if (org(*splittet) != sorg(abseg)) {
        esymself(*splittet);
      }
    }
  } 
  spintet = *splittet;
  pa = org(spintet);
  pb = dest(spintet);

  if (b->verbose > 1) {
    printf("  Inserting point %d on edge (%d, %d).\n", 
           pointmark(newpoint), pointmark(pa), pointmark(pb));
  }

  // Collect the tetrahedra containing the splitting edge (ab).
  n1 = apex(spintet);
  hitbdry = 0;
  wrapcount = 1;
  if (checksubfaces && abseg.sh != dummysh) {
    // It may happen that some tetrahedra containing ab (a subsegment) are
    //   completely disconnected with others. If it happens, use the face
    //   link of ab to cross the boundary. 
    while (true) {
      if (!fnextself(spintet)) {
        // Meet a boundary, walk through it.
        hitbdry ++;
        tspivot(spintet, spinsh);
        assert(spinsh.sh != dummysh);
        findedge(&spinsh, pa, pb);
        sfnextself(spinsh);
        stpivot(spinsh, spintet);
        assert(spintet.tet != dummytet);
        findedge(&spintet, pa, pb);
        // Remember this position (hull face) in 'splittet'.
        *splittet = spintet;
        // Split two hull faces increase the hull size;
        hullsize += 2;
      }
      if (apex(spintet) == n1) break;
      wrapcount ++;
    }
    if (hitbdry > 0) {
      wrapcount -= hitbdry;
    }
  } else {
    // All the tetrahedra containing ab are connected together. If there
    //   are subfaces, 'splitsh' keeps one of them.
    splitsh.sh = dummysh;
    while (hitbdry < 2) {
      if (checksubfaces && splitsh.sh == dummysh) {
        tspivot(spintet, splitsh);
      }
      if (fnextself(spintet)) {
        if (apex(spintet) == n1) break;
        wrapcount++;
      } else {
        hitbdry ++;
        if (hitbdry < 2) {
          esym(*splittet, spintet);
        }
      }
    }
    if (hitbdry > 0) {
      // ab is on the hull.
      wrapcount -= 1;
      // 'spintet' now is a hull face, inverse its edge direction.
      esym(spintet, *splittet);
      // Split two hull faces increases the number of hull faces.
      hullsize += 2;
    }
  }
  
  // Make arrays of updating (bot, oldtop) and new (newtop) tetrahedra.
  bots = new triface[wrapcount];
  newtops = new triface[wrapcount];
  // Spin around ab, gather tetrahedra and set up new tetrahedra. 
  spintet = *splittet;
  for (i = 0; i < wrapcount; i++) {
    // Get 'bots[i] = an1n2b'.
    enext2fnext(spintet, bots[i]);
    esymself(bots[i]);
    // Create 'newtops[i]'.
    maketetrahedron(&(newtops[i]));
    // Go to the next.
    fnextself(spintet);
    if (checksubfaces && abseg.sh != dummysh) {
      if (!issymexist(&spintet)) {
        // We meet a hull face, walk through it.
        tspivot(spintet, spinsh);
        assert(spinsh.sh != dummysh);
        findedge(&spinsh, pa, pb);
        sfnextself(spinsh);
        stpivot(spinsh, spintet);
        assert(spintet.tet != dummytet);
        findedge(&spintet, pa, pb);
      }
    }
  }
  
  // Set the vertices of updated and new tetrahedra.
  for (i = 0; i < wrapcount; i++) {
    // Update 'bots[i] = an1n2v'.
    setoppo(bots[i], newpoint);
    // Set 'newtops[i] = bn2n1v'.
    n1 = dest(bots[i]);
    n2 = apex(bots[i]);
    // Set 'newtops[i]'.
    setorg(newtops[i], pb);
    setdest(newtops[i], n2);
    setapex(newtops[i], n1);
    setoppo(newtops[i], newpoint);
    // Set the element attributes of a new tetrahedron.
    for (j = 0; j < in->numberoftetrahedronattributes; j++) {
      attrib = elemattribute(bots[i].tet, j);
      setelemattribute(newtops[i].tet, j, attrib);
    }
    if (b->varvolume) {
      // Set the area constraint of a new tetrahedron.
      volume = volumebound(bots[i].tet);
      setvolumebound(newtops[i].tet, volume);
    }
#ifdef SELF_CHECK
    // Make sure no inversed tetrahedron has been created.
    assert(orient3d(pa, n1, n2, newpoint) <= 0.0);
    assert(orient3d(pb, n2, n1, newpoint) <= 0.0);
#endif
  }

  // Bond newtops to topcasings and bots.
  for (i = 0; i < wrapcount; i++) {
    // Get 'oldtop = n1n2va' from 'bots[i]'.
    enextfnext(bots[i], oldtop);
    sym(oldtop, topcasing);
    bond(newtops[i], topcasing);
    if (checksubfaces) {
      tspivot(oldtop, topsh);
      if (topsh.sh != dummysh) {
        tsdissolve(oldtop);
        tsbond(newtops[i], topsh);
      }
    }
    enextfnext(newtops[i], tmpbond0);
    bond(oldtop, tmpbond0);
  }
  // Bond between newtops.
  fnext(newtops[0], tmpbond0);
  enext2fnext(bots[0], spintet); 
  for (i = 1; i < wrapcount; i ++) {
    if (issymexist(&spintet)) {
      enext2fnext(newtops[i], tmpbond1);
      bond(tmpbond0, tmpbond1);
    }
    fnext(newtops[i], tmpbond0);
    enext2fnext(bots[i], spintet); 
  }
  // Bond the last to the first if no boundary.
  if (issymexist(&spintet)) {
    enext2fnext(newtops[0], tmpbond1);
    bond(tmpbond0, tmpbond1);
  }

  // Is there exist subfaces and subsegment need to be split?
  if (checksubfaces) {
    if (abseg.sh != dummysh) {
      // A subsegment needs be split.
      spivot(abseg, splitsh);
      assert(splitsh.sh != dummysh);
    }
    if (splitsh.sh != dummysh) {
      // Split subfaces (and subsegment).
      findedge(&splitsh, pa, pb);
      splitsubedge(newpoint, &splitsh, (queue *) NULL);
    }
  }

  if (b->verbose > 3) {
    for (i = 0; i < wrapcount; i++) {
      printf("    Updating bots[%i] ", i);
      printtet(&(bots[i]));
      printf("    Creating newtops[%i] ", i);
      printtet(&(newtops[i]));
    }
  }

  if (flipqueue != (queue *) NULL) {
    for (i = 0; i < wrapcount; i++) {
      enqueueflipface(bots[i], flipqueue);
      enqueueflipface(newtops[i], flipqueue);
    }
  }

  // Set the return handle be avn1n2.  It is got by transforming from
  //   'bots[0]' (which is an1n2v).
  fnext(bots[0], spintet); // spintet is an1vn2.
  esymself(spintet); // spintet is n1avn2.
  enextself(spintet); // spintet is avn1n2.
  *splittet = spintet;

  delete [] bots;
  delete [] newtops;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// unsplittetedge()    Reverse the operation of splitting an edge, so as to  //
//                     remove the newly inserted point.                      //
//                                                                           //
// Assume the original edge is ab, the tetrahedron containing ab is abn1n2.  //
// After ab was split by a point v, every tetrahedron containing ab (e.g.,   //
// abn1n2) has been split into two (e.g., an1n2v and bn2n1v). 'splittet'     //
// represents avn1n2 (i.e., its destination is v).                           //
//                                                                           //
// To remove point v is to expand each split tetrahedron containing ab (e.g.,//
// (avn1n2 to abn1n2), then delete the redundant one(e.g., vbn1n2). If there //
// exists any subface around ab, routine unsplitsubedge() will be called to  //
// reverse the operation of splitting a edge (or a subsegment) of subfaces.  //
// On completion, point v is not deleted in this routine.                    //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::unsplittetedge(triface* splittet)
{
  triface *bots, *newtops;
  triface oldtop, topcasing;
  triface spintet;
  face avseg, splitsh, topsh, spinsh;
  point pa, pv, n1;
  int wrapcount, hitbdry;
  int i;

  spintet = *splittet;
  pa = org(spintet);
  pv = dest(spintet);
  if (checksubfaces) {
    // Is there a subsegment need to be unsplit together?
    tsspivot(splittet, &avseg);
    if (avseg.sh != dummysh) {
      // The subsegment's direction should conform to 'splittet'.
      if (sorg(avseg) != pa) {
        sesymself(avseg);
      }
    }
  } 

  n1 = apex(spintet);
  hitbdry = 0;
  wrapcount = 1;
  if (checksubfaces && avseg.sh != dummysh) {
    // It may happen that some tetrahedra containing ab (a subsegment) are
    //   completely disconnected with others. If it happens, use the face
    //   link of ab to cross the boundary. 
    while (true) {    
      if (!fnextself(spintet)) {
        // Meet a boundary, walk through it.
        hitbdry ++;
        tspivot(spintet, spinsh);
        assert(spinsh.sh != dummysh);
        findedge(&spinsh, pa, pv);
        sfnextself(spinsh);
        stpivot(spinsh, spintet);
        assert(spintet.tet != dummytet);
        findedge(&spintet, pa, pv);
        // Remember this position (hull face) in 'splittet'.
        *splittet = spintet;
        // Split two hull faces increase the hull size;
        hullsize += 2;
      }
      if (apex(spintet) == n1) break;
      wrapcount ++;
    }
    if (hitbdry > 0) {
      wrapcount -= hitbdry;
    }
  } else {
    // All the tetrahedra containing ab are connected together. If there
    //   are subfaces, 'splitsh' keeps one of them.
    splitsh.sh = dummysh;
    while (hitbdry < 2) {
      if (checksubfaces && splitsh.sh == dummysh) {
        tspivot(spintet, splitsh);
      }
      if (fnextself(spintet)) {
        if (apex(spintet) == n1) break;
        wrapcount++;
      } else {
        hitbdry ++;
        if (hitbdry < 2) {
          esym(*splittet, spintet);
        }
      }
    }
    if (hitbdry > 0) {
      // ab is on the hull.
      wrapcount -= 1;
      // 'spintet' now is a hull face, inverse its edge direction.
      esym(spintet, *splittet);
      // Split two hull faces increases the number of hull faces.
      hullsize += 2;
    }
  }
  
  // Make arrays of updating (bot, oldtop) and new (newtop) tetrahedra.
  bots = new triface[wrapcount];
  newtops = new triface[wrapcount];
  // Spin around av, gather tetrahedra and set up new tetrahedra. 
  spintet = *splittet;
  for (i = 0; i < wrapcount; i++) {
    // Get 'bots[i] = an1n2v'.
    enext2fnext(spintet, bots[i]);
    esymself(bots[i]);
    // Get 'oldtop = n1n2va'.
    enextfnext(bots[i], oldtop);
    // Get 'newtops[i] = 'bn1n2v'
    fnext(oldtop, newtops[i]); // newtop = n1n2bv
    esymself(newtops[i]); // newtop = n2n1bv
    enext2self(newtops[i]); // newtop = bn2n1v
    // Go to the next.
    fnextself(spintet);
    if (checksubfaces && avseg.sh != dummysh) {
      if (!issymexist(&spintet)) {
        // We meet a hull face, walk through it.
        tspivot(spintet, spinsh);
        assert(spinsh.sh != dummysh);
        findedge(&spinsh, pa, pv);
        sfnextself(spinsh);
        stpivot(spinsh, spintet);
        assert(spintet.tet != dummytet);
        findedge(&spintet, pa, pv);
      }
    }
  }

  if (b->verbose > 1) {
    printf("  Removing point %d from edge (%d, %d).\n", 
           pointmark(oppo(bots[0])), pointmark(org(bots[0])),
           pointmark(org(newtops[0])));
  }

  for (i = 0; i < wrapcount; i++) {
    // Expand an1n2v to an1n2b.
    setoppo(bots[i], org(newtops[i]));
    // Get 'oldtop = n1n2va' from 'bot[i]'.
    enextfnext(bots[i], oldtop);
    // Get 'topcasing' from 'newtop[i]'
    sym(newtops[i], topcasing);
    // Bond them.
    bond(oldtop, topcasing);
    if (checksubfaces) {
      tspivot(newtops[i], topsh);
      if (topsh.sh != dummysh) {
        tsbond(oldtop, topsh);
      }
    }
    // Delete the tetrahedron above an1n2v.
    tetrahedrondealloc(newtops[i].tet);
  }

  // If there exists any subface, unsplit them.
  if (checksubfaces) {
    if (avseg.sh != dummysh) {
      spivot(avseg, splitsh);
      assert(splitsh.sh != dummysh);
    }
    if (splitsh.sh != dummysh) {
      findedge(&splitsh, pa, pv);
      unsplitsubedge(&splitsh);
    }
  }

  delete [] bots;
  delete [] newtops;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// splitsubedge()    Insert a point on an edge of the surface mesh.          //
//                                                                           //
// The splitting edge is given by 'splitsh'. Assume its three corners are a, //
// b, c, where ab is the edge will be split. ab may be a subsegment.         //
//                                                                           //
// To split edge ab is to split all subfaces conatining ab. If ab is not a   //
// subsegment, there are only two subfaces need be split, otherwise, there   //
// may have any number of subfaces need be split. Each splitting subface abc //
// is shrunk to avc, a new subface vbc is created.  It is important to keep  //
// the orientations of edge rings of avc and vbc be the same as abc's. If ab //
// is a subsegment, it is shrunk to av and a new subsegment vb is created.   //
//                                                                           //
// If there are tetrahedra adjoining to the splitting subfaces, they should  //
// be split before calling this routine, so the connection between the new   //
// tetrahedra and the new subfaces can be correctly set.                     //
//                                                                           //
// On completion, 'splitsh' returns avc.  If 'flipqueue' is not NULL, it     //
// returns all edges which may be non-Delaunay.                              //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::splitsubedge(point newpoint, face* splitsh, queue* flipqueue)
{
  triface abcd, bace, vbcd, bvce;
  face startabc, spinabc, spinsh;
  face oldbc, bccasin, bccasout;
  face ab, bc;
  face avc, vbc, vbc1;
  face av, vb;
  point pa, pb;

  startabc = *splitsh;
  // Is there a subsegment?
  sspivot(startabc, ab);
  if (ab.sh != dummysh) {
    ab.shver = 0; 
    if (sorg(startabc) != sorg(ab)) {
      sesymself(startabc);
    }
  }
  pa = sorg(startabc);
  pb = sdest(startabc);
  
  if (b->verbose > 1) {
    printf("  Inserting point %d on subedge (%d, %d) %s.\n",
           pointmark(newpoint), pointmark(pa), pointmark(pb),
           (ab.sh != dummysh ? "(seg)" : " "));
  }
  
  // Spin arround ab, split every subface containing ab.
  spinabc = startabc;
  do {
    // Adjust spinabc be edge ab.
    if (sorg(spinabc) != pa) {
      sesymself(spinabc);
    }
    // Save old configuration at edge bc, if bc has a subsegment, save the
    //   face link of it and dissolve it from bc.
    senext(spinabc, oldbc);
    spivot(oldbc, bccasout);    
    sspivot(oldbc, bc);
    if (bc.sh != dummysh) {
      if (spinabc.sh != bccasout.sh) {
        // 'spinabc' is not self-bonded.
        spinsh = bccasout;
        do {
          bccasin = spinsh;
          spivotself(spinsh);
        } while (spinsh.sh != oldbc.sh);
      } else {
        bccasout.sh = dummysh;
      }
      ssdissolve(oldbc);
    }
    // Create a new subface.
    makeshellface(subfaces, &vbc);
    // Split abc.
    avc = spinabc;  // Update 'abc' to 'avc'.
    setsdest(avc, newpoint);
    // Make 'vbc' be in the same edge ring as 'avc'. 
    vbc.shver = avc.shver; 
    setsorg(vbc, newpoint); // Set 'vbc'.
    setsdest(vbc, pb);
    setsapex(vbc, sapex(avc));
    if (b->quality && varconstraint) {
      // Copy the area bound into the new subface.
      setareabound(vbc, areabound(avc));
    }
    // Copy the shell marker and shell type into the new subface.
    setshellmark(vbc, shellmark(avc));
    setshelltype(vbc, shelltype(avc));
    if (checkpbcs) {
      // Copy the pbcgroup into the new subface.
      setshellpbcgroup(vbc, shellpbcgroup(avc));
    }
    // Set the connection between updated and new subfaces.
    senext2self(vbc);
    sbond(vbc, oldbc);
    // Set the connection between new subface and casings.
    senext2self(vbc);
    if (bc.sh != dummysh) {
      if (bccasout.sh != dummysh) {
        // Insert 'vbc' into face link.
        sbond1(bccasin, vbc);
        sbond1(vbc, bccasout);
      } else {
        // Bond 'vbc' to itself.
        sbond(vbc, vbc);
      }
      ssbond(vbc, bc);
    } else {
      sbond(vbc, bccasout);
    }
    // Go to next subface at edge ab.
    spivotself(spinabc);
    if (spinabc.sh == dummysh) {
      break; // 'ab' is a hull edge.
    }
  } while (spinabc.sh != startabc.sh);

  // Get the new subface vbc above the updated subface avc (= startabc).
  senext(startabc, oldbc);
  spivot(oldbc, vbc);
  if (sorg(vbc) == newpoint) {
    sesymself(vbc);
  }
  assert(sorg(vbc) == sdest(oldbc) && sdest(vbc) == sorg(oldbc));
  senextself(vbc);
  // Set the face link for the new created subfaces around edge vb.
  spinabc = startabc;
  do {
    // Go to the next subface at edge av.
    spivotself(spinabc);
    if (spinabc.sh == dummysh) {
      break; // 'ab' is a hull edge.
    }
    if (sorg(spinabc) != pa) {
      sesymself(spinabc);
    }
    // Get the new subface vbc1 above the updated subface avc (= spinabc).
    senext(spinabc, oldbc);
    spivot(oldbc, vbc1);
    if (sorg(vbc1) == newpoint) {
      sesymself(vbc1);
    }
    assert(sorg(vbc1) == sdest(oldbc) && sdest(vbc1) == sorg(oldbc));
    senextself(vbc1);
    // Set the connection: vbc->vbc1.
    sbond1(vbc, vbc1);
    // For the next connection.
    vbc = vbc1;
  } while (spinabc.sh != startabc.sh);

  // Split ab if it is a subsegment.
  if (ab.sh != dummysh) {
    // Update subsegment ab to av.
    av = ab;
    setsdest(av, newpoint);
    // Create a new subsegment vb.
    makeshellface(subsegs, &vb);
    setsorg(vb, newpoint);
    setsdest(vb, pb);
    // vb gets the same mark and segment type as av.
    setshellmark(vb, shellmark(av));
    setshelltype(vb, shelltype(av));
    if (b->quality && varconstraint) {
      // Copy the area bound into the new subsegment.
      setareabound(vb, areabound(av));
    }
    // Save the old connection at ab (re-use the handles oldbc, bccasout).
    senext(av, oldbc);
    spivot(oldbc, bccasout);
    // Bond av and vb (bonded at their "fake" edges).
    senext2(vb, bccasin);
    sbond(bccasin, oldbc);
    if (bccasout.sh != dummysh) {
      // There is a subsegment connecting with ab at b. It will connect
      //   to vb at b after splitting.
      bccasout.shver = 0;
      assert(sorg(bccasout) == pb); 
      senext2self(bccasout);
      senext(vb, bccasin);
      sbond(bccasin, bccasout);
    }
    // Bond all new subfaces (vbc) to vb. 
    spinabc = startabc;
    do {
      // Adjust spinabc be edge av.
      if (sorg(spinabc) != pa) {
        sesymself(spinabc);
      }
      // Get new subface vbc above the updated subface avc (= spinabc).
      senext(spinabc, oldbc);
      spivot(oldbc, vbc);
      if (sorg(vbc) == newpoint) {
        sesymself(vbc);
      }
      senextself(vbc);
      // Bond the new subface and the new subsegment.
      ssbond(vbc, vb);
      // Go to the next.
      spivotself(spinabc);
      assert(spinabc.sh != dummysh);
    } while (spinabc.sh != startabc.sh);
  }

  // Bond the new subfaces to new tetrahedra if they exist.  New tetrahedra
  //   should have been created before calling this routine.
  spinabc = startabc;
  do {
    // Adjust spinabc be edge av.
    if (sorg(spinabc) != pa) {
      sesymself(spinabc);
    }
    // Get new subface vbc above the updated subface avc (= spinabc).
    senext(spinabc, oldbc);
    spivot(oldbc, vbc);
    if (sorg(vbc) == newpoint) {
      sesymself(vbc);
    }
    senextself(vbc);
    // Get the adjacent tetrahedra at 'spinabc'.
    stpivot(spinabc, abcd);
    if (abcd.tet != dummytet) {
      findedge(&abcd, sorg(spinabc), sdest(spinabc));
      enextfnext(abcd, vbcd);
      fnextself(vbcd);
      assert(vbcd.tet != dummytet);
      tsbond(vbcd, vbc);
      sym(vbcd, bvce);
      sesymself(vbc);
      tsbond(bvce, vbc);
    } else {
      // One side is empty, check the other side.
      sesymself(spinabc);
      stpivot(spinabc, bace);
      if (bace.tet != dummytet) {
        findedge(&bace, sorg(spinabc), sdest(spinabc));
        enext2fnext(bace, bvce);
        fnextself(bvce);
        assert(bvce.tet != dummytet);
        sesymself(vbc); 
        tsbond(bvce, vbc);
      }
    }
    // Go to the next.
    spivotself(spinabc);
    if (spinabc.sh == dummysh) {
      break; // 'ab' is a hull edge.
    }
  } while (spinabc.sh != startabc.sh);
  
  if (b->verbose > 3) {
    spinabc = startabc;
    do {
      // Adjust spinabc be edge av.
      if (sorg(spinabc) != pa) {
        sesymself(spinabc);
      }
      printf("    Updating abc:\n");
      printsh(&spinabc);
      // Get new subface vbc above the updated subface avc (= spinabc).
      senext(spinabc, oldbc);
      spivot(oldbc, vbc);
      if (sorg(vbc) == newpoint) {
        sesymself(vbc);
      }
      senextself(vbc);
      printf("    Creating vbc:\n");
      printsh(&vbc);
      // Go to the next.
      spivotself(spinabc);
      if (spinabc.sh == dummysh) {
        break; // 'ab' is a hull edge.
      }
    } while (spinabc.sh != startabc.sh);
  }

  if (flipqueue != (queue *) NULL) {
    spinabc = startabc;
    do {
      // Adjust spinabc be edge av.
      if (sorg(spinabc) != pa) {
        sesymself(spinabc);
      }
      senext2(spinabc, oldbc); // Re-use oldbc.
      enqueueflipedge(oldbc, flipqueue);
      // Get new subface vbc above the updated subface avc (= spinabc).
      senext(spinabc, oldbc);
      spivot(oldbc, vbc);
      if (sorg(vbc) == newpoint) {
        sesymself(vbc);
      }
      senextself(vbc);
      senext(vbc, oldbc); // Re-use oldbc.
      enqueueflipedge(oldbc, flipqueue);
      // Go to the next.
      spivotself(spinabc);
      if (spinabc.sh == dummysh) {
        break; // 'ab' is a hull edge.
      }
    } while (spinabc.sh != startabc.sh);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// unsplitsubedge()    Reverse the operation of splitting an edge of subface,//
//                     so as to remove a point from the edge.                //
//                                                                           //
// Assume the original edge is ab, the subface containing it is abc. It was  //
// split by a point v into avc, and vbc.  'splitsh' represents avc, further- //
// more, if av is a subsegment, av should be the zero version of the split   //
// subsegment (i.e., av.shver = 0), so we are sure that the destination (v)  //
// of both avc and av is the deleting point.                                 //
//                                                                           //
// To remove point v is to expand avc to abc, delete vbc, do the same for    //
// other subfaces containing av and vb. If av and vb are subsegments, expand //
// av to ab, delete vb.  On completion, point v is not deleted.              //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::unsplitsubedge(face* splitsh)
{
  face startavc, spinavc, spinbcv;
  face oldvc, bccasin, bccasout, spinsh;
  face av, vb, bc;
  point pa, pv, pb;

  startavc = *splitsh;
  sspivot(startavc, av);
  if (av.sh != dummysh) {
    // Orient the direction of subsegment to conform the subface. 
    if (sorg(av) != sorg(startavc)) {
      sesymself(av);
    }
    assert(av.shver == 0);
  }
  senext(startavc, oldvc);
  spivot(oldvc, vb);  // vb is subface vbc
  if (sorg(vb) != sdest(oldvc)) {
    sesymself(vb);
  }
  senextself(vb);
  pa = sorg(startavc);
  pv = sdest(startavc);
  pb = sdest(vb);

  if (b->verbose > 1) {
    printf("  Removing point %d from subedge (%d, %d).\n",
           pointmark(pv), pointmark(pa), pointmark(pb));
  }

  // Spin arround av, unsplit every subface containing av.
  spinavc = startavc;
  do {
    // Adjust spinavc be edge av.
    if (sorg(spinavc) != pa) {
      sesymself(spinavc);
    }
    // Save old configuration at edge bc, if bc has a subsegment, save the
    //   face link of it.
    senext(spinavc, oldvc);
    spivot(oldvc, spinbcv);
    if (sorg(spinbcv) != sdest(oldvc)) {
      sesymself(spinbcv);
    }
    senext2self(spinbcv);
    spivot(spinbcv, bccasout);
    sspivot(spinbcv, bc);
    if (bc.sh != dummysh) {
      if (spinbcv.sh != bccasout.sh) {
        // 'spinbcv' is not self-bonded.
        spinsh = bccasout;
        do {
          bccasin = spinsh;
          spivotself(spinsh);
        } while (spinsh.sh != spinbcv.sh);
      } else {
        bccasout.sh = dummysh;
      }
    }
    // Expand avc to abc.
    setsdest(spinavc, pb);
    if (bc.sh != dummysh) {
      if (bccasout.sh != dummysh) {
        sbond1(bccasin, oldvc);
        sbond1(oldvc, bccasout);
      } else {
        // Bond 'oldbc' to itself.
        sbond(oldvc, oldvc);
      }
      ssbond(oldvc, bc);
    } else {
      sbond(oldvc, bccasout);
    }
    // Delete bcv.
    shellfacedealloc(subfaces, spinbcv.sh);
    // Go to next subface at edge av.
    spivotself(spinavc);
    if (spinavc.sh == dummysh) {
      break; // 'av' is a hull edge.
    }
  } while (spinavc.sh != startavc.sh);

  // Is there a subsegment need to be unsplit?
  if (av.sh != dummysh) {
    senext(av, oldvc);  // Re-use oldvc.
    spivot(oldvc, vb);
    vb.shver = 0;
    assert(sdest(av) == sorg(vb));
    senext(vb, spinbcv); // Re-use spinbcv.
    spivot(spinbcv, bccasout);
    // Expand av to ab.
    setsdest(av, pb);
    sbond(oldvc, bccasout);
    // Delete vb.
    shellfacedealloc(subsegs, vb.sh);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// insertsite()    Insert a point into the mesh.                             //
//                                                                           //
// The 'newpoint' is located.  If 'searchtet->tet' is not NULL, the search   //
// for the containing tetrahedron begins from 'searchtet', otherwise, a full //
// point location procedure is called.  If 'newpoint' is found inside a      //
// tetrahedron, the tetrahedron is split into four (by splittetrahedron());  //
// if 'newpoint' lies on a face, the face is split into three, thereby       //
// splitting the two adjacent tetrahedra into six (by splittetface()); if    //
// 'newpoint' lies on an edge, the edge is split into two, thereby, every    //
// tetrahedron containing this edge is split into two. If 'newpoint' lies on //
// an existing vertex, no action is taken, and the value DUPLICATEPOINT  is  //
// returned and 'searchtet' is set to a handle whose origin is the vertex.   //
//                                                                           //
// If 'flipqueue' is not NULL, after 'newpoint' is inserted, it returns all  //
// faces which may become non-Delaunay due to the newly inserted point. Flip //
// operations can be performed as necessary on them to maintain the Delaunay //
// property.                                                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

enum tetgenmesh::insertsiteresult tetgenmesh::
insertsite(point newpoint, triface* searchtet, bool approx, queue* flipqueue)
{
  enum locateresult intersect, exactloc;
  point checkpt;
  REAL epspp, checklen;
  int count;

  if (b->verbose > 1) {
    printf("  Insert point to mesh: (%.12g, %.12g, %.12g) %d.\n",
           newpoint[0], newpoint[1], newpoint[2], pointmark(newpoint));
  }

  if (searchtet->tet == (tetrahedron *) NULL) {
    // Search for a tetrahedron containing 'newpoint'.
    searchtet->tet = dummytet;
    exactloc = locate(newpoint, searchtet);
  } else {
    // Start searching from the tetrahedron provided by the caller. 
    exactloc = preciselocate(newpoint, searchtet);
  }
  intersect = exactloc;
  if (approx && (exactloc != ONVERTEX)) {
    // Adjust the exact location to an approx. location wrt. epsilon.
    epspp = b->epsilon;
    count = 0;
    while (count < 16) {
      intersect = adjustlocate(newpoint, searchtet, exactloc, epspp);
      if (intersect == ONVERTEX) {
        checkpt = org(*searchtet);
        checklen = distance(checkpt, newpoint);
        if (checklen / longest > b->epsilon) {
          epspp *= 1e-2;
          count++;
          continue;
        }
      }
      break;
    }
  }
  // Keep current search state for next searching.
  recenttet = *searchtet; 

  // Insert the point using the right routine
  switch (intersect) {
  case ONVERTEX:
    // There's already a vertex there. Return in 'searchtet' a tetrahedron
    //   whose origin is the existing vertex.
    if (b->verbose > 1) {
      printf("  Not insert for duplicating point.\n");
    }
    return DUPLICATEPOINT;

  case OUTSIDE:
    if (b->verbose > 1) {
      printf("  Not insert for locating outside the mesh.\n");
    }
    return OUTSIDEPOINT;

  case ONEDGE:
    // 'newpoint' falls on an edge.
    splittetedge(newpoint, searchtet, flipqueue);
    return SUCCESSONEDGE;

  case ONFACE:
    // 'newpoint' falls on a face.
    splittetface(newpoint, searchtet, flipqueue);
    return SUCCESSONFACE;

  case INTETRAHEDRON:
    // 'newpoint' falls inside a tetrahedron.
    splittetrahedron(newpoint, searchtet, flipqueue);
    return SUCCESSINTET;
  }

  // Impossible case.
  assert(0);
  return OUTSIDEPOINT;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// undosite()    Undo the most recently point insertion.                     //
//                                                                           //
// 'insresult' indicates in where the newpoint has been inserted, i.e., in a //
// tetrahedron, on a face, or on an edge.  A correspoding routine will be    //
// called to undo the point insertion.  'splittet' is a handle represent one //
// of the resulting tetrahedra, but it may be changed after transformation,  //
// even may be dead.  Four points 'torg', ... 'toppo' are the corners which  //
// 'splittet' should have. On finish, 'newpoint' is not removed.             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::
undosite(enum insertsiteresult insresult, triface* splittet, point torg,
         point tdest, point tapex, point toppo)
{
  // Set the four corners of 'splittet' exactly be 'torg', ... 'toppo'.
  findface(splittet, torg, tdest, tapex);
  if (oppo(*splittet) != toppo) {
    symself(*splittet);
    assert(oppo(*splittet) == toppo);
    // The sym() operation may inverse the edge, correct it if so.
    findedge(splittet, torg, tdest);
  }
  
  // Unsplit the tetrahedron according to 'insresult'.  
  switch (insresult) {
  case SUCCESSINTET:
    // 'splittet' should be the face with 'newpoint' as its opposite.
    unsplittetrahedron(splittet);
    break;
  case SUCCESSONFACE:
    // 'splittet' should be the one of three splitted face with 'newpoint'
    //   as its apex.
    unsplittetface(splittet);
    break;
  case SUCCESSONEDGE:
    // 'splittet' should be the tet with destination is 'newpoint'.
    unsplittetedge(splittet);
    break;
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// inserthullsite()    Insert a point which is outside the convex hull.      //
//                                                                           //
// The inserting point 'inspoint' lies outside the tetrahedralization.'horiz'//
// is one of the convex hull faces which are visible from it. (You can image //
// that is is parallel to the horizon). To insert a point outside the convex //
// hull we have to enlarge current convex hull of the tetrahedralization for //
// including this point.  This routine collects convex hull faces which are  //
// visible from the inserting point, constructs new tetrahedra from these    //
// faces and the inserting point. On return, 'inspoint' has become a vertex  //
// of the augmented tetrahedralization.  The convex hull has been updated.   //
// 'flipcheckqueue' returns the old convex hull faces which may become non-  //
// Delaunay and need be flipped.                                             //
//                                                                           //
// The caller can optionally provide two variables. 'hulllink' is a link for //
// saving newly created hull faces (containing 'inspoint') which may not     //
// convex. Non-convex hull faces will be detected and finished by mounting   //
// new tetrahedra with other hull vertex near them.  'worklist' is an array, //
// used for face matching.                                                   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::
inserthullsite(point inspoint, triface* horiz, queue* flipqueue,
               link* hulllink, int* worklist)
{
  link *myhulllink;
  triface newtet, hullface;
  triface oldhull, newhull;
  point workpt[3];
  bool finished;
  int *myworklist;
  int idx, share;
  int i, j, k;

  if (b->verbose > 1) {
    printf("  Collect visible convex hull faces.\n");
  }

  // Check if the 'hulllink' is provided by the caller.
  if (hulllink != (link *) NULL) {
    myhulllink = (link *) NULL;
  } else {
    myhulllink = new link(sizeof(triface), NULL, 256);
    hulllink = myhulllink;
  }

  // Check if the 'worklist' is provided by the caller.
  if (worklist != (int *) NULL) {
    myworklist = (int *) NULL;
  } else {
    myworklist = new int[points->items];
    for (i = 0; i < points->items; i++) myworklist[i] = 0;
    worklist = myworklist;
  }

  adjustedgering(*horiz, CW);
  // Create a new tetrahedron from 'horiz' and 'inspoint'.
  maketetrahedron(&newtet);
  setorg (newtet, org(*horiz));
  setdest(newtet, dest(*horiz));
  setapex(newtet, apex(*horiz));
  setoppo(newtet, inspoint);
  // Make the connection of two tets.
  bond(newtet, *horiz);
  // 'horiz' becomes interior face.
  enqueueflipface(*horiz, flipqueue);
  // Add the three sides of 'newtet' to 'hulllink'.
  fnext(newtet, hullface);
  hulllink->add(&hullface);
  enextfnext(newtet, hullface);
  hulllink->add(&hullface);
  enext2fnext(newtet, hullface);
  hulllink->add(&hullface);
  if (b->verbose > 3) {
    printf("    Creating newtet ");
    printtet(&newtet);
  }
  // Hull face number decreased caused by face bond() operation.
  hullsize--;

  // Loop untill 'hulllink' is empty.  Find other visible convex hull faces,
  //   create tetrahedra from them and 'inspoint'. Update 'hulllink'.
  while (hulllink->len() > 0) {
    // Remove the top hull face from the link, its apex is 'inspoint'.
    hullface = * (triface *) hulllink->del(1);
    // Get the neighbor convex hull face at the edge of 'hullface'.  This is
    //   done by rotating faces around the edge from the inside until reach
    //   outer space (The rotation of faces should always terminate).
    esym(hullface, oldhull);
    while (fnextself(oldhull)) ;
    // Is 'inspoint' visible from 'oldhull'?
    if (orient3d(org(oldhull), dest(oldhull), apex(oldhull), inspoint) < 0.0) {
      // 'oldhull' is visible from 'inspoint'. Create a new tetrahedron
      //   from them.
      maketetrahedron(&newtet);
      setorg(newtet, org(oldhull));
      setdest(newtet, dest(oldhull));
      setapex(newtet, apex(oldhull));
      setoppo(newtet, inspoint);
      // Bond 'newtet' to 'oldhull'.
      bond(newtet, oldhull);
      // Hull face number decrease caused by bond().
      hullsize--;
      // Bond 'newtet' to 'hullface'.
      fnext(newtet, newhull);
      bond(newhull, hullface);
      // 'oldhull' becomes interior face.
      enqueueflipface(oldhull, flipqueue);
      // Check other two sides of 'newtet'.  If one exists in 'hulllink'.
      //   remove the one in 'hulllink' (it is finished), otherwise, it
      //   becomes a new hull face, add it into 'hulllink'.
      for (i = 0; i < 2; i++) {
        // Get 'newhull' and set flags for its vertices.
        if (i == 0) {
          enextfnext(newtet, newhull);
        } else {
          enext2fnext(newtet, newhull);
        }
        workpt[0] = org(newhull);
        workpt[1] = dest(newhull);
        workpt[2] = apex(newhull);
        for (k = 0; k < 3; k++) {
          idx = pointmark(workpt[k]) - in->firstnumber;
          worklist[idx] = 1;
        }
        // Search 'newhull' in 'hulllink'.
        finished = false;        
        for (j = 0; j < hulllink->len() && !finished; j++) {
          hullface = * (triface *) hulllink->getnitem(j + 1);
          workpt[0] = org(hullface);
          workpt[1] = dest(hullface);
          workpt[2] = apex(hullface);
          share = 0;
          for (k = 0; k < 3; k++) {
            idx = pointmark(workpt[k]) - in->firstnumber;
            if (worklist[idx] == 1) {
              share++;
            }
          }
          if (share == 3) {
            // Two faces are identical. Bond them togther.
            bond(newhull, hullface);
            // Remove 'hullface' from the link.
            hulllink->del(j + 1);
            finished = true;
          }
        }
        if (!finished) {
          // 'newhull' becomes a hull face, add it into 'hulllink'.
          hulllink->add(&newhull); 
        }
        // Clear used flags.
        workpt[0] = org(newhull);
        workpt[1] = dest(newhull);
        workpt[2] = apex(newhull);
        for (k = 0; k < 3; k++) {
          idx = pointmark(workpt[k]) - in->firstnumber;
          worklist[idx] = 0;
        }
      }
    } else {
      // 'hullface' becomes a convex hull face. 
      hullsize++;
      // Let 'dummytet[0]' points to it for next point location.
      dummytet[0] = encode(hullface);
    }
  }

  if (myhulllink != (link *) NULL) {
    delete myhulllink;
  }
  if (myworklist != (int *) NULL) {
    delete [] myworklist;
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// collectcavtets()    Collect all tets whose circumsphere contain newpoint. //
//                                                                           //
// 'cavtetlist' returns the list of tetrahedra. On input, it contains one    //
// tetrahedron which contains 'newpoint'.                                    //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::collectcavtets(point newpoint, list* cavtetlist)
{
  triface starttet, neightet;
  REAL sign;
  int i;

  // Now starttet contains newpoint.
  starttet = * (triface *)(* cavtetlist)[0];
  infect(starttet);

  // Find the other tetrahedra by looping in list.
  for (i = 0; i < cavtetlist->len(); i++) {
    starttet = * (triface *)(* cavtetlist)[i];
    // Check the four neighbors of starttet.
    for (starttet.loc = 0; starttet.loc < 4; starttet.loc++) {
      sym(starttet, neightet);
      if ((neightet.tet != dummytet) && !infected(neightet)) {
        // For positive orientation that insphere() test requires.
        adjustedgering(neightet, CW);
        sign = insphere(org(neightet), dest(neightet), apex(neightet),
                        oppo(neightet), newpoint);
        if (sign >= 0.0) {
          // Add neightet into list.
          infect(neightet);
          cavtetlist->append(&neightet);
        }
      }
    }
  }

  // Having find all tetrahedra, uninfect them before return.
  for (i = 0; i < cavtetlist->len(); i++) {
    starttet = * (triface *)(* cavtetlist)[i];
    assert(infected(starttet));
    uninfect(starttet);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// collectcavsubs()    Collect subfaces whose circumsphere contain newpoint. //
//                                                                           //
// 'cavsublist' returns the list of subfaces. It is not empty on input, it   //
// contains at least one such subface.                                       //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::collectcavsubs(point newpoint, list* cavsublist)
{
  face startsub, neighsub;
  face checkseg;
  point pa, pb, pc, liftpt;
  REAL sign, ori;
  int i, j;

  // First infect subfaces in 'cavsublist'.
  for (i = 0; i < cavsublist->len(); i++) {
    startsub = * (face *)(* cavsublist)[i];
    if (i == 0) {
      liftpt = getliftpoint(shellmark(startsub));
    }
    sinfect(startsub);
  }

  // Find the other subfaces by looping in list.
  for (i = 0; i < cavsublist->len(); i++) {
    startsub = * (face *)(* cavsublist)[i];
    for (j = 0; j < 3; j++) {
      sspivot(startsub, checkseg);
      if (checkseg.sh == dummysh) {
        spivot(startsub, neighsub);
        if (!sinfected(neighsub)) {
          pa = sorg(neighsub);
          pb = sdest(neighsub);
          pc = sapex(neighsub);
          sign = insphere(pa, pb, pc, liftpt, newpoint);
          ori = orient3d(pa, pb, pc, liftpt);
          if (sign != 0.0) {
            // Correct the sign. 
            assert(ori != 0.0);
            sign = ori > 0.0 ? sign : -sign;
          }
          if (sign > 0.0) {
            // neighsub is encroached by newpoint.
            sinfect(neighsub);
            cavsublist->append(&neighsub);
          }
        }
      }
      senextself(startsub);
    }
  }

  // Having find all subfaces, uninfect them before return.
  for (i = 0; i < cavsublist->len(); i++) {
    startsub = * (face *)(* cavsublist)[i];
    suninfect(startsub);
  }
}

//
// End of mesh transformation routines
//

//
// Begin of incremental flip Delaunay triangulation routines
//

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// incrflipinit()    Create an initial tetrahedralization.                   //
//                                                                           //
// The initial tetrahedralization only contains one tetrahedron formed from  //
// four affinely linear independent vertices from the input point set.       //
//                                                                           //
// 'insertqueue' returns the rest of vertices of the input point set.  These //
// vertices will be inserted one by one in the later step.                   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::incrflipinit(queue* insertqueue)
{
  triface newtet;
  point *plist, pointloop;
  point pa, pb, pc, pd;
  REAL det;
  int count;
  int i, j;

  if (b->verbose > 1) {
    printf("  Constructing an initial tetrahedron.\n");
  }

  // Create a point list and initialize it.
  plist = new point[in->numberofpoints];
  i = 0;
  points->traversalinit();
  pointloop = pointtraverse();
  while (pointloop != (point) NULL) {
    plist[i++] = pointloop;
    pointloop = pointtraverse();
  }
  assert(i == in->numberofpoints);

  if (b->dopermute) {
    // Do permutation.  Initialize the random seed.
    randomseed = b->srandseed;
    for (i = 0; i < in->numberofpoints; i++) {
      // Get a index j (from 0 to in->numberofpoints - i - 1).
      j = (int) randomnation(in->numberofpoints - i);
      // Exchange the i-th point and (j + i)-th point.
      pointloop = plist[j + i];
      plist[j + i] = plist[i];
      plist[i] = pointloop;
    }
  }

  // Set the plist into insertqueue.
  if (!insertqueue->empty()) {
    insertqueue->clear(); 
  }
  for (i = 0; i < in->numberofpoints; i++) {
    pointloop = plist[i];
    insertqueue->push(&pointloop);
  }
  delete [] plist;

  // Get the first two point 'pa'.
  pa = * (point *) insertqueue->pop();

  // Get the second point 'pb', which is not identical with 'pa'.
  count = 0;
  pb = * (point *) insertqueue->pop();
  while ((pb != (point) NULL) && (count < in->numberofpoints)) {
    if ((pb[0] == pa[0]) && (pb[1] == pa[1]) && (pb[2] == pa[2])) {
      // 'pb' is identical to 'pa', skip it.
      insertqueue->push(&pb);
    } else {
      break;
    }
    pb = * (point *) insertqueue->pop();
    count++;
  }
  if (pb == (point) NULL) {
    printf("\nAll points are identical, no triangulation be constructed.\n");
    exit(1);
  }

  // Get the third point 'pc', which is not collinear with 'pa' and 'pb'.
  count = 0;
  pc = * (point *) insertqueue->pop();
  while ((pc != (point) NULL) && (count < in->numberofpoints)) {
    if (iscollinear(pa, pb, pc, (b->epsilon * 1e-2))) {
      // They are collinear or identical, put it back to queue.
      insertqueue->push(&pc);
    } else {
      break;
    }
    pc = * (point *) insertqueue->pop();
    count++;
  }
  if (pc == (point) NULL) {
    printf("\nAll points are collinear, no triangulation be constructed.\n");
    exit(1);
  }

  // Get the fourth point which is not coplanar with pa, pb, and pc.
  count = 0;
  pd = * (point *) insertqueue->pop();
  while ((pd != (point) NULL) && (count < in->numberofpoints)) {
    det = orient3d(pa, pb, pc, pd);
    if (det == 0.0) {
      // They are coplanar or identical, put it back to queue.
      insertqueue->push(&pd);
    } else {
      break;
    }
    pd = * (point *) insertqueue->pop();
    count++;
  }
  if (pd == (point) NULL) {
    printf("\nAll points are coplanar, no triangulation be constructed.\n");
    exit(1);
  }
  if (det > 0.0) {
    pointloop = pa; pa = pb; pb = pointloop;
  }

  // Create the tetrahedron with corners pa, pb, pc and pd.
  maketetrahedron(&newtet);
  setorg(newtet, pa);
  setdest(newtet, pb);
  setapex(newtet, pc);
  setoppo(newtet, pd);
  // Set the vertices be FREEVOLVERTEX to indicate they belong to the mesh.
  setpointtype(pa, FREEVOLVERTEX);
  setpointtype(pb, FREEVOLVERTEX);
  setpointtype(pc, FREEVOLVERTEX);
  setpointtype(pd, FREEVOLVERTEX);
  // Bond to 'dummytet' for point location.
  dummytet[0] = encode(newtet);
  if (b->verbose > 3) {
    printf("    Creating tetra ");
    printtet(&newtet);
  }
  // At init, all faces of this tet are hull faces.
  hullsize = 4;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// mergepoints()    Merge two very close points to be one point.             //
//                                                                           //
// This function is used for dealing with inputs from CAD tools. It uses the //
// (relative) epsilon to determine whether two points are merged or not. The //
// default epsilon is (b->epsilon * 1e+2 = 1e-6). You can set the value thr- //
// ough the -T switch, e.g. -T1e-5.                                          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::
mergepoints(point testpt, triface* starttet, link* hulllink, int* worklist)
{
  triface hullface, neihull, checkhull;
  point workpt[4], checkpt;
  enum locateresult loc;
  REAL ori, dist, epspp;
  bool merged;
  int share;
  int i, j, k;

  // First locate the point in DT.
  loc = locate(testpt, starttet);
  if (loc == ONVERTEX) return; // They are merged.
  
  // Now testpt is either outside or insde.
  merged = false;
  if (loc == OUTSIDE) {
    // Outside, collect hullfaces which are visible by testpt.
    hulllink->add(starttet);
    for (i = 0; i < hulllink->len(); i++) {
      hullface = * (triface *) hulllink->getnitem(i + 1);
      // Check if hullface has a point close to testpt.
      workpt[0] = org(hullface);
      workpt[1] = dest(hullface);
      workpt[2] = apex(hullface);
      workpt[3] = oppo(hullface);
      for (j = 0; j < 4; j++) {
        dist = distance(testpt, workpt[j]);
        epspp = dist / longest;
        if (epspp <= (b->epsilon * 1e+2)) {
          // Merge the point to the existing point.
          for (k = 0; k < 3; k++) testpt[k] = workpt[j][k];
          merged = true;
          break;
        }
      }
      if (merged) break;
      // Check the neighbor visible hullfaces by testpt.
      adjustedgering(hullface, CCW);
      for (j = 0; j < 3; j++) {
        neihull = hullface;
        while (fnextself(neihull)) ;
        workpt[0] = org(neihull);
        workpt[1] = dest(neihull);
        workpt[2] = apex(neihull);
        ori = orient3d(workpt[0], workpt[1], workpt[2], testpt);
        if (ori < 0.0) {
          // Visible. Add neihull to link if it doesn't exist in it.
          for (k = 0; k < 3; k++) worklist[pointmark(workpt[k])] = 1;
          // Do a brute-force search.
          for (k = 0; k < hulllink->len(); k++) {
            if (k == i) continue;
            checkhull = * (triface *) hulllink->getnitem(k + 1);
            checkpt = org(checkhull);
            share = worklist[pointmark(checkpt)];
            checkpt = dest(checkhull);
            share += worklist[pointmark(checkpt)];
            checkpt = apex(checkhull);
            share += worklist[pointmark(checkpt)];
            if (share == 3) break;
          }
          if (k >= hulllink->len()) {
            hulllink->add(&neihull);
          }
          for (k = 0; k < 3; k++) worklist[pointmark(workpt[k])] = 0;
        } else {
          // Check the apex anyway.
          dist = distance(testpt, workpt[2]);
          epspp = dist / longest;
          if (epspp <= (b->epsilon * 1e+2)) {
            // Merge the point to the existing point.
            for (k = 0; k < 3; k++) testpt[k] = workpt[2][k];
            merged = true;
            break;
          }
          // Check the opposite anyway.
          workpt[3] = oppo(neihull);
          dist = distance(testpt, workpt[3]);
          epspp = dist / longest;
          if (epspp <= (b->epsilon * 1e+2)) {
            // Merge the point to the existing point.
            for (k = 0; k < 3; k++) testpt[k] = workpt[3][k];
            merged = true;
            break;
          }
        }
        enextself(hullface);
      }
      if (merged) break;
    }
  } else {
    hullface = *starttet;
    // Check if there is a close point?
    for (j = 0; j < 4 && !merged; j++) {
      checkpt = (point) hullface.tet[4 + j];
      dist = distance(testpt, checkpt);
      epspp = dist / longest;
      if (epspp <= (b->epsilon * 1e+2)) {
        // Merge the point to the existing point.
        for (k = 0; k < 3; k++) testpt[k] = checkpt[k];
        merged = true;
      }
    }
  }
  // Clear hulllink for the next use.
  hulllink->clear();
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// incrflipdelaunay()   Construct a delaunay tetrahedrization from a set of  //
//                      3D points using the incremental flip algorithm.      //
//                                                                           //
// The incremental flip algorithm is described in the paper of Edelsbrunner  //
// and Shah, "Incremental Topological Flipping Works for Regular Triangulat- //
// ions",  Algorithmica 15: 223-241, 1996.  It can be described as follows:  //
//                                                                           //
//   S be a set of points in 3D, Let 4 <= i <= n and assume that the         //
//   Delaunay triangulation of the first i-1 points in S is already          //
//   constructed; call it D(i-1). Add the i-th point p_i (belong to S) to    //
//   the triangulation,and restore Delaunayhood by flipping; this result     //
//   in D(i). Repeat this procedure until i = n.                             //
//                                                                           //
// This strategy always leads to the Ddelaunay triangulation of a point set. //
// The return value is the number of convex hull faces of this point set.    //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

long tetgenmesh::incrflipdelaunay()
{
  triface starttet;
  point pointloop;
  queue *flipqueue;
  queue *insertqueue;
  link *hulllink;
  enum insertsiteresult insres;
  int *worklist, i;

  if (!b->quiet) {
    if (!b->noflip) {
      printf("Constructing Delaunay tetrahedrization.\n");
    } else {
      printf("Constructing tetrahedrization.\n");
    }
  }

  // Initialize subsidary queues, link, list, ...
  flipqueue = new queue(sizeof(badface));
  insertqueue = new queue(sizeof(point*), in->numberofpoints);
  hulllink = new link(sizeof(triface), NULL, 256);
  worklist = new int[in->numberofpoints + 1];
  for (i = 0; i < in->numberofpoints + 1; i++) worklist[i] = 0;
  flip23s = flip32s = flip22s = flip44s = 0;

  // Algorithm starts from here.
  
  // Construct an initial tetrahedralization and fill 'insertqueue'.
  incrflipinit(insertqueue);

  // Loop untill all points are inserted.
  while (!insertqueue->empty()) {
    pointloop = * (point *) insertqueue->pop();
    // It will become a mesh point unless it duplicates an existing point.
    setpointtype(pointloop, FREEVOLVERTEX);
    // Try to insert the point first.
    starttet.tet = (tetrahedron *) NULL;

    // For STL, PLY, and OFF inputs. Merge very close points.
    if (b->detectinter || (b->object == tetgenbehavior::STL) ||
        (b->object == tetgenbehavior::PLY) ||
        (b->object == tetgenbehavior::OFF) ||
        (b->object == tetgenbehavior::MEDIT)) {
      mergepoints(pointloop, &starttet, hulllink, worklist);
    }

    insres = insertsite(pointloop, &starttet, false, flipqueue);
    if (insres == OUTSIDEPOINT) {
      // Point locates outside the convex hull.
      inserthullsite(pointloop, &starttet, flipqueue, hulllink, worklist);
    } else if (insres == DUPLICATEPOINT) {
      if (b->object != tetgenbehavior::STL) {
        if (!b->quiet) {
          printf("Warning:  Point %d is identical with point %d.\n",
                 pointmark(pointloop), pointmark(org(starttet)));
        }
        // Count the number of duplicated points.
        dupverts++;
      }
      // Remember it is a duplicated point.
      setpointtype(pointloop, DUPLICATEDVERTEX);
      if (b->plc || b->refine) {
        // Set a pointer to the point it duplicates.
        setpoint2pt(pointloop, org(starttet));
      }
    }
    if (!b->noflip) {
      // Call flip algorithm to recover Delaunayness.
      flip(flipqueue, NULL, false, false, false); 
    } else {
      // Not perform flip.
      flipqueue->clear();
    }
  }

  if (!b->noflip && b->verbose) {
    printf("  Total flips: %ld, where T23 %ld, T32 %ld, T22 %ld, T44 %ld\n",
           flip23s + flip32s + flip22s + flip44s,
           flip23s, flip32s, flip22s, flip44s);
  }

  delete flipqueue;
  delete insertqueue;
  delete hulllink;
  delete [] worklist;

  return hullsize;
}

//
// End of incremental flip Delaunay triangulation routines
//

//
// Begin of surface triangulation routines
//

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// The lift points                                                           //
//                                                                           //
// A 'lifting point' of a facet is a point which lies exactly non-coplanar   //
// with the plane containing that facet.  With such an additional point, the //
// three-dimensional geometric predicates (orient3d, insphere) can be used   //
// to substitute the lower dimensional predicates (orient2d, incircle). The  //
// advantage is there is no need to project 3D points back into 2D, so the   //
// rounding error can be avoid.                                              //
//                                                                           //
// These points are calculated during the initialization of triangulating    //
// the facets. It is important to orient subfaces of the same facet to have  //
// the same orientation with respect to its lift point. This way guarantees  //
// the test results are consistent. We take the convention that the lift     //
// point of a facet always lies above the CCW edge rings of subfaces of the  //
// same facet. By this convention, given three points a, b, and c in a facet,//
// we say c has the counterclockwise order with ab is corresponding to say   //
// that c is below the plane abp, where p is the lift point.                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// locatesub()    Find a point in the surface mesh.                          //
//                                                                           //
// Searching begins from the input 'searchsh', it should be a handle on the  //
// convex hull of the facet triangulation.                                   //
//                                                                           //
// If 'stopatseg' is nonzero, the search will stop if it tries to walk       //
// through a subsegment, and will return OUTSIDE.                            //
//                                                                           //
// On completion, 'searchsh' is a subface that contains 'searchpt'.          //
//   - Returns ONVERTEX if the point lies on an existing vertex. 'searchsh'  //
//     is a handle whose origin is the existing vertex.                      //
//   - Returns ONEDGE if the point lies on a mesh edge.  'searchsh' is a     //
//     handle whose primary edge is the edge on which the point lies.        //
//   - Returns ONFACE if the point lies strictly within a subface.           //
//     'searchsh' is a handle on which the point lies.                       //
//   - Returns OUTSIDE if the point lies outside the triangulation.          //
//                                                                           //
// WARNING: This routine is designed for convex triangulations, and will not //
// not generally work after the holes and concavities have been carved.      //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

enum tetgenmesh::locateresult tetgenmesh::
locatesub(point searchpt, face* searchsh, int stopatseg)
{
  face backtracksh, spinsh, checkedge;
  point forg, fdest, fapex, liftpoint;
  REAL abovept[3], norm[3], nlen;
  REAL orgori, destori, ori;
  int moveleft, i;

  if (searchsh->sh == dummysh) {
    searchsh->shver = 0;
    spivotself(*searchsh);
    assert(searchsh->sh != dummysh);
  }

  // Set the liftpoint.
  adjustedgering(*searchsh, CCW);
  forg = sorg(*searchsh);
  fdest = sdest(*searchsh);
  fapex = sapex(*searchsh);
  if (liftpointarray != (REAL *) NULL) {
    // The liftpoint already exits. 
    liftpoint = getliftpoint(shellmark(*searchsh));
  } else {
    // Calculate the liftpoint from the normal direction of searchsh.
    facenormal(forg, fdest, fapex, norm, &nlen);
    assert(nlen > 0.0);
    for (i = 0; i < 3; i++) norm[i] /= nlen;
    nlen = distance(forg, fdest);
    for (i = 0; i < 3; i++) abovept[i] = forg[i] + nlen * norm[i];
    liftpoint = abovept;
  }
  // Adjust the liftpoint be above the face.
  orgori = orient3d(forg, fdest, fapex, liftpoint);
  assert(orgori != 0.0);
  if (orgori > 0.0) {
    sesymself(*searchsh);
  }

  // Orient 'searchsh' so that 'searchpt' is below it (i.e., searchpt has
  //   CCW orientation with respect to searchsh in plane).  Such edge
  //   should always exist. Save it as (forg, fdest).
  for (i = 0; i < 3; i++) {
    forg = sorg(*searchsh);
    fdest = sdest(*searchsh);
    if (orient3d(forg, fdest, liftpoint, searchpt) > 0.0) break;
    senextself(*searchsh);
  }
  assert(i < 3);
  
  while (1) {
    fapex = sapex(*searchsh);
    // Check whether the apex is the point we seek.
    if (fapex[0] == searchpt[0] && fapex[1] == searchpt[1] &&
        fapex[2] == searchpt[2]) {
      senext2self(*searchsh);
      return ONVERTEX;
    }
    // Does the point lie on the other side of the line defined by the
    //   triangle edge opposite the triangle's destination?
    destori = orient3d(forg, fapex, liftpoint, searchpt);
    // Does the point lie on the other side of the line defined by the
    //   triangle edge opposite the triangle's origin? 
    orgori = orient3d(fapex, fdest, liftpoint, searchpt);
    if (destori > 0.0) {
      moveleft = 1;
    } else {
      if (orgori > 0.0) {
        moveleft = 0;
      } else {
        // The point must be on the boundary of or inside this triangle.
        if (destori == 0.0) {
          senext2self(*searchsh);
          return ONEDGE;
        } 
        if (orgori == 0.0) {
          senextself(*searchsh);
          return ONEDGE;
        }
        return ONFACE;
      }
    }
    // Move to another triangle.  Leave a trace `backtracksh' in case
    //   walking off a boundary of the triangulation.
    if (moveleft) {
      senext2(*searchsh, backtracksh);
      fdest = fapex;
    } else {
      senext(*searchsh, backtracksh);
      forg = fapex;
    }
    // Check if we meet a segment.
    sspivot(backtracksh, checkedge);
    if (checkedge.sh != dummysh) {
      if (stopatseg) {
        // The flag indicates we should not cross a segment. Stop.
        *searchsh = backtracksh;
        return OUTSIDE;
      }
      // Try to walk through a segment. We need to find a coplanar subface
      //   sharing this segment to get into.
      spinsh = backtracksh;
      do {
        spivotself(spinsh);
        if (spinsh.sh == backtracksh.sh) {
          // Turn back, no coplanar subface is found.
          break;
        }
        // Are they belong to the same facet.
        if (shellmark(spinsh) == shellmark(backtracksh)) {
          // Find a coplanar subface. Walk into it.
          *searchsh = spinsh;
          break;
        }
        // Are they (nearly) coplanar?
        ori = orient3d(forg, fdest, sapex(backtracksh), sapex(spinsh));
        if (iscoplanar(forg, fdest, sapex(backtracksh), sapex(spinsh), ori,
                       b->epsilon)) {
          // Find a coplanar subface. Walk into it.
          *searchsh = spinsh;
          break;
        }
      } while (spinsh.sh != backtracksh.sh);
    } else {
      spivot(backtracksh, *searchsh);
    }
    // Check for walking right out of the triangulation.
    if ((searchsh->sh == dummysh) || (searchsh->sh == backtracksh.sh)) {
      // Go back to the last triangle.
      *searchsh = backtracksh;
      return OUTSIDE;
    }
    // To keep the same orientation wrt. liftpoint.
    // adjustedgering(*searchsh, CCW);
    if (sorg(*searchsh) != forg) {
      sesymself(*searchsh);
    }
    assert((sorg(*searchsh) == forg) && (sdest(*searchsh) == fdest));
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// adjustlocatesub()    Adjust the precise location of a vertex.             //
//                                                                           //
// 'precise' is the precise location (returned from locatesub()) of 'searcht'//
// with respect to 'searchsh'. 'epspp' is the given relative tolerance.      //
//                                                                           //
// This routine re-evaluates the orientations of 'searchpt' with respect to  //
// the three edges of 'searchsh'. Detects the collinearities by additinal    //
// tests based on the given tolerance. If 'precise' is ONEDGE, one can save  //
// one orientation test for the current edge of 'searchsh'.                  //
//                                                                           //
// On completion, 'searchsh' is a subface contains 'searchpt'. The returned  //
// value indicates one of the following cases:                               //
//   - Returns ONVERTEX if the point lies on an existing vertex. 'searchsh'  //
//     is a handle whose origin is the existing vertex.                      //
//   - Returns ONEDGE if the point lies on a mesh edge.  'searchsh' is a     //
//     handle whose primary edge is the edge on which the point lies.        //
//   - Returns ONFACE if the point lies strictly within a subface.           //
//     'searchsh' is a handle on which the point lies.                       //
//   - Returns OUTSIDE if the point lies outside 'searchsh'.                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

enum tetgenmesh::locateresult tetgenmesh::
adjustlocatesub(point searchpt, face* searchsh, enum locateresult precise,
                REAL epspp)
{
  point pa, pb, pc;
  bool s1, s2, s3;

  pa = sorg(*searchsh);
  pb = sdest(*searchsh);
  pc = sapex(*searchsh);

  if (precise == ONEDGE) {
    s1 = true;
  } else {
    s1 = iscollinear(pa, pb, searchpt, epspp);
  }
  s2 = iscollinear(pb, pc, searchpt, epspp);
  s3 = iscollinear(pc, pa, searchpt, epspp);
  if (s1) {
    if (s2) {
      // on vertex pb.
      assert(!s3);
      senextself(*searchsh);
      return ONVERTEX;
    } else if (s3) {
      // on vertex pa.
      return ONVERTEX;
    } else {
      // on edge pa->pb.
      return ONEDGE;
    }
  } else if (s2) {
    if (s3) {
      // on vertex pc.
      senext2self(*searchsh);
      return ONVERTEX;
    } else {
      // on edge pb->pc.
      senextself(*searchsh);
      return ONEDGE;
    }
  } else if (s3) {
    // on edge pc->pa.
    senext2self(*searchsh);
    return ONEDGE;
  } else {
    return precise;
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// flipsub()    Flip all non-Delaunay edges in a given queue of subfaces.    //
//                                                                           //
// Assumpation:  Current triangulation is non-Delaunay after inserting a     //
// point or performing a flip operation, all possibly non-Delaunay edges are //
// in 'facequeue'. The return value is the total number of flips done during //
// this invocation.                                                          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

long tetgenmesh::flipsub(queue* flipqueue)
{
  badface *qedge;
  face flipedge, symedge, bdedge;
  point pa, pb, pc, pd;
  REAL liftpt[3], n[3], nlen;
  REAL sign, ll, d1, d2;
  int edgeflips, i;

  if (b->verbose > 1) {
    printf("  Start do edge queue: %ld edges.\n", flipqueue->len());
  }

  edgeflips = 0;

  while ((qedge = (badface *) flipqueue->pop()) != NULL) {
    flipedge = qedge->ss;
    if (flipedge.sh == dummysh) continue;
    if ((sorg(flipedge) != qedge->forg) || 
        (sdest(flipedge) != qedge->fdest)) continue; 
    sspivot(flipedge, bdedge);
    if (bdedge.sh != dummysh) continue;  // Can't flip a subsegment.
    spivot(flipedge, symedge);
    if (symedge.sh == dummysh) continue; // Can't flip a hull edge.
    pa = sorg(flipedge);
    pb = sdest(flipedge);
    pc = sapex(flipedge);
    pd = sapex(symedge);
    // liftpoint = getliftpoint(shellmark(flipedge));
    // If abc is nearly collinear, orient3d() test may return wrong value.
    //   Choose abc or abd when it has the bigger area than the other.
    d1 = shortdistance(pc, pa, pb);
    d2 = shortdistance(pd, pa, pb);
    ll = distance(pa, pb);
    if (d1 > d2) {
      // Use abc as the base.
      facenormal(pa, pb, pc, n, &nlen);
      for (i = 0; i < 3; i++) n[i] /= nlen;
      for (i = 0; i < 3; i++) liftpt[i] = pa[i] + ll * n[i];
      // liftpt is above abc;
      sign = insphere(pb, pa, pc, liftpt, pd);
    } else {
      // Use abd as the base.
      facenormal(pa, pb, pd, n, &nlen);
      for (i = 0; i < 3; i++) n[i] /= nlen;
      for (i = 0; i < 3; i++) liftpt[i] = pa[i] + ll * n[i];
      // liftpt is above abd;
      sign = insphere(pb, pa, pd, liftpt, pc);
    }
    if (sign > 0.0) {
      // Flip the non-Delaunay edge.
      flip22sub(&flipedge, flipqueue);
      edgeflips++;
    }
  }

  if (b->verbose > 1) {
    printf("  Total %d flips.\n", edgeflips);
  }

  return edgeflips;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// incrflipinitsub()    Create a initial triangulation.                      //
//                                                                           //
// The initial triangulation only consists of one triangle formed by three   //
// non-collinear points. 'facetidx' is the index of the facet in 'facetlist' //
// (starts from 1) of the tetgenio structure;  'ptlist' is a list of indices //
// of the facet vertices; 'idx2verlist' is a map from indices to vertices.   //
//                                                                           //
// The 'lift point' of this facet is calculated.  If not all vertices of the //
// facet are collinear,  such point is found by lifting the centroid of the  //
// set of vertices for a certain distance along the normal of this facet.    //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenmesh::
incrflipinitsub(int facetidx, list* ptlist, point* idx2verlist)
{
  face newsh;
  point pt1, pt2, pt3;
  point liftpoint, ptloop;
  pbcdata *pd;
  REAL cent[3], norm[3];
  REAL v1[3], v2[3];
  REAL smallcos, cosa;
  REAL liftdist, len, vol;
  int idx, smallidx;
  int i, j;
  
  if (ptlist->len() > 3) {
    // Find a (non-degenerate) vector from the vertex set.
    idx =  * (int *) (* ptlist)[0];
    pt1 = idx2verlist[idx - in->firstnumber];
    len = 0.0;
    // Loop the set of vertices until a not too small edge be found.
    for (i = 1; i < ptlist->len(); i++) {
      idx =  * (int *) (* ptlist)[i];
      pt2 = idx2verlist[idx - in->firstnumber];
      v1[0] = pt2[0] - pt1[0];
      v1[1] = pt2[1] - pt1[1];
      v1[2] = pt2[2] - pt1[2];
      len = sqrt(dot(v1, v1));
      if ((len / longest) > (b->epsilon * 1e+2)) break;
    } 
    // Remember this size as lift distance.
    liftdist = len;
    // 'v1' is a reasonable vector, normalize it.
    for (i = 0; i < 3; i++) v1[i] /= len;
    // Continue to find another (non-degenerate) vector, which forms an
    //   angle with v1 most close to 90 degree.
    smallcos = 1.0; // The cosine value of 0 degree.
    for (i = 1; i < ptlist->len(); i++) {
      idx =  * (int *) (* ptlist)[i];
      pt3 = idx2verlist[idx - in->firstnumber];
      if (pt3 == pt2) continue; // Skip the same point.
      v2[0] = pt3[0] - pt1[0];
      v2[1] = pt3[1] - pt1[1];
      v2[2] = pt3[2] - pt1[2];
      len = sqrt(dot(v2, v2));
      if (len > 0.0) { // v2 is not too small.
        cosa = fabs(dot(v1, v2)) / len;
        if (cosa < smallcos) {
          smallidx = idx;
          smallcos = cosa;
        }
      } else {  // len == 0.0, two identical points defined in a facet.
        printf("Warning:  Facet %d has two identical vertices: %d, %d.\n",
               facetidx, pointmark(pt1), pointmark(pt3));
        return false; // Invalid polygon, do not procced.
      }
    }
    if (smallcos == 1.0) {
      // The input set of vertices is not a good set (or nearly degenerate).
      printf("Warning:  Facet %d with vertices: ", facetidx);
      for (i = 0; i < 3; i++) {
        idx =  * (int *) (* ptlist)[i];
        ptloop = idx2verlist[idx - in->firstnumber];
        printf("%d ", pointmark(ptloop));
      }
      printf("... is degenerate.\n");
      return false; // Invalid polygon, do not procced.
    }
    // Get the right point to form v2.
    pt3 = idx2verlist[smallidx - in->firstnumber];
    assert(pt3 != pt2);
    v2[0] = pt3[0] - pt1[0];
    v2[1] = pt3[1] - pt1[1];
    v2[2] = pt3[2] - pt1[2];
    len = sqrt(dot(v2, v2));
    assert(len > 0.0);
    // Remember this size as lift distance.
    liftdist = (liftdist > len ? liftdist : len);
    // 'v2' is a reasonable vector, normalize it.
    for (i = 0; i < 3; i++) v2[i] /= len;
  } else { 
    // There are only three vertices of this facet (a triangle).
    idx =  * (int *) (* ptlist)[0];
    pt1 = idx2verlist[idx - in->firstnumber];
    idx =  * (int *) (* ptlist)[1];
    pt2 = idx2verlist[idx - in->firstnumber];
    idx =  * (int *) (* ptlist)[2];
    pt3 = idx2verlist[idx - in->firstnumber];
    v1[0] = pt2[0] - pt1[0];
    v1[1] = pt2[1] - pt1[1];
    v1[2] = pt2[2] - pt1[2];
    len = sqrt(dot(v1, v1));
    if (len == 0.0) {
      printf("Warning:  Facet %d has two identical vertices: %d, %d.\n",
             facetidx, pointmark(pt1), pointmark(pt2));
      return false; // Invalid polygon, do not procced.
    }
    // Remember this size as lift distance.
    liftdist = len;
    // 'v1' is a reasonable vector, normalize it.
    for (i = 0; i < 3; i++) v1[i] /= len;
    v2[0] = pt3[0] - pt1[0];
    v2[1] = pt3[1] - pt1[1];
    v2[2] = pt3[2] - pt1[2];
    len = sqrt(dot(v2, v2));
    if (len == 0.0) {
      printf("Warning:  Facet %d has two identical vertices: %d, %d.\n",
             facetidx, pointmark(pt1), pointmark(pt3));
      return false; // Invalid polygon, do not procced.
    }
    // Remember this size as lift distance.
    liftdist = (liftdist > len ? liftdist : len);
    // 'v2' is a reasonable vector, normalize it.
    for (i = 0; i < 3; i++) v2[i] /= len;
  }
  // Calculate the unit normal of this facet.
  cross(v1, v2, norm);

  // Calculate the centroid point of the vertex set. At the same time, check
  //   whether vertices of this facet are roughly coplanar or not.
  cent[0] = cent[1] = cent[2] = 0.0;
  for (i = 0; i < ptlist->len(); i++) {
    idx =  * (int *) (* ptlist)[i];
    ptloop = idx2verlist[idx - in->firstnumber];
    if (ptlist->len() > 3) {
      vol = orient3d(pt1, pt2, pt3, ptloop);
      if (vol != 0.0) {
        if (!iscoplanar(pt1, pt2, pt3, ptloop, vol, b->epsilon * 1e+3)) {
          printf("Warning:  Facet %d has a non-coplanar vertex %d.\n",
                 facetidx, pointmark(ptloop));
          // This is not a fatal problem, we still can procced.
        }
      }
    }
    cent[0] += ptloop[0];
    cent[1] += ptloop[1];
    cent[2] += ptloop[2];
  }
  for (i = 0; i < 3; i++) cent[i] /= ptlist->len();
  // Calculate the lifting point of the facet. It is lifted from 'cent'
  //   along the normal direction with a certain ditance.
  liftpoint = getliftpoint(facetidx); 
  for (i = 0; i < 3; i++) {
    liftpoint[i] = cent[i] + liftdist * norm[i];
  }

  // Create the initial triangle. The liftpoint is above (pt1, pt2, pt3).
  makeshellface(subfaces, &newsh);
  setsorg(newsh, pt1);
  setsdest(newsh, pt2);
  setsapex(newsh, pt3);
  // Remeber the facet it belongs to.
  setshellmark(newsh, facetidx);
  // Set vertices be type FACETVERTEX to indicate they belong to a facet.
  setpointtype(pt1, FACETVERTEX);
  setpointtype(pt2, FACETVERTEX);
  setpointtype(pt3, FACETVERTEX);
  // Bond this subface to 'dummysh' for point location routine.
  dummysh[0] = sencode(newsh);

  // Is there pbc conditions?
  if (checkpbcs) {
    // Get the facet marker (saved in 'in->facetmarkerlist').
    idx = in->facetmarkerlist[facetidx - 1];
    for (i = 0; i < in->numberofpbcgroups; i++) {
      pd = &subpbcgrouptable[i];
      for (j = 0; j < 2; j++) {
        if (pd->fmark[j] == idx) {
          setshellpbcgroup(newsh, i);
          pd->ss[j] = newsh;
        }
      }
    }
  }

  return true;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// collectvisiblesubs()    Collect convex hull edges which are visible from  //
//                         the inserting point. Construct new subfaces from  //
//                         these edges and the point.                        //
//                                                                           //
// 'facetidx' is the index of the facet in 'in->facetlist' (starts from 1),  //
// 'inspoint' is located outside current triangulation, 'horiz' is the hull  //
// edge it is visible. 'flipqueue' returns the visible hull edges which have //
// become interior edges on completion of this routine.                      //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::
collectvisiblesubs(int facetidx, point inspoint, face* horiz, queue* flipqueue)
{
  face newsh, hullsh;
  face rightsh, leftsh, spinedge;
  point horg, hdest, liftpoint;
  bool aboveflag;

  liftpoint = getliftpoint(facetidx); 

  // Create a new subface above 'horiz'.
  adjustedgering(*horiz, CCW);
  makeshellface(subfaces, &newsh);
  setsorg(newsh, sdest(*horiz));
  setsdest(newsh, sorg(*horiz));
  setsapex(newsh, inspoint);
  setshellmark(newsh, facetidx);
  if (checkpbcs) {
    setshellpbcgroup(newsh, shellpbcgroup(*horiz));
  }
  // Make the connection.
  sbond(newsh, *horiz);
  // 'horiz' becomes interior edge.
  enqueueflipedge(*horiz, flipqueue);
  
  // Finish the hull edges at the right side of the newsh.
  hullsh = *horiz;
  while (1) {
    senext(newsh, rightsh);
    // Get the right hull edge of 'horiz' by spinning inside edges around
    //   the origin of 'horiz' until reaching the 'dummysh'.
    spinedge = hullsh;
    do {
      hullsh = spinedge;
      senext2self(hullsh);
      spivot(hullsh, spinedge);
      adjustedgering(spinedge, CCW);
    } while (spinedge.sh != dummysh);
    // Test whether 'inspoint' is visible from 'hullsh'.
    horg = sorg(hullsh);
    hdest = sdest(hullsh);
    aboveflag = orient3d(horg, hdest, liftpoint, inspoint) < 0.0;
    if (aboveflag) {
      // It's a visible hull edge.
      makeshellface(subfaces, &newsh);
      setsorg(newsh, sdest(hullsh));
      setsdest(newsh, sorg(hullsh));
      setsapex(newsh, inspoint);
      setshellmark(newsh, facetidx);
      if (checkpbcs) {
        setshellpbcgroup(newsh, shellpbcgroup(hullsh));
      }
      // Make the connection.
      sbond(newsh, hullsh);
      senext2(newsh, leftsh);
      sbond(leftsh, rightsh);
      // 'horiz' becomes interior edge.
      enqueueflipedge(hullsh, flipqueue); 
    } else {
      // 'rightsh' is a new hull edge.
      dummysh[0] = sencode(rightsh);
      break;
    }
  }

  // Finish the hull edges at the left side of the newsh.
  hullsh = *horiz;
  spivot(*horiz, newsh);
  while (1) {
    senext2(newsh, leftsh);
    // Get the left hull edge of 'horiz' by spinning edges around the
    //   destination of 'horiz'.
    spinedge = hullsh;
    do {
      hullsh = spinedge;
      senextself(hullsh);
      spivot(hullsh, spinedge);
      adjustedgering(spinedge, CCW);
    } while (spinedge.sh != dummysh);
    // Test whether 'inspoint' is visible from 'hullsh'.
    horg = sorg(hullsh);
    hdest = sdest(hullsh);
    aboveflag = orient3d(horg, hdest, liftpoint, inspoint) < 0.0;
    if (aboveflag) {
      // It's a visible hull edge.
      makeshellface(subfaces, &newsh);
      setsorg(newsh, sdest(hullsh));
      setsdest(newsh, sorg(hullsh));
      setsapex(newsh, inspoint);
      setshellmark(newsh, facetidx);
      if (checkpbcs) {
        setshellpbcgroup(newsh, shellpbcgroup(hullsh));
      }
      // Make the connection.
      sbond(newsh, hullsh);
      senext(newsh, rightsh);
      sbond(rightsh, leftsh);
      // 'horiz' becomes interior edge.
      enqueueflipedge(hullsh, flipqueue); 
    } else {
      // 'leftsh' is a new hull edge.
      dummysh[0] = sencode(leftsh);
      break;
    }
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// incrflipdelaunaysub()    Create a Delaunay triangulation from a 3D point  //
//                          set using the incremental flip algorithm.        //
//                                                                           //
// 'facetidx' is the index of the facet in 'in->facetlist' (starts from 1),  //
// 'ptlist' is the index list of the vertices of the facet, 'idx2verlist' is //
// a map from indices to vertices.                                           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::
incrflipdelaunaysub(int facetidx, list* ptlist, point* idx2verlist,
                    queue* flipqueue)
{
  face startsh;
  point pointloop;
  enum locateresult loc;
  int idx, i;  

  for (i = 1; i < ptlist->len(); i++) {
    idx =  * (int *) (* ptlist)[i];
    pointloop = idx2verlist[idx - in->firstnumber];
    // Set vertices be type FACETVERTEX to indicate they belong to a facet.
    setpointtype(pointloop, FACETVERTEX);
    startsh.sh = dummysh;
    loc = locatesub(pointloop, &startsh, 0);
    if (loc == ONVERTEX) continue;
    if (loc == ONFACE) {
      splitsubface(pointloop, &startsh, flipqueue);
    } else if (loc == ONEDGE) {
      splitsubedge(pointloop, &startsh, flipqueue);
    } else if (loc == OUTSIDE) {
      collectvisiblesubs(facetidx, pointloop, &startsh, flipqueue);
    }
    flipsub(flipqueue);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// finddirectionsub()    Find the first subface in a facet on the path from  //
//                       one point to another.                               //
//                                                                           //
// Finds the subface in the facet that intersects a line segment drawn from  //
// the origin of `searchsh' to the point `tend', and returns the result in   //
// `searchsh'.  The origin of `searchsh' does not change,  even though the   //
// subface returned may differ from the one passed in.                       //
//                                                                           //
// The return value notes whether the destination or apex of the found face  //
// is collinear with the two points in question.                             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

enum tetgenmesh::finddirectionresult tetgenmesh::
finddirectionsub(face* searchsh, point tend)
{
  face checksh;
  point startpoint, liftpoint;
  point leftpoint, rightpoint;
  REAL leftccw, rightccw;
  int leftflag, rightflag;

  adjustedgering(*searchsh, CCW);
  liftpoint = getliftpoint(shellmark(*searchsh)); 
  startpoint = sorg(*searchsh);
  rightpoint = sdest(*searchsh);
  leftpoint = sapex(*searchsh);
  // Is `tend' to the left?
  leftccw = orient3d(tend, startpoint, liftpoint, leftpoint);
  leftflag = leftccw > 0.0;
  // Is `tend' to the right?
  rightccw = orient3d(startpoint, tend, liftpoint, rightpoint);
  rightflag = rightccw > 0.0;
  if (leftflag && rightflag) {
    // `searchsh' faces directly away from `tend'.  We could go left or
    //   right.  Ask whether it's a triangle or a boundary on the left.
    senext2(*searchsh, checksh);
    spivotself(checksh);
    if (checksh.sh == dummysh) {
      leftflag = 0;
    } else {
      rightflag = 0;
    }
  }
  while (leftflag) {
    // Turn left until satisfied.
    senext2self(*searchsh);
    spivotself(*searchsh);
    if (searchsh->sh == dummysh) {
      printf("Internal error in finddirectionsub():  Unable to find a\n");
      printf("  triangle leading from %d to %d.\n", pointmark(startpoint),
             pointmark(tend));
      internalerror();
    }
    adjustedgering(*searchsh, CCW);
    leftpoint = sapex(*searchsh);
    rightccw = leftccw;
    leftccw = orient3d(tend, startpoint, liftpoint, leftpoint);
    leftflag = leftccw > 0.0;
  }
  while (rightflag) {
    // Turn right until satisfied.
    spivotself(*searchsh);
    if (searchsh->sh == dummysh) {
      printf("Internal error in finddirectionsub():  Unable to find a\n");
      printf("  triangle leading from %d to %d.\n", pointmark(startpoint),
             pointmark(tend));
      internalerror();
    }
    adjustedgering(*searchsh, CCW);
    senextself(*searchsh);
    rightpoint = sdest(*searchsh);
    leftccw = rightccw;
    rightccw = orient3d(startpoint, tend, liftpoint, rightpoint);
    rightflag = rightccw > 0.0;
  }
  if (leftccw == 0.0) {
    return LEFTCOLLINEAR;
  } else if (rightccw == 0.0) {
    return RIGHTCOLLINEAR;
  } else {
    return ACROSSEDGE;
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// insertsubseg()    Create a subsegment and insert it between two subfaces. //
//                                                                           //
// The new subsegment is inserted at the edge described by the handle 'tri'. //
// If 'tri' is not on the hull, the segment is inserted between two faces.   //
// If 'tri' is a hull face, the initial face ring of this segment will be    //
// set only one face which is self-bonded.  The official face ring will be   //
// constructed later in routine unifysegments().                             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::insertsubseg(face* tri)
{
  face oppotri;
  face newsubseg;

  // Check if there's already a subsegment here.
  sspivot(*tri, newsubseg);
  if (newsubseg.sh == dummysh) {
    // Make new subsegment and initialize its vertices.
    makeshellface(subsegs, &newsubseg);
    setsorg(newsubseg, sorg(*tri));
    setsdest(newsubseg, sdest(*tri));
    // Bond new subsegment to the two triangles it is sandwiched between.
    ssbond(*tri, newsubseg);
    spivot(*tri, oppotri);
    // 'oppotri' might be "out space".
    if (oppotri.sh != dummysh) {
      ssbond(oppotri, newsubseg);
    } else {
      // Outside! Bond '*tri' to itself.
      sbond(*tri, *tri);
    }
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// scoutsegmentsub()    Scout the first triangle on the path from one point  //
//                      to another, and check for completion (reaching the   //
//                      second point), a collinear point,or the intersection //
//                      of two segments.                                     //
//                                                                           //
// Returns true if the entire segment is successfully inserted, and false if //
// the job must be finished by constrainededge().                            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenmesh::scoutsegmentsub(face* searchsh, point tend)
{
  face newsubseg;
  face crosssub, crosssubseg;
  point leftpoint, rightpoint;
  enum finddirectionresult collinear;

  collinear = finddirectionsub(searchsh, tend);
  rightpoint = sdest(*searchsh);
  leftpoint = sapex(*searchsh);
  if (rightpoint == tend || leftpoint == tend) {
    // The segment is already an edge.
    if (leftpoint == tend) {
      senext2self(*searchsh);
    }
    // Insert a subsegment.
    insertsubseg(searchsh);
    return true;
  } else if (collinear == LEFTCOLLINEAR) {
    // We've collided with a vertex between the segment's endpoints.
    // Make the collinear vertex be the triangle's origin.
    senextself(*searchsh); // lprevself(*searchtri);
    // Insert a subsegment.
    insertsubseg(searchsh);
    // Insert the remainder of the segment.
    return scoutsegmentsub(searchsh, tend);
  } else if (collinear == RIGHTCOLLINEAR) {
    // We've collided with a vertex between the segment's endpoints.
    // Insert a subsegment.
    insertsubseg(searchsh);
    // Make the collinear vertex be the triangle's origin.
    senextself(*searchsh); // lnextself(*searchtri);
    // Insert the remainder of the segment.
    return scoutsegmentsub(searchsh, tend);
  } else {
    senext(*searchsh, crosssub); // lnext(*searchtri, crosstri);
    // Check for a crossing segment.
    sspivot(crosssub, crosssubseg);
    assert(crosssubseg.sh == dummysh);
    return false;
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// delaunayfixup()    Enforce the Delaunay condition at an edge, fanning out //
//                    recursively from an existing point. Pay special        //
//                    attention to stacking inverted triangles.              //
//                                                                           //
// This is a support routine for inserting segments into a constrained       //
// Delaunay triangulation.                                                   //
//                                                                           //
// The origin of 'fixupsh' is treated as if it has just been inserted, and   //
// the local Delaunay condition needs to be enforced. It is only enforced in //
// one sector, however, that being the angular range defined by 'fixupsh'.   //
//                                                                           //
// `leftside' indicates whether or not fixupsh is to the left of the segment //
// being inserted.  (Imagine that the segment is pointing up from endpoint1  //
// to endpoint2.)                                                            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::delaunayfixup(face* fixupsh, int leftside)
{
  face nearsh, farsh, faredge;
  point nearpoint, leftpoint, rightpoint, farpoint;
  point liftpoint;
  REAL sign;

  // It is up to the caller, that 'fixupsh' must be in CCW edge ring.
  // adjustedgering(*fixupsh, CCW);
  assert((fixupsh->shver % 2) == 0);
  senext(*fixupsh, nearsh);
  spivot(nearsh, farsh);
  if (nearsh.sh == farsh.sh) {
    farsh.sh = dummysh;
  }
  // Check if the edge opposite the origin of fixupsh can be flipped.
  if (farsh.sh == dummysh) {
    return;
  }
  adjustedgering(farsh, CCW);
  sspivot(nearsh, faredge);
  if (faredge.sh != dummysh) {
    return;
  }
  // Find all the relevant vertices.
  liftpoint = getliftpoint(shellmark(*fixupsh));
  nearpoint = sapex(nearsh);
  leftpoint = sorg(nearsh);
  rightpoint = sdest(nearsh);
  farpoint = sapex(farsh);
  // Check whether the previous polygon point is a reflex point.
  if (leftside) {
    if (orient3d(nearpoint, leftpoint, liftpoint, farpoint) <= 0.0) {
      // leftpoint is a reflex point too.  Nothing can
      //   be done until a convex section is found. 
      return;
    }
  } else {
    if (orient3d(farpoint, rightpoint, liftpoint, nearpoint) <= 0.0) {
      // rightpoint is a reflex point too.  Nothing can
      //   be done until a convex section is found.
      return;
    }
  }
  if (orient3d(rightpoint, leftpoint, liftpoint, farpoint) > 0.0) {
    // farsh is not an inverted triangle, and farpoint is not a reflex
    //   point.  As there are no reflex vertices, fixupsh isn't an
    //   inverted triangle, either.  Hence, test the edge between the
    //   triangles to ensure it is locally Delaunay.
    sign = insphere(leftpoint, farpoint, rightpoint, liftpoint, nearpoint)
         * orient3d(leftpoint, farpoint, rightpoint, liftpoint);
    if (sign <= 0.0) {
      return;
    }
    // Not locally Delaunay; go on to an edge flip.
  }         // else farsh is inverted; remove it from the stack by flipping.
  flip22sub(&nearsh, NULL);
  senext2self(*fixupsh);    // Restore the origin of fixupsh after the flip.
  // Recursively process the two triangles that result from the flip.
  delaunayfixup(fixupsh, leftside);
  delaunayfixup(&farsh, leftside);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// constrainededge()    Force a segment into a constrained Delaunay          //
//                      triangulation by deleting the triangles it           //
//                      intersects, and triangulating the polygons that      //
//                      form on each side of it.                             //
//                                                                           //
// Generates a single subsegment connecting `tstart' to `tend'. The triangle //
// `startsh' has `tstart' as its origin.                                     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::constrainededge(face* startsh, point tend)
{
  face fixupsh, fixupsh2;
  face crosssubseg, newsubseg;
  point tstart, farpoint;
  point liftpoint;
  REAL area;
  int collision;
  int done;

  liftpoint = getliftpoint(shellmark(*startsh));
  tstart = sorg(*startsh);
  // Always works in the CCW edge ring.
  adjustedgering(*startsh, CCW);
  // Make sure the 'tstart' remians be the origin.
  if (sorg(*startsh) != tstart) {
    senextself(*startsh);
    assert(sorg(*startsh) == tstart);
  }
  senext(*startsh, fixupsh);
  flip22sub(&fixupsh, NULL);
  // `collision' indicates whether we have found a vertex directly
  //   between endpoint1 and endpoint2.
  collision = 0;
  done = 0;
  do {
    farpoint = sorg(fixupsh);
    // `farpoint' is the extreme point of the polygon we are "digging"
    //   to get from tstart to tend.
    if (farpoint == tend) {
      spivot(fixupsh, fixupsh2);  // oprev(fixupsh, fixupsh2);
      adjustedgering(fixupsh2, CCW);
      senextself(fixupsh2);
      // Enforce the Delaunay condition around tend.
      delaunayfixup(&fixupsh, 0);
      delaunayfixup(&fixupsh2, 1);
      done = 1;
    } else {
      // Check whether farpoint is to the left or right of the segment
      //   being inserted, to decide which edge of fixupsh to dig 
      //   through next.
      area = orient3d(tstart, tend, liftpoint, farpoint);
      if (area == 0.0) {
        // We've collided with a vertex between tstart and tend.
        collision = 1;
        spivot(fixupsh, fixupsh2);  // oprev(fixupsh, fixupsh2);
        adjustedgering(fixupsh2, CCW);
        senextself(fixupsh2);
        // Enforce the Delaunay condition around farpoint.
        delaunayfixup(&fixupsh, 0);
        delaunayfixup(&fixupsh2, 1);
        done = 1;
      } else {
        if (area > 0.0) {        // farpoint is to the left of the segment.
          spivot(fixupsh, fixupsh2);  // oprev(fixupsh, fixupsh2);
          adjustedgering(fixupsh2, CCW);
          senextself(fixupsh2); 
          // Enforce the Delaunay condition around farpoint, on the
          //   left side of the segment only.
          delaunayfixup(&fixupsh2, 1);
          // Flip the edge that crosses the segment.  After the edge is
          //   flipped, one of its endpoints is the fan vertex, and the
          //   destination of fixupsh is the fan vertex.
          senext2self(fixupsh); // lprevself(fixupsh);
        } else {                // farpoint is to the right of the segment.
          delaunayfixup(&fixupsh, 0);
          // Flip the edge that crosses the segment.  After the edge is
          //   flipped, one of its endpoints is the fan vertex, and the
          //   destination of fixupsh is the fan vertex.
          spivotself(fixupsh);  // oprevself(fixupsh);
          adjustedgering(fixupsh, CCW);
          senextself(fixupsh); 
        }
        // Check for two intersecting segments.
        sspivot(fixupsh, crosssubseg);
        if (crosssubseg.sh == dummysh) {
          flip22sub(&fixupsh, NULL);// May create inverted triangle at left.
        } else {
          // We've collided with a segment between tstart and tend.
          /* collision = 1;
          // Insert a vertex at the intersection.
          segmentintersection(m, b, &fixupsh, &crosssubseg, tend);
          done = 1;
          */
          assert(0);
        }
      }
    }
  } while (!done);
  // Insert a subsegment to make the segment permanent.
  insertsubseg(&fixupsh);
  // If there was a collision with an interceding vertex, install another
  //   segment connecting that vertex with endpoint2.
  if (collision) {
    // Insert the remainder of the segment.
    if (!scoutsegmentsub(&fixupsh, tend)) {
      constrainededge(&fixupsh, tend);
    }
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// insertsegmentsub()    Insert a PSLG segment into a triangulation.         //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::insertsegmentsub(point tstart, point tend)
{
  face searchsh1, searchsh2;

  if (b->verbose > 2) {
    printf("    Insert subsegment (%d, %d).\n", pointmark(tstart),
           pointmark(tend));
  }

  // Find a triangle whose origin is the segment's first endpoint.
  searchsh1.sh = dummysh;
  // Search for the segment's first endpoint by point location.
  if (locatesub(tstart, &searchsh1, 0) != ONVERTEX) {
    printf("Internal error in insertsegmentsub():");
    printf("  Unable to locate PSLG vertex %d.\n", pointmark(tstart));
    internalerror();
  }
  // Scout the beginnings of a path from the first endpoint
  //   toward the second. 
  if (scoutsegmentsub(&searchsh1, tend)) {
    // The segment was easily inserted.
    return;
  }
  // The first endpoint may have changed if a collision with an intervening
  //   vertex on the segment occurred.
  tstart = sorg(searchsh1);
  
  // Find a boundary triangle to search from.
  searchsh2.sh = dummysh;
  // Search for the segment's second endpoint by point location.
  if (locatesub(tend, &searchsh2, 0) != ONVERTEX) {
    printf("Internal error in insertsegmentsub():");
    printf("  Unable to locate PSLG vertex %d.\n", pointmark(tend));
    internalerror();
  }
  // Scout the beginnings of a path from the second endpoint
  //   toward the first.
  if (scoutsegmentsub(&searchsh2, tstart)) {
    // The segment was easily inserted.
    return;
  }
  // The second endpoint may have changed if a collision with an intervening
  //   vertex on the segment occurred. 
  tend = sorg(searchsh2);
  
  // Insert the segment directly into the triangulation.
  constrainededge(&searchsh1, tend);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// infecthullsub()    Virally infect all of the triangles of the convex hull //
//                    that are not protected by subsegments.                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::infecthullsub(memorypool* viri)
{
  face hulltri, nexttri, starttri;
  face hullsubseg;
  shellface **deadshellface;

  // Find a triangle handle on the hull.
  hulltri.sh = dummysh;
  hulltri.shver = 0;
  spivotself(hulltri);
  adjustedgering(hulltri, CCW);
  // Remember where we started so we know when to stop.
  starttri = hulltri;
  // Go once counterclockwise around the convex hull.
  do {
    // Ignore triangles that are already infected.
    if (!sinfected(hulltri)) {
      // Is the triangle protected by a subsegment?
      sspivot(hulltri, hullsubseg);
      if (hullsubseg.sh == dummysh) {
        // The triangle is not protected; infect it.
        if (!sinfected(hulltri)) {
          sinfect(hulltri);
          deadshellface = (shellface **) viri->alloc();
          *deadshellface = hulltri.sh;
        }
      } 
    }
    // To find the next hull edge, go clockwise around the next vertex.
    senextself(hulltri); // lnextself(hulltri);
    spivot(hulltri, nexttri); // oprev(hulltri, nexttri);
    if (nexttri.sh == hulltri.sh) {
      nexttri.sh = dummysh;  // 'hulltri' is self-bonded.
    } else {
      adjustedgering(nexttri, CCW);
      senextself(nexttri);
    }
    while (nexttri.sh != dummysh) {
      hulltri = nexttri;
      spivot(hulltri, nexttri); // oprev(hulltri, nexttri);
      if (nexttri.sh == hulltri.sh) {
        nexttri.sh = dummysh;  // 'hulltri' is self-bonded.
      } else {
        adjustedgering(nexttri, CCW);
        senextself(nexttri);
      }
    }
  } while (hulltri != starttri);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// plaguesub()    Spread the virus from all infected triangles to any        //
//                neighbors not protected by subsegments.  Delete all        //
//                infected triangles.                                        //
//                                                                           //
// This is the procedure that actually creates holes and concavities.        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::plaguesub(memorypool* viri)
{
  face testtri, neighbor, ghostsh;
  face neighborsubseg;
  shellface **virusloop;
  shellface **deadshellface;
  int i;

  // Loop through all the infected triangles, spreading the virus to
  //   their neighbors, then to their neighbors' neighbors.
  viri->traversalinit();
  virusloop = (shellface **) viri->traverse();
  while (virusloop != (shellface **) NULL) {
    testtri.sh = *virusloop;
    // Check each of the triangle's three neighbors.
    for (i = 0; i < 3; i++) {
      // Find the neighbor.
      spivot(testtri, neighbor);
      // Check for a subsegment between the triangle and its neighbor.
      sspivot(testtri, neighborsubseg);
      // Check if the neighbor is nonexistent or already infected.
      if ((neighbor.sh == dummysh) || sinfected(neighbor)) {
        if (neighborsubseg.sh != dummysh) {
          // There is a subsegment separating the triangle from its
          //   neighbor, but both triangles are dying, so the subsegment
          //   dies too.
          shellfacedealloc(subsegs, neighborsubseg.sh);
          if (neighbor.sh != dummysh) {
            // Make sure the subsegment doesn't get deallocated again
            //   later when the infected neighbor is visited.
            ssdissolve(neighbor);
          }
        }
      } else {                   // The neighbor exists and is not infected.
        if (neighborsubseg.sh == dummysh) {
          // There is no subsegment protecting the neighbor, so the
          //   neighbor becomes infected.
          sinfect(neighbor);
          // Ensure that the neighbor's neighbors will be infected.
          deadshellface = (shellface **) viri->alloc();
          *deadshellface = neighbor.sh;
        } else {               // The neighbor is protected by a subsegment.
          // Remove this triangle from the subsegment.
          ssbond(neighbor, neighborsubseg);
        }
      }
      senextself(testtri);
    }
    virusloop = (shellface **) viri->traverse();
  }

  ghostsh.sh = dummysh; // A handle of outer space.
  viri->traversalinit();
  virusloop = (shellface **) viri->traverse();
  while (virusloop != (shellface **) NULL) {
    testtri.sh = *virusloop;
    // Record changes in the number of boundary edges, and disconnect
    //   dead triangles from their neighbors. 
    for (i = 0; i < 3; i++) {
      spivot(testtri, neighbor);
      if (neighbor.sh != dummysh) {
        // Disconnect the triangle from its neighbor.
        // sdissolve(neighbor);
        sbond(neighbor, ghostsh); 
      }
      senextself(testtri);
    }
    // Return the dead triangle to the pool of triangles.
    shellfacedealloc(subfaces, testtri.sh);
    virusloop = (shellface **) viri->traverse();
  }
  // Empty the virus pool.
  viri->restart();
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// carveholessub()    Find the holes and infect them.  Find the area         //
//                    constraints and infect them.  Infect the convex hull.  //
//                    Spread the infection and kill triangles.  Spread the   //
//                    area constraints.                                      //
//                                                                           //
// This routine mainly calls other routines to carry out all these functions.//
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::carveholessub(int holes, REAL* holelist)
{
  face searchtri, triangleloop;
  shellface **holetri;
  memorypool *viri;
  enum locateresult intersect;
  int i;

  // Initialize a pool of viri to be used for holes, concavities.
  viri = new memorypool(sizeof(shellface *), 1024, POINTER, 0);

  // Mark as infected any unprotected triangles on the boundary.
  //   This is one way by which concavities are created.
  infecthullsub(viri);

  if (holes > 0) {
    // Infect each triangle in which a hole lies.
    for (i = 0; i < 3 * holes; i += 3) {
      // Ignore holes that aren't within the bounds of the mesh.
      if ((holelist[i] >= xmin) && (holelist[i] <= xmax)
          && (holelist[i + 1] >= ymin) && (holelist[i + 1] <= ymax)
          && (holelist[i + 2] >= zmin) && (holelist[i + 2] <= zmax)) {
        // Start searching from some triangle on the outer boundary.
        searchtri.sh = dummysh;
        // Find a triangle that contains the hole.
        intersect = locatesub(&holelist[i], &searchtri, 0);
        if ((intersect != OUTSIDE) && (!sinfected(searchtri))) {
          // Infect the triangle.  This is done by marking the triangle
          //   as infected and including the triangle in the virus pool.
          sinfect(searchtri);
          holetri = (shellface **) viri->alloc();
          *holetri = searchtri.sh;
        }
      }
    }
  }

  if (viri->items > 0) {
    // Carve the holes and concavities.
    plaguesub(viri);
  }
  // The virus pool should be empty now.

  // Free up memory.
  delete viri;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// triangulatefacet()    Create a constrained Delaunay triang. for a facet.  //
//                                                                           //
// 'facetidx' is the index of the facet in 'in->facetlist' (starts from 1),  //
// 'idx2verlist' is a map from indices to vertices.  'ptlist' and 'conlist'  //
// are two lists used to assemble the input data for each facet, 'ptlist'    //
// stores the index set of its vertices, 'conlist' stores the set of its     //
// segments, they should be empty on input and output.                       //
//                                                                           //
// The duplicated points (marked with the type DUPLICATEDVERTEX by routine   //
// "incrflipdelaunay()") are handled before starting to mesh the facet.  Let //
// p and q are duplicated, i.e., they have exactly the same coordinates, and //
// the index of p is larger than q, p is substituted by q.  In a STL mesh,   //
// duplicated points are implicitly included.                                //
//                                                                           //
// On completion, the CDT of this facet is constructed in pool 'subfaces'.   //
// Every isolated point on the facet will be set a type of FACETVERTEX.      //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::
triangulatefacet(int facetidx, list* ptlist, list* conlist, point* idx2verlist,
                 queue* flipqueue)
{
  tetgenio::facet *f;
  tetgenio::polygon *p; 
  point tstart, tend;
  int *cons, idx1, idx2;
  int end1, end2;
  int i, j;
  
  if (b->verbose > 1) {
    printf("  Triangulate facet %d.\n", facetidx);
  }

  // Get the pointer of the facet.  
  f = &in->facetlist[facetidx - 1];

  // Are there duplicated points? 
  if ((b->object == tetgenbehavior::STL) || dupverts) {
    // Loop all polygons of this facet.
    for (i = 0; i < f->numberofpolygons; i++) {
      p = &(f->polygonlist[i]);
      // Loop other vertices of this polygon.
      for (j = 0; j < p->numberofvertices; j++) {
        idx1 = p->vertexlist[j];
        tstart = idx2verlist[idx1 - in->firstnumber];
        if (pointtype(tstart) == DUPLICATEDVERTEX) {
          // Reset the index of vertex-j.
          tend = point2pt(tstart);
          idx2 = pointmark(tend);
          p->vertexlist[j] = idx2;
        }
      }
    }
  }

  // Loop all polygons of this facet, get the sets of vertices and segments.
  for (i = 0; i < f->numberofpolygons; i++) {
    p = &(f->polygonlist[i]);
    // Get the first vertex.
    end1 = p->vertexlist[0];
    if ((end1 < in->firstnumber) || 
        (end1 >= in->firstnumber + in->numberofpoints)) {
      if (!b->quiet) {
        printf("Warning:  Invalid the 1st vertex %d of polygon", end1);
        printf(" %d in facet %d.\n", i + 1, facetidx);
      }
      break; // Skip to mesh this facet.
    }
    // Save it in 'ptlist' if it didn't be added, and set its position.
    idx1 = ptlist->hasitem(&end1);
    if (idx1 == -1) {
      ptlist->append(&end1);
      idx1 = ptlist->len() - 1;
    }
    // Loop other vertices of this polygon.
    for (j = 1; j <= p->numberofvertices; j++) {
      // get a vertex.
      if (j < p->numberofvertices) {
        end2 = p->vertexlist[j];
      } else {
        end2 = p->vertexlist[0];  // Form a loop from last to first.
      }
      if ((end2 < in->firstnumber) ||
          (end2 >= in->firstnumber + in->numberofpoints)) {
        if (!b->quiet) {
          printf("Warning:  Invalid vertex %d in polygon %d", end2, i + 1);
          printf(" in facet %d.\n", facetidx);
        }
      } else {
        if (end1 != end2) {
          // 'end1' and 'end2' form a segment.  Save 'end2' in 'ptlist' if
          //   it didn't be added before.
          idx2 = ptlist->hasitem(&end2);
          if (idx2 == -1) {
            ptlist->append(&end2);
            idx2 = ptlist->len() - 1;
          }
          // Save the segment in 'conlist'.
	        cons = (int *) conlist->append(NULL);
          cons[0] = idx1;
          cons[1] = idx2;
          // Set the start for next continuous segment.
          end1 = end2;
          idx1 = idx2;
        } else {
          // It's a (degenerate) segment with identical endpoints, which
          //   represents an isolate vertex in facet.
          if (p->numberofvertices > 2) {
            // This may be an error in the input, anyway, we can continue
            //   by simply skipping this segment.
            if (!b->quiet) {
              printf("Warning:  Polygon %d has two identical vertices", i + 1);
              printf(" in facet %d.\n", facetidx);
            }
          } 
          // Ignore this vertex.
        } 
      }
      if (p->numberofvertices == 2) {
        // This case the polygon is either a segment or an isolated vertex.
        break;  
      }
    } 
  } 

  // Have got the vertex list and segment list.
  if (b->verbose > 1) {
    printf("    %d vertices, %d segments", ptlist->len(), conlist->len());
    if (f->numberofholes > 0) {
      printf(", %d holes", f->numberofholes);
    }
    printf(".\n");
  }

  if (ptlist->len() > 2) {
    // Construct an initial triangulation.
    if (incrflipinitsub(facetidx, ptlist, idx2verlist)) {
      if (ptlist->len() > 3) {
        // Create the Delaunay triangulation of 'ptlist'.
        incrflipdelaunaysub(facetidx, ptlist, idx2verlist, flipqueue);
      }
      // Insert segments (in 'conlist') into the Delaunay triangulation.
      for (i = 0; i < conlist->len(); i++) {
        cons = (int *)(* conlist)[i];
        idx1 = * (int *)(* ptlist)[cons[0]];
        tstart = idx2verlist[idx1 - in->firstnumber];
        idx2 = * (int *)(* ptlist)[cons[1]];
        tend = idx2verlist[idx2 - in->firstnumber];
        insertsegmentsub(tstart, tend);        
      }
      if (ptlist->len() > 3 && conlist->len() > 3) {
        // Carve holes and concavities.
        carveholessub(f->numberofholes, f->holelist);
      }
    }
  }

  // Clear working lists.
  ptlist->clear();
  conlist->clear();
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// unifysegments()    Unify identical segments and build facet connections.  //
//                                                                           //
// After creating the surface mesh. Each facet has its own segments.  There  //
// are duplicated segments between adjacent facets.  This routine has three  //
// purposes:                                                                 //
//   (1) identify the set of segments which have the same endpoints and      //
//       unify them into one segment, remove redundant ones;                 //
//   (2) create the face rings of the unified segments, hence setup the      //
//       connections between facets; and                                     //
//   (3) set a unique marker (1-based) for each segment.                     //
// On finish, each segment is unique and the face ring around it (right-hand //
// rule) is constructed. The connections between facets-facets are setup.    //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::unifysegments()
{
  list *sfacelist;
  shellface **facesperverlist;
  face subsegloop, testseg;
  face sface, sface1, sface2;
  point torg, tdest;
  REAL da1, da2;
  int *idx2facelist;
  int segmarker;
  int idx, k, m;

  if (b->verbose) {
    printf("  Unifying segments.\n");
  }

  // Compute a mapping from indices of vertices to subfaces.
  makesubfacemap(idx2facelist, facesperverlist);
  // Initialize 'sfacelist' for constructing the face link of each segment.
  sfacelist = new list(sizeof(face), NULL); 
  
  segmarker = 1;
  subsegs->traversalinit();
  subsegloop.sh = shellfacetraverse(subsegs);
  while (subsegloop.sh != (shellface *) NULL) {
    subsegloop.shver = 0; // For sure.
    torg = sorg(subsegloop);
    tdest = sdest(subsegloop);
    idx = pointmark(torg) - in->firstnumber;
    // Loop through the set of subfaces containing 'torg'.  Get all the
    //   subfaces containing the edge (torg, tdest). Save and order them
    //   in 'sfacelist', the ordering is defined by the right-hand rule
    //   with thumb points from torg to tdest.
    for (k = idx2facelist[idx]; k < idx2facelist[idx + 1]; k++) {
      sface.sh = facesperverlist[k];
      sface.shver = 0;
      // sface may be died due to the removing of duplicated subfaces.
      if (!isdead(&sface) && isfacehasedge(&sface, torg, tdest)) {
        // 'sface' contains this segment.
        findedge(&sface, torg, tdest);
        // Save it in 'sfacelist'.
        if (sfacelist->len() < 2) {
          sfacelist->append(&sface);
        } else {
          for (m = 0; m < sfacelist->len() - 1; m++) {
            sface1 = * (face *)(* sfacelist)[m];
            sface2 = * (face *)(* sfacelist)[m + 1];
            da1 = facedihedral(torg, tdest, sapex(sface1), sapex(sface));
            da2 = facedihedral(torg, tdest, sapex(sface1), sapex(sface2));
            if (da1 < da2) {
              break;  // Insert it after m.
            }
          }
          sfacelist->insert(m + 1, &sface);
        }
      }
    }
    if (b->verbose > 1) {
      printf("    Identifying %d segments of (%d  %d).\n", sfacelist->len(),
             pointmark(torg), pointmark(tdest));
    }
    // Set the connection between this segment and faces containing it,
    //   at the same time, remove redundant segments.
    for (k = 0; k < sfacelist->len(); k++) {
      sface = *(face *)(* sfacelist)[k];
      sspivot(sface, testseg);
      // If 'testseg' is not 'subsegloop', it is a redundant segment that
      //   needs be removed. BE CAREFUL it may already be removed. Do not
      //   remove it twice, i.e., do test 'isdead()' together.
      if ((testseg.sh != subsegloop.sh) && !isdead(&testseg)) {
        shellfacedealloc(subsegs, testseg.sh);
      }
      // 'ssbond' bonds the subface and the segment together, and dissloves
      //   the old bond as well.
      ssbond(sface, subsegloop);
    }
    // Set connection between these faces.
    sface = *(face *)(* sfacelist)[0];
    for (k = 1; k <= sfacelist->len(); k++) {
      if (k < sfacelist->len()) {
        sface1 = *(face *)(* sfacelist)[k];
      } else {
        sface1 = *(face *)(* sfacelist)[0];    // Form a face loop.
      }
      /*
      // Check if these two subfaces are the same. It is possible when user
      //   defines one facet (or polygon) two or more times. If they are,
      //   they should not be bonded together, instead of that, one of them
      //   should be delete from the surface mesh.
      if ((sfacelist->len() > 1) && sapex(sface) == sapex(sface1)) {
        // They are duplicated faces.
        if (b->verbose) {
          printf("  A duplicated subface (%d, %d, %d) is removed.\n",
                 pointmark(torg), pointmark(tdest), pointmark(sapex(sface)));
        }
        if (k == sfacelist->len()) {
          // 'sface' is the last face, however, it is same as the first one.
          //   In order to form the ring, we have to let the second last
          //   face bond to the first one 'sface1'.
          shellfacedealloc(subfaces, sface.sh);
          assert(sfacelist->len() >= 2);
          assert(k == sfacelist->len());
          sface = *(face *)(* sfacelist)[k - 2];
        } else {
          // 'sface1' is in the middle and may be the last one. 
          shellfacedealloc(subfaces, sface1.sh);
          // Skip this face and go to the next one.
          continue;
        }
      }
      */ 
      if (b->verbose > 2) {
        printf("    Bond subfaces (%d, %d, %d) and (%d, %d, %d).\n",
               pointmark(torg), pointmark(tdest), pointmark(sapex(sface)),
               pointmark(torg), pointmark(tdest), pointmark(sapex(sface1)));
      }
      sbond1(sface, sface1);
      sface = sface1;
    }
    // Set the unique segment marker into the unified segment.
    setshellmark(subsegloop, segmarker);
    // Increase the marker.
    segmarker++;
    // Clear the working list.
    sfacelist->clear(); 
    subsegloop.sh = shellfacetraverse(subsegs);
  }

  delete [] idx2facelist;
  delete [] facesperverlist;
  delete sfacelist;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// mergefacets()    Merge adjacent facets to be one facet if they are        //
//                  coplanar and have the same boundary marker.              //
//                                                                           //
// Segments between two merged facets will be removed from the mesh.  If all //
// segments around a vertex have been removed, change its vertex type to be  //
// FACETVERTEX. Edge flips will be performed to ensure the Delaunay criteria //
// of the triangulation of merged facets.                                    //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::mergefacets(queue* flipqueue)
{
  face parentsh, neighsh, neineighsh;
  face segloop;
  point eorg, edest;
  REAL ori;
  bool mergeflag, pbcflag;
  int* segspernodelist;
  int fidx1, fidx2;
  int i, j;

  if (b->verbose) {
    printf("  Merging coplanar facets.\n");
  }
  // Create and initialize 'segspernodelist'.
  segspernodelist = new int[points->items + 1];
  for (i = 0; i < points->items + 1; i++) {
    segspernodelist[i] = 0;
  }

  // Loop the segments, counter the number of segments sharing each vertex.
  subsegs->traversalinit();
  segloop.sh = shellfacetraverse(subsegs);
  while (segloop.sh != (shellface *) NULL) {
    // Increment the number of sharing segments for each endpoint.
    for (i = 0; i < 2; i++) {
      j = pointmark((point) segloop.sh[3 + i]);
      segspernodelist[j]++;
    }
    segloop.sh = shellfacetraverse(subsegs);
  }

  // Loop the segments, find out dead segments.
  subsegs->traversalinit();
  segloop.sh = shellfacetraverse(subsegs);
  while (segloop.sh != (shellface *) NULL) {
    eorg = sorg(segloop);
    edest = sdest(segloop);
    spivot(segloop, parentsh);
    spivot(parentsh, neighsh);
    spivot(neighsh, neineighsh);
    if (parentsh.sh != neighsh.sh && parentsh.sh == neineighsh.sh) {
      // Exactly two subfaces at this segment.
      fidx1 = shellmark(parentsh) - 1;
      fidx2 = shellmark(neighsh) - 1;
      pbcflag = false;
      if (checkpbcs) {
        pbcflag = (shellpbcgroup(parentsh) >= 0)
          || (shellpbcgroup(neighsh) >= 0);
      }
      // Possibly merge them if they are not in the same facet.
      if ((fidx1 != fidx2) && !pbcflag) {
        // Test if they are coplanar.
        ori = orient3d(eorg, edest, sapex(parentsh), sapex(neighsh));
        if (ori != 0.0) {
          if (iscoplanar(eorg, edest, sapex(parentsh), sapex(neighsh), ori,
                         b->epsilon)) {
            ori = 0.0; // They are assumed as coplanar.
          }
        }
        if (ori == 0.0) {
          mergeflag = (in->facetmarkerlist == (int *) NULL || 
          in->facetmarkerlist[fidx1] == in->facetmarkerlist[fidx2]);
          if (mergeflag) {
            // This segment becomes dead.
            if (b->verbose > 1) {
              printf("  Removing segment (%d, %d).\n", pointmark(eorg),
                     pointmark(edest));
            }
            ssdissolve(parentsh);
            ssdissolve(neighsh);
            shellfacedealloc(subsegs, segloop.sh);
            j = pointmark(eorg);
            segspernodelist[j]--;
            if (segspernodelist[j] == 0) {
              setpointtype(eorg, FACETVERTEX);
            }
            j = pointmark(edest);
            segspernodelist[j]--;
            if (segspernodelist[j] == 0) {
              setpointtype(edest, FACETVERTEX);
            }
            // Add 'parentsh' to queue checking for flip.
            enqueueflipedge(parentsh, flipqueue);
          }
        }
      }
    }
    segloop.sh = shellfacetraverse(subsegs);
  }

  if (!flipqueue->empty()) {
    // Restore the Delaunay property in the facet triangulation.
    flipsub(flipqueue);
  }

  delete [] segspernodelist;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// assignvarconstraints()    Assign constraints to facets, segs, and nodes.  //
//                                                                           //
// The variant constraints of facets, segments and nodes are defined in file //
// 'filename.cons'. These information have been loaded in 'in'.              //
//                                                                           //
// This routine will be called in meshsurface() (when -p switch is in use),  //
// and in reconstructmesh() (when -r switch is in use).                      //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::assignvarconstraints(point *idx2verlist)
{
  face subloop, segloop;
  point p1, p2;
  REAL area;
  int fmarker, fidx;
  int end1, end2;
  int i;

  if (in->facetconstraintlist != (REAL *) NULL) {
    if (b->verbose) {
      printf("  Assigning facet constraints.\n");
    }
    for (i = 0; i < in->numberoffacetconstraints; i++) {
      fmarker = (int) in->facetconstraintlist[i * 2];
      area = in->facetconstraintlist[i * 2 + 1];
      // Assign 'area' to all subfaces which having 'fmarker'.
      subfaces->traversalinit();
      subloop.sh = shellfacetraverse(subfaces);
      while (subloop.sh != (shellface *) NULL) {
        fidx = shellmark(subloop) - 1;
        if (in->facetmarkerlist[fidx] == fmarker) {
          setareabound(subloop, area);
        }
        subloop.sh = shellfacetraverse(subfaces);
      }
    }
  }

  if (in->segmentconstraintlist != (REAL *) NULL) {
    if (b->verbose) {
      printf("  Assigning segment constraints.\n");
    }
    for (i = 0; i < in->numberofsegmentconstraints; i++) {
      end1 = (int) in->segmentconstraintlist[i * 3];
      end2 = (int) in->segmentconstraintlist[i * 3 + 1];
      area = in->segmentconstraintlist[i * 3 + 2];
      // Assign 'area' to segment has (end1, end2).
      subsegs->traversalinit();
      segloop.sh = shellfacetraverse(subsegs);
      while (segloop.sh != (shellface *) NULL) {
	p1 = (point) segloop.sh[3];
        p2 = (point) segloop.sh[4];
        if (((pointmark(p1) == end1) && (pointmark(p2) == end2)) ||
            ((pointmark(p1) == end2) && (pointmark(p2) == end1))) {
          setareabound(segloop, area);
          break;
        }
        segloop.sh = shellfacetraverse(subsegs);
      }
    }
  }

  if (in->nodeconstraintlist != (REAL *) NULL) {
    if (b->verbose) {
      printf("  Assigning node constraints.\n");
    }
    for (i = 0; i < in->numberofnodeconstraints; i++) {
      end1 = (int) in->nodeconstraintlist[i * 2];
      area = in->nodeconstraintlist[i * 2 + 1];
      end1 -= in->firstnumber;
      if ((end1 >= 0) && (end1 < in->numberofpoints)) {
        p1 = idx2verlist[end1];
        setedgebound(p1, area);
      }
    }
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// meshsurface()    Create the surface mesh of a PLC.                        //
//                                                                           //
// The surface mesh of a PLC X is a triangulation consists of subfaces and   //
// segments. Subfaces are 2-dimensional constrained Delaunay triangulations  //
// of the facets of X, segments are edges bounded the facets.                //
//                                                                           //
// Subfaces of each facet are connecting each other. Each segment contains a //
// ring of subfaces which saves the connection between facets sharing at it. //
//                                                                           //
// This routine first creates the CDTs of facets separatly, i.e., each facet //
// will be meshed into a set of subfaces and segments. As a result, subfaces //
// only have connections to subfaces which are belong to the same facet. And //
// segments are over-created. Routine unifysegment() is called to remove the //
// redundant segments and create the subface ring around segments.           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

long tetgenmesh::meshsurface()
{
  list *ptlist, *conlist;
  queue *flipqueue;
  point *idx2verlist;
  int i;

  if (!b->quiet) {
    printf("Creating surface mesh.\n");
  }

  // Compute a mapping from indices to points.
  makeindex2pointmap(idx2verlist);
  // Initialize 'flipqueue'.
  flipqueue = new queue(sizeof(badface));
  // Two re-useable lists 'ptlist' and 'conlist'.
  ptlist = new list("int");
  conlist = new list(sizeof(int) * 2, NULL);
  // Initialize 'liftpointarray'.
  liftpointarray = new REAL[in->numberoffacets * 3];
  
  if (checkpbcs) {
    // Create the 'subpbcgrouptable'.
    createsubpbcgrouptable();
  }

  // Loop the facet list, triangulate each facet. On finish, all subfaces
  //   are in 'subfaces', all segments are in 'subsegs' (Note: there exist
  //   duplicated segments).
  for (i = 0; i < in->numberoffacets; i++) {
    triangulatefacet(i + 1, ptlist, conlist, idx2verlist, flipqueue);
  }

  // Unify segments in 'subsegs', remove redundant segments.  Face links
  //   of segments are also built.
  unifysegments();

  if (checkpbcs) {
    // Create the 'segpbcgrouptable'.
    createsegpbcgrouptable();
  }

  if (b->object == tetgenbehavior::STL) {
    // Remove redundant vertices (for .stl input mesh).
    jettisonnodes();
  }

  if (!b->nomerge) {
    // Merge adjacent facets if they are coplanar.
    mergefacets(flipqueue);
  }

  if (b->quality && varconstraint) {
    // Assign constraints on facets, segments, and nodes.
    assignvarconstraints(idx2verlist);
  }

  delete [] idx2verlist;
  delete flipqueue;
  delete conlist;
  delete ptlist;

  return subsegs->items;
}

//
// End of surface triangulation routines
//

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// interecursive()    Recursively do intersection test on a set of triangles.//
//                                                                           //
// Recursively split the set 'subfacearray' of subfaces into two sets using  //
// a cut plane parallel to x-, or, y-, or z-axies.  The split criteria are   //
// follows. Assume the cut plane is H, and H+ denotes the left halfspace of  //
// H, and H- denotes the right halfspace of H; and s be a subface:           //
//                                                                           //
//    (1) If all points of s lie at H+, put it into left array;              //
//    (2) If all points of s lie at H-, put it into right array;             //
//    (3) If some points of s lie at H+ and some of lie at H-, or some       //
//        points lie on H, put it into both arraies.                         //
//                                                                           //
// Partitions by x-axis if axis == '0'; by y-axis if axis == '1'; by z-axis  //
// if axis == '2'. If current cut plane is parallel to the x-axis, the next  //
// one will be parallel to y-axis, and the next one after the next is z-axis,//
// and then alternately return back to x-axis.                               //
//                                                                           //
// Stop splitting when the number of triangles of the input array is not     //
// decreased anymore. Do tests on the current set.                           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::
interecursive(shellface** subfacearray, int arraysize, int axis, REAL bxmin,
              REAL bxmax, REAL bymin, REAL bymax, REAL bzmin, REAL bzmax,
              int* internum)
{
  shellface **leftarray, **rightarray;
  face sface1, sface2;
  point p1, p2, p3;
  point p4, p5, p6;
  enum interresult intersect;
  REAL split;
  bool toleft, toright;
  int leftsize, rightsize;
  int i, j;

  if (b->verbose > 1) {
    printf("  Recur %d faces. Bbox (%g, %g, %g),(%g, %g, %g). %s-axis\n",
           arraysize, bxmin, bymin, bzmin, bxmax, bymax, bzmax,
           axis == 0 ? "x" : (axis == 1 ? "y" : "z"));
  }
    
  leftarray = new shellface*[arraysize];
  if (leftarray == NULL) {
    printf("Error in interecursive():  Insufficient memory.\n");
    exit(1);
  }
  rightarray = new shellface*[arraysize];
  if (rightarray == NULL) {
    printf("Error in interecursive():  Insufficient memory.\n");
    exit(1);
  }
  leftsize = rightsize = 0;

  if (axis == 0) {
    // Split along x-axis.
    split = 0.5 * (bxmin + bxmax);
  } else if (axis == 1) {
    // Split along y-axis.
    split = 0.5 * (bymin + bymax);
  } else {
    // Split along z-axis.
    split = 0.5 * (bzmin + bzmax);
  }

  for (i = 0; i < arraysize; i++) {
    sface1.sh = subfacearray[i];
    p1 = (point) sface1.sh[3];
    p2 = (point) sface1.sh[4];
    p3 = (point) sface1.sh[5];
    toleft = toright = false;
    if (p1[axis] < split) {
      toleft = true;
      if (p2[axis] >= split || p3[axis] >= split) {
        toright = true;
      } 
    } else if (p1[axis] > split) {
      toright = true;
      if (p2[axis] <= split || p3[axis] <= split) {
        toleft = true;
      } 
    } else {
      // p1[axis] == split;
      toleft = true;
      toright = true;
    }
    // At least one is true;
    assert(!(toleft == false && toright == false));
    if (toleft) {
      leftarray[leftsize] = sface1.sh;
      leftsize++;
    }
    if (toright) {
      rightarray[rightsize] = sface1.sh;
      rightsize++;
    }
  }

  if (leftsize < arraysize && rightsize < arraysize) {
    // Continue to partition the input set. Now 'subfacearray' has been
    //   split into two sets, it's memory can be freed. 'leftarray' and
    //   'rightarray' will be freed in the next recursive (after they're
    //   partitioned again or performing tests).
    delete [] subfacearray;
    // Continue to split these two sets.
    if (axis == 0) {
      interecursive(leftarray, leftsize, 1, bxmin, split, bymin, bymax,
                    bzmin, bzmax, internum);
      interecursive(rightarray, rightsize, 1, split, bxmax, bymin, bymax,
                    bzmin, bzmax, internum);
    } else if (axis == 1) {
      interecursive(leftarray, leftsize, 2, bxmin, bxmax, bymin, split,
                    bzmin, bzmax, internum);
      interecursive(rightarray, rightsize, 2, bxmin, bxmax, split, bymax,
                    bzmin, bzmax, internum);
    } else {
      interecursive(leftarray, leftsize, 0, bxmin, bxmax, bymin, bymax,
                    bzmin, split, internum);
      interecursive(rightarray, rightsize, 0, bxmin, bxmax, bymin, bymax,
                    split, bzmax, internum);
    }
  } else {
    if (b->verbose > 1) {
      printf("  Checking intersecting faces.\n");
    }
    // Perform a brute-force compare on the set.
    for (i = 0; i < arraysize; i++) {
      sface1.sh = subfacearray[i];
      p1 = (point) sface1.sh[3];
      p2 = (point) sface1.sh[4];
      p3 = (point) sface1.sh[5];
      for (j = i + 1; j < arraysize; j++) {
        sface2.sh = subfacearray[j];
        p4 = (point) sface2.sh[3];
        p5 = (point) sface2.sh[4];
        p6 = (point) sface2.sh[5];
        intersect = tri_tri_inter(p1, p2, p3, p4, p5, p6);
        if (intersect == INTERSECT || intersect == SHAREFACE) {
          if (!b->quiet) {
            if (intersect == INTERSECT) {
              printf("  Facet #%d intersects facet #%d at triangles:\n",
                     shellmark(sface1), shellmark(sface2));
              printf("    (%4d, %4d, %4d) and (%4d, %4d, %4d)\n",
                     pointmark(p1), pointmark(p2), pointmark(p3),
                     pointmark(p4), pointmark(p5), pointmark(p6));
            } else {
              printf("  Facet #%d duplicates facet #%d at triangle:\n",
                     shellmark(sface1), shellmark(sface2));
              printf("    (%4d, %4d, %4d)\n", pointmark(p1), pointmark(p2),
                     pointmark(p3));
            }
          }
          // Increase the number of intersecting pairs.
          (*internum)++; 
          // Infect these two faces (although they may already be infected).
          sinfect(sface1);
          sinfect(sface2);
        }
      }
    }
    // Don't forget to free all three arrays. No further partition.
    delete [] leftarray;
    delete [] rightarray;  
    delete [] subfacearray;
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// detectinterfaces()    Detect intersecting triangles.                      //
//                                                                           //
// Given a set of triangles,  find the pairs of intersecting triangles from  //
// them.  Here the set of triangles is in 'subfaces' which is a surface mesh //
// of a PLC (.poly or .smesh).                                               //
//                                                                           //
// To detect whether two triangles are intersecting is done by the routine   //
// 'tri_tri_inter()'.  The algorithm for the test is very simple and stable. //
// It is based on geometric orientation test which uses exact arithmetics.   //
//                                                                           //
// Use divide-and-conquer algorithm for reducing the number of intersection  //
// tests.  Start from the bounding box of the input point set, recursively   //
// partition the box into smaller boxes, until the number of triangles in a  //
// box is not decreased anymore. Then perform triangle-triangle tests on the //
// remaining set of triangles.  The memory allocated in the input set is     //
// freed immediately after it has been partitioned into two arrays.  So it   //
// can be re-used for the consequent partitions.                             //
//                                                                           //
// On return, the pool 'subfaces' will be cleared, and only the intersecting //
// triangles remain for output (to a .face file).                            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::detectinterfaces()
{
  shellface **subfacearray;
  face shloop;
  int internum;
  int i;

  if (!b->quiet) {
    printf("Detecting intersecting facets.\n");
  }

  // Construct a map from indices to subfaces;
  subfacearray = new shellface*[subfaces->items];
  subfaces->traversalinit();
  shloop.sh = shellfacetraverse(subfaces);
  i = 0;
  while (shloop.sh != (shellface *) NULL) {
    subfacearray[i] = shloop.sh;
    shloop.sh = shellfacetraverse(subfaces);
    i++;
  }

  internum = 0;
  // Recursively split the set of triangles into two sets using a cut plane
  //   parallel to x-, or, y-, or z-axies.  Stop splitting when the number
  //   of subfaces is not decreasing anymore. Do tests on the current set.
  interecursive(subfacearray, subfaces->items, 0, xmin, xmax, ymin, ymax,
                zmin, zmax, &internum);

  if (!b->quiet) {
    if (internum > 0) {
      printf("\n!! Found %d pairs of faces are intersecting.\n\n", internum);
    } else {
      printf("\nNo faces are intersecting.\n\n");
    }
  }

  if (internum > 0) {
    // Traverse all subfaces, deallocate those have not been infected (they
    //   are not intersecting faces). Uninfect those have been infected.
    //   After this loop, only intersecting faces remain.
    subfaces->traversalinit();
    shloop.sh = shellfacetraverse(subfaces);
    while (shloop.sh != (shellface *) NULL) {
      if (sinfected(shloop)) {
        suninfect(shloop);
      } else {
        shellfacedealloc(subfaces, shloop.sh);
      }
      shloop.sh = shellfacetraverse(subfaces);
    }
  } else {
    // Deallocate all subfaces.
    subfaces->restart();
  }
}

//
// Begin of periodic boundary condition routines
//

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// createsubpbcgrouptable()    Create the 'subpbcgrouptable'.                //
//                                                                           //
// Allocate the memory for 'subpbcgrouptable'.  Each entry i (a pbcdata) of  //
// the table represents a pbcgroup.  Most of the fields of a group-i are set //
// in this routine. 'fmark[0]', 'fmark[1]', and 'transmat[0]' are directly   //
// copied from the corresponding data of 'in->numberofpbcgroups'. 'transmat  //
// [1]' is calculated as the inverse matrix of 'transmat[0]'.  'ss[0]' and   //
// 'ss[1]' are initilized be 'dummysh'. They are set in 'trangulatefacet()'  //
// (when -p is in use) or 'reconstructmesh()' (when -r is in use).           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::createsubpbcgrouptable()
{
  tetgenio::pbcgroup *pg;
  pbcdata *pd;
  REAL A[4][4], rhs[4], D;
  int indx[4];
  int i, j, k;

  subpbcgrouptable = new pbcdata[in->numberofpbcgroups];
  for (i = 0; i < in->numberofpbcgroups; i++) {
    pg = &(in->pbcgrouplist[i]);
    pd = &(subpbcgrouptable[i]);
    // Copy data from pg to pd.
    pd->fmark[0] = pg->fmark1;
    pd->fmark[1] = pg->fmark2;
    // Initialize array 'pd->ss'.
    pd->ss[0].sh = dummysh;
    pd->ss[1].sh = dummysh;
    // Copy the transform matrix from pg to pd->transmat[0].
    for (j = 0; j < 4; j++) {
      for (k = 0; k < 4; k++) {
        pd->transmat[0][j][k] = pg->transmat[j][k];
        // Prepare for inverting the matrix.
        A[j][k] = pg->transmat[j][k];
      }
    }
    // Calculate the inverse matrix (pd->transmat[1]) of pd->transmat[0].
    lu_decmp(A, 4, indx, &D, 0);
    for (j = 0; j < 4; j++) {
      for (k = 0; k < 4; k++) rhs[k] = 0.0;
      rhs[j] = 1.0;
      lu_solve(A, 4, indx, rhs, 0);
      for (k = 0; k < 4; k++) pd->transmat[1][k][j] = rhs[k];
    }
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// getsubpbcgroup()    Get the pbcgroup of a subface.                        //
//                                                                           //
// 'pbcsub' has pbc defined. Its pbcgroup is returned in 'pd'. In addition,  //
// 'f1' (0 or 1) indicates the position of 'pbcsub' in 'pd'; 'f2' (= 1 - f1) //
// is the position where the symmetric subface of 'pbcsub' is found.         //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::getsubpbcgroup(face* pbcsub, pbcdata** pd, int *f1, int *f2)
{
  int groupid, fmark, idx;

  groupid = shellpbcgroup(*pbcsub);
  *pd = &subpbcgrouptable[groupid];
  
  // Get the facet index (1 - based).
  idx = shellmark(*pbcsub);
  // Get the facet marker from array (0 - based).
  fmark = in->facetmarkerlist[idx - 1];
  if ((*pd)->fmark[0] == fmark) {
    *f1 = 0;
  } else {
    assert((*pd)->fmark[1] == fmark);
    *f1 = 1;
  }
  *f2 = 1 - (*f1);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// getsubpbcsympoint()    Compute the symmetric point for a subface point.   //
//                                                                           //
// 'newpoint' lies on 'splitsub'. This routine calculates a 'sympoint' which //
// locates on 'symsplitsub' and symmtric to 'newpoint'.  Return the location //
// of sympoint wrt. symsplitsub.                                             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

enum tetgenmesh::locateresult tetgenmesh::
getsubpbcsympoint(point newpoint, face* splitsub, point sympoint,
                  face* symsplitsub)
{
  pbcdata *pd;
  face subloop;
  enum locateresult symloc;
  int f1, f2, i;

  // Get the pbcgroup of 'splitsub'.
  getsubpbcgroup(splitsub, &pd, &f1, &f2);
      
  // Transform newpoint from f1 -> f2.
  for (i = 0; i < 3; i++) {
    sympoint[i] = pd->transmat[f1][i][0] * newpoint[0]
                + pd->transmat[f1][i][1] * newpoint[1]
                + pd->transmat[f1][i][2] * newpoint[2]
                + pd->transmat[f1][i][3] * 1.0;
  }
  // Locate sympoint in f2.
  symloc = OUTSIDE;
  *symsplitsub = pd->ss[f2];
  // Is the stored subface valid? Hole removal may delete the subface.  
  if ((symsplitsub->sh != dummysh) && !isdead(symsplitsub)) {
    // 'symsplitsub' should lie on the symmetric facet. Check it.
    i = shellmark(*symsplitsub);
    if (in->facetmarkerlist[i - 1] == pd->fmark[f2]) {
      // Locate sympoint in facet. Don't stop at subsegment.
      symloc = locatesub(sympoint, symsplitsub, 0);
    }
  }
  if (symloc == OUTSIDE) {
    // Locate sympoint in the pool of subfaces (with fmark pd->fmark[f2]).
    subfaces->traversalinit();
    subloop.sh = shellfacetraverse(subfaces);
    while (subloop.sh != (shellface *) NULL) {
      i = shellmark(subloop);
      if (in->facetmarkerlist[i - 1] == pd->fmark[f2]) {
        // subloop is on the facet, search sympoint.
        symloc = locatesub(sympoint, &subloop, 0);
        if (symloc != OUTSIDE) break;
      }
      subloop.sh = shellfacetraverse(subfaces);
    }
    // Set the returning subface.
    *symsplitsub = subloop;
    // Update the stored subface for next searching.
    pd->ss[f2] = *symsplitsub;
  }
  // sympoint should be inside the facet.
  assert(symloc != OUTSIDE);

  return adjustlocatesub(sympoint, symsplitsub, symloc, b->epsilon);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// createsegpbcgrouptable()    Create the 'segpbcgrouptable'.                //
//                                                                           //
// Each segment may belong to more than one pbcgroups. 'segpbcgrouptable' is //
// implemented as a list of pbcdatas. Each item i represents a pbcgroup.     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::createsegpbcgrouptable()
{
  pbcdata *pd, *pd1, *pd2;
  face segloop, symseg;
  face startsh, spinsh, symsh;
  point pa, pb;
  enum locateresult symloc;
  REAL testpt[3], sympt[3];
  bool inflag;
  int segid1, segid2;
  int f1, f2;
  int i, j, k, l;

  // Allocate memory for 'subpbcgrouptable'.
  segpbcgrouptable = new list(sizeof(pbcdata), NULL, 256);

  // Loop through the segment list.
  subsegs->traversalinit();
  segloop.sh = shellfacetraverse(subsegs);
  while (segloop.sh != (shellface *) NULL) {
    // Loop the subface ring of segloop ab.
    pa = sorg(segloop);
    pb = sdest(segloop);
    segid1 = shellmark(segloop);
    spivot(segloop, startsh);
    spinsh = startsh;
    do {
      // Adjust spinsh be edge ab.
      if (sorg(spinsh) != pa) {
        sesymself(spinsh);
      }
      // Does spinsh belong to a pbcgroup?
      if (shellpbcgroup(spinsh) != -1) {
        // Yes! There exists a segment cd. ab and cd form a pbcgroup.
        //   'testpt' is the midpoint of ab used to find cd.
        for (i = 0; i < 3; i++) testpt[i] = 0.5 * (pa[i] + pb[i]);
        symloc = getsubpbcsympoint(testpt, &spinsh, sympt, &symsh);
        assert(symloc == ONEDGE);
        sspivot(symsh, symseg);
        assert(symseg.sh != dummysh);
        // Check whether this group has already been created in list.
        segid2 = shellmark(symseg);
        inflag = false;
        for (i = 0; i < segpbcgrouptable->len() && !inflag; i++) {
          pd = (pbcdata *)(* segpbcgrouptable)[i];
          if (pd->segid[0] == segid1) {
            if (pd->segid[1] == segid2) inflag = true;
          } else if (pd->segid[0] == segid2) {
            if (pd->segid[1] == segid1) inflag = true;
          }
        }
        if (!inflag) {
          // Create a segment pbcgroup in list for ab and cd.
          pd = (pbcdata *) segpbcgrouptable->append(NULL);
          // Save the markers of ab and cd.
          pd->segid[0] = segid1;
          pd->segid[1] = segid2;
          // Save the handles of ab and cd.
          pd->ss[0] = segloop;
          pd->ss[1] = symseg;
          // Find the map from ab to cd.
          getsubpbcgroup(&spinsh, &pd1, &f1, &f2);
          pd->fmark[0] = pd1->fmark[f1];
          pd->fmark[1] = pd1->fmark[f2];
          // Set the map from ab to cd.
          for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
              pd->transmat[0][i][j] = pd1->transmat[f1][i][j];
            }
          }
          // Set the map from cd to ab.
          for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
              pd->transmat[1][i][j] = pd1->transmat[f2][i][j];
            }
          }
        }
      }
      // Go to the next subface in the ring of ab.
      spivotself(spinsh);
    } while (spinsh.sh != startsh.sh);
    segloop.sh = shellfacetraverse(subsegs);
  }

  // Create the indirect segment pbcgroups.
  for (i = 0; i < segpbcgrouptable->len(); i++) {
    pd1 = (pbcdata *)(* segpbcgrouptable)[i];
    for (f1 = 0; f1 < 2; f1++) {
      // Search for a group (except i) contains pd1->segid[f1].
      for (j = 0; j < segpbcgrouptable->len(); j++) {
        if (j == i) continue;
        pd2 = (pbcdata *)(* segpbcgrouptable)[j];
        f2 = -1;
        if (pd1->segid[f1] == pd2->segid[0]) {
          f2 = 0;
        } else if (pd1->segid[f1] == pd2->segid[1]) {
          f2 = 1;
        }
        if (f2 != -1) {
          assert(pd1->segid[f1] == pd2->segid[f2]);
          segid1 = pd1->segid[1 - f1];
          segid2 = pd2->segid[1 - f2];
          // Search for the existence of segment pbcgroup (segid1, segid2).
          inflag = false;
          for (k = 0; k < segpbcgrouptable->len() && !inflag; k++) {
            pd = (pbcdata *)(* segpbcgrouptable)[k];
            if (pd->segid[0] == segid1) {
              if (pd->segid[1] == segid2) inflag = true;
            } else if (pd->segid[0] == segid2) {
              if (pd->segid[1] == segid1) inflag = true;
            }
          }
          if (!inflag) {
            pd = (pbcdata *) segpbcgrouptable->append(NULL);
            pd->segid[0] = pd1->segid[1 - f1];
            pd->segid[1] = pd2->segid[1 - f2];
            pd->ss[0] = pd1->ss[1 - f1];
            pd->ss[1] = pd2->ss[1 - f2];
            // Invalid the fmark[0] == fmark[1].
            pd->fmark[0] = pd->fmark[1] = 0;
            // Translate matrix pd->transmat[0] = m2 * m1, where m1 =
            //   pd1->transmat[1 - f1], m2 = pd2->transmat[f2].
            for (k = 0; k < 4; k++) {
              for (l = 0; l < 4; l++) { 
                pd->transmat[0][k][l] = pd2->transmat[f2][k][l];
              }
            }
            m4xm4(pd->transmat[0], pd1->transmat[1 - f1]);
            // Translate matrix pd->transmat[1] = m4 * m3, where m3 =
            //   pd2->transmat[1 - f2], m4 = pd1->transmat[f1].
            for (k = 0; k < 4; k++) {
              for (l = 0; l < 4; l++) { 
                pd->transmat[1][k][l] = pd1->transmat[f1][k][l];
              }
            }
            m4xm4(pd->transmat[1], pd2->transmat[1 - f2]);
          }
        }
      }
    }
  }

  // Form a map from segment index to pbcgroup list of this segment.
  idx2segpglist = new int[subsegs->items + 1];
  for (i = 0; i < subsegs->items + 1; i++) idx2segpglist[i] = 0;
  // Loop through 'segpbcgrouptable', counter the number of pbcgroups of
  //   each segment.
  for (i = 0; i < segpbcgrouptable->len(); i++) {
    pd = (pbcdata *)(* segpbcgrouptable)[i];
    for (j = 0; j < 2; j++) {
      k = pd->segid[j] - 1;
      idx2segpglist[k]++;
    }
  }
  // Calculate the total length of array 'segpglist'.
  j = idx2segpglist[0];
  idx2segpglist[0] = 0;  // Array starts from 0 element.
  for (i = 0; i < subsegs->items; i++) {
    k = idx2segpglist[i + 1];
    idx2segpglist[i + 1] = idx2segpglist[i] + j;
    j = k;
  }
  // The total length is in the last unit of idx2segpglist.
  segpglist = new int[idx2segpglist[i]];
  // Loop the set of pbcgroups again, set the data into segpglist.
  for (i = 0; i < segpbcgrouptable->len(); i++) {
    pd = (pbcdata *)(* segpbcgrouptable)[i];
    for (j = 0; j < 2; j++) {
      k = pd->segid[j] - 1;
      segpglist[idx2segpglist[k]] = i;
      idx2segpglist[k]++;
    }
  }
  // Contents in 'idx2segpglist' are shifted, now shift them back.
  for (i = subsegs->items - 1; i >= 0; i--) {
    idx2segpglist[i + 1] = idx2segpglist[i];
  }
  idx2segpglist[0] = 0;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// locateseg()    Find a point in subsegments.                               //
//                                                                           //
// Searching begins from the input 'searchseg', it should be a subsegment of //
// the whole segment.                                                        //
//                                                                           //
// On completion, 'searchseg' is a subsegment that contains 'searchpt'.      //
//   - Returns ONVERTEX if the point lies on an existing vertex. 'searchseg' //
//     is a handle whose origin is the existing vertex.                      //
//   - Returns ONEDGE if the point lies inside 'searchseg'.                  //
//   - Returns OUTSIDE if the point lies outside the segment.                //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

enum tetgenmesh::locateresult tetgenmesh::
locateseg(point searchpt, face* searchseg)
{
  face backtraceseg;
  point pa, pb;
  int moveleft;
  int i;

  while (1) {
    searchseg->shver = 0;
    pa = sorg(*searchseg);
    pb = sdest(*searchseg);
    for (i = 0; i < 3; i++) {
      if (pa[i] < pb[i]) {
        if (searchpt[i] < pa[i]) {
          moveleft = 1;
          break;
        } else if (searchpt[i] > pa[i]) {
          if (searchpt[i] < pb[i]) {
            return ONEDGE;
          } else if (searchpt[i] > pb[i]) {
            moveleft = 0;
            break;
          } else {
            assert(searchpt[i] == pb[i]);
            sesymself(*searchseg);
            return ONVERTEX;
          }
        } else {
          assert(searchpt[i] == pa[i]);
          return ONVERTEX;
        }
      } else if (pa[i] > pb[i]) {
        if (searchpt[i] < pb[i]) {
          moveleft = 0;
          break;
        } else if (searchpt[i] > pb[i]) {
          if (searchpt[i] < pa[i]) {
            return ONEDGE;
          } else if (searchpt[i] > pa[i]) {
            moveleft = 1;
            break;
          } else {
            assert(searchpt[i] == pa[i]);
            return ONVERTEX;
          }
        } else {
          assert(searchpt[i] == pb[i]);
          sesymself(*searchseg);
          return ONVERTEX;
        }
      }
    }
    assert(i < 3);
    backtraceseg = *searchseg;
    if (moveleft) {
      senext2self(*searchseg);
    } else {
      senextself(*searchseg);
    }
    spivotself(*searchseg);
    if (searchseg->sh == dummysh) {
      *searchseg = backtraceseg;
      break;
    }
  }

  return OUTSIDE;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// adjustlocateseg()    Adjust the precise location of a vertex on segment.  //
//                                                                           //
// 'searchpt' is either inside or ouside the segment 'searchseg'. It will be //
// adjusted to on vertex if it is very close to an endpoint of 'searchseg'.  //
// 'epspp' is the given relative tolerance.                                  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

enum tetgenmesh::locateresult tetgenmesh::
adjustlocateseg(point searchpt, face* searchseg, enum locateresult precise,
                REAL epspp)
{
  point pa, pb;
  REAL L, d, r;

  pa = sorg(*searchseg);
  pb = sdest(*searchseg);
  L = distance(pa, pb);

  // Is searchpt approximate to pa?
  d = distance(pa, searchpt);
  r = d / L;
  if (r <= epspp) {
    return ONVERTEX;
  }
  // Is searchpt approximate to pb?
  d = distance(pb, searchpt);
  r = d / L;
  if (r <= epspp) {
    sesymself(*searchseg);
    return ONVERTEX;
  }

  return precise;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// getsegpbcsympoint()    Compute the symmetric point for a segment point.   //
//                                                                           //
// 'newpoint' lies on 'splitseg'. This routine calculates a 'sympoint' which //
// locates on 'symsplitseg' and symmtric to 'newpoint'.  Return the location //
// of sympoint wrt. symsplitseg.                                             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

enum tetgenmesh::locateresult tetgenmesh::
getsegpbcsympoint(point newpoint, face* splitseg, point sympoint,
                  face* symsplitseg, int groupid)
{
  pbcdata *pd;
  enum locateresult symloc;
  int segid, f1, f2, i;

  pd = (pbcdata *)(* segpbcgrouptable)[groupid];
  segid = shellmark(*splitseg);
  if (pd->segid[0] == segid) {
    f1 = 0;
  } else {
    assert(pd->segid[1] == segid);
    f1 = 1;
  }
  f2 = 1 - f1;

  // Transform newpoint from f1 -> f2.
  for (i = 0; i < 3; i++) {
    sympoint[i] = pd->transmat[f1][i][0] * newpoint[0]
                + pd->transmat[f1][i][1] * newpoint[1]
                + pd->transmat[f1][i][2] * newpoint[2]
                + pd->transmat[f1][i][3] * 1.0;
  }
  // Locate sympoint in f2.
  *symsplitseg = pd->ss[f2];
  assert(symsplitseg->sh != dummysh);
  // Locate sympoint in facet. Stop at subsegment.
  symloc = locateseg(sympoint, symsplitseg);

  return adjustlocateseg(sympoint, symsplitseg, symloc, b->epsilon);
}

//
// End of periodic boundary condition routines
//

//
// Begin of vertex perturbation routines
//

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// randgenerator()    Generate a random REAL number between (0, |range|).    //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

REAL tetgenmesh::randgenerator(REAL range)
{
  REAL worknumber, result;
  int expo;

  if (range == 0.0) return 0.0;

  expo = 0;
  worknumber = fabs(range);
  // Normalize worknumber (i.e., 1.xxxExx)
  if (worknumber > 10.0) {
    while (worknumber > 10.0) {
      worknumber /= 10.0;
      expo++;
    }
  } else if (worknumber < 1.0) {
    while (worknumber < 1.0) {
      worknumber *= 10.0;
      expo--;
    }
  }
  assert(worknumber >= 1.0 && worknumber <= 10.0);

  // Enlarge worknumber 1000 times.
  worknumber *= 1e+3;
  expo -= 3;
  // Generate a randome number between (0, worknumber).
  result = (double) randomnation((int) worknumber);
  
  // Scale result back into the original size.
  if (expo > 0) {
    while (expo != 0) {
      result *= 10.0;
      expo--;
    }
  } else if (expo < 0) {
    while (expo != 0) {
      result /= 10.0;
      expo++;
    }
  }
  assert((result >= 0.0) && (result <= fabs(range)));

  return result;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// checksub4cocir()    Test a subface to find co-circular pair of subfaces.  //
//                                                                           //
// 'eps' is a relative tolerance for testing approximately cospherical case. //
// Set it to zero if only exact test is desired.                             //
//                                                                           //
// An edge(not a segment) of 'testsub' is locally degenerate if the opposite //
// vertex of the adjacent subface is cocircular with the vertices of testsub.//
// If 'once' is TRUE, operate on the edge only if the pointer 'testsub->sh'  //
// is smaller than its neighbor (for each edge is considered only once).     //
//                                                                           //
// Return TRUE if find an edge of testsub is locally degenerate.             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenmesh::
checksub4cocir(face* testsub, REAL eps, bool once, bool enqflag)
{
  badface *cocirsub;
  face subloop, neighsub;
  face checkseg;
  point pa, pb, pc, pd;
  point liftpt;
  REAL sign;
  int i;
  
  subloop = *testsub;
  // Get the liftpoint.
  liftpt = getliftpoint(shellmark(subloop));
  subloop.shver = 0; // Keep the CCW orientation.
  // Check the three edges of subloop.
  for (i = 0; i < 3; i++) {
    sspivot(subloop, checkseg);
    if (checkseg.sh == dummysh) {
      // It is not a segment, get the adjacent subface.
      spivot(subloop, neighsub);
      assert(neighsub.sh != dummysh);
      if (!once || (once && (neighsub.sh > subloop.sh))) {
        pa = sorg(subloop);
        pb = sdest(subloop);
        pc = sapex(subloop);
        pd = sapex(neighsub);
        sign = insphere(pa, pb, pc, liftpt, pd);
        if ((sign != 0.0) && (eps > 0.0)) {
          if (iscospheric(pa, pb, pc, liftpt, pd, sign, eps)) sign = 0.0;
        }
        if (sign == 0.0) {
          // It's locally degenerate!
          if (enqflag && badsubfaces != (memorypool *) NULL) {
            // Save it.
            cocirsub = (badface *) badsubfaces->alloc();
            cocirsub->ss = subloop;
            cocirsub->forg = pa;
            cocirsub->fdest = pb;
            cocirsub->fapex = pc;
            cocirsub->foppo = pd;
            setshell2badface(cocirsub->ss, cocirsub);
          }
          if (b->verbose > 1) {
            printf("    Found set (%d, %d, %d, %d).\n", pointmark(pa),
                   pointmark(pb), pointmark(pc), pointmark(pd));
          }
          return true;
        }
      }
    }
    senextself(subloop);
  }

  return false;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// checktet4cosph()    Test a tetrahedron to find co-spherical pair of tets. //
//                                                                           //
// 'eps' is a relative tolerance for testing approximately cospherical case. //
// Set it to zero if only exact test is desired.                             //
//                                                                           //
// A face of 'testtet' is locally degenerate if the opposite vertex of the   //
// adjacent tetrahedron is co-sphere with the vertices of testtet. If 'once' //
// is TRUE operate on the face only if the pointer 'testtet->tet' is smaller //
// than its neighbor (for each face is considered only once).                //
//                                                                           //
// Return TRUE if find a face of testtet is locally degenerate.              //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenmesh::
checktet4cosph(triface* testtet, REAL eps, bool once, bool enqflag)
{
  badface *cosphtet;
  triface tetloop, neightet;
  point pa, pb, pc, pd, pe;
  REAL sign;

  tetloop = *testtet;
  tetloop.ver = 0; // Keep the CCW orientation in each face.
  for (tetloop.loc = 0; tetloop.loc < 4; tetloop.loc++) {
    sym(tetloop, neightet);
    if (neightet.tet != dummytet) {
      // It is not a hull face.
      if (!once || (once && (tetloop.tet < neightet.tet))) {
        pa = org(tetloop);
        pb = dest(tetloop);
        pc = apex(tetloop);
        pd = oppo(tetloop);
        pe = oppo(neightet);
        sign = insphere(pa, pb, pc, pd, pe);
        // Approximate sign.
        if (eps > 0.0) {
          if (iscospheric(pa, pb, pc, pd, pe, sign, eps)) sign = 0.0;
        }
        if (sign == 0.0) {
          // It's degenerate!
          if (enqflag && (badtetrahedrons != (memorypool *) NULL)) {
            cosphtet = (badface *) badtetrahedrons->alloc();
            cosphtet->tt = tetloop;
            cosphtet->forg = pa;
            cosphtet->fdest = pb;
            cosphtet->fapex = pc;
            cosphtet->foppo = pd;
            cosphtet->noppo = pe;
          }
          if (b->verbose > 1) {
            printf("    Found set (%d, %d, %d, %d, %d).\n", pointmark(pa),
                   pointmark(pb), pointmark(pc), pointmark(pd), pointmark(pe));
          }
          return true;
        }
      }
    }
  }

  return false;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// tallcocirsubs()    Find all co-circular subfaces and save them in list.   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::tallcocirsubs(REAL eps, bool enqflag)
{
  face subloop;

  // Loop over all subfaces.
  subfaces->traversalinit();
  subloop.sh = shellfacetraverse(subfaces);
  while (subloop.sh != (shellface *) NULL) {
    checksub4cocir(&subloop, eps, true, enqflag);
    subloop.sh = shellfacetraverse(subfaces);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// tallcosphtets()    Find all co-spherical tets and save them in list.      //
//                                                                           //
// If 'testtetlist' is not NULL, only test the tetrahedra saved in the list. //
// Otherwise, test all tetrahedra of current mesh.                           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::tallcosphtets(list* testtetlist, REAL eps, bool enqflag)
{
  triface tetloop;
  int i;

  if (testtetlist != (list *) NULL) {
    for (i = 0; i < testtetlist->len(); i++) {
      tetloop = * (triface *)(* testtetlist)[i];
      checktet4cosph(&tetloop, eps, false, enqflag);
    }
  } else {
    tetrahedrons->traversalinit();
    tetloop.tet = tetrahedrontraverse();
    while (tetloop.tet != (tetrahedron *) NULL) {
      checktet4cosph(&tetloop, eps, true, enqflag);
      tetloop.tet = tetrahedrontraverse();
    }
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// tallencsegsfsubs()    Check for encroached segs from a list of subfaces.  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenmesh::tallencsegsfsubs(point testpt, list* cavsublist)
{
  face startsub, checkseg;
  long oldencnum;
  int i, j;

  // Remember the current number of encroached segments.
  oldencnum = badsubsegs->items;

  // Check segments in the list of subfaces.
  for (i = 0; i < cavsublist->len(); i++) {
    startsub = * (face *)(* cavsublist)[i];
    // Test all three edges of startsub.
    for (j = 0; j < 3; j++) {
      sspivot(startsub, checkseg);
      if (checkseg.sh != dummysh) {
        if (!shell2badface(checkseg)) {
          checkseg4encroach(&checkseg, testpt, NULL, true);
        }
      }
      senextself(startsub);
    }
  }

  return (badsubsegs->items > oldencnum);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// tallencsubsfsubs()    Check for encroached subs from a list of subfaces.  //
//                                                                           //
// 'cavtetlist' is a list of tetrahedra whose circumspheres include 'testpt'.//
// By the time this routine is called, there is still no connection between  //
// tetrahedra and subfaces.  We have to find out the subfaces related to the //
// list of tetrahedra. Here the trick is to mark all vertices of the tets,   //
// then loop in the pool of subfaces, for each subface, only do test if at   //
// least one of its three vertices are marked.                               //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenmesh::tallencsubsfsubs(point testpt, list* cavtetlist)
{
  triface *cavtet;
  face checksh;
  point pt;
  long oldencnum;
  int *worklist;
  int mcount;
  int i, j;

  // Initialize a worklist for vertices markers.
  worklist = new int[points->items + 1];
  for (i = 0; i < points->items + 1; i++) worklist[i] = 0;
  
  // Loop through the list of tets.
  for (i = 0; i < cavtetlist->len(); i++) {
    cavtet = (triface *)(* cavtetlist)[i];
    // Mark vertices of cavtet. Some vertices may be marked more than once,
    //   but do not matter.
    for (j = 0; j < 4; j++) {
      pt = (point) cavtet->tet[4 + j];
      worklist[pointmark(pt)] = 1;
    }
  }

  // Remember the current number of encroached segments.
  oldencnum = badsubsegs->items;

  // Check the entire list of subfaces.
  subfaces->traversalinit();
  checksh.sh = shellfacetraverse(subfaces);
  while (checksh.sh != (shellface *) NULL) {
    // Find out how many vertices of cehcksh are marked.
    mcount = 0;
    for (i = 0; i < 3; i++) {
      pt = (point) checksh.sh[3 + i];
      mcount += worklist[pointmark(pt)];
    }
    // If all three vertcies are marked, test it.
    if (mcount >= 1) {
      checksub4encroach(&checksh, testpt, true);
    }
    checksh.sh = shellfacetraverse(subfaces);
  }

  delete [] worklist;
  return (badsubfaces->items > oldencnum);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// collectflipedges()    Collect edges of split subfaces for flip checking.  //
//                                                                           //
// 'inspoint' is a newly inserted segment point (inserted by insertsite()).  //
// 'splitseg' is one of the two split subsegments. Some subfaces may be non- //
// Delaunay since they're still not bonded to CDT. This routine collect all  //
// such possible subfaces in 'flipqueue'.                                    //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::
collectflipedges(point inspoint, face* splitseg, queue* flipqueue)
{
  face startsh, spinsh, checksh;
  face nextseg;
  point pa, pb;

  // Let the dest of splitseg be inspoint.
  splitseg->shver = 0;
  if (sdest(*splitseg) != inspoint) {
    sesymself(*splitseg);
  }
  assert(sdest(*splitseg) == inspoint);
  pa = sorg(*splitseg);
  spivot(*splitseg, startsh);
  spinsh = startsh;
  do {
    findedge(&spinsh, pa, inspoint);
    senext2(spinsh, checksh);
    enqueueflipedge(checksh, flipqueue);
    spivotself(spinsh);
  } while (spinsh.sh != startsh.sh);

  // Get the next subsegment.
  senext(*splitseg, nextseg);
  spivotself(nextseg);
  assert(nextseg.sh != (shellface *) NULL);
  
  // Let the org of nextseg be inspoint.
  nextseg.shver = 0;
  if (sorg(nextseg) != inspoint) {
    sesymself(nextseg);
  }
  assert(sorg(nextseg) == inspoint);
  pb = sdest(nextseg);
  spivot(nextseg, startsh);
  spinsh = startsh;
  do {
    findedge(&spinsh, inspoint, pb);
    senext(spinsh, checksh);
    enqueueflipedge(checksh, flipqueue);
    spivotself(spinsh);
  } while (spinsh.sh != startsh.sh);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// perturbrepairencsegs()    Repair all encroached segments.                 //
//                                                                           //
// All encroached segments are stored in 'badsubsegs'.  Each segment will be //
// split by adding a perturbed point near its circumcenter.                  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::perturbrepairencsegs(queue* flipqueue)
{
  badface *encloop;
  tetrahedron encodedtet;
  triface splittet;
  face splitsub, symsplitsub;
  face splitseg, symsplitseg;
  point newpoint, sympoint;
  point pa, pb, pc;
  enum insertsiteresult success;
  enum locateresult loc, symloc;
  REAL cent[3], d1, ps, rs;
  int i, j;

  // Note that steinerleft == -1 if an unlimited number of Steiner points 
  //   is allowed.  Loop until 'badsubsegs' is empty.
  badsubsegs->traversalinit();
  encloop = badfacetraverse(badsubsegs);
  while ((encloop != (badface *) NULL) && (steinerleft != 0)) {
    splitseg = encloop->ss;
    assert(shell2badface(splitseg) == encloop);
    setshell2badface(splitseg, NULL);
    pa = sorg(splitseg);
    pb = sdest(splitseg);
    if ((pa == encloop->forg) && (pb == encloop->fdest)) {
      if (b->verbose > 1) {
        printf("  Get seg (%d, %d).\n", pointmark(pa), pointmark(pb));
      }
      // Create the newpoint.
      makepoint(&newpoint);
      // Get the circumcenter and radius of ab.
      for (i = 0; i < 3; i++) cent[i] = 0.5 * (pa[i] + pb[i]);
      d1 = 0.5 * distance(pa, pb);
      // Add a random perturbation to newpoint along the vector ab.
      ps = randgenerator(d1 * 1.0e-3);
      rs = ps / d1;
      // Set newpoint (be at the perturbed circumcenter of ab).
      for (i = 0; i < 3; i++) newpoint[i] = cent[i] + rs * (cent[i] - pa[i]);
      setpointtype(newpoint, FREESEGVERTEX);
      // Set splitseg into the newpoint.
      // setpoint2sh(newpoint, sencode(splitseg));        

      // Is there periodic boundary condition?
      if (checkpbcs) {
        // Insert points on other segments of incident pbcgroups.
        i = shellmark(splitseg) - 1;
        for (j = idx2segpglist[i]; j < idx2segpglist[i + 1]; j++) {
          makepoint(&sympoint);
          symloc = getsegpbcsympoint(newpoint, &splitseg, sympoint,
                                     &symsplitseg, segpglist[j]);
          assert(symloc != OUTSIDE);
          if (symloc == ONEDGE) {
            assert(symsplitseg.sh != dummysh);
            setpointtype(sympoint, FREESEGVERTEX);
            // setpoint2sh(sympoint, sencode(symsplitseg));
            // Insert sympoint into DT.
            pc = sorg(symsplitseg);
            splittet.tet = dummytet;
            // Find a good start point to search.
            encodedtet = point2tet(pc);
            if (encodedtet != (tetrahedron) NULL) {
              decode(encodedtet, splittet);
              if (isdead(&splittet)) {
                splittet.tet = dummytet; 
              }
            }
            // Locate sympoint in DT.  Do exact location.
            success = insertsite(sympoint, &splittet, false, flipqueue);
            assert(success != DUPLICATEPOINT);
            if (success == OUTSIDEPOINT) {
              inserthullsite(sympoint, &splittet, flipqueue, NULL, NULL);
            }
            if (steinerleft > 0) steinerleft--;
            // Let sympoint remember splittet.
            setpoint2tet(sympoint, encode(splittet));
            // Do flip in DT.
            flip(flipqueue, NULL, false, false, false);
            // Insert sympoint into F.
            symloc = locateseg(sympoint, &symsplitseg);
            if (symloc == ONEDGE) {
              symsplitseg.shver = 0;
              spivot(symsplitseg, symsplitsub);
              // sympoint should on the edge of symsplitsub.
              splitsubedge(sympoint, &symsplitsub, flipqueue);
            } else {
              // insertsite() has done the whole job.
              assert(symloc == ONVERTEX);
              assert(checksubfaces);
              // Some edges may need to be flipped.
              collectflipedges(sympoint, &symsplitseg, flipqueue);
            }
            // Do flip in facet.
            flipsub(flipqueue);
          } else if (symloc == ONVERTEX) {
            // The symmtric point already exists. It is possible when two
            //   pbc group are idebtical. Omit sympoint.
            pointdealloc(sympoint);
          }
        }
      }

      // Insert newpoint into DT.
      splittet.tet = dummytet;
      // Find a good start point to search.
      encodedtet = point2tet(pa);
      if (encodedtet != (tetrahedron) NULL) {
        decode(encodedtet, splittet);
        if (isdead(&splittet)) {
          splittet.tet = dummytet; 
        }
      }
      if (splittet.tet == dummytet) { // Try pb.
        encodedtet = point2tet(pb);
        if (encodedtet != (tetrahedron) NULL) {
          decode(encodedtet, splittet);
          if (isdead(&splittet)) {
            splittet.tet = dummytet;
          }
        }
      }
      // Locate the newpoint in DT.  Do exact location.
      success = insertsite(newpoint, &splittet, false, flipqueue);
      assert(success != DUPLICATEPOINT);
      if (success == OUTSIDEPOINT) {
        // A convex hull edge is mssing, and the inserting point lies
        //   (slightly) outside the convex hull due to the significant
        //   digits lost in the calculation. Enlarge the convex hull.
        inserthullsite(newpoint, &splittet, flipqueue, NULL, NULL);
      }
      if (steinerleft > 0) steinerleft--;
      // Let newpoint remember splittet.
      setpoint2tet(newpoint, encode(splittet));
      // Do flip in DT.
      flip(flipqueue, NULL, false, false, false);
      // Insert newpoint into F.
      loc = locateseg(newpoint, &splitseg);
      if (loc == ONEDGE) {
        splitseg.shver = 0;
        spivot(splitseg, splitsub);
        // newpoint should on the edge of splitsub.
        splitsubedge(newpoint, &splitsub, flipqueue);
      } else {
        // insertsite() has done the whole job.
        assert(loc == ONVERTEX);
        assert(checksubfaces);
        // Some edges may need to be flipped.
        collectflipedges(newpoint, &splitseg, flipqueue);
      }
      // Do flip in facet.
      flipsub(flipqueue);
    }
    // Remove this entry from list.
    badfacedealloc(badsubsegs, encloop);  
    // Get the next encroached segments.
    encloop = badfacetraverse(badsubsegs);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// perturbrepairencsubs()    Repair all encroached subfaces.                 //
//                                                                           //
// All encroached subfaces are stored in 'badsubfaces'. Each subface will be //
// split by adding a perturbed point near its circumcenter. However, if the  //
// point encroaches some segments, it will not be inserted.  Instead, the    //
// encroached segments are split.                                            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::
perturbrepairencsubs(REAL eps, list* cavsublist, queue* flipqueue)
{
  badface *encloop, *encsubseg;
  tetrahedron encodedtet;
  triface splittet;
  face splitsub, symsplitsub;
  face checkseg, symsplitseg;
  point newpoint, sympoint;
  point pa, pb, pc, pd;
  enum insertsiteresult success;
  enum locateresult loc, symloc;
  REAL cent[3], d1, ps, rs;
  bool reject;
  int i;

  // Note that steinerleft == -1 if an unlimited number of Steiner points
  //   is allowed.  Loop until the list 'badsubfaces' is empty.
  while ((badsubfaces->items > 0) && (steinerleft != 0)) {
    badsubfaces->traversalinit();
    encloop = badfacetraverse(badsubfaces);
    while ((encloop != (badface *) NULL) && (steinerleft != 0)) {
      splitsub = encloop->ss;
      assert(shell2badface(splitsub) == encloop);
      setshell2badface(splitsub, NULL);
      pa = sorg(splitsub);
      pb = sdest(splitsub);
      pc = sapex(splitsub);
      // The subface may be not the same one when it was determined to be
      //   encroached.  If its adjacent encroached subface was split, the
      //   consequent flips may change it into another subface.
      if ((pa == encloop->forg) && (pb == encloop->fdest) &&
          (pc == encloop->fapex)) {
        if (b->verbose > 1) {
          printf("  Get subface (%d, %d, %d).\n", pointmark(pa),
                 pointmark(pb), pointmark(pc));
        }
        // Create the newpoint.
        makepoint(&newpoint);
        // Get the circumcenter of abc.
        circumsphere(pa, pb, pc, NULL, cent, &d1);
        assert(d1 > 0.0);
        // Add a random perturbation to newpoint along the vector a->cent.
        //   This way, the perturbed point still lies in the plane of abc.
        ps = randgenerator(d1 * 1.0e-3);
        rs = ps / d1;
        // Set newpoint (be at the perturbed circumcenter of abc).
        for (i = 0; i < 3; i++) newpoint[i] = cent[i] + rs * (cent[i] - pa[i]);
        // Locate newpoint in facet. Stop at subsegment.
        loc = locatesub(newpoint, &splitsub, 1);
        assert(loc != ONVERTEX);
        if (loc != OUTSIDE) {
          // Add 'splitsub' into 'cavsublist'.
          cavsublist->append(&splitsub);
          // Collect all subfaces that encroached by newpoint.
          collectcavsubs(newpoint, cavsublist);
          // Find if there are encroached segments.
          reject = tallencsegsfsubs(newpoint, cavsublist);
          // Clear cavsublist for the next use.
          cavsublist->clear();
        } else {
          // newpoint lies outside. splitsub contains the boundary segment.
          sspivot(splitsub, checkseg);
          assert(checkseg.sh != dummysh);
          // Add this segment into list for splitting.
          if (b->verbose > 2) {
            printf("    Queuing boundary segment (%d, %d).\n",
                   pointmark(sorg(checkseg)), pointmark(sdest(checkseg)));
          }
          encsubseg = (badface *) badsubsegs->alloc();
          encsubseg->ss = checkseg;
          encsubseg->forg = sorg(checkseg);
          encsubseg->fdest = sdest(checkseg);
          encsubseg->foppo = (point) NULL;
          setshell2badface(encsubseg->ss, encsubseg);
          // Reject newpoint.
          reject = true;
        }

        if (!reject) {
          // newpoint is going to be inserted.
          
          // Is there periodic boundary condition?
          if (checkpbcs) {
            if (shellpbcgroup(splitsub) >= 0) {
              // Insert a point on another facet of the pbcgroup.
              makepoint(&sympoint);
              symloc = getsubpbcsympoint(newpoint, &splitsub, sympoint,
                                         &symsplitsub);
              assert(symloc != ONVERTEX);
              setpoint2pbcpt(newpoint, sympoint);
              setpoint2pbcpt(sympoint, newpoint);
              setpointtype(sympoint, FREESUBVERTEX);
              // setpoint2sh(sympoint, sencode(symsplitsub));
              // Insert sympoint into DT.
              pd = sorg(symsplitsub);
              splittet.tet = dummytet;
              // Find a good start point to search.
              encodedtet = point2tet(pd);
              if (encodedtet != (tetrahedron) NULL) {
                decode(encodedtet, splittet);
                if (isdead(&splittet)) {
                  splittet.tet = dummytet; 
                }
              }
              // Locate sympoint in DT.  Do exact location.
              success = insertsite(sympoint, &splittet, false, flipqueue);
              assert(success != DUPLICATEPOINT);
              if (success == OUTSIDEPOINT) {
                inserthullsite(sympoint, &splittet, flipqueue, NULL, NULL);
              }
              if (steinerleft > 0) steinerleft--;
              // Let sympoint remember splittet.
              setpoint2tet(sympoint, encode(splittet));
              // Do flip in DT.
              flip(flipqueue, NULL, false, false, false);
              // Insert sympoint into F.
              symloc = locatesub(sympoint, &symsplitsub, 1);
              if (symloc == ONFACE) {
                splitsubface(sympoint, &symsplitsub, flipqueue);
              } else if (symloc == ONEDGE) {
                splitsubedge(sympoint, &symsplitsub, flipqueue);
              } else {
                // 'insertsite()' has done the whole job.
                assert(symloc == ONVERTEX);
                assert(checksubfaces);
                // Split subfaces have been flipped.
                flipqueue->clear();
              }
              // Do flip in facet.
              flipsub(flipqueue);
            }
          }

          // Insert newpoint into DT.
          splittet.tet = dummytet;
          // Find a good start point to search.
          encodedtet = point2tet(pa);
          if (encodedtet != (tetrahedron) NULL) {
            decode(encodedtet, splittet);
            if (isdead(&splittet)) {
              splittet.tet = dummytet; 
            }
          }
          if (splittet.tet == dummytet) { // Try pb.
            encodedtet = point2tet(pb);
            if (encodedtet != (tetrahedron) NULL) {
              decode(encodedtet, splittet);
              if (isdead(&splittet)) {
                splittet.tet = dummytet;
              }
            }
          }
          // Locate the newpoint in DT.  Do exact location.
          success = insertsite(newpoint, &splittet, false, flipqueue);
          assert(success != DUPLICATEPOINT);
          if (success == OUTSIDEPOINT) {
            inserthullsite(newpoint, &splittet, flipqueue, NULL, NULL);
          }
          if (steinerleft > 0) steinerleft--;
          // Let newpoint remember splittet.
          setpoint2tet(newpoint, encode(splittet));
          // Do flip in DT.
          flip(flipqueue, NULL, false, false, false);
          // Insert newpoint into F.
          loc = locatesub(newpoint, &splitsub, 1);
          if (loc == ONFACE) {
            // Insert the newpoint in facet.
            splitsubface(newpoint, &splitsub, flipqueue);
          } else if (loc == ONEDGE) {
            // Insert the newpoint in facet.
            splitsubedge(newpoint, &splitsub, flipqueue);
          } else {
            // 'insertsite()' has done the whole job.
            assert(loc == ONVERTEX);
            assert(checksubfaces);
            // Split subfaces have been flipped.
            flipqueue->clear();
          }
          // Set the type of the newpoint.
          setpointtype(newpoint, FREESUBVERTEX);
          // Set splitsub into the newpoint.
          // setpoint2sh(newpoint, sencode(splitsub));
          // Do flip in facet.
          flipsub(flipqueue);

          // Remove this entry from list.
          badfacedealloc(badsubfaces, encloop);
        } else {
          // newpoint is rejected. Remove it from points.
          pointdealloc(newpoint);
          // Repair all encroached segments.
          perturbrepairencsegs(flipqueue);
          // Do not remove 'encloop'. Later it will be tested again.
          setshell2badface(encloop->ss, encloop);
        }
      } else {
        // This subface has been changed. Remove this entry from list.
        badfacedealloc(badsubfaces, encloop);
        // It may be co-circular with its neighbors.
        checksub4cocir(&splitsub, eps, false, true); 
      }
      // Get the next encroached subfaces.
      encloop = badfacetraverse(badsubfaces);
    }
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// perturbrepairbadtets()    Repair all bad tetrahedra.                      //
//                                                                           //
// Bad tetrahedra are saved in 'badtetrahedrons'. Each bad tetrahedron will  //
// be split by inserting a perturbed point near its circumcenter.  However,  //
// if the point encroaches upon some subfaces, it is rejected.  Instead, all //
// encroached subfaces are split.                                            //
//                                                                           //
// 'eps', and 'cavsublist' are not used in this routine, they are passed to  //
// 'perturbrepairencsubs()'. 'cavtetlist' is re-used in 'collectcavtets()'.  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::
perturbrepairbadtets(REAL eps, list* cavsublist, list* cavtetlist,
                     queue* flipqueue)
{
  badface *tetloop;
  triface splittet, neightet;
  point pa, pb, pc, pd, pe;
  point newpoint;
  enum insertsiteresult success;
  enum locateresult loc;
  REAL cent[3], d1, ps, rs;
  REAL vol1, vol2, vol3;
  REAL ori1, ori2, ori3, epspp;
  bool reject;
  int zerocount, restart;
  int i;

  while ((badtetrahedrons->items > 0) && (steinerleft != 0)) {
    badtetrahedrons->traversalinit();
    tetloop = badfacetraverse(badtetrahedrons);
    while ((tetloop != (badface *) NULL) && (steinerleft != 0)) {
      splittet = tetloop->tt;
      if (!isdead(&splittet)) {
        pa = org(splittet);
        pb = dest(splittet);
        pc = apex(splittet);
        pd = oppo(splittet);
        sym(splittet, neightet);
        if (neightet.tet != dummytet) {
          pe = oppo(neightet);
        } else {
          pe = (point) NULL;
        }
      } else {
        pa = (point) NULL;
      }
      // Make sure that 'splitet' is still the same one when it was tested.
      //   Subsequent transformations may have made it a different tet.
      if ((pa == tetloop->forg) && (pb == tetloop->fdest) &&
          (pc == tetloop->fapex) && (pd == tetloop->foppo) &&
          (pe == tetloop->noppo)) {
        if (b->verbose > 1) {
          printf("  Get deg-tets (%d, %d, %d, %d, %d).\n", pointmark(pa),
                 pointmark(pb), pointmark(pc), pointmark(pd), pointmark(pe));
        }
        // Find out if there are four coplanar points.  Since abc is the
        //   common face of the two tets. It should not be coplanar with e
        //   (at it's opposite).  We test the other three faces of abcd
        //   to see if they are coplanar with e.
        vol1 = orient3d(pa, pb, pd, pe);
        vol2 = orient3d(pb, pc, pd, pe);
        vol3 = orient3d(pc, pa, pd, pe);
        epspp = b->epsilon * 1e+2;
        restart = 0;
        while (restart < 32) {
          zerocount = 0;
          ori1 = vol1;
          if (ori1 != 0.0) {
            if (iscoplanar(pa, pb, pd, pe, ori1, epspp)) ori1 = 0.0;
          }
          ori2 = vol2;
          if (ori2 != 0.0) {
            if (iscoplanar(pb, pc, pd, pe, ori2, epspp)) ori2 = 0.0;
          }
          ori3 = vol3;
          if (ori3 != 0.0) {
            if (iscoplanar(pc, pa, pd, pe, ori3, epspp)) ori3 = 0.0;
          }
          if (ori1 == 0.0) zerocount++;
          if (ori2 == 0.0) zerocount++;
          if (ori3 == 0.0) zerocount++;
          // Only (zerocount == 0) or (zerocount == 1) is valid.
          if (zerocount > 1) {
            epspp *= 1e-1;
            restart++;
            continue;
          }
          break;
        }
        assert(restart < 32);
        
        // Create the newpoint.
        makepoint(&newpoint);
        // Get the circumcenter.  If there are four coplanar points, take
        //   the circumcenter of the circle.
        if (ori1 == 0.0) {
          circumsphere(pa, pb, pd, NULL, cent, &d1);
        } else if (ori2 == 0.0) {
          circumsphere(pb, pc, pd, NULL, cent, &d1);
        } else if (ori3 == 0.0) {
          circumsphere(pc, pa, pd, NULL, cent, &d1);
        } else {
          // Get the circumcenter of the tet abcd.
          circumsphere(pa, pb, pc, pd, cent, &d1);
        }
        assert(d1 > 0.0);
        // Add a random perturbation to newpoint along the vector d->cent.
        //   This way, the perturbed point will be in the plane if there
        //   are four points coplanar (d must be one of them).
        ps = randgenerator(d1 * 1.0e-3);
        rs = ps / d1;
        // Set newpoint (be at the perturbed circumcenter).
        for (i = 0; i < 3; i++) newpoint[i] = cent[i] + rs * (cent[i] - pd[i]);
        // Set it's type be FREEVOLVERTEX.
        setpointtype(newpoint, FREEVOLVERTEX);

        // Locate newpoint in DT.
        loc = preciselocate(newpoint, &splittet);
        // Note that newpoint may be outside the DT.
        if (loc == OUTSIDE) {
          // The following lines only do check.
          sym(splittet, neightet);
          assert(neightet.tet == dummytet);
        }
        // Look if the newpoint encroaches upon some subfaces.
        cavtetlist->append(&splittet);
        collectcavtets(newpoint, cavtetlist);
        assert(cavtetlist->len() > 0);
        reject = tallencsubsfsubs(newpoint, cavtetlist);
        // Clear the list for the next use.
        cavtetlist->clear();
        if (!reject) {
          // Insert the newpoint into DT.
          success = insertsite(newpoint, &splittet, false, flipqueue);
          assert(success != DUPLICATEPOINT);
          if (success == OUTSIDEPOINT) {
            inserthullsite(newpoint, &splittet, flipqueue, NULL, NULL);
          }
          if (steinerleft > 0) steinerleft--;
          // Let newpoint remember splittet.
          setpoint2tet(newpoint, encode(splittet));
          // Do flip in DT.
          flip(flipqueue, NULL, false, false, false);
          // Remove this entry from list.
          badfacedealloc(badtetrahedrons, tetloop);
        } else {
          // newpoint is rejected. Remove it from points.
          pointdealloc(newpoint);
          // Repair all encroached segments.
          perturbrepairencsubs(eps, cavsublist, flipqueue);
          // Do not remove 'tetloop'. Later it will be tested again.
        }
      } else {
        // This tet has been changed. Remove this entry from list.
        badfacedealloc(badtetrahedrons, tetloop);
        if (!isdead(&splittet)) {
          // It may be co-sphere with its neighbors.
          checktet4cosph(&splittet, eps, false, true); 
        }
      }
      // Get the next badtetrahedron.
      tetloop = badfacetraverse(badtetrahedrons);
    }
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// incrperturbvertices()    Remove the local degeneracies in DT.             //
//                                                                           //
// A local degeneracy of a DT D is a set of 5 or more vertices which share a //
// common sphere S and no other vertex of D in S.  D is not unique if it has //
// local degeneracies. This routine removes the local degeneracies from D by //
// inserting break points (as described in reference [2]).                   //
//                                                                           //
// 'eps' is a user-provided error tolerance. It is used to detect whether or //
// not five points are approximate cospherical (evaluated in iscospheric()). //
// Set it to 0.0 to disable it, i.e., only test pure degenerate point set.   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::incrperturbvertices(REAL eps)
{
  queue *flipqueue;
  list *cavsublist, *cavtetlist;
  long vertcount;
  int i;

  if (!b->quiet) {
    printf("Perturbing vertices.\n");
  }

  vertcount = points->items;
  // Create a map from points to tets for fastening search.
  makepoint2tetmap();

  // Initialize working queues, lists.
  flipqueue = new queue(sizeof(badface));
  cavsublist = new list(sizeof(face), NULL, 256);
  // Initialize the pool of encroached subfaces and subsegments.
  badsubsegs = new memorypool(sizeof(badface), SUBPERBLOCK, POINTER, 0);
  badsubfaces = new memorypool(sizeof(badface), SUBPERBLOCK, POINTER, 0);
  // Find all pairs of co-circular subfaces.
  tallcocirsubs(eps, true);
  if (b->verbose && badsubfaces->items > 0) {
    printf("  Removing degenerate subfaces.\n");
  }
  perturbrepairencsubs(eps, cavsublist, flipqueue);

  if (b->dofullperturb) {
    cavtetlist = new list(sizeof(triface), NULL, 256);
    // Initialize the pool of bad tetrahedra.
    badtetrahedrons = new memorypool(sizeof(badface), ELEPERBLOCK, POINTER, 0);
    // Initialize the queues of badfaces.
    for (i = 0; i < 2; i++) subquefront[i] = (badface *) NULL;
    for (i = 0; i < 2; i++) subquetail[i] = &subquefront[i];
    // Find all pairsof co-sphere tets.
    tallcosphtets(NULL, eps, true);
    if (b->verbose && badtetrahedrons->items > 0) {
      printf("  Removing degenerate tetrahedra.\n");
    }
    // do {
      perturbrepairbadtets(eps, cavsublist, cavtetlist, flipqueue);
      // tallcosphtets(NULL, eps, true);
    // } while (badtetrahedrons->items > 0);
    delete cavtetlist;
    delete badtetrahedrons;
    badtetrahedrons = (memorypool *) NULL;
  }

  if (b->verbose) {
    printf("  %ld break points are inserted.\n", points->items - vertcount);
  }
  
  delete cavsublist;
  delete flipqueue;
  delete badsubfaces;
  delete badsubsegs; 
  badsubsegs = (memorypool *) NULL;
  badsubfaces = (memorypool *) NULL;
}

//
// End of vertex perturbation routines
//

//
// Begin of segment recovery routines
//

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// markacutevertices()    Set the type (ACUTEVERTEX, NACUTEVERTEX) of verts. //
//                                                                           //
// Parameter 'acuteangle' gives the upperbound (in degree). Angles which are //
// smaller or equal than it are assumed as acute angles.  A vertex is acute  //
// if at least two segments incident at it with an acute angle.              //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::markacutevertices(REAL acuteangle)
{
  shellface** segsperverlist;
  face segloop, workseg, inciseg;
  point eorg, edest, eapex;
  REAL cosbound, anglearc;
  REAL v1[3], v2[3], L, D;
  bool isacute;
  int* idx2seglist;
  int idx, i, j, k;

  if (b->verbose) {
    printf("  Marking segments have acute corners.\n");
  }

  // Constructing a map from vertex to segments.
  makesegmentmap(idx2seglist, segsperverlist);

  // Initialize all vertices be unknown.
  subsegs->traversalinit();
  segloop.sh = shellfacetraverse(subsegs);
  while (segloop.sh != (shellface *) NULL) {
    // Check and set types for the two ends of this segment.
    for (segloop.shver = 0; segloop.shver < 2; segloop.shver++) {
      eorg = sorg(segloop);
      setpointtype(eorg, FACETVERTEX);
    }
    segloop.sh = shellfacetraverse(subsegs);
  }

  anglearc = acuteangle * PI / 180.0;
  cosbound = cos(anglearc);
  
  // Loop over the set of subsegments.
  subsegs->traversalinit();
  segloop.sh = shellfacetraverse(subsegs);
  while (segloop.sh != (shellface *) NULL) {
    // Check and set types for the two ends of this segment.
    for (segloop.shver = 0; segloop.shver < 2; segloop.shver++) {
      eorg = sorg(segloop);
      if ((pointtype(eorg) != ACUTEVERTEX) && 
          (pointtype(eorg) != NACUTEVERTEX)) {
        // This vertex has no type be set yet.
        idx = pointmark(eorg) - in->firstnumber;
        isacute = false;
        for (i = idx2seglist[idx]; i < idx2seglist[idx + 1] && !isacute; i++) {
          workseg.sh = segsperverlist[i];
          workseg.shver = 0;
          if (sorg(workseg) != eorg) {
            sesymself(workseg);
          }
          assert(sorg(workseg) == eorg);
          edest = sdest(workseg);
          for (j = i + 1; j < idx2seglist[idx + 1] && !isacute; j++) {
            inciseg.sh = segsperverlist[j];
            inciseg.shver = 0;
            assert(inciseg.sh != workseg.sh);
            if (sorg(inciseg) != eorg) {
              sesymself(inciseg);
            }
            assert(sorg(inciseg) == eorg);
            eapex = sdest(inciseg);
            // Check angles between segs (eorg, edest) and (eorg, eapex).
            for (k = 0; k < 3; k++) {
              v1[k] = edest[k] - eorg[k];
              v2[k] = eapex[k] - eorg[k];
            }
            L = sqrt(v1[0] * v1[0] + v1[1] * v1[1] + v1[2] * v1[2]);
            for (k = 0; k < 3; k++) v1[k] /= L;
            L = sqrt(v2[0] * v2[0] + v2[1] * v2[1] + v2[2] * v2[2]);
            for (k = 0; k < 3; k++) v2[k] /= L;
            D = v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];  
            if (D >= cosbound) {
              isacute = true; 
            }
          }
        }
        if (isacute) {
          setpointtype(eorg, ACUTEVERTEX);
        } else {
          setpointtype(eorg, NACUTEVERTEX);
        }
      }
    }
    segloop.sh = shellfacetraverse(subsegs);
  }

  delete [] idx2seglist;
  delete [] segsperverlist;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// finddirection()    Find the first tetrahedron on the path from one point  //
//                    to another.                                            //
//                                                                           //
// Find the tetrahedron that intersects a line segment L (from the origin of //
// 'searchtet' to the point 'tend'), and returns the result in 'searchtet'.  //
// The origin of 'searchtet' does not change, even though the tetrahedron    //
// returned may differ from the one passed in.  This routine is used to find //
// the direction to move in to get from one point to another.                //
//                                                                           //
// The return value notes the location of the line segment L with respect to //
// 'searchtet':                                                              //
//   - Returns RIGHTCOLLINEAR indicates L is collinear with the line segment //
//     from the origin to the destination of 'searchtet'.                    //
//   - Returns LEFTCOLLINEAR indicates L is collinear with the line segment  //
//     from the origin to the apex of 'searchtet'.                           //
//   - Returns TOPCOLLINEAR indicates L is collinear with the line segment   //
//     from the origin to the opposite of 'searchtet'.                       //
//   - Returns ACROSSEDGE indicates L intersects with the line segment from  //
//     the destination to the apex of 'searchtet'.                           //
//   - Returns ACROSSFACE indicates L intersects with the face opposite to   //
//     the origin of 'searchtet'.                                            //
//   - Returns BELOWHULL indicates L crosses outside the mesh domain. This   //
//     can only happen when the domain is non-convex.                        //
//                                                                           //
// NOTE: This routine only works correctly when the mesh is exactly Delaunay.//
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

enum tetgenmesh::finddirectionresult tetgenmesh::
finddirection(triface *searchtet, point tend)
{
  triface neightet;
  point tstart, tdest, tapex, toppo;
  REAL ori1, ori2, ori3;

  tstart = org(*searchtet);
  assert(tstart != tend);
  adjustedgering(*searchtet, CCW);
  if (tstart != org(*searchtet)) {
    enextself(*searchtet); // For keeping the same origin.
  }
  tdest = dest(*searchtet);
  if (tdest == tend) {
    return RIGHTCOLLINEAR;
  }
  tapex = apex(*searchtet); 
  if (tapex == tend) {
    return LEFTCOLLINEAR;
  } 

  ori1 = orient3d(tstart, tdest, tapex, tend);
  if (ori1 > 0.0) {
    // 'tend' is below the face, get the neighbor of this side.
    sym(*searchtet, neightet);
    if (neightet.tet != dummytet) {
      findorg(&neightet, tstart); 
      adjustedgering(neightet, CCW);
      if (org(neightet) != tstart) {
        enextself(neightet); // keep the same origin.
      }
      // Set the changed configuratiuon.
      *searchtet = neightet; 
      ori1 = -1.0; 
      tdest = dest(*searchtet);
      tapex = apex(*searchtet);
    } else {
      // A hull face. Only possible for a nonconvex mesh.
#ifdef SELF_CHECK
      assert(nonconvex);
#endif
      return BELOWHULL; 
    }
  }

  // Repeatedly change the 'searchtet', remain 'tstart' be its origin, until
  //   find a tetrahedron contains 'tend' or is crossed by the line segment
  //   from 'tstart' to 'tend'.
  while (true) {
    toppo = oppo(*searchtet);
    if (toppo == tend) {
      return TOPCOLLINEAR;
    }
    ori2 = orient3d(tstart, toppo, tdest, tend);
    if (ori2 > 0.0) {
      // 'tend' is below the face, get the neighbor at this side.
      fnext(*searchtet, neightet);
      symself(neightet);
      if (neightet.tet != dummytet) {
        findorg(&neightet, tstart); 
        adjustedgering(neightet, CCW);
        if (org(neightet) != tstart) {
          enextself(neightet); // keep the same origin.
        }
        // Set the changed configuration.
        *searchtet = neightet; 
        ori1 = -1.0; 
        tdest = dest(*searchtet);
        tapex = apex(*searchtet);
        // Continue the search from the changed 'searchtet'.
        continue;
      } else {
        // A hull face. Only possible for a nonconvex mesh.
#ifdef SELF_CHECK
        assert(nonconvex);
#endif
        return BELOWHULL; 
      }
    }
    ori3 = orient3d(tapex, toppo, tstart, tend);
    if (ori3 > 0.0) {
      // 'tend' is below the face, get the neighbor at this side.
      enext2fnext(*searchtet, neightet);
      symself(neightet);
      if (neightet.tet != dummytet) {
        findorg(&neightet, tstart); 
        adjustedgering(neightet, CCW);
        if (org(neightet) != tstart) {
          enextself(neightet); // keep the same origin.
        }
        // Set the changed configuration.
        *searchtet = neightet; 
        ori1 = -1.0; 
        tdest = dest(*searchtet);
        tapex = apex(*searchtet);
        // Continue the search from the changed 'searchtet'.
        continue;
      } else {
        // A hull face. Only possible for a nonconvex mesh.
#ifdef SELF_CHECK
        assert(nonconvex);
#endif
        return BELOWHULL; 
      }
    }
    // Now 'ori1', 'ori2' and 'ori3' are possible be 0.0 or all < 0.0;
    if (ori1 < 0.0) {
      // Possible cases are: ACROSSFACE, ACROSSEDGE, TOPCOLLINEAR.
      if (ori2 < 0.0) {
        if (ori3 < 0.0) {
          return ACROSSFACE;
        } else { // ori3 == 0.0;
          // Cross edge (apex, oppo)
          enext2fnextself(*searchtet);
          esymself(*searchtet); // org(*searchtet) == tstart;
          return ACROSSEDGE;
        }
      } else { // ori2 == 0.0; 
        if (ori3 < 0.0) {
          // Cross edge (dest, oppo)
          fnextself(*searchtet);
          esymself(*searchtet);
          enextself(*searchtet); // org(*searchtet) == tstart;
          return ACROSSEDGE;
        } else { // ori3 == 0.0;
          // Collinear with edge (org, oppo)
          return TOPCOLLINEAR;
        }
      }
    } else { // ori1 == 0.0;
      // Possible cases are: RIGHTCOLLINEAR, LEFTCOLLINEAR, ACROSSEDGE.
      if (ori2 < 0.0) {
        if (ori3 < 0.0) {
          // Cross edge (tdest, tapex)
          return ACROSSEDGE;
        } else { // ori3 == 0.0
          // Collinear with edge (torg, tapex)
          return LEFTCOLLINEAR;
        }
      } else { // ori2 == 0.0;
        assert(ori3 != 0.0);
        // Collinear with edge (torg, tdest)
        return RIGHTCOLLINEAR;
      }
    }
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// getsearchtet()    Find a tetrahedron whose origin is either 'p1' or 'p2'. //
//                                                                           //
// On return, the origin of 'searchtet' is either 'p1' or 'p2',  and 'tend'  //
// returns the other point.  'searchtet' serves as the starting tetrahedron  //
// for searching of the line segment from 'p1' to 'p2' or vice versa.        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::
getsearchtet(point p1, point p2, triface* searchtet, point* tend)
{
  tetrahedron encodedtet1, encodedtet2;

  // Is there a valid handle provided by the user?
  if ((searchtet->tet != (tetrahedron *) NULL) && !isdead(searchtet)) {
    // Find which endpoint the handle holds.
    if (findorg(searchtet, p1)) {
      *tend = p2;
      return;
    } else {
      if (findorg(searchtet, p2)) {
        *tend = p1;
        return;
      }
    }
  }
  // If not, search the handle stored in 'p1' or 'p2'.
  *tend = (point) NULL;
  encodedtet1 = point2tet(p1);
  encodedtet2 = point2tet(p2);
  if (encodedtet1 != (tetrahedron) NULL) {
    decode(encodedtet1, *searchtet);
    // Be careful, here 'searchtet' may be dead.
    if (findorg(searchtet, p1)) {
      *tend = p2;
    }
  } else if (encodedtet2 != (tetrahedron) NULL) {
    decode(encodedtet2, *searchtet);
    // Be careful, here 'searchtet' may be dead.
    if (findorg(searchtet, p2)) {
      *tend = p1;
    }
  }
  // If still not, perform a full point location.  The starting tetrahedron
  //   is chosen as follows: Use the handle stored in 'p1' or 'p2' if it is
  //   alive; otherwise, start from a tetrahedron on the convex hull.
  if (*tend == (point) NULL) {
    if (encodedtet1 != (tetrahedron) NULL) {
      decode(encodedtet1, *searchtet);
      // Be careful, here 'searchtet' may be dead.
    }
    if (isdead(searchtet)) {
      if (encodedtet2 != (tetrahedron) NULL) {
        decode(encodedtet2, *searchtet);
        // Be careful, here 'searchtet' may be dead.
      }
      if (isdead(searchtet)) {
        searchtet->tet = dummytet;
        searchtet->loc = 0;
        symself(*searchtet);
      }
      assert(!isdead(searchtet));
    }
    if (locate(p1, searchtet) != ONVERTEX) {
      printf("Internal error in getsearchtet():  Failed to locate point\n");
      printf("  (%.12g, %.12g, %.12g) %d.\n", p1[0], p1[1], p1[2],
             pointmark(p1));
      internalerror();
    }
    // Remember this handle in 'p1' to enhance the search speed.
    setpoint2tet(p1, encode(*searchtet));
    *tend = p2;
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// isedgeencroached()    Check whether or not a subsegment is encroached by  //
//                       a given point.                                      //
//                                                                           //
// A segment with endpoints 'p1' and 'p2' is encroached by the point 'testpt'//
// if it lies in the diametral sphere of this segment.  The degenerate case  //
// that 'testpt' lies on the sphere can be treated as either be encroached   //
// or not so. If you want to regard this case as be encroached, set the flag //
// 'degflag' be TRUE.                                                        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenmesh::
isedgeencroached(point p1, point p2, point testpt, bool degflag)
{
  REAL dotproduct;

  // Check if the segment is facing an angle larger than 90 degree?
  dotproduct = (p1[0] - testpt[0]) * (p2[0] - testpt[0])
             + (p1[1] - testpt[1]) * (p2[1] - testpt[1])
             + (p1[2] - testpt[2]) * (p2[2] - testpt[2]);
  if (dotproduct < 0) {
    return true;
  } else if (dotproduct == 0 && degflag) {
    return true;
  } else {
    return false;
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// scoutrefpoint()    Search the reference point of a missing segment.       //
//                                                                           //
// A segment S is missing in current Delaunay tetrahedralization DT and will //
// be split by inserting a point V in it.  The two end points of S are the   //
// origin of 'searchtet' and 'tend'. And we know that S is crossing the face //
// of 'searchtet' opposite to its origin (may be intersecting with the edge  //
// from the destination to the apex of the 'searchtet').  The search of P is //
// completed by walking through all faces of DT across by S.                 //
//                                                                           //
// Warning:  This routine is correct when the tetrahedralization is Delaunay //
// and convex. Otherwise, the search loop may not terminate.                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

tetgenmesh::point tetgenmesh::scoutrefpoint(triface* searchtet, point tend)
{
  triface checkface;
  point tstart, testpt, refpoint;
  REAL cent[3], radius, largest;
  REAL ahead;
  bool ncollinear;
  int sides;

  if (b->verbose > 2) {
    printf("  Scout the reference point of segment (%d, %d).\n",
           pointmark(org(*searchtet)), pointmark(tend));
  }

  tstart = org(*searchtet);
  refpoint = (point) NULL;
  
  // Check the three vertices of the crossing face.
  testpt = apex(*searchtet);
  if (isedgeencroached(tstart, tend, testpt, true)) {
    ncollinear = circumsphere(tstart, tend, testpt, NULL, cent, &radius);
    assert(ncollinear);
    refpoint = testpt;
    largest = radius;
  }
  testpt = dest(*searchtet);
  if (isedgeencroached(tstart, tend, testpt, true)) {
    ncollinear = circumsphere(tstart, tend, testpt, NULL, cent, &radius);
    assert(ncollinear);
    if (refpoint == (point) NULL) {
      refpoint = testpt;
      largest = radius;
    } else {
      if (radius > largest) {
        refpoint = testpt;
        largest = radius;
      }
    }
  }
  testpt = oppo(*searchtet);
  if (isedgeencroached(tstart, tend, testpt, true)) {
    ncollinear = circumsphere(tstart, tend, testpt, NULL, cent, &radius);
    assert(ncollinear);
    if (refpoint == (point) NULL) {
      refpoint = testpt;
      largest = radius;
    } else {
      if (radius > largest) {
        refpoint = testpt;
        largest = radius;
      }
    }
  }
  // Check the opposite vertex of the neighboring tet in case the segment
  //   crosses the edge (leftpoint, rightpoint) of the crossing face.
  sym(*searchtet, checkface);
  if (checkface.tet != dummytet) {
    testpt = oppo(checkface);
    if (isedgeencroached(tstart, tend, testpt, true)) {
      ncollinear = circumsphere(tstart, tend, testpt, NULL, cent, &radius);
      assert(ncollinear);
      if (refpoint == (point) NULL) {
        refpoint = testpt;
        largest = radius;
      } else {
        if (radius > largest) {
          refpoint = testpt;
          largest = radius;
        }
      }
    }
  }

  // Walk through all crossing faces.
  enextfnext(*searchtet, checkface);
  sym(checkface, *searchtet);
  while (true) {
    // Check if we are reaching the boundary of the triangulation.
    assert(searchtet->tet != dummytet);
    // Search for an adjoining tetrahedron we can walk through.
    searchtet->ver = 0;
    // 'testpt' is the shared vertex for the following orientation tests.
    testpt = oppo(*searchtet);
    if (testpt == tend) {
      // The searching is finished.
      break; 
    } else {
      // 'testpt' may encroach the segment.
      if ((testpt != tstart) && (testpt != refpoint)) {
        if (isedgeencroached(tstart, tend, testpt, true)) {
          ncollinear = circumsphere(tstart, tend, testpt, NULL, cent, &radius);
          if (!ncollinear) {
            // 'testpt' is collinear with the segment. It may happen when a
            //   set of collinear and continuous segments is defined by two
            //   extreme endpoints.  In this case, we should choose 'testpt'
            //   as the splitting point immediately.  No new point should be
            //   created.
            refpoint = testpt;
            break;
          }
          if (refpoint == (point) NULL) {
            refpoint = testpt;
            largest = radius;
          } else {
            if (radius > largest) {
              refpoint = testpt;
              largest = radius;
            }
          }
        }
      }
    }
    // Check three side-faces of 'searchtet' to find the one through
    //   which we can walk next.
    for (sides = 0; sides < 3; sides++) {
      fnext(*searchtet, checkface);
      ahead = orient3d(org(checkface), dest(checkface), testpt, tend);
      if (ahead < 0.0) {
        // We can walk through this face and continue the searching. 
        sym(checkface, *searchtet);
        break;
      }
      enextself(*searchtet);
    }
    assert (sides < 3);
  }

  assert(refpoint != (point) NULL);
  return refpoint;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// getsegmentorigin()    Return the origin of the (unsplit) segment.         //
//                                                                           //
// After a segment (or a subsegment) is split. Two resulting subsegments are //
// connecting each other through the pointers saved in their data fields.    //
// With these pointers, the whole (unsplit) segment can be found. 'splitseg' //
// may be a split subsegment.  Returns the origin of the unsplit segment.    //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

tetgenmesh::point tetgenmesh::getsegmentorigin(face* splitseg)
{
  face workseg;
  point farorg;

  farorg = sorg(*splitseg);
  if ((pointtype(farorg) != ACUTEVERTEX) &&
      (pointtype(farorg) != NACUTEVERTEX)) {
    workseg = *splitseg;
    do {
      senext2self(workseg);
      spivotself(workseg);
      if (workseg.sh != dummysh) {
        workseg.shver = 0;  // It's a subsegment.
        if (sdest(workseg) != farorg) {
          sesymself(workseg);
          assert(sdest(workseg) == farorg);
        }
        farorg = sorg(workseg);
        if ((pointtype(farorg) == ACUTEVERTEX) ||
            (pointtype(farorg) == NACUTEVERTEX)) break;
      }
    } while (workseg.sh != dummysh);
  }
  assert((pointtype(farorg) == ACUTEVERTEX) ||
         (pointtype(farorg) == NACUTEVERTEX));
  return farorg;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// getsplitpoint()    Get a point for splitting a segment.                   //
//                                                                           //
// 'splitseg' is the segment will be split. 'refpoint' is a reference point  //
// for splitting this segment. Moreover, it should not collinear with the    //
// splitting segment. (The collinear case will be detected by iscollinear()  //
// before entering this routine.)  The calculation of the splitting point is //
// governed by three rules introduced in my paper.                           //
//                                                                           //
// After the position is calculated, a new point is created at this location.//
// The new point has one of the two pointtypes: FREESEGVERTEX indicating it  //
// is an inserting vertex on segment, and NACUTEVERTEX indicating it is an   //
// endpoint of a segment which original has type-3 now becomes type-2.       //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

tetgenmesh::point tetgenmesh::getsplitpoint(face* splitseg, point refpoint)
{
  point splitpoint;
  point farorg, fardest;
  point ei, ej, ek, c;
  REAL v[3], r, split;
  REAL d1, ps, rs;
  bool acuteorg, acutedest;
  int stype;
  int i;   

  // First determine the type of the segment (type-1, type-2, or type-3).
  farorg = getsegmentorigin(splitseg);
  acuteorg = (pointtype(farorg) == ACUTEVERTEX);
  sesymself(*splitseg);
  fardest = getsegmentorigin(splitseg);
  acutedest = (pointtype(fardest) == ACUTEVERTEX);
  sesymself(*splitseg);

  if (acuteorg) {
    if (acutedest) {
      stype = 3;
    } else {
      stype = 2;
      ek = farorg;
    }
  } else {
    if (acutedest) {
      stype = 2;
      // Adjust splitseg, so that its origin is acute.
      sesymself(*splitseg);
      ek = fardest;
    } else {
      stype = 1;
    }
  }
  ei = sorg(*splitseg);
  ej = sdest(*splitseg);

  if (b->verbose > 1) {
    printf("  Splitting segment (%d, %d) type-%d with refpoint %d.\n",
           pointmark(ei), pointmark(ej), stype, pointmark(refpoint));
  }

  if (stype == 1 || stype == 3) {
    // Use rule-1.
    REAL eij, eip, ejp;
    eij = distance(ei, ej);
    eip = distance(ei, refpoint);
    ejp = distance(ej, refpoint);
    if ((eip < ejp) && (eip < 0.5 * eij)) {
      c = ei;
      r = eip;
    } else if ((eip > ejp) && (ejp < 0.5 * eij)) {
      c = ej;
      ej = ei;
      r = ejp;
    } else {
      c = ei;
      r = 0.5 * eij;
    }
    split = r / eij;
    for (i = 0; i < 3; i++) {
      v[i] = c[i] + split * (ej[i] - c[i]);
    }
  } else {
    // Use rule-2 or rule-3.
    REAL eki, ekj, ekp, evj, evp, eiv;
    c = ek;
    eki = distance(ek, ei);  // eki may equal zero.
    ekj = distance(ek, ej);
    ekp = distance(ek, refpoint);
    // Calculate v (the going to split position between ei, ej).
    r = ekp;
    assert(eki < r && r < ekj);
    split = r / ekj;
    for (i = 0; i < 3; i++) {
      v[i] = c[i] + split * (ej[i] - c[i]);
    }
    evj = ekj - r; // distance(v, ej);
    evp = distance(v, refpoint);
    if (evj < evp) {
      // v is rejected, use rule-3.
      eiv = distance(ei, v);
      if (evp <= 0.5 * eiv) {
        r = eki + eiv - evp;
      } else {
        r = eki + 0.5 * eiv;
      }
      assert(eki < r && r < ekj);
      split = r / ekj;
      for (i = 0; i < 3; i++) {
        v[i] = c[i] + split * (ej[i] - c[i]);
      }
      if (b->verbose > 1) {
        printf("    Using rule-3.\n");
      }
    } 
  }

  if (b->verbose > 1) {
    if (stype == 2) {
      printf("    Split = %.12g.\n", distance(ei, v) / distance(ei, ej));
    } else {
      printf("    Split = %.12g.\n", distance(c, v) / distance(c, ej));
    }
  }

  // Create the newpoint.
  makepoint(&splitpoint);
  // Add a random perturbation on splitpoint.
  d1 = distance(c, v);
  assert(d1 > 0.0);
  if (stype == 1 || stype == 3) {
    ps = randgenerator(d1 * 1.0e-3);
  } else {
    // For type-2 segment, add a smaller perturbation.
    ps = randgenerator(d1 * 1.0e-5);
  }
  rs = ps / d1;
  // Perturb splitpoint away from c.
  for (i = 0; i < 3; i++) {
    splitpoint[i] = c[i] + (1.0 + rs) * (v[i] - c[i]);
  }
  for (i = 0; i < in->numberofpointattributes; i++) {
    splitpoint[i + 3] = c[i + 3] + (split + rs) * (ej[i + 3] - c[i + 3]);
  }  
  if (stype == 3) {
    // Change a type-3 segment into two type-2 segments. 
    setpointtype(splitpoint, NACUTEVERTEX);
  } else {
    // Set it's type be FREESEGVERTEX.
    setpointtype(splitpoint, FREESEGVERTEX);
  }

  return splitpoint;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// delaunizesegments()    Split segments repeatedly until they appear in a   //
//                        Delaunay tetrahedralization.                       //
//                                                                           //
// Given a PLC X, which has a set V of vertices and a set of segments. Start //
// from a Delaunay tetrahedralization D of V, this routine recovers segments //
// of X in D by incrementally inserting points on missing segments, updating //
// D with the newly inserted points into D', which remains to be a Delaunay  //
// tetrahedralization and respects the segments of X. Hence, each segment of //
// X appears as a union of edges in D'.                                      //
//                                                                           //
// This routine dynamically maintains two meshes, one is DT, another is the  //
// surface mesh F of X.  DT and F have exactly the same vertices.  They are  //
// updated simultaneously with the newly inserted points.                    //
//                                                                           //
// Missing segments are found by looping the set S of segments, checking the //
// existence of each segment in DT.  Once a segment is found missing in DT,  //
// it is split into two subsegments by inserting a point into both DT and F, //
// and S is updated accordingly.  However, the inserted point may cause some //
// other existing segments be non-Delaunay,  hence are missing from the DT.  //
// In order to force all segments to appear in DT, we have to loop S again   //
// after some segments are split. (A little ugly method)  Use a handle to    //
// remember the last segment be split in one loop, hence all segments after  //
// it are existing and need not be checked.                                  //
//                                                                           //
// In priciple, a segment on the convex hull should exist in DT. However, if //
// there are four coplanar points on the convex hull, and the DT only can    //
// contain one diagonal edge which is unfortunately not the segment, then it //
// is missing. During the recovery of the segment, it is possible that the   //
// calculated inserting point for recovering this convex hull segment is not //
// exact enough and lies (slightly) outside the DT. In order to insert the   //
// point, we enlarge the convex hull of the DT, so it can contain the point  //
// and remains convex.  'inserthullsite()' is called for this case.          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::delaunizesegments()
{
  queue *flipqueue;
  tetrahedron encodedtet;
  triface searchtet, splittet;
  face splitsh, symsplitsub;
  face segloop, symsplitseg;
  face lastsplit;
  point refpoint, splitpoint, sympoint;
  point tend, checkpoint;
  point p1, p2, pa;
  enum finddirectionresult collinear;
  enum insertsiteresult success;
  enum locateresult symloc;
  bool finish, coll;
  long vertcount;
  int i, j;

  if (!b->quiet) {
    printf("Delaunizing segments.\n");
  }

  // Mark segment vertices (acute or not) for determining segment types.
  markacutevertices(89.0);
  // Construct a map from points to tetrahedra for speeding point location.
  makepoint2tetmap();
  // Initialize a queue for returning non-Delaunay faces and edges.
  flipqueue = new queue(sizeof(badface));
  // 'lastsplit' is the last segment be split in one loop, all segments
  //   after it are existing. At first, set it be NULL;
  lastsplit.sh = (shellface *) NULL;
  // Remember the current number of points.
  vertcount = points->items;

  finish = false;
  while (!finish && (steinerleft != 0)) {
    subsegs->traversalinit();
    segloop.sh = shellfacetraverse(subsegs);
    while ((segloop.sh != (shellface *) NULL) && (steinerleft != 0)) {
      // Search segment ab in DT.
      p1 = sorg(segloop);  // p1 = a;
      p2 = sdest(segloop);  // p2 = b;
      if (b->verbose > 2) {
        printf("  Checking segment (%d, %d).\n", pointmark(p1), pointmark(p2));
      }
      getsearchtet(p1, p2, &searchtet, &tend);
      collinear = finddirection(&searchtet, tend);
      if (collinear == LEFTCOLLINEAR) {
        checkpoint = apex(searchtet);
      } else if (collinear == RIGHTCOLLINEAR) {
        checkpoint = dest(searchtet);
      } else if (collinear == TOPCOLLINEAR) {
        checkpoint = oppo(searchtet);
      } else {
        assert(collinear == ACROSSFACE || collinear == ACROSSEDGE);
        checkpoint = (point) NULL;
      }
      if (checkpoint != tend) {
        // ab is missing.
        splitpoint = (point) NULL;
        if (checkpoint != (point) NULL) {
          // An existing point c is found on the segment. It can happen when
          //   ab is defined by a long segment with c inside it. Use c to
          //   split ab. No new point is created.
          splitpoint = checkpoint;
          if (pointtype(checkpoint) == FREEVOLVERTEX) {
            // c is not a segment vertex yet. It becomes NACUTEVERTEX.
            setpointtype(splitpoint, NACUTEVERTEX);  
          } else if (pointtype(checkpoint) == ACUTEVERTEX) {
            // c is an acute vertex. The definition of PLC is wrong.
          } else if (pointtype(checkpoint) == NACUTEVERTEX) {
            // c is an nonacute vertex. The definition of PLC is wrong.
          } else {
            assert(0);
          }
        } else {
          // Find a reference point p of ab.
          refpoint = scoutrefpoint(&searchtet, tend);
          if (pointtype(refpoint) == FREEVOLVERTEX) {
            // p is an input point, check if it is nearly collinear with ab.
            coll = iscollinear(p1, p2, refpoint, b->epsilon);
            if (coll) {
              // a, b, and p are collinear. We insert p into ab. p becomes
              //   a segment vertex with type NACUTEVERTEX.
              splitpoint = refpoint;
              setpointtype(splitpoint, NACUTEVERTEX);
            }
          }
          if (splitpoint == (point) NULL) {
            // Calculate a split point v using rule 1, or 2, or 3.
            splitpoint = getsplitpoint(&segloop, refpoint);
            
            // Is there periodic boundary conditions?
            if (checkpbcs) {
              // Yes! Insert points on other segments of incident pbcgroups.
              i = shellmark(segloop) - 1;
              for (j = idx2segpglist[i]; j < idx2segpglist[i + 1]; j++) {
                makepoint(&sympoint);
                symloc = getsegpbcsympoint(splitpoint, &segloop, sympoint,
                                           &symsplitseg, segpglist[j]);
                assert(symloc != OUTSIDE);
                if (symloc == ONEDGE) {
                  assert(symsplitseg.sh != dummysh);
                  setpointtype(sympoint, FREESEGVERTEX);
                  // setpoint2sh(sympoint, sencode(symsplitseg));
                  // Insert sympoint into DT.
                  pa = sorg(symsplitseg);
                  splittet.tet = dummytet;
                  // Find a good start point to search.
                  encodedtet = point2tet(pa);
                  if (encodedtet != (tetrahedron) NULL) {
                    decode(encodedtet, splittet);
                    if (isdead(&splittet)) {
                      splittet.tet = dummytet; 
                    }
                  }
                  // Locate sympoint in DT.  Do exact location.
                  success = insertsite(sympoint, &splittet, false, flipqueue);
                  assert(success != DUPLICATEPOINT);
                  if (success == OUTSIDEPOINT) {
                    inserthullsite(sympoint, &splittet, flipqueue, NULL, NULL);
                  }
                  if (steinerleft > 0) steinerleft--;
                  // Let sympoint remember splittet.
                  setpoint2tet(sympoint, encode(splittet));
                  // Do flip in DT.
                  flip(flipqueue, NULL, false, false, false);
                  // Insert sympoint into F.
                  symsplitseg.shver = 0;
                  spivot(symsplitseg, symsplitsub);
                  // sympoint should on the edge of symsplitsub.
                  splitsubedge(sympoint, &symsplitsub, flipqueue);
                  // Do flip in facet.
                  flipsub(flipqueue);
                } else if (symloc == ONVERTEX) {
                  // The sympoint already exists. It is possible when two
                  //   pbc groups are exactly the same. Omit this point.
                  pointdealloc(sympoint);
                }
              }
            }

            // Insert 'splitpoint' into DT.
            if (isdead(&searchtet)) searchtet.tet = dummytet;
            success = insertsite(splitpoint, &searchtet, false, flipqueue);
            if (success == OUTSIDEPOINT) {
              // A convex hull edge is missing, and the inserting point lies
              //   (slightly) outside the convex hull due to the significant
              //   digits lost in the calculation. Enlarge the convex hull.
              inserthullsite(splitpoint, &searchtet, flipqueue, NULL, NULL);
            }
            if (steinerleft > 0) steinerleft--;
            // Remember a handle in 'splitpoint' to enhance the speed of
            //   consequent point location.
            setpoint2tet(splitpoint, encode(searchtet));
            // Maintain Delaunayness in DT.
            flip(flipqueue, NULL, false, false, false);
          }
        }
        // Insert 'splitpoint' into F.
        spivot(segloop, splitsh);
        splitsubedge(splitpoint, &splitsh, flipqueue);
        flipsub(flipqueue);
        // Remember 'segloop'.
        lastsplit = segloop;
      } else {
        // ab exists. Is it the last one we've checked?
        if (segloop.sh == lastsplit.sh) {
          finish = true;
          break;
        }
      }
      segloop.sh = shellfacetraverse(subsegs);
    }
    if (lastsplit.sh == (shellface *) NULL) {
      // No missing segment!
      finish = true;
    }
  }

  if (b->verbose) {
    printf("  %ld protect points are inserted.\n", points->items - vertcount);
  }

  delete flipqueue;
}

//
// End of segments recovery routines
//

//
// Begin of facet recovery routines
//

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// insertsubface()    Insert a subface into the Delaunay tetrahedralization. //
//                                                                           //
// Search the subface in current Delaunay tetrahedralization. Return TRUE if //
// the subface exists, i.e., it appears as a face of the DT and is inserted. //
// Otherwise, return FALSE indicating it is a missing face.                  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenmesh::insertsubface(face* insertsh, triface* searchtet)
{
  triface spintet, symtet;
  face testsh, testseg;
  face spinsh, casin, casout;
  point tapex, checkpoint;
  enum finddirectionresult collinear;
  int hitbdry;

  // Search one edge of 'insertsh'.
  getsearchtet(sorg(*insertsh), sdest(*insertsh), searchtet, &checkpoint);
  collinear = finddirection(searchtet, checkpoint);
  if (collinear == LEFTCOLLINEAR) {
    enext2self(*searchtet);
    esymself(*searchtet);
  } else if (collinear == TOPCOLLINEAR) {
    fnextself(*searchtet);
    enext2self(*searchtet);
    esymself(*searchtet);
  }
  if (dest(*searchtet) != checkpoint) {
    // The edge is missing => subface is missing.
    return false;
  }

  // Spin around the edge (torg, tdest), look for a face containing tapex.
  tapex = sapex(*insertsh);
  spintet = *searchtet;
  hitbdry = 0;
  do {
    if (apex(spintet) == tapex) {
      // The subface is exist in DT. We will insert this subface. Before
      //   insertion, make sure there is no subface at this position.
      tspivot(spintet, testsh);
      if (testsh.sh == dummysh) {
        adjustedgering(spintet, CCW);
        findedge(insertsh, org(spintet), dest(spintet));
        tsbond(spintet, *insertsh);
        sym(spintet, symtet); // 'symtet' maybe outside, use it anyway.
        sesymself(*insertsh);
        tsbond(symtet, *insertsh);
      } else {
        // There already exists one subface. They're Duplicated.
        printf("Warning:  Two subfaces are found duplicated at ");
        printf("(%d, %d, %d)\n", pointmark(sorg(testsh)),
               pointmark(sdest(testsh)), pointmark(sapex(testsh)));
        printf("  The one of facet #%d is ignored.\n", shellmark(*insertsh));
        // printf("  Hint: -d switch can find all duplicated facets.\n");
      }
      return true;
    }
    if (!fnextself(spintet)) {
      hitbdry ++;
      if (hitbdry < 2) {
        esym(*searchtet, spintet);
        if (!fnextself(spintet)) {
          hitbdry ++;
        }
      }
    }
  } while (hitbdry < 2 && apex(spintet) != apex(*searchtet));

  // The face is missing.
  return false;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// tritritest()    Test if two triangles are intersecting in their interior. //
//                                                                           //
// One triangles is represented by 'checktet', the other is given by three   //
// corners 'p1', 'p2' and 'p3'. This routine calls tri_tri_inter() to detect //
// whether these two triangles are exactly intersecting in their interior    //
// (excluding the cases share a vertex, share an edge, or are coincide).     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenmesh::tritritest(triface* checktet, point p1, point p2, point p3)
{
  point forg, fdest, fapex;
  enum interresult intersect;

  forg = org(*checktet);
  fdest = dest(*checktet);
  fapex = apex(*checktet);

#ifdef SELF_CHECK
  REAL ax, ay, az, bx, by, bz;
  REAL n[3];
  // face (torg, tdest, tapex) should not be degenerate. However p1, p2,
  //   and p3 may be collinear. Check it.
  ax = forg[0] - fdest[0];
  ay = forg[1] - fdest[1];
  az = forg[2] - fdest[2];
  bx = forg[0] - fapex[0];
  by = forg[1] - fapex[1];
  bz = forg[2] - fapex[2];
  n[0] = ay * bz - by * az;
  n[1] = az * bx - bz * ax;
  n[2] = ax * by - bx * ay;
  assert(fabs(n[0]) + fabs(n[1]) + fabs(n[2]) > 0.0);
  // The components of n should not smaller than the machine epsilon.

  ax = p1[0] - p2[0];
  ay = p1[1] - p2[1];
  az = p1[2] - p2[2];
  bx = p1[0] - p3[0];
  by = p1[1] - p3[1];
  bz = p1[2] - p3[2];
  n[0] = ay * bz - by * az;
  n[1] = az * bx - bz * ax;
  n[2] = ax * by - bx * ay;
  assert(fabs(n[0]) + fabs(n[1]) + fabs(n[2]) > 0.0);
  // The components of n should not smaller than the machine epsilon.
#endif

  intersect = tri_tri_inter(forg, fdest, fapex, p1, p2, p3);
  return intersect == INTERSECT;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// initializecavity()    Initialize the cavity with a list of faces.         //
//                                                                           //
// Initialize the cavity C with a list of faces that bound C. Each face f of //
// C is hold by a tetrahedron t adjacent to C. t is outside the cavity (i.e.,//
// uninfected). Such t may not exist when f is on convex hull. In this case, //
// create a fake tetrahedron t' in order to hold f, oppo(t') = NULL. t' will //
// be removed automatically after C is retriangulated.                       //
//                                                                           //
// 'floorlist' is a list of coplanar subfaces, they are oriented in the same //
// direction pointing to the ceiling.  'ceilinglist' is a list of faces of   //
// tetrahedra which are crossing the cavity, they form the rest part of the  //
// boundary of the cavity. 'frontlink' is used to return the list of fronts, //
// it is empty on input.                                                     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::
initializecavity(list* floorlist, list* ceillist, link* frontlink)
{
  triface neightet, casingtet;
  triface faketet;
  face worksh;
  int i;

  // First add all faces in 'floorlist' into 'frontlink'.
  for (i = 0; i < floorlist->len(); i++) {
    // Get f = worksh.
    worksh = * (face *)(* floorlist)[i];
    // Current side of f should be empty.
    stpivot(worksh, neightet);
    assert(neightet.tet == dummytet);
    // Get adjacent tetrahedron t.
    sesymself(worksh);
    stpivot(worksh, casingtet);
    // Does t exist?
    if (casingtet.tet == dummytet) {
      // No. Create a fake tet t' to hold f temporarily. t' will be removed
      //   after f is hold by a new tetrahedron in C.
      maketetrahedron(&faketet);
      setorg(faketet, sorg(worksh));
      setdest(faketet, sdest(worksh));
      setapex(faketet, sapex(worksh));
      setoppo(faketet, (point) NULL); // Indicates it is 'fake'.
      tsbond(faketet, worksh);
      frontlink->add(&faketet);
    } else {
      frontlink->add(&casingtet);
    }
  }
  // Second add all casing faces in 'ceilinglist' into 'frontlink'.
  for (i = 0; i < ceillist->len(); i++) {
    neightet = * (triface *) (* ceillist)[i];
    // The ceil is a face of cavity tetrahedron (going to be deleted).
    assert(infected(neightet));
    // Get the adjacent tetrahedron t.
    sym(neightet, casingtet);
    // Does t exist?
    if (casingtet.tet == dummytet) {
      // No. Create a fake tet t' to hold f temporarily. t' will be removed
      //   after f is hold by a new tetrahedron in C.
      maketetrahedron(&faketet);
      setorg(faketet, org(neightet));
      setdest(faketet, dest(neightet));
      setapex(faketet, apex(neightet));
      setoppo(faketet, (point) NULL); // Indicates it is 'fake'.
      // Bond t' to a subface if it exists.
      tspivot(neightet, worksh);
      if (worksh.sh != dummysh) {
        sesymself(worksh);
        tsbond(faketet, worksh);
      } 
      // We bond t and t' together. So we're able to find t' and remove it.
      bond(faketet, neightet);
      // 'neightet' may become uninfected due to the bond().
      infect(neightet);
      frontlink->add(&faketet);
    } else {
      frontlink->add(&casingtet);
    }
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// delaunizevertices()    Create a DT of a set of vertices.                  //
//                                                                           //
// The routine constructs a Delaunay tetrahedralization of a set of vertices //
// by the incrmental-flip algorithm. 'floorptlist' and 'ceilptlist' form the //
// set of vertices.  Any vertex of 'ceilptlist' is not coplanar with all     //
// verrices of 'floorptlist', i.e., the initial DT can be quickly setup.     //
// 'newtetlink' returns all tetrahedra of the DT.                            //
//                                                                           //
// The tetrahedra of the DT are created directly in the pool 'tetrahedrons', //
// i.e., no auxiliary data structure and memory are required.  The trick is  //
// at the time they're created, there are no connections between them to the //
// other tetrahedra in the pool. You can imagine there is an ioslated island //
// in the whole DT.                                                          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::
delaunizevertices(list* floorptlist, list* ceilptlist, link* newtetlink,
                  int* worklist)
{
  queue *flipqueue;
  link *ptlink, *hulllink;
  triface starttet, neightet;
  triface newtet, bakhulltet;
  point pa, pb, pc, pd;
  point ptloop;
  enum insertsiteresult success;
  REAL ori;
  long bakhullsize;
  int i;

  // Initialize 'ptlink'.
  ptlink = new link(sizeof(point), NULL, 256);
  // Initialize 'hulllink' used in inserthullsite().
  hulllink = new link(sizeof(triface), NULL, 256);
  // Initialize flipqueue;
  flipqueue = new queue(sizeof(badface));
  // The incremental-flip routines are reused. Backup global variables.
  decode(dummytet[0], bakhulltet);
  bakhullsize = hullsize;
  // Decrease the debug level.
  b->verbose--;

  // Create an initial tetrahedralization containing only one tetrahedron
  //   formed by a (floor) subface and a (ceil) point.
  pa = * (point *)(* floorptlist)[0];
  pb = * (point *)(* floorptlist)[1];
  pc = * (point *)(* floorptlist)[2];
  pd = * (point *)(* ceilptlist)[0];
  // Adjust the orientation.
  ori = orient3d(pa, pb, pc, pd);
  assert(ori != 0.0);
  if (ori > 0) {
    ptloop = pa; pa = pb; pb = ptloop;
  }
  // Create the tetrahedron with corners pa, pb, pc and pd.
  maketetrahedron(&newtet);
  setorg(newtet, pa);
  setdest(newtet, pb);
  setapex(newtet, pc);
  setoppo(newtet, pd);
  // Bond to 'dummytet' for point location.
  dummytet[0] = encode(newtet);
  // At init, all faces of this tet are hull faces.
  hullsize = 4;

  // Put the rest of points into 'ptlink'.
  for (i = 3; i < floorptlist->len(); i++) {
    ptlink->add((point *)(* floorptlist)[i]);
  }
  for (i = 1; i < ceilptlist->len(); i++) {
    ptlink->add((point *)(* ceilptlist)[i]);
  }

  // Insert the rest of points of 'ptlink' into D.
  for (i = 0; i < ptlink->len(); i++) {
    ptloop = * (point *) ptlink->getnitem(i + 1);
    // Try to insert the point first.
    starttet.tet = dummytet; // Don't use locate().
    success = insertsite(ptloop, &starttet, false, flipqueue);
    assert(success != DUPLICATEPOINT);
    if (success == OUTSIDEPOINT) {
      // Point locates outside the convex hull. Mount it.
      inserthullsite(ptloop, &starttet, flipqueue, hulllink, worklist);
    }
    // Call flip algorithm to recover Delaunayness.
    flip(flipqueue, NULL, false, false, false);
  }

  // Have created the D. Gather the all new tetrahedra of D.
  decode(dummytet[0], starttet);
  infect(starttet);
  newtetlink->add(&starttet);
  for (i = 0; i < newtetlink->len(); i++) {
    starttet = * (triface *) newtetlink->getnitem(i + 1);
    for (starttet.loc = 0; starttet.loc < 4; starttet.loc++) {
      sym(starttet, neightet);
      if ((neightet.tet != dummytet) && !infected(neightet)) {
        infect(neightet);
        newtetlink->add(&neightet);
      }
    }
  }
  // Uninfect them.
  for (i = 0; i < newtetlink->len(); i++) {
    starttet = * (triface *) newtetlink->getnitem(i + 1);
    assert(infected(starttet));
    uninfect(starttet);
  }

  // Restore global variables.
  dummytet[0] = encode(bakhulltet);
  hullsize = bakhullsize;
  // Increase the debug level.
  b->verbose++;

  delete hulllink;
  delete ptlink;
  delete flipqueue;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// identifyfronts()    Identify faces of a cavity in a DT.                   //
//                                                                           //
// 'frontlink' is a list of faces bounded the cavity C.  The tetrahedra of D //
// are saved in 'newtetlink'.  This routine idnetifies each face of C in D.  //
// 'newfrontlink' saves the identified fronts in D corresponding to those of //
// 'frontlink'. Fronts saved in 'missceillist' are missing from D.           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::
identifyfronts(link* frontlink, link* newtetlink, link* newfrontlink,
               list* missceillist)
{
  triface front, starttet, spintet;
  face checksh;
  point pa, pb, pc;
  enum locateresult loc;
  enum finddirectionresult col;
  int hitbdry;
  int i;

  // Get a new tet for starting the search in D.
  recenttet = * (triface *) newtetlink->getnitem(1);
  
  // Identify the cavity faces in D.
  for (i = 0; i < frontlink->len(); i++) {
    // Get a cavity face f.
    front = * (triface *) frontlink->getnitem(i + 1);
    pa = org(front);
    pb = dest(front);
    pc = apex(front);
    if (b->verbose > 2) {
      printf("    Identifying front (%d, %d, %d).\n", pointmark(pa),
             pointmark(pb), pointmark(pc));
    }
    // Search for a tetrahedron containing vertex pa.
    starttet = recenttet;
    loc = preciselocate(pa, &starttet);
    assert(loc == ONVERTEX);
    // Search for a tetrahedron containing edge (pa, pb).
    col = finddirection(&starttet, pb);
    if (col == RIGHTCOLLINEAR) {
      // pb is just the destination.
    } else if (col == LEFTCOLLINEAR) {
      enext2self(starttet);
      esymself(starttet);
    } else if (col == TOPCOLLINEAR) {
      fnextself(starttet);
      enext2self(starttet);
      esymself(starttet);
    }
    if (dest(starttet) != pb) {
      // edge (pa, pb) doesn't exist. Front is missing.
      if (b->verbose > 2) {
        printf("    Edge (%d, %d, %d) not exists.\n", pointmark(pa),
               pointmark(pb), pointmark(pc));
      }
      // Get the tet inside the cavity C.
      symself(front);
      assert((front.tet != dummytet) && infected(front));
      // Put it into 'missceillist'.
      missceillist->append(&front);
      continue;
    }
    // Search for a tetrahedron containing face (pa, pb, pc).
    spintet = starttet;
    hitbdry = 0;
    do {
      if (apex(spintet) == pc) {
        // Find. The edge direction of 'spintet' may be reversed because of
        //   the hitting of boundary. Check it.
        if (org(spintet) != pa) {
          esymself(spintet);
        }
        starttet = spintet;
        break;
      }
      if (!fnextself(spintet)) {
        hitbdry ++;
        if (hitbdry < 2) {
          esym(starttet, spintet);
          if (!fnextself(spintet)) {
            hitbdry ++;
          }
        }
      }
      if (apex(spintet) == apex(starttet)) break;
    } while (hitbdry < 2);
    if (apex(starttet) != pc) {
      // Face (pa, pb, pc) doesn't exist.
      if (b->verbose > 2) {
        printf("    Face (%d, %d, %d) not exists.\n", pointmark(pa),
               pointmark(pb), pointmark(pc));
      }
      // Get the tet inside the cavity C.
      symself(front);
      assert((front.tet != dummytet) && infected(front));
      // Put it into 'missceillist'.
      missceillist->append(&front);
      continue;
    }
    // Save the handle for the next searching.
    recenttet = starttet;
    // Front is identified. Save the newfront.
    newfrontlink->add(&starttet);
  }

  if (missceillist->len() > 0) {
    // Fail to classify all fronts. Delete the new tets.
    for (i = 0; i < newtetlink->len(); i++) {
      starttet = * (triface *) newtetlink->getnitem(i + 1);
      tetrahedrondealloc(starttet.tet);
    }
    newtetlink->clear();
    newfrontlink->clear();
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// classifynewtets()    Classify new tets of D to be "inside" ot "outside".  //
//                                                                           //
// 'frontlink' is a list of faces bounded the cavity C.  The tetrahedra of D //
// are saved in 'newtetlink'. 'newfrontlink' is the list of identified faces //
// in D corresponding to 'frontlink'.                                        //
//                                                                           //
// For each identified face f, do the following: (1) Identify the inside and //
// outside of f and mark (infect) the outside tet (if it exists) for removal.//
// (2) Insert an auxilary subface s at f. s is simultaneously referenced by  //
// several tets that hold f: t1 - the tet not in D, t2 - the tet inside C,   //
// and t3 - the tet outside C (if it exists).  However s only points to t1 ( //
// i.e., the tet not in D).  It servers the link to bond t1 and t2 together  //
// later. If f is a subface, it is inserted directly. Otherwise, create and  //
// insert a 'fake' subface at f. It will be removed later.                   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::
classifynewtets(link* frontlink, link* newtetlink, link* newfrontlink)
{
  triface front, newfront, neightet;
  face checksh;
  point pa, pb, pc, pd;
  REAL ori;
  int i;

  assert(frontlink->len() == newfrontlink->len());
  for (i = 0; i < frontlink->len(); i++) {
    // Get a cavity face f.
    front = * (triface *) frontlink->getnitem(i + 1);
    // Let f face toward insde of the cavity. Since f is a face of tet
    //   adjacent to C. Hence choose the CW direction of f. 
    adjustedgering(front, CW);
    pa = org(front);
    pb = dest(front);
    pc = apex(front);
    // Get the correspond f in D.
    newfront = * (triface *) newfrontlink->getnitem(i + 1);
    // newfront may not the inside tet. Adjust it to be the inside one.
    pd = oppo(newfront);
    ori = orient3d(pa, pb, pc, pd);
    assert(ori != 0.0);
    if (ori > 0.0) {
      symself(newfront);
      assert(newfront.tet != dummytet);
    }
    // Insert an auxilary subface s at the place.
    // Is there already a subface? 
    tspivot(front, checksh);
    if (checksh.sh == dummysh) {
      // No. Create a 'fake' subface. It has no vertices.
      makeshellface(subfaces, &checksh);
      // Bond s and front (t1) together.
      tsbond(front, checksh);
    }
    // Bond s to newfront (t2) but not vice versa.
    sesymself(checksh);
    newfront.tet[8 + newfront.loc] = (tetrahedron) sencode(checksh);
    // Does the neighbor (t3) of newfront exists?
    sym(newfront, neightet);
    if (neightet.tet != dummytet) {
      // Bond s to neightet (t3) but not vice versa.
      sesymself(checksh);
      neightet.tet[8 + neightet.loc] = (tetrahedron) sencode(checksh);
      // Mark it to be "outside".
      infect(neightet);
    }
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// carvecavity()    Remove redundant (outside) tetrahedra from DT.           //
//                                                                           //
// All faces of the cavity C have been identified and protected by subfaces  //
// (may be faked) in DT. It's time to remove the outside tetrahedra and fill //
// the remaining (inside) tetrahedra into the CDT.                           //
//                                                                           //
// Notice that the "outside" tets may not only the tets on the convex hull   //
// but also tets inside the D - there is a "hole" in D. Since we have marked //
// all outside tets during identifycavity(). The hole tets are poped up and  //
// are removed too.                                                          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::carvecavity(link* newtetlink, list* newtetlist)
{
  triface starttet, neightet, front;
  face checksh, frontsh;
  point pointptr;
  int i;

  newtetlist->clear();
  // Some outside tets have been infected. Save them in 'newtetlist'.
  for (i = 0; i < newtetlink->len(); i++) {
    starttet = * (triface *) newtetlink->getnitem(i + 1);
    if (infected(starttet)) {
      newtetlist->append(&starttet);
    }
  }
  // Find and infect the rest of "outside" tetrahedra.
  for (i = 0; i < newtetlist->len(); i++) {
    starttet = * (triface *)(* newtetlist)[i];
    assert(infected(starttet));
    for (starttet.loc = 0; starttet.loc < 4; starttet.loc++) {
      sym(starttet, neightet);
      // Is neighbor exists and uninfected?
      if ((neightet.tet != dummytet) && !infected(neightet)) {
        // Yes. Is it protected by a subface?
        tspivot(starttet, checksh);
        if (checksh.sh == dummysh) {
          // No. It's an outside tet. Infect and save it.
          infect(neightet);
          newtetlist->append(&neightet);
        }
      }
    }
  }
  // Now remove the outside (and hole) tets.
  for (i = 0; i < newtetlink->len(); i++) {
    starttet = * (triface *) newtetlink->getnitem(i + 1);
    if (infected(starttet)) {
      // starttet is an "outside" tet.
      for (starttet.loc = 0; starttet.loc < 4; starttet.loc++) {
        // Is there a subface f?
        tspivot(starttet, checksh);
        if (checksh.sh != dummysh) {
          sym(starttet, neightet);
          // neightet must be an "inside" tet.
          assert(!infected(neightet));
          // Detach starttet from neightet.
          dissolve(neightet);
        }
      }
      // Dealloc the tet.
      tetrahedrondealloc(starttet.tet);
      // Remove the tet from newtetlink.
      newtetlink->del(i + 1);
      i--;
    }
  }
  // Clear the newtetlist for returning the inside tets.
  newtetlist->clear();

  // Now fill the inside tets into C. Remove fake subfaces and tets too.
  for (i = 0; i < newtetlink->len(); i++) {
    starttet = * (triface *) newtetlink->getnitem(i + 1);
    // Fill it into C.
    for (starttet.loc = 0; starttet.loc < 4; starttet.loc++) {
      // Is there a subface f?
      tspivot(starttet, checksh);
      if (checksh.sh != dummysh) {
        // Yes. Find the tet holds f.
        sesym(checksh, frontsh);
        stpivot(frontsh, front);
        assert((front.tet != dummytet) && !infected(front));
        // Either front or f may be fake, and can be both.
        if (sorg(checksh) == (point) NULL) {
          // Detach the fake subface from front and starttet.
          tsdissolve(front);
          tsdissolve(starttet);
          // Delete the fake subface.
          shellfacedealloc(subfaces, checksh.sh);
        } else {
          // Bond starttet to f.
          tsbond(starttet, checksh);
        }
        if (oppo(front) == (point) NULL) {
          // Detach the fake tet from this side. 
          if (!isdead(&frontsh)) {
            stdissolve(frontsh);
          }
          // Dealloc the fake tet.
          tetrahedrondealloc(front.tet);
          // This side becomes a hull. let 'dummytet' bond to it.
          dummytet[0] = encode(starttet);
        } else {
          // Bond front and starttet, also dissove the old bond in them.
          bond(starttet, front);
        }
      }
    }
    // Add it to the return list.
    starttet.loc = 0;
    newtetlist->append(&starttet);
    // Let the corners of starttet point to it for point searching.
    pointptr = org(starttet);
    setpoint2tet(pointptr, encode(starttet));
    pointptr = dest(starttet);
    setpoint2tet(pointptr, encode(starttet));
    pointptr = apex(starttet);
    setpoint2tet(pointptr, encode(starttet));
    pointptr = oppo(starttet);
    setpoint2tet(pointptr, encode(starttet));
  }
  // The cavity has been re-tetrahedralized.
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// delaunizecavity()    Triangulate a cavity by delaunizing its vertices.    //
//                                                                           //
// The cavity C is bounded by a set of triangles in 'floorlist' (a list of   //
// coplanar subfaces) and 'ceillist' (a list of tetrahedral faces lie above  //
// the subfaces). 'floorptlist' and 'ceilptlist' are vertices of 'floorlist' //
// and 'ceillist', respectively.  They form the set of vertices of C.        //
//                                                                           //
// The algorithm is simply desribed as follows: first form a Delaunay tetra- //
// hedralization D from the set of vertices of C; then mark each tetrahedron //
// of D to be "inside" and "outside"; finally, remove all tetrahedra marked  //
// as "outside".                                                             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::
delaunizecavity(list* floorlist, list* ceillist, list* floorptlist,
                list* ceilptlist, list* newtetlist, list* missceillist,
                int* worklist)
{
  link *frontlink, *newtetlink, *newfrontlink;

  if (b->verbose > 1) {
    printf("    Delaunizing cavity (%d floors, %d ceilings, %d vertices).\n",
           floorlist->len(), ceillist->len(), floorptlist->len() +
           ceilptlist->len());
  }

  // Save the size of the largest cavity.
  if ((floorlist->len() + ceillist->len()) > maxcavfaces) {
    maxcavfaces = floorlist->len() + ceillist->len();
  }
  if (floorptlist->len() + ceilptlist->len() > maxcavverts) {
    maxcavverts = floorptlist->len() + ceilptlist->len();
  }

  frontlink = new link(sizeof(triface), NULL, 256);
  newtetlink = new link(sizeof(triface), NULL, 256);
  newfrontlink = new link(sizeof(triface), NULL, 256);

  // Initialize the cavity C.
  initializecavity(floorlist, ceillist, frontlink);
  // Form the D of the vertices of C.
  delaunizevertices(floorptlist, ceilptlist, newtetlink, worklist);  
  // Identify faces of C in D.
  identifyfronts(frontlink, newtetlink, newfrontlink, missceillist);
  // Is there missing fronts in D?
  if (missceillist->len() == 0) {
    // No! Classify "inside" and "outside" tets in D.
    classifynewtets(frontlink, newtetlink, newfrontlink);
    // Remove the redundant tets in D and fill the rest to C.
    carvecavity(newtetlink, newtetlist);
  }

  delete frontlink;
  delete newtetlink;
  delete newfrontlink;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// formmissingregion()    Form the missing region.                           //
//                                                                           //
// 'missingsh' is a missing subface.  Start from it we can form the missing  //
// region R. Remember that all missing subfaces have been infected.  Other   //
// subfaces of R can be found by checking the neighbors of 'missingsh', and  //
// the neighbors of the neighbors, and so on. Stop checking further if       //
// either a segment or an uninfected subface is poped up.                    //
//                                                                           //
// 'missingshlist' returns subfaces of R, and these subfaces are oriented in //
// the same direction. 'equatptlist' returns vertices of R, and each vertex  //
// of R is marked with '1' (in 'worklist').                                  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::
formmissingregion(face* missingsh, list* missingshlist, list* equatptlist,
                  int* worklist)
{
  face neighsh, worksh, workseg;
  point workpt[3];
  int idx, i, j;

  // Add 'missingsh' into 'missingshlist'.
  missingshlist->append(missingsh);
  // Save and mark its three vertices.
  workpt[0] = sorg(*missingsh);
  workpt[1] = sdest(*missingsh);
  workpt[2] = sapex(*missingsh);
  for (i = 0; i < 3; i++) {
    idx = pointmark(workpt[i]) - in->firstnumber;
    worklist[idx] = 1;
    equatptlist->append(&workpt[i]);
  }
  // Temporarily uninfect it (avoid to save it again).
  suninfect(*missingsh);
  
  // Find the other missing subfaces.
  for (i = 0; i < missingshlist->len(); i++) {
    // Get a missing subface.
    worksh = * (face *)(* missingshlist)[i];
    // Check three neighbors of this face.
    for (j = 0; j < 3; j++) {
      sspivot(worksh, workseg);
      if (workseg.sh == dummysh) {
        spivot(worksh, neighsh);
        if (sinfected(neighsh)) {
          // Find a missing subface, adjust the face orientation.
          if (sorg(neighsh) != sdest(worksh)) {
            sesymself(neighsh);
          }
          if (b->verbose > 2) {
            printf("    Add missing subface (%d, %d, %d).\n", 
                   pointmark(sorg(neighsh)), pointmark(sdest(neighsh)),
                   pointmark(sapex(neighsh)));
          }
          missingshlist->append(&neighsh);
          // Save and mark its apex.
          workpt[0] = sapex(neighsh);
          idx = pointmark(workpt[0]) - in->firstnumber;
          // Has workpt[0] been added?
          if (worklist[idx] == 0) {
            worklist[idx] = 1;
            equatptlist->append(&workpt[0]);
          }
          // Temporarily uninfect it (avoid to save it again).
          suninfect(neighsh);
        } 
      } 
      senextself(worksh);
    }
  }

  // R has been formed. Infect missing subfaces again.
  for (i = 0; i < missingshlist->len(); i++) {
    worksh = * (face *)(* missingshlist)[i];
    sinfect(worksh);
  } 
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// scoutcrossingedge()    Search an edge crossing the missing region.        //
//                                                                           //
// 'missingshlist' forms the missing region R. This routine searches for an  //
// edge crossing R.  It first forms a 'boundedgelist' consisting of the      //
// boundary edges of R. Such edges are existing in CDT.  A crossing edge is  //
// found by rotating faces around one of the boundary edges. It is possible  //
// there is no edge crosses R (e.g. R has a degenerate point set).           //
//                                                                           //
// If find a croosing edge, return TRUE, 'crossedgelist' contains this edge. //
// Otherwise, return FALSE.                                                  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenmesh::
scoutcrossingedge(list* missingshlist, list* boundedgelist,
                  list* crossedgelist, int* worklist)
{
  triface starttet, spintet, worktet;
  face startsh, neighsh, worksh, workseg;
  point torg, tdest, tapex;
  point workpt[3], pa, pb, pc;
  enum finddirectionresult collinear;
  REAL ori1, ori2;
  bool crossflag;
  int hitbdry;
  int i, j, k;

  // Form the 'boundedgelist'. Loop through 'missingshlist', check each
  //   edge of these subfaces. If an edge is a segment or the neighbor
  //   subface is uninfected, add it to 'boundedgelist'.
  for (i = 0; i < missingshlist->len(); i++) {
    worksh = * (face *)(* missingshlist)[i];
    for (j = 0; j < 3; j++) {
      sspivot(worksh, workseg);
      if (workseg.sh == dummysh) {
        spivot(worksh, neighsh);
        if (!sinfected(neighsh)) {
          boundedgelist->append(&worksh);
        }
      } else {
        boundedgelist->append(&worksh);
      }
      senextself(worksh);
    }
  }

  crossflag = false;
  // Find a crossing edge. It is possible there is no such edge. We need to
  //   loop through all edges of 'boundedgelist' for sure we don't miss any.
  for (i = 0; i < boundedgelist->len() && !crossflag; i++) {
    startsh = * (face *)(* boundedgelist)[i];
    // 'startsh' (abc) holds an existing edge of the DT, find it.
    torg = sorg(startsh);
    tdest = sdest(startsh);
    tapex = sapex(startsh);
    getsearchtet(torg, tdest, &starttet, &workpt[0]);
    collinear = finddirection(&starttet, workpt[0]);
    if (collinear == LEFTCOLLINEAR) {
      enext2self(starttet);
      esymself(starttet);
    } else if (collinear == TOPCOLLINEAR) {
      fnextself(starttet);
      enext2self(starttet);
      esymself(starttet);
    }
    assert(dest(starttet) == workpt[0]);
    // Now starttet holds edge ab. Find is edge de crossing R.
    spintet = starttet;
    hitbdry = 0;
    do {
      if (fnextself(spintet)) {
        // splittet = abde. Check if de crosses abc.
        workpt[1] = apex(spintet);  // workpt[1] = d.
        workpt[2] = oppo(spintet);  // workpt[2] = e.
        j = pointmark(workpt[1]) - in->firstnumber;
        k = pointmark(workpt[2]) - in->firstnumber;
        if (worklist[j] == 1) {
          ori1 = 0.0; // d is a vertex of the missing region.
        } else {
          // Get the orientation of d wrt. abc.
          ori1 = orient3d(torg, tdest, tapex, workpt[1]);
        }
        if (worklist[k] == 1) {
          ori2 = 0.0; // e is a vertex of the missing region.
        } else {
          // Get the orientation of e wrt. abc.
          ori2 = orient3d(torg, tdest, tapex, workpt[2]);
        }
        // Only do check if d and e locate on different sides of abc.
        if (ori1 * ori2 < 0.0) {
          // Check if de crosses any subface of R.
          for (j = 0; j < missingshlist->len(); j++) {
            worksh = * (face *)(* missingshlist)[j];
            pa = sorg(worksh);
            pb = sdest(worksh);
            pc = sapex(worksh);
            crossflag = (tri_tri_inter(pa, pb, pc, workpt[0], workpt[1],
                                       workpt[2]) == INTERSECT);
            if (crossflag) {
              // Find a crossing edge. We're done.
              worktet = spintet;
              adjustedgering(worktet, CCW);
              enextfnextself(worktet);
              enextself(worktet);
              // Add this edge (worktet) into 'crossedgelist'.
              crossedgelist->append(&worktet);
              break;
            }
          }
          if (crossflag) break;
        }
        if (apex(spintet) == apex(starttet)) break;
      } else {
        hitbdry++;
        // It is only possible to hit boundary once.
        if (hitbdry < 2) {
          esym(starttet, spintet);
        }
      }
    } while (hitbdry < 2);
  }

  return crossflag;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// rearrangesubfaces()    Rearrange the set of subfaces of a missing region  //
//                        so that they conform to the faces of DT.           //
//                                                                           //
// The missing region formed by subfaces of 'missingshlist' contains a set   //
// of degenerate vertices, hence the set of subfaces don't match the set of  //
// faces in DT.  Instead of forcing them to present in DT, we re-arrange the //
// connection of them so that the new subfaces conform to the faces of DT.   //
// 'boundedgelist' is a set of boundary edges of the region, these edges(may //
// be subsegments) must exist in DT.                                         //
//                                                                           //
// On completion, we have created and inserted a set of new subfaces which   //
// conform to faces of DT. The set of old subfaces in 'missingshlist' are    //
// deleted. The region vertices in 'equatptlist' are unmarked.               //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::
rearrangesubfaces(list* missingshlist, list* boundedgelist, list* equatptlist,
                  int* worklist)
{
  link *boundedgelink;
  link *newshlink;
  triface starttet, spintet, neightet, worktet;
  face shloop, newsh, neighsh, spinsh, worksh;
  face workseg, casingin, casingout;
  point torg, tdest, workpt;
  point spt1, spt2, spt3;
  point liftpoint;
  enum finddirectionresult collinear;
  enum shestype shtype;
  REAL area;
  bool matchflag, finishflag;
  int shmark, idx, hitbdry;
  int i, j;

  // Initialize the boundary edge link.
  boundedgelink = new link(sizeof(face), NULL, 256);
  // Initialize the new subface link.
  newshlink = new link(sizeof(face), NULL, 256);
  // Remember the type (skinny or not) of replaced subfaces.  They should
  //   all have the same type since there is no segment inside the region.
  worksh = * (face *)(* missingshlist)[0];
  shtype = shelltype(worksh);
  // The following loop is only for checking purpose.
  for (i = 1; i < missingshlist->len(); i++) {
    worksh = * (face *)(* missingshlist)[i];
    assert(shelltype(worksh) == shtype);
  }

  // Create an initial boundary link.
  for (i = 0; i < boundedgelist->len(); i++) {
    shloop = * (face *)(* boundedgelist)[i];
    if (i == 0) {
      if (b->quality && varconstraint) {
        // area will be copied to all new created subfaces.
        area = areabound(shloop);
      }
      // 'shmark' will be set to all new created subfaces.
      shmark = shellmark(shloop);
      // Get the liftpoint of this facet for later checking.
      liftpoint = getliftpoint(shmark);
    }
    sspivot(shloop, workseg);
    if (workseg.sh == dummysh) {
      // This edge is an interior edge.
      spivot(shloop, neighsh);
      boundedgelink->add(&neighsh);
    } else {
      // This side has a segment, the edge exists. 
      boundedgelink->add(&shloop);
    }
  }

  // Each edge ab of boundedgelink will be finished by finding a vertex c
  //   which is a vertex of the missing region, such that:
  //   (1) abc is inside the missing region, i.e., abc intersects at least
  //       one of missing subfaces (saved in missingshlist);
  //   (2) abc is not intersect with any previously created new subfaces
  //       in the missing region (saved in newshlink).
  //   After abc is created, it will be inserted into both the surface mesh
  //   and the DT. The boundedgelink will be updated, ab is removed, bc and
  //   ca will be added if they are open.

  while (boundedgelink->len() > 0) {
    // Remove an edge (ab) from the link.
    shloop = * (face *) boundedgelink->del(1);
    // 'workseg' indicates it is a segment or not.
    sspivot(shloop, workseg);
    torg = sorg(shloop);  // torg = a;
    tdest = sdest(shloop);  // tdest = b; 
    // Find a tetrahedron containing ab.
    getsearchtet(torg, tdest, &starttet, &workpt);
    collinear = finddirection(&starttet, workpt);
    if (collinear == LEFTCOLLINEAR) {
      enext2self(starttet);
      esymself(starttet);
    } else if (collinear == TOPCOLLINEAR) {
      fnextself(starttet);
      enext2self(starttet);
      esymself(starttet);
    }
    assert(dest(starttet) == workpt);
    // Checking faces around ab until a valid face is found.
    matchflag = false;
    spintet = starttet;
    hitbdry = 0;
    do {
      workpt = apex(spintet);
      idx = pointmark(workpt) - in->firstnumber;
      if (worklist[idx] == 1) {
        // (trog, tdest, workpt) is on the facet. Check if it satisfies (1).
        finishflag = false;
        for (i = 0; i < missingshlist->len(); i++) {
          worksh = * (face *)(* missingshlist)[i];
          spt1 = sorg(worksh);
          spt2 = sdest(worksh);
          spt3 = sapex(worksh);
          // Does bc intersect the face?
          if (tri_edge_cop_inter(spt1, spt2, spt3, tdest, workpt, liftpoint)
              == INTERSECT) {
            finishflag = true; break;
          }
          // Does ca intersect the face?
          if (tri_edge_cop_inter(spt1, spt2, spt3, workpt, torg, liftpoint)
              == INTERSECT) {
            finishflag = true; break;
          }
          // Does c inside the face?
          if (tri_vert_cop_inter(spt1, spt2, spt3, workpt, liftpoint)
              == INTERSECT) {
            finishflag = true; break;
          }
        }
        if (finishflag) {
          // Satisfying (1). Check if it satisfies (2).
          matchflag = true;
          for (i = 0; i < newshlink->len() && matchflag; i++) {
            worksh = * (face *) newshlink->getnitem(i + 1);
            spt1 = sorg(worksh);
            spt2 = sdest(worksh);
            spt3 = sapex(worksh);
            // Does bc intersect the face?
            if (tri_edge_cop_inter(spt1, spt2, spt3, tdest, workpt, liftpoint)
                == INTERSECT) {
              matchflag = false; break;
            }
            // Does ca intersect the face?
            if (tri_edge_cop_inter(spt1, spt2, spt3, workpt, torg, liftpoint)
                == INTERSECT) {
              matchflag = false; break;
            }
            // Does c inside the face?
            if (tri_vert_cop_inter(spt1, spt2, spt3, workpt, liftpoint)
                == INTERSECT) {
              matchflag = false; break;
            }
          }
        }
        if (matchflag == true) {
          // Satisfying both (1) and (2). Find abc.
          break;
        }
      }
      if (!fnextself(spintet)) {
        hitbdry ++;
        if (hitbdry < 2) {
          esym(starttet, spintet);
          if (!fnextself(spintet)) {
            hitbdry ++;
          }
        }
      }
    } while (hitbdry < 2 && apex(spintet) != apex(starttet));
    assert(matchflag == true);
    tspivot(spintet, neighsh);
    if (neighsh.sh != dummysh) {
      printf("Error:  Invalid PLC.\n");
      printf("  Facet #%d and facet #%d overlap each other.\n",
             shellmark(neighsh), shellmark(shloop));
      printf("  It might be caused by a facet is defined more than once.\n");
      printf("  Hint:  Use -d switch to find all overlapping facets.\n");
      exit(1);
    }
    // The side of 'spintet' is at which a new subface will be attached.
    adjustedgering(spintet, CCW);
    // Create the new subface.
    makeshellface(subfaces, &newsh);
    setsorg(newsh, org(spintet));
    setsdest(newsh, dest(spintet));
    setsapex(newsh, apex(spintet));
    if (b->quality && varconstraint) {
      // Copy the areabound into the new subface.
      setareabound(newsh, area);
    }
    setshellmark(newsh, shmark);
    setshelltype(newsh, shtype);  // It may be a skinny subface.
    // Add newsh into newshlink for intersecting checking.
    newshlink->add(&newsh);
    // Insert it into the current mesh.
    tsbond(spintet, newsh);
    sym(spintet, neightet);
    if (neightet.tet != dummytet) {
      sesym(newsh, neighsh);
      tsbond(neightet, neighsh);
    }
    // Insert it into the surface mesh.
    sspivot(shloop, workseg);
    if (workseg.sh == dummysh) {
      sbond(shloop, newsh);
    } else {
      // There is a subsegment, 'shloop' is the subface which is going to
      //   die. Insert the 'newsh' at the place of 'shloop' into its face
      //   link, so as to dettach 'shloop'.   The original connection is:
      //   -> casingin -> shloop -> casingout ->, it will be changed with:
      //   -> casingin ->  newsh -> casingout ->.  Pay attention to the
      //   case when this subsegment is dangling in the mesh, i.e., 'shloop'
      //   is bonded to itself.
      spivot(shloop, casingout);
      if (shloop.sh != casingout.sh) {
        // 'shloop' is not bonded to itself.
        spinsh = casingout;
        do {
          casingin = spinsh;
          spivotself(spinsh);
        } while (sapex(spinsh) != sapex(shloop));
        assert(casingin.sh != shloop.sh); 
        // Bond casingin -> newsh -> casingout.
        sbond1(casingin, newsh);
        sbond1(newsh, casingout);
      } else {
        // Bond newsh -> newsh.
        sbond(newsh, newsh);
      }
      // Bond the segment.
      ssbond(newsh, workseg);
    }
    // Check other two sides of this new subface.  If a side is not bonded
    //   to any edge in the link, it will be added to the link.
    for (i = 0; i < 2; i++) {
      if (i == 0) {
        senext(newsh, worksh);
      } else {
        senext2(newsh, worksh);
      }
      torg = sorg(worksh);
      tdest = sdest(worksh);
      finishflag = false;
      for (j = 0; j < boundedgelink->len() && !finishflag; j++) {
        neighsh = * (face *) boundedgelink->getnitem(j + 1);
        if ((sorg(neighsh) == torg && sdest(neighsh) == tdest) ||
            (sorg(neighsh) == tdest && sdest(neighsh) == torg)) {
          // Find a boundary edge.  Bond them and exit the loop.
          sspivot(neighsh, workseg);
          if (workseg.sh == dummysh) {
            sbond(neighsh, worksh);
          } else {
            // There is a subsegment, 'neighsh' is the subface which is
            //   going to die. Do the same as above for 'worksh'.
            spivot(neighsh, casingout);
            if (neighsh.sh != casingout.sh) {
              // 'neighsh' is not bonded to itself.
              spinsh = casingout;
              do {
                casingin = spinsh;
                spivotself(spinsh);
              } while (sapex(spinsh) != sapex(neighsh));
              assert(casingin.sh != neighsh.sh); 
              // Bond casingin -> worksh -> casingout.
              sbond1(casingin, worksh);
              sbond1(worksh, casingout);
            } else {
              // Bond worksh -> worksh.
              sbond(worksh, worksh);
            }
            // Bond the segment.
            ssbond(worksh, workseg);
          }
          // Remove this boundary edge from the link.
          boundedgelink->del(j + 1);
          finishflag = true;
        }
      }
      if (!finishflag) {
        // It's a new boundary edge, add it to link.
        boundedgelink->add(&worksh);
      }
    }
  }

  // Deallocate the set of old missing subfaces.
  for (i = 0; i < missingshlist->len(); i++) {
    worksh = * (face *)(* missingshlist)[i];
    shellfacedealloc(subfaces, worksh.sh);
  }
  // Unmark region vertices in 'worklist'.
  for (i = 0; i < equatptlist->len(); i++) {
    workpt = * (point *)(* equatptlist)[i];
    idx = pointmark(workpt) - in->firstnumber;
    worklist[idx] = 0;
  }

  delete boundedgelink;
  delete newshlink;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// formcavity()    Form the cavity for recovering missing subfaces.          //
//                                                                           //
// The cavity C is bounded by faces of current CDT.  All tetrahedra inside C //
// will be removed, intead a set of constrained Delaunay tetrahedra will be  //
// filled in and the missing subfaces are respected.                         //
//                                                                           //
// 'missingshlist' contains a set of subfaces forming the missing region R.  //
// C is formed by first finding all the tetrahedra in CDT that intersect the //
// relative interior of R; then deleting them from the CDT, this will form C //
// inside the CDT. At the beginning, 'crossedgelist' contains an edge which  //
// is crossing R. All tets containing this edge must cross R. Start from it, //
// other crossing edges can be found incrementally.  The discovered crossing //
// tets are saved in 'crosstetlist'.                                         //
//                                                                           //
// Notice that not all tets in 'crosstetlist' are crossing R. The discovered //
// tets are connected each other. However, there may be other tets crossing  //
// R but disjoint with the found tets. Due to this fact we need to check the //
// 'missingshlist' once more. Only recover those subfaces which are crossed  //
// by the set of discovered tets, i.e., R may be shrinked to conform the set //
// of discovered tets. The extra subfaces of R will be recovered later.      //
//                                                                           //
// Notice that some previous recovered subfaces may completely included in C.//
// This can happen when R is very big and these subfaces lie above R and so  //
// close to it. Such subfaces have to be queued (and sinfected()) to recover //
// them later. Otherwise, we lost the connection to these subfaces forever.  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::
formcavity(list* missingshlist, list* crossedgelist, list* equatptlist,
           list* crossshlist, list* crosstetlist, list* belowfacelist,
           list* abovefacelist, list* horizptlist, list* belowptlist,
           list* aboveptlist, queue* missingshqueue, int* worklist)
{
  triface starttet, spintet, neightet, worktet;
  face startsh, neighsh, worksh, workseg;
  point torg, tdest, tapex, workpt[3];
  REAL checksign, orgori, destori;
  bool crossflag, inlistflag;
  bool belowflag, aboveflag;
  int idx, share;
  int i, j, k;

  // Get a face at horizon.
  startsh = * (face *)(* missingshlist)[0];
  torg = sorg(startsh);
  tdest = sdest(startsh);
  tapex = sapex(startsh);

  // Collect the set of crossing tetrahedra by rotating crossing edges.
  for (i = 0; i < crossedgelist->len(); i++) {
    // Get a tet abcd, ab is a crossing edge.
    starttet = * (triface *)(* crossedgelist)[i];
    adjustedgering(starttet, CCW);
    if (b->verbose > 2) {
      printf("    Collect tets containing edge (%d, %d).\n",
             pointmark(org(starttet)), pointmark(dest(starttet)));
    }
    orgori = orient3d(torg, tdest, tapex, org(starttet));
    destori = orient3d(torg, tdest, tapex, dest(starttet));
    assert(orgori * destori < 0.0); 
    spintet = starttet;
    do {
      // The face rotation should not meet boundary.
      fnextself(spintet); 
      // Check the validity of the PLC.
      tspivot(spintet, worksh);
      if (worksh.sh != dummysh) {
        printf("Error:  Invalid PLC.\n");
        printf("  Two subfaces (%d, %d, %d) and (%d, %d, %d)\n",
               pointmark(torg), pointmark(tdest), pointmark(tapex),
               pointmark(sorg(worksh)), pointmark(sdest(worksh)),
               pointmark(sapex(worksh)));
        printf("  are found intersecting each other.\n");
        printf("  Hint:  Use -d switch to find all intersecting facets.\n");
        exit(1);
      }
      if (!infected(spintet)) {
        if (b->verbose > 2) {
          printf("      Add crossing tet (%d, %d, %d, %d).\n",
                 pointmark(org(spintet)), pointmark(dest(spintet)),
                 pointmark(apex(spintet)), pointmark(oppo(spintet)));
        }
        infect(spintet);
        crosstetlist->append(&spintet);
      }
      // Check whether other two edges of 'spintet' is a crossing edge.
      //   It can be quickly checked from the apex of 'spintet', if it is
      //   not on the facet, then there exists a crossing edge.
      workpt[0] = apex(spintet);
      idx = pointmark(workpt[0]) - in->firstnumber;
      if (worklist[idx] != 1) {
        // Either edge (dest, apex) or edge (apex, org) crosses.
        checksign = orient3d(torg, tdest, tapex, workpt[0]);
        assert(checksign != 0.0);
        if (checksign * orgori < 0.0) {
          enext2(spintet, worktet); // edge (apex, org).
          workpt[1] = org(spintet);
        } else {
          assert(checksign * destori < 0.0);
          enext(spintet, worktet);  // edge (dest, apex).
          workpt[1] = dest(spintet);
        }
        // 'worktet' represents the crossing edge. Add it into list only
        //   it doesn't exist in 'crossedgelist'.
        inlistflag = false;
        for (j = 0; j < crossedgelist->len() && !inlistflag; j++) {
          neightet = * (triface *)(* crossedgelist)[j];
          if (org(neightet) == workpt[0]) {
            if (dest(neightet) == workpt[1]) inlistflag = true;
          } else if (org(neightet) == workpt[1]) {
            if (dest(neightet) == workpt[0]) inlistflag = true;
          }
        }
        if (!inlistflag) {
          crossedgelist->append(&worktet);
        }
      }
    } while (apex(spintet) != apex(starttet));
  }

  // Identifying the boundary faces and vertices of C. Sort them into
  //   'abovefacelist', 'aboveptlist, 'belowfacelist', and 'belowptlist',
  //    respectively. "above" and "below" are wrt.(torg, tdest, tapex). 
  for (i = 0; i < crosstetlist->len(); i++) {
    // Get a tet abcd, ab is the crossing edge.
    starttet = * (triface *)(* crosstetlist)[i];
    assert(infected(starttet));
    adjustedgering(starttet, CCW);
    // abc and abd are sharing the crossing edge, the two neighbors must
    //   be crossing tetrahedra too. They can't be boundaries of C.
    for (j = 0; j < 2; j++) {
      if (j == 0) {
        enextfnext(starttet, worktet); // Check bcd.
      } else {
        enext2fnext(starttet, worktet); // Check acd. 
      } 
      sym(worktet, neightet);
      // If the neighbor doesn't exist or exists but doesn't be infected,
      //   it's a boundary face of C, save it.
      if ((neightet.tet == dummytet) || !infected(neightet)) {
        workpt[0] = org(worktet);
        workpt[1] = dest(worktet);
        workpt[2] = apex(worktet);
        belowflag = aboveflag = false;
        share = 0;
        for (k = 0; k < 3; k++) {
          idx = pointmark(workpt[k]) - in->firstnumber;
          if (worklist[idx] == 0) {
            // It's not a vertices of facet, find which side it lies.
            checksign = orient3d(torg, tdest, tapex, workpt[k]);
            assert(checksign != 0.0);
            if (checksign > 0.0) {
              // It lies "below" the facet wrt. 'startsh'.
              worklist[idx] = 2;
              belowptlist->append(&workpt[k]);
            } else if (checksign < 0.0) {
              // It lies "above" the facet wrt. 'startsh'.
              worklist[idx] = 3;
              aboveptlist->append(&workpt[k]);
            }
          }
          if (worklist[idx] == 2) {
            // This face lies "below" the facet wrt. 'startsh'.
            belowflag = true;
          } else if (worklist[idx] == 3) {
            // This face lies "above" the facet wrt. 'startsh'.
            aboveflag = true;
          } else {
            // In degenerate case, this face may just be the equator.
            assert(worklist[idx] == 1);
            share++;
          }
        }
        // The degenerate case has been ruled out.
        assert(share < 3);
        // Only one flag is possible for a cavity face.
        assert(belowflag ^ aboveflag); 
        if (belowflag) {
          belowfacelist->append(&worktet);
        } else if (aboveflag) {
          abovefacelist->append(&worktet);
        }
      }
    }
  }

  // Shrink R if not all its subfaces are crossing by the discovered tets.
  //   'crossshlist' and 'horizptlist' represent the set of subfaces and
  //   vertices of the shrinked missing region, respectively.
  for (i = 0; i < missingshlist->len(); i++) {
    worksh = * (face *)(* missingshlist)[i];
    assert(sinfected(worksh));
    workpt[0] = sorg(worksh);
    workpt[1] = sdest(worksh);
    workpt[2] = sapex(worksh);
    crossflag = false;
    for (j = 0; j < crosstetlist->len() && !crossflag; j++) {
      // Get a tet abcd, ab is a crossing edge.
      starttet = * (triface *)(* crosstetlist)[j];
      adjustedgering(starttet, CCW);
      // Only need to check two sides of worktet.
      for (k = 0; k < 2 && !crossflag; k++) {
        if (k == 0) {
          worktet = starttet; // Check abc.
        } else {
          fnext(starttet, worktet); // Check abd.
        }
        crossflag = tritritest(&worktet, workpt[0], workpt[1], workpt[2]);
      }
    }
    if (crossflag) {
      // 'worksh' is crossed by 'worktet', uninfect it.
      suninfect(worksh);
      crossshlist->append(&worksh);
      // Add its corners into 'horizptlist'.
      for (k = 0; k < 3; k++) {
        idx = pointmark(workpt[k]) - in->firstnumber;
        if (worklist[idx] != 4) {
          worklist[idx] = 4;
          horizptlist->append(&workpt[k]);
        }
      }
    } 
  }

  // Check 'crossingtetlist'. Queue subfaces inside them.
  for (i = 0; i < crosstetlist->len(); i++) {
    starttet = * (triface *)(* crosstetlist)[i];
    for (starttet.loc = 0; starttet.loc < 4; starttet.loc++) {
      sym(starttet, neightet);
      // If the neighbor exist and is infected, check it.
      if ((neightet.tet != dummytet) && infected(neightet)) {
        tspivot(starttet, worksh);
        if (worksh.sh != dummysh) {
          // Temporarily remove worksh. Make it missing. recover it later.
          if (b->verbose > 2) {
            printf("    Queuing subface (%d, %d, %d).\n",
                   pointmark(sorg(worksh)), pointmark(sdest(worksh)),
                   pointmark(sapex(worksh)));
          }
          tsdissolve(neightet);
          tsdissolve(starttet);
          // Detach tets at the both sides of this subface.
          stdissolve(worksh);
          sesymself(worksh);
          stdissolve(worksh);
          sinfect(worksh);
          missingshqueue->push(&worksh);
        }
      }
    }
  }

  // Clear flags set in 'worklist'.
  for (i = 0; i < equatptlist->len(); i++) {
    workpt[0] = * (point *)(* equatptlist)[i];
    idx = pointmark(workpt[0]) - in->firstnumber;
    assert((worklist[idx] == 1) || (worklist[idx] == 4));
    worklist[idx] = 0;
  }
  for (i = 0; i < belowptlist->len(); i++) {
    workpt[0] = * (point *)(* belowptlist)[i];
    idx = pointmark(workpt[0]) - in->firstnumber;
    assert(worklist[idx] == 2);
    worklist[idx] = 0;
  }
  for (i = 0; i < aboveptlist->len(); i++) {
    workpt[0] = * (point *)(* aboveptlist)[i];
    idx = pointmark(workpt[0]) - in->firstnumber;
    assert(worklist[idx] == 3);
    worklist[idx] = 0;
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// enlargecavity()    Enlarge the cavity by expanding the faces on ceil.     //
//                                                                           //
// 'missceillist' contains missing faces of the cavity C in D.  These faces  //
// will be removed from 'ceillist', instead new faces will be added.         //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::
enlargecavity(list* missceillist, list* ceillist, list* ceilptlist,
              list* floorptlist, list* crosstetlist, queue* missingshqueue,
              int* worklist)
{
  triface missceil, neightet, newceil;
  triface neineitet, worktet;
  face checksh;
  point pd;
  int i, j, k;

  if (b->verbose > 1) {
    printf("    Enlarge cavity (%d missing faces).\n", missceillist->len());
  }

  // Increase the number of enlarged cavities.
  enlcavtimes++;

  // Mark all vertices in 'floorptlist'.
  for (i = 0; i < floorptlist->len(); i++) {
    pd = * (point *)(* floorptlist)[i];
    worklist[pointmark(pd)] = 1;
  }
  // Mark all vertices in 'ceilptlist'.
  for (i = 0; i < ceilptlist->len(); i++) {
    pd = * (point *)(* ceilptlist)[i];
    worklist[pointmark(pd)] = 2;
  }

  // Loop through 'missceillist'.
  for (i = 0; i < missceillist->len(); i++) {
    // Get a missing front f.
    missceil = * (triface *)(* missceillist)[i];
    // f is the face of a tet inside C. 
    assert(infected(missceil));
    // f is no longer a front face, delete it from 'ceillist'.
    for (j = 0; j < ceillist->len(); j++) {
      worktet = * (triface *)(* ceillist)[j];
      if ((missceil.tet == worktet.tet) && (missceil.loc == worktet.loc)) {
        ceillist->del(j);
        break;
      }
    }
    // Get the neighbor tet (adjacent to C) at f.
    sym(missceil, neightet);
    // The neighbor may have been added in C.
    pd = oppo(neightet);
    // It shouldn't be a 'fake' tet.
    assert(pd != (point) NULL);
    j = pointmark(pd);
    // Is pd in list?
    if ((worklist[j] != 1) && (worklist[j] != 2)) {
      // pd is a new ceil point. Add it into 'ceilptlist'.
      worklist[j] = 2;
      ceilptlist->append(&pd);
    }
    // Is f a subface?
    tspivot(neightet, checksh);
    if (checksh.sh != dummysh) {
      // Temporarily remove checksh. Make it missing. recover it later.
      if (b->verbose > 2) {
        printf("    Queuing subface (%d, %d, %d).\n",
               pointmark(sorg(checksh)), pointmark(sdest(checksh)),
               pointmark(sapex(checksh)));
      }
      tsdissolve(neightet);
      tsdissolve(missceil);
      // Detach tets at the both sides of checksh.
      stdissolve(checksh);
      sesymself(checksh);
      stdissolve(checksh);
      sinfect(checksh);
      missingshqueue->push(&checksh);
    }
    // Enlarge the cavity by adding three sides of the neightet.
    adjustedgering(neightet, CCW);
    for (j = 0; j < 3; j++) {
      fnext(neightet, newceil);
      sym(newceil, neineitet);
      // Is neineitet inside C?
      if (!infected(neineitet)) {
        // No. newceil becomes a front.
        ceillist->append(&newceil);
      } else {
        // Yes. neineitet is not a front anymore. remove it from ceillist.
        for (k = 0; k < ceillist->len(); k++) {
          worktet = * (triface *)(* ceillist)[k];
          if ((neineitet.tet == worktet.tet) &&
              (neineitet.loc == worktet.loc)) {
            ceillist->del(k);
            break;
          }
        }
        // Is newceil a subface?
        tspivot(newceil, checksh);
        if (checksh.sh != dummysh) {
          // Temporarily remove checksh. Make it missing. recover it later.
          if (b->verbose > 2) {
            printf("    Queuing subface (%d, %d, %d).\n",
                   pointmark(sorg(checksh)), pointmark(sdest(checksh)),
                   pointmark(sapex(checksh)));
          }
          tsdissolve(neineitet);
          tsdissolve(newceil);
          // Detach tets at the both sides of checksh.
          stdissolve(checksh);
          sesymself(checksh);
          stdissolve(checksh);
          sinfect(checksh);
          missingshqueue->push(&checksh);
        }
      }
      enextself(neightet);
    }
    // neightet may have already been queued.
    if (!infected(neightet)) {
      // neightet beomes a cavity tet, will be removed later.
      infect(neightet);
      crosstetlist->append(&neightet);
    }
  }

  // Unmark all vertices in 'floorptlist'.
  for (i = 0; i < floorptlist->len(); i++) {
    pd = * (point *)(* floorptlist)[i];
    worklist[pointmark(pd)] = 0;
  }
  // Unmark all vertices in 'ceilptlist'.
  for (i = 0; i < ceilptlist->len(); i++) {
    pd = * (point *)(* ceilptlist)[i];
    worklist[pointmark(pd)] = 0;
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// insertallsubfaces()    Insert all subfaces, queue missing subfaces.       //
//                                                                           //
// Loop through all subfaces, insert each into the DT. If one already exists,//
// bond it to the tetrahedra having it. Otherwise, it is missing, infect it  //
// and save it in 'missingshqueue'.                                          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::insertallsubfaces(queue* missingshqueue)
{
  triface searchtet;
  face subloop;

  searchtet.tet = (tetrahedron *) NULL;
  subfaces->traversalinit();
  subloop.sh = shellfacetraverse(subfaces);
  while (subloop.sh != (shellface *) NULL) {
    if (!insertsubface(&subloop, &searchtet)) {
      if (b->verbose > 1) {
        printf("    Queuing subface (%d, %d, %d).\n", pointmark(sorg(subloop)),
               pointmark(sdest(subloop)), pointmark(sapex(subloop)));
      }
      sinfect(subloop);
      missingshqueue->push(&subloop);
    }
    subloop.sh = shellfacetraverse(subfaces);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// constrainedfacets()    Recover subfaces in a Delaunay tetrahedralization. //
//                                                                           //
// This routine creates a CDT by incrementally updating a DT D into a CDT T. //
// The process of recovering facets can be imagined by "merging" the surface //
// mesh F into D. At the beginning, F and D are completely seperated.  Some  //
// faces of them are matching some are not because they are crossed by some  //
// tetrahedra of D. The non-matching subfaces will be forced to appear in T  //
// by locally retetrahedralizing the regions where F and D are intersecting. //
//                                                                           //
// When a subface s of F is found missing in D, probably some other subfaces //
// near to s are missing too.  The set of adjoining coplanar missing faces   //
// forms a missing region R (R may not simply connected).                    //
//                                                                           //
// There are two possibilities can result a mssing region R: (1) Some edges  //
// of D cross R; (2) No edge of D crosses R, but some faces of D spans R, ie,//
// D is locally degenerate at R. In case (1), D is modified so that it resp- //
// ects R (done by a cavity retetrahedralization algorithm).  In case (2), F //
// is modified so that the set of subfaces of R matches faces in D (done by  //
// a face rearrangment algorithm).                                           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::constrainedfacets()
{
  queue *missingshqueue;
  list *missingshlist, *equatptlist;
  list *boundedgelist, *crossedgelist, *crosstetlist;
  list *crossshlist, *belowfacelist, *abovefacelist;
  list *horizptlist, *belowptlist, *aboveptlist;
  list *newtetlist, *missceillist;
  triface searchtet, worktet;
  face subloop, worksh;
  int *worklist;
  int i;

  if (!b->quiet) {
    printf("Constraining facets.\n");
  }

  // Initialize the queue.
  missingshqueue = new queue(sizeof(face));
  // Initialize the working lists.
  missingshlist = new list(sizeof(face), NULL);
  boundedgelist = new list(sizeof(face), NULL);
  crossedgelist = new list(sizeof(triface), NULL);
  equatptlist = new list("point *");
  crossshlist = new list(sizeof(face), NULL);
  crosstetlist = new list(sizeof(triface), NULL);
  belowfacelist = new list(sizeof(triface), NULL);
  abovefacelist = new list(sizeof(triface), NULL);
  horizptlist = new list("point *");
  belowptlist = new list("point *");
  aboveptlist = new list("point *");
  newtetlist = new list(sizeof(triface), NULL);
  missceillist = new list(sizeof(triface), NULL);
  // Initialize the array for marking vertices.
  worklist = new int[points->items + 1];
  for (i = 0; i < points->items + 1; i++) worklist[i] = 0;

  // Compute a mapping from points to tetrahedra for fast searching.
  makepoint2tetmap();
  
  // Match subfaces in D, queue all missing subfaces.
  insertallsubfaces(missingshqueue);

  // Recover all missing subfaces.
  while (!missingshqueue->empty()) {
    // Get a queued face s.
    subloop = * (face *) missingshqueue->pop();
    // s may have been deleted in a face rearrangment operation.
    if (isdead(&subloop)) continue;
    // s may have been recovered in a previous missing region.
    if (!sinfected(subloop)) continue;
    // s may match a face in D now due to previous transformations.
    if (insertsubface(&subloop, &searchtet)) {
      suninfect(subloop);
      continue;
    }
    if (b->verbose > 1) {
      printf("    Recover subface (%d, %d, %d).\n", pointmark(sorg(subloop)),
             pointmark(sdest(subloop)), pointmark(sapex(subloop)));
    }
    // Form the missing region R containing s.
    formmissingregion(&subloop, missingshlist, equatptlist, worklist);
    // Is R crossing by any tetrahedron?
    if (scoutcrossingedge(missingshlist, boundedgelist, crossedgelist,
                          worklist)) {
      // Form the cavity C containing R.
      formcavity(missingshlist, crossedgelist, equatptlist, crossshlist,
                 crosstetlist, belowfacelist, abovefacelist, horizptlist,
                 belowptlist, aboveptlist, missingshqueue, worklist);
      // Recover the above part of C.
      do {
        delaunizecavity(crossshlist, abovefacelist, horizptlist, aboveptlist,
                        newtetlist, missceillist, worklist);
        if (missceillist->len() > 0) {
          // There're unrecovered faces. Enlarge the above part of C.
          enlargecavity(missceillist, abovefacelist, aboveptlist, horizptlist,
                        crosstetlist, missingshqueue, worklist);
          missceillist->clear();
          continue;
        }
        break;
      } while (true);
      // Inverse the direction of subfaces in R.
      for (i = 0; i < crossshlist->len(); i++) {
        worksh = * (face *)(* crossshlist)[i];
        sesymself(worksh);
        * (face *)(* crossshlist)[i] = worksh;
      }
      // Recover the below part of C.
      do {
        delaunizecavity(crossshlist, belowfacelist, horizptlist, belowptlist,
                        newtetlist, missceillist, worklist);
        if (missceillist->len() > 0) {
          // There're unrecovered faces. Enlarge the lower part of C.
          enlargecavity(missceillist, belowfacelist, belowptlist, horizptlist,
                        crosstetlist, missingshqueue, worklist);
          missceillist->clear();
          continue;
        }
        break;
      } while (true);
      // Delete tetrahedra in C.
      for (i = 0; i < crosstetlist->len(); i++) {
        worktet = * (triface *)(* crosstetlist)[i];
        tetrahedrondealloc(worktet.tet);
      }
      // There may have some un-recovered subfaces of R. Put them back into
      //   queue. Otherwise, they will be missing on the boundary.
      for (i = 0; i < missingshlist->len(); i++) {
        worksh = * (face *)(* missingshlist)[i];
        if (sinfected(worksh)) {
          // An unrecovered subface, put it back into queue.
          missingshqueue->push(&worksh);
        }
      }
      crossshlist->clear();
      crosstetlist->clear();
      belowfacelist->clear();
      abovefacelist->clear();
      horizptlist->clear();
      belowptlist->clear();
      aboveptlist->clear();
      newtetlist->clear();
    } else {
      // No. Rearrange subfaces of F conforming to that of D in R.
      rearrangesubfaces(missingshlist, boundedgelist, equatptlist, worklist);
    }
    // Clear all working lists.
    missingshlist->clear();
    boundedgelist->clear();
    crossedgelist->clear();
    equatptlist->clear();
  }

  // Subfaces have been merged into D.
  checksubfaces = 1;

  if (b->verbose) {
    printf("  The biggest cavity: %d faces, %d vertices\n", maxcavfaces,
           maxcavverts);
    printf("  Enlarged %d times\n", enlcavtimes);
  }

  delete missingshqueue;
  delete missingshlist;
  delete boundedgelist;
  delete crossedgelist;
  delete equatptlist;
  delete crossshlist;
  delete crosstetlist;
  delete belowfacelist;
  delete abovefacelist;
  delete horizptlist;
  delete belowptlist;
  delete aboveptlist;
  delete newtetlist;
  delete missceillist;
  delete [] worklist;
}

//
// End of facet recovery routines
//

//
// Begin of carving out holes and concavities routines
//

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// infecthull()    Virally infect all of the tetrahedra of the convex hull   //
//                 that are not protected by subfaces.  Where there are      //
//                 subfaces, set boundary markers as appropriate.            //
//                                                                           //
// Memorypool 'viri' is used to return all the infected tetrahedra.          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::infecthull(memorypool *viri)
{
  triface tetloop, tsymtet;
  tetrahedron **deadtet;
  face hullface;
  // point horg, hdest, hapex;

  if (b->verbose) {
    printf("  Marking concavities for elimination.\n");
  }
  tetrahedrons->traversalinit();
  tetloop.tet = tetrahedrontraverse();
  while (tetloop.tet != (tetrahedron *) NULL) {
    // Is this tetrahedron on the hull?
    for (tetloop.loc = 0; tetloop.loc < 4; tetloop.loc++) {
      sym(tetloop, tsymtet);
      if (tsymtet.tet == dummytet) {
        // Is the tetrahedron protected by a subface?
        tspivot(tetloop, hullface);
        if (hullface.sh == dummysh) {
          // The tetrahedron is not protected; infect it.
          if (!infected(tetloop)) {
            infect(tetloop);
            deadtet = (tetrahedron **) viri->alloc();
            *deadtet = tetloop.tet;
            break;  // Go and get next tet.
          }
        } else {
          // The tetrahedron is protected; set boundary markers if appropriate.
          if (shellmark(hullface) == 0) {
            setshellmark(hullface, 1);
            /*
            horg = sorg(hullface);
            hdest = sdest(hullface);
            hapex = sapex(hullface);
            if (pointmark(horg) == 0) {
              setpointmark(horg, 1);
            }
            if (pointmark(hdest) == 0) {
              setpointmark(hdest, 1);
            }
            if (pointmark(hapex) == 0) {
              setpointmark(hapex, 1);
            }
            */
          }
        }
      }
    }
    tetloop.tet = tetrahedrontraverse();
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// plague()    Spread the virus from all infected tets to any neighbors not  //
//             protected by subfaces.                                        //
//                                                                           //
// This routine identifies all the tetrahedra that will die, and marks them  //
// as infected.  They are marked to ensure that each tetrahedron is added to //
// the virus pool only once, so the procedure will terminate. 'viri' returns //
// all infected tetrahedra which are outside the domian.                     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::plague(memorypool *viri)
{
  tetrahedron **virusloop;
  tetrahedron **deadtet;
  triface testtet, neighbor;
  face neighsh, testseg;
  face spinsh, casingin, casingout;
  int i;

  if (b->verbose) {
    printf("  Marking neighbors of marked tetrahedra.\n");
  }
  // Loop through all the infected tetrahedra, spreading the virus to
  //   their neighbors, then to their neighbors' neighbors.
  viri->traversalinit();
  virusloop = (tetrahedron **) viri->traverse();
  while (virusloop != (tetrahedron **) NULL) {
    testtet.tet = *virusloop;
    // Temporarily uninfect this tetrahedron, not necessary.
    uninfect(testtet);
    // Check each of the tetrahedron's four neighbors.
    for (testtet.loc = 0; testtet.loc < 4; testtet.loc++) {
      // Find the neighbor.
      sym(testtet, neighbor);
      // Check for a shell between the tetrahedron and its neighbor.
      tspivot(testtet, neighsh);
      // Check if the neighbor is nonexistent or already infected.
      if ((neighbor.tet == dummytet) || infected(neighbor)) {
        if (neighsh.sh != dummysh) {
          // There is a subface separating the tetrahedron from its neighbor,
          //   but both tetrahedra are dying, so the subface dies too.
          // Before deallocte this subface, dissolve the connections between
          //   other subfaces, subsegments and tetrahedra.
          neighsh.shver = 0;
          // For keep the same enext() direction.
          findedge(&testtet, sorg(neighsh), sdest(neighsh));
          for (i = 0; i < 3; i++) {
            sspivot(neighsh, testseg);
            if (testseg.sh != dummysh) {
              // A subsegment is found at this side, dissolve this subface
              //   from the face link of this subsegment.
              testseg.shver = 0;
              spinsh = neighsh;
              if (sorg(spinsh) != sorg(testseg)) {
                sesymself(spinsh);
              }
              spivot(spinsh, casingout);
              if (casingout.sh == spinsh.sh) {
                // This is a trivial face link, only 'neighsh' itself,
                //   the subsegment at this side is also died.
                shellfacedealloc(subsegs, testseg.sh);
              } else {
                spinsh = casingout;
                do {
                  casingin = spinsh;
                  spivotself(spinsh);
                } while (spinsh.sh != neighsh.sh);
                // Set the link casingin->casingout.
                sbond1(casingin, casingout);
                // Bond the subsegment anyway.
                ssbond(casingin, testseg);
              }
            }
            senextself(neighsh);
            enextself(testtet);
          }
          shellfacedealloc(subfaces, neighsh.sh);
          if (neighbor.tet != dummytet) {
            // Make sure the subface doesn't get deallocated again later
            //  when the infected neighbor is visited.
            tsdissolve(neighbor);
          }
        }
      } else {                   // The neighbor exists and is not infected.
        if (neighsh.sh == dummysh) {
          // There is no subface protecting the neighbor, infect it.
          infect(neighbor);
          // Ensure that the neighbor's neighbors will be infected.
          deadtet = (tetrahedron **) viri->alloc();
          *deadtet = neighbor.tet;
        } else {               // The neighbor is protected by a subface.
          // Remove this tetrahedron from the subface.
          stdissolve(neighsh);
          // The subface becomes a boundary.  Set markers accordingly.
          if (shellmark(neighsh) == 0) {
            setshellmark(neighsh, 1);
          }
        }
      }
    }
    // Remark the tetrahedron as infected, so it doesn't get added to the
    //   virus pool again.
    infect(testtet);
    virusloop = (tetrahedron **) viri->traverse();
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// regionplague()    Spread regional attributes and/or volume constraints    //
//                   (from a .poly file) throughout the mesh.                //
//                                                                           //
// This procedure operates in two phases.  The first phase spreads an attri- //
// bute and/or a volume constraint through a (facet-bounded) region.  The    //
// second phase uninfects all infected tetrahedra, returning them to normal. //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::
regionplague(memorypool *regionviri, REAL attribute, REAL volume)
{
  tetrahedron **virusloop;
  tetrahedron **regiontet;
  triface testtet, neighbor;
  face neighsh;

  if (b->verbose > 1) {
    printf("  Marking neighbors of marked tetrahedra.\n");
  }
  // Loop through all the infected tetrahedra, spreading the attribute
  //   and/or volume constraint to their neighbors, then to their neighbors'
  //   neighbors.
  regionviri->traversalinit();
  virusloop = (tetrahedron **) regionviri->traverse();
  while (virusloop != (tetrahedron **) NULL) {
    testtet.tet = *virusloop;
    // Temporarily uninfect this tetrahedron, not necessary.
    uninfect(testtet);
    if (b->regionattrib) {
      // Set an attribute.
      setelemattribute(testtet.tet, in->numberoftetrahedronattributes,
                       attribute);
    }
    if (b->varvolume) {
      // Set a volume constraint.
      setvolumebound(testtet.tet, volume);
    }
    // Check each of the tetrahedron's four neighbors.
    for (testtet.loc = 0; testtet.loc < 4; testtet.loc++) {
      // Find the neighbor.
      sym(testtet, neighbor);
      // Check for a subface between the tetrahedron and its neighbor.
      tspivot(testtet, neighsh);
      // Make sure the neighbor exists, is not already infected, and
      //   isn't protected by a subface, or is protected by a nonsolid
      //   subface.
      if ((neighbor.tet != dummytet) && !infected(neighbor)
          && (neighsh.sh == dummysh)) {
        // Infect the neighbor.
        infect(neighbor);
        // Ensure that the neighbor's neighbors will be infected.
        regiontet = (tetrahedron **) regionviri->alloc();
        *regiontet = neighbor.tet;
      }
    }
    // Remark the tetrahedron as infected, so it doesn't get added to the
    //   virus pool again.
    infect(testtet);
    virusloop = (tetrahedron **) regionviri->traverse();
  }

  // Uninfect all tetrahedra.
  if (b->verbose > 1) {
    printf("  Unmarking marked tetrahedra.\n");
  }
  regionviri->traversalinit();
  virusloop = (tetrahedron **) regionviri->traverse();
  while (virusloop != (tetrahedron **) NULL) {
    testtet.tet = *virusloop;
    uninfect(testtet);
    virusloop = (tetrahedron **) regionviri->traverse();
  }
  // Empty the virus pool.
  regionviri->restart();
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// removeholetets()    Remove tetrahedra which are outside the domain.       //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::removeholetets(memorypool* viri)
{
  tetrahedron **virusloop;
  triface testtet, neighbor;
  point checkpt;
  int *tetspernodelist;
  int i, j;

  if (b->verbose) {
    printf("  Deleting marked tetrahedra.\n");
  }

  // Create and initialize 'tetspernodelist'.
  tetspernodelist = new int[points->items + 1];
  for (i = 0; i < points->items + 1; i++) tetspernodelist[i] = 0;
  
  // Loop the tetrahedra list, counter the number of tets sharing each node.
  tetrahedrons->traversalinit();
  testtet.tet = tetrahedrontraverse();
  while (testtet.tet != (tetrahedron *) NULL) {
    // Increment the number of sharing tets for each endpoint.
    for (i = 0; i < 4; i++) {
      j = pointmark((point) testtet.tet[4 + i]);
      tetspernodelist[j]++;
    }
    testtet.tet = tetrahedrontraverse();
  }

  viri->traversalinit();
  virusloop = (tetrahedron **) viri->traverse();
  while (virusloop != (tetrahedron **) NULL) {
    testtet.tet = *virusloop;
    // Record changes in the number of boundary faces, and disconnect
    //   dead tetrahedra from their neighbors.
    for (testtet.loc = 0; testtet.loc < 4; testtet.loc++) {
      sym(testtet, neighbor);
      if (neighbor.tet == dummytet) {
        // There is no neighboring tetrahedron on this face, so this face
        //   is a boundary face.  This tetrahedron is being deleted, so this
        //   boundary face is deleted.
        hullsize--;
      } else {
        // Disconnect the tetrahedron from its neighbor.
        dissolve(neighbor);
        // There is a neighboring tetrahedron on this face, so this face
        //   becomes a boundary face when this tetrahedron is deleted.
        hullsize++;
      }
    }
    // Check the four corners of this tet if they're isolated.
    for (i = 0; i < 4; i++) {
      checkpt = (point) testtet.tet[4 + i];
      j = pointmark(checkpt);
      tetspernodelist[j]--;
      if (tetspernodelist[j] == 0) {
        setpointtype(checkpt, UNUSEDVERTEX);
        unuverts++;
      }
    }
    // Return the dead tetrahedron to the pool of tetrahedra.
    tetrahedrondealloc(testtet.tet);
    virusloop = (tetrahedron **) viri->traverse();
  }
  
  delete [] tetspernodelist;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// carveholes()    Find the holes and infect them.  Find the volume          //
//                 constraints and infect them.  Infect the convex hull.     //
//                 Spread the infection and kill tetrahedra.  Spread the     //
//                 volume constraints.                                       //
//                                                                           //
// This routine mainly calls other routines to carry out all these functions.//
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::carveholes()
{
  memorypool *holeviri, *regionviri;
  tetrahedron *tptr, **holetet, **regiontet;
  triface searchtet, *holetets, *regiontets;
  enum locateresult intersect;
  int i;

  if (!b->quiet) {
    printf("Removing unwanted tetrahedra.\n");
    if (b->verbose && (in->numberofholes > 0)) {
      printf("  Marking holes for elimination.\n");
    }
  }

  // Initialize a pool of viri to be used for holes, concavities.
  holeviri = new memorypool(sizeof(tetrahedron *), 1024, POINTER, 0);
  // Mark as infected any unprotected tetrahedra on the boundary.
  infecthull(holeviri);

  if (in->numberofholes > 0) {
    // Allocate storage for the tetrahedra in which hole points fall.
    holetets = (triface *) new triface[in->numberofholes];
    // Infect each tetrahedron in which a hole lies.
    for (i = 0; i < 3 * in->numberofholes; i += 3) {
      // Ignore holes that aren't within the bounds of the mesh.
      if ((in->holelist[i] >= xmin) && (in->holelist[i] <= xmax)
          && (in->holelist[i + 1] >= ymin)
          && (in->holelist[i + 1] <= ymax)
          && (in->holelist[i + 2] >= zmin)
          && (in->holelist[i + 2] <= zmax)) {
        searchtet.tet = dummytet;
        // Find a tetrahedron that contains the hole.
        intersect = locate(&in->holelist[i], &searchtet);
        if ((intersect != OUTSIDE) && (!infected(searchtet))) {
          // Record the tetrahedron for processing carve hole.
          holetets[i / 3] = searchtet;
        }
      }
    }
    // Infect the hole tetrahedron.  This is done by marking the tet as
    //   infected and including the tetrahedron in the virus pool.
    for (i = 0; i < in->numberofholes; i++) {
      infect(holetets[i]);
      holetet = (tetrahedron **) holeviri->alloc();
      *holetet = holetets[i].tet;
    }
    // Free up memory.
    delete [] holetets;
  }

  // Mark as infected all tets of the holes and concavities.
  plague(holeviri);
  // The virus pool contains all outside tets now.

  if (in->numberofregions > 0) {
    if (!b->quiet) {
      if (b->regionattrib) {
        if (b->varvolume) {
          printf("Spreading regional attributes and volume constraints.\n");
        } else {
          printf("Spreading regional attributes.\n");
        }
      } else {
        printf("Spreading regional volume constraints.\n");
      }
    }
    // Allocate storage for the tetrahedra in which region points fall.
    regiontets = (triface *) new triface[in->numberofregions];
    // Find the starting tetrahedron for each region.
    for (i = 0; i < in->numberofregions; i++) {
      regiontets[i].tet = dummytet;
      // Ignore region points that aren't within the bounds of the mesh.
      if ((in->regionlist[5 * i] >= xmin)
           && (in->regionlist[5 * i] <= xmax)
           && (in->regionlist[5 * i + 1] >= ymin)
           && (in->regionlist[5 * i + 1] <= ymax)
           && (in->regionlist[5 * i + 2] >= zmin)
           && (in->regionlist[5 * i + 2] <= zmax)) {
        searchtet.tet = dummytet;
        // Find a tetrahedron that contains the region point.
        intersect = locate(&in->regionlist[5 * i], &searchtet);
        if ((intersect != OUTSIDE) && (!infected(searchtet))) {
          // Record the tetrahedron for processing after the
          //   holes have been carved.
          regiontets[i] = searchtet;
        }
      }
    }
    if (b->regionattrib && !b->refine) {
      // Assign every tetrahedron a regional attribute of zero.
      tetrahedrons->traversalinit();
      tptr = tetrahedrontraverse();
      while (tptr != (tetrahedron *) NULL) {
        setelemattribute(tptr, in->numberoftetrahedronattributes, 0.0);
        tptr = tetrahedrontraverse();
      }
    }
    // Initialize a pool to be used for regional attrs, and/or regional
    //   volume constraints.
    regionviri = new memorypool(sizeof(tetrahedron *), 1024, POINTER, 0);
    // Find and set all regions.
    for (i = 0; i < in->numberofregions; i++) {
      if (regiontets[i].tet != dummytet) {
        // Make sure the tetrahedron under consideration still exists.
        //   It may have been eaten by the virus.
        if (!isdead(&(regiontets[i]))) {
          // Put one tetrahedron in the virus pool.
          infect(regiontets[i]);
          regiontet = (tetrahedron **) regionviri->alloc();
          *regiontet = regiontets[i].tet;
          // Apply one region's attribute and/or volume constraint.
          regionplague(regionviri, in->regionlist[5 * i + 3],
                       in->regionlist[5 * i + 4]);
          // The virus pool should be empty now.
        }
      }
    }
    if (b->regionattrib && !b->refine) {
      // Note the fact that each tetrahedron has an additional attribute.
      in->numberoftetrahedronattributes++;
    }
    // Free up memory.
    delete [] regiontets;
    delete regionviri;
  }

  // Now acutually remove the outside and hole tets.
  removeholetets(holeviri);
  // The mesh is nonconvex now.
  nonconvex = 1;

  // Free up memory.
  delete holeviri;
}

//
// End of carving out holes and concavities routines
//

//
// Begin of mesh reconstruction routines
//

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// reconstructmesh()    Reconstruct a tetrahedral mesh from a list of        //
//                      tetrahedra and possibly a list of boundary faces.    //
//                                                                           //
// The list of tetrahedra is stored in 'in->tetrahedronlist',  the list of   //
// boundary faces is stored in 'in->trifacelist'.  The tetrahedral mesh is   //
// reconstructed in memorypool 'tetrahedrons', its boundary faces (subfaces) //
// are reconstructed in 'subfaces', its boundary edges (subsegments) are     //
// reconstructed in 'subsegs'. If the -a switch is used, this procedure will //
// also read a list of REALs from 'in->tetrahedronvolumelist' and set a      //
// maximum volume constraint on each tetrahedron.                            //
//                                                                           //
// If the user has provided the boundary faces in 'in->trifacelist', they    //
// will be inserted the mesh. Otherwise subfaces will be identified from the //
// mesh.  All hull faces (including faces of the internal holes) will be     //
// recognized as subfaces, internal faces between two tetrahedra which have  //
// different attributes will also be recognized as subfaces.                 //
//                                                                           //
// Subsegments will be identified after subfaces are reconstructed. Edges at //
// the intersections of non-coplanar subfaces are recognized as subsegments. //
// Edges between two coplanar subfaces with different boundary markers are   //
// also recognized as subsegments.                                           //
//                                                                           //
// The facet index of each subface will be set automatically after we have   //
// recovered subfaces and subsegments.  That is, the set of subfaces, which  //
// are coplanar and have the same boundary marker will be recognized as a    //
// facet and has a unique index, stored as the facet marker in each subface  //
// of the set, the real boundary marker of each subface will be found in     //
// 'in->facetmarkerlist' by the index.  Facet index will be used in Delaunay //
// refinement for detecting two incident facets.                             //
//                                                                           //
// Points which are not corners of tetrahedra will be inserted into the mesh.//
// Return the number of faces on the hull after the reconstruction.          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

long tetgenmesh::reconstructmesh()
{
  tetrahedron **tetsperverlist;
  shellface **facesperverlist;
  triface tetloop, neightet, neineightet, spintet;
  face subloop, neighsh, neineighsh, subseg;
  face sface1, sface2;
  point *idx2verlist;
  point torg, tdest, tapex, toppo;
  point norg, ndest, napex;
  list *neighshlist, *markerlist;
  REAL sign, attrib, volume;
  REAL da1, da2;
  bool bondflag, insertsegflag;
  int *idx2tetlist;
  int *idx2facelist;
  int *worklist;
  int facetidx, marker;
  int iorg, idest, iapex, ioppo;
  int inorg, indest, inapex;
  int index, i, j;

  if (!b->quiet) {
    printf("Reconstructing mesh.\n");
  }

  // Create a map from index to points.
  makeindex2pointmap(idx2verlist);

  // Create the tetrahedra.
  for (i = 0; i < in->numberoftetrahedra; i++) {
    // Create a new tetrahedron and set its four corners, make sure that
    //   four corners form a positive orientation.
    maketetrahedron(&tetloop);
    index = i * in->numberofcorners;
    // Although there may be 10 nodes, we only read the first 4.
    iorg = in->tetrahedronlist[index] - in->firstnumber;
    idest = in->tetrahedronlist[index + 1] - in->firstnumber;
    iapex = in->tetrahedronlist[index + 2] - in->firstnumber;
    ioppo = in->tetrahedronlist[index + 3] - in->firstnumber;
    torg = idx2verlist[iorg];
    tdest = idx2verlist[idest];
    tapex = idx2verlist[iapex];
    toppo = idx2verlist[ioppo];
    sign = orient3d(torg, tdest, tapex, toppo);
    if (sign > 0.0) {
      norg = torg; torg = tdest; tdest = norg;
    } else if (sign == 0.0) {
      printf("Warning:  Tetrahedron %d is degenerate.\n", i + in->firstnumber);
    }
    setorg(tetloop, torg);
    setdest(tetloop, tdest);
    setapex(tetloop, tapex);
    setoppo(tetloop, toppo);
    // Temporarily set the vertices be type FREEVOLVERTEX, to indicate that
    //   they belong to the mesh.  These types may be changed later.
    setpointtype(torg, FREEVOLVERTEX);
    setpointtype(tdest, FREEVOLVERTEX);
    setpointtype(tapex, FREEVOLVERTEX);
    setpointtype(toppo, FREEVOLVERTEX);
    // Set element attributes if they exist.
    for (j = 0; j < in->numberoftetrahedronattributes; j++) {
      index = i * in->numberoftetrahedronattributes;
      attrib = in->tetrahedronattributelist[index + j];
      setelemattribute(tetloop.tet, j, attrib);
    }
    // If -a switch is used (with no number follows) Set a volume
    //   constraint if it exists.
    if (b->varvolume) {
      if (in->tetrahedronvolumelist != (REAL *) NULL) {
        volume = in->tetrahedronvolumelist[i];
      } else {
        volume = -1.0;
      }
      setvolumebound(tetloop.tet, volume);
    }
  }

  // Set the connection between tetrahedra.
  hullsize = 0l;
  // Create a map from nodes to tetrahedra.
  maketetrahedronmap(idx2tetlist, tetsperverlist);
  // Initialize the worklist.
  worklist = new int[points->items];
  for (i = 0; i < points->items; i++) worklist[i] = 0;

  // Loop all tetrahedra, bond two tetrahedra if they share a common face.
  tetrahedrons->traversalinit();
  tetloop.tet = tetrahedrontraverse();
  while (tetloop.tet != (tetrahedron *) NULL) {
    // Loop the four sides of the tetrahedron.
    for (tetloop.loc = 0; tetloop.loc < 4; tetloop.loc++) {
      sym(tetloop, neightet);
      if (neightet.tet != dummytet) continue; // This side has finished.
      torg = org(tetloop);
      tdest = dest(tetloop);
      tapex = apex(tetloop);
      iorg = pointmark(torg) - in->firstnumber;
      idest = pointmark(tdest) - in->firstnumber;
      iapex = pointmark(tapex) - in->firstnumber;
      worklist[iorg] = 1;
      worklist[idest] = 1;
      worklist[iapex] = 1;
      bondflag = false;
      // Search its neighbor in the adjacent tets of torg.
      for (j = idx2tetlist[iorg]; j < idx2tetlist[iorg + 1] && !bondflag; 
           j++) {
        if (tetsperverlist[j] == tetloop.tet) continue; // Skip myself.
        neightet.tet = tetsperverlist[j];
        for (neightet.loc = 0; neightet.loc < 4; neightet.loc++) {
          sym(neightet, neineightet);
          if (neineightet.tet == dummytet) {
            norg = org(neightet);
            ndest = dest(neightet);
            napex = apex(neightet);
            inorg = pointmark(norg) - in->firstnumber;
            indest = pointmark(ndest) - in->firstnumber;
            inapex = pointmark(napex) - in->firstnumber;
            if ((worklist[inorg] + worklist[indest] + worklist[inapex]) == 3) {
              // Find! Bond them together and break the loop.
              bond(tetloop, neightet);
              bondflag = true;
              break;
            }
          }
        }
      }
      if (!bondflag) {
        hullsize++;  // It's a hull face.
        // Bond this side to outer space.
        dummytet[0] = encode(tetloop);
        if (in->pointmarkerlist != (int *) NULL) {
          // Set its three corners's markers be boundary (hull) vertices.
          if (in->pointmarkerlist[iorg] == 0) {
            in->pointmarkerlist[iorg] = 1;
          }
          if (in->pointmarkerlist[idest] == 0) {
            in->pointmarkerlist[idest] = 1;
          }
          if (in->pointmarkerlist[iapex] == 0) {
            in->pointmarkerlist[iapex] = 1;
          }
        }
      }
      worklist[iorg] = 0;
      worklist[idest] = 0;
      worklist[iapex] = 0;
    }
    tetloop.tet = tetrahedrontraverse();
  }

  // Subfaces will be inserted into the mesh.
  if (in->trifacelist != (int *) NULL) {
    // Recover subfaces from 'in->trifacelist'.
    for (i = 0; i < in->numberoftrifaces; i++) {
      index = i * 3;
      iorg = in->trifacelist[index] - in->firstnumber;
      idest = in->trifacelist[index + 1] - in->firstnumber;
      iapex = in->trifacelist[index + 2] - in->firstnumber;
      // Look for the location of this subface.
      worklist[iorg] = 1;
      worklist[idest] = 1;
      worklist[iapex] = 1;
      bondflag = false;
      // Search its neighbor in the adjacent tets of torg.
      for (j = idx2tetlist[iorg]; j < idx2tetlist[iorg + 1] && !bondflag; 
           j++) {
        neightet.tet = tetsperverlist[j];
        for (neightet.loc = 0; neightet.loc < 4; neightet.loc++) {
          norg = org(neightet);
          ndest = dest(neightet);
          napex = apex(neightet);
          inorg = pointmark(norg) - in->firstnumber;
          indest = pointmark(ndest) - in->firstnumber;
          inapex = pointmark(napex) - in->firstnumber;
          if ((worklist[inorg] + worklist[indest] + worklist[inapex]) == 3) {
            bondflag = true;  // Find!
            break;
          }
        }
      }
      if (bondflag) {
        // Create a new subface and insert it into the mesh.
        makeshellface(subfaces, &subloop);
        torg = idx2verlist[iorg];
        tdest = idx2verlist[idest];
        tapex = idx2verlist[iapex];
        setsorg(subloop, torg);
        setsdest(subloop, tdest);
        setsapex(subloop, tapex);
        // Set the vertices be FREESUBVERTEX to indicate they belong to a
        //   facet of the domain.  They may be changed later.
        setpointtype(torg, FREESUBVERTEX);
        setpointtype(tdest, FREESUBVERTEX);
        setpointtype(tapex, FREESUBVERTEX);
        if (in->trifacemarkerlist != (int *) NULL) {
          setshellmark(subloop, in->trifacemarkerlist[i]);
        }
        adjustedgering(neightet, CCW);
        findedge(&subloop, org(neightet), dest(neightet));
        tsbond(neightet, subloop);
        sym(neightet, neineightet);
        if (neineightet.tet != dummytet) {
          sesymself(subloop);
          tsbond(neineightet, subloop);
        }
      } else {
        printf("Warning:  Subface %d is discarded.\n", i + in->firstnumber);
      }
      worklist[iorg] = 0;
      worklist[idest] = 0;
      worklist[iapex] = 0;
    }
  } else {
    // Indentify subfaces from the mesh.
    tetrahedrons->traversalinit();
    tetloop.tet = tetrahedrontraverse();
    while (tetloop.tet != (tetrahedron *) NULL) {
      // Loop the four sides of the tetrahedron.
      for (tetloop.loc = 0; tetloop.loc < 4; tetloop.loc++) {
        tspivot(tetloop, subloop);
        if (subloop.sh != dummysh) continue;
        bondflag = false;
        sym(tetloop, neightet);
        if (neightet.tet == dummytet) {
          // It's a hull face. Insert a subface at here.
          bondflag = true;
        } else {
          // It's an interior face. Insert a subface if two tetrahedra have
          //   different attributes (i.e., they belong to two regions).
          if (in->numberoftetrahedronattributes > 0) {
            if (elemattribute(neightet.tet,
                in->numberoftetrahedronattributes - 1) != 
                elemattribute(tetloop.tet,
                in->numberoftetrahedronattributes - 1)) {
              bondflag = true;
            }
          }
        }
        if (bondflag) {
          adjustedgering(tetloop, CCW);
          makeshellface(subfaces, &subloop);
          torg = org(tetloop);
          tdest = dest(tetloop);
          tapex = apex(tetloop);
          setsorg(subloop, torg);
          setsdest(subloop, tdest);
          setsapex(subloop, tapex);
          // Set the vertices be FACETVERTEX to indicate they belong to a
          //   facet of the domain.  They may be changed later.
          setpointtype(torg, FACETVERTEX);
          setpointtype(tdest, FACETVERTEX);
          setpointtype(tapex, FACETVERTEX);
          tsbond(tetloop, subloop);
          if (neightet.tet != dummytet) {
            sesymself(subloop);
            tsbond(neightet, subloop);
          }
        }
      }
      tetloop.tet = tetrahedrontraverse();
    }
  }

  // Set the connection between subfaces. A subsegment may have more than
  //   two subfaces sharing it, 'neighshlist' stores all subfaces sharing
  //   one edge.
  neighshlist = new list(sizeof(face), NULL);
  // Create a map from nodes to subfaces.
  makesubfacemap(idx2facelist, facesperverlist);

  // Loop over the set of subfaces, setup the connection between subfaces.
  subfaces->traversalinit();
  subloop.sh = shellfacetraverse(subfaces);
  while (subloop.sh != (shellface *) NULL) {
    for (i = 0; i < 3; i++) {
      spivot(subloop, neighsh);
      if (neighsh.sh == dummysh) {
        // This side is 'empty', operate on it.
        torg = sorg(subloop);
        tdest = sdest(subloop);
        tapex = sapex(subloop);
        neighshlist->append(&subloop);
        iorg = pointmark(torg) - in->firstnumber;
        // Search its neighbor in the adjacent list of torg.
        for (j = idx2facelist[iorg]; j < idx2facelist[iorg + 1]; j++) {
          neighsh.sh = facesperverlist[j];
          if (neighsh.sh == subloop.sh) continue;
          neighsh.shver = 0;
          if (isfacehasedge(&neighsh, torg, tdest)) {
            findedge(&neighsh, torg, tdest);
            // Insert 'neighsh' into 'neighshlist'.
            if (neighshlist->len() < 2) {
              neighshlist->append(&neighsh);
            } else {
              for (index = 0; index < neighshlist->len() - 1; index++) {
                sface1 = * (face *)(* neighshlist)[index];
                sface2 = * (face *)(* neighshlist)[index + 1];
                da1 = facedihedral(torg, tdest, sapex(sface1), sapex(neighsh));
                da2 = facedihedral(torg, tdest, sapex(sface1), sapex(sface2));
                if (da1 < da2) {
                  break;  // Insert it after index.
                }
              }
              neighshlist->insert(index + 1, &neighsh);
            }
          }
        }
        // Bond the subfaces in 'neighshlist'. 
        if (neighshlist->len() > 1) {
          neighsh = * (face *)(* neighshlist)[0];
          for (j = 1; j <= neighshlist->len(); j++) {
            if (j < neighshlist->len()) {
              neineighsh = * (face *)(* neighshlist)[j];
            } else {
              neineighsh = * (face *)(* neighshlist)[0];
            }
            sbond1(neighsh, neineighsh);
            neighsh = neineighsh;
          }
        } else {
          // No neighbor subface be found, bond 'subloop' to itself.
          sbond(subloop, subloop);
        }
        neighshlist->clear();
      }
      senextself(subloop);
    }
    subloop.sh = shellfacetraverse(subfaces);
  }

  // Segments will be introudced. Each segment has a unique marker (1-based).
  marker = 1;
  subfaces->traversalinit();
  subloop.sh = shellfacetraverse(subfaces);
  while (subloop.sh != (shellface *) NULL) {
    for (i = 0; i < 3; i++) {
      sspivot(subloop, subseg);
      if (subseg.sh == dummysh) {
        // This side has no subsegment bonded, check it.
        torg = sorg(subloop);
        tdest = sdest(subloop);
        tapex = sapex(subloop);
        spivot(subloop, neighsh);
        spivot(neighsh, neineighsh);
        insertsegflag = false;
        if (subloop.sh == neighsh.sh || subloop.sh != neineighsh.sh) {
          // This side is either self-bonded or more than two subfaces,
          //   insert a subsegment at this side.
          insertsegflag = true;
        } else {
          // Only two subfaces case.
          assert(subloop.sh != neighsh.sh);
          napex = sapex(neighsh);
          sign = orient3d(torg, tdest, tapex, napex);
          if (iscoplanar(torg, tdest, tapex, napex, sign, b->epsilon)) {
            // Although they are coplanar, we still need to check if they
            //   have the same boundary marker.
            insertsegflag = (shellmark(subloop) != shellmark(neighsh));
          } else {
            // Non-coplanar.
            insertsegflag = true;
          }
        }
        if (insertsegflag) {
          // Create a subsegment at this side.
          makeshellface(subsegs, &subseg);
          setsorg(subseg, torg);
          setsdest(subseg, tdest);
          // At the moment, all segment vertices have type FACETVERTEX.
          //   They will be set to type ACUTEVERTEX or NACUTEVERTEX by
          //   routine markacutevertices() later.
          // setpointtype(torg, SEGMENTVERTEX);
          // setpointtype(tdest, SEGMENTVERTEX);
          setshellmark(subseg, marker);
          marker++;
          // Bond all subfaces to this subsegment.
          neighsh = subloop;
          do {
            ssbond(neighsh, subseg);
            spivotself(neighsh);
          } while (neighsh.sh != subloop.sh);
        }
      }
      senextself(subloop);
    }
    subloop.sh = shellfacetraverse(subfaces);
  }
  // Remember the number of input segments.
  insegment = subsegs->items;
  // Find the acute vertices and set them be type ACUTEVERTEX.

  // Indentify facets and set the facet marker (1-based) for subfaces.
  markerlist = new list("int");
  
  subfaces->traversalinit();
  subloop.sh = shellfacetraverse(subfaces);
  while (subloop.sh != (shellface *) NULL) {
    // Only operate on uninfected subface, after operating, infect it.
    if (!sinfected(subloop)) {
      // A new facet is found.
      marker = shellmark(subloop);
      markerlist->append(&marker);
      facetidx = markerlist->len(); // 'facetidx' starts from 1.
      setshellmark(subloop, facetidx);
      sinfect(subloop);
      neighshlist->append(&subloop);
      // Find out all subfaces of this facet (bounded by subsegments).
      for (i = 0; i < neighshlist->len(); i++) {
        neighsh = * (face *) (* neighshlist)[i];
        for (j = 0; j < 3; j++) {
          sspivot(neighsh, subseg);
          if (subseg.sh == dummysh) {
            spivot(neighsh, neineighsh);
            if (!sinfected(neineighsh)) {
              // 'neineighsh' is in the same facet as 'subloop'.
              assert(shellmark(neineighsh) == marker);
              setshellmark(neineighsh, facetidx);
              sinfect(neineighsh);
              neighshlist->append(&neineighsh);
            }
          }
          senextself(neighsh);
        }
      }
      neighshlist->clear();
    }
    subloop.sh = shellfacetraverse(subfaces);
  }
  // Save the facet markers in 'in->facetmarkerlist'.
  in->numberoffacets = markerlist->len();
  in->facetmarkerlist = new int[in->numberoffacets];
  for (i = 0; i < in->numberoffacets; i++) {
    marker = * (int *) (* markerlist)[i];
    in->facetmarkerlist[i] = marker;
  }
  // Uninfect all subfaces.
  subfaces->traversalinit();
  subloop.sh = shellfacetraverse(subfaces);
  while (subloop.sh != (shellface *) NULL) {
    assert(sinfected(subloop));
    suninfect(subloop);
    subloop.sh = shellfacetraverse(subfaces);
  }

  // The mesh contains boundary now.
  checksubfaces = 1;

  // Is there periodic boundary confitions?
  if (checkpbcs) {
    if (in->pbcgrouplist != (tetgenio::pbcgroup *) NULL) {
      tetgenio::pbcgroup *pg;
      pbcdata *pd;
      // Create 'subpbcgrouptable'.
      createsubpbcgrouptable();
      // Loop for each pbcgroup i.
      for (i = 0; i < in->numberofpbcgroups; i++) {
        pg = &(in->pbcgrouplist[i]);
        pd = &(subpbcgrouptable[i]);
        // Find all subfaces of pd, set each subface's group id be i.
        for (j = 0; j < 2; j++) {
          subfaces->traversalinit();
          subloop.sh = shellfacetraverse(subfaces);
          while (subloop.sh != (shellface *) NULL) {
            facetidx = shellmark(subloop);
            marker = in->facetmarkerlist[facetidx - 1];
            if (marker == pd->fmark[j]) {
              setshellpbcgroup(subloop, i);
              pd->ss[j] = subloop;
            }
            subloop.sh = shellfacetraverse(subfaces);
          }
        }
        if (pg->pointpairlist != (int *) NULL) {
          // Set the connections between pbc point pairs.
          for (j = 0; j < pg->numberofpointpairs; j++) {
            iorg = pg->pointpairlist[j * 2] - in->firstnumber;
            idest = pg->pointpairlist[j * 2 + 1] - in->firstnumber;
            torg = idx2verlist[iorg];
            tdest = idx2verlist[idest];
            setpoint2pbcpt(torg, tdest);
            setpoint2pbcpt(tdest, torg);
          }
        }
      }
      // Create 'segpbcgrouptable'.
      createsegpbcgrouptable();
    }
  }

  if (b->quality && varconstraint) {
    // Assign constraints on facets, segments, and nodes.
    assignvarconstraints(idx2verlist);
  }

  if (b->quality) {
    // Check and recover the Delaunay property.
    queue* flipqueue = new queue(sizeof(badface)); 
    checkdelaunay(0.0, flipqueue);
    if (!flipqueue->empty()) {
      // Call flip algorithm to recover Delaunayness.
      flip(flipqueue, NULL, false, false, false); 
    }
    delete flipqueue;
  }

  delete markerlist;
  delete neighshlist;
  delete [] worklist;
  delete [] idx2tetlist;
  delete [] tetsperverlist;
  delete [] idx2facelist;
  delete [] facesperverlist;
  delete [] idx2verlist;
  
  return hullsize;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// insertaddpoints()    Insert additional points in 'in->addpointlist'.      //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::insertaddpoints()
{
  queue *flipqueue;
  triface searchtet;
  face checksh, checkseg;
  point newpoint;
  point p1, p2, p3, p4;
  enum locateresult loc;
  REAL ori;
  int index;
  int i;
  
  if (!b->quiet) {
    printf("Insert additional points into mesh.\n");
  }
  // Initialize 'flipqueue'.
  flipqueue = new queue(sizeof(badface));
  recenttet.tet = dummytet;

  index = 0;
  for (i = 0; i < in->numberofaddpoints; i++) {
    // Create a newpoint.
    makepoint(&newpoint);
    newpoint[0] = in->addpointlist[index++];
    newpoint[1] = in->addpointlist[index++];
    newpoint[2] = in->addpointlist[index++];
    // Find the location of the inserted point.
    searchtet = recenttet;
    loc = locate(newpoint, &searchtet);
    if (loc != OUTSIDE) {
      if (loc != ONVERTEX) {
        loc = adjustlocate(newpoint, &searchtet, loc, b->epsilon);
      }
    }
    if (loc == OUTSIDE) {
      // Perform a brute-force search.
      tetrahedrons->traversalinit();
      searchtet.tet = tetrahedrontraverse();
      while (searchtet.tet != (tetrahedron *) NULL) {
        p1 = (point) searchtet.tet[4];
        p2 = (point) searchtet.tet[5];
        p3 = (point) searchtet.tet[6];
        p4 = (point) searchtet.tet[7];
        ori = orient3d(p2, p1, p3, newpoint);
        if (ori >= 0) {
          ori = orient3d(p1, p2, p4, newpoint);
          if (ori >= 0) {
            ori = orient3d(p2, p3, p4, newpoint);
            if (ori >= 0) {
              ori = orient3d(p3, p1, p4, newpoint);
              if (ori >= 0) {
                // 'newpoint' lies inside, or on a face, or on an edge, or
                //   a vertex of 'searchtet'.
                loc = adjustlocate(newpoint, &searchtet, OUTSIDE, b->epsilon);
                if (loc != OUTSIDE) break;
              }
            }
          }
        }
        searchtet.tet = tetrahedrontraverse();
      }
    }
    // Insert the point if it not lies outside or on a vertex.
    switch (loc) {
    case INTETRAHEDRON:
      setpointtype(newpoint, FREEVOLVERTEX);
      splittetrahedron(newpoint, &searchtet, flipqueue);
      break;
    case ONFACE:
      tspivot(searchtet, checksh);
      if (checksh.sh != dummysh) {
        setpointtype(newpoint, FREESUBVERTEX);
      } else {
        setpointtype(newpoint, FREEVOLVERTEX);
      }
      splittetface(newpoint, &searchtet, flipqueue);
      break;
    case ONEDGE:
      tsspivot(&searchtet, &checkseg);
      if (checkseg.sh != dummysh) {
        setpointtype(newpoint, FREESEGVERTEX);
      } else {
        tspivot(searchtet, checksh);
        if (checksh.sh != dummysh) {
          setpointtype(newpoint, FREESUBVERTEX);
        } else {
          setpointtype(newpoint, FREEVOLVERTEX);
        }
      }
      splittetedge(newpoint, &searchtet, flipqueue);
      break;
    case ONVERTEX:
      if (b->verbose) {
        printf("Warning: Point (%.17g, %.17g, %.17g) falls on a vertex.\n",
               newpoint[0], newpoint[1], newpoint[2]);
      }
      break;
    case OUTSIDE:
      if (b->verbose) {
        printf("Warning: Point (%.17g, %.17g, %.17g) lies outside the mesh.\n",
               newpoint[0], newpoint[1], newpoint[2]);
      }
      break;
    }
    // Remember the tetrahedron for next point searching.
    recenttet = searchtet;
    if (loc == ONVERTEX || loc == OUTSIDE) {
      pointdealloc(newpoint);
    } else {
      flip(flipqueue, NULL, false, false, false);
    }
  }

  delete flipqueue;
}

//
// End of mesh reconstruction routines
//

//
// Begin of mesh repair routines
//

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// checktet4dege()    Check a tetrahedron to see if it is degenerate.        //
//                                                                           //
// A tetrahedron is degenerate if (1) it has a zero-volume; or (2) it has 2  //
// faces on a facet. case (2) is caused by the vertices of a facet are not   //
// exactly coplanar.                                                         //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenmesh::checktet4dege(triface* testtet, list* degetetlist)
{
  badface *degetet;
  face checksh1, checksh2;
  face checkseg;
  point pa, pb, pc, pd;
  REAL volume;
  int shmark1, shmark2;
  int i, j, k, l;

  pa = org(*testtet);
  pb = dest(*testtet);
  pc = apex(*testtet);
  pd = oppo(*testtet);
  volume = orient3d(pb, pa, pc, pd);
  // 'volume' should be non negative.
  assert(volume >= 0.0);

  if (volume != 0.0) {
    // Check if it spans on one facet. That is, to look if there're two
    //   subfaces of the tet which belong to the same facet.
    for (i = 0; (i < 3) && (volume != 0); i++) {
      sdecode((shellface) testtet->tet[8 + i], checksh1);
      if (checksh1.sh != dummysh) {
        shmark1 = shellmark(checksh1);
        for (j = i + 1; (j < 4) && (volume != 0); j++) {
          sdecode((shellface) testtet->tet[8 + j], checksh2);
          if (checksh2.sh != dummysh) {
            shmark2 = shellmark(checksh2); 
            if (shmark1 == shmark2) {
              // The same marker - belong to the same facet.
              volume = 0.0;
            } else {
              // Two different markers. Find the sharing edge.
              for (k = 0; k < 3; k++) {
                for (l = 0; l < 3; l++) {
                  if (sorg(checksh2) == sorg(checksh1)) {
                    if (sdest(checksh2) == sdest(checksh1)) break;
                  } else if (sdest(checksh2) == sorg(checksh1)) {
                    if (sorg(checksh2) == sdest(checksh1)) break;
                  }
                  senextself(checksh2);
                }
                if (l < 3) break;
                senextself(checksh1);
              }
              assert(k < 3); // The edge must exist.
              // Is there a segment?
              sspivot(checksh2, checkseg);
              if (checkseg.sh == dummysh) {
                // No segment - two subfaces belong to a unified facet.
                volume = 0.0;
              }
            }
          }
        }
      }
    }
  }

  if (volume == 0.0) {
    if (degetetlist != (list *) NULL) {
      degetet = (badface *) degetetlist->append(NULL);
      degetet->tt = *testtet;
      degetet->forg = pa;
      degetet->fdest = pb;
      degetet->fapex = pc;
      degetet->foppo = pd;
    }
    if (b->verbose > 1) {
      printf("    Find tet (%d, %d, %d, %d).\n", pointmark(pa), pointmark(pb),
             pointmark(pc), pointmark(pd));
    }
  }

  return volume == 0.0;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// finddiagonal()    Find one of the diagonal edges in a kite.               //
//                                                                           //
// 'akite' (abcd) is degenerate. This routine sets ab be the diagonal edge.  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenmesh::finddiagonal(triface* akite)
{
  point pa, pb, pc, pd;
  REAL v1[3], v2[3], v3[3];
  REAL L12, L22, L32;
  REAL pref[3], n[3], nlen;
  REAL sign1, sign2, sign3;
  int i;

  pa = org(*akite);
  pb = dest(*akite);
  pc = apex(*akite);
  pd = oppo(*akite);

  // Calculate a point which is exactly above the plane having abcd.
  L12 = L22 = L32 = 0.0;
  for (i = 0; i < 3; i++) {v1[i] = pb[i] - pa[i]; L12 += (v1[i] * v1[i]);}
  for (i = 0; i < 3; i++) {v2[i] = pc[i] - pa[i]; L22 += (v2[i] * v2[i]);}
  for (i = 0; i < 3; i++) {v3[i] = pd[i] - pa[i]; L32 += (v3[i] * v3[i]);}
  sign1 = v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
  sign2 = v1[0] * v3[0] + v1[1] * v3[1] + v1[2] * v3[2];
  sign1 = (sign1 * sign1) / (L12 * L22);
  sign2 = (sign2 * sign2) / (L12 * L32);
  if (sign1 < sign2) {
    // Angle cab is closer to 90 degree.
    facenormal(pa, pb, pc, n, &nlen);
  } else {
    // Angle dab is closer to 90 degree.
    facenormal(pa, pb, pd, n, &nlen);
  }
  assert(nlen > 0.0);
  for (i = 0; i < 3; i++) n[i] /= nlen;
  nlen = sqrt(L12);
  for (i = 0; i < 3; i++) pref[i] = pa[i] + nlen * n[i];

  for (i = 0; i < 3; i++) {
    pa = org(*akite);
    pb = dest(*akite);
    pc = apex(*akite);
    sign1 = orient3d(pa, pb, pref, pc);
    sign2 = orient3d(pa, pb, pref, pd);
    sign3 = sign1 * sign2;
    assert(sign3 != 0.0);
    if (sign3 < 0.0) break;
    enextself(*akite);
  }
  if (i == 3) return false;
  return true;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// removetetbypeeloff()    Remove a boundary tetrahedron by peeling off.     //
//                                                                           //
// 'badtet' (abcd) is a boundary tetrahedron and going to be peeled off. abc //
// and bad are the external boundary faces.                                  //
//                                                                           //
// To peel 'abcd' from the mesh is to detach its two interal faces (dca and  //
// cdb) from their adjoining tetrahedra together with a 2-to-2 flip to trans-//
// form two subfaces (abc and bad) into another two (dca and cdb).           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::removetetbypeeloff(triface *badtet, queue* flipqueue)
{
  triface abcd, badc;
  triface dcacasing, cdbcasing;
  face abc, bad;
  
  if (b->verbose > 1) {
    printf("    by peeling off it from boundary.\n");
  }

  abcd = *badtet;
  adjustedgering(abcd, CCW);
  
  // Get the external subfaces abc, bad.
  fnext(abcd, badc);
  esymself(badc);
  tspivot(abcd, abc);
  tspivot(badc, bad);
  assert((abc.sh != dummysh) && (bad.sh != dummysh));
  findedge(&abc, org(abcd), dest(abcd));
  findedge(&bad, org(badc), dest(badc));

  // Get the casing tets at the internal sides.
  enextfnext(abcd, cdbcasing);
  enext2fnext(abcd, dcacasing);
  symself(cdbcasing);
  symself(dcacasing);
  assert(cdbcasing.tet != dummytet && dcacasing.tet != dummytet);

  // Do a 2-to-2 flip on abc and bad, transform abc->dca, bad->cdb.
  flip22sub(&abc, NULL);
  // Detach abcd from the two internal faces.
  dissolve(cdbcasing);
  dissolve(dcacasing);
  // The two internal faces become boundary faces.
  tsbond(cdbcasing, bad);
  tsbond(dcacasing, abc);
  // Delete abcd.
  tetrahedrondealloc(abcd.tet);

  if (flipqueue != (queue *) NULL) {
    // Edge cd may be non-Delaunay.
    adjustedgering(cdbcasing, CCW);
    fnextself(cdbcasing);
    enqueueflipface(cdbcasing, flipqueue);
    adjustedgering(dcacasing, CCW);
    fnextself(dcacasing);
    enqueueflipface(dcacasing, flipqueue);
    // Do flipping if cd is non-Delaunay.
    flip(flipqueue, NULL, false, false, false);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// removetetbyflip32()    Remove a tetrahedron by a 3-to-2 flip.             //
//                                                                           //
// 'badtet' (abcd) is the bad tetrahedron which is going to be removed by a  //
// 3-to-2 flip.  abc represents one of the internal faces, bad is another.   //
// If abc and bad are subfaces, a 2-to-2 flip is performed to transform abc, //
// bad into dca, cdb, before the 3-to-2 flip is applying.                    //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::removetetbyflip32(triface *badtet, queue* flipqueue)
{
  triface abcd, badc;
  triface cdab, dcba;
  triface baccasing, abdcasing;
  triface dcacasing, cdbcasing;
  face abc, bad;
  REAL attrib, testattr;
  int i;  

  if (b->verbose > 1) {
    printf("    by doing a 3-to-2 flip.\n");
  }

  abcd = *badtet;
  adjustedgering(abcd, CCW);
  fnext(abcd, badc);
  esymself(badc);
  sym(abcd, baccasing);
  sym(badc, abdcasing);
  assert((baccasing.tet != dummytet) && (abdcasing.tet != dummytet));
  assert(oppo(baccasing) == oppo(abdcasing));
  
  // Get subfaces abc, bad.
  tspivot(abcd, abc);
  tspivot(badc, bad);
  if (abc.sh != dummysh) {
    // Because ab should not be a subsegment.
    assert(bad.sh != dummysh);
    // Find abc and bad are internal subfaces. Here baccasing and abdcasing
    //   must have the same attributes (such as the region attribute if the
    //   -A switch is in use). But abcd may not be at the same region. After
    //   flip32, if abcd is not deleted, it will have wrong attributes. Set
    //   abcd be the same region attributes as baccasing and abdcasing.
    for (i = 0; i < in->numberoftetrahedronattributes; i++) {
      attrib = elemattribute(baccasing.tet, i);
      testattr = elemattribute(abdcasing.tet, i);
      assert(attrib == testattr);
      setelemattribute(abcd.tet, i, attrib);
    }
    findedge(&abc, org(abcd), dest(abcd));
    findedge(&bad, org(badc), dest(badc));
    // Detach abc, bad from the four tetrahedra at both sides.
    stdissolve(abc);
    stdissolve(bad);
    sesymself(abc);
    sesymself(bad);
    stdissolve(abc);
    stdissolve(bad);
    sesymself(abc);
    sesymself(bad);
    // Detach the four tetrahedra which hold abc and bad.
    tsdissolve(abcd);
    tsdissolve(badc);
    tsdissolve(baccasing);
    tsdissolve(abdcasing);
    // Perform a 2-to-2 flip on abc, bad, transform abc->dca, bad->cdb.
    flip22sub(&abc, NULL);
    // Insert the flipped subfaces abc and bad into tetrahedra.
    enextfnext(abcd, dcba); // dcba = bcda
    esymself(dcba); // dcba = cbda
    enext2fnext(abcd, cdab); // cdab = cadb
    esymself(cdab); // cdab = acdb
    findedge(&abc, org(cdab), dest(cdab));
    tsbond(cdab, abc);
    findedge(&bad, org(dcba), dest(dcba));
    tsbond(dcba, bad);
    // Bond the other sides of cdab, dcba, they may outer space.
    sym(cdab, dcacasing);
    sym(dcba, cdbcasing);
    sesymself(abc);
    sesymself(bad);
    tsbond(dcacasing, abc);
    tsbond(cdbcasing, bad);          
  }
  // Do a 3-to-2 flip on face abc to remove tetrahedron abcd.
  flip32(&abcd, flipqueue);
  // Do flipping if necessary.
  if (flipqueue != (queue *) NULL) {
    flip(flipqueue, NULL, false, false, false);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// removekite()    Remove a degenerate kite from the mesh.                   //
//                                                                           //
// 'akite' (abcd) is a degenerate kite (i.e., a, b, c, and d are coplanar),  //
// and ab is the diagonal edge. It is removable if (a) either the face pair  //
// abc and abd or dca and dcb are hull faces, hence it can be peeled off; or //
// (b) it is an internal tet and either edge ab or cd can be flipped by a 3- //
// to-2 flip.  Remove the kite if it is in case (a) or (b) and return TRUE.  //
// Otherwise it is unremovable, do nothing and return FALSE.                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenmesh::removekite(triface* akite, queue* flipqueue)
{
  triface abcd, badc;  // Tet configuration at edge ab.
  triface baccasing, abdcasing;
  triface cdab, dcba;  // Tet configuration at edge cd.
  triface bcdcasing, cadcasing;
  face abseg, cdseg;

  abcd = *akite;
  adjustedgering(abcd, CCW);

  if (b->verbose > 1) {
    printf("    Removing kite (%d, %d, %d, %d).\n", pointmark(org(abcd)),
      pointmark(dest(abcd)), pointmark(apex(abcd)), pointmark(oppo(abcd)));
  }

  // Get the tet configuration at edge ab.
  fnext(abcd, badc);
  esymself(badc);
  sym(abcd, baccasing);
  sym(badc, abdcasing);
  tsspivot(&abcd, &abseg);
  // Is edge ab a subsegment?
  if (abseg.sh == dummysh) {
    // Can 'abcd' be peeled off?
    if ((baccasing.tet == dummytet) && (abdcasing.tet == dummytet)) {
      removetetbypeeloff(&abcd, flipqueue);
      return true;
    } 
    // Can edge 'ab' be flipped away?
    if (oppo(baccasing) == oppo(abdcasing)) {
      removetetbyflip32(&abcd, flipqueue);
      return true;
    }
  }

  // Get the tet configuration at edge cd.
  enextfnext(abcd, dcba); // dcba = bcda
  esymself(dcba); // dcba = cbda
  enext2self(dcba);
  enext2fnext(abcd, cdab); // cdab = cadb
  esymself(cdab); // cdab = acdb
  enextself(cdab);
  sym(dcba, bcdcasing);
  sym(cdab, cadcasing);
  tsspivot(&dcba, &cdseg);  
  // Is edge cd a subsegment?
  if (cdseg.sh == dummysh) {
    // Can 'abcd' be peeled off?
    if ((bcdcasing.tet == dummytet) && (cadcasing.tet == dummytet)) {
      removetetbypeeloff(&cdab, flipqueue);
      return true;
    }
    // Can edge 'cd' be flipped away?
    if (oppo(bcdcasing) == oppo(cadcasing)) {
      removetetbyflip32(&cdab, flipqueue);
      return true;
    }
  }

  if ((abseg.sh != dummysh) && (cdseg.sh != dummysh)) {
    // Two crossing segments in one tet.  This may be a error in the PLC.
    printf("Warning:  Segments (%d, %d) and (%d, %d) are cross each other.\n",
           pointmark(org(abcd)), pointmark(dest(abcd)), pointmark(apex(abcd)),
           pointmark(oppo(abcd)));
  } else if (abseg.sh != dummysh) {
    // ab is a segment, cd is an internal edge but not flippable.
  } else if (cdseg.sh != dummysh) {
    // cd is a segment, ab is an internal edge but not flippable.
  }

  return false;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// talldegetets()    Queue all the degenerate tetrahedra in the mesh.        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::talldegetets(list* degetetlist)
{
  triface tetloop;

  tetrahedrons->traversalinit();
  tetloop.tet = tetrahedrontraverse();
  while (tetloop.tet != (tetrahedron *) NULL) {
    checktet4dege(&tetloop, degetetlist);
    tetloop.tet = tetrahedrontraverse();
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// removedegetets()    Repair mesh by removing degenerate elements.          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::repairdegetets()
{
  list *degetetlist;
  queue *flipqueue;
  badface *degetet;
  int total, counter, i;

  if (!b->quiet) {
    printf("Removing degenerate tets.\n");
  }

  // Initialize the pool of bad tetrahedra.
  degetetlist = new list(sizeof(badface), NULL, 1024);
  total = 0;
  
  // Find all degenerate tetrahedra.
  talldegetets(degetetlist);
  do {
    // Initialize the counter of removed tets.
    counter = 0;
    for (i = 0; i < degetetlist->len(); i++) {
      degetet = (badface *)(* degetetlist)[i];
      if (!isdead(&degetet->tt) && (org(degetet->tt) == degetet->forg) &&
          (dest(degetet->tt) == degetet->fdest) &&
          (apex(degetet->tt) == degetet->fapex) &&
          (oppo(degetet->tt) == degetet->foppo)) {
        if (finddiagonal(&(degetet->tt))) {
          if (removekite(&(degetet->tt), NULL)) counter++;
        }
      }
    }
    if (counter == 0) {
      // No degenerate tet is removed.
      if (b->verbose && (degetetlist->len() > 0)) {
        printf("Warning:  %d degenerate tets survived.\n", degetetlist->len());
      }
      break;
    }
    // Accumulate the number of removed elements.
    total += counter; 
    // Some degenerate tets are removed. Continue the loop.
    degetetlist->clear();
    talldegetets(degetetlist);
  } while (degetetlist->len() > 0);

  if (total > 0) {
    // Some faces may become non-Delaunay. Check and correct them.
    flipqueue = new queue(sizeof(badface));
    checkdelaunay(0.0, flipqueue);
    if (!flipqueue->empty()) {
      // Call flip algorithm to recover Delaunayness.
      flip(flipqueue, NULL, false, false, false); 
    }
    delete flipqueue; 
  }

  if (b->verbose) {
    printf("  %ld degeneracies are removed.\n", total);
  }

  delete degetetlist;
}

//
// End of mesh repair routines
//

//
// Begin of Delaunay refinement routines
//

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// initializerpsarray()    Initialize the 'rpsarray'.                        //
//                                                                           //
// Calculate the initial radii of protecting spheres for all acute vertices. //
// During Delaunay refinement, each acute vertex v is protected by a sphere  //
// S(v, r), no point should be added inside S(v).  The radius r is chosen as //
// follows: Let w be another vertex connecting to v, (a) if w is acute, then //
// r_w = 1/3 |vw|; (b) is w is not acute, then r_w = 1/2 |vw|. r = min{r_w}. //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::initializerpsarray()
{
  list *neightetlist;
  tetrahedron tetptr;
  triface starttet, neightet;
  point pointloop, workpt[3];
  REAL rps, len;
  int i, j;  

  if (b->verbose) {
    printf("  Initializing protecting spheres.\n");
  }

  // Initialize the point2tet field of each point.
  points->traversalinit();
  pointloop = pointtraverse();
  while (pointloop != (point) NULL) {
    setpoint2tet(pointloop, (tetrahedron) NULL);
    pointloop = pointtraverse();
  }
  // Construct a map from points to tetrahedra.
  makepoint2tetmap();
  // Initialize 'neightetlist'.
  neightetlist = new list(sizeof(triface), NULL, 256);
  
  points->traversalinit();
  pointloop = pointtraverse();
  while (pointloop != (point) NULL) {
    tetptr = point2tet(pointloop);
    // Only calculate lfs(p) if it is acute and is not dangling.
    if ((pointtype(pointloop) == ACUTEVERTEX) &&
        (tetptr != (tetrahedron) NULL)) {
      decode(tetptr, starttet);
      assert((starttet.tet != NULL) && (starttet.tet != dummytet));
      // Find all tetrahedra sharing 'pointloop'.
      findorg(&starttet, pointloop);
      infect(starttet);
      neightetlist->append(&starttet);
      for (i = 0; i < neightetlist->len(); i++) {
        starttet = * (triface *)(* neightetlist)[i];
        assert(infected(starttet));
        // The origin of 'starttet' should be 'pointloop'.
        adjustedgering(starttet, CCW);
        if (org(starttet) != pointloop) {
          enextself(starttet);
        }
        assert(org(starttet) == pointloop);
        // Let 'starttet' be the opposite face of 'pointloop'.
        enextfnextself(starttet);
        assert(oppo(starttet) == pointloop);
        // Get three neighbors of faces having 'pointloop'.
        adjustedgering(starttet, CCW);
        for (j = 0; j < 3; j++) {
          fnext(starttet, neightet);
          symself(neightet);
          // Add it into list if is is not outer space and not infected.
          if ((neightet.tet != dummytet) && !infected(neightet)) {
            findorg(&neightet, pointloop);
            infect(neightet);
            neightetlist->append(&neightet);
          }
          enextself(starttet);
        }
      }
      // 'neightetlist' contains all tetrahedra sharing at 'pointloop'.
      rps = longest;
      for (i = 0; i < neightetlist->len(); i++) {
        starttet = * (triface *)(* neightetlist)[i];
        assert(org(starttet) == pointloop);
        workpt[0] = dest(starttet);
        workpt[1] = apex(starttet);
        workpt[2] = oppo(starttet);
        for (j = 0; j < 3; j++) {
          len = distance(workpt[j], pointloop);
          if (pointtype(workpt[j]) == ACUTEVERTEX) {
            len /= 3.0;
          } else {
            len /= 2.0;
          }
          if (len < rps) rps = len;
        }
      }
      // Return the local feature size of pointloop.
      rpsarray[pointmark(pointloop)] = rps;
      // Uninfect tetrahedra and clear 'neightetlist'.
      for (i = 0; i < neightetlist->len(); i++) {
        starttet = * (triface *)(* neightetlist)[i];
        uninfect(starttet);
      }
      neightetlist->clear();
    }
    pointloop = pointtraverse();
  }

  delete neightetlist;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// marksharpsubfaces()    Mark all sharp subfaces.                           //
//                                                                           //
// A subface is sharp if it belongs to a facet which forms an acute dihedral //
// angle (< 'dihedbound', given in degrees) with other facets. It is marked  //
// as SHARPSUB. (May be SHARPSKINNYSUB later by markskinnysubfaces().)       //
//                                                                           //
// This procedure operates in two phases.  The first phase finds some sharp  //
// subfaces by checking the dihedral angles of facets around segments.  The  //
// second phase finds all sharp subfaces by a neighbor-first search.         //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::marksharpsubfaces(REAL dihedbound)
{
  list *incishlist, *sharpshlist;
  triface adjtet; 
  face startsh, spinsh, neighsh;
  face segloop, prevseg, checkseg;
  point eorg, edest; 
  REAL small, angle;
  int i, j;

  if (b->verbose) {
    printf("  Marking sharp subfaces.\n");
  }

  small = dihedbound * PI / 180.;
  // Initial working lists.
  incishlist = new list(sizeof(face), NULL, 256);
  sharpshlist = new list(sizeof(face), NULL, subfaces->items);

  // Loop the set of segments, collect some sharp subfaces.
  subsegs->traversalinit();
  segloop.sh = shellfacetraverse(subsegs);
  while (segloop.sh != (shellface *) NULL) {
    // A segment may be split into many subsegments, Operate the one which
    //   contains the origin of the segment.
    segloop.shver = 0;
    senext2(segloop, prevseg);
    spivotself(prevseg);
    if (prevseg.sh == dummysh) {
      // Operate on this subsegment.
      segloop.shver = 0;
      spivot(segloop, startsh);
      assert(startsh.sh != dummysh);
      spivot(startsh, spinsh);
      if (spinsh.sh != startsh.sh) {
        // This subface is not self-bonded.
        eorg = sorg(segloop);
        edest = sdest(segloop);
        // Get all incident subfaces around 'segloop'.
        spinsh = startsh;
        do {
          if (sorg(spinsh) != eorg) {
            sesymself(spinsh);
          }
          incishlist->append(&spinsh);  
          spivotself(spinsh);
        } while (spinsh.sh != startsh.sh);
        // Check the pair of adjacent subfaces for small angle.
        spinsh = * (face *)(* incishlist)[0];
        for (i = 1; i <= incishlist->len(); i++) {
          if (i == incishlist->len()) {
            neighsh = * (face *)(* incishlist)[0];
          } else {
            neighsh = * (face *)(* incishlist)[i];
          }
          // Only do test when the side spinsh is faceing inward.
          stpivot(spinsh, adjtet);
          if (adjtet.tet != dummytet) {
            angle = facedihedral(eorg, edest, sapex(spinsh), sapex(neighsh));
            // Is angle acute?
            if (angle < small) {
              // Has spinsh been marked?
              if (shelltype(spinsh) != SHARPSUB) {
                setshelltype(spinsh, SHARPSUB);
                sharpshlist->append(&spinsh);
              }
              // Has neighsh been marked?
              if (shelltype(neighsh) != SHARPSUB) {
                setshelltype(neighsh, SHARPSUB);
                sharpshlist->append(&neighsh);
              }
            }
          }
          spinsh = neighsh;
        }
        incishlist->clear();
      }
    }
    segloop.sh = shellfacetraverse(subsegs);
  }

  // Next finds all sharp subfaces.
  for (i = 0; i < sharpshlist->len(); i++) {
    startsh = * (face *)(* sharpshlist)[i];
    assert(shelltype(startsh) == SHARPSUB);
    for (j = 0; j < 3; j++) {
      sspivot(startsh, checkseg);
      if (checkseg.sh == dummysh) {
        spivot(startsh, neighsh);
        if (shelltype(neighsh) != SHARPSUB) {
          setshelltype(neighsh, SHARPSUB);
          sharpshlist->append(&neighsh);
        }
      }
      senextself(startsh);
    }
  }

  if (b->verbose) {
    printf("  %d subfaces have been marked.\n", sharpshlist->len());
  }

  delete incishlist;
  delete sharpshlist;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// markskinnysubfaces()    Mark all skinny subfaces.                         //
//                                                                           //
// A subface is skinny if it has an angle smaller than 'anglebound' and the  //
// two edges form the angle are both segments. Such subface is not be able   //
// to refine.  It will be marked as type SKINNYSUB or SHARPSKINNYSUB.        //
//                                                                           //
// This procedure operates in two phases.  The first phase finds some skinny //
// subfaces by checking the angles of subfaces.  The second phase finds all  //
// skinny subfaces by a neighbor-first search.                               //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::markskinnysubfaces(REAL anglebound)
{
  list *skinnyshlist;
  face subloop, checksub;
  face startsh, neighsh;
  face seg1, seg2, checkseg;
  point pa, pb, pc;
  enum shestype shty;
  REAL small, angle;
  int i, j;

  if (b->verbose) {
    printf("  Marking skinny subfaces.\n");
  }

  small = anglebound * PI / 180.;
  // Initial working list.
  skinnyshlist = new list(sizeof(face), NULL, subfaces->items);

  // Loop the set of subfaces, collect some which are skinny.
  subfaces->traversalinit();
  subloop.sh = shellfacetraverse(subfaces);
  while (subloop.sh != (shellface *) NULL) {
    // Check the three angles of subloop;
    for (i = 0; i < 3; i++) {
      sspivot(subloop, seg1);
      if (seg1.sh != dummysh) {
        senext2(subloop, checksub);
        sspivot(checksub, seg2);
        if (seg2.sh != dummysh) {
          pa = sorg(subloop);
          pb = sdest(subloop);
          pc = sapex(subloop);
          angle = interiorangle(pa, pb, pc, NULL);
          if (angle < small) {
            // It is skinny!
            if (shelltype(subloop) == SHARPSUB) {
              setshelltype(subloop, SHARPSKINNYSUB);
            } else {
              setshelltype(subloop, SKINNYSUB);
            }
            skinnyshlist->append(&subloop);
            break;
          }
        }
      }
      senextself(subloop);
    }
    subloop.sh = shellfacetraverse(subfaces);
  }

  // Next finds all skinny subfaces.
  for (i = 0; i < skinnyshlist->len(); i++) {
    startsh = * (face *)(* skinnyshlist)[i];
    shty = shelltype(startsh);
    assert((shty == SKINNYSUB) || (shty == SHARPSKINNYSUB));
    for (j = 0; j < 3; j++) {
      sspivot(startsh, checkseg);
      if (checkseg.sh == dummysh) {
        spivot(startsh, neighsh);
        if (shelltype(neighsh) != shty) {
          setshelltype(neighsh, shty);
          skinnyshlist->append(&neighsh);
        }
      }
      senextself(startsh);
    }
  }

  if (b->verbose) {
    printf("  %d subfaces have been marked.\n", skinnyshlist->len());
  }

  delete skinnyshlist;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// dequeuebadtet()    Remove a tetrahedron from the front of the queue.      //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

tetgenmesh::badface* tetgenmesh::dequeuebadtet()
{
  badface *result;
  int queuenumber;

  // Look for a nonempty queue.
  for (queuenumber = 63; queuenumber >= 0; queuenumber--) {
    result = tetquefront[queuenumber];
    if (result != (badface *) NULL) {
      // Remove the tetrahedron from the queue.
      tetquefront[queuenumber] = result->nextitem;
      // Maintain a pointer to the NULL pointer at the end of the queue.
      if (tetquefront[queuenumber] == (badface *) NULL) {
        tetquetail[queuenumber] = &tetquefront[queuenumber];
      }
      return result;
    }
  }
  return (badface *) NULL;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// checkseg4encroach()    Check a subsegment to see if it is encroached.     //
//                                                                           //
// A subsegment is encroached if there is a vertex in its diametral circle   //
// (that is, the subsegment faces an angle greater than 90 degrees).         //
//                                                                           //
// If 'testpt' is not NULL, only check whether 'testseg' is encroached by it //
// or not. Otherwise, check all apexes of faces in mesh containing 'testseg'.//
// If 'pencpt' is not NULL, return the encroaching point if it exists.       //
//                                                                           //
// If testseg is found be encroached, add it into 'badsubsegs' if 'enqflag'  //
// is TRUE.  Return TRUE if testseg is encroached, otherwise return FALSE.   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenmesh::
checkseg4encroach(face* testseg, point testpt, point* pencpt, bool enqflag)
{
  badface *encsubseg;
  triface starttet, spintet;
  point eorg, edest, eapex, encpt;
  REAL cent[3], radius, dist, diff;
  bool enq;
  int hitbdry;

  eorg = sorg(*testseg);
  edest = sdest(*testseg);
  cent[0] = 0.5 * (eorg[0] + edest[0]);
  cent[1] = 0.5 * (eorg[1] + edest[1]);
  cent[2] = 0.5 * (eorg[2] + edest[2]);
  radius = distance(cent, eorg);

  enq = false;
  encpt = (point) NULL;
  if (testpt == (point) NULL) {
    // Check if it is encroached by traversing all faces containing it.
    sstpivot(testseg, &starttet);
    eapex = apex(starttet);
    spintet = starttet;
    hitbdry = 0;
    do {
      dist = distance(cent, apex(spintet));
      diff = dist - radius;
      if (fabs(diff) / radius <= b->epsilon) diff = 0.0; // Rounding.
      if (diff < 0.0) {
        enq = true;
        encpt = apex(spintet);
        break;
      }
      if (!fnextself(spintet)) {
        hitbdry++;
        if (hitbdry < 2) {
          esym(starttet, spintet);
          if (!fnextself(spintet)) {
            hitbdry++;
          } 
        }
      }
    } while (apex(spintet) != eapex && (hitbdry < 2));
  } else {
    // Only check if 'testseg' is encroached by 'testpt'.
    dist = distance(cent, testpt);
    diff = dist - radius;
    if (fabs(diff) / radius <= b->epsilon) diff = 0.0; // Rounding.
    enq = diff < 0.0;
  }

  if (enq && enqflag) {
    if (b->verbose > 2) {
      printf("    Queuing encroaching subsegment (%d, %d).\n",
             pointmark(eorg), pointmark(edest));
    }
    encsubseg = (badface *) badsubsegs->alloc();
    encsubseg->ss = *testseg;
    encsubseg->forg = eorg;
    encsubseg->fdest = edest;
    encsubseg->foppo = encpt;
    // Set the pointer of 'encsubseg' into 'testseg'.  It has two purposes:
    //   (1) We can regonize it is encroached; (2) It is uniquely queued.
    setshell2badface(encsubseg->ss, encsubseg);
  }
  
  if (pencpt != (point *) NULL) {
    *pencpt = encpt;
  }

  return enq;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// checksub4encroach()    Check a subface to see if it is encroached.        //
//                                                                           //
// A subface is encroached if there is a vertex in its diametral sphere. If  //
// 'testpt != NULL', only test if 'testsub' is encroached by it.  Otherwise, //
// test the opposites of the adjoining tetrahedra of 'testsub'.              //
//                                                                           //
// If testsub is found be encroached, add it into 'badsubfacess' if 'enqflag'//
// is TRUE.  Return TRUE if testsub is encroached, otherwise return FALSE.   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenmesh::checksub4encroach(face* testsub, point testpt, bool enqflag)
{
  badface *encsub;
  triface abuttet;
  point forg, fdest, fapex, encpt;
  REAL cent[3], radius, dist, diff;
  bool enq, ncollinear;
  int i;
  
  forg = sorg(*testsub);
  fdest = sdest(*testsub);
  fapex = sapex(*testsub);
  ncollinear = circumsphere(forg, fdest, fapex, NULL, cent, &radius);
  assert(ncollinear == true);
  
  enq = false;
  encpt = (point) NULL;  
  if (testpt == (point) NULL) {
    stpivot(*testsub, abuttet);
    if (abuttet.tet != dummytet) {
      dist = distance(cent, oppo(abuttet));
      diff = dist - radius;
      if (fabs(diff) / radius <= b->epsilon) diff = 0.0; // Rounding.
      enq = diff < 0.0;
      if (enq) encpt = oppo(abuttet);
    }
    if (!enq) {
      sesymself(*testsub);
      stpivot(*testsub, abuttet);
      if (abuttet.tet != dummytet) {
        dist = distance(cent, oppo(abuttet));
        diff = dist - radius;
        if (fabs(diff) / radius <= b->epsilon) diff = 0.0; // Rounding.
        enq = diff < 0.0;
        if (enq) encpt = oppo(abuttet);
      }
    }
  } else {
    // Only do test when 'testpt' is not one of its corners.
    if (testpt != forg && testpt != fdest && testpt != fapex) {
      dist = distance(cent, testpt);
      diff = dist - radius;
      if (fabs(diff) / radius <= b->epsilon) diff = 0.0; // Rounding.
      enq = diff < 0.0;
    }
  }

  if (enq && enqflag) {    
    encsub = (badface *) badsubfaces->alloc();
    encsub->ss = *testsub;
    encsub->forg = sorg(*testsub);
    encsub->fdest = sdest(*testsub);
    encsub->fapex = sapex(*testsub);
    encsub->foppo = encpt;
    for (i = 0; i < 3; i++) encsub->cent[i] = cent[i];
    encsub->nextitem = (badface *) NULL;
    // Set the pointer of 'encsubseg' into 'testsub'.  It has two purposes:
    //   (1) We can regonize it is encroached; (2) It is uniquely queued.
    setshell2badface(encsub->ss, encsub);
    // Add the subface to the end of a queue (quenumber = 0, low priority).
    *subquetail[0] = encsub;
    // Maintain a pointer to the NULL pointer at the end of the queue.
    subquetail[0] = &encsub->nextitem;
    if (b->verbose > 2) {
      printf("    Queuing encroached subface (%d, %d, %d).\n", 
             pointmark(forg), pointmark(fdest), pointmark(fapex));
    }
  }

  return enq;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// checkseg4badqual()    Check if a segment is longer than it is allowed.    //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenmesh::checkseg4badqual(face* testseg, bool enqflag)
{
  badface *encsubseg;
  point eorg, edest;
  REAL dist;
  bool enq;

  eorg = sorg(*testseg);
  edest = sdest(*testseg);
  dist = distance(eorg, edest);
  
  enq = dist > areabound(*testseg);

  if (enq && enqflag) {
    if (b->verbose > 2) {
      printf("    Queuing badqual subsegment (%d, %d).\n",
             pointmark(eorg), pointmark(edest));
    }
    encsubseg = (badface *) badsubsegs->alloc();
    encsubseg->ss = *testseg;
    encsubseg->forg = eorg;
    encsubseg->fdest = edest;
    encsubseg->foppo = NULL;
    // Set the pointer of 'encsubseg' into 'testseg'.  It has two purposes:
    //   (1) We can regonize it is encroached; (2) It is uniquely queued.
    setshell2badface(encsubseg->ss, encsubseg);
  }

  return enq;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// checksub4badqual()    Test if the quality of a subface is bad.            //
//                                                                           //
// A subface has bad quality if: (1) its minimum internal angle is smaller   //
// than 20 degree; or (2) its area is larger than a maximum area condition.  //
// Return TRUE if it is bad.                                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenmesh::checksub4badqual(face* testsub, bool enqflag)
{
  badface *encsub;
  face sametestsub;
  face subseg1, subseg2;
  point torg, tdest, tapex;
  point anglevertex;
  REAL dxod, dyod, dzod;
  REAL dxda, dyda, dzda;
  REAL dxao, dyao, dzao;
  REAL dxod2, dyod2, dzod2;
  REAL dxda2, dyda2, dzda2;
  REAL dxao2, dyao2, dzao2;
  REAL apexlen, orglen, destlen;
  REAL angle, area;
  bool enq;
  int i;

  enq = false;
  torg = sorg(*testsub);
  tdest = sdest(*testsub);
  tapex = sapex(*testsub);
  dxod = torg[0] - tdest[0];
  dyod = torg[1] - tdest[1];
  dzod = torg[2] - tdest[2];
  dxda = tdest[0] - tapex[0];
  dyda = tdest[1] - tapex[1];
  dzda = tdest[2] - tapex[2];
  dxao = tapex[0] - torg[0];
  dyao = tapex[1] - torg[1];
  dzao = tapex[2] - torg[2];
  dxod2 = dxod * dxod;
  dyod2 = dyod * dyod;
  dzod2 = dzod * dzod;
  dxda2 = dxda * dxda;
  dyda2 = dyda * dyda;
  dzda2 = dzda * dzda;
  dxao2 = dxao * dxao;
  dyao2 = dyao * dyao;
  dzao2 = dzao * dzao;
  // Find the lengths of the triangle's three edges.
  apexlen = dxod2 + dyod2 + dzod2;
  orglen = dxda2 + dyda2 + dzda2;
  destlen = dxao2 + dyao2 + dzao2;
  if ((apexlen < orglen) && (apexlen < destlen)) {
    // The edge opposite the apex is shortest.
    // Find the square of the cosine of the angle at the apex.
    angle = dxda * dxao + dyda * dyao + dzda * dzao;
    angle = angle * angle / (orglen * destlen);
    anglevertex = tapex;
    senext(*testsub, sametestsub);
    sspivot(sametestsub, subseg1);
    senext2(*testsub, sametestsub);
    sspivot(sametestsub, subseg2);
  } else if (orglen < destlen) {
    // The edge opposite the origin is shortest.
    // Find the square of the cosine of the angle at the origin.
    angle = dxod * dxao + dyod * dyao + dzod * dzao;
    angle = angle * angle / (apexlen * destlen);
    anglevertex = torg;
    sspivot(*testsub, subseg1);
    senext2(*testsub, sametestsub);
    sspivot(sametestsub, subseg2);
  } else {
    // The edge opposite the destination is shortest.
    // Find the square of the cosine of the angle at the destination.
    angle = dxod * dxda + dyod * dyda + dzod * dzda;
    angle = angle * angle / (apexlen * orglen);
    anglevertex = tdest;
    sspivot(*testsub, subseg1);
    senext(*testsub, sametestsub);
    sspivot(sametestsub, subseg2);
  }

  // Check if both edges that form the angle are segments.
  if ((subseg1.sh != dummysh) && (subseg2.sh != dummysh)) {
    // The angle is a segment intersection.  Don't add this bad subface to
    //   the list; there's nothing that can be done about a small angle
    //   between two segments.
    angle = 0.0;
  } 

  // Check whether the angle is smaller than permitted.
  if (angle > b->goodangle) {
    enq = true;
  }

  if (!enq && varconstraint && areabound(*testsub) > 0.0) {
    // Check whether the area is larger than desired.  A variation form of
    //   Heron's formula which only uses the squares of the edge lengthes
    //   is used to calculated the area of a 3D triangle.
    area = apexlen + orglen - destlen;
    area = area * area;
    area = 4 * apexlen * orglen - area;
    area = 0.25 * sqrt(fabs(area));
    enq = area > areabound(*testsub);
  }

  if (enq && enqflag) {    
    encsub = (badface *) badsubfaces->alloc();
    encsub->ss = *testsub;
    encsub->forg = sorg(*testsub);
    encsub->fdest = sdest(*testsub);
    encsub->fapex = sapex(*testsub);
    encsub->foppo = (point) NULL;
    // Circumcent of testsub is not available. Only initialize it.    
    for (i = 0; i < 3; i++) encsub->cent[i] = 0.0;
    encsub->nextitem = (badface *) NULL;
    // Set the pointer of 'encsubseg' into 'testsub'.  It has two purposes:
    //   (1) We can regonize it is encroached; (2) It is uniquely queued.
    setshell2badface(encsub->ss, encsub);
    // Add the subface to the end of a queue (quenumber = 1, high priority).
    *subquetail[1] = encsub;
    // Maintain a pointer to the NULL pointer at the end of the queue.
    subquetail[1] = &encsub->nextitem;
    if (b->verbose > 2) {
      printf("    Queuing badqual subface (%d, %d, %d).\n", pointmark(torg),
             pointmark(tdest), pointmark(tapex));
    }
  }

  return enq;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// checktet4badqual()    Test a tetrahedron for quality measures.            //
//                                                                           //
// Tests a tetrahedron to see if it satisfies the minimum ratio condition    //
// and the maximum volume condition. Tetrahedra that aren't upto spec are    //
// added to the bad tetrahedron queue.                                       //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenmesh::checktet4badqual(triface* testtet, bool enqflag)
{
  badface *newbadtet;
  point torg, tdest, tapex, toppo;
  REAL dxod, dyod, dzod, dxda, dyda, dzda, dxao, dyao, dzao;
  REAL dxop, dyop, dzop, dxdp, dydp, dzdp, dxap, dyap, dzap;
  REAL dxod2, dyod2, dzod2, dxda2, dyda2, dzda2, dxao2, dyao2, dzao2;
  REAL dxop2, dyop2, dzop2, dxdp2, dydp2, dzdp2, dxap2, dyap2, dzap2;
  REAL dxoc, dyoc, dzoc, dxoc2, dyoc2, dzoc2;
  REAL elen[6], circumcent[3];
  REAL smlen, volume;
  REAL radius, ratio2;
  bool enq;
  int queuenumber;
  int i;

  torg = org(*testtet);
  tdest = dest(*testtet);
  tapex = apex(*testtet);
  toppo = oppo(*testtet);

  dxod = torg[0] - tdest[0];
  dyod = torg[1] - tdest[1];
  dzod = torg[2] - tdest[2];
  dxda = tdest[0] - tapex[0];
  dyda = tdest[1] - tapex[1];
  dzda = tdest[2] - tapex[2];
  dxao = tapex[0] - torg[0];
  dyao = tapex[1] - torg[1];
  dzao = tapex[2] - torg[2];

  dxop = torg[0] - toppo[0];
  dyop = torg[1] - toppo[1];
  dzop = torg[2] - toppo[2];
  dxdp = tdest[0] - toppo[0];
  dydp = tdest[1] - toppo[1];
  dzdp = tdest[2] - toppo[2];
  dxap = tapex[0] - toppo[0];
  dyap = tapex[1] - toppo[1];
  dzap = tapex[2] - toppo[2];

  dxod2 = dxod * dxod;
  dyod2 = dyod * dyod;
  dzod2 = dzod * dzod;
  dxda2 = dxda * dxda;
  dyda2 = dyda * dyda;
  dzda2 = dzda * dzda;
  dxao2 = dxao * dxao;
  dyao2 = dyao * dyao;
  dzao2 = dzao * dzao;

  dxop2 = dxop * dxop;
  dyop2 = dyop * dyop;
  dzop2 = dzop * dzop;
  dxdp2 = dxdp * dxdp;
  dydp2 = dydp * dydp;
  dzdp2 = dzdp * dzdp;
  dxap2 = dxap * dxap;
  dyap2 = dyap * dyap;
  dzap2 = dzap * dzap;

  // Find the smallest edge length of 'testtet'.
  elen[0] = dxod2 + dyod2 + dzod2;
  elen[1] = dxda2 + dyda2 + dzda2;
  elen[2] = dxao2 + dyao2 + dzao2;
  elen[3] = dxop2 + dyop2 + dzop2;
  elen[4] = dxdp2 + dydp2 + dzdp2;
  elen[5] = dxap2 + dyap2 + dzap2;
  smlen = elen[0];
  for (i = 1; i < 6; i++) {
    if (smlen > elen[i]) {
      smlen = elen[i];
    }
  }

  // Find the circumcenter and circumradius of 'testtet'.
  circumsphere(torg, tdest, tapex, toppo, circumcent, NULL);
  dxoc = torg[0] - circumcent[0];
  dyoc = torg[1] - circumcent[1];
  dzoc = torg[2] - circumcent[2];
  dxoc2 = dxoc * dxoc;
  dyoc2 = dyoc * dyoc;
  dzoc2 = dzoc * dzoc;
  radius = dxoc2 + dyoc2 + dzoc2;
  
  // Calculate the square of radius-edge ratio.
  ratio2 = radius / smlen;
  // Check whether the ratio is smaller than permitted.
  enq = ratio2 > b->goodratio;
  if (!enq && (b->varvolume || b->fixedvolume)) {
    // The tet is in good shape.
    ratio2 = 0.0;
    // It will get split if it's volume is larger than permitted.
    volume = orient3d(torg, tdest, tapex, toppo);
    if (volume < 0) volume = -volume;
    volume /= 6.0;
    enq = b->fixedvolume && (volume > b->maxvolume);
    if (!enq && b->varvolume) {
      enq = (volume > volumebound(testtet->tet)) &&
            (volumebound(testtet->tet) > 0.0);
    }
  }

  if (enq && enqflag) {
    // Allocate space for the bad tetrahedron.
    newbadtet = (badface *) badtetrahedrons->alloc();
    newbadtet->tt = *testtet;
    newbadtet->key = ratio2;
    newbadtet->cent[0] = circumcent[0];
    newbadtet->cent[1] = circumcent[1];
    newbadtet->cent[2] = circumcent[2];
    newbadtet->forg = torg;
    newbadtet->fdest = tdest;
    newbadtet->fapex = tapex;
    newbadtet->foppo = toppo;
    newbadtet->nextitem = (badface *) NULL;
    // Determine the appropriate queue to put the bad tetrahedron into.
    if (ratio2 > b->goodratio) {
      queuenumber = (int) ((ratio2 - b->goodratio) / 0.5);
      // 'queuenumber' may overflow (negative) caused by a very large ratio.
      if ((queuenumber > 63) || (queuenumber < 0)) {
        queuenumber = 63;
      }
    } else {
      // It's not a bad ratio; put the tet in the lowest-priority queue.
      queuenumber = 0;
    }
    // Add the tetrahedron to the end of a queue.
    *tetquetail[queuenumber] = newbadtet;
    // Maintain a pointer to the NULL pointer at the end of the queue.
    tetquetail[queuenumber] = &newbadtet->nextitem;
    if (b->verbose > 2) {
      printf("    Queueing bad tet: (%d, %d, %d, %d), ratio %g, qnum %d.\n",
             pointmark(torg), pointmark(tdest), pointmark(tapex),
             pointmark(toppo), sqrt(ratio2), queuenumber);
    }
  }

  return enq;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// checktet4sliver()    Test a tetrahedron to see if it is a sliver.         //
//                                                                           //
// A tetrahedron is a sliver if it is not in bad quality with respect to the //
// radius-edge ratio, but contains large dihedral angle (> 175 degree).      //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenmesh::checktet4sliver(triface* testtet, bool enqflag)
{
  badface *newbadtet;
  point pa, pb, pc, pd;
  REAL da[6], maxdihedral;
  bool enq;
  int i;

  maxdihedral = 170.0 / 180.0 * PI;
  enq = false;
  if (!checktet4badqual(testtet, false)) {
    pa = org(*testtet);
    pb = dest(*testtet);
    pc = apex(*testtet);
    pd = oppo(*testtet);
    tetalldihedral(pa, pb, pc, pd, da);
    for (i = 0; i < 6; i++) {
      enq = da[i] > maxdihedral;
      if (enq) break;
    }
  }

  if (enq && enqflag) {
    // Allocate space for the bad tetrahedron.
    newbadtet = (badface *) badtetrahedrons->alloc();
    newbadtet->tt = *testtet;
    newbadtet->key = da[i];
    newbadtet->cent[0] = 0.0;
    newbadtet->cent[1] = 0.0;
    newbadtet->cent[2] = 0.0;
    newbadtet->forg = pa;
    newbadtet->fdest = pb;
    newbadtet->fapex = pc;
    newbadtet->foppo = pd;
    newbadtet->nextitem = (badface *) NULL;
    if (b->verbose > 2) {
      printf("    Queueing sliver: (%d, %d, %d, %d) %.12g.\n", pointmark(pa),
             pointmark(pb), pointmark(pc), pointmark(pd), da[i] / PI * 180.0);
    }
  }

  return enq;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// checkseg4splitting()    Check an encroached subsegment to see if it is    //
//                         suitable to be split.                             //
//                                                                           //
// Segment(ab) is encroached by an existing vertex or rejected circumcenter  //
// of a subface.  It can be split if it satifies the following cases:        //
//   (1) if ab is encroached by an existing vertex; else                     //
//   (2) if ab is too long wrt the edge constraint; else                     //
//   (3) if ab not belongs to a skinny subface, then split it if:            //
//       (a) both a and b are acute or nonacute; else,                       //
//       (b) assume a is acute, it can be split if |ab| > rps(a) / 2.0.      //
//   (4) When the facet constraint is in use. If there is a constrained      //
//       subface s containing ab, and |ab|^2 > a, a is the area bound of a.  //
//   (5) When the volume costraint (-a) is in use. If there is a constrained //
//       tet t containg ab, and |ab|^3 > v, v is the volume bound of t.      //
// The perpose of using values |ab|^2 and |ab|^3 instead of area and volume  //
// is to avoid resulting too skinny triangles and tetrahedron.               //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenmesh::checkseg4splitting(face* testseg, point* pencpt)
{
  triface spintet;
  face parentsh, spinsh;
  point eorg, edest, fapex;
  bool acuteorg, acutedest;
  REAL rpslimit, L, L2, L3;
  enum shestype shty;
  bool skinny;
  int ptidx;

  *pencpt = (point) NULL;
  
  // Is it encroached by an existing vertex?
  if (checkseg4encroach(testseg, NULL, pencpt, false)) {
    assert(*pencpt != (point) NULL);
    return true;
  }

  eorg = sorg(*testseg);
  edest = sdest(*testseg);
  L = distance(eorg, edest);

  // Is it in badqual?
  if (varconstraint && (areabound(*testseg) > 0.0)) {
    return L > areabound(*testseg);
  }

  // Check if ab belongs to a skinny subface.
  skinny = false;
  spivot(*testseg, parentsh);
  spinsh = parentsh;
  do {
    shty = shelltype(spinsh);
    if ((shty == SKINNYSUB) || (shty == SHARPSKINNYSUB)) {
      skinny = true; break;
    }
    spivotself(spinsh);
  } while (spinsh.sh != parentsh.sh);

  if (!skinny) {
    acuteorg = pointtype(eorg) == ACUTEVERTEX;
    acutedest = pointtype(edest) == ACUTEVERTEX;
    if ((acuteorg && acutedest) || (!acuteorg && !acutedest)) {
      // It can be split.
      return true;
    }
    // Now exactly one vertex is acute.
    assert(acuteorg || acutedest);
    if (acuteorg) {
      ptidx = pointmark(eorg);
    } else {
      assert(acutedest);
      ptidx = pointmark(edest);
    }
    rpslimit = rpsarray[ptidx] / 2.0;
    if (L > (rpslimit * 1.1)) {
      // The edge is not too small, can be split.
      return true;
    }
    // L <= rpslimit.
  }

  if (varconstraint && in->facetconstraintlist) {
    // Is there a subface which has too large area?
    L2 = L * L / 2.0;
    spinsh = parentsh;
    do {
      if ((L2 > areabound(spinsh)) && (areabound(spinsh) > 0.0)) {
        // This edge is too long wrt the maximum area bound. Split it.
        return true;
      }
      spivotself(spinsh);
    } while (spinsh.sh != parentsh.sh);
  }

  // L <= rpslimit.  We should not split it. However, it may still be
  //   split if its length is too long wrt. the volume constraints.
  if (b->varvolume || b->fixedvolume) {
    L = distance(eorg, edest);
    L3 = L * L * L / 6.0;
    if (b->fixedvolume && (L3 > b->maxvolume)) {
      // This edge is too long wrt. the maximum volume bound. Split it.
      return true; 
    } 
    if (b->varvolume) {
      spivot(*testseg, parentsh);
      if (sorg(parentsh) != eorg) sesymself(parentsh);
      stpivot(parentsh, spintet);
      if (spintet.tet == dummytet) {
        sesymself(parentsh);
        stpivot(parentsh, spintet);
        assert(spintet.tet != dummytet);
      }
      findedge(&spintet, eorg, edest);
      fapex = apex(spintet);
      while (true) {
        if (!fnextself(spintet)) {
          // Meet a boundary, walk through it.
          tspivot(spintet, spinsh);
          assert(spinsh.sh != dummysh);
          findedge(&spinsh, eorg, edest);
          sfnextself(spinsh);
          stpivot(spinsh, spintet);
          assert(spintet.tet != dummytet);
          findedge(&spintet, eorg, edest);
        }
        if ((L3 > volumebound(spintet.tet)) && 
            (volumebound(spintet.tet) > 0.0)) {
          // This edge is too long wrt the maximum volume bound. Split it.
          return true; 
        }
        if (apex(spintet) == fapex) break;
      }
    }
  }

  // Not split it.
  return false;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// checksub4splitting()    Check an encroached subface to see if it is       //
//                         suitable to be split.                             //
//                                                                           //
// Subface(abc) is in bad quality, or is encroached by an existing vertex or //
// by a rejected circumcenter of a tetrahedron.  It can be split if:         //
//   (1) it is in bad quality (indicated by 'bqual'); else,                  //
//   (2) it is not in bad quality and not sharp; else,                       //
//   (3) When the volume costraint (-a) is in use. If there is a tet t       //
//       containg abc, and L^3 > vol(t), where L := max{|ab|, |bc|, |ca|}.   //
// The purpose of using L^3 is to avoid resulting too skinny tetrahedron.    //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenmesh::checksub4splitting(face* testsh, bool bqual)
{
  triface testtet;
  point p[3];
  enum shestype shty;
  REAL L, L3;
  int i;

  if (bqual) {
    return true;
  } else {
    shty = shelltype(*testsh);
    if ((shty != SHARPSUB) && (shty != SHARPSKINNYSUB)) {
      return true;
    }
  }

  if (b->varvolume || b->fixedvolume) {
    // Check if it is in case (3).
    p[0] = sorg(*testsh);
    p[1] = sdest(*testsh);
    p[2] = sapex(*testsh);
    // Get the longest edge length of testsh = L.
    L = distance(p[0], p[1]);
    L3 = distance(p[1], p[2]);
    L = (L >= L3 ? L : L3);
    L3 = distance(p[2], p[0]);
    L = (L >= L3 ? L : L3);

    L3 = L * L * L / 6.0;
    if (b->fixedvolume && (L3 > b->maxvolume)) {
      // This face is too large wrt. the maximum volume bound. Split it.
      return true; 
    }
    if (b->varvolume) {
      for (i = 0; i < 2; i ++) {
        stpivot(*testsh, testtet);
        if (testtet.tet != dummytet) {
          if ((L3 > volumebound(testtet.tet)) && 
              (volumebound(testtet.tet) > 0.0)) {
            // This face is too large wrt the maximum volume bound.
            return true;
          }
        }
        sesymself(*testsh);
      }
    }
  }

  return false;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// doqualchecktetlist()    Put bad-quality tetrahedra in 'qualchecktetlist'  //
//                         into queue and clear it.                          //
//                                                                           //
// 'qualchecktetlist' stores a list of tetrahedra which are possibly bad-    //
// quality, furthermore, one tetrahedron may appear many times in it.  For   //
// testing and queuing each bad-quality tetrahedron only once, infect it     //
// after testing, later on, only test the one which is not infected.  On     //
// finish, uninfect them.                                                    //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::doqualchecktetlist()
{
  triface testtet;
  int i;

  for (i = 0; i < qualchecktetlist->len(); i++) {
    testtet = * (triface *) (* qualchecktetlist)[i];
    if (!isdead(&testtet) && !infected(testtet)) {
      checktet4badqual(&testtet, true);
      infect(testtet);
    }
  }
  for (i = 0; i < qualchecktetlist->len(); i++) {
    testtet = * (triface *) (* qualchecktetlist)[i];
    if (!isdead(&testtet) && infected(testtet)) {
      uninfect(testtet);
    }
  }
  qualchecktetlist->clear();
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// tallencsegs()    Check for encroached segments, save them in list.        //
//                                                                           //
// If 'testpt' is not a NULL, only check if segments are encroached by this  //
// point.  Otherwise, check all the nearby mesh vertices.                    //
//                                                                           //
// If 'cavtetlist' is not a NULL only check the segments in 'cavtetlist' to  //
// see if they're encroached.  Otherwise, check the entire list of segments. //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenmesh::tallencsegs(point testpt, list *cavtetlist)
{
  triface starttet, neightet;
  face checkseg;
  long oldencnum;
  int i, j;
  
  // Remember the current number of encroached segments.
  oldencnum = badsubsegs->items;

  if (cavtetlist != (list *) NULL) {
    // Check segments in the list of tetrahedra.
    for (i = 0; i < cavtetlist->len(); i++) {
      starttet = * (triface *)(* cavtetlist)[i];
      infect(starttet); // Indicate it has been tested.
      sym(starttet, neightet);
      if (!infected(neightet)) {
        // Test all three edges of this face.
        for (j = 0; j < 3; j++) {
          tsspivot(&starttet, &checkseg);
          if (checkseg.sh != dummysh) {
            if (!shell2badface(checkseg)) {
              checkseg4encroach(&checkseg, testpt, NULL, true);
            }
          }
          enextself(starttet);
        }
      }
      adjustedgering(starttet, CCW);
      fnext(starttet, neightet);
      symself(neightet);
      if ((neightet.tet == dummytet) || !infected(neightet)) {
        fnext(starttet, neightet);
        // Test the tow other edges of this face.
        for (j = 0; j < 2; j++) {
          enextself(neightet);
          tsspivot(&neightet, &checkseg);
          if (checkseg.sh != dummysh) {
            if (!shell2badface(checkseg)) {
              checkseg4encroach(&checkseg, testpt, NULL, true);
            }
          }
        }
      }
      enextfnext(starttet, neightet);
      symself(neightet);
      if ((neightet.tet == dummytet) || !infected(neightet)) {
        enextfnext(starttet, neightet);
        // Only test the next edge of this face.
        enextself(neightet);
        tsspivot(&neightet, &checkseg);
        if (checkseg.sh != dummysh) {
          if (!shell2badface(checkseg)) {
            checkseg4encroach(&checkseg, testpt, NULL, true);
          }
        }
      }
    }
    // Uninfect all tetrahedra in the list.
    for (i = 0; i < cavtetlist->len(); i++) {
      starttet = * (triface *)(* cavtetlist)[i];
      assert(infected(starttet));
      uninfect(starttet);
    }
  } else {
    // Check the entire list of segments.
    subsegs->traversalinit();
    checkseg.sh = shellfacetraverse(subsegs);
    while (checkseg.sh != (shellface *) NULL) {
      if (!shell2badface(checkseg)) {
        checkseg4encroach(&checkseg, testpt, NULL, true);
      }
      checkseg.sh = shellfacetraverse(subsegs);
    }
  }

  return (badsubsegs->items > oldencnum);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// tallencsubs()    Find all encroached subfaces and save them in list.      //
//                                                                           //
// If 'testpt' is not a NULL, only check if subfaces are encroached by this  //
// point.  Otherwise, check all the nearby mesh vertices.                    //
//                                                                           //
// If 'cavtetlist' is not a NULL only check the subfaces in 'cavtetlist' to  //
// see if they're encroached.  Otherwise, check the entire list of subfaces. //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenmesh::tallencsubs(point testpt, list* cavtetlist)
{
  triface starttet, neightet;
  face checksh;
  long oldencnum;
  int i, j;
  
  // Remember the current number of encroached segments.
  oldencnum = badsubfaces->items;

  if (cavtetlist != (list *) NULL) {
    // Check subfaces in the list of tetrahedra.
    for (i = 0; i < cavtetlist->len(); i++) {
      starttet = * (triface *)(* cavtetlist)[i];
      infect(starttet); // Indicate it has been tested.
      sym(starttet, neightet);
      if (!infected(neightet)) {
        // Test if this face is encroached.
        tspivot(starttet, checksh);
        if (checksh.sh != dummysh) {
          // If it is not encroached, test it.
          if (shell2badface(checksh) == NULL) {
            checksub4encroach(&checksh, testpt, true);
          }
        }
      }
      adjustedgering(starttet, CCW);
      // Check the other three sides of this tet.
      for (j = 0; j < 3; j++) {
        fnext(starttet, neightet);
        symself(neightet);
        if ((neightet.tet == dummytet) || !infected(neightet)) {
          fnext(starttet, neightet);
          // Test if this face is encroached.
          tspivot(neightet, checksh);
          if (checksh.sh != dummysh) {
            // If it is not encroached, test it.
            if (shell2badface(checksh) == NULL) {
              checksub4encroach(&checksh, testpt, true);
            }
          }
        }
        enextself(starttet);
      }
    }
    // Uninfect all tetrahedra in the list.
    for (i = 0; i < cavtetlist->len(); i++) {
      starttet = * (triface *)(* cavtetlist)[i];
      assert(infected(starttet));
      uninfect(starttet);
    }
  } else {
    // Check the entire list of subfaces.
    subfaces->traversalinit();
    checksh.sh = shellfacetraverse(subfaces);
    while (checksh.sh != (shellface *) NULL) {
      // If it is not encroached, test it.
      if (shell2badface(checksh) == NULL) {
        checksub4encroach(&checksh, testpt, true);
      }
      checksh.sh = shellfacetraverse(subfaces);
    }
  }

  return (badsubfaces->items > oldencnum);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// tallencsubsfseg()    Find all bad-qual or enc subfaces at a segment.      //
//                                                                           //
// This routine is called in repairencsegs() directly after a seg is split.  //
// 'testseg' is the one of the two resulting subsegments.                    //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::tallencsubsfseg(face* testseg)
{
  face startsh, spinsh, checksh;
  face splitseg, checkseg;

  splitseg = *testseg;
  // Check the subfaces link of splitseg to see if they're encroached.
  spivot(splitseg, startsh);
  spinsh = startsh;
  do {
    findedge(&spinsh, sorg(splitseg), sdest(splitseg));
    // The next two lines are only for checking.
    sspivot(spinsh, checkseg);
    assert(checkseg.sh == splitseg.sh);
    checksh = spinsh;
    if (!shell2badface(checksh)) {
      checksub4badqual(&checksh, true);
    }
    if (!shell2badface(checksh)) {
      checksub4encroach(&checksh, NULL, true);
    }
    // The above operation may change the edge.
    findedge(&spinsh, sorg(splitseg), sdest(splitseg));
    spivotself(spinsh);
  } while (spinsh.sh != startsh.sh);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// tallbadsegs()    Find all bad-quality segments and save them in list.     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::tallbadsegs()
{
  face checkseg;

  subsegs->traversalinit();
  checkseg.sh = shellfacetraverse(subsegs);
  while (checkseg.sh != (shellface *) NULL) {
    if (varconstraint && (areabound(checkseg) > 0.0)) {
      checkseg4badqual(&checkseg, true);
    }
    checkseg.sh = shellfacetraverse(subsegs);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// tallbadsubs()    Find all bad-quality subfaces and save them in list.     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::tallbadsubs()
{
  face checksh;

  subfaces->traversalinit();
  checksh.sh = shellfacetraverse(subfaces);
  while (checksh.sh != (shellface *) NULL) {
    checksub4badqual(&checksh, true);
    checksh.sh = shellfacetraverse(subfaces);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// tallbadtetrahedrons()    Queue all the bad-quality tetrahedra in the mesh.//
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::tallbadtetrahedrons()
{
  triface tetloop;

  tetrahedrons->traversalinit();
  tetloop.tet = tetrahedrontraverse();
  while (tetloop.tet != (tetrahedron *) NULL) {
    checktet4badqual(&tetloop, true);
    tetloop.tet = tetrahedrontraverse();
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// tallslivers()    Queue all the slivers in the mesh.                       //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::tallslivers()
{
  triface tetloop;

  tetrahedrons->traversalinit();
  tetloop.tet = tetrahedrontraverse();
  while (tetloop.tet != (tetrahedron *) NULL) {
    checktet4sliver(&tetloop, true);
    tetloop.tet = tetrahedrontraverse();
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// getsplitpoint1()    Get a suitable point for splitting a segment.         //
//                                                                           //
// 'splitseg' is going to be split.  This routine finds a suitable point in  //
// it.  The rules of finding point are similar to that of getsplitpoint().   //
// If 'encpt != NULL', it encroaches 'splitseg'.                             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::getsplitpoint1(face* splitseg, REAL* splitpt, point encpt)
{
  point ei, ej, ek;
  point farorg, fardest;
  REAL dij, dip, djp;
  REAL dvj, dvp, div;
  REAL dki, dkj, dkp;
  REAL split;
  bool acuteorg, acutedest;
  int i;

  ei = sorg(*splitseg);
  ej = sdest(*splitseg);
  if (encpt == (point) NULL) {
    // No existing point encroaches the seg. Split it at the middle.
    for (i = 0; i < 3; i++) splitpt[i] = ei[i] + 0.5 * (ej[i] - ei[i]);
    return;
  }

  acuteorg = (pointtype(ei) == ACUTEVERTEX);
  acutedest = (pointtype(ej) == ACUTEVERTEX);
  
  if (acuteorg && acutedest) {
    // Use rule 1.
    dij = distance(ei, ej);
    dip = distance(ei, encpt);
    djp = distance(ej, encpt);
    if (dip < 0.5 * dij) {
      split = dip / dij;
    } else if (djp < 0.5 * dij) {
      split = (dij - djp) / dij;
    } else {
      split = 0.5;
    }
    for (i = 0; i < 3; i++) splitpt[i] = ei[i] + split * (ej[i] - ei[i]);
    return;
  }
  if (acuteorg || acutedest) {
    if (!acuteorg) {
      // eorg is not acute, but edest is. Exchange eorg, edest.
      ei = ej;
      ej = sorg(*splitseg);
    }
    // Now, eorg must be acute.
    // Try to split it by rule-2.      
    dij = distance(ei, ej);
    dip = distance(ei, encpt);
    split = dip / dij;
    for (i = 0; i < 3; i++) splitpt[i] = ei[i] + split * (ej[i] - ei[i]);
    dvj = dij - dip;
    dvp = distance(splitpt, encpt);
    if (dvj < dvp) {
      // v is rejected, use rule-3.
      split = 0.5 * dip / dij;
      for (i = 0; i < 3; i++) splitpt[i] = ei[i] + split * (ej[i] - ei[i]);
    }
    return;
  }

  // Both ei and ej are nonacute.
  farorg = getsegmentorigin(splitseg);
  acuteorg = (pointtype(farorg) == ACUTEVERTEX);
  sesymself(*splitseg);
  fardest = getsegmentorigin(splitseg);
  acutedest = (pointtype(fardest) == ACUTEVERTEX);
  sesymself(*splitseg);
  
  if (acuteorg || acutedest) {
    if (acuteorg && acutedest) {
      // Always use the vertex having smaller index.
      if (pointmark(farorg) < pointmark(fardest)) {
        acutedest = false;
      } else {
        acuteorg = false;
      }
    }
    if (!acuteorg) {
      // eorg is not acute, but edest is.
      assert(acutedest);
      // Exchange eorg, edest.
      ei = ej;
      ej = sorg(*splitseg);
      ek = fardest;
    } else {
      ek = farorg;
    }
    // Try use rule-2.
    dki = distance(ek, ei); 
    dkj = distance(ek, ej);
    dkp = distance(ek, encpt);
    split = dkp / dkj;
    for (i = 0; i < 3; i++) splitpt[i] = ek[i] + split * (ej[i] - ek[i]);
    // v may too close to ei or ej. If any of these happens, reject v.
    dvp = distance(splitpt, encpt);
    div = distance(ei, splitpt);
    dvj = distance(splitpt, ej);
    if ((div < dvp) || (dvj < dvp)) {
      // Reject v. Use the middle point of ei and ej.
      for (i = 0; i < 3; i++) splitpt[i] = ei[i] + 0.5 * (ej[i] - ei[i]);
    }
  } else {
    // No far acute points. Use rule 1.
    dij = distance(ei, ej);
    dip = distance(ei, encpt);
    djp = distance(ej, encpt);
    if (dip < 0.5 * dij) {
      split = dip / dij;
    } else if (djp < 0.5 * dij) {
      split = (dij - djp) / dij;
    } else {
      split = 0.5;
    }
    for (i = 0; i < 3; i++) splitpt[i] = ei[i] + split * (ej[i] - ei[i]);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// repairencsegs()    Repair all the encroached segments.                    //
//                                                                           //
// Encroached segments are in 'badsubsegs'.  Each queued segment is repaired //
// by inserting a point somewhere in it.  Newly inserted points may encroach //
// upon other segments, these are also repaired.                             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::repairencsegs(queue* flipqueue)
{
  badface *encloop;
  triface starttet;
  face splitseg, symsplitseg;
  point eorg, edest, encpt;
  point newpoint, sympoint;
  enum locateresult symloc;
  bool chkencsubs, chkbadqual;
  int i, j;

  if (b->verbose > 1) {
    printf("  Splitting encroached subsegments.\n");
  }

  // Note that steinerleft == -1 if an unlimited number of Steiner points 
  //   is allowed.  Loop until 'badsubsegs' is empty.
  while ((badsubsegs->items > 0) && (steinerleft != 0)) {
    badsubsegs->traversalinit();
    encloop = badfacetraverse(badsubsegs);
    while ((encloop != (badface *) NULL) && (steinerleft != 0)) {
      splitseg = encloop->ss;
      // Every splitseg has a pointer to encloop, now clear it.
      assert(shell2badface(splitseg) == encloop);
      setshell2badface(splitseg, NULL);
      eorg = sorg(splitseg);
      edest = sdest(splitseg);
      if ((eorg == encloop->forg) && (edest == encloop->fdest)) {
        if (b->verbose > 1) {
          printf("  Get seg (%d, %d) ", pointmark(eorg), pointmark(edest));
          printf("enc by %d.\n", encloop->foppo != (point) NULL ? 
                 pointmark(encloop->foppo) : 0);
        }
        // Split the seg if (1) it is encroached by an existing vertex, or
        //   (2) it is permitted to be split.
        if (checkseg4splitting(&splitseg, &encpt)) {
          // Create the new point.
          makepoint(&newpoint);
          // Decide the position to split the segment.
          getsplitpoint1(&splitseg, newpoint, encpt);
          // Set the parent point into the newpoint.
          setpoint2ppt(newpoint, encpt);
          // Set the type of the newpoint.
          setpointtype(newpoint, FREESEGVERTEX);
          // Set splitseg into the newpoint.
          // setpoint2sh(newpoint, sencode(splitseg));
          // Has subface confoming started?
          chkencsubs = badsubfaces != (memorypool *) NULL;
          // Has quality mesh started?
          chkbadqual = badtetrahedrons != (memorypool *) NULL;

          // Is there periodic boundary condition?
          if (checkpbcs) {
            // Yes! Insert points on other segments of incident pbcgroups.
            i = shellmark(splitseg) - 1;
            for (j = idx2segpglist[i]; j < idx2segpglist[i + 1]; j++) {
              makepoint(&sympoint);
              symloc = getsegpbcsympoint(newpoint, &splitseg, sympoint,
                                         &symsplitseg, segpglist[j]);
              assert(symloc != OUTSIDE);
              if (symloc == ONEDGE) {
                assert(symsplitseg.sh != dummysh);
                setpointtype(sympoint, FREESEGVERTEX);
                // setpoint2sh(sympoint, sencode(symsplitseg));
                // Insert sympoint into the mesh.
                symsplitseg.shver = 0;
                sstpivot(&symsplitseg, &starttet);
                splittetedge(sympoint, &starttet, flipqueue);
                if (steinerleft > 0) steinerleft--;
                // Check the two new subsegs to see if they're encroached.
                //   Note, symsplitseg may have already been queued.
                if (!shell2badface(symsplitseg)) {
                  if (varconstraint && (areabound(symsplitseg) > 0.0)) {
                    checkseg4badqual(&symsplitseg, true);
                  }
                }
                if (!shell2badface(symsplitseg)) {
                  checkseg4encroach(&symsplitseg, NULL, NULL, true);
                }
                if (chkencsubs) {
                  // Find encroaching subfaces around s.
                  tallencsubsfseg(&symsplitseg);
                }
                senextself(symsplitseg);
                spivotself(symsplitseg);
                assert(symsplitseg.sh != (shellface *) NULL);
                symsplitseg.shver = 0;
                // symsplitseg is a new segment and has not been queued.
                assert(shell2badface(symsplitseg) == (badface *) NULL);
                if (varconstraint && (areabound(symsplitseg) > 0.0)) {
                  checkseg4badqual(&symsplitseg, true);
                }
                if (!shell2badface(symsplitseg)) {
                  checkseg4encroach(&symsplitseg, NULL, NULL, true);
                }
                if (chkencsubs) {
                  // Find encroaching subfaces around s.
                  tallencsubsfseg(&symsplitseg);
                }
                // Recover Delaunay property by flipping.
                flip(flipqueue, NULL, true, chkencsubs, chkbadqual);
              } else if (symloc == ONVERTEX) {
                // The sympoint already exists. It is possible when two
                //   pbc groups are exactly the same. Omit this point.
                pointdealloc(sympoint);
              }
            }
          }

          // Insert new point into the mesh. It should be always success.
          splitseg.shver = 0;
          sstpivot(&splitseg, &starttet);
          splittetedge(newpoint, &starttet, flipqueue);
          if (steinerleft > 0) steinerleft--;
          // Check the two new subsegments to see if they're encroached.
          //   Note, splitseg may have already been queued.
          if (!shell2badface(splitseg)) {
            if (varconstraint && (areabound(splitseg) > 0.0)) {
              checkseg4badqual(&splitseg, true);
            }
          }
          if (!shell2badface(splitseg)) {
            checkseg4encroach(&splitseg, NULL, NULL, true);
          }
          if (chkencsubs) {
            // Find encroaching subfaces around s.
            tallencsubsfseg(&splitseg);
          }
          senextself(splitseg);
          spivotself(splitseg);
          assert(splitseg.sh != (shellface *) NULL);
          splitseg.shver = 0;
          // splitseg is a new segment and has not been queued.
          assert(shell2badface(splitseg) == (badface *) NULL);
          if (varconstraint && (areabound(splitseg) > 0.0)) {
            checkseg4badqual(&splitseg, true);
          }
          if (!shell2badface(splitseg)) {
            checkseg4encroach(&splitseg, NULL, NULL, true);
          }
          if (chkencsubs) {
            // Find encroaching subfaces around s.
            tallencsubsfseg(&splitseg);
          }
          // Recover Delaunay property by flipping. Existing segments which
          //   are encroached by newpoint will be discovered and queued.
          flip(flipqueue, NULL, true, chkencsubs, chkbadqual);
          
          // Queuing bad-quality tetrahedra if need.
          if (chkbadqual) {
            doqualchecktetlist();
          }
        }
      } else {
        // Splitseg has been split. Check it for encroachment.
        if (varconstraint && (areabound(splitseg) > 0.0)) {
          checkseg4badqual(&splitseg, true);
        }
        if (!shell2badface(splitseg)) {
          checkseg4encroach(&splitseg, NULL, NULL, true);
        }
      }

      // Remove this entry from list.
      badfacedealloc(badsubsegs, encloop);  
      // Get the next encroached segments.
      encloop = badfacetraverse(badsubsegs);
    }
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// repairencsubs()    Repair all the encroached subfaces.                    //
//                                                                           //
// Encroached subfaces are in pool 'badsubfaces'. Each encroached subface is //
// repaired by inserting a point near its circumcenter. However, If the new  //
// point encroaches upon one or more segments, it is not inserted.  Instead  //
// the encroached segments are split. Newly added points may encroach upon   //
// other subfaces, these are also repaired.                                  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::repairencsubs(list* cavtetlist, queue* flipqueue)
{
  badface *encloop;
  triface starttet, symstarttet;
  face splitsub, symsplitsub, neisplitsub;
  face checksh, checkseg;
  point newpoint, sympoint;
  point checkpt, pa, pb;
  enum locateresult loc, symloc;
  REAL epspp, dist;
  bool reject, chkbadqual;
  int quenumber;
  int epscount;
  int i;

  if (b->verbose > 1) {
    printf("  Splitting encroached subfaces.\n");
  }

  // Note that steinerleft == -1 if an unlimited number of Steiner points
  //   is allowed.  Loop until the list 'badsubfaces' is empty.
  while ((badsubfaces->items > 0) && (steinerleft != 0)) {
    // Look for a nonempty queue.
    encloop = (badface *) NULL;
    for (quenumber = 1; quenumber >= 0; quenumber--) {
      encloop = subquefront[quenumber];
      if (encloop != (badface *) NULL) {
        // Remove the badface from the queue.
        subquefront[quenumber] = encloop->nextitem;
        // Maintain a pointer to the NULL pointer at the end of the queue.
        if (subquefront[quenumber] == (badface *) NULL) {
          subquetail[quenumber] = &subquefront[quenumber];
        }
        break;
      }
    }
    assert(encloop != (badface *) NULL);
    // Clear the pointer saved in encloop->ss. 
    splitsub = encloop->ss;
    setshell2badface(splitsub, NULL);
    // The subface may be not the same one when it was determined to be
    //   encroached.  If its adjacent encroached subface was split, the
    //   consequent flips may change it into another subface.
    if ((sorg(splitsub) == encloop->forg) &&
        (sdest(splitsub) == encloop->fdest) &&
        (sapex(splitsub) == encloop->fapex)) {
      if (b->verbose > 1) {
        printf("    Dequeuing ensub (%d, %d, %d) [%d].\n",
               pointmark(encloop->forg), pointmark(encloop->fdest),
               pointmark(encloop->fapex), quenumber);
      }
      if (checksub4splitting(&splitsub, (quenumber == 1))) {
        // We can split this subface.
        makepoint(&newpoint);
        // If it is a bad quality face, calculate its circumcenter.
        if (quenumber == 1) {
          circumsphere(encloop->forg, encloop->fdest, encloop->fapex, NULL,
                       encloop->cent, NULL);
        }
        // Set the coordinates of newpoint.
        for (i = 0; i < 3; i++) newpoint[i] = encloop->cent[i];
        // Set the type of the newpoint.
        setpointtype(newpoint, FREESUBVERTEX);
        
        // Locate the newpoint in facet (resulting in splitsub).
        loc = locatesub(newpoint, &splitsub, 1);
        stpivot(splitsub, starttet);
        if (starttet.tet == dummytet) {
          sesymself(splitsub);
          stpivot(splitsub, starttet);
        }
        assert(starttet.tet != dummytet);
        // Look if the newpoint encroaches upon any segment.
        cavtetlist->append(&starttet);
        collectcavtets(newpoint, cavtetlist);
        assert(cavtetlist->len() > 0);
        reject = tallencsegs(newpoint, cavtetlist);
        // Clear the list for the next use.
        cavtetlist->clear();
        if (!reject) {
          // Remove the encroached subface by inserting the newpoint.
          if (loc != ONVERTEX) {
            // Adjust the location of newpoint wrt. starttet.
            epspp = b->epsilon;
            epscount = 0;
            while (epscount < 32) {
              loc = adjustlocate(newpoint, &starttet, ONFACE, epspp);
              if (loc == ONVERTEX) {
                checkpt = org(starttet);
                dist = distance(checkpt, newpoint);
                if ((dist / longest) > b->epsilon) {
                  epspp *= 1.0e-1;
                  epscount++;
                  continue;
                }
              }
              break;
            }
          }
          pa = org(starttet);
          pb = dest(starttet);
          findedge(&splitsub, pa, pb);

          // Has quality mesh started?
          chkbadqual = badtetrahedrons != (memorypool *) NULL;

          if (checkpbcs) {
            if (shellpbcgroup(splitsub) >= 0) {
              makepoint(&sympoint);
              symloc = getsubpbcsympoint(newpoint, &splitsub, sympoint,
                                         &symsplitsub);
              assert(symloc != ONVERTEX);
              setpoint2pbcpt(newpoint, sympoint);
              setpoint2pbcpt(sympoint, newpoint);
              // Set the type of sympoint.
              setpointtype(sympoint, FREESUBVERTEX);
              stpivot(symsplitsub, symstarttet);
              if (symstarttet.tet == dummytet) {
                sesymself(symsplitsub);
                stpivot(symsplitsub, symstarttet);
              }
              assert(symstarttet.tet != dummytet);
              // Adjust symstarttet be the same edge as symsplitsub.
              pa = sorg(symsplitsub);
              pb = sdest(symsplitsub);
              findedge(&symstarttet, pa, pb);
              // 'symsplitsub' is face abc.  ab is the current edge.
              if (symloc == ONFACE) {
                // Split the face abc into three faces abv, bcv, cav. 
                splittetface(sympoint, &symstarttet, flipqueue);
                // Adjust symsplitsub be abv.
                findedge(&symsplitsub, pa, pb);
                assert(sapex(symsplitsub) == sympoint);
                // Check the three new subfaces to see if they're encroached.
                //   symsplitsub may be queued (it exists before split).
                checksh = symsplitsub;
                if (!shell2badface(checksh)) {
                  checksub4badqual(&checksh, true); // abv
                }
                if (!shell2badface(checksh)) {
                  checksub4encroach(&checksh, NULL, true); // abv
                }
                senext(symsplitsub, checksh);
                spivotself(checksh);
                // It is a new created face and should not be infected.
                assert(checksh.sh != dummysh && !shell2badface(checksh));
                checksub4badqual(&checksh, true); // bcv
                if (!shell2badface(checksh)) {
                  checksub4encroach(&checksh, NULL, true); // bcv
                }
                senext2(symsplitsub, checksh);
                spivotself(checksh);
                // It is a new created face and should not be infected.
                assert(checksh.sh != dummysh && !shell2badface(checksh));
                checksub4badqual(&checksh, true); // cav
                if (!shell2badface(checksh)) {
                  checksub4encroach(&checksh, NULL, true); // cav
                }
              } else if (symloc == ONEDGE) {
                // Let the adjacent subface be bad.  ab is the spliting edge.
                //   Split 2 faces: abc, bad into 4: avc, vbc, avd, vbd.
                sspivot(symsplitsub, checkseg);
                assert(checkseg.sh == dummysh);
                // Remember the neighbor subface abd (going to be split too).
                spivot(symsplitsub, neisplitsub);
                findedge(&neisplitsub, pa, pb);
                // Split 2 faces: abc, abd into 4: avc, vbc, avd, vbd.
                splittetedge(sympoint, &symstarttet, flipqueue);
                // Adjust symsplitsub be avc, neisplitsub be avd.
                findedge(&symsplitsub, pa, sympoint);
                findedge(&neisplitsub, pa, sympoint);
                // Check the four new subfaces to see if they're encroached.
                //   splitsub may be infected (it exists before the split).
                checksh = symsplitsub;
                if (!shell2badface(checksh)) {
                  checksub4badqual(&checksh, true); // avc
                }
                if (!shell2badface(checksh)) {
                  checksub4encroach(&checksh, NULL, true); // avc
                }
                //   Get vbc.
                senext(symsplitsub, checksh);
                spivotself(checksh);
                //   vbc is newly created.
                assert(checksh.sh != dummysh && !shell2badface(checksh));
                checksub4badqual(&checksh, true); // vbc
                if (!shell2badface(checksh)) {
                  checksub4encroach(&checksh, NULL, true); // vbc
                }
                //   neisplitsub may be infected (exists before the split).
                checksh = neisplitsub;
                if (!shell2badface(checksh)) {
                  checksub4badqual(&checksh, true); // avd
                }
                if (!shell2badface(checksh)) {
                  checksub4encroach(&checksh, NULL, true); // avd
                }
                //   Get vbd.
                senext(neisplitsub, checksh);
                spivotself(checksh);
                //   vbd is newly created.
                assert(checksh.sh != dummysh && !shell2badface(checksh));
                checksub4badqual(&checksh, true); // vbd
                if (!shell2badface(checksh)) {
                  checksub4encroach(&checksh, NULL, true); // vbd
                }
              } else {
                // Delete the sympoint.
                pointdealloc(sympoint);
              }
              if ((symloc == ONFACE) || (symloc == ONEDGE)) {
                if (steinerleft > 0) steinerleft--;
                // Recover Delaunay property by flipping.
                flip(flipqueue, NULL, false, true, chkbadqual);
                // There should be no encroached segments.
                // assert(badsubsegs->items == 0);
                // Queuing bad-quality tetrahedra if need.
                if (chkbadqual) {
                  doqualchecktetlist();
                }
              }
            }
          }
          
          stpivot(splitsub, starttet);
          if (starttet.tet == dummytet) {
            sesymself(splitsub);
            stpivot(splitsub, starttet);
          }
          assert(starttet.tet != dummytet);
          // Adjust starttet be the same edge as splitsub.
          pa = sorg(splitsub);
          pb = sdest(splitsub);
          findedge(&starttet, pa, pb);
          // 'splitsub' is face abc.  ab is the current edge.
          if (loc == ONFACE) {
            // Split the face abc into three faces abv, bcv, cav. 
            splittetface(newpoint, &starttet, flipqueue);
            // Adjust splitsub be abv.
            findedge(&splitsub, pa, pb);
            assert(sapex(splitsub) == newpoint);
            // Check the three new subfaces to see if they're encroached.
            //   splitsub may be queued (it exists before split).
            checksh = splitsub;
            if (!shell2badface(checksh)) {
              checksub4badqual(&checksh, true); // abv
            }
            if (!shell2badface(checksh)) {
              checksub4encroach(&checksh, NULL, true); // abv
            }
            senext(splitsub, checksh);
            spivotself(checksh);
            // It is a new created face and should not be infected.
            assert(checksh.sh != dummysh && !shell2badface(checksh));
            checksub4badqual(&checksh, true); // bcv
            if (!shell2badface(checksh)) {
              checksub4encroach(&checksh, NULL, true); // bcv
            }
            senext2(splitsub, checksh);
            spivotself(checksh);
            // It is a new created face and should not be infected.
            assert(checksh.sh != dummysh && !shell2badface(checksh));
            checksub4badqual(&checksh, true); // cav
            if (!shell2badface(checksh)) {
              checksub4encroach(&checksh, NULL, true); // cav
            }
          } else if (loc == ONEDGE) {
            // Let the adjacent subface be bad.  ab is the spliting edge.
            //   Split 2 faces: abc, bad into 4: avc, vbc, avd, vbd.
            sspivot(splitsub, checkseg);
            assert(checkseg.sh == dummysh);
            // Remember the neighbor subface abd (going to be split too).
            spivot(splitsub, neisplitsub);
            findedge(&neisplitsub, pa, pb);
            // Split two faces abc, abd into four faces avc, vbc, avd, vbd.
            splittetedge(newpoint, &starttet, flipqueue);
            // Adjust splitsub be avc, neisplitsub be avd.
            findedge(&splitsub, pa, newpoint);
            findedge(&neisplitsub, pa, newpoint);
            // Check the four new subfaces to see if they're encroached.
            //   splitsub may be infected (it exists before the split).
            checksh = splitsub;
            if (!shell2badface(checksh)) {
              checksub4badqual(&checksh, true); // avc
            }
            if (!shell2badface(checksh)) {
              checksub4encroach(&checksh, NULL, true); // avc
            }
            //   Get vbc.
            senext(splitsub, checksh);
            spivotself(checksh);
            //   vbc is newly created.
            assert(checksh.sh != dummysh && !shell2badface(checksh));
            checksub4badqual(&checksh, true); // vbc
            if (!shell2badface(checksh)) {
              checksub4encroach(&checksh, NULL, true); // vbc
            }
            //   neisplitsub may be infected (it exists before the split).
            checksh = neisplitsub;
            if (!shell2badface(checksh)) {
              checksub4badqual(&checksh, true); // avd
            }
            if (!shell2badface(checksh)) {
              checksub4encroach(&checksh, NULL, true); // avd
            }
            //   Get vbd.
            senext(neisplitsub, checksh);
            spivotself(checksh);
            //   vbd is newly created.
            assert(checksh.sh != dummysh && !shell2badface(checksh));
            checksub4badqual(&checksh, true); // vbd
            if (!shell2badface(checksh)) {
              checksub4encroach(&checksh, NULL, true); // vbd
            }
          } else {
            /* It's a BUG.
            printf("Internal error in splitencsub():  Point %d locates %s.\n",
              pointmark(newpoint), loc == ONVERTEX ? "on vertex" : "outside");
            internalerror();
            */
            // Delete the newpoint.
            pointdealloc(newpoint);
          }
          if ((loc == ONFACE) || (loc == ONEDGE)) {
            if (steinerleft > 0) steinerleft--;
            // Recover Delaunay property by flipping. Subfaces which are
            //   encroached by the new point will be discovered.
            flip(flipqueue, NULL, false, true, chkbadqual);
            // There should be no encroached segments.
            // assert(badsubsegs->items == 0);
            // Queuing bad-quality tetrahedra if need.
            if (chkbadqual) {
              doqualchecktetlist();
            }
          }
        } else {
          // newpoint encroaches upon some segments. Rejected.
          // Delete the newpoint.
          pointdealloc(newpoint);
        }
        // Repair all the encroached segments.
        if (badsubsegs->items > 0) {
          repairencsegs(flipqueue);
        }
      }
    } else {
      // enq = false!  This subface has been changed, check it again.
      checksub4badqual(&splitsub, true);
      if (!shell2badface(splitsub)) {
        checksub4encroach(&splitsub, NULL, true);
      }
    }
    // Remove this entry from list.
    badfacedealloc(badsubfaces, encloop);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// repairbadtets()    Repair all bad-quality tetrahedra.                     //
//                                                                           //
// At beginning, all bad-quality tetrahedra are stored in 'badtetrahedrons'. //
// Each bad tetrahedron is repaired by inserting a point at or near its cir- //
// cumcenter.  However, if this point encroaches any subsegment or subface,  //
// it is not inserted. Instead the encroached segment and subface are split. //
// Newly inserted points may create other bad-quality tetrahedra, these are  //
// also repaired.                                                            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::repairbadtets(list* cavtetlist, queue* flipqueue)
{
  badface *badtet;
  triface starttet;
  point newpoint;
  enum insertsiteresult success;
  enum locateresult loc;
  bool reject;
  int i;

  // Loop until pool 'badtetrahedrons' is empty. Note that steinerleft == -1
  //   if an unlimited number of Steiner points is allowed.
  while ((badtetrahedrons->items > 0) && (steinerleft != 0)) {
    badtet = dequeuebadtet();
    assert (badtet != (badface *) NULL);
    // Make sure that 'badtet->tet' is still the same one when it was tested.
    //   Subsequent transformations may have made it a different tet.
    if (!isdead(&badtet->tt) && org(badtet->tt) == badtet->forg &&
        dest(badtet->tt) == badtet->fdest && 
        apex(badtet->tt) == badtet->fapex &&
        oppo(badtet->tt) == badtet->foppo) {
      // Create a newpoint at the circumcenter of this tetrahedron.
      makepoint(&newpoint);
      for (i = 0; i < 3; i++) newpoint[i] = badtet->cent[i];
      // Set it's type be FREEVOLVERTEX.
      setpointtype(newpoint, FREEVOLVERTEX);
  
      // Locate newpoint in mesh.
      starttet = badtet->tt;  // Used for the input of preciselocate().
      loc = preciselocate(newpoint, &starttet);
      // Look if the newpoint encroaches upon any segment or subface.
      cavtetlist->append(&starttet);
      collectcavtets(newpoint, cavtetlist);
      assert(cavtetlist->len() > 0);
      reject = tallencsubs(newpoint, cavtetlist);
      // Clear the list for the next use.
      cavtetlist->clear();

      if (!reject && (loc != OUTSIDE)) {
        // Insert the point, it should be always success.
        starttet = badtet->tt;
        success = insertsite(newpoint, &starttet, true, flipqueue);
        if (success != DUPLICATEPOINT) {
          if (steinerleft > 0) steinerleft--;
          // Recover Delaunay property by flipping.
          flip(flipqueue, NULL, false, false, true);
          // Queuing bad-quality tetrahedra if need.
          doqualchecktetlist();
        } else {
          // !!! It's a bug!!!
          pointdealloc(newpoint);
        }
      } else {
        // newpoint encroaches upon some subfaces. Rejected.
        pointdealloc(newpoint);
        if (badsubfaces->items > 0) {
          // Repair all the encroached subfaces.
          repairencsubs(cavtetlist, flipqueue);
        }
      }
    }
    // Remove the bad-quality tetrahedron from the pool.
    badfacedealloc(badtetrahedrons, badtet);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// repairslivers()    Remove slivers from the mesh.                          //
//                                                                           //
// Slivers are found and stored in 'badtetrahedrons'. Each sliver is removed //
// by either local transformation operator or inserting a point at or near   //
// its circumcenter.                                                         //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::repairslivers(list* cavtetlist, queue* flipqueue)
{
  badface *badtet;
  triface starttet;
  point newpoint;
  enum insertsiteresult success;
  enum locateresult loc;
  bool reject;
  int total, counter;

  total = 0;
  while (badtetrahedrons->items > 0l) {
    counter = 0;
    // Loop in pool 'badtetrahedrons'.
    badtetrahedrons->traversalinit();
    badtet = badfacetraverse(badtetrahedrons);
    while (badtet != (badface *) NULL) {
      if (!isdead(&badtet->tt) && (org(badtet->tt) == badtet->forg) &&
          (dest(badtet->tt) == badtet->fdest) &&
          (apex(badtet->tt) == badtet->fapex) &&
          (oppo(badtet->tt) == badtet->foppo)) {
        if (finddiagonal(&(badtet->tt))) {
          if (removekite(&(badtet->tt), NULL)) {
            // Remove the sliver from the pool.
            badfacedealloc(badtetrahedrons, badtet);
            counter++; 
          }
        }
      }
      badtet = badfacetraverse(badtetrahedrons);
    }
    // Are there any sliver be removed?
    if (counter == 0) break;
    // Accumulate the number of removed slivers.
    total += counter;
    if (badtetrahedrons->items > 0l) {
      // Some slivers may remain in the mesh.
      badtetrahedrons->restart();
      tallslivers();
    }
  }

  if (badtetrahedrons->items > 0l) {
    // Some slivers survived. Try to split them.
    counter = 0;
    badtetrahedrons->traversalinit();
    badtet = badfacetraverse(badtetrahedrons);
    while (badtet != (badface *) NULL) {
      if (!isdead(&badtet->tt) && (org(badtet->tt) == badtet->forg) &&
          (dest(badtet->tt) == badtet->fdest) &&
          (apex(badtet->tt) == badtet->fapex) &&
          (oppo(badtet->tt) == badtet->foppo)) {
        // Create a newpoint at the circumcenter of this sliver.
        makepoint(&newpoint);
        circumsphere(badtet->forg, badtet->fdest, badtet->fapex, badtet->foppo,
                     newpoint, NULL);
        // Set it's type be FREEVOLVERTEX.
        setpointtype(newpoint, FREEVOLVERTEX);
        // Locate newpoint in mesh.
        starttet = badtet->tt;  // Used for the input of preciselocate().
        loc = preciselocate(newpoint, &starttet);
        // Look if the newpoint encroaches upon any segment or subface.
        cavtetlist->append(&starttet);
        collectcavtets(newpoint, cavtetlist);
        assert(cavtetlist->len() > 0);
        reject = tallencsubs(newpoint, cavtetlist);
        // Clear the list for the next use.
        cavtetlist->clear();
        if (!reject && (loc != OUTSIDE)) {
          // Insert the point, it should be always success.
          starttet = badtet->tt;
          success = insertsite(newpoint, &starttet, true, flipqueue);
          if (success != DUPLICATEPOINT) {
            if (steinerleft > 0) steinerleft--;
            // Recover Delaunay property by flipping.
            flip(flipqueue, NULL, false, false, false);
            // Remove the sliver from the pool.
            badfacedealloc(badtetrahedrons, badtet);
            counter++; 
          } else {
            // !!! It's a bug!!!
            pointdealloc(newpoint);
          }
        } else {
          // Rejected. Do not insert the point.
          pointdealloc(newpoint);
          // Clean the pool.
          badsubfaces->restart();
        }
      } else {
        // Sliver has been changed.
        badfacedealloc(badtetrahedrons, badtet);
        counter++;
      }
      badtet = badfacetraverse(badtetrahedrons);
    }
    // Accumulate the number of removed slivers.
    total += counter;
  }

  if (b->verbose) {
    printf("  %d slivers are removed.\n", total);
    if (badtetrahedrons->items > 0l) {
      printf("  %ld sliver(s) survived.\n", badtetrahedrons->items);
    }
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// enforcequality()    Remove all the encroached subsegments, subfaces  and  //
//                     bad tetrahedra from the tetrahedral mesh.             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::enforcequality()
{
  queue *flipqueue;
  list *cavtetlist;
  long total, vertcount;
  int i;
  
  if (!b->quiet) {
    printf("Adding Steiner points to enforce quality.\n");
  } 

  total = 0l;
  // Initialize working queues, lists.
  flipqueue = new queue(sizeof(badface));
  rpsarray = new REAL[points->items + 1];
  cavtetlist = new list(sizeof(triface), NULL, 256);

  if (b->refine) {
    // Mark segment vertices (acute or not).
    markacutevertices(89.0);
  }
  // Mark sharp subfaces (for termination).
  marksharpsubfaces(89.0);
  // Mark skinny subfaces (for reducing Steiner points).
  markskinnysubfaces(19.0);
  // Calculate the protecting spheres for all acute points.
  initializerpsarray();

  // Initialize the pool of encroached subsegments.
  badsubsegs = new memorypool(sizeof(badface), SUBPERBLOCK, POINTER, 0);
  if (varconstraint && in->segmentconstraintlist) {
    // Test all segments to see if they're bad-quality.
    tallbadsegs();
  }
  // Test all segments to see if they're encroached.
  tallencsegs(NULL, NULL);
  if (b->verbose && badsubsegs->items > 0) {
    printf("  Splitting encroached subsegments.\n");
  }
  vertcount = points->items;
  // Fix encroached segments without noting any enc subfaces.
  repairencsegs(flipqueue);
  if (b->verbose) {
    printf("  %ld points are inserted.\n", points->items - vertcount);
  }
  total += points->items - vertcount;

  // Initialize the pool of encroached subfaces.
  badsubfaces = new memorypool(sizeof(badface), SUBPERBLOCK, POINTER, 0);
  // Initialize the queues of badfaces.
  for (i = 0; i < 2; i++) subquefront[i] = (badface *) NULL;
  for (i = 0; i < 2; i++) subquetail[i] = &subquefront[i];
  // Test all subfaces to see if they're bad-quality.
  tallbadsubs();
  // Test the rest of subfaces to see if they're encroached.
  tallencsubs(NULL, NULL);
  if (b->verbose && badsubfaces->items > 0) {
    printf("  Splitting encroached subfaces.\n");
  }
  vertcount = points->items;
  // Fix encroached subfaces without noting bad tetrahedra.
  repairencsubs(cavtetlist, flipqueue);
  // At this point, the mesh should be (conforming) Delaunay.
  if (b->verbose) {
    printf("  %ld points are inserted.\n", points->items - vertcount);
  }
  total += points->items - vertcount;

  // Next, fix bad quality tetrahedra.
  if ((b->minratio > 0.0) || b->varvolume || b->fixedvolume) {
    // Initialize the pool of bad tetrahedra.
    badtetrahedrons = new memorypool(sizeof(badface), ELEPERBLOCK, POINTER, 0);
    // Initialize the list of bad tetrahedra.
    qualchecktetlist = new list(sizeof(triface), NULL);
    // Initialize the queues of bad tetrahedra.
    for (i = 0; i < 64; i++) tetquefront[i] = (badface *) NULL;
    for (i = 0; i < 64; i++) tetquetail[i] = &tetquefront[i];
    // Test all tetrahedra to see if they're bad.
    tallbadtetrahedrons();
    if (b->verbose && badtetrahedrons->items > 0) {
      printf("  Splitting bad tetrahedra.\n");
    }
    vertcount = points->items;
    repairbadtets(cavtetlist, flipqueue);
    // At this point, it should no bad quality tetrahedra.
    if (b->verbose) {
      printf("  %ld points are inserted.\n", points->items - vertcount);
    }
    total += points->items - vertcount;
    assert(badtetrahedrons->items == 0l);
    // Next, remove slivers from the mesh.
    tallslivers();
    if (b->verbose && badtetrahedrons->items > 0) {
      printf("  Removing slivers.\n");
    }
    vertcount = points->items;
    repairslivers(cavtetlist, flipqueue);
    if (b->verbose) {
      printf("  %ld points are inserted.\n", points->items - vertcount);
    }
    total += points->items - vertcount;
    delete qualchecktetlist;
    delete badtetrahedrons;
  }

  if (b->verbose) {
    printf("  Total %ld points are inserted.\n", total);
  }

  delete cavtetlist;
  delete flipqueue;
  delete badsubfaces;
  delete badsubsegs;
  delete [] rpsarray;
}

//
// End of Delaunay refinement routines
//

//
// Begin of I/O rouitnes
//

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// transfernodes()    Transfer nodes from 'io->pointlist' to 'this->points'. //
//                                                                           //
// Initializing 'this->points'.  Transferring all points from 'in->pointlist'//
// into it. All points are indexed (start from in->firstnumber).  Each point //
// is initialized be UNUSEDVERTEX.  The bounding box (xmin, xmax, ymin, ymax,//
// zmin, zmax) and the diameter (longest) of the point set are calculated.   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::transfernodes()
{
  point pointloop;
  REAL x, y, z;
  int coordindex;
  int attribindex;
  int i, j;

  // Read the points.
  coordindex = 0;
  attribindex = 0;
  for (i = 0; i < in->numberofpoints; i++) {
    makepoint(&pointloop);
    // Read the point coordinates.
    x = pointloop[0] = in->pointlist[coordindex++];
    y = pointloop[1] = in->pointlist[coordindex++];
    z = pointloop[2] = in->pointlist[coordindex++];
    // Read the point attributes.
    for (j = 0; j < in->numberofpointattributes; j++) {
      pointloop[3 + j] = in->pointattributelist[attribindex++];
    }
    // Determine the smallest and largests x, y and z coordinates.
    if (i == 0) {
      xmin = xmax = x;
      ymin = ymax = y;
      zmin = zmax = z;
    } else {
      xmin = (x < xmin) ? x : xmin;
      xmax = (x > xmax) ? x : xmax;
      ymin = (y < ymin) ? y : ymin;
      ymax = (y > ymax) ? y : ymax;
      zmin = (z < zmin) ? z : zmin;
      zmax = (z > zmax) ? z : zmax;
    }
  }
  // 'longest' is the largest possible edge length formed by input vertices.
  //   It is used as the measure to distinguish two identical points.
  x = xmax - xmin;
  y = ymax - ymin;
  z = zmax - zmin;
  longest = sqrt(x * x + y * y + z * z);
  if (longest == 0.0) {
    printf("Error:  The point set is trivial.\n");
    exit(1);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// jettisonnodes()    Jettison unused or duplicated vertices.                //
//                                                                           //
// Unused points are those input points which are outside the mesh domain or //
// have no connection (isolated) to the mesh.  Duplicated points exist for   //
// example if the input PLC is read from a .stl mesh file (marked during the //
// Delaunay tetrahedralization step. This routine remove these points from   //
// points list. All existing points are reindexed.                           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::jettisonnodes()
{
  point pointloop;
  bool jetflag;
  int idx;

  if (!b->quiet) {
    printf("Jettisoning redundants points.\n");
  }

  points->traversalinit();
  pointloop = pointtraverse();
  idx = in->firstnumber;
  while (pointloop != (point) NULL) {
    jetflag = (pointtype(pointloop) == DUPLICATEDVERTEX) || 
      (pointtype(pointloop) == UNUSEDVERTEX);
    if (jetflag) {
      // It is a duplicated point, delete it.
      pointdealloc(pointloop);
    } else {
      // Index it.
      setpointmark(pointloop, idx);
      idx++;
    }
    pointloop = pointtraverse();
  }
  dupverts = 0;
  unuverts = 0;

  // The following line ensures that dead items in the pool of nodes cannot
  //   be allocated for the new created nodes. This ensures that the input
  //   nodes will occur earlier in the output files, and have lower indices.
  points->deaditemstack = (void *) NULL;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// highorder()   Create extra nodes for quadratic subparametric elements.    //
//                                                                           //
// 'highordertable' is an array (size = numberoftetrahedra * 6) for storing  //
// high-order nodes of each tetrahedron.  This routine is used only when -o2 //
// switch is used.                                                           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::highorder()
{
  triface tetloop, worktet;
  triface spintet, adjtet;
  point torg, tdest, tapex;
  point *extralist, *adjextralist;
  point newpoint;
  int hitbdry, ptmark;
  int i, j;

  // The 'edgeindex' (from 0 to 5) is list as follows:
  //   0 - (v0, v1), 1 - (v1, v2), 2 - (v2, v0)
  //   3 - (v3, v0), 4 - (v3, v1), 5 - (v3, v2)
  // Define an edgeindex map: (loc, ver)->edgeindex.
  int edgeindexmap[4][6] = {0, 0, 1, 1, 2, 2,
                            3, 3, 4, 4, 0, 0,
                            4, 4, 5, 5, 1, 1,
                            5, 5, 3, 3, 2, 2};

  if (!b->quiet) {
    printf("Adding vertices for second-order tetrahedra.\n");
  }

  // Initialize the 'highordertable'.
  highordertable = new point[tetrahedrons->items * 6];
  if (highordertable == (point *) NULL) {
    printf("Error:  Out of memory.\n");
    exit(1);
  }

  // The following line ensures that dead items in the pool of nodes cannot
  //   be allocated for the extra nodes associated with high order elements.
  //   This ensures that the primary nodes (at the corners of elements) will
  //   occur earlier in the output files, and have lower indices, than the
  //   extra nodes.
  points->deaditemstack = (void *) NULL;

  // Assign an entry for each tetrahedron to find its extra nodes. At the
  //   mean while, initialize all extra nodes be NULL.
  i = 0;
  tetrahedrons->traversalinit();
  tetloop.tet = tetrahedrontraverse();
  while (tetloop.tet != (tetrahedron *) NULL) {
    tetloop.tet[highorderindex] = (tetrahedron) &highordertable[i];
    for (j = 0; j < 6; j++) {
      highordertable[i + j] = (point) NULL;
    }
    i += 6;
    tetloop.tet = tetrahedrontraverse();
  }

  // To create a unique node on each edge. Loop over all tetrahedra, and
  //   look at the six edges of each tetrahedron.  If the extra node in
  //   the tetrahedron corresponding to this edge is NULL, create a node
  //   for this edge, at the same time, set the new node into the extra
  //   node lists of all other tetrahedra sharing this edge.  
  tetrahedrons->traversalinit();
  tetloop.tet = tetrahedrontraverse();
  while (tetloop.tet != (tetrahedron *) NULL) {
    // Get the list of extra nodes.
    extralist = (point *) tetloop.tet[highorderindex];
    for (i = 0; i < 6; i++) {
      if (extralist[i] == (point) NULL) {
        // Operate on this edge.
        worktet = tetloop;
        worktet.loc = 0; worktet.ver = 0;
        // Get the correct edge in 'worktet'.
        switch(i) {
        case 0: // (v0, v1) 
          break;
        case 1: // (v1, v2)
          enextself(worktet);
          break;
        case 2: // (v2, v0)
          enext2self(worktet);
          break;
        case 3: // (v3, v0)
          fnextself(worktet);
          enext2self(worktet);
          break;
        case 4: // (v3, v1)
          enextself(worktet);
          fnextself(worktet);
          enext2self(worktet);
          break;
        case 5: // (v3, v2)
          enext2self(worktet);
          fnextself(worktet);
          enext2self(worktet);
        }
        // Create a new node on this edge.
        torg = org(worktet);
        tdest = dest(worktet);
        // Create a new node in the middle of the edge.
        newpoint = (point) points->alloc();
        // Interpolate its attributes.
        for (j = 0; j < 3 + in->numberofpointattributes; j++) {
          newpoint[j] = 0.5 * (torg[j] + tdest[j]);
        }
        ptmark = (int) points->items - (in->firstnumber == 1 ? 0 : 1);
        setpointmark(newpoint, ptmark);
        // Add this node to its extra node list.
        extralist[i] = newpoint;
        // Set 'newpoint' into extra node lists of other tetrahedra
        //   sharing this edge.
        tapex = apex(worktet);
        spintet = worktet;
        hitbdry = 0;
        while (hitbdry < 2) {
          if (fnextself(spintet)) {
            // Get the extra node list of 'spintet'.
            adjextralist = (point *) spintet.tet[highorderindex];
            // Find the index of its extra node list.
            j = edgeindexmap[spintet.loc][spintet.ver];
            // Only set 'newpoint' into 'adjextralist' if it is a NULL.
            //   Because two faces can belong to the same tetrahedron.
            if (adjextralist[j] == (point) NULL) {
              adjextralist[j] = newpoint;
            }
            if (apex(spintet) == tapex) {
              break;
            }
          } else {
            hitbdry++;
            if (hitbdry < 2) {
              esym(worktet, spintet);
	    }
          }
        }
      }
    }
    tetloop.tet = tetrahedrontraverse();
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// outnodes()    Output the points to a .node file or a tetgenio structure.  //
//                                                                           //
// Note: each point has already been numbered on input (the first index is   //
// 'in->firstnumber').                                                       //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::outnodes(tetgenio* out)
{
  FILE *outfile;
  char outnodefilename[FILENAMESIZE];
  point pointloop;
  int nextras, bmark, marker;
  int coordindex, attribindex;
  int pointnumber, index, i;

  if (out == (tetgenio *) NULL) {
    strcpy(outnodefilename, b->outfilename);
    strcat(outnodefilename, ".node");
  } 
  
  if (!b->quiet) {
    if (out == (tetgenio *) NULL) {
      printf("Writing %s.\n", outnodefilename);
    } else {
      printf("Writing nodes.\n");
    }
  }

  nextras = in->numberofpointattributes;
  bmark = !b->nobound && in->pointmarkerlist;

  if (out == (tetgenio *) NULL) {
    outfile = fopen(outnodefilename, "w");
    if (outfile == (FILE *) NULL) {
      printf("File I/O Error:  Cannot create file %s.\n", outnodefilename);
      exit(1);
    }
    // Number of points, number of dimensions, number of point attributes,
    //   and number of boundary markers (zero or one).
    fprintf(outfile, "%ld  %d  %d  %d\n", points->items, 3, nextras, bmark);
  } else {
    // Allocate space for 'pointlist';
    out->pointlist = new REAL[points->items * 3];
    if (out->pointlist == (REAL *) NULL) {
      printf("Error:  Out of memory.\n");
      exit(1);
    }
    // Allocate space for 'pointattributelist' if necessary;
    if (nextras > 0) {
      out->pointattributelist = new REAL[points->items * nextras];
      if (out->pointattributelist == (REAL *) NULL) {
        printf("Error:  Out of memory.\n");
        exit(1);
      }
    }
    // Allocate space for 'pointmarkerlist' if necessary;
    if (bmark) {
      out->pointmarkerlist = new int[points->items];
      if (out->pointmarkerlist == (int *) NULL) {
        printf("Error:  Out of memory.\n");
        exit(1);
      }
    }
    out->numberofpoints = points->items;
    out->numberofpointattributes = nextras;
    coordindex = 0;
    attribindex = 0;
  }

  points->traversalinit();
  pointloop = pointtraverse();
  pointnumber = in->firstnumber;
  index = 0;
  while (pointloop != (point) NULL) {
    if (bmark) {
      // Determine the boundary marker.
      if (index < in->numberofpoints) {
        // Input point's marker is directly copied to output.
        marker = in->pointmarkerlist[index];
        if (marker == 0) {
          // Change the marker if it is a boundary point.
          marker = (pointtype(pointloop) != FREEVOLVERTEX) ? 1 : 0;
        }
      } else if (pointtype(pointloop) != FREEVOLVERTEX) {
        // A boundary vertex has marker 1.
        marker = 1;
      } else {
        // Free or internal point has a zero marker.
        marker = 0;
      }
    }
    if (out == (tetgenio *) NULL) {
      // Point number, x, y and z coordinates.
      fprintf(outfile, "%4d    %.17g  %.17g  %.17g", pointnumber,
              pointloop[0], pointloop[1], pointloop[2]);
      for (i = 0; i < nextras; i++) {
        // Write an attribute.
        fprintf(outfile, "  %.17g", pointloop[3 + i]);
      }
      if (bmark) {
        // Write the boundary marker.
        fprintf(outfile, "    %d", marker);
      }
      fprintf(outfile, "\n");
    } else {
      // X, y, and z coordinates.
      out->pointlist[coordindex++] = pointloop[0];
      out->pointlist[coordindex++] = pointloop[1];
      out->pointlist[coordindex++] = pointloop[2];
      // Point attributes.
      for (i = 0; i < nextras; i++) {
        // Output an attribute.
        out->pointattributelist[attribindex++] = pointloop[3 + i];
      }
      if (bmark) {
        // Output the boundary marker.  
        out->pointmarkerlist[index] = marker;
      }
    }
    pointloop = pointtraverse();
    pointnumber++; 
    index++;
  }

  if (out == (tetgenio *) NULL) {
    fprintf(outfile, "# Generated by %s\n", b->commandline);
    fclose(outfile);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// outelements()    Output the tetrahedra to an .ele file or a tetgenio      //
//                  structure.                                               //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::outelements(tetgenio* out)
{
  FILE *outfile;
  char outelefilename[FILENAMESIZE];
  tetrahedron* tptr;
  int *tlist;
  REAL *talist;
  int pointindex;
  int attribindex;
  point p1, p2, p3, p4;
  point *extralist;
  int elementnumber;
  int eextras;
  int i;

  if (out == (tetgenio *) NULL) {
    strcpy(outelefilename, b->outfilename);
    strcat(outelefilename, ".ele");
  }

  if (!b->quiet) {
    if (out == (tetgenio *) NULL) {
      printf("Writing %s.\n", outelefilename);
    } else {
      printf("Writing elements.\n");
    }
  }

  eextras = in->numberoftetrahedronattributes;
  if (out == (tetgenio *) NULL) {
    outfile = fopen(outelefilename, "w");
    if (outfile == (FILE *) NULL) {
      printf("File I/O Error:  Cannot create file %s.\n", outelefilename);
      exit(1);
    }
    // Number of tetras, points per tetra, attributes per tetra.
    fprintf(outfile, "%ld  %d  %d\n", tetrahedrons->items,
            b->order == 1 ? 4 : 10, eextras);
  } else {
    // Allocate memory for output tetrahedra.
    out->tetrahedronlist = new int[tetrahedrons->items * 
                                   (b->order == 1 ? 4 : 10)];
    if (out->tetrahedronlist == (int *) NULL) {
      printf("Error:  Out of memory.\n");
      exit(1);
    }
    // Allocate memory for output tetrahedron attributes if necessary.
    if (eextras > 0) {
      out->tetrahedronattributelist = new REAL[tetrahedrons->items * eextras];
      if (out->tetrahedronattributelist == (REAL *) NULL) {
        printf("Error:  Out of memory.\n");
        exit(1);
      }
    }
    out->numberoftetrahedra = tetrahedrons->items;
    out->numberofcorners = b->order == 1 ? 4 : 10;
    out->numberoftetrahedronattributes = eextras;
    tlist = out->tetrahedronlist;
    talist = out->tetrahedronattributelist;
    pointindex = 0;
    attribindex = 0;
  }

  tetrahedrons->traversalinit();
  tptr = tetrahedrontraverse();
  elementnumber = in->firstnumber;
  while (tptr != (tetrahedron *) NULL) {
    p1 = (point) tptr[4];
    p2 = (point) tptr[5];
    p3 = (point) tptr[6];
    p4 = (point) tptr[7];
    if (out == (tetgenio *) NULL) {
      // Tetrahedron number, indices for four points.
      fprintf(outfile, "%5d   %5d %5d %5d %5d", elementnumber,
              pointmark(p1), pointmark(p2), pointmark(p3), pointmark(p4));
      if (b->order == 2) {
        extralist = (point *) tptr[highorderindex];
        // Tetrahedron number, indices for four points plus six extra points.
        fprintf(outfile, "  %5d %5d %5d %5d %5d %5d",
                pointmark(extralist[0]), pointmark(extralist[1]),
                pointmark(extralist[2]), pointmark(extralist[3]),
                pointmark(extralist[4]), pointmark(extralist[5]));
      }
      for (i = 0; i < eextras; i++) {
        fprintf(outfile, "    %.17g", elemattribute(tptr, i));
      }
      fprintf(outfile, "\n");
    } else {
      tlist[pointindex++] = pointmark(p1);
      tlist[pointindex++] = pointmark(p2);
      tlist[pointindex++] = pointmark(p3);
      tlist[pointindex++] = pointmark(p4);
      if (b->order == 2) {
        extralist = (point *) tptr[highorderindex];
        tlist[pointindex++] = pointmark(extralist[0]);
        tlist[pointindex++] = pointmark(extralist[1]);
        tlist[pointindex++] = pointmark(extralist[2]);
        tlist[pointindex++] = pointmark(extralist[3]);
        tlist[pointindex++] = pointmark(extralist[4]);
        tlist[pointindex++] = pointmark(extralist[5]);
      }
      for (i = 0; i < eextras; i++) {
        talist[attribindex++] = elemattribute(tptr, i);
      }
    }
    tptr = tetrahedrontraverse();
    elementnumber++;
  }

  if (out == (tetgenio *) NULL) {
    fprintf(outfile, "# Generated by %s\n", b->commandline);
    fclose(outfile);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// outfaces()    Output all faces to a .face file or a tetgenio structure.   //
//                                                                           //
// This routines outputs all triangular faces (including outer boundary      //
// faces and inner faces) of this mesh.                                      //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::outfaces(tetgenio* out)
{
  FILE *outfile;
  char facefilename[FILENAMESIZE];
  int *elist;
  int *emlist;
  int index;
  triface tface, tsymface;
  face checkmark;
  point torg, tdest, tapex;
  long faces;
  int bmark, faceid, marker;
  int facenumber;

  if (out == (tetgenio *) NULL) {
    strcpy(facefilename, b->outfilename);
    strcat(facefilename, ".face");
  }

  if (!b->quiet) {
    if (out == (tetgenio *) NULL) {
      printf("Writing %s.\n", facefilename);
    } else {
      printf("Writing faces.\n");
    }
  }

  faces = (4l * tetrahedrons->items + hullsize) / 2l;
  bmark = !b->nobound && in->facetmarkerlist;

  if (out == (tetgenio *) NULL) {
    outfile = fopen(facefilename, "w");
    if (outfile == (FILE *) NULL) {
      printf("File I/O Error:  Cannot create file %s.\n", facefilename);
      exit(1);
    }
    fprintf(outfile, "%ld  %d\n", faces, bmark);
  } else {
    // Allocate memory for 'trifacelist'.
    out->trifacelist = new int[faces * 3];
    if (out->trifacelist == (int *) NULL) {
      printf("Error:  Out of memory.\n");
      exit(1);
    }
    // Allocate memory for 'trifacemarkerlist' if necessary.
    if (bmark) {
      out->trifacemarkerlist = new int[faces];
      if (out->trifacemarkerlist == (int *) NULL) {
        printf("Error:  Out of memory.\n");
        exit(1);
      }
    }
    out->numberoftrifaces = faces;
    elist = out->trifacelist;
    emlist = out->trifacemarkerlist;
    index = 0;
  }

  tetrahedrons->traversalinit();
  tface.tet = tetrahedrontraverse();
  facenumber = in->firstnumber;
  // To loop over the set of faces, loop over all tetrahedra, and look at
  //   the four faces of each one. If there isn't another tetrahedron
  //   adjacent to this face, operate on the face.  If there is another
  //   adjacent tetrahedron, operate on the face only if the current
  //   tetrahedron has a smaller pointer than its neighbor.  This way, each
  //   face is considered only once.
  while (tface.tet != (tetrahedron *) NULL) {
    for (tface.loc = 0; tface.loc < 4; tface.loc ++) {
      sym(tface, tsymface);
      if ((tsymface.tet == dummytet) || (tface.tet < tsymface.tet)) {
        torg = org(tface);
        tdest = dest(tface);
        tapex = apex(tface);
        if (bmark) {
          // Get the boundary marker of this face. If it is an inner face,
          //   it has no boundary marker, set it be zero.
          if (b->useshelles) {
            // Shell face is used.
            tspivot(tface, checkmark);
            if (checkmark.sh == dummysh) {
              marker = 0;  // It is an inner face.
            } else {
              faceid = shellmark(checkmark) - 1;
              marker = in->facetmarkerlist[faceid];
            }
          } else {
            // Shell face is not used, only distinguish outer and inner face.
            marker = tsymface.tet != dummytet ? 1 : 0;
          }
        }
        if (out == (tetgenio *) NULL) {
          // Face number, indices of three vertices.
          fprintf(outfile, "%5d   %4d  %4d  %4d", facenumber,
                  pointmark(torg), pointmark(tdest), pointmark(tapex));
          if (bmark) {
            // Output a boundary marker.
            fprintf(outfile, "  %d", marker);
          }
          fprintf(outfile, "\n");
        } else {
          // Output indices of three vertices.
          elist[index++] = pointmark(torg);
          elist[index++] = pointmark(tdest);
          elist[index++] = pointmark(tapex);
          if (bmark) {
            emlist[facenumber - in->firstnumber] = marker;
          }
        }
        facenumber++;
      }
    }
    tface.tet = tetrahedrontraverse();
  }

  if (out == (tetgenio *) NULL) {
    fprintf(outfile, "# Generated by %s\n", b->commandline);
    fclose(outfile);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// outhullfaces()    Output outer boundary faces to a .face file or a        //
//                   tetgenio structure.                                     //
//                                                                           //
// The normal of each face is arranged to point inside of the domain (use    //
// right-hand rule).  This routines will outputs convex hull faces if the    //
// mesh is a Delaunay tetrahedralization.                                    //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::outhullfaces(tetgenio* out)
{
  FILE *outfile;
  char facefilename[FILENAMESIZE];
  int *elist;
  int index;
  triface tface, tsymface;
  face checkmark;
  point torg, tdest, tapex;
  int facenumber;

  if (out == (tetgenio *) NULL) {
    strcpy(facefilename, b->outfilename);
    strcat(facefilename, ".face");
  }

  if (!b->quiet) {
    if (out == (tetgenio *) NULL) {
      printf("Writing %s.\n", facefilename);
    } else {
      printf("Writing faces.\n");
    }
  }

  if (out == (tetgenio *) NULL) {
    outfile = fopen(facefilename, "w");
    if (outfile == (FILE *) NULL) {
      printf("File I/O Error:  Cannot create file %s.\n", facefilename);
      exit(1);
    }
    fprintf(outfile, "%ld  0\n", hullsize);
  } else {
    // Allocate memory for 'trifacelist'.
    out->trifacelist = new int[hullsize * 3];
    if (out->trifacelist == (int *) NULL) {
      printf("Error:  Out of memory.\n");
      exit(1);
    }
    out->numberoftrifaces = hullsize;
    elist = out->trifacelist;
    index = 0;
  }

  tetrahedrons->traversalinit();
  tface.tet = tetrahedrontraverse();
  facenumber = in->firstnumber;
  // To loop over the set of hull faces, loop over all tetrahedra, and look
  //   at the four faces of each one. If there isn't another tetrahedron
  //   adjacent to this face, operate on the face.
  while (tface.tet != (tetrahedron *) NULL) {
    for (tface.loc = 0; tface.loc < 4; tface.loc ++) {
      sym(tface, tsymface);
      if (tsymface.tet == dummytet) {
        torg = org(tface);
        tdest = dest(tface);
        tapex = apex(tface);
        if (out == (tetgenio *) NULL) {
          // Face number, indices of three vertices.
          fprintf(outfile, "%5d   %4d  %4d  %4d", facenumber,
                  pointmark(torg), pointmark(tdest), pointmark(tapex));
          fprintf(outfile, "\n");
        } else {
          // Output indices of three vertices.
          elist[index++] = pointmark(torg);
          elist[index++] = pointmark(tdest);
          elist[index++] = pointmark(tapex);
        }
        facenumber++;
      }
    }
    tface.tet = tetrahedrontraverse();
  }

  if (out == (tetgenio *) NULL) {
    fprintf(outfile, "# Generated by %s\n", b->commandline);
    fclose(outfile);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// outsubfaces()    Output subfaces (i.e. boundary faces) to a .face file or //
//                  a tetgenio structure.                                    //
//                                                                           //
// The boundary faces are exist in 'subfaces'. For listing triangle vertices //
// in the same sense for all triangles in the mesh, the direction determined //
// by right-hand rule is pointer to the inside of the volume.                //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::outsubfaces(tetgenio* out)
{
  FILE *outfile;
  char facefilename[FILENAMESIZE];
  int *elist;
  int *emlist;
  int index;
  triface abuttingtet;
  face faceloop;
  point torg, tdest, tapex;
  int bmark, faceid, marker;
  int facenumber;

  if (out == (tetgenio *) NULL) {
    strcpy(facefilename, b->outfilename);
    strcat(facefilename, ".face");
  }

  if (!b->quiet) {
    if (out == (tetgenio *) NULL) {
      printf("Writing %s.\n", facefilename);
    } else {
      printf("Writing faces.\n");
    }
  }

  bmark = !b->nobound && in->facetmarkerlist;

  if (out == (tetgenio *) NULL) {
    outfile = fopen(facefilename, "w");
    if (outfile == (FILE *) NULL) {
      printf("File I/O Error:  Cannot create file %s.\n", facefilename);
      exit(1);
    }
    // Number of subfaces.
    fprintf(outfile, "%ld  %d\n", subfaces->items, bmark);
  } else {
    // Allocate memory for 'trifacelist'.
    out->trifacelist = new int[subfaces->items * 3];
    if (out->trifacelist == (int *) NULL) {
      printf("Error:  Out of memory.\n");
      exit(1);
    }
    // Allocate memory for 'trifacemarkerlist', if necessary.
    if (bmark) {
      out->trifacemarkerlist = new int[subfaces->items];
      if (out->trifacemarkerlist == (int *) NULL) {
        printf("Error:  Out of memory.\n");
        exit(1);
      }
    }
    out->numberoftrifaces = subfaces->items;
    elist = out->trifacelist;
    emlist = out->trifacemarkerlist;
    index = 0;
  }

  subfaces->traversalinit();
  faceloop.sh = shellfacetraverse(subfaces);
  facenumber = in->firstnumber;
  while (faceloop.sh != (shellface *) NULL) {
    stpivot(faceloop, abuttingtet);
    if (abuttingtet.tet == dummytet) {
      sesymself(faceloop);
      stpivot(faceloop, abuttingtet);
      // assert(abuttingtet.tet != dummytet) {
    }
    if (abuttingtet.tet != dummytet) {
      // If there is a tetrahedron containing this subface, orient it so
      //   that the normal of this face points to inside of the volume by
      //   right-hand rule.
      adjustedgering(abuttingtet, CCW);
      torg = org(abuttingtet);
      tdest = dest(abuttingtet);
      tapex = apex(abuttingtet);
    } else {
      // This may happen when only a surface mesh be generated.
      torg = sorg(faceloop);
      tdest = sdest(faceloop);
      tapex = sapex(faceloop);
    }
    if (bmark) {
      faceid = shellmark(faceloop) - 1;
      marker = in->facetmarkerlist[faceid];
    }
    if (out == (tetgenio *) NULL) {
      fprintf(outfile, "%5d   %4d  %4d  %4d", facenumber,
              pointmark(torg), pointmark(tdest), pointmark(tapex));
      if (bmark) {
        fprintf(outfile, "    %d", marker);
      }
      fprintf(outfile, "\n");
    } else {
      // Output three vertices of this face;
      elist[index++] = pointmark(torg);
      elist[index++] = pointmark(tdest);
      elist[index++] = pointmark(tapex);
      if (bmark) {
        emlist[facenumber - in->firstnumber] = marker;
      }
    }
    facenumber++;
    faceloop.sh = shellfacetraverse(subfaces);
  }

  if (out == (tetgenio *) NULL) {
    fprintf(outfile, "# Generated by %s\n", b->commandline);
    fclose(outfile);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// outsubsegments()    Output segments (i.e. boundary edges) to a .edge file //
//                     or a tetgenio structure.                              //
//                                                                           //
// The boundary edges are stored in 'subsegs'.                               //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::outsubsegments(tetgenio* out)
{
  FILE *outfile;
  char edgefilename[FILENAMESIZE];
  int *elist;
  int index;
  face edgeloop;
  point torg, tdest;
  int edgenumber;

  if (out == (tetgenio *) NULL) {
    strcpy(edgefilename, b->outfilename);
    strcat(edgefilename, ".edge");
  }

  if (!b->quiet) {
    if (out == (tetgenio *) NULL) {
      printf("Writing %s.\n", edgefilename);
    } else {
      printf("Writing faces.\n");
    }
  }

  if (out == (tetgenio *) NULL) {
    outfile = fopen(edgefilename, "w");
    if (outfile == (FILE *) NULL) {
      printf("File I/O Error:  Cannot create file %s.\n", edgefilename);
      exit(1);
    }
    // Number of subsegments.
    fprintf(outfile, "%ld\n", subsegs->items);
  } else {
    // Allocate memory for 'edgelist'.
    out->edgelist = new int[subsegs->items * 2];
    if (out->edgelist == (int *) NULL) {
      printf("Error:  Out of memory.\n");
      exit(1);
    }
    out->numberofedges = subsegs->items;
    elist = out->edgelist;
    index = 0;
  }

  subsegs->traversalinit();
  edgeloop.sh = shellfacetraverse(subsegs);
  edgenumber = in->firstnumber;
  while (edgeloop.sh != (shellface *) NULL) {
    torg = sorg(edgeloop);
    tdest = sdest(edgeloop);
    if (out == (tetgenio *) NULL) {
      fprintf(outfile, "%5d   %4d  %4d\n", edgenumber, pointmark(torg),
              pointmark(tdest));
    } else {
      // Output three vertices of this face;
      elist[index++] = pointmark(torg);
      elist[index++] = pointmark(tdest);
    }
    edgenumber++;
    edgeloop.sh = shellfacetraverse(subsegs);
  }

  if (out == (tetgenio *) NULL) {
    fprintf(outfile, "# Generated by %s\n", b->commandline);
    fclose(outfile);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// outneighbors()    Output a list of neighbors to a .neigh file or a        //
//                   tetgenio structure.                                     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::outneighbors(tetgenio* out)
{
  FILE *outfile;
  char neighborfilename[FILENAMESIZE];
  int *nlist;
  int index;
  tetrahedron *tptr;
  triface tetloop, tetsym;
  int neighbor1, neighbor2, neighbor3, neighbor4;
  int elementnumber;

  if (out == (tetgenio *) NULL) {
    strcpy(neighborfilename, b->outfilename);
    strcat(neighborfilename, ".neigh");
  }

  if (!b->quiet) {
    if (out == (tetgenio *) NULL) {
      printf("Writing %s.\n", neighborfilename);
    } else {
      printf("Writing neighbors.\n");
    }
  }

  if (out == (tetgenio *) NULL) {
    outfile = fopen(neighborfilename, "w");
    if (outfile == (FILE *) NULL) {
      printf("File I/O Error:  Cannot create file %s.\n", neighborfilename);
      exit(1);
    }
    // Number of tetrahedra, four faces per tetrahedron.
    fprintf(outfile, "%ld  %d\n", tetrahedrons->items, 4);
  } else {
    // Allocate memory for 'neighborlist'.
    out->neighborlist = new int[tetrahedrons->items * 4];
    if (out->neighborlist == (int *) NULL) {
      printf("Error:  Out of memory.\n");
      exit(1);
    }
    nlist = out->neighborlist;
    index = 0;
  }

  tetrahedrons->traversalinit();
  tptr = tetrahedrontraverse();
  elementnumber = in->firstnumber;
  while (tptr != (tetrahedron *) NULL) {
    * (int *) (tptr + 8) = elementnumber;
    tptr = tetrahedrontraverse();
    elementnumber++;
  }
  * (int *) (dummytet + 8) = -1;

  tetrahedrons->traversalinit();
  tetloop.tet = tetrahedrontraverse();
  elementnumber = in->firstnumber;
  while (tetloop.tet != (tetrahedron *) NULL) {
    tetloop.loc = 2;
    sym(tetloop, tetsym);
    neighbor1 = * (int *) (tetsym.tet + 8);
    tetloop.loc = 3;
    sym(tetloop, tetsym);
    neighbor2 = * (int *) (tetsym.tet + 8);
    tetloop.loc = 1;
    sym(tetloop, tetsym);
    neighbor3 = * (int *) (tetsym.tet + 8);
    tetloop.loc = 0;
    sym(tetloop, tetsym);
    neighbor4 = * (int *) (tetsym.tet + 8);
    if (out == (tetgenio *) NULL) {
      // Tetrahedra number, neighboring tetrahedron numbers.
      fprintf(outfile, "%4d    %4d  %4d  %4d  %4d\n", elementnumber,
              neighbor1, neighbor2, neighbor3, neighbor4);
    } else {
      nlist[index++] = neighbor1;
      nlist[index++] = neighbor2;
      nlist[index++] = neighbor3;
      nlist[index++] = neighbor4;
    }
    tetloop.tet = tetrahedrontraverse();
    elementnumber++;
  }

  if (out == (tetgenio *) NULL) {
    fprintf(outfile, "# Generated by %s\n", b->commandline);
    fclose(outfile);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// outpbcnodes()    Output a list of node pairs to a .pbc file or a tetgenio //
//                  structure.                                               //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::outpbcnodes(tetgenio* out)
{ 
  FILE *outfile;
  char pbcfilename[FILENAMESIZE];
  list *ptpairlist;
  tetgenio::pbcgroup *pgi, *pgo;
  pbcdata *pd;
  face faceloop;
  face checkseg, symseg;
  point *ptpair, pa, pb;
  REAL sympt[3];
  int *worklist;
  int index, idx;
  int i, j, k, l;

  if (out == (tetgenio *) NULL) {
    strcpy(pbcfilename, b->outfilename);
    strcat(pbcfilename, ".pbc");
  }

  if (!b->quiet) {
    if (out == (tetgenio *) NULL) {
      printf("Writing %s.\n", pbcfilename);
    } else {
      printf("Writing pbc nodes.\n");
    }
  }

  if (out == (tetgenio *) NULL) {
    outfile = fopen(pbcfilename, "w");
    if (outfile == (FILE *) NULL) {
      printf("File I/O Error:  Cannot create file %s.\n", pbcfilename);
      exit(1);
    }
    // Number of pbc groups.
    fprintf(outfile, "# number of PBCs.\n");
    fprintf(outfile, "%d\n\n", in->numberofpbcgroups);
  } else {
    out->numberofpbcgroups = in->numberofpbcgroups;
    // Allocate memory for 'out->pbcgrouplist'.
    out->pbcgrouplist = new tetgenio::pbcgroup[in->numberofpbcgroups];
    if (out->neighborlist == (int *) NULL) {
      printf("Error:  Out of memory.\n");
      exit(1);
    }
  }

  ptpairlist = new list(2 * sizeof(point *), NULL, 256);
  worklist = new int[points->items + 1];
  for (i = 0; i < points->items + 1; i++) worklist[i] = 0;

  for (i = 0; i < in->numberofpbcgroups; i++) {
    // Group i.
    pgi = &(in->pbcgrouplist[i]);
    if (out == (tetgenio *) NULL) {
      fprintf(outfile, "# PBC %d\n", in->firstnumber + i);
      // Output facet markers.
      fprintf(outfile, "%d  %d\n", pgi->fmark1, pgi->fmark2);
      // Output transformation matrix.
      fprintf(outfile, "[\n");
      for (j = 0; j < 4; j++) {
        fprintf(outfile, "  %.12g %.12g %.12g %.12g\n", pgi->transmat[j][0],
                pgi->transmat[j][1], pgi->transmat[j][2], pgi->transmat[j][3]);
      }
      fprintf(outfile, "]\n");
    } else {
      pgo = &(out->pbcgrouplist[i]);
      // Copy data from pgi to pgo.
      pgo->fmark1 = pgi->fmark1;
      pgo->fmark2 = pgi->fmark2;
      for (j = 0; j < 4; j++) {
        for (k = 0; k < 4; k++) pgo->transmat[j][k] = pgi->transmat[j][k];
      }
    }

    // Find the point pairs of group i.
    subfaces->traversalinit();
    faceloop.sh = shellfacetraverse(subfaces);
    while (faceloop.sh != (shellface *) NULL) {
      if (shellpbcgroup(faceloop) == i) {
        // It is in group i. Operate on it if it has pgi->fmark1.
        idx = shellmark(faceloop) - 1;
        if (in->facetmarkerlist[idx] == pgi->fmark1) {
          // Loop three edges of the subface.
          for (j = 0; j < 3; j++) {
            sspivot(faceloop, checkseg);
            // Loop two vertices of the edge.
            for (k = 0; k < 2; k++) {
              if (k == 0) pa = sorg(faceloop);
              else pa = sdest(faceloop);
              if (worklist[pointmark(pa)] == 0) {
                pb = (point) NULL;
                if (checkseg.sh != dummysh) {
                  // pa is on a segment. Find pb.
                  // Find the incident pbcgroup of checkseg.
                  idx = shellmark(checkseg) - 1;
                  for (l = idx2segpglist[idx]; l < idx2segpglist[idx + 1];
                       l++) {
                    pd = (pbcdata *)(* segpbcgrouptable)[segpglist[l]];
                    if (((pd->fmark[0] == pgi->fmark1) &&
                         (pd->fmark[1] == pgi->fmark2)) ||
                        ((pd->fmark[0] == pgi->fmark2) &&
                         (pd->fmark[1] == pgi->fmark1))) break;
                  }
                  assert(l < idx2segpglist[idx + 1]);
                  getsegpbcsympoint(pa, &checkseg, sympt, &symseg,
                                    segpglist[l]);
                  pb = sorg(symseg);
                } else {
                  // Operate on pa if it is inside the facet.
                  if (pointtype(pa) == FREESUBVERTEX) {
                    pb = point2pbcpt(pa);
                  }
                }
                if (pb != (point) NULL) {
                  // Add the pair (pa, pb) into list. 
                  ptpair = (point *) ptpairlist->append(NULL);
                  ptpair[0] = pa;
                  ptpair[1] = pb;
                  // Mark pa (avoid to operate on it later).
                  worklist[pointmark(pa)] = 1;
                }
              }
            }
            // Get the next edge.
            senextself(faceloop);
          }
        }
      }
      faceloop.sh = shellfacetraverse(subfaces);
    }

    // Output the list of pbc points.
    if (out == (tetgenio *) NULL) {
      fprintf(outfile, "%d\n", ptpairlist->len());
    } else {
      pgo->numberofpointpairs = ptpairlist->len();
      pgo->pointpairlist = new int[pgo->numberofpointpairs * 2];
      index = 0;
    }
    for (j = 0; j < ptpairlist->len(); j++) {
      ptpair = (point *)(* ptpairlist)[j];
      pa = ptpair[0];
      pb = ptpair[1];
      if (out == (tetgenio *) NULL) {
        fprintf(outfile, "  %4d %4d\n", pointmark(pa), pointmark(pb));
      } else {
        pgo->pointpairlist[index++] = pointmark(pa);
        pgo->pointpairlist[index++] = pointmark(pb);
      }
      // Unmark pa.
      worklist[pointmark(pa)] = 0;
    }
    if (out == (tetgenio *) NULL) {
      fprintf(outfile, "\n");
    }
    ptpairlist->clear();
  }

  delete [] worklist;
  delete ptpairlist;

  if (out == (tetgenio *) NULL) {
    fprintf(outfile, "# Generated by %s\n", b->commandline);
    fclose(outfile);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// outsmesh()    Write surface mesh to a .smesh file, which can be read and  //
//               tetrahedralized by TetGen.                                  //
//                                                                           //
// You can specify a filename (without suffix) in 'smfilename'. If you don't //
// supply a filename (let smfilename be NULL), the default name stored in    //
// 'tetgenbehavior' will be used.                                            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::outsmesh(char* smfilename)
{
  FILE *outfile;
  char smefilename[FILENAMESIZE];
  face faceloop;
  point pointloop;
  point p1, p2, p3;
  int pointnumber;
  int nextras, bmark;
  int faceid, marker;

  if (smfilename != (char *) NULL && smfilename[0] != '\0') {
    strcpy(smefilename, smfilename);
  } else if (b->outfilename[0] != '\0') {
    strcpy(smefilename, b->outfilename);
  } else {
    strcpy(smefilename, "unnamed");
  }
  strcat(smefilename, ".smesh");

  if (!b->quiet) {
    printf("Writing %s.\n", smefilename);
  }
  outfile = fopen(smefilename, "w");
  if (outfile == (FILE *) NULL) {
    printf("File I/O Error:  Cannot create file %s.\n", smefilename);
    return;
  }

  fprintf(outfile, "# %s.  TetGen's input file.\n", smefilename);
  
  nextras = in->numberofpointattributes;
  bmark = !b->nobound && in->pointmarkerlist;
  
  fprintf(outfile, "\n# part 1: node list.\n");
  // Number of points, number of dimensions, number of point attributes,
  //   and number of boundary markers (zero or one).
  fprintf(outfile, "%ld  %d  %d  %d\n", points->items, 3, nextras, bmark);

  points->traversalinit();
  pointloop = pointtraverse();
  pointnumber = in->firstnumber;
  while (pointloop != (point) NULL) {
    // Point coordinates.
    fprintf(outfile, "%4d  %.17g  %.17g  %.17g",  pointnumber,
            pointloop[0], pointloop[1], pointloop[2]);
    if (in->numberofpointattributes > 0) {
      // Write an attribute, ignore others if more than one.
      fprintf(outfile, "  %.17g", pointloop[3]);
    }
    fprintf(outfile, "\n");
    setpointmark(pointloop, pointnumber);
    pointloop = pointtraverse();
    pointnumber++;
  }

  bmark = !b->nobound && in->facetmarkerlist;  

  fprintf(outfile, "\n# part 2: facet list.\n");
  // Number of facets, boundary marker.
  fprintf(outfile, "%ld  %d\n", subfaces->items, bmark);
  
  subfaces->traversalinit();
  faceloop.sh = shellfacetraverse(subfaces);
  while (faceloop.sh != (shellface *) NULL) {
    p1 = sorg(faceloop);
    p2 = sdest(faceloop);
    p3 = sapex(faceloop);
    if (bmark) {
      faceid = shellmark(faceloop) - 1;
      marker = in->facetmarkerlist[faceid];
    }
    fprintf(outfile, "3    %4d  %4d  %4d", pointmark(p1), pointmark(p2),
            pointmark(p3));
    if (bmark) {
      fprintf(outfile, "    %d", marker);
    }
    fprintf(outfile, "\n");
    faceloop.sh = shellfacetraverse(subfaces);
  }

  fprintf(outfile, "\n# part 3: hole list.\n");
  fprintf(outfile, "0\n");

  fprintf(outfile, "\n# part 4: region list.\n");
  fprintf(outfile, "0\n");

  fprintf(outfile, "# Generated by %s\n", b->commandline);
  fclose(outfile);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// outmesh2medit()    Write mesh to a .mesh file, which can be read and      //
//                    rendered by Medit (a free mesh viewer from INRIA).     //
//                                                                           //
// You can specify a filename (without suffix) in 'mfilename'.  If you don't //
// supply a filename (let mfilename be NULL), the default name stored in     //
// 'tetgenbehavior' will be used. The output file will have the suffix .mesh.//
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::outmesh2medit(char* mfilename)
{
  FILE *outfile;
  char mefilename[FILENAMESIZE];
  tetrahedron* tetptr;
  triface tface, tsymface;
  face segloop, checkmark;
  point pointloop, p1, p2, p3, p4;
  long faces;
  int pointnumber;
  int i;

  if (mfilename != (char *) NULL && mfilename[0] != '\0') {
    strcpy(mefilename, mfilename);
  } else if (b->outfilename[0] != '\0') {
    strcpy(mefilename, b->outfilename);
  } else {
    strcpy(mefilename, "unnamed");
  }
  strcat(mefilename, ".mesh");

  if (!b->quiet) {
    printf("Writing %s.\n", mefilename);
  }
  outfile = fopen(mefilename, "w");
  if (outfile == (FILE *) NULL) {
    printf("File I/O Error:  Cannot create file %s.\n", mefilename);
    return;
  }

  fprintf(outfile, "MeshVersionFormatted 1\n");
  fprintf(outfile, "\n");
  fprintf(outfile, "Dimension\n");
  fprintf(outfile, "3\n");
  fprintf(outfile, "\n");

  fprintf(outfile, "\n# Set of mesh vertices\n");
  fprintf(outfile, "Vertices\n");
  fprintf(outfile, "%ld\n", points->items);

  points->traversalinit();
  pointloop = pointtraverse();
  pointnumber = 1;                        // Medit need start number form 1.
  while (pointloop != (point) NULL) {
    // Point coordinates.
    fprintf(outfile, "%.17g  %.17g  %.17g",
            pointloop[0], pointloop[1], pointloop[2]);
    if (in->numberofpointattributes > 0) {
      // Write an attribute, ignore others if more than one.
      fprintf(outfile, "  %.17g\n", pointloop[3]);
    } else {
      fprintf(outfile, "    0\n");
    }
    setpointmark(pointloop, pointnumber);
    pointloop = pointtraverse();
    pointnumber++;
  }

  // Compute the number of edges.
  faces = (4l * tetrahedrons->items + hullsize) / 2l;

  fprintf(outfile, "\n# Set of Triangles\n");
  fprintf(outfile, "Triangles\n");
  fprintf(outfile, "%ld\n", faces);

  tetrahedrons->traversalinit();
  tface.tet = tetrahedrontraverse();
  // To loop over the set of faces, loop over all tetrahedra, and look at
  //   the four faces of each tetrahedron. If there isn't another tetrahedron
  //   adjacent to the face, operate on the face.  If there is another adj-
  //   acent tetrahedron, operate on the face only if the current tetrahedron
  //   has a smaller pointer than its neighbor.  This way, each face is
  //   considered only once.
  while (tface.tet != (tetrahedron *) NULL) {
    for (tface.loc = 0; tface.loc < 4; tface.loc ++) {
      sym(tface, tsymface);
      if (tface.tet < tsymface.tet || tsymface.tet == dummytet) {
        p1 = org (tface);
        p2 = dest(tface);
        p3 = apex(tface);
        fprintf(outfile, "%5d  %5d  %5d",
                pointmark(p1), pointmark(p2), pointmark(p3));
        fprintf(outfile, "    0\n");
      }
    }
    tface.tet = tetrahedrontraverse();
  }

  fprintf(outfile, "\n# Set of Tetrahedra\n");
  fprintf(outfile, "Tetrahedra\n");
  fprintf(outfile, "%ld\n", tetrahedrons->items);

  tetrahedrons->traversalinit();
  tetptr = tetrahedrontraverse();
  while (tetptr != (tetrahedron *) NULL) {
    p1 = (point) tetptr[4];
    p2 = (point) tetptr[5];
    p3 = (point) tetptr[6];
    p4 = (point) tetptr[7];
    fprintf(outfile, "%5d  %5d  %5d  %5d",
            pointmark(p1), pointmark(p2), pointmark(p3), pointmark(p4));
    if (in->numberoftetrahedronattributes > 0) {
      fprintf(outfile, "  %.17g", elemattribute(tetptr, 0));
    } else {
      fprintf(outfile, "  0");
    }
    fprintf(outfile, "\n");
    tetptr = tetrahedrontraverse();
  }

  fprintf(outfile, "\nCorners\n");
  fprintf(outfile, "%d\n", in->numberofpoints);

  for (i = 0; i < in->numberofpoints; i++) {
    fprintf(outfile, "%4d\n", i + 1);
  }

  if (b->useshelles) {
    fprintf(outfile, "\nEdges\n");
    fprintf(outfile, "%ld\n", subsegs->items);

    subsegs->traversalinit();
    segloop.sh = shellfacetraverse(subsegs);
    while (segloop.sh != (shellface *) NULL) {
      p1 = sorg(segloop);
      p2 = sdest(segloop);
      fprintf(outfile, "%5d  %5d", pointmark(p1), pointmark(p2));
      fprintf(outfile, "    0\n");
      segloop.sh = shellfacetraverse(subsegs);
    }
  }

  fprintf(outfile, "\nEnd\n");
  fclose(outfile);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// outmesh2gid()    Write mesh to a .ele.msh file and a .face.msh file,      //
//                  which can be imported and rendered by Gid.               //
//                                                                           //
// You can specify a filename (without suffix) in 'gfilename'.  If you don't //
// supply a filename (let gfilename be NULL), the default name stored in     //
// 'tetgenbehavior' will be used. The suffixes (.ele.msh and .face.msh) will //
// be automatically added.                                                   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::outmesh2gid(char* gfilename)
{
  FILE *outfile;
  char gidfilename[FILENAMESIZE];
  tetrahedron* tetptr;
  triface tface, tsymface;
  face sface;
  point pointloop, p1, p2, p3, p4;
  int pointnumber;
  int elementnumber;

  if (gfilename != (char *) NULL && gfilename[0] != '\0') {
    strcpy(gidfilename, gfilename);
  } else if (b->outfilename[0] != '\0') {
    strcpy(gidfilename, b->outfilename);
  } else {
    strcpy(gidfilename, "unnamed");
  }
  strcat(gidfilename, ".ele.msh");

  if (!b->quiet) {
    printf("Writing %s.\n", gidfilename);
  }
  outfile = fopen(gidfilename, "w");
  if (outfile == (FILE *) NULL) {
    printf("File I/O Error:  Cannot create file %s.\n", gidfilename);
    return;
  }

  fprintf(outfile, "mesh dimension = 3 elemtype tetrahedron nnode = 4\n");
  fprintf(outfile, "coordinates\n");

  points->traversalinit();
  pointloop = pointtraverse();
  pointnumber = 1;                        // Gid need start number form 1.
  while (pointloop != (point) NULL) {
    // Point coordinates.
    fprintf(outfile, "%4d  %.17g %.17g %.17g", pointnumber,
            pointloop[0], pointloop[1], pointloop[2]);
    if (in->numberofpointattributes > 0) {
      // Write an attribute, ignore others if more than one.
      fprintf(outfile, "  %.17g", pointloop[3]);
    }
    fprintf(outfile, "\n");
    setpointmark(pointloop, pointnumber);
    pointloop = pointtraverse();
    pointnumber++;
  }

  fprintf(outfile, "end coordinates\n");
  fprintf(outfile, "elements\n");

  tetrahedrons->traversalinit();
  tetptr = tetrahedrontraverse();
  elementnumber = 1;
  while (tetptr != (tetrahedron *) NULL) {
    p1 = (point) tetptr[4];
    p2 = (point) tetptr[5];
    p3 = (point) tetptr[6];
    p4 = (point) tetptr[7];
    fprintf(outfile, "%5d  %5d %5d %5d %5d", elementnumber,
            pointmark(p1), pointmark(p2), pointmark(p3), pointmark(p4));
    if (in->numberoftetrahedronattributes > 0) {
      fprintf(outfile, "  %.17g", elemattribute(tetptr, 0));
    } 
    fprintf(outfile, "\n");
    tetptr = tetrahedrontraverse();
    elementnumber++;
  }

  fprintf(outfile, "end elements\n");
  fclose(outfile);

  if (gfilename != (char *) NULL && gfilename[0] != '\0') {
    strcpy(gidfilename, gfilename);
  } else if (b->outfilename[0] != '\0') {
    strcpy(gidfilename, b->outfilename);
  } else {
    strcpy(gidfilename, "unnamed");
  }
  strcat(gidfilename, ".face.msh");

  if (!b->quiet) {
    printf("Writing %s.\n", gidfilename);
  }
  outfile = fopen(gidfilename, "w");
  if (outfile == (FILE *) NULL) {
    printf("File I/O Error:  Cannot create file %s.\n", gidfilename);
    return;
  }

  fprintf(outfile, "mesh dimension = 3 elemtype triangle nnode = 3\n");
  fprintf(outfile, "coordinates\n");

  points->traversalinit();
  pointloop = pointtraverse();
  pointnumber = 1;                        // Gid need start number form 1.
  while (pointloop != (point) NULL) {
    // Point coordinates.
    fprintf(outfile, "%4d  %.17g %.17g %.17g", pointnumber,
            pointloop[0], pointloop[1], pointloop[2]);
    if (in->numberofpointattributes > 0) {
      // Write an attribute, ignore others if more than one.
      fprintf(outfile, "  %.17g", pointloop[3]);
    }
    fprintf(outfile, "\n");
    setpointmark(pointloop, pointnumber);
    pointloop = pointtraverse();
    pointnumber++;
  }

  fprintf(outfile, "end coordinates\n");
  fprintf(outfile, "elements\n");

  tetrahedrons->traversalinit();
  tface.tet = tetrahedrontraverse();
  elementnumber = 1;
  while (tface.tet != (tetrahedron *) NULL) {
    for (tface.loc = 0; tface.loc < 4; tface.loc ++) {
      sym(tface, tsymface);
      if ((tface.tet < tsymface.tet) || (tsymface.tet == dummytet)) {
        p1 = org(tface);
        p2 = dest(tface);
        p3 = apex(tface);
        if (tsymface.tet == dummytet) {
          // It's a hull face, output it.
          fprintf(outfile, "%5d   %d  %d  %d\n", elementnumber,
                  pointmark(p1), pointmark(p2), pointmark(p3));
          elementnumber++;
        } else if (b->useshelles) {
          // Only output it if it's a subface.
          tspivot(tface, sface);
          if (sface.sh != dummysh) {
            fprintf(outfile, "%5d   %d  %d  %d\n", elementnumber,
                    pointmark(p1), pointmark(p2), pointmark(p3));
            elementnumber++;
          }
        }
      }
    }
    tface.tet = tetrahedrontraverse();
  }

  fprintf(outfile, "end elements\n");
  fclose(outfile);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// outmesh2off()    Write the mesh to an .off file.                          //
//                                                                           //
// .off, the Object File Format, is one of the popular file formats from the //
// Geometry Center's Geomview package (http://www.geomview.org).             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::outmesh2off(char* ofilename)
{
  FILE *outfile;
  char offfilename[FILENAMESIZE];
  triface tface, tsymface;
  point pointloop, p1, p2, p3;
  long faces;
  int shift;

  if (ofilename != (char *) NULL && ofilename[0] != '\0') {
    strcpy(offfilename, ofilename);
  } else if (b->outfilename[0] != '\0') {
    strcpy(offfilename, b->outfilename);
  } else {
    strcpy(offfilename, "unnamed");
  }
  strcat(offfilename, ".off");

  if (!b->quiet) {
    printf("Writing %s.\n", offfilename);
  }
  outfile = fopen(offfilename, "w");
  if (outfile == (FILE *) NULL) {
    printf("File I/O Error:  Cannot create file %s.\n", offfilename);
    return;
  }

  // Calculate the number of triangular faces in the tetrahedral mesh.
  faces = (4l * tetrahedrons->items + hullsize) / 2l;

  // Number of points, faces, and edges(not used, here show hullsize).
  fprintf(outfile, "OFF\n%ld  %ld  %ld\n", points->items, faces, hullsize);

  // Write the points.
  points->traversalinit();
  pointloop = pointtraverse();
  while (pointloop != (point) NULL) {
    fprintf(outfile, " %.17g  %.17g  %.17g\n", pointloop[0], pointloop[1],
            pointloop[2]);
    pointloop = pointtraverse();
  }

  // OFF always use zero as the first index.
  shift = in->firstnumber == 1 ? 1 : 0;

  tetrahedrons->traversalinit();
  tface.tet = tetrahedrontraverse();
  // To loop over the set of faces, loop over all tetrahedra, and look at
  //   the four faces of each tetrahedron. If there isn't another tetrahedron
  //   adjacent to the face, operate on the face.  If there is another adj-
  //   acent tetrahedron, operate on the face only if the current tetrahedron
  //   has a smaller pointer than its neighbor.  This way, each face is
  //   considered only once.
  while (tface.tet != (tetrahedron *) NULL) {
    for (tface.loc = 0; tface.loc < 4; tface.loc ++) {
      sym(tface, tsymface);
      if ((tface.tet < tsymface.tet) || (tsymface.tet == dummytet)) {
        p1 = org(tface);
        p2 = dest(tface);
        p3 = apex(tface);
        // Face number, indices of three vertexs.
        fprintf(outfile, "3   %4d  %4d  %4d\n", pointmark(p1) - shift,
                pointmark(p2) - shift, pointmark(p3) - shift);
      }
    }
    tface.tet = tetrahedrontraverse();
  }

  fprintf(outfile, "# Generated by %s\n", b->commandline);
  fclose(outfile);
}

//
// End of I/O rouitnes
//

//
// Begin of user interaction routines
//

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// internalerror()    Ask the user to send me the defective product.  Exit.  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::internalerror()
{
  printf("  Please report this bug to sihang@mail.berlios.de. Include the\n");
  printf("    message above, your input data set, and the exact command\n");
  printf("    line you used to run this program, thank you.\n");
  exit(1);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// checkmesh()    Test the mesh for topological consistency.                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::checkmesh()
{
  triface tetraloop;
  triface oppotet, oppooppotet;
  point tetorg, tetdest, tetapex, tetoppo;
  point oppodest, oppoapex;
  REAL oritest;
  int horrors;

  if (!b->quiet) {
    printf("  Checking consistency of mesh...\n");
  }
  horrors = 0;
  // Run through the list of tetrahedra, checking each one.
  tetrahedrons->traversalinit();
  tetraloop.tet = tetrahedrontraverse();
  while (tetraloop.tet != (tetrahedron *) NULL) {
    // Check all four faces of the tetrahedron.
    for (tetraloop.loc = 0; tetraloop.loc < 4; tetraloop.loc++) {
      tetorg = org(tetraloop);
      tetdest = dest(tetraloop);
      tetapex = apex(tetraloop);
      tetoppo = oppo(tetraloop);
      if (tetraloop.loc == 0) {             // Only test for inversion once.
        oritest = orient3d(tetorg, tetdest, tetapex, tetoppo);
        if (oritest >= 0.0) {
          printf("  !! !! %s ", oritest > 0.0 ? "Inverted" : "Degenerated");
          printtet(&tetraloop);
          printf("  orient3d = %.17g.\n", oritest);
          horrors++;
        }
      }
      // Find the neighboring tetrahedron on this face.
      sym(tetraloop, oppotet);
      if (oppotet.tet != dummytet) {
        // Check that the tetrahedron's neighbor knows it's a neighbor.
        sym(oppotet, oppooppotet);
        if ((tetraloop.tet != oppooppotet.tet)
            || (tetraloop.loc != oppooppotet.loc)) {
          printf("  !! !! Asymmetric tetra-tetra bond:\n");
          if (tetraloop.tet == oppooppotet.tet) {
            printf("   (Right tetrahedron, wrong orientation)\n");
          }
          printf("    First ");
          printtet(&tetraloop);
          printf("    Second (nonreciprocating) ");
          printtet(&oppotet);
          horrors++;
        }
        // Check that both tetrahedra agree on the identities
        //   of their shared vertices.
        if (findorg(&oppotet, tetorg)) {
          oppodest = dest(oppotet);
          oppoapex = apex(oppotet);
        } else {
          oppodest = (point) NULL;
        }
        if ((tetdest != oppoapex) || (tetapex != oppodest)) {
          printf("  !! !! Mismatched face coordinates between two tetras:\n");
          printf("    First mismatched ");
          printtet(&tetraloop);
          printf("    Second mismatched ");
          printtet(&oppotet);
          horrors++;
        }
      }
    }
    tetraloop.tet = tetrahedrontraverse();
  }
  if (horrors == 0) {
    if (!b->quiet) {
      printf("  In my studied opinion, the mesh appears to be consistent.\n");
    }
  } else if (horrors == 1) {
    printf("  !! !! !! !! Precisely one festering wound discovered.\n");
  } else {
    printf("  !! !! !! !! %d abominations witnessed.\n", horrors);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// checkshells()       Test the boundary mesh for topological consistency.   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::checkshells()
{
  triface oppotet, oppooppotet, testtet; 
  face shloop, segloop, spin;
  face testsh, testseg, testshsh;
  point shorg, shdest, segorg, segdest;
  REAL checksign;
  bool same;
  int horrors;
  int i;

  if (!b->quiet) {
    printf("  Checking consistency of the mesh boundary...\n");
  }
  horrors = 0;

  // Run through the list of subfaces, checking each one.
  subfaces->traversalinit();
  shloop.sh = shellfacetraverse(subfaces);
  while (shloop.sh != (shellface *) NULL) {
    // Check two connected tetrahedra if they exist.
    shloop.shver = 0;
    stpivot(shloop, oppotet);
    if (oppotet.tet != dummytet) {
      tspivot(oppotet, testsh);
      if (testsh.sh != shloop.sh) {
        printf("  !! !! Wrong tetra-subface connection.\n");
        printf("    Tetra: ");
        printtet(&oppotet);
        printf("    Subface: ");
        printsh(&shloop);
        horrors++;
      }
      if (oppo(oppotet) != (point) NULL) {
        adjustedgering(oppotet, CCW);
        checksign = orient3d(sorg(shloop), sdest(shloop), sapex(shloop),
                             oppo(oppotet));
        if (checksign >= 0.0) {
          printf("  !! !! Wrong subface orientation.\n");
          printf("    Subface: ");
          printsh(&shloop);
          horrors++;
        }
      }
    }
    sesymself(shloop);
    stpivot(shloop, oppooppotet);
    if (oppooppotet.tet != dummytet) {
      tspivot(oppooppotet, testsh);
      if (testsh.sh != shloop.sh) {
        printf("  !! !! Wrong tetra-subface connection.\n");
        printf("    Tetra: ");
        printtet(&oppooppotet);
        printf("    Subface: ");
        printsh(&shloop);
        horrors++;
      }
      if (oppotet.tet != dummytet) {
        sym(oppotet, testtet);
        if (testtet.tet != oppooppotet.tet) {
          printf("  !! !! Wrong tetra-subface-tetra connection.\n");
          printf("    Tetra 1: ");
          printtet(&oppotet);
          printf("    Subface: ");
          printsh(&shloop);
          printf("    Tetra 2: ");
          printtet(&oppooppotet);
          horrors++;
        }
      }
      if (oppo(oppooppotet) != (point) NULL) {
        adjustedgering(oppooppotet, CCW);
        checksign = orient3d(sorg(shloop), sdest(shloop), sapex(shloop),
                             oppo(oppooppotet));
        if (checksign >= 0.0) {
          printf("  !! !! Wrong subface orientation.\n");
          printf("    Subface: ");
          printsh(&shloop);
          horrors++;
        }
      }
    }
    // Check connection between subfaces.
    shloop.shver = 0;
    for (i = 0; i < 3; i++) {
      shorg = sorg(shloop);
      shdest = sdest(shloop);
      sspivot(shloop, testseg);
      if (testseg.sh != dummysh) {
        segorg = sorg(testseg);
        segdest = sdest(testseg);
        same = ((shorg == segorg) && (shdest == segdest)) 
	    || ((shorg == segdest) && (shdest == segorg));
        if (!same) {
          printf("  !! !! Wrong subface-subsegment connection.\n");
          printf("    Subface: ");
          printsh(&shloop);
          printf("    Subsegment: ");
          printsh(&testseg);
          horrors++;
        } 
      } 
      spivot(shloop, testsh);
      if (testsh.sh != dummysh) {
        segorg = sorg(testsh);
        segdest = sdest(testsh);
        same = ((shorg == segorg) && (shdest == segdest)) 
	    || ((shorg == segdest) && (shdest == segorg));
        if (!same) {
          printf("  !! !! Wrong subface-subface connection.\n");
          printf("    Subface 1: ");
          printsh(&shloop);
          printf("    Subface 2: ");
          printsh(&testsh);
          horrors++;
        }
        spivot(testsh, testshsh);
        shorg = sorg(testshsh);
        shdest = sdest(testshsh);
        same = ((shorg == segorg) && (shdest == segdest)) 
	    || ((shorg == segdest) && (shdest == segorg));
        if (!same) {
          printf("  !! !! Wrong subface-subface connection.\n");
          printf("    Subface 1: ");
          printsh(&testsh);
          printf("    Subface 2: ");
          printsh(&testshsh);
          horrors++;
        }
        if (testseg.sh == dummysh) {
          if (testshsh.sh != shloop.sh) {
            printf("  !! !! Wrong subface-subface connection.\n");
            printf("    Subface 1: ");
            printsh(&shloop);
            printf("    Subface 2: ");
            printsh(&testsh);
            horrors++;
          }
        } 
      }
      senextself(shloop);
    }
    shloop.sh = shellfacetraverse(subfaces);
  }

  // Run through the list of subsegs, checking each one.
  subsegs->traversalinit();
  segloop.sh = shellfacetraverse(subsegs);
  while (segloop.sh != (shellface *) NULL) {
    segorg = sorg(segloop);
    segdest = sdest(segloop);
    spivot(segloop, testsh);
    if (testsh.sh == dummysh) {
      printf("  !! !! Wrong subsegment-subface connection.\n");
      printf("    Subsegment: ");
      printsh(&segloop);
      horrors++;
      segloop.sh = shellfacetraverse(subsegs);
      continue;
    }
    shorg = sorg(testsh);
    shdest = sdest(testsh);
    same = ((shorg == segorg) && (shdest == segdest)) 
        || ((shorg == segdest) && (shdest == segorg));
    if (!same) {
      printf("  !! !! Wrong subsegment-subface connection.\n");
      printf("    Subsegment : ");
      printsh(&segloop);
      printf("    Subface : ");
      printsh(&testsh);
      horrors++;
      segloop.sh = shellfacetraverse(subsegs);
      continue;
    }
    // Check the connection of face loop around this subsegment.
    spin = testsh;
    i = 0;
    do {
      spivotself(spin);
      shorg = sorg(spin);
      shdest = sdest(spin);
      same = ((shorg == segorg) && (shdest == segdest)) 
          || ((shorg == segdest) && (shdest == segorg));
      if (!same) {
        printf("  !! !! Wrong subsegment-subface connection.\n");
        printf("    Subsegment : ");
        printsh(&segloop);
        printf("    Subface : ");
        printsh(&testsh);
        horrors++;
        break;
      }
      i++;
    } while (spin.sh != testsh.sh && i < 1000);
    if (i >= 1000) {
      printf("  !! !! Wrong subsegment-subface connection.\n");
      printf("    Subsegment : ");
      printsh(&segloop);
      horrors++;
    }
    segloop.sh = shellfacetraverse(subsegs);
  }
  if (horrors == 0) {
    if (!b->quiet) {
      printf("  Mesh boundaries connected correctly.\n");
    }
  } else {
    printf("  !! !! !! !! %d boundary connection viewed with horror.\n",
           horrors);
    return;
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// checkdelaunay()    Ensure that the mesh is constrained Delaunay.          //
//                                                                           //
// If 'flipqueue' is not NULL, non-locally Delaunay faces are saved in it.   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::checkdelaunay(REAL eps, queue* flipqueue)
{
  triface tetraloop;
  triface oppotet;
  face opposhelle;
  point tetorg, tetdest, tetapex, tetoppo;
  point oppooppo;
  REAL sign;
  int shouldbedelaunay;
  int horrors;

  if (!b->quiet) {
    printf("  Checking Delaunay property of the mesh...\n");
  }
  horrors = 0;
  // Run through the list of triangles, checking each one.
  tetrahedrons->traversalinit();
  tetraloop.tet = tetrahedrontraverse();
  while (tetraloop.tet != (tetrahedron *) NULL) {
    // Check all four faces of the tetrahedron.
    for (tetraloop.loc = 0; tetraloop.loc < 4; tetraloop.loc++) {
      tetorg = org(tetraloop);
      tetdest = dest(tetraloop);
      tetapex = apex(tetraloop);
      tetoppo = oppo(tetraloop);
      sym(tetraloop, oppotet);
      oppooppo = oppo(oppotet);
      // Only do testif there is an adjoining tetrahedron whose pointer is
      //   larger (to ensure that each pair isn't tested twice).
      shouldbedelaunay = (oppotet.tet != dummytet)
                          && (tetoppo != (point) NULL)
                          && (oppooppo != (point) NULL)
                          && (tetraloop.tet < oppotet.tet);
      if (checksubfaces && shouldbedelaunay) {
        // If a shell face separates the tetrahedra, then the face is
        //   constrained, so no local Delaunay test should be done.
        tspivot(tetraloop, opposhelle);
        if (opposhelle.sh != dummysh){
          shouldbedelaunay = 0;
        }
      }
      if (shouldbedelaunay) {
        sign = insphere(tetdest, tetorg, tetapex, tetoppo, oppooppo);
        if ((sign > 0.0) && (eps > 0.0)) {
          if (iscospheric(tetdest, tetorg, tetapex, tetoppo, oppooppo, sign,
                          eps)) sign = 0.0;
        }
        if (sign > 0.0) {
          if (flipqueue) {
            enqueueflipface(tetraloop, flipqueue);
          } else {
            printf("  !! Non-locally Delaunay face (%d, %d, %d).\n",
                   pointmark(tetorg), pointmark(tetdest), pointmark(tetapex));
          }
          horrors++;
        }
      }
    }
    tetraloop.tet = tetrahedrontraverse();
  }
  if (flipqueue == (queue *) NULL) {
    if (horrors == 0) {
      if (!b->quiet) {
        printf("  The mesh is %s.\n",
               checksubfaces ? "constrained Delaunay" : "Delaunay");
      }
    } else {
      printf("  !! !! !! !! %d obscenities viewed with horror.\n", horrors);
    }
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// checkdegeneracy()    Check if the point set contains degeneracies.        //
//                                                                           //
// 'eps' is a relative error tolerance for testing approximatly degeneracies.//
// Set it to zero if only exact test is desired.                             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::checkdegeneracy(REAL eps)
{
  triface tetraloop;
  triface oppotet;
  point tetorg, tetdest, tetapex, tetoppo;
  point oppooppo;
  REAL sign;
  int horrors;

  if (!b->quiet) {
    printf("  Checking degeneracies in the point set...\n");
  }
  horrors = 0;
  // Run through the list of triangles, checking each one.
  tetrahedrons->traversalinit();
  tetraloop.tet = tetrahedrontraverse();
  while (tetraloop.tet != (tetrahedron *) NULL) {
    // Check all four faces of the tetrahedron.
    for (tetraloop.loc = 0; tetraloop.loc < 4; tetraloop.loc++) {
      tetorg = org(tetraloop);
      tetdest = dest(tetraloop);
      tetapex = apex(tetraloop);
      tetoppo = oppo(tetraloop);
      sym(tetraloop, oppotet);
      oppooppo = oppo(oppotet);
      // Only do test if there is an adjoining tetrahedron whose pointer is
      //   larger (to ensure that each pair isn't tested twice).
      if ((oppotet.tet != dummytet) && (tetoppo != (point) NULL) &&
          (oppooppo != (point) NULL) && (tetraloop.tet < oppotet.tet)) {
        sign = insphere(tetdest, tetorg, tetapex, tetoppo, oppooppo);
        if ((sign != 0.0) && (eps > 0.0)) {
          if (iscospheric(tetdest, tetorg, tetapex, tetoppo, oppooppo, sign,
                          eps)) sign = 0.0;
        }
        if (sign == 0.0) {
          printf("  !! Degenerate set (%d, %d, %d, %d, %d).\n",
                 pointmark(tetorg), pointmark(tetdest), pointmark(tetapex),
                 pointmark(tetoppo), pointmark(oppooppo));
          horrors++;
        }
      }
    }
    tetraloop.tet = tetrahedrontraverse();
  }

  if (horrors == 0) {
    if (!b->quiet) {
      printf("  The point set is non-degenerate.\n");
    }
  } else {
    printf("  !! !! !! !! %d obscenities viewed with horror.\n", horrors);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// checkconforming()    Ensure that the mesh is conforming Delaunay.         //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::checkconforming()
{
  face segloop, shloop;
  int encsubsegs, encsubfaces;

  if (!b->quiet) {
    printf("  Checking conforming Delaunay property of mesh...\n");
  }
  encsubsegs = encsubfaces = 0;
  // Run through the list of subsegments, check each one.
  subsegs->traversalinit();
  segloop.sh = shellfacetraverse(subsegs);
  while (segloop.sh != (shellface *) NULL) {
    if (checkseg4encroach(&segloop, NULL, NULL, false)) {
      printf("  !! !! Non-conforming subsegment: ");
      printsh(&segloop);
      encsubsegs++;
    }
    segloop.sh = shellfacetraverse(subsegs);
  }
  // Run through the list of subfaces, check each one.
  subfaces->traversalinit();
  shloop.sh = shellfacetraverse(subfaces);
  while (shloop.sh != (shellface *) NULL) {
    if (checksub4encroach(&shloop, NULL, false)) {
      printf("  !! !! Non-conforming subface: ");
      printsh(&shloop);
      encsubfaces++;
    }
    shloop.sh = shellfacetraverse(subfaces);
  }
  if (encsubsegs == 0 && encsubfaces == 0) {
    if (!b->quiet) {
      printf("  The mesh is conforming Delaunay.\n");
    }
  } else {
    if (encsubsegs > 0) {
      printf("  !! !! %d subsegments are non-conforming.\n", encsubsegs);
    }
    if (encsubfaces > 0) {
      printf("  !! !! %d subfaces are non-conforming.\n", encsubfaces);
    }
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// qualitystatistics()    Print statistics about the quality of the mesh.    //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::qualitystatistics()
{
  triface tetloop;
  point p[4];
  char sbuf[128];
  REAL radiusratiotable[12];
  REAL aspectratiotable[16];
  REAL dx[6], dy[6], dz[6];
  REAL edgelength[6];
  REAL alldihed[6];
  REAL cent[3];
  REAL shortest, longest;
  REAL smallestvolume, biggestvolume;
  REAL smallestdiangle, biggestdiangle;
  REAL tetvol;
  REAL tetlongest2;
  REAL minaltitude;
  REAL cirradius, insradius;
  REAL shortlen, longlen;
  REAL tetaspect, tetradius;
  REAL smalldiangle, bigdiangle;
  int radiustable[12];
  int aspecttable[16];
  int dihedangletable[18];
  int radiusindex;
  int aspectindex;
  int tendegree;
  int i, j, k;

  printf("Mesh quality statistics:\n\n");

  radiusratiotable[0]  =    0.707;    radiusratiotable[1]  =     1.0;
  radiusratiotable[2]  =      1.1;    radiusratiotable[3]  =     1.2;
  radiusratiotable[4]  =      1.4;    radiusratiotable[5]  =     1.6;
  radiusratiotable[6]  =      1.8;    radiusratiotable[7]  =     2.0;
  radiusratiotable[8]  =      2.5;    radiusratiotable[9]  =     3.0;
  radiusratiotable[10] =     10.0;    radiusratiotable[11] =     0.0;

  aspectratiotable[0]  =      1.5;    aspectratiotable[1]  =     2.0;
  aspectratiotable[2]  =      2.5;    aspectratiotable[3]  =     3.0;
  aspectratiotable[4]  =      4.0;    aspectratiotable[5]  =     6.0;
  aspectratiotable[6]  =     10.0;    aspectratiotable[7]  =    15.0;
  aspectratiotable[8]  =     25.0;    aspectratiotable[9]  =    50.0;
  aspectratiotable[10] =    100.0;    aspectratiotable[11] =   300.0;
  aspectratiotable[12] =   1000.0;    aspectratiotable[13] = 10000.0;
  aspectratiotable[14] = 100000.0;    aspectratiotable[15] =     0.0;
  
  for (i = 0; i < 12; i++) {
    radiustable[i] = 0;
  }
  for (i = 0; i < 16; i++) {
    aspecttable[i] = 0;
  }
  for (i = 0; i < 18; i++) {
    dihedangletable[i] = 0;
  }

  minaltitude = xmax - xmin + ymax - ymin + zmax - zmin;
  minaltitude = minaltitude * minaltitude;
  shortest = minaltitude;
  longest = 0.0;
  smallestvolume = minaltitude;
  biggestvolume = 0.0;
  smallestdiangle = 180.0;
  biggestdiangle = 0.0;

  // Loop all elements, calculate quality parameters for each element.
  tetrahedrons->traversalinit();
  tetloop.tet = tetrahedrontraverse();
  while (tetloop.tet != (tetrahedron *) NULL) {
    p[0] = org(tetloop);
    p[1] = dest(tetloop);
    p[2] = apex(tetloop);
    p[3] = oppo(tetloop);
    tetlongest2 = 0.0;
    
    // Calculate the longest and shortest edge length.
    for (i = 0; i < 3; i++) {
      j = plus1mod3[i];
      k = minus1mod3[i];
      dx[i] = p[j][0] - p[k][0];
      dy[i] = p[j][1] - p[k][1];
      dz[i] = p[j][2] - p[k][2];
      edgelength[i] = dx[i] * dx[i] + dy[i] * dy[i] + dz[i] * dz[i];
      if (i == 0) {
        shortlen = longlen = edgelength[i];
      } else {
        shortlen = edgelength[i] < shortlen ? edgelength[i] : shortlen;
        longlen  = edgelength[i] > longlen  ? edgelength[i] : longlen;
      }
      if (edgelength[i] > tetlongest2) {
        tetlongest2 = edgelength[i];
      }
      if (edgelength[i] > longest) {
        longest = edgelength[i];
      }
      if (edgelength[i] < shortest) {
        shortest = edgelength[i];
      }
    }
    for (i = 3; i < 6; i++) {
      j = i - 3;
      k = 3;
      dx[i] = p[j][0] - p[k][0];
      dy[i] = p[j][1] - p[k][1];
      dz[i] = p[j][2] - p[k][2];
      edgelength[i] = dx[i] * dx[i] + dy[i] * dy[i] + dz[i] * dz[i];
      shortlen = edgelength[i] < shortlen ? edgelength[i] : shortlen;
      longlen  = edgelength[i] > longlen  ? edgelength[i] : longlen;
      if (edgelength[i] > tetlongest2) {
        tetlongest2 = edgelength[i];
      }
      if (edgelength[i] > longest) {
        longest = edgelength[i];
      }
      if (edgelength[i] < shortest) {
        shortest = edgelength[i];
      }
    }
    
    // Calculate the largest and smallest volume.
    tetvol = orient3d(p[0], p[1], p[2], p[3]) / 6.0;
    if (tetvol < 0) tetvol = -tetvol;
    if (tetvol < smallestvolume) {
      smallestvolume = tetvol;
    }
    if (tetvol > biggestvolume) {
      biggestvolume = tetvol;
    }
    
    // Calculate the largest and smallest dihedral angles.
    tetalldihedral(p[0], p[1], p[2], p[3], alldihed);
    for (i = 0; i < 6; i++) {
      alldihed[i] = alldihed[i] * 180.0 / PI;
      if (i == 0) {
        smalldiangle = bigdiangle = alldihed[i];
      } else {
        smalldiangle = alldihed[i] < smalldiangle ? alldihed[i] : smalldiangle;
        bigdiangle = alldihed[i] > bigdiangle ? alldihed[i] : bigdiangle;
      }
      if (alldihed[i] < smallestdiangle) {
        smallestdiangle = alldihed[i];
      } else if (alldihed[i] > biggestdiangle) {
        biggestdiangle = alldihed[i];
      }
    }
    tendegree = (int) (smalldiangle / 10.);
    dihedangletable[tendegree]++;
    tendegree = (int) (bigdiangle / 10.);
    dihedangletable[tendegree]++;

    // Calculate aspect ratio and radius-edge ratio for this element.
    tetaspect = 0.0;
    if (!circumsphere(p[0], p[1], p[2], p[3], cent, &cirradius)) {
      // ! Very bad element.
      tetaspect = 1.e+8;  
      tetradius = 100.0;
    } else { 
      inscribedsphere(p[0], p[1], p[2], p[3], cent, &insradius);
    }
    if (tetaspect == 0.0) {
      tetradius = cirradius / sqrt(shortlen);
      tetaspect = sqrt(longlen) / (2.0 * insradius);
      
    }
    aspectindex = 0;
    while ((tetaspect > aspectratiotable[aspectindex]) && (aspectindex < 15)) {
      aspectindex++;
    }
    aspecttable[aspectindex]++;
    radiusindex = 0;
    while ((tetradius > radiusratiotable[radiusindex]) && (radiusindex < 11)) {
      radiusindex++;
    }
    radiustable[radiusindex]++;

    tetloop.tet = tetrahedrontraverse();
  }

  shortest = sqrt(shortest);
  longest = sqrt(longest);
  minaltitude = sqrt(minaltitude);

  printf("  Smallest volume: %16.5g   |  Largest volume: %16.5g\n",
         smallestvolume, biggestvolume);
  printf("  Shortest edge:   %16.5g   |  Longest edge:   %16.5g\n",
         shortest, longest);
  sprintf(sbuf, "%.17g", biggestdiangle);
  if (strlen(sbuf) > 8) {
    sbuf[8] = '\0';
  }
  printf("  Smallest dihedral: %14.5g   |  Largest dihedral:       %s\n\n",
         smallestdiangle, sbuf);

  printf("  Radius-edge ratio histogram:\n");
  printf("         < %-6.6g    :  %8d      | %6.6g - %-6.6g     :  %8d\n",
         radiusratiotable[0], radiustable[0], radiusratiotable[5],
         radiusratiotable[6], radiustable[6]);
  for (i = 1; i < 5; i++) {
    printf("  %6.6g - %-6.6g    :  %8d      | %6.6g - %-6.6g     :  %8d\n",
           radiusratiotable[i - 1], radiusratiotable[i], radiustable[i],
           radiusratiotable[i + 5], radiusratiotable[i + 6],
           radiustable[i + 6]);
  }
  printf("  %6.6g - %-6.6g    :  %8d      | %6.6g -            :  %8d\n",
         radiusratiotable[4], radiusratiotable[5], radiustable[5],
         radiusratiotable[10], radiustable[11]);
  printf("  (A tetrahedron's radius-edge ratio is its radius of ");
  printf("circumsphere divided\n");
  printf("    by its shortest edge length)\n\n");

  printf("  Aspect ratio histogram:\n");
  printf("  1.1547 - %-6.6g    :  %8d      | %6.6g - %-6.6g     :  %8d\n",
         aspectratiotable[0], aspecttable[0], aspectratiotable[7],
         aspectratiotable[8], aspecttable[8]);
  for (i = 1; i < 7; i++) {
    printf("  %6.6g - %-6.6g    :  %8d      | %6.6g - %-6.6g     :  %8d\n",
           aspectratiotable[i - 1], aspectratiotable[i], aspecttable[i],
           aspectratiotable[i + 7], aspectratiotable[i + 8],
           aspecttable[i + 8]);
  }
  printf("  %6.6g - %-6.6g    :  %8d      | %6.6g -            :  %8d\n",
         aspectratiotable[6], aspectratiotable[7], aspecttable[7],
         aspectratiotable[14], aspecttable[15]);
  printf("  (A tetrahedron's aspect ratio is its longest edge length");
  printf(" divided by the\n");
  printf("    diameter of its inscribed sphere)\n\n");

  printf("  Dihedral Angle histogram:\n");
  for (i = 0; i < 9; i++) {
    printf("     %3d - %2d degrees:  %8d      |    %3d - %3d degrees:  %8d\n",
           i * 10, i * 10 + 10, dihedangletable[i],
           i * 10 + 90, i * 10 + 100, dihedangletable[i + 9]);
  }
  printf("\n");
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// statistics()    Print all sorts of cool facts.                            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::statistics()
{
  printf("\nStatistics:\n\n");
  printf("  Input points: %d\n", in->numberofpoints);
  if (b->refine) {
    printf("  Input tetrahedra: %d\n", in->numberoftetrahedra);
  }
  if (b->plc) {
    printf("  Input facets: %d\n", in->numberoffacets);
    printf("  Input holes: %d\n", in->numberofholes);
    printf("  Input regions: %d\n", in->numberofregions);
  }

  printf("\n  Mesh points: %ld\n", points->items);
  printf("  Mesh tetrahedra: %ld\n", tetrahedrons->items);
  if (b->plc || b->refine) {
    printf("  Mesh faces: %ld\n", (4l * tetrahedrons->items + hullsize) / 2l);
  }
  if (b->plc || b->refine) {
    printf("  Mesh subfaces: %ld\n", subfaces->items);
    printf("  Mesh subsegments: %ld\n\n", subsegs->items);
  } else {
    printf("  Convex hull faces: %ld\n\n", hullsize);
  }
  if (b->verbose) {
    // if (b->quality) {
    qualitystatistics();
    // }
    printf("\n");
  }
}

//
// End of user interaction routines
//

//
// Begin of constructor and destructor of tetgenmesh
//

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// ~tetgenmesh()    Deallocte memory occupied by a tetgenmesh object.        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

tetgenmesh::~tetgenmesh()
{
  in = (tetgenio *) NULL;
  b = (tetgenbehavior *) NULL;

  if (tetrahedrons != (memorypool *) NULL) {
    delete tetrahedrons;
  }
  if (subfaces != (memorypool *) NULL) {
    delete subfaces;
  }
  if (subsegs != (memorypool *) NULL) {
    delete subsegs;
  }
  if (points != (memorypool *) NULL) {
    delete points;
  }
  if (dummytetbase != (tetrahedron *) NULL) {
    delete [] dummytetbase;
  }
  if (dummyshbase != (shellface *) NULL) {
    delete [] dummyshbase;
  }
  if (liftpointarray != (REAL *) NULL) {
    delete [] liftpointarray;
  }
  if (highordertable != (point *) NULL) {
    delete [] highordertable;
  }
  if (subpbcgrouptable != (pbcdata *) NULL) {
    delete [] subpbcgrouptable;
  }
  if (segpbcgrouptable != (list *) NULL) {
    delete segpbcgrouptable;
    delete [] idx2segpglist;
    delete [] segpglist;
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// tetgenmesh()    Initialize a tetgenmesh object.                           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

tetgenmesh::tetgenmesh()
{
  in = (tetgenio *) NULL;
  b = (tetgenbehavior *) NULL;

  tetrahedrons = (memorypool *) NULL;
  subfaces = (memorypool *) NULL;
  subsegs = (memorypool *) NULL;
  points = (memorypool *) NULL;
  badsubsegs = (memorypool *) NULL;
  badsubfaces = (memorypool *) NULL;
  badtetrahedrons = (memorypool *) NULL;
  flipstackers = (memorypool *) NULL;

  dummytet = (tetrahedron *) NULL;
  dummytetbase = (tetrahedron *) NULL;
  dummysh = (shellface *) NULL;
  dummyshbase = (shellface *) NULL;

  liftpointarray = (REAL *) NULL;
  highordertable = (point *) NULL;
  subpbcgrouptable = (pbcdata *) NULL;
  segpbcgrouptable = (list *) NULL;
  idx2segpglist = (int *) NULL;
  segpglist = (int *) NULL;

  xmax = xmin = ymax = ymin = zmax = zmin = 0.0; 
  longest = 0.0;
  hullsize = 0l;
  insegment = 0l;
  edgeboundindex = 0;
  pointmarkindex = 0;
  point2simindex = 0;
  point2pbcptindex = 0;
  highorderindex = 0;
  elemattribindex = 0;
  volumeboundindex = 0;
  shmarkindex = 0;
  areaboundindex = 0;
  checksubfaces = 0;
  checkpbcs = 0;
  varconstraint = 0;
  nonconvex = 0;
  dupverts = 0;
  unuverts = 0;
  samples = 0l;
  randomseed = 0l;
  macheps = 0.0;
  maxcavfaces = maxcavverts = 0;
  enlcavtimes = 0;
  flip23s = flip32s = flip22s = flip44s = 0l;
}

//
// End of constructor and destructor of tetgenmesh
//

//
// End of class 'tetgenmesh' implementation.
//

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// tetrahedralize()    The interface for users using TetGen library to       //
//                     generate tetrahedral meshes with all features.        //
//                                                                           //
// The sequence is roughly as follows.  Many of these steps can be skipped,  //
// depending on the command line switches.                                   //
//                                                                           //
// - Initialize constants and parse the command line.                        //
// - Read the vertices from a file and either                                //
//   - tetrahedralize them (no -r), or                                       //
//   - read an old mesh from files and reconstruct it (-r).                  //
// - Insert the PLC segments and facets (-p).                                //
// - Read the holes (-p), regional attributes (-pA), and regional volume     //
//   constraints (-pa).  Carve the holes and concavities, and spread the     //
//   regional attributes and volume constraints.                             //
// - Enforce the constraints on minimum quality bound (-q) and maximum       //
//   volume (-a). Also enforce the conforming Delaunay property (-q and -a). //
// - Promote the mesh's linear tetrahedra to higher order elements (-o).     //
// - Write the output files and print the statistics.                        //
// - Check the consistency and Delaunay property of the mesh (-C).           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include <time.h>           // Defined type clock_t, constant CLOCKS_PER_SEC.

void tetrahedralize(tetgenbehavior *b, tetgenio *in, tetgenio *out)
{
  tetgenmesh m;
  clock_t tv0, tv1, tv2, tv3, tv4, tv5, tv6, tv7, tv8;

  if (!b->quiet) {
    tv0 = clock();
  }
 
  m.b = b;
  m.in = in;

  m.macheps = exactinit();
  m.initializepools();
  m.steinerleft = b->steiner;

  if (!b->quiet) {
    tv1 = clock();
  }

  m.transfernodes();
  if (b->refine) {
    m.reconstructmesh();
  } else {
    m.incrflipdelaunay();
  }

  if (!b->quiet) {
    tv2 = clock();
    if (b->refine) {
      printf("Mesh reconstruction seconds:  %g\n",
             (tv2 - tv1) / (REAL) CLOCKS_PER_SEC);
    } else if (!b->detectinter) {
      printf("Delaunay seconds:  %g\n", (tv2 - tv1) / (REAL) CLOCKS_PER_SEC);
    }
  }

  if (b->useshelles && !b->refine) {
    m.insegment = m.meshsurface();
    if (b->detectinter) {
      m.detectinterfaces();
    } else {
      if (!b->nobisect) {
        m.incrperturbvertices(0.0);
        m.delaunizesegments();
        m.constrainedfacets();
      }
    }
  }

  if (!b->quiet) {
    tv3 = clock();
    if (b->useshelles && !b->refine) {
      if (b->detectinter) {
        printf("Intersection seconds:  %g\n", 
               (tv3 - tv2) / (REAL) CLOCKS_PER_SEC);  
      } else {
        if (!b->nobisect) {
          printf("Segment and facet seconds:  %g\n",
                 (tv3 - tv2) / (REAL) CLOCKS_PER_SEC);
        }
      }
    } 
  }

  if (b->plc && !b->refine && !b->detectinter) {
    m.carveholes();
  }

  if (!b->quiet) {
    tv4 = clock();
    if (b->plc && !b->refine && !b->detectinter) {
      printf("Hole seconds:  %g\n", (tv4 - tv3) / (REAL) CLOCKS_PER_SEC);
    }
  }

  if ((b->plc || b->refine) && !b->detectinter) {
    m.repairdegetets(); 
  }

  if (!b->quiet) {
    tv5 = clock();
    if ((b->plc || b->refine) && !b->detectinter) {
      printf("Repair seconds:  %g\n", (tv5 - tv4) / (REAL) CLOCKS_PER_SEC);
    }
  }

  if (b->insertaddpoints) {
    if (in->numberofaddpoints == 0) {
      in->load_addnodes(b->infilename);
    }
    if (in->numberofaddpoints > 0) {
      m.insertaddpoints(); 
    }
  }

  if (!b->quiet) {
    tv6 = clock();
    if ((b->plc || b->refine) && (in->numberofaddpoints > 0)) {
      printf("Add points seconds:  %g\n", (tv6 - tv5) / (REAL) CLOCKS_PER_SEC);
    }
  }

  if (b->quality && (m.tetrahedrons->items > 0)) {
    m.enforcequality();
  }

  if (!b->quiet) {
    tv7 = clock();
    if (b->quality && (m.tetrahedrons->items > 0)) {
      printf("Quality seconds:  %g\n", (tv7 - tv6) / (REAL) CLOCKS_PER_SEC);
    }
  }

  if ((m.dupverts > 0) || (m.unuverts > 0)) {
    m.jettisonnodes();
  }

  if (b->order > 1) {
    m.highorder();
  }

  if (!b->quiet) {
    printf("\n");
  }

  if (out != (tetgenio *) NULL) {
    out->firstnumber = in->firstnumber;
    out->mesh_dim = in->mesh_dim;
  }

  if (b->nonodewritten || b->noiterationnum) {
    if (!b->quiet) {
      printf("NOT writing a .node file.\n");
    }
  } else {
    if (b->detectinter) {
      if (m.subfaces->items > 0l) {
        // Only output when there are intersecting faces.
        m.outnodes(out);
      }
    } else {
      m.outnodes(out);
    }
  }

  if (b->noelewritten) {
    if (!b->quiet) {
      printf("NOT writing an .ele file.\n");
    }
  } else {
    if (!b->detectinter) {
      if (m.tetrahedrons->items > 0l) {
        m.outelements(out);
      }
    }
  }

  if (b->nofacewritten) {
    if (!b->quiet) {
      printf("NOT writing an .face file.\n");
    }
  } else {
    if (b->facesout) {
      if (m.tetrahedrons->items > 0l) {
        // Output all faces.
        m.outfaces(out);
      }
    } else {
      if (b->detectinter) {
        if (m.subfaces->items > 0l) {
          // Only output when there are intersecting faces.
          m.outsubfaces(out);
        }
      } else if (b->plc || b->refine) {
        if (m.tetrahedrons->items > 0l) {
          // Output boundary faces.
          m.outsubfaces(out); 
        }
      } else {
        if (m.tetrahedrons->items > 0l) {
          // Output convex hull faces.
          m.outhullfaces(out); 
        }
      }
    }
  }

  if (m.checkpbcs) {
    m.outpbcnodes(out);
  }

  if (b->edgesout && b->plc) {
    m.outsubsegments(out); 
  }

  if (!out && b->plc && ((b->object == tetgenbehavior::OFF) ||
                         (b->object == tetgenbehavior::PLY) ||
                         (b->object == tetgenbehavior::STL))) {
    m.outsmesh(b->outfilename);
  }

  if (!out && b->meditview) {
    m.outmesh2medit(b->outfilename); 
  }

  if (!out && b->gidview) {
    m.outmesh2gid(b->outfilename); 
  }

  if (!out && b->geomview) {
    m.outmesh2off(b->outfilename); 
  }

  if (b->neighout) {
    m.outneighbors(out);
  }

  if (!b->quiet) {
    tv8 = clock();
    printf("\nOutput seconds:  %g\n", (tv8 - tv7) / (REAL) CLOCKS_PER_SEC);
    printf("Total running seconds:  %g\n",
           (tv8 - tv0) / (REAL) CLOCKS_PER_SEC);
  }

  if (b->docheck) {
    m.checkmesh();
    if (m.checksubfaces) {
      m.checkshells();
    }
    if (b->docheck > 1) {
      m.checkdelaunay(b->epsilon, NULL);
      if (b->docheck > 2) {
        if (b->quality || b->refine) {
          m.checkconforming();
        }
      }
    }
  }

  if (!b->quiet) {
    m.statistics();
  }
}

#ifndef TETLIBRARY

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// main()    The entrance for running TetGen from command line.              //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])

#else // with TETLIBRARY

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// tetrahedralize()    The entrance for calling TetGen from another program. //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetrahedralize(char *switches, tetgenio *in, tetgenio *out)

#endif // not TETLIBRARY

{
  tetgenbehavior b;

#ifndef TETLIBRARY

  tetgenio in;
  
  if (!b.parse_commandline(argc, argv)) {
    exit(1);
  }
  if (b.refine) {
    if (!in.load_tetmesh(b.infilename)) {
      exit(1);
    }
  } else {
    if (!in.load_plc(b.infilename, (int) b.object)) {
      exit(1);
    }
  }
  tetrahedralize(&b, &in, NULL);

  return 0;

#else // with TETLIBRARY

  if (!b.parse_commandline(switches)) {
    exit(1);
  }
  tetrahedralize(&b, in, out);

#endif // not TETLIBRARY
}
