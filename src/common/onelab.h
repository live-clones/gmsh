// ONELAB - Copyright (C) 2011-2024 Universite de Liege - Universite catholique
// de Louvain
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, and/or sell copies of the
// Software, and to permit persons to whom the Software is furnished to do so,
// provided that the above copyright notice(s) and this permission notice appear
// in all copies of the Software and that both the above copyright notice(s) and
// this permission notice appear in supporting documentation.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT OF THIRD PARTY
// RIGHTS. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR HOLDERS INCLUDED IN THIS
// NOTICE BE LIABLE FOR ANY CLAIM, OR ANY SPECIAL INDIRECT OR CONSEQUENTIAL
// DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
// PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
// ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
// SOFTWARE.

#ifndef ONELAB_H
#define ONELAB_H

#include <time.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <mutex>
#include <regex>

#include "GmshSocket.h"

#define HAVE_PICOJSON
#if defined(HAVE_PICOJSON)
#include "picojson.h"
#endif

namespace onelab {

  // The base parameter class.
  class parameter {
  private:
    // the name of the parameter, including its '/'-separated path in the
    // parameter hierarchy. Subpaths can start with white space, numbers or
    // braces (in that order) to force their relative ordering; getShortName()
    // can be used to remove these prefixes automatically. All strings in ONELAB
    // are supposed to be UTF8-encoded.
    std::string _name;
    // the parameter label: if provided it serves as a better way to display the
    // parameter in the interface
    std::string _label;
    // a help string
    std::string _help;
    // map of clients that use this parameter, associated with a "changed" flag
    // (set to 0 if the client has already been run with the current value of
    // the parameter; set to defaultChangedValue() when the value of a parameter
    // has been changed; values between 1 and defaultChangedValue() can be used
    // to "modulate" the degree of change, e.g. to change the action to be
    // performed depending on the "severity" of the change)
    std::map<std::string, int> _clients;
    // flag indicating what the "changed" value should be set to when a
    // parameter is updated to a different value (if set to 0, the parameter
    // will appear as never being changed)
    int _changedValue;
    // should the parameter be visible in the interface?
    bool _visible;
    // sould the paramete be "read-only" (not settable by the user)
    bool _readOnly;

  protected:
    // optional additional attributes
    std::map<std::string, std::string> _attributes;

  public:
    parameter(const std::string &name = "", const std::string &label = "",
              const std::string &help = "")
      : _name(name), _label(label), _help(help), _visible(true),
        _readOnly(false)
    {
      _changedValue = defaultChangedValue();
    }
    virtual ~parameter() {}
    void setName(const std::string &name) { _name = name; }
    void setLabel(const std::string &label) { _label = label; }
    void setHelp(const std::string &help) { _help = help; }
    void setChanged(int changed, const std::string &client = "")
    {
      if(client.size()) {
        auto it = _clients.find(client);
        if(it != _clients.end()) it->second = changed;
      }
      else {
        for(auto it = _clients.begin(); it != _clients.end(); it++)
          it->second = changed;
      }
    }
    void setChangedValue(int value) { _changedValue = value; }
    void setNeverChanged(bool never)
    {
      _changedValue = never ? 0 : defaultChangedValue();
    }
    void setVisible(bool visible) { _visible = visible; }
    void setReadOnly(bool readOnly) { _readOnly = readOnly; }
    void setAttribute(const std::string &key, const std::string &value)
    {
      _attributes[key] = value;
    }
    void setAttributes(const std::map<std::string, std::string> &attributes)
    {
      _attributes = attributes;
    }
    void setClients(const std::map<std::string, int> &clients)
    {
      _clients = clients;
    }
    void addClient(const std::string &client, int changed)
    {
      if(_clients.find(client) == _clients.end()) _clients[client] = changed;
    }
    void addClients(const std::map<std::string, int> &clients)
    {
      _clients.insert(clients.begin(), clients.end());
    }
    bool hasClient(const std::string &client)
    {
      return (_clients.find(client) != _clients.end());
    }
    int getNumClients() { return (int)_clients.size(); };
    virtual std::string getType() const = 0;
    const std::string &getName() const { return _name; }
    const std::string &getLabel() const { return _label; }
    const std::string &getHelp() const { return _help; }
    std::string getPath() const
    {
      std::string::size_type last = _name.find_last_of('/');
      return _name.substr(0, last);
    }
    std::string getShortName() const
    {
      std::string units = getAttribute("Units");
      if(_label.size()) {
        if(units.empty())
          return _label;
        else
          return _label + " [" + units + "]";
      }
      std::string s = _name;
      // remove path
      std::string::size_type last = _name.find_last_of('/');
      if(last != std::string::npos) s = _name.substr(last + 1);
      // remove starting white space
      while(s.size() && s[0] == ' ') s = s.substr(1);
      // remove starting braces: can be used to order parameters 'from the end',
      // as the ASCII code is after numbers and letters
      while(s.size() && (s[0] == '}' || s[0] == '{')) s = s.substr(1);
      // remove starting numbers: can be used to order parameters 'from the
      // start'
      while(s.size() && s[0] >= '0' && s[0] <= '9') s = s.substr(1);
      if(units.empty())
        return s;
      else
        return s + " [" + units + "]";
    }
    int getChanged(const std::string &client = "") const
    {
      if(client.size()) {
        auto it = _clients.find(client);
        if(it != _clients.end())
          return it->second;
        else
          return 0;
      }
      else {
        int changed = 0;
        for(auto it = _clients.begin(); it != _clients.end(); it++) {
          changed = std::max(changed, it->second);
        }
        return changed;
      }
    }
    int getChangedValue() const { return _changedValue; }
    bool getNeverChanged() const { return _changedValue ? false : true; }
    bool getVisible() const { return _visible; }
    bool getReadOnly() const { return _readOnly; }
    std::string getAttribute(const std::string &key) const
    {
      auto it = _attributes.find(key);
      if(it != _attributes.end()) return it->second;
      return "";
    }
    const std::map<std::string, std::string> &getAttributes() const
    {
      return _attributes;
    }
    const std::map<std::string, int> &getClients() const { return _clients; }
    static char charSep() { return '\0'; }
    static double maxNumber() { return 1e200; }
    static std::string version() { return "1.3"; }
    static int defaultChangedValue() { return 31; }
    static std::string getNextToken(const std::string &msg,
                                    std::string::size_type &first,
                                    char separator = charSep())
    {
      if(first == std::string::npos) return "";
      std::string::size_type last = msg.find_first_of(separator, first);
      std::string next("");
      if(last == std::string::npos) {
        next = msg.substr(first);
        first = last;
      }
      else if(first == last) {
        next = "";
        first = last + 1;
      }
      else {
        next = msg.substr(first, last - first);
        first = last + 1;
      }
      return next;
    }
    static std::vector<std::string> split(const std::string &msg,
                                          char separator = charSep())
    {
      std::vector<std::string> out;
      std::string::size_type first = 0;
      while(first != std::string::npos)
        out.push_back(getNextToken(msg, first, separator));
      return out;
    }
    static std::string trim(const std::string &str,
                            const std::string &whitespace = " \t\n")
    {
      std::string::size_type strBegin = str.find_first_not_of(whitespace);
      if(strBegin == std::string::npos) return ""; // no content
      std::string::size_type strEnd = str.find_last_not_of(whitespace);
      std::string::size_type strRange = strEnd - strBegin + 1;
      return str.substr(strBegin, strRange);
    }
    std::string sanitize(const std::string &in) const
    {
      std::string out(in);
      for(std::size_t i = 0; i < in.size(); i++)
        if(out[i] == charSep()) out[i] = ' ';
      return out;
    }
    virtual std::string toChar() const
    {
      std::ostringstream sstream;
      sstream << version() << charSep() << getType() << charSep()
              << sanitize(getName()) << charSep() << sanitize(getLabel())
              << charSep() << sanitize(getHelp()) << charSep()
              << getChangedValue() << charSep() << (getVisible() ? 1 : 0)
              << charSep() << (getReadOnly() ? 1 : 0) << charSep()
              << _attributes.size() << charSep();
      for(auto it = _attributes.begin(); it != _attributes.end(); it++)
        sstream << sanitize(it->first) << charSep() << sanitize(it->second)
                << charSep();
      sstream << getClients().size() << charSep();
      for(auto it = getClients().begin(); it != getClients().end(); it++)
        sstream << sanitize(it->first) << charSep() << (it->second ? 1 : 0)
                << charSep();
      return sstream.str();
    }
    virtual std::string::size_type fromChar(const std::string &msg)
    {
      std::string::size_type pos = 0;
      if(getNextToken(msg, pos) != version()) return 0;
      if(getNextToken(msg, pos) != getType()) return 0;
      setName(getNextToken(msg, pos));
      setLabel(getNextToken(msg, pos));
      setHelp(getNextToken(msg, pos));
      setChangedValue(atoi(getNextToken(msg, pos).c_str()));
      setVisible(atoi(getNextToken(msg, pos).c_str()));
      setReadOnly(atoi(getNextToken(msg, pos).c_str()));
      int numAttributes = atoi(getNextToken(msg, pos).c_str());
      for(int i = 0; i < numAttributes; i++) {
        std::string key(getNextToken(msg, pos));
        setAttribute(key, getNextToken(msg, pos));
      }
      int numClients = atoi(getNextToken(msg, pos).c_str());
      for(int i = 0; i < numClients; i++) {
        std::string client(getNextToken(msg, pos));
        int changed = atoi(getNextToken(msg, pos).c_str());
        addClient(client, changed);
      }
      return pos;
    }
    static void getInfoFromChar(const std::string &msg, std::string &version,
                                std::string &type, std::string &name)
    {
      std::string::size_type first = 0;
      version = getNextToken(msg, first);
      type = getNextToken(msg, first);
      name = getNextToken(msg, first);
    }
    static bool fromFile(std::vector<std::string> &msg, FILE *fp)
    {
      msg.clear();
      char tmp[1000];
      if(!fgets(tmp, sizeof(tmp), fp)) return false; // first line is comment
      while(!feof(fp)) {
        int numc = 0;
        if(!fscanf(fp, "%d ", &numc)) break; // space is important
        if(!numc) break;
        msg.push_back("");
        for(int i = 0; i < numc; i++) msg.back() += fgetc(fp);
        if(!fgets(tmp, sizeof(tmp), fp)) break; // end of line
      }
      return true;
    }
    static bool toFile(const std::vector<std::string> &msg, FILE *fp,
                       const std::string &creator)
    {
      time_t now;
      time(&now);
      fprintf(fp, "ONELAB database created by %s on %s", creator.c_str(),
              ctime(&now));
      for(std::size_t i = 0; i < msg.size(); i++) {
        fprintf(fp, "%d ", (int)msg[i].size());
        for(std::size_t j = 0; j < msg[i].size(); j++) fputc(msg[i][j], fp);
        fputc('\n', fp);
      }
      return true;
    }
    std::string sanitizeJSON(const std::string &in) const
    {
      // FIXME: replace \n with \\n, \t with \\t, etc.
      return in;
    }
    virtual std::string toJSON() const
    {
      std::ostringstream sstream;
      sstream << "\"type\":\"" << getType() << "\""
              << ", \"name\":\"" << sanitizeJSON(getName()) << "\"";
      if(getLabel().size())
        sstream << ", \"label\":\"" << sanitizeJSON(getLabel()) << "\"";
      if(getHelp().size())
        sstream << ", \"help\":\"" << sanitizeJSON(getHelp()) << "\"";
      sstream << ", \"changedValue\":" << getChangedValue()
              << ", \"visible\":" << (getVisible() ? "true" : "false")
              << ", \"readOnly\":" << (getReadOnly() ? "true" : "false");
      if(_attributes.size()) {
        sstream << ", \"attributes\":{ ";
        for(auto it = _attributes.begin(); it != _attributes.end(); it++) {
          if(it != _attributes.begin()) sstream << ", ";
          sstream << "\"" << sanitizeJSON(it->first) << "\":\""
                  << sanitizeJSON(it->second) << "\"";
        }
        sstream << " }";
      }
      if(getClients().size()) {
        sstream << ", \"clients\":{ ";
        for(auto it = getClients().begin(); it != getClients().end(); it++) {
          if(it != getClients().begin()) sstream << ", ";
          sstream << "\"" << sanitizeJSON(it->first) << "\":" << it->second;
        }
        sstream << " }";
      }
      return sstream.str();
    }
#if defined(HAVE_PICOJSON)
    virtual bool fromJSON(const picojson::value::object &par)
    {
      for(auto it = par.begin(); it != par.end(); ++it) {
        if(it->first == "name") {
          if(!it->second.is<std::string>()) return false;
          setName(it->second.get<std::string>());
        }
        else if(it->first == "label") {
          if(!it->second.is<std::string>()) return false;
          setLabel(it->second.get<std::string>());
        }
        else if(it->first == "help") {
          if(!it->second.is<std::string>()) return false;
          setHelp(it->second.get<std::string>());
        }
        else if(it->first == "changedValue") {
          if(!it->second.is<double>()) return false;
          setChangedValue((int)it->second.get<double>());
        }
        else if(it->first == "visible") {
          if(!it->second.is<bool>()) return false;
          setVisible(it->second.get<bool>());
        }
        else if(it->first == "readOnly") {
          if(!it->second.is<bool>()) return false;
          setReadOnly(it->second.get<bool>());
        }
        else if(it->first == "attributes") {
          if(!it->second.is<picojson::object>()) return false;
          const picojson::value::object &obj =
            it->second.get<picojson::object>();
          for(auto i = obj.begin(); i != obj.end(); ++i) {
            std::string key(i->first);
            if(!i->second.is<std::string>()) return false;
            setAttribute(key, i->second.get<std::string>());
          }
        }
        else if(it->first == "clients") {
          if(!it->second.is<picojson::object>()) return false;
          const picojson::value::object &obj =
            it->second.get<picojson::object>();
          for(auto i = obj.begin(); i != obj.end(); ++i) {
            std::string client(i->first);
            if(!i->second.is<double>()) return false;
            addClient(client, (int)i->second.get<double>());
          }
        }
      }
      return true;
    }
#endif
  };

  class parameterLessThan {
  public:
    bool operator()(const parameter *p1, const parameter *p2) const
    {
      return p1->getName() < p2->getName();
    }
  };

  // The number class. Numbers are stored internally as double precision real
  // numbers.
  class number : public parameter {
  private:
    std::vector<double> _values, _choices;
    double _min, _max, _step;
    // when in a loop, indicates current index in the vector _choices; is -1
    // when not in a loop
    int _index;
    std::map<double, std::string> _valueLabels;

  public:
    number(const std::string &name = "", double value = 0.,
           const std::string &label = "", const std::string &help = "")
      : parameter(name, label, help), _values(std::vector<double>(1, value)),
        _min(-maxNumber()), _max(maxNumber()), _step(0.), _index(-1)
    {
    }
    number(const std::string &name, const std::vector<double> &values,
           const std::string &label = "", const std::string &help = "")
      : parameter(name, label, help), _values(values), _min(-maxNumber()),
        _max(maxNumber()), _step(0.), _index(-1)
    {
    }
    void setValue(double value)
    {
      _values.resize(1);
      _values[0] = value;
    }
    void setValues(const std::vector<double> &values) { _values = values; }
    void setMin(double min) { _min = min; }
    void setMax(double max) { _max = max; }
    void setStep(double step) { _step = step; }
    void setIndex(int index) { _index = index; }
    void setChoices(const std::vector<double> &choices) { _choices = choices; }
    void setChoiceLabels(const std::vector<std::string> &labels)
    {
      if(labels.size() != _choices.size()) return;
      if(_valueLabels.size()) _valueLabels.clear();
      for(std::size_t i = 0; i < _choices.size(); i++)
        _valueLabels[_choices[i]] = labels[i];
    }
    void setValueLabels(const std::map<double, std::string> &valueLabels)
    {
      _valueLabels = valueLabels;
    }
    void setValueLabel(double value, const std::string &label)
    {
      _valueLabels[value] = label;
    }
    std::string getType() const { return "number"; }
    double getValue() const
    {
      if(_values.empty()) return 0.;
      return _values[0];
    }
    std::string getValueAsString() const
    {
      std::ostringstream sstream;
      sstream << getValue();
      return sstream.str();
    }
    const std::vector<double> &getValues() const { return _values; }
    int getNumValues() const { return (int)_values.size(); }
    double getMin() const { return _min; }
    double getMax() const { return _max; }
    double getStep() const { return _step; }
    int getIndex() const { return _index; }
    const std::vector<double> &getChoices() const { return _choices; }
    const std::map<double, std::string> &getValueLabels() const
    {
      return _valueLabels;
    }
    std::string getValueLabel(double value) const
    {
      auto it = _valueLabels.find(value);
      if(it != _valueLabels.end()) return it->second;
      return "";
    }
    void update(const number &p)
    {
      addClients(p.getClients());
      setLabel(p.getLabel());
      setHelp(p.getHelp());
      setVisible(p.getVisible());
      setReadOnly(p.getReadOnly());
      setAttributes(p.getAttributes());
      bool changed = false;
      for(std::size_t i = 0; i < p.getValues().size(); i++) {
        if(p.getValues()[i] != getValues()[i]) {
          changed = true;
          break;
        }
      }
      if(changed) {
        setValues(p.getValues());
        setChanged(getChangedValue());
      }
      setMin(p.getMin());
      setMax(p.getMax());
      setStep(p.getStep());
      setIndex(p.getIndex());
      setChoices(p.getChoices());
      setValueLabels(p.getValueLabels());
      if(getNeverChanged()) setChanged(0);
    }
    std::string toChar() const
    {
      std::ostringstream sstream;
      sstream.precision(16);
      sstream << parameter::toChar() << _values.size() << charSep();
      for(std::size_t i = 0; i < _values.size(); i++)
        sstream << _values[i] << charSep();
      sstream << _min << charSep() << _max << charSep() << _step << charSep()
              << _index << charSep() << _choices.size() << charSep();
      for(std::size_t i = 0; i < _choices.size(); i++)
        sstream << _choices[i] << charSep();
      sstream << _valueLabels.size() << charSep();
      for(auto it = _valueLabels.begin(); it != _valueLabels.end(); it++) {
        sstream << it->first << charSep() << sanitize(it->second) << charSep();
      }
      return sstream.str();
    }
    std::string::size_type fromChar(const std::string &msg)
    {
      std::string::size_type pos = parameter::fromChar(msg);
      if(!pos) return 0;
      _values.resize(atoi(getNextToken(msg, pos).c_str()));
      for(std::size_t i = 0; i < _values.size(); i++)
        _values[i] = atof(getNextToken(msg, pos).c_str());
      setMin(atof(getNextToken(msg, pos).c_str()));
      setMax(atof(getNextToken(msg, pos).c_str()));
      setStep(atof(getNextToken(msg, pos).c_str()));
      setIndex(atoi(getNextToken(msg, pos).c_str()));
      _choices.resize(atoi(getNextToken(msg, pos).c_str()));
      for(std::size_t i = 0; i < _choices.size(); i++)
        _choices[i] = atof(getNextToken(msg, pos).c_str());
      int numValueLabels = atoi(getNextToken(msg, pos).c_str());
      for(int i = 0; i < numValueLabels; i++) {
        double value = atof(getNextToken(msg, pos).c_str());
        _valueLabels[value] = getNextToken(msg, pos);
      }
      return pos;
    }
    std::string toJSON() const
    {
      std::ostringstream sstream;
      sstream.precision(16);
      sstream << "{ " << parameter::toJSON() << ", \"values\":[ ";
      for(std::size_t i = 0; i < _values.size(); i++) {
        if(i) sstream << ", ";
        sstream << _values[i];
      }
      sstream << " ]"
              << ", \"min\":" << _min << ", \"max\":" << _max
              << ", \"step\":" << _step << ", \"index\":" << _index;
      if(_choices.size()) {
        sstream << ", \"choices\":[ ";
        for(std::size_t i = 0; i < _choices.size(); i++) {
          if(i) sstream << ", ";
          sstream << _choices[i];
        }
        sstream << " ]";
      }
      if(_valueLabels.size()) {
        sstream << ", \"valueLabels\":{ ";
        for(auto it = _valueLabels.begin(); it != _valueLabels.end(); it++) {
          if(it != _valueLabels.begin()) sstream << ", ";
          sstream << "\"" << sanitizeJSON(it->second) << "\":" << it->first;
        }
        sstream << " }";
      }
      sstream << " }";
      return sstream.str();
    }
    bool fromJSON(const std::string &json)
    {
#if defined(HAVE_PICOJSON)
      picojson::value v;
      std::string err = picojson::parse(v, json);
      if(err.size()) return false;
      if(!v.is<picojson::object>()) return false;
      const picojson::value::object &par = v.get<picojson::object>();
      auto it = par.find("type");
      if(it == par.end()) return false;
      if(it->second.to_str() == "number") {
        fromJSON(par);
        return true;
      }
#endif
      return false;
    }
#if defined(HAVE_PICOJSON)
    bool fromJSON(const picojson::value::object &par)
    {
      if(!parameter::fromJSON(par)) return false;
      for(auto it = par.begin(); it != par.end(); ++it) {
        if(it->first == "values") {
          if(!it->second.is<picojson::array>()) return false;
          const picojson::value::array &arr = it->second.get<picojson::array>();
          _values.resize(arr.size());
          for(std::size_t i = 0; i < arr.size(); i++) {
            if(!arr[i].is<double>()) return false;
            _values[i] = arr[i].get<double>();
          }
        }
        else if(it->first == "min") {
          if(!it->second.is<double>()) return false;
          setMin(it->second.get<double>());
        }
        else if(it->first == "max") {
          if(!it->second.is<double>()) return false;
          setMax(it->second.get<double>());
        }
        else if(it->first == "step") {
          if(!it->second.is<double>()) return false;
          setStep(it->second.get<double>());
        }
        else if(it->first == "index") {
          if(!it->second.is<double>()) return false;
          setIndex((int)it->second.get<double>());
        }
        else if(it->first == "choices") {
          if(!it->second.is<picojson::array>()) return false;
          const picojson::value::array &arr = it->second.get<picojson::array>();
          _choices.resize(arr.size());
          for(std::size_t i = 0; i < arr.size(); i++) {
            if(!arr[i].is<double>()) return false;
            _choices[i] = arr[i].get<double>();
          }
        }
        else if(it->first == "valueLabels") {
          if(!it->second.is<picojson::object>()) return false;
          const picojson::value::object &obj =
            it->second.get<picojson::object>();
          for(auto i = obj.begin(); i != obj.end(); ++i) {
            if(!i->second.is<double>()) return false;
            _valueLabels[i->second.get<double>()] = i->first;
          }
        }
      }
      return true;
    }
#endif
  };

  // The string class. A string has a mutable "kind", that can be changed at
  // runtime. Kinds leading to specific behavior in Gmsh are: "file".
  class string : public parameter {
  private:
    std::vector<std::string> _values, _choices;
    std::string _kind;

  public:
    string(const std::string &name = "", const std::string &value = "",
           const std::string &label = "", const std::string &help = "")
      : parameter(name, label, help),
        _values(std::vector<std::string>(1, value)), _kind("generic")
    {
    }
    string(const std::string &name, const std::vector<std::string> &values,
           const std::string &label = "", const std::string &help = "")
      : parameter(name, label, help), _values(values), _kind("generic")
    {
    }
    void setValue(const std::string &value)
    {
      _values.resize(1);
      _values[0] = value;
    }
    void setValues(const std::vector<std::string> &values) { _values = values; }
    void setKind(const std::string &kind) { _kind = kind; }
    void setChoices(const std::vector<std::string> &choices)
    {
      _choices = choices;
    }
    std::string getType() const { return "string"; }
    const std::string &getValue() const
    {
      static std::string n("");
      if(_values.empty()) return n;
      return _values[0];
    }
    std::string getValueAsString() const { return getValue(); }
    const std::vector<std::string> &getValues() const { return _values; }
    int getNumValues() const { return (int)_values.size(); }
    const std::string &getKind() const { return _kind; }
    const std::vector<std::string> &getChoices() const { return _choices; }
    void update(const string &p)
    {
      addClients(p.getClients());
      setLabel(p.getLabel());
      setHelp(p.getHelp());
      setVisible(p.getVisible());
      setReadOnly(p.getReadOnly());
      setAttributes(p.getAttributes());
      bool changed = false;
      for(std::size_t i = 0; i < p.getValues().size(); i++) {
        if(p.getValues()[i] != getValues()[i]) {
          changed = true;
          break;
        }
      }
      if(changed) {
        setValues(p.getValues());
        setChanged(getChangedValue());
      }
      if(p.getKind() != getKind()) {
        setKind(p.getKind());
        setChanged(getChangedValue());
      }
      setChoices(p.getChoices());
      if(getNeverChanged()) setChanged(0);
    }
    std::string toChar() const
    {
      std::ostringstream sstream;
      sstream << parameter::toChar() << _values.size() << charSep();
      for(std::size_t i = 0; i < _values.size(); i++)
        sstream << sanitize(_values[i]) << charSep();
      sstream << sanitize(_kind) << charSep() << _choices.size() << charSep();
      for(std::size_t i = 0; i < _choices.size(); i++)
        sstream << sanitize(_choices[i]) << charSep();
      return sstream.str();
    }
    std::string::size_type fromChar(const std::string &msg)
    {
      std::string::size_type pos = parameter::fromChar(msg);
      if(!pos) return 0;
      _values.resize(atoi(getNextToken(msg, pos).c_str()));
      for(std::size_t i = 0; i < _values.size(); i++)
        _values[i] = getNextToken(msg, pos);
      setKind(getNextToken(msg, pos));
      _choices.resize(atoi(getNextToken(msg, pos).c_str()));
      for(std::size_t i = 0; i < _choices.size(); i++)
        _choices[i] = getNextToken(msg, pos);
      return pos;
    }
    std::string toJSON() const
    {
      std::ostringstream sstream;
      sstream << "{ " << parameter::toJSON() << ", \"values\":[ ";
      for(std::size_t i = 0; i < _values.size(); i++) {
        if(i) sstream << ", ";
        sstream << "\"" << sanitizeJSON(_values[i]) << "\"";
      }
      sstream << " ] ";
      if(_kind.size())
        sstream << ", \"kind\":\"" << sanitizeJSON(_kind) << "\"";
      if(_choices.size()) {
        sstream << ", \"choices\":[ ";
        for(std::size_t i = 0; i < _choices.size(); i++) {
          if(i) sstream << ", ";
          sstream << "\"" << sanitizeJSON(_choices[i]) << "\"";
        }
        sstream << " ]";
      }
      sstream << " }";
      return sstream.str();
    }
    bool fromJSON(const std::string &json)
    {
#if defined(HAVE_PICOJSON)
      picojson::value v;
      std::string err = picojson::parse(v, json);
      if(err.size()) return false;
      if(!v.is<picojson::object>()) return false;
      const picojson::value::object &par = v.get<picojson::object>();
      auto it = par.find("type");
      if(it == par.end()) return false;
      if(it->second.to_str() == "string") {
        fromJSON(par);
        return true;
      }
#endif
      return false;
    }
#if defined(HAVE_PICOJSON)
    bool fromJSON(const picojson::value::object &par)
    {
      if(!parameter::fromJSON(par)) return false;
      for(auto it = par.begin(); it != par.end(); ++it) {
        if(it->first == "values") {
          if(!it->second.is<picojson::array>()) return false;
          const picojson::value::array &arr = it->second.get<picojson::array>();
          _values.resize(arr.size());
          for(std::size_t i = 0; i < arr.size(); i++) {
            if(!arr[i].is<std::string>()) return false;
            _values[i] = arr[i].get<std::string>();
          }
        }
        else if(it->first == "kind") {
          if(!it->second.is<std::string>()) return false;
          setKind(it->second.get<std::string>());
        }
        else if(it->first == "choices") {
          if(!it->second.is<picojson::array>()) return false;
          const picojson::value::array &arr = it->second.get<picojson::array>();
          _choices.resize(arr.size());
          for(std::size_t i = 0; i < arr.size(); i++) {
            if(!arr[i].is<std::string>()) return false;
            _choices[i] = arr[i].get<std::string>();
          }
        }
      }
      return true;
    }
#endif
  };

  // The parameter space, i.e., the set of parameters stored and handled by the
  // ONELAB server.
  class parameterSpace {
  private:
    std::set<number *, parameterLessThan> _numbers;
    std::set<string *, parameterLessThan> _strings;
    std::mutex _mutex;

    // delete a parameter from the parameter space
    template <class T>
    bool _clear(const std::string &name, const std::string &client,
                std::set<T *, parameterLessThan> &ps)
    {
      if(name.empty() && client.size()) {
        std::vector<T *> toDelete;
        for(auto it = ps.begin(); it != ps.end();) {
          T *p = *it;
          if(p->hasClient(client)) {
            ps.erase(it++); // to avoid invalid iterator
            delete p;
          }
          else {
            it++;
          }
        }
      }
      else {
        T tmp(name);
        auto it = ps.find(&tmp);
        if(it != ps.end()) {
          T *p = *it;
          if(client.empty() || p->hasClient(client)) {
            ps.erase(it);
            delete p;
            return true;
          }
        }
      }
      return false;
    }
    // set a parameter in the parameter space; if it already exists, update it
    // (adding new clients if necessary). This would need to be locked to avoid
    // race conditions when several clients try to set a parameter at the same
    // time.
    template <class T>
    bool _set(const T &p, const std::string &client,
              std::set<T *, parameterLessThan> &ps)
    {
      _mutex.lock();
      auto it = ps.find((T *)&p);
      if(it != ps.end()) {
        (*it)->update(p);
        if(client.size())
          (*it)->addClient(client, parameter::defaultChangedValue());
      }
      else {
        T *newp = new T(p);
        if(client.size())
          newp->addClient(client, parameter::defaultChangedValue());
        ps.insert(newp);
      }
      _mutex.unlock();
      return true;
    }
    // get the parameter matching the given name, or all the parameters in the
    // category if no name is given. If we find a given parameter by name, we
    // add the client requesting the parameter to the list of clients for this
    // parameter. This would also need to be locked.
    template <class T>
    bool _get(std::vector<T> &p, const std::string &name,
              const std::string &client, std::set<T *, parameterLessThan> &ps)
    {
      p.clear();
      if(name.empty()) {
        for(auto it = ps.begin(); it != ps.end(); it++) p.push_back(**it);
      }
      else {
        T tmp(name);
        auto it = ps.find(&tmp);
        if(it != ps.end()) {
          if(client.size()) {
            _mutex.lock();
            (*it)->addClient(client, parameter::defaultChangedValue());
            _mutex.unlock();
          }
          p.push_back(**it);
        }
      }
      return true;
    }
    template <class T>
    T *_getPtr(std::string name, const std::string client,
               std::set<T *, parameterLessThan> ps)
    {
      T tmp(name);
      auto it = ps.find(&tmp);
      if(it != ps.end()) {
        if(client.size()) {
          _mutex.lock();
          (*it)->addClient(client, parameter::defaultChangedValue());
          _mutex.unlock();
        }
        return *it;
      }
      return nullptr;
    }

  public:
    parameterSpace() {}
    ~parameterSpace() { clear(); }
    void clear(const std::string &name = "", const std::string &client = "")
    {
      if(name.empty() && client.empty()) {
        std::set<parameter *, parameterLessThan> ps;
        getAllParameters(ps);
        for(auto it = ps.begin(); it != ps.end(); it++) delete *it;
        _numbers.clear();
        _strings.clear();
      }
      else {
        bool done = _clear(name, client, _numbers);
        if(!done) done = _clear(name, client, _strings);
      }
    }
    bool set(const number &p, const std::string &client = "")
    {
      return _set(p, client, _numbers);
    }
    bool set(const string &p, const std::string &client = "")
    {
      return _set(p, client, _strings);
    }
    bool get(std::vector<number> &ps, const std::string &name = "",
             const std::string &client = "")
    {
      return _get(ps, name, client, _numbers);
    }
    bool get(std::vector<string> &ps, const std::string &name = "",
             const std::string &client = "")
    {
      return _get(ps, name, client, _strings);
    }
    void getPtr(number **ptr, const std::string &name,
                const std::string &client = "")
    {
      *ptr = _getPtr(name, client, _numbers);
    }
    void getPtr(string **ptr, const std::string &name,
                const std::string &client = "")
    {
      *ptr = _getPtr(name, client, _strings);
    }
    void getAllParameters(std::set<parameter *, parameterLessThan> &ps) const
    {
      ps.insert(_numbers.begin(), _numbers.end());
      ps.insert(_strings.begin(), _strings.end());
    }
    int getNumParameters() { return (int)(_numbers.size() + _strings.size()); }
    void getParameterNames(std::vector<std::string> &names,
                           const std::string &search = "") const
    {
      names.clear();
      if(search.empty()) {
        for(auto &p : _numbers) names.push_back(p->getName());
        for(auto &p : _strings) names.push_back(p->getName());
      }
      else {
        try {
          for(auto &p : _numbers) {
            if(std::regex_search(p->getName(), std::regex(search)))
              names.push_back(p->getName());
          }
          for(auto &p : _strings) {
            if(std::regex_search(p->getName(), std::regex(search)))
              names.push_back(p->getName());
          }
        } catch(...) {
        }
      }
    }
    // check if at least one parameter depends on the given client
    bool hasClient(const std::string &client) const
    {
      std::set<parameter *, parameterLessThan> ps;
      getAllParameters(ps);
      for(auto it = ps.begin(); it != ps.end(); it++)
        if((*it)->hasClient(client)) return true;
      return false;
    }
    // check if some parameters have changed (optionnally only check the
    // parameters that depend on a given client)
    int getChanged(const std::string &client = "") const
    {
      std::set<parameter *, parameterLessThan> ps;
      getAllParameters(ps);
      int changed = 0;
      for(auto it = ps.begin(); it != ps.end(); it++) {
        changed = std::max(changed, (*it)->getChanged(client));
      }
      return changed;
    }
    // set the changed flag for all the parameters that depend on the given
    // client (or for all parameters if no client name is provided)
    void setChanged(int changed, const std::string &client = "")
    {
      std::set<parameter *, parameterLessThan> ps;
      getAllParameters(ps);
      for(auto it = ps.begin(); it != ps.end(); it++)
        (*it)->setChanged(changed, client);
    }
    void thresholdChanged(int threshold, const std::string &client = "")
    {
      std::set<parameter *, parameterLessThan> ps;
      getAllParameters(ps);
      for(auto it = ps.begin(); it != ps.end(); it++) {
        int changed = (*it)->getChanged(client);
        if(changed > threshold) (*it)->setChanged(threshold, client);
      }
    }
    // serialize the parameter space (optionally only serialize those parameters
    // that depend on the given client)
    std::vector<std::string> toChar(const std::string &client = "") const
    {
      std::vector<std::string> s;
      std::set<parameter *, parameterLessThan> ps;
      getAllParameters(ps);
      for(auto it = ps.begin(); it != ps.end(); it++)
        if(client.empty() || (*it)->hasClient(client)) {
          if((*it)->getAttribute("NotInDb") != "True")
            s.push_back((*it)->toChar());
        }
      return s;
    }
    // unserialize the parameter space
    bool fromChar(const std::vector<std::string> &msg,
                  const std::string &client = "")
    {
      for(std::size_t i = 0; i < msg.size(); i++) {
        std::string version, type, name;
        onelab::parameter::getInfoFromChar(msg[i], version, type, name);
        if(onelab::parameter::version() != version) return false;
        if(type == "number") {
          number p;
          p.fromChar(msg[i]);
          set(p, client);
        }
        else if(type == "string") {
          string p;
          p.fromChar(msg[i]);
          set(p, client);
        }
        else
          return false;
      }
      return true;
    }
    bool toJSON(std::string &json, const std::string &creator = "",
                const std::string &client = "") const
    {
      time_t now;
      time(&now);
      std::string t(ctime(&now));
      t.resize(t.size() - 1);
      json.clear();
      json += "{ \"onelab\":{\n";
      json += "  \"creator\":\"" + creator + "\",\n";
      json += "  \"date\":\"" + t + "\",\n";
      json += "  \"version\":\"" + parameter::version() + "\",\n";
      json += "  \"parameters\":[\n";
      std::set<parameter *, parameterLessThan> ps;
      getAllParameters(ps);
      for(auto it = ps.begin(); it != ps.end(); it++) {
        if(it != ps.begin()) json += ",\n";
        if(client.empty() || (*it)->hasClient(client)) {
          if((*it)->getAttribute("NotInDb") != "True") {
            json += "    " + (*it)->toJSON();
          }
        }
      }
      json += "\n  ] }\n}\n";
      return true;
    }
    bool fromJSON(const std::string &json, const std::string &client = "")
    {
#if defined(HAVE_PICOJSON)
      picojson::value v;
      std::string err = picojson::parse(v, json);
      if(err.size()) return false;
      if(v.is<picojson::object>()) { // full database or single parameter
        const picojson::value::object &obj = v.get<picojson::object>();
        auto it = obj.find("onelab");
        if(it != obj.end()) { // full database
          if(!it->second.is<picojson::object>()) return false;
          const picojson::value::object &db =
            it->second.get<picojson::object>();
          for(auto j = db.begin(); j != db.end(); ++j) {
            if(j->first == "version") {
              if(!j->second.is<std::string>()) return false;
              if(j->second.get<std::string>() != parameter::version())
                return false;
            }
            else if(j->first == "parameters") {
              if(!j->second.is<picojson::array>()) return false;
              const picojson::value::array &arr =
                j->second.get<picojson::array>();
              for(std::size_t k = 0; k < arr.size(); k++) {
                if(!arr[k].is<picojson::object>()) return false;
                const picojson::value::object &par =
                  arr[k].get<picojson::object>();
                if(!fromJSON(par, client)) return false;
              }
            }
          }
          return true;
        }
        else { // single parameter
          return fromJSON(obj, client);
        }
      }
      else if(v.is<picojson::array>()) { // array of parameters
        const picojson::value::array &arr = v.get<picojson::array>();
        for(std::size_t k = 0; k < arr.size(); k++) {
          if(!arr[k].is<picojson::object>()) return false;
          const picojson::value::object &par = arr[k].get<picojson::object>();
          if(!fromJSON(par, client)) return false;
        }
        return true;
      }
      else {
        return false;
      }
#else
      return false;
#endif
    }
#if defined(HAVE_PICOJSON)
    bool fromJSON(const picojson::value::object &par,
                  const std::string &client = "")
    {
      auto it = par.find("type");
      if(it == par.end()) return false;
      if(it->second.to_str() == "number") {
        number p;
        p.fromJSON(par);
        set(p, client);
        return true;
      }
      else if(it->second.to_str() == "string") {
        string p;
        p.fromJSON(par);
        set(p, client);
        return true;
      }
      return false;
    }
#endif
  };

  // The ONELAB client: a class that communicates with the ONELAB server. Each
  // client should be derived from this one. A client can be understood as "one
  // simulation step in a complex computation".
  class client {
  protected:
    // the name of the client
    std::string _name;
    // the id of the client, used to create a unique socket for this client
    int _id;
    // the index of the client in an external client list (if any)
    int _index;

  public:
    client(const std::string &name) : _name(name), _id(0), _index(-1) {}
    virtual ~client() {}
    std::string getName() { return _name; }
    void setId(int id) { _id = id; }
    int getId() { return _id; }
    void setIndex(int index) { _index = index; }
    int getIndex() { return _index; }
    virtual bool run() { return false; }
    virtual bool isNetworkClient() { return false; }
    virtual bool kill() { return false; }
    virtual void sendInfo(const std::string &msg)
    {
      std::cout << msg << std::endl;
    }
    virtual void sendWarning(const std::string &msg)
    {
      std::cerr << msg << std::endl;
    }
    virtual void sendError(const std::string &msg)
    {
      std::cerr << msg << std::endl;
    }
    virtual void sendProgress(const std::string &msg)
    {
      std::cout << msg << std::endl;
    }
    virtual void sendMergeFileRequest(const std::string &msg) {}
    virtual void sendOpenProjectRequest(const std::string &msg) {}
    virtual void sendParseStringRequest(const std::string &msg) {}
    virtual void sendVertexArray(const std::string &msg) {}
    virtual bool clear(const std::string &name) = 0;
    virtual bool set(const number &p) = 0;
    virtual bool set(const string &p) = 0;
    virtual bool get(std::vector<number> &ps, const std::string &name = "") = 0;
    virtual bool get(std::vector<string> &ps, const std::string &name = "") = 0;
    virtual bool setAndAppendChoices(const number &p) = 0;
    virtual bool setAndAppendChoices(const string &p) = 0;
    virtual bool getWithoutChoices(std::vector<number> &ps,
                                   const std::string &name = "") = 0;
    virtual bool getWithoutChoices(std::vector<string> &ps,
                                   const std::string &name = "") = 0;
    std::vector<std::string> toChar()
    {
      std::vector<std::string> out;
      std::vector<number> n;
      get(n);
      for(std::size_t i = 0; i < n.size(); i++) out.push_back(n[i].toChar());
      std::vector<string> s;
      get(s);
      for(std::size_t i = 0; i < s.size(); i++) out.push_back(s[i].toChar());
      return out;
    }
    bool fromChar(const std::vector<std::string> &msg)
    {
      for(std::size_t i = 0; i < msg.size(); i++) {
        std::string version, type, name;
        onelab::parameter::getInfoFromChar(msg[i], version, type, name);
        if(onelab::parameter::version() != version) return false;
        if(type == "number") {
          number p;
          p.fromChar(msg[i]);
          set(p);
        }
        else if(type == "string") {
          string p;
          p.fromChar(msg[i]);
          set(p);
        }
        else
          return false;
      }
      return true;
    }
    bool toFile(FILE *fp) { return parameter::toFile(toChar(), fp, getName()); }
    bool fromFile(FILE *fp)
    {
      std::vector<std::string> msg;
      if(parameter::fromFile(msg, fp)) return fromChar(msg);
      return false;
    }
  };

  // The ONELAB server: a singleton that stores the parameter space and
  // interacts with ONELAB clients.
  class server {
  private:
    // the unique server (singleton behaviour due to the "static" specifier)
    static server *_server;
    // the address of the server
    std::string _address;
    // the connected clients
    std::set<client *> _clients;
    // the parameter space
    parameterSpace _parameterSpace;

  public:
    server(const std::string &address = "") : _address(address) {}
    ~server() {}
    static server *instance(const std::string &address = "")
    {
      if(!_server) _server = new server(address);
      return _server;
    }
    static void setInstance(server *s) { _server = s; }
    void clear(const std::string &name = "", const std::string &client = "")
    {
      _parameterSpace.clear(name, client);
    }
    template <class T> bool set(const T &p, const std::string &client = "")
    {
      return _parameterSpace.set(p, client);
    }
    template <class T>
    bool get(std::vector<T> &ps, const std::string &name = "",
             const std::string &client = "")
    {
      return _parameterSpace.get(ps, name, client);
    }
    typedef std::set<client *>::iterator citer;
    citer firstClient() { return _clients.begin(); }
    citer lastClient() { return _clients.end(); }
    int getNumClients() { return (int)_clients.size(); };
    citer findClient(const std::string &name)
    {
      for(auto it = _clients.begin(); it != _clients.end(); it++)
        if((*it)->getName() == name) return it;
      return _clients.end();
    }
    void registerClient(client *c)
    {
      _clients.insert(c);
      c->setId((int)_clients.size());
    }
    void unregisterClient(client *c) { _clients.erase(c); }
    void setChanged(int changed, const std::string &client = "")
    {
      _parameterSpace.setChanged(changed, client);
    }
    int getChanged(const std::string &client = "")
    {
      return _parameterSpace.getChanged(client);
    }
    void thresholdChanged(int value, const std::string &client = "")
    {
      _parameterSpace.thresholdChanged(value, client);
    }
    int getNumParameters() { return _parameterSpace.getNumParameters(); }
    void getParameterNames(std::vector<std::string> &names,
                           const std::string &search = "") const
    {
      _parameterSpace.getParameterNames(names, search);
    }
    std::vector<std::string> toChar(const std::string &client = "")
    {
      return _parameterSpace.toChar(client);
    }
    bool fromChar(const std::vector<std::string> &msg,
                  const std::string &client = "")
    {
      return _parameterSpace.fromChar(msg, client);
    }
    bool toFile(FILE *fp, const std::string &client = "")
    {
      return parameter::toFile(toChar(client), fp, "onelab server");
    }
    bool fromFile(FILE *fp, const std::string &client = "")
    {
      std::vector<std::string> msg;
      if(parameter::fromFile(msg, fp)) return fromChar(msg, client);
      return false;
    }
    bool toJSON(std::string &json, const std::string &client = "")
    {
      return _parameterSpace.toJSON(json, client);
    }
    bool fromJSON(const std::string &json, const std::string &client = "")
    {
      return _parameterSpace.fromJSON(json, client);
    }
  };

  // A local client, which lives in the same memory space as the server.
  class localClient : public client {
  private:
    template <class T> bool _set(const T &p)
    {
      server::instance()->set(p, _name);
      return true;
    }
    template <class T>
    bool _get(std::vector<T> &ps, const std::string &name = "")
    {
      server::instance()->get(ps, name, _name);
      return true;
    }

  public:
    localClient(const std::string &name) : client(name)
    {
      server::instance()->registerClient(this);
    }
    virtual ~localClient() { server::instance()->unregisterClient(this); }
    virtual bool clear(const std::string &name = "")
    {
      server::instance()->clear(name);
      return true;
    }
    virtual bool set(const number &p) { return _set(p); }
    virtual bool set(const string &p) { return _set(p); }
    virtual bool get(std::vector<number> &ps, const std::string &name = "")
    {
      return _get(ps, name);
    }
    virtual bool get(std::vector<string> &ps, const std::string &name = "")
    {
      return _get(ps, name);
    }
    virtual bool setAndAppendChoices(const number &p)
    {
      std::vector<number> ps;
      _get(ps, _name);
      std::vector<double> choices;
      if(ps.size()) choices = ps[0].getChoices();
      choices.insert(choices.end(), p.getChoices().begin(),
                     p.getChoices().end());
      number p2(p);
      p2.setChoices(choices);
      return _set(p2);
    }
    virtual bool setAndAppendChoices(const string &p)
    {
      std::vector<string> ps;
      _get(ps, _name);
      std::vector<std::string> choices;
      if(ps.size()) choices = ps[0].getChoices();
      choices.insert(choices.end(), p.getChoices().begin(),
                     p.getChoices().end());
      string p2(p);
      p2.setChoices(choices);
      return _set(p2);
    }
    virtual bool getWithoutChoices(std::vector<number> &ps,
                                   const std::string &name = "")
    {
      bool ret = _get(ps, name);
      for(std::size_t i = 0; i < ps.size(); i++)
        ps[i].setChoices(std::vector<double>());
      return ret;
    }
    virtual bool getWithoutChoices(std::vector<string> &ps,
                                   const std::string &name = "")
    {
      bool ret = _get(ps, name);
      for(std::size_t i = 0; i < ps.size(); i++)
        ps[i].setChoices(std::vector<std::string>());
      return ret;
    }
  };

  // The local part of a network client.
  class localNetworkClient : public localClient {
  private:
    // executable of the client (including filesystem path, if necessary)
    std::string _executable;
    // treat the executable name as a full command line (will prevent the
    // escaping of the exe name, and will assume that the command line has been
    // correcly escaped)
    bool _treatExecutableAsFullCommandLine;
    // command to login to a remote host (if necessary)
    std::string _remoteLogin;
    // command line option to specify socket
    std::string _socketSwitch;
    // pid of the remote network client while it is running (-1 otherwise)
    int _pid;
    // underlying GmshServer
    GmshServer *_gmshServer;

  public:
    localNetworkClient(const std::string &name, const std::string &executable,
                       const std::string &remoteLogin = "",
                       bool treatExecutableAsFullCommandLine = false)
      : localClient(name), _executable(executable),
        _treatExecutableAsFullCommandLine(treatExecutableAsFullCommandLine),
        _remoteLogin(remoteLogin), _socketSwitch("-onelab"), _pid(-1),
        _gmshServer(nullptr)
    {
    }
    virtual ~localNetworkClient() {}
    virtual bool isNetworkClient() { return true; }
    const std::string &getExecutable() { return _executable; }
    void setExecutable(const std::string &s) { _executable = s; }
    const std::string &getRemoteLogin() { return _remoteLogin; }
    bool treatExecutableAsFullCommandLine() const
    {
      return _treatExecutableAsFullCommandLine;
    }
    void setRemoteLogin(const std::string &s) { _remoteLogin = s; }
    const std::string &getSocketSwitch() { return _socketSwitch; }
    void setSocketSwitch(const std::string &s) { _socketSwitch = s; }
    int getPid() { return _pid; }
    void setPid(int pid) { _pid = pid; }
    GmshServer *getGmshServer() { return _gmshServer; }
    void setGmshServer(GmshServer *server) { _gmshServer = server; }
    virtual bool run() = 0;
    virtual bool kill() = 0;
  };

  // The remote part of a network client.
  class remoteNetworkClient : public client {
  private:
    // address (inet:port or unix socket) of the server
    std::string _serverAddress;
    // underlying GmshClient
    GmshClient *_gmshClient;
    // number of subclients
    int _numSubClients;
    template <class T> bool _set(const T &p, bool withChoices = true)
    {
      if(!_gmshClient) return false;
      std::string msg = p.toChar();
      _gmshClient->SendMessage(withChoices ?
                                 GmshSocket::GMSH_PARAMETER :
                                 GmshSocket::GMSH_PARAMETER_WITHOUT_CHOICES,
                               (int)msg.size(), &msg[0]);
      return true;
    }
    template <class T>
    bool _get(std::vector<T> &ps, const std::string &name = "",
              bool withChoices = true)
    {
      ps.clear();
      if(!_gmshClient) return false;
      T p(name);
      std::string msg = p.toChar();
      if(name.size())
        _gmshClient->SendMessage(
          withChoices ? GmshSocket::GMSH_PARAMETER_QUERY :
                        GmshSocket::GMSH_PARAMETER_QUERY_WITHOUT_CHOICES,
          (int)msg.size(), &msg[0]);
      else // get all parameters
        _gmshClient->SendMessage(GmshSocket::GMSH_PARAMETER_QUERY_ALL,
                                 (int)msg.size(), &msg[0]);

      while(1) {
        // stop if we have no communications for 5 minutes
        int ret = _gmshClient->Select(500, 0);
        if(!ret) {
          _gmshClient->Info("Timeout: aborting remote get");
          return false;
        }
        else if(ret < 0) {
          _gmshClient->Error("Error on select: aborting remote get");
          return false;
        }
        int type, length, swap;
        if(!_gmshClient->ReceiveHeader(&type, &length, &swap)) {
          _gmshClient->Error(
            "Did not receive message header: aborting remote get");
          return false;
        }
        std::string msg(length, ' ');
        if(!_gmshClient->ReceiveMessage(length, &msg[0])) {
          _gmshClient->Error(
            "Did not receive message body: aborting remote get");
          return false;
        }
        if(type == GmshSocket::GMSH_PARAMETER) {
          T p;
          p.fromChar(msg);
          ps.push_back(p);
          return true;
        }
        if(type == GmshSocket::GMSH_PARAMETER_QUERY_ALL) {
          T p;
          p.fromChar(msg);
          ps.push_back(p);
          // do NOT return until all parameters have been downloaded
        }
        else if(type == GmshSocket::GMSH_PARAMETER_QUERY_END) {
          // all parameters have been sent
          return true;
        }
        else if(type == GmshSocket::GMSH_PARAMETER_NOT_FOUND) {
          // parameter not found
          return true;
        }
        else if(type == GmshSocket::GMSH_INFO) {
          return true;
        }
        else {
          _gmshClient->Error("Unknown message type: aborting remote get");
          return false;
        }
      }
      return true;
    }

  public:
    void waitOnSubClients()
    {
      if(!_gmshClient) return;
      while(_numSubClients > 0) {
        int ret = _gmshClient->Select(500, 0);
        if(!ret) {
          _gmshClient->Info("Timeout: aborting wait on subclients");
          return;
        }
        else if(ret < 0) {
          _gmshClient->Error("Error on select: aborting wait on subclients");
          return;
        }
        int type, length, swap;
        if(!_gmshClient->ReceiveHeader(&type, &length, &swap)) {
          _gmshClient->Error(
            "Did not receive message header: aborting wait on subclients");
          return;
        }
        std::string msg(length, ' ');
        if(!_gmshClient->ReceiveMessage(length, &msg[0])) {
          _gmshClient->Error(
            "Did not receive message body: aborting wait on subclients");
          return;
        }
        if(type == GmshSocket::GMSH_STOP) _numSubClients -= 1;
      }
    }

  public:
    remoteNetworkClient(const std::string &name,
                        const std::string &serverAddress)
      : client(name), _serverAddress(serverAddress), _numSubClients(0)
    {
      _gmshClient = new GmshClient();
      if(_gmshClient->Connect(_serverAddress.c_str()) < 0) {
        delete _gmshClient;
        _gmshClient = nullptr;
      }
      else {
        _gmshClient->Start();
      }
    }
    virtual ~remoteNetworkClient()
    {
      if(_gmshClient) {
        waitOnSubClients();
        _gmshClient->Stop();
        _gmshClient->Disconnect();
        delete _gmshClient;
        _gmshClient = nullptr;
      }
    }
    GmshClient *getGmshClient() { return _gmshClient; }
    virtual bool isNetworkClient() { return true; }
    virtual bool clear(const std::string &name = "")
    {
      if(!_gmshClient) return false;
      std::string msg = name;
      if(msg.empty()) msg = "*";
      _gmshClient->SendMessage(GmshSocket::GMSH_PARAMETER_CLEAR,
                               (int)msg.size(), &msg[0]);
      return true;
    }
    virtual bool set(const number &p) { return _set(p); }
    virtual bool set(const string &p) { return _set(p); }
    virtual bool get(std::vector<number> &ps, const std::string &name = "")
    {
      return _get(ps, name);
    }
    virtual bool get(std::vector<string> &ps, const std::string &name = "")
    {
      return _get(ps, name);
    }
    virtual bool setAndAppendChoices(const number &p)
    {
      // this will send the parameter without choices, using
      // GMSH_PARAMETER_WITHOUT_CHOICES instead of GMSH_PARAMETER; the ONELAB
      // server will then append the value to the choices server-side.
      return _set(p, false);
    }
    virtual bool setAndAppendChoices(const string &p)
    {
      // idem
      return _set(p, false);
    }
    virtual bool getWithoutChoices(std::vector<number> &ps,
                                   const std::string &name = "")
    {
      return _get(ps, name, false);
    }
    virtual bool getWithoutChoices(std::vector<string> &ps,
                                   const std::string &name = "")
    {
      return _get(ps, name, false);
    }
    void sendInfo(const std::string &msg)
    {
      if(_gmshClient) _gmshClient->Info(msg.c_str());
    }
    void sendWarning(const std::string &msg)
    {
      if(_gmshClient) _gmshClient->Warning(msg.c_str());
    }
    void sendError(const std::string &msg)
    {
      if(_gmshClient) _gmshClient->Error(msg.c_str());
    }
    void sendProgress(const std::string &msg)
    {
      if(_gmshClient) _gmshClient->Progress(msg.c_str());
    }
    void sendMergeFileRequest(const std::string &msg)
    {
      if(_gmshClient) _gmshClient->MergeFile(msg.c_str());
    }
    void sendOpenProjectRequest(const std::string &msg)
    {
      if(_gmshClient) _gmshClient->OpenProject(msg.c_str());
    }
    void sendParseStringRequest(const std::string &msg)
    {
      if(_gmshClient) _gmshClient->ParseString(msg.c_str());
    }
    void runNonBlockingSubClient(const std::string &name,
                                 const std::string &command)
    {
#if !defined(BUILD_IOS)
      if(!_gmshClient) {
        int res = system(command.c_str());
        if(res) {
          // report error
        }
        return;
      }
#endif
      std::string msg = name + parameter::charSep() + command;
      _gmshClient->SendMessage(GmshSocket::GMSH_CONNECT, (int)msg.size(),
                               &msg[0]);
      _numSubClients += 1;
    }
    void runSubClient(const std::string &name, const std::string &command)
    {
      runNonBlockingSubClient(name, command);
      waitOnSubClients();
    }
  };

} // namespace onelab

#endif
