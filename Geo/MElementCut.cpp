// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <stdlib.h>
#include "GmshConfig.h"
#include "GModel.h"
#include "MElement.h"
#include "MElementCut.h"

#if defined(HAVE_DINTEGRATION)
#include "DILevelset.h"
#include "Integration3D.h"
#endif

//---------------------------------------- MPolyhedron ----------------------------

void MPolyhedron::_init()
{
  if(_parts.size() == 0) return;

  for(unsigned int i = 0; i < _parts.size(); i++) {
    if(_parts[i]->getVolume() * _parts[0]->getVolume() < 0.)
      _parts[i]->revert();
    for(int j = 0; j < 4; j++) {
      int k;
      for(k = _faces.size() - 1; k >= 0; k--)
        if(_parts[i]->getFace(j) == _faces[k])
          break;
      if(k < 0)
        _faces.push_back(_parts[i]->getFace(j));
      else
        _faces.erase(_faces.begin() + k);
    }
    if(_parts.size() < 4) { // No interior vertex
      for(int j = 0; j < 6; j++) {
        int k;
        for(k = _edges.size() - 1; k >= 0; k--)
          if(_parts[i]->getEdge(j) == _edges[k])
            break;
        if(k < 0)
          _edges.push_back(_parts[i]->getEdge(j));
      }
      for(int j = 0; j < 4; j++) {
        int k;
        for(k = _vertices.size() - 1; k >= 0; k--)
          if(_parts[i]->getVertex(j) == _vertices[k])
            break;
        if(k < 0)
          _vertices.push_back(_parts[i]->getVertex(j));
      }
    }
  }

  if(_parts.size() >= 4) {
    for(unsigned int i = 0; i < _faces.size(); i++) {
      for(int j = 0; j < 3; j++) {
        int k;
        for(k = _edges.size() - 1; k >= 0; k--)
          if(_faces[i].getEdge(j) == _edges[k])
            break;
        if(k < 0)
          _edges.push_back(_faces[i].getEdge(j));
      }
      for(int j = 0; j < 3; j++) {
        int k;
        for(k = _vertices.size() - 1; k >= 0; k--)
          if(_faces[i].getVertex(j) == _vertices[k])
            break;
        if(k < 0)
          _vertices.push_back(_faces[i].getVertex(j));
      }
    }
  }

  // innerVertices
  for(unsigned int i = 0; i < _parts.size(); i++) {
    for(int j = 0; j < 4; j++) {
      if(std::find(_vertices.begin(), _vertices.end(), _parts[i]->getVertex(j)) == _vertices.end())
        _innerVertices.push_back(_parts[i]->getVertex(j));
    }
  }

}

bool MPolyhedron::isInside(double u, double v, double w)
{
  double uvw[3] = {u, v, w};
  for(unsigned int i = 0; i < _parts.size(); i++) {
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
    if(t.isInside(ksi[0], ksi[1], ksi[2]))
      return true;
  }
  return false;
}

void MPolyhedron::getIntegrationPoints(int pOrder, int *npts, IntPt **pts)
{
  *npts = 0;
  double jac[3][3];
  if(_intpt) delete [] _intpt;
  _intpt = new IntPt[getNGQTetPts(pOrder) * _parts.size()];
  for(unsigned int i = 0; i < _parts.size(); i++) {
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

    for(int ip = 0; ip < nptsi; ip++){
      const double u = ptsi[ip].pt[0];
      const double v = ptsi[ip].pt[1];
      const double w = ptsi[ip].pt[2];
      const double weight = ptsi[ip].weight;
      const double detJ = tt.getJacobian(u, v, w, jac);
      SPoint3 p; tt.pnt(u, v, w, p);
      _intpt[*npts + ip].pt[0] = p.x();
      _intpt[*npts + ip].pt[1] = p.y();
      _intpt[*npts + ip].pt[2] = p.z();
      _intpt[*npts + ip].weight = detJ * weight;
    }
    *npts += nptsi;
  }
  *pts = _intpt;
}

//------------------------------------------- MPolygon ------------------------------

void MPolygon::_initVertices()
{
  if(_parts.size() == 0) return;

  // reorient the parts
  SVector3 n;
  if(_orig) n = _orig->getFace(0).normal();
  else n = _parts[0]->getFace(0).normal();
  for(unsigned int i = 0; i < _parts.size(); i++) {
    SVector3 ni = _parts[i]->getFace(0).normal();
    if(dot(n, ni) < 0.) _parts[i]->revert();
  }

  std::vector<MEdge> edg;
  for(unsigned int i = 0; i < _parts.size(); i++) {
    for(int j = 0; j < 3; j++) {
      int k;
      for(k = edg.size() - 1; k >= 0; k--)
        if(_parts[i]->getEdge(j) == edg[k])
          break;
      if(k < 0)
        edg.push_back(_parts[i]->getEdge(j));
      else
        edg.erase(edg.begin() + k);
    }
  }

  // organize edges to get vertices in rotating order
  _edges.push_back(edg[0]);
  edg.erase(edg.begin());
  while(edg.size()) {
    for(unsigned int i = 0; i < edg.size(); i++) {
      MVertex *v = _edges[_edges.size() - 1].getVertex(1);
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
    }
  }

  for(unsigned int i = 0; i < _edges.size(); i++) {
    _vertices.push_back(_edges[i].getVertex(0));
  }

  // innerVertices
  for(unsigned int i = 0; i < _parts.size(); i++) {
    for(int j = 0; j < 3; j++) {
      if(std::find(_vertices.begin(), _vertices.end(), _parts[i]->getVertex(j)) == _vertices.end())
        _innerVertices.push_back(_parts[i]->getVertex(j));
    }
  }
}
bool MPolygon::isInside(double u, double v, double w)
{
  double uvw[3] = {u, v, w};
  for(unsigned int i = 0; i < _parts.size(); i++) {
    double v_uvw[3][3];
    for(int j = 0; j < 3; j++) {
      MVertex *vij = _parts[i]->getVertex(j);
      double v_xyz[3] = {vij->x(), vij->y(), vij->z()};
      _orig->xyz2uvw(v_xyz, v_uvw[j]);
    }
    MVertex v0(v_uvw[0][0], v_uvw[0][1], v_uvw[0][2]);
    MVertex v1(v_uvw[1][0], v_uvw[1][1], v_uvw[1][2]);
    MVertex v2(v_uvw[2][0], v_uvw[2][1], v_uvw[2][2]);
    MTriangle t(&v0, &v1, &v2);
    double ksi[3];
    t.xyz2uvw(uvw, ksi);
    if(t.isInside(ksi[0], ksi[1], ksi[2]))
      return true;
  }
  return false;
}

void MPolygon::getIntegrationPoints(int pOrder, int *npts, IntPt **pts)
{
  *npts = 0;
  double jac[3][3];
  if(_intpt) delete [] _intpt;
  _intpt = new IntPt[getNGQTPts(pOrder) * _parts.size()];
  for(unsigned int i = 0; i < _parts.size(); i++) {
    int nptsi;
    IntPt *ptsi;
    _parts[i]->getIntegrationPoints(pOrder, &nptsi, &ptsi);
    double uvw[3][3];
    for(int j = 0; j < 3; j++) {
      double xyz[3] = {_parts[i]->getVertex(j)->x(), _parts[i]->getVertex(j)->y(),
                       _parts[i]->getVertex(j)->z()};
      _orig->xyz2uvw(xyz, uvw[j]);
    }
    MVertex v0(uvw[0][0], uvw[0][1], uvw[0][2]);
    MVertex v1(uvw[1][0], uvw[1][1], uvw[1][2]);
    MVertex v2(uvw[2][0], uvw[2][1], uvw[2][2]);
    MTriangle tt(&v0, &v1, &v2);
    for(int ip = 0; ip < nptsi; ip++){
      const double u = ptsi[ip].pt[0];
      const double v = ptsi[ip].pt[1];
      const double w = ptsi[ip].pt[2];
      const double weight = ptsi[ip].weight;
      const double detJ = tt.getJacobian(u, v, w, jac);
      SPoint3 p; tt.pnt(u, v, w, p);
      _intpt[*npts + ip].pt[0] = p.x();
      _intpt[*npts + ip].pt[1] = p.y();
      _intpt[*npts + ip].pt[2] = p.z();
      _intpt[*npts + ip].weight = detJ * weight;
    }
    *npts += nptsi;
  }
  *pts = _intpt;
}

//----------------------------------- MLineChild ------------------------------

bool MLineChild::isInside(double u, double v, double w)
{
  double uvw[3] = {u, v, w};
  double v_uvw[2][3];
  for(int i = 0; i < 2; i++) {
    MVertex *vi = getVertex(i);
    double v_xyz[3] = {vi->x(), vi->y(), vi->z()};
    _orig->xyz2uvw(v_xyz, v_uvw[i]);
  }
  MVertex v0(v_uvw[0][0], v_uvw[0][1], v_uvw[0][2]);
  MVertex v1(v_uvw[1][0], v_uvw[1][1], v_uvw[1][2]);
  MLine l(&v0, &v1);
  double ksi[3];
  l.xyz2uvw(uvw, ksi);
  if(l.isInside(ksi[0], ksi[1], ksi[2]))
    return true;
  return false;
}

void MLineChild::getIntegrationPoints(int pOrder, int *npts, IntPt **pts)
{
  *npts = 0;
  double jac[3][3];
  if(_intpt) delete [] _intpt;
  _intpt = new IntPt[getNGQLPts(pOrder)];

  int nptsi;
  IntPt *ptsi;
  double v_uvw[2][3];

// -------------before--------------------//

//  for(int i = 0; i < 2; i++) {
//    MVertex *vi = getVertex(i);
//    double v_xyz[3] = {vi->x(), vi->y(), vi->z()};
//    _orig->xyz2uvw(v_xyz, v_uvw[i]);
//  }

//  -----------mich mach---------------------//


  MVertex *vo = _orig->getVertex(0);
  MVertex *vf = _orig->getVertex(1);

  SPoint3 P(vo->x(), vo->y(), vo->z());
  SPoint3 Q(vf->x(), vf->y(), vf->z());

  SPoint3 R;

  R = P + Q;
  R/=2;

  vo = getVertex(0);
  vf = getVertex(1);

  SPoint3 A(vo->x(), vo->y(), vo->z());
  SPoint3 B(vf->x(), vf->y(), vf->z());

  double lengthDemi = R.distance(Q);

  if (P.distance(A) < Q.distance(A)) {v_uvw[0][0] = - R.distance(A)/lengthDemi;v_uvw[0][1]=0;v_uvw[0][2]=0;}
  else {v_uvw[0][0] = R.distance(A)/lengthDemi;v_uvw[0][1]=0;v_uvw[0][2]=0;}

  if (P.distance(B) < Q.distance(B)) {v_uvw[1][0] = - R.distance(B)/lengthDemi;v_uvw[1][1]=0;v_uvw[1][2]=0;}
  else {v_uvw[1][0] = R.distance(B)/lengthDemi;v_uvw[1][1]=0;v_uvw[1][2]=0;}

//  ---------------------------------------//

  MVertex v0(v_uvw[0][0], v_uvw[0][1], v_uvw[0][2]);
  MVertex v1(v_uvw[1][0], v_uvw[1][1], v_uvw[1][2]);

  MLine l(&v0, &v1);
  l.getIntegrationPoints(pOrder, &nptsi, &ptsi);

  for(int ip = 0; ip < nptsi; ip++){
    const double u = ptsi[ip].pt[0];
    const double v = ptsi[ip].pt[1];
    const double w = ptsi[ip].pt[2];
    const double weight = ptsi[ip].weight;
    const double detJ = l.getJacobian(u, v, w, jac);
    SPoint3 p; l.pnt(u, v, w, p);
    _intpt[*npts + ip].pt[0] = p.x();
    _intpt[*npts + ip].pt[1] = p.y();
    _intpt[*npts + ip].pt[2] = p.z();
    _intpt[*npts + ip].weight = detJ * weight;
  }
  *npts = nptsi;
  *pts = _intpt;

}

//----------------------------------- MTriangleBorder ------------------------------

void MTriangleBorder::getIntegrationPoints(int pOrder, int *npts, IntPt **pts)
{
  *npts = 0;
  if(_intpt) delete [] _intpt;
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
  for(int ip = 0; ip < nptsi; ip++){
    const double u = ptsi[ip].pt[0];
    const double v = ptsi[ip].pt[1];
    const double w = ptsi[ip].pt[2];
    const double weight = ptsi[ip].weight;
    //const double detJ =
    tt.getJacobian(u, v, w, jac);
    SPoint3 p; tt.pnt(u, v, w, p);
    _intpt[ip].pt[0] = p.x();
    _intpt[ip].pt[1] = p.y();
    _intpt[ip].pt[2] = p.z();
    _intpt[ip].weight = weight;//detJ * weight;
  }
  *npts = nptsi;
  *pts = _intpt;
}

//----------------------------------- MPolygonBorder ------------------------------

void MPolygonBorder::getIntegrationPoints(int pOrder, int *npts, IntPt **pts)
{
  *npts = 0;
  if(_intpt) delete [] _intpt;
  _intpt = new IntPt[getNGQTPts(pOrder) * _parts.size()];
  int nptsi;
  IntPt *ptsi;

  std::vector<MVertex*> verts;
  for(unsigned int i = 0; i < _parts.size(); i++) {
    double uvw[3][3];
    for(int j = 0; j < 3; j++) {
      MVertex *v = _parts[i]->getVertex(j);
      double xyz[3] = {v->x(), v->y(), v->z()};
      getParent()->xyz2uvw(xyz, uvw[j]);
    }
    verts.push_back(new MVertex(uvw[0][0], uvw[0][1], uvw[0][2]));
    verts.push_back(new MVertex(uvw[1][0], uvw[1][1], uvw[1][2]));
    verts.push_back(new MVertex(uvw[2][0], uvw[2][1], uvw[2][2]));
  }
  MPolygon pp(verts);
  pp.getIntegrationPoints(pOrder, &nptsi, &ptsi);
  double jac[3][3];
  for(int ip = 0; ip < nptsi; ip++){
    const double u = ptsi[ip].pt[0];
    const double v = ptsi[ip].pt[1];
    const double w = ptsi[ip].pt[2];
    const double weight = ptsi[ip].weight;
    //const double detJ =
    pp.getJacobian(u, v, w, jac);
    SPoint3 p; pp.pnt(u, v, w, p);
    _intpt[ip].pt[0] = p.x();
    _intpt[ip].pt[1] = p.y();
    _intpt[ip].pt[2] = p.z();
    _intpt[ip].weight = weight;//detJ * weight;
  }
  *npts = nptsi;
  *pts = _intpt;
  for(unsigned int i = 0; i < verts.size(); i++)
    delete verts[i];
}

//-------------------------------------- MLineBorder ------------------------------

void MLineBorder::getIntegrationPoints(int pOrder, int *npts, IntPt **pts)
{
  *npts = 0;
  if(_intpt) delete [] _intpt;
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
  double jac[3][3];
  for(int ip = 0; ip < nptsi; ip++){
    const double u = ptsi[ip].pt[0];
    const double v = ptsi[ip].pt[1];
    const double w = ptsi[ip].pt[2];
    const double weight = ptsi[ip].weight;
    //const double detJ =
    ll.getJacobian(u, v, w, jac);
    SPoint3 p; ll.pnt(u, v, w, p);
    _intpt[ip].pt[0] = p.x();
    _intpt[ip].pt[1] = p.y();
    _intpt[ip].pt[2] = p.z();
    _intpt[ip].weight = weight;//detJ * weight;
  }
  *npts = nptsi;
  *pts = _intpt;
}

//---------------------------------------- CutMesh ----------------------------

static void assignPhysicals(GModel *GM, std::vector<int> &gePhysicals, int reg, int dim,
                            std::map<int, std::map<int, std::string> > physicals[4])
{
  for(unsigned int i = 0; i < gePhysicals.size(); i++){
    int phys = gePhysicals[i];
    if(phys && (!physicals[dim].count(reg) || !physicals[dim][reg].count(phys)))
      physicals[dim][reg][phys] = GM->getPhysicalName(dim, phys);
  }
}

static int getElementaryTag(int lsTag, int elementary, std::map<int, int> &newElemTags)
{
  if(lsTag < 0){
    if(newElemTags.count(elementary))
      return newElemTags[elementary];
    else{
      int reg = ++newElemTags[0];
      newElemTags[elementary] = reg;
      return reg;
    }
  }
  return elementary;
}
static void getPhysicalTag(int lsTag, const std::vector<int> &physicals,
                           std::vector<int> &phys2, std::map<int, int> &newPhysTags)
{
  phys2.clear();
  for(unsigned int i = 0; i < physicals.size(); i++){
    int phys = physicals[i];
    if(lsTag < 0){
      if(!newPhysTags.count(phys))
        newPhysTags[phys] = ++newPhysTags[0];
      phys = newPhysTags[phys];
    }
    phys2.push_back(phys);
  }
}

static int getBorderTag(int lsTag, int count, int &maxTag, std::map<int, int> &borderTags)
{
  if(borderTags.count(lsTag))
    return borderTags[lsTag];
  if(count) {
    int tag = ++maxTag;
    borderTags[lsTag] = tag;
    return tag;
  }
  maxTag = std::max(maxTag, lsTag);
  borderTags[lsTag] = lsTag;
  return lsTag;
}

static void elementSplitMesh(MElement *e, fullMatrix<double> &verticesLs,
                             GEntity *ge, GModel *GM, int &numEle,
                             std::map<int, MVertex*> &vertexMap,
                             std::map<MElement*, MElement*> &newParents,
                             std::map<MElement*, MElement*> &newDomains,
                             std::map<int, std::vector<MElement*> > elements[10],
                             std::map<int, std::map<int, std::string> > physicals[4],
                             std::map<int, int> newElemTags[4],
                             std::map<int, int> newPhysTags[4])
{
  int elementary = ge->tag();
  int eType = e->getTypeForMSH();
  std::vector<int> gePhysicals = ge->physicals;

  MElement *copy = e->copy(numEle, vertexMap, newParents, newDomains);

  double lsMean = 0.;
  for(int k = 0; k < e->getNumVertices(); k++)
    lsMean += verticesLs(e->getVertex(k)->getIndex(), 0);
  int lsTag = (lsMean < 0) ? 1 : -1;

  switch (eType) {
  case MSH_TET_4 :
  case MSH_HEX_8 :
  case MSH_PYR_5 :
  case MSH_PRI_6 :
  case MSH_POLYH_ :
    {
      int reg = getElementaryTag(lsTag, elementary, newElemTags[3]);
      std::vector<int> phys;
      getPhysicalTag(lsTag, gePhysicals, phys, newPhysTags[3]);
      if(eType == MSH_TET_4)
        elements[4][reg].push_back(copy);
      else if(eType == MSH_HEX_8)
        elements[5][reg].push_back(copy);
      else if(eType == MSH_PRI_6)
        elements[6][reg].push_back(copy);
      else if(eType == MSH_PYR_5)
        elements[7][reg].push_back(copy);
      else if(eType == MSH_POLYH_)
        elements[9][reg].push_back(copy);
      assignPhysicals(GM, phys, reg, 3, physicals);
    }
    break;
  case MSH_TRI_3 :
  case MSH_QUA_4 :
  case MSH_POLYG_ :
  case MSH_POLYG_B :
    {
      int reg = getElementaryTag(lsTag, elementary, newElemTags[2]);
      std::vector<int> phys;
      getPhysicalTag(lsTag, gePhysicals, phys, newPhysTags[2]);
      if(eType == MSH_TRI_3)
        elements[2][reg].push_back(copy);
      else if(eType == MSH_QUA_4)
        elements[3][reg].push_back(copy);
      else if(eType == MSH_POLYG_ || eType == MSH_POLYG_B)
        elements[8][reg].push_back(copy);
      assignPhysicals(GM, phys, reg, 2, physicals);
    }
    break;
  case MSH_LIN_2 :
  case MSH_LIN_B :
    {
      int reg = getElementaryTag(lsTag, elementary, newElemTags[1]);
      std::vector<int> phys;
      getPhysicalTag(lsTag, gePhysicals, phys, newPhysTags[1]);
      elements[1][reg].push_back(copy);
      assignPhysicals(GM, phys, reg, 1, physicals);
    }
    break;
  case MSH_PNT :
    {
      int reg = getElementaryTag(lsTag, elementary, newElemTags[0]);
      std::vector<int> phys;
      getPhysicalTag(lsTag, gePhysicals, phys, newPhysTags[0]);
      elements[0][reg].push_back(copy);
      assignPhysicals(GM, phys, reg, 0, physicals);
    }
    break;
  default :
    Msg::Error("This type of element cannot be split.");
    return;
  }
}

#if defined(HAVE_DINTEGRATION)

static bool equalV(MVertex *v, const DI_Point *p)
{
  return (fabs(v->x() - p->x()) < 1.e-15 &&
          fabs(v->y() - p->y()) < 1.e-15 &&
          fabs(v->z() - p->z()) < 1.e-15);
}

static int getElementVertexNum(DI_Point *p, MElement *e)
{
  for(int i = 0; i < e->getNumVertices(); i++)
    if(equalV(e->getVertex(i), p))
      return e->getVertex(i)->getNum();
  return -1;
}

typedef std::set<MVertex*, MVertexLessThanLexicographic> newVerticesContainer;

static void elementCutMesh(MElement *e, std::vector<const gLevelset *> &RPN,
                           fullMatrix<double> &verticesLs,
                           GEntity *ge, GModel *GM, int &numEle,
                           std::map<int, MVertex*> &vertexMap,
                           newVerticesContainer &newVertices,
                           std::map<MElement*, MElement*> &newParents,
                           std::map<MElement*, MElement*> &newDomains,
                           std::multimap<MElement*, MElement*> borders[2],
                           std::map<int, std::vector<MElement*> > elements[10],
                           std::map<int, std::map<int, std::string> > physicals[4],
                           std::map<int, int> newElemTags[4],
                           std::map<int, int> newPhysTags[4],
                           std::map<int, int> borderElemTags[2],
                           std::map<int, int> borderPhysTags[2],
                           DI_Point::Container &cp,
                           std::vector<DI_Line *> &lines,
                           std::vector<DI_Triangle *> &triangles,
                           std::vector<DI_Quad *> &quads,
                           std::vector<DI_Tetra *> &tetras,
                           std::vector<DI_Hexa *> &hexas)
{
  int elementary = ge->tag();
  int eType = e->getTypeForMSH();
  int ePart = e->getPartition();
  MElement *eParent = e->getParent();
  std::vector<int> gePhysicals = ge->physicals;

  int integOrder = 1;
  std::vector<DI_IntegrationPoint *> ipV;
  std::vector<DI_IntegrationPoint *> ipS;
  bool isCut = false;
  unsigned int nbL = lines.size();
  unsigned int nbTr = triangles.size();
  unsigned int nbTe = tetras.size();

  MElement *copy = e->copy(numEle, vertexMap, newParents, newDomains);
  MElement *parent = eParent ? copy->getParent() : copy;

  double **nodeLs = new double*[e->getNumPrimaryVertices()];

  switch (eType) {
  case MSH_TET_4 :
  case MSH_HEX_8 :
  case MSH_PYR_5 :
  case MSH_PRI_6 :
  case MSH_POLYH_ :
    {
      if(eType == MSH_TET_4) {
        DI_Tetra T(e->getVertex(0)->x(), e->getVertex(0)->y(), e->getVertex(0)->z(),
                   e->getVertex(1)->x(), e->getVertex(1)->y(), e->getVertex(1)->z(),
                   e->getVertex(2)->x(), e->getVertex(2)->y(), e->getVertex(2)->z(),
                   e->getVertex(3)->x(), e->getVertex(3)->y(), e->getVertex(3)->z());
        for(int i = 0; i < 4; i++) nodeLs[i] = &verticesLs(e->getVertex(i)->getIndex(),0);
        isCut = T.cut(RPN, ipV, ipS, cp, integOrder, integOrder, integOrder,
                      tetras, quads, triangles, 0, nodeLs);
      }
      else if(eType == MSH_HEX_8){
        DI_Hexa H(e->getVertex(0)->x(), e->getVertex(0)->y(), e->getVertex(0)->z(),
                  e->getVertex(1)->x(), e->getVertex(1)->y(), e->getVertex(1)->z(),
                  e->getVertex(2)->x(), e->getVertex(2)->y(), e->getVertex(2)->z(),
                  e->getVertex(3)->x(), e->getVertex(3)->y(), e->getVertex(3)->z(),
                  e->getVertex(4)->x(), e->getVertex(4)->y(), e->getVertex(4)->z(),
                  e->getVertex(5)->x(), e->getVertex(5)->y(), e->getVertex(5)->z(),
                  e->getVertex(6)->x(), e->getVertex(6)->y(), e->getVertex(6)->z(),
                  e->getVertex(7)->x(), e->getVertex(7)->y(), e->getVertex(7)->z());
        for(int i = 0; i < 8; i++) nodeLs[i] = &verticesLs(e->getVertex(i)->getIndex(),0);
        isCut = H.cut(RPN, ipV, ipS, cp, integOrder, integOrder, integOrder, integOrder,
                      hexas, tetras, quads, triangles, lines, 0, nodeLs);
      }
      else if(eType == MSH_PRI_6){
        DI_Tetra T1(e->getVertex(0)->x(), e->getVertex(0)->y(), e->getVertex(0)->z(),
                    e->getVertex(1)->x(), e->getVertex(1)->y(), e->getVertex(1)->z(),
                    e->getVertex(2)->x(), e->getVertex(2)->y(), e->getVertex(2)->z(),
                    e->getVertex(5)->x(), e->getVertex(5)->y(), e->getVertex(5)->z());
        for(int i = 0; i < 3; i++) nodeLs[i] = &verticesLs(e->getVertex(i)->getIndex(),0);
        nodeLs[3] = &verticesLs(e->getVertex(5)->getIndex(),0);
        bool iC1 = T1.cut(RPN, ipV, ipS, cp, integOrder, integOrder, integOrder,
                          tetras, quads, triangles, 0, nodeLs);
        DI_Tetra T2(e->getVertex(0)->x(), e->getVertex(0)->y(), e->getVertex(0)->z(),
                    e->getVertex(4)->x(), e->getVertex(4)->y(), e->getVertex(4)->z(),
                    e->getVertex(1)->x(), e->getVertex(1)->y(), e->getVertex(1)->z(),
                    e->getVertex(5)->x(), e->getVertex(5)->y(), e->getVertex(5)->z());
        nodeLs[0] = &verticesLs(e->getVertex(0)->getIndex(),0);
        nodeLs[1] = &verticesLs(e->getVertex(4)->getIndex(),0);
        nodeLs[2] = &verticesLs(e->getVertex(1)->getIndex(),0);
        nodeLs[3] = &verticesLs(e->getVertex(5)->getIndex(),0);
        bool iC2 = T2.cut(RPN, ipV, ipS, cp, integOrder, integOrder, integOrder,
                          tetras, quads, triangles, 0, nodeLs);
        DI_Tetra T3(e->getVertex(0)->x(), e->getVertex(0)->y(), e->getVertex(0)->z(),
                    e->getVertex(3)->x(), e->getVertex(3)->y(), e->getVertex(3)->z(),
                    e->getVertex(4)->x(), e->getVertex(4)->y(), e->getVertex(4)->z(),
                    e->getVertex(5)->x(), e->getVertex(5)->y(), e->getVertex(5)->z());
        for(int i = 1; i < 4; i++) nodeLs[i] = &verticesLs(e->getVertex(i+2)->getIndex(),0);
        bool iC3 = T3.cut(RPN, ipV, ipS, cp, integOrder, integOrder, integOrder,
                          tetras, quads, triangles, 0, nodeLs);
        isCut = iC1 || iC2 || iC3;
      }
      else if(eType == MSH_PYR_5){
        DI_Tetra T1(e->getVertex(0)->x(), e->getVertex(0)->y(), e->getVertex(0)->z(),
                    e->getVertex(1)->x(), e->getVertex(1)->y(), e->getVertex(1)->z(),
                    e->getVertex(2)->x(), e->getVertex(2)->y(), e->getVertex(2)->z(),
                    e->getVertex(4)->x(), e->getVertex(4)->y(), e->getVertex(4)->z());
        for(int i = 0; i < 3; i++) nodeLs[i] = &verticesLs(e->getVertex(i)->getIndex(),0);
        nodeLs[3] = &verticesLs(e->getVertex(4)->getIndex(),0);
        bool iC1 = T1.cut(RPN, ipV, ipS, cp, integOrder, integOrder, integOrder,
                          tetras, quads, triangles, 0, nodeLs);
        DI_Tetra T2(e->getVertex(0)->x(), e->getVertex(0)->y(), e->getVertex(0)->z(),
                    e->getVertex(2)->x(), e->getVertex(2)->y(), e->getVertex(2)->z(),
                    e->getVertex(3)->x(), e->getVertex(3)->y(), e->getVertex(3)->z(),
                    e->getVertex(4)->x(), e->getVertex(4)->y(), e->getVertex(4)->z());
        nodeLs[0] = &verticesLs(e->getVertex(0)->getIndex(),0);
        for(int i = 1; i < 4; i++) nodeLs[i] = &verticesLs(e->getVertex(i+1)->getIndex(),0);
        bool iC2 = T2.cut(RPN, ipV, ipS, cp, integOrder, integOrder, integOrder,
                          tetras, quads, triangles, 0, nodeLs);
        isCut = iC1 || iC2;
      }
      else if(eType == MSH_POLYH_){
        for(int i = 0; i < e->getNumChildren(); i++) {
          MTetrahedron *t = (MTetrahedron*) e->getChild(i);
          DI_Tetra Tet(t->getVertex(0)->x(), t->getVertex(0)->y(), t->getVertex(0)->z(),
                       t->getVertex(1)->x(), t->getVertex(1)->y(), t->getVertex(1)->z(),
                       t->getVertex(2)->x(), t->getVertex(2)->y(), t->getVertex(2)->z(),
                       t->getVertex(3)->x(), t->getVertex(3)->y(), t->getVertex(3)->z());
          for(int i = 0; i < 4; i++) nodeLs[i] = &verticesLs(t->getVertex(i)->getIndex(),0);
          bool iC = Tet.cut(RPN, ipV, ipS, cp, integOrder, integOrder, integOrder,
                            tetras, quads, triangles, 0, nodeLs);
          isCut = (isCut || iC);
        }
      }

      MPolyhedron *p1 = NULL, *p2 = NULL;
      if(isCut) {
        std::vector<MTetrahedron*> poly[2];

        for (unsigned int i = nbTe; i < tetras.size(); i++){
          MVertex *mv[4] = {NULL, NULL, NULL, NULL};
          for(int j = 0; j < 4; j++){
            int numV = getElementVertexNum(tetras[i]->pt(j), e);
            if (numV == -1){
              MVertex *newv = new MVertex(tetras[i]->x(j), tetras[i]->y(j), tetras[i]->z(j));
              std::pair<newVerticesContainer::iterator, bool> it = newVertices.insert(newv);
              mv[j] = *(it.first);
              if (!it.second) newv->deleteLast();
            }
            else {
              std::map<int, MVertex*>::iterator it = vertexMap.find(numV);
              if(it == vertexMap.end()) {
                mv[j] = new MVertex(tetras[i]->x(j), tetras[i]->y(j),
                                    tetras[i]->z(j), 0, numV);
                vertexMap[numV] = mv[j];
              }
              else mv[j] = it->second;
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
          p1 = new MPolyhedron(poly[0], ++numEle, ePart, own, parent);
          own = false;
          int reg = getElementaryTag(-1, elementary, newElemTags[3]);
          std::vector<int> phys;
          getPhysicalTag(-1, gePhysicals, phys, newPhysTags[3]);
          elements[9][reg].push_back(p1);
          assignPhysicals(GM, phys, reg, 3, physicals);
        }
        if(poly[1].size()) {
          p2 = new MPolyhedron(poly[1], ++numEle, ePart, own, parent);
          elements[9][elementary].push_back(p2);
          assignPhysicals(GM, gePhysicals, elementary, 3, physicals);
        }
        std::pair<std::multimap<MElement*, MElement*>::iterator,
                  std::multimap<MElement*, MElement*>::iterator> itr = borders[1].equal_range(copy);
        for(std::multimap<MElement*, MElement*>::iterator it = itr.first;
            it != itr.second; it++) {
          MElement *tb = it->second;
          int match = 0;
          for(int i = 0; i < p1->getNumPrimaryVertices(); i++) {
            if(tb->getVertex(0) == p1->getVertex(i) ||
               tb->getVertex(1) == p1->getVertex(i) ||
               tb->getVertex(2) == p1->getVertex(i)) match++;
            if(match == 3) break;
          }
          MElement *dom = (match == 3) ? p1 : p2;
          tb->setDomain(dom, (tb->getDomain(0) == copy) ? 0 : 1);
          borders[1].insert(std::pair<MElement*, MElement*>(dom, tb));
        }
        borders[1].erase(itr.first, itr.second);
        if(eParent) {copy->setParent(NULL, false); delete copy;}
      }
      else { // no cut
        int reg = getElementaryTag(tetras[nbTe]->lsTag(), elementary, newElemTags[3]);
        std::vector<int> phys;
        getPhysicalTag(tetras[nbTe]->lsTag(), gePhysicals, phys, newPhysTags[3]);
        if(eType == MSH_TET_4)
          elements[4][reg].push_back(copy);
        else if(eType == MSH_HEX_8)
          elements[5][reg].push_back(copy);
        else if(eType == MSH_PRI_6)
          elements[6][reg].push_back(copy);
        else if(eType == MSH_PYR_5)
          elements[7][reg].push_back(copy);
        else if(eType == MSH_POLYH_)
          elements[9][reg].push_back(copy);
        assignPhysicals(GM, phys, reg, 3, physicals);
      }

      for (unsigned int i = nbTr; i < triangles.size(); i++){
        MVertex *mv[3] = {NULL, NULL, NULL};
        for(int j = 0; j < 3; j++){
          int numV = getElementVertexNum(triangles[i]->pt(j), e);
          if(numV == -1) {
            MVertex *newv = new MVertex(triangles[i]->x(j), triangles[i]->y(j), triangles[i]->z(j));
            std::pair<newVerticesContainer::iterator, bool> it = newVertices.insert(newv);
            mv[j] = *(it.first);
            if (!it.second) newv->deleteLast();
          }
          else {
            std::map<int, MVertex*>::iterator it = vertexMap.find(numV);
            if(it == vertexMap.end()) {
              mv[j] = new MVertex(triangles[i]->x(j), triangles[i]->y(j),
                                  triangles[i]->z(j), 0, numV);
              vertexMap[numV] = mv[j];
            }
            else mv[j] = it->second;
          }
        }
        MTriangle *tri;
        if(p1 || p2) tri = new MTriangleBorder(mv[0], mv[1], mv[2], ++numEle, ePart, p1, p2);
        else tri = new MTriangle(mv[0], mv[1], mv[2], ++numEle, ePart);
        int lsT = triangles[i]->lsTag();
        int c = elements[2].count(lsT) + elements[3].count(lsT) + elements[8].count(lsT);
        // the surfaces are cut before the volumes!
        int reg = getBorderTag(lsT, c, newElemTags[2][0], borderElemTags[1]);
        int physTag = getBorderTag(lsT, c, newPhysTags[2][0], borderPhysTags[1]);
        std::vector<int> phys; phys.push_back(physTag);
        elements[2][reg].push_back(tri);
        assignPhysicals(GM, phys, reg, 2, physicals);
        for(int i = 0; i < 2; i++)
          if(tri->getDomain(i))
            borders[1].insert(std::pair<MElement*, MElement*>(tri->getDomain(i), tri));
      }
    }
    break;
  case MSH_TRI_3 :
  case MSH_TRI_B :
  case MSH_QUA_4 :
  case MSH_POLYG_ :
  case MSH_POLYG_B :
    {
      if((eType == MSH_TRI_3) | (eType == MSH_TRI_B)) {
        DI_Triangle T(e->getVertex(0)->x(), e->getVertex(0)->y(), e->getVertex(0)->z(),
                      e->getVertex(1)->x(), e->getVertex(1)->y(), e->getVertex(1)->z(),
                      e->getVertex(2)->x(), e->getVertex(2)->y(), e->getVertex(2)->z());
        for(int i = 0; i < 3; i++) nodeLs[i] = &verticesLs(e->getVertex(i)->getIndex(),0);
        isCut = T.cut(RPN, ipV, ipS, cp, integOrder, integOrder, integOrder,
                      quads, triangles, lines, 0, nodeLs);
      }
      else if(eType == MSH_QUA_4){
        DI_Quad Q(e->getVertex(0)->x(), e->getVertex(0)->y(), e->getVertex(0)->z(),
                  e->getVertex(1)->x(), e->getVertex(1)->y(), e->getVertex(1)->z(),
                  e->getVertex(2)->x(), e->getVertex(2)->y(), e->getVertex(2)->z(),
                  e->getVertex(3)->x(), e->getVertex(3)->y(), e->getVertex(3)->z());
        for(int i = 0; i < 4; i++) nodeLs[i] = &verticesLs(e->getVertex(i)->getIndex(),0);
        isCut = Q.cut(RPN, ipV, ipS, cp, integOrder,integOrder,integOrder,
                      quads, triangles, lines, 0, nodeLs);
      }
      else if(eType == MSH_POLYG_ || eType == MSH_POLYG_B){
        for(int i = 0; i < e->getNumChildren(); i++) {
          MElement *t = e->getChild(i);
          DI_Triangle Tri(t->getVertex(0)->x(), t->getVertex(0)->y(), t->getVertex(0)->z(),
                          t->getVertex(1)->x(), t->getVertex(1)->y(), t->getVertex(1)->z(),
                          t->getVertex(2)->x(), t->getVertex(2)->y(), t->getVertex(2)->z());
          for(int i = 0; i < 3; i++) nodeLs[i] = &verticesLs(t->getVertex(i)->getIndex(),0);
          bool iC = Tri.cut(RPN, ipV, ipS, cp, integOrder, integOrder, integOrder,
                            quads, triangles, lines, 0, nodeLs);
          isCut = (isCut || iC);
        }
      }

      MPolygon *p1 = NULL, *p2 = NULL;
      if(isCut) {
        std::vector<MTriangle*> poly[2];

        for (unsigned int i = nbTr; i < triangles.size(); i++){
          MVertex *mv[3] = {NULL, NULL, NULL};
          for(int j = 0; j < 3; j++){
            int numV = getElementVertexNum(triangles[i]->pt(j), e);
            if(numV == -1) {
              MVertex *newv = new MVertex(triangles[i]->x(j), triangles[i]->y(j), triangles[i]->z(j));
              std::pair<newVerticesContainer::iterator, bool> it = newVertices.insert(newv);
              mv[j] = *(it.first);
              if (!it.second) newv->deleteLast();
            }
            else {
              std::map<int, MVertex*>::iterator it = vertexMap.find(numV);
              if(it == vertexMap.end()) {
                mv[j] = new MVertex(triangles[i]->x(j), triangles[i]->y(j),
                                    triangles[i]->z(j), 0, numV);
                vertexMap[numV] = mv[j];
              }
              else mv[j] = it->second;
            }
          }
          MTriangle *mt;
          if(eType == MSH_TRI_B || eType == MSH_POLYG_B)
            mt = new MTriangleBorder(mv[0], mv[1], mv[2], 0, 0,
                                        copy->getDomain(0), copy->getDomain(1));
          else mt = new MTriangle(mv[0], mv[1], mv[2], 0, 0);
          if(triangles[i]->lsTag() < 0)
            poly[0].push_back(mt);
          else
            poly[1].push_back(mt);
        }
        bool own = (eParent && !e->ownsParent()) ? false : true;
        if(poly[0].size()) {
          p1 = new MPolygon(poly[0], ++numEle, ePart, own, parent);
          own = false;
          int reg = getElementaryTag(-1, elementary, newElemTags[2]);
          std::vector<int> phys;
          getPhysicalTag(-1, gePhysicals, phys, newPhysTags[2]);
          elements[8][reg].push_back(p1);
          assignPhysicals(GM, phys, reg, 2, physicals);
          for(int i = 0; i < 2; i++)
            if(p1->getDomain(i))
              borders[1].insert(std::pair<MElement*, MElement*>(p1->getDomain(i), p1));
        }
        if(poly[1].size()) {
          p2 = new MPolygon(poly[1], ++numEle, ePart, own, parent);
          elements[8][elementary].push_back(p2);
          assignPhysicals(GM, gePhysicals, elementary, 2, physicals);
          for(int i = 0; i < 2; i++)
            if(p2->getDomain(i))
              borders[1].insert(std::pair<MElement*, MElement*>(p2->getDomain(i), p2));
        }
        std::pair<std::multimap<MElement*, MElement*>::iterator,
                  std::multimap<MElement*, MElement*>::iterator> itr = borders[0].equal_range(copy);
        for(std::multimap<MElement*, MElement*>::iterator it = itr.first;
            it != itr.second; ++it) {
          MElement *lb = it->second;
          int match = 0;
          for(int i = 0; i < p1->getNumPrimaryVertices(); i++) {
            if(lb->getVertex(0) == p1->getVertex(i) ||
               lb->getVertex(1) == p1->getVertex(i)) match++;
            if(match == 2) break;
          }
          MElement *dom = (match == 2) ? p1 : p2;
          lb->setDomain(dom, (lb->getDomain(0) == copy) ? 0 : 1);
          borders[0].insert(std::pair<MElement*, MElement*>(dom, lb));
        }
        borders[0].erase(itr.first, itr.second);
        if(eParent) {copy->setParent(NULL, false); delete copy;}
      }
      else { // no cut
        int reg = getElementaryTag(triangles[nbTr]->lsTag(), elementary, newElemTags[2]);
        std::vector<int> phys;
        getPhysicalTag(triangles[nbTr]->lsTag(), gePhysicals, phys, newPhysTags[2]);
        if((eType == MSH_TRI_3) | (eType == MSH_TRI_B))
          elements[2][reg].push_back(copy);
        else if(eType == MSH_QUA_4)
          elements[3][reg].push_back(copy);
        else if(eType == MSH_POLYG_ || eType == MSH_POLYG_B)
          elements[8][reg].push_back(copy);
        assignPhysicals(GM, phys, reg, 2, physicals);
        for(int i = 0; i < 2; i++)
          if(copy->getDomain(i))
            borders[1].insert(std::pair<MElement*, MElement*>(copy->getDomain(i), copy));
      }

      for (unsigned int i = nbL; i < lines.size(); i++){
        MVertex *mv[2] = {NULL, NULL};
        for(int j = 0; j < 2; j++){
          int numV = getElementVertexNum(lines[i]->pt(j), e);
          if(numV == -1) {
            MVertex *newv = new MVertex(lines[i]->x(j), lines[i]->y(j), lines[i]->z(j));
            std::pair<newVerticesContainer::iterator, bool> it = newVertices.insert(newv);
            mv[j] = *(it.first);
            if (!it.second) newv->deleteLast();
          }
          else {
            std::map<int, MVertex*>::iterator it = vertexMap.find(numV);
            if(it == vertexMap.end()) {
              mv[j] = new MVertex(lines[i]->x(j), lines[i]->y(j),
                                  lines[i]->z(j), 0, numV);
              vertexMap[numV] = mv[j];
            }
            else mv[j] = it->second;
          }
        }
        MLine *lin;
        if(p1 || p2) lin = new MLineBorder(mv[0], mv[1], ++numEle, ePart, p1, p2);
        else lin = new MLine(mv[0], mv[1], ++numEle, ePart);
        int lsL = lines[i]->lsTag();
        int c = elements[1].count(lsL);
        // the lines are cut before the surfaces!
        int reg = getBorderTag(lsL, c, newElemTags[1][0], borderElemTags[0]);
        int physTag = getBorderTag(lsL, c, newPhysTags[1][0], borderPhysTags[0]);
        std::vector<int> phys; phys.push_back(physTag);
        elements[1][reg].push_back(lin);
        assignPhysicals(GM, phys, reg, 1, physicals);
        for(int i = 0; i < 2; i++)
          if(lin->getDomain(i))
            borders[0].insert(std::pair<MElement*, MElement*>(lin->getDomain(i), lin));
      }
    }
    break;
  case MSH_LIN_2 :
  case MSH_LIN_B :
    {
      DI_Line L(e->getVertex(0)->x(), e->getVertex(0)->y(), e->getVertex(0)->z(),
                e->getVertex(1)->x(), e->getVertex(1)->y(), e->getVertex(1)->z());
      for(int i = 0; i < 2; i++) nodeLs[i] = &verticesLs(e->getVertex(i)->getIndex(),0);
      isCut = L.cut(RPN, ipV, cp, integOrder, lines, 0, nodeLs);

      if(isCut) {
        bool own = (eParent && !e->ownsParent()) ? false : true;
        for (unsigned int i = nbL; i < lines.size(); i++){
          MVertex *mv[2] = {NULL, NULL};
          for(int j = 0; j < 2; j++){
            int numV = getElementVertexNum(lines[i]->pt(j), e);
            if(numV == -1) {
              MVertex *newv = new MVertex(lines[i]->x(j), lines[i]->y(j), lines[i]->z(j));
              std::pair<newVerticesContainer::iterator, bool> it = newVertices.insert(newv);
              mv[j] = *(it.first);
              if (!it.second) newv->deleteLast();
            }
            else {
              std::map<int, MVertex*>::iterator it = vertexMap.find(numV);
              if(it == vertexMap.end()) {
                mv[j] = new MVertex(lines[i]->x(j), lines[i]->y(j), lines[i]->z(j), 0, numV);
                vertexMap[numV] = mv[j];
              }
              else mv[j] = it->second;
            }
          }
          MLine *ml;
          if(eType != MSH_LIN_B) ml = new MLineChild(mv[0], mv[1], ++numEle, ePart, own, parent);
          else ml = new MLineBorder(mv[0], mv[1], ++numEle, ePart,
                                    copy->getDomain(0), copy->getDomain(1));
          own = false;
          int reg = getElementaryTag(lines[i]->lsTag(), elementary, newElemTags[1]);
          std::vector<int> phys;
          getPhysicalTag(lines[i]->lsTag(), gePhysicals, phys, newPhysTags[1]);
          elements[1][reg].push_back(ml);
          assignPhysicals(GM, phys, reg, 1, physicals);
          for(int i = 0; i < 2; i++)
            if(ml->getDomain(i))
              borders[0].insert(std::pair<MElement*, MElement*>(ml->getDomain(i), ml));
        }
        if(eParent) {copy->setParent(NULL, false); delete copy;}
      }
      else { // no cut
        int reg = getElementaryTag(lines[nbL]->lsTag(), elementary, newElemTags[1]);
        std::vector<int> phys;
        getPhysicalTag(lines[nbL]->lsTag(), gePhysicals, phys, newPhysTags[1]);
        elements[1][reg].push_back(copy);
        assignPhysicals(GM, phys, reg, 1, physicals);
        for(int i = 0; i < 2; i++)
          if(copy->getDomain(i))
            borders[0].insert(std::pair<MElement*, MElement*>(copy->getDomain(i), copy));
      }
    }
    break;
  case MSH_PNT :
    {
      DI_Point P(e->getVertex(0)->x(), e->getVertex(0)->y(), e->getVertex(0)->z());
      P.computeLs(RPN.back());
      int reg = getElementaryTag(P.lsTag(), elementary, newElemTags[0]);
      std::vector<int> phys;
      getPhysicalTag(P.lsTag(), gePhysicals, phys, newPhysTags[0]);
      elements[0][reg].push_back(copy);
      assignPhysicals(GM, phys, reg, 0, physicals);
    }
    break;
  default :
    Msg::Error("This type of element cannot be cut.");
    return;
  }

  for(unsigned int i = 0; i < ipS.size(); i++)
    delete ipS[i];
  for(unsigned int i = 0; i < ipV.size(); i++)
    delete ipV[i];
  delete [] nodeLs;
}

#endif //HAVE_DINTEGRATION

GModel *buildCutMesh(GModel *gm, gLevelset *ls,
                     std::map<int, std::vector<MElement*> > elements[10],
                     std::map<int, MVertex*> &vertexMap,
                     std::map<int, std::map<int, std::string> > physicals[4],
                     bool cutElem)
{
#if defined(HAVE_DINTEGRATION)

  GModel *cutGM = new GModel(gm->getName() + "_cut");
  cutGM->setFileName(cutGM->getName());

  std::vector<GEntity*> gmEntities;
  gm->getEntities(gmEntities);

  std::vector<const gLevelset *> primitives;
  ls->getPrimitives(primitives);
  int numVert = gm->indexMeshVertices(true);
  int nbLs = (cutElem) ? primitives.size() : 1;
  fullMatrix<double> verticesLs(numVert + 1, nbLs);
  //compute and store levelset values
  for(unsigned int i = 0; i < gmEntities.size(); i++) {
    for(unsigned int j = 0; j < gmEntities[i]->getNumMeshVertices(); j++) {
      MVertex *vi = gmEntities[i]->getMeshVertex(j);
      if(cutElem)
        for(unsigned int k = 0; k < primitives.size(); k++)
          verticesLs(vi->getIndex(), k) = (*primitives[k])(vi->x(), vi->y(), vi->z());
      else
        verticesLs(vi->getIndex(), 0) = (*ls)(vi->x(), vi->y(), vi->z());
    }
  }

  std::map<int, int> newElemTags[4]; //map<oldElementary,newElementary>[dim]
  std::map<int, int> newPhysTags[4]; //map<oldPhysical,newPhysical>[dim]
  for(int d = 0; d < 4; d++){
    newElemTags[d][0] = gm->getMaxElementaryNumber(d); //max value at [dim][0]
    newPhysTags[d][0] = gm->getMaxPhysicalNumber(d); //max value at [dim][0]
  }

  int numEle = gm->getNumMeshElements(); //element number increment
  std::map<MElement*, MElement*> newParents; //map<oldParent, newParent>
  std::map<MElement*, MElement*> newDomains; //map<oldDomain, newDomain>

  //SplitMesh
  if(!cutElem) {
    for(unsigned int i = 0; i < gmEntities.size(); i++) {
      for(unsigned int j = 0; j < gmEntities[i]->getNumMeshElements(); j++) {
        MElement *e = gmEntities[i]->getMeshElement(j);
        e->setVolumePositive();
        elementSplitMesh(e, verticesLs, gmEntities[i], gm, numEle, vertexMap, newParents,
                         newDomains, elements, physicals, newElemTags, newPhysTags);
        cutGM->getMeshPartitions().insert(e->getPartition());
      }
    }
    return cutGM;
  }

  newVerticesContainer newVertices;
  std::map<int, int> borderElemTags[2]; //map<lsTag,elementary>[line=0,surface=1]
  std::map<int, int> borderPhysTags[2]; //map<lstag,physical>[line=0,surface=1]
  std::multimap<MElement*, MElement*> borders[2]; //multimap<domain,border>[polg=0,polyh=1]
  DI_Point::Container cp;
  std::vector<DI_Line *> lines;
  std::vector<DI_Triangle *> triangles;
  std::vector<DI_Quad *> quads;
  std::vector<DI_Tetra *> tetras;
  std::vector<DI_Hexa *> hexas;
  std::vector<const gLevelset *> RPN;
  ls->getRPN(RPN);
  for(unsigned int i = 0; i < gmEntities.size(); i++) {
    for(unsigned int j = 0; j < gmEntities[i]->getNumMeshElements(); j++) {
      MElement *e = gmEntities[i]->getMeshElement(j);
      e->setVolumePositive();
      elementCutMesh(e, RPN, verticesLs, gmEntities[i], gm, numEle, vertexMap, newVertices, newParents,
                     newDomains, borders, elements, physicals, newElemTags, newPhysTags,
                     borderElemTags, borderPhysTags, cp, lines, triangles, quads, tetras, hexas);
      cutGM->getMeshPartitions().insert(e->getPartition());
    }
    for(DI_Point::Container::iterator it = cp.begin(); it != cp.end(); it++) delete *it;
    for(unsigned int k = 0; k < lines.size(); k++) delete lines[k];
    for(unsigned int k = 0; k < triangles.size(); k++) delete triangles[k];
    for(unsigned int k = 0; k < quads.size(); k++) delete quads[k];
    for(unsigned int k = 0; k < tetras.size(); k++) delete tetras[k];
    for(unsigned int k = 0; k < hexas.size(); k++) delete hexas[k];
    cp.clear(); lines.clear(); triangles.clear(); quads.clear(); tetras.clear(); hexas.clear();
  }

  for(newVerticesContainer::iterator it = newVertices.begin() ; it != newVertices.end(); ++it) {
    vertexMap[(*it)->getNum()] = *it;
  }

  return cutGM;
#else
  Msg::Error("Gmsh need to be compiled with levelset support to cut mesh");
  return 0;
#endif
}

