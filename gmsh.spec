Summary: A 3D mesh generator with pre- and post-processing facilities
Name: gmsh
# Version: 1.0
Version: %{gmshversion}
Source: gmsh-%{version}.tar.gz
Release: 1
Copyright: GPL
Group: Applications/Engineering
URL: http://www.geuz.org/gmsh/
Packager: geuz@geuz.org
Prereq: /sbin/install-info
Buildroot: /var/tmp/%{name}-buildroot
Requires: Mesa >= 3.2
Prefix: /usr

%description 
Gmsh is an automatic three-dimensional finite element mesh generator,
primarily Delaunay, with built-in pre- and post-processing
facilities. Its primal design goal is to provide a simple meshing tool
for academic test cases with parametric input and up to date
visualization capabilities. Gmsh requires OpenGL (or Mesa) to be
installed on your system.

Install Gmsh if you need a simple 3D finite element mesh generator
and/or post-processor.

%prep

%setup -c -q

%build
make distrib-unix
make utils
make doc-info
strip bin/gmsh
rm -rf CVS */CVS */*/CVS

%install
rm -rf $RPM_BUILD_ROOT
mkdir -p $RPM_BUILD_ROOT/usr/bin
mkdir -p $RPM_BUILD_ROOT/usr/share/man/man1
mkdir -p $RPM_BUILD_ROOT/usr/share/info

install -m 755 bin/gmsh $RPM_BUILD_ROOT/usr/bin/gmsh
install -m 755 bin/dxf2geo $RPM_BUILD_ROOT/usr/bin/dxf2geo
install -m 755 bin/mshsort $RPM_BUILD_ROOT/usr/bin/mshsort
install -m 644 doc/gmsh.1 $RPM_BUILD_ROOT/usr/share/man/man1/gmsh.1
install -m 644 doc/texinfo/gmsh.info* $RPM_BUILD_ROOT/usr/share/info/

%post
/sbin/install-info /usr/share/info/gmsh.info /usr/share/info/dir

%clean
rm -rf $RPM_BUILD_ROOT

%files
%defattr(-,root,root)
%doc doc/LICENSE doc/VERSIONS doc/FAQ doc/CREDITS demos tutorial
/usr/bin/gmsh
/usr/bin/dxf2geo
/usr/bin/mshsort
/usr/share/man/man1/gmsh*
/usr/share/info/gmsh*
