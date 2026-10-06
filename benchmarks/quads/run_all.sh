#!/bin/sh
# Mesh every case of this directory with PACK and audit the result.
# usage: ./run_all.sh [case ...]     (GMSH=path/to/gmsh to choose the binary)
cd "$(dirname "$0")"
GMSH=${GMSH:-../../build/gmsh}
OUT=${OUT:-/tmp/quads_bench}
mkdir -p "$OUT"
cases=${*:-$(ls *.geo | sed 's/\.geo$//')}
printf '%-22s %7s %8s %7s %7s %9s %7s\n' case time cells tri bad minSine warped
for c in $cases; do
  start=$(date +%s)
  perl -e 'alarm shift; exec @ARGV' "${TIMEOUT:-600}" $GMSH "$c.geo" -2 -nt 2 -format msh2 -save_all -o "$OUT/$c.msh" > "$OUT/$c.log" 2>&1
  status=$?
  secs=$(( $(date +%s) - start ))
  if [ $status -ne 0 ] || [ ! -s "$OUT/$c.msh" ]; then
    printf '%-22s %6ss FAILED (see %s/%s.log)\n' "$c" "$secs" "$OUT" "$c"; continue
  fi
  python3 audit.py "$c.geo" "$OUT/$c.msh" 2>/dev/null | grep '^face' | awk -v c="$c" -v t="$secs" '
    { for(i=1;i<=NF;i++){split($i,a,"="); k[a[1]]=a[2]}
      cells+=k["cells"]; tri+=k["tri"]; bad+=k["flipped/invalid"]; wp+=k["warped"]
      if(NR==1||k["minSine"]<m) m=k["minSine"] }
    END { printf "%-22s %6ss %8d %7d %7d %9s %7d\n", c, t, cells, tri, bad, m, wp }'
done
