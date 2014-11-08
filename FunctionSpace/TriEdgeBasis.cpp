#include "Legendre.h"
#include "GmshDefines.h"
#include "ReferenceSpaceManager.h"

#include "TriEdgeBasis.h"

using namespace std;

TriEdgeBasis::TriEdgeBasis(size_t order){
  // Set Basis Type //
  this->order = order;

  type = TYPE_TRI;
  dim  = 2;

  nVertex   = 0;
  nEdge     = 3 * (order + 1);
  nFace     = ((order - 1) * order + order - 1);
  nCell     = 0;
  nFunction = nVertex + nEdge + nFace + nCell;

  // Reference Space //
  const size_t nOrientation = ReferenceSpaceManager::getNOrientation(type);

  const vector<vector<vector<size_t> > >&
    edgeIdx = ReferenceSpaceManager::getEdgeNodeIndex(type);

  const vector<vector<vector<size_t> > >&
    faceIdx = ReferenceSpaceManager::getFaceNodeIndex(type);

  // Alloc Some Space //
  const int orderPlus  = order + 1;
  const int orderMinus = order - 1;

  Polynomial* legendre    = new Polynomial[orderPlus];
  Polynomial* intLegendre = new Polynomial[orderPlus];

  // Legendre Polynomial //
  Legendre::legendre(legendre, order);
  Legendre::intScaled(intLegendre, orderPlus);

  // Lagrange //
  const Polynomial lagrange[3] =
    {
      Polynomial(Polynomial(1, 0, 0, 0) -
                 Polynomial(1, 1, 0, 0) -
                 Polynomial(1, 0, 1, 0)),

      Polynomial(Polynomial(1, 1, 0, 0)),

      Polynomial(Polynomial(1, 0, 1, 0))
    };

  // Basis //
  basis = new vector<Polynomial>**[nOrientation];

  for(size_t s = 0; s < nOrientation; s++)
    basis[s] = new vector<Polynomial>*[nFunction];

  // Edge Based //
  for(size_t s = 0; s < nOrientation; s++){
    size_t i = 0;

    for(int e = 0; e < 3; e++){
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
                                     lagrange[edgeIdx[s][e][1]] +
                                     lagrange[edgeIdx[s][e][0]])).gradient());
        }
        i++;
      }
    }
  }

  // Face Based //

  // NB: We use (*(*faceIdx[s])[f])[]
  //     where f = 0, because triangles
  //     have only ONE face: the face '0'

  for(size_t s = 0; s < nOrientation; s++){
    size_t i = nEdge;

    for(size_t l1 = 1; l1 < order; l1++){
      for(int l2 = 0; l2 + (int)l1 - 1 < orderMinus; l2++){
        // Preliminary Type 1
        Polynomial u =
          intLegendre[l1].compose(lagrange[faceIdx[s][0][1]] -
                                  lagrange[faceIdx[s][0][0]]
                                  ,
                                  lagrange[faceIdx[s][0][0]] +
                                  lagrange[faceIdx[s][0][1]]);
        Polynomial v =
          lagrange[faceIdx[s][0][2]] *
          legendre[l2].compose(lagrange[faceIdx[s][0][2]] * 2);

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
        vector<Polynomial> gradL1 = lagrange[faceIdx[s][0][0]].gradient();
        vector<Polynomial> gradL2 = lagrange[faceIdx[s][0][1]].gradient();

        vector<Polynomial> l2GradL1(gradL1);
        l2GradL1[0].mul(lagrange[faceIdx[s][0][1]]);
        l2GradL1[1].mul(lagrange[faceIdx[s][0][1]]);
        l2GradL1[2].mul(lagrange[faceIdx[s][0][1]]);

        vector<Polynomial> l1GradL2(gradL2);
        l1GradL2[0].mul(lagrange[faceIdx[s][0][0]]);
        l1GradL2[1].mul(lagrange[faceIdx[s][0][0]]);
        l1GradL2[2].mul(lagrange[faceIdx[s][0][0]]);

        vector<Polynomial> subGradL1L2V(l2GradL1);
        subGradL1L2V[0].sub(l1GradL2[0]);
        subGradL1L2V[1].sub(l1GradL2[1]);
        subGradL1L2V[2].sub(l1GradL2[2]);

        subGradL1L2V[0].mul(v);
        subGradL1L2V[1].mul(v);
        subGradL1L2V[2].mul(v);


        // Type 1
        basis[s][i] =
          new vector<Polynomial>((u * v).gradient());

        i++;

        // Type 2
        basis[s][i] =
          new vector<Polynomial>(subGradUV);

        i++;

        // Type 3
        if(l1 == 1){
          basis[s][i] =
            new vector<Polynomial>(subGradL1L2V);

          i++;
        }
      }
    }
  }

  // Clear //
  delete[] legendre;
  delete[] intLegendre;
}

TriEdgeBasis::~TriEdgeBasis(void){
  const size_t nOrientation = ReferenceSpaceManager::getNOrientation(type);

  // Basis //
  for(size_t i = 0; i < nOrientation; i++){
    for(size_t j = 0; j < nFunction; j++)
      delete basis[i][j];

    delete[] basis[i];
  }

  delete[] basis;
}
