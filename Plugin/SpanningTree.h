// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
// Contributed by Nicolas Marsic.

#ifndef SPANNING_TREE_H
#define SPANNING_TREE_H

#include <list>
#include "Plugin.h"

extern "C" {
GMSH_Plugin *GMSH_RegisterSpanningTreePlugin(void);
}

class GMSH_SpanningTreePlugin : public GMSH_MeshPlugin {
private:
  class DSU { // Disjoint Set Union
              // (https://en.wikipedia.org/wiki/Disjoint-set_data_structure)
              // (https://fr.wikipedia.org/wiki/Union-find)
              // (https://www.cs.auckland.ac.nz/software/AlgAnim/mst.html)
  private:
    std::vector<int> parent;
    std::vector<int> rank;

  public:
    DSU(size_t n);
    ~DSU(void);

    int find(int a);
    void join(int a, int b);

    std::string toString(void);
  };

  struct Sort {
    bool operator()(const std::pair<int, int> &a,
                    const std::pair<int, int> &b) const;
  };

  typedef std::set<const MElement *, MElementPtrLessThan> ElementSet;
  typedef std::set<std::pair<int, int>, Sort> EdgeSet;
  typedef std::list<std::pair<int, int> > Tree;

public:
  GMSH_SpanningTreePlugin(void);

  std::string getName(void) const;
  std::string getShortHelp(void) const;
  std::string getHelp(void) const;
  std::string getAuthor(void) const;

  int getNbOptions(void) const;
  StringXNumber *getOption(int iopt);

  int getNbOptionsStr() const;
  StringXString *getOptionStr(int iopt);

  void run(void);

private:
  static void spanningTree(EdgeSet &edge, DSU &vertex, Tree &tree);

  static std::string parse(std::string str, std::list<int> &physical);
  static void getAllMElement(GModel &model, int physical, int dim,
                             ElementSet &element);
  static void getAllMEdge(ElementSet &element, EdgeSet &edge);
  static void addToModel(GModel &model, Tree &tree, int tag);

  static std::pair<int, int> minmax(const std::pair<int, int> &p);
};

#endif
