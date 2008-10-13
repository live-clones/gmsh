// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <string.h>
#include <math.h>
#include "MVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "Message.h"
#include "StringUtils.h"

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
  if(_index < 0) return; // negative index vertices are never saved

  if(!binary){
    fprintf(fp, "%d %.16g %.16g %.16g\n", _index, 
            x() * scalingFactor, 
            y() * scalingFactor,
            z() * scalingFactor);
  }
  else{
    fwrite(&_index, sizeof(int), 1, fp);
    double data[3] = {x() * scalingFactor, y() * scalingFactor, z() * scalingFactor};
    fwrite(data, sizeof(double), 3, fp);
  }
}

void MVertex::writeVRML(FILE *fp, double scalingFactor)
{
  if(_index < 0) return; // negative index vertices are never saved

  fprintf(fp, "%.16g %.16g %.16g,\n",
          x() * scalingFactor, y() * scalingFactor, z() * scalingFactor);
}

void MVertex::writeUNV(FILE *fp, double scalingFactor)
{
  if(_index < 0) return; // negative index vertices are never saved

  int coord_sys = 1;
  int displacement_coord_sys = 1;
  int color = 11;
  fprintf(fp, "%10d%10d%10d%10d\n", _index, coord_sys, displacement_coord_sys, color);
  // hack to print the numbers with "D+XX" exponents
  char tmp[128];
  sprintf(tmp, "%25.16E%25.16E%25.16E\n", x() * scalingFactor, 
          y() * scalingFactor, z() * scalingFactor);
  for(unsigned int i = 0; i < strlen(tmp); i++) if(tmp[i] == 'E') tmp[i] = 'D';
  fprintf(fp, tmp);
}

void MVertex::writeVTK(FILE *fp, bool binary, double scalingFactor, bool bigEndian)
{
  if(_index < 0) return; // negative index vertices are never saved

  if(binary){
    double data[3] = {x() * scalingFactor, y() * scalingFactor, z() * scalingFactor};
    // VTK always expects big endian binary data
    if(!bigEndian) SwapBytes((char*)data, sizeof(double), 3);
    fwrite(data, sizeof(double), 3, fp);
  }
  else{
    fprintf(fp, "%.16g %.16g %.16g\n",
	    x() * scalingFactor, y() * scalingFactor, z() * scalingFactor);
  }
}

void MVertex::writeMESH(FILE *fp, double scalingFactor)
{
  if(_index < 0) return; // negative index vertices are never saved

  fprintf(fp, " %20.14G      %20.14G      %20.14G      %d\n", 
          x() * scalingFactor, y() * scalingFactor, z() * scalingFactor, 0);
}

static void double_to_char8(double val, char *str)
{
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

#if defined(WIN32)
  // Windows uses 3 digits in the exponent (which apparently does not
  // conform with ANSI C): remove the extra 0
  if(strlen(str) == 9 && (str[4] == 'E' || str[5] == 'E')){
    str[6] = str[7];
    str[7] = str[8];
  }
#endif

  str[8] = '\0';
}

void MVertex::writeBDF(FILE *fp, int format, double scalingFactor)
{
  if(_index < 0) return; // negative index vertices are never saved

  char xs[17], ys[17], zs[17];
  double x1 = x() * scalingFactor;
  double y1 = y() * scalingFactor;
  double z1 = z() * scalingFactor;
  if(format == 0){
    // free field format (max 8 char per field, comma separated, 10 per line)
    double_to_char8(x1, xs); double_to_char8(y1, ys); double_to_char8(z1, zs);
    fprintf(fp, "GRID,%d,%d,%s,%s,%s\n", _index, 0, xs, ys, zs);
  }
  else if(format == 1){ 
    // small field format (8 char par field, 10 per line)
    double_to_char8(x1, xs); double_to_char8(y1, ys); double_to_char8(z1, zs);
    fprintf(fp, "GRID    %-8d%-8d%-8s%-8s%-8s\n", _index, 0, xs, ys, zs);
  }
  else{ 
    // large field format (8 char first/last field, 16 char middle, 6 per line)
    fprintf(fp, "GRID*   %-16d%-16d%-16.9G%-16.9G*N%-6d\n", _index, 0, x1, y1, _index);
    fprintf(fp, "*N%-6d%-16.9G\n", _index, z1);
  }
}

void MVertex::writeDIFF(FILE *fp, bool binary, double scalingFactor)
{
  if(_index < 0) return; // negative index vertices are never saved

  fprintf(fp, " %d ( %25.16E , %25.16E , %25.16E )\n",
          getIndex(), x() * scalingFactor, y() * scalingFactor, z() * scalingFactor);
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

void parametricCoordinates(const MVertex *ver, const GFace *gf, double &u, double &v)
{
  GEntity *ge = ver->onWhat();
  if(ge->dim() == 2){
    ver->getParameter(0, u);
    ver->getParameter(1, v);      
  }
  else if(ge->dim() == 1){
    double t;
    ver->getParameter(0, t);
    GEdge *ged = dynamic_cast<GEdge*>(ge);
    SPoint2 p = ged->reparamOnFace((GFace*)gf, t, 1);
    u = p.x();
    v = p.y();
  }
  else{
    GVertex *gver = dynamic_cast<GVertex*>(ge);
    SPoint2 p = gver->reparamOnFace((GFace*)gf, 1);
    u = p.x();
    v = p.y();
  }      
}
