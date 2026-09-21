// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <cmath>
#include <map>
#include "GmshConfig.h"
#include "GmshVersion.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "PView.h"
#include "PViewData.h"
#include "PViewDataGModel.h"
#include "ElementType.h"
#include "StringUtils.h"
#include "Context.h"
#include "VTKXML.h"

// A step of a view that is not based on a model: a grid of its own, each
// element with its own points

static bool writeVTUStep(PViewData *data, int step, const std::string &name,
                         bool binary)
{
  struct node {
    int ent, ele, nod;
  };
  vtkXMLGrid grid;
  std::vector<node> nodes;
  std::map<int, bool> numComps;

  for(int ent = 0; ent < data->getNumEntities(step); ent++) {
    for(int ele = 0; ele < data->getNumElements(step, ent); ele++) {
      if(data->skipElement(step, ent, ele)) continue;
      int type = data->getType(step, ent, ele);
      int numNodes = data->getNumNodes(step, ent, ele);
      int mshType = 0;
      for(int order = 0; order <= 10 && !mshType; order++) {
        for(int serendip = 0; serendip < 2 && !mshType; serendip++) {
          int t = ElementType::getType(type, order, serendip);
          if(t > 0 && ElementType::getNumVertices(t) == numNodes) mshType = t;
        }
      }
      if(!mshType) mshType = ElementType::getType(type, 1);
      if(mshType <= 0) continue;
      const vtkXMLCell &c = getVTKXMLCell(mshType);
      if(!c.type) continue;
      for(auto k : c.nodes) {
        double x, y, z;
        data->getNode(step, ent, ele, k, x, y, z);
        grid.connectivity.push_back(nodes.size());
        nodes.push_back({ent, ele, k});
        grid.points.push_back(x);
        grid.points.push_back(y);
        grid.points.push_back(z);
      }
      grid.offsets.push_back(grid.connectivity.size());
      grid.types.push_back(c.type);
      numComps[data->getNumComponents(step, ent, ele)] = true;
    }
  }

  // one array per kind of field (scalar, vector, tensor) in the view
  for(auto &nc : numComps) {
    vtkXMLGrid::realArray a;
    a.numComp = nc.first;
    a.name = data->getName();
    if(numComps.size() > 1)
      a.name += (a.numComp == 1) ? " (scalar)" :
                (a.numComp == 3) ? " (vector)" : " (tensor)";
    a.name = grid.uniqueName(a.name);
    a.data.reserve(a.numComp * nodes.size());
    for(auto &n : nodes) {
      bool same = (data->getNumComponents(step, n.ent, n.ele) == a.numComp);
      for(int comp = 0; comp < a.numComp; comp++) {
        double val = std::nan("");
        if(same) data->getValue(step, n.ent, n.ele, n.nod, comp, val);
        a.data.push_back(val);
      }
    }
    grid.pointData.push_back(a);
  }

  return grid.write(name, binary,
                    data->getName() + ", created by Gmsh " + GMSH_VERSION);
}

// The views based on the same model go in the same file, as arrays on its
// mesh; several steps make a series of files, and a .pvd with their times

bool PView::writeVTU(const std::string &fileName, bool binary,
                     const std::vector<PView *> &views)
{
  std::map<GModel *, std::vector<PViewDataGModel *> > onModel;
  std::vector<PViewData *> others;
  int numSteps = 0;
  for(auto v : views) {
    PViewData *data = v->getData();
    if(!data->getNumTimeSteps()) continue;
    numSteps = std::max(numSteps, data->getNumTimeSteps());
    PViewDataGModel *d = dynamic_cast<PViewDataGModel *>(data);
    if(d && d->hasMultipleMeshes()) {
      Msg::Warning("View '%s' not exported: its steps have different meshes",
                   data->getName().c_str());
      continue;
    }
    if(d)
      onModel[d->getModel(d->getFirstNonEmptyTimeStep())].push_back(d);
    else
      others.push_back(data);
  }
  std::size_t numParts = onModel.size() + others.size();
  if(!numParts) {
    Msg::Error("No view to export in '%s'", fileName.c_str());
    return false;
  }

  std::vector<std::string> split = SplitFileName(fileName);
  bool series = (numSteps > 1 || split[2] == ".pvd");
  std::vector<std::vector<std::string> > files(numSteps);
  std::vector<double> times(numSteps, 0.);
  bool ok = true;

  for(int step = 0; step < numSteps; step++) {
    auto name = [&]() {
      std::string n = split[1];
      if(numParts > 1) n += "_" + std::to_string(files[step].size());
      if(series) {
        char s[32];
        snprintf(s, sizeof(s), "_%04d", step);
        n += s;
      }
      files[step].push_back(n + ".vtu");
      return split[0] + n + ".vtu";
    };
    bool timed = false;
    auto time = [&](PViewData *d) {
      if(!timed) times[step] = d->getTime(step);
      timed = true;
    };
    for(auto &m : onModel) {
      bool any = false;
      for(auto d : m.second) {
        // (a single step goes with every step of the others)
        if(d->getNumTimeSteps() > 1 && d->hasTimeStep(step)) time(d);
        if(d->getNumTimeSteps() == 1 || d->hasTimeStep(step)) any = true;
      }
      if(!any) continue;
      if(!m.first->writeVTU(name(), binary, CTX::instance()->mesh.saveAll,
                            CTX::instance()->mesh.scalingFactor, m.second,
                            step))
        ok = false;
    }
    for(auto d : others) {
      if(!d->hasTimeStep(step)) continue;
      time(d);
      if(!writeVTUStep(d, step, name(), binary)) ok = false;
    }
  }

  if(series && !writePVD(split[0] + split[1] + ".pvd", files, times))
    ok = false;
  return ok;
}
