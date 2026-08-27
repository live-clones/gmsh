#!/bin/sh
# Photograph the same dialogs in the three builds and put them side by side.
#
#   utils/guicompare/run.sh [dialog ...]
#
# Needs Xvfb, and a virtualenv holding the released gmsh, python-xlib and
# pillow -- GUICOMPARE_VENV says where it is:
#
#   python3 -m venv .venv && .venv/bin/pip install gmsh python-xlib pillow
#
# The FLTK build is expected in build/ and the Dear ImGui one in build-imgui/,
# both with ENABLE_BUILD_DYNAMIC so that there is a libgmsh to drive. The
# little models the dialogs are photographed against live in models/.

set -e
root=$(cd "$(dirname "$0")/../.." && pwd)
here=$root/utils/guicompare
venv=${GUICOMPARE_VENV:-$root/.venv}
py=$venv/bin/python
work=${GUICOMPARE_WORK:-$here/out}
shots=$work/shots
figures=$work/figures

[ -x "$py" ] || { echo "no virtualenv at $venv; see the head of this file" >&2; exit 1; }
command -v Xvfb >/dev/null || { echo "Xvfb is not installed" >&2; exit 1; }

# gmsh.py looks for the library next to itself
cp "$root/api/gmsh.py" "$root/build/gmsh.py"
cp "$root/api/gmsh.py" "$root/build-imgui/gmsh.py"

mkdir -p "$shots" "$figures"
if [ $# -eq 0 ]; then
  rm -rf "$work/home-released" "$work/home-fltk" "$work/home-imgui"
fi

# named on the command line, a dialog or a single shot is the only thing
# rephotographed; everything, in all three builds, when nothing is named
only=""
for d in "$@"; do only="$only --shot $d"; done

echo "== publié"
$py "$here/shoot.py" --build released --out "$shots" --home "$work/home-released" \
    --display 95 $only
echo "== FLTK converti"
$py "$here/shoot.py" --build fltk --lib "$root/build" --out "$shots" \
    --home "$work/home-fltk" --display 96 $only
echo "== Dear ImGui"
$py "$here/shoot.py" --build imgui --lib "$root/build-imgui" --out "$shots" \
    --home "$work/home-imgui" --display 97 $only

echo "== planches"
$py "$here/compare.py" --shots "$shots" --out "$figures"
echo "-> $figures"
