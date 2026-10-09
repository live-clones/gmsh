/**
 * @file dlmacros.h
 * @brief Misc macros
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-10-08
 */



#ifndef DL_MACRO_H
#define DL_MACRO_H



/******************************************************************************
* PORTABILITY MACROS **********************************************************
******************************************************************************/


/* check whether or not we can use C99 stuf */
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L)
  #define __DL_RESTRICT restrict
#else
  #define __DL_RESTRICT
#endif


/* include funkiness */
#if defined(__linux__)
  #include <endian.h>
  #define n16toh(x) be16toh(x)
  #define n32toh(x) be32toh(x)
  #define n64toh(x) be64toh(x)
  #define hton16(x) htobe16(x)
  #define hton32(x) htobe32(x)
  #define hton64(x) htobe64(x)
  #define DL_HTONXX_AVAILABLE
#elif defined(__FreeBSD__) || defined(__NetBSD__)
  #include <sys/endian.h>
  #define n16toh(x) be16toh(x)
  #define n32toh(x) be32toh(x)
  #define n64toh(x) be64toh(x)
  #define hton16(x) htobe16(x)
  #define hton32(x) htobe32(x)
  #define hton64(x) htobe64(x)
  #define DL_HTONXX_AVAILABLE
#elif defined(__OpenBSD__)
  #include <sys/types.h>
  #define n16toh(x) betoh16(x)
  #define n32toh(x) betoh32(x)
  #define n64toh(x) betoh64(x)
  #define hton16(x) htobe16(x)
  #define hton32(x) htobe32(x)
  #define hton64(x) htobe64(x)
  #define DL_HTONXX_AVAILABLE
#endif



/******************************************************************************
* TUNING MACROS ***************************************************************
******************************************************************************/


/* tuning parameters */
#define MIN_QUICKSORT_SIZE (16) 


#ifndef CACHE_LINE_SIZE
  #define CACHE_LINE_SIZE (64)
#endif


#ifndef MEM_BLOCK_SIZE
  #define MEM_BLOCK_SIZE (0x1000)
#endif


/* Binary numbers -- generated via python:
 * for i in range(0,64):
 *   print("#define BIN%02d 0x%016x" % (i,2**i))
 */
#define BIN00 (0x0000000000000001UL)
#define BIN01 (0x0000000000000002UL)
#define BIN02 (0x0000000000000004UL)
#define BIN03 (0x0000000000000008UL)
#define BIN04 (0x0000000000000010UL)
#define BIN05 (0x0000000000000020UL)
#define BIN06 (0x0000000000000040UL)
#define BIN07 (0x0000000000000080UL)
#define BIN08 (0x0000000000000100UL)
#define BIN09 (0x0000000000000200UL)
#define BIN10 (0x0000000000000400UL)
#define BIN11 (0x0000000000000800UL)
#define BIN12 (0x0000000000001000UL)
#define BIN13 (0x0000000000002000UL)
#define BIN14 (0x0000000000004000UL)
#define BIN15 (0x0000000000008000UL)
#define BIN16 (0x0000000000010000UL)
#define BIN17 (0x0000000000020000UL)
#define BIN18 (0x0000000000040000UL)
#define BIN19 (0x0000000000080000UL)
#define BIN20 (0x0000000000100000UL)
#define BIN21 (0x0000000000200000UL)
#define BIN22 (0x0000000000400000UL)
#define BIN23 (0x0000000000800000UL)
#define BIN24 (0x0000000001000000UL)
#define BIN25 (0x0000000002000000UL)
#define BIN26 (0x0000000004000000UL)
#define BIN27 (0x0000000008000000UL)
#define BIN28 (0x0000000010000000UL)
#define BIN29 (0x0000000020000000UL)
#define BIN30 (0x0000000040000000UL)
#define BIN31 (0x0000000080000000UL)
#define BIN32 (0x0000000100000000UL)
#define BIN33 (0x0000000200000000UL)
#define BIN34 (0x0000000400000000UL)
#define BIN35 (0x0000000800000000UL)
#define BIN36 (0x0000001000000000UL)
#define BIN37 (0x0000002000000000UL)
#define BIN38 (0x0000004000000000UL)
#define BIN39 (0x0000008000000000UL)
#define BIN40 (0x0000010000000000UL)
#define BIN41 (0x0000020000000000UL)
#define BIN42 (0x0000040000000000UL)
#define BIN43 (0x0000080000000000UL)
#define BIN44 (0x0000100000000000UL)
#define BIN45 (0x0000200000000000UL)
#define BIN46 (0x0000400000000000UL)
#define BIN47 (0x0000800000000000UL)
#define BIN48 (0x0001000000000000UL)
#define BIN49 (0x0002000000000000UL)
#define BIN50 (0x0004000000000000UL)
#define BIN51 (0x0008000000000000UL)
#define BIN52 (0x0010000000000000UL)
#define BIN53 (0x0020000000000000UL)
#define BIN54 (0x0040000000000000UL)
#define BIN55 (0x0080000000000000UL)
#define BIN56 (0x0100000000000000UL)
#define BIN57 (0x0200000000000000UL)
#define BIN58 (0x0400000000000000UL)
#define BIN59 (0x0800000000000000UL)
#define BIN60 (0x1000000000000000UL)
#define BIN61 (0x2000000000000000UL)
#define BIN62 (0x4000000000000000UL)
#define BIN63 (0x8000000000000000UL)




/******************************************************************************
* FUNCTION MACROS *************************************************************
******************************************************************************/


#define dl_bitsize(a) (sizeof(a)*8u)


#define dl_maxshift(a,b) (dl_min(b,(dl_bitsize(a)-1)))


#define dl_min(a,b) ((a) > (b) ? (b) : (a))


#define dl_max(a,b) ((a) < (b) ? (b) : (a))


#define dl_swap(a,b) \
  do { \
    __typeof__(b) _swap_var = (b); \
    (b) = (a); \
    (a) = _swap_var; \
  } while(0)


#define dl_safe_diff(a,b) \
  (((a) > (b)) ? ((a) - (b)) : ((b) - (a)))


#define dl_storemax(max,v) (((max) < (v)) ? ((max) = (v)) : (max))


#define dl_storemin(min,v) (((min) > (v)) ? ((min) = (v)) : (min))


/* count leading zeros of arbitrary size number */
#if defined(__GNUC__) || defined(__INTEL_COMPILER)
  #define dl_clz(a) \
    ((size_t)( (a) == 0 ? dl_bitsize(a) : \
      (sizeof(a) == sizeof(unsigned long long) ? \
        (size_t)__builtin_clzll((unsigned long long)a) \
        : (size_t)(__builtin_clz((unsigned int)a) - \
          (dl_bitsize(unsigned int) - dl_bitsize(a))) \
      ) \
    ))
#else
  /* cause trouble */
#endif


#define dl_near_equal(a,b) \
  ((a) == (b) ? 1 : ( \
      (fabs(a) > fabs(b) ? (fabs(((a)-(b))/(fabs(a)+1.0)) < 0.001) : \
        (fabs(((a)-(b))/(fabs(b)+1.0)) < 0.001))))


#ifdef _MSC_VER
/* I think I need to include the xmm- something header... */
#else
static inline void _mm_pause(void)
{
#if defined(__x86_64__) || defined(__i386__) /* For Gmsh */
  __asm__ ( "pause;" );
#elif defined(__aarch64__) || defined(__arm__)
  __asm__ __volatile__ ( "yield" );
#endif
}
#endif

   
#endif
