// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _SHOWNEIGHBORELEMENTS_H_
#define _SHOWNEIGHBORELEMENTS_H_

#include "Plugin.h"
#include <set>

class MVertex;

extern "C"
{
  GMSH_Plugin *GMSH_RegisterShowNeighborElementsPlugin();
}

class GMSH_ShowNeighborElementsPlugin : public GMSH_PostPlugin
{
private :
  int _nLayers;
  int _nel1, _nel2, _nel3, _nel4, _nel5;
  std::multimap<MVertex*, MElement*> _vert2elem;
  std::set<MVertex*> _vertices;

public :
  GMSH_ShowNeighborElementsPlugin() {}
  std::string getName() const { return "ShowNeighborElements"; }
  std::string getShortHelp() const {
    return "Choose which type of element to hide.";
  }
  std::string getHelp() const;
  std::string getAuthor() const { return "Amaury Johnen"; }
  int getNbOptions() const;
  StringXNumber* getOption(int);
  PView* execute(PView *);

private :
  void _init(GEntity *);
  void _showLayers(GEntity *, int nLayer);
};

#endif
