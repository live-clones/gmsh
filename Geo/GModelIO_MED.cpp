// $Id: GModelIO_MED.cpp,v 1.27 2008-04-13 09:45:48 geuzaine Exp $
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

med_geometrie_element msh2medElementType(int msh)
{
  switch(msh) {
  case MSH_LIN_2: return MED_SEG2;
  case MSH_TRI_3: return MED_TRIA3;
  case MSH_QUA_4: return MED_QUAD4;
  case MSH_TET_4: return MED_TETRA4;
  case MSH_HEX_8: return MED_HEXA8;
  case MSH_PRI_6: return MED_PENTA6;
  case MSH_PYR_5: return MED_PYRA5;
  case MSH_LIN_3: return MED_SEG3;
  case MSH_TRI_6: return MED_TRIA6;
  case MSH_TET_10: return MED_TETRA10;
  case MSH_PNT: return MED_POINT1;
  case MSH_QUA_8: return MED_QUAD8;
  case MSH_HEX_20: return MED_HEXA20;
  case MSH_PRI_15: return MED_PENTA15;
  case MSH_PYR_13: return MED_PYRA13;
  default: return MED_NONE;
  }
}

int med2mshElementType(med_geometrie_element med)
{
  switch(med) {
  case MED_SEG2: return MSH_LIN_2;
  case MED_TRIA3: return MSH_TRI_3;
  case MED_QUAD4: return MSH_QUA_4;
  case MED_TETRA4: return MSH_TET_4;
  case MED_HEXA8: return MSH_HEX_8;
  case MED_PENTA6: return MSH_PRI_6;
  case MED_PYRA5: return MSH_PYR_5;
  case MED_SEG3: return MSH_LIN_3;
  case MED_TRIA6: return MSH_TRI_6;
  case MED_TETRA10: return MSH_TET_10;
  case MED_POINT1: return MSH_PNT;
  case MED_QUAD8: return MSH_QUA_8;
  case MED_HEXA20: return MSH_HEX_20;
  case MED_PENTA15: return MSH_PRI_15;
  case MED_PYRA13: return MSH_PYR_13;
  default: return 0;
  }
}

int med2mshNodeIndex(med_geometrie_element med, int k)
{
  switch(med) {
  case MED_SEG2: return k;
  case MED_TRIA3: {
    static const int map[3] = {0, 2, 1}; 
    return map[k]; 
  }
  case MED_QUAD4: { 
    static const int map[4] = {0, 3, 2, 1};
    return map[k];
  }
  case MED_TETRA4: {
    static const int map[4] = {0, 2, 1, 3};
    return map[k];
  }
  case MED_HEXA8: {
    static const int map[8] = {0, 3, 2, 1, 4, 7, 6, 5};
    return map[k];
  }
  case MED_PENTA6: {
    static const int map[6] = {0, 2, 1, 3, 5, 4};
    return map[k];
  }
  case MED_PYRA5: {
    static const int map[5] = {0, 3, 2, 1, 4};
    return map[k];
  }
  case MED_SEG3: return k;
  case MED_TRIA6: {
    static const int map[6] = {0, 2, 1, 5, 4, 3};
    return map[k];
  }
  case MED_TETRA10: {
    static const int map[10] = {0, 2, 1, 3, 6, 5, 4, 7, 8, 9};
    return map[k];
  }
  case MED_POINT1: return k;
  case MED_QUAD8: {
    static const int map[8] = {0, 3, 2, 1, 7, 6, 5, 4};
    return map[k];
  }
  case MED_HEXA20: {
    static const int map[20] = {0, 3, 2, 1, 4, 7, 6, 5, 11, 8, 16,
				10, 19, 9, 18, 17, 15, 12, 14, 13};
    return map[k];
  }
  case MED_PENTA15: {
    static const int map[15] = {0, 2, 1, 3, 5, 4, 8, 6, 12, 7, 14, 13, 11, 9, 10};
    return map[k];
  }
  case MED_PYRA13: {
    static const int map[13] = {0, 3, 2, 1, 4, 8, 5, 9, 7, 12, 6, 11, 10};
    return map[k];
  }
  default:
    Msg(GERROR, "Unknown MED element type");
    return k;
  }
}

int GModel::readMED(const std::string &name)
{
  med_idt fid = MEDouvrir((char*)name.c_str(), MED_LECTURE);
  if(fid < 0) {
    Msg(GERROR, "Unable to open file '%s'", name.c_str());
    return 0;
  }

  med_int numMeshes = MEDnMaa(fid);

  if(MEDfermer(fid) < 0){
    Msg(GERROR, "Unable to close file '%s'", (char*)name.c_str());
    return 0;
  }

  int ret;
  // FIXME change all this once we clarify Open/Merge/Clear
  MVertex::resetGlobalNumber();
  MElement::resetGlobalNumber();
  for(int i = 0; i < numMeshes; i++){
    GModel *m = (!i && GModel::list.size() == 1) ? GModel::current() : new GModel;
    ret = m->readMED(name, i);
    if(!ret) return 0;
  }
  return ret;
}

int GModel::readMED(const std::string &name, int meshIndex)
{
  med_idt fid = MEDouvrir((char*)name.c_str(), MED_LECTURE);
  if(fid < 0) {
    Msg(GERROR, "Unable to open file '%s'", name.c_str());
    return 0;
  }
  
  int numMeshes = MEDnMaa(fid);
  if(meshIndex >= numMeshes){
    Msg(INFO, "Could not find mesh %d in MED file", meshIndex);
    return 0;
  }

  // read mesh info
  char meshName[MED_TAILLE_NOM + 1], meshDesc[MED_TAILLE_DESC + 1];
  med_int meshDim;
  med_maillage meshType;
  if(MEDmaaInfo(fid, meshIndex + 1, meshName, &meshDim, &meshType, meshDesc) < 0){
    Msg(GERROR, "Unable to read mesh information");
    return 0;
  }
  setName(meshName);
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
    med_geometrie_element type = msh2medElementType(mshType);
    if(type == MED_NONE) continue;
    med_int numEle = MEDnEntMaa(fid, meshName, MED_CONN, MED_MAILLE, type, MED_NOD);
    if(numEle <= 0) continue;
    int numNodPerEle = type % 100;
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
	  v[k] = verts[conn[numNodPerEle * j + med2mshNodeIndex(type, k)] - 1];
	MElement *e = factory.create(mshType, v, eleTags.empty() ? 0 : eleTags[j]);
	if(e) elements[-fam[j]].push_back(e);
      }
      _storeElementsInEntities(elements);
    }
  }
  _associateEntityWithMeshVertices();
  for(unsigned int i = 0; i < verts.size(); i++){
    GEntity *ge = verts[i]->onWhat();
    // store vertices (except for points, which are already ok)
    if(ge && ge->dim() > 0) ge->mesh_vertices.push_back(verts[i]);
    // delete unused vertices
    if(!ge) delete verts[i];
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
	GEntity *ge; // family tags are unique (for all dimensions)
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
static void fillElementsMED(med_int family, std::vector<T*> &elements,
			    std::vector<med_int> &conn, std::vector<med_int> &fam, 
			    med_geometrie_element &type)
{
  for(unsigned int i = 0; i < elements.size(); i++){
    for(int j = 0; j < elements[i]->getNumVertices(); j++)
      conn.push_back(elements[i]->getVertexMED(j)->getIndex());
    fam.push_back(family);
    if(!i) type = msh2medElementType(elements[i]->getTypeForMSH());
  }
}

static void writeElementsMED(med_idt &fid, char *meshName, std::vector<med_int> &conn, 
			     std::vector<med_int> &fam, med_geometrie_element type)
{
  if(fam.empty()) return;
  if(MEDelementsEcr(fid, meshName, (med_int)3, &conn[0], MED_FULL_INTERLACE,
		    0, MED_FAUX, 0, MED_FAUX, &fam[0], (med_int)fam.size(),
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
  
  // Gmsh always writes 3D unstructured meshes
  if(MEDmaaCr(fid, meshName, 3, MED_NON_STRUCTURE, (char*)"gmsh") < 0){
    Msg(GERROR, "Could not create MED mesh");
    return 0;
  }
  
  // if there are no physicals we save all the elements
  if(noPhysicalGroups()) saveAll = true;

  // index the vertices we save in a continuous sequence (MED
  // connectivity is given in terms of vertex indices)
  indexMeshVertices(saveAll);

  // fill a vector containing all the geometrical entities in the
  // model (the ordering of the entities must be the same as the one
  // used during the indexing of the vertices)
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
    std::vector<med_int> fam;
    for(unsigned int i = 0; i < entities.size(); i++){
      for(unsigned int j = 0; j < entities[i]->mesh_vertices.size(); j++){
	MVertex *v = entities[i]->mesh_vertices[j];
	if(v->getIndex() >= 0){
	  coord.push_back(v->x() * scalingFactor);
	  coord.push_back(v->y() * scalingFactor);
	  coord.push_back(v->z() * scalingFactor);
	  fam.push_back(0); // we never create node families
	}
      }
    }
    if(fam.empty()){
      Msg(GERROR, "No nodes to write in MED mesh");
      return 0;
    }
    char coordName[3 * MED_TAILLE_PNOM + 1] = 
      "x               y               z               ";
    char coordUnit[3 * MED_TAILLE_PNOM + 1] = 
      "unknown         unknown         unknown         ";
    if(MEDnoeudsEcr(fid, meshName, (med_int)3, &coord[0], MED_FULL_INTERLACE, 
		    MED_CART, coordName, coordUnit, 0, MED_FAUX, 0, MED_FAUX, 
		    &fam[0], (med_int)fam.size()) < 0)
      Msg(GERROR, "Could not write nodes");
  }
  
  // write the elements
  {
    med_geometrie_element typ;
    { // points
      std::vector<med_int> conn, fam;
      for(viter it = firstVertex(); it != lastVertex(); it++){
	if(saveAll || (*it)->physicals.size()){
	  conn.push_back((*it)->mesh_vertices[0]->getIndex());
	  fam.push_back(families[*it]);
	}
      }
      writeElementsMED(fid, meshName, conn, fam, MED_POINT1);
    }
    { // lines
      std::vector<med_int> conn, fam;
      for(eiter it = firstEdge(); it != lastEdge(); it++)
	if(saveAll || (*it)->physicals.size())
	  fillElementsMED(families[*it], (*it)->lines, conn, fam, typ);
      writeElementsMED(fid, meshName, conn, fam, typ);
    }
    { // triangles
      std::vector<med_int> conn, fam;
      for(fiter it = firstFace(); it != lastFace(); it++)
	if(saveAll || (*it)->physicals.size())
	  fillElementsMED(families[*it], (*it)->triangles, conn, fam, typ);
      writeElementsMED(fid, meshName, conn, fam, typ);
    }
    { // quads
      std::vector<med_int> conn, fam;
      for(fiter it = firstFace(); it != lastFace(); it++)
	if(saveAll || (*it)->physicals.size())
	  fillElementsMED(families[*it], (*it)->quadrangles, conn, fam, typ);
      writeElementsMED(fid, meshName, conn, fam, typ);
    }
    { // tets
      std::vector<med_int> conn, fam;
      for(riter it = firstRegion(); it != lastRegion(); it++)
	if(saveAll || (*it)->physicals.size())
	  fillElementsMED(families[*it], (*it)->tetrahedra, conn, fam, typ);
      writeElementsMED(fid, meshName, conn, fam, typ);
    }
    { // hexas
      std::vector<med_int> conn, fam;
      for(riter it = firstRegion(); it != lastRegion(); it++)
	if(saveAll || (*it)->physicals.size())
	  fillElementsMED(families[*it], (*it)->hexahedra, conn, fam, typ);
      writeElementsMED(fid, meshName, conn, fam, typ);
    }
    { // prisms
      std::vector<med_int> conn, fam;
      for(riter it = firstRegion(); it != lastRegion(); it++)
	if(saveAll || (*it)->physicals.size())
	  fillElementsMED(families[*it], (*it)->prisms, conn, fam, typ);
      writeElementsMED(fid, meshName, conn, fam, typ);
    }
    { // pyramids
      std::vector<med_int> conn, fam;
      for(riter it = firstRegion(); it != lastRegion(); it++)
	if(saveAll || (*it)->physicals.size())
	  fillElementsMED(families[*it], (*it)->pyramids, conn, fam, typ);
      writeElementsMED(fid, meshName, conn, fam, typ);
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

int GModel::readMED(const std::string &name, int meshIndex)
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
