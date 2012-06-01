#include "Legendre.h"

Polynomial Legendre::legendre(const int n, const Polynomial& l, 
			      const Polynomial& lMinus){
  const double nPlus = n + 1;

  return
    l * Polynomial(1, 1, 0, 0) * ((2 * n + 1) / nPlus) - lMinus * (n / nPlus);
}

Polynomial Legendre::scaled(const int n, const Polynomial& l, 
			    const Polynomial& lMinus){
  const double nPlus = n + 1;

  return
    l      * Polynomial(1, 1, 0, 0) * ((2 * n + 1) / nPlus) - 
    lMinus * Polynomial(1, 0, 2, 0) * ((    n    ) / nPlus);
}

Polynomial Legendre::integrated(const int n, const Polynomial& l, 
				const Polynomial& lMinus){
  const double nPlus = n + 1;

  return
    l * Polynomial(1, 1, 0, 0) * ((2 * n - 1) / nPlus) - lMinus * ((n - 2) / nPlus);
}

Polynomial Legendre::intScaled(const int n, const Polynomial& l, 
			       const Polynomial& lMinus){
  const double nPlus = n + 1;

  return
    l      * Polynomial(1, 1, 0, 0) * ((2 * n - 1) / nPlus) - 
    lMinus * Polynomial(1, 0, 2, 0) * ((    n - 2) / nPlus);
}



void Legendre::legendre(Polynomial* polynomial, const int order){
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

void Legendre::integrated(Polynomial* polynomial, const int order){
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

void Legendre::scaled(Polynomial* polynomial, const int order){
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

void Legendre::intScaled(Polynomial* polynomial, const int order){
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

/*
#include <iostream>
int main(void){
  Polynomial p[13];
  Legendre::legendre(p, 12);

  for(int i = 0; i < 13; i++)
    std::cout << "l(" << i << ")= " << (p[i]).toString() << std::endl;


  std::cout << std::endl;

  Polynomial pi[12];
  Legendre::integrated(pi, 12);

  for(int i = 0; i < 12; i++)
    std::cout << "L(" << i + 1 << ")= " << pi[i].toString() << std::endl;


  std::cout << std::endl;

  Polynomial ps[13];
  Legendre::scaled(ps, 12);

  for(int i = 0; i < 13; i++)
    std::cout << "ls(" << i << ")= " << (ps[i]).toString() << std::endl;


  std::cout << std::endl;

  Polynomial pis[12];
  Legendre::intScaled(pis, 12);

  for(int i = 0; i < 12; i++)
    std::cout << "Ls(" << i + 1<< ")= " << (pis[i]).toString() << std::endl;


  Polynomial p1 = Polynomial(1, 1, 1, 0);// - Polynomial(1, 0, 0, 0);
  Polynomial p2 = Polynomial(1, 0, 1, 1);// - Polynomial(1, 0, 0, 0);

  Polynomial p3 = pis[11].compose(p1, p2);

  std::cout << std::endl << "p1 = " << p1.toString() << std::endl;
  std::cout << "p2 = " << p2.toString() << std::endl;
  std::cout << "Ls(12, p1, p2) = " << p3.toString() << std::endl;

  return 0;
}
*/
