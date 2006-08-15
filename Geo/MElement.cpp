#include <math.h>
#include "MElement.h"
#include "GEntity.h"
#include "Numeric.h"

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
  for(int i = 0; i < getNumEdges(); i++){
    MEdge e = getEdge(i);
    m = std::min(m, dist(e.getVertex(0), e.getVertex(1)));
  }
  return m;
}

double MElement::maxEdge()
{
  double m = 0.;
  for(int i = 0; i < getNumEdges(); i++){
    MEdge e = getEdge(i);
    m = std::max(m, dist(e.getVertex(0), e.getVertex(1)));
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

double MTetrahedron::gammaShapeMeasure()
{
  double p0[3] = { _v[0]->x(), _v[0]->y(), _v[0]->z() };
  double p1[3] = { _v[1]->x(), _v[1]->y(), _v[1]->z() };
  double p2[3] = { _v[2]->x(), _v[2]->y(), _v[2]->z() };
  double p3[3] = { _v[3]->x(), _v[3]->y(), _v[3]->z() };
  double s1 = fabs(triangle_area(p0, p1, p2));
  double s2 = fabs(triangle_area(p0, p2, p3));
  double s3 = fabs(triangle_area(p0, p1, p3));
  double s4 = fabs(triangle_area(p1, p2, p3));
  double rhoin = 3. * fabs(getVolume()) / (s1 + s2 + s3 + s4);
  return 12. * rhoin / (sqrt(6.) * maxEdge());
}

double MTetrahedron::etaShapeMeasure()
{
  double lij2 = 0.;
  for(int i = 0; i <= 3; i++) {
    for(int j = i + 1; j <= 3; j++) {
      double lij = dist(_v[i], _v[j]);
      lij2 += lij * lij;
    }
  }
  double v = fabs(getVolume());
  return 12. * pow(0.9 * v * v, 1./3.) / lij2;
}

SPoint3 MElement::barycenter()
{
  SPoint3 p(0., 0., 0.);
  int n = getNumVertices();
  for(int i = 0; i < n; i++) {
    MVertex *v = getVertex(i);
    p[0] += v->x();
    p[1] += v->y();
    p[2] += v->z();
  }
  p[0] /= (double)n;
  p[1] /= (double)n;
  p[2] /= (double)n;
  return p;
}

void MElement::writeMSH(FILE *fp, double version, int num, int elementary, 
			int physical)
{
  // if necessary, change the ordering of the vertices to get positive
  // volume
  setVolumePositive();

  int n = getNumVertices();
  int type = getTypeForMSH();

  fprintf(fp, "%d %d", num ? num : _num, type);
  if(version < 2.0)
    fprintf(fp, " %d %d %d", physical, elementary, n);
  else
    fprintf(fp, " 3 %d %d %d", physical, elementary, _partition);
  
  if(physical >= 0){
    for(int i = 0; i < n; i++)
      fprintf(fp, " %d", getVertex(i)->getNum());
  }
  else{
    int nn = n - getNumEdgeVertices() - getNumFaceVertices() - getNumVolumeVertices();
    for(int i = 0; i < nn; i++)
      fprintf(fp, " %d", getVertex(nn - i - 1)->getNum());
    int ne = getNumEdgeVertices();
    for(int i = 0; i < ne; i++)
      fprintf(fp, " %d", getVertex(nn + ne - i - 1)->getNum());
    int nf = getNumFaceVertices();
    for(int i = 0; i < nf; i++)
      fprintf(fp, " %d", getVertex(nn + ne + nf - i - 1)->getNum());
    int nv = getNumVolumeVertices();
    for(int i = 0; i < nv; i++)
      fprintf(fp, " %d", getVertex(n - i - 1)->getNum());
  }

  fprintf(fp, "\n");
}

void MElement::writePOS(FILE *fp, double scalingFactor, int elementary)
{
  int n = getNumVertices();
  double gamma = gammaShapeMeasure();
  double eta = etaShapeMeasure();
  double rho = rhoShapeMeasure();

  fprintf(fp, "%s(", getStringForPOS());
  for(int i = 0; i < n; i++){
    if(i) fprintf(fp, ",");
    fprintf(fp, "%g,%g,%g", getVertex(i)->x() * scalingFactor, 
	    getVertex(i)->y() * scalingFactor, getVertex(i)->z() * scalingFactor);
  }
  fprintf(fp, "){");
  for(int i = 0; i < n; i++)
    fprintf(fp, "%d,", elementary);
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

void MElement::writeSTL(FILE *fp, double scalingFactor)
{
  int n = getNumVertices();
  if(n < 3 || n > 4) return;

  MVertex *v0 = getVertex(0);
  MVertex *v1 = getVertex(1);
  MVertex *v2 = getVertex(2);
  double N[3];
  normal3points(v0->x(), v0->y(), v0->z(), 
		v1->x(), v1->y(), v1->z(), 
		v2->x(), v2->y(), v2->z(), N);
  fprintf(fp, "facet normal %g %g %g\n", N[0], N[1], N[2]);
  fprintf(fp, "  outer loop\n");
  fprintf(fp, "    vertex %g %g %g\n", v0->x() * scalingFactor, 
	  v0->y() * scalingFactor, v0->z() * scalingFactor);
  fprintf(fp, "    vertex %g %g %g\n", v1->x() * scalingFactor, 
	  v1->y() * scalingFactor, v1->z() * scalingFactor);
  fprintf(fp, "    vertex %g %g %g\n", v2->x() * scalingFactor, 
	  v2->y() * scalingFactor, v2->z() * scalingFactor);
  fprintf(fp, "  endloop\n");
  fprintf(fp, "endfacet\n");
  if(n == 4){
    MVertex *v3 = getVertex(3);
    fprintf(fp, "facet normal %g %g %g\n", N[0], N[1], N[2]);
    fprintf(fp, "  outer loop\n");
    fprintf(fp, "    vertex %g %g %g\n", v0->x() * scalingFactor, 
	    v0->y() * scalingFactor, v0->z() * scalingFactor);
    fprintf(fp, "    vertex %g %g %g\n", v2->x() * scalingFactor, 
	    v2->y() * scalingFactor, v2->z() * scalingFactor);
    fprintf(fp, "    vertex %g %g %g\n", v3->x() * scalingFactor, 
	    v3->y() * scalingFactor, v3->z() * scalingFactor);
    fprintf(fp, "  endloop\n");
    fprintf(fp, "endfacet\n");
  }
}

void MElement::writeVRML(FILE *fp)
{
  for(int i = 0; i < getNumVertices(); i++)
    fprintf(fp, "%d,", getVertex(i)->getNum() - 1);
  fprintf(fp, "-1,\n");
}

void MElement::writeUNV(FILE *fp, int elementary)
{
  // if necessary, change the ordering of the vertices to get positive
  // volume
  setVolumePositive();

  int n = getNumVertices();
  int type = getTypeForUNV();

  fprintf(fp, "%10d%10d%10d%10d%10d%10d\n",
	  _num, type, elementary, elementary, 7, n);
  if(type == 21 || type == 24) // BEAM or BEAM2
    fprintf(fp, "%10d%10d%10d\n", 0, 0, 0);
  for(int k = 0; k < n; k++) {
    fprintf(fp, "%10d", getVertex(k)->getNum());
    if(k % 8 == 7)
      fprintf(fp, "\n");
  }
  if(n - 1 % 8 != 7)
    fprintf(fp, "\n");
}

void MElement::writeMESH(FILE *fp, int elementary)
{
  for(int i = 0; i < getNumVertices(); i++)
    fprintf(fp, " %d", getVertex(i)->getNum());
  fprintf(fp, " %d\n", elementary);
}
