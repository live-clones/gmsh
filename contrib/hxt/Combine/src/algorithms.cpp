
#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>

#include <string>
#include <vector>

#include "algorithms.h"

/**
* \authors Jeanne Pellerin, Kilian Verhetsel, Jonathan Lambrechts
*/

// Used to enumerate files in a directory.
#if defined WIN32
#include <io.h> 
#else
#include <glob.h>
#endif

void enumerateFiles(
  const std::string& directory,
  const std::string& extension,
  std::vector<std::string>& filenames)
{
  std::string filespecs = directory + "*." + extension;
#if defined WIN32
  _finddata_t data;
  intptr_t currentFile = _findfirst(filespecs.c_str(), &data);

  if (currentFile != -1) {
    int isTheEnd = 0;
    while (isTheEnd != -1) {
      std::string fullName = directory + data.name;
      filenames.push_back(fullName);
      isTheEnd = _findnext(currentFile, &data);
    }
    _findclose(currentFile);
  }
#else
  glob_t pglob;
  if (glob(filespecs.c_str(), 0, NULL, &pglob) == 0) {
    for (size_t i = 0; i < pglob.gl_pathc; ++i) {
      filenames.push_back(pglob.gl_pathv[i]);
    }
  }
  globfree(&pglob);
#endif
}
