// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Eric Bechet
//

#include "STensor33.h"

void STensor33::print(const char *s) const
{
  char format[2048];
  const char l[128] = "%12.5E %12.5E %12.5E \n";
  sprintf(format, " tensor3 %s : \n %s %s %s \n %s %s %s \n %s %s %s \n", s, l,
          l, l, l, l, l, l, l, l);
  printf(format, s, _val[0], _val[1], _val[2], _val[3], _val[4], _val[5],
         _val[6], _val[7], _val[8],

         _val[9], _val[10], _val[11], _val[12], _val[13], _val[14], _val[15],
         _val[16], _val[17],

         _val[18], _val[19], _val[20], _val[21], _val[22], _val[23], _val[24],
         _val[25], _val[26]);
}
