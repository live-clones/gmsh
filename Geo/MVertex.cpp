// $Id: MVertex.cpp,v 1.14 2007-07-31 22:09:11 geuzaine Exp $
//
// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
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

bool MVertexLessThanLexicographic::operator()(const MVertex *v1, const MVertex *v2) const
{
  if(v1->x() - v2->x() >  tolerance) return true;
  if(v1->x() - v2->x() < -tolerance) return false;
  if(v1->y() - v2->y() >  tolerance) return true;
  if(v1->y() - v2->y() < -tolerance) return false;
  if(v1->z() - v2->z() >  tolerance) return true;
  return false;
}

void MVertex::writeMSH(FILE *fp, bool binary, double scalingFactor)
{
  if(_num < 0) return; // negative vertices are never saved

  if(!binary){
    fprintf(fp, "%d %.16g %.16g %.16g\n", _num, 
	    x() * scalingFactor, 
	    y() * scalingFactor,
	    z() * scalingFactor);
  }
  else{
    fwrite(&_num, sizeof(int), 1, fp);
    double data[3] = {x() * scalingFactor, y() * scalingFactor, z() * scalingFactor};
    fwrite(data, sizeof(double), 3, fp);
  }
}

void MVertex::writeMSH(FILE *fp, double version, bool binary, int num, 
		       int elementary, int physical)
{
  if(!binary){
    fprintf(fp, "%d 15", num);
    if(version < 2.0)
      fprintf(fp, " %d %d 1", physical, elementary);
    else
      fprintf(fp, " 2 %d %d", physical, elementary);
    fprintf(fp, " %d\n", _num);
  }
  else{
    int tags[4] = {num, physical, elementary, 0};
    fwrite(tags, sizeof(int), 4, fp);
    int verts[1] = {_num};
    fwrite(verts, sizeof(int), 1, fp);
  }
}

void MVertex::writeVRML(FILE *fp, double scalingFactor)
{
  if(_num < 0) return; // negative vertices are never saved

  fprintf(fp, "%.16g %.16g %.16g,\n",
	  x() * scalingFactor, y() * scalingFactor, z() * scalingFactor);
}

void MVertex::writeUNV(FILE *fp, double scalingFactor)
{
  if(_num < 0) return; // negative vertices are never saved

  int coord_sys = 1;
  int displacement_coord_sys = 1;
  int color = 11;
  fprintf(fp, "%10d%10d%10d%10d\n", _num, coord_sys, displacement_coord_sys, color);
  // hack to print the numbers with "D+XX" exponents
  char tmp[128];
  sprintf(tmp, "%25.16E%25.16E%25.16E\n", x() * scalingFactor, 
	  y() * scalingFactor, z() * scalingFactor);
  for(unsigned int i = 0; i < strlen(tmp); i++) if(tmp[i] == 'E') tmp[i] = 'D';
  fprintf(fp, tmp);
}

void MVertex::writeMESH(FILE *fp, double scalingFactor)
{
  if(_num < 0) return; // negative vertices are never saved

  fprintf(fp, " %20.14G      %20.14G      %20.14G      %d\n", 
	  x() * scalingFactor, y() * scalingFactor, z() * scalingFactor, 0);
}

static void double_to_char8(double val, char *str){
  if(val >= 1.e6)
    sprintf(str, "%.2E", val);
  else if(val >= 1.e-3)
    sprintf(str, "%f", val);
  else if(val >= 0)
    sprintf(str, "%.2E", val);
  else if(val >= -1.e-3)
    sprintf(str, "%.1E", val);
  else if(val >= -1.e6)
    sprintf(str, "%f", val);
  else
    sprintf(str, "%.1E", val);
  str[8] = '\0';
}

void MVertex::writeBDF(FILE *fp, int format, double scalingFactor)
{
  if(_num < 0) return; // negative vertices are never saved

  char xs[17], ys[17], zs[17];
  double x1 = x() * scalingFactor;
  double y1 = y() * scalingFactor;
  double z1 = z() * scalingFactor;
  if(format == 0){
    // free field format (max 8 char per field, comma separated, 10 per line)
    double_to_char8(x1, xs); double_to_char8(y1, ys); double_to_char8(z1, zs);
    fprintf(fp, "GRID,%d,%d,%s,%s,%s\n", _num, 0, xs, ys, zs);
  }
  else if(format == 1){ 
    // small field format (8 char par field, 10 per line)
    double_to_char8(x1, xs); double_to_char8(y1, ys); double_to_char8(z1, zs);
    fprintf(fp, "GRID    %-8d%-8d%-8s%-8s%-8s\n", _num, 0, xs, ys, zs);
  }
  else{ 
    // large field format (8 char first/last field, 16 char middle, 6 per line)
    fprintf(fp, "GRID*   %-16d%-16d%-16.9G%-16.9G*N%-6d\n", _num, 0, x1, y1, _num);
    fprintf(fp, "*N%-6d%-16.9G\n", _num, z1);
  }
}

std::set<MVertex*, MVertexLessThanLexicographic>::iterator 
MVertex::linearSearch(std::set<MVertex*, MVertexLessThanLexicographic> &pos)
{
  double tol = MVertexLessThanLexicographic::tolerance;
  for(std::set<MVertex*, MVertexLessThanLexicographic>::iterator it = pos.begin();
      it != pos.end(); ++it){
    if(distance(*it) < tol) return it;
  }
  return pos.end();
}
