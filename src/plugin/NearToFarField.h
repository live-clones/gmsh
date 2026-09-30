// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef NEARTOFARFIELD_H
#define NEARTOFARFIELD_H

#include "Plugin.h"
#include "shapeFunctions.h"
#include "Numeric.h"
#include "PViewOptions.h"
#include "MElement.h"
#include "GModel.h"

class GMSH_NearToFarFieldPlugin : public GMSH_PostPlugin {
public:
  GMSH_NearToFarFieldPlugin();
  std::string getName() const { return "NearToFarField"; }
  std::string getShortHelp() const
  {
    return "Compute Far Field pattern from Near Field on a surface";
  }
  std::string getHelp() const;
  virtual std::string getAuthor() const { return "R. Sabariego, C. Geuzaine"; }
  PView *execute(PView *);

  // an element of the surface: its nodes, and the integral over it of the
  // shape function of each node, which the integrals of fields interpolated
  // at the nodes are sums of
  struct SurfaceElement {
    std::vector<double> x, y, z, w;
  };
  double getFarFieldJin(const std::vector<SurfaceElement> &elems,
                        std::vector<std::vector<double>> &js,
                        std::vector<std::vector<double>> &ms, double k0,
                        double r_far, double theta, double phi);

  double getFarFieldMonk(const std::vector<SurfaceElement> &elems,
                         std::vector<std::vector<double>> &farfieldvector,
                         std::vector<std::vector<double>> &js,
                         std::vector<std::vector<double>> &ms, double k0,
                         double theta, double phi);
};

#endif
