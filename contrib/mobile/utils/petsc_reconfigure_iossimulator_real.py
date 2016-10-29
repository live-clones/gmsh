#!/Users/geuzaine/anaconda/bin/python
if __name__ == '__main__':
  import sys
  import os
  sys.path.insert(0, os.path.abspath('config'))
  import configure
  configure_options = [
    '--CFLAGS=-isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneSimulator.platform/Developer/SDKs/iPhoneSimulator.sdk -miphoneos-version-min=8.0 -arch i386 -arch x86_64 -DPETSC_BLASLAPACK_UNDERSCORE',
    '--CXXFLAGS=-isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneSimulator.platform/Developer/SDKs/iPhoneSimulator.sdk -miphoneos-version-min=8.0 -arch i386 -arch x86_64 -DPETSC_BLASLAPACK_UNDERSCORE',
    '--download-suitesparse=yes',
    '--with-batch=1',
    '--with-blas-lib=/Applications/Xcode.app/Contents/Developer/Platforms/iPhoneSimulator.platform/Developer/SDKs/iPhoneSimulator.sdk/System/Library/Frameworks/Accelerate.framework/Frameworks/vecLib.framework/libBLAS.dylib',
    '--with-clanguage=cxx',
    '--with-cmake=1',
    '--with-debugging=0',
    '--with-fc=0',
    '--with-ios=1',
    '--with-lapack-lib=/Applications/Xcode.app/Contents/Developer/Platforms/iPhoneSimulator.platform/Developer/SDKs/iPhoneSimulator.sdk/System/Library/Frameworks/Accelerate.framework/Frameworks/vecLib.framework/libLAPACK.dylib',
    '--with-mpi=0',
    '--with-shared-libraries=0',
    '--with-ssl=0',
    '--with-x=0',
    'PETSC_ARCH=iossimulator_real',
  ]
  configure.petsc_configure(configure_options)
