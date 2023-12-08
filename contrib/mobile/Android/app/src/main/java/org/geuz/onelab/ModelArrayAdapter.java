package org.geuz.onelab;

import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.TextView;

public class ModelArrayAdapter extends ArrayAdapter<Model> {
  private List<Model> _models;

  public ModelArrayAdapter(Context c)
  {
    super(c, R.layout.model);
    _models = new ArrayList<Model>();
  }

  @Override public void add(Model model)
  {
    super.add(model);
    _models.add(model);
  }

  public void reset()
  {
    super.clear();
    _models.clear();
  }

  public void sortByName() { Collections.sort(_models, new ModelComp()); }

  public Model getModel(int pos) { return _models.get(pos); }

  @Override
  public View getView(int position, View convertView, final ViewGroup parent)
  {
    LayoutInflater inflater =
      (LayoutInflater)parent.getContext().getSystemService(
        Context.LAYOUT_INFLATER_SERVICE);
    final Model m = _models.get(position);
    View rowView = inflater.inflate(R.layout.model, parent, false);
    TextView title = (TextView)rowView.findViewById(R.id.title);
    TextView description = (TextView)rowView.findViewById(R.id.description);
    ImageView icon = (ImageView)rowView.findViewById(R.id.icon);
    if(m.getName() != null) title.setText(m.getName());
    if(m.getSummary() != null) description.setText(m.getSummary());
    if(m.getBitmap() != null)
      icon.setImageBitmap(m.getBitmap());
    else
      icon.setImageResource(R.drawable.ic_launcher);
    return rowView;
  }
}
