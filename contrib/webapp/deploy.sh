#!/bin/bash
#
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
#
# Deploy the web app demo on https://onelab.info/webapp/: the site is made in
# build/site, with the pages, the module of build.sh (run it first) and GetDP's
# templates, and the models (the GetDP tutorials
# and those of onelab_doc), each packed as a zip and listed on the landing
# page (index.html); then it is copied to the web server.
#
# Usage: ./deploy.sh [--dry-run]
#   --dry-run: make the site (which can also be served from build/site) and
#              show what would change on the server, without changing it
# GETDP: the GetDP sources (default: getdp next to the Gmsh sources)
# ONELAB_DOC: the onelab_doc sources (default: onelab_doc next to them)
# BUILD: the build directory (default: ./build)
# DEST: where the site goes (default: gmsh.info:.wwwonelab/webapp/)

set -e
HERE=$(cd "$(dirname "$0")" && pwd)
SRC=$(cd "$HERE/../.." && pwd)
GETDP=${GETDP:-$SRC/../getdp}
ONELAB_DOC=${ONELAB_DOC:-$SRC/../onelab_doc}
B=${BUILD:-$HERE/build}
DEST=${DEST:-gmsh.info:.wwwonelab/webapp/}
DRY=0
case "$1" in
  --dry-run) DRY=1 ;;
  "") ;;
  *) echo "Usage: $0 [--dry-run]"; exit 1 ;;
esac

T=$GETDP/tutorials
M=$ONELAB_DOC/models
P=$M/AcademicPhotonics/tutorial_photonics_dev
for d in "$T" "$M" "$P"; do
  if [ ! -d "$d" ]; then echo "No $d (see GETDP and ONELAB_DOC)"; exit 1; fi
done
if [ ! -f "$B/libgmsh.wasm" ]; then
  echo "No module in $B: run build.sh first"
  exit 1
fi
SITE=$B/site
mkdir -p "$SITE"

# the module, and GetDP's templates (for a page that sets up a problem on a
# geometry, not offered yet)
mkdir -p "$SITE/build/templates"
cp "$B/gmsh.mjs" "$B/libgmsh.mjs" "$B/libgmsh.wasm" "$SITE/build"
# its size, which the page cannot read from a compressed response, for the
# progress of its loading
wc -c < "$B/libgmsh.wasm" | tr -d ' ' > "$SITE/build/libgmsh.wasm.size"
if [ -d "$B/templates" ]; then cp "$B"/templates/* "$SITE/build/templates"; fi

# the page, its stylesheet and modules (see README.txt), with the manifest
# and the icons that make it an app on a phone's home screen
cp "$HERE/onelab.html" "$HERE/onelab.css" "$HERE/main.mjs" "$HERE/app.mjs" \
  "$HERE/gmshweb.mjs" "$HERE/scene.mjs" "$HERE/statusbar.mjs" "$HERE/tools.mjs" \
  "$HERE/actions.mjs" "$HERE/parameters.mjs" "$HERE/views.mjs" \
  "$HERE/solverClient.mjs" "$HERE/options.mjs" "$HERE/clipping.mjs" \
  "$HERE/visibility.mjs" "$HERE/editor.mjs" "$HERE/models.mjs" \
  "$HERE/shortcuts.js" "$HERE/solver.js" "$HERE/files.mjs" \
  "$HERE/manifest.webmanifest" "$SITE"
mkdir -p "$SITE/icons"
cp "$HERE"/icons/*.png "$SITE/icons"
# (what the viewer page left on the server, removed by rsync --delete)
rm -rf "$SITE/viewer.html" "$SITE/tutorials"

# The models, without what earlier runs left (meshes, results, databases),
# and their list on the landing page: group starts a list under a heading;
# model adds a directory (onelab.html opens its .pro with a .geo of the same
# name) or a .pro or .geo file in one (opened instead, e.g. for a directory of
# several models), with its title (by default the first heading of its
# README.md, else its name) and a note
html() { sed -e 's/&/\&amp;/g' -e 's/</\&lt;/g' -e 's/>/\&gt;/g'; }
rm -rf "$SITE/models"
mkdir "$SITE/models"
LIST="$SITE/models/list.html"
: > "$LIST"
inlist=0
group() {
  if [ $inlist == 1 ]; then echo "</ul>" >> "$LIST"; fi
  echo "<h3>$(echo "$1" | html)</h3>" >> "$LIST"
  echo "<ul>" >> "$LIST"
  inlist=1
}
model() {
  local path=$1 title=$2 note=$3 dir name open=""
  if [ -f "$path" ]; then
    dir=$(dirname "$path")
    open=$(basename "$path")
    name=${open%.*}
  else
    dir=${path%/}
    name=$(basename "$dir")
    if [ -z "$title" -a -f "$dir/README.md" ]; then
      title=$(sed -n 's/^# *//p' "$dir/README.md" | head -1)
    fi
  fi
  if [ -z "$title" ]; then title=$name; fi
  (cd "$dir" && zip -q -r "$SITE/models/$name.zip" . -x '*.msh' '*.pre' \
     '*.res' '*.pos' '*.db' '*.db.json' '*.png' '*.jpg' '*.out' '*.mp4')
  local link="onelab.html?zip=models/$name.zip"
  if [ -n "$open" ]; then link="$link&amp;open=$open"; fi
  if [ $inlist == 0 ]; then
    echo "<ul>" >> "$LIST"
    inlist=1
  fi
  local item="<a href=\"$link\">$(echo "$title" | html)</a>"
  if [ -n "$note" ]; then item="$item ($(echo "$note" | html))"; fi
  echo "  <li>$item</li>" >> "$LIST"
  echo "$name.zip: $title"
}

# the notes of the models that are slow, or do not run in the browser yet
BESSEL="does not run in the browser yet: needs GetDP's Bessel functions (Fortran)"
MEMORY="too large for the browser's memory for now"
CRYSTAL="Photonics tutorial P13: 3D photonic crystal of spheres"
P13=$P/P13-modes_photonic_crystal_3D/modes_photonic_crystal

model "$M/ElectricMachines/im_3kW.pro" "Induction machine, 3 kW (2D, frequency domain)"
model "$M/MagneticForces" "Magnetic forces between magnets (3D, OpenCASCADE geometry)"
group "GetDP tutorials"
for d in "$T"/0*/; do model "$d"; done
model "$T/10-Gauging" "" "3D, about 30 s"
group "Photonics tutorials"
for d in "$P"/P0[1-7]*/; do model "$d"; done
model "$(echo "$P"/P08*/)" "" "about 25 s"
for d in "$P"/P09*/ "$P"/P1[0-2]*/; do model "$d"; done
model "${P13}_cubic_3D.pro" "$CRYSTAL, simple cubic lattice" "about 20 s"
model "${P13}_diamond_3D.pro" "$CRYSTAL, diamond lattice" \
  "about 15 s; its high-order mesh optimization reports errors, as in the desktop app"
model "$(echo "$P"/P14*/)" "" "about 30 s"
model "$(echo "$P"/P15*/)"
model "$(echo "$P"/P16*/)" "" "about 10 s"
model "$(echo "$P"/P17*/)" "" "$BESSEL"
model "$(echo "$P"/P18*/)" "" "$MEMORY"
model "$(echo "$P"/P19*/)" "" "$BESSEL"
model "$(echo "$P"/P20*/)" "" "$MEMORY"
model "$(echo "$P"/P21*/)" "" "$MEMORY"
model "$(echo "$P"/P22*/)"
model "$(echo "$P"/P23*/)"
if [ $inlist == 1 ]; then echo "</ul>" >> "$LIST"; fi

# the landing page, with the list of the models
awk -v list="$LIST" '/<!-- MODELS -->/ { while((getline l < list) > 0) print l; next }
  { print }' "$HERE/index.html" > "$SITE/index.html"
rm "$LIST"
echo "Site in $SITE"

if [ $DRY == 1 ]; then
  # what would be sent (but the files whose time alone changed) and deleted
  rsync -azn --delete --itemize-changes "$SITE/" "$DEST" |
    grep -Ev '^[<.][fd]\.\.t\.* ' || true
else
  rsync -az --delete "$SITE/" "$DEST"
  echo "Deployed to $DEST"
fi
