// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
#ifndef STENSOR53_H_
#define STENSOR53_H_

class STensor53 {
  protected:
    double _val[3][3][3][3][3];

  public:
    STensor53(const double val = 0);
    STensor53(const STensor53& src);
    inline double &operator()(int i, int j,int k, int l, int m){
      return _val[i][j][k][l][m];
    };
    inline double operator()(int i, int j, int k, int l, int m) const{
      return _val[i][j][k][l][m];
    };
    STensor53& operator += (const STensor53 &other){
      for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
          for (int k=0; k<3; k++)
            for (int l=0; l<3; l++)
              for (int m=0; m<3; m++)
                _val[i][j][k][l][m] += other._val[i][j][k][l][m];
      return *this;
    };
    STensor53& operator -= (const STensor53 &other){
      for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
          for (int k=0; k<3; k++)
            for (int l=0; l<3; l++)
              for (int m=0; m<3; m++)
                _val[i][j][k][l][m] -= other._val[i][j][k][l][m];
      return *this;
    };
    STensor53& operator *= (const double &other){
      for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
          for (int k=0; k<3; k++)
            for (int l=0; l<3; l++)
              for (int m=0; m<3; m++)
                _val[i][j][k][l][m] *= other;
      return *this;
    };
};



#endif // STENSOR53_H_
