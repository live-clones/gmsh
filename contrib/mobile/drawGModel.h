#ifndef _DRAW_GMODEL_H_
#define _DRAW_GMODEL_H_

#include <string>

int onelab_cb(const std::string);

class drawGModel{
 private:
	float _translation[3];
	float _scale[3];
	int width, height;
	double left, right, top, bottom;
	float ratio;
	float _rotate[3];
	bool _gradiant, // show the background gradiant
		_showGeom, // show the Geometry
		_showMesh, // show the Mesh
		_fillMesh; // fill the Mesh

	void OrthofFromGModel(void);
	void drawPView(PView *p);
	void drawVectorArray(PViewOptions *opt, VertexArray *va);

 public:
	drawGModel();
	drawGModel(std::string name);
	~drawGModel(){}
	void load(std::string filename);
	void setTranslation(float tx, float ty, float tz=0);
	void setScale(float sx, float sy=0, float sz=0);
	void setRotation(float rx, float ry, float rz);
	void initView(int w, int h);
	void drawView();
	void drawAxes(double x0=0., double y0=0., double z0=0., double h=0.5);
	void drawGeom();
	void drawMesh();
	void drawPost();
	void drawScale();

	void useGradiant(bool gradiant=true) {_gradiant = gradiant;}
	void showGeom(bool show=true) {_showGeom = show;}
	void showMesh(bool show=true) {_showMesh = show;}
	void fillMesh(bool show=true) {_fillMesh = show;}
};
 
#endif
