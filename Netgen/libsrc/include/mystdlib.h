#ifndef FILE_MYSTDLIB
#define FILE_MYSTDLIB


#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

#ifdef OLDCINCLUDE

// e.g., CC compiler on SGI
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <ctype.h>
#include <time.h>

#else
 
// new standard
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <ctime>
#endif



#include <new>
#include <string>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


/*** Windows headers ***/
#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
#include <afxwin.h>
#include <afxmt.h>
#include <windows.h>
#undef WIN32_LEAN_AND_MEAN
#include <winnt.h>
#endif /* WIN32 */


/*
extern void* operator new(std::size_t) throw (std::bad_alloc);
extern void* operator new[](std::size_t) throw (std::bad_alloc);
extern void operator delete(void*) throw();
extern void operator delete[](void*) throw();
*/


extern int mem_alloc;
extern int mem_total_alloc;
extern int mem_max_alloc;
extern int mem_total_alloc_array;
extern int mem_total_alloc_table;


using namespace std;

#endif
