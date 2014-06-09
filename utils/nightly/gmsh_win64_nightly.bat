@echo off

C:
chdir C:\cygwin\bin

bash --login -c "cd ${HOME}/src/gmsh/utils/nightly && ctest -S gmsh_win64_nightly.ctest -VV > ${HOME}/src/gmsh/nightly.log 2>&1"

bash --login -c "cd ${HOME}/src/gmsh/utils/nightly && /cygdrive/c/Program\ Files\ \(x86\)/CMake\ 2.8/bin/ctest.exe -S gmsh_msvc_nightly.ctest -VV > ${HOME}/src/gmsh/nightly_msvc.log 2>&1"
