///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// defines.h    Header file for all the Tetgen source files needed.          //
//              Defines switches (Optional) used at compilation time.        //
//              Includes the most general used head files for all C/C++      //
//              program code needed. Defines marcos used throughout all      //
//              the source files.                                            //
//                                                                           //
// Tetgen Version 1.0 beta                                                   //
// July, 2001                                                                //
//                                                                           //
// Si hang                                                                   //
// Email: sihang@weboo.com                                                   //
// http://www.weboo.com/sh/tetgen.htm                                        //
//                                                                           //
// You are free to use, copy and modify the sources under certain            //
// circumstances, provided this copyright notice remains intact.             //
// See the file LICENSE for details.                                         //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#ifndef definesH
#define definesH

// If yours is not a Unix system,  define the  NO_TIMER  compiler  switch to
//   remove the Unix-specific timing code.

// #define NO_TIMER

// Define to disable assertions. Generally the assert() operater only be
//   used in developping stage, to catch the casual mistakes in programming.

// #define NDEBUG

// To insert lots of self-checks for internal errors, define the SELF_CHECK
//   symbol.  This will slow down the program significantly.  It is best to
//   define the symbol using the -DSELF_CHECK compiler switch, but you could
//   write "#define SELF_CHECK" below.  If you are modifying this code, I
//   recommend you turn self-checks on.

// #define SELF_CHECK

// For single precision ( which will save some  memory and  reduce paging ),
//   define the symbol  SINGLE  by using the  -DSINGLE compiler switch or by
//   writing "#define SINGLE" below.
//
// For double precision ( which will allow you to refine meshes to a smaller
//   edge length), leave SINGLE undefined.
//
// Double precision  uses  more  memory,  but improves the resolution of the
//   meshes you can  generate with Triangle.  It also reduces the likelihood
//   of a  floating  exception due to overflow.   Finally, it is much faster
//   than  single precision on  64-bit  architectures like the DEC Alpha.  I
//   recommend double precision unless you want to generate a mesh for which
//   you do not have enough memory.

// #define SINGLE

#ifdef SINGLE
  #define REAL float
#else
  #define REAL double
#endif 	// not defined SINGLE

// numbers that speaks for theirself.

#define PI 3.141592653589793238462643383279502884197169399375105820974944592308

#define SQUAREROOTTWO 1.4142135623730950488016887242096980785696718753769480732

#define ONETHIRD 0.333333333333333333333333333333333333333333333333333333333333

// For efficiency, a variety of data structures are allocated in bulk.  The
//   following constants determine how many of each structure is allocated
//   at once.

#define TRIPERBLOCK 4092           // Number of triangles allocated at once.
#define SHELLEPERBLOCK 508       // Number of shell edges allocated at once.
#define POINTPERBLOCK 4092            // Number of points allocated at once.
#define VIRUSPERBLOCK 1020   // Number of virus triangles allocated at once.
#define TETPERBLOCK 8188        // Number of tetrahedrons allocated at once.
#define SUBFACEPERBLOCK 1020        // Number of subfaces allocated at once.
#define SUBSEGPERBLOCK 1020      // Number of subsegments allocated at once.
#define POINTPERBLOCK 4092            // Number of points allocated at once.
// Number of encroached segments allocated at once.
#define BADSEGMENTPERBLOCK 252
// Number of encroached segments allocated at once.
#define BADSHELLFACEPERBLOCK 508
// Number of skinny triangles allocated at once.
#define BADTRIPERBLOCK 4092
// Number of skinny tetrahedras allocated at once.
#define BADTETPERBLOCK 8188

// The point marker DEADPOINT  is an arbitrary number chosen large enough to
//   (hopefully) not conflict with user boundary markers.  Make sure that it
//   is small enough to fit into your machine's integer size.

#define DEADPOINT -1073741824

// The nonsolid flag  NONSOLIDFLAG is an arbitrary number chosen large enou-
//   gh to (hopefully)not conflict with user boundary markers.Make sure that
//   it is small enough to fit into your machine's integer size.

#define NONSOLIDFLAG  -1342177279

// Maximum number of characters in a file name (including the null).

#ifndef FILENAMESIZE
  #define FILENAMESIZE 512
#endif

// Maximum number of characters in a line  read  from a file ( including the
//   null).

#ifndef INPUTLINESIZE
  #define INPUTLINESIZE 512
#endif

// Constant for algorithms based on random sampling.  This constant
//   have been chosen empirically to optimize its respective algorithms.

// Used for the point location scheme of Mucke, Saias, and Zhu, to decide
//   how large a random sample of triangles to inspect.
#define SAMPLEFACTOR 11

// Here is the most general used head files for all C/C++ program code
//   needed.

#include <stdio.h>                  // standard IO: FILE, NULL (*), EOF, ...
#include <stdlib.h>        // standard lib: abort(), system(), getenv(), ...
#include <string.h>        // declarations for string manipulation functions.
#include <math.h>                     // math lib: sin(), sqrt(), pow(), ...
#include <assert.h>
#ifndef NO_TIMER
  #include <sys/time.h>
#else
  #include <time.h>            // definitions/declarations for time routines.
#endif // defined NO_TIMER
#ifdef INTEL_MSC_TURBOC
  #include <float.h>                 // some compilers will not need float.h.
#endif // defined INTEL_MSC_TURBOC

// If you will compile and run this code on Intel CPUs, Maybe there is some
//   choices must be made by user to correctly execute Jonathan Schewck's
//   code for arbitrary floating-point precision arithmetic and robust geom-
//   etric predicates.  For more detail please see:
//
//            http://www.cs.cmu.edu/~quake/robust.pc.html.

// If you use Microsoft C/C++ or TOURB C/C++ or BORLAND C/C++, define the
//   symbol INTEL_MSC_TURBOC  by using -DINTEL_MSC_TURBOC compiler switch
//   or by writing #define INTEL_MSC_TURBOC as follows.

// #define INTEL_MSC_TURBOC

// If you use gcc running under Linux, define the symbol INTEL_GCC_LINUX. Be
//   sure to undefine the symbol INTEL_MSC_TURBOC.

// #define INTEL_GCC_LINUX

// If you use gcc but not running under linux, use the following symbol. Be
//   sure to undefine the symbol INTEL_MSC_TURBOC and INTEL_GCC_LINUX.

// #define INTEL_GCC

// Routines for Arbitrary Precision Floating-point Arithmetic and Fast
//   Robust Geometric Predicates.

void exactinit();
REAL orient2d(REAL* pa, REAL* pb, REAL* pc);
REAL incircle(REAL* pa, REAL* pb, REAL* pc, REAL* pd);
REAL orient3d(REAL* pa, REAL* pb, REAL* pc, REAL* pd);
REAL insphere(REAL* pa, REAL* pb, REAL* pc, REAL* pd, REAL* pe);

#endif // #ifndef definesH
