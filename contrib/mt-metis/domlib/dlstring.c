/**
 * @file dlstring.c
 * @brief Functions for manipulating and processing strings
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-10-08
 */




#ifndef DL_STRING_C
#define DL_STRING_C




#include "dlstring.h"
#include "ctype.h"




/******************************************************************************
* CONSTANTS *******************************************************************
******************************************************************************/


static char const __UPPERIZE_TABLE[] = {
  [  0] =   0, [  1] =   1, [  2] =   2, [  3] =   3, [  4] =   4, 
  [  5] =   5, [  6] =   6, [  7] =   7, [  8] =   8, [  9] =   9, 
  [ 10] =  10, [ 11] =  11, [ 12] =  12, [ 13] =  13, [ 14] =  14, 
  [ 15] =  15, [ 16] =  16, [ 17] =  17, [ 18] =  18, [ 19] =  19, 
  [ 20] =  20, [ 21] =  21, [ 22] =  22, [ 23] =  23, [ 24] =  24, 
  [ 25] =  25, [ 26] =  26, [ 27] =  27, [ 28] =  28, [ 29] =  29, 
  [ 30] =  30, [ 31] =  31, [ 32] =  32, [ 33] =  33, [ 34] =  34, 
  [ 35] =  35, [ 36] =  36, [ 37] =  37, [ 38] =  38, [ 39] =  39, 
  [ 40] =  40, [ 41] =  41, [ 42] =  42, [ 43] =  43, [ 44] =  44, 
  [ 45] =  45, [ 46] =  46, [ 47] =  47, [ 48] =  48, [ 49] =  49, 
  [ 50] =  50, [ 51] =  51, [ 52] =  52, [ 53] =  53, [ 54] =  54, 
  [ 55] =  55, [ 56] =  56, [ 57] =  57, [ 58] =  58, [ 59] =  59, 
  [ 60] =  60, [ 61] =  61, [ 62] =  62, [ 63] =  63, [ 64] =  64, 
  [ 65] =  65, [ 66] =  66, [ 67] =  67, [ 68] =  68, [ 69] =  69, 
  [ 70] =  70, [ 71] =  71, [ 72] =  72, [ 73] =  73, [ 74] =  74, 
  [ 75] =  75, [ 76] =  76, [ 77] =  77, [ 78] =  78, [ 79] =  79, 
  [ 80] =  80, [ 81] =  81, [ 82] =  82, [ 83] =  83, [ 84] =  84, 
  [ 85] =  85, [ 86] =  86, [ 87] =  87, [ 88] =  88, [ 89] =  89, 
  [ 90] =  90, [ 91] =  91, [ 92] =  92, [ 93] =  93, [ 94] =  94, 
  [ 95] =  95, [ 96] =  96, ['a'] = 'A', ['b'] = 'B', ['c'] = 'C', 
  ['d'] = 'D', ['e'] = 'E', ['f'] = 'F', ['g'] = 'G', ['h'] = 'H', 
  ['i'] = 'I', ['j'] = 'J', ['k'] = 'K', ['l'] = 'L', ['m'] = 'M', 
  ['n'] = 'N', ['o'] = 'O', ['p'] = 'P', ['q'] = 'Q', ['r'] = 'R', 
  ['s'] = 'S', ['t'] = 'T', ['u'] = 'U', ['v'] = 'V', ['w'] = 'W', 
  ['x'] = 'X', ['y'] = 'Y', ['z'] = 'Z', [123] = 123, [124] = 124, 
  [125] = 125, [126] = 126, [127] = 127
};




/******************************************************************************
* PUBLIC FUNCTIONS ************************************************************
******************************************************************************/


size_t dl_string_split(const char * const string, const char * const delims, 
    char *** ptrs)
{
  size_t i,j,n,noc;
  char c;
  char * base, * ind;
  char ** oc;

  /* create a character map of all 0's */
  char map[128] = {0};
  n = strlen(delims);

  /* mark my delimiters */
  for (i=0;i<n;++i) {
    map[(int)delims[i]] = 1;
  }

  /* count occurences and allocate our split string */
  noc = 1;
  for (i=0,noc=0;(c = string[i]) != '\0';++i) {
    if (map[(int)c]) {
      ++noc;
    }
  }

  /* create our memory locations */
  base = (char*)malloc(i+(sizeof(char*)*noc));
  ind = base + (sizeof(char*)*noc);
  oc = (char**)base;

  /* copy over chunks my string */
  i=j=0;
  oc[0] = ind;
  while ((c = *ind) != '\0') {
    if (map[(int)c]) {
      ind[j] = string[i];
    } else {
      ind[j] = '\0';
      oc[j++] = ind;
    }
    ++ind;
  }

  /* set our output */
  *ptrs = (char**)base;

  return j;
}

size_t dl_string_occurances(const char * string, const char * substr)
{
  size_t noc,n;
  size_t i,j,k;
  char c;

  /* create a character map of all 0's */
  char map[128] = {0};
  if ((n = strlen(substr)) == 0) {
    /* if we have a length 0 substring, quit */
    return 0;
  }
  for (i=0;i<n;++i) {
    map[i] = 1;
  }

  noc = 0;
  /* this is stupid, I should start at 0 and count forward */
  i = n-1;
  while ((c = string[i]) != '\0') {
    /* see if we hit part of the substr */
    if (map[(int)c]) {
      for(k=n-1,j=i;k>0;--j,--k) {
        if (string[j] != substr[k]) {
          break;
        }
      }
      if (i-j == n) {
        ++noc;
      }
    }
    i += n;
  }

  return noc;
}


int dl_string_endswith(const char * const string, const char * const suffix)
{
  size_t nstr, nsuf;

  if (!string || !suffix) {
    return 0;
  } else {
    nstr = strlen(string);
    nsuf = strlen(suffix);
    if (nsuf > nstr) {
      return 0;
    } else {
      return strncmp(string+nstr-nsuf,suffix,nsuf) == 0;
    }
  }
}


int dl_string_lowerize(char * const string)
{
  size_t i = 0;
  while (string[i] != '\0') {
    string[i] = tolower(string[i]);
    ++i;
  }

  return 1;
}


int dl_string_nlowerize(char * const string, const size_t len)
{
  size_t i = 0;
  while (string[i] != '\0' && i < len) {
    string[i] = tolower(string[i]);
    ++i;
  }

  return 1;
}


int dl_string_upperize(char * const string)
{
  size_t i = 0;
  while (string[i] != '\0') {
    string[i] = toupper(string[i]);
    ++i;
  }

  return 1;
}


int dl_string_nupperize(char * const string, const size_t len)
{
  size_t i = 0;
  while (string[i] != '\0' && i < len) {
    string[i] = toupper(string[i]);
    ++i;
  }

  return 1;
}


int dl_strncmp_nocase(
    char const * const a,
    char const * const b,
    size_t n)
{
  int z;
  char x, y;
  int * diff;
  size_t i;

  diff = int_alloc(n);

  z = 0;
  for (i=0;i<n;++i) {
    x = __UPPERIZE_TABLE[(int)a[i]];
    y = __UPPERIZE_TABLE[(int)b[i]];
    if (x < y) {
      z = -1;
      goto END;
    } else if (y > x) {
      z = 1;
      goto END;
    }
    /* null character is reached */
    if (x == 0) {
      goto END; 
    }
  }

  END:

  dl_free(diff);

  return z;
}




#endif
