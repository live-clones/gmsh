// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <sstream>
#include "GmshConfig.h"
#include "meshGRegionBoundaryRecovery.h"

#if defined(HAVE_TETGENBR)

#include "meshGRegion.h"
#include "meshGRegionDelaunayInsertion.h"
#include "robustPredicates.h"
#include "GModel.h"
#include "GRegion.h"
#include "GFace.h"
#include "MVertex.h"
#include "MLine.h"
#include "MPoint.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "Context.h"
#include "OS.h"
#if !defined(HAVE_NO_STDINT_H)
#include <stdint.h>
#elif defined(HAVE_NO_INTPTR_T)
typedef unsigned long intptr_t;
#endif

#if defined(HAVE_POST)
#include "PView.h"
#endif

#if defined(HAVE_FLTK)
#include "FlGui.h"
#include "drawContext.h"
#endif

#if 0
static int computeTetGenVersion2(uint32_t v1, uint32_t* v2Choices,
                                 const int iface2)
{
  int i;
  for (i = 0; i < 3; i++) {
    if(v1 == v2Choices[i]){
      break;
    }
  }

  if(i == 3)
    Msg::Error("Should never happen (file:%s line:%d)", __FILE__, __LINE__);

  // version%4 : corresponding face in adjacent tet
  // version/4 : which of the 3 rotation of the facet the tetrahedra has...
  return 4 * i + iface2;
}
#endif

namespace tetgenBR {

#define REAL double

  struct brdata {
    GRegion *gr;
    splitQuadRecovery *sqr;
  };

  // dummy tetgenio class
  class tetgenio {
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
      firstnumber = 1;
      numberofpointattributes = 0;
      numberoftetrahedronattributes = 0;
      numberofsegmentconstraints = 0;
      segmentconstraintlist = nullptr;
      numberoffacetconstraints = 0;
      facetconstraintlist = nullptr;
      numberofpoints = 0;
      pointlist = nullptr;
      pointattributelist = nullptr;
      numberofpointmakers = 0;
      pointmarkerlist = nullptr;
      numberofpointmtrs = 0;
      pointmtrlist = nullptr;
      numberofedges = 0;
      edgelist = nullptr;
      edgemarkerlist = nullptr;
      numberofholes = 0;
      holelist = nullptr;
      numberofregions = 0;
      regionlist = nullptr;
      mesh_dim = 0;
    }
  };

// redefinition of predicates using our own
#define orient3d robustPredicates::orient3d
#define insphere robustPredicates::insphere
  static double orient4d(double *, double *, double *, double *, double *,
                         double, double, double, double, double)
  {
    return 0.;
  }
  static int clock() { return 0; }
#define clock_t int
#if !defined(TETLIBRARY)
#define TETLIBRARY
#endif
#define printf Msg::Auto
#include "tetgenBR.h"
#include "tetgenBR.cxx"
#undef printf

  int tetgenmesh::reconstructmesh(void *p, double tol /* unused */)
  {
    GRegion *_gr = ((brdata *)p)->gr;
    splitQuadRecovery *_sqr = ((brdata *)p)->sqr;

    char opts[128];
    sprintf(opts, "YpeQT%gp/%g", CTX::instance()->mesh.toleranceInitialDelaunay,
            CTX::instance()->mesh.angleToleranceFacetOverlap);
    b->parse_commandline(opts);

    double t_start = Cpu(), w_start = TimeOfDay();
    std::vector<MVertex *> _vertices;
    std::map<int, MVertex *> _extras;
    // Get the set of vertices from GRegion.
    {
      std::set<MVertex *, MVertexPtrLessThan> all;
      std::vector<GFace *> const &f = _gr->faces();
      for(auto it = f.begin(); it != f.end(); ++it) {
        GFace *gf = *it;
        for(std::size_t i = 0; i < gf->triangles.size(); i++) {
          MVertex *v0 = gf->triangles[i]->getVertex(0);
          MVertex *v1 = gf->triangles[i]->getVertex(1);
          MVertex *v2 = gf->triangles[i]->getVertex(2);
          all.insert(v0);
          all.insert(v1);
          all.insert(v2);
        }
        if(_sqr) {
          for(std::size_t i = 0; i < gf->quadrangles.size(); i++) {
            MVertex *v0 = gf->quadrangles[i]->getVertex(0);
            MVertex *v1 = gf->quadrangles[i]->getVertex(1);
            MVertex *v2 = gf->quadrangles[i]->getVertex(2);
            MVertex *v3 = gf->quadrangles[i]->getVertex(3);
            MVertex *newv =
              new MVertex((v0->x() + v1->x() + v2->x() + v3->x()) * 0.25,
                          (v0->y() + v1->y() + v2->y() + v3->y()) * 0.25,
                          (v0->z() + v1->z() + v2->z() + v3->z()) * 0.25, gf);
            // the extra vertex will be added in a GRegion (and reclassified
            // correctly on that GRegion) when the pyramid is generated
            MFace mf = gf->quadrangles[i]->getFace(0);
            _sqr->add(mf, newv, gf);
            all.insert(v0);
            all.insert(v1);
            all.insert(v2);
            all.insert(v3);
            all.insert(newv);
          }
        }
      }
      std::vector<GEdge *> const &e = _gr->embeddedEdges();
      for(auto it = e.begin(); it != e.end(); ++it) {
        GEdge *ge = *it;
        for(std::size_t i = 0; i < ge->lines.size(); i++) {
          all.insert(ge->lines[i]->getVertex(0));
          all.insert(ge->lines[i]->getVertex(1));
        }
      }
      std::vector<GVertex *> const &v = _gr->embeddedVertices();
      for(auto it = v.begin(); it != v.end(); ++it) {
        GVertex *gv = *it;
        for(std::size_t i = 0; i < gv->points.size(); i++) {
          all.insert(gv->points[i]->getVertex(0));
        }
      }
      all.insert(_gr->mesh_vertices.begin(), _gr->mesh_vertices.end());

      _vertices.insert(_vertices.begin(), all.begin(), all.end());
    }

    initializepools();

    // Store all coordinates of the vertices as these will be pertubated in
    // function delaunayTriangulation
    std::map<MVertex *, SPoint3> originalCoordinates;
    for(std::size_t i = 0; i < _vertices.size(); i++) {
      MVertex *v = _vertices[i];
      originalCoordinates[v] = v->point();
    }

    std::vector<MTetrahedron *> tets;

    delaunayMeshIn3D(_vertices,
                     tets); // will add 8 MVertices at the end of _vertices
    if(Msg::GetErrorCount()) return 0;

    Msg::Debug("Points have been tetrahedralized");

    {
      point pointloop;
      REAL x, y, z;

      // Read the points.
      for(std::size_t i = 0; i < _vertices.size(); i++) {
        makepoint(&pointloop, UNUSEDVERTEX);
        // Read the point coordinates.
        x = pointloop[0] = _vertices[i]->x();
        y = pointloop[1] = _vertices[i]->y();
        z = pointloop[2] = _vertices[i]->z();
        // Determine the smallest and largest x, y and z coordinates.
        if(i == 0) {
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
      if(longest == 0.0) {
        Msg::Warning("The point set is trivial");
        return 1;
      }

      // Two identical points are distinguished by 'lengthlimit'.
      if(minedgelength == 0.0) { minedgelength = longest * b->epsilon; }
    }

    point *idx2verlist;

    // Create a map from indices to vertices.
    makeindex2pointmap(idx2verlist);
    // 'idx2verlist' has length 'in->numberofpoints + 1'.
    idx2verlist[0] = dummypoint; // Let 0th-entry be dummypoint.
    // Index the vertices, starting at 1 (vertex index 0 is used as special code
    // in tetgenBR in case of failure)
    for(std::size_t i = 0; i < _vertices.size(); i++) {
      _vertices[i]->setIndex(i + 1);
    }

    {
      tetrahedron *ver2tetarray;
      triface tetloop, checktet, prevchktet;
      triface hulltet, face1, face2;
      tetrahedron tptr;
      point p[4], q[3];
      REAL ori; //, attrib, volume;
      int bondflag;
      int t1ver;
      int idx, k;

      Msg::Info("Reconstructing mesh...");

      // Allocate an array that maps each vertex to its adjacent tets.
      ver2tetarray = new tetrahedron[_vertices.size() + in->firstnumber];
      for(std::size_t i = 0; i < _vertices.size() + in->firstnumber; i++) {
        setpointtype(idx2verlist[i], VOLVERTEX); // initial type.
        ver2tetarray[i] = nullptr;
      }

#if 0
      /*  N E W   V E R S I O N	  */
      std::vector<triface> ts( tets.size() );
      for(std::size_t i = 0; i < tets.size(); i++) {
	point p[4];
	// index tetrahedra in order to have access to neighbors ids.
	tets[i]->tet()->forceNum(i+1);
	p[0] = idx2verlist[tets[i]->getVertex(0)->getIndex()];
	p[1] = idx2verlist[tets[i]->getVertex(1)->getIndex()];
	p[2] = idx2verlist[tets[i]->getVertex(2)->getIndex()];
	p[3] = idx2verlist[tets[i]->getVertex(3)->getIndex()];
	setvertices(ts[i], p[0], p[1], p[2], p[3]);
      }
          // we can make this in parallel, iterations are totally independent
      for (uint64_t i = 0; i < tets.size(); i++) {
	triface tf1 = ts[i];

	for (tf1.ver=0; tf1.ver<4; tf1.ver++){
	  uint64_t neigh = tets[i]->getNeigh(tf1.ver)->tet()->getNum() - 1;
	  triface tf2 = ts[neigh];
	  int iface2 = tf1.ver;

	  int face2[3] = {
	    tets[i]->getVertex(faces_tetra(tf1.ver),0)->getIndex(),
	    tets[i]->getVertex(faces_tetra(tf1.ver),1)->getIndex(),
	    tets[i]->getVertex(faces_tetra(tf1.ver),2)->getIndex()};

	  tf2.ver = computeTetGenVersion2(faces2[0], face2, iface2);
	  bond(tf1,tf2);
	}
      }

#else

      /*  N E W   V E R S I O N	  */

      // Create the tetrahedra and connect those that share a common face.
      for(std::size_t i = 0; i < tets.size(); i++) {
        // Get the four vertices.
        for(int j = 0; j < 4; j++) {
          p[j] = idx2verlist[tets[i]->getVertex(j)->getIndex()];
        }
        // Check the orientation.
        ori = orient3d(p[0], p[1], p[2], p[3]);
        if(ori > 0.0) {
          // Swap the first two vertices.
          q[0] = p[0];
          p[0] = p[1];
          p[1] = q[0];
        }
        else if(ori == 0.0) {
          if(!b->quiet) {
            Msg::Warning("Tet #%d is degenerated", i + in->firstnumber);
          }
        }
        // Create a new tetrahedron.
        maketetrahedron(&tetloop); // tetloop.ver = 11.
        setvertices(tetloop, p[0], p[1], p[2], p[3]);
        // Try connecting this tet to others that share the common faces.
        for(tetloop.ver = 0; tetloop.ver < 4; tetloop.ver++) {
          p[3] = oppo(tetloop);
          // Look for other tets having this vertex.
          idx = pointmark(p[3]) - in->firstnumber;
          tptr = ver2tetarray[idx];
          // Link the current tet to the next one in the stack.
          tetloop.tet[8 + tetloop.ver] = tptr;
          // Push the current tet onto the stack.
          ver2tetarray[idx] = encode(tetloop);
          decode(tptr, checktet);
          if(checktet.tet != nullptr) {
            p[0] = org(tetloop); // a
            p[1] = dest(tetloop); // b
            p[2] = apex(tetloop); // c
            prevchktet = tetloop;
            do {
              q[0] = org(checktet); // a'
              q[1] = dest(checktet); // b'
              q[2] = apex(checktet); // c'
              // Check the three faces at 'd' in 'checktet'.
              bondflag = 0;
              for(int j = 0; j < 3; j++) {
                // Go to the face [b',a',d], or [c',b',d], or [a',c',d].
                esym(checktet, face2);
                if(face2.tet[face2.ver & 3] == nullptr) {
                  k = ((j + 1) % 3);
                  if(q[k] == p[0]) { // b', c', a' = a
                    if(q[j] == p[1]) { // a', b', c' = b
                      // [#,#,d] is matched to [b,a,d].
                      esym(tetloop, face1);
                      bond(face1, face2);
                      bondflag++;
                    }
                  }
                  if(q[k] == p[1]) { // b',c',a' = b
                    if(q[j] == p[2]) { // a',b',c' = c
                      // [#,#,d] is matched to [c,b,d].
                      enext(tetloop, face1);
                      esymself(face1);
                      bond(face1, face2);
                      bondflag++;
                    }
                  }
                  if(q[k] == p[2]) { // b',c',a' = c
                    if(q[j] == p[0]) { // a',b',c' = a
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
              if(bondflag == 3) {
                // All three faces at d in 'checktet' have been connected.
                // It can be removed from the link.
                prevchktet.tet[8 + prevchktet.ver] = tptr;
              }
              else {
                // Bakup the previous tet in the link.
                prevchktet = checktet;
              }
              decode(tptr, checktet);
            } while(checktet.tet != nullptr);
          } // if(checktet.tet != nullptr)
        } // for(tetloop.ver = 0; ...
      } // i

      // Remember a tet of the mesh.
      recenttet = tetloop;

      // Create hull tets, create the point-to-tet map, and clean up the
      //   temporary spaces used in each tet.
      hullsize = tetrahedrons->items;

      tetrahedrons->traversalinit();
      tetloop.tet = tetrahedrontraverse();
      while(tetloop.tet != (tetrahedron *)nullptr) {
        tptr = encode(tetloop);
        for(tetloop.ver = 0; tetloop.ver < 4; tetloop.ver++) {
          if(tetloop.tet[tetloop.ver] == nullptr) {
            // Create a hull tet.
            maketetrahedron(&hulltet);
            p[0] = org(tetloop);
            p[1] = dest(tetloop);
            p[2] = apex(tetloop);
            setvertices(hulltet, p[1], p[0], p[2], dummypoint);
            bond(tetloop, hulltet);
            // Try connecting this to others that share common hull edges.
            for(int j = 0; j < 3; j++) {
              fsym(hulltet, face2);
              while(1) {
                if(face2.tet == nullptr) break;
                esymself(face2);
                if(apex(face2) == dummypoint) break;
                fsymself(face2);
              }
              if(face2.tet != nullptr) {
                // Found an adjacent hull tet.
                assert(face2.tet[face2.ver & 3] == nullptr);
                esym(hulltet, face1);
                bond(face1, face2);
              }
              enextself(hulltet);
            }
            // hullsize++;
          }
          // Create the point-to-tet map.
          setpoint2tet((point)(tetloop.tet[4 + tetloop.ver]), tptr);
          // Clean the temporary used space.
          tetloop.tet[8 + tetloop.ver] = nullptr;
        }
        tetloop.tet = tetrahedrontraverse();
      }

      hullsize = tetrahedrons->items - hullsize;

      delete[] ver2tetarray;
      for(std::size_t i = 0; i < tets.size(); i++) delete tets[i];
      tets.clear(); // Release all memory in this vector.
    }
#endif

      std::vector<GFace *> const &f_list = _gr->faces();
      std::vector<GEdge *> const &e_list = _gr->embeddedEdges();

      {
        Msg::Info(" - Creating surface mesh");
        face newsh;
        face newseg;
        point p[4];
        int idx;

        for(auto it = f_list.begin(); it != f_list.end(); ++it) {
          GFace *gf = *it;
          for(std::size_t i = 0; i < gf->triangles.size(); i++) {
            for(int j = 0; j < 3; j++) {
              p[j] = idx2verlist[gf->triangles[i]->getVertex(j)->getIndex()];
              if(pointtype(p[j]) == VOLVERTEX) {
                setpointtype(p[j], FACETVERTEX);
              }
            }
            makeshellface(subfaces, &newsh);
            setshvertices(newsh, p[0], p[1], p[2]);
            setshellmark(newsh, gf->tag()); // the GFace's tag.
            recentsh = newsh;
            for(int j = 0; j < 3; j++) {
              makeshellface(subsegs, &newseg);
              setshvertices(newseg, sorg(newsh), sdest(newsh), nullptr);
              // Set the default segment marker '-1'.
              setshellmark(newseg, -1);
              ssbond(newsh, newseg);
              senextself(newsh);
            }
          }
        } // it

        if(_sqr) {
          std::map<MFace, GFace *, MFaceLessThan> f = _sqr->getTri();
          for(auto it = f.begin(); it != f.end(); it++) {
            const MFace &mf = it->first;
            for(int j = 0; j < 3; j++) {
              p[j] = idx2verlist[mf.getVertex(j)->getIndex()];
              if(pointtype(p[j]) == VOLVERTEX) {
                setpointtype(p[j], FACETVERTEX);
              }
            }
            makeshellface(subfaces, &newsh);
            setshvertices(newsh, p[0], p[1], p[2]);
            setshellmark(newsh, it->second->tag());
            recentsh = newsh;
            for(int j = 0; j < 3; j++) {
              makeshellface(subsegs, &newseg);
              setshvertices(newseg, sorg(newsh), sdest(newsh), nullptr);
              // Set the default segment marker '-1'.
              setshellmark(newseg, -1);
              ssbond(newsh, newseg);
              senextself(newsh);
            }
          }
        }

        // Connecting triangles, removing redundant segments.
        unifysegments();

        Msg::Info(" - Identifying boundary edges");

        face *shperverlist;
        int *idx2shlist;
        face searchsh, neighsh;
        face segloop, checkseg;
        point checkpt;

        // Construct a map from points to subfaces.
        makepoint2submap(subfaces, idx2shlist, shperverlist);

        // Process the set of PSC edges.
        // Remeber that all segments have default marker '-1'.
        //    int COUNTER = 0;
        for(auto it = e_list.begin(); it != e_list.end(); ++it) {
          GEdge *ge = *it;
          for(std::size_t i = 0; i < ge->lines.size(); i++) {
            for(int j = 0; j < 2; j++) {
              p[j] = idx2verlist[ge->lines[i]->getVertex(j)->getIndex()];
              setpointtype(p[j], RIDGEVERTEX);
            }
            if(p[0] == p[1]) {
              // This is a potential problem in surface mesh.
              continue; // Skip this edge.
            }
            // Find a face contains the edge p[0], p[1].
            newseg.sh = nullptr;
            searchsh.sh = nullptr;
            idx = pointmark(p[0]) - in->firstnumber;
            for(int j = idx2shlist[idx]; j < idx2shlist[idx + 1]; j++) {
              checkpt = sdest(shperverlist[j]);
              if(checkpt == p[1]) {
                searchsh = shperverlist[j];
                break; // Found.
              }
              else {
                checkpt = sapex(shperverlist[j]);
                if(checkpt == p[1]) {
                  senext2(shperverlist[j], searchsh);
                  sesymself(searchsh);
                  break;
                }
              }
            } // j
            if(searchsh.sh != nullptr) {
              // Check if this edge is already a segment of the mesh.
              sspivot(searchsh, checkseg);
              if(checkseg.sh != nullptr) {
                // This segment already exist.
                newseg = checkseg;
              }
              else {
                // Create a new segment at this edge.
                makeshellface(subsegs, &newseg);
                setshvertices(newseg, p[0], p[1], nullptr);
                ssbond(searchsh, newseg);
                spivot(searchsh, neighsh);
                if(neighsh.sh != nullptr) { ssbond(neighsh, newseg); }
              }
            }
            else {
              // It is a dangling segment (not belong to any facets).
              // Check if segment [p[0],p[1]] already exists.
              // TODO: Change the brute-force search. Slow!
              /*	  point *ppt;
              subsegs->traversalinit();
              segloop.sh = shellfacetraverse(subsegs);
              while (segloop.sh != nullptr){
                ppt = (point *) &(segloop.sh[3]);
                if(((ppt[0] == p[0]) && (ppt[1] == p[1])) ||
                ((ppt[0] == p[1]) && (ppt[1] == p[0]))){
                  // Found!
                  newseg = segloop;
                  break;
                }
                segloop.sh = shellfacetraverse(subsegs);
                }*/
              if(newseg.sh == nullptr) {
                makeshellface(subsegs, &newseg);
                setshvertices(newseg, p[0], p[1], nullptr);
              }
            }
            setshellmark(newseg, ge->tag());
          } // i
        } // e_list

        delete[] shperverlist;
        delete[] idx2shlist;

        Msg::Debug("  %ld (%ld) subfaces (segments)", subfaces->items,
                   subsegs->items);

        // The total number of iunput segments.
        insegments = subsegs->items;

        if(0) { outmesh2medit("dump2"); }
      }

      delete[] idx2verlist;

      // Boundary recovery.

      clock_t t;
      Msg::Info(" - Recovering boundary");
      recoverboundary(t);

      carveholes();

      if(subvertstack->objects > 0l) { suppresssteinerpoints(); }

      recoverdelaunay();

      // let's try
      optimizemesh();

      if((dupverts > 0l) || (unuverts > 0l)) {
        // Remove hanging nodes.
        // cannot call this here due to 8 additional exterior vertices we
        // inserted jettisonnodes();
      }

      long tetnumber, facenumber;

      Msg::Debug("Statistics:\n");
      Msg::Debug("  Input points: %ld", _vertices.size());
      if(b->plc) {
        Msg::Debug("  Input facets: %ld", f_list.size());
        Msg::Debug("  Input segments: %ld", e_list.size());
      }

      tetnumber = tetrahedrons->items - hullsize;
      facenumber = (tetnumber * 4l + hullsize) / 2l;

      if(b->weighted) { // -w option
        Msg::Debug(" Mesh points: %ld", points->items - nonregularcount);
      }
      else {
        Msg::Debug(" Mesh points: %ld", points->items);
      }
      Msg::Debug("  Mesh tetrahedra: %ld", tetnumber);
      Msg::Debug("  Mesh faces: %ld", facenumber);
      if(meshedges > 0l) { Msg::Debug("  Mesh edges: %ld", meshedges); }
      else {
        if(!nonconvex) {
          long vsize = points->items - dupverts - unuverts;
          if(b->weighted) vsize -= nonregularcount;
          meshedges = vsize + facenumber - tetnumber - 1;
          Msg::Debug("  Mesh edges: %ld", meshedges);
        }
      }

      if(b->plc || b->refine) {
        Msg::Debug("  Mesh faces on facets: %ld", subfaces->items);
        Msg::Debug("  Mesh edges on segments: %ld", subsegs->items);
        if(st_volref_count > 0l) {
          Msg::Debug("  Steiner points inside domain: %ld", st_volref_count);
        }
        if(st_facref_count > 0l) {
          Msg::Debug("  Steiner points on facets:  %ld", st_facref_count);
        }
        if(st_segref_count > 0l) {
          Msg::Debug("  Steiner points on segments:  %ld", st_segref_count);
        }
      }
      else {
        Msg::Debug("  Convex hull faces: %ld", hullsize);
        if(meshhulledges > 0l) {
          Msg::Debug("  Convex hull edges: %ld", meshhulledges);
        }
      }
      if(b->weighted) { // -w option
        Msg::Debug("  Skipped non-regular points: %ld", nonregularcount);
      }

      // Debug
      if(0) { outmesh2medit("dump"); }

      {
        // Write mesh into to GRegion.

        Msg::Debug("Writing to GRegion...");

        point p[4];

        // In some hard cases, the surface mesh may be modified.
        // Find the list of GFaces, GEdges that have been modified.
        std::set<int> l_faces, l_edges;

        if(points->items > (int)_vertices.size()) {
          face parentseg, parentsh, spinsh;
          point pointloop;
          // Create newly added mesh vertices.
          // The new vertices must be added at the end of the point list.
          points->traversalinit();
          pointloop = pointtraverse();
          while(pointloop != (point)nullptr) {
            if(issteinerpoint(pointloop)) {
              // Check if this Steiner point locates on boundary.
              if(pointtype(pointloop) == FREESEGVERTEX) {
                sdecode(point2sh(pointloop), parentseg);
                assert(parentseg.sh != nullptr);
                l_edges.insert(shellmark(parentseg));
                // Get the GEdge containing this vertex.
                GEdge *ge = nullptr;
                GFace *gf = nullptr;
                int etag = shellmark(parentseg);
                for(auto it = e_list.begin(); it != e_list.end(); ++it) {
                  if((*it)->tag() == etag) {
                    ge = *it;
                    break;
                  }
                }
                if(ge != nullptr) {
                  MEdgeVertex *v = new MEdgeVertex(pointloop[0], pointloop[1],
                                                   pointloop[2], ge, 0);
                  double uu = 0;
                  if(reparamMeshVertexOnEdge(v, ge, uu)) {
                    v->setParameter(0, uu);
                  }
                  v->setIndex(pointmark(pointloop));
                  _gr->mesh_vertices.push_back(v);
                  _extras[pointmark(pointloop) - in->firstnumber] = v;
                }
                spivot(parentseg, parentsh);
                if(parentsh.sh != nullptr) {
                  if(ge == nullptr) {
                    // We treat this vertex a facet vertex.
                    int ftag = shellmark(parentsh);
                    for(auto it = f_list.begin(); it != f_list.end(); ++it) {
                      if((*it)->tag() == ftag) {
                        gf = *it;
                        break;
                      }
                    }
                    if(gf != nullptr) {
                      MFaceVertex *v = new MFaceVertex(
                        pointloop[0], pointloop[1], pointloop[2], gf, 0, 0);
                      SPoint2 param;
                      if(reparamMeshVertexOnFace(v, gf, param)) {
                        v->setParameter(0, param.x());
                        v->setParameter(1, param.y());
                      }
                      v->setIndex(pointmark(pointloop));
                      _gr->mesh_vertices.push_back(v);
                      _extras[pointmark(pointloop) - in->firstnumber] = v;
                    }
                  }
                  // Record all the GFaces' tag at this segment.
                  spinsh = parentsh;
                  while(1) {
                    l_faces.insert(shellmark(spinsh));
                    spivotself(spinsh);
                    if(spinsh.sh == parentsh.sh) break;
                  }
                }
                if((ge == nullptr) && (gf == nullptr)) {
                  // Create an interior mesh vertex.
                  MVertex *v =
                    new MVertex(pointloop[0], pointloop[1], pointloop[2], _gr);
                  v->setIndex(pointmark(pointloop));
                  _extras[pointmark(pointloop) - in->firstnumber] = v;
                  _gr->mesh_vertices.push_back(v);
                }
              }
              else if(pointtype(pointloop) == FREEFACETVERTEX) {
                sdecode(point2sh(pointloop), parentsh);
                assert(parentsh.sh != nullptr);
                l_faces.insert(shellmark(parentsh));
                // Get the GFace containing this vertex.
                GFace *gf = nullptr;
                int ftag = shellmark(parentsh);
                for(auto it = f_list.begin(); it != f_list.end(); ++it) {
                  if((*it)->tag() == ftag) {
                    gf = *it;
                    break;
                  }
                }
                if(gf != nullptr) {
                  MFaceVertex *v = new MFaceVertex(pointloop[0], pointloop[1],
                                                   pointloop[2], gf, 0, 0);
                  SPoint2 param;
                  if(reparamMeshVertexOnFace(v, gf, param)) {
                    v->setParameter(0, param.x());
                    v->setParameter(1, param.y());
                  }
                  v->setIndex(pointmark(pointloop));
                  _gr->mesh_vertices.push_back(v);
                  _extras[pointmark(pointloop) - in->firstnumber] = v;
                }
                else {
                  // Create a mesh vertex.
                  MVertex *v =
                    new MVertex(pointloop[0], pointloop[1], pointloop[2], _gr);
                  v->setIndex(pointmark(pointloop));
                  _gr->mesh_vertices.push_back(v);
                  _extras[pointmark(pointloop) - in->firstnumber] = v;
                }
              }
              else {
                MVertex *v =
                  new MVertex(pointloop[0], pointloop[1], pointloop[2], _gr);
                v->setIndex(pointmark(pointloop));
                _gr->mesh_vertices.push_back(v);
                _extras[pointmark(pointloop) - in->firstnumber] = v;
              }
            }
            pointloop = pointtraverse();
          }
          // assert((int)_vertices.size() == points->items);
        }

        if(!_extras.empty())
          Msg::Info(" - Added %d Steiner point%s", _extras.size(),
                    (_extras.size() > 1) ? "s" : "");

        if(l_edges.size() > 0) {
          // There are Steiner points on segments!
          face segloop;
          // Re-create the segment mesh in the corresponding GEdges.
          for(auto it = l_edges.begin(); it != l_edges.end(); ++it) {
            // Find the GEdge with tag = *it.

            int etag = *it;
            GEdge *ge = nullptr;
            for(auto it = e_list.begin(); it != e_list.end(); ++it) {
              if((*it)->tag() == etag) {
                ge = *it;
                break;
              }
            }
            if(ge != nullptr) {
              Msg::Info(" - Steiner points exist on curve %d", ge->tag());
              // Delete the old triangles.
              for(std::size_t i = 0; i < ge->lines.size(); i++)
                delete ge->lines[i];
              ge->lines.clear();
              ge->deleteVertexArrays();
              // Create the new triangles.
              segloop.shver = 0;
              subsegs->traversalinit();
              segloop.sh = shellfacetraverse(subsegs);
              while(segloop.sh != nullptr) {
                if(shellmark(segloop) == etag) {
                  p[0] = sorg(segloop);
                  p[1] = sdest(segloop);
                  int idx1 = pointmark(p[0]) - in->firstnumber;
                  MVertex *v1 = idx1 >= (int)_vertices.size() ? _extras[idx1] :
                    _vertices[idx1];
                  int idx2 = pointmark(p[1]) - in->firstnumber;
                  MVertex *v2 = idx2 >= (int)_vertices.size() ? _extras[idx2] :
                    _vertices[idx2];
                  MLine *t = new MLine(v1, v2);
                  ge->lines.push_back(t);
                }
                segloop.sh = shellfacetraverse(subsegs);
              }
            }
            else {
              Msg::Debug("Unknown curve %d with Steiner point(s)", etag);
            }
          } // it
        }

        if(l_faces.size() > 0) {
          // There are Steiner points on facets!
          face subloop;
          // Re-create the surface mesh in the corresponding GFaces.
          for(auto it = l_faces.begin(); it != l_faces.end(); ++it) {
            // Find the GFace with tag = *it.

            int ftag = *it;
            GFace *gf = nullptr;
            for(auto it = f_list.begin(); it != f_list.end(); ++it) {
              if((*it)->tag() == ftag) {
                gf = *it;
                break;
              }
            }
            if(gf != nullptr) {
              // Delete the old triangles.
              Msg::Info(" - Steiner points exist on surface %d", gf->tag());
              for(std::size_t i = 0; i < gf->triangles.size(); i++)
                delete gf->triangles[i];
              gf->triangles.clear();
              gf->deleteVertexArrays();

              if(gf->quadrangles.size()) {
                Msg::Warning("Steiner points not handled for quad surface mesh");
              }

              // Create the new triangles.
              subloop.shver = 0;
              subfaces->traversalinit();
              subloop.sh = shellfacetraverse(subfaces);
              while(subloop.sh != nullptr) {
                if(shellmark(subloop) == ftag) {
                  p[0] = sorg(subloop);
                  p[1] = sdest(subloop);
                  p[2] = sapex(subloop);
                  int idx1 = pointmark(p[0]) - in->firstnumber;
                  MVertex *v1 = idx1 >= (int)_vertices.size() ? _extras[idx1] :
                    _vertices[idx1];
                  int idx2 = pointmark(p[1]) - in->firstnumber;
                  MVertex *v2 = idx2 >= (int)_vertices.size() ? _extras[idx2] :
                    _vertices[idx2];
                  int idx3 = pointmark(p[2]) - in->firstnumber;
                  MVertex *v3 = idx3 >= (int)_vertices.size() ? _extras[idx3] :
                    _vertices[idx3];
                  MTriangle *t = new MTriangle(v1, v2, v3);
                  gf->triangles.push_back(t);
                }
                subloop.sh = shellfacetraverse(subfaces);
              }
            }
            else {
              Msg::Debug("Unknown surface %d with Steiner point(s)", ftag);
            }
          } // it
        }

        triface tetloop;

        tetloop.ver = 11;
        tetrahedrons->traversalinit();
        tetloop.tet = tetrahedrontraverse();

        while(tetloop.tet != (tetrahedron *)nullptr) {
          p[0] = org(tetloop);
          p[1] = dest(tetloop);
          p[2] = apex(tetloop);
          p[3] = oppo(tetloop);

          int idx1 = pointmark(p[0]) - in->firstnumber;
          MVertex *v1 =
            idx1 >= (int)_vertices.size() ? _extras[idx1] : _vertices[idx1];
          int idx2 = pointmark(p[1]) - in->firstnumber;
          MVertex *v2 =
            idx2 >= (int)_vertices.size() ? _extras[idx2] : _vertices[idx2];
          int idx3 = pointmark(p[2]) - in->firstnumber;
          MVertex *v3 =
            idx3 >= (int)_vertices.size() ? _extras[idx3] : _vertices[idx3];
          int idx4 = pointmark(p[3]) - in->firstnumber;
          MVertex *v4 =
            idx4 >= (int)_vertices.size() ? _extras[idx4] : _vertices[idx4];
          MTetrahedron *t = new MTetrahedron(v1, v2, v3, v4);
          _gr->tetrahedra.push_back(t);
          tetloop.tet = tetrahedrontraverse();
        }
      } // mesh output

      Msg::Info("Done reconstructing mesh (Wall %gs, CPU %gs)",
                TimeOfDay() - w_start, Cpu() - t_start);

      // Put all coordinates back so they are not pertubated anymore
      // (pertubation done in delaunayTriangulation)
      for(auto vIter = originalCoordinates.begin();
          vIter != originalCoordinates.end(); ++vIter) {
        const SPoint3 &coordinates = vIter->second;
        vIter->first->setXYZ(coordinates.x(), coordinates.y(), coordinates.z());
      }

      // delete 8 new enclosing box vertices added in delaunayMeshIn3d
      for(std::size_t i = _vertices.size() - 8; i < _vertices.size(); i++)
        delete _vertices[i];

      return 1;
    }

    // Dump the input surface mesh.
    // 'mfilename' is a filename without suffix.
    void tetgenmesh::outsurfacemesh(const char *mfilename)
    {
      FILE *outfile = nullptr;
      char sfilename[256];
      int firstindex;

      point pointloop;
      int pointnumber;
      strcpy(sfilename, mfilename);
      strcat(sfilename, ".node");
      outfile = fopen(sfilename, "w");
      if(!b->quiet) { printf("Writing %s.\n", sfilename); }
      fprintf(outfile, "%ld  3  0  0\n", points->items);
      // Determine the first index (0 or 1).
      firstindex = b->zeroindex ? 0 : in->firstnumber;
      points->traversalinit();
      pointloop = pointtraverse();
      pointnumber = firstindex; // in->firstnumber;
      while(pointloop != (point)nullptr) {
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
      if(!b->quiet) { printf("Writing %s.\n", sfilename); }
      int shift = 0; // Default no shiftment.
      if((in->firstnumber == 1) && (firstindex == 0)) {
        shift = 1; // Shift the output indices by 1.
      }
      fprintf(outfile, "0 3 0 0\n");
      fprintf(outfile, "%ld  1\n", subfaces->items);
      subfaces->traversalinit();
      faceloop.sh = shellfacetraverse(subfaces);
      while(faceloop.sh != (shellface *)nullptr) {
        torg = sorg(faceloop);
        tdest = sdest(faceloop);
        tapex = sapex(faceloop);
        fprintf(outfile, "3   %4d  %4d  %4d  %d\n", pointmark(torg) - shift,
                pointmark(tdest) - shift, pointmark(tapex) - shift,
                shellmark(faceloop));
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
      if(!b->quiet) { printf("Writing %s.\n", sfilename); }
      fprintf(outfile, "%ld  1\n", subsegs->items);
      subsegs->traversalinit();
      edgeloop.sh = shellfacetraverse(subsegs);
      edgenumber = firstindex; // in->firstnumber;
      while(edgeloop.sh != (shellface *)nullptr) {
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

    void tetgenmesh::outmesh2medit(const char *mfilename)
    {
      FILE *outfile;
      char mefilename[256];
      tetrahedron *tetptr;
      triface tface, tsymface;
      face segloop, checkmark;
      point ptloop, p1, p2, p3, p4;
      long ntets, faces;
      int shift = 0;
      int marker;

      if(mfilename != (char *)nullptr && mfilename[0] != '\0') {
        strcpy(mefilename, mfilename);
      }
      else {
        strcpy(mefilename, "unnamed");
      }
      strcat(mefilename, ".mesh");

      if(!b->quiet) { printf("Writing %s.\n", mefilename); }
      outfile = fopen(mefilename, "w");
      if(outfile == (FILE *)nullptr) {
        Msg::Error("Could not open file '%s'", mefilename);
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
      // pointnumber = 1;
      while(ptloop != (point)nullptr) {
        // Point coordinates.
        fprintf(outfile, "%.17g  %.17g  %.17g", ptloop[0], ptloop[1],
                ptloop[2]);
        fprintf(outfile, "    0\n");
        // setpointmark(ptloop, pointnumber);
        ptloop = pointtraverse();
        // pointnumber++;
      }

      // Medit need start number form 1.
      if(in->firstnumber == 1) { shift = 0; }
      else {
        shift = 1;
      }

      // Compute the number of faces.
      ntets = tetrahedrons->items - hullsize;

      fprintf(outfile, "\n# Set of Tetrahedra\n");
      fprintf(outfile, "Tetrahedra\n");
      fprintf(outfile, "%ld\n", ntets);

      tetrahedrons->traversalinit();
      tetptr = tetrahedrontraverse();
      while(tetptr != (tetrahedron *)nullptr) {
        if(!b->reversetetori) {
          p1 = (point)tetptr[4];
          p2 = (point)tetptr[5];
        }
        else {
          p1 = (point)tetptr[5];
          p2 = (point)tetptr[4];
        }
        p3 = (point)tetptr[6];
        p4 = (point)tetptr[7];
        fprintf(outfile, "%5d  %5d  %5d  %5d", pointmark(p1) + shift,
                pointmark(p2) + shift, pointmark(p3) + shift,
                pointmark(p4) + shift);
        if(numelemattrib > 0) {
          fprintf(outfile, "  %.17g", elemattribute(tetptr, 0));
        }
        else {
          fprintf(outfile, "  0");
        }
        fprintf(outfile, "\n");
        tetptr = tetrahedrontraverse();
      }

      // faces = (ntets * 4l + hullsize) / 2l;
      faces = subfaces->items;
      face sface;

      fprintf(outfile, "\n# Set of Triangles\n");
      fprintf(outfile, "Triangles\n");
      fprintf(outfile, "%ld\n", faces);

      subfaces->traversalinit();
      sface.sh = shellfacetraverse(subfaces);
      while(sface.sh != nullptr) {
        p1 = sorg(sface);
        p2 = sdest(sface);
        p3 = sapex(sface);
        fprintf(outfile, "%5d  %5d  %5d", pointmark(p1) + shift,
                pointmark(p2) + shift, pointmark(p3) + shift);
        marker = shellmark(sface);
        fprintf(outfile, "    %d\n", marker);
        sface.sh = shellfacetraverse(subfaces);
      }

      fprintf(outfile, "\nEnd\n");
      fclose(outfile);
    }

  } // namespace tetgenBR

  bool meshGRegionBoundaryRecovery(GRegion *gr, splitQuadRecovery *sqr)
  {
    bool ret = false;
    try {
      tetgenBR::tetgenmesh *m = new tetgenBR::tetgenmesh();
      m->in = new tetgenBR::tetgenio();
      m->b = new tetgenBR::tetgenbehavior();
      tetgenBR::brdata data = {gr, sqr};
      ret = m->reconstructmesh((void *)&data, 0.);
      delete m->in;
      delete m->b;
      delete m;
    } catch(int err) {
      if(err == 1) {
        Msg::Error("Out of memory in boundary mesh recovery");
        ret = false;
      }
      else if(err == 3) {
        std::map<int, MVertex *> all;
        std::vector<GFace *> f = gr->faces();
        for(auto it = f.begin(); it != f.end(); ++it) {
          GFace *gf = *it;
          for(std::size_t i = 0; i < gf->triangles.size(); i++) {
            for(int j = 0; j < 3; j++) {
              MVertex *v = gf->triangles[i]->getVertex(j);
              all[v->getIndex()] = v;
            }
          }
        }
        std::vector<GEdge *> const &e = gr->embeddedEdges();
        for(auto it = e.begin(); it != e.end(); ++it) {
          GEdge *ge = *it;
          for(std::size_t i = 0; i < ge->lines.size(); i++) {
            for(int j = 0; j < 2; j++) {
              MVertex *v = ge->lines[i]->getVertex(j);
              all[v->getIndex()] = v;
            }
          }
        }
        std::vector<GVertex *> const &v = gr->embeddedVertices();
        for(auto it = v.begin(); it != v.end(); ++it) {
          GVertex *gv = *it;
          for(std::size_t i = 0; i < gv->points.size(); i++) {
            MVertex *v = gv->points[i]->getVertex(0);
            all[v->getIndex()] = v;
          }
        }
        for(std::size_t i = 0; i < gr->mesh_vertices.size(); i++) {
          MVertex *v = gr->mesh_vertices[i];
          all[v->getIndex()] = v;
        }
        std::string what;
        bool pnt = true;
        switch(tetgenBR::sevent.e_type) {
        case 1: what = "segment-segment intersection"; break;
        case 2: what = "segment-facet intersection"; break;
        case 3: what = "facet-facet intersection"; break;
        case 4:
          what = "overlapping segments";
          pnt = false;
          break;
        case 5:
          what = "segment in facet";
          pnt = false;
          break;
        case 6:
          what = "overlapping facets";
          pnt = false;
          break;
        case 7: what = "vertex in segment"; break;
        case 8: what = "vertex in facet"; break;
        default: what = "unknown"; break;
        }
        int vtags[2][3] = {
          {tetgenBR::sevent.f_vertices1[0], tetgenBR::sevent.f_vertices1[1],
           tetgenBR::sevent.f_vertices1[2]},
          {tetgenBR::sevent.f_vertices2[0], tetgenBR::sevent.f_vertices2[1],
           tetgenBR::sevent.f_vertices2[2]}};
        int ftags[2] = {tetgenBR::sevent.f_marker1, tetgenBR::sevent.f_marker2};
        int etags[2] = {tetgenBR::sevent.s_marker1, tetgenBR::sevent.s_marker2};
        std::ostringstream pb;
        std::vector<double> x, y, z, val;
        for(int f = 0; f < 2; f++) {
          if(ftags[f] > 0) {
            GFace *gf = gr->model()->getFaceByTag(ftags[f]);
            if(gf) {
              gr->model()->addLastMeshEntityError(gf);
              pb << " surface " << ftags[f];
            }
          }
          if(etags[f] > 0) {
            GEdge *ge = gr->model()->getEdgeByTag(etags[f]);
            if(ge) {
              gr->model()->addLastMeshEntityError(ge);
              pb << " curve " << etags[f];
            }
          }
          for(int i = 0; i < 3; i++) {
            MVertex *v = all[vtags[f][i]];
            if(v) {
              gr->model()->addLastMeshVertexError(v);
              x.push_back(v->x());
              y.push_back(v->y());
              z.push_back(v->z());
              val.push_back(f);
            }
          }
        }
        if(pnt) {
          double px = tetgenBR::sevent.int_point[0];
          double py = tetgenBR::sevent.int_point[1];
          double pz = tetgenBR::sevent.int_point[2];
          pb << ", intersection (" << px << "," << py << "," << pz << ")";
          x.push_back(px);
          y.push_back(py);
          z.push_back(pz);
          val.push_back(3.);
        }
        Msg::Error("Invalid boundary mesh (%s) on%s", what.c_str(),
                   pb.str().c_str());
#if defined(HAVE_POST)
        new PView("Boundary mesh issue", x, y, z, val);
#if defined(HAVE_FLTK)
        if(FlGui::available()) FlGui::instance()->updateViews(true, true);
        drawContext::global()->draw();
#endif
#endif
        ret = false;
      }
      else {
        Msg::Error("Could not recover boundary mesh: error %d", err);
        ret = false;
      }
    }
    return ret;
  }

#else

bool meshGRegionBoundaryRecovery(GRegion *gr, splitQuadRecovery *sqr)
{
  return false;
}

#endif
