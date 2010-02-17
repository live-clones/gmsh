#ifndef _DG_DOF_CONTAINER_H_
#define _DG_DOF_CONTAINER_H_

#include <vector>
#include "fullMatrix.h"
class dgGroupCollection;
class dgGroupOfElements;

struct dgDofContainer {
private:
  dgDofContainer (const dgDofContainer&);  
  int _totalNbElements; 
  int _nbFields;
  dgGroupCollection &_groups;
  int _dataSizeGhost; 
  fullVector<double> * _data; // the full data itself
  fullVector<double> * _ghostData;
  //inline int getDataSize(){return _dataSize;}
  // parallel
  void buildParallelStructure();
  bool _parallelStructureExists;
  int *countSend,*countRecv,*shiftSend,*shiftRecv,*groupShiftRecv;
  double *sendBuf, *recvBuf;
  std::vector<fullMatrix<double> *> _dataProxys; // proxys 
  std::map<const dgGroupOfElements*,int> _groupId;
public:
  void scale(double f);
  double norm();
  void axpy(dgDofContainer &x, double a=1.);
  inline fullMatrix<double> &getGroupProxy(int gId){ return *(_dataProxys[gId]); }
  inline fullMatrix<double> &getGroupProxy(const dgGroupOfElements* g){ return *(_dataProxys[_groupId[g]]); }
  dgDofContainer (dgGroupCollection *groups, int nbFields);
  ~dgDofContainer ();  
  int getNbElements() {return _totalNbElements;}
  int getNbFields() {return _nbFields;}
  void scatter();
  void save(const std::string name);
  void load(const std::string name);
  void setAll(double v);
  void L2Projection(std::string functionName);
  void Mesh2Mesh_L2Projection(dgDofContainer &other);
  void exportMsh(const std::string name);

  static void registerBindings(binding *b);
  inline dgGroupCollection *getGroups() { return &_groups; }
};
#endif
