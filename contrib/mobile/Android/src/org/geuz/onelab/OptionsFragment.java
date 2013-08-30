package org.geuz.onelab;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.LinearLayout;
import android.app.Fragment;
import android.app.FragmentTransaction;

public class OptionsFragment extends Fragment{

	private Gmsh _gmsh;
	private OptionsDisplayFragment _optionDisplayFragment;
	private OptionsModelFragment _optionModelFragment;
	
	public static OptionsFragment newInstance(Gmsh g) {
		OptionsFragment fragment = new OptionsFragment();
		Bundle bundle = new Bundle();
		bundle.putParcelable("Gmsh", g);
		fragment.setArguments(bundle);
        return fragment;
	}
	
	public OptionsFragment() {
	}
	
	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		_gmsh = getArguments().getParcelable("Gmsh");
	}
	
	@Override
	public View onCreateView(LayoutInflater inflater, ViewGroup container,
			Bundle savedInstanceState) {
		LinearLayout rootView = (LinearLayout)inflater.inflate(R.layout.fragment_options, container, false);
		_optionModelFragment = OptionsModelFragment.newInstance(_gmsh);
		getFragmentManager().beginTransaction().add(R.id.options_fragment, _optionModelFragment).commit();
		_optionDisplayFragment = OptionsDisplayFragment.newInstance(_gmsh);
		final Button optionModel = (Button) rootView.findViewById(R.id.goto_options_model);
		final Button optionDisplay = (Button) rootView.findViewById(R.id.goto_options_display);
		optionDisplay.setEnabled(true);
		optionModel.setEnabled(false);
		optionModel.setOnClickListener(new View.OnClickListener() {
			
			public void onClick(View v) {
				optionModel.setEnabled(false);
				optionDisplay.setEnabled(true);
				FragmentTransaction ft = getFragmentManager().beginTransaction();
	            ft.replace(R.id.options_fragment, _optionModelFragment);
	            ft.setTransition(FragmentTransaction.TRANSIT_FRAGMENT_OPEN);
	            ft.commit();
			}
		});
		optionDisplay.setOnClickListener(new View.OnClickListener() {
			
			public void onClick(View v) {
				optionDisplay.setEnabled(false);
				optionModel.setEnabled(true);
				FragmentTransaction ft = getFragmentManager().beginTransaction();
	            ft.replace(R.id.options_fragment, _optionDisplayFragment);
	            ft.setTransition(FragmentTransaction.TRANSIT_FRAGMENT_OPEN);
	            ft.commit();
			}
		});
		return rootView;
	}
	
	public void refresh() {
		if(_optionDisplayFragment != null)_optionDisplayFragment.refresh();
		if(_optionModelFragment != null)_optionModelFragment.refresh();
	}
}
