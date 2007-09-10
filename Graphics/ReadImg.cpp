// $Id: ReadImg.cpp,v 1.19 2007-09-10 04:47:03 geuzaine Exp $
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

#include "ReadImg.h"
#include "Gmsh.h"
#include "GmshUI.h"
#include "PView.h"
#include "PViewDataList.h"
  
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_PNM_Image.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_BMP_Image.H>

// from an image, we create a post-procession view

static PViewDataList *Img2Data(Fl_RGB_Image &img_init, int quads=1,
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
    Msg(GERROR, "Unable to obtain one-channel image");
    return 0;
  }

  PViewDataList *d = new PViewDataList(true);

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
	List_Add(d->SQ, &x); List_Add(d->SQ, &x); 
	List_Add(d->SQ, &x1); List_Add(d->SQ, &x1);
	List_Add(d->SQ, &y); List_Add(d->SQ, &y1);
	List_Add(d->SQ, &y1); List_Add(d->SQ, &y);
	List_Add(d->SQ, &z); List_Add(d->SQ, &z);
	List_Add(d->SQ, &z); List_Add(d->SQ, &z);
	List_Add(d->SQ, &val1); List_Add(d->SQ, &val2);
	List_Add(d->SQ, &val3); List_Add(d->SQ, &val4);
	d->NbSQ++;
      }
      else{ // generate triangles
	List_Add(d->ST, &x); List_Add(d->ST, &x); List_Add(d->ST, &x1);
	List_Add(d->ST, &y); List_Add(d->ST, &y1); List_Add(d->ST, &y1);
	List_Add(d->ST, &z); List_Add(d->ST, &z); List_Add(d->ST, &z);
	List_Add(d->ST, &val1); List_Add(d->ST, &val2); List_Add(d->ST, &val3);
	d->NbST++;
	List_Add(d->ST, &x); List_Add(d->ST, &x1); List_Add(d->ST, &x1);
	List_Add(d->ST, &y); List_Add(d->ST, &y1); List_Add(d->ST, &y);
	List_Add(d->ST, &z); List_Add(d->ST, &z); List_Add(d->ST, &z);
	List_Add(d->ST, &val1); List_Add(d->ST, &val3); List_Add(d->ST, &val4);
	d->NbST++;
      }
    }
  }
  delete img;
  return d;
}

static int EndPos(char *name, PViewData *d)
{
  if(!d) return 0;
  char name_pos[256], title[256];
  strcpy(name_pos, name);
  strcat(name_pos, ".pos");
  int i;
  for(i = strlen(name) - 1; i >= 0; i--){
    if(name[i] == '/' || name[i] == '\\')
      break;
  }
  if(i <= 0)
    strcpy(title, name);
  else
    strcpy(title, &name[i + 1]);
  d->setName(title);
  d->setFileName(name_pos);
  if(d->finalize()){
    new PView(d);
    return 1;
  }
  else{
    delete d;
    return 0;
  }
}

int read_pnm(char *name) 
{
  Fl_PNM_Image img(name);
  return EndPos(name, Img2Data(img));
}

int read_jpeg(char *name) 
{
  Fl_JPEG_Image img(name);
  return EndPos(name, Img2Data(img));
}

int read_png(char *name) 
{
  Fl_PNG_Image img(name);
  return EndPos(name, Img2Data(img));
}

int read_bmp(char *name) 
{
  Fl_BMP_Image img(name);
  return EndPos(name, Img2Data(img));
}
