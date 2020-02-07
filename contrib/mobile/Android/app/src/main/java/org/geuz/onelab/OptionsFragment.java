package org.geuz.onelab;

import org.geuz.onelab.Gmsh;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.LinearLayout;
import android.app.Fragment;
import android.app.FragmentTransaction;

public class OptionsFragment extends Fragment {
  private Gmsh _gmsh;
  private int _viewN;
  private OptionsDisplayFragment _optionDisplayFragment;
  private OptionsModelFragment _optionModelFragment;

  public static OptionsFragment newInstance(Gmsh g)
  {
    OptionsFragment fragment = new OptionsFragment();
    Bundle bundle = new Bundle();
    bundle.putParcelable("Gmsh", g);
    fragment.setArguments(bundle);
    return fragment;
  }

  public OptionsFragment() {}

  @Override public void onCreate(Bundle savedInstanceState)
  {
    super.onCreate(savedInstanceState);
    _gmsh = getArguments().getParcelable("Gmsh");
    _viewN = 0;
    if(savedInstanceState != null) _viewN = savedInstanceState.getInt("viewN");
  }

  @Override
  public View onCreateView(LayoutInflater inflater, ViewGroup container,
                           Bundle savedInstanceState)
  {
    LinearLayout rootView = (LinearLayout)inflater.inflate(
      R.layout.fragment_options, container, false);
    _optionModelFragment = OptionsModelFragment.newInstance(_gmsh);
    _optionModelFragment.setOnModelOptionsChangedListener(
      new OptionsModelFragment.OnModelOptionsChangedListener() {
        public void OnModelOptionsChanged()
        {
          if(mListener != null) mListener.OnOptionsChanged();
        }
      });
    _optionDisplayFragment = OptionsDisplayFragment.newInstance(_gmsh);
    _optionDisplayFragment.setOnModelOptionsChangedListener(
      new OptionsDisplayFragment.OnModelOptionsChangedListener() {
        public void OnModelOptionsChanged()
        {
          if(mListener != null) mListener.OnOptionsChanged();
        }
      });
    final Button optionModel =
      (Button)rootView.findViewById(R.id.goto_options_model);
    final Button optionDisplay =
      (Button)rootView.findViewById(R.id.goto_options_display);
    if(_viewN == 0) {
      optionDisplay.setEnabled(true);
      optionModel.setEnabled(false);
      getFragmentManager()
        .beginTransaction()
        .replace(R.id.options_fragment, _optionModelFragment)
        .commit();
    }
    else {
      optionDisplay.setEnabled(false);
      optionModel.setEnabled(true);
      getFragmentManager()
        .beginTransaction()
        .replace(R.id.options_fragment, _optionDisplayFragment)
        .commit();
    }
    optionModel.setOnClickListener(new View.OnClickListener() {
      public void onClick(View v)
      {
        optionModel.setEnabled(false);
        optionDisplay.setEnabled(true);
        FragmentTransaction ft = getFragmentManager().beginTransaction();
        ft.replace(R.id.options_fragment, _optionModelFragment);
        ft.setTransition(FragmentTransaction.TRANSIT_FRAGMENT_OPEN);
        ft.commit();
        _viewN = 0;
      }
    });
    optionDisplay.setOnClickListener(new View.OnClickListener() {
      public void onClick(View v)
      {
        optionDisplay.setEnabled(false);
        optionModel.setEnabled(true);
        FragmentTransaction ft = getFragmentManager().beginTransaction();
        ft.replace(R.id.options_fragment, _optionDisplayFragment);
        ft.setTransition(FragmentTransaction.TRANSIT_FRAGMENT_OPEN);
        ft.commit();
        _viewN = 1;
      }
    });
    return rootView;
  }

  @Override public void onSaveInstanceState(Bundle outState)
  {
    super.onSaveInstanceState(outState);
    outState.putInt("viewN", _viewN);
  }

  public void refresh()
  {
    if(_optionDisplayFragment != null) _optionDisplayFragment.refresh();
    if(_optionModelFragment != null) _optionModelFragment.refresh();
  }

  private OnOptionsChangedListener mListener;
  public void setOnOptionsChangedListener(OnOptionsChangedListener listener)
  {
    mListener = listener;
  }
  public interface OnOptionsChangedListener {
    void OnOptionsChanged();
  }
}
