#include "StringUtils.h"
#include "onelabUtils.h"
#include "OnelabClients.h"
#include "metamodel.h"
#include <algorithm>

onelab::server *onelab::server::_server = 0;
std::string clientName;

std::string stateToChar(){
  std::vector<onelab::number> numbers;
  std::ostringstream sstream;
  onelab::server::instance()->get(numbers);
  for(std::vector<onelab::number>::iterator it = numbers.begin();
      it != numbers.end(); it++)
    sstream << (*it).getValue() << '\t';
  return sstream.str();
}

std::string showParamSpace(){
  std::vector<std::string> parameters=onelab::server::instance()->toChar();
  std::string db = "ONELAB parameter space: size="
    + itoa(onelab::server::instance()->getNumParameters()) + "\n";
  for(unsigned int i = 0; i < parameters.size(); i++)
    db.append(parameters[i] + '\n');
  for(unsigned int i = 0; i < db.size(); i++)
    if(db[i] == onelab::parameter::charSep()) db[i] = ' ';
  return db.c_str();
}

std::string showClientStatus(){
  std::ostringstream sstream;
  std::string name;
  std::cout << "\nONELAB: Present state of the onelab clients" << std::endl;
  for(onelab::server::citer it = onelab::server::instance()->firstClient();
      it != onelab::server::instance()->lastClient(); it++){
    name.assign(it->first);
    sstream << "<" << onelab::server::instance()->getChanged(name) << "> "
	    << name << std::endl;
  }
  return sstream.str();
}

void initializeLoop(const std::string &level)
{
  bool changed = false;
  std::vector<onelab::number> numbers;
  onelab::server::instance()->get(numbers);
  for(unsigned int i = 0; i < numbers.size(); i++){

    if(numbers[i].getAttribute("Loop") == level){
      if(numbers[i].getChoices().size() > 1){
	numbers[i].setIndex(0);
	numbers[i].setValue(numbers[i].getChoices()[0]);
	onelab::server::instance()->set(numbers[i]);
	changed = true;
      }
      else if(numbers[i].getStep() > 0){
	if(numbers[i].getMin() != -onelab::parameter::maxNumber()){
	  numbers[i].setValue(numbers[i].getMin());
	  onelab::server::instance()->set(numbers[i]);
	  changed = true;
	}
      }
      else if(numbers[i].getStep() < 0){
	if(numbers[i].getMax() != onelab::parameter::maxNumber()){
	  numbers[i].setValue(numbers[i].getMax());
	  onelab::server::instance()->set(numbers[i]);
	  changed = true;
	}
      }
    }
  }

  // force this to make sure that we remesh, even if a mesh exists and
  // we did not actually change a Gmsh parameter
  if(changed)
    onelab::server::instance()->setChanged(true, "Gmsh");
}

bool incrementLoop(const std::string &level)
{
  bool recompute = false, loop = false;
  std::vector<onelab::number> numbers;
  onelab::server::instance()->get(numbers);
  for(unsigned int i = 0; i < numbers.size(); i++){
    if(numbers[i].getAttribute("Loop") == level){
      loop = true;

      if(numbers[i].getChoices().size() > 1){
	int j = numbers[i].getIndex() + 1;
	if((j >= 0) && (j < (int)numbers[i].getChoices().size())){
	  numbers[i].setValue(numbers[i].getChoices()[j]);
	  numbers[i].setIndex(j);
	  onelab::server::instance()->set(numbers[i]);
	  OLMsg::Info("Recomputing with %dth choice %s=%g", j,
		    numbers[i].getName().c_str(), numbers[i].getValue());
	  recompute = true;
	}
      }
      else if(numbers[i].getStep() > 0){
	if(numbers[i].getMax() != onelab::parameter::maxNumber() &&
	   numbers[i].getValue() < numbers[i].getMax()){
	  numbers[i].setValue(numbers[i].getValue() + numbers[i].getStep());
	  onelab::server::instance()->set(numbers[i]);
	  OLMsg::Info("Recomputing with new step %s=%g",
		    numbers[i].getName().c_str(), numbers[i].getValue());
	  recompute = true;
	}
      }
      else if(numbers[i].getStep() < 0){
	if(numbers[i].getMin() != -onelab::parameter::maxNumber() &&
	   numbers[i].getValue() > numbers[i].getMin()){
	  numbers[i].setValue(numbers[i].getValue() + numbers[i].getStep());
	  onelab::server::instance()->set(numbers[i]);
	  OLMsg::Info("Recomputing with new step %s=%g",
		    numbers[i].getName().c_str(), numbers[i].getValue());
	  recompute = true;
	}
      }
    }
  }

  if(loop && !recompute) // end of this loop level
    initializeLoop(level);

  return recompute;
}

void initializeLoops()
{
  initializeLoop("1");
  initializeLoop("2");
  initializeLoop("3");
}

bool incrementLoops()
{
  bool ret = false;
  if(incrementLoop("3"))      ret = true;
  else if(incrementLoop("2")) ret = true;
  else if(incrementLoop("1")) ret = true;
  return ret;
}

bool menu() {
  int choice, counter1=0, counter2=0;
  std::vector<onelab::number> numbers;
  std::vector<onelab::string> strings;

  do {
    std::cout << "\nONELAB: menu" << std::endl ;
    std::cout << " 1- View parameter space\n 2- Client status\n 3- Set value\n 4- Analyze\n 5- Compute\n 6- Loop\n 7- Quit metamodel" << std::endl;
    choice=0;
    std::string mystr;
    while( (choice<1 || choice>7) && ++counter1<10 ) {
      std::cout << "\nONELAB: your choice? ";
      std::getline (std::cin, mystr);
      std::stringstream myStream(mystr);
      if (myStream >> choice) break;
      std::cout << "Invalid choice" << std::endl;
    }
    std::cout << "Your choice is <" << choice << ">" << std::endl;

    if (choice==1){
      std::cout << showParamSpace();
      choice=0;
    }
    if (choice==2){
      std::cout << showClientStatus();
      choice=0;
    }
    else if (choice==3){
      std::string name;
      std::cout << "ONELAB: Variable name? "; std::cin >> name;
      onelab::server::instance()->get(numbers,name);
      if (numbers.size()) {
	float fval;
	std::cout << "ONELAB: Value? "; std::cin >> fval;
	numbers[0].setValue(fval);
	bool allowed = onelab::server::instance()->set(numbers[0]);
      }
      else{
	onelab::server::instance()->get(strings,name);
	if (strings.size()) {
	  std::string sval;
	  std::cout << "ONELAB: Value? "; std::cin >> sval;
	  strings[0].setValue(sval);
	  onelab::server::instance()->set(strings[0]);
	}
	else
	  std::cout << "ONELAB: The variable " << name
		    << " is not defined" << std::endl;
      }
      choice=0;
    }
    else if (choice==4){
      metamodel("check");
      choice=0;
    }
    else if (choice==5){
      metamodel("compute");
      choice=0;
    }
    else if (choice==6){
      initializeLoops();
      do{
	metamodel("compute");
      }while(incrementLoops());
      choice=0;
    }
    else if (choice==7)
      exit(1);
    else
      choice=0;
  } while(!choice && ++counter2<20);
}

void PrintUsage(const char *name){
  printf("\nUsage:       %s [-a -i -h -v int] modelName\n", name);
  exit(1);
}

int main(int argc, char *argv[]){
  bool launchMenu=false;
  int i = 1;
  std::string caseName="", todo="compute", modelName="", workingDir="";
  onelab::remoteNetworkClient *client = 0;

  while(i < argc) {
    if(argv[i][0] == '-') {
      if(!strcmp(argv[i] + 1, "a")) {
        i++;
	todo="check";
      }
      else if(!strcmp(argv[i] + 1, "i")) {
	i++;
	launchMenu=true;
      }
      else if(!strcmp(argv[i] + 1, "lol")) {
	std::string clientName=argv[i+1];
	client = new onelab::remoteNetworkClient(clientName,argv[i+2]);
	if(client){
	  std::string action, cmd;

	  std::vector<onelab::string> ps;
	  client->get(ps,clientName+"/Action");
	  if(ps.size() && ps[0].getValue().size())
	    action.assign(ps[0].getValue());

	  if(!action.compare("compute")){
	    std::vector<onelab::string> ps;
	    client->get(ps,clientName+"/FullCmdLine");
	    if(ps.size() && ps[0].getValue().size())
	      cmd.assign(ps[0].getValue());

	    if(cmd.size()){
	      OLMsg::Info("Loader calls <%s>",cmd.c_str());
	      SystemCall(cmd.c_str(),true); //true->blocking
	    }
	    else
	      OLMsg::Info("No full command line found for <%s>",
			  clientName.c_str());
	    //OLMsg::Info("Stopping client <%s>", clientName.c_str());
	  }
	  delete client;
	}
	exit(1);
      }
      else if(!strcmp(argv[i] + 1, "v")) {
        i++;
        if(argv[i])
          OLMsg::SetVerbosity(atoi(argv[i++]));
        else
          OLMsg::Fatal("Missing number");
      }
      else {
	i++;
	PrintUsage(argv[0]);
      }
    }
    else {
      caseName=argv[i];
      modelName.assign(SplitFileName(caseName)[1]);
      workingDir.assign(SplitFileName(caseName)[0]);
      if(workingDir.empty())
	workingDir.assign(getCurrentWorkdir());
      i++;
    }
  }

  if(caseName.empty())
    OLMsg::Fatal("No valid input model name <%s>.", caseName.c_str());

  OLMsg::InitializeOnelab("onelab");
  if(argc) OLMsg::SetOnelabString("LoaderPathName",argv[0]);
  OLMsg::SetOnelabString("Arguments/FileName",modelName);
  OLMsg::SetOnelabString("Arguments/WorkingDir",workingDir);

  if(launchMenu)
    menu();
  else
    metamodel(todo);

  OLMsg::FinalizeOnelab();
}

