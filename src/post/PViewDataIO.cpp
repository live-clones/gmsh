// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <cstdio>
#include <memory>
#include <stdio.h>
#include <string.h>
#include "Camera.h"
#include "GmshMessage.h"
#include "GmshDefines.h"
#include "Numeric.h"
#include "PViewData.h"
#include "PViewOptions.h"
#include "adaptiveData.h"
#include "OS.h"
#include "FLGui.h"
#include "openglWindow.h"
#include "Context.h"

bool PViewData::writeSTL(const std::string &fileName)
{
  FILE *fp = Fopen(fileName.c_str(), "w");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", fileName.c_str());
    return false;
  }

  if(!getNumTriangles() && !getNumQuadrangles()) {
    Msg::Error("No surface elements to save");
    fclose(fp);
    return false;
  }

  int step = getFirstNonEmptyTimeStep();

  fprintf(fp, "solid Created by Gmsh\n");
  for(int ent = 0; ent < getNumEntities(step); ent++) {
    for(int ele = 0; ele < getNumElements(step, ent); ele++) {
      if(getDimension(step, ent, ele) != 2) continue;
      if(skipElement(step, ent, ele)) continue;
      int N = getNumNodes(step, ent, ele);
      if(N != 3 && N != 4) continue;
      double x[4], y[4], z[4], n[3];
      for(int i = 0; i < N; i++) getNode(step, ent, ele, i, x[i], y[i], z[i]);
      normal3points(x[0], y[0], z[0], x[1], y[1], z[1], x[2], y[2], z[2], n);
      if(N == 3) {
        fprintf(fp, "facet normal %g %g %g\n", n[0], n[1], n[2]);
        fprintf(fp, "  outer loop\n");
        fprintf(fp, "    vertex %g %g %g\n", x[0], y[0], z[0]);
        fprintf(fp, "    vertex %g %g %g\n", x[1], y[1], z[1]);
        fprintf(fp, "    vertex %g %g %g\n", x[2], y[2], z[2]);
        fprintf(fp, "  endloop\n");
        fprintf(fp, "endfacet\n");
      }
      else {
        fprintf(fp, "facet normal %g %g %g\n", n[0], n[1], n[2]);
        fprintf(fp, "  outer loop\n");
        fprintf(fp, "    vertex %g %g %g\n", x[0], y[0], z[0]);
        fprintf(fp, "    vertex %g %g %g\n", x[1], y[1], z[1]);
        fprintf(fp, "    vertex %g %g %g\n", x[2], y[2], z[2]);
        fprintf(fp, "  endloop\n");
        fprintf(fp, "endfacet\n");
        fprintf(fp, "facet normal %g %g %g\n", n[0], n[1], n[2]);
        fprintf(fp, "  outer loop\n");
        fprintf(fp, "    vertex %g %g %g\n", x[0], y[0], z[0]);
        fprintf(fp, "    vertex %g %g %g\n", x[2], y[2], z[2]);
        fprintf(fp, "    vertex %g %g %g\n", x[3], y[3], z[3]);
        fprintf(fp, "  endloop\n");
        fprintf(fp, "endfacet\n");
      }
    }
  }
  fprintf(fp, "endsolid Created by Gmsh\n");

  fclose(fp);
  return true;
}

static const std::string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                        "abcdefghijklmnopqrstuvwxyz"
                                        "0123456789+/";

std::string base64_encode(const unsigned char *data, size_t len)
{
  std::string out;
  out.reserve(((len + 2) / 3) * 4);

  for(size_t i = 0; i < len; i += 3) {
    unsigned int val = 0;
    int count = 0;

    for(int j = 0; j < 3; j++) {
      val <<= 8;
      if(i + j < len) {
        val |= data[i + j];
        count++;
      }
    }

    for(int j = 0; j < 4; j++) {
      if(j <= count)
        out.push_back(base64_chars[(val >> (18 - 6 * j)) & 0x3F]);
      else
        out.push_back('=');
    }
  }

  return out;
}

inline void writeBuffer(FILE *fp, unsigned buffer, unsigned offset,
                        unsigned byteLength, unsigned target)
{
  fprintf(fp, "    {\n");
  fprintf(fp, "      \"buffer\" : %d,\n", buffer);
  fprintf(fp, "      \"byteOffset\" : %d,\n", offset);
  fprintf(fp, "      \"byteLength\" : %d,\n", byteLength);
  fprintf(fp, "      \"target\" : %d\n", target);
  fprintf(fp, "    }");
}

inline void writeBufferView(FILE *fp, unsigned bufferView,
                            unsigned componentType, unsigned count, char *type,
                            char *max = nullptr, char *min = nullptr)
{
  fprintf(fp, "    {\n");
  fprintf(fp, "      \"bufferView\" : %d,\n", bufferView);
  fprintf(fp, "      \"byteOffset\" : 0,\n");
  fprintf(fp, "      \"componentType\" : %d,\n", componentType);
  fprintf(fp, "      \"count\" : %d,\n", count);
  fprintf(fp, "      \"type\" : %s", type);
  if(max) fprintf(fp, ",\n      \"max\" : [ %s ]", max);
  if(min) fprintf(fp, ",\n      \"min\" : [ %s ]", min);
  fprintf(fp, "\n    }");
}

bool PViewData::writeGLTF(const std::string &fileName, PView *pv)
{
  FILE *fp = Fopen(fileName.c_str(), "w");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", fileName.c_str());
    return false;
  }

  // if(!getNumTriangles() && !getNumQuadrangles()) {
  // if(!getNumTriangles()) {
  //   Msg::Error("No surface elements to save");
  //   fclose(fp);
  //   return false;
  // }

  int step = getFirstNonEmptyTimeStep();

  // Camera
  drawContext *dc =
    FlGui::instance()->getCurrentOpenglWindow()->getDrawContext();
  double clip_near, clip_far;
  {
    double zmax =
      std::max(fabs(CTX::instance()->min[2]), fabs(CTX::instance()->max[2]));
    if(zmax < CTX::instance()->lc) zmax = CTX::instance()->lc;
    if(CTX::instance()->ortho) {
      clip_near = -zmax * dc->s[2] * CTX::instance()->clipFactor;
      clip_far = -clip_near;
    }
    else {
      clip_near = 0.75 * CTX::instance()->clipFactor * zmax;
      clip_far = 75. * CTX::instance()->clipFactor * zmax;
    }
  }
  double coef = (clip_far / clip_near) / 3.;

  unsigned counterPoint = 0, counterLine = 0, counterTriangle = 0;
  std::vector<unsigned char> bufferPoint, bufferPointPosition, bufferPointColor;
  std::vector<unsigned char> bufferLine, bufferLinePosition, bufferLineColor;
  std::vector<unsigned char> bufferTriangle, bufferTrianglePosition,
    bufferTriangleColor;
  unsigned char *pf;

  float xminTriangle = +1e100, xmaxTriangle = -1e100;
  float yminTriangle = +1e100, ymaxTriangle = -1e100;
  float zminTriangle = +1e100, zmaxTriangle = -1e100;
  float valminTriangle = +1e100, valmaxTriangle = -1e100;
  float xminLine = +1e100, xmaxLine = -1e100;
  float yminLine = +1e100, ymaxLine = -1e100;
  float zminLine = +1e100, zmaxLine = -1e100;
  float valminLine = +1e100, valmaxLine = -1e100;
  float xminPoint = +1e100, xmaxPoint = -1e100;
  float yminPoint = +1e100, ymaxPoint = -1e100;
  float zminPoint = +1e100, zmaxPoint = -1e100;
  float valminPoint = +1e100, valmaxPoint = -1e100;
  PViewOptions *opt = pv->getOptions();
  double vmin = opt->tmpMin, vmax = opt->tmpMax;

  for(int ent = 0; ent < getNumEntities(step); ent++) {
    for(int ele = 0; ele < getNumElements(step, ent); ele++) {
      if(skipElement(step, ent, ele)) continue;
      int type = getType(step, ent, ele);
      int numComp = getNumComponents(step, ent, ele);
      switch(type) {
      case TYPE_PNT: break;
      case TYPE_LIN: break;
      case TYPE_TRI: break;
      default:
        Msg::Warning("Only Points, Lines and Triangles can be exported in GLTF "
                     "format (type: %d)",
                     type);
        continue;
      }

      if(numComp != 1) {
        Msg::Warning(
          "Only Scalars can be exported in GLTF format (numComp: %d)", numComp);
        continue;
      }

      int N = getNumNodes(step, ent, ele);
      double x, y, z, val;
      bool skip = false;
      for(int i = 0; i < N; ++i) {
        getNode(step, ent, ele, i, x, y, z);
        getValue(step, ent, ele, i, val);
        if(val < vmin || val > vmax) {
          skip = true;
          break;
        }
      }
      if(skip) continue;
      for(int i = 0; i < N; ++i) {
        getNode(step, ent, ele, i, x, y, z);
        getValue(step, ent, ele, i, val);

        float fxyz[3] = {(float)x, (float)z, (float)-y};
        float fval = (float)val;

        unsigned int color = opt->getColor(val, vmin, vmax, false, opt->nbIso);
        unsigned char *rgba = reinterpret_cast<unsigned char *>(&color);
        if(val < vmin || val > vmax) rgba[3] = 0;
        float frgba[4] = {(float)rgba[0] / 255, (float)rgba[1] / 255,
                          (float)rgba[2] / 255, (float)rgba[3] / 255};

        if(N == 1) {
          if(fxyz[0] < xminPoint) xminPoint = fxyz[0];
          if(fxyz[0] > xmaxPoint) xmaxPoint = fxyz[0];
          if(fxyz[1] < yminPoint) yminPoint = fxyz[1];
          if(fxyz[1] > ymaxPoint) ymaxPoint = fxyz[1];
          if(fxyz[2] < zminPoint) zminPoint = fxyz[2];
          if(fxyz[2] > zmaxPoint) zmaxPoint = fxyz[2];
          if(fval < valminPoint) valminPoint = fval;
          if(fval > valmaxPoint) valmaxPoint = fval;
          pf = reinterpret_cast<unsigned char *>(&counterPoint);
          bufferPoint.insert(bufferPoint.end(), pf, pf + sizeof(counterPoint));
          ++counterPoint;
          pf = reinterpret_cast<unsigned char *>(fxyz);
          bufferPointPosition.insert(bufferPointPosition.end(), pf,
                                     pf + 3 * sizeof(float));

          pf = reinterpret_cast<unsigned char *>(frgba);
          bufferPointColor.insert(bufferPointColor.end(), pf,
                                  pf + 4 * sizeof(float));
        }
        else if(N == 2) {
          if(fxyz[0] < xminLine) xminLine = fxyz[0];
          if(fxyz[0] > xmaxLine) xmaxLine = fxyz[0];
          if(fxyz[1] < yminLine) yminLine = fxyz[1];
          if(fxyz[1] > ymaxLine) ymaxLine = fxyz[1];
          if(fxyz[2] < zminLine) zminLine = fxyz[2];
          if(fxyz[2] > zmaxLine) zmaxLine = fxyz[2];
          if(fval < valminLine) valminLine = fval;
          if(fval > valmaxLine) valmaxLine = fval;
          pf = reinterpret_cast<unsigned char *>(&counterLine);
          bufferLine.insert(bufferLine.end(), pf, pf + sizeof(counterLine));
          ++counterLine;
          pf = reinterpret_cast<unsigned char *>(fxyz);
          bufferLinePosition.insert(bufferLinePosition.end(), pf,
                                    pf + 3 * sizeof(float));
          pf = reinterpret_cast<unsigned char *>(frgba);
          bufferLineColor.insert(bufferLineColor.end(), pf,
                                 pf + 4 * sizeof(float));
        }
        if(N == 3) {
          if(fxyz[0] < xminTriangle) xminTriangle = fxyz[0];
          if(fxyz[0] > xmaxTriangle) xmaxTriangle = fxyz[0];
          if(fxyz[1] < yminTriangle) yminTriangle = fxyz[1];
          if(fxyz[1] > ymaxTriangle) ymaxTriangle = fxyz[1];
          if(fxyz[2] < zminTriangle) zminTriangle = fxyz[2];
          if(fxyz[2] > zmaxTriangle) zmaxTriangle = fxyz[2];
          if(fval < valminTriangle) valminTriangle = fval;
          if(fval > valmaxTriangle) valmaxTriangle = fval;
          pf = reinterpret_cast<unsigned char *>(&counterTriangle);
          bufferTriangle.insert(bufferTriangle.end(), pf,
                                pf + sizeof(counterTriangle));
          ++counterTriangle;
          pf = reinterpret_cast<unsigned char *>(fxyz);
          bufferTrianglePosition.insert(bufferTrianglePosition.end(), pf,
                                        pf + 3 * sizeof(float));

          pf = reinterpret_cast<unsigned char *>(frgba);
          bufferTriangleColor.insert(bufferTriangleColor.end(), pf,
                                     pf + 4 * sizeof(float));
        }
      }
    }
  }

  fprintf(fp, "{\n  \"scene\": 0,\n");
  fprintf(fp, "  \"scenes\" :\n");
  fprintf(fp, "  [\n");
  fprintf(fp, "    {\n");
  fprintf(fp, "      \"nodes\" : [ 0 ]\n");
  // fprintf(fp, "      \"nodes\" : [ 0, 1 ]\n");
  fprintf(fp, "    }\n");
  fprintf(fp, "  ],\n");
  fprintf(fp, "  \"nodes\" :\n");
  fprintf(fp, "  [\n");
  fprintf(fp, "    {\n");
  fprintf(fp, "      \"mesh\" : 0\n");
  fprintf(fp, "    }\n");
  fprintf(fp, "  ],\n");
  // fprintf(fp, "    },\n");
  // fprintf(fp, "    {\n");
  // {
  //   double zmax =
  //     std::max(fabs(CTX::instance()->min[2]),
  //     fabs(CTX::instance()->max[2]));
  //   if(zmax < CTX::instance()->lc) zmax = CTX::instance()->lc;
  //   if(CTX::instance()->ortho) {
  //     clip_near = -zmax * dc->s[2] * CTX::instance()->clipFactor;
  //     clip_far = -clip_near;
  //   }
  //   else {
  //     clip_near = 0.75 * CTX::instance()->clipFactor * zmax;
  //     clip_far = 75. * CTX::instance()->clipFactor * zmax;
  //   }
  // }
  // fprintf(fp, "      \"translation\" : [ %lf, %lf, %lf ],\n",
  //         -coef * dc->t_init[0] - dc->t[0], +coef * clip_near + dc->t[2],
  //         -coef * dc->t_init[1] + dc->t[1]);
  // double z = dc->r[0] / 180 * M_PI - M_PI / 2;
  // double y = -dc->r[1] / 180 * M_PI;
  // double x = dc->r[2] / 180 * M_PI;
  // double cx = cos(x * 0.5);
  // double sx = sin(x * 0.5);
  // double cy = cos(y * 0.5);
  // double sy = sin(y * 0.5);
  // double cz = cos(z * 0.5);
  // double sz = sin(z * 0.5);
  // double q[4] = {cx * cy * cz - sx * sy * sz, sx * cy * cz + cx * sy * sz,
  //                cx * sy * cz - sx * cy * sz, cx * cy * sz + sx * sy * cz};
  //
  // fprintf(fp, "      \"rotation\" : [ %lf, %lf, %lf, %lf ],\n", q[0], q[1],
  //         q[2], q[3]);
  // fprintf(fp, "      \"camera\" : 0\n");
  // fprintf(fp, "    }\n");
  // fprintf(fp, "  ],\n");
  // fprintf(fp, "  \"cameras\" : [\n");
  // fprintf(fp, "    {\n");
  // fprintf(fp, "      \"type\": \"orthographic\",\n");
  // fprintf(fp, "      \"orthographic\": {\n");
  // fprintf(fp, "        \"xmag\": 1.0,\n");
  // fprintf(fp, "        \"ymag\": 1.0,\n");
  // fprintf(fp, "        \"zfar\": %lf,\n", clip_far);
  // fprintf(fp, "        \"znear\": %lf\n", clip_near);
  // fprintf(fp, "      }\n");
  // fprintf(fp, "    }\n");
  // fprintf(fp, "  ],\n");
  fprintf(fp, "  \"meshes\" : [\n");
  fprintf(fp, "    {\n");
  fprintf(fp, "      \"primitives\" : [\n");
  unsigned bufferIndex = 0;
  if(counterTriangle) {
    fprintf(fp, "        {\n");
    fprintf(fp, "          \"attributes\" : {\n");
    fprintf(fp, "            \"POSITION\" : %d,\n", ++bufferIndex);
    fprintf(fp, "            \"COLOR_0\" : %d\n", ++bufferIndex);
    fprintf(fp, "          },\n");
    fprintf(fp, "          \"indices\" : %d\n", ++bufferIndex - 3);
    // fprintf(fp, "          \"material\" : 0\n");
    fprintf(fp, "        }");
  }
  if(counterLine) {
    if(counterTriangle) fprintf(fp, ",");
    fprintf(fp, "\n        {\n");
    fprintf(fp, "          \"attributes\" : {\n");
    fprintf(fp, "            \"POSITION\" : %d,\n", ++bufferIndex);
    fprintf(fp, "            \"COLOR_0\" : %d\n", ++bufferIndex);
    fprintf(fp, "          },\n");
    fprintf(fp, "          \"mode\" : 1,\n");
    fprintf(fp, "          \"indices\" : %d\n", ++bufferIndex - 3);
    // fprintf(fp, "          \"material\" : 0\n");
    fprintf(fp, "        }");
  }
  if(counterPoint) {
    if(counterTriangle || counterLine) fprintf(fp, ",");
    fprintf(fp, "\n        {\n");
    fprintf(fp, "          \"attributes\" : {\n");
    fprintf(fp, "            \"POSITION\" : %d,\n", ++bufferIndex);
    fprintf(fp, "            \"COLOR_0\" : %d\n", ++bufferIndex);
    fprintf(fp, "          },\n");
    fprintf(fp, "          \"mode\" : 0,\n");
    fprintf(fp, "          \"indices\" : %d\n", ++bufferIndex - 3);
    // fprintf(fp, "          \"material\" : 0\n");
    fprintf(fp, "        }");
  }
  fprintf(fp, "\n");
  fprintf(fp, "      ]\n");
  fprintf(fp, "   }\n");
  fprintf(fp, "  ],\n");
  // fprintf(fp, "  \"materials\": [\n");
  // fprintf(fp, "    {\n");
  // // fprintf(fp, "      \"doubleSided\":true,\n");
  // fprintf(fp, "      \"pbrMetallicRoughness\":\n");
  // fprintf(fp, "      {\n");
  // fprintf(fp, "        \"metallicFactor\":0,\n");
  // fprintf(fp, "        \"roughnessFactor\":0.5\n");
  // fprintf(fp, "      },\n");
  // fprintf(fp, "      \"alphaMode\": \"OPAQUE\"\n");
  // fprintf(fp, "    }\n");
  // fprintf(fp, "  ],\n");
  fprintf(fp, "  \"buffers\" : [\n");
  fprintf(fp, "    {\n");
  fprintf(fp, R"(
    "uri" : "data:application/octet-stream;base64,)");

  std::vector<unsigned char> buffer;
  unsigned sizeTriangles = sizeof(unsigned) * counterTriangle;
  unsigned sizeTrianglePosition = 3 * sizeof(float) * counterTriangle;
  unsigned sizeTriangleColor = 4 * sizeof(float) * counterTriangle;
  unsigned sizeLine = sizeof(unsigned) * counterLine;
  unsigned sizeLinePosition = 3 * sizeof(float) * counterLine;
  unsigned sizeLineColor = 4 * sizeof(float) * counterLine;
  unsigned sizePoint = sizeof(unsigned) * counterPoint;
  unsigned sizePointPosition = 3 * sizeof(float) * counterPoint;
  unsigned sizePointColor = 4 * sizeof(float) * counterPoint;

  // Triangles
  buffer.insert(buffer.end(), bufferTriangle.begin(), bufferTriangle.end());
  buffer.insert(buffer.end(), bufferTrianglePosition.begin(),
                bufferTrianglePosition.end());
  buffer.insert(buffer.end(), bufferTriangleColor.begin(),
                bufferTriangleColor.end());
  // Line
  buffer.insert(buffer.end(), bufferLine.begin(), bufferLine.end());
  buffer.insert(buffer.end(), bufferLinePosition.begin(),
                bufferLinePosition.end());
  buffer.insert(buffer.end(), bufferLineColor.begin(), bufferLineColor.end());

  // Points
  buffer.insert(buffer.end(), bufferPoint.begin(), bufferPoint.end());
  buffer.insert(buffer.end(), bufferPointPosition.begin(),
                bufferPointPosition.end());
  buffer.insert(buffer.end(), bufferPointColor.begin(), bufferPointColor.end());

  std::string encoded = base64_encode(buffer.data(), buffer.size());
  fprintf(fp, "%s", encoded.c_str());

  fprintf(fp, R"(",
      "byteLength" : )");

  fprintf(fp, "%d",
          sizeTriangles + sizeTrianglePosition + sizeTriangleColor + sizeLine +
            sizeLinePosition + sizeLineColor + sizePoint + sizePointPosition +
            sizePointColor);
  fprintf(fp, R"(
    }
  ],
  "bufferViews" : [
)");
  unsigned numBuffer = 0;
  unsigned offset = 0;
  if(counterTriangle) {
    writeBuffer(fp, numBuffer, offset, sizeTriangles, 34963);
    offset += sizeTriangles;

    fprintf(fp, ",\n");
    writeBuffer(fp, numBuffer, offset, sizeTrianglePosition, 34962);
    offset += sizeTrianglePosition;
    fprintf(fp, ",\n");
    writeBuffer(fp, numBuffer, offset, sizeTriangleColor, 34962);
    offset += sizeTriangleColor;
  }
  if(counterLine) {
    if(counterTriangle) fprintf(fp, ",");
    fprintf(fp, "\n");
    writeBuffer(fp, numBuffer, offset, sizeLine, 34963);
    offset += sizeLine;
    fprintf(fp, ",\n");
    writeBuffer(fp, numBuffer, offset, sizeLinePosition, 34962);
    offset += sizeLinePosition;
    fprintf(fp, ",\n");
    writeBuffer(fp, numBuffer, offset, sizeLineColor, 34962);
    offset += sizeLineColor;
  }
  if(counterPoint) {
    if(counterTriangle || counterLine) fprintf(fp, ",");
    fprintf(fp, "\n");
    writeBuffer(fp, numBuffer, offset, sizePoint, 34963);
    offset += sizePoint;
    fprintf(fp, ",\n");
    writeBuffer(fp, numBuffer, offset, sizePointPosition, 34962);
    offset += sizePointPosition;
    fprintf(fp, ",\n");
    writeBuffer(fp, numBuffer, offset, sizePointColor, 34962);
    offset += sizePointColor;
  }
  fprintf(fp, R"(
  ],
  "accessors" : [
)");

  char max[256], min[256], type[256];
  snprintf(type, sizeof(type), "\"SCALAR\"");
  snprintf(max, sizeof(max), "%d", counterTriangle - 1);
  snprintf(min, sizeof(min), "%d", 0);
  unsigned bufferView = 0;
  if(counterTriangle) {
    writeBufferView(fp, bufferView++, 5125, counterTriangle, type, max, min);
    fprintf(fp, ",\n");
    snprintf(type, sizeof(type), "\"VEC3\"");
    snprintf(max, sizeof(max), "%.9f, %.9f, %.9f", xmaxTriangle, ymaxTriangle,
             zmaxTriangle);
    snprintf(min, sizeof(min), "%.9f, %.9f, %.9f", xminTriangle, yminTriangle,
             zminTriangle);
    writeBufferView(fp, bufferView++, 5126, counterTriangle, type, max, min);
    fprintf(fp, ",\n");
    snprintf(type, sizeof(type), "\"VEC4\"");
    writeBufferView(fp, bufferView++, 5126, counterTriangle, type);
  }
  if(counterLine) {
    if(counterTriangle) fprintf(fp, ",");
    fprintf(fp, "\n");
    snprintf(type, sizeof(type), "\"SCALAR\"");
    snprintf(max, sizeof(max), "%d", counterLine - 1);
    snprintf(min, sizeof(min), "%d", 0);
    writeBufferView(fp, bufferView++, 5125, counterLine, type, max, min);
    fprintf(fp, ",\n");
    snprintf(type, sizeof(type), "\"VEC3\"");
    snprintf(max, sizeof(max), "%.9f, %.9f, %.9f", xmaxLine, ymaxLine,
             zmaxLine);
    snprintf(min, sizeof(min), "%.9f, %.9f, %.9f", xminLine, yminLine,
             zminLine);
    writeBufferView(fp, bufferView++, 5126, counterLine, type, max, min);
    fprintf(fp, ",\n");
    snprintf(type, sizeof(type), "\"VEC4\"");
    writeBufferView(fp, bufferView++, 5126, counterLine, type);
  }
  if(counterPoint) {
    if(counterTriangle || counterLine) fprintf(fp, ",");
    fprintf(fp, "\n");
    snprintf(type, sizeof(type), "\"SCALAR\"");
    snprintf(max, sizeof(max), "%d", counterPoint - 1);
    snprintf(min, sizeof(min), "%d", 0);
    writeBufferView(fp, bufferView++, 5125, counterPoint, type, max, min);
    fprintf(fp, ",\n");
    snprintf(type, sizeof(type), "\"VEC3\"");
    snprintf(max, sizeof(max), "%.9f, %.9f, %.9f", xmaxPoint, ymaxPoint,
             zmaxPoint);
    snprintf(min, sizeof(min), "%.9f, %.9f, %.9f", xminPoint, yminPoint,
             zminPoint);
    writeBufferView(fp, bufferView++, 5126, counterPoint, type, max, min);
    fprintf(fp, ",\n");
    snprintf(type, sizeof(type), "\"VEC4\"");
    writeBufferView(fp, bufferView++, 5126, counterPoint, type);
  }
  fprintf(fp, R"(
  ],
  
  "asset" : {
    "version" : "2.0"
  }
}
)");

  fclose(fp);
  return true;
}

bool PViewData::writeTXT(const std::string &fileName)
{
  FILE *fp = Fopen(fileName.c_str(), "w");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", fileName.c_str());
    return false;
  }

  for(int step = 0; step < getNumTimeSteps(); step++) {
    for(int ent = 0; ent < getNumEntities(step); ent++) {
      for(int ele = 0; ele < getNumElements(step, ent); ele++) {
        if(skipElement(step, ent, ele)) continue;
        for(int nod = 0; nod < getNumNodes(step, ent, ele); nod++) {
          double x, y, z;
          getNode(step, ent, ele, nod, x, y, z);
          fprintf(fp, "%d %.16g %d %d %.16g %.16g %.16g ", step, getTime(step),
                  ent, ele, x, y, z);
          for(int comp = 0; comp < getNumComponents(step, ent, ele); comp++) {
            double val;
            getValue(step, ent, ele, nod, comp, val);
            fprintf(fp, "%.16g ", val);
          }
        }
        fprintf(fp, "\n");
      }
    }
  }

  fclose(fp);
  return true;
}

bool PViewData::writePOS(const std::string &fileName, bool binary, bool parsed,
                         bool append)
{
  if(_adaptive) {
    Msg::Warning(
      "Writing adapted dataset (will only export current time step)");
    return _adaptive->getData()->writePOS(fileName, binary, parsed, append);
  }
  if(hasMultipleMeshes()) {
    Msg::Error("Cannot export multi-mesh datasets in .pos format");
    return false;
  }
  if(haveInterpolationMatrices())
    Msg::Warning(
      "Discarding interpolation matrices when saving in .pos format");
  if(binary || !parsed)
    Msg::Warning("Only parsed .pos files can be exported for this view type");

  FILE *fp = Fopen(fileName.c_str(), append ? "a" : "w");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", fileName.c_str());
    return false;
  }

  fprintf(fp, "View \"%s\" {\n", getName().c_str());

  int firstNonEmptyStep = getFirstNonEmptyTimeStep();
  for(int ent = 0; ent < getNumEntities(firstNonEmptyStep); ent++) {
    for(int ele = 0; ele < getNumElements(firstNonEmptyStep, ent); ele++) {
      if(skipElement(firstNonEmptyStep, ent, ele)) continue;
      int type = getType(firstNonEmptyStep, ent, ele);
      int numComp = getNumComponents(firstNonEmptyStep, ent, ele);
      const char *s = nullptr;
      switch(type) {
      case TYPE_PNT:
        s = (numComp == 9) ? "TP" : (numComp == 3) ? "VP" : "SP";
        break;
      case TYPE_LIN:
        s = (numComp == 9) ? "TL" : (numComp == 3) ? "VL" : "SL";
        break;
      case TYPE_TRI:
        s = (numComp == 9) ? "TT" : (numComp == 3) ? "VT" : "ST";
        break;
      case TYPE_QUA:
        s = (numComp == 9) ? "TQ" : (numComp == 3) ? "VQ" : "SQ";
        break;
      case TYPE_TET:
        s = (numComp == 9) ? "TS" : (numComp == 3) ? "VS" : "SS";
        break;
      case TYPE_HEX:
        s = (numComp == 9) ? "TH" : (numComp == 3) ? "VH" : "SH";
        break;
      case TYPE_PRI:
        s = (numComp == 9) ? "TI" : (numComp == 3) ? "VI" : "SI";
        break;
      case TYPE_PYR:
        s = (numComp == 9) ? "TY" : (numComp == 3) ? "VY" : "SY";
        break;
      }
      if(s) {
        fprintf(fp, "%s(", s);
        int numNod = getNumNodes(firstNonEmptyStep, ent, ele);
        for(int nod = 0; nod < numNod; nod++) {
          double x, y, z;
          getNode(firstNonEmptyStep, ent, ele, nod, x, y, z);
          fprintf(fp, "%.16g,%.16g,%.16g", x, y, z);
          if(nod != numNod - 1) fprintf(fp, ",");
        }
        bool first = true;
        for(int step = 0; step < getNumTimeSteps(); step++) {
          if(hasTimeStep(step)) {
            for(int nod = 0; nod < numNod; nod++) {
              for(int comp = 0; comp < numComp; comp++) {
                double val = 0.0;
                getValue(step, ent, ele, nod, comp, val);
                if(first) {
                  fprintf(fp, "){%.16g", val);
                  first = false;
                }
                else
                  fprintf(fp, ",%.16g", val);
              }
            }
          }
        }
        fprintf(fp, "};\n");
      }
    }
  }

  fprintf(fp, "};\n");
  fclose(fp);

  return true;
}

bool PViewData::writeMSH(const std::string &fileName, double version,
                         bool binary, bool saveMesh, bool multipleView,
                         int partitionNum, bool saveInterpolationMatrices,
                         bool forceNodeData, bool forceElementData)
{
  Msg::Error("MSH export not implemented for this view type");
  return false;
}

bool PViewData::writeMED(const std::string &fileName)
{
  Msg::Error("MED export only available for mesh-based post-processing views");
  return false;
}

bool PViewData::toVector(std::vector<std::vector<double>> &vec)
{
  vec.resize(getNumTimeSteps());
  for(int step = 0; step < getNumTimeSteps(); step++) {
    vec[step].clear();
    for(int ent = 0; ent < getNumEntities(step); ent++) {
      for(int ele = 0; ele < getNumElements(step, ent); ele++) {
        if(skipElement(step, ent, ele)) continue;
        for(int nod = 0; nod < getNumNodes(step, ent, ele); nod++) {
          for(int comp = 0; comp < getNumComponents(step, ent, ele); comp++) {
            double val;
            getValue(step, ent, ele, nod, comp, val);
            vec[step].push_back(val);
          }
        }
      }
    }
  }
  return true;
}

bool PViewData::fromVector(const std::vector<std::vector<double>> &vec)
{
  if(empty() || !getNumTimeSteps()) {
    Msg::Warning("Cannot import vector in an empty view; skipping");
    return false;
  }

  if((int)vec.size() != getNumTimeSteps()) {
    Msg::Error(
      "Incompatible number of steps in vector for view import (%d!=%d)",
      (int)vec.size(), getNumTimeSteps());
    return false;
  }

  for(int step = 0; step < getNumTimeSteps(); step++) {
    int i = 0;
    for(int ent = 0; ent < getNumEntities(step); ent++) {
      for(int ele = 0; ele < getNumElements(step, ent); ele++) {
        if(skipElement(step, ent, ele)) continue;
        for(int nod = 0; nod < getNumNodes(step, ent, ele); nod++) {
          double x, y, z;
          getNode(step, ent, ele, nod, x, y, z);
          for(int comp = 0; comp < getNumComponents(step, ent, ele); comp++) {
            if(i < (int)vec[step].size()) {
              setValue(step, ent, ele, nod, comp, vec[step][i++]);
            }
            else {
              Msg::Error("Bad index (%d) in vector (%d) for view import", i,
                         (int)vec[step].size());
              return false;
            }
          }
        }
      }
    }
  }
  return true;
}

void PViewData::importLists(int N[24], std::vector<double> *V[24])
{
  Msg::Error("importLists not available for this view data type");
}

void PViewData::getListPointers(int N[24], std::vector<double> *V[24])
{
  Msg::Error("getListPointers not available for this view data type");
}

void PViewData::sendToServer(const std::string &name)
{
  // Vectorize
  std::vector<std::vector<double>> vec;
  bool ok = toVector(vec);

  // Success ?
  if(!ok) Msg::Error("sendToServer: cannot vectorize PView");

  // Only one step ?
  if(vec.size() != 1)
    Msg::Error("sendToServer: cannot send a PView with more than one step");

  // Only one data ?
  if(vec[0].size() != 1)
    Msg::Error("sendToServer: cannot send a PView with more than one data");

  // Send data
  Msg::SetOnelabNumber(name, vec[0][0]);
}
