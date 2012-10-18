// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _NEARTOFARFIELD_H_
#define _NEARTOFARFIELD_H_

#include "Plugin.h"
#include "shapeFunctions.h"
#include "Numeric.h"
#include "PViewOptions.h"
#include "MElement.h"
#include "GModel.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterNearToFarFieldPlugin();
}

class GMSH_NearToFarFieldPlugin : public GMSH_PostPlugin
{
 public:
  GMSH_NearToFarFieldPlugin(){}
  std::string getName() const { return "NearToFarField"; }
  std::string getShortHelp() const
  {
    return "Compute Far Field pattern from Near Field on a surface";
  }
  std::string getHelp() const;
  virtual std::string getAuthor() const { return "R. Sabariego, C. Geuzaine"; }
  int getNbOptions() const;
  StringXNumber* getOption(int iopt);
  int getNbOptionsStr() const;
  StringXString *getOptionStr(int iopt);
  PView *execute(PView *);

  double getFarFieldJin(std::vector<element*> &allElems,
                        std::vector<std::vector<double> > &farfieldvector,
                        std::vector<std::vector<double> > &js,
                        std::vector<std::vector<double> > &ms,
                        double k0, double r_far, double theta, double phi);

  double getFarFieldMonk(std::vector<element*> &allElems,
                         std::vector<std::vector<double> > &farfieldvector,
                         std::vector<std::vector<double> > &js,
                         std::vector<std::vector<double> > &ms,
                         double k0, double theta, double phi);
};

#endif
