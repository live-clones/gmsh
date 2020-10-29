#ifndef HXT_POS_DEBUGGING_H
#define HXT_POS_DEBUGGING_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdarg.h>

// #define DUMP(varname, format) fprintf(stderr, "(DUMP) %s = " format "\n", #varname, varname);
// #define DUMP_I(varname) fprintf(stderr, "(DUMP) %s = %i\n", #varname, varname);
// #define DUMP_F(varname) fprintf(stderr, "(DUMP) %s = %.3f\n", #varname, varname);
// #define DUMP_LI(varname) fprintf(stderr, "(DUMP) %s = %li\n", #varname, varname);
// #define DUMP_S(varname) fprintf(stderr, "(DUMP) %s = %s\n", #varname, varname);

/* compatible HXTStatus return values */
static const int HXT_POS_OK = 0;
static const int HXT_POS_WRITE_ERROR = -8;

/* 
 * Debugging via .geo files 
 * Example:
 *   FILE* fp;
 *   hxtGeoInit("/tmp/debug.geo", &fp);
 *   for (int i ...) {
 *     ...
 *     hxtGeoAddSphere(fp, i, &(pts[4*i]), radius[i]);
 *   }
 *   hxtGeoFinish(fp);
 */

static inline int hxtGeoInit(const char* path, FILE** fpp) {
  *fpp = fopen(path, "w");
  if (*fpp == NULL) return HXT_POS_WRITE_ERROR;
  fprintf(*fpp, "SetFactory(\"OpenCASCADE\");\n\n");
  return HXT_POS_OK;
}

static inline int hxtGeoFinish(FILE* fp) {
  if (fprintf(fp, "\n") < 0) return HXT_POS_WRITE_ERROR;
  fclose(fp);
  return HXT_POS_OK;
}

static inline int hxtGeoAddSphere(FILE* fp, int id, const double* p, double radius) {
  if (fprintf(fp, "Sphere(%i) = {%.6f,%.6f,%.6f,%.6f};\n", id, p[0], p[1], p[2], radius) < 0) {
    return HXT_POS_WRITE_ERROR;
  };
  return HXT_POS_OK;
}

//static inline int hxtGeoAddLine(FILE* fp, int id, const double p1[3], const double p2[3]) {
static inline int hxtGeoAddLine(FILE* fp, const double p1[3], const double p2[3]) {
  if (fprintf(fp, "p1=newp;\nPoint(p1) = {%.6f,%.6f,%.6f};\n", p1[0], p1[1], p1[2]) < 0) {
    return HXT_POS_WRITE_ERROR;
  };
  if (fprintf(fp, "p2=newp;\nPoint(p2) = {%.6f,%.6f,%.6f};\n", p2[0], p2[1], p2[2]) < 0) {
    return HXT_POS_WRITE_ERROR;
  };
  if (fprintf(fp, "l=newl;Line(l) = {p1,p2};\n") < 0) {
    return HXT_POS_WRITE_ERROR;
  };
  return HXT_POS_OK;
}

/* Debugging via .pos files
 * Example:
 *   FILE* fp;
 *   hxtPosInit("/tmp/debug.pos", &fp);
 *   for (int i ...) {
 *     ...
 *     hxtPosAddPoint(fp, &(pts[4*i]), i);
 *   }
 *   hxtPosFinish(fp);
 */

static inline int hxtPosInit(const char* path, const char* view_name, FILE** fpp) {
  *fpp = fopen(path, "w");
  if (*fpp == NULL) return HXT_POS_WRITE_ERROR;
  fprintf(*fpp, "View \"%s\" {\n", view_name);
  return HXT_POS_OK;
}

static inline int hxtPosNewView(FILE* fp, const char* view_name, ...) {
  char buffer[4096];
  va_list args;
  va_start(args, view_name);
  vsnprintf(buffer, sizeof(buffer), view_name, args);
  va_end(args);
  if (fprintf(fp, "};\n\n") < 0) return HXT_POS_WRITE_ERROR;
  if (fprintf(fp, "View \"%s\" {\n", buffer) < 0) return HXT_POS_WRITE_ERROR;
  return HXT_POS_WRITE_ERROR;
}

static inline int hxtPosFinish(FILE* fp) {
  if (fprintf(fp, "};\n") < 0) return HXT_POS_WRITE_ERROR;
  fclose(fp);
  return HXT_POS_OK;
}

static inline int hxtPosAddPoint(FILE* fp, const double* p, int color) {
  if (fprintf(fp, "  SP(%.6f,%.6f,%.6f){%i};\n", p[0], p[1], p[2], color) < 0) {
    return HXT_POS_WRITE_ERROR;
  };
  return HXT_POS_OK;
}

static inline int hxtPosAddVector(FILE* fp, const double* p, const double* v) {
  if (fprintf(fp, "  VP(%.6f,%.6f,%.6f){%.6f,%.6f,%.6f};\n", p[0], p[1], p[2], v[0], v[1], v[2]) < 0) {
    return HXT_POS_WRITE_ERROR;
  };
  return HXT_POS_OK;
}

static inline int hxtPosAddLine(FILE* fp, const double* p1, const double* p2, int color) {
  if (fprintf(fp, "  SL(%.6f,%.6f,%.6f,%.6f,%.6f,%.6f){%i,%i};\n", 
        p1[0], p1[1], p1[2], 
        p2[0], p2[1], p2[2], 
        color, color) < 0) {
    return HXT_POS_WRITE_ERROR;
  };
  return HXT_POS_OK;
}

static inline int hxtPosAddTriangle(FILE* fp, const double* p1, const double* p2, const double* p3, int color) {
  if (fprintf(fp, "  ST(%.6f,%.6f,%.6f, %.6f,%.6f,%.6f, %.6f,%.6f,%.6f){%i,%i,%i};\n", 
        p1[0], p1[1], p1[2], 
        p2[0], p2[1], p2[2], 
        p3[0], p3[1], p3[2], 
        color, color, color) < 0) {
    return HXT_POS_WRITE_ERROR;
  };
  return HXT_POS_OK;
}

static inline int hxtPosAddTriangle2(FILE* fp, const double* p1, const double* p2, const double* p3, double color) {
  if (fprintf(fp, "  ST(%.6f,%.6f,%.6f, %.6f,%.6f,%.6f, %.6f,%.6f,%.6f){%f,%f,%f};\n", 
        p1[0], p1[1], p1[2], 
        p2[0], p2[1], p2[2], 
        p3[0], p3[1], p3[2], 
        color, color, color) < 0) {
    return HXT_POS_WRITE_ERROR;
  };
  return HXT_POS_OK;
}

static inline int hxtPosAddTet(FILE* fp, const double* p1, const double* p2, const double* p3, const double* p4, int color) {
  if (fprintf(fp, "  SS(%.6f,%.6f,%.6f, %.6f,%.6f,%.6f, %.6f,%.6f,%.6f, %.6f,%.6f,%.6f){%i,%i,%i,%i};\n", 
        p1[0], p1[1], p1[2], 
        p2[0], p2[1], p2[2], 
        p3[0], p3[1], p3[2], 
        p4[0], p4[1], p4[2], 
        color, color, color, color) < 0) {
    return HXT_POS_WRITE_ERROR;
  };
  return HXT_POS_OK;
}

static inline int hxtPosAddQuad(FILE* fp, const double* p1, const double* p2, const double* p3, const double* p4, double color) {
  if (fprintf(fp, "  SQ(%.6f,%.6f,%.6f, %.6f,%.6f,%.6f, %.6f,%.6f,%.6f, %.6f,%.6f,%.6f){%f,%f,%f,%f};\n", 
        p1[0], p1[1], p1[2], 
        p2[0], p2[1], p2[2], 
        p3[0], p3[1], p3[2], 
        p4[0], p4[1], p4[2], 
        color, color, color, color) < 0) {
    return HXT_POS_WRITE_ERROR;
  };
  return HXT_POS_OK;
}

static inline int hxtPosAddPyr(FILE* fp, const double* p1, const double* p2, const double* p3, const double* p4, const double* p5, int color) {
  if (fprintf(fp, "  SY(%.6f,%.6f,%.6f, %.6f,%.6f,%.6f, %.6f,%.6f,%.6f, %.6f,%.6f,%.6f, %.6f,%.6f,%.6f){%i,%i,%i,%i,%i};\n", 
        p1[0], p1[1], p1[2], 
        p2[0], p2[1], p2[2], 
        p3[0], p3[1], p3[2], 
        p4[0], p4[1], p4[2], 
        p5[0], p5[1], p5[2], 
        color, color, color, color, color) < 0) {
    return HXT_POS_WRITE_ERROR;
  };
  return HXT_POS_OK;
}

static inline int hxtPosAddText(FILE* fp, const double* p, char* fmt, ...) {
  char buffer[4096];
  va_list args;
  va_start(args, fmt);
  vsnprintf(buffer, sizeof(buffer), fmt, args);
  va_end(args);
  if (fprintf(fp, "  T3(%.6f,%.6f,%.6f,0){\"%s\"};\n", p[0], p[1], p[2], buffer) < 0) {
    return HXT_POS_WRITE_ERROR;
  };
  return HXT_POS_OK;
}

#ifdef __cplusplus
}
#endif

#endif
