// $Id: Gmsh.cpp,v 1.7 2008-07-03 17:06:01 geuzaine Exp $
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

#include <string>
#include "GmshDefines.h"
#include "GModel.h"
#include "Message.h"
#include "Parser.h"
#include "OpenFile.h"
#include "CreateFile.h"
#include "Options.h"
#include "CommandLine.h"
#include "OS.h"
#include "Numeric.h"
#include "Generator.h"
#include "Field.h"
#include "Context.h"

#if !defined(HAVE_NO_POST)
#include "PluginManager.h"
#endif

Context_T CTX;

int GmshInitialize(int argc, char **argv)
{
  // Initialize messages (parallel stuff, etc.)
  Msg::Init(argc, argv);

  // Initialize the symbol tree that will hold variable names in the
  // parser
  InitSymbols();
  
  // Load default options
  Init_Options(0);

  // Read configuration files and command line options
  Get_Options(argc, argv);

  // Make sure we have enough resources (stack)
  CheckResources();
  
#if !defined(HAVE_NO_POST)
  // Initialize the default plugins
  GMSH_PluginManager::instance()->registerDefaultPlugins();
#endif

  // Check for buggy obsolete GSL versions
  check_gsl();
  return 1;
}

int GmshSetMessageHandler(GmshMessage *callback)
{
  Msg::SetCallback(callback);
  return 1;
}

int GmshFinalize()
{
  return 1;
}

int GmshBatch()
{
  if(!GModel::current()) return 0;

  OpenProject(CTX.filename);
  for(unsigned int i = 1; i < CTX.files.size(); i++)
    MergeFile(CTX.files[i].c_str());
#if !defined(HAVE_NO_POST)
  if(CTX.bgm_filename) {
    MergeFile(CTX.bgm_filename);
    if(PView::list.size())
      GModel::current()->getFields()->set_background_mesh(PView::list.size() - 1);
    else
      Msg::Error("Invalid background mesh (no view)");
  }
#endif
  if(CTX.batch == 4) {
    AdaptMesh(GModel::current());
    CreateOutputFile(CTX.output_filename, CTX.mesh.format);
  }
  else if(CTX.batch > 0) {
    GModel::current()->mesh(CTX.batch);
    CreateOutputFile(CTX.output_filename, CTX.mesh.format);
  }
  else if(CTX.batch == -1)
    CreateOutputFile(CTX.output_filename, FORMAT_GEO);
  else if(CTX.batch == -2)
    GModel::current()->checkMeshCoherence();

  return 1;
}
