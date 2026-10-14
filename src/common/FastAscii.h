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

#if defined(__has_include)
#if __has_include(<version>)
#include <version>
#endif
#endif

// Exact "%.16g" for the mesh writers. Through the C library it costs more than
// the rest of the save, ~200-370 ns per value, and a 958k-node 2D mesh has 4.8M
// values. std::to_chars gives the same bytes 4-5x faster, but gcc only has it
// from 11 (the official Linux builds use gcc 8) and libc++ only from macOS
// 13.3, so it is used where the library advertises it and an exact 128-bit
// converter covers the rest. The 128-bit code can go once the minimum toolchain
// has to_chars.
#if defined(__cpp_lib_to_chars) && __cpp_lib_to_chars >= 201611L
#include <cmath>
#define GMSH_FAST_ASCII_TO_CHARS
#elif defined(__SIZEOF_INT128__)
#define GMSH_FAST_ASCII_INT128
#include <array>
#include <cstdint>
#if defined(__cpp_lib_bit_cast)
#include <bit>
#endif
// This is the exact rational method of Dragon4 [1], which is also the slow path
// of Gay's dtoa [2], with 128-bit integers in place of bignums since 16 digits
// are all that is needed. The value is m * 2^A * 5^B, so scaled to 16 digits it
// is the ratio of two integers. The quotient gives the digits and twice the
// remainder against the divisor rounds the last one, ties to even, which is the
// correctly rounded result C asks of printf [4]. The decimal exponent starts
// from the log10(2) estimate of [3] and is fixed up from the digit count.
// Values outside the 128-bit range, nonzero magnitudes below ~1e-17 or above
// ~1e48, and inf and nan still go through snprintf. [5] is the method behind
// to_chars with a precision in libstdc++.
//
// [1] G. L. Steele, J. L. White, How to print floating-point numbers
//     accurately, PLDI 1990, doi:10.1145/93542.93559
// [2] D. M. Gay, Correctly rounded binary-decimal and decimal-binary
//     conversions, AT&T Bell Labs Numerical Analysis Manuscript 90-10, 1990
// [3] R. G. Burger, R. K. Dybvig, Printing floating-point numbers quickly and
//     accurately, PLDI 1996, doi:10.1145/231379.231397
// [4] ISO C11 7.21.6.1, the %g style choice and the rounding of fprintf; C++17
//     [charconv.to.chars] gives to_chars the same output
// [5] U. Adams, Ryu revisited: printf floating point conversion, OOPSLA 2019,
//     doi:10.1145/3360595
namespace fastascii {

  __extension__ using u128 = unsigned __int128; // no -Wpedantic noise
  inline constexpr u128 kU128Max = ~u128{0};

  template <std::size_t N> constexpr std::array<u128, N> powers(unsigned base)
  {
    std::array<u128, N> p{};
    p[0] = 1;
    for(std::size_t i = 1; i < N; i++) p[i] = p[i - 1] * base;
    return p;
  }
  inline constexpr auto kPow5 = powers<56>(5);
  inline constexpr auto kPow10 = powers<19>(10);

  inline std::uint64_t bitsOf(double d)
  {
#if defined(__cpp_lib_bit_cast)
    return std::bit_cast<std::uint64_t>(d);
#else
    std::uint64_t b;
    std::memcpy(&b, &d, sizeof(b));
    return b;
#endif
  }

  // -1 when the value must go through the C library
  inline int format16g(double d, char *out)
  {
    const std::uint64_t bits = bitsOf(d);
    const bool negative = (bits >> 63) != 0;
    std::uint64_t m = bits & ((std::uint64_t{1} << 52) - 1);
    int e2 = static_cast<int>((bits >> 52) & 0x7FF);
    if(e2 == 0x7FF) return -1; // inf and nan
    int k = 0;
    if(negative) out[k++] = '-';
    if(e2 == 0)
      e2 = -1074; // subnormal: value = m * 2^-1074
    else {
      m |= std::uint64_t{1} << 52;
      e2 -= 1075;
    }
    if(m == 0) {
      out[k++] = '0';
      out[k] = 0;
      return k;
    }
    // floor(log10(value)) estimate from the binary exponent, corrected below by
    // the digit count of the exact quotient (it is within one)
    int X = static_cast<int>((e2 + 52) * 0.30102999566398119521);
    for(int attempt = 0; attempt < 3; attempt++) {
      const int s = X - 15;
      const int A = e2 - s; // value = m * 2^A * 5^B with B = -s
      const int B = -s;
      if(B > 55 || B < -55) return -1;
      // value / 10^s = num / den, both exact
      u128 num = m, den = 1;
      const u128 pow5 = kPow5[static_cast<std::size_t>(B >= 0 ? B : -B)];
      if(B >= 0) {
        if(m > kU128Max / pow5) return -1;
        num = m * pow5;
      }
      else
        den = pow5;
      if(A >= 0) {
        if(A > 127 || num > kU128Max >> A) return -1;
        num <<= A;
      }
      else {
        if(-A > 127 || den > kU128Max >> (-A)) return -1;
        den <<= -A;
      }
      u128 D = num / den, R = num - D * den;
      if(D < kPow10[15]) {
        X--;
        continue;
      }
      if(D >= kPow10[16]) {
        X++;
        continue;
      }
      if(R > den - R)
        D++;
      else if(R == den - R && (D & 1))
        D++; // exact tie: round to even
      if(D == kPow10[16]) { // the rounding carried into the next power of ten
        X++;
        D = kPow10[15];
      }
      char dig[17];
      {
        std::uint64_t d64 = static_cast<std::uint64_t>(D);
        for(int i = 15; i >= 0; i--) {
          dig[i] = static_cast<char>('0' + d64 % 10);
          d64 /= 10;
        }
      }
      int last = 16;
      while(last > 1 && dig[last - 1] == '0') last--; // %g drops trailing zeros
      if(X < -4 || X >= 16) {
        out[k++] = dig[0];
        if(last > 1) {
          out[k++] = '.';
          for(int i = 1; i < last; i++) out[k++] = dig[i];
        }
        out[k++] = 'e';
        int ex = X;
        out[k++] = (ex < 0) ? '-' : '+';
        if(ex < 0) ex = -ex;
        char eb[8];
        int ne = 0;
        do {
          eb[ne++] = static_cast<char>('0' + ex % 10);
          ex /= 10;
        } while(ex);
        while(ne < 2) eb[ne++] = '0';
        while(ne) out[k++] = eb[--ne];
      }
      else if(X >= 0) {
        const int ip = X + 1; // the point sits after X + 1 digits
        for(int i = 0; i < ip; i++) out[k++] = (i < last) ? dig[i] : '0';
        if(last > ip) {
          out[k++] = '.';
          for(int i = ip; i < last; i++) out[k++] = dig[i];
        }
      }
      else {
        out[k++] = '0';
        out[k++] = '.';
        for(int i = 0; i < -X - 1; i++) out[k++] = '0';
        for(int i = 0; i < last; i++) out[k++] = dig[i];
      }
      out[k] = 0;
      return k;
    }
    return -1;
  }

} // namespace fastascii
#endif

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
  // same bytes as fprintf("%.16g", v)
  void putDouble16g(double v)
  {
    char tmp[40];
    int n = -1;
#if defined(GMSH_FAST_ASCII_TO_CHARS)
    if(std::isfinite(v)) { // printf and to_chars spell nan differently
      const auto r = std::to_chars(tmp, tmp + sizeof(tmp), v,
                                   std::chars_format::general, 16);
      n = static_cast<int>(r.ptr - tmp);
    }
#elif defined(GMSH_FAST_ASCII_INT128)
    n = fastascii::format16g(v, tmp);
#endif
    if(n < 0) n = std::snprintf(tmp, sizeof(tmp), "%.16g", v);
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
