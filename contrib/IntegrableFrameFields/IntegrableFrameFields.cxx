// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Alexandre Chemin

#include <IntegrableFrameFields.hxx>
#include <IffTools.hxx>
#include <GModel.h>
#include <MTriangle.h>
#include <MQuadrangle.h>
#include <MLine.h>
#include <IffTools.hxx>
#include <ObjectiveFunctions.hxx>
#include <random>
#include <Solver.hxx>

using namespace IFF;

void iffComputeIntegrableFrameField(GModel *gm){
  std::vector<MElement*> elements;
  std::vector<MLine*> lines;
  for(GFace *gf: gm->getFaces()){
    elements.insert(elements.end(), gf->triangles.begin(), gf->triangles.end());
    elements.insert(elements.end(), gf->quadrangles.begin(), gf->quadrangles.end());
  }
  for(GEdge *ge: gm->getEdges())
    lines.insert(lines.end(), ge->lines.begin(), ge->lines.end());

  Mesh m(elements, lines);
  m.printInfos();

  //Test implemented functions
  DirichletEnergieVectCR *fTest = new DirichletEnergieVectCR();
  GLframeConstraint *fTestC = new GLframeConstraint(1.0/(4*m.getMaxEdgeLength()*m.getMaxEdgeLength()));
  SumObjectiveFunction *sum = *(0.54*(*fTest)) + *(10.5*(*fTestC));

  Element *e = m.getElement(0);
  std::vector<double> vRef = e->getDirEdg(0);

  double lower_bound = -1;
  double upper_bound = 1;
  std::uniform_real_distribution<double> unif(lower_bound,upper_bound);
  std::default_random_engine re;
  // for(size_t nTry=0; nTry<100; nTry++){
  //   double theta = unif(re);
   
  //   std::vector<std::vector<double>> solTri;
  //   solTri.resize(3);
  //   for(std::vector<double> &v: solTri)
  //     v.resize(2, 0.0);
  //   solTri[0][0] = cos(4*theta); solTri[0][1] = sin(4*theta);
  //   for(int k=1; k<3; k++){
  //     std::vector<double> v = e->getDirEdg(k);
  //     std::vector<double> n = e->getNormal();
  //     std::vector<double> t = tools::crossprod(n, vRef);
  //     double alpha = atan2(tools::dotprod(v, t), tools::dotprod(v, vRef));
  //     solTri[k][0] = cos(-4*(alpha-theta)); solTri[k][1] = sin(-4*(alpha+theta));
  //   }

  //   double valFunc = -10.0;
  //   // std::cout << "valfunc: " << valFunc << ", theta: " << theta << std::endl;
  //   fTest->evaluateFunction(e, solTri, valFunc);
  //   std::cout << "valfunc: " << valFunc << std::endl;
  // }

  std::vector<std::vector<double>> solTri;
  solTri.resize(3);
  for(std::vector<double> &v: solTri)
    v.resize(2, 0.0);

  for(size_t nTry=0; nTry<2; nTry++){
    for(size_t iN=0; iN<3; iN++)
      for(size_t iF=0; iF<2; iF++){
        solTri[iN][iF] = unif(re);
      }
    std::cout << "------" << std::endl;
    // fTest->checkGradient(e, solTri);
    sum->checkGradient(e, solTri);
  }

  SumObjectiveFunction *GLobj = *fTest + *fTestC;
  // Solver s(&m, 2, fTest, Solver::TYPEUNKNOWN::EDGE);
  // Solver s(&m, 2, fTestC, Solver::TYPEUNKNOWN::EDGE);
  Solver s(&m, 2, GLobj, Solver::TYPEUNKNOWN::EDGE);

  for(Element *l: m.getLines()){
    Edge* e=l->getEdge(0);
    s.addBCDirichlet(std::make_pair(e, 0), 1.0);
    s.addBCDirichlet(std::make_pair(e, 1), 0.0);
  }

  std::map<Edge*, std::vector<double>> sol;
  for(Edge* e: m.getEdges()){
    std::vector<double> solInitEdge{1.0, 0.0};
    sol[e] = solInitEdge;
  }
  
  s.solveLBFGS(sol);

  double funC = 0.0;
  for(Element *e: m.getElements()){
    std::vector<std::vector<double>> solEl;
    solEl.resize(e->getNumUnknown());
    for(size_t l=0; l<solEl.size(); l++)
      solEl[l].resize(s.m_nFields, 0.0);

    for(size_t l=0; l<solEl.size(); l++)
      solEl[l] = sol[e->getEdge(l)];

    double func = 0.0;
    fTestC->evaluateFunction(e, solEl, func);
    // std::cout << "func: " << func << std::endl;
    // std::cout << "------" << std::endl;
    // fTestC->checkGradient(e, solEl);
    funC += func;
  }
  std::cout << "func constr: " << funC << std::endl;
}

