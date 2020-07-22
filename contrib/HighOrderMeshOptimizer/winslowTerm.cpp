// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "winslowTerm.h"
#include "Numeric.h"

// The SElement (Solver element) that has been sent to the function
// contains 2 enrichments, that can enrich both shape and test functions

void winslowTerm::createData(MElement *e) const
{
  if(_data.find(e->getTypeForMSH()) != _data.end()) return;
  winslowDataAtGaussPoint d;
  int nbSF = (int)e->getNumShapeFunctions();
  // int integrationOrder = 2 * (e->getPolynomialOrder() - 1);
  int integrationOrder = 2 * e->getPolynomialOrder();
  // int integrationOrder = 5 * e->getPolynomialOrder();
  int npts;
  IntPt *GP;
  double gs[100][3];
  e->getIntegrationPoints(integrationOrder, &npts, &GP);
  for(int i = 0; i < npts; i++) {
    fullMatrix<double> a(nbSF, 3);
    const double u = GP[i].pt[0];
    const double v = GP[i].pt[1];
    const double w = GP[i].pt[2];
    const double weight = GP[i].weight;
    e->getGradShapeFunctions(u, v, w, gs);
    for(int j = 0; j < nbSF; j++) {
      a(j, 0) = gs[j][0];
      a(j, 1) = gs[j][1];
      a(j, 2) = gs[j][2];
    }
    d.gradSF.push_back(a);
    d.u.push_back(u);
    d.v.push_back(v);
    d.w.push_back(w);
    d.weight.push_back(weight);
  }
  _data[e->getTypeForMSH()] = d;
}

void winslowTerm::createDataNode(MElement *e) const
{
  if(_dataNode.find(e->getTypeForMSH()) != _dataNode.end()) return;
  winslowDataAtNode d;
  int nbSF = (int)e->getNumShapeFunctions();
  int integrationOrder = 2 * (e->getPolynomialOrder() - 1);
  int npts;
  IntPt *GP;
  double gs[100][3];
  for(int i = 0; i < e->getNumVertices(); i++) {
    fullMatrix<double> a(nbSF, 3);
    double u,v,w;
    e->getNode(i,u,v,w);
    e->getGradShapeFunctions(u, v, w, gs);
    for(int j = 0; j < nbSF; j++) {
      a(j, 0) = gs[j][0];
      a(j, 1) = gs[j][1];
      a(j, 2) = gs[j][2];
    }
    d.gradSF.push_back(a);
    d.u.push_back(u);
    d.v.push_back(v);
    d.w.push_back(w);
  }
  _dataNode[e->getTypeForMSH()] = d;
}

// void winslowTerm::computeMetricContrav(fullMatrix<double> &metricContrav, double GradsComput[100][3], MElement *newEl) const{
//   double covG[3][3]={{0.0}};
//   double metricCovG[3][3]={{0.0}};
//   double metricContravGARRAY[3][3]={{0.0}}; //xi,x (comput,phys)
//   int nbSF = (int)newEl->getNumShapeFunctions();
//   for(int k = 0; k < 3; k++)
//     for(int l = 0; l < nbSF; l++){
//       covG[0][k]+=GradsComput[l][k]*newEl->getVertex(l)->x();
//       covG[1][k]+=GradsComput[l][k]*newEl->getVertex(l)->y();
//       covG[2][k]+=GradsComput[l][k]*newEl->getVertex(l)->z();
//     }
//   for(int k = 0; k < 3; k++)
//     for(int l = 0; l < 3; l++)
//       for(int m = 0; m < 3; m++)
//   	metricCovG[k][l]+=covG[m][k]*covG[m][l];
//   inv3x3(metricCovG,metricContravGARRAY);
//   for(int k = 0; k < 3; k++)
//     for(int l = 0; l < 3; l++)
//       metricContrav(k,l)=metricContravGARRAY[k][l];
//       // metricContrav(k,l)=metricCovG[k][l];

//   // double norm=0.0;
//   // for(int k = 0; k < 3; k++)
//   //   for(int l = 0; l < 3; l++){
//   //     double idTerm=0.0;
//   //     if(k==l)
//   //       idTerm=1.0;
//   //     norm+=(metricContrav(k,l)-idTerm)*(metricContrav(k,l)-idTerm);
//   //   }
//   // norm=sqrt(norm);
//   // if(norm>1e-8){
//   //   printf("pb metric\n");
//   //   printf("norm : %g\n",norm);
//   //   metricContrav.print();
//   //   exit(0);
//   // }
  
//   //DBG metric id
//   // metricContrav.setAll(0.0);
//   // for(int k = 0; k < 3; k++)
//   //   metricContrav(k,k)=1.0;
//   return;
// }

void winslowTerm::computeMetricContrav(fullMatrix<double> &metricContrav, int i , MElement *newEl, MElement *linEl) const{
  double contravG[3][3]={{0.0}};
  double metricCovG[3][3]={{0.0}}; //x,xi (phys,comput)
  double metricContravGARRAY[3][3]={{0.0}}; //xi,x (comput,phys)
  int nbSF = (int)newEl->getNumShapeFunctions();
  winslowDataAtGaussPoint &d = _data[newEl->getTypeForMSH()];
  const fullMatrix<double> &grads = d.gradSF[i];
  double jacPhys[3][3], invjacPhys[3][3], GradsPhys[100][3];
  const double detJPhys = newEl->getJacobian(grads, jacPhys);
  inv3x3(jacPhys, invjacPhys);
  for(int j = 0; j < nbSF; j++) {
      GradsPhys[j][0] = invjacPhys[0][0] * grads(j, 0) + invjacPhys[0][1] * grads(j, 1) +
                          invjacPhys[0][2] * grads(j, 2);
      GradsPhys[j][1] = invjacPhys[1][0] * grads(j, 0) + invjacPhys[1][1] * grads(j, 1) +
                          invjacPhys[1][2] * grads(j, 2);
      GradsPhys[j][2] = invjacPhys[2][0] * grads(j, 0) + invjacPhys[2][1] * grads(j, 1) +
                          invjacPhys[2][2] * grads(j, 2);
    }
  
  for(int k = 0; k < 3; k++)
    for(int l = 0; l < nbSF; l++){
      contravG[0][k]+=GradsPhys[l][k]*linEl->getVertex(l)->x();
      contravG[1][k]+=GradsPhys[l][k]*linEl->getVertex(l)->y();
      contravG[2][k]+=GradsPhys[l][k]*linEl->getVertex(l)->z();
    }

  for(int k = 0; k < 3; k++)
    for(int l = 0; l < 3; l++)
      metricContrav(k,l)=contravG[k][l];
  return;
}

void winslowTerm::elementMatrix(SElement *se, fullMatrix<double> &m) const
{
  MElement *e = se->getMeshElement();
  MElementFactory f;
  std::vector<MVertex *> newVertices;
  newVertices.reserve(e->getNumVertices());
  for(int i = 0; i < e->getNumVertices(); i++){
    MVertex *vert = e->getVertex(i);
    double coordPhysicalX=(*_currentSolution)[vert][0];
    double coordPhysicalY=(*_currentSolution)[vert][1];
    double coordPhysicalZ=(*_currentSolution)[vert][2];
    MVertex *newVert = new MVertex(coordPhysicalX,coordPhysicalY,coordPhysicalZ);
    newVertices.push_back(newVert);
  }  
  MElement *newEl = f.create(e->getTypeForMSH(), newVertices);
  
  createData(e);
  
  winslowDataAtGaussPoint &d = _data[e->getTypeForMSH()];
  int npts = d.u.size();
  m.setAll(0.);
  
  int nbSF = (int)e->getNumShapeFunctions();
  fullMatrix<double> metricContravG(3, 3); //xi,x (comput,physic)
  fullMatrix<double> GradDiscr(nbSF, 3);
  fullMatrix<double> GradDiscrT(3,  nbSF);
  fullMatrix<double> metricContravGTimesGradDiscrT(3 , nbSF);
  double jacComput[3][3], invjacComput[3][3], GradsComput[100][3];
  for(int i = 0; i < npts; i++){
    const double weight = d.weight[i];
    const fullMatrix<double> &grads = d.gradSF[i];
    const double detJComput = e->getJacobian(grads, jacComput);
    inv3x3(jacComput, invjacComput);

    for(int j = 0; j < nbSF; j++) {
      GradsComput[j][0] = invjacComput[0][0] * grads(j, 0) + invjacComput[0][1] * grads(j, 1) +
                          invjacComput[0][2] * grads(j, 2);
      GradsComput[j][1] = invjacComput[1][0] * grads(j, 0) + invjacComput[1][1] * grads(j, 1) +
                          invjacComput[1][2] * grads(j, 2);
      GradsComput[j][2] = invjacComput[2][0] * grads(j, 0) + invjacComput[2][1] * grads(j, 1) +
                          invjacComput[2][2] * grads(j, 2);
    }
    for(int j = 0; j < nbSF; j++) {
      GradDiscr(j, 0) = GradDiscrT(0, j) = GradsComput[j][0];
      GradDiscr(j, 1) = GradDiscrT(1, j) = GradsComput[j][1];
      GradDiscr(j, 2) = GradDiscrT(2, j) = GradsComput[j][2];
    }

    //Computing contravariant metric derivative
    double ff[256];
    se->nodalTestFunctions(d.u[i], d.v[i], d.w[i], ff);
    fullMatrix<double> ffFM(nbSF,1);
    for(int l = 0; l < nbSF; l++){
      ffFM(l,0)=ff[l];
    }
    fullMatrix<double> alphaGauss(3,1);
    alphaGauss.setAll(0.0);
    for(int j=0;j<3;j++)
      for(int l = 0; l < nbSF; l++){
	MVertex *vert = e->getVertex(l);
	alphaGauss(j,0) += (*_alpha)[vert][j]*ff[l];
      }
    // //DBG norm alpha
    // double norm=0.0;
    // for(int j=0;j<3;j++)
    //   norm+=alphaGauss(j,0)*alphaGauss(j,0);
    // norm=sqrt(norm);
    // if(norm>1e-10){
    //   printf("norm alpha : %g\n",norm);
    //   alphaGauss.print();
    //   exit(0);
    // }
    //Compute contravariant metric
    // computeMetricContrav(metricContravG, GradsComput, newEl);
    computeMetricContrav(metricContravG, i, newEl, e);
    
    metricContravGTimesGradDiscrT.setAll(0.0);
    metricContravG.mult(GradDiscrT,metricContravGTimesGradDiscrT);
    
    m.gemm(GradDiscr, metricContravGTimesGradDiscrT, weight * detJComput, 1.);
    fullMatrix<double> alphaTimesGradDiscrT(1 , nbSF);
    alphaGauss.transpose().mult(GradDiscrT,alphaTimesGradDiscrT);
    m.gemm(ffFM, alphaTimesGradDiscrT, -1.0 * weight * detJComput, 1.);
  }
  for(int i = 0; i < newVertices.size(); i++){
    delete newVertices[i];
  }
  delete newEl;
  return;
}

void winslowTerm::elementVector(SElement *se, fullVector<double> &m) const
{
  
  return;
}
