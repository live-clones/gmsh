// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdio.h>
#include <string>
#include <algorithm>
#include <sstream>
#include "GModel.h"
#include "OS.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MVertexRTree.h"
#include "discreteFace.h"
#include "StringUtils.h"
#include "Context.h"

#ifdef HAVE_NII2MESH

#include "src/nifti1.h"
extern "C" {
float *load_nii(const char *fnm, nifti_1_header *hdr);
#include "src/meshify.h"
#include "src/quadric.h"
#include "src/isolevel.h"
}

/*
static int readAtlas(GModel *gm, const char *atlasFilename, int dim[3],
                     int nvox, float *img)
{
  float mx = img[0];
  for(int i = 0; i <= nvox; i++) mx = fmax(img[i], mx);
  if(mx < 1.0) {
    printf("intensity range not consistent with an indexed atlas %g..%g\n",
           hdr.cal_min, hdr.cal_max);
    exit(EXIT_FAILURE);
  }
  int nLabel = trunc(mx);
  char basenm[mxStr], ext[mxStr] = "";
  // look for text file, e.g. atlas.nii.gz -> atlas.txt
#define kLabelStrLen 32
  typedef struct {
    char str[kLabelStrLen];
  } tstr;
  tstr *atlasLabels = (tstr *)malloc((nLabel + 1) * sizeof(tstr));
  // We need to use a struct to support MSVC C90, with gcc and clang:
  //   char atlasLabels[nLabel+1][kLabelStrLen];
  for(int i = 0; i <= nLabel; i++)
    snprintf(atlasLabels[i].str, kLabelStrLen - 1, "%d", i);
  if(strcmp("1", atlasFilename) != 0) {
    FILE *fp = fopen(atlasFilename, "rt");
    if(fp == NULL) {
      printf("Unable to find atlas names '%s'\n", atlasFilename);
    }
    else {
      char str[mxStr], s[mxStr];
      while(fgets(str, mxStr, fp)) {
        strncpy(s, strtok(str, ";"), mxStr);
        int i = atoi(s);
        if((i < 0) || (i > nLabel)) continue;
        strncpy(s, strtok(NULL, ";"), mxStr);
        int len =
          snprintf(atlasLabels[i].str, kLabelStrLen - 1, "%s.k%d", s, i);
        if(len < 0) Msg::Error("Error reading atlas file %s", atlasFilename);
        if(len < 1) continue;
        for(int j = 0; j < len; j++)
          if((atlasLabels[i].str[j] < 1) || (atlasLabels[i].str[j] == ' ') ||
             (atlasLabels[i].str[j] == ',') || (atlasLabels[i].str[j] == '/') ||
             (atlasLabels[i].str[j] == '\\') ||
             (atlasLabels[i].str[j] == '%') || (atlasLabels[i].str[j] == '*') ||
             (atlasLabels[i].str[j] == 9) || (atlasLabels[i].str[j] == 10) ||
             (atlasLabels[i].str[j] == 11) || (atlasLabels[i].str[j] == 13))
            atlasLabels[i].str[j] = '-';
      }
      fclose(fp);
    }
  }

  int nOK = 0;
  for(int i = 1; i <= nLabel; i++) {
    float *imgbinary = (float *)malloc(nvox * sizeof(float));
    int n1 = 0;
    float lo = i - 0.5;
    float hi = i + 0.5;
    for(int j = 0; j < nvox; j++) {
      int n = 0;
      if((img[j] > lo) && (img[j] < hi)) n = 1;
      imgbinary[j] = n;
      n1 += n;
    }
    if(n1 == 0) {
      Msg::Info("Skipping %d: no voxels with this intensity", i);
      continue;
    }

    GFace *face = new discreteFace(gm, gm->getMaxElementaryNumber(2) + 1);
    gm->add(face);

    //    atlasLabels[i].str;

    //    int reti = nii2(hdr, imgbinary, originalMC, 0.5, reduceFraction,
    //    preSmooth, onlyLargest, fillBubbles, postSmooth, verbose, outnm,
    //    quality);
    if(meshify(imgbinary, dim, originalMC, 0.5, &tris, &pts, &ntri, &npt,
               preSmooth, onlyLargest, fillBubbles, 0) != EXIT_SUCCESS)
      continue;

    nOK++;
    free(imgbinary);
  } // for nLabel

  free(atlasLabels);
  Msg::Info("Converted %d regions of interest", nOK);
}
*/

int GModel::readNII(const std::string &name, float isolevel,
                    int isoDarkMediumBright123, float reduceFraction,
                    int preSmooth, bool onlyLargest, bool fillBubbles,
                    int postSmooth)
{
  nifti_1_header hdr;
  float *img = load_nii(name.c_str(), &hdr);
  int nvox = (hdr.dim[1] * hdr.dim[2] * hdr.dim[3]);
  if(isoDarkMediumBright123 !=
     0) // user did not provide numeric isosurface brightness
    isolevel = setThreshold(img, nvox, isoDarkMediumBright123);
  vec3d *pts = NULL;
  vec3i *tris = NULL;
  int ntri, npt;
  size_t dim[3] = {(size_t)hdr.dim[1], (size_t)hdr.dim[2], (size_t)hdr.dim[3]};
  int originalMC = 0;
  // marching cubes...
  if(meshify(img, dim, originalMC, isolevel, &tris, &pts, &ntri, &npt,
             preSmooth, onlyLargest, fillBubbles, 0) != EXIT_SUCCESS)
    return -1;

  int quality = 2;

  apply_sform(tris, pts, ntri, npt, hdr.srow_x, hdr.srow_y, hdr.srow_z);
  if(postSmooth > 0)
    laplacian_smoothHC(pts, tris, npt, ntri, 0.1, 0.5, postSmooth, true);
  if((reduceFraction < 1.0) || (quality > 1)) { // lossless for high quality
    double agressiveness = 7.0; // 7 = default for Simplify.h
    if(quality == 0) // fast
      agressiveness = 8.0;
    if(quality == 2) // best
      agressiveness = 5.0;
    int target_count = round((float)ntri * reduceFraction);
    quadric_simplify_mesh(&pts, &tris, &npt, &ntri, target_count, agressiveness,
                          0, (quality > 1));
  }

  GFace *face = new discreteFace(this, getMaxElementaryNumber(2) + 1);
  add(face);

  std::vector<MVertex *> vertices;

  for(int i = 0; i < npt; i++)
    vertices.push_back(new MVertex(pts[i].x, pts[i].y, pts[i].z));

  for(int i = 0; i < ntri; i++)
    face->triangles.push_back(new MTriangle(
      vertices[tris[i].x], vertices[tris[i].y], vertices[tris[i].z]));

  _associateEntityWithMeshVertices();

  _storeVerticesInEntities(vertices); // will delete unused vertices

  free(tris);
  free(pts);
  return 1;
}

#else

int GModel::readNII(const std::string &name, float isolevel,
                    int isoDarkMediumBright123, float reduceFraction,
                    int preSmooth, bool onlyLargest, bool fillBubbles,
                    int postSmooth)
{
  Msg::Warning("Gmsh must be compiled with nifti to load  Neuroimaging "
               "Informatics Technology Initiative (NII) files");
  return -1;
}

#endif
