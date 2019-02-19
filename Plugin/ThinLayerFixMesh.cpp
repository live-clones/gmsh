// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Nicolas Kowalski

#include "ThinLayerFixMesh.h"
#include "GModel.h"
#include "robustPredicates.h"
#include "GRegion.h"
#if defined(HAVE_MESH)
#include "meshGFaceDelaunayInsertion.h"
#endif

extern "C" {
GMSH_Plugin *GMSH_RegisterThinLayerFixMeshPlugin()
{
  return new GMSH_ThinLayerFixMeshPlugin();
}
}

std::string GMSH_ThinLayerFixMeshPlugin::getHelp() const
{
  return "Fix the mesh in thin parts";
}

int GMSH_ThinLayerFixMeshPlugin::getNbOptions() const { return 0; }

StringXNumber *GMSH_ThinLayerFixMeshPlugin::getOption(int iopt) { return 0; }

#if defined(HAVE_MESH)

const double GMSH_ThinLayerFixMeshPlugin::epsilon = 0.00000000001;
const double GMSH_ThinLayerFixMeshPlugin::angleMax = 0.9;
const double GMSH_ThinLayerFixMeshPlugin::distP2PMax = 5.0;

CorrespVerticesFixMesh::CorrespVerticesFixMesh() {}
CorrespVerticesFixMesh::~CorrespVerticesFixMesh() {}
void CorrespVerticesFixMesh::setStartPoint(MVertex *v) { this->StartPoint = v; }
void CorrespVerticesFixMesh::setEndPoint(SPoint3 p) { this->EndPoint = p; }
void CorrespVerticesFixMesh::setStartNormal(SVector3 v)
{
  this->StartNormal = v;
}
void CorrespVerticesFixMesh::setEndNormal(SVector3 v) { this->EndNormal = v; }
void CorrespVerticesFixMesh::setEndTrianglePoint1(MVertex *v)
{
  this->EndTrianglePoint1 = v;
}
void CorrespVerticesFixMesh::setEndTrianglePoint2(MVertex *v)
{
  this->EndTrianglePoint2 = v;
}
void CorrespVerticesFixMesh::setEndTrianglePoint3(MVertex *v)
{
  this->EndTrianglePoint3 = v;
}
void CorrespVerticesFixMesh::setdistP2P(double d) { this->distP2P = d; }
void CorrespVerticesFixMesh::setangleProd(double a) { this->angleProd = a; }
void CorrespVerticesFixMesh::setActive(bool b) { this->Active = b; }
void CorrespVerticesFixMesh::setEndTriangleActive(bool b)
{
  this->EndTriangleActive = b;
}
void CorrespVerticesFixMesh::setIsMaster(bool b) { this->IsMaster = b; }
void CorrespVerticesFixMesh::setTagMaster(int i) { this->tagMaster = i; }
MVertex *CorrespVerticesFixMesh::getStartPoint() { return StartPoint; }
SPoint3 CorrespVerticesFixMesh::getEndPoint() { return EndPoint; }
SVector3 CorrespVerticesFixMesh::getStartNormal() { return StartNormal; }
SVector3 CorrespVerticesFixMesh::getEndNormal() { return EndNormal; }
MVertex *CorrespVerticesFixMesh::getEndTrianglePoint1()
{
  return EndTrianglePoint1;
}
MVertex *CorrespVerticesFixMesh::getEndTrianglePoint2()
{
  return EndTrianglePoint2;
}
MVertex *CorrespVerticesFixMesh::getEndTrianglePoint3()
{
  return EndTrianglePoint3;
}
double CorrespVerticesFixMesh::getdistP2P() { return distP2P; }
double CorrespVerticesFixMesh::getangleProd() { return angleProd; }
bool CorrespVerticesFixMesh::getActive() { return Active; }
bool CorrespVerticesFixMesh::getEndTriangleActive()
{
  return EndTriangleActive;
}
bool CorrespVerticesFixMesh::getIsMaster() { return IsMaster; }
int CorrespVerticesFixMesh::getTagMaster() { return tagMaster; }

PView *GMSH_ThinLayerFixMeshPlugin::execute(PView *view)
{
  GMSH_ThinLayerFixMeshPlugin::perform();
  return view;
}

void GMSH_ThinLayerFixMeshPlugin::perform()
{
  VertexToTets.clear();
  TetToTet4.clear();
  VertexToCorresp.clear();
  vecOfThinSheets.clear();
  GMSH_ThinLayerFixMeshPlugin::fillVertexToTets();
  GMSH_ThinLayerFixMeshPlugin::fillTetToTet4();
  std::map<MVertex *, double> AllDist =
    GMSH_ThinLayerFixMeshPlugin::computeAllDistToOppSide();
  GMSH_ThinLayerFixMeshPlugin::checkOppositeTriangles();
  GMSH_ThinLayerFixMeshPlugin::fillvecOfThinSheets();
  for(std::size_t i = 0; i < vecOfThinSheets.size(); i++) {
    if(vecOfThinSheets[i].size() > 1) {
      GFace *OnSurf;
      for(std::size_t j = 0; j < vecOfThinSheets[i].size(); j++) {
        // find a point on the surface
        MVertex *vertOnSurf = vecOfThinSheets[i][j]->getEndTrianglePoint1();
        if(vertOnSurf->onWhat()->dim() < 2) {
          vertOnSurf = vecOfThinSheets[i][j]->getEndTrianglePoint2();
        }
        if(vertOnSurf->onWhat()->dim() < 2) {
          vertOnSurf = vecOfThinSheets[i][j]->getEndTrianglePoint3();
        }
        OnSurf = dynamic_cast<GFace *>(vertOnSurf->onWhat());
        SPoint2 ParOnSurf =
          OnSurf->parFromPoint(vecOfThinSheets[i][j]->getEndPoint(), 1);
        MVertex *StartPo = vecOfThinSheets[i][j]->getStartPoint();
        double param1 = 0.0;
        double param2 = 0.0;
        StartPo->getParameter(0, param1);
        StartPo->getParameter(1, param2);
        MFaceVertex *v =
          new MFaceVertex(vecOfThinSheets[i][j]->getEndPoint().x(),
                          vecOfThinSheets[i][j]->getEndPoint().y(),
                          vecOfThinSheets[i][j]->getEndPoint().z(), OnSurf,
                          ParOnSurf.x(), ParOnSurf.y());
        OnSurf->setMeshingAlgo(ALGO_2D_PACK_PRLGRMS_CSTR);
        OnSurf->constr_vertices.insert(v);
      }
    }
  }
  for(std::map<MVertex *, std::vector<CorrespVerticesFixMesh *> >::iterator
        it1 = VertexToCorresp.begin();
      it1 != VertexToCorresp.end(); it1++) {
    std::vector<CorrespVerticesFixMesh *> vecCorr = (*it1).second;
    for(std::size_t i = 0; i < vecCorr.size(); i++) {
      delete vecCorr[i];
    }
  }
}

void GMSH_ThinLayerFixMeshPlugin::checkOppositeTriangles()
{
  // all endTriangle will be set to active or not
  for(std::map<MVertex *, std::vector<CorrespVerticesFixMesh *> >::iterator
        it1 = VertexToCorresp.begin();
      it1 != VertexToCorresp.end(); it1++) {
    std::vector<CorrespVerticesFixMesh *> vecCorr = (*it1).second;
    for(std::size_t i = 0; i < vecCorr.size(); i++) {
      CorrespVerticesFixMesh *currentCorr = vecCorr[i];
      MVertex *endP0 = currentCorr->getEndTrianglePoint1();
      MVertex *endP1 = currentCorr->getEndTrianglePoint2();
      MVertex *endP2 = currentCorr->getEndTrianglePoint3();
      std::map<MVertex *, std::vector<CorrespVerticesFixMesh *> >::iterator
        it2 = VertexToCorresp.find(endP0);
      std::map<MVertex *, std::vector<CorrespVerticesFixMesh *> >::iterator
        it3 = VertexToCorresp.find(endP1);
      std::map<MVertex *, std::vector<CorrespVerticesFixMesh *> >::iterator
        it4 = VertexToCorresp.find(endP2);
      (*it1).second[i]->setEndTriangleActive(false);
      bool test0 = false;
      bool test1 = false;
      bool test2 = false;
      if(endP0->onWhat()->dim() < 2) {
        test0 = true;
      }
      if(endP1->onWhat()->dim() < 2) {
        test1 = true;
      }
      if(endP2->onWhat()->dim() < 2) {
        test2 = true;
      }
      if(it2 != VertexToCorresp.end()) {
        if((*it2).second.size() > 0) {
          if((*it2).second[0]->getActive()) {
            test0 = true;
          }
        }
      }
      if(it3 != VertexToCorresp.end()) {
        if((*it3).second.size() > 0) {
          if((*it3).second[0]->getActive()) {
            test1 = true;
          }
        }
      }
      if(it4 != VertexToCorresp.end()) {
        if((*it4).second.size() > 0) {
          if((*it4).second[0]->getActive()) {
            test2 = true;
          }
        }
      }
      if(test0) {
        if(test1) {
          if(test2) {
            (*it1).second[i]->setEndTriangleActive(true);
          }
        }
      }
    }
  }
}

void GMSH_ThinLayerFixMeshPlugin::fillvecOfThinSheets()
{
  for(std::map<MVertex *, std::vector<CorrespVerticesFixMesh *> >::iterator
        it1 = VertexToCorresp.begin();
      it1 != VertexToCorresp.end(); it1++) {
    std::vector<CorrespVerticesFixMesh *> vecCorr = (*it1).second;
    for(std::size_t i = 0; i < vecCorr.size(); i++) {
      CorrespVerticesFixMesh *currentCorr = vecCorr[i];
      if(currentCorr->getStartPoint()->onWhat()->dim() == 2)
        if(currentCorr->getActive())
          if(currentCorr->getEndTriangleActive())
            if(currentCorr->getTagMaster() == (-2))
              if((currentCorr->getStartPoint()->onWhat()->dim() == 2) &&
                 (currentCorr->getActive()) &&
                 (currentCorr->getEndTriangleActive()) &&
                 (currentCorr->getTagMaster() == (-2))) {
                // Found the first node of a new master sheet
                std::vector<CorrespVerticesFixMesh *> MasterSheet;
                MasterSheet.clear();
                (*it1).second[i]->setTagMaster(-1);
                {
                  std::map<MVertex *,
                           std::vector<CorrespVerticesFixMesh *> >::iterator
                    it2 = VertexToCorresp.find(
                      (*it1).second[i]->getEndTrianglePoint1());
                  if(it2 != VertexToCorresp.end()) {
                    if((*it2).second.size() > 0) {
                      if((*it1)
                           .second[i]
                           ->getEndTrianglePoint1()
                           ->onWhat()
                           ->dim() == 2) {
                        (*it2).second[0]->setTagMaster(
                          (*it1).second[i]->getStartPoint()->onWhat()->tag());
                      }
                    }
                  }
                  it2 = VertexToCorresp.find(
                    (*it1).second[i]->getEndTrianglePoint2());
                  if(it2 != VertexToCorresp.end()) {
                    if((*it2).second.size() > 0) {
                      if((*it1)
                           .second[i]
                           ->getEndTrianglePoint2()
                           ->onWhat()
                           ->dim() == 2) {
                        (*it2).second[0]->setTagMaster(
                          (*it1).second[i]->getStartPoint()->onWhat()->tag());
                      }
                    }
                  }
                  it2 = VertexToCorresp.find(
                    (*it1).second[i]->getEndTrianglePoint3());
                  if(it2 != VertexToCorresp.end()) {
                    if((*it2).second.size() > 0) {
                      if((*it1)
                           .second[i]
                           ->getEndTrianglePoint3()
                           ->onWhat()
                           ->dim() == 2) {
                        (*it2).second[0]->setTagMaster(
                          (*it1).second[i]->getStartPoint()->onWhat()->tag());
                      }
                    }
                  }
                }
                MasterSheet.push_back((*it1).second[i]);
                std::set<MVertex *> CurrentSheet;
                CurrentSheet.clear();
                CurrentSheet.insert((*it1).second[i]->getStartPoint());
                while(CurrentSheet.size() != 0) {
                  MVertex *VToDo = (*CurrentSheet.begin());
                  std::vector<MTetrahedron *> surroundingTet =
                    VertexToTets[VToDo];
                  for(std::size_t j = 0; j < surroundingTet.size(); j++) {
                    for(std::size_t k = 0;
                        k < surroundingTet[j]->getNumVertices(); k++) {
                      MVertex *ToInsertTmp = surroundingTet[j]->getVertex(k);
                      std::map<MVertex *,
                               std::vector<CorrespVerticesFixMesh *> >::iterator
                        it2 = VertexToCorresp.find(ToInsertTmp);
                      if(ToInsertTmp->onWhat()->tag() ==
                         VToDo->onWhat()->tag()) { // TODO: OR that onwhat ->
                                                   // dim <, for edges
                        if(it2 != VertexToCorresp.end()) {
                          if((*it2).second.size() > 0) {
                            CorrespVerticesFixMesh *correspToInsert =
                              ((*it2).second)[0];
                            if(correspToInsert->getStartPoint()
                                 ->onWhat()
                                 ->dim() == 2)
                              if(correspToInsert->getActive())
                                if(correspToInsert->getEndTriangleActive())
                                  if(correspToInsert->getTagMaster() == (-2))
                                    if((correspToInsert->getStartPoint()
                                          ->onWhat()
                                          ->dim() == 2) &&
                                       (correspToInsert->getActive()) &&
                                       (correspToInsert
                                          ->getEndTriangleActive()) &&
                                       (correspToInsert->getTagMaster() ==
                                        (-2))) {
                                      MasterSheet.push_back((*it2).second[0]);
                                      (*it2).second[0]->setTagMaster(-1);
                                      {
                                        std::map<
                                          MVertex *,
                                          std::vector<CorrespVerticesFixMesh
                                                        *> >::iterator it3 =
                                          VertexToCorresp.find(
                                            (*it2)
                                              .second[0]
                                              ->getEndTrianglePoint1());
                                        if(it3 != VertexToCorresp.end()) {
                                          if((*it3).second.size() > 0) {
                                            if((*it2)
                                                 .second[0]
                                                 ->getEndTrianglePoint1()
                                                 ->onWhat()
                                                 ->dim() == 2) {
                                              (*it3).second[0]->setTagMaster(
                                                (*it2)
                                                  .second[i]
                                                  ->getStartPoint()
                                                  ->onWhat()
                                                  ->tag());
                                            }
                                          }
                                        }
                                        it3 = VertexToCorresp.find(
                                          (*it2)
                                            .second[0]
                                            ->getEndTrianglePoint2());
                                        if(it3 != VertexToCorresp.end()) {
                                          if((*it3).second.size() > 0) {
                                            if((*it2)
                                                 .second[0]
                                                 ->getEndTrianglePoint2()
                                                 ->onWhat()
                                                 ->dim() == 2) {
                                              (*it3).second[0]->setTagMaster(
                                                (*it2)
                                                  .second[i]
                                                  ->getStartPoint()
                                                  ->onWhat()
                                                  ->tag());
                                            }
                                          }
                                        }
                                        it3 = VertexToCorresp.find(
                                          (*it2)
                                            .second[0]
                                            ->getEndTrianglePoint3());
                                        if(it3 != VertexToCorresp.end()) {
                                          if((*it3).second.size() > 0) {
                                            if((*it2)
                                                 .second[0]
                                                 ->getEndTrianglePoint3()
                                                 ->onWhat()
                                                 ->dim() == 2) {
                                              (*it3).second[0]->setTagMaster(
                                                (*it2)
                                                  .second[i]
                                                  ->getStartPoint()
                                                  ->onWhat()
                                                  ->tag());
                                            }
                                          }
                                        }
                                      }
                                      CurrentSheet.insert(ToInsertTmp);
                                    }
                          }
                        }
                      }
                    }
                  }
                  CurrentSheet.erase(VToDo);
                }
                vecOfThinSheets.push_back(MasterSheet);
              }
    }
  }
}
std::map<MVertex *, double>
GMSH_ThinLayerFixMeshPlugin::computeAllDistToOppSide()
{
  std::map<MVertex *, double> AllDistToOppSide;
  AllDistToOppSide.clear();
  GModel *m = GModel::current();
  std::set<MVertex *> BoundaryVertices;
  int countdown = 0;

  for(GModel::riter itr = m->firstRegion(); itr != m->lastRegion(); itr++) {
    GRegion *rTmp = (*itr);
    for(std::size_t i = 0; i < rTmp->tetrahedra.size(); i++) {
      countdown++;
      MTet4 *tet4Tmp = TetToTet4[rTmp->tetrahedra[i]];
      for(std::size_t j = 0; j < 4; j++) {
        if(tet4Tmp->getNeigh(j) == 0) {
          faceXtetFM fxtTmp(tet4Tmp, j);
          for(int k = 0; k < 3; k++) {
            MVertex *toTest = fxtTmp.v[k];
            if(toTest->onWhat()->dim() == 2) {
              if(BoundaryVertices.find(toTest) == BoundaryVertices.end()) {
                BoundaryVertices.insert(toTest);
              }
            }
          }
        }
      }
    }
  }
  countdown = 0;
  for(std::set<MVertex *>::iterator it = BoundaryVertices.begin();
      it != BoundaryVertices.end(); it++) {
    countdown++;
    MVertex *toCompute = (*it);
    double resultTmp = computeDistToOppSide(toCompute);
    AllDistToOppSide.insert(std::make_pair(toCompute, resultTmp));
    AllDistToOppSide[toCompute] = resultTmp;
  }
  return AllDistToOppSide;
}

double GMSH_ThinLayerFixMeshPlugin::computeDistToOppSide(MVertex *v)
{
  double DistToOppSide = 0.0;
  // We assume v is on the boundary
  // First we need to get the internal normal
  SVector3 InteriorNormal =
    GMSH_ThinLayerFixMeshPlugin::computeInteriorNormal(v);
  // Then we find the first triangle
  MTet4 *FirstTet =
    GMSH_ThinLayerFixMeshPlugin::getTetFromPoint(v, InteriorNormal);
  MTet4 *CurrentTet = FirstTet;
  MTet4 *PastTet = FirstTet;
  SPoint3 CurrentPos = SPoint3(v->x(), v->y(), v->z());
  SPoint3 LastPos = CurrentPos;
  int CurrentTriValue = 0;
  int *CurrentTri = &CurrentTriValue;
  CorrespVerticesFixMesh *CVTemp = new CorrespVerticesFixMesh();
  CorrespVerticesFixMesh CVTemp2;
  CVTemp->setStartPoint(v);
  CVTemp2.setStartPoint(v);
  CVTemp->setStartNormal(InteriorNormal);
  CVTemp2.setStartNormal(InteriorNormal);
  FindNewPoint((&CurrentPos), CurrentTri, &CurrentTet, InteriorNormal);
  DistToOppSide += CurrentPos.distance(LastPos);
  LastPos = CurrentPos;
  std::size_t countWhile = 0, prevprevtet = 1, prevtet = 2;
  while((CurrentTet != 0) && (countWhile < 50)) {
    countWhile++;
    faceXtetFM fxtCVtmp(PastTet, (*CurrentTri));
    PastTet = CurrentTet;
    CVTemp->setEndTrianglePoint1(
      PastTet->tet()->getVertex(faces[(*CurrentTri)][0]));
    CVTemp->setEndTrianglePoint2(
      PastTet->tet()->getVertex(faces[(*CurrentTri)][1]));
    CVTemp->setEndTrianglePoint3(
      PastTet->tet()->getVertex(faces[(*CurrentTri)][2]));
    CVTemp2.setEndTrianglePoint1(
      PastTet->tet()->getVertex(faces[(*CurrentTri)][0]));
    CVTemp2.setEndTrianglePoint2(
      PastTet->tet()->getVertex(faces[(*CurrentTri)][1]));
    CVTemp2.setEndTrianglePoint3(
      PastTet->tet()->getVertex(faces[(*CurrentTri)][2]));
    FindNewPoint((&CurrentPos), CurrentTri, &CurrentTet, InteriorNormal);
    DistToOppSide += CurrentPos.distance(LastPos);
    LastPos = CurrentPos;

    if(CurrentTet != 0) {
      if((CurrentTet->tet()->getNum()) == prevprevtet) {
        while(1) {
        }
      }
      prevprevtet = prevtet;
      prevtet = CurrentTet->tet()->getNum();
    }
  }
  CVTemp->setEndPoint(LastPos);
  CVTemp2.setEndPoint(LastPos);
  faceXtetFM fxtCV(PastTet, (*CurrentTri));
  CVTemp->setEndTrianglePoint1(
    PastTet->tet()->getVertex(faces[(*CurrentTri)][0]));
  CVTemp->setEndTrianglePoint2(
    PastTet->tet()->getVertex(faces[(*CurrentTri)][1]));
  CVTemp->setEndTrianglePoint3(
    PastTet->tet()->getVertex(faces[(*CurrentTri)][2]));
  CVTemp2.setEndTrianglePoint1(
    PastTet->tet()->getVertex(faces[(*CurrentTri)][0]));
  CVTemp2.setEndTrianglePoint2(
    PastTet->tet()->getVertex(faces[(*CurrentTri)][1]));
  CVTemp2.setEndTrianglePoint3(
    PastTet->tet()->getVertex(faces[(*CurrentTri)][2]));
  SVector3 EndNormal(-InteriorNormal.x(), -InteriorNormal.y(),
                     -InteriorNormal.z());
  EndNormal.normalize();
  CVTemp->setEndNormal(EndNormal);
  CVTemp2.setEndNormal(EndNormal);
  CVTemp->setangleProd(
    fabs(CVTemp->getStartNormal().x() * CVTemp->getEndNormal().x() +
         CVTemp->getStartNormal().y() * CVTemp->getEndNormal().y() +
         CVTemp->getStartNormal().z() * CVTemp->getEndNormal().z()));
  CVTemp2.setangleProd(
    fabs(CVTemp2.getStartNormal().x() * CVTemp2.getEndNormal().x() +
         CVTemp2.getStartNormal().y() * CVTemp2.getEndNormal().y() +
         CVTemp2.getStartNormal().z() * CVTemp2.getEndNormal().z()));
  CVTemp->setdistP2P(DistToOppSide);
  CVTemp2.setdistP2P(DistToOppSide);
  if((CVTemp->getangleProd() > angleMax) &&
     (CVTemp->getdistP2P() < distP2PMax)) {
    CVTemp->setActive(true);
  }
  else {
    CVTemp->setActive(false);
  }
  if((CVTemp2.getangleProd() > angleMax) &&
     (CVTemp2.getdistP2P() < distP2PMax)) {
    CVTemp2.setActive(true);
  }
  else {
    CVTemp2.setActive(false);
  }
  CVTemp->setTagMaster(-2);
  CVTemp2.setTagMaster(-2);
  VertexToCorresp[v].push_back(CVTemp);
  return DistToOppSide;
}

SVector3 GMSH_ThinLayerFixMeshPlugin::computeInteriorNormal(MVertex *v)
{
  SPoint3 InteriorNormal(0.0, 0.0, 0.0);
  std::vector<MTetrahedron *> currentVecTet = VertexToTets[v];
  std::vector<SPoint3> vecInteriorNodes;
  std::vector<SPoint3> vecFirstDir;
  std::vector<SPoint3> vecSecondDir;
  for(std::size_t i = 0; i < currentVecTet.size(); i++) {
    MTet4 *tet4Tmp = TetToTet4[currentVecTet[i]];
    for(int j = 0; j < 4; j++) {
      if(tet4Tmp->getNeigh(j) == 0) {
        // find the 4th point,and fill the two vector of the boundary triangle
        faceXtetFM fxtTmp(tet4Tmp, j);
        for(int k = 0; k < 4; k++) {
          bool foundInteriorPoint = true;
          for(int l = 0; l < 3; l++) {
            if(tet4Tmp->tet()->getVertex(k) == fxtTmp.v[l]) {
              foundInteriorPoint = false;
            }
          }
          if(foundInteriorPoint) {
            SPoint3 pointTmp(tet4Tmp->tet()->getVertex(k)->x(),
                             tet4Tmp->tet()->getVertex(k)->y(),
                             tet4Tmp->tet()->getVertex(k)->z());
            vecInteriorNodes.push_back(pointTmp);
          }
        }
        SPoint3 pointTmp1(fxtTmp.v[1]->x() - fxtTmp.v[0]->x(),
                          fxtTmp.v[1]->y() - fxtTmp.v[0]->y(),
                          fxtTmp.v[1]->z() - fxtTmp.v[0]->z());
        SPoint3 pointTmp2(fxtTmp.v[2]->x() - fxtTmp.v[0]->x(),
                          fxtTmp.v[2]->y() - fxtTmp.v[0]->y(),
                          fxtTmp.v[2]->z() - fxtTmp.v[0]->z());
        vecFirstDir.push_back(pointTmp1);
        vecSecondDir.push_back(pointTmp2);
      }
    }
  }
  // at this point we have all the info necessary.
  SPoint3 pointInteriorAverage(0.0, 0.0, 0.0);
  for(std::size_t i = 0; i < vecInteriorNodes.size(); i++) {
    pointInteriorAverage +=
      SPoint3(vecInteriorNodes[i].x(), vecInteriorNodes[i].y(),
              vecInteriorNodes[i].z());
  }
  pointInteriorAverage =
    SPoint3(pointInteriorAverage.x() / (double(vecInteriorNodes.size())),
            pointInteriorAverage.y() / (double(vecInteriorNodes.size())),
            pointInteriorAverage.z() / (double(vecInteriorNodes.size())));
  SPoint3 dirInteriorAverage(pointInteriorAverage.x() - v->x(),
                             pointInteriorAverage.y() - v->y(),
                             pointInteriorAverage.z() - v->z());
  double norme = sqrt(dirInteriorAverage.x() * dirInteriorAverage.x() +
                      dirInteriorAverage.y() * dirInteriorAverage.y() +
                      dirInteriorAverage.z() * dirInteriorAverage.z());
  dirInteriorAverage =
    SPoint3(dirInteriorAverage.x() / norme, dirInteriorAverage.y() / norme,
            dirInteriorAverage.z() / norme);
  std::vector<SPoint3> vecOrthogDir;
  for(std::size_t i = 0; i < vecFirstDir.size(); i++) {
    SPoint3 pointTmp(vecFirstDir[i].y() * vecSecondDir[i].z() -
                       vecFirstDir[i].z() * vecSecondDir[i].y(),
                     vecFirstDir[i].z() * vecSecondDir[i].x() -
                       vecFirstDir[i].x() * vecSecondDir[i].z(),
                     vecFirstDir[i].x() * vecSecondDir[i].y() -
                       vecFirstDir[i].y() * vecSecondDir[i].x());
    vecOrthogDir.push_back(pointTmp);
  }
  for(std::size_t i = 0; i < vecOrthogDir.size(); i++) {
    double prodScalTmp = vecOrthogDir[i].x() * dirInteriorAverage.x() +
                         vecOrthogDir[i].y() * dirInteriorAverage.y() +
                         vecOrthogDir[i].z() * dirInteriorAverage.z();
    if(prodScalTmp < 0.0) {
      vecOrthogDir[i] = SPoint3(-vecOrthogDir[i].x(), -vecOrthogDir[i].y(),
                                -vecOrthogDir[i].z());
    }
    double normeTmp = sqrt(vecOrthogDir[i].x() * vecOrthogDir[i].x() +
                           vecOrthogDir[i].y() * vecOrthogDir[i].y() +
                           vecOrthogDir[i].z() * vecOrthogDir[i].z());
    vecOrthogDir[i] =
      SPoint3(vecOrthogDir[i].x() / normeTmp, vecOrthogDir[i].y() / normeTmp,
              vecOrthogDir[i].z() / normeTmp);
    InteriorNormal +=
      SPoint3(vecOrthogDir[i].x(), vecOrthogDir[i].y(), vecOrthogDir[i].z());
  }
  norme = sqrt(InteriorNormal.x() * InteriorNormal.x() +
               InteriorNormal.y() * InteriorNormal.y() +
               InteriorNormal.z() * InteriorNormal.z());
  InteriorNormal =
    SPoint3(InteriorNormal.x() / norme, InteriorNormal.y() / norme,
            InteriorNormal.z() / norme);
  return InteriorNormal;
}

MTet4 *GMSH_ThinLayerFixMeshPlugin::getTetFromPoint(MVertex *v,
                                                    SVector3 InteriorNormal)
{
  MTet4 *TetToGet = 0;
  std::vector<MTetrahedron *> currentVecTet = VertexToTets[v];
  for(std::size_t i = 0; i < currentVecTet.size(); i++) {
    std::vector<SVector3> vecDir;
    for(int j = 0; j < 4; j++) {
      if(currentVecTet[i]->getVertex(j) != v) {
        SVector3 DirTmp(currentVecTet[i]->getVertex(j)->x() - v->x(),
                        currentVecTet[i]->getVertex(j)->y() - v->y(),
                        currentVecTet[i]->getVertex(j)->z() - v->z());
        vecDir.push_back(DirTmp);
      }
    }
    bool IsPositiv = GMSH_ThinLayerFixMeshPlugin::IsPositivOrientation(
      vecDir[0], vecDir[1], vecDir[2]);
    if(!IsPositiv) {
      SVector3 DirTmp1 = vecDir[1];
      SVector3 DirTmp2 = vecDir[0];
      SVector3 DirTmp3 = vecDir[2];
      vecDir.clear();
      vecDir.push_back(DirTmp1);
      vecDir.push_back(DirTmp2);
      vecDir.push_back(DirTmp3);
    }
    bool isPositiv1 = GMSH_ThinLayerFixMeshPlugin::IsPositivOrientation(
      vecDir[0], vecDir[1], InteriorNormal);
    bool isPositiv2 = GMSH_ThinLayerFixMeshPlugin::IsPositivOrientation(
      vecDir[1], vecDir[2], InteriorNormal);
    bool isPositiv3 = GMSH_ThinLayerFixMeshPlugin::IsPositivOrientation(
      vecDir[2], vecDir[0], InteriorNormal);
    if(isPositiv1) {
      if(isPositiv2) {
        if(isPositiv3) {
          TetToGet = TetToTet4[currentVecTet[i]];
         }
      }
    }
  }
   return TetToGet;
}

bool GMSH_ThinLayerFixMeshPlugin::IsPositivOrientation(SVector3 a, SVector3 b,
                                                       SVector3 c)
{
  bool result = false;
  SPoint3 ProdVec(a.y() * b.z() - a.z() * b.y(), a.z() * b.x() - a.x() * b.z(),
                  a.x() * b.y() - a.y() * b.x());
  double ProdScal =
    ProdVec.x() * c.x() + ProdVec.y() * c.y() + ProdVec.z() * c.z();
  if(ProdScal >= 0.0) {
    result = true;
  }
  return result;
}

void GMSH_ThinLayerFixMeshPlugin::FindNewPoint(SPoint3 *CurrentPoint,
                                               int *CurrentTri,
                                               MTet4 **CurrentTet,
                                               SVector3 InteriorNormal)
{
  double distanceP2P = 0.0;
  double alphaMax = 0.0;
  double betaMax = 0.0;
  SPoint3 ResultPoint;
  int triToGet = -1;
  for(std::size_t n = 0; n < 4; n++) {
    // calculer matrice a inverser
    faceXtetFM fxt((*CurrentTet), n);
    double a = fxt.v[1]->x() - fxt.v[0]->x();
    double b = fxt.v[2]->x() - fxt.v[0]->x();
    double c = InteriorNormal.x();
    double d = fxt.v[1]->y() - fxt.v[0]->y();
    double e = fxt.v[2]->y() - fxt.v[0]->y();
    double f = InteriorNormal.y();
    double g = fxt.v[1]->z() - fxt.v[0]->z();
    double h = fxt.v[2]->z() - fxt.v[0]->z();
    double i = InteriorNormal.z();
    // produit matrice inverse par vecteur donne poids
    double detMat =
      a * e * i + b * f * g + c * d * h - c * e * g - f * h * a - i * b * d;
    double ai = e * i - f * h;
    double bi = c * h - b * i;
    double ci = b * f - c * e;
    double di = f * g - d * i;
    double ei = a * i - c * g;
    double fi = c * d - a * f;
    double oppx = (*CurrentPoint).x() - fxt.v[0]->x();
    double oppy = (*CurrentPoint).y() - fxt.v[0]->y();
    double oppz = (*CurrentPoint).z() - fxt.v[0]->z();
    double alpha = ai / detMat * oppx + bi / detMat * oppy + ci / detMat * oppz;
    double beta = di / detMat * oppx + ei / detMat * oppy + fi / detMat * oppz;
    // Test si poids entre 0 et 1 et si length maximale
    if((alpha >= (0.0 - epsilon)) && (alpha <= (1.0 + epsilon))) {
      if((beta >= (0.0 - epsilon)) && (beta <= (1.0 + epsilon))) {
        if(((1.0 - alpha - beta) >= (0.0 - epsilon)) &&
           ((1.0 - alpha - beta) <= (1.0 + epsilon))) {
          SPoint3 PointTmp(
            fxt.v[0]->x() + alpha * (fxt.v[1]->x() - fxt.v[0]->x()) +
              beta * (fxt.v[2]->x() - fxt.v[0]->x()),
            fxt.v[0]->y() + alpha * (fxt.v[1]->y() - fxt.v[0]->y()) +
              beta * (fxt.v[2]->y() - fxt.v[0]->y()),
            fxt.v[0]->z() + alpha * (fxt.v[1]->z() - fxt.v[0]->z()) +
              beta * (fxt.v[2]->z() - fxt.v[0]->z()));
          double distanceTmp = PointTmp.distance((*CurrentPoint));
          if(distanceTmp > distanceP2P) {
            distanceP2P = distanceTmp;
            ResultPoint = PointTmp;
            triToGet = n;
            alphaMax = alpha;
            betaMax = beta;
          }
        }
      }
    }
  }
  // test si trop proche d'un point / une arete
  if(((alphaMax < epsilon) && (betaMax < epsilon)) ||
     ((alphaMax < epsilon) && ((1.0 - alphaMax - betaMax) < epsilon)) ||
     (((1.0 - alphaMax - betaMax) < epsilon) && (betaMax < epsilon))) {
    // proche d'un point
    double DistMinTmp = 10000000.0;
    int indexMinTmp = 0;
    for(std::size_t i = 0; i < 4; i++) {
      double distanceTmp =
        sqrt(((*CurrentTet)->tet()->getVertex(i)->x() - ResultPoint.x()) *
               ((*CurrentTet)->tet()->getVertex(i)->x() - ResultPoint.x()) +
             ((*CurrentTet)->tet()->getVertex(i)->y() - ResultPoint.y()) *
               ((*CurrentTet)->tet()->getVertex(i)->y() - ResultPoint.y()) +
             ((*CurrentTet)->tet()->getVertex(i)->z() - ResultPoint.z()) *
               ((*CurrentTet)->tet()->getVertex(i)->z() - ResultPoint.z()));
      if(distanceTmp < DistMinTmp) {
        DistMinTmp = distanceTmp;
        indexMinTmp = i;
      }
    }
    MTet4 *NewTet = GMSH_ThinLayerFixMeshPlugin::getTetFromPoint(
      (*CurrentTet)->tet()->getVertex(indexMinTmp), InteriorNormal);
    SPoint3 PointTmp((*CurrentTet)->tet()->getVertex(indexMinTmp)->x(),
                     (*CurrentTet)->tet()->getVertex(indexMinTmp)->y(),
                     (*CurrentTet)->tet()->getVertex(indexMinTmp)->z());
    (*CurrentPoint) = PointTmp;
    (*CurrentTet) = NewTet;
  }
  else if((alphaMax < epsilon) || (betaMax < epsilon) ||
          ((1.0 - alphaMax - betaMax) < epsilon)) {
    // trop proche d'une arete
  }
  else {
    (*CurrentPoint) = ResultPoint;
    (*CurrentTri) = triToGet;
    (*CurrentTet) = (*CurrentTet)->getNeigh(triToGet);
  }
}

void GMSH_ThinLayerFixMeshPlugin::fillVertexToTets()
{
  GModel *m = GModel::current();
  for(GModel::riter itr = m->firstRegion(); itr != m->lastRegion(); itr++) {
    GRegion *rTmp = (*itr);
    for(std::size_t i = 0; i < rTmp->tetrahedra.size(); i++) {
      MTetrahedron *elem = rTmp->tetrahedra[i];
      for(std::size_t j = 0; j < 4; j++) {
        std::vector<MTetrahedron *> emptyTetVec;
        emptyTetVec.clear();
        VertexToTets[elem->getVertex(j)] = emptyTetVec;
        std::vector<CorrespVerticesFixMesh *> emptyCVVec;
        emptyCVVec.clear();
        VertexToCorresp[elem->getVertex(j)] = emptyCVVec;
      }
    }
  }
  for(GModel::riter itr = m->firstRegion(); itr != m->lastRegion(); itr++) {
    GRegion *rTmp = (*itr);
    for(std::size_t i = 0; i < rTmp->tetrahedra.size(); i++) {
      MTetrahedron *elem = rTmp->tetrahedra[i];
      for(std::size_t j = 0; j < 4; j++) {
        VertexToTets[elem->getVertex(j)].push_back(elem);
      }
    }
  }
}

static void setLcsFM(MTriangle *t, std::map<MVertex *, double> &vSizes,
                     std::set<MVertex *> &bndVertices)
{
  for(int i = 0; i < 3; i++) {
    bndVertices.insert(t->getVertex(i));
    MEdge e = t->getEdge(i);
    MVertex *vi = e.getVertex(0);
    MVertex *vj = e.getVertex(1);
    double dx = vi->x() - vj->x();
    double dy = vi->y() - vj->y();
    double dz = vi->z() - vj->z();
    double l = sqrt(dx * dx + dy * dy + dz * dz);
    std::map<MVertex *, double>::iterator iti = vSizes.find(vi);
    std::map<MVertex *, double>::iterator itj = vSizes.find(vj);
    // use largest edge length
    if(iti == vSizes.end() || iti->second < l) vSizes[vi] = l;
    if(itj == vSizes.end() || itj->second < l) vSizes[vj] = l;
  }
}

static void setLcsFM(MTetrahedron *t, std::map<MVertex *, double> &vSizes,
                     std::set<MVertex *> &bndVertices)
{
  for(int i = 0; i < 4; i++) {
    for(int j = i + 1; j < 4; j++) {
      MVertex *vi = t->getVertex(i);
      MVertex *vj = t->getVertex(j);
      double dx = vi->x() - vj->x();
      double dy = vi->y() - vj->y();
      double dz = vi->z() - vj->z();
      double l = sqrt(dx * dx + dy * dy + dz * dz);
      std::map<MVertex *, double>::iterator iti = vSizes.find(vi);
      std::map<MVertex *, double>::iterator itj = vSizes.find(vj);
      std::set<MVertex *>::iterator itvi = bndVertices.find(vi);
      std::set<MVertex *>::iterator itvj = bndVertices.find(vj);
      // smallest tet edge
      if(itvi == bndVertices.end() && (iti == vSizes.end() || iti->second > l))
        vSizes[vi] = l;
      if(itvj == bndVertices.end() && (itj == vSizes.end() || itj->second > l))
        vSizes[vj] = l;
    }
  }
}

void GMSH_ThinLayerFixMeshPlugin::fillTetToTet4()
{
  GModel *m = GModel::current();
  std::vector<double> vSizes;
  std::vector<double> vSizesBGM;
  MTet4Factory myFactory(1600000);
  std::set<MTet4 *, compareTet4Ptr> &allTets = myFactory.getAllTets();
  std::set<MTet4 *, compareTet4Ptr> activeTets;
  int NUM = 0;

  for(GModel::riter itr = m->firstRegion(); itr != m->lastRegion(); itr++) {
    GRegion *gr = (*itr);
    { // leave this in a block so the map gets deallocated directly
      std::map<MVertex *, double> vSizesMap;
      std::set<MVertex *> bndVertices;
      for(GModel::fiter it = gr->model()->firstFace();
          it != gr->model()->lastFace(); ++it) {
        GFace *gf = *it;
        for(std::size_t i = 0; i < gf->triangles.size(); i++) {
          setLcsFM(gf->triangles[i], vSizesMap, bndVertices);
        }
      }
      for(std::size_t i = 0; i < gr->tetrahedra.size(); i++)
        setLcsFM(gr->tetrahedra[i], vSizesMap, bndVertices);
      for(std::map<MVertex *, double>::iterator it = vSizesMap.begin();
          it != vSizesMap.end(); ++it) {
        it->first->setIndex(NUM++);
        vSizes.push_back(it->second);
        vSizesBGM.push_back(it->second);
      }
    }
    for(std::size_t i = 0; i < gr->tetrahedra.size(); i++) {
      MTet4 *currentTet4 =
        myFactory.Create(gr->tetrahedra[i], vSizes, vSizesBGM);
      TetToTet4[gr->tetrahedra[i]] = currentTet4;
      allTets.insert(currentTet4);
    }
  }

  std::vector<MTet4 *> vecAllTet4;
  vecAllTet4.clear();
  for(std::set<MTet4 *, compareTet4Ptr>::iterator itTp = allTets.begin();
      itTp != allTets.end(); itTp++) {
    vecAllTet4.push_back((*itTp));
    //		//std::cout<<"inserted "<<(*itTp)->tet()->getNum()<<std::endl;
  }
  connectTets(vecAllTet4);
}

std::map<MVertex *, std::vector<MTetrahedron *> >
  GMSH_ThinLayerFixMeshPlugin::VertexToTets;
std::map<MTetrahedron *, MTet4 *> GMSH_ThinLayerFixMeshPlugin::TetToTet4;
std::map<MVertex *, std::vector<CorrespVerticesFixMesh *> >
  GMSH_ThinLayerFixMeshPlugin::VertexToCorresp;
std::vector<std::vector<CorrespVerticesFixMesh *> >
  GMSH_ThinLayerFixMeshPlugin::vecOfThinSheets;

#else

PView *GMSH_ThinLayerFixMeshPlugin::execute(PView *view)
{
  Msg::Error("Plugin(ThinLayerFixMesh requires mesh module");
  return view;
}

#endif
