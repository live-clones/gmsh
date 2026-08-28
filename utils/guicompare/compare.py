#!/usr/bin/env python3
"""Put the three pictures of one dialog side by side.

Left is the released Gmsh, which is what the conversion has to reproduce;
then the FLTK interface of this tree, which should be indistinguishable from
it; then the Dear ImGui one, which cannot be identical -- a different toolkit
draws differently -- but should hold the same fields, in the same order, in
the same grouping.

The pictures are pasted at the same size as each other, never one scaled
against another: a dialog that came out twice as tall as the one it replaces
has to look twice as tall. The sheet as a whole is enlarged by --scale, every
pixel repeated as it is -- a window of 449 pixels is small on a screen of four
thousand, and blurring it to make it bigger would hide the very thing one is
looking at. The size written under each picture is the real one.
"""

import argparse
import os
import re

from PIL import Image, ImageDraw, ImageFont

COLUMNS = [("released", "publié — Gmsh 4.15.2, FLTK 1.3.11"),
           ("fltk", "converti — FLTK 1.4.5"),
           ("imgui", "converti — Dear ImGui")]

DIALOG_TITLES = {
    "elementary": "Elementary Entity Context",
    "physical": "Physical Group Context",
    "transform": "Elementary Operation Context",
    "mesh": "Mesh Context",
    "partition": "Partition",
    "highorder": "High-order tools",
    "manipulator": "Manipulator",
    "statistics": "Statistics",
    "clipping": "Clipping",
    "options": "Options",
    "visibility": "Visibility",
}


def shot_names(shots):
    """Every shot there is a picture of, in any build. Nine panes of the
    elementary dialog have no window at all in the released Gmsh -- picking is
    all it offers there -- so keying this off the released pictures alone would
    leave them without a sheet."""
    seen = []
    for f in sorted(os.listdir(shots)):
        m = re.match(r"(?:released|fltk|imgui)-(.*)\.png$", f)
        if not m:
            continue
        name = m.group(1)
        if name.startswith("probe") or name.endswith("-MISS"):
            continue
        if name not in seen:
            seen.append(name)
    return seen


def title_of(name):
    dialog = name.split("-")[0]
    pane = name[len(dialog) + 1:]
    title = DIALOG_TITLES.get(dialog, dialog)
    return title + (" -- " + pane.replace("-", " ") if pane else "")

# how many screen pixels one pixel of a picture is worth, see --scale
SCALE = 2

BG = (56, 56, 60)
INK = (238, 238, 238)
DIM = (150, 150, 155)
PAD = 16
HEAD = 54


def font(size, bold=False):
    for path in ("/usr/share/fonts/liberation/LiberationSans-%s.ttf"
                 % ("Bold" if bold else "Regular"),
                 "/usr/share/fonts/TTF/DejaVuSans%s.ttf"
                 % ("-Bold" if bold else "")):
        if os.path.exists(path):
            return ImageFont.truetype(path, size)
    return ImageFont.load_default()


def sheet(shots, name, out):
    have = []
    for key, caption in COLUMNS:
        path = os.path.join(shots, "%s-%s.png" % (key, name))
        im = Image.open(path) if os.path.exists(path) else None
        # what it really measures, before it is enlarged
        size = (im.width, im.height) if im else None
        if im and SCALE != 1:
            im = im.resize((im.width * SCALE, im.height * SCALE), Image.NEAREST)
        have.append((caption, im, size))

    pad = PAD * SCALE
    head = HEAD * SCALE
    big = font(20 * SCALE, bold=True)
    med = font(14 * SCALE)
    small = font(12 * SCALE)

    widths = [max(260 * SCALE, (im.width if im else 0)) for _, im, _ in have]
    height = max((im.height if im else 0) for _, im, _ in have)
    W = sum(widths) + pad * (len(have) + 1)
    H = head + pad + height + pad + 22 * SCALE

    card = Image.new("RGB", (W, H), BG)
    draw = ImageDraw.Draw(card)
    draw.text((pad, 14 * SCALE), title_of(name), font=big, fill=INK)

    x = pad
    for column, ((caption, im, size), w) in enumerate(zip(have, widths)):
        draw.text((x, head - 18 * SCALE), caption, font=med, fill=DIM)
        if im:
            card.paste(im, (x, head + pad))
            draw.rectangle((x - 1, head + pad - 1, x + im.width,
                            head + pad + im.height), outline=(96, 96, 102))
            draw.text((x, head + pad + height + 4 * SCALE),
                      "%d x %d" % size, font=small, fill=DIM)
        else:
            # a pane the conversion added has nothing to compare itself to,
            # which is not the same thing as a picture that failed to be taken
            missing = ("(pas dans la version publiée)"
                       if column == 0 and all(i for _, i, _ in have[1:])
                       else "(pas de capture)")
            draw.text((x, head + pad), missing, font=med, fill=(200, 120, 120))
        x += w + pad

    card.save(out)
    return card.size


def main():
    global SCALE
    ap = argparse.ArgumentParser()
    ap.add_argument("--shots", required=True)
    ap.add_argument("--out", required=True)
    ap.add_argument("--dialog", action="append", default=[])
    ap.add_argument("--scale", type=int, default=SCALE,
                    help="how many screen pixels one pixel of a picture is "
                         "worth (default %d); the pixels are repeated, not "
                         "smoothed" % SCALE)
    args = ap.parse_args()
    SCALE = max(1, args.scale)
    os.makedirs(args.out, exist_ok=True)
    # a dialog names every one of its shots; a shot names only itself
    every = shot_names(args.shots)
    wanted = []
    for asked in args.dialog:
        hit = [n for n in every if n == asked or n.startswith(asked + "-")]
        if not hit:
            print("%-12s (rien de tel)" % asked)
        wanted += [n for n in hit if n not in wanted]
    for name in (wanted if args.dialog else every):
        path = os.path.join(args.out, "%s.png" % name)
        print("%-12s %s" % (name, sheet(args.shots, name, path)))


if __name__ == "__main__":
    main()
