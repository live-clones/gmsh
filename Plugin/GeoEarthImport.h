#ifndef _GEO_EARTH_IMPORT_H_
#define _GEO_EARTH_IMPORT_H_
#include "SPoint3.h"
#include "Field.h"
#include <sstream>
#include <fstream>
#include "GeoStringInterface.h"
class GeoEarthImport{
	Field *size_field;
	std::ostringstream loop_buff,surface_buff;;
	std::string filename;
	std::ofstream file;
	int il,ip,is,ill,ifi;
	int first_point_in_loop,first_point_in_surface;
	bool empty_surface;
	SPoint3 lastpoint;
	void new_surface();
	void new_loop();

	public :
	GeoEarthImport(const std::string _filename);
	~GeoEarthImport();
	void set_size_field(Field *_size_field);
	void add_point(const SPoint3 &point);
	void add_point_lon_lat(const SPoint2 &ll);
	void end_loop();
	void end_surface();
};
#endif
