#! /bin/csh -f

if ( "$#argv" < "1" ) then
  echo  usage: modif number_of_days
  exit
endif

find . \( -mtime -$1 -a ! -type d -a ! -name "*.o" -a ! -name "*.a" -a ! -name "*.bak" -a ! -name "*.tar*" -a ! -name "*~" -a ! -name "gmsh*" \)

echo "archiver ? (y/n)"
set caca = "$<"

if ("$caca" == "y") then
  set liste = `find . \( -mtime -$1 -a ! -type d -a ! -name "*.o" -a ! -name "*.a" -a ! -name "*.bak" -a ! -name "*.tar*" -a ! -name "*~" -a ! -name "gmsh*" \)`
  set date = `date "+%d.%m.%y-%Hh%M"`
  tar cvf modifs-gmsh-$date.tar $liste
  gzip modifs-gmsh-$date.tar
else 
  echo "bye"
endif


