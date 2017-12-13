import numpy as np
import sys
import gmsh


class ElementList :

    def __init__(self, tags, vid, quvw, qweights, qdata) :
        ne = tags.shape[0]
        self.vertices = vid.reshape((ne,-1))
        self.quvw = quvw.reshape([-1,3])
        self.qweights = qweights
        qd = qdata.reshape((-1,13))
        self.qx = qd[:,:3].reshape((ne,-1,3))
        self.qdet = qd[:,3].reshape((ne,-1))
        self.qjac = qd[:,4:]
        self.tags = tags


def triangle_max_edge(mesh,tri):
    x = mesh.vxyz[tri.vertices]
    a = np.sum((x[:,0,:]-x[:,1,:])**2,1)**0.5
    b = np.sum((x[:,0,:]-x[:,2,:])**2,1)**0.5
    c = np.sum((x[:,1,:]-x[:,2,:])**2,1)**0.5
    return np.maximum(a,np.maximum(b,c))
        

class Mesh:

    def __init__(self):
        vtags, vxyz, _ = gmsh.model.mesh.getVertices()
        self.vxyz = vxyz.reshape((-1,3))
        self.vtags = vtags
        self.vmap = dict({j:i for i,j in enumerate(vtags)})
        etypes, etags, evtags = gmsh.model.mesh.getElements()
        quvw, qweights, qdata = gmsh.model.mesh.getIntegrationData("Gauss", 2)
        self.elements = {}
        for i,typ in enumerate(etypes):
            evid = np.array([self.vmap[j] for j in evtags[i]])
            self.elements[typ] = ElementList(etags[i],evid,quvw[i],qweights[i],qdata[i])


def my_function(xyz):
    a = 6*(np.hypot(xyz[:,0]-.5,xyz[:,1]-.5)-.2)
    f = np.real(np.arctanh(a+0j))
    return f


def compute_interpolation_error(mesh, f):
    # evaluate f at the vertices
    f_nod = f(mesh.vxyz)
    # compute the interpolation error on the triangles
    triangles = mesh.elements[2]
    det = np.abs(triangles.qdet)
    fx = f(triangles.qx.reshape([-1,3])).reshape(-1,3)
    u = triangles.quvw
    weights = triangles.qweights[None,:]
    f_tri = f_nod[triangles.vertices]
    sf = np.vstack((1-u[:,0]-u[:,1], u[:,0], u[:,1]))
    f_fem = np.dot(f_tri,sf)
    err_tri = np.sum((f_fem-fx)**2*det*weights,1)
    return f_nod, np.sqrt(err_tri)


def compute_size_field(mesh, elements, err, N):
    a = 2.
    d = 2.
    fact = (a**((2.+a)/(1.+a)) + a**(1./(1.+a))) * np.sum(err**(2./(1.+a)))
    ri = err**(2./(2.*(1+a))) * a**(1./(d*(1.+a))) * ((1.+a)*N/fact)**(1./d)
    return triangle_max_edge(mesh,elements)/ri


print ("Usage: adapt_mesh [intial lc] [target #elements] [dump files]")

lc = 0.02;
N = 10000;
dumpfiles = False
if len(sys.argv) > 1: lc = float(sys.argv[1])
if len(sys.argv) > 2: N = int(sys.argv[2])
if len(sys.argv) > 3: dumpfiles = int(sys.argv[3])

gmsh.initialize()
gmsh.option.setNumber("General.Terminal", 1)

# create a geometrical gmsh.model
gmsh.model.add("square")
square = gmsh.model.occ.addRectangle(0, 0, 0, 1, 1)
gmsh.model.occ.synchronize()

# create intial uniform mesh
pnts = gmsh.model.getBoundary([(2,square)], True, True, True);
gmsh.model.mesh.setSize(pnts, lc)
gmsh.model.mesh.generate(2)
if dumpfiles: gmsh.write("mesh.msh")
mesh = Mesh()

# compute and visualize the interpolation error
f_nod, err_ele = compute_interpolation_error(mesh, my_function)
f_view = gmsh.view.add("nodal function")
gmsh.view.addModelData(f_view, 0, "square", "NodeData", 
        mesh.vtags, f_nod[:,None])
if dumpfiles: gmsh.view.write(f_view, "f.pos")
err_view = gmsh.view.add("element-wise error")
gmsh.view.addModelData(err_view, 0, "square", "ElementData", 
        mesh.elements[2].tags, err_ele[:,None])
if dumpfiles: gmsh.view.write(err_view, "err.pos")

# compute and visualize the remeshing size field
sf_ele = compute_size_field(mesh, mesh.elements[2], err_ele, N)
sf_view = gmsh.view.add("mesh size field")
gmsh.view.addModelData(sf_view, 0, "square", "ElementData", 
        mesh.elements[2].tags, sf_ele[:,None])
if dumpfiles: gmsh.view.write(sf_view, "sf.pos")

# create a new gmsh.model (to remesh the original gmsh.model in-place, the size field
# should be created as a list-based view)
gmsh.model.add("square2")
gmsh.model.occ.addRectangle(0, 0, 0, 1, 1)
gmsh.model.occ.synchronize()

# mesh the new gmsh.model using the size field 
bg_field = gmsh.model.mesh.field.add("PostView");
gmsh.model.mesh.field.setNumber(bg_field, "ViewTag", sf_view);
gmsh.model.mesh.field.setAsBackgroundMesh(bg_field);
gmsh.model.mesh.generate(2)
if dumpfiles: gmsh.write("mesh2.msh")
mesh2 = Mesh()

# compute and visualize the interpolation error on the adapted mesh
f2_nod, err2_ele = compute_interpolation_error(mesh2, my_function)
f2_view = gmsh.view.add("nodal function on adapted mesh")
gmsh.view.addModelData(f2_view, 0, "square2", "NodeData", 
        mesh2.vtags, f2_nod[:,None])
if dumpfiles: gmsh.view.write(f2_view, "f2.pos")
err2_view = gmsh.view.add("element-wise error on adapated mesh")
gmsh.view.addModelData(err2_view, 0, "square2", "ElementData", 
        mesh2.elements[2].tags, err2_ele[:,None])
if dumpfiles: gmsh.view.write(err2_view, "err2.pos")

# show everything in the gui
gmsh.fltk.run()

gmsh.finalize()
