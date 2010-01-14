#include "Gmsh.h"
#include "elasticitySolver.h"
#include "PView.h"
#include "PViewData.h"
#include "highlevel.h"
#include "groupOfElements.h"
#include <iterator>
#include "function.h"
#include "fullMatrix.h"

class functionAdd : public function
{
 private:
  std::vector<std::string> strvec;
  class data : public dataCacheDouble
  {
   private:
    std::vector<dataCacheDouble *> dcvec;
   public:
    data(const functionAdd * fm,dataCacheMap *m) :
      dataCacheDouble(*m,m->getNbEvaluationPoints(),1)
    {
      for (int i=0;i<fm->strvec.size();++i)
        dcvec.push_back(&(m->get(fm->strvec[i],this)));
    }
    void _eval()
    {
      _value(0, 0)=0;
      for (int i=0;i<dcvec.size();++i) { _value(0, 0) += (*(dcvec[i]))(0,0);}
    }
    ~data()
    {
    }
  };
 public:
  dataCacheDouble *newDataCache(dataCacheMap *m)
  {
    return new data(this,m);
  }
  functionAdd(std::string _a,std::string _b) {strvec.push_back(_a);strvec.push_back(_b);}
  void addNewTerm(std::string _a)  { strvec.push_back(_a);}
};




int main (int argc, char* argv[])
{

  if (argc != 2){
    printf("usage : elasticity input_file_name\n");
    return -1;
  }
#if 0
  fullMatrix<double> a(1,1);
  a(0,0)=1.0;
  fullMatrix<double> b(1,1);
  b(0,0)=2.0;
  fullMatrix<double> c(1,1);
  c(0,0)=4.0;
  fullMatrix<double> d(1,1);
  d(0,0)=8.0;
  fullMatrix<double> e(1,1);
  e(0,0)=16.0;

  std::cout << argc << std::endl;
  functionConstant fc_a(&a);
  functionConstant fc_b(&b);
  functionConstant fc_c(&c);
  functionConstant fc_d(&d);
  functionConstant fc_e(&e);

  functionAdd fa_ab(fc_a.getName(),fc_b.getName());
  functionAdd fa_cd(fc_c.getName(),fc_d.getName());
  functionAdd fa_abcd("a+b","c+d");

  function::add("a+b", &fa_ab );
  function::add("c+d", &fa_cd);
  function::add("a+b+c+d", &fa_abcd);

  dataCacheMap m(1);
  std::cout << "start" << std::endl;
  dataCacheDouble &dc_a=m.get(fc_a.getName());
  dataCacheDouble &dc_abcd=m.get("a+b+c+d");
  fa_abcd.addNewTerm(fc_e.getName());
  std::cout << "nb depsabcd=" << dc_abcd.howManyDoIDependOn() << std::endl;
  std::cout << "nb depsa=" << dc_a.howManyDependOnMe() << std::endl;
  std::cout << "a" << std::endl;
  std::cout << dc_a(0,0) << std::endl;
  std::cout << "a+b+c+d" << std::endl;
  std::cout << dc_abcd(0,0) << std::endl;
  std::cout << "dca.set(b)" << std::endl;
  dc_a.set(b);
  std::cout << "a+b+c+d" << std::endl;
  std::cout << dc_abcd(0,0) << std::endl;
  return(0);
#endif

  GmshInitialize(argc, argv);
  // globals are still present in Gmsh

  // instanciate a solver
  elasticitySolver mySolver (1000);

  // read some input file
  mySolver.readInputFile(argv[1]);

  // solve the problem
  mySolver.solve();

  PView *pv = mySolver.buildDisplacementView("displacement");
  pv->getData()->writeMSH("disp.msh", false);
  delete pv;
  pv = mySolver.buildElasticEnergyView("elastic energy");
  pv->getData()->writeMSH("energ.msh", false);
  delete pv;

  // stop gmsh
  GmshFinalize();
}
