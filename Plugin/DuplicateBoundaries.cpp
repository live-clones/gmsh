// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include "DuplicateBoundaries.h"
#include "GModel.h"
#include "discreteEdge.h"
#include "discreteFace.h"
#include "MElement.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MPrism.h"
#include "MEdge.h"
#include <fstream>
#include <sstream>
#include "Context.h"

StringXNumber DuplicateBoundariesOptions_Number[] = {
//  {GMSH_FULLRC, "Dimension", NULL, 1.},
//  {GMSH_FULLRC, "PhysicalGroup", NULL, 1.},
//  {GMSH_FULLRC, "OpenBoundaryPhysicalGroup", NULL, 0.},
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterDuplicateBoundariesPlugin()
  {
    return new GMSH_DuplicateBoundariesPlugin();
  }
}

std::string GMSH_DuplicateBoundariesPlugin::getHelp() const
{
  return "Plugin(Crack) creates a crack around the physical "
    "group `PhysicalGroup' of dimension `Dimension' (1 or 2). "
    "The plugin duplicates the vertices and the elements on "
    "the crack and stores them in a new discrete curve "
    "(`Dimension' = 1) or surface (`Dimension' = 2). The "
    "elements touching the crack on the negative side "
    "are modified to use the newly generated vertices."
    "If `OpenBoundaryPhysicalGroup' is given (> 0), its "
    "vertices are duplicated and the crack will be left "
    "open on that (part of the) boundary. Otherwise, the "
    "lips of the crack are sealed, i.e., its vertices are "
    "not duplicated.";
}

int GMSH_DuplicateBoundariesPlugin::getNbOptions() const
{
  return sizeof(DuplicateBoundariesOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_DuplicateBoundariesPlugin::getOption(int iopt)
{
  return &DuplicateBoundariesOptions_Number[iopt];
}

class EdgeData{
public:
  EdgeData(MEdge e) : edge(e) {}
  MEdge edge;
  std::vector<MVertex*> data;
};

struct Less_EdgeData : public std::binary_function<EdgeData, EdgeData, bool> {
  bool operator()(const EdgeData &e1, const EdgeData &e2) const
  {
    if(e1.edge.getMinVertex() < e2.edge.getMinVertex()) return true;
    if(e1.edge.getMinVertex() > e2.edge.getMinVertex()) return false;
    if(e1.edge.getMaxVertex() < e2.edge.getMaxVertex()) return true;
    return false;
  }
};

//OLF VERSION ONLY DUPLICATING NODES

//PView *GMSH_DuplicateBoundariesPlugin::execute(PView *view)
//{
//	std::cout<<"starting DuplicateBoundaries"<<std::endl;
//	GModel *m = GModel::current();
//	std::map<std::pair<MVertex*,GRegion*>,MVertex* > VertexAssociation;
//	for (GModel::viter itv = m->firstVertex();itv != m->lastVertex();itv++){
////		std::cout<<"entering first for"<<std::endl;
//		GVertex* vTmp = (*itv);
//		std::list<GRegion*> r = vTmp->regions();
//		std::cout<<"size of mesh_vertices: "<<vTmp->mesh_vertices.size()<<std::endl;
//		MVertex *vMesh = vTmp->mesh_vertices[0];
//		std::cout<<"size of r: "<<r.size()<<std::endl;
//		// for all regions, create association
////		for (int i = 0; i < vTmp->getNumMeshVertices();i++){
////			std::cout<<"entering second for"<<std::endl;
////			MVertex* vMesh = vTmp->getMeshVertex(i);
////			for (GModel::riter itr = vTmp->regions().begin();itr != vTmp->regions().end();itr++){
//		for (std::list<GRegion*>::iterator itr = r.begin();itr != r.end();itr++){
//			std::cout<<"entering third for"<<std::endl;
//			GRegion* vReg = (*itr);
//			//				std::cout<<"we have the region "<<vReg->
//			MVertex *newv = new MVertex(vMesh->x(), vMesh->y(), vMesh->z(), (GEntity*)vReg);
//			vReg->mesh_vertices.push_back(newv);
//			VertexAssociation[std::make_pair(vMesh,vReg)] = newv;
//			std::cout<<"end third for"<<std::endl;
//		}
////			std::cout<<"end second for"<<std::endl;
////		}
////		std::cout<<"end first for"<<std::endl;
//	}
//	std::cout<<"Phase 1 done for DuplicateBoundaries"<<std::endl;
//	for (GModel::eiter ite = m->firstEdge();ite != m->lastEdge();ite++){
//		GEdge* eTmp = (*ite);
//		for (int i = 0; i < eTmp->mesh_vertices.size();i++){
//			MVertex* vMesh = eTmp->mesh_vertices[i];
//			std::list<GRegion*> r = eTmp->regions();
//			for (std::list<GRegion*>::iterator itr = r.begin();itr != r.end();itr++){
//				GRegion* vReg = (*itr);
//				MVertex *newv = new MVertex(vMesh->x(), vMesh->y(), vMesh->z(), (GEntity*)vReg);
//				vReg->mesh_vertices.push_back(newv);
//				VertexAssociation[std::make_pair(vMesh,vReg)] = newv;
//			}
//		}
//	}
//	std::cout<<"Phase 2 done for DuplicateBoundaries"<<std::endl;
//	for (GModel::fiter itf = m->firstFace();itf != m->lastFace();itf++){
//		GFace* fTmp = (*itf);
//		for (int i = 0; i < fTmp->mesh_vertices.size();i++){
//			MVertex* vMesh = fTmp->mesh_vertices[i];
//			std::list<GRegion*> r = fTmp->regions();
//			for (std::list<GRegion*>::iterator itr = r.begin();itr != r.end();itr++){
//				GRegion* vReg = (*itr);
//				MVertex *newv = new MVertex(vMesh->x(), vMesh->y(), vMesh->z(), (GEntity*)vReg);
//				vReg->mesh_vertices.push_back(newv);
//				VertexAssociation[std::make_pair(vMesh,vReg)] = newv;
//			}
//		}
//	}
//	std::cout<<"Phase 3 done for DuplicateBoundaries"<<std::endl;
//	for (GModel::riter itr = m->firstRegion();itr != m->lastRegion();itr++){
//		GRegion* rTmp = (*itr);
//		for (int i = 0; i < rTmp->getNumMeshElements();i++){
//			MElement* elem = rTmp->getMeshElement(i);
//			for (int j = 0;j < elem->getNumVertices();j++){
//				MVertex* vert = elem->getVertex(j);
//				std::map<std::pair<MVertex*,GRegion*>,MVertex* >::iterator itMap = VertexAssociation.find(std::make_pair(vert,rTmp));
//				if (itMap != VertexAssociation.end()){
//					elem->setVertex(j,itMap->second);
//				}
//			}
//		}
//	}
//	std::cout<<"End of DuplicateBoundaries"<<std::endl;
//	return view;
//}

double GMSH_DuplicateBoundariesPlugin::abs(double x){
	if (x < 0.0){
		return (-x);
	}
	else{
		return x;
	}
}

PView *GMSH_DuplicateBoundariesPlugin::executeBis(PView *view)
{
	std::cout<<"starting DuplicateBoundaries"<<std::endl;
	GModel *m = GModel::current();
	m->setFactory("geo");
	std::set<GFace*> ToDuplicateList;
	ToDuplicateList.clear();
	std::set<GFace*> ToDuplicateListBoundary;
	ToDuplicateListBoundary.clear();
	std::vector<GFace*> facesBound;
	facesBound.clear();
	std::map<GFace*,SPoint3> centers;
	std::vector<std::pair<GFace*,GFace*> > pairs;
//	int PhysicalSeeds = m->setPhysicalName("Seeds",3);
//
//	//std::cout<<"number for seeds: "<<PhysicalSeeds<<" and for interface: "<<PhysicalInterface<<std::endl;
//
//	for (GModel::riter itf= m->firstRegion();itf != m->lastRegion();itf++){
//		GRegion* fTmp = (*itf);
//		fTmp->addPhysicalEntity(PhysicalSeeds);
//	}
	int PhysicalInterface = m->setPhysicalName("Interface",3);
	std::cout<<"DEBUT INIT"<<std::endl;
	for (GModel::fiter itf= m->firstFace();itf != m->lastFace();itf++){
		GFace* fTmp = (*itf);


		for (unsigned int i = 0; i < fTmp->getNumMeshElements();i++){
			MElement* elem = fTmp->getMeshElement(i);
//			std::cout<<"TEST INITIAL"<<std::endl;

			if (elem->getVertex(0)->getNum() > 100000){
				std::cout<<"on a un getnum de "<<elem->getVertex(0)->getNum()<<std::endl;
				while (1){

				}
			}
			if (elem->getVertex(1)->getNum() > 100000){
				std::cout<<"on a un getnum de "<<elem->getVertex(1)->getNum()<<std::endl;
				while (1){

				}
			}
			if (elem->getVertex(2)->getNum() > 100000){
				std::cout<<"on a un getnum de "<<elem->getVertex(2)->getNum()<<std::endl;
				while (1){

				}
			}
		}


		if (fTmp->numRegions() == 2){
			ToDuplicateList.insert(fTmp);
		}
		else{
			facesBound.push_back(fTmp);
			//ToDuplicateListBoundary.insert(fTmp);
		}
	}
	std::cout<<"FIN INIT"<<std::endl;

	for(unsigned int i=0;i<facesBound.size();i++){
		double x = 0.0;
		double y = 0.0;
		double z = 0.0;

		std::list<GVertex*> vertices;

		vertices = facesBound[i]->vertices();

		for(std::list<GVertex*>::iterator it2=vertices.begin();it2!=vertices.end();it2++){
			x = x + (*it2)->x();
			y = y + (*it2)->y();
			z = z + (*it2)->z();
		}

		x = x/vertices.size();
		y = y/vertices.size();
		z = z/vertices.size();

		centers.insert(std::pair<GFace*,SPoint3>(facesBound[i],SPoint3(x,y,z)));
	}

	for(unsigned int i=0;i<facesBound.size();i++){
		for(unsigned int j=0;j<facesBound.size();j++){
			std::map<GFace*,SPoint3>::iterator it3 = centers.find(facesBound[i]);
			std::map<GFace*,SPoint3>::iterator it4 = centers.find(facesBound[j]);

			SPoint3 p1 = it3->second;
			SPoint3 p2 = it4->second;


			//				categories.push_back(val);

			//				print_segment(p1,p2,file);

			if (abs((p2.x()-p1.x()-1.0))<0.0001){
				if (abs((p2.y()-p1.y()))<0.0001){
					if (abs((p2.z()-p1.z()))<0.0001){
						pairs.push_back(std::pair<GFace*,GFace*>(facesBound[i],facesBound[j]));
						ToDuplicateListBoundary.insert(facesBound[i]);
						std::cout<<"case 1"<<std::endl;
//						std::cout<<"on a p1.x() = "<<p1.x()<<" et p2.x() = "<<p2.x()<<" et abs((p2.x()-p1.x()-1.0)) = "<<abs((p2.x()-p1.x()-1.0))<<std::endl;
//						std::cout<<"on a abs(0.5) = "<<abs(0.5)<<" et abs(-0.5) = "<<abs(-0.5)<<" et abs(1.5) = "<<abs(1.5)<<" et abs(-1.5) = "<<abs(-1.5)<<std::endl;
//						std::cout<<"on a mis dans la liste: x "<<p1.x()<<" y "<<p1.y()<<" z "<<p1.z()<<std::endl;
//						std::cout<<"on avait pour second: x "<<p2.x()<<" y "<<p2.y()<<" z "<<p2.z()<<std::endl;
					}else if(abs((p2.z()-p1.z()-1.0))<0.0001){
						pairs.push_back(std::pair<GFace*,GFace*>(facesBound[i],facesBound[j]));
						ToDuplicateListBoundary.insert(facesBound[i]);
//						std::cout<<"case 2"<<std::endl;
//						std::cout<<"on a mis dans la liste: x "<<p1.x()<<" y "<<p1.y()<<" z "<<p1.z()<<std::endl;
//						std::cout<<"on avait pour second: x "<<p2.x()<<" y "<<p2.y()<<" z "<<p2.z()<<std::endl;
					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
						pairs.push_back(std::pair<GFace*,GFace*>(facesBound[i],facesBound[j]));
						ToDuplicateListBoundary.insert(facesBound[i]);
//						std::cout<<"case 3"<<std::endl;
//						std::cout<<"on a mis dans la liste: x "<<p1.x()<<" y "<<p1.y()<<" z "<<p1.z()<<std::endl;
//						std::cout<<"on avait pour second: x "<<p2.x()<<" y "<<p2.y()<<" z "<<p2.z()<<std::endl;
					}
				}else if (abs((p2.y()-p1.y()-1.0))<0.0001){
					if (abs((p2.z()-p1.z()))<0.0001){
						pairs.push_back(std::pair<GFace*,GFace*>(facesBound[i],facesBound[j]));
						ToDuplicateListBoundary.insert(facesBound[i]);
//						std::cout<<"case 4"<<std::endl;
//						std::cout<<"on a mis dans la liste: x "<<p1.x()<<" y "<<p1.y()<<" z "<<p1.z()<<std::endl;
//						std::cout<<"on avait pour second: x "<<p2.x()<<" y "<<p2.y()<<" z "<<p2.z()<<std::endl;
					}else if (abs((p2.z()-p1.z()-1.0))<0.0001){
						pairs.push_back(std::pair<GFace*,GFace*>(facesBound[i],facesBound[j]));
						ToDuplicateListBoundary.insert(facesBound[i]);
//						std::cout<<"case 5"<<std::endl;
//						std::cout<<"on a mis dans la liste: x "<<p1.x()<<" y "<<p1.y()<<" z "<<p1.z()<<std::endl;
//						std::cout<<"on avait pour second: x "<<p2.x()<<" y "<<p2.y()<<" z "<<p2.z()<<std::endl;
					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
						pairs.push_back(std::pair<GFace*,GFace*>(facesBound[i],facesBound[j]));
						ToDuplicateListBoundary.insert(facesBound[i]);
//						std::cout<<"case 6"<<std::endl;
//						std::cout<<"on a mis dans la liste: x "<<p1.x()<<" y "<<p1.y()<<" z "<<p1.z()<<std::endl;
//						std::cout<<"on avait pour second: x "<<p2.x()<<" y "<<p2.y()<<" z "<<p2.z()<<std::endl;
					}
				}else if (abs((p1.y()-p2.y()-1.0))<0.0001){
					if (abs((p2.z()-p1.z()))<0.0001){
						pairs.push_back(std::pair<GFace*,GFace*>(facesBound[i],facesBound[j]));
						ToDuplicateListBoundary.insert(facesBound[i]);
//						std::cout<<"case 7"<<std::endl;
//						std::cout<<"on a mis dans la liste: x "<<p1.x()<<" y "<<p1.y()<<" z "<<p1.z()<<std::endl;
//						std::cout<<"on avait pour second: x "<<p2.x()<<" y "<<p2.y()<<" z "<<p2.z()<<std::endl;
					}else if (abs((p2.z()-p1.z()-1.0))<0.0001){
						pairs.push_back(std::pair<GFace*,GFace*>(facesBound[i],facesBound[j]));
						ToDuplicateListBoundary.insert(facesBound[i]);
//						std::cout<<"case 8"<<std::endl;
//						std::cout<<"on a mis dans la liste: x "<<p1.x()<<" y "<<p1.y()<<" z "<<p1.z()<<std::endl;
//						std::cout<<"on avait pour second: x "<<p2.x()<<" y "<<p2.y()<<" z "<<p2.z()<<std::endl;
					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
						pairs.push_back(std::pair<GFace*,GFace*>(facesBound[i],facesBound[j]));
						ToDuplicateListBoundary.insert(facesBound[i]);
//						std::cout<<"case 9"<<std::endl;
//						std::cout<<"on a mis dans la liste: x "<<p1.x()<<" y "<<p1.y()<<" z "<<p1.z()<<std::endl;
//						std::cout<<"on avait pour second: x "<<p2.x()<<" y "<<p2.y()<<" z "<<p2.z()<<std::endl;
					}
				}
			}else if (abs((p1.x()-p2.x()-1.0))<0.0001){
				if (abs((p2.y()-p1.y()))<0.0001){
					if (abs((p2.z()-p1.z()))<0.0001){
						//NOTHING
					}else if(abs((p2.z()-p1.z()-1.0))<0.0001){
						//NOTHING
					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
						//NOTHING
					}
				}else if (abs((p2.y()-p1.y()-1.0))<0.0001){
					if (abs((p2.z()-p1.z()))<0.0001){
						//NOTHING
					}else if (abs((p2.z()-p1.z()-1.0))<0.0001){
						//NOTHING
					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
						//NOTHING
					}
				}else if (abs((p1.y()-p2.y()-1.0))<0.0001){
					if (abs((p2.z()-p1.z()))<0.0001){
						//NOTHING
					}else if (abs((p2.z()-p1.z()-1.0))<0.0001){
						//NOTHING
					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
						//NOTHING
					}
				}
			}else if (abs((p1.x()-p2.x()))<0.0001){
				if (abs((p2.y()-p1.y()-1.0))<0.0001){
					if (abs((p2.z()-p1.z()))<0.0001){
						pairs.push_back(std::pair<GFace*,GFace*>(facesBound[i],facesBound[j]));
						ToDuplicateListBoundary.insert(facesBound[i]);
//						std::cout<<"case 10"<<std::endl;
//						std::cout<<"on a mis dans la liste: x "<<p1.x()<<" y "<<p1.y()<<" z "<<p1.z()<<std::endl;
//						std::cout<<"on avait pour second: x "<<p2.x()<<" y "<<p2.y()<<" z "<<p2.z()<<std::endl;
					}else if (abs((p2.z()-p1.z()-1.0))<0.0001){
						pairs.push_back(std::pair<GFace*,GFace*>(facesBound[i],facesBound[j]));
						ToDuplicateListBoundary.insert(facesBound[i]);
//						std::cout<<"case 11"<<std::endl;
//						std::cout<<"on a mis dans la liste: x "<<p1.x()<<" y "<<p1.y()<<" z "<<p1.z()<<std::endl;
//						std::cout<<"on avait pour second: x "<<p2.x()<<" y "<<p2.y()<<" z "<<p2.z()<<std::endl;
					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
						pairs.push_back(std::pair<GFace*,GFace*>(facesBound[i],facesBound[j]));
						ToDuplicateListBoundary.insert(facesBound[i]);
//						std::cout<<"case 12"<<std::endl;
//						std::cout<<"on a mis dans la liste: x "<<p1.x()<<" y "<<p1.y()<<" z "<<p1.z()<<std::endl;
//						std::cout<<"on avait pour second: x "<<p2.x()<<" y "<<p2.y()<<" z "<<p2.z()<<std::endl;
					}
				}else if (abs((p1.y()-p2.y()-1.0))<0.0001){
					if (abs((p2.z()-p1.z()))<0.0001){
						//NOTHING
					}else if (abs((p2.z()-p1.z()-1.0))<0.0001){
						//NOTHING
					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
						//NOTHING
					}
				}else if (abs((p1.y()-p2.y()))<0.0001){
					if (abs((p2.z()-p1.z()-1.0))<0.0001){
						pairs.push_back(std::pair<GFace*,GFace*>(facesBound[i],facesBound[j]));
						ToDuplicateListBoundary.insert(facesBound[i]);
//						std::cout<<"case 13"<<std::endl;
//						std::cout<<"on a mis dans la liste: x "<<p1.x()<<" y "<<p1.y()<<" z "<<p1.z()<<std::endl;
//						std::cout<<"on avait pour second: x "<<p2.x()<<" y "<<p2.y()<<" z "<<p2.z()<<std::endl;
					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
						//NOTHING
					}
				}
			}
		}
	}
	std::cout<<"on a une taille de facesBound = "<<facesBound.size()<<" et ToDuplicateListBoundary = "<<ToDuplicateListBoundary.size()<<std::endl;

	int counterNbDone = 10000;
	//int tagEdges = 10000;
	for (std::set<GFace*>::iterator itr = ToDuplicateList.begin();itr != ToDuplicateList.end();itr++){
		std::cout<<"on est entre pour la fois numero "<<counterNbDone<<std::endl;
		counterNbDone++;
		GFace* fTmp = (*itr);
		//on doit dupliquer la face, les noeuds, les aretes, puis creer une region entre les deux
		std::map<MVertex*,MVertex* > VertexAssociation;
		std::map<GVertex*,GVertex* > GVertexAssociation;
		std::map<GEdge*,GEdge* > GEdgeAssociation;
		std::list<GVertex*> vlist = fTmp->vertices();
		std::map<GVertex*,GEdge* > SurroudingEdges;
		GRegion *rTmp = fTmp->getRegion(1);
		std::list<GFace*> facesReg;
		facesReg = rTmp->faces();
		std::cout<<"rmtp a un nombre INITIAL de faces de "<<rTmp->faces().size()<<std::endl;
		for (std::list<GFace*>::iterator it2=facesReg.begin();it2!=facesReg.end();it2++){
			GFace* fTemp = (*it2);
			std::cout<<" ID "<<fTemp->tag();
		}
		double xCenterReg = 0.0;
		double yCenterReg = 0.0;
		double zCenterReg = 0.0;




		std::cout<<"nb de faces de la region 2: "<<rTmp->faces().size()<<std::endl;
		std::cout<<"nb de points de la face 1 de region 2: "<<rTmp->faces().front()->vertices().size()<<std::endl;
		std::cout<<"nb de points de la region 2: "<<rTmp->vertices().size()<<std::endl;

		int counterPts = 0;
		for(std::list<GFace*>::iterator it2=facesReg.begin();it2!=facesReg.end();it2++){
			GFace* fTemp = (*it2);
			std::list<GVertex*> verticesFace = fTemp->vertices();
			for (std::list<GVertex*>::iterator it3=verticesFace.begin();it3!=verticesFace.end();it3++){
				xCenterReg = xCenterReg + (*it3)->x();
				yCenterReg = yCenterReg + (*it3)->y();
				zCenterReg = zCenterReg + (*it3)->z();
				counterPts++;
			}
		}

		xCenterReg = xCenterReg/counterPts;
		yCenterReg = yCenterReg/counterPts;
		zCenterReg = zCenterReg/counterPts;

		std::cout<<"debut boucle for "<<counterNbDone<<std::endl;
		for (std::list<GVertex*>::iterator itv = vlist.begin();itv != vlist.end();itv++){
			//duplication Gvertex
			std::cout<<"point 1 "<<counterNbDone<<std::endl;
			GVertex* vTmp = (*itv);
			std::cout<<"point 2 "<<counterNbDone<<std::endl;
			double ponderatedX = 0.99999999999 * vTmp->x() + 0.00000000001 * xCenterReg;
			double ponderatedY = 0.99999999999 * vTmp->y() + 0.00000000001 * yCenterReg;
			double ponderatedZ = 0.99999999999 * vTmp->z() + 0.00000000001 * zCenterReg;
//			double ponderatedX = 1.0 * vTmp->x() + 0.0 * xCenterReg;
//			double ponderatedY = 1.0 * vTmp->y() + 0.0 * yCenterReg;
//			double ponderatedZ = 1.0 * vTmp->z() + 0.0 * zCenterReg;
			//GVertex* newv = new gmshVertex(m,vTmp->prescribedMeshSizeAtVertex());
			GVertex* newv = m->addVertex(ponderatedX,ponderatedY,ponderatedZ,vTmp->prescribedMeshSizeAtVertex());
			std::cout<<"point 3 "<<counterNbDone<<std::endl;
			GVertexAssociation[vTmp] = newv;
			std::cout<<"test du ancien point: "<<vTmp->x()<<" et "<<vTmp->y()<<" et "<<vTmp->z()<<std::endl;
			//creation des Gedge correspondantes
			std::cout<<"point 4 "<<counterNbDone<<std::endl;
			std::cout<<"test du nouveau point: "<<newv->x()<<" et "<<newv->y()<<" et "<<newv->z()<<std::endl;
			//GEdge* newE = new GEdge(m,tagEdges,vTmp,newv);
			//tagEdges++;
			//m->add(newE);
			std::cout<<"point gloubigoulba "<<counterNbDone<<std::endl;
			GEdge* newE = m->addLine(vTmp,newv);
			std::cout<<"point 5 "<<counterNbDone<<std::endl;
			SurroudingEdges[vTmp] = newE;
			//maintenant traitement mesh
			std::cout<<"point 6 "<<counterNbDone<<std::endl;
			MVertex *vMesh = vTmp->mesh_vertices[0];
			std::cout<<"point 7 "<<counterNbDone<<std::endl;
			MVertex *newMv = new MVertex(vMesh->x(), vMesh->y(), vMesh->z(), (GEntity*)newv);
			std::cout<<"point 8 "<<counterNbDone<<std::endl;
			VertexAssociation[vMesh] = newMv;
			std::cout<<"point 9 "<<counterNbDone<<std::endl;
			newv->addMeshVertex(newMv);
			if (newMv->getNum() > 100000){
				std::cout<<"on a un getnum de "<<newMv->getNum()<<std::endl;
				while (1){

				}
			}
			if (vMesh->getNum() > 100000){
				std::cout<<"What ? on a un getnum vtmp de "<<newMv->getNum()<<std::endl;
				while (1){

				}
			}
		}
		std::cout<<"apres points "<<counterNbDone<<std::endl;
		std::list<GEdge*> elist = fTmp->edges();
		std::vector<GEdge*> newEdgesVector;
		std::vector<GFace*> SurroundingsFaces;
		for (std::list<GEdge*>::iterator ite = elist.begin();ite != elist.end();ite++){
			//duplication Gedge
			GEdge* eTmp = (*ite);
			GEdge* newE = m->addLine(GVertexAssociation[eTmp->getEndVertex()],GVertexAssociation[eTmp->getBeginVertex()]);
			GEdgeAssociation[eTmp] = newE;
			newEdgesVector.push_back(newE);
			//creation des GFace correspondantes
			GEdge* firstE = SurroudingEdges.find(eTmp->getEndVertex())->second;
			GEdge* lastE = SurroudingEdges.find(eTmp->getBeginVertex())->second;
			std::vector<GEdge*> VecEdgesTmp;
			VecEdgesTmp.push_back(eTmp);
			VecEdgesTmp.push_back(firstE);
			VecEdgesTmp.push_back(newE);
			VecEdgesTmp.push_back(lastE);
			std::vector<std::vector<GEdge*> > VecOfVecTmp;
			VecOfVecTmp.push_back(VecEdgesTmp);
			GFace* newFaceTmp = m->addPlanarFace(VecOfVecTmp);
			SurroundingsFaces.push_back(newFaceTmp);
			//maintenant traitement mesh
			for (unsigned int i = 0; i < eTmp->mesh_vertices.size();i++){
				MVertex *vMesh = eTmp->mesh_vertices[i];
				MVertex *newMv = new MVertex(vMesh->x(), vMesh->y(), vMesh->z(), (GEntity*)newE);
				VertexAssociation[vMesh] = newMv;
				newE->addMeshVertex(newMv);
			}
			for (unsigned int i = 0; i < eTmp->getNumMeshElements();i++){
				MElement* elem = eTmp->getMeshElement(i);
				MVertex *firstETmp = VertexAssociation.find(elem->getVertex(0))->second;
				MVertex *lastETmp = VertexAssociation.find(elem->getVertex(1))->second;
				MLine *newLine = new MLine(firstETmp,lastETmp);
				newE->addLine(newLine);
			}
		}
		std::cout<<"apres lignes "<<counterNbDone<<std::endl;
		std::vector<std::vector<GEdge*> > VecOfVec;
		VecOfVec.push_back(newEdgesVector);
		//creation de la nouvelle face
		GFace* GFaceAssociation = m->addPlanarFace(VecOfVec);
		//maintenant traitement mesh
		for (unsigned int i = 0; i < fTmp->mesh_vertices.size();i++){
			MVertex *vMesh = fTmp->mesh_vertices[i];
			MVertex *newMv = new MVertex(vMesh->x(), vMesh->y(), vMesh->z(), (GEntity*)GFaceAssociation);
			VertexAssociation[vMesh] = newMv;
			GFaceAssociation->addMeshVertex(newMv);
		}
		for (unsigned int i = 0; i < fTmp->getNumMeshElements();i++){
			MElement* elem = fTmp->getMeshElement(i);
			MVertex *firstE = VertexAssociation.find(elem->getVertex(0))->second;
			MVertex *secondE = VertexAssociation.find(elem->getVertex(1))->second;
			MVertex *thirdE = VertexAssociation.find(elem->getVertex(2))->second;
			MTriangle *newTri = new MTriangle(firstE,secondE,thirdE);
			GFaceAssociation->addTriangle(newTri);

			if (elem->getVertex(0)->getNum() > 100000){
				std::cout<<"ANCIENT TRI on a un getnum de "<<elem->getVertex(0)->getNum()<<std::endl;
				while (1){

				}
			}
			if (elem->getVertex(1)->getNum() > 100000){
				std::cout<<"ANCIENT TRI on a un getnum de "<<elem->getVertex(1)->getNum()<<std::endl;
				while (1){

				}
			}
			if (elem->getVertex(2)->getNum() > 100000){
				std::cout<<"ANCIENT TRI on a un getnum de "<<elem->getVertex(2)->getNum()<<std::endl;
				while (1){

				}
			}

			if (firstE->getNum() > 100000){
				std::cout<<"CREAT TRI on a un getnum de "<<firstE->getNum()<<std::endl;
				while (1){

				}
			}
			if (secondE->getNum() > 100000){
				std::cout<<"CREAT TRI on a un getnum de "<<secondE->getNum()<<std::endl;
				while (1){

				}
			}
			if (thirdE->getNum() > 100000){
				std::cout<<"CREAT TRI on a un getnum de "<<thirdE->getNum()<<std::endl;
				while (1){

				}
			}

		}
		std::cout<<"apres faces "<<counterNbDone<<std::endl;
		std::vector<GFace*> VectorFaces;
		std::list<GFace*> listFaces;
		VectorFaces.push_back(fTmp);
		listFaces.push_back(fTmp);
		for (unsigned int i = 0;i < SurroundingsFaces.size();i++){
			VectorFaces.push_back(SurroundingsFaces[i]);
			listFaces.push_back(SurroundingsFaces[i]);
		}
		VectorFaces.push_back(GFaceAssociation);
		listFaces.push_back(GFaceAssociation);
		std::vector<std::vector<GFace*> > VecOfVecGFace;
		VecOfVecGFace.push_back(VectorFaces);
		std::cout<<"creation de la nouvelle region "<<counterNbDone<<std::endl;
		//creation de la nouvelle region

		GRegion* createdRegion = new GRegion(m,counterNbDone);
		createdRegion->addPhysicalEntity(PhysicalInterface);
		createdRegion->set(listFaces);
		m->add(createdRegion);
//		std::cout<<"plop 1"<<std::endl;
		std::list<GFace*> RegFaces = rTmp->faces();
//		std::cout<<"plop 2"<<std::endl;
		std::list<GFace*>::iterator it = std::find(RegFaces.begin(), RegFaces.end(), fTmp);
//		std::cout<<"plop 3"<<std::endl;
//		std::cout<<"RegFaces a un nombre de faces de "<<RegFaces.size()<<std::endl;
		std::cout<<(*it)->tag()<<std::endl;
		if(it != RegFaces.end()) RegFaces.erase(it);
//		std::cout<<"RegFaces a un nombre de faces de "<<RegFaces.size()<<std::endl;
//		if(it != RegFaces.end()) RegFaces.remove((*it));
//		std::cout<<"plop 4"<<std::endl;
		RegFaces.push_back(GFaceAssociation);
//		std::cout<<GFaceAssociation->tag()<<std::endl;
//		std::cout<<"plop 5"<<std::endl;
		rTmp->set(RegFaces);
//		std::cout<<"rmtp a un nombre de faces de "<<rTmp->faces().size()<<std::endl;
		std::list<GFace*> NewFacesReg;
		NewFacesReg = rTmp->faces();
		for (std::list<GFace*>::iterator it2=NewFacesReg.begin();it2!=NewFacesReg.end();it2++){
			GFace* fTemp = (*it2);
//			std::cout<<" ID "<<fTemp->tag();
			for (std::list<GEdge*>::iterator ite = elist.begin();ite != elist.end();ite++){
				GEdge* eTmp = (*ite);
				GEdge* newE = GEdgeAssociation[eTmp];
				fTemp->replaceEdge(eTmp,newE);
			}
		}
		std::cout<<"plop 6"<<std::endl;
		for (unsigned int i = 0; i < fTmp->getNumMeshElements();i++){
			MElement* elem = fTmp->getMeshElement(i);
//			std::cout<<"on an element with a number of vertices of: "<<elem->getNumVertices()<<std::endl;

			if (elem->getVertex(0)->getNum() > 100000){
				std::cout<<"on a un getnum de "<<elem->getVertex(0)->getNum()<<std::endl;
				while (1){

				}
			}
			if (elem->getVertex(1)->getNum() > 100000){
				std::cout<<"on a un getnum de "<<elem->getVertex(1)->getNum()<<std::endl;
				while (1){

				}
			}
			if (elem->getVertex(2)->getNum() > 100000){
				std::cout<<"on a un getnum de "<<elem->getVertex(2)->getNum()<<std::endl;
				while (1){

				}
			}

//			std::cout<<"on a un element avec un nb de vertex de "<<elem->getNumVertices()<<std::endl;
			MVertex *firstE = VertexAssociation.find(elem->getVertex(0))->second;
			MVertex *secondE = VertexAssociation.find(elem->getVertex(1))->second;
			MVertex *thirdE = VertexAssociation.find(elem->getVertex(2))->second;

			if (firstE->getNum() > 100000){
				std::cout<<"on a un getnum de "<<firstE->getNum()<<std::endl;
				while (1){

				}
			}
			if (secondE->getNum() > 100000){
				std::cout<<"on a un getnum de "<<secondE->getNum()<<std::endl;
				while (1){

				}
			}
			if (thirdE->getNum() > 100000){
				std::cout<<"on a un getnum de "<<thirdE->getNum()<<std::endl;
				while (1){

				}
			}
//			std::cout<<"on a les 3 vertices: "<<elem->getVertex(0)->getNum()<<" "<<elem->getVertex(1)->getNum()<<" "<<elem->getVertex(2)->getNum()<<std::endl;
//			std::cout<<"et les 3 vertices: "<<firstE->getNum()<<" "<<secondE->getNum()<<" "<<thirdE->getNum()<<std::endl;
//			std::cout<<"creation de prisme "<<counterNbDone<<std::endl;
			MPrism *newPri = new MPrism(elem->getVertex(0),elem->getVertex(1),elem->getVertex(2),firstE,secondE,thirdE);
//			std::cout<<"addition de prisme "<<counterNbDone<<std::endl;

			createdRegion->addPrism(newPri);
//			std::cout<<"fin de for"<<std::endl;
		}
		std::cout<<"apres region, refonte points "<<counterNbDone<<std::endl;
		for (unsigned int i = 0; i < rTmp->getNumMeshElements();i++){
			MElement* elem = rTmp->getMeshElement(i);
			for (int j = 0;j < elem->getNumVertices();j++){
				MVertex* vert = elem->getVertex(j);
				std::map<MVertex*,MVertex* >::iterator itMap = VertexAssociation.find(vert);
				if (itMap != VertexAssociation.end()){
//					std::cout<<"on va changer un point"<<std::endl;
					elem->setVertex(j,itMap->second);
//					std::cout<<"on a introduit "<<itMap->second->getNum()<<std::endl;
//					std::cout<<"maintenant elem j "<<elem->getVertex(j)->getNum()<<std::endl;
//					std::cout<<"youpi"<<std::endl;
				}
			}
		}
		std::cout<<"plop 7"<<std::endl;
//		std::cout<<"rmtp a un nombre de faces de "<<rTmp->faces().size()<<std::endl;
		int countTmp = 0;
		//maitenant refonte points dans faces
		for (std::list<GFace*>::iterator itTmp = NewFacesReg.begin();itTmp != NewFacesReg.end();itTmp++){
			GFace* GFaceTmp = (*itTmp);
//			std::cout<<GFaceTmp->tag()<<std::endl;
			countTmp++;
//			std::cout<<" iteration "<<countTmp<<std::endl;
			for (unsigned int i = 0; i < GFaceTmp->getNumMeshElements();i++){
//				std::cout<<" plop 7.1"<<std::endl;
				MElement* elem = GFaceTmp->getMeshElement(i);
				for (int j = 0;j < elem->getNumVertices();j++){
//					std::cout<<" plop 7.2"<<std::endl;
					MVertex* vert = elem->getVertex(j);
//					std::cout<<" plop 7.3"<<std::endl;
					std::map<MVertex*,MVertex* >::iterator itMap = VertexAssociation.find(vert);
//					std::cout<<" plop 7.4"<<std::endl;
					if (itMap != VertexAssociation.end()){
//						std::cout<<"on va changer un point"<<std::endl;
//						if (elem->getNumVertices() != 3){
//							std::cout<<"on a un pb ! nb de vertices de "<<elem->getNumVertices()<<std::endl;
//							while (1){
//
//							}
//						}
						elem->setVertex(j,itMap->second);
						if (elem->getVertex(j)->getNum() > 100000){
							std::cout<<"PENDANT CHANGEMENT on a un getnum de "<<elem->getVertex(j)->getNum()<<std::endl;
							while (1){

							}
						}
						if (itMap->second->getNum() > 100000){
							std::cout<<"PENDANT CHANGEMENT on a un ITMAP getnum de "<<itMap->second->getNum()<<std::endl;
							while (1){

							}
						}


						std::vector<MVertex*> FaceVerti = GFaceTmp->mesh_vertices;
						std::vector<MVertex*>::iterator itHere = std::find(FaceVerti.begin(), FaceVerti.end(), vert);
						if(itHere != FaceVerti.end()) {
							FaceVerti.erase(itHere);
							FaceVerti.push_back(itMap->second);
							GFaceTmp->mesh_vertices = FaceVerti;
						}


//						std::cout<<"rmtp a un nombre de faces de "<<rTmp->faces().size()<<std::endl;
//						std::cout<<"on a introduit "<<itMap->second->getNum()<<std::endl;
//						std::cout<<"maintenant elem j "<<elem->getVertex(j)->getNum()<<std::endl;
//						std::cout<<"youpi"<<std::endl;
					}
				}
			}
//			std::cout<<"plop 8"<<std::endl;
		}
	}

	//maintenant on attaque les faces au bord
	for (std::set<GFace*>::iterator itr = ToDuplicateListBoundary.begin();itr != ToDuplicateListBoundary.end();itr++){
		std::cout<<"AU BORD on est entre pour la fois numero "<<counterNbDone<<std::endl;
		counterNbDone++;
		GFace* fTmp = (*itr);
		//on doit dupliquer la face, les noeuds, les aretes, puis creer une region entre les deux
		std::map<MVertex*,MVertex* > VertexAssociation;
		std::map<GVertex*,GVertex* > GVertexAssociation;
		std::map<GEdge*,GEdge* > GEdgeAssociation;
		std::list<GVertex*> vlist = fTmp->vertices();
		std::map<GVertex*,GEdge* > SurroudingEdges;
		GRegion *rTmp = fTmp->getRegion(0);
		double xCenterReg = 0.0;
		double yCenterReg = 0.0;
		double zCenterReg = 0.0;

		std::list<GFace*> facesReg;

		facesReg = rTmp->faces();

		int counterPts = 0;
		for(std::list<GFace*>::iterator it2=facesReg.begin();it2!=facesReg.end();it2++){
			GFace* fTemp = (*it2);
			std::list<GVertex*> verticesFace = fTemp->vertices();
			for (std::list<GVertex*>::iterator it3=verticesFace.begin();it3!=verticesFace.end();it3++){
				xCenterReg = xCenterReg + (*it3)->x();
				yCenterReg = yCenterReg + (*it3)->y();
				zCenterReg = zCenterReg + (*it3)->z();
				counterPts++;
			}
		}

		xCenterReg = xCenterReg/counterPts;
		yCenterReg = yCenterReg/counterPts;
		zCenterReg = zCenterReg/counterPts;

//		std::cout<<"debut boucle for "<<counterNbDone<<std::endl;
		for (std::list<GVertex*>::iterator itv = vlist.begin();itv != vlist.end();itv++){
			//duplication Gvertex
//			std::cout<<"point 1 "<<counterNbDone<<std::endl;
			GVertex* vTmp = (*itv);
//			std::cout<<"point 2 "<<counterNbDone<<std::endl;
			double ponderatedX = 0.99999999999 * vTmp->x() + 0.00000000001 * xCenterReg;
			double ponderatedY = 0.99999999999 * vTmp->y() + 0.00000000001 * yCenterReg;
			double ponderatedZ = 0.99999999999 * vTmp->z() + 0.00000000001 * zCenterReg;
//			double ponderatedX = 1.0 * vTmp->x() + 0.0 * xCenterReg;
//			double ponderatedY = 1.0 * vTmp->y() + 0.0 * yCenterReg;
//			double ponderatedZ = 1.0 * vTmp->z() + 0.0 * zCenterReg;
			//GVertex* newv = new gmshVertex(m,vTmp->prescribedMeshSizeAtVertex());
			GVertex* newv = m->addVertex(ponderatedX,ponderatedY,ponderatedZ,vTmp->prescribedMeshSizeAtVertex());
//			std::cout<<"point 3 "<<counterNbDone<<std::endl;
			GVertexAssociation[vTmp] = newv;
			//creation des Gedge correspondantes
//			std::cout<<"point 4 "<<counterNbDone<<std::endl;
//			std::cout<<"test du nouveau point: "<<newv->x()<<" et "<<newv->y()<<" et "<<newv->z()<<std::endl;
			//GEdge* newE = new GEdge(m,tagEdges,vTmp,newv);
			//tagEdges++;
			//m->add(newE);
			GEdge* newE = m->addLine(vTmp,newv);
//			std::cout<<"point 5 "<<counterNbDone<<std::endl;
			SurroudingEdges[vTmp] = newE;
			//maintenant traitement mesh
//			std::cout<<"point 6 "<<counterNbDone<<std::endl;
			MVertex *vMesh = vTmp->mesh_vertices[0];
//			std::cout<<"point 7 "<<counterNbDone<<std::endl;
			MVertex *newMv = new MVertex(vMesh->x(), vMesh->y(), vMesh->z(), (GEntity*)newv);
//			std::cout<<"point 8 "<<counterNbDone<<std::endl;
			VertexAssociation[vMesh] = newMv;
//			std::cout<<"point 9 "<<counterNbDone<<std::endl;
			newv->addMeshVertex(newMv);
			if (newMv->getNum() > 100000){
				std::cout<<"on a un getnum de "<<newMv->getNum()<<std::endl;
				while (1){

				}
			}
		}
//		std::cout<<"apres points "<<counterNbDone<<std::endl;
		std::list<GEdge*> elist = fTmp->edges();
		std::vector<GEdge*> newEdgesVector;
		std::vector<GFace*> SurroundingsFaces;
		for (std::list<GEdge*>::iterator ite = elist.begin();ite != elist.end();ite++){
			//duplication Gedge
			GEdge* eTmp = (*ite);
			GEdge* newE = m->addLine(GVertexAssociation[eTmp->getEndVertex()],GVertexAssociation[eTmp->getBeginVertex()]);
			GEdgeAssociation[eTmp] = newE;
			newEdgesVector.push_back(newE);
			//creation des GFace correspondantes
			GEdge* firstE = SurroudingEdges.find(eTmp->getEndVertex())->second;
			GEdge* lastE = SurroudingEdges.find(eTmp->getBeginVertex())->second;
			std::vector<GEdge*> VecEdgesTmp;
			VecEdgesTmp.push_back(eTmp);
			VecEdgesTmp.push_back(firstE);
			VecEdgesTmp.push_back(newE);
			VecEdgesTmp.push_back(lastE);
			std::vector<std::vector<GEdge*> > VecOfVecTmp;
			VecOfVecTmp.push_back(VecEdgesTmp);
			GFace* newFaceTmp = m->addPlanarFace(VecOfVecTmp);
			SurroundingsFaces.push_back(newFaceTmp);
			//maintenant traitement mesh
			for (unsigned int i = 0; i < eTmp->mesh_vertices.size();i++){
				MVertex *vMesh = eTmp->mesh_vertices[i];
				MVertex *newMv = new MVertex(vMesh->x(), vMesh->y(), vMesh->z(), (GEntity*)newE);
				VertexAssociation[vMesh] = newMv;
				newE->addMeshVertex(newMv);
			}
			for (unsigned int i = 0; i < eTmp->getNumMeshElements();i++){
				MElement* elem = eTmp->getMeshElement(i);
				MVertex *firstETmp = VertexAssociation.find(elem->getVertex(0))->second;
				MVertex *lastETmp = VertexAssociation.find(elem->getVertex(1))->second;
				MLine *newLine = new MLine(firstETmp,lastETmp);
				newE->addLine(newLine);
			}
		}
//		std::cout<<"apres lignes "<<counterNbDone<<std::endl;
		std::vector<std::vector<GEdge*> > VecOfVec;
		VecOfVec.push_back(newEdgesVector);
		//creation de la nouvelle face
		GFace* GFaceAssociation = m->addPlanarFace(VecOfVec);
		//maintenant traitement mesh
		for (unsigned int i = 0; i < fTmp->mesh_vertices.size();i++){
			MVertex *vMesh = fTmp->mesh_vertices[i];
			MVertex *newMv = new MVertex(vMesh->x(), vMesh->y(), vMesh->z(), (GEntity*)GFaceAssociation);
			VertexAssociation[vMesh] = newMv;
			GFaceAssociation->addMeshVertex(newMv);
		}
		for (unsigned int i = 0; i < fTmp->getNumMeshElements();i++){
			MElement* elem = fTmp->getMeshElement(i);
			MVertex *firstE = VertexAssociation.find(elem->getVertex(0))->second;
			MVertex *secondE = VertexAssociation.find(elem->getVertex(1))->second;
			MVertex *thirdE = VertexAssociation.find(elem->getVertex(2))->second;
			MTriangle *newTri = new MTriangle(firstE,secondE,thirdE);
			GFaceAssociation->addTriangle(newTri);
		}
//		std::cout<<"apres faces "<<counterNbDone<<std::endl;
		std::vector<GFace*> VectorFaces;
		std::list<GFace*> listFaces;
		VectorFaces.push_back(fTmp);
		listFaces.push_back(fTmp);
		for (unsigned int i = 0;i < SurroundingsFaces.size();i++){
			VectorFaces.push_back(SurroundingsFaces[i]);
			listFaces.push_back(SurroundingsFaces[i]);
		}
		VectorFaces.push_back(GFaceAssociation);
		listFaces.push_back(GFaceAssociation);
		std::vector<std::vector<GFace*> > VecOfVecGFace;
		VecOfVecGFace.push_back(VectorFaces);
//		std::cout<<"creation de la nouvelle region "<<counterNbDone<<std::endl;
		//creation de la nouvelle region

		GRegion* createdRegion = new GRegion(m,counterNbDone);
		createdRegion->set(listFaces);
		createdRegion->addPhysicalEntity(PhysicalInterface);
		m->add(createdRegion);


		std::list<GFace*> RegFaces = rTmp->faces();
		std::list<GFace*>::iterator it = std::find(RegFaces.begin(), RegFaces.end(), fTmp);
		std::cout<<(*it)->tag()<<std::endl;
		if(it != RegFaces.end()) RegFaces.erase(it);
		RegFaces.push_back(GFaceAssociation);
		rTmp->set(RegFaces);
		std::list<GFace*> NewFacesReg;
		NewFacesReg = rTmp->faces();
		for (std::list<GFace*>::iterator it2=NewFacesReg.begin();it2!=NewFacesReg.end();it2++){
			GFace* fTemp = (*it2);
			for (std::list<GEdge*>::iterator ite = elist.begin();ite != elist.end();ite++){
				GEdge* eTmp = (*ite);
				GEdge* newE = GEdgeAssociation[eTmp];
				fTemp->replaceEdge(eTmp,newE);
			}
		}


		for (unsigned int i = 0; i < fTmp->getNumMeshElements();i++){
			MElement* elem = fTmp->getMeshElement(i);
//			std::cout<<"on a un element avec un nb de vertex de "<<elem->getNumVertices()<<std::endl;
			MVertex *firstE = VertexAssociation.find(elem->getVertex(0))->second;
			MVertex *secondE = VertexAssociation.find(elem->getVertex(1))->second;
			MVertex *thirdE = VertexAssociation.find(elem->getVertex(2))->second;
//			std::cout<<"creation de prisme "<<counterNbDone<<std::endl;
			MPrism *newPri = new MPrism(elem->getVertex(0),elem->getVertex(1),elem->getVertex(2),firstE,secondE,thirdE);
//			std::cout<<"addition de prisme "<<counterNbDone<<std::endl;

			createdRegion->addPrism(newPri);
//			std::cout<<"fin de for"<<std::endl;
		}
		for (unsigned int i = 0; i < rTmp->getNumMeshElements();i++){
			MElement* elem = rTmp->getMeshElement(i);
			for (int j = 0;j < elem->getNumVertices();j++){
				MVertex* vert = elem->getVertex(j);
				std::map<MVertex*,MVertex* >::iterator itMap = VertexAssociation.find(vert);
				if (itMap != VertexAssociation.end()){
					elem->setVertex(j,itMap->second);
				}
			}
		}


		int countTmp = 0;
		//maitenant refonte points dans faces
		for (std::list<GFace*>::iterator itTmp = NewFacesReg.begin();itTmp != NewFacesReg.end();itTmp++){
			GFace* GFaceTmp = (*itTmp);
			countTmp++;
			for (unsigned int i = 0; i < GFaceTmp->getNumMeshElements();i++){
				MElement* elem = GFaceTmp->getMeshElement(i);
				for (int j = 0;j < elem->getNumVertices();j++){
					MVertex* vert = elem->getVertex(j);
					std::map<MVertex*,MVertex* >::iterator itMap = VertexAssociation.find(vert);
					if (itMap != VertexAssociation.end()){
						elem->setVertex(j,itMap->second);
						std::vector<MVertex*> FaceVerti = GFaceTmp->mesh_vertices;
						std::vector<MVertex*>::iterator itHere = std::find(FaceVerti.begin(), FaceVerti.end(), vert);
						if(itHere != FaceVerti.end()) {
							FaceVerti.erase(itHere);
							FaceVerti.push_back(itMap->second);
							GFaceTmp->mesh_vertices = FaceVerti;
						}
					}
				}
			}
		}


	}

/*
	//now we put all info into a file
	//to being with we put all boundary vertices into a unique set
	std::vector<MEdge*> ListBoundaryVectors;
	for (GModel::fiter itf= m->firstFace();itf != m->lastFace();itf++){
		GFace* fTmp = (*itf);
		if (fTmp->regions().size() == 1){
			//for each node we are going to test the displacement
			std::list<GEdge*> elist = fTmp->edges();
			for (std::list<GEdge*>::iterator ite = elist.begin();ite != elist.end();ite++){

			}
		}
	}
	std::ofstream file2("PeriodicMatches.txt");
	file2 << "PeriodicalNodes\n\n";
	file2 << "Displacement 1.0 0.0 0.0\n\n";
	file2 << "Displacement 0.0 1.0 0.0\n\n";
	file2 << "Displacement 0.0 0.0 1.0\n\n";
*/







/*
	std::map<std::pair<MVertex*,GRegion*>,MVertex* > VertexAssociation;
	for (GModel::viter itv = m->firstVertex();itv != m->lastVertex();itv++){
//		std::cout<<"entering first for"<<std::endl;
		GVertex* vTmp = (*itv);
		std::list<GRegion*> r = vTmp->regions();
		std::cout<<"size of mesh_vertices: "<<vTmp->mesh_vertices.size()<<std::endl;
		MVertex *vMesh = vTmp->mesh_vertices[0];
		std::cout<<"size of r: "<<r.size()<<std::endl;
		// for all regions, create association
//		for (int i = 0; i < vTmp->getNumMeshVertices();i++){
//			std::cout<<"entering second for"<<std::endl;
//			MVertex* vMesh = vTmp->getMeshVertex(i);
//			for (GModel::riter itr = vTmp->regions().begin();itr != vTmp->regions().end();itr++){
		for (std::list<GRegion*>::iterator itr = r.begin();itr != r.end();itr++){
			std::cout<<"entering third for"<<std::endl;
			GRegion* vReg = (*itr);
			//				std::cout<<"we have the region "<<vReg->
			MVertex *newv = new MVertex(vMesh->x(), vMesh->y(), vMesh->z(), (GEntity*)vReg);
			vReg->mesh_vertices.push_back(newv);
			VertexAssociation[std::make_pair(vMesh,vReg)] = newv;
			std::cout<<"end third for"<<std::endl;
		}
//			std::cout<<"end second for"<<std::endl;
//		}
//		std::cout<<"end first for"<<std::endl;
	}
	std::cout<<"Phase 1 done for DuplicateBoundaries"<<std::endl;
	for (GModel::eiter ite = m->firstEdge();ite != m->lastEdge();ite++){
		GEdge* eTmp = (*ite);
		for (int i = 0; i < eTmp->mesh_vertices.size();i++){
			MVertex* vMesh = eTmp->mesh_vertices[i];
			std::list<GRegion*> r = eTmp->regions();
			for (std::list<GRegion*>::iterator itr = r.begin();itr != r.end();itr++){
				GRegion* vReg = (*itr);
				MVertex *newv = new MVertex(vMesh->x(), vMesh->y(), vMesh->z(), (GEntity*)vReg);
				vReg->mesh_vertices.push_back(newv);
				VertexAssociation[std::make_pair(vMesh,vReg)] = newv;
			}
		}
	}
	std::cout<<"Phase 2 done for DuplicateBoundaries"<<std::endl;
	for (GModel::fiter itf = m->firstFace();itf != m->lastFace();itf++){
		GFace* fTmp = (*itf);
		for (int i = 0; i < fTmp->mesh_vertices.size();i++){
			MVertex* vMesh = fTmp->mesh_vertices[i];
			std::list<GRegion*> r = fTmp->regions();
			for (std::list<GRegion*>::iterator itr = r.begin();itr != r.end();itr++){
				GRegion* vReg = (*itr);
				MVertex *newv = new MVertex(vMesh->x(), vMesh->y(), vMesh->z(), (GEntity*)vReg);
				vReg->mesh_vertices.push_back(newv);
				VertexAssociation[std::make_pair(vMesh,vReg)] = newv;
			}
		}
	}
	std::cout<<"Phase 3 done for DuplicateBoundaries"<<std::endl;
	for (GModel::riter itr = m->firstRegion();itr != m->lastRegion();itr++){
		GRegion* rTmp = (*itr);
		for (int i = 0; i < rTmp->getNumMeshElements();i++){
			MElement* elem = rTmp->getMeshElement(i);
			for (int j = 0;j < elem->getNumVertices();j++){
				MVertex* vert = elem->getVertex(j);
				std::map<std::pair<MVertex*,GRegion*>,MVertex* >::iterator itMap = VertexAssociation.find(std::make_pair(vert,rTmp));
				if (itMap != VertexAssociation.end()){
					elem->setVertex(j,itMap->second);
				}
			}
		}
	}
	*/
//	std::cout<<"number for seeds: "<<PhysicalSeeds<<" and for interface: "<<PhysicalInterface<<std::endl;
	std::cout<<"End of DuplicateBoundaries"<<std::endl;
	return view;
}

PView *GMSH_DuplicateBoundariesPlugin::executeFourth(PView *view)
{
	std::cout<<"starting DuplicateBoundaries"<<std::endl;
	GModel *m = GModel::current();
	m->setFactory("geo");
	std::set<GFace*> ToDuplicateList;
	ToDuplicateList.clear();
	std::set<GFace*> ToDuplicateListBoundary;
	ToDuplicateListBoundary.clear();
	std::vector<GFace*> facesBound;
	facesBound.clear();
	std::map<GFace*,SPoint3> centers;
	std::vector<std::pair<GFace*,GFace*> > pairs;
	std::vector<std::pair<GFace*,GFace*> > newPairs;
	int PhysicalInterface = m->setPhysicalName("Interface",3);
	for (GModel::fiter itf= m->firstFace();itf != m->lastFace();itf++){
		GFace* fTmp = (*itf);
		if (fTmp->numRegions() == 2){
			ToDuplicateList.insert(fTmp);
		}
		else{
			ToDuplicateListBoundary.insert(fTmp);
			facesBound.push_back(fTmp);
		}
	}








	for(unsigned int i=0;i<facesBound.size();i++){
		double x = 0.0;
		double y = 0.0;
		double z = 0.0;

		std::list<GVertex*> vertices;

		vertices = facesBound[i]->vertices();

		for(std::list<GVertex*>::iterator it2=vertices.begin();it2!=vertices.end();it2++){
			x = x + (*it2)->x();
			y = y + (*it2)->y();
			z = z + (*it2)->z();
		}

		x = x/vertices.size();
		y = y/vertices.size();
		z = z/vertices.size();

		centers.insert(std::pair<GFace*,SPoint3>(facesBound[i],SPoint3(x,y,z)));
	}

	for(unsigned int i=0;i<facesBound.size();i++){
		for(unsigned int j=0;j<facesBound.size();j++){
			std::map<GFace*,SPoint3>::iterator it3 = centers.find(facesBound[i]);
			std::map<GFace*,SPoint3>::iterator it4 = centers.find(facesBound[j]);

			SPoint3 p1 = it3->second;
			SPoint3 p2 = it4->second;


			//				categories.push_back(val);

			//				print_segment(p1,p2,file);

			if (abs((p2.x()-p1.x()-1.0))<0.0001){
				if (abs((p2.y()-p1.y()))<0.0001){
					if (abs((p2.z()-p1.z()))<0.0001){
						pairs.push_back(std::pair<GFace*,GFace*>(facesBound[i],facesBound[j]));
						ToDuplicateListBoundary.insert(facesBound[i]);
//						std::cout<<"case 1"<<std::endl;
//						std::cout<<"on a p1.x() = "<<p1.x()<<" et p2.x() = "<<p2.x()<<" et abs((p2.x()-p1.x()-1.0)) = "<<abs((p2.x()-p1.x()-1.0))<<std::endl;
//						std::cout<<"on a abs(0.5) = "<<abs(0.5)<<" et abs(-0.5) = "<<abs(-0.5)<<" et abs(1.5) = "<<abs(1.5)<<" et abs(-1.5) = "<<abs(-1.5)<<std::endl;
//						std::cout<<"on a mis dans la liste: x "<<p1.x()<<" y "<<p1.y()<<" z "<<p1.z()<<std::endl;
//						std::cout<<"on avait pour second: x "<<p2.x()<<" y "<<p2.y()<<" z "<<p2.z()<<std::endl;
					}else if(abs((p2.z()-p1.z()-1.0))<0.0001){
						pairs.push_back(std::pair<GFace*,GFace*>(facesBound[i],facesBound[j]));
						ToDuplicateListBoundary.insert(facesBound[i]);
//						std::cout<<"case 2"<<std::endl;
//						std::cout<<"on a mis dans la liste: x "<<p1.x()<<" y "<<p1.y()<<" z "<<p1.z()<<std::endl;
//						std::cout<<"on avait pour second: x "<<p2.x()<<" y "<<p2.y()<<" z "<<p2.z()<<std::endl;
					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
						pairs.push_back(std::pair<GFace*,GFace*>(facesBound[i],facesBound[j]));
						ToDuplicateListBoundary.insert(facesBound[i]);
//						std::cout<<"case 3"<<std::endl;
//						std::cout<<"on a mis dans la liste: x "<<p1.x()<<" y "<<p1.y()<<" z "<<p1.z()<<std::endl;
//						std::cout<<"on avait pour second: x "<<p2.x()<<" y "<<p2.y()<<" z "<<p2.z()<<std::endl;
					}
				}else if (abs((p2.y()-p1.y()-1.0))<0.0001){
					if (abs((p2.z()-p1.z()))<0.0001){
						pairs.push_back(std::pair<GFace*,GFace*>(facesBound[i],facesBound[j]));
						ToDuplicateListBoundary.insert(facesBound[i]);
//						std::cout<<"case 4"<<std::endl;
//						std::cout<<"on a mis dans la liste: x "<<p1.x()<<" y "<<p1.y()<<" z "<<p1.z()<<std::endl;
//						std::cout<<"on avait pour second: x "<<p2.x()<<" y "<<p2.y()<<" z "<<p2.z()<<std::endl;
					}else if (abs((p2.z()-p1.z()-1.0))<0.0001){
						pairs.push_back(std::pair<GFace*,GFace*>(facesBound[i],facesBound[j]));
						ToDuplicateListBoundary.insert(facesBound[i]);
//						std::cout<<"case 5"<<std::endl;
//						std::cout<<"on a mis dans la liste: x "<<p1.x()<<" y "<<p1.y()<<" z "<<p1.z()<<std::endl;
//						std::cout<<"on avait pour second: x "<<p2.x()<<" y "<<p2.y()<<" z "<<p2.z()<<std::endl;
					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
						pairs.push_back(std::pair<GFace*,GFace*>(facesBound[i],facesBound[j]));
						ToDuplicateListBoundary.insert(facesBound[i]);
//						std::cout<<"case 6"<<std::endl;
//						std::cout<<"on a mis dans la liste: x "<<p1.x()<<" y "<<p1.y()<<" z "<<p1.z()<<std::endl;
//						std::cout<<"on avait pour second: x "<<p2.x()<<" y "<<p2.y()<<" z "<<p2.z()<<std::endl;
					}
				}else if (abs((p1.y()-p2.y()-1.0))<0.0001){
					if (abs((p2.z()-p1.z()))<0.0001){
						pairs.push_back(std::pair<GFace*,GFace*>(facesBound[i],facesBound[j]));
						ToDuplicateListBoundary.insert(facesBound[i]);
//						std::cout<<"case 7"<<std::endl;
//						std::cout<<"on a mis dans la liste: x "<<p1.x()<<" y "<<p1.y()<<" z "<<p1.z()<<std::endl;
//						std::cout<<"on avait pour second: x "<<p2.x()<<" y "<<p2.y()<<" z "<<p2.z()<<std::endl;
					}else if (abs((p2.z()-p1.z()-1.0))<0.0001){
						pairs.push_back(std::pair<GFace*,GFace*>(facesBound[i],facesBound[j]));
						ToDuplicateListBoundary.insert(facesBound[i]);
//						std::cout<<"case 8"<<std::endl;
//						std::cout<<"on a mis dans la liste: x "<<p1.x()<<" y "<<p1.y()<<" z "<<p1.z()<<std::endl;
//						std::cout<<"on avait pour second: x "<<p2.x()<<" y "<<p2.y()<<" z "<<p2.z()<<std::endl;
					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
						pairs.push_back(std::pair<GFace*,GFace*>(facesBound[i],facesBound[j]));
						ToDuplicateListBoundary.insert(facesBound[i]);
//						std::cout<<"case 9"<<std::endl;
//						std::cout<<"on a mis dans la liste: x "<<p1.x()<<" y "<<p1.y()<<" z "<<p1.z()<<std::endl;
//						std::cout<<"on avait pour second: x "<<p2.x()<<" y "<<p2.y()<<" z "<<p2.z()<<std::endl;
					}
				}
			}else if (abs((p1.x()-p2.x()-1.0))<0.0001){
				if (abs((p2.y()-p1.y()))<0.0001){
					if (abs((p2.z()-p1.z()))<0.0001){
						//NOTHING
					}else if(abs((p2.z()-p1.z()-1.0))<0.0001){
						//NOTHING
					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
						//NOTHING
					}
				}else if (abs((p2.y()-p1.y()-1.0))<0.0001){
					if (abs((p2.z()-p1.z()))<0.0001){
						//NOTHING
					}else if (abs((p2.z()-p1.z()-1.0))<0.0001){
						//NOTHING
					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
						//NOTHING
					}
				}else if (abs((p1.y()-p2.y()-1.0))<0.0001){
					if (abs((p2.z()-p1.z()))<0.0001){
						//NOTHING
					}else if (abs((p2.z()-p1.z()-1.0))<0.0001){
						//NOTHING
					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
						//NOTHING
					}
				}
			}else if (abs((p1.x()-p2.x()))<0.0001){
				if (abs((p2.y()-p1.y()-1.0))<0.0001){
					if (abs((p2.z()-p1.z()))<0.0001){
						pairs.push_back(std::pair<GFace*,GFace*>(facesBound[i],facesBound[j]));
						ToDuplicateListBoundary.insert(facesBound[i]);
//						std::cout<<"case 10"<<std::endl;
//						std::cout<<"on a mis dans la liste: x "<<p1.x()<<" y "<<p1.y()<<" z "<<p1.z()<<std::endl;
//						std::cout<<"on avait pour second: x "<<p2.x()<<" y "<<p2.y()<<" z "<<p2.z()<<std::endl;
					}else if (abs((p2.z()-p1.z()-1.0))<0.0001){
						pairs.push_back(std::pair<GFace*,GFace*>(facesBound[i],facesBound[j]));
						ToDuplicateListBoundary.insert(facesBound[i]);
//						std::cout<<"case 11"<<std::endl;
//						std::cout<<"on a mis dans la liste: x "<<p1.x()<<" y "<<p1.y()<<" z "<<p1.z()<<std::endl;
//						std::cout<<"on avait pour second: x "<<p2.x()<<" y "<<p2.y()<<" z "<<p2.z()<<std::endl;
					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
						pairs.push_back(std::pair<GFace*,GFace*>(facesBound[i],facesBound[j]));
						ToDuplicateListBoundary.insert(facesBound[i]);
//						std::cout<<"case 12"<<std::endl;
//						std::cout<<"on a mis dans la liste: x "<<p1.x()<<" y "<<p1.y()<<" z "<<p1.z()<<std::endl;
//						std::cout<<"on avait pour second: x "<<p2.x()<<" y "<<p2.y()<<" z "<<p2.z()<<std::endl;
					}
				}else if (abs((p1.y()-p2.y()-1.0))<0.0001){
					if (abs((p2.z()-p1.z()))<0.0001){
						//NOTHING
					}else if (abs((p2.z()-p1.z()-1.0))<0.0001){
						//NOTHING
					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
						//NOTHING
					}
				}else if (abs((p1.y()-p2.y()))<0.0001){
					if (abs((p2.z()-p1.z()-1.0))<0.0001){
						pairs.push_back(std::pair<GFace*,GFace*>(facesBound[i],facesBound[j]));
						ToDuplicateListBoundary.insert(facesBound[i]);
//						std::cout<<"case 13"<<std::endl;
//						std::cout<<"on a mis dans la liste: x "<<p1.x()<<" y "<<p1.y()<<" z "<<p1.z()<<std::endl;
//						std::cout<<"on avait pour second: x "<<p2.x()<<" y "<<p2.y()<<" z "<<p2.z()<<std::endl;
					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
						//NOTHING
					}
				}
			}
		}
	}
	std::cout<<"on a une taille de facesBound = "<<facesBound.size()<<" et ToDuplicateListBoundary = "<<ToDuplicateListBoundary.size()<<std::endl;










	std::map<std::pair<MVertex*,GRegion*>,MVertex* > VertexGlobalAssociation;
	std::map<std::pair<GVertex*,GRegion*>,GVertex* > GVertexGlobalAssociation;
	std::map<std::pair<GEdge*,GRegion*>,GEdge* > GEdgeGlobalAssociation;
	std::map<std::pair<GFace*,GRegion*>,GFace* > GFaceGlobalAssociation;
//	for (GModel::viter itv= m->firstVertex();itv != m->lastVertex();itv++){
//		GVertex* vTmp = (*itv);
//		std::vector<GVertex* > vecTmp;
//		vecTmp.clear();
//		GVertexGlobalAssociation[vTmp] = vecTmp;
//		for (int i = 0; i < vTmp->mesh_vertices.size();i++){
//			MVertex *vMesh = vTmp->mesh_vertices[i];
//			std::vector<MVertex* > vecTmpBis;
//			vecTmpBis.clear();
//			VertexGlobalAssociation[vMesh] = vecTmpBis;
//		}
//	}
//	for (GModel::eiter ite= m->firstEdge();ite != m->lastEdge();ite++){
//		GEdge* eTmp = (*ite);
//		std::vector<GEdge* > vecTmp;
//		vecTmp.clear();
//		GEdgeGlobalAssociation[eTmp] = vecTmp;
//		for (int i = 0; i < eTmp->mesh_vertices.size();i++){
//			MVertex *vMesh = eTmp->mesh_vertices[i];
//			std::vector<MVertex* > vecTmpBis;
//			vecTmpBis.clear();
//			VertexGlobalAssociation[vMesh] = vecTmpBis;
//		}
//	}
//	for (GModel::fiter itf= m->firstFace();itf != m->lastFace();itf++){
//		GFace* fTmp = (*itf);
//		for (int i = 0; i < fTmp->mesh_vertices.size();i++){
//			MVertex *vMesh = fTmp->mesh_vertices[i];
//			std::vector<MVertex* > vecTmpBis;
//			vecTmpBis.clear();
//			VertexGlobalAssociation[vMesh] = vecTmpBis;
//		}
//	}
//	for (GModel::riter itr= m->firstRegion();itr != m->lastRegion();itr++){
//		GRegion* rTmp = (*itr);
//		for (int i = 0; i < rTmp->mesh_vertices.size();i++){
//			MVertex *vMesh = rTmp->mesh_vertices[i];
//			std::vector<MVertex* > vecTmpBis;
//			vecTmpBis.clear();
//			VertexGlobalAssociation[vMesh] = vecTmpBis;
//		}
//	}
	std::cout<<"entree dans regions first pass"<<std::endl;
	for (GModel::riter itr= m->firstRegion();itr != m->lastRegion();itr++){
		GRegion* rTmp = (*itr);
		std::list<GFace*> RegFaces = rTmp->faces();
		std::map<MVertex*,MVertex* > VertexAssociation;
		std::map<GVertex*,GVertex* > GVertexAssociation;
		std::map<GEdge*,GEdge* > GEdgeAssociation;
		//int counterNbDone = 10000;
		double xCenterReg = 0.0;
		double yCenterReg = 0.0;
		double zCenterReg = 0.0;
		int counterPts = 0;
		for(std::list<GFace*>::iterator it2=RegFaces.begin();it2!=RegFaces.end();it2++){
			GFace* fTemp = (*it2);
			std::list<GVertex*> verticesFace = fTemp->vertices();
			for (std::list<GVertex*>::iterator it3=verticesFace.begin();it3!=verticesFace.end();it3++){
				xCenterReg = xCenterReg + (*it3)->x();
				yCenterReg = yCenterReg + (*it3)->y();
				zCenterReg = zCenterReg + (*it3)->z();
				counterPts++;
			}
		}
		xCenterReg = xCenterReg/counterPts;
		yCenterReg = yCenterReg/counterPts;
		zCenterReg = zCenterReg/counterPts;
		//duplication noeud et aretes au niveau de la region directement
		std::list<GVertex*> vlist;


		std::cout<<"wut 1"<<std::endl;
		std::list<GFace*> listFacesTmp = rTmp->faces();
		for (std::list<GFace*>::iterator itTp = listFacesTmp.begin();itTp != listFacesTmp.end();itTp++){
			std::cout<<"wut 2"<<std::endl;
			std::list<GVertex*> vlist2;
			std::cout<<"wut 3"<<std::endl;
			vlist2 = (*itTp)->vertices();
			std::cout<<"wut 4"<<std::endl;
			for (std::list<GVertex*>::iterator itTp2 = vlist2.begin();itTp2 != vlist2.end();itTp2++){
				std::cout<<"wut 5"<<std::endl;
				if(std::find(vlist.begin(), vlist.end(), *itTp2) == vlist.end())
					vlist.push_back(*itTp2);
				std::cout<<"wut 6"<<std::endl;
			}
			std::cout<<"wut 7"<<std::endl;
		}
		std::cout<<"wut 8"<<std::endl;


		std::cout<<"on a une taille vlist de "<<vlist.size()<<std::endl;
		std::cout<<"init done entering vertices"<<std::endl;
		for (std::list<GVertex*>::iterator itv = vlist.begin();itv != vlist.end();itv++){
			//duplication Gvertex
			GVertex* vTmp = (*itv);
			double ponderatedX = 0.99999999999 * vTmp->x() + 0.00000000001 * xCenterReg;
			double ponderatedY = 0.99999999999 * vTmp->y() + 0.00000000001 * yCenterReg;
			double ponderatedZ = 0.99999999999 * vTmp->z() + 0.00000000001 * zCenterReg;
			GVertex* newv = m->addVertex(ponderatedX,ponderatedY,ponderatedZ,vTmp->prescribedMeshSizeAtVertex());
			std::cout<<"inserted correspondance between : "<<vTmp->tag()<<" and : "<<newv->tag()<<std::endl;
			GVertexAssociation[vTmp] = newv;
			GVertexGlobalAssociation[std::make_pair(vTmp,rTmp)] = newv;
			//creation des Gedge correspondantes
//			GEdge* newE = m->addLine(vTmp,newv);
//			SurroudingEdges[vTmp] = newE;
			//maintenant traitement mesh
			MVertex *vMesh = vTmp->mesh_vertices[0];
			MVertex *newMv = new MVertex(vMesh->x(), vMesh->y(), vMesh->z(), (GEntity*)newv);
			VertexAssociation[vMesh] = newMv;
			VertexGlobalAssociation[std::make_pair(vMesh,rTmp)] = newMv;
			newv->addMeshVertex(newMv);
		}
		//maintenant on soccupe de duppliquer les edges de la region
		std::list<GEdge*> elist = rTmp->edges();
		std::cout<<"on a une taille elist de "<<elist.size()<<std::endl;
		std::cout<<"vertices done entering edges"<<std::endl;

		std::vector<GFace*> SurroundingsFaces;
		for (std::list<GEdge*>::iterator ite = elist.begin();ite != elist.end();ite++){
			//duplication Gedge
			GEdge* eTmp = (*ite);
			std::cout<<"before addline"<<std::endl;
			std::cout<<"begin ID : "<<eTmp->getBeginVertex()->tag()<<" and end ID : "<<eTmp->getEndVertex()->tag()<<std::endl;
			std::cout<<"corresponding begin ID : "<<GVertexAssociation[eTmp->getBeginVertex()]->tag()<<" and end ID : "<<GVertexAssociation[eTmp->getEndVertex()]->tag()<<std::endl;
			GEdge* newE = m->addLine(GVertexAssociation[eTmp->getEndVertex()],GVertexAssociation[eTmp->getBeginVertex()]);
			std::cout<<"after addline"<<std::endl;
			GEdgeAssociation[eTmp] = newE;
			GEdgeGlobalAssociation[std::make_pair(eTmp,rTmp)] = newE;
			//creation des GFace correspondantes
//			GEdge* firstE = SurroudingEdges.find(eTmp->getEndVertex())->second;
//			GEdge* lastE = SurroudingEdges.find(eTmp->getBeginVertex())->second;
//			std::vector<GEdge*> VecEdgesTmp;
//			VecEdgesTmp.push_back(eTmp);
//			VecEdgesTmp.push_back(firstE);
//			VecEdgesTmp.push_back(newE);
//			VecEdgesTmp.push_back(lastE);
//			std::vector<std::vector<GEdge*> > VecOfVecTmp;
//			VecOfVecTmp.push_back(VecEdgesTmp);
//			GFace* newFaceTmp = m->addPlanarFace(VecOfVecTmp);
//			SurroundingsFaces.push_back(newFaceTmp);
			//maintenant traitement mesh
			for (unsigned int i = 0; i < eTmp->mesh_vertices.size();i++){
				MVertex *vMesh = eTmp->mesh_vertices[i];
				MVertex *newMv = new MVertex(vMesh->x(), vMesh->y(), vMesh->z(), (GEntity*)newE);
				VertexAssociation[vMesh] = newMv;
				VertexGlobalAssociation[std::make_pair(vMesh,rTmp)] = newMv;
				newE->addMeshVertex(newMv);
			}
			std::cout<<"after newvertices"<<std::endl;
			for (unsigned int i = 0; i < eTmp->getNumMeshElements();i++){
				MElement* elem = eTmp->getMeshElement(i);
				MVertex *firstETmp = VertexAssociation.find(elem->getVertex(0))->second;
				MVertex *lastETmp = VertexAssociation.find(elem->getVertex(1))->second;
				MLine *newLine = new MLine(firstETmp,lastETmp);
				newE->addLine(newLine);
			}
			std::cout<<"after newMlines"<<std::endl;
		}
		std::cout<<"edges done entering faces"<<std::endl;
		for (std::list<GFace*>::iterator itf = RegFaces.begin();itf != RegFaces.end();itf++){
			GFace* fTmp = (*itf);
			std::vector<GEdge*> newEdgesVector;
			std::list<GEdge*> elistFace = fTmp->edges();
			for (std::list<GEdge*>::iterator ite = elistFace.begin();ite != elistFace.end();ite++){
				GEdge* eTmp = (*ite);
				GEdge* eToFind = GEdgeAssociation[eTmp];
				newEdgesVector.push_back(eToFind);
			}
			std::vector<std::vector<GEdge*> > VecOfVec;
			VecOfVec.push_back(newEdgesVector);
			//creation de la nouvelle face
			GFace* GFaceAssociation = m->addPlanarFace(VecOfVec);
			//maintenant traitement mesh
			for (unsigned int i = 0; i < fTmp->mesh_vertices.size();i++){
				MVertex *vMesh = fTmp->mesh_vertices[i];
				MVertex *newMv = new MVertex(vMesh->x(), vMesh->y(), vMesh->z(), (GEntity*)GFaceAssociation);
				VertexAssociation[vMesh] = newMv;
				VertexGlobalAssociation[std::make_pair(vMesh,rTmp)] = newMv;
				GFaceAssociation->addMeshVertex(newMv);
			}
			for (unsigned int i = 0; i < fTmp->getNumMeshElements();i++){
				MElement* elem = fTmp->getMeshElement(i);
				MVertex *firstE = VertexAssociation.find(elem->getVertex(0))->second;
				MVertex *secondE = VertexAssociation.find(elem->getVertex(1))->second;
				MVertex *thirdE = VertexAssociation.find(elem->getVertex(2))->second;
				MTriangle *newTri = new MTriangle(firstE,secondE,thirdE);
				GFaceAssociation->addTriangle(newTri);
			}
			GFaceGlobalAssociation[std::make_pair(fTmp,rTmp)] = GFaceAssociation;
		}
		std::cout<<"faces done for regions"<<std::endl;
	}
	std::cout<<"Regions done first pass"<<std::endl;
	int counterNbDone = 10000;
	//maintenant on va traiter les faces initiales
	for (std::set<GFace*>::iterator itf = ToDuplicateList.begin();itf != ToDuplicateList.end();itf++){
		counterNbDone++;
		GFace* fTmp = (*itf);
		GRegion* reg1 = fTmp->getRegion(0);
		GRegion* reg2 = fTmp->getRegion(1);
		//pour commencer on cree des aretes entre les vertex
		std::list<GVertex*> vlist = fTmp->vertices();
		std::map<GVertex*,GEdge* > SurroudingEdges;
		for (std::list<GVertex*>::iterator itv = vlist.begin();itv != vlist.end();itv++){
			GVertex* vTmp = (*itv);
			GVertex* v1;
			GVertex* v2;
			std::map<std::pair<GVertex*,GRegion*>,GVertex* >::iterator itMap = GVertexGlobalAssociation.find(std::make_pair(vTmp,reg1));
			if (itMap != GVertexGlobalAssociation.end()){
				v1 = itMap->second;
			}
			itMap = GVertexGlobalAssociation.find(std::make_pair(vTmp,reg2));
			if (itMap != GVertexGlobalAssociation.end()){
				v2 = itMap->second;
			}
			GEdge* newE = m->addLine(v1,v2);
			SurroudingEdges[vTmp] = newE;
		}
		//ici tous les vertex sont traites
		//on va traiter les edges
		std::list<GEdge*> elist = fTmp->edges();
		std::vector<GEdge*> newEdgesVector;
		std::vector<GFace*> SurroundingsFaces;
		for (std::list<GEdge*>::iterator ite = elist.begin();ite != elist.end();ite++){
			//duplication Gedge
			GEdge* eTmp = (*ite);
			GEdge* e1;
			GEdge* e2;
			std::map<std::pair<GEdge*,GRegion*>,GEdge* >::iterator itMap = GEdgeGlobalAssociation.find(std::make_pair(eTmp,reg1));
			if (itMap != GEdgeGlobalAssociation.end()){
				e1 = itMap->second;
			}
			itMap = GEdgeGlobalAssociation.find(std::make_pair(eTmp,reg2));
			if (itMap != GEdgeGlobalAssociation.end()){
				e2 = itMap->second;
			}
			//creation des GFace correspondantes
			GEdge* firstE = SurroudingEdges.find(eTmp->getBeginVertex())->second;
			GEdge* lastE = SurroudingEdges.find(eTmp->getEndVertex())->second;
			if (firstE->getBeginVertex() != e1->getEndVertex()){
				firstE->reverse();
			}
			if (firstE->getBeginVertex() != e1->getEndVertex()){
				e1->reverse();
			}
			if (firstE->getBeginVertex() != e1->getEndVertex()){
				firstE->reverse();
			}
			if (e2->getBeginVertex() != firstE->getEndVertex()){
				e2->reverse();
			}
			if (lastE->getBeginVertex() != e2->getEndVertex()){
				lastE->reverse();
			}
			std::vector<GEdge*> VecEdgesTmp;
			VecEdgesTmp.push_back(e1);
			VecEdgesTmp.push_back(firstE);
			VecEdgesTmp.push_back(e2);
			VecEdgesTmp.push_back(lastE);
			std::vector<std::vector<GEdge*> > VecOfVecTmp;
			VecOfVecTmp.push_back(VecEdgesTmp);
			GFace* newFaceTmp = m->addPlanarFace(VecOfVecTmp);
			SurroundingsFaces.push_back(newFaceTmp);
		}
		std::vector<GFace*> VectorFaces;
		std::list<GFace*> listFaces;
		GFace* f1;
		GFace* f2;
		std::map<std::pair<GFace*,GRegion*>,GFace* >::iterator itMap = GFaceGlobalAssociation.find(std::make_pair(fTmp,reg1));
		if (itMap != GFaceGlobalAssociation.end()){
			f1 = itMap->second;
		}
		itMap = GFaceGlobalAssociation.find(std::make_pair(fTmp,reg2));
		if (itMap != GFaceGlobalAssociation.end()){
			f2 = itMap->second;
		}
		VectorFaces.push_back(f1);
		listFaces.push_back(f1);
		for (unsigned int i = 0;i < SurroundingsFaces.size();i++){
			VectorFaces.push_back(SurroundingsFaces[i]);
			listFaces.push_back(SurroundingsFaces[i]);
		}
		VectorFaces.push_back(f2);
		listFaces.push_back(f2);
		std::vector<std::vector<GFace*> > VecOfVecGFace;
		VecOfVecGFace.push_back(VectorFaces);
		//creation de la nouvelle region
		GRegion* createdRegion = new GRegion(m,counterNbDone);
		createdRegion->addPhysicalEntity(PhysicalInterface);
		createdRegion->set(listFaces);
		m->add(createdRegion);
		for (unsigned int i = 0; i < fTmp->getNumMeshElements();i++){
			MElement* elem = fTmp->getMeshElement(i);
			MVertex* v1;
			MVertex* v2;
			MVertex* v3;
			MVertex* v4;
			MVertex* v5;
			MVertex* v6;
			std::map<std::pair<MVertex*,GRegion*>,MVertex* >::iterator itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(0),reg1));
			if (itMap != VertexGlobalAssociation.end()){
				v1 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(1),reg1));
			if (itMap != VertexGlobalAssociation.end()){
				v2 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(2),reg1));
			if (itMap != VertexGlobalAssociation.end()){
				v3 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(0),reg2));
			if (itMap != VertexGlobalAssociation.end()){
				v4 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(1),reg2));
			if (itMap != VertexGlobalAssociation.end()){
				v5 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(2),reg2));
			if (itMap != VertexGlobalAssociation.end()){
				v6 = itMap->second;
			}
//			std::cout<<"creation de prisme "<<counterNbDone<<std::endl;
			MPrism *newPri = new MPrism(v1,v2,v3,v4,v5,v6);
//			std::cout<<"addition de prisme "<<counterNbDone<<std::endl;

			createdRegion->addPrism(newPri);
//			std::cout<<"fin de for"<<std::endl;
		}
		std::cout<<"apres region, refonte points "<<counterNbDone<<std::endl;
		for (unsigned int i = 0; i < reg1->getNumMeshElements();i++){
			MElement* elem = reg1->getMeshElement(i);
			for (int j = 0;j < elem->getNumVertices();j++){
				MVertex* vert = elem->getVertex(j);
				std::map<std::pair<MVertex*,GRegion*>,MVertex* >::iterator itMap = VertexGlobalAssociation.find(std::make_pair(vert,reg1));
				if (itMap != VertexGlobalAssociation.end()){
//					std::cout<<"on va changer un point"<<std::endl;
					elem->setVertex(j,itMap->second);
//					std::cout<<"on a introduit "<<itMap->second->getNum()<<std::endl;
//					std::cout<<"maintenant elem j "<<elem->getVertex(j)->getNum()<<std::endl;
//					std::cout<<"youpi"<<std::endl;
				}
			}
		}
		for (unsigned int i = 0; i < reg2->getNumMeshElements();i++){
			MElement* elem = reg2->getMeshElement(i);
			for (int j = 0;j < elem->getNumVertices();j++){
				MVertex* vert = elem->getVertex(j);
				std::map<std::pair<MVertex*,GRegion*>,MVertex* >::iterator itMap = VertexGlobalAssociation.find(std::make_pair(vert,reg2));
				if (itMap != VertexGlobalAssociation.end()){
//					std::cout<<"on va changer un point"<<std::endl;
					elem->setVertex(j,itMap->second);
//					std::cout<<"on a introduit "<<itMap->second->getNum()<<std::endl;
//					std::cout<<"maintenant elem j "<<elem->getVertex(j)->getNum()<<std::endl;
//					std::cout<<"youpi"<<std::endl;
				}
			}
		}
	}
	std::cout<<"interior faces done"<<std::endl;
	//maintenant on va traiter les faces du bord
	for (std::set<GFace*>::iterator itf = ToDuplicateListBoundary.begin();itf != ToDuplicateListBoundary.end();itf++){
		counterNbDone++;
		GFace* fTmp = (*itf);
		GRegion* reg1 = fTmp->getRegion(0);
		//pour commencer on cree des aretes entre les vertex
		std::list<GVertex*> vlist = fTmp->vertices();
		std::map<GVertex*,GEdge* > SurroudingEdges;
		for (std::list<GVertex*>::iterator itv = vlist.begin();itv != vlist.end();itv++){
			GVertex* vTmp = (*itv);
			GVertex* v1;
			std::map<std::pair<GVertex*,GRegion*>,GVertex* >::iterator itMap = GVertexGlobalAssociation.find(std::make_pair(vTmp,reg1));
			if (itMap != GVertexGlobalAssociation.end()){
				v1 = itMap->second;
			}
			GEdge* newE = m->addLine(v1,vTmp);
			SurroudingEdges[vTmp] = newE;
		}
		//ici tous les vertex sont traites
		//on va traiter les edges
		std::list<GEdge*> elist = fTmp->edges();
		std::vector<GEdge*> newEdgesVector;
		std::vector<GFace*> SurroundingsFaces;
		for (std::list<GEdge*>::iterator ite = elist.begin();ite != elist.end();ite++){
			//duplication Gedge
			GEdge* eTmp = (*ite);
			GEdge* e1;
			std::map<std::pair<GEdge*,GRegion*>,GEdge* >::iterator itMap = GEdgeGlobalAssociation.find(std::make_pair(eTmp,reg1));
			if (itMap != GEdgeGlobalAssociation.end()){
				e1 = itMap->second;
			}
			//creation des GFace correspondantes
			GEdge* firstE = SurroudingEdges.find(eTmp->getBeginVertex())->second;
			GEdge* lastE = SurroudingEdges.find(eTmp->getEndVertex())->second;
			if (firstE->getBeginVertex() != e1->getEndVertex()){
				firstE->reverse();
			}
			if (firstE->getBeginVertex() != e1->getEndVertex()){
				e1->reverse();
			}
			if (firstE->getBeginVertex() != e1->getEndVertex()){
				firstE->reverse();
			}
			if (eTmp->getBeginVertex() != firstE->getEndVertex()){
				eTmp->reverse();
			}
			if (lastE->getBeginVertex() != eTmp->getEndVertex()){
				lastE->reverse();
			}
			std::vector<GEdge*> VecEdgesTmp;
			VecEdgesTmp.push_back(e1);
			VecEdgesTmp.push_back(firstE);
			VecEdgesTmp.push_back(eTmp);
			VecEdgesTmp.push_back(lastE);
			std::vector<std::vector<GEdge*> > VecOfVecTmp;
			VecOfVecTmp.push_back(VecEdgesTmp);
			GFace* newFaceTmp = m->addPlanarFace(VecOfVecTmp);
			SurroundingsFaces.push_back(newFaceTmp);
		}
		std::vector<GFace*> VectorFaces;
		std::list<GFace*> listFaces;
		GFace* f1;
		std::map<std::pair<GFace*,GRegion*>,GFace* >::iterator itMap = GFaceGlobalAssociation.find(std::make_pair(fTmp,reg1));
		if (itMap != GFaceGlobalAssociation.end()){
			f1 = itMap->second;
		}
		VectorFaces.push_back(f1);
		listFaces.push_back(f1);
		for (unsigned int i = 0;i < SurroundingsFaces.size();i++){
			VectorFaces.push_back(SurroundingsFaces[i]);
			listFaces.push_back(SurroundingsFaces[i]);
		}
		VectorFaces.push_back(fTmp);
		listFaces.push_back(fTmp);
		std::vector<std::vector<GFace*> > VecOfVecGFace;
		VecOfVecGFace.push_back(VectorFaces);
		//creation de la nouvelle region
		GRegion* createdRegion = new GRegion(m,counterNbDone);
		createdRegion->addPhysicalEntity(PhysicalInterface);
		createdRegion->set(listFaces);
		m->add(createdRegion);
		for (unsigned int i = 0; i < fTmp->getNumMeshElements();i++){
			MElement* elem = fTmp->getMeshElement(i);
			MVertex* v1;
			MVertex* v2;
			MVertex* v3;
			std::map<std::pair<MVertex*,GRegion*>,MVertex* >::iterator itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(0),reg1));
			if (itMap != VertexGlobalAssociation.end()){
				v1 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(1),reg1));
			if (itMap != VertexGlobalAssociation.end()){
				v2 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(2),reg1));
			if (itMap != VertexGlobalAssociation.end()){
				v3 = itMap->second;
			}
			//			std::cout<<"creation de prisme "<<counterNbDone<<std::endl;
			MPrism *newPri = new MPrism(v1,v2,v3,elem->getVertex(0),elem->getVertex(1),elem->getVertex(2));
			//			std::cout<<"addition de prisme "<<counterNbDone<<std::endl;

			createdRegion->addPrism(newPri);
			//			std::cout<<"fin de for"<<std::endl;
		}
		std::cout<<"apres region, refonte points "<<counterNbDone<<std::endl;
		for (unsigned int i = 0; i < reg1->getNumMeshElements();i++){
			MElement* elem = reg1->getMeshElement(i);
			for (int j = 0;j < elem->getNumVertices();j++){
				MVertex* vert = elem->getVertex(j);
				std::map<std::pair<MVertex*,GRegion*>,MVertex* >::iterator itMap = VertexGlobalAssociation.find(std::make_pair(vert,reg1));
				if (itMap != VertexGlobalAssociation.end()){
//					std::cout<<"on va changer un point"<<std::endl;
					elem->setVertex(j,itMap->second);
//					std::cout<<"on a introduit "<<itMap->second->getNum()<<std::endl;
//					std::cout<<"maintenant elem j "<<elem->getVertex(j)->getNum()<<std::endl;
//					std::cout<<"youpi"<<std::endl;
				}
			}
		}
	}
	std::ofstream file("MicrostructurePolycrystal3D.pos");
	file << "View \"test\" {\n";

	std::ofstream file2("PERIODIC.map");
	for (std::vector<std::pair<GFace*,GFace*> >::iterator itP = pairs.begin();itP != pairs.end();itP++){
		std::pair<GFace*,GFace*> pairTmp = (*itP);
		GFace* ToReplaceFace = pairTmp.second;
		GRegion* rTmp = ToReplaceFace->getRegion(0);
		std::map<std::pair<GFace*,GRegion*>,GFace* >::iterator itMap = GFaceGlobalAssociation.find(std::make_pair(ToReplaceFace,rTmp));
		if (itMap != GFaceGlobalAssociation.end()){
			GFace* associatedFace = (*itMap).second;






			std::map<GFace*,SPoint3>::iterator it3 = centers.find(pairTmp.first);
			std::map<GFace*,SPoint3>::iterator it4 = centers.find(ToReplaceFace);

			SPoint3 p1 = it3->second;
			SPoint3  p2 = it4->second;

			//double delta_x = fabs(p2.x()-p1.x());
			//double delta_y = fabs(p2.y()-p1.y());
			//double delta_z = fabs(p2.z()-p1.z());


			file << "SL ("
					<< p1.x() << ", " << p1.y() << ", " << p1.z() << ", "
					<< p2.x() << ", " << p2.y() << ", " << p2.z()
					<< "){10, 20};\n";

			//file2 << "PERIODIC\tSURFACE"<<faces[i]->tag() << "\tSURFACE" << faces[j]->tag() << "\t" << p2.x()-p1.x() << "\t" << p2.y()-p1.y() << "\t" << p2.z()-p1.z() << "\n";
			if (abs((p2.x()-p1.x()-1.0))<0.0001){
				if (abs((p2.y()-p1.y()))<0.0001){
					if (abs((p2.z()-p1.z()))<0.0001){
						file2 << "NSET\tFRONT = FRONT + SURFACE"<<ToReplaceFace->tag()<<"\n";
						file2 << "NSET\tBACK = BACK + SURFACE"<<pairTmp.first->tag()<<"\n";
					}else if(abs((p2.z()-p1.z()-1.0))<0.0001){
						file2 << "NSET\tFRONTTOP = FRONTTOP + SURFACE"<<ToReplaceFace->tag()<<"\n";
						file2 << "NSET\tBACKBOTTOM = BACKBOTTOM + SURFACE"<<pairTmp.first->tag()<<"\n";
					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
						file2 << "NSET\tFRONTBOTTOM = FRONTBOTTOM + SURFACE"<<ToReplaceFace->tag()<<"\n";
						file2 << "NSET\tBACKTOP = BACKTOP + SURFACE"<<pairTmp.first->tag()<<"\n";
					}
				}else if (abs((p2.y()-p1.y()-1.0))<0.0001){
					if (abs((p2.z()-p1.z()))<0.0001){
						file2 << "NSET\tFRONTRIGHT = FRONTRIGHT + SURFACE"<<ToReplaceFace->tag()<<"\n";
						file2 << "NSET\tBACKLEFT = BACKLEFT + SURFACE"<<pairTmp.first->tag()<<"\n";
					}else if (abs((p2.z()-p1.z()-1.0))<0.0001){
						file2 << "NSET\tFRONTRIGHTTOP = FRONTRIGHTTOP + SURFACE"<<ToReplaceFace->tag()<<"\n";
						file2 << "NSET\tBACKLEFTBOTTOM = BACKLEFTBOTTOM + SURFACE"<<pairTmp.first->tag()<<"\n";
					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
						file2 << "NSET\tFRONTRIGHTBOTTOM = FRONTRIGHTBOTTOM + SURFACE"<<ToReplaceFace->tag()<<"\n";
						file2 << "NSET\tBACKLEFTTOP = BACKLEFTTOP + SURFACE"<<pairTmp.first->tag()<<"\n";
					}
				}else if (abs((p1.y()-p2.y()-1.0))<0.0001){
					if (abs((p2.z()-p1.z()))<0.0001){
						file2 << "NSET\tFRONTLEFT = FRONTLEFT + SURFACE"<<ToReplaceFace->tag()<<"\n";
						file2 << "NSET\tBACKRIGHT = BACKRIGHT + SURFACE"<<pairTmp.first->tag()<<"\n";
					}else if (abs((p2.z()-p1.z()-1.0))<0.0001){
						file2 << "NSET\tFRONTLEFTTOP = FRONTLEFTTOP + SURFACE"<<ToReplaceFace->tag()<<"\n";
						file2 << "NSET\tBACKRIGHTBOTTOM = BACKRIGHTBOTTOM + SURFACE"<<pairTmp.first->tag()<<"\n";
					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
						file2 << "NSET\tFRONTLEFTBOTTOM = FRONTLEFTBOTTOM + SURFACE"<<ToReplaceFace->tag()<<"\n";
						file2 << "NSET\tBACKRIGHTTOP = BACKRIGHTTOP + SURFACE"<<pairTmp.first->tag()<<"\n";
					}
				}
			}else if (abs((p1.x()-p2.x()-1.0))<0.0001){
				if (abs((p2.y()-p1.y()))<0.0001){
					if (abs((p2.z()-p1.z()))<0.0001){
						file2 << "NSET\tFRONT = FRONT + SURFACE"<<pairTmp.first->tag()<<"\n";
						file2 << "NSET\tBACK = BACK + SURFACE"<<ToReplaceFace->tag()<<"\n";
					}else if(abs((p2.z()-p1.z()-1.0))<0.0001){
						file2 << "NSET\tFRONTBOTTOM = FRONTBOTTOM + SURFACE"<<pairTmp.first->tag()<<"\n";
						file2 << "NSET\tBACKTOP = BACKTOP + SURFACE"<<ToReplaceFace->tag()<<"\n";
					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
						file2 << "NSET\tFRONTTOP = FRONTTOP + SURFACE"<<pairTmp.first->tag()<<"\n";
						file2 << "NSET\tBACKBOTTOM = BACKBOTTOM + SURFACE"<<ToReplaceFace->tag()<<"\n";
					}
				}else if (abs((p2.y()-p1.y()-1.0))<0.0001){
					if (abs((p2.z()-p1.z()))<0.0001){
						file2 << "NSET\tFRONTLEFT = FRONTLEFT + SURFACE"<<pairTmp.first->tag()<<"\n";
						file2 << "NSET\tBACKRIGHT = BACKRIGHT + SURFACE"<<ToReplaceFace->tag()<<"\n";
					}else if (abs((p2.z()-p1.z()-1.0))<0.0001){
						file2 << "NSET\tFRONTLEFTBOTTOM = FRONTLEFTBOTTOM + SURFACE"<<pairTmp.first->tag()<<"\n";
						file2 << "NSET\tBACKRIGHTTOP = BACKRIGHTTOP + SURFACE"<<ToReplaceFace->tag()<<"\n";
					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
						file2 << "NSET\tFRONTLEFTTOP = FRONTLEFTTOP + SURFACE"<<pairTmp.first->tag()<<"\n";
						file2 << "NSET\tBACKRIGHTBOTTOM = BACKRIGHTBOTTOM + SURFACE"<<ToReplaceFace->tag()<<"\n";
					}
				}else if (abs((p1.y()-p2.y()-1.0))<0.0001){
					if (abs((p2.z()-p1.z()))<0.0001){
						file2 << "NSET\tFRONTRIGHT = FRONTRIGHT + SURFACE"<<pairTmp.first->tag()<<"\n";
						file2 << "NSET\tBACKLEFT = BACKLEFT + SURFACE"<<ToReplaceFace->tag()<<"\n";
					}else if (abs((p2.z()-p1.z()-1.0))<0.0001){
						file2 << "NSET\tFRONTRIGHTBOTTOM = FRONTRIGHTBOTTOM + SURFACE"<<pairTmp.first->tag()<<"\n";
						file2 << "NSET\tBACKLEFTTOP = BACKLEFTTOP + SURFACE"<<ToReplaceFace->tag()<<"\n";
					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
						file2 << "NSET\tFRONTRIGHTTOP = FRONTRIGHTTOP + SURFACE"<<pairTmp.first->tag()<<"\n";
						file2 << "NSET\tBACKLEFTBOTTOM = BACKLEFTBOTTOM + SURFACE"<<ToReplaceFace->tag()<<"\n";
					}
				}
			}else if (abs((p1.x()-p2.x()))<0.0001){
				if (abs((p2.y()-p1.y()-1.0))<0.0001){
					if (abs((p2.z()-p1.z()))<0.0001){
						file2 << "NSET\tRIGHT = RIGHT + SURFACE"<<ToReplaceFace->tag()<<"\n";
						file2 << "NSET\tLEFT = LEFT + SURFACE"<<pairTmp.first->tag()<<"\n";
					}else if (abs((p2.z()-p1.z()-1.0))<0.0001){
						file2 << "NSET\tRIGHTTOP = RIGHTTOP + SURFACE"<<ToReplaceFace->tag()<<"\n";
						file2 << "NSET\tLEFTBOTTOM = LEFTBOTTOM + SURFACE"<<pairTmp.first->tag()<<"\n";
					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
						file2 << "NSET\tRIGHTBOTTOM = RIGHTBOTTOM + SURFACE"<<ToReplaceFace->tag()<<"\n";
						file2 << "NSET\tLEFTTOP = LEFTTOP + SURFACE"<<pairTmp.first->tag()<<"\n";
					}
				}else if (abs((p1.y()-p2.y()-1.0))<0.0001){
					if (abs((p2.z()-p1.z()))<0.0001){
						file2 << "NSET\tRIGHT = RIGHT + SURFACE"<<pairTmp.first->tag()<<"\n";
						file2 << "NSET\tLEFT = LEFT + SURFACE"<<ToReplaceFace->tag()<<"\n";
					}else if (abs((p2.z()-p1.z()-1.0))<0.0001){
						file2 << "NSET\tRIGHTBOTTOM = RIGHTBOTTOM + SURFACE"<<pairTmp.first->tag()<<"\n";
						file2 << "NSET\tLEFTTOP = LEFTTOP + SURFACE"<<ToReplaceFace->tag()<<"\n";
					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
						file2 << "NSET\tRIGHTTOP = RIGHTTOP + SURFACE"<<pairTmp.first->tag()<<"\n";
						file2 << "NSET\tLEFTBOTTOM = LEFTBOTTOM + SURFACE"<<ToReplaceFace->tag()<<"\n";
					}
				}else if (abs((p1.y()-p2.y()))<0.0001){
					if (abs((p2.z()-p1.z()-1.0))<0.0001){
						file2 << "NSET\tTOP = TOP + SURFACE"<<ToReplaceFace->tag()<<"\n";
						file2 << "NSET\tBOTTOM = BOTTOM + SURFACE"<<pairTmp.first->tag()<<"\n";
					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
						file2 << "NSET\tTOP = TOP + SURFACE"<<pairTmp.first->tag()<<"\n";
						file2 << "NSET\tBOTTOM = BOTTOM + SURFACE"<<ToReplaceFace->tag()<<"\n";
					}
				}
			}
//			count++;







			newPairs.push_back(std::make_pair(pairTmp.first,associatedFace));
		}
	}
//	for (std::vector<std::pair<GFace*,GFace*> >::iterator itP = newPairs.begin();itP != newPairs.end();itP++){
//		std::pair<GFace*,GFace*> pairTmp = (*itP);
//	}

	std::cout<<"End of DuplicateBoundaries"<<std::endl;
	return view;
}





PView *GMSH_DuplicateBoundariesPlugin::execute(PView *view)
{
	GModel *m = GModel::current();
	if (m->getDim() == 3){
		view = GMSH_DuplicateBoundariesPlugin::executeDuplicate(view);
	}
	else if (m->getDim() == 2){
		view = GMSH_DuplicateBoundariesPlugin::execute2DWithBound(view);
	}
	//view = GMSH_DuplicateBoundariesPlugin::ComputeBestSeeds(view);
	//view = GMSH_DuplicateBoundariesPlugin::execute2D(view);
	//view = GMSH_DuplicateBoundariesPlugin::execute2DWithBound(view);
	return view;
}



PView *GMSH_DuplicateBoundariesPlugin::executeDuplicate(PView *view)
{
	std::cout<<"starting DuplicateBoundaries"<<std::endl;
	GModel *m = GModel::current();
	m->setFactory("geo");
	std::set<GFace*> ToDuplicateList;
	ToDuplicateList.clear();
	std::set<GFace*> ToDuplicateListBoundary;
	ToDuplicateListBoundary.clear();
	std::vector<GFace*> facesBound;
	facesBound.clear();
	std::map<GFace*,SPoint3> centers;
	std::vector<std::pair<GFace*,GFace*> > pairs;
	std::vector<std::pair<GFace*,GFace*> > newPairs;
	int PhysicalInterface = m->setPhysicalName("Interface",3);
	for (GModel::fiter itf= m->firstFace();itf != m->lastFace();itf++){
		GFace* fTmp = (*itf);
		if (fTmp->numRegions() == 2){
			ToDuplicateList.insert(fTmp);
		}
		else{
//			ToDuplicateListBoundary.insert(fTmp);
			facesBound.push_back(fTmp);
		}
	}








	for(unsigned int i=0;i<facesBound.size();i++){
		double x = 0.0;
		double y = 0.0;
		double z = 0.0;

		std::list<GVertex*> vertices;

		vertices = facesBound[i]->vertices();

		for(std::list<GVertex*>::iterator it2=vertices.begin();it2!=vertices.end();it2++){
			x = x + (*it2)->x();
			y = y + (*it2)->y();
			z = z + (*it2)->z();
		}

		x = x/vertices.size();
		y = y/vertices.size();
		z = z/vertices.size();

		centers.insert(std::pair<GFace*,SPoint3>(facesBound[i],SPoint3(x,y,z)));
	}

	for(unsigned int i=0;i<facesBound.size();i++){
		for(unsigned int j=0;j<facesBound.size();j++){
			std::map<GFace*,SPoint3>::iterator it3 = centers.find(facesBound[i]);
			std::map<GFace*,SPoint3>::iterator it4 = centers.find(facesBound[j]);

			SPoint3 p1 = it3->second;
			SPoint3 p2 = it4->second;


			//				categories.push_back(val);

			//				print_segment(p1,p2,file);

			if (abs((p2.x()-p1.x()-1.0))<0.0001){
				if (abs((p2.y()-p1.y()))<0.0001){
					if (abs((p2.z()-p1.z()))<0.0001){
						pairs.push_back(std::pair<GFace*,GFace*>(facesBound[i],facesBound[j]));
						ToDuplicateListBoundary.insert(facesBound[i]);
//						std::cout<<"case 1"<<std::endl;
//						std::cout<<"on a p1.x() = "<<p1.x()<<" et p2.x() = "<<p2.x()<<" et abs((p2.x()-p1.x()-1.0)) = "<<abs((p2.x()-p1.x()-1.0))<<std::endl;
//						std::cout<<"on a abs(0.5) = "<<abs(0.5)<<" et abs(-0.5) = "<<abs(-0.5)<<" et abs(1.5) = "<<abs(1.5)<<" et abs(-1.5) = "<<abs(-1.5)<<std::endl;
//						std::cout<<"on a mis dans la liste: x "<<p1.x()<<" y "<<p1.y()<<" z "<<p1.z()<<std::endl;
//						std::cout<<"on avait pour second: x "<<p2.x()<<" y "<<p2.y()<<" z "<<p2.z()<<std::endl;
					}else if(abs((p2.z()-p1.z()-1.0))<0.0001){
						pairs.push_back(std::pair<GFace*,GFace*>(facesBound[i],facesBound[j]));
						ToDuplicateListBoundary.insert(facesBound[i]);
//						std::cout<<"case 2"<<std::endl;
//						std::cout<<"on a mis dans la liste: x "<<p1.x()<<" y "<<p1.y()<<" z "<<p1.z()<<std::endl;
//						std::cout<<"on avait pour second: x "<<p2.x()<<" y "<<p2.y()<<" z "<<p2.z()<<std::endl;
					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
						pairs.push_back(std::pair<GFace*,GFace*>(facesBound[i],facesBound[j]));
						ToDuplicateListBoundary.insert(facesBound[i]);
//						std::cout<<"case 3"<<std::endl;
//						std::cout<<"on a mis dans la liste: x "<<p1.x()<<" y "<<p1.y()<<" z "<<p1.z()<<std::endl;
//						std::cout<<"on avait pour second: x "<<p2.x()<<" y "<<p2.y()<<" z "<<p2.z()<<std::endl;
					}
				}else if (abs((p2.y()-p1.y()-1.0))<0.0001){
					if (abs((p2.z()-p1.z()))<0.0001){
						pairs.push_back(std::pair<GFace*,GFace*>(facesBound[i],facesBound[j]));
						ToDuplicateListBoundary.insert(facesBound[i]);
//						std::cout<<"case 4"<<std::endl;
//						std::cout<<"on a mis dans la liste: x "<<p1.x()<<" y "<<p1.y()<<" z "<<p1.z()<<std::endl;
//						std::cout<<"on avait pour second: x "<<p2.x()<<" y "<<p2.y()<<" z "<<p2.z()<<std::endl;
					}else if (abs((p2.z()-p1.z()-1.0))<0.0001){
						pairs.push_back(std::pair<GFace*,GFace*>(facesBound[i],facesBound[j]));
						ToDuplicateListBoundary.insert(facesBound[i]);
//						std::cout<<"case 5"<<std::endl;
//						std::cout<<"on a mis dans la liste: x "<<p1.x()<<" y "<<p1.y()<<" z "<<p1.z()<<std::endl;
//						std::cout<<"on avait pour second: x "<<p2.x()<<" y "<<p2.y()<<" z "<<p2.z()<<std::endl;
					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
						pairs.push_back(std::pair<GFace*,GFace*>(facesBound[i],facesBound[j]));
						ToDuplicateListBoundary.insert(facesBound[i]);
//						std::cout<<"case 6"<<std::endl;
//						std::cout<<"on a mis dans la liste: x "<<p1.x()<<" y "<<p1.y()<<" z "<<p1.z()<<std::endl;
//						std::cout<<"on avait pour second: x "<<p2.x()<<" y "<<p2.y()<<" z "<<p2.z()<<std::endl;
					}
				}else if (abs((p1.y()-p2.y()-1.0))<0.0001){
					if (abs((p2.z()-p1.z()))<0.0001){
						pairs.push_back(std::pair<GFace*,GFace*>(facesBound[i],facesBound[j]));
						ToDuplicateListBoundary.insert(facesBound[i]);
//						std::cout<<"case 7"<<std::endl;
//						std::cout<<"on a mis dans la liste: x "<<p1.x()<<" y "<<p1.y()<<" z "<<p1.z()<<std::endl;
//						std::cout<<"on avait pour second: x "<<p2.x()<<" y "<<p2.y()<<" z "<<p2.z()<<std::endl;
					}else if (abs((p2.z()-p1.z()-1.0))<0.0001){
						pairs.push_back(std::pair<GFace*,GFace*>(facesBound[i],facesBound[j]));
						ToDuplicateListBoundary.insert(facesBound[i]);
//						std::cout<<"case 8"<<std::endl;
//						std::cout<<"on a mis dans la liste: x "<<p1.x()<<" y "<<p1.y()<<" z "<<p1.z()<<std::endl;
//						std::cout<<"on avait pour second: x "<<p2.x()<<" y "<<p2.y()<<" z "<<p2.z()<<std::endl;
					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
						pairs.push_back(std::pair<GFace*,GFace*>(facesBound[i],facesBound[j]));
						ToDuplicateListBoundary.insert(facesBound[i]);
//						std::cout<<"case 9"<<std::endl;
//						std::cout<<"on a mis dans la liste: x "<<p1.x()<<" y "<<p1.y()<<" z "<<p1.z()<<std::endl;
//						std::cout<<"on avait pour second: x "<<p2.x()<<" y "<<p2.y()<<" z "<<p2.z()<<std::endl;
					}
				}
			}else if (abs((p1.x()-p2.x()-1.0))<0.0001){
				if (abs((p2.y()-p1.y()))<0.0001){
					if (abs((p2.z()-p1.z()))<0.0001){
						//NOTHING
					}else if(abs((p2.z()-p1.z()-1.0))<0.0001){
						//NOTHING
					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
						//NOTHING
					}
				}else if (abs((p2.y()-p1.y()-1.0))<0.0001){
					if (abs((p2.z()-p1.z()))<0.0001){
						//NOTHING
					}else if (abs((p2.z()-p1.z()-1.0))<0.0001){
						//NOTHING
					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
						//NOTHING
					}
				}else if (abs((p1.y()-p2.y()-1.0))<0.0001){
					if (abs((p2.z()-p1.z()))<0.0001){
						//NOTHING
					}else if (abs((p2.z()-p1.z()-1.0))<0.0001){
						//NOTHING
					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
						//NOTHING
					}
				}
			}else if (abs((p1.x()-p2.x()))<0.0001){
				if (abs((p2.y()-p1.y()-1.0))<0.0001){
					if (abs((p2.z()-p1.z()))<0.0001){
						pairs.push_back(std::pair<GFace*,GFace*>(facesBound[i],facesBound[j]));
						ToDuplicateListBoundary.insert(facesBound[i]);
//						std::cout<<"case 10"<<std::endl;
//						std::cout<<"on a mis dans la liste: x "<<p1.x()<<" y "<<p1.y()<<" z "<<p1.z()<<std::endl;
//						std::cout<<"on avait pour second: x "<<p2.x()<<" y "<<p2.y()<<" z "<<p2.z()<<std::endl;
					}else if (abs((p2.z()-p1.z()-1.0))<0.0001){
						pairs.push_back(std::pair<GFace*,GFace*>(facesBound[i],facesBound[j]));
						ToDuplicateListBoundary.insert(facesBound[i]);
//						std::cout<<"case 11"<<std::endl;
//						std::cout<<"on a mis dans la liste: x "<<p1.x()<<" y "<<p1.y()<<" z "<<p1.z()<<std::endl;
//						std::cout<<"on avait pour second: x "<<p2.x()<<" y "<<p2.y()<<" z "<<p2.z()<<std::endl;
					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
						pairs.push_back(std::pair<GFace*,GFace*>(facesBound[i],facesBound[j]));
						ToDuplicateListBoundary.insert(facesBound[i]);
//						std::cout<<"case 12"<<std::endl;
//						std::cout<<"on a mis dans la liste: x "<<p1.x()<<" y "<<p1.y()<<" z "<<p1.z()<<std::endl;
//						std::cout<<"on avait pour second: x "<<p2.x()<<" y "<<p2.y()<<" z "<<p2.z()<<std::endl;
					}
				}else if (abs((p1.y()-p2.y()-1.0))<0.0001){
					if (abs((p2.z()-p1.z()))<0.0001){
						//NOTHING
					}else if (abs((p2.z()-p1.z()-1.0))<0.0001){
						//NOTHING
					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
						//NOTHING
					}
				}else if (abs((p1.y()-p2.y()))<0.0001){
					if (abs((p2.z()-p1.z()-1.0))<0.0001){
						pairs.push_back(std::pair<GFace*,GFace*>(facesBound[i],facesBound[j]));
						ToDuplicateListBoundary.insert(facesBound[i]);
//						std::cout<<"case 13"<<std::endl;
//						std::cout<<"on a mis dans la liste: x "<<p1.x()<<" y "<<p1.y()<<" z "<<p1.z()<<std::endl;
//						std::cout<<"on avait pour second: x "<<p2.x()<<" y "<<p2.y()<<" z "<<p2.z()<<std::endl;
					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
						//NOTHING
					}
				}
			}
		}
	}
//	std::cout<<"on a une taille de facesBound = "<<facesBound.size()<<" et ToDuplicateListBoundary = "<<ToDuplicateListBoundary.size()<<std::endl;










	std::map<std::pair<MVertex*,GRegion*>,MVertex* > VertexGlobalAssociation;
	std::map<std::pair<GVertex*,GRegion*>,GVertex* > GVertexGlobalAssociation;
	std::map<std::pair<GEdge*,GRegion*>,GEdge* > GEdgeGlobalAssociation;
	std::map<std::pair<GFace*,GRegion*>,GFace* > GFaceGlobalAssociation;
//	for (GModel::viter itv= m->firstVertex();itv != m->lastVertex();itv++){
//		GVertex* vTmp = (*itv);
//		std::vector<GVertex* > vecTmp;
//		vecTmp.clear();
//		GVertexGlobalAssociation[vTmp] = vecTmp;
//		for (int i = 0; i < vTmp->mesh_vertices.size();i++){
//			MVertex *vMesh = vTmp->mesh_vertices[i];
//			std::vector<MVertex* > vecTmpBis;
//			vecTmpBis.clear();
//			VertexGlobalAssociation[vMesh] = vecTmpBis;
//		}
//	}
//	for (GModel::eiter ite= m->firstEdge();ite != m->lastEdge();ite++){
//		GEdge* eTmp = (*ite);
//		std::vector<GEdge* > vecTmp;
//		vecTmp.clear();
//		GEdgeGlobalAssociation[eTmp] = vecTmp;
//		for (int i = 0; i < eTmp->mesh_vertices.size();i++){
//			MVertex *vMesh = eTmp->mesh_vertices[i];
//			std::vector<MVertex* > vecTmpBis;
//			vecTmpBis.clear();
//			VertexGlobalAssociation[vMesh] = vecTmpBis;
//		}
//	}
//	for (GModel::fiter itf= m->firstFace();itf != m->lastFace();itf++){
//		GFace* fTmp = (*itf);
//		for (int i = 0; i < fTmp->mesh_vertices.size();i++){
//			MVertex *vMesh = fTmp->mesh_vertices[i];
//			std::vector<MVertex* > vecTmpBis;
//			vecTmpBis.clear();
//			VertexGlobalAssociation[vMesh] = vecTmpBis;
//		}
//	}
//	for (GModel::riter itr= m->firstRegion();itr != m->lastRegion();itr++){
//		GRegion* rTmp = (*itr);
//		for (int i = 0; i < rTmp->mesh_vertices.size();i++){
//			MVertex *vMesh = rTmp->mesh_vertices[i];
//			std::vector<MVertex* > vecTmpBis;
//			vecTmpBis.clear();
//			VertexGlobalAssociation[vMesh] = vecTmpBis;
//		}
//	}
//	std::cout<<"entree dans regions first pass"<<std::endl;
	for (GModel::riter itr= m->firstRegion();itr != m->lastRegion();itr++){
		GRegion* rTmp = (*itr);
		std::list<GFace*> RegFaces = rTmp->faces();
		std::map<MVertex*,MVertex* > VertexAssociation;
		std::map<GVertex*,GVertex* > GVertexAssociation;
		std::map<GEdge*,GEdge* > GEdgeAssociation;
		//int counterNbDone = 10000;
		double xCenterReg = 0.0;
		double yCenterReg = 0.0;
		double zCenterReg = 0.0;
		int counterPts = 0;
		for(std::list<GFace*>::iterator it2=RegFaces.begin();it2!=RegFaces.end();it2++){
			GFace* fTemp = (*it2);
			std::list<GVertex*> verticesFace = fTemp->vertices();
			for (std::list<GVertex*>::iterator it3=verticesFace.begin();it3!=verticesFace.end();it3++){
				xCenterReg = xCenterReg + (*it3)->x();
				yCenterReg = yCenterReg + (*it3)->y();
				zCenterReg = zCenterReg + (*it3)->z();
				counterPts++;
			}
		}
		xCenterReg = xCenterReg/counterPts;
		yCenterReg = yCenterReg/counterPts;
		zCenterReg = zCenterReg/counterPts;
		//duplication noeud et aretes au niveau de la region directement
		std::list<GVertex*> vlist;


//		std::cout<<"wut 1"<<std::endl;
		std::list<GFace*> listFacesTmp = rTmp->faces();
		for (std::list<GFace*>::iterator itTp = listFacesTmp.begin();itTp != listFacesTmp.end();itTp++){
//			std::cout<<"wut 2"<<std::endl;
			std::list<GVertex*> vlist2;
//			std::cout<<"wut 3"<<std::endl;
			vlist2 = (*itTp)->vertices();
//			std::cout<<"wut 4"<<std::endl;
			for (std::list<GVertex*>::iterator itTp2 = vlist2.begin();itTp2 != vlist2.end();itTp2++){
//				std::cout<<"wut 5"<<std::endl;
				if(std::find(vlist.begin(), vlist.end(), *itTp2) == vlist.end())
					vlist.push_back(*itTp2);
//				std::cout<<"wut 6"<<std::endl;
			}
//			std::cout<<"wut 7"<<std::endl;
		}
//		std::cout<<"wut 8"<<std::endl;


//		std::cout<<"on a une taille vlist de "<<vlist.size()<<std::endl;
//		std::cout<<"init done entering vertices"<<std::endl;
		for (std::list<GVertex*>::iterator itv = vlist.begin();itv != vlist.end();itv++){
			//duplication Gvertex
			GVertex* vTmp = (*itv);
			double ponderatedX = 0.99999999999 * vTmp->x() + 0.00000000001 * xCenterReg;
			double ponderatedY = 0.99999999999 * vTmp->y() + 0.00000000001 * yCenterReg;
			double ponderatedZ = 0.99999999999 * vTmp->z() + 0.00000000001 * zCenterReg;
			GVertex* newv = m->addVertex(ponderatedX,ponderatedY,ponderatedZ,vTmp->prescribedMeshSizeAtVertex());
//			std::cout<<"inserted correspondance between : "<<vTmp->tag()<<" and : "<<newv->tag()<<std::endl;
			GVertexAssociation[vTmp] = newv;
			GVertexGlobalAssociation[std::make_pair(vTmp,rTmp)] = newv;
			//creation des Gedge correspondantes
//			GEdge* newE = m->addLine(vTmp,newv);
//			SurroudingEdges[vTmp] = newE;
			//maintenant traitement mesh
			MVertex *vMesh = vTmp->mesh_vertices[0];
			MVertex *newMv = new MVertex(vMesh->x(), vMesh->y(), vMesh->z(), (GEntity*)newv);
			VertexAssociation[vMesh] = newMv;
			VertexGlobalAssociation[std::make_pair(vMesh,rTmp)] = newMv;
			newv->addMeshVertex(newMv);
		}
		//maintenant on soccupe de duppliquer les edges de la region
		std::list<GEdge*> elist = rTmp->edges();
//		std::cout<<"on a une taille elist de "<<elist.size()<<std::endl;
//		std::cout<<"vertices done entering edges"<<std::endl;

		std::vector<GFace*> SurroundingsFaces;
		for (std::list<GEdge*>::iterator ite = elist.begin();ite != elist.end();ite++){
			//duplication Gedge
			GEdge* eTmp = (*ite);
//			std::cout<<"before addline"<<std::endl;
//			std::cout<<"begin ID : "<<eTmp->getBeginVertex()->tag()<<" and end ID : "<<eTmp->getEndVertex()->tag()<<std::endl;
//			std::cout<<"corresponding begin ID : "<<GVertexAssociation[eTmp->getBeginVertex()]->tag()<<" and end ID : "<<GVertexAssociation[eTmp->getEndVertex()]->tag()<<std::endl;
			GEdge* newE = m->addLine(GVertexAssociation[eTmp->getEndVertex()],GVertexAssociation[eTmp->getBeginVertex()]);
//			std::cout<<"after addline"<<std::endl;
			GEdgeAssociation[eTmp] = newE;
			GEdgeGlobalAssociation[std::make_pair(eTmp,rTmp)] = newE;
			//creation des GFace correspondantes
//			GEdge* firstE = SurroudingEdges.find(eTmp->getEndVertex())->second;
//			GEdge* lastE = SurroudingEdges.find(eTmp->getBeginVertex())->second;
//			std::vector<GEdge*> VecEdgesTmp;
//			VecEdgesTmp.push_back(eTmp);
//			VecEdgesTmp.push_back(firstE);
//			VecEdgesTmp.push_back(newE);
//			VecEdgesTmp.push_back(lastE);
//			std::vector<std::vector<GEdge*> > VecOfVecTmp;
//			VecOfVecTmp.push_back(VecEdgesTmp);
//			GFace* newFaceTmp = m->addPlanarFace(VecOfVecTmp);
//			SurroundingsFaces.push_back(newFaceTmp);
			//maintenant traitement mesh
			for (unsigned int i = 0; i < eTmp->mesh_vertices.size();i++){
				MVertex *vMesh = eTmp->mesh_vertices[i];
				MVertex *newMv = new MVertex(vMesh->x(), vMesh->y(), vMesh->z(), (GEntity*)newE);
				VertexAssociation[vMesh] = newMv;
				VertexGlobalAssociation[std::make_pair(vMesh,rTmp)] = newMv;
				newE->addMeshVertex(newMv);
			}
//			std::cout<<"after newvertices"<<std::endl;
			for (unsigned int i = 0; i < eTmp->getNumMeshElements();i++){
				MElement* elem = eTmp->getMeshElement(i);
				MVertex *firstETmp = VertexAssociation.find(elem->getVertex(0))->second;
				MVertex *lastETmp = VertexAssociation.find(elem->getVertex(1))->second;
				MVertex *midETmp = VertexAssociation.find(elem->getVertex(2))->second;
				MLine3 *newLine = new MLine3(firstETmp,lastETmp,midETmp);
				newE->addLine(newLine);
			}
//			std::cout<<"after newMlines"<<std::endl;
		}
//		std::cout<<"edges done entering faces"<<std::endl;
		for (std::list<GFace*>::iterator itf = RegFaces.begin();itf != RegFaces.end();itf++){
			GFace* fTmp = (*itf);
			std::vector<GEdge*> newEdgesVector;
			std::list<GEdge*> elistFace = fTmp->edges();
			for (std::list<GEdge*>::iterator ite = elistFace.begin();ite != elistFace.end();ite++){
				GEdge* eTmp = (*ite);
				GEdge* eToFind = GEdgeAssociation[eTmp];
				newEdgesVector.push_back(eToFind);
			}
			std::vector<std::vector<GEdge*> > VecOfVec;
			VecOfVec.push_back(newEdgesVector);
			//creation de la nouvelle face
			GFace* GFaceAssociation = m->addPlanarFace(VecOfVec);
//			int tagTmp = GFaceAssociation->tag();
//			std::ostringstream ss;
//			ss << tagTmp;
////			char *intStr = itoa(tagTmp);
//			std::string nameSurf = "SURFACE";
////			nameSurf += std::string(intStr);
//			nameSurf += ss.str();
//			int PhysicalSurfaceTmp = m->setPhysicalName(nameSurf,2);
//			GFaceAssociation->addPhysicalEntity(PhysicalSurfaceTmp);
//			std::cout<<"on a associe a la face : "<<fTmp->tag()<<" la face : "<<GFaceAssociation->tag()<<std::endl;
			//maintenant traitement mesh
			for (unsigned int i = 0; i < fTmp->mesh_vertices.size();i++){
				MVertex *vMesh = fTmp->mesh_vertices[i];
				MVertex *newMv = new MVertex(vMesh->x(), vMesh->y(), vMesh->z(), (GEntity*)GFaceAssociation);
				VertexAssociation[vMesh] = newMv;
				VertexGlobalAssociation[std::make_pair(vMesh,rTmp)] = newMv;
				GFaceAssociation->addMeshVertex(newMv);
			}
			for (unsigned int i = 0; i < fTmp->getNumMeshElements();i++){
				MElement* elem = fTmp->getMeshElement(i);
				MVertex *firstE = VertexAssociation.find(elem->getVertex(0))->second;
				MVertex *secondE = VertexAssociation.find(elem->getVertex(1))->second;
				MVertex *thirdE = VertexAssociation.find(elem->getVertex(2))->second;
				MVertex *fourthE = VertexAssociation.find(elem->getVertex(3))->second;
				MVertex *fifthE = VertexAssociation.find(elem->getVertex(4))->second;
				MVertex *sisthE = VertexAssociation.find(elem->getVertex(5))->second;
				MTriangle6 *newTri = new MTriangle6(firstE,secondE,thirdE,fourthE,fifthE,sisthE);
				GFaceAssociation->addTriangle(newTri);
			}
			GFaceGlobalAssociation[std::make_pair(fTmp,rTmp)] = GFaceAssociation;
		}
//		std::cout<<"faces done for regions"<<std::endl;
	}
//	std::cout<<"Regions done first pass"<<std::endl;
	int counterNbDone = 10000;
	//maintenant on va traiter les faces initiales
	for (std::set<GFace*>::iterator itf = ToDuplicateList.begin();itf != ToDuplicateList.end();itf++){
		counterNbDone++;
		GFace* fTmp = (*itf);
		GRegion* reg1 = fTmp->getRegion(0);
		GRegion* reg2 = fTmp->getRegion(1);
		//pour commencer on cree des aretes entre les vertex
		std::list<GVertex*> vlist = fTmp->vertices();
		std::map<GVertex*,GEdge* > SurroudingEdges;
		for (std::list<GVertex*>::iterator itv = vlist.begin();itv != vlist.end();itv++){
			GVertex* vTmp = (*itv);
			GVertex* v1;
			GVertex* v2;
			std::map<std::pair<GVertex*,GRegion*>,GVertex* >::iterator itMap = GVertexGlobalAssociation.find(std::make_pair(vTmp,reg1));
			if (itMap != GVertexGlobalAssociation.end()){
				v1 = itMap->second;
			}
			itMap = GVertexGlobalAssociation.find(std::make_pair(vTmp,reg2));
			if (itMap != GVertexGlobalAssociation.end()){
				v2 = itMap->second;
			}
			GEdge* newE = m->addLine(v1,v2);
			SurroudingEdges[vTmp] = newE;
		}
		//ici tous les vertex sont traites
		//on va traiter les edges
		std::list<GEdge*> elist = fTmp->edges();
		std::vector<GEdge*> newEdgesVector;
		std::vector<GFace*> SurroundingsFaces;
		for (std::list<GEdge*>::iterator ite = elist.begin();ite != elist.end();ite++){
			//duplication Gedge
			GEdge* eTmp = (*ite);
			GEdge* e1;
			GEdge* e2;
			std::map<std::pair<GEdge*,GRegion*>,GEdge* >::iterator itMap = GEdgeGlobalAssociation.find(std::make_pair(eTmp,reg1));
			if (itMap != GEdgeGlobalAssociation.end()){
				e1 = itMap->second;
			}
			itMap = GEdgeGlobalAssociation.find(std::make_pair(eTmp,reg2));
			if (itMap != GEdgeGlobalAssociation.end()){
				e2 = itMap->second;
			}
			//creation des GFace correspondantes
			GEdge* firstE = SurroudingEdges.find(eTmp->getBeginVertex())->second;
			GEdge* lastE = SurroudingEdges.find(eTmp->getEndVertex())->second;
			if (firstE->getBeginVertex() != e1->getEndVertex()){
				firstE->reverse();
			}
			if (firstE->getBeginVertex() != e1->getEndVertex()){
				e1->reverse();
			}
			if (firstE->getBeginVertex() != e1->getEndVertex()){
				firstE->reverse();
			}
			if (e2->getBeginVertex() != firstE->getEndVertex()){
				e2->reverse();
			}
			if (lastE->getBeginVertex() != e2->getEndVertex()){
				lastE->reverse();
			}
			std::vector<GEdge*> VecEdgesTmp;
			VecEdgesTmp.push_back(e1);
			VecEdgesTmp.push_back(firstE);
			VecEdgesTmp.push_back(e2);
			VecEdgesTmp.push_back(lastE);
			std::vector<std::vector<GEdge*> > VecOfVecTmp;
			VecOfVecTmp.push_back(VecEdgesTmp);
			GFace* newFaceTmp = m->addPlanarFace(VecOfVecTmp);
			SurroundingsFaces.push_back(newFaceTmp);
		}
		std::vector<GFace*> VectorFaces;
		std::list<GFace*> listFaces;
		GFace* f1;
		GFace* f2;
		std::map<std::pair<GFace*,GRegion*>,GFace* >::iterator itMap = GFaceGlobalAssociation.find(std::make_pair(fTmp,reg1));
		if (itMap != GFaceGlobalAssociation.end()){
			f1 = itMap->second;
		}
		itMap = GFaceGlobalAssociation.find(std::make_pair(fTmp,reg2));
		if (itMap != GFaceGlobalAssociation.end()){
			f2 = itMap->second;
		}
		VectorFaces.push_back(f1);
		listFaces.push_back(f1);
		for (unsigned int i = 0;i < SurroundingsFaces.size();i++){
			VectorFaces.push_back(SurroundingsFaces[i]);
			listFaces.push_back(SurroundingsFaces[i]);
		}
		VectorFaces.push_back(f2);
		listFaces.push_back(f2);
		std::vector<std::vector<GFace*> > VecOfVecGFace;
		VecOfVecGFace.push_back(VectorFaces);
		//creation de la nouvelle region
		GRegion* createdRegion = new GRegion(m,counterNbDone);
		createdRegion->addPhysicalEntity(PhysicalInterface);
		createdRegion->set(listFaces);
		m->add(createdRegion);
		for (unsigned int i = 0; i < fTmp->getNumMeshElements();i++){
			MElement* elem = fTmp->getMeshElement(i);
			MVertex* v1;
			MVertex* v2;
			MVertex* v3;
			MVertex* v4;
			MVertex* v5;
			MVertex* v6;
			std::map<std::pair<MVertex*,GRegion*>,MVertex* >::iterator itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(0),reg1));
			if (itMap != VertexGlobalAssociation.end()){
				v1 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(3),reg1));
			if (itMap != VertexGlobalAssociation.end()){
				v2 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(5),reg1));
			if (itMap != VertexGlobalAssociation.end()){
				v3 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(0),reg2));
			if (itMap != VertexGlobalAssociation.end()){
				v4 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(3),reg2));
			if (itMap != VertexGlobalAssociation.end()){
				v5 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(5),reg2));
			if (itMap != VertexGlobalAssociation.end()){
				v6 = itMap->second;
			}
//			std::cout<<"creation de prisme "<<counterNbDone<<std::endl;
			MPrism *newPri = new MPrism(v1,v3,v2,v4,v6,v5);
//			std::cout<<"addition de prisme "<<counterNbDone<<std::endl;

			createdRegion->addPrism(newPri);
//			std::cout<<"fin de for"<<std::endl;

			//second
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(1),reg1));
			if (itMap != VertexGlobalAssociation.end()){
				v1 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(4),reg1));
			if (itMap != VertexGlobalAssociation.end()){
				v2 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(3),reg1));
			if (itMap != VertexGlobalAssociation.end()){
				v3 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(1),reg2));
			if (itMap != VertexGlobalAssociation.end()){
				v4 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(4),reg2));
			if (itMap != VertexGlobalAssociation.end()){
				v5 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(3),reg2));
			if (itMap != VertexGlobalAssociation.end()){
				v6 = itMap->second;
			}
			//			std::cout<<"creation de prisme "<<counterNbDone<<std::endl;
			MPrism *newPri2 = new MPrism(v1,v3,v2,v4,v6,v5);
			//			std::cout<<"addition de prisme "<<counterNbDone<<std::endl;

			createdRegion->addPrism(newPri2);
			//third
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(2),reg1));
			if (itMap != VertexGlobalAssociation.end()){
				v1 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(5),reg1));
			if (itMap != VertexGlobalAssociation.end()){
				v2 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(4),reg1));
			if (itMap != VertexGlobalAssociation.end()){
				v3 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(2),reg2));
			if (itMap != VertexGlobalAssociation.end()){
				v4 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(5),reg2));
			if (itMap != VertexGlobalAssociation.end()){
				v5 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(4),reg2));
			if (itMap != VertexGlobalAssociation.end()){
				v6 = itMap->second;
			}
			//			std::cout<<"creation de prisme "<<counterNbDone<<std::endl;
			MPrism *newPri3 = new MPrism(v1,v3,v2,v4,v6,v5);
			//			std::cout<<"addition de prisme "<<counterNbDone<<std::endl;

			createdRegion->addPrism(newPri3);
			//fourth
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(3),reg1));
			if (itMap != VertexGlobalAssociation.end()){
				v1 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(4),reg1));
			if (itMap != VertexGlobalAssociation.end()){
				v2 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(5),reg1));
			if (itMap != VertexGlobalAssociation.end()){
				v3 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(3),reg2));
			if (itMap != VertexGlobalAssociation.end()){
				v4 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(4),reg2));
			if (itMap != VertexGlobalAssociation.end()){
				v5 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(5),reg2));
			if (itMap != VertexGlobalAssociation.end()){
				v6 = itMap->second;
			}
			//			std::cout<<"creation de prisme "<<counterNbDone<<std::endl;
			MPrism *newPri4 = new MPrism(v1,v3,v2,v4,v6,v5);
			//			std::cout<<"addition de prisme "<<counterNbDone<<std::endl;

			createdRegion->addPrism(newPri4);
		}
//		std::cout<<"apres region, refonte points "<<counterNbDone<<std::endl;
		for (unsigned int i = 0; i < reg1->getNumMeshElements();i++){
			MElement* elem = reg1->getMeshElement(i);
			for (int j = 0;j < elem->getNumVertices();j++){
				MVertex* vert = elem->getVertex(j);
				std::map<std::pair<MVertex*,GRegion*>,MVertex* >::iterator itMap = VertexGlobalAssociation.find(std::make_pair(vert,reg1));
				if (itMap != VertexGlobalAssociation.end()){
//					std::cout<<"on va changer un point"<<std::endl;
					elem->setVertex(j,itMap->second);
//					std::cout<<"on a introduit "<<itMap->second->getNum()<<std::endl;
//					std::cout<<"maintenant elem j "<<elem->getVertex(j)->getNum()<<std::endl;
//					std::cout<<"youpi"<<std::endl;
				}
			}
		}
		for (unsigned int i = 0; i < reg2->getNumMeshElements();i++){
			MElement* elem = reg2->getMeshElement(i);
			for (int j = 0;j < elem->getNumVertices();j++){
				MVertex* vert = elem->getVertex(j);
				std::map<std::pair<MVertex*,GRegion*>,MVertex* >::iterator itMap = VertexGlobalAssociation.find(std::make_pair(vert,reg2));
				if (itMap != VertexGlobalAssociation.end()){
//					std::cout<<"on va changer un point"<<std::endl;
					elem->setVertex(j,itMap->second);
//					std::cout<<"on a introduit "<<itMap->second->getNum()<<std::endl;
//					std::cout<<"maintenant elem j "<<elem->getVertex(j)->getNum()<<std::endl;
//					std::cout<<"youpi"<<std::endl;
				}
			}
		}
	}
//	std::cout<<"interior faces done"<<std::endl;
	//maintenant on va traiter les faces du bord
	for (std::set<GFace*>::iterator itf = ToDuplicateListBoundary.begin();itf != ToDuplicateListBoundary.end();itf++){
		counterNbDone++;
		GFace* fTmp = (*itf);
		GRegion* reg1 = fTmp->getRegion(0);
		//pour commencer on cree des aretes entre les vertex
		std::list<GVertex*> vlist = fTmp->vertices();
		std::map<GVertex*,GEdge* > SurroudingEdges;
		for (std::list<GVertex*>::iterator itv = vlist.begin();itv != vlist.end();itv++){
			GVertex* vTmp = (*itv);
			GVertex* v1;
			std::map<std::pair<GVertex*,GRegion*>,GVertex* >::iterator itMap = GVertexGlobalAssociation.find(std::make_pair(vTmp,reg1));
			if (itMap != GVertexGlobalAssociation.end()){
				v1 = itMap->second;
			}
			GEdge* newE = m->addLine(v1,vTmp);
			SurroudingEdges[vTmp] = newE;
		}
		//ici tous les vertex sont traites
		//on va traiter les edges
		std::list<GEdge*> elist = fTmp->edges();
		std::vector<GEdge*> newEdgesVector;
		std::vector<GFace*> SurroundingsFaces;
		for (std::list<GEdge*>::iterator ite = elist.begin();ite != elist.end();ite++){
			//duplication Gedge
			GEdge* eTmp = (*ite);
			GEdge* e1;
			std::map<std::pair<GEdge*,GRegion*>,GEdge* >::iterator itMap = GEdgeGlobalAssociation.find(std::make_pair(eTmp,reg1));
			if (itMap != GEdgeGlobalAssociation.end()){
				e1 = itMap->second;
			}
			//creation des GFace correspondantes
			GEdge* firstE = SurroudingEdges.find(eTmp->getBeginVertex())->second;
			GEdge* lastE = SurroudingEdges.find(eTmp->getEndVertex())->second;
			if (firstE->getBeginVertex() != e1->getEndVertex()){
				firstE->reverse();
			}
			if (firstE->getBeginVertex() != e1->getEndVertex()){
				e1->reverse();
			}
			if (firstE->getBeginVertex() != e1->getEndVertex()){
				firstE->reverse();
			}
			if (eTmp->getBeginVertex() != firstE->getEndVertex()){
				eTmp->reverse();
			}
			if (lastE->getBeginVertex() != eTmp->getEndVertex()){
				lastE->reverse();
			}
			std::vector<GEdge*> VecEdgesTmp;
			VecEdgesTmp.push_back(e1);
			VecEdgesTmp.push_back(firstE);
			VecEdgesTmp.push_back(eTmp);
			VecEdgesTmp.push_back(lastE);
			std::vector<std::vector<GEdge*> > VecOfVecTmp;
			VecOfVecTmp.push_back(VecEdgesTmp);
			GFace* newFaceTmp = m->addPlanarFace(VecOfVecTmp);
			SurroundingsFaces.push_back(newFaceTmp);
		}
		std::vector<GFace*> VectorFaces;
		std::list<GFace*> listFaces;
		GFace* f1;
		std::map<std::pair<GFace*,GRegion*>,GFace* >::iterator itMap = GFaceGlobalAssociation.find(std::make_pair(fTmp,reg1));
		if (itMap != GFaceGlobalAssociation.end()){
			f1 = itMap->second;
		}
		VectorFaces.push_back(f1);
		listFaces.push_back(f1);
		for (unsigned int i = 0;i < SurroundingsFaces.size();i++){
			VectorFaces.push_back(SurroundingsFaces[i]);
			listFaces.push_back(SurroundingsFaces[i]);
		}
		VectorFaces.push_back(fTmp);
		listFaces.push_back(fTmp);
		std::vector<std::vector<GFace*> > VecOfVecGFace;
		VecOfVecGFace.push_back(VectorFaces);
		//creation de la nouvelle region
		GRegion* createdRegion = new GRegion(m,counterNbDone);
		createdRegion->addPhysicalEntity(PhysicalInterface);
		createdRegion->set(listFaces);
		m->add(createdRegion);
		for (unsigned int i = 0; i < fTmp->getNumMeshElements();i++){
			MElement* elem = fTmp->getMeshElement(i);
			MVertex* v1;
			MVertex* v2;
			MVertex* v3;
			std::map<std::pair<MVertex*,GRegion*>,MVertex* >::iterator itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(0),reg1));
			if (itMap != VertexGlobalAssociation.end()){
				v1 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(3),reg1));
			if (itMap != VertexGlobalAssociation.end()){
				v2 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(5),reg1));
			if (itMap != VertexGlobalAssociation.end()){
				v3 = itMap->second;
			}
			//			std::cout<<"creation de prisme "<<counterNbDone<<std::endl;
			MPrism *newPri = new MPrism(v1,v3,v2,elem->getVertex(0),elem->getVertex(5),elem->getVertex(3));
			//			std::cout<<"addition de prisme "<<counterNbDone<<std::endl;

			createdRegion->addPrism(newPri);
			//			std::cout<<"fin de for"<<std::endl;
			//second
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(1),reg1));
			if (itMap != VertexGlobalAssociation.end()){
				v1 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(4),reg1));
			if (itMap != VertexGlobalAssociation.end()){
				v2 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(3),reg1));
			if (itMap != VertexGlobalAssociation.end()){
				v3 = itMap->second;
			}
			//			std::cout<<"creation de prisme "<<counterNbDone<<std::endl;
			MPrism *newPri2 = new MPrism(v1,v3,v2,elem->getVertex(1),elem->getVertex(3),elem->getVertex(4));
			//			std::cout<<"addition de prisme "<<counterNbDone<<std::endl;

			createdRegion->addPrism(newPri2);
			//third
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(2),reg1));
			if (itMap != VertexGlobalAssociation.end()){
				v1 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(5),reg1));
			if (itMap != VertexGlobalAssociation.end()){
				v2 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(4),reg1));
			if (itMap != VertexGlobalAssociation.end()){
				v3 = itMap->second;
			}
			//			std::cout<<"creation de prisme "<<counterNbDone<<std::endl;
			MPrism *newPri3 = new MPrism(v1,v3,v2,elem->getVertex(2),elem->getVertex(4),elem->getVertex(5));
			//			std::cout<<"addition de prisme "<<counterNbDone<<std::endl;

			createdRegion->addPrism(newPri3);
			//fourth
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(3),reg1));
			if (itMap != VertexGlobalAssociation.end()){
				v1 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(4),reg1));
			if (itMap != VertexGlobalAssociation.end()){
				v2 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(5),reg1));
			if (itMap != VertexGlobalAssociation.end()){
				v3 = itMap->second;
			}
			//			std::cout<<"creation de prisme "<<counterNbDone<<std::endl;
			MPrism *newPri4 = new MPrism(v1,v3,v2,elem->getVertex(3),elem->getVertex(5),elem->getVertex(4));
			//			std::cout<<"addition de prisme "<<counterNbDone<<std::endl;

			createdRegion->addPrism(newPri4);
		}
//		std::cout<<"apres region, refonte points "<<counterNbDone<<std::endl;
		for (unsigned int i = 0; i < reg1->getNumMeshElements();i++){
			MElement* elem = reg1->getMeshElement(i);
			for (int j = 0;j < elem->getNumVertices();j++){
				MVertex* vert = elem->getVertex(j);
				std::map<std::pair<MVertex*,GRegion*>,MVertex* >::iterator itMap = VertexGlobalAssociation.find(std::make_pair(vert,reg1));
				if (itMap != VertexGlobalAssociation.end()){
//					std::cout<<"on va changer un point"<<std::endl;
					elem->setVertex(j,itMap->second);
//					std::cout<<"on a introduit "<<itMap->second->getNum()<<std::endl;
//					std::cout<<"maintenant elem j "<<elem->getVertex(j)->getNum()<<std::endl;
//					std::cout<<"youpi"<<std::endl;
				}
			}
		}
	}
	std::ofstream file("MicrostructurePolycrystal3D.pos");
	file << "View \"test\" {\n";

	std::ofstream file2("PERIODIC.map");
	std::ofstream file3("SetAdd.map");
	for (std::vector<std::pair<GFace*,GFace*> >::iterator itP = pairs.begin();itP != pairs.end();itP++){
		std::pair<GFace*,GFace*> pairTmp = (*itP);
		GFace* ToReplaceFace = pairTmp.second;
		GRegion* rTmp = ToReplaceFace->getRegion(0);
		std::map<std::pair<GFace*,GRegion*>,GFace* >::iterator itMap = GFaceGlobalAssociation.find(std::make_pair(ToReplaceFace,rTmp));
		if (itMap != GFaceGlobalAssociation.end()){
			GFace* associatedFace = (*itMap).second;





			file3 <<associatedFace->tag()<<"\tSURFACE"<<associatedFace->tag()<<"\tNSET "<<"\n";

			int tagTmp = associatedFace->tag();
			std::ostringstream ss;
			ss << tagTmp;
//			char *intStr = itoa(tagTmp);
			std::string nameSurf = "SURFACE";
//			nameSurf += std::string(intStr);
			nameSurf += ss.str();
			int PhysicalSurfaceTmp = m->setPhysicalName(nameSurf,2);
			associatedFace->addPhysicalEntity(PhysicalSurfaceTmp);

			std::map<GFace*,SPoint3>::iterator it3 = centers.find(pairTmp.first);
			std::map<GFace*,SPoint3>::iterator it4 = centers.find(ToReplaceFace);

			SPoint3 p1 = it3->second;
			SPoint3  p2 = it4->second;

			//double delta_x = fabs(p2.x()-p1.x());
			//double delta_y = fabs(p2.y()-p1.y());
			//double delta_z = fabs(p2.z()-p1.z());


			file << "SL ("
					<< p1.x() << ", " << p1.y() << ", " << p1.z() << ", "
					<< p2.x() << ", " << p2.y() << ", " << p2.z()
					<< "){10, 20};\n";

			//file2 << "PERIODIC\tSURFACE"<<faces[i]->tag() << "\tSURFACE" << faces[j]->tag() << "\t" << p2.x()-p1.x() << "\t" << p2.y()-p1.y() << "\t" << p2.z()-p1.z() << "\n";
			if (abs((p2.x()-p1.x()-1.0))<0.0001){
				if (abs((p2.y()-p1.y()))<0.0001){
					if (abs((p2.z()-p1.z()))<0.0001){
						file2 << "NSET\tFRONT = FRONT + SURFACE"<<associatedFace->tag()<<"\n";
						file2 << "NSET\tBACK = BACK + SURFACE"<<pairTmp.first->tag()<<"\n";
					}else if(abs((p2.z()-p1.z()-1.0))<0.0001){
						file2 << "NSET\tFRONTTOP = FRONTTOP + SURFACE"<<associatedFace->tag()<<"\n";
						file2 << "NSET\tBACKBOTTOM = BACKBOTTOM + SURFACE"<<pairTmp.first->tag()<<"\n";
					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
						file2 << "NSET\tFRONTBOTTOM = FRONTBOTTOM + SURFACE"<<associatedFace->tag()<<"\n";
						file2 << "NSET\tBACKTOP = BACKTOP + SURFACE"<<pairTmp.first->tag()<<"\n";
					}
				}else if (abs((p2.y()-p1.y()-1.0))<0.0001){
					if (abs((p2.z()-p1.z()))<0.0001){
						file2 << "NSET\tFRONTRIGHT = FRONTRIGHT + SURFACE"<<associatedFace->tag()<<"\n";
						file2 << "NSET\tBACKLEFT = BACKLEFT + SURFACE"<<pairTmp.first->tag()<<"\n";
					}else if (abs((p2.z()-p1.z()-1.0))<0.0001){
						file2 << "NSET\tFRONTRIGHTTOP = FRONTRIGHTTOP + SURFACE"<<associatedFace->tag()<<"\n";
						file2 << "NSET\tBACKLEFTBOTTOM = BACKLEFTBOTTOM + SURFACE"<<pairTmp.first->tag()<<"\n";
					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
						file2 << "NSET\tFRONTRIGHTBOTTOM = FRONTRIGHTBOTTOM + SURFACE"<<associatedFace->tag()<<"\n";
						file2 << "NSET\tBACKLEFTTOP = BACKLEFTTOP + SURFACE"<<pairTmp.first->tag()<<"\n";
					}
				}else if (abs((p1.y()-p2.y()-1.0))<0.0001){
					if (abs((p2.z()-p1.z()))<0.0001){
						file2 << "NSET\tFRONTLEFT = FRONTLEFT + SURFACE"<<associatedFace->tag()<<"\n";
						file2 << "NSET\tBACKRIGHT = BACKRIGHT + SURFACE"<<pairTmp.first->tag()<<"\n";
					}else if (abs((p2.z()-p1.z()-1.0))<0.0001){
						file2 << "NSET\tFRONTLEFTTOP = FRONTLEFTTOP + SURFACE"<<associatedFace->tag()<<"\n";
						file2 << "NSET\tBACKRIGHTBOTTOM = BACKRIGHTBOTTOM + SURFACE"<<pairTmp.first->tag()<<"\n";
					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
						file2 << "NSET\tFRONTLEFTBOTTOM = FRONTLEFTBOTTOM + SURFACE"<<associatedFace->tag()<<"\n";
						file2 << "NSET\tBACKRIGHTTOP = BACKRIGHTTOP + SURFACE"<<pairTmp.first->tag()<<"\n";
					}
				}
			}else if (abs((p1.x()-p2.x()-1.0))<0.0001){
				if (abs((p2.y()-p1.y()))<0.0001){
					if (abs((p2.z()-p1.z()))<0.0001){
						file2 << "NSET\tFRONT = FRONT + SURFACE"<<pairTmp.first->tag()<<"\n";
						file2 << "NSET\tBACK = BACK + SURFACE"<<associatedFace->tag()<<"\n";
					}else if(abs((p2.z()-p1.z()-1.0))<0.0001){
						file2 << "NSET\tFRONTBOTTOM = FRONTBOTTOM + SURFACE"<<pairTmp.first->tag()<<"\n";
						file2 << "NSET\tBACKTOP = BACKTOP + SURFACE"<<associatedFace->tag()<<"\n";
					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
						file2 << "NSET\tFRONTTOP = FRONTTOP + SURFACE"<<pairTmp.first->tag()<<"\n";
						file2 << "NSET\tBACKBOTTOM = BACKBOTTOM + SURFACE"<<associatedFace->tag()<<"\n";
					}
				}else if (abs((p2.y()-p1.y()-1.0))<0.0001){
					if (abs((p2.z()-p1.z()))<0.0001){
						file2 << "NSET\tFRONTLEFT = FRONTLEFT + SURFACE"<<pairTmp.first->tag()<<"\n";
						file2 << "NSET\tBACKRIGHT = BACKRIGHT + SURFACE"<<associatedFace->tag()<<"\n";
					}else if (abs((p2.z()-p1.z()-1.0))<0.0001){
						file2 << "NSET\tFRONTLEFTBOTTOM = FRONTLEFTBOTTOM + SURFACE"<<pairTmp.first->tag()<<"\n";
						file2 << "NSET\tBACKRIGHTTOP = BACKRIGHTTOP + SURFACE"<<associatedFace->tag()<<"\n";
					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
						file2 << "NSET\tFRONTLEFTTOP = FRONTLEFTTOP + SURFACE"<<pairTmp.first->tag()<<"\n";
						file2 << "NSET\tBACKRIGHTBOTTOM = BACKRIGHTBOTTOM + SURFACE"<<associatedFace->tag()<<"\n";
					}
				}else if (abs((p1.y()-p2.y()-1.0))<0.0001){
					if (abs((p2.z()-p1.z()))<0.0001){
						file2 << "NSET\tFRONTRIGHT = FRONTRIGHT + SURFACE"<<pairTmp.first->tag()<<"\n";
						file2 << "NSET\tBACKLEFT = BACKLEFT + SURFACE"<<associatedFace->tag()<<"\n";
					}else if (abs((p2.z()-p1.z()-1.0))<0.0001){
						file2 << "NSET\tFRONTRIGHTBOTTOM = FRONTRIGHTBOTTOM + SURFACE"<<pairTmp.first->tag()<<"\n";
						file2 << "NSET\tBACKLEFTTOP = BACKLEFTTOP + SURFACE"<<associatedFace->tag()<<"\n";
					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
						file2 << "NSET\tFRONTRIGHTTOP = FRONTRIGHTTOP + SURFACE"<<pairTmp.first->tag()<<"\n";
						file2 << "NSET\tBACKLEFTBOTTOM = BACKLEFTBOTTOM + SURFACE"<<associatedFace->tag()<<"\n";
					}
				}
			}else if (abs((p1.x()-p2.x()))<0.0001){
				if (abs((p2.y()-p1.y()-1.0))<0.0001){
					if (abs((p2.z()-p1.z()))<0.0001){
						file2 << "NSET\tRIGHT = RIGHT + SURFACE"<<associatedFace->tag()<<"\n";
						file2 << "NSET\tLEFT = LEFT + SURFACE"<<pairTmp.first->tag()<<"\n";
					}else if (abs((p2.z()-p1.z()-1.0))<0.0001){
						file2 << "NSET\tRIGHTTOP = RIGHTTOP + SURFACE"<<associatedFace->tag()<<"\n";
						file2 << "NSET\tLEFTBOTTOM = LEFTBOTTOM + SURFACE"<<pairTmp.first->tag()<<"\n";
					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
						file2 << "NSET\tRIGHTBOTTOM = RIGHTBOTTOM + SURFACE"<<associatedFace->tag()<<"\n";
						file2 << "NSET\tLEFTTOP = LEFTTOP + SURFACE"<<pairTmp.first->tag()<<"\n";
					}
				}else if (abs((p1.y()-p2.y()-1.0))<0.0001){
					if (abs((p2.z()-p1.z()))<0.0001){
						file2 << "NSET\tRIGHT = RIGHT + SURFACE"<<pairTmp.first->tag()<<"\n";
						file2 << "NSET\tLEFT = LEFT + SURFACE"<<associatedFace->tag()<<"\n";
					}else if (abs((p2.z()-p1.z()-1.0))<0.0001){
						file2 << "NSET\tRIGHTBOTTOM = RIGHTBOTTOM + SURFACE"<<pairTmp.first->tag()<<"\n";
						file2 << "NSET\tLEFTTOP = LEFTTOP + SURFACE"<<associatedFace->tag()<<"\n";
					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
						file2 << "NSET\tRIGHTTOP = RIGHTTOP + SURFACE"<<pairTmp.first->tag()<<"\n";
						file2 << "NSET\tLEFTBOTTOM = LEFTBOTTOM + SURFACE"<<associatedFace->tag()<<"\n";
					}
				}else if (abs((p1.y()-p2.y()))<0.0001){
					if (abs((p2.z()-p1.z()-1.0))<0.0001){
						file2 << "NSET\tTOP = TOP + SURFACE"<<associatedFace->tag()<<"\n";
						file2 << "NSET\tBOTTOM = BOTTOM + SURFACE"<<pairTmp.first->tag()<<"\n";
					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
						file2 << "NSET\tTOP = TOP + SURFACE"<<pairTmp.first->tag()<<"\n";
						file2 << "NSET\tBOTTOM = BOTTOM + SURFACE"<<associatedFace->tag()<<"\n";
					}
				}
			}
//			count++;







			newPairs.push_back(std::make_pair(pairTmp.first,associatedFace));
		}
	}
//	for (std::vector<std::pair<GFace*,GFace*> >::iterator itP = newPairs.begin();itP != newPairs.end();itP++){
//		std::pair<GFace*,GFace*> pairTmp = (*itP);
//	}

	std::cout<<"End of DuplicateBoundaries"<<std::endl;
	return view;
}











PView *GMSH_DuplicateBoundariesPlugin::execute2D(PView *view)
{
	std::cout<<"starting DuplicateBoundaries"<<std::endl;
	GModel *m = GModel::current();
	m->setFactory("geo");
	std::set<GEdge*> ToDuplicateList;
	ToDuplicateList.clear();
	std::set<GFace*> ToDuplicateListBoundary;
	ToDuplicateListBoundary.clear();
	std::vector<GFace*> facesBound;
	facesBound.clear();
	std::map<GFace*,SPoint3> centers;
	std::vector<std::pair<GFace*,GFace*> > pairs;
	std::vector<std::pair<GFace*,GFace*> > newPairs;
	int PhysicalInterface = m->setPhysicalName("Interface",2);
//	for (GModel::fiter itf= m->firstFace();itf != m->lastFace();itf++){
//		GFace* ftmp= (*itf);
//		std::list<GEdge*> edgesFace = ftmp->edges();
////		std::cout<<"size de edgesFace "<<edgesFace.size()<<std::endl;
//		for (std::list<GEdge*>::iterator it2=edgesFace.begin();it2!=edgesFace.end();it2++){
//			GEdge* etmp = (*it2);
////			std::cout<<"on a la edge "<<etmp->tag()<<std::endl;
////			std::cout<<"size de face de etmp before : "<<etmp->faces().size()<<std::endl;
//			etmp->addFace(ftmp);
////			std::cout<<"size de face de etmp after : "<<etmp->faces().size()<<std::endl;
//		}
//	}
	for (GModel::eiter ite= m->firstEdge();ite != m->lastEdge();ite++){
		GEdge* eTmp = (*ite);
//		std::cout<<"on a size de face de etmp de "<<eTmp->faces().size()<<std::endl;
		if (eTmp->faces().size() == 2){
			ToDuplicateList.insert(eTmp);
		}
	}










	std::map<std::pair<MVertex*,GFace*>,MVertex* > VertexGlobalAssociation;
	std::map<std::pair<GVertex*,GFace*>,GVertex* > GVertexGlobalAssociation;
	std::map<std::pair<GEdge*,GFace*>,GEdge* > GEdgeGlobalAssociation;
	std::map<std::pair<GFace*,GRegion*>,GFace* > GFaceGlobalAssociation;
	std::cout<<"entree dans regions first pass"<<std::endl;
	for (GModel::fiter itr= m->firstFace();itr != m->lastFace();itr++){
		GFace* rTmp = (*itr);
		std::list<GEdge*> RegEdges = rTmp->edges();
		std::map<MVertex*,MVertex* > VertexAssociation;
		std::map<GVertex*,GVertex* > GVertexAssociation;
		std::map<GEdge*,GEdge* > GEdgeAssociation;
		//int counterNbDone = 10000;
		double xCenterReg = 0.0;
		double yCenterReg = 0.0;
		double zCenterReg = 0.0;
		int counterPts = 0;
		for(std::list<GEdge*>::iterator it2=RegEdges.begin();it2!=RegEdges.end();it2++){
			GEdge* fTemp = (*it2);
			std::list<GVertex*> verticesFace = fTemp->vertices();
			for (std::list<GVertex*>::iterator it3=verticesFace.begin();it3!=verticesFace.end();it3++){
				xCenterReg = xCenterReg + (*it3)->x();
				yCenterReg = yCenterReg + (*it3)->y();
				zCenterReg = zCenterReg + (*it3)->z();
				counterPts++;
			}
		}
		xCenterReg = xCenterReg/counterPts;
		yCenterReg = yCenterReg/counterPts;
		zCenterReg = zCenterReg/counterPts;
		//duplication noeud et aretes au niveau de la region directement
		std::list<GVertex*> vlist;


//		std::cout<<"wut 1"<<std::endl;
		std::list<GEdge*> listedgesTmp = rTmp->edges();
		std::cout<<"listeEdge size "<<listedgesTmp.size()<<std::endl;
		for (std::list<GEdge*>::iterator itTp = listedgesTmp.begin();itTp != listedgesTmp.end();itTp++){
//			std::cout<<"wut 2"<<std::endl;
			std::list<GVertex*> vlist2;
//			std::cout<<"wut 3"<<std::endl;
			if(std::find(vlist.begin(), vlist.end(),(*itTp)->getBeginVertex()) == vlist.end())
				vlist.push_back((*itTp)->getBeginVertex());
			if(std::find(vlist.begin(), vlist.end(),(*itTp)->getEndVertex()) == vlist.end())
				vlist.push_back((*itTp)->getEndVertex());
//			vlist2 = (*itTp)->vertices();
//			std::cout<<"vlist2 size "<<vlist2.size()<<std::endl;
////			std::cout<<"wut 4"<<std::endl;
//			for (std::list<GVertex*>::iterator itTp2 = vlist2.begin();itTp2 != vlist2.end();itTp2++){
////				std::cout<<"wut 5"<<std::endl;
//				if(std::find(vlist.begin(), vlist.end(), *itTp2) == vlist.end())
//					vlist.push_back(*itTp2);
////				std::cout<<"wut 6"<<std::endl;
//			}
//			std::cout<<"wut 7"<<std::endl;
		}
//		std::cout<<"wut 8"<<std::endl;


//		std::cout<<"on a une taille vlist de "<<vlist.size()<<std::endl;
//		std::cout<<"init done entering vertices"<<std::endl;
		for (std::list<GVertex*>::iterator itv = vlist.begin();itv != vlist.end();itv++){
			//duplication Gvertex
			GVertex* vTmp = (*itv);
			double ponderatedX = 0.99999999999 * vTmp->x() + 0.00000000001 * xCenterReg;
			double ponderatedY = 0.99999999999 * vTmp->y() + 0.00000000001 * yCenterReg;
			double ponderatedZ = 0.99999999999 * vTmp->z() + 0.00000000001 * zCenterReg;
			GVertex* newv = m->addVertex(ponderatedX,ponderatedY,ponderatedZ,vTmp->prescribedMeshSizeAtVertex());
//			std::cout<<"inserted correspondance between : "<<vTmp->tag()<<" and : "<<newv->tag()<<std::endl;
			GVertexAssociation[vTmp] = newv;
			GVertexGlobalAssociation[std::make_pair(vTmp,rTmp)] = newv;
			//creation des Gedge correspondantes
//			GEdge* newE = m->addLine(vTmp,newv);
//			SurroudingEdges[vTmp] = newE;
			//maintenant traitement mesh
			MVertex *vMesh = vTmp->mesh_vertices[0];
			MVertex *newMv = new MVertex(vMesh->x(), vMesh->y(), vMesh->z(), (GEntity*)newv);
			VertexAssociation[vMesh] = newMv;
			VertexGlobalAssociation[std::make_pair(vMesh,rTmp)] = newMv;
			newv->addMeshVertex(newMv);
		}
		//maintenant on soccupe de duppliquer les edges de la region
		std::list<GEdge*> elist = rTmp->edges();
		std::cout<<"on a une taille elist de "<<elist.size()<<std::endl;
		std::cout<<"vertices done entering edges"<<std::endl;

		std::vector<GFace*> SurroundingsFaces;
//		for (std::list<GEdge*>::iterator ite = elist.begin();ite != elist.end();ite++){
//			//duplication Gedge
//			GEdge* eTmp = (*ite);
////			std::cout<<"before addline"<<std::endl;
////			std::cout<<"begin ID : "<<eTmp->getBeginVertex()->tag()<<" and end ID : "<<eTmp->getEndVertex()->tag()<<std::endl;
////			std::cout<<"corresponding begin ID : "<<GVertexAssociation[eTmp->getBeginVertex()]->tag()<<" and end ID : "<<GVertexAssociation[eTmp->getEndVertex()]->tag()<<std::endl;
//			GEdge* newE = m->addLine(GVertexAssociation[eTmp->getEndVertex()],GVertexAssociation[eTmp->getBeginVertex()]);
////			std::cout<<"after addline"<<std::endl;
//			GEdgeAssociation[eTmp] = newE;
//			GEdgeGlobalAssociation[std::make_pair(eTmp,rTmp)] = newE;
//			//creation des GFace correspondantes
////			GEdge* firstE = SurroudingEdges.find(eTmp->getEndVertex())->second;
////			GEdge* lastE = SurroudingEdges.find(eTmp->getBeginVertex())->second;
////			std::vector<GEdge*> VecEdgesTmp;
////			VecEdgesTmp.push_back(eTmp);
////			VecEdgesTmp.push_back(firstE);
////			VecEdgesTmp.push_back(newE);
////			VecEdgesTmp.push_back(lastE);
////			std::vector<std::vector<GEdge*> > VecOfVecTmp;
////			VecOfVecTmp.push_back(VecEdgesTmp);
////			GFace* newFaceTmp = m->addPlanarFace(VecOfVecTmp);
////			SurroundingsFaces.push_back(newFaceTmp);
//			//maintenant traitement mesh
//			for (int i = 0; i < eTmp->mesh_vertices.size();i++){
//				MVertex *vMesh = eTmp->mesh_vertices[i];
//				MVertex *newMv = new MVertex(vMesh->x(), vMesh->y(), vMesh->z(), (GEntity*)newE);
//				VertexAssociation[vMesh] = newMv;
//				VertexGlobalAssociation[std::make_pair(vMesh,rTmp)] = newMv;
//				newE->addMeshVertex(newMv);
//			}
////			std::cout<<"after newvertices"<<std::endl;
//			for (int i = 0; i < eTmp->getNumMeshElements();i++){
//				MElement* elem = eTmp->getMeshElement(i);
//				MVertex *firstETmp = VertexAssociation.find(elem->getVertex(0))->second;
//				MVertex *lastETmp = VertexAssociation.find(elem->getVertex(1))->second;
//				MVertex *midETmp = VertexAssociation.find(elem->getVertex(2))->second;
//				MLine3 *newLine = new MLine3(firstETmp,lastETmp,midETmp);
//				newE->addLine(newLine);
//			}
////			std::cout<<"after newMlines"<<std::endl;
//		}
		std::cout<<"edges done entering faces"<<std::endl;
		std::cout<<"RegEdges size : "<<RegEdges.size()<<std::endl;
		for (std::list<GEdge*>::iterator itf = RegEdges.begin();itf != RegEdges.end();itf++){
			GEdge* eTmp = (*itf);
//			std::vector<GEdge*> newEdgesVector;
//			std::list<GEdge*> elistFace = fTmp->edges();
//			for (std::list<GEdge*>::iterator ite = elistFace.begin();ite != elistFace.end();ite++){
//				GEdge* eTmp = (*ite);
//				GEdge* eToFind = GEdgeAssociation[eTmp];
//				newEdgesVector.push_back(eToFind);
//			}
//			std::vector<std::vector<GEdge*> > VecOfVec;
//			VecOfVec.push_back(newEdgesVector);
			//creation de la nouvelle face
			std::cout<<"before newvertices"<<std::endl;
			std::cout<<"beginvertex : "<<eTmp->getBeginVertex()->tag()<<std::endl;
			std::cout<<"endvertex : "<<eTmp->getEndVertex()->tag()<<std::endl;
			std::cout<<"associated begin "<<GVertexAssociation[eTmp->getBeginVertex()]->tag()<<std::endl;
			std::cout<<"associated end "<<GVertexAssociation[eTmp->getEndVertex()]->tag()<<std::endl;
			GEdge* newE = m->addLine(GVertexAssociation[eTmp->getBeginVertex()],GVertexAssociation[eTmp->getEndVertex()]);
//			std::cout<<"plop1"<<std::endl;
			for (unsigned int i = 0; i < eTmp->mesh_vertices.size();i++){
//				std::cout<<"plop2"<<std::endl;
				MVertex *vMesh = eTmp->mesh_vertices[i];
//				std::cout<<"plop3"<<std::endl;
				MVertex *newMv = new MVertex(vMesh->x(), vMesh->y(), vMesh->z(), (GEntity*)newE);
//				std::cout<<"plop4"<<std::endl;
				VertexAssociation[vMesh] = newMv;
//				std::cout<<"plop5"<<std::endl;
				VertexGlobalAssociation[std::make_pair(vMesh,rTmp)] = newMv;
//				std::cout<<"plop6"<<std::endl;
				newE->addMeshVertex(newMv);
//				std::cout<<"plop7"<<std::endl;
			}
			std::cout<<"after newvertices"<<std::endl;
			for (unsigned int i = 0; i < eTmp->getNumMeshElements();i++){
				MElement* elem = eTmp->getMeshElement(i);
				MVertex *firstETmp = VertexAssociation.find(elem->getVertex(0))->second;
				MVertex *lastETmp = VertexAssociation.find(elem->getVertex(1))->second;
				MVertex *midETmp = VertexAssociation.find(elem->getVertex(2))->second;
				MLine3 *newLine = new MLine3(firstETmp,lastETmp,midETmp);
				newE->addLine(newLine);
			}
			std::cout<<"after addline"<<std::endl;
			GEdgeGlobalAssociation[std::make_pair(eTmp,rTmp)] = newE;
//			GEdge* GFaceAssociation = m->addPlanarFace(VecOfVec);
//			int tagTmp = GFaceAssociation->tag();
//			std::ostringstream ss;
//			ss << tagTmp;
////			char *intStr = itoa(tagTmp);
//			std::string nameSurf = "SURFACE";
////			nameSurf += std::string(intStr);
//			nameSurf += ss.str();
//			int PhysicalSurfaceTmp = m->setPhysicalName(nameSurf,2);
//			GFaceAssociation->addPhysicalEntity(PhysicalSurfaceTmp);
//			std::cout<<"on a associe a la face : "<<fTmp->tag()<<" la face : "<<GFaceAssociation->tag()<<std::endl;
//			//maintenant traitement mesh
//			for (int i = 0; i < fTmp->mesh_vertices.size();i++){
//				MVertex *vMesh = fTmp->mesh_vertices[i];
//				MVertex *newMv = new MVertex(vMesh->x(), vMesh->y(), vMesh->z(), (GEntity*)GFaceAssociation);
//				VertexAssociation[vMesh] = newMv;
//				VertexGlobalAssociation[std::make_pair(vMesh,rTmp)] = newMv;
//				GFaceAssociation->addMeshVertex(newMv);
//			}
//			for (int i = 0; i < fTmp->getNumMeshElements();i++){
//				MElement* elem = fTmp->getMeshElement(i);
//				MVertex *firstE = VertexAssociation.find(elem->getVertex(0))->second;
//				MVertex *secondE = VertexAssociation.find(elem->getVertex(1))->second;
//				MVertex *thirdE = VertexAssociation.find(elem->getVertex(2))->second;
//				MVertex *fourthE = VertexAssociation.find(elem->getVertex(3))->second;
//				MVertex *fifthE = VertexAssociation.find(elem->getVertex(4))->second;
//				MVertex *sisthE = VertexAssociation.find(elem->getVertex(5))->second;
//				MTriangle6 *newTri = new MTriangle6(firstE,secondE,thirdE,fourthE,fifthE,sisthE);
//				GFaceAssociation->addTriangle(newTri);
//			}
//			GFaceGlobalAssociation[std::make_pair(fTmp,rTmp)] = GFaceAssociation;
		}
//		std::cout<<"faces done for regions"<<std::endl;
	}
	std::cout<<"Regions done first pass"<<std::endl;
	int counterNbDone = 10000;
	//maintenant on va traiter les faces initiales
	for (std::set<GEdge*>::iterator itf = ToDuplicateList.begin();itf != ToDuplicateList.end();itf++){
		counterNbDone++;
		std::cout<<"entree dans toduplicateList numero "<<counterNbDone<<std::endl;
		GEdge* eTmp = (*itf);
		std::list<GFace*> listFacesTmpT = eTmp->faces();
		std::cout<<"on a une taille de list faces de "<<listFacesTmpT.size()<<std::endl;
		std::list<GFace*>::iterator itTmpFace = listFacesTmpT.begin();
		GFace* fac1 = (*itTmpFace);
		itTmpFace++;
		GFace* fac2 = (*itTmpFace);
		//pour commencer on cree des aretes entre les vertex
//		std::list<GVertex*> vlist = eTmp->vertices();
		std::list<GVertex*> vlist;
		vlist.push_back(eTmp->getBeginVertex());
		vlist.push_back(eTmp->getEndVertex());
		std::map<GVertex*,GEdge* > SurroudingEdges;
		std::cout<<"entre dans vlist.begin"<<std::endl;
		for (std::list<GVertex*>::iterator itv = vlist.begin();itv != vlist.end();itv++){
			GVertex* vTmp = (*itv);
			std::cout<<"test1"<<std::endl;
			std::cout<<"on a fac1 "<<fac1->tag()<<" et fac2 "<<fac2->tag()<<" et vTmp "<<vTmp->tag()<<std::endl;
			GVertex* v1;
			GVertex* v2;
			std::map<std::pair<GVertex*,GFace*>,GVertex* >::iterator itMap = GVertexGlobalAssociation.find(std::make_pair(vTmp,fac1));
			std::cout<<"test2"<<std::endl;
			if (itMap != GVertexGlobalAssociation.end()){
				v1 = itMap->second;
				std::cout<<"assigned v1"<<std::endl;
			}
			std::cout<<"test3"<<std::endl;
			itMap = GVertexGlobalAssociation.find(std::make_pair(vTmp,fac2));
			std::cout<<"test4"<<std::endl;
			if (itMap != GVertexGlobalAssociation.end()){
				v2 = itMap->second;
				std::cout<<"assigned v2"<<std::endl;
			}
			std::cout<<"test5"<<std::endl;
			GEdge* newE = m->addLine(v1,v2);
			std::cout<<"test6"<<std::endl;
			SurroudingEdges[vTmp] = newE;
			std::cout<<"test7"<<std::endl;
		}
		std::cout<<"vertex traites"<<std::endl;
		//ici tous les vertex sont traites
		//on va traiter les edges
//		std::list<GEdge*> elist = fTmp->edges();
		std::vector<GEdge*> newEdgesVector;
		std::vector<GFace*> SurroundingsFaces;
		//duplication Gedge
		//			GEdge* eTmp = (*ite);
		GEdge* e1;
		GEdge* e2;
		std::map<std::pair<GEdge*,GFace*>,GEdge* >::iterator itMap = GEdgeGlobalAssociation.find(std::make_pair(eTmp,fac1));
		if (itMap != GEdgeGlobalAssociation.end()){
			e1 = itMap->second;
		}
		itMap = GEdgeGlobalAssociation.find(std::make_pair(eTmp,fac2));
		if (itMap != GEdgeGlobalAssociation.end()){
			e2 = itMap->second;
		}
		std::cout<<"creation des GFace correspondantes"<<std::endl;
		//creation des GFace correspondantes
		GEdge* firstE = SurroudingEdges.find(eTmp->getBeginVertex())->second;
		GEdge* lastE = SurroudingEdges.find(eTmp->getEndVertex())->second;
		if (firstE->getBeginVertex() != e1->getEndVertex()){
			firstE->reverse();
		}
		if (firstE->getBeginVertex() != e1->getEndVertex()){
			e1->reverse();
		}
		if (firstE->getBeginVertex() != e1->getEndVertex()){
			firstE->reverse();
		}
		if (e2->getBeginVertex() != firstE->getEndVertex()){
			e2->reverse();
		}
		if (lastE->getBeginVertex() != e2->getEndVertex()){
			lastE->reverse();
		}
		std::vector<GEdge*> VecEdgesTmp;
		VecEdgesTmp.push_back(e1);
		VecEdgesTmp.push_back(firstE);
		VecEdgesTmp.push_back(e2);
		VecEdgesTmp.push_back(lastE);
		std::vector<std::vector<GEdge*> > VecOfVecTmp;
		VecOfVecTmp.push_back(VecEdgesTmp);
		GFace* newFaceTmp = m->addPlanarFace(VecOfVecTmp);
		//			SurroundingsFaces.push_back(newFaceTmp);

		//creation de la nouvelle region
//		GRegion* createdRegion = new GRegion(m,counterNbDone);
		newFaceTmp->addPhysicalEntity(PhysicalInterface);
//		createdRegion->set(listFaces);
//		m->add(createdRegion);
		std::cout<<"eTmp->getNumMeshElements() "<<eTmp->getNumMeshElements()<<std::endl;
		for (unsigned int i = 0; i < eTmp->getNumMeshElements();i++){
			MElement* elem = eTmp->getMeshElement(i);
			MVertex* v1;
			MVertex* v2;
			MVertex* v3;
			MVertex* v4;
			//MVertex* v5;
			//MVertex* v6;
			std::map<std::pair<MVertex*,GFace*>,MVertex* >::iterator itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(0),fac1));
			if (itMap != VertexGlobalAssociation.end()){
				v1 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(2),fac1));
			if (itMap != VertexGlobalAssociation.end()){
				v2 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(2),fac2));
			if (itMap != VertexGlobalAssociation.end()){
				v3 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(0),fac2));
			if (itMap != VertexGlobalAssociation.end()){
				v4 = itMap->second;
			}
//			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(3),fac2));
//			if (itMap != VertexGlobalAssociation.end()){
//				v5 = itMap->second;
//			}
//			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(5),fac2));
//			if (itMap != VertexGlobalAssociation.end()){
//				v6 = itMap->second;
//			}
//			std::cout<<"creation de prisme "<<counterNbDone<<std::endl;
			MQuadrangle *newQua = new MQuadrangle(v1,v2,v3,v4);
			std::cout<<"addition du quad "<<newQua->getNum()<<" avec les vertices "<<v1->getNum()<<" ; "<<v2->getNum()<<" ; "<<v3->getNum()<<" ; "<<v4->getNum()<<std::endl;
//			std::cout<<"addition de prisme "<<counterNbDone<<std::endl;

			newFaceTmp->addQuadrangle(newQua);
//			std::cout<<"fin de for"<<std::endl;

			//second
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(2),fac1));
			if (itMap != VertexGlobalAssociation.end()){
				v1 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(1),fac1));
			if (itMap != VertexGlobalAssociation.end()){
				v2 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(1),fac2));
			if (itMap != VertexGlobalAssociation.end()){
				v3 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(2),fac2));
			if (itMap != VertexGlobalAssociation.end()){
				v4 = itMap->second;
			}
			//			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(3),fac2));
			//			if (itMap != VertexGlobalAssociation.end()){
			//				v5 = itMap->second;
			//			}
			//			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(5),fac2));
			//			if (itMap != VertexGlobalAssociation.end()){
			//				v6 = itMap->second;
			//			}
			//			std::cout<<"creation de prisme "<<counterNbDone<<std::endl;
			MQuadrangle *newQua2 = new MQuadrangle(v1,v2,v3,v4);
			std::cout<<"addition du quad "<<newQua2->getNum()<<" avec les vertices "<<v1->getNum()<<" ; "<<v2->getNum()<<" ; "<<v3->getNum()<<" ; "<<v4->getNum()<<std::endl;
			//			std::cout<<"addition de prisme "<<counterNbDone<<std::endl;

			newFaceTmp->addQuadrangle(newQua2);




		}
//		std::cout<<"apres region, refonte points "<<counterNbDone<<std::endl;
		for (unsigned int i = 0; i < fac1->getNumMeshElements();i++){
			MElement* elem = fac1->getMeshElement(i);
			for (int j = 0;j < elem->getNumVertices();j++){
				MVertex* vert = elem->getVertex(j);
				std::map<std::pair<MVertex*,GFace*>,MVertex* >::iterator itMap = VertexGlobalAssociation.find(std::make_pair(vert,fac1));
				if (itMap != VertexGlobalAssociation.end()){
//					std::cout<<"on va changer un point"<<std::endl;
					elem->setVertex(j,itMap->second);
//					std::cout<<"on a introduit "<<itMap->second->getNum()<<std::endl;
//					std::cout<<"maintenant elem j "<<elem->getVertex(j)->getNum()<<std::endl;
//					std::cout<<"youpi"<<std::endl;
				}
			}
		}
		for (unsigned int i = 0; i < fac2->getNumMeshElements();i++){
			MElement* elem = fac2->getMeshElement(i);
			for (int j = 0;j < elem->getNumVertices();j++){
				MVertex* vert = elem->getVertex(j);
				std::map<std::pair<MVertex*,GFace*>,MVertex* >::iterator itMap = VertexGlobalAssociation.find(std::make_pair(vert,fac2));
				if (itMap != VertexGlobalAssociation.end()){
//					std::cout<<"on va changer un point"<<std::endl;
					elem->setVertex(j,itMap->second);
//					std::cout<<"on a introduit "<<itMap->second->getNum()<<std::endl;
//					std::cout<<"maintenant elem j "<<elem->getVertex(j)->getNum()<<std::endl;
//					std::cout<<"youpi"<<std::endl;
				}
			}
		}
	}
	std::cout<<"interior faces done"<<std::endl;
	//maintenant on va traiter les faces du bord
//	std::ofstream file("MicrostructurePolycrystal3D.pos");
//	file << "View \"test\" {\n";
//
//	std::ofstream file2("PERIODIC.map");
//	std::ofstream file3("SetAdd.map");
//	for (std::vector<std::pair<GFace*,GFace*> >::iterator itP = pairs.begin();itP != pairs.end();itP++){
//		std::pair<GFace*,GFace*> pairTmp = (*itP);
//		GFace* ToReplaceFace = pairTmp.second;
//		GRegion* rTmp = ToReplaceFace->getRegion(0);
//		std::map<std::pair<GFace*,GRegion*>,GFace* >::iterator itMap = GFaceGlobalAssociation.find(std::make_pair(ToReplaceFace,rTmp));
//		if (itMap != GFaceGlobalAssociation.end()){
//			GFace* associatedFace = (*itMap).second;
//
//
//
//
//
//			file3 <<associatedFace->tag()<<"\tSURFACE"<<associatedFace->tag()<<"\tNSET "<<"\n";
//
//			int tagTmp = associatedFace->tag();
//			std::ostringstream ss;
//			ss << tagTmp;
////			char *intStr = itoa(tagTmp);
//			std::string nameSurf = "SURFACE";
////			nameSurf += std::string(intStr);
//			nameSurf += ss.str();
//			int PhysicalSurfaceTmp = m->setPhysicalName(nameSurf,2);
//			associatedFace->addPhysicalEntity(PhysicalSurfaceTmp);
//
//			std::map<GFace*,SPoint3>::iterator it3 = centers.find(pairTmp.first);
//			std::map<GFace*,SPoint3>::iterator it4 = centers.find(ToReplaceFace);
//
//			SPoint3 p1 = it3->second;
//			SPoint3  p2 = it4->second;
//
//			double delta_x = fabs(p2.x()-p1.x());
//			double delta_y = fabs(p2.y()-p1.y());
//			double delta_z = fabs(p2.z()-p1.z());
//
//
//			file << "SL ("
//					<< p1.x() << ", " << p1.y() << ", " << p1.z() << ", "
//					<< p2.x() << ", " << p2.y() << ", " << p2.z()
//					<< "){10, 20};\n";
//
//			//file2 << "PERIODIC\tSURFACE"<<faces[i]->tag() << "\tSURFACE" << faces[j]->tag() << "\t" << p2.x()-p1.x() << "\t" << p2.y()-p1.y() << "\t" << p2.z()-p1.z() << "\n";
//			if (abs((p2.x()-p1.x()-1.0))<0.0001){
//				if (abs((p2.y()-p1.y()))<0.0001){
//					if (abs((p2.z()-p1.z()))<0.0001){
//						file2 << "NSET\tFRONT = FRONT + SURFACE"<<associatedFace->tag()<<"\n";
//						file2 << "NSET\tBACK = BACK + SURFACE"<<pairTmp.first->tag()<<"\n";
//					}else if(abs((p2.z()-p1.z()-1.0))<0.0001){
//						file2 << "NSET\tFRONTTOP = FRONTTOP + SURFACE"<<associatedFace->tag()<<"\n";
//						file2 << "NSET\tBACKBOTTOM = BACKBOTTOM + SURFACE"<<pairTmp.first->tag()<<"\n";
//					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
//						file2 << "NSET\tFRONTBOTTOM = FRONTBOTTOM + SURFACE"<<associatedFace->tag()<<"\n";
//						file2 << "NSET\tBACKTOP = BACKTOP + SURFACE"<<pairTmp.first->tag()<<"\n";
//					}
//				}else if (abs((p2.y()-p1.y()-1.0))<0.0001){
//					if (abs((p2.z()-p1.z()))<0.0001){
//						file2 << "NSET\tFRONTRIGHT = FRONTRIGHT + SURFACE"<<associatedFace->tag()<<"\n";
//						file2 << "NSET\tBACKLEFT = BACKLEFT + SURFACE"<<pairTmp.first->tag()<<"\n";
//					}else if (abs((p2.z()-p1.z()-1.0))<0.0001){
//						file2 << "NSET\tFRONTRIGHTTOP = FRONTRIGHTTOP + SURFACE"<<associatedFace->tag()<<"\n";
//						file2 << "NSET\tBACKLEFTBOTTOM = BACKLEFTBOTTOM + SURFACE"<<pairTmp.first->tag()<<"\n";
//					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
//						file2 << "NSET\tFRONTRIGHTBOTTOM = FRONTRIGHTBOTTOM + SURFACE"<<associatedFace->tag()<<"\n";
//						file2 << "NSET\tBACKLEFTTOP = BACKLEFTTOP + SURFACE"<<pairTmp.first->tag()<<"\n";
//					}
//				}else if (abs((p1.y()-p2.y()-1.0))<0.0001){
//					if (abs((p2.z()-p1.z()))<0.0001){
//						file2 << "NSET\tFRONTLEFT = FRONTLEFT + SURFACE"<<associatedFace->tag()<<"\n";
//						file2 << "NSET\tBACKRIGHT = BACKRIGHT + SURFACE"<<pairTmp.first->tag()<<"\n";
//					}else if (abs((p2.z()-p1.z()-1.0))<0.0001){
//						file2 << "NSET\tFRONTLEFTTOP = FRONTLEFTTOP + SURFACE"<<associatedFace->tag()<<"\n";
//						file2 << "NSET\tBACKRIGHTBOTTOM = BACKRIGHTBOTTOM + SURFACE"<<pairTmp.first->tag()<<"\n";
//					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
//						file2 << "NSET\tFRONTLEFTBOTTOM = FRONTLEFTBOTTOM + SURFACE"<<associatedFace->tag()<<"\n";
//						file2 << "NSET\tBACKRIGHTTOP = BACKRIGHTTOP + SURFACE"<<pairTmp.first->tag()<<"\n";
//					}
//				}
//			}else if (abs((p1.x()-p2.x()-1.0))<0.0001){
//				if (abs((p2.y()-p1.y()))<0.0001){
//					if (abs((p2.z()-p1.z()))<0.0001){
//						file2 << "NSET\tFRONT = FRONT + SURFACE"<<pairTmp.first->tag()<<"\n";
//						file2 << "NSET\tBACK = BACK + SURFACE"<<associatedFace->tag()<<"\n";
//					}else if(abs((p2.z()-p1.z()-1.0))<0.0001){
//						file2 << "NSET\tFRONTBOTTOM = FRONTBOTTOM + SURFACE"<<pairTmp.first->tag()<<"\n";
//						file2 << "NSET\tBACKTOP = BACKTOP + SURFACE"<<associatedFace->tag()<<"\n";
//					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
//						file2 << "NSET\tFRONTTOP = FRONTTOP + SURFACE"<<pairTmp.first->tag()<<"\n";
//						file2 << "NSET\tBACKBOTTOM = BACKBOTTOM + SURFACE"<<associatedFace->tag()<<"\n";
//					}
//				}else if (abs((p2.y()-p1.y()-1.0))<0.0001){
//					if (abs((p2.z()-p1.z()))<0.0001){
//						file2 << "NSET\tFRONTLEFT = FRONTLEFT + SURFACE"<<pairTmp.first->tag()<<"\n";
//						file2 << "NSET\tBACKRIGHT = BACKRIGHT + SURFACE"<<associatedFace->tag()<<"\n";
//					}else if (abs((p2.z()-p1.z()-1.0))<0.0001){
//						file2 << "NSET\tFRONTLEFTBOTTOM = FRONTLEFTBOTTOM + SURFACE"<<pairTmp.first->tag()<<"\n";
//						file2 << "NSET\tBACKRIGHTTOP = BACKRIGHTTOP + SURFACE"<<associatedFace->tag()<<"\n";
//					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
//						file2 << "NSET\tFRONTLEFTTOP = FRONTLEFTTOP + SURFACE"<<pairTmp.first->tag()<<"\n";
//						file2 << "NSET\tBACKRIGHTBOTTOM = BACKRIGHTBOTTOM + SURFACE"<<associatedFace->tag()<<"\n";
//					}
//				}else if (abs((p1.y()-p2.y()-1.0))<0.0001){
//					if (abs((p2.z()-p1.z()))<0.0001){
//						file2 << "NSET\tFRONTRIGHT = FRONTRIGHT + SURFACE"<<pairTmp.first->tag()<<"\n";
//						file2 << "NSET\tBACKLEFT = BACKLEFT + SURFACE"<<associatedFace->tag()<<"\n";
//					}else if (abs((p2.z()-p1.z()-1.0))<0.0001){
//						file2 << "NSET\tFRONTRIGHTBOTTOM = FRONTRIGHTBOTTOM + SURFACE"<<pairTmp.first->tag()<<"\n";
//						file2 << "NSET\tBACKLEFTTOP = BACKLEFTTOP + SURFACE"<<associatedFace->tag()<<"\n";
//					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
//						file2 << "NSET\tFRONTRIGHTTOP = FRONTRIGHTTOP + SURFACE"<<pairTmp.first->tag()<<"\n";
//						file2 << "NSET\tBACKLEFTBOTTOM = BACKLEFTBOTTOM + SURFACE"<<associatedFace->tag()<<"\n";
//					}
//				}
//			}else if (abs((p1.x()-p2.x()))<0.0001){
//				if (abs((p2.y()-p1.y()-1.0))<0.0001){
//					if (abs((p2.z()-p1.z()))<0.0001){
//						file2 << "NSET\tRIGHT = RIGHT + SURFACE"<<associatedFace->tag()<<"\n";
//						file2 << "NSET\tLEFT = LEFT + SURFACE"<<pairTmp.first->tag()<<"\n";
//					}else if (abs((p2.z()-p1.z()-1.0))<0.0001){
//						file2 << "NSET\tRIGHTTOP = RIGHTTOP + SURFACE"<<associatedFace->tag()<<"\n";
//						file2 << "NSET\tLEFTBOTTOM = LEFTBOTTOM + SURFACE"<<pairTmp.first->tag()<<"\n";
//					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
//						file2 << "NSET\tRIGHTBOTTOM = RIGHTBOTTOM + SURFACE"<<associatedFace->tag()<<"\n";
//						file2 << "NSET\tLEFTTOP = LEFTTOP + SURFACE"<<pairTmp.first->tag()<<"\n";
//					}
//				}else if (abs((p1.y()-p2.y()-1.0))<0.0001){
//					if (abs((p2.z()-p1.z()))<0.0001){
//						file2 << "NSET\tRIGHT = RIGHT + SURFACE"<<pairTmp.first->tag()<<"\n";
//						file2 << "NSET\tLEFT = LEFT + SURFACE"<<associatedFace->tag()<<"\n";
//					}else if (abs((p2.z()-p1.z()-1.0))<0.0001){
//						file2 << "NSET\tRIGHTBOTTOM = RIGHTBOTTOM + SURFACE"<<pairTmp.first->tag()<<"\n";
//						file2 << "NSET\tLEFTTOP = LEFTTOP + SURFACE"<<associatedFace->tag()<<"\n";
//					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
//						file2 << "NSET\tRIGHTTOP = RIGHTTOP + SURFACE"<<pairTmp.first->tag()<<"\n";
//						file2 << "NSET\tLEFTBOTTOM = LEFTBOTTOM + SURFACE"<<associatedFace->tag()<<"\n";
//					}
//				}else if (abs((p1.y()-p2.y()))<0.0001){
//					if (abs((p2.z()-p1.z()-1.0))<0.0001){
//						file2 << "NSET\tTOP = TOP + SURFACE"<<associatedFace->tag()<<"\n";
//						file2 << "NSET\tBOTTOM = BOTTOM + SURFACE"<<pairTmp.first->tag()<<"\n";
//					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
//						file2 << "NSET\tTOP = TOP + SURFACE"<<pairTmp.first->tag()<<"\n";
//						file2 << "NSET\tBOTTOM = BOTTOM + SURFACE"<<associatedFace->tag()<<"\n";
//					}
//				}
//			}
////			count++;
//
//
//
//
//
//
//
//			newPairs.push_back(std::make_pair(pairTmp.first,associatedFace));
//		}
//	}
//	for (std::vector<std::pair<GFace*,GFace*> >::iterator itP = newPairs.begin();itP != newPairs.end();itP++){
//		std::pair<GFace*,GFace*> pairTmp = (*itP);
//	}

	std::cout<<"End of DuplicateBoundaries"<<std::endl;
	return view;
}

























PView *GMSH_DuplicateBoundariesPlugin::execute2DWithBound(PView *view)
{
	std::cout<<"starting DuplicateBoundaries"<<std::endl;
	GModel *m = GModel::current();
	m->setFactory("geo");
	std::set<GEdge*> ToDuplicateList;
	ToDuplicateList.clear();
	std::set<GEdge*> ToDuplicateListBoundary;
	ToDuplicateListBoundary.clear();
	std::vector<GFace*> facesBound;
	facesBound.clear();
	std::map<GFace*,SPoint3> centers;
	std::vector<std::pair<GFace*,GFace*> > pairs;
	std::vector<std::pair<GFace*,GFace*> > newPairs;
	int PhysicalInterface = m->setPhysicalName("Interface",2);
//	for (GModel::fiter itf= m->firstFace();itf != m->lastFace();itf++){
//		GFace* ftmp= (*itf);
//		std::list<GEdge*> edgesFace = ftmp->edges();
////		std::cout<<"size de edgesFace "<<edgesFace.size()<<std::endl;
//		for (std::list<GEdge*>::iterator it2=edgesFace.begin();it2!=edgesFace.end();it2++){
//			GEdge* etmp = (*it2);
////			std::cout<<"on a la edge "<<etmp->tag()<<std::endl;
////			std::cout<<"size de face de etmp before : "<<etmp->faces().size()<<std::endl;
//			etmp->addFace(ftmp);
////			std::cout<<"size de face de etmp after : "<<etmp->faces().size()<<std::endl;
//		}
//	}
	for (GModel::eiter ite= m->firstEdge();ite != m->lastEdge();ite++){
		GEdge* eTmp = (*ite);
//		std::cout<<"on a size de face de etmp de "<<eTmp->faces().size()<<std::endl;
		if (eTmp->faces().size() == 2){
			ToDuplicateList.insert(eTmp);
		}
		else{
			ToDuplicateListBoundary.insert(eTmp);
		}
	}










	std::map<std::pair<MVertex*,GFace*>,MVertex* > VertexGlobalAssociation;
	std::map<std::pair<GVertex*,GFace*>,GVertex* > GVertexGlobalAssociation;
	std::map<std::pair<GEdge*,GFace*>,GEdge* > GEdgeGlobalAssociation;
	std::map<std::pair<GFace*,GRegion*>,GFace* > GFaceGlobalAssociation;
//	std::cout<<"entree dans regions first pass"<<std::endl;
	for (GModel::fiter itr= m->firstFace();itr != m->lastFace();itr++){
		GFace* rTmp = (*itr);
		std::list<GEdge*> RegEdges = rTmp->edges();
		std::map<MVertex*,MVertex* > VertexAssociation;
		std::map<GVertex*,GVertex* > GVertexAssociation;
		std::map<GEdge*,GEdge* > GEdgeAssociation;
		//int counterNbDone = 10000;
		double xCenterReg = 0.0;
		double yCenterReg = 0.0;
		double zCenterReg = 0.0;
		int counterPts = 0;
		for(std::list<GEdge*>::iterator it2=RegEdges.begin();it2!=RegEdges.end();it2++){
			GEdge* fTemp = (*it2);
			std::list<GVertex*> verticesFace = fTemp->vertices();
			for (std::list<GVertex*>::iterator it3=verticesFace.begin();it3!=verticesFace.end();it3++){
				xCenterReg = xCenterReg + (*it3)->x();
				yCenterReg = yCenterReg + (*it3)->y();
				zCenterReg = zCenterReg + (*it3)->z();
				counterPts++;
			}
		}
		xCenterReg = xCenterReg/counterPts;
		yCenterReg = yCenterReg/counterPts;
		zCenterReg = zCenterReg/counterPts;
		//duplication noeud et aretes au niveau de la region directement
		std::list<GVertex*> vlist;


//		std::cout<<"wut 1"<<std::endl;
		std::list<GEdge*> listedgesTmp = rTmp->edges();
//		std::cout<<"listeEdge size "<<listedgesTmp.size()<<std::endl;
		for (std::list<GEdge*>::iterator itTp = listedgesTmp.begin();itTp != listedgesTmp.end();itTp++){
//			std::cout<<"wut 2"<<std::endl;
			std::list<GVertex*> vlist2;
//			std::cout<<"wut 3"<<std::endl;
			if(std::find(vlist.begin(), vlist.end(),(*itTp)->getBeginVertex()) == vlist.end())
				vlist.push_back((*itTp)->getBeginVertex());
			if(std::find(vlist.begin(), vlist.end(),(*itTp)->getEndVertex()) == vlist.end())
				vlist.push_back((*itTp)->getEndVertex());
//			vlist2 = (*itTp)->vertices();
//			std::cout<<"vlist2 size "<<vlist2.size()<<std::endl;
////			std::cout<<"wut 4"<<std::endl;
//			for (std::list<GVertex*>::iterator itTp2 = vlist2.begin();itTp2 != vlist2.end();itTp2++){
////				std::cout<<"wut 5"<<std::endl;
//				if(std::find(vlist.begin(), vlist.end(), *itTp2) == vlist.end())
//					vlist.push_back(*itTp2);
////				std::cout<<"wut 6"<<std::endl;
//			}
//			std::cout<<"wut 7"<<std::endl;
		}
//		std::cout<<"wut 8"<<std::endl;


//		std::cout<<"on a une taille vlist de "<<vlist.size()<<std::endl;
//		std::cout<<"init done entering vertices"<<std::endl;
		for (std::list<GVertex*>::iterator itv = vlist.begin();itv != vlist.end();itv++){
			//duplication Gvertex
			GVertex* vTmp = (*itv);
			double ponderatedX = 0.99999999999 * vTmp->x() + 0.00000000001 * xCenterReg;
			double ponderatedY = 0.99999999999 * vTmp->y() + 0.00000000001 * yCenterReg;
			double ponderatedZ = 0.99999999999 * vTmp->z() + 0.00000000001 * zCenterReg;
			GVertex* newv = m->addVertex(ponderatedX,ponderatedY,ponderatedZ,vTmp->prescribedMeshSizeAtVertex());
//			std::cout<<"inserted correspondance between : "<<vTmp->tag()<<" and : "<<newv->tag()<<std::endl;
			GVertexAssociation[vTmp] = newv;
			GVertexGlobalAssociation[std::make_pair(vTmp,rTmp)] = newv;
			//creation des Gedge correspondantes
//			GEdge* newE = m->addLine(vTmp,newv);
//			SurroudingEdges[vTmp] = newE;
			//maintenant traitement mesh
			MVertex *vMesh = vTmp->mesh_vertices[0];
			MVertex *newMv = new MVertex(vMesh->x(), vMesh->y(), vMesh->z(), (GEntity*)newv);
			VertexAssociation[vMesh] = newMv;
			VertexGlobalAssociation[std::make_pair(vMesh,rTmp)] = newMv;
			newv->addMeshVertex(newMv);
		}
		//maintenant on soccupe de duppliquer les edges de la region
		std::list<GEdge*> elist = rTmp->edges();
//		std::cout<<"on a une taille elist de "<<elist.size()<<std::endl;
//		std::cout<<"vertices done entering edges"<<std::endl;

		std::vector<GFace*> SurroundingsFaces;
//		for (std::list<GEdge*>::iterator ite = elist.begin();ite != elist.end();ite++){
//			//duplication Gedge
//			GEdge* eTmp = (*ite);
////			std::cout<<"before addline"<<std::endl;
////			std::cout<<"begin ID : "<<eTmp->getBeginVertex()->tag()<<" and end ID : "<<eTmp->getEndVertex()->tag()<<std::endl;
////			std::cout<<"corresponding begin ID : "<<GVertexAssociation[eTmp->getBeginVertex()]->tag()<<" and end ID : "<<GVertexAssociation[eTmp->getEndVertex()]->tag()<<std::endl;
//			GEdge* newE = m->addLine(GVertexAssociation[eTmp->getEndVertex()],GVertexAssociation[eTmp->getBeginVertex()]);
////			std::cout<<"after addline"<<std::endl;
//			GEdgeAssociation[eTmp] = newE;
//			GEdgeGlobalAssociation[std::make_pair(eTmp,rTmp)] = newE;
//			//creation des GFace correspondantes
////			GEdge* firstE = SurroudingEdges.find(eTmp->getEndVertex())->second;
////			GEdge* lastE = SurroudingEdges.find(eTmp->getBeginVertex())->second;
////			std::vector<GEdge*> VecEdgesTmp;
////			VecEdgesTmp.push_back(eTmp);
////			VecEdgesTmp.push_back(firstE);
////			VecEdgesTmp.push_back(newE);
////			VecEdgesTmp.push_back(lastE);
////			std::vector<std::vector<GEdge*> > VecOfVecTmp;
////			VecOfVecTmp.push_back(VecEdgesTmp);
////			GFace* newFaceTmp = m->addPlanarFace(VecOfVecTmp);
////			SurroundingsFaces.push_back(newFaceTmp);
//			//maintenant traitement mesh
//			for (int i = 0; i < eTmp->mesh_vertices.size();i++){
//				MVertex *vMesh = eTmp->mesh_vertices[i];
//				MVertex *newMv = new MVertex(vMesh->x(), vMesh->y(), vMesh->z(), (GEntity*)newE);
//				VertexAssociation[vMesh] = newMv;
//				VertexGlobalAssociation[std::make_pair(vMesh,rTmp)] = newMv;
//				newE->addMeshVertex(newMv);
//			}
////			std::cout<<"after newvertices"<<std::endl;
//			for (int i = 0; i < eTmp->getNumMeshElements();i++){
//				MElement* elem = eTmp->getMeshElement(i);
//				MVertex *firstETmp = VertexAssociation.find(elem->getVertex(0))->second;
//				MVertex *lastETmp = VertexAssociation.find(elem->getVertex(1))->second;
//				MVertex *midETmp = VertexAssociation.find(elem->getVertex(2))->second;
//				MLine3 *newLine = new MLine3(firstETmp,lastETmp,midETmp);
//				newE->addLine(newLine);
//			}
////			std::cout<<"after newMlines"<<std::endl;
//		}
//		std::cout<<"edges done entering faces"<<std::endl;
//		std::cout<<"RegEdges size : "<<RegEdges.size()<<std::endl;
		for (std::list<GEdge*>::iterator itf = RegEdges.begin();itf != RegEdges.end();itf++){
			GEdge* eTmp = (*itf);
//			std::vector<GEdge*> newEdgesVector;
//			std::list<GEdge*> elistFace = fTmp->edges();
//			for (std::list<GEdge*>::iterator ite = elistFace.begin();ite != elistFace.end();ite++){
//				GEdge* eTmp = (*ite);
//				GEdge* eToFind = GEdgeAssociation[eTmp];
//				newEdgesVector.push_back(eToFind);
//			}
//			std::vector<std::vector<GEdge*> > VecOfVec;
//			VecOfVec.push_back(newEdgesVector);
			//creation de la nouvelle face
//			std::cout<<"before newvertices"<<std::endl;
//			std::cout<<"beginvertex : "<<eTmp->getBeginVertex()->tag()<<std::endl;
//			std::cout<<"endvertex : "<<eTmp->getEndVertex()->tag()<<std::endl;
//			std::cout<<"associated begin "<<GVertexAssociation[eTmp->getBeginVertex()]->tag()<<std::endl;
//			std::cout<<"associated end "<<GVertexAssociation[eTmp->getEndVertex()]->tag()<<std::endl;
			GEdge* newE = m->addLine(GVertexAssociation[eTmp->getBeginVertex()],GVertexAssociation[eTmp->getEndVertex()]);
//			std::cout<<"plop1"<<std::endl;
			for (unsigned int i = 0; i < eTmp->mesh_vertices.size();i++){
//				std::cout<<"plop2"<<std::endl;
				MVertex *vMesh = eTmp->mesh_vertices[i];
//				std::cout<<"plop3"<<std::endl;
				MVertex *newMv = new MVertex(vMesh->x(), vMesh->y(), vMesh->z(), (GEntity*)newE);
//				std::cout<<"plop4"<<std::endl;
				VertexAssociation[vMesh] = newMv;
//				std::cout<<"plop5"<<std::endl;
				VertexGlobalAssociation[std::make_pair(vMesh,rTmp)] = newMv;
//				std::cout<<"plop6"<<std::endl;
				newE->addMeshVertex(newMv);
//				std::cout<<"plop7"<<std::endl;
			}
//			std::cout<<"after newvertices"<<std::endl;
			for (unsigned int i = 0; i < eTmp->getNumMeshElements();i++){
				MElement* elem = eTmp->getMeshElement(i);
				MVertex *firstETmp = VertexAssociation.find(elem->getVertex(0))->second;
				MVertex *lastETmp = VertexAssociation.find(elem->getVertex(1))->second;
				MVertex *midETmp = VertexAssociation.find(elem->getVertex(2))->second;
				MLine3 *newLine = new MLine3(firstETmp,lastETmp,midETmp);
				newE->addLine(newLine);
			}
//			std::cout<<"after addline"<<std::endl;
			GEdgeGlobalAssociation[std::make_pair(eTmp,rTmp)] = newE;
//			GEdge* GFaceAssociation = m->addPlanarFace(VecOfVec);
//			int tagTmp = GFaceAssociation->tag();
//			std::ostringstream ss;
//			ss << tagTmp;
////			char *intStr = itoa(tagTmp);
//			std::string nameSurf = "SURFACE";
////			nameSurf += std::string(intStr);
//			nameSurf += ss.str();
//			int PhysicalSurfaceTmp = m->setPhysicalName(nameSurf,2);
//			GFaceAssociation->addPhysicalEntity(PhysicalSurfaceTmp);
//			std::cout<<"on a associe a la face : "<<fTmp->tag()<<" la face : "<<GFaceAssociation->tag()<<std::endl;
//			//maintenant traitement mesh
//			for (int i = 0; i < fTmp->mesh_vertices.size();i++){
//				MVertex *vMesh = fTmp->mesh_vertices[i];
//				MVertex *newMv = new MVertex(vMesh->x(), vMesh->y(), vMesh->z(), (GEntity*)GFaceAssociation);
//				VertexAssociation[vMesh] = newMv;
//				VertexGlobalAssociation[std::make_pair(vMesh,rTmp)] = newMv;
//				GFaceAssociation->addMeshVertex(newMv);
//			}
//			for (int i = 0; i < fTmp->getNumMeshElements();i++){
//				MElement* elem = fTmp->getMeshElement(i);
//				MVertex *firstE = VertexAssociation.find(elem->getVertex(0))->second;
//				MVertex *secondE = VertexAssociation.find(elem->getVertex(1))->second;
//				MVertex *thirdE = VertexAssociation.find(elem->getVertex(2))->second;
//				MVertex *fourthE = VertexAssociation.find(elem->getVertex(3))->second;
//				MVertex *fifthE = VertexAssociation.find(elem->getVertex(4))->second;
//				MVertex *sisthE = VertexAssociation.find(elem->getVertex(5))->second;
//				MTriangle6 *newTri = new MTriangle6(firstE,secondE,thirdE,fourthE,fifthE,sisthE);
//				GFaceAssociation->addTriangle(newTri);
//			}
//			GFaceGlobalAssociation[std::make_pair(fTmp,rTmp)] = GFaceAssociation;
		}
//		std::cout<<"faces done for regions"<<std::endl;
	}
//	std::cout<<"Regions done first pass"<<std::endl;
	int counterNbDone = 10000;
	//maintenant on va traiter les faces initiales
	for (std::set<GEdge*>::iterator itf = ToDuplicateList.begin();itf != ToDuplicateList.end();itf++){
		counterNbDone++;
//		std::cout<<"entree dans toduplicateList numero "<<counterNbDone<<std::endl;
		GEdge* eTmp = (*itf);
		std::list<GFace*> listFacesTmpT = eTmp->faces();
//		std::cout<<"on a une taille de list faces de "<<listFacesTmpT.size()<<std::endl;
		std::list<GFace*>::iterator itTmpFace = listFacesTmpT.begin();
		GFace* fac1 = (*itTmpFace);
		itTmpFace++;
		GFace* fac2 = (*itTmpFace);
		//pour commencer on cree des aretes entre les vertex
//		std::list<GVertex*> vlist = eTmp->vertices();
		std::list<GVertex*> vlist;
		vlist.push_back(eTmp->getBeginVertex());
		vlist.push_back(eTmp->getEndVertex());
		std::map<GVertex*,GEdge* > SurroudingEdges;
//		std::cout<<"entre dans vlist.begin"<<std::endl;
		for (std::list<GVertex*>::iterator itv = vlist.begin();itv != vlist.end();itv++){
			GVertex* vTmp = (*itv);
//			std::cout<<"test1"<<std::endl;
//			std::cout<<"on a fac1 "<<fac1->tag()<<" et fac2 "<<fac2->tag()<<" et vTmp "<<vTmp->tag()<<std::endl;
			GVertex* v1;
			GVertex* v2;
			std::map<std::pair<GVertex*,GFace*>,GVertex* >::iterator itMap = GVertexGlobalAssociation.find(std::make_pair(vTmp,fac1));
//			std::cout<<"test2"<<std::endl;
			if (itMap != GVertexGlobalAssociation.end()){
				v1 = itMap->second;
//				std::cout<<"assigned v1"<<std::endl;
			}
//			std::cout<<"test3"<<std::endl;
			itMap = GVertexGlobalAssociation.find(std::make_pair(vTmp,fac2));
//			std::cout<<"test4"<<std::endl;
			if (itMap != GVertexGlobalAssociation.end()){
				v2 = itMap->second;
//				std::cout<<"assigned v2"<<std::endl;
			}
//			std::cout<<"test5"<<std::endl;
			GEdge* newE = m->addLine(v1,v2);
//			std::cout<<"test6"<<std::endl;
			SurroudingEdges[vTmp] = newE;
//			std::cout<<"test7"<<std::endl;
		}
//		std::cout<<"vertex traites"<<std::endl;
		//ici tous les vertex sont traites
		//on va traiter les edges
//		std::list<GEdge*> elist = fTmp->edges();
		std::vector<GEdge*> newEdgesVector;
		std::vector<GFace*> SurroundingsFaces;
		//duplication Gedge
		//			GEdge* eTmp = (*ite);
		GEdge* e1;
		GEdge* e2;
		std::map<std::pair<GEdge*,GFace*>,GEdge* >::iterator itMap = GEdgeGlobalAssociation.find(std::make_pair(eTmp,fac1));
		if (itMap != GEdgeGlobalAssociation.end()){
			e1 = itMap->second;
		}
		itMap = GEdgeGlobalAssociation.find(std::make_pair(eTmp,fac2));
		if (itMap != GEdgeGlobalAssociation.end()){
			e2 = itMap->second;
		}
//		std::cout<<"creation des GFace correspondantes"<<std::endl;
		//creation des GFace correspondantes
		GEdge* firstE = SurroudingEdges.find(eTmp->getBeginVertex())->second;
		GEdge* lastE = SurroudingEdges.find(eTmp->getEndVertex())->second;
		if (firstE->getBeginVertex() != e1->getEndVertex()){
			firstE->reverse();
		}
		if (firstE->getBeginVertex() != e1->getEndVertex()){
			e1->reverse();
		}
		if (firstE->getBeginVertex() != e1->getEndVertex()){
			firstE->reverse();
		}
		if (e2->getBeginVertex() != firstE->getEndVertex()){
			e2->reverse();
		}
		if (lastE->getBeginVertex() != e2->getEndVertex()){
			lastE->reverse();
		}
		std::vector<GEdge*> VecEdgesTmp;
		VecEdgesTmp.push_back(e1);
		VecEdgesTmp.push_back(firstE);
		VecEdgesTmp.push_back(e2);
		VecEdgesTmp.push_back(lastE);
		std::vector<std::vector<GEdge*> > VecOfVecTmp;
		VecOfVecTmp.push_back(VecEdgesTmp);
		GFace* newFaceTmp = m->addPlanarFace(VecOfVecTmp);
		//			SurroundingsFaces.push_back(newFaceTmp);

		//creation de la nouvelle region
//		GRegion* createdRegion = new GRegion(m,counterNbDone);
		newFaceTmp->addPhysicalEntity(PhysicalInterface);
//		createdRegion->set(listFaces);
//		m->add(createdRegion);
//		std::cout<<"eTmp->getNumMeshElements() "<<eTmp->getNumMeshElements()<<std::endl;
		for (unsigned int i = 0; i < eTmp->getNumMeshElements();i++){
			MElement* elem = eTmp->getMeshElement(i);
			MVertex* v1;
			MVertex* v2;
			MVertex* v3;
			MVertex* v4;
			//MVertex* v5;
			//MVertex* v6;
			std::map<std::pair<MVertex*,GFace*>,MVertex* >::iterator itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(0),fac1));
			if (itMap != VertexGlobalAssociation.end()){
				v1 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(2),fac1));
			if (itMap != VertexGlobalAssociation.end()){
				v2 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(2),fac2));
			if (itMap != VertexGlobalAssociation.end()){
				v3 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(0),fac2));
			if (itMap != VertexGlobalAssociation.end()){
				v4 = itMap->second;
			}
//			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(3),fac2));
//			if (itMap != VertexGlobalAssociation.end()){
//				v5 = itMap->second;
//			}
//			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(5),fac2));
//			if (itMap != VertexGlobalAssociation.end()){
//				v6 = itMap->second;
//			}
//			std::cout<<"creation de prisme "<<counterNbDone<<std::endl;
			MQuadrangle *newQua = new MQuadrangle(v1,v2,v3,v4);
//			std::cout<<"addition du quad "<<newQua->getNum()<<" avec les vertices "<<v1->getNum()<<" ; "<<v2->getNum()<<" ; "<<v3->getNum()<<" ; "<<v4->getNum()<<std::endl;
//			std::cout<<"addition de prisme "<<counterNbDone<<std::endl;

			newFaceTmp->addQuadrangle(newQua);
//			std::cout<<"fin de for"<<std::endl;

			//second
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(2),fac1));
			if (itMap != VertexGlobalAssociation.end()){
				v1 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(1),fac1));
			if (itMap != VertexGlobalAssociation.end()){
				v2 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(1),fac2));
			if (itMap != VertexGlobalAssociation.end()){
				v3 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(2),fac2));
			if (itMap != VertexGlobalAssociation.end()){
				v4 = itMap->second;
			}
			//			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(3),fac2));
			//			if (itMap != VertexGlobalAssociation.end()){
			//				v5 = itMap->second;
			//			}
			//			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(5),fac2));
			//			if (itMap != VertexGlobalAssociation.end()){
			//				v6 = itMap->second;
			//			}
			//			std::cout<<"creation de prisme "<<counterNbDone<<std::endl;
			MQuadrangle *newQua2 = new MQuadrangle(v1,v2,v3,v4);
//			std::cout<<"addition du quad "<<newQua2->getNum()<<" avec les vertices "<<v1->getNum()<<" ; "<<v2->getNum()<<" ; "<<v3->getNum()<<" ; "<<v4->getNum()<<std::endl;
			//			std::cout<<"addition de prisme "<<counterNbDone<<std::endl;

			newFaceTmp->addQuadrangle(newQua2);




		}
//		std::cout<<"apres region, refonte points "<<counterNbDone<<std::endl;
		for (unsigned int i = 0; i < fac1->getNumMeshElements();i++){
			MElement* elem = fac1->getMeshElement(i);
			for (int j = 0;j < elem->getNumVertices();j++){
				MVertex* vert = elem->getVertex(j);
				std::map<std::pair<MVertex*,GFace*>,MVertex* >::iterator itMap = VertexGlobalAssociation.find(std::make_pair(vert,fac1));
				if (itMap != VertexGlobalAssociation.end()){
//					std::cout<<"on va changer un point"<<std::endl;
					elem->setVertex(j,itMap->second);
//					std::cout<<"on a introduit "<<itMap->second->getNum()<<std::endl;
//					std::cout<<"maintenant elem j "<<elem->getVertex(j)->getNum()<<std::endl;
//					std::cout<<"youpi"<<std::endl;
				}
			}
		}
		for (unsigned int i = 0; i < fac2->getNumMeshElements();i++){
			MElement* elem = fac2->getMeshElement(i);
			for (int j = 0;j < elem->getNumVertices();j++){
				MVertex* vert = elem->getVertex(j);
				std::map<std::pair<MVertex*,GFace*>,MVertex* >::iterator itMap = VertexGlobalAssociation.find(std::make_pair(vert,fac2));
				if (itMap != VertexGlobalAssociation.end()){
//					std::cout<<"on va changer un point"<<std::endl;
					elem->setVertex(j,itMap->second);
//					std::cout<<"on a introduit "<<itMap->second->getNum()<<std::endl;
//					std::cout<<"maintenant elem j "<<elem->getVertex(j)->getNum()<<std::endl;
//					std::cout<<"youpi"<<std::endl;
				}
			}
		}
	}
//	std::cout<<"interior faces done"<<std::endl;








	//maintenant on va traiter les faces du bord
	for (std::set<GEdge*>::iterator itf = ToDuplicateListBoundary.begin();itf != ToDuplicateListBoundary.end();itf++){
		counterNbDone++;
		GEdge* eTmp = (*itf);
		std::list<GFace*> listFacesTmpT = eTmp->faces();
		std::list<GFace*>::iterator itTmpFace = listFacesTmpT.begin();
		GFace* fac1 = (*itTmpFace);
//		GFace* reg1 = fTmp->getRegion(0);
		//pour commencer on cree des aretes entre les vertex
		std::list<GVertex*> vlist;
		vlist.push_back(eTmp->getBeginVertex());
		vlist.push_back(eTmp->getEndVertex());
		std::map<GVertex*,GEdge* > SurroudingEdges;
		for (std::list<GVertex*>::iterator itv = vlist.begin();itv != vlist.end();itv++){
			GVertex* vTmp = (*itv);
			GVertex* v1;
			std::map<std::pair<GVertex*,GFace*>,GVertex* >::iterator itMap = GVertexGlobalAssociation.find(std::make_pair(vTmp,fac1));
			if (itMap != GVertexGlobalAssociation.end()){
				v1 = itMap->second;
			}
			GEdge* newE = m->addLine(v1,vTmp);
			SurroudingEdges[vTmp] = newE;
		}
		//ici tous les vertex sont traites
		//on va traiter les edges
//		std::list<GEdge*> elist = fTmp->edges();
		std::vector<GEdge*> newEdgesVector;
		std::vector<GFace*> SurroundingsFaces;
//		for (std::list<GEdge*>::iterator ite = elist.begin();ite != elist.end();ite++){
		//duplication Gedge
		//			GEdge* eTmp = (*ite);
		GEdge* e1;
		std::map<std::pair<GEdge*,GFace*>,GEdge* >::iterator itMap = GEdgeGlobalAssociation.find(std::make_pair(eTmp,fac1));
		if (itMap != GEdgeGlobalAssociation.end()){
			e1 = itMap->second;
		}
		//creation des GFace correspondantes
		GEdge* firstE = SurroudingEdges.find(eTmp->getBeginVertex())->second;
		GEdge* lastE = SurroudingEdges.find(eTmp->getEndVertex())->second;
		if (firstE->getBeginVertex() != e1->getEndVertex()){
			firstE->reverse();
		}
		if (firstE->getBeginVertex() != e1->getEndVertex()){
			e1->reverse();
		}
		if (firstE->getBeginVertex() != e1->getEndVertex()){
			firstE->reverse();
		}
		if (eTmp->getBeginVertex() != firstE->getEndVertex()){
			eTmp->reverse();
		}
		if (lastE->getBeginVertex() != eTmp->getEndVertex()){
			lastE->reverse();
		}
		std::vector<GEdge*> VecEdgesTmp;
		VecEdgesTmp.push_back(e1);
		VecEdgesTmp.push_back(firstE);
		VecEdgesTmp.push_back(eTmp);
		VecEdgesTmp.push_back(lastE);
		std::vector<std::vector<GEdge*> > VecOfVecTmp;
		VecOfVecTmp.push_back(VecEdgesTmp);
		GFace* newFaceTmp = m->addPlanarFace(VecOfVecTmp);
//		SurroundingsFaces.push_back(newFaceTmp);
//		}
		std::vector<GFace*> VectorFaces;
		std::list<GFace*> listFaces;
//		GFace* f1;
//		std::map<std::pair<GFace*,GRegion*>,GFace* >::iterator itMap = GFaceGlobalAssociation.find(std::make_pair(fTmp,reg1));
//		if (itMap != GFaceGlobalAssociation.end()){
//			f1 = itMap->second;
//		}
//		VectorFaces.push_back(f1);
//		listFaces.push_back(f1);
//		for (unsigned int i = 0;i < SurroundingsFaces.size();i++){
//			VectorFaces.push_back(SurroundingsFaces[i]);
//			listFaces.push_back(SurroundingsFaces[i]);
//		}
//		VectorFaces.push_back(fTmp);
//		listFaces.push_back(fTmp);
//		std::vector<std::vector<GFace*> > VecOfVecGFace;
//		VecOfVecGFace.push_back(VectorFaces);
//		//creation de la nouvelle region
//		GRegion* createdRegion = new GRegion(m,counterNbDone);
		newFaceTmp->addPhysicalEntity(PhysicalInterface);
//		createdRegion->set(listFaces);
//		m->add(createdRegion);
		for (unsigned int i = 0; i < eTmp->getNumMeshElements();i++){
			MElement* elem = eTmp->getMeshElement(i);
			MVertex* v1;
			MVertex* v2;
			//MVertex* v3;
			std::map<std::pair<MVertex*,GFace*>,MVertex* >::iterator itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(0),fac1));
			if (itMap != VertexGlobalAssociation.end()){
				v1 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(2),fac1));
			if (itMap != VertexGlobalAssociation.end()){
				v2 = itMap->second;
			}
			MQuadrangle *newQua = new MQuadrangle(v1,v2,elem->getVertex(2),elem->getVertex(0));
			newFaceTmp->addQuadrangle(newQua);
			//second
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(2),fac1));
			if (itMap != VertexGlobalAssociation.end()){
				v1 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(1),fac1));
			if (itMap != VertexGlobalAssociation.end()){
				v2 = itMap->second;
			}
			MQuadrangle *newQua2 = new MQuadrangle(v1,v2,elem->getVertex(1),elem->getVertex(2));
			newFaceTmp->addQuadrangle(newQua2);
		}
//		std::cout<<"apres region, refonte points "<<counterNbDone<<std::endl;
		for (unsigned int i = 0; i < fac1->getNumMeshElements();i++){
			MElement* elem = fac1->getMeshElement(i);
			for (int j = 0;j < elem->getNumVertices();j++){
				MVertex* vert = elem->getVertex(j);
				std::map<std::pair<MVertex*,GFace*>,MVertex* >::iterator itMap = VertexGlobalAssociation.find(std::make_pair(vert,fac1));
				if (itMap != VertexGlobalAssociation.end()){
//					std::cout<<"on va changer un point"<<std::endl;
					elem->setVertex(j,itMap->second);
//					std::cout<<"on a introduit "<<itMap->second->getNum()<<std::endl;
//					std::cout<<"maintenant elem j "<<elem->getVertex(j)->getNum()<<std::endl;
//					std::cout<<"youpi"<<std::endl;
				}
			}
		}
	}


















//	std::ofstream file("MicrostructurePolycrystal3D.pos");
//	file << "View \"test\" {\n";
//
//	std::ofstream file2("PERIODIC.map");
//	std::ofstream file3("SetAdd.map");
//	for (std::vector<std::pair<GFace*,GFace*> >::iterator itP = pairs.begin();itP != pairs.end();itP++){
//		std::pair<GFace*,GFace*> pairTmp = (*itP);
//		GFace* ToReplaceFace = pairTmp.second;
//		GRegion* rTmp = ToReplaceFace->getRegion(0);
//		std::map<std::pair<GFace*,GRegion*>,GFace* >::iterator itMap = GFaceGlobalAssociation.find(std::make_pair(ToReplaceFace,rTmp));
//		if (itMap != GFaceGlobalAssociation.end()){
//			GFace* associatedFace = (*itMap).second;
//
//
//
//
//
//			file3 <<associatedFace->tag()<<"\tSURFACE"<<associatedFace->tag()<<"\tNSET "<<"\n";
//
//			int tagTmp = associatedFace->tag();
//			std::ostringstream ss;
//			ss << tagTmp;
////			char *intStr = itoa(tagTmp);
//			std::string nameSurf = "SURFACE";
////			nameSurf += std::string(intStr);
//			nameSurf += ss.str();
//			int PhysicalSurfaceTmp = m->setPhysicalName(nameSurf,2);
//			associatedFace->addPhysicalEntity(PhysicalSurfaceTmp);
//
//			std::map<GFace*,SPoint3>::iterator it3 = centers.find(pairTmp.first);
//			std::map<GFace*,SPoint3>::iterator it4 = centers.find(ToReplaceFace);
//
//			SPoint3 p1 = it3->second;
//			SPoint3  p2 = it4->second;
//
//			double delta_x = fabs(p2.x()-p1.x());
//			double delta_y = fabs(p2.y()-p1.y());
//			double delta_z = fabs(p2.z()-p1.z());
//
//
//			file << "SL ("
//					<< p1.x() << ", " << p1.y() << ", " << p1.z() << ", "
//					<< p2.x() << ", " << p2.y() << ", " << p2.z()
//					<< "){10, 20};\n";
//
//			//file2 << "PERIODIC\tSURFACE"<<faces[i]->tag() << "\tSURFACE" << faces[j]->tag() << "\t" << p2.x()-p1.x() << "\t" << p2.y()-p1.y() << "\t" << p2.z()-p1.z() << "\n";
//			if (abs((p2.x()-p1.x()-1.0))<0.0001){
//				if (abs((p2.y()-p1.y()))<0.0001){
//					if (abs((p2.z()-p1.z()))<0.0001){
//						file2 << "NSET\tFRONT = FRONT + SURFACE"<<associatedFace->tag()<<"\n";
//						file2 << "NSET\tBACK = BACK + SURFACE"<<pairTmp.first->tag()<<"\n";
//					}else if(abs((p2.z()-p1.z()-1.0))<0.0001){
//						file2 << "NSET\tFRONTTOP = FRONTTOP + SURFACE"<<associatedFace->tag()<<"\n";
//						file2 << "NSET\tBACKBOTTOM = BACKBOTTOM + SURFACE"<<pairTmp.first->tag()<<"\n";
//					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
//						file2 << "NSET\tFRONTBOTTOM = FRONTBOTTOM + SURFACE"<<associatedFace->tag()<<"\n";
//						file2 << "NSET\tBACKTOP = BACKTOP + SURFACE"<<pairTmp.first->tag()<<"\n";
//					}
//				}else if (abs((p2.y()-p1.y()-1.0))<0.0001){
//					if (abs((p2.z()-p1.z()))<0.0001){
//						file2 << "NSET\tFRONTRIGHT = FRONTRIGHT + SURFACE"<<associatedFace->tag()<<"\n";
//						file2 << "NSET\tBACKLEFT = BACKLEFT + SURFACE"<<pairTmp.first->tag()<<"\n";
//					}else if (abs((p2.z()-p1.z()-1.0))<0.0001){
//						file2 << "NSET\tFRONTRIGHTTOP = FRONTRIGHTTOP + SURFACE"<<associatedFace->tag()<<"\n";
//						file2 << "NSET\tBACKLEFTBOTTOM = BACKLEFTBOTTOM + SURFACE"<<pairTmp.first->tag()<<"\n";
//					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
//						file2 << "NSET\tFRONTRIGHTBOTTOM = FRONTRIGHTBOTTOM + SURFACE"<<associatedFace->tag()<<"\n";
//						file2 << "NSET\tBACKLEFTTOP = BACKLEFTTOP + SURFACE"<<pairTmp.first->tag()<<"\n";
//					}
//				}else if (abs((p1.y()-p2.y()-1.0))<0.0001){
//					if (abs((p2.z()-p1.z()))<0.0001){
//						file2 << "NSET\tFRONTLEFT = FRONTLEFT + SURFACE"<<associatedFace->tag()<<"\n";
//						file2 << "NSET\tBACKRIGHT = BACKRIGHT + SURFACE"<<pairTmp.first->tag()<<"\n";
//					}else if (abs((p2.z()-p1.z()-1.0))<0.0001){
//						file2 << "NSET\tFRONTLEFTTOP = FRONTLEFTTOP + SURFACE"<<associatedFace->tag()<<"\n";
//						file2 << "NSET\tBACKRIGHTBOTTOM = BACKRIGHTBOTTOM + SURFACE"<<pairTmp.first->tag()<<"\n";
//					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
//						file2 << "NSET\tFRONTLEFTBOTTOM = FRONTLEFTBOTTOM + SURFACE"<<associatedFace->tag()<<"\n";
//						file2 << "NSET\tBACKRIGHTTOP = BACKRIGHTTOP + SURFACE"<<pairTmp.first->tag()<<"\n";
//					}
//				}
//			}else if (abs((p1.x()-p2.x()-1.0))<0.0001){
//				if (abs((p2.y()-p1.y()))<0.0001){
//					if (abs((p2.z()-p1.z()))<0.0001){
//						file2 << "NSET\tFRONT = FRONT + SURFACE"<<pairTmp.first->tag()<<"\n";
//						file2 << "NSET\tBACK = BACK + SURFACE"<<associatedFace->tag()<<"\n";
//					}else if(abs((p2.z()-p1.z()-1.0))<0.0001){
//						file2 << "NSET\tFRONTBOTTOM = FRONTBOTTOM + SURFACE"<<pairTmp.first->tag()<<"\n";
//						file2 << "NSET\tBACKTOP = BACKTOP + SURFACE"<<associatedFace->tag()<<"\n";
//					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
//						file2 << "NSET\tFRONTTOP = FRONTTOP + SURFACE"<<pairTmp.first->tag()<<"\n";
//						file2 << "NSET\tBACKBOTTOM = BACKBOTTOM + SURFACE"<<associatedFace->tag()<<"\n";
//					}
//				}else if (abs((p2.y()-p1.y()-1.0))<0.0001){
//					if (abs((p2.z()-p1.z()))<0.0001){
//						file2 << "NSET\tFRONTLEFT = FRONTLEFT + SURFACE"<<pairTmp.first->tag()<<"\n";
//						file2 << "NSET\tBACKRIGHT = BACKRIGHT + SURFACE"<<associatedFace->tag()<<"\n";
//					}else if (abs((p2.z()-p1.z()-1.0))<0.0001){
//						file2 << "NSET\tFRONTLEFTBOTTOM = FRONTLEFTBOTTOM + SURFACE"<<pairTmp.first->tag()<<"\n";
//						file2 << "NSET\tBACKRIGHTTOP = BACKRIGHTTOP + SURFACE"<<associatedFace->tag()<<"\n";
//					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
//						file2 << "NSET\tFRONTLEFTTOP = FRONTLEFTTOP + SURFACE"<<pairTmp.first->tag()<<"\n";
//						file2 << "NSET\tBACKRIGHTBOTTOM = BACKRIGHTBOTTOM + SURFACE"<<associatedFace->tag()<<"\n";
//					}
//				}else if (abs((p1.y()-p2.y()-1.0))<0.0001){
//					if (abs((p2.z()-p1.z()))<0.0001){
//						file2 << "NSET\tFRONTRIGHT = FRONTRIGHT + SURFACE"<<pairTmp.first->tag()<<"\n";
//						file2 << "NSET\tBACKLEFT = BACKLEFT + SURFACE"<<associatedFace->tag()<<"\n";
//					}else if (abs((p2.z()-p1.z()-1.0))<0.0001){
//						file2 << "NSET\tFRONTRIGHTBOTTOM = FRONTRIGHTBOTTOM + SURFACE"<<pairTmp.first->tag()<<"\n";
//						file2 << "NSET\tBACKLEFTTOP = BACKLEFTTOP + SURFACE"<<associatedFace->tag()<<"\n";
//					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
//						file2 << "NSET\tFRONTRIGHTTOP = FRONTRIGHTTOP + SURFACE"<<pairTmp.first->tag()<<"\n";
//						file2 << "NSET\tBACKLEFTBOTTOM = BACKLEFTBOTTOM + SURFACE"<<associatedFace->tag()<<"\n";
//					}
//				}
//			}else if (abs((p1.x()-p2.x()))<0.0001){
//				if (abs((p2.y()-p1.y()-1.0))<0.0001){
//					if (abs((p2.z()-p1.z()))<0.0001){
//						file2 << "NSET\tRIGHT = RIGHT + SURFACE"<<associatedFace->tag()<<"\n";
//						file2 << "NSET\tLEFT = LEFT + SURFACE"<<pairTmp.first->tag()<<"\n";
//					}else if (abs((p2.z()-p1.z()-1.0))<0.0001){
//						file2 << "NSET\tRIGHTTOP = RIGHTTOP + SURFACE"<<associatedFace->tag()<<"\n";
//						file2 << "NSET\tLEFTBOTTOM = LEFTBOTTOM + SURFACE"<<pairTmp.first->tag()<<"\n";
//					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
//						file2 << "NSET\tRIGHTBOTTOM = RIGHTBOTTOM + SURFACE"<<associatedFace->tag()<<"\n";
//						file2 << "NSET\tLEFTTOP = LEFTTOP + SURFACE"<<pairTmp.first->tag()<<"\n";
//					}
//				}else if (abs((p1.y()-p2.y()-1.0))<0.0001){
//					if (abs((p2.z()-p1.z()))<0.0001){
//						file2 << "NSET\tRIGHT = RIGHT + SURFACE"<<pairTmp.first->tag()<<"\n";
//						file2 << "NSET\tLEFT = LEFT + SURFACE"<<associatedFace->tag()<<"\n";
//					}else if (abs((p2.z()-p1.z()-1.0))<0.0001){
//						file2 << "NSET\tRIGHTBOTTOM = RIGHTBOTTOM + SURFACE"<<pairTmp.first->tag()<<"\n";
//						file2 << "NSET\tLEFTTOP = LEFTTOP + SURFACE"<<associatedFace->tag()<<"\n";
//					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
//						file2 << "NSET\tRIGHTTOP = RIGHTTOP + SURFACE"<<pairTmp.first->tag()<<"\n";
//						file2 << "NSET\tLEFTBOTTOM = LEFTBOTTOM + SURFACE"<<associatedFace->tag()<<"\n";
//					}
//				}else if (abs((p1.y()-p2.y()))<0.0001){
//					if (abs((p2.z()-p1.z()-1.0))<0.0001){
//						file2 << "NSET\tTOP = TOP + SURFACE"<<associatedFace->tag()<<"\n";
//						file2 << "NSET\tBOTTOM = BOTTOM + SURFACE"<<pairTmp.first->tag()<<"\n";
//					}else if (abs((p1.z()-p2.z()-1.0))<0.0001){
//						file2 << "NSET\tTOP = TOP + SURFACE"<<pairTmp.first->tag()<<"\n";
//						file2 << "NSET\tBOTTOM = BOTTOM + SURFACE"<<associatedFace->tag()<<"\n";
//					}
//				}
//			}
////			count++;
//
//
//
//
//
//
//
//			newPairs.push_back(std::make_pair(pairTmp.first,associatedFace));
//		}
//	}
//	for (std::vector<std::pair<GFace*,GFace*> >::iterator itP = newPairs.begin();itP != newPairs.end();itP++){
//		std::pair<GFace*,GFace*> pairTmp = (*itP);
//	}

	std::cout<<"End of DuplicateBoundaries"<<std::endl;
	return view;
}










































PView *GMSH_DuplicateBoundariesPlugin::executeTer(PView *view)
{
	std::cout<<"starting DuplicateBoundaries"<<std::endl;
	GModel *m = GModel::current();
	m->setFactory("geo");
	std::set<GFace*> ToDuplicateList;
	ToDuplicateList.clear();
	std::set<GFace*> ToDuplicateListBoundary;
	ToDuplicateListBoundary.clear();
	std::vector<GFace*> facesBound;
	facesBound.clear();
	std::map<GFace*,SPoint3> centers;
	std::vector<std::pair<GFace*,GFace*> > pairs;
	std::vector<std::pair<GFace*,GFace*> > newPairs;
	int PhysicalInterface = m->setPhysicalName("Interface",3);
	int PhysicalBoundary = m->setPhysicalName("Boundary",2);
	for (GModel::fiter itf= m->firstFace();itf != m->lastFace();itf++){
		GFace* fTmp = (*itf);
		if (fTmp->numRegions() == 2){
			ToDuplicateList.insert(fTmp);
		}
		else{
			ToDuplicateListBoundary.insert(fTmp);
			facesBound.push_back(fTmp);
		}
	}







	std::map<std::pair<MVertex*,GRegion*>,MVertex* > VertexGlobalAssociation;
	std::map<std::pair<GVertex*,GRegion*>,GVertex* > GVertexGlobalAssociation;
	std::map<std::pair<GEdge*,GRegion*>,GEdge* > GEdgeGlobalAssociation;
	std::map<std::pair<GFace*,GRegion*>,GFace* > GFaceGlobalAssociation;

	std::cout<<"entree dans regions first pass"<<std::endl;
	for (GModel::riter itr= m->firstRegion();itr != m->lastRegion();itr++){
		GRegion* rTmp = (*itr);
		std::list<GFace*> RegFaces = rTmp->faces();
		std::map<MVertex*,MVertex* > VertexAssociation;
		std::map<GVertex*,GVertex* > GVertexAssociation;
		std::map<GEdge*,GEdge* > GEdgeAssociation;
		//int counterNbDone = 10000;
		double xCenterReg = 0.0;
		double yCenterReg = 0.0;
		double zCenterReg = 0.0;
		int counterPts = 0;
		for(std::list<GFace*>::iterator it2=RegFaces.begin();it2!=RegFaces.end();it2++){
			GFace* fTemp = (*it2);
			std::list<GVertex*> verticesFace = fTemp->vertices();
			for (std::list<GVertex*>::iterator it3=verticesFace.begin();it3!=verticesFace.end();it3++){
				xCenterReg = xCenterReg + (*it3)->x();
				yCenterReg = yCenterReg + (*it3)->y();
				zCenterReg = zCenterReg + (*it3)->z();
				counterPts++;
			}
		}
		xCenterReg = xCenterReg/counterPts;
		yCenterReg = yCenterReg/counterPts;
		zCenterReg = zCenterReg/counterPts;
		//duplication noeud et aretes au niveau de la region directement
		std::list<GVertex*> vlist;


		std::cout<<"wut 1"<<std::endl;
		std::list<GFace*> listFacesTmp = rTmp->faces();
		for (std::list<GFace*>::iterator itTp = listFacesTmp.begin();itTp != listFacesTmp.end();itTp++){
			std::cout<<"wut 2"<<std::endl;
			std::list<GVertex*> vlist2;
			std::cout<<"wut 3"<<std::endl;
			vlist2 = (*itTp)->vertices();
			std::cout<<"wut 4"<<std::endl;
			for (std::list<GVertex*>::iterator itTp2 = vlist2.begin();itTp2 != vlist2.end();itTp2++){
				std::cout<<"wut 5"<<std::endl;
				if(std::find(vlist.begin(), vlist.end(), *itTp2) == vlist.end())
					vlist.push_back(*itTp2);
				std::cout<<"wut 6"<<std::endl;
			}
			std::cout<<"wut 7"<<std::endl;
		}
		std::cout<<"wut 8"<<std::endl;


		std::cout<<"on a une taille vlist de "<<vlist.size()<<std::endl;
		std::cout<<"init done entering vertices"<<std::endl;
		for (std::list<GVertex*>::iterator itv = vlist.begin();itv != vlist.end();itv++){
			//duplication Gvertex
			GVertex* vTmp = (*itv);
			double ponderatedX = 0.99999999999 * vTmp->x() + 0.00000000001 * xCenterReg;
			double ponderatedY = 0.99999999999 * vTmp->y() + 0.00000000001 * yCenterReg;
			double ponderatedZ = 0.99999999999 * vTmp->z() + 0.00000000001 * zCenterReg;
			GVertex* newv = m->addVertex(ponderatedX,ponderatedY,ponderatedZ,vTmp->prescribedMeshSizeAtVertex());
			std::cout<<"inserted correspondance between : "<<vTmp->tag()<<" and : "<<newv->tag()<<std::endl;
			GVertexAssociation[vTmp] = newv;
			GVertexGlobalAssociation[std::make_pair(vTmp,rTmp)] = newv;
			//creation des Gedge correspondantes
//			GEdge* newE = m->addLine(vTmp,newv);
//			SurroudingEdges[vTmp] = newE;
			//maintenant traitement mesh
			MVertex *vMesh = vTmp->mesh_vertices[0];
			MVertex *newMv = new MVertex(vMesh->x(), vMesh->y(), vMesh->z(), (GEntity*)newv);
			VertexAssociation[vMesh] = newMv;
			VertexGlobalAssociation[std::make_pair(vMesh,rTmp)] = newMv;
			newv->addMeshVertex(newMv);
		}
		//maintenant on soccupe de duppliquer les edges de la region
		std::list<GEdge*> elist = rTmp->edges();
		std::cout<<"on a une taille elist de "<<elist.size()<<std::endl;
		std::cout<<"vertices done entering edges"<<std::endl;

		std::vector<GFace*> SurroundingsFaces;
		for (std::list<GEdge*>::iterator ite = elist.begin();ite != elist.end();ite++){
			//duplication Gedge
			GEdge* eTmp = (*ite);
			std::cout<<"before addline"<<std::endl;
			std::cout<<"begin ID : "<<eTmp->getBeginVertex()->tag()<<" and end ID : "<<eTmp->getEndVertex()->tag()<<std::endl;
			std::cout<<"corresponding begin ID : "<<GVertexAssociation[eTmp->getBeginVertex()]->tag()<<" and end ID : "<<GVertexAssociation[eTmp->getEndVertex()]->tag()<<std::endl;
			GEdge* newE = m->addLine(GVertexAssociation[eTmp->getEndVertex()],GVertexAssociation[eTmp->getBeginVertex()]);
			std::cout<<"after addline"<<std::endl;
			GEdgeAssociation[eTmp] = newE;
			GEdgeGlobalAssociation[std::make_pair(eTmp,rTmp)] = newE;
			//creation des GFace correspondantes
//			GEdge* firstE = SurroudingEdges.find(eTmp->getEndVertex())->second;
//			GEdge* lastE = SurroudingEdges.find(eTmp->getBeginVertex())->second;
//			std::vector<GEdge*> VecEdgesTmp;
//			VecEdgesTmp.push_back(eTmp);
//			VecEdgesTmp.push_back(firstE);
//			VecEdgesTmp.push_back(newE);
//			VecEdgesTmp.push_back(lastE);
//			std::vector<std::vector<GEdge*> > VecOfVecTmp;
//			VecOfVecTmp.push_back(VecEdgesTmp);
//			GFace* newFaceTmp = m->addPlanarFace(VecOfVecTmp);
//			SurroundingsFaces.push_back(newFaceTmp);
			//maintenant traitement mesh
			for (unsigned int i = 0; i < eTmp->mesh_vertices.size();i++){
				MVertex *vMesh = eTmp->mesh_vertices[i];
				MVertex *newMv = new MVertex(vMesh->x(), vMesh->y(), vMesh->z(), (GEntity*)newE);
				VertexAssociation[vMesh] = newMv;
				VertexGlobalAssociation[std::make_pair(vMesh,rTmp)] = newMv;
				newE->addMeshVertex(newMv);
			}
			std::cout<<"after newvertices"<<std::endl;
			for (unsigned int i = 0; i < eTmp->getNumMeshElements();i++){
				MElement* elem = eTmp->getMeshElement(i);
				MVertex *firstETmp = VertexAssociation.find(elem->getVertex(0))->second;
				MVertex *lastETmp = VertexAssociation.find(elem->getVertex(1))->second;
				MLine *newLine = new MLine(firstETmp,lastETmp);
				newE->addLine(newLine);
			}
			std::cout<<"after newMlines"<<std::endl;
		}
		std::cout<<"edges done entering faces"<<std::endl;
		for (std::list<GFace*>::iterator itf = RegFaces.begin();itf != RegFaces.end();itf++){
			GFace* fTmp = (*itf);
			std::vector<GEdge*> newEdgesVector;
			std::list<GEdge*> elistFace = fTmp->edges();
			for (std::list<GEdge*>::iterator ite = elistFace.begin();ite != elistFace.end();ite++){
				GEdge* eTmp = (*ite);
				GEdge* eToFind = GEdgeAssociation[eTmp];
				newEdgesVector.push_back(eToFind);
			}
			std::vector<std::vector<GEdge*> > VecOfVec;
			VecOfVec.push_back(newEdgesVector);
			//creation de la nouvelle face
			GFace* GFaceAssociation = m->addPlanarFace(VecOfVec);
			//maintenant traitement mesh
			for (unsigned int i = 0; i < fTmp->mesh_vertices.size();i++){
				MVertex *vMesh = fTmp->mesh_vertices[i];
				MVertex *newMv = new MVertex(vMesh->x(), vMesh->y(), vMesh->z(), (GEntity*)GFaceAssociation);
				VertexAssociation[vMesh] = newMv;
				VertexGlobalAssociation[std::make_pair(vMesh,rTmp)] = newMv;
				GFaceAssociation->addMeshVertex(newMv);
			}
			for (unsigned int i = 0; i < fTmp->getNumMeshElements();i++){
				MElement* elem = fTmp->getMeshElement(i);
				MVertex *firstE = VertexAssociation.find(elem->getVertex(0))->second;
				MVertex *secondE = VertexAssociation.find(elem->getVertex(1))->second;
				MVertex *thirdE = VertexAssociation.find(elem->getVertex(2))->second;
				MTriangle *newTri = new MTriangle(firstE,secondE,thirdE);
				GFaceAssociation->addTriangle(newTri);
			}
			GFaceGlobalAssociation[std::make_pair(fTmp,rTmp)] = GFaceAssociation;
		}
		std::cout<<"faces done for regions"<<std::endl;
	}
	std::cout<<"Regions done first pass"<<std::endl;
	int counterNbDone = 10000;
	//maintenant on va traiter les faces initiales
	for (std::set<GFace*>::iterator itf = ToDuplicateList.begin();itf != ToDuplicateList.end();itf++){
		counterNbDone++;
		GFace* fTmp = (*itf);
		GRegion* reg1 = fTmp->getRegion(0);
		GRegion* reg2 = fTmp->getRegion(1);
		//pour commencer on cree des aretes entre les vertex
		std::list<GVertex*> vlist = fTmp->vertices();
		std::map<GVertex*,GEdge* > SurroudingEdges;
		for (std::list<GVertex*>::iterator itv = vlist.begin();itv != vlist.end();itv++){
			GVertex* vTmp = (*itv);
			GVertex* v1;
			GVertex* v2;
			std::map<std::pair<GVertex*,GRegion*>,GVertex* >::iterator itMap = GVertexGlobalAssociation.find(std::make_pair(vTmp,reg1));
			if (itMap != GVertexGlobalAssociation.end()){
				v1 = itMap->second;
			}
			itMap = GVertexGlobalAssociation.find(std::make_pair(vTmp,reg2));
			if (itMap != GVertexGlobalAssociation.end()){
				v2 = itMap->second;
			}
			GEdge* newE = m->addLine(v1,v2);
			SurroudingEdges[vTmp] = newE;
		}
		//ici tous les vertex sont traites
		//on va traiter les edges
		std::list<GEdge*> elist = fTmp->edges();
		std::vector<GEdge*> newEdgesVector;
		std::vector<GFace*> SurroundingsFaces;
		for (std::list<GEdge*>::iterator ite = elist.begin();ite != elist.end();ite++){
			//duplication Gedge
			GEdge* eTmp = (*ite);
			GEdge* e1;
			GEdge* e2;
			std::map<std::pair<GEdge*,GRegion*>,GEdge* >::iterator itMap = GEdgeGlobalAssociation.find(std::make_pair(eTmp,reg1));
			if (itMap != GEdgeGlobalAssociation.end()){
				e1 = itMap->second;
			}
			itMap = GEdgeGlobalAssociation.find(std::make_pair(eTmp,reg2));
			if (itMap != GEdgeGlobalAssociation.end()){
				e2 = itMap->second;
			}
			//creation des GFace correspondantes
			GEdge* firstE = SurroudingEdges.find(eTmp->getBeginVertex())->second;
			GEdge* lastE = SurroudingEdges.find(eTmp->getEndVertex())->second;
			if (firstE->getBeginVertex() != e1->getEndVertex()){
				firstE->reverse();
			}
			if (firstE->getBeginVertex() != e1->getEndVertex()){
				e1->reverse();
			}
			if (firstE->getBeginVertex() != e1->getEndVertex()){
				firstE->reverse();
			}
			if (e2->getBeginVertex() != firstE->getEndVertex()){
				e2->reverse();
			}
			if (lastE->getBeginVertex() != e2->getEndVertex()){
				lastE->reverse();
			}
			std::vector<GEdge*> VecEdgesTmp;
			VecEdgesTmp.push_back(e1);
			VecEdgesTmp.push_back(firstE);
			VecEdgesTmp.push_back(e2);
			VecEdgesTmp.push_back(lastE);
			std::vector<std::vector<GEdge*> > VecOfVecTmp;
			VecOfVecTmp.push_back(VecEdgesTmp);
			GFace* newFaceTmp = m->addPlanarFace(VecOfVecTmp);
			SurroundingsFaces.push_back(newFaceTmp);
		}
		std::vector<GFace*> VectorFaces;
		std::list<GFace*> listFaces;
		GFace* f1;
		GFace* f2;
		std::map<std::pair<GFace*,GRegion*>,GFace* >::iterator itMap = GFaceGlobalAssociation.find(std::make_pair(fTmp,reg1));
		if (itMap != GFaceGlobalAssociation.end()){
			f1 = itMap->second;
		}
		itMap = GFaceGlobalAssociation.find(std::make_pair(fTmp,reg2));
		if (itMap != GFaceGlobalAssociation.end()){
			f2 = itMap->second;
		}
		VectorFaces.push_back(f1);
		listFaces.push_back(f1);
		for (unsigned int i = 0;i < SurroundingsFaces.size();i++){
			VectorFaces.push_back(SurroundingsFaces[i]);
			listFaces.push_back(SurroundingsFaces[i]);
		}
		VectorFaces.push_back(f2);
		listFaces.push_back(f2);
		std::vector<std::vector<GFace*> > VecOfVecGFace;
		VecOfVecGFace.push_back(VectorFaces);
		//creation de la nouvelle region
		GRegion* createdRegion = new GRegion(m,counterNbDone);
		createdRegion->addPhysicalEntity(PhysicalInterface);
		createdRegion->set(listFaces);
		m->add(createdRegion);
		for (unsigned int i = 0; i < fTmp->getNumMeshElements();i++){
			MElement* elem = fTmp->getMeshElement(i);
			MVertex* v1;
			MVertex* v2;
			MVertex* v3;
			MVertex* v4;
			MVertex* v5;
			MVertex* v6;
			std::map<std::pair<MVertex*,GRegion*>,MVertex* >::iterator itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(0),reg1));
			if (itMap != VertexGlobalAssociation.end()){
				v1 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(1),reg1));
			if (itMap != VertexGlobalAssociation.end()){
				v2 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(2),reg1));
			if (itMap != VertexGlobalAssociation.end()){
				v3 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(0),reg2));
			if (itMap != VertexGlobalAssociation.end()){
				v4 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(1),reg2));
			if (itMap != VertexGlobalAssociation.end()){
				v5 = itMap->second;
			}
			itMap = VertexGlobalAssociation.find(std::make_pair(elem->getVertex(2),reg2));
			if (itMap != VertexGlobalAssociation.end()){
				v6 = itMap->second;
			}
//			std::cout<<"creation de prisme "<<counterNbDone<<std::endl;
			MPrism *newPri = new MPrism(v1,v2,v3,v4,v5,v6);
//			std::cout<<"addition de prisme "<<counterNbDone<<std::endl;

			createdRegion->addPrism(newPri);
//			std::cout<<"fin de for"<<std::endl;
		}
		std::cout<<"apres region, refonte points "<<counterNbDone<<std::endl;
		for (unsigned int i = 0; i < reg1->getNumMeshElements();i++){
			MElement* elem = reg1->getMeshElement(i);
			for (int j = 0;j < elem->getNumVertices();j++){
				MVertex* vert = elem->getVertex(j);
				std::map<std::pair<MVertex*,GRegion*>,MVertex* >::iterator itMap = VertexGlobalAssociation.find(std::make_pair(vert,reg1));
				if (itMap != VertexGlobalAssociation.end()){
//					std::cout<<"on va changer un point"<<std::endl;
					elem->setVertex(j,itMap->second);
//					std::cout<<"on a introduit "<<itMap->second->getNum()<<std::endl;
//					std::cout<<"maintenant elem j "<<elem->getVertex(j)->getNum()<<std::endl;
//					std::cout<<"youpi"<<std::endl;
				}
			}
		}
		for (unsigned int i = 0; i < reg2->getNumMeshElements();i++){
			MElement* elem = reg2->getMeshElement(i);
			for (int j = 0;j < elem->getNumVertices();j++){
				MVertex* vert = elem->getVertex(j);
				std::map<std::pair<MVertex*,GRegion*>,MVertex* >::iterator itMap = VertexGlobalAssociation.find(std::make_pair(vert,reg2));
				if (itMap != VertexGlobalAssociation.end()){
//					std::cout<<"on va changer un point"<<std::endl;
					elem->setVertex(j,itMap->second);
//					std::cout<<"on a introduit "<<itMap->second->getNum()<<std::endl;
//					std::cout<<"maintenant elem j "<<elem->getVertex(j)->getNum()<<std::endl;
//					std::cout<<"youpi"<<std::endl;
				}
			}
		}
	}
	std::cout<<"interior faces done"<<std::endl;

	for (std::set<GFace*>::iterator itf = ToDuplicateListBoundary.begin();itf != ToDuplicateListBoundary.end();itf++){
		GFace* fTmp = (*itf);
		GRegion* reg1 = fTmp->getRegion(0);
		std::map<std::pair<GFace*,GRegion*>,GFace* >::iterator itMap = GFaceGlobalAssociation.find(std::make_pair(fTmp,reg1));
		GFace* f1 = itMap->second;
		f1->addPhysicalEntity(PhysicalBoundary);
	}


	std::cout<<"End of DuplicateBoundaries"<<std::endl;
	return view;
}

PView *GMSH_DuplicateBoundariesPlugin::ComputeBestSeeds(PView *view)
{
	std::cout<<"starting DuplicateBoundaries"<<std::endl;
	GModel *m = GModel::current();
	m->setFactory("geo");
	return view;
}

