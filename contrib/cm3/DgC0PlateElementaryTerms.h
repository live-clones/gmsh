//
// C++ Interface: terms
//
// Description: Functions used to compute a component of elementary matrix term
//
//
// Author:  <Gauthier BECKER>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

// Or put in the file C0DgPlateTerms.h ??
#ifndef DGC0PLATEELEMENTARYTERMS_H_
#define DGC0PLATEELEMENTARYTERMS_H_

inline void diaprod(const double a[3], const double b[3], double m[3][3]){
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      m[i][j]=a[i]*b[j];
}

static inline void dot(const double a[3], const double b[3], double c[3]){
  for(int i=0;i<3;i++)
    c[i] = a[i]*b[i];
}

static inline void dot(const double a[3], const SVector3 &b, double c[3]){
  for(int i=0;i<3;i++)
    c[i] = a[i]*b(i);
}

inline void matTvectprod(const double m[3][3], const SVector3 &v, double v2[3]){
  double temp[3];
  for(int i=0;i<3;i++){
    temp[0] = m[0][i]; temp[1] = m[1][i]; temp[2] = m[2][i];
    v2[i] = dot(temp,v);
  }
}

inline void matTvectprod(const double m[3][3], const double v[3],  double v2[3]){
  double temp[3];
  for(int i=0;i<3;i++){
    temp[0] = m[0][i]; temp[1] = m[1][i]; temp[2] = m[2][i];
    v2[i] = dot(temp,v);
  }
}

// Compute the component (j,k) of the elementary stiffness matrix
inline void BulkC0PlateDGStiffnessMembraneTerms(const double Bj[3][2][2],const double Bk[3][2][2], const LinearElasticShellHookeTensor *H, double me[3][3]){
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      me[i][j]=0.; // make a methode in object me ??
  double mtemp[3][3];
  double v1[3], v2[3];
  for(int a=0;a<2;a++)
    for(int b=0;b<2;b++){
      v2[0] = Bk[0][a][b]; v2[1] = Bk[1][a][b]; v2[2]= Bk[2][a][b]; // make a method
      for(int c=0;c<2;c++)
        for(int d=0;d<2;d++){
          v1[0] = Bj[0][c][d]; v1[1]=Bj[1][c][d]; v1[2]=Bj[2][c][d]; //make a method
          diaprod(v1,v2,mtemp);
          for(int jj=0;jj<3;jj++)
            for(int kk=0;kk<3;kk++)
              me[jj][kk]+=(H->get(a,b,c,d)*mtemp[jj][kk]);
        }
    }
}

inline void BulkC0PlateDGStiffnessBendingTerms(TensorialTraits<double>::HessType &hessj, TensorialTraits<double>::HessType &hessk, const LinearElasticShellHookeTensor *H, const LocalBasis *lb, double me[3][3]){
  double mtemp[3][3];
  for(int i=0;i<3;i++) for(int j=0;j<3;j++) me[i][j]=0.;
  double B1[3],B2[3];
  for(int alpha=0;alpha<2;alpha++)
    for(int beta=0;beta<2;beta++){
      B1[0]=-hessj(alpha,beta)*lb->gett0(0); B1[1]=-hessj(alpha,beta)*lb->gett0(1); B1[2]=-hessj(alpha,beta)*lb->gett0(2);
      for(int gamma=0;gamma<2;gamma++)
        for(int delta=0;delta<2;delta++){
          B2[0]=-hessk(gamma,delta)*lb->gett0(0); B2[1]=-hessk(gamma,delta)*lb->gett0(1); B2[2]=-hessk(gamma,delta)*lb->gett0(2);
          diaprod(B1,B2,mtemp);
          for(int jj=0;jj<3;jj++)
            for(int kk=0;kk<3;kk++)
              me[jj][kk]+=H->get(alpha,beta,gamma,delta)*mtemp[jj][kk];
        }
    }
}

inline void consAndCompC0PlateStiffnessTerms(LinearElasticShellHookeTensor *Hhat,const double Bhat[3][2][2],const double dt[3][3], const LocalBasis *lb, double me[3][3]){
  for(int i=0;i<3;i++) for(int j=0;j<3;j++) me[i][j]=0.;
  double v1[3], v2[3];
  double mtemp[3][3];
  double temp=0.;
  for(int alpha=0;alpha<2;alpha++)
    for(int beta=0;beta<2;beta++)
      for(int gamma=0;gamma<2;gamma++)
        for(int delta=0;delta<2;delta++){
          v1[0] = Bhat[0][gamma][delta]; v1[1] = Bhat[1][gamma][delta]; v1[2] = Bhat[2][gamma][delta];
          matTvectprod(dt,lb->getphi0(alpha),v2);
          diaprod(v1,v2,mtemp);
          temp = 0.5*Hhat->get(alpha,beta,gamma,delta)*(-lb->getphi0(1,beta));
          for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
              me[i][j] += (mtemp[i][j]*temp);
        }
}

inline void stabilityC0PlateStiffnessTerms(LinearElasticShellHookeTensor *Hhat, const double dta[3][3], const double dtb[3][3], const LocalBasis *lb, double me[3][3]){
  for(int i=0;i<3;i++) for(int j=0;j<3;j++) me[i][j]=0.;
  double mtemp[3][3];
  double v1[3],v2[3];
  double temp=0.;
  for(int alpha=0;alpha<2;alpha++)
    for(int beta=0;beta<2;beta++)
      for(int gamma=0;gamma<2;gamma++)
        for(int delta=0;delta<2;delta++){
          matTvectprod(dta,lb->getphi0(gamma),v1);
          matTvectprod(dtb,lb->getphi0(alpha),v2);
          diaprod(v1,v2,mtemp);
          temp = Hhat->get(alpha,beta,gamma,delta)*(-lb->getphi0(1,delta))*(-lb->getphi0(1,beta));
          for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
              me[i][j]+=(mtemp[i][j]*temp);
        }
}


inline void BulkC0PlateDGForceBendingTerms(const TensorialTraits<double>::HessType &hessj,const std::vector<TensorialTraits<double>::HessType> &Hess,const LinearElasticShellHookeTensor *H,const LocalBasis *lb,const fullMatrix<double> &disp, double me[3]){
  const int n = Hess.size();
  for(int i=0;i<3;i++) me[i]=0.;
  double mtemp[3][3];
  double B1[3],B2[3];
  for(int a=0;a<2;a++)
    for(int b=0;b<2;b++)
      for(int c=0;c<2;c++)
        for(int d=0;d<2;d++){
          B1[0] = - hessj(c,d)*lb->gett0(0); B1[1] = - hessj(c,d)*lb->gett0(1); B1[2] = - hessj(c,d)*lb->gett0(2);
          for(int j=0;j<n;j++){
            B2[0] = - Hess[j](a,b)*lb->gett0(0); B2[1] = - Hess[j](a,b)*lb->gett0(1); B2[2] = - Hess[j](a,b)*lb->gett0(2);
            diaprod(B1,B2,mtemp);
            for(int i=0;i<3;i++)
              me[i]+=H->get(a,b,c,d)*(mtemp[i][0]*disp(j,0)+mtemp[i][1]*disp(j+n,0)+mtemp[i][2]*disp(j+2*n,0));
          }
        }
}

inline void BulkC0PlateDGForceMembraneTerms(const double Bj[3][2][2],const double Bn[256][3][2][2] , const LinearElasticShellHookeTensor *H, const int n, const fullMatrix<double> &disp, double me[3]){
  for(int i=0;i<3;i++) me[i]=0.;
  double mtemp[3][3];
  SVector3 v1(0.,0.,0.), v2(0.,0.,0.);
  for(int a=0;a<2;a++)
    for(int b=0;b<2;b++)
      for(int c=0;c<2;c++)
        for(int d=0;d<2;d++){
          v1(0) = Bj[0][c][d]; v1(1) = Bj[1][c][d]; v1[2]=Bj[2][c][d];
          for(int j=0;j<n;j++){
            v2(0) = Bn[j][0][a][b]; v2(1) = Bn[j][1][a][b]; v2(2) = Bn[j][2][a][b];
            diaprod(v1,v2,mtemp);
            for(int jj=0;jj<3;jj++)
              me[jj] += H->get(a,b,c,d)*(mtemp[jj][0]*disp(j,0)+mtemp[jj][1]*disp(j+n,0)+mtemp[jj][2]*disp(j+2*n,0));
          }
        }

}

inline void consC0PlateForceTerms(const LinearElasticShellHookeTensor *Hhat, const int n_m, const int n_p, const double Bhat[3][2][2], const double Dt_m[256][3][3], const double Dt_p[256][3][3],const LocalBasis *lb, const fullMatrix<double> &disp, double me[3]){
  double mtemp[3][3];
  double v1[3],v2[3];
  double temp=0.;
  for(int i=0;i<3;i++) me[i]=0.;
  for(int a=0;a<2;a++)
    for(int b=0;b<2;b++)
      for(int c=0;c<2;c++)
        for(int d=0;d<2;d++){
          v1[0]=Bhat[0][c][d] ; v1[1]=Bhat[1][c][d]; v1[2]=Bhat[2][c][d];
          temp = 0.5*Hhat->get(a,b,c,d)*(-lb->getphi0(1,b));
          for(int j=0;j<n_m;j++){
            matTvectprod(Dt_m[j],lb->getphi0(a),v2); // put in a loop but in this time a vector is need to store the result of matTvectprod
            diaprod(v1,v2,mtemp);
            for(int k=0;k<3;k++)
              me[k] += -temp*(mtemp[k][0]*disp(j,0)+mtemp[k][1]*disp(j+n_m,0)+mtemp[k][2]*disp(j+2*n_m,0));
          }
          for(int j=0;j<n_p;j++){
            matTvectprod(Dt_p[j],lb->getphi0(a),v2); //idem
            diaprod(v1,v2,mtemp);
            for(int k=0;k<3;k++)
              me[k] += temp*(mtemp[k][0]*disp(j+3*n_m,0)+mtemp[k][1]*disp(j+n_p+3*n_m,0)+mtemp[k][2]*disp(j+2*n_p+3*n_m,0));
          }
        }
}

inline void compC0PlateForceTerms(const int n_m, const int n_p, const LinearElasticShellHookeTensor *Hhat_m, const LinearElasticShellHookeTensor *Hhat_p, const double Bhat_m[256][3][2][2],const double Bhat_p[256][3][2][2],const double Dt[3][3],const LocalBasis *lb, const fullMatrix<double> &disp, double me[3]){
  double v1[3],v2[3];
  double mtemp[3][3];
  double temp_m=0.;
  double temp_p=0.;
  for(int i=0;i<3;i++) me[i]=0.;
  for(int a=0;a<2;a++){
    matTvectprod(Dt,lb->getphi0(a),v1);
    for(int b=0;b<2;b++)
      for(int c=0;c<2;c++)
        for(int d=0;d<2;d++){
          temp_m = 0.5*Hhat_m->get(a,b,c,d)*(-lb->getphi0(1,b));
          temp_p = 0.5*Hhat_p->get(a,b,c,d)*(-lb->getphi0(1,b));
          for(int j=0;j<n_m;j++){
            v2[0] = Bhat_m[j][0][c][d]; v2[1] = Bhat_m[j][1][c][d]; v2[2] = Bhat_m[j][2][c][d];
            diaprod(v1,v2,mtemp);
            for(int jj=0;jj<3;jj++)
              me[jj]+= temp_m*(mtemp[jj][0]*disp(j,0)+mtemp[jj][1]*disp(j+n_m,0)+mtemp[jj][2]*disp(j+2*n_m,0));
          }
          for(int j=0;j<n_p;j++){
           v2[0] = Bhat_p[j][0][c][d]; v2[1] = Bhat_p[j][1][c][d]; v2[2]=Bhat_p[j][2][c][d];
           diaprod(v1,v2,mtemp);
           for(int jj=0;jj<3;jj++)
             me[jj]+= temp_p*(mtemp[jj][0]*disp(j+3*n_m,0)+mtemp[jj][1]*disp(j+n_p+3*n_m,0)+mtemp[jj][2]*disp(j+2*n_p+3*n_m,0));
          }
        }
  }
}

inline void stabilityC0PlateForceTerms(const int n_p,const int n_m, const LinearElasticShellHookeTensor *Hhat,const  double Dt[3][3],const double Dt_m[256][3][3],const double Dt_p[256][3][3], const LocalBasis *lb, const fullMatrix<double> &disp, double me[3]){
  for(int i=0;i<3;i++) me[i]=0.;
  double v1[3],v2[3];
  double mtemp[3][3];
  double temp=0.;
  for(int a=0;a<2;a++)
    for(int b=0;b<2;b++)
      for(int c=0;c<2;c++){
        matTvectprod(Dt,lb->getphi0(c),v1);
        for(int d=0;d<2;d++){
          temp = Hhat->get(a,b,c,d)*(-lb->getphi0(1,d))*(-lb->getphi0(1,b));
          for(int j=0;j<n_m;j++){
            matTvectprod(Dt_m[j],lb->getphi0(a),v2); // can be put on a loop but it is necessary to create a vector to keep the result of matTvectprod
            diaprod(v1,v2,mtemp);
            for(int jj=0;jj<3;jj++)
              me[jj] += -temp*(mtemp[jj][0]*disp(j,0)+mtemp[jj][1]*disp(j+n_m,0)+mtemp[jj][2]*disp(j+2*n_m,0));
          }
          for(int j=0;j<n_p;j++){
            matTvectprod(Dt_p[j],lb->getphi0(a),v2); // idem
            diaprod(v1,v2,mtemp);
            for(int jj=0;jj<3;jj++)
              me[jj] += temp*(mtemp[jj][0]*disp(j+3*n_m,0)+mtemp[jj][1]*disp(j+n_p+3*n_m,0)+mtemp[jj][2]*disp(j+2*n_p+3*n_m,0));
          }
       }
      }
}

inline void consC0PlateForceTermsBound(const LinearElasticShellHookeTensor *Hhat, const int n, const double Bhat[3][2][2], const double Dt_m[256][3][3], const LocalBasis *lb, const fullMatrix<double> &disp, double me[3]){
  double mtemp[3][3];
  double v1[3],v2[3];
  double temp=0.;
  for(int i=0;i<3;i++) me[i]=0.;
  for(int a=0;a<2;a++)
    for(int b=0;b<2;b++)
      for(int c=0;c<2;c++)
        for(int d=0;d<2;d++){
          v1[0]=Bhat[0][c][d] ; v1[1]=Bhat[1][c][d]; v1[2]=Bhat[2][c][d];
          temp = 0.5*Hhat->get(a,b,c,d)*(-lb->getphi0(1,b));
          for(int j=0;j<n;j++){
            matTvectprod(Dt_m[j],lb->getphi0(a),v2); // put in a loop but in this time a vector is need to store the result of matTvectprod
            diaprod(v1,v2,mtemp);
            for(int k=0;k<3;k++)
              me[k] += -temp*(mtemp[k][0]*disp(j,0)+mtemp[k][1]*disp(j+n,0)+mtemp[k][2]*disp(j+2*n,0));
          }
        }
}

inline void compC0PlateForceTermsBound(const int n_m,const LinearElasticShellHookeTensor *Hhat_m, const double Bhat_m[256][3][2][2], const double Dt[3][3],const LocalBasis *lb, const fullMatrix<double> &disp, double me[3]){
  double v1[3],v2[3];
  double mtemp[3][3];
  double temp_m=0.;
  for(int i=0;i<3;i++) me[i]=0.;
  for(int a=0;a<2;a++){
    matTvectprod(Dt,lb->getphi0(a),v1);
    for(int b=0;b<2;b++)
      for(int c=0;c<2;c++)
        for(int d=0;d<2;d++){
          temp_m = 0.5*Hhat_m->get(a,b,c,d)*(-lb->getphi0(1,b));
          for(int j=0;j<n_m;j++){
            v2[0] = Bhat_m[j][0][c][d]; v2[1] = Bhat_m[j][1][c][d]; v2[2] = Bhat_m[j][2][c][d];
            diaprod(v1,v2,mtemp);
            for(int jj=0;jj<3;jj++)
              me[jj]+= temp_m*(mtemp[jj][0]*disp(j,0)+mtemp[jj][1]*disp(j+n_m,0)+mtemp[jj][2]*disp(j+2*n_m,0));
          }
        }
  }
}

inline void stabilityC0PlateForceTermsBound(const int n_m,const LinearElasticShellHookeTensor *Hhat,const double Dt[3][3],const double Dt_m[256][3][3], const LocalBasis *lb, const fullMatrix<double> &disp, double me[3]){
  for(int i=0;i<3;i++) me[i]=0.;
  double v1[3],v2[3];
  double mtemp[3][3];
  double temp=0.;
  for(int a=0;a<2;a++)
    for(int b=0;b<2;b++)
      for(int c=0;c<2;c++){
        matTvectprod(Dt,lb->getphi0(c),v1);
        for(int d=0;d<2;d++){
          temp = Hhat->get(a,b,c,d)*(-lb->getphi0(1,d))*(-lb->getphi0(1,b));
          for(int j=0;j<n_m;j++){
            matTvectprod(Dt_m[j],lb->getphi0(a),v2); // can be put on a loop but it is necessary to create a vector to keep the result of matTvectprod
            diaprod(v1,v2,mtemp);
            for(int jj=0;jj<3;jj++)
              me[jj] += -temp*(mtemp[jj][0]*disp(j,0)+mtemp[jj][1]*disp(j+n_m,0)+mtemp[jj][2]*disp(j+2*n_m,0));
          }
        }
      }
}

// Compute value needed in get
void compute_Bn(const LocalBasis *lb, const std::vector<TensorialTraits<SVector3>::GradType> &Grads, const int n, double B[][3][2][2]){
  for(int i=0;i<n;i++){
    for(int a=0;a<2;a++)
      for(int b=0;b<2;b++){
        B[i][0][a][b] = 0.5*(lb->getphi0(a,0)*Grads[i](0,b)+lb->getphi0(b,0)*Grads[i](0,a) );
        B[i][1][a][b] = 0.5*(lb->getphi0(a,1)*Grads[i](0,b)+lb->getphi0(b,1)*Grads[i](0,a) );
        B[i][2][a][b] = 0.5*(lb->getphi0(a,2)*Grads[i](0,b)+lb->getphi0(b,2)*Grads[i](0,a) );
      }
  }

}

void  Compute_Bhat(const LocalBasis *lb,const std::vector<TensorialTraits<double>::HessType> &Hess, const int &n, double B[256][3][2][2]){
  for(int i=0;i<n;i++){
    for(int ii=0;ii<3;ii++){
      B[i][ii][0][0] =0.; B[i][ii][0][1]=0.; B[i][ii][1][0]=0.; B[i][ii][1][1]=0.;
      for(int j=0;j<2;j++)
        for(int k=0;k<2;k++){
          B[i][ii][0][0] += -lb->gett0(ii)*lb->gett(0,j)*Hess[i](j,k)*lb->gett(0,k);
          B[i][ii][0][1] += -lb->gett0(ii)*lb->gett(0,j)*Hess[i](j,k)*lb->gett(1,k);
          B[i][ii][1][0] += -lb->gett0(ii)*lb->gett(1,j)*Hess[i](j,k)*lb->gett(0,k);
          B[i][ii][1][1] += -lb->gett0(ii)*lb->gett(1,j)*Hess[i](j,k)*lb->gett(1,k);
        }
    }
  }
}

// Compute value needed in getinter
void compute_Deltat_tilde(const LocalBasis *lb, const std::vector<TensorialTraits<SVector3>::GradType> &Grads, const int &n, double Deltat[256][3][3]){
  SVector3 vect(0.,0.,0.),vect2(0.,0.,0.);
  vect = crossprod(lb->gett0(),lb->getphi0(0));
  vect2= crossprod(lb->gett0(),lb->getphi0(1));
  double invJ0 = 1./lb->getJacobian();
  for(int i=0;i<n;i++){
    Deltat[i][0][0] = invJ0 *(-lb->gett0(0)*vect(2)*Grads[i](0,1) + lb->gett0(0)*vect2(2))*Grads[i](0,0);
    Deltat[i][1][0] = invJ0 *((lb->getphi0(0,2)-lb->gett0(1)*vect(2))*Grads[i](0,1) - (lb->getphi0(1,2)-lb->gett0(1)*vect2(2))*Grads[i](0,0));
    Deltat[i][2][0] = invJ0 *((-lb->getphi0(0,1)-lb->gett0(2)*vect(2))*Grads[i](0,1) - (-lb->getphi0(1,1)-lb->gett0(2)*vect2(2))*Grads[i](0,0));

    Deltat[i][0][1] = invJ0 *((-lb->getphi0(0,2)-lb->gett0(0)*vect(2))*Grads[i](0,1) - (-lb->getphi0(1,2)-lb->gett0(0)*vect2(2))*Grads[i](0,0));
    Deltat[i][1][1] = invJ0 *(-lb->gett0(1)*vect(2)*Grads[i](0,1) + lb->gett0(1)*vect2(2)*Grads[i](0,0));
    Deltat[i][2][1] = invJ0 *((lb->getphi0(0,0)-lb->gett0(2)*vect(2))*Grads[i](0,1) - (lb->getphi0(1,0)-lb->gett0(2)*vect2(2))*Grads[i](0,0));

    Deltat[i][0][2] = invJ0 *((lb->getphi0(0,1)-lb->gett0(0)*vect(2))*Grads[i](0,1) - (lb->getphi0(1,1)-lb->gett0(0)*vect2(2))*Grads[i](0,0));
    Deltat[i][1][2] = invJ0 *((-lb->getphi0(0,0)-lb->gett0(1)*vect(2))*Grads[i](0,1) - (-lb->getphi0(1,0)-lb->gett0(1)*vect2(2))*Grads[i](0,0));
    Deltat[i][2][2] = invJ0 *( -lb->gett0(2)*vect(2)*Grads[i](0,1) + lb->gett0(2)*vect2(2)*Grads[i](0,0));
  }
}
void compute_Deltat_tildeBound(const LocalBasis *lb, const std::vector<TensorialTraits<SVector3>::GradType> &Grads, const int &n, double Deltat[256][3][3], const LocalBasis *lbs){
  SVector3 vect(0.,0.,0.),vect2(0.,0.,0.),temp2(0.,0.,0.),temp3(0.,0.,0.),phi1norm(0.,0.,0.);
  vect = crossprod(lb->gett0(),lb->getphi0(0));
  vect2= crossprod(lb->gett0(),lb->getphi0(1));
  phi1norm=lbs->getphi0(0);
  phi1norm.normalize();
  double temp[3][3];
  double invJ0 = 1./lb->getJacobian();
  for(int i=0;i<n;i++){
    temp[0][0] = invJ0 *(-lb->gett0(0)*vect(2)*Grads[i](0,1) + lb->gett0(0)*vect2(2))*Grads[i](0,0);
    temp[1][0] = invJ0 *((lb->getphi0(0,2)-lb->gett0(1)*vect(2))*Grads[i](0,1) - (lb->getphi0(1,2)-lb->gett0(1)*vect2(2))*Grads[i](0,0));
    temp[2][0] = invJ0 *((-lb->getphi0(0,1)-lb->gett0(2)*vect(2))*Grads[i](0,1) - (-lb->getphi0(1,1)-lb->gett0(2)*vect2(2))*Grads[i](0,0));

    temp[0][1] = invJ0 *((-lb->getphi0(0,2)-lb->gett0(0)*vect(2))*Grads[i](0,1) - (-lb->getphi0(1,2)-lb->gett0(0)*vect2(2))*Grads[i](0,0));
    temp[1][1] = invJ0 *(-lb->gett0(1)*vect(2)*Grads[i](0,1) + lb->gett0(1)*vect2(2)*Grads[i](0,0));
    temp[2][1] = invJ0 *((lb->getphi0(0,0)-lb->gett0(2)*vect(2))*Grads[i](0,1) - (lb->getphi0(1,0)-lb->gett0(2)*vect2(2))*Grads[i](0,0));

    temp[0][2] = invJ0 *((lb->getphi0(0,1)-lb->gett0(0)*vect(2))*Grads[i](0,1) - (lb->getphi0(1,1)-lb->gett0(0)*vect2(2))*Grads[i](0,0));
    temp[1][2] = invJ0 *((-lb->getphi0(0,0)-lb->gett0(1)*vect(2))*Grads[i](0,1) - (-lb->getphi0(1,0)-lb->gett0(1)*vect2(2))*Grads[i](0,0));
    temp[2][2] = invJ0 *( -lb->gett0(2)*vect(2)*Grads[i](0,1) + lb->gett0(2)*vect2(2)*Grads[i](0,0));

    // Projection of normal
    for(int j=0;j<3;j++){
      temp3(0)=temp[0][j]; temp3(1)=temp[1][j]; temp3(2)=temp[2][j];
      temp2=dot(temp3,phi1norm)*phi1norm;
      temp3-=temp2;
      Deltat[i][0][j]=temp3(0);Deltat[i][1][j]=temp3(1); Deltat[i][2][j]=temp3(2);
    }
  }
}
#endif //DGC0PLATEELEMENTARYTERMS_H_
