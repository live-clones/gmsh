// $Id: ReadImg.cpp,v 1.13 2006-01-28 04:50:36 geuzaine Exp $
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

#include "ReadImg.h"
#include "Gmsh.h"
#include "GmshUI.h"
#include "Views.h"
  
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_PNM_Image.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_BMP_Image.H>

// from an image, we create a post-procession view

static Post_View *Img2Pos(Fl_RGB_Image & img_init, int quads=1, 
			  int resizex=0, int resizey=0) 
{
  img_init.desaturate(); // convert to grayscale

  // resize if necessary
  Fl_RGB_Image * img;
  if(!resizex || !resizey)
    img = (Fl_RGB_Image *) img_init.copy();
  else
    img = (Fl_RGB_Image *) img_init.copy(resizex, resizey);

  const uchar *data = img->array;
  int height = img->h();
  int width = img->w();
  int dim = img->d();

  if(dim != 1) {
    Msg(GERROR, "Unable to convert image to grayscale");
    return NULL;
  }

  Post_View * v = BeginView(1);

  double z = 0.;
  for(int i = 0; i < height - 1; i++) {
    const uchar *a = data + i * width * dim;
    const uchar *a1 = data + (i + 1) * width * dim;
    double y = height - i - 1;
    double y1 = height - i - 2;
    for(int j = 0; j < width - 1; j++) {
      double x = j;
      double x1 = j + 1;
      double val1 = (double)a[j]/255.;
      double val2 = (double)a1[j]/255.;
      double val3 = (double)a1[j + 1]/255.;
      double val4 = (double)a[j + 1]/255.;
      if(quads){ // generate quads
	List_Add(v->SQ, &x); List_Add(v->SQ, &x); 
	List_Add(v->SQ, &x1); List_Add(v->SQ, &x1);
	List_Add(v->SQ, &y); List_Add(v->SQ, &y1);
	List_Add(v->SQ, &y1); List_Add(v->SQ, &y);
	List_Add(v->SQ, &z); List_Add(v->SQ, &z);
	List_Add(v->SQ, &z); List_Add(v->SQ, &z);
	List_Add(v->SQ, &val1); List_Add(v->SQ, &val2);
	List_Add(v->SQ, &val3); List_Add(v->SQ, &val4);
	v->NbSQ++;
      }
      else{ // generate triangles
	List_Add(v->ST, &x); List_Add(v->ST, &x); List_Add(v->ST, &x1);
	List_Add(v->ST, &y); List_Add(v->ST, &y1); List_Add(v->ST, &y1);
	List_Add(v->ST, &z); List_Add(v->ST, &z); List_Add(v->ST, &z);
	List_Add(v->ST, &val1); List_Add(v->ST, &val2); List_Add(v->ST, &val3);
	v->NbST++;
	List_Add(v->ST, &x); List_Add(v->ST, &x1); List_Add(v->ST, &x1);
	List_Add(v->ST, &y); List_Add(v->ST, &y1); List_Add(v->ST, &y);
	List_Add(v->ST, &z); List_Add(v->ST, &z); List_Add(v->ST, &z);
	List_Add(v->ST, &val1); List_Add(v->ST, &val3); List_Add(v->ST, &val4);
	v->NbST++;
      }
    }
  }
  delete img;
  return v;
}

static void EndPos(char *name, Post_View *v)
{
  if(!v) return;
  char name2[256];
  strcpy(name2, name);
  strcat(name2, ".pos");
  EndView(v, 1, name2, name);
  Msg(INFO, "Read file '%s'", name);
  Msg(STATUS2N, "Read '%s'", name);
}

void read_pnm(char *name) 
{
  Msg(INFO, "Reading PNM file '%s'", name);
  Fl_PNM_Image img(name);
  EndPos(name, Img2Pos(img));
}

void read_jpeg(char *name) 
{
  Msg(INFO, "Reading JPEG file '%s'", name);
  Fl_JPEG_Image img(name);
  EndPos(name, Img2Pos(img));
}

void read_png(char *name) 
{
  Msg(INFO, "Reading PNG file '%s'", name);
  Fl_PNG_Image img(name);
  EndPos(name, Img2Pos(img));
}

void read_bmp(char *name) 
{
  Msg(INFO, "Reading BMP file '%s'", name);
  Fl_BMP_Image img(name);
  EndPos(name, Img2Pos(img));
}
