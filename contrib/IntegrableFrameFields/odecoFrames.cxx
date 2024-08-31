#include <odecoFrames.hxx>
#include <IffTools.hxx>
#include <vector>
#include <Eigen/Dense>

namespace IFF{
  size_t GLIso2D::nUnknown = 2;
  size_t OdecoIso2D::nUnknown = 3;
  size_t OdecoAniso2D::nUnknown = 5;

  // ------------------------------- Odeco isotrope 2D frame representation
  std::vector<std::vector<double>> OdecoIso2D::getAlignmentLinConstr(const std::vector<double> &dir){
    std::vector<double> dirN = dir;
    tools::normalize(dirN);
    std::vector<std::vector<double>> dirs(1, dirN);
    OdecoIso2D frame(dirs);
    // f is the matrix such as frame = f.A, for any A
    Eigen::Vector3d f(frame.m_frame.data());
    Eigen::MatrixXd matLinConstr = (f.transpose().fullPivLu().kernel()).transpose();
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

  std::vector<std::vector<double>> OdecoIso2D::getSizeLinConstr(double sizeFrame){
    std::vector<double> dirN{sizeFrame, 0.0};
    std::vector<std::vector<double>> dirs(1, dirN);
    OdecoIso2D frame(dirs);
    // f is the matrix such as frame = f.A, for any A
    Eigen::MatrixXd f{
      {0.0, 1.0, 0.0},
      {0.0, 0.0, 1.0}
    };
    Eigen::MatrixXd matLinConstr = (f.transpose().fullPivLu().kernel()).transpose();
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

  std::vector<std::vector<double>> OdecoIso2D::getAlignmentPlusTangentSizeLinConstr(const std::vector<double> &dir){
    std::vector<double> dirN = dir;
    tools::normalize(dirN);
    std::vector<double> normal = {0.0, 0.0, 1.0};
    std::vector<double> dirM = tools::crossprod(normal, dirN);
    std::vector<std::vector<double>> dirs{dirN, dirM};
    OdecoAniso2D frame(dirs);
    // f is the matrix such as frame = f.A, for any A
    Eigen::MatrixXd f{
      {frame.m_frame[0], frame.m_frame[1], frame.m_frame[2]}
    };
    // Eigen::MatrixXd matLinConstr = (f.fullPivLu().kernel()).transpose();
    // Eigen::MatrixXd matLinConstr = f;
    std::vector<std::vector<double>> matLinConstr;
    matLinConstr.resize(1);
    matLinConstr[0].resize(OdecoIso2D::nUnknown, 0.0);
    matLinConstr[0][0] = frame.m_frame[0]; matLinConstr[0][1] = frame.m_frame[1]; matLinConstr[0][2] = frame.m_frame[2];
    double normV = tools::norm2(matLinConstr[0]);
    matLinConstr[0][0] /= normV; matLinConstr[0][1] /= normV; matLinConstr[0][2] /= normV;
    
    std::vector<std::vector<double>> linConstr;
    linConstr.resize(matLinConstr.size());
    for(size_t k=0; k<matLinConstr.size(); k++)
      linConstr[k].resize(matLinConstr[0].size(), 0.0);
    for(size_t k=0; k<matLinConstr.size(); k++)
      for(size_t l=0; l<matLinConstr[0].size(); l++)
        linConstr[k][l] = matLinConstr[k][l];
    return linConstr;
  }
  
  void OdecoIso2D::getCRRotOperator(Element *e, std::vector<std::vector<std::vector<double>>> &rotOp){
    // int nEdges = e->getNumEdges();
    // rotOp.resize(nEdges);
    // for(std::vector<std::vector<double>> &vv: rotOp){
    //   vv.resize(3);
    //   for(std::vector<double> &v: vv)
    //     v.resize(3, 0.0);
    // }
    // std::vector<double> vRef = e->getDirEdg(0);
    // std::vector<double> n = e->getNormal();
    // std::vector<double> t = tools::crossprod(n, vRef);
    // rotOp[0][0][0] = 1.0; rotOp[0][1][1] = 1.0; rotOp[0][2][2] = 1.0;
    // for(int iEdg=1; iEdg<nEdges; iEdg++){
    //   std::vector<double> vEdg = e->getDirEdg(iEdg);
    //   double alpha = atan2(tools::dotprod(t,vEdg), tools::dotprod(vRef,vEdg));
    //   rotOp[iEdg][0][0] = 1.0; rotOp[iEdg][0][1] =          0.0; rotOp[iEdg][0][2] = 0.0;
    //   rotOp[iEdg][1][0] = 0.0; rotOp[iEdg][1][1] = cos(4*alpha); rotOp[iEdg][1][2] = -sin(4*alpha);
    //   rotOp[iEdg][2][0] = 0.0; rotOp[iEdg][2][1] = sin(4*alpha); rotOp[iEdg][2][2] = cos(4*alpha);
    // }
    OdecoIso2D::getCRRotOperatorWithDefinedRef(e, rotOp, 0);
  }

  void OdecoIso2D::getCRRotOperatorWithDefinedRef(Element *e, std::vector<std::vector<std::vector<double>>> &rotOp, int indLocEdgeRef){
    int nEdges = e->getNumEdges();
    rotOp.resize(nEdges);
    for(std::vector<std::vector<double>> &vv: rotOp){
      vv.resize(3);
      for(std::vector<double> &v: vv)
        v.resize(3, 0.0);
    }
    std::vector<double> vRef = e->getDirEdg(indLocEdgeRef);
    std::vector<double> n = e->getNormal();
    std::vector<double> t = tools::crossprod(n, vRef);
    rotOp[0][0][0] = 1.0; rotOp[0][1][1] = 1.0; rotOp[0][2][2] = 1.0;
    for(int iEdg=1; iEdg<nEdges; iEdg++){
      std::vector<double> vEdg = e->getDirEdg((indLocEdgeRef+iEdg)%nEdges);
      double alpha = atan2(tools::dotprod(t,vEdg), tools::dotprod(vRef,vEdg));
      rotOp[iEdg][0][0] = 1.0; rotOp[iEdg][0][1] =          0.0; rotOp[iEdg][0][2] = 0.0;
      rotOp[iEdg][1][0] = 0.0; rotOp[iEdg][1][1] = cos(4*alpha); rotOp[iEdg][1][2] = -sin(4*alpha);
      rotOp[iEdg][2][0] = 0.0; rotOp[iEdg][2][1] = sin(4*alpha); rotOp[iEdg][2][2] = cos(4*alpha);
    }
  }

  void OdecoIso2D::getRotatedSol(const std::vector<double> &sol, std::vector<double> &solRotated, double alpha){
    std::vector<std::vector<double>> rotOp;
    rotOp.resize(3);
    for(std::vector<double> &v: rotOp){
      v.resize(3, 0.0);
    }
    rotOp[0][0] = 1.0; rotOp[0][1] =          0.0; rotOp[0][2] = 0.0;
    rotOp[1][0] = 0.0; rotOp[1][1] = cos(4*alpha); rotOp[1][2] = -sin(4*alpha);
    rotOp[2][0] = 0.0; rotOp[2][1] = sin(4*alpha); rotOp[2][2] = cos(4*alpha);

    int nFields = sol.size();
    solRotated.resize(nFields, 0.0);
    for(size_t jField=0; jField<nFields; jField++)
      for(size_t kField=0; kField<nFields; kField++)
        solRotated[jField] += rotOp[jField][kField]*sol[kField];
  }
  
  void OdecoIso2D::getRotatedSolEl(Element *e, const std::vector<std::vector<double>> &solEl, std::vector<std::vector<double>> &solRotated){
    std::vector<std::vector<std::vector<double>>> rotOp;
    getCRRotOperator(e, rotOp);
    int nFields = solEl[0].size();
    solRotated.resize(solEl.size());
    for(std::vector<double> &v: solRotated)
      v.resize(solEl[0].size(), 0.0);
    for(size_t iEdg=0; iEdg<solRotated.size(); iEdg++)
      for(size_t jField=0; jField<nFields; jField++)
        for(size_t kField=0; kField<nFields; kField++)
          solRotated[iEdg][jField] += rotOp[iEdg][jField][kField]*solEl[iEdg][kField];
  }

  void OdecoIso2D::getInvertRotatedGradient(Element *e, const std::vector<double> &localRhsRotated, std::vector<double> &localRhs){
    std::vector<std::vector<std::vector<double>>> rotOp;
    getCRRotOperator(e, rotOp);

    int nEdges = rotOp.size();
    int nFields = rotOp[0].size();

    localRhs.resize(nEdges*nFields, 0.0);
    for(size_t jField=0; jField<nFields; jField++)
      for(size_t jEdg=0; jEdg<nEdges; jEdg++){
        size_t locIndJ = nFields*jEdg + jField;
        for(size_t kField=0; kField<nFields; kField++){
          size_t locIndK = nFields*jEdg + kField;
          localRhs[locIndJ] += localRhsRotated[locIndK] * rotOp[jEdg][kField][jField];
        }
      }
  }

  void OdecoIso2D::getInvertRotatedHessianAndGradient(Element *e, const std::vector<std::vector<double>> &localHessRotated, const std::vector<double> &localRhsRotated, std::vector<std::vector<double>> &localHess, std::vector<double> &localRhs){
    std::vector<std::vector<std::vector<double>>> rotOp;
    getCRRotOperator(e, rotOp);

    int nEdges = rotOp.size();
    int nFields = rotOp[0].size();

    localRhs.resize(nEdges*nFields, 0.0);
    localHess.resize(nEdges*nFields);
    for(auto &v: localHess)
      v.resize(nEdges*nFields, 0.0);    
    // for(size_t jField=0; jField<nFields; jField++){
    //   for(size_t jEdg=0; jEdg<nEdges; jEdg++){
    //     size_t locIndJ = nFields*jEdg + jField;
    //     for(size_t kField=0; kField<nFields; kField++){
    //       size_t locIndK = nFields*jEdg + kField;
    //       localRhs[locIndJ] += localRhsRotated[locIndK] * rotOp[jEdg][kField][jField];
    //     }
    //   }
    // }

    for(size_t jField=0; jField<nFields; jField++){
      for(size_t jEdg=0; jEdg<nEdges; jEdg++){
        size_t locIndJ = nFields*jEdg + jField;
        for(size_t kField=0; kField<nFields; kField++){
          size_t locIndK = nFields*jEdg + kField;
          localRhs[locIndJ] += localRhsRotated[locIndK] * rotOp[jEdg][kField][jField];
          for(size_t iField=0; iField<nFields; iField++){
            for(size_t iEdg=0; iEdg<nEdges; iEdg++){
              size_t locIndI = nFields*iEdg + iField;
              for(size_t pField=0; pField<nFields; pField++){
                size_t locIndP = nFields*iEdg + pField;
                localHess[locIndI][locIndJ] += localHessRotated[locIndP][locIndK] * rotOp[iEdg][pField][iField] * rotOp[jEdg][kField][jField];
              }
            }
          }
        }
      }
    }
  }
  
  // ------------------------------- Odeco anisotrope 2D frame representation
  std::vector<std::vector<double>> OdecoAniso2D::getAlignmentLinConstr(const std::vector<double> &dir){
    std::vector<double> dirN = dir;
    tools::normalize(dirN);
    std::vector<double> normal = {0.0, 0.0, 1.0};
    std::vector<double> dirM = tools::crossprod(normal, dirN);
    for(size_t k=0; k<3; k++)
      dirM[k] *= 0.5;
    std::vector<std::vector<double>> dirs{dirN, dirM};
    OdecoAniso2D frame(dirs);
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

  std::vector<std::vector<double>> OdecoAniso2D::getAlignmentPlusTangentSizeLinConstr(const std::vector<double> &dir){
    std::vector<double> dirN = dir;
    tools::normalize(dirN);
    std::vector<double> normal = {0.0, 0.0, 1.0};
    std::vector<double> dirM = tools::crossprod(normal, dirN);
    for(size_t k=0; k<3; k++)
      dirM[k] *= 0.5;
    std::vector<std::vector<double>> dirs{dirN, dirM};
    OdecoAniso2D frame(dirs);
    std::vector<double> v1{frame.m_frame[0]/1.5, frame.m_frame[1]/0.5, frame.m_frame[2]/0.5, frame.m_frame[3]/1.5, frame.m_frame[4]/1.5};
    std::vector<double> v2{v1[0], -v1[1], -v1[2], v1[3], v1[4]};
    double norm2v1 = tools::norm2(v1);
    double norm2v2 = tools::norm2(v2);
    double psv1v2 = tools::dotprod(v1, v2);

    tools::scale(v1, norm2v2/(norm2v1*norm2v2 - psv1v2*psv1v2));
    tools::scale(v2, psv1v2/(norm2v1*norm2v2 - psv1v2*psv1v2));
    std::vector<double> constraint = tools::diff(v1, v2);
    
    std::vector<std::vector<double>> linConstr;
    linConstr.resize(1);
    linConstr[0].resize(OdecoAniso2D::nUnknown, 0.0);
    for(size_t l=0; l<OdecoAniso2D::nUnknown; l++)
      linConstr[0][l] = constraint[l];
    return linConstr;
  }

  void OdecoAniso2D::getCRRotOperator(Element *e, std::vector<std::vector<std::vector<double>>> &rotOp){
    int nEdges = e->getNumEdges();
    rotOp.resize(nEdges);
    for(std::vector<std::vector<double>> &vv: rotOp){
      vv.resize(5);
      for(std::vector<double> &v: vv)
        v.resize(5, 0.0);
    }
    std::vector<double> vRef = e->getDirEdg(0);
    std::vector<double> n = e->getNormal();
    std::vector<double> t = tools::crossprod(n, vRef);
    rotOp[0][0][0] = 1.0; rotOp[0][1][1] = 1.0; rotOp[0][2][2] = 1.0; rotOp[0][3][3] = 1.0; rotOp[0][4][4] = 1.0;
    for(int iEdg=1; iEdg<nEdges; iEdg++){
      std::vector<double> vEdg = e->getDirEdg(iEdg);
      double alpha = atan2(tools::dotprod(t,vEdg), tools::dotprod(vRef,vEdg));
      rotOp[iEdg][0][0] = 1.0;
      rotOp[iEdg][1][1] = cos(2*alpha); rotOp[iEdg][1][2] = -sin(2*alpha);
      rotOp[iEdg][2][1] = sin(2*alpha); rotOp[iEdg][2][2] =  cos(2*alpha);
      rotOp[iEdg][3][3] = cos(4*alpha); rotOp[iEdg][3][4] = -sin(4*alpha);
      rotOp[iEdg][4][3] = sin(4*alpha); rotOp[iEdg][4][4] =  cos(4*alpha);
    }
  }

  void OdecoAniso2D::getRotatedSol(const std::vector<double> &sol, std::vector<double> &solRotated, double alpha){
    std::vector<std::vector<double>> rotOp;
    rotOp.resize(5);
    for(std::vector<double> &v: rotOp){
      v.resize(5, 0.0);
    }
    rotOp[0][0] = 1.0;
    rotOp[1][1] = cos(2*alpha); rotOp[1][2] = -sin(2*alpha);
    rotOp[2][1] = sin(2*alpha); rotOp[2][2] =  cos(2*alpha);
    rotOp[3][3] = cos(4*alpha); rotOp[3][4] = -sin(4*alpha);
    rotOp[4][3] = sin(4*alpha); rotOp[4][4] =  cos(4*alpha);

    int nFields = sol.size();
    solRotated.resize(nFields, 0.0);
    for(size_t jField=0; jField<nFields; jField++)
      for(size_t kField=0; kField<nFields; kField++)
        solRotated[jField] += rotOp[jField][kField]*sol[kField];
  }
  
  void OdecoAniso2D::getRotatedSolEl(Element *e, const std::vector<std::vector<double>> &solEl, std::vector<std::vector<double>> &solRotated){
    std::vector<std::vector<std::vector<double>>> rotOp;
    getCRRotOperator(e, rotOp);
    int nFields = solEl[0].size();
    solRotated.resize(solEl.size());
    for(std::vector<double> &v: solRotated)
      v.resize(solEl[0].size(), 0.0);
    for(size_t iEdg=0; iEdg<solRotated.size(); iEdg++)
      for(size_t jField=0; jField<nFields; jField++)
        for(size_t kField=0; kField<nFields; kField++)
          solRotated[iEdg][jField] += rotOp[iEdg][jField][kField]*solEl[iEdg][kField];
  }

  void OdecoAniso2D::getInvertRotatedGradient(Element *e, const std::vector<double> &localRhsRotated, std::vector<double> &localRhs){
    std::vector<std::vector<std::vector<double>>> rotOp;
    getCRRotOperator(e, rotOp);

    int nEdges = rotOp.size();
    int nFields = rotOp[0].size();

    localRhs.resize(nEdges*nFields, 0.0);
    for(size_t jField=0; jField<nFields; jField++)
      for(size_t jEdg=0; jEdg<nEdges; jEdg++){
        size_t locIndJ = nFields*jEdg + jField;
        for(size_t kField=0; kField<nFields; kField++){
          size_t locIndK = nFields*jEdg + kField;
          localRhs[locIndJ] += localRhsRotated[locIndK] * rotOp[jEdg][kField][jField];
        }
      }
  }

  void OdecoAniso2D::getInvertRotatedHessianAndGradient(Element *e, const std::vector<std::vector<double>> &localHessRotated, const std::vector<double> &localRhsRotated, std::vector<std::vector<double>> &localHess, std::vector<double> &localRhs){
    std::vector<std::vector<std::vector<double>>> rotOp;
    getCRRotOperator(e, rotOp);

    int nEdges = rotOp.size();
    int nFields = rotOp[0].size();

    localRhs.resize(nEdges*nFields, 0.0);
    localHess.resize(nEdges*nFields);
    for(auto &v: localHess)
      v.resize(nEdges*nFields, 0.0);    
    // for(size_t jField=0; jField<nFields; jField++){
    //   for(size_t jEdg=0; jEdg<nEdges; jEdg++){
    //     size_t locIndJ = nFields*jEdg + jField;
    //     for(size_t kField=0; kField<nFields; kField++){
    //       size_t locIndK = nFields*jEdg + kField;
    //       localRhs[locIndJ] += localRhsRotated[locIndK] * rotOp[jEdg][kField][jField];
    //     }
    //   }
    // }

    for(size_t jField=0; jField<nFields; jField++){
      for(size_t jEdg=0; jEdg<nEdges; jEdg++){
        size_t locIndJ = nFields*jEdg + jField;
        for(size_t kField=0; kField<nFields; kField++){
          size_t locIndK = nFields*jEdg + kField;
          localRhs[locIndJ] += localRhsRotated[locIndK] * rotOp[jEdg][kField][jField];
          for(size_t iField=0; iField<nFields; iField++){
            for(size_t iEdg=0; iEdg<nEdges; iEdg++){
              size_t locIndI = nFields*iEdg + iField;
              for(size_t pField=0; pField<nFields; pField++){
                size_t locIndP = nFields*iEdg + pField;
                localHess[locIndI][locIndJ] += localHessRotated[locIndP][locIndK] * rotOp[iEdg][pField][iField] * rotOp[jEdg][kField][jField];
              }
            }
          }
        }
      }
    }
  }
  
  // ------------------------------- Classic 2D frame representation (cos(4*theta), sin(4*theta))
  void GLIso2D::getCRRotOperator(Element *e, std::vector<std::vector<std::vector<double>>> &rotOp){
    int nEdges = e->getNumEdges();
    rotOp.resize(nEdges);
    for(std::vector<std::vector<double>> &vv: rotOp){
      vv.resize(2);
      for(std::vector<double> &v: vv)
        v.resize(2, 0.0);
    }
    std::vector<double> vRef = e->getDirEdg(0);
    std::vector<double> n = e->getNormal();
    std::vector<double> t = tools::crossprod(n, vRef);
    rotOp[0][0][0] = 1.0; rotOp[0][1][1] = 1.0;
    for(int iEdg=0; iEdg<nEdges; iEdg++){
      std::vector<double> vEdg = e->getDirEdg(iEdg);
      double alpha = atan2(tools::dotprod(t,vEdg), tools::dotprod(vRef,vEdg));
      rotOp[iEdg][0][0] = cos(4*alpha); rotOp[iEdg][0][1] = -sin(4*alpha);
      rotOp[iEdg][1][0] = sin(4*alpha); rotOp[iEdg][1][1] =  cos(4*alpha);
    }
  }

  void GLIso2D::getRotatedSolEl(Element *e, const std::vector<std::vector<double>> &solEl, std::vector<std::vector<double>> &solRotated){
    std::vector<std::vector<std::vector<double>>> rotOp;
    getCRRotOperator(e, rotOp);
    int nFields = solEl[0].size();
    solRotated.resize(solEl.size());
    for(std::vector<double> &v: solRotated)
      v.resize(solEl[0].size(), 0.0);
    for(size_t iEdg=0; iEdg<solRotated.size(); iEdg++)
      for(size_t jField=0; jField<nFields; jField++)
        for(size_t kField=0; kField<nFields; kField++)
          solRotated[iEdg][jField] += rotOp[iEdg][jField][kField]*solEl[iEdg][kField];
  }

  void GLIso2D::getInvertRotatedGradient(Element *e, const std::vector<double> &localRhsRotated, std::vector<double> &localRhs){
    std::vector<std::vector<std::vector<double>>> rotOp;
    getCRRotOperator(e, rotOp);

    int nEdges = rotOp.size();
    int nFields = rotOp[0].size();

    localRhs.resize(nEdges*nFields, 0.0);
    for(size_t jField=0; jField<nFields; jField++)
      for(size_t jEdg=0; jEdg<nEdges; jEdg++){
        size_t locIndJ = nFields*jEdg + jField;
        for(size_t kField=0; kField<nFields; kField++){
          size_t locIndK = nFields*jEdg + kField;
          localRhs[locIndJ] += localRhsRotated[locIndK] * rotOp[jEdg][kField][jField];
        }
      }
  }
}
