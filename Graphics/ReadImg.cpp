// $Id: ReadImg.cpp,v 1.6 2003-11-27 02:33:31 geuzaine Exp $
//
// Copyright (C) 1997-2003 C. Geuzaine, J.-F. Remacle
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
// Please report all bugs and problems to "gmsh@geuz.org".

#include "ReadImg.h"
#include "Gmsh.h"
#include "GmshUI.h"
#include "Views.h"
  
#if (FL_MAJOR_VERSION == 1) && (FL_MINOR_VERSION == 0)

void read_pnm(char *name) 
{
}

#else

#include <FL/Fl_PNM_Image.H>
  
// from an image, we create a post pro object
Post_View * Img2Pos(Fl_RGB_Image & img_init) 
{
  img_init.desaturate();

  Fl_RGB_Image * img = (Fl_RGB_Image *) img_init.copy(128, 128);

  const uchar *data = img->array;
  int height = img->h();
  int width = img->w();
  int dim = img->d();

  Post_View * v = BeginView(1);

  for(int i = 0; i < width - 1; i++) {
    const uchar *a = data + i * width * dim;
    const uchar *a1 = data + (i + 1) * width * dim;
    double y = 1. - (double)i / ((double)width - 1.);
    double y1 = 1. - (double)(i + 1) / ((double)width - 1.);
    for(int j = 0; j < height - 1; j++) {
      double x = (double)j / ((double)height - 1.);
      double x1 = (double)(j + 1) / ((double)height - 1.);
      double z = 0.0;
      if(dim == 1) {     // grayscale
        uchar G1 = a[j];
        uchar G2 = a1[j];
        uchar G3 = a1[j + 1];
        uchar G4 = a[j + 1];
        const double eps = 0.005;
        const double Eps = .25;
        double val1 = Eps * (G1) / 255. + eps;
        double val2 = Eps * (G2) / 255. + eps;
        double val3 = Eps * (G3) / 255. + eps;
        double val4 = Eps * (G4) / 255. + eps;
	/*
	  val1*=val1;
	  val2*=val2;
	  val3*=val3;
	  val4*=val4;
	*/ 
	List_Add(v->ST, &x);
        List_Add(v->ST, &x);
        List_Add(v->ST, &x1);
        List_Add(v->ST, &y);
        List_Add(v->ST, &y1);
        List_Add(v->ST, &y1);
        List_Add(v->ST, &z);
        List_Add(v->ST, &z);
        List_Add(v->ST, &z);
        List_Add(v->ST, &val1);
        List_Add(v->ST, &val2);
        List_Add(v->ST, &val3);
        v->NbST++;
        List_Add(v->ST, &x);
        List_Add(v->ST, &x1);
        List_Add(v->ST, &x1);
        List_Add(v->ST, &y);
        List_Add(v->ST, &y1);
        List_Add(v->ST, &y);
        List_Add(v->ST, &z);
        List_Add(v->ST, &z);
        List_Add(v->ST, &z);
        List_Add(v->ST, &val1);
        List_Add(v->ST, &val3);
        List_Add(v->ST, &val4);
        v->NbST++;
      }
    }
  }
  delete img;
  return v;
}

void read_pnm(char *name) 
{
  Msg(INFO, "Reading PNM file '%s'", name);

  Fl_PNM_Image theVeryNicePicture(name);
  Post_View * v = Img2Pos(theVeryNicePicture);
  char name2[256];
  strcpy(name2, name);
  strcat(name2, ".pos");
  EndView(v, 1, name2, name);

  Msg(INFO, "Read PNM file '%s'", name);
  Msg(STATUS2N, "Read '%s'", name);
}

#endif
