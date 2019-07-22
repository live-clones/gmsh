# Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

# Contributor(s):
#   Jonathan Lambrechts

import textwrap
import string

class arg:
    def __init__(self, name, value, python_value, julia_value,
                 cpp_type, c_type, out):
        self.name = name
        self.value = value
        self.out = out
        self.cpp = cpp_type + " " + name + ((" = " + value) if value else "")
        self.c_arg = name
        self.c_pre = ""
        self.c_post = ""
        self.c = c_type + " " + name
        self.cwrap_arg = self.name
        self.cwrap_pre = ""
        self.cwrap_post = ""
        self.python_value = python_value if python_value is not None else value
        self.python_arg = ""
        self.python_return = ""
        self.python_pre = ""
        self.julia_value = julia_value if julia_value is not None else value
        self.julia_arg = name
        self.julia_ctype = ""
        self.julia_pre = ""
        self.julia_post = ""
        self.julia_return = name

# input types

def ibool(name, value=None, python_value=None, julia_value=None):
    a = arg(name, value, python_value, julia_value,
            "const bool", "const int", False)
    a.python_arg = "c_int(bool(" + name + "))"
    a.cwrap_arg = "(int)" + name
    a.julia_ctype = "Cint"
    return a

def iint(name, value=None, python_value=None, julia_value=None):
    a = arg(name, value, python_value, julia_value,
            "const int", "const int", False)
    a.python_arg = "c_int(" + name + ")"
    a.julia_ctype = "Cint"
    return a

def isize(name, value=None, python_value=None, julia_value=None):
    a = arg(name, value, python_value, julia_value,
            "const std::size_t", "const size_t", False)
    a.python_arg = "c_size_t(" + name + ")"
    a.julia_ctype = "Csize_t"
    return a

def idouble(name, value=None, python_value=None, julia_value=None):
    a = arg(name, value, python_value, julia_value,
            "const double", "const double", False)
    a.python_arg = "c_double(" + name + ")"
    a.julia_ctype = "Cdouble"
    return a

def istring(name, value=None, python_value=None, julia_value=None):
    a = arg(name, value, python_value, julia_value,
            "const std::string &", "const char *", False)
    a.python_arg = "c_char_p(" + name + ".encode())"
    a.cwrap_arg = name + ".c_str()"
    a.julia_ctype = "Ptr{Cchar}"
    return a

def ivoidstar(name, value=None, python_value=None, julia_value=None):
    a = arg(name, value, python_value, julia_value,
            "const void *", "const void *", False)
    a.python_arg = "c_void_p(" + name + ")"
    a.julia_ctype = "Ptr{Cvoid}"
    return a

def ivectorint(name, value=None, python_value=None, julia_value=None):
    if julia_value == "[]":
        julia_value = "Cint[]"
    a = arg(name, value, python_value, julia_value,
            "const std::vector<int> &", "const int *", False)
    api_name = "api_" + name + "_"
    api_name_n = "api_" + name + "_n_"
    a.c_pre = ("    std::vector<int> " + api_name + "(" + name + ", " + name +
               " + " + name + "_n);\n")
    a.c_arg = api_name
    a.c = "int * " + name + ", size_t " + name + "_n"
    a.cwrap_pre = ("int *" + api_name + "; size_t " + api_name_n + "; " +
                   "vector2ptr(" + name + ", &" + api_name + ", &" + api_name_n + ");\n")
    a.cwrap_arg = api_name + ", " + api_name_n
    a.cwrap_post = ns + "Free(" + api_name + ");\n"
    a.python_pre = api_name + ", " + api_name_n + " = _ivectorint(" + name + ")"
    a.python_arg = api_name + ", " + api_name_n
    a.julia_ctype = "Ptr{Cint}, Csize_t"
    a.julia_arg = "convert(Vector{Cint}, " + name + "), length(" + name + ")"
    return a

def ivectorsize(name, value=None, python_value=None, julia_value=None):
    if julia_value == "[]":
        julia_value = "Csize_t[]"
    a = arg(name, value, python_value, julia_value,
            "const std::vector<std::size_t> &", "const size_t *", False)
    api_name = "api_" + name + "_"
    api_name_n = "api_" + name + "_n_"
    a.c_pre = ("    std::vector<std::size_t> " + api_name + "(" + name + ", " + name +
               " + " + name + "_n);\n")
    a.c_arg = api_name
    a.c = "size_t * " + name + ", size_t " + name + "_n"
    a.cwrap_pre = ("size_t *" + api_name + "; size_t " + api_name_n + "; " +
                   "vector2ptr(" + name + ", &" + api_name + ", &" + api_name_n + ");\n")
    a.cwrap_arg = api_name + ", " + api_name_n
    a.cwrap_post = ns + "Free(" + api_name + ");\n"
    a.python_pre = api_name + ", " + api_name_n + " = _ivectorsize(" + name + ")"
    a.python_arg = api_name + ", " + api_name_n
    a.julia_ctype = "Ptr{Csize_t}, Csize_t"
    a.julia_arg = "convert(Vector{Csize_t}, " + name + "), length(" + name + ")"
    return a

def ivectordouble(name, value=None, python_value=None, julia_value=None):
    if julia_value == "[]":
        julia_value = "Cdouble[]"
    a = arg(name, value, python_value, julia_value,
            "const std::vector<double> &", "double **", False)
    api_name = "api_" + name + "_"
    api_name_n = "api_" + name + "_n_"
    a.c_pre = ("    std::vector<double> " + api_name + "(" + name + ", " +
               name + " + " + name + "_n);\n")
    a.c_arg = api_name
    a.c = "double * " + name + ", size_t " + name + "_n"
    a.cwrap_pre = ("double *" + api_name + "; size_t " + api_name_n + "; " +
                   "vector2ptr(" + name + ", &" + api_name + ", &" + api_name_n + ");\n")
    a.cwrap_arg = api_name + ", " + api_name_n
    a.cwrap_post = ns + "Free(" + api_name + ");\n"
    a.python_pre = api_name + ", " + api_name_n + " = _ivectordouble(" + name + ")"
    a.python_arg = api_name + ", " + api_name_n
    a.julia_ctype = "Ptr{Cdouble}, Csize_t"
    a.julia_arg = "convert(Vector{Cdouble}, " + name + "), length(" + name + ")"
    return a

def ivectorstring(name, value=None, python_value=None, julia_value=None):
    a = arg(name, value, python_value, julia_value,
            "const std::vector<std::string> &", "char **", False)
    api_name = "api_" + name + "_"
    api_name_n = "api_" + name + "_n_"
    a.c_pre = ("    std::vector<std::string> " + api_name + "(" + name + ", " +
               name + " + " + name + "_n);\n")
    a.c_arg = api_name
    a.c = "char ** " + name + ", size_t " + name + "_n"
    a.cwrap_pre = ("char **" + api_name + "; size_t " + api_name_n + "; " +
                   "vectorstring2charptrptr(" + name + ", &" + api_name + ", &" + api_name_n + ");\n")
    a.cwrap_arg = api_name + ", " + api_name_n
    a.cwrap_post = ("for(size_t i = 0; i < " + api_name_n + "; ++i){ " +
                    ns + "Free(" + api_name + "[i]); } " +
                    ns + "Free(" + api_name + ");\n")
    a.python_pre = api_name + ", " + api_name_n + " = _ivectorstring(" + name + ")"
    a.python_arg = api_name + ", " + api_name_n
    a.julia_ctype = "Ptr{Ptr{Cchar}}, Csize_t"
    a.julia_arg = name + ", length(" + name + ")"
    return a

def ivectorpair(name, value=None, python_value=None, julia_value=None):
    if julia_value == "[]":
        julia_value = "Tuple{Cint,Cint}[]"
    a = arg(name, value, python_value, julia_value,
            "const " + ns + "::vectorpair &", "const int *", False)
    api_name = "api_" + name + "_"
    api_name_n = "api_" + name + "_n_"
    a.c_pre = ("    " + ns + "::vectorpair " + api_name + "(" + name + "_n/2);\n" +
               "    for(size_t i = 0; i < " + name + "_n/2; ++i){\n" +
               "      " + api_name + "[i].first = " + name + "[i * 2 + 0];\n" +
               "      " + api_name + "[i].second = " + name + "[i * 2 + 1];\n" +
               "    }\n")
    a.c_arg = api_name
    a.c = "int * " + name + ", size_t " + name + "_n"
    a.cwrap_pre = ("int *" + api_name + "; size_t " + api_name_n + "; " +
                   "vectorpair2intptr(" + name + ", &" + api_name + ", &" +
                   api_name_n + ");\n")
    a.cwrap_arg = api_name + ", " + api_name_n
    a.cwrap_post = ns + "Free(" + api_name + ");\n"
    a.python_pre = api_name + ", " + api_name_n + " = _ivectorpair(" + name + ")"
    a.python_arg = api_name + ", " + api_name_n
    a.julia_ctype = "Ptr{Cint}, Csize_t"
    a.julia_arg = ("convert(Vector{Cint}, collect(Cint, Iterators.flatten(" + name + "))), " +
                   "2 * length(" + name + ")")
    return a

def ivectorvectorint(name, value=None, python_value=None, julia_value=None):
    if julia_value == "[]":
        julia_value = "Vector{Cint}[]"
    a = arg(name, value, python_value, julia_value,
            "const std::vector<std::vector<int> > &", "const int **", False)
    api_name = "api_" + name + "_"
    api_name_n = "api_" + name + "_n_"
    api_name_nn = "api_" + name + "_nn_"
    a.c_pre = ("    std::vector<std::vector<int> > " + api_name +
               "(" + name + "_nn);\n" +
               "    for(size_t i = 0; i < " + name + "_nn; ++i)\n" +
               "      " + api_name + "[i] = std::vector<int>(" + name + "[i], " +
               name + "[i] + " + name + "_n[i]);\n")
    a.c_arg = api_name
    a.c = ("const int ** " + name + ", const size_t * " + name + "_n, " +
           "size_t " + name + "_nn")
    a.cwrap_pre = ("int **" + api_name + "; size_t *" + api_name_n + ", " +
                   api_name_nn + "; " + "vectorvector2ptrptr(" + name + ", &" +
                   api_name + ", &" + api_name_n + ", &" + api_name_nn + ");\n")
    a.cwrap_arg = "(const int **)" + api_name + ", " + api_name_n + ", " + api_name_nn
    a.cwrap_post = ("for(size_t i = 0; i < " + api_name_nn + "; ++i){ " +
                    ns + "Free(" + api_name + "[i]); } " +
                    ns + "Free(" + api_name + "); " + ns + "Free(" + api_name_n + ");\n")
    a.python_pre = (api_name + ", " + api_name_n + ", " +
                    api_name_nn + " = _ivectorvectorint(" + name + ")")
    a.python_arg = api_name + ", " + api_name_n + ", " + api_name_nn
    a.julia_ctype = "Ptr{Ptr{Cint}}, Ptr{Csize_t}, Csize_t"
    a.julia_pre = (api_name_n + " = [ length(" + name + "[i]) for i in 1:length(" +
                   name + ") ]")
    a.julia_arg = ("convert(Vector{Vector{Cint}}," + name + "), " + api_name_n +
                   ", length(" + name + ")")
    return a

def ivectorvectorsize(name, value=None, python_value=None, julia_value=None):
    if julia_value == "[]":
        julia_value = "Vector{Csize_t}[]"
    a = arg(name, value, python_value, julia_value,
            "const std::vector<std::vector<std::size_t> > &", "const size_t **", False)
    api_name = "api_" + name + "_"
    api_name_n = "api_" + name + "_n_"
    api_name_nn = "api_" + name + "_nn_"
    a.c_pre = ("    std::vector<std::vector<std::size_t> > " + api_name +
               "(" + name + "_nn);\n" +
               "    for(size_t i = 0; i < " + name + "_nn; ++i)\n" +
               "      " + api_name + "[i] = std::vector<std::size_t>(" + name + "[i], " +
               name + "[i] + " + name + "_n[i]);\n")
    a.c_arg = api_name
    a.c = ("const size_t ** " + name + ", const size_t * " + name + "_n, " +
           "size_t " + name + "_nn")
    a.cwrap_pre = ("size_t **" + api_name + "; size_t *" + api_name_n + ", " +
                   api_name_nn + "; " + "vectorvector2ptrptr(" + name + ", &" +
                   api_name + ", &" + api_name_n + ", &" + api_name_nn + ");\n")
    a.cwrap_arg = "(const size_t **)" + api_name + ", " + api_name_n + ", " + api_name_nn
    a.cwrap_post = ("for(size_t i = 0; i < " + api_name_nn + "; ++i){ " +
                    ns + "Free(" + api_name + "[i]); } " +
                    ns + "Free(" + api_name + "); " + ns + "Free(" + api_name_n + ");\n")
    a.python_pre = (api_name + ", " + api_name_n + ", " +
                    api_name_nn + " = _ivectorvectorsize(" + name + ")")
    a.python_arg = api_name + ", " + api_name_n + ", " + api_name_nn
    a.julia_ctype = "Ptr{Ptr{Csize_t}}, Ptr{Csize_t}, Csize_t"
    a.julia_pre = (api_name_n + " = [ length(" + name + "[i]) for i in 1:length(" +
                   name + ") ]")
    a.julia_arg = ("convert(Vector{Vector{Csize_t}}," + name + "), " + api_name_n +
                   ", length(" + name + ")")
    return a

def ivectorvectordouble(name, value=None, python_value=None, julia_value=None):
    if julia_value == "[]":
        julia_value = "Vector{Cdouble}[]"
    a = arg(name, value, python_value, julia_value,
            "const std::vector<std::vector<double> > &", "const double**", False)
    api_name = "api_" + name + "_"
    api_name_n = "api_" + name + "_n_"
    api_name_nn = "api_" + name + "_nn_"
    a.c_pre = ("    std::vector<std::vector<double> > " + api_name +
               "(" + name + "_nn);\n" +
               "    for(size_t i = 0; i < " + name + "_nn; ++i)\n" +
               "      " + api_name + "[i] = std::vector<double>(" + name + "[i], " +
               name + "[i] + " + name + "_n[i]);\n")
    a.c_arg = api_name
    a.c = ("const double ** " + name + ", const size_t * " + name + "_n, " +
           "size_t " + name + "_nn")
    a.cwrap_pre = ("double **" + api_name + "; size_t *" + api_name_n + ", " +
                   api_name_nn + "; " +
                   "vectorvector2ptrptr(" + name + ", &" + api_name + ", &" +
                   api_name_n + ", &" + api_name_nn + ");\n")
    a.cwrap_arg = "(const double **)" + api_name + ", " + api_name_n + ", " + api_name_nn
    a.cwrap_post = ("for(size_t i = 0; i < " + api_name_nn + "; ++i){ " +
                    ns + "Free(" + api_name + "[i]); } " +
                    ns + "Free(" + api_name + "); " + ns + "Free(" + api_name_n + ");\n")
    a.python_pre = (api_name + ", " + api_name_n + ", " + api_name_nn +
                    " = _ivectorvectordouble(" + name + ")")
    a.python_arg = api_name + ", " + api_name_n + ", " + api_name_nn
    a.julia_ctype = "Ptr{Ptr{Cdouble}}, Ptr{Csize_t}, Csize_t"
    a.julia_pre = (api_name_n + " = [ length(" + name + "[i]) for i in 1:length(" +
                   name + ") ]")
    a.julia_arg = ("convert(Vector{Vector{Cdouble}}," + name + "), " + api_name_n +
                   ", length(" + name + ")")
    return a

# output types

class oint(arg):
    rcpp_type = "int"
    rc_type = "int"
    rtexi_type = "integer value"
    rjulia_type = "Cint"
    def __init__(self, name, value=None, python_value=None, julia_value=None):
        arg.__init__(self, name, value, python_value, julia_value,
                     "int &", "int *", True)
        api_name = "api_" + name + "_"
        self.c_arg = "*" + name
        self.cwrap_arg = "&" + name
        self.python_pre = api_name + " = c_int()"
        self.python_arg = "byref(" + api_name + ")"
        self.python_return = api_name + ".value"
        self.julia_ctype = "Ptr{Cint}"
        self.julia_pre = api_name + " = Ref{Cint}()"
        self.julia_arg = api_name
        self.julia_return = api_name + "[]"

class osize(arg):
    rcpp_type = "std::size_t"
    rc_type = "size_t"
    rtexi_type = "size value"
    rjulia_type = "Csize_t"
    def __init__(self, name, value=None, python_value=None, julia_value=None):
        arg.__init__(self, name, value, python_value, julia_value,
                     "std::size_t &", "size_t *", True)
        api_name = "api_" + name + "_"
        self.c_arg = "*" + name
        self.cwrap_arg = "&" + name
        self.python_pre = api_name + " = c_size_t()"
        self.python_arg = "byref(" + api_name + ")"
        self.python_return = api_name + ".value"
        self.julia_ctype = "Ptr{Csize_t}"
        self.julia_pre = api_name + " = Ref{Csize_t}()"
        self.julia_arg = api_name
        self.julia_return = api_name + "[]"

class odouble(arg):
    rcpp_type = "double"
    rc_type = "double"
    rtexi_type = "floating point value"
    rjulia_type = "Cdouble"
    def __init__(self, name, value=None, python_value=None, julia_value=None):
        arg.__init__(self, name, value, python_value, julia_value,
                     "double &", "double *", True)
        api_name = "api_" + name + "_"
        self.c_arg = "*" + name
        self.cwrap_arg = "&" + name
        self.python_pre = api_name + " = c_double()"
        self.python_arg = "byref(" + api_name + ")"
        self.python_return = api_name + ".value"
        self.julia_ctype = "Ptr{Cdouble}"
        self.julia_pre = api_name + " = Ref{Cdouble}()"
        self.julia_arg = api_name
        self.julia_return = api_name + "[]"

def ostring(name, value=None, python_value=None, julia_value=None):
    a = arg(name, value, python_value, julia_value,
            "std::string &", "char **", True)
    api_name = "api_" + name + "_"
    a.c_pre = "    std::string " + api_name + ";\n"
    a.c_arg = api_name
    a.c_post = "    *" + name + " = strdup(" + api_name + ".c_str());\n"
    a.cwrap_pre = "char *" + api_name + ";\n"
    a.cwrap_arg = "&" + api_name
    a.cwrap_post = (name + " = std::string(" + api_name + "); " +
                    ns + "Free(" + api_name + ");\n")
    a.python_pre = api_name + " = c_char_p()"
    a.python_arg = "byref(" + api_name + ")"
    a.python_return = "_ostring(" + api_name + ")"
    a.julia_ctype = "Ptr{Ptr{Cchar}}"
    a.julia_pre = api_name + " = Ref{Ptr{Cchar}}()"
    a.julia_arg = api_name
    a.julia_post = name + " = unsafe_string(" + api_name + "[])"
    return a

def ovectorint(name, value=None, python_value=None, julia_value=None):
    a = arg(name, value, python_value, julia_value,
            "std::vector<int> &", "int **", True)
    api_name = "api_" + name + "_"
    api_name_n = api_name + "n_"
    a.c_pre = "    std::vector<int> " + api_name + ";\n"
    a.c_arg = api_name
    a.c_post = "    vector2ptr(" + api_name + ", " + name + ", " + name + "_n);\n"
    a.c = "int ** " + name + ", size_t * " + name + "_n"
    a.cwrap_pre = "int *" + api_name + "; size_t " + api_name_n + ";\n"
    a.cwrap_arg = "&" + api_name + ", " + "&" + api_name_n
    a.cwrap_post = (name + ".assign(" + api_name + ", " + api_name + " + " +
                    api_name_n + "); " + ns + "Free(" + api_name + ");\n")
    a.python_pre = api_name + ", " + api_name_n + " = POINTER(c_int)(), c_size_t()"
    a.python_arg = "byref(" + api_name + "), byref(" + api_name_n + ")"
    a.python_return = "_ovectorint(" + api_name + ", " + api_name_n + ".value)"
    a.julia_ctype = "Ptr{Ptr{Cint}}, Ptr{Csize_t}"
    a.julia_pre = (api_name + " = Ref{Ptr{Cint}}()\n    " +
                   api_name_n + " = Ref{Csize_t}()")
    a.julia_arg = api_name + ", " + api_name_n
    a.julia_post = (name + " = unsafe_wrap(Array, " + api_name + "[], " +
                    api_name_n + "[], own=true)")
    return a

def ovectorsize(name, value=None, python_value=None, julia_value=None):
    a = arg(name, value, python_value, julia_value,
            "std::vector<std::size_t> &", "size_t **", True)
    api_name = "api_" + name + "_"
    api_name_n = api_name + "n_"
    a.c_pre = "    std::vector<std::size_t> " + api_name + ";\n"
    a.c_arg = api_name
    a.c_post = "    vector2ptr(" + api_name + ", " + name + ", " + name + "_n);\n"
    a.c = "size_t ** " + name + ", size_t * " + name + "_n"
    a.cwrap_pre = "size_t *" + api_name + "; size_t " + api_name_n + ";\n"
    a.cwrap_arg = "&" + api_name + ", " + "&" + api_name_n
    a.cwrap_post = (name + ".assign(" + api_name + ", " + api_name + " + " +
                    api_name_n + "); " + ns + "Free(" + api_name + ");\n")
    a.python_pre = api_name + ", " + api_name_n + " = POINTER(c_size_t)(), c_size_t()"
    a.python_arg = "byref(" + api_name + "), byref(" + api_name_n + ")"
    a.python_return = "_ovectorsize(" + api_name + ", " + api_name_n + ".value)"
    a.julia_ctype = "Ptr{Ptr{Csize_t}}, Ptr{Csize_t}"
    a.julia_pre = (api_name + " = Ref{Ptr{Csize_t}}()\n    " +
                   api_name_n + " = Ref{Csize_t}()")
    a.julia_arg = api_name + ", " + api_name_n
    a.julia_post = (name + " = unsafe_wrap(Array, " + api_name + "[], " +
                    api_name_n + "[], own=true)")
    return a

def ovectordouble(name, value=None, python_value=None, julia_value=None):
    a = arg(name, value, python_value, julia_value,
            "std::vector<double> &", "double *", True)
    api_name = "api_" + name + "_"
    api_name_n = api_name + "n_"
    a.c_pre = "    std::vector<double> " + api_name + ";\n"
    a.c_arg = api_name
    a.c_post = "    vector2ptr(" + api_name + ", " + name + ", " + name + "_n);\n"
    a.c = "double ** " + name + ", size_t * " + name + "_n"
    a.cwrap_pre = "double *" + api_name + "; size_t " + api_name_n + ";\n"
    a.cwrap_arg = "&" + api_name + ", " + "&" + api_name_n
    a.cwrap_post = (name + ".assign(" + api_name + ", " + api_name + " + " +
                    api_name_n + "); " + ns + "Free(" + api_name + ");\n")
    a.python_pre = api_name + ", " + api_name_n + " = POINTER(c_double)(), c_size_t()"
    a.python_arg = "byref(" + api_name + "), byref(" + api_name_n + ")"
    a.python_return = "_ovectordouble(" + api_name + ", " + api_name_n + ".value)"
    a.julia_ctype = "Ptr{Ptr{Cdouble}}, Ptr{Csize_t}"
    a.julia_pre = (api_name + " = Ref{Ptr{Cdouble}}()\n    " +
                   api_name_n + " = Ref{Csize_t}()")
    a.julia_arg = api_name + ", " + api_name_n
    a.julia_post = (name + " = unsafe_wrap(Array, " + api_name + "[], " +
                    api_name_n + "[], own=true)")
    return a

def ovectorstring(name, value=None, python_value=None, julia_value=None):
    a = arg(name, value, python_value, julia_value,
            "std::vector<std::string> &", "char **", True)
    api_name = "api_" + name + "_"
    api_name_n = api_name + "n_"
    a.c_pre = "    std::vector<std::string> " + api_name + ";\n"
    a.c_arg = api_name
    a.c_post = ("    vectorstring2charptrptr(" + api_name + ", " + name + ", " +
                name + "_n);\n")
    a.c = "char *** " + name + ", size_t * " + name + "_n"
    a.cwrap_pre = "char **" + api_name + "; size_t " + api_name_n + ";\n"
    a.cwrap_arg = "&" + api_name + ", " + "&" + api_name_n
    a.cwrap_post = (name + ".resize(" + api_name_n + "); " +
                    "for(size_t i = 0; i < " + api_name_n + "; ++i){ " +
                    name + "[i] = std::string(" + api_name + "[i]); " +
                    ns + "Free(" + api_name + "[i]); } " +
                    ns + "Free(" + api_name + ");\n")
    a.python_pre = api_name + ", " + api_name_n + " = POINTER(POINTER(c_char))(), c_size_t()"
    a.python_arg = "byref(" + api_name + "), byref(" + api_name_n + ")"
    a.python_return = "_ovectorstring(" + api_name + ", " + api_name_n + ".value)"
    a.julia_ctype = "Ptr{Ptr{Ptr{Cchar}}}, Ptr{Csize_t}"
    a.julia_pre = (api_name + " = Ref{Ptr{Ptr{Cchar}}}()\n    " +
                   api_name_n + " = Ref{Csize_t}()")
    a.julia_arg = api_name + ", " + api_name_n
    a.julia_post = ("tmp_" + api_name + " = unsafe_wrap(Array, " + api_name + "[], " +
                    api_name_n + "[], own=true)\n    " +
                    name + " = [unsafe_string(tmp_" + api_name + "[i]) for i in 1:length(tmp_" +
                    api_name + ") ]")
    return a

def ovectorpair(name, value=None, python_value=None, julia_value=None):
    a = arg(name, value, python_value, julia_value,
            ns + "::vectorpair &", "int **", True)
    api_name = "api_" + name + "_"
    api_name_n = api_name + "n_"
    a.c_pre = "    " + ns + "::vectorpair " + api_name + ";\n"
    a.c_arg = api_name
    a.c_post = "    vectorpair2intptr(" + api_name + ", " + name + ", " + name + "_n);\n"
    a.c = "int ** " + name + ", size_t * " + name + "_n"
    a.cwrap_pre = "int *" + api_name + "; size_t " + api_name_n + ";\n"
    a.cwrap_arg = "&" + api_name + ", " + "&" + api_name_n
    a.cwrap_post = (name + ".resize(" + api_name_n + " / 2); " +
                    "for(size_t i = 0; i < " + api_name_n + " / 2; ++i){ " +
                    name + "[i].first = " + api_name + "[i * 2 + 0]; " +
                    name + "[i].second = " + api_name + "[i * 2 + 1]; } " +
                    ns + "Free(" + api_name + ");\n")
    a.python_pre = api_name + ", " + api_name_n + " = POINTER(c_int)(), c_size_t()"
    a.python_arg = "byref(" + api_name + "), byref(" + api_name_n + ")"
    a.python_return = "_ovectorpair(" + api_name + ", " + api_name_n + ".value)"
    a.julia_ctype = "Ptr{Ptr{Cint}}, Ptr{Csize_t}"
    a.julia_pre = (api_name + " = Ref{Ptr{Cint}}()\n    " +
                   api_name_n + " = Ref{Csize_t}()")
    a.julia_arg = api_name + ", " + api_name_n
    a.julia_post = ("tmp_" + api_name + " = unsafe_wrap(Array, " + api_name + "[], " +
                    api_name_n + "[], own=true)\n    " +
                    name + " = [ (tmp_" + api_name + "[i], tmp_" + api_name + "[i+1]) " +
                    "for i in 1:2:length(tmp_" + api_name + ") ]")
    return a

def ovectorvectorint(name, value=None, python_value=None, julia_value=None):
    a = arg(name, value, python_value, julia_value,
            "std::vector<std::vector<int> > &", "int **", True)
    api_name = "api_" + name + "_"
    api_name_n = api_name + "n_"
    api_name_nn = api_name + "nn_"
    a.c_pre = "    std::vector<std::vector<int> > " + api_name + ";\n"
    a.c_arg = api_name
    a.c_post = ("    vectorvector2ptrptr(" + api_name + ", " + name + ", " +
                name + "_n, " + name + "_nn);\n")
    a.c  = "int *** " + name + ", size_t ** " + name + "_n, size_t *" + name + "_nn"
    a.cwrap_pre = "int **" + api_name + "; size_t *" + api_name_n + ", " + api_name_nn + ";\n"
    a.cwrap_arg = "&" + api_name + ", " + "&" + api_name_n + ", " + "&" + api_name_nn
    a.cwrap_post = (name + ".resize(" + api_name_nn + "); " +
                    "for(size_t i = 0; i < " + api_name_nn + "; ++i){ " +
                    name + "[i].assign(" + api_name + "[i], " + api_name + "[i] + " +
                    api_name_n + "[i]); " + ns + "Free(" + api_name + "[i]); } " +
                    ns + "Free(" + api_name + "); " + ns + "Free(" + api_name_n + ");\n")
    a.python_pre = (api_name + ", " + api_name_n + ", " + api_name_nn +
                    " = POINTER(POINTER(c_int))(), POINTER(c_size_t)(), c_size_t()")
    a.python_arg = ("byref(" + api_name + "), byref(" + api_name_n + "), byref(" +
                    api_name_nn + ")")
    a.python_return = ("_ovectorvectorint(" + api_name + ", " + api_name_n + ", " +
                       api_name_nn + ")")
    a.julia_ctype = "Ptr{Ptr{Ptr{Cint}}}, Ptr{Ptr{Csize_t}}, Ptr{Csize_t}"
    a.julia_pre = (api_name + " = Ref{Ptr{Ptr{Cint}}}()\n    " +
                   api_name_n + " = Ref{Ptr{Csize_t}}()\n    " +
                   api_name_nn + " = Ref{Csize_t}()")
    a.julia_arg = api_name + ", " + api_name_n + ", " + api_name_nn
    a.julia_post = ("tmp_" + api_name + " = unsafe_wrap(Array, " + api_name + "[], " +
                    api_name_nn + "[], own=true)\n    " +
                    "tmp_" + api_name_n + " = unsafe_wrap(Array, " + api_name_n + "[], " +
                    api_name_nn + "[], own=true)\n    " +
                    name + " = [ unsafe_wrap(Array, tmp_" + api_name + "[i], " +
                    "tmp_" + api_name_n + "[i], own=true) for i in 1:" +
                    api_name_nn + "[] ]")
    return a

def ovectorvectorsize(name, value=None, python_value=None, julia_value=None):
    a = arg(name, value, python_value, julia_value,
            "std::vector<std::vector<std::size_t> > &", "size_t **", True)
    api_name = "api_" + name + "_"
    api_name_n = api_name + "n_"
    api_name_nn = api_name + "nn_"
    a.c_pre = "    std::vector<std::vector<std::size_t> > " + api_name + ";\n"
    a.c_arg = api_name
    a.c_post = ("    vectorvector2ptrptr(" + api_name + ", " + name + ", " +
                name + "_n, " + name + "_nn);\n")
    a.c  = "size_t *** " + name + ", size_t ** " + name + "_n, size_t *" + name + "_nn"
    a.cwrap_pre = "size_t **" + api_name + "; size_t *" + api_name_n + ", " + api_name_nn + ";\n"
    a.cwrap_arg = "&" + api_name + ", " + "&" + api_name_n + ", " + "&" + api_name_nn
    a.cwrap_post = (name + ".resize(" + api_name_nn + "); " +
                    "for(size_t i = 0; i < " + api_name_nn + "; ++i){ " +
                    name + "[i].assign(" + api_name + "[i], " + api_name + "[i] + " +
                    api_name_n + "[i]); " + ns + "Free(" + api_name + "[i]); } " +
                    ns + "Free(" + api_name + "); " + ns + "Free(" + api_name_n + ");\n")
    a.python_pre = (api_name + ", " + api_name_n + ", " + api_name_nn +
                    " = POINTER(POINTER(c_size_t))(), POINTER(c_size_t)(), c_size_t()")
    a.python_arg = ("byref(" + api_name + "), byref(" + api_name_n + "), byref(" +
                    api_name_nn + ")")
    a.python_return = ("_ovectorvectorsize(" + api_name + ", " + api_name_n + ", " +
                       api_name_nn + ")")
    a.julia_ctype = "Ptr{Ptr{Ptr{Csize_t}}}, Ptr{Ptr{Csize_t}}, Ptr{Csize_t}"
    a.julia_pre = (api_name + " = Ref{Ptr{Ptr{Csize_t}}}()\n    " +
                   api_name_n + " = Ref{Ptr{Csize_t}}()\n    " +
                   api_name_nn + " = Ref{Csize_t}()")
    a.julia_arg = api_name + ", " + api_name_n + ", " + api_name_nn
    a.julia_post = ("tmp_" + api_name + " = unsafe_wrap(Array, " + api_name + "[], " +
                    api_name_nn + "[], own=true)\n    " +
                    "tmp_" + api_name_n + " = unsafe_wrap(Array, " + api_name_n + "[], " +
                    api_name_nn + "[], own=true)\n    " +
                    name + " = [ unsafe_wrap(Array, tmp_" + api_name + "[i], " +
                    "tmp_" + api_name_n + "[i], own=true) for i in 1:" +
                    api_name_nn + "[] ]")
    return a

def ovectorvectordouble(name, value=None, python_value=None, julia_value=None):
    a = arg(name, value, python_value, julia_value,
            "std::vector<std::vector<double> > &", "double **", True)
    api_name = "api_" + name + "_"
    api_name_n = api_name + "n_"
    api_name_nn = api_name + "nn_"
    a.c_pre = "    std::vector<std::vector<double> > " + api_name + ";\n"
    a.c_arg = api_name
    a.c_post = ("    vectorvector2ptrptr(" + api_name + ", " + name + ", " + name +
                "_n, " + name + "_nn);\n")
    a.c  = "double *** " + name + ", size_t ** " + name + "_n, size_t *" + name + "_nn"
    a.cwrap_pre = ("double **" + api_name + "; size_t *" + api_name_n + ", " +
                   api_name_nn + ";\n")
    a.cwrap_arg = "&" + api_name + ", " + "&" + api_name_n + ", " + "&" + api_name_nn
    a.cwrap_post = (name + ".resize(" + api_name_nn + "); " +
                    "for(size_t i = 0; i < " + api_name_nn + "; ++i){ " +
                    name + "[i].assign(" + api_name + "[i], " + api_name + "[i] + " +
                    api_name_n + "[i]); " + ns + "Free(" + api_name + "[i]); } " +
                    ns + "Free(" + api_name + "); " + ns + "Free(" + api_name_n + ");\n")
    a.python_pre = (api_name + ", " + api_name_n + ", " + api_name_nn +
                    " = POINTER(POINTER(c_double))(), POINTER(c_size_t)(), c_size_t()")
    a.python_arg = ("byref(" + api_name + "), byref(" + api_name_n + "), byref(" +
                    api_name_nn + ")")
    a.python_return = ("_ovectorvectordouble(" + api_name + ", " + api_name_n + ", " +
                       api_name_nn + ")")
    a.julia_ctype = "Ptr{Ptr{Ptr{Cdouble}}}, Ptr{Ptr{Csize_t}}, Ptr{Csize_t}"
    a.julia_pre = (api_name + " = Ref{Ptr{Ptr{Cdouble}}}()\n    " +
                   api_name_n + " = Ref{Ptr{Csize_t}}()\n    " +
                   api_name_nn + " = Ref{Csize_t}()")
    a.julia_arg = api_name + ", " + api_name_n + ", " + api_name_nn
    a.julia_post = ("tmp_" + api_name + " = unsafe_wrap(Array, " + api_name + "[], " +
                    api_name_nn + "[], own=true)\n    " +
                    "tmp_" + api_name_n + " = unsafe_wrap(Array, " + api_name_n + "[], " +
                    api_name_nn + "[], own=true)\n    " +
                    name + " = [ unsafe_wrap(Array, tmp_" + api_name + "[i], " +
                    "tmp_" + api_name_n + "[i], own=true) for i in 1:" +
                    api_name_nn + "[] ]")
    return a

def ovectorvectorpair(name, value=None, python_value=None, julia_value=None):
    a = arg(name, value, python_value, julia_value,
            "std::vector<" + ns + "::vectorpair> &", "int **", True)
    api_name = "api_" + name + "_"
    api_name_n = api_name + "n_"
    api_name_nn = api_name + "nn_"
    a.c_pre = "    std::vector<" + ns + "::vectorpair >" + api_name + ";\n"
    a.c_arg = api_name
    a.c_post = ("    vectorvectorpair2intptrptr(" + api_name + ", " + name +
                ", " + name + "_n, " + name + "_nn);\n")
    a.c = "int *** " + name + ", size_t ** " + name + "_n, size_t *" + name + "_nn"
    a.cwrap_pre = "int **" + api_name + "; size_t *" + api_name_n + ", " + api_name_nn + ";\n"
    a.cwrap_arg = "&" + api_name + ", " + "&" + api_name_n + ", " + "&" + api_name_nn
    a.cwrap_post = (name + ".resize(" + api_name_nn + "); " +
                    "for(size_t i = 0; i < " + api_name_nn + "; ++i){ " +
                    name + "[i].resize(" + api_name_n + "[i] / 2); " +
                    "for(size_t j = 0; j < " + api_name_n + "[i] / 2; ++j){ " +
                    name + "[i][j].first = " + api_name + "[i][j * 2 + 0]; " +
                    name + "[i][j].second = " + api_name + "[i][j * 2 + 1]; } " +
                    ns + "Free(" + api_name + "[i]); } " +
                    ns + "Free(" + api_name + "); " + ns + "Free(" + api_name_n + ");\n")
    a.python_pre = (api_name + ", " + api_name_n + ", " + api_name_nn +
                    " = POINTER(POINTER(c_int))(), POINTER(c_size_t)(), c_size_t()")
    a.python_arg = ("byref(" + api_name + "), byref(" + api_name_n + "), byref(" +
                    api_name_nn + ")")
    a.python_return = ("_ovectorvectorpair(" + api_name + ", " + api_name_n + ", " +
                       api_name_nn + ")")
    a.julia_ctype = "Ptr{Ptr{Ptr{Cint}}}, Ptr{Ptr{Csize_t}}, Ptr{Csize_t}"
    a.julia_pre = (api_name + " = Ref{Ptr{Ptr{Cint}}}()\n    " +
                   api_name_n + " = Ref{Ptr{Csize_t}}()\n    " +
                   api_name_nn + " = Ref{Csize_t}()")
    a.julia_arg = api_name + ", " + api_name_n + ", " + api_name_nn
    a.julia_post = ("tmp_" + api_name + " = unsafe_wrap(Array, " + api_name + "[], " +
                    api_name_nn + "[], own=true)\n    " +
                    "tmp_" + api_name_n + " = unsafe_wrap(Array, " + api_name_n + "[], " +
                    api_name_nn + "[], own=true)\n    " +
                    name + " = Vector{Tuple{Cint,Cint}}[]\n    " +
                    "resize!(" + name + ", " + api_name_nn + "[])\n    " +
                    "for i in 1:" + api_name_nn + "[]\n    " +
                    "    tmp = unsafe_wrap(Array, tmp_" + api_name + "[i], tmp_" +
                    api_name_n + "[i], own=true)\n    " +
                    "    " + name + "[i] = [(tmp[i], tmp[i+1]) for i in 1:2:length(tmp)]\n    " +
                    "end")
    return a

def argcargv():
    a = arg("", None, None, None, "", "", False)
    a.cpp = "int argc = 0, char ** argv = 0"
    a.c_arg = "argc, argv"
    a.c = "int argc, char ** argv"
    a.c_pre = ""
    a.c_post = ""
    a.cwrap_arg = "argc, argv"
    a.name = "argv"
    a.python_value = "[]"
    a.julia_value = "Vector{String}()"
    a.python_arg = "api_argc_, api_argv_"
    a.python_pre = "api_argc_, api_argv_ = _iargcargv(argv)"
    a.julia_ctype = "Cint, Ptr{Ptr{Cchar}}"
    a.julia_arg = "length(argv), argv"
    return a

class Module:

    def __init__(self, name, doc):
        self.name = name
        self.doc = doc
        self.fs = []
        self.submodules = []

    def add(self, name, doc, rtype, *args):
        self.fs.append((rtype, name, args, doc, []))

    def add_special(self, name, doc, special, rtype, *args):
        self.fs.append((rtype, name, args, doc, special))

    def add_module(self, name, doc):
        module = Module(name, doc)
        self.submodules.append(module)
        return module


cpp_header="""// {0}
//
// See the LICENSE.txt file for license information. Please report all
// issues on {1}

#ifndef {2}_H
#define {2}_H

// This file defines the {3} C++ API (v{4}.{5}).
//
// Do not edit it directly: it is automatically generated by `api/gen.py'.
//
// By design, the {3} C++ API is purely functional, and only uses elementary
// types from the standard library. See `demos/api' for examples.

#if defined(_MSC_VER) && !defined(_USE_MATH_DEFINES)
#define _USE_MATH_DEFINES
#endif

#include <cmath>
#include <vector>
#include <string>
#include <utility>

#define {2}_API_VERSION "{4}.{5}"
#define {2}_API_VERSION_MAJOR {4}
#define {2}_API_VERSION_MINOR {5}

#if defined({2}_DLL)
#if defined({2}_DLL_EXPORT)
#define {2}_API __declspec(dllexport)
#else
#define {2}_API __declspec(dllimport)
#endif
#else
#define {2}_API
#endif

namespace {6} {{

  // A geometrical entity in the {3} API is represented by two integers: its
  // dimension (dim = 0, 1, 2 or 3) and its tag (its unique, strictly positive
  // identifier). When dealing with multiple geometrical entities of possibly
  // different dimensions, the entities are packed as a vector of (dim, tag)
  // integer pairs.
  typedef std::vector<std::pair<int, int> > vectorpair;

}}

"""

cpp_footer="""#endif
"""

c_header="""/*
 * {0}
 *
 * See the LICENSE.txt file for license information. Please report all
 * issues on {1}
 */

#ifndef {2}C_H
#define {2}C_H

/*
 * This file defines the {3} C API (v{4}.{5}).
 *
 * Do not edit it directly: it is automatically generated by `api/gen.py'.
 *
 * By design, the {3} C API is purely functional, and only uses elementary
 * types. See `demos/api' for examples.
 */

#include <stddef.h>

#define {2}_API_VERSION "{4}.{5}"
#define {2}_API_VERSION_MAJOR {4}
#define {2}_API_VERSION_MINOR {5}

#if defined({2}_DLL)
#if defined({2}_DLL_EXPORT)
#define {2}_API __declspec(dllexport)
#else
#define {2}_API __declspec(dllimport)
#endif
#else
#define {2}_API
#endif

{2}_API void {6}Free(void *p);
{2}_API void *{6}Malloc(size_t n);
"""

c_footer="""
#endif
"""

c_cpp_header="""// {0}
//
// See the LICENSE.txt file for license information. Please report all
// issues on {1}

#include <string.h>
#include <stdlib.h>
#include "{2}.h"

extern \"C\" {{
  #include "{2}c.h"
}}

{3}_API void *{2}Malloc(size_t n)
{{
  return malloc(n);
}}

{3}_API void {2}Free(void *p)
{{
  if(p) free(p);
}}
"""

c_cpp_utils="""
void vectorvectorpair2intptrptr(const std::vector<{0}::vectorpair > &v, int ***p, size_t **size, size_t *sizeSize)
{{
  *p = (int**){0}Malloc(sizeof(int*) * v.size());
  *size = (size_t*){0}Malloc(sizeof(size_t) * v.size());
  for(size_t i = 0; i < v.size(); ++i)
    vectorpair2intptr(v[i], &(*p)[i], &((*size)[i]));
  *sizeSize = v.size();
}}
"""

cwrap_header="""// {0}
//
// See the LICENSE.txt file for license information. Please report all
// issues on {1}

#ifndef {2}_H
#define {2}_H

// This file redefines the {3} C++ API in terms of the C API (v{4}.{5}).
//
// This is provided as a convenience for users of the binary {3} SDK whose C++
// compiler ABI is not compatible with the ABI of the C++ compiler used to create
// the SDK (and who can thus not directly use the C++ API defined in `{6}.h').
//
// To use this header file in your C++ code, simply rename it as `{6}.h'.
//
// Note that using this header file will lead to (slightly) reduced performance
// compared to using the native {3} C++ API from the original `{6}.h', as it
// entails additional data copies between this C++ wrapper, the C API and the
// native C++ code.
//
// Do not edit this file directly: it is automatically generated by `api/gen.py'.

#if defined(_MSC_VER) && !defined(_USE_MATH_DEFINES)
#define _USE_MATH_DEFINES
#endif

#include <cmath>
#include <vector>
#include <string>
#include <utility>
#include <string.h>

extern \"C\" {{
  #include "{6}c.h"
}}

namespace {6} {{

  // A geometrical entity in the {3} API is represented by two integers: its
  // dimension (dim = 0, 1, 2 or 3) and its tag (its unique, strictly positive
  // identifier). When dealing with multiple geometrical entities of possibly
  // different dimensions, the entities are packed as a vector of (dim, tag)
  // integer pairs.
  typedef std::vector<std::pair<int, int> > vectorpair;

}}

"""

cwrap_utils="""
template<typename t>
{1}void vector2ptr(const std::vector<t> &v, t **p, size_t *size)
{{
  *p = (t*){0}Malloc(sizeof(t) * v.size());
  for(size_t i = 0; i < v.size(); ++i){{
    (*p)[i] = v[i];
  }}
  *size = v.size();
}}

{1}void vectorpair2intptr(const {0}::vectorpair &v, int **p, size_t *size)
{{
  *p = (int*){0}Malloc(sizeof(int) * v.size() * 2);
  for(size_t i = 0; i < v.size(); ++i){{
    (*p)[i * 2 + 0] = v[i].first;
    (*p)[i * 2 + 1] = v[i].second;
  }}
  *size = v.size() * 2;
}}

{1}void vectorstring2charptrptr(const std::vector<std::string> &v, char ***p, size_t *size)
{{
  *p = (char**){0}Malloc(sizeof(char*) * v.size());
  for(size_t i = 0; i < v.size(); ++i){{
    (*p)[i] = strdup(v[i].c_str());
  }}
  *size = v.size();
}}

template<typename t>
{1}void vectorvector2ptrptr(const std::vector<std::vector<t> > &v, t ***p, size_t **size, size_t *sizeSize)
{{
  *p = (t**){0}Malloc(sizeof(t*) * v.size());
  *size = (size_t*){0}Malloc(sizeof(size_t) * v.size());
  for(size_t i = 0; i < v.size(); ++i)
    vector2ptr(v[i], &((*p)[i]), &((*size)[i]));
  *sizeSize = v.size();
}}
"""

cwrap_footer="""#endif
"""

python_header = """# {0}
#
# See the LICENSE.txt file for license information. Please report all
# issues on {1}

# This file defines the {2} Python API (v{3}.{4}).
#
# Do not edit it directly: it is automatically generated by `api/gen.py'.
#
# By design, the {2} Python API is purely functional, and only uses elementary
# types (as well as `numpy' arrays if `numpy' is avaiable). See `demos/api' for
# examples.

from ctypes import *
from ctypes.util import find_library
import signal
import os
import platform
from math import pi

{5}_API_VERSION = "{3}.{4}"
{5}_API_VERSION_MAJOR = {3}
{5}_API_VERSION_MINOR = {4}

__version__ = {5}_API_VERSION

signal.signal(signal.SIGINT, signal.SIG_DFL)
libdir = os.path.dirname(os.path.realpath(__file__))
if platform.system() == "Windows":
    libpath = os.path.join(libdir, "{6}-{3}.{4}.dll")
elif platform.system() == "Darwin":
    libpath = os.path.join(libdir, "lib{6}.dylib")
else:
    libpath = os.path.join(libdir, "lib{6}.so")

if not os.path.exists(libpath):
    libpath = find_library("{6}")

lib = CDLL(libpath)

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

# Utility functions, not part of the Gmsh Python API

def _ostring(s):
    sp = s.value.decode("utf-8")
    lib.{6}Free(s)
    return sp

def _ovectorpair(ptr, size):
    v = list((ptr[i * 2], ptr[i * 2 + 1]) for i in range(size//2))
    lib.{6}Free(ptr)
    return v

def _ovectorint(ptr, size):
    if use_numpy:
        v = numpy.ctypeslib.as_array(ptr, (size, ))
        weakreffinalize(v, lib.{6}Free, ptr)
    else:
        v = list(ptr[i] for i in range(size))
        lib.{6}Free(ptr)
    return v

def _ovectorsize(ptr, size):
    if use_numpy:
        v = numpy.ctypeslib.as_array(ptr, (size, ))
        weakreffinalize(v, lib.{6}Free, ptr)
    else:
        v = list(ptr[i] for i in range(size))
        lib.{6}Free(ptr)
    return v

def _ovectordouble(ptr, size):
    if use_numpy:
        v = numpy.ctypeslib.as_array(ptr, (size, ))
        weakreffinalize(v, lib.{6}Free, ptr)
    else:
        v = list(ptr[i] for i in range(size))
        lib.{6}Free(ptr)
    return v

def _ovectorstring(ptr, size):
    v = list(_ostring(cast(ptr[i], c_char_p)) for i in range(size))
    lib.{6}Free(ptr)
    return v

def _ovectorvectorint(ptr, size, n):
    v = [_ovectorint(pointer(ptr[i].contents), size[i]) for i in range(n.value)]
    lib.{6}Free(size)
    lib.{6}Free(ptr)
    return v

def _ovectorvectorsize(ptr, size, n):
    v = [_ovectorsize(pointer(ptr[i].contents), size[i]) for i in range(n.value)]
    lib.{6}Free(size)
    lib.{6}Free(ptr)
    return v

def _ovectorvectordouble(ptr, size, n):
    v = [_ovectordouble(pointer(ptr[i].contents), size[i]) for i in range(n.value)]
    lib.{6}Free(size)
    lib.{6}Free(ptr)
    return v

def _ovectorvectorpair(ptr, size, n):
    v = [_ovectorpair(pointer(ptr[i].contents), size[i]) for i in range(n.value)]
    lib.{6}Free(size)
    lib.{6}Free(ptr)
    return v

def _ivectorint(o):
    if use_numpy:
        return numpy.ascontiguousarray(o, numpy.int32).ctypes, c_size_t(len(o))
    else:
        return (c_int * len(o))(*o), c_size_t(len(o))

def _ivectorsize(o):
    if use_numpy:
        return numpy.ascontiguousarray(o, numpy.uintp).ctypes, c_size_t(len(o))
    else:
        return (c_size_t * len(o))(*o), c_size_t(len(o))

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

def _ivectorstring(o):
    return (c_char_p * len(o))(*(s.encode() for s in o)), c_size_t(len(o))

def _ivectorvectorint(os):
    n = len(os)
    parrays = [_ivectorint(o) for o in os]
    sizes = (c_size_t * n)(*(a[1] for a in parrays))
    arrays = (POINTER(c_int) * n)(*(cast(a[0], POINTER(c_int)) for a in parrays))
    arrays.ref = [a[0] for a in parrays]
    size = c_size_t(n)
    return arrays, sizes, size

def _ivectorvectorsize(os):
    n = len(os)
    parrays = [_ivectorsize(o) for o in os]
    sizes = (c_size_t * n)(*(a[1] for a in parrays))
    arrays = (POINTER(c_size_t) * n)(*(cast(a[0], POINTER(c_size_t)) for a in parrays))
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

def _iargcargv(o):
    return c_int(len(o)), (c_char_p * len(o))(*(s.encode() for s in o))

# Gmsh Python API begins here
"""

julia_header = """# {0}
#
# See the LICENSE.txt file for license information. Please report all
# issues on {1}

# This file defines the {2} Julia API (v{3}.{4}).
#
# Do not edit it directly: it is automatically generated by `api/gen.py'.
#
# By design, the {2} Julia API is purely functional, and only uses elementary
# types. See `demos/api' for examples.
"""

def capi(s): return s[:1].upper() + s[1:]

class API:

    def __init__(self, version_major, version_minor, namespace="gmsh", code="Gmsh",
                 copyright="Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle",
                 issues="https://gitlab.onelab.info/gmsh/gmsh/issues."):
        self.version_major = version_major
        self.version_minor = version_minor
        global ns
        ns = namespace
        self.code = code
        self.copyright = copyright
        self.issues = issues
        self.modules = []

    def add_module(self, name, doc):
        module = Module(name, doc)
        self.modules.append(module)
        return module

    def write_cpp(self):
        def write_module(module, indent):
            f.write(indent + "namespace " + module.name + " { // " +
                    capi(module.doc) + "\n\n")
            indent += "  "
            for rtype, name, args, doc, special in module.fs:
                f.write(indent + "// " + ("\n" + indent + "// ").join(
                    textwrap.wrap(doc, 80-len(indent))) + "\n")
                rt = rtype.rcpp_type if rtype else "void"
                fnameapi = indent + ns.upper() + "_API " + rt + " " + name + "(";
                f.write(fnameapi)
                if args:
                    f.write((",\n" + ' ' * len(fnameapi)).join(a.cpp for a in args))
                f.write(");\n\n")
            for m in module.submodules:
                write_module(m, indent)
            f.write(indent[:-2] + "} // namespace " + module.name + "\n\n")
        with open(ns + ".h", "w") as f:
            f.write(cpp_header.format(self.copyright, self.issues, ns.upper(), self.code,
                                      self.version_major, self.version_minor, ns))
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
            fcwrap.write(indent + "namespace " + module.name + " { // " +
                         capi(module.doc) + "\n\n")
            indent += "  "
            for rtype, name, args, doc, special in module.fs:
                # *c.h
                fname = c_namespace + name[0].upper() + name[1:]
                f.write("\n/* " + "\n * ".join(textwrap.wrap(doc, 75)) + " */\n")
                fnameapi = ns.upper() + "_API " + (rtype.rc_type if rtype else "void") + " " + fname + "("
                f.write(fnameapi
                        + (",\n" + ' ' * len(fnameapi)).join(
                            list((a.c for a in args + (oint("ierr"), ))))
                        + ");\n")
                if "rawc" not in special:
                    # *c.cpp
                    fc.write(ns.upper() + "_API " + (rtype.rc_type if rtype else "void"))
                    fc.write(" " + fname + "(" +
                             ", ".join(list((a.c for a in args + (oint("ierr"), )))) +
                             ")\n{\n")
                    if rtype:
                        fc.write("  " + rtype.rc_type + " result_api_ = 0;\n")
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
                    fc.write("  }\n  catch(int api_ierr_){\n    " +
                             "if(ierr) *ierr = api_ierr_;\n  }\n");
                    if rtype:
                        fc.write("  return result_api_;\n");
                    fc.write("}\n\n")
                # *.h_cwrap
                fcwrap.write(indent + "// " + ("\n" + indent + "// ").join
                             (textwrap.wrap(doc, 80-len(indent))) + "\n")
                rt = rtype.rcpp_type if rtype else "void"
                fnameapi = indent + "inline " + rt + " " + name + "(";
                fcwrap.write(fnameapi)
                if args:
                    fcwrap.write((",\n" + ' ' * len(fnameapi)).join(a.cpp for a in args))
                fcwrap.write(")\n" + indent + "{\n" + indent + "  int ierr = 0;\n")
                for a in args:
                    if a.cwrap_pre:
                        fcwrap.write(indent + "  " + a.cwrap_pre)
                fcwrap.write(indent + "  ")
                if rtype:
                    fcwrap.write(rt + " result_api_ = ")
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
        with open(ns + "c.h", "w") as f:
            with open(ns + "c.cpp", "w") as fc:
                with open(ns + ".h_cwrap", "w") as fcwrap:
                    f.write(c_header.format(self.copyright, self.issues, ns.upper(),
                                            self.code, self.version_major,
                                            self.version_minor, ns))
                    fc.write(c_cpp_header.format(self.copyright, self.issues, ns,
                                                 ns.upper()))
                    fc.write(cwrap_utils.format(ns, ""))
                    fc.write(c_cpp_utils.format(ns))
                    fc.write("\n")
                    fcwrap.write(cwrap_header.format(self.copyright, self.issues,
                                                     ns.upper(), self.code,
                                                     self.version_major,
                                                     self.version_minor, ns))
                    fcwrap.write("namespace " + ns + " {\n")
                    s = cwrap_utils.format(ns, "inline ").split('\n')
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
            (rtype, name, args, doc, special) = fun
            if "onlycc++" in special: return
            iargs = list(a for a in args if not a.out)
            oargs = list(a for a in args if a.out)
            f.write("\n")
            if modulepath != ns:
                f.write(indent + "@staticmethod\n")
            f.write(indent + "def " + name + "("
                   + ", ".join((parg(a) for a in iargs))
                   + "):\n")
            indent += "    "
            f.write(indent + '"""\n')
            f.write(indent + ("\n" + indent).join(textwrap.wrap(doc, 75)) + "\n")
            if rtype or oargs:
                f.write("\n" + indent + "Return " + ", ".join(
                    ([("an " if rtype.rtexi_type == "integer value" else "a ") +
                      rtype.rtexi_type] if rtype else[])
                   + [("`" + a.name + "'") for a in oargs])
               + ".\n")
            f.write(indent + '"""\n')
            for a in args:
                if a.python_pre: f.write(indent + a.python_pre + "\n")
            f.write(indent + "ierr = c_int()\n")
            f.write(indent + "api__result__ = " if ((rtype is oint) or (rtype is odouble)) else (indent))
            c_name = modulepath + name[0].upper() + name[1:]
            f.write("lib." + c_name + "(\n    " + indent +
                    (",\n" + indent + "    ").join(
                        tuple((a.python_arg for a in args)) + ("byref(ierr)", )) +
                    ")\n")
            f.write(indent + "if ierr.value != 0:\n")
            f.write(indent + "    raise ValueError(\n")
            f.write(indent + '        "' + c_name + ' returned non-zero error code: ",\n')
            f.write(indent + "        ierr.value)\n")
            r = (["api__result__"]) if rtype else []
            r += list((o.python_return for o in oargs))
            if len(r) != 0:
                if len(r) == 1:
                    f.write(indent + "return " + r[0] + "\n")
                else:
                    f.write(indent + "return (\n" + indent + "    " +
                            (",\n" + indent + "    ").join(r) + ")\n")
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
                f.write(indentm + ("\n" + indentm).join
                        (textwrap.wrap(capi(module.doc), 75)) + "\n")
                f.write(indentm + '"""\n')
                write_module(f, module, modulepath, indentm)
        with open(ns + ".py", "w") as f:
            f.write(python_header.format(self.copyright, self.issues, self.code,
                                         self.version_major, self.version_minor,
                                         ns.upper(), ns))
            for module in self.modules:
                write_module(f, module, "", "")

    def write_julia(self):
        def parg(a):
            return a.name + ((" = " + a.julia_value) if a.julia_value else "")
        def write_function(f, fun, c_mpath, jl_mpath):
            (rtype, name, args, doc, special) = fun
            if "onlycc++" in special: return
            iargs = list(a for a in args if not a.out)
            oargs = list(a for a in args if a.out)
            f.write('\n"""\n    ')
            f.write(jl_mpath + name + "(" + ", ".join(parg(a) for a in iargs) + ")\n\n")
            f.write("\n".join(textwrap.wrap(doc, 80)).replace("'", "`") + "\n")
            if rtype or oargs:
                f.write("\nReturn " + ", ".join(
                    ([("an " if rtype.rtexi_type == "integer value" else "a ") +
                      rtype.rtexi_type] if rtype else[])
                   + [("`" + a.name + "`") for a in oargs])
               + ".\n")
            f.write('"""\n')
            f.write("function " + name + "("
                   + ", ".join((parg(a) for a in iargs))
                   + ")\n")
            for a in args:
                if a.julia_pre: f.write("    " + a.julia_pre + "\n")
            f.write("    ierr = Ref{Cint}()\n    ")
            f.write("api__result__ = " if ((rtype is oint) or (rtype is odouble)) else "")
            c_name = c_mpath + name[0].upper() + name[1:]
            f.write("ccall((:" + c_name + ", " +
                    ("" if c_mpath == ns else ns + ".") + "lib), " +
                    ("Cvoid" if rtype is None else rtype.rjulia_type) + ",\n" +
                    " " * 10 + "(" + ", ".join(
                        (tuple(a.julia_ctype for a in args) + ("Ptr{Cint}",))) +
                    ("," if not len(args) else "") + "),\n" +
                    " " * 10 + ", ".join(
                        tuple(a.julia_arg for a in args) + ("ierr",)) + ")\n")
            f.write('    ierr[] != 0 && error("' + c_name +
                    ' returned non-zero error code: $(ierr[])")\n')
            for a in args:
                if a.julia_post: f.write("    " + a.julia_post + "\n")
            r = (["api__result__"]) if rtype else []
            r += list((o.julia_return for o in oargs))
            f.write("    return ")
            if len(r) == 0:
                f.write("nothing")
            else:
                f.write(", ".join(r))
            f.write("\nend\n")
        def write_module(f, m, c_mpath, jl_mpath, level):
            f.write('\n"""\n    ')
            f.write("module " + jl_mpath + m.name + "\n\n")
            f.write("\n".join(textwrap.wrap(capi(m.doc), 80)) + "\n")
            f.write('"""\n')
            f.write("module " + m.name + "\n\n")
            if level == 1:
                f.write('const {0}_API_VERSION = "{1}.{2}"\n'.
                        format(ns.upper(), self.version_major, self.version_minor))
                f.write('const {0}_API_VERSION_MAJOR = {1}\n'.
                        format(ns.upper(), self.version_major))
                f.write('const {0}_API_VERSION_MINOR = {1}\n'.
                        format(ns.upper(), self.version_minor))
                f.write('const libdir = dirname(@__FILE__)\n')
                f.write('const libname = Sys.iswindows() ? "' + ns +
                        '-{0}.{1}'.format(self.version_major, self.version_minor) +
                        '" : "lib' + ns + '"\n')
                f.write('import Libdl\n')
                f.write('const lib = Libdl.find_library([libname], [libdir])\n')
            else:
                f.write("import " + ("." * level) + ns + "\n")
            if c_mpath:
                c_mpath += m.name[0].upper() + m.name[1:]
                jl_mpath += m.name + "."
            else:
                c_mpath = m.name
                jl_mpath = m.name + "."
            for fun in m.fs:
                write_function(f, fun, c_mpath, jl_mpath)
            for module in m.submodules:
                write_module(f, module, c_mpath, jl_mpath, level + 1)
            f.write("\nend # end of module " + m.name + "\n")
        with open(ns + ".jl", "w") as f:
            f.write(julia_header.format(self.copyright, self.issues, self.code,
                                        self.version_major, self.version_minor))
            for module in self.modules:
                write_module(f, module, "", "", 1)

    def write_texi(self):
        def write_module(module, path, node, node_next, node_prev):
            f.write("@node " + node + ", " + node_next + ", " + node_prev + ", Gmsh API\n");
            f.write("@section Namespace @code{" + path + "}: " + module.doc + "\n\n");
            f.write("@ftable @code\n");
            for rtype, name, args, doc, special in module.fs:
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
                        (rtype.rtexi_type if rtype else "-") + "\n")
                f.write("@end table\n\n");
            f.write("@end ftable\n\n");
        with open("api.texi", "w") as f:
            f.write("@c This file was generated by api/gen.py: do not edit manually!\n\n")
            def flatten_module(flat, module, path):
                p = path + ("/" if len(path) else "") + module.name
                flat.append((module, p))
                for m in module.submodules:
                    flatten_module(flat, m, p)
            def node_name(n):
                return "Namespace " + n[1]
            flat = []
            for m in self.modules:
                flatten_module(flat, m, "")
            N = len(flat)
            f.write("@menu\n")
            for i in range(N):
                f.write("* " + node_name(flat[i]) + "::\n")
            f.write("@end menu\n\n")
            for i in range(N):
                write_module(flat[i][0], flat[i][1], node_name(flat[i]),
                             "" if i == N - 1 else node_name(flat[i+1]),
                             "" if i == 0 else node_name(flat[i-1]))
