// HighOrderMeshOptimizer - Copyright (C) 2013-2024 UCLouvain-ULiege
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
// Contributors: Amaury Johnen

#include <vector>
#include <tuple>
#include <unordered_set>
#include "BoundaryLayerCurver.h"
#include "MQuadrangle.h"
#include "MTriangle.h"
#include "BasisFactory.h"
#include "GFace.h"
#include "orthogonalBasis.h"
#include "bezierBasis.h"
#include "gmshVertex.h"
#include "Geo.h"
#include "MLine.h"
#include "GModel.h"
#include "Options.h"
#include "AnalyseMeshQuality.h"
#include "InnerVertexPlacement.h"
#include "pointsGenerators.h"
#include "qualityMeasuresJacobian.h"

#if defined(HAVE_POST)
#include "PView.h"
#endif

#if defined(HAVE_FLTK)
#include "FlGui.h"
#endif

namespace {
  void drawEquidistantPoints(GEdge *gedge, int N)
  {
    return;
    const std::size_t numLine = gedge->getNumMeshElements();
    for(std::size_t i = 0; i < numLine; ++i) {
      gedge->getMeshElement(i)->setVisibility(0);
    }

    const double umin = gedge->getLowerBound();
    const double umax = gedge->getUpperBound();
    const double step = (umax - umin) / (N - 1);

    for(int i = 0; i < N; ++i) {
      const double u = umin + i * step;
      const GPoint p = gedge->point(u);
      MVertex *v = new MVertex(p.x(), p.y(), p.z());
      gedge->addMeshVertex(v);
      gedge->addLine(new MLine(v, v));
    }
  }

  void drawBezierControlPolygon(const bezierCoeff &controlPoints, GEdge *gedge)
  {
    const int nVert = controlPoints.getNumCoeff();

    MVertex *previous = nullptr;
    for(int i = 0; i < nVert; ++i) {
      MVertex *v = new MVertex(controlPoints(i, 0), controlPoints(i, 1),
                               controlPoints(i, 2), gedge);
      if(previous) {
        MLine *line = new MLine(v, previous);
        gedge->addLine(line);
      }
      gedge->addMeshVertex(v);
      previous = v;
    }
  }

  void drawBezierControlPolygon(const std::vector<MVertex *> &vertices,
                                GEdge *gedge = nullptr)
  {
    if(!gedge) { gedge = *GModel::current()->firstEdge(); }

    const int nVert = (int)vertices.size();
    fullMatrix<double> xyz(nVert, 3);
    for(int i = 0; i < nVert; ++i) {
      xyz(i, 0) = vertices[i]->x();
      xyz(i, 1) = vertices[i]->y();
      xyz(i, 2) = vertices[i]->z();
    }

    bezierCoeff *controlPoints =
      new bezierCoeff(FuncSpaceData(TYPE_LIN, nVert - 1, false), xyz);
    std::vector<bezierCoeff *> allControlPoints(1, controlPoints);

    int numSubdivision = 0; // change this to choose num subdivision
    while(numSubdivision-- > 0) {
      std::vector<bezierCoeff *> gatherSubs;
      for(std::size_t i = 0; i < allControlPoints.size(); ++i) {
        std::vector<bezierCoeff *> tmp;
        allControlPoints[i]->subdivide(tmp);
        gatherSubs.insert(allControlPoints.end(), tmp.begin(), tmp.end());
      }
      allControlPoints.swap(gatherSubs);
    }

    for(std::size_t i = 0; i < allControlPoints.size(); ++i) {
      drawBezierControlPolygon(*allControlPoints[i], gedge);
    }
  }

  void draw3DFrame(SPoint3 &p, SVector3 &t, SVector3 &n, SVector3 &w,
                   double unitDimension, GFace *gFace = nullptr)
  {
    //return;
    if(!gFace) gFace = *GModel::current()->firstFace();

    MVertex *v = new MVertex(p.x(), p.y(), p.z(), gFace);

    SPoint3 pnt = p + n * unitDimension * .75;
    MVertex *vn = new MVertex(pnt.x(), pnt.y(), pnt.z(), gFace);

    pnt = p + w * unitDimension * 2;
    MVertex *vw = new MVertex(pnt.x(), pnt.y(), pnt.z(), gFace);

    pnt = p + t * unitDimension;
    MVertex *vt = new MVertex(pnt.x(), pnt.y(), pnt.z(), gFace);

    gFace->addMeshVertex(v);
    gFace->addMeshVertex(vn);
    //gFace->addMeshVertex(vw);
    //gFace->addMeshVertex(vt);

    MLine *line = new MLine(v, vn);
    gFace->edges().front()->addLine(line);

    line = new MLine(v, vw);
    gFace->edges().front()->addLine(line);

    line = new MLine(v, vt);
    gFace->edges().front()->addLine(line);
  }
} // namespace

namespace BoundaryLayerCurver {
  void projectVertexIntoGFace(MVertex *v, const GFace *gface)
  {
    SPoint3 p = v->point();
    SPoint2 param = gface->parFromPoint(p);
    GPoint projected = gface->point(param);
    v->x() = projected.x();
    v->y() = projected.y();
    v->z() = projected.z();
  }

  void projectVerticesIntoGFace(const MEdgeN *edge, const GFace *gface,
                                bool alsoExtremity = true)
  {
    int i = alsoExtremity ? 0 : 2;

    for(; i < edge->getNumVertices(); ++i)
      projectVertexIntoGFace(edge->getVertex(i), gface);
  }

  void projectVerticesIntoGFace(const MFaceN *face, const GFace *gface,
                                bool alsoBoundary = true)
  {
    int i = alsoBoundary ? 0 : face->getNumVerticesOnBoundary();

    for(; i < face->getNumVertices(); ++i)
      projectVertexIntoGFace(face->getVertex(i), gface);
  }

  namespace EdgeCurver2D {
    // TODO: smooth normals if CAD not available
    // TODO: check quality of elements

    _Frame::_Frame(const MEdgeN *edge, const GFace *gface, const GEdge *gedge,
                   const SVector3 &normal)
      : _normalToTheMesh(normal), _gface(gface), _gedge(gedge),
        _edgeOnBoundary(edge), _newIdea(false)
    {
      const int nVert = (int)edge->getNumVertices();

      if(gface) {
        for(int i = 0; i < nVert; ++i) {
          SPoint2 param;
          bool success =
            reparamMeshVertexOnFace(edge->getVertex(i), gface, param, true);
          _paramVerticesOnGFace[2 * i + 0] = param[0];
          _paramVerticesOnGFace[2 * i + 1] = param[1];
          if(!success) {
            Msg::Warning("Could not compute param of node %d on surface %d",
                         edge->getVertex(i)->getNum(), gface->tag());
          }
          // TODO: Check if periodic face
        }
      }

      if(gedge) {
        for(int i = nVert - 1; i >= 0; --i) {
          bool success = reparamMeshVertexOnEdge(edge->getVertex(i), gedge,
                                                 _paramVerticesOnGEdge[i]);
          if(!success) {
            Msg::Warning("Could not compute param of node %d on edge %d",
                         edge->getVertex(i)->getNum(), gedge->tag());
          }
          // Periodicity check
          else if(gedge->periodic(0) && gedge->getBeginVertex() &&
                  edge->getVertex(i) ==
                    gedge->getBeginVertex()->mesh_vertices[0]) {
            double u0 = gedge->getLowerBound();
            double un = gedge->getUpperBound();
            // FIXME: It seems incorrect, in particular when nVert == 2 and i = 1. In this case
            //  _paramVerticesOnGEdge[0] is not defined yet.
            int k = (nVert == 2 ? 1 - i : (i == 0 ? 2 : nVert - 1));
            double uk = _paramVerticesOnGEdge[k];
            _paramVerticesOnGEdge[i] = uk - u0 < un - uk ? u0 : un;
          }
        }
      }
    }

    _Frame::_Frame(const MEdgeN *edge, const GFace *gface,
                   const SVector3 &normal)
      : _normalToTheMesh(normal), _gface(gface), _gedge(nullptr),
        _edgeOnBoundary(edge), _newIdea(true)
    {
      const int nVert = (int)edge->getNumVertices();

      if(gface) {
        for(int i = 0; i < nVert; ++i) {
          SPoint2 param;
          bool success =
            reparamMeshVertexOnFace(edge->getVertex(i), gface, param, true);
          _paramVerticesOnGFace[2 * i + 0] = param[0];
          _paramVerticesOnGFace[2 * i + 1] = param[1];
          if(!success) {
            Msg::Warning("Could not compute param of node %d on surface %d",
                         edge->getVertex(i)->getNum(), gface->tag());
          }
          // TODO: Check if periodic face
        }
      }
    }

    void _Frame::computeFrame(double paramEdge, SVector3 &t, SVector3 &n,
                              SVector3 &w, bool atExtremity) const
    {
      // Make sure that we execute the right code:
      if (_newIdea && _gedge) Msg::Error("There was an error in BLCurver computeFrame");

      if(_gedge) {
        double paramGeoEdge;
        if(atExtremity) {
          if(paramEdge < 0)
            paramGeoEdge = _paramVerticesOnGEdge[0];
          else
            paramGeoEdge = _paramVerticesOnGEdge[1];
        }
        else
          paramGeoEdge =
            _edgeOnBoundary->interpolate(_paramVerticesOnGEdge, paramEdge);

        t = _gedge->firstDer(paramGeoEdge);
        t.normalize();
      }
      if(!_gedge || t.norm() == 0) {
        if (_newIdea) {
//          Msg::Error("TO BE IMPLEMENTED");
          t = tangentBSpline(_edgeOnBoundary, paramEdge);
          // TODO: Here, I have to change to compute smooth tangent
        }
        else
          t = _edgeOnBoundary->tangent(paramEdge);
      }

      if(_gface) {
        SPoint2 paramGFace;
        if(atExtremity) {
          if(paramEdge < 0)
            paramGFace =
              SPoint2(_paramVerticesOnGFace[0], _paramVerticesOnGFace[1]);
          else
            paramGFace =
              SPoint2(_paramVerticesOnGFace[2], _paramVerticesOnGFace[3]);
        }
        else {
          paramGFace = SPoint2(
            _edgeOnBoundary->interpolate(_paramVerticesOnGFace, paramEdge, 2),
            _edgeOnBoundary->interpolate(_paramVerticesOnGFace + 1, paramEdge,
                                         2));
        }
        w = _gface->normal(paramGFace);
      }
      else {
        w = _normalToTheMesh;
      }
      if(w.norm() == 0) {
        Msg::Error("normal to the CAD or 2Dmesh is nul. BL curving will fail.");
      }
      n = crossprod(w, t);
    }

    SVector3 _Frame::tangentBSpline(const MEdgeN *edge, double u) const
    {
      const int orderBSpline = 2;

      // J'ai l'impression qu'il faut que je calcule _computeBSpline pour différent
      // knots (k1, k2, k3, k4) puis (k2, k3, k4, k5), puis (..) ...
      // De cette facon, j'aurais chaque fonction de la base auquel j'associe un
      // noeud de 'edge'.
      // Et puis je dois régulariser.
      //
      // u in [0, 1]
      // Il y a une transformation à faire pour le domaine.
      // Ou pas ?
      // Si N = nombre points
      // step = 1 / (N-1)
      // knots = -5*step/2:step:1+5*step/2. Il y en a N+3
      // Si je donne (k0,...,k3) à (kN+1,...,kN+4), j'en ai N+2...
      // -1.5 -.5 .5 1.5 2.5 3.5

      const int N = static_cast<double>(edge->getNumVertices());
      double stepKnots = 2. / (N - 1.);

      std::vector<double> knots(4); // if orderBSpline=2
      std::vector<double> coeff(N+2); // if orderBSpline=2
      for (int i = 0; i < N+2; ++i) {
        for (int j = 0; j < 4; ++j) {
          knots[j] = -1 + stepKnots * (-2.5 + i + j); // if orderBSpline=2
        }
        coeff[i] = computeBSplineDerivative(orderBSpline, u, knots);
      }

      // Regularize (for orderBSpline=2)
      coeff[1] += 3 * coeff[0];
      coeff[2] -= 3 * coeff[0];
      coeff[3] += 1 * coeff[0];
      coeff[N-2] += 1 * coeff[N+1];
      coeff[N-1] -= 3 * coeff[N+1];
      coeff[N]   += 3 * coeff[N+1];

      coeff[0] = coeff[1];
      coeff[1] = coeff[N];
      double dx = 0, dy = 0, dz = 0;
      for (size_t i = 0; i < N; ++i) {
        const MVertex *v = edge->getVertex(i);
        dx += coeff[i] * v->x();
        dy += coeff[i] * v->y();
        dz += coeff[i] * v->z();
      }

      return SVector3(dx, dy, dz).unit();
    }

    double _Frame::computeBSpline(size_t n, double u, const std::vector<double>& t) const
    {
      if (n == 0) {
        return (u >= t[0] && u < t[1])? 1.0 : 0.0;
      }
      else {
        double a = (u - t[0]) / (t[n] - t[0]) * computeBSpline(n - 1, u, std::vector<double>(t.begin(), t.begin() + n + 1));
        double b = (t[n + 1] - u) / (t[n + 1] - t[1]) * computeBSpline(n - 1, u, std::vector<double>(t.begin() + 1, t.begin() + n + 2));
        return a + b;
      }
    }

    double _Frame::computeBSplineDerivative(size_t n, double u, const std::vector<double>& t) const
    {
      if (n == 0) {
        return 0.0;
      }
      else {
        double a = 1 / (t[n] - t[0]) * computeBSpline(n - 1, u, std::vector<double>(t.begin(), t.begin() + n + 1))
                   + (u - t[0]) / (t[n] - t[0]) * computeBSplineDerivative(n - 1, u, std::vector<double>(t.begin(), t.begin() + n + 1));
        double b = -1 / (t[n + 1] - t[1]) * computeBSpline(n - 1, u, std::vector<double>(t.begin() + 1, t.begin() + n + 2))
                   + (t[n + 1] - u) / (t[n + 1] - t[1]) * computeBSplineDerivative(n - 1, u, std::vector<double>(t.begin() + 1, t.begin() + n + 2));
        return a + b;
      }
    }

    SPoint3 _Frame::pnt(double u) const
    {
      if (_newIdea) return _edgeOnBoundary->pnt(u);

      if(!_gedge) return SPoint3();

      double paramGeoEdge =
        _edgeOnBoundary->interpolate(_paramVerticesOnGEdge, u);
      GPoint p = _gedge->point(paramGeoEdge);
      return SPoint3(p.x(), p.y(), p.z());
    }

    void _computeParameters(const MEdgeN *baseEdge, const MEdgeN *otherEdge,
                            const _Frame &frame, double coeffs[2][3])
    {
      SVector3 t, n, w, h;
      MVertex *vb, *vt;

      frame.computeFrame(-1, t, n, w, true);
      vb = baseEdge->getVertex(0);
      vt = otherEdge->getVertex(0);
      h = SVector3(vt->x() - vb->x(), vt->y() - vb->y(), vt->z() - vb->z());
      coeffs[0][0] = dot(h, n);
      coeffs[0][1] = dot(h, t);
      coeffs[0][2] = dot(h, w);

//      SPoint3 p1 = frame.pnt(-1);
//      //      SPoint3 p1(vb->x(), vb->y(), vb->z());
//      draw3DFrame(p1, t, n, w, .0004);

      frame.computeFrame(1, t, n, w, true);
      vb = baseEdge->getVertex(1);
      vt = otherEdge->getVertex(1);
      h = SVector3(vt->x() - vb->x(), vt->y() - vb->y(), vt->z() - vb->z());
      coeffs[1][0] = dot(h, n);
      coeffs[1][1] = dot(h, t);
      coeffs[1][2] = dot(h, w);
      //
//      SPoint3 p2 = frame.pnt(1);
//      //      SPoint3 p2(vb->x(), vb->y(), vb->z());
//      draw3DFrame(p2, t, n, w, .0004);
    }

    void _refPntsForALPShiftedCurve(const MEdgeN *baseEdge, const _Frame &frame,
                                    double coeffs[2][3], 
                                    const std::vector<double> &refTarget,
                                    std::vector<double> &refForExtrusion)
    {
      // ALP is for 'arc-length parameterized'
      // The idea is the following:
      //  Consider the points C_i of 'baseEdge' sampled at 'refTarget'.
      //  'baseEdge' is supposed to be ALP, which means that the
      //  arc lengths between the C_i have the same proportions than
      //  the difference between the ref-points 'refTarget'.
      //  Consider the points P_i of 'baseEdge' sampled at 'refForExtrusion'.
      //  Consider the points Q_i of the shifted curve facing the P_i.
      //  Then we want that the arc lengths between the Q_i to have the same
      //  proportions (than the difference between the ref-points 'refTarget').
      // Output:
      //  - 'refForExtrusion' are the ref-points such that the corresponding
      //  shifted xy-points, when associated with ref-points 'refTarget',
      //  implies an ALP of the shifted curve.

      // DONE : Calculer la courbe idéale telle que sa param soit curviligne
      //   Actuellement, à tout point de l'arête précédente, j'associe un point
      //   de la courbe shiftée qui a le même point de référence (dit autrement,
      //   avec les notations décrite plus loin, je fais s(r) = r).
      //   Puis j'applique la correction pour que ça match avec
      //   les noeuds P1 de l'arête en court, ce qui me donne la courbe idéale
      //   dont la paramétrisation n'est pas curviligne. Je pense qu'il faut
      //   essayer d'avoir une paramétrisation proche de la curviligne (je pense
      //   surtout pour l'élément dans le coin). Pour faire ça, voici une idée.
      //   - Soit l'arête précédente : C(t)
      //   (- Soit la courbe idéale : R(r) = C(s(r)) + D(r)
      //       où s(r) est à définir
      //       et D(r) est la correction.)
      //   - Soit la courbe shiftée : Q(r) = C(s(r)) + N(s(r))
      //       où N(r) est le shift constant dans la direction de la normale.
      //   - Objectif : On veut s(r) tel que Q(r) soit une courbe de
      //      paramétrisation curviligne
      //   - Soit les points de Gauss (augmentés) : g_i (g_-1 = -1 et g_n+1 = 1)
      //      et leur différence : h_i = g_i+1 - g_i
      //   - Soit P_i = C(g_i)
      //   - Soit Q_i = Q(g_i) = C(s(g_i)) + N(s(g_i))  (donc pas forcément
      //      en face des P_i, ça dépend de s(r))
      //   - Soit p_i et q_i : o_i = norm(O_i+1 - O_i)  (remplacer o et O)
      //   - On doit calculer s_i = s(g_i) mais on ne connait pas s(r).
      //   - Ici, je fais une approximation (qui est faible si l'épaisseur est
      //      faible. Et si l'épaisseur est importante, c'est moins grave qu'il
      //      y a une grosse erreur). Sachant que h_i est proportionnel à la
      //      longueur du segment de courbe, je dis que
      //        h_i / p_i = tau_i / q_i,
      //      où tau_i est approximativement proportionnel à la longeur du
      //      segment de la courbe shiftée. Donc vu l'objectif, on veut
      //        tau_i / sum(tau_i) = g_i
      //   - Soit une première approximation s^0(r) = r. On a s^0_i = g_i.
      //      Q^0_i = P_0(s^0_i) + N(s^0_i)
      //      q^0_i = norm(Q^0_i+1 - Q^0_i)
      //      tau^0_i = h_i / p_i * q^0_i
      //      kappa^0_i = sum_0_to_i(tau^0_k) / sum(tau^0_i)
      //   - On calcule s^1_i sur l'interpolation linéaire f^0(s) des points
      //      (s^0_i, kappa^0_i) tel que f^0(s^1_i) = g_i

      // FIXME: thickness should be an input, this is a naive code:
      //  or we should keep it and check that ideal curve is ALP instead
      //  of shifted curve
      // FIXME norm3 should be norm3(const double a[3]) 
      //  so that I can have const double coeffs[2][3] here  
      double thickness = .5 * (norm3(coeffs[0]) + norm3(coeffs[1]));
  
      size_t nbPoints = refTarget.size();

      // ratios h_i / p_i
      std::vector<SPoint3> points(nbPoints);
//      points[0] = baseEdge->pnt(-1);
//      points[nbPoints-1] = baseEdge->pnt(1);
      for(size_t i = 0; i < nbPoints; ++i) {
        double u = refTarget[i];
        points[i] = baseEdge->pnt(u);
      }
      std::vector<double> ratios(nbPoints-1);
      for(size_t i = 0; i < nbPoints-1; ++i) {
        double numerator = refTarget[i+1] - refTarget[i];
        ratios[i] = numerator / norm(points[i+1]-points[i]);
      }

      // use now 'points' for shifted ones, extremities are fixed
      SVector3 t, n, w;
      frame.computeFrame(-1, t, n, w);
      points[0] = points[0] + thickness * n;
      frame.computeFrame(1, t, n, w);
      points[nbPoints-1] = points[nbPoints-1] + thickness * n;

      // Init refForExtrusion with refTarget (s^0_i = g_i)
      for(size_t i = 0; i < nbPoints; ++i) refForExtrusion[i] = refTarget[i];

      std::vector<double> taui(nbPoints-1);
      std::vector<double> kappai(nbPoints);
      std::vector<double> refNew(nbPoints);
      int k = 0;
      double maxChanged = 1;

      while(k < 20 && maxChanged > 1e-4) {
        ++k;
        // Compute shifted points
        for(size_t i = 1; i < nbPoints-1; ++i) {
          double u = refForExtrusion[i];
          frame.computeFrame(u, t, n, w);
          points[i] = baseEdge->pnt(u) + thickness * n;
        }
//
//std::cout << "xy{" << k << "} = [" << std::endl;
//for(size_t i = 0; i < nbPoints; ++i) {
//  std::cout << points[i].x() << " " << points[i].y() << std::endl;
//}
//std::cout << "];" << std::endl;

        // Compute corresponding Kappa_i
        double accumulator = 0;
        kappai[0] = 0;
        for(size_t i = 0; i < nbPoints-1; ++i) {
          taui[i] = norm(points[i+1]-points[i]) * ratios[i];
          kappai[i+1] = kappai[i] + taui[i];
          accumulator += taui[i];
        }
        double scale = 2 / accumulator;
        for(size_t i = 0; i < nbPoints; ++i) {
          kappai[i] = scale * kappai[i] - 1;
        }

        // Interpolate
        for(size_t i = 1; i < nbPoints-1; ++i) {
          if(kappai[i] < refTarget[i]) {
            double f = (refTarget[i]-kappai[i]) / (refTarget[i+1]-refTarget[i]);
            refNew[i] = (1-f) * refForExtrusion[i] + f * refForExtrusion[i+1];
          }
          else {
            double f = (kappai[i]-refTarget[i]) / (refTarget[i]-refTarget[i-1]);
            refNew[i] = (1-f) * refForExtrusion[i] + f * refForExtrusion[i-1];
          }
          refNew[i] = .5 * refNew[i] + .5 * refForExtrusion[i];
        }

//
//std::cout << "uv{" << k << "} = [" << std::endl;
//for(size_t i = 0; i < nbPoints; ++i) {
//  std::cout << refForExtrusion[i] << " " << kappai[i] << std::endl;
//}
//std::cout << "];" << std::endl;

        // Update
        maxChanged = 0;
        for(size_t i = 1; i < nbPoints-1; ++i) {
          double diff = std::abs(refNew[i]-refForExtrusion[i]);
          maxChanged = std::max(maxChanged, diff);
          refForExtrusion[i] = refNew[i];
          //std::cout << refForExtrusion[i] << " ";
        }
      }
//      std::cout << k << std::endl;

//int N = 101;
//std::cout << "X = [" << std::endl;
//for(int i = 0; i < N; ++i) {
//  double u = -1 + 2 * (double)i/(N-1);
//  SPoint3 P = baseEdge->pnt(u);
//  std::cout << P.x() << " " << P.y() << " ";
//  frame.computeFrame(u, t, n, w);
//  P = P + thickness * n;
//  std::cout << P.x() << " " << P.y() << std::endl;
//}
//std::cout << "];" << std::endl;


    }

    // FIXME rename sampleIdealCurve?
    void _idealPositionEdge(const MEdgeN *baseEdge, const _Frame &frame,
                            double coeffs[2][3], int nbPoints,
                            const IntPt *points, fullMatrix<double> &xyz)
    {
      // Gauss points + the two extremities
      std::vector<double> refTarget(nbPoints+2);
      refTarget[0] = -1;
      refTarget[nbPoints+1] = 1;
      for(int i = 0; i < nbPoints; ++i) {
        refTarget[i+1] = points[i].pt[0];
      }

      std::vector<double> refPnts(nbPoints+2);
      _refPntsForALPShiftedCurve(baseEdge, frame, coeffs, refTarget, refPnts);

//      for(size_t i = 0; i < nbPoints+2; ++i) {
//        std::cout << refTarget[i] << " " << refPnts[i] << std:: endl;
////        refPnts[i] = refTarget[i];
//      }
//      std::cout << std::endl;

      // TODO : Interpolation angulaire si ouverture, linéaire si fermeture

      double angle1 = atan2(coeffs[0][1], coeffs[0][0]);
      double angle2 = atan2(coeffs[1][1], coeffs[1][0]);

      for(int i = 0; i < nbPoints; ++i) {
        double u = refPnts[i+1];
        SPoint3 p = baseEdge->pnt(u);
        SVector3 t, n, w;
        frame.computeFrame(u, t, n, w);

//        //        draw3DFrame(p, t, n, w, .0002);
//        SPoint3 pp = frame.pnt(u);
//        draw3DFrame(pp, t, n, w, .005);

        double interpolatedCoeffs[3];
        for(int j = 0; j < 3; ++j) {
          interpolatedCoeffs[j] =
            coeffs[0][j] * (1 - u) / 2 + coeffs[1][j] * (1 + u) / 2;
        }
        SVector3 h, h2;
        h = interpolatedCoeffs[0] * n + interpolatedCoeffs[1] * t +
            interpolatedCoeffs[2] * w;

        // TODO: this is for a plane only, adapt the code for 3d!
        double angle = angle1 * (1 - u) / 2 + angle2 * (1 + u) / 2;
        double dist1 = norm3(coeffs[0]);
        double dist2 = norm3(coeffs[1]);
        double dist = dist1 * (1 - u) / 2 + dist2 * (1 + u) / 2;
        h2 = dist * (std::cos(angle) * n + std::sin(angle) * t);
        double uu = dist * std::cos(angle);
        double vv = dist * std::sin(angle);
        // TODO: choose in function of expansion/reduction
        h = h2;
        xyz(i, 0) = p.x() + h.x();
        xyz(i, 1) = p.y() + h.y();
        xyz(i, 2) = p.z() + h.z();
      }
    }

    void _drawIdealPositionEdge(const MEdgeN *baseEdge, const _Frame &frame,
                                double coeffs[2][3], GEdge *gedge = nullptr)
    {
      if(!gedge) gedge = *GModel::current()->firstEdge();
      int N = 100;
      MVertex *previous = nullptr;

      for(int i = 0; i < N + 1; ++i) {
        const double u = (double)i / N * 2 - 1;
        SPoint3 p = baseEdge->pnt(u);
        SVector3 t, n, w;
        frame.computeFrame(u, t, n, w);

        double interpolatedCoeffs[3];
        for(int j = 0; j < 3; ++j) {
          interpolatedCoeffs[j] =
            coeffs[0][j] * (1 - u) / 2 + coeffs[1][j] * (1 + u) / 2;
        }
        SVector3 h;
        h = interpolatedCoeffs[0] * n + interpolatedCoeffs[1] * t +
            interpolatedCoeffs[2] * w;
        double x = p.x() + h.x();
        double y = p.y() + h.y();
        double z = p.z() + h.z();

        MVertex *current = new MVertex(x, y, z, gedge);
        gedge->addMeshVertex(current);
        if(previous) {
          MLine *line = new MLine(previous, current);
          gedge->addLine(line);
        }
        //        MVertex *base = new MVertex(p.x(), p.y(), p.z(), gedge);
        //        MLine *line = new MLine(base, current);
        //        gedge->addLine(line);
        previous = current;
      }
    }

    void curveEdge(const MEdgeN *baseEdge, MEdgeN *edge, const GFace *gface,
                   const GEdge *gedge, const SVector3 &normal)
    {
      _Frame frame(baseEdge, gface, gedge, normal);

      double coeffs[2][3];
      _computeParameters(baseEdge, edge, frame, coeffs);

      const int orderCurve = baseEdge->getPolynomialOrder();
      const int orderGauss = orderCurve * 2;
      const int sizeSystem = getNGQLPts(orderGauss);
      const IntPt *gaussPnts = getGQLPts(orderGauss);

      // Least square projection
      fullMatrix<double> xyz(sizeSystem + 2, 3);
      _idealPositionEdge(baseEdge, frame, coeffs, sizeSystem, gaussPnts, xyz);
      //      _drawIdealPositionEdge(baseEdge, frame, coeffs, (GEdge*)gedge);
      for(int i = 0; i < 2; ++i) {
        xyz(sizeSystem + i, 0) = edge->getVertex(i)->x();
        xyz(sizeSystem + i, 1) = edge->getVertex(i)->y();
        xyz(sizeSystem + i, 2) = edge->getVertex(i)->z();
      }

      LeastSquareData *data =
        getLeastSquareData(TYPE_LIN, orderCurve, orderGauss);
      fullMatrix<double> newxyz(orderCurve + 1, 3);
      data->invA.mult(xyz, newxyz);

      for(int i = 2; i < edge->getNumVertices(); ++i) {
        edge->getVertex(i)->x() = newxyz(i, 0);
        edge->getVertex(i)->y() = newxyz(i, 1);
        edge->getVertex(i)->z() = newxyz(i, 2);
      }

      if(gface) projectVerticesIntoGFace(edge, gface, false);
    }

    void _reduceCurving_newIdea(const fullMatrix<double> &xyz,
                                fullMatrix<double> &new_xyz, double coeff_tang)
    {
      fullMatrix<double> A(15, 7);
      fullMatrix<double> c(15, 3);

      A(0, 0) = -7.3459;
      A(0, 1) = 17.9843;
      A(0, 2) = -22.4737;
      A(0, 3) = 19.9746;
      A(0, 4) = -11.2352;
      A(0, 5) = 3.5951;
      A(0, 6) = -0.49932;
      A(1, 0) = -3.0189;
      A(1, 1) = 2.4697;
      A(1, 2) = 1.7465;
      A(1, 3) = -2.1449;
      A(1, 4) = 1.3297;
      A(1, 5) = -0.44567;
      A(1, 6) = 0.063588;
      A(2, 0) = 0.068021;
      A(2, 1) = -3.4377;
      A(2, 2) = 3.7162;
      A(2, 3) = -0.38885;
      A(2, 4) = 0.037655;
      A(2, 5) = 0.0068591;
      A(2, 6) = -0.002186;
      A(3, 0) = -0.013929;
      A(3, 1) = 0.19409;
      A(3, 2) = -3.5155;
      A(3, 3) = 3.5192;
      A(3, 4) = -0.19866;
      A(3, 5) = 0.014904;
      A(3, 6) = -0.00010118;
      A(4, 0) = 0.00010118;
      A(4, 1) = -0.014904;
      A(4, 2) = 0.19866;
      A(4, 3) = -3.5192;
      A(4, 4) = 3.5155;
      A(4, 5) = -0.19409;
      A(4, 6) = 0.013929;
      A(5, 0) = 0.002186;
      A(5, 1) = -0.0068591;
      A(5, 2) = -0.037655;
      A(5, 3) = 0.38885;
      A(5, 4) = -3.7162;
      A(5, 5) = 3.4377;
      A(5, 6) = -0.068021;
      A(6, 0) = -0.063588;
      A(6, 1) = 0.44567;
      A(6, 2) = -1.3297;
      A(6, 3) = 2.1449;
      A(6, 4) = -1.7465;
      A(6, 5) = -2.4697;
      A(6, 6) = 3.0189;
      A(7, 0) = 0.49932;
      A(7, 1) = -3.5951;
      A(7, 2) = 11.2352;
      A(7, 3) = -19.9746;
      A(7, 4) = 22.4737;
      A(7, 5) = -17.9843;
      A(7, 6) = 7.3459;

//      c(0, 0) =  (+ -12 * xyz(0, 0) + 21 * xyz(1, 0) + -12 * xyz(2, 0) + 3 * xyz(3, 0))/2;
//      c(0, 1) =  (+ -12 * xyz(0, 1) + 21 * xyz(1, 1) + -12 * xyz(2, 1) + 3 * xyz(3, 1))/2;
//      c(0, 2) =  (+ -12 * xyz(0, 2) + 21 * xyz(1, 2) + -12 * xyz(2, 2) + 3 * xyz(3, 2))/2;
//      c(7, 0) =  (+ -3 * xyz(3, 0) + 12 * xyz(4, 0) + -21 * xyz(5, 0) + 12 * xyz(6, 0))/2;
//      c(7, 1) =  (+ -3 * xyz(3, 1) + 12 * xyz(4, 1) + -21 * xyz(5, 1) + 12 * xyz(6, 1))/2;
//      c(7, 2) =  (+ -3 * xyz(3, 2) + 12 * xyz(4, 2) + -21 * xyz(5, 2) + 12 * xyz(6, 2))/2;
//      c(1, 0) =  (+ -6.408 * xyz(0, 0) + 6.816 * xyz(1, 0) + -0.408 * xyz(2, 0))/2;
//      c(1, 1) =  (+ -6.408 * xyz(0, 1) + 6.816 * xyz(1, 1) + -0.408 * xyz(2, 1))/2;
//      c(1, 2) =  (+ -6.408 * xyz(0, 2) + 6.816 * xyz(1, 2) + -0.408 * xyz(2, 2))/2;
//      c(6, 0) =  (+ 0.408 * xyz(4, 0) + -6.816 * xyz(5, 0) + 6.408 * xyz(6, 0))/2;
//      c(6, 1) =  (+ 0.408 * xyz(4, 1) + -6.816 * xyz(5, 1) + 6.408 * xyz(6, 1))/2;
//      c(6, 2) =  (+ 0.408 * xyz(4, 2) + -6.816 * xyz(5, 2) + 6.408 * xyz(6, 2))/2;
//      c(2, 0) =  + 0.068021 * xyz(0, 0) + -3.4377 * xyz(1, 0) + 3.7162 * xyz(2, 0) + -0.38885 * xyz(3, 0) + 0.037655 * xyz(4, 0) + 0.0068591 * xyz(5, 0) + -0.002186 * xyz(6, 0);
//      c(2, 1) =  + 0.068021 * xyz(0, 1) + -3.4377 * xyz(1, 1) + 3.7162 * xyz(2, 1) + -0.38885 * xyz(3, 1) + 0.037655 * xyz(4, 1) + 0.0068591 * xyz(5, 1) + -0.002186 * xyz(6, 1);
//      c(2, 2) =  + 0.068021 * xyz(0, 2) + -3.4377 * xyz(1, 2) + 3.7162 * xyz(2, 2) + -0.38885 * xyz(3, 2) + 0.037655 * xyz(4, 2) + 0.0068591 * xyz(5, 2) + -0.002186 * xyz(6, 2);
//      c(3, 0) =  + -0.013929 * xyz(0, 0) + 0.19409 * xyz(1, 0) + -3.5155 * xyz(2, 0) + 3.5192 * xyz(3, 0) + -0.19866 * xyz(4, 0) + 0.014904 * xyz(5, 0) + -0.00010118 * xyz(6, 0);
//      c(3, 1) =  + -0.013929 * xyz(0, 1) + 0.19409 * xyz(1, 1) + -3.5155 * xyz(2, 1) + 3.5192 * xyz(3, 1) + -0.19866 * xyz(4, 1) + 0.014904 * xyz(5, 1) + -0.00010118 * xyz(6, 1);
//      c(3, 2) =  + -0.013929 * xyz(0, 2) + 0.19409 * xyz(1, 2) + -3.5155 * xyz(2, 2) + 3.5192 * xyz(3, 2) + -0.19866 * xyz(4, 2) + 0.014904 * xyz(5, 2) + -0.00010118 * xyz(6, 2);
//      c(4, 0) =  + 0.00010118 * xyz(0, 0) + -0.014904 * xyz(1, 0) + 0.19866 * xyz(2, 0) + -3.5192 * xyz(3, 0) + 3.5155 * xyz(4, 0) + -0.19409 * xyz(5, 0) + 0.013929 * xyz(6, 0);
//      c(4, 1) =  + 0.00010118 * xyz(0, 1) + -0.014904 * xyz(1, 1) + 0.19866 * xyz(2, 1) + -3.5192 * xyz(3, 1) + 3.5155 * xyz(4, 1) + -0.19409 * xyz(5, 1) + 0.013929 * xyz(6, 1);
//      c(4, 2) =  + 0.00010118 * xyz(0, 2) + -0.014904 * xyz(1, 2) + 0.19866 * xyz(2, 2) + -3.5192 * xyz(3, 2) + 3.5155 * xyz(4, 2) + -0.19409 * xyz(5, 2) + 0.013929 * xyz(6, 2);
//      c(5, 0) =  + 0.002186 * xyz(0, 0) + -0.0068591 * xyz(1, 0) + -0.037655 * xyz(2, 0) + 0.38885 * xyz(3, 0) + -3.7162 * xyz(4, 0) + 3.4377 * xyz(5, 0) + -0.068021 * xyz(6, 0);
//      c(5, 1) =  + 0.002186 * xyz(0, 1) + -0.0068591 * xyz(1, 1) + -0.037655 * xyz(2, 1) + 0.38885 * xyz(3, 1) + -3.7162 * xyz(4, 1) + 3.4377 * xyz(5, 1) + -0.068021 * xyz(6, 1);
//      c(5, 2) =  + 0.002186 * xyz(0, 2) + -0.0068591 * xyz(1, 2) + -0.037655 * xyz(2, 2) + 0.38885 * xyz(3, 2) + -3.7162 * xyz(4, 2) + 3.4377 * xyz(5, 2) + -0.068021 * xyz(6, 2);

//      c(0, 0) =  (-1 * xyz(0, 0) + 1 * xyz(6, 0))/2;
//      c(0, 1) =  (-1 * xyz(0, 1) + 1 * xyz(6, 1))/2;
//      c(0, 2) =  (-1 * xyz(0, 2) + 1 * xyz(6, 2))/2;
//      c(1, 0) =  (-1 * xyz(0, 0) + 1 * xyz(6, 0))/2;
//      c(1, 1) =  (-1 * xyz(0, 1) + 1 * xyz(6, 1))/2;
//      c(1, 2) =  (-1 * xyz(0, 2) + 1 * xyz(6, 2))/2;
//      c(2, 0) =  (-1 * xyz(0, 0) + 1 * xyz(6, 0))/2;
//      c(2, 1) =  (-1 * xyz(0, 1) + 1 * xyz(6, 1))/2;
//      c(2, 2) =  (-1 * xyz(0, 2) + 1 * xyz(6, 2))/2;
//      c(3, 0) =  (-1 * xyz(0, 0) + 1 * xyz(6, 0))/2;
//      c(3, 1) =  (-1 * xyz(0, 1) + 1 * xyz(6, 1))/2;
//      c(3, 2) =  (-1 * xyz(0, 2) + 1 * xyz(6, 2))/2;
//      c(4, 0) =  (-1 * xyz(0, 0) + 1 * xyz(6, 0))/2;
//      c(4, 1) =  (-1 * xyz(0, 1) + 1 * xyz(6, 1))/2;
//      c(4, 2) =  (-1 * xyz(0, 2) + 1 * xyz(6, 2))/2;
//      c(5, 0) =  (-1 * xyz(0, 0) + 1 * xyz(6, 0))/2;
//      c(5, 1) =  (-1 * xyz(0, 1) + 1 * xyz(6, 1))/2;
//      c(5, 2) =  (-1 * xyz(0, 2) + 1 * xyz(6, 2))/2;
//      c(6, 0) =  (-1 * xyz(0, 0) + 1 * xyz(6, 0))/2;
//      c(6, 1) =  (-1 * xyz(0, 1) + 1 * xyz(6, 1))/2;
//      c(6, 2) =  (-1 * xyz(0, 2) + 1 * xyz(6, 2))/2;
//      c(7, 0) =  (-1 * xyz(0, 0) + 1 * xyz(6, 0))/2;
//      c(7, 1) =  (-1 * xyz(0, 1) + 1 * xyz(6, 1))/2;
//      c(7, 2) =  (-1 * xyz(0, 2) + 1 * xyz(6, 2))/2;

      SVector3 tangents[8];
      double norms[8];
      double normsSorted[8];
      tangents[0](0) = ( + -9 * xyz(0, 0) + 12 * xyz(1, 0) + -3 * xyz(2, 0))/2;
      tangents[0](1) = ( + -9 * xyz(0, 1) + 12 * xyz(1, 1) + -3 * xyz(2, 1))/2;
      tangents[0](2) = ( + -9 * xyz(0, 2) + 12 * xyz(1, 2) + -3 * xyz(2, 2))/2;
      tangents[1](0) = ( + -6.4257 * xyz(0, 0) + 6.8515 * xyz(1, 0) + -0.42574 * xyz(2, 0))/2;
      tangents[1](1) = ( + -6.4257 * xyz(0, 1) + 6.8515 * xyz(1, 1) + -0.42574 * xyz(2, 1))/2;
      tangents[1](2) = ( + -6.4257 * xyz(0, 2) + 6.8515 * xyz(1, 2) + -0.42574 * xyz(2, 2))/2;
      tangents[2](0) = ( + -0.37714 * xyz(0, 0) + -5.2457 * xyz(1, 0) + 5.6229 * xyz(2, 0))/2;
      tangents[2](1) = ( + -0.37714 * xyz(0, 1) + -5.2457 * xyz(1, 1) + 5.6229 * xyz(2, 1))/2;
      tangents[2](2) = ( + -0.37714 * xyz(0, 2) + -5.2457 * xyz(1, 2) + 5.6229 * xyz(2, 2))/2;
      tangents[3](0) = ( + -0.0045005 * xyz(1, 0) + -5.991 * xyz(2, 0) + 5.9955 * xyz(3, 0))/2;
      tangents[3](1) = ( + -0.0045005 * xyz(1, 1) + -5.991 * xyz(2, 1) + 5.9955 * xyz(3, 1))/2;
      tangents[3](2) = ( + -0.0045005 * xyz(1, 2) + -5.991 * xyz(2, 2) + 5.9955 * xyz(3, 2))/2;
      tangents[4](0) = ( + -5.9955 * xyz(3, 0) + 5.991 * xyz(4, 0) + 0.0045005 * xyz(5, 0))/2;
      tangents[4](1) = ( + -5.9955 * xyz(3, 1) + 5.991 * xyz(4, 1) + 0.0045005 * xyz(5, 1))/2;
      tangents[4](2) = ( + -5.9955 * xyz(3, 2) + 5.991 * xyz(4, 2) + 0.0045005 * xyz(5, 2))/2;
      tangents[5](0) = ( + -5.6229 * xyz(4, 0) + 5.2457 * xyz(5, 0) + 0.37714 * xyz(6, 0))/2;
      tangents[5](1) = ( + -5.6229 * xyz(4, 1) + 5.2457 * xyz(5, 1) + 0.37714 * xyz(6, 1))/2;
      tangents[5](2) = ( + -5.6229 * xyz(4, 2) + 5.2457 * xyz(5, 2) + 0.37714 * xyz(6, 2))/2;
      tangents[6](0) = ( + 0.42574 * xyz(4, 0) + -6.8515 * xyz(5, 0) + 6.4257 * xyz(6, 0))/2;
      tangents[6](1) = ( + 0.42574 * xyz(4, 1) + -6.8515 * xyz(5, 1) + 6.4257 * xyz(6, 1))/2;
      tangents[6](2) = ( + 0.42574 * xyz(4, 2) + -6.8515 * xyz(5, 2) + 6.4257 * xyz(6, 2))/2;
      tangents[7](0) = ( + 3 * xyz(4, 0) + -12 * xyz(5, 0) + 9 * xyz(6, 0))/2;
      tangents[7](1) = ( + 3 * xyz(4, 1) + -12 * xyz(5, 1) + 9 * xyz(6, 1))/2;
      tangents[7](2) = ( + 3 * xyz(4, 2) + -12 * xyz(5, 2) + 9 * xyz(6, 2))/2;
      for (int i = 0; i < 8; ++i) {
        norms[i] = tangents[i].norm();
        normsSorted[i] = norms[i];
      }
      std::sort(&(normsSorted[0]), &(normsSorted[8]));
      double myNorm = .9*.5 * (normsSorted[3] + normsSorted[4]);
      for (int i = 0; i < 8; ++i) {
//        std::cout << norms[i] << " ";
        tangents[i](0) = tangents[i](0) / norms[i] * myNorm;
        tangents[i](1) = tangents[i](1) / norms[i] * myNorm;
        tangents[i](2) = tangents[i](2) / norms[i] * myNorm;
      }
      for (int i = 0; i < 8; ++i) {
                c(i, 0) = tangents[i](0);
                c(i, 1) = tangents[i](1);
                c(i, 2) = tangents[i](2);
      }

//      std::cout << " => " << norms[7] << "-" << norms[0] << " = " << norms[7] - norms[0];
//      std::cout << "  tang0 (" << tangents[0](0) << ", " << tangents[0](1) << ", " << tangents[0](2) << ")";
//      std::cout << "  tang7 (" << tangents[7](0) << ", " << tangents[7](1) << ", " << tangents[7](2) << ")";
//      std::cout << std::endl;



      for (int i = 0; i < 8; ++i) {
        c(i, 0) -= A(i, 0) * xyz(0, 0);
        c(i, 1) -= A(i, 0) * xyz(0, 1);
        c(i, 2) -= A(i, 0) * xyz(0, 2);
        A(i, 0) = 0;
        c(i, 0) -= A(i, 6) * xyz(6, 0);
        c(i, 1) -= A(i, 6) * xyz(6, 1);
        c(i, 2) -= A(i, 6) * xyz(6, 2);
        A(i, 6) = 0;
      }

      A.scale(coeff_tang);
      c.scale(coeff_tang);

//      A(8, 0) = 1;
//      c(8, 0) = xyz(0, 0);
//      c(8, 1) = xyz(0, 1);
//      c(8, 2) = xyz(0, 2);
//      A(9, 6) = 1;
//      c(9, 0) = xyz(6, 0);
//      c(9, 1) = xyz(6, 1);
//      c(9, 2) = xyz(6, 2);

      for (int i = 0; i < 7; ++i) {
        A(8+i, i) = 1;
        c(8+i, 0) = xyz(i, 0);
        c(8+i, 1) = xyz(i, 1);
        c(8+i, 2) = xyz(i, 2);
      }

      fullMatrix<double> B = A.transpose();
      fullMatrix<double> C(7, 7);
      fullMatrix<double> d(7, 3);
      //fullMatrix<double> x(7, 3);
      B.mult(A, C);
      B.mult(c, d);
      C.invertInPlace();
      new_xyz.resize(7, 3);
      C.mult(d, new_xyz);



      // extremity (from bspln3 : -12 21 -12 3)
      // at .0715 (from bspln2 : -6.408	6.816	-0.408)
      // at .2395 .4165 from curve
    }

    void _reduceCurving_newIdea(MEdgeN *edge, double max_diff, const GFace *gface)
    {
      int order = edge->getPolynomialOrder();

      if (order != 6) {
        Msg::Error("_reduceCurving_newIdea not implemented for order not 6");
        return;
      }

      fullMatrix<double> xyz(order + 1, 3);
      fullMatrix<double> new_xyz;

      MVertex *v0 = edge->getVertex(0);
      MVertex *v1 = edge->getVertex(1);
      xyz(0, 0) = v0->x();
      xyz(0, 1) = v0->y();
      xyz(0, 2) = v0->z();
      xyz(order, 0) = v1->x();
      xyz(order, 1) = v1->y();
      xyz(order, 2) = v1->z();

      for (int i = 2; i < order + 1; ++i) {
        MVertex *v = edge->getVertex(i);
        xyz(i - 1, 0) = v->x();
        xyz(i - 1, 1) = v->y();
        xyz(i - 1, 2) = v->z();
        //std::cout << " (" << xyz(i-2, 0) << "," << xyz(i-2, 1) << "," << xyz(i-2, 2) << ")  ";
      }
      //std::cout << "(max=" << max_diff << ")" << std::endl;

      double coeff = 1;
      double diff = 2 * max_diff;

      int k = 1;
      while (diff > max_diff || diff < .9 * max_diff) {
        _reduceCurving_newIdea(xyz, new_xyz, coeff);
        double thisMaxDiff = 0;
        for (int i = 0; i < order + 1; ++i) {
          double dx = xyz(i, 0) - new_xyz(i, 0);
          double dy = xyz(i, 1) - new_xyz(i, 1);
          double dz = xyz(i, 2) - new_xyz(i, 2);
          double diff = std::sqrt(dx*dx + dy*dy + dz*dz);
          thisMaxDiff = std::max(thisMaxDiff, diff);
          //std::cout << diff << " (" << xyz(i, 0) << "," << xyz(i, 1) << "," << xyz(i, 2) << ")-(" << new_xyz(i, 0) << "," << new_xyz(i, 1) << "," << new_xyz(i, 2) << ")  ";
        }
        //std::cout << "(max=" << max_diff << ")" << std::endl;
//        std::cout << coeff << ": " << thisMaxDiff << "/" << max_diff << std::endl;
        coeff = coeff / thisMaxDiff * max_diff * .95;
        if (++k == 40) break;
        diff = thisMaxDiff;
      }

      for (int i = 0; i < order + 1; ++i) {
        double dx = xyz(i, 0) - new_xyz(i, 0);
        double dy = xyz(i, 1) - new_xyz(i, 1);
        double dz = xyz(i, 2) - new_xyz(i, 2);
        double diff = std::sqrt(dx*dx + dy*dy + dz*dz);
//        std::cout << diff << " (" << xyz(i, 0) << "," << xyz(i, 1) << "," << xyz(i, 2) << ")-(" << new_xyz(i, 0) << "," << new_xyz(i, 1) << "," << new_xyz(i, 2) << ")  ";
      }
//      std::cout << "(max=" << max_diff << ")" << std::endl;

      v0->x() = new_xyz(0, 0);
      v0->y() = new_xyz(0, 1);
      v0->z() = new_xyz(0, 2);
      v1->x() = new_xyz(order, 0);
      v1->y() = new_xyz(order, 1);
      v1->z() = new_xyz(order, 2);

      for (int i = 2; i < order + 1; ++i) {
        MVertex *v = edge->getVertex(i);
        v->x() = new_xyz(i - 1, 0);
        v->y() = new_xyz(i - 1, 1);
        v->z() = new_xyz(i - 1, 2);
      }

      // 1) Create matrix to assemble
      // 2) Add equation tangent
      // 3) Fix extremity nodes
      // 4) solve
      // 5) iterate
      if(gface) projectVerticesIntoGFace(edge, gface, false);
    }

    void _construct_matrices(const fullMatrix<double> &xyz_gmsh,
      const fullMatrix<double> &xyz_seq,
      const SVector3 dir_extremities[2],
      fullMatrix<double> &A_lin, fullMatrix<double> &b_lin,
      fullMatrix<double> &A_pos, fullMatrix<double> &b_pos,
      fullMatrix<double> &A_ext, fullMatrix<double> &b_ext,
      fullMatrix<double> &A_tg1, fullMatrix<double> &b_tg1,
      fullMatrix<double> &A_tg2, fullMatrix<double> &b_tg2)
    {
      int polyo = xyz_gmsh.size1() - 1;

      fullMatrix<double> bspl_tg(2*polyo - 1, 3);
      for(int i = 0; i < 2*polyo - 1; ++i) {
        if (i % 2 == 0) {
          int ii = i / 2;
          for (int j = 0; j < 3; ++j) {
            bspl_tg(i, j) = xyz_seq(ii + 1, j) - xyz_seq(ii, j);
          }
        }
        else {
          int ii = (i-1) / 2;
          for (int j = 0; j < 3; ++j) {
            bspl_tg(i, j) = .5 * (xyz_seq(ii + 2, j) - xyz_seq(ii, j));
          }
        }
      }
      bspl_tg.scale(polyo/2);
      fullVector<double> bspl_tg_length(2*polyo - 1);
      for(int i = 0; i < 2*polyo - 1; ++i) {
        SVector3 v(bspl_tg(i, 0), bspl_tg(i, 1), bspl_tg(i, 2));
        bspl_tg_length(i) = v.norm();
      }

      const int tagLine = ElementType::getType(TYPE_LIN, polyo);
      const nodalBasis *nb = BasisFactory::getNodalBasis(tagLine);
      const fullMatrix<double> &refNodes_gmsh = nb->getReferenceNodes();
      // refNodes_gmsh.print(std::string("refNodes_gmsh"), std::string(""));
      int nbDof = refNodes_gmsh.size1();
      fullMatrix<double> refNodes_seq(polyo + 1, 1);
      refNodes_seq(0, 0) = refNodes_gmsh(0, 0);
      // refNodes_seq(0, 1) = refNodes_gmsh(0, 1);
      // refNodes_seq(0, 2) = refNodes_gmsh(0, 2);
      for(int i = 1; i < polyo; ++i) {
        refNodes_seq(i, 0) = refNodes_gmsh(i+1, 0);
        // refNodes_seq(i, 1) = refNodes_gmsh(i+1, 1);
        // refNodes_seq(i, 2) = refNodes_gmsh(i+1, 2);
      }
      refNodes_seq(polyo, 0) = refNodes_gmsh(1, 0);
      // refNodes_seq(polyo, 1) = refNodes_gmsh(1, 1);
      // refNodes_seq(polyo, 2) = refNodes_gmsh(1, 2);

      // 1) Construct Position linear system
      A_pos = fullMatrix<double>(polyo - 1, polyo + 1);
      b_pos = fullMatrix<double>(polyo - 1, 3);
      for(int i = 2; i < polyo + 1; ++i) {
        int I = i - 2;
        A_pos(I, i) = 1;
        for(int j = 0; j < 3; ++j) { b_pos(I, j) = xyz_gmsh(i, j); }
      }
      // A_pos.print(std::string("A_pos:"),std::string(""));
      // b_pos.print(std::string("b_pos:"),std::string(""));

      // 2) Construct Tangent linear system
      const double amplification = 1.; // Hack
      A_tg1 = fullMatrix<double>(polyo, polyo + 1);
      b_tg1 = fullMatrix<double>(polyo, 3);
      for(int i = 0; i < polyo; ++i) {
        int I = i;
        double u = .5 * (refNodes_seq(i, 0) + refNodes_seq(i+1, 0));
        // std::cout << "u = " << u << std::endl;
        // double sf[100];
        double grads[100][3];
        nb->df(u, 0, 0, grads);
        for(int j = 0; j < nbDof; ++j) { A_tg1(I, j) = grads[j][0]; }
        // for(int j = 0; j < 3; ++j) { b_tg(I, j) = xyz(i+1, j) - xyz(i, j); }
        for(int j = 0; j < 3; ++j) { b_tg1(I, j) = bspl_tg(i*2, j); }
      }

      A_tg2 = fullMatrix<double>(polyo - 1, polyo + 1);
      b_tg2 = fullMatrix<double>(polyo - 1, 3);
      for(int i = 1; i < polyo; ++i) {
        int I = i - 1;
        double u = refNodes_seq(i, 0);
        // std::cout << "_u = " << u << std::endl;
        // double sf[100];
        // nb->f(u, 0, 0, sf);
        // for(int j = 0; j < nbDof; ++j) { A_tg(I, j) = sf[j]; }
        double grads[100][3];
        nb->df(u, 0, 0, grads);
        for(int j = 0; j < nbDof; ++j) { A_tg2(I, j) = grads[j][0]; }
        // for(int j = 0; j < 3; ++j) {
        //   b_tg(I, j) = .5 * (xyz(i+1, j) - xyz(i-1, j));
        // }
        for(int j = 0; j < 3; ++j) { b_tg2(I, j) = bspl_tg(i*2-1, j); }
      }

      b_tg1.scale(amplification);
      b_tg2.scale(amplification);
      // A_tg1.print(std::string("A_tg1:"),std::string(""));
      // b_tg1.print(std::string("b_tg1:"),std::string(""));
      // A_tg2.print(std::string("A_tg2:"),std::string(""));
      // b_tg2.print(std::string("b_tg2:"),std::string(""));

      // 3) Construct Extremity tangent linear system
      A_ext = fullMatrix<double>(2, polyo + 1);
      b_ext = fullMatrix<double>(2, 3);

      double desired_lengths[2] = {2*bspl_tg_length(0) - bspl_tg_length(1),
        2*bspl_tg_length(2*polyo-2) - bspl_tg_length(2*polyo-3)};
      // bspl_tg_length.print(std::string("bspl_tg_length:"),std::string(""));

      for(int i = 0; i < 2; ++i) {
        // double sf[100];
        double grads[100][3];
        nb->df(i ? 1 : -1, 0, 0, grads);
        for(int j = 0; j < nbDof; ++j) { A_ext(i, j) = grads[j][0]; } // TODO check
        for(int j = 0; j < 3; ++j) { b_ext(i, j) = desired_lengths[i] * dir_extremities[i](j); }
      }
      b_ext.scale(amplification);
      // A_ext.print(std::string("A_ext:"),std::string(""));
      // b_ext.print(std::string("b_ext:"),std::string(""));

      // 4) Construct Linear tangent linear system
      fullMatrix<double> A_lin_tg(polyo, polyo + 1);
      fullMatrix<double> b_lin_tg(polyo, 3);
      double vx = xyz_gmsh(1, 0) - xyz_gmsh(0, 0);
      double vy = xyz_gmsh(1, 1) - xyz_gmsh(0, 1);
      double vz = xyz_gmsh(1, 2) - xyz_gmsh(0, 2);
      SVector3 t(vx, vy, vz);
      t *= .5;
      for(int i = 0; i < polyo; ++i) {
        for(int j = 0; j < polyo+1; ++j) { A_lin_tg(i, j) = A_tg1(i, j); }
        for(int j = 0; j < 3; ++j) { b_lin_tg(i, j) = t(j); }
      }

      fullMatrix<double> A_lin_pos = A_pos;
      fullMatrix<double> b_lin_pos(polyo - 1, 3);
      // SPoint3 x_0(xyz_gmsh(0, 0), xyz_gmsh(0, 1), xyz_gmsh(0, 2));
      t *= 2;
      for(int i = 0; i < polyo - 1; ++i) {
        for(int j = 0; j < 3; ++j) { b_lin_pos(i, j) = xyz_gmsh(0, j) + (i+1.) / polyo * t(j); }
      }

      // A_lin = A_lin_tg;
      // b_lin = b_lin_tg;
      A_lin = A_lin_pos;
      b_lin = b_lin_pos;
      // A_lin = fullMatrix<double>(2 * polyo - 1, polyo + 1);
      // b_lin = fullMatrix<double>(2 * polyo - 1, 3);
      // A_lin.copy(A_lin_tg, 0, polyo, 0, polyo + 1, 0, 0);
      // b_lin.copy(b_lin_tg, 0, polyo, 0,         3, 0, 0);
      // A_lin.copy(A_lin_pos, 0, polyo - 1, 0, polyo + 1, polyo, 0);
      // b_lin.copy(b_lin_pos, 0, polyo - 1, 0,         3, polyo, 0);
      // A_lin.print(std::string("A_lin:"),std::string(""));
      // b_lin.print(std::string("b_lin:"),std::string(""));
      // bspl_tg_length.print(std::string("bspl_tg_length:"),std::string(""));
      // bspl_tg.print(std::string("bspl_tg:"),std::string(""));
    }

    void _construct_test_system(
      const fullMatrix<double> &A_lin, const fullMatrix<double> &b_lin,
      const fullMatrix<double> &A_pos, const fullMatrix<double> &b_pos,
      const fullMatrix<double> &A_ext, const fullMatrix<double> &b_ext,
      const fullMatrix<double> &A_tg1, const fullMatrix<double> &b_tg1,
      const fullMatrix<double> &A_tg2, const fullMatrix<double> &b_tg2,
      fullMatrix<double> &A, fullMatrix<double> &b)
    {
      // Choose
      int sz_lin = A_lin.size1();
      int sz_ext = A_ext.size1();
      int sz_pos = A_pos.size1();
      int sz_tg1 = A_tg1.size1();
      int sz_tg2 = A_tg2.size1();

      double coeff_lin = .0000001;
      double coeff_pos = .00000001;
      double coeff_ext = .00000001;
      // Between those two, none is stable alone, but they seems stable together.
      // This observation may be dependent on the way edges are curved, in
      // particular the preservation of arc-length nature of edges (see ALP)
      double coeff_tg1 = 1000;
      double coeff_tg2 = 1000;

      int SZ = sz_lin + sz_pos + sz_ext + sz_tg1 + sz_tg2;
      int polyo = A_lin.size2() - 1;
      A = fullMatrix<double>(SZ, polyo+1);
      b = fullMatrix<double>(SZ, 3);

      int desti0 = 0;
      fullMatrix<double> tmp;
      tmp = A_lin; tmp.scale(coeff_lin);
      A.copy(tmp, 0, sz_lin, 0, polyo+1, desti0, 0); desti0 += sz_lin;
      tmp = A_pos; tmp.scale(coeff_pos);
      A.copy(tmp, 0, sz_pos, 0, polyo+1, desti0, 0); desti0 += sz_pos;
      tmp = A_ext; tmp.scale(coeff_ext);
      A.copy(tmp, 0, sz_ext, 0, polyo+1, desti0, 0); desti0 += sz_ext;
      tmp = A_tg1; tmp.scale(coeff_tg1);
      A.copy(tmp, 0, sz_tg1, 0, polyo+1, desti0, 0); desti0 += sz_tg1;
      tmp = A_tg2; tmp.scale(coeff_tg2);
      A.copy(tmp, 0, sz_tg2, 0, polyo+1, desti0, 0); desti0 += sz_tg2;

      desti0 = 0;
      tmp = b_lin; tmp.scale(coeff_lin);
      b.copy(tmp, 0, sz_lin, 0, 3, desti0, 0); desti0 += sz_lin;
      tmp = b_pos; tmp.scale(coeff_pos);
      b.copy(tmp, 0, sz_pos, 0, 3, desti0, 0); desti0 += sz_pos;
      tmp = b_ext; tmp.scale(coeff_ext);
      b.copy(tmp, 0, sz_ext, 0, 3, desti0, 0); desti0 += sz_ext;
      tmp = b_tg1; tmp.scale(coeff_tg1);
      b.copy(tmp, 0, sz_tg1, 0, 3, desti0, 0); desti0 += sz_tg1;
      tmp = b_tg2; tmp.scale(coeff_tg2);
      b.copy(tmp, 0, sz_tg2, 0, 3, desti0, 0); desti0 += sz_tg2;
    }

    void _construct_system(double kappa, double f_0, double f_s, double f_l,
      const fullMatrix<double> &A_lin, const fullMatrix<double> &b_lin,
      const fullMatrix<double> &A_pos, const fullMatrix<double> &b_pos,
      const fullMatrix<double> &A_ext, const fullMatrix<double> &b_ext,
      const fullMatrix<double> &A_tg1, const fullMatrix<double> &b_tg1,
      const fullMatrix<double> &A_tg2, const fullMatrix<double> &b_tg2,
      fullMatrix<double> &A, fullMatrix<double> &b)
    {
      // Choose
      int sz_lin = A_lin.size1();
      int sz_ext = A_ext.size1();
      int sz_pos = A_pos.size1();
      int sz_tg1 = A_tg1.size1();
      int sz_tg2 = A_tg2.size1();

      double coeff_lin = f_l;
      double coeff_pos = f_0;
      double coeff_ext = kappa * f_s;
      // Between those two, none is stable alone, but they seems stable together.
      // This observation may be dependent on the way edges are curved, in
      // particular the preservation of arc-length nature of edges (see ALP)
      double coeff_tg1 = f_s;
      double coeff_tg2 = f_s;

      int SZ = sz_lin + sz_pos + sz_ext + sz_tg1 + sz_tg2;
      int polyo = A_lin.size2() - 1;
      A = fullMatrix<double>(SZ, polyo+1);
      b = fullMatrix<double>(SZ, 3);

      int desti0 = 0;
      fullMatrix<double> tmp;
      tmp = A_lin; tmp.scale(coeff_lin);
      A.copy(tmp, 0, sz_lin, 0, polyo+1, desti0, 0); desti0 += sz_lin;
      tmp = A_pos; tmp.scale(coeff_pos);
      A.copy(tmp, 0, sz_pos, 0, polyo+1, desti0, 0); desti0 += sz_pos;
      tmp = A_ext; tmp.scale(coeff_ext);
      A.copy(tmp, 0, sz_ext, 0, polyo+1, desti0, 0); desti0 += sz_ext;
      tmp = A_tg1; tmp.scale(coeff_tg1);
      A.copy(tmp, 0, sz_tg1, 0, polyo+1, desti0, 0); desti0 += sz_tg1;
      tmp = A_tg2; tmp.scale(coeff_tg2);
      A.copy(tmp, 0, sz_tg2, 0, polyo+1, desti0, 0); desti0 += sz_tg2;

      desti0 = 0;
      tmp = b_lin; tmp.scale(coeff_lin);
      b.copy(tmp, 0, sz_lin, 0, 3, desti0, 0); desti0 += sz_lin;
      tmp = b_pos; tmp.scale(coeff_pos);
      b.copy(tmp, 0, sz_pos, 0, 3, desti0, 0); desti0 += sz_pos;
      tmp = b_ext; tmp.scale(coeff_ext);
      b.copy(tmp, 0, sz_ext, 0, 3, desti0, 0); desti0 += sz_ext;
      tmp = b_tg1; tmp.scale(coeff_tg1);
      b.copy(tmp, 0, sz_tg1, 0, 3, desti0, 0); desti0 += sz_tg1;
      tmp = b_tg2; tmp.scale(coeff_tg2);
      b.copy(tmp, 0, sz_tg2, 0, 3, desti0, 0); desti0 += sz_tg2;
    }

    void _construct_system_lin(double coeff,
      const fullMatrix<double> &A_lin, const fullMatrix<double> &b_lin,
      const fullMatrix<double> &A_pos, const fullMatrix<double> &b_pos,
      fullMatrix<double> &A, fullMatrix<double> &b)
    {
      int sz_lin = A_lin.size1();
      int sz_pos = A_pos.size1();

      double coeff_lin = coeff;
      double coeff_pos = 1-coeff;

      int SZ = sz_lin + sz_pos;
      int polyo = A_lin.size2() - 1;
      A = fullMatrix<double>(SZ, polyo+1);
      b = fullMatrix<double>(SZ, 3);

      int desti0 = 0;
      fullMatrix<double> tmp;
      tmp = A_lin; tmp.scale(coeff_lin);
      A.copy(tmp, 0, sz_lin, 0, polyo+1, desti0, 0); desti0 += sz_lin;
      tmp = A_pos; tmp.scale(coeff_pos);
      A.copy(tmp, 0, sz_pos, 0, polyo+1, desti0, 0); desti0 += sz_pos;

      desti0 = 0;
      tmp = b_lin; tmp.scale(coeff_lin);
      b.copy(tmp, 0, sz_lin, 0, 3, desti0, 0); desti0 += sz_lin;
      tmp = b_pos; tmp.scale(coeff_pos);
      b.copy(tmp, 0, sz_pos, 0, 3, desti0, 0); desti0 += sz_pos;
    }

    void solve_system(const fullMatrix<double> &A, const fullMatrix<double> &b,
                      const fullMatrix<double> &xyz_gmsh,
                      fullMatrix<double> &new_xyz_HO, bool verbose = false)
    {
      fullMatrix<double> A_fixed_boundary = A;
      const fullMatrix<double> &b_fixed_boundary = b;
      if (verbose) {
        A_fixed_boundary.print(std::string("A_fixed_boundary"), std::string(""));
        b_fixed_boundary.print(std::string("b_fixed_boundary"), std::string(""));
      }

      // Fix extremities
      fullVector<double> proxA, proxb;

      proxA.setAsProxy(A_fixed_boundary, 0);
      for(int j = 0; j < 3; ++j) {
        proxb.setAsProxy(b_fixed_boundary, j);
        proxb.axpy(proxA, -xyz_gmsh(0, j));
      }
      if (verbose) {
        A_fixed_boundary.print(std::string("A_fixed_boundary"), std::string(""));
        b_fixed_boundary.print(std::string("b_fixed_boundary"), std::string(""));
      }

      proxA.setAsProxy(A_fixed_boundary, 1);
      for(int j = 0; j < 3; ++j) {
        proxb.setAsProxy(b_fixed_boundary, j);
        proxb.axpy(proxA, -xyz_gmsh(1, j));
      }
      if (verbose) {
        A_fixed_boundary.print(std::string("A_fixed_boundary"), std::string(""));
        b_fixed_boundary.print(std::string("b_fixed_boundary"), std::string(""));
      }

      fullMatrix<double> tmpA(A_fixed_boundary, 2, A_fixed_boundary.size2() - 2);
      fullMatrix<double> tmpA2 = tmpA;
      if (verbose) {
        tmpA.print(std::string("tmpA"), std::string(""));
        tmpA2.print(std::string("tmpA2"), std::string(""));
      }
      A_fixed_boundary = tmpA2;
      if (verbose) {
        A_fixed_boundary.print(std::string("A_fixed_boundary"), std::string(""));
        b_fixed_boundary.print(std::string("b_fixed_boundary"), std::string(""));
      }

      // TRANSPOSE

      // A_fixed_boundary.print(std::string("A_fb:"),std::string(""));
      // b_fixed_boundary.print(std::string("b_fb:"),std::string(""));

      // Transform into square linear system
      int sz = A_fixed_boundary.size2();
      fullMatrix<double> A_sq(sz, sz);
      fullMatrix<double> b_sq(sz, 3);
      fullMatrix<double> A_T = A_fixed_boundary.transpose();

      A_T.mult(A_fixed_boundary, A_sq);
      A_T.mult(b_fixed_boundary, b_sq);

      // A_sq.print(std::string("A_sq:"),std::string(""));
      // b_sq.print(std::string("b_sq:"),std::string(""));


      fullVector<double> y, c;
      // new_xyz_HO.print(std::string("new_xyz_HO:"),std::string(""));
      for(int j = 0; j < 3; ++j) {
        y.setAsProxy(new_xyz_HO, j);
        c.setAsProxy(b_sq, j);
        A_sq.luSolve(c, y);
        // A_sq.print(std::string("A_sq:"),std::string(""));
        // c.print(std::string("c:"),std::string(""));
        // y.print(std::string("y:"),std::string(""));
        // new_xyz_HO.print(std::string("new_xyz_HO:"),std::string(""));
      }

      // new_xyz_HO.print(std::string("new_xyz_HO:"),std::string(""));
      // xyz_gmsh.print(std::string("xyz_gmsh:"),std::string(""));
      // xyz_seq.print(std::string("xyz_seq:"),std::string(""));
    }

    double _one_iteration(double alpha, double gamma, double kappa,
      const fullMatrix<double> &xyz_gmsh,
      const fullMatrix<double> &A_lin, const fullMatrix<double> &b_lin,
      const fullMatrix<double> &A_pos, const fullMatrix<double> &b_pos,
      const fullMatrix<double> &A_ext, const fullMatrix<double> &b_ext,
      const fullMatrix<double> &A_tg1, const fullMatrix<double> &b_tg1,
      const fullMatrix<double> &A_tg2, const fullMatrix<double> &b_tg2,
      fullMatrix<double> &A, fullMatrix<double> &b,
      fullMatrix<double> &new_xyz)
    {
      double f_0 = 1 - alpha;
      double f_s = alpha * (1 - gamma * alpha);
      double f_l = gamma * alpha * alpha;

      // Construct the system
      _construct_system(kappa * (1 - gamma), f_0, f_s, f_l, A_lin, b_lin, A_pos, b_pos,
                             A_ext, b_ext, A_tg1, b_tg1, A_tg2, b_tg2, A, b);

      // Solve the system
      solve_system(A, b, xyz_gmsh, new_xyz);

      // Update max_displ
      int polyo = A_lin.size2() - 1;
      // prev_max_displ = max_displ;
      double max_displ = 0;

      for (int i = 0; i < polyo - 2; ++i) {
        double vx = xyz_gmsh(i+2, 0) - new_xyz(i, 0);
        double vy = xyz_gmsh(i+2, 1) - new_xyz(i, 1);
        double vz = xyz_gmsh(i+2, 2) - new_xyz(i, 2);
        double displ = sqrt(vx*vx + vy*vy + vz*vz);
        if (displ > max_displ) {
          max_displ = displ;
        }
      }
      return max_displ;
    }

    void _find_best_reduction(double max_displ_ub, double gamma, double kappa,
      const fullMatrix<double> &xyz_gmsh, const fullMatrix<double> &xyz_seq,
      const fullMatrix<double> &A_lin, const fullMatrix<double> &b_lin,
      const fullMatrix<double> &A_pos, const fullMatrix<double> &b_pos,
      const fullMatrix<double> &A_ext, const fullMatrix<double> &b_ext,
      const fullMatrix<double> &A_tg1, const fullMatrix<double> &b_tg1,
      const fullMatrix<double> &A_tg2, const fullMatrix<double> &b_tg2,
      fullMatrix<double> &new_xyz)
    {
      fullMatrix<double> A, b;

      // _construct_test_system(A_lin, b_lin, A_pos, b_pos, A_ext, b_ext,
      //   A_tg1, b_tg1, A_tg2, b_tg2, A, b);
      //
      // solve_system(A, b, xyz_gmsh, new_xyz);
      // return;

      // NOTE
      //  1. Choose alpha = .5 and gamma_target = .5
      //  2. Assemble matrix
      //  3. Solve
      //  4. Compute max_displacement
      //  5. Update alpha
      //  6. Loop

      // Define data storage for iterations
      std::vector<std::tuple<double, double, double, double, double>> iteration_data; // Stores (x_i, y_i, a_i, s_i, q_i)

      // Initial values for i = 0 and i = 1
      iteration_data.emplace_back(0, 0, std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN());
      double alpha = 1.;
      double max_displ = _one_iteration(alpha, gamma, kappa, xyz_gmsh, A_lin, b_lin, A_pos, b_pos, A_ext, b_ext, A_tg1, b_tg1, A_tg2, b_tg2, A, b, new_xyz);
      iteration_data.emplace_back(alpha, max_displ, alpha/2, max_displ, std::numeric_limits<double>::quiet_NaN());

      if(max_displ < .9 * max_displ_ub) return;

      double target = 0.95 * max_displ_ub; // Y = target
      double tol = 0.05 * max_displ_ub;
      double next_x_i = alpha / max_displ * target;

      int k = 1; // Start after initialization
      while (true) {
        ++k; // Increment iteration counter

        // Previous iteration data
        double prev_x = std::get<0>(iteration_data[k - 1]);
        double prev_y = std::get<1>(iteration_data[k - 1]);
        double prev_a = std::get<2>(iteration_data[k - 1]);
        double prev_s = std::get<3>(iteration_data[k - 1]);
        // double prev_q = std::get<4>(iteration_data[k - 1]);

        double x_i = next_x_i;
        double y_i = _one_iteration(x_i, gamma, kappa, xyz_gmsh, A_lin, b_lin, A_pos, b_pos, A_ext, b_ext, A_tg1, b_tg1, A_tg2, b_tg2, A, b, new_xyz);
        double a_i = (x_i + prev_x) / 2;                             // Midpoint of current and previous alpha
        double s_i = (y_i - prev_y) / (x_i - prev_x);          // Slope between current and previous values
        double q_i = (s_i - prev_s) / (a_i - prev_a);    // Slope change rate, with special handling for i=2
        // if(k > 2) q_i = (q_i + prev_q) / 2;
        iteration_data.emplace_back(x_i, y_i, a_i, s_i, q_i);

        // Quadratic coefficients
        double q_coef = q_i / 2;
        double lin_coef = s_i - q_i * a_i;
        double const_coef = prev_y - target - s_i * x_i - q_i * x_i * (x_i / 2 - a_i);

        // Solve the quadratic equation q_coef * X^2 + lin_coef * X + const_coef = 0
        double discriminant = lin_coef * lin_coef - 4 * q_coef * const_coef;
        if (discriminant >= 0) {
          // Take the root that satisfies the direction of progression
          double root1 = (-lin_coef + sqrt(discriminant)) / (2 * q_coef);
          double root2 = (-lin_coef - sqrt(discriminant)) / (2 * q_coef);
          // std::cout << "root1: " << root1 << ", root2: " << root2 << std::endl;
          next_x_i = root1;
          if(next_x_i <= 0) next_x_i = .5 * std::min(x_i, prev_x);
          else if(next_x_i >= 1) next_x_i = .5 + .5 * std::max(x_i, prev_x);
        }
        else {
          // In case the discriminant is negative (unlikely), fallback to halving alpha
          next_x_i = 0.5 * (x_i + prev_x);
        }
        next_x_i = .5 * (next_x_i + x_i); //FIXME Hack

        // Print iteration information
        // std::cout << "Iteration " << k << ": "
        //           << "x_i = " << x_i << ", y_i = " << y_i << ", y_i/target = " << y_i / target
        //           << ", a_i = " << a_i << ", s_i = " << s_i << ", q_i = " << q_i << std::endl;

        // Stopping condition
        if (std::abs(y_i - target) < tol) {
          break;
        }

        // Safety break to prevent infinite loops
        if (k > 1000) {
          std::cerr << "Iteration limit reached. Exiting loop to avoid infinite iterations." << std::endl;
          break;
        }
      }

      // std::cout << "k = " << k << " alpha = " << std::get<0>(iteration_data[k]) << std::endl;
    }

    void compute_xyz_gmsh_seq(const MEdgeN *edge, fullMatrix<double> &xyz_gmsh,
      fullMatrix<double> &xyz_seq)
    {
      int polyo = edge->getPolynomialOrder();
      xyz_gmsh = fullMatrix<double>(polyo + 1, 3);
      for (int i = 0; i < polyo + 1; ++i) {
        MVertex *v = edge->getVertex(i);
        xyz_gmsh(i, 0) = v->x();
        xyz_gmsh(i, 1) = v->y();
        xyz_gmsh(i, 2) = v->z();
      }

      xyz_seq = fullMatrix<double>(polyo + 1, 3);
      xyz_seq(0, 0) = xyz_gmsh(0, 0);
      xyz_seq(0, 1) = xyz_gmsh(0, 1);
      xyz_seq(0, 2) = xyz_gmsh(0, 2);
      for(int i = 1; i < polyo; ++i) {
        xyz_seq(i, 0) = xyz_gmsh(i+1, 0);
        xyz_seq(i, 1) = xyz_gmsh(i+1, 1);
        xyz_seq(i, 2) = xyz_gmsh(i+1, 2);
      }
      xyz_seq(polyo, 0) = xyz_gmsh(1, 0);
      xyz_seq(polyo, 1) = xyz_gmsh(1, 1);
      xyz_seq(polyo, 2) = xyz_gmsh(1, 2);
    }

    void _reduceCurving_newIdea2(MEdgeN *edge, double max_displ_ub, const GFace *gface,
      double gamma, double kappa, const MEdgeN *previous, const MEdgeN *next)
    {
      fullMatrix<double> xyz_gmsh, xyz_seq;
      compute_xyz_gmsh_seq(edge, xyz_gmsh, xyz_seq);

      int polyo = edge->getPolynomialOrder();

      SVector3 dirs[2];
      for(int i = 0; i < 2; ++i) {
        MVertex *v0 = previous->getVertex(i);
        MVertex *v1 = edge->getVertex(i);
        SVector3 n = v1->point() - v0->point();
        n.normalize();
        if(next) {
          MVertex *v2 = next->getVertex(i);
          SVector3 n2 = v2->point() - v1->point();
          n2.normalize();
          n = n + n2;
          n.normalize();
        }
        // Projection
        SVector3 t = edge->tangent(i ? 1 : -1);
        if(i == 0) {
          t = edge->getVertex(2)->point() - v1->point();
        }
        else {
          t = v1->point() - edge->getVertex(polyo)->point();
        }
        dirs[i] = t - dot(t, n) * n;
        dirs[i].normalize();
        // A_ext(i, 0) = dir(0);
      }

      fullMatrix<double> A_lin, b_lin, A_pos, b_pos, A_ext, b_ext,
      A_tg1, b_tg1, A_tg2, b_tg2;
      _construct_matrices(xyz_gmsh, xyz_seq, dirs, A_lin, b_lin, A_pos, b_pos,
        A_ext, b_ext, A_tg1, b_tg1, A_tg2, b_tg2);

      fullMatrix<double> new_xyz(polyo - 1, 3);
      _find_best_reduction(max_displ_ub, gamma, kappa, xyz_gmsh, xyz_seq,
        A_lin, b_lin, A_pos, b_pos, A_ext, b_ext, A_tg1, b_tg1, A_tg2, b_tg2,
        new_xyz);

      for (int i = 2; i < polyo + 1; ++i) {
        MVertex *v = edge->getVertex(i);
        v->x() = new_xyz(i - 2, 0);
        v->y() = new_xyz(i - 2, 1);
        v->z() = new_xyz(i - 2, 2);
      }
    }

    double compute_R(fullMatrix<double> &xyz_seq, const fullMatrix<double> &xyz_HO)
    {
      int polyo = xyz_seq.size1() - 1;
      xyz_seq.copy(xyz_HO, 0, polyo-1, 0, 3, 1, 0);

      double vx, vy, vz;

      // Compute L_discrete
      double L_disc = 0;
      for(int i = 0; i < polyo; ++i) {
        vx = xyz_seq(i+1, 0) - xyz_seq(i, 0);
        vy = xyz_seq(i+1, 1) - xyz_seq(i, 1);
        vz = xyz_seq(i+1, 2) - xyz_seq(i, 2);
        L_disc += std::sqrt(vx*vx + vy*vy + vz*vz);
      }

      // Compute L_linear
      vx = xyz_seq(polyo, 0) - xyz_seq(0, 0);
      vy = xyz_seq(polyo, 1) - xyz_seq(0, 1);
      vz = xyz_seq(polyo, 2) - xyz_seq(0, 2);
      double L_lin = std::sqrt(vx*vx + vy*vy + vz*vz);

      // Compute Z
      double Z = 0;
      for(int i = 1; i < polyo; ++i) {
        double f = static_cast<double>(i) / polyo;
        double x_lin = xyz_seq(0, 0) + f * vx;
        double y_lin = xyz_seq(0, 1) + f * vy;
        double z_lin = xyz_seq(0, 2) + f * vz;
        double dx = x_lin - xyz_seq(i, 0);
        double dy = y_lin - xyz_seq(i, 1);
        double dz = z_lin - xyz_seq(i, 2);
        Z += std::sqrt(dx*dx + dy*dy + dz*dz);
      }
      Z /= polyo; // not polyo+1 because simpson integration

      // Compute R
      double L = .5 * (L_disc + L_lin);
      double R = 1 - 2 * Z / L;
      R *= R; // R^2
      return R * R; // R^4
    }

    double match_gamma(double gamma, MEdgeN *edge, const GFace *gface, const SVector3 &normal)
    {
      int polyo = edge->getPolynomialOrder();

      if(gamma >= 1.) {
        fullMatrix<double> xyz(2, 3);
        for(int i = 0; i < 2; ++i) {
          xyz(i, 0) = edge->getVertex(i)->x();
          xyz(i, 1) = edge->getVertex(i)->y();
          xyz(i, 2) = edge->getVertex(i)->z();
        }
        for(int i = 2; i < polyo+1; ++i) {
          double f = (i - 1.) / polyo;
          edge->getVertex(i)->x() = (1-f) * xyz(0, 0) + f * xyz(1, 0);
          edge->getVertex(i)->y() = (1-f) * xyz(0, 1) + f * xyz(1, 1);
          edge->getVertex(i)->z() = (1-f) * xyz(0, 2) + f * xyz(1, 2);
        }
        return 1.;
      }

      fullMatrix<double> xyz_gmsh, xyz_seq;
      compute_xyz_gmsh_seq(edge, xyz_gmsh, xyz_seq);

      SVector3 dirs[2];
      fullMatrix<double> A_lin, b_lin, A_pos, b_pos, A_ext, b_ext,
      A_tg1, b_tg1, A_tg2, b_tg2;
      _construct_matrices(xyz_gmsh, xyz_seq, dirs, A_lin, b_lin, A_pos, b_pos,
        A_ext, b_ext, A_tg1, b_tg1, A_tg2, b_tg2);

      // solve R
      // (coeff - 1) / (R - 1) + 1
      fullMatrix<double> new_xyz_HO(polyo-1, 3);
      for(int i = 0; i < polyo-1; ++i) {
        new_xyz_HO(i, 0) = edge->getVertex(i+2)->x();
        new_xyz_HO(i, 1) = edge->getVertex(i+2)->y();
        new_xyz_HO(i, 2) = edge->getVertex(i+2)->z();
      }

      double R = compute_R(xyz_seq, new_xyz_HO);
      double coeff = 0;
      double target = .95 * gamma;
      double tol = .05 * gamma;

      while(R + tol < target) {
        coeff = 1 + (coeff-1) / (R-1) * (target-1) ;
        // Solve R
        // Update

        fullMatrix<double> A, b;
        _construct_system_lin(coeff, A_lin, b_lin, A_pos, b_pos, A, b);
        // A.print(std::string("A"), std::string(""));
        // b.print(std::string("b"), std::string(""));
        solve_system(A, b, xyz_gmsh, new_xyz_HO, false);
        // xyz_gmsh.print(std::string("xyz_gmsh"), std::string(""));
        // new_xyz_HO.print(std::string("new_xyz_HO"), std::string(""));
        R = compute_R(xyz_seq, new_xyz_HO);
      }

      for(int i = 2; i < polyo+1; ++i) {
        edge->getVertex(i)->x() = new_xyz_HO(i-2, 0);
        edge->getVertex(i)->y() = new_xyz_HO(i-2, 1);
        edge->getVertex(i)->z() = new_xyz_HO(i-2, 2);
      }
      std::cout << "(" << R << ", " << coeff << ", " << tol << ")" << std::endl;
      return coeff;
    }

    void linearize(double coeff, MEdgeN *edge, const GFace *gface, const SVector3 &normal)
    {
      if(coeff < 1e-5) return;
      int polyo = edge->getPolynomialOrder();

      fullMatrix<double> xyz_gmsh, xyz_seq;
      compute_xyz_gmsh_seq(edge, xyz_gmsh, xyz_seq);

      SVector3 dirs[2];
      fullMatrix<double> A_lin, b_lin, A_pos, b_pos, A_ext, b_ext,
      A_tg1, b_tg1, A_tg2, b_tg2;
      _construct_matrices(xyz_gmsh, xyz_seq, dirs, A_lin, b_lin, A_pos, b_pos,
        A_ext, b_ext, A_tg1, b_tg1, A_tg2, b_tg2);

      fullMatrix<double> A, b;
      _construct_system_lin(coeff, A_lin, b_lin, A_pos, b_pos, A, b);
      fullMatrix<double> new_xyz_HO(polyo-1, 3);
      solve_system(A, b, xyz_gmsh, new_xyz_HO, false);

      // xyz_gmsh.print("xyz_gmsh");
      // xyz_seq.print("xyz_seq");
      // new_xyz_HO.print("new_xyz_HO");

      for(int i = 2; i < polyo+1; ++i) {
        edge->getVertex(i)->x() = new_xyz_HO(i-2, 0);
        edge->getVertex(i)->y() = new_xyz_HO(i-2, 1);
        edge->getVertex(i)->z() = new_xyz_HO(i-2, 2);
      }
    }

    void curveEdge_newIdea(const MEdgeN *baseEdge, MEdgeN *edge, const GFace *gface,
                           const SVector3 &normal, MEdgeN *next, double current_h)
    {
      _Frame frame(baseEdge, gface, normal);

      double coeffs[2][3];
      _computeParameters(baseEdge, edge, frame, coeffs);

      const int orderCurve = baseEdge->getPolynomialOrder();
      const int orderGauss = orderCurve * 2;
      const int sizeSystem = getNGQLPts(orderGauss);
      const IntPt *gaussPnts = getGQLPts(orderGauss);

      // Least square projection
      fullMatrix<double> xyz(sizeSystem + 2, 3);
      _idealPositionEdge(baseEdge, frame, coeffs, sizeSystem, gaussPnts, xyz);
      // _drawIdealPositionEdge(baseEdge, frame, coeffs);
      for(int i = 0; i < 2; ++i) {
        xyz(sizeSystem + i, 0) = edge->getVertex(i)->x();
        xyz(sizeSystem + i, 1) = edge->getVertex(i)->y();
        xyz(sizeSystem + i, 2) = edge->getVertex(i)->z();
      }

      LeastSquareData *data =
        getLeastSquareData(TYPE_LIN, orderCurve, orderGauss);
      fullMatrix<double> newxyz(orderCurve + 1, 3);
      data->invA.mult(xyz, newxyz);

      for(int i = 2; i < edge->getNumVertices(); ++i) {
        edge->getVertex(i)->x() = newxyz(i, 0);
        edge->getVertex(i)->y() = newxyz(i, 1);
        edge->getVertex(i)->z() = newxyz(i, 2);
      }

      double minThickness = 1e10;
      MVertex *v0 = edge->getVertex(0);
      MVertex *v1 = baseEdge->getVertex(0);
      if (v0 != v1) {
        SVector3 vec = v0->point() - v1->point();
        minThickness = std::min(minThickness, vec.norm());
      }
      v0 = edge->getVertex(6);
      v1 = baseEdge->getVertex(6);
      if (v0 != v1) {
        SVector3 vec = v0->point() - v1->point();
        minThickness = std::min(minThickness, vec.norm());
      }

      // _reduceCurving_newIdea(edge, minThickness*.1, gface);
      // NOTE
      //  1) Calculer les h_i. -> H = h_N, z_i = h_i / H
      //  2) Param z_lin : Si h_i / H < z_lin, pas de réduction de courbure
      //  3) Param gamma_out : gamma(z) = 0 si z <= z_lin,
      //                                = f*(z-z_lin) si z >= z_lin
      //                                  f tq gamma(z_out) = gamma_out
      //  4) Param tau : tq max_displ = tau * (h_i+1 - h_i)
      //  5) Param kappa : imposition perpendicularité aux extrémités

      // TODO
      //  0x Séparer les tangentes BSpline dans la matrice
      //  1x Calculer h_i
      //  2. Déterminer relation entre gamma (degré linéarité voulu) et
      //     Sum (b_i-x_i)^2 / L^2
      //     => • L = (L_lin + L_disc) / 2
      //        • Z = sum |x_i-z_i| / (N-1) (car Simpson)
      //        • R = (1 - 2*Z/L) ** 4
      //        • R >= gamma
      //  3. Déterminer relation entre gamma voulu et coefficient dans la matrice
      //     (recalculer relation pour deux F_a = (x-x_a)^2 et F_b. On veut
      //      x_opt = (1 - w) * x_a + w * x_b, alors quelle fonctionnel minimiser ?
      //      F = c_a * F_a + c_b * F_b
      //      => c_a = (1-w) et c_b = w => barycentric weight
      //  4. Mettre tout ensemble pour obtenir le résultat final

      double gamma = current_h < .5 ? 0 : 2 * current_h - .5;
      gamma = current_h;
      // gamma = 1;
      gamma = 0; // 0 = curved
      double kappa = .1;
      double tau = .1;
      _reduceCurving_newIdea2(edge, minThickness*tau, gface, gamma, kappa, baseEdge, next);

      if(gface) projectVerticesIntoGFace(edge, gface, false);


      //drawBezierControlPolygon(edge->getVertices());
    }

    void _reduceCurving(MEdgeN *edge, double factor, const GFace *gface)
    {
      int order = edge->getPolynomialOrder();

      MVertex *v0 = edge->getVertex(0);
      MVertex *v1 = edge->getVertex(1);

      for(int i = 2; i < order + 1; ++i) {
        double f = (double)(i - 1) / order;
        MVertex *v = edge->getVertex(i);
        v->x() =
          (1 - factor) * v->x() + factor * ((1 - f) * v0->x() + f * v1->x());
        v->y() =
          (1 - factor) * v->y() + factor * ((1 - f) * v0->y() + f * v1->y());
        v->z() =
          (1 - factor) * v->z() + factor * ((1 - f) * v0->z() + f * v1->z());
      }
      if(gface) projectVerticesIntoGFace(edge, gface, false);
    }

    void _reduceCurving2(MEdgeN *edge, double dx, const GFace *gface)
    {
      int order = edge->getPolynomialOrder();

      MVertex *v0 = edge->getVertex(0);
      MVertex *v1 = edge->getVertex(1);

      double max_h = 0;
      for(int i = 2; i < order + 1; ++i) {
        double f = (double)(i - 1) / order;
        MVertex *v = edge->getVertex(i);
        double dh_x = v->x() - ((1 - f) * v0->x() + f * v1->x());
        double dh_y = v->y() - ((1 - f) * v0->y() + f * v1->y());
        double dh_z = v->z() - ((1 - f) * v0->z() + f * v1->z());
        max_h = std::max(max_h, std::sqrt(dh_x*dh_x + dh_y*dh_y + dh_z*dh_z));
      }

      double factor = dx / max_h;

      for(int i = 2; i < order + 1; ++i) {
        double f = (double)(i - 1) / order;
        MVertex *v = edge->getVertex(i);
        v->x() =
          (1 - factor) * v->x() + factor * ((1 - f) * v0->x() + f * v1->x());
        v->y() =
          (1 - factor) * v->y() + factor * ((1 - f) * v0->y() + f * v1->y());
        v->z() =
          (1 - factor) * v->z() + factor * ((1 - f) * v0->z() + f * v1->z());
      }
      if(gface) projectVerticesIntoGFace(edge, gface, false);
    }

    void _reduceOrderCurve(MEdgeN *edge, int order, const GFace *gface)
    {
      const int orderCurve = edge->getPolynomialOrder();
      const int orderGauss = order * 2;
      const int sizeSystem = getNGQLPts(orderGauss);
      const IntPt *gaussPnts = getGQLPts(orderGauss);

      // Least square projection
      fullMatrix<double> xyz(sizeSystem + 2, 3);
      for(int i = 0; i < sizeSystem; ++i) {
        SPoint3 p = edge->pnt(gaussPnts[i].pt[0]);
        xyz(i, 0) = p.x();
        xyz(i, 1) = p.y();
        xyz(i, 2) = p.z();
      }
      for(int i = 0; i < 2; ++i) {
        xyz(sizeSystem + i, 0) = edge->getVertex(i)->x();
        xyz(sizeSystem + i, 1) = edge->getVertex(i)->y();
        xyz(sizeSystem + i, 2) = edge->getVertex(i)->z();
      }

      LeastSquareData *data = getLeastSquareData(TYPE_LIN, order, orderGauss);
      fullMatrix<double> newxyzLow(order + 1, 3);
      data->invA.mult(xyz, newxyzLow);

      std::vector<MVertex *> vertices = edge->getVertices();
      vertices.resize(static_cast<std::size_t>(order) + 1);
      MEdgeN lowOrderEdge(vertices);

      for(std::size_t i = 2; i < vertices.size(); ++i) {
        vertices[i]->x() = newxyzLow(i, 0);
        vertices[i]->y() = newxyzLow(i, 1);
        vertices[i]->z() = newxyzLow(i, 2);
      }

      const int tagLine = ElementType::getType(TYPE_LIN, orderCurve);
      const nodalBasis *nb = BasisFactory::getNodalBasis(tagLine);
      const fullMatrix<double> &refpnts = nb->getReferenceNodes();

      fullMatrix<double> newxyz(edge->getNumVertices(), 3);
      for(std::size_t i = 2; i < edge->getNumVertices(); ++i) {
        SPoint3 p = lowOrderEdge.pnt(refpnts(i, 0));
        newxyz(i, 0) = p.x();
        newxyz(i, 1) = p.y();
        newxyz(i, 2) = p.z();
      }

      for(int i = 2; i < edge->getNumVertices(); ++i) {
        edge->getVertex(i)->x() = newxyz(i, 0);
        edge->getVertex(i)->y() = newxyz(i, 1);
        edge->getVertex(i)->z() = newxyz(i, 2);
      }

      if(gface) projectVerticesIntoGFace(edge, gface, false);
    }

    void recoverQualityElements(std::vector<MEdgeN> &stackEdges,
                                std::vector<MFaceN> &stackFaces,
                                std::vector<MElement *> &stackElements,
                                int iFirst, int iLast, const GFace *gface)
    {
      std::vector<MEdgeN> subsetEdges(4);
      subsetEdges[0] = stackEdges[0];
      subsetEdges[1] = stackEdges[iFirst];
      subsetEdges[2] = stackEdges[iLast - 1];
      subsetEdges[3] = stackEdges[iLast];
      MEdgeN *lastEdge = &stackEdges[iLast];
      std::vector<MFaceN> subsetFaces;
      subsetFaces.push_back(stackFaces[iLast - 1]);
      subsetFaces.push_back(stackFaces[iLast]);
      // Warning: subsetFaces should contain 2 faces since
      // repositionInnerVertices() need a column of BL faces + the exterior face

      // First get sure that last element of the BL is of good quality
      MElement *lastElementBL = stackElements[iLast - 1];
      MElement *linear = createPrimaryElement(lastElementBL);
      double qualLinear = jacobianBasedQuality::minIGEMeasure(linear);
      delete linear;

      InteriorEdgeCurver::curveEdges(subsetEdges, 1, 3, gface);
      repositionInnerVertices(subsetFaces, gface);
      double qual = jacobianBasedQuality::minIGEMeasure(lastElementBL);
      int currentOrder = lastEdge->getPolynomialOrder();
      while(qual < .75 && qual < .8 * qualLinear && currentOrder > 2) {
        _reduceOrderCurve(lastEdge, --currentOrder, gface);
        InteriorEdgeCurver::curveEdges(subsetEdges, 1, 3, gface);
        repositionInnerVertices(subsetFaces, gface);
        qual = jacobianBasedQuality::minIGEMeasure(lastElementBL);
      }
      int iter = 0;
      const int maxIter = 15;
      while(qual < .75 && qual < .8 * qualLinear && ++iter < maxIter) {
        _reduceCurving(lastEdge, .25, gface);
        InteriorEdgeCurver::curveEdges(subsetEdges, 1, 3, gface);
        repositionInnerVertices(subsetFaces, gface);
        qual = jacobianBasedQuality::minIGEMeasure(lastElementBL);
      }

      // Now, get sure the exterior element is of good quality
      MElement *lastElement = stackElements[iLast];
      linear = createPrimaryElement(lastElement);
      qualLinear = jacobianBasedQuality::minIGEMeasure(linear);
      delete linear;

      qual = jacobianBasedQuality::minIGEMeasure(lastElement);
      while(qual < .75 && qual < .8 * qualLinear && ++iter < maxIter) {
        _reduceCurving(lastEdge, .25, gface);
        repositionInnerVertices(subsetFaces, gface);
        qual = jacobianBasedQuality::minIGEMeasure(lastElement);
      }
      if(iter == maxIter) _reduceCurving(lastEdge, 1, gface);
    }

    double match_gamma_simpler(double gamma, MEdgeN *edge, const GFace *gface, const SVector3 &normal)
    {
      int polyo = edge->getPolynomialOrder();

      if(gamma >= 1.) {
        fullMatrix<double> xyz(2, 3);
        for(int i = 0; i < 2; ++i) {
          xyz(i, 0) = edge->getVertex(i)->x();
          xyz(i, 1) = edge->getVertex(i)->y();
          xyz(i, 2) = edge->getVertex(i)->z();
        }
        for(int i = 2; i < polyo+1; ++i) {
          double f = (i - 1.) / polyo;
          edge->getVertex(i)->x() = (1-f) * xyz(0, 0) + f * xyz(1, 0);
          edge->getVertex(i)->y() = (1-f) * xyz(0, 1) + f * xyz(1, 1);
          edge->getVertex(i)->z() = (1-f) * xyz(0, 2) + f * xyz(1, 2);
        }
        return 1.;
      }

      fullMatrix<double> xyz_gmsh, xyz_seq;
      compute_xyz_gmsh_seq(edge, xyz_gmsh, xyz_seq);

      // _reduceCurving(edge, .25, gface);

      fullMatrix<double> xyz_HO(polyo-1, 3), xyz_lin(polyo-1, 3);
      for(int i = 0; i < polyo-1; ++i) {
        xyz_HO(i, 0) = edge->getVertex(i+2)->x();
        xyz_HO(i, 1) = edge->getVertex(i+2)->y();
        xyz_HO(i, 2) = edge->getVertex(i+2)->z();
        double f = (i + 1.) / polyo;
        xyz_lin(i, 0) = (1-f) * edge->getVertex(0)->x() + f * edge->getVertex(1)->x();
        xyz_lin(i, 1) = (1-f) * edge->getVertex(0)->y() + f * edge->getVertex(1)->y();
        xyz_lin(i, 2) = (1-f) * edge->getVertex(0)->z() + f * edge->getVertex(1)->z();
      }

      double R = compute_R(xyz_seq, xyz_HO);
      double coeff = 0;
      double target = .95 * gamma;
      double tol = .05 * gamma;
      fullMatrix<double> new_xyz_HO = xyz_HO;

      while(R + tol < target) {
        coeff = 1 + (coeff-1) / (R-1) * (target-1) ;

        new_xyz_HO = xyz_HO;
        new_xyz_HO.scale(1-coeff);
        new_xyz_HO.axpy(xyz_lin, coeff);

        // xyz_gmsh.print(std::string("xyz_gmsh"), std::string(""));
        // new_xyz_HO.print(std::string("new_xyz_HO"), std::string(""));
        R = compute_R(xyz_seq, new_xyz_HO);
      }

      for(int i = 2; i < polyo+1; ++i) {
        edge->getVertex(i)->x() = new_xyz_HO(i-2, 0);
        edge->getVertex(i)->y() = new_xyz_HO(i-2, 1);
        edge->getVertex(i)->z() = new_xyz_HO(i-2, 2);
      }
      std::cout << "(" << R << ", " << coeff << ", " << tol << ")" << std::endl;
      return coeff;
    }

    double match_gamma_simpler2(double gamma, MEdgeN *edge, const GFace *gface, const SVector3 &normal)
    {
      int polyo = edge->getPolynomialOrder();

      if(gamma >= 1.) {
        fullMatrix<double> xyz(2, 3);
        for(int i = 0; i < 2; ++i) {
          xyz(i, 0) = edge->getVertex(i)->x();
          xyz(i, 1) = edge->getVertex(i)->y();
          xyz(i, 2) = edge->getVertex(i)->z();
        }
        double max_displ = 0;
        for(int i = 2; i < polyo+1; ++i) {
          double f = (i - 1.) / polyo;
          double dx = edge->getVertex(i)->x() - ((1-f) * xyz(0, 0) + f * xyz(1, 0));
          double dy = edge->getVertex(i)->y() - ((1-f) * xyz(0, 1) + f * xyz(1, 1));
          double dz = edge->getVertex(i)->z() - ((1-f) * xyz(0, 2) + f * xyz(1, 2));
          max_displ = std::max(max_displ, sqrt(dx*dx + dy*dy + dz*dz));
          edge->getVertex(i)->x() = (1-f) * xyz(0, 0) + f * xyz(1, 0);
          edge->getVertex(i)->y() = (1-f) * xyz(0, 1) + f * xyz(1, 1);
          edge->getVertex(i)->z() = (1-f) * xyz(0, 2) + f * xyz(1, 2);
        }
        return max_displ;
      }

      fullMatrix<double> xyz_gmsh, xyz_seq;
      compute_xyz_gmsh_seq(edge, xyz_gmsh, xyz_seq);

      // _reduceCurving(edge, .25, gface);

      fullMatrix<double> xyz_HO(polyo-1, 3), xyz_lin(polyo-1, 3);
      for(int i = 0; i < polyo-1; ++i) {
        xyz_HO(i, 0) = edge->getVertex(i+2)->x();
        xyz_HO(i, 1) = edge->getVertex(i+2)->y();
        xyz_HO(i, 2) = edge->getVertex(i+2)->z();
        double f = (i + 1.) / polyo;
        xyz_lin(i, 0) = (1-f) * edge->getVertex(0)->x() + f * edge->getVertex(1)->x();
        xyz_lin(i, 1) = (1-f) * edge->getVertex(0)->y() + f * edge->getVertex(1)->y();
        xyz_lin(i, 2) = (1-f) * edge->getVertex(0)->z() + f * edge->getVertex(1)->z();
      }

      double R = compute_R(xyz_seq, xyz_HO);
      double coeff = 0;
      double target = .95 * gamma;
      double tol = .05 * gamma;
      fullMatrix<double> new_xyz_HO = xyz_HO;

      while(R + tol < target) {
        coeff = 1 + (coeff-1) / (R-1) * (target-1) ;

        new_xyz_HO = xyz_HO;
        new_xyz_HO.scale(1-coeff);
        new_xyz_HO.axpy(xyz_lin, coeff);

        // xyz_gmsh.print(std::string("xyz_gmsh"), std::string(""));
        // new_xyz_HO.print(std::string("new_xyz_HO"), std::string(""));
        R = compute_R(xyz_seq, new_xyz_HO);
      }

      double max_displ = 0;
      for(int i = 2; i < polyo+1; ++i) {
        double dx = edge->getVertex(i)->x() - new_xyz_HO(i-2, 0);
        double dy = edge->getVertex(i)->y() - new_xyz_HO(i-2, 1);
        double dz = edge->getVertex(i)->z() - new_xyz_HO(i-2, 2);
        max_displ = std::max(max_displ, sqrt(dx*dx + dy*dy + dz*dz));
        edge->getVertex(i)->x() = new_xyz_HO(i-2, 0);
        edge->getVertex(i)->y() = new_xyz_HO(i-2, 1);
        edge->getVertex(i)->z() = new_xyz_HO(i-2, 2);
      }
      std::cout << "(" << R << ", " << coeff << ", " << tol << ")" << std::endl;
      return max_displ;
    }
  } // namespace EdgeCurver2D

  namespace InteriorEdgeCurver {
    static std::map<std::pair<int, int>, TFIData *> tfiData;

    TFIData *_constructTFIData(int typeElement, int order)
    {
      TFIData *data = new TFIData;
      int nbDof = order + 1;

      fullMatrix<double> Mh; // lag coeff p n -> lag coeff p (n+1)
      fullMatrix<double> M0; // lag coeff p (n+1) c -> (1-xi) * c
      fullMatrix<double> M1; // lag coeff p (n+1) c ->    xi  * c
      fullMatrix<double> Ml; // lag coeff p (n+1) -> leg coeff p n
      fullMatrix<double> Me; // leg coeff p n -> lag coeff p n

      if(typeElement == TYPE_LIN) {
        int tagLine = ElementType::getType(TYPE_LIN, order);
        const nodalBasis *fs = BasisFactory::getNodalBasis(tagLine);
        const fullMatrix<double> &refNodes = fs->getReferenceNodes();
        const fullMatrix<double> refNodesh = gmshGeneratePointsLine(order + 1);

        int nbDofh = refNodesh.size1();

        //      refNodesh.print("refNodesh");

        Mh.resize(nbDofh, nbDof);
        for(int i = 0; i < nbDofh; ++i) {
          double sf[100];
          fs->f(refNodesh(i, 0), refNodesh(i, 1), refNodesh(i, 2), sf);
          for(int j = 0; j < nbDof; ++j) { Mh(i, j) = sf[j]; }
        }
        //      Mh.print("Mh");

        M0.resize(nbDofh, nbDofh, true);
        M1.resize(nbDofh, nbDofh, true);
        for(int i = 0; i < nbDofh; ++i) {
          M0(i, i) = .5 - refNodesh(i, 0) / 2;
          M1(i, i) = .5 + refNodesh(i, 0) / 2;
        }
        //      M0.print("M0");
        //      M1.print("M1");

        Ml.resize(nbDof, nbDofh);
        {
          fullMatrix<double> vandermonde(nbDofh, nbDofh);

          double *val = new double[nbDofh];
          for(int i = 0; i < nbDofh; ++i) {
            LegendrePolynomials::fc(order + 1, refNodesh(i, 0), val);
            for(int j = 0; j < nbDofh; ++j) { vandermonde(i, j) = val[j]; }
          }
          delete val;

          fullMatrix<double> tmp;
          vandermonde.invert(tmp);
          //        vandermonde.print("vandermonde");
          //        tmp.print("tmp");
          Ml.copy(tmp, 0, nbDof, 0, nbDofh, 0, 0);
        }
        //      Ml.print("Ml");

        Me.resize(nbDof, nbDof);
        {
          double *val = new double[nbDof];
          for(int i = 0; i < nbDof; ++i) {
            LegendrePolynomials::fc(order, refNodes(i, 0), val);
            for(int j = 0; j < nbDof; ++j) { Me(i, j) = val[j]; }
          }
          delete val;
        }
        //      Me.print("Me");

        fullMatrix<double> tmp0(nbDofh, nbDof);
        fullMatrix<double> tmp1(nbDofh, nbDof);
        M0.mult(Mh, tmp0);
        M1.mult(Mh, tmp1);
        fullMatrix<double> tmp(nbDof, nbDofh);
        Me.mult(Ml, tmp);
        //      tmp.print("tmp");
        data->T0.resize(nbDof, nbDof);
        data->T1.resize(nbDof, nbDof);
        tmp.mult(tmp0, data->T0);
        tmp.mult(tmp1, data->T1);

        //      data->T0.print("data->T0");
        //      data->T1.print("data->T1");
      }

      //    fullVector<double> x(nbDof);
      //    x.setAll(1);
      //    fullVector<double> b1(nbDof);
      //    fullVector<double> b2(nbDof);
      //    data->T0.mult(x, b1);
      //    b1.print("b");
      //    data->T1.mult(x, b1);
      //    b1.print("b");
      //
      //    x(0) = 0;
      //    x(2) = 1/6.;
      //    x(3) = 2/6.;
      //    x(4) = 3/6.;
      //    x(5) = 4/6.;
      //    x(6) = 5/6.;
      //    x(1) = 1;
      //    data->T0.mult(x, b1);
      //    b1.print("b1");
      //    data->T1.mult(x, b2);
      //    b2.print("b2");
      //    b1.axpy(b2);
      //    b1.print("b");
      //
      //    x(0) = 0;
      //    x(2) = 0.000021433470508;
      //    x(3) = 0.001371742112483;
      //    x(4) = 0.015625000000000;
      //    x(5) = 0.087791495198903;
      //    x(6) = 0.334897976680384;
      //    x(1) = 1.000000000000000;
      //    data->T0.mult(x, b1);
      //    b1.print("b1");
      //    data->T1.mult(x, b2);
      //    b2.print("b2");
      //    b1.axpy(b2);
      //    b1.print("b");

      return data;
    }

    TFIData *_getTFIData(int typeElement, int order)
    {
      std::pair<int, int> typeOrder(typeElement, order);
      std::map<std::pair<int, int>, TFIData *>::iterator it;
      it = tfiData.find(typeOrder);

      if(it != tfiData.end()) return it->second;

      TFIData *data = _constructTFIData(typeElement, order);

      tfiData[typeOrder] = data;
      return data;
    }

    void _linearize(const fullMatrix<double> &x, fullMatrix<double> &lin)
    {
      int n = x.size1();
      lin.copy(x, 0, 2, 0, 3, 0, 0);
      for(int i = 2; i < n; ++i) {
        double fact = ((double)i - 1) / (n - 1);
        for(int j = 0; j < 3; ++j)
          lin(i, j) = (1 - fact) * x(0, j) + fact * x(1, j);
      }
    }

    void _computeEtas(const std::vector<MEdgeN> &stack,
                      std::vector<std::pair<double, double> > &eta)
    {
      eta.resize(stack.size());
      eta[0] = std::make_pair(0, 0);
      MVertex *vb0 = stack[0].getVertex(0);
      MVertex *vb1 = stack[0].getVertex(1);

      for(std::size_t i = 1; i < stack.size(); ++i) {
        MVertex *v0 = stack[i].getVertex(0);
        MVertex *v1 = stack[i].getVertex(1);
        eta[i].first = vb0->distance(v0);
        eta[i].second = vb1->distance(v1);
      }

      for(int i = 1; i < eta.size(); ++i) {
        eta[i].first /= eta.back().first;
        eta[i].second /= eta.back().second;
      }
    }

    void _computeDeltaForTFI(const std::vector<MEdgeN> &stack, int iFirst,
                             int iLast, fullMatrix<double> &delta0,
                             fullMatrix<double> &delta1,
                             fullMatrix<double> &deltaN)
    {
      const int numVertices = stack[0].getNumVertices();

      fullMatrix<double> x0(numVertices, 3);
      fullMatrix<double> x1(numVertices, 3);
      fullMatrix<double> xN(numVertices, 3);
      for(int k = 0; k < numVertices; ++k) {
        x0(k, 0) = stack[0].getVertex(k)->x();
        x0(k, 1) = stack[0].getVertex(k)->y();
        x0(k, 2) = stack[0].getVertex(k)->z();
        x1(k, 0) = stack[iFirst].getVertex(k)->x();
        x1(k, 1) = stack[iFirst].getVertex(k)->y();
        x1(k, 2) = stack[iFirst].getVertex(k)->z();
        xN(k, 0) = stack[iLast].getVertex(k)->x();
        xN(k, 1) = stack[iLast].getVertex(k)->y();
        xN(k, 2) = stack[iLast].getVertex(k)->z();
      }

      fullMatrix<double> x0linear(numVertices, 3);
      fullMatrix<double> x1linear(numVertices, 3);
      fullMatrix<double> xNlinear(numVertices, 3);
      _linearize(x0, x0linear);
      _linearize(x1, x1linear);
      _linearize(xN, xNlinear);
      delta0 = x0;
      delta0.axpy(x0linear, -1);
      delta1 = x1;
      delta1.axpy(x1linear, -1);
      deltaN = xN;
      deltaN.axpy(xNlinear, -1);
    }

    void _computeTerms(const fullMatrix<double> &delta0,
                       const fullMatrix<double> &delta1,
                       const fullMatrix<double> &deltaN, double eta1,
                       fullMatrix<double> terms[8])
    {
      fullMatrix<double> &term0 = terms[0];
      fullMatrix<double> &term1d10 = terms[1];
      fullMatrix<double> &term1d11 = terms[2];
      fullMatrix<double> &term1dN0 = terms[3];
      fullMatrix<double> &term1dN1 = terms[4];
      fullMatrix<double> &term20 = terms[5];
      fullMatrix<double> &term21 = terms[6];
      fullMatrix<double> &term22 = terms[7];

      const int numVertices = delta0.size1();

      fullMatrix<double> delta10 = delta1;
      delta10.axpy(delta0, -1);
      delta10.scale(1 / eta1);
      fullMatrix<double> deltaN0 = deltaN;
      deltaN0.axpy(delta0, -1);

      term0.resize(numVertices, 3);
      term1d10.resize(numVertices, 3);
      term1d11.resize(numVertices, 3);
      term1dN0.resize(numVertices, 3);
      term1dN1.resize(numVertices, 3);
      term20.resize(numVertices, 3);
      term21.resize(numVertices, 3);
      term22.resize(numVertices, 3);

      TFIData *tfiData = _getTFIData(TYPE_LIN, numVertices - 1);

      term0.copy(delta0);
      tfiData->T0.mult(delta10, term1d10);
      tfiData->T1.mult(delta10, term1d11);
      tfiData->T0.mult(deltaN0, term1dN0);
      tfiData->T1.mult(deltaN0, term1dN1);
      fullMatrix<double> diff(numVertices, 3);
      fullMatrix<double> dum0(numVertices, 3);
      fullMatrix<double> dum1(numVertices, 3);
      diff.copy(deltaN0);
      diff.axpy(delta10, -1);
      tfiData->T0.mult(diff, dum0);
      tfiData->T1.mult(diff, dum1);
      tfiData->T0.mult(dum0, term20);
      tfiData->T1.mult(dum0, term21);
      tfiData->T1.mult(dum1, term22);
    }

    void _generalTFI(std::vector<MEdgeN> &stack, int iLast,
                     const std::vector<std::pair<double, double> > &eta,
                     const fullMatrix<double> terms[8], double coeffHermite,
                     const GFace *gface)
    {
      // Let L() be the linear TFI transformation
      // Let H() be the semi-Hermite TFI transformation
      // This function return (1-coeffHermite) * L() + coeffHermite * H()

      const fullMatrix<double> &term0 = terms[0];
      const fullMatrix<double> &term1d10 = terms[1];
      const fullMatrix<double> &term1d11 = terms[2];
      const fullMatrix<double> &term1dN0 = terms[3];
      const fullMatrix<double> &term1dN1 = terms[4];
      const fullMatrix<double> &term20 = terms[5];
      const fullMatrix<double> &term21 = terms[6];
      const fullMatrix<double> &term22 = terms[7];

      int numVertices = stack[0].getNumVertices();

      for(std::size_t i = 1; i < stack.size(); ++i) {
        if(i == iLast) continue;
        // we want to change stack[iFirst] but not stack[iLast]

        fullMatrix<double> x(numVertices, 3);
        for(int j = 0; j < numVertices; ++j) {
          MVertex *v = stack[i].getVertex(j);
          x(j, 0) = v->x();
          x(j, 1) = v->y();
          x(j, 2) = v->z();
        }
        _linearize(x, x);

        double &c = coeffHermite;
        x.axpy(term0);
        x.axpy(term1d10, c * eta[i].first);
        x.axpy(term1d11, c * eta[i].second);
        x.axpy(term1dN0, (1 - c) * eta[i].first);
        x.axpy(term1dN1, (1 - c) * eta[i].second);
        x.axpy(term20, c * eta[i].first * eta[i].first);
        x.axpy(term21, c * 2 * eta[i].first * eta[i].second);
        x.axpy(term22, c * eta[i].second * eta[i].second);

        for(int j = 2; j < numVertices; ++j) {
          MVertex *v = stack[i].getVertex(j);
          v->x() = x(j, 0);
          v->y() = x(j, 1);
          v->z() = x(j, 2);
        }
        if(gface) projectVerticesIntoGFace(&stack[i], gface, false);
      }
    }

    void _computeEtaAndTerms(std::vector<MEdgeN> &stack, int iFirst, int iLast,
                             std::vector<std::pair<double, double> > &eta,
                             fullMatrix<double> terms[8])
    {
      // Compute eta_i^k, k=0,1
      _computeEtas(stack, eta);

      // Precompute Delta(x_i), i=0,1,n
      fullMatrix<double> delta0, delta1, deltaN;
      _computeDeltaForTFI(stack, iFirst, iLast, delta0, delta1, deltaN);

      // Compute terms
      double eta1 = .5 * (eta[iFirst].first + eta[iFirst].second);
      _computeTerms(delta0, delta1, deltaN, eta1, terms);
    }

    void curveEdges(std::vector<MEdgeN> &stack, int iFirst, int iLast,
                    const GFace *gface)
    {
      std::vector<std::pair<double, double> > eta;
      fullMatrix<double> terms[8];
      _computeEtaAndTerms(stack, iFirst, iLast, eta, terms);

      _generalTFI(stack, iLast, eta, terms, 1, gface);
    }

    void curveEdgesAndPreserveQuality(std::vector<MEdgeN> &stackEdges,
                                      std::vector<MFaceN> &stackFaces,
                                      std::vector<MElement *> &stackElements,
                                      int iFirst, int iLast, const GFace *gface)
    {
      std::vector<std::pair<double, double> > eta;
      fullMatrix<double> terms[8];
      _computeEtaAndTerms(stackEdges, iFirst, iLast, eta, terms);

      // Compute quality of primary elements
      unsigned long numElements = stackElements.size() - 1;
      std::vector<double> qualitiesLinear(numElements);
      for(std::size_t i = 0; i < numElements; ++i) {
        MElement *linear = createPrimaryElement(stackElements[i]);
        qualitiesLinear[i] = jacobianBasedQuality::minIGEMeasure(linear);
        delete linear;
      }

      static double coeffHermite[11] = {1,  .9, .8, .7, .6, .5,
                                        .4, .3, .2, .1, 0};
      for(int i = 0; i < 11; ++i) {
        _generalTFI(stackEdges, iLast, eta, terms, coeffHermite[i], gface);
        repositionInnerVertices(stackFaces, gface);

        bool allOk = true;
        if(coeffHermite[i]) {
          for(std::size_t i = 0; i < numElements; ++i) {
            double qual = jacobianBasedQuality::minIGEMeasure(stackElements[i]);
            if(qual < .5 && qual < .8 * qualitiesLinear[i]) {
              allOk = false;
              break;
            }
          }
        }

        if(allOk) return;
      }
    }
  } // namespace InteriorEdgeCurver

  MElement *createPrimaryElement(MElement *el)
  {
    int tagLinear = ElementType::getType(el->getType(), 1);
    std::vector<MVertex *> vertices;
    el->getVertices(vertices);
    MElementFactory f;
    return f.create(tagLinear, vertices, -1);
  }

  LeastSquareData *constructLeastSquareData(int typeElement, int order,
                                            int orderGauss)
  {
    // invM1 gives
    //     value of coefficients in Legendre basis
    //   + value of Lagrange multipliers
    // from
    //     Ij + value of function f at extremities
    // M2 gives
    //     Ij = integral of product function f with Legendre polynomial j
    //   + value of function f at extremities
    // from
    //     the values of function f at Gauss points
    //   + value of function f at extremities

    orthogonalBasis basis(typeElement, order);
    LeastSquareData *data = new LeastSquareData;

    if(typeElement == TYPE_LIN) {
      data->nbPoints = getNGQLPts(orderGauss);
      data->intPoints = getGQLPts(orderGauss);

      const int szSpace = order + 1;
      const int nGP = data->nbPoints;

      double *val = new double[szSpace];

      fullMatrix<double> M2(szSpace + 2, nGP + 2, true);
      {
        for(int j = 0; j < nGP; ++j) {
          basis.f(data->intPoints[j].pt[0], 0, 0, val);
          for(int i = 0; i < szSpace; ++i) {
            M2(i, j) = val[i] * data->intPoints[j].weight;
          }
        }
        M2(szSpace, nGP) = M2(szSpace + 1, nGP + 1) = 1;
      }

      fullMatrix<double> M1(szSpace + 2, szSpace + 2, true);
      {
        basis.integralfSquared(val);
        for(int k = 0; k < szSpace; ++k) M1(k, k) = val[k];

        basis.f(-1, 0, 0, val);
        for(int k = 0; k < szSpace; ++k)
          M1(szSpace, k) = M1(k, szSpace) = val[k];

        basis.f(1, 0, 0, val);
        for(int k = 0; k < szSpace; ++k)
          M1(szSpace + 1, k) = M1(k, szSpace + 1) = val[k];
      }
      fullMatrix<double> invM1;
      M1.invert(invM1);

      fullMatrix<double> Leg2Lag(szSpace, szSpace, true);
      {
        int tagLine = ElementType::getType(TYPE_LIN, order);
        const nodalBasis *fs = BasisFactory::getNodalBasis(tagLine);
        const fullMatrix<double> &refNodes = fs->getReferenceNodes();
        for(int i = 0; i < szSpace; ++i) {
          basis.f(refNodes(i, 0), 0, 0, val);
          for(int j = 0; j < szSpace; ++j) { Leg2Lag(i, j) = val[j]; }
        }
      }

      delete val;

      fullMatrix<double> tmp(szSpace + 2, nGP + 2, false);
      invM1.mult(M2, tmp);
      fullMatrix<double> tmp2(szSpace, nGP + 2, false);
      tmp2.copy(tmp, 0, szSpace, 0, nGP + 2, 0, 0);

      data->invA.resize(szSpace, nGP + 2, false);
      Leg2Lag.mult(tmp2, data->invA);
      return data;
    }

    else if(typeElement == TYPE_QUA) {
      data->nbPoints = getNGQQPts(orderGauss);
      data->intPoints = getGQQPts(orderGauss);

      fullMatrix<double> refNodes = gmshGeneratePointsQuadrangle(order);

      const int szSpace = (order + 1) * (order + 1);
      const int nGP = data->nbPoints;
      const int nConstraint = 4 * order;

      double *val = new double[szSpace];

      fullMatrix<double> M2(szSpace + nConstraint, nGP + nConstraint, true);
      {
        for(int j = 0; j < nGP; ++j) {
          basis.f(data->intPoints[j].pt[0], data->intPoints[j].pt[1], 0, val);
          for(int i = 0; i < szSpace; ++i) {
            M2(i, j) = val[i] * data->intPoints[j].weight;
          }
        }
        for(int i = 0; i < nConstraint; ++i) { M2(szSpace + i, nGP + i) = 1; }
      }

      fullMatrix<double> M1(szSpace + nConstraint, szSpace + nConstraint, true);
      {
        basis.integralfSquared(val);
        for(int k = 0; k < szSpace; ++k) M1(k, k) = val[k];

        for(int i = 0; i < nConstraint; ++i) {
          basis.f(refNodes(i, 0), refNodes(i, 1), 0, val);
          for(int k = 0; k < szSpace; ++k) {
            M1(szSpace + i, k) = M1(k, szSpace + i) = val[k];
          }
        }
      }
      fullMatrix<double> invM1;
      M1.invert(invM1);

      fullMatrix<double> Leg2Lag(szSpace, szSpace, true);
      {
        for(int i = 0; i < szSpace; ++i) {
          basis.f(refNodes(i, 0), refNodes(i, 1), 0, val);
          for(int j = 0; j < szSpace; ++j) { Leg2Lag(i, j) = val[j]; }
        }
      }

      delete val;

      fullMatrix<double> tmp(szSpace + nConstraint, nGP + nConstraint, false);
      invM1.mult(M2, tmp);
      fullMatrix<double> tmp2(szSpace, nGP + nConstraint, false);
      tmp2.copy(tmp, 0, szSpace, 0, nGP + nConstraint, 0, 0);

      data->invA.resize(szSpace, nGP + nConstraint, false);
      Leg2Lag.mult(tmp2, data->invA);
      return data;
    }

    else if(typeElement == TYPE_TRI) {
      data->nbPoints = getNGQTPts(orderGauss);
      data->intPoints = getGQTPts(orderGauss);

      fullMatrix<double> refNodes = gmshGeneratePointsTriangle(order);

      const int szSpace = (order + 1) * (order + 2) / 2;
      const int nGP = data->nbPoints;
      const int nConstraint = 3 * order;

      double *val = new double[szSpace];

      fullMatrix<double> M2(szSpace + nConstraint, nGP + nConstraint, true);
      {
        for(int j = 0; j < nGP; ++j) {
          basis.f(data->intPoints[j].pt[0], data->intPoints[j].pt[1], 0, val);
          for(int i = 0; i < szSpace; ++i) {
            M2(i, j) = val[i] * data->intPoints[j].weight;
          }
        }
        for(int i = 0; i < nConstraint; ++i) { M2(szSpace + i, nGP + i) = 1; }
      }

      fullMatrix<double> M1(szSpace + nConstraint, szSpace + nConstraint, true);
      {
        basis.integralfSquared(val);
        for(int k = 0; k < szSpace; ++k) M1(k, k) = val[k];

        for(int i = 0; i < nConstraint; ++i) {
          basis.f(refNodes(i, 0), refNodes(i, 1), 0, val);
          for(int k = 0; k < szSpace; ++k) {
            M1(szSpace + i, k) = M1(k, szSpace + i) = val[k];
          }
        }
      }
      fullMatrix<double> invM1;
      M1.invert(invM1);

      fullMatrix<double> Leg2Lag(szSpace, szSpace, true);
      {
        for(int i = 0; i < szSpace; ++i) {
          basis.f(refNodes(i, 0), refNodes(i, 1), 0, val);
          for(int j = 0; j < szSpace; ++j) { Leg2Lag(i, j) = val[j]; }
        }
      }

      delete val;

      fullMatrix<double> tmp(szSpace + nConstraint, nGP + nConstraint, false);
      invM1.mult(M2, tmp);
      fullMatrix<double> tmp2(szSpace, nGP + nConstraint, false);
      tmp2.copy(tmp, 0, szSpace, 0, nGP + nConstraint, 0, 0);

      data->invA.resize(szSpace, nGP + nConstraint, false);
      Leg2Lag.mult(tmp2, data->invA);
      return data;
    }
  }

  LeastSquareData *getLeastSquareData(int typeElement, int order,
                                      int orderGauss)
  {
    TupleLeastSquareData typeOrder(typeElement,
                                   std::make_pair(order, orderGauss));
    std::map<TupleLeastSquareData, LeastSquareData *>::iterator it;
    it = leastSquareData.find(typeOrder);

    if(it != leastSquareData.end()) return it->second;

    LeastSquareData *data =
      constructLeastSquareData(typeElement, order, orderGauss);
    leastSquareData[typeOrder] = data;
    return data;
  }

  bool computeCommonEdge(MElement *el1, MElement *el2, MEdge &e)
  {
    for(int i = 0; i < el1->getNumEdges(); ++i) {
      e = el1->getEdge(i);
      for(int j = 0; j < el2->getNumEdges(); ++j) {
        MEdge e2 = el2->getEdge(j);
        if(e == e2) return true;
      }
    }
    e = MEdge();
    return false;
  }

  void compute2DstackPrimaryVertices(const PairMElemVecMElem &column,
                                     std::vector<MVertex *> &stack)
  {
    MElement *bottomElement = column.first;
    const std::vector<MElement *> &stackElements = column.second;
    int numVertexPerLayer = 2;
    unsigned long numLayers = stackElements.size();
    stack.assign(numVertexPerLayer * numLayers, nullptr);

    int k = 0;
    for(int i = 0; i < numVertexPerLayer; ++i) {
      stack[k++] = bottomElement->getVertex(i);
    }
    MEdge bottomEdge = bottomElement->getEdge(0);
    for(std::size_t i = 0; i < numLayers - 1; ++i) {
      MElement *currentElement = stackElements[i];
      MEdge topEdge;
      if(!computeCommonEdge(currentElement, stackElements[i + 1], topEdge)) {
        Msg::Error("Did not find common edge");
      }

      // Eeach edge that is not the bottom edge nor the top edge links a bottom
      // node with the corresponding top node
      for(int j = 0; j < currentElement->getNumEdges(); ++j) {
        MEdge edge = currentElement->getEdge(j);
        if(edge == bottomEdge || edge == topEdge) continue;

        MVertex *vbot, *vtop;
        if(edge.getVertex(0) == bottomEdge.getVertex(0) ||
           edge.getVertex(0) == bottomEdge.getVertex(1)) {
          vbot = edge.getVertex(0);
          vtop = edge.getVertex(1);
        }
        else {
          vbot = edge.getVertex(1);
          vtop = edge.getVertex(0);
        }

        for(int l = k - numVertexPerLayer; l < k; ++l) {
          if(stack[l] == vbot) { stack[l + numVertexPerLayer] = vtop; }
        }
      }

      // If there remains NULL values, it is because the vertex is the same
      // on bottom face and top face.
      for(int l = k; l < k + numVertexPerLayer; ++l) {
        if(stack[l] == nullptr) { stack[l] = stack[l - numVertexPerLayer]; }
      }

      k += numVertexPerLayer;
      bottomEdge = topEdge;
    }
  }

  void computeStackHOEdgesFaces(const PairMElemVecMElem &column,
                                std::vector<MEdgeN> &stackEdges,
                                std::vector<MFaceN> &stackFaces)
  {
    const std::vector<MElement *> &stackElements = column.second;
    const int numElements = (int)stackElements.size();
    stackEdges.resize(numElements);
    stackFaces.resize(numElements);

    std::vector<MVertex *> primVert;
    compute2DstackPrimaryVertices(column, primVert);

    for(std::size_t i = 0; i < numElements; ++i) {
      MEdge e(primVert[2 * i + 0], primVert[2 * i + 1]);
      stackEdges[i] = stackElements[i]->getHighOrderEdge(e);
    }
    for(std::size_t i = 0; i < numElements - 1; ++i) {
      MFace face;
      if(primVert[2 * i + 0] == primVert[2 * i + 2])
        face =
          MFace(primVert[2 * i + 1], primVert[2 * i + 0], primVert[2 * i + 3]);
      else if(primVert[2 * i + 1] == primVert[2 * i + 3])
        face =
          MFace(primVert[2 * i + 0], primVert[2 * i + 1], primVert[2 * i + 2]);
      else
        face = MFace(primVert[2 * i + 0], primVert[2 * i + 1],
                     primVert[2 * i + 3], primVert[2 * i + 2]);
      stackFaces[i] = stackElements[i]->getHighOrderFace(face);
    }
    // We don't care about the orientation of the last element
    stackFaces.back() = stackElements.back()->getHighOrderFace(0, 0, 0);
  }

  bool edgesShareVertex(MEdgeN *e0, MEdgeN *e1)
  {
    MVertex *v = e0->getVertex(0);
    MVertex *v0 = e1->getVertex(0);
    if(v == v0) return true;
    MVertex *v1 = e1->getVertex(1);
    if(v == v1) return true;
    v = e0->getVertex(1);
    if(v == v0) return true;
    if(v == v1) return true;
    return false;
  }

  void repositionInnerVertices(const std::vector<MFaceN> &stackFaces,
                               const GFace *gface)
  {
    if(stackFaces.empty()) return;

    int order = stackFaces[0].getPolynomialOrder();
    const fullMatrix<double> *placementTri, *placementQua, *placement;

    placementTri = InnerVertPlacementMatrices::triangle(order, true);
    placementQua = InnerVertPlacementMatrices::quadrangle(order, true);

    for(std::size_t i = 0; i < stackFaces.size() - 1; ++i) {
      const MFaceN &face = stackFaces[i];
      if(face.getType() == TYPE_QUA)
        face.repositionInnerVertices(placementQua);
      else
        face.repositionInnerVertices(placementTri);
      if(gface) projectVerticesIntoGFace(&face, gface, false);
    }

    if(stackFaces.back().getType() == TYPE_QUA) {
      placement = InnerVertPlacementMatrices::quadrangle(order, false);
    }
    else {
      placement = InnerVertPlacementMatrices::triangle(order, false);
    }
    stackFaces.back().repositionInnerVertices(placement);
    if(gface) projectVerticesIntoGFace(&stackFaces.back(), gface, false);
  }

  bool curve2Dcolumn(PairMElemVecMElem &column, const GFace *gface,
                     const GEdge *gedge, const SVector3 &normal)
  {
    // This approach consists in:
    // 1. Curving the first edge not on the boundary of the geometry and
    //    the last edge of the column, using data from the edge on the boundary
    //    for both.
    // 2. In `recoverQualityElements`, checking that the curving computed
    //    in `1.` will allow to generate good quality elements.
    //    If this is not the case, the order and/or the curving
    //    of the last edge is reduced.
    // 3. In `curveEdgesAndPreserveQuality`, curving the other edges
    //    of the column and positioning the interior nodes of each element.
    //
    // Note: Here, either gface is defined and not normal, or the normal
    // is defined and not gface.

    if(column.second.size() < 2) return true;

    // Compute stack high order edges and faces
    std::vector<MEdgeN> stackEdges;
    std::vector<MFaceN> stackFaces;
    computeStackHOEdgesFaces(column, stackEdges, stackFaces);

    // Curve topEdge of first element and last edge
    int iFirst = 1, iLast = (int)stackEdges.size() - 1;
    MEdgeN *baseEdge = &stackEdges[0];
    MEdgeN *firstEdge = &stackEdges[iFirst];
    if(edgesShareVertex(baseEdge, firstEdge)) {
      iFirst = 2;
      firstEdge = &stackEdges[iFirst];
    }
    MEdgeN *topEdge = &stackEdges[iLast];

    EdgeCurver2D::curveEdge(baseEdge, firstEdge, gface, gedge, normal);
    EdgeCurver2D::curveEdge(baseEdge, topEdge, gface, gedge, normal);
    EdgeCurver2D::recoverQualityElements(stackEdges, stackFaces, column.second,
                                         iFirst, iLast, gface);

    // Curve interior edges and inner vertices
    InteriorEdgeCurver::curveEdgesAndPreserveQuality(
      stackEdges, stackFaces, column.second, iFirst, iLast, gface);
    return true;
  }

  void computeRelativePositions(const std::vector<MEdgeN> &stackEdges, std::vector<double> relativePositions)
  {
    // FIXME: this is some basic code, need generalization for extrusion normal
    //        changing direction

    // Compute total thickness (left and right)
    const MEdgeN *baseEdge = &stackEdges[0];
    SVector3 v = stackEdges.back().pnt(-1) - baseEdge->pnt(-1);
    double thickness_left = v.norm();
    v = stackEdges.back().pnt(1) - baseEdge->pnt(1);
    double thickness_right = v.norm();

    // Compute ratios
    relativePositions.resize(stackEdges.size());
    relativePositions[0] = 0.0;
    for(auto i = 1; i < stackEdges.size(); ++i) {
      const MEdgeN *edge = &stackEdges[i];
      v = edge->pnt(-1) - baseEdge->pnt(-1);
      double ratio = v.norm() / thickness_left;
      v = edge->pnt(1) - baseEdge->pnt(1);
      relativePositions[i] = std::min(ratio, v.norm() / thickness_right);
    }
  }

  bool curve2Dcolumn_newIdea(Parameters params, PairMElemVecMElem &column, const GFace *gface,
                             const GEdge *gedge, const SVector3 &normal)
  {
    // This approach consists in:
    // 1. Curving the edges of the column sequentially. For each, the data
    //    that is used to compute the curving is taken from the previous edge.
    // 2. Positioning the interior nodes of each element.
    //
    // Some quality checks will be needed but are not yet implemented (FIXME)
    //
    // Note: Here, either gface is defined and not normal, or the normal
    // is defined and not gface.

    if(column.second.size() < 2) return true;

    // Compute stack high order edges and faces
    std::vector<MEdgeN> stackEdges;
    std::vector<MFaceN> stackFaces;
    computeStackHOEdgesFaces(column, stackEdges, stackFaces);

    // Compute relative positions
    std::vector<double> relativePositions(stackEdges.size());
    computeRelativePositions(stackEdges, relativePositions);

    // Curve all edges
    for(auto i = 1; i < stackEdges.size(); ++i) {
      MEdgeN *next = nullptr;
      if(i+1 < stackEdges.size()) {
       next = &stackEdges[i+1];
      }
      EdgeCurver2D::curveEdge_newIdea(&stackEdges[i-1], &stackEdges[i], gface, normal, next, relativePositions[i]);
      // FIXME: Should we check the quality of first element? In which case, if
      //  the quality is not good, what do we do? I don't know for now
    }
    // TODO: Here we need to check the validity/quality of the two last elements
    //  (last of BL and exterior one) and reduce the curvature if necessary.

    double gamma = 0;
    double start = 0;
    int start_index = -1;
    int N = (int)stackEdges.size();
    if(gamma) {
      double coeff = 0, max_displ = 0;
      coeff = EdgeCurver2D::match_gamma_simpler(gamma, &stackEdges.back(), gface, normal);
      // max_displ = EdgeCurver2D::match_gamma_simpler2(gamma, &stackEdges.back(), gface, normal);
      std::cout << "coeff = " << coeff << std::endl;
      for(int i = 1; i < N - 1; ++i) {
        double c = 0;
        double dx = 0;
        if(relativePositions[i] > start) {
          c = coeff / (1 - start) * (relativePositions[i] - start);
          dx = max_displ / (1 - start) * (relativePositions[i] - start);
          // if(start_index == -1) start_index = i - 1;
          // c = coeff / (N-1 - start_index) * (i - start_index);
          // dx = max_displ / (N-1 - start_index) * (i - start_index);
          std::cout << "c[" << i << "] = " << c << std::endl;
        }
        // EdgeCurver2D::linearize(c, &stackEdges[i], gface, normal);
        EdgeCurver2D::_reduceCurving(&stackEdges[i], c, gface);
        // EdgeCurver2D::_reduceCurving2(&stackEdges[i], dx, gface);
      }
    }
    // Reduce curving based on

      //     => • L = (L_lin + L_disc) / 2
      //        • Z = sum |x_i-z_i| / (N-1) (car Simpson)
      //        • R = (1 - 2*Z/L) ** 4
      //        • R >= gamma

    repositionInnerVertices(stackFaces, gface);

    // FIXME: Should we check the quality of all the elements?
    return true;
  }

  bool dev_change_normals(PairMElemVecMElem &column, const GFace *gface,
                             const GEdge *gedge, const SVector3 &normal)
  {

    if(column.second.size() < 2) return true;
    if(column.second.size() > 20) return true;

    // Compute stack high order edges and faces
    std::vector<MEdgeN> stackEdges;
    std::vector<MFaceN> stackFaces;
    computeStackHOEdgesFaces(column, stackEdges, stackFaces);

    //
    MVertex *v0 = stackEdges[0].getVertex(0);
    MVertex *v = stackEdges[1].getVertex(0);
    //double thick = norm3(v->point() - v0->point());
    double x = v->x() - v0->x();// = v->x() + (rand() % 1001 - 500) / 500. * thick / 2;
    double y = v->y() - v0->y();// = v->y() + (rand() % 1001 - 500) / 500. * thick / 2;
    double angle = atan2(y, x);
    std::vector<double> lengths(stackEdges.size()-1);
    for(auto i = 0; i < lengths.size(); ++i) {
      MVertex *v0 = stackEdges[i].getVertex(0);
      MVertex *v = stackEdges[i+1].getVertex(0);
      // double x = v->x();
      // double y = v->y();
      lengths[i] = norm3(v->point() - v0->point());
    }
    for(auto i = 1; i < stackEdges.size(); ++i) {
      double this_angle = angle + (rand() % 1001 - 500) / 500. * M_PI / 3.5;
      double this_length = lengths[i-1] * ((rand() % 1001) / 1000. * 1.5 + .5);
      MVertex *v0 = stackEdges[i-1].getVertex(0);
      MVertex *v = stackEdges[i].getVertex(0);
      v->x() = v0->x() + this_length * std::cos(this_angle);
      v->y() = v0->y() + this_length * std::sin(this_angle);
      std::vector<MVertex *> vert = stackFaces[i-1].getVertices();
      vert[19]->x() = 1./6 * v0->x() + 5./6 * v->x();
      vert[19]->y() = 1./6 * v0->y() + 5./6 * v->y();
      vert[20]->x() = 2./6 * v0->x() + 4./6 * v->x();
      vert[20]->y() = 2./6 * v0->y() + 4./6 * v->y();
      vert[21]->x() = 3./6 * v0->x() + 3./6 * v->x();
      vert[21]->y() = 3./6 * v0->y() + 3./6 * v->y();
      vert[22]->x() = 4./6 * v0->x() + 2./6 * v->x();
      vert[22]->y() = 4./6 * v0->y() + 2./6 * v->y();
      vert[23]->x() = 5./6 * v0->x() + 1./6 * v->x();
      vert[23]->y() = 5./6 * v0->y() + 1./6 * v->y();
    }
    return true;
  }

  SVector3 computeBisector(const SVector3 &u0, const SVector3 &u1, const SVector3 &v) {
    // Normalize the input vectors
    SVector3 n0 = u0.unit();
    SVector3 n1 = u1.unit();

    // Compute the unnormalized bisector
    SVector3 bisector = n0 + n1;

    // FIXME if bisector == 0

    // Ensure the bisector is in the same direction as 'v'
    if(dot(bisector, v) < 0.0) {
      bisector *= -1;
    }

    // bisector.normalize();
    // bisector *= v.norm();

    return bisector.unit();
  }


  bool dev_reorient_normals(VecPairMElemVecMElem &columns, const GFace *gface,
                             const GEdge *gedge, const SVector3 &normal)
  {
    for(auto &column : columns) {
      if(column.second.size() > 20) continue;
      // std::cout << column.second.size() << std::endl;
      for(auto &column_other : columns) {
        if(&column == &column_other) continue;
        MElement *el0 = column.second[0];
        MElement *el1 = column_other.second[0];
        MEdge e;
        if(!computeCommonEdge(el0, el1, e)) continue;

        MElement *b0 = column.first;
        MElement *b1 = column_other.first;
        const MEdgeN e0 = b0->getHighOrderEdge(b0->getEdge(0));
        const MEdgeN e1 = b1->getHighOrderEdge(b1->getEdge(0));
        MVertex *v_common = nullptr;
        for(int i = 0; i < 2; ++i) {
          if(e0.getVertex(i) == e1.getVertex(0) || e0.getVertex(i) == e1.getVertex(1)) {
            v_common = e0.getVertex(i);
            break;
          }
        }
        if(!v_common) {
          std::cerr << "Error: no common vertex between columns" << std::endl;
        }


        SVector3 u0, u1, v;
        for(int i = 0; i < 2; ++i) {
          if(e.getVertex(i) != v_common) {
            v = e.getVertex(i)->point() - v_common->point();
          }
        }

        int polyo = e0.getPolynomialOrder();
        if(e0.getVertex(0) == v_common) {
          u0 = e0.getVertex(2)->point() - v_common->point();
        }
        else {
          u0 = e0.getVertex(polyo)->point() - v_common->point();
        }
        if(e1.getVertex(0) == v_common) {
          u1 = e1.getVertex(2)->point() - v_common->point();
        }
        else {
          u1 = e1.getVertex(polyo)->point() - v_common->point();
        }

        SVector3 bisector = computeBisector(u0, u1, v);

        SPoint3 p0 = v_common->point(), p1;
        MVertex *v0 = v_common;

        std::vector<MElement*> stack;
        MEdge bottomEdge;
        if(column.second.size() > column_other.second.size()) {
          stack = column.second;
          bottomEdge = b0->getEdge(0);
        }
        else {
          stack = column_other.second;
          bottomEdge = b1->getEdge(0);
        }

        for(int i = 0; i < (int)stack.size()-1; ++i) {
          MElement *el = stack[i];
          MEdge e;
          for(int j = 0; j < 4; ++j) {
            e = el->getEdge(j);
            if(e == bottomEdge) continue;
            if(e.getVertex(0) == v0 || e.getVertex(1) == v0) break;
          }
          MVertex *other_v = nullptr;
          for(int j = 0; j < 2; ++j) {
            if(e.getVertex(j) != v0) { // `e(j)` gives the vertices of the edge
              other_v = e.getVertex(j);
              break;
            }
          }
          if(!other_v) {
            std::cerr << "Error: no other vertex found" << std::endl;
          }

          p1 = other_v->point();
          SVector3 v01 = p1 - p0;
          double length = v01.norm();

          // Compute the new position for `other_v`
          SPoint3 new_position = v0->point() + bisector * length; // v0 + bisector vector

          // Update the position of `other_v` to the new position
          other_v->setXYZ(new_position.x(), new_position.y(), new_position.z());

          // Advance v0 to the newly repositioned vertex
          v0 = other_v;
          p0 = p1;

          // Interior nodes
          MEdgeN e_ho = el->getHighOrderEdge(e);
          for(int j = 2; j < polyo+1; ++j) {
            double f = static_cast<double>(j-1) / polyo;
            double x = (1-f) * e_ho.getVertex(0)->x() + f * e_ho.getVertex(1)->x();
            double y = (1-f) * e_ho.getVertex(0)->y() + f * e_ho.getVertex(1)->y();
            double z = (1-f) * e_ho.getVertex(0)->z() + f * e_ho.getVertex(1)->z();
            e_ho.getVertex(j)->setXYZ(x, y, z);
          }

          computeCommonEdge(stack[i+1], el, bottomEdge);
        }
      }
    }
  }

  bool dev_touch_boundary(PairMElemVecMElem &column, const GFace *gface,
                             const GEdge *gedge, const SVector3 &normal)
  {
    if(column.second.size() < 2) return true;

    // Compute stack high order edges and faces
    std::vector<MEdgeN> stackEdges;
    std::vector<MFaceN> stackFaces;
    computeStackHOEdgesFaces(column, stackEdges, stackFaces);

    MEdgeN &edge = stackEdges[0];
    int polyo = edge.getPolynomialOrder();

    // Compute L_discrete
    double L_disc = 0;
    double vx, vy, vz;

    vx = edge.getVertex(2)->x() - edge.getVertex(0)->x();
    vy = edge.getVertex(2)->y() - edge.getVertex(0)->y();
    vz = edge.getVertex(2)->z() - edge.getVertex(0)->z();
    L_disc = sqrt(vx * vx + vy * vy + vz * vz);

    vx = edge.getVertex(1)->x() - edge.getVertex(polyo)->x();
    vy = edge.getVertex(1)->y() - edge.getVertex(polyo)->y();
    vz = edge.getVertex(1)->z() - edge.getVertex(polyo)->z();
    L_disc += sqrt(vx * vx + vy * vy + vz * vz);

    for(int i = 2; i < polyo; ++i) {
      vx = edge.getVertex(i+1)->x() - edge.getVertex(i)->x();
      vy = edge.getVertex(i+1)->y() - edge.getVertex(i)->y();
      vz = edge.getVertex(i+1)->z() - edge.getVertex(i)->z();
      L_disc += std::sqrt(vx*vx + vy*vy + vz*vz);
    }

    double pert = L_disc / polyo / 10;

    for(int i = 2; i < polyo + 1; ++i) {
      MVertex *v = edge.getVertex(i);
      v->x() += pert * (rand() % 1001 - 500) / 500.;
      v->y() += pert * (rand() % 1001 - 500) / 500.;
      v->z() += pert * (rand() % 1001 - 500) / 500.;
    }
    return true;
  }
} // namespace BoundaryLayerCurver

void curve2DBoundaryLayer(VecPairMElemVecMElem &bndEl2column, SVector3 normal,
                          const GEdge *gedge)
{
  // TODO:
  //  1. Check if easy to include to GUI. Include to GUI or make usable by script
  //  2. Create class for parameters:
  //     - skip ensuring good quality element touching the BLM
  //     - how much reduce curving last layer
  //     - how much last layer should be close to linearity
  //       => reduce curving for meeting all three conditions
  //     - % of thickness of high quality elements (if possible)
  //     - how much to force continuity between elements
  //  3. Implement quality check
  //     - at forward stage
  //     - at backward stage
  //  4. Implement better reducing of curving inside BLM
  //  5. Push to Git

  // TODO:
  //  • Implement triangles
  //  • Implement suface BL
  //  • Clean the code

  double length = normal.normalize();
  if(length == 0) {
    Msg::Error("normal must be non-zero for boundary layer curving");
    return;
  }

  // // Hack for making pictures without HO vertices of triangles
  // {
  //   if(normal.z() < .5) {
  //     normal *= -1; // FIXME Hack for making work msh quad HO
  //   }
  //
  //   if(bndEl2column.empty()) return;
  //
  //   std::unordered_set<MVertex*> vertices_to_keep;
  //   for(auto gface = GModel::current()->firstFace(); gface != GModel::current()->lastFace(); ++gface) {
  //     std::vector<MQuadrangle*> quadrangles = (*gface)->quadrangles;
  //     for(auto quad : quadrangles) {
  //       int num_vert = quad->getNumVertices();
  //       for(int i = 0; i < num_vert; ++i) {
  //         MVertex *v = quad->getVertex(i);
  //         vertices_to_keep.insert(v);
  //       }
  //     }
  //   }
  //
  //   for(auto gface = GModel::current()->firstFace(); gface != GModel::current()->lastFace(); ++gface) {
  //     std::vector<MTriangle*> triangles = (*gface)->triangles;
  //     for(auto triangle : triangles) {
  //       int num_vert = triangle->getNumVertices();
  //       int polyo = triangle->getPolynomialOrder();
  //       for(int i = 3*polyo; i < num_vert; ++i) {
  //         MVertex *v = triangle->getVertex(i);
  //         v->setXYZ(-100, -100, 0);
  //       }
  //     }
  //     (*gface)->triangles.clear(); // FIXME Hack for visu
  //
  //     std::vector<MVertex*> vertices = (*gface)->mesh_vertices;
  //
  //     std::vector<MVertex*> vertices_to_remove;
  //     for (MVertex *v : vertices) {
  //       if (vertices_to_keep.find(v) == vertices_to_keep.end()) {
  //         vertices_to_remove.push_back(v);
  //       }
  //     }
  //
  //     std::cout << "Removing " << vertices_to_remove.size() << " vertices" << std::endl;
  //
  //     for(auto &v : vertices_to_remove) {
  //       v->setXYZ(-100, -100, 0);
  //     }
  //   }
  // }

  //  for (int i = 0; i < bndEl2column.size(); ++i) {
  //    bndEl2column[i].first->setVisibility(1);
  //    for (std::size_t j = 0; j < bndEl2column[i].second.size(); ++j) {
  //      bndEl2column[i].second[j]->setVisibility(1);
  //    }
  //  }

  // for(int i = 0; i < bndEl2column.size(); ++i) {
  //   BoundaryLayerCurver::dev_touch_boundary(bndEl2column[i], nullptr, gedge, normal);
  // }

  // for(int i = 0; i < bndEl2column.size(); ++i) {
  //   BoundaryLayerCurver::dev_change_normals(bndEl2column[i], nullptr, gedge, normal);
  // }

  // BoundaryLayerCurver::dev_reorient_normals(bndEl2column, nullptr, gedge, normal);

  for(int i = 0; i < bndEl2column.size(); ++i) {
    // if (bndEl2column[i].first->getNum() != 205) continue; // t161
    // if (bndEl2column[i].first->getNum() != 316) continue; // t161
    // if (bndEl2column[i].first->getNum() != 1156) continue; // trimesh
    // std::cout << bndEl2column[i].first->getNum() << std::endl;
    // if (   bndEl2column[i].first->getNum() != 1156
        // && bndEl2column[i].first->getNum() != 1079
        // && bndEl2column[i].first->getNum() != 1102
        // && bndEl2column[i].first->getNum() != 1119) continue;
    // if (   bndEl2column[i].first->getNum() != 1156) continue;
    // if (   bndEl2column[i].first->getNum() != 1157) continue;
    // std::cout << std::endl;
    // std::cout << "column " << bndEl2column[i].first->getNum() << std::endl;
    // if (bndEl2column[i].first->getNum() != 1079) continue; // Good
    // if (bndEl2column[i].first->getNum() != 1078) continue; // Next to good
    // if (bndEl2column[i].first->getNum() != 1099) continue; // Long on corner
    // if (bndEl2column[i].first->getNum() != 1102) continue; // HO
    // if (bndEl2column[i].first->getNum() != 1136) continue; // Bad linear
    // if (bndEl2column[i].first->getNum() != 1149) continue; // shorter
    // if (bndEl2column[i].first->getNum() != 1150) continue; // concave
    // if (bndEl2column[i].first->getNum() != 1151) continue; // symetric of concave
    // if (bndEl2column[i].first->getNum() != 1156) continue; // Strange
    // if (bndEl2column[i].first->getNum() != 1157) continue; // next to Strange
    // if (bndEl2column[i].first->getNum() != 6994) continue; // HO -> trailingL2
    // BoundaryLayerCurver::curve2Dcolumn(bndEl2column[i], nullptr, gedge, normal);
    //if (bndEl2column[i].first->getNum() != 12882) continue;
    BoundaryLayerCurver::curve2Dcolumn_newIdea(bndEl2column[i], nullptr, gedge, normal);
  }
}

void curve2DBoundaryLayer(VecPairMElemVecMElem &bndEl2column,
                          const GFace *gface, const GEdge *gedge)
{
  if(!gface || !gedge) {
    Msg::Error("both gface and gedge are needed for boundary layer curving "
               "(%d, %d)",
               gface, gedge);
    return;
  }

  //  for (int i = 0; i < bndEl2column.size(); ++i) {
  //    bndEl2column[i].first->setVisibility(1);
  //    for (std::size_t j = 0; j < bndEl2column[i].second.size(); ++j) {
  //      bndEl2column[i].second[j]->setVisibility(1);
  //    }
  //  }

  for(int i = 0; i < bndEl2column.size(); ++i)
//    BoundaryLayerCurver::curve2Dcolumn(bndEl2column[i], gface, gedge,
//                                       SVector3());
    BoundaryLayerCurver::curve2Dcolumn_newIdea(bndEl2column[i], nullptr, gedge,
                                       SVector3());
}
