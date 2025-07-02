// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Nicolas Kowalski

#include "ThinLayer.h"
#include "GModel.h"
#include "robustPredicates.h"
#include "GRegion.h"

std::map<MVertex *, std::vector<MTetrahedron *> > ThinLayer::VertexToTets;
std::map<MTetrahedron *, MTet4 *> ThinLayer::TetToTet4;
std::map<MVertex *, std::vector<CorrespVertices *> > ThinLayer::VertexToCorresp;
std::vector<std::vector<CorrespVertices *> > ThinLayer::vecOfThinSheets;
const double ThinLayer::epsilon = 0.00001;
const double ThinLayer::angleMax = 0.9;
const double ThinLayer::distP2PMax = 0.3;

CorrespVertices::CorrespVertices() {}
CorrespVertices::~CorrespVertices() {}
void CorrespVertices::setStartPoint(MVertex *v) { this->StartPoint = v; }
void CorrespVertices::setEndPoint(const SPoint3 &p) { this->EndPoint = p; }
void CorrespVertices::setStartNormal(const SVector3 &v)
{
  this->StartNormal = v;
}
void CorrespVertices::setEndNormal(const SVector3 &v) { this->EndNormal = v; }
void CorrespVertices::setEndTriangle(faceXtet f) { this->EndTriangle = f; }
void CorrespVertices::setdistP2P(double d) { this->distP2P = d; }
void CorrespVertices::setangleProd(double a) { this->angleProd = a; }
void CorrespVertices::setActive(bool b) { this->Active = b; }
void CorrespVertices::setEndTriangleActive(bool b)
{
  this->EndTriangleActive = b;
}
void CorrespVertices::setIsMaster(bool b) { this->IsMaster = b; }
void CorrespVertices::setTagMaster(int i) { this->tagMaster = i; }
MVertex *CorrespVertices::getStartPoint() { return StartPoint; }
SPoint3 CorrespVertices::getEndPoint() { return EndPoint; }
SVector3 CorrespVertices::getStartNormal() { return StartNormal; }
SVector3 CorrespVertices::getEndNormal() { return EndNormal; }
faceXtet CorrespVertices::getEndTriangle() { return EndTriangle; }
double CorrespVertices::getdistP2P() { return distP2P; }
double CorrespVertices::getangleProd() { return angleProd; }
bool CorrespVertices::getActive() { return Active; }
bool CorrespVertices::getEndTriangleActive() { return EndTriangleActive; }
bool CorrespVertices::getIsMaster() { return IsMaster; }
int CorrespVertices::getTagMaster() { return tagMaster; }

ThinLayer::ThinLayer() {}

ThinLayer::~ThinLayer() {}

void ThinLayer::perform()
{
  ThinLayer::fillVertexToTets();
  ThinLayer::fillTetToTet4();
  std::map<MVertex *, double> AllDist = ThinLayer::computeAllDistToOppSide();
  ThinLayer::checkOppositeTriangles();
  ThinLayer::fillvecOfThinSheets();
  std::set<MVertex *> constr_vertices;
}

void ThinLayer::checkOppositeTriangles()
{
  // all endTriangle will be set to active or not
  for(std::map<MVertex *, std::vector<CorrespVertices *> >::iterator it1 =
        VertexToCorresp.begin();
      it1 != VertexToCorresp.end(); it1++) {
    std::vector<CorrespVertices *> vecCorr = (*it1).second;
    for(unsigned int i = 0; i < vecCorr.size(); i++) {
      CorrespVertices *currentCorr = vecCorr[i];
      faceXtet currentEndTri = currentCorr->getEndTriangle();
      MVertex *endP0 = currentEndTri.v[0];
      MVertex *endP1 = currentEndTri.v[1];
      MVertex *endP2 = currentEndTri.v[2];
      std::map<MVertex *, std::vector<CorrespVertices *> >::iterator it2 =
        VertexToCorresp.find(endP0);
      std::map<MVertex *, std::vector<CorrespVertices *> >::iterator it3 =
        VertexToCorresp.find(endP1);
      std::map<MVertex *, std::vector<CorrespVertices *> >::iterator it4 =
        VertexToCorresp.find(endP2);
      (*it1).second[i]->setEndTriangleActive(false);
      if(it2 != VertexToCorresp.end()) {
        if(it3 != VertexToCorresp.end()) {
          if(it4 != VertexToCorresp.end()) {
            if((*it2).second[0]->getActive()) {
              if((*it3).second[0]->getActive()) {
                if((*it4).second[0]->getActive()) {
                  (*it1).second[i]->setEndTriangleActive(true);
                }
              }
            }
          }
        }
      }
    }
  }
}

void ThinLayer::fillvecOfThinSheets()
{
  for(std::map<MVertex *, std::vector<CorrespVertices *> >::iterator it1 =
        VertexToCorresp.begin();
      it1 != VertexToCorresp.end(); it1++) {
    std::vector<CorrespVertices *> vecCorr = (*it1).second;
    for(unsigned int i = 0; i < vecCorr.size(); i++) {
      CorrespVertices *currentCorr = vecCorr[i];
      if((currentCorr->getStartPoint()->onWhat()->dim() == 2) &&
         (currentCorr->getActive()) && (currentCorr->getEndTriangleActive()) &&
         (currentCorr->getTagMaster() == (-2))) {
        // Found the first node of a new master sheet
        std::vector<CorrespVertices *> MasterSheet;
        MasterSheet.clear();
        (*it1).second[i]->setTagMaster(-1);
        faceXtet faceEndSlave = (*it1).second[i]->getEndTriangle();
        for(unsigned int j = 0; j < 3; j++) {
          std::map<MVertex *, std::vector<CorrespVertices *> >::iterator it2 =
            VertexToCorresp.find(faceEndSlave.v[j]);
          if(it2 != VertexToCorresp.end()) {
            if(faceEndSlave.v[j]->onWhat()->dim() == 2) {
              (*it2).second[0]->setTagMaster(
                (*it1).second[i]->getStartPoint()->onWhat()->tag());
            }
          }
        }
        MasterSheet.push_back((*it1).second[i]);
        std::set<MVertex *> CurrentSheet;
        CurrentSheet.clear();
        CurrentSheet.insert((*it1).second[i]->getStartPoint());
        while(CurrentSheet.size() != 0) {
          MVertex *VToDo = (*CurrentSheet.begin());
          std::vector<MTetrahedron *> surroundingTet = VertexToTets[VToDo];
          for(unsigned int j = 0; j < surroundingTet.size(); j++) {
            for(std::size_t k = 0; k < surroundingTet[j]->getNumVertices();
                k++) {
              MVertex *ToInsertTmp = surroundingTet[j]->getVertex(k);
              std::map<MVertex *, std::vector<CorrespVertices *> >::iterator
                it2 = VertexToCorresp.find(ToInsertTmp);
              if(ToInsertTmp->onWhat()->tag() == VToDo->onWhat()->tag()) {
                // TODO: OR that onwhat -> dim <, for edges
                if(it2 != VertexToCorresp.end()) {
                  CorrespVertices *correspToInsert = ((*it2).second)[0];
                  if((correspToInsert->getStartPoint()->onWhat()->dim() == 2) &&
                     (correspToInsert->getActive()) &&
                     (correspToInsert->getEndTriangleActive()) &&
                     (correspToInsert->getTagMaster() == (-2))) {
                    MasterSheet.push_back((*it2).second[0]);
                    (*it2).second[0]->setTagMaster(-1);
                    faceXtet faceEndSlave2 = (*it2).second[0]->getEndTriangle();
                    for(unsigned int j = 0; j < 3; j++) {
                      std::map<MVertex *,
                               std::vector<CorrespVertices *> >::iterator it3 =
                        VertexToCorresp.find(faceEndSlave2.v[j]);
                      if(it3 != VertexToCorresp.end()) {
                        if(faceEndSlave2.v[j]->onWhat()->dim() == 2) {
                          (*it3).second[0]->setTagMaster(
                            (*it2).second[i]->getStartPoint()->onWhat()->tag());
                        }
                      }
                    }
                    CurrentSheet.insert(ToInsertTmp);
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

std::map<MVertex *, double> ThinLayer::computeAllDistToOppSide()
{
  std::map<MVertex *, double> AllDistToOppSide;
  GModel *m = GModel::current();
  // std::vector<MElement*> crackElements;
  std::set<MVertex *> BoundaryVertices;

  for(GModel::riter itr = m->firstRegion(); itr != m->lastRegion(); itr++) {
    GRegion *rTmp = (*itr);
    for(unsigned int i = 0; i < rTmp->tetrahedra.size(); i++) {
      MTet4 *tet4Tmp = TetToTet4[rTmp->tetrahedra[i]];
      for(unsigned int j = 0; j < 4; j++) {
        if(tet4Tmp->getNeigh(j) == 0) {
          // find the 4th point,and fill the two vector of the boundary triangle
          faceXtet fxtTmp(tet4Tmp, j);
          for(int k = 0; k < 3; k++) {
            MVertex *toTest = fxtTmp.v[k];
            if(toTest->onWhat()->dim() == 2) {
              if(BoundaryVertices.find(toTest) == BoundaryVertices.end()) {
                BoundaryVertices.insert(toTest);
              }
            }
          }
          // crackElements.push_back(rTmp->getMeshElement(j));
        }
      }
    }
  }
  for(std::set<MVertex *>::iterator it = BoundaryVertices.begin();
      it != BoundaryVertices.end(); it++) {
    MVertex *toCompute = (*it);
    double resultTmp = computeDistToOppSide(toCompute);
    AllDistToOppSide[toCompute] = resultTmp;
  }

  return AllDistToOppSide;
}

double ThinLayer::computeDistToOppSide(MVertex *v)
{
  double DistToOppSide = 0.;
  // We assume v is on the boundary
  // First we need to get the internal normal
  SVector3 InteriorNormal = ThinLayer::computeInteriorNormal(v);
  // Then we find the first triangle
  MTet4 *FirstTet = ThinLayer::getTetFromPoint(v, InteriorNormal);
  MTet4 *CurrentTet = FirstTet;
  MTet4 *PastTet = FirstTet;
  SPoint3 CurrentPos = SPoint3(v->x(), v->y(), v->z());
  SPoint3 LastPos = CurrentPos;
  int *CurrentTri = 0;
  CorrespVertices CVTemp;
  CVTemp.setStartPoint(v);
  CVTemp.setStartNormal(InteriorNormal);
  FindNewPoint((&CurrentPos), CurrentTri, CurrentTet, InteriorNormal);
  faceXtet fxtCV(CurrentTet, (*CurrentTri));
  //	while(CurrentTet->getNeigh((*CurrentTri)) != 0){
  while(CurrentTet != 0) {
    PastTet = CurrentTet;
    faceXtet fxtCVtmp(PastTet, (*CurrentTri));
    FindNewPoint((&CurrentPos), CurrentTri, CurrentTet, InteriorNormal);
    CurrentTet = CurrentTet->getNeigh((*CurrentTri));
    DistToOppSide += CurrentPos.distance(LastPos);
    LastPos = CurrentPos;
  }
  CVTemp.setEndPoint(LastPos);
  CVTemp.setEndTriangle(fxtCV);
  SVector3 EndDir1(fxtCV.v[1]->x() - fxtCV.v[0]->x(),
                   fxtCV.v[1]->y() - fxtCV.v[0]->y(),
                   fxtCV.v[1]->z() - fxtCV.v[0]->z());
  SVector3 EndDir2(fxtCV.v[2]->x() - fxtCV.v[0]->x(),
                   fxtCV.v[2]->y() - fxtCV.v[0]->y(),
                   fxtCV.v[2]->z() - fxtCV.v[0]->z());
  SVector3 EndNormal(EndDir1.y() * EndDir2.z() - EndDir1.z() * EndDir2.y(),
                     EndDir1.z() * EndDir2.x() - EndDir1.x() * EndDir2.z(),
                     EndDir1.x() * EndDir2.y() - EndDir1.y() * EndDir2.x());
  EndNormal.normalize();
  CVTemp.setEndNormal(EndNormal);
  CVTemp.setangleProd(
    fabs(CVTemp.getStartNormal().x() * CVTemp.getEndNormal().x() +
         CVTemp.getStartNormal().y() * CVTemp.getEndNormal().y() +
         CVTemp.getStartNormal().z() * CVTemp.getEndNormal().z()));
  CVTemp.setdistP2P(DistToOppSide);
  if((CVTemp.getangleProd() > angleMax) && (CVTemp.getdistP2P() < distP2PMax)) {
    CVTemp.setActive(true);
  }
  else {
    CVTemp.setActive(false);
  }
  CVTemp.setTagMaster(-2);
  VertexToCorresp[v].push_back(&CVTemp);
  return DistToOppSide;
}

SVector3 ThinLayer::computeInteriorNormal(MVertex *v)
{
  SPoint3 InteriorNormal(0.0, 0.0, 0.0);
  std::vector<MTetrahedron *> currentVecTet = VertexToTets[v];
  std::vector<SPoint3> vecInteriorNodes;
  std::vector<SPoint3> vecFirstDir;
  std::vector<SPoint3> vecSecondDir;
  for(unsigned int i = 0; i < currentVecTet.size(); i++) {
    MTet4 *tet4Tmp = TetToTet4[currentVecTet[i]];
    for(int j = 0; j < 4; j++) {
      if(tet4Tmp->getNeigh(j) == 0) {
        // find the 4th point,and fill the two vector of the boundary triangle
        faceXtet fxtTmp(tet4Tmp, j);
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
  for(unsigned int i = 0; i < vecInteriorNodes.size(); i++) {
    pointInteriorAverage +=
      SPoint3(vecInteriorNodes[i].x(), vecInteriorNodes[i].y(),
              vecInteriorNodes[i].z());
    // pointInteriorAverage.x() += vecInteriorNodes[i].x();
    // pointInteriorAverage.y() += vecInteriorNodes[i].y();
    // pointInteriorAverage.z() += vecInteriorNodes[i].z();
  }
  pointInteriorAverage =
    SPoint3(pointInteriorAverage.x() / (double(vecInteriorNodes.size())),
            pointInteriorAverage.y() / (double(vecInteriorNodes.size())),
            pointInteriorAverage.z() / (double(vecInteriorNodes.size())));
  // pointInteriorAverage.x() = pointInteriorAverage.x() /
  // (double(vecInteriorNodes.size())); pointInteriorAverage.y() =
  // pointInteriorAverage.y() / (double(vecInteriorNodes.size()));
  // pointInteriorAverage.z() = pointInteriorAverage.z() /
  // (double(vecInteriorNodes.size()));
  SPoint3 dirInteriorAverage(pointInteriorAverage.x() - v->x(),
                             pointInteriorAverage.y() - v->y(),
                             pointInteriorAverage.z() - v->z());
  double norme = sqrt(dirInteriorAverage.x() * dirInteriorAverage.x() +
                      dirInteriorAverage.y() * dirInteriorAverage.y() +
                      dirInteriorAverage.z() * dirInteriorAverage.z());
  dirInteriorAverage =
    SPoint3(dirInteriorAverage.x() / norme, dirInteriorAverage.y() / norme,
            dirInteriorAverage.z() / norme);
  // dirInteriorAverage.x() = dirInteriorAverage.x() / norme;
  // dirInteriorAverage.y() = dirInteriorAverage.y() / norme;
  // dirInteriorAverage.z() = dirInteriorAverage.z() / norme;
  std::vector<SPoint3> vecOrthogDir;
  for(unsigned int i = 0; i < vecFirstDir.size(); i++) {
    SPoint3 pointTmp(vecFirstDir[i].y() * vecSecondDir[i].z() -
                       vecFirstDir[i].z() * vecSecondDir[i].y(),
                     vecFirstDir[i].z() * vecSecondDir[i].x() -
                       vecFirstDir[i].x() * vecSecondDir[i].z(),
                     vecFirstDir[i].x() * vecSecondDir[i].y() -
                       vecFirstDir[i].y() * vecSecondDir[i].x());
    vecOrthogDir.push_back(pointTmp);
  }
  for(unsigned int i = 0; i < vecOrthogDir.size(); i++) {
    double prodScalTmp = vecOrthogDir[i].x() * dirInteriorAverage.x() +
                         vecOrthogDir[i].y() * dirInteriorAverage.y() +
                         vecOrthogDir[i].z() * dirInteriorAverage.z();
    if(prodScalTmp < 0.0) {
      vecOrthogDir[i] = SPoint3(-vecOrthogDir[i].x(), -vecOrthogDir[i].y(),
                                -vecOrthogDir[i].z());
      // vecOrthogDir[i].x() = - vecOrthogDir[i].x();
      // vecOrthogDir[i].y() = - vecOrthogDir[i].y();
      // vecOrthogDir[i].z() = - vecOrthogDir[i].z();
    }
    double normeTmp = sqrt(vecOrthogDir[i].x() * vecOrthogDir[i].x() +
                           vecOrthogDir[i].y() * vecOrthogDir[i].y() +
                           vecOrthogDir[i].z() * vecOrthogDir[i].z());
    vecOrthogDir[i] =
      SPoint3(vecOrthogDir[i].x() / normeTmp, vecOrthogDir[i].y() / normeTmp,
              vecOrthogDir[i].z() / normeTmp);
    // vecOrthogDir[i].x() = vecOrthogDir[i].x() / normeTmp;
    // vecOrthogDir[i].y() = vecOrthogDir[i].y() / normeTmp;
    // vecOrthogDir[i].z() = vecOrthogDir[i].z() / normeTmp;
    InteriorNormal +=
      SPoint3(vecOrthogDir[i].x(), vecOrthogDir[i].y(), vecOrthogDir[i].z());
    // InteriorNormal.x() += vecOrthogDir[i].x();
    // InteriorNormal.y() += vecOrthogDir[i].y();
    // InteriorNormal.z() += vecOrthogDir[i].z();
  }
  norme = sqrt(InteriorNormal.x() * InteriorNormal.x() +
               InteriorNormal.y() * InteriorNormal.y() +
               InteriorNormal.z() * InteriorNormal.z());
  InteriorNormal =
    SPoint3(InteriorNormal.x() / norme, InteriorNormal.y() / norme,
            InteriorNormal.z() / norme);
  // InteriorNormal.x() = InteriorNormal.x() / norme;
  // InteriorNormal.y() = InteriorNormal.y() / norme;
  // InteriorNormal.z() = InteriorNormal.z() / norme;
  return InteriorNormal;
}

MTet4 *ThinLayer::getTetFromPoint(MVertex *v, const SVector3 &InteriorNormal)
{
  MTet4 *TetToGet = 0;
  std::vector<MTetrahedron *> currentVecTet = VertexToTets[v];
  for(unsigned int i = 0; i < currentVecTet.size(); i++) {
    std::vector<SVector3> vecDir;
    for(int j = 0; j < 4; j++) {
      if(currentVecTet[i]->getVertex(j) != v) {
        SVector3 DirTmp(currentVecTet[i]->getVertex(j)->x() - v->x(),
                        currentVecTet[i]->getVertex(j)->y() - v->y(),
                        currentVecTet[i]->getVertex(j)->z() - v->z());
        vecDir.push_back(DirTmp);
      }
    }
    bool IsPositiv =
      ThinLayer::IsPositivOrientation(vecDir[0], vecDir[1], vecDir[2]);
    if(!IsPositiv) {
      SVector3 DirTmp1 = vecDir[1];
      SVector3 DirTmp2 = vecDir[0];
      SVector3 DirTmp3 = vecDir[2];
      vecDir.clear();
      vecDir.push_back(DirTmp1);
      vecDir.push_back(DirTmp2);
      vecDir.push_back(DirTmp3);
    }
    bool isPositiv1 =
      ThinLayer::IsPositivOrientation(vecDir[0], vecDir[1], InteriorNormal);
    bool isPositiv2 =
      ThinLayer::IsPositivOrientation(vecDir[1], vecDir[2], InteriorNormal);
    bool isPositiv3 =
      ThinLayer::IsPositivOrientation(vecDir[2], vecDir[0], InteriorNormal);
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

bool ThinLayer::IsPositivOrientation(const SVector3 &a, const SVector3 &b,
                                     const SVector3 &c)
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

void ThinLayer::FindNewPoint(SPoint3 *CurrentPoint, int *CurrentTri,
                             MTet4 *CurrentTet, const SVector3 &InteriorNormal)
{
  double distanceP2P = 0.0;
  double alphaMax = 0.0;
  double betaMax = 0.0;
  SPoint3 ResultPoint;
  int triToGet = 0;
  for(unsigned int n = 0; n < 4; n++) {
    // calculer matrice a inverser
    faceXtet fxt(CurrentTet, n);
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
    // double gi = d * h - e * g;
    // double hi = b * g - a * h;
    // double ii = a * e - b * d;
    double oppx = (*CurrentPoint).x() - fxt.v[0]->x();
    double oppy = (*CurrentPoint).y() - fxt.v[0]->y();
    double oppz = (*CurrentPoint).z() - fxt.v[0]->z();
    double alpha = ai / detMat * oppx + bi / detMat * oppy + ci / detMat * oppz;
    double beta = di / detMat * oppx + ei / detMat * oppy + fi / detMat * oppz;
    // double gamma = gi / detMat * oppx + hi / detMat * oppy + ii / detMat *
    // oppz;
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
    for(unsigned int i = 0; i < 4; i++) {
      double distanceTmp =
        sqrt((CurrentTet->tet()->getVertex(i)->x() - ResultPoint.x()) *
               (CurrentTet->tet()->getVertex(i)->x() - ResultPoint.x()) +
             (CurrentTet->tet()->getVertex(i)->y() - ResultPoint.y()) *
               (CurrentTet->tet()->getVertex(i)->y() - ResultPoint.y()) +
             (CurrentTet->tet()->getVertex(i)->z() - ResultPoint.z()) *
               (CurrentTet->tet()->getVertex(i)->z() - ResultPoint.z()));
      if(distanceTmp < DistMinTmp) {
        DistMinTmp = distanceTmp;
        indexMinTmp = i;
      }
    }
    MTet4 *NewTet = ThinLayer::getTetFromPoint(
      CurrentTet->tet()->getVertex(indexMinTmp), InteriorNormal);
    SPoint3 PointTmp(CurrentTet->tet()->getVertex(indexMinTmp)->x(),
                     CurrentTet->tet()->getVertex(indexMinTmp)->y(),
                     CurrentTet->tet()->getVertex(indexMinTmp)->z());
    (*CurrentPoint) = PointTmp;
    CurrentTet = NewTet;
  }
  else if((alphaMax < epsilon) || (betaMax < epsilon) ||
          ((1.0 - alphaMax - betaMax) < epsilon)) {
    // trop proche d'une arete
  }
  else {
    (*CurrentPoint) = ResultPoint;
    (*CurrentTri) = triToGet;
    CurrentTet = CurrentTet->getNeigh(triToGet);
  }
}

void ThinLayer::fillVertexToTets()
{
  GModel *m = GModel::current();
  for(GModel::riter itr = m->firstRegion(); itr != m->lastRegion(); itr++) {
    GRegion *rTmp = (*itr);
    for(unsigned int i = 0; i < rTmp->tetrahedra.size(); i++) {
      MTetrahedron *elem = rTmp->tetrahedra[i];
      for(unsigned int j = 0; j < 4; j++) {
        std::vector<MTetrahedron *> emptyTetVec;
        emptyTetVec.clear();
        VertexToTets[elem->getVertex(j)] = emptyTetVec;
        std::vector<CorrespVertices *> emptyCVVec;
        emptyCVVec.clear();
        VertexToCorresp[elem->getVertex(j)] = emptyCVVec;
      }
    }
  }
  for(GModel::riter itr = m->firstRegion(); itr != m->lastRegion(); itr++) {
    GRegion *rTmp = (*itr);
    for(unsigned int i = 0; i < rTmp->tetrahedra.size(); i++) {
      MTetrahedron *elem = rTmp->tetrahedra[i];
      for(unsigned int j = 0; j < 4; j++) {
        VertexToTets[elem->getVertex(j)].push_back(elem);
      }
    }
  }
}

void ThinLayer::fillTetToTet4()
{
  GModel *m = GModel::current();
  std::vector<MTet4 *> vecAllTet4;
  vecAllTet4.clear();
  for(GModel::riter itr = m->firstRegion(); itr != m->lastRegion(); itr++) {
    GRegion *rTmp = (*itr);
    for(unsigned int i = 0; i < rTmp->tetrahedra.size(); i++) {
      MTetrahedron *elem = rTmp->tetrahedra[i];
      MTet4 tet4tmp = MTet4(elem, 0.0);
      MTet4 *currentTet4 = &tet4tmp;
      TetToTet4[elem] = currentTet4;
      vecAllTet4.clear();
    }
  }
  connectTets(vecAllTet4);
}
