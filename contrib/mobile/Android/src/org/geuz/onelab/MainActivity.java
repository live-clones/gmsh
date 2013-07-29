package org.geuz.onelab;

import java.util.ArrayList;
import java.util.List;

import android.opengl.GLSurfaceView;
import android.os.AsyncTask;
import android.os.Bundle;
import android.os.Handler;
import android.os.Vibrator;
import android.app.Activity;
import android.app.AlertDialog;
import android.app.ProgressDialog;

import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.res.Configuration;
import android.graphics.Color;
import android.graphics.Point;
import android.support.v4.view.PagerAdapter;
import android.support.v4.view.ViewPager;
import android.text.Editable;
import android.text.TextWatcher;
import android.util.DisplayMetrics;
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
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.EditText;
import android.widget.LinearLayout;
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
	private Gmsh gmsh;
	private Button run, reset;
	private UndragableViewPager pager;
	private List<Parameter> params = new ArrayList<Parameter>();
	private SeparatedListView paramListView;
	private boolean compute = false;

    @Override
    public void onCreate(Bundle savedInstanceState) {
    	super.onCreate(savedInstanceState);
    	
    	getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,
				WindowManager.LayoutParams.FLAG_FULLSCREEN);

    	LinearLayout layout = new LinearLayout(this);
    	loading = new ProgressDialog(this);
    	layout.setLayoutParams(new LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.MATCH_PARENT));
    	layout.setOrientation(LinearLayout.VERTICAL);
    	pager = new UndragableViewPager(this);
    	pager.setLayoutParams(new LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.MATCH_PARENT));
    	pager.setAdapter(new AdaptedPager());
    	pager.setOffscreenPageLimit(2);
    	pager.setCurrentItem(0);
    	layout.addView(pager);
    	dialogBuilder = new AlertDialog.Builder(this);

    	Intent intent = getIntent();

    	gmsh = new Gmsh("", mainHandler);
    	Bundle extras = getIntent().getExtras(); 
    	if(intent != null && intent.getAction() != null && intent.getAction().equals(Intent.ACTION_VIEW)) {
    		String tmp = intent.getData().getPath();
    		pager.setCurrentItem(1, true);
    		gmsh.load(tmp);
    	}    		
    	else if(extras != null) {
    		pager.setCurrentItem(0, true);
    		//extras.getInt("model");
    		//extras.getString("name");
    		String tmp = extras.getString("file");
    		gmsh.load(tmp);
			getAvailableParam();
			if(params.size()>0)params.get(params.size() - 1)._changed = true; // Hack for the first run
    	}
    	else
    		this.finish();
    	setContentView(layout);
    }
    
    @Override
    protected void onDestroy() {
    	// TODO Unload library ?
    	super.onDestroy();
    }
    
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
    	super.onCreateOptionsMenu(menu);
    	MenuItem listitem = menu.add(Menu.NONE, Menu.NONE, Menu.NONE, R.string.menu_list);
        if(getResources().getConfiguration().orientation == Configuration.ORIENTATION_PORTRAIT || screenInch() < 7)
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
    		pager.setCurrentItem(0, true);
    	else if(item.getTitle().equals(getString(R.string.menu_list))) {
    		if(this.compute)
    			loading.show();
    		else
    			this.finish();
    	}
    	else if (item.getTitle().equals(getString(R.string.menu_model)))
    		pager.setCurrentItem(1, true);
    	else if(item.getTitle().equals(getString(R.string.menu_postpro))){
    		dialogBuilder.setTitle("Post proccessing")
    			.setView(postproView())
				.setPositiveButton("Ok", null)
				.show();
    	}
    	/*else if(item.getTitle().equals(getString(R.string.menu_view_x))){
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
		}*/ // TODO
    	return super.onMenuItemSelected(featureId, item);
    }
    
    private class UndragableViewPager extends ViewPager{

		public UndragableViewPager(Context context) {
			super(context);
		}
		
		@Override
		public boolean onTouchEvent(MotionEvent arg0) {
			return true;
		}
		
		@Override
		public boolean onInterceptTouchEvent(MotionEvent arg0) {
			return false;
		}
    	
    }
    
    private class AdaptedPager extends PagerAdapter {
    	
    	@Override
    	public Object instantiateItem(ViewGroup container, int position) {
    		switch (position) {
			case 0: // Parameters
				(MainActivity.this).getAvailableParam();
				View paramView = (MainActivity.this).paramView(container.getContext());
				container.addView(paramView);
				paramView.setPadding(15, 10, 10, 5);
				return paramView;
			case 1: // OpenGL ES view
				renderer = new GLESRender(gmsh);
				glView = new mGLSurfaceView(container.getContext(), renderer);
				glView.setEGLContextClientVersion(1);
				glView.setRenderer(renderer);
				glView.setRenderMode(GLSurfaceView.RENDERMODE_WHEN_DIRTY);
				glView.requestRender();
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
			if(getResources().getConfiguration().orientation == Configuration.ORIENTATION_LANDSCAPE)
			{
				if(screenInch() < 7)
					return 1f;
				switch (position) {
				case 1:
					return 0.25f;
				case 2:
					return 0.75f;
				default:
					return 1f;
				}
			}
			
			return 1f;
		}

		@Override
		public boolean isViewFromObject(View view, Object object) {
			return(view == object);
		}
   	
    }
    
    public double screenInch()
    {
        Point size = new Point();
		getWindowManager().getDefaultDisplay().getSize(size);
		int width = size.x;
		int height = size.y;
        DisplayMetrics dm = new DisplayMetrics();
        getWindowManager().getDefaultDisplay().getMetrics(dm);
        double x = Math.pow(width/dm.xdpi,2);
        double y = Math.pow(height/dm.ydpi,2);
        return Math.sqrt(x+y);
    }
    
    private void getAvailableParam(){
    	String[] tmp = gmsh.getParams();
		for(String s : tmp){ // for each parameters in ONEALB
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
    	run = new Button(ctx);
    	reset = new Button(ctx);
    	run.setText("Run");
    	reset.setText("Reset");
    	run.setOnClickListener(new OnClickListener() {
    		public void onClick(View v) {
	    		if(compute) {
	    			loading.show();
	    		}
	    		else {
	    			new Run().execute();
	    			pager.setCurrentItem(1, true);
	    		}
    		}
    	});
    	reset.setOnClickListener(new OnClickListener() {public void onClick(View v) {
    		if(gmsh.onelabCB("reset") == 1){
    			getAvailableParam();
				glView.requestRender();
			}
			pager.setCurrentItem(0, true);
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
    	return paramListView;
    }
    
    private class Run extends AsyncTask<Void, Void, Integer[]> {

    	@Override
    	protected void onPreExecute() {
    		compute = true;
    		loading.setTitle("Please wait");
        	loading.setButton(DialogInterface.BUTTON_NEUTRAL, "Hide", new DialogInterface.OnClickListener() {
    			
    			public void onClick(DialogInterface dialog, int which) {
    				loading.dismiss();
    			}
    		});
        	loading.setButton(DialogInterface.BUTTON_NEGATIVE, "Stop", new DialogInterface.OnClickListener() {
    			
    			public void onClick(DialogInterface dialog, int which) {
    				gmsh.onelabCB("stop");
    				run.setEnabled(false);
    			}
    		});
    		loading.setMessage("...");
    		loading.show();
    		//run.setText("Show progress");
    		reset.setEnabled(false);
    		super.onPreExecute();
    	}
    	
		@Override
		protected Integer[] doInBackground(Void... params) {
				gmsh.onelabCB("compute");
			return new Integer[] {1};
		}

		@Override
		protected void onPostExecute(Integer[] result) {
			Vibrator v = (Vibrator) getSystemService(Context.VIBRATOR_SERVICE);
			if(!v.hasVibrator()) // TODO Do not commit this line !
				v.vibrate(350);
			reset.setEnabled(true);
			run.setEnabled(true);
			//run.setText("Run"); // TODO this seems break the ViewPager
			glView.requestRender();
			super.onPostExecute(result);
			loading.dismiss();
			compute = false;
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
