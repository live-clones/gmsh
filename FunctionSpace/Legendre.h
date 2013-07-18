#ifndef _LEGENDRE_H_
#define _LEGENDRE_H_

#include "Polynomial.h"

/**
   @class Legendre
   @brief Generators for legendre Polynomial%s

   This class handles the generation of legendre
   Polynomial%s of many types:
   @li Classical legendre (Legendre::legendre)
   @li Integrated legendre (Legendre::integrated)
   @li Scaled legendre (Legendre::scaled)
   @li Integrated Scaled legendre (Legendre::intScaled)

   @note
   It is @em not @em requiered to instantiate a Legendre class.@n
   Indeed, all its methods are @em static.@n
   Each method is actualy a @em specific Polynomial @em generator.
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
   @param polynomial An @em allocated array (of size @c 'order' @c + @c 1)
   for storing the requested legendre Polynomial%s
   @param order The @em maximal order of the requested Polynomial%s
   @return Stores in @c 'polynomial' all the @em classical legendre Polynomial%s
   of order [@c 0, @c 'order']

   @fn void Legendre::integrated(Polynomial*, int)
   @param polynomial An @em allocated array (of size @c 'order')
   for storing the requested legendre Polynomial%s
   @param order The @em maximal order of the requested Polynomial%s
   @return Stores in @c 'polynomial' all the @em integrated legendre Polynomial%s
   of order [@c 1, @c 'order']

   @fn void Legendre::scaled(Polynomial*, int)
   @param polynomial An @em allocated array (of size @c 'order' @c + @c 1)
   for storing the requested legendre Polynomial%s
   @param order The @em maximal order of the requested Polynomial%s
   @return Stores in @c 'polynomial' all the @em scaled legendre Polynomial%s
   of order [@c 0, @c 'order']

   @fn void Legendre::intScaled(Polynomial*, int)
   @param polynomial An @em allocated array (of size @c 'order')
   for storing the requested legendre Polynomial%s
   @param order The @em maximal order of the requested Polynomial%s
   @return Stores in @c 'polynomial' all the @em scaled @em integrated
   legendre Polynomial%s of order [@c 1, @c 'order']
 */

#endif
