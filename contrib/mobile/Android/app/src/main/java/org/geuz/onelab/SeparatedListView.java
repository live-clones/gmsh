package org.geuz.onelab;

import java.util.ArrayList;
import java.util.List;

import android.content.Context;
import android.util.AttributeSet;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ListView;
import android.widget.TextView;

public class SeparatedListView extends ListView {
  private SeparatedListAdaptater adapter;
  private Context _context;

  public SeparatedListView(Context context)
  {
    super(context);
    _context = context;
    adapter = new SeparatedListAdaptater();
    this.setAdapter(adapter);
  }
  public SeparatedListView(Context context, AttributeSet attrs)
  {
    this(context);
  }
  public SeparatedListView(Context context, View[] footer)
  {
    super(context);
    _context = context;
    for(View v : footer) this.addFooterView(v);
    adapter = new SeparatedListAdaptater();
    this.setAdapter(adapter);
  }
  public void addItem(String header, View item)
  {
    TextView title = (TextView)((LayoutInflater)_context.getSystemService(
                                  Context.LAYOUT_INFLATER_SERVICE))
                       .inflate(R.layout.list_header, null);
    title.setText(header);
    adapter.addItem(header, title, item);
    adapter.notifyDataSetChanged();
    this.invalidateViews();
  }
  public int itemsCountInSection(String header)
  {
    return adapter.getCountForSection(header);
  }
  public void refresh()
  {
    adapter.notifyDataSetChanged();
    this.invalidateViews();
  }
  public void clear()
  {
    adapter.clear();
    adapter.notifyDataSetChanged();
  }
  private class Section {
    private String _name;
    private List<View> _items;
    public Section(String name)
    {
      _name = name;
      _items = new ArrayList<View>();
    }
    public void addItem(View v) { _items.add(v); }
    public String getName() { return _name; }
    public int getItemsCount() { return _items.size(); }
    public View getItem(int pos) { return _items.get(pos); }
  }
  private class SeparatedListAdaptater extends BaseAdapter {
    List<Section> sections;
    List<View> titles;
    public SeparatedListAdaptater()
    {
      sections = new ArrayList<SeparatedListView.Section>();
      titles = new ArrayList<View>();
    }
    public void addItem(String header, View title, View item)
    {
      for(Section s : sections) {
        if(s.getName().equals(header)) {
          s.addItem(item);
          return;
        }
      }
      Section s = new Section(header);
      s.addItem(item);
      sections.add(s);
      titles.add(title);
    }
    //@Override
    public int getCount()
    {
      int count = 0;
      for(Section s : sections) count += s.getItemsCount() + 1;
      return count;
    }
    public int getCountForSection(String header)
    {
      for(Section s : sections)
        if(s.getName().equals(header)) return s.getItemsCount();
      return 0;
    }
    //@Override
    public Object getItem(int position)
    {
      int section = -1, lastPosition = -1;
      while(lastPosition < position) {
        int itemsCount = sections.get(section + 1).getItemsCount();
        if(lastPosition + 1 == position) // this is a section
          return titles.get(section + 1);
        else if(lastPosition + 1 + itemsCount >=
                position) { // the view is in this section
          if(section < 0)
            return sections.get(section + 1).getItem(position - 1);
          return sections.get(section + 1).getItem(position - lastPosition - 2);
        }
        lastPosition += 1 + itemsCount;
        section++;
      }
      return null;
    }

    //@Override
    public long getItemId(int position)
    {
      // UNUSED Auto-generated method stub
      return 0;
    }

    //@Override
    public View getView(int position, View convertView, ViewGroup parent)
    {
      int section = -1, lastPosition = -1;
      while(lastPosition < position) {
        int itemsCount = sections.get(section + 1).getItemsCount();
        if(lastPosition + 1 == position) // this is a section
          return titles.get(section + 1);
        else if(lastPosition + 1 + itemsCount >=
                position) { // the view is in this section
          if(section < 0)
            return sections.get(section + 1).getItem(position - 1);
          return sections.get(section + 1).getItem(position - lastPosition - 2);
        }
        lastPosition += 1 + itemsCount;
        section++;
      }
      return null;
    }
    public void clear()
    {
      sections.clear();
      titles.clear();
    }
  }
}
