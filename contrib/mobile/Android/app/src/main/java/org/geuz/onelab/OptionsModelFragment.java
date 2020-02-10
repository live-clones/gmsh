package org.geuz.onelab;

import org.geuz.onelab.Gmsh;

import java.util.ArrayList;
import java.util.List;

import android.app.Fragment;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

public class OptionsModelFragment extends Fragment {
  private Gmsh _gmsh;
  private SeparatedListView _listView;
  private List<Parameter> params = new ArrayList<Parameter>();

  public static OptionsModelFragment newInstance(Gmsh g)
  {
    OptionsModelFragment fragment = new OptionsModelFragment();
    Bundle bundle = new Bundle();
    bundle.putParcelable("Gmsh", g);
    fragment.setArguments(bundle);
    return fragment;
  }

  public OptionsModelFragment() { super(); }

  @Override public void onCreate(Bundle savedInstanceState)
  {
    super.onCreate(savedInstanceState);
    _gmsh = getArguments().getParcelable("Gmsh");
  }

  @Override
  public View onCreateView(LayoutInflater inflater, ViewGroup container,
                           Bundle savedInstanceState)
  {
    params.clear();
    _listView = (SeparatedListView)inflater.inflate(
      R.layout.fragment_options_display, container, false);
    _listView.setDividerHeight(0);
    this.refresh();
    return _listView;
  }

  public void refresh()
  {
    if(_gmsh == null) return;
    // TODO temporary, remove must be implemented in listview
    if(_listView != null) {
      _listView.clear();
      params.clear();
    }
    this.getAvailableParam();
    if(_listView != null) _listView.refresh();
  }

  private void getAvailableParam()
  {
    String[] tmp = _gmsh.getParams();
    for(String s : tmp) { // for each parameter in ONEALB
      boolean found = false;
      for(int i = 0; i < params.size(); i++) { // for each parameter in the GUI
        Parameter p = params.get(i);
        if(s.split(Character.toString((char)0x03))[2].equals(p.getName())) {
          // the parameter already exist, just refresh it
          if(p.getType().equals("ParameterNumber")) {
            if(((ParameterNumber)p).fromString(s) == -1) { params.remove(i); }
          }
          else if(p.getType().equals("ParameterString")) {
            if(((ParameterString)p).fromString(s) == -1) params.remove(i);
          }
          found = true;
          break;
        }
      }
      if(found) continue;
      // add new parameter
      if(s.split(Character.toString((char)0x03))[1].equals("number")) {
        final ParameterNumber mParam =
          new ParameterNumber(_listView.getContext(), _gmsh, "");
        if(mParam.fromString(s) == -1) continue;
        mParam.setOnParameterChangedListener(
          new ParameterNumber.OnParameterChangedListener() {
            public void OnParameterChanged()
            {
              if(_gmsh.onelabCB("check") > 0 && mListener != null)
                mListener.OnModelOptionsChanged();
              refresh();
            }
          });
        params.add(mParam);
        if(_listView != null)
          _listView.addItem(mParam.getSectionName(), mParam.getView());
      }
      else if(s.split("|")[1].equals("string")) {
        ParameterString mParam =
          new ParameterString(_listView.getContext(), _gmsh, "");
        if(mParam.fromString(s) != -1) {
          mParam.setOnParameterChangedListener(
            new ParameterString.OnParameterChangedListener() {
              public void OnParameterChanged()
              {
                if(_gmsh.onelabCB("check") > 0 && mListener != null)
                  mListener.OnModelOptionsChanged();
                refresh();
              }
            });
          params.add(mParam);
          if(_listView != null)
            _listView.addItem(mParam.getSectionName(), mParam.getView());
        }
      }
    }
  }
  private OnModelOptionsChangedListener mListener;
  public void
  setOnModelOptionsChangedListener(OnModelOptionsChangedListener listener)
  {
    mListener = listener;
  }
  public interface OnModelOptionsChangedListener {
    void OnModelOptionsChanged();
  }
}
