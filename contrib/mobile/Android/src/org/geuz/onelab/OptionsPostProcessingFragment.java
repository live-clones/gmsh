package org.geuz.onelab;

import java.util.ArrayList;

import android.app.Fragment;
import android.content.Context;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.KeyEvent;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.inputmethod.InputMethodManager;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.SeekBar;
import android.widget.Spinner;

public class OptionsPostProcessingFragment extends Fragment{
	private Gmsh _gmsh;
	private int _pview;
	
	public static OptionsPostProcessingFragment newInstance(Gmsh g, int p) {
		OptionsPostProcessingFragment fragment = new OptionsPostProcessingFragment();
		Bundle bundle = new Bundle();
		bundle.putParcelable("Gmsh", g);
		bundle.putInt("PView", p);
		fragment.setArguments(bundle);
        return fragment;
	}
	
	private OptionsPostProcessingFragment() {
		super();
	}

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		_gmsh = getArguments().getParcelable("Gmsh");
		_pview = getArguments().getInt("PView");
	}
	
	@Override
	public View onCreateView(LayoutInflater inflater, ViewGroup container,
			Bundle savedInstanceState) {
		String[] PViews = _gmsh.getPView();
		String[] infos = PViews[_pview].split("\n");
		getActivity().getActionBar().setTitle(infos[0]);
		LinearLayout layout =  (LinearLayout)inflater.inflate(R.layout.fragment_postprocessing, container, false);
		final Spinner intervalsType = (Spinner)layout.findViewById(R.id.intervals_type);
		final EditText intervals = (EditText)layout.findViewById(R.id.intervals);
		final SeekBar raiseZ = (SeekBar)layout.findViewById(R.id.raisez);
		raiseZ.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
			
			public void onStopTrackingTouch(SeekBar seekBar) {_gmsh.setPView(_pview, -1, -1, -1, seekBar.getProgress());}
			public void onStartTrackingTouch(SeekBar seekBar) {} // UNUSED Auto-generated method stub
			public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) { } // UNUSED Auto-generated method stub
		});
		raiseZ.setProgress(Integer.parseInt(infos[4]));
		intervalsType.setEnabled(infos[2].equals("1"));
		ArrayList<String> choices;
		ArrayAdapter<String> adapter;
		choices = new ArrayList<String>();
		choices.add("Iso-values");
		choices.add("Continous map");
		choices.add("Filled iso-values");
		adapter = new ArrayAdapter<String>(container.getContext(), android.R.layout.simple_spinner_dropdown_item, choices);
		adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
		intervalsType.setAdapter(adapter);
		intervalsType.setSelection(Integer.parseInt(infos[1])-1);
		intervalsType.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
			public void onItemSelected(AdapterView<?> parent, View view, int pos, long id) {
				_gmsh.setPView(_pview, pos+1, -1, -1, -1);
				//TODO glView.requestRender();
				intervals.setEnabled(pos == 0 || pos == 2);
			}
			public void onNothingSelected(AdapterView<?> arg0) {} // Unused Auto-generated method stub
		});
		intervals.setText(infos[3]);
		intervals.setOnKeyListener(new View.OnKeyListener() {
			
			public boolean onKey(View v, int keyCode, KeyEvent event) {
				if(keyCode == KeyEvent.KEYCODE_ENTER){ // hide the keyboard
					InputMethodManager imm = (InputMethodManager)intervals.getContext().getSystemService(Context.INPUT_METHOD_SERVICE);
					imm.hideSoftInputFromWindow(intervals.getWindowToken(), 0);
					return true;
				}
				return false;
			}
		});
		intervals.addTextChangedListener(new TextWatcher() {
			
			public void onTextChanged(CharSequence s, int start, int before, int count) {
				
				int nIso = 1;
				try {
					if(s.length() < 1) nIso = 1;
					else nIso = Integer.parseInt(s.toString());
				}
				catch(NumberFormatException e)
				{
					nIso = 1;
					intervals.setText("");
				}
				if(nIso > 1000) {_gmsh.setPView(_pview, -1, -1, 1000, -1); intervals.setText("1000");}
				else if(nIso > 0) _gmsh.setPView(_pview, -1, -1, nIso, -1);
				else _gmsh.setPView(_pview, -1, -1, 1, -1);
			}
			
			public void beforeTextChanged(CharSequence s, int start, int count, int after) {} // UNUSED Auto-generated method stub
			public void afterTextChanged(Editable s) {} // UNUSED Auto-generated method stub

		});

		return layout;
	}
}
