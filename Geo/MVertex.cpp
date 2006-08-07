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
