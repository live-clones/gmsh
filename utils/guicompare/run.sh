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
#   python3 -m venv .venv
#   .venv/bin/pip install 'gmsh==4.15.2' python-xlib pillow
#
# The version is pinned on purpose: that build is the reference every picture
# is compared against, and every coordinate this bench clicks was measured on
# its windows. A newer one would move them and quietly change what "the same"
# means.
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
# than one. The categories of the option window are swept as well, each in the
# same interface that has just been photographed.
#
# Each one holds an X server, a Gmsh with its model, and for the page a
# browser besides -- the better part of a gigabyte apiece. On a machine with
# little memory to spare, and none of it swap, GUICOMPARE_AT_ONCE says how
# many may run together; the rest wait their turn.

root=$(cd "$(dirname "$0")/../.." && pwd)
here=$root/utils/guicompare
venv=${GUICOMPARE_VENV:-$root/.venv}
py=$venv/bin/python
work=${GUICOMPARE_WORK:-$here/out}
# The categories of the option window to sweep as well. Every one of them by
# default: it is the window with the most in it by far, and one tab of it says
# nothing about the other twenty-four. GUICOMPARE_OPTIONS names which, and an
# empty one skips them.
options=${GUICOMPARE_OPTIONS-general geometry mesh solver post view}
shots=$work/shots
figures=$work/figures

[ -x "$py" ] || { echo "no virtualenv at $venv; see the head of this file" >&2; exit 1; }
command -v Xvfb >/dev/null || { echo "Xvfb is not installed" >&2; exit 1; }

# One build holding every interface if there is one, since which of them comes
# up is decided when it does; otherwise the one dedicated to each.
one=""
[ -d "$root/build-all" ] && one="$root/build-all"

# gmsh.py looks for the library next to itself
for d in build build-imgui build-browser build-all; do
  [ -d "$root/$d" ] && cp "$root/api/gmsh.py" "$root/$d/gmsh.py"
done

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
  for category in $options; do
    $py "$here/shoot.py" --build "$build" ${1:+--lib "$1"} --out "$shots" \
        --home "$home" --display "$display" --sweep-options --only "$category" \
        2>&1 | sed "s/^/$build: /"
  done
}

# how many builds photograph at a time, see the head of this file
atonce=${GUICOMPARE_AT_ONCE:-4}
running=0
breathe() {
  running=$((running + 1))
  [ "$running" -lt "$atonce" ] && return
  wait
  running=0
}

photograph released 95 "" &
breathe
photograph fltk 96 "${one:-$root/build}" &
breathe
photograph imgui 97 "${one:-$root/build-imgui}" &
breathe
# the page in a browser, if it was built: it is driven over the socket it
# answers on rather than by clicking, and photographed inside one browser
# window
if [ -n "$one" ] || [ -d "$root/build-browser" ]; then
  photograph browser 98 "${one:-$root/build-browser}" &
  breathe
fi
wait

echo "== planches"
$py "$here/compare.py" --shots "$shots" --out "$figures"
# and one page holding the lot, which is what one actually looks at
$py "$here/report.py" --shots "$shots" --out "$work/bench.html"
echo "-> $figures"
