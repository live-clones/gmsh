// $Id: Main.cpp,v 1.2 2008-06-05 11:52:49 samtech Exp $
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

#include <stdlib.h>
#include "Gmsh.h"
#include "GModel.h"
#include "CommandLine.h"
#include "Message.h"
#include "Context.h"

extern Context_T CTX;

int main(int argc, char *argv[])
{
  CTX.terminal = 1;

  if(argc < 2){
    Print_Usage(argv[0]);
    exit(0);
  }

  GmshInitialize(argc, argv);
  new GModel;
  GmshBatch();
  GmshFinalize();

  Msg::Exit(0);
  return 1;
}
