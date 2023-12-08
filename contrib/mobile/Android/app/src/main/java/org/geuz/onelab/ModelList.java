package org.geuz.onelab;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;

import org.xmlpull.v1.XmlPullParser;
import org.xmlpull.v1.XmlPullParserException;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.ActivityNotFoundException;
import android.content.DialogInterface;
import android.content.Intent;
import android.database.Cursor;
import android.graphics.Color;
import android.net.Uri;
import android.os.Bundle;
import android.provider.MediaStore;
import android.util.Xml;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.LinearLayout;
import android.widget.ListView;
import android.widget.Toast;
import android.util.Log;
import android.os.Environment;

public class ModelList extends Activity {
  private ModelArrayAdapter _modelArrayAdapter;

  private void deleteRecursive(File fileOrDirectory)
  {
    if(fileOrDirectory.isDirectory()) {
      for(File child : fileOrDirectory.listFiles()) deleteRecursive(child);
    }
    fileOrDirectory.delete();
  }

  private void copyFile(File src, File dst) throws IOException
  {
    FileInputStream in = new FileInputStream(src);
    FileOutputStream out = new FileOutputStream(dst);
    byte[] buf = new byte[1024];
    int len;
    while((len = in.read(buf)) > 0) { out.write(buf, 0, len); }
    in.close();
    out.close();
  }

  @Override protected void onCreate(Bundle savedInstanceState)
  {
    super.onCreate(savedInstanceState);

    _modelArrayAdapter = new ModelArrayAdapter(this);
    try {
      this.getModels();
    } catch(XmlPullParserException e) {
      e.printStackTrace();
    } catch(IOException e) {
      e.printStackTrace();
    }

    LinearLayout layout = new LinearLayout(this);
    layout.setOrientation(LinearLayout.VERTICAL);
    ListView list = new ListView(this);
    list.setAdapter(_modelArrayAdapter);
    list.setOnItemClickListener(new AdapterView.OnItemClickListener() {
      public void onItemClick(AdapterView<?> parent, View view, int position,
                              long id)
      {
        Model m = _modelArrayAdapter.getModel(position);
        Intent intent = new Intent(ModelList.this, MainActivity.class);
        intent.putExtra("file", m.getFile().toString());
        intent.putExtra("name", m.getName());
        startActivity(intent);
      }
    });
    list.setOnItemLongClickListener(new AdapterView.OnItemLongClickListener() {
      public boolean onItemLongClick(AdapterView<?> parent, View view,
                                     int position, long id)
      {
        final Model m = _modelArrayAdapter.getModel(position);
        CharSequence[] actions;
        if(m.getUrl() != null) {
          actions = new CharSequence[6];
          actions[0] = "Open";
          actions[1] = "Remove";
          actions[2] = "Clear results";
          actions[3] = "Edit model files";
          actions[4] = "Email model files";
          actions[5] = "Visit model website";
        }
        else {
          actions = new CharSequence[5];
          actions[0] = "Open";
          actions[1] = "Remove";
          actions[2] = "Clear results";
          actions[3] = "Edit model files";
          actions[4] = "Email model files";
        }
        final AdapterView<?> p = parent;
        AlertDialog.Builder builder = new AlertDialog.Builder(p.getContext());
        builder.setTitle(m.getName());
        builder.setItems(actions, new DialogInterface.OnClickListener() {
          public void onClick(DialogInterface dialog, int position)
          {
            switch(position) {
            case 0: {
              Intent intent = new Intent(ModelList.this, MainActivity.class);
              intent.putExtra("file", m.getFile().toString());
              intent.putExtra("name", m.getName());
              startActivity(intent);
            } break;
            case 1:
              deleteRecursive(m.getFile().getParentFile());
              _modelArrayAdapter.reset();
              try {
                getModels();
              } catch(XmlPullParserException e) {
                e.printStackTrace();
              } catch(IOException e) {
                e.printStackTrace();
              }
              break;
            case 2: {
              File folder = m.getFile().getParentFile();
              File[] files = folder.listFiles();
              for(int i = 0; i < files.length; i++) {
                if(files[i].isFile()) {
                  String filenameArray[] = files[i].getName().split("\\.");
                  String extension = filenameArray[filenameArray.length - 1];
                  if(extension.equalsIgnoreCase("msh") ||
                     extension.equalsIgnoreCase("pre") ||
                     extension.equalsIgnoreCase("res") ||
                     extension.equalsIgnoreCase("pos")) {
                    deleteRecursive(files[i]);
                  }
                }
              }
            } break;
            case 3: {
              AlertDialog.Builder builder =
                new AlertDialog.Builder(p.getContext());
              builder.setTitle("Edit model files");
              File folder = m.getFile().getParentFile();
              File[] files = folder.listFiles();
              ArrayList<String> selection = new ArrayList<String>();
              for(int i = 0; i < files.length; i++) {
                if(files[i].isFile()) {
                  String filenameArray[] = files[i].getName().split("\\.");
                  String extension = filenameArray[filenameArray.length - 1];
                  if(extension.equalsIgnoreCase("txt") ||
                     extension.equalsIgnoreCase("geo") ||
                     extension.equalsIgnoreCase("pro") ||
                     extension.equalsIgnoreCase("dat")) {
                    selection.add(files[i].getName());
                  }
                }
              }
              final String[] names = new String[selection.size()];
              for(int i = 0; i < selection.size(); i++)
                names[i] = selection.get(i);
              builder.setItems(names, new DialogInterface.OnClickListener() {
                public void onClick(DialogInterface dialog, int position)
                {
                  Intent intent =
                    new Intent(ModelList.this, AboutActivity.class);
                  File folder = m.getFile().getParentFile();
                  String file = folder + "/" + names[position];
                  intent.putExtra("file", file);
                  intent.putExtra("name", names[position]);
                  startActivity(intent);
                }
              });
              AlertDialog alert = builder.create();
              alert.show();
            } break;
            case 4: {
              Intent emailIntent = new Intent(Intent.ACTION_SEND_MULTIPLE);
              emailIntent.setType("vnd.android.cursor.dir/email");
              File folder = m.getFile().getParentFile();
              File[] files = folder.listFiles();
              emailIntent.putExtra(Intent.EXTRA_SUBJECT,
                                   folder + "/" + files[0].getName());
              ArrayList<Uri> copies = new ArrayList<Uri>();
              for(int i = 0; i < files.length; i++) {
                if(files[i].isFile()) {
                  // need to copy as we cannot attach files directly from
                  // the app data dir
                  File copy = new File(
                    Environment.getExternalStorageDirectory().getAbsolutePath(),
                    files[i].getName());
                  try {
                    copyFile(files[i], copy);
                  } catch(IOException e) {
                  }
                  // FIXME: Starting with Nougat (api 24+) this is not allowed
                  // anymore and it throws a android.os.FileUriExposedException
                  //
                  // https://proandroiddev.com/sharing-files-though-intents-are-you-ready-for-nougat-70f7e9294a0b
                  try {
                    copies.add(Uri.fromFile(copy));
                  } catch(Exception e) {
                  }
                }
              }
              emailIntent.putExtra(Intent.EXTRA_STREAM, copies);
              startActivity(
                Intent.createChooser(emailIntent, "Share model files..."));
            } break;
            case 5: {
              Intent browserIntent = new Intent(Intent.ACTION_VIEW, m.getUrl());
              startActivity(browserIntent);
            } break;
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

  @Override public boolean onCreateOptionsMenu(Menu menu)
  {
    MenuItem help = menu.add("Help");
    help.setShowAsAction(MenuItem.SHOW_AS_ACTION_IF_ROOM);
    MenuItem about = menu.add("About");
    about.setShowAsAction(MenuItem.SHOW_AS_ACTION_IF_ROOM);
    return super.onCreateOptionsMenu(menu);
  }

  @Override public boolean onMenuItemSelected(int featureId, MenuItem item)
  {
    if(item.getTitle().equals("About")) {
      Intent intent = new Intent(ModelList.this, AboutActivity.class);
      startActivity(intent);
    }
    else if(item.getTitle().equals("Help")) {
      Intent intent = new Intent(ModelList.this, AboutActivity.class);
      intent.putExtra("file", "Help");
      intent.putExtra("name", "Help");
      startActivity(intent);
    }
    return super.onMenuItemSelected(featureId, item);
  }

  @Override
  protected void onActivityResult(int requestCode, int resultCode, Intent data)
  {
    super.onActivityResult(requestCode, resultCode, data);
    if(resultCode == RESULT_CANCELED) return;
    switch(requestCode) {
    case 1:
      Uri uri = data.getData();
      String[] projection = {MediaStore.Images.Media.DATA};
      Cursor cursor = managedQuery(uri, projection, null, null, null);
      int column_index =
        cursor.getColumnIndexOrThrow(MediaStore.Images.Media.DATA);
      cursor.moveToFirst();
      Intent intent = new Intent(ModelList.this, MainActivity.class);
      intent.putExtra("file", cursor.getString(column_index));
      intent.putExtra("name", "None");
      startActivity(intent);
      break;
    }
  }

  private void getModels() throws XmlPullParserException, IOException
  {
    File document = this.getFilesDir();
    File files[] = document.listFiles();
    for(int i = 0; i < files.length; i++) {
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
          while(parser.next() != XmlPullParser.END_TAG) {
            if(parser.getEventType() != XmlPullParser.START_TAG) continue;
            String tagName = parser.getName();
            if(tagName.equals("model"))
              readModel(parser, files[i].toString());
            else
              skipTag(parser);
          }
        } finally {
          in.close();
        }
      }
    }
    _modelArrayAdapter.sortByName();
  }
  private void readModel(XmlPullParser parser, String dir)
    throws XmlPullParserException, IOException
  {
    parser.require(XmlPullParser.START_TAG, null, "model");
    String title = null;
    String summary = null;
    String file = null;
    String bitmap = null;
    String url = null;
    while(parser.next() != XmlPullParser.END_TAG) {
      if(parser.getEventType() != XmlPullParser.START_TAG) continue;
      String name = parser.getName();
      if(name.equals("title")) {
        if(parser.next() == XmlPullParser.TEXT) {
          title = parser.getText();
          parser.nextTag();
        }
      }
      else if(name.equals("summary")) {
        if(parser.next() == XmlPullParser.TEXT) {
          summary = parser.getText();
          parser.nextTag();
        }
      }
      else if(name.equals("file")) {
        // String relType = parser.getAttributeValue(null, "type");
        if(parser.next() == XmlPullParser.TEXT) {
          file = parser.getText();
          parser.nextTag();
        }
      }
      else if(name.equals("preview")) {
        if(parser.next() == XmlPullParser.TEXT) {
          bitmap = parser.getText();
          parser.nextTag();
        }
      }
      else if(name.equals("url")) {
        if(parser.next() == XmlPullParser.TEXT) {
          url = parser.getText();
          parser.nextTag();
        }
      }
      else {
        skipTag(parser);
      }
    }
    if(title == null || file == null) return;
    Model newModel = new Model(title, summary, new File(dir + "/" + file));
    if(bitmap != null) newModel.setBitmap(new File(dir + "/" + bitmap));
    if(url != null) newModel.setUrl(Uri.parse(url));
    _modelArrayAdapter.add(newModel);
  }
  private void skipTag(XmlPullParser parser)
    throws XmlPullParserException, IOException
  {
    if(parser.getEventType() != XmlPullParser.START_TAG) {
      throw new IllegalStateException();
    }
    int depth = 1;
    while(depth != 0) {
      switch(parser.next()) {
      case XmlPullParser.END_TAG: depth--; break;
      case XmlPullParser.START_TAG: depth++; break;
      }
    }
  }
}
