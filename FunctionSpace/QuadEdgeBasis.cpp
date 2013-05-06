#include "QuadEdgeBasis.h"
#include "QuadReferenceSpace.h"
#include "Legendre.h"

using namespace std;

QuadEdgeBasis::QuadEdgeBasis(unsigned int order){
  // Reference Space //
  refSpace  = new QuadReferenceSpace;
  nRefSpace = refSpace->getNPermutation();

  const vector<const vector<const vector<unsigned int>*>*>&
    edgeV = refSpace->getAllEdge();

  const vector<const vector<const vector<unsigned int>*>*>&
    faceV = refSpace->getAllFace();

  // Set Basis Type //
  this->order = order;

  type = 1;
  dim  = 2;

  nVertex   = 0;
  nEdge     = 4 * (order + 1);
  nFace     = 2 * (order + 1) * order;
  nCell     = 0;
  nFunction = nVertex + nEdge + nFace + nCell;

  // Legendre Polynomial //
  const unsigned int orderPlus = order + 1;

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
  basis = new vector<Polynomial>**[nRefSpace];

  for(unsigned int s = 0; s < nRefSpace; s++)
    basis[s] = new vector<Polynomial>*[nFunction];

  // Edge Based //
  for(unsigned int s = 0; s < nRefSpace; s++){
    unsigned int i = 0;

    for(unsigned int e = 0; e < 4; e++){
      for(unsigned int l = 0; l < orderPlus; l++){
        // Nedelec
        if(l == 0){
          Polynomial lambda = (lagrange[(*(*edgeV[s])[e])[0]] +
                               lagrange[(*(*edgeV[s])[e])[1]]) * 0.5;

          basis[s][i] =
            new vector<Polynomial>((lifting[(*(*edgeV[s])[e])[1]] -
                                    lifting[(*(*edgeV[s])[e])[0]]).gradient());

          basis[s][i]->at(0).mul(lambda);
          basis[s][i]->at(1).mul(lambda);
          basis[s][i]->at(2).mul(lambda);
        }

        // High Order
        else{
          basis[s][i] =
            new vector<Polynomial>
            ((intLegendre[l].compose(lifting[(*(*edgeV[s])[e])[1]] -
                                     lifting[(*(*edgeV[s])[e])[0]])
              *
              (lagrange[(*(*edgeV[s])[e])[0]] +
               lagrange[(*(*edgeV[s])[e])[1]])).gradient());
        }

	i++;
      }
    }
  }

  // Face Based //

  // NB: We use (*(*faceV[s])[f])[]
  //     where f = 0, because triangles
  //     have only ONE face: the face '0'

  for(unsigned int s = 0; s < nRefSpace; s++){
    unsigned int i = nEdge;

    // Type 1
    for(unsigned int l1 = 1; l1 < orderPlus; l1++){
      for(unsigned int l2 = 1; l2 < orderPlus; l2++){
        basis[s][i] =
          new vector<Polynomial>
          ((intLegendre[l1].compose(lifting[(*(*faceV[s])[0])[0]] -
                                    lifting[(*(*faceV[s])[0])[1]])
            *

            intLegendre[l2].compose(lifting[(*(*faceV[s])[0])[0]] -
                                    lifting[(*(*faceV[s])[0])[3]])).gradient());

        i++;
      }
    }

    // Type 2
    for(unsigned int l1 = 1; l1 < orderPlus; l1++){
      for(unsigned int l2 = 1; l2 < orderPlus; l2++){
        Polynomial pOne = lifting[(*(*faceV[s])[0])[0]] -
                          lifting[(*(*faceV[s])[0])[1]];

        Polynomial pTwo = lifting[(*(*faceV[s])[0])[0]] -
                          lifting[(*(*faceV[s])[0])[3]];

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
    for(unsigned int l1 = 1; l1 < orderPlus; l1++){
      Polynomial tmp =
        intLegendre[l1].compose(lifting[(*(*faceV[s])[0])[0]] -
                                lifting[(*(*faceV[s])[0])[3]]);


      basis[s][i] =
        new vector<Polynomial>((lifting[(*(*faceV[s])[0])[0]] -
                                lifting[(*(*faceV[s])[0])[1]]).gradient());

      basis[s][i]->at(0).mul(tmp);
      basis[s][i]->at(1).mul(tmp);
      basis[s][i]->at(2).mul(tmp);

      i++;
    }

    // Type 3.2
    for(unsigned int l1 = 1; l1 < orderPlus; l1++){
      Polynomial tmp =
        intLegendre[l1].compose(lifting[(*(*faceV[s])[0])[0]] -
                                lifting[(*(*faceV[s])[0])[1]]);


      basis[s][i] =
        new vector<Polynomial>((lifting[(*(*faceV[s])[0])[0]] -
                                lifting[(*(*faceV[s])[0])[3]]).gradient());

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

  for(unsigned int s = 0; s < nRefSpace; s++){
    for(unsigned int i = 0; i < nFunction; i++){
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
  // ReferenceSpace //
  delete refSpace;

  // Basis //
  for(unsigned int i = 0; i < nRefSpace; i++){
    for(unsigned int j = 0; j < nFunction; j++)
      delete basis[i][j];

    delete[] basis[i];
  }

  delete[] basis;
}
