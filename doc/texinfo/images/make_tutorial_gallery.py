#
# Just run "python3 make_tutorial_gallery.py" from this directory to create all
# the tutorial screenshots
#

import gmsh

def execfile(filepath, globals=None, locals=None):
    if globals is None:
        globals = {}
    globals.update({
        "__file__": filepath,
        "__name__": "__main__",
    })
    with open(filepath, 'rb') as file:
        exec(compile(file.read(), filepath, 'exec'), globals, locals)

def screenshot():
    gmsh.fltk.run = fltkrun
    gmsh.fltk.initialize = fltkinit
    gmsh.fltk.isAvailable = fltkavail
    gmsh.option.setNumber('General.TrackballQuaternion0', 0.25)
    gmsh.option.setNumber('General.TrackballQuaternion1', -0.1)
    gmsh.option.setNumber('General.TrackballQuaternion2', -0.2)
    gmsh.option.setNumber('General.TrackballQuaternion3', 0.9)
    gmsh.option.setNumber('General.Orthographic', 0)
    gmsh.option.setNumber('General.GraphicsFontSize', 12)
    gmsh.option.setNumber('General.GraphicsFontSizeTitle', 12)
    if gmsh.option.getNumber('PostProcessing.NbViews') > 0:
        gmsh.option.setNumber('Mesh.SurfaceFaces', 0)
        gmsh.option.setNumber('Mesh.ColorCarousel', 0)
    else:
        gmsh.option.setNumber('Mesh.SurfaceFaces', 1)
        gmsh.option.setNumber('Mesh.ColorCarousel', 1)
    gmsh.option.setNumber('Mesh.SmoothNormals', 1)
    gmsh.option.setNumber('Mesh.AngleSmoothNormals', 60)
    gmsh.option.setNumber('Print.Background', 0)
    # 16/9 aspect ratio, width of 512*2 pixels when generated in mac with retina
    # display
    gmsh.option.setNumber('General.GraphicsWidth', 512 +
                          gmsh.option.getNumber('General.MenuWidth'))
    gmsh.option.setNumber('General.GraphicsHeight', 288)
    gmsh.fltk.initialize()
    gmsh.write(tuto + '.png')
    gmsh.fltk.finalize()

def return0():
    return 0

fltkrun = gmsh.fltk.run
fltkinit = gmsh.fltk.initialize
fltkavail = gmsh.fltk.isAvailable

for i in range(1, 22):
    tuto = 't' + str(i)
    gmsh.fltk.run = screenshot
    if i != 8:
        gmsh.fltk.initialize = screenshot
    gmsh.fltk.isAvailable = return0
    execfile('../../../tutorials/python/' + tuto + '.py')
    print("done " + tuto)

for i in range(1, 8):
    tuto = 'x' + str(i)
    gmsh.fltk.run = screenshot
    gmsh.fltk.initialize = screenshot
    gmsh.fltk.isAvailable = return0
    execfile('../../../tutorials/python/' + tuto + '.py')
    print("done " + tuto)
