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
#include <Gmsh/PViewData.h>
#include <Gmsh/Context.h>
#include <Gmsh/StringUtils.h>

#include <GetDP/GetDP.h>
#endif

#if defined(BUILD_ANDROID)
#include <GLES/gl.h>
#include <GLES/glext.h>

#include <gmsh/Gmsh.h>
#include <gmsh/GModel.h>
#include <gmsh/MElement.h>
#include <gmsh/VertexArray.h>
#include <gmsh/onelab.h>
#include <gmsh/onelabUtils.h>
#include <gmsh/PView.h>
#include <gmsh/PViewOptions.h>
#include <gmsh/PViewData.h>
#include <gmsh/Context.h>
#include <gmsh/StringUtils.h>

#include <getdp/GetDP.h>

#include "androidGModel.h"
#endif

#include "drawContext.h"
#include "drawString.h"
#include "Trackball.h"

static bool locked = false;
static bool onelabStop = false;

drawContext::drawContext()
{
	GmshInitialize();
	GmshSetOption("General", "Terminal", 1.0);
	onelabUtils::setFirstComputationFlag(false);
	for(int i = 0; i < 3; i++){
		_translate[i] = 0.;
		_scale[i] = 1.;
	}
	setQuaternion(0., 0., 0., 1.);
    
	_fillMesh = false;
	_gradiant = true;
}

static void checkGlError(const char* op) {
	for (GLint error = glGetError(); error; error = glGetError())
		Msg::Error("%s: glError (0x%x)",op,error);
}

void drawContext::load(std::string filename)
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
    
	// to allow the first run
	onelab::server::instance()->setChanged(true, "Gmsh");
	onelab::server::instance()->setChanged(true, "GetDP");
}

void drawContext::eventHandler(int event, float x, float y)
{
	this->_current.set(this->_scale, this->_translate, this->_right, this->_left, this->_bottom, this->_top, this->_width, this->_height, x, y);
    double xx[3] = {1.,0.,0.};
    double yy[3] = {0.,1.,0.};
    double q[4];
	switch(event)
	{
		case 0: // finger(s) press the screen
			// in this case x and y represent the start point
			this->_start.set(this->_scale, this->_translate, this->_right, this->_left, this->_bottom, this->_top, this->_width, this->_height, x, y);
			this->_previous.set(this->_scale, this->_translate, this->_right, this->_left, this->_bottom, this->_top, this->_width, this->_height, x, y);
			break;
		case 1: // finger move (translate)
			// in this case x and y represent the current point
			_translate[0] += (this->_current.wnr[0] - this->_previous.wnr[0]);
			_translate[1] += (this->_current.wnr[1] - this->_previous.wnr[1]);
			_translate[2] = 0.;
			break;
		case 2: // fingers move (scale)
			// in this case we don't care about previous and current position, x represent the scale
			this->_scale[0] = this->_scale[1] = this->_scale[2] = x;
			this->_start.recenter(this->_scale, this->_translate);
			break;
		case 3: // fingers move (rotate)
			this->addQuaternion((2. * this->_previous.win[0] - this->_width) / this->_width,
                                (this->_height - 2. * this->_previous.win[1]) / this->_height,
                                (2. * this->_current.win[0] - this->_width) / this->_width,
                                (this->_height - 2. * this->_current.win[1]) / this->_height);
			break;
		case 4: // release the finger(s)
			// Do nothink ?
			break;
		case 5: // X view
			axis_to_quat(xx, M_PI/2, q);
			setQuaternion(q[0], q[1], q[2], q[3]);
			break;
		case 6: // Y view
			axis_to_quat(yy, M_PI/2, q);
			setQuaternion(q[0], q[1], q[2], q[3]);
			break;
		case 7: // Z view
			setQuaternion(0., 0., 0., 1.);
			break;
		default: // all other reset the position
			setQuaternion(0., 0., 0., 1.);
			for(int i = 0; i < 3; i++){
				_translate[i] = 0.;
				_scale[i] = 1.;
			}
			break;
	}
	this->_previous.set(this->_scale, this->_translate, this->_right, this->_left, this->_bottom, this->_top, this->_width, this->_height, x, y);
}

void drawContext::setQuaternion(double q0, double q1, double q2, double q3)
{
	this->_quaternion[0] = q0;
	this->_quaternion[1] = q1;
	this->_quaternion[2] = q2;
	this->_quaternion[3] = q3;
}

void drawContext::addQuaternion(double p1x, double p1y, double p2x, double p2y)
{
  double quat[4];
  trackball(quat, p1x, p1y, p2x, p2y);
  add_quats(quat, this->_quaternion, this->_quaternion);
}

void drawContext::buildRotationMatrix()
{
	build_rotmatrix(_rotate, _quaternion);
	for(int i=0; i<16;i++)
		_rotatef[i] = (float)_rotate[i];
}

void drawContext::OrthofFromGModel()
{
	SBoundingBox3d bb = GModel::current()->bounds();
	double ratio = (double)(this->_width ? this->_width : 1.) / (double)(this->_height ? this->_height : 1.);
	double bbRation = (bb.max().x() - bb.min().x()) / (bb.max().y() - bb.min().y());
	double xmin = -ratio, xmax = ratio, ymin = -1., ymax = 1.;
	if(bbRation < 1) {
		xmin = bb.min().y() * ratio + bb.max().x() + bb.min().x();
		xmax = bb.max().y() * ratio + bb.max().x() + bb.min().x();
		ymin = bb.min().y() + bb.max().y() + bb.min().y();
		ymax = bb.max().y() + bb.max().y() + bb.min().y();
	}
	else {
		xmin = bb.min().x() + bb.max().x() + bb.min().x();
		xmax = bb.max().x() + bb.max().x() + bb.min().x();
		ymin = bb.min().x() / ratio + bb.max().y() + bb.min().y();
		ymax = bb.max().x() / ratio + bb.max().y() + bb.min().y();
	}
	xmax += (xmax - xmin) / 5.;
	xmin -= (xmax - xmin) / 5.;
	ymax += (ymax - ymin) / 5.;
	ymin -= (ymax - ymin) / 5.;
	
	// clipping
	double zmax = std::max(fabs(bb.min().z()), fabs(bb.max().z()));
	double clip = zmax  * 5.;
	clip = 1.;

	GLint matrixMode;
	glGetIntegerv(GL_MATRIX_MODE, &matrixMode);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	this->_left = (xmin != 0 || xmax != 0)? xmin : -ratio;
	this->_right = (xmin != 0 || xmax != 0)? xmax : ratio;
	this->_top = (xmin != 0 || xmax != 0)? ymax : 1.0;
	this->_bottom = (xmin != 0 || xmax != 0)? ymin : -1.0;
	glOrthof(this->_left, this->_right, this->_bottom, this->_top, -clip, clip);
    
	glMatrixMode(matrixMode);
}

void drawContext::initView(int w, int h)
{
	this->_height = h;
	this->_width = w;
	glViewport(0, 0, w, h);

	this->OrthofFromGModel();
    
	glClearColor(.83,.85,.98,1.);
	glDepthMask(GL_TRUE);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glDepthFunc(GL_LESS);
}

void drawArray(VertexArray *va, GLint type, bool useColorArray, bool useNormalArray)
{
	if(!va) return;
	glEnable(GL_BLEND);
	glEnable(GL_RESCALE_NORMAL);
	glShadeModel(GL_SMOOTH);
	glVertexPointer(3, GL_FLOAT, 0, va->getVertexArray());
	glEnableClientState(GL_VERTEX_ARRAY);
	if(useNormalArray){
		glNormalPointer(GL_BYTE, 0, va->getNormalArray());
		glEnableClientState(GL_NORMAL_ARRAY);
	}
	if(useColorArray){
		glColorPointer(4, GL_UNSIGNED_BYTE, 0, va->getColorArray());
		glEnableClientState(GL_COLOR_ARRAY);
	}
	glDrawArrays(type, 0, va->getNumVertices());
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

void drawContext::drawVectorArray(PViewOptions *opt, VertexArray *va)
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
				double d = (this->_right - this->_left) / this->_width / _scale[0];
				dx *= d; dy *= d; dz *= d;
				double x = s[0], y = s[1], z = s[2];
				drawVector(x,y,z,dx,dy,dz);
			}
		}
	}
}

void drawContext::drawPView(PView *p)
{
	PViewOptions *opt = p->getOptions();
	if(!opt->visible) return;
    
	glPointSize((GLfloat)opt->pointSize);
	glLineWidth((GLfloat)opt->lineWidth);
    
	drawArray(p->va_points, GL_POINTS, true);
	drawArray(p->va_lines, GL_LINES, true);
	drawArray(p->va_triangles, GL_TRIANGLES, true, true);

	glLineWidth(1);
	glPointSize(1);
    
	drawVectorArray(p->getOptions(), p->va_vectors);
}

void drawContext::drawScale()
{
	glPushMatrix();
	glLoadIdentity();
	// Draw the scale bar
	int nPview = 0;
	for(int i=0; i<PView::list.size();i++){
		PView *p = PView::list[i];
		PViewOptions *opt = p->getOptions();
		if(!opt->visible) continue;

		double width = (this->_right -this->_left) / 2.;
		double height = (this->_top - this->_bottom) / 10.;
		double dh = height / 5;
		double box = width / (opt->nbIso ? opt->nbIso : 1);
		double xmin = this->_left + (this->_right - this->_left -width)/2.;
		double ymin = this->_bottom + 0.8 * height + height * nPview;
    
		std::vector<GLfloat> vertex(opt->nbIso*3*4);
		std::vector<GLubyte> color(opt->nbIso*4*4);
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
				vertex[i*3*4+4] = ymin + dh;
				vertex[i*3*4+5] = 0.;
				vertex[i*3*4+6] = xmin + (i + 1) * box;
				vertex[i*3*4+7] = ymin;
				vertex[i*3*4+8] = 0.;
				vertex[i*3*4+9] = xmin + (i + 1) * box;
				vertex[i*3*4+10] = ymin + dh;
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
				vertex[i*3*4+4] = ymin + dh;
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
				vertex[i*3*4+10] = ymin + dh;
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
				vertex[i*3*4+4] = ymin + dh;
				vertex[i*3*4+5] = 0.;
				vertex[i*3*4+6] = xmin + (i + 1) * box;
				vertex[i*3*4+7] = ymin;
				vertex[i*3*4+8] = 0.;
				vertex[i*3*4+9] = xmin + (i + 1) * box;
				vertex[i*3*4+10] = ymin + dh;
				vertex[i*3*4+11] = 0.;
			}
		}
	
		glVertexPointer(3, GL_FLOAT, 0, &vertex[0]);
		glEnableClientState(GL_VERTEX_ARRAY);
		glColorPointer(4, GL_UNSIGNED_BYTE, 0, &color[0]);
		glEnableClientState(GL_COLOR_ARRAY);
		if(opt->intervalsType == PViewOptions::Discrete || opt->intervalsType == PViewOptions::Numeric || opt->intervalsType == PViewOptions::Continuous)
			glDrawArrays(GL_TRIANGLE_STRIP, 0, opt->nbIso*4);
		else
			glDrawArrays(GL_LINES, 0, opt->nbIso*4);
		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);

		drawString lbl(p->getData()->getName().c_str(), 20);
		lbl.draw(xmin+width/2, ymin+ 2.5*dh, 0., _width/(_right-_left), _height/(_top-_bottom));

		drawString val(p->getData()->getName().c_str(), 14);
		for(int i = 0; i < 3; i++) {
			double v = opt->getScaleValue(i, 3, opt->tmpMin, opt->tmpMax);
			char label[1024];
			sprintf(label, opt->format.c_str(), v);
			val.setText(label);
			val.draw(xmin+i*width/2, ymin+ 1.5*dh, 0., _width/(_right-_left), _height/(_top-_bottom));
		}
		nPview++;
	}
	glPopMatrix();
}

void drawContext::drawPost()
{
	if(PView::list.empty()) return ;
    
	for(unsigned int i = 0; i < PView::list.size(); i++){
		PView::list[i]->fillVertexArrays();
		drawPView(PView::list[i]);
	}
}

void drawContext::drawAxes(float x0, float y0, float z0, float h)
{
	glLineWidth(1.);
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(x0, y0, z0);
	glMultMatrixf(_rotatef);
	glTranslatef(-x0, -y0, -z0);
    
  const GLfloat axes[] = {
		(GLfloat)x0, (GLfloat)y0, (GLfloat)z0,
		(GLfloat)(x0+h), (GLfloat)y0, (GLfloat)z0,
		(GLfloat)x0, (GLfloat)y0, (GLfloat)z0,
		(GLfloat)x0, (GLfloat)(y0+h), (GLfloat)z0,
		(GLfloat)x0, (GLfloat)y0, (GLfloat)z0,
		(GLfloat)x0, (GLfloat)y0, (GLfloat)(z0+h),
	};
  GLfloat colors[] = {
		0., 0, 0, 1.,
		0., 0, 0, 1.,
		0, 0, 0., 1.,
		0, 0, 0., 1.,
		0, 0., 0, 1.,
		0, 0., 0, 1.,
	};
	glVertexPointer(3, GL_FLOAT, 0, axes);
	glEnableClientState(GL_VERTEX_ARRAY);
	glColorPointer(4, GL_FLOAT, 0, colors);
	glEnableClientState(GL_COLOR_ARRAY);
	glDrawArrays(GL_LINES, 0, 6);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
	double dx = h/10;
	drawString x ("X", 14,colors);
	x.draw(x0+h+dx, y0, z0, _width/(_right-_left), _height/(_top-_bottom), false);
	drawString y("Y", 14,colors+8);
	y.draw(x0+dx, y0+h, z0, _width/(_right-_left), _height/(_top-_bottom), false);
	drawString z("Z", 14,colors+16);
	z.draw(x0+dx, y0, z0+h, _width/(_right-_left), _height/(_top-_bottom), false);
	glPopMatrix();
	glLineWidth(1);
}

void drawContext::drawView()
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
			(GLfloat)this->_top,	(GLfloat)this->_left, -5.,
			(GLfloat)this->_top,	(GLfloat)this->_right, -5.,
			(GLfloat)this->_bottom,	(GLfloat)this->_left, -5.,
			(GLfloat)this->_bottom,	(GLfloat)this->_right, -5.,
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
		glDisableClientState(GL_VERTEX_ARRAY);
		glPopMatrix();
	}
	checkGlError("Draw background");
	//
	glLoadIdentity();
	glScalef(_scale[0], _scale[1], _scale[2]);
	glTranslatef(_translate[0], _translate[1], _translate[2]);
	this->buildRotationMatrix();
	glMultMatrixf(_rotatef);
	checkGlError("Initialize position");

	//
  glEnable(GL_DEPTH_TEST);
	this->drawMesh();
	checkGlError("Draw mesh");
	this->drawGeom();
	checkGlError("Draw geometry");
	this->drawPost();
	checkGlError("Draw post-pro");
  glDisable(GL_DEPTH_TEST);
	this->drawScale();
	checkGlError("Draw scales");
	this->drawAxes(this->_right - (this->_top - this->_bottom)/15.0,
                   this->_bottom + (this->_top - this->_bottom)/15.0,
                    0, (this->_top - this->_bottom)/25.);
	checkGlError("Draw axes");
}

std::vector<std::string> commandToVector(const std::string cmd)
{
	std::vector<std::string> ret;
	int pos=0, last=0;
	while((pos = cmd.find("-", last+1)) != std::string::npos)
	{
		ret.push_back(cmd.substr(last,pos-1-last));
		last = pos;
	}
	ret.push_back(cmd.substr(last,cmd.size()-1));
	return ret;
}

int onelab_cb(std::string action)
{
	Msg::Debug("Ask onlab to %s", action.c_str());
	if(action == "stop"){
		onelab::string o("GetDP/Action", "stop");
		o.setVisible(false);
		o.setNeverChanged(true);
		onelab::server::instance()->set(o);
		onelabStop = true;
		return 0;
	}
	if(locked) return -1;
	locked = true;
	int redraw = 0;
	if(action == "reset"){
        onelab::server::instance()->clear();
        onelabUtils::runGmshClient(action, true);
		action = "check";
	}
    
	Msg::ResetErrorCounter();
    
	if(action == "compute"){
		onelabUtils::initializeLoop("1");
		onelabUtils::initializeLoop("2");
		onelabUtils::initializeLoop("3");
	}
    
	do{
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
        
		if(action == "compute" && (onelab::server::instance()->getChanged("Gmsh") || onelab::server::instance()->getChanged("GetDP"))){
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
		if(action == "check" && (onelab::server::instance()->getChanged("Gmsh") || onelab::server::instance()->getChanged("GetDP"))){
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
	} while(action == "compute" && !onelabStop && (onelabUtils::incrementLoop("3") || onelabUtils::incrementLoop("2") || onelabUtils::incrementLoop("1")));
    
	locked = false;

	return redraw;
}

int number_of_animation() {
	int ret = 0;
	for(unsigned int i = 0; i < PView::list.size(); i++){
		PView * p = PView::list[i];
		if(p->getOptions()->visible){
			int numSteps = (int)p->getData()->getNumTimeSteps();
			if(numSteps > ret) ret = numSteps;
		}
	}
	return ret;
}

void set_animation(int step) {
	for(unsigned int i = 0; i < PView::list.size(); i++){
		PView * p = PView::list[i];
		if(p->getOptions()->visible){
			p->getOptions()->timeStep = step;
			p->setChanged(true);
		}
	}	
}

int animation_next() {
	int ret = 0;
	for(unsigned int i = 0; i < PView::list.size(); i++){
		PView * p = PView::list[i];
		if(p->getOptions()->visible){
			int step = (int)p->getOptions()->timeStep + 1;
			int numSteps = (int)p->getData()->getNumTimeSteps();
			if(step < 0) step = numSteps - 1;
			if(step > numSteps - 1) step = 0;
			p->getOptions()->timeStep = step;
			p->setChanged(true);
			ret = step;
		}
	}
	return ret;
}
int animation_prev() {
	int ret = 0;
	for(unsigned int i = 0; i < PView::list.size(); i++){
		PView * p = PView::list[i];
		if(p->getOptions()->visible){
			// skip empty steps
			int step = (int)p->getOptions()->timeStep - 1;
			int numSteps = (int)p->getData()->getNumTimeSteps();
			if(step < 0) step = numSteps - 1;
			if(step > numSteps - 1) step = 0;
			p->getOptions()->timeStep = step;
			p->setChanged(true);
			ret = step;
		}
	}
	return ret;
}

// vim:set ts=2:
