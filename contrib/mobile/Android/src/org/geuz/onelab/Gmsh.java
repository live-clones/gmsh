package org.geuz.onelab;

import android.os.Handler;
import android.os.Parcel;
import android.os.Parcelable;

public class Gmsh implements Parcelable {
    /** From C / C++ code **/
    static {
        System.loadLibrary("f2cblas");
        System.loadLibrary("f2clapack");
        System.loadLibrary("petsc");
        System.loadLibrary("Gmsh");
        System.loadLibrary("GetDP");
        System.loadLibrary("Onelab");
    }
    private native long init(float fontFactor); // Init Gmsh
    private native void loadFile(long ptr, String name); // load a file(OpenProjet)
    private native void initView(long ptr, int w, int h); // Called each time the GLView change
    private native void drawView(long ptr); // Called each time the GLView request a render
    private native void eventHandler(long ptr, int event, float x, float y);
    public native String[] getParams(); // return the parameters for onelab
    public native int setParam(String type, String name, String value); // change a parameters
    public native int setStringOption(String category, String name, String value);
    public native int setDoubleOption(String category, String name, double value);
    public native int setIntegerOption(String category, String name, int value);
    public native String getStringOption(String category, String name);
    public native double getDoubleOption(String category, String name);
    public native int getIntegerOption(String category, String name);
    public native String[] getPView(); // get a list of PViews
    public native void setPView(int position, int intervalsType,int visible,int nbIso, float raisez); // Change options for a PView
    public native int onelabCB(String action); // Call onelab

    public boolean haveAnimation() {return numberOfAnimation() > 1;}
    public native int numberOfAnimation();
    public native int animationNext();
    public native int animationPrev();
    public native void setAnimation(int animation);

    public static native String getAboutGmsh();
    public static native String getAboutGetDP();

    /** Java CLASS **/
    private long ptr;
    private Handler handler;
    public Gmsh(Handler handler, float fontFactor)
    {
        ptr = this.init(fontFactor);
        this.handler = handler;
    }
    public void viewInit(int w, int h)
    {
        this.initView(ptr, w, h);
    }
    public void viewDraw()
    {
        this.drawView(ptr);
    }
    public void load(String filename)
    {
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
    public void ShowPopup(String message) {
        if(handler != null)
            handler.obtainMessage(0, message).sendToTarget();
    }
    public void RequestRender() {
        if(handler != null)
            handler.obtainMessage(1).sendToTarget();
    }
    public void SetLoading(String message)
    {
        if(handler != null)
            handler.obtainMessage(2, message).sendToTarget();
    }
    public void SetLoading(int percent)
    {
        if(handler != null)
            handler.obtainMessage(3, percent, 100).sendToTarget();
    }
    // Parcelable methods/constructors
    private Gmsh(Parcel in)
    {
        this.ptr = in.readLong();
    }
    public int describeContents() {return 0;}
    public void writeToParcel(Parcel out, int flags)
    {
        out.writeLong(this.ptr);
    }
    public static Parcelable.Creator<Gmsh> CREATOR = new Parcelable.Creator<Gmsh>()
    {
        public Gmsh createFromParcel(Parcel source)
        {
            return new Gmsh(source);
        }
        public Gmsh[] newArray(int size)
        {
            return new Gmsh[size];
        }
    };
}
