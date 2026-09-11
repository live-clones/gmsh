#!/usr/bin/env python3
"""One page holding the whole bench, for looking at it rather than printing it.

compare.py makes one sheet per dialog, which is what you send someone. This
makes a single page that points at the shots where they lie: every dialog, all
four interfaces side by side, with a box to filter by name and a switch to
enlarge the pixels. It is written next to the pictures and read straight off
the disk -- no server, nothing to install.

  utils/guicompare/report.py --shots out/shots --out out/bench.html
"""

import argparse
import os
import re

from compare import COLUMNS, shot_names, title_of

try:
    from PIL import Image
except ImportError:  # the size under each picture is a nicety, not a need
    Image = None


def size_of(path):
    if Image is None:
        return None
    try:
        with Image.open(path) as im:
            return im.size
    except Exception:
        return None


# What each column is, said once here rather than in the markup: the caption
# comes from compare.py so that the two ways of looking at the bench cannot
# drift apart.
NOTE = {
    "released": "ce que la conversion doit reproduire",
    "fltk": "doit être indiscernable de la version publiée",
    "imgui": "un autre toolkit dessine autrement, mais les mêmes champs",
    "browser": "ni widget ni toolkit en commun : la déclaration seule",
}

STYLE = """
:root {
  color-scheme: light dark;
  /* the pale blue the Gmsh viewport is drawn against, taken down to a ground */
  --ground: #eceef3;
  --card: #ffffff;
  --rule: #ccd0da;
  --ink: #171a21;
  --ink-soft: #5c6373;
  --ink-faint: #868d9d;
  --accent: #2f5d8a;
  --accent-soft: #dde6f0;
  --missing: #8a5a2f;
  --missing-soft: #f2e6d8;
  --shadow: 0 1px 2px #171a2114, 0 6px 18px #171a210f;
}
@media (prefers-color-scheme: dark) {
  :root:not([data-theme="light"]) {
    --ground: #14171d;
    --card: #1c2027;
    --rule: #333947;
    --ink: #e8eaef;
    --ink-soft: #a3aab9;
    --ink-faint: #757d8d;
    --accent: #7fb0e0;
    --accent-soft: #22303f;
    --missing: #d3a473;
    --missing-soft: #33291d;
    --shadow: 0 1px 2px #0006, 0 6px 18px #0004;
  }
}
:root[data-theme="dark"] {
  --ground: #14171d;
  --card: #1c2027;
  --rule: #333947;
  --ink: #e8eaef;
  --ink-soft: #a3aab9;
  --ink-faint: #757d8d;
  --accent: #7fb0e0;
  --accent-soft: #22303f;
  --missing: #d3a473;
  --missing-soft: #33291d;
  --shadow: 0 1px 2px #0006, 0 6px 18px #0004;
}

* { box-sizing: border-box; }
body {
  margin: 0;
  background: var(--ground);
  color: var(--ink);
  font: 15px/1.55 ui-sans-serif, system-ui, "Segoe UI", Roboto, sans-serif;
}
code, .num { font-family: ui-monospace, "SFMono-Regular", Menlo, monospace; }

header {
  padding: 34px 32px 26px;
  border-bottom: 1px solid var(--rule);
  background: var(--card);
}
h1 {
  margin: 0 0 6px;
  font-size: 27px;
  font-weight: 620;
  letter-spacing: -0.015em;
  text-wrap: balance;
}
header p { margin: 0; max-width: 62ch; color: var(--ink-soft); }

.counts {
  display: flex;
  flex-wrap: wrap;
  gap: 10px;
  margin-top: 20px;
  list-style: none;
  padding: 0;
}
.counts li {
  border: 1px solid var(--rule);
  border-radius: 3px;
  padding: 7px 12px 8px;
  min-width: 148px;
  background: var(--ground);
}
.counts b {
  display: block;
  font-size: 21px;
  font-weight: 600;
  font-variant-numeric: tabular-nums;
}
.counts span {
  font-size: 11.5px;
  letter-spacing: 0.07em;
  text-transform: uppercase;
  color: var(--ink-faint);
}

.bar {
  position: sticky;
  top: 0;
  z-index: 5;
  display: flex;
  flex-wrap: wrap;
  align-items: center;
  gap: 14px;
  padding: 11px 32px;
  background: color-mix(in srgb, var(--card) 88%, transparent);
  backdrop-filter: blur(8px);
  border-bottom: 1px solid var(--rule);
}
.bar input[type="search"] {
  flex: 1 1 260px;
  max-width: 380px;
  padding: 7px 11px;
  border: 1px solid var(--rule);
  border-radius: 3px;
  background: var(--ground);
  color: inherit;
  font: inherit;
}
.bar label { display: flex; align-items: center; gap: 6px; color: var(--ink-soft); }
.bar .said { margin-left: auto; color: var(--ink-faint); font-size: 13px; }
:focus-visible { outline: 2px solid var(--accent); outline-offset: 2px; }

main { padding: 26px 32px 80px; display: flex; flex-direction: column; gap: 34px; }

section > h2 {
  margin: 0 0 3px;
  font-size: 17px;
  font-weight: 600;
  letter-spacing: -0.01em;
}
section > h2 a { color: var(--ink-faint); text-decoration: none; font-weight: 400; }
section > h2 a:hover { color: var(--accent); }
.shot-name { color: var(--ink-faint); font-size: 12.5px; }

.row {
  display: flex;
  gap: 16px;
  align-items: flex-start;
  overflow-x: auto;
  padding: 12px 0 4px;
}
figure {
  margin: 0;
  flex: 0 0 auto;
  background: var(--card);
  border: 1px solid var(--rule);
  border-radius: 3px;
  box-shadow: var(--shadow);
  overflow: hidden;
}
figcaption {
  display: flex;
  align-items: baseline;
  gap: 8px;
  padding: 7px 10px;
  border-bottom: 1px solid var(--rule);
  font-size: 12px;
}
figcaption b { font-weight: 600; }
figcaption .why { color: var(--ink-faint); }
/* How the pictures are drawn.
   A screenshot has the pixels it has, and it looks like itself only while
   each of them covers a whole number of the screen's. Otherwise some rows of
   a letter come out twice as thick as others -- and how badly depends on the
   browser, which is why the same page can look right in one and broken in
   another. So the size is never asked for in the abstract: it is said in
   screen pixels per picture pixel, and the width in CSS is worked out from
   that and from what the screen says it is worth. That leaves nothing to
   interpolate, and nothing for a browser to have an opinion about. */
figure img { display: block; height: auto; }
figure .num {
  display: block;
  padding: 5px 10px 7px;
  border-top: 1px solid var(--rule);
  color: var(--ink-faint);
  font-size: 11.5px;
  font-variant-numeric: tabular-nums;
}
figure.none {
  border-style: dashed;
  border-color: color-mix(in srgb, var(--missing) 45%, var(--rule));
  box-shadow: none;
  min-width: 240px;
}
figure.none .said {
  padding: 26px 14px;
  color: var(--missing);
  background: var(--missing-soft);
  font-size: 13px;
  text-align: center;
}

"""

SCRIPT = """
const box = document.getElementById('filter');
const said = document.getElementById('said');
const sections = [...document.querySelectorAll('section')];
function sift() {
  const want = box.value.trim().toLowerCase();
  let shown = 0;
  for (const s of sections) {
    const on = !want || s.dataset.name.includes(want) ||
               s.dataset.title.toLowerCase().includes(want);
    s.hidden = !on;
    if (on) shown++;
  }
  said.textContent = shown + ' / ' + sections.length + ' fenêtres';
}
box.addEventListener('input', sift);

// How big a picture is drawn, said in screen pixels per picture pixel so
// that one of its pixels always covers a whole number of the screen's and
// there is nothing to interpolate. What that comes to in the units a page is
// laid out in depends on what the screen says it is worth, which is why it is
// worked out here rather than written into the style sheet.
//
// The default is what makes a window as big on this screen as it was on the
// one it was photographed on, which is the size the bench is about.
const zoom = document.getElementById('zoom');
const how = document.getElementById('how');
const shots = [...document.querySelectorAll('figure img')];
function scale() {
  const k = Number(zoom.value);
  const dpr = window.devicePixelRatio || 1;
  for(const im of shots)
    im.style.width = (Number(im.dataset.w) * k / dpr) + 'px';
  how.textContent = dpr === 1 ? 'pixel pour pixel'
    : '\u00e9cran \u00d7' + dpr + ', donc ' + (k / dpr) +
      ' pixel de page par pixel de capture';
}
zoom.addEventListener('change', scale);
// the ratio changes when the window is dragged to another screen
matchMedia('(resolution: 1dppx)').addEventListener('change', scale);
window.addEventListener('resize', scale);
zoom.value = String(Math.max(1, Math.min(3,
                    Math.round(window.devicePixelRatio || 1))));
scale();
sift();
"""


def write(shots, out, title):
    names = shot_names(shots)
    here = os.path.dirname(os.path.abspath(out)) or "."
    where = os.path.relpath(os.path.abspath(shots), here)

    have = {key: 0 for key, _ in COLUMNS}
    body = []
    for name in names:
        rows = []
        for key, caption in COLUMNS:
            f = "%s-%s.png" % (key, name)
            path = os.path.join(shots, f)
            if os.path.exists(path):
                have[key] += 1
                size = size_of(path)
                rows.append(
                    '<figure><figcaption><b>%s</b><span class="why">%s</span>'
                    '</figcaption><img src="%s/%s" alt="%s, %s" '
                    'data-w="%d" loading="lazy">'
                    '<span class="num">%s</span></figure>'
                    % (caption, NOTE.get(key, ""), where, f, name, caption,
                       size[0] if size else 0,
                       "%d &times; %d" % size if size else "&nbsp;"))
            else:
                rows.append(
                    '<figure class="none"><figcaption><b>%s</b></figcaption>'
                    '<div class="said">pas de capture</div></figure>' % caption)
        body.append(
            '<section id="%s" data-name="%s" data-title="%s">\n'
            '<h2>%s <a href="#%s">#</a></h2>\n'
            '<div class="shot-name"><code>%s</code></div>\n'
            '<div class="row">%s</div>\n</section>'
            % (name, name.lower(), title_of(name).replace('"', "&quot;"),
               title_of(name), name, name, "\n".join(rows)))

    counts = "".join(
        '<li><b>%d</b><span>%s</span></li>' % (have[key], key)
        for key, _ in COLUMNS)

    page = """<!doctype html>
<html lang="fr">
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>%s</title>
<style>%s</style>
<header>
<h1>%s</h1>
<p>La même fenêtre, déclarée une fois et construite par chaque interface.
La version publiée est la référence&nbsp;; ce qui la suit doit tenir les mêmes
champs, dans le même ordre et le même groupement. Les images sont à leur taille
réelle&nbsp;: une fenêtre deux fois plus haute que celle qu'elle remplace doit
avoir l'air deux fois plus haute.</p>
<ul class="counts"><li><b>%d</b><span>fenêtres</span></li>%s</ul>
</header>
<div class="bar">
<input type="search" id="filter" placeholder="filtrer&nbsp;: options, elementary, visibility…"
       aria-label="filtrer les fenêtres">
<label for="zoom">pixels d'écran par pixel de capture</label>
<select id="zoom">
<option value="1">1</option>
<option value="2">2</option>
<option value="3">3</option>
</select>
<span class="said" id="how"></span>
<span class="said" id="said"></span>
</div>
<main>
%s
</main>
<script>%s</script>
</html>
""" % (title, STYLE, title, len(names), counts, "\n\n".join(body), SCRIPT)

    with open(out, "w") as f:
        f.write(page)
    return len(names), have


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--shots", required=True)
    ap.add_argument("--out", required=True)
    ap.add_argument("--title", default="Les fenêtres de Gmsh, quatre fois")
    args = ap.parse_args()
    n, have = write(args.shots, args.out, args.title)
    print("%s : %d fenêtres, %s"
          % (args.out, n, ", ".join("%s %d" % (k, v) for k, v in have.items())))


if __name__ == "__main__":
    main()
