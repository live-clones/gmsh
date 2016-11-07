// Copyright (C) 2013 ULg-UCL
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
// Contributors: Thomas Toulorge, Jonathan Lambrechts

#include <stdio.h>
#include <sstream>
#include <fstream>
#include <iterator>
#include <string.h>
#include "GmshConfig.h"
#include "OptHomFastCurving.h"
#include "GModel.h"
#include "Gmsh.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MLine.h"
#include "OS.h"
#include <stack>
#include "SuperEl.h"
#include "SVector3.h"
#include "BasisFactory.h"
#include "Field.h"



namespace {



// Compute vertex -> element connectivity
void calcVertex2Elements(int dim, GEntity *entity,
                                std::map<MVertex*, std::vector<MElement *> > &vertex2elements)
{
  for (size_t i = 0; i < entity->getNumMeshElements(); ++i) {
    MElement *element = entity->getMeshElement(i);
    if (element->getDim() == dim)
      for (int j = 0; j < element->getNumPrimaryVertices(); ++j)
        vertex2elements[element->getVertex(j)].push_back(element);
  }
}



// Given a starting vertex and a direction, find the next vertex in a column
MVertex *findVertFromDir(const std::map<MVertex*, std::vector<MElement*> > &vertex2elements,
                         MVertex *v0, MVertex *vExclude, const SVector3 &dir, double spLimit)
{

  const std::vector<MElement*> &elts = (*vertex2elements.find(v0)).second;                      // All elements connected to vertex
  MVertex *vFound = 0;
  double spMax = 0.;
  for (std::vector<MElement*>::const_iterator itEl = elts.begin(); itEl != elts.end(); ++itEl)  // Loop over all elements
    for (int i=0; i<(*itEl)->getNumEdges(); i++) {                                              // Loop over all edges of each element
      MEdge edge = (*itEl)->getEdge(i);
      MVertex *vA = edge.getVertex(0), *vB = edge.getVertex(1), *vTmp;
      if (v0 == vA)                                                                             // Skip if edge unconnected to vertex...
        if (vB == vExclude) continue;                                                           // ... or if connecting to preceding vertex
        else vTmp = vB;
      else if (v0 == vB)
        if (vA == vExclude) continue;
        else vTmp = vA;
      else continue;
      SVector3 tanVec = edge.tangent();
      double sp = fabs(dot(tanVec, dir));
      if ((sp > spMax) && (sp > spLimit)){                                                      // Retain the edge giving max. dot product with normal
        spMax = sp;
        vFound = vTmp;
      }
    }
  return vFound;
}



// Find a column of vertices starting with a given vertex
template<class bndType>
bool findColumn(const std::map<MVertex*, std::vector<MElement*> > &vertex2elements,
                MVertex *baseVert, const SVector3 &norm,
                const bndType &baseEd, std::vector<MVertex*> &col, int maxNumLayers)
{
  static const double spMin = 0.866025404;                                                // Threshold in cosine between 1st edge and normal
  static const double spTol = 0.999;                                                      // Threshold in cosine between an edge and 1st edge

  MVertex *vert = findVertFromDir(vertex2elements, baseVert, 0, norm, spMin);
  if (!vert) {                                                                            // If 1st normal edge not found...
    vert = findVertFromDir(vertex2elements, baseVert, 0, baseEd.normal(), spMin);         // ... tries normal to base edge/face
    if (!vert) {
      Msg::Warning("Could not find normal edge for vertex %i ", baseVert->getNum());
      return false;
    }
  }
  SVector3 firstEdgeDir(baseVert->point(), vert->point());
  firstEdgeDir.normalize();

  SVector3 dir(baseVert->point(), vert->point());
  col.push_back(vert);
  MVertex *oldVert = baseVert, *newVert;
  for (int iLayer = 0; iLayer < maxNumLayers; iLayer++) {
    newVert = findVertFromDir(vertex2elements, vert, oldVert, firstEdgeDir, spTol);
    col.push_back(newVert);                                                               // Will add null pointer at the end, which is OK
    if (!newVert) break;
    oldVert = vert;
    vert = newVert;
  }

  return (col.size() > 1);
}



// Add normal to edge/face to data structure for vertices
void addNormVertEl(MElement *el, const SVector3 &norm,
                   std::map<MVertex*, SVector3> &normVert)
{
  for(unsigned int iV = 0; iV<el->getNumVertices(); iV++) {
    MVertex *vert = el->getVertex(iV);
    std::pair<std::map<MVertex*, SVector3>::iterator, bool> insNorm =           // If nothing for vert...
      normVert.insert(std::pair<MVertex*, SVector3>(vert, SVector3(0.)));       // ... create zero normal
    insNorm.first->second += norm;                                              // Cumulate normals
  }
}



// Compute normals to boundary edges/faces and store them per vertex
void buildNormals(const std::map<MVertex*, std::vector<MElement*> > &vertex2elements,
                    const std::multimap<GEntity*,GEntity*> &entities, const FastCurvingParameters &p,
                    std::map<GEntity*, std::map<MVertex*, SVector3> > &normVertEnt)
{
  normVertEnt.clear();
  for (std::multimap<GEntity*,GEntity*>::const_iterator itBE = entities.begin();
                                                   itBE != entities.end(); itBE++) {  // Loop over model entities
    GEntity* const &bndEnt = itBE->second;
    std::map<MVertex*, SVector3> &normVert = normVertEnt[bndEnt];
    if (bndEnt->dim() == 1) {
      GEdge *ge = bndEnt->cast2Edge();
      for(unsigned int iEl = 0; iEl<ge->lines.size(); iEl++) {
        MLine* const &line = ge->lines[iEl];
        SVector3 norm = line->getEdge(0).normal();
        addNormVertEl(line, norm, normVert);
      }
    }
    else if (bndEnt->dim() == 2) {
      GFace *gf = bndEnt->cast2Face();
      for(unsigned int iEl = 0; iEl<gf->triangles.size(); iEl++) {
        MTriangle* const &tri = gf->triangles[iEl];
        SVector3 norm = tri->getFace(0).normal();
        addNormVertEl(tri, norm, normVert);
      }
      for(unsigned int iEl = 0; iEl<gf->quadrangles.size(); iEl++) {
        MQuadrangle* const &quad = gf->quadrangles[iEl];
        SVector3 norm = quad->getFace(0).normal();
        addNormVertEl(quad, norm, normVert);
      }
    }
    for (std::map<MVertex*, SVector3> ::iterator itNV =                                 // Re-normalize for each geom. entity
         normVert.begin(); itNV != normVert.end(); itNV++)
      itNV->second.normalize();
  }
}



// Get first domain element for a given boundary edge
MElement *getFirstEl(const std::map<MVertex*, std::vector<MElement*> > &vertex2elements,
                     const MEdge &baseEd)
{
  MVertex *vb0 = baseEd.getVertex(0), *vb1 = baseEd.getVertex(1);

  const std::vector<MElement*> &nb0 = vertex2elements.find(vb0)->second;
  const std::vector<MElement*> &nb1 = vertex2elements.find(vb1)->second;
  MElement *firstEl = 0;
  for (int iEl=0; iEl<nb0.size(); iEl++) {
    if (find(nb1.begin(), nb1.end(), nb0[iEl]) != nb1.end()) {
      firstEl = nb0[iEl];
      break;
    }
  }

  return firstEl;
}



// Get intersection of two vectors of MElement*
void intersect(const std::vector<MElement*> &vi1, const std::vector<MElement*> &vi2,
               std::vector<MElement*> &vo)
{
  vo.clear();
  for (std::vector<MElement*>::const_iterator it = vi1.begin(); it != vi1.end(); it++)
    if (std::find(vi2.begin(), vi2.end(), *it) != vi2.end())
      vo.push_back(*it);
}



// Get first domain element for a given boundary face
MElement *getFirstEl(const std::map<MVertex*, std::vector<MElement*> > &vertex2elements,
                     const MFace &baseFace)
{
  MVertex *vb0 = baseFace.getVertex(0), *vb1 = baseFace.getVertex(1);

  // Get elements common to vertices 0 and 1
  const std::vector<MElement*> &nb0 = vertex2elements.find(vb0)->second;
  const std::vector<MElement*> &nb1 = vertex2elements.find(vb1)->second;
  std::vector<MElement*> nb01;
  intersect(nb0, nb1, nb01);
  if (nb01.empty()) return 0;
  if (nb01.size() == 1) return nb01.front();

  // Get elements common to vertices 0, 1 and 2
  MVertex *vb2 = baseFace.getVertex(2);
  const std::vector<MElement*> &nb2 = vertex2elements.find(vb2)->second;
  std::vector<MElement*> nb012;
  intersect(nb01, nb2, nb012);
  if (nb012.empty()) return 0;
  if (nb012.size() == 1) return nb012.front();

  // If quad, get elements common to all 4 vertices
  if (baseFace.getNumVertices() == 4) {
    MVertex *vb3 = baseFace.getVertex(3);
    const std::vector<MElement*> &nb3 = vertex2elements.find(vb3)->second;
    std::vector<MElement*> nb0123;
    intersect(nb012, nb3, nb0123);
    if (nb0123.empty()) return 0;
    if (nb0123.size() == 1) return nb0123.front();
  }

  // Too many elements, return error
  return 0;
}



// Get base vertices (in order of first element) for an edge
bool getBaseVertices(const MEdge &baseEd, MElement *firstEl, std::vector<MVertex*> &baseVert)
{
  baseVert.clear();
  for (int iEd = 0; iEd < firstEl->getNumEdges(); iEd++)
    if (firstEl->getEdge(iEd) == baseEd)
      firstEl->getEdgeVertices(iEd, baseVert);

  if (baseVert.empty()) {
    Msg::Error("Base edge vertices not found in getBaseVertices");
    return false;
  }
  else
    return true;
}



// Get base vertices (in order of first element) for a face
bool getBaseVertices(const MFace &baseFace, MElement *firstEl, std::vector<MVertex*> &baseVert)
{
  baseVert.clear();
  for (int iFace = 0; iFace < firstEl->getNumFaces(); iFace++)
    if (firstEl->getFace(iFace) == baseFace)
      firstEl->getFaceVertices(iFace, baseVert);

  if (baseVert.empty()) {
    Msg::Error("Base face vertices not found in getBaseVertices");
    return false;
  }
  else
    return true;
}



// Top primary vertices (in order corresponding to the primary base vertices)
template<class bndType>
bool getTopPrimVertices(std::map<MVertex*, std::vector<MElement *> > &vertex2elements,
                        const std::map<MVertex*, SVector3> &normVert,
                        const BoundaryLayerColumns *blc, const bndType &baseBnd,
                        int maxNumLayers, const std::vector<MVertex*> &baseVert,
                        std::vector<MVertex*> &topPrimVert)
{
  int nbVert = baseBnd.getNumVertices();
  topPrimVert = std::vector<MVertex*>(nbVert);
  for(int i = 0; i < nbVert; i++) {
    if (blc && (blc->size() > 1)) {                                                             // Is there BL data?
      return false;
      //      const BoundaryLayerData &c = blc->getColumn(baseVert[i], baseBnd);
      //      if (c._column.size() == 0) return false;                                                  // Give up element if column not found
      //      topPrimVert[i] = *(c._column.end()-2);
    }
    else {                                                                                      // No BL data, look for columns of vertices
      std::map<MVertex*, SVector3>::const_iterator itNorm = normVert.find(baseVert[i]);
      if (itNorm == normVert.end()) {
        Msg::Error("Normal to vertex not found in getTopPrimVertices");
        itNorm = normVert.begin();
      }
      std::vector<MVertex*> col;
      bool colFound = findColumn(vertex2elements, baseVert[i], itNorm->second,
                                 baseBnd, col, maxNumLayers);
      if (!colFound) return false;                                                              // Give up element if column not found
      topPrimVert[i] = *(col.end()-2);
    }
  }

  return true;
}



// Get blob of elements encompassed by a given meta-element
// FIXME: Implement 3D
void get2DBLBlob(const std::map<MVertex*, std::vector<MElement*> > &vertex2elements,
                 MElement *firstEl, const SuperEl *supEl, std::set<MElement*> &blob)
{
  static const int maxDepth = 100;
  typedef std::list<MElement*> elLType;
  typedef std::vector<MElement*> elVType;

  // Build blob by looping over layers of elements (assuming that if an el is too far, its neighbours are too far as well)
  blob.clear();
  elLType currentLayer, lastLayer;
  blob.insert(firstEl);
  lastLayer.push_back(firstEl);
  for (int d = 0; d < maxDepth; ++d) {                                                              // Loop over layers
    currentLayer.clear();
    for (elLType::iterator it = lastLayer.begin(); it != lastLayer.end(); ++it) {                   // Loop over elements of last layer
      for (int i = 0; i < (*it)->getNumPrimaryVertices(); ++i) {
        const elVType &neighbours = vertex2elements.find((*it)->getVertex(i))->second;
        for (elVType::const_iterator itN = neighbours.begin(); itN != neighbours.end(); ++itN) {    // Loop over neighbours of last layer
          SPoint3 p = (*itN)->barycenter(true);
          if (supEl->isPointIn(p))                                                                  // Add neighbour to blob if inside test element
            if (blob.insert(*itN).second) currentLayer.push_back(*itN);                             // Add to current layer if new in blob
        }
      }
    }
    if (currentLayer.empty()) break;                                                                // Finished if no new element in blob
    lastLayer = currentLayer;
  }
}



void makeStraight(MElement *el, const std::set<MVertex*> &movedVert)
{
  const nodalBasis *nb = el->getFunctionSpace();
  const fullMatrix<double> &pts = nb->points;

  SPoint3 p;

  for(int iPt = el->getNumPrimaryVertices(); iPt < el->getNumVertices(); ++iPt) {
    MVertex *vert = el->getVertex(iPt);
    if (movedVert.find(vert) == movedVert.end()) {
      el->primaryPnt(pts(iPt,0),pts(iPt,1),pts(iPt,2),p);
      vert->setXYZ(p.x(),p.y(),p.z());
    }
  }
}



inline void insertIfCurved(MElement *el, std::list<MElement*> &bndEl)
{
  static const double curvedTol = 1.e-3;                                              // Tolerance to consider element as curved

  const double normalDispCurved = curvedTol*el->getInnerRadius();                     // Threshold in normal displacement to consider element as curved
  const int dim = el->getDim();

  // Compute unit normal to straight edge/face
  SVector3 normal = (dim == 1) ? el->getEdge(0).normal() : el->getFace(0).normal();

  // Get functional spaces
  const nodalBasis *lagBasis = el->getFunctionSpace();
  const fullMatrix<double> &uvw = lagBasis->points;
  const int &nV = uvw.size1();
  const nodalBasis *lagBasis1 = el->getFunctionSpace(1);
  const int &nV1 = lagBasis1->points.size1();

  // Get first-order vertices
  std::vector<SPoint3> xyz1(nV1);
  for (int iV = 0; iV < nV1; ++iV) xyz1[iV] = el->getVertex(iV)->point();

  // Check normal displacement at each HO vertex
  for (int iV = nV1; iV < nV; ++iV) {                                                 // Loop over HO nodes
    double f[256];
    lagBasis1->f(uvw(iV, 0), (dim > 1) ? uvw(iV, 1) : 0., 0., f);
    SPoint3 xyzS(0.,0.,0.);
    for (int iSF = 0; iSF < nV1; ++iSF) xyzS += xyz1[iSF]*f[iSF];                     // Compute location of node in straight element
    const SVector3 vec(xyzS, el->getVertex(iV)->point());
    const double normalDisp = fabs(dot(vec, normal));                                 // Normal component of displacement
    if (normalDisp > normalDispCurved) {
      bndEl.push_back(el);
      break;
    }
  }
}



// Curve elements adjacent to a boundary model entity
void curveMeshFromBnd(std::map<MVertex*, std::vector<MElement *> > &vertex2elements,
                      const std::map<MVertex*, SVector3> &normVert, BoundaryLayerColumns *blc,
                      GEntity *bndEnt, FastCurvingParameters &p)
{
  // Build list of bnd. elements to consider
  std::list<MElement*> bndEl;
  if (bndEnt->dim() == 1) {
    GEdge *gEd = bndEnt->cast2Edge();
    for(unsigned int i = 0; i< gEd->lines.size(); i++)
      insertIfCurved(gEd->lines[i], bndEl);
  }
  else if (bndEnt->dim() == 2) {
    GFace *gFace = bndEnt->cast2Face();
    for(unsigned int i = 0; i< gFace->triangles.size(); i++)
      insertIfCurved(gFace->triangles[i], bndEl);
    for(unsigned int i = 0; i< gFace->quadrangles.size(); i++)
      insertIfCurved(gFace->quadrangles[i], bndEl);
  }
  else
    Msg::Error("Cannot treat model entity %i of dim %i", bndEnt->tag(), bndEnt->dim());

  std::ostringstream oss;
  oss << "meta-elements_" << bndEnt->tag() << ".pos";
  std::ofstream of(oss.str().c_str());
  of << "View \" \"{\n";

  std::set<MVertex*> movedVert;
  for(std::list<MElement*>::iterator itBE = bndEl.begin();
      itBE != bndEl.end(); itBE++) {   // Loop over bnd. elements
    const int bndType = (*itBE)->getType();
    int seType;
    bool foundVert;
    MElement *firstEl = 0;
    std::vector<MVertex*> baseVert, topPrimVert;
    if (bndType == TYPE_LIN) {                                                               // 1D boundary?
      MVertex *vb0 = (*itBE)->getVertex(0);
      MVertex *vb1 = (*itBE)->getVertex(1);
      seType = TYPE_QUA;
      MEdge baseEd(vb0, vb1);
      firstEl = getFirstEl(vertex2elements, baseEd);
      foundVert = getBaseVertices(baseEd, firstEl, baseVert);
      if (!foundVert) continue;                                                             // Skip bnd. el. if base vertices not found
      foundVert = getTopPrimVertices(vertex2elements, normVert, blc, baseEd,
                                     p.maxNumLayers, baseVert, topPrimVert);
    }
    else {                                                                                  // 2D boundary
      MVertex *vb0 = (*itBE)->getVertex(0);
      MVertex *vb1 = (*itBE)->getVertex(1);
      MVertex *vb2 = (*itBE)->getVertex(2);
      MVertex *vb3;
      if (bndType == TYPE_QUA) {
        vb3 = (*itBE)->getVertex(3);
        seType = TYPE_HEX;
      }
      else {
        vb3 = 0;
        seType = TYPE_PRI;
      }
      MFace baseFace(vb0, vb1, vb2, vb3);
      firstEl = getFirstEl(vertex2elements, baseFace);
      if (!firstEl) {
        Msg::Error("Did not find first domain element for boundary element %i",
                   (*itBE)->getNum());
        continue;
      }
      foundVert = getBaseVertices(baseFace, firstEl, baseVert);
      if (!foundVert) continue;                                                             // Skip bnd. el. if base vertices not found
      foundVert = getTopPrimVertices(vertex2elements, normVert, blc,
                                     baseFace, p.maxNumLayers,
                                     baseVert, topPrimVert);
    }
    if (!foundVert) continue;                                                               // Skip bnd. el. if top vertices not found
    int order = firstEl->getPolynomialOrder();
    SuperEl se(seType, order, baseVert, topPrimVert);
    of << se.printPOS();
    std::set<MElement*> blob;
    get2DBLBlob(vertex2elements, firstEl, &se, blob); // TODO: Implement for 3D
    for (std::set<MElement*>::iterator itE = blob.begin(); itE != blob.end(); ++itE) {
      makeStraight(*itE, movedVert);
      for (int i = (*itE)->getNumPrimaryVertices(); i < (*itE)->getNumVertices(); ++i) {    // Loop over HO vert. of each el. in blob
        MVertex* vert = (*itE)->getVertex(i);
        if (movedVert.find(vert) == movedVert.end()) {                                      // Try to move vert. not already moved
          double xyzS[3] = {vert->x(), vert->y(), vert->z()}, xyzC[3];
          if (se.straightToCurved(xyzS,xyzC)) {
            vert->setXYZ(xyzC[0], xyzC[1], xyzC[2]);
            movedVert.insert(vert);
          }
        }
      }
    }
  }

  of << "};\n";
  of.close();
}



}



// Main function for fast curving
void HighOrderMeshFastCurving(GModel *gm, FastCurvingParameters &p)
{
  double t1 = Cpu();

  Msg::StatusBar(true, "Optimizing high order mesh...");
  std::vector<GEntity*> allEntities;
  gm->getEntities(allEntities);

  // Compute vert. -> elt. connectivity
  Msg::Info("Computing connectivity...");
  std::map<MVertex*, std::vector<MElement *> > vertex2elements;
  for (int iEnt = 0; iEnt < allEntities.size(); ++iEnt)
    calcVertex2Elements(p.dim, allEntities[iEnt], vertex2elements);

  // Get BL field (if any)
  BoundaryLayerField *blf = getBLField(gm);

  // Build multimap of each geometric entity to its boundaries
  std::multimap<GEntity*,GEntity*> entities;
  if (blf) {                                                                                    // BF field?
    for (int iEnt = 0; iEnt < allEntities.size(); ++iEnt) {
      GEntity* &entity = allEntities[iEnt];
      if (entity->dim() == p.dim && (!p.onlyVisible || entity->getVisibility()))                // Consider only "domain" entities
        if (p.dim == 2) {                                                                       // "Domain" face?
          std::list<GEdge*> edges = entity->edges();
          for (std::list<GEdge*>::iterator itEd = edges.begin(); itEd != edges.end(); itEd++)   // Loop over model boundary edges
            if (blf->isEdgeBL((*itEd)->tag()))                                                  // Already skip model edge if no BL there
              entities.insert(std::pair<GEntity*,GEntity*>(entity, *itEd));
        }
      //        else if (p.dim == 3) {                                                                  // "Domain" region?
      //          std::list<GFace*> faces = entity->faces();
      //          for (std::list<GFace*>::iterator itF = faces.begin(); itF != faces.end(); itF++)      // Loop over model boundary faces
      //            if (blf->isFaceBL((*itF)->tag()))                                                   // Already skip model face if no BL there
      //              entities.insert(std::pair<GEntity*,GEntity*>(entity, *itF));
      //        }
    }
  }
  else {                                                                                        // No BL field
    for (int iEnt = 0; iEnt < allEntities.size(); ++iEnt) {
      GEntity *dummy = 0;
      GEntity* &entity = allEntities[iEnt];
      if (entity->dim() == p.dim-1 && (!p.onlyVisible || entity->getVisibility()))              // Consider boundary entities
        entities.insert(std::pair<GEntity*,GEntity*>(dummy, entity));
    }
  }

  // Build normals if necessary
  std::map<GEntity*, std::map<MVertex*, SVector3> > normVertEnt;                                // Normal to each vertex for each geom. entity
  if (!blf) {
    Msg::Warning("Boundary layer data not found, trying to detect columns");
    buildNormals(vertex2elements, entities, p, normVertEnt);
  }

  // Loop over geometric entities
  for (std::multimap<GEntity*,GEntity*>::iterator itBE = entities.begin();
       itBE != entities.end(); itBE++) {
    GEntity *domEnt = itBE->first, *bndEnt = itBE->second;
    BoundaryLayerColumns *blc = 0;
    if (blf) {
      Msg::Info("Curving elements for entity %d bounding entity %d...",
                bndEnt->tag(), domEnt->tag());
      if (p.dim == 2)
        blc = domEnt->cast2Face()->getColumns();
      else if (p.dim == 3)
        blc = domEnt->cast2Region()->getColumns();
      else
        Msg::Error("Fast curving implemented only in dim. 2 and 3");
    }
    else
      Msg::Info("Curving elements for boundary entity %d...", bndEnt->tag());
    std::map<MVertex*, SVector3> &normVert = normVertEnt[bndEnt];
    curveMeshFromBnd(vertex2elements, normVert, blc, bndEnt, p);
  }

  double t2 = Cpu();

  Msg::StatusBar(true, "Done curving high order mesh (%g s)", t2-t1);
}
