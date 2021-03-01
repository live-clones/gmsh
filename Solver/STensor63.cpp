// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "STensor63.h"

STensor63::STensor63(const double val)
{
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      for(int k = 0; k < 3; k++)
        for(int l = 0; l < 3; l++)
          for(int m = 0; m < 3; m++)
            for(int n = 0; n < 3; n++) _val[i][j][k][l][m][n] = val;
};

STensor63::STensor63(const STensor63 &src)
{
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      for(int k = 0; k < 3; k++)
        for(int l = 0; l < 3; l++)
          for(int m = 0; m < 3; m++)
            for(int n = 0; n < 3; n++)
              _val[i][j][k][l][m][n] = src._val[i][j][k][l][m][n];
};
