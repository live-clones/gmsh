package org.geuz.onelab;

import android.app.Activity;
import android.os.Bundle;
import android.view.MenuItem;

public class OptionsActivity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_fragment);
		Bundle extra = getIntent().getExtras();
		Gmsh gmsh = extra.getParcelable("Gmsh");
		getActionBar().setDisplayHomeAsUpEnabled(true);
		getActionBar().setTitle(R.string.title_activity_options);
		OptionsFragment optionsFragment = OptionsFragment.newInstance(gmsh);
		getFragmentManager().beginTransaction().add(R.id.model_fragment, optionsFragment).commit();
	}

	@Override
	public boolean onMenuItemSelected(int featureId, MenuItem item) {
		if(item.getItemId() == android.R.id.home)
			this.finish();
		return super.onMenuItemSelected(featureId, item);
	}
}
