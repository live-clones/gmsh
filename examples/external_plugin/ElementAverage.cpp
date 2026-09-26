// A plugin built as a shared library, which Gmsh loads when it starts if the
// library is in a directory listed in the GMSHPLUGINSHOME environment
// variable, or with gmsh::plugin::load() (see README.txt).
//
// Plugin(ElementAverage) creates a list-based view with, for each element of a
// scalar view, the average of the values at its nodes, at every step.

#include "Plugin.h"

class GMSH_ElementAveragePlugin : public GMSH_PostPlugin {
public:
  // the options, and their default values
  GMSH_ElementAveragePlugin()
    : GMSH_PostPlugin({{GMSH_FULLRC, "View", nullptr, -1., ""},
                       {GMSH_FULLRC, "Scale", nullptr, 1., ""}},
                      {{GMSH_FULLRC, "Name", nullptr, "Average", ""}})
  {
  }
  std::string getName() const { return "ElementAverage"; }
  std::string getShortHelp() const { return "Average the values of elements"; }
  std::string getHelp() const
  {
    return "Plugin(ElementAverage) creates a list-based view named `Name' "
           "with, for each element of the scalar view `View', the average of "
           "the values at its nodes multiplied by `Scale', at every step.\n\n"
           "If `View' < 0, the plugin is run on the current view.";
  }
  std::string getAuthor() const { return "Gmsh example"; }

  PView *execute(PView *v)
  {
    PView *v1 = getView((int)option(0), v);
    if(!v1) return v;
    PViewData *data1 = getPossiblyAdaptiveData(v1);
    double scale = option(1);

    PView *v2 = new PView();
    PViewDataList *data2 = getDataList(v2);
    int step0 = data1->getFirstNonEmptyTimeStep();
    for(int ent = 0; ent < data1->getNumEntities(step0); ent++) {
      for(int ele = 0; ele < data1->getNumElements(step0, ent); ele++) {
        if(data1->skipElement(step0, ent, ele)) continue;
        if(data1->getNumComponents(step0, ent, ele) != 1) continue;
        // lists hold first order elements: read the corners only
        int numNodes = getNumCornerNodes(data1, step0, ent, ele);
        if(!numNodes) continue;
        int type = data1->getType(step0, ent, ele);
        std::vector<double> *out = data2->incrementList(1, type, numNodes);
        if(!out) continue;
        // the coordinates: all the x, then all the y, then all the z
        std::vector<double> x(numNodes), y(numNodes), z(numNodes);
        for(int nod = 0; nod < numNodes; nod++)
          data1->getNode(step0, ent, ele, nod, x[nod], y[nod], z[nod]);
        out->insert(out->end(), x.begin(), x.end());
        out->insert(out->end(), y.begin(), y.end());
        out->insert(out->end(), z.begin(), z.end());
        // the values: the same average at every node, for each step
        for(int step = step0; step < data1->getNumTimeSteps(); step++) {
          if(!data1->hasTimeStep(step)) continue;
          double sum = 0.;
          for(int nod = 0; nod < numNodes; nod++) {
            double val;
            data1->getValue(step, ent, ele, nod, 0, val);
            sum += val;
          }
          for(int nod = 0; nod < numNodes; nod++)
            out->push_back(scale * sum / numNodes);
        }
      }
    }
    for(int step = step0; step < data1->getNumTimeSteps(); step++)
      if(data1->hasTimeStep(step)) data2->Time.push_back(data1->getTime(step));
    data2->setName(optionStr(0));
    data2->setFileName(optionStr(0) + ".pos");
    data2->finalize();
    return v2;
  }
};

// the functions Gmsh looks for in the library
GMSH_PLUGIN(GMSH_ElementAveragePlugin)
