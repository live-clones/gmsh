#include "GeoEarthImport.h"
GeoEarthImport::~GeoEarthImport(){
  //  printf("oya\n");
  //  myfile->close();
  //  printf("oyo\n");
  delete myfile;
}
GeoEarthImport::GeoEarthImport(const std::string &_filename)
  : filename(_filename)
{
  myfile = new std::ofstream(filename.c_str());
  size_field=NULL;
  loop_buff.precision(16);
  il=ip=ill=is=ifi=0;
  (*myfile) << "IP = newp;\n";
  (*myfile) << "IL = newl;\n";
  (*myfile) << "ILL = newll;\n";
  (*myfile) << "IS = news;\n";
  (*myfile) << "IFI = newf;\n";
  (*myfile) << "Point ( IP + " << ip++ << " ) = {0, 0, 0 , 1};\n";
  (*myfile) << "Point ( IP + " << ip++ << " ) = {0, 0, 6.371e6 , 1};\n";
  (*myfile) << "PolarSphere ( IS + " << is++ << " ) = {IP , IP+1};\n";
  new_surface();
  new_loop();  
}
void GeoEarthImport::set_size_field(Field *_size_field){
  size_field=_size_field;
}
void GeoEarthImport::add_point(const SPoint3 &point){
  SPoint3 midpoint = point;
  SPoint2 stereo(-point.x()/(1+point.z()),-point.y()/(1+point.z()));
  midpoint+=lastpoint;
  midpoint/=2;
  if( ip==first_point_in_loop || !size_field || point.distance(lastpoint)*6361e3 > (*size_field)(midpoint[0],midpoint[1],midpoint[2])){
    loop_buff<<"Point ( IP + "<<ip++<<" ) = {"<<stereo.x()<<", "<<stereo.y()<<", "<<0<<", 1};\n";
    lastpoint=point;
  }
}
void GeoEarthImport::add_point_lon_lat(const SPoint2 &ll){
  SPoint3 xyz( cos(ll.y())*cos(ll.x()), cos(ll.y())*sin(ll.x()), sin(ll.y()));
  add_point(xyz);
}
void GeoEarthImport::new_loop(){
  loop_buff.str("");
  first_point_in_loop=ip;
}
void GeoEarthImport::end_loop(){
  if(ip-first_point_in_loop>3){
    loop_buff<<"BSpline ( IL + "<<il++<<" ) = { IP + "<<first_point_in_loop<<" : IP + "<<ip-1<<", IP + "<<first_point_in_loop<<" };\n";
    loop_buff<<"Line Loop ( ILL + "<<ill++<<" ) = { IL + "<<il-1<<" };";
    (*myfile)<<loop_buff.str();	
    if(!empty_surface)
      surface_buff<<", ";
    surface_buff<< "ILL + "<<ill-1;
    empty_surface=false;
  }else{
    ip=first_point_in_loop;
  }
  new_loop();
}
void GeoEarthImport::new_surface(){
  surface_buff.str("");
  surface_buff<<"Plane Surface( IS + "<<is++<<" ) = { ";
  first_point_in_surface=ip;
  bool empty_surface=true;
}
void GeoEarthImport::end_surface(){
  if(!empty_surface){
    surface_buff<<"};\n";
    surface_buff<<"Field [ IFI + "<<ifi<<"]  = Attractor;\n";
    surface_buff<<"Field [ IFI + "<<ifi<<"].NodesList  = { IP + "<<first_point_in_surface <<" : IP + "<<ip-1<<" };";
    ifi++;
    (*myfile)<<surface_buff.str();	
  }
  new_surface();
}

/*static void projectLatLon(Point3D &psphere,Point &pplan){
<<<<<<< GeoEarthImport.cpp
  pplan.x=asin(psphere.z);
  pplan.y=atan2(psphere.y,psphere.x);
	pplan.zone_id=psphere.zone_id;
=======
        pplan.x=asin(psphere.z);
        pplan.y=atan2(psphere.y,psphere.x);
        pplan.zone_id=psphere.zone_id;
>>>>>>> 1.3
}
static void projectInvStereo(Point &pplan,Point3D &psphere){
        double rp2=pplan.x*pplan.x+pplan.y*pplan.y;
        psphere.z= (4-rp2)/(4+rp2);
        psphere.x= (1+psphere.z)/2*pplan.x;
        psphere.y= (1+psphere.z)/2*pplan.y;
        psphere.zone_id=pplan.zone_id;
}
static void projectStereo(Point3D &psphere,Point &pplan){
        pplan.x=2*psphere.x/(psphere.z+1);
        pplan.y=2*psphere.y/(psphere.z+1);
        pplan.zone_id=psphere.zone_id;
}*/
