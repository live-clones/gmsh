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
Buildroot: /var/tmp/%{name}-buildroot
Requires: Mesa >= 3.2

%description 
Gmsh is an automatic three-dimensional finite element mesh generator,
primarily Delaunay, with built-in pre- and post-processing
facilities. Its primal goal is to provide a simple meshing tool for
academic test cases with parametric input and up to date visualization
capabilities.  One of the strengths of Gmsh is its ability to respect
a characteristic length field for the generation of adapted meshes on
lines, surfaces and volumes. Gmsh requires OpenGL (or Mesa) to be
installed on your system.

Install Gmsh if you need a simple 3D finite element mesh generator
and/or post-processor.

%prep

%setup -c -q

%build
make distrib-linux-gcc-2.95
make utilities
rm -rf CVS */CVS */*/CVS

%install
rm -rf $RPM_BUILD_ROOT
mkdir -p $RPM_BUILD_ROOT/usr/bin
mkdir -p $RPM_BUILD_ROOT/usr/man/man1

install -m 755 bin/gmsh $RPM_BUILD_ROOT/usr/bin/gmsh
install -m 755 bin/gmsh-batch $RPM_BUILD_ROOT/usr/bin/gmsh-batch
install -m 755 bin/dxf2geo $RPM_BUILD_ROOT/usr/bin/dxf2geo
install -m 644 doc/gmsh.1 $RPM_BUILD_ROOT/usr/man/man1/gmsh.1

%clean
rm -rf $RPM_BUILD_ROOT

%files
%defattr(-,root,root)
%doc doc/FORMATS doc/VERSIONS doc/FAQ doc/CONTRIBUTORS demos tutorial
/usr/bin/gmsh
/usr/bin/gmsh-batch
/usr/bin/dxf2geo
/usr/man/man1/gmsh*

