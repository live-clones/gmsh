package org.geuz.onelab;

import org.geuz.onelab.Gmsh;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.WindowManager;

public class OptionsActivity extends Activity {
  boolean _compute;

  @Override protected void onCreate(Bundle savedInstanceState)
  {
    super.onCreate(savedInstanceState);
    getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,
                         WindowManager.LayoutParams.FLAG_FULLSCREEN);
    setContentView(R.layout.activity_fragment);
    Bundle extra = getIntent().getExtras();
    Gmsh gmsh = extra.getParcelable("Gmsh");
    _compute = extra.getBoolean("Compute", false);
    getActionBar().setDisplayHomeAsUpEnabled(true);
    getActionBar().setTitle(R.string.title_activity_options);
    OptionsFragment optionsFragment = OptionsFragment.newInstance(gmsh);
    getFragmentManager()
      .beginTransaction()
      .replace(R.id.model_fragment, optionsFragment)
      .commit();
  }

  @Override public boolean onCreateOptionsMenu(Menu menu)
  {
    if(_compute) return super.onCreateOptionsMenu(menu);
    MenuItem runStopMenuItem = menu.add(R.string.menu_run);
    runStopMenuItem.setShowAsAction(MenuItem.SHOW_AS_ACTION_ALWAYS);
    return super.onCreateOptionsMenu(menu);
  }

  @Override public boolean onMenuItemSelected(int featureId, MenuItem item)
  {
    if(item.getTitle().equals(getString(R.string.menu_run))) {
      Intent returnIntent = new Intent();
      returnIntent.putExtra("Compute", true);
      this.setResult(RESULT_OK, returnIntent);
      this.finish();
    }
    else if(item.getItemId() == android.R.id.home) {
      Intent returnIntent = new Intent();
      this.setResult(RESULT_CANCELED, returnIntent);
      this.finish();
    }
    return super.onMenuItemSelected(featureId, item);
  }
}
