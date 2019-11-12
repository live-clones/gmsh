package org.geuz.onelab;

import org.geuz.onelab.Gmsh;

import java.nio.IntBuffer;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.graphics.Bitmap;
import android.opengl.GLSurfaceView.Renderer;

public class GLESRender implements Renderer {
  private Gmsh mGModel;
  private int _width, _height;
  public GLESRender(Gmsh model) { this.mGModel = model; }
  public void load(String filename) { mGModel.load(filename); }
  public void startInteraction(float x, float y) { mGModel.startEvent(x, y); }
  public void endInteraction(float x, float y) { mGModel.endEvent(x, y); }
  public void rotateModel(float x, float y) { mGModel.rotate(x, y); }
  public void scaleModel(float s) { mGModel.scale(s); }
  public void translateModel(float x, float y) { mGModel.translate(x, y); }
  public void resetModelPosition() { mGModel.resetPosition(); }
  public void viewX() { mGModel.viewX(); }
  public void viewY() { mGModel.viewY(); }
  public void viewZ() { mGModel.viewZ(); }

  // OpenGL ES methods
  public void onDrawFrame(GL10 gl) { mGModel.viewDraw(); }
  public void onSurfaceChanged(GL10 gl, int width, int height)
  {
    mGModel.viewInit(width, height);
    _width = width;
    _height = height;
  }
  public void onSurfaceCreated(GL10 gl, EGLConfig config) {}
}
