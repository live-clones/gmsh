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
# Make the missing thumbnails of the models of the landing page, name.jpg in
# this directory (remove one to make it again), from the list deploy.sh gives
# (./deploy.sh --thumbnails runs this): a line per model, with its name, its
# directory, the file it opens (if not the one onelab.html would find), the
# Gmsh options its thumbnail is drawn with (see render.py) and the ONELAB
# parameters it is run with (see run.mjs), the last three possibly empty,
# separated by |. A model with a solver (a .pro) is run with the web app's
# module under node (run.mjs, so the module of build.sh is needed), then drawn
# by a native Gmsh (render.py, with the Python API of the Gmsh sources, the
# library of their build in bin/, and Pillow); a .geo alone is drawn by the
# native Gmsh only.
#
# NODE: the node of emsdk (default: the one in ~/src/emsdk)

HERE=$(cd "$(dirname "$0")" && pwd)
SRC=$(cd "$HERE/../../.." && pwd)
NODE=${NODE:-$(ls -d ~/src/emsdk/node/*/bin/node 2>/dev/null | tail -1)}
export PYTHONPATH=$SRC/api
TMP=$(mktemp -d)
trap 'rm -rf "$TMP"' EXIT

while IFS='|' read -r name dir open options parameters; do
  out=$HERE/$name.jpg
  if [ -f "$out" ]; then continue; fi
  if [ "${open##*.}" != geo ]; then
    "$NODE" "$HERE/run.mjs" "$TMP" "$name" "$dir" "$open" "$parameters" \
      < /dev/null || continue
    file=$dir/$(cat "$TMP/$name.open")
    python3 "$HERE/render.py" "${file%.pro}.geo" "$out" "$TMP" "$name" \
      "$options" "$parameters" < /dev/null > /dev/null
  else
    python3 "$HERE/render.py" "$dir/$open" "$out" "" "" "$options" \
      < /dev/null > /dev/null &&
      echo "$name: ok"
  fi
done
