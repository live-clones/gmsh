#!/bin/bash
# Runs of the random user (gui_fuzz, see fuzz.cpp) on models, one run at a
# time, each in a scratch copy of the model's own files that is deleted
# afterwards; the log of each run and, on macOS, the crash report of a run
# that died are kept in the output directory:
#   benchmarks/gui/fuzz.sh <build dir> <seconds> <seeds> <output dir> model...
# e.g.
#   benchmarks/gui/fuzz.sh bin 60 1,2,3 /tmp/fuzz tutorials/t1.geo tutorials/t5.geo
# The windows of the interface open on screen while a run goes: do not use the
# computer meanwhile. A run that does not end by itself is killed after twice
# its time.
if [ $# -lt 5 ]; then
  echo "Usage: $0 <build dir> <seconds> <seeds> <output dir> model.geo ..."
  exit 1
fi
build=$(cd "$1" && pwd); seconds=$2; seeds=$3; out=$4; shift 4
mkdir -p "$out"
timeout=$((2 * seconds + 30))
failed=0
for model in "$@"; do
  name=$(basename "$model" .geo)
  dir=$(dirname "$model")
  for seed in ${seeds//,/ }; do
    run="$out/$name-$seed"
    scratch=$(mktemp -d "${TMPDIR:-/tmp}/gui_fuzz.XXXXXX")
    # the model and the files it includes, as far as a .geo names them
    cp "$model" "$scratch/"
    for f in $(grep -oE 'Include *"[^"]+"|Merge *"[^"]+"' "$model" | grep -oE '"[^"]+"' | tr -d '"'); do
      [ -f "$dir/$f" ] && cp "$dir/$f" "$scratch/"
    done
    echo "=== $name seed $seed"
    ( cd "$scratch" && "$build/gui_fuzz" "$name.geo" "$seconds" "$seed" > "$run.log" 2>&1 ) &
    pid=$!
    waited=0
    while kill -0 $pid 2>/dev/null && [ $waited -lt $timeout ]; do sleep 1; waited=$((waited + 1)); done
    if kill -0 $pid 2>/dev/null; then
      echo "    stuck after $timeout s: killed" | tee -a "$run.log"
      kill -9 $pid 2>/dev/null
      failed=$((failed + 1))
    else
      wait $pid; status=$?
      if [ $status -ne 0 ]; then
        echo "    exit $status" | tee -a "$run.log"
        failed=$((failed + 1))
        # the crash report of the run, on macOS
        sleep 2
        report=$(ls -t ~/Library/Logs/DiagnosticReports/gui_fuzz-*.ips 2>/dev/null | head -1)
        [ -n "$report" ] && cp "$report" "$run.ips"
      else
        tail -1 "$run.log"
      fi
    fi
    # the solvers a run may have started
    pkill -P $pid 2>/dev/null
    rm -rf "$scratch"
  done
done
echo "$failed runs failed; logs in $out"
exit $failed
