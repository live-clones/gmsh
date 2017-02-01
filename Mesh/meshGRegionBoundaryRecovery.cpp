// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "GmshConfig.h"
#include "meshGRegionBoundaryRecovery.h"
#include "meshGRegionDelaunayInsertion.h"
#include "robustPredicates.h"
#include "GRegion.h"
#include "GFace.h"
#include "MVertex.h"
#include "MLine.h"
#include "MPoint.h"
#include "MTriangle.h"
#include "MTetrahedron.h"
#include "Context.h"
#include "OS.h"
#if !defined(HAVE_NO_STDINT_H)
#include <stdint.h>
#elif defined(HAVE_NO_INTPTR_T)
typedef unsigned long intptr_t;
#endif

namespace tetgenBR
{

#define REAL double

// dummy tetgenio class
class tetgenio{
public:
  int firstnumber;
  int numberofpointattributes;
  int numberoftetrahedronattributes;
  int numberofsegmentconstraints;
  REAL *segmentconstraintlist;
  int numberoffacetconstraints;
  REAL *facetconstraintlist;
  int numberofpoints;
  int *pointlist;
  int *pointattributelist;
  int numberofpointmakers;
  int *pointmarkerlist;
  int numberofpointmtrs;
  int *pointmtrlist;
  int numberofedges;
  int *edgelist;
  int *edgemarkerlist;
  int numberofholes;
  REAL *holelist;
  int numberofregions;
  REAL *regionlist;
  int mesh_dim;
  tetgenio()
  {
    firstnumber = 0;
    numberofpointattributes = 0;
    numberoftetrahedronattributes = 0;
    numberofsegmentconstraints = 0;
    segmentconstraintlist = 0;
    numberoffacetconstraints = 0;
    facetconstraintlist = 0;
    numberofpoints = 0;
    pointlist = 0;
    pointattributelist = 0;
    numberofpointmakers = 0;
    pointmarkerlist = 0;
    numberofpointmtrs = 0;
    pointmtrlist = 0;
    numberofedges = 0;
    edgelist = 0;
    edgemarkerlist = 0;
    numberofholes = 0;
    holelist = 0;
    numberofregions = 0;
    regionlist = 0;
    mesh_dim = 0;
  }
};

// redefinition of predicates using our own
#define orient3d robustPredicates::orient3d
#define insphere robustPredicates::insphere
static double orient4d(double*, double *, double *, double *, double *,
                       double, double, double, double, double){ return 0.; }
static int clock(){ return 0; }
#define clock_t int
#if !defined(TETLIBRARY)
#define TETLIBRARY
#endif
#include "tetgenBR.h"
#include "tetgenBR.cxx"

bool tetgenmesh::reconstructmesh(void *p)
{
  GRegion *_gr = (GRegion*)p;

  in = new tetgenio();
  b = new tetgenbehavior();
  char opts[128];
  sprintf(opts, "YpeQT%g", CTX::instance()->mesh.toleranceInitialDelaunay);
  b->parse_commandline(opts);

  double t_start = Cpu();
  std::vector<MVertex*> _vertices;

  // Get the set of vertices from GRegion.
  {
    std::set<MVertex*, MVertexLessThanNum> all;
    std::list<GFace*> f = _gr->faces();
    for (std::list<GFace*>::iterator it = f.begin(); it != f.end(); ++it) {
      GFace *gf = *it;
      for (unsigned int i = 0; i < gf->triangles.size(); i++){
        all.insert(gf->triangles[i]->getVertex(0));
        all.insert(gf->triangles[i]->getVertex(1));
        all.insert(gf->triangles[i]->getVertex(2));
      }
    }
    std::list<GEdge*> e = _gr->embeddedEdges();
    for (std::list<GEdge*>::iterator it = e.begin(); it != e.end(); ++it) {
      GEdge *ge = *it;
      for (unsigned int i = 0; i < ge->lines.size(); i++){
        all.insert(ge->lines[i]->getVertex(0));
        all.insert(ge->lines[i]->getVertex(1));
      }
    }
    std::list<GVertex*> v = _gr->embeddedVertices();
    for (std::list<GVertex*>::iterator it = v.begin(); it != v.end(); ++it) {
      GVertex *gv = *it;
      for (unsigned int i = 0; i < gv->points.size(); i++){
        all.insert(gv->points[i]->getVertex(0));
      }
    }
    all.insert(_gr->mesh_vertices.begin(), _gr->mesh_vertices.end());

    _vertices.insert(_vertices.begin(), all.begin(), all.end());
  }

  initializepools();

  std::vector<MTetrahedron*> tets;

  delaunayMeshIn3D(_vertices, tets, false);

  Msg::Debug("Points have been tetrahedralized");

  {
    point pointloop;
    REAL x, y, z;

    // Read the points.
    for (unsigned int i = 0; i < _vertices.size(); i++) {
      makepoint(&pointloop, UNUSEDVERTEX);
      // Read the point coordinates.
      x = pointloop[0] = _vertices[i]->x();
      y = pointloop[1] = _vertices[i]->y();
      z = pointloop[2] = _vertices[i]->z();
      // Determine the smallest and largest x, y and z coordinates.
      if (i == 0) {
	xmin = xmax = x;
	ymin = ymax = y;
	zmin = zmax = z;
      }
      else {
	xmin = (x < xmin) ? x : xmin;
	xmax = (x > xmax) ? x : xmax;
	ymin = (y < ymin) ? y : ymin;
	ymax = (y > ymax) ? y : ymax;
	zmin = (z < zmin) ? z : zmin;
	zmax = (z > zmax) ? z : zmax;
      }
    }

    // 'longest' is the largest possible edge length formed by input vertices.
    x = xmax - xmin;
    y = ymax - ymin;
    z = zmax - zmin;
    longest = sqrt(x * x + y * y + z * z);
    if (longest == 0.0) {
      Msg::Warning("The point set is trivial");
      return true;
    }

    // Two identical points are distinguished by 'lengthlimit'.
    if (minedgelength == 0.0) {
      minedgelength = longest * b->epsilon;
    }
  }

  point *idx2verlist;

  // Create a map from indices to vertices.
  makeindex2pointmap(idx2verlist);
  // 'idx2verlist' has length 'in->numberofpoints + 1'.
  if (in->firstnumber == 1) {
    idx2verlist[0] = dummypoint; // Let 0th-entry be dummypoint.
  }

  {
    // Index the vertices.
    for (unsigned int i = 0; i < _vertices.size(); i++){
      _vertices[i]->setIndex(i);
    }

    tetrahedron *ver2tetarray;
    //point *idx2verlist;
    triface tetloop, checktet, prevchktet;
    triface hulltet, face1, face2;
    tetrahedron tptr;
    point p[4], q[3];
    REAL ori; //, attrib, volume;
    int bondflag;
    int t1ver;
    int idx, k;

    Msg::Info("Reconstructing mesh ...");

    // Allocate an array that maps each vertex to its adjacent tets.
    ver2tetarray = new tetrahedron[_vertices.size() + 1];
    //for (i = 0; i < in->numberofpoints + 1; i++) {
    for (unsigned int i = in->firstnumber; i < _vertices.size() + in->firstnumber; i++) {
      setpointtype(idx2verlist[i], VOLVERTEX); // initial type.
      ver2tetarray[i] = NULL;
    }

    // Create the tetrahedra and connect those that share a common face.
    for (unsigned int i = 0; i < tets.size(); i++) {
      // Get the four vertices.
      for (int j = 0; j < 4; j++) {
	p[j] = idx2verlist[tets[i]->getVertex(j)->getIndex()];
      }
      // Check the orientation.
      ori = orient3d(p[0], p[1], p[2], p[3]);
      if (ori > 0.0) {
	// Swap the first two vertices.
	q[0] = p[0]; p[0] = p[1]; p[1] = q[0];
      }
      else if (ori == 0.0) {
	if (!b->quiet) {
	  printf("Warning:  Tet #%d is degenerate.\n", i + in->firstnumber);
	}
      }
      // Create a new tetrahedron.
      maketetrahedron(&tetloop); // tetloop.ver = 11.
      setvertices(tetloop, p[0], p[1], p[2], p[3]);
      // Try connecting this tet to others that share the common faces.
      for (tetloop.ver = 0; tetloop.ver < 4; tetloop.ver++) {
	p[3] = oppo(tetloop);
	// Look for other tets having this vertex.
	idx = pointmark(p[3]);
	tptr = ver2tetarray[idx];
	// Link the current tet to the next one in the stack.
	tetloop.tet[8 + tetloop.ver] = tptr;
	// Push the current tet onto the stack.
	ver2tetarray[idx] = encode(tetloop);
	decode(tptr, checktet);
	if (checktet.tet != NULL) {
	  p[0] =  org(tetloop); // a
	  p[1] = dest(tetloop); // b
	  p[2] = apex(tetloop); // c
	  prevchktet = tetloop;
	  do {
	    q[0] =  org(checktet); // a'
	    q[1] = dest(checktet); // b'
	    q[2] = apex(checktet); // c'
	    // Check the three faces at 'd' in 'checktet'.
	    bondflag = 0;
	    for (int j = 0; j < 3; j++) {
	      // Go to the face [b',a',d], or [c',b',d], or [a',c',d].
	      esym(checktet, face2);
	      if (face2.tet[face2.ver & 3] == NULL) {
		k = ((j + 1) % 3);
		if (q[k] == p[0]) {   // b', c', a' = a
		  if (q[j] == p[1]) { // a', b', c' = b
		    // [#,#,d] is matched to [b,a,d].
		    esym(tetloop, face1);
		    bond(face1, face2);
		    bondflag++;
		  }
		}
		if (q[k] == p[1]) {   // b',c',a' = b
		  if (q[j] == p[2]) { // a',b',c' = c
		    // [#,#,d] is matched to [c,b,d].
		    enext(tetloop, face1);
		    esymself(face1);
		    bond(face1, face2);
		    bondflag++;
		  }
		}
		if (q[k] == p[2]) {   // b',c',a' = c
		  if (q[j] == p[0]) { // a',b',c' = a
		    // [#,#,d] is matched to [a,c,d].
		    eprev(tetloop, face1);
		    esymself(face1);
		    bond(face1, face2);
		    bondflag++;
		  }
		}
	      }
              else {
		bondflag++;
	      }
	      enextself(checktet);
	    } // j
	    // Go to the next tet in the link.
	    tptr = checktet.tet[8 + checktet.ver];
	    if (bondflag == 3) {
	      // All three faces at d in 'checktet' have been connected.
	      // It can be removed from the link.
	      prevchktet.tet[8 + prevchktet.ver] = tptr;
	    }
            else {
	      // Bakup the previous tet in the link.
	      prevchktet = checktet;
	    }
	    decode(tptr, checktet);
	  } while (checktet.tet != NULL);
	} // if (checktet.tet != NULL)
      } // for (tetloop.ver = 0; ...
    } // i

    // Remember a tet of the mesh.
    recenttet = tetloop;

    // Create hull tets, create the point-to-tet map, and clean up the
    //   temporary spaces used in each tet.
    hullsize = tetrahedrons->items;

    tetrahedrons->traversalinit();
    tetloop.tet = tetrahedrontraverse();
    while (tetloop.tet != (tetrahedron *) NULL) {
      tptr = encode(tetloop);
      for (tetloop.ver = 0; tetloop.ver < 4; tetloop.ver++) {
	if (tetloop.tet[tetloop.ver] == NULL) {
	  // Create a hull tet.
	  maketetrahedron(&hulltet);
	  p[0] =  org(tetloop);
	  p[1] = dest(tetloop);
	  p[2] = apex(tetloop);
	  setvertices(hulltet, p[1], p[0], p[2], dummypoint);
	  bond(tetloop, hulltet);
	  // Try connecting this to others that share common hull edges.
	  for (int j = 0; j < 3; j++) {
	    fsym(hulltet, face2);
	    while (1) {
	      if (face2.tet == NULL) break;
	      esymself(face2);
	      if (apex(face2) == dummypoint) break;
	      fsymself(face2);
	    }
	    if (face2.tet != NULL) {
	      // Found an adjacent hull tet.
	      assert(face2.tet[face2.ver & 3] == NULL);
	      esym(hulltet, face1);
	      bond(face1, face2);
	    }
	    enextself(hulltet);
	  }
	  //hullsize++;
	}
	// Create the point-to-tet map.
	setpoint2tet((point) (tetloop.tet[4 + tetloop.ver]), tptr);
	// Clean the temporary used space.
	tetloop.tet[8 + tetloop.ver] = NULL;
      }
      tetloop.tet = tetrahedrontraverse();
    }

    hullsize = tetrahedrons->items - hullsize;

    delete [] ver2tetarray;
    tets.clear(); // Release all memory in this vector.
  }

  std::list<GFace*> f_list = _gr->faces();
  std::list<GEdge*> e_list = _gr->embeddedEdges();

  {
    Msg::Info("Creating surface mesh...");
    face newsh;
    face newseg;
    point p[4];
    int idx;

    for (std::list<GFace*>::iterator it = f_list.begin(); it != f_list.end(); ++it){
      GFace *gf = *it;
      for (unsigned int i = 0; i < gf->triangles.size(); i++) {
	for (int j = 0; j < 3; j++) {
	  p[j] = idx2verlist[gf->triangles[i]->getVertex(j)->getIndex()];
	  if (pointtype(p[j]) == VOLVERTEX) {
	    setpointtype(p[j], FACETVERTEX);
	  }
	}
	// Create an initial triangulation.
	makeshellface(subfaces, &newsh);
	setshvertices(newsh, p[0], p[1], p[2]);
	setshellmark(newsh, gf->tag()); // the GFace's tag.
	recentsh = newsh;
	for (int j = 0; j < 3; j++) {
	  makeshellface(subsegs, &newseg);
	  setshvertices(newseg, sorg(newsh), sdest(newsh), NULL);
	  // Set the default segment marker '-1'.
	  setshellmark(newseg, -1);
	  ssbond(newsh, newseg);
	  senextself(newsh);
	}
      } // i
    } // it

    // Connecting triangles, removing redundant segments.
    unifysegments();

    Msg::Info("Identifying boundary edges...");

    face* shperverlist;
    int* idx2shlist;
    face searchsh, neighsh;
    face segloop, checkseg;
    point checkpt;

    // Construct a map from points to subfaces.
    makepoint2submap(subfaces, idx2shlist, shperverlist);

    //    printf("coucou1\n");
    
    // Process the set of PSC edges.
    // Remeber that all segments have default marker '-1'.
    //    int COUNTER = 0;
    for (std::list<GEdge*>::iterator it = e_list.begin(); it != e_list.end();
	 ++it) {
      GEdge *ge = *it;
      for (unsigned int i = 0; i < ge->lines.size(); i++) {
	for (int j = 0; j < 2; j++) {
	  p[j] = idx2verlist[ge->lines[i]->getVertex(j)->getIndex()];
	  setpointtype(p[j], RIDGEVERTEX);
        }
	if (p[0] == p[1]) {
	  // This is a potential problem in surface mesh.
	  continue; // Skip this edge.
	}
	// Find a face contains the edge p[0], p[1].
	newseg.sh = NULL;
	searchsh.sh = NULL;
	idx = pointmark(p[0]) - in->firstnumber;
	for (int j = idx2shlist[idx]; j < idx2shlist[idx + 1]; j++) {
	  checkpt = sdest(shperverlist[j]);
	  if (checkpt == p[1]) {
	    searchsh = shperverlist[j];
	    break; // Found.
	  }
          else {
	    checkpt = sapex(shperverlist[j]);
	    if (checkpt == p[1]) {
	      senext2(shperverlist[j], searchsh);
	      sesymself(searchsh);
	      break;
	    }
	  }
	} // j
	if (searchsh.sh != NULL) {
	  // Check if this edge is already a segment of the mesh.
	  sspivot(searchsh, checkseg);
          if (checkseg.sh != NULL) {
            // This segment already exist.
            newseg = checkseg;
          }
          else {
            // Create a new segment at this edge.
            makeshellface(subsegs, &newseg);
            setshvertices(newseg, p[0], p[1], NULL);
            ssbond(searchsh, newseg);
            spivot(searchsh, neighsh);
            if (neighsh.sh != NULL) {
              ssbond(neighsh, newseg);
            }
          }
	}
        else {
	  // It is a dangling segment (not belong to any facets).
	  // Check if segment [p[0],p[1]] already exists.
	  // TODO: Change the brute-force search. Slow!
	  /*	  point *ppt;
	  subsegs->traversalinit();
	  segloop.sh = shellfacetraverse(subsegs);
	  while (segloop.sh != NULL) {
	    ppt = (point *) &(segloop.sh[3]);
	    if (((ppt[0] == p[0]) && (ppt[1] == p[1])) ||
		((ppt[0] == p[1]) && (ppt[1] == p[0]))) {
	      // Found!
	      newseg = segloop;
	      break;
	    }
	    segloop.sh = shellfacetraverse(subsegs);
	    }*/
	  if (newseg.sh == NULL) {
	    makeshellface(subsegs, &newseg);
	    setshvertices(newseg, p[0], p[1], NULL);
	  }
	}
	setshellmark(newseg, ge->tag());
      } // i
    } // e_list

    delete [] shperverlist;
    delete [] idx2shlist;

    Msg::Debug("  %ld (%ld) subfaces (segments).", subfaces->items,
               subsegs->items);

    // The total number of iunput segments.
    insegments = subsegs->items;

    if (0) {
      outmesh2medit("dump2");
    }

  }

  delete [] idx2verlist;

  // Boundary recovery.

  clock_t t;
  //    printf("coucou2\n");
  recoverboundary(t);
  //    printf("coucou3\n");

  carveholes();
  //    printf("coucou4\n");

  if (subvertstack->objects > 0l) {
    suppresssteinerpoints();
  }

  recoverdelaunay();

  // let's trry
  optimizemesh();

  if ((dupverts > 0l) || (unuverts > 0l)) {
    // Remove hanging nodes.
    // cannot call this here due to 8 additional exterior vertices we inserted
    // jettisonnodes();
  }

  long tetnumber, facenumber;

  Msg::Debug("Statistics:\n");
  Msg::Debug("  Input points: %ld", _vertices.size());
  if (b->plc) {
    Msg::Debug("  Input facets: %ld", f_list.size());
    Msg::Debug("  Input segments: %ld", e_list.size());
  }

  tetnumber = tetrahedrons->items - hullsize;
  facenumber = (tetnumber * 4l + hullsize) / 2l;

  if (b->weighted) { // -w option
    Msg::Debug(" Mesh points: %ld", points->items - nonregularcount);
  }
  else {
    Msg::Debug(" Mesh points: %ld", points->items);
  }
  Msg::Debug("  Mesh tetrahedra: %ld", tetnumber);
  Msg::Debug("  Mesh faces: %ld", facenumber);
  if (meshedges > 0l) {
    Msg::Debug("  Mesh edges: %ld", meshedges);
  } else {
    if (!nonconvex) {
      long vsize = points->items - dupverts - unuverts;
      if (b->weighted) vsize -= nonregularcount;
      meshedges = vsize + facenumber - tetnumber - 1;
      Msg::Debug("  Mesh edges: %ld", meshedges);
    }
  }

  if (b->plc || b->refine) {
    Msg::Debug("  Mesh faces on facets: %ld", subfaces->items);
    Msg::Debug("  Mesh edges on segments: %ld", subsegs->items);
    if (st_volref_count > 0l) {
      Msg::Debug("  Steiner points inside domain: %ld", st_volref_count);
    }
    if (st_facref_count > 0l) {
      Msg::Debug("  Steiner points on facets:  %ld", st_facref_count);
    }
    if (st_segref_count > 0l) {
      Msg::Debug("  Steiner points on segments:  %ld", st_segref_count);
    }
  }
  else {
    Msg::Debug("  Convex hull faces: %ld", hullsize);
    if (meshhulledges > 0l) {
      Msg::Debug("  Convex hull edges: %ld", meshhulledges);
    }
  }
  if (b->weighted) { // -w option
    Msg::Debug("  Skipped non-regular points: %ld", nonregularcount);
  }

  // Debug
  if (0) {
    outmesh2medit("dump");
  }

  {
    // Write mesh into to GRegion.

    Msg::Info("Writing to GRegion...");

    point p[4];

    // In some hard cases, the surface mesh may be modified.
    // Find the list of GFaces, GEdges that have been modified.
    std::set<int> l_faces, l_edges;

    if (points->items > (int)_vertices.size()) {
      face parentseg, parentsh, spinsh;
      point pointloop;
      // Create newly added mesh vertices.
      // The new vertices must be added at the end of the point list.
      points->traversalinit();
      pointloop = pointtraverse();
      while (pointloop != (point) NULL) {
        if (issteinerpoint(pointloop)) {
          // Check if this Steiner point locates on boundary.
          if (pointtype(pointloop) == FREESEGVERTEX) {
            sdecode(point2sh(pointloop), parentseg);
            assert(parentseg.sh != NULL);
            l_edges.insert(shellmark(parentseg));
            // Get the GEdge containing this vertex.
            GEdge *ge = NULL;
            GFace *gf = NULL;
            int etag = shellmark(parentseg);
            for (std::list<GEdge*>::iterator it = e_list.begin();
                 it != e_list.end(); ++it) {
              if ((*it)->tag() == etag) {
                ge = *it;
                break;
              }
            }
            if (ge != NULL) {
              MEdgeVertex *v = new MEdgeVertex(pointloop[0], pointloop[1],
                                               pointloop[2], ge, 0);
              double uu = 0;
              if (reparamMeshVertexOnEdge(v, ge, uu)) {
                v->setParameter(0, uu);
              }
              v->setIndex(pointmark(pointloop));
              _gr->mesh_vertices.push_back(v);
              _vertices.push_back(v);
            }
            spivot(parentseg, parentsh);
            if (parentsh.sh != NULL) {
              if (ge == NULL) {
                // We treat this vertex a facet vertex.
                int ftag = shellmark(parentsh);
                for (std::list<GFace*>::iterator it = f_list.begin();
                     it != f_list.end(); ++it) {
                  if ((*it)->tag() == ftag) {
                    gf = *it;
                    break;
                  }
                }
                if (gf != NULL) {
                  MFaceVertex *v = new MFaceVertex(pointloop[0], pointloop[1],
                                                   pointloop[2], gf, 0, 0);
                  SPoint2 param;
                  if (reparamMeshVertexOnFace(v, gf, param)) {
                    v->setParameter(0, param.x());
                    v->setParameter(1, param.y());
                  }
                  v->setIndex(pointmark(pointloop));
                  _gr->mesh_vertices.push_back(v);
                  _vertices.push_back(v);
                }
              }
              // Record all the GFaces' tag at this segment.
              spinsh = parentsh;
              while (1) {
                l_faces.insert(shellmark(spinsh));
                spivotself(spinsh);
                if (spinsh.sh == parentsh.sh) break;
              }
            }
            if ((ge == NULL) && (gf == NULL)) {
              // Create an interior mesh vertex.
              MVertex *v = new MVertex(pointloop[0], pointloop[1], pointloop[2], _gr);
              v->setIndex(pointmark(pointloop));
              _gr->mesh_vertices.push_back(v);
              _vertices.push_back(v);
            }
          }
          else if (pointtype(pointloop) == FREEFACETVERTEX) {
            sdecode(point2sh(pointloop), parentsh);
            assert(parentsh.sh != NULL);
            l_faces.insert(shellmark(parentsh));
            // Get the GFace containing this vertex.
            GFace *gf = NULL;
            int ftag = shellmark(parentsh);
            for (std::list<GFace*>::iterator it = f_list.begin();
                 it != f_list.end(); ++it) {
              if ((*it)->tag() == ftag) {
                gf = *it;
                break;
              }
            }
            if (gf != NULL) {
              MFaceVertex *v = new MFaceVertex(pointloop[0], pointloop[1],
                                               pointloop[2], gf, 0, 0);
              SPoint2 param;
              if (reparamMeshVertexOnFace(v, gf, param)) {
                v->setParameter(0, param.x());
                v->setParameter(1, param.y());
              }
              v->setIndex(pointmark(pointloop));
              _gr->mesh_vertices.push_back(v);
              _vertices.push_back(v);
            }
            else {
              // Create a mesh vertex.
              MVertex *v = new MVertex(pointloop[0], pointloop[1], pointloop[2], _gr);
              v->setIndex(pointmark(pointloop));
              _gr->mesh_vertices.push_back(v);
              _vertices.push_back(v);
            }
          }
          else {
            MVertex *v = new MVertex(pointloop[0], pointloop[1], pointloop[2], _gr);
            v->setIndex(pointmark(pointloop));
            _gr->mesh_vertices.push_back(v);
            _vertices.push_back(v);
          }
        }
        pointloop = pointtraverse();
      }
      assert((int)_vertices.size() == points->items);
    }

    if (l_edges.size() > 0) {
      // There are Steiner points on segments!
      face segloop;
      // Re-create the segment mesh in the corresponding GEdges.
      for (std::set<int>::iterator it = l_edges.begin(); it!=l_edges.end(); ++it) {
        // Find the GFace with tag = *it.
        GEdge *ge = NULL;
        int etag = *it;
        for (std::list<GEdge*>::iterator eit = e_list.begin();
             eit != e_list.end(); ++eit) {
          if ((*eit)->tag() == etag) {
            ge = (*eit);
            break;
          }
        }
        assert(ge != NULL);
        // Delete the old triangles.
        for(unsigned int i = 0; i < ge->lines.size(); i++)
          delete ge->lines[i];
        ge->lines.clear();
        ge->deleteVertexArrays();
        // Create the new triangles.
        segloop.shver = 0;
        subsegs->traversalinit();
        segloop.sh = shellfacetraverse(subsegs);
        while (segloop.sh != NULL) {
          if (shellmark(segloop) == etag) {
            p[0] = sorg(segloop);
            p[1] = sdest(segloop);
            MVertex *v1 = _vertices[pointmark(p[0])];
            MVertex *v2 = _vertices[pointmark(p[1])];
            MLine *t = new MLine(v1, v2);
            ge->lines.push_back(t);
          }
          segloop.sh = shellfacetraverse(subsegs);
        }
      } // it
    }

    if (l_faces.size() > 0) {
      // There are Steiner points on facets!
      face subloop;
      // Re-create the surface mesh in the corresponding GFaces.
      for (std::set<int>::iterator it = l_faces.begin(); it != l_faces.end(); ++it) {
        // Find the GFace with tag = *it.
        GFace *gf = NULL;
        int ftag = *it;
        for (std::list<GFace*>::iterator fit = f_list.begin();
             fit != f_list.end(); ++fit) {
          if ((*fit)->tag() == ftag) {
            gf = (*fit);
            break;
          }
        }
        assert(gf != NULL);
        // Delete the old triangles.
        Msg::Info("Steiner points exist on GFace %d", gf->tag());
        for(unsigned int i = 0; i < gf->triangles.size(); i++)
          delete gf->triangles[i];
        //for(i = 0; i < gf->quadrangles.size(); i++)
        //  delete gf->quadrangles[i];
        gf->triangles.clear();
        //gf->quadrangles.clear();
        gf->deleteVertexArrays();
        // Create the new triangles.
        subloop.shver = 0;
        subfaces->traversalinit();
        subloop.sh = shellfacetraverse(subfaces);
        while (subloop.sh != NULL) {
          if (shellmark(subloop) == ftag) {
            p[0] = sorg(subloop);
            p[1] = sdest(subloop);
            p[2] = sapex(subloop);
            MVertex *v1 = _vertices[pointmark(p[0])];
            MVertex *v2 = _vertices[pointmark(p[1])];
            MVertex *v3 = _vertices[pointmark(p[2])];
            MTriangle *t = new MTriangle(v1, v2, v3);
            gf->triangles.push_back(t);
          }
          subloop.sh = shellfacetraverse(subfaces);
        }
      } // it
    }

    triface tetloop;

    tetloop.ver = 11;
    tetrahedrons->traversalinit();
    tetloop.tet = tetrahedrontraverse();

    while (tetloop.tet != (tetrahedron *) NULL) {
      p[0] = org(tetloop);
      p[1] = dest(tetloop);
      p[2] = apex(tetloop);
      p[3] = oppo(tetloop);

      MVertex *v1 = _vertices[pointmark(p[0])];
      MVertex *v2 = _vertices[pointmark(p[1])];
      MVertex *v3 = _vertices[pointmark(p[2])];
      MVertex *v4 = _vertices[pointmark(p[3])];
      MTetrahedron *t = new  MTetrahedron(v1, v2, v3, v4);
      _gr->tetrahedra.push_back(t);
      tetloop.tet = tetrahedrontraverse();
    }
  } // mesh output

  Msg::Info("Reconstruct time : %g sec", Cpu() - t_start);
  return true;
}

// Dump the input surface mesh.
// 'mfilename' is a filename without suffix.
void tetgenmesh::outsurfacemesh(const char* mfilename)
{
  FILE *outfile = NULL;
  char sfilename[256];
  int firstindex;

  point pointloop;
  int pointnumber;
  strcpy(sfilename, mfilename);
  strcat(sfilename, ".node");
  outfile = fopen(sfilename, "w");
  if (!b->quiet) {
    printf("Writing %s.\n", sfilename);
  }
  fprintf(outfile, "%ld  3  0  0\n", points->items);
  // Determine the first index (0 or 1).
  firstindex = b->zeroindex ? 0 : in->firstnumber;
  points->traversalinit();
  pointloop = pointtraverse();
  pointnumber = firstindex; // in->firstnumber;
  while (pointloop != (point) NULL) {
    // Point number, x, y and z coordinates.
    fprintf(outfile, "%4d    %.17g  %.17g  %.17g", pointnumber,
            pointloop[0], pointloop[1], pointloop[2]);
    fprintf(outfile, "\n");
    pointloop = pointtraverse();
    pointnumber++;
  }
  fclose(outfile);

  face faceloop;
  point torg, tdest, tapex;
  strcpy(sfilename, mfilename);
  strcat(sfilename, ".smesh");
  outfile = fopen(sfilename, "w");
  if (!b->quiet) {
    printf("Writing %s.\n", sfilename);
  }
  int shift = 0; // Default no shiftment.
  if ((in->firstnumber == 1) && (firstindex == 0)) {
    shift = 1; // Shift the output indices by 1.
  }
  fprintf(outfile, "0 3 0 0\n");
  fprintf(outfile, "%ld  1\n", subfaces->items);
  subfaces->traversalinit();
  faceloop.sh = shellfacetraverse(subfaces);
  while (faceloop.sh != (shellface *) NULL) {
    torg = sorg(faceloop);
    tdest = sdest(faceloop);
    tapex = sapex(faceloop);
    fprintf(outfile, "3   %4d  %4d  %4d  %d\n",
            pointmark(torg) - shift, pointmark(tdest) - shift,
            pointmark(tapex) - shift, shellmark(faceloop));
    faceloop.sh = shellfacetraverse(subfaces);
  }
  fprintf(outfile, "0\n");
  fprintf(outfile, "0\n");
  fclose(outfile);

  face edgeloop;
  int edgenumber;
  strcpy(sfilename, mfilename);
  strcat(sfilename, ".edge");
  outfile = fopen(sfilename, "w");
  if (!b->quiet) {
    printf("Writing %s.\n", sfilename);
  }
  fprintf(outfile, "%ld  1\n", subsegs->items);
  subsegs->traversalinit();
  edgeloop.sh = shellfacetraverse(subsegs);
  edgenumber = firstindex; // in->firstnumber;
  while (edgeloop.sh != (shellface *) NULL) {
    torg = sorg(edgeloop);
    tdest = sdest(edgeloop);
    fprintf(outfile, "%5d   %4d  %4d  %d\n", edgenumber,
            pointmark(torg) - shift, pointmark(tdest) - shift,
            shellmark(edgeloop));
    edgenumber++;
    edgeloop.sh = shellfacetraverse(subsegs);
  }
  fclose(outfile);
}

void tetgenmesh::outmesh2medit(const char* mfilename)
{
  FILE *outfile;
  char mefilename[256];
  tetrahedron* tetptr;
  triface tface, tsymface;
  face segloop, checkmark;
  point ptloop, p1, p2, p3, p4;
  long ntets, faces;
  int shift = 0;
  int marker;

  if (mfilename != (char *) NULL && mfilename[0] != '\0') {
    strcpy(mefilename, mfilename);
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
  ptloop = pointtraverse();
  //pointnumber = 1;
  while (ptloop != (point) NULL) {
    // Point coordinates.
    fprintf(outfile, "%.17g  %.17g  %.17g", ptloop[0], ptloop[1], ptloop[2]);
    fprintf(outfile, "    0\n");
    //setpointmark(ptloop, pointnumber);
    ptloop = pointtraverse();
    //pointnumber++;
  }

  // Medit need start number form 1.
  if (in->firstnumber == 1) {
    shift = 0;
  } else {
    shift = 1;
  }

  // Compute the number of faces.
  ntets = tetrahedrons->items - hullsize;

  fprintf(outfile, "\n# Set of Tetrahedra\n");
  fprintf(outfile, "Tetrahedra\n");
  fprintf(outfile, "%ld\n", ntets);

  tetrahedrons->traversalinit();
  tetptr = tetrahedrontraverse();
  while (tetptr != (tetrahedron *) NULL) {
    if (!b->reversetetori) {
      p1 = (point) tetptr[4];
      p2 = (point) tetptr[5];
    } else {
      p1 = (point) tetptr[5];
      p2 = (point) tetptr[4];
    }
    p3 = (point) tetptr[6];
    p4 = (point) tetptr[7];
    fprintf(outfile, "%5d  %5d  %5d  %5d",
            pointmark(p1)+shift, pointmark(p2)+shift,
            pointmark(p3)+shift, pointmark(p4)+shift);
    if (numelemattrib > 0) {
      fprintf(outfile, "  %.17g", elemattribute(tetptr, 0));
    } else {
      fprintf(outfile, "  0");
    }
    fprintf(outfile, "\n");
    tetptr = tetrahedrontraverse();
  }

  //faces = (ntets * 4l + hullsize) / 2l;
  faces = subfaces->items;
  face sface;

  fprintf(outfile, "\n# Set of Triangles\n");
  fprintf(outfile, "Triangles\n");
  fprintf(outfile, "%ld\n", faces);

  subfaces->traversalinit();
  sface.sh = shellfacetraverse(subfaces);
  while (sface.sh != NULL) {
    p1 =  sorg(sface);
    p2 = sdest(sface);
    p3 = sapex(sface);
    fprintf(outfile, "%5d  %5d  %5d",
      pointmark(p1)+shift, pointmark(p2)+shift, pointmark(p3)+shift);
    marker = shellmark(sface);
    fprintf(outfile, "    %d\n", marker);
    sface.sh = shellfacetraverse(subfaces);
  }

  fprintf(outfile, "\nEnd\n");
  fclose(outfile);
}

} // end namespace

bool meshGRegionBoundaryRecovery(GRegion *gr)
{
  tetgenBR::tetgenmesh *m = new tetgenBR::tetgenmesh();
  bool ret = m->reconstructmesh((void*)gr);
  delete m;
  return ret;
}
