#ifndef _LEGENDRE_H_
#define _LEGENDRE_H_

#include "Polynomial.h"

/**
   @class Legendre
   @brief Generators for Legendre Polynomial%s

   This class handles the generation of Legendre Polynomial%s of many types:
   @li Classical Legendre (Legendre::legendre)
   @li Integrated Legendre (Legendre::integrated)
   @li Scaled Legendre (Legendre::scaled)
   @li Integrated Scaled Legendre (Legendre::intScaled)

   It is not requiered to instantiate a Legendre class.
   Indeed, all its methods are static.
 */

class Legendre{
 public:
  static void legendre(Polynomial* polynomial, int order);
  static void integrated(Polynomial* polynomial, int order);
  static void scaled(Polynomial* polynomial, int order);
  static void intScaled(Polynomial* polynomial,int order);

 private:
  static Polynomial legendre(int n,
                             const Polynomial& l,
                             const Polynomial& lMinus);

  static Polynomial integrated(int n,
                               const Polynomial& l,
                               const Polynomial& lMinus);

  static Polynomial scaled(int n,
                           const Polynomial& l,
                           const Polynomial& lMinus);

  static Polynomial intScaled(int n,
                              const Polynomial& l,
                              const Polynomial& lMinus);
};

/**
   @fn void Legendre::legendre(Polynomial*, int)
   @param polynomial An allocated array (of size 'order' + 1)
   for storing the requested legendre Polynomial%s
   @param order The maximal order of the requested Polynomial%s

   Stores in 'polynomial' all the classical legendre Polynomial%s
   of order [0, 'order']
   **

   @fn void Legendre::integrated(Polynomial*, int)
   @param polynomial An allocated array (of size 'order')
   for storing the requested legendre Polynomial%s
   @param order The maximal order of the requested Polynomial%s

   Stores in 'polynomial' all the integrated legendre Polynomial%s
   of order [1, 'order']
   **

   @fn void Legendre::scaled(Polynomial*, int)
   @param polynomial An allocated array (of size 'order' + 1)
   for storing the requested legendre Polynomial%s
   @param order The maximal order of the requested Polynomial%s

   Stores in 'polynomial' all the scaled legendre Polynomial%s
   of order [0, 'order']
   **

   @fn void Legendre::intScaled(Polynomial*, int)
   @param polynomial An allocated array (of size 'order')
   for storing the requested legendre Polynomial%s
   @param order The maximal order of the requested Polynomial%s

   Stores in 'polynomial' all the scaled integrated legendre Polynomial%s
   of order [1, 'order']
 */

#endif
