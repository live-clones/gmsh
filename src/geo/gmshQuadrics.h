// Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_QUADRICS_H
#define GMSH_QUADRICS_H

#include <vector>
#include <string>
#include "SPoint3.h"
#include "Numeric.h"

class gmshQuadric {
  std::vector<SPoint3> points;

public:
  virtual double distance(const SPoint3 &p) = 0;
  virtual int minNumPoints() = 0;
  virtual void compute(std::vector<SPoint3> &p) = 0;
  virtual std::string name() = 0;
  virtual ~gmshQuadric() {}
  bool addPointIfOk(const SPoint3 &p, double d)
  {
    if(points.size() < minNumPoints()) {
      //      printf("--> adding %g %g %g
      //      %g\n",p.x(),p.y(),p.z(),p.y()*p.y()+p.z()*p.z());
      for(auto pp : points)
        if(pp.distance(p) < 1.e-12) return true;
      points.push_back(p);
      if(points.size() == minNumPoints()) compute(points);
      return true;
    }

    double dist = distance(p);
    //    printf("dist %g d %g name %s\n",dist,d,name().c_str());
    if(dist < d) return true;
    return false;
  }
};

class gmshQuadricPlane : public gmshQuadric {
  mean_plane meanPlane;

public:
  std::string name() { return "Plane"; }
  void compute(std::vector<SPoint3> &p);
  double distance(const SPoint3 &p);
  int minNumPoints() { return 3; }
  ~gmshQuadricPlane() {}
};

class gmshQuadricSphere : public gmshQuadric {
  SPoint3 P;
  double R;

public:
  std::string name() { return "Sphere"; }
  void compute(std::vector<SPoint3> &p);
  double distance(const SPoint3 &p);
  int minNumPoints() { return 4; }
  ~gmshQuadricSphere() {}
};

class gmshQuadricCylinder : public gmshQuadric {
  SVector3 D;
  SPoint3 P;
  double R;

public:
  std::string name() { return "Cylinder"; }
  void compute(std::vector<SPoint3> &p);
  double distance(const SPoint3 &p);
  int minNumPoints() { return 6; }
  ~gmshQuadricCylinder() {}
};

#endif
