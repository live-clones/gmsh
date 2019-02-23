#!/Users/geuzaine/anaconda/bin/python
if __name__ == '__main__':
  import sys
  import os
  sys.path.insert(0, os.path.abspath('config'))
  import configure
  configure_options = [
    '--CFLAGS=-isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS.sdk -miphoneos-version-min=8.0 -arch armv7 -arch armv7s -arch arm64 -fembed-bitcode -DPETSC_BLASLAPACK_UNDERSCORE',
    '--CXXFLAGS=-isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS.sdk -miphoneos-version-min=8.0 -arch armv7 -arch armv7s -arch arm64 -fembed-bitcode -DPETSC_BLASLAPACK_UNDERSCORE',
    '--download-suitesparse=yes',
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
    '--with-blas-lib=/Users/geuzaine/src/gmsh/contrib/mobile/frameworks_ios/petsc.framework/libf2cblas.a',
    '--with-clanguage=cxx',
    '--with-cmake=1',
    '--with-debugging=0',
    '--with-fc=0',
    '--with-ios=1',
    '--with-lapack-lib=/Users/geuzaine/src/gmsh/contrib/mobile/frameworks_ios/petsc.framework/libf2clapack.a',
    '--with-mpi=0',
    '--with-shared-libraries=0',
    '--with-ssl=0',
    '--with-x=0',
    'PETSC_ARCH=ios_real',
  ]
  configure.petsc_configure(configure_options)
