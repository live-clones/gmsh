// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <string.h>
#include <vector>
#include "ReadImg.h"
#include "GmshMessage.h"
#include "ImageIO.h"
#include "PView.h"
#include "PViewDataList.h"
#include "GmshConfig.h"

// from an image, we create a post-processing view

static PViewDataList *Img2Data(const std::string &fileName, int quads = 1,
                               int resizex = 0, int resizey = 0)
{
  int width = 0, height = 0, dim = 0;
  std::vector<unsigned char> pixels;
  // read as greyscale
  if(!ImageIO::read(fileName, width, height, dim, pixels, 1)) return nullptr;

  if(resizex && resizey) {
    std::vector<unsigned char> resized;
    if(!ImageIO::resize(pixels, width, height, dim, resized, resizex, resizey))
      return nullptr;
    pixels.swap(resized);
    width = resizex;
    height = resizey;
  }

  const unsigned char *data = &pixels[0];

  PViewDataList *d = new PViewDataList();

  double z = 0.;
  for(int i = 0; i < height - 1; i++) {
    const unsigned char *a = data + i * width * dim;
    const unsigned char *a1 = data + (i + 1) * width * dim;
    double y = height - i - 1;
    double y1 = height - i - 2;
    for(int j = 0; j < width - 1; j++) {
      double x = j;
      double x1 = j + 1;
      double val1 = (double)a[j * dim] / 255.;
      double val2 = (double)a1[j * dim] / 255.;
      double val3 = (double)a1[(j + 1) * dim] / 255.;
      double val4 = (double)a[(j + 1) * dim] / 255.;
      if(quads) { // generate quads
        d->SQ.push_back(x);
        d->SQ.push_back(x);
        d->SQ.push_back(x1);
        d->SQ.push_back(x1);
        d->SQ.push_back(y);
        d->SQ.push_back(y1);
        d->SQ.push_back(y1);
        d->SQ.push_back(y);
        d->SQ.push_back(z);
        d->SQ.push_back(z);
        d->SQ.push_back(z);
        d->SQ.push_back(z);
        d->SQ.push_back(val1);
        d->SQ.push_back(val2);
        d->SQ.push_back(val3);
        d->SQ.push_back(val4);
        d->NbSQ++;
      }
      else { // generate triangles
        d->ST.push_back(x);
        d->ST.push_back(x);
        d->ST.push_back(x1);
        d->ST.push_back(y);
        d->ST.push_back(y1);
        d->ST.push_back(y1);
        d->ST.push_back(z);
        d->ST.push_back(z);
        d->ST.push_back(z);
        d->ST.push_back(val1);
        d->ST.push_back(val2);
        d->ST.push_back(val3);
        d->NbST++;
        d->ST.push_back(x);
        d->ST.push_back(x1);
        d->ST.push_back(x1);
        d->ST.push_back(y);
        d->ST.push_back(y1);
        d->ST.push_back(y);
        d->ST.push_back(z);
        d->ST.push_back(z);
        d->ST.push_back(z);
        d->ST.push_back(val1);
        d->ST.push_back(val3);
        d->ST.push_back(val4);
        d->NbST++;
      }
    }
  }
  return d;
}

static int EndPos(const char *name, PViewData *d)
{
  if(!d) return 0;
  char name_pos[256], title[256];
  strcpy(name_pos, name);
  strcat(name_pos, ".pos");
  int i;
  for(i = strlen(name) - 1; i >= 0; i--) {
    if(name[i] == '/' || name[i] == '\\') break;
  }
  if(i <= 0)
    strcpy(title, name);
  else
    strcpy(title, &name[i + 1]);
  d->setName(title);
  d->setFileName(name_pos);
  if(d->finalize()) {
    new PView(d);
    return 1;
  }
  else {
    delete d;
    return 0;
  }
}

int read_pnm(const std::string &fileName)
{
  return EndPos(fileName.c_str(), Img2Data(fileName));
}

int read_jpeg(const std::string &fileName)
{
  return EndPos(fileName.c_str(), Img2Data(fileName));
}

int read_png(const std::string &fileName)
{
  return EndPos(fileName.c_str(), Img2Data(fileName));
}

int read_bmp(const std::string &fileName)
{
  return EndPos(fileName.c_str(), Img2Data(fileName));
}
