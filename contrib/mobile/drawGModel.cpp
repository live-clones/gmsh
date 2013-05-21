#if !defined(BUILD_ANDROID)
#define BUILD_IOS 1
#endif

#include <map>

#if defined(BUILD_IOS)
#include <OpenGLES/ES1/gl.h>
#include <OpenGLES/ES1/glext.h>

#include <Gmsh/Gmsh.h>
#include <Gmsh/GModel.h>
#include <Gmsh/MElement.h>
#include <Gmsh/VertexArray.h>
#include <Gmsh/onelab.h>
#include <Gmsh/onelabUtils.h>
#include <Gmsh/PView.h>
#include <Gmsh/PViewOptions.h>
#include <Gmsh/Context.h>
#include <Gmsh/StringUtils.h>

#include <GetDP/GetDP.h>
#endif

#if defined(BUILD_ANDROID)
#include <GLES/gl.h>
#include <GLES/glext.h>
#include <android/log.h>

#define	LOG_TAG		"Gmsh"
#define	LOGI(...)	__android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define	LOGE(...)	__android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

#include <gmsh/Gmsh.h>
#include <gmsh/GModel.h>
#include <gmsh/MElement.h>
#include <gmsh/VertexArray.h>
#include <gmsh/onelab.h>
#include <gmsh/onelabUtils.h>
#include <gmsh/PView.h>
#include <gmsh/PViewOptions.h>
#include <gmsh/Context.h>
#include <gmsh/StringUtils.h>

#include <getdp/GetDP.h>

#include "androidGModel.h"
#endif

#include "drawGModel.h"

drawGModel::drawGModel()
{
	new GModel();
	GmshInitialize();
	GmshSetOption("Mesh", "SurfaceFaces", 1.);
	GmshSetOption("General", "Terminal", 1.);
	GmshSetOption("General", "Verbosity", 99.);
	onelabUtils::setFirstComputationFlag(false);
	for(int i = 0; i < 3; i++){
		_translation[i] = 0.;
		_scale[i] = 1.;
		_rotate[i] = 0.;
	}
    
	_fillMesh = false;
	_showMesh = false;
	_showGeom = true;
	_gradiant = true;
}

static void checkGlError(const char* op) {
	for (GLint error = glGetError(); error; error	= glGetError())
		Msg::Error("%s: glError (0x%x)",op,error);
}

static bool locked = false;

void drawGModel::load(std::string filename)
{
	if(locked) return;
	// clear previous GModel, onelab datas and PView
	GModel::list.clear();
	PView::list.clear();
	onelab::server::instance()->clear();
	
	// open the file with Gmsh
	GmshOpenProject(filename);
    
	// run getdp witout parameter
	onelab_cb("check");
    
	// to allow the firs run
	onelab::server::instance()->setChanged(true, "Gmsh");
	onelab::server::instance()->setChanged(true, "GetDP");
}

void drawGModel::setTranslation(float tx, float ty, float tz)
{
	if(tx == 0 && tx == ty && ty == tz)
		_translation[0] = _translation[1] = _translation[2] = 0;
	else
	{
		_translation[0] += tx * (this->right - this->left);
		_translation[1] += ty * (this->right - this->left);
		_translation[2] += tz * (this->right - this->left);
	}
}

void drawGModel::setScale(float sx, float sy, float sz)
{
	_scale[0] = sx;
	_scale[1] = sy ? sy : sx;
	_scale[2] = sz ? sz : sx;
}

void drawGModel::setRotation(float rx, float ry, float rz)
{
	if(rx == 0 && rx == ry && ry == rz)
		_rotate[0] = _rotate[1] = _rotate[2] = 0;
	else
	{
		_rotate[0] += rx;
		_rotate[1] += ry;
		_rotate[2] += rz;
	}
}
void drawGModel::OrthofFromGModel()
{
	SBoundingBox3d bb = GModel::current()->bounds();
	double ratio = (double)(width ? width : 1.) / (double)(height ? height : 1.);
	double modelh = bb.max().y() - bb.min().y(), modelw = bb.max().x() - bb.min().x();
	double modelratio = (modelw ? modelw : 1.) / (modelh ? modelh : 1.);
	double xmin = -ratio, xmax = ratio, ymin = -1., ymax = 1.;
    xmin = bb.min().x();
	xmax = bb.max().x();
	ymin = bb.min().x() / ratio;
	ymax = bb.max().x() / ratio;
	xmax += (xmax - xmin) / 5.;
	xmin -= (xmax - xmin) / 5.;
	ymax += (ymax - ymin) / 5.;
	ymin -= (ymax - ymin) / 5.;
	
	// clipping
	double zmax = std::max(fabs(bb.min().z()), fabs(bb.max().z()));
	double clip = zmax  * 5.;
	clip = 1.;
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrthof(xmin, xmax, ymin, ymax, -clip, clip);
	this->left = xmin; this->right = xmax; this->top = ymax; this->bottom = ymin;
    
	glMatrixMode(GL_MODELVIEW);
}
void drawGModel::initView(int w, int h)
{
	this->height = h;
	this->width = w;
	glViewport(0, 0, w, h);
    
	this->OrthofFromGModel();
    
	glClearColor(.83,.85,.98,1.);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
}

void drawArray(VertexArray *va, GLint type, bool colorArray=false)
{
	if(!va) return;
	glEnable(GL_BLEND);
	glEnable(GL_RESCALE_NORMAL);
	glShadeModel(GL_SMOOTH);
	glVertexPointer(3, GL_FLOAT, 0, va->getVertexArray());
	glEnableClientState(GL_VERTEX_ARRAY);
	glNormalPointer(GL_BYTE, 0, va->getNormalArray());
	glEnableClientState(GL_NORMAL_ARRAY);
	if(colorArray)
	{
		glColorPointer(4, GL_UNSIGNED_BYTE, 0, va->getColorArray());
		glEnableClientState(GL_COLOR_ARRAY);
	}
	glDrawArrays(type, 0, va->getNumVertices());
	glDisable(GL_POLYGON_OFFSET_FILL);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
	glDisable(GL_RESCALE_NORMAL);
	glDisable(GL_BLEND);
}

void drawVector(double x, double y, double z, double dx, double dy, double dz)
{
	double l = sqrt(dx * dx + dy * dy + dz * dz), lt;
	double n[3], t[3], u[3];
    
	if(l == 0.0) return;
    
	GLfloat line[] = {
		(GLfloat)x, (GLfloat)y, (GLfloat)z,
		(GLfloat)(x+dx), (GLfloat)(y+dy), (GLfloat)(z+dz),
    };
    glVertexPointer(3, GL_FLOAT, 0, line);
    glEnableClientState(GL_VERTEX_ARRAY);
    glDrawArrays(GL_LINES, 0, 2);
	glDisableClientState(GL_VERTEX_ARRAY);
    
	n[0] = dx / l;
	n[1] = dy / l;
	n[2] = dz / l;
    
	if((fabs(n[0]) >= fabs(n[1]) && fabs(n[0]) >= fabs(n[2])) ||
       (fabs(n[1]) >= fabs(n[0]) && fabs(n[1]) >= fabs(n[2]))) {
		t[0] = n[1];
		t[1] = -n[0];
		t[2] = 0.;
	}
	else {
		t[0] = 0.;
		t[1] = n[2];
		t[2] = -n[1];
	}
    
	lt = sqrt(t[0] * t[0] + t[1] * t[1] + t[2] * t[2]);
	t[0] /= lt;
	t[1] /= lt;
	t[2] /= lt;
    
	u[0] = n[1] * t[2] - n[2] * t[1];
	u[1] = n[2] * t[0] - n[0] * t[2];
	u[2] = n[0] * t[1] - n[1] * t[0];
    
	lt = sqrt(u[0] * u[0] + u[1] * u[1] + u[2] * u[2]);
	u[0] /= lt;
	u[1] /= lt;
	u[2] /= lt;
    
	double f1 = 0.75; // Stem lenght
	double b = 0.1 * l;
	
	GLfloat arrow[] = {
		(GLfloat)(x + dx), (GLfloat)(y + dy), (GLfloat)(z + dz),
		(GLfloat)(x + f1 * dx + b * (t[0])), (GLfloat)(y + f1 * dy + b * (t[1])), (GLfloat)(z + f1 * dz + b * (t[2])),
		(GLfloat)(x + f1 * dx + b * (-t[0])), (GLfloat)(y + f1 * dy + b * (-t[1])), (GLfloat)(z + f1 * dz + b * (-t[2])),
        
		(GLfloat)(x + dx), (GLfloat)(y + dy), (GLfloat)(z + dz),
		(GLfloat)(x + f1 * dx + b * (-u[0])), (GLfloat)(y + f1 * dy + b * (-u[1])), (GLfloat)(z + f1 * dz + b * (-u[2])),
		(GLfloat)(x + f1 * dx + b * (u[0])), (GLfloat)(y + f1 * dy + b * (u[1])), (GLfloat)(z + f1 * dz + b * (u[2])),
	};
    glVertexPointer(3, GL_FLOAT, 0, arrow);
    glEnableClientState(GL_VERTEX_ARRAY);
	glEnable(GL_LINE_SMOOTH);
    glDrawArrays(GL_TRIANGLES, 0, 6);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisable(GL_LINE_SMOOTH);
    
}

void drawGModel::drawVectorArray(PViewOptions *opt, VertexArray *va)
{
	if(!va || va->getNumVerticesPerElement() != 2) return;
    
	for(int i = 0; i < va->getNumVertices(); i += 2){
		float *s = va->getVertexArray(3 * i);
		float *v = va->getVertexArray(3 * (i + 1));
		double l = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
		double lmax = opt->tmpMax;
		if((l && opt->vectorType) && lmax)
		{
			double scale = (opt->arrowSizeMax - opt->arrowSizeMin) / lmax;
			if(opt->arrowSizeMin && l) scale += opt->arrowSizeMin / l;
			double dx = scale * v[0];
			double dy = scale * v[1];
			double dz = scale * v[2];
			GLubyte *color = (GLubyte *)va->getColorArray(4 * i);
			glColor4ub(*(color), *(color+1), *(color+2), *(color+3));
			if(fabs(dx) > 1. || fabs(dy) > 1. || fabs(dz) > 1.)
			{
				double d = (this->right - this->left) / this->width / _scale[0];
				dx *= d; dy *= d; dz *= d;
				double x = s[0], y = s[1], z = s[2];
				drawVector(x,y,z,dx,dy,dz);
			}
		}
	}
}

void drawGModel::drawPView(PView *p)
{
	PViewOptions *opt = p->getOptions();
	PViewData *data = p->getData(true);
	if(!opt->visible) return;
    
	glPointSize((GLfloat)opt->pointSize);
	glLineWidth((GLfloat)opt->lineWidth);
    
	drawArray(p->va_points, GL_POINTS,true);
	drawArray(p->va_lines, GL_LINES,true);
	drawArray(p->va_triangles, GL_TRIANGLES,true);

	glLineWidth(1);
	glPointSize(1);
    
	drawVectorArray(p->getOptions(), p->va_vectors);
}

void drawGModel::drawScale()
{
	glPushMatrix();
	glLoadIdentity();
	// Draw the scale bar
	if(PView::list.size() < 1) return;
	PView *p = PView::list[PView::list.size()-1];
	PViewOptions *opt = p->getOptions();
    
	double width = 6*(this->right -this->left) / 10.;
	double height = (this->top - this->bottom) / 20.;
	double box = width / (opt->nbIso ? opt->nbIso : 1);
	double xmin = this->left + (this->right - this->left -width)/2.;
	double ymin = this->bottom + height;
    
    GLfloat *vertex = (GLfloat *)malloc(opt->nbIso*3*4*sizeof(GLfloat));
    GLubyte *color = (GLubyte *)malloc(opt->nbIso*4*4*sizeof(GLubyte));
	for(int i = 0; i < opt->nbIso; i++){
		if(opt->intervalsType == PViewOptions::Discrete || opt->intervalsType == PViewOptions::Numeric)
		{
			unsigned int col = opt->getColor(i, opt->nbIso);
			color[i*4*4+0] = color[i*4*4+4] = color[i*4*4+8] = color[i*4*4+12] = (GLubyte)CTX::instance()->unpackRed(col);
			color[i*4*4+1] = color[i*4*4+5] = color[i*4*4+9] = color[i*4*4+13] = (GLubyte)CTX::instance()->unpackGreen(col);
			color[i*4*4+2] = color[i*4*4+6] = color[i*4*4+10] = color[i*4*4+14] = (GLubyte)CTX::instance()->unpackBlue(col);
			color[i*4*4+3] = color[i*4*4+7] = color[i*4*4+11] = color[i*4*4+15] = (GLubyte)CTX::instance()->unpackAlpha(col);
			vertex[i*3*4+0] = xmin + i * box;
			vertex[i*3*4+1] = ymin;
			vertex[i*3*4+2] = 0.;
			vertex[i*3*4+3] = xmin + i * box;
			vertex[i*3*4+4] = ymin + height;
			vertex[i*3*4+5] = 0.;
			vertex[i*3*4+6] = xmin + (i + 1) * box;
			vertex[i*3*4+7] = ymin;
			vertex[i*3*4+8] = 0.;
			vertex[i*3*4+9] = xmin + (i + 1) * box;
			vertex[i*3*4+10] = ymin + height;
			vertex[i*3*4+11] = 0.;
		}
		else if(opt->intervalsType == PViewOptions::Continuous)
		{
			double dv = (opt->tmpMax - opt->tmpMin) / (opt->nbIso ? opt->nbIso : 1);
			double v1 = opt->tmpMin + i * dv;
			unsigned int col1 = opt->getColor(v1, opt->tmpMin, opt->tmpMax, true);
			color[i*4*4+0] = color[i*4*4+4] = (GLubyte)CTX::instance()->unpackRed(col1);
			color[i*4*4+1] = color[i*4*4+5] = (GLubyte)CTX::instance()->unpackGreen(col1);
			color[i*4*4+2] = color[i*4*4+6] = (GLubyte)CTX::instance()->unpackBlue(col1);
			color[i*4*4+3] = color[i*4*4+7] = (GLubyte)CTX::instance()->unpackAlpha(col1);
			vertex[i*3*4+0] = xmin + i * box;
			vertex[i*3*4+1] = ymin;
			vertex[i*3*4+2] = 0.;
			vertex[i*3*4+3] = xmin + i * box;
			vertex[i*3*4+4] = ymin + height;
			vertex[i*3*4+5] = 0.;
			double v2 = opt->tmpMin + (i + 1) * dv;
            unsigned int col2 = opt->getColor(v2, opt->tmpMin, opt->tmpMax, true);
			color[i*4*4+8] = color[i*4*4+12] = (GLubyte)CTX::instance()->unpackRed(col2);
			color[i*4*4+9] = color[i*4*4+13] = (GLubyte)CTX::instance()->unpackGreen(col2);
			color[i*4*4+10] = color[i*4*4+14] = (GLubyte)CTX::instance()->unpackBlue(col2);
			color[i*4*4+11] = color[i*4*4+15] = (GLubyte)CTX::instance()->unpackAlpha(col2);
			vertex[i*3*4+6] = xmin + (i + 1) * box;
			vertex[i*3*4+7] = ymin;
			vertex[i*3*4+8] = 0.;
			vertex[i*3*4+9] = xmin + (i + 1) * box;
			vertex[i*3*4+10] = ymin + height;
			vertex[i*3*4+11] = 0.;
		}
		else
		{
			unsigned int col = opt->getColor(i, opt->nbIso);
			color[i*4*4+0] = color[i*4*4+4] = color[i*4*4+8] = color[i*4*4+12] = (GLubyte)CTX::instance()->unpackRed(col);
			color[i*4*4+1] = color[i*4*4+5] = color[i*4*4+9] = color[i*4*4+13] = (GLubyte)CTX::instance()->unpackGreen(col);
			color[i*4*4+2] = color[i*4*4+6] = color[i*4*4+10] = color[i*4*4+14] = (GLubyte)CTX::instance()->unpackBlue(col);
			color[i*4*4+3] = color[i*4*4+7] = color[i*4*4+11] = color[i*4*4+15] = (GLubyte)CTX::instance()->unpackAlpha(col);
			vertex[i*3*4+0] = xmin + i * box;
			vertex[i*3*4+1] = ymin;
			vertex[i*3*4+2] = 0.;
			vertex[i*3*4+3] = xmin + i * box;
			vertex[i*3*4+4] = ymin + height;
			vertex[i*3*4+5] = 0.;
			vertex[i*3*4+6] = xmin + (i + 1) * box;
			vertex[i*3*4+7] = ymin;
			vertex[i*3*4+8] = 0.;
			vertex[i*3*4+9] = xmin + (i + 1) * box;
			vertex[i*3*4+10] = ymin + height;
			vertex[i*3*4+11] = 0.;
		}
	}
	
	{
        glVertexPointer(3, GL_FLOAT, 0, vertex);
        glEnableClientState(GL_VERTEX_ARRAY);
        glColorPointer(4, GL_UNSIGNED_BYTE, 0, color);
        glEnableClientState(GL_COLOR_ARRAY);
        if(opt->intervalsType == PViewOptions::Discrete || opt->intervalsType == PViewOptions::Numeric || opt->intervalsType == PViewOptions::Continuous)
            glDrawArrays(GL_TRIANGLE_STRIP, 0, opt->nbIso*4);
        else
            glDrawArrays(GL_LINES, 0, opt->nbIso*4);
        glDisableClientState(GL_COLOR_ARRAY);
        glDisableClientState(GL_VERTEX_ARRAY);
	}
	free(vertex);
	free(color);
	glPopMatrix();
}

void drawGModel::drawMesh()
{
	GModel::current()->fillVertexArrays();
	glColor4f(0,0,0,1.);
	for(GModel::fiter it = GModel::current()->firstFace(); it != GModel::current()->lastFace(); it++){
		if(_fillMesh) drawArray((*it)->va_triangles, GL_TRIANGLES);
		else drawArray((*it)->va_lines, GL_LINES);
	}
}

void drawGModel::drawPost()
{
	if(PView::list.empty()) return ;
    
	for(unsigned int i = 0; i < PView::list.size(); i++){
		PView::list[i]->fillVertexArrays();
		drawPView(PView::list[i]);
	}
}

void drawGModel::drawGeom()
{
	glColor4f(0,0,1.,1.);
	glLineWidth(3);
	for(GModel::eiter it = GModel::current()->firstEdge(); it != GModel::current()->lastEdge(); it++){
		GEdge *e = *it;
		int N = e->minimumDrawSegments() + 1;
		Range<double> t_bounds = e->parBounds(0);
		double t_min = t_bounds.low();
		double t_max = t_bounds.high();
        
		// Create a VA for this edge
		GLfloat edge[N*3];
        
		for(unsigned int i=0; i < N; i++) {
			double t = t_min + (double)i / (double)(N-1) * (t_max - t_min);
			GPoint p = e->point(t);
			edge[i*3] = p.x(); edge[i*3+1] = p.y(); edge[i*3+2] = p.z();
		}
		// Then print the VA
		glVertexPointer(3, GL_FLOAT, 0, edge);
		glEnableClientState(GL_VERTEX_ARRAY);
		glDrawArrays(GL_LINE_STRIP, 0, N);
		glDisableClientState(GL_VERTEX_ARRAY);
	}
	glLineWidth(1);
}

void drawGModel::drawAxes(double x0, double y0, double z0, double h)
{
	glLineWidth(5);
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(x0, y0, z0);
	glRotatef(this->_rotate[0], 1, 0, 0);
	glRotatef(this->_rotate[1], 0, 1, 0);
	glRotatef(this->_rotate[2], 0, 0, 1);
	glTranslatef(-x0, -y0, -z0);
    
    const GLfloat axes[] = {
		(GLfloat)x0, (GLfloat)y0, (GLfloat)z0,
		(GLfloat)(x0+h), (GLfloat)y0, (GLfloat)z0,
		(GLfloat)x0, (GLfloat)y0, (GLfloat)z0,
		(GLfloat)x0, (GLfloat)(y0+h), (GLfloat)z0,
		(GLfloat)x0, (GLfloat)y0, (GLfloat)z0,
		(GLfloat)x0, (GLfloat)y0, (GLfloat)(z0+h),
	};
    const GLubyte colors[] = {
        255, 0, 0, 255,
        255, 0, 0, 255,
        0, 0, 255, 255,
        0, 0, 255, 255,
        0, 255, 0, 255,
        0, 255, 0, 255,
    };
	glVertexPointer(3, GL_FLOAT, 0, axes);
	glEnableClientState(GL_VERTEX_ARRAY);
    glColorPointer(4, GL_UNSIGNED_BYTE, 0, colors);
    glEnableClientState(GL_COLOR_ARRAY);
	glDrawArrays(GL_LINES, 0, 6);
	glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
	glPopMatrix();
	glLineWidth(1);
}

void drawGModel::drawView()
{
	this->OrthofFromGModel();
    
	glMatrixMode(GL_MODELVIEW);
	// fill the background
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if(_gradiant)
	{
		glPushMatrix();
		glLoadIdentity();
		const GLfloat squareVertices[] = {
			(GLfloat)this->top,	(GLfloat)this->left, -5.,
			(GLfloat)this->top,	(GLfloat)this->right, -5.,
			(GLfloat)this->bottom,	(GLfloat)this->left, -5.,
			(GLfloat)this->bottom,	(GLfloat)this->right, -5.,
		};
		const GLubyte squareColors[] = {
			255, 255, 255, 255,
			255, 255, 255, 255,
			190, 200, 255, 255,
			190, 200, 255, 255,
		};
		glVertexPointer(3, GL_FLOAT, 0, squareVertices);
		glEnableClientState(GL_VERTEX_ARRAY);
		glColorPointer(4, GL_UNSIGNED_BYTE, 0, squareColors);
		glEnableClientState(GL_COLOR_ARRAY);
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
		glDisableClientState(GL_COLOR_ARRAY);
		glPopMatrix();
	}
	checkGlError("glError -> drawGradiant");
	//
	glLoadIdentity();
	glRotatef(this->_rotate[0], 1, 0, 0);
	glRotatef(this->_rotate[1], 0, 1, 0);
	glRotatef(this->_rotate[2], 0, 0, 1);
	glTranslatef(this->_translation[0]/this->height,this->_translation[1]/this->width,0);
	glScalef(this->_scale[0], this->_scale[1], this->_scale[2]);
	checkGlError("glTranslatef");
    
	this->drawAxes(this->right - (this->top - this->bottom)/9.0, this->bottom + (this->top - this->bottom)/9.0, 0, (this->top - this->bottom)/10.);
	this->drawPost();
	if(_showGeom) this->drawGeom();
	if(_showMesh) this->drawMesh();
	//this->drawScale();
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glDisable(GL_DEPTH_TEST);
}

std::vector<std::string> commandToVector(const std::string cmd)
{
	std::vector<std::string> ret;
	int pos=0, last=0;
	Msg::Info("Cut: %s", cmd.c_str());
	while((pos = cmd.find("-", last+1)) != std::string::npos)
	{
		ret.push_back(cmd.substr(last,pos-1-last));
		Msg::Info("Add: %s (%d,%d)", ret[ret.size()-1].c_str(), last, pos-1);
		last = pos;
	}
	ret.push_back(cmd.substr(last,cmd.size()-1));
	Msg::Info("Add: %s", ret[ret.size()-1].c_str());
	return ret;
}

int onelab_cb(std::string action)
{
	Msg::Debug("Ask onlab to %s", action.c_str());
	if(action == "stop")
	{
		onelab::string o("GetDP/Action", "stop");
		o.setVisible(false);
		o.setNeverChanged(true);
		onelab::server::instance()->set(o);
		return 0;
	}
	if(locked) return -1;
	locked = true;
	int redraw = 0;
	if(action == "reset")
	{
        onelab::server::instance()->clear();
        onelabUtils::runGmshClient(action, true);
		action = "check";
	}
    
	Msg::ResetErrorCounter();
    
	if(action == "compute")
	{
		onelabUtils::initializeLoop("1");
		onelabUtils::initializeLoop("2");
		onelabUtils::initializeLoop("3");
	}
    
	do
	{
		if(onelabUtils::runGmshClient(action, true))
			redraw = 1;
        
		if(redraw == 0 && !onelab::server::instance()->getChanged("GetDP"))continue;
        
		std::vector<onelab::string> ps;
		onelab::server::instance()->get(ps, "GetDP/1ModelName");
		if(ps.empty()){
			std::vector<std::string> split = SplitFileName(GModel::current()->getFileName());
			std::string name(split[0] + split[1]);
			onelab::string o("GetDP/1ModelName", name, "Model name");
			o.setKind("file");
			onelab::server::instance()->set(o);
		}
		onelab::string o("GetDP/Action", action);
		o.setVisible(false);
		o.setNeverChanged(true);
		onelab::server::instance()->set(o);
        
		if(action == "compute")
		{
			std::string filename = GModel::current()->getFileName();
			std::vector<std::string> args;
			args.push_back("getdp");
			std::vector<onelab::string> onelabArgs;
			onelab::server::instance()->get(onelabArgs, "GetDP/1ModelName");
			args.push_back((onelabArgs.empty())? SplitFileName(filename)[0] + SplitFileName(filename)[1] : onelabArgs[0].getValue());
			onelab::server::instance()->get(onelabArgs, "GetDP/9ComputeCommand");
			std::vector<std::string> compute = commandToVector((onelabArgs.empty())? "" : onelabArgs[0].getValue().c_str());
			args.insert( args.end(), compute.begin(), compute.end() );
			args.push_back("-onelab");
			args.push_back("GetDP");
			GetDP(args, onelab::server::instance());
		}
		if(action == "check")
		{
			std::string filename = GModel::current()->getFileName();
			std::vector<std::string> args;
			args.push_back("getdp");
			std::vector<onelab::string> onelabArgs;
			args.push_back(SplitFileName(filename)[0] + SplitFileName(filename)[1]);
			onelab::server::instance()->get(onelabArgs, "GetDP/9CheckCommand");
			args.push_back((onelabArgs.empty())? "" : onelabArgs[0].getValue());
			args.push_back("-onelab");
			args.push_back("GetDP");
			GetDP(args, onelab::server::instance());
		}
	} while(action == "compute" && (onelabUtils::incrementLoop("3") || onelabUtils::incrementLoop("2") || onelabUtils::incrementLoop("1")));
    
	locked = false;
    
	return redraw;
}

// vim:set ts=2:
