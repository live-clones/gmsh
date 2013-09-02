package org.geuz.onelab;

import java.io.File;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;


class Model {
	private String _name, _summary;
	private File _file;
	private Bitmap _bitmap;
	
	public Model(String name, String summary, File file){
		_name = name;
		_summary = summary;
		_file = file;
	}
	public String getName() {
		return _name;
	}
	public String getSummary() {
		return _summary;
	}
	public File getFile() {
		return _file;
	}
	public Bitmap getBitmap() {
		return _bitmap;
	}
	public void setBitmap(File f) {
		_bitmap = BitmapFactory.decodeFile(f.toString());
	}
}
