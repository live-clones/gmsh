// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
#ifndef _CREATE_FILE_H_
#define _CREATE_FILE_H_


int GuessFileFormatFromFileName(const char *name);
void GetDefaultFileName(int format, char *name);
void CreateOutputFile(const char *name, int format);

#endif
