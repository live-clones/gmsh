package org.geuz.onelab;

import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.zip.ZipEntry;
import java.util.zip.ZipInputStream;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
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
        Intent oldIntent = this.getIntent();
        if(oldIntent != null && oldIntent.getAction() != null && oldIntent.getAction().equals(Intent.ACTION_VIEW)){
            newIntent = new Intent(SplashScreen.this, MainActivity.class);
            newIntent.setAction(oldIntent.getAction());
            newIntent.setData(oldIntent.getData());
        }
        else
            newIntent = new Intent(SplashScreen.this, ModelList.class);
	SharedPreferences sharedPref = getSharedPreferences(getPackageName(), Context.MODE_PRIVATE);
	int codev = 0;
	try {
		codev = getPackageManager().getPackageInfo(getPackageName(), 0).versionCode;
	} catch (android.content.pm.PackageManager.NameNotFoundException e) {}
	int modelsv = sharedPref.getInt("OnelabModelsVersion", 0);
	if(modelsv == 0 || modelsv != codev) {
		Log.d("Models", "Updating models to version "+codev);
		SharedPreferences.Editor editor = sharedPref.edit();
		editor.putInt("OnelabModelsVersion", codev);
		editor.commit();
		loadNative();
	}
	else Log.d("Models", "Leaving models as-is (version "+modelsv+")");
        final Message msg = new Message();
        msg.what = STOPSPLASH;
        handler.sendMessageDelayed(msg, SPLASHTIME);
    }

    /**
     * Load file from res/raw/ directory to the files directory of the application.
     */
    private void loadNative()
    {
    	try {
            ZipInputStream zipStream = new ZipInputStream(new BufferedInputStream(getResources().openRawResource(R.raw.models)));
            ZipEntry entry;
            while ((entry = zipStream.getNextEntry()) != null) {
                String name = entry.getName();
                FileOutputStream outputStream;
                if(name.charAt(name.length()-1) == '/') {
                    continue;
                }
                else if(name.lastIndexOf("/") > 0) {
                    File document = this.getFilesDir();
                    File currentDirectory = new File(document,name.substring(0, name.lastIndexOf("/")));
                    currentDirectory.mkdir();
                    File currentFile = new File(currentDirectory, name.substring(name.lastIndexOf("/")+1));
                    outputStream = new FileOutputStream(currentFile);
                }
                else {
                    outputStream = openFileOutput(name, Context.MODE_PRIVATE);
                }
                byte[] buffer = new byte[2048];
                for (int i = zipStream.read(buffer, 0, buffer.length); i > 0;i = zipStream.read(buffer, 0, buffer.length))
                    outputStream.write(buffer,0,i);
            }
            zipStream.close();
        } catch (IOException e1) {
            e1.printStackTrace();
        }
    }
}
