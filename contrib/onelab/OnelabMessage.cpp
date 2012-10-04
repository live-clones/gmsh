// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <algorithm>
#include "OnelabMessage.h"
#include "GmshSocket.h"
#include "OS.h"

#define ALWAYS_TRUE 1

onelab::remoteNetworkClient *OLMsg::loader = 0;

int OLMsg::_commRank = 0;
int OLMsg::_commSize = 1;
int OLMsg::_verbosity = 4;
// int OLMsg::_progressMeterStep = 10;
// int OLMsg::_progressMeterCurrent = 0;
// std::map<std::string, double> OLMsg::_timers;
int OLMsg::_warningCount = 0;
int OLMsg::_errorCount = 0;
GmshMessage *OLMsg::_callback = 0;
std::string OLMsg::_commandLine;
std::string OLMsg::_launchDate;
GmshClient *OLMsg::_client = 0;
onelab::client *OLMsg::_onelabClient = 0;
bool OLMsg::hasGmsh=false;
std::set<std::string, fullNameLessThan> OLMsg::_fullNameDict;

#if defined(HAVE_NO_VSNPRINTF)
static int vsnprintf(char *str, size_t size, const char *fmt, va_list ap)
{
  if(strlen(fmt) > size - 1){ // just copy the format
    strncpy(str, fmt, size - 1);
    str[size - 1] = '\0';
    return size;
  }
  return vsprintf(str, fmt, ap);
}
#endif

#if defined(_MSC_VER) && (_MSC_VER == 1310) //NET 2003
#define vsnprintf _vsnprintf
#endif

void OLMsg::Init(int argc, char **argv)
{
  time_t now;
  time(&now);
  _launchDate = ctime(&now);
  _launchDate.resize(_launchDate.size() - 1);
  _commandLine.clear();
  for(int i = 0; i < argc; i++){
    if(i) _commandLine += " ";
    _commandLine += argv[i];
  }
}

void OLMsg::Exit(int level)
{
  if(level){
    exit(level);
  }
  exit(_errorCount);
}

void OLMsg::Fatal(const char *fmt, ...)
{
  _errorCount++;

  char str[1024];
  va_list args;
  va_start(args, fmt);
  vsnprintf(str, sizeof(str), fmt, args);
  va_end(args);

  if(_callback) (*_callback)("Fatal", str);
  if(_client) _client->Error(str);

  if(ALWAYS_TRUE){
    if(_commSize > 1)
      fprintf(stderr, "Fatal   : [On processor %d] %s\n", _commRank, str);
    else
      fprintf(stderr, "Fatal   : %s\n", str);
   fflush(stderr);
  }

  OLMsg::SetOnelabString("MetaModel/STATUS","STOP");
  FinalizeClient();
  FinalizeOnelab();
  delete loader;
  Exit(1);
}

void OLMsg::Error(const char *fmt, ...)
{
  _errorCount++;

  if(_verbosity < 1) return;

  char str[1024];
  va_list args;
  va_start(args, fmt);
  vsnprintf(str, sizeof(str), fmt, args);
  va_end(args);

  if(_callback) (*_callback)("Error", str);
  if(_client) _client->Error(str);

  if(ALWAYS_TRUE){
    if(_commSize > 1)
      fprintf(stderr, "Error   : [On processor %d] %s\n", _commRank, str);
    else
      fprintf(stderr, "Error   : %s\n", str);
    fflush(stderr);
  }
}

void OLMsg::Warning(const char *fmt, ...)
{
  _warningCount++;

  if(_commRank || _verbosity < 2) return;

  char str[1024];
  va_list args;
  va_start(args, fmt);
  vsnprintf(str, sizeof(str), fmt, args);
  va_end(args);

  if(_callback) (*_callback)("Warning", str);
  if(_client) _client->Warning(str);

  if(ALWAYS_TRUE){
    fprintf(stderr, "Warning : %s\n", str);
    fflush(stderr);
  }
}



void OLMsg::Info(const char *fmt, ...)
{
  if(_commRank || _verbosity < 3) return;

  char str[1024];
  va_list args;
  va_start(args, fmt);
  vsnprintf(str, sizeof(str), fmt, args);
  va_end(args);

  if(_callback) (*_callback)("Info", str);
  if(_client) _client->Info(str);

  if(ALWAYS_TRUE){
    fprintf(stdout, "Onelab  : %s\n", str);
    fflush(stdout);
  }
}

void OLMsg::Direct(const char *fmt, ...)
{
  if(_commRank || _verbosity < 3) return;

  char str[1024];
  va_list args;
  va_start(args, fmt);
  vsnprintf(str, sizeof(str), fmt, args);
  va_end(args);

  Direct(3, str);
}

void OLMsg::Direct(int level, const char *fmt, ...)
{
  if(_commRank || _verbosity < level) return;

  char str[1024];
  va_list args;
  va_start(args, fmt);
  vsnprintf(str, sizeof(str), fmt, args);
  va_end(args);

  if(_callback) (*_callback)("Direct", str);
  if(_client) _client->Info(str);

  if(ALWAYS_TRUE){
    fprintf(stdout, "%s\n", str);
    fflush(stdout);
  }
}

void OLMsg::StatusBar(int num, bool log, const char *fmt, ...)
{
  if(_commRank || _verbosity < 3) return;
  if(num < 1 || num > 3) return;

  char str[1024];
  va_list args;
  va_start(args, fmt);
  vsnprintf(str, sizeof(str), fmt, args);
  va_end(args);

  if(_callback && log) (*_callback)("Info", str);
  if(_client && log) _client->Info(str);

  if(log && ALWAYS_TRUE){
    fprintf(stdout, "Info    : %s\n", str);
    fflush(stdout);
  }
}

/*
void OLMsg::Debug(const char *fmt, ...)
{
  if(_verbosity < 99) return;

  char str[1024];
  va_list args;
  va_start(args, fmt);
  vsnprintf(str, sizeof(str), fmt, args);
  va_end(args);

  if(_callback) (*_callback)("Debug", str);
  if(_client) _client->Info(str);

  if(ALWAYS_TRUE){
    if(_commSize > 1)
      fprintf(stdout, "Debug   : [On processor %d] %s\n", _commRank, str);
    else
      fprintf(stdout, "Debug   : %s\n", str);
    fflush(stdout);
  }
}

void OLMsg::ProgressMeter(int n, int N, const char *fmt, ...)
{
  if(_commRank || _verbosity < 3) return;

  double percent = 100. * (double)n/(double)N;

  if(percent >= _progressMeterCurrent){
    char str[1024];
    va_list args;
    va_start(args, fmt);
    vsnprintf(str, sizeof(str), fmt, args);
    va_end(args);

    if(strlen(fmt)) strcat(str, " ");

    char str2[1024];
    sprintf(str2, "(%d %%)", _progressMeterCurrent);
    strcat(str, str2);

    if(_client) _client->Progress(str);

    if(ALWAYS_TRUE){
      fprintf(stdout, "%s                     \r", str);
      fflush(stdout);
    }

    while(_progressMeterCurrent < percent)
      _progressMeterCurrent += _progressMeterStep;
  }

  if(n > N - 1){
    if(_client) _client->Progress("Done!");

    if(ALWAYS_TRUE){
      fprintf(stdout, "Done!                                              \r");
      fflush(stdout);
    }
  }
}

void OLMsg::PrintTimers()
{
  // do a single stdio call!
  std::string str;
  for(std::map<std::string, double>::iterator it = _timers.begin();
      it != _timers.end(); it++){
    if(it != _timers.begin()) str += ", ";
    char tmp[256];
    sprintf(tmp, "%s = %gs ", it->first.c_str(), it->second);
    str += std::string(tmp);
  }
  if(!str.size()) return;

  if(ALWAYS_TRUE){
    if(_commSize > 1)
      fprintf(stdout, "Timers  : [On processor %d] %s\n", _commRank, str.c_str());
    else
      fprintf(stdout, "Timers  : %s\n", str.c_str());
    fflush(stdout);
  }
}

void OLMsg::PrintErrorCounter(const char *title)
{
  if(_commRank || _verbosity < 1) return;
  if(!_warningCount && !_errorCount) return;

  std::string prefix = _errorCount ? "Error   : " : "Warning : ";
  std::string help("Check the full log for details");
  std::string line(std::max(strlen(title), help.size()), '-');
  char warn[128], err[128];
  sprintf(warn, "%5d warning%s", _warningCount, _warningCount == 1 ? "" : "s");
  sprintf(err, "%5d error%s", _errorCount, _errorCount == 1 ? "" : "s");

  if(ALWAYS_TRUE){
    fprintf(stderr, "%s\n%s\n%s\n%s\n%s\n%s\n", (prefix + line).c_str(),
            (prefix + title).c_str(), (prefix + warn).c_str(),
            (prefix + err).c_str(), (prefix + help).c_str(),
            (prefix + line).c_str());
    fflush(stderr);
  }
}

double OLMsg::GetValue(const char *text, double defaultval)
{
  printf("%s (default=%.16g): ", text, defaultval);
  char str[256];
  char *ret = fgets(str, sizeof(str), stdin);
  if(!ret || !strlen(str) || !strcmp(str, "\n"))
    return defaultval;
  else
    return atof(str);
}

std::string OLMsg::GetString(const char *text, std::string defaultval)
{
  printf("%s (default=%s): ", text, defaultval.c_str());
  char str[256];
  char *ret = fgets(str, sizeof(str), stdin);
  if(!ret || !strlen(str) || !strcmp(str, "\n"))
    return defaultval;
  else
    return std::string(str);
}

int OLMsg::GetAnswer(const char *question, int defaultval, const char *zero,
                   const char *one, const char *two)
{
  if(two)
    printf("%s\n\n0=[%s] 1=[%s] 2=[%s] (default=%d): ", question,
           zero, one, two, defaultval);
  else
    printf("%s\n\n0=[%s] 1=[%s] (default=%d): ", question,
           zero, one, defaultval);
  char str[256];
  char *ret = fgets(str, sizeof(str), stdin);
  if(!ret || !strlen(str) || !strcmp(str, "\n"))
    return defaultval;
  else
    return atoi(ret);
}

void OLMsg::InitClient(std::string sockname)
{
  if(_client) delete _client;
  _client = new GmshClient();
  if(_client->Connect(sockname.c_str()) < 0){
    OLMsg::Error("Unable to connect to server on %s", sockname.c_str());
    delete _client;
    _client = 0;
  }
  else
    _client->Start();
}

void OLMsg::Barrier()
{
}
*/
void OLMsg::FinalizeClient()
{
  if(_client){
    _client->Stop();
    _client->Disconnect();
    delete _client;
  }
  _client = 0;
}

void OLMsg::InitializeOnelab(const std::string &name, const std::string &sockname)
{
  if(_onelabClient) delete _onelabClient;
  if (sockname.empty())
    _onelabClient = new onelab::localClient(name);
  else{
    onelab::remoteNetworkClient *c =
      new onelab::remoteNetworkClient(name, sockname);
    _onelabClient = c;
    _client = c->getGmshClient();
  }
}

double OLMsg::GetOnelabNumber(std::string name)
{
  if(_onelabClient){
    std::vector<onelab::number> ps;
    _onelabClient->get(ps, name);
    if(ps.size())
      return ps[0].getValue();
  }
  return 0;
}

void OLMsg::GetOnelabNumber(std::string name, double *val)
{
  if(_onelabClient){
    std::vector<onelab::number> ps;
    _onelabClient->get(ps, name);
    if(ps.size()){
      *val = ps[0].getValue();
      return;
    }
  }
  *val = 0;
}

void OLMsg::SetOnelabNumber(std::string name, double val, bool visible)
{
  if(_onelabClient){
    std::vector<onelab::number> numbers;
    _onelabClient->get(numbers, name);
    if(numbers.empty()){
      numbers.resize(1);
      numbers[0].setName(name);
    }
    numbers[0].setValue(val);
    numbers[0].setVisible(visible);
    _onelabClient->set(numbers[0]);
  }
}

std::string OLMsg::GetOnelabString(std::string name)
{
  std::string str="";
  if(_onelabClient){
    std::vector<onelab::string> ps;
    _onelabClient->get(ps, name);
    if(ps.size() && ps[0].getValue().size())
      str = ps[0].getValue();
  }
  return str;
}

bool OLMsg::GetOnelabChoices(std::string name, std::vector<std::string> &choices){
  if(_onelabClient){
    std::vector<onelab::string> ps;
    _onelabClient->get(ps, name);
    if(ps.size() && ps[0].getValue().size()){
      choices=ps[0].getChoices();
      return true;
    }
  }
  return false;
}

void OLMsg::SetOnelabString(std::string name, std::string val, bool visible)
{
  if(_onelabClient){
    std::vector<onelab::string> strings;
    _onelabClient->get(strings, name);
    if(strings.empty()){
      strings.resize(1);
      strings[0].setName(name);
    }
    strings[0].setValue(val);
    strings[0].setVisible(visible);
    _onelabClient->set(strings[0]);
  }
}

void OLMsg::SetOnelabAttributeString(std::string name,
				   std::string attrib,std::string val){
  if(_onelabClient){
    std::vector<onelab::string> ps;
    _onelabClient->get(ps, name);
    if(ps.size()){
      ps[0].setAttribute(attrib,val);
    }
  }
}
std::string OLMsg::GetOnelabAttributeString(std::string name,std::string attrib){
  std::string str="";
  if(_onelabClient){
    std::vector<onelab::string> ps;
    _onelabClient->get(ps, name);
    if(ps.size())
      str = ps[0].getAttribute(attrib);
  }
  return str;
}
std::string OLMsg::GetOnelabAttributeNumber(std::string name,std::string attrib){
  std::string str="";
  if(_onelabClient){
    std::vector<onelab::number> ps;
    _onelabClient->get(ps, name);
    if(ps.size())
      str = ps[0].getAttribute(attrib);
  }
  return str;
}

void OLMsg::AddOnelabNumberChoice(std::string name, double val)
{
  if(_onelabClient){
    std::vector<double> choices;
    std::vector<onelab::number> ps;
    _onelabClient->get(ps, name);
    if(ps.size()){
      choices = ps[0].getChoices();
    }
    else{
      ps.resize(1);
      ps[0].setName(name);
    }
    ps[0].setAttribute("Highlight","Coral"); // only used by PostArray
    ps[0].setReadOnly(false);
    ps[0].setVisible(true);
    ps[0].setValue(val);
    choices.push_back(val);
    ps[0].setChoices(choices);
    _onelabClient->set(ps[0]);
  }
}

int fullNameLessThan::compareFullNames(const std::string a, const std::string b) const{
  std::string::const_iterator ita, itb;
  ita=a.begin(); itb=b.begin();
  if( (*ita >= '0') && (*ita <= '9')) ita++;
  if( (*itb >= '0') && (*itb <= '9')) itb++;

  while( (ita<a.end()) && (itb<b.end()) && (*ita == *itb) ){
    if(*ita == '/'){
      ita++;
      if( (*ita >= '0') && (*ita <= '9')) ita++;
    }
    else
      ita++;

    if(*itb == '/'){
      itb++;
      if( (*itb >= '0') && (*itb <= '9')) itb++;
    }
    else
      itb++;
  }
  return *ita < *itb ;
}
void OLMsg::recordFullName(const std::string &name){
  OLMsg::_fullNameDict.insert(name);
}
std::string OLMsg::obtainFullName(const std::string &name){
  std::set<std::string, fullNameLessThan>::iterator it;

  // fullNameLessThan* comp=new fullNameLessThan;
  // std::cout << "Dict=" << OLMsg::_fullNameDict.size() << std::endl;
  // std::cout << "Looking for " << name << std::endl;
  // for ( it=OLMsg::_fullNameDict.begin() ; it != OLMsg::_fullNameDict.end(); it++ )
  //   std::cout << *it << " <" << comp->operator()(*it,name) << ">" << std::endl;
  // std::cout << std::endl;

  it = OLMsg::_fullNameDict.find(name);
  if(it == OLMsg::_fullNameDict.end()){
    return name;
  }
  else{
    return *it;
  }
}

void OLMsg::SendMergeFileRequest(const std::string &name){
  _onelabClient->sendMergeFileRequest(name);
}

int OLMsg::Synchronize_Down(){
  OLMsg::_fullNameDict.clear();
  std::vector<onelab::number> numbers;
  loader->get(numbers,"");
  if(numbers.size()){
    for(std::vector<onelab::number>::const_iterator it = numbers.begin();
	it != numbers.end(); it++){
      if(_onelabClient) _onelabClient->set(*it);
      OLMsg::recordFullName((*it).getName());
      //std::cout << "FHF d " << (*it).getName() << "=" << (*it).getChanged() << std::endl;
    }
  }
  std::vector<onelab::string> strings;
  loader->get(strings,"");
  if(strings.size()){
    for(std::vector<onelab::string>::const_iterator it = strings.begin();
  	it != strings.end(); it++){
      if(_onelabClient) _onelabClient->set(*it);
      OLMsg::recordFullName((*it).getName());
      //std::cout << "FHF d " << (*it).getName() << "=" << (*it).getChanged() << std::endl;
    }
  }
  std::vector<onelab::region> regions;
  loader->get(regions,"");
  if(regions.size()){
    for(std::vector<onelab::region>::const_iterator it = regions.begin();
  	it != regions.end(); it++){
      if(_onelabClient) _onelabClient->set(*it);
      OLMsg::recordFullName((*it).getName());
    }
  }
  return(numbers.size()+strings.size()+regions.size());
}

int OLMsg::Synchronize_Up(){
  std::vector<onelab::number> numbers;
  _onelabClient->get(numbers,"");
  if(numbers.size()){
    for(std::vector<onelab::number>::const_iterator it = numbers.begin();
  	it != numbers.end(); it++){
      loader->set(*it);
      //std::cout << "FHF u " << (*it).getName() << "="
      //<< (*it).getChanged() << std::endl;
    }
  }
  loader->get(numbers,"");
  if(numbers.size()){
    for(std::vector<onelab::number>::const_iterator it = numbers.begin();
  	it != numbers.end(); it++){
      //std::cout << "FHF control " << (*it).getName() << "="
      //<< (*it).getChanged() << std::endl;
    }
  }

  std::vector<onelab::string> strings;
  _onelabClient->get(strings,"");
  if(strings.size()){
    for(std::vector<onelab::string>::const_iterator it = strings.begin();
	it != strings.end(); it++){
      loader->set(*it);
      //std::cout << "FHF u " << (*it).getName() << "=" << (*it).getChanged() << std::endl;
    }
  }
  std::vector<onelab::region> regions;
  _onelabClient->get(regions,"");
  if(regions.size()){
    for(std::vector<onelab::region>::const_iterator it = regions.begin();
	it != regions.end(); it++){
      loader->set(*it);
    }
  }
  return(numbers.size()+strings.size()+regions.size());
}

void OLMsg::FinalizeOnelab(){
  if(_onelabClient){
    delete _onelabClient;
    _onelabClient = 0;
    _client = 0;
  }
}
