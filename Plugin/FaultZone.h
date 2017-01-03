// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _MESH_FAULTZONE_H_
#define _MESH_FAULTZONE_H_

#include <assert.h>
#include "Plugin.h"

class SVector3;
class GEdge;
class GFace;
class MVertex;
class MElement;

extern "C"
{
  GMSH_Plugin *GMSH_RegisterFaultZonePlugin();
}

class GMSH_FaultZonePlugin : public GMSH_PostPlugin{
 public:
  GMSH_FaultZonePlugin(){}
  std::string getName() const { return "FaultZone"; }
  std::string getShortHelp() const{ return "FaultZone generator"; }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber* getOption(int iopt);
  int getNbOptionsStr() const;
  StringXString *getOptionStr(int iopt);
  PView* execute(PView*);
};

//=============================================================================
/*!
 * \brief This class creates joint elements over the embedded edges of a GFace
 */
//=============================================================================
class GMSH_FaultZoneMesher{
 public:
  GMSH_FaultZoneMesher(){}
  void RetriveFissuresInfos(GFace* gFace);
  void DuplicateNodes();
  void ComputeHeavisideFunction();
  void CreateJointElements(GModel* gModel, GFace* gFace, const std::string prefix);
  void ModifyElementsConnectivity(GFace* gFace);
  void ModifyJointNodePosition(const double eps);
 private:
  std::set < MElement* > _jointElements;
  std::map < GEdge* , SVector3 > _vectNormByFissure;
  std::map < MVertex* , GEdge* > _fissureByHeavNode;
  std::map < MVertex* , std::vector < GEdge* > > _fissuresByJunctionNode;
  std::map < MVertex* , std::vector < SVector3 > > _vectsTanByJunctionNode;
  std::set < MElement* > _connectedElements;
  typedef std::set<MElement*>::iterator elementsIt;
  static const SVector3 vectZ;
  static const double tolerance;

  std::map < MVertex* , SVector3 > _vectsTanByTipNode;
  std::map < MVertex*, MVertex* > _nodeByHeavNode;
  std::map < MVertex*, MVertex* > _nodeJointByHeavOrJunctionNode;
  std::map < MVertex*, std::vector < MVertex*> > _nodesByJunctionNode;

  std::map < MVertex*, std::vector <std::vector< int > > > _heavFuncByJunctionNode;

  std::vector < int > HeavisideFunc(MVertex* mVert, SPoint3& sPoint);

  static const int _numNodeHeavInf[3];
  static const int _numNodeHeavSup[3];
  static const int _numNodeJoint[2];
};

//=============================================================================
/*!
 * \brief Compare two heaviside functions
 */
//=============================================================================
inline bool compareHeav(const std::vector< int > heav1, const std::vector< int > heav2){
  assert(heav1.size() >= heav2.size());
  for (unsigned int i=0; i< heav2.size(); i++){
    if (heav1[i] != 0 && heav1[i] != heav2[i] && heav2[i] != 0){
      return false;
    }
  }
  return true;
}

//=============================================================================
/*!
 * \brief Find the matching heaviside function heav, in the vector heavFunc
 */
//=============================================================================
inline int findMatchingHeav(const std::vector< std::vector < int > >& heavFunc,
                            const std::vector< int >& heav){
  unsigned int i=0;
  for (; i < heavFunc.size();i++)
    if(compareHeav(heavFunc[i], heav)) break;
  assert(i<heavFunc.size());
  return i;
}

#endif
