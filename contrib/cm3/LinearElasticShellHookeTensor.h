//
// C++ Interface: terms
//
// Description: Hooke Tensor for shell (linear elastic)
//
//
// Author:  <Gauthier BECKER>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

# ifndef LINEARELASTICSHELLHOOKETENSOR_H_
# define LINEARELASTICSHELLHOOKETENSOR_H_
#include "Tensor4dim2.h"
class LinearElasticShellHookeTensor : public Tensor4dim2{

  public :
    LinearElasticShellHookeTensor(){};
    ~LinearElasticShellHookeTensor(){};
    void set(const LocalBasis *lb,const double &C11,const double &nu){
      for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
          for(int ii=0;ii<2;ii++)
            for(int jj=0;jj<2;jj++)
              tensor[i][j][ii][jj] = C11*( nu*dot(lb->getphi0d(i),lb->getphi0d(j))*dot(lb->getphi0d(ii),lb->getphi0d(jj)) + 0.5*(1.-nu)*(dot(lb->getphi0d(i),lb->getphi0d(ii))*dot(lb->getphi0d(jj),lb->getphi0d(j)) + dot(lb->getphi0d(i),lb->getphi0d(jj))*dot(lb->getphi0d(ii),lb->getphi0d(j)) ) );
    }

    void set(const LocalBasis *lb,const double &nu){
      for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
          for(int ii=0;ii<2;ii++)
            for(int jj=0;jj<2;jj++)
              tensor[i][j][ii][jj] = ( nu*dot(lb->getphi0d(i),lb->getphi0d(j))*dot(lb->getphi0d(ii),lb->getphi0d(jj)) + 0.5*(1.-nu)*(dot(lb->getphi0d(i),lb->getphi0d(ii))*dot(lb->getphi0d(jj),lb->getphi0d(j)) + dot(lb->getphi0d(i),lb->getphi0d(jj))*dot(lb->getphi0d(ii),lb->getphi0d(j)) ) );
    }

    void hat(const LocalBasis *lb, const double C11, const double nu){
      double temp;
      for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
          for(int ii=0;ii<2;ii++)
            for(int jj=0;jj<2;jj++){
              temp =0.;
              for(int a=0;a<2;a++)
                for(int b=0;b<2;b++)
                  for(int c=0;c<2;c++)
                    for(int d=0;d<2;d++)
                      temp += lb->getT(a,i)*lb->getT(b,j)*( nu*dot(lb->getphi0d(a),lb->getphi0d(b))*dot(lb->getphi0d(c),lb->getphi0d(d)) + 0.5*(1.-nu)*(dot(lb->getphi0d(a),lb->getphi0d(c))*dot(lb->getphi0d(d),lb->getphi0d(b)) + dot(lb->getphi0d(a),lb->getphi0d(d))*dot(lb->getphi0d(c),lb->getphi0d(b)) )) *lb->getT(c,ii)*lb->getT(d,jj);
              tensor[i][j][ii][jj]=C11*temp;
            }
    }
    void hat(const LocalBasis *lb,const LinearElasticShellHookeTensor *H){
      double temp;
      for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
          for(int ii=0;ii<2;ii++)
            for(int jj=0;jj<2;jj++){
              temp =0.;
              for(int a=0;a<2;a++)
                for(int b=0;b<2;b++)
                  for(int c=0;c<2;c++)
                    for(int d=0;d<2;d++)
                      temp += lb->getT(a,i)*lb->getT(b,j)*H->get(a,b,c,d)*lb->getT(c,ii)*lb->getT(d,jj);
              this->tensor[i][j][ii][jj]=temp;
            }
    }
    void mean(const LinearElasticShellHookeTensor *Hp, const LinearElasticShellHookeTensor *Hm){
      for(int a=0;a<2;a++)
        for(int b=0;b<2;b++)
          for(int c=0;c<2;c++)
            for(int d=0;d<2;d++)
              tensor[a][b][c][d] = 0.5*(Hp->get(a,b,c,d)+Hm->get(a,b,c,d));
    }
};
#endif // LinearElasticShellHooketensor
