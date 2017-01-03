// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include <sstream>
#include "GModel.h"
#include "GFace.h"
#include "GFaceCompound.h"
#include "gmshEdge.h"
#include "Geo.h"
#include "GeoInterpolation.h"
#include "GmshMessage.h"
#include "Context.h"
#include "decasteljau.h"

gmshEdge::gmshEdge(GModel *m, Curve *edge, GVertex *v1, GVertex *v2)
  : GEdge(m, edge->Num, v1, v2), c(edge)
{
  resetMeshAttributes();
}

bool gmshEdge::degenerate(int dim) const
{
  if (c->beg == c->end &&
      c->Typ ==  MSH_SEGM_LINE &&
      List_Nbr(c->Control_Points) == 0){
    Msg::Info("Model Edge %d is degenerate", tag());
    return true;
  }
  return false;
}

void gmshEdge::resetMeshAttributes()
{
  meshAttributes.method = c->Method;
  meshAttributes.nbPointsTransfinite = c->nbPointsTransfinite;
  meshAttributes.typeTransfinite = c->typeTransfinite;
  meshAttributes.coeffTransfinite = c->coeffTransfinite;
  meshAttributes.extrude = c->Extrude;
  meshAttributes.reverseMesh = c->ReverseMesh;
}

Range<double> gmshEdge::parBounds(int i) const
{
 return Range<double>(c->ubeg, c->uend);
}

GPoint gmshEdge::point(double par) const
{
  Vertex a = InterpolateCurve(c, par, 0);
  return GPoint(a.Pos.X, a.Pos.Y, a.Pos.Z, this, par);
}

SVector3 gmshEdge::firstDer(double par) const
{
  Vertex a = InterpolateCurve(c, par, 1);
  return SVector3(a.Pos.X, a.Pos.Y, a.Pos.Z);
}

SVector3 gmshEdge::secondDer(double par) const
{
  Vertex a = InterpolateCurve(c, par, 2);
  return SVector3(a.Pos.X, a.Pos.Y, a.Pos.Z);
}

GEntity::GeomType gmshEdge::geomType() const
{
  switch (c->Typ){
  case MSH_SEGM_LINE : return Line;
  case MSH_SEGM_CIRC :
  case MSH_SEGM_CIRC_INV : return Circle;
  case MSH_SEGM_ELLI:
  case MSH_SEGM_ELLI_INV: return Ellipse;
  case MSH_SEGM_BSPLN:
  case MSH_SEGM_BEZIER:
  case MSH_SEGM_NURBS:
  case MSH_SEGM_SPLN: return Nurb;
  case MSH_SEGM_BND_LAYER: return BoundaryLayerCurve;
  case MSH_SEGM_DISCRETE: return DiscreteCurve;
  default : return Unknown;
  }
}

std::string gmshEdge::getAdditionalInfoString()
{
  if(List_Nbr(c->Control_Points) > 0){
    std::ostringstream sstream;
    sstream << "{";
    for(int i = 0; i < List_Nbr(c->Control_Points); i++){
      if(i) sstream << " ";
      Vertex *v;
      List_Read(c->Control_Points, i, &v);
      sstream << v->Num;
    }
    sstream << "}";

    if(meshAttributes.method == MESH_TRANSFINITE){
      sstream << " transfinite (" << meshAttributes.nbPointsTransfinite;
      int type = meshAttributes.typeTransfinite;
      if(std::abs(type) == 1)
        sstream << ", progression " << gmsh_sign(type) * meshAttributes.coeffTransfinite;
      else if(std::abs(type) == 2)
        sstream << ", bump " << meshAttributes.coeffTransfinite;
      sstream << ")";
    }
    if(meshAttributes.extrude)
      sstream << " extruded";
    if(meshAttributes.reverseMesh)
      sstream << " reversed";

    return sstream.str();
  }
  else
    return GEdge::getAdditionalInfoString();
}

int gmshEdge::minimumMeshSegments () const
{
  int np;
  if(geomType() == Line){
    np = GEdge::minimumMeshSegments();
    // FIXME FOR QUADS
    if(List_Nbr(c->Control_Points) > 2){
      np = 3 * (List_Nbr(c->Control_Points)) + 1;
    }
  }
  else if(geomType() == Circle || geomType() == Ellipse)
    np = (int)(0.99 + fabs(c->Circle.t1 - c->Circle.t2) *
               ((double)CTX::instance()->mesh.minCircPoints - 1.0) / (2 * M_PI));
  else
    np = CTX::instance()->mesh.minCurvPoints - 1;
  return std::max(np, meshAttributes.minimumMeshSegments);
}

int gmshEdge::minimumDrawSegments () const
{
  int n = List_Nbr(c->Control_Points) - 1;
  if(!n) n = GEdge::minimumDrawSegments();

  if(geomType() == Line && !c->geometry)
    return n;
  else
    return CTX::instance()->geom.numSubEdges * n;
}

SPoint2 gmshEdge::reparamOnFace(const GFace *face, double epar,int dir) const
{
  Surface *s = (Surface*) face->getNativePtr();

  bool periodic = (c->end == c->beg);
  if(s->geometry){
    switch (c->Typ) {
    case MSH_SEGM_LINE:
      {
        Vertex *v[3];
        List_Read(c->Control_Points, 0, &v[1]);
        List_Read(c->Control_Points, 1, &v[2]);
        SPoint2 p = v[1]->pntOnGeometry +
          (v[2]->pntOnGeometry - v[1]->pntOnGeometry) * epar;
        return p;
      }
    case MSH_SEGM_BSPLN:
    case MSH_SEGM_BEZIER:
      {
        int NbControlPoints = List_Nbr(c->Control_Points);
        int NbCurves = NbControlPoints + (periodic ? -1 : 1);
        int iCurve = (int)floor(epar * (double)NbCurves);
        if(iCurve >= NbCurves)
          iCurve = NbCurves - 1;
        else if (iCurve < 0) // ? does it happen ?
          iCurve = 0;
        double t1 = (double)(iCurve) / (double)(NbCurves);
        double t2 = (double)(iCurve+1) / (double)(NbCurves);
        double t = (epar - t1) / (t2 - t1);
        Vertex *v[4];
        for(int j = 0; j < 4; j ++ ){
          int k = iCurve - (periodic ? 1 : 2) + j;
          if(k < 0)
            k = periodic ? k + NbControlPoints - 1 : 0;
          if(k >= NbControlPoints)
            k = periodic ? k - NbControlPoints + 1: NbControlPoints - 1;
          List_Read(c->Control_Points, k, &v[j]);
        }
        return InterpolateCubicSpline(v, t, c->mat, t1, t2, c->geometry,0);
      }
    case MSH_SEGM_SPLN :
      {
        Vertex temp1, temp2;
        int N = List_Nbr(c->Control_Points);
        int i = (int)((double)(N - 1) * epar);
        if(i < 0)
          i = 0;
        if(i >= N - 1)
          i = N - 2;
        double t1 = (double)(i) / (double)(N - 1);
        double t2 = (double)(i + 1) / (double)(N - 1);
        double t = (epar - t1) / (t2 - t1);
        Vertex *v[4];
        List_Read(c->Control_Points, i, &v[1]);
        List_Read(c->Control_Points, i + 1, &v[2]);
        if(!i) {
          if(c->beg == c->end){
            List_Read(c->Control_Points,N-2,&v[0]);
          }
          else{
            v[0] = &temp1;
            v[0]->pntOnGeometry = v[1]->pntOnGeometry * 2. - v[2]->pntOnGeometry;
          }
        }
        else{
          List_Read(c->Control_Points, i - 1, &v[0]);
        }
        if(i == N - 2) {
          if(c->beg == c->end){
            List_Read(c->Control_Points,1,&v[3]);
          }
          else{
            v[3] = &temp2;
            v[3]->pntOnGeometry = v[2]->pntOnGeometry * 2. - v[1]->pntOnGeometry;
          }
        }
        else{
          List_Read(c->Control_Points, i + 2, &v[3]);
        }
        return InterpolateCubicSpline(v, t, c->mat, t1, t2, c->geometry,0);
      }
    default:
      Msg::Error("Unknown edge type in reparamOnFace");
      return SPoint2();
    }
  }


  if(s->Typ ==  MSH_SURF_REGL){
    Curve *C[4];
    for(int i = 0; i < 4; i++)
      List_Read(s->Generatrices, i, &C[i]);

    double U, V;
    if (C[0]->Num == c->Num) {
      U = (epar - C[0]->ubeg) / (C[0]->uend - C[0]->ubeg) ;
      V = 0;
    }
    else if (C[0]->Num == -c->Num) {
      U = (C[0]->uend - epar - C[0]->ubeg) / (C[0]->uend - C[0]->ubeg) ;
      V = 0;
    }
    else if (C[1]->Num == c->Num) {
      V = (epar - C[1]->ubeg) / (C[1]->uend - C[1]->ubeg) ;
      U = 1;
    }
    else if (C[1]->Num == -c->Num) {
      V = (C[1]->uend - epar - C[1]->ubeg) / (C[1]->uend - C[1]->ubeg) ;
      U = 1;
    }
    else if (C[2]->Num == c->Num) {
      U =  1 - (epar - C[2]->ubeg) / (C[2]->uend - C[2]->ubeg) ;
      V = 1;
    }
    else if (C[2]->Num == -c->Num) {
      U =  1 - ( C[2]->uend -epar - C[2]->ubeg) / (C[2]->uend - C[2]->ubeg) ;
      V = 1;
    }
    else if (C[3]->Num == c->Num) {
      V = 1-(epar - C[3]->ubeg) / (C[3]->uend - C[3]->ubeg) ;
      U = 0;
    }
    else if (C[3]->Num == -c->Num) {
      V = 1-(C[3]->uend - epar - C[3]->ubeg) / (C[3]->uend - C[3]->ubeg) ;
      U = 0;
    }
    else{
      Msg::Info("Reparameterizing edge %d on face %d", c->Num, s->Num);
      return GEdge::reparamOnFace(face, epar, dir);
    }
    return SPoint2(U, V);
  }
  else if (s->Typ == MSH_SURF_TRIC){
    Curve *C[3];
    for(int i = 0; i < 3; i++)
      List_Read(s->Generatrices, i, &C[i]);
    double U, V;
    if(CTX::instance()->geom.oldRuledSurface){
      if (C[0]->Num == c->Num) {
        U = (epar - C[0]->ubeg) / (C[0]->uend - C[0]->ubeg) ;
        V = 0;
      }
      else if (C[0]->Num == -c->Num) {
        U = (C[0]->uend - epar - C[0]->ubeg) / (C[0]->uend - C[0]->ubeg) ;
        V = 0;
      }
      else if (C[1]->Num == c->Num) {
        V = (epar - C[1]->ubeg) / (C[1]->uend - C[1]->ubeg) ;
        U = 1;
      }
      else if (C[1]->Num == -c->Num) {
        V = (C[1]->uend - epar - C[1]->ubeg) / (C[1]->uend - C[1]->ubeg) ;
        U = 1;
      }
      else if (C[2]->Num == c->Num) {
        U = 1-(epar - C[2]->ubeg) / (C[2]->uend - C[2]->ubeg) ;
        V = 1;
      }
      else if (C[2]->Num == -c->Num) {
        U = 1-(C[2]->uend - epar - C[2]->ubeg) / (C[2]->uend - C[2]->ubeg) ;
        V = 1;
      }
      else{
        Msg::Info("Reparameterizing edge %d on face %d", c->Num, s->Num);
        return GEdge::reparamOnFace(face, epar, dir);
      }

    }
    else{
      // FIXME: workaround for exact extrusions
      bool hack = false;
      if(CTX::instance()->geom.exactExtrusion && s->Extrude &&
         s->Extrude->geo.Mode == EXTRUDED_ENTITY && s->Typ != MSH_SURF_PLAN)
        hack = true;
      if (C[0]->Num == c->Num) {
        U = (epar - C[0]->ubeg) / (C[0]->uend - C[0]->ubeg) ;
        V = 0;
      }
      else if (C[0]->Num == -c->Num) {
        U = (C[0]->uend - epar - C[0]->ubeg) / (C[0]->uend - C[0]->ubeg) ;
        V = 0;
      }
      else if (C[1]->Num == c->Num) {
        V = (epar - C[1]->ubeg) / (C[1]->uend - C[1]->ubeg) ;
        U = 1;
      }
      else if (C[1]->Num == -c->Num) {
        V = (C[1]->uend - epar - C[1]->ubeg) / (C[1]->uend - C[1]->ubeg) ;
        U = 1;
      }
      else if (C[2]->Num == c->Num) {
        U = 1-(epar - C[2]->ubeg) / (C[2]->uend - C[2]->ubeg) ;
        V = hack ? 1 : U;
      }
      else if (C[2]->Num == -c->Num) {
        U = 1-(C[2]->uend - epar - C[2]->ubeg) / (C[2]->uend - C[2]->ubeg) ;
        V = hack ? 1 : U;
      }
      else{
        Msg::Info("Reparameterizing edge %d on face %d", c->Num, s->Num);
        return GEdge::reparamOnFace(face, epar, dir);
      }
    }
    return SPoint2(U, V);
  }
  else{
    return GEdge::reparamOnFace(face, epar, dir);
  }
}

void gmshEdge::writeGEO(FILE *fp)
{
  if(!c || c->Num < 0 || c->Typ == MSH_SEGM_DISCRETE) return;
  switch (c->Typ) {
  case MSH_SEGM_LINE:
    fprintf(fp, "Line(%d) = ", c->Num);
    break;
  case MSH_SEGM_CIRC:
  case MSH_SEGM_CIRC_INV:
    fprintf(fp, "Circle(%d) = ", c->Num);
    break;
  case MSH_SEGM_ELLI:
  case MSH_SEGM_ELLI_INV:
    fprintf(fp, "Ellipse(%d) = ", c->Num);
    break;
  case MSH_SEGM_NURBS:
    fprintf(fp, "Nurbs(%d) = {", c->Num);
    for(int i = 0; i < List_Nbr(c->Control_Points); i++) {
      Vertex *v;
      List_Read(c->Control_Points, i, &v);
      if(!i)
        fprintf(fp, "%d", v->Num);
      else
        fprintf(fp, ", %d", v->Num);
      if(i % 8 == 7 && i != List_Nbr(c->Control_Points) - 1)
        fprintf(fp, "\n");
    }
    fprintf(fp, "}\n");
    fprintf(fp, "  Knots {");
    for(int j = 0; j < List_Nbr(c->Control_Points) + c->degre + 1; j++) {
      if(!j)
        fprintf(fp, "%.16g", c->k[j]);
      else
        fprintf(fp, ", %.16g", c->k[j]);
      if(j % 5 == 4 && j != List_Nbr(c->Control_Points) + c->degre)
        fprintf(fp, "\n        ");
    }
    fprintf(fp, "}\n");
    fprintf(fp, "  Order %d;\n", c->degre);
    return;
  case MSH_SEGM_SPLN:
    fprintf(fp, "Spline(%d) = ", c->Num);
    break;
  case MSH_SEGM_BSPLN:
    fprintf(fp, "BSpline(%d) = ", c->Num);
    break;
  case MSH_SEGM_BEZIER:
    fprintf(fp, "Bezier(%d) = ", c->Num);
    break;
  default:
    Msg::Error("Unknown curve type %d", c->Typ);
    return;
  }
  for(int i = 0; i < List_Nbr(c->Control_Points); i++) {
    Vertex *v;
    List_Read(c->Control_Points, i, &v);
    if(i)
      fprintf(fp, ", %d", v->Num);
    else
      fprintf(fp, "{%d", v->Num);
    if(i % 8 == 7)
      fprintf(fp, "\n");
  }
  fprintf(fp, "};\n");

  if(meshAttributes.method == MESH_TRANSFINITE){
    fprintf(fp, "Transfinite Line {%d} = %d",
            tag() * (meshAttributes.typeTransfinite > 0 ? 1 : -1),
            meshAttributes.nbPointsTransfinite);
    if(meshAttributes.typeTransfinite){
      if(std::abs(meshAttributes.typeTransfinite) == 1)
        fprintf(fp, "Using Progression ");
      else if(std::abs(meshAttributes.typeTransfinite) == 2)
        fprintf(fp, "Using Bump ");
      fprintf(fp, "%g", meshAttributes.coeffTransfinite);
    }
    fprintf(fp, ";\n");
  }

  if(meshAttributes.reverseMesh)
    fprintf(fp, "Reverse Line {%d};\n", tag());
}

static inline SPoint3 curveGetPoint(Curve *c, int i)
{
  Vertex *v;
  List_Read(c->Control_Points, i , &v);
  return SPoint3(v->Pos.X, v->Pos.Y, v->Pos.Z);
}

void gmshEdge::discretize(double tol, std::vector<SPoint3> &pts, std::vector<double> &ts)
{
  switch(c->Typ) {
    case MSH_SEGM_LINE :
      {
        int NPt = List_Nbr(c->Control_Points);
        pts.resize(NPt);
        ts.resize(NPt);
        for (int i = 0; i < NPt; ++i) {
          pts[i]= curveGetPoint(c, i);
          ts[i] = i / (double) (NPt - 1);
        }
        return;
      }
    case MSH_SEGM_BEZIER :
      {
        int NbCurves = (List_Nbr(c->Control_Points) - 1) / 3;
        for (int iCurve = 0; iCurve < NbCurves; ++iCurve) {
          double t1 = (iCurve) / (double)(NbCurves);
          double t2 = (iCurve+1) / (double)(NbCurves);
          SPoint3 pt[4];
          for(int i = 0; i < 4; i++) {
            pt[i] = curveGetPoint(c, iCurve * 3 + i);
          }
          std::vector<double> lts;
          std::vector<SPoint3> lpts;
          decasteljau(tol, pt[0], pt[1], pt[2], pt[3], lpts, lts);
          for (size_t i = (iCurve == 0 ? 0 : 1); i < lpts.size(); ++i) {
            pts.push_back(lpts[i]);
            ts.push_back(t1 + lts[i] * (t2 - t1));
          }
        }
        break;
      }
    case MSH_SEGM_BSPLN:
      {
        bool periodic = (c->end == c->beg);
        int NbControlPoints = List_Nbr(c->Control_Points);
        int NbCurves = NbControlPoints + (periodic ? -1 : 1);
        SPoint3 pt[4];
        for (int iCurve = 0; iCurve < NbCurves; ++iCurve) {
          double t1 = (iCurve) / (double)(NbCurves);
          double t2 = (iCurve+1) / (double)(NbCurves);
          for(int i = 0; i < 4; i++) {
            int k;
            if (periodic) {
              k = (iCurve - 1 + i) % (NbControlPoints - 1);
              if (k < 0)
                k += NbControlPoints - 1;
            }
            else {
              k = std::max(0, std::min(iCurve - 2 + i, NbControlPoints -1));
            }
            pt[i] = curveGetPoint(c, k);
          }
          SPoint3 bpt[4] = {
            (pt[0] + pt[1] * 4 + pt[2]) * (1./6.),
            (pt[1] * 2 + pt[2]) * (1./3.),
            (pt[1] + pt[2] * 2) * (1./3.),
            (pt[1] + pt[2] * 4 + pt[3]) * (1./6.)
          };
          std::vector<double> lts;
          std::vector<SPoint3> lpts;
          decasteljau(tol, bpt[0], bpt[1], bpt[2], bpt[3], lpts, lts);
          for (size_t i = (iCurve == 0 ? 0 : 1); i < lpts.size(); ++i) {
            pts.push_back(lpts[i]);
            ts.push_back(t1 + lts[i] * (t2 - t1));
          }
        }
        break;
      }
    case MSH_SEGM_SPLN:
      {
        int NbCurves = List_Nbr(c->Control_Points) - 1;
        SPoint3 pt[4];
        for (int iCurve = 0; iCurve < NbCurves; ++iCurve) {
          double t1 = (iCurve) / (double)(NbCurves);
          double t2 = (iCurve+1) / (double)(NbCurves);
          pt[1] = curveGetPoint(c, iCurve);
          pt[2] = curveGetPoint(c, iCurve + 1);
          if(iCurve == 0) {
            if(c->beg == c->end)
              pt[0] = curveGetPoint(c, NbCurves - 1);
            else
              pt[0] = SPoint3(pt[1] * 2 - pt[2]);
          }
          else
            pt[0] = curveGetPoint(c, iCurve - 1);
          if(iCurve == NbCurves - 1) {
            if(c->beg == c->end)
              pt[3] = curveGetPoint(c, 1);
            else
              pt[3] = SPoint3(2 * pt[2] - pt[1]);
          }
          else
            pt[3] = curveGetPoint(c, iCurve + 2);
          SPoint3 bpt[4] = {
            pt[1],
            (pt[1] * 6 + pt[2] - pt[0]) * (1./6.),
            (pt[2] * 6 - pt[3] + pt[1]) * (1./6.),
            pt[2]
          };
          std::vector<double> lts;
          std::vector<SPoint3> lpts;
          decasteljau(tol, bpt[0], bpt[1], bpt[2], bpt[3], lpts, lts);
          for (size_t i = (iCurve == 0 ? 0 : 1); i < lpts.size(); ++i) {
            pts.push_back(lpts[i]);
            ts.push_back(t1 + lts[i] * (t2 - t1));
          }
        }
        break;
      }
    default :
      GEdge::discretize(tol, pts, ts);
  }
}
