extern "C" {
#include "hxt_mesh.h"
#include "hxt_tools.h"
#include "hxt_omp.h"
#include "predicates.h"
}

#include <assert.h>
#include <set>
#include <vector>
#include <time.h>

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

static double orient4d(double*, double *, double *, double *, double *,
           double, double, double, double, double){ return 0.; }
#if !defined(TETLIBRARY)
#define TETLIBRARY
#endif

#include <cstdio>
#include <cstring>

#ifdef HXT_WITHOUT_GMSH
#warning "Using TetgenBR without Gmsh - please note the different licensing terms"
#include "tetgenBR.h"
#include "tetgenBR.cxx"
#else
#include "../../../../src/mesh/tetgenBR.h"
#include "../../../../src/mesh/tetgenBR.cxx"
#endif


/* just a function such that:
 * if hashLess(a,b)==true
 * then hashLess(b,a)==false
 *
 * BUT hashLess(a,b)==true and hashLess(b,c)==true
 * doesn't imply that hashLess(a,c)==true
 * and inversely if you replace true with false (no transitivity) */
static inline uint64_t hashLess(uint64_t a, uint64_t b) {
  return ((a^b)&1)^(a<b);
}


static inline int computeTetGenVersion(uint32_t v1, uint32_t* v2Choices, const int iface2){
  int i;
  for (i=0; i<3; i++) {
      if(v1==v2Choices[i]){
        break;
      }
  }
#ifndef NDEBUG
  if(i==3)
    HXT_WARNING("should never happen (file:%s line:%d)\n", __FILE__, __LINE__);
#endif

  // version%4 : corresponding face in adjacent tet
  // version/4 : which of the 3 rotation of the facet the tetrahedra has...
  return 4*i + iface2;
}


int tetgenmesh::reconstructmesh(void *p, double tol){
  HXTMesh *mesh = (HXTMesh*) p;
  in = new tetgenio();
  b = new tetgenbehavior();
  char opts[128];
  sprintf(opts, "YpeQT%gp/%g", tol, tol);
  //sprintf(opts, "YpeQT%gp/%g", CTX::instance()->mesh.toleranceInitialDelaunay,
  //        CTX::instance()->mesh.angleToleranceFacetOverlap);

  b->parse_commandline(opts);

  initializepools();

  //  printf("we have %u vertices\n", mesh->vertices.num);

  {
    point pointloop;
    REAL x, y, z;
    // Read the points.
    for (uint32_t i = 0; i < mesh->vertices.num; i++) {
      makepoint(&pointloop, UNUSEDVERTEX);
      // Read the point coordinates.
      x = pointloop[0] =mesh->vertices.coord[4*i  ];
      y = pointloop[1] =mesh->vertices.coord[4*i+1];
      z = pointloop[2] =mesh->vertices.coord[4*i+2];
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
      return HXT_STATUS_OK;
    }

    // Two identical points are distinguished by 'lengthlimit'.
    if (minedgelength == 0.0) {
      minedgelength = longest * b->epsilon;
    }
  }

  point *idx2verlist;

  // Create a map from indices to vertices.
  //  printf("we create a map from indices to vertices\n");
  makeindex2pointmap(idx2verlist);


  {
    hullsize = 0;

    // Create the tetrahedra and connect those that share a common face.
    //    printf("Connect %d tetrahedra\n", mesh->tetrahedra.num);
    std::vector<triface> ts( mesh->tetrahedra.num );
    for (uint64_t i = 0; i < mesh->tetrahedra.num; i++) {
      maketetrahedron(&ts[i]); // ts[i].ver = 11.

      uint32_t* nodes = mesh->tetrahedra.node + 4*i;
      point p[4];

      p[0] = idx2verlist[nodes[0]];
      p[1] = idx2verlist[nodes[1]];
      p[2] = idx2verlist[nodes[2]];
      if(nodes[3]==HXT_GHOST_VERTEX) {
        hullsize++;
        p[3] = dummypoint;
      }
      else {
        p[3] = idx2verlist[nodes[3]];
      }
      setvertices(ts[i], p[0], p[1], p[2], p[3]);

      #ifndef NDEBUG
      for (int j=0; j<4; j++) {
        if(mesh->tetrahedra.neigh[4*i+j]>=4*mesh->tetrahedra.num)
          return HXT_ERROR_MSG(HXT_STATUS_ERROR, "A tetrahedron is missing a neighbor");
      }
      #endif
    }

    // we can make this in parallel, iterations are totally independent
    #pragma omp parallel for
    for (uint64_t i = 0; i < mesh->tetrahedra.num; i++) {
      triface tf1 = ts[i];

      for (tf1.ver=0; tf1.ver<4; tf1.ver++){
        uint64_t neigh = mesh->tetrahedra.neigh[4*i + tf1.ver];
        uint64_t n = neigh/4;

        /* we shouldn't compute bond on both side of a facet, so we must
         * give a priority to one side.
         * simply using if(i<n) would produce load imbalance
         * as the first thread, which takes care of the first tet
         * would have much more work to do. Therefore, we use the
         * hashLess function */
        if(hashLess(i, n)) {
          int iface2 = neigh%4;

          triface tf2 = ts[n];

          // the face of the neighbor tetrahedra that is the same
          uint32_t face2[3] = {mesh->tetrahedra.node[4*n+((iface2+1)&3)],
                               mesh->tetrahedra.node[4*n+((iface2&2)^3)],
                               mesh->tetrahedra.node[4*n+((iface2+3)&2)]};

          tf2.ver = computeTetGenVersion(mesh->tetrahedra.node[4*i+((tf1.ver+1)&3)], face2, iface2);
          bond(tf1,tf2);
        }
      }
    }
  }

  {
    // Create the point-to-tet map, and clean up the temporary spaces used in each tet.
    triface tetloop;
    tetrahedrons->traversalinit();
    tetloop.tet = tetrahedrontraverse();
    while (tetloop.tet != (tetrahedron *) NULL) {
      tetrahedron tptr = encode(tetloop);
      for (tetloop.ver = 0; tetloop.ver < 4; tetloop.ver++) {
        // Create the point-to-tet map.
        setpoint2tet((point) (tetloop.tet[4 + tetloop.ver]), tptr);

        // Clean the temporary used space.
        tetloop.tet[8 + tetloop.ver] = NULL;
      }
      tetloop.tet = tetrahedrontraverse();
    }
  }

  {
    face newsh;
    face newseg;
    point p[4];
    int idx;

    for (uint64_t i=0;i<mesh->triangles.num;i++){
      for (uint64_t j = 0; j < 3; j++) {
        p[j] = idx2verlist[mesh->triangles.node[3*i+j]];
        if (pointtype(p[j]) == VOLVERTEX) {
          setpointtype(p[j], FACETVERTEX);
        }
      }

      // Create an initial triangulation.
      makeshellface(subfaces, &newsh);
      setshvertices(newsh, p[0], p[1], p[2]);
      setshellmark(newsh, mesh->triangles.color[i]);
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

    unifysegments();


    face* shperverlist;
    int* idx2shlist;
    face searchsh, neighsh;
    face segloop, checkseg;
    point checkpt;

    // Construct a map from points to subfaces.
    makepoint2submap(subfaces, idx2shlist, shperverlist);

    // Process the set of PSC edges.
    // Remeber that all segments have default marker '-1'.
    //    int COUNTER = 0;
    //   printf("Add Edges\n");
    {
      for (uint64_t i = 0; i< mesh->lines.num;i++) {
        for (uint64_t j = 0; j < 2; j++) {
          p[j] = idx2verlist[mesh->lines.node[2*i+j]];
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
         /*    point *ppt;
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
        setshellmark(newseg, mesh->lines.color[i]);
      } // i

      delete [] shperverlist;
      delete [] idx2shlist;
      insegments = subsegs->items;
    }
  }

  delete [] idx2verlist;
  clock_t t = clock();
  recoverboundary(t);
  //  printf("Carve Holes\n");
  //  carveholes();
  if (subvertstack->objects > 0l) {
    HXT_INFO("Suppressing Steiner points...");
    suppresssteinerpoints();
  }

// TODO: is this usefull ?
#if 1
  HXT_INFO("Recover Delaunay");
  recoverdelaunay();
#endif
  //  printf("Optimize final mesh\n");
  //  optimizemesh();
  {
    //    printf("Write to HXT -->\n");
    // Write mesh into to HXT.
    point p[4];
    std::set<int> /*l_faces, */l_edges;

    if (points->items > mesh->vertices.num) {
      mesh->vertices.num = points->items;
      if(mesh->vertices.num > mesh->vertices.size) {
        // HXT_CHECK( hxtAlignedFree (&mesh->vertices.coord) );
        HXT_CHECK( hxtAlignedRealloc(&mesh->vertices.coord,
                                    4*mesh->vertices.num*sizeof( double )) );
        mesh->vertices.size = mesh->vertices.num;
      }

      face parentseg, parentsh, spinsh;
      point pointloop;
      // Create newly added mesh vertices.
      // The new vertices must be added at the end of the point list.
      points->traversalinit();
      pointloop = pointtraverse();
      int reconstructingTriangularMeshIsRequired = 0;
      while (pointloop != (point) NULL) {
        if (issteinerpoint(pointloop)) {
          // Check if this Steiner point locates on boundary.
          if (pointtype(pointloop) == FREESEGVERTEX) {
            HXT_WARNING("Steiner point inserted that splits an existing edge"
                        "(boundary mesh has changed,"
                        "JF you should finish that thing and reconstruct edges as well)");
            reconstructingTriangularMeshIsRequired = 1;
            sdecode(point2sh(pointloop), parentseg);
            assert(parentseg.sh != NULL);
            l_edges.insert(shellmark(parentseg));
            mesh->vertices.coord[4*pointmark(pointloop)  ] = pointloop[0];
            mesh->vertices.coord[4*pointmark(pointloop)+1] = pointloop[1];
            mesh->vertices.coord[4*pointmark(pointloop)+2] = pointloop[2];
          }
          else if (pointtype(pointloop) == FREEFACETVERTEX) {
            //            HXT_INFO("Steiner point inserted that splits an existing facet (boundary mesh has changed, JF you should code that thing)");
            reconstructingTriangularMeshIsRequired = 1;
            sdecode(point2sh(pointloop), parentsh);
            assert(parentsh.sh != NULL);
            mesh->vertices.coord[4*pointmark(pointloop)  ] = pointloop[0];
            mesh->vertices.coord[4*pointmark(pointloop)+1] = pointloop[1];
            mesh->vertices.coord[4*pointmark(pointloop)+2] = pointloop[2];
          }
          else if (pointtype(pointloop) == FREEVOLVERTEX) {
            //            HXT_INFO("Steiner point inserted inside the volume of the mesh (not that much of a problem)");
            mesh->vertices.coord[4*pointmark(pointloop)  ] = pointloop[0];
            mesh->vertices.coord[4*pointmark(pointloop)+1] = pointloop[1];
            mesh->vertices.coord[4*pointmark(pointloop)+2] = pointloop[2];
          }
        }
        else{
          mesh->vertices.coord[4*pointmark(pointloop)  ] = pointloop[0];
          mesh->vertices.coord[4*pointmark(pointloop)+1] = pointloop[1];
          mesh->vertices.coord[4*pointmark(pointloop)+2] = pointloop[2];
        }

        pointloop = pointtraverse();
      }
      if (reconstructingTriangularMeshIsRequired) {
        // restore 2D mesh ...
        HXT_CHECK( hxtAlignedFree(&(mesh->triangles.node)));
        HXT_CHECK( hxtAlignedFree(&(mesh->triangles.color)));
        HXT_INFO("deleting %u triangles",mesh->triangles.num);
        mesh->triangles.num = 0; // firstindex; // in->firstnumber;
        {
          face subloop;
          subloop.shver = 0;
          subfaces->traversalinit();
          subloop.sh = shellfacetraverse(subfaces);
          while (subloop.sh != NULL) {
            mesh->triangles.num ++ ;
            subloop.sh = shellfacetraverse(subfaces);
          }
        }
        HXT_INFO("creating %u triangles",mesh->triangles.num);

        {
          face subloop;
          HXT_CHECK( hxtAlignedMalloc(&mesh->triangles.node,
                                     (mesh->triangles.num)*3*sizeof(uint32_t)) );
          HXT_CHECK( hxtAlignedMalloc(&mesh->triangles.color,
                                     (mesh->triangles.num)*sizeof(uint32_t)) );
          mesh->triangles.size = mesh->triangles.num;
          subloop.shver = 0;
          subfaces->traversalinit();
          subloop.sh = shellfacetraverse(subfaces);
          int iTriangle = 0;
          while (subloop.sh != NULL) {
            p[0] = sorg(subloop);
            p[1] = sdest(subloop);
            p[2] = sapex(subloop);
            mesh->triangles.node [3*iTriangle+0] = pointmark(p[0]);
            mesh->triangles.node [3*iTriangle+1] = pointmark(p[1]);
            mesh->triangles.node [3*iTriangle+2] = pointmark(p[2]);
            mesh->triangles.color[iTriangle]     = shellmark(subloop);
            iTriangle++;
            subloop.sh = shellfacetraverse(subfaces);
          }
        }
      }
    }

    // TODO: maybe fill a vector with triface and use that to convert in parallel ?
    int elementnumber = 0; // firstindex; // in->firstnumber;
    {
      // number tets
      triface tetloop;
      tetrahedrons->traversalinit();
      tetloop.tet = alltetrahedrontraverse();
      while (tetloop.tet != (tetrahedron *) NULL) {
        setelemindex(tetloop.tet, elementnumber);
        tetloop.tet = alltetrahedrontraverse();
        elementnumber++;
      }
    }

    if(elementnumber!=tetrahedrons->items)
      return HXT_ERROR_MSG(HXT_STATUS_ERROR, "This can not happen...");

    {
      // move data to HXT
      triface tetloop;
      tetrahedrons->traversalinit();
      tetloop.tet = alltetrahedrontraverse();

      // TODO: maybe free during recovery to save size...
      mesh->tetrahedra.num  = tetrahedrons->items;

      HXT_ASSERT(mesh->tetrahedra.color == NULL);

      if(mesh->tetrahedra.num > mesh->tetrahedra.size) {
        HXT_CHECK( hxtAlignedFree(&mesh->tetrahedra.node) );
        HXT_CHECK( hxtAlignedFree(&mesh->tetrahedra.neigh) );
        HXT_CHECK( hxtAlignedFree(&mesh->tetrahedra.flag) );

        HXT_CHECK( hxtAlignedMalloc(&mesh->tetrahedra.node,
                                   (mesh->tetrahedra.num)*4*sizeof(uint32_t)) );
        HXT_CHECK( hxtAlignedMalloc(&mesh->tetrahedra.neigh,
                                   (mesh->tetrahedra.num)*4*sizeof(uint64_t)) );
        HXT_CHECK( hxtAlignedMalloc(&mesh->tetrahedra.flag,
                                   (mesh->tetrahedra.num)*sizeof(uint16_t)) );

        mesh->tetrahedra.size = mesh->tetrahedra.num;
      }


      int counter = 0;
      while (tetloop.tet != (tetrahedron *) NULL) {
        tetloop.ver = 11;
        p[0] = org(tetloop);
        p[1] = dest(tetloop);
        p[2] = apex(tetloop);
        p[3] = oppo(tetloop);

        mesh->tetrahedra.flag[counter] = 0;

        for (tetloop.ver=0;tetloop.ver<4;tetloop.ver++){
          int k = tetloop.ver;
          triface N;
          fsym(tetloop, N);

          if(p[k]==dummypoint) {
            if(k!=3)
              return HXT_ERROR_MSG(HXT_STATUS_ERROR, "Error: the ghost vertex is not the third vertex");
            mesh->tetrahedra.node[4*counter+k] = HXT_GHOST_VERTEX;
          }
          else {
            mesh->tetrahedra.node[4*counter+k] = pointmark(p[k]);
            if (mesh->tetrahedra.node[4*counter+k] >= mesh->vertices.num)
              return HXT_ERROR_MSG(HXT_STATUS_ERROR, "ERROR : index %u out of range (%u)\n",
                                   mesh->tetrahedra.node[4*counter+k], mesh->vertices.num);
          }

          // set the neighbor
          uint64_t ngh =  elemindex(N.tet);
          int face = N.ver%4;

          mesh->tetrahedra.neigh[4*counter+k] = 4*ngh+face;
        }

        counter++;
        tetloop.tet = alltetrahedrontraverse();
      }
    } // mesh output
  }

  delete in;
  delete b;
  return HXT_STATUS_OK;
}

extern "C" {
  HXTStatus hxt_boundary_recovery(HXTMesh *mesh, double tol)
  {
    HXTStatus status;
    try{
      tetgenmesh *m = new tetgenmesh();
      status = (HXTStatus) m->reconstructmesh((void*)mesh, tol);
      if(status!=HXT_STATUS_OK)
        HXT_TRACE(status);
      delete m;
    }
    catch (...){
      return HXT_ERROR_MSG(HXT_STATUS_FAILED, "failed to recover constrained lines/triangles") ;
    }

    return status;
  }
}
