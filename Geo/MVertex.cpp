// $Id: MVertex.cpp,v 1.5 2006-08-15 06:26:52 geuzaine Exp $
//
// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include <math.h>
#include "MVertex.h"

int MVertex::_globalNum = 0;
double MVertexLessThanLexicographic::tolerance = 1.e-6;

void MVertex::writeMSH(FILE *fp, double scalingFactor)
{
  fprintf(fp, "%d %.16g %.16g %.16g\n", _num, x() * scalingFactor, 
	  y() * scalingFactor, z() * scalingFactor);
}

void MVertex::writeMSH(FILE *fp, double version, int num, 
		       int elementary, int physical)
{
  fprintf(fp, "%d 15", num);
  if(version < 2.0)
    fprintf(fp, " %d %d 1", physical, elementary);
  else
    fprintf(fp, " 2 %d %d", physical, elementary);
  fprintf(fp, " %d\n", _num);
}

void MVertex::writeVRML(FILE *fp, double scalingFactor)
{
  fprintf(fp, "%.16g %.16g %.16g,\n",
	  x() * scalingFactor, y() * scalingFactor, z() * scalingFactor);
}

void MVertex::writeUNV(FILE *fp, double scalingFactor)
{
  fprintf(fp, "%10d%10d%10d%10d\n", _num, 1, 1, 11);
  // hack to print the numbers with "D+XX" exponents
  char tmp[128];
  sprintf(tmp, "%25.16E%25.16E%25.16E\n", x() * scalingFactor, 
	  y() * scalingFactor, z() * scalingFactor);
  tmp[21] = 'D';
  tmp[46] = 'D';
  tmp[71] = 'D';
  fprintf(fp, tmp);
}

void MVertex::writeMESH(FILE *fp, double scalingFactor)
{
  fprintf(fp, " %20.14E      %20.14E      %20.14E      %d\n", 
	  x() * scalingFactor, y() * scalingFactor, z() * scalingFactor, 0);
}
