package org.geuz.onelab;

import java.util.ArrayList;
import java.util.List;


class Models {
	private List<String> _name;
	private List<String> _summary;
	private List<String> _file;
	
	public Models(){
		_name = new ArrayList<String>();
		_summary = new ArrayList<String>();
		_file = new ArrayList<String>();
	}
	
	public int size() {
		return _name.size();
	}
	public String getName(int pos) {
		return _name.get(pos);
	}
	public String[] getNames() {
		String[] ret = new String[_name.size()];
    	ret = _name.toArray(ret);
    	return ret;
	}
	public String getSummary(int pos) {
		return _summary.get(pos);
	}
	public String getFile(int pos) {
		return _file.get(pos);
	}
	public void addModel(String name, String summary, String file){
		_name.add(name);
		_file.add(file);
		_summary.add(summary);
	}
}
