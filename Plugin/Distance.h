// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributed by Matti Pellikka <matti.pellikka@tut.fi>.

#ifndef _DISTANCE_H_
#define _DISTANCE_H_

#include <string>
#include "Plugin.h"
#include "MVertex.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterDistancePlugin();
}

class GMSH_DistancePlugin : public GMSH_PostPlugin
{
 private:
  std::string _fileName;
  double _minScale;
  double _maxScale;
  int _maxDim;
  PViewDataList *_data;
 public:
  std::map<MVertex*,double > _distance_map;
  GMSH_DistancePlugin(); 
  std::string getName() const { return "Distance"; }
  std::string getShortHelp() const
  {
    return "Compute distance to boundaries";
  }
  std::string getHelp() const;
  std::string getAuthor() const { return "E. Marchandise"; }
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);  
  int getNbOptionsStr() const;
  StringXString *getOptionStr(int iopt);
  PView *execute(PView *);
  void printView(std::vector<GEntity*> _entities,  
		 std::map<MVertex*,double > _distance_map );
};

#endif
