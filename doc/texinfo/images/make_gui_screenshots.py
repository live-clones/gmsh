#
# Composes the captures of make_gui_screenshots.cpp into the pictures of the
# manual: "python3 make_gui_screenshots.py <dir>" reads <dir>/<scene>.txt for
# each scene, lays the menus over the main window at their offsets (the
# captures are at twice the logical size on a retina screen), and writes
# <scene>.png scaled to 1280 pixels wide in the current directory
#
import sys
from PIL import Image

d = sys.argv[1] if len(sys.argv) > 1 else 'shots'
for name in ('gui', 'gui_add_rectangle', 'gui_mesh', 'gui_tools'):
    lines = [l.split() for l in open('%s/%s.txt' % (d, name))]
    main = Image.open(lines[0][0]).convert('RGB')
    for f, x, y, w, h, t in lines[1:]:
        if 'Menu_Window' in t:
            im = Image.open(f).convert('RGB')
            main.paste(im, (int(x) * 2, int(y) * 2))
    W = 1280
    H = round(main.height * W / main.width)
    main.resize((W, H), Image.LANCZOS).save(name + '.png')
    print(name + '.png', W, H)
