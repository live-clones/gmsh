package org.geuz.onelab;

import java.nio.IntBuffer;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.graphics.Bitmap;
import android.opengl.GLSurfaceView.Renderer;

public class GLESRender implements Renderer{

    private Gmsh mGModel;
    private int _width, _height;
    private Bitmap _screenshot;
    private boolean _needScreenshot;

    public GLESRender(Gmsh model)
    {
        this.mGModel = model;
        _needScreenshot = false;
    }
    public void load(String filename){ mGModel.load(filename); }
    public void startInteraction(float x, float y) { mGModel.startEvent(x, y); }
    public void endInteraction(float x, float y) { mGModel.endEvent(x, y); }
    public void rotateModel(float x, float y) { mGModel.rotate(x, y); }
    public void scaleModel(float s) { mGModel.scale(s); }
    public void translateModel(float x, float y) { mGModel.translate(x, y); }
    public void resetModelPosition() { mGModel.resetPosition(); }
    public void viewX() { mGModel.viewX();}
    public void viewY() { mGModel.viewY();}
    public void viewZ() { mGModel.viewZ();}

    // OpenGL ES methods
    public void onDrawFrame(GL10 gl)
    {
        mGModel.viewDraw();
        if(_needScreenshot) this.screenshot(gl);
    }
    public void onSurfaceChanged(GL10 gl, int width, int height)
    {
        mGModel.viewInit(width, height);
        _width = width;
        _height = height;
    }
    public void onSurfaceCreated(GL10 gl, EGLConfig config) { }
    public void needScreenshot() {_screenshot = null; _needScreenshot = true;}
    public Bitmap getScreenshot(){return _screenshot;}
    private void screenshot(GL10 gl)
    {
        _needScreenshot = false;
        int bitmapBuffer[] = new int[_width * _height];
        int bitmapSource[] = new int[_width * _height];
        IntBuffer intBuffer = IntBuffer.wrap(bitmapBuffer);
        intBuffer.position(0);

        gl.glReadPixels(0, 0, _width, _height, GL10.GL_RGBA, GL10.GL_UNSIGNED_BYTE, intBuffer);
        int offset1, offset2;
        for (int i = 0; i < _height; i++) {
            offset1 = i * _width;
            offset2 = (_height - i - 1) * _width;
            for (int j = 0; j < _width; j++) {
                int pixel = bitmapBuffer[offset1 + j];
                bitmapSource[offset2 + j] = (pixel & 0xFF00FF00) | (pixel << 16) & 0x00FF0000 | (pixel >> 16) & 0x000000FF;
            }
        }
        _screenshot = Bitmap.createBitmap(bitmapSource, _width, _height, Bitmap.Config.ARGB_8888);
    }
}
