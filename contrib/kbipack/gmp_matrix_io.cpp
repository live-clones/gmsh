/*
  IO-routines for gmp integer matrices in coordinate format.

  Copyright (C) 19.11.2003 Saku Suuriniemi TUT/CEM

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  any later version.
   
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

  Saku Suuriniemi, TUT/Electromagetics
  P.O.Box 692, FIN-33101 Tampere, Finland
  saku.suuriniemi@tut.fi

  $Id: gmp_matrix_io.c,v 1.1 2009-03-30 14:10:57 matti Exp $
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "gmp_matrix_io.h"

gmp_matrix * gmp_matrix_read_coord(char* filename)
{
  FILE *  p_file;
  size_t  read_values;
  size_t  row, col, nrows, ncols, dummy;
  int     val;
  char    buffer[1000];
  gmp_matrix * new_matrix;
  
  p_file = fopen(filename, "r");
  if(p_file == NULL)
    return NULL;

  /* Matlab and Octave typically include comments on ascii files. */
  /* They start with # */
  fgets(buffer, 999, p_file);
  while(strncmp(buffer, "#",1) == 0)
    {
      fgets(buffer, 999, p_file);
    }

  /* First read the size of the matrix */
  read_values = sscanf(buffer, "%u %u %u", &nrows, &ncols, &dummy);

  /* Create the matrix */
  new_matrix = create_gmp_matrix_zero(nrows, ncols);
  if(new_matrix == NULL)
    {
      fclose(p_file);
      return NULL;
    }

  /* Read the values to the matrix */
  while(read_values != EOF)
    {
      read_values = fscanf(p_file, "%u %u %i\n", &row, &col, &val);
      if( (row <= nrows) && (row > 0) && (col <= ncols) && (col > 0) )
	{
	  mpz_set_si ( new_matrix->storage[(row-1)+(col-1)*nrows], val );
	}
    }
  fclose(p_file);

  return new_matrix;
}

int gmp_matrix_write_coord(char* filename, gmp_matrix * M)
{

  FILE *  p_file;
  size_t  written_values;
  size_t  row, col, nrows, ncols, nnz;
  mpz_t   outz;

  if(M == NULL)
    {
      return EXIT_FAILURE;
    }

  nrows = M->rows;
  ncols = M->cols;

  p_file = fopen(filename, "w");
  if(p_file == NULL)
    return 0;

  nnz = 0;
  /* Compute the number of nonzeros for coordinate format */
  mpz_init(outz);
  for(col = 1; col <= ncols ; col++)
    {
      for(row = 1; row <= nrows ; row++)
	{
	  gmp_matrix_get_elem(outz, row, col, M);
	  if( mpz_cmp_si (outz, 0) != 0)
	    {
	      nnz++;
	    }
	}
    }

  /* First write the size of the matrix */
  written_values = fprintf(p_file, "%u %u %u\n", nrows, ncols, nnz);

  /* Write the values to the matrix */
  for(col = 1; col <= ncols ; col++)
    {
      for(row = 1; row <= nrows ; row++)
	{
	  gmp_matrix_get_elem(outz, row, col, M);
	  if( mpz_cmp_si (outz, 0) != 0)
	    {
	      fprintf(p_file, "%u %u ", row, col);
	      mpz_out_str (p_file, 10, outz);
	      fprintf(p_file, "\n");
	    }
	}
    }
  mpz_clear(outz);  

  fclose(p_file);

  return EXIT_SUCCESS;
}
