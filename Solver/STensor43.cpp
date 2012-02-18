// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Eric Bechet
//

#include "STensor43.h"

void STensor43::print (const char *s) const
{
  char format[2048];
  const char l[256]="%12.5E %12.5E %12.5E  %12.5E %12.5E %12.5E  %12.5E %12.5E %12.5E \n";
  sprintf (format, " tensor4 %s : \n %s %s %s \n %s %s %s \n %s %s %s \n",s, l,l,l, l,l,l, l,l,l);
  printf(format,s,_val[ 0],_val[ 1],_val[ 2], _val[ 3],_val[ 4],_val[ 5], _val[ 6],_val[ 7],_val[ 8],
                  _val[ 9],_val[10],_val[11], _val[12],_val[13],_val[14], _val[15],_val[16],_val[17],
                  _val[18],_val[19],_val[20], _val[21],_val[22],_val[23], _val[24],_val[25],_val[26],

                  _val[27],_val[28],_val[29], _val[30],_val[31],_val[32], _val[33],_val[34],_val[35],
                  _val[36],_val[37],_val[38], _val[39],_val[40],_val[41], _val[42],_val[43],_val[44],
                  _val[45],_val[46],_val[47], _val[48],_val[49],_val[50], _val[51],_val[52],_val[53],

                  _val[54],_val[55],_val[56], _val[57],_val[58],_val[59], _val[60],_val[61],_val[62],
                  _val[63],_val[64],_val[65], _val[66],_val[67],_val[68], _val[69],_val[70],_val[71],
                  _val[72],_val[73],_val[74], _val[75],_val[76],_val[77], _val[78],_val[79],_val[80]);
}
