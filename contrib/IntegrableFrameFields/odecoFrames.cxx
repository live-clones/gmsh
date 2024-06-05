#include <odecoFrames.hxx>
#include <IffTools.hxx>
#include <vector>
#include <Eigen/Dense>

namespace IFF{
  size_t OdecoIso2Dplanar::nUnknown = 3;
  size_t OdecoAniso2Dplanar::nUnknown = 5;

  std::vector<std::vector<double>> OdecoAniso2Dplanar::getAlignmentLinConstr(const std::vector<double> &dir){
    std::vector<double> dirN = dir;
    tools::normalize(dirN);
    std::vector<double> normal = {0.0, 0.0, 1.0};
    std::vector<double> dirM = tools::crossprod(normal, dirN);
    for(size_t k=0; k<3; k++)
      dirM[k] *= 0.5;
    std::vector<std::vector<double>> dirs{dirN, dirM};
    OdecoAniso2Dplanar frame(dirs);
    // f is the matrix such as frame = f.A, for any A
    Eigen::MatrixXd f{
      {frame.m_frame[0], 0.0, 0.0, frame.m_frame[3], frame.m_frame[4]},
      {0.0, frame.m_frame[1], frame.m_frame[2], 0.0, 0.0}
    };
    Eigen::MatrixXd matLinConstr = (f.fullPivLu().kernel()).transpose();
    int nRows = static_cast<int>(matLinConstr.rows());
    int nCols = static_cast<int>(matLinConstr.cols());
    for(size_t k=0; k<nRows; k++)
      matLinConstr.row(k).normalize();
    for(size_t k=1; k<nRows; k++){
      for(size_t l=0; l<k; l++){
	matLinConstr.row(k) = matLinConstr.row(k) - matLinConstr.row(l).dot(matLinConstr.row(k)) * matLinConstr.row(l);
      }
      matLinConstr.row(k).normalize();
    }
    
    std::vector<std::vector<double>> linConstr;
    linConstr.resize(nRows);
    for(size_t k=0; k<nRows; k++)
      linConstr[k].resize(nCols, 0.0);
    for(size_t k=0; k<nRows; k++)
      for(size_t l=0; l<nCols; l++)
	linConstr[k][l] = matLinConstr(k,l);
    return linConstr;
  }
}
