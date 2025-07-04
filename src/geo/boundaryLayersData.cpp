// Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Michael Ermakov (ermakov@ipmnet.ru)

#include "boundaryLayersData.h"
#include "GmshConfig.h"
#include "GModel.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MEdge.h"
#include "OS.h"
#include "Context.h"

#if !defined(HAVE_MESH)

BoundaryLayerField *getBLField(GModel *gm) { return 0; }

bool buildAdditionalPoints2D(GFace *gf) { return false; }

bool buildAdditionalPoints3D(GRegion *gr) { return false; }

edgeColumn BoundaryLayerColumns::getColumns(MVertex *v1, MVertex *v2, int side)
{
  return edgeColumn(BoundaryLayerData(), BoundaryLayerData());
}

#else

#include "Field.h"

/*
               ^  ni
               |
               |
      +-----------------+
               bi      /
                 bj  /
                   /\
                 /    \   nj
               /        Z
             +
*/

SVector3 interiorNormal(const SPoint2 &p1, const SPoint2 &p2, const SPoint2 &p3)
{
  SVector3 ez(0, 0, 1);
  SVector3 d(p1.x() - p2.x(), p1.y() - p2.y(), 0);
  SVector3 h(p3.x() - 0.5 * (p2.x() + p1.x()), p3.y() - 0.5 * (p2.y() + p1.y()),
             0);
  SVector3 n = crossprod(d, ez);
  n.normalize();
  if(dot(n, h) > 0) return n;
  return n * (-1.);
}

edgeColumn BoundaryLayerColumns::getColumns(MVertex *v1, MVertex *v2, int side)
{
  MEdgeEqual aaa;
  MEdge e(v1, v2);
  auto it1 = _fans.find(v1);
  auto it2 = _fans.find(v2);
  int N1 = getNbColumns(v1);
  int N2 = getNbColumns(v2);

  int nbSides = _normals.count(e);

  // Standard case, only two extruded columns from the two vertices
  if(N1 == 1 && N2 == 1) return edgeColumn(getColumn(v1, 0), getColumn(v2, 0));
  // one fan on
  if(nbSides == 1) {
    if(it1 != _fans.end() && it2 == _fans.end()) {
      if(aaa(it1->second._e1, e))
        return edgeColumn(getColumn(v1, 0), getColumn(v2, 0));
      else
        return edgeColumn(getColumn(v1, N1 - 1), getColumn(v2, 0));
    }
    if(it2 != _fans.end() && it1 == _fans.end()) {
      if(aaa(it2->second._e1, e))
        return edgeColumn(getColumn(v1, 0), getColumn(v2, 0));
      else
        return edgeColumn(getColumn(v1, 0), getColumn(v2, N2 - 1));
    }
    if(it2 != _fans.end() && it1 != _fans.end()) {
      int c1, c2;
      if(aaa(it1->second._e1, e))
        c1 = 0;
      else
        c1 = N1 - 1;
      if(aaa(it2->second._e1, e))
        c2 = 0;
      else
        c2 = N2 - 1;
      return edgeColumn(getColumn(v1, c1), getColumn(v2, c2));
    }
    // fan on the right
    if(N1 == 1 || N2 == 2) {
      const BoundaryLayerData &c10 = getColumn(v1, 0);
      const BoundaryLayerData &c20 = getColumn(v2, 0);
      const BoundaryLayerData &c21 = getColumn(v2, 1);
      if(dot(c10._n, c20._n) > dot(c10._n, c21._n))
        return edgeColumn(c10, c20);
      else
        return edgeColumn(c10, c21);
    }
    // fan on the left
    if(N1 == 2 || N2 == 1) {
      const BoundaryLayerData &c10 = getColumn(v1, 0);
      const BoundaryLayerData &c11 = getColumn(v1, 1);
      const BoundaryLayerData &c20 = getColumn(v2, 0);
      if(dot(c10._n, c20._n) > dot(c11._n, c20._n))
        return edgeColumn(c10, c20);
      else
        return edgeColumn(c11, c20);
    }

    // Msg::Error("Impossible Boundary Layer Configuration : "
    //             "one side and no fans %d %d", N1, N2);
    // FIXME WRONG
    return N1 ? edgeColumn(getColumn(v1, 0), getColumn(v1, 0)) :
                edgeColumn(getColumn(v2, 0), getColumn(v2, 0));
  }
  else if(nbSides == 2) {
    int i1 = 0, i2 = 1, j1 = 0, j2 = 1;
    if(it1 != _fans.end()) {
      i1 = aaa(it1->second._e1, e) ? 0 : N1 - 1;
      i2 = !aaa(it1->second._e1, e) ? 0 : N1 - 1;
    }
    if(it2 != _fans.end()) {
      j1 = aaa(it2->second._e1, e) ? 0 : N2 - 1;
      j2 = !aaa(it2->second._e1, e) ? 0 : N2 - 1;
    }
    const BoundaryLayerData &c10 = getColumn(v1, i1);
    const BoundaryLayerData &c11 = getColumn(v1, i2);
    const BoundaryLayerData &c20 = getColumn(v2, j1);
    const BoundaryLayerData &c21 = getColumn(v2, j2);

    if(side == 0) {
      if(dot(c10._n, c20._n) > dot(c10._n, c21._n))
        return edgeColumn(c10, c20);
      else
        return edgeColumn(c10, c21);
    }
    if(side == 1) {
      if(dot(c11._n, c20._n) > dot(c11._n, c21._n))
        return edgeColumn(c11, c20);
      else
        return edgeColumn(c11, c21);
    }
  }

  Msg::Error("Not yet Done in BoundaryLayerData nbSides = %d, ", nbSides);
  static BoundaryLayerData error;
  static edgeColumn error2(error, error);
  return error2;
}

static void treat2Connections(GFace *gf, MVertex *_myVert, MEdge &e1, MEdge &e2,
                              BoundaryLayerColumns *_columns,
                              std::vector<SVector3> &_dirs, bool fan,
                              int fanSize, int fanType)
{
  std::vector<SVector3> N1, N2;
  for(auto itm = _columns->_normals.lower_bound(e1);
      itm != _columns->_normals.upper_bound(e1); ++itm)
    N1.push_back(itm->second);
  for(auto itm = _columns->_normals.lower_bound(e2);
      itm != _columns->_normals.upper_bound(e2); ++itm)
    N2.push_back(itm->second);
  if(N1.size() == N2.size()) {
    for(std::size_t SIDE = 0; SIDE < N1.size(); SIDE++) {
      if(!fan) {
        SVector3 x = N1[SIDE] * 1.01 + N2[SIDE];
        x.normalize();
        // fix for #1054: the size should be divided by cos(theta/2) where
        // cos(theta) is dot(N1[SIDE], N2[SIDE])
        double d = fabs(dot(N1[SIDE], N2[SIDE]));
        if(d > 1.) d = 1.; // fix for #1450
        double ct2 = cos(acos(d) / 2);
        if(ct2) { // fix for #1450
          double fact = 1. / ct2;
          x *= fabs(fact);
        }
        _dirs.push_back(x);
      }
      else if(fan) {
        // if the angle is greater than PI, than reverse the sense
        double alpha1 = atan2(N1[SIDE].y(), N1[SIDE].x());
        double alpha2 = atan2(N2[SIDE].y(), N2[SIDE].x());
        double AMAX = std::max(alpha1, alpha2);
        double AMIN = std::min(alpha1, alpha2);
        MEdge ee[2];
        if(alpha1 > alpha2) {
          ee[0] = e2;
          ee[1] = e1;
        }
        else {
          ee[0] = e1;
          ee[1] = e2;
        }
        if(AMAX - AMIN >= M_PI) {
          double temp = AMAX;
          AMAX = AMIN + 2 * M_PI;
          AMIN = temp;
          MEdge eee0 = ee[0];
          ee[0] = ee[1];
          ee[1] = eee0;
        }

        int fanSize2 = 0;
        switch(fanType) {
        case 1:
        case 2:
        case 3: fanSize2 = fanSize - 1; break;
        default:
          double frac = fabs(AMAX - AMIN) / M_PI;
          int n = (int)(frac * fanSize + 0.5);
          fanSize2 = fan ? n : 0;
        }

        _columns->addFan(_myVert, ee[0], ee[1], true, fanType);
        for(int i = -1; i <= fanSize2; i++) {
          double t = (double)(i + 1) / (fanSize2 + 1);
          double alpha = t * AMAX + (1. - t) * AMIN;
          SVector3 x(cos(alpha), sin(alpha), 0);
          x.normalize();
          _dirs.push_back(x);
        }
      }
      /*
      else {
        _dirs.push_back(N1[SIDE]);
        _dirs.push_back(N2[SIDE]);
        }
      */
    }
  }
}

static void treat3Connections(GFace *gf, MVertex *_myVert, MEdge &e1, MEdge &e2,
                              MEdge &e3, BoundaryLayerColumns *_columns,
                              std::vector<SVector3> &_dirs)
{
  std::vector<SVector3> N1, N2, N3;
  for(auto itm = _columns->_normals.lower_bound(e1);
      itm != _columns->_normals.upper_bound(e1); ++itm)
    N1.push_back(itm->second);
  for(auto itm = _columns->_normals.lower_bound(e2);
      itm != _columns->_normals.upper_bound(e2); ++itm)
    N2.push_back(itm->second);
  for(auto itm = _columns->_normals.lower_bound(e3);
      itm != _columns->_normals.upper_bound(e3); ++itm)
    N3.push_back(itm->second);

  SVector3 x1, x2;
  if(N1.size() == 2) {}
  else if(N2.size() == 2) {
    std::vector<SVector3> temp = N1;
    N1.clear();
    N1 = N2;
    N2.clear();
    N2 = temp;
  }
  else if(N3.size() == 2) {
    std::vector<SVector3> temp = N1;
    N1.clear();
    N1 = N3;
    N3.clear();
    N3 = temp;
  }
  else {
    Msg::Error("Impossible boundary layer configuration");
  }
  if(dot(N1[0], N2[0]) > dot(N1[0], N3[0])) {
    x1 = N1[0] * 1.01 + N2[0];
    x2 = N1[1] * 1.01 + N3[0];
  }
  else {
    x1 = N1[1] * 1.01 + N2[0];
    x2 = N1[0] * 1.01 + N3[0];
  }
  x1.normalize();
  _dirs.push_back(x1);
  x2.normalize();
  _dirs.push_back(x2);
}

static bool isEdgeOfFaceBL(GFace *gf, GEdge *ge, BoundaryLayerField *blf)
{
  if(blf->isEdgeBL(ge->tag())) return true;
  /*
  std::list<GFace*> faces = ge->faces();
  for(auto it = faces.begin(); it != faces.end() ; ++it){
    if((*it) == gf)return false;
  }
  for(auto it = faces.begin(); it != faces.end() ; ++it){
    if(blf->isFaceBL((*it)->tag()))return true;
  }
  */
  return false;
}

static void getEdgesData(GFace *gf, BoundaryLayerField *blf,
                         BoundaryLayerColumns *_columns,
                         std::set<MVertex *> &_vertices,
                         std::set<MEdge, MEdgeLessThan> &allEdges,
                         std::multimap<MVertex *, MVertex *> &tangents)
{
  // get all model edges
  std::vector<GEdge *> edges = gf->edges();
  std::vector<GEdge *> const &embedded_edges = gf->embeddedEdges();
  edges.insert(edges.begin(), embedded_edges.begin(), embedded_edges.end());

  // iterate on model edges
  auto ite = edges.begin();
  while(ite != edges.end()) {
    // check if this edge generates a boundary layer
    if(isEdgeOfFaceBL(gf, *ite, blf)) {
      for(std::size_t i = 0; i < (*ite)->lines.size(); i++) {
        MVertex *v1 = (*ite)->lines[i]->getVertex(0);
        MVertex *v2 = (*ite)->lines[i]->getVertex(1);
        allEdges.insert(MEdge(v1, v2));
        _columns->_non_manifold_edges.insert(std::make_pair(v1, v2));
        _columns->_non_manifold_edges.insert(std::make_pair(v2, v1));
        _vertices.insert(v1);
        _vertices.insert(v2);
      }
    }
    else {
      MVertex *v1 = (*ite)->lines[0]->getVertex(0);
      MVertex *v2 = (*ite)->lines[0]->getVertex(1);
      MVertex *v3 = (*ite)->lines[(*ite)->lines.size() - 1]->getVertex(1);
      MVertex *v4 = (*ite)->lines[(*ite)->lines.size() - 1]->getVertex(0);
      tangents.insert(std::make_pair(v1, v2));
      tangents.insert(std::make_pair(v3, v4));
    }
    ++ite;
  }
}

static void getNormals(GFace *gf, BoundaryLayerField *blf,
                       BoundaryLayerColumns *_columns,
                       std::set<MEdge, MEdgeLessThan> &allEdges)
{
  // assume that the initial mesh has been created i.e. that there exist
  // triangles inside the domain. Triangles are used to define exterior normals
  for(std::size_t i = 0; i < gf->triangles.size(); i++) {
    SPoint2 p0, p1, p2;
    MVertex *v0 = gf->triangles[i]->getVertex(0);
    MVertex *v1 = gf->triangles[i]->getVertex(1);
    MVertex *v2 = gf->triangles[i]->getVertex(2);
    reparamMeshEdgeOnFace(v0, v1, gf, p0, p1);
    reparamMeshEdgeOnFace(v0, v2, gf, p0, p2);

    MEdge me01(v0, v1);
    if(allEdges.find(me01) != allEdges.end()) {
      SVector3 v01 = interiorNormal(p0, p1, p2);
      _columns->_normals.insert(std::make_pair(me01, v01));
    }

    MEdge me02(v0, v2);
    if(allEdges.find(me02) != allEdges.end()) {
      SVector3 v02 = interiorNormal(p0, p2, p1);
      _columns->_normals.insert(std::make_pair(me02, v02));
    }

    MEdge me21(v2, v1);
    if(allEdges.find(me21) != allEdges.end()) {
      SVector3 v21 = interiorNormal(p2, p1, p0);
      _columns->_normals.insert(std::make_pair(me21, v21));
    }
  }
}

static void addColumnAtTheEndOfTheBL(GEdge *ge, GVertex *gv,
                                     BoundaryLayerColumns *_columns,
                                     BoundaryLayerField *blf)
{
  if(!blf->isEdgeBL(ge->tag())) {
    std::vector<MVertex *> invert;
    for(std::size_t i = 0; i < ge->mesh_vertices.size(); i++)
      invert.push_back(ge->mesh_vertices[ge->mesh_vertices.size() - i - 1]);
    GVertex *g0 = ge->getBeginVertex();
    GVertex *g1 = ge->getEndVertex();
    if(g0 && g1) {
      MVertex *v0 = g0->mesh_vertices[0];
      MVertex *v1 = g1->mesh_vertices[0];
      SVector3 t(v1->x() - v0->x(), v1->y() - v0->y(), v1->z() - v0->z());
      t.normalize();
      if(g0 == gv)
        _columns->addColumn(t, v0, ge->mesh_vertices);
      else if(g1 == gv)
        _columns->addColumn(t * -1.0, v1, invert);
    }
  }
}

void getLocalInfoAtNode(MVertex *v, BoundaryLayerField *blf, double &hWall)
{
  hWall = blf->hWallN;
  if(v->onWhat()->dim() == 0) { hWall = blf->hWall(v->onWhat()->tag()); }
  else if(v->onWhat()->dim() == 1) {
    GEdge *ge = (GEdge *)v->onWhat();
    Range<double> bounds = ge->parBounds(0);
    double t_begin = bounds.low();
    double t_end = bounds.high();
    double t;
    v->getParameter(0, t);
    if(ge->getBeginVertex() && ge->getEndVertex()) {
      double hWall_beg = blf->hWall(ge->getBeginVertex()->tag());
      double hWall_end = blf->hWall(ge->getEndVertex()->tag());
      double x = (t - t_begin) / (t_end - t_begin);
      double hWallLin = hWall_beg + x * (hWall_end - hWall_beg);
      double hWall_mid = std::min(hWall_beg, hWall_end);
      double hWallQuad = hWall_beg * (1 - x) * (1 - x) +
                         hWall_mid * 2 * x * (1 - x) + hWall_end * x * x;
      // we prefer a quadratic growing:
      hWall = 0 * hWallLin + 1 * hWallQuad;
    }
  }
}

bool buildAdditionalPoints2D(GFace *gf)
{
  BoundaryLayerColumns *_columns = gf->getColumns();
  _columns->clearData();

  FieldManager *fields = gf->model()->getFields();
  int nBL = fields->getNumBoundaryLayerFields();
  if(nBL == 0) return false;

  // Note: boundary layers must be separate (must not touch each other)
  bool addedAdditionalPoints = false;
  for(int i = 0; i < nBL; ++i) {
    // GET THE FIELD THAT DEFINES THE DISTANCE FUNCTION
    Field *bl_field = fields->get(fields->getBoundaryLayerField(i));
    if(bl_field == nullptr) continue;
    BoundaryLayerField *blf = dynamic_cast<BoundaryLayerField *>(bl_field);

    if(!blf || !blf->setupFor2d(gf->tag())) continue;

    std::set<MVertex *> _vertices;
    std::set<MEdge, MEdgeLessThan> allEdges;
    std::multimap<MVertex *, MVertex *> tangents;

    getEdgesData(gf, blf, _columns, _vertices, allEdges, tangents);

    if(!_vertices.size()) continue;

    getNormals(gf, blf, _columns, allEdges);

    // for all boundry points
    for(auto it = _vertices.begin(); it != _vertices.end(); ++it) {
      bool endOfTheBL = false;
      SVector3 dirEndOfBL;
      std::vector<MVertex *> columnEndOfBL;
      std::vector<MVertex *> _connections;
      std::vector<SVector3> _dirs;
      // get all vertices that are connected to that vertex among all boundary
      // layer vertices !

      bool fan =
        (*it)->onWhat()->dim() == 0 && blf->isFanNode((*it)->onWhat()->tag());
      int fanSize = fan ? blf->fanSize((*it)->onWhat()->tag()) : 0;

      int fanType = 0; // no fan
      if(fan) {
        int t = blf->fanSize((*it)->onWhat()->tag());
        switch(t) {
        case -1:
          fanType = 1; // cross
          break;
        case -2:
          fanType = 2; // mix
          break;
        case -3:
          fanType = 3; // tail
          break;
        case -4:
          fanType = 4; // skip
          fanSize = 0;
          break;
        default:
          if(t < 0) { // auto
            fanType = 4;
            fanSize = 0;
          }
          else {
            fanType = -1; // fan
          }
        }
      }

      if(fanType == -1 || fanType == 0 || fanType == 4) { // fan, nofan, skip

        for(auto itm = _columns->_non_manifold_edges.lower_bound(*it);
            itm != _columns->_non_manifold_edges.upper_bound(*it); ++itm)
          _connections.push_back(itm->second);

        // A trailing edge topology : 3 edges incident to a vertex
        if(_connections.size() == 3) {
          MEdge e1(*it, _connections[0]);
          MEdge e2(*it, _connections[1]);
          MEdge e3(*it, _connections[2]);
          treat3Connections(gf, *it, e1, e2, e3, _columns, _dirs);
        }
        // STANDARD CASE, one vertex connected to two neighboring vertices
        else if(_connections.size() == 2) {
          MEdge e1(*it, _connections[0]);
          MEdge e2(*it, _connections[1]);
          treat2Connections(gf, *it, e1, e2, _columns, _dirs, fan, fanSize,
                            fanType);
        }
        else if(_connections.size() == 1) {
          MEdge e1(*it, _connections[0]);
          std::vector<SVector3> N1;
          for(auto itm = _columns->_normals.lower_bound(e1);
              itm != _columns->_normals.upper_bound(e1); ++itm)
            N1.push_back(itm->second);
          // one point has only one side and one normal : it has to be at the
          // end of the BL then, we have the tangent to the connecting edge

          //          *it          _connections[0]
          // --------- + -----------
          //   NO BL          BL

          if(N1.size() == 1) {
            std::vector<MVertex *> Ts;
            for(auto itm = tangents.lower_bound(*it);
                itm != tangents.upper_bound(*it); ++itm)
              Ts.push_back(itm->second);
            // end of the BL --> let's add a column that correspond to the
            // model edge that lies after the end of teh BL
            if(Ts.size() == 1) {
              GEdge *ge = dynamic_cast<GEdge *>(Ts[0]->onWhat());
              GVertex *gv = dynamic_cast<GVertex *>((*it)->onWhat());
              if(ge && gv) { addColumnAtTheEndOfTheBL(ge, gv, _columns, blf); }
            }
            else {
              Msg::Error(
                "Impossible BL Configuration -- One Edge -- Tscp.size() = %d",
                Ts.size());
            }
          }
          else if(N1.size() == 2) {
            SPoint2 p0, p1;
            reparamMeshEdgeOnFace(_connections[0], *it, gf, p0, p1);
            double alpha1 = atan2(N1[0].y(), N1[0].x());
            double alpha2 = atan2(N1[1].y(), N1[1].x());
            double alpha3 = atan2(p1.y() - p0.y(), p1.x() - p0.x());
            double AMAX = std::max(alpha1, alpha2);
            double AMIN = std::min(alpha1, alpha2);
            if(alpha3 > AMAX) {
              double temp = AMAX;
              AMAX = AMIN + 2 * M_PI;
              AMIN = temp;
            }
            if(alpha3 < AMIN) {
              double temp = AMIN;
              AMIN = AMAX - 2 * M_PI;
              AMAX = temp;
            }
            double frac = fabs(AMAX - AMIN) / M_PI;
            int n = (int)(frac * fanSize + 0.5);
            int fanSize2 = fan ? n : 0;
            if(fan) _columns->addFan(*it, e1, e1, true, fanType);
            for(int i = -1; i <= fanSize2; i++) {
              double t = (double)(i + 1) / (fanSize2 + 1);
              double alpha = t * AMAX + (1. - t) * AMIN;
              SVector3 x(cos(alpha), sin(alpha), 0);
              x.normalize();
              _dirs.push_back(x);
            }
          }
        }

        // if(_dirs.size() > 1) printf("%d directions\n",_dirs.size());

        // now create the BL points
        for(std::size_t DIR = 0; DIR < _dirs.size(); DIR++) {
          SVector3 n = _dirs[DIR];

          // < ------------------------------- > //
          //   N = X(p0+ e n) - X(p0)            //
          //     = e * (dX/du n_u + dX/dv n_v)   //
          // < ------------------------------- > //

          if(endOfTheBL && dot(n, dirEndOfBL) > 0.99) {
            // end
          }
          else if(blf->betaLaw) {
            MVertex *first = *it;
            double hWall;
            getLocalInfoAtNode(first, blf, hWall);
            std::vector<MVertex *> _column;
            SPoint2 par =
              gf->parFromPoint(SPoint3(first->x(), first->y(), first->z()));
            std::vector<double> t(blf->nb_divisions);

            double zlog = log((1 + blf->beta) / (blf->beta - 1));
            // printf("T = ");
            for(int i = 0; i < blf->nb_divisions; i++) {
              const double eta = (double)(i + 1) / blf->nb_divisions;
              const double power = exp(zlog * (1. - eta));
              const double ratio = (1. - power) / (1. + power);
              t[i] = 1.0 + blf->beta * ratio;
              // printf("%12.5E ", t[i]);
            }
            // printf("\n");
            for(int i = 0; i < blf->nb_divisions; i++) {
              double L = hWall * t[i] / t[0];
              SPoint2 pnew(par.x() + L * n.x(), par.y() + L * n.y());
              GPoint pp = gf->point(pnew);
              MFaceVertex *_current =
                new MFaceVertex(pp.x(), pp.y(), pp.z(), gf, pnew.x(), pnew.y());
              _current->bl_data = new MVertexBoundaryLayerData;
              _column.push_back(_current);
            }
            _columns->addColumn(n, *it, _column /*,_metrics*/);
          }
          else {
            MVertex *first = *it;
            double hWall;
            getLocalInfoAtNode(first, blf, hWall);
            std::vector<MVertex *> _column;
            SPoint2 par =
              gf->parFromPoint(SPoint3(first->x(), first->y(), first->z()));
            double L = hWall;
            while(1) {
              // printf("L = %g\n",L);
              if(L > blf->thickness) break;
              SPoint2 pnew(par.x() + L * n.x(), par.y() + L * n.y());
              GPoint pp = gf->point(pnew);
              MFaceVertex *_current =
                new MFaceVertex(pp.x(), pp.y(), pp.z(), gf, pnew.x(), pnew.y());
              _current->bl_data = new MVertexBoundaryLayerData;
              _column.push_back(_current);
              int ith = _column.size();
              // ADD BETA LAW HERE !!!
              L += hWall * pow(blf->ratio, ith);
            }
            _columns->addColumn(n, *it, _column /*,_metrics*/);
          }
        }
      }
      else { // cross, mix, tail

        // calculate a number of layers in the BL and layers depth
        std::vector<double> bl_depth;
        MVertex *first = *it;
        int nlayers = 0;
        double hWall;
        getLocalInfoAtNode(first, blf, hWall);

        SPoint2 par =
          gf->parFromPoint(SPoint3(first->x(), first->y(), first->z()));
        double x0 = par.x();
        double y0 = par.y();

        if(blf->betaLaw) {
          SPoint2 par =
            gf->parFromPoint(SPoint3(first->x(), first->y(), first->z()));
          std::vector<double> t(blf->nb_divisions);
          double zlog = log((1 + blf->beta) / (blf->beta - 1));
          for(int i = 0; i < blf->nb_divisions; i++) {
            const double eta = (double)(i + 1) / blf->nb_divisions;
            const double power = exp(zlog * (1.0 - eta));
            const double ratio = (1.0 - power) / (1.0 + power);
            t[i] = 1.0 + blf->beta * ratio;
          }

          for(int i = 0; i < blf->nb_divisions; i++) {
            double L = hWall * t[i] / t[0];
            bl_depth.push_back(L);
          }
        }
        else {
          double L = hWall;
          while(1) {
            if(L > blf->thickness) break;
            bl_depth.push_back(L);
            int ith = bl_depth.size();
            L += hWall * pow(blf->ratio, ith);
          }
        }
        nlayers = bl_depth.size() + 1;

        for(auto itm = _columns->_non_manifold_edges.lower_bound(*it);
            itm != _columns->_non_manifold_edges.upper_bound(*it); ++itm)
          _connections.push_back(itm->second);

        // A trailing edge topology : 3 edges incident to a vertex
        if(_connections.size() == 3) {
          MEdge e1(*it, _connections[0]);
          MEdge e2(*it, _connections[1]);
          MEdge e3(*it, _connections[2]);
          treat3Connections(gf, *it, e1, e2, e3, _columns, _dirs);
        }
        // STANDARD CASE, one vertex connected to two neighboring vertices
        else if(_connections.size() == 2) {
          MEdge e1(*it, _connections[0]);
          MEdge e2(*it, _connections[1]);
          if(fanType < 3) { fanSize = nlayers; }
          else {
            fanSize = 2 * nlayers;
          }
          treat2Connections(gf, *it, e1, e2, _columns, _dirs, fan, fanSize,
                            fanType);
        }
        else if(_connections.size() == 1) {
          MEdge e1(*it, _connections[0]);
          std::vector<SVector3> N1;
          for(auto itm = _columns->_normals.lower_bound(e1);
              itm != _columns->_normals.upper_bound(e1); ++itm)
            N1.push_back(itm->second);
          // one point has only one side and one normal : it has to be at the
          // end of the BL then, we have the tangent to the connecting edge

          //          *it          _connections[0]
          // --------- + -----------
          //   NO BL          BL

          if(N1.size() == 1) {
            std::vector<MVertex *> Ts;
            for(auto itm = tangents.lower_bound(*it);
                itm != tangents.upper_bound(*it); ++itm)
              Ts.push_back(itm->second);
            // end of the BL --> let's add a column that correspond to the
            // model edge that lies after the end of teh BL
            if(Ts.size() == 1) {
              GEdge *ge = dynamic_cast<GEdge *>(Ts[0]->onWhat());
              GVertex *gv = dynamic_cast<GVertex *>((*it)->onWhat());
              if(ge && gv) { addColumnAtTheEndOfTheBL(ge, gv, _columns, blf); }
            }
            else {
              Msg::Error(
                "Impossible BL Configuration -- One Edge -- Tscp.size() = %d",
                Ts.size());
            }
          }
          else if(N1.size() == 2) {
            SPoint2 p0, p1;
            reparamMeshEdgeOnFace(_connections[0], *it, gf, p0, p1);
            double alpha1 = atan2(N1[0].y(), N1[0].x());
            double alpha2 = atan2(N1[1].y(), N1[1].x());
            double alpha3 = atan2(p1.y() - p0.y(), p1.x() - p0.x());
            double AMAX = std::max(alpha1, alpha2);
            double AMIN = std::min(alpha1, alpha2);
            if(alpha3 > AMAX) {
              double temp = AMAX;
              AMAX = AMIN + 2 * M_PI;
              AMIN = temp;
            }
            if(alpha3 < AMIN) {
              double temp = AMIN;
              AMIN = AMAX - 2.0 * M_PI;
              AMAX = temp;
            }

            int fanSize2 = fan ? nlayers : 0;
            if(fan) _columns->addFan(*it, e1, e1, true, fanType);
            for(int i = -1; i <= fanSize2; i++) {
              double t = (double)(i + 1) / (fanSize2 + 1);
              double alpha = t * AMAX + (1.0 - t) * AMIN;
              SVector3 x(cos(alpha), sin(alpha), 0.0);
              x.normalize();
              _dirs.push_back(x);
            }
          }
        }

        // now create the BL points
        SVector3 n1 = _dirs.front();
        SVector3 n2 = _dirs.back();
        double h = bl_depth[bl_depth.size() - 1];
        double x1 = x0 + h * n1.x();
        double y1 = y0 + h * n1.y();
        double x2 = x0 + h * n2.x();
        double y2 = y0 + h * n2.y();
        double D = n1.y() * n2.x() - n1.x() * n2.y();
        double Dt = -(x2 - x1) * n2.x() - (y2 - y1) * n2.y();
        double t = Dt / D;
        double x3 = x1 - t * n1.y();
        double y3 = y1 + t * n1.x();

        switch(fanType) {
        case 1: // cross

          for(std::size_t DIR = 0; DIR < _dirs.size(); DIR++) {
            SVector3 n = _dirs[DIR];
            std::vector<MVertex *> _column;

            if(endOfTheBL && dot(n, dirEndOfBL) > 0.99) {
              // end
            }
            else {
              for(std::size_t layer = 0; layer < bl_depth.size(); layer++) {
                double x, y;
                if(DIR == 0 || DIR == _dirs.size() - 1) {
                  double L = bl_depth[layer];
                  x = x0 + L * n.x();
                  y = y0 + L * n.y();
                }
                else {
                  // x = x0 + bl_depth[layer] * n1.x() +
                  // bl_depth[DIR - 1] * n2.x(); y = y0 +
                  // bl_depth[layer] * n1.y() + bl_depth[DIR - 1] * n2.y();

                  double s = bl_depth[layer] / h;
                  double t = bl_depth[DIR - 1] / h;
                  double xs = x0 + s * (x1 - x0);
                  double ys = y0 + s * (y1 - y0);
                  double xf = x2 + s * (x3 - x2);
                  double yf = y2 + s * (y3 - y2);
                  x = xs + t * (xf - xs);
                  y = ys + t * (yf - ys);
                }

                SPoint2 pnew(x, y);
                GPoint pp = gf->point(pnew);
                MFaceVertex *_current = new MFaceVertex(pp.x(), pp.y(), pp.z(),
                                                        gf, pnew.x(), pnew.y());

                _current->bl_data = new MVertexBoundaryLayerData;
                _column.push_back(_current);
              }
              _columns->addColumn(n, *it, _column /*, _metrics */);
            }
          }

          break;

        case 2: // mix

          for(std::size_t DIR = 0; DIR < _dirs.size(); DIR++) {
            SVector3 n = _dirs[DIR];
            std::vector<MVertex *> _column;

            if(endOfTheBL && dot(n, dirEndOfBL) > 0.99) {
              // end
            }
            else {
              for(std::size_t layer = 0; layer < bl_depth.size(); layer++) {
                double dx, dy, x, y;
                if(DIR == 0 || DIR == _dirs.size() - 1) {
                  double L = bl_depth[layer];
                  x = x0 + L * n.x();
                  y = y0 + L * n.y();
                }
                else {
                  int dc = (_dirs.size() - 1) / 2;
                  int lc = dc - 1;
                  double s, t, xs, ys, xf, yf;

                  if((int)DIR == dc && (int)layer > lc) {
                    double d = bl_depth[layer];
                    double rc = bl_depth[DIR - 1];
                    double r = d - rc;
                    dx = rc + r / sqrt(2.0);
                    dy = dx;
                  }
                  else if((int)DIR < dc && (int)layer > lc) {
                    double d = bl_depth[layer];
                    double rc = bl_depth[dc - 1];
                    double r = d - rc;
                    double dL = M_PI * r / 4.0;
                    double L = rc + dL;
                    double t_star = rc / L;
                    double t = bl_depth[DIR - 1] / rc;

                    if(t <= t_star) {
                      dx = d;
                      dy = L * t;
                    }
                    else {
                      double len = L * (t - t_star);
                      double angle = len / dL * M_PI / 4.0;
                      dx = rc + r * cos(angle);
                      dy = rc + r * sin(angle);
                    }
                  }
                  else if((int)DIR > dc && (int)layer < lc) {
                    double d = bl_depth[DIR - 1];
                    double rc = bl_depth[dc - 1];
                    double r = d - rc;
                    double dL = M_PI * r / 4.0;
                    double L = rc + dL;
                    double t_star = rc / L;
                    double t = bl_depth[layer] / rc;

                    if(t <= t_star) {
                      dx = L * t;
                      dy = d;
                    }
                    else {
                      double len = L * (t - t_star);
                      double angle = len / dL * M_PI / 4.0;
                      dx = rc + r * sin(angle);
                      dy = rc + r * cos(angle);
                    }
                  }
                  else {
                    dx = bl_depth[layer];
                    dy = bl_depth[DIR - 1];
                  }
                  // x = x0 + dx * n1.x() + dy * n2.x();
                  // y = y0 + dx * n1.y() + dy * n2.y();
                  s = dx / h;
                  t = dy / h;
                  xs = x0 + s * (x1 - x0);
                  ys = y0 + s * (y1 - y0);
                  xf = x2 + s * (x3 - x2);
                  yf = y2 + s * (y3 - y2);
                  x = xs + t * (xf - xs);
                  y = ys + t * (yf - ys);
                }

                SPoint2 pnew(x, y);
                GPoint pp = gf->point(pnew);
                MFaceVertex *_current = new MFaceVertex(pp.x(), pp.y(), pp.z(),
                                                        gf, pnew.x(), pnew.y());

                _current->bl_data = new MVertexBoundaryLayerData;
                _column.push_back(_current);
              }
              _columns->addColumn(n, *it, _column /*, _metrics */);
            }
          }

          break;

        case 3: // tail

          double L = bl_depth.back();
          const double eps = 1e-16;
          double step = 0.0;
          int count = 0;
          for(auto it = allEdges.begin(); it != allEdges.end(); ++it) {
            auto v1 = it->getVertex(0);
            auto v2 = it->getVertex(1);
            SPoint2 par1 = gf->parFromPoint(SPoint3(v1->x(), v1->y(), v1->z()));
            SPoint2 par2 = gf->parFromPoint(SPoint3(v2->x(), v2->y(), v2->z()));
            double dx1 = par1.x() - x0;
            double dy1 = par1.y() - y0;
            double dx2 = par2.x() - x0;
            double dy2 = par2.y() - y0;
            if(dx1 * dx1 + dy1 * dy1 < eps || dx2 * dx2 + dy2 * dy2 < eps) {
              step += it->length();
              count++;
            }
          }
          if(count) { step /= count; }
          else {
            Msg::Warning("vertice not found in bl");
          }

          SPoint2 p1(x0 + L * n1.x(), par.y() + L * n1.y());
          SPoint2 p2(x0 + L * n2.x(), par.y() + L * n2.y());
          SPoint2 pc(x0, par.y());

          SVector3 nc = n1 + n2;
          nc.normalize();

          SPoint2 t1(x0 + L * (n1.x() + nc.x()), y0 + L * (n1.y() + nc.y()));
          SPoint2 t2(x0 + L * (n2.x() + nc.x()), y0 + L * (n2.y() + nc.y()));
          SPoint2 tc =
            SPoint2(0.5 * (t1.x() + t2.x()), 0.5 * (t1.y() + t2.y()));

          const std::size_t dir_half = _dirs.size() / 2;

          for(std::size_t DIR = 0; DIR < _dirs.size(); DIR++) {
            SVector3 n = _dirs[DIR];
            std::vector<MVertex *> _column;

            if(DIR == 0 || DIR == _dirs.size() - 1)
              nlayers = bl_depth.size();
            else
              nlayers = L / step + 1;

            for(int layer = 0; layer < nlayers; layer++) {
              double x, y;

              if(DIR == 0 || DIR == _dirs.size() - 1) {
                double l = bl_depth[layer];

                if(DIR == 0) {
                  x = x0 + l * n1.x();
                  y = y0 + l * n1.y();
                }
                else {
                  x = x0 + l * n2.x();
                  y = y0 + l * n2.y();
                }
              }
              else {
                double ll = step * (layer + 1);
                if(DIR < dir_half) {
                  double l = bl_depth[dir_half - DIR - 1];
                  x = x0 + l * n1.x() + ll * nc.x();
                  y = y0 + l * n1.y() + ll * nc.y();
                }
                else if(DIR == dir_half) {
                  x = x0 + ll * nc.x();
                  y = y0 + ll * nc.y();
                }
                else { // DIR > dir_half
                  double l = bl_depth[DIR - dir_half - 1];
                  x = x0 + l * n2.x() + ll * nc.x();
                  y = y0 + l * n2.y() + ll * nc.y();
                }
              }

              SPoint2 pnew(x, y);
              GPoint pp = GPoint(gf->point(pnew));
              MFaceVertex *_current =
                new MFaceVertex(pp.x(), pp.y(), pp.z(), gf, pnew.x(), pnew.y());

              _current->bl_data = new MVertexBoundaryLayerData;
              _column.push_back(_current);
            }
            _columns->addColumn(n, *it, _column /*, _metrics */);
          }

          break;
        }
      }
    }

    addedAdditionalPoints = true;
  }

#if 0 // DEBUG STUFF
  char name[256];
  sprintf(name, "points_face_%d.pos", gf->tag());
  FILE *f = Fopen(name,"w");
  if(f){
    fprintf(f,"View \"\" {\n");
    for(auto it = _vertices.begin(); it != _vertices.end() ; ++it){
      MVertex *v = *it;
      for(int i = 0; i < _columns->getNbColumns(v); i++){
        const BoundaryLayerData &data = _columns->getColumn(v, i);
        for(std::size_t j = 0; j < data._column.size(); j++){
          MVertex *blv = data._column[j];
          fprintf(f, "SP(%g,%g,%g){%d};\n", blv->x(), blv->y(), blv->z(),
                  v->getNum());
        }
      }
    }
    fprintf(f, "};\n");
    fclose(f);
  }
#endif

  return addedAdditionalPoints;
}

#endif
