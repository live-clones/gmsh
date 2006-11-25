// $Id: OptimizeMesh.cpp,v 1.1 2006-11-25 23:06:08 geuzaine Exp $
//
// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
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

#include "GModel.h"
#include "GRegion.h"
#include "Message.h"
#include "OS.h"

extern GModel *GMODEL;

void OptimizeMesh()
{
  Msg(STATUS1, "Optimizing order...");
  double t1 = Cpu();

  Msg(GERROR, "Mesh optimize needs to be reinterfaced");


  double t2 = Cpu();
  Msg(INFO, "Mesh optimize complete (%g s)", t2 - t1);
  Msg(STATUS1, "Mesh");
}
