// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GL2MPEG_H
#define GL2MPEG_H

#include <string>
#include <vector>

class PixelBuffer;

// An MPEG-1 movie made of pictures, encoded with the mpeg_encode of
// contrib/mpeg_encode: the pictures are written as PPM files next to a
// parameter file in the home directory, and encoded when the movie is closed.
// Without mpeg_encode, open() says so and fails.
class mpegWriter {
private:
  std::string _name, _parFileName;
  std::vector<std::string> _frames;
  // how many times each picture is repeated, at 30 frames per second
  int _repeat = 1;
  bool _opened = false, _failed = false;

public:
  ~mpegWriter() { close(); }
  bool open(const std::string &name, int width, int height, double fps);
  bool write(PixelBuffer *buffer);
  // encode the movie and delete the temporary files (if
  // Print.DeleteTemporaryFiles); false if anything failed
  bool close();
};

#endif
