#include "Legendre.h"
#include "GmshDefines.h"
#include "ReferenceSpaceManager.h"

#include "QuadEdgeBasis.h"

using namespace std;

QuadEdgeBasis::QuadEdgeBasis(size_t order){
  // Set Basis Type //
  this->order = order;

  type = TYPE_QUA;
  dim  = 2;

  nVertex   = 0;
  nEdge     = 4 * (order + 1);
  nFace     = 2 * (order + 1) * order;
  nCell     = 0;
  nFunction = nVertex + nEdge + nFace + nCell;

  // Reference Space //
  const size_t nOrientation = ReferenceSpaceManager::getNOrientation(type);

  const vector<vector<vector<size_t> > >&
    edgeIdx = ReferenceSpaceManager::getEdgeNodeIndex(type);

  const vector<vector<vector<size_t> > >&
    faceIdx = ReferenceSpaceManager::getFaceNodeIndex(type);


  // Legendre Polynomial //
  const size_t orderPlus = order + 1;

  Polynomial* legendre    = new Polynomial[orderPlus];
  Polynomial* intLegendre = new Polynomial[orderPlus];

  Legendre::integrated(intLegendre, orderPlus);
  Legendre::legendre(legendre, order);

  // Lagrange & Lifting //
  const Polynomial lagrange[4] =
    {
      Polynomial((Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) *
                 (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0))),

      Polynomial((Polynomial(1, 1, 0, 0)) *
                 (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0))),

      Polynomial((Polynomial(1, 1, 0, 0)) *
                 (Polynomial(1, 0, 1, 0))),

      Polynomial((Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) *
                 (Polynomial(1, 0, 1, 0)))
    };

  const Polynomial lifting[4] =
    {
      Polynomial((Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) +
                 (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0))),

      Polynomial((Polynomial(1, 1, 0, 0)) +
                 (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0))),

      Polynomial((Polynomial(1, 1, 0, 0)) +
                 (Polynomial(1, 0, 1, 0))),

      Polynomial((Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) +
                 (Polynomial(1, 0, 1, 0)))
    };

  // Basis //
  basis = new vector<Polynomial>**[nOrientation];

  for(size_t s = 0; s < nOrientation; s++)
    basis[s] = new vector<Polynomial>*[nFunction];

  // Edge Based //
  for(size_t s = 0; s < nOrientation; s++){
    size_t i = 0;

    for(size_t e = 0; e < 4; e++){
      for(size_t l = 0; l < orderPlus; l++){
        // Nedelec
        if(l == 0){
          Polynomial lambda = (lagrange[edgeIdx[s][e][0]] +
                               lagrange[edgeIdx[s][e][1]]) * 0.5;

          basis[s][i] =
            new vector<Polynomial>((lifting[edgeIdx[s][e][1]] -
                                    lifting[edgeIdx[s][e][0]]).gradient());

          basis[s][i]->at(0).mul(lambda);
          basis[s][i]->at(1).mul(lambda);
          basis[s][i]->at(2).mul(lambda);
        }

        // High Order
        else{
          basis[s][i] =
            new vector<Polynomial>
            ((intLegendre[l].compose(lifting[edgeIdx[s][e][1]] -
                                     lifting[edgeIdx[s][e][0]])
              *
              (lagrange[edgeIdx[s][e][0]] +
               lagrange[edgeIdx[s][e][1]])).gradient());
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

    // Type 1
    for(size_t l1 = 1; l1 < orderPlus; l1++){
      for(size_t l2 = 1; l2 < orderPlus; l2++){
        basis[s][i] =
          new vector<Polynomial>
          ((intLegendre[l1].compose(lifting[faceIdx[s][0][0]] -
                                    lifting[faceIdx[s][0][1]])
            *

            intLegendre[l2].compose(lifting[faceIdx[s][0][0]] -
                                    lifting[faceIdx[s][0][3]])).gradient());

        i++;
      }
    }

    // Type 2
    for(size_t l1 = 1; l1 < orderPlus; l1++){
      for(size_t l2 = 1; l2 < orderPlus; l2++){
        Polynomial pOne = lifting[faceIdx[s][0][0]] -
                          lifting[faceIdx[s][0][1]];

        Polynomial pTwo = lifting[faceIdx[s][0][0]] -
                          lifting[faceIdx[s][0][3]];

        Polynomial lOne =    legendre[l1].compose(pOne) *
                          intLegendre[l2].compose(pTwo);

        Polynomial lTwo =    legendre[l2].compose(pTwo) *
                          intLegendre[l1].compose(pOne);

        vector<Polynomial> gradOne = pOne.gradient();
        vector<Polynomial> gradTwo = pTwo.gradient();

        gradOne[0].mul(lOne);
        gradOne[1].mul(lOne);
        gradOne[2].mul(lOne);

        gradTwo[0].mul(lTwo);
        gradTwo[1].mul(lTwo);
        gradTwo[2].mul(lTwo);

        basis[s][i] = new vector<Polynomial>(gradOne);

        basis[s][i]->at(0).sub(gradTwo[0]);
        basis[s][i]->at(1).sub(gradTwo[1]);
        basis[s][i]->at(2).sub(gradTwo[2]);

        i++;
      }
    }

    // Type 3.1
    for(size_t l1 = 1; l1 < orderPlus; l1++){
      Polynomial tmp =
        intLegendre[l1].compose(lifting[faceIdx[s][0][0]] -
                                lifting[faceIdx[s][0][3]]);


      basis[s][i] =
        new vector<Polynomial>((lifting[faceIdx[s][0][0]] -
                                lifting[faceIdx[s][0][1]]).gradient());

      basis[s][i]->at(0).mul(tmp);
      basis[s][i]->at(1).mul(tmp);
      basis[s][i]->at(2).mul(tmp);

      i++;
    }

    // Type 3.2
    for(size_t l1 = 1; l1 < orderPlus; l1++){
      Polynomial tmp =
        intLegendre[l1].compose(lifting[faceIdx[s][0][0]] -
                                lifting[faceIdx[s][0][1]]);


      basis[s][i] =
        new vector<Polynomial>((lifting[faceIdx[s][0][0]] -
                                lifting[faceIdx[s][0][3]]).gradient());

      basis[s][i]->at(0).mul(tmp);
      basis[s][i]->at(1).mul(tmp);
      basis[s][i]->at(2).mul(tmp);

      i++;
    }
  }

  // Mapping to Gmsh Quad //
  // x = (u + 1) / 2
  // y = (v + 1) / 2
  //
  // (x, y) = Zaglmayr Ref Quad
  // (u, v) = Gmsh     Ref Quad

  Polynomial  mapX(Polynomial(0.5, 1, 0, 0) +
                   Polynomial(0.5, 0, 0, 0));

  Polynomial  mapY(Polynomial(0.5, 0, 1, 0) +
                   Polynomial(0.5, 0, 0, 0));

  for(size_t s = 0; s < nOrientation; s++){
    for(size_t i = 0; i < nFunction; i++){
      vector<Polynomial>* old;
      vector<Polynomial>  nxt(3);

      old    = basis[s][i];
      nxt[0] = (*old)[0].compose(mapX, mapY);
      nxt[1] = (*old)[1].compose(mapX, mapY);
      nxt[2] = (*old)[2].compose(mapX, mapY);

      basis[s][i] = new vector<Polynomial>(nxt);
      delete old;
    }
  }

  // Free Temporary Sapce //
  delete[] legendre;
  delete[] intLegendre;
}

QuadEdgeBasis::~QuadEdgeBasis(void){
  const size_t nOrientation = ReferenceSpaceManager::getNOrientation(type);

  // Basis //
  for(size_t i = 0; i < nOrientation; i++){
    for(size_t j = 0; j < nFunction; j++)
      delete basis[i][j];

    delete[] basis[i];
  }

  delete[] basis;
}
