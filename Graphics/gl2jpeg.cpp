
#include "Gmsh.h"
#include "GmshUI.h"
#include "Context.h"

#include "jpeglib.h"
#include "jerror.h"

extern Context_T CTX ;

void my_output_message (j_common_ptr cinfo){
  char buffer[JMSG_LENGTH_MAX];

  /* Create the message */
  (*cinfo->err->format_message) (cinfo, buffer);

  Msg(DEBUG, "%s", buffer);
}

void create_jpeg(FILE *outfile, int width, int height){
  int i;
  unsigned char *pixels;
  struct jpeg_compress_struct cinfo;
  struct jpeg_error_mgr jerr;
  JSAMPROW row_pointer[1];      /* pointer to JSAMPLE row[s] */
  int row_stride;               /* physical row width in image buffer */
            
  cinfo.err = jpeg_std_error(&jerr);
  cinfo.err->output_message = my_output_message;

  jpeg_create_compress(&cinfo);
  jpeg_stdio_dest(&cinfo, outfile);
  cinfo.image_width = width;       /* image width and height, in pixels */
  cinfo.image_height = height;
  cinfo.input_components = 3;      /* # of color components per pixel */
  cinfo.in_color_space = JCS_RGB;  /* colorspace of input image */
  jpeg_set_defaults(&cinfo);                            
  jpeg_set_quality(&cinfo, CTX.print.jpeg_quality, TRUE /* limit to baseline-JPEG values */);
  jpeg_start_compress(&cinfo, TRUE);

  pixels=(unsigned char *)Malloc(height*width*3);
  glReadPixels(0,0,width,height,GL_RGB,GL_UNSIGNED_BYTE,pixels);

  row_stride = width * 3;
  i=cinfo.image_height-1;
  while (i >= 0) {
    /* jpeg_write_scanlines expects an array of pointers to scanlines.
     * Here the array is only one element long, but you could pass
     * more than one scanline at a time if that's more convenient.
     */
    row_pointer[0] = &pixels[i * row_stride];
    (void) jpeg_write_scanlines(&cinfo, row_pointer, 1);
    i--;
  }
  jpeg_finish_compress(&cinfo);
  jpeg_destroy_compress(&cinfo);                                 

  Free(pixels);
}
