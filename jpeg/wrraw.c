/*
 * wrraw.c
 *
 * Copyright (C) 1991-1994, Thomas G. Lane.
 * This file is part of the Independent JPEG Group's software.
 * For conditions of distribution and use, see the accompanying README file.
 *
 * This file contains routines to write output the raw YCC subsampled data
 * read from the jpeg file.
 *
 * These routines may need modification for non-Unix environments or
 * specialized applications.  As they stand, they assume output to
 * an ordinary stdio stream.
 *  
 *  Based on code contributed by James Arthur Boucher
 */

#include "cdjpeg.h"             /* Common decls for cjpeg/djpeg applications */


#ifdef RAW_SUPPORTED


/*
 * Haven't yet got around to making this work with text-format output,
 * hence cannot handle pixels wider than 8 bits.
 */

#if BITS_IN_JSAMPLE != 8
  Sorry, this code only copes with 8-bit JSAMPLEs. /* deliberate syntax err */
#endif

/*
 *
 * The output buffer needs to be writable by fwrite().  On PCs, we must
 * allocate the buffer in near data space, because we are assuming small-data
 * memory model, wherein fwrite() can't reach far memory.  If you need to
 * process very wide images on a PC, you might have to compile in large-memory
 * model, or else replace fwrite() with a putc() loop --- which will be much
 * slower.
 */


/* Private version of data destination object */

typedef struct {
  struct djpeg_dest_struct pub; /* public fields */

  JSAMPLE *iobuffer;            /* non-FAR pointer to I/O buffer */
  JSAMPROW pixrow;              /* FAR pointer to same */
  JDIMENSION buffer_width;      /* width of one row */
} raw_dest_struct;

typedef raw_dest_struct * raw_dest_ptr;


/*
 * Write some pixel data. In this module rows_supplied can be variable
 */

METHODDEF void
put_pixel_rows (j_decompress_ptr cinfo, djpeg_dest_ptr dinfo,
		JDIMENSION rows_supplied)
{
  raw_dest_ptr dest = (raw_dest_ptr) dinfo;
  int ci,cp;
  JDIMENSION ncols,nrows;
  jpeg_component_info *compptr;

  TRACEMS(cinfo,2,JERR_RAW_PPR);
  for(cp=0,compptr = cinfo->comp_info; cp <cinfo->num_components;
       cp++,compptr++){
   ncols = (JDIMENSION)((cinfo->image_width*compptr->h_samp_factor)/
           cinfo->max_h_samp_factor);
   nrows = (JDIMENSION)((rows_supplied*compptr->v_samp_factor)/
           cinfo->max_v_samp_factor);

  for(ci =0;ci<nrows;ci++){
  TRACEMS1(cinfo,3,JTRC_RAW_PUTROW,ci);  
(void) JFWRITE(dest->pub.output_file, dest->pub.image_buffer[cp][ci],
               ncols);
   }
}
   TRACEMS(cinfo,2,JTRC_RAW_PUTEND);
  
}



/*
 * Startup: write null header.
 */

METHODDEF void
start_output (j_decompress_ptr cinfo, djpeg_dest_ptr dinfo)
{ /* do nothing*/
}


/*
 * Finish up at the end of the file.
 */

METHODDEF void
finish_output (j_decompress_ptr cinfo, djpeg_dest_ptr dinfo)
{
  /* Make sure we wrote the output file OK */
  fflush(dinfo->output_file);
  if (ferror(dinfo->output_file))
    ERREXIT(cinfo, JERR_FILE_WRITE);
}


/*
 * The module selection routine for raw format output.
 */

GLOBAL djpeg_dest_ptr
jinit_write_raw (j_decompress_ptr cinfo)
{
  raw_dest_ptr dest;
  int cp;
  JDIMENSION ncols,nrows;
  jpeg_component_info *compptr;
  int temp;
  int h_samp[3],v_samp[3];

  TRACEMS(cinfo,1,JTRC_RAW_INIT);

  cinfo->out_color_space = JCS_YCbCr; /* We want YCbCr or YUV output */
  cinfo->want_raw_output = TRUE;     /* boolean used in main and api */

  /* This module does not work unless JSAMPLE is a char. */
  /* Unfortunately, we can't test it at compile time. */
  if (SIZEOF(JSAMPLE) != SIZEOF(char))
    ERREXIT(cinfo, JERR_RAW_SAMPLESIZE);

  /* Create module interface object, fill in method pointers */
  dest = (raw_dest_ptr)
      (*cinfo->mem->alloc_small) ((j_common_ptr) cinfo, JPOOL_IMAGE,
				  SIZEOF(raw_dest_struct));

  dest->pub.start_output = start_output;
  dest->pub.finish_output = finish_output;

  /* Calculate output image dimensions so we can allocate space */
  jpeg_calc_output_dimensions(cinfo);

  /* Create I/O buffer.  Note we make this near on a PC. */
  dest->buffer_width = (cinfo->output_width);

/* calculate max_h(v)_samp_factors since not done yet */  
for(cp=0,compptr = cinfo->comp_info;cp<cinfo->num_components;
          cp++,compptr++){
   h_samp[cp] = compptr->h_samp_factor;
   v_samp[cp] = compptr->v_samp_factor;
 }
  /* assumes three components */
  temp = (h_samp[0]<h_samp[1]) ? h_samp[1] : h_samp[0];
  cinfo->max_h_samp_factor = (temp<h_samp[2]) ? h_samp[2]:temp;
  temp = (v_samp[0]<v_samp[1]) ? v_samp[1]:v_samp[0];
  cinfo->max_v_samp_factor = (temp<v_samp[2]) ? v_samp[2]:temp;  

/* chose to make buffer up to 8 rows high, 2 and 4 also valid */
  dest->pub.buffer_height = 8;


/* allocate sample arrays for each component */
  for(cp=0,compptr = cinfo->comp_info;cp<cinfo->num_components;
            cp++,compptr++){

    ncols = (JDIMENSION)((cinfo->image_width*compptr->h_samp_factor)/
          cinfo->max_h_samp_factor);

    nrows = (JDIMENSION)((dest->pub.buffer_height*compptr->v_samp_factor)/
            cinfo->max_v_samp_factor);

    dest->pub.image_buffer[cp] = (*cinfo->mem->alloc_sarray)((j_common_ptr)
                      cinfo,JPOOL_IMAGE,ncols,nrows);
   }


    dest->pub.put_pixel_rows = put_pixel_rows;
    TRACEMS(cinfo,1,JTRC_RAW_IEND);

  return (djpeg_dest_ptr) dest;
}

#endif /* RAW_SUPPORTED */
