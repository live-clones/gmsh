// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Alexandre Chemin

#pragma once

#include <IffTools.hxx>

namespace IFF{
  namespace visu{
    int framefield(const std::map<Element *, std::vector<std::vector<double>>> &mapElemDir, const std::string & nameView="Frame field", int visible=0);
    int vectorField(const std::map<Element *, std::vector<double>> &mapElemVect, const std::string & nameView="Vector", int visible=0);
    int vectorField(const std::map<Edge *, std::vector<double>> &mapEdgVect, const std::string & nameView="Vector", int visible=0);
    int scalarField(const std::map<Vertex *, double> &mapVertScalar, const std::string & nameView="Scalar", int visible=0);
    int scalarField(const std::map<Edge*, std::vector<double>> &mapEdgScalar, const std::string & nameView="Scalar", int visible=0);
    int scalarField(const std::map<Element*, double> &mapElemScalar, const std::string & nameView="Scalar", int visible=0);
    int scalarFieldOnMesh(const std::map<Element*, std::vector<double>> &mapVertScalar, const std::string & nameView="Scalar", int visible=0);
    int integerPotentialOnMesh(const std::map<Element*, std::vector<double>> &mapVertScalar, const std::string & nameView="Scalar", int visible=0);
  }
}
