#include "Legendre.h"

Polynomial Legendre::legendre(int n, const Polynomial& l,
                              const Polynomial& lMinus){
  const double nPlus = n + 1;

  return
    l * Polynomial(1, 1, 0, 0) * ((2 * n + 1) / nPlus) - lMinus * (n / nPlus);
}

Polynomial Legendre::scaled(int n, const Polynomial& l,
                            const Polynomial& lMinus){
  const double nPlus = n + 1;

  return
    l      * Polynomial(1, 1, 0, 0) * ((2 * n + 1) / nPlus) -
    lMinus * Polynomial(1, 0, 2, 0) * ((    n    ) / nPlus);
}

Polynomial Legendre::integrated(int n, const Polynomial& l,
                                const Polynomial& lMinus){
  const double nPlus = n + 1;

  return
    l      * Polynomial(1, 1, 0, 0) * ((2 * n - 1) / nPlus) -
    lMinus * ((n - 2) / nPlus);
}

Polynomial Legendre::intScaled(int n, const Polynomial& l,
                               const Polynomial& lMinus){
  const double nPlus = n + 1;

  return
    l      * Polynomial(1, 1, 0, 0) * ((2 * n - 1) / nPlus) -
    lMinus * Polynomial(1, 0, 2, 0) * ((    n - 2) / nPlus);
}



void Legendre::legendre(Polynomial* polynomial, int order){
  int i, j, k;

  if(order >= 0)

    polynomial[0] = Polynomial(1, 0, 0, 0);

  if(order >= 1)
    polynomial[1] = Polynomial(1, 1, 0, 0);

  if(order >= 2){
    for(k = 2; k <= order; k++){
      i = k - 1;
      j = k - 2;

      polynomial[k] = legendre(i, polynomial[i], polynomial[j]);
    }
  }
}

void Legendre::integrated(Polynomial* polynomial, int order){
  int i, j, k;

  if(order >= 1)
    polynomial[0] = Polynomial(1, 1, 0, 0);

  if(order >= 2)
    polynomial[1] = (Polynomial(1, 2, 0, 0) + Polynomial(-1, 0, 0, 0)) * 0.5;

  if(order >= 3){
    for(k = 2; k < order; k++){
      i = k - 1;
      j = k - 2;

      polynomial[k] = integrated(k, polynomial[i], polynomial[j]);
    }
  }
}

void Legendre::scaled(Polynomial* polynomial, int order){
  int i, j, k;

  if(order >= 0)
    polynomial[0] = Polynomial(1, 0, 0, 0);

  if(order >= 1)
    polynomial[1] = Polynomial(1, 1, 0, 0);

  if(order >= 2){
    for(k = 2; k <= order; k++){
      i = k - 1;
      j = k - 2;

      polynomial[k] = scaled(i, polynomial[i], polynomial[j]);
    }
  }
}

void Legendre::intScaled(Polynomial* polynomial, int order){
  int i, j, k;

  if(order >= 1)
    polynomial[0] = Polynomial(1, 1, 0, 0);

  if(order >= 2)
    polynomial[1] = (Polynomial(1, 2, 0, 0) + Polynomial(-1, 0, 2, 0)) * 0.5;

  if(order >= 3){
    for(k = 2; k < order; k++){
      i = k - 1;
      j = k - 2;

      polynomial[k] = intScaled(k, polynomial[i], polynomial[j]);
    }
  }
}
