// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <dofManager.h>
#include "GmshConfig.h"

#ifdef HAVE_MPI
#include "mpi.h"
#endif

template<>
void dofManager<double>::scatterSolution()
{
#ifdef HAVE_MPI
  if (!_parallelFinalized) {
    _parallelFinalize();
  }
  MPI_Status status;
  std::vector<std::vector<double> > sendBuf(Msg::GetCommSize()), recvBuf(Msg::GetCommSize());
  std::vector<MPI_Request> reqRecv(Msg::GetCommSize()), reqSend(Msg::GetCommSize());
  for (int i = 0; i<Msg::GetCommSize(); i++) {
    reqRecv[i] = reqSend[i] = MPI_REQUEST_NULL;
    if (!ghostByProc[i].empty()) {
      recvBuf[i].resize(ghostByProc[i].size());
      MPI_Irecv (&recvBuf[i][0], recvBuf[i].size(), MPI_DOUBLE, i, 0, MPI_COMM_WORLD, &reqRecv[i]);
    }
    if (!parentByProc[i].empty()) {
      getDofValue(parentByProc[i], sendBuf[i]);
      MPI_Isend(&sendBuf[i][0], sendBuf[i].size(), MPI_DOUBLE, i, 0, MPI_COMM_WORLD, &reqSend[i]);
    }
  }
  int index;
  while (MPI_Waitany (Msg::GetCommSize(), &reqRecv[0], &index, &status) == 0 && index != MPI_UNDEFINED) {
    if (status.MPI_TAG == 0)
      for (unsigned int j = 0; j < recvBuf[index].size(); j++) {
        ghostValue[ghostByProc[index][j]] = recvBuf[index][j];
        //const Dof &dof = ghostByProc[index][j];
      }
  }
  MPI_Waitall (Msg::GetCommSize(), &reqSend[0], MPI_STATUS_IGNORE);
#endif
}

void dofManagerBase::_parallelFinalize()
{
  _localSize = unknown.size();
#ifdef HAVE_MPI
  int numStart;
  int numTotal;
  MPI_Status status;
  parentByProc.resize(Msg::GetCommSize());
  ghostByProc.resize(Msg::GetCommSize());
  if (Msg::GetCommRank() == 0){
    numStart = 0;
  }
  else
    MPI_Recv (&numStart, 1, MPI_INT, Msg::GetCommRank()-1, 0, MPI_COMM_WORLD, &status);
  numTotal = numStart + _localSize;
  if (Msg::GetCommRank() != Msg::GetCommSize()-1)
    MPI_Send (&numTotal, 1, MPI_INT, Msg::GetCommRank()+1, 0, MPI_COMM_WORLD);
  MPI_Bcast(&numTotal, 1, MPI_INT, Msg::GetCommSize()-1, MPI_COMM_WORLD);
  for (std::map <Dof, int> ::iterator it = unknown.begin(); it!= unknown.end(); it++)
    it->second += numStart;
  std::vector<std::list<Dof> >  ghostedByProc;
  int *nRequest = new int[Msg::GetCommSize()];
  int *nRequested = new int[Msg::GetCommSize()];
  for (int i = 0; i<Msg::GetCommSize(); i++)
    nRequest[i] = 0;
  for (std::map <Dof, std::pair<int, int> >::iterator it = ghostByDof.begin(); it != ghostByDof.end(); it++) {
    int procId = it->second.first;
    it->second.second = nRequest[procId]++;
  }
  MPI_Alltoall(nRequest, 1, MPI_INT, nRequested, 1, MPI_INT, MPI_COMM_WORLD);
  long int **recv0 = new long int*[Msg::GetCommSize()];
  int **recv1 = new int*[Msg::GetCommSize()];
  long int **send0 = new long int*[Msg::GetCommSize()];
  int **send1 = new int*[Msg::GetCommSize()];
  MPI_Request *reqRecv0 = new MPI_Request[2*Msg::GetCommSize()];
  MPI_Request *reqRecv1 = reqRecv0 + Msg::GetCommSize();
  MPI_Request *reqSend0 = new MPI_Request[Msg::GetCommSize()];
  MPI_Request *reqSend1 = new MPI_Request[Msg::GetCommSize()];
  for (int i = 0; i < Msg::GetCommSize(); i++) {
    send0[i] = new long int[nRequest[i]*2];
    recv0[i] = new long int[nRequested[i]*2];
    send1[i] = new int[nRequested[i]];
    recv1[i] = new int[nRequest[i]];
    reqSend0[i] = reqSend1[i] = reqRecv0[i] = reqRecv1[i] = MPI_REQUEST_NULL;
    parentByProc[i].resize(nRequested[i], Dof(0,0));
    ghostByProc[i].resize(nRequest[i], Dof(0,0));
  }
  for (int i = 0; i<Msg::GetCommSize(); i++)
    nRequest [i] = 0;
  for (std::map <Dof, std::pair<int, int> >::iterator it = ghostByDof.begin(); it != ghostByDof.end(); it++) {
    int proc = it->second.first;
    send0 [proc] [nRequest[proc]*2] = it->first.getEntity();
    send0 [proc] [nRequest[proc]*2+1] = it->first.getType();
    ghostByProc[proc][nRequest[proc]] = it->first;
    nRequest [proc] ++;
  }
  for (int i = 0; i<Msg::GetCommSize(); i++) {
    if (nRequested[i] > 0) {
      MPI_Irecv (recv0[i], 2*nRequested[i], MPI_LONG, i, 0, MPI_COMM_WORLD, &reqRecv0[i]);
    }
    if (nRequest[i] > 0) {
      MPI_Irecv (recv1[i], 2*nRequest[i], MPI_INT, i, 1, MPI_COMM_WORLD, &reqRecv1[i]);
      MPI_Isend (send0[i], 2*nRequest[i], MPI_LONG, i, 0, MPI_COMM_WORLD, &reqSend0[i]);
    }
  }
  int index;
  while (MPI_Waitany (2*Msg::GetCommSize(), reqRecv0, &index, &status) == 0 &&
         index != MPI_UNDEFINED) {
    if (status.MPI_TAG == 0) {
      for (int j = 0; j < nRequested[index]; j++) {
        Dof d(recv0[index][j*2], recv0[index][j*2+1]);
        std::map<Dof, int>::iterator it = unknown.find(d);
        if (it == unknown.end ())
          Msg::Error ("ghost Dof does not exist on parent process");
        send1[index][j] = it->second;
        parentByProc[index][j] = d;
      }
      MPI_Isend(send1[index], nRequested[index], MPI_INT, index, 1,
                MPI_COMM_WORLD, &reqSend1[index]);
    }
  }
  for (int i = 0; i<Msg::GetCommSize(); i++)
  for (int i = 0; i<Msg::GetCommSize(); i++)
    nRequest[i] = 0;
  for (std::map <Dof, std::pair<int, int> >::iterator it = ghostByDof.begin(); it != ghostByDof.end(); it++) {
    int proc = it->second.first;
    unknown[it->first] = recv1 [proc][nRequest[proc] ++];
  }
  MPI_Waitall (Msg::GetCommSize(), reqSend0, MPI_STATUS_IGNORE);
  MPI_Waitall (Msg::GetCommSize(), reqSend1, MPI_STATUS_IGNORE);
  for (int i = 0; i < Msg::GetCommSize(); i++) {
    delete [] send0[i];
    delete [] send1[i];
    delete [] recv0[i];
    delete [] recv1[i];
  }
  delete [] send0;
  delete [] send1;
  delete [] recv0;
  delete [] recv1;
  delete [] reqSend0;
  delete [] reqSend1;
  delete [] reqRecv0;
#endif
  _parallelFinalized = true;
}


