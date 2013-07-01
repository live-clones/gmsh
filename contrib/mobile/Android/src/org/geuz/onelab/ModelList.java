package org.geuz.onelab;

import java.io.File;
import java.io.FilenameFilter;
import java.io.IOException;

import org.xmlpull.v1.XmlPullParser;
import org.xmlpull.v1.XmlPullParserException;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.app.DialogFragment;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.res.XmlResourceParser;
import android.graphics.Color;
import android.os.Bundle;
import android.os.Environment;
import android.view.View;
import android.view.ViewGroup.LayoutParams;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.ListView;
import android.widget.AdapterView.OnItemClickListener;

public class ModelList extends Activity {
	
	private Models modelList;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		
		this.modelList = new Models();
		this.getModels();
		
		LinearLayout layout = new LinearLayout(this);
    	layout.setOrientation(LinearLayout.VERTICAL);
    	ListView list = new ListView(this);
    	Button loadSD = new Button(this);
    	loadSD.setText(R.string.button_open_external_file);
    	loadSD.setLayoutParams(new LayoutParams(LayoutParams.MATCH_PARENT,LayoutParams.WRAP_CONTENT));
    	loadSD.setOnClickListener(new View.OnClickListener() {
			
			public void onClick(View v) {
				@SuppressWarnings("unused")
				SDFileChooser f = new SDFileChooser();
			}
		});
    	list.addFooterView(loadSD);
    	list.setAdapter( new ModeleArrayAdapter(this, modelList));
    	list.setOnItemClickListener(new OnItemClickListener() {

			public void onItemClick(AdapterView<?> parent, View view, int position,
					long id) {
				int model = (position < modelList.size())? position : 0;
				String path = getFilesDir() + "/" + modelList.getFile(model);
				
				Intent intent = new Intent(ModelList.this, MainActivity.class);
				intent.putExtra("model", model);
				intent.putExtra("file", path);
				intent.putExtra("name", modelList.getName(model));
				startActivity(intent);
			}
		});
    	layout.addView(list);
		this.setContentView(layout);
		layout.setPadding(15, 10, 10, 5);
		layout.setBackgroundColor(Color.argb(255, 67, 67, 67));
	}
	
	private void getModels()
    {
    	XmlResourceParser parser =  getResources().getXml(R.xml.models);
    	int eventType;
		try {
			eventType = parser.getEventType();
    	while (eventType != XmlPullParser.END_DOCUMENT) {
            if(eventType == XmlPullParser.START_DOCUMENT){
            	eventType = parser.next();
            	continue;
            }
            else if(eventType == XmlPullParser.START_TAG && parser.getName().equals("model")) {
            	String title = "", file = "", summary = "";
            	while(eventType != XmlPullParser.END_TAG || !parser.getName().equals("model"))
            	{
            		
            		eventType = parser.next();
            		if(eventType == XmlPullParser.START_TAG && parser.getName().equals("title")){
            			eventType = parser.next();
            			if(eventType == XmlPullParser.TEXT)
            				title = parser.getText();
            		}
            		else if(eventType == XmlPullParser.START_TAG && parser.getName().equals("summary")){
            			eventType = parser.next();
            			if(eventType == XmlPullParser.TEXT)
            				summary = parser.getText();
            		}
            		else if(eventType == XmlPullParser.START_TAG && parser.getName().equals("file")){
            			eventType = parser.next();
            			if(eventType == XmlPullParser.TEXT)
            				file = parser.getText();
            		}
            	}
            	if(title.length() > 0) modelList.addModel(title, summary, file);
            }
            eventType = parser.next();
           }
		} catch (XmlPullParserException e) {
			// TODO Error in XML file
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Error in XML file
			e.printStackTrace();
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
