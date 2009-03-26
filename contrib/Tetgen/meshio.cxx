#ifndef meshioCXX
#define meshioCXX

#include "tetgen.h"

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// transfernodes()    Transfer points from 'in->pointlist' to 'pointpool'.   //
//                                                                           //
// While transfering the points, the size of the bounding box (xmax, ....,   //
// zmin) is caclulated.                                                      //
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
      pointloop[4 + j] = in->pointattributelist[attribindex++];
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
  int oldidx, newidx;
  int remcount;

  if (!b->quiet) {
    printf("Jettisoning redundants points.\n");
  }

  pointpool->traversalinit();
  pointloop = pointtraverse();
  oldidx = newidx = 0; // in->firstnumber;
  remcount = 0;
  while (pointloop != (point) NULL) {
    jetflag = (getpointtype(pointloop) == DUPLICATEDVERTEX) || 
      (getpointtype(pointloop) == UNUSEDVERTEX);
    jetflag = (getpointtype(pointloop) == DUPLICATEDVERTEX);
    if (jetflag) {
      // It is a duplicated point, delete it.
      pointdealloc(pointloop);
      remcount++;
    } else {
      // Re-index it.
      pointmark(pointloop) = newidx + in->firstnumber;
      if (in->pointmarkerlist != (int *) NULL) {
        if (oldidx < in->numberofpoints) {
          // Re-index the point marker as well.
          in->pointmarkerlist[newidx] = in->pointmarkerlist[oldidx];
        }
      }
      newidx++;
    }
    oldidx++;
    if (oldidx == in->numberofpoints) {
      // Update the numbe of input points (Because some were removed).
      in->numberofpoints -= remcount;
      // Remember this number for output original input nodes.
      // jettisoninverts = remcount;
    }
    pointloop = pointtraverse();
  }
  if (b->verbose) {
    printf("  %d duplicated vertices have been removed.\n", dupverts);
    // printf("  %d unused vertices have been removed.\n", unuverts);
  }
  dupverts = 0; 
  // unuverts = 0;

  // The following line ensures that dead items in the pool of nodes cannot
  //   be allocated for the new created nodes. This ensures that the input
  //   nodes will occur earlier in the output files, and have lower indices.
  pointpool->deaditemstack = (void *) NULL;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// numberedges()    Count the number of mesh edges (in 'meshedges').         //
//                                                                           //
// The edges will be automatically counted in routine 'outelements()'.  This //
// routine is needed only -E option is used.                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::numberedges()
{
  triface worktet, spintet;
  int i;

  meshedges = 0l;
  tetrahedronpool->traversalinit();
  worktet.tet = tetrahedrontraverse();
  while (worktet.tet != NULL) {
    // Count the number of Voronoi faces. Look at the six edges of this
    //   tet. Count an edge only if this tet's pointer is smaller than
    //   those of other non-hull tets which share this edge.
    for (i = 0; i < 6; i++) {
      worktet.loc = edge2locver[i][0];
      worktet.ver = edge2locver[i][1];
      fnext(worktet, spintet);
      do {
        if ((point) spintet.tet[7] != dummypoint) {
          if (spintet.tet < worktet.tet) break;
        }
        fnextself(spintet);
      } while (spintet.tet != worktet.tet);
      // Count this edge if no adjacent tets are smaller than this tet.
      if (spintet.tet == worktet.tet) {
        meshedges++;
      }
    }
    worktet.tet = tetrahedrontraverse();
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// numbersubedges()    Count the number of boundary mesh edges (in           //
//                     'meshsubedges').                                      //
//                                                                           //
// The number of boundary edges will be automatically counted in routine     //
// 'outsubfaces()'.  This routine is needed only -F option is used.          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::numbersubedges()
{
  face faceloop, spinsh;
  int i;

  shellface sptr;

  meshsubedges = 0l;
  subfacepool->traversalinit();
  faceloop.sh = shellfacetraverse(subfacepool);
  while (faceloop.sh != NULL) {
    // Count the number of boundary edges. Look at all subfaces sharing at 
    //   this edge. Count it only if this subface's pointer is the smallest.
    faceloop.shver = 0;
    for (i = 0; i < 3; i++) {
      spivot(faceloop, spinsh);
      if (spinsh.sh != NULL) {
        while (spinsh.sh != faceloop.sh) {
          if ((unsigned long) spinsh.sh < (unsigned long) faceloop.sh) break;
          spivotself(spinsh);
        }
        if (spinsh.sh == faceloop.sh) {
          meshsubedges++;
        }
      } else {
        meshsubedges++;
      }
      senextself(faceloop);
    }
    faceloop.sh = shellfacetraverse(subfacepool);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// outnodes()    Output the points to a .node file or a tetgenio structure.  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::outnodes(tetgenio* out)
{
  FILE *outfile;
  char outnodefilename[FILENAMESIZE];
  point pointloop;
  int nextras, bmark, marker;
  int coordindex, attribindex;
  int pointnumber, firstindex;
  int index, i;
  
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
      terminatetetgen(1);
    }
    // Number of pointpool, number of dimensions, number of point attributes,
    //   and number of boundary markers (zero or one).
    fprintf(outfile, "%ld  %d  %d  %d\n", pointpool->items, 3, nextras, bmark);
  } else {
    // Allocate space for 'pointlist';
    out->pointlist = new REAL[pointpool->items * 3];
    if (out->pointlist == (REAL *) NULL) {
      printf("Error:  Out of memory.\n");
      terminatetetgen(1);
    }
    // Allocate space for 'pointattributelist' if necessary;
    if (nextras > 0) {
      out->pointattributelist = new REAL[pointpool->items * nextras];
      if (out->pointattributelist == (REAL *) NULL) {
        printf("Error:  Out of memory.\n");
        terminatetetgen(1);
      }
    }
    // Allocate space for 'pointmarkerlist' if necessary;
    if (bmark) {
      out->pointmarkerlist = new int[pointpool->items];
      if (out->pointmarkerlist == (int *) NULL) {
        printf("Error:  Out of memory.\n");
        terminatetetgen(1);
      }
    }
    out->numberofpoints = pointpool->items;
    out->numberofpointattributes = nextras;
    coordindex = 0;
    attribindex = 0;
  }
  
  // Determine the first index (0 or 1).
  firstindex = b->zeroindex ? 0 : in->firstnumber;

  pointpool->traversalinit();
  pointloop = pointtraverse();
  pointnumber = firstindex; // in->firstnumber;
  index = 0;
  while (pointloop != (point) NULL) {
    if (bmark) {
      // Default the vertex has a zero marker.
      marker = 0;
      // Is it an input vertex?
      if (index < in->numberofpoints) {
        // Input point's marker is directly copied to output.
        marker = in->pointmarkerlist[index];
      }
    }
    if (out == (tetgenio *) NULL) {
      // Point number, x, y and z coordinates.
      fprintf(outfile, "%4d    %.17g  %.17g  %.17g", pointnumber,
              pointloop[0], pointloop[1], pointloop[2]);
      for (i = 0; i < nextras; i++) {
        // Write an attribute.
        fprintf(outfile, "  %.17g", pointloop[4 + i]);
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
        out->pointattributelist[attribindex++] = pointloop[4 + i];
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
// outelements()    Output tetrahedra to an .ele file or a tetgenio object.  //
//                                                                           //
// The total number of mesh edges 'meshedges' (the number of Voronoi faces)  //
// are counted in this function.                                             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::outelements(tetgenio* out)
{
  FILE *outfile;
  char outelefilename[FILENAMESIZE];
  tetrahedron* tptr;
  triface worktet, spintet;
  point p1, p2, p3, p4;
  point *extralist;
  REAL *talist;
  int *tlist;
  long ntets;
  int firstindex, shift;
  int pointindex, attribindex;
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

  // The number of tets excluding hull tets.
  ntets = tetrahedronpool->items - hullsize;

  eextras = in->numberoftetrahedronattributes;
  if (out == (tetgenio *) NULL) {
    outfile = fopen(outelefilename, "w");
    if (outfile == (FILE *) NULL) {
      printf("File I/O Error:  Cannot create file %s.\n", outelefilename);
      terminatetetgen(1);
    }
    // Number of tetras, points per tetra, attributes per tetra.
    fprintf(outfile, "%ld  %d  %d\n", ntets, b->order == 1 ? 4 : 10, eextras);
  } else {
    // Allocate memory for output tetrahedra.
    out->tetrahedronlist = new int[ntets * (b->order == 1 ? 4 : 10)];
    if (out->tetrahedronlist == (int *) NULL) {
      printf("Error:  Out of memory.\n");
      terminatetetgen(1);
    }
    // Allocate memory for output tetrahedron attributes if necessary.
    if (eextras > 0) {
      out->tetrahedronattributelist = new REAL[ntets * eextras];
      if (out->tetrahedronattributelist == (REAL *) NULL) {
        printf("Error:  Out of memory.\n");
        terminatetetgen(1);
      }
    }
    out->numberoftetrahedra = ntets;
    out->numberofcorners = b->order == 1 ? 4 : 10;
    out->numberoftetrahedronattributes = eextras;
    tlist = out->tetrahedronlist;
    talist = out->tetrahedronattributelist;
    pointindex = 0;
    attribindex = 0;
  }

  // Determine the first index (0 or 1).
  firstindex = b->zeroindex ? 0 : in->firstnumber;
  shift = 0; // Default no shiftment.
  if ((in->firstnumber == 1) && (firstindex == 0)) {
    shift = 1; // Shift the output indices by 1.
  }

  // Count the total edge numbers.
  meshedges = 0l;

  tetrahedronpool->traversalinit();
  tptr = tetrahedrontraverse();
  elementnumber = firstindex; // in->firstnumber;
  while (tptr != (tetrahedron *) NULL) {
    // Reverse the orientation so that Orient3D() > 0.
    p1 = (point) tptr[5];
    p2 = (point) tptr[4];
    p3 = (point) tptr[6];
    p4 = (point) tptr[7];
    if (out == (tetgenio *) NULL) {
      // Tetrahedron number, indices for four points.
      fprintf(outfile, "%5d   %5d %5d %5d %5d", elementnumber,
              pointmark(p1) - shift, pointmark(p2) - shift,
              pointmark(p3) - shift, pointmark(p4) - shift);
      if (b->order == 2) {
        extralist = (point *) tptr[highorderindex];
        // Tetrahedron number, indices for four points plus six extra points.
        fprintf(outfile, "  %5d %5d %5d %5d %5d %5d",
          pointmark(extralist[0]) - shift, pointmark(extralist[1]) - shift,
          pointmark(extralist[2]) - shift, pointmark(extralist[3]) - shift,
          pointmark(extralist[4]) - shift, pointmark(extralist[5]) - shift);
      }
      for (i = 0; i < eextras; i++) {
        fprintf(outfile, "    %.17g", elemattribute(tptr, i));
      }
      fprintf(outfile, "\n");
    } else {
      tlist[pointindex++] = pointmark(p1) - shift;
      tlist[pointindex++] = pointmark(p2) - shift;
      tlist[pointindex++] = pointmark(p3) - shift;
      tlist[pointindex++] = pointmark(p4) - shift;
      if (b->order == 2) {
        extralist = (point *) tptr[highorderindex];
        tlist[pointindex++] = pointmark(extralist[0]) - shift;
        tlist[pointindex++] = pointmark(extralist[1]) - shift;
        tlist[pointindex++] = pointmark(extralist[2]) - shift;
        tlist[pointindex++] = pointmark(extralist[3]) - shift;
        tlist[pointindex++] = pointmark(extralist[4]) - shift;
        tlist[pointindex++] = pointmark(extralist[5]) - shift;
      }
      for (i = 0; i < eextras; i++) {
        talist[attribindex++] = elemattribute(tptr, i);
      }
    }
    if (b->neighout) {
      // Remember the index of this element.
      * (int *) (tptr + elemmarkerindex) = elementnumber;
    }
    // Count the number of Voronoi faces. Look at the six edges of this
    //   tet. Count an edge only if this tet's pointer is smaller than
    //   those of other non-hull tets which share this edge.
    worktet.tet = tptr;
    for (i = 0; i < 6; i++) {
      worktet.loc = edge2locver[i][0];
      worktet.ver = edge2locver[i][1];
      fnext(worktet, spintet);
      do {
        if ((point) spintet.tet[7] != dummypoint) {
          if (spintet.tet < worktet.tet) break;
        }
        fnextself(spintet);
      } while (spintet.tet != worktet.tet);
      // Count this edge if no adjacent tets are smaller than this tet.
      if (spintet.tet == worktet.tet) {
        meshedges++;
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
// outfaces()    Output all faces to a .face file or a tetgenio object.      //
//                                                                           //
// The total number of faces f can be calculated as following:  Let t be the //
// total number of tets. Since each tet has 4 faces, the number t * 4 counts //
// each interior face twice and each hull face once. So f = (t * 4 + h) / 2, //
// where h is the total number of hull faces (which is known).               //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::outfaces(tetgenio* out)
{
  FILE *outfile;
  char facefilename[FILENAMESIZE];
  triface tface, tsymface;
  face checkmark;
  point torg, tdest, tapex;
  long ntets, faces;
  int *elist, *emlist;
  int neigh1, neigh2;
  int bmark, faceid, marker;
  int firstindex, shift;
  int facenumber;
  int index;

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

  ntets = tetrahedronpool->items - hullsize;
  faces = (ntets * 4l + hullsize) / 2l;
  bmark = !b->nobound && in->facetmarkerlist;

  if (out == (tetgenio *) NULL) {
    outfile = fopen(facefilename, "w");
    if (outfile == (FILE *) NULL) {
      printf("File I/O Error:  Cannot create file %s.\n", facefilename);
      terminatetetgen(1);
    }
    fprintf(outfile, "%ld  %d\n", faces, bmark);
  } else {
    // Allocate memory for 'trifacelist'.
    out->trifacelist = new int[faces * 3];
    if (out->trifacelist == (int *) NULL) {
      printf("Error:  Out of memory.\n");
      terminatetetgen(1);
    }
    // Allocate memory for 'trifacemarkerlist' if necessary.
    if (bmark) {
      out->trifacemarkerlist = new int[faces];
      if (out->trifacemarkerlist == (int *) NULL) {
        printf("Error:  Out of memory.\n");
        terminatetetgen(1);
      }
    }
    if (b->neighout > 1) {
      // '-nn' switch.
      out->adjtetlist = new int[faces * 2];
      if (out->adjtetlist == (int *) NULL) {
        printf("Error:  Out of memory.\n");
        terminatetetgen(1);
      }
    }
    out->numberoftrifaces = faces;
    elist = out->trifacelist;
    emlist = out->trifacemarkerlist;
    index = 0;
  }

  // Determine the first index (0 or 1).
  firstindex = b->zeroindex ? 0 : in->firstnumber;
  shift = 0; // Default no shiftment.
  if ((in->firstnumber == 1) && (firstindex == 0)) {
    shift = 1; // Shift the output indices by 1.
  }

  tetrahedronpool->traversalinit();
  tface.tet = tetrahedrontraverse();
  facenumber = firstindex; // in->firstnumber;
  // To loop over the set of faces, loop over all tetrahedra, and look at
  //   the four faces of each one. If its adjacent tet is a hull tet,
  //   operate on the face, otherwise, operate on the face only if the
  //   current tet has a smaller pointer than its neighbor.
  while (tface.tet != (tetrahedron *) NULL) {
    for (tface.loc = 0; tface.loc < 4; tface.loc ++) {
      sym(tface, tsymface);
      if (((point) tsymface.tet[7] == dummypoint) || 
          (tface.tet < tsymface.tet)) {
        torg = org(tface);
        tdest = dest(tface);
        tapex = apex(tface);
        if (bmark) {
          // Get the boundary marker of this face. If it is an inner face,
          //   it has no boundary marker, set it be zero.
          if (b->useshelles) {
            // Shell face is used.
            // tspivot(tface, checkmark);
            if (checkmark.sh == NULL) {
              marker = 0;  // It is an inner face.
            } else {
              faceid = getshellmark(checkmark) - 1;
              marker = in->facetmarkerlist[faceid];
            }
          } else {
            // Shell face is not used, only distinguish outer and inner face.
            marker = tsymface.tet != NULL ? 1 : 0;
          }
        }
        if (b->neighout > 1) {
          // '-nn' switch. Output adjacent tets indices.
          neigh1 = * (int *)(tface.tet + elemmarkerindex);
          if (tsymface.tet != NULL) {
            neigh2 = * (int *)(tsymface.tet + elemmarkerindex);
          } else {
            neigh2 = -1;  
          }
        }
        if (out == (tetgenio *) NULL) {
          // Face number, indices of three vertices.
          fprintf(outfile, "%5d   %4d  %4d  %4d", facenumber,
                  pointmark(torg) - shift, pointmark(tdest) - shift,
                  pointmark(tapex) - shift);
          if (bmark) {
            // Output a boundary marker.
            fprintf(outfile, "  %d", marker);
          }
          if (b->neighout > 1) {
            fprintf(outfile, "    %5d  %5d", neigh1, neigh2);
          }
          fprintf(outfile, "\n");
        } else {
          // Output indices of three vertices.
          elist[index++] = pointmark(torg) - shift;
          elist[index++] = pointmark(tdest) - shift;
          elist[index++] = pointmark(tapex) - shift;
          if (bmark) {
            emlist[facenumber - in->firstnumber] = marker;
          }
          if (b->neighout > 1) {
            out->adjtetlist[(facenumber - in->firstnumber) * 2]     = neigh1;
            out->adjtetlist[(facenumber - in->firstnumber) * 2 + 1] = neigh2;
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
// outhullfaces()    Output hull faces to a .face file or a tetgenio object. //
//                                                                           //
// The normal of each face is pointing to the outside of the domain.         //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::outhullfaces(tetgenio* out)
{
  FILE *outfile;
  char facefilename[FILENAMESIZE];
  triface hulltet;
  point torg, tdest, tapex;
  int *elist;
  int firstindex, shift;
  int facenumber;
  int index;

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
      terminatetetgen(1);
    }
    fprintf(outfile, "%ld  0\n", hullsize);
  } else {
    // Allocate memory for 'trifacelist'.
    out->trifacelist = new int[hullsize * 3];
    if (out->trifacelist == (int *) NULL) {
      printf("Error:  Out of memory.\n");
      terminatetetgen(1);
    }
    out->numberoftrifaces = hullsize;
    elist = out->trifacelist;
    index = 0;
  }

  // Determine the first index (0 or 1).
  firstindex = b->zeroindex ? 0 : in->firstnumber;
  shift = 0; // Default no shiftment.
  if ((in->firstnumber == 1) && (firstindex == 0)) {
    shift = 1; // Shift the output indices by 1.
  }

  tetrahedronpool->traversalinit();
  hulltet.tet = alltetrahedrontraverse();
  facenumber = firstindex;
  while (hulltet.tet != (tetrahedron *) NULL) {
    if ((point) hulltet.tet[7] == dummypoint) {
      torg = (point) hulltet.tet[4];
      tdest = (point) hulltet.tet[5];
      tapex = (point) hulltet.tet[6];
      if (out == (tetgenio *) NULL) {
        // Face number, indices of three vertices.
        fprintf(outfile, "%5d   %4d  %4d  %4d", facenumber,
          pointmark(torg) - shift, pointmark(tdest) - shift,
          pointmark(tapex) - shift);
        fprintf(outfile, "\n");
      } else {
        // Output indices of three vertices.
        elist[index++] = pointmark(torg) - shift;
        elist[index++] = pointmark(tdest) - shift;
        elist[index++] = pointmark(tapex) - shift;
      }
      facenumber++;
    }
    hulltet.tet = alltetrahedrontraverse();
  }
  
  if (out == (tetgenio *) NULL) {
    fprintf(outfile, "# Generated by %s\n", b->commandline);
    fclose(outfile);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// outsubfaces()    Output subfaces to a .face file or a tetgenio object.    //
//                                                                           //
// The number of mesh boundary edges ('meshsubedges') will be counted.       //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::outsubfaces(tetgenio* out)
{
  FILE *outfile;
  char facefilename[FILENAMESIZE];
  int *elist;
  int *emlist;
  int index, index1=0, index2=0;
  triface abuttingtet;
  face faceloop, spinsh;
  point torg, tdest, tapex;
  int bmark, faceid, marker;
  int firstindex, shift;
  int neigh1, neigh2;
  int facenumber, i;

  shellface sptr;

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
      terminatetetgen(1);
    }
    // Number of subfaces.
    fprintf(outfile, "%ld  %d\n", subfacepool->items, bmark);
  } else {
    // Allocate memory for 'trifacelist'.
    out->trifacelist = new int[subfacepool->items * 3];
    if (out->trifacelist == (int *) NULL) {
      printf("Error:  Out of memory.\n");
      terminatetetgen(1);
    }
    if (bmark) {
      // Allocate memory for 'trifacemarkerlist'.
      out->trifacemarkerlist = new int[subfacepool->items];
      if (out->trifacemarkerlist == (int *) NULL) {
        printf("Error:  Out of memory.\n");
        terminatetetgen(1);
      }
    }
    if (b->neighout > 1) {
      // '-nn' switch.
      out->adjtetlist = new int[subfacepool->items * 2];
      if (out->adjtetlist == (int *) NULL) {
        printf("Error:  Out of memory.\n");
        terminatetetgen(1);
      }
    }
    out->numberoftrifaces = subfacepool->items;
    elist = out->trifacelist;
    emlist = out->trifacemarkerlist;
  }

  // Determine the first index (0 or 1).
  firstindex = b->zeroindex ? 0 : in->firstnumber;
  shift = 0; // Default no shiftment.
  if ((in->firstnumber == 1) && (firstindex == 0)) {
    shift = 1; // Shift the output indices by 1.
  }

  meshsubedges = 0l;

  subfacepool->traversalinit();
  faceloop.sh = shellfacetraverse(subfacepool);
  facenumber = firstindex; // in->firstnumber;
  while (faceloop.sh != (shellface *) NULL) {
    abuttingtet.tet = NULL; // stpivot(faceloop, abuttingtet);
    if (abuttingtet.tet != NULL) {
      // There is a tetrahedron containing this subface, orient it.
      abuttingtet.ver = 0;
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
      faceid = getshellmark(faceloop) - 1;
      marker = in->facetmarkerlist[faceid];
    }
    if (b->neighout > 1) {
      // '-nn' switch. Output adjacent tets indices.
      neigh1 = -1;
      // stpivot(faceloop, abuttingtet);
      if (abuttingtet.tet != NULL) {
        neigh1 = * (int *)(abuttingtet.tet + elemmarkerindex);
      }
      neigh2 = -1;
      sesymself(faceloop);
      // stpivot(faceloop, abuttingtet);
      if (abuttingtet.tet != NULL) {
        neigh2 = * (int *)(abuttingtet.tet + elemmarkerindex);
      }
    }
    if (out == (tetgenio *) NULL) {
      fprintf(outfile, "%5d   %4d  %4d  %4d", facenumber,
              pointmark(torg) - shift, pointmark(tdest) - shift,
              pointmark(tapex) - shift);
      if (bmark) {
        fprintf(outfile, "    %d", marker);
      }
      if (b->neighout > 1) {
        fprintf(outfile, "    %5d  %5d", neigh1, neigh2);
      }
      fprintf(outfile, "\n");
    } else {
      // Output three vertices of this face;
      elist[index++] = pointmark(torg) - shift;
      elist[index++] = pointmark(tdest) - shift;
      elist[index++] = pointmark(tapex) - shift;
      if (bmark) {
        emlist[index1++] = marker;
      }
      if (b->neighout > 1) {
        out->adjtetlist[index2++] = neigh1;
        out->adjtetlist[index2++] = neigh2;
      }
    }
    // Count the number of boundary edges. Look at all subfaces sharing at 
    //   this edge. Count it only if this subface's pointer is the smallest.
    faceloop.shver = 0;
    for (i = 0; i < 3; i++) {
      spivot(faceloop, spinsh);
      if (spinsh.sh != NULL) {
        while (spinsh.sh != faceloop.sh) {
          if ((unsigned long) spinsh.sh < (unsigned long) faceloop.sh) break;
          spivotself(spinsh);
        }
        if (spinsh.sh == faceloop.sh) {
          meshsubedges++;
        }
      } else {
        meshsubedges++;
      }
      senextself(faceloop);
    }
    facenumber++;
    faceloop.sh = shellfacetraverse(subfacepool);
  }

  if (out == (tetgenio *) NULL) {
    fprintf(outfile, "# Generated by %s\n", b->commandline);
    fclose(outfile);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// outedges()    Output all edges to a .edge file or a tetgenio object.      //
//                                                                           //
// Note: This routine must be called after outelements(),  so that the total //
// number of edges 'meshedges' has been counted.                             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::outedges(tetgenio* out)
{
  FILE *outfile;
  char edgefilename[FILENAMESIZE];
  triface tetloop, worktet, spintet;
  point torg, tdest;
  int *elist, *emlist;
  int firstindex, shift;
  int edgenumber;
  int index;
  int i;

  if (out == (tetgenio *) NULL) {
    strcpy(edgefilename, b->outfilename);
    strcat(edgefilename, ".edge");
  }

  if (!b->quiet) {
    if (out == (tetgenio *) NULL) {
      printf("Writing %s.\n", edgefilename);
    } else {
      printf("Writing edges.\n");
    }
  }

  if (out == (tetgenio *) NULL) {
    outfile = fopen(edgefilename, "w");
    if (outfile == (FILE *) NULL) {
      printf("File I/O Error:  Cannot create file %s.\n", edgefilename);
      terminatetetgen(1);
    }
    // Write the number of edges, boundary markers (0 or 1).
    fprintf(outfile, "%ld  %d\n", meshedges, !b->nobound);
  } else {
    // Allocate memory for 'edgelist'.
    out->edgelist = new int[meshedges * 2];
    if (out->edgelist == (int *) NULL) {
      printf("Error:  Out of memory.\n");
      terminatetetgen(1);
    }
    if (!b->nobound) {
      out->edgemarkerlist = new int[meshedges];
    }
    out->numberofedges = meshedges;
    elist = out->edgelist;
    emlist = out->edgemarkerlist;
    index = 0;
  }

  // Determine the first index (0 or 1).
  firstindex = b->zeroindex ? 0 : in->firstnumber;
  shift = 0; // Default no shiftment.
  if ((in->firstnumber == 1) && (firstindex == 0)) {
    shift = 1; // Shift (reduce) the output indices by 1.
  }

  tetrahedronpool->traversalinit();
  tetloop.tet = tetrahedrontraverse();
  edgenumber = firstindex; // in->firstnumber;
  while (tetloop.tet != (tetrahedron *) NULL) {
    // Count the number of Voronoi faces. Look at the six edges of this
    //   tet. Count an edge only if this tet's pointer is smaller than
    //   those of other non-hull tets which share this edge.
    worktet.tet = tetloop.tet;
    for (i = 0; i < 6; i++) {
      worktet.loc = edge2locver[i][0];
      worktet.ver = edge2locver[i][1];
      fnext(worktet, spintet);
      do {
        if ((point) spintet.tet[7] != dummypoint) {
          if (spintet.tet < worktet.tet) break;
        }
        fnextself(spintet);
      } while (spintet.tet != worktet.tet);
      // Count this edge if no adjacent tets are smaller than this tet.
      if (spintet.tet == worktet.tet) {
        torg = org(worktet);
        tdest = dest(worktet);
        if (out == (tetgenio *) NULL) {
          fprintf(outfile, "%5d   %4d  %4d", edgenumber,
                  pointmark(torg) - shift, pointmark(tdest) - shift);
        } else {
          // Output three vertices of this face;
          elist[index++] = pointmark(torg) - shift;
          elist[index++] = pointmark(tdest) - shift;
        }
        /*
        if (!b->nobound) {
          // Check if the edge is a segment.
          tsspivot(&worktet, &checkseg);
          if (checkseg.sh != dummysh) {
            marker = shellmark(checkseg);
            if (marker == 0) {  // Does it have no marker?
              marker = 1;  // Set the default marker for this segment.
            }
          } else {
            marker = 0;  // It's not a segment.
          }
          if (out == (tetgenio *) NULL) {
            fprintf(outfile, "  %d", marker);
          } else {
            emlist[index1++] = marker;
          }
        }
        */
        if (out == (tetgenio *) NULL) {
          fprintf(outfile, "\n");
        }
        edgenumber++;
      }
    }
    tetloop.tet = tetrahedrontraverse();
  }

  if (out == (tetgenio *) NULL) {
    fprintf(outfile, "# Generated by %s\n", b->commandline);
    fclose(outfile);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// outsubsegments()    Output subsegments into an .edge file or an object.   //
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
  int firstindex, shift;
  int edgenumber;

  if (out == (tetgenio *) NULL) {
    strcpy(edgefilename, b->outfilename);
    strcat(edgefilename, ".edge");
  }

  if (!b->quiet) {
    if (out == (tetgenio *) NULL) {
      printf("Writing %s.\n", edgefilename);
    } else {
      printf("Writing edges.\n");
    }
  }

  // Avoid compile warnings.
  outfile = (FILE *) NULL;
  elist = (int *) NULL;
  index = 0;  

  if (out == (tetgenio *) NULL) {
    outfile = fopen(edgefilename, "w");
    if (outfile == (FILE *) NULL) {
      printf("File I/O Error:  Cannot create file %s.\n", edgefilename);
      terminatetetgen(1);
    }
    // Number of subsegments.
    fprintf(outfile, "%ld\n", subsegpool->items);
  } else {
    // Allocate memory for 'edgelist'.
    out->edgelist = new int[subsegpool->items * 2];
    if (out->edgelist == (int *) NULL) {
      printf("Error:  Out of memory.\n");
      terminatetetgen(1);
    }
    out->numberofedges = subsegpool->items;
    elist = out->edgelist;
  }

  // Determine the first index (0 or 1).
  firstindex = b->zeroindex ? 0 : in->firstnumber;
  shift = 0; // Default no shiftment.
  if ((in->firstnumber == 1) && (firstindex == 0)) {
    shift = 1; // Shift the output indices by 1.
  }

  subsegpool->traversalinit();
  edgeloop.sh = shellfacetraverse(subsegpool);
  edgenumber = firstindex; // in->firstnumber;
  while (edgeloop.sh != (shellface *) NULL) {
    torg = sorg(edgeloop);
    tdest = sdest(edgeloop);
    if (out == (tetgenio *) NULL) {
      fprintf(outfile, "%5d   %4d  %4d\n", edgenumber,
              pointmark(torg) - shift, pointmark(tdest) - shift);
    } else {
      // Output three vertices of this face;
      elist[index++] = pointmark(torg) - shift;
      elist[index++] = pointmark(tdest) - shift;
    }
    edgenumber++;
    edgeloop.sh = shellfacetraverse(subsegpool);
  }

  if (out == (tetgenio *) NULL) {
    fprintf(outfile, "# Generated by %s\n", b->commandline);
    fclose(outfile);
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// outneighbors()    Output tet neighbors to a .neigh file or an object.     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::outneighbors(tetgenio* out)
{
  FILE *outfile;
  char neighborfilename[FILENAMESIZE];
  int *nlist;
  int index;
  triface tetloop, tetsym;
  int neighbor1, neighbor2, neighbor3, neighbor4;
  int firstindex;
  int elementnumber;
  long ntets;

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

  ntets = tetrahedronpool->items - hullsize;

  if (out == (tetgenio *) NULL) {
    outfile = fopen(neighborfilename, "w");
    if (outfile == (FILE *) NULL) {
      printf("File I/O Error:  Cannot create file %s.\n", neighborfilename);
      terminatetetgen(1);
    }
    // Number of tetrahedra, four faces per tetrahedron.
    fprintf(outfile, "%ld  %d\n", ntets, 4);
  } else {
    // Allocate memory for 'neighborlist'.
    out->neighborlist = new int[ntets * 4];
    if (out->neighborlist == (int *) NULL) {
      printf("Error:  Out of memory.\n");
      terminatetetgen(1);
    }
    nlist = out->neighborlist;
  }

  // Determine the first index (0 or 1).
  firstindex = b->zeroindex ? 0 : in->firstnumber;

  tetrahedronpool->traversalinit();
  tetloop.tet = tetrahedrontraverse();
  elementnumber = firstindex; // in->firstnumber;
  while (tetloop.tet != (tetrahedron *) NULL) {
    tetloop.loc = 2;
    sym(tetloop, tetsym);
    if ((point) tetsym.tet[7] != dummypoint) {
      neighbor1 = * (int *) (tetsym.tet + elemmarkerindex);
    } else {
      neighbor1 = -1;
    }
    tetloop.loc = 3;
    sym(tetloop, tetsym);
    if ((point) tetsym.tet[7] != dummypoint) {
      neighbor2 = * (int *) (tetsym.tet + elemmarkerindex);
    } else {
      neighbor1 = -1;
    }
    tetloop.loc = 1;
    sym(tetloop, tetsym);
    if ((point) tetsym.tet[7] != dummypoint) {
      neighbor3 = * (int *) (tetsym.tet + elemmarkerindex);
    } else {
      neighbor1 = -1;
    }
    tetloop.loc = 0;
    sym(tetloop, tetsym);
    if ((point) tetsym.tet[7] != dummypoint) {
      neighbor4 = * (int *) (tetsym.tet + elemmarkerindex);
    } else {
      neighbor1 = -1;
    }
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

#endif // #ifndef meshioCXX
