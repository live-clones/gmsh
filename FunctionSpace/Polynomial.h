#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_

#include <string>
#include <stack>
#include <vector>
#include "fullMatrix.h"

/**
   @class Polynomial
   @brief Represents 3D polynomials

   This class represents 3D polynomials.
   A 3D polynomials uses monomials of 'xyz' type.
 */

// We suppose 3D Polynomial
class Polynomial{
 private:
  static const char coefName[3];

  struct monomial_t{
    double coef;
    int power[3];
  };

  int         nMon;
  monomial_t*  mon;

 public:
   Polynomial(double coef,
              int powerX,
              int powerY,
              int powerZ);

   Polynomial(const Polynomial& other);
   Polynomial(void);
  ~Polynomial(void);

  void derivative(int dim);
  std::vector<Polynomial> gradient(void) const;
  static std::vector<Polynomial> curl(const std::vector<Polynomial>& p);
  static Polynomial divergence(const std::vector<Polynomial>& p);

  double operator()
    (double x, double y, double z) const;

  double at
    (double x, double y, double z) const;

  static fullVector<double> at(const std::vector<Polynomial>& P,
                               double x,
                               double y,
                               double z);

  Polynomial operator+(const Polynomial& other) const;
  Polynomial operator-(const Polynomial& other) const;
  Polynomial operator*(const Polynomial& other) const;
  Polynomial operator*(double alpha) const;

  void add(const Polynomial& other);
  void sub(const Polynomial& other);
  void mul(const Polynomial& other);
  void mul(double alpha);

  void power(int n);

  Polynomial compose(const Polynomial& other) const;
  Polynomial compose(const Polynomial& otherA,
                     const Polynomial& otherB) const;
  Polynomial compose(const Polynomial& otherA,
                     const Polynomial& otherB,
                     const Polynomial& otherC) const;

  void operator=(const Polynomial& other);

  std::string toString(void) const;

 private:
  static std::string toString(const monomial_t* mon, const bool isAbs);

  static bool isSmaller(const monomial_t* a, const monomial_t*b);
  static bool isEqual(const monomial_t* a, const monomial_t*b);
  static bool isSmallerPower(const monomial_t* a, const monomial_t* b);
  static bool isEqualPower(const monomial_t* a, const monomial_t* b);

  static void sort(monomial_t* mon, int size);
  static void swap(monomial_t* mon, int i, int j);

  static int mergeMon(monomial_t* sourceA, int sizeA,
                      monomial_t* sourceB, int sizeB,
                      monomial_t** dest);

  static int mult(const monomial_t* sourceA, int sizeA,
                  const monomial_t* sourceB, int sizeB,
                  monomial_t** dest);

  static void mult(monomial_t* source, int size, double alpha);

  static void distribute(monomial_t* src, int size, const monomial_t* m);

  static void compose(const monomial_t* src,
                      Polynomial comp,
                      std::stack<monomial_t>* stk);

  static void compose(const monomial_t* src,
                      Polynomial compA, Polynomial compB,
                      std::stack<monomial_t>* stk);

  static void compose(const monomial_t* src,
                      Polynomial compA, Polynomial compB, Polynomial compC,
                      std::stack<monomial_t>* stk);

  static Polynomial polynomialFromStack(std::stack<monomial_t>& stk);

  static monomial_t* copyMonomial(const monomial_t* src, int size);

  static monomial_t* zeroPolynomial(void);
  static monomial_t* unitPolynomial(void);
};

/**
   @fn Polynomial::Polynomial(double, int, int, int)
   @param coef The coeficient of the futur monomial
   @param powerX The power of the 'x' coordinate of the futur monomial
   @param powerY The power of the 'y' coordinate of the futur monomial
   @param powerZ The power of the 'z' coordinate of the futur monomial
   @return Returns a new Monomial with the given parameters
   (note that Monomials are special case of Polynomial%s)
   **

   @fn Polynomial::Polynomial(const Polynomial&)
   @param other A Polynomial
   @return Returns a new Polynomial, which is the copy of the given one
   **

   @fn Polynomial::Polynomial(void)
   @return Returns a new Polynomial, which is empty

   An empty Polynomial means: a Polynomial with no monomials.
   In particular, the empty Polynomial is not the zero Polynomial.
   Indeed, the zero Polynomial has one monomial, 0.
   **

   @fn Polynomial::~Polynomial
   @return Deletes this Polynomial
   **

   @fn Polynomial::derivative
   @param dim The dimention to use for the derivation
   @returns Derivates this Polynomial with respect to the given dimention

   Note that dimention:
   @li 0 is for the x coordinate
   @li 1 is for the y coordinate
   @li 2 is for the z coordinate
   **

   @fn Polynomial::gradient
   @return Returns the gradient of this Polynomial
   **

   @fn Polynomial::curl
   @param p A vector of Polynomial%s
   @return Returns the curl of the given vector of Polynomial%s
   **

   @fn Polynomial::divergence
   @param p A vector of Polynomial%s
   @return Returns the divergence of the given vector of Polynomial%s
   **

   @fn double Polynomial::operator()(double, double, double)
   @param x A value
   @param y A value
   @param z A value
   @return Returns the evaluation of this Polynomial at (x, y, z)
   **

   @fn double Polynomial::at(double, double, double) const
   @param x A value
   @param y A value
   @param z A value
   @return Returns the evaluation of this Polynomial at (x, y, z)
   **

   @fn fullVector<double> Polynomial::at(const std::vector<Polynomial>&, double, double, double)
   @param P A vector of Polynomial%s
   @param x A value
   @param y A value
   @param z A value
   @return Returns a fullVector with the evaluation of
   the given vector of Polynomial%s at (x, y, z)
   **

   @fn Polynomial Polynomial::operator+(const Polynomial&) const
   @param other An other Polynomial
   @return Returns a new Polynomial,
   which is the sum of this Polynomial and the given one
   **

   @fn Polynomial Polynomial::operator-(const Polynomial&) const
   @param other An other Polynomial
   @return Returns a new Polynomial,
   which is the difference of this Polynomial and the given one
   **

   @fn Polynomial Polynomial::operator*(const Polynomial&) const
   @param other An other Polynomial
   @return Returns a new Polynomial,
   which is the product of this Polynomial and the given one
   **

   @fn Polynomial Polynomial::operator*(double) const
   @param alpha A value
   @return Returns a new Polynomial,
   which is this Polynomial multiplied by alpha
   **

   @fn Polynomial::add
   @param other An other Polynomial
   @return The given Polynomial is added to this Polynomial

   Note that the result of this operation is stored in this Polynomial
   **

   @fn Polynomial::sub
   @param other An other Polynomial
   @return The given Polynomial is substracted to this Polynomial

   Note that the result of this operation is stored in this Polynomial
   **

   @fn void Polynomial::mul(const Polynomial&)
   @param other An other Polynomial
   @return The given Polynomial is multiplied with this Polynomial

   Note that the result of this operation is stored in this Polynomial
   **

   @fn void Polynomial::mul(double)
   @param alpha A value
   @return This Polynomial is multiplied by the given value

   Note that the result of this operation is stored in this Polynomial
   **

   @fn Polynomial::power
   @param n A natural number
   @return Takes this Polynomial to the power n
   **

   @fn Polynomial Polynomial::compose(const Polynomial&) const
   @param other An other Polynomial, called Q(x, y, z)
   @return
   Let this Polynomial be P(x, y, z). This method returns a new Polynomial,
   representing P(Q(x, y, z), y, z)
   **

   @fn Polynomial Polynomial::compose(const Polynomial&, const Polynomial&) const
   @param otherA An other Polynomial, called Q(x, y, z)
   @param otherB An other Polynomial, called R(x, y, z)
   @return
   Let this Polynomial be P(x, y, z). This method returns a new Polynomial,
   representing P(Q(x, y, z), R(x, y, z), z)
   **

   @fn Polynomial Polynomial::compose(const Polynomial&, const Polynomial&, const Polynomial&) const
   @param otherA An other Polynomial, called Q(x, y, z)
   @param otherB An other Polynomial, called R(x, y, z)
   @param otherC An other Polynomial, called S(x, y, z)
   @return
   Let this Polynomial be P(x, y, z). This method returns a new Polynomial,
   representing P(Q(x, y, z), R(x, y, z), S(x, y, z))
   **

   @fn void Polynomial::operator=(const Polynomial&)
   @param other A Polynomial
   @return Sets this Polynomial to a copy of the given one
   **

   @fn Polynomial::toString
   @return Returns a string representing this Polynomial
*/

//////////////////////
// Inline Functions //
//////////////////////

inline double Polynomial::operator() (double x,
                                      double y,
                                      double z) const{
  return at(x, y, z);
}

inline bool Polynomial::isEqual(const Polynomial::monomial_t* a,
                                const Polynomial::monomial_t* b){
  return a->power[0] == b->power[0] &&
         a->power[1] == b->power[1] &&
         a->power[2] == b->power[2];
}

inline bool Polynomial::isSmallerPower(const Polynomial::monomial_t* a,
                                       const Polynomial::monomial_t* b){

  return
    a->power[0] + a->power[1] + a->power[2]
    <
    b->power[0] + b->power[1] + b->power[2] ;
}

inline bool Polynomial::isEqualPower(const Polynomial::monomial_t* a,
                                     const Polynomial::monomial_t* b){

  return
    a->power[0] + a->power[1] + a->power[2]
    ==
    b->power[0] + b->power[1] + b->power[2] ;
}

#endif
