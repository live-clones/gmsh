// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include <stdlib.h>
#include <vector>
#include "GmshMessage.h"
#include "fullMatrix.h"
#include "meshGFaceOptimize.h"
#include "meshGRegionBoundaryRecovery.h"
#include "meshGRegionDelaunayInsertion.h"
#include "meshGRegionRelocateVertex.h"
#include "delaunay3d.h"
#include "GModel.h"
#include "GRegion.h"
#include "GFace.h"
#include "discreteFace.h"
#include "discreteRegion.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MTetrahedron.h"
#include "MPyramid.h"
#include "MPrism.h"
#include "MHexahedron.h"

// Recursive function to generate all combinations of 4 indices between start
// and end indices included
// Jeanne - HEXTREME
void combination_of_4( int combination[4], int start, int end, int index,
  const std::vector<MVertex*>& vertices, std::vector<MTetrahedron*>& tets)
{
  if (index == 4 ) {
    // Create the tet and get out
    MVertex* v1 = vertices[combination[0]];
    MVertex* v2 = vertices[combination[1]];
    MVertex* v3 = vertices[combination[2]];
    MVertex* v4 = vertices[combination[3]];
    MTetrahedron* tet = new MTetrahedron(v1, v2, v3, v4);
    tets.push_back(tet);
    return;
  }
  for (int i = start; i <= end+1 -(4-index); i++) {
    combination[index] = i;
    combination_of_4(combination, i+1, end, index+1, vertices, tets);
  }
}

// Fill a region with all possible tets genereated from the
// combination of points assigned to it
// Jeanne - HEXTREME
void create_all_possible_tets(GRegion* region, const std::vector<MVertex*>& vertices)
{
  unsigned int nb_points = vertices.size();

  int combinaison[4];
  std::vector<MTetrahedron*> tets;
  combination_of_4(combinaison, 0, nb_points - 1, 0, vertices, tets);
  std::cout << " Number of tets created - all possible combinations - "
            << tets.size() << std::endl;

  for (unsigned int i = 0; i < tets.size(); ++i) {
    region->addTetrahedron(tets[i]);
  }
}

// triangles are defining the boundary
// internal points are allowed
// This has been done for HEXTREME
GRegion * createDiscreteRegionFromRawData(GModel *gm, fullMatrix<double> &pts,
                                          fullMatrix<int> &triangles, bool all_tets)
{
  GRegion *gr = new discreteRegion(gm, gm->getMaxElementaryNumber(3) + 1);
  GFace *gf = new discreteFace(gm, gm->getMaxElementaryNumber(2) + 1);
  gm->add(gr);
  gm->add(gf);
  std::list<GFace*> faces; faces.push_back(gf); gr->set(faces);
  // get boundary nodes
  std::set<int> bnd;
  unsigned int nbTriangles = triangles.size1();
  unsigned int nbPts = pts.size1();
  for (unsigned int i = 0; i < nbTriangles; i++) {
    bnd.insert(triangles(i, 0));
    bnd.insert(triangles(i, 1));
    bnd.insert(triangles(i, 2));
  }
  // create points
  std::vector<MVertex*> vs(nbPts);
  for (unsigned int i = 0; i < nbPts; i++) {
    if (bnd.find(i) == bnd.end()){
      MVertex *v = new MVertex(pts(i,0), pts(i,1), pts(i,2), gr);
      gr->mesh_vertices.push_back(v);
      vs[i] = v;
    }
    else {
      MVertex *v = new MFaceVertex(pts(i,0), pts(i,1), pts(i,2), gf, 0, 0);
      gf->mesh_vertices.push_back(v);
      vs[i] = v;
    }
  }
  // create triangles
  for (unsigned int i = 0 ; i < nbTriangles; i++) {
    int i0 = triangles(i,0);
    int i1 = triangles(i,1);
    int i2 = triangles(i,2);
    MTriangle *t = new MTriangle(vs[i0], vs[i1], vs[i2]);
    gf->triangles.push_back(t);
  }

  // delaunayTriangulation(1, 1, vs, gr->tetrahedra);
  // tetrahedralization is done when recovering the boundary

  // create all tets
  if (all_tets) {
    create_all_possible_tets(gr, vs);
  }

  return gr;
}

GRegion *createTetrahedralMesh(GModel *gm, fullMatrix<double> &pts,
                               fullMatrix<int> &triangles, bool all_tets)
{
  GRegion *gr = createDiscreteRegionFromRawData(gm, pts, triangles, all_tets);

  if (!all_tets){
    try {
      meshGRegionBoundaryRecovery(gr);
    }
    catch (int err) {
      if (err == 3) {
        Msg::Warning("Self-intersecting surface mesh: TODO!");
      }
      else {
        Msg::Error("Could not recover boundary: error %d", err);
      }
    }
  }
  return gr;
}
