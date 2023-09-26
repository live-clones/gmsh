#include "crossfields.hxx"
#include "tools.hxx"
#include "visualization.hxx"
#include "objectiveFunction.hxx"
#include "solver.hxx"
#include <queue>
#include "visualization.hxx"
#include <tuple>

namespace IFF{

  size_t OdecoIso2Dplanar::nUnkown = 3;
  size_t OdecoAniso2Dplanar::nUnkown = 5;
  
  std::vector<std::vector<double>> OdecoIso2Dplanar::getAlignmentLinConstr(const std::vector<double> &dir){
    std::vector<double> dirN = dir;
    tools::normalize(dirN);
    // std::cout << "dir: " << dir[0] << " " << dir[1] << " " << dir[2] << std::endl;
    // std::cout << "dirN: " << dirN[0] << " " << dirN[1] << " " << dirN[2] << std::endl;
    std::vector<std::vector<double>> dirs(1, dirN);
    OdecoIso2Dplanar frame(dirs);
    // OdecoIso2Dplanar frameDbg(dirs);
    // frameDbg.projectOnCrossManifold();
    // std::cout << "frame: " << frame.m_frame[0] << " " << frame.m_frame[1] << " " << frame.m_frame[2] << std::endl;
    // if(tools::distance(frameDbg.m_frame, frame.m_frame) > 1e-12){
    //   std::cout << "pb proj or frame construction" << std::endl;
    //   std::cout << "dist: " << tools::distance(frameDbg.m_frame, frame.m_frame) << std::endl;
    //   exit(0);
    // }
    Eigen::Vector3d f(frame.m_frame.data());
    // std::cout << "vect frame: " << f.transpose() << std::endl;
    Eigen::MatrixXd matLinConstr = (f.transpose().fullPivLu().kernel()).transpose();
    int nRows = static_cast<int>(matLinConstr.rows());
    int nCols = static_cast<int>(matLinConstr.cols());
    // std::cout << "nRows: " << nRows << " nCols: " << nCols << std::endl;
    // std::cout << matLinConstr << std::endl;
    for(size_t k=0; k<nRows; k++)
      matLinConstr.row(k).normalize();
    for(size_t k=1; k<nRows; k++){
      for(size_t l=0; l<k; l++){
	matLinConstr.row(k) = matLinConstr.row(k) - matLinConstr.row(l).dot(matLinConstr.row(k)) * matLinConstr.row(l);
      }
      matLinConstr.row(k).normalize();
    }
    // std::cout << matLinConstr << std::endl;
    // if(fabs(f.dot(matLinConstr.row(0))) > 1e-12){
    //   std::cout << "pb ps in cf" << std::endl;
    //   exit(0);
    // }
    // if(fabs(f.dot(matLinConstr.row(1))) > 1e-12){
    //   std::cout << "pb ps in cf" << std::endl;
    //   exit(0);
    // }
    std::vector<std::vector<double>> linConstr;
    linConstr.resize(nRows);
    for(size_t k=0; k<nRows; k++)
      linConstr[k].resize(nCols, 0.0);
    for(size_t k=0; k<nRows; k++)
      for(size_t l=0; l<nCols; l++)
	linConstr[k][l] = matLinConstr(k,l);
    return linConstr;
  }

  std::vector<std::vector<double>> OdecoAniso2Dplanar::getAlignmentLinConstr(const std::vector<double> &dir){
    std::vector<double> dirN = dir;
    tools::normalize(dirN);
    std::vector<double> normal = {0.0, 0.0, 1.0};
    std::vector<double> dirM = tools::crossprod(normal, dirN);
    for(size_t k=0; k<3; k++)
      dirM[k] *= 0.5;
    std::vector<std::vector<double>> dirs{dirN, dirM};
    OdecoAniso2Dplanar frame(dirs);
    Eigen::MatrixXd f{
      {frame.m_frame[0], 0.0, 0.0, frame.m_frame[3], frame.m_frame[4]},
      {0.0, frame.m_frame[1], frame.m_frame[2], 0.0, 0.0}
    };
    Eigen::MatrixXd matLinConstr = (f.fullPivLu().kernel()).transpose();
    int nRows = static_cast<int>(matLinConstr.rows());
    int nCols = static_cast<int>(matLinConstr.cols());
    for(size_t k=0; k<nRows; k++)
      matLinConstr.row(k).normalize();
    for(size_t k=1; k<nRows; k++){
      for(size_t l=0; l<k; l++){
	matLinConstr.row(k) = matLinConstr.row(k) - matLinConstr.row(l).dot(matLinConstr.row(k)) * matLinConstr.row(l);
      }
      matLinConstr.row(k).normalize();
    }
    
    std::vector<std::vector<double>> linConstr;
    linConstr.resize(nRows);
    for(size_t k=0; k<nRows; k++)
      linConstr[k].resize(nCols, 0.0);
    for(size_t k=0; k<nRows; k++)
      for(size_t l=0; l<nCols; l++)
	linConstr[k][l] = matLinConstr(k,l);
    return linConstr;
  }

  std::vector<double> Cross2D::getClosestDirection(const std::vector<double> &dir) const{
    double maxDotProd = 0.0;
    int index = -1;
    double sign = 0;
    for(size_t k=0; k<2; k++){
      double dotProd = tools::dotprod(tools::getNormalizedVector(m_directions[k]), dir);
      if(dotProd > maxDotProd || index == -1){
	maxDotProd = dotProd;
	index = k;
	sign = 1.0;
      }
      dotProd *= -1.0;
      if(dotProd > maxDotProd){
	maxDotProd = dotProd;
	index = k;
	sign = -1.0;
      }
    }
    std::vector<double> closestDir = m_directions[index];
    for(size_t k=0; k<closestDir.size(); k++)
      closestDir[k] = sign*closestDir[k];
  
  
    return closestDir;
  }

  std::vector<std::map<Triangle* , std::vector<double>>> CrossField2D::getPotentials(){
    std::vector<std::map<Triangle* , std::vector<double>>> pots;
    pots.reserve(2);
    if(m_potU.size() > 0 && m_potV.size() > 0){
      pots.push_back(m_potU);
      pots.push_back(m_potV);
    }
    else{
      _computePotentials();
      pots.push_back(m_potU);
      pots.push_back(m_potV);
    }

    return pots;
  }

  std::vector<std::pair<std::vector<Vertex *>, int>> CrossField2D::_getConstantPotBC(std::vector<std::map<Vertex*, std::vector<double>>> &crossLifting, Mesh &cm){
    std::vector<std::pair<std::vector<Vertex *>, int>> cstPotBC;
    for(Vertex *v: cm.m_pVertices)
      v->setIndex(-1);
    size_t cpt=0;  
    for(Vertex *v: cm.m_pBoundaryVertices){
      v->setIndex(cpt);
      cpt++;
    }

    std::vector<int> indexPot;
    indexPot.resize(cm.m_pBoundaryVertices.size());
    for(auto &kv: crossLifting[0]){
      if(!(kv.first->getIndex() == -1)){
	std::vector<double> lift0 = kv.second;
	tools::normalize(lift0);
	if(fabs(tools::dotprod(kv.first->m_geodesicNormal, lift0)) > sqrt(2)/2.0)
	  indexPot[kv.first->getIndex()] = 0;
	else
	  indexPot[kv.first->getIndex()] = 1;
      }
    }

    std::vector<std::vector<size_t>> neighVert;
    neighVert.resize(cm.m_pBoundaryVertices.size());
    for(std::vector<size_t> &vect: neighVert)
      vect.reserve(2);
    for(Edge *e: cm.m_pBoundaryEdges){
      if(indexPot[e->getVertex(0)->getIndex()] == indexPot[e->getVertex(1)->getIndex()]){
	neighVert[e->getVertex(0)->getIndex()].push_back(e->getVertex(1)->getIndex());
	neighVert[e->getVertex(1)->getIndex()].push_back(e->getVertex(0)->getIndex());
      }
    }
  
    std::vector<bool> vertTreated;
    vertTreated.resize(neighVert.size(), false);
    size_t indexStart = -1;
    for(size_t k=0; k<neighVert.size(); k++)
      if(neighVert[k].size()==1){
	indexStart = k;
	break;
      }
    while(indexStart != -1){
      std::vector<Vertex *> listVert;
      int potIndex = indexPot[indexStart];
      listVert.push_back(cm.m_pBoundaryVertices[indexStart]);
      vertTreated[indexStart] = true;
      size_t currentIndex = indexStart;
      while(currentIndex != -1){
	size_t nextIndex = -1;
	if(vertTreated[neighVert[currentIndex][0]]){
	  if(neighVert[currentIndex].size() > 1)
	    if(!vertTreated[neighVert[currentIndex][1]])
	      nextIndex = neighVert[currentIndex][1];
	}
	else
	  if(!vertTreated[neighVert[currentIndex][0]])
	    nextIndex = neighVert[currentIndex][0];
	if(nextIndex != -1){
	  listVert.push_back(cm.m_pBoundaryVertices[nextIndex]);
	  vertTreated[nextIndex] = true;
	}
	currentIndex = nextIndex;
      }
      cstPotBC.push_back(std::make_pair(listVert, potIndex));
      indexStart = -1;
      for(size_t k=0; k<neighVert.size(); k++)
	if(neighVert[k].size()==1 && !vertTreated[k]){
	  indexStart = k;
	  break;
	}
    }
    return cstPotBC;
  }

  void CrossField2D::_addCGcompatibilityConditions(Solver &solver, Mesh &cm, std::vector<std::map<Vertex*, std::vector<double>>> &crossLifting){
    size_t cpt = 0;
    for(Triangle *t: m_mesh->m_pTriangles){
      t->setIndex(cpt);
      cpt++;
    }
    cpt = 0;
    for(Triangle *t: cm.m_pTriangles){
      t->setIndex(cpt);
      cpt++;
    }
    std::vector<Edge> equalityConditions;
    std::vector<Edge*> edgJumpCond;
    std::vector<Edge*> edgEqualCond;
    std::vector<Edge*> edgDBG;
    // cpt=0;
    for(Edge *e: m_mesh->m_cutGraph){
      if(e->m_triangles.size() > 1){
	// cpt++;
	// if(cpt == 5){//DBG
	Triangle *t0 = e->m_triangles[0];
	Triangle *t1 = e->m_triangles[1];
	size_t locIndE0 = t0->getLocalIndexEdge(e);
	size_t locIndE1 = t1->getLocalIndexEdge(e);
	edgDBG.push_back(t0->getEdge(locIndE0));
	edgDBG.push_back(t1->getEdge(locIndE1));
	Triangle *tcm0 = cm.m_pTriangles[t0->getIndex()];
	Triangle *tcm1 = cm.m_pTriangles[t1->getIndex()];
	std::vector<std::pair<Vertex*, Vertex*>> pairVert{std::make_pair(tcm0->getVertex(locIndE0), tcm1->getVertex((locIndE1+1)%3)), std::make_pair(tcm0->getVertex((locIndE0+1)%3), tcm1->getVertex(locIndE1))};
	if(!(t0->getVertex(locIndE0) == t1->getVertex((locIndE1+1)%3))){
	  std::cout << "arf" << std::endl;
	  exit(0);
	}
	if(!(t0->getVertex((locIndE0+1)%3) == t1->getVertex(locIndE1))){
	  std::cout << "arf" << std::endl;
	  exit(0);
	}
	std::vector<std::vector<std::vector<double>>> vectLift;
	vectLift.resize(2);
	for(auto &vv: vectLift){
	  vv.resize(4);
	}
	for(size_t k=0; k<2; k++){
	  for(size_t l=0; l<2; l++){
	    vectLift[k][2*l+0] = crossLifting[k][pairVert[l].first];
	    tools::normalize(vectLift[k][2*l+0]);
	    vectLift[k][2*l+1] = crossLifting[k][pairVert[l].second];
	    tools::normalize(vectLift[k][2*l+1]);
	  }
	}
      
	std::vector<std::tuple<std::pair<Vertex*, int>, std::pair<Vertex*, int>, double>> jumps;
	jumps.reserve(4);
	for(size_t k=0; k<2; k++){
	  for(size_t l=0; l<2; l++){
	    std::pair<Vertex*, int> pairV0 = std::make_pair(pairVert[l].first, k);
	    std::pair<Vertex*, int> pairV1 = std::make_pair(pairVert[l].second, k);
	    std::vector<double> vectLeft = vectLift[k][2*l+0];
	    std::vector<double> vectRight = vectLift[k][2*l+1];
	    if(fabs(tools::dotprod(vectLeft, vectRight)) < sqrt(2)/2.0){
	      std::vector<double> vectRightOpp = vectLift[(k+1)%2][2*l+1];
	      std::pair<Vertex*, int> pairV1Opp = std::make_pair(pairVert[l].second, (k+1)%2);
	      if(tools::dotprod(vectLeft, vectRightOpp) > 0.0)
		jumps.push_back(std::make_tuple(pairV0, pairV1Opp, 1.0));
	      else
		jumps.push_back(std::make_tuple(pairV0, pairV1Opp, -1.0));
	    }
	    else{
	      if(tools::dotprod(vectLeft, vectRight) > 0.0)
		jumps.push_back(std::make_tuple(pairV0, pairV1, 1.0));
	      else
		jumps.push_back(std::make_tuple(pairV0, pairV1, -1.0));
	    }
	  
	  }
	}
      
	auto it0 = std::find(m_verticesSingularTriangles.begin(), m_verticesSingularTriangles.end(), e->getMinVertex());
	auto it1 = std::find(m_verticesSingularTriangles.begin(), m_verticesSingularTriangles.end(), e->getMaxVertex());
	bool notSingular = true;
	// if(it0 != m_verticesSingularTriangles.end() || it1 != m_verticesSingularTriangles.end()){
	// 	notSingular = false;
	// }
	if(notSingular)
	  for(size_t l=0; l<2; l++){
	    std::tuple<std::pair<Vertex*, int>, std::pair<Vertex*, int>, double> jumpV0 = jumps[2*l+0];
	    std::tuple<std::pair<Vertex*, int>, std::pair<Vertex*, int>, double> jumpV1 = jumps[2*l+1];
	    if((std::get<0>(jumpV0).second == std::get<0>(jumpV1).second) && (std::get<1>(jumpV0).second == std::get<1>(jumpV1).second)){
	      if(std::get<2>(jumpV0) == std::get<2>(jumpV1)){
		edgJumpCond.push_back(e);
		double signJump = std::get<2>(jumpV0);
		std::vector<std::vector<double>> mat;
		mat.resize(1);
		mat[0].resize(4, 0.0);
		mat[0][0] = 1.0;
		mat[0][1] = -signJump;
		mat[0][2] = -1.0;
		mat[0][3] = signJump;
		std::vector<double> vect{0.0};
		std::vector<std::pair<Vertex *, int>> pairVertexField{std::get<0>(jumpV0), std::get<1>(jumpV0), std::get<0>(jumpV1), std::get<1>(jumpV1)};
		solver.addBCLinearCombination(mat, vect, pairVertexField);
	      }
	    }
	  }
      }
    }
    visu::edges(edgJumpCond, "edge jump");
    visu::edges(edgEqualCond, "edge equ");
    visu::edges(edgDBG, "edge DBG");

  }

  void CrossField2D::_computePotentials(){
    std::cout << "detect singularities" << std::endl;
    _detectSingularities();
    m_mesh->m_pSingularities = m_singularities;
    m_mesh->createCutGraph();
    Mesh cutMesh;
    m_mesh->splitMeshOnEdges(m_mesh->m_cutGraph, cutMesh);
    std::cout << "create lifting" << std::endl;
    std::vector<std::map<Vertex*, std::vector<double>>> crossLifting = _getLifting(cutMesh);
    // Modify lifting norms to feat gradient of potential
    for(auto &kv: crossLifting[0]){
      double norm = fmax(tools::norm(kv.second), 1e-12);
      for(size_t k=0; k<kv.second.size(); k++)
	kv.second[k] = kv.second[k]/(norm*norm);
    }
    for(auto &kv: crossLifting[1]){
      double norm = fmax(tools::norm(kv.second), 1e-12);
      for(size_t k=0; k<kv.second.size(); k++)
	kv.second[k] = kv.second[k]/(norm*norm);
    }

    std::vector<std::pair<std::vector<Vertex *>, int>> cstPotBC = _getConstantPotBC(crossLifting, cutMesh);
    std::cout << "n bc const: " << cstPotBC.size() << std::endl;
    DoublePotential *funcPot = new DoublePotential();
    //Remove singular triangles from potential computation
    std::vector<Triangle *> computTri;
    if(m_ignoreSingularTriangles){
      for(Triangle *t: cutMesh.m_pTriangles){
	bool isSing = false;
	for(Triangle *ts: m_singularTriangles){
	  if(ts->getTag() == t->getTag()){
	    isSing = true;
	    break;
	  }
	}
	if(!isSing)
	  computTri.push_back(t);
      }
    }
    else{
      computTri = cutMesh.m_pTriangles;
    }
    // Solver solver(cutMesh.m_pTriangles, 2, funcPot);
    Solver solver(computTri, 2, funcPot);

    // Solve for first potential
    std::map<Vertex*, std::vector<double>> doubleCrossLifting;
    for(auto &kv: crossLifting[0]){
      std::vector<double> doublePot(6, 0.0);
      doubleCrossLifting[kv.first] = doublePot;
    }

    for(size_t k=0; k<2; k++)
      for(auto &kv: crossLifting[k]){
	for(size_t l=0; l<3; l++)
	  doubleCrossLifting[kv.first][3*k + l] = kv.second[l];
      }

    // solver.m_nodeData = doubleCrossLifting;
    solver.setNodeData(doubleCrossLifting);
    //Fix one value to zero for each potential
    Vertex *v = cutMesh.m_pVertices[0];
    for(size_t k=0; k<2; k++){
      std::vector<std::pair<Vertex *, int>> dirichletBC;
      dirichletBC.push_back(std::make_pair(v, k));
      std::vector<double> valDirichlet{0.0};
      solver.addBCDirichlet(dirichletBC, valDirichlet);
    }
    if(m_forceSeamless){
      //Constant value on boundary for both potentials
      for(auto &vectVpotInd: cstPotBC){
	for(size_t k=1; k<vectVpotInd.first.size(); k++){
	  std::vector<std::vector<double>> mat;
	  mat.resize(1);
	  mat[0].resize(2, 0.0);
	  mat[0][0] = 1.0;
	  mat[0][1] = -1.0;
	  std::vector<double> vect{0.0};
	  std::vector<std::pair<Vertex *, int>> pairVertexField{std::make_pair(vectVpotInd.first[0], vectVpotInd.second), std::make_pair(vectVpotInd.first[k], vectVpotInd.second)};
	  solver.addBCLinearCombination(mat, vect, pairVertexField);
	}
      }
  
      //Compatibility conditions at cutgraph
      std::cout << "BC compatibility" << std::endl;
      _addCGcompatibilityConditions(solver, cutMesh, crossLifting);
    }
    
    //Solve problem
    std::cout << "Solve potentials" << std::endl;
    std::map<Vertex *, std::vector<double>> pots;
    solver.solve(pots);

    std::cout << "tranfer sol" << std::endl;
    std::vector<double> vectPotU;
    vectPotU.resize(cutMesh.m_pVertices.size(), 0.0);
    std::vector<double> vectPotV;
    vectPotV.resize(cutMesh.m_pVertices.size(), 0.0);
    size_t index = 0;
    for(Vertex *v: cutMesh.m_pVertices){
      v->setIndex(index);
      index++;
    }
    for(auto &kv: pots){
      vectPotU[kv.first->getIndex()] = kv.second[0];
      vectPotV[kv.first->getIndex()] = kv.second[1];
    }

    m_rangePotU[0] = *min_element(vectPotU.begin(), vectPotU.end());
    m_rangePotU[1] = *max_element(vectPotU.begin(), vectPotU.end());
    m_rangePotV[0] = *min_element(vectPotV.begin(), vectPotV.end());
    m_rangePotV[1] = *max_element(vectPotV.begin(), vectPotV.end());    
    m_potU.clear();
    m_potV.clear();
    for(size_t k=0; k<m_mesh->m_pTriangles.size(); k++){
      Triangle *t = cutMesh.m_pTriangles[k];
      if(std::find(computTri.begin(), computTri.end(), t) != computTri.end()){
	std::vector<double> potUtri{vectPotU[t->getVertex(0)->getIndex()], vectPotU[t->getVertex(1)->getIndex()], vectPotU[t->getVertex(2)->getIndex()]};
	std::vector<double> potVtri{vectPotV[t->getVertex(0)->getIndex()], vectPotV[t->getVertex(1)->getIndex()], vectPotV[t->getVertex(2)->getIndex()]};
	m_potU[m_mesh->m_pTriangles[k]] = potUtri;
	m_potV[m_mesh->m_pTriangles[k]] = potVtri;
      }
    }
    //DBG
    std::cout << "size crosslifting: " << crossLifting[0].size() << std::endl;
    std::cout << "size crosslifting: " << crossLifting[1].size() << std::endl;
    std::map<Triangle* , std::vector<double>> solDBG;
    std::vector<double> initVect(9, 0.0);
    for(size_t k=0; k<m_mesh->m_pTriangles.size(); k++)
      solDBG[m_mesh->m_pTriangles[k]] = initVect;
    for(size_t k=0; k<m_mesh->m_pTriangles.size(); k++){
      Triangle *t = m_mesh->m_pTriangles[k];
      for(size_t l=0; l<3; l++){
	for(size_t m=0; m<3; m++)
	  solDBG[t][3*l+m] = crossLifting[0][cutMesh.m_pTriangles[k]->getVertex(l)][m];
      }
    }
    std::cout << "solDBG size: " << solDBG.size() << std::endl;
    visu::vectorfield(solDBG, "liftU");
    for(size_t k=0; k<m_mesh->m_pTriangles.size(); k++){
      Triangle *t = m_mesh->m_pTriangles[k];
      for(size_t l=0; l<3; l++){
	for(size_t m=0; m<3; m++)
	  solDBG[t][3*l+m] = crossLifting[1][cutMesh.m_pTriangles[k]->getVertex(l)][m];
      }
    }

    std::cout << "solDBG size: " << solDBG.size() << std::endl;
    visu::vectorfield(solDBG, "liftV");
  }

  void CrossField2D::_computePotentialsOld(){
    _detectSingularities();
    m_mesh->m_pSingularities = m_singularities;
    m_mesh->createCutGraph();
    Mesh cutMesh;
    m_mesh->splitMeshOnEdges(m_mesh->m_cutGraph, cutMesh);
    std::vector<std::map<Vertex*, std::vector<double>>> crossLifting = _getLifting(cutMesh);
    // Modify lifting norms to feat gradient of potential
    for(auto &kv: crossLifting[0]){
      double norm = fmax(tools::norm(kv.second), 1e-12);
      for(size_t k=0; k<kv.second.size(); k++)
	kv.second[k] = kv.second[k]/(norm*norm);
    }
    for(auto &kv: crossLifting[1]){
      double norm = fmax(tools::norm(kv.second), 1e-12);
      for(size_t k=0; k<kv.second.size(); k++)
	kv.second[k] = kv.second[k]/(norm*norm);
    }

    std::vector<std::pair<std::vector<Vertex *>, int>> cstPotBC = _getConstantPotBC(crossLifting, cutMesh);
    std::cout << "n bc const: " << cstPotBC.size() << std::endl;
    Potential *funcPot = new Potential();
    Solver solver(cutMesh.m_pTriangles, 1, funcPot);
    // Solve for first potential
    solver.m_nodeData = crossLifting[0];
    Vertex *v = cutMesh.m_pVertices[0];
    std::vector<std::pair<Vertex *, int>> dirichletBC;
    dirichletBC.push_back(std::make_pair(v, 0));
    std::vector<double> valDirichlet{0.0};
    solver.addBCDirichlet(dirichletBC, valDirichlet);
    for(auto &vectVpotInd: cstPotBC){
      if(vectVpotInd.second == 0){
	for(size_t k=1; k<vectVpotInd.first.size(); k++){
	  std::vector<std::vector<double>> mat;
	  mat.resize(1);
	  mat[0].resize(2, 0.0);
	  mat[0][0] = 1.0;
	  mat[0][1] = -1.0;
	  std::vector<double> vect{0.0};
	  std::vector<std::pair<Vertex *, int>> pairVertexField{std::make_pair(vectVpotInd.first[0], 0), std::make_pair(vectVpotInd.first[k], 0)};
	  solver.addBCLinearCombination(mat, vect, pairVertexField);
	}
      }
    }
    std::map<Vertex *, std::vector<double>> potU;
    solver.solve(potU);
    // Solve for second potential
    solver.clearBC();
    solver.addBCDirichlet(dirichletBC, valDirichlet);
    for(auto &vectVpotInd: cstPotBC){
      if(vectVpotInd.second == 1){
	for(size_t k=1; k<vectVpotInd.first.size(); k++){
	  std::vector<std::vector<double>> mat;
	  mat.resize(1);
	  mat[0].resize(2, 0.0);
	  mat[0][0] = 1.0;
	  mat[0][1] = -1.0;
	  std::vector<double> vect{0.0};
	  std::vector<std::pair<Vertex *, int>> pairVertexField{std::make_pair(vectVpotInd.first[0], 0), std::make_pair(vectVpotInd.first[k], 0)};
	  solver.addBCLinearCombination(mat, vect, pairVertexField);
	}
      }
    }
    solver.m_nodeData = crossLifting[1];
    std::map<Vertex *, std::vector<double>> potV;
    solver.solve(potV);
    std::vector<double> vectPotU;
    vectPotU.resize(cutMesh.m_pVertices.size(), 0.0);
    std::vector<double> vectPotV;
    vectPotV.resize(cutMesh.m_pVertices.size(), 0.0);
    size_t index = 0;
    for(Vertex *v: cutMesh.m_pVertices){
      v->setIndex(index);
      index++;
    }
    for(auto &kv: potU)
      vectPotU[kv.first->getIndex()] = kv.second[0];
    for(auto &kv: potV)
      vectPotV[kv.first->getIndex()] = kv.second[0];
    m_rangePotU[0] = *min_element(vectPotU.begin(), vectPotU.end());
    m_rangePotU[1] = *max_element(vectPotU.begin(), vectPotU.end());
    m_rangePotV[0] = *min_element(vectPotV.begin(), vectPotV.end());
    m_rangePotV[1] = *max_element(vectPotV.begin(), vectPotV.end());    
    m_potU.clear();
    m_potV.clear();
    for(size_t k=0; k<m_mesh->m_pTriangles.size(); k++){
      Triangle *t = cutMesh.m_pTriangles[k];
      std::vector<double> potUtri{vectPotU[t->getVertex(0)->getIndex()], vectPotU[t->getVertex(1)->getIndex()], vectPotU[t->getVertex(2)->getIndex()]};
      std::vector<double> potVtri{vectPotV[t->getVertex(0)->getIndex()], vectPotV[t->getVertex(1)->getIndex()], vectPotV[t->getVertex(2)->getIndex()]};
      m_potU[m_mesh->m_pTriangles[k]] = potUtri;
      m_potV[m_mesh->m_pTriangles[k]] = potVtri;
    }
    //DBG
    std::cout << "size crosslifting: " << crossLifting[0].size() << std::endl;
    std::cout << "size crosslifting: " << crossLifting[1].size() << std::endl;
    std::map<Triangle* , std::vector<double>> solDBG;
    std::vector<double> initVect(9, 0.0);
    for(size_t k=0; k<m_mesh->m_pTriangles.size(); k++)
      solDBG[m_mesh->m_pTriangles[k]] = initVect;
    for(size_t k=0; k<m_mesh->m_pTriangles.size(); k++){
      Triangle *t = m_mesh->m_pTriangles[k];
      for(size_t l=0; l<3; l++){
	for(size_t m=0; m<3; m++)
	  solDBG[t][3*l+m] = crossLifting[0][cutMesh.m_pTriangles[k]->getVertex(l)][m];
      }
    }
    std::cout << "solDBG size: " << solDBG.size() << std::endl;
    visu::vectorfield(solDBG, "liftU");
    for(size_t k=0; k<m_mesh->m_pTriangles.size(); k++){
      Triangle *t = m_mesh->m_pTriangles[k];
      for(size_t l=0; l<3; l++){
	for(size_t m=0; m<3; m++)
	  solDBG[t][3*l+m] = crossLifting[1][cutMesh.m_pTriangles[k]->getVertex(l)][m];
      }
    }
    // for(size_t k=0; k<m_mesh->m_pTriangles.size(); k++){
    //   Triangle *t = m_mesh->m_pTriangles[k];
    //   for(size_t l=0; l<3; l++){
    //     solDBG[t->getVertex(l)] = crossLifting[1][cutMesh.m_pTriangles[k]->getVertex(l)];
    //   }
    // }
    std::cout << "solDBG size: " << solDBG.size() << std::endl;
    visu::vectorfield(solDBG, "liftV");
  }

  std::vector<std::map<Vertex*, std::vector<double>>> CrossField2D::_getLifting(Mesh &cm){
    std::vector<std::map<Vertex*, std::vector<double>>> lift;
    lift.resize(2);
    for(Vertex *v: cm.m_pVertices){
      std::vector<double> initDir(3, 0.0);
      lift[0][v] = initDir;
      lift[1][v] = initDir;
    }
    //Transfer crossfield2D from mesh to cutMesh
    std::vector<Cross2D> vectCrossfieldCutMesh;
    std::vector<Cross2D> vectCrossfield;
    vectCrossfieldCutMesh.resize(cm.m_vertices.size());
    vectCrossfield.resize(m_crossfield.size());
    size_t index=0;
    for(auto &kv: m_crossfield){
      kv.first->setIndex(index);
      vectCrossfield[index] = kv.second;
      index++;
    }
    index = 0;
    for(Vertex &v: cm.m_vertices){
      v.setIndex(index);
      index++;
    }
    for(size_t k=0; k<m_mesh->m_pTriangles.size(); k++){
      Triangle *t = m_mesh->m_pTriangles[k];
      for(size_t l=0; l<3; l++){
	vectCrossfieldCutMesh[cm.m_triangles[k].getVertex(l)->getIndex()] = vectCrossfield[t->getVertex(l)->getIndex()];
      }
    }
    //Create Liftings
    std::vector<bool> isVertSingular;
    isVertSingular.resize(cm.m_vertices.size(), false);
    // for(Vertex *v: m_singularities){
    for(Vertex *v: m_verticesSingularTriangles){
      isVertSingular[cm.m_pVertices[m_mesh->m_tagToVertices[v->getTag()]]->getIndex()] = true;
    }
    // for(size_t k=0; k<m_mesh->m_triangles.size(); k++){
    //   m_mesh->m_triangles[k].setIndex(k);
    //   cm.m_triangles[k].setIndex(k);
    // }
    // for(Triangle *t: m_singularTriangles){
    //   for(size_t l=0; l<3; l++){
    //     Vertex *v = cm.m_triangles[t->getIndex()].getVertex(l);
    //     isVertSingular[cm.m_pVertices[cm.m_tagToVertices[v->getTag()]]->getIndex()] = true;
    //   }
    // }
    size_t nSingVert = 0;
    for(bool b: isVertSingular)
      if(b)
	nSingVert++;
    // std::cout << "n sing vert: " << nSingVert << std::endl;
    std::queue<std::pair<Vertex*, std::vector<std::vector<double>>>> vertQueue;
    std::vector<std::vector<double>> refDirs;
    refDirs.reserve(2);
    std::vector<double> refU{1.0, 0.0, 0.0};
    std::vector<double> refV{0.0, 1.0, 0.0};
    refDirs.push_back(refU);
    refDirs.push_back(refV);
    std::vector<bool> vertPushed;
    vertPushed.resize(cm.m_pVertices.size(), false);
    size_t indexInit = isVertSingular.size()/2;
    while(vertQueue.size() == 0){
      if(!isVertSingular[cm.m_pVertices[indexInit]->getIndex()]){
	std::vector<std::vector<double>> refDirVertInit = vectCrossfieldCutMesh[cm.m_pVertices[indexInit]->getIndex()].getDirections();
	vertQueue.push(std::make_pair(cm.m_pVertices[indexInit], refDirVertInit));
	vertPushed[cm.m_pVertices[indexInit]->getIndex()] = true;
	// std::cout << "indexInit: " << indexInit << std::endl;
      }
      indexInit++;
    }

    size_t cpt = 0;
    while(vertQueue.size() > 0 && cpt < cm.m_pVertices.size()){
      std::pair<Vertex *, std::vector<std::vector<double>>> kv = vertQueue.front();
      vertQueue.pop();
      // std::cout << "vertex tag: " << kv.first->getTag() << std::endl;
      std::vector<double> U = vectCrossfieldCutMesh[kv.first->getIndex()].getClosestDirection(kv.second[0]);
      std::vector<double> n{0.0, 0.0, 1.0};
      std::vector<double> V = tools::crossprod(n, U);
    
      lift[0][kv.first] = U;
      lift[1][kv.first] = V;

      if(!isVertSingular[kv.first->getIndex()]){
	for(Vertex *v: cm.m_verticesNeighbours[kv.first]){
	  if(!vertPushed[v->getIndex()]){
	    std::vector<std::vector<double>> refDirNewV{U, V};
	    vertQueue.push(std::make_pair(v, refDirNewV));
	    vertPushed[v->getIndex()] = true;
	  }
	}
      }
      cpt++;
    }
    std::cout << "end lifting" << std::endl;
  
    return lift;
  }

  void CrossField2D::_detectSingularities(){
    m_singularities.clear();
    std::vector<Triangle*> triangles = m_mesh->m_pTriangles;
    std::vector<Vertex*> vertices = m_mesh->m_pVertices;
    for(size_t k=0; k<triangles.size(); k++)
      triangles[k]->setIndex(k);
    for(size_t k=0; k<vertices.size(); k++)
      vertices[k]->setIndex(k);
    // Find Singular triangles
    std::vector<double> singularTriangles;
    m_singularTriangles.clear();
    singularTriangles.resize(triangles.size(), 0.0);

    std::vector<Cross2D> crossfield;
    crossfield.resize(vertices.size());
    for(auto &kv: m_crossfield)
      crossfield[kv.first->getIndex()] = kv.second;

    size_t nSingTri = 0;
    for(auto tri: triangles){
      Cross2D *c0 = &(crossfield[tri->getVertex(0)->getIndex()]);
      std::vector<std::vector<double>> refDirs = c0->getDirections();
      std::vector<double> refDir = refDirs[0];
      std::vector<double> refDirTemp = refDir;
      std::vector<double> newDir = refDirTemp;
      for(size_t k=1; k<3; k++){
	Cross2D *c = &(crossfield[tri->getVertex(k)->getIndex()]);
	newDir = c->getClosestDirection(refDirTemp);
	refDirTemp = newDir;
      }
      std::vector<double> lastDir = c0->getClosestDirection(newDir);
      double norm = tools::distance(lastDir, refDir);
      if(norm > 1e-12){
	std::vector<double> cp = tools::crossprod(refDir, lastDir);
	if(tools::dotprod(cp, tri->m_normal)>0.0){
	  singularTriangles[tri->getIndex()] = -1.0;
	  nSingTri++;
	}
	if(tools::dotprod(cp, tri->m_normal)<0.0){
	  singularTriangles[tri->getIndex()] = 1.0;
	  nSingTri++;
	}
      }
    }

    std::map<Triangle *, double> mapSingularTriangles;
    for(Triangle *t: triangles)
      if(singularTriangles[t->getIndex()] != 0.0){
	mapSingularTriangles[t] = singularTriangles[t->getIndex()];
	m_singularTriangles.push_back(t);
      }
  
    visu::scalarfield(mapSingularTriangles, "SingInCF2D");

    //Flag singular vertices
    for(auto &kv: mapSingularTriangles){
      // if(fabs(kv.second) > 1e-12)
      //   m_singularities.push_back(kv.first->getVertex(0));
      for(Vertex *v: kv.first->m_vertices){
	m_verticesSingularTriangles.push_back(v);
	m_singularities.push_back(v);
      }
    }
  }

}
