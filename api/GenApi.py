class arg:

    def __init__(self,name,value,type_cpp,type_c,out):
        self.name = name
        self.value = value
        self.out = out
        self.type_cpp = type_cpp
        self.type_c = type_c
        self.cpp_value = (" = "+value) if value else ""

        n = self.type_cpp 
        if n[-1] != "&":
            n += " "
        n += self.name
        n += self.cpp_value
        self.cpp = n

        self.c_arg = self.name
        self.c_pre = ""
        self.c_post = ""
        self.c = type_c + " " + name

        self.python_arg = "not_implemented"
        self.python_return = "not_implemented"
        self.python_pre = ""

def iint(name,value=None):
    a = arg(name,value,"const int","const int",False)
    a.python_arg = "c_int("+name+")"
    return a

class oint(arg):
    rtype_cpp = "int"
    rtype_c = "int"
    def __init__(self,name,value=None):
        arg.__init__(self,name,value,"int&","int*",True)
        self.c_arg = "*"+name

def istring(name,value=None):
    value = "\""+value+"\"" if value is not None else None
    a = arg(name,value,"const std::string&","const char*",False)
    a.python_arg = "c_char_p("+name+".encode())"
    return a

def ostring(name,value=None):
    a = arg(name,value,"std::string &","char**",True)
    a.c_arg = "api_"+name+"_"
    a.c_pre = "  std::string "+a.c_arg +";\n"
    a.c_post = "  *"+name+" = strdup("+a.c_arg+".c_str());\n"
    name_ = "api_"+name+"_"
    a.python_pre = name_+" = c_char_p()"
    a.python_arg = "byref("+name_+")"
    a.python_return = "_ostring("+name_+")"
    return a

def idouble(name,value=None):
     a = arg(name,value,"const double","const double",False)
     a.python_arg = "c_double("+name+")"
     return a

def odouble(name,value=None):
    a = arg(name,value,"double&","double*",True)
    a.c_arg = "*"+name
    name_ = "api_"+name+"_"
    a.python_pre = name_+" = c_double()"
    a.python_arg = "byref("+name_+")"
    a.python_return = name_+".value"
    return a

def ovectorpair(name,value=None):
    a = arg(name,value,"vector_pair &","int**",True)
    name_ = "api_"+name+"_"
    name_n = name_ + "n_"
    a.c_arg = name_
    a.c_pre = "  vector_pair "+name_ +";\n"
    a.c_post = "  pairvector2intptr("+name_+"," + name + ","+name_n+");\n"
    a.c = "int** "+name+",size_t* "+name_n
    a.python_pre = name_+", "+name_n+" = POINTER(c_int)(), c_size_t()"
    a.python_arg = "byref("+name_+"),byref("+name_n+")"
    a.python_return = "_ovectorpair("+name_+","+name_n+".value)"
    return a

def ivectorpair(name,value=None):
    a = arg(name,value,"const vector_pair &","const int*",False)
    a.c_arg = "intptr2pairvector("+name+","+name+"_n)"
    a.c = "int* "+name+",size_t "+name+"_n"
    a.python_pre = "api_"+name+"_, api"+name+"_n_ = _ivectorpair("+name+")"
    a.python_arg = "api_"+name+"_, api"+name+"_n_"
    return a

def ibool(name,value=None):
    a = arg(name,value,"const bool","const int",False)
    a.python_arg = "c_int(bool("+name+"))"
    return a
    
def obool(name,value=None):
    a = arg(name,value,"bool &","int*",True)
    a.c_arg = "api_"+name+"_"
    a.c_pre = "  bool "+a.c_arg +";\n"
    a.c_post = "  *"+name+" = (int)"+a.c_arg+";\n"
    return a

def ivectorint(name,value=None):
    a = arg(name,value,"const std::vector<int> &","const int*",False)
    a.c_arg = "ptr2vector("+name+","+name+"_n)"
    a.c = "int* "+name+",size_t "+name+"_n"
    a.python_pre = "api_"+name+"_, api"+name+"_n_ = _ivectorint("+name+")"
    a.python_arg = "api_"+name+"_, api"+name+"_n_"
    return a

def ovectorint(name,value=None):
    a = arg(name,value,"std::vector<int> &","int**",True)
    name_ = "api_"+name+"_"
    name_n = name_ + "n_"
    a.c_arg = name_
    a.c_pre = "  std::vector<int> "+name_ +";\n"
    a.c_post = "  vector2ptr("+name_+"," + name + ","+name_n+");\n"
    a.c = "int** "+name+",size_t* "+name_n
    a.python_pre = name_+", "+name_n+" = POINTER(c_int)(), c_size_t()"
    a.python_arg = "byref("+name_+"),byref("+name_n+")"
    a.python_return = "_ovectorint("+name_+","+name_n+".value)"
    return a

def ivectordouble(name,value=None):
    a = arg(name,value,"const std::vector<double> &","double**",False)
    a.c_arg = "ptr2vector("+name+","+name+"_n)"
    a.c  = "double* "+name+",size_t "+name+"_n"
    a.python_pre = "api_"+name+"_, api"+name+"_n_ = _ivectordouble("+name+")"
    a.python_arg = "api_"+name+"_, api"+name+"_n_"
    return a

def ovectordouble(name,value=None):
    a = arg(name,value,"std::vector<double> &","double*",True)
    name_ = "api_"+name+"_"
    name_n = name_ + "n_"
    a.c_arg = name_
    a.c_pre = "  std::vector<double> "+a.c_arg +";\n"
    a.c_post = "  vector2ptr("+name_+"," + name + ","+name_n+";\n"
    a.c  = "double** "+name+",size_t* "+name+"_n"
    a.python_pre = name_+", "+name_n+" = POINTER(c_double)(), c_size_t()"
    a.python_arg = "byref("+name_+"),byref("+name_n+")"
    a.python_return = "_ovectordouble("+name_+","+name_n+".value)"
    return a

def ovectorvectorint(name,value=None):
    a = arg(name,value,"std::vector<std::vector<int> > &","int**",True)
    name_ = "api_"+name+"_"
    name_n = name_ + "n_"
    name_nn = name_ + "nn_"
    a.c_arg = name_
    a.c_pre = "  std::vector<std::vector<int> > "+a.c_arg +";\n"
    a.c_post = "  vectorvector2ptrptr("+name_+"," + name + ","+name_n+","+name_nn+");\n"
    a.c  = "int*** "+name+",size_t** "+name_n+",size_t *"+name_nn
    a.python_pre = name_+", "+name_n+", "+name_nn +" = POINTER(POINTER(c_int))(), POINTER(c_size_t)(), c_size_t()"
    a.python_arg = "byref("+name_+"),byref("+name_n+"),byref("+name_nn+")"
    a.python_return = "_ovectorvectorint("+name_+","+name_n+","+name_nn+")"
    return a

def ovectorvectorpair(name,value=None):
    a = arg(name,value,"std::vector<vector_pair> &","int**",True)
    name_ = "api_"+name+"_"
    name_n = name_ + "n_"
    name_nn = name_ + "nn_"
    a.c_arg = name_
    a.c_pre = "  std::vector<vector_pair >"+name_ +";\n"
    a.c_post = "  pairvectorvector2intptrptr("+name_+"," + name + ","+name_n+","+name_nn+";\n"
    a.c  = "int*** "+name+",size_t** "+name_n+",size_t *"+name_nn
    a.python_pre = name_+", "+name_n+", "+name_nn +" = POINTER(POINTER(c_int))(), POINTER(c_size_t)(), c_size_t()"
    a.python_arg = "byref("+name_+"),byref("+name_n+"),byref("+name_nn+")"
    a.python_return = "_ovectorvectorpair("+name_+","+name_n+","+name_nn+")"
    return a

class Module:

    def __init__(self,name):
        self.name = name
        self.fs = []

    def add(self,rtype,name,*args):
        self.fs.append((rtype,name,args))

cpp_header="""// Gmsh - Copyright (C) 1997-2017 C. Geuzaine,J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _GMSH_H_
#define _GMSH_H_

// This is the embryo of what will become the Gmsh API.
//
// Don't use it yet,it's not ready:-) We plan to release a first version in
// Gmsh 3.1,and something more complete in Gmsh 4.0.
//
// Your input is welcome: please contribute your ideas on
// https://gitlab.onelab.info/gmsh/gmsh/issues/188
//
// By design,the API is purely functional,and only uses elementary C++ types
// from the standard library. This design should not and will not change.

// All functions return 0 as the first entry of the returned vector on
// successful completion. Additional integer results can be appends to this
// returned value,depending on context.

#include <cmath>
#include <vector>
#include <string>

#if defined(WIN32)
#define GMSH_API __declspec(dllexport)
#else
#define GMSH_API
#endif

typedef std::vector<std::pair<int,int> > vector_pair;

GMSH_API void gmshInitialize(int argc,char **argv);
"""

cpp_footer=""" 
#undef GMSH_API

#endif
"""

c_header="""// Gmsh - Copyright (C) 1997-2017 C. Geuzaine,J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _GMSHC_H_
#define _GMSHC_H_

// This is the embryo of what will become the Gmsh API.
//
// Don't use it yet,it's not ready:-) We plan to release a first version in
// Gmsh 3.1,and something more complete in Gmsh 4.0.
//
// Your input is welcome: please contribute your ideas on
// https://gitlab.onelab.info/gmsh/gmsh/issues/188
//
// By design,the API is purely functional,and only uses elementary C++ types
// from the standard library. This design should not and will not change.

// All functions return 0 as the first entry of the returned vector on
// successful completion. Additional integer results can be appends to this
// returned value,depending on context.

#if defined(WIN32)
#define GMSH_API __declspec(dllexport)
#else
#define GMSH_API
#endif

#include <stdlib.h>

GMSH_API void gmshcInitialize(char argc,char **argv);
GMSH_API void gmshcFree_(void *p);
"""

c_footer="""
#undef GMSH_API

#endif
"""

c_header="""// Gmsh - Copyright (C) 1997-2017 C. Geuzaine,J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

extern \"C\" {
    #include "gmshc.h"
}
#include "gmsh.h"
#include <cstring>

template<typename t>
std::vector<t> ptr2vector(const t *p,size_t size) {
  return std::vector<t>(p,p+size);
}

template<typename t>
void vector2ptr(const std::vector<t>&v,t **p,size_t *size) {
  *p = (t*)malloc(sizeof(t)*(v.size()));
  for (size_t i = 0; i < v.size(); ++i){
    (*p)[i] = v[i];
  }
  *size = v.size();
}

void pairvector2intptr(const vector_pair &v,int **p,size_t *size) {
  *p = (int*)malloc(sizeof(int)*(v.size()*2));
  for (size_t i = 0; i < v.size(); ++i){
    (*p)[i*2+0] = v[i].first;
    (*p)[i*2+1] = v[i].second;
  }
  *size = v.size()*2;
}

vector_pair intptr2pairvector(const int *p,size_t size){
  vector_pair v(size/2);
  for (size_t i = 0; i < size/2; ++i) {
    v[i].first = p[i*2+0];
    v[i].second = p[i*2+1];
  }
  return v;
}

template<typename t>
void vectorvector2ptrptr(const std::vector<std::vector<t> > &v,t ***p,size_t **size,size_t *sizeSize) {
  *p = (t**)malloc(sizeof(t*)*v.size());
  *size = (size_t*)malloc(sizeof(size_t)*v.size()); 
  for (size_t i = 0; i < v.size(); ++i)
    vector2ptr(v[i],&((*p)[i]),&((*size)[i]));
  *sizeSize = v.size();
}

int** pairvectorvector2intptrptr(const std::vector<vector_pair > &v,int ***p,size_t **size,size_t *sizeSize) {
  *p = (int**)malloc(sizeof(int*)*v.size());
  for (size_t i = 0; i < v.size(); ++i)
    pairvector2intptr(v[i],p[i],size[i]);
  *sizeSize = v.size();
}

void gmshcInitialize(char argc,char **argv){
  gmshInitialize(argc,argv);
}

void gmshcFree_(void *p) {
  if(p) free(p);
}
"""

python_header = """from ctypes import *
import signal
import os
signal.signal(signal.SIGINT,signal.SIG_DFL)
libdir = os.path.dirname(os.path.realpath(__file__))
lib = CDLL(libdir+"/libgmshc.so")

use_numpy = False
try :
    import numpy
    use_numpy = True
    try : 
        from weakref import finalize
    except :
        from backports.weakref import finalize
except :
    pass

def Initialize() :
    lib.gmshcInitialize(c_int(0),c_voidp(None))

def _ostring(s) :
    sp = s.value.decode("utf-8")
    lib.gmshcFree_(s)
    return sp

def _ovectorpair(ptr,size):
    if use_numpy :
        v = numpy.ctypeslib.as_array(ptr, (size//2,2))
        finalize(v, lib.gmshcFree_, ptr)
    else :
        v = list((ptr[i*2],ptr[i*2+1]) for i in range(size//2))
        lib.gmshcFree_(ptr)
    return v

def _ovectorint(ptr,size):
    if use_numpy :
        v = numpy.ctypeslib.as_array(ptr, (size,))
        finalize(v, lib.gmshcFree_, ptr)
    else :
        v = list(ptr[i] for i in range(size))
        lib.gmshcFree_(ptr)
    return v

def _ovectordouble(ptr,size):
    if use_numpy :
        v = numpy.ctypeslib.as_array(ptr, (size,))
        finalize(v, lib.gmshcFree_, ptr)
    else :
        v = list(ptr[i] for i in range(size))
        lib.gmshcFree_(ptr)
    return v


def _ovectorvectorint(ptr,size,n):
    v = [_ovectorint(pointer(ptr[i].contents),size[i]) for i in range(n.value)]
    lib.gmshcFree_(size)
    lib.gmshcFree_(ptr)
    return v

def _ovectorvectorpair(ptr,size,n):
    v = [_ovectorpair(pointer(ptr[i].contents),size[i]) for i in range(n.value)]
    lib.gmshcFree_(size)
    lib.gmshcFree_(ptr)
    return v

def _ivectorint(o):
    if use_numpy :
        return  numpy.ascontiguousarray(o,numpy.int32).ctypes, c_size_t(len(o))
    else :
        return byref((c_int*len(o))(*o)), c_size_t(len(o))
        

def _ivectordouble(o):
    if use_numpy :
        return  numpy.ascontiguousarray(o,numpy.float64).ctypes, c_size_t(len(o))
    else :
        return byref((c_double*len(o))(*o)), c_size_t(len(o))

def _ivectorpair(o):
    if use_numpy :
        return  numpy.ascontiguousarray(o,numpy.int32).reshape(len(o),2).ctypes, c_size_t(len(o)*2)
    else :
        return byref(((c_int*2)*len(o))(*o)), c_size_t(len(o)*2)

"""

class API:

    def __init__(self):
        self.modules = []

    def add_module(self,name):
        module = Module(name)
        self.modules.append(module)
        return module

    def write_cpp(self,filename):
        with open(filename+".h","w") as f:
            f.write(cpp_header)
            for module in self.modules:
                f.write("\n")
                f.write("// gmsh"+module.name+"\n")
                for rtype,name,args in module.fs:
                    rt = rtype.rtype_cpp if rtype else "void"
                    f.write("GMSH_API " + rt + " gmsh" + module.name+name+"("+",".join(
                        list((a.cpp for a in args)))+");\n")
            f.write(cpp_footer)

    def write_c(self,filename):
        with open(filename+".h","w") as f:
            f.write(c_header)
            for module in self.modules:
                f.write("\n")
                f.write("/* gmsh"+module.name+" */\n")
                for rtype,name,args in module.fs:
                    f.write("GMSH_API "+(rtype.rtype_c if rtype else "void"))
                    f.write(" gmshc" + module.name+name+"("
                            +",".join(list((a.c for a in args+(oint("ierr"),))))
                            + ");\n")
            f.write(c_footer)

        with open(filename+".cc","w") as f:
            f.write(c_header)
            for module in self.modules:
                f.write("\n")
                f.write("/* gmsh"+module.name+" */\n")
                for rtype,name,args in module.fs:
                    f.write(rtype.rtype_c if rtype else "void")
                    f.write(" gmshc" + module.name+name+"("
                        +",".join(list((a.c for a in args+(oint("ierr"),))))+"){\n")
                    if rtype:
                        f.write("  "+ rtype.rtype_c + " result_api_;\n")
                    f.write("  if(ierr) *ierr = 0;\n");
                    f.write("  try {\n");
                    f.write("".join((a.c_pre for a in args)))
                    f.write("  ")
                    if rtype:
                        f.write("result_api_ = ")
                    f.write("gmsh" + module.name+name+"("+",".join(
                        list((a.c_arg for a in args)))+
                        ");\n")
                    f.write("".join((a.c_post for a in args)))
                    f.write("  } catch(int api_ierr_) {if (ierr) *ierr = api_ierr_;}\n");
                    if rtype :
                        f.write("  return result_api_;\n");
                    f.write("}\n\n")

    def write_python(self) :
        with open("gmsh.py","w") as f :
            f.write(python_header)
            for module in self.modules:
                f.write("\n## gmsh"+module.name + " ##\n")
                for (rtype,name,args) in module.fs:
                    iargs = list(a for a in args if not a.out)
                    oargs = list(a for a in args if a.out)
                    f.write("\ndef "+module.name+name+"("
                            +",".join((a.name for a in iargs))
                            +"):\n")
                    for a in args :
                        if a.python_pre : f.write("    "+a.python_pre+"\n")
                    f.write("    ierr = c_int()\n")
                    f.write("    api__result__ = " if rtype is oint else "    ")
                    f.write("lib.gmshc"+module.name+name+"(\n        "
                            +",\n        ".join(tuple((a.python_arg for a in args))+("byref(ierr)",))
                            +")\n")
                    f.write("    if ierr.value != 0 :\n")
                    f.write("        raise ValueError(\"gmsh."+module.name+name+" returned non-zero error code : \"+ str(ierr.value))\n")
                    r = (["api__result__"]) if rtype else []
                    r += list((o.python_return for o in oargs))
                    if len(r) != 0 :
                        if len(r) == 1 :
                            f.write("    return "+r[0]+"\n")
                        else :
                            f.write("    return (\n        "+",\n        ".join(r)+")\n")
