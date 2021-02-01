// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <vector>
#include <stdlib.h>
#include "GmshConfig.h"
#include "GModel.h"
#include "discreteFace.h"
#include "GmshMessage.h"
#include "MVertex.h"
#include "Triangulate.h"
#include "Context.h"

#if defined(HAVE_MESH)
#include "DivideAndConquer.h"
#include "meshGFaceDelaunayInsertion.h"
#endif

StringXNumber TriangulateOptions_Number[] = {
  {GMSH_FULLRC, "Algorithm", nullptr, 1.}, {GMSH_FULLRC, "View", nullptr, -1.}};

extern "C" {
GMSH_Plugin *GMSH_RegisterTriangulatePlugin()
{
  return new GMSH_TriangulatePlugin();
}
}

std::string GMSH_TriangulatePlugin::getHelp() const
{
  return "Plugin(Triangulate) triangulates the points in the "
         "view `View', assuming that all the points belong "
         "to a surface that can be projected one-to-one "
         "onto a plane. Algorithm selects the old (0) or new (1) "
         "meshing algorithm.\n\n"
         "If `View' < 0, the plugin is run on the current view.\n\n"
         "Plugin(Triangulate) creates one new list-based view.";
}

int GMSH_TriangulatePlugin::getNbOptions() const
{
  return sizeof(TriangulateOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_TriangulatePlugin::getOption(int iopt)
{
  return &TriangulateOptions_Number[iopt];
}

#if defined(HAVE_MESH)

namespace {
  class PointData : public MVertex {
  public:
    std::vector<double> v;
    PointData(double x, double y, double z, int numVal) : MVertex(x, y, z)
    {
      v.resize(3 + numVal);
      v[0] = x;
      v[1] = y;
      v[2] = z;
    }
  };
} // namespace

PView *GMSH_TriangulatePlugin::execute(PView *v)
{
  int algo = (int)TriangulateOptions_Number[0].def;
  int iView = (int)TriangulateOptions_Number[1].def;

  PView *v1 = getView(iView, v);
  if(!v1) return v;
  PViewData *data1 = v1->getData();

  if(data1->hasMultipleMeshes()) {
    Msg::Error("Triangulate plugin cannot be applied to multi-mesh views");
    return v1;
  }

  // create list of points with associated data
  std::vector<MVertex *> points;
  int numSteps = data1->getNumTimeSteps();
  for(int ent = 0; ent < data1->getNumEntities(0); ent++) {
    for(int ele = 0; ele < data1->getNumElements(0, ent); ele++) {
      if(data1->skipElement(0, ent, ele)) continue;
      if(data1->getNumNodes(0, ent, ele) != 1) continue;
      int numComp = data1->getNumComponents(0, ent, ele);
      double x, y, z;
      data1->getNode(0, ent, ele, 0, x, y, z);
      PointData *p = new PointData(x, y, z, numComp * numSteps);
      for(int step = 0; step < numSteps; step++)
        for(int comp = 0; comp < numComp; comp++)
          data1->getValue(step, ent, ele, 0, comp,
                          p->v[3 + numComp * step + comp]);
      points.push_back(p);
    }
  }

  if(points.size() < 3) {
    Msg::Error("Need at least 3 points to triangulate");
    for(std::size_t i = 0; i < points.size(); i++) delete points[i];
    return v1;
  }

  // get bounding box
  SBoundingBox3d bbox;
  for(std::size_t i = 0; i < points.size(); i++) bbox += points[i]->point();
  double lc = 10 * norm(SVector3(bbox.max(), bbox.min()));

  // project points onto plane
  discreteFace *s =
    new discreteFace(GModel::current(), GModel::current()->getNumFaces() + 1);
  s->computeMeanPlane(points);
  double x, y, z, VX[3], VY[3];
  s->getMeanPlaneData(VX, VY, x, y, z);
  for(std::size_t i = 0; i < points.size(); i++) {
    double vec[3] = {points[i]->x() - x, points[i]->y() - y,
                     points[i]->z() - z};
    double u = prosca(vec, VX);
    double v = prosca(vec, VY);
    points[i]->x() = u;
    points[i]->y() = v;
    points[i]->z() = 0.;
  }
  delete s;

  PView *v2;
  PViewDataList *data2;

  if(algo == 0) { // using old code

    // build a point record structure for the divide and conquer algorithm
    DocRecord doc(points.size());
    for(std::size_t i = 0; i < points.size(); i++) {
      double XX = CTX::instance()->mesh.randFactor * lc * (double)rand() /
                  (double)RAND_MAX;
      double YY = CTX::instance()->mesh.randFactor * lc * (double)rand() /
                  (double)RAND_MAX;
      doc.points[i].where.h = points[i]->x() + XX;
      doc.points[i].where.v = points[i]->y() + YY;
      doc.points[i].adjacent = nullptr;
      doc.points[i].data = (void *)points[i];
    }

    // triangulate
    try {
      doc.MakeMeshWithPoints();
    } catch(const char *err) {
      Msg::Error("%s", err);
    }

    // create output (using unperturbed data)
    v2 = new PView();
    data2 = getDataList(v2);
    for(int i = 0; i < doc.numTriangles; i++) {
      int a = doc.triangles[i].a;
      int b = doc.triangles[i].b;
      int c = doc.triangles[i].c;
      int n = doc.numPoints;
      if(a < 0 || a >= n || b < 0 || b >= n || c < 0 || c >= n) {
        Msg::Warning("Skipping bad triangle %d", i);
        continue;
      }
      PointData *p[3];
      p[0] = (PointData *)doc.points[doc.triangles[i].a].data;
      p[1] = (PointData *)doc.points[doc.triangles[i].b].data;
      p[2] = (PointData *)doc.points[doc.triangles[i].c].data;
      int numComp = 0;
      std::vector<double> *vec = nullptr;
      if((int)p[0]->v.size() == 3 + 9 * numSteps &&
         (int)p[1]->v.size() == 3 + 9 * numSteps &&
         (int)p[2]->v.size() == 3 + 9 * numSteps) {
        numComp = 9;
        data2->NbTT++;
        vec = &data2->TT;
      }
      else if((int)p[0]->v.size() == 3 + 3 * numSteps &&
              (int)p[1]->v.size() == 3 + 3 * numSteps &&
              (int)p[2]->v.size() == 3 + 3 * numSteps) {
        numComp = 3;
        data2->NbVT++;
        vec = &data2->VT;
      }
      else {
        numComp = 1;
        data2->NbST++;
        vec = &data2->ST;
      }
      for(int nod = 0; nod < 3; nod++) vec->push_back(p[nod]->v[0]);
      for(int nod = 0; nod < 3; nod++) vec->push_back(p[nod]->v[1]);
      for(int nod = 0; nod < 3; nod++) vec->push_back(p[nod]->v[2]);
      for(int step = 0; step < numSteps; step++)
        for(int nod = 0; nod < 3; nod++)
          for(int comp = 0; comp < numComp; comp++)
            vec->push_back(p[nod]->v[3 + numComp * step + comp]);
    }
  }
  else { // new code

    Msg::Info("Using new triangulation code");
    std::vector<MTriangle *> tris;
    for(std::size_t i = 0; i < points.size(); i++) {
      double XX = 1.e-12 * lc * (double)rand() / (double)RAND_MAX;
      double YY = 1.e-12 * lc * (double)rand() / (double)RAND_MAX;
      points[i]->x() += XX;
      points[i]->y() += YY;
    }
    delaunayMeshIn2D(points, tris);

    v2 = new PView();
    data2 = getDataList(v2);
    for(std::size_t i = 0; i < tris.size(); i++) {
      PointData *p[3];
      p[0] = (PointData *)tris[i]->getVertex(0);
      p[1] = (PointData *)tris[i]->getVertex(1);
      p[2] = (PointData *)tris[i]->getVertex(2);
      int numComp = 0;
      std::vector<double> *vec = nullptr;
      if((int)p[0]->v.size() == 3 + 9 * numSteps &&
         (int)p[1]->v.size() == 3 + 9 * numSteps &&
         (int)p[2]->v.size() == 3 + 9 * numSteps) {
        numComp = 9;
        data2->NbTT++;
        vec = &data2->TT;
      }
      else if((int)p[0]->v.size() == 3 + 3 * numSteps &&
              (int)p[1]->v.size() == 3 + 3 * numSteps &&
              (int)p[2]->v.size() == 3 + 3 * numSteps) {
        numComp = 3;
        data2->NbVT++;
        vec = &data2->VT;
      }
      else {
        numComp = 1;
        data2->NbST++;
        vec = &data2->ST;
      }
      for(int nod = 0; nod < 3; nod++) vec->push_back(p[nod]->v[0]);
      for(int nod = 0; nod < 3; nod++) vec->push_back(p[nod]->v[1]);
      for(int nod = 0; nod < 3; nod++) vec->push_back(p[nod]->v[2]);
      for(int step = 0; step < numSteps; step++)
        for(int nod = 0; nod < 3; nod++)
          for(int comp = 0; comp < numComp; comp++)
            vec->push_back(p[nod]->v[3 + numComp * step + comp]);
      delete tris[i];
    }
  }

  for(std::size_t i = 0; i < points.size(); i++) delete points[i];

  for(int i = 0; i < data1->getNumTimeSteps(); i++)
    data2->Time.push_back(data1->getTime(i));
  data2->setName(data1->getName() + "_Triangulate");
  data2->setFileName(data1->getName() + "_Triangulate.pos");
  data2->finalize();

  return v2;
}

#else

PView *GMSH_TriangulatePlugin::execute(PView *v)
{
  Msg::Error("Plugin(Triangulate) requires mesh module");
  return v;
}

#endif
