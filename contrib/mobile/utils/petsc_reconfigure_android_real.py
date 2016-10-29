#!/usr/bin/python

######## FOR PETSC 3.6.0
######## I had to
########   change Cxx.py in the PETSc 3.6.0 distrib to replace CXXCPP by CPP
########   edit src/system/err.c to remove the exception throwing code
########   edit android_real/lib/petsc/conf/petscvariables:
########         remove the dylib stuff
########         edit SL_LINKER_FUNCTION: SL_LINKER_FUNCTION = -shared
########         edit SONAME_FUNCTION: SONAME_FUNCTION=$(1).$(2).so
########         add "-Wl,--unresolved-symbols=ignore-all" to the PCC_LINKER_FLAGS to
########           fix undefined ref to 'main'

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
    '--CXXFLAGS=--sysroot=' + ndkroot + 'platforms/android-8/arch-arm -fsigned-char -march=armv7-a -mfloat-abi=softfp -mfpu=vfp -fdata-sections -ffunction-sections -fPIC -Wno-psabi -frtti -fexceptions -mthumb -O3 -fomit-frame-pointer -DNDEBUG -fPIC -isystem ' + ndkroot + 'platforms/android-8/arch-arm/usr/include -isystem ' + ndkroot + 'sources/cxx-stl/gnu-libstdc++/4.6/include -isystem ' + ndkroot + 'sources/cxx-stl/gnu-libstdc++/4.6/libs/armeabi-v7a/include -lstdc++ -I' + ndkroot + 'sources/cxx-stl/gnu-libstdc++/4.6/include/ -I' + ndkroot + 'sources/cxx-stl/gnu-libstdc++/4.6/include/backward -I' + ndkroot + 'sources/cxx-stl/gnu-libstdc++/4.6/libs/armeabi/include',
    '--LDFLAGS= -L' + ndklibs + 'armeabi-v7a -L' + ndklibs2 + ' -lm',
    '--LD_SHARED=' + ndkbin + 'arm-linux-androideabi-ld',
    '--CLINKER=' + ndkbin + 'arm-linux-androideabi-gcc',
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
    '--download-suitesparse=yes',
    '--with-shared-libraries=1',
    '--with-x=0',
    '-I' + ndkroot + 'sources/cxx-stl/gnu-libstdc++/4.6/include/',
    '-I' + ndkroot + 'sources/cxx-stl/gnu-libstdc++/4.6/include/backward',
    '-I' + ndkroot + 'sources/cxx-stl/gnu-libstdc++/4.6/libs/armeabi/include',
    '-lstdc++',
    '-with-batch=1',
    'PETSC_ARCH=android_real',
  ]
  configure.petsc_configure(configure_options)
