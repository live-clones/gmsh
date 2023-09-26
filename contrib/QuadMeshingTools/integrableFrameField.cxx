#include "integrableFrameField.hxx"
#include "tools.hxx"
#include <cmath>
#include <gmsh.h>
#include "crossfields.hxx"
#include "objectiveFunction.hxx"

namespace IFF{

  IntegrableFrameField::~IntegrableFrameField(){
    ObjectiveFunction::clearAll;
    delete m_m;
  }
  
  void IntegrableFrameField::setBC(const std::vector<size_t> &vertTags, const std::vector<std::vector<std::vector<double>>> &imposedDir){
    if(vertTags.size() != imposedDir.size())
      gmsh::logger::write("Error in IntegrableFrameField::setBC. vertTags and imposedDir sizes not matching.", "error");

    m_bc.clear();
    size_t maxVertTag = 0;
    for(const size_t &tag: vertTags)
      if(tag > maxVertTag)
	maxVertTag = tag;
  
    std::vector<bool> flaggedVert(maxVertTag, false);
    for(const size_t &tag: vertTags)
      if(flaggedVert[tag]){
	gmsh::logger::write("Error in IntegrableFrameField::setBC. Duplicate vertices tags present", "error");
      }
      else
	flaggedVert[tag] = true;

    //Might be slow, to see if it's needed to optimize
    for(size_t k=0; k<vertTags.size(); k++){
      Vertex *v = m_m->getVertexByTag(vertTags[k]);
      std::vector<std::vector<double>> dirs = imposedDir[k];
      std::vector<std::vector<double>> bcDir{dirs};
      if(m_cftype == ISO){
	OdecoIso2Dplanar f(bcDir);
	m_bc[v] = f.m_frame;
      }
      else if(m_cftype == ANISO){
	OdecoAniso2Dplanar f(bcDir);
	m_bc[v] = f.m_frame;
      }
      else
      	gmsh::logger::write("Unknown crossfield type required. Available options: IFF::ISO, IFF::ANISO", "error");
    }

    m_bcSet = true;
  }

  void IntegrableFrameField::setSizes(const std::vector<size_t> &vertTags, const std::vector<double> &imposedSize){
    if(vertTags.size() != imposedSize.size())
      gmsh::logger::write("Error in IntegrableFrameField::setSizes. vertTags and imposedSize sizes not matching.", "error");

    m_imposedSizes.clear();
    size_t maxVertTag = 0;
    for(const size_t &tag: vertTags)
      if(tag > maxVertTag)
	maxVertTag = tag;
  
    std::vector<bool> flaggedVert(maxVertTag, false);
    for(const size_t &tag: vertTags)
      if(flaggedVert[tag]){
	gmsh::logger::write("Error in IntegrableFrameField::setSizes. Duplicate vertices tags present", "error");
      }
      else
	flaggedVert[tag] = true;

    //Might be slow, to see if it's needed to optimize
    for(size_t k=0; k<vertTags.size(); k++){
      Vertex *v = m_m->getVertexByTag(vertTags[k]);
      if(imposedSize[k] >= 0.0){
        m_imposedSizes[v] = imposedSize[k];
      }
      else{
	gmsh::logger::write("Error in IntegrableFrameField::setSizes. Imposed size is negative", "error");
      }
    }
    m_sizesSet = true;
  }
  
  void IntegrableFrameField::setTriangles(const std::vector<size_t> &triTags){
    if(triTags.size() == 0){
      gmsh::logger::write("Error in IntegrableFrameField::setTriangles. Empty triangle tags vector", "error");
    }
    size_t maxTriTag = 0;
    for(const size_t &tag: triTags)
      if(tag > maxTriTag)
	maxTriTag = tag;
    std::vector<bool> flaggedTri(maxTriTag, false);
    for(const size_t &tag: triTags)
      if(flaggedTri[tag]){
	gmsh::logger::write("Error in IntegrableFrameField::setTriangles. Duplicate triangle tags present", "error");
      }
      else
	flaggedTri[tag] = true;

    m_tri.reserve(triTags.size());
    for(Triangle *t: m_m->m_pTriangles)
      if(flaggedTri[t->getTag()])
	m_tri.push_back(t);

    m_triSet = true;
  }

  void IntegrableFrameField::setInitCrossField(const std::vector<size_t> &vertTags, const std::vector<std::vector<std::vector<double>>> &initDir){
    if(vertTags.size() != initDir.size()){
      gmsh::logger::write("Error in IntegrableFrameField::setInitCrossField. Vertices tags size and initial directions size not matching", "error");
    }
    else{
      m_initDir.clear();
      for(size_t k=0; k<vertTags.size(); k++)
	m_initDir[m_m->getVertexByTag(vertTags[k])] = initDir[k];
    }
    m_initSolExists = true;
  }

  mapVertTagCf IntegrableFrameField::computeInitialCrossfield(){
    if(m_cftype == ISO){
      return _computeInitialIsoCrossfield();
    }
    else if(m_cftype == ANISO){
      return _computeInitialAnisoCrossfield();
    }
    else{
      gmsh::logger::write("Unknown crossfield type required. Available options: IFF::ISO, IFF::ANISO", "error");
      mapVertTagCf cf;
      return cf;
    }
  }
  
  mapVertTagCf IntegrableFrameField::_computeInitialIsoCrossfield(){
    std::map<Vertex *, std::vector<double>> solution;
    int nFields = OdecoIso2Dplanar::nUnkown;
    
    DirichletEnergie *dir = new DirichletEnergie(nFields);
    double hmax = m_m->getHmax(m_tri);
    double penalty = 1.0/(4*2*hmax*hmax);
    // std::cout << "Val penalty: " << penalty << std::endl;
  
    OdecoIso2DplanarConstraint *odConstr = new OdecoIso2DplanarConstraint(penalty);
    LBOdecoIso2Dplanar *odLBConstr = new LBOdecoIso2Dplanar();
  
    ObjectiveFunction *func_to_minimize = odLBConstr;

    Solver solver(m_tri, nFields, func_to_minimize);

    // Boundary conditions
    std::vector<double> valDirichlet;
    std::vector<std::pair<Vertex *, int>> dirichletBC;
    for(auto &kv: m_bc){
      OdecoIso2Dplanar f(kv.second);
      for(size_t kF=0; kF<nFields; kF++){
	dirichletBC.push_back(std::make_pair(kv.first, kF));
	valDirichlet.push_back(f.m_frame[kF]);
      }
      solution[kv.first] = f.m_frame;
    }
    //
    // Imposed sizes condition
    for(auto &kv: m_imposedSizes){
      dirichletBC.push_back(std::make_pair(kv.first, 0));
      valDirichlet.push_back(2*3*sqrt(2*M_PI)/8.0*kv.second);
      solution[kv.first][0] = 2*3*sqrt(2*M_PI)/8.0*kv.second;
    }
    //
    
    solver.addBCDirichlet(dirichletBC, valDirichlet);
    solver.m_lbfgsGradPrec = m_gradPrec;
    solver.m_lbfgsFuncPrec = m_funcPrec;
    solver.m_lbfgsXPrec = m_XPrec;
    solver.m_maxItLbfgs = 100000;

    solver.m_objFunc = dir;
    solver.solve(solution);
    solver.m_objFunc = (*dir) + (*odConstr);
    solver.solveLBFGS(solution);

    mapVertTagCf cf;
    for(auto &kv: solution){
      OdecoIso2Dplanar f(kv.second);
      cf[kv.first->getTag()] = f.getDirections();
    }

    return cf;
  }

    mapVertTagCf IntegrableFrameField::_computeInitialAnisoCrossfield(){
    std::map<Vertex *, std::vector<double>> solution;
    int nFields = OdecoAniso2Dplanar::nUnkown;
    
    DirichletEnergie *dir = new DirichletEnergie(nFields);
    double hmax = m_m->getHmax(m_tri);
    double penalty = 1.0/(4*2*hmax*hmax);
    // std::cout << "Val penalty: " << penalty << std::endl;
  
    OdecoAniso2DplanarConstraint *odConstr = new OdecoAniso2DplanarConstraint(penalty);
    LBOdecoAniso2Dplanar *odLBConstr = new LBOdecoAniso2Dplanar();
  
    ObjectiveFunction *func_to_minimize = odLBConstr;

    Solver solver(m_tri, nFields, func_to_minimize);

    // Boundary conditions
    std::vector<double> valDirichlet;
    std::vector<std::pair<Vertex *, int>> dirichletBC;
    for(auto &kv: m_bc){
      OdecoAniso2Dplanar f(kv.second);
      for(size_t kF=0; kF<nFields; kF++){
	dirichletBC.push_back(std::make_pair(kv.first, kF));
	valDirichlet.push_back(f.m_frame[kF]);
      }
      solution[kv.first] = f.m_frame;
    }
    //
    // Imposed sizes condition
    for(auto &kv: m_imposedSizes){
      dirichletBC.push_back(std::make_pair(kv.first, 0));
      valDirichlet.push_back(2*3*sqrt(2*M_PI)/8.0*kv.second);
      solution[kv.first][0] = 2*3*sqrt(2*M_PI)/8.0*kv.second;
    }
    //
    
    solver.addBCDirichlet(dirichletBC, valDirichlet);
    solver.m_lbfgsGradPrec = m_gradPrec;
    solver.m_lbfgsFuncPrec = m_funcPrec;
    solver.m_lbfgsXPrec = m_XPrec;
    solver.m_maxItLbfgs = 100000;

    solver.m_objFunc = dir;
    solver.solve(solution);
    solver.m_objFunc = (*dir) + (*odConstr);
    solver.solveLBFGS(solution);

    mapVertTagCf cf;
    for(auto &kv: solution){
      OdecoAniso2Dplanar f(kv.second);
      cf[kv.first->getTag()] = f.getDirections();
    }

    return cf;
  }
  
  mapVertTagCf IntegrableFrameField::computeIntegrableCrossfield(){
    if(m_bcSet && m_triSet){
      if(m_cftype == ISO){
	std::map<Vertex *, std::vector<double>> solution;
	_computeLBOdeco2DisoCrossfield(solution);

	mapVertTagCf cf;
	for(auto &kv: solution){
	  OdecoIso2Dplanar f(kv.second);
	  cf[kv.first->getTag()] = f.getDirections();
	}

	return cf;
      }
      else if(m_cftype == ANISO){
	std::map<Vertex *, std::vector<double>> solution;
	_computeLBOdeco2DanisoCrossfield(solution);
	
	mapVertTagCf cf;
	for(auto &kv: solution){
	  OdecoAniso2Dplanar f(kv.second);
	  cf[kv.first->getTag()] = f.getDirections();
	}

	return cf;
      }
      else{
	gmsh::logger::write("Unknown crossfield type required. Available options: IFF::ISO, IFF::ANISO", "error");
	mapVertTagCf cf;
	return cf;
      }
    }
    else{
      gmsh::logger::write("Error in IntegrableFrameField::computeCrossfield. Boundary conditions or list triangles not set.", "error");
      mapVertTagCf cf;
      return cf;
    }
  }

  void IntegrableFrameField::_computeLBOdeco2DisoCrossfield(std::map<Vertex *, std::vector<double>> &solution){
    int nFields = OdecoIso2Dplanar::nUnkown;
    
    DirichletEnergie *dir = new DirichletEnergie(nFields);
    double hmax = m_m->getHmax(m_tri);
    double penalty = 1.0/(4*2*hmax*hmax);
    // std::cout << "Val penalty: " << penalty << std::endl;
  
    OdecoIso2DplanarConstraint *odConstr = new OdecoIso2DplanarConstraint(penalty);
    LBOdecoIso2Dplanar *odLBConstr = new LBOdecoIso2Dplanar();
  
    ObjectiveFunction *func_to_minimize = odLBConstr;

    Solver solver(m_tri, nFields, func_to_minimize);

    // Initialize solution
    solution.clear();
    if(m_initSolExists){
      for(auto &kv: m_initDir){
	OdecoIso2Dplanar f(kv.second);
	solution[kv.first] = f.m_frame;
      }
    }
    // Boundary conditions
    std::vector<double> valDirichlet;
    std::vector<std::pair<Vertex *, int>> dirichletBC;
    for(auto &kv: m_bc){
      OdecoIso2Dplanar f(kv.second);
      for(size_t kF=0; kF<nFields; kF++){
	dirichletBC.push_back(std::make_pair(kv.first, kF));
	valDirichlet.push_back(f.m_frame[kF]);
      }
      solution[kv.first] = f.m_frame;
    }
    //
    // Imposed sizes condition
    for(auto &kv: m_imposedSizes){
      dirichletBC.push_back(std::make_pair(kv.first, 0));
      valDirichlet.push_back(2*3*sqrt(2*M_PI)/8.0*kv.second);
      solution[kv.first][0] = 2*3*sqrt(2*M_PI)/8.0*kv.second;
    }
    //
    solver.addBCDirichlet(dirichletBC, valDirichlet);

    std::chrono::time_point<std::chrono::high_resolution_clock> c_start = std::chrono::high_resolution_clock::now();

    solver.m_lbfgsGradPrec = m_gradPrec;
    solver.m_lbfgsFuncPrec = m_funcPrec;
    solver.m_lbfgsXPrec = m_XPrec;
    solver.m_maxItLbfgs = 100000;

    if(!m_initSolExists){
      solver.m_objFunc = dir;
      solver.solve(solution);
      solver.m_objFunc = (*dir) + (*odConstr);
      solver.solveLBFGS(solution);
    }

    std::map<Vertex *, std::vector<double>> solutionInit;
    solutionInit = solution;
    // std::vector<double> valInit{1.0, 0.0, 0.0};
    // for(auto &kv: solution){
    //   solutionInit[kv.first] = valInit;
    // }
    // for(Vertex *v: m.m_pBoundaryVertices)
    //   solutionInit[v] = solution[v];

    // std::vector<double> scheduledOdConstr{0.0, 1e-5, 1e-4, 1e-3};
    std::vector<double> scheduledOdConstr{1e-5};
    // std::vector<double> scheduledOdConstr{};
    // std::vector<double> scheduledOdConstr{1.0};

    for(double val: scheduledOdConstr){
      solver.m_maxItLbfgs = 100000;
      solver.m_objFunc = (*odLBConstr) + (*(val * (*odConstr)));
      solver.solveLBFGS(solutionInit);
    }
  
    solution = solutionInit;
    std::chrono::time_point<std::chrono::high_resolution_clock> c_end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed_time = (c_end-c_start);
    double time_elapsed_ms = elapsed_time.count();
    gmsh::logger::write("Solving time: " + std::to_string(time_elapsed_ms) + " s", "info");
  }

  void IntegrableFrameField::_computeLBOdeco2DanisoCrossfield(std::map<Vertex *, std::vector<double>> &solution){
    int nFields = OdecoAniso2Dplanar::nUnkown;
    
    DirichletEnergie *dir = new DirichletEnergie(nFields);
    double hmax = m_m->getHmax(m_tri);
    double penalty = 1.0/(4*2*hmax*hmax);
    // std::cout << "Val penalty: " << penalty << std::endl;
  
    OdecoAniso2DplanarConstraint *odConstr = new OdecoAniso2DplanarConstraint(penalty);
    LBOdecoAniso2Dplanar *odLBConstr = new LBOdecoAniso2Dplanar();
  
    ObjectiveFunction *func_to_minimize = odLBConstr;

    Solver solver(m_tri, nFields, func_to_minimize);

    // Initialize solution
    solution.clear();
    if(m_initSolExists){
      for(auto &kv: m_initDir){
	OdecoAniso2Dplanar f(kv.second);
	solution[kv.first] = f.m_frame;
      }
    }
    // Boundary conditions
    std::vector<double> valDirichlet;
    std::vector<std::pair<Vertex *, int>> dirichletBC;
    for(auto &kv: m_bc){
      OdecoAniso2Dplanar f(kv.second);
      for(size_t kF=0; kF<nFields; kF++){
	dirichletBC.push_back(std::make_pair(kv.first, kF));
	valDirichlet.push_back(f.m_frame[kF]);
      }
      solution[kv.first] = f.m_frame;
    }
    //
    // Imposed sizes condition
    for(auto &kv: m_imposedSizes){
      dirichletBC.push_back(std::make_pair(kv.first, 0));
      valDirichlet.push_back(2*3*sqrt(2*M_PI)/8.0*kv.second);
      solution[kv.first][0] = 2*3*sqrt(2*M_PI)/8.0*kv.second;
    }
    //
    solver.addBCDirichlet(dirichletBC, valDirichlet);

    std::chrono::time_point<std::chrono::high_resolution_clock> c_start = std::chrono::high_resolution_clock::now();

    solver.m_lbfgsGradPrec = m_gradPrec;
    solver.m_lbfgsFuncPrec = m_funcPrec;
    solver.m_lbfgsXPrec = m_XPrec;
    solver.m_maxItLbfgs = 100000;

    if(!m_initSolExists){
      solver.m_objFunc = dir;
      solver.solve(solution);
      solver.m_objFunc = (*dir) + (*odConstr);
      solver.solveLBFGS(solution);
    }

    std::map<Vertex *, std::vector<double>> solutionInit;
    solutionInit = solution;
    // std::vector<double> valInit{1.0, 0.0, 0.0};
    // for(auto &kv: solution){
    //   solutionInit[kv.first] = valInit;
    // }
    // for(Vertex *v: m.m_pBoundaryVertices)
    //   solutionInit[v] = solution[v];

    // std::vector<double> scheduledOdConstr{0.0, 1e-5, 1e-4, 1e-3};
    std::vector<double> scheduledOdConstr{1e-5};
    // std::vector<double> scheduledOdConstr{};
    // std::vector<double> scheduledOdConstr{1.0};

    for(double val: scheduledOdConstr){
      solver.m_maxItLbfgs = 100000;
      solver.m_objFunc = (*odLBConstr) + (*(val * (*odConstr)));
      solver.solveLBFGS(solutionInit);
    }
  
    solution = solutionInit;
    std::chrono::time_point<std::chrono::high_resolution_clock> c_end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed_time = (c_end-c_start);
    double time_elapsed_ms = elapsed_time.count();
    gmsh::logger::write("Solving time: " + std::to_string(time_elapsed_ms) + " s", "info");
  }

}
