//
// C++ Interface: terms
//
// Description: Function of GModelWithInterface
//
//
// Author:  <Gauthier BECKER>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "GModelWithInterface.h"
#include "GEntity.h"
#include "MInterfaceElement.h"
#include <limits>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <string>
#include "GmshDefines.h"
#include "MPoint.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "MElementCut.h"
#include "SBoundingBox3d.h"
#include "StringUtils.h"
#include "GmshMessage.h"
#include "discreteVertex.h"
#include "discreteEdge.h"
#include "discreteFace.h"
#include "discreteRegion.h"
#include "MElement.h"
#include "GEdgeCompound.h"
#include "GFaceCompound.h"


// Function allowing to create an interface element TODO try to optimized it (use the work done for interelement on boundary)
// TODO verification of this function with element plus of polynomialorder more important than minus element
void createInterfaceElementMSH(GModel *m, MElement *e,
                                  int reg, int part, std::vector<MVertex*> &v,
                                  std::map<int, std::vector<MElement*> > elements[10],
                                  std::vector<std::pair<int,MInterfaceElement> > &interelements, const int physicals)
{

  // take the vector of element corresponding to the element's type
  std::vector<MElement*> ve;
  switch(e->getType()){
    case TYPE_PNT :
      ve = elements[0][reg]; break;
    case TYPE_LIN :
      ve = elements[1][reg]; break;
    case TYPE_TRI :
      ve = elements[2][reg]; break;
    case TYPE_QUA :
      ve = elements[3][reg]; break;
    case TYPE_TET :
      ve = elements[4][reg]; break;
    case TYPE_HEX :
      ve = elements[5][reg]; break;
    case TYPE_PRI :
      ve = elements[6][reg]; break;
    case TYPE_PYR :
      ve = elements[7][reg]; break;
    case TYPE_POLYG :
      ve = elements[8][reg]; break;
    case TYPE_POLYH :
      ve = elements[9][reg]; break;
    default : Msg::Error("Wrong type of element");
    }

  // (Primary) Nodes of element e
  int npn = e->getNumPrimaryVertices();
  std::vector<MVertex*> nodes;
//  std::vector<MVertex*> *nodes = NULL;
  for (int i = 0; i < npn ; i++)
    nodes.push_back(e->getVertex(i));
  // loop on element to find the interface elements associate to this element (begin at the end of the vector because the elements
  // adjoining the  element are a number near the looked element )
  MElement* el = NULL;
  std::vector<MVertex*> nodes_el;
  MVertex* pt;
  double dist = 0.;
  int count = 0; // count the number of interface elements found
  for( int i = ve.size() - 2; i > -1; i--) // -2 because the last element has no interface element with itself
  {
    el=ve[i];
    // List of el's (primary) vertices
    nodes_el.clear();
    for(int j = 0; j < el->getNumPrimaryVertices(); j++)
      nodes_el.push_back(el->getVertex(j));
    int first_point_m = -1; // First point of interface element has number of vertex is >=0 it can be initialized to -1
    int first_point_p = -1;

    // loop on el's (primary) vertices  // TODO The last node is not considered because if the others is negative the last one will be negative
    for(int j = 0; j<nodes_el.size(); j++){
      pt = nodes_el[j];

      for(int k = 0; k < nodes.size(); k++){
        if (pt == nodes[k]){
          if (first_point_m == -1){
          first_point_m = k;
          first_point_p = j;
          break;
          }
          else{
            // Creation of interface element
            // It is a MLine of the degree of an edge of the element --> the vertices of the (minus) element must be retrieve
            std::vector<MVertex*> vv;
            // choose if the node of plus and minus element that are kept
            int diffpo = e->getPolynomialOrder() - el->getPolynomialOrder();
            if(diffpo <0){
              switch(el->getType()){
                case TYPE_TRI :
                  switch(first_point_p+j){
                    case 1 :
                      el->getEdgeVertices(0,vv); break;
                    case 2 :
                      el->getEdgeVertices(2,vv); break;
                    case 3 :
                      el->getEdgeVertices(1,vv); break;
                  }
                  break;
                case TYPE_QUA :
                  switch(first_point_p+j){
                    case 1 :
                      el->getEdgeVertices(0,vv); break;
                    case 5 :
                      el->getEdgeVertices(2,vv); break;
                    case 3 :
                      if(first_point_p==0 or k==0) el->getEdgeVertices(3,vv);
                      else el->getEdgeVertices(2,vv);
                      break;
                  }
                  break;
                default : Msg::Error("Cannot build interface element for element type : %s",e->getType());
              }
              MInterfaceElement ie =  MInterfaceElement(vv, 0, part, el, e); // MinterfaceElement defined with the same direction of minus element
              interelements.push_back(std::pair<int,MInterfaceElement>(physicals,ie));
            }
            else{
              switch(e->getType()){
                case TYPE_TRI :
                  switch(first_point_m+k){
                    case 1 :
                      e->getEdgeVertices(0,vv); break;
                    case 2 :
                      e->getEdgeVertices(2,vv); break;
                    case 3 :
                      e->getEdgeVertices(1,vv); break;
                  }
                  break;
                case TYPE_QUA :
                  switch(first_point_m+k){
                    case 1 :
                      e->getEdgeVertices(0,vv); break;
                    case 5 :
                      e->getEdgeVertices(2,vv); break;
                    case 3 :
                      if(first_point_m==0 or k==0) e->getEdgeVertices(3,vv);
                      else e->getEdgeVertices(2,vv);
                      break;
                  }
                  break;
                default : Msg::Error("Cannot build interface element for element type : %s",e->getType());
              }
              MInterfaceElement ie =  MInterfaceElement(vv, 0, part, e, el); // MinterfaceElement defined with the same direction of minus element
              interelements.push_back(std::pair<int,MInterfaceElement>(physicals,ie));
            }
            vv.clear();
            count++;
            break;
          }
        }
      }
    }
  // Check if the maximum interface element is reached
  if(count == npn) break;
  }
}


// Function to store the interfaceElement in the GModel
//void GModelWithInterface::_storeInterfaceElements(std::vector<std::map<int,MInterfaceElement> > & ie )
//{
//  interfaces=ie;
//}



// Duplication of GModelIO_Mesh.cpp because it's static functions ??
static bool getVertices(int num, int *indices, std::map<int, MVertex*> &map,
                        std::vector<MVertex*> &vertices)
{
  for(int i = 0; i < num; i++){
    if(!map.count(indices[i])){
      Msg::Error("Wrong vertex index %d", indices[i]);
      return false;
    }
    else
      vertices.push_back(map[indices[i]]);
  }
  return true;
}

static bool getVertices(int num, int *indices, std::vector<MVertex*> &vec,
                        std::vector<MVertex*> &vertices)
{
  for(int i = 0; i < num; i++){
    if(indices[i] < 0 || indices[i] > (int)(vec.size() - 1)){
      Msg::Error("Wrong vertex index %d", indices[i]);
      return false;
    }
    else
      vertices.push_back(vec[indices[i]]);
  }
  return true;
}

static MElement *createElementMSH(GModel *m, int num, int typeMSH, int physical,
                                  int reg, int part, std::vector<MVertex*> &v,
                                  std::map<int, std::vector<MElement*> > elements[10],
                                  std::map<int, std::map<int, std::string> > physicals[4])
{
  MElementFactory factory;
  MElement *e = factory.create(typeMSH, v, num, part);

  if(!e){
    Msg::Error("Unknown type of element %d", typeMSH);
    return NULL;
  }

  switch(e->getType()){
  case TYPE_PNT :
    elements[0][reg].push_back(e); break;
  case TYPE_LIN :
    elements[1][reg].push_back(e); break;
  case TYPE_TRI :
    elements[2][reg].push_back(e); break;
  case TYPE_QUA :
    elements[3][reg].push_back(e); break;
  case TYPE_TET :
    elements[4][reg].push_back(e); break;
  case TYPE_HEX :
    elements[5][reg].push_back(e); break;
  case TYPE_PRI :
    elements[6][reg].push_back(e); break;
  case TYPE_PYR :
    elements[7][reg].push_back(e); break;
  case TYPE_POLYG :
    elements[8][reg].push_back(e); break;
  case TYPE_POLYH :
    elements[9][reg].push_back(e); break;
  default : Msg::Error("Wrong type of element"); return NULL;
  }

  int dim = e->getDim();
  if(physical && (!physicals[dim].count(reg) || !physicals[dim][reg].count(physical)))
    physicals[dim][reg][physical] = "unnamed";

  if(part) m->getMeshPartitions().insert(part);
  return e;
}

static MElement *getParent(int parentNum, std::map<int, std::vector<MElement*> > &elements)
{
  std::map<int, std::vector<MElement*> >::iterator it = elements.begin();
  for(; it != elements.end(); ++it) {
    std::vector<MElement*>::iterator itE = it->second.begin();
    for(; itE != it->second.end(); itE++)
      if((*itE)->getNum() == parentNum) {
        MElement *p = (*itE);
        it->second.erase(itE);
        return p;
      }
  }
  return NULL;
}

static MElement *getParent(int parentNum, int dim,
                           std::map<int, std::vector<MElement*> > elements[10])
{
  MElement *parent = NULL;
  switch(dim){
  case 0 :
    return getParent(parentNum, elements[0]);
  case 1 :
    return getParent(parentNum, elements[1]);
  case 2 :
    if(parent = getParent(parentNum, elements[2])) return parent;
    if(parent = getParent(parentNum, elements[3])) return parent;
    if(parent = getParent(parentNum, elements[8])) return parent;
    return parent;
  case 3 :
    if(parent = getParent(parentNum, elements[4])) return parent;
    if(parent = getParent(parentNum, elements[5])) return parent;
    if(parent = getParent(parentNum, elements[6])) return parent;
    if(parent = getParent(parentNum, elements[7])) return parent;
    if(parent = getParent(parentNum, elements[9])) return parent;
    return parent;
  default : return parent;
  }
}


// Read the mesh from .msh file +/- a copy of function of GModel but a line is added to create interfaceelemnt and a if(THETA) is added to compute interface element on extremities
int GModelWithInterface::readMSH(const std::string &name)
{
  FILE *fp = fopen(name.c_str(), "rb");
  if(!fp){
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  char str[256] = "XXX";
  double version = 1.0;
  bool binary = false, swap = false, postpro = false;
  std::map<int, std::vector<MElement*> > elements[10];
  //std::vector<std::map<int,MInterfaceElement> > interelements;
  std::map<int, std::map<int, std::string> > physicals[4];
  std::map<int, MVertex*> vertexMap;
  std::vector<MVertex*> vertexVector;


  while(1) {

    while(str[0] != '$'){
      if(!fgets(str, sizeof(str), fp) || feof(fp))
        break;
    }

    if(feof(fp))
      break;

    if(!strncmp(&str[1], "MeshFormat", 10)) {

      if(!fgets(str, sizeof(str), fp)) return 0;
      int format, size;
      if(sscanf(str, "%lf %d %d", &version, &format, &size) != 3) return 0;
      if(format){
        binary = true;
        Msg::Info("Mesh is in binary format");
        int one;
        if(fread(&one, sizeof(int), 1, fp) != 1) return 0;
        if(one != 1){
          swap = true;
          Msg::Info("Swapping bytes from binary file");
        }
      }

    }
    else if(!strncmp(&str[1], "PhysicalNames", 13)) {

      if(!fgets(str, sizeof(str), fp)) return 0;
      int numNames;
      if(sscanf(str, "%d", &numNames) != 1) return 0;
      for(int i = 0; i < numNames; i++) {
        int dim = -1, num;
        if(version > 2.0){
          if(fscanf(fp, "%d", &dim) != 1) return 0;
        }
        if(fscanf(fp, "%d", &num) != 1) return 0;
        if(!fgets(str, sizeof(str), fp)) return 0;
        std::string name = ExtractDoubleQuotedString(str, 256);
        if(name.size()) setPhysicalName(name, dim, num);
      }

    }
    else if(!strncmp(&str[1], "NO", 2) || !strncmp(&str[1], "Nodes", 5) ||
            !strncmp(&str[1], "ParametricNodes", 15)) {

      const bool parametric = !strncmp(&str[1], "ParametricNodes", 15);
      if(!fgets(str, sizeof(str), fp)) return 0;
      int numVertices;
      if(sscanf(str, "%d", &numVertices) != 1) return 0;
      Msg::Info("%d vertices", numVertices);
      Msg::ResetProgressMeter();
      vertexVector.clear();
      vertexMap.clear();
      int minVertex = numVertices + 1, maxVertex = -1;
      for(int i = 0; i < numVertices; i++) {
        int num;
        double xyz[3], uv[2];
        MVertex *newVertex = 0;
        if (!parametric){
          if(!binary){
            if (fscanf(fp, "%d %lf %lf %lf", &num, &xyz[0], &xyz[1], &xyz[2]) != 4)
              return 0;
          }
          else{
            if(fread(&num, sizeof(int), 1, fp) != 1) return 0;
            if(swap) SwapBytes((char*)&num, sizeof(int), 1);
            if(fread(xyz, sizeof(double), 3, fp) != 3) return 0;
            if(swap) SwapBytes((char*)xyz, sizeof(double), 3);
          }
          newVertex = new MVertex(xyz[0], xyz[1], xyz[2], 0, num);
        }
        else{
          int iClasDim, iClasTag;
          if(!binary){
            if (fscanf(fp, "%d %lf %lf %lf %d %d", &num, &xyz[0], &xyz[1], &xyz[2],
                       &iClasDim, &iClasTag) != 6)
              return 0;
          }
          else{
            if(fread(&num, sizeof(int), 1, fp) != 1) return 0;
            if(swap) SwapBytes((char*)&num, sizeof(int), 1);
            if(fread(xyz, sizeof(double), 3, fp) != 3) return 0;
            if(swap) SwapBytes((char*)xyz, sizeof(double), 3);
            if(fread(&iClasDim, sizeof(int), 1, fp) != 1) return 0;
            if(swap) SwapBytes((char*)&iClasDim, sizeof(int), 1);
            if(fread(&iClasTag, sizeof(int), 1, fp) != 1) return 0;
            if(swap) SwapBytes((char*)&iClasTag, sizeof(int), 1);
          }
          if (iClasDim == 0){
            GVertex *gv = getVertexByTag(iClasTag);
            if (gv) gv->deleteMesh();
            newVertex = new MVertex(xyz[0], xyz[1], xyz[2], gv, num);
          }
          else if (iClasDim == 1){
            GEdge *ge = getEdgeByTag(iClasTag);
            if(!binary){
              if (fscanf(fp, "%lf", &uv[0]) != 1) return 0;
            }
            else{
              if(fread(uv, sizeof(double), 1, fp) != 1) return 0;
              if(swap) SwapBytes((char*)uv, sizeof(double), 1);
            }
            newVertex = new MEdgeVertex(xyz[0], xyz[1], xyz[2], ge, uv[0], -1.0, num);
          }
          else if (iClasDim == 2){
            GFace *gf = getFaceByTag(iClasTag);
            if(!binary){
              if (fscanf(fp, "%lf %lf", &uv[0], &uv[1]) != 2) return 0;
            }
            else{
              if(fread(uv, sizeof(double), 2, fp) != 2) return 0;
              if(swap) SwapBytes((char*)uv, sizeof(double), 2);
            }
            newVertex = new MFaceVertex(xyz[0], xyz[1], xyz[2], gf, uv[0], uv[1], num);
          }
          else if (iClasDim == 3){
            GRegion *gr = getRegionByTag(iClasTag);
            newVertex = new MVertex(xyz[0], xyz[1], xyz[2], gr, num);
          }
        }
        minVertex = std::min(minVertex, num);
        maxVertex = std::max(maxVertex, num);
        if(vertexMap.count(num))
          Msg::Warning("Skipping duplicate vertex %d", num);
        vertexMap[num] = newVertex;
        if(numVertices > 100000)
          Msg::ProgressMeter(i + 1, numVertices, "Reading nodes");
      }
      // If the vertex numbering is dense, tranfer the map into a
      // vector to speed up element creation
      if((int)vertexMap.size() == numVertices &&
         ((minVertex == 1 && maxVertex == numVertices) ||
          (minVertex == 0 && maxVertex == numVertices - 1))){
        Msg::Info("Vertex numbering is dense");
        vertexVector.resize(vertexMap.size() + 1);
        if(minVertex == 1)
          vertexVector[0] = 0;
        else
          vertexVector[numVertices] = 0;
        std::map<int, MVertex*>::const_iterator it = vertexMap.begin();
        for(; it != vertexMap.end(); ++it)
          vertexVector[it->first] = it->second;
        vertexMap.clear();
      }

    }
    else if(!strncmp(&str[1], "ELM", 3) || !strncmp(&str[1], "Elements", 8)) {

      if(!fgets(str, sizeof(str), fp)) return 0;
      int numElements;
      std::map<int, MElement*> parents;
      sscanf(str, "%d", &numElements);
      Msg::Info("%d elements", numElements);
      Msg::ResetProgressMeter();
      if(!binary){
        for(int i = 0; i < numElements; i++) {
          int num, type, physical = 0, elementary = 0, partition = 0, parentN = 0, numVertices;
          if(version <= 1.0){
            if(fscanf(fp, "%d %d %d %d %d", &num, &type, &physical, &elementary, &numVertices) != 5)
              return 0;
            if(numVertices != MElement::getInfoMSH(type)) return 0;
          }
          else{
            int numTags;
            if(fscanf(fp, "%d %d %d", &num, &type, &numTags) != 3) return 0;
            for(int j = 0; j < numTags; j++){
              int tag;
              if(fscanf(fp, "%d", &tag) != 1) return 0;
              if(j == 0)      physical = tag;
              else if(j == 1) elementary = tag;
              else if(j == 2) partition = tag;
              else if(j == 3) parentN = tag;
              // ignore any other tags for now
            }
            if(!(numVertices = MElement::getInfoMSH(type))) {
              if(type != MSH_POLYG_ && type != MSH_POLYH_) return 0;
              if(fscanf(fp, "%d", &numVertices) != 1) return 0;
            }
          }
          int *indices = new int[numVertices];
          for(int j = 0; j < numVertices; j++)
            if(fscanf(fp, "%d", &indices[j]) != 1) return 0;
          std::vector<MVertex*> vertices;
          if(vertexVector.size()){
            if(!getVertices(numVertices, indices, vertexVector, vertices)) return 0;
          }
          else{
            if(!getVertices(numVertices, indices, vertexMap, vertices)) return 0;
          }
          MElement *e = createElementMSH(this, num, type, physical, elementary,
                                         partition, vertices, elements, physicals);
          // creation of interface elements (no interface element for a line)
          if(e->getNumPrimaryVertices() > 2) createInterfaceElementMSH(this, e, elementary, partition, vertices, elements, interfaces,physical);
          if(parentN) {
            MElement *parent = NULL;
            if(parents.find(parentN) == parents.end()){
              parent = getParent(parentN, e->getDim(), elements);
              if(parent) parents[parentN] = parent;
              else Msg::Error("Parent element %d not found!",parentN);
            }
            else parent = parents.find(parentN)->second;
            e->setParent(parent);
          }
          if(numElements > 100000)
            Msg::ProgressMeter(i + 1, numElements, "Reading elements");
          delete [] indices;
        }
      }
      else{
        int numElementsPartial = 0;
        while(numElementsPartial < numElements){
          int header[3];
          if(fread(header, sizeof(int), 3, fp) != 3) return 0;
          if(swap) SwapBytes((char*)header, sizeof(int), 3);
          int type = header[0];
          int numElms = header[1];
          int numTags = header[2];
          int numVertices = MElement::getInfoMSH(type);
          unsigned int n = 1 + numTags + numVertices;
          int *data = new int[n];
          for(int i = 0; i < numElms; i++) {
            if(fread(data, sizeof(int), n, fp) != n) return 0;
            if(swap) SwapBytes((char*)data, sizeof(int), n);
            int num = data[0];
            int physical = (numTags > 0) ? data[4 - numTags] : 0;
            int elementary = (numTags > 1) ? data[4 - numTags + 1] : 0;
            int partition = (numTags > 2) ? data[4 - numTags + 2] : 0;
            int *indices = &data[numTags + 1];
            std::vector<MVertex*> vertices;
            if(vertexVector.size()){
              if(!getVertices(numVertices, indices, vertexVector, vertices)) return 0;
            }
            else{
              if(!getVertices(numVertices, indices, vertexMap, vertices)) return 0;
            }
            createElementMSH(this, num, type, physical, elementary, partition,
                             vertices, elements, physicals);
            if(numElements > 100000)
              Msg::ProgressMeter(numElementsPartial + i + 1, numElements,
                                 "Reading elements");
          }
          delete [] data;
          numElementsPartial += numElms;
        }
      }
    }
    else if(!strncmp(&str[1], "NodeData", 8)) {

      // there's some nodal post-processing data to read later on, so
      // cache the vertex indexing data
      if(vertexVector.size())
        _vertexVectorCache = vertexVector;
      else
        _vertexMapCache = vertexMap;
      postpro = true;
      break;
    }
    else if(!strncmp(&str[1], "ElementData", 11) ||
            !strncmp(&str[1], "ElementNodeData", 15)) {

      // there's some element post-processing data to read later on
      postpro = true;
      break;
    }

    do {
      if(!fgets(str, sizeof(str), fp) || feof(fp))
        break;
    } while(str[0] != '$');
  }

  // store the elements in their associated elementary entity. If the
  // entity does not exist, create a new (discrete) one.
  for(int i = 0; i < (int)(sizeof(elements) / sizeof(elements[0])); i++)
    _storeElementsInEntities(elements[i]);

  // Store the interfaceElements when I understand this operation
  //_storeInterfaceElements(interelements);

  // associate the correct geometrical entity with each mesh vertex
  _associateEntityWithMeshVertices();

  // store the vertices in their associated geometrical entity
  if(vertexVector.size())
    _storeVerticesInEntities(vertexVector);
  else
    _storeVerticesInEntities(vertexMap);

  // store the physical tags
  for(int i = 0; i < 4; i++)
    _storePhysicalTagsInEntities(i, physicals[i]);

  fclose(fp);

  return postpro ? 2 : 1;
}
// Generate Interface Element on BoundaryCondition
void GModelWithInterface::generateInterfaceElementsOnBoundary(const int &num_phys, std::vector<DGelasticField> elasticFields){
  //Boundary condition on the derivative of displacement
  std::vector<MVertex*> Mv;
  std::vector<MVertex*> vv;
  MElement *el=NULL;
  int ord,nedge,temp=0;
  bool flag_find;
  this->getMeshVerticesForPhysicalGroup(1,num_phys,Mv); // 1 because always 1D interface element for thin structures
  // Loop on nodes of Physical entities to find the associated element Optimize it because for each components of Mv loop on all elements (il faudrait les "noeuds interieurs du groupe physique)
  for(int j=0;j<Mv.size();j++){
    flag_find=false;
    for(int jj=0;jj<elasticFields.size();jj++){
      for (std::set<MElement*>::const_iterator it=elasticFields[jj].g->begin();it!=elasticFields[jj].g->end();++it){
        el = *it;
        // retrieve order and number of edge of element
        ord = el->getPolynomialOrder(); nedge = el->getNumEdges();
        // The interfaceElement is created only if Mv[j] is the first interior vertex (ie it is not a primary vertex) of the edge of the element
        // So only this vertex of element are tested
        for(int k=0;k<nedge;k++){
          temp = nedge + k*(ord-1);
          if (el->getVertex(temp) == Mv[j]){
            el->getEdgeVertices(k,vv);
            MInterfaceElement ie = MInterfaceElement(vv, 0, 0, el,el);
            boundinter.push_back(std::pair<int,MInterfaceElement>(jj,ie));
            vv.clear();
            flag_find=true;
            break;
          }
          else if(el->getVertex(k) == Mv[j]) {flag_find=true; break;} // Mv[j] is a primary vertices -->break // Remove it if Mv contains only the interior vertices
        }
        if(flag_find) break; // Element associated to the node is find -->break
      }
      if(flag_find) break; // Element associated to the node is find -->break
    }
  }
}
