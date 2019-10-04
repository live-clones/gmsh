package org.geuz.onelab;

import org.geuz.onelab.Gmsh;

import android.content.Context;
import android.graphics.Color;
import android.widget.LinearLayout;
import android.widget.TextView;

public class Parameter {
  protected Context _context;
  protected Gmsh _gmsh;
  protected String _name;
  protected String _label;
  protected boolean _readOnly;
  protected boolean _changed;
  protected TextView _title;

  public Parameter(Context context, Gmsh gmsh, String name)
  {
    _context = context;
    _gmsh = gmsh;
    _readOnly = false;
    _name = name;
    _title = new TextView(context);
    _title.setText(name);
    _title.setTextAppearance(
      context, android.R.style.TextAppearance_DeviceDefault_Medium);
    _title.setTextColor(Color.DKGRAY);
  }
  public Parameter(Context context, Gmsh gmsh, String name, boolean readOnly)
  {
    this(context, gmsh, name);
    _readOnly = readOnly;
    _changed = false;
  }

  protected void update()
  {
    _title.setText(getShortName());
    if(isReadOnly()) _title.setAlpha(0.423f);
  }

  public void setName(String name)
  {
    _name = name;
    this.update();
  }
  public void setReadOnly(boolean readOnly)
  {
    _readOnly = readOnly;
    this.update();
  }
  public void setLabel(String label)
  {
    _label = label;
    this.update();
  }
  public String getName() { return _name; }
  public String getShortName()
  {
    if(_label != null && _label.length() > 0) return _label;
    String[] split = _name.split("/");
    String name = split[split.length - 1];
    while(name.length() > 0 && name.charAt(0) == ' ') name = name.substring(1);
    while(name.length() > 0 && (name.charAt(0) == '{' || name.charAt(0) == '}'))
      name = name.substring(1);
    while(name.length() > 0 && name.charAt(0) >= '0' && name.charAt(0) <= '9')
      name = name.substring(1);
    return name;
  }
  public String getSectionName()
  {
    String name = "";
    if(_name.contains("/")) {
      String[] split = _name.split("/");
      for(int i = 0; i < split.length - 1; i++) {
        String s = split[i];
        while(s.length() > 0 && s.charAt(0) == ' ') s = s.substring(1);
        while(s.length() > 0 && (s.charAt(0) == '{' || s.charAt(0) == '}'))
          s = s.substring(1);
        while(s.length() > 0 && s.charAt(0) >= '0' && s.charAt(0) <= '9')
          s = s.substring(1);
        if(i != 0) name += " > ";
        name += s;
      }
    }
    return name;
  }
  public boolean isReadOnly() { return _readOnly; }
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
  public int fromString(String s)
  {
    String[] infos = s.split(Character.toString((char)0x03));
    int pos = 0;
    pos++; // version
    pos++; // type
    setName(infos[pos++]); // name
    if(_name.equals("GetDP/}ModelCheck")) // don't show model checking
      return -1;
    setLabel(infos[pos++]); // label
    pos++; // help
    pos++; // changedValue
    if(parseInt(infos[pos++], 0) != 1) return -1; // visible
    this.setReadOnly((infos[pos++].equals("1"))); // read only
    int nAttributes = parseInt(infos[pos++], 0); // number of attributes
    pos += (nAttributes * 2); // key+value
    int nClients = parseInt(infos[pos++], 0); // number of client
    pos += (nClients * 2); // client+changed
    this.update();
    return pos;
  }
  public boolean changed()
  {
    if(_changed) {
      _changed = false;
      return true;
    }
    return _changed;
  }
  public String getType() { return "Parameter"; }
  public LinearLayout getView()
  {
    LinearLayout paramLayout = new LinearLayout(_context);
    paramLayout.setOrientation(LinearLayout.VERTICAL);
    paramLayout.addView(_title);
    return paramLayout;
  }
}
