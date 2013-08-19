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
	
	public void startInteraction(float x, float y) {
		mGModel.startEvent(x, y);
	}
	public void endInteraction(float x, float y) {
		mGModel.endEvent(x, y);
	}
	public void rotateModel(float x, float y) {
		mGModel.rotate(x, y);
	}
	public void scaleModel(float s) {
		mGModel.scale(s);
	}
	public void translateModel(float x, float y) {
		mGModel.translate(x, y);
	}
	public void resetModelPosition() {
		mGModel.resetPosition();
	}
	public void viewX() { mGModel.viewX();}
	public void viewY() { mGModel.viewY();}
	public void viewZ() { mGModel.viewZ();}
	
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
