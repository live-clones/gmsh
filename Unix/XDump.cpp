
/* This is a modified version for Gmsh (mainly for c++ compliance) */

/* Dump the image in an X xindow to a .xwd file.
 * This code was extracted by Brian Paul from the xwd program which is
 * included with X11.  The OMIT preprocessor identifier denotes regions
 * of code I've had to omit.
 */

/* from xwd.c: */

/* $XConsortium: xwd.c,v 1.56 91/07/25 18:00:15 rws Exp $ */

/* Copyright 1987 Massachusetts Institute of Technology */

/*
 * xwd.c MIT Project Athena, X Window system window raster image dumper.
 *
 * This program will dump a raster image of the contents of a window into a 
 * file for output on graphics printers or for other uses.
 *
 *  Author:        Tony Della Fera, DEC
 *                17-Jun-85
 * 
 *  Modification history:
 *
 *  11/14/86 Bill Wyatt, Smithsonian Astrophysical Observatory
 *    - Removed Z format option, changing it to an XY option. Monochrome 
 *      windows will always dump in XY format. Color windows will dump
 *      in Z format by default, but can be dumped in XY format with the
 *      -xy option.
 *
 *  11/18/86 Bill Wyatt
 *    - VERSION 6 is same as version 5 for monchrome. For colors, the 
 *      appropriate number of Color structs are dumped after the header,
 *      which has the number of colors (=0 for monochrome) in place of the
 *      V5 padding at the end. Up to 16-bit displays are supported. I
 *      don't yet know how 24- to 32-bit displays will be handled under
 *      the Version 11 protocol.
 *
 *  6/15/87 David Krikorian, MIT Project Athena
 *    - VERSION 7 runs under the X Version 11 servers, while the previous
 *      versions of xwd were are for X Version 10.  This version is based
 *      on xwd version 6, and should eventually have the same color
 *      abilities. (Xwd V7 has yet to be tested on a color machine, so
 *      all color-related code is commented out until color support
 *      becomes practical.)
 */


/*
 * The following XCOLOR struct is to be used in place of X's XColor
 * struct because on 32-bit systems, sizeof(XColor)=12 while on 64-bit
 * systems, sizeof(XColor)=16.  We MUST have an XColor struct of size
 * 12 so a correct file is written.  BEP July-21-95
 */
typedef struct {
        unsigned int /*long*/ pixel;
        unsigned short red, green, blue;
        char flags;  /* do_red, do_green, do_blue */
        char pad;
} XCOLOR;


#include <assert.h>
#include <X11/Xlib.h>
#include <X11/Xmd.h>
#include <X11/Xutil.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <X11/XWDFile.h>

static Bool debug = False;
static Bool nobdrs = False;
static Bool on_root = False;
static Bool use_installed = False;
static long add_pixel_value = 0;
static int format = ZPixmap;

static Display *dpy;
static char *program_name = "xdump";
static int screen;

typedef unsigned long Pixel;



/*
 * outl: a debugging routine.  Flushes stdout then prints a message on stderr
 *       and flushes stderr.  Used to print messages when past certain points
 *       in code so we can tell where we are.  Outl may be invoked like
 *       printf with up to 7 arguments.
 */
/* VARARGS1 */
static void outl( char *msg )
{
        fflush(stdout);
        fprintf(stderr, "%s\n", msg );
        fflush(stderr);
}


/*
 * Standard fatal error routine - call like printf but maximum of 7 arguments.
 * Does not require dpy or screen defined.
 */
/* VARARGS1 */
static void Fatal_Error( char *msg )
{
        fflush(stdout);
        fflush(stderr);
        fprintf(stderr, "%s: error: %s\n", program_name, msg);
        exit(1);
}


/*
 * Determine the pixmap size.
 */

static int Image_Size( XImage *image )
{
    if (image->format != ZPixmap)
      return(image->bytes_per_line * image->height * image->depth);

    return(image->bytes_per_line * image->height);
}



#define lowbit(x) ((x) & (~(x) + 1))

/*
 * Get the XColors of all pixels in image - returns # of colors
 */
static int Get_XColors( XWindowAttributes *win_info, XColor **colors )
{
    int i, ncolors;
    Colormap cmap = win_info->colormap;

    if (use_installed)
        /* assume the visual will be OK ... */
        cmap = XListInstalledColormaps(dpy, win_info->root, &i)[0];
    if (!cmap)
        return(0);

    ncolors = win_info->visual->map_entries;
    if (!(*colors = (XColor *) malloc (sizeof(XColor) * ncolors)))
      Fatal_Error("Out of memory!");

#if defined(__cplusplus) || defined(c_plusplus)
    if (win_info->visual->c_class == DirectColor ||
        win_info->visual->c_class == TrueColor) {
#else
    if (win_info->visual->class == DirectColor ||
        win_info->visual->class == TrueColor) {
#endif

        Pixel red, green, blue, red1, green1, blue1;

        red = green = blue = 0;
        red1 = lowbit(win_info->visual->red_mask);
        green1 = lowbit(win_info->visual->green_mask);
        blue1 = lowbit(win_info->visual->blue_mask);
        for (i=0; i<ncolors; i++) {
          (*colors)[i].pixel = red|green|blue;
          (*colors)[i].pad = 0;
          red += red1;
          if (red > win_info->visual->red_mask)
            red = 0;
          green += green1;
          if (green > win_info->visual->green_mask)
            green = 0;
          blue += blue1;
          if (blue > win_info->visual->blue_mask)
            blue = 0;
        }
    } else {
        for (i=0; i<ncolors; i++) {
          (*colors)[i].pixel = i;
          (*colors)[i].pad = 0;
        }
    }

    XQueryColors(dpy, cmap, *colors, ncolors);
    
    return(ncolors);
}



static void _swapshort( char *bp, unsigned n )
{
    register char c;
    register char *ep = bp + n;

    while (bp < ep) {
        c = *bp;
        *bp = *(bp + 1);
        bp++;
        *bp++ = c;
    }
}

static void _swaplong ( char *bp, unsigned n )
{
    register char c;
    register char *ep = bp + n;
    register char *sp;

    while (bp < ep) {
        sp = bp + 3;
        c = *sp;
        *sp = *bp;
        *bp++ = c;
        sp = bp + 1;
        c = *sp;
        *sp = *bp;
        *bp++ = c;
        bp += 2;
    }
}






/*
 * Window_Dump: dump a window to a file which must already be open for
 *              writting.
 */


void Window_Dump(Display *display, int scr, Window window, FILE *out){
    unsigned long swaptest = 1;
    XColor *colors;
    unsigned buffer_size;
    int win_name_size;
    int header_size;
    int ncolors, i;
    char *win_name;
    Bool got_win_name;
    XWindowAttributes win_info;
    XImage *image;
    int absx, absy, x, y;
    int width, height; /* unsigned */
    int dwidth, dheight;
    int bw;
    Window dummywin;
    XWDFileHeader header;

    dpy = display;
    screen = scr;

    /*
     * Inform the user not to alter the screen.
     */
#ifdef OMIT
    Beep();
#endif

    /*
     * Get the parameters of the window being dumped.
     */
    if (debug) outl("xwd: Getting target window information.\n");
    if(!XGetWindowAttributes(dpy, window, &win_info)) 
      Fatal_Error("Can't get target window attributes.");

    /* handle any frame window */
    if (!XTranslateCoordinates (dpy, window, RootWindow (dpy, screen), 0, 0,
                                &absx, &absy, &dummywin)) {
        fprintf (stderr, 
                 "%s:  unable to translate window coordinates (%d,%d)\n",
                 program_name, absx, absy);
        exit (1);
    }
    win_info.x = absx;
    win_info.y = absy;
    width = win_info.width;
    height = win_info.height;
    bw = 0;

    if (!nobdrs) {
        absx -= win_info.border_width;
        absy -= win_info.border_width;
        bw = win_info.border_width;
        width += (2 * bw);
        height += (2 * bw);
    }
    dwidth = DisplayWidth (dpy, screen);
    dheight = DisplayHeight (dpy, screen);


    /* clip to window */
    if (absx < 0) width += absx, absx = 0;
    if (absy < 0) height += absy, absy = 0;
    if (absx + width > dwidth) width = dwidth - absx;
    if (absy + height > dheight) height = dheight - absy;

    XFetchName(dpy, window, &win_name);
    if (!win_name || !win_name[0]) {
        win_name = "xwdump";
        got_win_name = False;
    } else {
        got_win_name = True;
    }

    /* sizeof(char) is included for the null string terminator. */
    win_name_size = strlen(win_name) + sizeof(char);

    /*
     * Snarf the pixmap with XGetImage.
     */

    x = absx - win_info.x;
    y = absy - win_info.y;
    if (on_root)
        image = XGetImage (dpy, RootWindow(dpy, screen), absx, absy, width, height, AllPlanes, format);
    else
        image = XGetImage (dpy, window, x, y, width, height, AllPlanes, format);
    if (!image) {
        fprintf (stderr, "%s:  unable to get image at %dx%d+%d+%d\n",
                 program_name, width, height, x, y);
        exit (1);
    }

    if (add_pixel_value != 0) XAddPixel (image, add_pixel_value);

    /*
     * Determine the pixmap size.
     */
    buffer_size = Image_Size(image);

    if (debug) outl("xwd: Getting Colors.\n");

    ncolors = Get_XColors(&win_info, &colors);

    /*
     * Inform the user that the image has been retrieved.
     */
#ifdef OMIT
    XBell(dpy, FEEP_VOLUME);
    XBell(dpy, FEEP_VOLUME);
#endif
    XFlush(dpy);

    /*
     * Calculate header size.
     */
    if (debug) outl("xwd: Calculating header size.\n");
    header_size = sizeof(header) + win_name_size;

    /*
     * Write out header information.
     */
    if (debug) outl("xwd: Constructing and dumping file header.\n");
    header.header_size = (CARD32) header_size;
    header.file_version = (CARD32) XWD_FILE_VERSION;
    header.pixmap_format = (CARD32) format;
    header.pixmap_depth = (CARD32) image->depth;
    header.pixmap_width = (CARD32) image->width;
    header.pixmap_height = (CARD32) image->height;
    header.xoffset = (CARD32) image->xoffset;
    header.byte_order = (CARD32) image->byte_order;
    header.bitmap_unit = (CARD32) image->bitmap_unit;
    header.bitmap_bit_order = (CARD32) image->bitmap_bit_order;
    header.bitmap_pad = (CARD32) image->bitmap_pad;
    header.bits_per_pixel = (CARD32) image->bits_per_pixel;
    header.bytes_per_line = (CARD32) image->bytes_per_line;
#if defined(__cplusplus) || defined(c_plusplus)
    header.visual_class = (CARD32) win_info.visual->c_class;
#else
    header.visual_class = (CARD32) win_info.visual->class;
#endif
    header.red_mask = (CARD32) win_info.visual->red_mask;
    header.green_mask = (CARD32) win_info.visual->green_mask;
    header.blue_mask = (CARD32) win_info.visual->blue_mask;
    header.bits_per_rgb = (CARD32) win_info.visual->bits_per_rgb;
    header.colormap_entries = (CARD32) win_info.visual->map_entries;
    header.ncolors = ncolors;
    header.window_width = (CARD32) win_info.width;
    header.window_height = (CARD32) win_info.height;
    header.window_x = absx;
    header.window_y = absy;
    header.window_bdrwidth = (CARD32) win_info.border_width;

    if (*(char *) &swaptest) {
        _swaplong((char *) &header, sizeof(header));
        for (i = 0; i < ncolors; i++) {
            _swaplong((char *) &colors[i].pixel, sizeof(long));
            _swapshort((char *) &colors[i].red, 3 * sizeof(short));
         }
    }

    (void) fwrite((char *)&header, sizeof(header), 1, out);
    (void) fwrite(win_name, win_name_size, 1, out);

    /*
     * Write out the color maps, if any
     */

    /*if (debug) outl("xwd: Dumping %d colors.\n", ncolors);*/
    for (i=0;i<ncolors;i++) {
       XCOLOR xc;
       assert( sizeof(xc)==12 );
       xc.pixel = colors[i].pixel;
       xc.red   = colors[i].red;
       xc.green = colors[i].green;
       xc.blue  = colors[i].blue;
       xc.flags = colors[i].flags;
       xc.pad   = colors[i].pad;
       (void) fwrite( (char *) &xc, sizeof(XCOLOR), 1, out );
    } 
/* OLD:
    (void) fwrite((char *) colors, sizeof(XColor), ncolors, out);
*/

    /*
     * Write out the buffer.
     */
    /*if (debug) outl("xwd: Dumping pixmap.  bufsize=%d\n",buffer_size);*/

    /*
     *    This copying of the bit stream (data) to a file is to be replaced
     *  by an Xlib call which hasn't been written yet.  It is not clear
     *  what other functions of xwd will be taken over by this (as yet)
     *  non-existant X function.
     */
    (void) fwrite(image->data, (int) buffer_size, 1, out);

    /*
     * free the color buffer.
     */

    if(debug && ncolors > 0) outl("xwd: Freeing colors.\n");
    if(ncolors > 0) free(colors);

    /*
     * Free window name string.
     */
    if (debug) outl("xwd: Freeing window name string.\n");
    if (got_win_name) XFree(win_name);

    /*
     * Free image
     */
    XDestroyImage(image);
}
