package org.geuz.onelab;

import java.lang.String;

import android.app.Activity;
import android.content.Intent;
import android.view.MenuItem;
import android.webkit.WebView;

public class AboutActivity extends Activity{

	protected void onCreate(android.os.Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		getActionBar().setDisplayHomeAsUpEnabled(true);
		WebView webview = new WebView(this);
		String aboutGmsh = Gmsh.getAboutGmsh();
		String aboutGetDP = Gmsh.getAboutGetDP();
		String aboutOnelab = "<center><h3>Onelab/Mobile</h3>";
		try {
			aboutOnelab += "Version "+this.getPackageManager().getPackageInfo(this.getPackageName(), 0).versionName;
		}
		catch (android.content.pm.PackageManager.NameNotFoundException e) {
			aboutOnelab += "Version ?.?.?";
		}
		aboutOnelab += "<p>Copyright (C) 2014 Christophe Geuzaine and Maxime Graulich, University of Li&egrave;ge</p>";
		aboutOnelab += "<p>Visit <a href=\"http://onelab.info/\">http://onelab.info/</a> for more information</p>";
		aboutOnelab += "<p>This version of Onelab/Mobile contains:</p>";
		webview.loadDataWithBaseURL("", aboutOnelab + aboutGmsh + aboutGetDP, "text/html", "UTF-8", "");
		setContentView(webview);
	}
	@Override
	public boolean onMenuItemSelected(int featureId, MenuItem item) {
		if(item.getItemId() == android.R.id.home) {
			Intent returnIntent = new Intent();
			this.setResult(RESULT_CANCELED, returnIntent);
			this.finish();
		}
		return super.onMenuItemSelected(featureId, item);
	}
}
