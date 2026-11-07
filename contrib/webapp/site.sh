#!/bin/bash
# Make the web app's site in a directory, to serve or copy to a web server:
# the pages, the module built by build.sh with GetDP's templates, the examples
# of the viewer, and the models given, each packed as a zip and listed on the
# landing page (index.html)
#
# Usage: ./site.sh <site directory> [--group <heading>] [--note <text>]
#                  [<title>|]<model> ...
#
# A model is a directory (onelab.html opens its .pro with a .geo of the same
# name), or a .pro or .geo file in one (opened instead, e.g. for a directory of
# several models). Its title is the first heading of its README.md, else its
# name, unless given as "<title>|<model>". --group starts a list of models
# under a heading; --note adds a remark after the next model. E.g.
#
#   ./site.sh site --group "GetDP tutorials" ~/src/getdp/tutorials/*/
#   rsync -az site/ server:path
#
# BUILD: the build directory (default: ./build)

set -e
HERE=$(cd "$(dirname "$0")" && pwd)
SRC=$(cd "$HERE/../.." && pwd)
B=${BUILD:-$HERE/build}
if [ $# -lt 1 ]; then
  echo "Usage: $0 <site directory> [--group <heading>] [--note <text>]" \
       "[<title>|]<model> ..."
  exit 1
fi
if [ ! -f "$B/libgmsh.wasm" ]; then
  echo "No module in $B: run build.sh first"
  exit 1
fi
mkdir -p "$1"
SITE=$(cd "$1" && pwd)
shift

# the module, and GetDP's templates (for a page that sets up a problem on a
# geometry, not offered yet)
mkdir -p "$SITE/build/templates"
cp "$B/gmsh.mjs" "$B/libgmsh.mjs" "$B/libgmsh.wasm" "$SITE/build"
if [ -d "$B/templates" ]; then cp "$B"/templates/* "$SITE/build/templates"; fi

# the pages, and the examples of the viewer next to it
cp "$HERE/onelab.html" "$HERE/shortcuts.js" "$HERE/solver.js" "$SITE"
sed "s|^const examples = '../../tutorials/';|const examples = 'tutorials/';|" \
  "$HERE/viewer.html" > "$SITE/viewer.html"
mkdir -p "$SITE/tutorials"
for f in $(sed -n 's|.*<option value="\([^"]*\.[a-z]*\)".*|\1|p' "$HERE/viewer.html"); do
  cp "$SRC/tutorials/$f" "$SITE/tutorials"
done

# the models, without what earlier runs left (meshes, results, databases)
html() { sed -e 's/&/\&amp;/g' -e 's/</\&lt;/g' -e 's/>/\&gt;/g'; }
rm -rf "$SITE/models"
mkdir "$SITE/models"
LIST="$SITE/models/list.html"
inlist=0
note=""
while [ $# -gt 0 ]; do
  if [ "$1" == "--note" ]; then
    note=$2
    shift 2
    continue
  fi
  if [ "$1" == "--group" ]; then
    if [ $inlist == 1 ]; then echo "</ul>" >> "$LIST"; fi
    echo "<h3>$(echo "$2" | html)</h3>" >> "$LIST"
    echo "<ul>" >> "$LIST"
    inlist=1
    shift 2
    continue
  fi
  title=""
  model=$1
  case "$model" in *"|"*) title=${model%%|*}; model=${model#*|};; esac
  open=""
  if [ -f "$model" ]; then
    dir=$(dirname "$model")
    open=$(basename "$model")
    name=${open%.*}
  else
    dir=${model%/}
    name=$(basename "$dir")
    if [ -z "$title" -a -f "$dir/README.md" ]; then
      title=$(sed -n 's/^# *//p' "$dir/README.md" | head -1)
    fi
  fi
  if [ -z "$title" ]; then title=$name; fi
  (cd "$dir" && zip -q -r "$SITE/models/$name.zip" . -x '*.msh' '*.pre' \
     '*.res' '*.pos' '*.db' '*.db.json' '*.png' '*.jpg' '*.out' '*.mp4')
  link="onelab.html?zip=models/$name.zip"
  if [ -n "$open" ]; then link="$link&amp;open=$open"; fi
  if [ $inlist == 0 ]; then
    echo "<ul>" >> "$LIST"
    inlist=1
  fi
  item="<a href=\"$link\">$(echo "$title" | html)</a>"
  if [ -n "$note" ]; then item="$item ($(echo "$note" | html))"; fi
  echo "  <li>$item</li>" >> "$LIST"
  note=""
  echo "$name.zip: $title"
  shift
done
if [ $inlist == 1 ]; then echo "</ul>" >> "$LIST"; fi
touch "$LIST"

# the landing page, with the list of the models
awk -v list="$LIST" '/<!-- MODELS -->/ { while((getline l < list) > 0) print l; next }
  { print }' "$HERE/index.html" > "$SITE/index.html"
rm "$LIST"
echo "Site in $SITE"
