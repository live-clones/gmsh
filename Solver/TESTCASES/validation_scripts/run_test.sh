# $1 command $2 name $3 rev $4 dir
run_test() {
  start_time=`date "+%s"`
  ulimit -t 600
  echo running "$2"
  dir="$4/$2"
  mkdir -p $dir
  echo "$3" >"$dir/last_tested"
  echo "running" > "$dir/status"
  if $1  &>"$dir/log" ; then
    echo "$3" >"$dir/last_passed"
    rm -f $dir/first_failed
    rm -f $dir/log_first_failed
    cp "$dir/log" "$dir/log_last_passed"
    echo "passed" |tee "$dir/status"
  else 
    if [ ! -e "$dir/first_failed" ]; then
      echo "$3" > "$dir/first_failed"
      cp "$dir/log" "$dir/log_first_failed"
    fi
    echo "failed" |tee "$dir/status"
    let nfailed=$nfailed+1
  fi
  end_time=`date "+%s"`
  echo $(($end_time-$start_time)) > "$dir/time"
}
