package org.geuz.onelab;

import org.geuz.onelab.Gmsh;

import android.os.Bundle;
import android.os.Parcelable;
import android.app.Fragment;
import android.content.Intent;
import android.graphics.Color;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.ViewGroup.LayoutParams;
import android.widget.AbsListView;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.LinearLayout;

public class OptionsDisplayFragment extends Fragment {
  private Gmsh _gmsh;
  private SeparatedListView _listView;

  public static OptionsDisplayFragment newInstance(Gmsh g)
  {
    OptionsDisplayFragment fragment = new OptionsDisplayFragment();
    Bundle bundle = new Bundle();
    bundle.putParcelable("Gmsh", g);
    fragment.setArguments(bundle);
    return fragment;
  }

  public OptionsDisplayFragment() { super(); }

  @Override public void onCreate(Bundle savedInstanceState)
  {
    super.onCreate(savedInstanceState);
    _gmsh = getArguments().getParcelable("Gmsh");
  }

  @Override
  public View onCreateView(LayoutInflater inflater, final ViewGroup container,
                           Bundle savedInstanceState)
  {
    _listView = (SeparatedListView)inflater.inflate(
      R.layout.fragment_options_display, container, false);
    CheckBox showGeomPoints = new CheckBox(_listView.getContext());
    showGeomPoints.setText("Show geometry points");
    showGeomPoints.setChecked(_gmsh.getDoubleOption("Geometry", "Points", 0) >
                              0.);
    showGeomPoints.setOnCheckedChangeListener(
      new CompoundButton.OnCheckedChangeListener() {
        public void onCheckedChanged(CompoundButton buttonView,
                                     boolean isChecked)
        {
          _gmsh.setDoubleOption("Geometry", "Points", (isChecked) ? 1. : 0., 0);
          if(mListener != null) mListener.OnModelOptionsChanged();
        }
      });
    _listView.addItem("Display Options", showGeomPoints);
    CheckBox showGeomLines = new CheckBox(_listView.getContext());
    showGeomLines.setText("Show geometry lines");
    showGeomLines.setChecked(_gmsh.getDoubleOption("Geometry", "Lines", 0) >
                             0.);
    showGeomLines.setOnCheckedChangeListener(
      new CompoundButton.OnCheckedChangeListener() {
        public void onCheckedChanged(CompoundButton buttonView,
                                     boolean isChecked)
        {
          _gmsh.setDoubleOption("Geometry", "Lines", (isChecked) ? 1. : 0., 0);
          if(mListener != null) mListener.OnModelOptionsChanged();
        }
      });
    _listView.addItem("Display Options", showGeomLines);
    CheckBox showMeshSurfaceEdges = new CheckBox(_listView.getContext());
    showMeshSurfaceEdges.setText("Show mesh surface edges");
    showMeshSurfaceEdges.setChecked(
      _gmsh.getDoubleOption("Mesh", "SurfaceEdges", 0) > 0.);
    showMeshSurfaceEdges.setOnCheckedChangeListener(
      new CompoundButton.OnCheckedChangeListener() {
        public void onCheckedChanged(CompoundButton buttonView,
                                     boolean isChecked)
        {
          _gmsh.setDoubleOption("Mesh", "SurfaceEdges", (isChecked) ? 1. : 0.,
                                0);
          if(mListener != null) mListener.OnModelOptionsChanged();
        }
      });
    _listView.addItem("Display Options", showMeshSurfaceEdges);
    CheckBox showMeshVolumesEdges = new CheckBox(_listView.getContext());
    showMeshVolumesEdges.setText("Show mesh volume edges");
    showMeshVolumesEdges.setChecked(
      _gmsh.getDoubleOption("Mesh", "VolumeEdges", 0) > 0.);
    showMeshVolumesEdges.setOnCheckedChangeListener(
      new CompoundButton.OnCheckedChangeListener() {
        public void onCheckedChanged(CompoundButton buttonView,
                                     boolean isChecked)
        {
          _gmsh.setDoubleOption("Mesh", "VolumeEdges", (isChecked) ? 1. : 0.,
                                0);
          if(mListener != null) mListener.OnModelOptionsChanged();
        }
      });
    _listView.addItem("Display Options", showMeshVolumesEdges);
    this.refresh();
    return _listView;
  }

  public void refresh()
  {
    if(_gmsh == null) return;
    int nbviews = (int)_gmsh.getDoubleOption("PostProcessing", "NbViews", 0);

    for(int i = 0; i < _listView.itemsCountInSection("Result Options"); i++) {
      View v = (View)_listView.getItemAtPosition(6 + i);
      if(!v.getClass().equals(LinearLayout.class)) continue;
      for(int j = 0; j < ((LinearLayout)v).getChildCount(); j++) {
        View sv = ((LinearLayout)v).getChildAt(j);
        if(sv.getClass().equals(CheckBox.class)) {
          ((CheckBox)sv)
            .setChecked(_gmsh.getDoubleOption("View", "Visible", i) > 0.);
        }
      }
    }
    for(int i = _listView.itemsCountInSection("Result Options"); i < nbviews;
        i++) {
      final int myID = i;
      LinearLayout layout = new LinearLayout(_listView.getContext());
      CheckBox checkbox = new CheckBox(_listView.getContext());
      checkbox.setLayoutParams(new AbsListView.LayoutParams(
        LayoutParams.WRAP_CONTENT, LayoutParams.WRAP_CONTENT));
      checkbox.setText(_gmsh.getStringOption("View", "Name", myID));
      checkbox.setChecked(_gmsh.getDoubleOption("View", "Visible", myID) > 0.);
      checkbox.setOnCheckedChangeListener(
        new CompoundButton.OnCheckedChangeListener() {
          public void onCheckedChanged(CompoundButton buttonView,
                                       boolean isChecked)
          {
            _gmsh.setDoubleOption("View", "Visible", isChecked ? 1. : 0., myID);
            if(mListener != null) mListener.OnModelOptionsChanged();
          }
        });
      Button button = new Button(_listView.getContext());
      button.setText(">");
      button.setOnClickListener(new View.OnClickListener() {
        public void onClick(View v)
        {
          Intent intent =
            new Intent(getActivity(), PostProcessingActivity.class);
          intent.putExtra("Gmsh", (Parcelable)_gmsh);
          intent.putExtra("PView", myID);
          startActivity(intent);
          if(mListener != null) mListener.OnModelOptionsChanged();
        }
      });
      button.setLayoutParams(new AbsListView.LayoutParams(
        LayoutParams.MATCH_PARENT, LayoutParams.WRAP_CONTENT));
      button.setBackgroundColor(Color.TRANSPARENT);
      button.setGravity(Gravity.RIGHT);
      layout.addView(checkbox);
      layout.addView(button);
      _listView.addItem("Result Options", layout);
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
