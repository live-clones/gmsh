// This file is part of Eigen, a lightweight C++ template library
// for linear algebra.
//
// Copyright (C) 2008-2018 Gael Guennebaud <gael.guennebaud@inria.fr>
// Copyright (C) 2020, Arm Limited and Contributors
//
// This Source Code Form is subject to the terms of the Mozilla
// Public License v. 2.0. If a copy of the MPL was not distributed
// with this file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef EIGEN_CONFIGURE_VECTORIZATION_H
#define EIGEN_CONFIGURE_VECTORIZATION_H

//------------------------------------------------------------------------------------------
// Static and dynamic alignment control
//
// The main purpose of this section is to define EIGEN_MAX_ALIGN_BYTES and EIGEN_MAX_STATIC_ALIGN_BYTES
// as the maximal boundary in bytes on which dynamically and statically allocated data may be alignment respectively.
// The values of EIGEN_MAX_ALIGN_BYTES and EIGEN_MAX_STATIC_ALIGN_BYTES can be specified by the user. If not,
// a default value is automatically computed based on architecture, compiler, and OS.
//
// This section also defines macros EIGEN_ALIGN_TO_BOUNDARY(N) and the shortcuts EIGEN_ALIGN{8,16,32,_MAX}
// to be used to declare statically aligned buffers.
//------------------------------------------------------------------------------------------


/* EIGEN_ALIGN_TO_BOUNDARY(n) forces data to be n-byte aligned. This is used to satisfy SIMD requirements.
 * However, we do that EVEN if vectorization (EIGEN_VECTORIZE) is disabled,
 * so that vectorization doesn't affect binary compatibility.
 *
 * If we made alignment depend on whether or not EIGEN_VECTORIZE is defined, it would be impossible to link
 * vectorized and non-vectorized code.
 * 
 * FIXME: this code can be cleaned up once we switch to proper C++11 only.
 */
#if (defined EIGEN_CUDACC)
  #define EIGEN_ALIGN_TO_BOUNDARY(n) __align__(n)
  #define EIGEN_ALIGNOF(x) __alignof(x)
#elif EIGEN_HAS_ALIGNAS
  #define EIGEN_ALIGN_TO_BOUNDARY(n) alignas(n)
  #define EIGEN_ALIGNOF(x) alignof(x)
#elif EIGEN_COMP_GNUC || EIGEN_COMP_PGI || EIGEN_COMP_IBM || EIGEN_COMP_ARM
  #define EIGEN_ALIGN_TO_BOUNDARY(n) __attribute__((aligned(n)))
  #define EIGEN_ALIGNOF(x) __alignof(x)
#elif EIGEN_COMP_MSVC
  #define EIGEN_ALIGN_TO_BOUNDARY(n) __declspec(align(n))
  #define EIGEN_ALIGNOF(x) __alignof(x)
#elif EIGEN_COMP_SUNCC
  // FIXME not sure about this one:
  #define EIGEN_ALIGN_TO_BOUNDARY(n) __attribute__((aligned(n)))
  #define EIGEN_ALIGNOF(x) __alignof(x)
#else
  #error Please tell me what is the equivalent of alignas(n) and alignof(x) for your compiler
#endif

// If the user explicitly disable vectorization, then we also disable alignment
#if defined(EIGEN_DONT_VECTORIZE)
  #if defined(EIGEN_GPUCC)
    // GPU code is always vectorized and requires memory alignment for
    // statically allocated buffers.
    #define EIGEN_IDEAL_MAX_ALIGN_BYTES 16
  #else
    #define EIGEN_IDEAL_MAX_ALIGN_BYTES 0
  #endif
#else
  #define EIGEN_IDEAL_MAX_ALIGN_BYTES 16
#endif


// EIGEN_MIN_ALIGN_BYTES defines the minimal value for which the notion of explicit alignment makes sense
#define EIGEN_MIN_ALIGN_BYTES 16

// Defined the boundary (in bytes) on which the data needs to be aligned. Note
// that unless EIGEN_ALIGN is defined and not equal to 0, the data may not be
// aligned at all regardless of the value of this #define.

#if (defined(EIGEN_DONT_ALIGN_STATICALLY) || defined(EIGEN_DONT_ALIGN))  && defined(EIGEN_MAX_STATIC_ALIGN_BYTES) && EIGEN_MAX_STATIC_ALIGN_BYTES>0
#error EIGEN_MAX_STATIC_ALIGN_BYTES and EIGEN_DONT_ALIGN[_STATICALLY] are both defined with EIGEN_MAX_STATIC_ALIGN_BYTES!=0. Use EIGEN_MAX_STATIC_ALIGN_BYTES=0 as a synonym of EIGEN_DONT_ALIGN_STATICALLY.
#endif

// EIGEN_DONT_ALIGN_STATICALLY and EIGEN_DONT_ALIGN are deprecated
// They imply EIGEN_MAX_STATIC_ALIGN_BYTES=0
#if defined(EIGEN_DONT_ALIGN_STATICALLY) || defined(EIGEN_DONT_ALIGN)
  #ifdef EIGEN_MAX_STATIC_ALIGN_BYTES
    #undef EIGEN_MAX_STATIC_ALIGN_BYTES
  #endif
  #define EIGEN_MAX_STATIC_ALIGN_BYTES 0
#endif

#ifndef EIGEN_MAX_STATIC_ALIGN_BYTES

  // Try to automatically guess what is the best default value for EIGEN_MAX_STATIC_ALIGN_BYTES

  // 16 byte alignment is only useful for vectorization. Since it affects the ABI, we need to enable
  // 16 byte alignment on all platforms where vectorization might be enabled. In theory we could always
  // enable alignment, but it can be a cause of problems on some platforms, so we just disable it in
  // certain common platform (compiler+architecture combinations) to avoid these problems.
  // Only static alignment is really problematic (relies on nonstandard compiler extensions),
  // try to keep heap alignment even when we have to disable static alignment.
  #if EIGEN_COMP_GNUC && !(EIGEN_ARCH_i386_OR_x86_64 || EIGEN_ARCH_ARM_OR_ARM64 || EIGEN_ARCH_PPC || EIGEN_ARCH_IA64 || EIGEN_ARCH_MIPS)
  #define EIGEN_GCC_AND_ARCH_DOESNT_WANT_STACK_ALIGNMENT 1
  #elif EIGEN_ARCH_ARM_OR_ARM64 && EIGEN_COMP_GNUC_STRICT && EIGEN_GNUC_AT_MOST(4, 6)
  // Old versions of GCC on ARM, at least 4.4, were once seen to have buggy static alignment support.
  // Not sure which version fixed it, hopefully it doesn't affect 4.7, which is still somewhat in use.
  // 4.8 and newer seem definitely unaffected.
  #define EIGEN_GCC_AND_ARCH_DOESNT_WANT_STACK_ALIGNMENT 1
  #else
  #define EIGEN_GCC_AND_ARCH_DOESNT_WANT_STACK_ALIGNMENT 0
  #endif

  // static alignment is completely disabled with GCC 3, Sun Studio, and QCC/QNX
  #if !EIGEN_GCC_AND_ARCH_DOESNT_WANT_STACK_ALIGNMENT \
  && !EIGEN_GCC3_OR_OLDER \
  && !EIGEN_COMP_SUNCC \
  && !EIGEN_OS_QNX
    #define EIGEN_ARCH_WANTS_STACK_ALIGNMENT 1
  #else
    #define EIGEN_ARCH_WANTS_STACK_ALIGNMENT 0
  #endif

  #if EIGEN_ARCH_WANTS_STACK_ALIGNMENT
    #define EIGEN_MAX_STATIC_ALIGN_BYTES EIGEN_IDEAL_MAX_ALIGN_BYTES
  #else
    #define EIGEN_MAX_STATIC_ALIGN_BYTES 0
  #endif

#endif

// If EIGEN_MAX_ALIGN_BYTES is defined, then it is considered as an upper bound for EIGEN_MAX_STATIC_ALIGN_BYTES
#if defined(EIGEN_MAX_ALIGN_BYTES) && EIGEN_MAX_ALIGN_BYTES<EIGEN_MAX_STATIC_ALIGN_BYTES
#undef EIGEN_MAX_STATIC_ALIGN_BYTES
#define EIGEN_MAX_STATIC_ALIGN_BYTES EIGEN_MAX_ALIGN_BYTES
#endif

#if EIGEN_MAX_STATIC_ALIGN_BYTES==0 && !defined(EIGEN_DISABLE_UNALIGNED_ARRAY_ASSERT)
  #define EIGEN_DISABLE_UNALIGNED_ARRAY_ASSERT
#endif

// At this stage, EIGEN_MAX_STATIC_ALIGN_BYTES>0 is the true test whether we want to align arrays on the stack or not.
// It takes into account both the user choice to explicitly enable/disable alignment (by setting EIGEN_MAX_STATIC_ALIGN_BYTES)
// and the architecture config (EIGEN_ARCH_WANTS_STACK_ALIGNMENT).
// Henceforth, only EIGEN_MAX_STATIC_ALIGN_BYTES should be used.


// Shortcuts to EIGEN_ALIGN_TO_BOUNDARY
#define EIGEN_ALIGN8  EIGEN_ALIGN_TO_BOUNDARY(8)
#define EIGEN_ALIGN16 EIGEN_ALIGN_TO_BOUNDARY(16)
#define EIGEN_ALIGN32 EIGEN_ALIGN_TO_BOUNDARY(32)
#define EIGEN_ALIGN64 EIGEN_ALIGN_TO_BOUNDARY(64)
#if EIGEN_MAX_STATIC_ALIGN_BYTES>0
#define EIGEN_ALIGN_MAX EIGEN_ALIGN_TO_BOUNDARY(EIGEN_MAX_STATIC_ALIGN_BYTES)
#else
#define EIGEN_ALIGN_MAX
#endif


// Dynamic alignment control

#if defined(EIGEN_DONT_ALIGN) && defined(EIGEN_MAX_ALIGN_BYTES) && EIGEN_MAX_ALIGN_BYTES>0
#error EIGEN_MAX_ALIGN_BYTES and EIGEN_DONT_ALIGN are both defined with EIGEN_MAX_ALIGN_BYTES!=0. Use EIGEN_MAX_ALIGN_BYTES=0 as a synonym of EIGEN_DONT_ALIGN.
#endif

#ifdef EIGEN_DONT_ALIGN
  #ifdef EIGEN_MAX_ALIGN_BYTES
    #undef EIGEN_MAX_ALIGN_BYTES
  #endif
  #define EIGEN_MAX_ALIGN_BYTES 0
#elif !defined(EIGEN_MAX_ALIGN_BYTES)
  #define EIGEN_MAX_ALIGN_BYTES EIGEN_IDEAL_MAX_ALIGN_BYTES
#endif

#if EIGEN_IDEAL_MAX_ALIGN_BYTES > EIGEN_MAX_ALIGN_BYTES
#define EIGEN_DEFAULT_ALIGN_BYTES EIGEN_IDEAL_MAX_ALIGN_BYTES
#else
#define EIGEN_DEFAULT_ALIGN_BYTES EIGEN_MAX_ALIGN_BYTES
#endif


#ifndef EIGEN_UNALIGNED_VECTORIZE
#define EIGEN_UNALIGNED_VECTORIZE 1
#endif

//----------------------------------------------------------------------

// if alignment is disabled, then disable vectorization. Note: EIGEN_MAX_ALIGN_BYTES is the proper check, it takes into
// account both the user's will (EIGEN_MAX_ALIGN_BYTES,EIGEN_DONT_ALIGN) and our own platform checks
#if EIGEN_MAX_ALIGN_BYTES==0
  #ifndef EIGEN_DONT_VECTORIZE
    #define EIGEN_DONT_VECTORIZE
  #endif
#endif


// The following (except #include <malloc.h> and _M_IX86_FP ??) can likely be
// removed as gcc 4.1 and msvc 2008 are not supported anyways.
#if EIGEN_COMP_MSVC
  #include <malloc.h> // for _aligned_malloc -- need it regardless of whether vectorization is enabled
  #if (EIGEN_COMP_MSVC >= 1500) // 2008 or later
    // a user reported that in 64-bit mode, MSVC doesn't care to define _M_IX86_FP.
    #if (defined(_M_IX86_FP) && (_M_IX86_FP >= 2)) || EIGEN_ARCH_x86_64
      #define EIGEN_SSE2_ON_MSVC_2008_OR_LATER
    #endif
  #endif
#endif


/** \brief Namespace containing all symbols from the %Eigen library. */
namespace Eigen {

inline static const char *SimdInstructionSetsInUse(void) {
  return "None";
}

} // end namespace Eigen


#endif // EIGEN_CONFIGURE_VECTORIZATION_H
