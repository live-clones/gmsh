class arg:

    def __init__(self, name, value=None):
        self.name = name
        self.value = value

    @property
    def cpp_value(self):
        if self.value is None:
            return ""
        return " = "+self.value

    @property
    def cpp(self):
        n = self.type_cpp 
        if n[-1] != "&":
            n += " "
        n += self.name
        n += self.cpp_value
        return n

    @property
    def c_cpp_arg(self):
        return self.name

    @property
    def c_cpp_pre(self):
        return ""
    @property
    def c_cpp_post(self):
        return ""
    @property
    def c(self):
        return self.type_c + " " + self.name 

class simplearg(arg):
    def __init__(self,cpptype,ctype,out,name,value):
        self.type_cpp = cpptype
        self.type_c = ctype
        arg.__init__(self,name,value)

class iint(simplearg):
    def __init__(self,name,value=None):
        simplearg.__init__(self,"const int","const int",False,name,value)

class oint(simplearg):
    def __init__(self,name,value=None):
        simplearg.__init__(self,"int &","int*",True,name,value)
    rtype_cpp = "int"
    rtype_c = "int"
    @property
    def c_cpp_arg(self):
        return "*"+self.name

class istring(simplearg):
    def __init__(self,name,value=None):
        simplearg.__init__(self,"const std::string &", "const char*",False,name,value)
    @property
    def cpp_value(self):
        if self.value is None:
            return ""
        return " = \""+self.value+"\""

class ostring(simplearg):
    def __init__(self,name,value=None):
        simplearg.__init__(self,"std::string &","char**",True,name,value)
    @property
    def c_cpp_arg(self):
        return "api_"+self.name+"_"
    @property
    def c_cpp_pre(self):
        return "  std::string "+self.c_cpp_arg +";\n"
    @property
    def c_cpp_post(self):
        return "  *"+self.name+" = strdup("+self.c_cpp_arg+".c_str());\n"

class idouble(simplearg):
    def __init__(self,name,value=None):
        simplearg.__init__(self,"const double","const double",False,name,value)

class odouble(simplearg):
    def __init__(self,name,value=None):
        simplearg.__init__(self,"double &","double*",True,name,value)
    @property
    def c_cpp_arg(self):
        return "*"+self.name

class ovectorpair(arg):
    def __init__(self,name,value=None):
        arg.__init__(self,name,value)
    type_cpp = "vector_pair &"
    type_c = "int**"
    @property
    def c_cpp_arg(self):
        return "api_"+self.name+"_"
    @property
    def c_cpp_pre(self):
        return "  vector_pair "+self.c_cpp_arg +";\n"
    @property
    def c_cpp_post(self):
        return "  pairvector2intptr("+self.c_cpp_arg+", " + self.name + ", "+self.name+"Size);\n"
    @property
    def c (self):
        return "int** "+self.name+", size_t* "+self.name+"Size"

class ivectorpair(arg):
    def __init__(self,name,value=None):
        arg.__init__(self,name,value)
    type_cpp = "const vector_pair &"
    type_c = "const int*"
    @property
    def c_cpp_arg(self):
        return "intptr2pairvector("+self.name+","+self.name+"Size)"
    @property
    def c (self):
        return "int* "+self.name+", size_t "+self.name+"Size"


class ibool(arg):
    def __init__(self,name,value=None):
        arg.__init__(self,name,value)
    type_cpp = "const bool"
    type_c = "const int"
    
class obool(arg):
    def __init__(self,name,value=None):
        arg.__init__(self,name,value)
    type_cpp = "bool &"
    type_c = "int*"
    @property
    def c_cpp_arg(self):
        return "api_"+self.name+"_"
    @property
    def c_cpp_pre(self):
        return "  bool "+self.c_cpp_arg +";\n"
    @property
    def c_cpp_post(self):
        return "  *"+self.name+" = (int)"+self.c_cpp_arg+";\n"

class ivectorint(arg):
    def __init__(self,name,value=None):
        arg.__init__(self,name,value)
    type_cpp = "const std::vector<int> &"
    type_c = "const int*"
    @property
    def c_cpp_arg(self):
        return "ptr2vector("+self.name+", "+self.name+"Size)"
    @property
    def c (self):
        return "int* "+self.name+", size_t "+self.name+"Size"

class ovectorint(arg):
    def __init__(self,name,value=None):
        arg.__init__(self,name,value)
    type_cpp = "std::vector<int> &"
    type_c = "int**"
    @property
    def c_cpp_arg(self):
        return "api_"+self.name+"_"
    @property
    def c_cpp_pre(self):
        return "  std::vector<int> "+self.c_cpp_arg +";\n"
    @property
    def c_cpp_post(self):
        return "  vector2ptr("+self.c_cpp_arg+", " + self.name + ", "+self.name+"Size);\n"
    @property
    def c (self):
        return "int** "+self.name+", size_t* "+self.name+"Size"


class ovectorvectorint(arg):
    def __init__(self,name,value=None):
        arg.__init__(self,name,value)
    type_cpp = "std::vector<std::vector<int> > &"
    type_c = "int**"
    @property
    def c_cpp_arg(self):
        return "api_"+self.name+"_"
    @property
    def c_cpp_pre(self):
        return "  std::vector<std::vector<int> >"+self.c_cpp_arg +";\n"
    @property
    def c_cpp_post(self):
        return "  vectorvector2ptrptr("+self.c_cpp_arg+", " + self.name + ", "+self.name+"Size, "+self.name+"SizeSize);\n"
    @property
    def c (self):
        return "int*** "+self.name+", size_t** "+self.name+"Size"+", size_t *"+self.name+"SizeSize"

class ovectorvectorpair(arg):
    def __init__(self,name,value=None):
        arg.__init__(self,name,value)
    type_cpp = "std::vector<vector_pair> &"
    type_c = "int**"
    @property
    def c_cpp_arg(self):
        return "api_"+self.name+"_"
    @property
    def c_cpp_pre(self):
        return "  std::vector<vector_pair >"+self.c_cpp_arg +";\n"
    @property
    def c_cpp_post(self):
        return "  pairvectorvector2intptrptr("+self.c_cpp_arg+", " + self.name + ", "+self.name+"Size, "+self.name+"SizeSize);\n"
    @property
    def c (self):
        return "int*** "+self.name+", size_t** "+self.name+"Size"+", size_t *"+self.name+"SizeSize"

class ivectordouble(arg):
    def __init__(self,name,value=None):
        arg.__init__(self,name,value)
    type_cpp = "const std::vector<double> &"
    type_c = "double**"
    @property
    def c_cpp_arg(self):
        return "ptr2vector("+self.name+", "+self.name+"Size)"
    @property
    def c (self):
        return "double* "+self.name+", size_t "+self.name+"Size"

class ovectordouble(arg):
    def __init__(self,name,value=None):
        arg.__init__(self,name,value)
    type_cpp = "std::vector<double> &"
    type_c = "double*"
    @property
    def c_cpp_arg(self):
        return "api_"+self.name+"_"
    @property
    def c_cpp_pre(self):
        return "  std::vector<double> "+self.c_cpp_arg +";\n"
    @property
    def c_cpp_post(self):
        return "  vector2ptr("+self.c_cpp_arg+", " + self.name + ", "+self.name+"Size);\n"
    @property
    def c (self):
        return "double** "+self.name+", size_t* "+self.name+"Size"

class Module:

    def __init__(self, name):
        self.name = name
        self.fs = []

    def add(self,rtype, name, *args):
        self.fs.append((rtype,name,args))

cpp_header="""// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _GMSH_H_
#define _GMSH_H_

// This is the embryo of what will become the Gmsh API.
//
// Don't use it yet, it's not ready:-) We plan to release a first version in
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
#define GMSH_API __declspec(dllexport)
#else
#define GMSH_API
#endif

typedef std::vector<std::pair<int, int> > vector_pair;

GMSH_API void gmshInitialize(int argc, char **argv);
"""

cpp_footer=""" 
#undef GMSH_API

#endif
"""

c_header="""// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _GMSHC_H_
#define _GMSHC_H_

// This is the embryo of what will become the Gmsh API.
//
// Don't use it yet, it's not ready:-) We plan to release a first version in
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

#if defined(WIN32)
#define GMSH_API __declspec(dllexport)
#else
#define GMSH_API
#endif

#include <stdlib.h>

GMSH_API void gmshcInitialize(char argc, char **argv);
"""

c_footer="""
#undef GMSH_API

#endif
"""

c_cpp_header="""// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

extern \"C\" {
    #include "gmshc.h"
}
#include "gmsh.h"
#include <cstring>

template<typename t>
std::vector<t> ptr2vector(const t *p, size_t size) {
  return std::vector<t>(p,p+size);
}

template<typename t>
void vector2ptr(const std::vector<t>&v, t **p, size_t *size) {
  *p = (t*)malloc(sizeof(t)*(v.size()));
  for (size_t i = 0; i < v.size(); ++i){
    (*p)[i] = v[i];
  }
  *size = v.size();
}

void pairvector2intptr(const vector_pair &v, int **p, size_t *size) {
  *p = (int*)malloc(sizeof(int)*(v.size()*2));
  for (size_t i = 0; i < v.size(); ++i){
    (*p)[i*2+0] = v[i].first;
    (*p)[i*2+1] = v[i].second;
  }
  *size = v.size()*2;
}

vector_pair intptr2pairvector(const int *p, size_t size){
  vector_pair v(size);
  for (size_t i = 0; i < size; ++i) {
    v[i].first = p[i*2+0];
    v[i].second = p[i*2+1];
  }
  return v;
}

template<typename t>
void vectorvector2ptrptr(const std::vector<std::vector<t> > &v, t ***p, size_t **size, size_t *sizeSize) {
  *p = (t**)malloc(sizeof(t*)*v.size());
  *size = (size_t*)malloc(sizeof(size_t)*v.size()); 
  for (size_t i = 0; i < v.size(); ++i)
    vector2ptr(v[i], &((*p)[i]), &((*size)[i]));
  *sizeSize = v.size();
}

int** pairvectorvector2intptrptr(const std::vector<vector_pair > &v, int ***p, size_t **size, size_t *sizeSize) {
  *p = (int**)malloc(sizeof(int*)*v.size());
  for (size_t i = 0; i < v.size(); ++i)
    pairvector2intptr(v[i],p[i],size[i]);
  *sizeSize = v.size();
}

void gmshcInitialize(char argc, char **argv){
  gmshInitialize(argc, argv);
}
"""

class API:

    def __init__(self):
        self.modules = []

    def add_module(self, name):
        module = Module(name)
        self.modules.append(module)
        return module

    def write_cpp(self, filename):
        with open(filename+".h","w") as f:
            f.write(cpp_header)
            for module in self.modules:
                f.write("\n")
                f.write("// gmsh"+module.name+"\n")
                for rtype, name, args in module.fs:
                    rt = rtype.rtype_cpp if rtype else "void"
                    f.write("GMSH_API " + rt + " gmsh" + module.name+name+"("+", ".join(
                        list((a.cpp for a in args)))+");\n")
            f.write(cpp_footer)

    def write_c(self,filename):
        with open(filename+".h","w") as f:
            f.write(c_header)
            for module in self.modules:
                f.write("\n")
                f.write("/* gmsh"+module.name+" */\n")
                for rtype, name, args in module.fs:
                    f.write("GMSH_API "+(rtype.rtype_c if rtype else "void"))
                    f.write(" gmshc" + module.name+name+"("
                            +", ".join(list((a.c for a in args+(oint("ierr"),))))
                            + ");\n")
            f.write(c_footer)

        with open(filename+".cc","w") as f:
            f.write(c_cpp_header)
            for module in self.modules:
                f.write("\n")
                f.write("/* gmsh"+module.name+" */\n")
                for rtype, name, args in module.fs:
                    f.write(rtype.rtype_c if rtype else "void")
                    f.write(" gmshc" + module.name+name+"("
                        +", ".join(list((a.c for a in args+(oint("ierr"),))))+"){\n")
                    if rtype:
                        f.write("  "+ rtype.rtype_c + "  result_api_;\n")
                    f.write("  if(ierr) *ierr = 0;\n");
                    f.write("  try {\n");
                    f.write("".join((a.c_cpp_pre for a in args)))
                    if rtype:
                        f.write("  result_api_ = ")
                    f.write("  gmsh" + module.name+name+"("+", ".join(
                        list((a.c_cpp_arg for a in args)))+
                        ");\n")
                    f.write("".join((a.c_cpp_post for a in args)))
                    f.write("  } catch(int api_ierr_) {if (ierr) *ierr = api_ierr_;}\n");
                    if rtype :
                        f.write("  return result_api_;\n");
                    f.write("}\n\n")
