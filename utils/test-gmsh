#/bin/sh

if [ $# -lt 2 ]; then
  echo "Usage: $0 path program [options]" 1>&2;
  exit 1;
fi

path=$1
shift 1
program=$*
files=`find $path -name "*.geo"`
for file in $files ; do
  echo "Running $program $file" ;
  $program $file -o /tmp/tmp.msh >& log ;
  grep -i "Warning" log ;
  grep -i "Error" log ;
done

