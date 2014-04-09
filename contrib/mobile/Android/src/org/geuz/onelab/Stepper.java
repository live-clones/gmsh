package org.geuz.onelab;

import android.content.Context;
import android.view.View;
import android.widget.LinearLayout;
import android.widget.Button;
import android.widget.EditText;


class Stepper extends LinearLayout{

	private int _min, _max, _val;
	private Button _incBtn, _decBtn;
	private EditText _valTxt;
	private OnValueChangedListener _listener;

	public Stepper(Context context){
		super(context);
		_max = _min = _val = 0;
		_incBtn = new Button(context);
		_decBtn = new Button(context);
		_valTxt = new EditText(context);
		_incBtn.setText("+");
		_decBtn.setText("-");
		_valTxt.setText(Integer.toString(_val));
		this.addView(_decBtn);
		this.addView(_valTxt);
		this.addView(_incBtn);
		_incBtn.setOnClickListener(new OnClickListener() {
			public void onClick(View v) {
				inc();
			}
		});
		_decBtn.setOnClickListener(new OnClickListener() {
			public void onClick(View v) {
				dec();
			}
		});
	}

	public interface OnValueChangedListener {
		public void onValueChanged();
	}


	public void inc(){setValue(_val+1);}
	public void dec(){setValue(_val-1);}

	public void setOnValueChangedListener(OnValueChangedListener listener) {_listener = listener;}
	public void setMaximum(int max){_max = max;}
	public void setMinimum(int min){_min = min;}
	public void setValue(int val){
		if(_max > _min) {
			if(val == _max) _incBtn.setEnabled(false);
			else if(val == _min) _decBtn.setEnabled(false);
			else {_incBtn.setEnabled(true); _decBtn.setEnabled(true);} 
		}
		_val = val;
		_valTxt.setText(Integer.toString(_val));
		if(_listener != null) _listener.onValueChanged();
	}
	public int getMaximum(){return _max;}
	public int getMinimum(){return _min;}
	public int getValue(){return _val;}
}
