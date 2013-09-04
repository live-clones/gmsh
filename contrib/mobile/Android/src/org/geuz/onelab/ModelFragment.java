package org.geuz.onelab;

import android.app.Fragment;
import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.LinearLayout;
import android.widget.RelativeLayout;
import android.widget.TextView;

public class ModelFragment extends Fragment{

	Gmsh _gmsh;
	mGLSurfaceView _glView;
	TextView _progress;
	
	public static ModelFragment newInstance(Gmsh g) {
		ModelFragment fragment = new ModelFragment();
		Bundle bundle = new Bundle();
		bundle.putParcelable("Gmsh", g);
		fragment.setArguments(bundle);
        return fragment;
    }
	
	public ModelFragment() {
	}

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		_gmsh = getArguments().getParcelable("Gmsh");
	}

	@Override
	public View onCreateView(LayoutInflater inflater, ViewGroup container,
			Bundle savedInstanceState) {
		View rootView = inflater.inflate(R.layout.fragment_model, container, false);
		RelativeLayout glViewLayout = (RelativeLayout)rootView.findViewById(R.id.glViewLayout);
		GLESRender renderer = new GLESRender(_gmsh);
		_glView = new mGLSurfaceView(glViewLayout.getContext(), renderer);
		_glView.setEGLContextClientVersion(1);
		_glView.setRenderer(renderer);
		_glView.setRenderMode(GLSurfaceView.RENDERMODE_WHEN_DIRTY);
		_glView.requestRender();
		glViewLayout.addView(_glView);
		_progress = new TextView(container.getContext());
		_progress.setAlpha(0);
		RelativeLayout.LayoutParams layoutParams = new RelativeLayout.LayoutParams(
			    RelativeLayout.LayoutParams.WRAP_CONTENT, 
			    RelativeLayout.LayoutParams.WRAP_CONTENT);
		layoutParams.addRule(RelativeLayout.ALIGN_PARENT_BOTTOM);
		_progress.setPadding(10, 0, 10, 10);
		_progress.setLayoutParams(layoutParams);
		glViewLayout.addView(_progress);
		return rootView;
	}
	public void showProgress(String progress) {
		_progress.setAlpha(1);
		_progress.setText(progress);
	}
	public void hideProgress() {
		_progress.setAlpha(0);
		_progress.setText("");
	}
	public void requestRender() {
		_glView.requestRender();
	}
}
