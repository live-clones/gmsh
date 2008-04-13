// $Id: Gmsh.cpp,v 1.2 2008-04-13 09:45:48 geuzaine Exp $
//
// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include "Parser.h"
#include "Options.h"
#include "CommandLine.h"
#include "OS.h"
#include "PluginManager.h"
#include "Numeric.h"

int GmshInitialize(int argc, char **argv)
{
  // Initialize the symbol tree that will hold variable names in the
  // parser
  InitSymbols();
  
  // Load default options
  Init_Options(0);

  // Read configuration files and command line options
  Get_Options(argc, argv);

  // Make sure we have enough resources (stack)
  CheckResources();
  
  // Initialize the default plugins
  GMSH_PluginManager::instance()->registerDefaultPlugins();

  // Check for buggy obsolete GSL versions
  check_gsl();
  return 1;
}

int GmshNewModel()
{
  // Create a new model and add it to the model list, and make it the
  // current model
}

int GmshMerge(std::string fileName)
{
  // Merge CAD or mesh data in the current model, or create
  // post-processing view associated with the current model
}

int GmshClear()
{
  // Destroys all models and post-processing views
}

int GmshOpen(std::string fileName)
{
  GmshClear();
  GmshNewModel();
  GmshMerge(fileName);
}

int GmshFinalize()
{
  return 1;
}
