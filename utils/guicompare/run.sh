#!/bin/sh
# Photograph the same dialogs in every build there is and put them side by
# side.
#
#   utils/guicompare/run.sh [dialog ...]
#   GUICOMPARE_OPTIONS="general mesh" utils/guicompare/run.sh
#
# Needs Xvfb, and a virtualenv holding the released gmsh, python-xlib and
# pillow -- GUICOMPARE_VENV says where it is:
#
#   python3 -m venv .venv && .venv/bin/pip install gmsh python-xlib pillow
#
# The FLTK build is expected in build/, the Dear ImGui one in build-imgui/ and
# the page in build-browser/ if it is wanted, all with ENABLE_BUILD_DYNAMIC so
# that there is a libgmsh to drive; the page also needs chromium, which is what
# holds it. The
# little models the dialogs are photographed against live in models/.
#
# The builds run at the same time. They share nothing: each has its own X
# server, its own HOME and its own name for every picture, and photographing
# one interface is mostly waiting for it, so three at once cost little more
# than one. GUICOMPARE_OPTIONS names the categories of the option window to
# sweep as well, each in the same interface that has just been photographed.

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
[ -d "$root/build-browser" ] && cp "$root/api/gmsh.py" "$root/build-browser/gmsh.py"

mkdir -p "$shots" "$figures"
if [ $# -eq 0 ]; then
  rm -rf "$work/home-released" "$work/home-fltk" "$work/home-imgui" \
         "$work/home-browser"
fi

# named on the command line, a dialog or a single shot is the only thing
# rephotographed; everything, in all three builds, when nothing is named
only=""
for d in "$@"; do only="$only --shot $d"; done

# one build: its dialogs, then the categories of the option window it was
# asked to sweep
photograph() {
  build=$1 display=$2 home=$work/home-$build
  shift 2
  $py "$here/shoot.py" --build "$build" ${1:+--lib "$1"} --out "$shots" \
      --home "$home" --display "$display" $only 2>&1 | sed "s/^/$build: /"
  for category in $GUICOMPARE_OPTIONS; do
    $py "$here/shoot.py" --build "$build" ${1:+--lib "$1"} --out "$shots" \
        --home "$home" --display "$display" --sweep-options --only "$category" \
        2>&1 | sed "s/^/$build: /"
  done
}

photograph released 95 "" &
photograph fltk 96 "$root/build" &
photograph imgui 97 "$root/build-imgui" &
# the page in a browser, if that build is there: it is driven over the socket
# it answers on rather than by clicking, and photographed inside one browser
# window
if [ -d "$root/build-browser" ]; then
  photograph browser 98 "$root/build-browser" &
fi
wait

echo "== planches"
$py "$here/compare.py" --shots "$shots" --out "$figures"
# and one page holding the lot, which is what one actually looks at
$py "$here/report.py" --shots "$shots" --out "$work/bench.html"
echo "-> $figures"
