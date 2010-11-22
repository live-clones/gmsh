// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <stdlib.h>
#include "Gmsh.h"
#include "GModel.h"
#include "MTriangle.h"
#include "Numeric.h"
#include "Bubbles.h"

StringXNumber BubblesOptions_Number[] = {
  {GMSH_FULLRC, "ShrinkFactor", NULL, 0.},
};

StringXString BubblesOptions_String[] = {
  {GMSH_FULLRC, "OutputFile", NULL, "bubbles.geo"}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterBubblesPlugin()
  {
    return new GMSH_BubblesPlugin();
  }
}

std::string GMSH_BubblesPlugin::getHelp() const
{
  return "Plugin(Bubbles) constructs a geometry consisting of "
    "`bubbles' inscribed in the Voronoi of an input triangulation. "
    "`ShrinkFactor' allows to change the size of the bubbles. "
    "The plugin expects a triangulation in the `z = 0' plane to exist "
    "in the current model.\n\n"
    "Plugin(Bubbles) creates one `.geo' file.";
}

int GMSH_BubblesPlugin::getNbOptions() const
{
  return sizeof(BubblesOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_BubblesPlugin::getOption(int iopt)
{
  return &BubblesOptions_Number[iopt];
}

int GMSH_BubblesPlugin::getNbOptionsStr() const
{
  return sizeof(BubblesOptions_String) / sizeof(StringXString);
}

StringXString *GMSH_BubblesPlugin::getOptionStr(int iopt)
{
  return &BubblesOptions_String[iopt];
}

static double myangle(double c[3], double p[3])
{
  double v[3] = {1, 0, 0};
  double n[3] = {0, 0, 1};
  if(fabs(c[0] - p[0]) < 1e-12 && 
     fabs(c[1] - p[1]) < 1e-12 && 
     fabs(c[2] - p[2]) < 1e-12)
    return 0.;
  return angle_plan(c, v, p, n);
}

class compareAngle{
 private:
  SPoint3 v;
 public:
  compareAngle(SPoint3 vv) : v(vv) {}
  bool operator()(const SPoint3 &b1, const SPoint3 &b2)
  {
    double p1[3] = {b1.x(), b1.y(), b1.z()};
    double p2[3] = {b2.x(), b2.y(), b2.z()};
    double c[3] = {v.x(), v.y(), v.z()};
    double a1 = myangle(c, p1);
    double a2 = myangle(c, p2);
    return a1 < a2;
  }
};

PView *GMSH_BubblesPlugin::execute(PView *v)
{
  double shrink = (double)BubblesOptions_Number[0].def;
  std::string fileName = BubblesOptions_String[0].def;

  FILE *fp = fopen(fileName.c_str(), "w");
  if(!fp){
    Msg::Error("Could not open output file '%s'", fileName.c_str());
    return v;
  }
  
  GModel *m = GModel::current();

  int p = m->getMaxElementaryNumber(0) + 1;
  int l = m->getMaxElementaryNumber(1) + 1;
  int s = m->getMaxElementaryNumber(2) + 1;
  int ll = s, ps = 1;

  SBoundingBox3d bbox = m->bounds();
  double lc = norm(SVector3(bbox.max(), bbox.min())) / 100;
  fprintf(fp, "lc = %g;\n", lc);

  for(GModel::viter vit = m->firstVertex(); vit != m->lastVertex(); vit++)
    (*vit)->writeGEO(fp, "lc");

  for(GModel::eiter eit = m->firstEdge(); eit != m->lastEdge(); eit++)
    (*eit)->writeGEO(fp);

  for(GModel::fiter fit = m->firstFace(); fit != m->lastFace(); fit++){
    (*fit)->writeGEO(fp);
    fprintf(fp, "Delete { Surface {%d}; }\n", (*fit)->tag());

    int sbeg = s;
    int llbeg = ll;

    // compute vertex-to-triangle_barycenter map
    std::map<MVertex*, std::vector<SPoint3> > v2t;
    for(unsigned int i = 0; i < (*fit)->triangles.size(); i++)
      for(int j = 0; j < 3; j++)
        v2t[(*fit)->triangles[i]->getVertex(j)].push_back((*fit)->triangles[i]->barycenter());

    // add boundary vertices in map to get cells "closer" to the boundary
    for(std::map<MVertex*, std::vector<SPoint3> >::iterator it = v2t.begin();
        it != v2t.end(); it++){
      MVertex *v = it->first;
      if(v->onWhat() && v->onWhat()->dim() < 2)
        it->second.push_back(SPoint3(it->first->x(), it->first->y(), it->first->z()));
    }
 
    for(std::map<MVertex*, std::vector<SPoint3> >::iterator it = v2t.begin();
        it != v2t.end(); it++){
      if(it->second.size() > 2){
        // get barycenter of cell boundary points and order them
        SPoint3 bc;
        for(unsigned int i = 0; i < it->second.size(); i++)
          bc += it->second[i];
        bc *= 1. / (double)it->second.size();
        compareAngle comp(bc);
        std::sort(it->second.begin(), it->second.end(), comp);
        // shrink cells
        if(shrink){
          for(unsigned int i = 0; i < it->second.size(); i++){
            double dir[3] = {it->second[i].x() - bc.x(), 
                             it->second[i].y() - bc.y(), 
                             it->second[i].z() - bc.z()};
            it->second[i][0] -= shrink * dir[0];
            it->second[i][1] -= shrink * dir[1];
            it->second[i][2] -= shrink * dir[2];
          }
        }
        // create b-spline bounded surface for each cell
        int nump = it->second.size();
        for(int i = 0; i < nump; i++){
          SPoint3 &b(it->second[i]);
          fprintf(fp, "Point(%d) = {%.16g, %.16g, %.16g, lc};\n", p++, b.x(), b.y(), b.z());
        }
        fprintf(fp, "BSpline(%d) = {", l++);
        for(int i = nump - 1; i >= 0; i--)
          fprintf(fp, "%d,", p - i - 1);
        fprintf(fp, "%d};\n", p - nump);
        fprintf(fp, "Line Loop(%d) = {%d};\n", ll++, l - 1);
        fprintf(fp, "Plane Surface(%d) = {%d};\n", s++, ll - 1);
      }
    }
    fprintf(fp, "Physical Surface(%d) = {%d:%d};\n", ps++, sbeg, s - 1);

    fprintf(fp, "Plane Surface(%d) = {%d, %d:%d};\n", s++, (*fit)->tag(), llbeg, ll - 1);
    fprintf(fp, "Physical Surface(%d) = {%d};\n", ps++, s - 1);
  }

  fclose(fp);

  return v;
}
