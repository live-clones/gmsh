//
// C++ Interface: terms
//
// Description: Elementary matrix terms for C0 Dg Plate
//
//
// Author:  <Gauthier BECKER>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//



#ifndef C0DGPLATETERMS_H
#define C0DGPLATETERMS_H
#include "terms.h"
#include "SVector3.h"
#include <string>
#include "LocalBasis.h"
#include "LinearElasticShellHookeTensor.h"
#include "DgC0PlateElementaryTerms.h"


class IsotropicElasticTermC0Plate : public BilinearTerm<SVector3,SVector3>
{
 protected :
  double E,nu,h,Cm,Cn;
  bool sym;

 public :
  IsotropicElasticTermC0Plate(FunctionSpace<SVector3>& space1_,FunctionSpace<SVector3>& space2_,double E_,double nu_,double h_) : BilinearTerm<SVector3,SVector3>(space1_,space2_),E(E_),nu(nu_),h(h_)
  {
    sym=(&space1_==&space2_);
    Cm = ( E_ * h_ * h_ * h_ ) / ( 12 * (1 - nu_) * (1 + nu_) );
    Cn = E_*h_/((1-nu_)*(1+nu_));
  }
  IsotropicElasticTermC0Plate(FunctionSpace<SVector3>& space1_,double E_,double nu_,double h_) : BilinearTerm<SVector3,SVector3>(space1_,space1_),E(E_),nu(nu_),h(h_)
  {
    sym=true;
    Cm = ( E_ * h_ * h_ * h_ ) / ( 12 * (1 - nu_) * (1 + nu_) );
    Cn = E_*h_/((1-nu_)*(1+nu_));
  }
  virtual ~IsotropicElasticTermC0Plate() {}
  virtual void get(MElement *ele,int npts,IntPt *GP,fullMatrix<double> &m)
  {
    if (sym)
    {
      // Initialization of some data
      const int nbdof = BilinearTerm<SVector3,SVector3>::space1.getNumKeys(ele);
      const int nbFF = nbdof/3;
      double Cmt= 0., Cnt=0.;
      LinearElasticShellHookeTensor HOOKe; LinearElasticShellHookeTensor *H=&HOOKe; // make a pointer in an other way
      m.resize(nbdof, nbdof);
      m.setAll(0.);
      std::vector<TensorialTraits<SVector3>::HessType> Hess;
      std::vector<TensorialTraits<SVector3>::GradType> Grad;
      double Bn[256][3][2][2]; // max order 256 or dynamical allocation ?? better than std::vector and fullMatrix ?? create a class with this variable
      LocalBasis LB;
      LocalBasis *lb=&LB; // two last line in 1 operation ??
      double me_bending[3][3];
      double me_membrane[3][3]; // better than fullMatrix<double> used for me_bending ??
      // sum on Gauss' points
      for (int i = 0; i < npts; i++)
      {
        // Coordonate of Gauss' point i
        const double u = GP[i].pt[0]; const double v = GP[i].pt[1]; const double w = GP[i].pt[2];
        // Weight of Gauss' point i and Jacobian's value at this point
        const double weight = GP[i].weight;

        // Compute of Hessian of SF. Each component of the vector in link to a shape function.
        // It give the value of second derivative of SF in the isoparametric configuration
        BilinearTerm<SVector3,SVector3>::space1.gradfuvw(ele,u, v, w, Grad); // a optimiser the jacobian cannot be given in argument...
        BilinearTerm<SVector3,SVector3>::space1.hessfuvw(ele,u, v, w, Hess); // a optimiser

        lb->set(ele,Grad); // This function can become a method of MElement Plante lors du calcul de l'énergie  à cause de  std::vector<TensorialTraits<SVector3>::GradType> qui retourne un vecteur vide prob de template??

        // multiplication of constant by detJ and weight
        Cmt = lb->getJacobian() * weight *Cm;
        Cnt = lb->getJacobian() * weight *Cn;
        // compute of Hooke tensor
        H->set(lb,nu);

        // compute Bn value
        compute_Bn(lb,Grad,nbFF,Bn);

       // loop on SF to construct the elementary (bulk) stiffness matrix at the Gauss' point i
       for(int j=0; j<nbFF;j++)
         for(int k=0;k<nbFF;k++){
           BulkC0PlateDGStiffnessBendingTerms(Hess[j],Hess[k],H,lb,me_bending);
           BulkC0PlateDGStiffnessMembraneTerms(Bn[j],Bn[k],H,me_membrane);
           for(int jj=0;jj<3;jj++)
             for(int kk=0;kk<3;kk++)
               m(j+(jj*nbFF),k+(kk*nbFF)) += (Cmt*me_bending[jj][kk]+Cnt*me_membrane[jj][kk]);
         }
       // clear the hessian and Grad because the components append in hessfuvw and gradfuvw
       Hess.clear(); Grad.clear();
    }
//    m.print("bulk");
/*    // By numerical perturbation (Verification OK)
    double eps=1.e-8;
    fullMatrix<double> fp(nbdof,1);
    fullMatrix<double> fm(nbdof,1);
    fp.setAll(0.);
    fm.setAll(0.);
    fullMatrix<double> m2(nbdof,nbdof); m2.setAll(0.);
    fullMatrix<double> disp(nbdof,1);
    //GaussQuadrature Integ_Bulk(GaussQuadrature::GradGrad);
    //IntPt *GPbulk;
    //int npts=integrator.getIntPoints(ele,&GP);
    for(int j=0;j<nbdof;j++){
      disp.setAll(0.); fm.setAll(0.);fp.setAll(0.);
      disp(j,0)=eps;
      this->getForce(ele,npts,GP,disp,fp);
      disp(j,0)=-eps;
      this->getForce(ele,npts,GP,disp,fm);
      for(int k=0;k<nbdof;k++)
        m2(k,j)=(fp(k,0)-fm(k,0))/(2.*eps);
    }
    m2.print("Bulk pert");*/
  }
  else
    {
      printf("not implemented\n");
    }
  }


   virtual void getForce(MElement *ele,int npts,IntPt *GP,const fullMatrix<double> &disp, fullMatrix<double> &m)
  {
    if (sym)
    {
      // Initialization of some data
      const int nbdof = BilinearTerm<SVector3,SVector3>::space1.getNumKeys(ele);
      const int nbFF = nbdof/3;
      double Cmt= 0.,Cnt=0.;
      LinearElasticShellHookeTensor HOOKe; LinearElasticShellHookeTensor *H=&HOOKe; // make a pointer in an other way
      m.resize(nbdof,1);
      m.setAll(0.);
      std::vector<TensorialTraits<SVector3>::HessType> Hess;
      std::vector<TensorialTraits<SVector3>::GradType> Grad;
      double Bn[256][3][2][2]; // max order 256 or dynamical allocation ?? better than std::vector and fullMatrix ?? create a class with this variable
      LocalBasis LB;
      LocalBasis *lb=&LB; // two last line in 1 operation ??
      double me_bending[3];
      double me_membrane[3];
      // sum on Gauss' points
      for (int i = 0; i < npts; i++)
      {
        // Coordonate of Gauss' point i
        const double u = GP[i].pt[0]; const double v = GP[i].pt[1]; const double w = GP[i].pt[2];
        // Weight of Gauss' point i and Jacobian's value at this point
        const double weight = GP[i].weight;

        // Compute of Hessian of SF. Each component of the vector in link to a shape function.
        // It give the value of second derivative of SF in the isoparametric configuration
        BilinearTerm<SVector3,SVector3>::space1.gradfuvw(ele,u, v, w, Grad); // a optimiser the jacobian cannot be given in argument...
        BilinearTerm<SVector3,SVector3>::space1.hessfuvw(ele,u, v, w, Hess); // a optimiser

        lb->set(ele,Grad); // This function can become a method of MElement Plante lors du calcul de l'énergie  à cause de  std::vector<TensorialTraits<SVector3>::GradType> qui retourne un vecteur vide prob de template??

        // multiplication of constant by detJ and weight
        Cmt = lb->getJacobian() * weight * Cm;
        Cnt = lb->getJacobian() * weight * Cn;

        // compute of Hooke tensor
        H->set(lb,nu);

        // compute Bn value
        compute_Bn(lb,Grad,nbFF,Bn);

       // loop on SF to construct the elementary (bulk) stiffness matrix at the Gauss' point i
       for(int j=0; j<nbFF;j++){
           BulkC0PlateDGForceBendingTerms(Hess[j],Hess,H,lb,disp,me_bending);
           BulkC0PlateDGForceMembraneTerms(Bn[j],Bn,H,nbFF,disp,me_membrane);
           for(int k=0;k<3;k++)
             m(j+k*nbFF,0) += (Cmt*me_bending[k]+ Cnt*me_membrane[k]);
       }
       // clear the hessian and Grad because the components append in hessfuvw and gradfuvw
       Hess.clear(); Grad.clear();
    }
  }
  else
    {
      printf("not implemented\n");
    }
  }
}; // IsotropicElasticTermC0Plate


class IsotropicElasticInterfaceTermC0Plate : public BilinearTerm<SVector3,SVector3>
{
 protected :
  double E,nu,beta1,h;
  double Cm;
  bool sym;

 public :
  IsotropicElasticInterfaceTermC0Plate(FunctionSpace<SVector3>& space1_,FunctionSpace<SVector3>& space2_,double E_,double nu_,double beta1_,double h_) : BilinearTerm<SVector3,SVector3>(space1_,space2_),E(E_),nu(nu_),beta1(beta1_),h(h_)
  {
    Cm = ( E_ * h_ * h_ * h_ ) / ( 12 * (1 - nu_) * (1 + nu_) );
    sym=(&space1_==&space2_);
  }
  IsotropicElasticInterfaceTermC0Plate(FunctionSpace<SVector3>& space1_,double E_,double nu_,double beta1_,double h_) : BilinearTerm<SVector3,SVector3>(space1_,space1_),E(E_),nu(nu_),beta1(beta1_),h(h_)
  {
    Cm = ( E_ * h_ * h_ * h_ ) / ( 12 * (1 - nu_) * (1 + nu_) );
    sym=true;
  }
  virtual ~IsotropicElasticInterfaceTermC0Plate() {}
  // Must be declare has this function is virtual pure in class BilinearTermBase
  virtual void get(MElement *ele,int npts,IntPt *GP,fullMatrix<double> &m) {}

  virtual void getInter(MInterfaceElement *iele,int npts,IntPt *GP,fullMatrix<double> &m)
  {
    if (sym)
    {
      // data initialization
      // Retrieve of the element link to the interface element velem[0] == minus elem ; velem == plus elem
      MElement ** velem = iele->getElem();
      const int nbdof_m = BilinearTerm<SVector3,SVector3>::space1.getNumKeys(velem[0]);
      const int nbdof_p = BilinearTerm<SVector3,SVector3>::space1.getNumKeys(velem[1]);
      const int nbFF_m = nbdof_m/3;
      const int nbFF_p = nbdof_p/3;
      // Initialization
      m.resize(nbdof_m+nbdof_p, nbdof_m+nbdof_p);
      m.setAll(0.);
      double uem,uep,vem,vep;
      std::vector<TensorialTraits<SVector3>::GradType> Grads_m;
      std::vector<TensorialTraits<SVector3>::GradType> Grads_p;
      std::vector<TensorialTraits<SVector3>::GradType> Grads;
      std::vector<TensorialTraits<SVector3>::HessType> Hess_m;
      std::vector<TensorialTraits<SVector3>::HessType> Hess_p;
      LocalBasis LBS,LBP,LBM;
      LocalBasis *lbs=&LBS; LocalBasis *lb_p=&LBP; LocalBasis *lb_m=&LBM;
      double Bhat_p[256][3][2][2], Bhat_m[256][3][2][2];
      LinearElasticShellHookeTensor HOOKEhat_p;
      LinearElasticShellHookeTensor HOOKehat_m;
      LinearElasticShellHookeTensor HOOKehatmean;
      LinearElasticShellHookeTensor *Hhat_p=&HOOKEhat_p;
      LinearElasticShellHookeTensor *Hhat_m=&HOOKehat_m;
      LinearElasticShellHookeTensor *Hhatmean=&HOOKehatmean;
      double Deltat_m[256][3][3], Deltat_p[256][3][3];
      double Cmt;
      double me_cons[3][3];
      double me_comp[3][3];
      double me_stab[3][3];

      // Characteristic size of interface element
      double h_s = iele->getCharacteristicSize();

      const double Bhs = beta1/h_s;
      // sum on Gauss' points
      for (int i = 0; i < npts; i++)
      {
        // Coordonate of Gauss' point i
        const double u = GP[i].pt[0]; const double v = GP[i].pt[1]; const double w = GP[i].pt[2];
        // Weight of Gauss' point i
        const double weight = GP[i].weight;
        //printf("Abscisse of gauss point %f\n",u);
        //Compute the position (u,v) in the element of the Gauss point (to know where evaluate the shape functions)
        iele->getuvOnElem(u,uem,vem,uep,vep);
        // Compute of gradient and hessian of shape functions on interface element and on elements
        // ATTENTION after multiplication by multipliers (functionspace 276) components are in the "second line of tensor change this ??
        BilinearTerm<SVector3,SVector3>::space1.gradfuvw(iele,u, v, w, Grads); // grad of shape fonction on interface element
        BilinearTerm<SVector3,SVector3>::space1.gradfuvw(velem[0],uem, vem, w, Grads_m); // w = 0
        BilinearTerm<SVector3,SVector3>::space1.gradfuvw(velem[1],uep, vep, w, Grads_p);
        BilinearTerm<SVector3,SVector3>::space1.hessfuvw(velem[0],uem, vem, w, Hess_m);
        BilinearTerm<SVector3,SVector3>::space1.hessfuvw(velem[1],uep, vep, w, Hess_p);

        // basis of elements and interface element
        lb_m->set(velem[0],Grads_m); // This function can become a method of MElement Plante lors du calcul de l'énergie  à cause de  std::vector<TensorialTraits<SVector3>::GradType> prob de template??
        lb_p->set(velem[1],Grads_p); // This function can become a method of MElement Plante lors du calcul de l'énergie  à cause de  std::vector<TensorialTraits<SVector3>::GradType> prob de template??
        lbs->set(iele,Grads,lb_p->gett0(),lb_m->gett0()); // This function can become a method of MElement Plante lors du calcul de l'énergie  à cause de  std::vector<TensorialTraits<SVector3>::GradType> prob de template??

        // PushForwardTensor
        lb_m->set_pushForward(lbs);
        lb_p->set_pushForward(lbs);

        // Compute of Bhat vector (1 component for now because 1 dof (z) ) --> it's a vector of length == nbFF
        Compute_Bhat(lb_p,Hess_p,nbFF_p,Bhat_p);
        Compute_Bhat(lb_m,Hess_m,nbFF_m,Bhat_m);

        // Compute of Hooke hat tensor on minus and plus element
        Cmt = weight * lbs->getJacobian()  * Cm; // Eh^3/(12(1-nu^2)) * weight gauss * jacobian
        Hhat_p->hat(lb_p,Cmt,nu);
        Hhat_m->hat(lb_m,Cmt,nu); //Hhat_m->hat(lb_m,H_m);
        Hhatmean->mean(Hhat_p,Hhat_m); // mean value of tensor by component used for stability term

        // Compute of Deltat_tilde
        compute_Deltat_tilde(lb_p,Grads_p,nbFF_p,Deltat_p);
        compute_Deltat_tilde(lb_m,Grads_m,nbFF_m,Deltat_m);

        for(int j=0;j<nbFF_m;j++){
          for(int k=0;k<nbFF_m;k++){
            consAndCompC0PlateStiffnessTerms(Hhat_m,Bhat_m[j],Deltat_m[k],lbs,me_cons);
            consAndCompC0PlateStiffnessTerms(Hhat_m,Bhat_m[k],Deltat_m[j],lbs,me_comp);
            stabilityC0PlateStiffnessTerms(Hhatmean,Deltat_m[j], Deltat_m[k],lbs,me_stab);
            for(int jj=0;jj<3;jj++)
              for(int kk=0;kk<3;kk++)
                m(j+jj*nbFF_m,k+kk*nbFF_m) += (- me_cons[jj][kk] - me_comp[jj][kk] + Bhs * me_stab[jj][kk] );
          }
          for(int k=0;k<nbFF_p;k++){
            consAndCompC0PlateStiffnessTerms(Hhat_m,Bhat_m[j],Deltat_p[k],lbs,me_cons);
            consAndCompC0PlateStiffnessTerms(Hhat_p,Bhat_p[k],Deltat_m[j],lbs,me_comp);
            stabilityC0PlateStiffnessTerms(Hhatmean,Deltat_m[j], Deltat_p[k],lbs,me_stab);
            for(int jj=0;jj<3;jj++)
              for(int kk=0;kk<3;kk++)
                m(j+jj*nbFF_m,k+nbdof_m+kk*nbFF_p) += ( me_cons[jj][kk] - me_comp[jj][kk]- Bhs * me_stab[jj][kk] );
          }
        }
        for(int j=0;j<nbFF_p;j++){
          for(int k=0;k<nbFF_m;k++){
            consAndCompC0PlateStiffnessTerms(Hhat_p,Bhat_p[j],Deltat_m[k],lbs,me_cons);
            consAndCompC0PlateStiffnessTerms(Hhat_m,Bhat_m[k],Deltat_p[j],lbs,me_comp);
            stabilityC0PlateStiffnessTerms(Hhatmean,Deltat_p[j], Deltat_m[k],lbs,me_stab);
            for(int jj=0;jj<3;jj++)
              for(int kk=0;kk<3;kk++)
                m(j+(jj*nbFF_p)+nbdof_m,k+kk*nbFF_m) += (- me_cons[jj][kk] + me_comp[jj][kk] - Bhs * me_stab[jj][kk]);
          }
          for(int k=0;k<nbFF_p;k++){
            consAndCompC0PlateStiffnessTerms(Hhat_p,Bhat_p[j],Deltat_p[k],lbs,me_cons);
            consAndCompC0PlateStiffnessTerms(Hhat_p,Bhat_p[k],Deltat_p[j],lbs,me_comp);
            stabilityC0PlateStiffnessTerms(Hhatmean,Deltat_p[j], Deltat_p[k],lbs,me_stab);
            for(int jj=0;jj<3;jj++)
              for(int kk=0;kk<3;kk++)
                m(j+(jj*nbFF_p)+nbdof_m,k+(kk*nbFF_p)+nbdof_m) += ( me_cons[jj][kk] + me_comp[jj][kk] + Bhs * me_stab[jj][kk]);
          }
        }
        // Because component are push_back in Grads in gradfuvw idem for hess
        Grads_m.clear(); Grads_p.clear(); Hess_m.clear(); Hess_p.clear(); Grads.clear();
    }
//    m.print("Interface");
/*    // Compute the matrix by numerical perturbation Verif OK
    double eps=1.e-6;
    fullMatrix<double> fp(nbdof_m+nbdof_p,1);
    fullMatrix<double> fm(nbdof_m+nbdof_p,1);
    fp.setAll(0.);
    fm.setAll(0.);
    fullMatrix<double> m2(nbdof_m+nbdof_p,nbdof_m+nbdof_p); m2.setAll(0.);
    fullMatrix<double> disp(nbdof_m+nbdof_p,1);
    for(int j=0;j<nbdof_m+nbdof_p;j++){
      disp.setAll(0.); fm.setAll(0.);fp.setAll(0.);
      disp(j,0)=eps;
      this->getInterForce(iele,npts,GP,disp,fp);
      disp(j,0)=-eps;
      this->getInterForce(iele,npts,GP,disp,fm);
      for(int k=0;k<nbdof_m+nbdof_p;k++)
        m2(k,j)=(fp(k,0)-fm(k,0))/(2.*eps);
    }
    m2.print("Matrix by perturbation");*/
  }
  else
    {
      printf("not implemented\n");
    }
  }

  virtual void getInterForce(MInterfaceElement *iele,int npts,IntPt *GP,const fullMatrix<double> &disp, fullMatrix<double> &m){
    if (sym)
    {
      // data initialization
      // Retrieve of the element link to the interface element velem[0] == minus elem ; velem == plus elem
      MElement ** velem = iele->getElem();
      const int nbdof_m = BilinearTerm<SVector3,SVector3>::space1.getNumKeys(velem[0]);
      const int nbdof_p = BilinearTerm<SVector3,SVector3>::space1.getNumKeys(velem[1]);
      const int nbFF_m=nbdof_m/3;
      const int nbFF_p=nbdof_p/3;
      // Initialization
      m.resize(nbdof_m+nbdof_p, 1);
      m.setAll(0.);
      double uem,uep,vem,vep;
      std::vector<TensorialTraits<SVector3>::GradType> Grads_m;
      std::vector<TensorialTraits<SVector3>::GradType> Grads_p;
      std::vector<TensorialTraits<SVector3>::GradType> Grads;
      std::vector<TensorialTraits<SVector3>::HessType> Hess_m;
      std::vector<TensorialTraits<SVector3>::HessType> Hess_p;
      LocalBasis LBS,LBP,LBM;
      LocalBasis *lbs=&LBS; LocalBasis *lb_p=&LBP; LocalBasis *lb_m=&LBM;
      double Bhat_p[256][3][2][2],Bhat_m[256][3][2][2];
      LinearElasticShellHookeTensor HOOKEhat_p; LinearElasticShellHookeTensor *Hhat_p=&HOOKEhat_p;
      LinearElasticShellHookeTensor HOOKehat_m; LinearElasticShellHookeTensor *Hhat_m=&HOOKehat_m;
      LinearElasticShellHookeTensor HOOKehatmean; LinearElasticShellHookeTensor *Hhatmean=&HOOKehatmean;
      double Deltat_m[256][3][3], Deltat_p[256][3][3];
      double Cmt;
      double me_cons[3];
      double me_comp[3];
      double me_stab[3];

      // Characteristic size of interface element
      double h_s = iele->getCharacteristicSize();

      const double Bhs = beta1/h_s;
      // sum on Gauss' points
      for (int i = 0; i < npts; i++)
      {
        // Coordonate of Gauss' point i
        const double u = GP[i].pt[0]; const double v = GP[i].pt[1]; const double w = GP[i].pt[2];
        // Weight of Gauss' point i
        const double weight = GP[i].weight;
        //printf("Abscisse of gauss point %f\n",u);
        //Compute the position (u,v) in the element of the Gauss point (to know where evaluate the shape functions)
        iele->getuvOnElem(u,uem,vem,uep,vep);
        // Compute of gradient and hessian of shape functions on interface element and on elements
        // ATTENTION after multiplication by multipliers (functionspace 276) components are in the "second line of tensor change this ??
        BilinearTerm<SVector3,SVector3>::space1.gradfuvw(iele,u, v, w, Grads); // grad of shape fonction on interface element
        BilinearTerm<SVector3,SVector3>::space1.gradfuvw(velem[0],uem, vem, w, Grads_m); // w = 0
        BilinearTerm<SVector3,SVector3>::space1.gradfuvw(velem[1],uep, vep, w, Grads_p);
        BilinearTerm<SVector3,SVector3>::space1.hessfuvw(velem[0],uem, vem, w, Hess_m);
        BilinearTerm<SVector3,SVector3>::space1.hessfuvw(velem[1],uep, vep, w, Hess_p);

        // basis of elements and interface element
        lb_m->set(velem[0],Grads_m); // This function can become a method of MElement Plante lors du calcul de l'énergie  à cause de  std::vector<TensorialTraits<SVector3>::GradType> prob de template??
        lb_p->set(velem[1],Grads_p); // This function can become a method of MElement Plante lors du calcul de l'énergie  à cause de  std::vector<TensorialTraits<SVector3>::GradType> prob de template??
        lbs->set(iele,Grads,lb_p->gett0(),lb_m->gett0()); // This function can become a method of MElement Plante lors du calcul de l'énergie  à cause de  std::vector<TensorialTraits<SVector3>::GradType> prob de template??

        // PushForwardTensor
        lb_m->set_pushForward(lbs);
        lb_p->set_pushForward(lbs);

        // Compute of Bhat vector (1 component for now because 1 dof (z) ) --> it's a vector of length == nbFF
        Compute_Bhat(lb_p,Hess_p,nbFF_p,Bhat_p);
        Compute_Bhat(lb_m,Hess_m,nbFF_m,Bhat_m);
        // Compute of Hooke hat tensor on minus and plus element
        Cmt = weight * lbs->getJacobian()  * Cm; // Eh^3/(12(1-nu^2)) * weight gauss * jacobian
        Hhat_p->hat(lb_p,Cmt,nu);
        Hhat_m->hat(lb_m,Cmt,nu);
        Hhatmean->mean(Hhat_p,Hhat_m); // mean value of tensor by component used for stability term

        // Compute of Deltat_tilde
        compute_Deltat_tilde(lb_p,Grads_p,nbFF_p,Deltat_p);
        compute_Deltat_tilde(lb_m,Grads_m,nbFF_m,Deltat_m);

        // loop on dof ATTENTION SAME NUMBER OF DOF for the two elements TODO take into account a different dof numbers between the two elements There ok because sym ??
        for(int j=0;j<nbFF_m;j++){
          consC0PlateForceTerms(Hhat_m,nbFF_m,nbFF_p,Bhat_m[j],Deltat_m,Deltat_p,lbs,disp,me_cons);
          compC0PlateForceTerms(nbFF_m,nbFF_p, Hhat_m,Hhat_p,Bhat_m,Bhat_p,Deltat_m[j],lbs,disp,me_comp);
          stabilityC0PlateForceTerms(nbFF_m,nbFF_p,Hhatmean,Deltat_m[j],Deltat_m,Deltat_p,lbs,disp,me_stab);
          for(int jj=0;jj<3;jj++)
            m(j+jj*nbFF_m,0) += (me_cons[jj] - me_comp[jj]- Bhs * me_stab[jj] );
        }
        for(int j=0;j<nbFF_p;j++){
          consC0PlateForceTerms(Hhat_p,nbFF_m,nbFF_p,Bhat_p[j],Deltat_m,Deltat_p,lbs,disp,me_cons);
          compC0PlateForceTerms(nbFF_m,nbFF_p,Hhat_m,Hhat_p,Bhat_m,Bhat_p,Deltat_p[j],lbs,disp,me_comp);
          stabilityC0PlateForceTerms(nbFF_m,nbFF_p,Hhatmean,Deltat_p[j],Deltat_m,Deltat_p,lbs,disp,me_stab);
          for(int jj=0;jj<3;jj++)
            m(j+(jj*nbFF_p)+nbdof_m,0) += ( me_cons[jj] + me_comp[jj] + Bhs * me_stab[jj]);
        }
      // Because component are push_back in Grads in gradfuvw idem for hess
      Grads_m.clear(); Grads_p.clear(); Hess_m.clear(); Hess_p.clear(); Grads.clear();
      }
    }
  else
    {
      printf("not implemented\n");
    }

  }


  virtual void getInterOnBoundary(MInterfaceElement *iele,int npts,IntPt *GP,fullMatrix<double> &m)
  {
    if (sym)
    {
      // data initialization
      // Retrieve of the element link to the interface element velem[0] == minus elem ; velem == plus elem
      MElement ** velem = iele->getElem();
      const int nbdof_m = BilinearTerm<SVector3,SVector3>::space1.getNumKeys(velem[0]);
      const int nbFF_m = nbdof_m/3;
      // Initialization
      m.resize(nbdof_m, nbdof_m);
      m.setAll(0.);
      double uem,uep,vem,vep;
      std::vector<TensorialTraits<SVector3>::GradType> Grads_m;
      std::vector<TensorialTraits<SVector3>::GradType> Grads_p;
      std::vector<TensorialTraits<SVector3>::GradType> Grads;
      std::vector<TensorialTraits<SVector3>::HessType> Hess_m;
      std::vector<TensorialTraits<SVector3>::HessType> Hess_p;
      LocalBasis LBS,LBM;
      LocalBasis *lbs=&LBS; LocalBasis *lb_m=&LBM;
      //std::vector<std::vector<fullMatrix<double> > > Bhat_m;
      double Bhat_m[256][3][2][2];
      LinearElasticShellHookeTensor HOOKehat_m;
      LinearElasticShellHookeTensor *Hhat_m=&HOOKehat_m;
      double Deltat_m[256][3][3],Deltat_p[256][3][3];
      double Cmt;
      double me_cons[3][3];
      double me_comp[3][3];
      double me_stab[3][3];

      // Characteristic size of interface element
      double h_s = iele->getCharacteristicSize();
      const double Bhs = beta1/h_s;
      // sum on Gauss' points
      for (int i = 0; i < npts; i++)
      {
        // Coordonate of Gauss' point i
        const double u = GP[i].pt[0]; const double v = GP[i].pt[1]; const double w = GP[i].pt[2];
        // Weight of Gauss' point i
        const double weight = GP[i].weight;

        //printf("Abscisse of gauss point %f\n",u);
        //Compute the position (u,v) in the element of the Gauss point (to know where evaluate the shape functions)
        iele->getuvOnElem(u,uem,vem,uep,vep);
        //printf("Position (u,v) of minus element (%f,%f)\n",uem,vem);
        // Compute of gradient and hessian of shape functions on interface element and on elements
        // ATTENTION after multiplication by multipliers (functionspace 276) components are in the "second line of tensor change this ??
        BilinearTerm<SVector3,SVector3>::space1.gradfuvw(iele,u, v, w, Grads); // grad of shape fonction on interface element
        BilinearTerm<SVector3,SVector3>::space1.gradfuvw(velem[0],uem, vem, w, Grads_m); // w = 0
        BilinearTerm<SVector3,SVector3>::space1.hessfuvw(velem[0],uem, vem, w, Hess_m);

        // basis of elements and interface element
        lb_m->set(velem[0],Grads_m); // This function can become a method of MElement Plante lors du calcul de l'énergie  à cause de  std::vector<TensorialTraits<SVector3>::GradType> prob de template??
        lbs->set(iele,Grads,lb_m->gett0()); // This function can become a method of MElement Plante lors du calcul de l'énergie  à cause de  std::vector<TensorialTraits<SVector3>::GradType> prob de template??

        // PushForwardTensor
        lb_m->set_pushForward(lbs);

        /*printf("Local basis interface\n");
        lbs->print();
        printf("Local basis minus\n");
        lb_m->print();*/

        // Compute of Bhat vector (1 component for now because 1 dof (z) ) --> it's a vector of length == nbFF
        Compute_Bhat(lb_m,Hess_m,nbFF_m,Bhat_m);
        // Compute of Hooke hat tensor on minus and plus element
        Cmt = weight * lbs->getJacobian()  * Cm; // Eh^3/(12(1-nu^2)) * weight gauss * jacobian
        Hhat_m->hat(lb_m,Cmt,nu);

        // Compute of Deltat_tilde
        compute_Deltat_tildeBound(lb_m,Grads_m,nbFF_m,Deltat_m,lbs);

        // loop on dof ATTENTION SAME NUMBER OF DOF for the two elements TODO take into account a different dof numbers between the two elements There ok because sym ??
        for(int j=0;j<nbFF_m;j++){
          for(int k=0;k<nbFF_m;k++){
            consAndCompC0PlateStiffnessTerms(Hhat_m,Bhat_m[j],Deltat_m[k],lbs,me_cons);
            consAndCompC0PlateStiffnessTerms(Hhat_m,Bhat_m[k],Deltat_m[j],lbs,me_comp);
            stabilityC0PlateStiffnessTerms(Hhat_m,Deltat_m[j], Deltat_m[k],lbs,me_stab);
            for(int jj=0;jj<3;jj++)
              for(int kk=0;kk<3;kk++)
                m(j+jj*nbFF_m,k+kk*nbFF_m) += -(me_cons[jj][kk] + me_comp[jj][kk] - Bhs * me_stab[jj][kk]);
          }
        }

        // Because component are push_back in Grads in gradfuvw idem for hess
        Grads_m.clear(); Hess_m.clear(); Grads.clear();
    }
//    m.print("InterfaceBound");
/*    // Compute the matrix by numerical perturbation Verif OK
    double eps=1.e-8;
    fullMatrix<double> fm(nbdof_m,1), fp(nbdof_m,1);
    fullMatrix<double> m2(nbdof_m,nbdof_m); m2.setAll(0.);
    fullMatrix<double> disp(nbdof_m,1);
    for(int j=0;j<nbdof_m;j++){
      disp.setAll(0.); fm.setAll(0.); fp.setAll(0.);
      disp(j,0)=eps;
      this->getInterForceOnBoundary(iele,npts,GP,disp,fp);
      disp(j,0)=-eps;
      this->getInterForceOnBoundary(iele,npts,GP,disp,fm);
      for(int k=0;k<nbdof_m;k++)
        m2(k,j)=(fp(k,0)-fm(k,0))/(2.*eps);
    }
    m2.print("Matrix by perturbation");*/
  }
  else
    {
      printf("not implemented\n");
    }
  }

  virtual void getInterForceOnBoundary(MInterfaceElement *iele,int npts,IntPt *GP,const fullMatrix<double> &disp, fullMatrix<double> &m){
    if (sym)
    {
      // data initialization
      // Retrieve of the element link to the interface element velem[0] == minus elem ; velem == plus elem
      MElement ** velem = iele->getElem();
      const int nbdof_m = BilinearTerm<SVector3,SVector3>::space1.getNumKeys(velem[0]);
      const int nbFF_m = nbdof_m/3;
      // Initialization
      m.resize(nbdof_m, 1);
      m.setAll(0.);
      double uem,vem,uep,vep;
      std::vector<TensorialTraits<SVector3>::GradType> Grads_m;
      std::vector<TensorialTraits<SVector3>::GradType> Grads;
      std::vector<TensorialTraits<SVector3>::HessType> Hess_m;
      LocalBasis LBS,LBM;
      LocalBasis *lbs=&LBS; LocalBasis *lb_m=&LBM;
      double Bhat_m[256][3][2][2];
      LinearElasticShellHookeTensor HOOKehat_m;
      LinearElasticShellHookeTensor HOOKe_m;
      LinearElasticShellHookeTensor *Hhat_m=&HOOKehat_m;
      double Deltat_m[256][3][3];
      double Cmt;
      double me_cons[3];
      double me_comp[3];
      double me_stab[3];
      // Characteristic size of interface element
      double h_s = iele->getCharacteristicSize();

      const double Bhs = beta1/h_s;
      // sum on Gauss' points
      for (int i = 0; i < npts; i++)
      {
        // Coordonate of Gauss' point i
        const double u = GP[i].pt[0]; const double v = GP[i].pt[1]; const double w = GP[i].pt[2];
        // Weight of Gauss' point i
        const double weight = GP[i].weight;
        //printf("Abscisse of gauss point %f\n",u);
        //Compute the position (u,v) in the element of the Gauss point (to know where evaluate the shape functions)
        iele->getuvOnElem(u,uem,vem,uep,vep);
        // Compute of gradient and hessian of shape functions on interface element and on elements
        // ATTENTION after multiplication by multipliers (functionspace 276) components are in the "second line of tensor change this ??
        BilinearTerm<SVector3,SVector3>::space1.gradfuvw(iele,u, v, w, Grads); // grad of shape fonction on interface element
        BilinearTerm<SVector3,SVector3>::space1.gradfuvw(velem[0],uem, vem, w, Grads_m); // w = 0
        BilinearTerm<SVector3,SVector3>::space1.hessfuvw(velem[0],uem, vem, w, Hess_m);

        // basis of elements and interface element
        lb_m->set(velem[0],Grads_m); // This function can become a method of MElement Plante lors du calcul de l'énergie  à cause de  std::vector<TensorialTraits<SVector3>::GradType> prob de template??
        lbs->set(iele,Grads,lb_m->gett0()); // This function can become a method of MElement Plante lors du calcul de l'énergie  à cause de  std::vector<TensorialTraits<SVector3>::GradType> prob de template??

        // PushForwardTensor
        lb_m->set_pushForward(lbs);

        // Compute of Bhat vector (1 component for now because 1 dof (z) ) --> it's a vector of length == nbFF
        Compute_Bhat(lb_m,Hess_m,nbFF_m,Bhat_m);
        // Compute of Hooke hat tensor on minus and plus element
        Cmt = weight * lbs->getJacobian()  * Cm; // Eh^3/(12(1-nu^2)) * weight gauss * jacobian
        Hhat_m->hat(lb_m,Cmt,nu);

        // Compute of Deltat_tilde
        compute_Deltat_tildeBound(lb_m,Grads_m,nbFF_m,Deltat_m,lbs);

        for(int j=0;j<nbFF_m;j++){
          consC0PlateForceTermsBound(Hhat_m,nbFF_m,Bhat_m[j],Deltat_m,lbs,disp,me_cons);
          compC0PlateForceTermsBound(nbFF_m,Hhat_m,Bhat_m,Deltat_m[j],lbs,disp,me_comp);
          stabilityC0PlateForceTermsBound(nbFF_m,Hhat_m,Deltat_m[j],Deltat_m,lbs,disp,me_stab);
          for(int jj=0;jj<3;jj++)
            m(j+jj*nbFF_m,0) += (me_cons[jj] - me_comp[jj] - Bhs * me_stab[jj] );
        }
        // Because component are push_back in Grads in gradfuvw idem for hess
        Grads_m.clear(); Hess_m.clear(); Grads.clear();
      }
    }
  else
    {
      printf("not implemented\n");
    }

  }
}; // class IsotropicElasticInterfaceTermC0Plate
#endif // C0DGPLATETERMS_H
