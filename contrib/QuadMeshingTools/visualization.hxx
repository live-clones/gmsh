#ifndef CFMB_VISUALIZATION_H
#define CFMB_VISUALIZATION_H

#include <gmsh.h>
#include "mesh.hxx"

namespace IFF{
  namespace visu{
    void scalarfield(const std::map<Vertex *, double> &solution, const std::string & nameView="Scalar", int visible=0);
    void scalarfield(const std::map<Triangle *, double> &solution, const std::string & nameView="Scalar", int visible=0);
    void scalarfield(const std::map<Triangle *, std::vector<double>> &solution, const std::string & nameView, int visible=0);
    void scalarfield(const std::map<Vertex *, std::vector<double>> &solutionGiven, const std::string & nameView="Scalar", int visible=0);
    void vectorfield(const std::map<Vertex *, std::vector<double>> &solutionGiven, const std::string & nameView="Vector", int visible=0);
    void scalarfieldIsoValues(const std::map<Triangle *, std::vector<double>> &solution, const std::string & nameView, size_t nbIso=10, int visible=0);
    void vectorfield(const std::map<Triangle *, std::vector<double>> &solutionGiven, const std::string & nameView="Vector", int visible=0);
    void crossfield(const std::map<Vertex *, std::vector<std::vector<double>>> &mapVertDir, const std::string & nameView="Branch", int visible=0);
    void edges(const std::vector<Edge*> &edges, const std::string & nameView="Edges", int visible=0);
  }
}
#endif
