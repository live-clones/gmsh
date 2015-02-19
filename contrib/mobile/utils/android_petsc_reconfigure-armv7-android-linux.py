#!/usr/bin/python2
if __name__ == '__main__':
  import sys
  import os
  sys.path.insert(0, os.path.abspath('config'))
  import configure
  ndkroot='/Users/geuzaine/android-ndk-r8b/'
  ndkbin=ndkroot + 'toolchains/arm-linux-androideabi-4.6/prebuilt/darwin-x86/bin/'
  ndklibs=ndkroot + 'toolchains/arm-linux-androideabi-4.6/prebuilt/darwin-x86/user/libs/'
  ndklibs2=ndkroot + 'platforms/android-14/arch-arm/usr/lib/'
  externallibs='/Users/geuzaine/src/gmsh/contrib/mobile/frameworks_android/petsc/'
  configure_options = [
    '--AR=' + ndkbin + 'arm-linux-androideabi-ar',
    '--CC=' + ndkbin + 'arm-linux-androideabi-gcc',
    '--CFLAGS=--sysroot=' + ndkroot + 'platforms/android-8/arch-arm',
    '--CPP=' + ndkbin + 'arm-linux-androideabi-cpp',
    '--CPPFLAGS=--sysroot=' + ndkroot + 'platforms/android-8/arch-arm',
    '--CXX=' + ndkbin + 'arm-linux-androideabi-g++',
    '--CXXFLAGS=--sysroot=' + ndkroot + 'platforms/android-8/arch-arm -fsigned-char -march=armv7-a -mfloat-abi=softfp -mfpu=vfp -fdata-sections -ffunction-sections -fPIC -Wno-psabi -frtti -fexceptions -mthumb -O3 -fomit-frame-pointer -DNDEBUG -fPIC -isystem ' + ndkroot + 'platforms/android-8/arch-arm/usr/include -isystem ' + ndkroot + 'sources/cxx-stl/gnu-libstdc++/4.6/include -isystem ' + ndkroot + 'sources/cxx-stl/gnu-libstdc++/4.6/libs/armeabi-v7a/include -lstdc++',
    '--LDFLAGS= -L' + ndklibs + 'armeabi-v7a -L' + ndklibs2 + ' -lm',
    '--LD_SHARED=' + ndkbin + 'arm-linux-androideabi-ld',
    '--download-blacs=0',
    '--download-mumps=0',
    '--download-parmetis=0',
    '--download-scalapack=0',
    '--download-umfpack=0',
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
    '--with-blas-lib=' + externallibs + 'libf2cblas.so',
    '--with-clanguage=cxx',
    '--with-cmake=1',
    '--with-debugging=0',
    '--with-fc=0',
    '--with-lapack-lib=' + externallibs + 'libf2clapack.so',
    '--with-mpi=0',
    '--with-shared-libraries=1',
    '--with-x=0',
    '-I' + ndkroot + 'sources/cxx-stl/gnu-libstdc++/include/',
    '-I' + ndkroot + 'sources/cxx-stl/gnu-libstdc++/include/backward',
    '-I' + ndkroot + 'sources/cxx-stl/gnu-libstdc++/libs/armeabi/include',
    '-lstdc++',
    '-with-batch=1',
    'PETSC_ARCH=armv7-android-linux',
  ]
  configure.petsc_configure(configure_options)
