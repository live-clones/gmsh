@echo off

C:
chdir C:\cygwin\bin

bash --login -c "cd ${HOME}/src/gmsh/utils/nightly && ctest -S gmsh_win64_nightly.ctest -VV > ${HOME}/src/gmsh/nightly.log 2>&1"
