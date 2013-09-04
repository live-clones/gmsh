package org.geuz.onelab;

import android.app.Activity;
import android.os.Bundle;

public class PostProcessingActivity extends Activity{
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_fragment);
		Bundle extra = getIntent().getExtras();
		int id = extra.getInt("PView", 0);
		Gmsh gmsh = extra.getParcelable("Gmsh");
		getActionBar().setDisplayHomeAsUpEnabled(true);
		OptionsPostProcessingFragment optionsFragment = OptionsPostProcessingFragment.newInstance(gmsh, id);
		getFragmentManager().beginTransaction().add(R.id.model_fragment, optionsFragment).commit();
	}
}
