#include "Gmsh.h"
#include "elasticitySolver.h"
#include "PView.h"
#include "PViewData.h"
#include "highlevel.h"
#include "groupOfElements.h"
#include <iterator>
#include "function.h"
#include "fullMatrix.h"
/*
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
      dataCacheDouble(m->getNbEvaluationPoints(),1)
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

*/


int main (int argc, char* argv[])
{

  if (argc != 2){
    printf("usage : elasticity input_file_name\n");
    return -1;
  }
/*
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
*/

/*
  functionMult fm("axbxcxd","axbxcxd");
  dataCacheDouble *res;
  res=fm.newDataCache(&m);
  std::cout << "*res" << std::endl;
  std::cout << (*res)(0,0) << std::endl;
*/

//  return(0);

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



/*
  groupOfElements *g = new groupOfElements (2, 7);

  MElement *e=*(g->begin());
  std::cout << e->getNumPrimaryVertices() << "vertices" << std::endl;
  const double uvw[3]={0.,0.,0.};
  std::vector<Dof> dofs;
  std::vector<double> vals;
  std::vector<SVector3> grads;
  std::vector<SVector3> vals2;
  std::vector<STensor3> grads2;

  std::ostream_iterator< double > output( std::cout, " " );

  ScalarLagrangeFunctionSpace L(100);
  std::cout << L.getNumKeys(e) << "fonctions de formes L" << std::endl;
  L.getKeys(e,dofs);
  for (int i=0;i<dofs.size();++i) std::cout << "entity: " << dofs[i].getEntity() << " id: " << dofs[i].getType() << std::endl;
  dofs.clear();
  L.f(e,0.1,0.1,0,vals);
  L.gradf(e,0.1,0.1,0,grads);
  std::copy(vals.begin(),vals.end(),output); std::cout << std::endl;
  for (std::vector<SVector3>::iterator it=grads.begin();it!=grads.end();++it) { std::cout << (*it)[0]<< " " << (*it)[1] <<" " << (*it)[2] << std::endl; }

  VectorLagrangeFunctionSpace L1(100,VectorLagrangeFunctionSpace::VECTOR_X);
  VectorLagrangeFunctionSpace L2(100,VectorLagrangeFunctionSpace::VECTOR_Y);
  std::cout << L2.getNumKeys(e) << "fonctions de formes L2" << std::endl;
  L2.f(e,0.1,0.1,0,vals2);
  L2.gradf(e,0.1,0.1,0,grads2);
  for (std::vector<SVector3>::iterator it=vals2.begin();it!=vals2.end();++it) { std::cout << (*it)[0]<< " " << (*it)[1] <<" " << (*it)[2] << std::endl; }
  for (std::vector<STensor3>::iterator it=grads2.begin();it!=grads2.end();++it) { (*it).print(""); }

  VectorLagrangeFunctionSpace L3(100,VectorLagrangeFunctionSpace::VECTOR_Z);

  VectorLagrangeFunctionSpace P123(100);
  std::cout << P123.getNumKeys(e) << "fonctions de formes P123" << std::endl;
  P123.getKeys(e,dofs);
  std::cout << dofs.size() << std::endl;
  for (int i=0;i<dofs.size();++i) std::cout << "entity: " << dofs[i].getEntity() << " id: " << dofs[i].getType() << std::endl;

  vals2.clear();
  grads2.clear();
  P123.f(e,0.1,0.1,0,vals2);
  P123.gradf(e,0.1,0.1,0,grads2);
  for (std::vector<SVector3>::iterator it=vals2.begin();it!=vals2.end();++it) { std::cout << (*it)[0]<< " " << (*it)[1] <<" " << (*it)[2] << std::endl; }
  for (std::vector<STensor3>::iterator it=grads2.begin();it!=grads2.end();++it) { (*it).print(""); }



  FormBilinear<TermBilinearMeca,ScalarLagrangeFunctionSpace,ScalarLagrangeFunctionSpace > f(L,L);
  f.func();
  f.Accumulate(e,uvw);


  FormBilinear<TermBilinearMecaNL,ScalarLagrangeFunctionSpace,ScalarLagrangeFunctionSpace > fnl(L,L);
  fnl.func();

*/





