Summary: A 3D mesh generator with pre- and post-processing facilities
Name: gmsh
Version: 0.998
Source: gmsh-0.998.tar.gz
Release: 1
Copyright: distributable
Group: Applications/Engineering
URL: http://www.geuz.org/gmsh/
Packager: Christophe.Geuzaine@AdValvas.be
Buildroot: /var/tmp/%{name}-buildroot
Requires: Mesa >= 3.0 lesstif >= 0.90

%description 
Gmsh is an automatic three-dimensional mesh generator, primarily
Delaunay, with pre- and post-processing facilities. Its primal goal is
to provide a simple meshing tool for academic test cases with
parametric input and up to date visualization capabilities.  One of
the strengths of Gmsh is its ability to respect a characteristic
length field for the generation of adapted meshes on lines, surfaces
and volumes. Gmsh requires the Mesa and Lesstif libraries to be
installed on your system.

Install Gmsh if you need a simple 3D finite element mesh generator.

%prep

%setup -c -q

%build
make linux
make utils
rm -rf CVS */CVS */*/CVS

%install
rm -rf $RPM_BUILD_ROOT
mkdir -p $RPM_BUILD_ROOT/usr/bin
mkdir -p $RPM_BUILD_ROOT/usr/man/man1

install -m 755 bin/gmsh $RPM_BUILD_ROOT/usr/bin/gmsh
install -m 755 bin/dxf2geo $RPM_BUILD_ROOT/usr/bin/dxf2geo
install -m 644 doc/gmsh.1 $RPM_BUILD_ROOT/usr/man/man1/gmsh.1

%clean
rm -rf $RPM_BUILD_ROOT

%files
%defattr(-,root,root)
%doc doc/FORMATS demos tutorial
/usr/bin/gmsh
/usr/bin/dxf2geo
/usr/man/man1/gmsh*

%changelog
* Sat Sep 23 2000 Christophe Geuzaine <Christophe.Geuzaine@AdValvas.be> 
 - initial revision
