#!/bin/bash
dir_list="../gmsh"
export LC_ALL=C

get_revision(){
  rev=-1
  for i in $dir_list; do
    cd $i
    svn up
    nrev=`LC_ALL=C svn info |grep Revision|awk '{print $2}'`
    if [ $nrev -gt $rev ]; then
      rev=$nrev
    fi
    cd - >/dev/null
  done
}

source run_test.sh
if [ -e results/_global/last_tested ]; then
  old_rev=`cat results/_global/last_tested`
else
  old_rev=-1
fi
get_revision
if [ $rev -gt $old_rev ]; then
  start_time_global=`date "+%s"`
  nfailed=0
  mkdir -p "results/_global"
  echo "running" > "results/_global/status"
  source ./test_compilation.sh $rev
  source ./test_benchmarks.sh $rev 
  #generate _global entry
  if [ $nfailed -gt 0 ];then
    run_test '[ 1 -eq 0 ]' "_global" $rev results
#    ./send_mail.php
  else
#    # send an email for first succeeded test
#    if [ -e results/_global/first_failed ];then
#      ./send_mail.php
#    fi
    run_test '[ 0 -eq 0 ]' "_global" $rev results
  fi
  end_time_global=`date "+%s"`
  echo $(($end_time_global-$start_time_global)) > "results/_global/time"
  #remove old test case's directories 
  for i in results/*; do
    if [ -e $i/last_tested ]
		then
      lasttested=`cat $i/last_tested`
    else
      lasttested=-1
    fi
    if [ ! $lasttested -eq $rev ]; then
      rm -rf $i
    fi
  done
else
  sleep 20
fi
