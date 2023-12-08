package org.geuz.onelab;

import java.io.File;
import android.net.Uri;
import java.util.Comparator;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;

class Model {
  private String _name, _summary;
  private File _file;
  private Bitmap _bitmap;
  private Uri _url;
  public Model(String name, String summary, File file)
  {
    _name = name;
    _summary = summary;
    _file = file;
  }
  public String getName() { return _name; }
  public String getSummary() { return _summary; }
  public File getFile() { return _file; }
  public Bitmap getBitmap() { return _bitmap; }
  public Uri getUrl() { return _url; }
  public void setBitmap(File f)
  {
    BitmapFactory.Options options = new BitmapFactory.Options();
    options.inJustDecodeBounds = false;
    options.inPreferredConfig = Bitmap.Config.RGB_565;
    options.inDither = true;
    _bitmap = BitmapFactory.decodeFile(f.toString(), options);
  }
  public void setUrl(Uri url) { _url = url; }
}

class ModelComp implements Comparator<Model> {
  @Override public int compare(Model e1, Model e2)
  {
    return e1.getName().compareTo(e2.getName());
  }
}
