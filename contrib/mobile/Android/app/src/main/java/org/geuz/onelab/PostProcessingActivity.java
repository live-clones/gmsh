package org.geuz.onelab;

import org.geuz.onelab.Gmsh;

import android.app.Activity;
import android.os.Bundle;
import android.view.MenuItem;
import android.view.WindowManager;

public class PostProcessingActivity extends Activity {
  @Override protected void onCreate(Bundle savedInstanceState)
  {
    super.onCreate(savedInstanceState);
    getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,
                         WindowManager.LayoutParams.FLAG_FULLSCREEN);
    setContentView(R.layout.activity_fragment);
    Bundle extra = getIntent().getExtras();
    int id = extra.getInt("PView", 0);
    Gmsh gmsh = extra.getParcelable("Gmsh");
    getActionBar().setDisplayHomeAsUpEnabled(true);
    OptionsPostProcessingFragment optionsFragment =
      OptionsPostProcessingFragment.newInstance(gmsh, id);
    getFragmentManager()
      .beginTransaction()
      .add(R.id.model_fragment, optionsFragment)
      .commit();
  }

  @Override public boolean onMenuItemSelected(int featureId, MenuItem item)
  {
    if(item.getItemId() == android.R.id.home) this.finish();
    return super.onMenuItemSelected(featureId, item);
  }
}
