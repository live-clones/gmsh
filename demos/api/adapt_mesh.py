import numpy as np
import sys
import gmsh

class myVertex:
    def __init__(self, tag, x, y, z):
        self.tag = tag; self.x = x; self.y = y; self.z = z;
    def distance(self, other):
        return np.sqrt((self.x - other.x)**2 +
                       (self.y - other.y)**2 + 
                       (self.z - other.z)**2)

class myElement:
    def __init__(self, tag, vertices, qu, qv, qw, qweight, qx, qy, qz, qdet, qjac):
        self.tag = tag; self.vertices = vertices
        self.qu = qu; self.qv = qv; self.qw = qw; self.qweight = qweight
        self.qx = qx; self.qy = qy; self.qz = qz; 
        self.qdet = qdet; self.qjac = qjac
    def maxEdge(self):
        if(len(self.vertices) == 3):
            a = self.vertices[0].distance(self.vertices[1]);
            b = self.vertices[0].distance(self.vertices[2]);
            c = self.vertices[1].distance(self.vertices[2]);
            return max(a, b, c)
        else:
            print "maxEdge only implemented for 3-node triangles"
            exit(1)

class myMesh:
    def __init__(self):
        vtags, vxyz, _ = gmsh.model.mesh.getVertices()
        etypes, etags, evtags = gmsh.model.mesh.getElements()
        quvw, qdata, fsComp, fsData = gmsh.model.mesh.getIntegrationData("Gauss2", "None")
        self.vertices = {}
        for i in range(len(vtags)):
            self.vertices[vtags[i]] = myVertex(
                vtags[i], vxyz[3*i], vxyz[3*i+1], vxyz[3*i+2])
        self.elements = {}
        for i in range(len(etypes)):
            nev = len(evtags[i]) / len(etags[i])
            nq = len(quvw[i]) / 4
            qu = quvw[i][0::4]; qv = quvw[i][1::4]; qw = quvw[i][2::4]; 
            qweight = quvw[i][3::4]
            for j in range(len(etags[i])):
                ev = [self.vertices[k] for k in evtags[i][nev*j:nev*(j+1)]]
                qx = []; qy = []; qz = []; qdet = []; qjac = []
                for k in range(13*nq*j, 13*nq*(j+1), 13):
                    qx.append(qdata[i][k]); 
                    qy.append(qdata[i][k+1]);
                    qz.append(qdata[i][k+2])
                    qdet.append(qdata[i][k+3])
                    qjac.extend(list(qdata[i][k+4:k+13]))
                self.elements[etags[i][j]] = myElement(
                    etags[i][j], ev, qu, qv, qw, qweight, qx, qy, qz, qdet, qjac)

def myFunction(x, y, z):
    a = 6*(np.sqrt((x-.5)**2+(y-.5)**2)-.2)
    return np.real(np.arctanh(a+0j))
    #return (x*y)**2

def computeInterpolationError(mesh, f):
    # evaluate f at the vertices
    f_nod = {}
    for tag, v in mesh.vertices.items():
        f_nod[tag] = f(v.x, v.y, v.z)
    # compute the interpolation error on the elements
    err_ele = {}
    for tag, e in mesh.elements.items():
        if(len(e.vertices) == 3):
            err = 0.
            t0 = e.vertices[0].tag 
            t1 = e.vertices[1].tag 
            t2 = e.vertices[2].tag
            for i in range(len(e.qweight)):
                u = e.qu[i]; v = e.qv[i]; w = e.qw[i]
                weight = e.qweight[i];
                x = e.qx[i]; y = e.qy[i]; z = e.qz[i]
                det = np.abs(e.qdet[i])
                f_fem = f_nod[t0]*(1-u-v) + f_nod[t1]*u + f_nod[t2]*v
                err = err + (f(x, y, z) - f_fem)**2 * det * weight
            err_ele[tag] = np.sqrt(err)
    return f_nod, err_ele

def computeSizeField(mesh, err, N):
    a = 2.
    d = 2.
    fact = 0.
    for tag, e in err.items():
        fact = fact + e**(2./(1.+a))
    fact = fact * (a**((2.+a)/(1.+a)) + a**(1./(1.+a)))
    sf = {}
    for tag, e in err.items():
        ri = e**(2./(2.*(1+a))) * a**(1./(d*(1.+a))) * ((1.+a)*N/fact)**(1./d)
        sf[tag] = mesh.elements[tag].maxEdge() / ri
    return sf

print "Usage: adapt_mesh [intial lc] [target #elements] [dump files]"

lc = 0.02;
N = 10000;
dumpfiles = False
if len(sys.argv) > 1: lc = float(sys.argv[1])
if len(sys.argv) > 2: N = int(sys.argv[2])
if len(sys.argv) > 3: dumpfiles = int(sys.argv[3])

gmsh.initialize()
gmsh.option.setNumber("General.Terminal", 1)

# create a geometrical model
gmsh.model.add("square")
square = gmsh.model.occ.addRectangle(0, 0, 0, 1, 1)
gmsh.model.occ.synchronize()

# create intial uniform mesh
pnts = gmsh.model.getBoundary([(2,square)], True, True, True);
gmsh.model.mesh.setSize(pnts, lc)
gmsh.model.mesh.generate(2)
if dumpfiles: gmsh.write("mesh.msh")
mesh = myMesh()

# compute and visualize the interpolation error
f_nod, err_ele = computeInterpolationError(mesh, myFunction)
f_view = gmsh.view.add("nodal function")
gmsh.view.addModelData(f_view, 0, "square", "NodeData", 
                       f_nod.keys(), [[i] for i in f_nod.values()])
if dumpfiles: gmsh.view.write(f_view, "f.pos")
err_view = gmsh.view.add("element-wise error")
gmsh.view.addModelData(err_view, 0, "square", "ElementData", 
                       err_ele.keys(), [[i] for i in err_ele.values()])
if dumpfiles: gmsh.view.write(err_view, "err.pos")

# compute and visualize the remeshing size field
sf_ele = computeSizeField(mesh, err_ele, N)
sf_view = gmsh.view.add("mesh size field")
gmsh.view.addModelData(sf_view, 0, "square", "ElementData", 
                       sf_ele.keys(), [[i] for i in sf_ele.values()])
if dumpfiles: gmsh.view.write(sf_view, "sf.pos")

# create a new model (to remesh the original model in-place, the size field
# should be created as a list-based view)
gmsh.model.add("square2")
gmsh.model.occ.addRectangle(0, 0, 0, 1, 1)
gmsh.model.occ.synchronize()

# mesh the new model using the size field 
bg_field = gmsh.model.mesh.field.add("PostView");
gmsh.model.mesh.field.setNumber(bg_field, "ViewTag", sf_view);
gmsh.model.mesh.field.setAsBackgroundMesh(bg_field);
gmsh.model.mesh.generate(2)
if dumpfiles: gmsh.write("mesh2.msh")
mesh2 = myMesh()

# compute and visualize the interpolation error on the adapted mesh
f2_nod, err2_ele = computeInterpolationError(mesh2, myFunction)
f2_view = gmsh.view.add("nodal function on adapted mesh")
gmsh.view.addModelData(f2_view, 0, "square2", "NodeData", 
                       f2_nod.keys(), [[i] for i in f2_nod.values()])
if dumpfiles: gmsh.view.write(f2_view, "f2.pos")
err2_view = gmsh.view.add("element-wise error on adapated mesh")
gmsh.view.addModelData(err2_view, 0, "square2", "ElementData", 
                       err2_ele.keys(), [[i] for i in err2_ele.values()])
if dumpfiles: gmsh.view.write(err2_view, "err2.pos")

# show everything in the gui
gmsh.fltk.run()

gmsh.finalize()
