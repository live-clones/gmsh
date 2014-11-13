#include "Legendre.h"
#include "GmshDefines.h"
#include "ReferenceSpaceManager.h"

#include "TetEdgeBasis.h"

using namespace std;

TetEdgeBasis::TetEdgeBasis(size_t order){
  // Set Basis Type //
  this->order = order;

  type = TYPE_TET;
  dim  = 3;

  nVertex   = 0;
  nEdge     = 6 * (order + 1);
  nFace     = 4 * (order + 1) * (order - 1);
  nCell     =     (order + 1) * (order - 1) * (order - 2) / 2;
  nFunction = nVertex + nEdge + nFace + nCell;

  // Reference Space //
  const size_t nOrientation = ReferenceSpaceManager::getNOrientation(type);

  const vector<vector<vector<size_t> > >&
    edgeIdx = ReferenceSpaceManager::getEdgeNodeIndex(type);

  const vector<vector<vector<size_t> > >&
    faceIdx = ReferenceSpaceManager::getFaceNodeIndex(type);

  // Alloc Temporary Space //
  const int orderPlus     = order + 1;
  const int orderMinus    = order - 1;
  const int orderMinusTwo = order - 2;

  Polynomial* legendre    = new Polynomial[orderMinus];
  Polynomial* sclLegendre = new Polynomial[orderMinus];
  Polynomial* intLegendre = new Polynomial[orderPlus];

  // Legendre Polynomial //
  Legendre::legendre(legendre, orderMinusTwo);
  Legendre::scaled(sclLegendre, orderMinusTwo);
  Legendre::intScaled(intLegendre, orderPlus);

  // Lagrange Polynomial //
  const Polynomial lagrange[4] =
    {
      Polynomial(Polynomial(1, 0, 0, 0) -
                 Polynomial(1, 1, 0, 0) -
                 Polynomial(1, 0, 1, 0) -
                 Polynomial(1, 0, 0, 1)),

      Polynomial(Polynomial(1, 1, 0, 0)),

      Polynomial(Polynomial(1, 0, 1, 0)),

      Polynomial(Polynomial(1, 0, 0, 1))
    };


  // Basis //
  basis = new vector<Polynomial>**[nOrientation];

  for(size_t s = 0; s < nOrientation; s++)
    basis[s] = new vector<Polynomial>*[nFunction];

  // Edge Based //
  for(size_t s = 0; s < nOrientation; s++){
    size_t i = 0;

    for(int e = 0; e < 6; e++){
      for(int l = 0; l < orderPlus; l++){
        // Nedelec
        if(l == 0){
          vector<Polynomial> tmp1 = lagrange[edgeIdx[s][e][1]].gradient();
          vector<Polynomial> tmp2 = lagrange[edgeIdx[s][e][0]].gradient();

          tmp1[0].mul(lagrange[edgeIdx[s][e][0]]);
          tmp1[1].mul(lagrange[edgeIdx[s][e][0]]);
          tmp1[2].mul(lagrange[edgeIdx[s][e][0]]);

          tmp2[0].mul(lagrange[edgeIdx[s][e][1]]);
          tmp2[1].mul(lagrange[edgeIdx[s][e][1]]);
          tmp2[2].mul(lagrange[edgeIdx[s][e][1]]);

          tmp2[0].sub(tmp1[0]);
          tmp2[1].sub(tmp1[1]);
          tmp2[2].sub(tmp1[2]);

          basis[s][i] = new vector<Polynomial>(tmp2);
        }

        // High Order
        else{
          basis[s][i] =
            new vector<Polynomial>
            ((intLegendre[l].compose(lagrange[edgeIdx[s][e][0]] -
                                     lagrange[edgeIdx[s][e][1]]
                                     ,
                                     lagrange[edgeIdx[s][e][0]] +
                                     lagrange[edgeIdx[s][e][1]])).gradient());
        }
        i++;
      }
    }
  }

  // Face Based //
  for(size_t s = 0; s < nOrientation; s++){
    size_t i = nEdge;

    for(int f = 0; f < 4; f++){
      for(size_t l1 = 1; l1 < order; l1++){
        for(int l2 = 0; l2 + (int)l1 - 1 < orderMinus; l2++){
          // Preliminary Type 1
          Polynomial sum =
            lagrange[faceIdx[s][f][0]] +
            lagrange[faceIdx[s][f][1]] +
            lagrange[faceIdx[s][f][2]];

          Polynomial u =
            intLegendre[l1].compose(lagrange[faceIdx[s][f][1]] -
                                    lagrange[faceIdx[s][f][0]]
                                    ,
                                    lagrange[faceIdx[s][f][0]] +
                                    lagrange[faceIdx[s][f][1]]);
          Polynomial v =
            lagrange[faceIdx[s][f][2]] *
            sclLegendre[l2].compose(lagrange[faceIdx[s][f][2]] * 2 - sum, sum);

          // Preliminary Type 2
          vector<Polynomial> gradU = u.gradient();
          vector<Polynomial> gradV = v.gradient();

          vector<Polynomial> vGradU(gradU);
          vGradU[0].mul(v);
          vGradU[1].mul(v);
          vGradU[2].mul(v);

          vector<Polynomial> uGradV(gradV);
          uGradV[0].mul(u);
          uGradV[1].mul(u);
          uGradV[2].mul(u);

          vector<Polynomial> subGradUV(vGradU);
          subGradUV[0].sub(uGradV[0]);
          subGradUV[1].sub(uGradV[1]);
          subGradUV[2].sub(uGradV[2]);

          // Preliminary Type 3
          vector<Polynomial> gradL1 = lagrange[faceIdx[s][f][0]].gradient();
          vector<Polynomial> gradL2 = lagrange[faceIdx[s][f][1]].gradient();

          vector<Polynomial> l2GradL1(gradL1);
          l2GradL1[0].mul(lagrange[faceIdx[s][f][1]]);
          l2GradL1[1].mul(lagrange[faceIdx[s][f][1]]);
          l2GradL1[2].mul(lagrange[faceIdx[s][f][1]]);

          vector<Polynomial> l1GradL2(gradL2);
          l1GradL2[0].mul(lagrange[faceIdx[s][f][0]]);
          l1GradL2[1].mul(lagrange[faceIdx[s][f][0]]);
          l1GradL2[2].mul(lagrange[faceIdx[s][f][0]]);

          vector<Polynomial> subGradL1L2V(l2GradL1);
          subGradL1L2V[0].sub(l1GradL2[0]);
          subGradL1L2V[1].sub(l1GradL2[1]);
          subGradL1L2V[2].sub(l1GradL2[2]);

          subGradL1L2V[0].mul(v);
          subGradL1L2V[1].mul(v);
          subGradL1L2V[2].mul(v);


          // Type 1
          basis[s][i] = new vector<Polynomial>((u * v).gradient());
          i++;

          // Type 2
          basis[s][i] = new vector<Polynomial>(subGradUV);
          i++;

          // Type 3
          if(l1 == 1){
            basis[s][i] = new vector<Polynomial>(subGradL1L2V);
            i++;
          }
        }
      }
    }
  }

  // Cell Based //
  const Polynomial one(1, 0, 0, 0);

  for(size_t s = 0; s < nOrientation; s++){
    size_t i = nEdge + nFace;

    for(int l1 = 1; l1 < orderMinus; l1++){
      for(int l2 = 0; l2 + l1 - 1 <  orderMinusTwo; l2++){
        for(int l3 = 0; l3 + l2 + l1 - 1 <  orderMinusTwo; l3++){
          // Preliminary Type 1
          Polynomial u = intLegendre[l1].compose
            (lagrange[0] - lagrange[1],
             lagrange[0] + lagrange[1]);

          Polynomial v = lagrange[2] * sclLegendre[l2].compose
            (lagrange[2] * 2 - (one - lagrange[3]), one - lagrange[3]);

          Polynomial w = lagrange[3] * legendre[l3].compose
            (lagrange[3] * 2 - one);

          // Preliminary Type 2
          vector<Polynomial> gradU = u.gradient();
          vector<Polynomial> gradV = v.gradient();
          vector<Polynomial> gradW = w.gradient();

          vector<Polynomial> vwGradU(gradU);
          vwGradU[0].mul(v);
          vwGradU[1].mul(v);
          vwGradU[2].mul(v);

          vwGradU[0].mul(w);
          vwGradU[1].mul(w);
          vwGradU[2].mul(w);

          vector<Polynomial> uwGradV(gradV);
          uwGradV[0].mul(u);
          uwGradV[1].mul(u);
          uwGradV[2].mul(u);

          uwGradV[0].mul(w);
          uwGradV[1].mul(w);
          uwGradV[2].mul(w);

          vector<Polynomial> uvGradW(gradW);
          uvGradW[0].mul(u);
          uvGradW[1].mul(u);
          uvGradW[2].mul(u);

          uvGradW[0].mul(v);
          uvGradW[1].mul(v);
          uvGradW[2].mul(v);

          vector<Polynomial> term1(vwGradU);
          term1[0].sub(uwGradV[0]);
          term1[1].sub(uwGradV[1]);
          term1[2].sub(uwGradV[2]);

          term1[0].add(uvGradW[0]);
          term1[1].add(uvGradW[1]);
          term1[2].add(uvGradW[2]);

          vector<Polynomial> term2(vwGradU);
          term2[0].add(uwGradV[0]);
          term2[1].add(uwGradV[1]);
          term2[2].add(uwGradV[2]);

          term2[0].sub(uvGradW[0]);
          term2[1].sub(uvGradW[1]);
          term2[2].sub(uvGradW[2]);

          // Preliminary Type 3
          vector<Polynomial> gradL1 = lagrange[0].gradient();
          vector<Polynomial> gradL2 = lagrange[1].gradient();

          vector<Polynomial> l2GradL1(gradL1);
          l2GradL1[0].mul(lagrange[1]);
          l2GradL1[1].mul(lagrange[1]);
          l2GradL1[2].mul(lagrange[1]);

          vector<Polynomial> l1GradL2(gradL2);
          l1GradL2[0].mul(lagrange[0]);
          l1GradL2[1].mul(lagrange[0]);
          l1GradL2[2].mul(lagrange[0]);

          vector<Polynomial> subGradL1L2VW(l2GradL1);
          subGradL1L2VW[0].sub(l1GradL2[0]);
          subGradL1L2VW[1].sub(l1GradL2[1]);
          subGradL1L2VW[2].sub(l1GradL2[2]);

          subGradL1L2VW[0].mul(v);
          subGradL1L2VW[1].mul(v);
          subGradL1L2VW[2].mul(v);

          subGradL1L2VW[0].mul(w);
          subGradL1L2VW[1].mul(w);
          subGradL1L2VW[2].mul(w);


          // Type 1
          basis[s][i] = new vector<Polynomial>((u * v * w).gradient());
          i++;

          // Type 2 -- Part 1
          basis[s][i] = new vector<Polynomial>(term1);
          i++;

          // Type 2 -- Part 2
          basis[s][i] = new vector<Polynomial>(term2);
          i++;

          // Type 3
          if(l1 == 1){
            basis[s][i] = new vector<Polynomial>(subGradL1L2VW);
            i++;
          }
        }
      }
    }
  }

  // Free Temporary Space //
  // Legendre
  delete[] legendre;
  delete[] sclLegendre;
  delete[] intLegendre;
}

TetEdgeBasis::~TetEdgeBasis(void){
  const size_t nOrientation = ReferenceSpaceManager::getNOrientation(type);

  // Basis //
  for(size_t i = 0; i < nOrientation; i++){
    for(size_t j = 0; j < nFunction; j++)
      delete basis[i][j];

    delete[] basis[i];
  }

  delete[] basis;
}
