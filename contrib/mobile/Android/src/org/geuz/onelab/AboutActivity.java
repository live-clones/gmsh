package org.geuz.onelab;

import java.lang.String;

import android.app.Activity;
import android.webkit.WebView;

public class AboutActivity extends Activity{

	protected void onCreate(android.os.Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
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
		aboutOnelab += "<p>Copyright (C) 2014<br>Maxime Graulich and Christophe Geuzaine, University of Li&egrave;ge</p>";
		aboutOnelab += "<p>Visit <a href=\"http://onelab.info/\">http://onelab.info/</a> for more information</p>";
		webview.loadDataWithBaseURL("", aboutOnelab + aboutGmsh + aboutGetDP, "text/html", "UTF-8", "");
		setContentView(webview);
	}

}
