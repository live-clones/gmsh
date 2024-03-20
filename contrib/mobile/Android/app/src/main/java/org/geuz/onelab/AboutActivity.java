package org.geuz.onelab;

import org.geuz.onelab.Gmsh;

import java.lang.String;
import java.io.File;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

import android.app.Activity;
import android.content.Intent;
import android.view.Menu;
import android.view.MenuItem;
import android.webkit.WebView;
import android.webkit.JavascriptInterface;
import android.os.Bundle;

class MyJavaScriptInterface {
  private String _filename;
  public MyJavaScriptInterface(String filename) { _filename = filename; }
  @JavascriptInterface public void myJsCallback(String jsResult)
  {
    File outputFile = new File(_filename);
    try {
      BufferedWriter writer = new BufferedWriter(new FileWriter(outputFile));
      writer.write(jsResult);
      writer.close();
    } catch(IOException e) {
    }
  }
}

public class AboutActivity extends Activity {
  private MenuItem _saveMenuItem;
  private boolean _editingMode;
  private WebView _webview;

  protected void onCreate(android.os.Bundle savedInstanceState)
  {
    super.onCreate(savedInstanceState);
    getActionBar().setDisplayHomeAsUpEnabled(true);

    _webview = new WebView(this);
    _webview.getSettings().setJavaScriptEnabled(true);

    String css =
      "body { background-color: #FFFFFF; color: #252525; margin: 35px 10px 35px 10px; padding: 0; font-family: helvetica,sans-serif; font-size: 1em; }";

    Intent intent = getIntent();
    Bundle extras = intent.getExtras();
    if(extras != null) {
      String name = extras.getString("name");
      getActionBar().setTitle(name);
      if(name.equals("Help")) {
        _editingMode = false;
        _webview.loadDataWithBaseURL(
          "",
          "<html><head><style type=\"text/css\">" + css +
            " h3 { text-align: center; } </style></head><h3>Onelab/Mobile</h3> <h4>Running an existing model</h4> <p> The list of available models appears when you launch the app. Selecting a model will load it. You can then press <b>Run</b> to launch a simulation with the default set of parameters. When available, additional information about a model can be obtained by long-pressing on the model description and selecting <b>Visit model website</b>.</p> <h4>Modifying a model</h4> <p>To run a model with different parameters, press <b>Parameters</b> and modify any of the presets. Then press <b>Run</b> again: all the simulation steps will be performed with the new parameter values. To restore the preset parameters values, press <b>Reset</b>. </p> <p> Advanced users can also directly edit the model input files: long-press on the model description and select <b>Edit model files</b>. </p> <p> To free up space, temporary model files (meshes, solution files) can be removed by long-pressing on the model description and selecting <b>Clear results</b>. </p> <p> To completey remove a model, long-press on the model description and select <b>Remove</b>. </p> <h4>Sharing a model</h4> <p> To share a model by email, long-press on the model description and select <b>Email model files</b>. </p> <h4>Installing a new model</h4> <p> To install a new model: <ol> <li>Put all the model files (.pro, .geo) in a directory, which should also contain a file named <code>infos.xml</code> with the model information: <pre>\n&lt;?xml version=\"1.0\" encoding=\"utf-8\"?&gt;\n&lt;models&gt;\n  &lt;model&gt;\n    &lt;title&gt;Model title&lt;/title&gt;\n    &lt;summary&gt;Model summary&lt;/summary&gt;\n    &lt;file type=\"pro\"&gt;main_pro_file.pro&lt;/file&gt;\n    &lt;preview type=\"png\"&gt;128x128_pixel_screenshot.png&lt;/preview&gt;\n    &lt;url&gt;http://model_website.com&lt;/url&gt;\n  &lt;/model&gt;\n&lt;/models&gt;\n</pre><li>Zip the directory. <li>Open the .zip file on your device, e.g. by copying it on an SD card, through Google Drive or by  emailing it to yourself and opening the attachment; or by putting it  on a web server and downloading the file on the device with Chrome. <li>Refresh the list of models: the new model will be extracted  alongside Onelab/Mobile\'s built-in models.</ol> <p style=\"padding-top: 2em;\">Visit <a href=\"https://onelab.info/\">https://onelab.info/</a> for more information.</p> </body></html>",
          "text/html", "UTF-8", "");
      }
      else {
        _editingMode = true;
        String filename = extras.getString("file");
        MyJavaScriptInterface javaInterface =
          new MyJavaScriptInterface(filename);
        _webview.addJavascriptInterface(javaInterface, "HTMLOUT");
        File file = new File(filename);
        StringBuilder text = new StringBuilder();
        try {
          BufferedReader br = new BufferedReader(new FileReader(file));
          String line;
          while((line = br.readLine()) != null) {
            text.append(line);
            text.append('\n');
          }
          br.close();
        } catch(IOException e) {
        }
        String code = text.toString().replace("<", "&lt;");
        code = code.replace(">", "&gt;");
        String js =
          "!function(a,b){\"function\"==typeof define&&define.amd?define([\"exports\"],b):b(\"undefined\"!=typeof exports?exports:a.microlight={})}(this,function(a){var k,l,m,b=window,c=document,d=\"appendChild\",e=\"test\",g=\"opacity:.\",n=function(a){for(l=c.getElementsByClassName(a||\"microlight\"),k=0;m=l[k++];){var n,o,r,s,t,f=m.textContent,h=0,i=f[0],j=1,p=m.innerHTML=\"\",q=0,u=/(\\d*\\, \\d*\\, \\d*)(, ([.\\d]*))?/g.exec(b.getComputedStyle(m).color);for(\"px rgba(\"+u[1]+\",\",u[3]||1;o=n,n=q<7&&\"\\\\\"==n?1:j;){if(j=i,i=f[++h],s=p.length>1,!j||q>8&&\"\\n\"==j||[/\\S/[e](j),1,1,!/[$\\w]/[e](j),(\"/\"==n||\"\\n\"==n)&&s,\'\"\'==n&&s,\"\'\"==n&&s,f[h-4]+o+n==\"-->\",o+n==\"*/\"][q])for(p&&(m[d](t=c.createElement(\"span\")).setAttribute(\"style\",[\"\",\"font-weight:bold;color:#00c;\",g+6,\"color: #a08;\"+g+8,\"font-style:italic;color: #b00;\"+g+8][q?q<3?2:q>6?4:q>3?3:+/^(If|Else|ElseIf|EndIf|Include|For|EndFor|Include|Macro|Return)$/[e](p):0]),t[d](c.createTextNode(p))),r=q&&q<7?q:r,p=\"\",q=11;![1,/[\\/{}[(\\-+*=<>:;|\\\\.,?!&@~]/[e](j),/[\\])]/[e](j),/[$\\w]/[e](j),\"/\"==j&&r<2&&\"<\"!=n,\'\"\'==j,\"\'\"==j,j+i+f[h+1]+f[h+2]==\"<!--\",j+i==\"/*\",j+i==\"//\",j+i==\"//\"][--q];);p+=j}}};a.reset=n,\"complete\"==c.readyState?n():b.addEventListener(\"load\",function(){n()},0)});";
        _webview.loadDataWithBaseURL(
          "",
          "<html><head><script>" + js +
            "</script></head><body><pre contenteditable=\"true\" class=microlight>" +
            code + "</pre></body></html>",
          "text/html", "UTF-8", "");
      }
    }
    else {
      _editingMode = false;
      String aboutOnelab = "<center><h3>Onelab/Mobile</h3>";
      try {
        aboutOnelab += "Version " + this.getPackageManager()
                                      .getPackageInfo(this.getPackageName(), 0)
                                      .versionName;
      } catch(android.content.pm.PackageManager.NameNotFoundException e) {
      }
      aboutOnelab +=
        "<p>Copyright (C) 2014-2024 Christophe Geuzaine and Maxime Graulich, ";
      aboutOnelab += "University of Li&egrave;ge</p>";
      aboutOnelab +=
        "<p>Visit <a href=\"https://onelab.info/\">https://onelab.info/</a> ";
      aboutOnelab += "for more information</p>";
      aboutOnelab +=
        "<p>&nbsp;</p><p>This version of Onelab/Mobile contains:</p></center>";
      _webview.loadDataWithBaseURL("",
                                   "<html><head><style type=\"text/css\">" +
                                     css + "</style></head><body>" +
                                     aboutOnelab + Gmsh.getAboutGmsh() +
                                     Gmsh.getAboutGetDP() + "</body></html>",
                                   "text/html", "UTF-8", "");
    }
    setContentView(_webview);
  }
  @Override public boolean onCreateOptionsMenu(Menu menu)
  {
    super.onCreateOptionsMenu(menu);
    if(_editingMode) {
      _saveMenuItem = menu.add(R.string.menu_save);
      _saveMenuItem.setShowAsAction(MenuItem.SHOW_AS_ACTION_ALWAYS);
    }
    return true;
  }
  @Override public boolean onMenuItemSelected(int featureId, MenuItem item)
  {
    if(item.getItemId() == android.R.id.home) {
      Intent returnIntent = new Intent();
      this.setResult(RESULT_CANCELED, returnIntent);
      this.finish();
    }
    else if(item.getTitle().equals(getString(R.string.menu_save))) {
      _webview.loadUrl(
        "javascript:( function () { window.HTMLOUT.myJsCallback(document.body.innerText); } ) ()");
      // FIXME: should reload the page to correctly re-highlight
    }
    return super.onMenuItemSelected(featureId, item);
  }
}
