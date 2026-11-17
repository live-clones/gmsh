# Draws the model of tiny_model.geo at sizes from 1 to 1e-30 and checks that
# the pictures are those of size 1:
#
#   python tiny_model.py [path/to/gmsh]
#
# Needs a Gmsh built with graphics, and the Python Imaging Library. The
# pictures are made in a temporary directory; a few pixels can differ (the
# coordinates are not scaled exactly), more than 100 is an error.

import os, shutil, subprocess, sys, tempfile
from PIL import Image, ImageChops

gmsh = sys.argv[1] if len(sys.argv) > 1 else 'gmsh'
geo = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'tiny_model.geo')
sizes = ['1', '1e-3', '1e-6', '1e-7', '1e-9', '1e-12', '1e-20', '1e-30']
pictures = ['tiny_model_%d.png' % i for i in range(1, 5)]

def differing(a, b):
    """number of pixels differing by more than 16/255 in a channel"""
    d = ImageChops.difference(Image.open(a).convert('RGB'),
                              Image.open(b).convert('RGB'))
    return sum(1 for p in d.getdata() if max(p) > 16)

tmp = tempfile.mkdtemp()
failed = 0
try:
    shutil.copy(geo, tmp)
    for size in sizes:
        # "-" runs the script without opening the window
        subprocess.run([gmsh, 'tiny_model.geo', '-setnumber', 'L', size,
                        '-v', '1', '-'], cwd=tmp, check=True, timeout=300)
        out = os.path.join(tmp, size)
        os.mkdir(out)
        for p in pictures:
            shutil.move(os.path.join(tmp, p), out)
        n = [differing(os.path.join(tmp, sizes[0], p), os.path.join(out, p))
             for p in pictures]
        ok = max(n) <= 100
        failed += not ok
        print('size %-6s differing pixels %s %s' % (size, n, '' if ok else 'FAILED'))
finally:
    shutil.rmtree(tmp)
sys.exit(1 if failed else 0)
