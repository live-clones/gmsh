package org.geuz.onelab;

import org.geuz.onelab.Gmsh;

import java.util.ArrayList;

import android.app.Activity;
import android.content.Context;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.KeyEvent;
import android.view.View;
import android.view.inputmethod.InputMethodManager;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.SeekBar;
import android.widget.Spinner;
import android.app.Dialog;
import android.app.AlertDialog;
import android.app.DialogFragment;
import android.content.DialogInterface;
import android.widget.LinearLayout;
import android.widget.TextView;

public class ParameterNumber extends Parameter {
  private double _value, _tmpValue, _min, _max, _step;
  private SeekBar _bar;
  private ArrayList<Double> _values;
  private ArrayList<String> _choices;
  private ArrayAdapter<String> _adapter;
  private Spinner _spinner;
  private CheckBox _checkbox;
  private EditText _edittext;
  private Stepper _stepper;

  public ParameterNumber(Context context, Gmsh gmsh, String name)
  {
    super(context, gmsh, name);
  }
  public ParameterNumber(Context context, Gmsh gmsh, String name, double value,
                         double min, double max, double step)
  {
    this(context, gmsh, name);
    _value = value;
    _min = min;
    _max = max;
    _step = step;
  }
  public ParameterNumber(Context context, Gmsh gmsh, String name,
                         boolean readOnly, double value, double min, double max,
                         double step)
  {
    this(context, gmsh, name, value, min, max, step);
    _readOnly = readOnly;
  }

  public static String formatDouble(double x)
  {
    return String.format("%.6g", x).replaceFirst("\\.?0+(e|$)", "$1");
  }

  protected void update()
  {
    super.update();
    if(_bar != null) {
      _title.setText(getShortName() + " (" + formatDouble(_value) + ")");
      _bar.setMax(100);
      _bar.setProgress((int)(100 * (_value - _min) / (_max - _min)));
      _bar.setEnabled(!this.isReadOnly());
    }
    else if(_spinner != null) {
      for(int i = 0; i < _choices.size(); i++)
        if(_values.get(i) == _value) _spinner.setSelection(i, true);
    }
    else if(_checkbox != null) {
      _checkbox.setText(getShortName());
      _checkbox.setChecked((_value == 0) ? false : true);
    }
    else if(_edittext != null) {
      _edittext.setText("" + formatDouble(_value));
    }
    else if(_stepper != null) {
      _stepper.setMaximum((int)Math.round(_max));
      _stepper.setMinimum((int)Math.round(_min));
      _stepper.setValue((int)Math.round(_value));
    }
  }
  public void setValue(double value)
  {
    if(value == _value) return;
    _value = value;
    _changed = true;
    _gmsh.setParam(getType(), getName(), String.valueOf(value));
    if(mListener != null) mListener.OnParameterChanged();
  }
  public void setMin(double min)
  {
    _min = min;
    this.update();
  }
  public void setMax(double max)
  {
    _max = max;
    this.update();
  }
  public void setStep(double step)
  {
    _step = step;
    this.update();
  }
  public void addChoice(double choice, String value)
  {
    if(_values == null) {
      _values = new ArrayList<Double>();
      _choices = new ArrayList<String>();
      _values.add(choice);
      _choices.add(value);
      if(_spinner == null) {
        _spinner = new Spinner(_context);
        _adapter = new ArrayAdapter<String>(
          _context, android.R.layout.simple_spinner_dropdown_item, _choices);
        _adapter.setDropDownViewResource(
          android.R.layout.simple_spinner_dropdown_item);
        _spinner.setAdapter(_adapter);
      }
    }
    else {
      for(int i = 0; i < _values.size(); i++) {
        if(_values.get(i).equals(choice) && _choices.size() > i) {
          _choices.set(i, value);
          return;
        }
        else if(_values.get(i).equals(choice)) {
          _choices.add(value);
          return;
        }
      }
      _values.add(choice);
      _choices.add(value);
    }
  }
  public double getValue() { return _value; }
  public double getMax() { return _max; }
  public double getMin() { return _min; }
  public double getStep() { return _step; }
  public int parseInt(String s, int defaultValue)
  {
    int tmp;
    try {
      tmp = Integer.parseInt(s);
    } catch(NumberFormatException e) {
      tmp = defaultValue;
    }
    return tmp;
  }
  public double parseDouble(String s, double defaultValue)
  {
    double tmp;
    try {
      tmp = Double.parseDouble(s);
    } catch(NumberFormatException e) {
      tmp = defaultValue;
    }
    return tmp;
  }
  public int fromString(String s)
  {
    int pos = super.fromString(s);
    if(pos <= 0) return -1; // error
    String[] infos = s.split(Character.toString((char)0x03));
    int nValues = parseInt(infos[pos++], 0);
    _value = 0;
    if(nValues > 0) {
      double values[] = new double[nValues];
      for(int i = 0; i < nValues; i++) {
        String tmpVal = infos[pos++];
        values[i] = parseDouble(tmpVal, 0.);
      }
      // FIXME: generalize to handle list of values
      _value = values[0];
    }
    this.setMin(parseDouble(infos[pos++], 0.));
    this.setMax(parseDouble(infos[pos++], 0.));
    this.setStep(parseDouble(infos[pos++], 0.));
    pos++; // index
    int nChoices = parseInt(infos[pos++], 0); // choices' size
    double choices[] = new double[nChoices];
    for(int i = 0; i < nChoices; i++)
      choices[i] = parseDouble(infos[pos++], 0.); // choice
    int nLabels = parseInt(infos[pos++], 0); // labels' size
    if(nChoices == 2 && choices[0] == 0 && choices[1] == 1 && nLabels == 0) {
      _checkbox = new CheckBox(_context);
      this.update();
      return pos;
    }
    if(_choices != null) _choices.clear();
    if(_values != null) _values.clear();
    for(int i = 0; i < nLabels && nChoices == nLabels; i++) {
      double val = parseDouble(infos[pos++], 0.); // choice
      this.addChoice(val, infos[pos++]); // label
    }
    // ...
    if(nLabels < 1 && _step == 0)
      _edittext = new EditText(_context);
    else if(_step == 1)
      _stepper = new Stepper(_context);
    else if(nLabels < 1)
      _bar = new SeekBar(_context);
    this.update();
    return pos;
  }
  public String getType() { return "ParameterNumber"; }
  public LinearLayout getView()
  {
    LinearLayout paramLayout = new LinearLayout(_context);
    paramLayout.setOrientation(LinearLayout.VERTICAL);
    paramLayout.addView(_title);
    if(!_readOnly)
      paramLayout.setOnLongClickListener(new View.OnLongClickListener() {
        @Override public boolean onLongClick(View v)
        {
          AlertDialog.Builder builder = new AlertDialog.Builder(_context);
          LinearLayout layout = new LinearLayout(_context);
          layout.setOrientation(LinearLayout.VERTICAL);
          TextView label = new TextView(_context);
          label.setText("Edit value of \n" + _name);
          EditText edit = new EditText(_context);
          edit.setText(String.valueOf(_value));
          edit.addTextChangedListener(new TextWatcher() {
            public void onTextChanged(CharSequence s, int start, int before,
                                      int count)
            {
              _tmpValue = parseDouble(s.toString(), 1.);
            }
            // UNUSED Auto-generated method stub
            public void beforeTextChanged(CharSequence s, int start, int count,
                                          int after)
            {
            }
            // UNUSED Auto-generated method stub
            public void afterTextChanged(Editable s) {}
          });
          edit.requestFocus();
          //_context.getWindow().setSoftInputMode
          //    (WindowManager.LayoutParams.SOFT_INPUT_STATE_ALWAYS_VISIBLE);
          layout.addView(label);
          layout.addView(edit);
          builder.setView(layout)
            .setPositiveButton("OK",
                               new DialogInterface.OnClickListener() {
                                 public void onClick(DialogInterface dialog,
                                                     int id)
                                 {
                                   setValue(_tmpValue);
                                 }
                               })
            .setNegativeButton("Cancel", new DialogInterface.OnClickListener() {
              public void onClick(DialogInterface dialog, int id)
              {
                // User cancelled the dialog
              }
            });
          builder.create().show();
          return true;
        }
      });
    if(_spinner != null) {
      paramLayout.addView(_spinner);
      _spinner.setEnabled(!_readOnly);
      _spinner.setOnItemSelectedListener(
        new AdapterView.OnItemSelectedListener() {
          public void onNothingSelected(AdapterView<?> arg0) {}
          public void onItemSelected(AdapterView<?> parent, View view, int pos,
                                     long id)
          {
            setValue(_values.get(pos));
          }
        });
    }
    else if(_bar != null) {
      paramLayout.addView(_bar);
      _bar.setEnabled(!_readOnly);
      _bar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
        public void onStopTrackingTouch(SeekBar seekBar)
        {
          setValue(getMin() +
                   (getMax() - getMin()) * seekBar.getProgress() / 100);
        }
        public void onStartTrackingTouch(SeekBar seekBar) {}
        public void onProgressChanged(SeekBar seekBar, int progress,
                                      boolean fromUser)
        {
        }
      });
    }
    else if(_checkbox != null) {
      paramLayout.removeView(_title);
      paramLayout.addView(_checkbox);
      _checkbox.setEnabled(!_readOnly);
      _checkbox.setOnCheckedChangeListener(
        new CompoundButton.OnCheckedChangeListener() {
          public void onCheckedChanged(CompoundButton buttonView,
                                       boolean isChecked)
          {
            setValue((isChecked) ? 1 : 0);
          }
        });
    }
    else if(_edittext != null) {
      paramLayout.addView(_edittext);
      _edittext.setEnabled(!_readOnly);

      _edittext.setOnKeyListener(new View.OnKeyListener() {
        public boolean onKey(View v, int keyCode, KeyEvent event)
        {
          if(keyCode == KeyEvent.KEYCODE_ENTER) { // hide the keyboard
            InputMethodManager imm =
              (InputMethodManager)_context.getSystemService(
                Context.INPUT_METHOD_SERVICE);
            imm.hideSoftInputFromWindow(_edittext.getWindowToken(), 0);
            setValue(_value);
            _edittext.clearFocus();
            return true;
          }
          if(keyCode > KeyEvent.KEYCODE_9 &&
             keyCode != KeyEvent.KEYCODE_NUMPAD_DOT &&
             (keyCode < KeyEvent.KEYCODE_NUMPAD_0 ||
              keyCode > KeyEvent.KEYCODE_NUMPAD_9) &&
             keyCode != KeyEvent.KEYCODE_DEL)
            return true;
          return false;
        }
      });
      _edittext.addTextChangedListener(new TextWatcher() {
        public void onTextChanged(CharSequence s, int start, int before,
                                  int count)
        {
          _value = parseDouble(s.toString(), 1.);
        }
        // UNUSED Auto-generated method stub
        public void beforeTextChanged(CharSequence s, int start, int count,
                                      int after)
        {
        }
        // UNUSED Auto-generated method stub
        public void afterTextChanged(Editable s) {}
      });
    }
    else if(_stepper != null) {
      paramLayout.addView(_stepper);
      _stepper.setOnValueChangedListener(new Stepper.OnValueChangedListener() {
        public void onValueChanged() { setValue(_stepper.getValue()); }
      });
    }
    return paramLayout;
  }
  private OnParameterChangedListener mListener;
  public void setOnParameterChangedListener(OnParameterChangedListener listener)
  {
    mListener = listener;
  }
  public interface OnParameterChangedListener {
    void OnParameterChanged();
  }
}
