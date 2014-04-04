package org.geuz.onelab;

import android.content.Context;
import android.graphics.Bitmap;
import android.opengl.GLSurfaceView;
import android.view.GestureDetector;
import android.view.MotionEvent;
import android.view.ScaleGestureDetector;
import android.view.GestureDetector.OnDoubleTapListener;
import android.view.GestureDetector.OnGestureListener;
import android.view.ScaleGestureDetector.OnScaleGestureListener;

class mGLSurfaceView extends GLSurfaceView {
	private float scaleFactor = 1f;
	private GestureDetector gesture;
	private ScaleGestureDetector scaleGesture;
	private GLESRender _renderer;
	private boolean _rotate;

	public mGLSurfaceView(Context context, GLESRender renderer) {
		super(context);
		_renderer = renderer;
		gesture = new GestureDetector(context, new GestureListener());
		scaleGesture = new ScaleGestureDetector(context, new OnScaleGestureListener() {
			
			public void onScaleEnd(ScaleGestureDetector detector) {
				_renderer.endInteraction(detector.getFocusX(), detector.getFocusY());
			}
			
			public boolean onScaleBegin(ScaleGestureDetector detector) {
				_renderer.startInteraction(detector.getFocusX(), detector.getFocusY());
				return true;
			}
			
			public boolean onScale(ScaleGestureDetector detector) {
				scaleFactor *= detector.getScaleFactor();
				scaleFactor = Math.max(0.1f, Math.min(scaleFactor, 50.0f)); // limit the scale factor
				_renderer.scaleModel(scaleFactor);
				requestRender();
				return true;
				
			}
		});
	}
		
	@Override
	public boolean onTouchEvent(MotionEvent event) {
		scaleGesture.onTouchEvent(event);
		return gesture.onTouchEvent(event);
	}
	
	private class GestureListener implements OnGestureListener, OnDoubleTapListener{
		public boolean onDown(MotionEvent e) {
			_renderer.startInteraction(e.getX(),e.getY());
			return true;
		}

		public boolean onFling(MotionEvent e1, MotionEvent e2,
				float velocityX, float velocityY) {
			// UNUSED Auto-generated method stub
			return false;
		}

		public void onLongPress(MotionEvent e) {
			// UNUSED Auto-generated method stub
			
		}

		public boolean onScroll(MotionEvent e1, MotionEvent e2,
				float distanceX, float distanceY) {
			if(e1.getPointerCount() > 1 || e2.getPointerCount() > 1) return false;
			if(_rotate)
				_renderer.rotateModel(e2.getX(), e2.getY());
			else
				_renderer.translateModel(e2.getX(), e2.getY());
			requestRender();
			return true;
		}

		public void onShowPress(MotionEvent e) {
			// UNUSED Auto-generated method stub
			
		}

		public boolean onSingleTapUp(MotionEvent e) {
			// UNUSED Auto-generated method stub
			return false;
		}
		public boolean onDoubleTap(MotionEvent e) {
			// UNUSED Auto-generated method stub
			return false;
		}
		public boolean onDoubleTapEvent(MotionEvent e) {
			scaleFactor = 1f;
			_renderer.resetModelPosition();
			requestRender();
			return true;
		}
		public boolean onSingleTapConfirmed(MotionEvent e) {
			// UNUSED Auto-generated method stub
			return false;
		}
		
	}
	public boolean getRotate() {return _rotate;}
	public void setRotate(boolean r) {_rotate = r;}
	public void resetScale(){
		scaleFactor = 1f;
		_renderer.scaleModel(scaleFactor);
	}
	public Bitmap getScreenshot() {
		_renderer.needScreenshot();
		this.requestRender();
		while(_renderer.getScreenshot() == null);
		return _renderer.getScreenshot();
	}
}
