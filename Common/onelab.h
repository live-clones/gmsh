// ONELAB - Copyright (C) 2011 ULg-UCL
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use, copy,
// modify, merge, publish, distribute, and/or sell copies of the
// Software, and to permit persons to whom the Software is furnished
// to do so, provided that the above copyright notice(s) and this
// permission notice appear in all copies of the Software and that
// both the above copyright notice(s) and this permission notice
// appear in supporting documentation.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT OF THIRD PARTY RIGHTS. IN NO EVENT SHALL THE
// COPYRIGHT HOLDER OR HOLDERS INCLUDED IN THIS NOTICE BE LIABLE FOR
// ANY CLAIM, OR ANY SPECIAL INDIRECT OR CONSEQUENTIAL DAMAGES, OR ANY
// DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
// WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
// ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
// OF THIS SOFTWARE.

#ifndef _ONELAB_H_
#define _ONELAB_H_

#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <sstream>
#include "GmshSocket.h";

namespace onelab{

  // The base parameter class.
  class parameter{
  private:
    // the name of the parameter, including its '/'-separated path in
    // the parameter hierarchy. Parameters or subpaths can start with
    // numbers to force their relative ordering.
    std::string _name;
    // optional help strings
    std::string _shortHelp, _help;
    // client code(s) for which this parameter makes sense
    std::set<std::string> _clients;
  public:
    parameter(const std::string &name="", const std::string &shortHelp="", 
              const std::string &help="")
      : _name(name), _shortHelp(shortHelp), _help(help){}
    void setName(const std::string &name){ _name = name; }
    void setShortHelp(const std::string &shortHelp){ _shortHelp = shortHelp; }
    void setHelp(const std::string &help){ _help = help; }
    void setClients(std::set<std::string> &clients){ _clients = clients; }
    void addClient(const std::string &client){ _clients.insert(client); }
    void addClients(std::set<std::string> &clients)
    { 
      _clients.insert(clients.begin(), clients.end()); 
    }
    bool hasClient(const std::string &client)
    {
      return (_clients.find(client) != _clients.end());
    }
    virtual std::string getType() const = 0;
    const std::string &getName() const { return _name; }
    const std::string &getShortHelp() const { return _shortHelp; }
    const std::string &getHelp() const { return _help; }
    const std::set<std::string> &getClients() const { return _clients; }
    static char charSep(){ return '|' /* '\0' */; }
    std::string sanitize(const std::string &in)
    {
      std::string out(in);
      for(unsigned int i = 0; i < in.size(); i++)
        if(out[i] == charSep()) out[i] = ' ';
      return out;
    }
    virtual std::string toChar()
    {
      std::ostringstream sstream;
      sstream << getType() << charSep() << sanitize(getName()) << charSep() 
              << sanitize(getShortHelp()) << charSep() << sanitize(getHelp());
      return sstream.str();
    }
    virtual void fromChar(const std::string &msg){}
    static std::string getNextToken(const std::string &msg, 
                                    std::string::size_type &first)
    {
      std::string::size_type last = msg.find_first_of(charSep(), first);
      std::string next = msg.substr(first, last - first);
      first = (last == std::string::npos) ? last : last + 1;
      return next;
    }
    static void getTypeAndNameFromChar(const std::string &msg, std::string &type, 
                                       std::string &name)
    {
      std::string::size_type first = 0;
      type = getNextToken(msg, first);
      name = getNextToken(msg, first);
    }
  };
  
  class parameterLessThan{
  public:
    bool operator()(const parameter *p1, const parameter *p2) const
    {
      return p1->getName() < p2->getName();
    }
  };

  // The number class. Numbers are stored internally as double
  // precision real numbers. Currently all more complicated types
  // (complex numbers, vectors, etc.) are supposed to be encapsulated
  // in functions. We will probably add more base types in the future
  // to make the interface nicer.
  class number : public parameter{
  private:
    double _value, _defaultValue, _min, _max, _step;
    std::vector<double> _choices;
  public:
    number(const std::string &name="", double defaultValue=0.,
           const std::string &shortHelp="", const std::string &help="") 
      : parameter(name, shortHelp, help), _value(defaultValue), 
        _defaultValue(defaultValue), _min(1.), _max(0.), _step(0.) {}
    void setValue(double value){ _value = value; }
    void setDefaultValue(double value){ _defaultValue = value; }
    void setMin(double min){ _min = min; }
    void setMax(double max){ _max = max; }
    void setStep(double step){ _step = step; }
    void setChoices(std::vector<double> &choices){ _choices = choices; }
    std::string getType() const { return "number"; }
    double getValue() const { return _value; }
    double getDefaultValue() const { return _defaultValue; }
    double getMin(){ return _min; }
    double getMax(){ return _max; }
    double getStep(){ return _step; }
    const std::vector<double> &getChoices(){ return _choices; }
    std::string toChar()
    {
      std::ostringstream sstream;
      sstream << parameter::toChar() << charSep() << _value << charSep() 
              << _defaultValue << charSep() << _min << charSep() << _max 
              << charSep() << _step << charSep() << _choices.size() << charSep();
      for(unsigned int i = 0; i < _choices.size(); i++)
        sstream << _choices[i] << charSep();
      sstream << getClients().size() << charSep();
      for(std::set<std::string>::iterator it = getClients().begin();
          it != getClients().end(); it++)
        sstream << *it << charSep();
      return sstream.str();
    }
    void fromChar(const std::string &msg)
    {
      std::string::size_type pos = 0;
      if(getNextToken(msg, pos) != getType()) return;
      setName(getNextToken(msg, pos));
      setShortHelp(getNextToken(msg, pos));
      setHelp(getNextToken(msg, pos));
      setValue(atof(getNextToken(msg, pos).c_str()));
      setDefaultValue(atof(getNextToken(msg, pos).c_str()));
      setMin(atof(getNextToken(msg, pos).c_str()));
      setMax(atof(getNextToken(msg, pos).c_str()));
      setStep(atof(getNextToken(msg, pos).c_str()));
      _choices.resize(atoi(getNextToken(msg, pos).c_str()));
      for(unsigned int i = 0; i < _choices.size(); i++)
        _choices[i] = atof(getNextToken(msg, pos).c_str());
    }
  };

  // The string class.
  class string : public parameter{
  private:
    std::string _value;
    std::string _defaultValue;
    std::vector<std::string> _choices;
  public:
    string(const std::string &name="", const std::string &defaultValue="", 
           const std::string &shortHelp="", const std::string &help="") 
      : parameter(name, shortHelp, help), _value(defaultValue), 
        _defaultValue(defaultValue) {}
    void setValue(const std::string &value){ _value = value; }
    void setDefaultValue(const std::string &value){ _defaultValue = value; }
    void setChoices(std::vector<std::string> &choices){ _choices = choices; }
    std::string getType() const { return "string"; }
    const std::string &getValue() const { return _value; }
    const std::string &getDefaultValue() const { return _defaultValue; }
    const std::vector<std::string> &getChoices(){ return _choices; }
    std::string toChar()
    {
      std::ostringstream sstream;
      sstream << parameter::toChar() << charSep() << sanitize(_value) << charSep()
              << sanitize(_defaultValue) << charSep() << _choices.size() << charSep();
      for(unsigned int i = 0; i < _choices.size(); i++)
        sstream << sanitize(_choices[i]) << charSep();
      sstream << getClients().size() << charSep();
      for(std::set<std::string>::iterator it = getClients().begin();
          it != getClients().end(); it++)
        sstream << *it << charSep();
      return sstream.str();
    }
    void fromChar(const std::string &msg)
    {
      std::string::size_type pos = 0;
      if(getNextToken(msg, pos) != getType()) return;
      setName(getNextToken(msg, pos));
      setShortHelp(getNextToken(msg, pos));
      setHelp(getNextToken(msg, pos));
      setValue(getNextToken(msg, pos));
      setDefaultValue(getNextToken(msg, pos));
      _choices.resize(atoi(getNextToken(msg, pos).c_str()));
      for(unsigned int i = 0; i < _choices.size(); i++)
        _choices[i] = getNextToken(msg, pos);
    }
  };

  // The region class. A region can be any kind of geometrical entity.
  class region : public parameter{
  private:
    std::string _value, _defaultValue;
    std::vector<std::string> _choices;
  public:
    region(const std::string &name="", const std::string &defaultValue="",
           const std::string &shortHelp="", const std::string &help="") 
      : parameter(name, shortHelp, help), _value(defaultValue), 
        _defaultValue(defaultValue) {}
    void setValue(const std::string &value){ _value = value; }
    std::string getType() const { return "region"; }
    const std::string &getValue() const { return _value; }
    const std::string &getDefaultValue() const { return _defaultValue; }
    std::string toChar()
    {
      std::ostringstream sstream;
      sstream << parameter::toChar() << charSep() << _value << charSep() 
              << _defaultValue << charSep() << _choices.size() << charSep();
      for(unsigned int i = 0; i < _choices.size(); i++)
        sstream << _choices[i] << charSep();
      sstream << getClients().size() << charSep();
      for(std::set<std::string>::iterator it = getClients().begin();
          it != getClients().end(); it++)
        sstream << *it << charSep();
      return sstream.str();
    }
  };

  // The (possibly piece-wise defined on regions) function
  // class. Currently functions are entirely client-dependent: they
  // are just represented internally as strings. Again, we might want
  // to specialize in the future to make the interface more refined.
  class function : public parameter{
  private:
    std::string _value, _defaultValue;
    std::map<std::string, std::string> _pieceWiseValues;
    std::vector<std::string> _choices;
  public:
    function(const std::string &name="", const std::string &defaultValue="",
             const std::string &shortHelp="", const std::string &help="") 
      : parameter(name, shortHelp, help), _value(defaultValue), 
        _defaultValue(defaultValue) {}
    void setValue(const std::string &value, const std::string &region="")
    {
      if(region.empty())
        _value = value;
      else
        _pieceWiseValues[region] = value;
    }
    std::string getType() const { return "function"; }
    const std::string getValue(const std::string &region="") const
    {
      if(region.size()){
        std::map<std::string, std::string>::const_iterator it =
          _pieceWiseValues.find(region);
        if(it != _pieceWiseValues.end()) return it->second;
        return "";
      }
      else return _value; 
    }
    const std::map<std::string, std::string> &getPieceWiseValues() const 
    {
      return _pieceWiseValues; 
    }
    const std::string &getDefaultValue() const { return _defaultValue; }
    std::string toChar()
    {
      std::ostringstream sstream;
      sstream << parameter::toChar() << charSep() << sanitize(_value) << charSep()
              << sanitize(_defaultValue) << charSep() 
              << _pieceWiseValues.size() << charSep();
        for(std::map<std::string, std::string>::const_iterator it =
              _pieceWiseValues.begin(); it != _pieceWiseValues.end(); it++)
          sstream << sanitize(it->first) << charSep() 
                  << sanitize(it->second) << charSep();
      sstream << _choices.size() << charSep();
      for(unsigned int i = 0; i < _choices.size(); i++)
        sstream << sanitize(_choices[i]) << charSep();
      sstream << getClients().size() << charSep();
      for(std::set<std::string>::iterator it = getClients().begin();
          it != getClients().end(); it++)
        sstream << *it << charSep();
      return sstream.str();
    }
  };

  // The parameter space, i.e., the set of parameters stored and
  // handled by the onelab server.
  class parameterSpace{
  private:
    std::set<number*, parameterLessThan> _numbers;
    std::set<string*, parameterLessThan> _strings;
    std::set<region*, parameterLessThan> _regions;
    std::set<function*, parameterLessThan> _functions;
    // set a parameter in the parameter space; if it already exists,
    // add new clients if necessary.  This needs to be locked to avoid
    // race conditions when several clients try to set a parameter at
    // the same time
    template <class T> bool _set(T &p, std::set<T*, parameterLessThan> &ps,
                                 bool value=true)
    {
      typename std::set<T*, parameterLessThan>::iterator it = ps.find(&p);
      if(it != ps.end()){
        std::set<std::string> clients = p.getClients();
        (*it)->addClients(clients);
        if(value) (*it)->setValue(p.getValue());
      }
      else{
        ps.insert(new T(p));
      }
      return true;
    }
    // get the parameter matching the given name, or all the
    // parameters in the category if no name is given. If we find a
    // given parameter by name, we add the client requesting the
    // parameter to the list of clients for this parameter.
    template <class T> bool _get(std::vector<T> &p, const std::string &name,
                                 const std::string &client,
                                 std::set<T*, parameterLessThan> &ps)
    {
      p.clear();
      if(name.empty()){
        for(typename std::set<T*, parameterLessThan>::iterator it = ps.begin();
            it != ps.end(); it++)
          p.push_back(**it);
      }
      else{
        T tmp(name);
        typename std::set<T*, parameterLessThan>::iterator it = ps.find(&tmp);
        if(it != ps.end()){
          if(client.size()) (*it)->addClient(client);
          p.push_back(**it);
        }
      }
      return true;
    }
    void _getAllParameters(std::set<parameter*> &ps)
    {
      ps.insert(_numbers.begin(), _numbers.end());
      ps.insert(_strings.begin(), _strings.end());
      ps.insert(_regions.begin(), _regions.end());
      ps.insert(_functions.begin(), _functions.end());
    }
  public:
    parameterSpace(){}
    ~parameterSpace()
    {
      std::set<parameter*> ps;
      _getAllParameters(ps);
      for(std::set<parameter*>::iterator it = ps.begin(); it != ps.end(); it++)
        delete *it;
    }
    bool set(number &p, bool value=true){ return _set(p, _numbers, value); }
    bool set(string &p, bool value=true){ return _set(p, _strings, value); }
    bool set(region &p, bool value=true){ return _set(p, _regions, value); }
    bool set(function &p, bool value=true){ return _set(p, _functions, value); }
    bool get(std::vector<number> &ps, const std::string &name="", 
             const std::string &client=""){ return _get(ps, name, client, _numbers); }
    bool get(std::vector<string> &ps, const std::string &name="",
             const std::string &client=""){ return _get(ps, name, client, _strings); }
    bool get(std::vector<region> &ps, const std::string &name="",
             const std::string &client=""){ return _get(ps, name, client, _regions); }
    bool get(std::vector<function> &ps, const std::string &name="",
             const std::string &client=""){ return _get(ps, name, client, _functions); }
    bool hasClient(const std::string &client)
    {
      std::set<parameter*> ps;
      _getAllParameters(ps);
      for(std::set<parameter*>::iterator it = ps.begin(); it != ps.end(); it++)
        if((*it)->hasClient(client)) return true;
      return false;
    }
    std::string toChar()
    {
      std::string s;
      std::set<parameter*> ps;
      _getAllParameters(ps);
      for(std::set<parameter*>::iterator it = ps.begin(); it != ps.end(); it++)
        s += (*it)->toChar() + "\n";
      return s;
    }
  };

  // The onelab client: a class that communicates with the onelab
  // server. Each client should be derived from this one.
  class client{
  protected:
    // the name of the client
    std::string _name;
  public:
    client(const std::string &name) : _name(name){}
    virtual ~client(){}
    std::string getName(){ return _name; }
    virtual bool run(const std::string &what){ return false; }
    virtual bool kill(){ return false; }
    virtual void sendInfo(const std::string &msg){ std::cout << msg << std::endl; }
    virtual void sendWarning(const std::string &msg){ std::cerr << msg << std::endl; }
    virtual void sendError(const std::string &msg){ std::cerr << msg << std::endl; }
    virtual void sendProgress(const std::string &msg){ std::cout << msg << std::endl; }
    virtual void sendMergeFileRequest(const std::string &msg){}
    virtual void sendParseStringRequest(const std::string &msg){}
    virtual void sendVertexArray(const std::string &msg){}
    virtual bool set(number &p, bool value=true) = 0;
    virtual bool set(string &p, bool value=true) = 0;
    virtual bool set(region &p, bool value=true) = 0;
    virtual bool set(function &p, bool value=true) = 0;
    virtual bool get(std::vector<number> &ps, const std::string &name="") = 0;
    virtual bool get(std::vector<string> &ps, const std::string &name="") = 0;
    virtual bool get(std::vector<region> &ps, const std::string &name="") = 0;
    virtual bool get(std::vector<function> &ps, const std::string &name="") = 0;
  };

  // The onelab server: a singleton that stores the parameter space
  // and interacts with onelab clients.
  class server{
  private:
    // the unique server
    static server *_server;
    // the address of the server
    std::string _address;
    // the connected clients, indexed by name
    std::map<std::string, client*> _clients;
    // the parameter space
    parameterSpace _parameterSpace;
  public:
    server(const std::string &address="") : _address(address) {}
    ~server(){}
    static server *instance(const std::string &address="")
    {
      if(!_server) _server = new server(address);
      return _server;
    }
    template <class T> bool set(T &p, bool value=true)
    {
      return _parameterSpace.set(p, value); 
    }
    template <class T> bool get(std::vector<T> &ps, const std::string &name="",
                                const std::string &client="")
    {
      return _parameterSpace.get(ps, name, client); 
    }
    bool registerClient(client *c)
    {
      if(_clients.count(c->getName())) return false;
      _clients[c->getName()] = c;
      return true;
    }
    typedef std::map<std::string, client*>::iterator citer;
    citer firstClient(){ return _clients.begin(); }
    citer lastClient(){ return _clients.end(); }
    citer findClient(const std::string &name){ return _clients.find(name); }
    int getNumClients(){ return _clients.size(); }
    bool dependsOnClient(const std::string &client)
    {
      return _parameterSpace.hasClient(client);
    }
    std::string toChar(){ return _parameterSpace.toChar(); }
  };
    
  class localClient : public client{
  private:
    // the pointer to the server
    server *_server;
    template <class T> bool _set(T &p, bool value=true)
    {
      p.addClient(_name);
      _server->set(p, value);
      return true;
    }
    template <class T> bool _get(std::vector<T> &ps,
                                 const std::string &name="")
    {
      _server->get(ps, name, _name);
      return true;
    }
  public:
    localClient(const std::string &name) : client(name)
    {
      _server = server::instance();
      _server->registerClient(this);
    }
    virtual ~localClient(){}
    virtual bool set(number &p, bool value=true){ return _set(p, value); }
    virtual bool set(string &p, bool value=true){ return _set(p, value); }
    virtual bool set(function &p, bool value=true){ return _set(p, value); }
    virtual bool set(region &p, bool value=true){ return _set(p, value); }
    virtual bool get(std::vector<number> &ps,
                     const std::string &name=""){ return _get(ps, name); }
    virtual bool get(std::vector<string> &ps,
                     const std::string &name=""){ return _get(ps, name); }
    virtual bool get(std::vector<function> &ps,
                     const std::string &name=""){ return _get(ps, name); }
    virtual bool get(std::vector<region> &ps,
                     const std::string &name=""){ return _get(ps, name); }
  };

  class localNetworkClient : public localClient{
  private:
    // command line to launch the remote network client
    std::string _commandLine;
    // pid of the remote network client
    int _pid;
  public:
    localNetworkClient(const std::string &name, const std::string &commandLine)
      : localClient(name), _commandLine(commandLine), _pid(-1) {}
    virtual ~localNetworkClient(){}
    int getPid(){ return _pid; }
    void setPid(int pid){ _pid = pid; }
    virtual bool run(const std::string &what);
    virtual bool kill();
  };

  class remoteNetworkClient : public client{
  private:
    std::string _serverAddress;
    // underlying GmshClient
    GmshClient *_gmshClient;
    template <class T> bool _set(T &p)
    {
      if(!_gmshClient) return false;
      p.addClient(_name);
      std::string msg = p.toChar();
      _gmshClient->SendMessage(GmshSocket::GMSH_PARAMETER, msg.size(), &msg[0]);
      return true;
    }
    template <class T> bool _get(std::vector<T> &ps, 
                                 const std::string &name="")
    {
      ps.clear();
      if(!_gmshClient) return false;
      T p(name);
      p.addClient(_name);
      std::string msg = p.toChar();
      _gmshClient->SendMessage(GmshSocket::GMSH_PARAMETER_QUERY, msg.size(), &msg[0]);
      while(1){
        // stop if we have no communications for 10 secs
        int ret = _gmshClient->Select(10, 0);
        if(!ret){
          _gmshClient->Info("Timout: aborting remote get");
          return false;
        }
        else if(ret < 0){
          _gmshClient->Error("Error on select: aborting remote get");
          return false;
        }
        int type, length, swap;
        if(!_gmshClient->ReceiveHeader(&type, &length, &swap)){
          _gmshClient->Error("Did not receive message header: aborting remote get");
          return false;
        }
        std::string msg(length, ' ');
        if(!_gmshClient->ReceiveMessage(length, &msg[0])){
          _gmshClient->Error("Did not receive message body: aborting remote get");
          return false;
        }
        if(type == GmshSocket::GMSH_PARAMETER){
          T p;
          p.fromChar(msg);
          ps.push_back(p);
          return true;
        }
        else if(type == GmshSocket::GMSH_INFO){
          // parameter not found
          return true;
        }
        else{
          _gmshClient->Error("Unknown message type: aborting remote get");
          return false;
        }
      }
      return true;
    }
  public:
    remoteNetworkClient(const std::string &name, const std::string &serverAddress)
      : client(name), _serverAddress(serverAddress)
    {
      _gmshClient = new GmshClient();
      if(_gmshClient->Connect(_serverAddress.c_str()) < 0){
        delete _gmshClient;
        _gmshClient = 0;
      }
      else{
        _gmshClient->Start();
      }
    }
    virtual ~remoteNetworkClient()
    {
      if(_gmshClient){
        _gmshClient->Stop();
        _gmshClient->Disconnect();
        delete _gmshClient;
        _gmshClient = 0;
      }
    }
    virtual bool set(number &p, bool value=true){ return _set(p); }
    virtual bool set(string &p, bool value=true){ return _set(p); }
    virtual bool set(function &p, bool value=true){ return _set(p); }
    virtual bool set(region &p, bool value=true){ return _set(p); }
    virtual bool get(std::vector<number> &ps, 
                     const std::string &name=""){ return _get(ps, name); }
    virtual bool get(std::vector<string> &ps,
                     const std::string &name=""){ return _get(ps, name); }
    virtual bool get(std::vector<function> &ps, 
                     const std::string &name=""){ return _get(ps, name); }
    virtual bool get(std::vector<region> &ps,
                     const std::string &name=""){ return _get(ps, name); }
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
    void sendParseStringRequest(const std::string &msg)
    {
      if(_gmshClient) _gmshClient->ParseString(msg.c_str()); 
    }
  };

}

#endif
