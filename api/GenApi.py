# Gmsh - Copyright (C) 1997-2018 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to the public mailing list <gmsh@onelab.info>.

# Contributor(s):
#   Jonathan Lambrechts

import textwrap
import string

class arg:
    def __init__(self, name, value, python_value, type_cpp, type_c, out):
        self.name = name
        self.value = value
        self.python_value = python_value if python_value is not None else value
        self.out = out
        self.type_cpp = type_cpp
        self.type_c = type_c
        self.cpp = self.type_cpp + " " + self.name + ((" = " + value) if value else "")

        self.c_arg = self.name
        self.c_pre = ""
        self.c_post = ""
        self.c = type_c + " " + name

        self.cwrap_arg = self.name
        self.cwrap_pre = ""
        self.cwrap_post = ""
                
        self.python_arg = "not_implemented"
        self.python_return = "not_implemented"
        self.python_pre = ""

# input types

def ibool(name, value=None, python_value=None):
    a = arg(name, value, python_value, "const bool", "const int", False)
    a.python_arg = "c_int(bool(" + name + "))"
    a.cwrap_arg = "(int)" + name
    return a

def iint(name, value=None, python_value=None):
    a = arg(name, value, python_value, "const int", "const int", False)
    a.python_arg = "c_int(" + name + ")"
    return a

def idouble(name, value=None, python_value=None):
    a = arg(name, value, python_value, "const double", "const double", False)
    a.python_arg = "c_double(" + name + ")"
    return a

def istring(name, value=None, python_value=None):
    a = arg(name, value, python_value, "const std::string &", "const char *", False)
    a.python_arg = "c_char_p(" + name + ".encode())"
    a.cwrap_arg = name + ".c_str()"
    return a

def ivectorint(name, value=None, python_value=None):
    a = arg(name, value, python_value, "const std::vector<int> &", "const int *", False)
    api_name = "api_" + name + "_"
    api_name_n = "api_" + name + "_n_"
    a.c_pre = "    std::vector<int> " + api_name + "(" + name + ", " + name + " + " + name + "_n);\n"
    a.c_arg = api_name
    a.c = "int * " + name + ", size_t " + name + "_n"
    a.cwrap_pre = "int *" + api_name + "; size_t " + api_name_n + "; " + \
                  "vector2ptr(" + name + ", &" + api_name + ", &" + api_name_n + ");\n"
    a.cwrap_arg = api_name + ", " + api_name_n
    a.cwrap_post = "gmshFree(" + api_name + ");\n"
    a.python_pre = api_name + ", " + api_name_n + " = _ivectorint(" + name + ")"
    a.python_arg = api_name + ", " + api_name_n
    return a

def ivectordouble(name, value=None, python_value=None):
    a = arg(name, value, python_value, "const std::vector<double> &", "double **", False)
    api_name = "api_" + name + "_"
    api_name_n = "api_" + name + "_n_"
    a.c_pre = "    std::vector<double> " + api_name + "(" + name + ", " + name + " + " + name + "_n);\n"
    a.c_arg = api_name
    a.c = "double * " + name + ", size_t " + name + "_n"
    a.cwrap_pre = "double *" + api_name + "; size_t " + api_name_n + "; " + \
                  "vector2ptr(" + name + ", &" + api_name + ", &" + api_name_n + ");\n"
    a.cwrap_arg = api_name + ", " + api_name_n
    a.cwrap_post = "gmshFree(" + api_name + ");\n"
    a.python_pre = api_name + ", " + api_name_n + " = _ivectordouble(" + name + ")"
    a.python_arg = api_name + ", " + api_name_n
    return a

def ivectorpair(name, value=None, python_value=None):
    a = arg(name, value, python_value, "const gmsh::vector_pair &", "const int *", False)
    api_name = "api_" + name + "_"
    api_name_n = "api_" + name + "_n_"
    a.c_pre = "    gmsh::vector_pair " + api_name + "(" + name + "_n/2);\n" + \
              "    for(size_t i = 0; i < " + name + "_n/2; ++i){\n" + \
              "      " + api_name + "[i].first = " + name + "[i * 2 + 0];\n" + \
              "      " + api_name + "[i].second = " + name + "[i * 2 + 1];\n" + \
              "    }\n"
    a.c_arg = api_name
    a.c = "int * " + name + ", size_t " + name + "_n"
    a.cwrap_pre = "int *" + api_name + "; size_t " + api_name_n + "; " + \
                  "pairvector2intptr(" + name + ", &" + api_name + ", &" + api_name_n + ");\n"
    a.cwrap_arg = api_name + ", " + api_name_n
    a.cwrap_post = "gmshFree(" + api_name + ");\n"
    a.python_pre = api_name + ", " + api_name_n + " = _ivectorpair(" + name + ")"
    a.python_arg = api_name + ", " + api_name_n
    return a

def ivectorvectorint(name, value=None, python_value=None):
    a = arg(name, value, python_value, "const std::vector<std::vector<int> > &", "const int **", False)
    api_name = "api_" + name + "_"
    api_name_n = "api_" + name + "_n_"
    api_name_nn = "api_" + name + "_nn_"
    a.c_pre = "    std::vector<std::vector<int> > " + api_name + "(" + name + "_nn);\n" + \
              "    for(size_t i = 0; i < " + name + "_nn; ++i)\n" + \
              "      " + api_name + "[i] = std::vector<int>(" + name + "[i], " + name + "[i] + " + name + "_n[i]);\n"
    a.c_arg = api_name
    a.c = "const int ** " + name + ", const size_t * " + name + "_n, " + "size_t " + name + "_nn"
    a.cwrap_pre = "int **" + api_name + "; size_t *" + api_name_n + ", " + api_name_nn + "; " + \
                  "vectorvector2ptrptr(" + name + ", &" + api_name + ", &" + api_name_n + ", &" + api_name_nn + ");\n"
    a.cwrap_arg = "(const int **)" + api_name + ", " + api_name_n + ", " + api_name_nn
    a.cwrap_post = "for(size_t i = 0; i < " + api_name_nn + "; ++i){ gmshFree(" + api_name + "[i]); } " + \
                    "gmshFree(" + api_name + "); gmshFree(" + api_name_n + ");\n"
    a.python_pre = api_name + ", " + api_name_n + ", " + api_name_nn + " = _ivectorvectorint(" + name + ")"
    a.python_arg = api_name + ", " + api_name_n + ", " + api_name_nn
    return a

def ivectorvectordouble(name, value=None, python_value=None):
    a = arg(name, value, python_value, "const std::vector<std::vector<double> > &", "const double**", False)
    api_name = "api_" + name + "_"
    api_name_n = "api_" + name + "_n_"
    api_name_nn = "api_" + name + "_nn_"
    a.c_pre = "    std::vector<std::vector<double> > " + api_name + "(" + name + "_nn);\n" + \
              "    for(size_t i = 0; i < " + name + "_nn; ++i)\n" + \
              "      " + api_name + "[i] = std::vector<double>(" + name + "[i], " + name + "[i] + " + name + "_n[i]);\n"
    a.c_arg = api_name
    a.c = "const double ** " + name + ", const size_t * " + name + "_n, " + "size_t " + name + "_nn"
    a.cwrap_pre = "double **" + api_name + "; size_t *" + api_name_n + ", " + api_name_nn + "; " + \
                  "vectorvector2ptrptr(" + name + ", &" + api_name + ", &" + api_name_n + ", &" + api_name_nn + ");\n"
    a.cwrap_arg = "(const double **)" + api_name + ", " + api_name_n + ", " + api_name_nn
    a.cwrap_post = "for(size_t i = 0; i < " + api_name_nn + "; ++i){ gmshFree(" + api_name + "[i]); } " + \
                    "gmshFree(" + api_name + "); gmshFree(" + api_name_n + ");\n"
    a.python_pre = api_name + ", " + api_name_n + ", " + api_name_nn + " = _ivectorvectordouble(" + name + ")"
    a.python_arg = api_name + ", " + api_name_n + ", " + api_name_nn
    return a

# output types

class oint(arg):
    rtype_cpp = "int"
    rtype_c = "int"
    rtype_texi = "integer"
    def __init__(self, name, value=None, python_value=None):
        arg.__init__(self, name, value, python_value, "int &", "int *", True)
        api_name = "api_" + name + "_"
        self.c_arg = "*" + name
        self.cwrap_arg = "&" + name
        self.python_pre = api_name + " = c_int()"
        self.python_arg = "byref(" + api_name + ")"
        self.python_return = api_name + ".value"

def odouble(name, value=None, python_value=None):
    a = arg(name, value, python_value, "double &", "double *", True)
    api_name = "api_" + name + "_"
    a.c_arg = "*" + name
    a.cwrap_arg = "&" + name
    a.python_pre = api_name + " = c_double()"
    a.python_arg = "byref(" + api_name + ")"
    a.python_return = api_name + ".value"
    return a

def ostring(name, value=None, python_value=None):
    a = arg(name, value, python_value, "std::string &", "char **", True)
    api_name = "api_" + name + "_"
    a.c_pre = "    std::string " + api_name + ";\n"
    a.c_arg = api_name
    a.c_post = "    *" + name + " = strdup(" + api_name + ".c_str());\n"
    a.cwrap_pre = "char *" + api_name + ";\n"
    a.cwrap_arg = "&" + api_name
    a.cwrap_post = name + " = *" + api_name + "; gmshFree(" + api_name + ");\n"
    a.python_pre = api_name + " = c_char_p()"
    a.python_arg = "byref(" + api_name + ")"
    a.python_return = "_ostring(" + api_name + ")"
    return a

def ovectorint(name, value=None, python_value=None):
    a = arg(name, value, python_value, "std::vector<int> &", "int **", True)
    api_name = "api_" + name + "_"
    api_name_n = api_name + "n_"
    a.c_pre = "    std::vector<int> " + api_name + ";\n"
    a.c_arg = api_name
    a.c_post = "    vector2ptr(" + api_name + ", " + name + ", " + name + "_n);\n"
    a.c = "int ** " + name + ", size_t * " + name + "_n"
    a.cwrap_pre = "int *" + api_name + "; size_t " + api_name_n + ";\n"
    a.cwrap_arg = "&" + api_name + ", " + "&" + api_name_n
    a.cwrap_post = name + ".assign(" + api_name + ", " + api_name + " + " + api_name_n + "); gmshFree(" + api_name + ");\n"
    a.python_pre = api_name + ", " + api_name_n + " = POINTER(c_int)(), c_size_t()"
    a.python_arg = "byref(" + api_name + "), byref(" + api_name_n + ")"
    a.python_return = "_ovectorint(" + api_name + ", " + api_name_n + ".value)"
    return a

def ovectordouble(name, value=None, python_value=None):
    a = arg(name, value, python_value, "std::vector<double> &", "double *", True)
    api_name = "api_" + name + "_"
    api_name_n = api_name + "n_"
    a.c_pre = "    std::vector<double> " + api_name + ";\n"
    a.c_arg = api_name
    a.c_post = "    vector2ptr(" + api_name + ", " + name + ", " + name + "_n);\n"
    a.c = "double ** " + name + ", size_t * " + name + "_n"
    a.cwrap_pre = "double *" + api_name + "; size_t " + api_name_n + ";\n"
    a.cwrap_arg = "&" + api_name + ", " + "&" + api_name_n
    a.cwrap_post = name + ".assign(" + api_name + ", " + api_name + " + " + api_name_n + "); " +\
                   "gmshFree(" + api_name + ");\n"
    a.python_pre = api_name + ", " + api_name_n + " = POINTER(c_double)(), c_size_t()"
    a.python_arg = "byref(" + api_name + "), byref(" + api_name_n + ")"
    a.python_return = "_ovectordouble(" + api_name + ", " + api_name_n + ".value)"
    return a

def ovectorstring(name, value=None, python_value=None):
    a = arg(name, value, python_value, "std::vector<std::string> &", "char **", True)
    api_name = "api_" + name + "_"
    api_name_n = api_name + "n_"
    a.c_pre = "    std::vector<std::string> " + api_name + ";\n"
    a.c_arg = api_name
    a.c_post = "    stringvector2charpp(" + api_name + ", " + name + ", " + name + "_n);\n"
    a.c = "char *** " + name + ", size_t * " + name + "_n"
    a.cwrap_pre = "char **" + api_name + "; size_t " + api_name_n + ";\n"
    a.cwrap_arg = "&" + api_name + ", " + "&" + api_name_n
    a.cwrap_post = name + ".resize(" + api_name_n + "); " +\
                   "for(size_t i = 0; i < " + api_name_n + "; ++i){ " +\
                   name + "[i] = std::string(" + api_name + "[i]); gmshFree(" + api_name + "[i]); } " +\
                   "gmshFree(" + api_name + ");\n"
    a.python_pre = api_name + ", " + api_name_n + " = POINTER(POINTER(c_char))(), c_size_t()"
    a.python_arg = "byref(" + api_name + "), byref(" + api_name_n + ")"
    a.python_return = "_ovectorstring(" + api_name + ", " + api_name_n + ".value)"
    return a

def ovectorpair(name, value=None, python_value=None):
    a = arg(name, value, python_value, "gmsh::vector_pair &", "int **", True)
    api_name = "api_" + name + "_"
    api_name_n = api_name + "n_"
    a.c_pre = "    gmsh::vector_pair " + api_name + ";\n"
    a.c_arg = api_name
    a.c_post = "    pairvector2intptr(" + api_name + ", " + name + ", " + name + "_n);\n"
    a.c = "int ** " + name + ", size_t * " + name + "_n"
    a.cwrap_pre = "int *" + api_name + "; size_t " + api_name_n + ";\n"
    a.cwrap_arg = "&" + api_name + ", " + "&" + api_name_n
    a.cwrap_post = name + ".resize(" + api_name_n + " / 2); " +\
                   "for(size_t i = 0; i < " + api_name_n + " / 2; ++i){ " +\
                   name + "[i].first = " + api_name + "[i * 2 + 0]; " + \
                   name + "[i].second = " + api_name + "[i * 2 + 1]; } " +\
                   "gmshFree(" + api_name + ");\n"
    a.python_pre = api_name + ", " + api_name_n + " = POINTER(c_int)(), c_size_t()"
    a.python_arg = "byref(" + api_name + "), byref(" + api_name_n + ")"
    a.python_return = "_ovectorpair(" + api_name + ", " + api_name_n + ".value)"
    return a

def ovectorvectorint(name, value=None, python_value=None):
    a = arg(name, value, python_value, "std::vector<std::vector<int> > &", "int **", True)
    api_name = "api_" + name + "_"
    api_name_n = api_name + "n_"
    api_name_nn = api_name + "nn_"
    a.c_pre = "    std::vector<std::vector<int> > " + api_name + ";\n"
    a.c_arg = api_name
    a.c_post = "    vectorvector2ptrptr(" + api_name + ", " + name + ", " + name + "_n, " + name + "_nn);\n"
    a.c  = "int *** " + name + ", size_t ** " + name + "_n, size_t *" + name + "_nn"
    a.cwrap_pre = "int **" + api_name + "; size_t *" + api_name_n + ", " + api_name_nn + ";\n"
    a.cwrap_arg = "&" + api_name + ", " + "&" + api_name_n + ", " + "&" + api_name_nn
    a.cwrap_post = name + ".resize(" + api_name_nn + "); " +\
                   "for(size_t i = 0; i < " + api_name_nn + "; ++i){ " +\
                   name + "[i].assign(" + api_name + "[i], " + api_name + "[i] + " + api_name_n + "[i]); gmshFree(" + api_name + "[i]); } " +\
                   "gmshFree(" + api_name + "); gmshFree(" + api_name_n + ");\n"
    a.python_pre = api_name + ", " + api_name_n + ", " + api_name_nn + " = POINTER(POINTER(c_int))(), POINTER(c_size_t)(), c_size_t()"
    a.python_arg = "byref(" + api_name + "), byref(" + api_name_n + "), byref(" + api_name_nn + ")"
    a.python_return = "_ovectorvectorint(" + api_name + ", " + api_name_n + ", " + api_name_nn + ")"
    return a

def ovectorvectordouble(name, value=None, python_value=None):
    a = arg(name, value, python_value, "std::vector<std::vector<double> > &", "double **", True)
    api_name = "api_" + name + "_"
    api_name_n = api_name + "n_"
    api_name_nn = api_name + "nn_"
    a.c_pre = "    std::vector<std::vector<double> > " + api_name + ";\n"
    a.c_arg = api_name
    a.c_post = "    vectorvector2ptrptr(" + api_name + ", " + name + ", " + name + "_n, " + name + "_nn);\n"
    a.c  = "double *** " + name + ", size_t ** " + name + "_n, size_t *" + name + "_nn"
    a.cwrap_pre = "double **" + api_name + "; size_t *" + api_name_n + ", " + api_name_nn + ";\n"
    a.cwrap_arg = "&" + api_name + ", " + "&" + api_name_n + ", " + "&" + api_name_nn
    a.cwrap_post = name + ".resize(" + api_name_nn + "); " +\
                   "for(size_t i = 0; i < " + api_name_nn + "; ++i){ " +\
                   name + "[i].assign(" + api_name + "[i], " + api_name + "[i] + " + api_name_n + "[i]); gmshFree(" + api_name + "[i]); } " +\
                   "gmshFree(" + api_name + "); gmshFree(" + api_name_n + ");\n"
    a.python_pre = api_name + ", " + api_name_n + ", " + api_name_nn + " = POINTER(POINTER(c_double))(), POINTER(c_size_t)(), c_size_t()"
    a.python_arg = "byref(" + api_name + "), byref(" + api_name_n + "), byref(" + api_name_nn + ")"
    a.python_return = "_ovectorvectordouble(" + api_name + ", " + api_name_n + ", " + api_name_nn + ")"
    return a

def ovectorvectorpair(name, value=None, python_value=None):
    a = arg(name, value, python_value, "std::vector<gmsh::vector_pair> &", "int **", True)
    api_name = "api_" + name + "_"
    api_name_n = api_name + "n_"
    api_name_nn = api_name + "nn_"
    a.c_pre = "    std::vector<gmsh::vector_pair >" + api_name + ";\n"
    a.c_arg = api_name
    a.c_post = "    pairvectorvector2intptrptr(" + api_name + ", " + name + ", " + name + "_n, " + name + "_nn);\n"
    a.c  = "int *** " + name + ", size_t ** " + name + "_n, size_t *" + name + "_nn"
    a.cwrap_pre = "int **" + api_name + "; size_t *" + api_name_n + ", " + api_name_nn + ";\n"
    a.cwrap_arg = "&" + api_name + ", " + "&" + api_name_n + ", " + "&" + api_name_nn
    a.cwrap_post = name + ".resize(" + api_name_nn + "); " +\
                   "for(size_t i = 0; i < " + api_name_nn + "; ++i){ " +\
                   name + "[i].resize(" + api_name_n + "[i] / 2); " +\
                   "for(size_t j = 0; j < " + api_name_n + "[i] / 2; ++j){ " +\
                   name + "[i][j].first = " + api_name + "[i][j * 2 + 0]; " +\
                   name + "[i][j].second = " + api_name + "[i][j * 2 + 1]; } " +\
                   "gmshFree(" + api_name + "[i]); } " +\
                   "gmshFree(" + api_name + "); gmshFree(" + api_name_n + ");\n"
    a.python_pre = api_name + ", " + api_name_n + ", " + api_name_nn + " = POINTER(POINTER(c_int))(), POINTER(c_size_t)(), c_size_t()"
    a.python_arg = "byref(" + api_name + "), byref(" + api_name_n + "), byref(" + api_name_nn + ")"
    a.python_return = "_ovectorvectorpair(" + api_name + ", " + api_name_n + ", " + api_name_nn + ")"
    return a

def argcargv():
    a = arg("", None, None, "", "", False)
    a.cpp = "int argc = 0, char ** argv = 0"
    a.c_arg = "argc, argv"
    a.c = "int argc, char ** argv"
    a.c_pre = ""
    a.c_post = ""
    a.cwrap_arg = "argc, argv"
    a.name = "argv"
    a.python_value = "[]"
    a.python_arg = "api_argc_, api_argv_"
    a.python_pre = "api_argc_, api_argv_ = _iargcargv(argv)"
    return a

class Module:

    def __init__(self, name, doc):
        self.name = name
        self.doc = doc
        self.fs = []
        self.submodules = []

    def add(self, name, doc, rtype, *args):
        self.fs.append((rtype, name, args, doc, False))

    # a raw C implementation of the function is available
    def add_rawc(self, name, doc, rtype, *args):
        self.fs.append((rtype, name, args, doc, True))
        
    def add_module(self, name, doc):
        module = Module(name, doc)
        self.submodules.append(module)
        return module


cpp_header="""// Gmsh - Copyright (C) 1997-2018 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _GMSH_H_
#define _GMSH_H_

// This file defines the Gmsh C++ API.
//
// Do not edit it directly: it is automatically generated by `api/gen.py'.
//
// By design, the Gmsh C++ API is purely functional, and only uses elementary
// types from the standard library. A pure C as well as a Python API are also
// automatically generated by `api/gen.py': see `gmshc.h' and `gmsh.py'.
//
// See `demos/api' for examples on how to use the Gmsh API. In particular,
// `demos/api' contains C++ and Python versions of several of the `.geo'
// tutorials from `tutorials'.

#include <cmath>
#include <vector>
#include <string>

#if defined(GMSH_DLL)
#if defined(GMSH_DLL_EXPORT)
#define GMSH_API __declspec(dllexport)
#else
#define GMSH_API __declspec(dllimport)
#endif
#else
#define GMSH_API
#endif

namespace gmsh {

  // A geometrical entity in the Gmsh API is represented by two integers: its
  // dimension (dim = 0, 1, 2 or 3) and its tag (its unique, strictly positive
  // identifier). When dealing with multiple geometrical entities of possibly
  // different dimensions, the entities are packed as a vector of (dim, tag)
  // integer pairs.
  typedef std::vector<std::pair<int, int> > vector_pair;

}

"""

cpp_footer="""#endif
"""

c_header="""/*
 * Gmsh - Copyright (C) 1997-2018 C. Geuzaine, J.-F. Remacle
 *
 * See the LICENSE.txt file for license information. Please report all
 * bugs and problems to the public mailing list <gmsh@onelab.info>.
 */

#ifndef _GMSHC_H_
#define _GMSHC_H_

/*
 * This file defines the Gmsh C API.
 *
 * Do not edit it directly: it is automatically generated by `api/gen.py'.
 *
 * By design, the Gmsh C API is purely functional, and only uses elementary
 * types. A C++ as well as a Python API are also automatically generated by
 * `api/gen.py': see `gmsh.h' and `gmsh.py'.
 *
 * See `demos/api' for examples on how to use the Gmsh API. In particular,
 * `demos/api' contains C++ and Python versions of several of the `.geo'
 * tutorials from `tutorials'.
 */

#include <stdlib.h>

#if defined(GMSH_DLL)
#if defined(GMSH_DLL_EXPORT)
#define GMSH_API __declspec(dllexport)
#else
#define GMSH_API __declspec(dllimport)
#endif
#else
#define GMSH_API
#endif

GMSH_API void gmshFree(void *p);
"""

c_footer="""
#endif
"""

c_cpp_header="""// Gmsh - Copyright (C) 1997-2018 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include <string.h>
#include "gmsh.h"

extern \"C\" {
  #include "gmshc.h"
}

void gmshFree(void *p)
{
  if(p) free(p);
}
"""

c_cpp_utils="""
template<typename t>
void vector2ptr(const std::vector<t> &v, t **p, size_t *size)
{
  *p = (t*)malloc(sizeof(t) * v.size());
  for(size_t i = 0; i < v.size(); ++i){
    (*p)[i] = v[i];
  }
  *size = v.size();
}

void pairvector2intptr(const gmsh::vector_pair &v, int **p, size_t *size)
{
  *p = (int*)malloc(sizeof(int) * v.size() * 2);
  for(size_t i = 0; i < v.size(); ++i){
    (*p)[i * 2 + 0] = v[i].first;
    (*p)[i * 2 + 1] = v[i].second;
  }
  *size = v.size() * 2;
}

void stringvector2charpp(const std::vector<std::string> &v, char ***p, size_t *size)
{
  *p = (char**)malloc(sizeof(char*) * v.size() * 2);
  for(size_t i = 0; i < v.size(); ++i){
    (*p)[i] = strdup(v[i].c_str());
  }
  *size = v.size();
}

template<typename t>
void vectorvector2ptrptr(const std::vector<std::vector<t> > &v, t ***p, size_t **size, size_t *sizeSize)
{
  *p = (t**)malloc(sizeof(t*) * v.size());
  *size = (size_t*)malloc(sizeof(size_t) * v.size());
  for(size_t i = 0; i < v.size(); ++i)
    vector2ptr(v[i], &((*p)[i]), &((*size)[i]));
  *sizeSize = v.size();
}

void pairvectorvector2intptrptr(const std::vector<gmsh::vector_pair > &v, int ***p, size_t **size, size_t *sizeSize)
{
  *p = (int**)malloc(sizeof(int*) * v.size());
  *size = (size_t*)malloc(sizeof(size_t) * v.size());
  for(size_t i = 0; i < v.size(); ++i)
    pairvector2intptr(v[i], &(*p)[i], &((*size)[i]));
  *sizeSize = v.size();
}
"""

cwrap_header="""// Gmsh - Copyright (C) 1997-2018 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _GMSH_H_
#define _GMSH_H_

// This file redefines the C++ API in terms of the Gmsh C API. 
//
// This is provided as a convenience for users of the binary Gmsh SDK, whose C++
// compiler ABI is not compatible with the ABI of the C++ compiler used to create 
// the SDK (and who can thus not directly use the C++ API defined in `gmsh.h').
//
// To use this header file in your C++ code, simply rename it as `gmsh.h'.
//
// Warning: using this header file will lead to (slightly) reduced performance
// compared to using the native Gmsh C++ API from the original `gmsh.h', as it 
// entails additional data copies between this C++ wrapper, the C API and the
// native C++ code.
//
// Do not edit this file directly: it is automatically generated by `api/gen.py'.

#include <cmath>
#include <vector>
#include <string>

#if defined(GMSH_DLL)
#if defined(GMSH_DLL_EXPORT)
#define GMSH_API __declspec(dllexport)
#else
#define GMSH_API __declspec(dllimport)
#endif
#else
#define GMSH_API
#endif

extern \"C\" {
  #include "gmshc.h"
}

namespace gmsh {

  // A geometrical entity in the Gmsh API is represented by two integers: its
  // dimension (dim = 0, 1, 2 or 3) and its tag (its unique, strictly positive
  // identifier). When dealing with multiple geometrical entities of possibly
  // different dimensions, the entities are packed as a vector of (dim, tag)
  // integer pairs.
  typedef std::vector<std::pair<int, int> > vector_pair;

}

"""

cwrap_footer="""#endif
"""
  
python_header = """# Gmsh - Copyright (C) 1997-2018 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to the public mailing list <gmsh@onelab.info>.

# This file defines the Gmsh Pyhton API.
#
# Do not edit it directly: it is automatically generated by `api/gen.py'.
#
# By design, the Gmsh Pyhton API is purely functional, and only uses elementary
# types (as well as `numpy' arrays if `numpy' is avaiable). A C++ as well as a
# pure C API are also automatically generated by `api/gen.py': see `gmsh.h'
# and `gmshc.h'.
#
# See `demos/api' for examples on how to use the Gmsh API. In particular,
# `demos/api' contains C++ and Python versions of several of the `.geo'
# tutorials from `tutorials'.

from ctypes import *
import signal
import os
import platform
from math import pi

signal.signal(signal.SIGINT, signal.SIG_DFL)
libdir = os.path.dirname(os.path.realpath(__file__))
if platform.system() == 'Windows':
    lib = CDLL(libdir + "/gmsh-{0}.dll")
elif platform.system() == 'Darwin':
    lib = CDLL(libdir + "/libgmsh.dylib")
else:
    lib = CDLL(libdir + "/libgmsh.so")

use_numpy = False
try:
    import numpy
    try:
        from weakref import finalize as weakreffinalize
    except:
        from backports.weakref import finalize as weakreffinalize
    use_numpy = True
except:
    pass

def _ostring(s):
    sp = s.value.decode("utf-8")
    lib.gmshFree(s)
    return sp

def _ovectorpair(ptr, size):
    if use_numpy:
        v = numpy.ctypeslib.as_array(ptr, (size//2, 2))
        weakreffinalize(v, lib.gmshFree, ptr)
    else:
        v = list((ptr[i * 2], ptr[i * 2 + 1]) for i in range(size//2))
        lib.gmshFree(ptr)
    return v

def _ovectorint(ptr, size):
    if use_numpy:
        v = numpy.ctypeslib.as_array(ptr, (size, ))
        weakreffinalize(v, lib.gmshFree, ptr)
    else:
        v = list(ptr[i] for i in range(size))
        lib.gmshFree(ptr)
    return v

def _ovectordouble(ptr, size):
    if use_numpy:
        v = numpy.ctypeslib.as_array(ptr, (size, ))
        weakreffinalize(v, lib.gmshFree, ptr)
    else:
        v = list(ptr[i] for i in range(size))
        lib.gmshFree(ptr)
    return v

def _ovectorstring(ptr, size):
    v = list(_ostring(cast(ptr[i], c_char_p)) for i in range(size))
    lib.gmshFree(ptr)
    return v

def _ovectorvectorint(ptr, size, n):
    v = [_ovectorint(pointer(ptr[i].contents), size[i]) for i in range(n.value)]
    lib.gmshFree(size)
    lib.gmshFree(ptr)
    return v

def _ovectorvectordouble(ptr, size, n):
    v = [_ovectordouble(pointer(ptr[i].contents), size[i]) for i in range(n.value)]
    lib.gmshFree(size)
    lib.gmshFree(ptr)
    return v

def _ovectorvectorpair(ptr, size, n):
    v = [_ovectorpair(pointer(ptr[i].contents), size[i]) for i in range(n.value)]
    lib.gmshFree(size)
    lib.gmshFree(ptr)
    return v

def _ivectorint(o):
    if use_numpy:
        return numpy.ascontiguousarray(o, numpy.int32).ctypes, c_size_t(len(o))
    else:
        return (c_int * len(o))(*o), c_size_t(len(o))

def _ivectorvectorint(os):
    n = len(os)
    parrays = [_ivectorint(o) for o in os]
    sizes = (c_size_t * n)(*(a[1] for a in parrays))
    arrays = (POINTER(c_int) * n)(*(cast(a[0], POINTER(c_int)) for a in parrays))
    arrays.ref = [a[0] for a in parrays]
    size = c_size_t(n)
    return arrays, sizes, size

def _ivectorvectordouble(os):
    n = len(os)
    parrays = [_ivectordouble(o) for o in os]
    sizes = (c_size_t * n)(*(a[1] for a in parrays))
    arrays = (POINTER(c_double) * n)(*(cast(a[0], POINTER(c_double)) for a in parrays))
    arrays.ref = [a[0] for a in parrays]
    size = c_size_t(n)
    return arrays, sizes, size

def _ivectordouble(o):
    if use_numpy:
        array = numpy.ascontiguousarray(o, numpy.float64)
        ct = array.ctypes
        ct.array = array
        return  ct, c_size_t(len(o))
    else:
        return (c_double * len(o))(*o), c_size_t(len(o))

def _ivectorpair(o):
    if use_numpy:
        array = numpy.ascontiguousarray(o, numpy.int32)
        ct = array.ctypes
        ct.array = array
        return  ct, c_size_t(len(o) * 2)
    else:
        return ((c_int * 2) * len(o))(*o), c_size_t(len(o) * 2)

def _iargcargv(o):
    return c_int(len(o)), (c_char_p * len(o))(*(s.encode() for s in o))

"""

class API:

    def __init__(self, version):
        self.api_version = version
        self.modules = []

    def add_module(self, name, doc):
        module = Module(name, doc)
        self.modules.append(module)
        return module

    def write_cpp(self):
        def write_module(module, indent):
            f.write(indent + "namespace " + module.name + " { // " + module.doc + "\n\n")
            indent += "  "
            for rtype, name, args, doc, rawc in module.fs:
                f.write(indent + "// " + ("\n" + indent + "// ").join(textwrap.wrap(doc, 80-len(indent))) + "\n")
                rt = rtype.rtype_cpp if rtype else "void"
                fnameapi = indent + "GMSH_API " + rt + " " + name + "(";
                f.write(fnameapi)
                if args:
                    f.write((",\n" + ' ' * len(fnameapi)).join(a.cpp for a in args))
                f.write(");\n\n")
            for m in module.submodules:
                write_module(m, indent)
            f.write(indent[:-2] + "} // namespace " + module.name + "\n\n")
        with open("gmsh.h", "w") as f:
            f.write(cpp_header)
            for m in self.modules:
                write_module(m, "")
            f.write(cpp_footer)

    def write_c(self):
        def write_module(module, c_namespace, cpp_namespace, indent):
            cpp_namespace += module.name + "::"
            if c_namespace:
                c_namespace += module.name[0].upper() + module.name[1:]
            else:
                c_namespace = module.name
            fcwrap.write(indent + "namespace " + module.name + " { // " + module.doc + "\n\n")
            indent += "  "
            for rtype, name, args, doc, rawc in module.fs:
                # gmshc.h
                fname = c_namespace + name[0].upper() + name[1:]
                f.write("\n/* " + "\n * ".join(textwrap.wrap(doc, 75)) + " */\n")
                fnameapi = "GMSH_API " + (rtype.rtype_c if rtype else "void") + " " + fname + "("
                f.write(fnameapi
                        + (",\n" + ' ' * len(fnameapi)).join(list((a.c for a in args + (oint("ierr"), ))))
                        + ");\n")
                if not rawc:
                    # gmshc.cpp
                    fc.write("GMSH_API " + (rtype.rtype_c if rtype else "void"))
                    fc.write(" " + fname + "("
                             + ", ".join(list((a.c for a in args + (oint("ierr"), )))) + ")\n{\n")
                    if rtype:
                        fc.write("  " + rtype.rtype_c + " result_api_;\n")
                    fc.write("  if(ierr) *ierr = 0;\n");
                    fc.write("  try {\n");
                    fc.write("".join((a.c_pre for a in args)))
                    fc.write("    ")
                    if rtype:
                        fc.write("result_api_ = ")
                    fc.write(cpp_namespace + name + "(" + ", ".join(
                        list((a.c_arg for a in args))) + 
                             ");\n")
                    fc.write("".join((a.c_post for a in args)))
                    fc.write("  }\n  catch(int api_ierr_){\n    if(ierr) *ierr = api_ierr_;\n  }\n");
                    if rtype:
                        fc.write("  return result_api_;\n");
                    fc.write("}\n\n")
                # gmsh.h_cwrap
                fcwrap.write(indent + "// " + ("\n" + indent + "// ").join(textwrap.wrap(doc, 80-len(indent))) + "\n")
                rt = rtype.rtype_cpp if rtype else "void"
                fnameapi = indent + "GMSH_API " + rt + " " + name + "(";
                fcwrap.write(fnameapi)
                if args:
                    fcwrap.write((",\n" + ' ' * len(fnameapi)).join(a.cpp for a in args))
                fcwrap.write(")\n" + indent + "{\n" + indent + "  int ierr = 0;\n")
                for a in args:
                    if a.cwrap_pre:
                        fcwrap.write(indent + "  " + a.cwrap_pre)
                fcwrap.write(indent + "  ")
                if rtype:
                    fcwrap.write("int result_api_ = ")
                fcwrap.write(fname + "(" + ", ".join((a.cwrap_arg for a in args)))
                if args:
                    fcwrap.write(", &ierr);\n")
                else:
                    fcwrap.write("&ierr);\n")
                fcwrap.write(indent + "  " + "if(ierr) throw ierr;\n");
                for a in args:
                    if a.cwrap_post:
                        fcwrap.write(indent + "  " + a.cwrap_post)
                if rtype:
                    fcwrap.write(indent + "  " + "return result_api_;\n")
                fcwrap.write(indent + "}\n\n")
            for m in module.submodules:
                write_module(m, c_namespace, cpp_namespace, indent)
            fcwrap.write(indent[:-2] + "} // namespace " + module.name + "\n\n")
        with open("gmshc.h", "w") as f:
            with open("gmshc.cpp", "w") as fc:
                with open("gmsh.h_cwrap", "w") as fcwrap:
                    f.write(c_header)
                    fc.write(c_cpp_header)
                    fc.write(c_cpp_utils)
                    fc.write("\n")
                    fcwrap.write(cwrap_header)
                    fcwrap.write("namespace gmsh {\n")
                    s = string.split(c_cpp_utils, '\n')
                    for line in s:
                        fcwrap.write("  " + line + "\n")
                    fcwrap.write("}\n\n")
                    for module in self.modules:
                        write_module(module, "", "", "")
                    f.write(c_footer)
                    fcwrap.write(cwrap_footer)

    def write_python(self):
        def parg(a):
            return a.name + (("=" + a.python_value) if a.python_value else "")
        def write_function(f, fun, modulepath, indent):
            (rtype, name, args, doc, rawc) = fun
            iargs = list(a for a in args if not a.out)
            oargs = list(a for a in args if a.out)
            f.write("\n")
            if modulepath != "gmsh":
                f.write(indent + "@staticmethod\n")
            f.write(indent + "def " + name + "("
                   + ", ".join((parg(a) for a in iargs))
                   + "):\n")
            indent += "    "
            f.write(indent + '"""\n')
            f.write(indent + ("\n" + indent).join(textwrap.wrap(doc, 75)) + "\n")
            if rtype or oargs:
                f.write("\n" + indent + "Returns " + ", ".join(
                    (["an " + rtype.rtype_texi] if rtype else[])
                   + [("`" + a.name + "'") for a in oargs])
               + ".\n")
            f.write(indent + '"""\n')
            for a in args:
                if a.python_pre: f.write(indent + a.python_pre + "\n")
            f.write(indent + "ierr = c_int()\n")
            f.write(indent + "api__result__ = " if rtype is oint else (indent))
            c_name = modulepath + name[0].upper() + name[1:]
            f.write("lib." + c_name + "(\n    " + indent
                   + (",\n" + indent + "    ").join(tuple((a.python_arg for a in args)) + ("byref(ierr)", ))
                   + ")\n")
            f.write(indent + "if ierr.value != 0:\n")
            f.write(indent + "    raise ValueError(\n")
            f.write(indent + "        \"" + c_name + " returned non-zero error code: \",\n")
            f.write(indent + "        ierr.value)\n")
            r = (["api__result__"]) if rtype else []
            r += list((o.python_return for o in oargs))
            if len(r) != 0:
                if len(r) == 1:
                    f.write(indent + "return " + r[0] + "\n")
                else:
                    f.write(indent + "return (\n" + indent + "    " + (",\n" + indent + "    ").join(r) + ")\n")
        def write_module(f, m, modulepath, indent):
            if modulepath:
                modulepath += m.name[0].upper() + m.name[1:]
            else:
                modulepath = m.name
            for fun in m.fs:
                write_function(f, fun, modulepath, indent)
            for module in m.submodules:
                f.write("\n\n" + indent + "class " + module.name + ":\n")
                indentm = indent + "    "
                f.write(indentm + '"""\n')
                f.write(indentm + ("\n" + indentm).join(textwrap.wrap(module.doc, 75)) + "\n")
                f.write(indentm + '"""\n')
                write_module(f, module, modulepath, indentm)
        with open("gmsh.py", "w") as f:
            f.write(python_header.format(self.api_version))
            for module in self.modules:
                write_module(f, module, "", "")

    def write_texi(self):
        def write_module(module, parent):
            full = parent + "/" + module.name
            f.write("@heading Module @code{" + full + "}\n");
            f.write("@ftable @code\n");
            for rtype, name, args, doc, rawc in module.fs:
                f.write("@item " + name + "\n");
                tdoc = doc.replace("`", "@code{").replace("'", "}")
                f.write("\n".join(textwrap.wrap(tdoc, 80)) + "\n\n")
                f.write("@table @asis\n");
                iargs = list(a for a in args if not a.out)
                oargs = list(a for a in args if a.out)
                f.write("@item " + "Input:\n" + 
                        (", ".join(("@code{" + iarg.name + "}") for iarg in iargs)
                         if len(iargs) else "-") + "\n")
                f.write("@item " + "Output:\n" + 
                        (", ".join(("@code{" + oarg.name + "}") for oarg in oargs)
                         if len(oargs) else "-") + "\n")
                f.write("@item " + "Return:\n" + 
                        (rtype.rtype_texi if rtype else "-") + "\n")
                f.write("@end table\n\n");
            f.write("@end ftable\n\n");
            for m in module.submodules:
                write_module(m, full)
        with open("api.texi", "w") as f:
            f.write("@c This file was generated by api/gen.py: do not edit manually!\n\n")
            for m in self.modules:
                write_module(m, "")
