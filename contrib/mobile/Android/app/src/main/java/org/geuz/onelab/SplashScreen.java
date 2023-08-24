package org.geuz.onelab;

import java.io.InputStream;
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
import android.content.ContentResolver;
import android.os.Handler;
import android.os.Message;
import android.util.Log;

public class SplashScreen extends Activity {
  private final Handler handler = new Handler() {
    public void handleMessage(Message msg)
    {
      Intent i = new Intent(SplashScreen.this, ModelList.class);
      startActivity(i);
      finish();
    };
  };

  protected void onCreate(android.os.Bundle savedInstanceState)
  {
    super.onCreate(savedInstanceState);
    setContentView(R.layout.splash);

    // import built-in models
    SharedPreferences sharedPref =
      getSharedPreferences(getPackageName(), Context.MODE_PRIVATE);
    int codev = 0;
    try {
      codev =
        getPackageManager().getPackageInfo(getPackageName(), 0).versionCode;
    } catch(android.content.pm.PackageManager.NameNotFoundException e) {
    }
    int modelsv = sharedPref.getInt("OnelabModelsVersion", 0);
    if(modelsv == 0 || modelsv != codev) {
      Log.d("Models", "Updating models to version " + codev);
      SharedPreferences.Editor editor = sharedPref.edit();
      editor.putInt("OnelabModelsVersion", codev);
      editor.commit();
      // import built-in models from from res/raw/
      ImportZipArchive(
        new BufferedInputStream(getResources().openRawResource(R.raw.models)));
    }
    else {
      Log.d("Models", "Leaving models as-is (version " + modelsv + ")");
    }

    // import user model
    Intent intent = getIntent();
    String action = intent.getAction();
    if(action != null && action.equals(Intent.ACTION_VIEW)) {
      Log.d("Models", "Importing user model " + intent.getData());
      try {
        ImportZipArchive(
          getContentResolver().openInputStream(intent.getData()));
      } catch(IOException e1) {
        e1.printStackTrace();
      }
    }

    final Message msg = new Message();
    handler.sendMessageDelayed(msg, 500); // 500 milliseconds
  }

  // Uncompress zip archive into the files directory of the application.
  private boolean ImportZipArchive(InputStream stream)
  {
    try {
      String path = this.getFilesDir().getAbsolutePath() + File.separator;
      ZipInputStream zis = new ZipInputStream(stream);
      byte[] buffer = new byte[1024];
      ZipEntry ze;
      while((ze = zis.getNextEntry()) != null) {
        // check for malicious zip files having path traversal characters
        // ("../") - cf. https://support.google.com/faqs/answer/9294009
        File f = new File(path, ze.getName());
        String canonicalPath = f.getCanonicalPath();
        if (!canonicalPath.startsWith(path)) {
          Log.d("Models", "Warning file with path traversal characters? Check this!");
          //Log.d("Models", "Skipping file with path traversal characters");
          //continue;
        }
        String filename = ze.getName();
        if(ze.isDirectory()) {
          File fmd = new File(path + filename);
          fmd.mkdirs();
          continue;
        }
        FileOutputStream fout = new FileOutputStream(path + filename);
        int count;
        while((count = zis.read(buffer)) != -1) {
          fout.write(buffer, 0, count);
        }
        fout.close();
        zis.closeEntry();
      }
      zis.close();
    } catch(IOException e) {
      e.printStackTrace();
      return false;
    }
    return true;
  }
}
