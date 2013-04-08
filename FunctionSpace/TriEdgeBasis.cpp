#include "TriEdgeBasis.h"
#include "TriReferenceSpace.h"
#include "Legendre.h"

using namespace std;

TriEdgeBasis::TriEdgeBasis(unsigned int order){
  // Reference Space //
  refSpace  = new TriReferenceSpace;
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
  nEdge     = 3 * (order + 1);
  nFace     = ((order - 1) * order + order - 1);
  nCell     = 0;
  nFunction = nVertex + nEdge + nFace + nCell;

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
  basis = new vector<Polynomial>**[nRefSpace];

  for(unsigned int s = 0; s < nRefSpace; s++)
    basis[s] = new vector<Polynomial>*[nFunction];

  // Edge Based //
  for(unsigned int s = 0; s < nRefSpace; s++){
    unsigned int i = 0;

    for(int e = 0; e < 3; e++){
      for(int l = 0; l < orderPlus; l++){
	// Nedelec
	if(l == 0){
	  vector<Polynomial> tmp1 = lagrange[(*(*edgeV[s])[e])[1]].gradient();
	  vector<Polynomial> tmp2 = lagrange[(*(*edgeV[s])[e])[0]].gradient();

	  tmp1[0].mul(lagrange[(*(*edgeV[s])[e])[0]]);
	  tmp1[1].mul(lagrange[(*(*edgeV[s])[e])[0]]);
	  tmp1[2].mul(lagrange[(*(*edgeV[s])[e])[0]]);


	  tmp2[0].mul(lagrange[(*(*edgeV[s])[e])[1]]);
	  tmp2[1].mul(lagrange[(*(*edgeV[s])[e])[1]]);
	  tmp2[2].mul(lagrange[(*(*edgeV[s])[e])[1]]);

	  tmp2[0].sub(tmp1[0]);
	  tmp2[1].sub(tmp1[1]);
	  tmp2[2].sub(tmp1[2]);

	  basis[s][i] = new vector<Polynomial>(tmp2);
	}

	// High Order
	else{
	  basis[s][i] =
	    new vector<Polynomial>
	    ((intLegendre[l].compose(lagrange[(*(*edgeV[s])[e])[0]] -
				     lagrange[(*(*edgeV[s])[e])[1]]
				     ,
				     lagrange[(*(*edgeV[s])[e])[1]] +
				     lagrange[(*(*edgeV[s])[e])[0]])).gradient());
	}
	i++;
      }
    }
  }

  // Face Based //

  // NB: We use (*(*faceV[s])[f])[]
  //     where f = 0, because triangles
  //     have only ONE face: the face '0'

  // TO CHECK: Are Triangles face matching tets ?

  // Alloc Temp
  Polynomial** u               = new Polynomial*[nRefSpace];
  Polynomial** v               = new Polynomial*[nRefSpace];
  Polynomial*  p               = new Polynomial[nRefSpace];
  vector<Polynomial>** subGrad = new vector<Polynomial>*[nRefSpace];

  for(unsigned int s = 0; s < nRefSpace; s++)
    u[s] = new Polynomial[orderPlus];

  for(unsigned int s = 0; s < nRefSpace; s++)
    v[s] = new Polynomial[orderPlus];

  // Preliminaries
  for(unsigned int s = 0; s < nRefSpace; s++){
    p[s] = lagrange[(*(*faceV[s])[0])[2]] * 2 - Polynomial(1, 0, 0, 0);

    // Polynomial u(x) & v(x)
    for(int l = 0; l < orderPlus; l++){
      u[s][l] = intLegendre[l].compose(lagrange[(*(*faceV[s])[0])[1]] -
                                       lagrange[(*(*faceV[s])[0])[0]],
                                       lagrange[(*(*faceV[s])[0])[0]] +
                                       lagrange[(*(*faceV[s])[0])[1]]);

      v[s][l] = legendre[l].compose(p[s]);
      v[s][l].mul(lagrange[(*(*faceV[s])[0])[2]]);
    }

    // Differences of grad(u) and grad(v)
    vector<Polynomial> gradL1 = lagrange[(*(*faceV[s])[0])[0]].gradient();
    vector<Polynomial> gradL2 = lagrange[(*(*faceV[s])[0])[1]].gradient();

    vector<Polynomial> l2GradL1(gradL1);
    l2GradL1[0].mul(lagrange[(*(*faceV[s])[0])[1]]);
    l2GradL1[1].mul(lagrange[(*(*faceV[s])[0])[1]]);
    l2GradL1[2].mul(lagrange[(*(*faceV[s])[0])[1]]);

    vector<Polynomial> l1GradL2(gradL2);
    l1GradL2[0].mul(lagrange[(*(*faceV[s])[0])[0]]);
    l1GradL2[1].mul(lagrange[(*(*faceV[s])[0])[0]]);
    l1GradL2[2].mul(lagrange[(*(*faceV[s])[0])[0]]);

    subGrad[s] = new vector<Polynomial>(3);
    (*subGrad[s])[0].sub(l1GradL2[0]);
    (*subGrad[s])[1].sub(l1GradL2[1]);
    (*subGrad[s])[2].sub(l1GradL2[2]);
  }

  // Face Basis
  for(unsigned int s = 0; s < nRefSpace; s++){
    unsigned int i = nEdge;

    // Type 1
    for(unsigned int l1 = 1; l1 < order; l1++){
      for(int l2 = 0; l2 + (int)l1 - 1 < orderMinus; l2++){
	vector<Polynomial> tmp1 = v[s][l2].gradient();
	vector<Polynomial> tmp2 = u[s][l1].gradient();

	tmp1[0].mul(u[s][l1]);
	tmp1[1].mul(u[s][l1]);
	tmp1[2].mul(u[s][l1]);

	tmp2[0].mul(v[s][l2]);
	tmp2[1].mul(v[s][l2]);
	tmp2[2].mul(v[s][l2]);

	tmp2[0].add(tmp1[0]);
	tmp2[1].add(tmp1[1]);
	tmp2[2].add(tmp1[2]);

	basis[s][i] = new vector<Polynomial>(tmp2);

	i++;
      }
    }

    // Type 2
    for(unsigned int l1 = 1; l1 < order; l1++){
      for(int l2 = 0; l2 + (int)l1 - 1 < orderMinus; l2++){
	vector<Polynomial> tmp1 = v[s][l2].gradient();
	vector<Polynomial> tmp2 = u[s][l1].gradient();

	tmp1[0].mul(u[s][l1]);
	tmp1[1].mul(u[s][l1]);
	tmp1[2].mul(u[s][l1]);

	tmp2[0].mul(v[s][l2]);
	tmp2[1].mul(v[s][l2]);
	tmp2[2].mul(v[s][l2]);

	tmp2[0].sub(tmp1[0]);
	tmp2[1].sub(tmp1[1]);
	tmp2[2].sub(tmp1[2]);

	basis[s][i] = new vector<Polynomial>(tmp2);

	i++;
      }
    }

    // Type 3
    for(int l = 0; l < orderMinus; l++){
      vector<Polynomial> subGradL1L2V(*subGrad[s]);

      subGradL1L2V[0].mul(v[s][l]);
      subGradL1L2V[1].mul(v[s][l]);
      subGradL1L2V[2].mul(v[s][l]);

      basis[s][i] = new vector<Polynomial>(subGradL1L2V);

      i++;
    }
  }

  // Free Temporary Sapce //
  for(unsigned int s = 0; s < nRefSpace; s++)
    delete[] u[s];

  for(unsigned int s = 0; s < nRefSpace; s++)
    delete[] v[s];

  for(unsigned int s = 0; s < nRefSpace; s++)
    delete subGrad[s];

  delete[] legendre;
  delete[] intLegendre;
  delete[] p;
  delete[] u;
  delete[] v;
  delete[] subGrad;
}

TriEdgeBasis::~TriEdgeBasis(void){
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
