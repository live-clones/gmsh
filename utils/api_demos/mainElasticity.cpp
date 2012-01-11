#include "Gmsh.h"
#include "elasticitySolver.h"
#include "PView.h"
#include "PViewData.h"
#include "onelab.h"


onelab::remoteNetworkClient *_onelabClient = 0;

void Info (int i, char* c){
  printf("%d %s\n",i,c);
}

void InitializeOnelab(const char * socket, std::string &modName) {
  _onelabClient = 
    new onelab::remoteNetworkClient("ElasticSolver", socket );  
  std::vector<std::string> choices;
  std::vector<onelab::string> ps;
  _onelabClient->get(ps,"Elasticity/9Compute");
  ps.resize(1);
  ps[0].setName("Elasticity/9Compute");
  ps[0].setValue("-solve -pos");  
  choices.push_back("-solve -pos");
  choices.push_back("-pos");
  choices.push_back("-solve");
  ps[0].setChoices(choices);
  _onelabClient->set(ps[0]);
  ps.resize(1);
  ps[0].setName("Elasticity/1ModelName");
  ps[0].setValue(modName);  
  _onelabClient->set(ps[0]);
}
void AddOnelabNumberChoice(std::string name, double val, std::string help)
{
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
  ps[0].setValue(val);
  choices.push_back(val);
  ps[0].setChoices(choices);
  ps[0].setHelp(help);
  ps[0].setShortHelp(help);
  _onelabClient->set(ps[0]);
}

void GetSetMaterials (elasticitySolver &e) {

  std::vector<onelab::number> ps;
  for (int i=0;i<e.elasticFields.size();i++){
    std::stringstream ss;//create a stringstream
    ss << i;//add number to the stream
    std::string mat = "Elasticity/LinearElasticMaterial "+ss.str()+"/Young/";
    std::string help = "Young Modulus";
    AddOnelabNumberChoice (mat,e.elasticFields[i]._E,help);
    mat = "Elasticity/LinearElasticMaterial "+ss.str()+"/Poisson/";
    help = "Poisson Ratio";
    AddOnelabNumberChoice (mat,e.elasticFields[i]._nu,help);
  }
}

void GetSetLoads (elasticitySolver &e) {
  // todo
}

void GetSetFixations (elasticitySolver &e) {
  // todo
}

void WhatToDoNow(int argc, char *argv[], int &solve, std::string &modName)
{
  int i =  1;
  solve = 0;
  while (i < argc) {
    
    if (argv[i][0] == '-') {
      if (!strcmp(argv[i]+1, "onelab")) {
	i++;
	if (i<argc && argv[i][0]!='-') { 
	  printf("INITIALIZINK SOCKET %s\n",argv[i]);
	  InitializeOnelab(argv[i],modName); i++; 
	}
	else {
	  printf("Error : Missing address of onelab server");
	}
      }

      else if (!strcmp(argv[i]+1, "help")  || !strcmp(argv[i]+1, "h") ||
	       !strcmp(argv[i]+1, "-help") || !strcmp(argv[i]+1, "-h")) {
	i++;
	Info(0, argv[0]);
      }

      else if (!strcmp(argv[i]+1, "version") || 
	       !strcmp(argv[i]+1, "-version")) {
	i++;
	Info(1, argv[0]);
      }

      else if (!strcmp(argv[i]+1, "info") || 
               !strcmp(argv[i]+1, "-info")) {
	i++;
        Info(2, argv[0]);
      }
      else if (!strcmp(argv[i]+1, "solve") || 
               !strcmp(argv[i]+1, "-solve")) {
	solve = 1;
	i++;
      }
      else if (!strcmp(argv[i]+1, "pos") || 
               !strcmp(argv[i]+1, "-pos")) {
	i++;
      }
    }
    else {
      modName = std::string(argv[i]);
      //      if (modName)
      //      modName = modName + std::string(".fuk");
      std::vector<onelab::string> ps;
      i++;
    }
  }
}



int main (int argc, char* argv[]){
  
  char* a[10];
  char name[245];
  a[0] = name; 
  GmshInitialize(1, a);
  GmshSetOption("General","Terminal",1.);
  
  //  for (int i=0;i<argc;i++)printf("%s\n",argv[i]);  

  printf("Welcome to the Simple Elasticity Program For Onelab\n");


  int solve;
  std::string pn;
  WhatToDoNow (argc,argv, solve,pn);

  elasticitySolver mySolver (1000);
  mySolver.setMesh(std::string(pn+".msh").c_str());
  _onelabClient->sendMergeFileRequest(pn+".msh");
  mySolver.readInputFile(std::string(pn+".dat").c_str());
  GetSetMaterials (mySolver);
  if (solve){
    mySolver.solve(); 
    PView *pvm = mySolver.buildVonMisesView("vonMises");
    PView *pv = mySolver.buildDisplacementView("displacement");
    //    pv->getData()->writeMSH("disp.msh", false, false);
    pv->getData()->writePOS("disp.pos");
    pvm->getData()->writePOS("vonMises.pos");
    _onelabClient->sendMergeFileRequest("disp.pos");
    _onelabClient->sendMergeFileRequest("vonMises.pos");
    delete pv;
  }

  //GmshFinalize();
  if (_onelabClient) delete _onelabClient;

  return 0;


  
  // solve the problem

        
  // stop gmsh
  
}
