/* $Id: gl2gif.cpp,v 1.22 2006-05-17 01:19:06 geuzaine Exp $ */
/*
 * GL2GIF, an OpenGL to GIF Printing Library
 * Copyright (C) 1999-2003 Christophe Geuzaine <geuz@geuz.org>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of either:
 *
 * a) the GNU Library General Public License as published by the Free
 * Software Foundation, either version 2 of the License, or (at your
 * option) any later version; or
 *
 * b) the GL2PS License as published by Christophe Geuzaine, either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See either
 * the GNU Library General Public License or the GL2PS License for
 * more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library in the file named "COPYING.LGPL";
 * if not, write to the Free Software Foundation, Inc., 675 Mass Ave,
 * Cambridge, MA 02139, USA.
 *
 * You should have received a copy of the GL2PS License with this
 * library in the file named "COPYING.GL2PS"; if not, I will be glad
 * to provide one.
 */

/* 
 * Warning: This code is really a dirty hack. It SHOULD be cleaned
 * (and most of all, all the static variables should be removed).
 *
 * It is based on 
 *
 * - libppm3.c - ppm utility library part 3
 * - ppmquant.c - quantize the colors in a pixmap down to a specified number
 *
 * Copyright (C) 1989, 1991 by Jef Poskanzer.
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose and without fee is hereby granted, provided
 * that the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation.  This software is provided "as is" without express or
 * implied warranty.
 *
 * and 
 *
 * - ppmtogif.c - read a portable pixmap and produce a GIF file
 *
 * Based on GIFENCOD by David Rowley <mgardi@watdscu.waterloo.edu>.A
 * Lempel-Zim compression based on "compress".
 *
 * Modified by Marcel Wijkstra <wijkstra@fwi.uva.nl>
 *
 * Copyright (C) 1989 by Jef Poskanzer.
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose and without fee is hereby granted, provided
 * that the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation.  This software is provided "as is" without express or
 * implied warranty.
 *
 * The Graphics Interchange Format(c) is the Copyright property of
 * CompuServe Incorporated.  GIF(sm) is a Service Mark property of
 * CompuServe Incorporated.
 *
 */

#include "gl2gif.h"

/* PPM colormap routines */

#define HASH_SIZE 20023
#define ppm_hashpixel(p) ( ( (int) (p) & 0x7fffffff ) % HASH_SIZE )

static int static_red[MAX_GIFCOLORS];
static int static_green[MAX_GIFCOLORS];
static int static_blue[MAX_GIFCOLORS];
static int static_perm[MAX_GIFCOLORS], static_permi[MAX_GIFCOLORS];
static int static_nbcolors;
static pixel **static_pixels;
static colorhash_table static_cht;

colorhash_table ppm_alloccolorhash()
{
  colorhash_table cht;
  int i;

  cht = (colorhash_table) Malloc(HASH_SIZE * sizeof(colorhist_list));

  for(i = 0; i < HASH_SIZE; ++i)
    cht[i] = (colorhist_list) 0;

  return cht;
}

void ppm_freecolorhash(colorhash_table cht)
{
  int i;
  colorhist_list chl, chlnext;

  for(i = 0; i < HASH_SIZE; ++i)
    for(chl = cht[i]; chl != (colorhist_list) 0; chl = chlnext) {
      chlnext = chl->next;
      Free((char *)chl);
    }
  Free((char *)cht);
}

colorhash_table ppm_computecolorhash(pixel ** const pixels,
                                     const int cols, const int rows,
                                     const int maxcolors, int *const colorsP)
{
  colorhash_table cht;
  const pixel *pP;
  colorhist_list chl;
  int col, row, hash;

  cht = ppm_alloccolorhash();
  *colorsP = 0;

  /* Go through the entire image, building a hash table of colors. */
  for(row = 0; row < rows; ++row)
    for(col = 0, pP = pixels[row]; col < cols; ++col, ++pP) {
      hash = ppm_hashpixel(*pP);
      for(chl = cht[hash]; chl != (colorhist_list) 0; chl = chl->next)
        if(PPM_EQUAL(chl->ch.color, *pP))
          break;
      if(chl != (colorhist_list) 0)
        ++(chl->ch.value);
      else {
        if(++(*colorsP) > maxcolors) {
          ppm_freecolorhash(cht);
          return (colorhash_table) 0;
        }
        chl = (colorhist_list) Malloc(sizeof(struct colorhist_list_item));
        chl->ch.color = *pP;
        chl->ch.value = 1;
        chl->next = cht[hash];
        cht[hash] = chl;
      }
    }

  return cht;
}

int ppm_addtocolorhash(colorhash_table cht, const pixel * const colorP,
                       const int value)
{
  register int hash;
  register colorhist_list chl;

  chl = (colorhist_list) Malloc(sizeof(struct colorhist_list_item));
  hash = ppm_hashpixel(*colorP);
  chl->ch.color = *colorP;
  chl->ch.value = value;
  chl->next = cht[hash];
  cht[hash] = chl;
  return 0;
}

colorhist_vector ppm_colorhashtocolorhist(const colorhash_table cht,
                                          const int maxcolors)
{
  colorhist_vector chv;
  colorhist_list chl;
  int i, j;

  /* Now collate the hash table into a simple colorhist array. */
  chv = (colorhist_vector) Malloc(maxcolors * sizeof(struct colorhist_item));
  /* Loop through the hash table. */
  j = 0;
  for(i = 0; i < HASH_SIZE; ++i)
    for(chl = cht[i]; chl != (colorhist_list) 0; chl = chl->next) {
      /* Add the new entry. */
      chv[j] = chl->ch;
      ++j;
    }

  /* All done. */
  return chv;
}

colorhash_table ppm_colorhisttocolorhash(const colorhist_vector chv,
                                         const int colors)
{
  colorhash_table cht;
  int i, hash;
  pixel color;
  colorhist_list chl;

  cht = ppm_alloccolorhash();   /* Initializes to NULLs */

  for(i = 0; i < colors; ++i) {
    color = chv[i].color;
    hash = ppm_hashpixel(color);
    for(chl = cht[hash]; chl != (colorhist_list) 0; chl = chl->next)
      if(PPM_EQUAL(chl->ch.color, color))
        Msg(GERROR, "GIF: same color found twice - %d %d %d", PPM_GETR(color),
            PPM_GETG(color), PPM_GETB(color));
    chl = (colorhist_list) Malloc(sizeof(struct colorhist_list_item));
    chl->ch.color = color;
    chl->ch.value = i;
    chl->next = cht[hash];
    cht[hash] = chl;
  }

  return cht;
}

colorhist_vector ppm_computecolorhist(pixel ** const pixels,
                                      const int cols, const int rows,
                                      const int maxcolors, int *const colorsP)
{
  colorhash_table cht;
  colorhist_vector chv;

  cht = ppm_computecolorhash(pixels, cols, rows, maxcolors, colorsP);
  if(cht == (colorhash_table) 0)
    return (colorhist_vector) 0;
  chv = ppm_colorhashtocolorhist(cht, maxcolors);
  ppm_freecolorhash(cht);
  return chv;
}


int ppm_lookupcolor(const colorhash_table cht, const pixel * const colorP)
{
  int hash;
  colorhist_list chl;

  hash = ppm_hashpixel(*colorP);
  for(chl = cht[hash]; chl != (colorhist_list) 0; chl = chl->next)
    if(PPM_EQUAL(chl->ch.color, *colorP))
      return chl->ch.value;

  return -1;
}

void ppm_freecolorhist(colorhist_vector chv)
{
  Free((char *)chv);
}

static int colorstobpp(int colors)
{
  int bpp;

  if(colors <= 2)
    bpp = 1;
  else if(colors <= 4)
    bpp = 2;
  else if(colors <= 8)
    bpp = 3;
  else if(colors <= 16)
    bpp = 4;
  else if(colors <= 32)
    bpp = 5;
  else if(colors <= 64)
    bpp = 6;
  else if(colors <= 128)
    bpp = 7;
  else if(colors <= 256)
    bpp = 8;
  else {
    Msg(GERROR, "GIF: can't happen: too many colors");
    bpp = 8;
  }

  return bpp;
}


static int sqr(int x)
{
  return x * x;
}

static int closestcolor(pixel color)
{
  int i, r, g, b, d, imin = 0, dmin;

  r = (int)PPM_GETR(color);
  g = (int)PPM_GETG(color);
  b = (int)PPM_GETB(color);

  dmin = 1000000;
  for(i = 0; i < static_nbcolors; i++) {
    d =
      sqr(r - static_red[i]) + sqr(g - static_green[i]) + sqr(b -
                                                              static_blue[i]);
    if(d < dmin) {
      dmin = d;
      imin = i;
    }
  }
  ppm_addtocolorhash(static_cht, &color, static_permi[imin]);
  return imin;
}


static int GetPixel(int x, int y)
{
  int color;

  color = ppm_lookupcolor(static_cht, &static_pixels[y][x]);
  if(color == -1)
    color = closestcolor(static_pixels[y][x]);
  else
    color = static_perm[color];
  return color;
}


/* PPM quantization */

/* #define LARGE_NORM */
#define LARGE_LUM

/* #define REP_CENTER_BOX */
/* #define REP_AVERAGE_COLORS */
#define REP_AVERAGE_PIXELS

typedef struct box *box_vector;
struct box
{
  int ind;
  int colors;
  int sum;
};

static int redcompare(const void *ch1, const void *ch2)
{
  return (int)PPM_GETR(((colorhist_vector) ch1)->color) -
    (int)PPM_GETR(((colorhist_vector) ch2)->color);
}

static int greencompare(const void *ch1, const void *ch2)
{
  return (int)PPM_GETG(((colorhist_vector) ch1)->color) -
    (int)PPM_GETG(((colorhist_vector) ch2)->color);
}

static int bluecompare(const void *ch1, const void *ch2)
{
  return (int)PPM_GETB(((colorhist_vector) ch1)->color) -
    (int)PPM_GETB(((colorhist_vector) ch2)->color);
}

static int sumcompare(const void *b1, const void *b2)
{
  return (((box_vector) b2)->sum - ((box_vector) b1)->sum);
}

/*
 * Here is the fun part, the median-cut colormap generator.  This is based
 * on Paul Heckbert's paper "Color Image Quantization for Frame Buffer
 * Display", SIGGRAPH '82 Proceedings, page 297.
 */

static colorhist_vector mediancut(colorhist_vector chv, int colors,
                                  int sum, pixval maxval, int newcolors)
{
  colorhist_vector colormap;
  box_vector bv;
  register int bi, i;
  int boxes;

  bv = (box_vector) malloc(sizeof(struct box) * newcolors);
  colormap =
    (colorhist_vector) malloc(sizeof(struct colorhist_item) * newcolors);
  if(bv == (box_vector) 0 || colormap == (colorhist_vector) 0)
    Msg(GERROR, "GIF: out of memory");
  for(i = 0; i < newcolors; ++i)
    PPM_ASSIGN(colormap[i].color, 0, 0, 0);

  /*
   * Set up the initial box.
   */
  bv[0].ind = 0;
  bv[0].colors = colors;
  bv[0].sum = sum;
  boxes = 1;

  /*
   * Main loop: split boxes until we have enough.
   */
  while(boxes < newcolors) {
    register int indx, clrs;
    int sm;
    register int minr, maxr, ming, maxg, minb, maxb, v;
    int halfsum, lowersum;

    /*
     * Find the first splittable box.
     */
    for(bi = 0; bi < boxes; ++bi)
      if(bv[bi].colors >= 2)
        break;
    if(bi == boxes)
      break;    /* ran out of colors! */
    indx = bv[bi].ind;
    clrs = bv[bi].colors;
    sm = bv[bi].sum;

    /*
     * Go through the box finding the minimum and maximum of each
     * component - the boundaries of the box.
     */
    minr = maxr = PPM_GETR(chv[indx].color);
    ming = maxg = PPM_GETG(chv[indx].color);
    minb = maxb = PPM_GETB(chv[indx].color);
    for(i = 1; i < clrs; ++i) {
      v = PPM_GETR(chv[indx + i].color);
      if(v < minr)
        minr = v;
      if(v > maxr)
        maxr = v;
      v = PPM_GETG(chv[indx + i].color);
      if(v < ming)
        ming = v;
      if(v > maxg)
        maxg = v;
      v = PPM_GETB(chv[indx + i].color);
      if(v < minb)
        minb = v;
      if(v > maxb)
        maxb = v;
    }

    /*
     * Find the largest dimension, and sort by that component.  I have
     * included two methods for determining the "largest" dimension;
     * first by simply comparing the range in RGB space, and second
     * by transforming into luminosities before the comparison.  You
     * can switch which method is used by switching the commenting on
     * the LARGE_ defines at the beginning of this source file.
     */
#ifdef LARGE_NORM
    if(maxr - minr >= maxg - ming && maxr - minr >= maxb - minb)
      qsort((char *)&(chv[indx]), clrs, sizeof(struct colorhist_item),
            redcompare);
    else if(maxg - ming >= maxb - minb)
      qsort((char *)&(chv[indx]), clrs, sizeof(struct colorhist_item),
            greencompare);
    else
      qsort((char *)&(chv[indx]), clrs, sizeof(struct colorhist_item),
            bluecompare);
#endif

#ifdef LARGE_LUM
    pixel p;
    float rl, gl, bl;

    PPM_ASSIGN(p, maxr - minr, 0, 0);
    rl = PPM_LUMIN(p);
    PPM_ASSIGN(p, 0, maxg - ming, 0);
    gl = PPM_LUMIN(p);
    PPM_ASSIGN(p, 0, 0, maxb - minb);
    bl = PPM_LUMIN(p);

    if(rl >= gl && rl >= bl)
      qsort((char *)&(chv[indx]), clrs, sizeof(struct colorhist_item),
            &redcompare);
    else if(gl >= bl)
      qsort((char *)&(chv[indx]), clrs, sizeof(struct colorhist_item),
            &greencompare);
    else
      qsort((char *)&(chv[indx]), clrs, sizeof(struct colorhist_item),
            &bluecompare);
#endif

    /*
     * Now find the median based on the counts, so that about half the
     * pixels (not colors, pixels) are in each subdivision.
     */
    lowersum = chv[indx].value;
    halfsum = sm / 2;
    for(i = 1; i < clrs - 1; ++i) {
      if(lowersum >= halfsum)
        break;
      lowersum += chv[indx + i].value;
    }

    /*
     * Split the box, and sort to bring the biggest boxes to the top.
     */
    bv[bi].colors = i;
    bv[bi].sum = lowersum;
    bv[boxes].ind = indx + i;
    bv[boxes].colors = clrs - i;
    bv[boxes].sum = sm - lowersum;
    ++boxes;
    qsort((char *)bv, boxes, sizeof(struct box), sumcompare);
  }

  /*
   * Ok, we've got enough boxes.  Now choose a representative color for
   * each box.  There are a number of possible ways to make this choice.
   * One would be to choose the center of the box; this ignores any structure
   * within the boxes.  Another method would be to average all the colors in
   * the box - this is the method specified in Heckbert's paper.  A third
   * method is to average all the pixels in the box.  You can switch which
   * method is used by switching the commenting on the REP_ defines at
   * the beginning of this source file.
   */
  for(bi = 0; bi < boxes; ++bi) {

#ifdef REP_CENTER_BOX
    register int indx = bv[bi].ind;
    register int clrs = bv[bi].colors;
    register int minr, maxr, ming, maxg, minb, maxb, v;

    minr = maxr = PPM_GETR(chv[indx].color);
    ming = maxg = PPM_GETG(chv[indx].color);
    minb = maxb = PPM_GETB(chv[indx].color);
    for(i = 1; i < clrs; ++i) {
      v = PPM_GETR(chv[indx + i].color);
      minr = min(minr, v);
      maxr = max(maxr, v);
      v = PPM_GETG(chv[indx + i].color);
      ming = min(ming, v);
      maxg = max(maxg, v);
      v = PPM_GETB(chv[indx + i].color);
      minb = min(minb, v);
      maxb = max(maxb, v);
    }
    PPM_ASSIGN(colormap[bi].color, (minr + maxr) / 2, (ming + maxg) / 2,
               (minb + maxb) / 2);
#endif

#ifdef REP_AVERAGE_COLORS
    register int indx = bv[bi].ind;
    register int clrs = bv[bi].colors;
    register long r = 0, g = 0, b = 0;

    for(i = 0; i < clrs; ++i) {
      r += PPM_GETR(chv[indx + i].color);
      g += PPM_GETG(chv[indx + i].color);
      b += PPM_GETB(chv[indx + i].color);
    }
    r = r / clrs;
    g = g / clrs;
    b = b / clrs;
    PPM_ASSIGN(colormap[bi].color, r, g, b);
#endif

#ifdef REP_AVERAGE_PIXELS
    register int indx = bv[bi].ind;
    register int clrs = bv[bi].colors;
    register long r = 0, g = 0, b = 0, sum = 0;

    for(i = 0; i < clrs; ++i) {
      r += PPM_GETR(chv[indx + i].color) * chv[indx + i].value;
      g += PPM_GETG(chv[indx + i].color) * chv[indx + i].value;
      b += PPM_GETB(chv[indx + i].color) * chv[indx + i].value;
      sum += chv[indx + i].value;
    }
    r = r / sum;
    if(r > (long)maxval)
      r = maxval;       /* avoid math errors */
    g = g / sum;
    if(g > (long)maxval)
      g = maxval;
    b = b / sum;
    if(b > (long)maxval)
      b = maxval;
    PPM_ASSIGN(colormap[bi].color, r, g, b);
#endif
  }

  /*
   * All done.
   */
  return colormap;
}


/* GIF compression routines */

#define BITS    12
#define HSIZE   5003    /* 80% occupancy */
#define TRUE    1
#define FALSE   0

typedef unsigned char char_type;
typedef int (*ifunptr) (int, int);

static int g_init_bits;
static FILE *g_outfile;
static int Width, Height;
static int curx, cury;
static long CountDown;
static int Pass = 0;
static int Interlace;

#include <ctype.h>

#define ARGVAL() (*++(*argv) || (--argc && *++argv))

static int n_bits;              /* number of bits/code */
static int maxbits = BITS;      /* user settable max # bits/code */
static code_int maxcode;        /* maximum code, given n_bits */
static code_int maxmaxcode = (code_int) 1 << BITS;
                                    /* should NEVER generate this code */

#define MAXCODE(n_bits) (((code_int) 1 << (n_bits)) - 1)

static count_int htab[HSIZE];
static unsigned short codetab[HSIZE];
#define HashTabOf(i)    htab[i]
#define CodeTabOf(i)    codetab[i]

static code_int hsize = HSIZE;  /* for dynamic table sizing */

/*
 * To save much memory, we overlay the table used by compress() with those
 * used by decompress().  The tab_prefix table is the same size and type
 * as the codetab.  The tab_suffix table needs 2**BITS characters.  We
 * get this from the beginning of htab.  The output stack uses the rest
 * of htab, and contains characters.  There is plenty of room for any
 * possible stack (stack used to be 8000 characters).
 */

#define tab_prefixof(i)  CodeTabOf(i)
#define tab_suffixof(i)  ((char_type*)(htab))[i]
#define de_stack         ((char_type*)&tab_suffixof((code_int)1<<BITS))

static code_int free_ent = 0;   /* first unused entry */

/*
 * block compression parameters -- after all codes are used up,
 * and compression rate changes, start over.
 */
static int clear_flg = 0;

static long int in_count = 1;   /* length of input */
static long int out_count = 0;  /* # of codes output (for debugging) */
static int ClearCode;
static int EOFCode;

/*
 * Number of characters so far in this 'packet'
 */
static int a_count;

/*
 * Set up the 'byte output' routine
 */
static void char_init()
{
  a_count = 0;
}

/*
 * Define the storage for the packet accumulator
 */
static char accum[256];


/*
 * Flush the packet to disk, and reset the accumulator
 */
static void flush_char()
{
  if(a_count > 0) {
    fputc(a_count, g_outfile);
    fwrite(accum, 1, a_count, g_outfile);
    a_count = 0;
  }
}

/*
 * Add a character to the end of the current packet, and if it is 254
 * characters, flush the packet to disk.
 */
static void char_out(int c)
{
  accum[a_count++] = c;
  if(a_count >= 254)
    flush_char();
}

/*
 * Bump the 'curx' and 'cury' to point to the next pixel
 */

static void BumpPixel()
{
  /*
   * Bump the current X position
   */
  ++curx;

  /*
   * If we are at the end of a scan line, set curx back to the beginning
   * If we are interlaced, bump the cury to the appropriate spot,
   * otherwise, just increment it.
   */
  if(curx == Width) {
    curx = 0;

    if(!Interlace)
      ++cury;
    else {
      switch (Pass) {

      case 0:
        cury += 8;
        if(cury >= Height) {
          ++Pass;
          cury = 4;
        }
        break;

      case 1:
        cury += 8;
        if(cury >= Height) {
          ++Pass;
          cury = 2;
        }
        break;

      case 2:
        cury += 4;
        if(cury >= Height) {
          ++Pass;
          cury = 1;
        }
        break;

      case 3:
        cury += 2;
        break;
      }
    }
  }
}


/*
 * Return the next pixel from the image
 */
static int GIFNextPixel(ifunptr getpixel)
{
  int r;

  if(CountDown == 0)
    return EOF;

  --CountDown;

  r = (*getpixel) (curx, cury);

  BumpPixel();

  return r;
}


/*
 * Output the given code.
 * Inputs:
 *      code:   A n_bits-bit integer.  If == -1, then EOF.  This assumes
 *              that n_bits =< (long)wordsize - 1.
 * Outputs:
 *      Outputs code to the file.
 * Assumptions:
 *      Chars are 8 bits long.
 * Algorithm:
 *      Maintain a BITS character long buffer (so that 8 codes will
 * fit in it exactly).  Use the VAX insv instruction to insert each
 * code in turn.  When the buffer fills up empty it and start over.
 */

static unsigned long cur_accum = 0;
static int cur_bits = 0;

static unsigned long masks[] = { 0x0000, 0x0001, 0x0003, 0x0007, 0x000F,
  0x001F, 0x003F, 0x007F, 0x00FF,
  0x01FF, 0x03FF, 0x07FF, 0x0FFF,
  0x1FFF, 0x3FFF, 0x7FFF, 0xFFFF
};

static void output(code_int code)
{
  cur_accum &= masks[cur_bits];

  if(cur_bits > 0)
    cur_accum |= ((long)code << cur_bits);
  else
    cur_accum = code;

  cur_bits += n_bits;

  while(cur_bits >= 8) {
    char_out((unsigned int)(cur_accum & 0xff));
    cur_accum >>= 8;
    cur_bits -= 8;
  }

  /*
   * If the next entry is going to be too big for the code size,
   * then increase it, if possible.
   */
  if(free_ent > maxcode || clear_flg) {

    if(clear_flg) {
      maxcode = MAXCODE(n_bits = g_init_bits);
      clear_flg = 0;
    }
    else {
      ++n_bits;
      if(n_bits == maxbits)
        maxcode = maxmaxcode;
      else
        maxcode = MAXCODE(n_bits);
    }
  }

  if(code == EOFCode) {
    /*
     * At EOF, write the rest of the buffer.
     */
    while(cur_bits > 0) {
      char_out((unsigned int)(cur_accum & 0xff));
      cur_accum >>= 8;
      cur_bits -= 8;
    }

    flush_char();

    fflush(g_outfile);

    if(ferror(g_outfile))
      Msg(GERROR, "GIF: Error writing output file");
  }
}


/*
 * compress 
 *
 * Algorithm:  use open addressing double hashing (no chaining) on the
 * prefix code / next character combination.  We do a variant of Knuth's
 * algorithm D (vol. 3, sec. 6.4) along with G. Knott's relatively-prime
 * secondary probe.  Here, the modular division first probe is gives way
 * to a faster exclusive-or manipulation.  Also do block compression with
 * an adaptive reset, whereby the code table is cleared when the compression
 * ratio decreases, but after the table fills.  The variable-length output
 * codes are re-sized at this point, and a special CLEAR code is generated
 * for the decompressor.  Late addition:  construct the table according to
 * file size for noticeable speed improvement on small files.  Please direct
 * questions about this implementation to ames!jaw.
 */

static void cl_hash(register count_int hsize)
{       /* reset code table */
  register count_int *htab_p = htab + hsize;

  register long i;
  register long m1 = -1;

  i = hsize - 16;
  do {  /* might use Sys V memset(3) here */
    *(htab_p - 16) = m1;
    *(htab_p - 15) = m1;
    *(htab_p - 14) = m1;
    *(htab_p - 13) = m1;
    *(htab_p - 12) = m1;
    *(htab_p - 11) = m1;
    *(htab_p - 10) = m1;
    *(htab_p - 9) = m1;
    *(htab_p - 8) = m1;
    *(htab_p - 7) = m1;
    *(htab_p - 6) = m1;
    *(htab_p - 5) = m1;
    *(htab_p - 4) = m1;
    *(htab_p - 3) = m1;
    *(htab_p - 2) = m1;
    *(htab_p - 1) = m1;
    htab_p -= 16;
  } while((i -= 16) >= 0);

  for(i += 16; i > 0; --i)
    *--htab_p = m1;
}


/*
 * Clear out the hash table
 */
static void cl_block()
{       /* table clear for block compress */

  cl_hash((count_int) hsize);
  free_ent = ClearCode + 2;
  clear_flg = 1;

  output((code_int) ClearCode);
}

static void compress(int init_bits, FILE * outfile, ifunptr ReadValue)
{
  register long fcode;
  register code_int i /* = 0 */ ;
  register int c;
  register code_int ent;
  register code_int disp;
  register code_int hsize_reg;
  register int hshift;

  /*
   * Set up the globals:  g_init_bits - initial number of bits
   *                      g_outfile   - pointer to output file
   */
  g_init_bits = init_bits;
  g_outfile = outfile;

  /*
   * Set up the necessary values
   */
  out_count = 0;
  clear_flg = 0;
  in_count = 1;
  maxcode = MAXCODE(n_bits = g_init_bits);

  ClearCode = (1 << (init_bits - 1));
  EOFCode = ClearCode + 1;
  free_ent = ClearCode + 2;

  char_init();

  ent = GIFNextPixel(ReadValue);

  hshift = 0;
  for(fcode = (long)hsize; fcode < 65536L; fcode *= 2L)
    ++hshift;
  hshift = 8 - hshift;  /* set hash code range bound */

  hsize_reg = hsize;
  cl_hash((count_int) hsize_reg);       /* clear hash table */

  output((code_int) ClearCode);

  while((c = GIFNextPixel(ReadValue)) != EOF) {

    ++in_count;

    fcode = (long)(((long)c << maxbits) + ent);
    i = (((code_int) c << hshift) ^ ent);       /* xor hashing */

    if(HashTabOf(i) == fcode) {
      ent = CodeTabOf(i);
      continue;
    }
    else if((long)HashTabOf(i) < 0)     /* empty slot */
      goto nomatch;
    disp = hsize_reg - i;       /* secondary hash (after G. Knott) */
    if(i == 0)
      disp = 1;
  probe:
    if((i -= disp) < 0)
      i += hsize_reg;

    if(HashTabOf(i) == fcode) {
      ent = CodeTabOf(i);
      continue;
    }
    if((long)HashTabOf(i) > 0)
      goto probe;
  nomatch:
    output((code_int) ent);
    ++out_count;
    ent = c;
    if(free_ent < maxmaxcode) {
      CodeTabOf(i) = free_ent++;        /* code -> hashtable */
      HashTabOf(i) = fcode;
    }
    else
      cl_block();
  }
  /*
   * Put out the final code.
   */
  output((code_int) ent);
  ++out_count;
  output((code_int) EOFCode);
}


/*
 * Write out a word to the GIF file
 */
static void Putword(int w, FILE * fp)
{
  fputc(w & 0xff, fp);
  fputc((w / 256) & 0xff, fp);
}


static void GIFEncode(FILE * fp,
                      int GWidth, int GHeight,
                      int GInterlace, int Background, int Transparent,
                      int BitsPerPixel, int Red[], int Green[], int Blue[],
                      ifunptr GetPixel)
{
  int B;
  int RWidth, RHeight;
  int LeftOfs, TopOfs;
  int Resolution;
  int ColorMapSize;
  int InitCodeSize;
  int i;

  /* reset stuff for output */
  cur_accum = 0;
  cur_bits = 0;
  free_ent = 0;

  Interlace = GInterlace;

  ColorMapSize = 1 << BitsPerPixel;

  RWidth = Width = GWidth;
  RHeight = Height = GHeight;
  LeftOfs = TopOfs = 0;

  Resolution = BitsPerPixel;

  /*
   * Calculate number of bits we are expecting
   */
  CountDown = (long)Width *(long)Height;

  /*
   * Indicate which pass we are on (if interlace)
   */
  Pass = 0;

  /*
   * The initial code size
   */
  if(BitsPerPixel <= 1)
    InitCodeSize = 2;
  else
    InitCodeSize = BitsPerPixel;

  /*
   * Set up the current x and y position
   */
  curx = cury = 0;

  /*
   * Write the Magic header
   */
  fwrite(Transparent < 0 ? "GIF87a" : "GIF89a", 1, 6, fp);

  /*
   * Write out the screen width and height
   */
  Putword(RWidth, fp);
  Putword(RHeight, fp);

  /*
   * Indicate that there is a global colour map
   */
  B = 0x80;     /* Yes, there is a color map */

  /*
   * OR in the resolution
   */
  B |= (Resolution - 1) << 5;

  /*
   * OR in the Bits per Pixel
   */
  B |= (BitsPerPixel - 1);

  /*
   * Write it out
   */
  fputc(B, fp);

  /*
   * Write out the Background colour
   */
  fputc(Background, fp);

  /*
   * Byte of 0's (future expansion)
   */
  fputc(0, fp);

  /*
   * Write out the Global Colour Map
   */
  for(i = 0; i < ColorMapSize; ++i) {
    fputc(Red[i], fp);
    fputc(Green[i], fp);
    fputc(Blue[i], fp);
  }

  /*
   * Write out extension for transparent colour index, if necessary.
   */
  if(Transparent >= 0) {
    fputc('!', fp);
    fputc(0xf9, fp);
    fputc(4, fp);
    fputc(1, fp);
    fputc(0, fp);
    fputc(0, fp);
    fputc(Transparent, fp);
    fputc(0, fp);
  }

  /*
   * Write an Image separator
   */
  fputc(',', fp);

  /*
   * Write the Image header
   */

  Putword(LeftOfs, fp);
  Putword(TopOfs, fp);
  Putword(Width, fp);
  Putword(Height, fp);

  /*
   * Write out whether or not the image is interlaced
   */
  if(Interlace)
    fputc(0x40, fp);
  else
    fputc(0x00, fp);

  /*
   * Write out the initial code size
   */
  fputc(InitCodeSize, fp);

  /*
   * Go and actually compress the data
   */
  compress(InitCodeSize + 1, fp, GetPixel);

  /*
   * Write out a Zero-length packet (to end the series)
   */
  fputc(0, fp);

  /*
   * Write the GIF file terminator
   */
  fputc(';', fp);

}


/* gl2gif public routine */

#define FS_SCALE   1024
#define MAXCOL2    32767

void create_gif(FILE * outfile, PixelBuffer *buffer,
                int dither, int sort, int interlace,
                int transparency, int bg_r, int bg_g, int bg_b)
{

  int i, j, k, transparent, rows, cols;
  pixel transcolor;
  colorhist_vector chv, colormap;
  int BitsPerPixel, usehash;
  pixval maxval = MAXCOL2, newmaxval;
  colorhash_table cht;
  register pixel *pP;
  register int col, row, limitcol, ind;
  int newcolors = 256;
  long *thisrerr = NULL, *nextrerr = NULL, *thisgerr = NULL, *nextgerr = NULL;
  long *thisberr = NULL, *nextberr = NULL, *temperr = NULL;
  register long sr = 0, sg = 0, sb = 0, err = 0;
  int fs_direction = 0;

  int width = buffer->GetWidth();
  int height = buffer->GetHeight();
  int numcomp = buffer->GetNumComp();

  if(numcomp != 3){
    Msg(GERROR, "GIF only implemented for GL_RGB");
    return;
  }

  static_pixels = (pixel **) Malloc(height * sizeof(pixel *));
  for(i = 0; i < height; i++)
    static_pixels[i] = (pixel *) Malloc(3 * width * sizeof(pixel));

  unsigned char *pixels = (unsigned char*)buffer->GetPixels();
  for(i = 0; i < height; i++)
    for(j = 0; j < width; j++)
      PPM_ASSIGN(static_pixels[height - 1 - i][j],
                 pixels[i * width * 3 + j * 3],
                 pixels[i * width * 3 + j * 3 + 1],
                 pixels[i * width * 3 + j * 3 + 2]);

  /* Try to compute color histogram */

  chv = ppm_computecolorhist(static_pixels, width, height, MAX_GIFCOLORS,
                             &static_nbcolors);


  /* Fuck, there are more than 256 colors in the picture: we need to quantize */

  if(chv == (colorhist_vector) 0) {

    Msg(DEBUG, "GIF: too many colors in image");

    rows = height;
    cols = width;

    while(1) {
      Msg(DEBUG, "GIF: making histogram...");
      chv = ppm_computecolorhist(static_pixels, width, height, MAXCOL2,
                                 &static_nbcolors);
      if(chv != (colorhist_vector) 0)
        break;
      Msg(DEBUG, "GIF: still too many colors!");
      newmaxval = maxval / 2;
      Msg(DEBUG,
          "GIF: scaling colors from maxval=%d to maxval=%d to improve clustering...",
          maxval, newmaxval);
      for(row = 0; row < rows; ++row)
        for(col = 0, pP = static_pixels[row]; col < cols; ++col, ++pP)
          PPM_DEPTH(*pP, *pP, maxval, newmaxval);
      maxval = newmaxval;
    }
    Msg(DEBUG, "GIF: %d colors found", static_nbcolors);
    Msg(DEBUG, "GIF: choosing %d colors...", newcolors);
    colormap =
      mediancut(chv, static_nbcolors, rows * cols, maxval, newcolors);

    cht = ppm_alloccolorhash();

    ppm_freecolorhist(chv);

    /* map the colors in the image to their closest match in the new colormap */
    Msg(DEBUG, "GIF: mapping image to new colors...");
    usehash = 1;

    if(dither) {
      Msg(DEBUG, "GIF: Floyd-Steinberg dithering is selected...");
      /* Initialize Floyd-Steinberg error vectors. */
      thisrerr = (long *)Malloc((cols + 2) * sizeof(long));
      nextrerr = (long *)Malloc((cols + 2) * sizeof(long));
      thisgerr = (long *)Malloc((cols + 2) * sizeof(long));
      nextgerr = (long *)Malloc((cols + 2) * sizeof(long));
      thisberr = (long *)Malloc((cols + 2) * sizeof(long));
      nextberr = (long *)Malloc((cols + 2) * sizeof(long));
      /* srand( (int) ( time( 0 ) ^ getpid( ) ) ); */
      for(col = 0; col < cols + 2; ++col) {
        thisrerr[col] = rand() % (FS_SCALE * 2) - FS_SCALE;
        thisgerr[col] = rand() % (FS_SCALE * 2) - FS_SCALE;
        thisberr[col] = rand() % (FS_SCALE * 2) - FS_SCALE;
        /* (random errors in [-1 .. 1]) */
      }
      fs_direction = 1;
    }
    for(row = 0; row < rows; ++row) {

      if(dither)
        for(col = 0; col < cols + 2; ++col)
          nextrerr[col] = nextgerr[col] = nextberr[col] = 0;

      if((!dither) || fs_direction) {
        col = 0;
        limitcol = cols;
        pP = static_pixels[row];
      }
      else {
        col = cols - 1;
        limitcol = -1;
        pP = &(static_pixels[row][col]);
      }

      do {

        if(dither) {
          /* Use Floyd-Steinberg errors to adjust actual color. */
          sr = PPM_GETR(*pP) + thisrerr[col + 1] / FS_SCALE;
          sg = PPM_GETG(*pP) + thisgerr[col + 1] / FS_SCALE;
          sb = PPM_GETB(*pP) + thisberr[col + 1] / FS_SCALE;
          if(sr < 0)
            sr = 0;
          else if(sr > (long)maxval)
            sr = maxval;
          if(sg < 0)
            sg = 0;
          else if(sg > (long)maxval)
            sg = maxval;
          if(sb < 0)
            sb = 0;
          else if(sb > (long)maxval)
            sb = maxval;
          PPM_ASSIGN(*pP, sr, sg, sb);
        }

        /* Check hash table to see if we have already matched this color. */
        ind = ppm_lookupcolor(cht, pP);
        if(ind == -1) { /* No; search colormap for closest match. */
          register int i, r1, g1, b1, r2, g2, b2;
          register long dist, newdist;
          r1 = PPM_GETR(*pP);
          g1 = PPM_GETG(*pP);
          b1 = PPM_GETB(*pP);
          dist = 2000000000;
          for(i = 0; i < newcolors; ++i) {
            r2 = PPM_GETR(colormap[i].color);
            g2 = PPM_GETG(colormap[i].color);
            b2 = PPM_GETB(colormap[i].color);
            newdist =
              (r1 - r2) * (r1 - r2) +
              (g1 - g2) * (g1 - g2) + (b1 - b2) * (b1 - b2);
            if(newdist < dist) {
              ind = i;
              dist = newdist;
            }
          }
          if(usehash) {
            if(ppm_addtocolorhash(cht, pP, ind) < 0) {
              Msg(WARNING,
                  "GIF: Out of memory adding to hash table, proceeding without it");
              usehash = 0;
            }
          }
        }

        if(dither) {
          /* Propagate Floyd-Steinberg error terms. */
          if(fs_direction) {
            err = (sr - (long)PPM_GETR(colormap[ind].color)) * FS_SCALE;
            thisrerr[col + 2] += (err * 7) / 16;
            nextrerr[col] += (err * 3) / 16;
            nextrerr[col + 1] += (err * 5) / 16;
            nextrerr[col + 2] += (err) / 16;
            err = (sg - (long)PPM_GETG(colormap[ind].color)) * FS_SCALE;
            thisgerr[col + 2] += (err * 7) / 16;
            nextgerr[col] += (err * 3) / 16;
            nextgerr[col + 1] += (err * 5) / 16;
            nextgerr[col + 2] += (err) / 16;
            err = (sb - (long)PPM_GETB(colormap[ind].color)) * FS_SCALE;
            thisberr[col + 2] += (err * 7) / 16;
            nextberr[col] += (err * 3) / 16;
            nextberr[col + 1] += (err * 5) / 16;
            nextberr[col + 2] += (err) / 16;
          }
          else {
            err = (sr - (long)PPM_GETR(colormap[ind].color)) * FS_SCALE;
            thisrerr[col] += (err * 7) / 16;
            nextrerr[col + 2] += (err * 3) / 16;
            nextrerr[col + 1] += (err * 5) / 16;
            nextrerr[col] += (err) / 16;
            err = (sg - (long)PPM_GETG(colormap[ind].color)) * FS_SCALE;
            thisgerr[col] += (err * 7) / 16;
            nextgerr[col + 2] += (err * 3) / 16;
            nextgerr[col + 1] += (err * 5) / 16;
            nextgerr[col] += (err) / 16;
            err = (sb - (long)PPM_GETB(colormap[ind].color)) * FS_SCALE;
            thisberr[col] += (err * 7) / 16;
            nextberr[col + 2] += (err * 3) / 16;
            nextberr[col + 1] += (err * 5) / 16;
            nextberr[col] += (err) / 16;
          }
        }

        *pP = colormap[ind].color;

        if((!dither) || fs_direction) {
          ++col;
          ++pP;
        }
        else {
          --col;
          --pP;
        }
      }
      while(col != limitcol);

      if(dither) {
        temperr = thisrerr;
        thisrerr = nextrerr;
        nextrerr = temperr;
        temperr = thisgerr;
        thisgerr = nextgerr;
        nextgerr = temperr;
        temperr = thisberr;
        thisberr = nextberr;
        nextberr = temperr;
        fs_direction = !fs_direction;
      }

    }

    if(cht)
      ppm_freecolorhash(cht);
    if(dither) {
      Free(thisrerr);
      Free(nextrerr);
      Free(thisgerr);
      Free(nextgerr);
      Free(thisberr);
      Free(nextberr);
    }
    chv = ppm_computecolorhist(static_pixels, width, height, MAX_GIFCOLORS,
                               &static_nbcolors);

  }

  /* We now have a colormap of maximum 256 colors */

  for(i = 0; i < static_nbcolors; ++i) {
    static_red[i] = PPM_GETR(chv[i].color);
    static_green[i] = PPM_GETG(chv[i].color);
    static_blue[i] = PPM_GETB(chv[i].color);
  }

  /* Sort the colormap */
  for(i = 0; i < static_nbcolors; i++)
    static_permi[i] = i;
  if(sort) {
    Msg(DEBUG, "GIF: sorting colormap");
    for(i = 0; i < static_nbcolors; i++)
      for(j = i + 1; j < static_nbcolors; j++)
        if(((static_red[i] * MAX_GIFCOLORS) +
            static_green[i]) * MAX_GIFCOLORS + static_blue[i] >
           ((static_red[j] * MAX_GIFCOLORS) +
            static_green[j]) * MAX_GIFCOLORS + static_blue[j]) {
          k = static_permi[i];
          static_permi[i] = static_permi[j];
          static_permi[j] = k;
          k = static_red[i];
          static_red[i] = static_red[j];
          static_red[j] = k;
          k = static_green[i];
          static_green[i] = static_green[j];
          static_green[j] = k;
          k = static_blue[i];
          static_blue[i] = static_blue[j];
          static_blue[j] = k;
        }
  }
  for(i = 0; i < static_nbcolors; i++)
    static_perm[static_permi[i]] = i;

  BitsPerPixel = colorstobpp(static_nbcolors);

  /* And make a hash table for fast lookup. */
  static_cht = ppm_colorhisttocolorhash(chv, static_nbcolors);
  ppm_freecolorhist(chv);

  /* figure out the transparent colour index */
  if(transparency) {
    PPM_ASSIGN(transcolor, bg_r, bg_g, bg_b);
    transparent = ppm_lookupcolor(static_cht, &transcolor);
    if(transparent == -1)
      transparent = closestcolor(transcolor);
    else
      transparent = static_perm[transparent];
  }
  else
    transparent = -1;

  /* All set, let's do it. */
  GIFEncode(outfile, width, height, interlace, 0, transparent, BitsPerPixel,
            static_red, static_green, static_blue, GetPixel);

  for(i = 0; i < height; i++)
    Free(static_pixels[i]);
  Free(static_pixels);

}
