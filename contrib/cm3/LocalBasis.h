//
// C++ Interface: terms
//
// Description: Define the localbasis of element for shells
//
//
// Author:  <Gauthier BECKER>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//


#ifndef LOCALBASIS_H_
#define LOCALBASIS_H_
#include"SVector3.h"
class LocalBasis{
  protected :
    std::vector<SVector3> phi0;
    std::vector<SVector3> phi0d;
    fullMatrix<double> T; // not used if interface element  and bulk term --> create separate class ??
    fullMatrix<double> t; // not used if interface element  and bulk term --> create separate class ??
    SVector3 t0;
    double detJ0;

  void setphiall(const double d){
    for(int i=0;i<2;i++)
      for(int j=0;j<3;j++){
        phi0[i](j)=d;
      }
  }

  public :
    LocalBasis(){
      phi0.reserve(2);
      phi0d.reserve(2);
      T.resize(2,2);
      t.resize(2,2);
      for(int i=0;i<2;i++){
        SVector3 temp(0.,0.,0.);
        phi0.push_back(temp);
        //phi0[i]=temp;
        phi0d.push_back(temp);
      }
      T.setAll(0.);
      t.setAll(0.);
    }
    ~LocalBasis(){}

    void set(MElement *ele, const std::vector<TensorialTraits<SVector3>::GradType> &Grads){
      const int nbFF = ele->getNumVertices();
      // Compute local basis vector
      this->setphiall(0.);
      for(int i=0;i<2;i++){
        for(int j=0;j<nbFF;j++){
          phi0[i](0) += Grads[j](0,i)*ele->getVertex(j)->x();
          phi0[i](1) += Grads[j](0,i)*ele->getVertex(j)->y();
          phi0[i](2) += Grads[j](0,i)*ele->getVertex(j)->z();
        }
      }

      // Compute normal and Jacobian
      t0 = crossprod(phi0[0],phi0[1]);
      detJ0=t0.norm();
      t0.normalize();

      // Compute dual basis vector
      double cos;
      for(int i=0;i<2;i++){
        phi0d[i] = crossprod(phi0[1-i],t0);
        cos =  dot(phi0d[i],phi0[i]);
        phi0d[i] *= (1./cos);
      }
    }

    void set(MInterfaceElement *iele, const std::vector<TensorialTraits<SVector3>::GradType> &Grads, const SVector3 &t0p, const SVector3 &t0m){
      const int nbFF = iele->getNumVertices();

      // Compute of normal
      t0=t0p+t0m;
      assert(t0.norm()>1.e-8);
      t0.normalize();

      // Compute local basis vector
      this->setphiall(0.);
      for(int j=0;j<nbFF;j++){
          phi0[0](0) += Grads[j](0,0)*iele->getVertex(j)->x();
          phi0[0](1) += Grads[j](0,0)*iele->getVertex(j)->y();
          phi0[0](2) += Grads[j](0,0)*iele->getVertex(j)->z();
        }
        phi0[1] = crossprod(t0,phi0[0]);
        phi0[1].normalize();

      // Compute normal and Jacobian
      detJ0=crossprod(phi0[0],phi0[1]).norm();

      // Compute dual basis vector
      double cos;
      for(int i=0;i<2;i++){
        phi0d[i] = crossprod(phi0[1-i],t0);
        cos =  dot(phi0d[i],phi0[i]);
        phi0d[i] *= (1./cos);
      }
    }

    void set(MInterfaceElement *iele, const std::vector<TensorialTraits<SVector3>::GradType> &Grads, const SVector3 &t0m){
      const int nbFF = iele->getNumVertices();

      // Compute of normal
      t0=t0m;
      assert(t0.norm()>1.e-8);
      t0.normalize();

      // Compute local basis vector
      this->setphiall(0.);
      for(int j=0;j<nbFF;j++){
          phi0[0](0) += Grads[j](0,0)*iele->getVertex(j)->x();
          phi0[0](1) += Grads[j](0,0)*iele->getVertex(j)->y();
          phi0[0](2) += Grads[j](0,0)*iele->getVertex(j)->z();
        }
        phi0[1] = crossprod(t0,phi0[0]);
        phi0[1].normalize();

      // Compute normal and Jacobian
      detJ0=crossprod(phi0[0],phi0[1]).norm();

      // Compute dual basis vector
      double cos;
      for(int i=0;i<2;i++){
        phi0d[i] = crossprod(phi0[1-i],t0);
        cos =  dot(phi0d[i],phi0[i]);
        phi0d[i] *= (1./cos);
      }
    }


    // Push Forward Tensor (not used for interface element --> create a separate class ??
    void set_pushForward(const LocalBasis *lbs){
      // push forward tensor T and inverse push forward tensor t
      for(int i=0;i<2;i++)
        for(int j=0;j<2;j++){
          T(i,j)=dot(phi0[i],lbs->getphi0d(j));
          t(i,j)=dot(phi0d[j],lbs->getphi0(i));
        }
    }
    // get operation
    inline double getJacobian() const {return detJ0;}
    SVector3 gett0() const {return t0;}
    inline double gett0(const int i) const {return t0(i);}
    std::vector<SVector3> getphi0() const {return phi0;}
    std::vector<SVector3> getphi0d()const {return phi0d;}
    SVector3 getphi0(const int i) const {return phi0[i];}
    SVector3 getphi0d(const int i)const {return phi0d[i];}
    inline double getphi0(const int i,const int j) const {return phi0[i](j);}
    inline double getphi0d(const int i,const int j) const {return phi0d[i](j);}
    fullMatrix<double> getT() const {return T;}
    fullMatrix<double> gett() const {return t;}
    inline double getT(const int i, const int j) const {return T(i,j);}
    inline double gett(const int i, const int j) const {return t(i,j);}

    // Print
    void print(){
    printf("Basis phi0\n");
    printf("1 : %f %f %f\n",phi0[0](0),phi0[0](1),phi0[0](2));
    printf("2 : %f %f %f\n",phi0[1](0),phi0[1](1),phi0[1](2));
    printf("Normal : %f %f %f \n",t0(0),t0(1),t0(2));
    printf("Dual Basis phi0d\n");
    printf("1 : %f %f %f\n",phi0d[0](0),phi0d[0](1),phi0d[0](2));
    printf("2 : %f %f %f\n",phi0d[1](0),phi0d[1](1),phi0d[1](2));
    T.print("PushForward tensor");
    t.print("Inverse PushForward tensor");
    }
};
# endif // localbasis
