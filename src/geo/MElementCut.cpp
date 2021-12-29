// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Gaetan Bricteux

#include <stdlib.h>
#include <sstream>
#include "GmshConfig.h"
#include "GModel.h"
#include "MElement.h"
#include "MElementCut.h"
#include "gmshLevelset.h"
#include "MQuadrangle.h"

#if defined(HAVE_DINTEGRATION)
#include "Integration3D.h"
#endif

//---------------------------------------- MPolyhedron
//----------------------------

void MPolyhedron::_init()
{
  if(_parts.size() == 0) return;

  for(std::size_t i = 0; i < _parts.size(); i++) {
    if(_parts[i]->getVolume() * _parts[0]->getVolume() < 0.)
      _parts[i]->reverse();
    for(int j = 0; j < 4; j++) {
      int k;
      for(k = _faces.size() - 1; k >= 0; k--)
        if(_parts[i]->getFace(j) == _faces[k]) break;
      if(k < 0)
        _faces.push_back(_parts[i]->getFace(j));
      else
        _faces.erase(_faces.begin() + k);
    }
    if(_parts.size() < 4) { // No interior vertex
      for(int j = 0; j < 6; j++) {
        int k;
        for(k = _edges.size() - 1; k >= 0; k--)
          if(_parts[i]->getEdge(j) == _edges[k]) break;
        if(k < 0) _edges.push_back(_parts[i]->getEdge(j));
      }
      for(int j = 0; j < 4; j++) {
        int k;
        for(k = _vertices.size() - 1; k >= 0; k--)
          if(_parts[i]->getVertex(j) == _vertices[k]) break;
        if(k < 0) _vertices.push_back(_parts[i]->getVertex(j));
      }
    }
  }

  if(_parts.size() >= 4) {
    for(std::size_t i = 0; i < _faces.size(); i++) {
      for(int j = 0; j < 3; j++) {
        int k;
        for(k = _edges.size() - 1; k >= 0; k--)
          if(_faces[i].getEdge(j) == _edges[k]) break;
        if(k < 0) _edges.push_back(_faces[i].getEdge(j));
      }
      for(int j = 0; j < 3; j++) {
        int k;
        for(k = _vertices.size() - 1; k >= 0; k--)
          if(_faces[i].getVertex(j) == _vertices[k]) break;
        if(k < 0) _vertices.push_back(_faces[i].getVertex(j));
      }
    }
  }

  // innerVertices
  for(std::size_t i = 0; i < _parts.size(); i++) {
    for(int j = 0; j < 4; j++) {
      if(std::find(_vertices.begin(), _vertices.end(),
                   _parts[i]->getVertex(j)) == _vertices.end())
        _innerVertices.push_back(_parts[i]->getVertex(j));
    }
  }
}

bool MPolyhedron::isInside(double u, double v, double w) const
{
  if(!_orig) return false;
  double uvw[3] = {u, v, w};
  for(std::size_t i = 0; i < _parts.size(); i++) {
    double verts[4][3];
    for(int j = 0; j < 4; j++) {
      MVertex *vij = _parts[i]->getVertex(j);
      double v_xyz[3] = {vij->x(), vij->y(), vij->z()};
      _orig->xyz2uvw(v_xyz, verts[j]);
    }
    MVertex v0(verts[0][0], verts[0][1], verts[0][2]);
    MVertex v1(verts[1][0], verts[1][1], verts[1][2]);
    MVertex v2(verts[2][0], verts[2][1], verts[2][2]);
    MVertex v3(verts[3][0], verts[3][1], verts[3][2]);
    MTetrahedron t(&v0, &v1, &v2, &v3);
    double ksi[3];
    t.xyz2uvw(uvw, ksi);
    if(t.isInside(ksi[0], ksi[1], ksi[2])) return true;
  }
  return false;
}

void MPolyhedron::getIntegrationPoints(int pOrder, int *npts, IntPt **pts)
{
  *npts = 0;
  if(_intpt) delete[] _intpt;
  if(!_orig) return;
  double jac[3][3];
  _intpt = new IntPt[getNGQTetPts(pOrder) * _parts.size()];
  for(std::size_t i = 0; i < _parts.size(); i++) {
    int nptsi;
    IntPt *ptsi;
    _parts[i]->getIntegrationPoints(pOrder, &nptsi, &ptsi);
    double uvw[4][3];
    for(int j = 0; j < 4; j++) {
      double xyz[3] = {_parts[i]->getVertex(j)->x(),
                       _parts[i]->getVertex(j)->y(),
                       _parts[i]->getVertex(j)->z()};
      _orig->xyz2uvw(xyz, uvw[j]);
    }
    MVertex v0(uvw[0][0], uvw[0][1], uvw[0][2]);
    MVertex v1(uvw[1][0], uvw[1][1], uvw[1][2]);
    MVertex v2(uvw[2][0], uvw[2][1], uvw[2][2]);
    MVertex v3(uvw[3][0], uvw[3][1], uvw[3][2]);
    MTetrahedron tt(&v0, &v1, &v2, &v3);

    for(int ip = 0; ip < nptsi; ip++) {
      const double u = ptsi[ip].pt[0];
      const double v = ptsi[ip].pt[1];
      const double w = ptsi[ip].pt[2];
      SPoint3 p;
      tt.pnt(u, v, w, p);
      _intpt[*npts + ip].pt[0] = p.x();
      _intpt[*npts + ip].pt[1] = p.y();
      _intpt[*npts + ip].pt[2] = p.z();
      double partJac = _parts[i]->getJacobian(p.x(), p.y(), p.z(), jac);
      double Jac = getJacobian(p.x(), p.y(), p.z(), jac);
      _intpt[*npts + ip].weight = ptsi[ip].weight * partJac / Jac;
    }
    *npts += nptsi;
  }
  *pts = _intpt;
}

//------------------------------------------- MPolygon
//------------------------------

void MPolygon::_initVertices()
{
  if(_parts.size() == 0) return;

  // reorient the parts
  SVector3 n;
  if(_orig)
    n = _orig->getFace(0).normal();
  else
    n = _parts[0]->getFace(0).normal();
  for(std::size_t i = 0; i < _parts.size(); i++) {
    SVector3 ni = _parts[i]->getFace(0).normal();
    if(dot(n, ni) < 0.) _parts[i]->reverse();
  }
  // select only outer edges in vector edg
  std::vector<MEdge> edg;
  std::vector<MEdge> multiEdges;
  edg.reserve(_parts[0]->getNumEdges());
  for(int j = 0; j < _parts[0]->getNumEdges(); j++)
    edg.push_back(_parts[0]->getEdge(j));
  for(std::size_t i = 1; i < _parts.size(); i++) {
    for(int j = 0; j < _parts[i]->getNumEdges(); j++) {
      bool found = false;
      MEdge ed = _parts[i]->getEdge(j);
      int k;
      for(k = edg.size() - 1; k >= 0; k--) {
        if(ed == edg[k]) {
          edg.erase(edg.begin() + k);
          found = true;
          break;
        }
      }
      if(!found) {
        for(k = 0; k < (int)multiEdges.size(); k++)
          if(multiEdges[k].isInside(ed.getVertex(0)) &&
             multiEdges[k].isInside(ed.getVertex(1))) {
            found = true;
            break;
          }
      }
      if(!found) {
        for(k = edg.size() - 1; k >= 0; k--) {
          if(edg[k].isInside(ed.getVertex(0)) &&
             edg[k].isInside(ed.getVertex(1))) {
            multiEdges.push_back(edg[k]);
            edg.erase(edg.begin() + k);
            found = true;
            break;
          }
        }
      }
      if(!found) {
        for(k = edg.size() - 1; k >= 0; k--) {
          if(ed.isInside(edg[k].getVertex(0)) &&
             ed.isInside(edg[k].getVertex(1))) {
            edg.erase(edg.begin() + k);
            int nbME = multiEdges.size();
            if(nbME == 0 || multiEdges[nbME - 1] != ed)
              multiEdges.push_back(ed);
            found = true;
          }
        }
      }
      if(!found) edg.push_back(ed);
    }
  }

  // organize edges to get vertices in rotating order
  _edges.push_back(edg[0]);
  edg.erase(edg.begin());
  while(edg.size()) {
    MVertex *v = _edges[_edges.size() - 1].getVertex(1);
    for(std::size_t i = 0; i < edg.size(); i++) {
      if(edg[i].getVertex(0) == v) {
        _edges.push_back(edg[i]);
        edg.erase(edg.begin() + i);
        break;
      }
      if(edg[i].getVertex(1) == v) {
        _edges.push_back(MEdge(edg[i].getVertex(1), edg[i].getVertex(0)));
        edg.erase(edg.begin() + i);
        break;
      }
      if(i == edg.size() - 1) {
        _edges.push_back(edg[0]);
        edg.erase(edg.begin());
        break;
      }
    }
  }

  for(std::size_t i = 0; i < _edges.size(); i++) {
    _vertices.push_back(_edges[i].getVertex(0));
  }

  // innerVertices
  for(std::size_t i = 0; i < _parts.size(); i++) {
    for(int j = 0; j < 3; j++) {
      if(std::find(_vertices.begin(), _vertices.end(),
                   _parts[i]->getVertex(j)) == _vertices.end())
        _innerVertices.push_back(_parts[i]->getVertex(j));
    }
  }
}

bool MPolygon::isInside(double u, double v, double w) const
{
  if(!getParent()) return false;
  double uvw[3] = {u, v, w};
  for(std::size_t i = 0; i < _parts.size(); i++) {
    double v_uvw[3][3];
    for(int j = 0; j < 3; j++) {
      MVertex *vij = _parts[i]->getVertex(j);
      double v_xyz[3] = {vij->x(), vij->y(), vij->z()};
      getParent()->xyz2uvw(v_xyz, v_uvw[j]);
    }
    MVertex v0(v_uvw[0][0], v_uvw[0][1], v_uvw[0][2]);
    MVertex v1(v_uvw[1][0], v_uvw[1][1], v_uvw[1][2]);
    MVertex v2(v_uvw[2][0], v_uvw[2][1], v_uvw[2][2]);
    MTriangle t(&v0, &v1, &v2);
    double ksi[3];
    t.xyz2uvw(uvw, ksi);
    if(t.isInside(ksi[0], ksi[1], ksi[2])) return true;
  }
  return false;
}

void MPolygon::getIntegrationPoints(int pOrder, int *npts, IntPt **pts)
{
  *npts = 0;
  if(_intpt) delete[] _intpt;
  if(!getParent()) return;
  double jac[3][3];
  _intpt = new IntPt[getNGQTPts(pOrder) * _parts.size()];
  for(std::size_t i = 0; i < _parts.size(); i++) {
    int nptsi;
    IntPt *ptsi;
    _parts[i]->getIntegrationPoints(pOrder, &nptsi, &ptsi);
    double uvw[3][3];
    for(int j = 0; j < 3; j++) {
      double xyz[3] = {_parts[i]->getVertex(j)->x(),
                       _parts[i]->getVertex(j)->y(),
                       _parts[i]->getVertex(j)->z()};
      getParent()->xyz2uvw(xyz, uvw[j]);
    }
    MVertex v0(uvw[0][0], uvw[0][1], uvw[0][2]);
    MVertex v1(uvw[1][0], uvw[1][1], uvw[1][2]);
    MVertex v2(uvw[2][0], uvw[2][1], uvw[2][2]);
    MTriangle tt(&v0, &v1, &v2);
    for(int ip = 0; ip < nptsi; ip++) {
      const double u = ptsi[ip].pt[0];
      const double v = ptsi[ip].pt[1];
      const double w = ptsi[ip].pt[2];
      SPoint3 p;
      tt.pnt(u, v, w, p);
      _intpt[*npts + ip].pt[0] = p.x();
      _intpt[*npts + ip].pt[1] = p.y();
      _intpt[*npts + ip].pt[2] = p.z();
      double partJac = _parts[i]->getJacobian(p.x(), p.y(), p.z(), jac);
      double Jac = getJacobian(p.x(), p.y(), p.z(), jac);
      _intpt[*npts + ip].weight = ptsi[ip].weight * partJac / Jac;
    }
    *npts += nptsi;
  }
  *pts = _intpt;
}

//----------------------------------- MLineChild ------------------------------

bool MLineChild::isInside(double u, double v, double w) const
{
  if(!_orig) return false;
  double uvw[3] = {u, v, w};
  double v_uvw[2][3];
  for(int i = 0; i < 2; i++) {
    const MVertex *vi = getVertex(i);
    double v_xyz[3] = {vi->x(), vi->y(), vi->z()};
    _orig->xyz2uvw(v_xyz, v_uvw[i]);
  }
  MVertex v0(v_uvw[0][0], v_uvw[0][1], v_uvw[0][2]);
  MVertex v1(v_uvw[1][0], v_uvw[1][1], v_uvw[1][2]);
  MLine l(&v0, &v1);
  double ksi[3];
  l.xyz2uvw(uvw, ksi);
  if(l.isInside(ksi[0], ksi[1], ksi[2])) return true;
  return false;
}

void MLineChild::getIntegrationPoints(int pOrder, int *npts, IntPt **pts)
{
  *npts = 0;
  if(_intpt) delete[] _intpt;
  if(!_orig) return;
  _intpt = new IntPt[getNGQLPts(pOrder)];
  int nptsi;
  IntPt *ptsi;
  double v_uvw[2][3];
  for(int i = 0; i < 2; i++) {
    MVertex *vi = getVertex(i);
    double v_xyz[3] = {vi->x(), vi->y(), vi->z()};
    _orig->xyz2uvw(v_xyz, v_uvw[i]);
  }
  MVertex v0(v_uvw[0][0], v_uvw[0][1], v_uvw[0][2]);
  MVertex v1(v_uvw[1][0], v_uvw[1][1], v_uvw[1][2]);
  MLine l(&v0, &v1);
  l.getIntegrationPoints(pOrder, &nptsi, &ptsi);
  for(int ip = 0; ip < nptsi; ip++) {
    const double u = ptsi[ip].pt[0];
    const double v = ptsi[ip].pt[1];
    const double w = ptsi[ip].pt[2];
    SPoint3 p;
    l.pnt(u, v, w, p);
    _intpt[*npts + ip].pt[0] = p.x();
    _intpt[*npts + ip].pt[1] = p.y();
    _intpt[*npts + ip].pt[2] = p.z();
    _intpt[*npts + ip].weight = ptsi[ip].weight;
  }
  *npts = nptsi;
  *pts = _intpt;
}

//----------------------------------- MTriangleBorder
//------------------------------

bool MTriangleBorder::isInside(double u, double v, double w) const
{
  if(!getParent()) return false;
  double uvw[3] = {u, v, w};
  double v_uvw[3][3];
  for(int i = 0; i < 3; i++) {
    const MVertex *vi = getVertex(i);
    double v_xyz[3] = {vi->x(), vi->y(), vi->z()};
    getParent()->xyz2uvw(v_xyz, v_uvw[i]);
  }
  MVertex v0(v_uvw[0][0], v_uvw[0][1], v_uvw[0][2]);
  MVertex v1(v_uvw[1][0], v_uvw[1][1], v_uvw[1][2]);
  MVertex v2(v_uvw[2][0], v_uvw[2][1], v_uvw[2][2]);
  MTriangle t(&v0, &v1, &v2);
  double ksi[3];
  t.xyz2uvw(uvw, ksi);
  if(t.isInside(ksi[0], ksi[1], ksi[2])) return true;
  return false;
}

void MTriangleBorder::getIntegrationPoints(int pOrder, int *npts, IntPt **pts)
{
  *npts = 0;
  if(_intpt) delete[] _intpt;
  if(!getParent()) return;
  _intpt = new IntPt[getNGQTPts(pOrder)];
  int nptsi;
  IntPt *ptsi;

  double uvw[3][3];
  for(int j = 0; j < 3; j++) {
    double xyz[3] = {_v[j]->x(), _v[j]->y(), _v[j]->z()};
    getParent()->xyz2uvw(xyz, uvw[j]);
  }
  MVertex v0(uvw[0][0], uvw[0][1], uvw[0][2]);
  MVertex v1(uvw[1][0], uvw[1][1], uvw[1][2]);
  MVertex v2(uvw[2][0], uvw[2][1], uvw[2][2]);
  MTriangle tt(&v0, &v1, &v2);
  tt.getIntegrationPoints(pOrder, &nptsi, &ptsi);
  double jac[3][3];
  for(int ip = 0; ip < nptsi; ip++) {
    const double u = ptsi[ip].pt[0];
    const double v = ptsi[ip].pt[1];
    const double w = ptsi[ip].pt[2];
    tt.getJacobian(u, v, w, jac);
    SPoint3 p;
    tt.pnt(u, v, w, p);
    _intpt[ip].pt[0] = p.x();
    _intpt[ip].pt[1] = p.y();
    _intpt[ip].pt[2] = p.z();
    _intpt[ip].weight = ptsi[ip].weight;
  }
  *npts = nptsi;
  *pts = _intpt;
}

//-------------------------------------- MLineBorder
//------------------------------

bool MLineBorder::isInside(double u, double v, double w) const
{
  if(!getParent()) return false;
  double uvw[3] = {u, v, w};
  double v_uvw[2][3];
  for(int i = 0; i < 2; i++) {
    const MVertex *vi = getVertex(i);
    double v_xyz[3] = {vi->x(), vi->y(), vi->z()};
    getParent()->xyz2uvw(v_xyz, v_uvw[i]);
  }
  MVertex v0(v_uvw[0][0], v_uvw[0][1], v_uvw[0][2]);
  MVertex v1(v_uvw[1][0], v_uvw[1][1], v_uvw[1][2]);
  MLine l(&v0, &v1);
  double ksi[3];
  l.xyz2uvw(uvw, ksi);
  if(l.isInside(ksi[0], ksi[1], ksi[2])) return true;
  return false;
}

void MLineBorder::getIntegrationPoints(int pOrder, int *npts, IntPt **pts)
{
  *npts = 0;
  if(_intpt) delete[] _intpt;
  if(!getParent()) return;
  _intpt = new IntPt[getNGQLPts(pOrder)];
  int nptsi;
  IntPt *ptsi;

  double uvw[2][3];
  for(int j = 0; j < 2; j++) {
    double xyz[3] = {_v[j]->x(), _v[j]->y(), _v[j]->z()};
    getParent()->xyz2uvw(xyz, uvw[j]);
  }
  MVertex v0(uvw[0][0], uvw[0][1], uvw[0][2]);
  MVertex v1(uvw[1][0], uvw[1][1], uvw[1][2]);
  MLine ll(&v0, &v1);
  ll.getIntegrationPoints(pOrder, &nptsi, &ptsi);
  for(int ip = 0; ip < nptsi; ip++) {
    const double u = ptsi[ip].pt[0];
    const double v = ptsi[ip].pt[1];
    const double w = ptsi[ip].pt[2];
    SPoint3 p;
    ll.pnt(u, v, w, p);
    _intpt[ip].pt[0] = p.x();
    _intpt[ip].pt[1] = p.y();
    _intpt[ip].pt[2] = p.z();
    _intpt[ip].weight = ptsi[ip].weight;
  }
  *npts = nptsi;
  *pts = _intpt;
}

//---------------------------------------- CutMesh
//----------------------------

#if defined(HAVE_DINTEGRATION)

static void
assignPhysicals(GModel *GM, std::vector<int> &gePhysicals, int reg, int dim,
                std::map<int, std::map<int, std::string> > physicals[4],
                std::map<int, int> &newPhysTags, int lsTag)
{
  for(std::size_t i = 0; i < gePhysicals.size(); i++) {
    int phys = gePhysicals[i];

    if(lsTag > 0 && newPhysTags.count(phys)) {
      int phys2 = newPhysTags[phys];
      if(phys2 &&
         (!physicals[dim].count(reg) || !physicals[dim][reg].count(phys2))) {
        std::string name = GM->getPhysicalName(dim, phys);
        if(name != "" && newPhysTags.count(-phys)) {
          auto it = physicals[dim].begin();
          for(; it != physicals[dim].end(); it++) {
            auto it2 = it->second.begin();
            for(; it2 != it->second.end(); it2++)
              if(it2->second == name)
                physicals[dim][it->first][it2->first] = name + "_out";
          }
          name += "_in";
        }
        physicals[dim][reg][phys2] = name;
      }
    }
    else if(lsTag < 0 && newPhysTags.count(-phys)) {
      int phys2 = newPhysTags[-phys];
      if(phys2 &&
         (!physicals[dim].count(reg) || !physicals[dim][reg].count(phys2))) {
        std::string name = GM->getPhysicalName(dim, phys);
        if(name != "" && newPhysTags.count(phys)) {
          auto it = physicals[dim].begin();
          for(; it != physicals[dim].end(); it++) {
            auto it2 = it->second.begin();
            for(; it2 != it->second.end(); it2++)
              if(it2->second == name)
                physicals[dim][it->first][it2->first] = name + "_in";
          }
          name += "_out";
        }
        physicals[dim][reg][phys2] = name;
      }
    }
  }
}

static void
assignLsPhysical(GModel *GM, int reg, int dim,
                 std::map<int, std::map<int, std::string> > physicals[4],
                 int physTag, int lsTag)
{
  if(!physicals[dim][reg].count(physTag)) {
    std::stringstream strs;
    strs << lsTag;
    std::string sdim = (dim == 2) ? "S" : "L";
    physicals[dim][reg][physTag] = "levelset_" + sdim + strs.str();
    if(physTag != lsTag)
      Msg::Info("Levelset %d -> physical %d", lsTag, physTag);
  }
}

static int getElementaryTag(int lsTag, int elementary,
                            std::map<int, int> &newElemTags)
{
  if(lsTag < 0) {
    if(newElemTags.count(elementary))
      return newElemTags[elementary];
    else {
      int reg = ++newElemTags[0];
      newElemTags[elementary] = reg;
      return reg;
    }
  }
  return elementary;
}
static void getPhysicalTag(int lsTag, const std::vector<int> &physicals,
                           std::map<int, int> &newPhysTags)
{
  for(std::size_t i = 0; i < physicals.size(); i++) {
    int phys = physicals[i];
    if(lsTag < 0) {
      if(!newPhysTags.count(-phys)) newPhysTags[-phys] = ++newPhysTags[0];
      phys = newPhysTags[-phys];
    }
    else if(!newPhysTags.count(phys))
      newPhysTags[phys] = phys;
  }
}

static int getBorderTag(int lsTag, int count, int &maxTag,
                        std::map<int, int> &borderTags)
{
  if(borderTags.count(lsTag)) return borderTags[lsTag];
  if(count || lsTag < 0) {
    int tag = ++maxTag;
    borderTags[lsTag] = tag;
    return tag;
  }
  maxTag = std::max(maxTag, lsTag);
  borderTags[lsTag] = lsTag;
  return lsTag;
}

static void elementSplitMesh(
  MElement *e, std::vector<gLevelset *> &RPN, fullMatrix<double> &verticesLs,
  GEntity *ge, GModel *GM, std::size_t &numEle,
  std::map<int, MVertex *> &vertexMap,
  std::map<MElement *, MElement *> &newParents,
  std::map<MElement *, MElement *> &newDomains,
  std::map<int, std::vector<MElement *> > elements[10],
  std::map<int, std::map<int, std::string> > physicals[4],
  std::map<int, int> newElemTags[4], std::map<int, int> newPhysTags[4],
  std::map<int, int> borderElemTags[2], std::map<int, int> borderPhysTags[2])
{
  int elementary = ge->tag();
  int eType = e->getType();
  std::vector<int> gePhysicals = ge->physicals;
  int iLs = (verticesLs.size1() == 1) ? 0 : verticesLs.size1() - 1;
  int gLsTag = RPN[RPN.size() - 1]->getTag();

  MElement *copy = e->copy(vertexMap, newParents, newDomains);
  double eps = 1.e-10;
  bool splitElem = false;

  // split acording to center of gravity
  // double lsMean = 0.0;
  // int lsTag = 1;
  // for(int k = 0; k < e->getNumVertices(); k++)
  //   lsMean += verticesLs(iLs, e->getVertex(k)->getIndex()) - eps;
  // if (lsMean > 0) lsTag = -1;

  // EMI : better for embedded dirichlet with smoothed properties
  // split according to values of vertices (keep +)
  int lsTag = (verticesLs(iLs, e->getVertex(0)->getIndex()) > eps) ? -1 : 1;
  int ils = 0;
  for(std::size_t k = 1; k < e->getNumVertices(); k++) {
    int lsTag2 = (verticesLs(iLs, e->getVertex(k)->getIndex()) > eps) ? -1 : 1;
    if(lsTag * lsTag2 < 0) {
      lsTag = -1;
      splitElem = true;
      if(RPN.size() > 1) {
        for(; ils < verticesLs.size1() - 1; ils++) {
          int lsT1 =
            (verticesLs(ils, e->getVertex(0)->getIndex()) > eps) ? -1 : 1;
          int lsT2 =
            (verticesLs(ils, e->getVertex(k)->getIndex()) > eps) ? -1 : 1;
          if(lsT1 * lsT2 < 0) break;
        }
        for(int i = 0; i <= ils; i++)
          if(!RPN[i]->isPrimitive()) ils++;
        gLsTag = RPN[ils]->getTag();
      }
      break;
    }
  }

  // invert tag
  // lsTag = 1; //negative ls
  // for(int k = 0; k < e->getNumVertices(); k++){
  //  double val = verticesLs(iLs, e->getVertex(k)->getIndex());
  //  if (val > 0.0) { lsTag = -1; break; }
  //}

  switch(eType) {
  case TYPE_TET:
  case TYPE_HEX:
  case TYPE_PYR:
  case TYPE_PRI:
  case TYPE_POLYH: {
    int reg = getElementaryTag(lsTag, elementary, newElemTags[3]);
    getPhysicalTag(lsTag, gePhysicals, newPhysTags[3]);
    if(eType == TYPE_TET)
      elements[4][reg].push_back(copy);
    else if(eType == TYPE_HEX)
      elements[5][reg].push_back(copy);
    else if(eType == TYPE_PRI)
      elements[6][reg].push_back(copy);
    else if(eType == TYPE_PYR)
      elements[7][reg].push_back(copy);
    else if(eType == TYPE_POLYH)
      elements[9][reg].push_back(copy);
    assignPhysicals(GM, gePhysicals, reg, 3, physicals, newPhysTags[3], lsTag);
  } break;
  case TYPE_TRI:
  case TYPE_QUA:
  case TYPE_POLYG: {
    int reg = getElementaryTag(lsTag, elementary, newElemTags[2]);
    getPhysicalTag(lsTag, gePhysicals, newPhysTags[2]);
    if(eType == TYPE_TRI)
      elements[2][reg].push_back(copy);
    else if(eType == TYPE_QUA)
      elements[3][reg].push_back(copy);
    else if(eType == TYPE_POLYG)
      elements[8][reg].push_back(copy);
    assignPhysicals(GM, gePhysicals, reg, 2, physicals, newPhysTags[2], lsTag);
  } break;
  case TYPE_LIN: {
    int reg = getElementaryTag(lsTag, elementary, newElemTags[1]);
    getPhysicalTag(lsTag, gePhysicals, newPhysTags[1]);
    elements[1][reg].push_back(copy);
    assignPhysicals(GM, gePhysicals, reg, 1, physicals, newPhysTags[1], lsTag);
  } break;
  case TYPE_PNT: {
    int reg = getElementaryTag(lsTag, elementary, newElemTags[0]);
    getPhysicalTag(lsTag, gePhysicals, newPhysTags[0]);
    elements[0][reg].push_back(copy);
    assignPhysicals(GM, gePhysicals, reg, 0, physicals, newPhysTags[0], lsTag);
  } break;
  default: Msg::Error("This type of element cannot be split."); return;
  }

  // create level set interface (pt in 1D, line in 2D or face in 3D)
  if(splitElem && e->getDim() == 2) {
    for(int k = 0; k < e->getNumEdges(); k++) {
      MEdge me = e->getEdge(k);
      MVertex *v0 = me.getVertex(0);
      MVertex *v1 = me.getVertex(1);
      MVertex *v0N = vertexMap[v0->getNum()];
      MVertex *v1N = vertexMap[v1->getNum()];
      double val0 = (verticesLs(iLs, v0->getIndex()) > eps) ? 1 : -1;
      double val1 = (verticesLs(iLs, v1->getIndex()) > eps) ? 1 : -1;
      if(val0 * val1 > 0.0 && val0 < 0.0) {
        getPhysicalTag(-1, gePhysicals, newPhysTags[1]);
        int c = elements[1].count(gLsTag);
        int reg = getBorderTag(gLsTag, c, newElemTags[1][0], borderElemTags[0]);
        int physTag =
          (!gePhysicals.size()) ?
            0 :
            getBorderTag(gLsTag, c, newPhysTags[1][0], borderPhysTags[0]);
        int i;
        for(i = elements[1][reg].size() - 1; i >= 0; i--) {
          MElement *el = elements[1][reg][i];
          if((el->getVertex(0) == v0N && el->getVertex(1) == v1N) ||
             (el->getVertex(0) == v1N && el->getVertex(1) == v0N))
            break;
        }
        if(i < 0) {
          MLine *lin = new MLine(v0N, v1N);
          elements[1][reg].push_back(lin);
          if(physTag) assignLsPhysical(GM, reg, 1, physicals, physTag, gLsTag);
        }
        else {
          MElement *el = elements[1][reg][i];
          elements[1][reg].erase(elements[1][reg].begin() + i);
          delete el;
        }
      }
    }
  }
  else if(splitElem && e->getDim() == 3) {
    for(int k = 0; k < e->getNumFaces(); k++) {
      MFace mf = e->getFace(k);
      bool sameSign = true;
      double val0 =
        (verticesLs(iLs, mf.getVertex(0)->getIndex()) > eps) ? 1 : -1;
      for(std::size_t j = 1; j < mf.getNumVertices(); j++) {
        double valj =
          (verticesLs(iLs, mf.getVertex(j)->getIndex()) > eps) ? 1 : -1;
        if(val0 * valj < 0.0) {
          sameSign = false;
          break;
        }
      }
      if(sameSign && val0 < 0.0) {
        getPhysicalTag(-1, gePhysicals, newPhysTags[2]);
        int c = elements[2].count(gLsTag) + elements[3].count(gLsTag) +
                elements[8].count(gLsTag);
        int reg = getBorderTag(gLsTag, c, newElemTags[2][0], borderElemTags[1]);
        int physTag =
          (!gePhysicals.size()) ?
            0 :
            getBorderTag(gLsTag, c, newPhysTags[2][0], borderPhysTags[1]);
        if(mf.getNumVertices() == 3) {
          MFace f1 = MFace(vertexMap[mf.getVertex(0)->getNum()],
                           vertexMap[mf.getVertex(1)->getNum()],
                           vertexMap[mf.getVertex(2)->getNum()]);
          int i = elements[2][reg].size() - 1;
          for(; i >= 0; i--) {
            MElement *el = elements[2][reg][i];
            MFace f2 =
              MFace(el->getVertex(0), el->getVertex(1), el->getVertex(2));
            if(f1 == f2) break;
          }
          if(i < 0) {
            MTriangle *tri =
              new MTriangle(f1.getVertex(0), f1.getVertex(1), f1.getVertex(2));
            elements[2][reg].push_back(tri);
          }
          else {
            MElement *el = elements[2][reg][i];
            elements[2][reg].erase(elements[2][reg].begin() + i);
            delete el;
          }
        }
        else if(mf.getNumVertices() == 4) {
          MFace f1 = MFace(vertexMap[mf.getVertex(0)->getNum()],
                           vertexMap[mf.getVertex(1)->getNum()],
                           vertexMap[mf.getVertex(2)->getNum()],
                           vertexMap[mf.getVertex(3)->getNum()]);
          int i;
          for(i = elements[3][reg].size() - 1; i >= 0; i--) {
            MElement *el = elements[3][reg][i];
            MFace f2 = MFace(el->getVertex(0), el->getVertex(1),
                             el->getVertex(2), el->getVertex(3));
            if(f1 == f2) break;
          }
          if(i < 0) {
            MQuadrangle *quad =
              new MQuadrangle(f1.getVertex(0), f1.getVertex(1), f1.getVertex(2),
                              f1.getVertex(2));
            elements[3][reg].push_back(quad);
          }
          else {
            MElement *el = elements[3][reg][i];
            elements[3][reg].erase(elements[3][reg].begin() + i);
            delete el;
          }
        }
        if(physTag) assignLsPhysical(GM, reg, 2, physicals, physTag, gLsTag);
      }
    }
  }
}

static bool equalV(MVertex *v, const DI_Point *p)
{
  return (fabs(v->x() - p->x()) < 1.e-15 && fabs(v->y() - p->y()) < 1.e-15 &&
          fabs(v->z() - p->z()) < 1.e-15);
}

static int getElementVertexNum(DI_Point *p, MElement *e)
{
  for(std::size_t i = 0; i < e->getNumVertices(); i++)
    if(equalV(e->getVertex(i), p)) return e->getVertex(i)->getNum();
  return -1;
}

typedef std::set<MVertex *, MVertexPtrLessThanLexicographic>
  newVerticesContainer;

static void elementCutMesh(
  MElement *e, std::vector<gLevelset *> &RPN, fullMatrix<double> &verticesLs,
  GEntity *ge, GModel *GM, std::size_t &numEle,
  std::map<int, MVertex *> &vertexMap, newVerticesContainer &newVertices,
  std::map<MElement *, MElement *> &newParents,
  std::map<MElement *, MElement *> &newDomains,
  std::multimap<MElement *, MElement *> borders[2],
  std::map<int, std::vector<MElement *> > elements[10],
  std::map<int, std::map<int, std::string> > physicals[4],
  std::map<int, int> newElemTags[4], std::map<int, int> newPhysTags[4],
  std::map<int, int> borderElemTags[2], std::map<int, int> borderPhysTags[2],
  DI_Point::Container &cp, std::vector<DI_Line *> &lines,
  std::vector<DI_Triangle *> &triangles, std::vector<DI_Quad *> &quads,
  std::vector<DI_Tetra *> &tetras, std::vector<DI_Hexa *> &hexas)
{
  int elementary = ge->tag();
  int eType = e->getType();
  int recur = e->getPolynomialOrder() - 1;
  int ePart = e->getPartition();
  MElement *eParent = e->getParent();
  std::vector<int> gePhysicals = ge->physicals;

  int integOrder = 1;
  std::vector<DI_IntegrationPoint *> ipV;
  std::vector<DI_IntegrationPoint *> ipS;
  bool isCut = false;
  std::size_t nbL = lines.size();
  std::size_t nbTr = triangles.size();
  std::size_t nbQ = quads.size();
  std::size_t nbTe = tetras.size();
  std::size_t nbH = hexas.size();

  MElement *copy = e->copy(vertexMap, newParents, newDomains);
  MElement *parent = eParent ? copy->getParent() : copy;

  double **nodeLs = new double *[e->getNumVertices()];

  switch(eType) {
  case TYPE_TET:
  case TYPE_HEX:
  case TYPE_PYR:
  case TYPE_PRI:
  case TYPE_POLYH: {
    if(eType == TYPE_TET) {
      DI_Tetra T(
        e->getVertex(0)->x(), e->getVertex(0)->y(), e->getVertex(0)->z(),
        e->getVertex(1)->x(), e->getVertex(1)->y(), e->getVertex(1)->z(),
        e->getVertex(2)->x(), e->getVertex(2)->y(), e->getVertex(2)->z(),
        e->getVertex(3)->x(), e->getVertex(3)->y(), e->getVertex(3)->z());
      T.setPolynomialOrder(recur + 1);
      for(std::size_t i = 0; i < e->getNumVertices(); i++)
        nodeLs[i] = &verticesLs(0, e->getVertex(i)->getIndex());
      isCut = T.cut(RPN, ipV, ipS, cp, integOrder, integOrder, integOrder,
                    tetras, quads, triangles, recur, nodeLs);
    }
    else if(eType == TYPE_HEX) {
      DI_Hexa H(
        e->getVertex(0)->x(), e->getVertex(0)->y(), e->getVertex(0)->z(),
        e->getVertex(1)->x(), e->getVertex(1)->y(), e->getVertex(1)->z(),
        e->getVertex(2)->x(), e->getVertex(2)->y(), e->getVertex(2)->z(),
        e->getVertex(3)->x(), e->getVertex(3)->y(), e->getVertex(3)->z(),
        e->getVertex(4)->x(), e->getVertex(4)->y(), e->getVertex(4)->z(),
        e->getVertex(5)->x(), e->getVertex(5)->y(), e->getVertex(5)->z(),
        e->getVertex(6)->x(), e->getVertex(6)->y(), e->getVertex(6)->z(),
        e->getVertex(7)->x(), e->getVertex(7)->y(), e->getVertex(7)->z());
      H.setPolynomialOrder(recur + 1);
      for(std::size_t i = 0; i < e->getNumVertices(); i++)
        nodeLs[i] = &verticesLs(0, e->getVertex(i)->getIndex());
      isCut =
        H.cut(RPN, ipV, ipS, cp, integOrder, integOrder, integOrder, integOrder,
              hexas, tetras, quads, triangles, lines, recur, nodeLs);
    }
    else if(eType == TYPE_PRI) {
      DI_Tetra T1(
        e->getVertex(0)->x(), e->getVertex(0)->y(), e->getVertex(0)->z(),
        e->getVertex(1)->x(), e->getVertex(1)->y(), e->getVertex(1)->z(),
        e->getVertex(2)->x(), e->getVertex(2)->y(), e->getVertex(2)->z(),
        e->getVertex(5)->x(), e->getVertex(5)->y(), e->getVertex(5)->z());
      // T1.setPolynomialOrder(recur+1);
      for(int i = 0; i < 3; i++)
        nodeLs[i] = &verticesLs(0, e->getVertex(i)->getIndex());
      nodeLs[3] = &verticesLs(0, e->getVertex(5)->getIndex());
      bool iC1 = T1.cut(RPN, ipV, ipS, cp, integOrder, integOrder, integOrder,
                        tetras, quads, triangles, recur, nodeLs);
      DI_Tetra T2(
        e->getVertex(0)->x(), e->getVertex(0)->y(), e->getVertex(0)->z(),
        e->getVertex(4)->x(), e->getVertex(4)->y(), e->getVertex(4)->z(),
        e->getVertex(1)->x(), e->getVertex(1)->y(), e->getVertex(1)->z(),
        e->getVertex(5)->x(), e->getVertex(5)->y(), e->getVertex(5)->z());
      // T2.setPolynomialOrder(recur+1);
      nodeLs[0] = &verticesLs(0, e->getVertex(0)->getIndex());
      nodeLs[1] = &verticesLs(0, e->getVertex(4)->getIndex());
      nodeLs[2] = &verticesLs(0, e->getVertex(1)->getIndex());
      nodeLs[3] = &verticesLs(0, e->getVertex(5)->getIndex());
      bool iC2 = T2.cut(RPN, ipV, ipS, cp, integOrder, integOrder, integOrder,
                        tetras, quads, triangles, recur, nodeLs);
      DI_Tetra T3(
        e->getVertex(0)->x(), e->getVertex(0)->y(), e->getVertex(0)->z(),
        e->getVertex(3)->x(), e->getVertex(3)->y(), e->getVertex(3)->z(),
        e->getVertex(4)->x(), e->getVertex(4)->y(), e->getVertex(4)->z(),
        e->getVertex(5)->x(), e->getVertex(5)->y(), e->getVertex(5)->z());
      // T3.setPolynomialOrder(recur+1);
      for(int i = 1; i < 4; i++)
        nodeLs[i] = &verticesLs(0, e->getVertex(i + 2)->getIndex());
      bool iC3 = T3.cut(RPN, ipV, ipS, cp, integOrder, integOrder, integOrder,
                        tetras, quads, triangles, recur, nodeLs);
      isCut = iC1 || iC2 || iC3;
    }
    else if(eType == TYPE_PYR) {
      DI_Tetra T1(
        e->getVertex(0)->x(), e->getVertex(0)->y(), e->getVertex(0)->z(),
        e->getVertex(1)->x(), e->getVertex(1)->y(), e->getVertex(1)->z(),
        e->getVertex(2)->x(), e->getVertex(2)->y(), e->getVertex(2)->z(),
        e->getVertex(4)->x(), e->getVertex(4)->y(), e->getVertex(4)->z());
      // T1.setPolynomialOrder(recur+1);
      for(int i = 0; i < 3; i++)
        nodeLs[i] = &verticesLs(0, e->getVertex(i)->getIndex());
      nodeLs[3] = &verticesLs(0, e->getVertex(4)->getIndex());
      bool iC1 = T1.cut(RPN, ipV, ipS, cp, integOrder, integOrder, integOrder,
                        tetras, quads, triangles, recur, nodeLs);
      DI_Tetra T2(
        e->getVertex(0)->x(), e->getVertex(0)->y(), e->getVertex(0)->z(),
        e->getVertex(2)->x(), e->getVertex(2)->y(), e->getVertex(2)->z(),
        e->getVertex(3)->x(), e->getVertex(3)->y(), e->getVertex(3)->z(),
        e->getVertex(4)->x(), e->getVertex(4)->y(), e->getVertex(4)->z());
      // T2.setPolynomialOrder(recur+1);
      nodeLs[0] = &verticesLs(0, e->getVertex(0)->getIndex());
      for(int i = 1; i < 4; i++)
        nodeLs[i] = &verticesLs(0, e->getVertex(i + 1)->getIndex());
      bool iC2 = T2.cut(RPN, ipV, ipS, cp, integOrder, integOrder, integOrder,
                        tetras, quads, triangles, recur, nodeLs);
      isCut = iC1 || iC2;
    }
    else if(eType == TYPE_POLYH) {
      for(int i = 0; i < e->getNumChildren(); i++) {
        MTetrahedron *t = (MTetrahedron *)e->getChild(i);
        DI_Tetra Tet(
          t->getVertex(0)->x(), t->getVertex(0)->y(), t->getVertex(0)->z(),
          t->getVertex(1)->x(), t->getVertex(1)->y(), t->getVertex(1)->z(),
          t->getVertex(2)->x(), t->getVertex(2)->y(), t->getVertex(2)->z(),
          t->getVertex(3)->x(), t->getVertex(3)->y(), t->getVertex(3)->z());
        Tet.setPolynomialOrder(recur + 1);
        for(std::size_t i = 0; i < t->getNumVertices(); i++)
          nodeLs[i] = &verticesLs(0, t->getVertex(i)->getIndex());
        bool iC = Tet.cut(RPN, ipV, ipS, cp, integOrder, integOrder, integOrder,
                          tetras, quads, triangles, recur, nodeLs);
        isCut = (isCut || iC);
      }
    }
    MPolyhedron *p1 = nullptr, *p2 = nullptr;
    if(isCut) {
      std::vector<MTetrahedron *> poly[2];

      for(std::size_t i = nbTe; i < tetras.size(); i++) {
        MVertex *mv[4] = {nullptr, nullptr, nullptr, nullptr};
        for(int j = 0; j < 4; j++) {
          int numV = getElementVertexNum(tetras[i]->pt(j), e);
          if(numV == -1) {
            MVertex *newv =
              new MVertex(tetras[i]->x(j), tetras[i]->y(j), tetras[i]->z(j));
            auto it = newVertices.insert(newv);
            mv[j] = *(it.first);
            if(!it.second) newv->deleteLast();
          }
          else {
            auto it = vertexMap.find(numV);
            if(it == vertexMap.end()) {
              mv[j] = new MVertex(tetras[i]->x(j), tetras[i]->y(j),
                                  tetras[i]->z(j), nullptr, numV);
              vertexMap[numV] = mv[j];
            }
            else
              mv[j] = it->second;
          }
        }
        MTetrahedron *mt = new MTetrahedron(mv[0], mv[1], mv[2], mv[3], 0, 0);
        if(tetras[i]->lsTag() < 0)
          poly[0].push_back(mt);
        else
          poly[1].push_back(mt);
      }
      bool own = (eParent && !e->ownsParent()) ? false : true;
      if(poly[0].size()) {
        int n = (e->getParent()) ? e->getNum() : ++numEle;
        p1 = new MPolyhedron(poly[0], n, ePart, own, parent);
        own = false;
        int reg = getElementaryTag(-1, elementary, newElemTags[3]);
        getPhysicalTag(-1, gePhysicals, newPhysTags[3]);
        elements[9][reg].push_back(p1);
        assignPhysicals(GM, gePhysicals, reg, 3, physicals, newPhysTags[3], -1);
      }
      if(poly[1].size()) {
        int n =
          (e->getParent() && poly[0].size() == 0) ? e->getNum() : ++numEle;
        p2 = new MPolyhedron(poly[1], n, ePart, own, parent);
        getPhysicalTag(1, gePhysicals, newPhysTags[3]);
        elements[9][elementary].push_back(p2);
        assignPhysicals(GM, gePhysicals, elementary, 3, physicals,
                        newPhysTags[3], 1);
      }
      // check for border surfaces cut earlier along the polyhedra
      auto itr = borders[1].equal_range(copy);
      std::vector<std::pair<MElement *, MElement *> > bords;
      for(auto it = itr.first; it != itr.second; it++) {
        MElement *tb = it->second;
        int match = 0;
        for(std::size_t i = 0; i < p1->getNumPrimaryVertices(); i++) {
          if(tb->getVertex(0) == p1->getVertex(i) ||
             tb->getVertex(1) == p1->getVertex(i) ||
             tb->getVertex(2) == p1->getVertex(i))
            match++;
          if(match == 3) break;
        }
        MElement *dom = (match == 3) ? p1 : p2;
        tb->setDomain(dom, (tb->getDomain(0) == copy) ? 0 : 1);
        bords.push_back(std::make_pair(dom, tb));
      }
      borders[1].erase(itr.first, itr.second);
      for(std::size_t i = 0; i < bords.size(); i++) borders[1].insert(bords[i]);
      if(eParent) {
        copy->setParent(nullptr, false);
        delete copy;
      }
    }
    else { // no cut
      int lsTag;
      if(eType == TYPE_HEX)
        lsTag = hexas[nbH]->lsTag();
      else
        lsTag = tetras[nbTe]->lsTag();
      int reg = getElementaryTag(lsTag, elementary, newElemTags[3]);
      getPhysicalTag(lsTag, gePhysicals, newPhysTags[3]);
      if(eType == TYPE_TET)
        elements[4][reg].push_back(copy);
      else if(eType == TYPE_HEX)
        elements[5][reg].push_back(copy);
      else if(eType == TYPE_PRI)
        elements[6][reg].push_back(copy);
      else if(eType == TYPE_PYR)
        elements[7][reg].push_back(copy);
      else if(eType == TYPE_POLYH)
        elements[9][reg].push_back(copy);
      assignPhysicals(GM, gePhysicals, reg, 3, physicals, newPhysTags[3],
                      lsTag);
    }

    for(std::size_t i = nbTr; i < triangles.size(); i++) {
      MVertex *mv[3] = {nullptr, nullptr, nullptr};
      for(int j = 0; j < 3; j++) {
        int numV = getElementVertexNum(triangles[i]->pt(j), e);
        if(numV == -1) {
          MVertex *newv = new MVertex(triangles[i]->x(j), triangles[i]->y(j),
                                      triangles[i]->z(j));
          auto it = newVertices.insert(newv);
          mv[j] = *(it.first);
          if(!it.second) newv->deleteLast();
        }
        else {
          auto it = vertexMap.find(numV);
          if(it == vertexMap.end()) {
            mv[j] = new MVertex(triangles[i]->x(j), triangles[i]->y(j),
                                triangles[i]->z(j), nullptr, numV);
            vertexMap[numV] = mv[j];
          }
          else
            mv[j] = it->second;
        }
      }
      MTriangle *tri;
      if(p1 || p2) {
        if(!p1)
          tri =
            new MTriangleBorder(mv[0], mv[1], mv[2], ++numEle, ePart, p2, p1);
        else
          tri =
            new MTriangleBorder(mv[0], mv[1], mv[2], ++numEle, ePart, p1, p2);
      }
      else
        tri = new MTriangle(mv[0], mv[1], mv[2], ++numEle, ePart);
      int lsTag = triangles[i]->lsTag();
      int cR = elements[2].count(lsTag) + elements[3].count(lsTag) +
               elements[8].count(lsTag);
      int cP = 0;
      for(auto it = physicals[2].begin(); it != physicals[2].end(); it++)
        for(auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
          if(it2->first == lsTag) {
            cP = 1;
            break;
          }
      // the surfaces are cut before the volumes!
      int reg = getBorderTag(lsTag, cR, newElemTags[2][0], borderElemTags[1]);
      int physTag =
        (!gePhysicals.size()) ?
          0 :
          getBorderTag(lsTag, cP, newPhysTags[2][0], borderPhysTags[1]);
      elements[2][reg].push_back(tri);
      if(physTag) assignLsPhysical(GM, reg, 2, physicals, physTag, lsTag);
      for(int i = 0; i < 2; i++)
        if(tri->getDomain(i))
          borders[1].insert(std::make_pair(tri->getDomain(i), tri));
    }
  } break;
  case TYPE_TRI:
  case TYPE_QUA:
  case TYPE_POLYG: {
    if(eType == TYPE_TRI) {
      DI_Triangle T(
        e->getVertex(0)->x(), e->getVertex(0)->y(), e->getVertex(0)->z(),
        e->getVertex(1)->x(), e->getVertex(1)->y(), e->getVertex(1)->z(),
        e->getVertex(2)->x(), e->getVertex(2)->y(), e->getVertex(2)->z());
      T.setPolynomialOrder(recur + 1);
      for(std::size_t i = 0; i < e->getNumVertices(); i++)
        nodeLs[i] = &verticesLs(0, e->getVertex(i)->getIndex());
      isCut = T.cut(RPN, ipV, ipS, cp, integOrder, integOrder, integOrder,
                    quads, triangles, lines, recur, nodeLs);
    }
    else if(eType == TYPE_QUA) {
      DI_Quad Q(
        e->getVertex(0)->x(), e->getVertex(0)->y(), e->getVertex(0)->z(),
        e->getVertex(1)->x(), e->getVertex(1)->y(), e->getVertex(1)->z(),
        e->getVertex(2)->x(), e->getVertex(2)->y(), e->getVertex(2)->z(),
        e->getVertex(3)->x(), e->getVertex(3)->y(), e->getVertex(3)->z());
      Q.setPolynomialOrder(recur + 1);
      for(std::size_t i = 0; i < e->getNumVertices(); i++)
        nodeLs[i] = &verticesLs(0, e->getVertex(i)->getIndex());
      isCut = Q.cut(RPN, ipV, ipS, cp, integOrder, integOrder, integOrder,
                    quads, triangles, lines, recur, nodeLs);
    }
    else if(eType == TYPE_POLYG) {
      for(int i = 0; i < e->getNumChildren(); i++) {
        MElement *t = e->getChild(i);
        DI_Triangle Tri(
          t->getVertex(0)->x(), t->getVertex(0)->y(), t->getVertex(0)->z(),
          t->getVertex(1)->x(), t->getVertex(1)->y(), t->getVertex(1)->z(),
          t->getVertex(2)->x(), t->getVertex(2)->y(), t->getVertex(2)->z());
        Tri.setPolynomialOrder(recur + 1);
        for(std::size_t i = 0; i < t->getNumVertices(); i++)
          nodeLs[i] = &verticesLs(0, t->getVertex(i)->getIndex());
        bool iC = Tri.cut(RPN, ipV, ipS, cp, integOrder, integOrder, integOrder,
                          quads, triangles, lines, recur, nodeLs);
        isCut = (isCut || iC);
      }
    }

    MPolygon *p1 = nullptr, *p2 = nullptr;
    if(isCut) {
      std::vector<MTriangle *> poly[2];

      for(std::size_t i = nbTr; i < triangles.size(); i++) {
        MVertex *mv[3] = {nullptr, nullptr, nullptr};
        for(int j = 0; j < 3; j++) {
          int numV = getElementVertexNum(triangles[i]->pt(j), e);
          if(numV == -1) {
            MVertex *newv = new MVertex(triangles[i]->x(j), triangles[i]->y(j),
                                        triangles[i]->z(j));
            auto it = newVertices.insert(newv);
            mv[j] = *(it.first);
            if(!it.second) newv->deleteLast();
          }
          else {
            auto it = vertexMap.find(numV);
            if(it == vertexMap.end()) {
              mv[j] = new MVertex(triangles[i]->x(j), triangles[i]->y(j),
                                  triangles[i]->z(j), nullptr, numV);
              vertexMap[numV] = mv[j];
            }
            else
              mv[j] = it->second;
          }
        }
        MTriangle *mt = new MTriangle(mv[0], mv[1], mv[2], 0, 0);
        if(triangles[i]->lsTag() < 0)
          poly[0].push_back(mt);
        else
          poly[1].push_back(mt);
      }
      // if quads
      for(std::size_t i = nbQ; i < quads.size(); i++) {
        MVertex *mv[4] = {nullptr, nullptr, nullptr, nullptr};
        for(int j = 0; j < 4; j++) {
          int numV = getElementVertexNum(quads[i]->pt(j), e);
          if(numV == -1) {
            MVertex *newv =
              new MVertex(quads[i]->x(j), quads[i]->y(j), quads[i]->z(j));
            auto it = newVertices.insert(newv);
            mv[j] = *(it.first);
            if(!it.second) newv->deleteLast();
          }
          else {
            auto it = vertexMap.find(numV);
            if(it == vertexMap.end()) {
              mv[j] = new MVertex(quads[i]->x(j), quads[i]->y(j),
                                  quads[i]->z(j), nullptr, numV);
              vertexMap[numV] = mv[j];
            }
            else
              mv[j] = it->second;
          }
        }
        MTriangle *mt0 = new MTriangle(mv[0], mv[1], mv[2], 0, 0);
        MTriangle *mt1 = new MTriangle(mv[0], mv[2], mv[3], 0, 0);
        if(quads[i]->lsTag() < 0) {
          poly[0].push_back(mt0);
          poly[0].push_back(mt1);
        }
        else {
          poly[1].push_back(mt0);
          poly[1].push_back(mt1);
        }
      }

      bool own = (eParent && !e->ownsParent()) ? false : true;
      if(poly[0].size()) {
        int n = (e->getParent()) ? e->getNum() : ++numEle;
        if(eType == MSH_TRI_B || eType == MSH_POLYG_B)
          p1 = new MPolygonBorder(poly[0], n, ePart, own, parent,
                                  copy->getDomain(0), copy->getDomain(1));
        else
          p1 = new MPolygon(poly[0], n, ePart, own, parent);
        own = false;
        int reg = getElementaryTag(-1, elementary, newElemTags[2]);
        getPhysicalTag(-1, gePhysicals, newPhysTags[2]);
        elements[8][reg].push_back(p1);
        assignPhysicals(GM, gePhysicals, reg, 2, physicals, newPhysTags[2], -1);
        for(int i = 0; i < 2; i++)
          if(p1->getDomain(i))
            borders[1].insert(std::make_pair(p1->getDomain(i), p1));
      }
      if(poly[1].size()) {
        int n =
          (e->getParent() && poly[0].size() == 0) ? e->getNum() : ++numEle;
        if(eType == MSH_TRI_B || eType == MSH_POLYG_B)
          p2 = new MPolygonBorder(poly[1], n, ePart, own, parent,
                                  copy->getDomain(0), copy->getDomain(1));
        else
          p2 = new MPolygon(poly[1], n, ePart, own, parent);
        getPhysicalTag(1, gePhysicals, newPhysTags[2]);
        elements[8][elementary].push_back(p2);
        assignPhysicals(GM, gePhysicals, elementary, 2, physicals,
                        newPhysTags[2], 1);
        for(int i = 0; i < 2; i++)
          if(p2->getDomain(i))
            borders[1].insert(std::make_pair(p2->getDomain(i), p2));
      }
      // check for border lines cut earlier along the polygons
      auto itr = borders[0].equal_range(copy);
      std::vector<std::pair<MElement *, MElement *> > bords;
      for(auto it = itr.first; it != itr.second; ++it) {
        MElement *lb = it->second;
        int match = 0;
        for(std::size_t i = 0; i < p1->getNumPrimaryVertices(); i++) {
          if(lb->getVertex(0) == p1->getVertex(i) ||
             lb->getVertex(1) == p1->getVertex(i))
            match++;
          if(match == 2) break;
        }
        MElement *dom = (match == 2) ? p1 : p2;
        lb->setDomain(dom, (lb->getDomain(0) == copy) ? 0 : 1);
        bords.push_back(std::make_pair(dom, lb));
      }
      borders[0].erase(itr.first, itr.second);
      for(std::size_t i = 0; i < bords.size(); i++) borders[0].insert(bords[i]);
      if(eParent) {
        copy->setParent(nullptr, false);
        delete copy;
      }
    }
    else { // no cut
      int lsTag;
      if(eType == TYPE_QUA)
        lsTag = quads[nbQ]->lsTag();
      else
        lsTag = triangles[nbTr]->lsTag();
      int reg = getElementaryTag(lsTag, elementary, newElemTags[2]);
      getPhysicalTag(lsTag, gePhysicals, newPhysTags[2]);
      if(eType == TYPE_TRI)
        elements[2][reg].push_back(copy);
      else if(eType == TYPE_QUA)
        elements[3][reg].push_back(copy);
      else if(eType == TYPE_POLYG)
        elements[8][reg].push_back(copy);
      assignPhysicals(GM, gePhysicals, reg, 2, physicals, newPhysTags[2],
                      lsTag);
      for(int i = 0; i < 2; i++)
        if(copy->getDomain(i))
          borders[1].insert(std::make_pair(copy->getDomain(i), copy));
    }

    for(std::size_t i = nbL; i < lines.size(); i++) {
      MVertex *mv[2] = {nullptr, nullptr};
      for(int j = 0; j < 2; j++) {
        int numV = getElementVertexNum(lines[i]->pt(j), e);
        if(numV == -1) {
          MVertex *newv =
            new MVertex(lines[i]->x(j), lines[i]->y(j), lines[i]->z(j));
          auto it = newVertices.insert(newv);
          mv[j] = *(it.first);
          if(!it.second) newv->deleteLast();
        }
        else {
          auto it = vertexMap.find(numV);
          if(it == vertexMap.end()) {
            mv[j] = new MVertex(lines[i]->x(j), lines[i]->y(j), lines[i]->z(j),
                                nullptr, numV);
            vertexMap[numV] = mv[j];
          }
          else
            mv[j] = it->second;
        }
      }
      MLine *lin;
      if(p1 || p2) {
        if(!p1)
          lin = new MLineBorder(mv[0], mv[1], ++numEle, ePart, p2, p1);
        else
          lin = new MLineBorder(mv[0], mv[1], ++numEle, ePart, p1, p2);
      }
      else
        lin = new MLine(mv[0], mv[1], ++numEle, ePart);
      int lsTag = lines[i]->lsTag();
      int cR = elements[1].count(lsTag);
      int cP = 0;
      for(auto it = physicals[1].begin(); it != physicals[1].end(); it++)
        for(auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
          if(it2->first == lsTag) {
            cP = 1;
            break;
          }
      // the lines are cut before the surfaces!
      int reg = getBorderTag(lsTag, cR, newElemTags[1][0], borderElemTags[0]);
      int physTag =
        (!gePhysicals.size()) ?
          0 :
          getBorderTag(lsTag, cP, newPhysTags[1][0], borderPhysTags[0]);
      elements[1][reg].push_back(lin);
      if(physTag) assignLsPhysical(GM, reg, 1, physicals, physTag, lsTag);
      for(int i = 0; i < 2; i++)
        if(lin->getDomain(i))
          borders[0].insert(std::make_pair(lin->getDomain(i), lin));
    }
  } break;
  case TYPE_LIN: {
    DI_Line L(e->getVertex(0)->x(), e->getVertex(0)->y(), e->getVertex(0)->z(),
              e->getVertex(1)->x(), e->getVertex(1)->y(), e->getVertex(1)->z());
    L.setPolynomialOrder(recur + 1);
    for(std::size_t i = 0; i < e->getNumVertices(); i++)
      nodeLs[i] = &verticesLs(0, e->getVertex(i)->getIndex());
    isCut = L.cut(RPN, ipV, cp, integOrder, lines, recur, nodeLs);

    if(isCut) {
      bool own = (eParent && !e->ownsParent()) ? false : true;
      for(std::size_t i = nbL; i < lines.size(); i++) {
        MVertex *mv[2] = {nullptr, nullptr};
        for(int j = 0; j < 2; j++) {
          int numV = getElementVertexNum(lines[i]->pt(j), e);
          if(numV == -1) {
            MVertex *newv =
              new MVertex(lines[i]->x(j), lines[i]->y(j), lines[i]->z(j));
            auto it = newVertices.insert(newv);
            mv[j] = *(it.first);
            if(!it.second) newv->deleteLast();
          }
          else {
            auto it = vertexMap.find(numV);
            if(it == vertexMap.end()) {
              mv[j] = new MVertex(lines[i]->x(j), lines[i]->y(j),
                                  lines[i]->z(j), nullptr, numV);
              vertexMap[numV] = mv[j];
            }
            else
              mv[j] = it->second;
          }
        }
        MLine *ml;
        int n = (e->getParent() && i == nbL) ? e->getNum() : ++numEle;
        if(eType != MSH_LIN_B)
          ml = new MLineChild(mv[0], mv[1], n, ePart, own, parent);
        else
          ml = new MLineBorder(mv[0], mv[1], n, ePart, copy->getDomain(0),
                               copy->getDomain(1));
        own = false;
        int reg =
          getElementaryTag(lines[i]->lsTag(), elementary, newElemTags[1]);
        int lsTag = lines[i]->lsTag();
        getPhysicalTag(lsTag, gePhysicals, newPhysTags[1]);
        elements[1][reg].push_back(ml);
        assignPhysicals(GM, gePhysicals, reg, 1, physicals, newPhysTags[1],
                        lsTag);
        for(int i = 0; i < 2; i++)
          if(ml->getDomain(i))
            borders[0].insert(std::make_pair(ml->getDomain(i), ml));
      }
      if(eParent) {
        copy->setParent(nullptr, false);
        delete copy;
      }
    }
    else { // no cut
      int lsTag = lines[nbL]->lsTag();
      int reg = getElementaryTag(lsTag, elementary, newElemTags[1]);
      getPhysicalTag(lsTag, gePhysicals, newPhysTags[1]);
      elements[1][reg].push_back(copy);
      assignPhysicals(GM, gePhysicals, reg, 1, physicals, newPhysTags[1],
                      lsTag);
      for(int i = 0; i < 2; i++)
        if(copy->getDomain(i))
          borders[0].insert(std::make_pair(copy->getDomain(i), copy));
    }
  } break;
  case TYPE_PNT: {
    DI_Point P(e->getVertex(0)->x(), e->getVertex(0)->y(),
               e->getVertex(0)->z());
    P.computeLs(RPN.back());
    int lsTag = P.lsTag();
    int reg = getElementaryTag(lsTag, elementary, newElemTags[0]);
    getPhysicalTag(lsTag, gePhysicals, newPhysTags[0]);
    elements[0][reg].push_back(copy);
    assignPhysicals(GM, gePhysicals, reg, 0, physicals, newPhysTags[0], lsTag);
  } break;
  default: Msg::Error("This type of element cannot be cut %d.", eType); break;
  }

  for(std::size_t i = 0; i < ipS.size(); i++) delete ipS[i];
  for(std::size_t i = 0; i < ipV.size(); i++) delete ipV[i];
  delete[] nodeLs;
}

#endif // HAVE_DINTEGRATION

GModel *buildCutMesh(GModel *gm, gLevelset *ls,
                     std::map<int, std::vector<MElement *> > elements[10],
                     std::map<int, MVertex *> &vertexMap,
                     std::map<int, std::map<int, std::string> > physicals[4],
                     bool cutElem)
{
#if defined(HAVE_DINTEGRATION)

  GModel *cutGM = new GModel(gm->getName() + "_cut");
  cutGM->setFileName(cutGM->getName());

  std::vector<GEntity *> gmEntities;
  gm->getEntities(gmEntities);

  std::vector<gLevelset *> primitives;
  ls->getPrimitivesPO(primitives);
  int primS = primitives.size();
  std::vector<gLevelset *> RPN;
  ls->getRPN(RPN);
  int numVert = gm->indexMeshVertices(true);
  int nbLs = (primS > 1) ? primS + 1 : 1;
  fullMatrix<double> verticesLs(nbLs, numVert + 1);

  // compute all at once for ls POINTS (type = 11)
  bool lsPoints = false;
  for(int i = 0; i < primS; i++)
    if(primitives[i]->type() == LSPOINTS) {
      lsPoints = true;
      break;
    }
  if(lsPoints) {
    std::vector<MVertex *> vert;
    for(std::size_t i = 0; i < gmEntities.size(); i++) {
      for(std::size_t j = 0; j < gmEntities[i]->getNumMeshVertices(); j++) {
        vert.push_back(gmEntities[i]->getMeshVertex(j));
      }
    }
    for(int k = 0; k < primS; k++) {
      if(primitives[k]->type() == LSPOINTS) {
        ((gLevelsetPoints *)primitives[k])->computeLS(vert);
      }
    }
  }

  // compute and store levelset values + create new nodes
  for(std::size_t i = 0; i < gmEntities.size(); i++) {
    for(std::size_t j = 0; j < gmEntities[i]->getNumMeshVertices(); j++) {
      MVertex *vi = gmEntities[i]->getMeshVertex(j);
      if(vi->getIndex() < 0) continue;
      int k = 0;
      for(; k < primS; k++)
        verticesLs(k, vi->getIndex()) =
          (*primitives[k])(vi->x(), vi->y(), vi->z());
      if(primS > 1)
        verticesLs(k, vi->getIndex()) = (*ls)(vi->x(), vi->y(), vi->z());

      MVertex *vn =
        new MVertex(vi->x(), vi->y(), vi->z(), nullptr, vi->getNum());
      vertexMap[vi->getNum()] = vn;
    }
  }

  // element number increment
  std::size_t numEle =
    gm->getNumMeshElements() + gm->getNumMeshParentElements();
  for(std::size_t i = 0; i < gmEntities.size(); i++) {
    for(std::size_t j = 0; j < gmEntities[i]->getNumMeshElements(); j++) {
      MElement *e = gmEntities[i]->getMeshElement(j);
      if(e->getNum() > numEle) numEle = e->getNum();
      if(e->getParent())
        if(e->getParent()->getNum() > numEle) numEle = e->getParent()->getNum();
    }
  }

  std::map<int, int> newElemTags[4]; // map<oldElementary,newElementary>[dim]
  std::map<int, int> newPhysTags[4]; // map<oldPhysical,newPhysical>[dim]
  for(int d = 0; d < 4; d++) {
    newElemTags[d][0] = gm->getMaxElementaryNumber(d); // max value at [dim][0]
    newPhysTags[d][0] = gm->getMaxPhysicalNumber(d); // max value at [dim][0]
  }

  std::map<MElement *, MElement *> newParents; // map<oldParent, newParent>
  std::map<MElement *, MElement *> newDomains; // map<oldDomain, newDomain>
  std::map<int, int>
    borderElemTags[2]; // map<lsTag,elementary>[line=0,surface=1]
  std::map<int, int> borderPhysTags[2]; // map<lstag,physical>[line=0,surface=1]

  // SplitMesh
  if(!cutElem) {
    for(std::size_t i = 0; i < gmEntities.size(); i++) {
      for(std::size_t j = 0; j < gmEntities[i]->getNumMeshElements(); j++) {
        MElement *e = gmEntities[i]->getMeshElement(j);
        e->setVolumePositive();
        elementSplitMesh(e, RPN, verticesLs, gmEntities[i], gm, numEle,
                         vertexMap, newParents, newDomains, elements, physicals,
                         newElemTags, newPhysTags, borderElemTags,
                         borderPhysTags);
        if(e->getPartition() > static_cast<int>(cutGM->getNumPartitions())) {
          cutGM->setNumPartitions(e->getPartition());
        }
      }
    }
    return cutGM;
  }

  // CutMesh
  newVerticesContainer newVertices;
  // multimap<domain,border>[polyg=0,polyh=1]
  std::multimap<MElement *, MElement *> borders[2];
  DI_Point::Container cp;
  std::vector<DI_Line *> lines;
  std::vector<DI_Triangle *> triangles;
  std::vector<DI_Quad *> quads;
  std::vector<DI_Tetra *> tetras;
  std::vector<DI_Hexa *> hexas;
  std::vector<int> lsLineRegs;
  for(std::size_t i = 0; i < gmEntities.size(); i++) {
    std::vector<int> oldLineRegs;
    for(auto it = elements[1].begin(); it != elements[1].end(); it++)
      oldLineRegs.push_back(it->first);
    int nbBorders = borders[0].size();
    for(std::size_t j = 0; j < gmEntities[i]->getNumMeshElements(); j++) {
      MElement *e = gmEntities[i]->getMeshElement(j);
      e->setVolumePositive();
      elementCutMesh(e, RPN, verticesLs, gmEntities[i], gm, numEle, vertexMap,
                     newVertices, newParents, newDomains, borders, elements,
                     physicals, newElemTags, newPhysTags, borderElemTags,
                     borderPhysTags, cp, lines, triangles, quads, tetras,
                     hexas);
      if(e->getPartition() > static_cast<int>(cutGM->getNumPartitions())) {
        cutGM->setNumPartitions(e->getPartition());
      }
    }

    // Create elementary and physical for non connected border lines
    if((int)borders[0].size() > nbBorders && gmEntities[i]->dim() == 2 &&
       i == gm->getNumVertices() + gm->getNumEdges() + gm->getNumFaces() - 1) {
      int k = 0;
      for(auto it = elements[1].begin(); it != elements[1].end(); it++) {
        if(oldLineRegs.size() && it->first == oldLineRegs[k])
          k++;
        else
          lsLineRegs.push_back(it->first);
      }
      for(std::size_t j = 0; j < lsLineRegs.size(); j++) {
        int nLR = lsLineRegs[j];
        bool havePhys = physicals[1][nLR].size();
        while(1) {
          std::vector<MElement *> conLines;
          conLines.push_back(elements[1][nLR][0]);
          elements[1][nLR].erase(elements[1][nLR].begin());
          MVertex *v1 = conLines[0]->getVertex(0);
          MVertex *v2 = conLines[0]->getVertex(1);
          for(std::size_t k = 0; k < elements[1][nLR].size();) {
            MVertex *va = elements[1][nLR][k]->getVertex(0);
            MVertex *vb = elements[1][nLR][k]->getVertex(1);
            if(va == v1 || vb == v1 || va == v2 || vb == v2) {
              conLines.push_back(elements[1][nLR][k]);
              elements[1][nLR].erase(elements[1][nLR].begin() + k);
              if(v1 == va)
                v1 = vb;
              else if(v1 == vb)
                v1 = va;
              else if(v2 == va)
                v2 = vb;
              else if(v2 == vb)
                v2 = va;
              k = 0;
            }
            else
              k++;
          }
          if(!elements[1][nLR].empty()) {
            int newReg = ++newElemTags[1][0];
            int newPhys = (!havePhys) ? 0 : ++newPhysTags[1][0];
            if(newPhys)
              assignLsPhysical(gm, newReg, 1, physicals, newPhys,
                               lines[lines.size() - 1]->lsTag());
            for(std::size_t k = 0; k < conLines.size(); k++)
              elements[1][newReg].push_back(conLines[k]);
          }
          else {
            for(std::size_t k = 0; k < conLines.size(); k++)
              elements[1][nLR].push_back(conLines[k]);
            break;
          }
        }
      }
    }

    for(auto it = cp.begin(); it != cp.end(); it++) delete *it;
    for(std::size_t k = 0; k < lines.size(); k++) delete lines[k];
    for(std::size_t k = 0; k < triangles.size(); k++) delete triangles[k];
    for(std::size_t k = 0; k < quads.size(); k++) delete quads[k];
    for(std::size_t k = 0; k < tetras.size(); k++) delete tetras[k];
    for(std::size_t k = 0; k < hexas.size(); k++) delete hexas[k];
    cp.clear();
    lines.clear();
    triangles.clear();
    quads.clear();
    tetras.clear();
    hexas.clear();
  }

#if 0
  int numElements = 0;
  for(int i = 0; i < 10; i++) {
    printf(" - element type : %d\n", i);
    for(auto it = elements[i].begin(); it != elements[i].end(); it++){
      printf(" elementary : %d\n",it->first);
      for(std::size_t j = 0; j < it->second.size(); j++){
        MElement *e = it->second[j];
        printf("element %d",e->getNum());
        if(e->getParent()) printf(" par=%d (%d)",e->getParent()->getNum(),e->ownsParent());
        if(e->getDomain(0)) printf(" d0=%d",e->getDomain(0)->getNum());
        if(e->getDomain(1)) printf(" d1=%d",e->getDomain(1)->getNum());
        printf("\n"); numElements++;
      }
    }
  }
  printf("PHYS\n");
  for(int i = 0; i < 4; i++)
    for(auto it = physicals[i].begin(); it != physicals[i].end(); it++)
      for(auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
        printf(" dim=%d reg=%d phys=%d \"%s\"\n", i, it->first, it2->first,
               it2->second.c_str());
  printf("new Model : %d elements %d nodes\n\n", numElements, vertexMap.size());
#endif

  for(auto it = newVertices.begin(); it != newVertices.end(); ++it) {
    vertexMap[(*it)->getNum()] = *it;
  }

  return cutGM;
#else
  Msg::Error("Gmsh need to be compiled with levelset support to cut mesh");
  return 0;
#endif
}
