#!/usr/bin/env python3
"""Put the three pictures of one dialog side by side.

Left is the released Gmsh, which is what the conversion has to reproduce;
then the FLTK interface of this tree, which should be indistinguishable from
it; then the Dear ImGui one, which cannot be identical -- a different toolkit
draws differently -- but should hold the same fields, in the same order, in
the same grouping.

The pictures are pasted at their own size, never scaled: a dialog that came
out twice as tall as the one it replaces has to look twice as tall.
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
        have.append((caption, Image.open(path) if os.path.exists(path) else None))

    big = font(20, bold=True)
    med = font(14)
    small = font(12)

    widths = [max(260, (im.width if im else 0)) for _, im in have]
    height = max((im.height if im else 0) for _, im in have)
    W = sum(widths) + PAD * (len(have) + 1)
    H = HEAD + PAD + height + PAD + 22

    card = Image.new("RGB", (W, H), BG)
    draw = ImageDraw.Draw(card)
    draw.text((PAD, 14), title_of(name), font=big, fill=INK)

    x = PAD
    for column, ((caption, im), w) in enumerate(zip(have, widths)):
        draw.text((x, HEAD - 18), caption, font=med, fill=DIM)
        if im:
            card.paste(im, (x, HEAD + PAD))
            draw.rectangle((x - 1, HEAD + PAD - 1, x + im.width, HEAD + PAD + im.height),
                           outline=(96, 96, 102))
            draw.text((x, HEAD + PAD + height + 4),
                      "%d x %d" % (im.width, im.height), font=small, fill=DIM)
        else:
            # a pane the conversion added has nothing to compare itself to,
            # which is not the same thing as a picture that failed to be taken
            missing = ("(pas dans la version publiée)"
                       if column == 0 and all(i for _, i in have[1:])
                       else "(pas de capture)")
            draw.text((x, HEAD + PAD), missing, font=med, fill=(200, 120, 120))
        x += w + PAD

    card.save(out)
    return card.size


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--shots", required=True)
    ap.add_argument("--out", required=True)
    ap.add_argument("--dialog", action="append", default=[])
    args = ap.parse_args()
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
