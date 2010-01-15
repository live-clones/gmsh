#ifndef _DG_DOF_CONTAINER_H_
#define _DG_DOF_CONTAINER_H_

#include <vector>
#include "fullMatrix.h"
class dgGroupCollection;

struct dgDofContainer {
private:
  dgDofContainer (const dgDofContainer&);  
  int _totalNbElements; 
  int _nbFields;
  dgGroupCollection &_groups;
  int _dataSizeGhost; 
  fullVector<double> * _ghostData;
  inline int getDataSize(){return _dataSize;}
  // parallel
  void buildParallelStructure();
  bool _parallelStructureExists;
  int *countSend,*countRecv,*shiftSend,*shiftRecv,*groupShiftRecv;
  double *sendBuf, *recvBuf;
public:
  //todo move those 3 to private
  fullVector<double> * _data; // the full data itself
  std::vector<fullMatrix<double> *> _dataProxys; // proxys 
  int _dataSize; // the full data size i.e. concerning all groups (not ghost, see bellow)

  inline fullMatrix<double> &getGroupProxy(int gId){ return *(_dataProxys[gId]); }
  dgDofContainer (dgGroupCollection &groups, int nbFields);
  ~dgDofContainer ();  
  int getNbElements() {return _totalNbElements;}
  void scatter();
};
#endif
