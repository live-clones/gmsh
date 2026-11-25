// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef SCRIPT_STYLES_H
#define SCRIPT_STYLES_H

#include <string>

// The colors of a script (.geo, .opt) or of a problem of GetDP (.pro) in an
// editor: the style of each character, for the editor of the graphical
// interface and that of the web page

enum scriptStyle {
  StylePlain = 'A',
  StyleComment, // "//" to the end of the line, "/*" to "*/"
  StyleString,
  StyleNumber,
  StyleWord, // a word of the language: a command, a function, a type, ...
  StyleOption // an option of Gmsh, as "Mesh.Algorithm" or "View[0].Visible"
};

// the style of each character of the text of a file (a string of the same
// length)
std::string GetScriptStyles(const std::string &fileName,
                            const std::string &text);

#endif
