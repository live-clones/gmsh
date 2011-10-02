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
    // the name of the parameter, including its "path" in the
    // parameter hierarchy. The path separator '/' can be followed by
    // a number to force ordering (hence a parameter name cannot start
    // with a number).
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
    static std::string getNextToken(const std::string &msg, std::string::size_type &first)
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
    double _value;
    double _defaultValue, _min, _max, _step;
    std::vector<double> _choices;
  public:
    number(const std::string &name="", double defaultValue=0.,
           const std::string &shortHelp="", const std::string &help="") 
      : parameter(name, shortHelp, help), _value(defaultValue), 
        _defaultValue(defaultValue), _min(1.), _max(0.), _step(0.) {}
    void setValue(double value){ _value = value; }
    void setMin(double min){ _min = min; }
    void setMax(double max){ _min = max; }
    void setStep(double step){ _step = step; }
    void setChoices(std::vector<double> &choices){ _choices = choices; }
    std::string getType() const { return "number"; }
    double getValue() const { return _value; }
    double getDefaultValue() const { return _defaultValue; }
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
    void setChoices(std::vector<std::string> &choices){ _choices = choices; }
    std::string getType() const { return "string"; }
    const std::string &getValue() const { return _value; }
    const std::string &getDefaultValue() const { return _defaultValue; }
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
        _defaultValue(defaultValue)
    {
    }
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
    // use the new value but make sure to add new clients if
    // necessary.  This needs to be locked to avoid race conditions
    // when several clients try to set a parameter at the same time
    template <class T> bool _set(T &p, std::set<T*, parameterLessThan> &parameters)
    {
      std::set<std::string> clients;
      typename std::set<T*, parameterLessThan>::iterator it = parameters.find(&p);
      if(it != parameters.end()){
        parameters.erase(it);
        T* oldp = *it;
        clients = oldp->getClients();
        delete oldp;
      }
      T* newp = new T(p);
      newp->addClients(clients);
      parameters.insert(newp);
      return true;
    }
    // get the parameter matching the given name, or all the
    // parameters in the category if no name is given
    template <class T> bool _get(std::vector<T> &p, const std::string &name,
                                 std::set<T*, parameterLessThan> &parameters)
    {
      if(name.empty()){
        for(typename std::set<T*, parameterLessThan>::iterator it = parameters.begin();
            it != parameters.end(); it++)
          p.push_back(**it);
      }
      else{
        T tmp(name);
        typename std::set<T*, parameterLessThan>::iterator it = parameters.find(&tmp);
        if(it != parameters.end())
          p.push_back(**it);
      }
      return true;
    }
  public:
    parameterSpace(){}
    ~parameterSpace()
    {
      for(std::set<number*, parameterLessThan>::iterator it = _numbers.begin();
          it != _numbers.end(); it++)
        delete *it;
      for(std::set<string*, parameterLessThan>::iterator it = _strings.begin();
          it != _strings.end(); it++)
        delete *it;
      for(std::set<region*, parameterLessThan>::iterator it = _regions.begin();
          it != _regions.end(); it++)
        delete *it;
      for(std::set<function*, parameterLessThan>::iterator it = _functions.begin();
          it != _functions.end(); it++)
        delete *it;
    }
    bool set(number &p){ return _set(p, _numbers); }
    bool set(string &p){ return _set(p, _strings); }
    bool set(region &p){ return _set(p, _regions); }
    bool set(function &p){ return _set(p, _functions); }
    bool get(std::vector<number> &p, const std::string &name="")
    {
      return _get(p, name, _numbers); 
    }
    bool get(std::vector<string> &p, const std::string &name="")
    {
      return _get(p, name, _strings); 
    }
    bool get(std::vector<region> &p, const std::string &name="")
    {
      return _get(p, name, _regions); 
    }
    bool get(std::vector<function> &p, const std::string &name="")
    {
      return _get(p, name, _functions);
    }
    void print()
    {
      for(std::set<number*, parameterLessThan>::iterator it = _numbers.begin();
          it != _numbers.end(); it++) std::cout << (*it)->toChar() << std::endl;
      for(std::set<string*, parameterLessThan>::iterator it = _strings.begin();
          it != _strings.end(); it++) std::cout << (*it)->toChar() << std::endl;
      for(std::set<region*, parameterLessThan>::iterator it = _regions.begin();
          it != _regions.end(); it++) std::cout << (*it)->toChar() << std::endl;
      for(std::set<function*, parameterLessThan>::iterator it = _functions.begin();
          it != _functions.end(); it++) std::cout << (*it)->toChar() << std::endl;
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
    template <class T> bool set(T &p)
    {
      return _parameterSpace.set(p); 
    }
    template <class T> bool get(std::vector<T> &p, const std::string &name="")
    {
      return _parameterSpace.get(p, name); 
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
    void print(){ _parameterSpace.print(); }
  };
    
  class localClient : public client{
  protected:
    // the pointer to the server
    server *_server;
  public:
    localClient(const std::string &name) : client(name)
    {
      _server = server::instance();
      _server->registerClient(this);
    }
    virtual ~localClient(){}
    template <class T> bool set(T &parameter)
    {
      parameter.addClient(_name);
      _server->set(parameter);
      return true;
    }
    template <class T> bool get(std::vector<T> &parameters,
                                const std::string &name="")
    {
      _server->get(parameters, name);
      return true;
    }
    void print(){ _server->print(); }
  };

  class localNetworkClient : public localClient{
  private:
    // command line to launch the remote network client
    std::string _commandLine;
    // pid of the remote network client
    int _pid;
  public:
    localNetworkClient(const std::string &name, const std::string &commandLine)
      : localClient(name), _commandLine(commandLine){}
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
    template <class T> bool set(T &parameter)
    {
      if(!_gmshClient) return false;
      parameter.addClient(_name);
      std::string msg = parameter.toChar();
      _gmshClient->SendMessage(GmshSocket::GMSH_PARAMETER, msg.size(), &msg[0]);
      return true;
    }
    template <class T> bool get(std::vector<T> &parameters, 
                                const std::string &name="")
    {
      if(!_gmshClient) return false;
      T parameter(name);
      parameter.addClient(_name);
      std::string msg = parameter.toChar();
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
          parameters.push_back(p);
          return true;
        }
        else{
          _gmshClient->Error("Unknown message type: aborting remote get");
          return false;
        }
      }
      return true;
    }
    void sendInfo(const std::string &msg){ _gmshClient->Info(msg.c_str()); }
    void sendWarning(const std::string &msg){ _gmshClient->Warning(msg.c_str()); }
    void sendError(const std::string &msg){ _gmshClient->Error(msg.c_str()); }
    void sendProgress(const std::string &msg){ _gmshClient->Progress(msg.c_str()); }
    void sendMergeFileRequest(const std::string &msg){ _gmshClient->MergeFile(msg.c_str()); }
    void sendParseStringRequest(const std::string &msg){ _gmshClient->ParseString(msg.c_str()); }
  };

}

#endif
