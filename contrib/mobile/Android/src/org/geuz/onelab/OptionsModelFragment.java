package org.geuz.onelab;

import java.util.ArrayList;
import java.util.List;

import android.app.Fragment;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

public class OptionsModelFragment extends Fragment{
	private Gmsh _gmsh;
	private SeparatedListView _listView;
	private List<Parameter> params = new ArrayList<Parameter>();
	
	public static OptionsModelFragment newInstance(Gmsh g) {
		OptionsModelFragment fragment = new OptionsModelFragment();
		Bundle bundle = new Bundle();
		bundle.putParcelable("Gmsh", g);
		fragment.setArguments(bundle);
        return fragment;
	}
	
	public OptionsModelFragment() {
		super();
	}
	
	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		_gmsh = getArguments().getParcelable("Gmsh");
	}
	
	@Override
	public View onCreateView(LayoutInflater inflater, ViewGroup container,
			Bundle savedInstanceState) {
		params.clear();
		_listView = (SeparatedListView)inflater.inflate(R.layout.fragment_options_display, container, false);
		_listView.setDividerHeight(0);
		this.refresh();
		return _listView;
	}
	
	public void refresh() {
		if(_gmsh == null) return;
		this.getAvailableParam();
	}
	
	private void getAvailableParam(){
    	String[] tmp = _gmsh.getParams();
		for(String s : tmp){ // for each parameters in ONEALB
			boolean found = false;
			for(Parameter p : params){ // for each parameters
				if(s.split("\n")[2].equals(p.getName())){ // the parameter already exist, just refresh it
					if(p.getType().equals("ParameterNumber"))
						((ParameterNumber)p).fromString(s);
					else if(p.getType().equals("ParameterString"))
						((ParameterString)p).fromString(s);
					found = true;
					break;
				}
			}
			if(found) continue;
			// add new parameter
			if(s.split("\n")[1].equals("number")){
				final ParameterNumber mParam = new ParameterNumber(_listView.getContext(), _gmsh, mCallback, "");
				if(mParam.fromString(s) == -1) continue;
				params.add(mParam);
				if(_listView != null)
					_listView.addItem(mParam.getName().split("/")[0].equals("Parameters")? mParam.getName().split("/")[0] + " > " + mParam.getName().split("/")[1]: mParam.getName().split("/")[0], mParam.getView());
			}
			else if(s.split("\n")[1].equals("string")){
				ParameterString mParam = new ParameterString(_listView.getContext(), _gmsh, mCallback, "");
				if(mParam.fromString(s) != -1){
					params.add(mParam);
					if(_listView != null)
						_listView.addItem(mParam.getName().split("/")[0], mParam.getView());
				}
			}
		}
    }
	private OnOptionRequestRender mCallback;
	public interface OnOptionRequestRender {
		public void onRequestRender();
	}
}
