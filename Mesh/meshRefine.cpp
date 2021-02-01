// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Brian Helenbrook
//

#include "GModel.h"
#include "HighOrder.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "GmshMessage.h"
#include "OS.h"
#include "meshGFaceOptimize.h"
#include "Generator.h"
#include "Context.h"

typedef std::map<MFace, std::vector<MVertex *>, MFaceLessThan> faceContainer;

void subdivide_pyramid(MElement *element, GRegion *gr,
                       faceContainer &faceVertices,
                       std::vector<MHexahedron *> &dwarfs88);

struct MVertexPtrLessThanParam {
  bool operator()(const MVertex *v1, const MVertex *v2) const
  {
    double u1 = 0., u2 = 1.;
    v1->getParameter(0, u1);
    v2->getParameter(0, u2);
    return u1 < u2;
  }
};

// Set BM data on vertex
static void setBLData(MVertex *v)
{
  switch(v->onWhat()->dim()) {
  case 1: {
    MEdgeVertex *ve = dynamic_cast<MEdgeVertex *>(v);
    if(ve) ve->bl_data = new MVertexBoundaryLayerData();
    break;
  }
  case 2: {
    MFaceVertex *vf = dynamic_cast<MFaceVertex *>(v);
    if(vf) vf->bl_data = new MVertexBoundaryLayerData();
    break;
  }
  }
}

// If all low-order nodes in are marked as BL, then mark high-order nodes as BL
// (only works in 2D)
static bool setBLData(MElement *el)
{
  // Check whether all low-order nodes are marked as BL nodes (only works in 2D)
  for(std::size_t i = 0; i < el->getNumPrimaryVertices(); i++) {
    MVertex *v = el->getVertex(i);
    bool isBL = false;
    switch(v->onWhat()->dim()) {
    case 0: isBL = true; break;
    case 1: {
      MEdgeVertex *ve = dynamic_cast<MEdgeVertex *>(v);
      if(ve && ve->bl_data) isBL = true;
      break;
    }
    case 2: {
      MFaceVertex *vf = dynamic_cast<MFaceVertex *>(v);
      if(vf && vf->bl_data) isBL = true;
      break;
    }
    }
    if(!isBL) return false;
  }
  // Mark high-order nodes as BL nodes (only works in 2D)
  for(std::size_t i = el->getNumPrimaryVertices(); i < el->getNumVertices();
      i++)
    setBLData(el->getVertex(i));
  return true;
}

static void Subdivide(GEdge *ge)
{
  std::vector<MLine *> lines2;
  for(std::size_t i = 0; i < ge->lines.size(); i++) {
    MLine *l = ge->lines[i];
    if(l->getNumVertices() == 3) {
      lines2.push_back(new MLine(l->getVertex(0), l->getVertex(2)));
      lines2.push_back(new MLine(l->getVertex(2), l->getVertex(1)));
      setBLData(l);
    }
    delete l;
  }
  ge->lines = lines2;

  // 2nd order meshing destroyed the ordering of the vertices on the edge
  std::sort(ge->mesh_vertices.begin(), ge->mesh_vertices.end(),
            MVertexPtrLessThanParam());
  for(std::size_t i = 0; i < ge->mesh_vertices.size(); i++)
    ge->mesh_vertices[i]->setPolynomialOrder(1);
  ge->correspondingVertices.insert(ge->correspondingHighOrderVertices.begin(),
                                   ge->correspondingHighOrderVertices.end());
  ge->correspondingHighOrderVertices.clear();
  ge->deleteVertexArrays();
}

static void Subdivide(GFace *gf, bool splitIntoQuads, bool splitIntoHexas,
                      faceContainer &faceVertices, bool linear)
{
  if(!splitIntoQuads && !splitIntoHexas) {
    std::vector<MTriangle *> triangles2;
    for(std::size_t i = 0; i < gf->triangles.size(); i++) {
      MTriangle *t = gf->triangles[i];
      if(t->getNumVertices() == 6) {
        triangles2.push_back(
          new MTriangle(t->getVertex(0), t->getVertex(3), t->getVertex(5)));
        triangles2.push_back(
          new MTriangle(t->getVertex(3), t->getVertex(4), t->getVertex(5)));
        triangles2.push_back(
          new MTriangle(t->getVertex(3), t->getVertex(1), t->getVertex(4)));
        triangles2.push_back(
          new MTriangle(t->getVertex(5), t->getVertex(4), t->getVertex(2)));
        setBLData(t);
      }
      delete t;
    }
    gf->triangles = triangles2;
  }

  std::vector<MQuadrangle *> quadrangles2;
  for(std::size_t i = 0; i < gf->quadrangles.size(); i++) {
    MQuadrangle *q = gf->quadrangles[i];
    if(q->getNumVertices() == 9) {
      quadrangles2.push_back(new MQuadrangle(q->getVertex(0), q->getVertex(4),
                                             q->getVertex(8), q->getVertex(7)));
      quadrangles2.push_back(new MQuadrangle(q->getVertex(4), q->getVertex(1),
                                             q->getVertex(5), q->getVertex(8)));
      quadrangles2.push_back(new MQuadrangle(q->getVertex(8), q->getVertex(5),
                                             q->getVertex(2), q->getVertex(6)));
      quadrangles2.push_back(new MQuadrangle(q->getVertex(7), q->getVertex(8),
                                             q->getVertex(6), q->getVertex(3)));
      setBLData(q);
    }
    delete q;
  }
  if(splitIntoQuads || splitIntoHexas) {
    for(std::size_t i = 0; i < gf->triangles.size(); i++) {
      MTriangle *t = gf->triangles[i];
      if(t->getNumVertices() == 6) {
        MVertex *newv;
        if(linear) {
          SPoint3 ptx;
          t->pnt(1. / 3., 1. / 3., 0., ptx); // is the barycenter
          newv = new MVertex(ptx.x(), ptx.y(), ptx.z(), gf);
        }
        else {
          SPoint3 ctr = t->barycenter();
          const double pp[2] = {0.5, 0.5}; // should be improved...
          GPoint gp = gf->closestPoint(ctr, pp); // orthogonal projection
          newv = new MFaceVertex(gp.x(), gp.y(), gp.z(), gf, gp.u(), gp.v());
        }
        gf->mesh_vertices.push_back(newv);
        if(splitIntoHexas) faceVertices[t->getFace(0)].push_back(newv);
        quadrangles2.push_back(new MQuadrangle(t->getVertex(0), t->getVertex(3),
                                               newv, t->getVertex(5)));
        quadrangles2.push_back(new MQuadrangle(t->getVertex(3), t->getVertex(1),
                                               t->getVertex(4), newv));
        quadrangles2.push_back(new MQuadrangle(
          t->getVertex(5), newv, t->getVertex(4), t->getVertex(2)));
        if(setBLData(t)) setBLData(newv);
        delete t;
      }
    }
    gf->triangles.clear();
  }
  gf->quadrangles = quadrangles2;

  for(std::size_t i = 0; i < gf->mesh_vertices.size(); i++)
    gf->mesh_vertices[i]->setPolynomialOrder(1);
  gf->correspondingVertices.insert(gf->correspondingHighOrderVertices.begin(),
                                   gf->correspondingHighOrderVertices.end());
  gf->correspondingHighOrderVertices.clear();
  gf->deleteVertexArrays();
}

static void Subdivide(GRegion *gr, bool splitIntoHexas,
                      faceContainer &faceVertices)
{
  if(!splitIntoHexas) {
    // Split tets into other tets
    std::vector<MTetrahedron *> tetrahedra2;
    for(std::size_t i = 0; i < gr->tetrahedra.size(); i++) {
      MTetrahedron *t = gr->tetrahedra[i];
      // Use a template that maximizes the quality, which is a modification of
      // Algorithm RedRefinement3D in: Bey, Jürgen. "Simplicial grid refinement:
      // on Freudenthal's algorithm and the optimal number of congruence
      // classes." Numerische Mathematik 85.1 (2000): 1-29. Contributed by Jose
      // Paulo Moitinho de Almeida, April 2019.
      if(t->getNumVertices() == 10) {
        tetrahedra2.push_back(new MTetrahedron(
          t->getVertex(0), t->getVertex(4), t->getVertex(6), t->getVertex(7)));
        tetrahedra2.push_back(new MTetrahedron(
          t->getVertex(4), t->getVertex(1), t->getVertex(5), t->getVertex(9)));
        tetrahedra2.push_back(new MTetrahedron(
          t->getVertex(6), t->getVertex(5), t->getVertex(2), t->getVertex(8)));
        tetrahedra2.push_back(new MTetrahedron(
          t->getVertex(7), t->getVertex(9), t->getVertex(8), t->getVertex(3)));
        tetrahedra2.push_back(new MTetrahedron(
          t->getVertex(4), t->getVertex(6), t->getVertex(7), t->getVertex(9)));
        tetrahedra2.push_back(new MTetrahedron(
          t->getVertex(4), t->getVertex(9), t->getVertex(5), t->getVertex(6)));
        tetrahedra2.push_back(new MTetrahedron(
          t->getVertex(6), t->getVertex(7), t->getVertex(9), t->getVertex(8)));
        tetrahedra2.push_back(new MTetrahedron(
          t->getVertex(6), t->getVertex(8), t->getVertex(9), t->getVertex(5)));
        setBLData(t);
      }
      delete t;
    }
    gr->tetrahedra = tetrahedra2;
  }

  // Split hexes into other hexes.
  std::vector<MHexahedron *> hexahedra2;
  for(std::size_t i = 0; i < gr->hexahedra.size(); i++) {
    MHexahedron *h = gr->hexahedra[i];
    if(h->getNumVertices() == 27) {
      hexahedra2.push_back(new MHexahedron(h->getVertex(0), h->getVertex(8),
                                           h->getVertex(20), h->getVertex(9),
                                           h->getVertex(10), h->getVertex(21),
                                           h->getVertex(26), h->getVertex(22)));
      hexahedra2.push_back(new MHexahedron(
        h->getVertex(10), h->getVertex(21), h->getVertex(26), h->getVertex(22),
        h->getVertex(4), h->getVertex(16), h->getVertex(25), h->getVertex(17)));
      hexahedra2.push_back(new MHexahedron(h->getVertex(8), h->getVertex(1),
                                           h->getVertex(11), h->getVertex(20),
                                           h->getVertex(21), h->getVertex(12),
                                           h->getVertex(23), h->getVertex(26)));
      hexahedra2.push_back(new MHexahedron(
        h->getVertex(21), h->getVertex(12), h->getVertex(23), h->getVertex(26),
        h->getVertex(16), h->getVertex(5), h->getVertex(18), h->getVertex(25)));
      hexahedra2.push_back(new MHexahedron(h->getVertex(9), h->getVertex(20),
                                           h->getVertex(13), h->getVertex(3),
                                           h->getVertex(22), h->getVertex(26),
                                           h->getVertex(24), h->getVertex(15)));
      hexahedra2.push_back(new MHexahedron(
        h->getVertex(22), h->getVertex(26), h->getVertex(24), h->getVertex(15),
        h->getVertex(17), h->getVertex(25), h->getVertex(19), h->getVertex(7)));
      hexahedra2.push_back(new MHexahedron(h->getVertex(20), h->getVertex(11),
                                           h->getVertex(2), h->getVertex(13),
                                           h->getVertex(26), h->getVertex(23),
                                           h->getVertex(14), h->getVertex(24)));
      hexahedra2.push_back(new MHexahedron(
        h->getVertex(26), h->getVertex(23), h->getVertex(14), h->getVertex(24),
        h->getVertex(25), h->getVertex(18), h->getVertex(6), h->getVertex(19)));
      setBLData(h);
    }
    delete h;
  }

  // Split tets into other hexes.
  if(splitIntoHexas) {
    for(std::size_t i = 0; i < gr->tetrahedra.size(); i++) {
      MTetrahedron *t = gr->tetrahedra[i];
      if(t->getNumVertices() == 10) {
        std::vector<MVertex *> newv;
        for(int j = 0; j < t->getNumFaces(); j++) {
          MFace face = t->getFace(j);
          auto fIter = faceVertices.find(face);
          if(fIter != faceVertices.end()) { newv.push_back(fIter->second[0]); }
          else {
            SPoint3 pc = face.barycenter();
            newv.push_back(new MVertex(pc.x(), pc.y(), pc.z(), gr));
            faceVertices[face].push_back(newv.back());
            gr->mesh_vertices.push_back(newv.back());
          }
        }
        SPoint3 pc = t->barycenter();
        newv.push_back(new MVertex(pc.x(), pc.y(), pc.z(), gr));
        gr->mesh_vertices.push_back(newv.back());
        hexahedra2.push_back(new MHexahedron(
          t->getVertex(0), t->getVertex(4), newv[0], t->getVertex(6),
          t->getVertex(7), newv[1], newv[4], newv[2]));
        hexahedra2.push_back(
          new MHexahedron(t->getVertex(4), t->getVertex(1), t->getVertex(5),
                          newv[0], newv[1], t->getVertex(9), newv[3], newv[4]));
        hexahedra2.push_back(new MHexahedron(
          t->getVertex(6), newv[0], t->getVertex(5), t->getVertex(2), newv[2],
          newv[4], newv[3], t->getVertex(8)));
        hexahedra2.push_back(new MHexahedron(
          t->getVertex(3), t->getVertex(9), newv[1], t->getVertex(7),
          t->getVertex(8), newv[3], newv[4], newv[2]));
        if(setBLData(t)) {
          setBLData(newv[0]);
          setBLData(newv[1]);
          setBLData(newv[2]);
          setBLData(newv[3]);
          setBLData(newv[4]);
        }
        delete t;
      }
    }
    gr->tetrahedra.clear();

    for(std::size_t i = 0; i < gr->prisms.size(); i++) {
      MPrism *p = gr->prisms[i];
      if(p->getNumVertices() == 18) {
        std::vector<MVertex *> newv;
        for(int j = 0; j < 2; j++) {
          MFace face = p->getFace(j);
          auto fIter = faceVertices.find(face);
          if(fIter != faceVertices.end()) { newv.push_back(fIter->second[0]); }
          else {
            SPoint3 pc = face.barycenter();
            newv.push_back(new MVertex(pc.x(), pc.y(), pc.z(), gr));
            faceVertices[face].push_back(newv.back());
            gr->mesh_vertices.push_back(newv.back());
          }
        }
        SPoint3 pc = p->barycenter();
        newv.push_back(new MVertex(pc.x(), pc.y(), pc.z(), gr));
        gr->mesh_vertices.push_back(newv.back());
        hexahedra2.push_back(new MHexahedron(
          p->getVertex(0), p->getVertex(6), newv[0], p->getVertex(7),
          p->getVertex(8), p->getVertex(15), newv[2], p->getVertex(16)));
        hexahedra2.push_back(new MHexahedron(
          p->getVertex(1), p->getVertex(9), newv[0], p->getVertex(6),
          p->getVertex(10), p->getVertex(17), newv[2], p->getVertex(15)));
        hexahedra2.push_back(new MHexahedron(
          p->getVertex(2), p->getVertex(7), newv[0], p->getVertex(9),
          p->getVertex(11), p->getVertex(16), newv[2], p->getVertex(17)));
        hexahedra2.push_back(new MHexahedron(
          p->getVertex(8), p->getVertex(15), newv[2], p->getVertex(16),
          p->getVertex(3), p->getVertex(12), newv[1], p->getVertex(13)));
        hexahedra2.push_back(new MHexahedron(
          p->getVertex(10), p->getVertex(17), newv[2], p->getVertex(15),
          p->getVertex(4), p->getVertex(14), newv[1], p->getVertex(12)));
        hexahedra2.push_back(new MHexahedron(
          p->getVertex(11), p->getVertex(16), newv[2], p->getVertex(17),
          p->getVertex(5), p->getVertex(13), newv[1], p->getVertex(14)));
        if(setBLData(p)) {
          setBLData(newv[0]);
          setBLData(newv[1]);
          setBLData(newv[2]);
        }
      }
    }
    gr->prisms.clear();

    // Yamakawa subdivision of a pyramid into 88 hexes (thanks to Tristan
    // Carrier Baudouin!)
    std::vector<MHexahedron *> dwarfs88;
    for(std::size_t i = 0; i < gr->pyramids.size(); i++) {
      MPyramid *p = gr->pyramids[i];
      if(p->getNumVertices() == 14) {
        subdivide_pyramid(p, gr, faceVertices, dwarfs88);
        for(int j = 0; j < 88; j++) hexahedra2.push_back(dwarfs88[j]);
      }
    }
    gr->pyramids.clear();
  }
  gr->hexahedra = hexahedra2;

  std::vector<MPrism *> prisms2;
  for(std::size_t i = 0; i < gr->prisms.size(); i++) {
    MPrism *p = gr->prisms[i];
    if(p->getNumVertices() == 18) {
      prisms2.push_back(new MPrism(p->getVertex(0), p->getVertex(6),
                                   p->getVertex(7), p->getVertex(8),
                                   p->getVertex(15), p->getVertex(16)));
      prisms2.push_back(new MPrism(p->getVertex(8), p->getVertex(15),
                                   p->getVertex(16), p->getVertex(3),
                                   p->getVertex(12), p->getVertex(13)));
      prisms2.push_back(new MPrism(p->getVertex(6), p->getVertex(1),
                                   p->getVertex(9), p->getVertex(15),
                                   p->getVertex(10), p->getVertex(17)));
      prisms2.push_back(new MPrism(p->getVertex(15), p->getVertex(10),
                                   p->getVertex(17), p->getVertex(12),
                                   p->getVertex(4), p->getVertex(14)));
      prisms2.push_back(new MPrism(p->getVertex(7), p->getVertex(9),
                                   p->getVertex(2), p->getVertex(16),
                                   p->getVertex(17), p->getVertex(11)));
      prisms2.push_back(new MPrism(p->getVertex(16), p->getVertex(17),
                                   p->getVertex(11), p->getVertex(13),
                                   p->getVertex(14), p->getVertex(5)));
      prisms2.push_back(new MPrism(p->getVertex(9), p->getVertex(7),
                                   p->getVertex(6), p->getVertex(17),
                                   p->getVertex(16), p->getVertex(15)));
      prisms2.push_back(new MPrism(p->getVertex(17), p->getVertex(16),
                                   p->getVertex(15), p->getVertex(14),
                                   p->getVertex(13), p->getVertex(12)));
      setBLData(p);
    }
    delete p;
  }
  gr->prisms = prisms2;

  std::vector<MPyramid *> pyramids2;
  for(std::size_t i = 0; i < gr->pyramids.size(); i++) {
    if(splitIntoHexas) {
      Msg::Error("Full hexahedron subdivision is not implemented for pyramids");
      return;
    }
    MPyramid *p = gr->pyramids[i];
    if(p->getNumVertices() == 14) {
      // Base
      pyramids2.push_back(new MPyramid(p->getVertex(0), p->getVertex(5),
                                       p->getVertex(13), p->getVertex(6),
                                       p->getVertex(7)));
      pyramids2.push_back(new MPyramid(p->getVertex(5), p->getVertex(1),
                                       p->getVertex(8), p->getVertex(13),
                                       p->getVertex(9)));
      pyramids2.push_back(new MPyramid(p->getVertex(13), p->getVertex(8),
                                       p->getVertex(2), p->getVertex(10),
                                       p->getVertex(11)));
      pyramids2.push_back(new MPyramid(p->getVertex(6), p->getVertex(13),
                                       p->getVertex(10), p->getVertex(3),
                                       p->getVertex(12)));

      // Split remaining into tets
      // Top
      gr->tetrahedra.push_back((new MTetrahedron(
        p->getVertex(7), p->getVertex(9), p->getVertex(12), p->getVertex(4))));
      gr->tetrahedra.push_back((new MTetrahedron(
        p->getVertex(9), p->getVertex(11), p->getVertex(12), p->getVertex(4))));

      // Upside down one
      gr->tetrahedra.push_back(
        (new MTetrahedron(p->getVertex(9), p->getVertex(12), p->getVertex(11),
                          p->getVertex(13))));
      gr->tetrahedra.push_back((new MTetrahedron(
        p->getVertex(7), p->getVertex(12), p->getVertex(9), p->getVertex(13))));

      // Four tets around bottom perimeter
      gr->tetrahedra.push_back((new MTetrahedron(
        p->getVertex(7), p->getVertex(9), p->getVertex(5), p->getVertex(13))));
      gr->tetrahedra.push_back((new MTetrahedron(
        p->getVertex(9), p->getVertex(11), p->getVertex(8), p->getVertex(13))));
      gr->tetrahedra.push_back(
        (new MTetrahedron(p->getVertex(12), p->getVertex(10), p->getVertex(11),
                          p->getVertex(13))));
      gr->tetrahedra.push_back((new MTetrahedron(
        p->getVertex(7), p->getVertex(6), p->getVertex(12), p->getVertex(13))));
      setBLData(p);
    }
    delete p;
  }
  gr->pyramids = pyramids2;

  for(std::size_t i = 0; i < gr->mesh_vertices.size(); i++)
    gr->mesh_vertices[i]->setPolynomialOrder(1);
  gr->deleteVertexArrays();
}

void RefineMesh(GModel *m, bool linear, bool splitIntoQuads,
                bool splitIntoHexas)
{
  Msg::StatusBar(true, "Refining mesh...");
  double t1 = Cpu(), w1 = TimeOfDay();

  // Create 2nd order mesh (using "2nd order complete" elements) to
  // generate vertex positions
  SetOrderN(m, 2, linear, false);

  // Optimize high order elements
  if(CTX::instance()->mesh.hoOptimize == 2 ||
     CTX::instance()->mesh.hoOptimize == 3)
    OptimizeMesh(m, "HighOrderElastic");

  if(CTX::instance()->mesh.hoOptimize == 1 ||
     CTX::instance()->mesh.hoOptimize == 2)
    OptimizeMesh(m, "HighOrder");

  if(CTX::instance()->mesh.hoOptimize == 4)
    OptimizeMesh(m, "HighOrderFastCurving");

  // store periodic node correspondances
  FixPeriodicMesh(m);

  // only used when splitting tets into hexes
  faceContainer faceVertices;

  // Subdivide the second order elements to create the refined linear
  // mesh
  for(auto it = m->firstEdge(); it != m->lastEdge(); ++it) Subdivide(*it);
  for(auto it = m->firstFace(); it != m->lastFace(); ++it)
    Subdivide(*it, splitIntoQuads, splitIntoHexas, faceVertices, linear);
  for(auto it = m->firstRegion(); it != m->lastRegion(); ++it)
    Subdivide(*it, splitIntoHexas, faceVertices);

  // Check all 3D elements for negative volume and reverse if needed
  m->setAllVolumesPositive();

  double t2 = Cpu(), w2 = TimeOfDay();
  Msg::StatusBar(true, "Done refining mesh (Wall %gs, CPU %gs)", w2 - w1,
                 t2 - t1);
}

void BarycentricRefineMesh(GModel *m)
{
  Msg::StatusBar(true, "Barycentrically refining mesh...");
  double t1 = Cpu(), w1 = TimeOfDay();

  m->destroyMeshCaches();

  // Only update triangles in 2D, only update tets in 3D
  if(m->getNumRegions() == 0) {
    for(auto it = m->firstFace(); it != m->lastFace(); ++it) {
      GFace *gf = *it;
      std::size_t numt = gf->triangles.size();
      if(!numt) continue;
      std::vector<MTriangle *> triangles2(3 * numt);
      for(std::size_t i = 0; i < numt; i++) {
        MTriangle *t = gf->triangles[i];
        SPoint3 bary = t->barycenter();
        // FIXME: create an MFaceVertex (with correct parametric coordinates)?
        MVertex *v = new MVertex(bary.x(), bary.y(), bary.z(), gf);
        triangles2[3 * i] = new MTriangle(t->getVertex(0), t->getVertex(1), v);
        triangles2[3 * i + 1] =
          new MTriangle(t->getVertex(1), t->getVertex(2), v);
        triangles2[3 * i + 2] =
          new MTriangle(t->getVertex(2), t->getVertex(0), v);
        delete t;
        gf->mesh_vertices.push_back(v);
      }
      gf->triangles = triangles2;
      gf->deleteVertexArrays();
    }
  }
  else {
    for(auto it = m->firstRegion(); it != m->lastRegion(); ++it) {
      GRegion *gr = *it;
      std::size_t numt = gr->tetrahedra.size();
      if(!numt) continue;
      std::vector<MTetrahedron *> tetrahedra2(4 * numt);
      for(std::size_t i = 0; i < numt; i++) {
        MTetrahedron *t = gr->tetrahedra[i];
        SPoint3 bary = t->barycenter();
        // FIXME: create an MFaceVertex (with correct parametric coordinates)?
        MVertex *v = new MVertex(bary.x(), bary.y(), bary.z(), gr);
        tetrahedra2[4 * i] = new MTetrahedron(t->getVertex(0), t->getVertex(1),
                                              t->getVertex(2), v);
        tetrahedra2[4 * i + 1] = new MTetrahedron(
          t->getVertex(1), t->getVertex(2), t->getVertex(3), v);
        tetrahedra2[4 * i + 2] = new MTetrahedron(
          t->getVertex(2), t->getVertex(3), t->getVertex(0), v);
        tetrahedra2[4 * i + 3] = new MTetrahedron(
          t->getVertex(3), t->getVertex(0), t->getVertex(1), v);
        delete t;
        gr->mesh_vertices.push_back(v);
      }
      gr->tetrahedra = tetrahedra2;
      gr->deleteVertexArrays();
    }
  }

  double t2 = Cpu(), w2 = TimeOfDay();
  Msg::StatusBar(true, "Done barycentrically refining mesh (Wall %gs, CPU %gs)",
                 w2 - w1, t2 - t1);
}

// Tristan Carrier Baudouin's contribution on Full Hex Meshing

static double schneiders_x(int i)
{
  double coord[105] = {
    0.500000,  0.666667,  0.500000,  1.000000,  1.000000,  1.000000,  0.289057,
    0.324970,  0.276710,  0.337200,  0.364878,  0.325197,  0.000000,  0.000000,
    0.000000,  0.000000,  0.000000,  0.000000,  -0.289057, -0.324970, -0.276710,
    -0.337200, -0.364878, -0.325197, -0.500000, -0.666667, -0.500000, -1.000000,
    -1.000000, -1.000000, 0.084599,  0.263953,  0.442960,  0.310954,  0.000000,
    0.000000,  0.118244,  0.212082,  0.244049,  0.213940,  0.040495,  0.110306,
    0.000000,  0.000000,  0.000000,  0.000000,  0.000000,  0.000000,  -0.118244,
    -0.212082, -0.244049, -0.213940, -0.040495, -0.110306, -0.084599, -0.263953,
    -0.442960, -0.310954, 0.650493,  0.454537,  0.000000,  0.000000,  0.320508,
    0.264129,  0.063695,  0.092212,  0.000000,  0.000000,  0.000000,  0.000000,
    -0.320508, -0.264129, -0.063695, -0.092212, -0.650493, -0.454537, 0.619616,
    0.000000,  0.277170,  0.124682,  0.000000,  0.000000,  -0.277170, -0.124682,
    -0.619616, 0.128101,  0.000000,  0.176104,  0.084236,  0.000000,  0.000000,
    -0.176104, -0.084236, -0.128101, 0.000000,  0.000000,  0.000000,  0.000000,
    0.000000,  0.000000,  0.000000,  0.000000,  0.000000,  0.000000,  0.000000};

  return coord[i];
}

static double schneiders_y(int i)
{
  double coord[105] = {
    0.707107, 0.471405, 0.707107, 0.000000, 0.000000, 0.000000, 0.474601,
    0.421483, 0.463847, 0.367090, 0.344843, 0.361229, 0.429392, 0.410339,
    0.435001, 0.407674, 0.401208, 0.404164, 0.474601, 0.421483, 0.463847,
    0.367090, 0.344843, 0.361229, 0.707107, 0.471405, 0.707107, 0.000000,
    0.000000, 0.000000, 0.536392, 0.697790, 0.569124, 0.742881, 0.558045,
    0.946690, 0.497378, 0.532513, 0.500133, 0.541479, 0.530503, 0.666252,
    0.463274, 0.465454, 0.430972, 0.451135, 0.515274, 0.589713, 0.497378,
    0.532513, 0.500133, 0.541479, 0.530503, 0.666252, 0.536392, 0.697790,
    0.569124, 0.742881, 0.080018, 0.104977, 0.216381, 0.200920, 0.326416,
    0.339933, 0.280915, 0.305725, 0.396502, 0.394423, 0.310617, 0.337499,
    0.326416, 0.339933, 0.280915, 0.305725, 0.080018, 0.104977, 0.081443,
    0.204690, 0.354750, 0.334964, 0.403611, 0.367496, 0.354750, 0.334964,
    0.081443, 0.501199, 0.538575, 0.447454, 0.486224, 0.431723, 0.470065,
    0.447454, 0.486224, 0.501199, 0.488701, 0.471405, 0.017336, 0.000000,
    0.452197, 0.471405, 0.057682, 0.000000, 1.414213, 0.015731, 0.000000};

  return coord[i];
}

static double schneiders_z(int i)
{
  double coord[105] = {
    0.500000,  0.000000,  -0.500000, 1.000000,  0.000000,  -1.000000, 0.051666,
    -0.058015, -0.148140, 0.071987,  -0.057896, -0.181788, -0.016801, -0.054195,
    -0.104114, -0.015276, -0.054392, -0.110605, 0.051666,  -0.058015, -0.148140,
    0.071987,  -0.057896, -0.181788, 0.500000,  0.000000,  -0.500000, 1.000000,
    0.000000,  -1.000000, -0.208673, -0.162945, 0.021476,  0.389516,  -0.157646,
    0.159885,  -0.142645, -0.073557, -0.032793, 0.060339,  -0.136482, 0.043449,
    -0.111103, -0.079664, -0.047879, -0.008734, -0.124554, 0.008560,  -0.142645,
    -0.073557, -0.032793, 0.060339,  -0.136482, 0.043449,  -0.208673, -0.162945,
    0.021476,  0.389516,  -0.041899, -0.680880, -0.103504, -0.392255, -0.065989,
    -0.212535, -0.093142, -0.227139, -0.056201, -0.124443, -0.087185, -0.182164,
    -0.065989, -0.212535, -0.093142, -0.227139, -0.041899, -0.680880, 0.786284,
    0.443271,  0.104202,  0.144731,  -0.005330, 0.073926,  0.104202,  0.144731,
    0.786284,  -0.364254, -0.282882, -0.189794, -0.182143, -0.127036, -0.148665,
    -0.189794, -0.182143, -0.364254, 0.642222,  0.666667,  0.959658,  1.000000,
    -0.455079, -0.666667, -0.844452, -1.000000, 0.000000,  -0.009020, 0.000000};

  return coord[i];
}

static int schneiders_connect(int i, int j)
{
  int n0[88] = {0,  1,  6,  7,  12,  13,  18, 19, 41, 39, 37, 41, 36, 40, 47,
                45, 43, 47, 42, 46,  53,  51, 49, 53, 48, 52, 35, 57, 55, 35,
                54, 34, 34, 35, 65,  63,  64, 62, 69, 67, 68, 66, 73, 71, 72,
                70, 61, 75, 60, 74,  60,  61, 79, 78, 81, 80, 83, 82, 77, 84,
                77, 88, 87, 90, 89,  92,  91, 86, 93, 86, 57, 24, 95, 85, 2,
                99, 84, 74, 97, 104, 104, 97, 26, 35, 35, 24, 35, 24};

  int n1[88] = {1,  2,  7,  8,  13,  14, 19, 20, 39, 6,   38, 37, 37, 36, 45,
                12, 44, 43, 43, 42,  51, 18, 50, 49, 49,  48, 57, 24, 56, 55,
                55, 54, 40, 41, 63,  11, 62, 10, 67, 17,  66, 16, 71, 23, 70,
                22, 75, 29, 74, 28,  64, 65, 78, 9,  80,  15, 82, 21, 84, 27,
                79, 87, 8,  89, 14,  91, 20, 93, 26, 88,  35, 57, 94, 86, 85,
                98, 77, 60, 96, 103, 28, 27, 99, 55, 102, 25, 31, 102};

  int n2[88] = {4,  5,  10, 11, 16, 17, 22, 23, 38, 7,  7,  36, 8,  87, 44,
                13, 13, 42, 14, 89, 50, 19, 19, 48, 20, 91, 56, 25, 25, 54,
                26, 93, 46, 47, 62, 10, 78, 9,  66, 16, 80, 15, 70, 22, 82,
                21, 74, 28, 84, 27, 68, 69, 39, 6,  45, 12, 51, 18, 57, 24,
                81, 63, 11, 67, 17, 71, 23, 75, 29, 90, 33, 94, 33, 93, 98,
                93, 76, 58, 76, 58, 74, 84, 2,  26, 2,  26, 2,  0};

  int n3[88] = {3,  4,  9,   10, 15,  16,  21, 22,  37,  38, 8,  40, 87,
                88, 43, 44,  14, 46,  89,  90, 49,  50,  20, 52, 91, 92,
                55, 56, 26,  34, 93,  86,  52, 53,  64,  62, 79, 78, 68,
                66, 81, 80,  72, 70,  83,  82, 60,  74,  77, 84, 72, 73,
                41, 39, 47,  45, 53,  51,  35, 57,  83,  65, 63, 69, 67,
                73, 71, 61,  75, 92,  94,  95, 0,   98,  99, 26, 96, 103,
                3,  4,  103, 96, 102, 102, 31, 102, 102, 95};

  int n4[88] = {6,   7,  12, 13,  18,  19,  24,  25, 35, 33, 31, 35, 30, 34, 41,
                39,  37, 41, 36,  40,  47,  45,  43, 47, 42, 46, 53, 51, 49, 53,
                48,  52, 86, 34,  61,  59,  60,  58, 65, 63, 64, 62, 69, 67, 68,
                66,  73, 71, 72,  70,  77,  60,  77, 76, 79, 78, 81, 80, 83, 82,
                35,  86, 85, 88,  87,  90,  89,  92, 91, 61, 84, 27, 97, 59, 5,
                101, 74, 75, 104, 101, 101, 104, 93, 34, 34, 57, 33, 57};

  int n5[88] = {7,   8,  13, 14,  19,  20, 25, 26, 33, 0,  32, 31, 31, 30, 39,
                6,   38, 37, 37,  36,  45, 12, 44, 43, 43, 42, 51, 18, 50, 49,
                49,  48, 88, 40,  59,  5,  58, 4,  63, 11, 62, 10, 67, 17, 66,
                16,  71, 23, 70,  22,  79, 64, 76, 3,  78, 9,  80, 15, 82, 21,
                41,  85, 2,  87,  8,   89, 14, 91, 20, 65, 77, 84, 96, 61, 59,
                100, 60, 61, 103, 100, 29, 28, 98, 54, 86, 56, 32, 35};

  int n6[88] = {10, 11, 16, 17, 22, 23, 28, 29, 32, 1,  1,  30, 2,  85, 38,
                7,  7,  36, 8,  87, 44, 13, 13, 42, 14, 89, 50, 19, 19, 48,
                20, 91, 90, 46, 58, 4,  76, 3,  62, 10, 78, 9,  66, 16, 80,
                15, 70, 22, 82, 21, 81, 68, 33, 0,  39, 6,  45, 12, 51, 18,
                47, 59, 5,  63, 11, 67, 17, 71, 23, 69, 76, 96, 76, 75, 100,
                75, 58, 59, 58, 59, 75, 74, 85, 93, 85, 55, 1,  33};

  int n7[88] = {9,  10, 15,  16,  21, 22, 27, 28, 31,  32,  2,  34,  85,
                86, 37, 38,  8,   40, 87, 88, 43, 44,  14,  46, 89,  90,
                49, 50, 20,  52,  91, 92, 92, 52, 60,  58,  77, 76,  64,
                62, 79, 78,  68,  66, 81, 80, 72, 70,  83,  82, 83,  72,
                35, 33, 41,  39,  47, 45, 53, 51, 53,  61,  59, 65,  63,
                69, 67, 73,  71,  73, 96, 97, 3,  100, 101, 29, 103, 100,
                4,  5,  100, 103, 86, 86, 30, 35, 0,   94};

  if(i == 0) { return n0[j]; }
  else if(i == 1) {
    return n1[j];
  }
  else if(i == 2) {
    return n2[j];
  }
  else if(i == 3) {
    return n3[j];
  }
  else if(i == 4) {
    return n4[j];
  }
  else if(i == 5) {
    return n5[j];
  }
  else if(i == 6) {
    return n6[j];
  }
  else {
    return n7[j];
  }
}

void subdivide_pyramid(MElement *element, GRegion *gr,
                       faceContainer &faceVertices,
                       std::vector<MHexahedron *> &dwarfs88)
{
  std::vector<MVertex *> v(105, (MVertex *)nullptr);

  v[29] = element->getVertex(0);
  v[27] = element->getVertex(1);
  v[3] = element->getVertex(2);
  v[5] = element->getVertex(3);
  v[102] = element->getVertex(4);

  v[28] = element->getVertex(5);
  v[97] = element->getVertex(8);
  v[4] = element->getVertex(10);
  v[101] = element->getVertex(6);
  v[26] = element->getVertex(7);
  v[24] = element->getVertex(9);
  v[0] = element->getVertex(11);
  v[2] = element->getVertex(12);

  // the one in the middle of rect face
  v[104] = element->getVertex(13);

  SPoint3 point;

  auto fIter = faceVertices.find(MFace(v[29], v[27], v[102]));
  if(fIter != faceVertices.end())
    v[25] = fIter->second[0];
  else {
    element->pnt(0.0, -0.666667, 0.471405 / 1.414213, point);
    v[25] = new MVertex(point.x(), point.y(), point.z(), gr);
    gr->addMeshVertex(v[25]);
    faceVertices[MFace(v[29], v[27], v[102])].push_back(v[25]);
  }

  fIter = faceVertices.find(MFace(v[27], v[3], v[102]));
  if(fIter != faceVertices.end())
    v[95] = fIter->second[0];
  else {
    element->pnt(0.666667, 0.0, 0.471405 / 1.414213, point);
    v[95] = new MVertex(point.x(), point.y(), point.z(), gr);
    gr->addMeshVertex(v[95]);
    faceVertices[MFace(v[27], v[3], v[102])].push_back(v[95]);
  }

  fIter = faceVertices.find(MFace(v[3], v[5], v[102]));
  if(fIter != faceVertices.end())
    v[1] = fIter->second[0];
  else {
    element->pnt(0.0, 0.666667, 0.471405 / 1.414213, point);
    v[1] = new MVertex(point.x(), point.y(), point.z(), gr);
    gr->addMeshVertex(v[1]);
    faceVertices[MFace(v[3], v[5], v[102])].push_back(v[1]);
  }

  fIter = faceVertices.find(MFace(v[5], v[29], v[102]));
  if(fIter != faceVertices.end())
    v[99] = fIter->second[0];
  else {
    element->pnt(-0.666667, 0.0, 0.471405 / 1.414213, point);
    v[99] = new MVertex(point.x(), point.y(), point.z(), gr);
    gr->addMeshVertex(v[99]);
    faceVertices[MFace(v[5], v[29], v[102])].push_back(v[99]);
  }

  for(int i = 0; i < 105; i++) {
    if(!v[i]) {
      element->pnt(schneiders_z(i), schneiders_x(i), schneiders_y(i) / 1.414213,
                   point);
      v[i] = new MVertex(point.x(), point.y(), point.z(), gr);
      gr->addMeshVertex(v[i]);
    }
  }

  dwarfs88.resize(88);

  for(int i = 0; i < 88; i++) {
    int const index1 = schneiders_connect(0, i);
    int const index2 = schneiders_connect(1, i);
    int const index3 = schneiders_connect(2, i);
    int const index4 = schneiders_connect(3, i);
    int const index5 = schneiders_connect(4, i);
    int const index6 = schneiders_connect(5, i);
    int const index7 = schneiders_connect(6, i);
    int const index8 = schneiders_connect(7, i);

    dwarfs88[i] = new MHexahedron(v[index1], v[index2], v[index3], v[index4],
                                  v[index5], v[index6], v[index7], v[index8]);
  }
}
