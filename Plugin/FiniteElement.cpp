// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshConfig.h"
#include "GModel.h"
#include "FiniteElement.h"
#include "gmshAssembler.h"
#include "gmshLaplace.h"
#include "gmshHelmholtz.h"
#include "gmshLinearSystemGmm.h"

StringXNumber FiniteElementOptions_Number[] = {
  {GMSH_FULLRC, "Parameter", NULL, 1.},
  {GMSH_FULLRC, "Volume", NULL, 1.},
  {GMSH_FULLRC, "Surface1", NULL, 2.},
  {GMSH_FULLRC, "Value1", NULL, 0.},
  {GMSH_FULLRC, "Surface2", NULL, 3.},
  {GMSH_FULLRC, "Value2", NULL, 1.}
};

StringXString FiniteElementOptions_String[] = {
  {GMSH_FULLRC, "Equation", NULL, "Laplace"},
  {GMSH_FULLRC, "BC1", NULL, "Dirichlet"},
  {GMSH_FULLRC, "BC2", NULL, "Dirichlet"},
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterFiniteElementPlugin()
  {
    return new GMSH_FiniteElementPlugin();
  }
}

void GMSH_FiniteElementPlugin::getName(char *name) const
{
  strcpy(name, "Finite Element");
}

void GMSH_FiniteElementPlugin::getInfos(char *author, char *copyright,
                                   char *help_text) const
{
  strcpy(author, "C. Geuzaine, J.-F. Remacle");
  strcpy(copyright, "C. Geuzaine, J.-F. Remacle");
  strcpy(help_text,
         "Plugin(FiniteElement) solves simple PDEs\n"
         "using the finite element method. This is only\n"
         "intended as a demonstration tool: it is NOT\n"
         "intended for general use."
         "\n"
         "Plugin(FiniteElement) creates a new view.\n");
}

int GMSH_FiniteElementPlugin::getNbOptions() const
{
  return sizeof(FiniteElementOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_FiniteElementPlugin::getOption(int iopt)
{
  return &FiniteElementOptions_Number[iopt];
}

int GMSH_FiniteElementPlugin::getNbOptionsStr() const
{
  return sizeof(FiniteElementOptions_String) / sizeof(StringXString);
}

StringXString *GMSH_FiniteElementPlugin::getOptionStr(int iopt)
{
  return &FiniteElementOptions_String[iopt];
}

void GMSH_FiniteElementPlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "FiniteElement failed...");
}

#if defined(HAVE_GMM)
template<class scalar>
class solver{
 public:
  gmshLinearSystemGmm<scalar> *lsys;
  gmshAssembler<scalar> *myAssembler;
  solver()
  {
    int volume = (int)FiniteElementOptions_Number[1].def;
    int surface1 = (int)FiniteElementOptions_Number[2].def;
    double value1 = FiniteElementOptions_Number[3].def;
    int surface2 = (int)FiniteElementOptions_Number[4].def;
    double value2 = FiniteElementOptions_Number[5].def;
    std::string bc1 = FiniteElementOptions_String[1].def;
    std::string bc2 = FiniteElementOptions_String[2].def;

    lsys = new gmshLinearSystemGmm<scalar>;
    lsys->setPrec(1.e-10);
    lsys->setNoisy(2);
    myAssembler = new gmshAssembler<scalar>(lsys);

    GModel *m = GModel::current();
    std::vector<MVertex*> vertices;

    if(bc1 == "Dirichlet"){
      m->getMeshVertices(surface1, 2, vertices);
      for(unsigned int i = 0; i < vertices.size(); i++)
        myAssembler->fixVertex(vertices[i], 0, 1, value1);
    }
    if(bc2 == "Dirichlet"){
      m->getMeshVertices(surface2, 2, vertices);
      for(unsigned int i = 0; i < vertices.size(); i++)
        myAssembler->fixVertex(vertices[i], 0, 1, value2);
    }
    m->getMeshVertices(volume, 3, vertices);
    for(unsigned int i = 0; i < vertices.size(); i++)
      myAssembler->numberVertex(vertices[i], 0, 1);

    Msg::Info("Assembler: %d dofs, %d fixed",
              myAssembler->sizeOfR(), myAssembler->sizeOfF());
  }
};
#endif

PView *GMSH_FiniteElementPlugin::execute(PView *v)
{
  std::string equation = FiniteElementOptions_String[0].def;
  double parameter = FiniteElementOptions_Number[0].def;
  int volume = (int)FiniteElementOptions_Number[1].def;

#if defined(HAVE_GMM)
  GModel *m = GModel::current();
  std::map<int, std::vector<GEntity*> > groups[4];
  m->getPhysicalGroups(groups);

  std::vector<MVertex*> vertices;
  m->getMeshVertices(volume, 3, vertices);
  std::map<int, std::vector<double> > data;

  if(equation == "Laplace"){
    solver<double> s;
    gmshFunction<double> diffusivity(parameter);
    gmshLaplaceTerm laplace(m, &diffusivity, 1);
    for(unsigned int i = 0; i < groups[3][volume].size(); i++)
      laplace.addToMatrix(*s.myAssembler, groups[3][volume][i]);
    s.lsys->systemSolve();
    for (unsigned int i = 0; i < vertices.size(); i++)
      data[vertices[i]->getNum()].push_back
        (s.myAssembler->getDofValue(vertices[i], 0, 1));
    PView *pv = new PView("laplace", "NodeData", m, data, 0.);
  }
  else if(equation == "Helmholtz"){
    solver<std::complex<double> > s;
    gmshFunction<std::complex<double> > waveNumber(parameter);
    gmshHelmholtzTerm helmholtz(m, &waveNumber, 1);
    for(unsigned int i = 0; i < groups[3][volume].size(); i++)
      helmholtz.addToMatrix(*s.myAssembler, groups[3][volume][i]);
    s.lsys->setGmres(1);
    s.lsys->systemSolve();
    for (unsigned int i = 0; i < vertices.size(); i++)
      data[vertices[i]->getNum()].push_back
        (s.myAssembler->getDofValue(vertices[i], 0, 1).real());
    PView *pv = new PView("helmholtz", "NodeData", m, data, 0.);
    data.clear();
    for (unsigned int i = 0; i < vertices.size(); i++)
      data[vertices[i]->getNum()].push_back
        (s.myAssembler->getDofValue(vertices[i], 0, 1).imag());
    pv->addStep(m, data, 1.);
  }
  else{
    Msg::Error("Unknown equation to solve");
  }
#endif
  return 0;
}
