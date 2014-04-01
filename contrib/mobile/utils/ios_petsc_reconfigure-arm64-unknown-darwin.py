#!/opt/local/bin/python
if __name__ == '__main__':
  import sys
  import os
  sys.path.insert(0, os.path.abspath('config'))
  import configure
  configure_options = [
    '--CC=/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang',
    '--CFLAGS=-arch arm64 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS7.1.sdk -miphoneos-version-min=7.0',
    '--CXX=/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++',
    '--CXXFLAGS=-arch arm64 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS7.1.sdk -miphoneos-version-min=7.0',
    '--known-bits-per-byte=8',
    '--known-endian=little',
    '--known-level1-dcache-assoc=1',
    '--known-level1-dcache-linesize=16',
    '--known-level1-dcache-size=4000',
    '--known-memcmp-ok=1',
    '--known-sizeof-char=1',
    '--known-sizeof-double=8',
    '--known-sizeof-float=4',
    '--known-sizeof-int=4',
    '--known-sizeof-long-long=8',
    '--known-sizeof-long=8',
    '--known-sizeof-short=2',
    '--known-sizeof-size_t=8',
    '--known-sizeof-void-p=8',
    '--with-batch=1',
    '--with-blas-lib=/path/to/libf2cblas.a',
    '--with-clanguage=cxx',
    '--with-cmake=1',
    '--with-debugging=0',
    '--with-fc=0',
    '--with-lapack-lib=/path/to/libf2clapack.a',
    '--with-mpi=0',
    '--with-parmetis=0',
    '--with-scalapack=0',
    '--with-shared-libraries=0',
    '--with-x=0',
    'PETSC_ARCH=arm64-unknown-darwin',
  ]
  configure.petsc_configure(configure_options)
