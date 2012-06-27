// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
#ifndef STENSOR63_H_
#define STENSOR63_H_

class STensor63{
  protected:
    double _val[3][3][3][3][3][3];

  public:
    STensor63(const double val = 0);
    STensor63(const STensor63& src);
    inline double &operator()(int i, int j,int k, int l, int m, int n){
      return _val[i][j][k][l][m][n];
    };
    inline double operator()(int i, int j, int k, int l, int m, int n) const{
      return _val[i][j][k][l][m][n];
    };
    STensor63& operator += (const STensor63 &other){
      for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
          for (int k=0; k<3; k++)
            for (int l=0; l<3; l++)
              for (int m=0; m<3; m++)
                for (int n=0; n<3; n++)
                  _val[i][j][k][l][m][n] += other._val[i][j][k][l][m][n];
      return *this;
    };
    STensor63& operator -= (const STensor63 &other){
      for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
          for (int k=0; k<3; k++)
            for (int l=0; l<3; l++)
              for (int m=0; m<3; m++)
                for (int n=0; n<3; n++)
                  _val[i][j][k][l][m][n] -= other._val[i][j][k][l][m][n];
      return *this;
    };
    STensor63& operator *= (const double &other){
      for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
          for (int k=0; k<3; k++)
            for (int l=0; l<3; l++)
              for (int m=0; m<3; m++)
                for (int n=0; n<3; n++)
                _val[i][j][k][l][m][n] *= other;
      return *this;
    };
};



#endif // STENSOR63_H_
