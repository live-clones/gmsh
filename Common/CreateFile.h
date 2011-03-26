// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _CREATE_FILE_H_
#define _CREATE_FILE_H_

#include <string>

int GuessFileFormatFromFileName(std::string fileName);
std::string GetDefaultFileName(int format);
void CreateOutputFile(std::string fileName, int format);

#endif
