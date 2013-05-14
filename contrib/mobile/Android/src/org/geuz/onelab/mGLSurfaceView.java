package org.geuz.onelab;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.support.v4.view.MotionEventCompat;
import android.view.GestureDetector;
import android.view.MotionEvent;
import android.view.ScaleGestureDetector;
import android.view.View;
import android.view.GestureDetector.OnDoubleTapListener;
import android.view.GestureDetector.OnGestureListener;
import android.view.ScaleGestureDetector.OnScaleGestureListener;

class mGLSurfaceView extends GLSurfaceView {
	private float scaleFactor = 1f;
	private GestureDetector gesture;
	private ScaleGestureDetector scaleGesture;
	private float lastX, lastY;
	private GLESRender _renderer;
	public mGLSurfaceView(Context context, GLESRender renderer) {
		super(context);
		_renderer = renderer;
		gesture = new GestureDetector(context, new GestureListener(this));
		scaleGesture = new ScaleGestureDetector(context, new OnScaleGestureListener() {
			
			public void onScaleEnd(ScaleGestureDetector detector) {}// UNUSED Auto-generated method stub
			
			public boolean onScaleBegin(ScaleGestureDetector detector) {return true;}// UNUSED Auto-generated method stub
			
			public boolean onScale(ScaleGestureDetector detector) {
				scaleFactor *= detector.getScaleFactor();
				scaleFactor = Math.max(0.1f, Math.min(scaleFactor, 50.0f)); 
				_renderer.scale(scaleFactor, scaleFactor, scaleFactor);
				requestRender();
				return true;
				
			}
		});
	}
		
	@Override
	public boolean onTouchEvent(MotionEvent event) {
		if(event.getPointerCount() >= 3){
			scaleGesture.onTouchEvent(MotionEvent.obtain(0, 0, MotionEvent.ACTION_CANCEL, 0,0, 0));
			
			final float x = MotionEventCompat.getX(event, 1);
	        final float y = MotionEventCompat.getY(event, 1);
	        
	        int action = MotionEventCompat.getActionMasked(event);
	        
	        if(action == MotionEvent.ACTION_DOWN || action == MotionEvent.ACTION_POINTER_1_DOWN){
	        	lastX = x;
	        	lastY = y;
	        }
	        else if(action == MotionEvent.ACTION_MOVE){
	        	float dx = x - lastX,
	        			dy = y - lastY;
	        	if(dx != 0 || dy != 0)
	        		_renderer.rotate(dy, dx, 0);
	        	requestRender();
	        	lastX = x;
	        	lastY = y;
	        }

			return true;
		}
		else {
			scaleGesture.onTouchEvent(event);
			return gesture.onTouchEvent(event);
		}
		
	}
	
	private class GestureListener implements OnGestureListener, OnDoubleTapListener{
		//private View view;
		public GestureListener(View view) {
			//this.view = view;
		}
		public boolean onDown(MotionEvent e) {
			// UNUSED Auto-generated method stub
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
			_renderer.translate(-distanceX, distanceY, 0f);
			requestRender();
			return false;
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
			_renderer.translate(0f, 0f, 0f);
			scaleFactor = 1f;
			_renderer.scale(scaleFactor, scaleFactor, scaleFactor);
			_renderer.rotate(0, 0, 0);
			requestRender();
			return false;
		}
		public boolean onSingleTapConfirmed(MotionEvent e) {
			// UNUSED Auto-generated method stub
			return false;
		}
		
	}
	public void resetScale(){
		scaleFactor = 1f;
		_renderer.scale(scaleFactor, scaleFactor, scaleFactor);
	}	
}
