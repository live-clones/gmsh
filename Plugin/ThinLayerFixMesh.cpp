// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.
//
// Author: Nicolas Kowalski

#include "ThinLayerFixMesh.h"
#include "GModel.h"
#include "robustPredicates.h"
#include "GRegion.h"
#if defined(HAVE_MESH)
#include "meshGFaceDelaunayInsertion.h"
#endif

extern "C"
{
  GMSH_Plugin *GMSH_RegisterThinLayerFixMeshPlugin()
  {
    return new GMSH_ThinLayerFixMeshPlugin();
  }
}

std::string GMSH_ThinLayerFixMeshPlugin::getHelp() const
{
  return "Fix the mesh in thin parts";
}

int GMSH_ThinLayerFixMeshPlugin::getNbOptions() const
{
  return 0;
}

StringXNumber *GMSH_ThinLayerFixMeshPlugin::getOption(int iopt)
{
  return 0;
}


#if defined(HAVE_MESH)

const double GMSH_ThinLayerFixMeshPlugin::epsilon = 0.00000000001;
const double GMSH_ThinLayerFixMeshPlugin::angleMax = 0.9;
const double GMSH_ThinLayerFixMeshPlugin::distP2PMax = 5.0;

CorrespVerticesFixMesh::CorrespVerticesFixMesh(){
  //	std::cout<<"started init CorrespVerticesFixMesh"<<std::endl;
  //	this->EndTriangle = faceXtetFM();
  //	this->StartPoint = 0;
  //	this->EndPoint = SPoint3(0.0,0.0,0.0);
  //	this->StartNormal = SVector3(0.0,0.0,0.0);
  //	this->EndNormal = SVector3(0.0,0.0,0.0);
  //	this->distP2P = 0.0;
  //	this->angleProd = 0.0;
  //	this->Active = false;
  //	this->EndTriangleActive = false;
  //	this->IsMaster = false;
  //	this->tagMaster = 0;
  //	std::cout<<"completed init CorrespVerticesFixMesh"<<std::endl;
}
CorrespVerticesFixMesh::~CorrespVerticesFixMesh(){}
void CorrespVerticesFixMesh::setStartPoint(MVertex* v){
  this->StartPoint = v;
}
void CorrespVerticesFixMesh::setEndPoint(SPoint3 p){
  this->EndPoint = p;
}
void CorrespVerticesFixMesh::setStartNormal(SVector3 v){
  this->StartNormal = v;
}
void CorrespVerticesFixMesh::setEndNormal(SVector3 v){
  this->EndNormal = v;
}
//void CorrespVerticesFixMesh::setEndTriangle(faceXtetFM f){
//	this->EndTriangle(f.t1,f.i1);
//}
void CorrespVerticesFixMesh::setEndTrianglePoint1(MVertex* v){
  this->EndTrianglePoint1 = v;
}
void CorrespVerticesFixMesh::setEndTrianglePoint2(MVertex* v){
  this->EndTrianglePoint2 = v;
}
void CorrespVerticesFixMesh::setEndTrianglePoint3(MVertex* v){
  this->EndTrianglePoint3 = v;
}
void CorrespVerticesFixMesh::setdistP2P(double d){
  this->distP2P = d;
}
void CorrespVerticesFixMesh::setangleProd(double a){
  this->angleProd = a;
}
void CorrespVerticesFixMesh::setActive(bool b){
  this->Active = b;
}
void CorrespVerticesFixMesh::setEndTriangleActive(bool b){
  this->EndTriangleActive = b;
}
void CorrespVerticesFixMesh::setIsMaster(bool b){
  this->IsMaster = b;
}
void CorrespVerticesFixMesh::setTagMaster(int i){
  this->tagMaster = i;
}
MVertex* CorrespVerticesFixMesh::getStartPoint(){
  return StartPoint;
}
SPoint3 CorrespVerticesFixMesh::getEndPoint(){
  return EndPoint;
}
SVector3 CorrespVerticesFixMesh::getStartNormal(){
  return StartNormal;
}
SVector3 CorrespVerticesFixMesh::getEndNormal(){
  return EndNormal;
}
//faceXtetFM CorrespVerticesFixMesh::getEndTriangle(){
//	return EndTriangle;
//}
MVertex* CorrespVerticesFixMesh::getEndTrianglePoint1(){
  return EndTrianglePoint1;
}
MVertex* CorrespVerticesFixMesh::getEndTrianglePoint2(){
  return EndTrianglePoint2;
}
MVertex* CorrespVerticesFixMesh::getEndTrianglePoint3(){
  return EndTrianglePoint3;
}
double CorrespVerticesFixMesh::getdistP2P(){
  return distP2P;
}
double CorrespVerticesFixMesh::getangleProd(){
  return angleProd;
}
bool CorrespVerticesFixMesh::getActive(){
  return Active;
}
bool CorrespVerticesFixMesh::getEndTriangleActive(){
  return EndTriangleActive;
}
bool CorrespVerticesFixMesh::getIsMaster(){
  return IsMaster;
}
int CorrespVerticesFixMesh::getTagMaster(){
  return tagMaster;
}


PView *GMSH_ThinLayerFixMeshPlugin::execute(PView *view)
{
  // GModel *m = GModel::current();
  GMSH_ThinLayerFixMeshPlugin::perform();
  //	if (m->getDim() == 3){
  //		view = GMSH_DuplicateBoundariesPlugin::executeDuplicate(view);
  //	}
  //	else if (m->getDim() == 2){
  //		view = GMSH_DuplicateBoundariesPlugin::execute2DWithBound(view);
  //	}
  return view;
}

void GMSH_ThinLayerFixMeshPlugin::perform(){
  VertexToTets.clear();
  TetToTet4.clear();
  VertexToCorresp.clear();
  vecOfThinSheets.clear();
  GMSH_ThinLayerFixMeshPlugin::fillVertexToTets();
  GMSH_ThinLayerFixMeshPlugin::fillTetToTet4();
  //std::cout<<"computeAllDistToOppSide"<<std::endl;
  std::map<MVertex*,double> AllDist = GMSH_ThinLayerFixMeshPlugin::computeAllDistToOppSide();
  for (std::map<MVertex*,double>::iterator allDistIt = AllDist.begin();allDistIt != AllDist.end();allDistIt++){
    //std::cout<<"allDist of point "<<(*allDistIt).first->getNum()<<" with Pos "<<(*allDistIt).first->x()<<" ; "<<(*allDistIt).first->z()<<" ; "<<(*allDistIt).first->y()<<" is "<<(*allDistIt).second<<std::endl;
    //std::cout<<"   Size of vertexToCorresp "<<VertexToCorresp[(*allDistIt).first].size()<<std::endl;
    //		//std::cout<<"      Testing FaceXTet out of while fourth time "<<VertexToCorresp[(*allDistIt).first][VertexToCorresp[(*allDistIt).first].size() - 1]->getEndTriangle().t1->tet()->getNum()<<std::endl;
    //std::cout<<"      Testing StartPoint "<<VertexToCorresp[(*allDistIt).first][VertexToCorresp[(*allDistIt).first].size() - 1]->getStartPoint()->getNum()<<std::endl;
    //std::cout<<"      Testing StartNormal "<<VertexToCorresp[(*allDistIt).first][VertexToCorresp[(*allDistIt).first].size() - 1]->getStartNormal().norm()<<std::endl;
  }
  //std::cout<<"checkOppositeTriangles !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<std::endl;
  GMSH_ThinLayerFixMeshPlugin::checkOppositeTriangles();
  //std::cout<<"fillvecOfThinSheets !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<std::endl;
  GMSH_ThinLayerFixMeshPlugin::fillvecOfThinSheets();
  //std::cout<<"Out of fillvecOfThinSheets"<<std::endl;
  //	std::set<MVertex*> constr_vertices;
  for (unsigned int i = 0;i < vecOfThinSheets.size();i++){
    if (vecOfThinSheets[i].size() > 1){
      GFace* OnSurf;
      for (unsigned int j = 0;j < vecOfThinSheets[i].size();j++){
        //find a point on the surface
        MVertex* vertOnSurf = vecOfThinSheets[i][j]->getEndTrianglePoint1();
        if (vertOnSurf->onWhat()->dim() < 2){
          vertOnSurf = vecOfThinSheets[i][j]->getEndTrianglePoint2();
        }
        if (vertOnSurf->onWhat()->dim() < 2){
          vertOnSurf = vecOfThinSheets[i][j]->getEndTrianglePoint3();
        }
        OnSurf = dynamic_cast<GFace*>(vertOnSurf->onWhat());
        SPoint2 ParOnSurf = OnSurf->parFromPoint(vecOfThinSheets[i][j]->getEndPoint(),1);
        MVertex* StartPo = vecOfThinSheets[i][j]->getStartPoint();
        double param1 = 0.0;
        double param2 = 0.0;
        StartPo->getParameter(0,param1);
        StartPo->getParameter(1,param2);
        //std::cout<<" PointBegin is "<<StartPo->x()<<" ; "<<StartPo->y()<<" ; "<<StartPo->z()<<" with param "<<param1<<" ; "<<param2<<std::endl;
        //std::cout<<"insertion of point "<<vecOfThinSheets[i][j]->getEndPoint().x()<<" ; "<<vecOfThinSheets[i][j]->getEndPoint().y()<<" ; "<<vecOfThinSheets[i][j]->getEndPoint().z()<<" with param "<<ParOnSurf.x()<<" ; "<<ParOnSurf.y()<<std::endl;
        MFaceVertex *v = new MFaceVertex(vecOfThinSheets[i][j]->getEndPoint().x(),vecOfThinSheets[i][j]->getEndPoint().y(),vecOfThinSheets[i][j]->getEndPoint().z(),OnSurf,ParOnSurf.x(),ParOnSurf.y());
        OnSurf->setMeshingAlgo(ALGO_2D_PACK_PRLGRMS_CSTR);
        OnSurf->constr_vertices.insert(v);
        //				OnSurf->addMeshVertex(v);
        //				constr_vertices.insert(v);
        //std::cout<<"inserted point with tag "<<v->getNum()<<" on surface "<<OnSurf->tag()<<std::endl;
      }
      //			OnSurf->setMeshingAlgo(ALGO_2D_PACK_PRLGRMS_CSTR);
      //			OnSurf->GFace::deleteMesh();
      //			buildBackGroundMesh (OnSurf);
      //			meshGFace::modifyInitialMeshForTakingIntoAccountBoundaryLayers(OnSurf);
      //			OnSurf->meshStatistics.status = GFace::PENDING;
      //			OnSurf->meshStatistics.nbTriangle = OnSurf->meshStatistics.nbEdge = 0;
      //			OnSurf->correspondingVertices.clear();
      //			std::map<MVertex* , MVertex*>* equivalence;
      //			std::map<MVertex*, SPoint2> * parametricCoordinates;
      //			bowyerWatsonParallelogramsConstrained(OnSurf,constr_vertices);
    }
    //		constr_vertices.clear();
  }
  for (std::map<MVertex*,std::vector<CorrespVerticesFixMesh*> >::iterator it1 = VertexToCorresp.begin();it1 != VertexToCorresp.end();it1++){
    std::vector<CorrespVerticesFixMesh*> vecCorr = (*it1).second;
    for (unsigned int i = 0;i < vecCorr.size();i++){
      delete vecCorr[i];
    }
  }
}

void GMSH_ThinLayerFixMeshPlugin::checkOppositeTriangles(){
  //all endTriangle will be set to active or not
  for (std::map<MVertex*,std::vector<CorrespVerticesFixMesh*> >::iterator it1 = VertexToCorresp.begin();it1 != VertexToCorresp.end();it1++){
    //		std::cout<<"   Entering For"<<std::endl;
    // MVertex* vertTmp = (*it1).first;
    //std::cout<<"   Vert Tested is "<<vertTmp->getNum()<<" and its vector size is "<<(*it1).second.size()<<" pos "<<vertTmp->x()<<" ; "<<vertTmp->y()<<" ; "<<vertTmp->z()<<std::endl;
    std::vector<CorrespVerticesFixMesh*> vecCorr = (*it1).second;
    for (unsigned int i = 0;i < vecCorr.size();i++){
      //std::cout<<"      Entering deeper For"<<std::endl;
      CorrespVerticesFixMesh* currentCorr = vecCorr[i];
      //			std::cout<<"      Step 1"<<std::endl;
      //			faceXtetFM currentEndTri = (*(currentCorr->getEndTriangle()));
      //			std::cout<<"      Step 2"<<std::endl;
      MVertex* endP0 = currentCorr->getEndTrianglePoint1();
      //			std::cout<<"      Step 3"<<std::endl;
      MVertex* endP1 = currentCorr->getEndTrianglePoint2();
      //			std::cout<<"      Step 4"<<std::endl;
      MVertex* endP2 = currentCorr->getEndTrianglePoint3();
      //			std::cout<<"      Step 5"<<std::endl;
      std::map<MVertex*,std::vector<CorrespVerticesFixMesh*> >::iterator it2 = VertexToCorresp.find(endP0);
      //			std::cout<<"      Step 6 ?"<<std::endl;
      //			std::cout<<"      Tet is "<<currentCorr->getEndTriangle().t1->tet()->getNum()<<std::endl;
      //			std::cout<<"      Face number is "<<currentCorr->getEndTriangle().i1<<std::endl;
      //			std::cout<<"      Tet is made of vertex 0 "<<currentCorr->getEndTriangle().t1->tet()->getVertex(0)->getNum()<<std::endl;
      //			std::cout<<"      Tet is made of vertex 1 "<<currentCorr->getEndTriangle().t1->tet()->getVertex(1)->getNum()<<std::endl;
      //			std::cout<<"      Tet is made of vertex 2 "<<currentCorr->getEndTriangle().t1->tet()->getVertex(2)->getNum()<<std::endl;
      //			std::cout<<"      Tet is made of vertex 3 "<<currentCorr->getEndTriangle().t1->tet()->getVertex(3)->getNum()<<std::endl;
      //			std::cout<<"      Adresses of endP0 "<<endP0<<" and endP1 "<<endP1<<" and endP2 "<<endP2<<std::endl;
      //std::cout<<"      endP0 is "<<endP0->getNum()<<" pos "<<endP0->x()<<" ; "<<endP0->y()<<" ; "<<endP0->z()<<std::endl;
      //			std::cout<<"      Step 6"<<std::endl;
      std::map<MVertex*,std::vector<CorrespVerticesFixMesh*> >::iterator it3 = VertexToCorresp.find(endP1);
      //std::cout<<"      endP1 is "<<endP1->getNum()<<" pos "<<endP1->x()<<" ; "<<endP1->y()<<" ; "<<endP1->z()<<std::endl;
      //			std::cout<<"      Step 7"<<std::endl;
      std::map<MVertex*,std::vector<CorrespVerticesFixMesh*> >::iterator it4 = VertexToCorresp.find(endP2);
      //std::cout<<"      endP2 is "<<endP2->getNum()<<" pos "<<endP2->x()<<" ; "<<endP2->y()<<" ; "<<endP2->z()<<std::endl;
      //			std::cout<<"      Step 8"<<std::endl;
      (*it1).second[i]->setEndTriangleActive(false);
      //std::cout<<"      Starting tests"<<std::endl;
      bool test0 = false;
      bool test1 = false;
      bool test2 = false;
      if (endP0->onWhat()->dim() < 2){
        test0 = true;
        //std::cout<<"         test0 true by dim"<<std::endl;
      }
      if (endP1->onWhat()->dim() < 2){
        test1 = true;
        //std::cout<<"         test1 true by dim"<<std::endl;
      }
      if (endP2->onWhat()->dim() < 2){
        test2 = true;
        //std::cout<<"         test2 true by dim"<<std::endl;
      }
      if (it2 != VertexToCorresp.end()){
        if ((*it2).second.size() > 0){
          if ((*it2).second[0]->getActive()){
            test0 = true;
            //std::cout<<"         test0 true by active"<<std::endl;
          }
        }
      }
      if (it3 != VertexToCorresp.end()){
        if ((*it3).second.size() > 0){
          if ((*it3).second[0]->getActive()){
            test1 = true;
            //std::cout<<"         test1 true by active"<<std::endl;
          }
        }
      }
      if (it4 != VertexToCorresp.end()){
        if ((*it4).second.size() > 0){
          if ((*it4).second[0]->getActive()){
            test2 = true;
            //std::cout<<"         test2 true by active"<<std::endl;
          }
        }
      }
      if (test0){
        if (test1){
          if (test2){
            (*it1).second[i]->setEndTriangleActive(true);
            //std::cout<<"                        EndTriangle Activated"<<std::endl;
          }
        }
      }
      //			if (it2 != VertexToCorresp.end()){
      ////				std::cout<<"         Passed Number 1"<<std::endl;
      //				if (it3 != VertexToCorresp.end()){
      ////					std::cout<<"            Passed Number 2"<<std::endl;
      //					if (it4 != VertexToCorresp.end()){
      ////						std::cout<<"               Passed Number 3"<<std::endl;
      //						if (((*it2).second.size() > 0)  || (endP0->onWhat()->dim() < 2)){
      //							std::cout<<"         Passed Number 1 Bis"<<std::endl;
      //							if (((*it3).second.size() > 0)  || (endP1->onWhat()->dim() < 2)){
      //								std::cout<<"            Passed Number 2 Bis"<<std::endl;
      //								if (((*it4).second.size() > 0)  || (endP2->onWhat()->dim() < 2)){
      //									std::cout<<"               Passed Number 3 Bis"<<std::endl;
      //									if (((*it2).second[0]->getActive()) || (endP0->onWhat()->dim() < 2)){
      //										std::cout<<"                  Passed Number 4"<<std::endl;
      //										if (((*it3).second[0]->getActive()) || (endP1->onWhat()->dim() < 2)){
      //											std::cout<<"                     Passed Number 5"<<std::endl;
      //											if (((*it4).second[0]->getActive()) || (endP2->onWhat()->dim() < 2)){
      //												std::cout<<"                        Passed Number 6"<<std::endl;
      //												(*it1).second[i]->setEndTriangleActive(true);
      //											}
      //										}
      //									}
      //								}
      //							}
      //						}
      //					}
      //				}
      //			}
      //std::cout<<"      Exiting out of deeper For"<<std::endl;
    }
    //		std::cout<<"   Getting Out Of For"<<std::endl;
  }
}

void GMSH_ThinLayerFixMeshPlugin::fillvecOfThinSheets()
{
  for (std::map<MVertex*,std::vector<CorrespVerticesFixMesh*> >::iterator it1 = VertexToCorresp.begin();it1 != VertexToCorresp.end();it1++){
    // MVertex* vertTmp = (*it1).first;
    std::vector<CorrespVerticesFixMesh*> vecCorr = (*it1).second;
    for (unsigned int i = 0;i < vecCorr.size();i++){
      CorrespVerticesFixMesh* currentCorr = vecCorr[i];
      //std::cout<<"going to test vecCorr["<<i<<"]"<<" vertex "<<currentCorr->getStartPoint()->getNum()<<" and pos "<<currentCorr->getStartPoint()->x()<<" ; "<<currentCorr->getStartPoint()->y()<<" ; "<<currentCorr->getStartPoint()->z()<<std::endl;
      if (currentCorr->getStartPoint()->onWhat()->dim() == 2)
        //std::cout<<"On a surface ; ";
        if (currentCorr->getActive())
          //std::cout<<"Is active ; ";
          if (currentCorr->getEndTriangleActive())
            //std::cout<<"End Triangle active ; ";
            if (currentCorr->getTagMaster() == (-2))
              //std::cout<<"Has yet to be used ; ";
              //std::cout<<std::endl;
              if ((currentCorr->getStartPoint()->onWhat()->dim() == 2) && (currentCorr->getActive()) && (currentCorr->getEndTriangleActive()) && (currentCorr->getTagMaster() == (-2))){
                //Found the first node of a new master sheet
                //std::cout<<"entering a new master sheet !"<<std::endl;
                std::vector<CorrespVerticesFixMesh*> MasterSheet;
                MasterSheet.clear();
                (*it1).second[i]->setTagMaster(-1);
                //				faceXtetFM faceEndSlave = (*((*it1).second[i]->getEndTriangle()));
                //				faceXtetFM faceEndSlave = ((*it1).second[i]->getEndTriangle());
                {
                  std::map<MVertex*,std::vector<CorrespVerticesFixMesh*> >::iterator it2 = VertexToCorresp.find((*it1).second[i]->getEndTrianglePoint1());
                  if (it2 != VertexToCorresp.end()){
                    if ((*it2).second.size() > 0){
                      if ((*it1).second[i]->getEndTrianglePoint1()->onWhat()->dim() == 2){
                        (*it2).second[0]->setTagMaster((*it1).second[i]->getStartPoint()->onWhat()->tag());
                      }
                    }
                  }
                  it2 = VertexToCorresp.find((*it1).second[i]->getEndTrianglePoint2());
                  if (it2 != VertexToCorresp.end()){
                    if ((*it2).second.size() > 0){
                      if ((*it1).second[i]->getEndTrianglePoint2()->onWhat()->dim() == 2){
                        (*it2).second[0]->setTagMaster((*it1).second[i]->getStartPoint()->onWhat()->tag());
                      }
                    }
                  }
                  it2 = VertexToCorresp.find((*it1).second[i]->getEndTrianglePoint3());
                  if (it2 != VertexToCorresp.end()){
                    if ((*it2).second.size() > 0){
                      if ((*it1).second[i]->getEndTrianglePoint3()->onWhat()->dim() == 2){
                        (*it2).second[0]->setTagMaster((*it1).second[i]->getStartPoint()->onWhat()->tag());
                      }
                    }
                  }
                }
                //				for (unsigned int j = 0;j < 3;j++){
                //					std::map<MVertex*,std::vector<CorrespVerticesFixMesh*> >::iterator it2 = VertexToCorresp.find(faceEndSlave.v[j]);
                //					if (it2 != VertexToCorresp.end()){
                //						if (faceEndSlave.v[j]->onWhat()->dim() == 2){
                //							(*it2).second[0]->setTagMaster((*it1).second[i]->getStartPoint()->onWhat()->tag());
                //						}
                //					}
                //				}
                MasterSheet.push_back((*it1).second[i]);
                std::set<MVertex*> CurrentSheet;
                CurrentSheet.clear();
                CurrentSheet.insert((*it1).second[i]->getStartPoint());
                while (CurrentSheet.size() != 0){
                  MVertex* VToDo = (*CurrentSheet.begin());
                  std::vector<MTetrahedron*> surroundingTet = VertexToTets[VToDo];
                  for (unsigned int j = 0;j < surroundingTet.size();j++){
                    for (int k = 0;k < surroundingTet[j]->getNumVertices();k++){
                      MVertex* ToInsertTmp = surroundingTet[j]->getVertex(k);
                      std::map<MVertex*,std::vector<CorrespVerticesFixMesh*> >::iterator it2 = VertexToCorresp.find(ToInsertTmp);
                      if (ToInsertTmp->onWhat()->tag() == VToDo->onWhat()->tag()){//TODO: OR that onwhat -> dim <, for edges
                        if (it2 != VertexToCorresp.end()){
                          if ((*it2).second.size() > 0){
                            CorrespVerticesFixMesh* correspToInsert = ((*it2).second)[0];
                            //std::cout<<"      Testing "<<((*it2).second)[0]->getStartPoint()->getNum()<<" with ";
                            if (correspToInsert->getStartPoint()->onWhat()->dim() == 2)
                              //std::cout<<"On a surface ; ";
                              if (correspToInsert->getActive())
                                //std::cout<<"Is active ; ";
                                if (correspToInsert->getEndTriangleActive())
                                  //std::cout<<"End Triangle active ; ";
                                  if (correspToInsert->getTagMaster() == (-2))
                                    //std::cout<<"Has yet to be used ; ";
                                    //std::cout<<std::endl;
                                    if ((correspToInsert->getStartPoint()->onWhat()->dim() == 2) && (correspToInsert->getActive()) && (correspToInsert->getEndTriangleActive()) && (correspToInsert->getTagMaster() == (-2))){
                                      MasterSheet.push_back((*it2).second[0]);
                                      (*it2).second[0]->setTagMaster(-1);
                                      //										faceXtetFM faceEndSlave2 = (*((*it2).second[0]->getEndTriangle()));
                                      //										faceXtetFM faceEndSlave2 = ((*it2).second[0]->getEndTriangle());
                                      {
                                        std::map<MVertex*,std::vector<CorrespVerticesFixMesh*> >::iterator it3 = VertexToCorresp.find((*it2).second[0]->getEndTrianglePoint1());
                                        if (it3 != VertexToCorresp.end()){
                                          if ((*it3).second.size() > 0){
                                            if ((*it2).second[0]->getEndTrianglePoint1()->onWhat()->dim() == 2){
                                              (*it3).second[0]->setTagMaster((*it2).second[i]->getStartPoint()->onWhat()->tag());
                                            }
                                          }
                                        }
                                        it3 = VertexToCorresp.find((*it2).second[0]->getEndTrianglePoint2());
                                        if (it3 != VertexToCorresp.end()){
                                          if ((*it3).second.size() > 0){
                                            if ((*it2).second[0]->getEndTrianglePoint2()->onWhat()->dim() == 2){
                                              (*it3).second[0]->setTagMaster((*it2).second[i]->getStartPoint()->onWhat()->tag());
                                            }
                                          }
                                        }
                                        it3 = VertexToCorresp.find((*it2).second[0]->getEndTrianglePoint3());
                                        if (it3 != VertexToCorresp.end()){
                                          if ((*it3).second.size() > 0){
                                            if ((*it2).second[0]->getEndTrianglePoint3()->onWhat()->dim() == 2){
                                              (*it3).second[0]->setTagMaster((*it2).second[i]->getStartPoint()->onWhat()->tag());
                                            }
                                          }
                                        }
                                      }
                                      //										for (unsigned int j = 0;j < 3;j++){
                                      //											std::map<MVertex*,std::vector<CorrespVerticesFixMesh*> >::iterator it3 = VertexToCorresp.find(faceEndSlave2.v[j]);
                                      //											if (it3 != VertexToCorresp.end()){
                                      //												if (faceEndSlave2.v[j]->onWhat()->dim() == 2){
                                      //													(*it3).second[0]->setTagMaster((*it2).second[i]->getStartPoint()->onWhat()->tag());
                                      //												}
                                      //											}
                                      //										}
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
                //std::cout<<"describing new MasterSheet !"<<std::endl;
                for (unsigned int j = 0;j < MasterSheet.size();j++){
                  //std::cout<<"Number "<<j<<" is "<<MasterSheet[j]->getStartPoint()->getNum()<<" with position "<<MasterSheet[j]->getStartPoint()->x()<<" ; "<<MasterSheet[j]->getStartPoint()->y()<<" ; "<<MasterSheet[j]->getStartPoint()->z()<<std::endl;
                }
                //std::cout<<"exiting the master sheet !"<<std::endl;
              }
    }
  }
}
std::map<MVertex*,double> GMSH_ThinLayerFixMeshPlugin::computeAllDistToOppSide(){
  std::map<MVertex*,double> AllDistToOppSide;
  AllDistToOppSide.clear();
  GModel *m = GModel::current();
  //	std::vector<MElement*> crackElements;
  std::set<MVertex*> BoundaryVertices;
  int countdown = 0;



  for (GModel::riter itr= m->firstRegion();itr != m->lastRegion();itr++){
    GRegion* rTmp = (*itr);
    //std::cout<<"   Entering region "<<rTmp->tag()<<std::endl;
    for(unsigned int i = 0; i < rTmp->tetrahedra.size(); i++){
      countdown++;
      //std::cout<<"      Entering tet "<<rTmp->tetrahedra[i]->getNum()<<" its the "<<countdown<<"st"<<std::endl;
      MTet4* tet4Tmp = TetToTet4[rTmp->tetrahedra[i]];
      //std::cout<<"      Neighbours 0: "<<tet4Tmp->getNeigh(0)<<" Neighbours 1: "<<tet4Tmp->getNeigh(1)<<" Neighbours 2: "<<tet4Tmp->getNeigh(2)<<" Neighbours 3: "<<tet4Tmp->getNeigh(3)<<std::endl;
      for (unsigned int j = 0;j < 4;j++){
        //std::cout<<"         Entering neighbour "<<j<<std::endl;
        if (tet4Tmp->getNeigh(j) == 0){
          //std::cout<<"         Test Passed "<<std::endl;
          //find the 4th point,and fill the two vector of the boundary triangle
          faceXtetFM fxtTmp(tet4Tmp,j);
          //std::cout<<"         fxtTmp created "<<std::endl;
          for (int k = 0;k < 3;k++){
            //std::cout<<"            Entering Point "<<k<<std::endl;
            MVertex* toTest = fxtTmp.v[k];
            if (toTest->onWhat()->dim() == 2){
              //std::cout<<"               Passed First test "<<std::endl;
              if(BoundaryVertices.find(toTest) == BoundaryVertices.end()){
                //std::cout<<"                  Passed Second test "<<std::endl;
                BoundaryVertices.insert(toTest);
              }
            }
            //std::cout<<"            Exiting Point "<<k<<std::endl;
          }
          //			crackElements.push_back(rTmp->getMeshElement(j));
        }
        //std::cout<<"         Exiting neighbour "<<j<<std::endl;
      }
      //std::cout<<"      Exiting tet "<<rTmp->tetrahedra[i]->getNum()<<std::endl;
    }
    //std::cout<<"   Exiting region "<<rTmp->tag()<<std::endl;
  }
  //std::cout<<"Entering computeDistToOppSide"<<std::endl;
  countdown = 0;
  for(std::set<MVertex*>::iterator it = BoundaryVertices.begin(); it != BoundaryVertices.end(); it++){
    countdown++;
    //std::cout<<"   entering Bound Vert "<<(*it)->getNum()<<" it's the "<<countdown<<"st"<<std::endl;
    MVertex* toCompute = (*it);
    double resultTmp = computeDistToOppSide(toCompute);
    // int lastTmp = VertexToCorresp[toCompute].size() - 1;
    //std::cout<<"            getEndNormal is "<<VertexToCorresp[toCompute][lastTmp]->getEndNormal().x()<<" ; "<<VertexToCorresp[toCompute][lastTmp]->getEndNormal().y()<<" ; "<<VertexToCorresp[toCompute][lastTmp]->getEndNormal().z()<<std::endl;
    //std::cout<<"            getEndNormal is "<<VertexToCorresp[toCompute][lastTmp]->getEndNormal().x()<<" ; "<<VertexToCorresp[toCompute][lastTmp]->getEndNormal().y()<<" ; "<<VertexToCorresp[toCompute][lastTmp]->getEndNormal().z()<<std::endl;
    //std::cout<<"            getEndNormal is "<<VertexToCorresp[toCompute][lastTmp]->getEndNormal().x()<<" ; "<<VertexToCorresp[toCompute][lastTmp]->getEndNormal().y()<<" ; "<<VertexToCorresp[toCompute][lastTmp]->getEndNormal().z()<<std::endl;
    //		std::cout<<"         Testing FaceXTet out of while third time "<<VertexToCorresp[toCompute][lastTmp]->getEndTriangle().t1->tet()->getNum()<<std::endl;
    //std::cout<<"            LastTmp is "<<lastTmp<<std::endl;
    //std::cout<<"            ToCompute is "<<toCompute->getNum()<<std::endl;
    //std::cout<<"               ToCompute adress is "<<toCompute<<std::endl;
    //std::cout<<"            VertexToCorresp[toCompute][lastTmp] is "<<VertexToCorresp[toCompute][lastTmp]<<std::endl;
    //		std::cout<<"            getEndTriangle is "<<VertexToCorresp[toCompute][lastTmp]->getEndTriangle()<<std::endl;
    //		std::cout<<"            t1 is "<<VertexToCorresp[toCompute][lastTmp]->getEndTriangle().t1<<std::endl;
    //		std::cout<<"            tet is "<<VertexToCorresp[toCompute][lastTmp]->getEndTriangle().t1->tet()<<std::endl;
    //		std::cout<<"         Testing FaceXTet out of while popo "<<VertexToCorresp[toCompute][lastTmp]->getEndTriangle().t1->tet()->getNum()<<std::endl;
    //std::cout<<"     size of AllDistToOppSide is "<<AllDistToOppSide.size()<<std::endl;
    //std::cout<<"            LastTmp is "<<lastTmp<<std::endl;
    //std::cout<<"            ToCompute is "<<toCompute->getNum()<<std::endl;
    //std::cout<<"               ToCompute adress is "<<toCompute<<std::endl;
    //std::cout<<"            VertexToCorresp[toCompute][lastTmp] is "<<VertexToCorresp[toCompute][lastTmp]<<std::endl;
    //		std::cout<<"            getEndTriangle is "<<VertexToCorresp[toCompute][lastTmp]->getEndTriangle()<<std::endl;
    //std::cout<<"            getEndNormal is "<<VertexToCorresp[toCompute][lastTmp]->getEndNormal()<<std::endl;
    //std::cout<<"            getEndNormal is "<<VertexToCorresp[toCompute][lastTmp]->getEndNormal().x()<<" ; "<<VertexToCorresp[toCompute][lastTmp]->getEndNormal().y()<<" ; "<<VertexToCorresp[toCompute][lastTmp]->getEndNormal().z()<<std::endl;
    //std::cout<<"            getEndNormal is "<<VertexToCorresp[toCompute][lastTmp]->getEndNormal().x()<<" ; "<<VertexToCorresp[toCompute][lastTmp]->getEndNormal().y()<<" ; "<<VertexToCorresp[toCompute][lastTmp]->getEndNormal().z()<<std::endl;
    //		std::cout<<"            t1 is "<<VertexToCorresp[toCompute][lastTmp]->getEndTriangle().t1<<std::endl;
    //		std::cout<<"            tet is "<<VertexToCorresp[toCompute][lastTmp]->getEndTriangle().t1->tet()<<std::endl;
    //std::cout<<"            VertexToCorresp[toCompute][lastTmp] is "<<VertexToCorresp[toCompute][lastTmp]<<std::endl;
    //		std::cout<<"            getEndTriangle is "<<VertexToCorresp[toCompute][lastTmp]->getEndTriangle()<<std::endl;
    //std::cout<<"            getEndNormal is "<<VertexToCorresp[toCompute][lastTmp]->getEndNormal()<<std::endl;
    //std::cout<<"            getEndNormal is "<<VertexToCorresp[toCompute][lastTmp]->getEndNormal().x()<<" ; "<<VertexToCorresp[toCompute][lastTmp]->getEndNormal().y()<<" ; "<<VertexToCorresp[toCompute][lastTmp]->getEndNormal().z()<<std::endl;
    //		std::cout<<"     VertexToCorresp[toCompute][lastTmp]->getEndTriangle().t1 adress is "<<&(VertexToCorresp[toCompute][lastTmp]->getEndTriangle().t1)<<std::endl;
    //std::cout<<"            VertexToCorresp[toCompute][lastTmp] is "<<VertexToCorresp[toCompute][lastTmp]<<std::endl;
    //		std::cout<<"            getEndTriangle is "<<VertexToCorresp[toCompute][lastTmp]->getEndTriangle()<<std::endl;
    //std::cout<<"            getEndNormal is "<<VertexToCorresp[toCompute][lastTmp]->getEndNormal()<<std::endl;
    //std::cout<<"            getEndNormal is "<<VertexToCorresp[toCompute][lastTmp]->getEndNormal().x()<<" ; "<<VertexToCorresp[toCompute][lastTmp]->getEndNormal().y()<<" ; "<<VertexToCorresp[toCompute][lastTmp]->getEndNormal().z()<<std::endl;
    //		std::cout<<"     VertexToCorresp[toCompute][lastTmp]->getEndTriangle().t1 adress is "<<&(VertexToCorresp[toCompute][lastTmp]->getEndTriangle().t1)<<std::endl;
    //std::cout<<"               ToCompute adress is "<<toCompute<<std::endl;
    //		std::cout<<"         Testing FaceXTet out of while popo 2 "<<VertexToCorresp[toCompute][lastTmp]->getEndTriangle().t1->tet()->getNum()<<std::endl;
    AllDistToOppSide.insert(std::make_pair(toCompute, resultTmp));
    //std::cout<<"     AllDistToOppSide[toCompute] is "<<AllDistToOppSide[toCompute]<<std::endl;
    //std::cout<<"               ToCompute adress is "<<toCompute<<std::endl;
    //std::cout<<"            VertexToCorresp[toCompute][lastTmp] is "<<VertexToCorresp[toCompute][lastTmp]<<std::endl;
    //		std::cout<<"            getEndTriangle is "<<VertexToCorresp[toCompute][lastTmp]->getEndTriangle()<<std::endl;
    //std::cout<<"            getEndNormal is "<<VertexToCorresp[toCompute][lastTmp]->getEndNormal()<<std::endl;
    //std::cout<<"            getEndNormal is "<<VertexToCorresp[toCompute][lastTmp]->getEndNormal().x()<<" ; "<<VertexToCorresp[toCompute][lastTmp]->getEndNormal().y()<<" ; "<<VertexToCorresp[toCompute][lastTmp]->getEndNormal().z()<<std::endl;
    //		std::cout<<"     VertexToCorresp[toCompute][lastTmp]->getEndTriangle().t1 adress is "<<&(VertexToCorresp[toCompute][lastTmp]->getEndTriangle().t1)<<std::endl;
    //std::cout<<"               ToCompute adress is "<<toCompute<<std::endl;
    //std::cout<<"            VertexToCorresp[toCompute][lastTmp] is "<<VertexToCorresp[toCompute][lastTmp]<<std::endl;
    //		std::cout<<"            getEndTriangle is "<<VertexToCorresp[toCompute][lastTmp]->getEndTriangle()<<std::endl;
    //		std::cout<<"     VertexToCorresp[toCompute][lastTmp]->getEndTriangle().t1 adress is "<<&(VertexToCorresp[toCompute][lastTmp]->getEndTriangle().t1)<<std::endl;
    //std::cout<<"     AllDistToOppSide[toCompute] adress is "<<&AllDistToOppSide[toCompute]<<std::endl;
    //std::cout<<"            VertexToCorresp[toCompute][lastTmp] is "<<VertexToCorresp[toCompute][lastTmp]<<std::endl;
    //		std::cout<<"            getEndTriangle is "<<VertexToCorresp[toCompute][lastTmp]->getEndTriangle()<<std::endl;
    //		std::cout<<"     VertexToCorresp[toCompute][lastTmp]->getEndTriangle().t1 adress is "<<&(VertexToCorresp[toCompute][lastTmp]->getEndTriangle().t1)<<std::endl;
    //std::cout<<"            VertexToCorresp[toCompute][lastTmp] is "<<VertexToCorresp[toCompute][lastTmp]<<std::endl;
    //		std::cout<<"            getEndTriangle is "<<VertexToCorresp[toCompute][lastTmp]->getEndTriangle()<<std::endl;
    //		std::cout<<"     VertexToCorresp[toCompute][lastTmp]->getEndTriangle().t1 adress is "<<&(VertexToCorresp[toCompute][lastTmp]->getEndTriangle().t1)<<std::endl;
    //std::cout<<"            VertexToCorresp[toCompute][lastTmp] is "<<VertexToCorresp[toCompute][lastTmp]<<std::endl;
    //		std::cout<<"            getEndTriangle is "<<VertexToCorresp[toCompute][lastTmp]->getEndTriangle()<<std::endl;
    //		std::cout<<"     VertexToCorresp[toCompute][lastTmp]->getEndTriangle().t1 adress is "<<&(VertexToCorresp[toCompute][lastTmp]->getEndTriangle().t1)<<std::endl;
    //std::cout<<"            LastTmp is "<<lastTmp<<std::endl;
    //std::cout<<"            ToCompute is "<<toCompute->getNum()<<std::endl;
    //std::cout<<"               ToCompute adress is "<<toCompute<<std::endl;
    //std::cout<<"            VertexToCorresp[toCompute][lastTmp] is "<<VertexToCorresp[toCompute][lastTmp]<<std::endl;
    //		std::cout<<"            getEndTriangle is "<<VertexToCorresp[toCompute][lastTmp]->getEndTriangle()<<std::endl;
    //		std::cout<<"            t1 is "<<VertexToCorresp[toCompute][lastTmp]->getEndTriangle().t1<<std::endl;
    //		std::cout<<"            tet is "<<VertexToCorresp[toCompute][lastTmp]->getEndTriangle().t1->tet()<<std::endl;
    //		std::cout<<"         Testing FaceXTet out of while popo 3 "<<VertexToCorresp[toCompute][lastTmp]->getEndTriangle().t1->tet()->getNum()<<std::endl;
    //		AllDistToOppSide[toCompute] = 0.0;
    //		std::cout<<"            LastTmp is "<<lastTmp<<std::endl;
    //		std::cout<<"            ToCompute is "<<toCompute->getNum()<<std::endl;
    //		std::cout<<"            getEndTriangle is "<<VertexToCorresp[toCompute][lastTmp]->getEndTriangle()<<std::endl;
    //		std::cout<<"            t1 is "<<VertexToCorresp[toCompute][lastTmp]->getEndTriangle().t1<<std::endl;
    //		std::cout<<"            tet is "<<VertexToCorresp[toCompute][lastTmp]->getEndTriangle().t1->tet()<<std::endl;
    //		std::cout<<"     size of AllDistToOppSide is "<<AllDistToOppSide.size()<<std::endl;
    //		std::cout<<"            LastTmp is "<<lastTmp<<std::endl;
    //		std::cout<<"            ToCompute is "<<toCompute->getNum()<<std::endl;
    //		std::cout<<"            getEndTriangle is "<<VertexToCorresp[toCompute][lastTmp]->getEndTriangle()<<std::endl;
    //		std::cout<<"            t1 is "<<VertexToCorresp[toCompute][lastTmp]->getEndTriangle().t1<<std::endl;
    //		std::cout<<"            tet is "<<VertexToCorresp[toCompute][lastTmp]->getEndTriangle().t1->tet()<<std::endl;
    AllDistToOppSide[toCompute] = resultTmp;
    //std::cout<<" observation "<<countdown<<std::endl;
    //std::cout<<"            LastTmp is "<<lastTmp<<std::endl;
    //std::cout<<"            ToCompute is "<<toCompute->getNum()<<std::endl;
    //std::cout<<"            VertexToCorresp[toCompute][lastTmp] is "<<VertexToCorresp[toCompute][lastTmp]<<std::endl;
    //		std::cout<<"            getEndTriangle is "<<VertexToCorresp[toCompute][lastTmp]->getEndTriangle()<<std::endl;
    //		std::cout<<"            t1 is "<<VertexToCorresp[toCompute][lastTmp]->getEndTriangle().t1<<std::endl;
    //		std::cout<<"            tet is "<<VertexToCorresp[toCompute][lastTmp]->getEndTriangle().t1->tet()<<std::endl;
    //		std::cout<<"         Testing FaceXTet out of while bis repetita "<<VertexToCorresp[toCompute][lastTmp]->getEndTriangle().t1->tet()->getNum()<<std::endl;
    for (std::map<MVertex*,double>::iterator allDistIt = AllDistToOppSide.begin();allDistIt != AllDistToOppSide.end();allDistIt++){
      //std::cout<<"allDist of point "<<(*allDistIt).first->getNum()<<" with Pos "<<(*allDistIt).first->x()<<" ; "<<(*allDistIt).first->z()<<" ; "<<(*allDistIt).first->y()<<" is "<<(*allDistIt).second<<std::endl;
      //std::cout<<"   Size of vertexToCorresp "<<VertexToCorresp[(*allDistIt).first].size()<<std::endl;
      // MVertex* toComputeTest = (*allDistIt).first;
      //std::cout<<"   ToComputeTest is "<<toComputeTest->getNum()<<std::endl;
      // int lastTmpTest = VertexToCorresp[toComputeTest].size() - 1;
      //			std::cout<<"         Testing FaceXTet out of while ter repetita "<<VertexToCorresp[toComputeTest][lastTmpTest]->getEndTriangle().t1->tet()->getNum()<<std::endl;
      //			std::cout<<"      Testing FaceXTet out of while fourth time "<<VertexToCorresp[(*allDistIt).first][VertexToCorresp[(*allDistIt).first].size() - 1]->getEndTriangle().t1->tet()->getNum()<<std::endl;
    }
  }

  //std::cout<<"first observation"<<std::endl;
  for (std::map<MVertex*,double>::iterator allDistIt = AllDistToOppSide.begin();allDistIt != AllDistToOppSide.end();allDistIt++){
    //std::cout<<"allDist of point "<<(*allDistIt).first->getNum()<<" with Pos "<<(*allDistIt).first->x()<<" ; "<<(*allDistIt).first->z()<<" ; "<<(*allDistIt).first->y()<<" is "<<(*allDistIt).second<<std::endl;
    //std::cout<<"   Size of vertexToCorresp "<<VertexToCorresp[(*allDistIt).first].size()<<std::endl;
    //		std::cout<<"      Testing FaceXTet out of while fourth time "<<VertexToCorresp[(*allDistIt).first][VertexToCorresp[(*allDistIt).first].size() - 1]->getEndTriangle().t1->tet()->getNum()<<std::endl;
  }

  return AllDistToOppSide;
}

double GMSH_ThinLayerFixMeshPlugin::computeDistToOppSide(MVertex* v){
  double DistToOppSide = 0.0;
  //We assume v is on the boundary
  //First we need to get the internal normal
  //std::cout<<"      Entering ComputeDistToOppSide Function"<<std::endl;
  SVector3 InteriorNormal = GMSH_ThinLayerFixMeshPlugin::computeInteriorNormal(v);
  //std::cout<<"      Normal computed"<<std::endl;
  //Then we find the first triangle
  MTet4* FirstTet = GMSH_ThinLayerFixMeshPlugin::getTetFromPoint(v,InteriorNormal);
  //std::cout<<"   FirstTet is tet "<<FirstTet->tet()->getNum()<<std::endl;
  //std::cout<<"      got FirstTet"<<std::endl;
  MTet4* CurrentTet = FirstTet;
  //std::cout<<"      set currentTet"<<std::endl;
  MTet4* PastTet = FirstTet;
  //std::cout<<"      set PastTet"<<std::endl;
  SPoint3 CurrentPos = SPoint3(v->x(),v->y(),v->z());
  //std::cout<<"      set CurrentPos"<<std::endl;
  SPoint3 LastPos = CurrentPos;
  //std::cout<<"      set LasPos"<<std::endl;
  int CurrentTriValue = 0;
  int* CurrentTri = &CurrentTriValue;
  //std::cout<<"      set CurrentTri"<<std::endl;
  CorrespVerticesFixMesh* CVTemp = new CorrespVerticesFixMesh();
  //std::cout<<"      Created CVTemp"<<std::endl;
  CorrespVerticesFixMesh CVTemp2;
  //std::cout<<"      Created CVTemp2"<<std::endl;
  CVTemp->setStartPoint(v);
  CVTemp2.setStartPoint(v);
  //std::cout<<"      setStartPoint"<<std::endl;
  CVTemp->setStartNormal(InteriorNormal);
  CVTemp2.setStartNormal(InteriorNormal);
  //std::cout<<"      setStartNormal"<<std::endl;
  FindNewPoint((&CurrentPos),CurrentTri,&CurrentTet,InteriorNormal);
  DistToOppSide += CurrentPos.distance(LastPos);
  LastPos = CurrentPos;
  //std::cout<<"      Found New Point"<<std::endl;
  //	faceXtetFM fxtCV(PastTet,(*CurrentTri));
  //	CVTemp->setEndTriangle(&fxtCV);
  //	while(CurrentTet->getNeigh((*CurrentTri)) != 0){
  int countWhile = 0;
  int prevprevtet = 1;
  int prevtet = 2;
  while((CurrentTet != 0) && (countWhile < 50)){
    //std::cout<<"                                    Entering While"<<std::endl;
    //std::cout<<"CurrentTet is "<<CurrentTet->tet()->getNum()<< "adress "<<CurrentTet<< " and currentTri "<<(*CurrentTri)<<std::endl;
    //std::cout<<"currentPos is "<<CurrentPos.x()<<" ; "<<CurrentPos.y()<<" ; "<<CurrentPos.z()<<std::endl;
    countWhile++;
    faceXtetFM fxtCVtmp(PastTet,(*CurrentTri));
    PastTet = CurrentTet;
    CVTemp->setEndTrianglePoint1(PastTet->tet()->getVertex(faces[(*CurrentTri)][0]));
    CVTemp->setEndTrianglePoint2(PastTet->tet()->getVertex(faces[(*CurrentTri)][1]));
    CVTemp->setEndTrianglePoint3(PastTet->tet()->getVertex(faces[(*CurrentTri)][2]));
    CVTemp2.setEndTrianglePoint1(PastTet->tet()->getVertex(faces[(*CurrentTri)][0]));
    CVTemp2.setEndTrianglePoint2(PastTet->tet()->getVertex(faces[(*CurrentTri)][1]));
    CVTemp2.setEndTrianglePoint3(PastTet->tet()->getVertex(faces[(*CurrentTri)][2]));
    //		CVTemp->setEndTriangle(fxtCVtmp);
    //		CVTemp2.setEndTriangle(fxtCVtmp);
    //std::cout<<"         FaceXTetCreated"<<std::endl;
    //std::cout<<"         Testing FaceXTet in while "<<fxtCVtmp.t1->tet()->getNum()<<std::endl;
    //std::cout<<"            CurrentTet before FindNewPoint "<<CurrentTet<<std::endl;
    FindNewPoint((&CurrentPos),CurrentTri,&CurrentTet,InteriorNormal);
    //std::cout<<"            CurrentTet after FindNewPoint "<<CurrentTet<<std::endl;
    //std::cout<<"         FoundNewPoint While"<<std::endl;
    //		CurrentTet = CurrentTet->getNeigh((*CurrentTri));
    //		//std::cout<<"         GotNeigh While"<<std::endl;
    DistToOppSide += CurrentPos.distance(LastPos);
    LastPos = CurrentPos;

    if (CurrentTet != 0){
      if ((CurrentTet->tet()->getNum()) == prevprevtet){
        //std::cout<<"reached standstill"<<std::endl;
        while (1){

        }
      }
      prevprevtet = prevtet;
      prevtet=CurrentTet->tet()->getNum();
    }
    //std::cout<<"                                    Exiting While"<<std::endl;
  }
  //std::cout<<"      Out Of While"<<std::endl;
  CVTemp->setEndPoint(LastPos);
  CVTemp2.setEndPoint(LastPos);
  faceXtetFM fxtCV(PastTet,(*CurrentTri));
  //std::cout<<"         Testing FaceXTet out of while "<<fxtCV.t1->tet()->getNum()<<std::endl;
  CVTemp->setEndTrianglePoint1(PastTet->tet()->getVertex(faces[(*CurrentTri)][0]));
  CVTemp->setEndTrianglePoint2(PastTet->tet()->getVertex(faces[(*CurrentTri)][1]));
  CVTemp->setEndTrianglePoint3(PastTet->tet()->getVertex(faces[(*CurrentTri)][2]));
  CVTemp2.setEndTrianglePoint1(PastTet->tet()->getVertex(faces[(*CurrentTri)][0]));
  CVTemp2.setEndTrianglePoint2(PastTet->tet()->getVertex(faces[(*CurrentTri)][1]));
  CVTemp2.setEndTrianglePoint3(PastTet->tet()->getVertex(faces[(*CurrentTri)][2]));
  //	CVTemp->setEndTriangle(fxtCV);
  //	CVTemp2.setEndTriangle(fxtCV);
  //	//std::cout<<"         Testing FaceXTet out of while second time "<<CVTemp->getEndTriangle().t1->tet()->getNum()<<std::endl;
  //	//std::cout<<"         Testing FaceXTet out of while second time CVTemp2 "<<CVTemp2.getEndTriangle().t1->tet()->getNum()<<std::endl;
  //	CVTemp->setEndTriangle(&fxtCV);
  //	SVector3 EndDir1(fxtCV.v[1]->x() - fxtCV.v[0]->x(),fxtCV.v[1]->y() - fxtCV.v[0]->y(),fxtCV.v[1]->z() - fxtCV.v[0]->z());
  //	SVector3 EndDir2(fxtCV.v[2]->x() - fxtCV.v[0]->x(),fxtCV.v[2]->y() - fxtCV.v[0]->y(),fxtCV.v[2]->z() - fxtCV.v[0]->z());
  //	SVector3 EndNormal(EndDir1.y() * EndDir2.z() - EndDir1.z() * EndDir2.y(),EndDir1.z() * EndDir2.x() - EndDir1.x() * EndDir2.z(),EndDir1.x() * EndDir2.y() - EndDir1.y() * EndDir2.x());
  SVector3 EndNormal(-InteriorNormal.x(),-InteriorNormal.y(),-InteriorNormal.z());
  EndNormal.normalize();
  CVTemp->setEndNormal(EndNormal);
  CVTemp2.setEndNormal(EndNormal);
  CVTemp->setangleProd(fabs(CVTemp->getStartNormal().x() * CVTemp->getEndNormal().x() + CVTemp->getStartNormal().y() * CVTemp->getEndNormal().y() + CVTemp->getStartNormal().z() * CVTemp->getEndNormal().z()));
  CVTemp2.setangleProd(fabs(CVTemp2.getStartNormal().x() * CVTemp2.getEndNormal().x() + CVTemp2.getStartNormal().y() * CVTemp2.getEndNormal().y() + CVTemp2.getStartNormal().z() * CVTemp2.getEndNormal().z()));
  CVTemp->setdistP2P(DistToOppSide);
  CVTemp2.setdistP2P(DistToOppSide);
  if ((CVTemp->getangleProd() > angleMax) &&(CVTemp->getdistP2P() < distP2PMax)){
    CVTemp->setActive(true);
  }
  else{
    CVTemp->setActive(false);
  }
  if ((CVTemp2.getangleProd() > angleMax) &&(CVTemp2.getdistP2P() < distP2PMax)){
    CVTemp2.setActive(true);
  }
  else{
    CVTemp2.setActive(false);
  }
  CVTemp->setTagMaster(-2);
  CVTemp2.setTagMaster(-2);
  //std::cout<<"            getEndNormal is "<<CVTemp2.getEndNormal().x()<<" ; "<<CVTemp2.getEndNormal().y()<<" ; "<<CVTemp2.getEndNormal().z()<<std::endl;
  //std::cout<<"            getEndNormal is "<<CVTemp2.getEndNormal().x()<<" ; "<<CVTemp2.getEndNormal().y()<<" ; "<<CVTemp2.getEndNormal().z()<<std::endl;

  VertexToCorresp[v].push_back(CVTemp);
  //	VertexToCorresp[v].push_back(&CVTemp2);
  //std::cout<<"              getEndNormal test is "<<VertexToCorresp[v][VertexToCorresp[v].size() - 1]->getEndNormal().x()<<" ; "<<VertexToCorresp[v][VertexToCorresp[v].size() - 1]->getEndNormal().y()<<" ; "<<VertexToCorresp[v][VertexToCorresp[v].size() - 1]->getEndNormal().z()<<std::endl;
  //std::cout<<"              getEndNormal is "<<VertexToCorresp[v][VertexToCorresp[v].size() - 1]->getEndNormal().x()<<" ; "<<VertexToCorresp[v][VertexToCorresp[v].size() - 1]->getEndNormal().y()<<" ; "<<VertexToCorresp[v][VertexToCorresp[v].size() - 1]->getEndNormal().z()<<std::endl;
  //std::cout<<"              getEndNormal is "<<VertexToCorresp[v][VertexToCorresp[v].size() - 1]->getEndNormal().x()<<" ; "<<VertexToCorresp[v][VertexToCorresp[v].size() - 1]->getEndNormal().y()<<" ; "<<VertexToCorresp[v][VertexToCorresp[v].size() - 1]->getEndNormal().z()<<std::endl;
  //std::cout<<"              getEndNormal is "<<VertexToCorresp[v][VertexToCorresp[v].size() - 1]->getEndNormal().x()<<" ; "<<VertexToCorresp[v][VertexToCorresp[v].size() - 1]->getEndNormal().y()<<" ; "<<VertexToCorresp[v][VertexToCorresp[v].size() - 1]->getEndNormal().z()<<std::endl;

  return DistToOppSide;
}

SVector3 GMSH_ThinLayerFixMeshPlugin::computeInteriorNormal(MVertex* v){
  SPoint3 InteriorNormal(0.0,0.0,0.0);
  //std::cout<<"         Entering computeInteriorNormal"<<std::endl;
  std::vector<MTetrahedron*> currentVecTet = VertexToTets[v];
  std::vector<SPoint3> vecInteriorNodes;
  std::vector<SPoint3> vecFirstDir;
  std::vector<SPoint3> vecSecondDir;
  for (unsigned int i = 0;i < currentVecTet.size();i++){
    //std::cout<<"            Entering for "<<i<<std::endl;
    MTet4* tet4Tmp = TetToTet4[currentVecTet[i]];
    for (int j = 0;j < 4 ; j++){
      //std::cout<<"            Entering for "<<j<<std::endl;
      if (tet4Tmp->getNeigh(j) == 0){
        //std::cout<<"               Test Passed neigh zero "<<std::endl;
        //find the 4th point,and fill the two vector of the boundary triangle
        faceXtetFM fxtTmp(tet4Tmp,j);
        //std::cout<<"               Face Created "<<j<<std::endl;
        for (int k = 0;k < 4;k++){
          //std::cout<<"                  Entering for "<<k<<std::endl;
          bool foundInteriorPoint = true;
          for (int l = 0;l < 3;l++){
            if (tet4Tmp->tet()->getVertex(k) == fxtTmp.v[l]){
              foundInteriorPoint = false;
            }
          }
          if (foundInteriorPoint){
            SPoint3 pointTmp(tet4Tmp->tet()->getVertex(k)->x(),tet4Tmp->tet()->getVertex(k)->y(),tet4Tmp->tet()->getVertex(k)->z());
            vecInteriorNodes.push_back(pointTmp);
          }
        }
        SPoint3 pointTmp1(fxtTmp.v[1]->x() - fxtTmp.v[0]->x(),fxtTmp.v[1]->y() - fxtTmp.v[0]->y(),fxtTmp.v[1]->z() - fxtTmp.v[0]->z());
        SPoint3 pointTmp2(fxtTmp.v[2]->x() - fxtTmp.v[0]->x(),fxtTmp.v[2]->y() - fxtTmp.v[0]->y(),fxtTmp.v[2]->z() - fxtTmp.v[0]->z());
        vecFirstDir.push_back(pointTmp1);
        vecSecondDir.push_back(pointTmp2);
      }
    }
  }
  //std::cout<<"         Out of loop for "<<std::endl;
  //at this point we have all the info necessary.
  SPoint3 pointInteriorAverage(0.0,0.0,0.0);
  for (unsigned int i = 0;i < vecInteriorNodes.size();i++){
    pointInteriorAverage += SPoint3(vecInteriorNodes[i].x(),vecInteriorNodes[i].y(),vecInteriorNodes[i].z());
    //		pointInteriorAverage.x() += vecInteriorNodes[i].x();
    //		pointInteriorAverage.y() += vecInteriorNodes[i].y();
    //		pointInteriorAverage.z() += vecInteriorNodes[i].z();
  }
  pointInteriorAverage = SPoint3(pointInteriorAverage.x() / (double(vecInteriorNodes.size())),pointInteriorAverage.y() / (double(vecInteriorNodes.size())),pointInteriorAverage.z() / (double(vecInteriorNodes.size())));
  //	pointInteriorAverage.x() = pointInteriorAverage.x() / (double(vecInteriorNodes.size()));
  //	pointInteriorAverage.y() = pointInteriorAverage.y() / (double(vecInteriorNodes.size()));
  //	pointInteriorAverage.z() = pointInteriorAverage.z() / (double(vecInteriorNodes.size()));
  SPoint3 dirInteriorAverage(pointInteriorAverage.x() - v->x(),pointInteriorAverage.y() - v->y(),pointInteriorAverage.z() - v->z());
  double norme = sqrt(dirInteriorAverage.x() * dirInteriorAverage.x() + dirInteriorAverage.y() * dirInteriorAverage.y() + dirInteriorAverage.z() * dirInteriorAverage.z());
  dirInteriorAverage = SPoint3(dirInteriorAverage.x() / norme,dirInteriorAverage.y() / norme,dirInteriorAverage.z() / norme);
  //	dirInteriorAverage.x() = dirInteriorAverage.x() / norme;
  //	dirInteriorAverage.y() = dirInteriorAverage.y() / norme;
  //	dirInteriorAverage.z() = dirInteriorAverage.z() / norme;
  std::vector<SPoint3> vecOrthogDir;
  for(unsigned int i = 0;i < vecFirstDir.size();i++){
    SPoint3 pointTmp(vecFirstDir[i].y() * vecSecondDir[i].z() - vecFirstDir[i].z() * vecSecondDir[i].y(),vecFirstDir[i].z() * vecSecondDir[i].x() - vecFirstDir[i].x() * vecSecondDir[i].z(),vecFirstDir[i].x() * vecSecondDir[i].y() - vecFirstDir[i].y() * vecSecondDir[i].x());
    vecOrthogDir.push_back(pointTmp);
  }
  for(unsigned int i = 0;i < vecOrthogDir.size();i++){
    double prodScalTmp = vecOrthogDir[i].x() * dirInteriorAverage.x() + vecOrthogDir[i].y() * dirInteriorAverage.y() + vecOrthogDir[i].z() * dirInteriorAverage.z();
    if (prodScalTmp < 0.0){
      vecOrthogDir[i] = SPoint3(- vecOrthogDir[i].x(),- vecOrthogDir[i].y(),- vecOrthogDir[i].z());
      //			vecOrthogDir[i].x() = - vecOrthogDir[i].x();
      //			vecOrthogDir[i].y() = - vecOrthogDir[i].y();
      //			vecOrthogDir[i].z() = - vecOrthogDir[i].z();
    }
    double normeTmp = sqrt(vecOrthogDir[i].x() * vecOrthogDir[i].x() + vecOrthogDir[i].y() * vecOrthogDir[i].y() + vecOrthogDir[i].z() * vecOrthogDir[i].z());
    vecOrthogDir[i] = SPoint3(vecOrthogDir[i].x() / normeTmp,vecOrthogDir[i].y() / normeTmp,vecOrthogDir[i].z() / normeTmp);
    //		vecOrthogDir[i].x() = vecOrthogDir[i].x() / normeTmp;
    //		vecOrthogDir[i].y() = vecOrthogDir[i].y() / normeTmp;
    //		vecOrthogDir[i].z() = vecOrthogDir[i].z() / normeTmp;
    InteriorNormal += SPoint3(vecOrthogDir[i].x(),vecOrthogDir[i].y(),vecOrthogDir[i].z());
    //		InteriorNormal.x() += vecOrthogDir[i].x();
    //		InteriorNormal.y() += vecOrthogDir[i].y();
    //		InteriorNormal.z() += vecOrthogDir[i].z();
  }
  norme = sqrt(InteriorNormal.x() * InteriorNormal.x() + InteriorNormal.y() * InteriorNormal.y() + InteriorNormal.z() * InteriorNormal.z());
  InteriorNormal = SPoint3(InteriorNormal.x() / norme,InteriorNormal.y() / norme,InteriorNormal.z() / norme);
  //	InteriorNormal.x() = InteriorNormal.x() / norme;
  //	InteriorNormal.y() = InteriorNormal.y() / norme;
  //	InteriorNormal.z() = InteriorNormal.z() / norme;
  return InteriorNormal;
}

MTet4* GMSH_ThinLayerFixMeshPlugin::getTetFromPoint(MVertex* v, SVector3 InteriorNormal){
  MTet4* TetToGet = 0;
  std::vector<MTetrahedron*> currentVecTet = VertexToTets[v];
  //std::cout<<"   entering getTetFromPoint, vertex "<<v->x()<<" ; "<<v->y()<<" ; "<<v->z()<<" and dir "<<InteriorNormal.x()<<" ; "<<InteriorNormal.y()<<" ; "<<InteriorNormal.z()<<std::endl;
  for (unsigned int i = 0;i < currentVecTet.size();i++){
    std::vector<SVector3> vecDir;
    for (int j = 0;j < 4 ; j++){
      if (currentVecTet[i]->getVertex(j) != v){
        SVector3 DirTmp(currentVecTet[i]->getVertex(j)->x() - v->x(),currentVecTet[i]->getVertex(j)->y() - v->y(),currentVecTet[i]->getVertex(j)->z() - v->z());
        vecDir.push_back(DirTmp);
      }
    }
    bool IsPositiv = GMSH_ThinLayerFixMeshPlugin::IsPositivOrientation(vecDir[0],vecDir[1],vecDir[2]);
    if (!IsPositiv){
      SVector3 DirTmp1 = vecDir[1];
      SVector3 DirTmp2 = vecDir[0];
      SVector3 DirTmp3 = vecDir[2];
      vecDir.clear();
      vecDir.push_back(DirTmp1);
      vecDir.push_back(DirTmp2);
      vecDir.push_back(DirTmp3);
    }
    bool isPositiv1 = GMSH_ThinLayerFixMeshPlugin::IsPositivOrientation(vecDir[0],vecDir[1],InteriorNormal);
    bool isPositiv2 = GMSH_ThinLayerFixMeshPlugin::IsPositivOrientation(vecDir[1],vecDir[2],InteriorNormal);
    bool isPositiv3 = GMSH_ThinLayerFixMeshPlugin::IsPositivOrientation(vecDir[2],vecDir[0],InteriorNormal);
    if (isPositiv1){
      if (isPositiv2){
        if (isPositiv3){
          TetToGet = TetToTet4[currentVecTet[i]];
          //std::cout<<"      Found one fitting ! "<<TetToGet->tet()->getNum()<<std::endl;
        }
      }
    }
  }
  //std::cout<<"   exiting getTetFromPoint with result "<<TetToGet<<std::endl;
  //std::cout<<"   getTetFromPoint is tet "<<TetToGet->tet()->getNum()<<std::endl;
  return TetToGet;
}

bool GMSH_ThinLayerFixMeshPlugin::IsPositivOrientation(SVector3 a, SVector3 b, SVector3 c){
  bool result = false;
  SPoint3 ProdVec(a.y() * b.z() - a.z() * b.y(),a.z() * b.x() - a.x() * b.z(),a.x() * b.y() - a.y() * b.x());
  double ProdScal = ProdVec.x() * c.x() + ProdVec.y() * c.y() + ProdVec.z() * c.z();
  if (ProdScal >= 0.0){
    result = true;
  }
  return result;
}


void GMSH_ThinLayerFixMeshPlugin::FindNewPoint(SPoint3* CurrentPoint, int* CurrentTri, MTet4** CurrentTet, SVector3 InteriorNormal){
  double distanceP2P = 0.0;
  double alphaMax = 0.0;
  double betaMax = 0.0;
  SPoint3 ResultPoint;
  int triToGet = -1;
  //std::cout<<"   Entered FindNewPoint"<<std::endl;
  for (unsigned int n = 0;n < 4 ; n++){
    //calculer matrice a inverser
    faceXtetFM fxt((*CurrentTet),n);
    double a = fxt.v[1]->x() - fxt.v[0]->x();
    double b = fxt.v[2]->x() - fxt.v[0]->x();
    double c = InteriorNormal.x();
    double d = fxt.v[1]->y() - fxt.v[0]->y();
    double e = fxt.v[2]->y() - fxt.v[0]->y();
    double f = InteriorNormal.y();
    double g = fxt.v[1]->z() - fxt.v[0]->z();
    double h = fxt.v[2]->z() - fxt.v[0]->z();
    double i = InteriorNormal.z();
    //produit matrice inverse par vecteur donne poids
    double detMat = a * e * i  + b * f * g + c * d * h - c * e * g - f * h * a - i * b * d;
    double ai = e * i - f * h;
    double bi = c * h - b * i;
    double ci = b * f - c * e;
    double di = f * g - d * i;
    double ei = a * i - c * g;
    double fi = c * d - a * f;
    //		double gi = d * h - e * g;
    //		double hi = b * g - a * h;
    //		double ii = a * e - b * d;
    double oppx = (*CurrentPoint).x() - fxt.v[0]->x();
    double oppy = (*CurrentPoint).y() - fxt.v[0]->y();
    double oppz = (*CurrentPoint).z() - fxt.v[0]->z();
    double alpha = ai / detMat * oppx + bi / detMat * oppy + ci / detMat * oppz;
    double beta = di / detMat * oppx + ei / detMat * oppy + fi / detMat * oppz;
    //		double gamma = gi / detMat * oppx + hi / detMat * oppy + ii / detMat * oppz;
    //Test si poids entre 0 et 1 et si length maximale
    if ((alpha >= (0.0-epsilon)) && (alpha <= (1.0 + epsilon))){
      if ((beta >= (0.0-epsilon)) && (beta <= (1.0 + epsilon))){
        if (((1.0 - alpha - beta) >= (0.0-epsilon)) && ((1.0 - alpha - beta) <= (1.0 + epsilon))){
          SPoint3 PointTmp(fxt.v[0]->x() + alpha * (fxt.v[1]->x() - fxt.v[0]->x()) + beta * (fxt.v[2]->x() - fxt.v[0]->x()),fxt.v[0]->y() + alpha * (fxt.v[1]->y() - fxt.v[0]->y()) + beta * (fxt.v[2]->y() - fxt.v[0]->y()),fxt.v[0]->z() + alpha * (fxt.v[1]->z() - fxt.v[0]->z()) + beta * (fxt.v[2]->z() - fxt.v[0]->z()));
          double distanceTmp = PointTmp.distance((*CurrentPoint));
          if (distanceTmp > distanceP2P){
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
  //std::cout<<"   End of For loop"<<std::endl;
  //test si trop proche d'un point / une arete
  if (((alphaMax < epsilon) && (betaMax < epsilon)) || ((alphaMax < epsilon) && ((1.0 - alphaMax - betaMax) < epsilon)) || (((1.0 - alphaMax - betaMax) < epsilon) && (betaMax < epsilon))){
    //proche d'un point
    //std::cout<<"      Close to point"<<std::endl;
    double DistMinTmp = 10000000.0;
    int indexMinTmp = 0;
    for (unsigned int i = 0;i < 4;i++){
      double distanceTmp = sqrt(((*CurrentTet)->tet()->getVertex(i)->x() - ResultPoint.x()) * ((*CurrentTet)->tet()->getVertex(i)->x() - ResultPoint.x()) + ((*CurrentTet)->tet()->getVertex(i)->y() - ResultPoint.y()) * ((*CurrentTet)->tet()->getVertex(i)->y() - ResultPoint.y()) + ((*CurrentTet)->tet()->getVertex(i)->z() - ResultPoint.z()) * ((*CurrentTet)->tet()->getVertex(i)->z() - ResultPoint.z()));
      if (distanceTmp < DistMinTmp){
        DistMinTmp = distanceTmp;
        indexMinTmp = i;
      }
    }
    ////std::cout<<"NewTet before is "<<NewTet<<std::endl;
    MTet4* NewTet = GMSH_ThinLayerFixMeshPlugin::getTetFromPoint((*CurrentTet)->tet()->getVertex(indexMinTmp),InteriorNormal);
    //std::cout<<"NewTet after is "<<NewTet<<std::endl;
    SPoint3 PointTmp((*CurrentTet)->tet()->getVertex(indexMinTmp)->x(),(*CurrentTet)->tet()->getVertex(indexMinTmp)->y(),(*CurrentTet)->tet()->getVertex(indexMinTmp)->z());
    (*CurrentPoint) = PointTmp;
    (*CurrentTet) = NewTet;
  }
  else if ((alphaMax < epsilon) || (betaMax < epsilon) || ((1.0 - alphaMax - betaMax) < epsilon)){
    //trop proche d'une arete
    //std::cout<<"      Close to edge"<<std::endl;
  }
  else{
    //std::cout<<"      Close to nothing"<<std::endl;
    //std::cout<<"      ResultPoint is "<<ResultPoint.x()<<"; "<<ResultPoint.y()<<"; "<<ResultPoint.z()<<"; "<<" and tritoget is "<<triToGet<<std::endl;
    //std::cout<<"      CurrentPoint is "<<(*CurrentPoint).x()<<"; "<<(*CurrentPoint).y()<<"; "<<(*CurrentPoint).z()<<std::endl;
    (*CurrentPoint) = ResultPoint;
    //std::cout<<"      test 1"<<std::endl;
    //std::cout<<"      CurrentTri is "<<(*CurrentTri)<<std::endl;
    (*CurrentTri) = triToGet;
    //std::cout<<"      test 2"<<std::endl;
    //std::cout<<"      CurrentTet is "<<(*CurrentTet)<<" and has neighbours "<< (*CurrentTet)->getNeigh(0)<<" ; "<< (*CurrentTet)->getNeigh(1)<<" ; "<< (*CurrentTet)->getNeigh(2)<<" ; "<< (*CurrentTet)->getNeigh(3)<<std::endl;
    (*CurrentTet) = (*CurrentTet)->getNeigh(triToGet);
    //std::cout<<"      CurrentTet has been changed to "<<(*CurrentTet)<<std::endl;
    //std::cout<<"      test 3"<<std::endl;
  }
  //std::cout<<"   Exit FindNewPoint"<<std::endl;
}

void GMSH_ThinLayerFixMeshPlugin::fillVertexToTets(){
  GModel *m = GModel::current();
  for (GModel::riter itr= m->firstRegion();itr != m->lastRegion();itr++){
    GRegion* rTmp = (*itr);
    for (unsigned int i = 0; i < rTmp->tetrahedra.size();i++){
      MTetrahedron* elem = rTmp->tetrahedra[i];
      for (unsigned int j = 0; j < 4;j++){
        std::vector<MTetrahedron*> emptyTetVec;
        emptyTetVec.clear();
        VertexToTets[elem->getVertex(j)] = emptyTetVec;
        std::vector<CorrespVerticesFixMesh*> emptyCVVec;
        emptyCVVec.clear();
        VertexToCorresp[elem->getVertex(j)] = emptyCVVec;
      }
    }
  }
  for (GModel::riter itr= m->firstRegion();itr != m->lastRegion();itr++){
    GRegion* rTmp = (*itr);
    for (unsigned int i = 0; i < rTmp->tetrahedra.size();i++){
      MTetrahedron* elem = rTmp->tetrahedra[i];
      for (unsigned int j = 0; j < 4;j++){
        VertexToTets[elem->getVertex(j)].push_back(elem);
      }
    }
  }
}

static void setLcsFM(MTriangle *t, std::map<MVertex*, double> &vSizes,
                     std::set<MVertex*> &bndVertices)
{
  for(int i = 0; i < 3; i++){
    bndVertices.insert(t->getVertex(i));
    MEdge e = t->getEdge(i);
    MVertex *vi = e.getVertex(0);
    MVertex *vj = e.getVertex(1);
    double dx = vi->x()-vj->x();
    double dy = vi->y()-vj->y();
    double dz = vi->z()-vj->z();
    double l = sqrt(dx * dx + dy * dy + dz * dz);
    std::map<MVertex*,double>::iterator iti = vSizes.find(vi);
    std::map<MVertex*,double>::iterator itj = vSizes.find(vj);
    // use largest edge length
    if (iti == vSizes.end() || iti->second < l) vSizes[vi] = l;
    if (itj == vSizes.end() || itj->second < l) vSizes[vj] = l;
  }
}

static void setLcsFM(MTetrahedron *t, std::map<MVertex*, double> &vSizes,
                     std::set<MVertex*> &bndVertices)
{
  for (int i = 0; i < 4; i++){
    for (int j = i + 1; j < 4; j++){
      MVertex *vi = t->getVertex(i);
      MVertex *vj = t->getVertex(j);
      double dx = vi->x()-vj->x();
      double dy = vi->y()-vj->y();
      double dz = vi->z()-vj->z();
      double l = sqrt(dx * dx + dy * dy + dz * dz);
      std::map<MVertex*,double>::iterator iti = vSizes.find(vi);
      std::map<MVertex*,double>::iterator itj = vSizes.find(vj);
      std::set<MVertex*>::iterator itvi = bndVertices.find(vi);
      std::set<MVertex*>::iterator itvj = bndVertices.find(vj);
      // smallest tet edge
      if (itvi == bndVertices.end() &&
          (iti == vSizes.end() || iti->second > l)) vSizes[vi] = l;
      if (itvj == bndVertices.end() &&
          (itj == vSizes.end() || itj->second > l)) vSizes[vj] = l;
    }
  }
}

void GMSH_ThinLayerFixMeshPlugin::fillTetToTet4(){
  GModel *m = GModel::current();
  std::vector<double> vSizes;
  std::vector<double> vSizesBGM;
  MTet4Factory myFactory(1600000);
  std::set<MTet4*, compareTet4Ptr> &allTets = myFactory.getAllTets();
  std::set<MTet4*, compareTet4Ptr> activeTets;
  int NUM = 0;

  for (GModel::riter itr= m->firstRegion();itr != m->lastRegion();itr++){
    GRegion* gr = (*itr);
    { // leave this in a block so the map gets deallocated directly
      std::map<MVertex*, double> vSizesMap;
      std::set<MVertex*> bndVertices;
      for(GModel::fiter it = gr->model()->firstFace(); it != gr->model()->lastFace(); ++it){
        GFace *gf = *it;
        for(unsigned int i = 0; i < gf->triangles.size(); i++){
          setLcsFM(gf->triangles[i], vSizesMap, bndVertices);
        }
      }
      for(unsigned int i = 0; i < gr->tetrahedra.size(); i++)
        setLcsFM(gr->tetrahedra[i], vSizesMap, bndVertices);
      for(std::map<MVertex*, double>::iterator it = vSizesMap.begin();
          it != vSizesMap.end(); ++it){
        it->first->setIndex(NUM++);
        vSizes.push_back(it->second);
        vSizesBGM.push_back(it->second);
      }
    }
    for(unsigned int i = 0; i < gr->tetrahedra.size(); i++)
      {
        MTet4* currentTet4 = myFactory.Create(gr->tetrahedra[i], vSizes,vSizesBGM);
        TetToTet4[gr->tetrahedra[i]] = currentTet4;
        allTets.insert(currentTet4);
      }
  }


  std::vector<MTet4*> vecAllTet4;
  vecAllTet4.clear();
  for (std::set<MTet4*, compareTet4Ptr>::iterator itTp = allTets.begin();itTp != allTets.end();itTp++){
    vecAllTet4.push_back((*itTp));
    //		//std::cout<<"inserted "<<(*itTp)->tet()->getNum()<<std::endl;
  }
  connectTets(vecAllTet4);



  //	GModel *m = GModel::current();
  //	std::vector<MTet4*> vecAllTet4;
  //	vecAllTet4.clear();
  //	for (GModel::riter itr= m->firstRegion();itr != m->lastRegion();itr++){
  //		GRegion* rTmp = (*itr);
  //		for (unsigned int i = 0; i < rTmp->tetrahedra.size();i++){
  //			MTetrahedron* elem = rTmp->tetrahedra[i];
  //			MTet4 tet4tmp = MTet4(elem,0.0);
  //			MTet4* currentTet4 = &tet4tmp;
  //			TetToTet4[elem] = currentTet4;
  //			vecAllTet4.push_back(currentTet4);
  //		}
  //	}
  //	connectTets(vecAllTet4);
}

/****************static declarations****************/

std::map<MVertex*,std::vector<MTetrahedron*> > GMSH_ThinLayerFixMeshPlugin::VertexToTets;
std::map<MTetrahedron*,MTet4*> GMSH_ThinLayerFixMeshPlugin::TetToTet4;
std::map<MVertex*,std::vector<CorrespVerticesFixMesh*> > GMSH_ThinLayerFixMeshPlugin::VertexToCorresp;
std::vector<std::vector<CorrespVerticesFixMesh*> > GMSH_ThinLayerFixMeshPlugin::vecOfThinSheets;


#else

PView *GMSH_ThinLayerFixMeshPlugin::execute(PView *view)
{
  Msg::Error("Plugin(ThinLayerFixMesh requires mesh module");
  return view;
}

#endif
