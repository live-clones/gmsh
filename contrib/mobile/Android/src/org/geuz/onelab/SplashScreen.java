package org.geuz.onelab;

import android.app.Activity;
import android.content.Intent;
import android.os.Handler;
import android.os.Message;

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
		final Message msg = new Message();
        msg.what = STOPSPLASH;
        handler.sendMessageDelayed(msg, SPLASHTIME);
	};
}
