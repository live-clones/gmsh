// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "STensor53.h"

STensor53::STensor53(const double val)
{
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      for(int k = 0; k < 3; k++)
        for(int l = 0; l < 3; l++)
          for(int m = 0; m < 3; m++) _val[i][j][k][l][m] = val;
};

STensor53::STensor53(const STensor53 &src)
{
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      for(int k = 0; k < 3; k++)
        for(int l = 0; l < 3; l++)
          for(int m = 0; m < 3; m++)
            _val[i][j][k][l][m] = src._val[i][j][k][l][m];
};
