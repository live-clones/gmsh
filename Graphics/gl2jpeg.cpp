// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshConfig.h"
#include "gl2jpeg.h"
#undef EXTERN

#if !defined(HAVE_LIBJPEG)

void create_jpeg(FILE *outfile, PixelBuffer *buffer, int quality, int smoothing)
{
  Msg::Error("This version of Gmsh was compiled without JPEG support");
}

#else

extern "C"
{
#include <jpeglib.h>
#include <jerror.h>
}

static void my_output_message(j_common_ptr cinfo)
{
  char buffer[JMSG_LENGTH_MAX];

  (*cinfo->err->format_message) (cinfo, buffer);

  Msg::Debug("%s", buffer);
}

void create_jpeg(FILE *outfile, PixelBuffer *buffer, int quality, int smoothing)
{
  if(buffer->getFormat() != GL_RGB || buffer->getType() != GL_UNSIGNED_BYTE){
    Msg::Error("JPEG only implemented for GL_RGB and GL_UNSIGNED_BYTE");
    return;
  }

  struct jpeg_compress_struct cinfo;
  struct jpeg_error_mgr jerr;
  cinfo.err = jpeg_std_error(&jerr);
  cinfo.err->output_message = my_output_message;

  jpeg_create_compress(&cinfo);
  jpeg_stdio_dest(&cinfo, outfile);
  cinfo.image_width = buffer->getWidth();
  cinfo.image_height = buffer->getHeight();
  cinfo.input_components = 3;
  cinfo.in_color_space = JCS_RGB;
  jpeg_set_defaults(&cinfo);
  jpeg_set_quality(&cinfo, quality, TRUE);
  cinfo.optimize_coding = TRUE;
  cinfo.smoothing_factor = smoothing;
  jpeg_start_compress(&cinfo, TRUE);

  unsigned char *pixels = (unsigned char*)buffer->getPixels();
  JSAMPROW row_pointer[1]; 
  int row_stride = cinfo.image_width * cinfo.input_components;
  int i = cinfo.image_height - 1;
  while(i >= 0) {
    row_pointer[0] = &pixels[i * row_stride];
    (void)jpeg_write_scanlines(&cinfo, row_pointer, 1);
    i--;
  }
  jpeg_finish_compress(&cinfo);
  jpeg_destroy_compress(&cinfo);
}

#endif
