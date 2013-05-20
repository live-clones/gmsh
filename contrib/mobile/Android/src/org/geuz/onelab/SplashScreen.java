package org.geuz.onelab;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.lang.reflect.Field;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.os.Handler;
import android.os.Message;
import android.util.Log;

public class SplashScreen extends Activity{
	private static final int SPLASHTIME = 1000; // duration for the splash screen in milliseconds
	
	private static final int STOPSPLASH = 0;
	private static final int EXITAPP = 1;
	
	private Intent newIntent;
	
	private final Handler handler = new Handler()
	{
		public void handleMessage(Message msg) {
			switch (msg.what) {
			case STOPSPLASH:
				startActivity(newIntent);
				finish();
				break;
			case EXITAPP:
				finish();
				break;
			default:
				break;
			}
		};
	};
	
	protected void onCreate(android.os.Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.splash);
		newIntent = new Intent(SplashScreen.this, MainActivity.class);
		Intent oldIntent = this.getIntent();
		if(oldIntent != null && oldIntent.getAction() != null && oldIntent.getAction().equals(Intent.ACTION_VIEW)){
			newIntent.setAction(oldIntent.getAction());
			newIntent.setData(oldIntent.getData());
		}
		loadNative();
		final Message msg = new Message();
        msg.what = STOPSPLASH;
        handler.sendMessageDelayed(msg, SPLASHTIME);
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
}
