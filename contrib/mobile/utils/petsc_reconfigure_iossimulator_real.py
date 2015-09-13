#!/Users/geuzaine/anaconda/bin/python
if __name__ == '__main__':
  import sys
  import os
  sys.path.insert(0, os.path.abspath('config'))
  import configure
  configure_options = [
    '--CC=gcc',
    '--CFLAGS=-m32 -DPETSC_BLASLAPACK_UNDERSCORE',
    '--CXX=g++',
    '--CXXFLAGS=-m32 -DPETSC_BLASLAPACK_UNDERSCORE',
    '--with-clanguage=cxx',
    '--with-debugging=0',
    '--with-fc=0',
    '--with-ios=1',
    '--with-mpi=0',
    '--with-shared-libraries=0',
    '--with-ssl=0',
    '--with-x=0',
    'PETSC_ARCH=iossimulator_real',
  ]
  configure.petsc_configure(configure_options)
