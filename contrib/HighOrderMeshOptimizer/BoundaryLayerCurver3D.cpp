// Copyright (C) 2017 ULg-UCL
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use, copy,
// modify, merge, publish, distribute, and/or sell copies of the
// Software, and to permit persons to whom the Software is furnished
// to do so, provided that the above copyright notice(s) and this
// permission notice appear in all copies of the Software and that
// both the above copyright notice(s) and this permission notice
// appear in supporting documentation.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT OF THIRD PARTY RIGHTS. IN NO EVENT SHALL THE
// COPYRIGHT HOLDER OR HOLDERS INCLUDED IN THIS NOTICE BE LIABLE FOR
// ANY CLAIM, OR ANY SPECIAL INDIRECT OR CONSEQUENTIAL DAMAGES, OR ANY
// DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
// WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
// ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
// OF THIS SOFTWARE.
//
// Please report all bugs and problems to the public mailing list
// <gmsh@onelab.info>.
//
// Contributors: Amaury Johnen

#include "BoundaryLayerCurver.h"
#include "MQuadrangle.h"
#include "MTriangle.h"
#include "BasisFactory.h"
#include "GFace.h"
#include "legendrePolynomials.h"
#include "bezierBasis.h"

#include "gmshVertex.h"
#include "Geo.h"
#include "MLine.h"
#include "GModel.h"
#if defined(HAVE_POST)
#include "PView.h"
#endif
#if defined(HAVE_FLTK)
#include "FlGui.h"
#endif
#include "Options.h"
#include "AnalyseCurvedMesh.h"
#include "InteriorNodePlacement.h"

namespace
{
  void drawAmplifiedDiffWithLin(const std::vector<MVertex *> &vertices,
                                GEntity *entity, double amp = 100,
                                bool drawBasisLines = false, int cnt = 100)
  {
    MLineN l(vertices);
    MVertex *v0 = vertices[0];
    MVertex *v1 = vertices[1];
    MVertex *previous = NULL;
    for (int i = 0; i < cnt; ++i) {
      double xi = -1 + 2 * i / (cnt - 1.);
      double c1 = i / (cnt - 1.);
      double c0 = 1 - c1;
      SPoint3 pLin(v0->x() * c0 + v1->x() * c1,
                   v0->y() * c0 + v1->y() * c1,
                   v0->z() * c0 + v1->z() * c1);
      SPoint3 p;
      l.pnt(xi, 0, 0, p);
      MVertex *vLin = new MVertex(pLin.x(), pLin.y(), pLin.z(), entity);
      MVertex *v = new MVertex(amp * p.x() - (amp - 1) * pLin.x(),
                               amp * p.y() - (amp - 1) * pLin.y(),
                               amp * p.z() - (amp - 1) * pLin.z(), entity);
      if (previous) {
        MLine *line = new MLine(v, previous);
        ((GEdge *) entity)->addLine(line);
      }
      if (drawBasisLines) {
        MLine *line = new MLine(v, vLin);
        ((GEdge *) entity)->addLine(line);
        ((GEdge *) entity)->addMeshVertex(vLin);
      }
      ((GEdge *) entity)->addMeshVertex(v);
      previous = v;
    }
  }

  void drawBezierControlPolygon(const fullMatrix<double> &controlPoints,
                                GEntity *entity)
  {
    const int nVert = controlPoints.size1();
    std::vector<int> idx(nVert);
    idx[0] = 0;
    for (int i = 1; i < nVert-1; ++i) idx[i] = i+1;
    idx[nVert-1] = 1;

    MVertex *previous = NULL;
    for (int i = 0; i < nVert; ++i) {
      MVertex *v = new MVertex(controlPoints(idx[i], 0), controlPoints(idx[i], 1),
                               controlPoints(idx[i], 2), entity);
      if (previous) {
        MLine *line = new MLine(v, previous);
        ((GEdge *) entity)->addLine(line);
      }
      ((GEdge *) entity)->addMeshVertex(v);
      previous = v;
    }
  }

  void drawBezierControlPolygon(const std::vector<MVertex *> &vertices,
                                GEntity *entity)
  {
    const int nVert = (int)vertices.size();
    const bezierBasis *fs = BasisFactory::getBezierBasis(TYPE_LIN, nVert - 1);

    fullMatrix<double> xyz(nVert, 3);
    for (int i = 0; i < nVert; ++i) {
      xyz(i, 0) = vertices[i]->x();
      xyz(i, 1) = vertices[i]->y();
      xyz(i, 2) = vertices[i]->z();
    }
    fullMatrix<double> controlPoints(nVert, 3);
    fs->lag2Bez(xyz, controlPoints);

    bool subdivide = true;
    bool subdivide2 = true;
    if (subdivide) {
      fullMatrix<double> allSubs(2*nVert, 3);
      fs->subdivideBezCoeff(controlPoints, allSubs);
      fullMatrix<double> sub(nVert, 3);
      sub.copy(allSubs, 0, nVert, 0, 3, 0, 0);
      if (subdivide2) {
        fullMatrix<double> allSubs2(2*nVert, 3);
        fs->subdivideBezCoeff(sub, allSubs2);
        fullMatrix<double> sub2(nVert, 3);
        sub2.copy(allSubs2, 0, nVert, 0, 3, 0, 0);
        drawBezierControlPolygon(sub2, entity);
        sub2.copy(allSubs2, nVert, nVert, 0, 3, 0, 0);
        drawBezierControlPolygon(sub2, entity);
      }
      else
        drawBezierControlPolygon(sub, entity);
      sub.copy(allSubs, nVert, nVert, 0, 3, 0, 0);
      if (subdivide2) {
        fullMatrix<double> allSubs2(2*nVert, 3);
        fs->subdivideBezCoeff(sub, allSubs2);
        fullMatrix<double> sub2(nVert, 3);
        sub2.copy(allSubs2, 0, nVert, 0, 3, 0, 0);
        drawBezierControlPolygon(sub2, entity);
        sub2.copy(allSubs2, nVert, nVert, 0, 3, 0, 0);
        drawBezierControlPolygon(sub2, entity);
      }
      else
        drawBezierControlPolygon(sub, entity);
    }
    else {
      drawBezierControlPolygon(controlPoints, entity);
    }
  }

  void drawBezierDerivative(const std::vector<MVertex *> &vertices,
                            GEntity *entity, SPoint3 p, int *onlyN = NULL,
                            double fact = 1)
  {
    MVertex *v = new MVertex(p.x(), p.y(), p.z(), entity);
    MLine *line = new MLine(v, v);
    ((GEdge *) entity)->addLine(line);
    ((GEdge *) entity)->addMeshVertex(v);

    const int nVert = vertices.size();

    fullMatrix<double> controlPoints(nVert, 3);
    {
      const bezierBasis *fs = BasisFactory::getBezierBasis(TYPE_LIN, nVert - 1);
      fullMatrix<double> xyz(nVert, 3);
      for (int i = 0; i < nVert; ++i) {
        xyz(i, 0) = vertices[i]->x();
        xyz(i, 1) = vertices[i]->y();
        xyz(i, 2) = vertices[i]->z();
      }
      fs->lag2Bez(xyz, controlPoints);
    }

    fullMatrix<double> deriv(nVert, 3);
    deriv(0, 0) = controlPoints(0, 0);
    deriv(0, 1) = controlPoints(0, 1);
    deriv(0, 2) = controlPoints(0, 2);
    for (int i = 1; i < nVert-1; ++i) {
      deriv(i, 0) = controlPoints(i+1, 0);
      deriv(i, 1) = controlPoints(i+1, 1);
      deriv(i, 2) = controlPoints(i+1, 2);
    }
    deriv(nVert-1, 0) = controlPoints(1, 0);
    deriv(nVert-1, 1) = controlPoints(1, 1);
    deriv(nVert-1, 2) = controlPoints(1, 2);
    deriv.scale(fact);

    for (int n = nVert - 1; n > 0; --n) {
      for (int i = 0; i < n; ++i) {
        deriv(i, 0) = deriv(i+1, 0) - deriv(i, 0);
        deriv(i, 1) = deriv(i+1, 1) - deriv(i, 1);
        deriv(i, 2) = deriv(i+1, 2) - deriv(i, 2);
      }
      deriv.scale(n);
      fullMatrix<double> controlPointsDeriv(n, 3);
      controlPointsDeriv(0, 0) = p.x() + deriv(0, 0);
      controlPointsDeriv(0, 1) = p.y() + deriv(0, 1);
      controlPointsDeriv(0, 2) = p.z() + deriv(0, 2);
      controlPointsDeriv(1, 0) = p.x() + deriv(n-1, 0);
      controlPointsDeriv(1, 1) = p.y() + deriv(n-1, 1);
      controlPointsDeriv(1, 2) = p.z() + deriv(n-1, 2);
      for (int i = 2; i < n; ++i) {
        controlPointsDeriv(i, 0) = p.x() + deriv(i-1, 0);
        controlPointsDeriv(i, 1) = p.y() + deriv(i-1, 1);
        controlPointsDeriv(i, 2) = p.z() + deriv(i-1, 2);
      }
      if (!onlyN || *onlyN == n) {
        bool subdivide = true;
        bool subdivide2 = true;
        if (subdivide) {
          const bezierBasis *fs = BasisFactory::getBezierBasis(TYPE_LIN, n-1);
          fullMatrix<double> allSubs(2*n, 3);
          fs->subdivideBezCoeff(controlPointsDeriv, allSubs);
          fullMatrix<double> sub(n, 3);
          sub.copy(allSubs, 0, n, 0, 3, 0, 0);
          if (subdivide2) {
            fullMatrix<double> allSubs2(2*n, 3);
            fs->subdivideBezCoeff(sub, allSubs2);
            fullMatrix<double> sub2(n, 3);
            sub2.copy(allSubs2, 0, n, 0, 3, 0, 0);
            drawBezierControlPolygon(sub2, entity);
            sub2.copy(allSubs2, n, n, 0, 3, 0, 0);
            drawBezierControlPolygon(sub2, entity);
          }
          else
            drawBezierControlPolygon(sub, entity);
          sub.copy(allSubs, n, n, 0, 3, 0, 0);
          if (subdivide2) {
            fullMatrix<double> allSubs2(2*n, 3);
            fs->subdivideBezCoeff(sub, allSubs2);
            fullMatrix<double> sub2(n, 3);
            sub2.copy(allSubs2, 0, n, 0, 3, 0, 0);
            drawBezierControlPolygon(sub2, entity);
            sub2.copy(allSubs2, n, n, 0, 3, 0, 0);
            drawBezierControlPolygon(sub2, entity);
          }
          else
            drawBezierControlPolygon(sub, entity);
        }
        else {
          drawBezierControlPolygon(controlPointsDeriv, entity);
        }
      }
    }
  }

  void drawBezierOffsets(fullMatrix<double> controlPoints,
                         GEdge *entity, SPoint3 p, double fact = 1)
  {
    MVertex *v = new MVertex(p.x(), p.y(), p.z(), entity);
    entity->addLine(new MLine(v, v));
    entity->addMeshVertex(v);

    int order = controlPoints.size1() - 1;
    const bezierBasis *fs = BasisFactory::getBezierBasis(TYPE_LIN, order);

    controlPoints.scale(fact);
    for (int i = 0; i < order + 1; ++i) {
      controlPoints(i, 0) += p.x();
      controlPoints(i, 1) += p.y();
      controlPoints(i, 2) += p.z();
    }

    fullMatrix<double> xyz(order+1, 3);
    fs->matrixBez2Lag.mult(controlPoints, xyz);

    std::vector<MVertex *> vertices(order + 1);
    for (int i = 0; i < order + 1; ++i) {
      vertices[i] = new MVertex(xyz(i, 0), xyz(i, 1), xyz(i, 2));
      entity->addMeshVertex(vertices[i]);
    }

    MLineN *line = new MLineN(vertices);
    entity->addLine(line);

    MVertex *previous = NULL;
    int idx[100];
    idx[0] = 0;
    idx[order] = 1;
    for (int i = 1; i < order; ++i) {
      idx[i] = i+1;
    }
    for (int i = 0; i < order + 1; ++i) {
      MVertex *v = new MVertex(controlPoints(idx[i], 0), controlPoints(idx[i], 1), controlPoints(idx[i], 2));
      if (previous) {
        MLine *line = new MLine(v, previous);
        entity->addLine(line);
        entity->addMeshVertex(v);
      }
      previous = v;
    }
  }

  void drawIdealCurve(const std::vector<MVertex *> &baseVert,
                      BoundaryLayerCurver::Parameters2DCurve &parameters,
                      SVector3 w, GEntity *entity, bool drawVertLines = false,
                      bool drawh = true,
                      bool drawn = false, bool drawt = false, int cnt = 100)
  {
    int tagLine = ElementType::getTag(TYPE_LIN, baseVert.size() - 1);
    const nodalBasis *fs = BasisFactory::getNodalBasis(tagLine);

    MVertex *vh0 = NULL;
    MVertex *vn0 = NULL;
    MVertex *vt0 = NULL;

    for (int i = 0; i < cnt; ++i) {
      double xi = -1 + 2 * i / (cnt - 1.);
      double xc = 0, yc = 0, zc = 0;
      double dx = 0, dy = 0, dz = 0;
      {
        double f[100];
        double sf[100][3];
        fs->f(xi, 0, 0, f);
        fs->df(xi, 0, 0, sf);
        for (int j = 0; j < fs->getNumShapeFunctions(); j++) {
          const MVertex *v = baseVert[j];
          xc += f[j] * v->x();
          yc += f[j] * v->y();
          zc += f[j] * v->z();
          dx += sf[j][0] * v->x();
          dy += sf[j][0] * v->y();
          dz += sf[j][0] * v->z();
        }
      }
      SVector3 t, n, h;
      double x, y, z;
      MVertex *v;
      MLine *line;
      t = SVector3(dx, dy, dz).unit();
      n = crossprod(w, t);

      if (drawh) {
        h = parameters.thicknessAtPoint(xi) * n +
            parameters.coeffbAtPoint(xi) * t;
        x = xc + h.x();
        y = yc + h.y();
        z = zc + h.z();
        v = new MVertex(x, y, z, entity);
        ((GEdge *) entity)->addMeshVertex(v);
        if (vh0) {
          line = new MLine(v, vh0);
          ((GEdge *) entity)->addLine(line);
        }
        if (drawVertLines) {
          MVertex *vbase = new MVertex(xc, yc, zc, entity);
          line = new MLine(vbase, v);
          ((GEdge *) entity)->addLine(line);
        }
        vh0 = v;
      }

      if (drawn) {
        h = parameters.thicknessAtPoint(xi) * n;
        x = xc + h.x();
        y = yc + h.y();
        z = zc + h.z();
        v = new MVertex(x, y, z, entity);
        if (vn0) {
          line = new MLine(v, vn0);
          ((GEdge *) entity)->addLine(line);
        }
        if (drawVertLines) {
          MVertex *vbase = new MVertex(xc, yc, zc, entity);
          line = new MLine(vbase, v);
          ((GEdge *) entity)->addLine(line);
        }
        ((GEdge *) entity)->addMeshVertex(v);
        vn0 = v;
      }

      if (drawt) {
        h = parameters.coeffbAtPoint(xi) * t;
        x = xc + h.x();
        y = yc + h.y();
        z = zc + h.z();
        v = new MVertex(x, y, z, entity);
        if (vt0) {
          line = new MLine(v, vt0);
          ((GEdge *) entity)->addLine(line);
        }
        ((GEdge *) entity)->addMeshVertex(v);
        vt0 = v;
      }
    }
  }

  void drawMLineN(const std::vector<MVertex *> &vertices_, GEdge *ent,
                  bool newHOvert = false)
  {
    std::vector<MVertex *> vertices = vertices_;
    if (newHOvert) {
      for (int j = 2; j < vertices.size(); ++j) {
        MVertex *v = vertices[j];
        vertices[j] = new MVertex(v->x(), v->y(), v->z());
        ent->addMeshVertex(vertices[j]);
      }
    }
    MLineN *line = new MLineN(vertices);
    ent->addLine(line);
  }

  /*             A
   *             *
   *           ,/ \
   *       c ,/    \ b
   *       ,/       \
   *     ,/          \
   *    *-------------*
   *  B        a        C
   */

  bool solveASDtriangle(double angleB, const SVector3 &sideA,
                        const SVector3 &dirSideB, double &lengthSideB,
                        const SVector3 &w, bool positiveLengths = true)
  {
    // Assuming:
    // - angleB is the signed angle from a to c in range [-pi, pi]
    // - sideA is the vector from B to C
    // - dirSideB is a vector from C in the direction of A
    // positiveLengths=true implies that all angles have to be of the same sign
    if (dirSideB.norm() < 1e-12) return false;
    if (std::abs(angleB) > M_PI) {
      Msg::Warning("angle greater than pi in solveASDtriangle");
    }
    int sign = gmsh_sign(angleB);

    double angleC = signedAngle(dirSideB, -sideA, w);
    if (positiveLengths && sign * angleC < 0) return false;

    double angleA = sign * M_PI - angleB - angleC;
    if (std::abs(angleA) < 1e-12) return false;
    if (positiveLengths && (sign * angleA < 0 || sign * angleA > M_PI)) return false;

    lengthSideB = sideA.norm() / std::sin(angleA) * std::sin(angleB);
    return true;
  }

  bool solveLSDtriangle(double lengthSideC, const SVector3 &sideA,
                        const SVector3 &dirSideB, double &lengthSideB,
                        const SVector3 &w)
  {
    // Assuming:
    // - sideA is the vector from B to C
    // - dirSideB is a vector from C in the direction of A
    // - positive lengths, i.e. all angles have to be of the same sign
    // - lengthSideC > length(sideA). Otherwise, ambiguous (0, 1 or 2 solutions)
    if (lengthSideC < sideA.norm()) return false;
    if (dirSideB.norm() < 1e-12) return false;

    double angleC = signedAngle(dirSideB, -sideA, w);
    int sign = gmsh_sign(angleC);

    double sinAngleA = sideA.norm() / lengthSideC * std::sin(angleC);
    double angleA = std::asin(sinAngleA);

    double angleB = sign * M_PI - angleA - angleC;
    lengthSideB = sideA.norm() / sinAngleA * std::sin(angleB);
    if (lengthSideB < 0) std::cout << "AARRAFGAGGAE" << std::endl;
    // TODO remove this
    return true;
  }

  void draw3DFrame(SPoint3 &p, SVector3 &t, SVector3 &n, SVector3 &w,
                   double unitDimension, GFace *gFace)
  {
    // Make sure to have 2 vector that are perpendicular to t assuming n != alpha * t, forall alpha
    SVector3 a = n;
    SVector3 b = crossprod(t, n).unit();
    a = crossprod(t, b).unit();
    a *= unitDimension;
    b *= unitDimension;

    SPoint3 pnt = p + a.point();
    MVertex *previous = new MVertex(pnt.x(), pnt.y(), pnt.z(), gFace);
   gFace->addMeshVertex(previous);

    const int N = 30;
    for (int j = 1; j <= N; ++j) {
      const double theta = (double) j / N * 2 * M_PI;
      SPoint3 pnt = p + a.point() * std::cos(theta) + b.point() * std::sin(theta);
      MVertex *current = new MVertex(pnt.x(), pnt.y(), pnt.z(), gFace);
      gFace->addMeshVertex(current);
      MLine *line = new MLine(previous, current);
      gFace->edges().front()->addLine(line);
      previous = current;
    }

    MVertex *v = new MVertex(p.x(), p.y(), p.z(), gFace);
    pnt = p + n.point() * unitDimension;
    MVertex *vn = new MVertex(pnt.x(), pnt.y(), pnt.z(), gFace);
    pnt = p + w.point() * unitDimension;
    MVertex *vw = new MVertex(pnt.x(), pnt.y(), pnt.z(), gFace);
    gFace->addMeshVertex(v);
    gFace->addMeshVertex(vn);
    gFace->addMeshVertex(vw);
    MLine *line = new MLine(v, vn);
    gFace->edges().front()->addLine(line);
    line = new MLine(v, vw);
    gFace->edges().front()->addLine(line);
  }

  void drawIdealPositionEdge(const MElement *bottom1, const MElement *bottom2,
                             const MEdgeN &baseEdge,
                             const Parameters3DCurve &parameters, GFace *gFace,
                             int triDirection = 0)
  {
    int N = 40;

    MVertex *previous = NULL;

    for (int i = 0; i < N+1; ++i) {
      const double u = (double)i / N * 2 - 1;
      SPoint3 pnt = baseEdge.pnt(u);
      SVector3 t = baseEdge.tangent(u);

      SVector3 n;
      {
        double xyz[3];
        pnt.position(xyz);

        // TODO: more efficient function? (than xyz2uvw)
        double uvw[3], gradients[3][3];
        bottom1->xyz2uvw(xyz, uvw);
        bottom1->getJacobian(uvw[0], uvw[1], uvw[2], gradients);
        n = SVector3(gradients[2][0], gradients[2][1], gradients[2][2]);
        bottom2->xyz2uvw(xyz, uvw);
        bottom2->getJacobian(uvw[0], uvw[1], uvw[2], gradients);
        SVector3 n2 = SVector3(gradients[2][0], gradients[2][1], gradients[2][2]);

        if (dot(n, n2) < 0) {
          Msg::Warning("Boundary elements have opposite normals (2) %d -- %d",
                       bottom1->getNum(), bottom2->getNum());
          n.negate();
        }
        n.axpy(1, n2);
        n.normalize();
      }

      SVector3 w = crossprod(t, n);

      int &d = triDirection;
      SVector3 h = parameters.thicknessAtPoint(u, d) * n
                   + parameters.coeffbAtPoint(u, d) * t
                   + parameters.coeffcAtPoint(u, d) * w;
      double x = pnt.x() + h.x();
      double y = pnt.y() + h.y();
      double z = pnt.z() + h.z();

      MVertex *current = new MVertex(x, y, z, gFace);
      gFace->addMeshVertex(current);
      if (previous) {
        MLine *line = new MLine(previous, current);
        gFace->edges().front()->addLine(line);
      }
      previous = current;
    }
  }
}

namespace BoundaryLayerCurver
{

}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// compute adjacencies of boundary elements, thus of columns
void computeAdjacencies(VecPairMElemVecMElem &bndEl2column,
                        std::vector<std::pair<int, int> > &adjacencies)
{
  std::map<MEdge, int, Less_Edge> edge2element;
  for (unsigned int i = 0; i < bndEl2column.size(); ++i) {
    MElement *el = bndEl2column[i].first;
    for (unsigned int j = 0; j < el->getNumEdges(); ++j) {
      MEdge e = el->getEdge(j);
      std::map<MEdge, int, Less_Edge>::iterator it = edge2element.find(e);
      if (it != edge2element.end()) {
        adjacencies.push_back(std::make_pair(i, it->second));
        // This is for debug purpose, we expect that two elements at most
        // share a given edge.
        it->second = -1;
      }
      else {
        edge2element[e] = i;
      }
    }
  }
}


bool areSameFaces(MFace &f1, MFace &f2)
{
  int nVertices = f1.getNumVertices();
  if (f2.getNumVertices() != nVertices) return false;

  MVertex *v = f1.getVertex(0);

  // Find the vertex in f2
  int k = 0;
  while (k < nVertices && f2.getVertex(k) != v) ++k;
  if (k == nVertices) return false;

  // Just in case
  if (nVertices == 1) return true;

  // Determine which orientation
  int inc = 0;
  if (f2.getVertex((k+1)%nVertices) == f1.getVertex(1)) inc = 1;
  else if (f2.getVertex((k+nVertices-1)%nVertices) == f1.getVertex(1)) inc = -1;
  if (inc == 0) return false;

  for (int i = 2; i < nVertices; ++i) {
    if (f1.getVertex(i) != f2.getVertex((k+nVertices+inc*i) % nVertices))
      return false;
  }
  return true;
}


bool computeCommonFace(MElement *e1, MElement *e2, MFace &f)
{
  for (int i = 0; i < e1->getNumFaces(); ++i) {
    f = e1->getFace(i);
    for (int j = 0; j < e2->getNumFaces(); ++j) {
      MFace f2 = e2->getFace(j);
      if (areSameFaces(f, f2)) return true;
    }
  }
  f = MFace();
  return false;
}


bool faceContainsVertex(MFace &f, MVertex *v)
{
  for (int i = 0; i < f.getNumVertices(); ++i) {
    if (f.getVertex(i) == v) return true;
  }
  return false;
}


void computeStackPrimaryVertices(const PairMElemVecMElem &c1,
                                 std::vector<MVertex*> &stack)
{
  int numVertexPerLayer = c1.first->getNumPrimaryVertices();
  unsigned int numLayers = c1.second.size();
  stack.clear();
  stack.resize(numVertexPerLayer * numLayers);
  for (unsigned int i = 0; i < stack.size(); ++i) {
    stack[i] = NULL;
  }

  int k = 0;
  for (int i = 0; i < numVertexPerLayer; ++i) {
    stack[k++] = c1.first->getVertex(i);
  }
  MFace bottomFace = c1.first->getFace(0);
  for (unsigned int i = 0; i < numLayers - 1; ++i) {
    MElement *currentElement = c1.second[i];
    MFace topFace;
    if (!computeCommonFace(currentElement, c1.second[i+1], topFace)) {
      Msg::Error("Did not find common face");
    }

    // Eeach edge that is not in bottom face nor in top face links a bottom
    // node with the corresponding top node
    for (int j = 0; j < currentElement->getNumEdges(); ++j) {
      MEdge edge = currentElement->getEdge(j);
      bool v0InBottomFace = faceContainsVertex(bottomFace, edge.getVertex(0));
      bool v1InBottomFace = faceContainsVertex(bottomFace, edge.getVertex(1));
      bool v0InTopFace = faceContainsVertex(topFace, edge.getVertex(0));
      bool v1InTopFace = faceContainsVertex(topFace, edge.getVertex(1));
      if (   (v0InBottomFace && v1InBottomFace)
          || (v0InTopFace && v1InTopFace)      ) continue;

      MVertex *vbot, *vtop;
      if (v0InBottomFace) {
        vbot = edge.getVertex(0);
        vtop = edge.getVertex(1);
      }
      else {
        vbot = edge.getVertex(1);
        vtop = edge.getVertex(0);
      }

      for (int l = k-numVertexPerLayer; l < k; ++l) {
        if (stack[l] == vbot) {
          stack[l+numVertexPerLayer] = vtop;
        }
      }
    }

    // If there remains NULL values, it is because the vertex is the same
    // on bottom face and top face.
    for (int l = k; l < k+numVertexPerLayer; ++l) {
      if (stack[l] == NULL) {
        stack[l] = stack[l-numVertexPerLayer];
      }
    }

    k += numVertexPerLayer;
    bottomFace = topFace;
  }
}


bool computeCommonEdge(MElement *el1, MElement *el2, MEdge &e)
{
  for (int i = 0; i < el1->getNumEdges(); ++i) {
    e = el1->getEdge(i);
    for (int j = 0; j < el2->getNumEdges(); ++j) {
      MEdge thisEdge = el2->getEdge(j);
      if (thisEdge == e) return true;
    }
  }
}


void computeInterface(const PairMElemVecMElem &c1, const PairMElemVecMElem &c2,
                      std::vector<MFaceN> &interface, MEdgeN &bottomEdge,
                      MEdgeN &topEdge)
{
  // Find common edge on boundary
  MElement *bottomElement1 = c1.first;
  MElement *bottomElement2 = c2.first;
  MEdge commonEdge;
  if (!computeCommonEdge(bottomElement1, bottomElement2, commonEdge)) {
    Msg::Error("Couldn't find common edge on bottom elements");
    return;
  }
  bottomEdge = bottomElement1->getHighOrderEdge(commonEdge);

  // Choose biggest column
  PairMElemVecMElem column;
  std::vector<MElement*> stackElements;
  MElement *bottomElement;
  if (c1.second.size() < c2.second.size()) {
    column = c2;
    stackElements = c2.second;
    bottomElement = bottomElement2;
  }
  else {
    column = c1;
    stackElements = c1.second;
    bottomElement = bottomElement1;
  }

  // Compute stack of Primary vertices
  std::vector<MVertex*> allPrimaryVertices;
  computeStackPrimaryVertices(column, allPrimaryVertices);

  std::vector<MVertex*> interfacePrimaryVertices;
  {
    int nVertexPerLayer = bottomElement->getNumPrimaryVertices();
    int n0 = -1;
    int n1 = -1;
    for (int i = 0; i < nVertexPerLayer; ++i) {
      if (bottomEdge.getVertex(0) == allPrimaryVertices[i]) n0 = i;
      if (bottomEdge.getVertex(1) == allPrimaryVertices[i]) n1 = i;
    }
    if (n0 == -1 || n1 == -1) {
      Msg::Error("Error in computeInterface");
      return;
    }
    interfacePrimaryVertices.resize(2*(stackElements.size()));
    for (unsigned int i = 0; i < stackElements.size(); ++i) {
      interfacePrimaryVertices[2*i+0] = allPrimaryVertices[nVertexPerLayer*i+n0];
      interfacePrimaryVertices[2*i+1] = allPrimaryVertices[nVertexPerLayer*i+n1];
    }
  }

  // Compute interface
  interface.clear();
  for (int i = 0; i < stackElements.size() - 1; ++i) {
    MVertex *v0 = interfacePrimaryVertices[2*i+0];
    MVertex *v1 = interfacePrimaryVertices[2*i+1];
    MVertex *v2 = interfacePrimaryVertices[2*i+3];
    MVertex *v3 = interfacePrimaryVertices[2*i+2];
    if (v2 == v1 && v3 == v0) {
      Msg::Error("Error in computeInterface: not an element");
    }
    if (v2 == v1) {
      v2 = v3;
      v3 = NULL;
    }
    else if (v3 == v0) {
      v3 = NULL;
    }
    if (v3 == NULL) {
      interface.push_back(stackElements[i]->getHighOrderFace(MFace(v0, v1, v2)));
      if (   v0 != interface.back().getVertex(0)
          || v1 != interface.back().getVertex(1)
          || v2 != interface.back().getVertex(2))
        Msg::Error("did not get the faceN I wanted!");
//      std::cout << "vertices: " << v0->getNum() << " " << v1->getNum() << " " << v2->getNum() << std::endl;
//      std::cout << "vertices: " << interface.back().getVertex(0)->getNum() << " " << interface.back().getVertex(1)->getNum() << " ";
//      std::cout <<                 interface.back().getVertex(2)->getNum() << std::endl;
    }
    else {
      interface.push_back(stackElements[i]->getHighOrderFace(MFace(v0, v1, v2, v3)));
      if (   v0 != interface.back().getVertex(0)
          || v1 != interface.back().getVertex(1)
          || v2 != interface.back().getVertex(2)
          || v3 != interface.back().getVertex(3))
        Msg::Error("did not get the faceN I wanted!");
//      std::cout << "vertices: " << v0->getNum() << " " << v1->getNum() << " " << v2->getNum() << " " << v3->getNum() << std::endl;
//      std::cout << "vertices: " << interface.back().getVertex(0)->getNum() << " " << interface.back().getVertex(1)->getNum() << " ";
//      std::cout <<                 interface.back().getVertex(2)->getNum() << " " << interface.back().getVertex(3)->getNum() << std::endl;
    }
  }
  topEdge = interface.back().getEdgeN(0, 1);
}


SVector3 getBisectorAtCommonCornerVertex(const MElement *surface1,
                                         const MElement *surface2,
                                         MVertex *corner)
{
  // Assume that 't' is the tangent of the common edge between the two surfaces.
  // This function return the vector 'n' that is normal to 't' and such that
  // the plane generated by 't' and 'n' is the bisector plane of the two
  // surfaces at vertex 'corner'...
  int i1, i2;
  for (i1 = 0; i1 < surface1->getNumPrimaryVertices(); ++i1) {
    if (surface1->getVertex(i1) == corner) break;
  }
  for (i2 = 0; i2 < surface2->getNumPrimaryVertices(); ++i2) {
    if (surface2->getVertex(i2) == corner) break;
  }
  if (i1 > 3 || i2 > 3)
    Msg::Error("Incoherence for computeExtremityCoefficients");

  SVector3 n1, n2;

  double u, v, w;
  double gradients[3][3];

  surface1->getNode(i1, u, v, w);
  surface1->getJacobian(u, v, w, gradients);
  n1 = SVector3(gradients[2][0], gradients[2][1], gradients[2][2]);
//  Msg::Info("surf1 (%g, %g, %g)", u, v, w);

  surface2->getNode(i2, u, v, w);
  surface2->getJacobian(u, v, w, gradients);
  n2 = SVector3(gradients[2][0], gradients[2][1], gradients[2][2]);
//  Msg::Info("surf2 (%g, %g, %g)", u, v, w);

  if (dot(n1, n2) < 0) {
    // This should never happen!
    Msg::Warning("Boundary elements have opposite normals (1) %d -- %d",
                 surface1->getNum(), surface2->getNum());
    // If really cannot prevent opposite normals, then  we should ideally
    // compare to the geometry normal or something... For now, arbitrarily
    // negate one of the normals.
    n1.negate();
  }

  n1.axpy(1, n2);
  n1.normalize();
  return n1;
}


void idealPositionEdge(const MElement *bottom1, const MElement *bottom2,
                       const MEdgeN &baseEdge,
                       const Parameters3DCurve &parameters,
                       int nbPoints, const IntPt *points,
                       fullMatrix<double> &xyz, int triDirection = 0,
                       GFace *gFace = NULL)
{
//  static int ITER = 0;
//  ++ITER;
//  int MOD = 1;
//  int START = 0;

  for (int i = 0; i < nbPoints; ++i) {
    const double &u = points[i].pt[0];
    SPoint3 pnt = baseEdge.pnt(u);
    SVector3 t = baseEdge.tangent(u);

    SVector3 n;
    {
      double xyz[3], uvw[3];
      pnt.position(xyz);

      // TODO: more efficient function? (than xyz2uvw)
      double gradients[3][3];
      bottom1->xyz2uvw(xyz, uvw);
      bottom1->getJacobian(uvw[0], uvw[1], uvw[2], gradients);
      n = SVector3(gradients[2][0], gradients[2][1], gradients[2][2]);
      bottom2->xyz2uvw(xyz, uvw);
      bottom2->getJacobian(uvw[0], uvw[1], uvw[2], gradients);
      SVector3 n2 = SVector3(gradients[2][0], gradients[2][1], gradients[2][2]);

      if (dot(n, n2) < 0) {
        Msg::Warning("Boundary elements have opposite normals (2) %d -- %d",
                     bottom1->getNum(), bottom2->getNum());
        n.negate();
      }
      n.axpy(1, n2);
      n.normalize();
    }

    SVector3 w = crossprod(t, n);

//    if (ITER % MOD == START)
//      draw3DFrame(pnt, t, n, w, .25, gFace);

    int &d = triDirection;
    SVector3 h = parameters.thicknessAtPoint(u, d) * n
                 + parameters.coeffbAtPoint(u, d) * t
                 + parameters.coeffcAtPoint(u, d) * w;
    xyz(i, 0) = pnt.x() + h.x();
    xyz(i, 1) = pnt.y() + h.y();
    xyz(i, 2) = pnt.z() + h.z();
  }
}


void computePosition3DEdge(const MElement *bottom1, const MElement *bottom2,
                           const MEdgeN &baseEdge, const MEdgeN &topEdge,
                           const Parameters3DCurve &parameters,
                           int triDirection, double dampingFactor,
                           GFace *gFace)
{
  // Let (t, n, w) be the local reference frame on 'baseEdge'
  // where t(u) is the unit tangent of the 'baseEdge'
  //       n(u) is unit, normal to 't' and such that (t, n) is bisector of faces
  //            'bottom1' and 'bottom2' at corresponding point
  //       w = t x n
  // We seek for each component the polynomial function that fit the best
  //   x1(u) = x0(u) + h(u) * n(u) + b(u) * t(u) + c(u) * w(u)
  // in the least square sense.
  // where x0(u) is the position of 'baseEdge' and h, b, c are given by
  //       'parameters'

  const int orderCurve = baseEdge.getNumVertices() - 1;
  const int orderGauss = orderCurve * 2;
  const int sizeSystem = getNGQLPts(orderGauss);
  const IntPt *gaussPnts = getGQLPts(orderGauss);

  fullMatrix<double> xyz(sizeSystem + 2, 3);
  idealPositionEdge(bottom1, bottom2, baseEdge, parameters, sizeSystem,
                    gaussPnts, xyz, triDirection, gFace);
//  drawIdealPositionEdge(bottom1, bottom2, baseEdge, parameters, gFace, triDirection);
  for (int i = 0; i < 2; ++i) {
    xyz(sizeSystem+i, 0) = topEdge.getVertex(i)->x();
    xyz(sizeSystem+i, 1) = topEdge.getVertex(i)->y();
    xyz(sizeSystem+i, 2) = topEdge.getVertex(i)->z();
  }

  BoundaryLayerCurver::LeastSquareData *data =
      BoundaryLayerCurver::getLeastSquareData(TYPE_LIN, orderCurve, orderGauss);

  fullMatrix<double> coeff(orderCurve + 1, 3);
  fullMatrix<double> newxyz(orderCurve + 1, 3);
  data->invA.mult(xyz, coeff);
  data->Leg2Lag.mult(coeff, newxyz);

  for (int i = 2; i < topEdge.getNumVertices(); ++i) {
    topEdge.getVertex(i)->x() = newxyz(i, 0);
    topEdge.getVertex(i)->y() = newxyz(i, 1);
    topEdge.getVertex(i)->z() = newxyz(i, 2);
  }
}


void computeExtremityCoefficients(const MElement *bottom1, const MElement *bottom2,
                                  const MEdgeN &baseEdge, const MEdgeN &topEdge,
                                  Parameters3DCurve &parameters)
{
  MVertex *vBase, *vTop;
  SVector3 t, n, w, h;

  vBase = baseEdge.getVertex(0);
  vTop = topEdge.getVertex(0);
  t = baseEdge.tangent(-1);
  n = getBisectorAtCommonCornerVertex(bottom1, bottom2, vBase);
  w = crossprod(t, n);
  h = SVector3(vTop->x() - vBase->x(),
               vTop->y() - vBase->y(),
               vTop->z() - vBase->z());

  parameters.thickness[0] = dot(h, n);
  parameters.coeffb[0] = dot(h, t);
  parameters.coeffc[0] = dot(h, w);

  vBase = baseEdge.getVertex(1);
  vTop = topEdge.getVertex(1);
  t = baseEdge.tangent(1);
  n = getBisectorAtCommonCornerVertex(bottom1, bottom2, vBase);
  w = crossprod(t, n);
  h = SVector3(vTop->x() - vBase->x(),
               vTop->y() - vBase->y(),
               vTop->z() - vBase->z());

  parameters.thickness[1] = dot(h, n);
  parameters.coeffb[1] = dot(h, t);
  parameters.coeffc[1] = dot(h, w);
}


void computePositionInteriorEdgesLinearTFI(std::vector<MFaceN> &column,
                                           const MEdgeN &baseEdge,
                                           const MEdgeN &topEdge)
{
  // Here, we assume that "thickness" is identical on the left and on the
  // right part of the column => identical eta_i
  MVertex *vbot = baseEdge.getVertex(0);
  MVertex *vtop = topEdge.getVertex(0);
  double dX = vtop->x() - vbot->x();
  double dY = vtop->y() - vbot->y();
  double dZ = vtop->z() - vbot->z();
  int componentToLookAt = 0;
  if (std::abs(dY) > std::abs(dX)) {
    if (std::abs(dZ) > std::abs(dY)) componentToLookAt = 2;
    else componentToLookAt = 1;
  }
  else if(std::abs(dZ) > std::abs(dX)) componentToLookAt = 2;

  // Go trough the whole column and compute TFI position of topVertices
  for (int i = 1; i < (int)column.size() - 1; ++i) {
    MEdgeN e = column[i].getEdgeN(0, 1);
    MVertex *v = e.getVertex(0);
    double factor;
    switch (componentToLookAt) {
      case 0: factor = (v->x() - vbot->x()) / dX; break;
      case 1: factor = (v->y() - vbot->y()) / dY; break;
      case 2: factor = (v->z() - vbot->z()) / dZ; break;
    }
    for (int j = 2; j < e.getNumVertices(); ++j) {
      MVertex *vbot = baseEdge.getVertex(j);
      MVertex *vtop = topEdge.getVertex(j);
      MVertex *v = e.getVertex(j);
      v->x() = (1 - factor) * vbot->x() + factor * vtop->x();
      v->y() = (1 - factor) * vbot->y() + factor * vtop->y();
      v->z() = (1 - factor) * vbot->z() + factor * vtop->z();
    }
  }
}


namespace InteriorNodePlacementMatrices {
  fullMatrix<double>* triangle[10] = {NULL, NULL, NULL, NULL, NULL,
                                      NULL, NULL, NULL, NULL, NULL};
  fullMatrix<double>* quadrangle[10] = {NULL, NULL, NULL, NULL, NULL,
                                        NULL, NULL, NULL, NULL, NULL};
  fullMatrix<double>* linearTriangle0[10] = {NULL, NULL, NULL, NULL, NULL,
                                             NULL, NULL, NULL, NULL, NULL};
  fullMatrix<double>* linearTriangle2[10] = {NULL, NULL, NULL, NULL, NULL,
                                             NULL, NULL, NULL, NULL, NULL};
  fullMatrix<double>* linearQuadrangle[10] = {NULL, NULL, NULL, NULL, NULL,
                                              NULL, NULL, NULL, NULL, NULL};

  const fullMatrix<double>* forTriangle(int order, bool linear, int edge = 2)
  {
    if (!linear) {
      if (!triangle[order]) {
        triangle[order] = new fullMatrix<double>();
        *triangle[order] = gmshGenerateInteriorNodePlacementTriangle(order);
      }
      return triangle[order];
    }
    else if (edge == 0) {
      if (!linearTriangle0[order]) {
        linearTriangle0[order] = new fullMatrix<double>();
        *linearTriangle0[order] =
            gmshGenerateInteriorNodePlacementTriangleLinear(order, 0);
      }
      return linearTriangle0[order];
    }
    else if (edge == 2) {
      if (!linearTriangle2[order]) {
        linearTriangle2[order] = new fullMatrix<double>();
        *linearTriangle2[order] =
            gmshGenerateInteriorNodePlacementTriangleLinear(order, 2);
      }
      return linearTriangle2[order];
    }
  }

  const fullMatrix<double>* forQuadrangle(int order, bool linear)
  {
    if (!linear) {
      if (!quadrangle[order]) {
        quadrangle[order] = new fullMatrix<double>();
        *quadrangle[order] = gmshGenerateInteriorNodePlacementQuadrangle(order);
      }
      return quadrangle[order];
    }
    else {
      if (!linearQuadrangle[order]) {
        linearQuadrangle[order] = new fullMatrix<double>();
        *linearQuadrangle[order] =
            gmshGenerateInteriorNodePlacementQuadrangleLinear(order);
      }
      return linearQuadrangle[order];
    }
  }
}


void repositionInteriorNodes(std::vector<MFaceN> &column)
{
  for (unsigned int i = 0; i < column.size(); ++i) {
    MFaceN &f = column[i];
    const fullMatrix<double> *placement = NULL;
    if (f.getNumPrimaryVertices() == 3) {
      // TODO Determine if edge 0 or 2
    }
    else {
      placement = InteriorNodePlacementMatrices::forQuadrangle(f.order(), true);
    }
    f.repositionInteriorNodes(placement);
  }
}


bool curveInterface(std::vector<MFaceN> &column,
                    const MElement *bottom1, const MElement *bottom2,
                    const MEdgeN &baseEdge, MEdgeN &topEdge,
                    double dampingFactor, GFace *bndEnt,
                    bool linear)
{
  // inspired from curve2DQuadColumnTFI

  Parameters3DCurve parameters;
  computeExtremityCoefficients(bottom1, bottom2, baseEdge, topEdge, parameters);
  computePosition3DEdge(bottom1, bottom2, baseEdge, topEdge, parameters,
                        0, dampingFactor, bndEnt);

  computePositionInteriorEdgesLinearTFI(column, baseEdge, topEdge);
  repositionInteriorNodes(column);
}

// compute then curve interfaces between columns
void curveInterfaces(VecPairMElemVecMElem &bndEl2column,
                     std::vector<std::pair<int, int> > &adjacencies,
                     GFace *boundary)
{
  for (unsigned int i = 0; i < adjacencies.size(); ++i) {
    MEdgeN bottomEdge, topEdge;
    std::vector<MFaceN> interface;
    PairMElemVecMElem &column1 = bndEl2column[adjacencies[i].first];
    PairMElemVecMElem &column2 = bndEl2column[adjacencies[i].second];
    bool doIt = true;
//    if (column1.first->getNum() != 861 && column1.first->getNum() != 467)
//      doIt = false;
//    if (column2.first->getNum() != 861 && column2.first->getNum() != 467)
//      doIt = false;

    if (doIt) {
      computeInterface(column1, column2, interface, bottomEdge, topEdge);
      curveInterface(interface, column1.first, column2.first, bottomEdge,
                     topEdge, 0, boundary, true);
//      Msg::Error("RETURN"); return;
    }
  }
}


void computeStackHighOrderFaces(const PairMElemVecMElem &bndEl2column,
                                std::vector<MFaceN> &stack)
{
  const std::vector<MElement*> &column = bndEl2column.second;
  stack.resize(column.size());

  std::vector<MVertex *> allPrimaryVertices;
  computeStackPrimaryVertices(bndEl2column, allPrimaryVertices);
  // FIXME already calculated in computeInterfaces. Reuse them?

  int nVertexPerLayer = bndEl2column.first->getNumPrimaryVertices();
  for (unsigned int j = 0; j < stack.size(); ++j) {
    MFace f;
    if (nVertexPerLayer == 3)
      f = MFace(allPrimaryVertices[j*3+0],
                allPrimaryVertices[j*3+1],
                allPrimaryVertices[j*3+2]);
    else
      f = MFace(allPrimaryVertices[j*4+0],
                allPrimaryVertices[j*4+1],
                allPrimaryVertices[j*4+2],
                allPrimaryVertices[j*4+3]);
    stack[j] = column[j]->getHighOrderFace(f);
  }
}


void curveColumns(VecPairMElemVecMElem &bndEl2column,
                  GFace *boundary)
{
  for (unsigned int i = 0; i < bndEl2column.size(); ++i) {
    std::vector<MFaceN> stackFaces;
    computeStackHighOrderFaces(bndEl2column[i], stackFaces);
  }
}


void curve3DBoundaryLayer(VecPairMElemVecMElem &bndEl2column, GFace *boundary)
{
  std::vector<std::pair<int, int> > adjacencies;
  computeAdjacencies(bndEl2column, adjacencies);

  curveInterfaces(bndEl2column, adjacencies, boundary);

  curveColumns(bndEl2column, boundary);

  for (int i = 0; i < bndEl2column.size(); ++i) {
    Msg::Info("el %d, size %d", bndEl2column[i].first->getNum(), bndEl2column[i].second.size());
  }
}
