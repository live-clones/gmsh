#include <math.h>
#include "MElement.h"
#include "GEntity.h"

int MElement::_globalNum = 0;

static double dist(MVertex *v1, MVertex *v2)
{
  double dx = v1->x() - v2->x();
  double dy = v1->y() - v2->y();
  double dz = v1->z() - v2->z();
  return sqrt(dx * dx + dy * dy + dz * dz);
}

double MElement::minEdge()
{
  double m = 1.e25;
  MVertex *v[2];
  for(int i = 0; i < getNumEdges(); i++){
    getEdge(i, v);
    m = std::min(m, dist(v[0], v[1]));
  }
  return m;
}

double MElement::maxEdge()
{
  double m = 0.;
  MVertex *v[2];
  for(int i = 0; i < getNumEdges(); i++){
    getEdge(i, v);
    m = std::max(m, dist(v[0], v[1]));
  }
  return m;
}

double MElement::rhoShapeMeasure()
{
  double min = minEdge();
  double max = maxEdge();
  if(max)
    return min / max;
  else
    return 0.;
}

void MElement::cog(double &x, double &y, double &z)
{
  x = y = z = 0.;
  int n = getNumVertices();
  for(int i = 0; i < n; i++) {
    MVertex *v = getVertex(i);
    x += v->x();
    y += v->y();
    z += v->z();
  }
  x /= (double)n;
  y /= (double)n;
  z /= (double)n;
}

void MElement::writeMSH(FILE *fp, double version, int num, int elementary, 
			int physical)
{
  int n = getNumVertices();

  fprintf(fp, "%d %d", num ? num : _num, getTypeForMSH());
  if(version < 2.0)
    fprintf(fp, " %d %d %d", physical, elementary, n);
  else
    fprintf(fp, " 3 %d %d %d", physical, elementary, _partition);
  for(int i = 0; i < n; i++){
    fprintf(fp, " %d", getVertex(i)->getNum());
  }
  fprintf(fp, " \n");
}

void MElement::writePOS(FILE *fp)
{
  int n = getNumVertices();
  double gamma = gammaShapeMeasure();
  double eta = etaShapeMeasure();
  double rho = rhoShapeMeasure();

  fprintf(fp, "%s(", getStringForPOS());
  for(int i = 0; i < n; i++){
    if(i) fprintf(fp, ",");
    fprintf(fp, "%g,%g,%g", getVertex(i)->x(), getVertex(i)->y(), getVertex(i)->z());
  }
  fprintf(fp, "){");
  for(int i = 0; i < n; i++)
    fprintf(fp, "%d,", getVertex(i)->onWhat()->tag());
  for(int i = 0; i < n; i++)
    fprintf(fp, "%d,", getNum());
  for(int i = 0; i < n; i++)
    fprintf(fp, "%g,", gamma);
  for(int i = 0; i < n; i++)
    fprintf(fp, "%g,", eta);
  for(int i = 0; i < n; i++){
    if(i == n - 1)
      fprintf(fp, "%g", rho);
    else
      fprintf(fp, "%g,", rho);
  }
  fprintf(fp, "};\n");
}

