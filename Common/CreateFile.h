// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _CREATE_FILE_H_
#define _CREATE_FILE_H_

#include <string>

int GetFileFormatFromExtension(const std::string &fileName);
int GuessFileFormatFromFileName(const std::string &fileName);
std::string GetDefaultFileName(int format);
void CreateOutputFile(const std::string &fileName, int format,
                      bool status=true, bool redraw=true);

#endif
