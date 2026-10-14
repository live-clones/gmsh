// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_FAST_ASCII_H
#define GMSH_FAST_ASCII_H

#include <algorithm>
#include <charconv>
#include <cstdio>
#include <cstddef>
#include <cstring>
#include <memory>
#include <string_view>
#include <type_traits>

// Accumulates formatted ASCII output for the mesh writers. The MSH writers
// make one fprintf call per integer and per coordinate, tens of millions of
// them on a large mesh, and the per-call work (format parsing, the stdio
// lock, the double conversion) dominates the cost of saving: writing the
// characters directly into a buffer and flushing it with fwrite, with the
// integer conversion done inline, removes the first two. The conversions
// produce exactly the bytes the replaced fprintf calls produced, so the
// saved files stay byte-identical.
//
// The writers create one per entity or element block, so construction has to
// stay cheap on models with thousands of entities: the buffer is left
// uninitialized and kept below the size at which malloc switches to mmap.
class FastAscii {
public:
  explicit FastAscii(std::FILE *fp, std::size_t size = 1 << 16)
    : _fp(fp), _size(std::max<std::size_t>(size, 512)),
      _buf(uninitialized(_size)), _pos(0)
  {
  }
  ~FastAscii() { flush(); }
  FastAscii(const FastAscii &) = delete;
  FastAscii &operator=(const FastAscii &) = delete;

  void flush()
  {
    if(_pos) {
      std::fwrite(_buf.get(), 1, _pos, _fp);
      _pos = 0;
    }
  }
  void put(char c)
  {
    if(_pos == _size) flush();
    _buf[_pos++] = c;
  }
  void writeBytes(const void *p, std::size_t n)
  {
    if(n >= _size) { // keep the ordering with what is buffered
      flush();
      std::fwrite(p, 1, n, _fp);
      return;
    }
    if(_size - _pos < n) flush();
    std::memcpy(&_buf[_pos], p, n);
    _pos += n;
  }
  void write(std::string_view s) { writeBytes(s.data(), s.size()); }
  // decimal digits, as "%d" / "%zu" would print them
  template <class T> void putInt(T v)
  {
    static_assert(std::is_integral_v<T>, "putInt takes an integer");
    char tmp[24];
    const auto r = std::to_chars(tmp, tmp + sizeof(tmp), v);
    writeBytes(tmp, static_cast<std::size_t>(r.ptr - tmp));
  }
  // same bytes as fprintf("%.16g", v): the conversion is still the C
  // library's, only the stdio lock and the format parsing are gone
  void putDouble16g(double v)
  {
    char tmp[40];
    const int n = std::snprintf(tmp, sizeof(tmp), "%.16g", v);
    if(n > 0) writeBytes(tmp, static_cast<std::size_t>(n));
  }

private:
  // the writers make one per entity, so the buffer must not be zero-filled
  static std::unique_ptr<char[]> uninitialized(std::size_t n)
  {
#if defined(__cpp_lib_smart_ptr_for_overwrite)
    return std::make_unique_for_overwrite<char[]>(n);
#else
    return std::unique_ptr<char[]>(new char[n]);
#endif
  }

  std::FILE *_fp;
  std::size_t _size;
  std::unique_ptr<char[]> _buf;
  std::size_t _pos;
};

#endif
