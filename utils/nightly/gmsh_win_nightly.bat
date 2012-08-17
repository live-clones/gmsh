@echo off

C:
chdir C:\cygwin\bin

bash --login -c "cd ${HOME}/src/gmsh/utils/nightly && ctest -S gmsh_win_nightly.ctest"
