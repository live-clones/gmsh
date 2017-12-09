// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include "QuadratureData.h"
#include "GModel.h"
#include "MElement.h"
#include "PView.h"
#include "PViewDataGModel.h"

StringXNumber QuadratureDataOptions_Number[] = {
  {GMSH_FULLRC, "Dimension", NULL, -1},
  {GMSH_FULLRC, "Tag", NULL, -1},
  {GMSH_FULLRC, "Physical", NULL, 0},
  {GMSH_FULLRC, "Order", NULL, 4},
  {GMSH_FULLRC, "ViewTag", NULL, -1},
};

StringXString QuadratureDataOptions_String[] = {
  {GMSH_FULLRC, "Type", NULL, "Gauss"},
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterQuadratureDataPlugin()
  {
    return new GMSH_QuadratureDataPlugin();
  }
}

int GMSH_QuadratureDataPlugin::getNbOptions() const
{
  return sizeof(QuadratureDataOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_QuadratureDataPlugin::getOption(int iopt)
{
  return &QuadratureDataOptions_Number[iopt];
}

int GMSH_QuadratureDataPlugin::getNbOptionsStr() const
{
  return sizeof(QuadratureDataOptions_String) / sizeof(StringXString);
}

StringXString *GMSH_QuadratureDataPlugin::getOptionStr(int iopt)
{
  return &QuadratureDataOptions_String[iopt];
}

std::string GMSH_QuadratureDataPlugin::getHelp() const
{
  return "Given an input mesh, Plugin(QuadratureData) creates a view "
    "containing quadrature data allowing to integrate polynomials of order "
    "`Order' on elements in the mesh."
    "\n\n"
    "If `Dimension' >= 0, only return data for entities of that dimension. Otherwise "
    "return data for entities of all dimensions."
    "\n\n"
    "If `Dimension' >= 0 and `Tag' >= 0, only return data for the entity of the given"
    "dimension and tag."
    "\n\n"
    "If `Physical' is set, interpret `Tag' as a physical group tag instead of an "
    "elementary entity tag."
    "\n\n"
    "The data returned is as follows (numComp = 17, mult = #quadraturePoints):"
    "\n\n"
    "   x(p1), y(p1), z(p1), u(p1), v(p1), w(p1), weight(p1), "
    "     detj(p1), jac11(p1), jac12(p1), ..., jac33(p1)"
    "   x(p2), y(p2), z(p2), u(p2), v(p2), w(p2), weight(p2), "
    "     detj(p2), jac11(p2), jac12(p2), ..., jac33(p2)"
    "   ..."
    "\n\n"
    "If `ViewTag' is positive, force that tag for the created view."
    ;
}

PView* GMSH_QuadratureDataPlugin::execute(PView *v)
{
  int dim = (int)QuadratureDataOptions_Number[0].def;
  int tag = (int)QuadratureDataOptions_Number[1].def;
  int physical = (int)QuadratureDataOptions_Number[2].def;
  int order = (int)QuadratureDataOptions_Number[3].def;
  int viewtag = (int)QuadratureDataOptions_Number[4].def;

  std::string type = QuadratureDataOptions_String[0].def;

  GModel *m = GModel::current();

  std::vector<GEntity*> entities;
  if(physical){
    std::map<int, std::vector<GEntity*> > groups[4];
    m->getPhysicalGroups(groups);
    if(dim >= 0 && dim <= 3 && tag > 0){
      entities = groups[dim][tag];
    }
    else if(dim >= 0 && dim <= 3){
      for(std::map<int, std::vector<GEntity*> >::iterator it = groups[dim].begin();
          it != groups[dim].end(); it++){
        entities.insert(entities.end(), it->second.begin(), it->second.end());
      }
    }
    else{
      for(int d = 0; d < 4; d++){
        for(std::map<int, std::vector<GEntity*> >::iterator it = groups[d].begin();
            it != groups[dim].end(); it++){
          entities.insert(entities.end(), it->second.begin(), it->second.end());
        }
      }
    }
  }
  else if(dim >= 0 && dim <= 3 && tag >= 0){
    GEntity *ge = m->getEntityByTag(dim, tag);
    if(ge) entities.push_back(ge);
  }
  else{
    m->getEntities(entities, dim);
  }

  if(entities.empty()){
    Msg::Error("No entities");
    return v;
  }

  PViewDataGModel *q = 0;
  if(type == "Gauss")
    q = new PViewDataGModel(PViewDataGModel::GaussPointData);
  else if(type.size()){
    Msg::Error("Unknown quadrature type '%s'", type.c_str());
    return v;
  }

  std::vector<int> tags;
  std::vector<std::vector<double> > data;

  // FIXME: make this efficient: precompute the size of vectors (or better,
  // directly fill stepData), precompute the shape functions derivatives and use
  // that for the jacobian + parallelise with openmp.
  for(unsigned int i = 0; i < entities.size(); i++){
    for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++){
      MElement *e = entities[i]->getMeshElement(j);
      tags.push_back(e->getNum());
      data.push_back(std::vector<double>());
      int npts; IntPt *gp;
      e->getIntegrationPoints(order, &npts, &gp);
      for(int i = 0; i < npts; i++){
        double u = gp[i].pt[0];
        double v = gp[i].pt[1];
        double w = gp[i].pt[2];
        double weight = gp[i].weight;
        SPoint3 p;
        e->pnt(u, v, w, p);
        data.back().push_back(p.x());
        data.back().push_back(p.y());
        data.back().push_back(p.z());
        data.back().push_back(u);
        data.back().push_back(v);
        data.back().push_back(w);
        data.back().push_back(weight);
        double jac[3][3];
        data.back().push_back(e->getJacobian(u, v, w, jac));
        data.back().push_back(jac[0][0]);
        data.back().push_back(jac[0][1]);
        data.back().push_back(jac[0][2]);
        data.back().push_back(jac[1][0]);
        data.back().push_back(jac[1][1]);
        data.back().push_back(jac[1][2]);
        data.back().push_back(jac[2][0]);
        data.back().push_back(jac[2][1]);
        data.back().push_back(jac[2][2]);
      }
    }
  }

  q->addData(m, tags, data, 0, 0, 0, 17);
  q->setName("Quadrature");
  q->setFileName("Quadrature.pos");
  q->finalize();
  new PView(q, viewtag);

  return v;
}
