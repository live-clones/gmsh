class arg :

    def __init__(self, name, value=None) :
        self.name = name
        self.value = value

    @property
    def cpp_value(self) :
        if self.value is None :
            return ""
        return " = "+self.value

    @property
    def cpp(self) :
        n = self.type_cpp 
        if n[-1] != "&" :
            n += " "
        n += self.name
        n += self.cpp_value
        return n

    @property
    def c(self):
        return ""

class simplearg(arg) :
    def __init__(self,cpptype,ctype,out,name,value):
        self.type_cpp = cpptype
        self.type_c = ctype
        arg.__init__(self,name,value)

    @property
    def c(self):
        return self.type_c + " " + self.name 

class vectorarg(arg) :
    def __init__(self,cpptype,ctype,out,name,value):
        self.type_cpp = cpptype
        self.type_c = ctype
        vectorarg.__init__(self,name,value)

class iint(simplearg):
    def __init__(self,name,value=None):
        simplearg.__init__(self,"const int","const int",False,name,value)

class oint(simplearg):
    def __init__(self,name,value=None) :
        simplearg.__init__(self,"int &","int *",True,name,value)

class istring(simplearg) :
    def __init__(self,name,value=None) :
        simplearg.__init__(self,"const std::string &", "const char*",False,name,value)
    @property
    def cpp_value(self) :
        if self.value is None :
            return ""
        return " = \""+self.value+"\""

class ostring(simplearg) :
    def __init__(self,name,value=None) :
        simplearg.__init__(self,"std::string &","char**",True,name,value)

class idouble(simplearg) :
    def __init__(self,name,value=None) :
        simplearg.__init__(self,"const double","const double",False,name,value)

class odouble(simplearg) :
    def __init__(self,name,value=None) :
        simplearg.__init__(self,"double &","double *",True,name,value)

class ovectorpair(arg) :
    def __init__(self,name,value=None) :
        arg.__init__(self,name,value)
    type_cpp = "vector_pair &"

class ivectorpair(arg) :
    def __init__(self,name,value=None) :
        arg.__init__(self,name,value)
    type_cpp = "const vector_pair &"

class ibool(arg) :
    def __init__(self,name,value=None) :
        arg.__init__(self,name,value)
    type_cpp = "const bool"
    
class obool(arg) :
    def __init__(self,name,value=None) :
        arg.__init__(self,name,value)
    type_cpp = "bool &"

class ivectorint(arg) :
    def __init__(self,name,value=None) :
        arg.__init__(self,name,value)
    type_cpp = "const std::vector<int> &"

class ovectorint(arg) :
    def __init__(self,name,value=None) :
        arg.__init__(self,name,value)
    type_cpp = "std::vector<int> &"

class ovectorvectorint(arg) :
    def __init__(self,name,value=None) :
        arg.__init__(self,name,value)
    type_cpp = "std::vector<std::vector<int> > &"

class ovectorvectorpair(arg) :
    def __init__(self,name,value=None) :
        arg.__init__(self,name,value)
    type_cpp = "std::vector<vector_pair> &"

class ivectordouble(arg) :
    def __init__(self,name,value=None) :
        arg.__init__(self,name,value)
    type_cpp = "const std::vector<double> &"

class ovectordouble(arg) :
    def __init__(self,name,value=None) :
        arg.__init__(self,name,value)
    type_cpp = "std::vector<double> &"


class Module :

    def __init__(self, name) :
        self.name = name
        self.fs = []

    def add(self,name, *args) :
        self.fs.append((name,args))

cpp_header="""// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _GMSH_H_
#define _GMSH_H_

// This is the embryo of what will become the Gmsh API.
//
// Don't use it yet, it's not ready :-) We plan to release a first version in
// Gmsh 3.1, and something more complete in Gmsh 4.0.
//
// Your input is welcome: please contribute your ideas on
// https://gitlab.onelab.info/gmsh/gmsh/issues/188
//
// By design, the API is purely functional, and only uses elementary C++ types
// from the standard library. This design should not and will not change.

// All functions return 0 as the first entry of the returned vector on
// successful completion. Additional integer results can be appends to this
// returned value, depending on context.

#include <cmath>
#include <vector>
#include <string>

#if defined(WIN32)
#define GMSH_API __declspec(dllexport) std::vector<int>
#else
#define GMSH_API std::vector<int>
#endif

typedef std::vector<std::pair<int, int> > vector_pair;
"""

cpp_footer=""" 
#undef GMSH_API

#endif
"""

c_header="""
"""

c_footer="""
"""

class API :

    def __init__(self) :
        self.modules = []

    def add_module(self, name):
        module = Module(name)
        self.modules.append(module)
        return module

    def write_cpp(self, filename):
        with open(filename+".h","w") as f :
            f.write(cpp_header)
            for module in self.modules :
                f.write("\n")
                f.write("// gmsh"+module.name+"\n")
                for name, args in module.fs :
                    f.write("GMSH_API gmsh" + module.name+name+"("+", ".join(
                        list((a.cpp for a in args)))+");\n")
            f.write(cpp_footer)

    def write_c(self,filename) :
        with open(filename+".h","w") as f :
            f.write(c_header)
            for module in self.modules :
                f.write("\n")
                f.write("// gmsh"+module.name+"\n")
                for name, args in module.fs :
                    f.write("GMSH_API gmsh" + module.name+name+"("+", ".join(
                        list((a.c for a in args)))+");\n")
            f.write(c_footer)
