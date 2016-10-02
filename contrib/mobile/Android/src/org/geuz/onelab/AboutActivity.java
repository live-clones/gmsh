package org.geuz.onelab;

import org.geuz.onelab.Gmsh;

import java.lang.String;

import android.app.Activity;
import android.content.Intent;
import android.view.Menu;
import android.view.MenuItem;
import android.webkit.WebView;

public class AboutActivity extends Activity{
  private MenuItem _saveMenuItem;

  protected void onCreate(android.os.Bundle savedInstanceState)
  {
    super.onCreate(savedInstanceState);
    getActionBar().setDisplayHomeAsUpEnabled(true);

    //getActionBar().setTitle("Editing");

    WebView webview = new WebView(this);
    String aboutGmsh = Gmsh.getAboutGmsh();
    String aboutGetDP = Gmsh.getAboutGetDP();
    String aboutOnelab = "<p>&nbsp;</p><center><h3>Onelab/Mobile</h3>";
    try {
      aboutOnelab += "Version " + this.getPackageManager().
        getPackageInfo(this.getPackageName(), 0).versionName;
    }
    catch (android.content.pm.PackageManager.NameNotFoundException e) {
      aboutOnelab += "Version ?.?.?";
    }

    //aboutOnelab += "<pre contenteditable=\"true\"> THIS IS EDITABLE </pre>";

    aboutOnelab += "<p>Copyright (C) 2014-2016 Christophe Geuzaine and Maxime Graulich, ";
    aboutOnelab += "University of Li&egrave;ge</p>";
    aboutOnelab += "<p>Visit <a href=\"http://onelab.info/\">http://onelab.info/</a> ";
    aboutOnelab += "for more information</p>";
    aboutOnelab += "<p>&nbsp;</p><p>This version of Onelab/Mobile contains:</p>";
    webview.loadDataWithBaseURL("", aboutOnelab + aboutGmsh + aboutGetDP,
                                "text/html", "UTF-8", "");
    setContentView(webview);
  }
  @Override
  public boolean onCreateOptionsMenu(Menu menu)
  {
    super.onCreateOptionsMenu(menu);
    //_saveMenuItem = menu.add(R.string.menu_save);
    //_saveMenuItem.setShowAsAction(MenuItem.SHOW_AS_ACTION_ALWAYS);
    return true;
  }
  @Override
  public boolean onMenuItemSelected(int featureId, MenuItem item)
  {
    if(item.getItemId() == android.R.id.home) {
      Intent returnIntent = new Intent();
      this.setResult(RESULT_CANCELED, returnIntent);
      this.finish();
    }
    else if(item.getTitle().equals(getString(R.string.menu_save))){

    }
    return super.onMenuItemSelected(featureId, item);
  }
}
