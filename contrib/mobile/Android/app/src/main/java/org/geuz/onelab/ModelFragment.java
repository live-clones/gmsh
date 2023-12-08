package org.geuz.onelab;

import org.geuz.onelab.Gmsh;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.util.Timer;
import java.util.TimerTask;

import android.app.Fragment;
import android.graphics.Bitmap;
import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.os.Handler;
import android.view.GestureDetector;
import android.view.GestureDetector.OnGestureListener;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.MotionEvent;
import android.view.View;
import android.view.ViewGroup;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.widget.ImageButton;
import android.widget.LinearLayout;
import android.widget.ProgressBar;
import android.widget.RelativeLayout;
import android.widget.SeekBar;
import android.widget.TextView;
import android.util.TypedValue;

public class ModelFragment extends Fragment {
  private Gmsh _gmsh;
  private mGLSurfaceView _glView;
  private TextView _progress;
  private LinearLayout _progressLayout;
  private LinearLayout _controlBarLayout;
  private GestureDetector _gestureDetector;
  private Timer _animation;
  private Handler _hideDelay;
  private SeekBar _animationStepper;

  final Runnable hideControlsRunnable = new Runnable() {
    public void run() { hideControlBar(); }
  };

  public static ModelFragment newInstance(Gmsh g)
  {
    ModelFragment fragment = new ModelFragment();
    Bundle bundle = new Bundle();
    bundle.putParcelable("Gmsh", g);
    fragment.setArguments(bundle);
    return fragment;
  }

  public ModelFragment() {}

  @Override public void onCreate(Bundle savedInstanceState)
  {
    super.onCreate(savedInstanceState);
    _gmsh = getArguments().getParcelable("Gmsh");
  }

  @Override
  public View onCreateView(LayoutInflater inflater, ViewGroup container,
                           Bundle savedInstanceState)
  {
    View rootView = inflater.inflate(R.layout.fragment_model, container, false);
    RelativeLayout glViewLayout =
      (RelativeLayout)rootView.findViewById(R.id.glViewLayout);
    GLESRender renderer = new GLESRender(_gmsh);
    _glView = new mGLSurfaceView(glViewLayout.getContext(), renderer);
    _glView.setEGLContextClientVersion(1);
    _glView.setRenderer(renderer);
    _glView.setRenderMode(GLSurfaceView.RENDERMODE_WHEN_DIRTY);
    _glView.requestRender();
    _hideDelay = new Handler();
    _gestureDetector =
      new GestureDetector(getActivity(), new OnGestureListener() {
        // UNUSED Auto-generated method stub
        public boolean onSingleTapUp(MotionEvent e) { return false; }
        // UNUSED Auto-generated method stub
        public void onShowPress(MotionEvent e) {}
        // UNUSED Auto-generated method stub
        public boolean onScroll(MotionEvent e1, MotionEvent e2, float distanceX,
                                float distanceY)
        {
          return false;
        }
        // UNUSED Auto-generated method stub
        public void onLongPress(MotionEvent e) {}
        // UNUSED Auto-generated method stub
        public boolean onFling(MotionEvent e1, MotionEvent e2, float velocityX,
                               float velocityY)
        {
          return false;
        }
        // UNUSED Auto-generated method stub
        public boolean onDown(MotionEvent e) { return false; }
      });
    _gestureDetector.setOnDoubleTapListener(
      new GestureDetector.OnDoubleTapListener() {
        public boolean onSingleTapConfirmed(MotionEvent e)
        {
          if(View.VISIBLE == _controlBarLayout.getVisibility())
            hideControlBar();
          else
            showControlBar();
          return true;
        }
        // UNUSED Auto-generated method stub
        public boolean onDoubleTapEvent(MotionEvent e) { return false; }
        // UNUSED Auto-generated method stub
        public boolean onDoubleTap(MotionEvent e) { return false; }
      });
    _glView.setOnTouchListener(new View.OnTouchListener() {
      public boolean onTouch(View v, MotionEvent event)
      {
        return _gestureDetector.onTouchEvent(event);
      }
    });
    glViewLayout.addView(_glView);
    RelativeLayout topRightLayout = new RelativeLayout(container.getContext());
    ImageButton rotationButton = new ImageButton(container.getContext());
    rotationButton.setBackgroundResource(R.drawable.icon_rotate);
    rotationButton.setLayoutParams(new LinearLayout.LayoutParams(60, 60));
    rotationButton.setOnClickListener(new View.OnClickListener() {
      public void onClick(View v)
      {
        boolean rotate = !_glView.getRotate();
        ((ImageButton)v)
          .setBackgroundResource(rotate ? R.drawable.icon_translate :
                                          R.drawable.icon_rotate);
        _glView.setRotate(rotate);
      }
    });
    topRightLayout.addView(rotationButton);
    RelativeLayout.LayoutParams layoutParams =
      new RelativeLayout.LayoutParams(RelativeLayout.LayoutParams.WRAP_CONTENT,
                                      RelativeLayout.LayoutParams.WRAP_CONTENT);

    TypedValue tv = new TypedValue();
    int actionBarHeight = 80;
    if(container.getContext().getTheme().resolveAttribute(
         android.R.attr.actionBarSize, tv, true)) {
      actionBarHeight = TypedValue.complexToDimensionPixelSize(
        tv.data, getResources().getDisplayMetrics());
    }
    layoutParams.setMargins(0, actionBarHeight + 20, 20, 0);
    layoutParams.addRule(RelativeLayout.ALIGN_PARENT_TOP);
    layoutParams.addRule(RelativeLayout.ALIGN_PARENT_RIGHT);
    glViewLayout.addView(topRightLayout, layoutParams);
    _progressLayout = new LinearLayout(container.getContext());
    ProgressBar bar = new ProgressBar(container.getContext());
    bar.setOnClickListener(new View.OnClickListener() {
      public void onClick(View v)
      {
        _progress.setAlpha((_progress.getAlpha() > 0) ? 0 : 1);
      }
    });
    _progressLayout.addView(bar);
    _progress = new TextView(container.getContext());
    _progressLayout.setAlpha(0);
    _progressLayout.setGravity(Gravity.CENTER);
    _progressLayout.addView(_progress);
    layoutParams =
      new RelativeLayout.LayoutParams(RelativeLayout.LayoutParams.WRAP_CONTENT,
                                      RelativeLayout.LayoutParams.WRAP_CONTENT);
    layoutParams.addRule(RelativeLayout.ALIGN_PARENT_BOTTOM);
    glViewLayout.addView(_progressLayout, layoutParams);
    _controlBarLayout = (LinearLayout)getActivity().getLayoutInflater().inflate(
      R.layout.control_bar, null);
    final ImageButton prevButton =
      (ImageButton)_controlBarLayout.findViewById(R.id.controlPrev);
    final ImageButton playPauseButton =
      (ImageButton)_controlBarLayout.findViewById(R.id.controlPlay);
    final ImageButton nextButton =
      (ImageButton)_controlBarLayout.findViewById(R.id.controlNext);
    _animationStepper =
      (SeekBar)_controlBarLayout.findViewById(R.id.controlStepper);
    _animationStepper.setOnSeekBarChangeListener(
      new SeekBar.OnSeekBarChangeListener() {
        // UNUSED Auto-generated method stub
        public void onStopTrackingTouch(SeekBar seekBar) {}
        // UNUSED Auto-generated method stub
        public void onStartTrackingTouch(SeekBar seekBar) {}
        public void onProgressChanged(SeekBar seekBar, int progress,
                                      boolean fromUser)
        {
          if(fromUser) {
            postDelay();
            _gmsh.setAnimation(progress);
            requestRender();
          }
        }
      });
    _controlBarLayout.setEnabled(false);
    playPauseButton.setOnClickListener(new View.OnClickListener() {
      public void onClick(View v)
      {
        postDelay();
        if(((ImageButton)v).getContentDescription().equals("play")) {
          ((ImageButton)v).setContentDescription("pause");
          ((ImageButton)v).setImageResource(android.R.drawable.ic_media_pause);
          _animationStepper.setMax(_gmsh.numberOfAnimation() - 1);
          _animation = new Timer();
          _animation.schedule(new TimerTask() {
            public void run()
            {
              _animationStepper.setProgress(_gmsh.animationNext());
              requestRender();
            }
          }, 0, 500);
          prevButton.setEnabled(false);
          nextButton.setEnabled(false);
        }
        else {
          ((ImageButton)v).setContentDescription("play");
          ((ImageButton)v).setImageResource(android.R.drawable.ic_media_play);
          _animation.cancel();
          prevButton.setEnabled(true);
          nextButton.setEnabled(true);
        }
      }
    });
    nextButton.setOnClickListener(new View.OnClickListener() {
      public void onClick(View v)
      {
        postDelay();
        _animationStepper.setProgress(_gmsh.animationNext());
        requestRender();
      }
    });
    prevButton.setOnClickListener(new View.OnClickListener() {
      public void onClick(View v)
      {
        postDelay();
        _animationStepper.setProgress(_gmsh.animationPrev());
        requestRender();
      }
    });
    layoutParams =
      new RelativeLayout.LayoutParams(RelativeLayout.LayoutParams.MATCH_PARENT,
                                      RelativeLayout.LayoutParams.WRAP_CONTENT);
    layoutParams.addRule(RelativeLayout.ALIGN_PARENT_BOTTOM);
    glViewLayout.addView(_controlBarLayout, layoutParams);
    this._controlBarLayout.setVisibility(View.INVISIBLE);
    return rootView;
  }
  public void postDelay(int delay)
  {
    _hideDelay.removeCallbacks(hideControlsRunnable);
    _hideDelay.postDelayed(hideControlsRunnable, delay);
  }
  public void postDelay() { this.postDelay(6000); }
  public void showControlBar()
  {
    if(getActivity() == null || ((MainActivity)getActivity()).isComputing() ||
       !_gmsh.haveAnimation())
      return;
    _controlBarLayout.setEnabled(true);
    _animationStepper.setMax(_gmsh.numberOfAnimation() - 1);
    this.postDelay();
    Animation bottomUp =
      AnimationUtils.loadAnimation(getActivity(), android.R.anim.fade_in);
    _controlBarLayout.setVisibility(View.VISIBLE);
    _controlBarLayout.startAnimation(bottomUp);
  }
  public void hideControlBar()
  {
    if(getActivity() == null ||
       View.INVISIBLE == _controlBarLayout.getVisibility())
      return;
    _hideDelay.removeCallbacks(hideControlsRunnable);
    Animation bottomDown =
      AnimationUtils.loadAnimation(getActivity(), android.R.anim.fade_out);
    _controlBarLayout.startAnimation(bottomDown);
    _controlBarLayout.setVisibility(View.INVISIBLE);
  }
  public void showProgress(String progress)
  {
    _progressLayout.setAlpha(1);
    _progress.setText(progress);
  }
  public void hideProgress()
  {
    _progressLayout.setAlpha(0);
    _progress.setText("");
  }
  public void requestRender() { _glView.requestRender(); }
}
