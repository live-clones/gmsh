// $Id: Field.cpp,v 1.20 2008-03-19 08:57:35 remacle Exp $
//
// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include <list>
#include <math.h>
#include <fstream>
#include <string>
#include <sstream>

#ifdef HAVE_MATH_EVAL
#include "matheval.h"
#endif
#ifdef HAVE_ANN
#include "ANN/ANN.h"
#endif

#include "Context.h"
#include "Field.h"
#include "GeoInterpolation.h"
#include "GModel.h"
#include "Message.h"
#include "OctreePost.h"
#include "PViewDataList.h"

#define MAX_LC 1.e22

extern Context_T CTX;

class FieldOptionDouble:public FieldOption{
	public:
	double &val;
	FieldOptionType get_type(){return FIELD_OPTION_DOUBLE;};
	FieldOptionDouble(double &_val,bool *_status=NULL):FieldOption(_status),val(_val){};
	double numerical_value()const { return val;};
	void numerical_value(double v){modified(); val=v;};
	void get_text_representation(std::string &v_str){
		std::ostringstream sstream;
		sstream.precision(16);
		sstream<<val;
		v_str=sstream.str();
	}
};

class FieldOptionInt:public FieldOption{
	public:
	int &val;
	FieldOptionType get_type(){return FIELD_OPTION_INT;};
	FieldOptionInt(int &_val, bool *_status=NULL):FieldOption(_status),val(_val){};
	double numerical_value()const{ return val;};
	void numerical_value(double v){modified(); val=v;};
	void get_text_representation(std::string &v_str){
		std::ostringstream sstream;
		sstream<<val;
		v_str=sstream.str();
	}
};
class FieldOptionList:public FieldOption{
	public:
	std::list<int> &val;
	FieldOptionType get_type(){return FIELD_OPTION_LIST;};
	FieldOptionList(std::list<int> &_val, bool *_status=NULL):FieldOption(_status),val(_val){};
	std::list<int> &list(){modified(); return val; }
	const std::list<int> &list()const { return val; }
	void get_text_representation(std::string &v_str){
		std::ostringstream sstream;
		sstream<<"{";
		for(std::list<int>::iterator it=val.begin();it!=val.end();it++){
			if(it!=val.begin())
				sstream<<", ";
			sstream<<*it;
		}
		sstream<<"}";
		v_str=sstream.str();
	}
};
class FieldOptionString:public FieldOption{
	public:
	std::string &val;
	virtual FieldOptionType get_type(){return FIELD_OPTION_STRING;};
	FieldOptionString(std::string &_val, bool *_status=NULL):FieldOption(_status),val(_val){};
	std::string &string(){modified(); return val; }
	const std::string &string()const {return val; }
	void get_text_representation(std::string &v_str){
		std::ostringstream sstream;
		sstream<<"\""<<val<<"\"";
		v_str=sstream.str();
	}
};
class FieldOptionBool:public FieldOption{
	public:
	bool &val;
	FieldOptionType get_type(){return FIELD_OPTION_BOOL;};
	FieldOptionBool(bool &_val, bool *_status=NULL):FieldOption(_status),val(_val){};
	double numerical_value()const { return val;};
	void numerical_value(double v){modified(); val=v;};
	void get_text_representation(std::string &v_str){
		std::ostringstream sstream;
		sstream<<val;
		v_str=sstream.str();
	}
};
class FieldOptionPath:public FieldOptionString{
	public:
	FieldOptionType get_type(){return FIELD_OPTION_PATH;};
};

void FieldManager::reset()
{
  for(std::map<int,Field*>::iterator it = begin(); it != end(); it++){
    delete it->second;
  }
  clear();
}

Field *FieldManager::get(int id)
{
  iterator it = find(id);
  if(it == end()){
    return NULL;
  }
  return it->second;
}

Field *FieldManager::new_field(int id, const char *type_name)
{
	if(find(id) != end()){
		Msg(GERROR, "Field id %i is already defined.",id);
		return NULL;
	}
	if(map_type_name.find(type_name) == map_type_name.end()){
		Msg(GERROR, "Unknown field type \"%s\".",type_name);
		return NULL;
	}
	Field *f=(*map_type_name[type_name])();
	if(!f)
		return NULL;
	f->id=id;
	(*this)[id]=f;
  return f;
}

int FieldManager::new_id(){
	int i=0;
	iterator it=begin();
	while(1){
		i++;
		while(it!=end() && it->first<i)it++;
		if(it==end() || it->first!=i)break;
	}
	return std::max(i,1);
}
int FieldManager::max_id(){
	if(!empty())
		return rbegin()->first;
	else return 0;
}
void FieldManager::delete_field(int id){
	iterator it=find(id);
	if(it==end()){
		Msg(GERROR, "Cannot delete field id %i, it does not exist.",id);
		return;
	}
	delete it->second;
	erase(it);
}

// StructuredField
class StructuredField : public Field{
  double o[3], d[3];
  int n[3];
  double *data;
	bool error_status;
	std::string file_name;
public :
  StructuredField(){
		options["FileName"]=new FieldOptionString(file_name,&update_needed);
		data=NULL;
	}
	const char *get_name(){
		return "Structured";
	}
  virtual ~StructuredField(){
		if(data) delete []data;
	}
  double operator()(double x, double y, double z){
		if(update_needed){
			error_status=false;
			try{
				std::ifstream input(file_name.c_str());
				if(!input.is_open())throw(1);
				input.exceptions ( std::ifstream::eofbit | std::ifstream::failbit | std::ifstream::badbit );
				input.read((char*)o, 3 * sizeof(double));
				input.read((char*)d, 3 * sizeof(double));
				input.read((char*)n, 3 * sizeof(int));
				int nt = n[0] * n[1] * n[2];
				if(data) delete []data;
				data = new double[nt];
				input.read((char*)data, nt * sizeof(double));
				input.close();
			}
			catch(...){
				error_status=true;
				Msg(GERROR,"Field %i : error reading file %s",this->id,file_name.c_str());
			}
			update_needed=false;
		}
		if(error_status)return MAX_LC;
		//tri-linear
		int id[2][3];
		double xi[3];
		double xyz[3]={x,y,z};
		for(int i = 0; i < 3; i++){
			id[0][i] = (int)floor((xyz[i] - o[i]) / d[i]);
			id[1][i] = id[0][i] + 1;
			id[0][i] = std::max(std::min(id[0][i], n[i] - 1), 0);
			id[1][i] = std::max(std::min(id[1][i], n[i] - 1), 0);
			xi[i] = xyz[i] - (o[i] + id[0][i] * d[i]);
			xi[i] = std::max(std::min(xi[i], 1.), 0.);
		}
		double v = 0;
		for(int i = 0; i < 2; i++) 
			for(int j = 0;j < 2; j++)
				for(int k = 0; k < 2; k++){
		v += data[id[i][0] * n[1] * n[2] + id[j][1] * n[2] + id[k][2]]
			* (i * xi[0] + (1 - i) * (1 - xi[0]))
			* (j * xi[1] + (1 - j) * (1 - xi[1]))
			* (k * xi[2] + (1 - k) * (1 - xi[2]));
				}
		return v;
	}
	FieldDialogBox *&dialog_box(){
		static FieldDialogBox *dialogBox=NULL;
		return dialogBox;
	}
};

class LonLatField : public Field{
	int field_id;
public:
  LonLatField(){
		field_id=1;
		options["IField"]=new FieldOptionInt(field_id);
	}
	const char *get_name(){return "LonLat";}
  double operator()(double x, double y, double z){
		return (*GModel::current()->fields.get(field_id))(atan2(x,y),asin(z / sqrt(x * x + y * y + z * z)), 0);
	}
	FieldDialogBox *&dialog_box(){
		static FieldDialogBox *dialogBox=NULL;
		return dialogBox;
	}
};

class BoxField : public Field{
	double v_in,v_out,x_min,x_max,y_min,y_max,z_min,z_max;
	public:
	BoxField(){
		v_in=v_out=x_min=x_max=y_min=y_max=z_min=z_max=0;
		options["VIn"]=new FieldOptionDouble(v_in);
		options["VOut"]=new FieldOptionDouble(v_out);
		options["XMin"]=new FieldOptionDouble(x_min);
		options["XMax"]=new FieldOptionDouble(x_max);
		options["YMin"]=new FieldOptionDouble(y_min);
		options["YMax"]=new FieldOptionDouble(y_max);
		options["ZMin"]=new FieldOptionDouble(z_min);
		options["ZMax"]=new FieldOptionDouble(z_max);
	}
	const char *get_name(){return "Box";}
	FieldDialogBox *&dialog_box(){
		static FieldDialogBox *dialogBox=NULL;
		return dialogBox;
	}
  double operator()(double x, double y, double z){
		return (x<=x_max && x>=x_min && y<=y_max && y>=y_min && z<=z_max && z>=z_min) ?
			v_in : v_out;
	}
};


class ThresholdField : public Field{
	int iField;
  double dmin, dmax, lcmin, lcmax;
	public:
	const char *get_name(){
		return "Threshold";
	}
  ThresholdField(){
		iField=0;
		dmin=1;
		dmax=10;
		lcmin=0.1;
		lcmax=1;
		options["IField"]=new FieldOptionInt(iField);
		options["DistMin"]=new FieldOptionDouble(dmin);
		options["DistMax"]=new FieldOptionDouble(dmax);
		options["LcMin"]=new FieldOptionDouble(lcmin);
		options["LcMax"]=new FieldOptionDouble(lcmax);
	}
  double operator()(double x, double y, double z){
		Field *field=GModel::current()->fields.get(iField);
		double r = ((*field)(x, y, z) - dmin) / (dmax - dmin);
		r = std::max(std::min(r, 1.), 0.);
		double lc = lcmin * (1 - r) + lcmax * r;
		return lc;
	}
	FieldDialogBox *&dialog_box(){
		static FieldDialogBox *dialogBox=NULL;
		return dialogBox;
	}
};


class GradientField : public Field{
	int iField,kind;
	double delta;
	public:
	const char *get_name(){
		return "Gradient";
	}
  GradientField():iField(0),kind(3),delta(CTX.lc/1e4){
		options["IField"]=new FieldOptionInt(iField);
		options["Kind"]=new FieldOptionInt(kind);
		options["Delta"]=new FieldOptionDouble(delta);
	}
  double operator()(double x, double y, double z){
		Field *field=GModel::current()->fields.get(iField);
		double gx, gy, gz;
		switch(kind){
		case 0 : /* x */
			return ((*field)(x + delta / 2, y, z) - (*field)(x - delta / 2, y, z)) / delta;
		case 1 : /* y */
			return ((*field)(x, y + delta / 2, z) - (*field)(x, y - delta / 2, z)) / delta;
		case 2 : /* z */
			return ((*field)(x, y, z + delta / 2) - (*field)(x, y, z - delta / 2)) / delta;
		case 3 : /* norm */
			gx = ((*field)(x + delta / 2, y, z) - (*field)(x - delta / 2, y, z)) / delta;
			gy = ((*field)(x, y + delta / 2, z) - (*field)(x, y - delta / 2, z)) / delta;
			gz = ((*field)(x, y, z + delta / 2) - (*field)(x, y, z - delta / 2)) / delta;
			return sqrt(gx * gx + gy * gy + gz * gz);
		default :
			Msg(GERROR, "Field %i : Unknown kind (%i) of gradient.",this->id, kind);
			return MAX_LC;
		}
	}
	FieldDialogBox *&dialog_box(){
		static FieldDialogBox *dialogBox=NULL;
		return dialogBox;
	}
};

#if defined(HAVE_MATH_EVAL)
class MathEvalExpression{
	bool error_status;
  std::list<Field*> *list;
	int nvalues;
  char **names;
  double *values;
  void *eval;
	int *evaluators_id;
	std::string function;
	char *c_str_function;
	public:
	double evaluate(double x,double y, double z){
		if(error_status) return MAX_LC;
		for(int i=0;i<nvalues;i++){
			Field *f;
			switch (evaluators_id[i]){
				case -1: values[i]=x; break;
				case -2: values[i]=y; break;
				case -3: values[i]=z; break;
				default: {
					f=GModel::current()->fields.get(evaluators_id[i]);
					values[i] = f ? (*f)(x,y,z) : MAX_LC;
				}
			}
		}
		return evaluator_evaluate(eval, nvalues, names, values);
	}
	MathEvalExpression(){
		eval=NULL;
		values=NULL;
		c_str_function=NULL;
		evaluators_id=NULL;
	}
	bool set_function(const std::string &f){
		free_members();
		error_status=false;
		c_str_function=strdup(f.c_str());
		eval = evaluator_create(c_str_function);
		if(!eval){
			error_status=true;
			return false;
		}
		evaluator_get_variables(eval,&names,&nvalues);
		values = new double[nvalues];
		evaluators_id=new int[nvalues];
		for(int i=0;i<nvalues;i++){
			int id;
			if(!strcmp("x",names[i])) evaluators_id[i]=-1;
			else if(!strcmp("y",names[i])) evaluators_id[i]=-2;
			else if(!strcmp("z",names[i])) evaluators_id[i]=-3;
			else if(sscanf(names[i],"F%i",&id)==1) evaluators_id[i]=id;
			else{
				Msg(GERROR, "Unknown matheval argument \"%s\"\n",names[i]);
				error_status=true;
				return false;
			}
		}
		return true;
	}
	void free_members(){
		if(c_str_function)free(c_str_function);
		if(eval) evaluator_destroy(eval);
		if(values)delete[]values;
		if(evaluators_id) delete evaluators_id;
	}
	~MathEvalExpression(){
		free_members();
	}
};

class MathEvalField : public Field{
	MathEvalExpression expr;
	std::string f;
	public:
	MathEvalField(){
		options["F"]=new FieldOptionString(f,&update_needed);
	}
  double operator()(double x, double y, double z){
		if(update_needed){
			if(!expr.set_function(f))
				Msg(GERROR, "Field %i : Invalid matheval expression \"%s\"\n",this->id,f.c_str());
			update_needed=false;
		}
		return expr.evaluate(x,y,z);
	}
	FieldDialogBox *&dialog_box(){
		static FieldDialogBox *dialogBox=NULL;
		return dialogBox;
	}
	const char *get_name(){return "MathEval";}
};
class ParametricField : public Field{
	MathEvalExpression expr[3];
	std::string f[3];
	int ifield;
	public:
	ParametricField(){
		options["IField"] = new FieldOptionInt(ifield);
		options["FX"]=new FieldOptionString(f[0],&update_needed);
		options["FY"]=new FieldOptionString(f[1],&update_needed);
		options["FZ"]=new FieldOptionString(f[2],&update_needed);
	}
  double operator()(double x, double y, double z){
		if(update_needed){
			for(int i=0;i<3;i++){
				if(!expr[i].set_function(f[i]))
					Msg(GERROR, "Field %i : Invalid matheval expression \"%s\"\n",this->id,f[i].c_str());
			}
			update_needed=false;
		}
		return (*GModel::current()->fields.get(ifield))(expr[0].evaluate(x,y,z),expr[1].evaluate(x,y,z),expr[2].evaluate(x,y,z));
	}
	FieldDialogBox *&dialog_box(){
		static FieldDialogBox *dialogBox=NULL;
		return dialogBox;
	}
	const char *get_name(){return "Param";}
};
#endif

class PostViewField:public Field{
  OctreePost *octree;
	public : 
	int view_index;
	double operator()(double x, double y, double z) {
		// FIXME: should test unique view num instead, but that would be slower
		if(view_index < 0 || view_index >= (int)PView::list.size()) return MAX_LC;
		if(update_needed){
			if(octree)delete octree;
			octree = new OctreePost(PView::list[view_index]);
			update_needed=false;
		}
		double l = 0.;
		if(!octree->searchScalar(x, y, z, &l, 0)){
			// uncomment the following to try really hard to find an element
			// around the point
			/*
			double fact[9] = {0.001, 0.0025, 0.005, 0.0075, 0.01, 0.025, 0.05, 0.075, 0.1};
			for(int i = 0; i < 9; i++){
				double eps = CTX.lc * fact[i];
				if(octree->searchScalar(x + eps, y, z, &l, 0)) break;
				if(octree->searchScalar(x - eps, y, z, &l, 0)) break;
				if(octree->searchScalar(x, y + eps, z, &l, 0)) break;
				if(octree->searchScalar(x, y - eps, z, &l, 0)) break;
				if(octree->searchScalar(x, y, z + eps, &l, 0)) break;
				if(octree->searchScalar(x, y, z - eps, &l, 0)) break;
				if(octree->searchScalar(x + eps, y - eps, z - eps, &l, 0)) break;
				if(octree->searchScalar(x + eps, y + eps, z - eps, &l, 0)) break;
				if(octree->searchScalar(x - eps, y - eps, z - eps, &l, 0)) break;
				if(octree->searchScalar(x - eps, y + eps, z - eps, &l, 0)) break;
				if(octree->searchScalar(x + eps, y - eps, z + eps, &l, 0)) break;
				if(octree->searchScalar(x + eps, y + eps, z + eps, &l, 0)) break;
				if(octree->searchScalar(x - eps, y - eps, z + eps, &l, 0)) break;
				if(octree->searchScalar(x - eps, y + eps, z + eps, &l, 0)) break;
			}
			*/
		}
		//if(l <= 0) return MAX_LC;
		return l;
	}
	const char *get_name(){ return "PostView"; }
	PostViewField() {
		octree=NULL;
		options["IView"]=new FieldOptionInt(view_index,&update_needed);
	}
	~PostViewField(){
		if(octree) delete octree;
	}
	FieldDialogBox *&dialog_box(){
		static FieldDialogBox *dialogBox=NULL;
		return dialogBox;
	}
};

class MinField : public Field{
	std::list<int> idlist;
	public:
	MinField(){
		options["FieldsList"]=new FieldOptionList(idlist,&update_needed);
	}
  double operator()(double x, double y, double z){
		double v=MAX_LC;
		for(std::list<int>::iterator it=idlist.begin();it!=idlist.end();it++){
			Field *f=(GModel::current()->fields.get(*it));
			if(f)
				v=std::min(v,(*f)(x,y,z));
		}
		return v;
	}
	FieldDialogBox *&dialog_box(){
		static FieldDialogBox *dialogBox=NULL;
		return dialogBox;
	}
 const char *get_name(){return "Min";}
};

class MaxField : public Field{
	std::list<int> idlist;
	public:
	MaxField(){
		options["FieldsList"]=new FieldOptionList(idlist,&update_needed);
	}
  double operator()(double x, double y, double z){
		double v=-MAX_LC;
		for(std::list<int>::iterator it=idlist.begin();it!=idlist.end();it++){
			Field *f=(GModel::current()->fields.get(*it));
			if(f)
				v=std::max(v,(*f)(x,y,z));
		}
		return v;
	}
	FieldDialogBox *&dialog_box(){
		static FieldDialogBox *dialogBox=NULL;
		return dialogBox;
	}
	const char *get_name(){return "Max";}
};
#ifdef HAVE_ANN
class AttractorField : public Field{
  ANNkd_tree* kdtree;
  ANNpointArray zeronodes;
  ANNidxArray index;
  ANNdistArray dist;
  std::list<int> nodes_id;  
  std::list<int> edges_id;  
	int n_nodes_by_edge;
public :
  AttractorField(): kdtree (0), zeronodes(0) {
		index = new ANNidx[1];
		dist = new ANNdist[1];
		options["NodesList"]=new FieldOptionList(nodes_id,&update_needed);
		options["EdgesList"]=new FieldOptionList(edges_id,&update_needed);
		options["NNodesByEdge"]=new FieldOptionInt(n_nodes_by_edge,&update_needed);
		n_nodes_by_edge=20;
	}
  ~AttractorField(){
		if(kdtree) delete kdtree;
		if(zeronodes) annDeallocPts(zeronodes);
		delete [] index;
		delete [] dist;
	}
	const char *get_name(){
		return "Attractor";
	}
  virtual double operator()(double X, double Y, double Z){
		if(update_needed){
			if(zeronodes){
				annDeallocPts(zeronodes);
				delete kdtree;
			}
			int totpoints = nodes_id.size()+n_nodes_by_edge*edges_id.size();
			if (totpoints)
				zeronodes = annAllocPts(totpoints, 4);
			int k = 0;
			for(std::list <int>::iterator it = nodes_id.begin(); it != nodes_id.end(); ++it){
				Vertex *v = FindPoint(*it); 
				if(v){
					zeronodes[k][0]=v->Pos.X;
					zeronodes[k][1]=v->Pos.Y;
					zeronodes[k++][2]=v->Pos.Z;
				}else{
					GVertex *gv = GModel::current()->getVertexByTag(*it);
					if(gv){
						zeronodes[k][0]=gv->x();
						zeronodes[k][1]=gv->y();
						zeronodes[k++][2]=gv->z();
					}
				}
			}
			for(std::list <int>::iterator it = edges_id.begin(); it != edges_id.end(); ++it){
				Curve *c = FindCurve(*it); 
				if(c){
					for(int i = 0; i < n_nodes_by_edge ; i++){
						double u = (double)i / (n_nodes_by_edge - 1);
						Vertex V = InterpolateCurve(c, u, 0);
						zeronodes[k][0]=V.Pos.X;
						zeronodes[k][1]=V.Pos.Y;
						zeronodes[k++][2]=V.Pos.Z;
					}
				}else{
					GEdge *ge = GModel::current()->getEdgeByTag(*it);
					if(ge){
						for(int i = 0; i < n_nodes_by_edge; i++){
							double u = (double)i / (n_nodes_by_edge - 1);
							Range<double> b = ge->parBounds(0);
							double t = b.low() + u * (b.high() - b.low());
							GPoint gp = ge->point(t);
							zeronodes[k][0]=gp.x();
							zeronodes[k][1]=gp.y();
							zeronodes[k++][2]=gp.z();
						}
					}
				}
			}
			kdtree = new ANNkd_tree(zeronodes, totpoints, 3);
			update_needed=false;
		}
		double xyz[3] = {X, Y, Z};
		kdtree->annkSearch(xyz, 1, index, dist);
		return sqrt(dist[0]);
	}
	FieldDialogBox *&dialog_box(){
		static FieldDialogBox *dialogBox=NULL;
		return dialogBox;
	}
};
#endif

#if 0
void addMapLc (std::map<MVertex*, double> &maplc, MVertex *v, double l)
{
  std::map<MVertex*, double>::iterator it = maplc.find(v);
  if(it == maplc.end()) maplc[v] = l;
  else if(it->second > l) it->second = l;
}
#endif

#if 0
/*class AttractorField_1DMesh : public AttractorField 
{
protected:
  std::vector<double> lcs;
  std::vector<double> lcs2;
  double _dmax,_dmin,_lcmax;
public:
  AttractorField_1DMesh (GModel *m , double dmax, double dmin, double lcmax);
  AttractorField_1DMesh (GFace  *gf, double dmax, double dmin, double lcmax);
  virtual double operator()(double X, double Y, double Z) ;
  virtual void eval(double X, double Y, double Z, double &l, double &lpt, double &dist) ;
};*/
AttractorField_1DMesh::AttractorField_1DMesh(GModel *m, double dmax, double dmin, 
					     double lcmax)
  : _dmax(dmax), _dmin(dmin), _lcmax(lcmax)
{
  GModel::eiter it = m->firstEdge();

  std::map<MVertex*, double> maplc;

  while(it != m->lastEdge()){
    MVertex *first = (*it)->getBeginVertex()->mesh_vertices[0];
    for(unsigned int i = 1; i <= (*it)->mesh_vertices.size(); ++i){
      MVertex *last = (i == (*it)->mesh_vertices.size()) ? 
	(*it)->getEndVertex()->mesh_vertices[0] : (*it)->mesh_vertices[i];
      double l = sqrt((first->x() - last->x()) * (first->x() - last->x()) +
		      (first->y() - last->y()) * (first->y() - last->y()) +
		      (first->z() - last->z()) * (first->z() - last->z()));
      addMapLc(maplc, first, l);
      addMapLc(maplc, last, l);
      first = last;
    }
  }      
  
  std::map<MVertex*, double>::iterator itm = maplc.begin();
  
  while(itm != maplc.end()){
    addPoint(itm->first->x(), itm->first->y(), itm->first->z());
    lcs.push_back(itm->second);
  }
}

AttractorField_1DMesh::AttractorField_1DMesh(GFace *gf, double dmax, double dmin, 
					     double lcmax)
  : _dmax(dmax), _dmin(dmin), _lcmax(lcmax)
{
  std::list<GEdge*> edges = gf->edges(); 
  std::list<GEdge*>::iterator it = edges.begin();

  std::map<MVertex*, double> maplc;
  std::map<MVertex*, double> maplc2;

  while(it != edges.end()){
    MVertex *first = (*it)->getBeginVertex()->mesh_vertices[0];
    for(unsigned int i = 1; i <= (*it)->mesh_vertices.size(); ++i){
      MVertex *last = (i == (*it)->mesh_vertices.size()) ? 
	(*it)->getEndVertex()->mesh_vertices[0] : (*it)->mesh_vertices[i];
      double l = sqrt((first->x() - last->x()) * (first->x() - last->x()) +
		      (first->y() - last->y()) * (first->y() - last->y()) +
		      (first->z() - last->z()) * (first->z() - last->z()));
      double t;
      last->getParameter(0,t);
      double l2 = LC_MVertex_PNTS(last->onWhat(),t,0);
      addMapLc(maplc, first, l);
      addMapLc(maplc, last, l);
      addMapLc(maplc2, first, l2);
      addMapLc(maplc2, last, l2);
      first = last;      
    }
    ++it;
  }      
  
  std::map<MVertex*, double>::iterator itm = maplc.begin();  
  while(itm != maplc.end()){
    addPoint(itm->first->x(), itm->first->y(), itm->first->z());
    lcs.push_back(itm->second);
    ++itm;
  }
  itm = maplc2.begin();  
  while(itm != maplc2.end()){
    lcs2.push_back(itm->second);
    ++itm;
  }
}

double AttractorField_1DMesh::operator()(double X, double Y, double Z)
{
#ifdef HAVE_ANN
  double xyz[3] = {X, Y, Z};
  kdtree->annkSearch(xyz, maxpts, index, dist);
  double d = sqrt(dist[0]);
  double lcmin = lcs[index[0]];
  double r = (d - _dmin) / (_dmax - _dmin);
  r = std::max(std::min(r, 1.), 0.);
  double lc = lcmin * (1 - r) + _lcmax * r;
  return lc;
#else
  Msg(GERROR,"GMSH should be compiled with ANN in order to enable attractors");
  return 1.e22;
#endif
}

void AttractorField_1DMesh::eval(double X, double Y, double Z, double &lcmin, double &lcpt, double &d)
{
#ifdef HAVE_ANN
  double xyz[3] = {X, Y, Z};
  kdtree->annkSearch(xyz, maxpts, index, dist);
  d = sqrt(dist[0]);
  lcmin = lcs[index[0]];
  lcpt  = lcs2[index[0]] * CTX.mesh.lc_factor;
#else
  Msg(GERROR,"GMSH should be compiled with ANN in order to enable attractors");
#endif
}
#endif

template<class F>
class FieldFactoryT:public FieldFactory{
	public:
	Field *operator()(){return new F;};
};

template<class F>
Field *field_factory(){return new F();};

FieldManager::FieldManager(){
	map_type_name["Structured"]=new FieldFactoryT<StructuredField>();
	map_type_name["Threshold"]=new FieldFactoryT<ThresholdField>();
	map_type_name["Box"]=new FieldFactoryT<BoxField>();
	map_type_name["LonLat"]=new FieldFactoryT<LonLatField>();
#if defined(HAVE_MATH_EVAL)
	map_type_name["Param"]=new FieldFactoryT<ParametricField>();
	map_type_name["MathEval"]=new FieldFactoryT<MathEvalField>();
#endif
#if defined(HAVE_ANN)
	map_type_name["Attractor"]=new FieldFactoryT<AttractorField>();
#endif
	map_type_name["PostView"]=new FieldFactoryT<PostViewField>();
	map_type_name["Gradient"]=new FieldFactoryT<GradientField>();
	map_type_name["Min"]=new FieldFactoryT<MinField>();
	map_type_name["Max"]=new FieldFactoryT<MaxField>();
	background_field=-1;
}

static void evaluate(Field *field, List_T *list1, int nbElm1, int nbNod, 
		     int nbComp, int comp )
{
  if(!nbElm1) return;
  int nb = List_Nbr(list1) / nbElm1;
  for(int i = 0; i < List_Nbr(list1); i += nb) {
    double *x = (double *)List_Pointer_Fast(list1, i);
    double *y = (double *)List_Pointer_Fast(list1, i + nbNod);
    double *z = (double *)List_Pointer_Fast(list1, i + 2 * nbNod);
    for(int j = 0; j < nbNod; j++) {
      // store data from the main view into v
      double *val1 = (double *)List_Pointer_Fast(list1, 
						 i + 3 * nbNod + 
						 nbNod * nbComp * 0 + nbComp * j);
      val1[comp] = (*field)(x[j],y[j],z[j]);
    }
  }
}

Field::Field(){
}

void Field::put_on_view(PView *view,int comp)
{
  PViewDataList *data = dynamic_cast<PViewDataList*>(view->getData());
  if(!data) return ;
  evaluate(this, data->SP, data->NbSP, 1, 1, 0);
  evaluate(this, data->SL, data->NbSL, 2, 1, 0);
  evaluate(this, data->ST, data->NbST, 3, 1, 0);
  evaluate(this, data->SQ, data->NbSQ, 4, 1, 0);      
  evaluate(this, data->SS, data->NbSS, 4, 1, 0);
  evaluate(this, data->SH, data->NbSH, 8, 1, 0);      
  evaluate(this, data->SI, data->NbSI, 6, 1, 0);
  evaluate(this, data->SY, data->NbSY, 5, 1, 0);
  for(int cc = 0; cc < 3; cc++){
    if(comp < 0 || comp == cc){
      evaluate(this, data->VP, data->NbVP, 1, 3, cc);
      evaluate(this, data->VL, data->NbVL, 2, 3, cc);
      evaluate(this, data->VT, data->NbVT, 3, 3, cc);
      evaluate(this, data->VQ, data->NbVQ, 4, 3, cc);
      evaluate(this, data->VS, data->NbVS, 4, 3, cc);
      evaluate(this, data->VH, data->NbVH, 8, 3, cc);
      evaluate(this, data->VI, data->NbVI, 6, 3, cc);
      evaluate(this, data->VY, data->NbVY, 5, 3, cc);
    }
  }
  for(int cc = 0; cc < 9; cc++){
    if(comp < 0 || comp == cc){
      evaluate(this, data->TP, data->NbTP, 1, 9, cc);
      evaluate(this, data->TL, data->NbTL, 2, 9, cc);
      evaluate(this, data->TT, data->NbTT, 3, 9, cc);      
      evaluate(this, data->TQ, data->NbTQ, 4, 9, cc);
      evaluate(this, data->TS, data->NbTS, 4, 9, cc);
      evaluate(this, data->TH, data->NbTH, 8, 9, cc);
      evaluate(this, data->TI, data->NbTI, 6, 9, cc);
      evaluate(this, data->TY, data->NbTY, 5, 9, cc);
    }
  }
  data->finalize();
  view->setChanged(true);
}

void FieldManager::set_background_mesh(int iView){
	int id=new_id();
	Field *f=new_field(id,"PostView");
	f->options["IView"]->numerical_value(iView);
	(*this)[id]=f;
	background_field=id;
}

