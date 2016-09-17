// Gmsh - Copyright (C) 1997-2016 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include <stdlib.h>
#include <vector>
// general
#include "OS.h"
#include "Geo.h"
#include "Context.h"
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "fullMatrix.h"
// mesh
#include "meshGFaceOptimize.h"
#include "meshGRegionBoundaryRecovery.h"
#include "meshGRegionDelaunayInsertion.h"
#include "meshGRegionRelocateVertex.h"
#include "delaunay3d.h"
// model
#include "GModel.h"
#include "GRegion.h"
#include "GFace.h"
#include "discreteFace.h"
#include "discreteRegion.h"
// elements
#include "MLine.h"
#include "MTriangle.h"
#include "MTetrahedron.h"
#include "MPyramid.h"
#include "MPrism.h"
#include "MHexahedron.h"

// triangles are defining the boundary
// internal points are allowed
// This has been done for HEXTREME
GRegion * createDiscreteRegionFromRawData(GModel *gm, fullMatrix<double> &pts,
                                          fullMatrix<int> &triangles)
{
  GRegion *gr = new discreteRegion(gm, NEWREG());
  GFace *gf = new discreteFace(gm, NEWREG());
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
      MVertex *v = new MFaceVertex(pts(i,0), pts(i,1), pts(i,2), gr, 0, 0);
      gr->mesh_vertices.push_back(v);
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

  delaunayTriangulation(1, 1, vs, gr->tetrahedra);

  return gr;
}

GRegion *createTetrahedralMesh(GModel *gm, fullMatrix<double> &pts,
                               fullMatrix<int> &triangles)
{
  GRegion *gr = createDiscreteRegionFromRawData(gm, pts, triangles);
  try{
    meshGRegionBoundaryRecovery(gr);
  }
  catch(int err){
    if(err == 3){
      Msg::Warning("Self-intersecting surface mesh: TODO!");
    }
    else{
      Msg::Error("Could not recover boundary: error %d", err);
    }
  }
  return gr;
}
