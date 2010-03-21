// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   David Colignon
//

// This is a simple AutoCAD DXF to Gmsh GEO Data File Converter
//   
// It was created from the AutoCAD DXF file to DKB data file converter
// written and placed in the public domain 8/13/90 by Aaron
// A. Collins (http://www.sdsc.edu/~mjb/mae152/dxf.spec.txt).
//   
// It parses a limited, but useful, subset of the AutoCAD DXF file
// format. No effort has been made to handle the complete range of
// possible DXF opcodes and commands.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <set>

#define DEG2RAD    3.14159265359/180.
#define BUFSIZE    2048
#define GEOLINE    1
#define GEOCIRCLE  2
#define GEOTRI     3
#define GEOQUAD    4

FILE *infile, *outfile;
char inname[80], outname[80], curobj[80], linbuf[BUFSIZE];
long primitives = 0L, degenerates = 0L;
int groupcode, curcolor, ints[10], nump = 1, numc = 1;
int cpt_vert_node = 1, num_vert_node[1024];
float curthick, xcoords[10], ycoords[10], zcoords[10], floats[10], angles[10];
float max_x, max_y, max_z, min_x, min_y, min_z;
float THETOL, THEROT = 0., THETRANSX = 0., THETRANSY = 0.;

class Point
{
 public:
  int num;
  float x, y, z;
  void write() const
  {
    float xx = x;
    float yy = y;
    xx = cos(-THEROT * DEG2RAD) * x + sin(-THEROT * DEG2RAD) * y;
    yy = -sin(-THEROT * DEG2RAD) * x + cos(-THEROT * DEG2RAD) * y;
    xx += THETRANSX;
    yy += THETRANSY;
    fprintf(outfile, "Point (%d) = {%g *u, %g *u, %g *u, lc} ;\n",
            num, xx, yy, z);
  }
};

class PointLessThanLexicographic{
 public:
  bool operator()(const Point &v1, const Point &v2) const
  {
    if(v1.x - v2.x >  THETOL) return true;
    if(v1.x - v2.x < -THETOL) return false;
    if(v1.y - v2.y >  THETOL) return true;
    if(v1.y - v2.y < -THETOL) return false;
    if(v1.z - v2.z >  THETOL) return true;
    return false;
  }
};

class Curve
{
 public:
  int num, type, a, b, c;
  void write() const
  {
    switch (type) {
    case GEOLINE:
      fprintf(outfile, "Line (%d) = {%d, %d} ;\n", num, a, b);
      break;
    case GEOCIRCLE:
      fprintf(outfile, "Circle (%d) = {%d, %d, %d} ;\n",
              num, a, b, c);
      break;
    }
  }
};

class CurveLessThan{
 public:
  bool operator()(const Curve &c1, const Curve &c2) const
  {
    if(c1.num < c2.num) return true;
    return false;
  }
};

std::set<Point, PointLessThanLexicographic> Point_T;
std::set<Curve, CurveLessThan> Curve_T;

int addpoint(Point &p)
{
  std::set<Point>::iterator it = Point_T.find(p);
  if(it != Point_T.end())
    return it->num;
  p.num = nump++;
  Point_T.insert(p);
  return p.num;
}

void addcurve(Curve &c)
{
  c.num = numc++;
  Curve_T.insert(c);
}

int checkdegen(int a, int b, int c)
{       /* check for degenerate triangle structure */
  if((xcoords[a] == xcoords[b] &&
      ycoords[a] == ycoords[b] &&
      zcoords[a] == zcoords[b]) ||
     (xcoords[b] == xcoords[c] &&
      ycoords[b] == ycoords[c] &&
      zcoords[b] == zcoords[c]) ||
     (xcoords[a] == xcoords[c] &&
      ycoords[a] == ycoords[c] && 
      zcoords[a] == zcoords[c]))
    return (1);
  return (0);
}

void addobj(void)
{       /* dump out current object we should have all info on */
  Point p;
  Curve c;
  int num[10];

  if(strstr(curobj, "POINT")) {
    p.x = xcoords[0];
    p.y = ycoords[0];
    p.z = zcoords[0];
    addpoint(p);
  }
  else if(strstr(curobj, "LINE") || strstr(curobj, "3DLINE")) {
    if(xcoords[0] == xcoords[1] && ycoords[0] == ycoords[1]
       && zcoords[0] == zcoords[1]) {
      degenerates++;
      return;
    }
    p.x = xcoords[0];
    p.y = ycoords[0];
    p.z = zcoords[0];
    num[0] = addpoint(p);
    p.x = xcoords[1];
    p.y = ycoords[1];
    p.z = zcoords[1];
    num[1] = addpoint(p);
    c.type = GEOLINE;
    c.a = num[0];
    c.b = num[1];
    addcurve(c);
  }
  else if(strstr(curobj, "CIRCLE")) {
    p.x = xcoords[0];
    p.y = ycoords[0];
    p.z = zcoords[0];
    num[0] = addpoint(p);
    p.x = xcoords[0] - floats[0];
    p.y = ycoords[0];
    p.z = zcoords[0];
    num[1] = addpoint(p);
    p.x = xcoords[0] + floats[0];
    p.y = ycoords[0];
    p.z = zcoords[0];
    num[2] = addpoint(p);
    p.x = xcoords[0];
    p.y = ycoords[0] - floats[0];
    p.z = zcoords[0];
    num[3] = addpoint(p);
    p.x = xcoords[0];
    p.y = ycoords[0] + floats[0];
    p.z = zcoords[0];
    num[4] = addpoint(p);
    c.type = GEOCIRCLE;
    c.a = num[2];
    c.b = num[0];
    c.c = num[4];
    addcurve(c);
    c.type = GEOCIRCLE;
    c.a = num[4];
    c.b = num[0];
    c.c = num[1];
    addcurve(c);
    c.type = GEOCIRCLE;
    c.a = num[1];
    c.b = num[0];
    c.c = num[3];
    addcurve(c);
    c.type = GEOCIRCLE;
    c.a = num[3];
    c.b = num[0];
    c.c = num[2];
    addcurve(c);
  }
  else if(strstr(curobj, "ARC")) {
    p.x = xcoords[0];
    p.y = ycoords[0];
    p.z = zcoords[0];
    num[0] = addpoint(p);

    p.x = xcoords[0] + floats[0] * cos(angles[0] * DEG2RAD);
    p.y = ycoords[0] + floats[0] * sin(angles[0] * DEG2RAD);
    p.z = zcoords[0];
    num[1] = addpoint(p);

    p.x = xcoords[0] + floats[0] * cos(angles[1] * DEG2RAD);
    p.y = ycoords[0] + floats[0] * sin(angles[1] * DEG2RAD);
    p.z = zcoords[0];
    num[2] = addpoint(p);

    if((angles[1] - angles[0] > 0 && angles[1] - angles[0] < 180) ||
       (angles[1] - angles[0] < 0 && angles[1] - angles[0] < -180)) {
      c.type = GEOCIRCLE;
      c.a = num[1];
      c.b = num[0];
      c.c = num[2];
      addcurve(c);
    }
    else {
      if(angles[1] - angles[0] > 0) {
        p.x =
          xcoords[0] +
          floats[0] * cos((angles[1] - angles[0]) * 0.5 * DEG2RAD);
        p.y =
          ycoords[0] +
          floats[0] * sin((angles[1] - angles[0]) * 0.5 * DEG2RAD);
      }
      else {
        p.x =
          xcoords[0] +
          floats[0] * cos((angles[0] - angles[1]) * 0.5 * DEG2RAD);
        p.y =
          ycoords[0] +
          floats[0] * sin((angles[0] - angles[1]) * 0.5 * DEG2RAD);
      }
      p.z = zcoords[0];
      num[3] = addpoint(p);
      c.type = GEOCIRCLE;
      c.a = num[1];
      c.b = num[0];
      c.c = num[3];
      addcurve(c);
      c.type = GEOCIRCLE;
      c.a = num[3];
      c.b = num[0];
      c.c = num[2];
      addcurve(c);
    }
  }
  else if(strstr(curobj, "TRACE")) {    /* 2 back-to-back triangles */
    if(checkdegen(0, 1, 2)) {
      degenerates++;
      return;
    }
    /* add triangle 0, 1, 2 */

    if(checkdegen(0, 3, 2)) {
      degenerates++;
      return;
    }
    /* add triangle 0 3 2 */
  }
  else if(strstr(curobj, "SOLID")) {    /* 1 or 2 triangles */
    if(checkdegen(0, 1, 2)) {
      degenerates++;
      return;
    }
    /* add triangle 0, 1, 2 */

    if(xcoords[2] == xcoords[3] && ycoords[2] == ycoords[3]
       && zcoords[2] == zcoords[3])
      return;   /* one triangle was enough... */

    if(checkdegen(0, 3, 2)) {
      degenerates++;
      return;
    }
    /* add triangle 0 3 2 */
  }
  else if(strstr(curobj, "TEXT")) {     /* not implemented for now */
  }
  else if(strstr(curobj, "SHAPE")) {    /* these look very hard */
  }
  else if(strstr(curobj, "BLOCK")) {    /* these look very hard */
  }
  else if(strstr(curobj, "ENDBLK")) {   /* these look very hard */
  }
  else if(strstr(curobj, "INSERT")) {   /* these look very hard */
  }
  else if(strstr(curobj, "ATTDEF")) {   /* not implemented for now */
  }
  else if(strstr(curobj, "ATTRIB")) {   /* not implemented for now */
  }
  else if(strstr(curobj, "POLYLINE")) { /* these look fairly hard */
  }
  else if(strstr(curobj, "VERTEX")) {   /* these look fairly hard */
    if(ints[0] == 192) {
      p.x = xcoords[0];
      p.y = ycoords[0];
      p.z = zcoords[0];
      num_vert_node[cpt_vert_node] = addpoint(p);
      cpt_vert_node++;
    }
    else if(ints[0] == 128) {
      c.type = GEOLINE;
      c.a = num_vert_node[ints[1]];
      c.b = num_vert_node[ints[2]];
      addcurve(c);
      c.type = GEOLINE;
      c.a = num_vert_node[ints[2]];
      c.b = num_vert_node[ints[3]];
      addcurve(c);
      if(ints[4] == 0) {
        c.type = GEOLINE;
        c.a = num_vert_node[ints[3]];
        c.b = num_vert_node[ints[1]];
        addcurve(c);
      }
      else {
        c.type = GEOLINE;
        c.a = num_vert_node[ints[3]];
        c.b = num_vert_node[ints[4]];
        addcurve(c);
        c.type = GEOLINE;
        c.a = num_vert_node[ints[4]];
        c.b = num_vert_node[ints[1]];
        addcurve(c);
      }
    }
    ints[0] = ints[1] = ints[2] = ints[3] = ints[4] = ints[5] = 0;
  }
  else if(strstr(curobj, "SEQEND")) {   /* these look fairly hard */
  }
  else if(strstr(curobj, "3DFACE")) {   /* 1 or 2 triangles */
#if 0   //removed by David Colignon
    if(checkdegen(0, 1, 2)) {
      degenerates++;
      return;
    }
    /* add triangle 0 1 2 */

    if(xcoords[2] == xcoords[3] && ycoords[2] == ycoords[3]
       && zcoords[2] == zcoords[3])
      return;   /* one triangle was enough... */

    if(checkdegen(0, 3, 2)) {
      degenerates++;
      return;
    }
    /* add triangle 0 3 2 */
#else
    p.x = xcoords[0];
    p.y = ycoords[0];
    p.z = zcoords[0];
    num[0] = addpoint(p);
    p.x = xcoords[1];
    p.y = ycoords[1];
    p.z = zcoords[1];
    num[1] = addpoint(p);
    p.x = xcoords[2];
    p.y = ycoords[2];
    p.z = zcoords[2];
    num[2] = addpoint(p);
    c.type = GEOLINE;
    c.a = num[0];
    c.b = num[1];
    addcurve(c);
    c.type = GEOLINE;
    c.a = num[1];
    c.b = num[2];
    addcurve(c);
    if(xcoords[3] == xcoords[2] &&
       ycoords[3] == ycoords[2] &&
       zcoords[3] == zcoords[2]) {
      c.type = GEOLINE;
      c.a = num[2];
      c.b = num[0];
      addcurve(c);
    }
    else {
      p.x = xcoords[3];
      p.y = ycoords[3];
      p.z = zcoords[3];
      num[3] = addpoint(p);
      c.type = GEOLINE;
      c.a = num[2];
      c.b = num[3];
      addcurve(c);
      c.type = GEOLINE;
      c.a = num[3];
      c.b = num[0];
      addcurve(c);
    }
#endif
  }
  else if(strstr(curobj, "DIMENSION")) {        /* not implemented for now */
  }

}

int getline(void)
{       /* read a group code and the next line from infile */
  fgets(linbuf, BUFSIZE, infile);       /* get a line from .DXF */
  if(feof(infile))
    return (1);
  sscanf(linbuf, "%3d", &groupcode);    /* scan out group code */
  fgets(linbuf, BUFSIZE, infile);       /* get a line from .DXF */
  if(feof(infile))
    return (1);
  return (0);
}

int main(int argc, char *argv[])
{
  char *index;

  printf("dxf2geo, a 2D AutoCad DXF to Gmsh GEO file translator\n");
  if(argc < 3) {
    printf("Usage: %s file[.dxf] tolerance [rotation] [xoffset] [yoffset]\n",
           argv[0]);
    exit(1);
  }

  THETOL = atof(argv[2]);
  if(argc > 3)
    THEROT = atof(argv[3]);
  if(argc > 4)
    THETRANSX = atof(argv[4]);
  if(argc > 5)
    THETRANSY = atof(argv[5]);

  strcpy(inname, argv[1]);      /* make copy we can mess with */
  if(!strchr(inname, '.'))      /* no dot present in filename? */
    strcat(inname, ".dxf");
  if(!(infile = fopen(inname, "r"))) {
    printf("Cannot open input file %s\n", inname);
    exit(1);
  }
  strcpy(outname, inname);
  index = strchr(outname, '.'); /* find the dot */
  strcpy(index, ".geo");        /* make new ext. .geo... */

  if(!(outfile = fopen(outname, "w"))) {
    printf("Cannot create output file %s\n", outname);
    fclose(infile);
    exit(1);
  }

  ints[0] = ints[1] = ints[2] = ints[3] = ints[4] = ints[5] = 0;
  curobj[0] = '\0';     /* not working on any object currently */
  curcolor = 7; /* and it also doesn't have a color yet... */
  max_x = max_y = max_z = -10000000.0;  /* init bounding limits */
  min_x = min_y = min_z = 10000000.0;

find:
  while(!feof(infile)) {        /* run file up to the "ENTITIES" section */
    if(getline())
      goto stopit;
    if(groupcode == 0) {        /* file section mark */
      if(strstr(linbuf, "EOF"))
        goto stopit;
      if(strstr(linbuf, "SECTION")) {
        if(getline())
          goto stopit;
        if(groupcode != 2)
          continue;
        if(strstr(linbuf, "ENTITIES"))
          break;
      }
    }
  }

  while(!feof(infile)) {        /* scan ENTITIES section */
    if(getline())       /* get a group code and a line */
      break;
    if(groupcode < 10) {        /* cardinal group codes */
      switch (groupcode) {
      case 0:  /* start of entity, table, file sep */
        if(strstr(linbuf, "EOF")) {
          addobj();     /* dump object */
          goto stopit;
        }
        if(strstr(linbuf, "ENDSEC")) {
          addobj();     /* dump object */
          goto find;
        }
        addobj();       /* dump old object */
        curobj[0] = '\0';       /* reset object */
        curcolor = 7;
        strcpy(curobj, linbuf); /* get new */
        break;
      case 1:  /* primary text value for entity (?) */
        break;
      case 2:  /* block name, attribute tag, etc */
      case 3:  /* other names */
      case 4:
        break;
      case 5:  /* entity handle (hex string) */
        break;
      case 6:  /* line type name */
        break;
      case 7:  /* text style name */
        break;
      case 8:  /* layer name */
        break;
      case 9:  /* variable name ID (only in header) */
        break;
      }
    }
    else if(groupcode >= 10 && groupcode < 19) {        /* Some X coord */
      sscanf(linbuf, "%f", &(xcoords[groupcode - 10]));
      if(xcoords[groupcode - 10] > max_x)
        max_x = xcoords[groupcode - 10];
      if(xcoords[groupcode - 10] < min_x)
        min_x = xcoords[groupcode - 10];
    }
    else if(groupcode >= 20 && groupcode < 29) {        /* Some Y coord */
      sscanf(linbuf, "%f", &(ycoords[groupcode - 20]));
      if(ycoords[groupcode - 20] > max_y)
        max_y = ycoords[groupcode - 20];
      if(ycoords[groupcode - 20] < min_y)
        min_y = ycoords[groupcode - 20];
    }
    else if(groupcode >= 30 && groupcode < 38) {        /* Some Z coord */
      sscanf(linbuf, "%f", &(zcoords[groupcode - 30]));
      if(zcoords[groupcode - 30] > max_z)
        max_z = zcoords[groupcode - 30];
      if(zcoords[groupcode - 30] < min_z)
        min_z = zcoords[groupcode - 30];
    }
    else if(groupcode == 38) {  /* entity elevation if nonzero */
    }
    else if(groupcode == 39) {  /* entity thickness if nonzero */
    }
    else if(groupcode >= 40 && groupcode < 49) {        /* misc floats */
      sscanf(linbuf, "%f", &(floats[groupcode - 40]));
    }
    else if(groupcode == 49) {  /* repeated value groups */
    }
    else if(groupcode >= 50 && groupcode < 59) {        /* misc angles */
      sscanf(linbuf, "%f", &(angles[groupcode - 50]));
    }
    else if(groupcode == 62) {  /* Color number */
      sscanf(linbuf, "%6d", &curcolor);
    }
    else if(groupcode == 66) {  /* "entities follow" flag */
    }
    else if(groupcode >= 70 && groupcode < 79) {        /* misc ints */
      sscanf(linbuf, "%d", &(ints[groupcode - 70]));
    }
    else if(groupcode == 210 || groupcode == 220 || groupcode == 230) {
      /* X, Y, Z components of extrusion direction */
    }
  }

stopit:
  fclose(infile);
  fprintf(outfile, "/* Converted from AutoCad DXF file: %s */\n", inname);
  fprintf(outfile, "/* Tolerance %g: %d points / %d curves */\n\n",
          THETOL, Point_T.size(), Curve_T.size());
  fprintf(outfile, "u = 1; \nlc = 1 ;\n\n");

  for(std::set<Point>::iterator it = Point_T.begin(); it != Point_T.end(); ++it)
    it->write();
  fprintf(outfile, "\n");

  for(std::set<Curve>::iterator it = Curve_T.begin(); it != Curve_T.end(); ++it)
    it->write();
  fprintf(outfile, "\n");

  fflush(outfile);
  fclose(outfile);
  printf("bounding box [%g,%g] [%g,%g] [%g,%g]\n",
         min_x, max_x, min_y, max_y, min_z, max_z);
  printf("tolerance %g: %d points / %d curves / %ld degenerate entities removed\n",
         THETOL, Point_T.size(), Curve_T.size(), degenerates);
  exit(0);
}
