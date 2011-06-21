#include <dofManager.h>
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
      for (int j = 0; j < recvBuf[index].size(); j++) {
        ghostValue[ghostByProc[index][j]] = recvBuf[index][j];
        const Dof &dof = ghostByProc[index][j];
      }
  }
  MPI_Waitall (Msg::GetCommSize(), &reqSend[0], MPI_STATUS_IGNORE);
#endif
}
