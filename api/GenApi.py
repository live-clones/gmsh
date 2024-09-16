# Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file in the Gmsh root directory for license information.
# Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

# Contributor(s):
#   Jonathan Lambrechts, Giannis Nikiteas

import textwrap
import string
import os
import re

# TODO: Fortran mark all output variables with intent(out)
# TODO: Fortran all methods that return a single value, should be functions not subroutines
class arg:
    def __init__(self, name, value, python_value, julia_value, cpp_type,
                 c_type, out):
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
        self.fortran_args = [name]
        self.fortran_c_args = [name]
        self.fortran_pre = None
        self.fortran_post = None
        self.fortran_call = None
        self.fortran_local = None
        self.texi_type = ""
        self.texi = name + (
            (" = " + self.python_value) if self.python_value else "")


# input types


def ibool(name, value=None, python_value=None, julia_value=None):
    a = arg(name, value, python_value, julia_value, "const bool", "const int",
            False)
    a.python_arg = "c_int(bool(" + name + "))"
    a.cwrap_arg = "(int)" + name
    a.julia_ctype = "Cint"
    a.fortran_types = ["logical, intent(in)"]
    a.fortran_c_api = ["integer(c_int), value, intent(in)"]
    a.fortran_call = f"{name}=optval_c_bool(.{value}., {name})" if value is not None else f"{name}=merge(1_c_int, 0_c_int, {name})"
    a.texi_type = "boolean"
    return a


def iint(name, value=None, python_value=None, julia_value=None):
    a = arg(name, value, python_value, julia_value, "const int", "const int",
            False)
    a.python_arg = "c_int(" + name + ")"
    a.julia_ctype = "Cint"
    a.fortran_types = ["integer, intent(in)"]
    a.fortran_c_api = ["integer(c_int), value, intent(in)"]
    a.fortran_call = f"{name}=optval_c_int({value}, {name})" if value is not None else f"{name}=int({name}, c_int)"
    a.texi_type = "integer"
    return a


def isize(name, value=None, python_value=None, julia_value=None):
    a = arg(name, value, python_value, julia_value, "const std::size_t",
            "const size_t", False)
    a.python_arg = "c_size_t(" + name + ")"
    a.julia_ctype = "Csize_t"
    a.fortran_types = ["integer, intent(in)"]
    a.fortran_c_api = ["integer(c_size_t), value, intent(in)"]
    a.fortran_call = f"{name}=optval_c_size_t({value}, {name})" if value is not None else f"{name}=int({name}, c_size_t)"
    a.texi_type = "size"
    return a


def idouble(name, value=None, python_value=None, julia_value=None):
    a = arg(name, value, python_value, julia_value, "const double",
            "const double", False)
    a.python_arg = "c_double(" + name + ")"
    a.julia_ctype = "Cdouble"
    a.fortran_types = ["real(c_double), intent(in)"]
    a.fortran_c_api = ["real(c_double), value, intent(in)"]
    a.fortran_call = f"{name}=optval_c_double({value}, {name})" if value is not None else f"{name}=real({name}, c_double)"
    a.texi_type = "double"
    return a


def istring(name, value=None, python_value=None, julia_value=None):
    a = arg(name, value, python_value, julia_value, "const std::string &",
            "const char *", False)
    a.python_arg = "c_char_p(" + name + ".encode())"
    a.cwrap_arg = name + ".c_str()"
    a.julia_ctype = "Ptr{Cchar}"
    a.fortran_types = ["character(len=*), intent(in)"]
    a.fortran_c_api = ["character(len=1, kind=c_char), dimension(*), intent(in)"]
    a.fortran_call = f"{name}=istring_(optval_c_str({value}, {name}))" if value is not None else f"{name}=istring_({name})"
    a.texi_type = "string"
    return a


def ivoidstar(name, value=None, python_value=None, julia_value=None):
    a = arg(name, value, python_value, julia_value, "const void *",
            "const void *", False)
    a.python_arg = "c_void_p(" + name + ")"
    a.julia_ctype = "Ptr{Cvoid}"
    a.fortran_types = ["type(c_ptr), intent(in)"]
    a.fortran_c_api = ["type(c_ptr), value, intent(in)"]
    a.texi_type = "pointer"
    return a


def ivectorint(name, value=None, python_value=None, julia_value=None):
    if julia_value == "[]":
        julia_value = "Cint[]"
    a = arg(name, value, python_value, julia_value, "const std::vector<int> &",
            "const int *", False)
    api_name = "api_" + name + "_"
    api_name_n = "api_" + name + "_n_"
    a.c_pre = ("    std::vector<int> " + api_name + "(" + name + ", " + name +
               " + " + name + "_n);\n")
    a.c_arg = api_name
    a.c = "const int * " + name + ", const size_t " + name + "_n"
    a.cwrap_pre = ("int *" + api_name + "; size_t " + api_name_n + "; " +
                   "vector2ptr(" + name + ", &" + api_name + ", &" +
                   api_name_n + ");\n")
    a.cwrap_arg = api_name + ", " + api_name_n
    a.cwrap_post = ns + "Free(" + api_name + ");\n"
    a.python_pre = api_name + ", " + api_name_n + " = _ivectorint(" + name + ")"
    a.python_arg = api_name + ", " + api_name_n
    a.julia_ctype = "Ptr{Cint}, Csize_t"
    a.julia_arg = "convert(Vector{Cint}, " + name + "), length(" + name + ")"
    a.fortran_args = [name]
    a.fortran_types = ["integer(c_int), dimension(:), intent(in)"]
    a.fortran_c_api = ["integer(c_int), dimension(*)", "integer(c_size_t), value, intent(in)"]
    a.fortran_c_args = [api_name, api_name_n]
    a.fortran_call = f"{api_name}={name}, &{api_name_n}=size_gmsh_int({name})"
    a.texi_type = "vector of integers"
    return a


def ivectorsize(name, value=None, python_value=None, julia_value=None):
    if julia_value == "[]":
        julia_value = "Csize_t[]"
    a = arg(name, value, python_value, julia_value,
            "const std::vector<std::size_t> &", "const size_t *", False)
    api_name = "api_" + name + "_"
    api_name_n = "api_" + name + "_n_"
    a.c_pre = ("    std::vector<std::size_t> " + api_name + "(" + name + ", " +
               name + " + " + name + "_n);\n")
    a.c_arg = api_name
    a.c = "const size_t * " + name + ", const size_t " + name + "_n"
    a.cwrap_pre = ("size_t *" + api_name + "; size_t " + api_name_n + "; " +
                   "vector2ptr(" + name + ", &" + api_name + ", &" +
                   api_name_n + ");\n")
    a.cwrap_arg = api_name + ", " + api_name_n
    a.cwrap_post = ns + "Free(" + api_name + ");\n"
    a.python_pre = api_name + ", " + api_name_n + " = _ivectorsize(" + name + ")"
    a.python_arg = api_name + ", " + api_name_n
    a.julia_ctype = "Ptr{Csize_t}, Csize_t"
    a.julia_arg = "convert(Vector{Csize_t}, " + name + "), length(" + name + ")"
    a.fortran_args = [name]
    a.fortran_types = ["integer(c_size_t), dimension(:), intent(in)"]
    a.fortran_c_api = ["integer(c_size_t), dimension(*)", "integer(c_size_t), value, intent(in)"]
    a.fortran_c_args = [api_name, api_name_n]
    a.fortran_call = f"{api_name}={name}, &{api_name_n}=size_gmsh_size({name})"
    a.texi_type = "vector of sizes"
    return a


def ivectordouble(name, value=None, python_value=None, julia_value=None):
    if julia_value == "[]":
        julia_value = "Cdouble[]"
    a = arg(name, value, python_value, julia_value,
            "const std::vector<double> &", "const double * const *", False)
    api_name = "api_" + name + "_"
    api_name_n = "api_" + name + "_n_"
    a.c_pre = ("    std::vector<double> " + api_name + "(" + name + ", " +
               name + " + " + name + "_n);\n")
    a.c_arg = api_name
    a.c = "const double * " + name + ", const size_t " + name + "_n"
    a.cwrap_pre = ("double *" + api_name + "; size_t " + api_name_n + "; " +
                   "vector2ptr(" + name + ", &" + api_name + ", &" +
                   api_name_n + ");\n")
    a.cwrap_arg = api_name + ", " + api_name_n
    a.cwrap_post = ns + "Free(" + api_name + ");\n"
    a.python_pre = api_name + ", " + api_name_n + " = _ivectordouble(" + name + ")"
    a.python_arg = api_name + ", " + api_name_n
    a.julia_ctype = "Ptr{Cdouble}, Csize_t"
    a.julia_arg = "convert(Vector{Cdouble}, " + name + "), length(" + name + ")"
    a.fortran_args = [name]
    a.fortran_types = ["real(c_double), dimension(:), intent(in)"]
    a.fortran_c_api = ["real(c_double), dimension(*)", "integer(c_size_t), value, intent(in)"]
    a.fortran_c_args = [api_name, api_name_n]
    a.fortran_call = f"{api_name}={name}, &{api_name_n}=size_gmsh_double({name})"
    a.texi_type = "vector of doubles"
    return a


def ivectorstring(name, value=None, python_value=None, julia_value=None):
    a = arg(name, value, python_value, julia_value,
            "const std::vector<std::string> &", "const char * const *", False)
    api_name = "api_" + name + "_"
    api_name_n = "api_" + name + "_n_"
    a.c_pre = ("    std::vector<std::string> " + api_name + "(" + name + ", " +
               name + " + " + name + "_n);\n")
    a.c_arg = api_name
    a.c = "const char * const * " + name + ", const size_t " + name + "_n"
    a.cwrap_pre = ("char **" + api_name + "; size_t " + api_name_n + "; " +
                   "vectorstring2charptrptr(" + name + ", &" + api_name +
                   ", &" + api_name_n + ");\n")
    a.cwrap_arg = api_name + ", " + api_name_n
    a.cwrap_post = ("for(size_t i = 0; i < " + api_name_n + "; ++i){ " + ns +
                    "Free(" + api_name + "[i]); } " + ns + "Free(" + api_name +
                    ");\n")
    a.python_pre = api_name + ", " + api_name_n + " = _ivectorstring(" + name + ")"
    a.python_arg = api_name + ", " + api_name_n
    a.julia_ctype = "Ptr{Ptr{Cchar}}, Csize_t"
    a.julia_arg = name + ", length(" + name + ")"
    a.fortran_args = [name]
    a.fortran_types = ["character(len=*), dimension(:), intent(in)"]
    a.fortran_c_api = ["type(c_ptr), dimension(*)", "integer(c_size_t), value, intent(in)"]
    a.fortran_c_args = [api_name, api_name_n]
    # pass the locally created api_name variable to the C interface
    a.fortran_call = f"{api_name}={api_name}, &{api_name_n}=size_gmsh_str({name})"
    a.fortran_pre = f"call ivectorstring_({name}, &{api_name}strs, &{api_name})"
    a.fortran_local = [f"character(len=GMSH_API_MAX_STR_LEN, kind=c_char), allocatable :: {api_name}strs(:)",
                       f"type(c_ptr), allocatable :: {api_name}(:)"]
    a.texi_type = "vector of strings"
    return a


def ivectorpair(name, value=None, python_value=None, julia_value=None):
    if julia_value == "[]":
        julia_value = "Tuple{Cint,Cint}[]"
    a = arg(name, value, python_value, julia_value,
            "const " + ns + "::vectorpair &", "const int *", False)
    api_name = "api_" + name + "_"
    api_name_n = "api_" + name + "_n_"
    a.c_pre = ("    " + ns + "::vectorpair " + api_name + "(" + name +
               "_n/2);\n" + "    for(size_t i = 0; i < " + name +
               "_n/2; ++i){\n" + "      " + api_name + "[i].first = " + name +
               "[i * 2 + 0];\n" + "      " + api_name + "[i].second = " +
               name + "[i * 2 + 1];\n" + "    }\n")
    a.c_arg = api_name
    a.c = "const int * " + name + ", const size_t " + name + "_n"
    a.cwrap_pre = ("int *" + api_name + "; size_t " + api_name_n + "; " +
                   "vectorpair2intptr(" + name + ", &" + api_name + ", &" +
                   api_name_n + ");\n")
    a.cwrap_arg = api_name + ", " + api_name_n
    a.cwrap_post = ns + "Free(" + api_name + ");\n"
    a.python_pre = api_name + ", " + api_name_n + " = _ivectorpair(" + name + ")"
    a.python_arg = api_name + ", " + api_name_n
    a.julia_ctype = "Ptr{Cint}, Csize_t"
    a.julia_pre = (api_name + " = collect(Cint, Iterators.flatten(" + name +
                   "))\n    " + api_name_n + " = length(" + api_name + ")")
    a.julia_arg = (api_name + ", " + api_name_n)
    a.fortran_args = [name]
    a.fortran_types = ["integer(c_int), dimension(:,:), intent(in)"]
    a.fortran_c_api = ["integer(c_int), dimension(*)", "integer(c_size_t), value, intent(in)"]
    a.fortran_c_args = [api_name, api_name_n]
    a.fortran_call = f"{api_name}={name}, &{api_name_n}=size_gmsh_pair({name})"
    a.texi_type = "vector of pairs of integers"
    return a


def ivectorvectorint(name, value=None, python_value=None, julia_value=None):
    if julia_value == "[]":
        julia_value = "Vector{Cint}[]"
    a = arg(name, value, python_value, julia_value,
            "const std::vector<std::vector<int> > &", "const int * const *", False)
    api_name = "api_" + name + "_"
    api_name_n = "api_" + name + "_n_"
    api_name_nn = "api_" + name + "_nn_"
    a.c_pre = ("    std::vector<std::vector<int> > " + api_name + "(" + name +
               "_nn);\n" + "    for(size_t i = 0; i < " + name +
               "_nn; ++i)\n" + "      " + api_name +
               "[i] = std::vector<int>(" + name + "[i], " + name + "[i] + " +
               name + "_n[i]);\n")
    a.c_arg = api_name
    a.c = ("const int * const * " + name + ", const size_t * " + name + "_n, " +
           "const size_t " + name + "_nn")
    a.cwrap_pre = ("int **" + api_name + "; size_t *" + api_name_n + ", " +
                   api_name_nn + "; " + "vectorvector2ptrptr(" + name + ", &" +
                   api_name + ", &" + api_name_n + ", &" + api_name_nn +
                   ");\n")
    a.cwrap_arg = api_name + ", " + api_name_n + ", " + api_name_nn
    a.cwrap_post = ("for(size_t i = 0; i < " + api_name_nn + "; ++i){ " + ns +
                    "Free(" + api_name + "[i]); } " + ns + "Free(" + api_name +
                    "); " + ns + "Free(" + api_name_n + ");\n")
    a.python_pre = (api_name + ", " + api_name_n + ", " + api_name_nn +
                    " = _ivectorvectorint(" + name + ")")
    a.python_arg = api_name + ", " + api_name_n + ", " + api_name_nn
    a.julia_ctype = "Ptr{Ptr{Cint}}, Ptr{Csize_t}, Csize_t"
    a.julia_pre = (api_name_n + " = [ length(" + name +
                   "[i]) for i in 1:length(" + name + ") ]")
    a.julia_arg = ("convert(Vector{Vector{Cint}}," + name + "), " +
                   api_name_n + ", length(" + name + ")")
    a.fortran_args = [name, name + "_n"]
    a.fortran_types = ["integer(c_int), dimension(:), intent(in)", "integer(c_size_t), dimension(:), intent(in)"]
    a.fortran_c_api = ["type(c_ptr), intent(in)", "type(c_ptr), intent(in)", "integer(c_size_t), value, intent(in)"]
    a.fortran_c_args = [api_name, api_name_n, api_name_nn]
    a.fortran_pre = f"call ivectorvectorint_({name}, &{name}_n, &{api_name}, &{api_name_n}, &{api_name_nn})"
    a.fortran_local = [f"type(c_ptr) :: {api_name}", f"type(c_ptr) :: {api_name_n}", f"integer(c_size_t) :: {api_name_nn}"]
    a.fortran_call = f"{api_name}={api_name}, &{api_name_n}={api_name_n}, &{api_name_nn}={api_name_nn}"
    a.texi_type = "vector of vectors of integers"
    return a


def ivectorvectorsize(name, value=None, python_value=None, julia_value=None):
    if julia_value == "[]":
        julia_value = "Vector{Csize_t}[]"
    a = arg(name, value, python_value, julia_value,
            "const std::vector<std::vector<std::size_t> > &",
            "const size_t * const *", False)
    api_name = "api_" + name + "_"
    api_name_n = "api_" + name + "_n_"
    api_name_nn = "api_" + name + "_nn_"
    a.c_pre = ("    std::vector<std::vector<std::size_t> > " + api_name + "(" +
               name + "_nn);\n" + "    for(size_t i = 0; i < " + name +
               "_nn; ++i)\n" + "      " + api_name +
               "[i] = std::vector<std::size_t>(" + name + "[i], " + name +
               "[i] + " + name + "_n[i]);\n")
    a.c_arg = api_name
    a.c = ("const size_t * const * " + name + ", const size_t * " + name + "_n, " +
           "const size_t " + name + "_nn")
    a.cwrap_pre = ("size_t **" + api_name + "; size_t *" + api_name_n + ", " +
                   api_name_nn + "; " + "vectorvector2ptrptr(" + name + ", &" +
                   api_name + ", &" + api_name_n + ", &" + api_name_nn +
                   ");\n")
    a.cwrap_arg = api_name + ", " + api_name_n + ", " + api_name_nn
    a.cwrap_post = ("for(size_t i = 0; i < " + api_name_nn + "; ++i){ " + ns +
                    "Free(" + api_name + "[i]); } " + ns + "Free(" + api_name +
                    "); " + ns + "Free(" + api_name_n + ");\n")
    a.python_pre = (api_name + ", " + api_name_n + ", " + api_name_nn +
                    " = _ivectorvectorsize(" + name + ")")
    a.python_arg = api_name + ", " + api_name_n + ", " + api_name_nn
    a.julia_ctype = "Ptr{Ptr{Csize_t}}, Ptr{Csize_t}, Csize_t"
    a.julia_pre = (api_name_n + " = [ length(" + name +
                   "[i]) for i in 1:length(" + name + ") ]")
    a.julia_arg = ("convert(Vector{Vector{Csize_t}}," + name + "), " +
                   api_name_n + ", length(" + name + ")")
    a.fortran_args = [name, name + "_n"]
    a.fortran_types = ["integer(c_size_t), dimension(:), intent(in)", "integer(c_size_t), dimension(:), intent(in)"]
    a.fortran_c_api = ["type(c_ptr), intent(in)", "type(c_ptr), intent(in)", "integer(c_size_t), value, intent(in)"]
    a.fortran_c_args = [api_name, api_name_n, api_name_nn]
    a.fortran_pre = f"call ivectorvectorsize_({name}, &{name}_n, &{api_name}, &{api_name_n}, &{api_name_nn})"
    a.fortran_local = [f"type(c_ptr) :: {api_name}", f"type(c_ptr) :: {api_name_n}", f"integer(c_size_t) :: {api_name_nn}"]
    a.fortran_call = f"{api_name}={api_name}, &{api_name_n}={api_name_n}, &{api_name_nn}={api_name_nn}"
    a.texi_type = "vector of vectors of integers (size)"
    return a


def ivectorvectordouble(name, value=None, python_value=None, julia_value=None):
    if julia_value == "[]":
        julia_value = "Vector{Cdouble}[]"
    a = arg(name, value, python_value, julia_value,
            "const std::vector<std::vector<double> > &", "const double * const *",
            False)
    api_name = "api_" + name + "_"
    api_name_n = "api_" + name + "_n_"
    api_name_nn = "api_" + name + "_nn_"
    a.c_pre = ("    std::vector<std::vector<double> > " + api_name + "(" +
               name + "_nn);\n" + "    for(size_t i = 0; i < " + name +
               "_nn; ++i)\n" + "      " + api_name +
               "[i] = std::vector<double>(" + name + "[i], " + name +
               "[i] + " + name + "_n[i]);\n")
    a.c_arg = api_name
    a.c = ("const double * const * " + name + ", const size_t * " + name + "_n, " +
           "const size_t " + name + "_nn")
    a.cwrap_pre = ("double **" + api_name + "; size_t *" + api_name_n + ", " +
                   api_name_nn + "; " + "vectorvector2ptrptr(" + name + ", &" +
                   api_name + ", &" + api_name_n + ", &" + api_name_nn +
                   ");\n")
    a.cwrap_arg = api_name + ", " + api_name_n + ", " + api_name_nn
    a.cwrap_post = ("for(size_t i = 0; i < " + api_name_nn + "; ++i){ " + ns +
                    "Free(" + api_name + "[i]); } " + ns + "Free(" + api_name +
                    "); " + ns + "Free(" + api_name_n + ");\n")
    a.python_pre = (api_name + ", " + api_name_n + ", " + api_name_nn +
                    " = _ivectorvectordouble(" + name + ")")
    a.python_arg = api_name + ", " + api_name_n + ", " + api_name_nn
    a.julia_ctype = "Ptr{Ptr{Cdouble}}, Ptr{Csize_t}, Csize_t"
    a.julia_pre = (api_name_n + " = [ length(" + name +
                   "[i]) for i in 1:length(" + name + ") ]")
    a.julia_arg = ("convert(Vector{Vector{Cdouble}}," + name + "), " +
                   api_name_n + ", length(" + name + ")")
    a.fortran_args = [name, name + "_n"]
    a.fortran_types = ["real(c_double), dimension(:), intent(in)", "integer(c_size_t), dimension(:), intent(in)"]
    a.fortran_c_api = ["type(c_ptr), intent(in)", "type(c_ptr), intent(in)", "integer(c_size_t), value, intent(in)"]
    a.fortran_c_args = [api_name, api_name_n, api_name_nn]
    a.fortran_pre = f"call ivectorvectordouble_({name}, &{name}_n, &{api_name}, &{api_name_n}, &{api_name_nn})"
    a.fortran_local = [f"type(c_ptr) :: {api_name}", f"type(c_ptr) :: {api_name_n}", f"integer(c_size_t) :: {api_name_nn}"]
    a.fortran_call = f"{api_name}={api_name}, &{api_name_n}={api_name_n}, &{api_name_nn}={api_name_nn}"
    a.texi_type = "vector of vectors of doubles"
    return a


# output types

class oint(arg):
    rcpp_type = "int"
    rc_type = "int"
    rjulia_type = "Cint"
    fortran_c_api = ["integer(c_int)"]
    fortran_types = ["integer(c_int)"]
    texi_type = "integer"

    def __init__(self, name, value=None, python_value=None, julia_value=None):
        arg.__init__(self, name, value, python_value, julia_value, "int &",
                     "int *", True)
        api_name = "api_" + name + "_"
        self.texi_type = "integer"
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
    rjulia_type = "Csize_t"
    fortran_c_api = ["integer(c_size_t)"]
    fortran_types = ["integer(c_size_t)"]
    texi_type = "size"

    def __init__(self, name, value=None, python_value=None, julia_value=None):
        arg.__init__(self, name, value, python_value, julia_value,
                     "std::size_t &", "size_t *", True)
        api_name = "api_" + name + "_"
        self.texi_type = "size"
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
    rjulia_type = "Cdouble"
    fortran_c_api = ["real(c_double)"]
    fortran_types = ["real(c_double)"]
    texi_type = "double"

    def __init__(self, name, value=None, python_value=None, julia_value=None):
        arg.__init__(self, name, value, python_value, julia_value, "double &",
                     "double *", True)
        api_name = "api_" + name + "_"
        self.texi_type = "double"
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
    a = arg(name, value, python_value, julia_value, "std::string &", "char **",
            True)
    api_name = "api_" + name + "_"
    a.c_pre = "    std::string " + api_name + ";\n"
    a.c_arg = api_name
    a.c_post = "    *" + name + " = strdup(" + api_name + ".c_str());\n"
    a.cwrap_pre = "char *" + api_name + ";\n"
    a.cwrap_arg = "&" + api_name
    a.cwrap_post = (name + " = std::string(" + api_name + "); " + ns +
                    "Free(" + api_name + ");\n")
    a.python_pre = api_name + " = c_char_p()"
    a.python_arg = "byref(" + api_name + ")"
    a.python_return = "_ostring(" + api_name + ")"
    a.julia_ctype = "Ptr{Ptr{Cchar}}"
    a.julia_pre = api_name + " = Ref{Ptr{Cchar}}()"
    a.julia_arg = api_name
    a.julia_post = name + " = unsafe_string(" + api_name + "[])"
    a.fortran_args = [name]
    a.fortran_types = ["character(len=:), allocatable, intent(out)"]
    a.fortran_c_api = ["type(c_ptr), intent(out)"]
    a.fortran_c_args = [api_name]
    a.fortran_call = f"{api_name}={api_name}"
    a.fortran_post = f"{name} = ostring_({api_name})"
    a.fortran_local = [f"type(c_ptr) :: {api_name}"]
    a.texi_type = "string"
    return a


def ovectorint(name, value=None, python_value=None, julia_value=None):
    a = arg(name, value, python_value, julia_value, "std::vector<int> &",
            "int **", True)
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
    a.julia_pre = (api_name + " = Ref{Ptr{Cint}}()\n    " + api_name_n +
                   " = Ref{Csize_t}()")
    a.julia_arg = api_name + ", " + api_name_n
    a.julia_post = (name + " = unsafe_wrap(Array, " + api_name + "[], " +
                    api_name_n + "[], own = true)")
    a.fortran_args = [name]
    a.fortran_types = ["integer(c_int), dimension(:), allocatable, intent(out)"]
    a.fortran_c_api = ["type(c_ptr), intent(out)", "integer(c_size_t), intent(out)"]
    a.fortran_c_args = [api_name, api_name_n]
    a.fortran_call = f"{api_name}={api_name}, &{api_name_n}={api_name_n}"
    a.fortran_post = f"{name} = ovectorint_({api_name}, &{api_name_n})"
    a.fortran_local = [f"type(c_ptr) :: {api_name}", f"integer(c_size_t) :: {api_name_n}"]
    a.texi_type = "vector of integers"
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
    a.julia_pre = (api_name + " = Ref{Ptr{Csize_t}}()\n    " + api_name_n +
                   " = Ref{Csize_t}()")
    a.julia_arg = api_name + ", " + api_name_n
    a.julia_post = (name + " = unsafe_wrap(Array, " + api_name + "[], " +
                    api_name_n + "[], own = true)")
    a.fortran_args = [name]
    a.fortran_types = ["integer(c_size_t), dimension(:), allocatable, intent(out)"]
    a.fortran_c_api = ["type(c_ptr), intent(out)", "integer(c_size_t), intent(out)"]
    a.fortran_c_args = [api_name, api_name_n]
    a.fortran_call = f"{api_name}={api_name}, &{api_name_n}={api_name_n}"
    a.fortran_post = f"{name} = ovectorsize_({api_name}, &{api_name_n})"
    a.fortran_local = [f"type(c_ptr) :: {api_name}", f"integer(c_size_t) :: {api_name_n}"]
    a.texi_type = "vector of sizes"
    return a


def ovectordouble(name, value=None, python_value=None, julia_value=None):
    a = arg(name, value, python_value, julia_value, "std::vector<double> &",
            "double *", True)
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
    a.julia_pre = (api_name + " = Ref{Ptr{Cdouble}}()\n    " + api_name_n +
                   " = Ref{Csize_t}()")
    a.julia_arg = api_name + ", " + api_name_n
    a.julia_post = (name + " = unsafe_wrap(Array, " + api_name + "[], " +
                    api_name_n + "[], own = true)")
    a.fortran_args = [name]
    a.fortran_c_api = ["type(c_ptr), intent(out)", "integer(c_size_t)"]
    a.fortran_c_args = [api_name, api_name_n]
    a.fortran_types = ["real(c_double), dimension(:), allocatable, intent(out)"]
    a.fortran_call = f"{api_name}={api_name}, &{api_name_n}={api_name_n}"
    a.fortran_post = f"{name} = ovectordouble_({api_name}, &{api_name_n})"
    a.fortran_local = [f"type(c_ptr) :: {api_name}", f"integer(c_size_t) :: {api_name_n}"]
    a.texi_type = "vector of doubles"
    return a


def ovectorstring(name, value=None, python_value=None, julia_value=None):
    a = arg(name, value, python_value, julia_value,
            "std::vector<std::string> &", "char **", True)
    api_name = "api_" + name + "_"
    api_name_n = api_name + "n_"
    a.c_pre = "    std::vector<std::string> " + api_name + ";\n"
    a.c_arg = api_name
    a.c_post = ("    vectorstring2charptrptr(" + api_name + ", " + name +
                ", " + name + "_n);\n")
    a.c = "char *** " + name + ", size_t * " + name + "_n"
    a.cwrap_pre = "char **" + api_name + "; size_t " + api_name_n + ";\n"
    a.cwrap_arg = "&" + api_name + ", " + "&" + api_name_n
    a.cwrap_post = (name + ".resize(" + api_name_n + "); " +
                    "for(size_t i = 0; i < " + api_name_n + "; ++i){ " + name +
                    "[i] = std::string(" + api_name + "[i]); " + ns + "Free(" +
                    api_name + "[i]); } " + ns + "Free(" + api_name + ");\n")
    a.python_pre = api_name + ", " + api_name_n + " = POINTER(POINTER(c_char))(), c_size_t()"
    a.python_arg = "byref(" + api_name + "), byref(" + api_name_n + ")"
    a.python_return = "_ovectorstring(" + api_name + ", " + api_name_n + ".value)"
    a.julia_ctype = "Ptr{Ptr{Ptr{Cchar}}}, Ptr{Csize_t}"
    a.julia_pre = (api_name + " = Ref{Ptr{Ptr{Cchar}}}()\n    " + api_name_n +
                   " = Ref{Csize_t}()")
    a.julia_arg = api_name + ", " + api_name_n
    a.julia_post = ("tmp_" + api_name + " = unsafe_wrap(Array, " + api_name +
                    "[], " + api_name_n + "[], own = true)\n    " + name +
                    " = [unsafe_string(tmp_" + api_name +
                    "[i]) for i in 1:length(tmp_" + api_name + ") ]")
    a.fortran_args = [name]
    a.fortran_types = ["character(len=GMSH_API_MAX_STR_LEN), dimension(:), allocatable, intent(out)"]
    a.fortran_c_api = ["type(c_ptr), intent(out)", "integer(c_size_t), intent(out)"]
    a.fortran_c_args = [api_name, api_name_n]
    a.fortran_call = f"{api_name}={api_name}, &{api_name_n}={api_name_n}"
    a.fortran_post = f"{name} = ovectorstring_({api_name}, &{api_name_n})"
    a.fortran_local = [f"type(c_ptr) :: {api_name}", f"integer(c_size_t) :: {api_name_n}"]
    a.texi_type = "vector of strings"
    return a


def ovectorpair(name, value=None, python_value=None, julia_value=None):
    a = arg(name, value, python_value, julia_value, ns + "::vectorpair &",
            "int **", True)
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
                    name + "[i].first = " + api_name + "[i * 2 + 0]; " + name +
                    "[i].second = " + api_name + "[i * 2 + 1]; } " + ns +
                    "Free(" + api_name + ");\n")
    a.python_pre = api_name + ", " + api_name_n + " = POINTER(c_int)(), c_size_t()"
    a.python_arg = "byref(" + api_name + "), byref(" + api_name_n + ")"
    a.python_return = "_ovectorpair(" + api_name + ", " + api_name_n + ".value)"
    a.julia_ctype = "Ptr{Ptr{Cint}}, Ptr{Csize_t}"
    a.julia_pre = (api_name + " = Ref{Ptr{Cint}}()\n    " + api_name_n +
                   " = Ref{Csize_t}()")
    a.julia_arg = api_name + ", " + api_name_n
    a.julia_post = ("tmp_" + api_name + " = unsafe_wrap(Array, " + api_name +
                    "[], " + api_name_n + "[], own = true)\n    " + name +
                    " = [ (tmp_" + api_name + "[i], tmp_" + api_name +
                    "[i+1]) " + "for i in 1:2:length(tmp_" + api_name + ") ]")
    a.fortran_args = [name]
    a.fortran_types = ["integer(c_int), dimension(:,:), allocatable, intent(out)"]
    a.fortran_c_api = ["type(c_ptr), intent(out)", "integer(c_size_t), intent(out)"]
    a.fortran_c_args = [api_name, api_name_n]
    a.fortran_call = f"{api_name}={api_name}, &{api_name_n}={api_name_n}"
    a.fortran_post = f"{name} = ovectorpair_({api_name}, &{api_name_n})"
    a.fortran_local = [f"type(c_ptr) :: {api_name}", f"integer(c_size_t) :: {api_name_n}"]
    a.texi_type = "vector of pairs of integers"
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
    a.c = "int *** " + name + ", size_t ** " + name + "_n, size_t *" + name + "_nn"
    a.cwrap_pre = "int **" + api_name + "; size_t *" + api_name_n + ", " + api_name_nn + ";\n"
    a.cwrap_arg = "&" + api_name + ", " + "&" + api_name_n + ", " + "&" + api_name_nn
    a.cwrap_post = (name + ".resize(" + api_name_nn + "); " +
                    "for(size_t i = 0; i < " + api_name_nn + "; ++i){ " +
                    name + "[i].assign(" + api_name + "[i], " + api_name +
                    "[i] + " + api_name_n + "[i]); " + ns + "Free(" +
                    api_name + "[i]); } " + ns + "Free(" + api_name + "); " +
                    ns + "Free(" + api_name_n + ");\n")
    a.python_pre = (
        api_name + ", " + api_name_n + ", " + api_name_nn +
        " = POINTER(POINTER(c_int))(), POINTER(c_size_t)(), c_size_t()")
    a.python_arg = ("byref(" + api_name + "), byref(" + api_name_n +
                    "), byref(" + api_name_nn + ")")
    a.python_return = ("_ovectorvectorint(" + api_name + ", " + api_name_n +
                       ", " + api_name_nn + ")")
    a.julia_ctype = "Ptr{Ptr{Ptr{Cint}}}, Ptr{Ptr{Csize_t}}, Ptr{Csize_t}"
    a.julia_pre = (api_name + " = Ref{Ptr{Ptr{Cint}}}()\n    " + api_name_n +
                   " = Ref{Ptr{Csize_t}}()\n    " + api_name_nn +
                   " = Ref{Csize_t}()")
    a.julia_arg = api_name + ", " + api_name_n + ", " + api_name_nn
    a.julia_post = ("tmp_" + api_name + " = unsafe_wrap(Array, " + api_name +
                    "[], " + api_name_nn + "[], own = true)\n    " + "tmp_" +
                    api_name_n + " = unsafe_wrap(Array, " + api_name_n +
                    "[], " + api_name_nn + "[], own = true)\n    " + name +
                    " = [ unsafe_wrap(Array, tmp_" + api_name + "[i], " +
                    "tmp_" + api_name_n + "[i], own = true) for i in 1:" +
                    api_name_nn + "[] ]")
    a.fortran_args = [name, name + "_n"]
    a.fortran_types = ["integer(c_int), dimension(:), allocatable, intent(out)", "integer(c_size_t), dimension(:), allocatable, intent(out)"]
    a.fortran_c_api = ["type(c_ptr), intent(out)", "type(c_ptr), intent(out)", "integer(c_size_t), intent(out)"]
    a.fortran_c_args = [api_name, api_name_n, api_name_nn]
    a.fortran_call = f"{api_name}={api_name}, &{api_name_n}={api_name_n}, &{api_name_nn}={api_name_nn}"
    a.fortran_post = f"call ovectorvectorint_({api_name}, &{api_name_n}, &{api_name_nn}, &{name}, &{name}_n)"
    a.fortran_local = [f"type(c_ptr) :: {api_name}, {api_name_n}", f"integer(c_size_t) :: {api_name_nn}"]
    a.texi_type = "vector of vectors of integers"
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
    a.c = "size_t *** " + name + ", size_t ** " + name + "_n, size_t *" + name + "_nn"
    a.cwrap_pre = "size_t **" + api_name + "; size_t *" + api_name_n + ", " + api_name_nn + ";\n"
    a.cwrap_arg = "&" + api_name + ", " + "&" + api_name_n + ", " + "&" + api_name_nn
    a.cwrap_post = (name + ".resize(" + api_name_nn + "); " +
                    "for(size_t i = 0; i < " + api_name_nn + "; ++i){ " +
                    name + "[i].assign(" + api_name + "[i], " + api_name +
                    "[i] + " + api_name_n + "[i]); " + ns + "Free(" +
                    api_name + "[i]); } " + ns + "Free(" + api_name + "); " +
                    ns + "Free(" + api_name_n + ");\n")
    a.python_pre = (
        api_name + ", " + api_name_n + ", " + api_name_nn +
        " = POINTER(POINTER(c_size_t))(), POINTER(c_size_t)(), c_size_t()")
    a.python_arg = ("byref(" + api_name + "), byref(" + api_name_n +
                    "), byref(" + api_name_nn + ")")
    a.python_return = ("_ovectorvectorsize(" + api_name + ", " + api_name_n +
                       ", " + api_name_nn + ")")
    a.julia_ctype = "Ptr{Ptr{Ptr{Csize_t}}}, Ptr{Ptr{Csize_t}}, Ptr{Csize_t}"
    a.julia_pre = (api_name + " = Ref{Ptr{Ptr{Csize_t}}}()\n    " +
                   api_name_n + " = Ref{Ptr{Csize_t}}()\n    " + api_name_nn +
                   " = Ref{Csize_t}()")
    a.julia_arg = api_name + ", " + api_name_n + ", " + api_name_nn
    a.julia_post = ("tmp_" + api_name + " = unsafe_wrap(Array, " + api_name +
                    "[], " + api_name_nn + "[], own = true)\n    " + "tmp_" +
                    api_name_n + " = unsafe_wrap(Array, " + api_name_n +
                    "[], " + api_name_nn + "[], own = true)\n    " + name +
                    " = [ unsafe_wrap(Array, tmp_" + api_name + "[i], " +
                    "tmp_" + api_name_n + "[i], own = true) for i in 1:" +
                    api_name_nn + "[] ]")
    a.fortran_args = [name, name + "_n"]
    a.fortran_types = ["integer(c_size_t), dimension(:), allocatable, intent(out)", "integer(c_size_t), dimension(:), allocatable, intent(out)"]
    a.fortran_c_api = ["type(c_ptr), intent(out)", "type(c_ptr), intent(out)", "integer(c_size_t), intent(out)"]
    a.fortran_c_args = [api_name, api_name_n, api_name_nn]
    a.fortran_call = f"{api_name}={api_name}, &{api_name_n}={api_name_n}, &{api_name_nn}={api_name_nn}"
    a.fortran_post = f"call ovectorvectorsize_({api_name}, &{api_name_n}, &{api_name_nn}, &{name}, &{name}_n)"
    a.fortran_local = [f"type(c_ptr) :: {api_name}, {api_name_n}", f"integer(c_size_t) :: {api_name_nn}"]
    a.texi_type = "vector of vectors of sizes"
    return a


def ovectorvectordouble(name, value=None, python_value=None, julia_value=None):
    a = arg(name, value, python_value, julia_value,
            "std::vector<std::vector<double> > &", "double **", True)
    api_name = "api_" + name + "_"
    api_name_n = api_name + "n_"
    api_name_nn = api_name + "nn_"
    a.c_pre = "    std::vector<std::vector<double> > " + api_name + ";\n"
    a.c_arg = api_name
    a.c_post = ("    vectorvector2ptrptr(" + api_name + ", " + name + ", " +
                name + "_n, " + name + "_nn);\n")
    a.c = "double *** " + name + ", size_t ** " + name + "_n, size_t *" + name + "_nn"
    a.cwrap_pre = ("double **" + api_name + "; size_t *" + api_name_n + ", " +
                   api_name_nn + ";\n")
    a.cwrap_arg = "&" + api_name + ", " + "&" + api_name_n + ", " + "&" + api_name_nn
    a.cwrap_post = (name + ".resize(" + api_name_nn + "); " +
                    "for(size_t i = 0; i < " + api_name_nn + "; ++i){ " +
                    name + "[i].assign(" + api_name + "[i], " + api_name +
                    "[i] + " + api_name_n + "[i]); " + ns + "Free(" +
                    api_name + "[i]); } " + ns + "Free(" + api_name + "); " +
                    ns + "Free(" + api_name_n + ");\n")
    a.python_pre = (
        api_name + ", " + api_name_n + ", " + api_name_nn +
        " = POINTER(POINTER(c_double))(), POINTER(c_size_t)(), c_size_t()")
    a.python_arg = ("byref(" + api_name + "), byref(" + api_name_n +
                    "), byref(" + api_name_nn + ")")
    a.python_return = ("_ovectorvectordouble(" + api_name + ", " + api_name_n +
                       ", " + api_name_nn + ")")
    a.julia_ctype = "Ptr{Ptr{Ptr{Cdouble}}}, Ptr{Ptr{Csize_t}}, Ptr{Csize_t}"
    a.julia_pre = (api_name + " = Ref{Ptr{Ptr{Cdouble}}}()\n    " +
                   api_name_n + " = Ref{Ptr{Csize_t}}()\n    " + api_name_nn +
                   " = Ref{Csize_t}()")
    a.julia_arg = api_name + ", " + api_name_n + ", " + api_name_nn
    a.julia_post = ("tmp_" + api_name + " = unsafe_wrap(Array, " + api_name +
                    "[], " + api_name_nn + "[], own = true)\n    " + "tmp_" +
                    api_name_n + " = unsafe_wrap(Array, " + api_name_n +
                    "[], " + api_name_nn + "[], own = true)\n    " + name +
                    " = [ unsafe_wrap(Array, tmp_" + api_name + "[i], " +
                    "tmp_" + api_name_n + "[i], own = true) for i in 1:" +
                    api_name_nn + "[] ]")
    a.fortran_args = [name, name + "_n"]
    a.fortran_types = ["real(c_double), dimension(:), allocatable, intent(out)", "integer(c_size_t), dimension(:), allocatable, intent(out)"]
    a.fortran_c_api = ["type(c_ptr), intent(out)", "type(c_ptr), intent(out)", "integer(c_size_t), intent(out)"]
    a.fortran_c_args = [api_name, api_name_n, api_name_nn]
    a.fortran_call = f"{api_name}={api_name}, &{api_name_n}={api_name_n}, &{api_name_nn}={api_name_nn}"
    a.fortran_post = f"call ovectorvectordouble_({api_name}, &{api_name_n}, &{api_name_nn}, &{name}, &{name}_n)"
    a.fortran_local = [f"type(c_ptr) :: {api_name}, {api_name_n}", f"integer(c_size_t) :: {api_name_nn}"]
    a.texi_type = "vector of vectors of doubles"
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
                    name + "[i][j].second = " + api_name +
                    "[i][j * 2 + 1]; } " + ns + "Free(" + api_name +
                    "[i]); } " + ns + "Free(" + api_name + "); " + ns +
                    "Free(" + api_name_n + ");\n")
    a.python_pre = (
        api_name + ", " + api_name_n + ", " + api_name_nn +
        " = POINTER(POINTER(c_int))(), POINTER(c_size_t)(), c_size_t()")
    a.python_arg = ("byref(" + api_name + "), byref(" + api_name_n +
                    "), byref(" + api_name_nn + ")")
    a.python_return = ("_ovectorvectorpair(" + api_name + ", " + api_name_n +
                       ", " + api_name_nn + ")")
    a.julia_ctype = "Ptr{Ptr{Ptr{Cint}}}, Ptr{Ptr{Csize_t}}, Ptr{Csize_t}"
    a.julia_pre = (api_name + " = Ref{Ptr{Ptr{Cint}}}()\n    " + api_name_n +
                   " = Ref{Ptr{Csize_t}}()\n    " + api_name_nn +
                   " = Ref{Csize_t}()")
    a.julia_arg = api_name + ", " + api_name_n + ", " + api_name_nn
    a.julia_post = (
        "tmp_" + api_name + " = unsafe_wrap(Array, " + api_name + "[], " +
        api_name_nn + "[], own = true)\n    " + "tmp_" + api_name_n +
        " = unsafe_wrap(Array, " + api_name_n + "[], " + api_name_nn +
        "[], own = true)\n    " + name + " = Vector{Tuple{Cint,Cint}}[]\n    " +
        "resize!(" + name + ", " + api_name_nn + "[])\n    " + "for i in 1:" +
        api_name_nn + "[]\n    " + "    tmp = unsafe_wrap(Array, tmp_" +
        api_name + "[i], tmp_" + api_name_n + "[i], own = true)\n    " + "    " +
        name + "[i] = [(tmp[i], tmp[i+1]) for i in 1:2:length(tmp)]\n    " +
        "end")
    a.fortran_args = [name, name + "_n"]
    a.fortran_types = ["integer(c_int), dimension(:,:), allocatable, intent(out)", "integer(c_size_t), dimension(:), allocatable, intent(out)"]
    a.fortran_c_api = ["type(c_ptr), intent(out)", "type(c_ptr), intent(out)", "integer(c_size_t)"]
    a.fortran_c_args = [api_name, api_name_n, api_name_nn]
    a.fortran_call = f"{api_name}={api_name}, &{api_name_n}={api_name_n}, &{api_name_nn}={api_name_nn}"
    a.fortran_post = f"call ovectorvectorpair_({api_name}, &{api_name_n}, &{api_name_nn}, &{name}, &{name}_n)"
    a.fortran_local = [f"type(c_ptr) :: {api_name}, {api_name_n}", f"integer(c_size_t) :: {api_name_nn}"]
    a.texi_type = "vector of vectors of pairs of integers"
    return a


# special types


def iargcargv():
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
    a.texi = "(argc = 0)}, @code{argv = []"
    a.fortran_args = ["argv"]
    a.fortran_types = ["character(len=*), dimension(:), intent(in), optional"]
    a.fortran_c_api = ["integer(c_int), value, intent(in)", "type(c_ptr), dimension(*), intent(in)"]
    a.fortran_c_args = ["argc", "argv"]
    a.fortran_call = "argc=size_gmsh_str_array(argv), argv=argv_cptr"
    a.fortran_pre = "call ivectorstring_(optval_str_array(def=[''], val=argv), argv_strs, argv_cptr)"
    a.fortran_local = ["character(len=GMSH_API_MAX_STR_LEN, kind=c_char), allocatable :: argv_strs(:)",
                       "type(c_ptr), allocatable :: argv_cptr(:)"]
    a.texi_type = "command line arguments"
    return a


def isizefun(name):
    a = arg(name, None, None, None, "", "", False)
    a.cpp = "std::function<double(int, int, double, double, double, double)> " + name
    a.c_arg = ("std::bind(" + name + ", std::placeholders::_1, " +
               "std::placeholders::_2, std::placeholders::_3, " +
               "std::placeholders::_4, std::placeholders::_5, " +
               "std::placeholders::_6, " + name + "_data)")
    a.c = ("double (*" + name + ")" +
           "(int dim, int tag, double x, double y, double z, double lc, void * data), " +
           "void * " + name + "_data")
    a.cwrap_pre = "struct " + name + """_caller_  {
          static double call(int dim, int tag, double x, double y, double z, double lc, void * callbackp_) {
            return (*static_cast<std::function<double(int, int, double, double, double, double)>*> (callbackp_))(dim, tag, x, y, z, lc);
          }
        };
        // FIXME memory leak
        auto *""" + name + "_ptr_ = new std::function<double(int, int, double, double, double, double)>(" + name + """);
"""
    a.cwrap_arg = "&" + name + "_caller_::call, " + name + "_ptr_"
    a.python_pre = (
        "global api_" + name + "_type_\n" + "            api_" + name +
        "_type_ = " +
        "CFUNCTYPE(c_double, c_int, c_int, c_double, c_double, c_double, c_double, c_void_p)\n"
        + "            global api_" + name + "_\n" + "            api_" +
        name + "_ = api_" + name + "_type_(lambda dim, tag, x, y, z, lc, _ : " +
        name + "(dim, tag, x, y, z, lc))")
    a.python_arg = "api_" + name + "_, None"
    a.julia_pre = (
        "api_" + name + "__(dim, tag, x, y, z, lc, data) = " + name +
        "(dim, tag, x, y, z, lc)\n    " + "api_" + name + "_ = @cfunction($api_" +
        name + "__" +
        ", Cdouble, (Cint, Cint, Cdouble, Cdouble, Cdouble, Cdouble, Ptr{Cvoid}))")
    a.julia_arg = "api_" + name + "_, C_NULL"
    a.julia_ctype = "Ptr{Cvoid}, Ptr{Cvoid}"
    a.fortran_args = [name]
    a.fortran_types = ["type(c_funptr), value, intent(in)"]
    a.fortran_c_api = ["type(c_funptr), value, intent(in)"]
    a.fortran_c_args = [name]
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


cpp_header = """// {0}
//
// See the LICENSE.txt file in the {3} root directory for license information.
// Please report all issues on {1}

#ifndef {2}_H
#define {2}_H

// {8}This file defines the {3} C++ API (v{4}.{5}.{6}).
//
// Do not edit this file directly: it is automatically generated by `api/gen.py'.
//
// By design, the {3} C++ API is purely functional, and only uses elementary
// types from the C++ standard library. See `tutorials/c++' and `examples/api'
// for tutorials and examples.

#include <cmath>
#include <vector>
#include <string>
#include <utility>
#include <functional>

#define {2}_API_VERSION "{4}.{5}.{6}"
#define {2}_API_VERSION_MAJOR {4}
#define {2}_API_VERSION_MINOR {5}
#define {2}_API_VERSION_PATCH {6}

#if defined({2}_DLL)
#if defined({2}_DLL_EXPORT)
#define {2}_API __declspec(dllexport)
#else
#define {2}_API __declspec(dllimport)
#endif
#elif defined(__GNUC__)
#define {2}_API __attribute__ ((visibility("default")))
#else
#define {2}_API
#endif

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

namespace {7} {{

  // A model entity in the {3} API is represented by two integers: its
  // dimension (dim = 0, 1, 2 or 3) and its tag (its unique, strictly positive
  // identifier). When dealing with multiple model entities of possibly
  // different dimensions, the entities are packed as a vector of (dim, tag)
  // integer pairs.
  typedef std::vector<std::pair<int, int> > vectorpair;

}}

"""

cpp_footer = """#endif
"""

c_header = """/*
 * {0}
 *
 * See the LICENSE.txt file in the {3} root directory for license information.
 * Please report all issues on {1}
 */

#ifndef {2}C_H
#define {2}C_H

/*
 * {8}This file defines the {3} C API (v{4}.{5}.{6}).
 *
 * Do not edit this file directly: it is automatically generated by `api/gen.py'.
 *
 * By design, the {3} C API is purely functional, and only uses elementary
 * C types. See `tutorials/c' and `examples/api' for tutorials and examples.
 */

#include <stddef.h>

#define {2}_API_VERSION "{4}.{5}.{6}"
#define {2}_API_VERSION_MAJOR {4}
#define {2}_API_VERSION_MINOR {5}
#define {2}_API_VERSION_PATCH {6}

#if defined({2}_DLL)
#if defined({2}_DLL_EXPORT)
#define {2}_API __declspec(dllexport)
#else
#define {2}_API __declspec(dllimport)
#endif
#elif defined(__GNUC__)
#define {2}_API __attribute__ ((visibility("default")))
#else
#define {2}_API
#endif

/* All the functions in the {3} C API that return arrays allocate the
 * necessary memory with {7}Malloc(). These arrays should be deallocated
 * with {7}Free(). */
{2}_API void {7}Free(void *p);
{2}_API void *{7}Malloc(size_t n);
"""

c_footer = """
#endif
"""

c_cpp_header = """// {0}
//
// See the LICENSE.txt file in the {4} root directory for license information.
// Please report all issues on {1}

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

c_cpp_utils = """
void vectorvectorpair2intptrptr(const std::vector<{0}::vectorpair > &v, int ***p, size_t **size, size_t *sizeSize)
{{
  if(p) {{
    *p = (int**){0}Malloc(sizeof(int*) * v.size());
  }}
  if(size) {{
    *size = (size_t*){0}Malloc(sizeof(size_t) * v.size());
  }}
  for(size_t i = 0; i < v.size(); ++i)
    vectorpair2intptr(v[i], p ? &((*p)[i]) : NULL, size ? &((*size)[i]) : NULL);
  if(sizeSize) {{
    *sizeSize = v.size();
  }}
}}
"""

cwrap_header = """// {0}
//
// See the LICENSE.txt file in the {3} root directory for license information.
// Please report all issues on {1}

#ifndef {2}_H
#define {2}_H

// {8}This file redefines the {3} C++ API in terms of the C API (v{4}.{5}.{6}).
//
// This is provided as a convenience for users of the binary {3} SDK whose C++
// compiler ABI is not compatible with the ABI of the C++ compiler used to create
// the SDK (and who can thus not directly use the C++ API defined in `{7}.h').
//
// To use this header file in your C++ code, simply rename it as `{7}.h'.
//
// Note that using this header file will lead to (slightly) reduced performance
// compared to using the native {3} C++ API from the original `{7}.h', as it
// entails additional data copies between this C++ wrapper, the C API and the
// native C++ code.
//
// Do not edit this file directly: it is automatically generated by `api/gen.py'.

#include <cmath>
#include <vector>
#include <string>
#include <utility>
#include <functional>
#include <stdexcept>

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

extern \"C\" {{
  #include "{7}c.h"
}}

namespace {7} {{

  // A model entity in the {3} API is represented by two integers: its
  // dimension (dim = 0, 1, 2 or 3) and its tag (its unique, strictly positive
  // identifier). When dealing with multiple model entities of possibly
  // different dimensions, the entities are packed as a vector of (dim, tag)
  // integer pairs.
  typedef std::vector<std::pair<int, int> > vectorpair;

}}

"""

cwrap_utils = """
template<typename t>
{1}void vector2ptr(const std::vector<t> &v, t **p, size_t *size)
{{
  if(p) {{
    *p = (t*){0}Malloc(sizeof(t) * v.size());
    for(size_t i = 0; i < v.size(); ++i) {{
      (*p)[i] = v[i];
    }}
  }}
  if(size) {{
    *size = v.size();
  }}
}}

{1}void vectorpair2intptr(const {0}::vectorpair &v, int **p, size_t *size)
{{
  if(p) {{
    *p = (int*){0}Malloc(sizeof(int) * v.size() * 2);
    for(size_t i = 0; i < v.size(); ++i) {{
      (*p)[i * 2 + 0] = v[i].first;
      (*p)[i * 2 + 1] = v[i].second;
    }}
  }}
  if(size) {{
    *size = v.size() * 2;
  }}
}}

{1}void vectorstring2charptrptr(const std::vector<std::string> &v, char ***p, size_t *size)
{{
  if(p) {{
    *p = (char**){0}Malloc(sizeof(char*) * v.size());
    for(size_t i = 0; i < v.size(); ++i) {{
      (*p)[i] = (char*){0}Malloc(sizeof(char) * (v[i].size() + 1));
      for(size_t j = 0; j < v[i].size(); j++) (*p)[i][j] = v[i][j];
      (*p)[i][v[i].size()] = '\\0';
    }}
  }}
  if(size) {{
    *size = v.size();
  }}
}}

template<typename t>
{1}void vectorvector2ptrptr(const std::vector<std::vector<t> > &v, t ***p, size_t **size, size_t *sizeSize)
{{
  if(p) {{
    *p = (t**){0}Malloc(sizeof(t*) * v.size());
  }}
  if(size) {{
    *size = (size_t*){0}Malloc(sizeof(size_t) * v.size());
  }}
  for(size_t i = 0; i < v.size(); ++i)
    vector2ptr(v[i], p ? &((*p)[i]) : NULL, size ? &((*size)[i]) : NULL);
  if(sizeSize) {{
    *sizeSize = v.size();
  }}
}}
"""

cwrap_footer = """#endif
"""

python_header = """# {0}
#
# See the LICENSE.txt file in the {2} root directory for license information.
# Please report all issues on {1}

# This file defines the {2} Python API (v{3}.{4}.{5}).
#
# Do not edit this file directly: it is automatically generated by `api/gen.py'.
#
# By design, the {2} Python API is purely functional, and only uses elementary
# Python types (as well as `numpy' arrays if `numpy' is available). See
# `tutorials/python' and `examples/api' for tutorials and examples.

\"\"\"
{8}

This module defines the {2} Python API.
\"\"\"

from ctypes import *
from ctypes.util import find_library
import signal
import os
import platform
from math import pi

{6}_API_VERSION = "{3}.{4}.{5}"
{6}_API_VERSION_MAJOR = {3}
{6}_API_VERSION_MINOR = {4}
{6}_API_VERSION_PATCH = {5}

__version__ = {6}_API_VERSION

moduledir = os.path.dirname(os.path.realpath(__file__))
parentdir1 = os.path.dirname(moduledir)
parentdir2 = os.path.dirname(parentdir1)

if platform.system() == "Windows":
    libname = "{7}-{3}.{4}.dll"
elif platform.system() == "Darwin":
    libname = "lib{7}.{3}.{4}.dylib"
else:
    libname = "lib{7}.so.{3}.{4}"

# Searching lib in various subfolders
libpath = None
possible_libpaths = [os.path.join(moduledir, libname),
                     os.path.join(moduledir, "lib", libname),
                     os.path.join(moduledir, "Lib", libname),
                     # first parent dir
                     os.path.join(parentdir1, libname),
                     os.path.join(parentdir1, "lib", libname),
                     os.path.join(parentdir1, "Lib", libname),
                     # second parent dir
                     os.path.join(parentdir2, libname),
                     os.path.join(parentdir2, "lib", libname),
                     os.path.join(parentdir2, "Lib", libname)
                     ]

for libpath_to_look in possible_libpaths:
    if os.path.exists(libpath_to_look):
        libpath = libpath_to_look
        break

# if we couldn't find it, use ctype's find_library utility...
if not libpath:
    if platform.system() == "Windows":
        libpath = find_library("gmsh-4.11")
        if not libpath:
            libpath = find_library("gmsh")
    else:
        libpath = find_library("gmsh")

# ... and print a warning if everything failed
if not libpath:
    print("Warning: could not find Gmsh shared library " + libname +
          " with ctypes.util.find_library() or in the following locations: " +
          str(possible_libpaths))

lib = CDLL(libpath)

try_numpy = True # set this to False to never use numpy

use_numpy = False
if try_numpy:
    try:
        import numpy
        try:
            from weakref import finalize as weakreffinalize
        except:
            from backports.weakref import finalize as weakreffinalize
        use_numpy = True
    except:
        pass

prev_interrupt_handler = None

# Utility functions, not part of the Gmsh Python API

def _ostring(s):
    sp = s.value.decode("utf-8")
    lib.{7}Free(s)
    return sp

def _ovectorpair(ptr, size):
    v = list((ptr[i * 2], ptr[i * 2 + 1]) for i in range(size//2))
    lib.{7}Free(ptr)
    return v

def _ovectorint(ptr, size):
    if use_numpy:
        if size == 0 :
            lib.{7}Free(ptr)
            return numpy.ndarray((0,),numpy.int32)
        v = numpy.ctypeslib.as_array(ptr, (size, ))
        weakreffinalize(v, lib.{7}Free, ptr)
    else:
        v = list(ptr[i] for i in range(size))
        lib.{7}Free(ptr)
    return v

def _ovectorsize(ptr, size):
    if use_numpy:
        if size == 0 :
            lib.{7}Free(ptr)
            return numpy.ndarray((0,),numpy.uintp)
        v = numpy.ctypeslib.as_array(ptr, (size, ))
        weakreffinalize(v, lib.{7}Free, ptr)
    else:
        v = list(ptr[i] for i in range(size))
        lib.{7}Free(ptr)
    return v

def _ovectordouble(ptr, size):
    if use_numpy:
        if size == 0 :
            lib.{7}Free(ptr)
            return numpy.ndarray((0,),numpy.float64)
        v = numpy.ctypeslib.as_array(ptr, (size, ))
        weakreffinalize(v, lib.{7}Free, ptr)
    else:
        v = list(ptr[i] for i in range(size))
        lib.{7}Free(ptr)
    return v

def _ovectorstring(ptr, size):
    v = list(_ostring(cast(ptr[i], c_char_p)) for i in range(size))
    lib.{7}Free(ptr)
    return v

def _ovectorvectorint(ptr, size, n):
    v = [_ovectorint(pointer(ptr[i].contents), size[i]) for i in range(n.value)]
    lib.{7}Free(size)
    lib.{7}Free(ptr)
    return v

def _ovectorvectorsize(ptr, size, n):
    v = [_ovectorsize(pointer(ptr[i].contents), size[i]) for i in range(n.value)]
    lib.{7}Free(size)
    lib.{7}Free(ptr)
    return v

def _ovectorvectordouble(ptr, size, n):
    v = [_ovectordouble(pointer(ptr[i].contents), size[i]) for i in range(n.value)]
    lib.{7}Free(size)
    lib.{7}Free(ptr)
    return v

def _ovectorvectorpair(ptr, size, n):
    v = [_ovectorpair(pointer(ptr[i].contents), size[i]) for i in range(n.value)]
    lib.{7}Free(size)
    lib.{7}Free(ptr)
    return v

def _ivectorint(o):
    if use_numpy:
        array = numpy.ascontiguousarray(o, numpy.int32)
        if(len(o) and array.ndim != 1):
            raise Exception("Invalid data for input vector of integers")
        ct = array.ctypes
        ct.array = array
        return ct, c_size_t(len(o))
    else:
        return (c_int * len(o))(*o), c_size_t(len(o))

def _ivectorsize(o):
    if use_numpy:
        array = numpy.ascontiguousarray(o, numpy.uintp)
        if(len(o) and array.ndim != 1):
            raise Exception("Invalid data for input vector of sizes")
        ct = array.ctypes
        ct.array = array
        return ct, c_size_t(len(o))
    else:
        return (c_size_t * len(o))(*o), c_size_t(len(o))

def _ivectordouble(o):
    if use_numpy:
        array = numpy.ascontiguousarray(o, numpy.float64)
        if(len(o) and array.ndim != 1):
            raise Exception("Invalid data for input vector of doubles")
        ct = array.ctypes
        ct.array = array
        return  ct, c_size_t(len(o))
    else:
        return (c_double * len(o))(*o), c_size_t(len(o))

def _ivectorpair(o):
    if use_numpy:
        array = numpy.ascontiguousarray(o, numpy.int32)
        if(len(o) and (array.ndim != 2 or array.shape[1] != 2)):
            raise Exception("Invalid data for input vector of pairs")
        ct = array.ctypes
        ct.array = array
        return ct, c_size_t(len(o) * 2)
    else:
        if(len(o) and len(o[0]) != 2):
            raise Exception("Invalid data for input vector of pairs")
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
# See the LICENSE.txt file in the {2} root directory for license information.
# Please report all issues on {1}

# This file defines the {2} Julia API (v{3}.{4}.{5}).
#
# Do not edit this file directly: it is automatically generated by `api/gen.py'.
#
# By design, the {2} Julia API is purely functional, and only uses elementary
# Julia types. See `tutorials/julia' and `examples/api' for tutorials and
# examples.
"""


fortran_header = """!
! {0}
!
! See the LICENSE.txt file in the {3} root directory for license information.
! Please report all issues on {1}

! {7}This file defines the {3} Fortran API (v{4}.{5}.{6}).
!
! Do not edit this file directly: it is automatically generated by `api/gen.py'.
!
! By design, the {3} Fortran API is purely functional, and only uses elementary
! Fortran types. See `tutorials/fortran' and `examples/api' for tutorials and
! examples.

module gmsh

  use, intrinsic :: iso_c_binding

  implicit none

  private

  integer, parameter, public :: {2}_API_VERSION_MAJOR = {4}
  integer, parameter, public :: {2}_API_VERSION_MINOR = {5}
  integer, parameter, public :: {2}_API_VERSION_PATCH = {6}
  integer, parameter, public :: {2}_API_MAX_STR_LEN = 512
  real(c_double), parameter, public :: M_PI = 3.14159265358979323846_c_double
  character(len=100), parameter, public :: {2}_API_VERSION = "{4}.{5}.{6}"

  public :: gmshFree

  type cstr_t
    character(len=:), allocatable :: s
  end type cstr_t

  type, private :: c_array_t
    type(c_ptr) :: s
  end type c_array_t

  interface optval_c_int
    module procedure optval_c_int_1
  end interface optval_c_int

  interface optval_c_size_t
    module procedure optval_c_size_t_1, optval_c_size_t_2
  end interface optval_c_size_t

  interface optval_c_double
    module procedure optval_c_double_1, optval_c_double_2
  end interface optval_c_double

"""

fortran_footer = """
  ! ----------------------------------------------------------------------------
  ! GMSH size function
  ! ----------------------------------------------------------------------------

  pure integer(c_int) function optval_c_int_1(def, val) result(res)
    integer(c_int), intent(in) :: def
    integer(c_int), optional, intent(in) :: val
    res = int(def, kind=c_int)
    if (present(val)) res = int(val, kind=c_int)
  end function optval_c_int_1

  pure integer(c_size_t) function optval_c_size_t_1(def, val) result(res)
    integer, intent(in) :: def
    integer, optional, intent(in) :: val
    res = int(def, kind=c_size_t)
    if (present(val)) res = int(val, kind=c_size_t)
  end function optval_c_size_t_1

  pure integer(c_size_t) function optval_c_size_t_2(def, val) result(res)
    integer(c_size_t), intent(in) :: def
    integer(c_size_t), optional, intent(in) :: val
    res = int(def, kind=c_size_t)
    if (present(val)) res = int(val, kind=c_size_t)
  end function optval_c_size_t_2

  pure real(c_double) function optval_c_double_1(def, val) result(res)
    real(c_double), intent(in) :: def
    real(c_double), optional, intent(in) :: val
    res = real(def, kind=c_double)
    if (present(val)) res = real(val, kind=c_double)
  end function optval_c_double_1

  pure real(c_double) function optval_c_double_2(def, val) result(res)
    real, intent(in) :: def
    real(c_double), optional, intent(in) :: val
    res = real(def, kind=c_double)
    if (present(val)) res = real(val, kind=c_double)
  end function optval_c_double_2

  pure integer(c_int) function optval_c_bool(def, val) result(res)
    logical, intent(in) :: def
    logical, optional, intent(in) :: val
    res = merge(1_c_int, 0_c_int, def)
    if (present(val)) res = merge(1_c_int, 0_c_int, val)
  end function optval_c_bool

  pure function optval_c_str(def, val) result(res)
    character(len=*), intent(in) :: def
    character(len=*), optional, intent(in) :: val
    character(len=:), allocatable :: res
    if (present(val)) then
      res = val
    else
      res = def
    end if
  end function optval_c_str

  pure function optval_str_array(def, val) result(res)
    character(len=*), intent(in) :: def(:)
    character(len=*), optional, intent(in) :: val(:)
    character(len=:), allocatable :: res(:)
    if (present(val)) then
      res = val
    else
      res = def
    end if
  end function optval_str_array

  ! ----------------------------------------------------------------------------
  ! GMSH size functions, with handling of optional arguments
  ! ----------------------------------------------------------------------------

  pure integer(c_size_t) function size_gmsh_int(v) result(n)
    integer(c_int), optional, intent(in) :: v(:)
    n = 0
    if (present(v)) n = size(v, kind=c_size_t)
  end function size_gmsh_int

  pure integer(c_size_t) function size_gmsh_size(v) result(n)
    integer(c_size_t), optional, intent(in) :: v(:)
    n = 0
    if (present(v)) n = size(v, kind=c_size_t)
  end function size_gmsh_size

  pure integer(c_size_t) function size_gmsh_double(v) result(n)
    real(c_double), optional, intent(in) :: v(:)
    n = 0
    if (present(v)) n = size(v, kind=c_size_t)
  end function size_gmsh_double

  pure integer(c_size_t) function size_gmsh_str(v) result(n)
    character(len=*), optional, intent(in) :: v(:)
    n = 0
    if (present(v)) n = size(v, kind=c_size_t)
  end function size_gmsh_str

  pure integer(c_size_t) function size_gmsh_pair(v) result(n)
    integer(c_int), optional, intent(in) :: v(:,:)
    n = 0
    if (present(v)) n = size(v, kind=c_size_t)
  end function size_gmsh_pair

  pure integer(c_int) function size_gmsh_str_array(v) result(n)
    character(len=*), optional, intent(in) :: v(:)
    n = 1   ! can't have 0-length commands
    if (present(v)) n = size(v, kind=c_int)
  end function size_gmsh_str_array

  ! ----------------------------------------------------------------------------
  ! GMSH C memory management tools
  ! ----------------------------------------------------------------------------

  !> Callback to C to free any reserved memory
  subroutine gmshFree(p)
    interface
      subroutine C_API(ptr) bind(C, name="gmshFree")
        use, intrinsic :: iso_c_binding
        type(c_ptr), value :: ptr
      end subroutine C_API
    end interface
    type(c_ptr) :: p
    call C_API(p)
  end subroutine gmshFree

  ! ----------------------------------------------------------------------------
  ! Input routines from Fortran to C
  ! ----------------------------------------------------------------------------

  function istring_(o) result(v)
    character(len=*), intent(in) :: o
    character(len=:, kind=c_char), allocatable :: v
    v = trim(o)//c_null_char
  end function istring_

  function ivectorint_(o) result(v)
    integer(c_int), intent(in) :: o(:)
    integer(c_int), dimension(size(o)) :: v
    v = o
  end function ivectorint_

  function ivectorsize_(o) result(v)
    integer(c_size_t), intent(in) :: o(:)
    integer(c_size_t), dimension(size(o)) :: v
    v = o
  end function ivectorsize_

  function ivectordouble_(o) result(v)
    real(c_double), intent(in) :: o(:)
    real(c_double), dimension(size(o)) :: v
    v = o
  end function ivectordouble_

  subroutine ivectorstring_(o, cstrs, cptrs)
    character(len=*), intent(in) :: o(:)
    character(len=GMSH_API_MAX_STR_LEN, kind=c_char), target, allocatable, intent(out) :: cstrs(:)
    type(c_ptr), allocatable, intent(out) :: cptrs(:)
    integer :: i
    allocate(cstrs(size(o)))    ! Return to keep references from cptrs
    allocate(cptrs(size(o)))
    do i = 1, size(o)
        cstrs(i) = istring_(o(i))
        cptrs(i) = c_loc(cstrs(i))
    end do
  end subroutine ivectorstring_

  function ivectorpair_(o) result(v)
    integer(c_int), intent(in) :: o(:,:)
    integer(c_int), dimension(size(o,1),2) :: v
    v = o
  end function ivectorpair_

  subroutine ivectorvectorint_(v, dims, cptr1, cptr2, n)
    integer(c_int), target, intent(in) :: v(:)
    integer(c_size_t), target, intent(in) :: dims(:)
    type(c_ptr), intent(out) :: cptr1, cptr2
    integer(c_size_t), intent(out) :: n

    n = size(dims, kind=c_size_t)
    cptr1 = c_loc(v)
    cptr2 = c_loc(dims)
  end subroutine ivectorvectorint_

  subroutine ivectorvectorsize_(v, dims, cptr1, cptr2, n)
    integer(c_size_t), target, intent(in) :: v(:)
    integer(c_size_t), target, intent(in) :: dims(:)
    type(c_ptr), intent(out) :: cptr1, cptr2
    integer(c_size_t), intent(out) :: n

    n = size(dims, kind=c_size_t)
    cptr1 = c_loc(v)
    cptr2 = c_loc(dims)
  end subroutine ivectorvectorsize_

  subroutine ivectorvectordouble_(v, dims, cptr1, cptr2, n)
    real(c_double), target, intent(in) :: v(:)
    integer(c_size_t), target, intent(in) :: dims(:)
    type(c_ptr), intent(out) :: cptr1, cptr2
    integer(c_size_t), intent(out) :: n

    n = size(dims, kind=c_size_t)
    cptr1 = c_loc(v)
    cptr2 = c_loc(dims)
  end subroutine ivectorvectordouble_

  ! subroutine ivectorvectorpair_(v, dims, cptr1, cptr2, n)
  !   integer(c_int), target, intent(in) :: v(:,:)
  !   integer(c_size_t), target, intent(in) :: dims(:)
  !   type(c_ptr), intent(out) :: cptr1, cptr2
  !   integer(c_size_t), intent(out) :: n
  !
  !   n = size(dims, kind=c_size_t)
  !   cptr1 = c_loc(v)
  !   cptr2 = c_loc(dims)
  ! end subroutine ivectorvectorpair_


  ! ----------------------------------------------------------------------------
  ! Output routines from C to Fortran
  ! ----------------------------------------------------------------------------


  function ostring_(cptr) result(v)
    type(c_ptr), intent(inout) :: cptr
    character(len=:), allocatable :: v
    character(len=GMSH_API_MAX_STR_LEN), pointer :: fptr
    integer(c_size_t) :: i
    call c_f_pointer(cptr, fptr)
    do i = 1_c_size_t, GMSH_API_MAX_STR_LEN
      if (fptr(i:i) == c_null_char) exit
    end do
    v = fptr(:i)
    call gmshFree(cptr)
  end function ostring_

  function ovectorint_(cptr, n) result(v)
    type(c_ptr), intent(inout) :: cptr
    integer(c_size_t), intent(in) :: n
    integer(c_int), allocatable :: v(:)
    integer(c_int), pointer :: v_(:)
    call c_f_pointer(cptr, v_, [n])
    allocate(v, source=v_)
    call gmshFree(cptr)
  end function ovectorint_

  function ovectorsize_(cptr, n) result(v)
    type(c_ptr), intent(inout) :: cptr
    integer(c_size_t), intent(in) :: n
    integer(c_size_t), allocatable :: v(:)
    integer(c_size_t), pointer :: v_(:)
    call c_f_pointer(cptr, v_, [n])
    allocate(v, source=v_)
    call gmshFree(cptr)
  end function ovectorsize_

  function ovectordouble_(cptr, n) result(v)
    type(c_ptr), intent(inout) :: cptr
    integer(c_size_t), intent(in) :: n
    real(c_double), allocatable :: v(:)
    real(c_double), pointer :: v_(:)
    call c_f_pointer(cptr, v_, [n])
    allocate(v, source=v_)
    call gmshFree(cptr)
  end function ovectordouble_

  function ovectorstring_(cptr, n) result(v)
    type(c_ptr), intent(inout) :: cptr
    integer(c_size_t), intent(in) :: n
    character(len=GMSH_API_MAX_STR_LEN), allocatable :: v(:)

    integer(c_size_t) :: i
    type(c_array_t), pointer :: c_array(:)
    character(len=GMSH_API_MAX_STR_LEN), pointer :: fptr

    call c_f_pointer(cptr, c_array, [n])
    allocate(v(n))
    do i = 1_c_size_t, n
      v(i) = ostring_(c_array(i)%s)
    end do
    call gmshFree(cptr)
  end function ovectorstring_

  function ovectorpair_(cptr, n) result(v)
    type(c_ptr), intent(inout) :: cptr
    integer(c_size_t), intent(in) :: n
    integer(c_int), allocatable :: v(:,:)
    integer(c_int), pointer :: v_(:,:)
    call c_f_pointer(cptr, v_, [2_c_size_t, n / 2_c_size_t])
    allocate(v, source=v_)
    call gmshFree(cptr)
  end function ovectorpair_

  subroutine ovectorvectorint_(cptr1, cptr2, n, v, dims)
    type(c_ptr), intent(inout) :: cptr1, cptr2
    integer(c_size_t), intent(in) :: n
    integer(c_int), allocatable, intent(out) :: v(:)
    integer(c_size_t), allocatable, intent(out) :: dims(:)
    integer(c_int), pointer :: v_(:)
    integer(c_size_t), pointer :: dims_(:)
    type(c_ptr), pointer :: ptrs(:)
    integer(c_size_t) :: i, istart, iend
    call c_f_pointer(cptr2, dims_, [n])
    allocate(dims, source=dims_)
    allocate(v(sum(dims_)))
    istart = 1
    call c_f_pointer(cptr1, ptrs, [n])
    do i = 1_c_size_t, n
        iend = int(dims(i))
        call c_f_pointer(ptrs(i), v_, [iend])
        v(istart:istart + iend - 1) = v_
        istart = istart + iend
    end do
    do i = 1_c_size_t, n
        call gmshFree(ptrs(i))
    end do
    call gmshFree(cptr1)
    call gmshFree(cptr2)
  end subroutine ovectorvectorint_

  subroutine ovectorvectorsize_(cptr1, cptr2, n, v, dims)
    type(c_ptr), intent(inout) :: cptr1, cptr2
    integer(c_size_t), intent(in) :: n
    integer(c_size_t), allocatable, intent(out) :: v(:)
    integer(c_size_t), allocatable, intent(out) :: dims(:)
    integer(c_size_t), pointer :: v_(:)
    integer(c_size_t), pointer :: dims_(:)
    type(c_ptr), pointer :: ptrs(:)
    integer(c_size_t) :: i, istart, iend
    call c_f_pointer(cptr2, dims_, [n])
    allocate(dims, source=dims_)
    allocate(v(sum(dims_)))
    istart = 1
    call c_f_pointer(cptr1, ptrs, [n])
    do i = 1_c_size_t, n
        iend = int(dims(i))
        call c_f_pointer(ptrs(i), v_, [iend])
        v(istart:istart + iend - 1) = v_
        istart = istart + iend
    end do
    do i = 1_c_size_t, n
        call gmshFree(ptrs(i))
    end do
    call gmshFree(cptr1)
    call gmshFree(cptr2)
  end subroutine ovectorvectorsize_

  subroutine ovectorvectordouble_(cptr1, cptr2, n, v, dims)
    type(c_ptr), intent(inout) :: cptr1, cptr2
    integer(c_size_t), intent(in) :: n
    real(c_double), allocatable, intent(out) :: v(:)
    integer(c_size_t), allocatable, intent(out) :: dims(:)
    real(c_double), pointer :: v_(:)
    integer(c_size_t), pointer :: dims_(:)
    type(c_ptr), pointer :: ptrs(:)
    integer(c_size_t) :: i, istart, iend
    call c_f_pointer(cptr2, dims_, [n])
    allocate(dims, source=dims_)
    allocate(v(sum(dims_)))
    istart = 1
    call c_f_pointer(cptr1, ptrs, [n])
    do i = 1_c_size_t, n
        iend = int(dims(i))
        call c_f_pointer(ptrs(i), v_, [iend])
        v(istart:istart + iend - 1) = v_
        istart = istart + iend
    end do
    do i = 1_c_size_t, n
        call gmshFree(ptrs(i))
    end do
    call gmshFree(cptr1)
    call gmshFree(cptr2)
  end subroutine ovectorvectordouble_

  subroutine ovectorvectorpair_(cptr1, cptr2, n, v, dims)
    type(c_ptr), intent(inout) :: cptr1, cptr2
    integer(c_size_t), intent(in) :: n
    integer(c_int), allocatable, intent(out) :: v(:,:)
    integer(c_size_t), allocatable, intent(out) :: dims(:)
    integer(c_int), pointer :: v_(:,:)
    integer(c_size_t), pointer :: dims_(:)
    type(c_ptr), pointer :: ptrs(:)
    integer(c_size_t) :: i, istart, iend
    call c_f_pointer(cptr2, dims_, [n])
    allocate(dims, source=dims_)
    allocate(v(2, int(sum(dims_)/2)))
    istart = 1
    call c_f_pointer(cptr1, ptrs, [n])
    do i = 1_c_size_t, n
        iend = int(dims(i)/2)
        call c_f_pointer(ptrs(i), v_, [2_c_size_t, iend])
        v(:,istart:istart + iend - 1) = v_
        istart = istart + iend
    end do
    do i = 1_c_size_t, n
        call gmshFree(ptrs(i))
    end do
    call gmshFree(cptr1)
    call gmshFree(cptr2)
  end subroutine ovectorvectorpair_

end module gmsh
"""


def capi(s):
    return s[:1].upper() + s[1:]


class API:
    def __init__(
        self,
        version_major,
        version_minor,
        version_patch,
        namespace = "gmsh",
        code = "Gmsh",
        copyright = "Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle",
        issues = "https://gitlab.onelab.info/gmsh/gmsh/issues.",
        description = "Gmsh is an automatic three-dimensional finite element mesh generator with a built-in CAD engine and post-processor. Its design goal is to provide a fast, light and user-friendly meshing tool with parametric input and flexible visualization capabilities.\nGmsh is built around four modules (geometry, mesh, solver and post-processing), which can be controlled with the graphical user interface, from the command line, using text files written in Gmsh's own scripting language (.geo files), or through the C++, C, Python, Julia and Fortran application programming interface (API)."):
        self.version_major = version_major
        self.version_minor = version_minor
        self.version_patch = version_patch
        global ns
        ns = namespace
        self.code = code
        self.copyright = copyright
        self.issues = issues
        self.description = description
        self.modules = []
        self.api_lineno = {'cpp': {}, 'c': {}, 'py': {}, 'jl': {}, 'f': {}}

    def add_module(self, name, doc):
        module = Module(name, doc)
        self.modules.append(module)
        return module

    def fwrite(self, f, s):
        self.current_lineno += s.count('\n')
        f.write(s)

    def flog(self, lang, fname):
        self.api_lineno[lang][fname] = self.current_lineno

    def write_cpp(self):
        def write_module(module, indent, cpp_mpath):
            cpp_mpath += module.name + "::"
            self.fwrite(
                f, indent + "namespace " + module.name + " { // " +
                capi(module.doc) + "\n\n")
            indent += "  "
            for rtype, name, args, doc, special in module.fs:
                rt = rtype.rcpp_type if rtype else "void"
                self.fwrite(
                    f,
                    indent + "// " + cpp_mpath + name + "\n" + indent + "//\n")
                self.fwrite(
                    f, indent + "// " + ("\n" + indent + "// ").join(
                        textwrap.wrap(doc, 80 - len(indent))) + "\n")
                fnameapi = indent + ns.upper(
                ) + "_API " + rt + " " + name + "("
                self.flog('cpp', cpp_mpath.replace('::', '/') + name)
                self.fwrite(f, fnameapi)
                if args:
                    self.fwrite(f, (",\n" + ' ' * len(fnameapi)).join(
                        a.cpp for a in args))
                self.fwrite(f, ");\n\n")
            for m in module.submodules:
                write_module(m, indent, cpp_mpath)
            self.fwrite(f,
                        indent[:-2] + "} // namespace " + module.name + "\n\n")

        self.current_lineno = 1
        with open(ns + ".h", "w") as f:
            self.fwrite(
                f,
                cpp_header.format(self.copyright, self.issues, ns.upper(),
                                  self.code, self.version_major,
                                  self.version_minor, self.version_patch, ns,
                                  "\n// ".join(textwrap.wrap(self.description, 80)) +
                                  "\n//\n// "))
            for m in self.modules:
                write_module(m, "", "")
            self.fwrite(f, cpp_footer)

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
                self.fwrite(
                    f,
                    "\n/* " + "\n * ".join(textwrap.wrap(doc, 75)) + " */\n")
                fnameapi = ns.upper() + "_API " + (rtype.rc_type if rtype else
                                                   "void") + " " + fname + "("
                self.flog('c', cpp_namespace.replace('::', '/') + name)
                self.fwrite(
                    f, fnameapi + (",\n" + ' ' * len(fnameapi)).join(
                        list((a.c for a in args + (oint("ierr"), )))) + ");\n")

                if "rawc" not in special:
                    # *c.cpp
                    fc.write(ns.upper() + "_API " +
                             (rtype.rc_type if rtype else "void"))
                    fc.write(
                        " " + fname + "(" +
                        ", ".join(list((a.c for a in args +
                                        (oint("ierr"), )))) + ")\n{\n")
                    if rtype:
                        fc.write("  " + rtype.rc_type + " result_api_ = 0;\n")
                    fc.write("  if(ierr) *ierr = 0;\n")
                    fc.write("  try {\n")
                    fc.write("".join((a.c_pre for a in args)))
                    fc.write("    ")
                    if rtype:
                        fc.write("result_api_ = ")
                    fc.write(cpp_namespace + name + "(" +
                             ", ".join(list((a.c_arg for a in args))) + ");\n")
                    fc.write("".join((a.c_post for a in args)))
                    fc.write("  }\n  catch(...){\n    " +
                             "if(ierr) *ierr = 1;\n  }\n")
                    if rtype:
                        fc.write("  return result_api_;\n")
                    fc.write("}\n\n")
                # *.h_cwrap
                fcwrap.write(
                    indent + "// " + cpp_namespace + name + "\n" + indent + "//\n")
                fcwrap.write(
                    indent + "// " + ("\n" + indent + "// ").join(
                        textwrap.wrap(doc, 80 - len(indent))) + "\n")
                rt = rtype.rcpp_type if rtype else "void"
                fnameapi = indent + "inline " + rt + " " + name + "("
                fcwrap.write(fnameapi)
                if args:
                    fcwrap.write(
                        (",\n" + ' ' * len(fnameapi)).join(a.cpp
                                                           for a in args))
                fcwrap.write(")\n" + indent + "{\n" + indent +
                             "  int ierr = 0;\n")
                for a in args:
                    if a.cwrap_pre:
                        fcwrap.write(indent + "  " + a.cwrap_pre)
                fcwrap.write(indent + "  ")
                if rtype:
                    fcwrap.write(rt + " result_api_ = ")
                fcwrap.write(fname + "(" + ", ".join((a.cwrap_arg
                                                      for a in args)))
                if args:
                    fcwrap.write(", &ierr);\n")
                else:
                    fcwrap.write("&ierr);\n")
                if name == 'getLastError':  # special case for getLastError() function
                    fcwrap.write(
                        indent + "  " +
                        'if(ierr) throw std::runtime_error("Could not get last error");\n')
                else:
                    fcwrap.write(indent + "  " +
                                 "if(ierr) throwLastError();\n")
                for a in args:
                    if a.cwrap_post:
                        fcwrap.write(indent + "  " + a.cwrap_post)
                if rtype:
                    fcwrap.write(indent + "  " + "return result_api_;\n")
                fcwrap.write(indent + "}\n\n")
            for m in module.submodules:
                write_module(m, c_namespace, cpp_namespace, indent)
            fcwrap.write(indent[:-2] + "} // namespace " + module.name +
                         "\n\n")

        self.current_lineno = 1
        with open(ns + "c.h", "w") as f:
            with open(ns + "c.cpp", "w") as fc:
                with open(ns + ".h_cwrap", "w") as fcwrap:
                    self.fwrite(
                        f,
                        c_header.format(self.copyright, self.issues,
                                        ns.upper(), self.code,
                                        self.version_major, self.version_minor,
                                        self.version_patch, ns,
                                        "\n * ".join(textwrap.wrap(self.description, 80)) +
                                        "\n *\n * "))
                    fc.write(
                        c_cpp_header.format(self.copyright, self.issues, ns,
                                            ns.upper(), self.code))
                    fc.write(cwrap_utils.format(ns, ""))
                    fc.write(c_cpp_utils.format(ns))
                    fc.write("\n")
                    fcwrap.write(
                        cwrap_header.format(self.copyright, self.issues,
                                            ns.upper(), self.code,
                                            self.version_major,
                                            self.version_minor,
                                            self.version_patch, ns,
                                            "\n// ".join(textwrap.wrap(self.description, 80)) +
                                            "\n//\n// "))
                    fcwrap.write("namespace " + ns + " {\n")
                    s = cwrap_utils.format(ns, "inline ").split('\n')
                    for line in s:
                        fcwrap.write("  " + line + "\n")
                    fcwrap.write("  inline void throwLastError()\n")
                    fcwrap.write("  {\n")
                    fcwrap.write('     int ierr = 0;\n')
                    fcwrap.write('     char *api_error_;\n')
                    fcwrap.write(
                        '     gmshLoggerGetLastError(&api_error_, &ierr);\n')
                    fcwrap.write(
                        '     if(ierr) throw std::runtime_error("Could not get last error");\n')
                    fcwrap.write(
                        '     std::string error = std::string(api_error_);\n')
                    fcwrap.write('     gmshFree(api_error_);\n')
                    fcwrap.write('     throw std::runtime_error(error);\n')
                    fcwrap.write("  }\n\n")
                    fcwrap.write("}\n\n")
                    for module in self.modules:
                        write_module(module, "", "", "")
                    self.fwrite(f, c_footer)
                    fcwrap.write(cwrap_footer)

    def write_python(self):
        def parg(a):
            return a.name + (("=" + a.python_value) if a.python_value else "")

        def write_function(f, fun, c_mpath, py_mpath, indent):
            (rtype, name, args, doc, special) = fun
            if "onlycc++" in special: return
            if "nopython" in special: return
            iargs = list(a for a in args if not a.out)
            oargs = list(a for a in args if a.out)
            self.fwrite(f, "\n")
            if c_mpath != ns:
                self.fwrite(f, indent + "@staticmethod\n")
            self.flog('py', py_mpath.replace('.', '/') + name)
            if c_mpath == ns and name == "initialize": # special case for top-level initialize
                self.fwrite(
                    f, indent + "def " + name + "(" + ", ".join(
                        (parg(a) for a in iargs)) + ", interruptible=True):\n")
            else:
                self.fwrite(
                    f, indent + "def " + name + "(" + ", ".join(
                        (parg(a) for a in iargs)) + "):\n")
            ind = indent + "    "
            self.fwrite(f, ind + '"""\n')
            self.fwrite(
                f, ind + py_mpath + name + "(" +
                ", ".join(parg(a) for a in iargs) + ")\n\n")
            self.fwrite(
                f,
                ind + ("\n" + ind).join(textwrap.wrap(doc, 75)) + "\n")
            if rtype or oargs:
                self.fwrite(
                    f, "\n" + ind + "Return " +
                    ", ".join(([("an " if rtype.texi_type ==
                                 "integer" else "a ") +
                                rtype.texi_type] if rtype else []) +
                              [("`" + a.name + "'") for a in oargs]) + ".\n")
            if args:
                self.fwrite(f, "\n" + ind + "Types:")
                for a in args:
                    self.fwrite(f, "\n" + ind + "- `" + a.name + "': " + a.texi_type)
                self.fwrite(f, "\n")
            self.fwrite(f, ind + '"""\n')
            for a in args:
                if a.python_pre: self.fwrite(f, ind + a.python_pre + "\n")
            self.fwrite(f, ind + "ierr = c_int()\n")
            c_name = c_mpath + name[0].upper() + name[1:]
            if rtype is odouble:
                self.fwrite(f, ind + "lib." + c_name + ".restype = c_double\n")
            self.fwrite(
                f, ind + "api_result_ = " if
                ((rtype is oint) or (rtype is odouble)) else (ind))
            self.fwrite(
                f, "lib." + c_name + "(\n    " + ind +
                (",\n" + ind + "    ").join(
                    tuple((a.python_arg
                           for a in args)) + ("byref(ierr)", )) + ")\n")
            if c_mpath == ns: # special cases for top-level initialize/finalize
                if name == "initialize":
                    self.fwrite(f, ind + "if interruptible == True:\n")
                    self.fwrite(
                        f, ind + "    prev_interrupt_handler = signal.signal(signal.SIGINT, signal.SIG_DFL)\n")
                elif name == "finalize":  # special case for finalize()
                    self.fwrite(f, ind + "if prev_interrupt_handler is not None:\n")
                    self.fwrite(
                        f, ind + "    signal.signal(signal.SIGINT, prev_interrupt_handler)\n")
            self.fwrite(f, ind + "if ierr.value != 0:\n")
            if name == "getLastError":  # special case for getLastError() function
                self.fwrite(
                    f, ind +
                    "    raise Exception('Could not get last error')\n")
            else:
                self.fwrite(
                    f, ind + "    raise Exception(logger.getLastError())\n")
            r = (["api_result_"]) if rtype else []
            r += list((o.python_return for o in oargs))
            if len(r) != 0:
                if len(r) == 1:
                    self.fwrite(f, ind + "return " + r[0] + "\n")
                else:
                    self.fwrite(
                        f, ind + "return (\n" + ind + "    " +
                        (",\n" + ind + "    ").join(r) + ")\n")
            # define alias with underscore (standard python style)
            name_ = re.sub('([A-Z]+)', r'_\1', name).lower()
            if name != name_:
                self.fwrite(f, indent + name_ + " = " + name + "\n")

        def write_module(f, m, c_mpath, py_mpath, indent):
            if c_mpath:
                c_mpath += m.name[0].upper() + m.name[1:]
                py_mpath += m.name + "."
            else:
                c_mpath = m.name
                py_mpath = m.name + "."
            for fun in m.fs:
                write_function(f, fun, c_mpath, py_mpath, indent)
            for module in m.submodules:
                self.fwrite(f,
                            "\n\n" + indent + "class " + module.name + ":\n")
                indentm = indent + "    "
                self.fwrite(f, indentm + '"""\n')
                self.fwrite(
                    f, indentm + ("\n" + indentm).join(
                        textwrap.wrap(capi(module.doc), 75)) + "\n")
                self.fwrite(f, indentm + '"""\n')
                write_module(f, module, c_mpath, py_mpath, indentm)

        self.current_lineno = 1
        with open(ns + ".py", "w") as f:
            self.fwrite(
                f,
                python_header.format(self.copyright, self.issues, self.code,
                                     self.version_major, self.version_minor,
                                     self.version_patch, ns.upper(), ns,
                                     "\n".join(textwrap.wrap(self.description, 80))))
            for module in self.modules:
                write_module(f, module, "", "", "")

    def write_julia(self):
        def parg(a):
            return a.name + ((" = " + a.julia_value) if a.julia_value else "")

        def write_function(f, fun, c_mpath, jl_mpath):
            (rtype, name, args, doc, special) = fun
            if "onlycc++" in special: return
            if "nojulia" in special: return
            iargs = list(a for a in args if not a.out)
            oargs = list(a for a in args if a.out)
            self.fwrite(f, '\n"""\n    ')
            self.fwrite(
                f, jl_mpath + name + "(" + ", ".join(parg(a)
                                                     for a in iargs) + ")\n\n")
            self.fwrite(
                f, "\n".join(textwrap.wrap(doc, 80)).replace("'", "`") + "\n")
            if rtype or oargs:
                self.fwrite(
                    f, "\nReturn " +
                    ", ".join(([("an " if rtype.texi_type ==
                                 "integer" else "a ") +
                                rtype.texi_type] if rtype else []) +
                              [("`" + a.name + "`") for a in oargs]) + ".\n")
            if args:
                self.fwrite(f, "\nTypes:")
                for a in args:
                    self.fwrite(f, "\n - `" + a.name + "`: " + a.texi_type)
                self.fwrite(f, "\n")
            self.fwrite(f, '"""\n')
            self.flog('jl', jl_mpath.replace('.', '/') + name)
            self.fwrite(
                f, "function " + name + "(" + ", ".join(
                    (parg(a) for a in iargs)) + ")\n")
            for a in args:
                if a.julia_pre: self.fwrite(f, "    " + a.julia_pre + "\n")
            self.fwrite(f, "    ierr = Ref{Cint}()\n    ")
            self.fwrite(
                f, "api_result_ = " if
                ((rtype is oint) or (rtype is odouble)) else "")
            c_name = c_mpath + name[0].upper() + name[1:]
            self.fwrite(
                f, "ccall((:" + c_name + ", " +
                ("" if c_mpath == ns else ns + ".") + "lib), " +
                ("Cvoid" if rtype is None else rtype.rjulia_type) + ",\n" +
                " " * 10 + "(" + ", ".join(
                    (tuple(a.julia_ctype for a in args) + ("Ptr{Cint}", ))) +
                ("," if not len(args) else "") + "),\n" + " " * 10 +
                ", ".join(tuple(a.julia_arg
                                for a in args) + ("ierr", )) + ")\n")
            if name == "getLastError":  # special case for getLastError() function
                self.fwrite(
                    f,
                    '    ierr[] != 0 && error("Could not get last error")\n')
            else:
                self.fwrite(
                    f,
                    '    ierr[] != 0 && error(gmsh.logger.getLastError())\n')
            for a in args:
                if a.julia_post: self.fwrite(f, "    " + a.julia_post + "\n")
            r = (["api_result_"]) if rtype else []
            r += list((o.julia_return for o in oargs))
            self.fwrite(f, "    return ")
            if len(r) == 0:
                self.fwrite(f, "nothing")
            else:
                self.fwrite(f, ", ".join(r))
            self.fwrite(f, "\nend\n")
            # define alias with underscore (closer to Julia style)
            name_ = re.sub('([A-Z]+)', r'_\1', name).lower()
            if name != name_:
                self.fwrite(f, "const " + name_ + " = " + name + "\n")

        def write_module(f, m, c_mpath, jl_mpath, level):
            self.fwrite(f, '\n"""\n    ')
            self.fwrite(f, "module " + jl_mpath + m.name + "\n\n")
            if level == 1:
                self.fwrite(f, "\n".join(textwrap.wrap(self.description, 80)) + "\n")
                self.fwrite(f, "\nThis module defines the {0} Julia API.\n".format(
                    ns.capitalize()))
            else:
                self.fwrite(f, "\n".join(textwrap.wrap(capi(m.doc), 80)) + "\n")
            self.fwrite(f, '"""\n')
            self.fwrite(f, "module " + m.name + "\n\n")
            if level == 1:
                self.fwrite(
                    f, 'const {0}_API_VERSION = "{1}.{2}.{3}"\n'.format(
                        ns.upper(), self.version_major, self.version_minor,
                        self.version_patch))
                self.fwrite(
                    f, 'const {0}_API_VERSION_MAJOR = {1}\n'.format(
                        ns.upper(), self.version_major))
                self.fwrite(
                    f, 'const {0}_API_VERSION_MINOR = {1}\n'.format(
                        ns.upper(), self.version_minor))
                self.fwrite(
                    f, 'const {0}_API_VERSION_PATCH = {1}\n'.format(
                        ns.upper(), self.version_patch))
                self.fwrite(f, 'const libdir = dirname(@__FILE__)\n')
                self.fwrite(
                    f, 'const libname = Sys.iswindows() ? "' + ns +
                    '-{0}.{1}'.format(self.version_major, self.version_minor) +
                    '.dll" : "lib' + ns + '"\n')
                self.fwrite(f, 'import Libdl\n')
                self.fwrite(
                    f, 'const lib = Libdl.find_library([libname], [libdir])\n')
            else:
                self.fwrite(f, "import " + ("." * level) + ns + "\n")
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
            self.fwrite(f, "\nend # end of module " + m.name + "\n")

        self.current_lineno = 1
        with open(ns + ".jl", "w") as f:
            self.fwrite(
                f,
                julia_header.format(self.copyright, self.issues, self.code,
                                    self.version_major, self.version_minor,
                                    self.version_patch))
            for module in self.modules:
                write_module(f, module, "", "", 1)

    def write_fortran(self):
        types_list = []

        def get_fname(name):
            return name[0].upper() + name[1:]

        def get_fc_name_t(name, c_mpath, f_mpath):
            f_mpath += name + "_"
            if c_mpath:
                c_mpath += get_fname(name)
            else:
                c_mpath = name
            return c_mpath, f_mpath

        def write_type_vars(m, c_mpath, f_mpath, indent):
            r = ""
            for var in m.submodules:
                c_mpath_l, f_mpath_l = get_fc_name_t(var.name, c_mpath, f_mpath)
                r += f"{indent}type({f_mpath_l}t) :: {var.name}\n"
            return r

        def generate_procedures(m, c_mpath, indent):
            r = ""
            for fun in m.fs:
                (_, name, _, _, _) = fun
                fname = c_mpath + get_fname(name)
                r += f"{indent}procedure, nopass :: {name} => &\n{indent*2}{fname}\n"
            return r

        def generate_ftypes(f, m, c_mpath, f_mpath, indent):
            c_mpath, f_mpath = get_fc_name_t(m.name, c_mpath, f_mpath)
            r = f"{indent}type, public :: {f_mpath}t\n"
            r += write_type_vars(m, c_mpath, f_mpath, indent * 2)
            r += f"{indent * 2}contains\n"
            r += generate_procedures(m, c_mpath, indent * 2)
            r += f"{indent}end type {f_mpath}t\n"
            # Save the types in a list
            types_list.append(r)

            for ftype in m.submodules:
                generate_ftypes(f, ftype, c_mpath, f_mpath, indent)

        def write_function(f, fun, c_mpath, f_mpath, indent):
            def get_arg_list(args, indent):
                arg_list = ""
                for arg in args:
                    # These lists contain only a single element = arg.value
                    for t, a in zip(arg.fortran_types, arg.fortran_args):
                        if arg.value:
                            t += ", optional"
                        arg_list += f"{indent}{t} :: {a}\n"
                arg_list += f"{indent}integer(c_int), intent(out), optional :: ierr\n"
                return arg_list

            def get_c_api_arg_list(args, indent):
                arg_list = ""
                for arg in args:
                    # These lists can contain multiple elements e.g. array, array_n
                    for t, a in zip(arg.fortran_c_api, arg.fortran_c_args):
                        # Passing by VALUE cannot be OPTIONAL
                        if arg.value and not (", value" in t):
                            t += f", optional"
                        arg_list += f"{indent}{t} :: {a}\n"
                arg_list += f"{indent}integer(c_int), intent(out), optional :: ierr_\n"
                return arg_list

            def get_dummy_arg_list(args):
                dummy_list = ""
                for arg in args:
                    for a in arg.fortran_args:
                        dummy_list += f"{a}, &"
                dummy_list += "ierr"
                return dummy_list

            def get_c_api_call(args):
                dummy_list = ""
                for arg in args:
                    if arg.fortran_call:
                        dummy_list += f"{arg.fortran_call}, &"
                    else:
                        # These are single element lists
                        for c, a in zip(arg.fortran_c_args, arg.fortran_args):
                            dummy_list += f"{c}={a}, &"
                dummy_list += "ierr_=ierr"
                return dummy_list

            def get_c_api_dummy_arg_list(args):
                dummy_list = ""
                for arg in args:
                    for a in arg.fortran_c_args:
                        dummy_list += f"{a}, &"
                dummy_list += "ierr_"
                return dummy_list

            def write_c_interface(args, rtype, fname, indent):
                proc_type = "function" if rtype else "subroutine"
                dummy_list = get_c_api_dummy_arg_list(args)
                r = f"{indent * 2}interface\n"
                r += f"{indent * 2}{proc_type} C_API({dummy_list})".replace(
                    "&", f"&\n{(len(indent * 2+proc_type+' C_API('))*' '}"
                )
                r += f" &\n{indent * 3}bind(C, name=\"{fname}\")\n"
                r += f"{indent * 3}use, intrinsic :: iso_c_binding\n"
                if rtype:
                    r += f"{indent * 3}{rtype.fortran_c_api[0]} :: C_API\n"

                r += get_c_api_arg_list(args, indent * 3)
                r += f"{indent * 2}end {proc_type} C_API\n"
                r += f"{indent * 2}end interface\n"
                return r

            def get_local_variables(args, indent):
                r = ""
                for a in args:
                    if a.fortran_local:
                        for var in a.fortran_local:
                            r += f"{indent}{var}\n"
                return r

            def get_local_setup(args, indent):
                r = ""
                for a in args:
                    if a.fortran_pre:
                        r += f"{indent}{a.fortran_pre}\n"
                return r

            def get_local_cleanup(args, indent):
                r = ""
                for a in args:
                    if a.fortran_post:
                        r += f"{indent}{a.fortran_post}\n"
                return r

            (rtype, name, args, doc, special) = fun
            fname = c_mpath + get_fname(name)
            # Documentation (Doxygen)
            self.fwrite(
                f, f"\n{indent}!> " +
                (f"\n{indent}!! ").join(textwrap.wrap(doc, 75)) + "\n")

            # Procedure declaration
            proc_type = "function" if rtype else "subroutine"
            fnamef = f"{proc_type} {fname}"
            dummy_list = get_dummy_arg_list(args)
            r = f"{indent}{fnamef}({dummy_list})\n".replace(
                    "&", f"&\n{(len(indent+fnamef)+1)*' '}"
                )
            r += write_c_interface(args, rtype, fname, indent)
            if rtype:
                r += f"{indent * 2}{rtype.fortran_types[0]} :: {fname}\n"
            r += get_arg_list(args, indent * 2)
            # r += f"{indent * 2}! Local variables\n"
            # Prepare input arguments
            r += get_local_variables(args, indent * 2)
            r += get_local_setup(args, indent * 2).replace("&", f"&\n{indent*3}")
            # call the C function
            dummy_list = get_c_api_call(args)
            if rtype:
                r += f"{indent * 2}{fname} = C_API({dummy_list})\n".replace(
                    "&", f"&\n{(len(indent*2)+len(fname)+3)*' '}"
                )
            else:
                r += f"{indent * 2}call C_API({dummy_list})\n".replace(
                    "&", f"&\n{(len(indent*2)+5)*' '}"
                )
            # Prepare output arguments
            # r += f"{indent * 2}! Post processing\n"
            r += get_local_cleanup(args, indent * 2).replace("&", f"&\n{indent * 3}")
            r += f"{indent}end {fnamef}\n"
            self.fwrite(f, r)

        def write_module(f, m, c_mpath, f_mpath, indent):
            c_mpath, f_mpath = get_fc_name_t(m.name, c_mpath, f_mpath)
            for fun in m.fs:
                write_function(f, fun, c_mpath, f_mpath, indent)
            for m in m.submodules:
                write_module(f, m, c_mpath, f_mpath, indent)

        self.current_lineno = 1
        with open(ns + ".f90", "w") as f:
            self.fwrite(
                f,
                fortran_header.format(self.copyright, self.issues, ns.upper(),
                                      self.code, self.version_major,
                                      self.version_minor, self.version_patch,
                                      "\n! ".join(textwrap.wrap(self.description, 80)) +
                                      "\n!\n! "))
            indent = " " * 2
            for ftype in self.modules:
                generate_ftypes(f, ftype, "", "", indent)
            # Write types in reverse since they have to be defined before use
            for ftype in reversed(types_list):
                self.fwrite(f, ftype)
                self.fwrite(f, "\n")
            self.fwrite(f, f"{indent}contains\n")
            for module in self.modules:
                write_module(f, module, "", "", indent)
            self.fwrite(f, fortran_footer)


    def write_texi(self):
        def tryint(s):
            try:
                return int(s)
            except:
                return s

        def alphanum_key(s):
            return [tryint(c) for c in re.split('([0-9]+)', s)]

        def get_file_data(path, ext):
            data = []
            for r, d, f in os.walk(path):
                for file in f:
                    if file.endswith(ext):
                        filename = os.path.join(r, file)
                        contents = []
                        for line in open(filename, 'r'):
                            contents.append(line)
                        data.append([filename, contents])
            data.sort(key=lambda x: alphanum_key(x[0]))
            return data

        def find_function(lang, name, data):
            only_unique = False  # only report unique matches?
            in_comments = False  # report matches in comments?
            if lang == 'Python':
                func = name.replace('/', '.')
                comment = '#'
            else:
                func = name.replace('/', '::')
                comment = '//'
            match = []
            unique = set()
            for file in data:
                l = 0
                for line in file[1]:
                    l = l + 1
                    # allow white space between func name and (
                    if re.search(func + '\\s*\\(', line):
                        strip = re.sub(r'\s+', '', line)
                        # don't report matches in comments
                        if not in_comments and strip.startswith(comment):
                            continue
                        # only report a given match once
                        if (not only_unique) or (strip not in unique):
                            match.append((file[0], l))
                            unique.add(strip)
                            break  # report only one match per file
                        else:
                            unique.add(strip)
            return match

        def write_module(module, path, node, node_next, node_prev, cpp_data,
                         py_data):
            f.write("@node " + node + ", " + node_next + ", " + node_prev +
                    ", Gmsh application programming interface\n")
            f.write("@section Namespace @code{" + path + "}: " + module.doc +
                    "\n\n")
            f.write("@ftable @code\n")
            for rtype, name, args, doc, special in module.fs:
                tfull = path + '/' + name
                if len(tfull) > 40:  # insert discretionary hyphen if too long
                    for i in range(40, len(tfull)):
                        if tfull[i].isupper():
                            tfull = tfull[:i] + '@-' + tfull[i:]
                            break
                f.write("@item " + tfull + "\n")
                tdoc = doc.replace("`", "@code{").replace("'", "}")
                tdoc = re.sub(r'"([a-zA-Z ]+)" chapter of the Gmsh reference manual \((.+)\)',
                              r'@url{\2,"\1" chapter of the Gmsh reference manual}',
                              tdoc)
                f.write(tdoc + "\n\n")
                f.write("@table @asis\n")
                iargs = list(a for a in args if not a.out)
                oargs = list(a for a in args if a.out)
                f.write("@item " + "Input:\n" + (", ".join(
                    ("@code{" + iarg.texi + "} (" + iarg.texi_type + ")")
                    for iarg in iargs) if len(iargs) else "-") + "\n")
                f.write("@item " + "Output:\n" + (", ".join(
                    ("@code{" + oarg.name + "} (" + oarg.texi_type + ")")
                    for oarg in oargs) if len(oargs) else "-") + "\n")
                f.write("@item " + "Return:\n" +
                        (rtype.texi_type if rtype else "-") + "\n")
                f.write("@item " + "Language-specific definition:\n")
                f.write("@url{@value{GITLAB-PREFIX}/api/gmsh.h#L" +
                        str(self.api_lineno['cpp'][path + '/' + name]) +
                        ",C++}")
                f.write(", @url{@value{GITLAB-PREFIX}/api/gmshc.h#L" +
                        str(self.api_lineno['c'][path + '/' + name]) + ",C}")
                try:
                    f.write(", @url{@value{GITLAB-PREFIX}/api/gmsh.py#L" +
                            str(self.api_lineno['py'][path + '/' + name]) +
                            ",Python}")
                except:
                    pass
                try:
                    f.write(", @url{@value{GITLAB-PREFIX}/api/gmsh.jl#L" +
                            str(self.api_lineno['jl'][path + '/' + name]) +
                            ",Julia}")
                except:
                    pass
                f.write("\n")
                cpp = find_function('C++', path + '/' + name, cpp_data)
                py = find_function('Python', path + '/' + name, py_data)

                def write_matches(lang, matches, max_matches):
                    f.write(lang + ' (')
                    for i in range(min(max_matches,
                                       len(matches))):  # write max 5 matches
                        if i > 0: f.write(', ')
                        f.write('@url{@value{GITLAB-PREFIX}/' +
                                matches[i][0][3:] + '#L' + str(matches[i][1]) +
                                ',' + os.path.basename(matches[i][0]) + '}')
                    if len(matches) > max_matches: f.write(', ...')
                    f.write(')')

                if len(cpp) or len(py):
                    f.write("@item " + "Examples:\n")
                    if len(cpp):
                        write_matches("C++", cpp, 5)
                        if len(py): f.write(', ')
                    if len(py):
                        write_matches("Python", py, 5)
                    f.write("\n")
                f.write("@end table\n\n")
            f.write("@end ftable\n\n")

        with open("../doc/texinfo/api.texi", "w") as f:
            f.write(
                "@c This file was generated by api/gen.py: do not edit manually!\n\n"
            )

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
            cpp_data = get_file_data('../tutorials', '.cpp')
            cpp_data.extend(get_file_data('../exampls/api', '.cpp'))
            py_data = get_file_data('../tutorials', '.py')
            py_data.extend(get_file_data('../examples/api', '.py'))
            for i in range(N):
                write_module(flat[i][0], flat[i][1], node_name(flat[i]),
                             "" if i == N - 1 else node_name(flat[i + 1]),
                             "" if i == 0 else node_name(flat[i - 1]),
                             cpp_data, py_data)
