# Gmsh web app - Copyright (C) 2026 C. Geuzaine and J.-F. Remacle
#
# This program is free software: you can redistribute it and/or modify it under
# the terms of the GNU Affero General Public License as published by the Free
# Software Foundation, either version 3 of the License, or (at your option) any
# later version.
#
# This program is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
# FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more
# details.
#
# You should have received a copy of the GNU Affero General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.

# The second half of a thumbnail of the landing page (see make.sh), drawn
# offscreen by a native Gmsh: the geometry of the model (its .geo, opened
# here), with what run.mjs saved of its run in the web app (its views and
# options), or, for a .geo alone, its mesh. Without the scales, axes and
# graphs that would not read at that size; cropped to what is drawn, then
# reduced to a JPEG of twice the size on the page, for high-density screens
# (with Pillow). Usage:
#
#   python3 render.py <file.geo> <output.jpg> [<run.mjs's directory> <name>
#                     [<options> [<parameters>]]]
#
# with options, in Gmsh's language, applied last (e.g. another view than the
# one the model ends with), and the ONELAB parameters the model was run with
# (name=value;..., see run.mjs), for its geometry; for a .geo alone, the
# directory and name empty.

import os
import sys
import tempfile
import gmsh
from PIL import Image, ImageChops

# drawn at the size of a window, where glyphs and lines have their usual size
# (a 3D model drawn smaller, as Gmsh fits it to the window before it is
# rotated), then cropped and reduced to the size of the thumbnail
W, H = 1200, 900
TW, TH = 480, 360


def main():
    geo, jpg = os.path.abspath(sys.argv[1]), os.path.abspath(sys.argv[2])
    run = len(sys.argv) > 4 and sys.argv[3]
    gmsh.initialize([], False, False)
    gmsh.option.setNumber('General.Terminal', 0)
    gmsh.option.setNumber('General.NoPopup', 1)
    os.chdir(os.path.dirname(geo))
    # (the size first: the model is fitted to it as it is read)
    gmsh.option.setNumber('General.BackgroundGradient', 0)
    gmsh.option.setColor('General.Background', 255, 255, 255)
    gmsh.option.setNumber('General.SmallAxes', 0)
    gmsh.option.setNumber('General.Axes', 0)
    gmsh.option.setNumber('General.GraphicsWidth', W)
    gmsh.option.setNumber('General.GraphicsHeight', H)
    gmsh.option.setNumber('General.DisplayBorderFactor', 0.05)
    gmsh.option.setNumber('Print.Background', 1)
    gmsh.option.setNumber('Print.Width', W)
    gmsh.option.setNumber('Print.Height', H)
    gmsh.option.setNumber('Print.Text', 0)
    if run:
        d, name = os.path.abspath(sys.argv[3]), sys.argv[4]
        params = sys.argv[6] if len(sys.argv) > 6 else ''
        for p in [p for p in params.split(';') if p.strip()]:
            i = p.rindex('=')
            gmsh.onelab.setNumber(p[:i].strip(), [float(p[i + 1:])])
        if geo.endswith('.geo'):
            gmsh.open(os.path.basename(geo))
        else:
            gmsh.merge(os.path.join(d, name + '.msh'))
        i = 1
        while os.path.exists(os.path.join(d, '%s_%d.pos' % (name, i))):
            gmsh.merge(os.path.join(d, '%s_%d.pos' % (name, i)))
            i += 1
        gmsh.merge(os.path.join(d, name + '.opt'))
    else:
        gmsh.open(os.path.basename(geo))
        if gmsh.model.mesh.getNodes()[0].size == 0:
            gmsh.model.mesh.generate(gmsh.model.getDimension())

    # the views as the model left them, but without their scales and titles;
    # graphs and text views hidden
    shown = 0
    for i in range(len(gmsh.view.getTags())):
        v = 'View[%d].' % i
        gmsh.option.setNumber(v + 'ShowScale', 0)
        gmsh.option.setNumber(v + 'Axes', 0)
        if gmsh.option.getNumber(v + 'Type') != 1:
            gmsh.option.setNumber(v + 'Visible', 0)
        shown += gmsh.option.getNumber(v + 'Visible') > 0

    # the mesh: its surfaces, unless views are shown (made again from the
    # .geo for a model whose results are graphs alone)
    gmsh.option.setNumber('Mesh.VolumeEdges', 0)
    gmsh.option.setNumber('Mesh.VolumeFaces', 0)
    if shown:
        gmsh.option.setNumber('Mesh.SurfaceEdges', 0)
    else:
        if gmsh.model.mesh.getNodes()[0].size == 0:
            gmsh.model.mesh.generate(gmsh.model.getDimension())
        gmsh.option.setNumber('Mesh.SurfaceFaces', 1)
        gmsh.option.setNumber('Mesh.ColorCarousel', 0)
        for t in ['Triangles', 'Quadrangles']:
            gmsh.option.setColor('Mesh.Color.' + t, 205, 215, 235)
    gmsh.option.setNumber('Geometry.Points', 0)

    # a 3D model seen from above at an angle, unless it sets its own view
    if gmsh.model.getDimension() == 3 and \
       gmsh.option.getNumber('General.RotationX') == 0 and \
       gmsh.option.getNumber('General.RotationY') == 0 and \
       gmsh.option.getNumber('General.RotationZ') == 0:
        gmsh.option.setNumber('General.Trackball', 0)
        gmsh.option.setNumber('General.RotationX', -60)
        gmsh.option.setNumber('General.RotationZ', -30)
        for x in 'XYZ':
            gmsh.option.setNumber('General.Scale' + x, 0.6)

    # the options of the model's thumbnail, last
    if len(sys.argv) > 5 and sys.argv[5]:
        opt = tempfile.mktemp(suffix='.opt')
        with open(opt, 'w') as f:
            f.write(sys.argv[5] + '\n')
        gmsh.merge(opt)
        os.remove(opt)

    png = tempfile.mktemp(suffix='.png')
    gmsh.write(png)
    gmsh.finalize()

    # cropped to what is drawn, with a margin, in the proportions of the
    # thumbnail
    im = Image.open(png).convert('RGB')
    os.remove(png)
    box = ImageChops.difference(im, Image.new('RGB', im.size, 'white')).getbbox()
    if box:
        im = im.crop(box)
    w, h = im.size
    w, h = max(w, h * TW // TH), max(h, w * TH // TW)
    w, h = int(w * 1.08), int(h * 1.08)
    canvas = Image.new('RGB', (w, h), 'white')
    canvas.paste(im, ((w - im.size[0]) // 2, (h - im.size[1]) // 2))
    canvas.resize((TW, TH), Image.LANCZOS).save(jpg, quality=82, optimize=True)


main()
