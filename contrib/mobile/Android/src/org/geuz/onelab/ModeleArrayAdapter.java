package org.geuz.onelab;

import android.content.Context;
import android.graphics.Color;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.TextView;

public class ModeleArrayAdapter extends ArrayAdapter<String> {
	private Context context;
	private String[] titres;
	private String[] descriptions;

	public ModeleArrayAdapter(Context context, String[] titres) {
		super(context, R.layout.model, titres);
		this.context = context;
		this.titres = titres;
	}
	public ModeleArrayAdapter(Context context, String[] titres, String[] descriptions) {
		this(context,titres);
		this.descriptions = descriptions;
	}
	public ModeleArrayAdapter(Context context, Models models) {
		super(context, R.layout.model, models.getNames());
		this.context = context;
		titres = new String[models.size()];
		descriptions = new String[models.size()];
		for(int i=0;i < models.size();i++) {
			titres[i] = models.getName(i);
			descriptions[i] = models.getSummary(i);
		}
		
	}
	
	@Override
	public View getView(int position, View convertView, ViewGroup parent){
		LayoutInflater inflater = (LayoutInflater) context
				.getSystemService(Context.LAYOUT_INFLATER_SERVICE);

		View rowView = inflater.inflate(R.layout.model, parent, false);
		TextView Titre = (TextView) rowView.findViewById(R.id.titre);
		TextView Description = (TextView) rowView.findViewById(R.id.description);
		ImageView Icone = (ImageView) rowView.findViewById(R.id.icone);
		if(this.titres != null) Titre.setText(this.titres[position]);
		if(this.descriptions != null) Description.setText(this.descriptions[position]);
		if(Icone != null) Icone.setImageResource(R.drawable.ic_launcher);
		Icone.setPadding(10, 10, 10, 10);
		
		return rowView;
	}
}
