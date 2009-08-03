// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GModel.h"
#include "MElement.h"
#include "MElementCut.h"

//#define HAVE_DINTEGRATION

#if defined(HAVE_DINTEGRATION)
#include "DILevelset.h"
#include "Integration3D.h"
#endif

//---------------------------------------- MPolyhedron ----------------------------

void MPolyhedron::_init()
{
  for(unsigned int i = 0; i < _parts.size(); i++) {
    if(_parts[i]->getVolume() * _parts[0]->getVolume() < 0)
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
      for(int j = 0; j < 6; j++) {
        int k;
        for(k = _edges.size() - 1; k >= 0; k--)
          if(_faces[i].getEdge(j) == _edges[k])
            break;
        if(k < 0)
          _edges.push_back(_faces[i].getEdge(j));
      }
      for(int j = 0; j < 4; j++) {
        int k;
        for(k = _vertices.size() - 1; k >= 0; k--)
          if(_faces[i].getVertex(j) == _vertices[k])
            break;
        if(k < 0)
          _vertices.push_back(_faces[i].getVertex(j));
      }
    }
  }
}
bool MPolyhedron::isInside(double u, double v, double w)
{
  double ksi[3] = {u, v, w};
  for(unsigned int i = 0; i < _parts.size(); i++) {
    double uvw[3];
    _parts[i]->xyz2uvw(ksi,uvw);
    if(_parts[i]->isInside(uvw[0],uvw[1],uvw[2]))
      return true;
  }
  return false;
}
void MPolyhedron::getIntegrationPoints(int pOrder, int *npts, IntPt **pts) const
{
  *npts = 0;
  double jac[3][3];
  for(unsigned int i = 0; i < _parts.size(); i++) {
    int nptsi;
    IntPt *ptsi;
    _parts[i]->getIntegrationPoints(pOrder, &nptsi, &ptsi);
    for(int ip = 0; ip < nptsi; ip++){
      const double u = ptsi[ip].pt[0];
      const double v = ptsi[ip].pt[1];
      const double w = ptsi[ip].pt[2];
      const double weight = ptsi[ip].weight;
      const double detJ = _parts[i]->getJacobian(u, v, w, jac);
      SPoint3 p; _parts[i]->pnt(u, v, w, p);
      (*pts[*npts + ip]).pt[0] = p.x();
      (*pts[*npts + ip]).pt[1] = p.y();
      (*pts[*npts + ip]).pt[2] = p.z();
      (*pts[*npts + ip]).weight = detJ * weight;
    }
    *npts += nptsi;
  }
}
void MPolyhedron::writeMSH(FILE *fp, double version, bool binary, int num, 
                        int elementary, int physical)
{
  int type = getTypeForMSH();

  if(!type) return;

  // if necessary, change the ordering of the vertices to get positive
  // volume
  setVolumePositive();
  int n = _parts.size() * 4;
  int numE = getNum();
  int partE = getPartition();

  if(!binary){
    fprintf(fp, "%d %d", num ? num : numE, type);
    if(version < 2.0)
      fprintf(fp, " %d %d %d", abs(physical), elementary, n);
    else
      fprintf(fp, " 3 %d %d %d", abs(physical), elementary, partE);
  }
  else{
    int tags[4] = {num ? num : numE, abs(physical), elementary, partE};
    fwrite(tags, sizeof(int), 4, fp);
  }

  if(physical < 0) revert();

  fprintf(fp, " %d", n);
  int verts[180];
  for(unsigned int i = 0; i < _parts.size(); i++)
    for(int j = 0; j < 4; j++)
      verts[i * 4 + j] = _parts[i]->getVertex(j)->getIndex();

  if(!binary){
    for(int i = 0; i < n; i++)
      fprintf(fp, " %d", verts[i]);
    fprintf(fp, "\n");
  }
  else{
    fwrite(verts, sizeof(int), n, fp);
  }

  if(physical < 0) revert();
}

//------------------------------------------- MPolygon ------------------------------

void MPolygon::_initVertices()
{
  std::vector<MEdge> edges;
  for(unsigned int i = 0; i < _parts.size(); i++) {
    for(int j = 0; j < 3; j++) {
      int k;
      for(k = edges.size() - 1; k >= 0; k--)
        if(_parts[i]->getEdge(j) == edges[k])
          break;
      if(k < 0)
        edges.push_back(_parts[i]->getEdge(j));
      else
        edges.erase(edges.begin() + k);
    }
  }

  _vertices.push_back(edges.back().getVertex(0));
  _vertices.push_back(edges.back().getVertex(1));
  edges.pop_back();
  while(edges.size() > 1) {
    for(int k = edges.size() - 1; k >=0; k--) {
      if(edges[k].getVertex(0) == _vertices.back()){
        _vertices.push_back(edges[k].getVertex(1));
        edges.erase(edges.begin() + k);
        break;
      }
      if(edges[k].getVertex(1) == _vertices.back()){
        _vertices.push_back(edges[k].getVertex(0));
        edges.erase(edges.begin() + k);
        break;
      }
    }
  }
}
bool MPolygon::isInside(double u, double v, double w)
{
   double ksi[3] = {u, v, w};
  for(unsigned int i = 0; i < _parts.size(); i++) {
    double uvw[3];
    _parts[i]->xyz2uvw(ksi,uvw);
    if(_parts[i]->isInside(uvw[0],uvw[1],uvw[2]))
      return true;
  }
  return false; 
}
void MPolygon::getIntegrationPoints(int pOrder, int *npts, IntPt **pts) const
{
  *npts = 0;
  double jac[3][3];
  for(unsigned int i = 0; i < _parts.size(); i++) {
    int nptsi;
    IntPt *ptsi;
    _parts[i]->getIntegrationPoints(pOrder, &nptsi, &ptsi);
    for(int ip = 0; ip < nptsi; ip++){
      const double u = ptsi[ip].pt[0];
      const double v = ptsi[ip].pt[1];
      const double w = ptsi[ip].pt[2];
      const double weight = ptsi[ip].weight;
      const double detJ = _parts[i]->getJacobian(u, v, w, jac);
      SPoint3 p; _parts[i]->pnt(u, v, w, p);
      (*pts[*npts + ip]).pt[0] = p.x();
      (*pts[*npts + ip]).pt[1] = p.y();
      (*pts[*npts + ip]).pt[2] = p.z();
      (*pts[*npts + ip]).weight = detJ * weight;
    }
    *npts += nptsi;
  }
}
void MPolygon::writeMSH(FILE *fp, double version, bool binary, int num, 
                        int elementary, int physical)
{
  int type = getTypeForMSH();

  if(!type) return;

  // if necessary, change the ordering of the vertices to get positive
  // volume
  setVolumePositive();
  int n = _parts.size() * 3;
  int numE = getNum();
  int partE = getPartition();

  if(!binary){
    fprintf(fp, "%d %d", num ? num : numE, type);
    if(version < 2.0)
      fprintf(fp, " %d %d %d", abs(physical), elementary, n);
    else
      fprintf(fp, " 3 %d %d %d", abs(physical), elementary, partE);
  }
  else{
    int tags[4] = {num ? num : numE, abs(physical), elementary, partE};
    fwrite(tags, sizeof(int), 4, fp);
  }

  if(physical < 0) revert();

  fprintf(fp, " %d", n);
  int verts[120];
  for(unsigned int i = 0; i < _parts.size(); i++)
    for(int j = 0; j < 3; j++)
      verts[i * 3 + j] = _parts[i]->getVertex(j)->getIndex();

  if(!binary){
    for(int i = 0; i < n; i++)
      fprintf(fp, " %d", verts[i]);
    fprintf(fp, "\n");
  }
  else{
    fwrite(verts, sizeof(int), n, fp);
  }

  if(physical < 0) revert();
}

//---------------------------------------- CutMesh ----------------------------

#if defined(HAVE_DINTEGRATION)

int getElementVertexNum (DI_Point p, MElement *e)
{
  for(int i = 0; i < e->getNumVertices(); i++)
    if(p.x() == e->getVertex(i)->x() && p.y() == e->getVertex(i)->y() &&
       p.z() == e->getVertex(i)->z())
      return e->getVertex(i)->getNum();
  return -1;
}

void assignPhysicals(GModel *GM, std::vector<int> gePhysicals, int reg, int dim,
                     std::map<int, std::map<int, std::string> > physicals[4])
{
  for(unsigned int i = 0; i < gePhysicals.size(); i++)
    if(gePhysicals[i] && (!physicals[dim].count(reg) ||
                          !physicals[dim][reg].count(gePhysicals[i])))
      physicals[dim][reg][gePhysicals[i]] = GM->getPhysicalName(dim, gePhysicals[i]);
}

bool equalV(MVertex *v, DI_Point p)
{
  return (fabs(v->x() - p.x()) < 1.e-15 && fabs(v->y() - p.y()) < 1.e-15 &&
          fabs(v->z() - p.z()) < 1.e-15);
}

static void elementCutMesh (MElement *e, gLevelset *ls, GEntity *ge, GModel *GM, int &numEle,
                     std::map<int, MVertex*> &vertexMap,
                     std::vector<MVertex*> &newVertices,
                     std::map<int, std::vector<MElement*> > elements[10],
                     std::map<int, std::vector<MElement*> > border[2],
                     std::map<int, std::map<int, std::string> > physicals[4],
                     std::map<int, std::vector<GEntity*> > &entityCut)
{
  int elementary = ge->tag();
  int eType = e->getTypeForMSH();
  int ePart = e->getPartition();
  std::vector<int> gePhysicals = ge->physicals;

  // copy element
  std::vector<MVertex*> vmv;
  for(int i = 0; i < e->getNumVertices(); i++) {
    int numV = e->getVertex(i)->getNum();
    if(vertexMap.count(numV))
      vmv.push_back(vertexMap[numV]);
    else {
      MVertex *mv = new MVertex(e->getVertex(i)->x(), e->getVertex(i)->y(),
                                e->getVertex(i)->z(), 0, numV);
      vmv.push_back(mv);
      vertexMap[numV] = mv;
    }
  }
  MElementFactory factory;
  MElement *copy = factory.create(eType, vmv, e->getNum(), ePart);

  switch (eType) {
  case MSH_TET_4 :
  case MSH_HEX_8 :
  case MSH_PYR_5 :
  case MSH_PRI_6 :
    {
      std::vector<DI_CuttingPoint> cp;
      std::vector<DI_Tetra> subTetras;
      std::vector<DI_Hexa> subHexas;
      std::vector<DI_Quad> surfQuads;
      std::vector<DI_Triangle> surfTriangles;
      std::vector<DI_Line> boundLines;
      int integOrder = 1;
      std::vector<DI_IntegrationPoint> ipV;
      std::vector<DI_IntegrationPoint> ipS;

      if(eType == MSH_TET_4) {
	DI_Tetra T(e->getVertex(0)->x(), e->getVertex(0)->y(), e->getVertex(0)->z(),
		   e->getVertex(1)->x(), e->getVertex(1)->y(), e->getVertex(1)->z(),
		   e->getVertex(2)->x(), e->getVertex(2)->y(), e->getVertex(2)->z(),
		   e->getVertex(3)->x(), e->getVertex(3)->y(), e->getVertex(3)->z());
	T.cut(*ls, ipV, ipS, cp, integOrder, integOrder, integOrder,
              subTetras, surfQuads, surfTriangles);
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
	H.cut(*ls, ipV, ipS, cp, integOrder, integOrder, integOrder, integOrder,
              subHexas, subTetras, surfQuads, surfTriangles, boundLines);
      }
      else if(eType == MSH_PRI_6){
        DI_Tetra T1(e->getVertex(0)->x(), e->getVertex(0)->y(), e->getVertex(0)->z(),
		    e->getVertex(1)->x(), e->getVertex(1)->y(), e->getVertex(1)->z(),
		    e->getVertex(2)->x(), e->getVertex(2)->y(), e->getVertex(2)->z(),
                    e->getVertex(5)->x(), e->getVertex(5)->y(), e->getVertex(5)->z());
        DI_Tetra T2(e->getVertex(0)->x(), e->getVertex(0)->y(), e->getVertex(0)->z(),
		    e->getVertex(4)->x(), e->getVertex(4)->y(), e->getVertex(4)->z(),
		    e->getVertex(1)->x(), e->getVertex(1)->y(), e->getVertex(1)->z(),
                    e->getVertex(5)->x(), e->getVertex(5)->y(), e->getVertex(5)->z());
        DI_Tetra T3(e->getVertex(0)->x(), e->getVertex(0)->y(), e->getVertex(0)->z(),
		    e->getVertex(3)->x(), e->getVertex(3)->y(), e->getVertex(3)->z(),
		    e->getVertex(4)->x(), e->getVertex(4)->y(), e->getVertex(4)->z(),
                    e->getVertex(5)->x(), e->getVertex(5)->y(), e->getVertex(5)->z());
        T1.cut(*ls, ipV, ipS, cp, integOrder, integOrder, integOrder,
               subTetras, surfQuads, surfTriangles);
        T2.cut(*ls, ipV, ipS, cp, integOrder, integOrder, integOrder,
               subTetras, surfQuads, surfTriangles);
        T3.cut(*ls, ipV, ipS, cp, integOrder, integOrder, integOrder,
               subTetras, surfQuads, surfTriangles);
      }
      else if(eType == MSH_PYR_5){
        DI_Tetra T1(e->getVertex(0)->x(), e->getVertex(0)->y(), e->getVertex(0)->z(),
		    e->getVertex(1)->x(), e->getVertex(1)->y(), e->getVertex(1)->z(),
		    e->getVertex(2)->x(), e->getVertex(2)->y(), e->getVertex(2)->z(),
		    e->getVertex(4)->x(), e->getVertex(4)->y(), e->getVertex(4)->z());
        DI_Tetra T2(e->getVertex(0)->x(), e->getVertex(0)->y(), e->getVertex(0)->z(),
                    e->getVertex(2)->x(), e->getVertex(2)->y(), e->getVertex(2)->z(),
		    e->getVertex(3)->x(), e->getVertex(3)->y(), e->getVertex(3)->z(),
		    e->getVertex(4)->x(), e->getVertex(4)->y(), e->getVertex(4)->z());
        T1.cut(*ls, ipV, ipS, cp, integOrder, integOrder, integOrder,
               subTetras, surfQuads, surfTriangles);
        T2.cut(*ls, ipV, ipS, cp, integOrder, integOrder, integOrder,
               subTetras, surfQuads, surfTriangles);
      }

      // if cut
      if((eType == MSH_TET_4 && subTetras.size() > 1) ||
         (eType == MSH_HEX_8 && subTetras.size() > 6) ||
         (eType == MSH_PRI_6 && subTetras.size() > 3) ||
         (eType == MSH_PYR_5 && subTetras.size() > 2)) {
        std::vector<MTetrahedron*> poly[2];

	for (unsigned int i = 0; i < subTetras.size(); i++){
          MVertex *mv[4] = {NULL, NULL, NULL, NULL};
          for(int j = 0; j < 4; j++){
            int numV = getElementVertexNum(subTetras[i].pt(j), e);
            if(numV == -1) {
              unsigned int k;
              for(k = 0; k < newVertices.size(); k++)
                if(equalV(newVertices[k], subTetras[i].pt(j))) break;
              if(k == newVertices.size()) {
                mv[j] = new MVertex(subTetras[i].x(j), subTetras[i].y(j),
                                    subTetras[i].z(j), 0, numV);
                newVertices.push_back(mv[j]);
              }
              else mv[j] = newVertices[k];
            }
            else {
              std::map<int, MVertex*>::iterator it = vertexMap.find(numV);
              if(it == vertexMap.end()) {
                mv[j] = new MVertex(subTetras[i].x(j), subTetras[i].y(j),
                                    subTetras[i].z(j), 0, numV);
                vertexMap[numV] = mv[j];
              }
              else mv[j] = it->second;
            }
          }
          MTetrahedron *mt = new MTetrahedron(mv[0], mv[1], mv[2], mv[3], ++numEle, ePart);
          if(subTetras[i].lsTag() < 0)
            poly[0].push_back(mt);
          else
            poly[1].push_back(mt);
        }
        MPolyhedron *p1 = new MPolyhedron(poly[0], copy, true, ++numEle, ePart);
        elements[9][elementary * -1].push_back(p1);
        assignPhysicals(GM, gePhysicals, elementary * -1, 3, physicals);
        MPolyhedron *p2 = new MPolyhedron(poly[1], copy, false, ++numEle, ePart);
        elements[9][elementary].push_back(p2);
        assignPhysicals(GM, gePhysicals, elementary, 3, physicals);

        for (int i = 0; i < surfTriangles.size(); i++){
          MVertex *mv[3] = {NULL, NULL, NULL};
          for(int j = 0; j < 3; j++){
            int numV = getElementVertexNum(surfTriangles[i].pt(j), e);
            if(numV == -1) {
              unsigned int k;
              for(k = 0; k < newVertices.size(); k++)
                if(equalV(newVertices[k], surfTriangles[i].pt(j))) break;
              if(k == newVertices.size()) {
                mv[j] = new MVertex(surfTriangles[i].x(j), surfTriangles[i].y(j),
                                    surfTriangles[i].z(j), 0, numV);
                newVertices.push_back(mv[j]);
              }
              else mv[j] = newVertices[k];
            }
            else {
              std::map<int, MVertex*>::iterator it = vertexMap.find(numV);
              if(it == vertexMap.end()) {
                mv[j] = new MVertex(surfTriangles[i].x(j), surfTriangles[i].y(j),
                                    surfTriangles[i].z(j), 0, numV);
                vertexMap[numV] = mv[j];
              }
              else mv[j] = it->second;
            }
          }
          MTriangleBorder *tri = new MTriangleBorder(mv[0], mv[1], mv[2],
                                                     p1, p2, ++numEle, ePart);
          border[1][surfTriangles[i].lsTag()].push_back(tri);
          entityCut[surfTriangles[i].lsTag()].push_back(ge);
        }
      }

      else { // no cut
        int reg = subTetras[0].lsTag() * elementary;
        if(eType == MSH_TET_4)
          elements[4][reg].push_back(copy);
        else if(eType == MSH_HEX_8)
          elements[5][reg].push_back(copy);
        else if(eType == MSH_PRI_6)
          elements[6][reg].push_back(copy);
        else if(eType == MSH_PYR_5)
          elements[7][reg].push_back(copy);

        assignPhysicals(GM, gePhysicals, reg, 3, physicals);
      }
      
    }
    break;
  case MSH_TRI_3 :
  case MSH_QUA_4 :
    {
      std::vector<DI_CuttingPoint> cp;
      std::vector<DI_Quad> subQuads;
      std::vector<DI_Triangle> subTriangles;
      std::vector<DI_Line> boundLines;
      int integOrder = 1;
      std::vector<DI_IntegrationPoint> ipV;
      std::vector<DI_IntegrationPoint> ipS;

      if(eType == MSH_TRI_3) {
	DI_Triangle T(e->getVertex(0)->x(), e->getVertex(0)->y(), e->getVertex(0)->z(),
		      e->getVertex(1)->x(), e->getVertex(1)->y(), e->getVertex(1)->z(),
		      e->getVertex(2)->x(), e->getVertex(2)->y(), e->getVertex(2)->z());
	T.cut(*ls, ipV, ipS, cp, integOrder, integOrder, integOrder,
              subQuads, subTriangles, boundLines);
      }
      else {
	DI_Quad Q(e->getVertex(0)->x(), e->getVertex(0)->y(), e->getVertex(0)->z(),
		  e->getVertex(1)->x(), e->getVertex(1)->y(), e->getVertex(1)->z(),
		  e->getVertex(2)->x(), e->getVertex(2)->y(), e->getVertex(2)->z(),
		  e->getVertex(3)->x(), e->getVertex(3)->y(), e->getVertex(3)->z());
	Q.cut(*ls, ipV, ipS, cp, integOrder,integOrder,integOrder,
              subQuads, subTriangles, boundLines);
      }

      // if cut
      if((eType == MSH_TRI_3 && subTriangles.size() > 1) ||
         (eType == MSH_QUA_4 && subTriangles.size() > 2)) {
        std::vector<MTriangle*> poly[2];

	for (unsigned int i = 0; i < subTriangles.size(); i++){
          MVertex *mv[3] = {NULL, NULL, NULL};
          for(int j = 0; j < 3; j++){
            int numV = getElementVertexNum(subTriangles[i].pt(j), e);
            if(numV == -1) {
              unsigned int k;
              for(k = 0; k < newVertices.size(); k++)
                if(equalV(newVertices[k], subTriangles[i].pt(j))) break;
              if(k == newVertices.size()) {
                mv[j] = new MVertex(subTriangles[i].x(j), subTriangles[i].y(j),
                                    subTriangles[i].z(j), 0, numV);
                newVertices.push_back(mv[j]);
              }
              else mv[j] = newVertices[k];
            }
            else {
              std::map<int, MVertex*>::iterator it = vertexMap.find(numV);
              if(it == vertexMap.end()) {
                mv[j] = new MVertex(subTriangles[i].x(j), subTriangles[i].y(j),
                                    subTriangles[i].z(j), 0, numV);
                vertexMap[numV] = mv[j];
              }
              else mv[j] = it->second;
            }
          }
          MTriangle *mt = new MTriangle(mv[0], mv[1], mv[2], ++numEle, ePart);
          if(subTriangles[i].lsTag() < 0)
            poly[0].push_back(mt);
          else
            poly[1].push_back(mt);
        }
        MPolygon *p1 = new MPolygon(poly[0], copy, true, ++numEle, ePart);
        elements[8][elementary * -1].push_back(p1);
        assignPhysicals(GM, gePhysicals, elementary * -1, 2, physicals);
        MPolygon *p2 = new MPolygon(poly[1], copy, false, ++numEle, ePart);
        elements[8][elementary].push_back(p2);
        assignPhysicals(GM, gePhysicals, elementary, 2, physicals);

        for (int i = 0; i < boundLines.size(); i++){
          MVertex *mv[2] = {NULL, NULL};
          for(int j = 0; j < 2; j++){
            int numV = getElementVertexNum(boundLines[i].pt(j), e);
            if(numV == -1) {
              unsigned int k;
              for(k = 0; k < newVertices.size(); k++)
                if(equalV(newVertices[k], boundLines[i].pt(j))) break;
              if(k == newVertices.size()) {
                mv[j] = new MVertex(boundLines[i].x(j), boundLines[i].y(j),
                                    boundLines[i].z(j), 0, numV);
                newVertices.push_back(mv[j]);
              }
              else mv[j] = newVertices[k];
            }
            else {
              std::map<int, MVertex*>::iterator it = vertexMap.find(numV);
              if(it == vertexMap.end()) {
                mv[j] = new MVertex(boundLines[i].x(j), boundLines[i].y(j),
                                    boundLines[i].z(j), 0, numV);
                vertexMap[numV] = mv[j];
              }
              else mv[j] = it->second;
            }
          }
          MLineBorder *lin = new MLineBorder(mv[0], mv[1], p1, p2, ++numEle, ePart);
          border[0][boundLines[i].lsTag()].push_back(lin);
          entityCut[boundLines[i].lsTag()].push_back(ge);
        }
      }

      else { // no cut
        int reg = subTriangles[0].lsTag() * elementary;
        if(eType == MSH_TRI_3)
          elements[2][reg].push_back(copy);
        else if(eType == MSH_QUA_4)
          elements[3][reg].push_back(copy);
        assignPhysicals(GM, gePhysicals, reg, 2, physicals);
      }
    }
    break;
  case MSH_LIN_2 :
    {
      std::vector<DI_CuttingPoint> cp;
      std::vector<DI_Line> lines;
      int integOrder = 1;
      std::vector<DI_IntegrationPoint> ip;
      DI_Line L(e->getVertex(0)->x(), e->getVertex(0)->y(), e->getVertex(0)->z(),
		e->getVertex(1)->x(), e->getVertex(1)->y(), e->getVertex(1)->z());
      L.cut(*ls, ip, cp, integOrder, lines);

      if(lines.size() > 1) {
	for (unsigned int i = 0; i < lines.size(); i++){
          MVertex *mv[2] = {NULL, NULL};
          for(int j = 0; j < 2; j++){
            int numV = getElementVertexNum(lines[i].pt(j), e);
            if(numV == -1) {
              unsigned int k;
              for(k = 0; k < newVertices.size(); k++)
                if(equalV(newVertices[k], lines[i].pt(j))) break;
              if(k == newVertices.size()) {
                mv[j] = new MVertex(lines[i].x(j), lines[i].y(j), lines[i].z(j), 0, numV);
                newVertices.push_back(mv[j]);
              }
              else mv[j] = newVertices[k];
            }
            else {
              std::map<int, MVertex*>::iterator it = vertexMap.find(numV);
              if(it == vertexMap.end()) {
                mv[j] = new MVertex(lines[i].x(j), lines[i].y(j), lines[i].z(j), 0, numV);
                vertexMap[numV] = mv[j];
              }
              else mv[j] = it->second;
            }
          }
          MLine *ml = new MLine(mv[0], mv[1], ++numEle, ePart);
          int reg = lines[i].lsTag() * elementary;
          elements[1][reg].push_back(ml);
          assignPhysicals(GM, gePhysicals, reg, 1, physicals);
        }
      }

      else { // no cut
        int reg = lines[0].lsTag() * elementary;
        elements[1][reg].push_back(copy);
        assignPhysicals(GM, gePhysicals, reg, 1, physicals);
      }
    }
    break;
  case MSH_PNT :
    {
      DI_Point P(e->getVertex(0)->x(), e->getVertex(0)->y(), e->getVertex(0)->z());
      P.computeLs(*ls);
      int reg = P.lsTag() * elementary;
      elements[0][reg].push_back(copy);
      assignPhysicals(GM, gePhysicals, reg, 0, physicals);
    }
    break;
  default :
    Msg::Error("This type of element cannot be cut.");
    throw;
  }
}

#endif

GModel *buildCutMesh(GModel *gm, gLevelset *ls, 
                     std::map<int, std::vector<MElement*> > elements[10],
                     std::map<int, MVertex*> &vertexMap,
                     std::map<int, std::map<int, std::string> > physicals[4])
{
#if defined(HAVE_DINTEGRATION)
  GModel *cutGM = new GModel;

  std::map<int, std::vector<MElement*> > border[2];
  std::vector<MVertex*> newVertices;
  std::vector<GEntity*> gmEntities;
  std::map<int, std::vector<GEntity*> > entityCut;

  gm->getEntities(gmEntities);
  int numEle = gm->getNumMeshElements();

  for(unsigned int i = 0; i < gmEntities.size(); i++) {
    for(int j = 0; j < gmEntities[i]->getNumMeshElements(); j++) {
      MElement *e = gmEntities[i]->getMeshElement(j);
      elementCutMesh (e, ls, gmEntities[i], gm, numEle,
                      vertexMap, newVertices, elements, border, physicals, entityCut);
      cutGM->getMeshPartitions().insert(e->getPartition());
    }
  }

  // add borders in elements and change the tag if it's already used
  std::map<int, std::vector<MElement*> >::iterator itbo, itel;
  for(itbo = border[0].begin(); itbo != border[0].end(); itbo++) {
    int reg = itbo->first;
    if(elements[1].count(reg)) {
      itel = elements[1].end(); itel--;
      reg = itel->first + 1;
    }
    for(unsigned int j = 0; j < itbo->second.size(); j++)
      elements[1][reg].push_back(itbo->second[j]);
    std::map<int, std::vector<GEntity*> >::iterator itge = entityCut.find(itbo->first);
    for(unsigned int j = 0; j < itge->second.size(); j++)
      assignPhysicals(gm, itge->second[j]->physicals, reg, 1, physicals);
  }
  for(itbo = border[1].begin(); itbo != border[1].end(); itbo++) {
    int reg = itbo->first;
    if(elements[2].count(reg)) {
      itel = elements[2].end(); itel--;
      reg = itel->first + 1;
    }
    if(elements[3].count(reg)) {
      itel = elements[3].end(); itel--;
      reg = std::max(reg, itel->first + 1);
    }
    for(unsigned int j = 0; j < itbo->second.size(); j++)
      elements[2][reg].push_back(itbo->second[j]);
    std::map<int, std::vector<GEntity*> >::iterator itge = entityCut.find(itbo->first);
    for(unsigned int j = 0; j < itge->second.size(); j++)
      assignPhysicals(gm, itge->second[j]->physicals, reg, 2, physicals);
  }

  // number the new vertices and add in vertexMap
  std::map<int, MVertex* >::iterator itend = vertexMap.end(); itend--;
  int num = itend->first;
  for(unsigned int i = 0; i < newVertices.size(); i++) {
    newVertices[i]->setNum(++num);
    vertexMap[num] = newVertices[i];
  }printf("numbering vertices finished : %d vertices \n",vertexMap.size());

  return cutGM;
#else
  Msg::Error("Gmsh need to be compiled with levelset support to cut mesh");
  return 0;
#endif
}

