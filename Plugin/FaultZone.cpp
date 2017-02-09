// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include <assert.h>
#include <sstream>
#include <stdlib.h>
#include "Numeric.h"
#include "Context.h"
#include "GmshMessage.h"
#include "FaultZone.h"
#include "GModel.h"
#include "GModelIO_GEO.h"
#include "SVector3.h"
#include "GEdge.h"
#include "GFace.h"
#include "discreteFace.h"
#include "MVertex.h"
#include "MElement.h"
#include "MQuadrangle.h"

StringXNumber FaultZoneOptions_Number[] = {
  {GMSH_FULLRC, "SurfaceTag", NULL, 1},
  {GMSH_FULLRC, "Thickness", NULL, 0.},
};

StringXString FaultZoneOptions_String[] = {
  {GMSH_FULLRC, "Prefix", NULL, "FAMI_"},
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterFaultZonePlugin()
  {
    return new GMSH_FaultZonePlugin();
  }
}

std::string GMSH_FaultZonePlugin::getHelp() const
{
  return "Plugin(FaultZone) convert all the embedded lines of an existing "
    "surfacic mesh to flat quadrangles. Flat quadrangles represent joint "
    "elements suitable to model a fault zone with Code_Aster."
    "\n\n"
    "`SurfaceTag' must be an existing plane surface containing embedded "
    "lines. Embedded lines must have been added to the surface via the "
    "command Line In Surface. "
    "The surface must be meshed with quadratic incomplete elements."
    "\n\n"
    "`Thickness' is the thichness of the flat quadrangles. "
    "Set a value different to zero can be helpfull to check the connectivity. "
    "\n\n"
    "`Prefix' is the prefix of the name of physicals containing the new embedded. "
    "All physicals containing embedded lines are replaced by physicals containing "
    "the coresponding joint elements.";
}

int GMSH_FaultZonePlugin::getNbOptions() const
{
  return sizeof(FaultZoneOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_FaultZonePlugin::getOption(int iopt)
{
  return &FaultZoneOptions_Number[iopt];
}

int GMSH_FaultZonePlugin::getNbOptionsStr() const
{
  return sizeof(FaultZoneOptions_String) / sizeof(StringXString);
}

StringXString *GMSH_FaultZonePlugin::getOptionStr(int iopt)
{
  return &FaultZoneOptions_String[iopt];
}

//=============================================================================
/*!
 * \brief Execute the pluggin FaultZone
 */
//=============================================================================
PView *GMSH_FaultZonePlugin::execute(PView *view)
{
  int tag = (int)FaultZoneOptions_Number[0].def;
  double eps = (double)FaultZoneOptions_Number[1].def;
  std::string prefix = FaultZoneOptions_String[0].def;

  // controls

  GModel *gModel = GModel::current();

  GFace *gFace = gModel->getFaceByTag(tag);

  if (!gFace){
    Msg::Error("Face %d does not exist or was not meshed",tag);
    return view;
  }

  if (!gFace->embeddedEdges().size()){
    Msg::Error("No line to treat in this surface");
    return view;
  }

  std::list< GEdge* > embeddedEdges = gFace->embeddedEdges();
  std::list<GEdge*>::const_iterator itl;
  for(itl = embeddedEdges.begin();itl != embeddedEdges.end(); ++itl)
    if ((*itl)->length() != 0) break;
  if (itl == embeddedEdges.end()){
    Msg::Error("No line to treat in this surface");
    Msg::Error("The plugin FaultZone may have been already run for this surface. "
               "Reload your geometry");
    return view;
  }

  for(itl = embeddedEdges.begin();itl != embeddedEdges.end(); ++itl)
    if ((*itl)->geomType() != GEntity::Line) break;
  if (itl != embeddedEdges.end()){
    Msg::Error("All the embedded edges must be straight lines");
    return view;
  }

  for(itl = embeddedEdges.begin();itl != embeddedEdges.end(); ++itl){
    Curve* c = FindCurve((*itl)->tag());
    if (c && List_Nbr(c->Control_Points) > 2) break;
  }
  if (itl != embeddedEdges.end()){
    Msg::Error("The embedded edges must not contain control points");
    return view;
  }

  for(itl = embeddedEdges.begin();itl != embeddedEdges.end(); ++itl){
    GEdge* gEdge = *itl;
    unsigned int i = 0;
    for(; i < gEdge->getNumMeshElements(); i++)
      if (gEdge->getMeshElement(i)->getNumVertices() == 3) break;
    if (i == gEdge->getNumMeshElements()) break;
  }
  if (itl != embeddedEdges.end()){
    Msg::Error("The mesh must be order 2");
    return view;
  }

  // end of controls

  GMSH_FaultZoneMesher faultZoneMesher;

  faultZoneMesher.RetriveFissuresInfos(gFace);

  faultZoneMesher.DuplicateNodes();

  faultZoneMesher.ComputeHeavisideFunction();

  faultZoneMesher.CreateJointElements(gModel, gFace, prefix);

  faultZoneMesher.ModifyElementsConnectivity(gFace);

  if (eps)
    faultZoneMesher.ModifyJointNodePosition(eps/2);

  CTX::instance()->mesh.changed = ENT_ALL;

  return view;
}

//================================================================================
/*!
 * \brief retirive fissures (embedded edges) infos in maps.
 * this function fills in the following set and maps :
 *     _jointElements,
 *     _fissureByHeavNode,
 *     _vectNormByFissure,
 *     _fissuresByJunctionNode,
 *     _vectsTanByJunctionNode,
 *     _connectedElements
 */
//================================================================================
void GMSH_FaultZoneMesher::RetriveFissuresInfos(GFace* gFace){

  std::list< GEdge* > embeddedEdges = gFace->embeddedEdges();
  std::list< GEdge* > edges = gFace->edges();

  // set with all the MVertex of the fissures
  std::set < MVertex* > allFissuresVertices;
  for(std::list<GEdge*>::const_iterator itl = embeddedEdges.begin();
      itl != embeddedEdges.end(); ++itl){
    GEdge *gEdge = *itl;
    for (unsigned int i = 0; i < gEdge->getNumMeshVertices(); i++){
      allFissuresVertices.insert(gEdge->getMeshVertex(i));
    }
    allFissuresVertices.insert(gEdge->getBeginVertex()->getMeshVertex(0));
    allFissuresVertices.insert(gEdge->getEndVertex()->getMeshVertex(0));
  }

  // set with all quadratic MVertex of the fissures connected to the surface
  std::set < MVertex* > allConnectedQuadraticVertices;
  // fill _connectedElements
  for(unsigned int i = 0; i < gFace->getNumMeshElements(); i++){
    MElement *mElem = gFace->getMeshElement(i);
    for (int j = 0; j < mElem->getNumVertices(); j++){
      MVertex *mVert = mElem->getVertex(j);
      std::set < MVertex* >::iterator its = allFissuresVertices.find( mVert );
      if (its != allFissuresVertices.end()){
        _connectedElements.insert(mElem);
        if (mVert->getPolynomialOrder() == 2)
          allConnectedQuadraticVertices.insert( mVert );
      }
    }
  }
  // for the generatrices
  for(std::list<GEdge*>::const_iterator itl = edges.begin();itl != edges.end(); ++itl){
    GEdge *gEdge = *itl;
    for(unsigned int i = 0; i < gEdge->getNumMeshElements(); i++){
      MElement *mElem = gEdge->getMeshElement(i);
      for (int j = 0; j < mElem->getNumVertices(); j++){
        MVertex *mVert = mElem->getVertex(j);
        std::set < MVertex* >::iterator its = allFissuresVertices.find( mVert );
        if (its != allFissuresVertices.end()){
          _connectedElements.insert(mElem);
        }
      }
    }
  }

  for(std::list<GEdge*>::const_iterator itl = embeddedEdges.begin();
      itl != embeddedEdges.end(); ++itl){
    GEdge *gEdge = *itl;
    if (gEdge->length() == 0)// nothing to do if there is no element
      continue;

    MVertex *mVertexBegin = gEdge->getBeginVertex()->getMeshVertex(0);
    MVertex *mVertexEnd = gEdge->getEndVertex()->getMeshVertex(0);

    SPoint3 pointBegin = gEdge->getBeginVertex()->xyz();
    SPoint3 pointEnd = gEdge->getEndVertex()->xyz();

    SVector3 vectTanBegin = SVector3(pointEnd, pointBegin);
    SVector3 vectTanEnd = SVector3(pointBegin, pointEnd);
    SVector3 vectNorm  = crossprod(vectZ , vectTanEnd);

    vectTanBegin.normalize();
    vectTanEnd.normalize();
    double norm = vectNorm.normalize();
    if(!norm) Msg::Error("norm == 0 in Plugin(FaultZone)");

    // fill _jointElements and _fissureByHeavNode
    for(unsigned int i = 0; i < gEdge->getNumMeshElements(); i++){
      MElement *mElem = gEdge->getMeshElement(i);
      assert(mElem->getNumVertices() == 3);
      elementsIt its;
      for (its = _jointElements.begin(); its != _jointElements.end(); its++){
        assert((*its)->getNumVertices() == 3);
        // the MElements are considered the same if the quadratic node is the same
        if ((*its)->getVertex(2) == mElem->getVertex(2)){
          break;
        }
      }

      if (its != _jointElements.end()){
        Msg::Warning("Element edge %d appears in a second GEntity", mElem->getNum());
        continue;
      }

      // the MElements are considered connected if the quadratic node is connected
      std::set < MVertex* >::iterator its2 = allConnectedQuadraticVertices.find
        (mElem->getVertex(2));
      if (its2 == allConnectedQuadraticVertices.end()){
        Msg::Warning("Element edge %d seams to be not connected, it will be ignored",
                     mElem->getNum());
        continue;
      }

      _jointElements.insert(mElem);
      for(int j = 0; j < mElem->getNumVertices(); j++){
        MVertex *mVert = mElem->getVertex(j);
        _fissureByHeavNode[mVert] = gEdge;
      }
    }

    // fill _vectNormByFissure
    _vectNormByFissure[gEdge] = vectNorm;

    // fill _fissuresByJunctionNode and _vectsTanByJunctionNode
    std::map < MVertex* , GEdge* >::iterator itm = _fissureByHeavNode.find(mVertexBegin);
    if (itm != _fissureByHeavNode.end()){
      _fissuresByJunctionNode[mVertexBegin].push_back(gEdge);
      _vectsTanByJunctionNode[mVertexBegin].push_back( vectTanBegin );
      _fissureByHeavNode.erase(mVertexBegin);
    }
    itm = _fissureByHeavNode.find(mVertexEnd);
    if (itm != _fissureByHeavNode.end()){
      _fissuresByJunctionNode[mVertexEnd].push_back( gEdge );
      _vectsTanByJunctionNode[mVertexEnd].push_back( vectTanEnd );
      _fissureByHeavNode.erase(mVertexEnd);
    }
  }
}

//================================================================================
/*!
 * \brief vectZ
 */
const SVector3 GMSH_FaultZoneMesher::vectZ = SVector3(0,0,1);

//================================================================================
/*!
 * \brief tolerance
 */
const double GMSH_FaultZoneMesher::tolerance = 1.e-12;


//================================================================================
/*!
 * \brief duplicates nodes of the embedded edges to model the joints
 * this function fills in the following maps :
 *     _vectsTanByTipNode;
 *     _nodeByHeavNode;
 *     _nodeJointByHeavOrJunctionNode;
 *     _nodesByJunctionNode;
 *
 * The new nodes are not yet associated to a GEntity. The association
 * will be done in the CreateJointElements function.
 */
//================================================================================
void GMSH_FaultZoneMesher::DuplicateNodes(){

  // fill _nodeJointByHeavOrJunctionNode and _nodesByJunctionNode
  for(std::map<MVertex*,std::vector<GEdge*> >::iterator itm =
        _fissuresByJunctionNode.begin();itm != _fissuresByJunctionNode.end();){
    MVertex *mVert = itm->first;
    std::vector < GEdge* > fissures = itm->second;

    unsigned int nbFiss = fissures.size();
    if (nbFiss == 1){ // if only one fissure, the node will be treated in _fissureByHeavNode
      _fissureByHeavNode[mVert] = fissures.front();
      _vectsTanByTipNode[mVert] = _vectsTanByJunctionNode[mVert][0];
      _vectsTanByJunctionNode.erase(mVert);
      _fissuresByJunctionNode.erase(itm++);
    }
    else{
      std::vector < MVertex* > mVertices;
      mVertices.push_back(mVert);
      for (unsigned int i = 0; i < nbFiss-1; i++){
        MVertex *mVertJonc = new MVertex(mVert->x(), mVert->y(), mVert->z());
        mVertices.push_back(mVertJonc);
      }
      _nodesByJunctionNode[mVert] = mVertices;
      MVertex *mVertJoint = new MVertex(mVert->x(), mVert->y(), mVert->z());
      mVertJoint->setPolynomialOrder(2);
      _nodeJointByHeavOrJunctionNode[mVert] = mVertJoint;
      itm++;
    }
  }

  // fill _nodeJointByHeavOrJunctionNode and _nodeByHeavNode
  for(std::map<MVertex*,GEdge*>::iterator itm=_fissureByHeavNode.begin();
      itm != _fissureByHeavNode.end(); itm++){
    MVertex *mVert = itm->first;
    if (mVert->getPolynomialOrder() == 1){
      MVertex *mVertJoint;
      mVertJoint = new MVertex(mVert->x(), mVert->y(), mVert->z());
      mVertJoint->setPolynomialOrder(2);
      _nodeJointByHeavOrJunctionNode[mVert] = mVertJoint;
    }
    MVertex *mVertHeav;
    mVertHeav = new MVertex(mVert->x(), mVert->y(), mVert->z());
    _nodeByHeavNode[mVert] = mVertHeav;
  }

}

//================================================================================
/*!
 * \brief compute Heaviside function for junction nodes
 * this function fills in the following maps :
 *     _heavFuncByJunctionNode;
 *
 * The _heavFuncByJunctionNode map is used to determinate from which
 * domain the junction nodes contained in _nodesByJunctionNode are
 * associated. A domain is characterised by the Heaviside values of
 * the corresponding level set where the iso-zeros describe the fissures.
 * Each term can be +1 (upper the fissure), -1 (under the fissure),
 * 0 (undeterminate, can be upper or under).
 */
//================================================================================
void GMSH_FaultZoneMesher::ComputeHeavisideFunction(){

  for (std::map<MVertex*,std::vector<GEdge*> >::iterator itm =
         _fissuresByJunctionNode.begin(); itm != _fissuresByJunctionNode.end(); itm++){
    MVertex *mVert = itm->first;
    std::vector < GEdge* > fissures = itm->second;
    unsigned int size = fissures.size();
    assert(size >= 2);
    std::vector < SVector3 > vectsTan = _vectsTanByJunctionNode[mVert];
    assert(vectsTan.size() == size);

    std::vector < SVector3 > vectsNor;
    for (std::vector<GEdge*>::iterator itl = fissures.begin(); itl != fissures.end(); itl++){
      vectsNor.push_back(_vectNormByFissure[*itl]);
    }
    assert(vectsNor.size() == size);
    std::vector < std::vector< int> > heavFunc;

    for (unsigned int i=0; i < size; i++){
      std::vector < int > heav(size, 0);

      if (i == 0){
        heavFunc.insert(heavFunc.begin(), heav);
        continue;
      }
      // found from which side of fissure i, the precedent fissures are placed
      // upper = 1, under = -1, both = 0
      bool upper = false;
      bool under = false;
      for (unsigned int j=0; j<i; j++){
        double lsn = -dot(vectsNor[i], vectsTan[j]);
        upper = (upper || lsn > tolerance);
        under = (under || lsn < -tolerance);
      }
      if (!under) heav[i] = 1;
      if (under && !upper) heav[i] = -1;

      // compute the heaviside functions of the precedent fissures for a point
      // located on fissure i
      for (unsigned int j=0; j < i;j++){
        double lsn = -dot(vectsNor[j], vectsTan[i]);
        if (fabs(lsn) < tolerance){
          lsn = dot(vectsNor[j], vectsNor[i])*heav[i];
          assert(fabs(lsn) > tolerance || heav[i] == 0);
        }
        heav[j] = gmsh_sign(lsn);
      }

      if (heav[i] != 0){
        // add the new domain on the side where the precedent fissure are
        //
        //                                        Fissure2
        //                    Fissure1            /
        //                          \            /
        //                           \          /
        //                            \        /
        //             new domain      `.     /
        //                               \   /
        //                                \ /
        // Fissure3 -----------------------+
        //
        heavFunc.insert(heavFunc.begin(), heav);
      }
      else{
        // find the domain where the fissure i is and duplicates it with value
        // -1 and +1 for the fissure i
        //
        //                                       Fissure1
        //                                       /
        //              found domain            /
        //              with value +1          /
        //                                    /
        //                                   /
        //                 +                /
        // Fissure3 -----------------------;
        //                 -                `._
        //                                     `.
        //                                       `.
        //               found domain              `._
        //               with value -1                `.
        //                                             Fissure2
        //
        bool isDomain = false;
        for (unsigned int j=0; j < i;j++){
          isDomain = compareHeav(heavFunc[j], heav);
          if (isDomain){
            heavFunc.insert(heavFunc.begin()+j, heavFunc[j]);
            heavFunc[j][i] = -1;
            heavFunc[j+1][i] = 1;
            break;
          }
        }
        assert(isDomain);
      }
    }
    _heavFuncByJunctionNode[mVert] = heavFunc;
  }
}

//================================================================================
/*!
 * \brief Return the value of the heaviside function associated to mVert evaluated
 * on point sPoint.
 */
//================================================================================
std::vector < int > GMSH_FaultZoneMesher::HeavisideFunc(MVertex* mVert, SPoint3& sPoint){

  SVector3 vectPoint = SVector3(mVert->point(), sPoint);
  double norm = vectPoint.normalize();
  if(!norm) Msg::Error("norm == 0 in Plugin(FaultZone)");

  std::vector < int > heav;
  if (_nodeByHeavNode.find( mVert ) != _nodeByHeavNode.end()){
    // if it is a pure heaviside node
    SVector3 vectNorm = _vectNormByFissure[_fissureByHeavNode[mVert]];
    double lsn = dot(vectPoint, vectNorm);
    if (fabs(lsn) < tolerance){
      // verify the point is outside the fissure
      assert(_vectsTanByTipNode.find( mVert ) != _vectsTanByTipNode.end());
      SVector3 vectTan = _vectsTanByTipNode[mVert];
      assert(dot(vectPoint, vectTan) > 0);
      lsn = 0;
    }
    heav.push_back(gmsh_sign(lsn));
  }
  else if (_nodesByJunctionNode.find( mVert ) != _nodesByJunctionNode.end()){
    // if it is a junction node
    std::vector < GEdge* > fissures = _fissuresByJunctionNode[mVert];
    unsigned int size = fissures.size();
    for (unsigned int i=0; i < size; i++){
      SVector3 vectNorm = _vectNormByFissure[fissures[i]];
      double lsn = dot(vectPoint, vectNorm);
      if (fabs(lsn) > tolerance) // tolerance seems to be ok
        heav.push_back(gmsh_sign(lsn));
      else
        heav.push_back(0);
    }
  }
  else// if it is not a heaviside node
    assert(false);

  return heav;
}

//================================================================================
/*!
 * \brief create joint Elements. For each element in the embedded edges,
 * a corresponding face element is created, based on the nodes of the edge element.
 * additionnal nodes are picked in the _nodeJointByHeavOrJunctionNode,
 * _nodeByHeavNode and _nodesByJunctionNode maps. In case of _nodesByJunctionNode,
 * the _heavFuncByJunctionNode map is used to found the corresponding node.
 *
 * this function also replace physical edges containning the embedded edges by
 * new corresponding physical faces
 */
//================================================================================
void GMSH_FaultZoneMesher::CreateJointElements(GModel* gModel, GFace* gFace,
                                               std::string prefix){

  std::list< GEdge * > embeddedEdges = gFace->embeddedEdges();
  std::map < int , int > discreteFaceEntityByEmbeddedEdgeEntity;
  for(std::list<GEdge*>::const_iterator itl = embeddedEdges.begin();
      itl != embeddedEdges.end(); ++itl){
    GEdge *gEdge = *itl;
    if (gEdge->length() == 0)// nothing to do if there is no element
      continue;

    // creation of a new GFace
    GFace *jointFace = new discreteFace(gModel, gModel->getMaxElementaryNumber(2) + 1);
    discreteFaceEntityByEmbeddedEdgeEntity[gEdge->tag()] = jointFace->tag();
    gModel->add(jointFace);

    // for each MElement in the GEdge, a new MElement is created and inserted in GFace
    for(unsigned int i = 0; i < gEdge->getNumMeshElements(); i++){
      MElement *mElem = gEdge->getMeshElement(i);
      elementsIt its = _jointElements.find(mElem);
      if (its == _jointElements.end())
        continue;

      SPoint3 bary = mElem->barycenter();
      std::vector<MVertex*> mVerts(8, (MVertex*)0);

      // check orientation
      SVector3 nor = _vectNormByFissure[gEdge];
      SVector3 tan = mElem->getEdge(0).tangent();
      int changeOri = (dot(crossprod(nor, tan), vectZ) > 0);
      if (changeOri)
        Msg::Warning("Reverting local numbering node for element %d to set "
                     "outgoing normal for its corresponding joint element",
                     mElem->getNum());
      // retriving MVertices to create the new MElement
      for(int i = 0; i < mElem->getNumVertices(); i++){
        MVertex *mVert = mElem->getVertex(i);

        int j = (changeOri && i < 2) ? !i : i;
        if (j < 2) // adding intern node
          mVerts[_numNodeJoint[j]] = _nodeJointByHeavOrJunctionNode[mVert];

        if (_nodeByHeavNode.find(mVert) != _nodeByHeavNode.end()){
          // adding upper and under nodes
          mVerts[_numNodeHeavInf[j]] = mVert;
          mVerts[_numNodeHeavSup[j]] = _nodeByHeavNode[mVert];
        }
        else{
          std::vector < int > heav = HeavisideFunc(mVert, bary);
          unsigned int size = heav.size();
          assert(size > 1);
          std::vector < GEdge* > fissures = _fissuresByJunctionNode[mVert];
          assert (fissures.size() == size);
          std::vector <std::vector< int > > heavFunc = _heavFuncByJunctionNode[mVert];
          assert (heavFunc.size() == size);
          std::vector < MVertex*> nodes = _nodesByJunctionNode[mVert];
          assert (nodes.size() == size);

          unsigned int k;
          for (k=0; k < size; k++){
            if (fissures[k]->tag() == gEdge->tag())
              break;
          }
          assert(k < size);

          // adding under node
          heav[k] = -1;
          mVerts[_numNodeHeavInf[j]] = nodes[findMatchingHeav(heavFunc, heav)];

          // adding upper node
          heav[k] =  1;
          mVerts[_numNodeHeavSup[j]] = nodes[findMatchingHeav(heavFunc, heav)];
        }
      }
      // association of the MVertices (created in function DuplicateNodes) to
      // the new GEntity (created here)
      for(int j =0; j<8; j++){
        MVertex *mVert = mVerts[j];
        assert(mVert != NULL);
        if (mVert->onWhat() == 0){
          mVert->setEntity(jointFace);
          jointFace->addMeshVertex(mVert);
        }
      }
      // creation of the new MElement and push into the new GEntity
      MQuadrangle8* mQuad8 = new MQuadrangle8(mVerts[0], mVerts[1], mVerts[2], mVerts[3],
                                              mVerts[4], mVerts[5], mVerts[6], mVerts[7]);
      jointFace->quadrangles.push_back(mQuad8);
    }
    // hide gEdge and set lenght to zero to detect that this edge was treated
    gEdge->setVisibility(0);
    gEdge->setLength(0);
  }

  // replace physical edges by physical surfaces
  for(int i = 0; i < List_Nbr(gModel->getGEOInternals()->PhysicalGroups); i++){
    PhysicalGroup *p = *(PhysicalGroup**)List_Pointer
      (GModel::current()->getGEOInternals()->PhysicalGroups, i);
    if(p->Typ == MSH_PHYSICAL_LINE){
      List_T *faceEntities = List_Create(2, 1, sizeof(int));
      for(int j = 0; j < List_Nbr(p->Entities); j++){
        int num;
        List_Read(p->Entities, j, &num);
        std::map < int ,int >::iterator itm =
          discreteFaceEntityByEmbeddedEdgeEntity.find(num);
        if (itm != discreteFaceEntityByEmbeddedEdgeEntity.end()){
          List_Add(faceEntities, &itm->second);
        }
      }
      if (List_Nbr(faceEntities) > 0){
        std::stringstream sufix;
        sufix << p->Num;
        int num = gModel->setPhysicalName
          (prefix+sufix.str(), 2, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
        PhysicalGroup *pnew = Create_PhysicalGroup(num, MSH_PHYSICAL_SURFACE, faceEntities);
        List_Add(gModel->getGEOInternals()->PhysicalGroups, &pnew);
        for(int j = 0; j < List_Nbr(faceEntities); j++){
          int num;
          List_Read(faceEntities, j, &num);
          GFace* gFace = gModel->getFaceByTag(num);
          gFace->physicals.push_back(pnew->Num);
        }
        List_Remove(gModel->getGEOInternals()->PhysicalGroups, i);
        gModel->deletePhysicalGroup(1, p->Num);
        i-=1;
      }
      List_Delete(faceEntities);
    }
  }
}

//================================================================================
/*!
 * \brief corresponding quad8 node number to seg3 node number for under side
 */
const int GMSH_FaultZoneMesher::_numNodeHeavInf[3] = {0, 1, 4};

/*!
 * \brief corresponding quad8 node number to seg3 node number for upper side
 */
const int GMSH_FaultZoneMesher::_numNodeHeavSup[3] = {3, 2, 6};

/*!
 * \brief corresponding quad8 node number to seg3 node number for middle side
 */
const int GMSH_FaultZoneMesher::_numNodeJoint[2]   = {7, 5};

//================================================================================
/*!
 * \brief modify the connectivity of face elements connected to the joint elements
 * to take into account the duplicates nodes. Nodes are picked in the _nodeByHeavNode
 * and _nodesByJunctionNode maps. In case of _nodesByJunctionNode, the
 * _heavFuncByJunctionNode map is used to determinate the corresponding node.
 */
//================================================================================
void GMSH_FaultZoneMesher::ModifyElementsConnectivity(GFace* gFace){

  // modif connectivity in _connectedElements
  for(elementsIt its = _connectedElements.begin();its != _connectedElements.end(); ++its){
    MElement *mElem = *its;
    SPoint3 bary = mElem->barycenter();
    std::vector<MVertex*> mVerts;
    mElem->getVertices(mVerts);
    for (unsigned j = 0; j < mVerts.size(); j++){
      MVertex *mVert = mVerts[j];
      if (_nodeByHeavNode.find( mVert ) == _nodeByHeavNode.end() &&
          _nodesByJunctionNode.find( mVert ) == _nodesByJunctionNode.end())
        continue;

      std::vector < int > heav = HeavisideFunc(mVert, bary);
      unsigned int size = heav.size();
      if (size == 1){ // if it is a pure heaviside node
        if (heav[0] == 1) // modifying connectivity only if upper side
          mElem->setVertex(j, _nodeByHeavNode[mVert]);
      }
      else{ // if it is a junction node
        std::vector <std::vector< int > > heavFunc = _heavFuncByJunctionNode[mVert];
        assert (heavFunc.size() == size);
        int i = findMatchingHeav(heavFunc, heav);
        std::vector < MVertex*> nodes = _nodesByJunctionNode[mVert];
        assert (nodes.size() == size);
        assert(nodes[i]->onWhat() != 0);
        mElem->setVertex(j, nodes[i]);
      }
    }
  }
}

//================================================================================
/*!
 * \brief modify node positions of the joint elements with distance eps. This function
 * is optional, it give a thickness to the joint elements that helps to view the joint
 * elements appear on the mesh.
 * Nodes in the _nodeByHeavNode and _nodesByJunctionNode maps are moved.
 */
//================================================================================
void GMSH_FaultZoneMesher::ModifyJointNodePosition(double eps){

  // for pure heaviside nodes
  for (std::map<MVertex*,MVertex*>::iterator itm = _nodeByHeavNode.begin();
       itm != _nodeByHeavNode.end(); itm++){
    // under side
    MVertex *mVert = itm->first;
    SVector3 vectNorm = _vectNormByFissure[_fissureByHeavNode[mVert]];
    vectNorm *= eps;
    mVert->x() -= vectNorm.x();
    mVert->y() -= vectNorm.y();
    mVert->z() -= vectNorm.z();
    // upper side
    mVert = itm->second;
    mVert->x() += vectNorm.x();
    mVert->y() += vectNorm.y();
    mVert->z() += vectNorm.z();
  }

  // for junction nodes
  std::map < MVertex*, std::set < MElement* > > connectedElementsByJunctionNode;
  for (std::map<MVertex*,std::vector<MVertex*> >::iterator itm =
         _nodesByJunctionNode.begin(); itm != _nodesByJunctionNode.end(); itm++){
    std::vector < MVertex* > nodes = itm->second;
    for (unsigned int i=0; i< nodes.size(); i++){
      std::set < MElement* > mElements;
      connectedElementsByJunctionNode[nodes[i]] = mElements;
    }
  }

  std::map<MVertex*,std::set<MElement*> >::iterator itm;
  for(elementsIt its = _connectedElements.begin();
      its != _connectedElements.end(); ++its){
    MElement *mElem = *its;
    std::vector<MVertex*> mVerts;
    mElem->getVertices(mVerts);
    for (unsigned j = 0; j < mVerts.size(); j++){
      itm = connectedElementsByJunctionNode.find( mVerts[j] );
      if (itm != connectedElementsByJunctionNode.end()){
        itm->second.insert(mElem);
      }
    }
  }

  for (itm = connectedElementsByJunctionNode.begin();
       itm != connectedElementsByJunctionNode.end(); itm++){
    MVertex *mVert = itm->first;
    SPoint3 point = mVert->point();

    std::set < MElement* > mElements = itm->second;
    assert(mElements.size() > 0);
    SVector3 vect = SVector3(0,0,0);
    for (std::set < MElement* >::iterator its = mElements.begin();
         its != mElements.end(); its++){
      MElement *mElem = *its;
      SPoint3 bary = mElem->barycenter();
      SVector3 vectPointBary = SVector3(point, bary)*fabs(mElem->getVolume());
      vect += vectPointBary;
    }
    vect.normalize();
    vect *= eps;
    mVert->x() += vect.x();
    mVert->y() += vect.y();
    mVert->z() += vect.z();
  }
}
