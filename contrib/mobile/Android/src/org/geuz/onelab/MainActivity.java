package org.geuz.onelab;

import android.app.ActionBar;
import android.app.Activity;
import android.content.Intent;
import android.graphics.Color;
import android.graphics.drawable.ColorDrawable;
import android.os.AsyncTask;
import android.os.Bundle;
import android.os.Handler;
import android.app.FragmentTransaction;
import android.view.Menu;
import android.view.MenuItem;
import android.view.Window;
import android.view.WindowManager;


public class MainActivity extends Activity implements OptionsDisplayFragment.OnOptionRequestRender{

	private Gmsh _gmsh;
	private boolean _compute, _twoPane;
	private MenuItem _runStopMenuItem, _switchFragmentMenuItem;
	private ModelFragment _modelFragment;
	private OptionsFragment _optionsFragment;

	public MainActivity() {
	}
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN, WindowManager.LayoutParams.FLAG_FULLSCREEN);
		getWindow().requestFeature(Window.FEATURE_ACTION_BAR_OVERLAY);
		setContentView(R.layout.main_activity_layout);
		_gmsh = new Gmsh("", mainHandler);
		ActionBar actionBar = getActionBar();
		actionBar.setDisplayHomeAsUpEnabled(true);
		actionBar.setBackgroundDrawable(new ColorDrawable(Color.parseColor("#64000000")));
		Intent intent = getIntent();
    	Bundle extras = intent.getExtras(); 
    	if(intent != null && intent.getAction() != null && intent.getAction().equals(Intent.ACTION_VIEW)) {
    		String tmp = intent.getData().getPath();
    		_gmsh.load(tmp);
    	}    		
    	else if(extras != null) {
    		//extras.getInt("model");
    		//extras.getString("name");
    		String tmp = extras.getString("file");
    		_gmsh.load(tmp);
    	}
    	else
    		this.finish();
    	_twoPane = (findViewById(R.id.parameter_fragment) != null);
    	if(_twoPane) {
    		_optionsFragment = OptionsFragment.newInstance(_gmsh);
    		getFragmentManager().beginTransaction().add(R.id.parameter_fragment, _optionsFragment).commit();
    		_modelFragment = ModelFragment.newInstance(_gmsh);
    		getFragmentManager().beginTransaction().add(R.id.model_fragment, _modelFragment).commit();
    	}
    	else {
    		_optionsFragment = OptionsFragment.newInstance(_gmsh);
    		_modelFragment = ModelFragment.newInstance(_gmsh);
    		getFragmentManager().beginTransaction().add(R.id.model_fragment, _modelFragment).commit();
    	}
	}
	@Override
    public boolean onCreateOptionsMenu(Menu menu) {
    	super.onCreateOptionsMenu(menu);
    	if(!_twoPane) {
    		_switchFragmentMenuItem = menu.add(R.string.menu_parameters);
    		_switchFragmentMenuItem.setShowAsAction(MenuItem.SHOW_AS_ACTION_IF_ROOM);
    	}
    	_runStopMenuItem = menu.add(R.string.menu_run);
    	_runStopMenuItem.setShowAsAction(MenuItem.SHOW_AS_ACTION_ALWAYS);
        return true;
    }
	@Override
    public boolean onMenuItemSelected(int featureId, MenuItem item) {
    	if (item.getTitle().equals(getString(R.string.menu_parameters))) {
    		item.setTitle(R.string.menu_model);
    		FragmentTransaction ft = getFragmentManager().beginTransaction();
            ft.replace(R.id.model_fragment, _optionsFragment);
            ft.setTransition(FragmentTransaction.TRANSIT_FRAGMENT_OPEN);
            ft.commit();
    	}
    	else if (item.getTitle().equals(getString(R.string.menu_model))) {
    		item.setTitle(R.string.menu_parameters);
    		FragmentTransaction ft = getFragmentManager().beginTransaction();
            ft.replace(R.id.model_fragment, _modelFragment);
            ft.setTransition(FragmentTransaction.TRANSIT_FRAGMENT_CLOSE);
            ft.commit();
    	}
    	else if(item.getTitle().equals(getString(R.string.menu_run))){
    		if(_switchFragmentMenuItem != null && _switchFragmentMenuItem.getTitle().equals(getString(R.string.menu_model))) {
    			_switchFragmentMenuItem.setTitle(R.string.menu_parameters);
        		FragmentTransaction ft = getFragmentManager().beginTransaction();
                ft.replace(R.id.model_fragment, _modelFragment);
                ft.setTransition(FragmentTransaction.TRANSIT_FRAGMENT_CLOSE);
                ft.commit();
    		}
    		new Run().execute();
    	}
    	else if(item.getTitle().equals(getString(R.string.menu_stop))){
    		_gmsh.onelabCB("stop");
    	}
		else if(item.getItemId() == android.R.id.home)
		{
			if(this._compute)
    			;//TODO loading.show();
    		else
    			this.finish();
		}
    	return super.onMenuItemSelected(featureId, item);
    }
	
	private class Run extends AsyncTask<Void, Void, Integer[]> {

    	@Override
    	protected void onPreExecute() {
    		_compute = true;
    		_runStopMenuItem.setTitle(R.string.menu_stop);
    		/*loading.setTitle("Please wait");
        	loading.setButton(DialogInterface.BUTTON_NEUTRAL, "Hide", new DialogInterface.OnClickListener() {
    			
    			public void onClick(DialogInterface dialog, int which) {
    				loading.dismiss();
    			}
    		});
        	loading.setButton(DialogInterface.BUTTON_NEGATIVE, "Stop", new DialogInterface.OnClickListener() {
    			
    			public void onClick(DialogInterface dialog, int which) {
    				gmsh.onelabCB("stop");
    			}
    		});
    		loading.setMessage("...");
    		loading.show();
    		reset.setEnabled(false);*/
    		super.onPreExecute();
    	}
    	
		@Override
		protected Integer[] doInBackground(Void... params) {
				_gmsh.onelabCB("compute");
			return new Integer[] {1};
		}

		@Override
		protected void onPostExecute(Integer[] result) {
			//(Vibrator) getSystemService(Context.VIBRATOR_SERVICE).vibrate(350);
			_runStopMenuItem.setTitle(R.string.menu_run);
			//reset.setEnabled(true);
			//loading.dismiss();
			_compute = false;
			super.onPostExecute(result);
		}
    	
    }
	public void onRequestRender() {
		_modelFragment.requestRender();
	}
	private final Handler mainHandler = new Handler(){
    	public void handleMessage(android.os.Message msg) {
    		switch (msg.what) {
			case 0: // we get a message from gmsh library
				//String message =(String) msg.obj;
				//errors.add(message);
				//showError();
				break;
			case 1: // request render from gmsh library
				if(_modelFragment != null) _modelFragment.requestRender();
				if(_optionsFragment != null) _optionsFragment.refresh();
				break;
			case 2: // we get a message for loading
				/*String loadingMessage =(String) msg.obj;
				loading.setMessage(loadingMessage);*/
				break;
			case 3: // we get a progress for loading
				//loading.setProgress(msg.arg1);
				break;
			default:
				break;
			}
    	};
    };
}
