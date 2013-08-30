package org.geuz.onelab;

import android.app.Fragment;
import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.LinearLayout;

public class ModelFragment extends Fragment{

	Gmsh _gmsh;
	mGLSurfaceView _glView;
	
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
		LinearLayout glViewLayout = (LinearLayout)rootView.findViewById(R.id.glViewLayout);
		GLESRender renderer = new GLESRender(_gmsh);
		_glView = new mGLSurfaceView(glViewLayout.getContext(), renderer);
		_glView.setEGLContextClientVersion(1);
		_glView.setRenderer(renderer);
		_glView.setRenderMode(GLSurfaceView.RENDERMODE_WHEN_DIRTY);
		_glView.requestRender();
		glViewLayout.addView(_glView);
		return rootView;
	}
	
	public void requestRender() {
		_glView.requestRender();
	}
}
