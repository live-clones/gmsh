// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <cstdarg>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <sstream>
#include "GmshConfig.h"
#include "meshGRegionBoundaryRecovery.h"

#if defined(HAVE_TETGENBR)

#include "meshGRegion.h"
#include "meshGRegionDelaunay.h"
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

  struct coreData {
    const boundaryRecoveryInput *in;
    boundaryRecoveryOutput *out;
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
  // TetGen's messages: at their natural level, or as debug output when the
  // caller does not want them (a failed local recovery is not an error)
  static bool tetgenQuiet = false;
  static void tetgenPrintf(const char *fmt, ...)
  {
    char str[5000];
    va_list args;
    va_start(args, fmt);
    vsnprintf(str, sizeof(str), fmt, args);
    va_end(args);
    if(tetgenQuiet)
      Msg::Debug("%s", str);
    else
      Msg::Auto("%s", str);
  }
#define printf tetgenPrintf
#include "tetgenBR.h"
#include "tetgenBR.cxx"
#undef printf

  int tetgenmesh::reconstructmesh(void *p, double /* unused */)
  {
    const boundaryRecoveryInput &I = *((coreData *)p)->in;
    boundaryRecoveryOutput &O = *((coreData *)p)->out;

    char opts[128];
    sprintf(opts, "YpeQT%gp/%g", CTX::instance()->mesh.toleranceInitialDelaunay,
            I.overlapAngleTolerance >= 0. ?
              I.overlapAngleTolerance :
              CTX::instance()->mesh.angleToleranceFacetOverlap);
    b->parse_commandline(opts);

    initializepools();
    const std::size_t nv = I.xyz.size() / 3;

    {
      point pointloop;
      REAL x, y, z;

      // Read the points.
      for(std::size_t i = 0; i < nv; i++) {
        makepoint(&pointloop, UNUSEDVERTEX);
        // Read the point coordinates.
        x = pointloop[0] = I.xyz[3 * i];
        y = pointloop[1] = I.xyz[3 * i + 1];
        z = pointloop[2] = I.xyz[3 * i + 2];
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

    std::vector<triface> ts; // the tets, in the input order
    {
      triface tetloop, checktet;
      triface hulltet, face1, face2;
      tetrahedron tptr;
      point p[4], q[3];
      REAL ori; //, attrib, volume;
      int t1ver; // used by the fsymself() macro
      int k;

      if(I.verbose) Msg::Info("Reconstructing mesh...");

      for(std::size_t i = 0; i < nv + in->firstnumber; i++) {
        setpointtype(idx2verlist[i], VOLVERTEX); // initial type.
      }

      // Create the tetrahedra.
      const std::size_t numTets = I.tetNode.size() / 4;
      ts.resize(numTets);
      for(std::size_t i = 0; i < numTets; i++) {
        // Get the four vertices.
        for(int j = 0; j < 4; j++) {
          p[j] = idx2verlist[I.tetNode[4 * i + j] + in->firstnumber];
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
        ts[i] = tetloop;
      }

      // Remember a tet of the mesh, in the state the former version-scanning
      // code left it in.
      tetloop.ver = 4;
      recenttet = tetloop;

      // Connect the tetrahedra that share a common face, using the
      // adjacencies computed by the initial Delaunay triangulation instead
      // of rediscovering them through per-vertex tet lists. For each pair,
      // the case analysis replicates the former code (with the later tet
      // playing the role of the tet whose creation triggered the scan), so
      // that the face bonds - including their edge versions - are identical.
      for(std::size_t i = 0; i < ts.size(); i++) {
        for(int kf = 0; kf < 4; kf++) {
          const std::int64_t nj = I.tetNeighbors[4 * i + kf];
          if(nj < 0 || (std::size_t)nj <= i) continue;
          triface L = ts[nj]; // created later
          triface E = ts[i]; // created earlier
          bool bonded = false;
          for(L.ver = 0; L.ver < 4 && !bonded; L.ver++) {
            point d = oppo(L);
            int vE = -1;
            for(E.ver = 0; E.ver < 4; E.ver++) {
              if(oppo(E) == d) {
                vE = E.ver;
                break;
              }
            }
            if(vE < 0) continue;
            E.ver = vE;
            p[0] = org(L); // a
            p[1] = dest(L); // b
            p[2] = apex(L); // c
            q[0] = org(E); // a'
            q[1] = dest(E); // b'
            q[2] = apex(E); // c'
            checktet = E;
            for(int j = 0; j < 3 && !bonded; j++) {
              // Go to the face [b',a',d], or [c',b',d], or [a',c',d].
              esym(checktet, face2);
              if(face2.tet[face2.ver & 3] == nullptr) {
                k = ((j + 1) % 3);
                if(q[k] == p[0] && q[j] == p[1]) {
                  // [#,#,d] is matched to [b,a,d].
                  esym(L, face1);
                  bond(face1, face2);
                  bonded = true;
                }
                else if(q[k] == p[1] && q[j] == p[2]) {
                  // [#,#,d] is matched to [c,b,d].
                  enext(L, face1);
                  esymself(face1);
                  bond(face1, face2);
                  bonded = true;
                }
                else if(q[k] == p[2] && q[j] == p[0]) {
                  // [#,#,d] is matched to [a,c,d].
                  eprev(L, face1);
                  esymself(face1);
                  bond(face1, face2);
                  bonded = true;
                }
              }
              enextself(checktet);
            } // j
          } // L.ver
        } // kf
      } // i

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
    }

      {
        if(I.verbose) Msg::Info(" - Creating surface mesh");
        face newsh;
        face newseg;
        point p[4];
        int idx;

        for(std::size_t i = 0; i < I.triNode.size() / 3; i++) {
          for(int j = 0; j < 3; j++) {
            p[j] = idx2verlist[I.triNode[3 * i + j] + in->firstnumber];
            if(pointtype(p[j]) == VOLVERTEX) {
              setpointtype(p[j], FACETVERTEX);
            }
          }
          makeshellface(subfaces, &newsh);
          setshvertices(newsh, p[0], p[1], p[2]);
          setshellmark(newsh, I.triTag[i]);
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

        // Connecting triangles, removing redundant segments.
        unifysegments();

        if(I.verbose) Msg::Info(" - Identifying boundary edges");

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
        for(std::size_t i = 0; i < I.segNode.size() / 2; i++) {
          {
            for(int j = 0; j < 2; j++) {
              p[j] = idx2verlist[I.segNode[2 * i + j] + in->firstnumber];
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
            setshellmark(newseg, I.segTag[i]);
          }
        } // segments

        delete[] shperverlist;
        delete[] idx2shlist;

        Msg::Debug("  %ld (%ld) subfaces (segments)", subfaces->items,
                   subsegs->items);

        // The total number of iunput segments.
        insegments = subsegs->items;
      }

      delete[] idx2verlist;

      // Boundary recovery.

      if(I.nonconvex) {
        // the walks towards a point (finddirection) may leave a cavity: let
        // them. The constraints present in the mesh are bonded here, from
        // the tets given with the triangles (the boundary of a cavity may be
        // non-manifold: the tets around a point are not all reached through
        // its faces, so no search), the segments through their subfaces, so
        // that the recovery walks only for the missing ones
        nonconvex = 1;
        int t1ver; // used by the fsymself/fnextself macros
        triface tetloop, spintet;
        face sh;
        std::size_t missingFaces = 0, missingSegs = 0, i = 0;
        subfaces->traversalinit();
        sh.sh = shellfacetraverse(subfaces);
        while(sh.sh != nullptr) {
          sh.shver = 0;
          const point p0 = sorg(sh), p1 = sdest(sh), p2 = sapex(sh);
          const std::int64_t j = i < I.triTet.size() ? I.triTet[i] : -1;
          bool bonded = false;
          if(j >= 0) {
            // the face (p0, p1, p2) of tet j, oriented like the subface,
            // seen from tet j or from the tet across
            tetloop = ts[j];
            int ver = 0;
            for(; ver < 12; ver++) {
              tetloop.ver = ver;
              if(org(tetloop) == p0 && dest(tetloop) == p1 &&
                 apex(tetloop) == p2)
                break;
            }
            if(ver < 12)
              bonded = true;
            else {
              for(ver = 0; ver < 12; ver++) {
                tetloop.ver = ver;
                if(org(tetloop) == p1 && dest(tetloop) == p0 &&
                   apex(tetloop) == p2)
                  break;
              }
              if(ver < 12) {
                fsymself(tetloop);
                bonded = true;
              }
            }
            if(bonded) {
              tsbond(tetloop, sh);
              fsymself(tetloop);
              sesymself(sh);
              tsbond(tetloop, sh);
            }
          }
          if(!bonded) missingFaces++;
          sh.sh = shellfacetraverse(subfaces);
          i++;
        }
        subsegs->traversalinit();
        sh.sh = shellfacetraverse(subsegs);
        while(sh.sh != nullptr) {
          sh.shver = 0;
          face parentsh;
          spivot(sh, parentsh);
          bool bonded = false;
          if(parentsh.sh != nullptr) {
            stpivot(parentsh, tetloop);
            if(tetloop.tet != nullptr) {
              const point e0 = sorg(sh), e1 = sdest(sh);
              int ver = 0;
              for(; ver < 12; ver++) {
                tetloop.ver = ver;
                if(org(tetloop) == e0 && dest(tetloop) == e1) break;
              }
              if(ver < 12) {
                bonded = true;
                sstbond1(sh, tetloop);
                spintet = tetloop;
                do {
                  tssbond1(spintet, sh);
                  fnextself(spintet);
                } while(spintet.tet != tetloop.tet);
              }
            }
          }
          if(!bonded) missingSegs++;
          sh.sh = shellfacetraverse(subsegs);
        }
        Msg::Debug("  nonconvex mesh: %lu of %ld faces and %lu of %ld segments "
                   "left to recover",
                   missingFaces, subfaces->items, missingSegs, subsegs->items);
      }
      ts.clear();

      clock_t t;
      if(I.verbose) Msg::Info(" - Recovering boundary");
      recoverboundary(t);

      if(I.carve) carveholes();

      if(subvertstack->objects > 0l) { suppresssteinerpoints(); }

      if(I.postprocess) {
        recoverdelaunay();
        // let's try
        optimizemesh();
      }

      Msg::Debug("  Mesh tetrahedra: %ld", tetrahedrons->items - hullsize);
      Msg::Debug("  Mesh faces on facets: %ld", subfaces->items);
      Msg::Debug("  Mesh edges on segments: %ld", subsegs->items);
      if(st_volref_count > 0l)
        Msg::Debug("  Steiner points inside domain: %ld", st_volref_count);
      if(st_facref_count > 0l)
        Msg::Debug("  Steiner points on facets:  %ld", st_facref_count);
      if(st_segref_count > 0l)
        Msg::Debug("  Steiner points on segments:  %ld", st_segref_count);

      {
        // the output: the Steiner points first (index nv + k for the k-th)
        point p[4];
        std::vector<std::uint32_t> markToIndex(points->items + nv + 2, 0);
        for(std::size_t i = 0; i < nv; i++)
          markToIndex[i + in->firstnumber] = (std::uint32_t)i;
        {
          face parentseg, parentsh, spinsh;
          point pointloop;
          points->traversalinit();
          pointloop = pointtraverse();
          while(pointloop != (point)nullptr) {
            if(issteinerpoint(pointloop)) {
              const std::uint32_t index =
                (std::uint32_t)(nv + O.steinerXYZ.size() / 3);
              markToIndex[pointmark(pointloop)] = index;
              for(int k = 0; k < 3; k++) O.steinerXYZ.push_back(pointloop[k]);
              int type = 0, segTag = -1, faceTag = -1;
              if(pointtype(pointloop) == FREESEGVERTEX) {
                type = 1;
                sdecode(point2sh(pointloop), parentseg);
                assert(parentseg.sh != nullptr);
                segTag = shellmark(parentseg);
                O.changedEdges.insert(segTag);
                spivot(parentseg, parentsh);
                if(parentsh.sh != nullptr) {
                  faceTag = shellmark(parentsh);
                  // Record all the facets at this segment (the ring is not
                  // closed around a segment with a single facet)
                  spinsh = parentsh;
                  while(1) {
                    O.changedFaces.insert(shellmark(spinsh));
                    spivotself(spinsh);
                    if(spinsh.sh == nullptr || spinsh.sh == parentsh.sh) break;
                  }
                }
              }
              else if(pointtype(pointloop) == FREEFACETVERTEX) {
                type = 2;
                sdecode(point2sh(pointloop), parentsh);
                assert(parentsh.sh != nullptr);
                faceTag = shellmark(parentsh);
                O.changedFaces.insert(faceTag);
              }
              O.steinerType.push_back(type);
              O.steinerSegTag.push_back(segTag);
              O.steinerFaceTag.push_back(faceTag);
            }
            pointloop = pointtraverse();
          }
        }
        {
          face segloop;
          segloop.shver = 0;
          subsegs->traversalinit();
          segloop.sh = shellfacetraverse(subsegs);
          while(segloop.sh != nullptr) {
            p[0] = sorg(segloop);
            p[1] = sdest(segloop);
            O.segNode.push_back(markToIndex[pointmark(p[0])]);
            O.segNode.push_back(markToIndex[pointmark(p[1])]);
            O.segTag.push_back(shellmark(segloop));
            segloop.sh = shellfacetraverse(subsegs);
          }
        }
        {
          face subloop;
          subloop.shver = 0;
          subfaces->traversalinit();
          subloop.sh = shellfacetraverse(subfaces);
          while(subloop.sh != nullptr) {
            p[0] = sorg(subloop);
            p[1] = sdest(subloop);
            p[2] = sapex(subloop);
            for(int k = 0; k < 3; k++)
              O.triNode.push_back(markToIndex[pointmark(p[k])]);
            O.triTag.push_back(shellmark(subloop));
            subloop.sh = shellfacetraverse(subfaces);
          }
        }
        {
          triface tetloop;
          tetloop.ver = 11;
          tetrahedrons->traversalinit();
          tetloop.tet = tetrahedrontraverse();
          while(tetloop.tet != (tetrahedron *)nullptr) {
            p[0] = org(tetloop);
            p[1] = dest(tetloop);
            p[2] = apex(tetloop);
            p[3] = oppo(tetloop);
            for(int k = 0; k < 4; k++)
              O.tetNode.push_back(markToIndex[pointmark(p[k])]);
            tetloop.tet = tetrahedrontraverse();
          }
        }
      }
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

  // the flat entry point: the recovery itself, with tetgen's error code
  int runCore(const boundaryRecoveryInput &in, boundaryRecoveryOutput &out)
  {
    int err = 0;
    tetgenBR::tetgenmesh *m = new tetgenBR::tetgenmesh();
    m->in = new tetgenBR::tetgenio();
    m->b = new tetgenBR::tetgenbehavior();
    tetgenBR::coreData data = {&in, &out};
    tetgenBR::tetgenQuiet = !in.verbose;
    try {
      if(!m->reconstructmesh((void *)&data, 0.)) err = -1;
    } catch(int e) {
      err = e;
      if(e == 3) {
        Msg::Debug("TetGen input error: event type %d, markers %d %d / %d %d",
                   tetgenBR::sevent.e_type, tetgenBR::sevent.f_marker1,
                   tetgenBR::sevent.f_marker2, tetgenBR::sevent.s_marker1,
                   tetgenBR::sevent.s_marker2);
        const int *fv[2] = {tetgenBR::sevent.f_vertices1,
                            tetgenBR::sevent.f_vertices2};
        for(int f = 0; f < 2; f++)
          for(int k = 0; k < 3; k++) {
            const int i = fv[f][k] - 1;
            if(i >= 0 && 3 * i + 2 < (int)in.xyz.size())
              Msg::Debug("  facet %d vertex %d: (%.17g %.17g %.17g)", f, i,
                         in.xyz[3 * i], in.xyz[3 * i + 1], in.xyz[3 * i + 2]);
          }
      }
    }
    delete m->in;
    delete m->b;
    delete m;
    tetgenBR::tetgenQuiet = false;
    return err;
  }

  bool meshGRegionBoundaryRecovery(GRegion *gr, splitQuadRecovery *sqr,
                                   const initialTetrahedralization *init)
  {
    double t_start = Cpu(), w_start = TimeOfDay();
    std::vector<MVertex *> _vertices;
    // Get the set of vertices from GRegion.
    if(init) { _vertices = init->vertices; }
    else {
      std::set<MVertex *, MVertexPtrLessThan> all;
      std::vector<GFace *> const &f = gr->faces();
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
        if(sqr) {
          for(std::size_t i = 0; i < gf->quadrangles.size(); i++) {
            MVertex *v0 = gf->quadrangles[i]->getVertex(0);
            MVertex *v1 = gf->quadrangles[i]->getVertex(1);
            MVertex *v2 = gf->quadrangles[i]->getVertex(2);
            MVertex *v3 = gf->quadrangles[i]->getVertex(3);
            MFace mf = gf->quadrangles[i]->getFace(0);
            if(sqr->doWeCreatePyramids()) {
              SPoint3 p((v0->x() + v1->x() + v2->x() + v3->x()) * 0.25,
                        (v0->y() + v1->y() + v2->y() + v3->y()) * 0.25,
                        (v0->z() + v1->z() + v2->z() + v3->z()) * 0.25);
              if(CTX::instance()->mesh.optimizePyramids < 0) {
                // push the vertex along the face normal by fact * diam_face:
                double fact = std::abs(CTX::instance()->mesh.optimizePyramids);
                SVector3 n = mf.normal();
                double diam = v0->distance(v2);
                p = (p + fact * diam * n);
              }
              MVertex *newv = new MVertex(p.x(), p.y(), p.z(), gf);
              // the extra vertex will be added in a GRegion (and reclassified
              // correctly on that GRegion) when the pyramid is generated
              sqr->add(mf, newv, gf);
              all.insert(newv);
            }
            else {
              sqr->add(mf, nullptr, gf);
            }
            all.insert(v0);
            all.insert(v1);
            all.insert(v2);
            all.insert(v3);
          }
        }
      }
      std::vector<GEdge *> const &e = gr->embeddedEdges();
      for(auto it = e.begin(); it != e.end(); ++it) {
        GEdge *ge = *it;
        for(std::size_t i = 0; i < ge->lines.size(); i++) {
          all.insert(ge->lines[i]->getVertex(0));
          all.insert(ge->lines[i]->getVertex(1));
        }
      }
      std::vector<GVertex *> const &v = gr->embeddedVertices();
      for(auto it = v.begin(); it != v.end(); ++it) {
        GVertex *gv = *it;
        for(std::size_t i = 0; i < gv->points.size(); i++) {
          all.insert(gv->points[i]->getVertex(0));
        }
      }
      all.insert(gr->mesh_vertices.begin(), gr->mesh_vertices.end());

      _vertices.insert(_vertices.begin(), all.begin(), all.end());
    }

    // Store all coordinates of the vertices as these will be pertubated in
    // function delaunayTriangulation
    std::map<MVertex *, SPoint3> originalCoordinates;
    boundaryRecoveryInput in;
    if(init) {
      in.tetNode = init->tetNode;
      in.tetNeighbors = init->neighbors;
    }
    else {
      for(std::size_t i = 0; i < _vertices.size(); i++) {
        MVertex *v = _vertices[i];
        originalCoordinates[v] = v->point();
      }
      std::vector<MTetrahedron *> tets;
      // will add 8 MVertices at the end of _vertices
      delaunayMeshIn3D(_vertices, tets, false, &in.tetNeighbors);
      if(Msg::GetErrorCount()) return false;
      for(std::size_t i = 0; i < _vertices.size(); i++)
        _vertices[i]->setIndex((long)i);
      in.tetNode.resize(4 * tets.size());
      for(std::size_t i = 0; i < tets.size(); i++) {
        for(int j = 0; j < 4; j++)
          in.tetNode[4 * i + j] =
            (std::uint32_t)tets[i]->getVertex(j)->getIndex();
        delete tets[i];
      }
    }

    Msg::Debug("Points have been tetrahedralized");

    const std::size_t nv = _vertices.size();
    in.xyz.resize(3 * nv);
    for(std::size_t i = 0; i < nv; i++) {
      in.xyz[3 * i] = _vertices[i]->x();
      in.xyz[3 * i + 1] = _vertices[i]->y();
      in.xyz[3 * i + 2] = _vertices[i]->z();
      // Index the vertices, starting at 1 (vertex index 0 is used as special
      // code in tetgenBR in case of failure)
      _vertices[i]->setIndex(i + 1);
    }
    std::vector<GFace *> const &f_list = gr->faces();
    std::vector<GEdge *> const &e_list = gr->embeddedEdges();
    for(auto it = f_list.begin(); it != f_list.end(); ++it) {
      GFace *gf = *it;
      for(std::size_t i = 0; i < gf->triangles.size(); i++) {
        for(int j = 0; j < 3; j++)
          in.triNode.push_back(
            (std::uint32_t)(gf->triangles[i]->getVertex(j)->getIndex() - 1));
        in.triTag.push_back(gf->tag());
      }
    }
    if(sqr) {
      std::map<MFace, GFace *, MFaceLessThan> f = sqr->getTri();
      for(auto it = f.begin(); it != f.end(); it++) {
        const MFace &mf = it->first;
        for(int j = 0; j < 3; j++)
          in.triNode.push_back((std::uint32_t)(mf.getVertex(j)->getIndex() - 1));
        in.triTag.push_back(it->second->tag());
      }
    }
    for(auto it = e_list.begin(); it != e_list.end(); ++it) {
      GEdge *ge = *it;
      for(std::size_t i = 0; i < ge->lines.size(); i++) {
        for(int j = 0; j < 2; j++)
          in.segNode.push_back(
            (std::uint32_t)(ge->lines[i]->getVertex(j)->getIndex() - 1));
        in.segTag.push_back(ge->tag());
      }
    }

    boundaryRecoveryOutput out;
    const int err = runCore(in, out);
    bool ret = false;
    if(err == 0) {
      // Write mesh into to GRegion.
      Msg::Debug("Writing to GRegion...");
      std::vector<MVertex *> extras;
      for(std::size_t k = 0; k < out.steinerType.size(); k++) {
        const double *x = &out.steinerXYZ[3 * k];
        GEdge *ge = nullptr;
        GFace *gf = nullptr;
        MVertex *v = nullptr;
        if(out.steinerType[k] == 1) {
          // Get the GEdge containing this vertex.
          for(auto it = e_list.begin(); it != e_list.end(); ++it)
            if((*it)->tag() == out.steinerSegTag[k]) ge = *it;
          if(ge) {
            MEdgeVertex *ev = new MEdgeVertex(x[0], x[1], x[2], ge, 0);
            double uu = 0;
            if(reparamMeshVertexOnEdge(ev, ge, uu)) ev->setParameter(0, uu);
            ge->mesh_vertices.push_back(ev);
            v = ev;
          }
          else if(out.steinerFaceTag[k] >= 0) {
            // We treat this vertex a facet vertex.
            for(auto it = f_list.begin(); it != f_list.end(); ++it)
              if((*it)->tag() == out.steinerFaceTag[k]) gf = *it;
          }
        }
        else if(out.steinerType[k] == 2) {
          for(auto it = f_list.begin(); it != f_list.end(); ++it)
            if((*it)->tag() == out.steinerFaceTag[k]) gf = *it;
        }
        if(!v && gf) {
          MFaceVertex *fv = new MFaceVertex(x[0], x[1], x[2], gf, 0, 0);
          SPoint2 param;
          if(reparamMeshVertexOnFace(fv, gf, param)) {
            fv->setParameter(0, param.x());
            fv->setParameter(1, param.y());
          }
          gf->mesh_vertices.push_back(fv);
          v = fv;
        }
        if(!v) {
          // Create an interior mesh vertex.
          v = new MVertex(x[0], x[1], x[2], gr);
          gr->mesh_vertices.push_back(v);
        }
        v->setIndex((long)(nv + k + 1));
        extras.push_back(v);
      }
      auto vertexOf = [&](std::uint32_t i) {
        return i < nv ? _vertices[i] : extras[i - nv];
      };

      if(!extras.empty())
        Msg::Info(" - Added %d Steiner point%s", extras.size(),
                  (extras.size() > 1) ? "s" : "");

      // the segment and surface meshes with Steiner points are re-created
      for(auto etag : out.changedEdges) {
        GEdge *ge = nullptr;
        for(auto it = e_list.begin(); it != e_list.end(); ++it)
          if((*it)->tag() == etag) ge = *it;
        if(!ge) {
          Msg::Debug("Unknown curve %d with Steiner point(s)", etag);
          continue;
        }
        Msg::Info(" - Steiner points exist on curve %d", ge->tag());
        for(std::size_t i = 0; i < ge->lines.size(); i++) delete ge->lines[i];
        ge->lines.clear();
        ge->deleteVertexArrays();
        for(std::size_t i = 0; i < out.segTag.size(); i++)
          if(out.segTag[i] == etag)
            ge->lines.push_back(new MLine(vertexOf(out.segNode[2 * i]),
                                          vertexOf(out.segNode[2 * i + 1])));
      }
      for(auto ftag : out.changedFaces) {
        GFace *gf = nullptr;
        for(auto it = f_list.begin(); it != f_list.end(); ++it)
          if((*it)->tag() == ftag) gf = *it;
        if(!gf) {
          Msg::Debug("Unknown surface %d with Steiner point(s)", ftag);
          continue;
        }
        Msg::Info(" - Steiner points exist on surface %d", gf->tag());
        for(std::size_t i = 0; i < gf->triangles.size(); i++)
          delete gf->triangles[i];
        gf->triangles.clear();
        gf->deleteVertexArrays();
        if(gf->quadrangles.size())
          Msg::Warning("Steiner points not handled for quad surface mesh");
        for(std::size_t i = 0; i < out.triTag.size(); i++)
          if(out.triTag[i] == ftag)
            gf->triangles.push_back(new MTriangle(vertexOf(out.triNode[3 * i]),
                                                  vertexOf(out.triNode[3 * i + 1]),
                                                  vertexOf(out.triNode[3 * i + 2])));
      }
      for(std::size_t t = 0; t < out.tetNode.size() / 4; t++)
        gr->tetrahedra.push_back(new MTetrahedron(
          vertexOf(out.tetNode[4 * t]), vertexOf(out.tetNode[4 * t + 1]),
          vertexOf(out.tetNode[4 * t + 2]), vertexOf(out.tetNode[4 * t + 3])));

      Msg::Info("Done reconstructing mesh (Wall %gs, CPU %gs)",
                TimeOfDay() - w_start, Cpu() - t_start);
      ret = true;
    }
    else if(err == 1) {
      Msg::Error("Out of memory in boundary mesh recovery");
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
    }

    // Put all coordinates back so they are not pertubated anymore
    // (pertubation done in delaunayTriangulation)
    for(auto vIter = originalCoordinates.begin();
        vIter != originalCoordinates.end(); ++vIter) {
      const SPoint3 &coordinates = vIter->second;
      vIter->first->setXYZ(coordinates.x(), coordinates.y(), coordinates.z());
    }
    // delete 8 new enclosing box vertices added in delaunayMeshIn3d
    if(!init && ret) {
      for(std::size_t i = _vertices.size() - 8; i < _vertices.size(); i++)
        delete _vertices[i];
    }
    return ret;
  }

  int meshGRegionBoundaryRecoveryFlat(const boundaryRecoveryInput &in,
                                      boundaryRecoveryOutput &out)
  {
    return runCore(in, out);
  }

#else

bool meshGRegionBoundaryRecovery(GRegion *gr, splitQuadRecovery *sqr,
                                 const initialTetrahedralization *init)
{
  return false;
}

int meshGRegionBoundaryRecoveryFlat(const boundaryRecoveryInput &in,
                                    boundaryRecoveryOutput &out)
{
  return -1;
}

#endif
