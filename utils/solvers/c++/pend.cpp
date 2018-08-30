// 1) compile with "g++ pend.cpp -o pend.exe"
// 2) launch "gmsh pend.exe"

#include <math.h>
#include <stdio.h>
#include "onelab.h"

void exportMsh(const std::string &path, double le1, double le2)
{
  FILE *mshFile = fopen((path + "pend.msh").c_str(),"w");
  if(!mshFile) return;
  fprintf(mshFile, "$MeshFormat\n2.2 0 8\n$EndMeshFormat\n");
  fprintf(mshFile, "$Nodes\n3\n1 0 0 0\n2 0 %f 0\n3 0 %f 0\n$EndNodes\n",
          -le1, -le1-le2);
  fprintf(mshFile, "$Elements\n3\n1 1 2 0 1 1 2\n2 1 2 0 1 2 3\n3 15 2 0 2 3\n"
          "$EndElements\n");
  fclose(mshFile);
}

void exportMshOpt(const std::string &path)
{
  FILE *optFile = fopen((path + "pend.msh.opt").c_str(), "w");
  if(!optFile) return;
  fprintf(optFile, "n = PostProcessing.NbViews - 1;\n");
  fprintf(optFile, "If(n >= 0)\nView[n].ShowScale = 0;\nView[n].VectorType = 5;\n");
  fprintf(optFile, "View[n].ExternalView = 0;\nView[n].DisplacementFactor = 1 ;\n");
  fprintf(optFile, "View[n].PointType = 1;\nView[n].PointSize = 5;\n");
  fprintf(optFile, "View[n].LineWidth = 2;\nEndIf\n");
  fclose(optFile);
}

void exportIter(const std::string &path, int iter, double t, double x1, double y1,
                double x2, double y2)
{
  FILE *mshFile = fopen((path + "pend.msh").c_str(), "a");
  if(!mshFile) return;
  fprintf(mshFile, "$NodeData\n1\n\"motion\"\n1\n\t%f\n3\n\t%d\n3\n", t, iter);
  fprintf(mshFile, "\t3\n\t1 0 0 0\n\t2 %f %f 0\n\t3 %f %f 0\n$EndNodeData\n",
          x1, y1, x2, y2);
  fclose(mshFile);
}

double defineNumber(onelab::client *c, const std::string &name, double value,
                    const std::map<std::string, std::string> &attributes)
{
  std::vector<onelab::number> ns;
  c->get(ns, name);
  if(ns.empty()){ // define new parameter
    onelab::number n(name, value);
    if(attributes.size()) n.setAttributes(attributes);
    c->set(n);
    return value;
  }
  // return value from server
  return ns[0].getValue();
}

void setNumber(onelab::client *c, const std::string &name, double value,
               double min=0, double max=0, bool visible=true)
{
  onelab::number n(name, value);
  n.setMin(min);
  n.setMax(max);
  n.setVisible(visible);
  c->set(n);
}

void addNumberChoice(onelab::client *c, const std::string &name, double choice)
{
  std::vector<onelab::number> ns;
  c->get(ns, name);
  if(ns.size()){
    std::vector<double> choices = ns[0].getChoices();
    choices.push_back(choice);
    ns[0].setChoices(choices);
    c->set(ns[0]);
  }
}

int main(int argc, char **argv)
{
  std::string name, address;
  for(int i = 0; i < argc; i++){
    if(std::string(argv[i]) == "-onelab" && i + 2 < argc){
      name = std::string(argv[i + 1]);
      address = std::string(argv[i + 2]);
    }
  }

  if(name.empty() || address.empty()) return 1;

  onelab::remoteNetworkClient *c = new onelab::remoteNetworkClient(name, address);

  std::string action;
  std::vector<onelab::string> ns;
  c->get(ns, name + "/Action");
  if(ns.size()) action = ns[0].getValue();

  // prevent automatic Gmsh model reload & meshing
  onelab::number n("IsMetamodel", 1);
  c->set(n);

  std::string path(argv[0]);
  int islash = (int)path.find_last_of("/\\");
  if(islash > 0)
    path = path.substr(0, islash + 1);
  else
    path = "";

  double g = 9.8; // acceleration of gravity
  double m = 0.3; // mass of pendulum balls

  std::map<std::string, std::string> attr;

  double l = defineNumber(c, "Geom/arm length [m]", 1.0, attr);
  double time = defineNumber(c, "Dyna/time [s]", 0., attr);
  double dt = defineNumber(c, "Dyna/time step [s]", 0.001, attr);
  double tmax = defineNumber(c, "Dyna/max time [s]", 20, attr);
  double refresh = defineNumber(c, "Dyna/refresh interval [s]", 0.05, attr);
  attr["Highlight"] = "Pink";
  double theta0 = defineNumber(c, "Init/initial theta angle [deg]", 10, attr);
  double phi0 = defineNumber(c, "Init/initial phi angle [deg]", 180, attr);

  // we're done if we are not in the compute phase
  if(action != "compute"){
    delete c;
    return 0;
  }

  double l1 = l;
  double l2 = l;
  double m1 = m;
  double m2 = m;
  double theta = theta0 / 180.*M_PI;
  double phi = phi0 / 180.*M_PI;
  double theta_dot = 0.0;
  double phi_dot = 0.0;
  double refr = 0.0;
  int iter = 0;
  time = 0.0;

  while (time < tmax){
    double delta = phi - theta;
    double sdelta = sin(delta);
    double cdelta = cos(delta);
    double theta_dot_dot = ( m2*l1*(theta_dot*theta_dot)*sdelta*cdelta
                             + m2*g*sin(phi)*cdelta
                             + m2*l2*(phi_dot*phi_dot)*sdelta
                             - (m1+m2)*g*sin(theta) );
    theta_dot_dot /= ( (m1+m2)*l1 - m2*l1*(cdelta*cdelta) );

    double phi_dot_dot = ( -m2*l2*(phi_dot*phi_dot)*sdelta*cdelta
                           + (m1+m2)*(g*sin(theta)*cdelta
                                      - l1*(theta_dot*theta_dot)*sdelta
                                      - g*sin(phi)) );
    phi_dot_dot /= ( (m1+m2)*l2 - m2*l2*(cdelta*cdelta) );

    theta_dot += theta_dot_dot*dt;
    phi_dot += phi_dot_dot*dt;
    theta += theta_dot*dt;
    phi += phi_dot*dt;

    double x1 =  l1*sin(theta);
    double y1 = -l1*cos(theta);
    double x2 =  l1*sin(theta) + l2*sin(phi);
    double y2 = -l1*cos(theta) - l2*cos(phi);

    time += dt;
    refr += dt;

    exportMshOpt(path);

    if(refr >= refresh){
      refr = 0;
      setNumber(c, name + "/Progress", time, 0, tmax, false);
      setNumber(c, "Dyna/time [s]", time);
      setNumber(c, "Solu/phi", phi);
      addNumberChoice(c, "Solu/phi", phi);
      setNumber(c, "Solu/theta",  theta);
      addNumberChoice(c, "Solu/theta", theta);
      setNumber(c, "Solu/phi dot", phi_dot);
      addNumberChoice(c, "Solu/phi dot", phi_dot);
      setNumber(c, "Solu/theta dot", theta_dot);
      addNumberChoice(c, "Solu/theta dot", theta_dot);

      // ask Gmsh to refresh
      onelab::string s("Gmsh/Action", "refresh");
      c->set(s);

      // stop if we are asked to (by Gmsh)
      c->get(ns, name + "/Action");
      if(ns.size() && ns[0].getValue() == "stop") break;

      exportMsh(path, l1, l2);
      exportIter(path, iter, time, x1, y1+l1, x2, y2+l1+l2);
      c->sendMergeFileRequest(path + "pend.msh");
      iter += 1;
    }
  }

  setNumber(c, name + "/Progress", 0, 0, tmax, false);

  delete c;

  return 0;
}
