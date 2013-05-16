package org.geuz.onelab;

import java.io.File;
import java.io.FileOutputStream;
import java.io.FilenameFilter;
import java.io.IOException;
import java.io.InputStream;
import java.lang.reflect.Field;
import java.util.ArrayList;
import java.util.List;

import org.xmlpull.v1.XmlPullParser;
import org.xmlpull.v1.XmlPullParserException;

import android.opengl.GLSurfaceView;
import android.os.AsyncTask;
import android.os.Bundle;
import android.os.Environment;
import android.os.Handler;
import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.app.DialogFragment;
import android.app.ProgressDialog;

import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.res.Configuration;
import android.content.res.XmlResourceParser;
import android.graphics.Color;
import android.support.v4.view.PagerAdapter;
import android.support.v4.view.ViewPager;
import android.text.Editable;
import android.text.TextWatcher;
import android.util.Log;
import android.view.MenuItem;
import android.view.MotionEvent;
import android.view.SubMenu;
import android.view.View.OnClickListener;
import android.view.ViewGroup.LayoutParams;
import android.view.KeyEvent;
import android.view.Menu;
import android.view.View;
import android.view.ViewGroup;
import android.view.WindowManager;
import android.view.inputmethod.InputMethodManager;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.ListView;
import android.widget.ScrollView;
import android.widget.Spinner;
import android.widget.TableLayout;
import android.widget.TableRow;
import android.widget.TextView;

public class MainActivity extends Activity {

	private mGLSurfaceView glView;
	private GLESRender renderer;
	private ProgressDialog loading;
	private AlertDialog.Builder dialogBuilder;
	private Models modelList;
	private int model;
	private Gmsh gmsh;
	private Button run, reset;
	private UndragableViewPager pager;
	private List<Parameter> params = new ArrayList<Parameter>();
	private SeparatedListView paramListView;

    @Override
    public void onCreate(Bundle savedInstanceState) {
    	super.onCreate(savedInstanceState);
    	
    	getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,
				WindowManager.LayoutParams.FLAG_FULLSCREEN);
    	//this.requestWindowFeature(Window.FEATURE_NO_TITLE);
    	
    	LinearLayout layout = new LinearLayout(this);
    	loading = new ProgressDialog(this);
    	layout.setLayoutParams(new LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.MATCH_PARENT));
    	layout.setOrientation(LinearLayout.VERTICAL);
    	pager = new UndragableViewPager(this);
    	pager.setLayoutParams(new LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.MATCH_PARENT));
    	pager.setAdapter(new AdaptedPager());
    	pager.setOffscreenPageLimit(3);
    	pager.setCurrentItem(0);
    	layout.addView(pager);
    	dialogBuilder = new AlertDialog.Builder(this);

    	Intent intent = getIntent();

    	gmsh = new Gmsh("", mainHandler);
    	modelList = new Models();
    	getModels();
    	loadNative();
    	if(intent.getAction().equals(Intent.ACTION_VIEW)) {
    		String tmp = intent.getData().getPath();
    		gmsh.load(tmp);
    	}
    	else if(modelList.size() > 0){
    		model = 0;
	    	String tmp = getFilesDir()+ "/" + modelList.getFile(model);
	    	gmsh.load(tmp);
    	}
    	setContentView(layout);
    }
    
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
    	super.onCreateOptionsMenu(menu);
    	MenuItem listitem = menu.add(Menu.NONE, Menu.NONE, Menu.NONE, R.string.menu_list);
        if(getResources().getConfiguration().orientation == Configuration.ORIENTATION_PORTRAIT)
        {
        	MenuItem paramitem = menu.add(Menu.NONE, Menu.NONE, Menu.NONE, R.string.menu_settings);
        	paramitem.setIcon(R.drawable.ic_settings);
        	paramitem.setShowAsAction(MenuItem.SHOW_AS_ACTION_IF_ROOM);
        }
        MenuItem modelitem = menu.add(Menu.NONE, Menu.NONE, Menu.NONE, R.string.menu_model);
        MenuItem postitem = menu.add(Menu.NONE, Menu.NONE, Menu.NONE, R.string.menu_postpro);
        SubMenu viewitem = menu.addSubMenu(R.string.menu_view);
        
        
        listitem.setIcon(R.drawable.ic_list);
        modelitem.setIcon(R.drawable.ic_mesh);
        listitem.setShowAsAction(MenuItem.SHOW_AS_ACTION_IF_ROOM);
        modelitem.setShowAsAction(MenuItem.SHOW_AS_ACTION_IF_ROOM);
        postitem.setShowAsAction(MenuItem.SHOW_AS_ACTION_COLLAPSE_ACTION_VIEW);
        
        viewitem.add(R.string.menu_view_x);
        viewitem.add(R.string.menu_view_y);
        viewitem.add(R.string.menu_view_z);
        viewitem.add(R.string.menu_view_scale);
        viewitem.add(R.string.menu_view_translation);
        return true;
    }
    @Override
    public boolean onMenuItemSelected(int featureId, MenuItem item) {
    	if(item.getTitle().equals(getString(R.string.menu_settings)))
    		pager.setCurrentItem(1, true);
    	else if(item.getTitle().equals(getString(R.string.menu_list)))
    		pager.setCurrentItem(0, true);
    	else if (item.getTitle().equals(getString(R.string.menu_model)))
    		pager.setCurrentItem(2, true);
    	else if(item.getTitle().equals(getString(R.string.menu_postpro))){
    		dialogBuilder.setTitle("Post proccessing")
    			.setView(postproView())
				.setPositiveButton("Ok", null)
				.show();
    	}
    	else if(item.getTitle().equals(getString(R.string.menu_view_x))){
    		renderer.rotate(0, 0, 0);
    		renderer.rotate(90, 0, 0);
    		glView.requestRender();
    	}
		else if(item.getTitle().equals(getString(R.string.menu_view_y))){
			renderer.rotate(0, 0, 0);
			renderer.rotate(0, 90, 0);
			glView.requestRender();
		}
		else if(item.getTitle().equals(getString(R.string.menu_view_z))){
			renderer.rotate(0, 0, 0);
			glView.requestRender();
		}
		else if(item.getTitle().equals(getString(R.string.menu_view_scale))){
			glView.resetScale();
			glView.requestRender();
		}
		else if(item.getTitle().equals(getString(R.string.menu_view_translation))){
			renderer.translate(0, 0, 0);
			glView.requestRender();
		}
    	return super.onMenuItemSelected(featureId, item);
    }
    
    private class UndragableViewPager extends ViewPager{

		public UndragableViewPager(Context context) {
			super(context);
		}
		@Override
		public boolean onInterceptTouchEvent(MotionEvent arg0) {
			return false;
			//return super.onInterceptTouchEvent(arg0);
		}
    	
    }
    
    private class AdaptedPager extends PagerAdapter {
    	
    	@Override
    	public Object instantiateItem(ViewGroup container, int position) {
    		switch (position) {
			case 0: // Select a model
				View listView = listView(container.getContext());
				container.addView(listView);
				listView.setPadding(15, 10, 10, 5);
				listView.setBackgroundColor(Color.argb(255, 67, 67, 67));
				return listView;
			case 1: // Parameters
				(MainActivity.this).getAvailableParam();
				View paramView = (MainActivity.this).paramView(container.getContext());
				container.addView(paramView);
				paramView.setPadding(15, 10, 10, 5);
				return paramView;
			case 2: // OpenGL ES view
				renderer = new GLESRender(gmsh);
				glView = new mGLSurfaceView(container.getContext(), renderer);
				//TODO the glView seems break the ViewPager (black square appear ...)
				glView.setEGLContextClientVersion(1);
				glView.setRenderer(renderer);
				glView.setRenderMode(GLSurfaceView.RENDERMODE_WHEN_DIRTY);

				container.addView(glView);
				return glView;
			default: // ???
				View defaultView = new View(container.getContext());
				defaultView.setBackgroundColor(Color.argb(255, 255, 0, 0));
				container.addView(defaultView);
				return defaultView;
			}
    	}

		@Override
		public int getCount() {
			return 3;
		}
		
		@Override
		public float getPageWidth(int position) {
			getResources().getConfiguration();
			if(getResources().getConfiguration().orientation == Configuration.ORIENTATION_LANDSCAPE)
			{
				switch (position) {
				case 1:
					if((MainActivity.this).getWindowManager().getDefaultDisplay().getWidth() < 500 )
						return 1f;
					return 0.25f;
				case 2:
					if((MainActivity.this).getWindowManager().getDefaultDisplay().getWidth() < 500 )
						return 1f;
					return 0.75f;
				default:
					return 1f;
				}
			}
			switch (position) {
			case 1:
				if((MainActivity.this).getWindowManager().getDefaultDisplay().getWidth() < 500 )
					return 1f;
				return 0.5f;
			case 2:
				return 1f;
			default:
				return 1f;
			}
		}

		@Override
		public boolean isViewFromObject(View view, Object object) {
			return(view == object);
		}
   	
    }
    
    private void getAvailableParam(){
    	String[] tmp = gmsh.getParams();
		for(String s : tmp){ // for each parameters in onelab
			boolean found = false;
			for(Parameter p : params){ // for each parameters
				if(s.split("\n")[2].equals(p.getName())){ // the parameter already exist, just refresh it
					if(p.getType().equals("ParameterNumber"))
						((ParameterNumber)p).fromString(s);
					else if(p.getType().equals("ParameterString"))
						((ParameterString)p).fromString(s);
					found = true;
					break;
				}
			}
			if(found) continue;
			// add new parameter
			if(s.split("\n")[1].equals("number")){
				final ParameterNumber mParam = new ParameterNumber(this, gmsh, glView, "");
				if(mParam.fromString(s) == -1) continue;
				params.add(mParam);
				if(paramListView != null){
					paramListView.addItem(mParam.getName().split("/")[0].equals("Parameters")? mParam.getName().split("/")[0] + " > " + mParam.getName().split("/")[1]: mParam.getName().split("/")[0], mParam.getView());
				}
			}
			else if(s.split("\n")[1].equals("string")){
				ParameterString mParam = new ParameterString(this, gmsh, glView, "");
				if(mParam.fromString(s) != -1){
					params.add(mParam);
					if(paramListView != null)
						paramListView.addItem(mParam.getName().split("/")[0], mParam.getView());
				}
			}
		}
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
    
    /**
     * Load file from res/raw/ directory to the files directory of the application.
     */
    private void loadNative()
    {
    	for( Field f : R.raw.class.getFields()) {
    		try {
				int Msh = f.getInt(null), i;
				String androidName = getResources().getResourceEntryName(Msh);
				StringBuilder tmp = new StringBuilder(androidName);
				tmp.setCharAt(androidName.lastIndexOf('_'), '.');
				String nativeName = tmp.toString();
				//String nativeExtension = nativeName.substring(nativeName.lastIndexOf('.'));
				/*if(new File(getFilesDir().toString()+"/"+nativeName).exists()){
					//TODO check if the files are the same
					continue;
				}*/
				InputStream mshFile = getResources().openRawResource(Msh);
		    	
		    	FileOutputStream outputStream = openFileOutput(nativeName, Context.MODE_WORLD_READABLE);
		    	byte[] buffer = new byte[2048];
		    	
		    	while ((i = mshFile.read(buffer, 0, buffer.length)) > 0) 
					outputStream.write(buffer,0,i);

			} catch (IllegalArgumentException e) {
				Log.e("Load files", "Error " + e.toString());
				
			} catch (IllegalAccessException e) {
				Log.e("Load files", "Error " + e.toString());
				
			} catch (IOException e) {
				Log.e("Load files", "Error " + e.toString());
			}
    	}
    }
    
    private View postproView() {
    	ScrollView scroll = new ScrollView(this);
    	scroll.setLayoutParams(new LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.WRAP_CONTENT));
    	String[] PViews = gmsh.getPView();
    	if(PViews.length < 1){
    		LinearLayout layout = new LinearLayout(this);
    		TextView noPView = new TextView(this);
    		noPView.setText("There is no post processing data !");
    		layout.addView(noPView);
    		return layout;
    	}
    	TableLayout table = new TableLayout(this);
    	table.setColumnShrinkable(0, true);
    	TableRow title = new TableRow(this);
    	TextView title_name = new TextView(this);
    	TextView title_intervalType = new TextView(this);
    	TextView title_intervals = new TextView(this);
    	title_name.setText("Name");
    	title_intervals.setText("Intervals");
    	title_intervalType.setText("Interval type");
    	title.addView(title_name);
    	title.addView(title_intervalType);
    	title.addView(title_intervals);
    	table.addView(title);
    	for(int i=PViews.length-1; i >= 0;i--){
    		TableRow row = new TableRow(this);
    		final int myID =i;
    		String[] infos = PViews[i].split("\n"); // name / IntervalsType (1=Iso 2=Continous 3=Discrete 4=Numeric)
        	CheckBox checkbox = new CheckBox(this);
        	final Spinner spinner = new Spinner(this);
        	final EditText nbIso = new EditText(this);
        	checkbox.setText(infos[0]);
        	checkbox.setChecked(infos[2].equals("1"));
        	checkbox.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
				
				public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
					gmsh.setPView(myID, -1, (isChecked)? 1 : 0, -1);
					spinner.setEnabled(isChecked);
					glView.requestRender();
				}
			});
        	spinner.setEnabled(infos[2].equals("1"));
        	ArrayList<String> choices;
        	ArrayAdapter<String> adapter;
        	choices = new ArrayList<String>();
    		choices.add("Iso-values");
    		choices.add("Continous map");
    		choices.add("Filled iso-values");
    		adapter = new ArrayAdapter<String>(this, android.R.layout.simple_spinner_dropdown_item, choices);
    		adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        	spinner.setAdapter(adapter);
        	spinner.setSelection(Integer.parseInt(infos[1])-1);
        	spinner.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {

				public void onItemSelected(AdapterView<?> parent, View view,
						int pos, long id) {
					gmsh.setPView(myID, pos+1, -1, -1);
					glView.requestRender();
					nbIso.setEnabled(pos == 0 || pos == 2);
				}
				public void onNothingSelected(AdapterView<?> arg0) {} // Unused Auto-generated method stub
			});
        	nbIso.setText(infos[3]);
        	nbIso.setRawInputType(Configuration.KEYBOARD_12KEY);
        	nbIso.setOnKeyListener(new View.OnKeyListener() {
				
				public boolean onKey(View v, int keyCode, KeyEvent event) {
					if(keyCode == KeyEvent.KEYCODE_ENTER){ // hide the keyboard
						InputMethodManager imm = (InputMethodManager)getSystemService(
							      Context.INPUT_METHOD_SERVICE);
							imm.hideSoftInputFromWindow(nbIso.getWindowToken(), 0);
						return true;
					}
					return false;
				}
			});
        	nbIso.addTextChangedListener(new TextWatcher() {
				
				public void onTextChanged(CharSequence s, int start, int before, int count) {
					
					int nIso = 1;
					try {
						if(s.length() < 1) nIso = 1;
						else nIso = Integer.parseInt(s.toString());
					}
					catch(NumberFormatException e)
					{
						nIso = 1;
						nbIso.setText("");
					}
					if(nIso > 1000) {gmsh.setPView(myID, -1, -1, 1000); nbIso.setText("1000");}
					else if(nIso > 0) gmsh.setPView(myID, -1, -1, nIso);
					else gmsh.setPView(myID, -1, -1, 1);
					glView.requestRender();
				}
				
				public void beforeTextChanged(CharSequence s, int start, int count, int after) {} // UNUSED Auto-generated method stub
				public void afterTextChanged(Editable s) {} // UNUSED Auto-generated method stub

			});
        	row.addView(checkbox);
        	row.addView(spinner);
        	row.addView(nbIso);
        	table.addView(row);
    	}
    	scroll.addView(table);
    	return scroll;
    }
    
    private View paramView(Context ctx) {
    	LinearLayout layout = new LinearLayout(this);
    	layout.setOrientation(LinearLayout.VERTICAL);
    	/*TextView title = new TextView(ctx);
    	title.setText(R.string.title_parameter);
    	title.setTextAppearance(ctx, android.R.style.TextAppearance_DeviceDefault_Large);
    	title.setTextColor(Color.BLACK);*/
    	run = new Button(ctx);
    	reset = new Button(ctx);
    	run.setText("Run");
    	reset.setText("Reset");
    	//reset.setEnabled(false);
    	run.setOnClickListener(new OnClickListener() {public void onClick(View v) {
    		if(run.getText().equals("Show step"))
    		{
    			loading.show();
    			return;
    		}
    		boolean changed = false;
			for(Parameter p : params){
				if(p.changed()){
					changed = true;
					break;
				}
			}
			if(changed){
				new Run().execute();
				//gmsh.onelabCB("compute");
				
			}
			getAvailableParam();
				
			pager.setCurrentItem(2, true);
		}});
    	reset.setOnClickListener(new OnClickListener() {public void onClick(View v) {
    		if(gmsh.onelabCB("reset") == 1){
    			getAvailableParam();
				glView.requestRender();
			}
			pager.setCurrentItem(1, true);
		}});
    	LinearLayout onelabBtns = new LinearLayout(this);
    	onelabBtns.setOrientation(LinearLayout.HORIZONTAL);
    	LinearLayout.LayoutParams lp = new LinearLayout.LayoutParams(LayoutParams.WRAP_CONTENT, LayoutParams.MATCH_PARENT);
    	lp.weight = 1;
    	onelabBtns.addView(reset, lp);
    	onelabBtns.addView(run, lp);
    	CheckBox showMesh = new CheckBox(ctx);
    	showMesh.setText("Show the mesh");
    	showMesh.setChecked(false);
    	showMesh.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
			
			public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
				gmsh.showMesh(isChecked);
				glView.requestRender();
			}
		});
    	CheckBox showGeom = new CheckBox(ctx);
    	showGeom.setText("Show the geometry");
    	showGeom.setChecked(true);
    	showGeom.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
			
			public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
				gmsh.showGeom(isChecked);
				glView.requestRender();
			}
		});
    	paramListView = new SeparatedListView(ctx, new View[] {showMesh, showGeom, onelabBtns});
    	paramListView.setDividerHeight(0);
    	for(Parameter p : params)
    	{
    		paramListView.addItem(p.getName().split("/")[0].equals("Parameters")? p.getName().split("/")[0] + " > " + p.getName().split("/")[1]: p.getName().split("/")[0], p.getView());
    		p.setList(paramListView);
    	}
    	/*LinearLayout.LayoutParams layoutParams = new LinearLayout.LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.WRAP_CONTENT);
    	layoutParams.weight = 1;
    	layout.addView(paramListView, layoutParams);
    	layoutParams = new LinearLayout.LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.WRAP_CONTENT);
    	layoutParams.weight = 0;
    	layoutParams.gravity = Gravity.BOTTOM;
    	layout.addView(onelabBtns,layoutParams);
    	return layout;*/
    	//layout.addView(onelabBtns);
    	//layout.addView(paramListView);
    	//return layout;
    	return paramListView;
    }
    
    private View listView(Context ctx) {
    	LinearLayout layout = new LinearLayout(ctx);
    	layout.setOrientation(LinearLayout.VERTICAL);
    	ListView list = new ListView(ctx);
    	list.setAdapter( new ModeleArrayAdapter(ctx, modelList));
    	list.setOnItemClickListener(new OnItemClickListener() {

			public void onItemClick(AdapterView<?> parent, View view, int position,
					long id) {
				model = (position < modelList.size())? position : 0;
				String tmp = getFilesDir() + "/" + modelList.getFile(model);
				gmsh.load(tmp);
				
				params.clear();
				paramListView.clear();
				getAvailableParam();
				if(params.size()>0)params.get(params.size() - 1)._changed = true; // Hack for the first run
				glView.requestRender();
				pager.setCurrentItem(1);
			}
		});
    	layout.addView(list);
    	Button loadSD = new Button(ctx);
    	loadSD.setText(R.string.button_open_external_file);
    	loadSD.setLayoutParams(new LayoutParams(LayoutParams.MATCH_PARENT,LayoutParams.WRAP_CONTENT));
    	loadSD.setOnClickListener(new OnClickListener() {
			
			public void onClick(View v) {
				@SuppressWarnings("unused")
				SDFileChooser f = new SDFileChooser();
			}
		});
    	layout.addView(loadSD);
    	return layout;
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
    				else if(ext.equals("MSH") || ext.equals("msh"))
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
			    				if(ext.equals("MSH") || ext.equals("msh")) {
			    					gmsh.load(curentPath+"/"+getFile(curentPath)[which]);
			    					glView.requestRender();
			    				}
							}
						}
					});
    			}
    			return builder.create();
    		};
    	}
    	
    }
    
    private class Run extends AsyncTask<Void, Void, Integer[]> {

    	@Override
    	protected void onPreExecute() {
    		loading.setTitle("Please wait");
        	loading.setButton(DialogInterface.BUTTON_NEUTRAL, "Hide", new DialogInterface.OnClickListener() {
    			
    			public void onClick(DialogInterface dialog, int which) {
    				loading.dismiss();
    			}
    		});
        	loading.setButton(DialogInterface.BUTTON_NEGATIVE, "Stop", new DialogInterface.OnClickListener() {
    			
    			public void onClick(DialogInterface dialog, int which) {
    				//loading.dismiss();
    				//run.setText("Run");
    				gmsh.onelabCB("stop");
    				run.setEnabled(false);
    				//cancel(true);
    			}
    		});
    		loading.setMessage("...");
    		loading.show();
    		//run.setEnabled(false);
    		run.setText("Show progress");
    		super.onPreExecute();
    	}
    	
		@Override
		protected Integer[] doInBackground(Void... params) {
				gmsh.onelabCB("compute");
			return new Integer[] {1};
		}

		@Override
		protected void onPostExecute(Integer[] result) {
			loading.dismiss();
			//run.setEnabled(true);
			run.setText("Run");
			run.setEnabled(true);
			glView.requestRender();
			super.onPostExecute(result);
		}
    	
    }

    private final Handler mainHandler = new Handler(){
    	public void handleMessage(android.os.Message msg) {
    		switch (msg.what) {
			case 0: // we get a message from gmsh library
				String message =(String) msg.obj;
				dialogBuilder
			    .setTitle("Erreur Gmsh/GetDP")
			    .setMessage(message)
			    .setPositiveButton("Continue", new DialogInterface.OnClickListener() {
			        public void onClick(DialogInterface dialog, int which) { 
			            dialog.dismiss();
			        }
			     })
			     .show();

				break;
			case 1: // request render from gmsh library
				if(glView != null)
				glView.requestRender();
				getAvailableParam();
				break;
			case 2: // we get a message for loading
				String loadingMessage =(String) msg.obj;
				loading.setMessage(loadingMessage);
				break;
			case 3: // we get a progress for loading
				loading.setProgress(msg.arg1);
				break;
			default:
				break;
			}
    	};
    };
}
