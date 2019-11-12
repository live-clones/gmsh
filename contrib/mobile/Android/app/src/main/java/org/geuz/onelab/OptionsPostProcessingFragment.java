package org.geuz.onelab;

import org.geuz.onelab.Gmsh;

import java.util.ArrayList;
import java.lang.Math;

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

public class OptionsPostProcessingFragment extends Fragment {
  private Gmsh _gmsh;
  private int _pview;

  public static OptionsPostProcessingFragment newInstance(Gmsh g, int p)
  {
    OptionsPostProcessingFragment fragment =
      new OptionsPostProcessingFragment();
    Bundle bundle = new Bundle();
    bundle.putParcelable("Gmsh", g);
    bundle.putInt("PView", p);
    fragment.setArguments(bundle);
    return fragment;
  }

  private OptionsPostProcessingFragment() { super(); }

  @Override public void onCreate(Bundle savedInstanceState)
  {
    super.onCreate(savedInstanceState);
    _gmsh = getArguments().getParcelable("Gmsh");
    _pview = getArguments().getInt("PView");
  }

  @Override
  public View onCreateView(LayoutInflater inflater, ViewGroup container,
                           Bundle savedInstanceState)
  {
    getActivity().getActionBar().setTitle(
      _gmsh.getStringOption("View", "Name", _pview));
    LinearLayout layout = (LinearLayout)inflater.inflate(
      R.layout.fragment_postprocessing, container, false);
    final Spinner intervalsType =
      (Spinner)layout.findViewById(R.id.intervals_type);
    intervalsType.setEnabled(_gmsh.getDoubleOption("View", "Visible", _pview) >
                             0.);
    ArrayList<String> choices;
    ArrayAdapter<String> adapter;
    choices = new ArrayList<String>();
    choices.add("Iso-values");
    choices.add("Continous map");
    choices.add("Filled iso-values");
    adapter = new ArrayAdapter<String>(
      container.getContext(), android.R.layout.simple_spinner_dropdown_item,
      choices);
    adapter.setDropDownViewResource(
      android.R.layout.simple_spinner_dropdown_item);
    intervalsType.setAdapter(adapter);
    intervalsType.setSelection(
      (int)_gmsh.getDoubleOption("View", "IntervalsType", _pview) - 1);
    intervalsType.setOnItemSelectedListener(
      new AdapterView.OnItemSelectedListener() {
        public void onItemSelected(AdapterView<?> parent, View view, int pos,
                                   long id)
        {
          _gmsh.setDoubleOption("View", "IntervalsType", pos + 1, _pview);
          // TODO glView.requestRender();
        }
        // Unused Auto-generated method stub
        public void onNothingSelected(AdapterView<?> arg0) {}
      });

    final SeekBar intervals = (SeekBar)layout.findViewById(R.id.intervals);
    intervals.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
      public void onStopTrackingTouch(SeekBar seekBar)
      {
        double d = seekBar.getProgress();
        if(d < 1.) d = 1.;
        _gmsh.setDoubleOption("View", "NbIso", d, _pview);
      }
      // UNUSED Auto-generated method stub
      public void onStartTrackingTouch(SeekBar seekBar) {}
      // UNUSED Auto-generated method stub
      public void onProgressChanged(SeekBar seekBar, int progress,
                                    boolean fromUser)
      {
      }
    });
    intervals.setProgress((int)_gmsh.getDoubleOption("View", "NbIso", _pview));

    final SeekBar raiseZ = (SeekBar)layout.findViewById(R.id.raisez);
    raiseZ.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
      public void onStopTrackingTouch(SeekBar seekBar)
      {
        double maxval =
          Math.max(Math.abs(_gmsh.getDoubleOption("View", "Min", _pview)),
                   Math.abs(_gmsh.getDoubleOption("View", "Max", _pview)));
        if(maxval == 0.) maxval = 1.;
        double val2 =
          2. * _gmsh.getDoubleOption("General", "BoundingBoxSize", 0) / maxval;
        // map [0,100] to [-val2,val2]
        double d = 2 * val2 * (seekBar.getProgress() / 100. - 0.5);
        _gmsh.setDoubleOption("View", "RaiseZ", d, _pview);
      }
      // UNUSED Auto-generated method stub
      public void onStartTrackingTouch(SeekBar seekBar) {}
      // UNUSED Auto-generated method stub
      public void onProgressChanged(SeekBar seekBar, int progress,
                                    boolean fromUser)
      {
      }
    });
    double maxval =
      Math.max(Math.abs(_gmsh.getDoubleOption("View", "Min", _pview)),
               Math.abs(_gmsh.getDoubleOption("View", "Max", _pview)));
    if(maxval == 0.) maxval = 1.;
    double val2 =
      2. * _gmsh.getDoubleOption("General", "BoundingBoxSize", 0) / maxval;
    // map [-val2,val2] to [0,100]
    double d =
      100. *
      (_gmsh.getDoubleOption("View", "RaiseZ", _pview) / (2 * val2) + 0.5);
    raiseZ.setProgress((int)d);
    return layout;
  }
}
