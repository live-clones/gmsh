/*
 * GL2JPEG, an OpenGL to JPEG Printing Library
 * Copyright (C) 1999-2002  Christophe Geuzaine 
 *
 * $Id: gl2jpeg.cpp,v 1.9 2002-05-18 07:56:48 geuzaine Exp $
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.
 *
 */

#include "Gmsh.h"
#include "GmshUI.h"

#include "jpeglib.h"
#include "jerror.h"

void my_output_message (j_common_ptr cinfo){
  char buffer[JMSG_LENGTH_MAX];

  (*cinfo->err->format_message) (cinfo, buffer);

  Msg(DEBUG, "%s", buffer);
}

void create_jpeg(FILE *outfile, int width, int height, int quality){
  int i;
  unsigned char *pixels;
  struct jpeg_compress_struct cinfo;
  struct jpeg_error_mgr jerr;
  JSAMPROW row_pointer[1];      // pointer to JSAMPLE row[s]
  int row_stride;               // physical row width in image buffer
            
  cinfo.err = jpeg_std_error(&jerr);
  cinfo.err->output_message = my_output_message;

  jpeg_create_compress(&cinfo);
  jpeg_stdio_dest(&cinfo, outfile);
  cinfo.image_width = width;       // image width and height, in pixels
  cinfo.image_height = height;
  cinfo.input_components = 3;      // # of color components per pixel
  cinfo.in_color_space = JCS_RGB;  // colorspace of input image
  jpeg_set_defaults(&cinfo);                            
  jpeg_set_quality(&cinfo, quality, TRUE);
  jpeg_start_compress(&cinfo, TRUE);

  glPixelStorei(GL_PACK_ALIGNMENT,1);
  glPixelStorei(GL_UNPACK_ALIGNMENT,1);
  pixels=(unsigned char *)Malloc(height*width*3);
  glReadPixels(0,0,width,height,GL_RGB,GL_UNSIGNED_BYTE,pixels);

  row_stride = width * 3;
  i=cinfo.image_height-1;
  while (i >= 0) {
    /* 
       jpeg_write_scanlines expects an array of pointers to scanlines.
       Here the array is only one element long, but you could pass
       more than one scanline at a time if that's more convenient.
     */
    row_pointer[0] = &pixels[i * row_stride];
    (void) jpeg_write_scanlines(&cinfo, row_pointer, 1);
    i--;
  }
  jpeg_finish_compress(&cinfo);
  jpeg_destroy_compress(&cinfo);                                 

  Free(pixels);
}

