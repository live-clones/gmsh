package org.geuz.onelab;

import android.os.Handler;

public class Gmsh {
	/** From C / C++ code **/
	static {
		System.loadLibrary("f2cblas");
		System.loadLibrary("f2clapack");
		System.loadLibrary("petsc");
		System.loadLibrary("Gmsh");
		System.loadLibrary("GetDP");
		System.loadLibrary("Onelab");
        
    }
	private native long init(String name); // Init Gmsh
	private native void loadFile(long ptr, String name); // load a file(OpenProjet)
	private native void initView(long ptr, int w, int h); // Called each time the GLView change
	private native void drawView(long ptr); // Called each time the GLView request a render
	private native void eventHandler(long ptr, int event, float x, float y);
	private native void setShow(long ptr, String what, boolean show); // select what to show / hide
	private native boolean isShow(long ptr, String what);
	private native long getOnelabInstance(); // return the singleton of the onelab server
	public native String[] getParams(); // return the parameters for onelab
	public native int setParam(String type, String name, String value); // change a parameters
	public native String[] getPView(); // get a list of PViews
	public native void setPView(int position, int intervalsType,int visible,int nbIso); // Change options for a PView
	public native int onelabCB(String action); // Call onelab
	
	/** Java CLASS **/
	private long ptr;
	private long onelab;
	private Handler handler;

	public Gmsh(String name, Handler handler) {
		ptr = this.init(name);
		onelab = this.getOnelabInstance();
		this.handler = handler;
	}

	public void viewInit(int w, int h) {
		this.initView(ptr, w, h);
	}

	public void viewDraw() {
		this.drawView(ptr);
	}

	public void load(String filename){
		this.loadFile(ptr, filename);
	}

	public void startEvent(float x, float y)
	{
		this.eventHandler(ptr, 0, x, y);
	}
	public void translate(float x, float y)
	{
		this.eventHandler(ptr, 1, x, y);
	}
	public void scale(float s)
	{
		this.eventHandler(ptr, 2, s, 0);
	}
	public void rotate(float x, float y)
	{
		this.eventHandler(ptr, 3, x, y);
	}
	public void viewX() { this.eventHandler(ptr, 5, 0, 0);}
	public void viewY() { this.eventHandler(ptr, 6, 0, 0);}
	public void viewZ() { this.eventHandler(ptr, 7, 0, 0);}
	public void endEvent(float x, float y)
	{
		this.eventHandler(ptr, 4, x, y);
	}
	public void resetPosition()
	{
		this.eventHandler(ptr, 10, 0, 0);
	}
	public void showGeom(boolean show)
	{
		this.setShow(ptr, "geom", show);
	}
	public void showMesh(boolean show)
	{
		this.setShow(ptr, "mesh", show);
	}
	public boolean showMesh() 
	{
		return this.isShow(ptr, "mesh");
	}
	public boolean showGeom() 
	{
		return this.isShow(ptr, "geom");
	}
	public long getOnelab() {
		return this.onelab;
	}
	public void ShowPopup(String message) {
		handler.obtainMessage(0, message).sendToTarget();
	}
	public void RequestRender() {
		handler.obtainMessage(1).sendToTarget();
	}
	public void SetLoading(String message) {
		handler.obtainMessage(2, message).sendToTarget();
	}
	public void SetLoading(int percent) {
		handler.obtainMessage(3, percent, 100).sendToTarget();
	}
}
