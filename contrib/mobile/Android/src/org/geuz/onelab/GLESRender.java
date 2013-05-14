package org.geuz.onelab;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.opengl.GLSurfaceView.Renderer;
import android.os.Handler;

public class GLESRender implements Renderer{

	Gmsh mGModel;
	Handler loadingHand;

	public GLESRender(Gmsh model) {
		this.mGModel = model;
	}
	
	public void load(String filename){
		mGModel.load(filename);
	}
	
	public void translate(float tx, float ty, float tz){
		mGModel.translation(tx, ty, tz);
	}
	public void scale(float sx, float sy, float sz){
		mGModel.scale(sx, sy, sz);
	}
	public void rotate(float rx, float ry, float rz){
		mGModel.rotate(rx, ry, rz);
	}
	
	// OpenGL ES methods
	public void onDrawFrame(GL10 gl) {
		mGModel.viewDraw();
	}

	public void onSurfaceChanged(GL10 gl, int width, int height) {
		mGModel.viewInit(width, height);
	}

	public void onSurfaceCreated(GL10 gl, EGLConfig config) {
		
	}

}
