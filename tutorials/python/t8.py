# ------------------------------------------------------------------------------
#
#  Gmsh Python tutorial 8
#
#  Post-processing and animations
#
# ------------------------------------------------------------------------------

import gmsh
import os
import sys

# In addition to creating geometries and meshes, the Python API can also be used
# to manipulate post-processing datasets (called "views" in Gmsh).

gmsh.initialize()

# We first create a simple geometry
lc = 1e-2
gmsh.model.geo.addPoint(0, 0, 0, lc, 1)
gmsh.model.geo.addPoint(.1, 0, 0, lc, 2)
gmsh.model.geo.addPoint(.1, .3, 0, lc, 3)
gmsh.model.geo.addPoint(0, .3, 0, lc, 4)
gmsh.model.geo.addLine(1, 2, 1)
gmsh.model.geo.addLine(3, 2, 2)
gmsh.model.geo.addLine(3, 4, 3)
gmsh.model.geo.addLine(4, 1, 4)
gmsh.model.geo.addCurveLoop([4, 1, -2, 3], 1)
gmsh.model.geo.addPlaneSurface([1], 1)

gmsh.model.geo.synchronize()

# We merge some post-processing views to work on
path = os.path.dirname(os.path.abspath(__file__))
gmsh.merge(os.path.join(path, os.pardir, 'view1.pos'))
gmsh.merge(os.path.join(path, os.pardir, 'view1.pos'))
gmsh.merge(os.path.join(path, os.pardir, 'view4.pos'))  # contains 2 views inside

# Gmsh can read post-processing views in various formats. Here the `view1.pos'
# and `view4.pos' files are in the Gmsh "parsed" format, which is interpreted by
# the GEO script parser. The parsed format should only be used for relatively
# small datasets of course: for larger datasets using e.g. MSH files is much
# more efficient. Post-processing views can also be created directly from the
# Python API.

# We then set some general options:
gmsh.option.setNumber("General.Trackball", 0)
gmsh.option.setNumber("General.RotationX", 0)
gmsh.option.setNumber("General.RotationY", 0)
gmsh.option.setNumber("General.RotationZ", 0)

white = (255, 255, 255)
black = (0, 0, 0)

# Color options are special
# Setting a color option of "X.Y" actually sets the option "X.Color.Y"
# Sets "General.Color.Background", etc.
gmsh.option.setColor("General.Background", white[0], white[1], white[2])

# We can make our own shorter versions of repetitive methods
set_color = lambda name, c: gmsh.option.setColor(name, c[0], c[1], c[2])
set_color("General.Foreground", black)
set_color("General.Text", black)

gmsh.option.setNumber("General.Orthographic", 0)
gmsh.option.setNumber("General.Axes", 0)
gmsh.option.setNumber("General.SmallAxes", 0)

# Show the GUI:
if '-nopopup' not in sys.argv:
    gmsh.fltk.initialize()

# We also set some options for each post-processing view:

# If we were to follow the geo example blindly, we would read the number of
# views from the relevant option value. A nicer way is to use
# gmsh.view.getTags()
view_tags = [v0, v1, v2, v3] = gmsh.view.getTags()

# View name format helper function: returns "View[index]." for a given view tag
view_fmt = lambda v_tag: "View[" + str(gmsh.view.getIndex(v_tag)) + "]."


# Option setter
def set_opt(name, val):
    # if it's a string, call the string method
    val_type = type(val)
    if val_type == type("str"):
        gmsh.option.setString(name, val)
    # otherwise call the number method
    elif val_type == type(0.5) or val_type == type(1):
        gmsh.option.setNumber(name, val)
    else:
        print("error: bad input to set_opt: " + name + " = " + str(val))
        print("error: set_opt is only meant for numbers and strings, aborting")
        quit(1)


# We'll use this helper function for our views
set_view_opt = lambda v_tag, name, val: set_opt(view_fmt(v_tag) + name, val)

# We set some options for each post-processing view:
# v0
set_view_opt(v0, "IntervalsType", 2)
set_view_opt(v0, "OffsetZ", 0.05)
set_view_opt(v0, "RaiseZ", 0)
set_view_opt(v0, "Light", 1)
set_view_opt(v0, "ShowScale", 0)
set_view_opt(v0, "SmoothNormals", 1)

# v1
set_view_opt(v1, "IntervalsType", 1)
# We can't yet set the ColorTable in API
# gmsh.option.setColorTable(view_opt[v1] + "ColorTable", "{ Green, Blue }")
set_view_opt(v1, "NbIso", 10)
set_view_opt(v1, "ShowScale", 0)

# v2
set_view_opt(v2, "Name", "Test...")
set_view_opt(v2, "Axes", 1)
set_view_opt(v2, "IntervalsType", 2)
set_view_opt(v2, "Type", 2)
set_view_opt(v2, "IntervalsType", 2)
set_view_opt(v2, "AutoPosition", 0)
set_view_opt(v2, "PositionX", 85)
set_view_opt(v2, "PositionY", 50)
set_view_opt(v2, "Width", 200)
set_view_opt(v2, "Height", 130)

# v3
set_view_opt(v3, "Visible", 0)

# You can save an MPEG movie directly by selecting `File->Export' in the
# GUI. Several predefined animations are setup, for looping on all the time
# steps in views, or for looping between views.

# But the API can be used to build much more complex animations, by changing
# options at run-time and re-rendering the graphics. Each frame can then be
# saved to disk as an image, and multiple frames can be encoded to form a
# movie. Below is an example of such a custom animation.

t = 0  # Initial step

for num in range(1, 4):

    # Set time step
    for v in view_tags:
        set_view_opt(v, "TimeStep", t)

    # helper function to match the geo file's +=, -= operators for numbers
    adjust_num_opt =\
    lambda name, diff: set_opt(name, gmsh.option.getNumber(name) + diff)

    current_step = gmsh.option.getNumber(view_fmt(v0) + "TimeStep")
    max_step = gmsh.option.getNumber(view_fmt(v0) + "NbTimeStep") - 1
    if current_step < max_step:
        t = t + 1
    else:
        t = 0

    v0_max = gmsh.option.getNumber(view_fmt(v0) + "Max")
    adjust_num_opt(view_fmt(v0) + "RaiseZ", 0.01 / v0_max * t)

    if num == 3:
        set_opt("General.GraphicsWidth",
                gmsh.option.getNumber("General.MenuWidth") + 640)
        set_opt("General.GraphicsHeight", 480)

    frames = 50
    for num2 in range(frames):
        # Incrementally rotate the scene
        adjust_num_opt("General.RotationX", 10)
        set_opt("General.RotationY",
                gmsh.option.getNumber("General.RotationX") / 3)
        adjust_num_opt("General.RotationZ", 0.1)

        # Draw the scene
        gmsh.graphics.draw()

        # Uncomment the following lines to save each frame to an image file
        # if num == 3:
        #     gmsh.write("t2-{:.2g}.gif".format(num2))
        #     gmsh.write("t2-{:.2g}.ppm".format(num2))
        #     gmsh.write("t2-{:.2g}.jpg".format(num2))

    if num == 3:
        pass
        # Here we could make a system call to generate a movie. For example:
        # import subprocess
        # call_ffmpeg1 = "ffmpeg -hq -r 5 -b 800 -vcodec mpeg1video -i t8-%02d.jpg t8.mpg"
        # call_ffmpeg2 = "ffmpeg -hq -r 5 -b 800 -i t8-%02d.jpg t8.asf"
        # subprocess.call(call_ffmpeg1.split(' '))
        # subprocess.call(call_ffmpeg2.split(' '))

if '-nopopup' not in sys.argv:
    gmsh.fltk.run()

gmsh.finalize()
