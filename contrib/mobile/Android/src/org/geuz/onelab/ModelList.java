package org.geuz.onelab;

import java.io.File;
import java.io.FileInputStream;
import java.io.FilenameFilter;
import java.io.IOException;
import java.io.InputStream;

import org.xmlpull.v1.XmlPullParser;
import org.xmlpull.v1.XmlPullParserException;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.app.DialogFragment;
import android.content.DialogInterface;
import android.content.Intent;
import android.graphics.Color;
import android.net.Uri;
import android.os.Bundle;
import android.os.Environment;
import android.util.Xml;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup.LayoutParams;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.ListView;

public class ModelList extends Activity {
	
	private ModelArrayAdapter _modelArrayAdapter;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		_modelArrayAdapter = new ModelArrayAdapter(this);
		try {
			this.getModels();
		} catch (XmlPullParserException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}

		LinearLayout layout = new LinearLayout(this);
    	layout.setOrientation(LinearLayout.VERTICAL);
    	ListView list = new ListView(this);
    	Button loadSD = new Button(this);
    	loadSD.setText(R.string.button_open_external_file);
    	loadSD.setLayoutParams(new ListView.LayoutParams(LayoutParams.MATCH_PARENT, ListView.LayoutParams.WRAP_CONTENT));
    	loadSD.setOnClickListener(new View.OnClickListener() {
			
			public void onClick(View v) {
				@SuppressWarnings("unused")
				SDFileChooser f = new SDFileChooser();
			}
		});
    	//TODO list.addFooterView(loadSD);
    	list.setAdapter(_modelArrayAdapter);
    	list.setOnItemClickListener(new AdapterView.OnItemClickListener() {

			public void onItemClick(AdapterView<?> parent, View view, int position,
					long id) {
				Model m = _modelArrayAdapter.getModel(position);
				Intent intent = new Intent(ModelList.this, MainActivity.class);
				intent.putExtra("file", m.getFile().toString());
				intent.putExtra("name", m.getName());
				startActivity(intent);
			}
		});
    	list.setOnItemLongClickListener(new AdapterView.OnItemLongClickListener() {

			public boolean onItemLongClick(AdapterView<?> parent, View view,
					int position, long id) {
				final Model m = _modelArrayAdapter.getModel(position);
				CharSequence[] actions;
				if(m.getUrl() != null) {
					actions = new CharSequence[2];
					actions[0] = "Open this model";
					actions[1] = "More information";
				}
				else {
					actions = new CharSequence[1];
					actions[0] = "Open this model";
				}
				AlertDialog.Builder builder = new AlertDialog.Builder(parent.getContext());
				builder.setTitle(m.getName());
				builder.setItems(actions, new DialogInterface.OnClickListener() {
				    public void onClick(DialogInterface dialog, int position) {
				    	switch (position) {
						case 1:
							Intent browserIntent = new Intent(Intent.ACTION_VIEW, m.getUrl());
							startActivity(browserIntent);
							break;
						default:
							Intent intent = new Intent(ModelList.this, MainActivity.class);
							intent.putExtra("file", m.getFile().toString());
							intent.putExtra("name", m.getName());
							startActivity(intent);
							break;
						}
				    }
				});
				AlertDialog alert = builder.create();
				alert.show();
				return true;
			}
		});
    	layout.addView(list);
		this.setContentView(layout);
		layout.setPadding(15, 10, 10, 5);
		layout.setBackgroundColor(Color.argb(255, 67, 67, 67));
	}
	
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		MenuItem loadFile = menu.add(R.string.button_open_external_file);
		loadFile.setShowAsAction(MenuItem.SHOW_AS_ACTION_NEVER);
		return super.onCreateOptionsMenu(menu);
	}
	
	@Override
	public boolean onMenuItemSelected(int featureId, MenuItem item) {
		if(item.getTitle().equals(getString(R.string.button_open_external_file))) {
			Intent browserIntent = new Intent(Intent.ACTION_VIEW, Uri.fromFile(this.getFilesDir()));
			startActivity(browserIntent);
		}
		return super.onMenuItemSelected(featureId, item);
	}
	
	private void getModels() throws XmlPullParserException, IOException
    {
		File document = this.getFilesDir();
		File files[] = document.listFiles();
		for(int i=0; i<files.length; i++) {
			if(files[i].isDirectory()) { // models are in directory
				File xmlInfos = new File(files[i], "infos.xml");
				if(!xmlInfos.isFile()) continue;
				InputStream in = new FileInputStream(xmlInfos);
				try {
					XmlPullParser parser = Xml.newPullParser();
					parser.setFeature(XmlPullParser.FEATURE_PROCESS_NAMESPACES, false);
					parser.setInput(in, null);
					parser.nextTag();
					parser.require(XmlPullParser.START_TAG, null, "models");
					while (parser.next() != XmlPullParser.END_TAG) {
						if (parser.getEventType() != XmlPullParser.START_TAG) continue;
						String tagName = parser.getName();
						if(tagName.equals("model"))
							readModel(parser, files[i].toString());
						else
							skipTag(parser);
					}
				}
				finally {
					in.close();
				}
			}
		}
    }
	private void readModel(XmlPullParser parser, String dir) throws XmlPullParserException, IOException{
		parser.require(XmlPullParser.START_TAG, null, "model");
		String title = null;
	    String summary = null;
	    String file = null;
	    String bitmap = null;
	    String url = null;
	    while (parser.next() != XmlPullParser.END_TAG) {
	    	if (parser.getEventType() != XmlPullParser.START_TAG) continue;
	    	String name = parser.getName();
	    	if(name.equals("title")) {
	    		if (parser.next() == XmlPullParser.TEXT) {
	    			title = parser.getText();
	    			parser.nextTag();
	    		}
	    	}
	    	else if(name.equals("summary")) {
	    		if (parser.next() == XmlPullParser.TEXT) {
	    			summary = parser.getText();
	    			parser.nextTag();
	    		}
	    	}
	    	else if(name.equals("file")) {
	    		//String relType = parser.getAttributeValue(null, "type"); 
	    		if (parser.next() == XmlPullParser.TEXT) {
	    			file = parser.getText();
	    			parser.nextTag();
	    		}
	    	}
	    	else if(name.equals("preview")) {
	    		if (parser.next() == XmlPullParser.TEXT) {
	    			bitmap = parser.getText();
	    			parser.nextTag();
	    		}
	    	}
	    	else if(name.equals("url")) {
	    		if (parser.next() == XmlPullParser.TEXT) {
	    			url = parser.getText();
	    			parser.nextTag();
	    		}
	    	}
	    	else {
	    		skipTag(parser);
	    	}
	    }
	    if(title == null || file == null) return;
	    Model newModel = new Model(title, summary, new File(dir+"/"+file));
	    if(bitmap != null) newModel.setBitmap(new File(dir+"/"+bitmap));
	    if(url != null) newModel.setUrl(Uri.parse(url));
	    _modelArrayAdapter.add(newModel);
	}
	private void skipTag(XmlPullParser parser) throws XmlPullParserException, IOException {
	    if (parser.getEventType() != XmlPullParser.START_TAG) {
	        throw new IllegalStateException();
	    }
	    int depth = 1;
	    while (depth != 0) {
	        switch (parser.next()) {
	        case XmlPullParser.END_TAG:
	            depth--;
	            break;
	        case XmlPullParser.START_TAG:
	            depth++;
	            break;
	        }
	    }
	 }
	

    private class SDFileChooser{
    	File curentPath;
    	FileDialog dialog;
    	
    	public SDFileChooser() {
    		String state = Environment.getExternalStorageState();
    		if (Environment.MEDIA_MOUNTED.equals(state) || Environment.MEDIA_MOUNTED_READ_ONLY.equals(state)) {
    			curentPath = Environment.getExternalStorageDirectory();

    			showList(getFile(curentPath));
    		}
    		else
    			showMessage(R.string.error_nosdcard);
    	}
    	
    	public void setPath(String newPath) {
    		curentPath = new File(newPath);
    		showList(getFile(curentPath));
    		
    	}
    	public String getPath() {
    		return curentPath.toString();
    	}
    	
    	private void showList(String[] list) {
    		if(!curentPath.toString().equals(Environment.getExternalStorageDirectory().toString())){
    			String[] newList = new String[list.length + 1];
    			for(int i=0;i<list.length;i++)
    				newList[i+1] = list[i];
    			newList[0] = "..";
    			list = newList;
    		}	
    		if(list.length < 1){
    			showMessage(R.string.error_nomshfile);
    			return;
    		}
    		if(dialog != null) dialog.dismiss();
    		dialog = new FileDialog(this, list);
    		dialog.show(getFragmentManager(), "files");
    	}
    	
    	private void showMessage(int msg) {
    		dialog = new FileDialog(this, msg);
    		dialog.show(getFragmentManager(), "msg");
    	}
    	
    	private String[] getFile(File path) {
    		return path.list(new FilenameFilter() {
    			
    			public boolean accept(File dir, String filename) {
    				String ext = filename.substring(filename.lastIndexOf(".") + 1, filename.length());
    				File curent = new File(dir.toString()+"/"+filename);
    				if(curent.isHidden())
    					return false;
    				else if(curent.isDirectory())
    					return true;
    				else if(ext.equals("MSH") || ext.equals("msh") || ext.equals("geo") || ext.equals("GEO") || ext.equals("pro")  || ext.equals("PRO"))
    					return true;
    				else
    					return false;
    			}
    		});
    	}
    	private class FileDialog extends DialogFragment {
    		
    		String[] list;
    		int msg = -1;
    		SDFileChooser parent;
    		
    		public FileDialog(SDFileChooser p, String[] l) {
    			list = l;
    			parent = p;
    		}
    		public FileDialog(SDFileChooser p, int m) {
    			msg = m;
    			parent = p;
    		}
    		
    		@Override
    		public Dialog onCreateDialog(Bundle savedInstanceState) {
    			AlertDialog.Builder builder = new AlertDialog.Builder(getActivity());
    			if(msg > 0) {
    				builder.setMessage(R.string.error_nomshfile)
    				.setPositiveButton(R.string.button_ok, null);
    			}
    			else {
    				builder.setTitle(R.string.dialog_title_choosefile);
	        		builder.setItems(list, new DialogInterface.OnClickListener() {
						
						public void onClick(DialogInterface dialog, int which) {
							if(list[which].equals(".."))
								parent.setPath(curentPath.getParentFile().toString());
							else if( new File(parent.getPath() + "/" + list[which]).isDirectory())
								parent.setPath(parent.getPath() + "/" + list[which]);
							else {
								String ext = list[which].substring(list[which].lastIndexOf(".") + 1, list[which].length());
			    				if(ext.equals("MSH") || ext.equals("msh") || ext.equals("geo") || ext.equals("GEO") || ext.equals("pro")  || ext.equals("PRO")) {
			    					Intent intent = new Intent(ModelList.this, MainActivity.class);
			    					intent.putExtra("file", curentPath+"/"+getFile(curentPath)[which]);
			    					startActivity(intent);
			    				}
							}
						}
					});
    			}
    			return builder.create();
    		};
    	}
    	
    }

}
