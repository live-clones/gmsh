#include <vector>
#include <gmsh/MTriangle.h>


#if defined(HAVE_SOLVER)
#include <gmsh/linearSystemPETSc.h>
#include <gmsh/linearSystemCSR.h>
#include <gmsh/linearSystemFull.h>
#endif


void laplacianSmoothing(const std::vector<MVertex *> & nodes,
                        const std::map<MEdge, std::vector<MTriangle *>, MEdgeLessThan> & edge2Triangles,
                        const std::vector<std::vector<MVertex *> > & loops,
                        const std::vector<bool> & bc,
                        std::vector<double> & u,
                        double gravity = 0)
{
  // assemble matrix
#if defined(HAVE_SOLVER)
#if defined(HAVE_PETSC)
  linearSystemPETSc<double> *lsys = new linearSystemPETSc<double>;
  std::string options = "-ksp_type preonly -pc_type lu ";
#if defined(PETSC_HAVE_MUMPS)
  options += "-pc_factor_mat_solver_type mumps";
#elif defined(PETSC_HAVE_MKL_PARDISO)
  options += "-pc_factor_mat_solver_type mkl_pardiso";
#elif defined(PETSC_HAVE_UMFPACK) || defined(PETSC_HAVE_SUITESPARSE)
  options += "-pc_factor_mat_solver_type umfpack";
#endif
  lsys->setParameter("petsc_solver_options", options);
  lsys->setParameter("matrix_reuse", "same_matrix");
#elif defined(HAVE_GMM)
  linearSystemCSRGmm<double> *lsys = new linearSystemCSRGmm<double>;
#else
  linearSystemFull<double> *lsys = new linearSystemFull<double>;
#endif

  lsys->allocate(nodes.size());

#if defined(HAVE_PETSC)
  for(auto it = edge2Triangles.begin(); it != edge2Triangles.end(); ++it) {
    for(int i = 0; i < 2; i++) {
      for(int j = 0; j < 2; j++) {
        lsys->insertInSparsityPattern(it->first.getVertex(i)->getIndex(),
                                      it->first.getVertex(j)->getIndex());
      }
    }
  }
#endif

  for(auto it = edge2Triangles.begin(); it != edge2Triangles.end(); ++it) {
    for(int ij = 0; ij < 2; ij++) {
      MVertex *v0 = it->first.getVertex(ij);
      int index0 = v0->getIndex();
      if(bc[index0]) continue; // boundary condition
      MVertex *v1 = it->first.getVertex(1 - ij);
      int index1 = v1->getIndex();
      MTriangle *tLeft = it->second[0];
      MVertex *vLeft = tLeft->getVertex(0);
      if(vLeft == v0 || vLeft == v1) vLeft = tLeft->getVertex(1);
      if(vLeft == v0 || vLeft == v1) vLeft = tLeft->getVertex(2);
      double e[3] = {v1->x() - v0->x(), v1->y() - v0->y(), v1->z() - v0->z()};
      double ne = sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
      double a[3] = {vLeft->x() - v0->x(), vLeft->y() - v0->y(),
                     vLeft->z() - v0->z()};
      double na = sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
      double thetaL =
        acos((a[0] * e[0] + a[1] * e[1] + a[2] * e[2]) / (na * ne));
      double thetaR = 0.;
      if(it->second.size() == 2) {
        MTriangle *tRight = it->second[1];
        MVertex *vRight = tRight->getVertex(0);
        if(vRight == v0 || vRight == v1) vRight = tRight->getVertex(1);
        if(vRight == v0 || vRight == v1) vRight = tRight->getVertex(2);
        double b[3] = {vRight->x() - v0->x(), vRight->y() - v0->y(),
                       vRight->z() - v0->z()};
        double nb = sqrt(b[0] * b[0] + b[1] * b[1] + b[2] * b[2]);
        thetaR = acos((b[0] * e[0] + b[1] * e[1] + b[2] * e[2]) / (nb * ne));
      }
      double c = (tan(.5 * thetaL) + tan(.5 * thetaR)) / ne;
      lsys->addToMatrix(index0, index1, -c);
      lsys->addToMatrix(index0, index0, c);
    }
  }
  for(std::size_t j = 0; j < loops.size(); j++) {
    const std::vector<MVertex *>& loop = loops[j];
    for(std::size_t i = 0; i < loop.size() - 1; i++) {
      int row = loop[i]->getIndex();
      lsys->addToMatrix(row, row, 1);
    }
  }

  lsys->zeroRightHandSide();
  for(std::size_t j = 0; j < loops.size(); j++) {
    const std::vector<MVertex *>& loop = loops[j];
    for(std::size_t i = 0; i < loop.size() - 1; i++) {
      int row = loop[i]->getIndex();
      lsys->addToRightHandSide(row, u[row]);
      lsys->addToRightHandSide(row, +gravity);
    }
  }
  for(std::size_t row = 0; row < u.size(); row++) {
    lsys->addToRightHandSide(row, -gravity);
  }

  lsys->systemSolve();
  for(std::size_t i = 0; i < nodes.size(); i++) lsys->getFromSolution(i, u[i]);

  delete lsys;
#endif
};
