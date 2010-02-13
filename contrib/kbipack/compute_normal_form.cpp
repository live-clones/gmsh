/* 
   COMPUTE_NORMAL_FORM

   Hermite and Smith normal forms of integer matrices. 

   Implementation: Dense matrix with GMP-library's mpz_t elements to 
                   hold huge integers. 

   Algorithm: Kannan - Bachem algorithm with improvement by
              Chou and Collins. Expects a large number of unit invariant 
	      factors and takes advantage of them as they appear.

   References: 
    [1] Ravindran Kannan, Achim Bachem: 
        "Polynomial algorithms for computing the Smith and Hermite normal 
	forms of an integer matrix", 
	SIAM J. Comput., vol. 8, no. 5, pp. 499-507, 1979.
    [2] Tsu-Wu J.Chou, George E. Collins: 
        "Algorithms for the solution of systems of linear Diophantine 
	equations", 
	SIAM J. Comput., vol. 11, no. 4, pp. 687-708, 1982.
    [3] GMP homepage http://www.swox.com/gmp/
    [4] GNU gmp page http://www.gnu.org/software/gmp/

   Copyright (C) 3.11.2003 Saku Suuriniemi TUT/CEM

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
   
   $Id: compute_normal_form.c,v 1.1 2009-03-30 14:10:57 matti Exp $
*/


#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"gmp_matrix_io.h"
#include"gmp_normal_form.h"

typedef enum {HERMITE, SMITH}     nf_flag;
typedef enum {NOT_WANTED, WANTED} w_flag;

static int nf_parse_options(int arg_counter, char ** args, 
			    char ** p_infile_name, char ** p_outfile_name, 
			    nf_flag *       p_normal_form_requested, 
			    inverted_flag * p_left_inverted, 
			    inverted_flag * p_right_inverted, 
			    w_flag *        p_help_wanted, 
			    w_flag *        p_verbose_wanted)
{
  size_t ind1, ind2;
  size_t outfilename_length;
  
  /* If no infile is specified, the error is indisputable. 
      => Print help and exit. 
     Infile should be the last argument. */

  if(strncmp(args[arg_counter-1], "-", 1) == 0)
    {
      *(p_help_wanted) = WANTED;
      return EXIT_SUCCESS;
    }

  /* Should I find arguments? */
  if(arg_counter > 2)
    {
      for(ind1 = 1; ind1 < arg_counter-1; ind1++)
	{
	  /* No multiple infile names ! */
	  if(strncmp(args[ind1], "-", 1) != 0)
	    {
	      *(p_help_wanted) = WANTED;
	      return EXIT_SUCCESS;
	    }

	  /* Parse the option letters after '-' one by one */
	  for(ind2 = 1; ind2 < strlen(args[ind1]); ind2++)
	    {
	      switch(args[ind1][ind2])
		{
		case 'h':
		  *(p_help_wanted) = WANTED;
		  return EXIT_SUCCESS;
		  break;
		case 'H':
		  *(p_normal_form_requested) = HERMITE;
		  break;
		case 'S':
		  *(p_normal_form_requested) = SMITH;
		  break;
		case 'l':
		  *(p_left_inverted) = INVERTED;
		  break;
		case 'r':
		  *(p_right_inverted) = INVERTED;
		  break;
		case 'v':
		  *(p_verbose_wanted) = WANTED;
		  break;
		}
	    }	  
	}
    }

  /* Get the infile name */
  * p_infile_name = (char *) calloc(strlen(args[arg_counter-1]) + 1, 
				    sizeof(char));
  if(* p_infile_name == NULL)
    {
      return EXIT_FAILURE;
    }

  strcpy(* p_infile_name, args[arg_counter-1]);

  /* Create the outfile name */
  outfilename_length = strcspn( * p_infile_name, ".");
  * p_outfile_name = (char *) calloc(outfilename_length + 1, 
				     sizeof(char));
  if( * p_outfile_name == NULL)
    {
      free( * p_infile_name);
      return EXIT_FAILURE;
    }

  strncpy(* p_outfile_name, * p_infile_name, outfilename_length);
  (* p_outfile_name)[outfilename_length] = '\0';

  return EXIT_SUCCESS;
}

static int nf_print_help(void)
{
  fprintf(stdout, "Usage: compute_normal_form [-hHSlrv] infile\n");
  fprintf(stdout, "\n");
  fprintf(stdout, "Description: Compute the Hermite/Smith normal form of an integer matrix.\n");
  fprintf(stdout, "\n");
  fprintf(stdout, "Input: \"infile\" is an ascii file, which contains an integer matrix\n");
  fprintf(stdout, "       in the sparse coordinate format:\n"); 
  fprintf(stdout, "\n");
  fprintf(stdout, "        # All comments before the data\n");
  fprintf(stdout, "        rows columns nonzeros\n");
  fprintf(stdout, "        row1 col1    value1\n");
  fprintf(stdout, "        row2 col2    value2\n");
  fprintf(stdout, "        ...\n");
  fprintf(stdout, "\n");
  fprintf(stdout, "       No multiple infiles, please.\n");
  fprintf(stdout, "\n");
  fprintf(stdout, "Options: -h This help\n");
  fprintf(stdout, "         -H Compute the Hermite normal form (default)\n");
  fprintf(stdout, "         -S Compute the Smith normal form\n");
  fprintf(stdout, "         -l Left factor inverted (A = P^(T)LU instead of PA = LU for Hermite, \n");
  fprintf(stdout, "                                  U^(-1)A = SV instead of A = USV for Smith)\n");
  fprintf(stdout, "         -r Right factor inverted (PAU^(-1) = L instead of PA = LU for Hermite, \n");
  fprintf(stdout, "                                   AV^(-1) = US instead of A = USV for Smith)\n");
  fprintf(stdout, "         -v Verbose. Print the matrix and the decomposition to sdtout, \n");
  fprintf(stdout, "                     so that the user may check that the problem is read and written\n");
  fprintf(stdout, "                     correctly.\n");
  fprintf(stdout, "\n");
  fprintf(stdout, "Output: For inpur matrix in e.g. \"infile.coord\", writes ascii files\n");
  fprintf(stdout, "        \"infile.left\", \"infile.can\", and \"infile.right\", which \n");
  fprintf(stdout, "        contain the left factor, canonical form, and the right factor, \n");
  fprintf(stdout, "        respectively. The matrices are written in the sparse coordinate\n");
  fprintf(stdout, "        format.\n");
  fprintf(stdout, "\n");
  fprintf(stdout, "Note: The return values may be big enough to not fit the standard integer types.\n");
  fprintf(stdout, "\n");
  fprintf(stdout, "Copyright (C) 3.11.2003 Saku Suuriniemi, Tampere University of Technology/Electromagnetics\n");
  fprintf(stdout, "                        P.O.Box 692, FIN-33101 Tampere, Finland. saku.suuriniemi@tut.fi\n");
  fprintf(stdout, "\n");
  fprintf(stdout, "Licenced under GNU General Public Licence (GPL) version 2 or later, ABSOLUTELY NO WARRANTY.\n");

  return EXIT_SUCCESS;
}


static char* append_suffix(const char * file_base_name, const char * suffix)
{
  char * filename;

  if((file_base_name == NULL) || (suffix == NULL))
    {
      return NULL;
    }

  filename = 
    (char*) calloc(strlen(file_base_name)+strlen(suffix)+2,
		   sizeof(char));

  if(filename == NULL)
    {
      return NULL;
    }

  strcpy(filename, file_base_name);
  strcat(filename, ".");
  strcat(filename, suffix);

  return filename;
}



int main(int argc, char * argv[])
{
  char            * infile_name;
  char            * file_base_name;
  char            * outfile_name;
  gmp_matrix      * A;
  gmp_normal_form * normal_form;
  w_flag            help_wanted;
  w_flag            verbose_wanted;
  nf_flag           normal_form_requested;
  inverted_flag     left_inverted;
  inverted_flag     right_inverted;

  if(argc == 1)
    {
      fprintf(stdout, "Please try \"compute_normal_form -h\" for help.\n");
      return EXIT_SUCCESS;
    }

  /* Default settings before option parsing */
  normal_form_requested = HERMITE;
  left_inverted         = NOT_INVERTED;
  right_inverted        = NOT_INVERTED;
  help_wanted           = NOT_WANTED;
  verbose_wanted        = NOT_WANTED;

  if( nf_parse_options(argc, argv, 
		       &infile_name, &file_base_name, 
		       &normal_form_requested, 
		       &left_inverted, &right_inverted, 
		       &help_wanted, 
		       &verbose_wanted) 
      == EXIT_FAILURE )
    {
      return EXIT_FAILURE;
    }

  /* In this case, no dynamical memory has been allocated by 
     nf_parse_options ! */
  if(help_wanted == WANTED)
    {
      return nf_print_help();
    }

  if(verbose_wanted == WANTED)
    {
      fprintf(stdout, "Computing ");
      if(normal_form_requested == HERMITE)
	{
	  fprintf(stdout, "Hermite");
	}
      else
	{
	  fprintf(stdout, "Smith");
	}
      fprintf(stdout, " normal form\n");
      if(left_inverted == INVERTED)
	{
	  fprintf(stdout, "The left factor will be inverted.\n");
	}
      if(right_inverted == INVERTED)
	{
	  fprintf(stdout, "The right factor will be inverted.\n");
	}
      fprintf(stdout, "Matrix read from file %s\n", infile_name);
    }

  /*************************************************************/
  /* We have all we need to get to the computational business: */
  /*************************************************************/

  /* Read the matrix */
  A = gmp_matrix_read_coord(infile_name);
  free(infile_name);

  if(verbose_wanted == WANTED)
    {
      fprintf(stdout, "Input matrix:\n");
      gmp_matrix_fprintf(stdout, A);
    }

  /* Compute the requested normal form */
  switch(normal_form_requested)
    {
    case SMITH:
      normal_form = create_gmp_Smith_normal_form(A, left_inverted, right_inverted);
      break;

    default:
      normal_form = create_gmp_Hermite_normal_form(A, left_inverted, right_inverted);
      break;
    }


  if(verbose_wanted == WANTED)
    {
      fprintf(stdout, "Left factor:\n");
      gmp_matrix_fprintf(stdout, normal_form->left);
      fprintf(stdout, "Canonical form:\n");
      gmp_matrix_fprintf(stdout, normal_form->canonical);
      fprintf(stdout, "Right factor:\n");
      gmp_matrix_fprintf(stdout, normal_form->right);
    }

  /* Save the result to the output files */
  outfile_name = append_suffix(file_base_name, "left");
  if( gmp_matrix_write_coord(outfile_name, normal_form -> left) 
      == EXIT_SUCCESS)
    {
      if(verbose_wanted == WANTED)
	fprintf(stdout, "Left factor successfully writen to file     %s\n", outfile_name);
    }

  free(outfile_name);

  outfile_name = append_suffix(file_base_name, "can");
  if( gmp_matrix_write_coord(outfile_name, normal_form -> canonical)
      == EXIT_SUCCESS)
    {
      if(verbose_wanted == WANTED)
	fprintf(stdout, "Canonical form successfully writen to file  %s\n", outfile_name);
    }
  free(outfile_name);

  outfile_name = append_suffix(file_base_name, "right");
  if( gmp_matrix_write_coord(outfile_name, normal_form -> right)
      == EXIT_SUCCESS)
    {
      if(verbose_wanted == WANTED)
	fprintf(stdout, "Right factor successfully writen to file    %s\n", outfile_name);
    }
  free(outfile_name);

  free(file_base_name);
  destroy_gmp_normal_form(normal_form);
  
  return EXIT_SUCCESS;
}
