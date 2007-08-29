// $Id: Graph2D.cpp,v 1.60 2007-08-29 18:41:06 geuzaine Exp $
//
// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
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

#include "GmshUI.h"
#include "Draw.h"
#include "PView.h"

void Draw_Graph2D()
{
}

void Draw_Text2D()
{
  for(unsigned int i = 0; i < PView::list.size(); i++){
    PViewData *data = PView::list[i]->getData();
    PViewOptions *opt = PView::list[i]->getOptions();
    if(opt->Visible && opt->DrawStrings){
      glColor4ubv((GLubyte *) & opt->color.text2d);
      for(int j = 0; j < data->getNumStrings2D(); j++){
	double x, y, style;
	std::string str;
	data->getString2D(j, opt->TimeStep, str, x, y, style);
	Fix2DCoordinates(&x, &y);
	glRasterPos2d(x, y);
	Draw_String((char*)str.c_str(), style);
      }
    }
  }
}
