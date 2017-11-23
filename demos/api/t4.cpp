// This file reimplements gmsh/tutorial/t4.geo in C++.

#include <math.h>
#include <gmsh.h>

double hypoth(double a, double b){ return sqrt(a * a + b * b); }

int main(int argc, char **argv)
{
  gmshInitialize(argc, argv);
  gmshOptionSetNumber("General.Terminal", 1);

  gmshModelCreate("t4");

  double cm = 1e-02;
  double e1 = 4.5 * cm, e2 = 6 * cm / 2, e3 =  5 * cm / 2;
  double h1 = 5 * cm, h2 = 10 * cm, h3 = 5 * cm, h4 = 2 * cm, h5 = 4.5 * cm;
  double R1 = 1 * cm, R2 = 1.5 * cm, r = 1 * cm;
  double Lc1 = 0.01;
  double Lc2 = 0.003;

  double ccos = (-h5*R1 + e2 * hypot(h5, hypot(e2, R1))) / (h5*h5 + e2*e2);
  double ssin = sqrt(1 - ccos*ccos);

  gmshModelGeoAddPoint(-e1-e2, 0    , 0, Lc1, 1);
  gmshModelGeoAddPoint(-e1-e2, h1   , 0, Lc1, 2);
  gmshModelGeoAddPoint(-e3-r , h1   , 0, Lc2, 3);
  gmshModelGeoAddPoint(-e3-r , h1+r , 0, Lc2, 4);
  gmshModelGeoAddPoint(-e3   , h1+r , 0, Lc2, 5);
  gmshModelGeoAddPoint(-e3   , h1+h2, 0, Lc1, 6);
  gmshModelGeoAddPoint( e3   , h1+h2, 0, Lc1, 7);
  gmshModelGeoAddPoint( e3   , h1+r , 0, Lc2, 8);
  gmshModelGeoAddPoint( e3+r , h1+r , 0, Lc2, 9);
  gmshModelGeoAddPoint( e3+r , h1   , 0, Lc2, 10);
  gmshModelGeoAddPoint( e1+e2, h1   , 0, Lc1, 11);
  gmshModelGeoAddPoint( e1+e2, 0    , 0, Lc1, 12);
  gmshModelGeoAddPoint( e2   , 0    , 0, Lc1, 13);

  gmshModelGeoAddPoint( R1 / ssin, h5+R1*ccos, 0, Lc2, 14);
  gmshModelGeoAddPoint( 0        , h5        , 0, Lc2, 15);
  gmshModelGeoAddPoint(-R1 / ssin, h5+R1*ccos, 0, Lc2, 16);
  gmshModelGeoAddPoint(-e2       , 0.0       , 0, Lc1, 17);

  gmshModelGeoAddPoint(-R2 , h1+h3   , 0, Lc2, 18);
  gmshModelGeoAddPoint(-R2 , h1+h3+h4, 0, Lc2, 19);
  gmshModelGeoAddPoint( 0  , h1+h3+h4, 0, Lc2, 20);
  gmshModelGeoAddPoint( R2 , h1+h3+h4, 0, Lc2, 21);
  gmshModelGeoAddPoint( R2 , h1+h3   , 0, Lc2, 22);
  gmshModelGeoAddPoint( 0  , h1+h3   , 0, Lc2, 23);

  gmshModelGeoAddPoint(0, h1+h3+h4+R2, 0, Lc2, 24);
  gmshModelGeoAddPoint(0, h1+h3-R2,    0, Lc2, 25);

  gmshModelGeoAddLine(1 , 17, 1);
  gmshModelGeoAddLine(17, 16, 2);

  gmshModelGeoAddCircleArc(14,15,16, 3);
  gmshModelGeoAddLine(14,13, 4);
  gmshModelGeoAddLine(13,12, 5);
  gmshModelGeoAddLine(12,11, 6);
  gmshModelGeoAddLine(11,10, 7);
  gmshModelGeoAddCircleArc(8,9,10, 8);
  gmshModelGeoAddLine(8,7, 9);
  gmshModelGeoAddLine(7,6, 10);
  gmshModelGeoAddLine(6,5, 11);
  gmshModelGeoAddCircleArc(3,4,5, 12);
  gmshModelGeoAddLine(3,2, 13);
  gmshModelGeoAddLine(2,1, 14);
  gmshModelGeoAddLine(18,19, 15);
  gmshModelGeoAddCircleArc(21,20,24, 16);
  gmshModelGeoAddCircleArc(24,20,19, 17);
  gmshModelGeoAddCircleArc(18,23,25, 18);
  gmshModelGeoAddCircleArc(25,23,22, 19);
  gmshModelGeoAddLine(21,22, 20);

  gmshModelGeoAddLineLoop({17,-15,18,19,-20,16}, 21);
  gmshModelGeoAddPlaneSurface({21}, 22);
  gmshModelGeoAddLineLoop({11,-12,13,14,1,2,-3,4,5,6,7,-8,9,10}, 23);

  // A surface with one hole is specified using 2 line loops:
  gmshModelGeoAddPlaneSurface({23,21}, 24);

  // FIXME: this will be implemented through the gmshView API
  /*
  View "comments" {
    T2(10, -10, 0){ StrCat("Created on ", Today, " with Gmsh") };
    T3(0, 0.11, 0, TextAttributes("Align", "Center", "Font", "Helvetica")){ "Hole" };
    T3(0, 0.09, 0, TextAttributes("Align", "Center")){ "file://image.png@0.01x0" };
    T3(-0.01, 0.09, 0, 0){ "file://image.png@0.01x0,0,0,1,0,1,0" };
    T3(0, 0.12, 0, TextAttributes("Align", "Center")){ "file://image.png@0.01x0#" };
    T2(350, -7, 0){ "file://image.png@20x0" };
  };
  */

  gmshModelGeoSynchronize();

  gmshModelMesh(2);

  gmshExport("t4.msh");

  gmshFinalize();
  return 0;
}
