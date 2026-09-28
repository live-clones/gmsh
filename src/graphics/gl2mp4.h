// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GL2MP4_H
#define GL2MP4_H

#include <string>

class PixelBuffer;

// An MP4 movie made of pictures (RGB bytes, of the same size), encoded with
// FFmpeg: H.264 if it has an encoder for it, MPEG-4 otherwise. Without
// FFmpeg, open() says so and fails.
class mp4Writer {
public:
  // what FFmpeg holds for the movie
  struct data;

private:
  data *_d;

public:
  mp4Writer();
  ~mp4Writer();
  bool open(const std::string &name, int width, int height, double fps);
  bool write(PixelBuffer *buffer);
  // write what is left and the end of the file; false if anything failed
  bool close();
};

#endif
