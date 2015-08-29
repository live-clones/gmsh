// @licstart farmhash
// Copyright (c) 2014 Google, Inc.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// FarmHash, by Geoff Pike

//
// http://code.google.com/p/farmhash/
//
// This file provides a few functions for hashing strings and other
// data.  All of them are high-quality functions in the sense that
// they do well on standard tests such as Austin Appleby's SMHasher.
// They're also fast.  FarmHash is the successor to CityHash.
//
// Functions in the FarmHash family are not suitable for cryptography.
//
// WARNING: This code has been only lightly tested on big-endian platforms!
// It is known to work well on little-endian platforms that have a small penalty
// for unaligned reads, such as current Intel and AMD moderate-to-high-end CPUs.
// It should work on all 32-bit and 64-bit platforms that allow unaligned reads;
// bug reports are welcome.
//
// By the way, for some hash functions, given strings a and b, the hash
// of a+b is easily derived from the hashes of a and b.  This property
// doesn't hold for any hash functions in this file.
// 
// @licend farmhash

#ifndef _REVOROPT_TOOLS_HASH_HPP_
#define _REVOROPT_TOOLS_HASH_HPP_

#include <functional>

namespace Revoropt {

template < class T, class Hasher = std::hash<T> > 
inline void hash_combine(std::size_t& seed, const T& v)
{
    Hasher hasher;
    const std::size_t kMul = 0x9ddfea08eb382d69ULL;
    std::size_t a = (hasher(v) ^ seed) * kMul;
    a ^= (a >> 47);
    std::size_t b = (seed ^ a) * kMul;
    b ^= (b >> 47);
    seed = b * kMul;
}

} // end of namespace Revoropt

#endif
