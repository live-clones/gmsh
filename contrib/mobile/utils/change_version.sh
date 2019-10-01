#!/usr/bin/env bash

version=2.3.0
build=44 # must be incremented for each submitted build

# modify iOS/Onelab/Onelab-Info.plist
#
# <key>CFBundleShortVersionString</key><string>XXX</string>
# <key>CFBundleVersion</key><string>XXX</string>

sed -i "" "s/.*CFBundleShortVersionString.*/    <key>CFBundleShortVersionString<\/key><string>${version}<\/string>/" ../iOS/Onelab/Onelab-Info.plist
sed -i "" "s/.*CFBundleVersion.*/    <key>CFBundleVersion<\/key><string>${build}<\/string>/" ../iOS/Onelab/Onelab-Info.plist

# modify Android/app/src/main/AndroidManifest.xml
#
#   android:versionName="2.3.0"
#   android:versionCode="43"

sed -i "" "s/.*android:versionName.*/          android:versionName=\"${version}\"/" ../Android/app/src/main/AndroidManifest.xml
sed -i "" "s/.*android:versionCode.*/          android:versionCode=\"${build}\"/" ../Android/app/src/main/AndroidManifest.xml
