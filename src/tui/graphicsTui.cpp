// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_TUI)

#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <unistd.h>

#if defined(HAVE_LIBZ)
#include <zlib.h>
#endif

#include "tuiCommon.h"

// The picture of the scene at the resolution of the terminal, where the
// terminal can show one: the graphics protocol of kitty (kitty, WezTerm,
// Ghostty, Konsole), or sixel (foot, WezTerm, xterm, mlterm); in half blocks
// otherwise, two pixels a cell, which any terminal with 24-bit colours shows.
// Written after FTXUI's frame, the cursor saved and put back around it, so
// that FTXUI finds it where it left it.

namespace {

  Tui::Graphics _detect()
  {
    // what one asks for comes first
    if(const char *said = getenv("GMSH_TUI_GRAPHICS")) {
      std::string s = said;
      if(s == "kitty") return Tui::Kitty;
      if(s == "sixel") return Tui::Sixel;
      if(s == "blocks") return Tui::Blocks;
    }
    int w = 0, h = 0;
    if(!Tui::cellPixels(w, h)) return Tui::Blocks;
    std::string term = getenv("TERM") ? getenv("TERM") : "";
    std::string program = getenv("TERM_PROGRAM") ? getenv("TERM_PROGRAM") : "";
    if(getenv("KITTY_WINDOW_ID") || term.find("kitty") != std::string::npos ||
       program == "WezTerm" || program == "ghostty" ||
       term.find("ghostty") != std::string::npos || getenv("KONSOLE_VERSION"))
      return Tui::Kitty;
    if(term.find("foot") != std::string::npos ||
       term.find("mlterm") != std::string::npos ||
       term.find("sixel") != std::string::npos)
      return Tui::Sixel;
    return Tui::Blocks;
  }

  std::string _base64(const unsigned char *data, std::size_t n)
  {
    static const char *table =
      "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    std::string out;
    out.reserve((n + 2) / 3 * 4);
    for(std::size_t i = 0; i < n; i += 3) {
      unsigned int v = data[i] << 16;
      if(i + 1 < n) v |= data[i + 1] << 8;
      if(i + 2 < n) v |= data[i + 2];
      out += table[(v >> 18) & 63];
      out += table[(v >> 12) & 63];
      out += i + 1 < n ? table[(v >> 6) & 63] : '=';
      out += i + 2 < n ? table[v & 63] : '=';
    }
    return out;
  }

  // the rows of the bitmap top down, as RGB
  std::vector<unsigned char> _rgb(const unsigned char *bmp, int w, int h)
  {
    std::vector<unsigned char> rgb((std::size_t)3 * w * h);
    int stride = (w * 3 + 3) & ~3;
    for(int y = 0; y < h; y++) {
      const unsigned char *from = bmp + 54 + (std::size_t)stride * (h - 1 - y);
      unsigned char *to = &rgb[(std::size_t)3 * w * y];
      for(int x = 0; x < w; x++) {
        to[3 * x + 0] = from[3 * x + 2];
        to[3 * x + 1] = from[3 * x + 1];
        to[3 * x + 2] = from[3 * x + 0];
      }
    }
    return rgb;
  }

  // under the cells that have a background of their own, so that the menus
  // and the boxes over the scene stay above it
  const char *_kittyUnder = "-1073741825";

  // two images taken in turn: the new one is put up before the old one is
  // taken down, or the terminal shows nothing in between
  int _kittyId = 31;

  // kitty itself, on this machine: the picture can go through shared memory,
  // which kitty reads and unlinks, rather than through the terminal
  bool _sharedMemory()
  {
    static int said = -1;
    if(said < 0) {
      const char *no = getenv("GMSH_TUI_KITTY_SHM");
      said = getenv("KITTY_WINDOW_ID") && !getenv("SSH_CONNECTION") &&
             !getenv("SSH_TTY") && !(no && std::string(no) == "0");
    }
    return said == 1;
  }

  // the bitmap into shared memory, top down as RGB; its name, or nothing
  std::string _toShared(const unsigned char *bmp, int w, int h)
  {
    static unsigned count = 0;
    std::string name = "/gmsh-tui-" + std::to_string(getpid()) + "-" +
                       std::to_string(count++);
    std::size_t bytes = (std::size_t)3 * w * h;
    int fd = shm_open(name.c_str(), O_CREAT | O_RDWR | O_EXCL, 0600);
    if(fd < 0) return "";
    if(ftruncate(fd, (off_t)bytes)) {
      close(fd);
      shm_unlink(name.c_str());
      return "";
    }
    void *at = mmap(nullptr, bytes, PROT_WRITE, MAP_SHARED, fd, 0);
    close(fd);
    if(at == MAP_FAILED) {
      shm_unlink(name.c_str());
      return "";
    }
    unsigned char *to = (unsigned char *)at;
    int stride = (w * 3 + 3) & ~3;
    for(int y = 0; y < h; y++) {
      const unsigned char *from = bmp + 54 + (std::size_t)stride * (h - 1 - y);
      unsigned char *row = to + (std::size_t)3 * w * y;
      for(int x = 0; x < w; x++) {
        row[3 * x + 0] = from[3 * x + 2];
        row[3 * x + 1] = from[3 * x + 1];
        row[3 * x + 2] = from[3 * x + 0];
      }
    }
    munmap(at, bytes);
    return name;
  }

  std::string _kittyShared(const std::string &name, int w, int h, int cols,
                           int rows)
  {
    int was = _kittyId;
    _kittyId = _kittyId == 31 ? 32 : 31;
    std::string out = "\x1b_Ga=T,f=24,t=s,s=" + std::to_string(w) +
                      ",v=" + std::to_string(h) + ",i=" +
                      std::to_string(_kittyId) + ",p=1,c=" +
                      std::to_string(cols) + ",r=" + std::to_string(rows) +
                      ",C=1,q=2,z=" + _kittyUnder + ";" +
                      _base64((const unsigned char *)name.data(), name.size()) +
                      "\x1b\\";
    out += "\x1b_Ga=d,d=I,i=" + std::to_string(was) + ",q=2\x1b\\";
    return out;
  }

  std::string _kitty(const std::vector<unsigned char> &rgb, int w, int h,
                     int cols, int rows)
  {
    std::string payload;
    int was = _kittyId;
    _kittyId = _kittyId == 31 ? 32 : 31;
    std::string keys = "a=T,f=24,s=" + std::to_string(w) +
                       ",v=" + std::to_string(h) + ",i=" +
                       std::to_string(_kittyId) + ",p=1,c=" +
                       std::to_string(cols) + ",r=" + std::to_string(rows) +
                       ",C=1,q=2,z=" + _kittyUnder;
#if defined(HAVE_LIBZ)
    uLongf size = compressBound((uLong)rgb.size());
    std::vector<unsigned char> packed(size);
    if(compress2(&packed[0], &size, &rgb[0], (uLong)rgb.size(), 1) == Z_OK) {
      payload = _base64(&packed[0], size);
      keys += ",o=z";
    }
    else
#endif
      payload = _base64(&rgb[0], rgb.size());
    std::string out;
    // in chunks of at most 4096 bytes
    for(std::size_t at = 0; at < payload.size(); at += 4096) {
      bool more = at + 4096 < payload.size();
      out += "\x1b_G";
      if(at == 0) out += keys + ",";
      out += std::string("m=") + (more ? "1" : "0") + ";";
      out += payload.substr(at, 4096);
      out += "\x1b\\";
    }
    out += "\x1b_Ga=d,d=I,i=" + std::to_string(was) + ",q=2\x1b\\";
    return out;
  }

  // six levels of red and blue, seven of green: 252 colours, set once; the
  // levels between them dithered with a 4x4 Bayer matrix, so that a gradient
  // does not come out in bands
  int _level(int v, int levels, int threshold)
  {
    int scaled = v * (levels - 1) * 16 + threshold * 255;
    return std::min(levels - 1, scaled / (255 * 16));
  }

  int _index(const unsigned char *p, int x, int y)
  {
    static const int bayer[4][4] = {
      {0, 8, 2, 10}, {12, 4, 14, 6}, {3, 11, 1, 9}, {15, 7, 13, 5}};
    int t = bayer[y & 3][x & 3];
    int r = _level(p[0], 6, t), g = _level(p[1], 7, t), b = _level(p[2], 6, t);
    return (r * 7 + g) * 6 + b;
  }

  std::string _sixel(const std::vector<unsigned char> &rgb, int w, int h)
  {
    std::string out = "\x1bP0;1;0q\"1;1;" + std::to_string(w) + ";" +
                      std::to_string(h);
    for(int r = 0; r < 6; r++)
      for(int g = 0; g < 7; g++)
        for(int b = 0; b < 6; b++)
          out += "#" + std::to_string((r * 7 + g) * 6 + b) + ";2;" +
                 std::to_string(r * 100 / 5) + ";" + std::to_string(g * 100 / 6) +
                 ";" + std::to_string(b * 100 / 5);
    std::vector<int> index((std::size_t)w * h);
    for(int y = 0; y < h; y++)
      for(int x = 0; x < w; x++) {
        std::size_t i = (std::size_t)y * w + x;
        index[i] = _index(&rgb[3 * i], x, y);
      }
    std::vector<unsigned char> bits(w);
    std::vector<char> used(252);
    for(int band = 0; band < h; band += 6) {
      std::fill(used.begin(), used.end(), 0);
      for(int y = band; y < band + 6 && y < h; y++)
        for(int x = 0; x < w; x++) used[index[(std::size_t)y * w + x]] = 1;
      bool first = true;
      for(int c = 0; c < 252; c++) {
        if(!used[c]) continue;
        std::fill(bits.begin(), bits.end(), 0);
        for(int y = band; y < band + 6 && y < h; y++)
          for(int x = 0; x < w; x++)
            if(index[(std::size_t)y * w + x] == c) bits[x] |= 1 << (y - band);
        if(!first) out += "$";
        first = false;
        out += "#" + std::to_string(c);
        // runs of the same six pixels written once
        for(int x = 0; x < w;) {
          int n = 1;
          while(x + n < w && bits[x + n] == bits[x]) n++;
          char ch = (char)(63 + bits[x]);
          if(n > 3)
            out += "!" + std::to_string(n) + ch;
          else
            out += std::string(n, ch);
          x += n;
        }
      }
      out += "-";
    }
    out += "\x1b\\";
    return out;
  }

} // namespace

Tui::Graphics Tui::graphics()
{
  static Graphics said = _detect();
  return said;
}

bool Tui::cellPixels(int &width, int &height)
{
  struct winsize ws;
  width = height = 0;
  if(ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) || !ws.ws_col || !ws.ws_row)
    return false;
  width = ws.ws_xpixel / ws.ws_col;
  height = ws.ws_ypixel / ws.ws_row;
  return width > 0 && height > 0;
}

void Tui::showPicture(const unsigned char *bmp, int w, int h, int x, int y,
                      int cols, int rows)
{
  if(!bmp || w < 1 || h < 1 || cols < 1 || rows < 1) return;
  std::string out = "\x1b" "7\x1b[" + std::to_string(y + 1) + ";" +
                    std::to_string(x + 1) + "H";
  std::string shared;
  if(graphics() == Kitty && _sharedMemory()) shared = _toShared(bmp, w, h);
  if(shared.size())
    out += _kittyShared(shared, w, h, cols, rows);
  else {
    std::vector<unsigned char> rgb = _rgb(bmp, w, h);
    out += graphics() == Kitty ? _kitty(rgb, w, h, cols, rows) :
                                 _sixel(rgb, w, h);
  }
  out += "\x1b" "8";
  std::cout << out << std::flush;
}

void Tui::clearPictures()
{
  if(graphics() == Kitty) std::cout << "\x1b_Ga=d,d=A,q=2\x1b\\" << std::flush;
}

#endif
