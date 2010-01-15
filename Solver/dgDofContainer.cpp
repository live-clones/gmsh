#include "GmshConfig.h"
#include "dgDofContainer.h"
#include "dgGroupOfElements.h"
#ifdef HAVE_MPI
#include "mpi.h"
#else
#include "string.h"
#endif
dgDofContainer::dgDofContainer (dgGroupCollection &groups, int nbFields):
  _groups(groups)
{
  _dataSize = 0;
  _dataSizeGhost=0;
  _totalNbElements = 0;
  _parallelStructureExists = false;
  _nbFields = nbFields;
  for (int i=0; i< _groups.getNbElementGroups();i++){
    int nbNodes    = _groups.getElementGroup(i)->getNbNodes();
    int nbElements = _groups.getElementGroup(i)->getNbElements();
    _totalNbElements +=nbElements;
    _dataSize += nbNodes*_nbFields*nbElements;
  }

  // allocate the big vectors
  _data      = new fullVector<double>(_dataSize);
  // create proxys for each group
  int offset = 0;
  _dataProxys.resize(_groups.getNbElementGroups()+_groups.getNbGhostGroups());
  for (int i=0;i<_groups.getNbElementGroups();i++){    
    dgGroupOfElements *group = _groups.getElementGroup(i);
    int nbNodes    = group->getNbNodes();
    int nbElements = group->getNbElements();
    _dataProxys[i] = new fullMatrix<double> (&(*_data)(offset),nbNodes, _nbFields*nbElements);
    offset += nbNodes*_nbFields*nbElements;
  }  

  //ghosts
  
  int totalNbElementsGhost =0;
  for (int i=0; i<_groups.getNbGhostGroups(); i++){
    int nbNodes    = _groups.getGhostGroup(i)->getNbNodes();
    int nbElements = _groups.getGhostGroup(i)->getNbElements();
    totalNbElementsGhost +=nbElements;
    _dataSizeGhost += nbNodes*_nbFields*nbElements;
  }

  _dataProxys.resize(_groups.getNbElementGroups()+_groups.getNbGhostGroups());
  _ghostData = new fullVector<double>(_dataSizeGhost);
  offset=0;
  for (int i=0;i<_groups.getNbGhostGroups();i++){    
    dgGroupOfElements *group = _groups.getGhostGroup(i);
    int nbNodes    = group->getNbNodes();
    int nbElements = group->getNbElements();
    _dataProxys[i+_groups.getNbElementGroups()] = new fullMatrix<double> (&(*_ghostData)(offset),nbNodes, _nbFields*nbElements);
    offset += nbNodes*_nbFields*nbElements;
  }  

}

dgDofContainer::~dgDofContainer (){
  if(_parallelStructureExists) {
    delete []countSend;
    delete []countRecv;
    delete []shiftSend;
    delete []shiftRecv;
    delete []groupShiftRecv;
    delete []sendBuf;
    delete []recvBuf;
  }
  if (!_dataSize)return;
  for (int i=0;i<_dataProxys.size();++i) delete _dataProxys[i];
  delete _data;
  delete _ghostData;
}

void dgDofContainer::buildParallelStructure(){
  if (_parallelStructureExists)
    return;

  // MPI all2all buffers
  countSend = new int[Msg::GetCommSize()];
  shiftSend = new int[Msg::GetCommSize()];
  countRecv = new int[Msg::GetCommSize()];
  shiftRecv = new int[Msg::GetCommSize()];
  groupShiftRecv = new int[_groups.getNbGhostGroups()];
  for(int i=0;i<Msg::GetCommSize();i++){
    countSend[i]=0;
    countRecv[i]=0;
    for(size_t j=0;j<_groups.getNbImageElementsOnPartition(i);j++){
      countSend[i] += _groups.getElementGroup(_groups.getImageElementGroup(i,j))->getNbNodes()*_nbFields;
    }
  }
  for(size_t i=0; i<_groups.getNbGhostGroups(); i++){
    dgGroupOfElements *group = _groups.getGhostGroup(i);
    groupShiftRecv[i] = countRecv[group->getGhostPartition()];
    countRecv[group->getGhostPartition()]+=group->getNbElements()*group->getNbNodes()*_nbFields;
  }
  shiftSend[0] = shiftRecv[0]=0;
  int totalSend = countSend[0];
  int totalRecv = countRecv[0];
  for(size_t i=1; i<Msg::GetCommSize(); i++){
    shiftSend[i] = shiftSend[i-1]+countSend[i-1];
    shiftRecv[i] = shiftRecv[i-1]+countRecv[i-1];
    totalSend += countSend[i];
    totalRecv += countRecv[i];
  }
  for(size_t i=0; i<_groups.getNbGhostGroups(); i++){
    dgGroupOfElements *group = _groups.getGhostGroup(i);
    groupShiftRecv[i] += shiftRecv[group->getGhostPartition()];
  }
  sendBuf = new double[totalSend];
  recvBuf = new double[totalRecv];

  _parallelStructureExists = true;
}

void dgDofContainer::scatter() {
  if(!_parallelStructureExists)
    buildParallelStructure();
  //1) fill
  int index=0;
  for(int i=0;i<Msg::GetCommSize();i++){
    for(size_t j=0;j<_groups.getNbImageElementsOnPartition(i);j++){
      fullMatrix<double> &sol = getGroupProxy(_groups.getImageElementGroup(i,j));
      int eid = _groups.getImageElementPositionInGroup(i,j);
      for(int l=0;l<_nbFields;l++) {
        for(int k=0;k<sol.size1();k++) {
          sendBuf[index++] = sol(k, eid *_nbFields+l);
        }
      }
    }
  }
  //2) send
  #ifdef HAVE_MPI
  MPI_Alltoallv(sendBuf,countSend,shiftSend,MPI_DOUBLE,recvBuf,countRecv,shiftRecv,MPI_DOUBLE,MPI_COMM_WORLD);
  #else
  memcpy(recvBuf,sendBuf,countSend[0]*sizeof(double));
  #endif
  //3) distribute
  for(int i=0; i< _groups.getNbGhostGroups();i++) {
    fullMatrix<double> &sol = getGroupProxy(i+_groups.getNbElementGroups());
    fullMatrix<double> recvProxy (recvBuf + groupShiftRecv[i], sol.size1(), sol.size2());
    sol.setAll(recvProxy);
  }
}
