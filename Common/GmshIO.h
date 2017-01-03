// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.
//
// Contribued by Alexis Salzman

#ifndef _GMSH_IO_H_
#define _GMSH_IO_H_

#include <stdio.h>
#include "GmshConfig.h"

#if defined(HAVE_COMPRESSED_IO) && defined(HAVE_LIBZ)

#include <zlib.h>
typedef gzFile gmshFILE;
typedef z_off_t gmshfpos_t;
#define gmshopen gzopen
#define gmshgets(a,b,c) gzgets((c),(a),(b))
#define gmshclose gzclose
#define gmsheof gzeof
#define gmshgetc gzgetc
#define gmshprintf gzprintf
#define gmsherror(a){ int ernum; char *gzerror(a,&ernum); return ernum; }
#define gmshsetpos(a, b){ return gzseek(a,*b,SEEK_SET); }
#define gmshgetpos(a, b){ *b=gztell(a); return 0; }

#else

typedef FILE *gmshFILE;
typedef fpos_t gmshfpos_t;
#define gmshopen Fopen
#define gmshgets fgets
#define gmshclose fclose
#define gmsheof feof
#define gmshgetc getc
#define gmshprintf fprintf
#define gmsherror ferror
#define gmshsetpos fsetpos
#define gmshgetpos fgetpos

#endif

#endif
