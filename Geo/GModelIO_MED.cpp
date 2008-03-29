// $Id: GModelIO_MED.cpp,v 1.18 2008-03-29 10:19:36 geuzaine Exp $
//
// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include <string>
#include "GModel.h"
#include "Message.h"

#if defined(HAVE_MED)

#include <map>
#include <sstream>
#include <vector>
#include <cstring>
#include "MElement.h"
#include "MVertex.h"
#include "discreteVertex.h"

extern "C" {
#include <med.h>
}

static int getTypeForMED(int msh, med_geometrie_element &med)
{
  switch(msh) {
  case MSH_LIN_2: med = MED_SEG2; return 2; 
  case MSH_TRI_3: med = MED_TRIA3; return 3; 
  case MSH_QUA_4: med = MED_QUAD4; return 4; 
  case MSH_TET_4: med = MED_TETRA4; return 4; 
  case MSH_HEX_8: med = MED_HEXA8; return 8; 
  case MSH_PRI_6: med = MED_PENTA6; return 6; 
  case MSH_PYR_5: med = MED_PYRA5; return 5; 
  case MSH_LIN_3: med = MED_SEG3; return 3; 
  case MSH_TRI_6: med = MED_TRIA6; return 6; 
  case MSH_TET_10: med = MED_TETRA10; return 10;
  case MSH_PNT: med = MED_POINT1; return 1; 
  case MSH_QUA_8: med = MED_QUAD8; return 8; 
  case MSH_HEX_20: med = MED_HEXA20; return 20;
  case MSH_PRI_15: med = MED_PENTA15; return 15;
  case MSH_PYR_13: med = MED_PYRA13; return 13;
  default: med = MED_NONE; return 0; 
  }
}

int GModel::readMED(const std::string &name)
{
  med_idt fid = MEDouvrir((char*)name.c_str(), MED_LECTURE);
  if(fid < 0) {
    Msg(GERROR, "Unable to open file '%s'", name.c_str());
    return 0;
  }
  
  int numMeshes = MEDnMaa(fid);
  if(!numMeshes){
    Msg(INFO, "No mesh found in MED file");
    return 0;
  }
  if(numMeshes > 1)
    Msg(WARNING, "Reading mesh 1 of %d (ignoring the others)", numMeshes);

  // read mesh info
  char meshName[MED_TAILLE_NOM + 1], meshDesc[MED_TAILLE_DESC + 1];
  med_int meshDim;
  med_maillage meshType;
  if(MEDmaaInfo(fid, 1, meshName, &meshDim, &meshType, meshDesc) < 0){
    Msg(GERROR, "Unable to read mesh information");
    return 0;
  }

  if(meshType == MED_NON_STRUCTURE){
    Msg(INFO, "Reading %d-D unstructured mesh <<%s>>", meshDim, meshName);
  }
  else{
    Msg(GERROR, "Cannot read structured mesh");
    return 0;
  }

  // read nodes
  med_int numNodes = MEDnEntMaa(fid, meshName, MED_COOR, MED_NOEUD, MED_NONE,
				MED_NOD);
  if(numNodes < 0){
    Msg(GERROR, "Could not read number of MED nodes");
    return 0;
  }
  if(numNodes == 0){
    Msg(GERROR, "No nodes in MED mesh");
    return 0;
  }
  std::vector<MVertex*> verts(numNodes);
  std::vector<med_float> coord(meshDim * numNodes);
  std::vector<char> coordName(meshDim * MED_TAILLE_PNOM + 1);
  std::vector<char> coordUnit(meshDim * MED_TAILLE_PNOM + 1);
  med_repere rep;
  if(MEDcoordLire(fid, meshName, meshDim, &coord[0], MED_FULL_INTERLACE,
		  MED_ALL, 0, 0, &rep, &coordName[0], &coordUnit[0]) < 0){
    Msg(GERROR, "Could not read MED node coordinates");
    return 0;
  }
  std::vector<med_int> nodeTags(numNodes);
  if(MEDnumLire(fid, meshName, &nodeTags[0], numNodes, MED_NOEUD, MED_NONE) < 0)
    nodeTags.clear();
  for(int i = 0; i < numNodes; i++)
    verts[i] = new MVertex(coord[meshDim * i], 
			   (meshDim > 1) ? coord[meshDim * i + 1] : 0., 
			   (meshDim > 2) ? coord[meshDim * i + 2] : 0.,
			   0, nodeTags.empty() ? 0 : nodeTags[i]);
  // read elements
  for(int mshType = 0; mshType < 50; mshType++){ // loop over all possible MSH types
    med_geometrie_element type;
    int numNodPerEle = getTypeForMED(mshType, type);
    if(type == MED_NONE) continue;
    med_int numEle = MEDnEntMaa(fid, meshName, MED_CONN, MED_MAILLE, type, MED_NOD);
    if(numEle <= 0) continue;
    std::vector<med_int> conn(numEle * numNodPerEle);
    if(MEDconnLire(fid, meshName, meshDim, &conn[0], MED_FULL_INTERLACE, 0, MED_ALL,
		   MED_MAILLE, type, MED_NOD) < 0) {
      Msg(GERROR, "Could not read MED elements");
      return 0;
    }
    std::vector<med_int> fam(numEle);
    if(MEDfamLire(fid, meshName, &fam[0], numEle, MED_MAILLE, type) < 0) {
      Msg(GERROR, "Could not read MED families");
      return 0;
    }
    std::vector<med_int> eleTags(numEle);
    if(MEDnumLire(fid, meshName, &eleTags[0], numEle, MED_MAILLE, type) < 0)
      eleTags.clear();
    if(numNodPerEle == 1){ // special case for points
      for(int j = 0; j < numEle; j++){    
	GVertex *v = getVertexByTag(-fam[j]);
	if(!v){
	  v = new discreteVertex(this, -fam[j]);
	  add(v);
	}
	v->mesh_vertices.push_back(verts[conn[j] - 1]);
      }
    }
    else{
      std::map<int, std::vector<MElement*> > elements;
      MElementFactory factory;
      for(int j = 0; j < numEle; j++){    
	std::vector<MVertex*> v(numNodPerEle);
	for(int k = 0; k < numNodPerEle; k++)
	  v[k] = verts[conn[numNodPerEle * j + k] - 1];
	MElement *e = factory.create(mshType, v, eleTags.empty() ? 0 : eleTags[j]);
	if(e) elements[-fam[j]].push_back(e);
      }
      _storeElementsInEntities(elements);
    }
  }
  _associateEntityWithMeshVertices();
  for(unsigned int i = 0; i < verts.size(); i++){
    GEntity *ge = verts[i]->onWhat();
    if(ge && ge->dim() > 0) ge->mesh_vertices.push_back(verts[i]);
    if(!ge) delete verts[i]; // delete unused vertices
  }

  // read family info
  med_int numFamilies = MEDnFam(fid, meshName);
  if(numFamilies < 0) {
    Msg(GERROR, "Could not read MED families");
    return 0;
  }
  for(int i = 0; i < numFamilies; i++) {
    med_int numAttrib = MEDnAttribut(fid, meshName, i + 1);
    med_int numGroups = MEDnGroupe(fid, meshName, i + 1);
    if(numAttrib < 0 || numGroups < 0){
      Msg(GERROR, "Could not read MED groups or attributes");
      return 0;
    }
    if(numGroups > 0){ // get physicals
      std::vector<med_int> attribId(numAttrib + 1);
      std::vector<med_int> attribVal(numAttrib + 1);
      std::vector<char> attribDes(MED_TAILLE_DESC * numAttrib + 1);
      std::vector<char> groupNames(MED_TAILLE_LNOM * numGroups + 1);
      char familyName[MED_TAILLE_NOM + 1];
      med_int familyNum;
      if(MEDfamInfo(fid, meshName, i + 1, familyName, &familyNum, &attribId[0], 
		    &attribVal[0], &attribDes[0], &numAttrib, &groupNames[0],
		    &numGroups) < 0) {
	Msg(GERROR, "Could not read info for MED family %d", i + 1);
      }
      else{
	GEntity *ge; // family tags are unique (for all dims)
	if((ge = getRegionByTag(-familyNum))){}
	else if((ge = getFaceByTag(-familyNum))){}
	else if((ge = getEdgeByTag(-familyNum))){}
	else ge = getVertexByTag(-familyNum);
	if(ge){
	  for(int j = 0; j < numGroups; j++) {
	    char tmp[MED_TAILLE_LNOM + 1];
	    strncpy(tmp, &groupNames[j * MED_TAILLE_LNOM], MED_TAILLE_LNOM);
	    tmp[MED_TAILLE_LNOM] = '\0';
	    ge->physicals.push_back(setPhysicalName(tmp));
	  }
	}
      }
    }
  }

  // check if we need to read some post-processing data later
  bool postpro = (MEDnChamp(fid, 0) > 0) ? true : false;
  
  if(MEDfermer(fid) < 0){
    Msg(GERROR, "Unable to close file '%s'", (char*)name.c_str());
    return 0;
  }
  
  return postpro ? 2 : 1;
}

template<class T>
static void fillElementsMED(med_int family, std::vector<T*> &elements, med_int &ele, 
			    std::vector<med_int> &num, std::vector<med_int> &conn,
			    std::vector<med_int> &fam, med_geometrie_element &type)
{
  for(unsigned int i = 0; i < elements.size(); i++){
    num.push_back(++ele);
    for(int j = 0; j < elements[i]->getNumVertices(); j++)
      conn.push_back(elements[i]->getVertexMED(j)->getNum());
    fam.push_back(family);
    if(!i) getTypeForMED(elements[i]->getTypeForMSH(), type);
  }
}

static void writeElementsMED(med_idt &fid, char *meshName,
			     std::vector<med_int> &num, std::vector<med_int> &conn, 
			     std::vector<med_int> &fam, med_geometrie_element type)
{
  if(num.empty()) return;
  if(MEDelementsEcr(fid, meshName, (med_int)3, &conn[0], MED_FULL_INTERLACE,
		    0, MED_FAUX, 0, MED_FAUX, &fam[0], (med_int)num.size(),
		    MED_MAILLE, type, MED_NOD) < 0)
    Msg(GERROR, "Could not write elements");
}

int GModel::writeMED(const std::string &name, bool saveAll, double scalingFactor)
{
  med_idt fid = MEDouvrir((char*)name.c_str(), MED_CREATION);
  if(fid < 0) {
    Msg(GERROR, "Unable to open file '%s'", name.c_str());
    return 0;
  }

  // write header
  if(MEDfichDesEcr(fid, (char*)"MED file generated by Gmsh") < 0) {
    Msg(GERROR, "Unable to write MED descriptor");
    return 0;
  }

  char *meshName = (char*)getName().c_str();
  
  // create 3D unstructured mesh
  if(MEDmaaCr(fid, meshName, 3, MED_NON_STRUCTURE, (char*)"gmsh") < 0){
    Msg(GERROR, "Could not create MED mesh");
    return 0;
  }
  
  // if there are no physicals we save all the elements
  if(noPhysicalGroups()) saveAll = true;

  // renumber the vertices we will save in a continuous sequence (MED
  // connectivity is given in terms of vertex indices)
  renumberMeshVertices(saveAll);

  // fill a vector containing all the geometrical entities in the model
  std::vector<GEntity*> entities;
  entities.insert(entities.end(), vertices.begin(), vertices.end());
  entities.insert(entities.end(), edges.begin(), edges.end());
  entities.insert(entities.end(), faces.begin(), faces.end());
  entities.insert(entities.end(), regions.begin(), regions.end());

  std::map<GEntity*, int> families;

  // write the families
  {
    // always create a "0" family, with no groups or attributes
    if(MEDfamCr(fid, meshName, (char*)"F_0", 0, 0, 0, 0, 0, 0, 0) < 0)
      Msg(GERROR, "Could not create MED family 0");

    // create one family per elementary entity, with one group per
    // physical entity and no attributes
    for(unsigned int i = 0; i < entities.size(); i++){
      if(saveAll || entities[i]->physicals.size()){
	int num = - (families.size() + 1);
	families[entities[i]] = num;
	std::ostringstream fs;
	fs << entities[i]->dim() << "D_" << entities[i]->tag();
	std::string familyName = "F_" + fs.str();
	std::string groupName;
	for(unsigned j = 0; j < entities[i]->physicals.size(); j++){
	  std::string tmp = getPhysicalName(entities[i]->physicals[j]);
	  std::ostringstream gs;
	  gs << entities[i]->dim() << "D_" << tmp;
	  if(tmp.empty()) gs << entities[i]->physicals[j];
	  groupName += "G_" + gs.str();
	  groupName.resize((j + 1) * 80, ' ');
	}
	if(MEDfamCr(fid, meshName, (char*)familyName.c_str(), 
		    (med_int)num, 0, 0, 0, 0, (char*)groupName.c_str(),
		    (med_int)entities[i]->physicals.size()) < 0)
	  Msg(GERROR, "Could not create MED family %d", num);
      }
    }
  }
  
  // write the nodes
  {
    std::vector<med_float> coord;
    std::vector<med_int> num, fam;
    for(unsigned int i = 0; i < entities.size(); i++){
      for(unsigned int j = 0; j < entities[i]->mesh_vertices.size(); j++){
	MVertex *v = entities[i]->mesh_vertices[j];
	if(v->getNum() >= 0){
	  coord.push_back(v->x() * scalingFactor);
	  coord.push_back(v->y() * scalingFactor);
	  coord.push_back(v->z() * scalingFactor);
	  num.push_back(v->getNum());
	  fam.push_back(0); // we never create node families
	}
      }
    }
    if(num.empty()){
      Msg(GERROR, "No nodes to write in MED mesh");
      return 0;
    }
    char coordName[3 * MED_TAILLE_PNOM + 1] = 
      "x               y               z               ";
    char coordUnit[3 * MED_TAILLE_PNOM + 1] = 
      "unknown         unknown         unknown         ";
    if(MEDnoeudsEcr(fid, meshName, (med_int)3, &coord[0], MED_FULL_INTERLACE, 
		    MED_CART, coordName, coordUnit, 0, MED_FAUX, &num[0], 
		    MED_VRAI, &fam[0], (med_int)num.size()) < 0)
      Msg(GERROR, "Could not write nodes");
  }
  
  // write the elements
  {
    med_geometrie_element typ;
    med_int ele = 0;

    { // points
      std::vector<med_int> num, conn, fam;
      for(viter it = firstVertex(); it != lastVertex(); it++){
	if(saveAll || (*it)->physicals.size()){
	  num.push_back(++ele);
	  conn.push_back((*it)->mesh_vertices[0]->getNum());
	  fam.push_back(families[*it]);
	}
      }
      writeElementsMED(fid, meshName, num, conn, fam, MED_POINT1);
    }
    { // lines
      std::vector<med_int> num, conn, fam;
      for(eiter it = firstEdge(); it != lastEdge(); it++)
	if(saveAll || (*it)->physicals.size())
	  fillElementsMED(families[*it], (*it)->lines, ele, num, conn, fam, typ);
      writeElementsMED(fid, meshName, num, conn, fam, typ);
    }
    { // triangles
      std::vector<med_int> num, conn, fam;
      for(fiter it = firstFace(); it != lastFace(); it++)
	if(saveAll || (*it)->physicals.size())
	  fillElementsMED(families[*it], (*it)->triangles, ele, num, conn, fam, typ);
      writeElementsMED(fid, meshName, num, conn, fam, typ);
    }
    { // quads
      std::vector<med_int> num, conn, fam;
      for(fiter it = firstFace(); it != lastFace(); it++)
	if(saveAll || (*it)->physicals.size())
	  fillElementsMED(families[*it], (*it)->quadrangles, ele, num, conn, fam, typ);
      writeElementsMED(fid, meshName, num, conn, fam, typ);
    }
    { // tets
      std::vector<med_int> num, conn, fam;
      for(riter it = firstRegion(); it != lastRegion(); it++)
	if(saveAll || (*it)->physicals.size())
	  fillElementsMED(families[*it], (*it)->tetrahedra, ele, num, conn, fam, typ);
      writeElementsMED(fid, meshName, num, conn, fam, typ);
    }
    { // hexas
      std::vector<med_int> num, conn, fam;
      for(riter it = firstRegion(); it != lastRegion(); it++)
	if(saveAll || (*it)->physicals.size())
	  fillElementsMED(families[*it], (*it)->hexahedra, ele, num, conn, fam, typ);
      writeElementsMED(fid, meshName, num, conn, fam, typ);
    }
    { // prisms
      std::vector<med_int> num, conn, fam;
      for(riter it = firstRegion(); it != lastRegion(); it++)
	if(saveAll || (*it)->physicals.size())
	  fillElementsMED(families[*it], (*it)->prisms, ele, num, conn, fam, typ);
      writeElementsMED(fid, meshName, num, conn, fam, typ);
    }
    { // pyramids
      std::vector<med_int> num, conn, fam;
      for(riter it = firstRegion(); it != lastRegion(); it++)
	if(saveAll || (*it)->physicals.size())
	  fillElementsMED(families[*it], (*it)->pyramids, ele, num, conn, fam, typ);
      writeElementsMED(fid, meshName, num, conn, fam, typ);
    }
  }
  
  if(MEDfermer(fid) < 0){
    Msg(GERROR, "Unable to close file '%s'", (char*)name.c_str());
    return 0;
  }
  
  return 1;
}

#else

int GModel::readMED(const std::string &name)
{
  Msg(GERROR, "Gmsh has to be compiled with MED support to read '%s'",
      name.c_str());
  return 0;
}

int GModel::writeMED(const std::string &name, bool saveAll, double scalingFactor)
{
  Msg(GERROR, "Gmsh has to be compiled with MED support to write '%s'",
      name.c_str());
  return 0;
}

#endif
