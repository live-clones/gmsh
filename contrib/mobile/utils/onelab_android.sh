#!/usr/bin/env bash

function checkError {
        if [ $# == 2 ]; then
                if [ $1 == 0 ]; then return; fi
                echo -e "\033[31m[-] $2 \033[0m"
                exit $1
        fi
}

if [ -z "$ANDROID_NDK" ]; then
        echo "ERROR: You must specify android NDK path: export ANDROID_NDK=/path/to/android-ndk/"
        exit 1
fi
if [ -z "$ANDROID_SDK" ]; then
        echo "ERROR: You must specify android SDK path: export ANDROID_NDK=/path/to/android-sdk/"
        exit 1
fi
if [ -z "$ANDROID_TOOLCHAIN" ] && [ -f "$ANDROID_TOOLCHAIN" ]; then
        echo "ERROR: You must specify a valid android toolchain: export ANDROID_TOOLCHAIN=/path/to/android.toolchain.cmake"
        exit 1
fi

echo -e "\033[1m[+] Take the last version of Gmsh and GetDP from svn\033[0m"
if [ ! -d "gmsh" ]; then mkdir svn --username gmsh --password gmsh co https://geuz.org/svn/gmsh/trunk gmsh; else svn up gmsh; fi
if [ ! -d "getdp" ]; then mkdir svn --username gmsh --password gmsh co https://geuz.org/svn/getdp/trunk getdp; else svn up getdp; fi

if [ ! -d "gmsh.android" ]; then mkdir gmsh.android; fi
if [ ! -d "getdp.android" ]; then mkdir getdp.android; fi
if [ ! -d "onelab.android" ]; then mkdir onelab.android; fi
if [ ! -f "petsc.android/libpetsc.so" ] || [ ! -f "petsc.android/libf2clapack.so" ] || [ ! -f "petsc.android/libf2cblas.so" ]; then 
	echo "ERROR: petsc.android do not exist or is incomplete (need blas, lapack and petsc)"
	exit 1
fi

cd gmsh.android
echo -e "\033[1m[+] Make Gmsh library\033[0m"
cmake -DDEFAULT=0 -DCMAKE_TOOLCHAIN_FILE=$ANDROID_TOOLCHAIN -DENABLE_BLAS_LAPACK=1 -DENABLE_BUILD_ANDROID=1 -DENABLE_MESH=1 -DENABLE_ONELAB=1 -DENABLE_PARSER=1 -DENABLE_POST=1 -DCMAKE_BUILD_TYPE=Release -DBLAS_LIB=../petsc.android/libf2cblas.so -DLAPACK_LIB=../petsc.android/libf2clapack.so ../gmsh
checkError $?  "CMake fail (Gmsh)"
make androidGmsh -j3
checkError $? "make fail (Gmsh)"
make getHeaders
checkError $? "make getHeaders fail (Gmsh)"

cd ../getdp.android
echo -e "\033[1m[+] Make GetDP library\033[0m"
cmake -DDEFAULT=0 -DCMAKE_TOOLCHAIN_FILE=$ANDROID_TOOLCHAIN -DENABLE_FORTRAN=0 -DENABLE_BUILD_ANDROID=1 -DENABLE_GMSH=1 -DENABLE_LEGACY=1 -DENABLE_PETSC=1 -DCMAKE_BUILD_TYPE=Release -DGMSH_INC=..//gmsh.android/Headers -DGMSH_LIB=../gmsh.android/libs/libGmsh.so -DPETSC_INC=../petsc.android/include/ -DPETSC_LIBS=../petsc.android/libpetsc.so ../getdp
checkError $? "CMake fail (GetDP)"
make androidGetdp -j3
checkError $? "make fail (GetDP)"
make getHeaders
checkError $? "make getHeaders fail (GetDP)"

cd ../onelab.android
echo -e "\033[1m[+] Make Onelab interface library\033[0m"
cmake -DCMAKE_TOOLCHAIN_FILE=$ANDROID_TOOLCHAIN -DENABLE_BUILD_ANDROID=1 -DGETDP_LIB=../getdp.android/libs/libGetDP.so -DGETDP_INC=../getdp.android/Headers/ -DGMSH_LIB=../gmsh.android/libs/libGmsh.so -DGMSH_INC=../gmsh.android/Headers/ ../gmsh/contrib/mobile/
checkError $? "CMake fail (Onelab)"
make androidOnelab -j3
checkError $? "make fail (Onelab)"

echo -e "\033[1m[+] Build Android application (java)\033[0m"
cd ../gmsh/contrib/mobile/Android
if [ ! -d "libs/armeabi-v7a/" ]; then mkdir -p libs/armeabi-v7a/; fi
cp $ANDROID_SDK/extras/android/support/v4/android-support-v4.jar libs/
checkError $? "Copy android support v4 fail (Android)"
cp ../../../../gmsh.android/libs/libGmsh.so libs/armeabi-v7a/
cp ../../../../getdp.android/libs/libGetDP.so libs/armeabi-v7a/
cp ../../../../onelab.android/libs/libOnelab.so libs/armeabi-v7a/
cp ../../../../petsc.android/libpetsc.so libs/armeabi-v7a/
cp ../../../../petsc.android/libf2clapack.so libs/armeabi-v7a/
cp ../../../../petsc.android/libf2cblas.so libs/armeabi-v7a/
target=1
count=0
while read line; do
        read line # Name
        target_name=$(echo $line | awk '{print $2}')
        target_version=$(echo $line | awk '{print $3}')
        read line # Type
        read line # API level
        target_api=$(echo $line | awk '{print $3}')
        read line # Revision
        read line # Skins
        if [ $target_api -ge 14 ]; then
                echo -e "\n\nBuild $target_name $target_version (target id: $target)"
                $ANDROID_SDK/tools/android update project --name Onelab --path . --target $target
                ant -quiet release
		checkError $? "ant fail ($(echo $target_name $target_version))"
                cp bin/Onelab-release.apk ../../../../Onelab-$(echo $target_name)_$(echo $target_version).apk
		if [ $? -ne 0 ]; then
                	cp bin/Onelab-release-unsigned.apk ../../../../Onelab-unsigned-$(echo $target_name)_$(echo $target_version).apk
		fi
		count=$(($count+1))
		break # build only for the first target
        fi
        read line # HACK
        target=$(($target+1))
done < <($ANDROID_SDK/tools/android list target | grep -A 5 "id:")
echo -e "\033[1m[V] Build $count apk(s)\033[0m"
exit 0
