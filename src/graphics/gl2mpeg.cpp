// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <cstdio>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "Context.h"
#include "OS.h"
#include "PixelBuffer.h"
#include "gl2mpeg.h"
#include "gl2ppm.h"

#if defined(HAVE_MPEG_ENCODE)

extern int mpeg_encode_main(int, char **);

bool mpegWriter::open(const std::string &name, int width, int height,
                      double fps)
{
  close();
  _name = name;
  _parFileName = CTX::instance()->homeDir + ".gmsh-mpeg_encode.par";
  _repeat = (fps > 0.) ? (int)(30. / fps) : 1;
  if(_repeat < 1) _repeat = 1;
  _opened = true;
  _failed = false;
  return true;
}

bool mpegWriter::write(PixelBuffer *buffer)
{
  if(!_opened || _failed) return false;
  char tmp[256];
  snprintf(tmp, sizeof(tmp), ".gmsh-%06d.ppm", (int)_frames.size());
  std::string path = CTX::instance()->homeDir + tmp;
  FILE *fp = Fopen(path.c_str(), "wb");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", path.c_str());
    _failed = true;
    return false;
  }
  create_ppm(fp, buffer);
  fclose(fp);
  _frames.push_back(tmp);
  return true;
}

bool mpegWriter::close()
{
  if(!_opened) return true;
  _opened = false;
  bool ok = !_failed && !_frames.empty();
  if(ok) {
    FILE *fp = Fopen(_parFileName.c_str(), "w");
    if(!fp) {
      Msg::Error("Unable to open file '%s'", _parFileName.c_str());
      ok = false;
    }
    else {
      // including P frames would lead to smaller files, but the quality
      // degradation is perceptible
      fprintf(fp,
              "PATTERN I\nBASE_FILE_FORMAT PPM\nGOP_SIZE %d\n"
              "SLICES_PER_FRAME 1\nPIXEL FULL\nRANGE 10\n"
              "PSEARCH_ALG EXHAUSTIVE\nBSEARCH_ALG CROSS2\n"
              "IQSCALE 1\nPQSCALE 1\nBQSCALE 25\nREFERENCE_FRAME DECODED\n"
              "OUTPUT %s\nINPUT_CONVERT *\nINPUT_DIR %s\nINPUT\n",
              _repeat, _name.c_str(), CTX::instance()->homeDir.c_str());
      for(auto &f : _frames) {
        fprintf(fp, "%s", f.c_str());
        if(_repeat > 1) fprintf(fp, " [1-%d]", _repeat);
        fprintf(fp, "\n");
      }
      fprintf(fp, "END_INPUT\n");
      fclose(fp);
      char *args[] = {(char *)"gmsh", (char *)_parFileName.c_str()};
      try {
        mpeg_encode_main(2, args);
      } catch(const char *msg) {
        Msg::Error("%s", msg);
        ok = false;
      }
    }
  }
  if(CTX::instance()->print.deleteTmpFiles) {
    UnlinkFile(_parFileName);
    for(auto &f : _frames) UnlinkFile(CTX::instance()->homeDir + f);
  }
  _frames.clear();
  return ok;
}

#else

bool mpegWriter::open(const std::string &name, int width, int height,
                      double fps)
{
  Msg::Error("Gmsh must be compiled with mpeg_encode to write MPEG movies");
  return false;
}
bool mpegWriter::write(PixelBuffer *buffer) { return false; }
bool mpegWriter::close() { return true; }

#endif
