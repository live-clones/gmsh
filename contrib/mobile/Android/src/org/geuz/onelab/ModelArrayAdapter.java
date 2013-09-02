package org.geuz.onelab;

import java.util.List;
import java.util.ArrayList;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.TextView;

public class ModelArrayAdapter extends ArrayAdapter<Model> {
	private List<Model> _models;

	public ModelArrayAdapter(Context c) {
		super(c, R.layout.model);
		_models = new ArrayList<Model>();
	}
	
	@Override
	public void add(Model model) {
		super.add(model);
		_models.add(model);
	}
	
	public Model getModel(int pos) {
		return _models.get(pos);
	}

	@Override
	public View getView(int position, View convertView, ViewGroup parent) {
		LayoutInflater inflater = (LayoutInflater) parent.getContext()
				.getSystemService(Context.LAYOUT_INFLATER_SERVICE);

		View rowView = inflater.inflate(R.layout.model, parent, false);
		TextView title = (TextView) rowView.findViewById(R.id.title);
		TextView description = (TextView) rowView.findViewById(R.id.description);
		ImageView icon = (ImageView) rowView.findViewById(R.id.icon);
		if(_models.get(position).getName() != null) title.setText(_models.get(position).getName());
		if(_models.get(position).getSummary() != null) description.setText(_models.get(position).getSummary());
		if(_models.get(position).getBitmap() != null) icon.setImageBitmap(_models.get(position).getBitmap());
		else icon.setImageResource(R.drawable.ic_launcher);
		icon.setPadding(10, 10, 10, 10);
		
		return rowView;
	}
}
