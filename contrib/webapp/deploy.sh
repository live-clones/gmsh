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
# templates, and the models (the Gmsh and GetDP tutorials and those of
# onelab_doc), packed as zips and shown on the landing page (index.html) with
# their thumbnails; then it is copied to the web server.
#
# Usage: ./deploy.sh [--dry-run | --thumbnails]
#   --dry-run: make the site (which can also be served from build/site) and
#              show what would change on the server, without changing it
#   --thumbnails: make the missing thumbnails of the models instead
#                 (thumbnails/make.sh), without deploying
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
THUMBNAILS=0
case "$1" in
  --dry-run) DRY=1 ;;
  --thumbnails) THUMBNAILS=1 ;;
  "") ;;
  *) echo "Usage: $0 [--dry-run | --thumbnails]"; exit 1 ;;
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
  "$HERE/visibility.mjs" "$HERE/plugins.mjs" "$HERE/editor.mjs" "$HERE/models.mjs" \
  "$HERE/shortcuts.js" "$HERE/solver.js" "$HERE/files.mjs" \
  "$HERE/manifest.webmanifest" "$SITE"
mkdir -p "$SITE/icons"
cp "$HERE"/icons/*.png "$SITE/icons"
# (what the viewer page left on the server, removed by rsync --delete)
rm -rf "$SITE/viewer.html" "$SITE/tutorials"

# The models, without what earlier runs left (meshes, results, databases),
# each directory packed once (models/<directory>.zip, shared by the models it
# holds), and their cards on the landing page, with their thumbnails
# (thumbnails/, made by thumbnails/make.sh): section starts a part of the page
# under a heading, with a line of text; group starts a set of cards under a
# smaller heading; model adds a card for a directory (onelab.html opens its
# .pro with a .geo of the same name) or for a .pro or .geo file in one (opened
# instead, for a directory of several models), with its title (by default the
# first heading of its README.md, whose "... tutorial N:" goes above the
# title, else its name), a note, a label above the title, the Gmsh options
# its thumbnail is drawn with and the ONELAB parameters it is run with for it
# (see thumbnails/render.py and run.mjs), and the directory packed instead of
# its own, for a model that includes files of the directories above (opened
# in it). A directory that is a git checkout of its own is packed with the
# files it tracks, not the results left in it (and still without meshes...)
html() { sed -e 's/&/\&amp;/g' -e 's/</\&lt;/g' -e 's/>/\&gt;/g'; }
rm -rf "$SITE/models" "$SITE/thumbnails"
mkdir "$SITE/models" "$SITE/thumbnails"
LIST="$SITE/models/list.html"
THUMBS="$SITE/models/thumbnails.txt"
: > "$LIST"
: > "$THUMBS"
incards=0
endcards() {
  if [ $incards == 1 ]; then echo "</div>" >> "$LIST"; fi
  incards=0
}
section() {
  endcards
  echo "<h2 id=\"$2\">$(echo "$1" | html)</h2>" >> "$LIST"
  if [ -n "$3" ]; then echo "<p class=\"sub\">$3</p>" >> "$LIST"; fi
}
group() {
  endcards
  echo "<h3>$(echo "$1" | html)</h3>" >> "$LIST"
}
model() {
  local path=$1 title=$2 note=$3 label=$4 options=${5//$'\n'/ } parameters=$6
  local root=$7 dir name zip open=""
  if [ -f "$path" ]; then
    dir=$(dirname "$path")
    open=$(basename "$path")
    name=${open%.*}
    if [ -n "$root" ]; then
      dir=${root%/}
      open=${path#$dir/}
    fi
  else
    dir=${path%/}
    name=$(basename "$dir")
    if [ -z "$title" -a -f "$dir/README.md" ]; then
      title=$(sed -n 's/^# *//p' "$dir/README.md" | head -1)
      if [[ "$title" =~ ^(.*[Tt]utorial\ [^:]*):\ *(.*)$ ]]; then
        label=${BASH_REMATCH[1]}
        title=${BASH_REMATCH[2]}
        title=$(echo "${title:0:1}" | tr a-z A-Z)${title:1}
      fi
    fi
  fi
  if [ -z "$title" ]; then title=$name; fi
  zip=$(basename "$dir")
  if [ "$dir" == "$SRC/tutorials" ]; then
    # the Gmsh tutorials: the files of the directory alone, not those of the
    # other languages under it
    zip=gmsh_tutorials
    if [ ! -f "$SITE/models/$zip.zip" ]; then
      (cd "$dir" && git ls-files . | grep -v / |
         zip -q "$SITE/models/$zip.zip" -@)
    fi
  elif [ ! -f "$SITE/models/$zip.zip" ]; then
    if [ -d "$dir/.git" ]; then
      (cd "$dir" && git ls-files |
         grep -Eiv '\.(msh|pre|res|pos|db|db\.json|png|jpg|out|mp4)$' |
         zip -q "$SITE/models/$zip.zip" -@)
    else
      (cd "$dir" && zip -q -r "$SITE/models/$zip.zip" . -x '*.msh' '*.pre' \
         '*.res' '*.pos' '*.db' '*.db.json' '*.png' '*.jpg' '*.out' '*.mp4')
    fi
  fi
  printf '%s|%s|%s|%s|%s\n' "$name" "$dir" "$open" "$options" \
    "$parameters" >> "$THUMBS"
  local link="onelab.html?zip=models/$zip.zip"
  if [ -n "$open" ]; then link="$link&amp;open=$open"; fi
  if [ $incards == 0 ]; then
    echo "<div class=\"cards\">" >> "$LIST"
    incards=1
  fi
  local img="<span class=\"thumb\"></span>"
  if [ -f "$HERE/thumbnails/$name.jpg" ]; then
    cp "$HERE/thumbnails/$name.jpg" "$SITE/thumbnails"
    img="<img class=\"thumb\" src=\"thumbnails/$name.jpg\" alt=\"\" width=\"240\" height=\"180\" loading=\"lazy\">"
  fi
  {
    echo "<a class=\"card\" href=\"$link\">$img"
    if [ -n "$label" ]; then echo "<span class=\"label\">$(echo "$label" | html)</span>"; fi
    echo "<span class=\"title\">$(echo "$title" | html)</span>"
    if [ -n "$note" ]; then echo "<span class=\"note\">$(echo "$note" | html)</span>"; fi
    echo "</a>"
  } >> "$LIST"
  echo "$zip.zip: $title"
}

section "Gmsh tutorials" gmsh \
  "Geometries and meshes made step by step with Gmsh's own language: open
   one, change its parameters, press <b>Run</b> to mesh it."
# (the thumbnails of t4 and t21 show the colours of their entities and
# partitions, those of t4, t7 and t17 their mesh rather than their view)
MESH="View[0].Visible=0; Mesh.SurfaceFaces=1; Mesh.SurfaceEdges=1;
  Mesh.ColorCarousel=0; Mesh.Color.Triangles={205,215,235};"
for i in $(seq 1 21); do
  options=""
  if [ $i == 4 ]; then options="$MESH Mesh.ColorCarousel=2;"; fi
  if [ $i == 7 -o $i == 17 ]; then options="$MESH"; fi
  if [ $i == 21 ]; then options="Mesh.ColorCarousel=3;"; fi
  model "$SRC/tutorials/t$i.geo" \
    "$(sed -n '5s|^// *||p' "$SRC/tutorials/t$i.geo")" "" "Gmsh tutorial $i" \
    "$options"
done

section "GetDP tutorials" getdp \
  "Finite element problems of growing complexity, each solved with GetDP:
   open one, change its parameters, press <b>Run</b>."
# (the thumbnails of some show another view than the one they end with)
model "$T/01-Electrostatics" "" "" "" "View[0].Visible=1; View[2].Visible=0;"
model "$T/02-Thermal" "" "" "" \
  "View[0].Visible=1; View[1].Visible=0; General.Trackball=0;
   General.RotationX=-70; General.RotationY=0; General.RotationZ=-40;" \
  "Parameters/0Model dimension=3"
model "$T/03-Magnetostatics" "" "" "" "View[2].Visible=1; View[4].Visible=0;"
model "$T/04-Magneto-quasistatics" "" "" "" \
  "View[5].ForceNumComponents=1; View[5].ComponentMap0=2; Geometry.Curves=0;"
model "$T/05-Full_wave"
model "$T/06-Global_quantities" "" "" "" \
  "View[1].Visible=1; View[2].Visible=1; View[1].ShowElement=0;
   General.ScaleX=2.2; General.ScaleY=2.2; General.TranslationX=0.0038;
   General.TranslationY=0.0038;" \
  "Parameters/3Display global basis functions=1"
model "$T/07-Coupled_problems"
model "$T/08-Circuit_coupling" "" "" "" \
  "View[2].Sampling=12; View[2].ArrowSizeMax=60; View[2].ArrowSizeMin=8;
   Mesh.SurfaceFaces=1; Mesh.SurfaceEdges=0; Mesh.ColorCarousel=0;
   Mesh.Color.Triangles={200,205,215}; Mesh.Opacity=0.25;" \
  "Parameters/0Model dimension=3"
model "$T/09-Template_library" "" "" "" \
  "View[2].Visible=1; View[4].Visible=0; View[2].ScaleType=2;
   View[2].RangeType=2; View[2].CustomMin=1e-3; View[2].CustomMax=0.13;
   General.ScaleX=2.4; General.ScaleY=2.4;"
model "$T/10-Gauging" "" "" "" \
  "View[0].Visible=1; View[0].TimeStep=1; View[3].TimeStep=1;
   Geometry.Curves=0; General.ScaleX=1; General.ScaleY=1; General.ScaleZ=1;"

section "ONELAB models" models \
  "Models of the <a href=\"https://onelab.info\">ONELAB</a> collection,
   ready to run with their parameters."
# (the thumbnails of the rotating machines show the elements of their views,
# as the rotor has turned)
OUTLINES="View[0].ShowElement=1; View[1].ShowElement=1; View[2].ShowElement=1;
  View[3].ShowElement=1; View[4].ShowElement=1;"
group "Electrical machines and devices"
model "$M/ElectricMachines/pmsm.pro" "Permanent magnet synchronous machine" \
  "Eight-pole surface mounted PMSM"
model "$M/ElectricMachines/wfsm_4p.pro" "Wound field synchronous machine" \
  "Four-pole WFSM" "" "$OUTLINES"
model "$M/ElectricMachines/im_3kW.pro" "Induction machine" \
  "3 kW four-pole induction machine"
model "$M/ElectricMachines/srm.pro" "Switched reluctance machine" "Simple SRM" \
  "" "$OUTLINES"
model "$M/ElectromechanicalRelay/relay.pro" "Electromechanical relay" \
  "2D model of an electro-mechanical relay" "" "View[3].Visible=1;" \
  "Input/31Time max.=0.05"
group "Magnetics and induction"
model "$M/Magnets/magnets.pro" "Magnets" \
  "3D force computation of a collection of magnets"
model "$M/MagnetInTube/magnet_in_tube.pro" "Magnet in a tube" \
  "Magnet falling in a conducting tube, slowed by eddy currents"
model "$M/Magnetometer/magnetometer.pro" "Magnetometer" \
  "3D model of a xylophone-bar magnetometer" "" "" \
  "Input/0Type of analysis=0"
model "$M/Cohomology/indheat.pro" "Induction heating" \
  "3D inductor with cohomology solver"
model "$M/Superconductors/helix.pro" "Superconducting wire" \
  "2D and 3D H-formulation of HTS with nonlinear power law" "" \
  "View[2].Visible=1; View[3].Visible=0; View[2].ForceNumComponents=1;
   View[2].ComponentMap0=2; General.ScaleX=2.6; General.ScaleY=2.6;"
# (the Life-HTS models include its lib directory: Life-HTS is packed; the
# thumbnail of the magnet, whose full run did not end in half an hour, was
# drawn by hand after ten time steps: View[1].TimeStep=10, its current density)
# (the thumbnail of the cylinder: its current density, run on a finer mesh
# and zoomed)
model "$M/Life-HTS/cylinder/cylinder.pro" "Superconducting cylinder" \
  "Life-HTS: axisymmetric bulk HTS cylinder" "" \
  "View[6].Visible=0; View[3].Visible=1; View[3].TimeStep=80; View[3].Light=0;
   Geometry.Curves=0; General.ScaleX=6; General.ScaleY=6;
   General.TranslationX=0.044;" \
  "Input/2Mesh/1Mesh size multiplier (-)=1.5" "$M/Life-HTS"
model "$M/Life-HTS/magnet/magnet.pro" "Superconducting magnet" \
  "Life-HTS: 3D bulk HTS magnetized by a coil" "" "" "" "$M/Life-HTS"
group "Waves"
model "$M/Waveguides/waveguide2D_straight.pro" "Straight waveguide" \
  "2D model of a rectangular metallic waveguide"
model "$M/Waveguides/waveguide2D_Hbend.pro" "H-bend waveguide" \
  "2D model of a bent metallic waveguide"
model "$M/Waveguides/waveguide2D_starNetwork.pro" "Star-shaped waveguide" \
  "2D model of a star-shaped metallic waveguide"
model "$M/Waveguides/waveguide2D_MMI.pro" "Multi-mode interference coupler" \
  "2D model of an MMI"
model "$M/AcousticScattering/scattering.pro" "Acoustic wave scattering" \
  "2D models of multiple acoustic scattering"
model "$M/TimeReversal/TR.pro" "Time reversal" \
  "2D model of time reversal of acoustic waves"
# (the thumbnail of the dipole: the magnitude of its field, on a log scale)
model "$M/Antennas/dipole.pro" "Dipole antenna" "2D and 3D models of a dipole" \
  "" "View[2].Visible=0; Plugin(MathEval).Expression0=\"Sqrt(v0^2+v1^2+v2^2)\";
   Plugin(MathEval).View=0; Plugin(MathEval).Run; View[3].ScaleType=2;
   View[3].Light=0; View[3].IntervalsType=2; View[3].ShowScale=0;
   General.Trackball=0; General.RotationZ=90;"
model "$M/Shielding/main.pro" "Electromagnetic shielding" \
  "2D and 3D models of shielding cavities"
model "$M/BlochPeriodicWaveguides/rhombus.pro" "Periodic waveguide" \
  "Bloch modes in a periodic waveguide of rhombi"
group "Mechanics, heat and flow"
model "$M/ElasticityKirsch/kirsch.pro" "Kirsch problem" \
  "Elastic stresses around a hole in a plate under tension"
model "$M/ThermalConduction/contact.pro" "Thermal conduction" \
  "Heat conduction after a transient heat flux pulse" "" \
  "View[0].TimeStep=10; View[0].RangeType=3;"
model "$M/PotentialFlow/magnus.pro" "Potential flow" \
  "Lift and Magnus effect in 2D irrotational fluid flow" "" "View[0].Visible=1;"
# (P17 to P21 left out: they need GetDP's Bessel functions, in Fortran, or
# more memory than the browser gives)
group "Photonics"
model "$(echo "$P"/P01*/)"
model "$(echo "$P"/P02*/)" "" "" "" "View[0].TimeStep=9;"
for d in "$P"/P0[3-5]*/; do model "$d"; done
model "$(echo "$P"/P06*/)" "" "" "" "View[0].TimeStep=11;"
model "$(echo "$P"/P07*/)"
model "$(echo "$P"/P08*/)"
for d in "$P"/P09*/ "$P"/P1[01]*/; do model "$d"; done
model "$(echo "$P"/P12*/)" "" "" "" \
  "View[1].ArrowSizeMax=120; View[1].ArrowSizeMin=20;"
P13=$P/P13-modes_photonic_crystal_3D/modes_photonic_crystal
model "${P13}_cubic_3D.pro" "3D photonic crystal of spheres, simple cubic lattice" \
  "" "Photonics tutorial P13"
model "${P13}_diamond_3D.pro" "3D photonic crystal of spheres, diamond lattice" \
  "" "Photonics tutorial P13"
model "$(echo "$P"/P14*/)"
model "$(echo "$P"/P15*/)"
model "$(echo "$P"/P16*/)"
model "$(echo "$P"/P22*/)"
model "$(echo "$P"/P23*/)"
endcards

if [ $THUMBNAILS == 1 ]; then
  "$HERE/thumbnails/make.sh" < "$THUMBS"
  exit 0
fi
rm "$THUMBS"

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
