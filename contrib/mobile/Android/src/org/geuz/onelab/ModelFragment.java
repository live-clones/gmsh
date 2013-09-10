package org.geuz.onelab;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;

import android.app.Fragment;
import android.graphics.Bitmap;
import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.LinearLayout;
import android.widget.ProgressBar;
import android.widget.RelativeLayout;
import android.widget.TextView;

public class ModelFragment extends Fragment{

	Gmsh _gmsh;
	mGLSurfaceView _glView;
	TextView _progress;
	LinearLayout _progressLayout;
	
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
		_progressLayout = new LinearLayout(container.getContext());
		ProgressBar bar = new ProgressBar(container.getContext());
		bar.setOnClickListener(new View.OnClickListener() {
			public void onClick(View v) {
				_progress.setAlpha((_progress.getAlpha() > 0)? 0 : 1);
			}
		});
		_progressLayout.addView(bar);
		_progress = new TextView(container.getContext());
		_progressLayout.setAlpha(0);
		_progressLayout.setGravity(Gravity.CENTER);
		_progressLayout.addView(_progress);
		RelativeLayout.LayoutParams layoutParams = new RelativeLayout.LayoutParams(
			    RelativeLayout.LayoutParams.WRAP_CONTENT, 
			    RelativeLayout.LayoutParams.WRAP_CONTENT);
		layoutParams.addRule(RelativeLayout.ALIGN_PARENT_BOTTOM);
		glViewLayout.addView(_progressLayout, layoutParams);
		return rootView;
	}
	public void showProgress(String progress) {
		_progressLayout.setAlpha(1);
		_progress.setText(progress);
	}
	public void hideProgress() {
		_progressLayout.setAlpha(0);
		_progress.setText("");
	}
	public void requestRender() {
		_glView.requestRender();
	}
	public void takeScreenshot(File out) {
		Bitmap screenshot = _glView.getScreenshot();
		try {
			FileOutputStream f = new FileOutputStream(out);
			screenshot.compress(Bitmap.CompressFormat.PNG, 85, f);
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		finally {
			_glView.setDrawingCacheEnabled(false);
		}
	}
}
