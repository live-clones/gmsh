#define __STDC_LIMIT_MACROS // FIXME Gmsh: this is needed so that stdint.h defines
                            // UINT_MAX & co in C++ code

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <set>
#include <vector>
#include <time.h>
#if !defined(HAVE_NO_STDINT_H)
#include <stdint.h>
#elif defined(HAVE_NO_INTPTR_T)
typedef unsigned long intptr_t;
#endif
extern "C" {
#include "hxt_mesh.h"
#include "predicates.h"
#include "hxt_api.h"
#include "hxt_boundary_recovery.h"
}

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
#include "tetgenBR.h"
#include "tetgenBR.cxx"

// int _edges [12][2] = {{3,2},{3,0},{1,0},{1,2},{2,1},{0,2},{0,3},{2,0},{1,3},{2,3},{3,1},{0,1}};

// int computeTetGenVersion (const int iface1, uint32_t *v1,
//         uint32_t *v2){

//   uint32_t i1 = v1[_edges[iface1][0]];
//   uint32_t i2 = v1[_edges[iface1][1]];
//   for (int i=0;i<12;i++){
//     if (i2 == v2[_edges[i][0]] &&
//   i1 == v2[_edges[i][1]]) return i;
//   }
//   printf("oulalalala\n");
//   return -1;

// }

static inline int computeTetGenVersion2(uint32_t v1, uint32_t* v2Choices, const int iface2){
  int i;
  for (i=0; i<3; i++) {
      if(v1==v2Choices[i]){
        break;
      }
  }
#ifdef DEBUG
  if(i==3)
    HXT_WARNING("should never happen (file:%s line:%s)\n", __FILE__, __LINE__);
#endif

  return 4*i + iface2;
}


bool tetgenmesh::reconstructmesh(void *p){
  HXTMesh *mesh = (HXTMesh*) p;
  in = new tetgenio();
  b = new tetgenbehavior();
  char opts[128];
  sprintf(opts, "YpeQT%g", 1.e-12);
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
      return true;
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
  // 'idx2verlist' has length 'in->numberofpoints + 1'.
  if (in->firstnumber == 1) {
    idx2verlist[0] = dummypoint; // Let 0th-entry be dummypoint.
  }
  {
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

    // Allocate an array that maps each vertex to its adjacent tets.
    //    printf("Allocate an array that maps each vertex to its adjacent tets\n");
    ver2tetarray = new tetrahedron[mesh->vertices.num + 1];
    for (unsigned int i = in->firstnumber; i < mesh->vertices.num + in->firstnumber; i++) {
      setpointtype(idx2verlist[i], VOLVERTEX); // initial type.
      ver2tetarray[i] = NULL;
    }


    // Create the tetrahedra and connect those that share a common face.
    //    printf("Connect %d tetrahedra\n", mesh->tetrahedra.num);

    const int perm[4] = {1,0,2,3};
    std::vector<triface> ts( mesh->tetrahedra.num );
    for (uint64_t i = 0; i < mesh->tetrahedra.num; i++) {
      if (mesh->tetrahedra.node[4*i+3] == HXT_GHOST_VERTEX)
        continue;

      maketetrahedron(&tetloop); // tetloop.ver = 11.
      for (uint64_t j = 0; j < 4; j++) {
        p[j] = idx2verlist[mesh->tetrahedra.node[j+4*i]];
      }
      setvertices(tetloop, p[perm[0]], p[perm[1]], p[perm[2]], p[perm[3]]);
      ts[i] = tetloop;
    }

    for (uint64_t i = 0; i < mesh->tetrahedra.num; i++) {
      if (mesh->tetrahedra.node[4*i+3] != HXT_GHOST_VERTEX){

        for (int iface1=0; iface1<4; iface1++){
          uint64_t neigh = mesh->tetrahedra.neigh[4*i + perm[iface1]];
          // p[1] and p[0] have been exchanged
          if(neigh!=HXT_NO_ADJACENT) {
            uint64_t n = neigh >> 2;
            int iface2 = perm[neigh&3];

            if (mesh->tetrahedra.node[4*n+3] != HXT_GHOST_VERTEX){
              triface tf1 = ts[i];
              triface tf2 = ts[n];
              tf1.ver = iface1;

              // the face of the neighbor tetrahedra that is the same
              uint32_t face2[3] = {mesh->tetrahedra.node[4*n+perm[(iface2+1)&3]],
                                   mesh->tetrahedra.node[4*n+perm[((iface2&2)^3)]],
                                   mesh->tetrahedra.node[4*n+perm[((iface2+3)&2)]]};

              tf2.ver = computeTetGenVersion2 (mesh->tetrahedra.node[4*i+perm[(iface1+1)&3]], face2, iface2);
              bond(tf1,tf2);
            }
          }
        }
      }
    }

    // printf("Create hull tets, create the point-to-tet map, and clean up the temporary spaces used in each tet\n");
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
              if (face2.tet == NULL)
                break;

              esymself(face2);

              if (apex(face2) == dummypoint)
                break;

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
      setshellmark(newsh, mesh->triangles.colors[i]);
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
        setshellmark(newseg, mesh->lines.colors[i]);
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
            int ftag = shellmark(parentsh);
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
        HXT_CHECK( hxtAlignedFree(&(mesh->triangles.colors)));
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
          if (mesh->triangles.node == NULL)
            return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
          HXT_CHECK( hxtAlignedMalloc(&mesh->triangles.colors,
                                     (mesh->triangles.num)*sizeof(uint16_t)) );
          if (mesh->triangles.colors == NULL)
            return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
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
            mesh->triangles.colors[iTriangle]     = shellmark(subloop);
            iTriangle++;
            subloop.sh = shellfacetraverse(subfaces);
          }
        }
      }
    }

    int elementnumber = 1; // firstindex; // in->firstnumber;
    {
      // number tets
      triface tetloop;
      tetrahedrons->traversalinit();
      tetloop.tet = tetrahedrontraverse();
      while (tetloop.tet != (tetrahedron *) NULL) {
        setelemindex(tetloop.tet, elementnumber);
        tetloop.tet = tetrahedrontraverse();
        elementnumber++;
      }
    }

    {
      // move data to HXT
      triface tetloop;
      tetrahedrons->traversalinit();
      tetloop.tet = tetrahedrontraverse();
      mesh->tetrahedra.num  = elementnumber-1;
      if(mesh->tetrahedra.num > mesh->tetrahedra.size) {
        HXT_CHECK( hxtAlignedFree(&mesh->tetrahedra.node) );
        HXT_CHECK( hxtAlignedFree(&mesh->tetrahedra.neigh) );
        HXT_CHECK( hxtAlignedFree(&mesh->tetrahedra.colors) );
        HXT_CHECK( hxtAlignedFree(&mesh->tetrahedra.flag) );

        HXT_CHECK( hxtAlignedMalloc(&mesh->tetrahedra.node,
                                   (mesh->tetrahedra.num)*4*sizeof(uint32_t)) );
        HXT_CHECK( hxtAlignedMalloc(&mesh->tetrahedra.neigh,
                                   (mesh->tetrahedra.num)*4*sizeof(uint64_t)) );
        HXT_CHECK( hxtAlignedMalloc(&mesh->tetrahedra.colors,
                                   (mesh->tetrahedra.num)*sizeof(uint16_t)) );
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
        triface E, N[4];
        E = tetloop;
        for (E.ver = 0; E.ver < 4; E.ver++) {
          fsym(E, N[E.ver]);
        }
        int orderHXT[4] = {1,0,2,3};
        mesh->tetrahedra.colors[counter] = 0;
        for (int k=0;k<4;k++){
          mesh->tetrahedra.node[4*counter+k] = pointmark(p[orderHXT[k]]);
          if (mesh->tetrahedra.node[4*counter+k] >= mesh->vertices.num)
            HXT_WARNING("ERROR : index %u out of range (%u)\n",mesh->tetrahedra.node[4*counter+k],mesh->vertices.num);
        }
        for (int i=0;i<4;i++){
          int ngh =  elemindex(N[orderHXT[i]].tet);
          if (ngh) {
            //      mesh->tetrahedra.neigh[4*counter+i] = 4*(elemindex(N[i].tet)-1)+i;
          }
          else{
            //      mesh->tetrahedra.neigh[4*counter+i] = HXT_NO_ADJACENT;
          }
        }
        //  printf("%d --> %d %d %d %d\n", counter,  pointmark(p[0]),pointmark(p[1]),pointmark(p[2]),pointmark(p[3]));

        counter++;
        tetloop.tet = tetrahedrontraverse();
      }
    } // mesh output
  }

  delete in;
  delete b;
  return true;
}

extern "C" {
  HXTStatus hxt_boundary_recovery(HXTMesh *mesh)
  {
    bool ret = false;
    try{
      tetgenmesh *m = new tetgenmesh();
      ret = m->reconstructmesh((void*)mesh);
      delete m;
      return HXT_STATUS_OK ;
    }
    catch (...){
      return HXT_ERROR_MSG(HXT_STATUS_FAILED, "failed to recover constrained lines/triangles") ;
    }
  }
}
