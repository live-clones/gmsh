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

  $Id: gmp_matrix_io.h,v 1.1 2009-03-30 14:10:57 matti Exp $
 */

#ifndef _GMP_MATRIX_IO_
#define _GMP_MATRIX_IO_


#include "gmp_matrix.h"

gmp_matrix * gmp_matrix_read_coord(char* filename);
int          gmp_matrix_write_coord(char* filename, const gmp_matrix * M);


#endif
