
SRCDIR=gmsh-distrib
DMGNAME=gmsh.dmg
VOLNAME=gmsh

####################################################################
###### 1. create a disk image and format it
####################################################################

# compute total size of disk image (5% percent more than the
# total data size; this allows for the partition tables overhead:
# 64 sectors, 512 bytes each + some spare)
#
SIZE=`du -sk ${SRCDIR} | awk '{printf "%.3gn",($1*10.5)/(10240)}'`

# create the disk image
#
hdiutil create tmp.dmg -megabytes ${SIZE} -ov -type UDIF

# create /dev entries but do not mount it, else the Finder will prompt
# to initialize the disk (since the disk is not formatted yet)
#
# The output of hdid looks like
#
# /dev/disk2              Apple_partition_scheme         
# /dev/disk2s1            Apple_partition_map            
# /dev/disk2s2            Apple_HFS         
#
# MYDISK contains only the disk name, i.e. "disk2"
#
# To check to currently handled disks images, type
#
# hdiutils info
#
MYDISK=`hdid -nomount tmp.dmg |awk '/scheme/ {print substr ($1, 6, length)}'`

# make a new filesystem on the device
#
sudo newfs_hfs -v "$VOLNAME" /dev/r${MYDISK}s2

# eject the device
#
hdiutil eject $MYDISK

####################################################################
###### 2. mount the disk image and copy files to it
####################################################################

# mount the image
#
hdid tmp.dmg

# make sure that there are no locked files before running ditto 
# (ditto is the same as 'cp', except that it preserves resource 
# forks)
#
chflags -R nouchg,noschg "${SRCDIR}"
ditto -rsrcFork -v "${SRCDIR}" "/Volumes/${VOLNAME}"

# eject the device
#
hdiutil eject $MYDISK

####################################################################
###### 3. Convert to compressed image, delete temp image
####################################################################

# convert to compressed image
#
hdiutil convert tmp.dmg -format UDZO -o "${DMGNAME}"

# remove temp image
#
rm -f tmp.dmg

