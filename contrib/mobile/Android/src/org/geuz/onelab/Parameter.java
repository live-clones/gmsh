package org.geuz.onelab;

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

	public Parameter(Context context, Gmsh gmsh, String name){
		_context = context;
		_gmsh = gmsh;
		_readOnly = false;
		_name = name;
		_title = new TextView(context);
		_title.setText(name);
		_title.setTextAppearance(context, android.R.style.TextAppearance_DeviceDefault_Medium);
		_title.setTextColor(Color.DKGRAY);
	}
	public Parameter(Context context, Gmsh gmsh, String name, boolean readOnly){
		this(context, gmsh, name);
		_readOnly = readOnly;
		_changed = false;
	}

	protected void update(){
		if(_label != null && !_label.equals(""))
			_title.setText(_label);
		else
			_title.setText(getShortName());
		if(isReadOnly()) _title.setAlpha(0.423f);
	}

	public void setName(String name) {_name = name;this.update();}
	public void setReadOnly(boolean readOnly) {_readOnly = readOnly;this.update();}
	public void setLabel(String label) {
		_label = label;
		this.update();
	}
	public String getName() { return _name;}
	public String getShortName() {
		if(_label != null && _label.length() > 0) return _label;
		String[] splited = _name.split("/");
		String name = splited[splited.length-1];
		while(name.length() > 0 && name.charAt(0) >= '0' && name.charAt(0) <= '9')
			name = name.substring(1);
		return name;
	}
	public boolean isReadOnly() {return _readOnly;}
	public String getLabel() {return _label;}
	public int fromString(String s){
		String[] infos = s.split(Character.toString((char)0x03));
		int pos=0;
		pos++;// version
		pos++;// type
		setName(infos[pos++]);// name
		setLabel(infos[pos++]);// label
		pos++;// help
		pos++;// never change
		if(Integer.parseInt(infos[pos++]) != 1)return -1;// visible
		this.setReadOnly((infos[pos++].equals("1")));// read only
		int nAttributes = Integer.parseInt(infos[pos++]);// number of attributes
		pos+=(nAttributes*2);// key+value
		int nClients = Integer.parseInt(infos[pos++]);// number of client
		pos+=(nClients*2);// client+changed
		this.update();
		return pos;
	}
	public boolean changed() { if(_changed){_changed=false; return true;}return _changed;}
	public String getType(){return "Parameter";}

	public LinearLayout getView() {
		LinearLayout paramLayout = new LinearLayout(_context);
		paramLayout.setOrientation(LinearLayout.VERTICAL);
		paramLayout.addView(_title);
		return paramLayout;
	}
}

