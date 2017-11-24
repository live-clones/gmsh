tmap = {
        'int':'iint',
        'char**':'icharpp',
        'constbool':'ibool',
        'constdouble':'idouble',
        'constint':'iint',
        'conststd::string&':'istring',
        'conststd::vector<double>&':'ivectordouble',
        'conststd::vector<int>&':'ivectorint',
        'conststd::vector<std::vector<double>>&':'ivectorvectordouble',
        'conststd::vector<std::vector<int>>&':'ivectorvectorint',
        'constvector_pair&':'ivectorpair',
        'double&': 'odouble',
        'int&':'oint',
        'std::string&':'ostring',
        'std::vector<double>&':'ovectordouble',
        'std::vector<int>&':'ovectorint',
        'std::vector<std::string>&':'ovectorstring',
        'std::vector<std::vector<int>>&':'ovectorvectorint',
        'std::vector<vector_pair>&':'ovectorvectorpair',
        'vector_pair&':'ovectorpair'
}
def parse_arg(a) :
    value = None
    eq = a.find("=")
    if eq != -1 :
        value = a[eq+1:].strip()
        a = a[:eq].strip()
    p = max(a.rfind(" "), a.rfind("*"), a.rfind("&"), a.rfind(">"))
    name = a[p+1:]
    typ = a[:p+1].replace(" ","")
    return tmap[typ]+"('"+name+"'"+((",'"+value+"'") if value else "")+")"

def parse_fun(f,fun,namespace) :
    iarg =fun.find("(")
    earg =fun.rfind(")")
    pre = fun[:iarg]
    args = fun[iarg+1:earg].split(",")
    w = pre.split()
    t = w[1]
    name = w[2]
    ret = "None"
    if t == "int" :
        ret = "oint"
    elif t != "void" :
        raise NameError("Unknown return type : ", t)
    if (args == ['']) :
        args = []
    if (name in ["initialize","setElements","addModelData"]) :
        f.write("#")
    f.write(namespace+".add("+",".join([ret,"'"+name+"'"]+[parse_arg(a) for a in args])+")\n")

namespace = ["api"]

with open("../Common/gmsh.h") as f :
    with open("gen.py","w") as fo :
        fo.write("from GenApi import *\n\napi = API()\n")
        ls = f.readlines()
        i = 0
        while i < len(ls) :
            l = ls[i].strip()
            w = l.split()
            i += 1
            if not w :
                continue
            if w[0] == "GMSH_API" :
                f = l
                while f[-1] != ";" :
                    l = ls[i].strip()
                    i += 1
                    f += " " + l
                try :
                    parse_fun(fo,f,namespace[-1])
                except :
                    raise NameError(f)
            elif w[0] == "namespace" :
                fo.write("\n"+w[1]+" = "+namespace[-1]+".add_module('"+w[1]+"')\n")
                namespace += [w[1]]
            elif w[0] == "}" :
                namespace.pop()
        fo.write("api.write_cpp()\n")
        fo.write("api.write_c()\n")
        fo.write("api.write_python()\n")
