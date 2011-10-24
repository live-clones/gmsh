// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "Gmsh.h"
#include "GModel.h"
#include "GmshMessage.h"
#include "JacobianBasis.h"
#include "polynomialBasis.h"
#include "AnalyseCurvedMesh.h"
#include "FlGui.h"
#include "Context.h"
#include "drawContext.h"
#include "OS.h"
#define UNDEF_JAC_TAG -999


StringXNumber JacobianOptions_Number[] = {
  {GMSH_FULLRC, "Dim", NULL, -1},
  /*{GMSH_FULLRC, "Analysis", NULL, 1},*/
  {GMSH_FULLRC, "Effect", NULL, 6},
  {GMSH_FULLRC, "MaxDepth", NULL, 10},
  {GMSH_FULLRC, "JacBreak", NULL, .0},
  {GMSH_FULLRC, "BezBreak", NULL, .0},
  /*{GMSH_FULLRC, "Tolerance", NULL, 1e-5}*/
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterAnalyseCurvedMeshPlugin()
  {
    return new GMSH_AnalyseCurvedMeshPlugin();
  }
}
int GMSH_AnalyseCurvedMeshPlugin::getNbOptions() const
{
  return sizeof(JacobianOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_AnalyseCurvedMeshPlugin::getOption(int iopt)
{
  return &JacobianOptions_Number[iopt];
}

std::string GMSH_AnalyseCurvedMeshPlugin::getHelp() const
{
  return "Plugin(AnalyseCurvedMesh) check the jacobian of all elements of dimension 'Dim' or "
    "the greater model dimension if 'Dim' is either <0 or >3.\n\n "
    //"Elements for which we are absolutely certain that they are good (positive jacobian) are ignored. "
    //"Others are wrong or suppose to be wrong.\n\n"
    //"Plugin(AnalyseCurvedMesh) write in the console which elements are wrong. "
    //"(if labels of analysed type of elements are set visible, only wrong elements will be visible)\n\n"
    /*"Analysis : 0 do nothing\n"
    "          +1 find invalid elements (*)\n"
    "          +2 compute min and max of all elements and print some statistics\n\n"*/
    /*"Effect (for *) : 0 do nothing\n"*/
    "Effect : 0 do nothing\n"
    "                +1 print a list of invalid elements\n"
    "                +2 print some statistics\n"
    "                +4 hide valid elements (for GUI)\n\n"
    "MaxDepth = {0,1,...}\n"
    "         0 : only sample the jacobian\n"
    "         1 : compute Bezier coefficients\n"
    "        2+ : execute a maximum of 1+ subdivision(s)\n\n"
    "JacBreak = [0,1[ : if a value of the jacobian <= 'JacBreak' is found, "
    "the element is said to be invalid\n\n"
    "BezBreak = [0,JacBreak[ : if all Bezier coefficients are > 'BezBreak', "
    "the element is said to be valid\n\n"
    /*"Tolerance = R+ , << 1 : tolerance (relatively to J_avg.) used during the computation of min and max"*/;
}

// Miscellaneous method
/*int max(const std::vector<int> &vec)
{
  int max = vec[0];
  for (unsigned int i = 1; i < vec.size(); i++)
    if (vec[i] > max) max = vec[i];
  return max;
}*/

/*static double computeDeterminant(MElement *el, double jac[3][3])
{
  switch (el->getDim()) {
  case 0:
    return 1.0;
  case 1:
    return jac[0][0];
  case 2:
    return jac[0][0] * jac[1][1] - jac[0][1] * jac[1][0];
  case 3:
    return jac[0][0] * jac[1][1] * jac[2][2] + jac[0][2] * jac[1][0] * jac[2][1] +
           jac[0][1] * jac[1][2] * jac[2][0] - jac[0][2] * jac[1][1] * jac[2][0] -
           jac[0][0] * jac[1][2] * jac[2][1] - jac[0][1] * jac[1][0] * jac[2][2];
  default:
    return 1;
  }
}

double getJacobian(double gsf[][3], double jac[3][3], MElement *el)
{
  jac[0][0] = jac[0][1] = jac[0][2] = 0.;
  jac[1][0] = jac[1][1] = jac[1][2] = 0.;
  jac[2][0] = jac[2][1] = jac[2][2] = 0.;

  for (int i = 0; i < el->getNumVertices(); i++) {
    const MVertex *v = el->getVertex(i);
    double *gg = gsf[i];
    for (int j = 0; j < 3; j++) {
      jac[j][0] += v->x() * gg[j];
      jac[j][1] += v->y() * gg[j];
      jac[j][2] += v->z() * gg[j];
    }
  }

  return computeDeterminant(el, jac);
}*/

static void setJacobian(MElement *el, const JacobianBasis *jfs, fullVector<double> &jacobian)
{
  int numVertices = el->getNumVertices();
  fullVector<double> nodesX(numVertices);
  fullVector<double> nodesY;
  fullVector<double> nodesZ;
  fullVector<double> interm1;
  fullVector<double> interm2;
  
  switch (el->getDim()) {
    
    case 1 :
      for (int i = 0; i < numVertices; i++) {
        nodesX(i) = el->getVertex(i)->x();
      }
      jfs->gradShapeMatX.mult(nodesX, jacobian);
      break;
    
    case 2 :
      nodesY.resize(numVertices);
      interm1.resize(jacobian.size());
      interm2.resize(jacobian.size());
      
      for (int i = 0; i < numVertices; i++) {
        nodesX(i) = el->getVertex(i)->x();
        nodesY(i) = el->getVertex(i)->y();
      }
      
      jfs->gradShapeMatX.mult(nodesX, jacobian);
      jfs->gradShapeMatY.mult(nodesY, interm2);
      jacobian.multTByT(interm2);
      
      jfs->gradShapeMatY.mult(nodesX, interm1);
      jfs->gradShapeMatX.mult(nodesY, interm2);
      interm1.multTByT(interm2);
      
      jacobian.axpy(interm1, -1);
      break;
    
    case 3 :
      nodesY.resize(numVertices);
      nodesZ.resize(numVertices);
      interm1.resize(jacobian.size());
      interm2.resize(jacobian.size());
      
      for (int i = 0; i < numVertices; i++) {
        nodesX(i) = el->getVertex(i)->x();
        nodesY(i) = el->getVertex(i)->y();
        nodesZ(i) = el->getVertex(i)->z();
      }
      
      jfs->gradShapeMatX.mult(nodesX, jacobian);
      jfs->gradShapeMatY.mult(nodesY, interm2);
      jacobian.multTByT(interm2);
      jfs->gradShapeMatZ.mult(nodesZ, interm2);
      jacobian.multTByT(interm2);
      
      jfs->gradShapeMatX.mult(nodesY, interm1);
      jfs->gradShapeMatY.mult(nodesZ, interm2);
      interm1.multTByT(interm2);
      jfs->gradShapeMatZ.mult(nodesX, interm2);
      interm1.multTByT(interm2);
      jacobian.axpy(interm1, 1);
      
      jfs->gradShapeMatX.mult(nodesZ, interm1);
      jfs->gradShapeMatY.mult(nodesX, interm2);
      interm1.multTByT(interm2);
      jfs->gradShapeMatZ.mult(nodesY, interm2);
      interm1.multTByT(interm2);
      jacobian.axpy(interm1, 1);
      
      
      jfs->gradShapeMatX.mult(nodesY, interm1);
      jfs->gradShapeMatY.mult(nodesX, interm2);
      interm1.multTByT(interm2);
      jfs->gradShapeMatZ.mult(nodesZ, interm2);
      interm1.multTByT(interm2);
      jacobian.axpy(interm1, -1);
      
      jfs->gradShapeMatX.mult(nodesZ, interm1);
      jfs->gradShapeMatY.mult(nodesY, interm2);
      interm1.multTByT(interm2);
      jfs->gradShapeMatZ.mult(nodesX, interm2);
      interm1.multTByT(interm2);
      jacobian.axpy(interm1, -1);
      
      jfs->gradShapeMatX.mult(nodesX, interm1);
      jfs->gradShapeMatY.mult(nodesZ, interm2);
      interm1.multTByT(interm2);
      jfs->gradShapeMatZ.mult(nodesY, interm2);
      interm1.multTByT(interm2);
      jacobian.axpy(interm1, -1);
  }
}



void setJacobian(MElement *const *el, const JacobianBasis *jfs, fullMatrix<double> &jacobian)
{
  int numEl = jacobian.size2();
  int numVertices = el[0]->getNumVertices();
  fullMatrix<double> nodesX(numVertices,numEl);
  fullMatrix<double> nodesY;
  fullMatrix<double> nodesZ;
  fullMatrix<double> interm1;
  fullMatrix<double> interm2;
  
  switch (el[0]->getDim()) {
    
    case 1 :
      for (int j = 0; j < numEl; j++) {
        for (int i = 0; i < numVertices; i++) {
          nodesX(i,j) = el[j]->getVertex(i)->x();
        }
      }
      jfs->gradShapeMatX.mult(nodesX, jacobian);
      break;
    
    
    case 2 :
      nodesY.resize(numVertices,numEl);
      interm1.resize(jacobian.size1(),jacobian.size2());
      interm2.resize(jacobian.size1(),jacobian.size2());
      
      for (int j = 0; j < numEl; j++) {
        for (int i = 0; i < numVertices; i++) {
          nodesX(i,j) = el[j]->getVertex(i)->x();
          nodesY(i,j) = el[j]->getVertex(i)->y();
        }
      }
      
      jfs->gradShapeMatX.mult(nodesX, jacobian);
      jfs->gradShapeMatY.mult(nodesY, interm2);
      jacobian.multTByT(interm2);
      
      jfs->gradShapeMatY.mult(nodesX, interm1);
      jfs->gradShapeMatX.mult(nodesY, interm2);
      interm1.multTByT(interm2);
      
      jacobian.add(interm1, -1);
      break;
    
    case 3 :
      nodesY.resize(numVertices,numEl);
      nodesZ.resize(numVertices,numEl);
      interm1.resize(jacobian.size1(),jacobian.size2());
      interm2.resize(jacobian.size1(),jacobian.size2());
      
      for (int j = 0; j < numEl; j++) {
        for (int i = 0; i < numVertices; i++) {
          nodesX(i,j) = el[j]->getVertex(i)->x();
          nodesY(i,j) = el[j]->getVertex(i)->y();
          nodesZ(i,j) = el[j]->getVertex(i)->z();
        }
      }
      
      jfs->gradShapeMatX.mult(nodesX, jacobian);
      jfs->gradShapeMatY.mult(nodesY, interm2);
      jacobian.multTByT(interm2);
      jfs->gradShapeMatZ.mult(nodesZ, interm2);
      jacobian.multTByT(interm2);
      
      jfs->gradShapeMatX.mult(nodesY, interm1);
      jfs->gradShapeMatY.mult(nodesZ, interm2);
      interm1.multTByT(interm2);
      jfs->gradShapeMatZ.mult(nodesX, interm2);
      interm1.multTByT(interm2);
      jacobian.add(interm1, 1);
      
      jfs->gradShapeMatX.mult(nodesZ, interm1);
      jfs->gradShapeMatY.mult(nodesX, interm2);
      interm1.multTByT(interm2);
      jfs->gradShapeMatZ.mult(nodesY, interm2);
      interm1.multTByT(interm2);
      jacobian.add(interm1, 1);
      
      
      jfs->gradShapeMatX.mult(nodesY, interm1);
      jfs->gradShapeMatY.mult(nodesX, interm2);
      interm1.multTByT(interm2);
      jfs->gradShapeMatZ.mult(nodesZ, interm2);
      interm1.multTByT(interm2);
      jacobian.add(interm1, -1);
      
      jfs->gradShapeMatX.mult(nodesZ, interm1);
      jfs->gradShapeMatY.mult(nodesY, interm2);
      interm1.multTByT(interm2);
      jfs->gradShapeMatZ.mult(nodesX, interm2);
      interm1.multTByT(interm2);
      jacobian.add(interm1, -1);
      
      jfs->gradShapeMatX.mult(nodesX, interm1);
      jfs->gradShapeMatY.mult(nodesZ, interm2);
      interm1.multTByT(interm2);
      jfs->gradShapeMatZ.mult(nodesY, interm2);
      interm1.multTByT(interm2);
      jacobian.add(interm1, -1);
      
    default :
      break;
  }
}

// Execution
PView *GMSH_AnalyseCurvedMeshPlugin::execute(PView *v)
{
  _m = GModel::current();
  _dim = (int) JacobianOptions_Number[0].def;
  if (_dim < 0 || _dim > 3)
    _dim = _m->getDim();
  /*int analysis = (int) JacobianOptions_Number[1].def % 2;*/
  int analysis = 1;
  int toDo = (int) JacobianOptions_Number[1].def % 8;
  _maxDepth = (int) JacobianOptions_Number[2].def;
  _jacBreak = (double) JacobianOptions_Number[3].def;
  _bezBreak = (double) JacobianOptions_Number[4].def;
  _tol = 1;/*(double) JacobianOptions_Number[5].def;*/
  
  if (analysis % 2) {
    double t = Cpu();
    Msg::Info("Strating validity check...");
    checkValidity(toDo);
    Msg::Info("Done validity check (%fs)", Cpu()-t);
  }
  if (analysis / 2) {
    computeMinMax();
  }
}
  
//{
//  Msg::Info("AnalyseCurvedMeshPlugin : Starting analysis.");
//  int numBadEl = 0;
//  int numUncertain = 0;
//  int numAnalysedEl = 0;
//  std::vector<int> tag;
//  int method = (int)JacobianOptions_Number[0].def % 4;
//  int maxDepth = (int)JacobianOptions_Number[1].def;
//
//  if (method < 1 || method > 2) {
//#if defined(HAVE_BLAS)
//    method = 2;
//#else
//    method = 1;
//#endif
//  } 
//
//  GModel *m = GModel::current();
//  switch (m->getDim()) {
//
//    case 3 :
//      Msg::Info("Only 3D elements will be analyse.");
//      for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); it++) {
//        GRegion *r = *it;
//        
//        unsigned int numType[5] = {0, 0, 0, 0, 0};
//        r->getNumMeshElements(numType);
//
//        for(int type = 0; type < 5; type++) {
//          MElement *const *el = r->getStartElementType(type);
//          
//          int *a;
//          a = checkJacobian(el, numType[type], maxDepth, method);
//          numUncertain += a[0];
//          numBadEl += a[1];
//          numAnalysedEl += numType[type];
//          delete[] a;
//
//          /*for(unsigned int i = 0; i < numType[type]; i++) {
//            numAnalysedEl++;
//            if (checkJacobian(el[i], maxDepth) <= 0) numBadEl++;
//          }*/
//        }
//      }
//      break;
//
//    case 2 :
//      Msg::Info("Only 2D elements will be analyse.");
//      Msg::Warning("2D elements must be in a z=cst plane ! If they aren't, results won't be correct.");
//      for (GModel::fiter it = m->firstFace(); it != m->lastFace(); it++) {
//        GFace *f = *it;
//        
//        unsigned int numType[3] = {0, 0, 0};
//        f->getNumMeshElements(numType);
//
//        for (int type = 0; type < 3; type++) {
//          MElement *const *el = f->getStartElementType(type);
//
//          int *a;
//          a = checkJacobian(el, numType[type], maxDepth, method);
//          numUncertain += a[0];
//          numBadEl += a[1];
//          numAnalysedEl += numType[type];
//          delete[] a;
//
//          /*for (unsigned int i = 0; i < numType[type]; i++) {
//            numAnalysedEl++;
//            if (checkJacobian(el[i], maxDepth) <= 0) numBadEl++;
//          }*/
//        }
//      }
//      break;
//
//    case 1 :
//      Msg::Info("Only 1D elements will be analyse.");
//      Msg::Warning("1D elements must be on a y=cst & z=cst line ! If they aren't, results won't be correct.");
//      for (GModel::eiter it = m->firstEdge(); it != m->lastEdge(); it++) {
//        GEdge *e = *it;
//        
//        unsigned int numElement = e->getNumMeshElements();
//        MElement *const *el = e->getStartElementType(0);
//
//        int *a;
//        a = checkJacobian(el, numElement, maxDepth, method);
//        numUncertain += a[0];
//        numBadEl += a[1];
//        numAnalysedEl += numElement;
//        delete[] a;
//
//        /*for (unsigned int i = 0; i < numElement; i++) {
//          numAnalysedEl++;
//          if (checkJacobian(el[i], maxDepth) <= 0) numBadEl++;
//        }*/
//      }
//      break;
//
//    default :
//      Msg::Error("I can't analyse any element.");
//  }
//
//
//  //Set all visibility of smaller dimension elements to 0
//  switch (m->getDim()) {
//    case 2 :
//      for (GModel::fiter it = m->firstFace(); it != m->lastFace(); it++) {
//        GFace *f = *it;
//        
//        unsigned int numType[3] = {0, 0, 0};
//        f->getNumMeshElements(numType);
//
//        for (int type = 0; type < 3; type++) {
//          MElement *const *el = f->getStartElementType(type);
//          for (unsigned int i = 0; i < numType[type]; i++) {
//            el[i]->setVisibility(0);
//          }
//        }
//      }
//    case 1 :
//      for (GModel::eiter it = m->firstEdge(); it != m->lastEdge(); it++) {
//        GEdge *e = *it;
//        
//        unsigned int numElement = e->getNumMeshElements();
//        MElement *const *el = e->getStartElementType(0);
//
//        for (unsigned int i = 0; i < numElement; i++) {
//          el[i]->setVisibility(0);
//        }
//      }
//      break;
//  }
//  
//  Msg::Info("%d elements have been analysed.", numAnalysedEl);
//  Msg::Info("%d elements were bad.", numBadEl);
//  Msg::Info("%d elements were undetermined.", numUncertain);
//  Msg::Info("AnalyseCurvedMeshPlugin : Job finished.");
//
//  return 0;
//}


void GMSH_AnalyseCurvedMeshPlugin::checkValidity(int toDo)
{
  std::vector<MElement*> invalids;
  _numAnalysedEl = 0;
  _numInvalid = 0;
  _numValid = 0;
  _numUncertain = 0;
  
  switch (_dim) {
    case 3 :
      for(GModel::riter it = _m->firstRegion(); it != _m->lastRegion(); it++) {
        GRegion *r = *it;
        unsigned int numType[5] = {0, 0, 0, 0, 0};
        r->getNumMeshElements(numType);
        
        for(int type = 0; type < 5; type++) {
          MElement *const *el = r->getStartElementType(type);
          checkValidity(el, numType[type], invalids);
          _numAnalysedEl += numType[type];
        }
      }
      break;
    
    case 2 :
      Msg::Warning("2D elements must be in a z=cst plane ! If they aren't, results won't be correct.");
      for (GModel::fiter it = _m->firstFace(); it != _m->lastFace(); it++) {
        GFace *f = *it;
        unsigned int numType[3] = {0, 0, 0};
        f->getNumMeshElements(numType);
        
        for (int type = 0; type < 3; type++) {
          MElement *const *el = f->getStartElementType(type);
          checkValidity(el, numType[type], invalids);
          _numAnalysedEl += numType[type];
        }
      }
      break;
    
    case 1 :
      Msg::Warning("1D elements must be on a y=cst & z=cst line ! If they aren't, results won't be correct.");
      for (GModel::eiter it = _m->firstEdge(); it != _m->lastEdge(); it++) {
        GEdge *e = *it;
        unsigned int numElement = e->getNumMeshElements();
        MElement *const *el = e->getStartElementType(0);
        checkValidity(el, numElement, invalids);
        _numAnalysedEl += numElement;
      }
      break;
    
    default :
      Msg::Error("I can't analyse any element.");
  }
  
  if (toDo % 2) {
    Msg::Info("Invalids elements :");
    Msg::Info("-------------------");
    for (unsigned int i = 0; i < invalids.size(); ++i) {
      Msg::Info(" %d", invalids[i]->getNum());
    }
  }
  if (toDo / 2 % 2) {
    Msg::Info("Found %d invalid elements and %d valid", _numInvalid, _numValid);
    if (_numUncertain) {
      Msg::Info("%d uncertain elements.", _numUncertain);
      if (_jacBreak < _bezBreak) {
        Msg::Info("'JacBreak' is smaller than 'BezBreak'. Change values in order to decrease the number of uncertain elements.");
      }
      else {
        Msg::Info("Increase MaxDepth in order to decrease the number of uncertain elements.");
      }
    }
    Msg::Info("%d elements analysed", _numAnalysedEl);
  }
  if (toDo / 4 % 2) {
    Msg::Info("Note: Valid elements are hidden. Change 'Effect' to disable this functionality.");
    Msg::Info("(To revert visibility : Tools > Visibility > Interactive > Show All)");
    hideValid_ShowInvalid(invalids);
    CTX::instance()->mesh.changed = (ENT_ALL);
    FlGui::instance()->check();
    drawContext::global()->draw();
  }
}

void GMSH_AnalyseCurvedMeshPlugin::hideValid_ShowInvalid(std::vector<MElement*> &invalids)
{
  int current = 0;
  invalids.push_back(NULL);
  
  switch (_dim) {
    case 3 :
      for(GModel::riter it = _m->firstRegion(); it != _m->lastRegion(); it++) {
        GRegion *r = *it;
        unsigned int numType[5] = {0, 0, 0, 0, 0};
        r->getNumMeshElements(numType);
        
        for(int type = 0; type < 5; type++) {
          MElement *const *el = r->getStartElementType(type);
          for (int i = 0; i < numType[type]; ++i) {
            if (el[i] == invalids[current]) {
              ++current;
              el[i]->setVisibility(1);
            }
            else
              el[i]->setVisibility(0);
          }
        }
      }
      break;
    
    case 2 :
      for (GModel::fiter it = _m->firstFace(); it != _m->lastFace(); it++) {
        GFace *f = *it;
        unsigned int numType[3] = {0, 0, 0};
        f->getNumMeshElements(numType);
        
        for (int type = 0; type < 3; type++) {
          MElement *const *el = f->getStartElementType(type);
          for (int i = 0; i < numType[type]; ++i) {
            if (el[i] == invalids[current]) {
              ++current;
              el[i]->setVisibility(1);
            }
            else
              el[i]->setVisibility(0);
          }
        }
      }
      break;
    
    case 1 :
      for (GModel::eiter it = _m->firstEdge(); it != _m->lastEdge(); it++) {
        GEdge *e = *it;
        unsigned int numElement = e->getNumMeshElements();
        MElement *const *el = e->getStartElementType(0);
        for (int i = 0; i < numElement; ++i) {
          if (el[i] == invalids[current]) {
            ++current;
            el[i]->setVisibility(1);
          }
          else
            el[i]->setVisibility(0);
        }
      }
      break;
    
    default :
      break;
  }
  invalids.pop_back();
}

void GMSH_AnalyseCurvedMeshPlugin::computeMinMax()
{
  _numAnalysedEl = 0;
  _numInvalid = 0;
  _numValid = 0;
  _numUncertain = 0;
  _min_Javg = .0, _max_Javg = .0;
  _min_pJmin = .0, _avg_pJmin = .0;
  _min_ratioJ = .0, _avg_ratioJ = .0;
  
  switch (_dim) {
    case 3 :
      for(GModel::riter it = _m->firstRegion(); it != _m->lastRegion(); it++) {
        GRegion *r = *it;
        unsigned int numType[5] = {0, 0, 0, 0, 0};
        r->getNumMeshElements(numType);
        
        for(int type = 0; type < 5; type++) {
          MElement *const *el = r->getStartElementType(type);
          computeMinMax(el, numType[type]);
          _numAnalysedEl += numType[type];
        }
      }
      break;
    
    case 2 :
      Msg::Warning("2D elements must be in a z=cst plane ! If they aren't, results won't be correct.");
      for (GModel::fiter it = _m->firstFace(); it != _m->lastFace(); it++) {
        GFace *f = *it;
        unsigned int numType[3] = {0, 0, 0};
        f->getNumMeshElements(numType);
        
        for (int type = 0; type < 3; type++) {
          MElement *const *el = f->getStartElementType(type);
          computeMinMax(el, numType[type]);
          _numAnalysedEl += numType[type];
        }
      }
      break;
    
    case 1 :
      Msg::Warning("1D elements must be on a y=cst & z=cst line ! If they aren't, results won't be correct.");
      for (GModel::eiter it = _m->firstEdge(); it != _m->lastEdge(); it++) {
        GEdge *e = *it;
        unsigned int numElement = e->getNumMeshElements();
        MElement *const *el = e->getStartElementType(0);
        computeMinMax(el, numElement);
        _numAnalysedEl += numElement;
      }
      break;
    
    default :
      Msg::Error("I can't analyse any element.");
      return;
  }
  Msg::Info("Extrema of J_avg : %g, %g", _min_Javg, _max_Javg);
  Msg::Info("Minimum of min(distortion) : %g", _min_pJmin);
  Msg::Info("Average of min(distortion) : %g", _avg_pJmin / _numAnalysedEl);
  Msg::Info("Minimum of min(J) / max(J) : %g", _min_ratioJ);
  Msg::Info("Average of min(J) / max(J) : %g", _avg_ratioJ / _numAnalysedEl);
}




void GMSH_AnalyseCurvedMeshPlugin::
  checkValidity(MElement *const*el, int numEl, std::vector<MElement*> &invalids)
{
  if (numEl < 1)
    return;
  
  const JacobianBasis *jfs = el[0]->getJacobianFuncSpace(-1);
  if (!jfs) {
    Msg::Error("Jacobian function space not implemented for type of element %d", el[0]->getNum());
    return;
  }
  const bezierBasis *bb = jfs->bezier;
  
  int numSamplingPt = bb->points.size1();
  int dim = bb->points.size2();
  fullVector<double> jacobian(numSamplingPt);
  fullVector<double> jacBez(numSamplingPt);
  
  for (int k = 0; k < numEl; ++k) {
    setJacobian(el[k], jfs, jacobian);
    
    int i;
    for (i = 0; i < jacobian.size() && jacobian(i) > _jacBreak; ++i);
    if (i < jacobian.size()) {
      invalids.push_back(el[k]);
      ++_numInvalid;
      continue;
    }
    
    if (_maxDepth < 1) {
      invalids.push_back(el[k]);
      ++_numUncertain;
      continue;
    }
    
    bb->matrixLag2Bez.mult(jacobian, jacBez);
    
    for (i = 0; i < jacBez.size() && jacBez(i) > _bezBreak; ++i);
    if (i >= jacBez.size()) {
      ++_numValid;
      continue;
    }
    
    if (_maxDepth < 2) {
      invalids.push_back(el[k]);
      ++_numUncertain;
      continue;
    }
    else {
      int result = subDivision(bb, jacBez, _maxDepth-1);
      if (result < 0) {
        invalids.push_back(el[k]);
        ++_numInvalid;
        continue;
      }
      if (result > 0) {
        ++_numValid;
        continue;
      }
      invalids.push_back(el[k]);
      ++_numUncertain;
      continue;
    }
  }
}

int GMSH_AnalyseCurvedMeshPlugin::
  subDivision(const bezierBasis *bb, const fullVector<double> &jacobian, int depth)
{
  fullVector<double> newJacobian(bb->subDivisor.size1());
  bb->subDivisor.mult(jacobian, newJacobian);
  
  for (int i = 0; i < bb->numDivisions; i++)
  for (int j = 0; j < bb->numLagPts; j++)
  if (newJacobian(i * bb->points.size1() + j) <= _jacBreak)
    return -1;
    
  int i = 0;
  while (i < newJacobian.size() && newJacobian(i) > _bezBreak)
    ++i;
  if (i >= newJacobian.size()) return 1;
  
  if (depth <= 1) {
    return 0;
  }
  else{
    fullVector<double> subJacobian;
    std::vector<int> negTag, posTag;
    bool zeroTag = false;
    
    for (int i = 0; i < bb->numDivisions; i++) {
      subJacobian.setAsProxy(newJacobian, i * jacobian.size(), jacobian.size());
      int tag = subDivision(bb, subJacobian, depth-1);
      
      if (tag < 0)
        negTag.push_back(tag);
      else if (tag > 0)
        posTag.push_back(tag);
      else 
        zeroTag = true;
    }
    
    if (negTag.size() > 0)
      return *std::min_element(negTag.begin(), negTag.end()) - 1;
    
    if (zeroTag) return 0;
    
    return *std::max_element(posTag.begin(), posTag.end()) + 1;
  }
}


void GMSH_AnalyseCurvedMeshPlugin::
  computeMinMax(MElement *const*el, int numEl)
{
  if (numEl < 1)
    return;
  
  const JacobianBasis *jfs = el[0]->getJacobianFuncSpace(-1);
  if (!jfs) {
    Msg::Error("Jacobian function space not implemented for type of element %d", el[0]->getNum());
    return;
  }
  const bezierBasis *bb = jfs->bezier;
  
  int numSamplingPt = bb->points.size1();
  int dim = bb->points.size2();
  
  fullMatrix<double> jacobian(numSamplingPt, numEl);
  fullMatrix<double> jacBez(numSamplingPt, numEl);
  setJacobian(el, jfs, jacobian);
  bb->matrixLag2Bez.mult(jacobian, jacBez);
  
  fullVector<double> prox(numSamplingPt);
  
  for (int k = 0; k < numEl; ++k) {
    prox.setAsProxy(jacBez, k);
    
    double minJ, maxJ = minJ = jacobian(0,k);//, avgJac = 0;
    for (int i = 1; i < jacobian.size1(); ++i) {
      if (jacobian(i,k) < minJ) minJ = jacobian(i,k);
      if (jacobian(i,k) > maxJ) maxJ = jacobian(i,k);
      //avgJac += prox(i);
    }
    //avgJac /= jacobian.size1();
    
    
    
    //int minJ, maxJ = minJ = prox(0);
    //
    //for (int i = 1; i < prox.size(); ++i) {
    //  if (prox(i) > maxJ) maxJ = prox(i);
    //  if (prox(i) < minJ) minJ = prox(i);
    //}
    
    //for (int i = 0; i < jacobian.size(); i++)
    //if (jacobian(i) <= _jacBreak) {
    //  invalids.push_back(el[k]);
    //  ++_numInvalid;
    //  continue;
    //}
    //
    //if (_maxDepth < 1) {
    //  ++_numUncertain;
    //  continue;
    //}
    //
    //bb->matrixLag2Bez.mult(jacobian, jacBez);
    //
    //int i = 0;
    //while (i < jacBez.size() && jacBez(i) > _bezBreak)
    //  ++i;
    //if (i >= jacBez.size()) {
    //  ++_numValid;
    //  continue;
    //}
    //
    //if (_maxDepth < 2) {
    //  ++_numUncertain;
    //  continue;
    //}
    //else {
    //  int result = subDivision(bb, jacBez, _maxDepth-1);
    //  if (result < 0) {
    //    invalids.push_back(el[k]);
    //    ++_numInvalid;
    //    continue;
    //  }
    //  if (result > 0) {
    //    ++_numValid;
    //    continue;
    //  }
    //  ++_numUncertain;
    //  continue;
    //}
  }
}

//int *GMSH_AnalyseCurvedMeshPlugin::checkJacobian
//(MElement *const *el, int numEl, int maxDepth, int method)
//{
//  int *a = new int[2];
//  a[0] = a[1] = 0;
//  if (numEl <= 0) return a;
//
//  switch (method) {
//
//    case 1 :
//      for (int i = 0; i < numEl; i++) {
//        int tag = method_1_2(el[i], maxDepth);
//        if (tag < 0) {
//          a[1]++;
//          if (tag < -1)
//            Msg::Info("Bad element : %d (with tag %d)", el[i]->getNum(), tag);
//          else
//            Msg::Info("Bad element : %d", el[i]->getNum());
//        }
//        else if (tag > 0) {
//          el[i]->setVisibility(0);
//          if (tag > 1)
//            Msg::Info("Good element : %d (with tag %d)", el[i]->getNum(), tag);
//        }
//        else {
//          a[0]++;
//          Msg::Info("Element %d may be bad", el[i]->getNum());
//        }
//      }
//      return a;
//
//    case 2 :
//      std::vector<int> tag(numEl, UNDEF_JAC_TAG);
//      method_2_2(el, tag, maxDepth);
//
//      Msg::Info(" ");
//      Msg::Info("Bad elements :");
//      for (unsigned int i = 0; i < tag.size(); i++) {
//        if (tag[i] < 0) {
//          if (tag[i] < -1)
//            Msg::Info("%d (with tag %d)", el[i]->getNum(), tag[i]);
//          else
//            Msg::Info("%d", el[i]->getNum());
//          a[1]++;
//        }
//      }
//
//      Msg::Info(" ");
//      Msg::Info("Uncertain elements :");
//      for (unsigned int i = 0; i < tag.size(); i++) {
//        if (tag[i] == 0) {
//          Msg::Info("%d", el[i]->getNum());
//          a[0]++;
//        }
//      }
//
//      Msg::Info(" ");
//      return a;
//  }
//}
//
//
//int GMSH_AnalyseCurvedMeshPlugin::method_1_1(MElement *el, int depth)
//{
//  const polynomialBasis *fs = el->getFunctionSpace(-1);
//  if (!fs) {
//    Msg::Error("Function space not implemented for type of element %d", el->getNum());
//    return 0;
//  }
//  const JacobianBasis *jfs = el->getJacobianFuncSpace(-1);
//  if (!jfs) {
//    Msg::Error("Jacobian function space not implemented for type of element %d", el->getNum());
//    return 0;
//  }
//  const bezierBasis *bb = jfs->bezier;
//
//  int numSamplingPt = bb->points.size1();
//  int dim = bb->points.size2();
//  fullVector<double> jacobian(numSamplingPt);
//
//  for (int i = 0; i < numSamplingPt; i++) {
//    double gsf[256][3];
//    switch (dim) {
//      case 1 :
//        fs->df(bb->points(i,0),0,0, gsf);
//        break;
//      case 2 :
//        fs->df(bb->points(i,0),bb->points(i,1),0, gsf);
//        break;
//      case 3 :
//        fs->df(bb->points(i,0),bb->points(i,1),bb->points(i,2), gsf);
//        break;
//      default :
//        Msg::Error("Can't get the gradient for %dD elements.", dim);
//        return false;
//    }
//    double jac[3][3];
//    jacobian(i) = getJacobian(gsf, jac, el);
//  }
//
//  for (int i = 0; i < jacobian.size(); i++) {
//    if (jacobian(i) <= 0.) return -1;
//  }
//
//
//  fullVector<double> jacBez(jacobian.size());
//  bb->matrixLag2Bez.mult(jacobian, jacBez);
//
//  bool allPtPositive = true;
//  for (int i = 0; i < jacBez.size(); i++) {
//    if (jacBez(i) <= 0.) allPtPositive = false;
//  }
//  if (allPtPositive) return 1;
//
//
//  if (depth <= 1) {
//    return 0;
//  }
//  else{
//    int tag = division(bb, jacBez, depth-1);
//    if (tag < 0)
//      return tag - 1;
//    if (tag > 0)
//      return tag + 1;
//    return tag;
//  }
//}
//
//
//int GMSH_AnalyseCurvedMeshPlugin::method_1_2(MElement *el, int depth)
//{
//  const polynomialBasis *fs = el->getFunctionSpace(-1);
//  if (!fs) {
//    Msg::Error("Function space not implemented for type of element %d", el->getNum());
//    return 0;
//  }
//  const JacobianBasis *jfs = el->getJacobianFuncSpace(-1);
//  if (!jfs) {
//    Msg::Error("Jacobian function space not implemented for type of element %d", el->getNum());
//    return 0;
//  }
//  const bezierBasis *bb = jfs->bezier;
//
//  int numSamplingPt = bb->points.size1();
//  int dim = bb->points.size2();
//  fullVector<double> jacobian(numSamplingPt);
//
//  
//  setJacobian(el, jfs, jacobian);
//
//  {
//    Msg::Info("Printing vector jac[%d]", el->getNum());
//    Msg::Info("  ");
//    for(int I = 0; I < jacobian.size(); I++){
//      Msg::Info("%lf ", jacobian(I));
//    }
//    Msg::Info(" ");
//  }
//
//  for (int i = 0; i < jacobian.size(); i++) {
//    if (jacobian(i) <= 0.) return -1;
//  }
//
//
//  fullVector<double> jacBez(jacobian.size());
//  bb->matrixLag2Bez.mult(jacobian, jacBez);
//
//  bool allPtPositive = true;
//  for (int i = 0; i < jacBez.size(); i++) {
//    if (jacBez(i) <= 0.) allPtPositive = false;
//  }
//  if (allPtPositive) return 1;
//
//
//  if (depth <= 1) {
//    return 0;
//  }
//  else{
//    int tag = division(bb, jacBez, depth-1);
//    if (tag < 0)
//      return tag - 1;
//    if (tag > 0)
//      return tag + 1;
//    return tag;
//  }
//}
//
//
//void GMSH_AnalyseCurvedMeshPlugin::method_2_2
//  (MElement *const *el, std::vector<int> &tags, int depth)
//{
//  const polynomialBasis *fs = el[0]->getFunctionSpace(-1);
//  if (!fs) {
//    Msg::Error("Function space not implemented for type of element %d", el[0]->getNum());
//    return;
//  }
//  const JacobianBasis *jfs = el[0]->getJacobianFuncSpace(-1);
//  if (!jfs) {
//    Msg::Error("Jacobian function space not implemented for type of element %d", el[0]->getNum());
//    return;
//  }
//  const bezierBasis *bb = jfs->bezier;
//
//  int numSamplingPt = bb->points.size1();
//  int dim = bb->points.size2();
//  int numEl = tags.size();
//
//  fullMatrix<double> jacobian(numSamplingPt, numEl);
//  setJacobian(el, jfs, jacobian);
//
//  
//  int numBad = 0;
//
//  for (int i = 0; i < numEl; i++) {
//    bool isBad = false;
//    for (int j = 0; j < jacobian.size1(); j++) {
//      if (jacobian(j,i) <= 0.) isBad = true;
//    }
//    if (isBad) {
//      tags[i] = -1;
//      numBad++;
//    }
//  }
//
//
//  fullMatrix<double> jacBez;
//  std::vector<int> correspondingEl;
//
//  double critere = .2; // à définir suivant le temps de chaque opération
//  if ((double) numBad / (double) numEl < critere) {// il vaut mieux calculer les points de controle de chaque élément
//    jacBez.resize(numSamplingPt, numEl);
//    bb->matrixLag2Bez.mult(jacobian, jacBez);
//    correspondingEl.resize(numEl);
//    for (int i = 0; i < numEl; i++) correspondingEl[i] = i;
//  }
//  else {// il vaut mieux ne calculer que les points de controle des éléments encore incertains
//    fullMatrix<double> newJac(numSamplingPt, numEl-numBad);
//    fullMatrix<double> prox1(numSamplingPt,1);
//    fullMatrix<double> prox2(numSamplingPt,1);
//    int index = 0;
//    correspondingEl.resize(numEl - numBad);
//    for (int i = 0; i < numEl; i++) {
//      if (tags[i] == UNDEF_JAC_TAG) {
//        correspondingEl[index] = i;
//        prox1.setAsProxy(newJac,index,1);
//        prox2.setAsProxy(jacobian,i,1);
//        prox1.copy(prox2);
//      }
//    }
//    jacBez.resize(numSamplingPt, numEl-numBad);
//    bb->matrixLag2Bez.mult(jacobian, jacBez);
//  }
//
//
//  int numGood = 0;
//
//  for (int i = 0; i < jacBez.size2(); i++) {
//    bool allPtPositive = true;
//    for (int j = 0; j < jacBez.size1(); j++) {
//      if (jacBez(j,i) <= 0.) allPtPositive = false;
//    }
//    if (allPtPositive) {
//      tags[correspondingEl[i]] = 1;
//      numGood++;
//    }
//  }
//
//
//  Msg::Warning("Not yet implemented for maxDepth > 1");
//  depth = 1;
//  if (depth <= 1) {
//    for (int i = 0; i < jacBez.size2(); i++)
//      if (tags[correspondingEl[i]] == UNDEF_JAC_TAG)
//        tags[correspondingEl[i]] = 0;
//    return;
//  }
//  /*else{
//    int tag = division(jfs, jacBez, depth-1);
//    if (tag < 0)
//      return tag - 1;
//    if (tag > 0)
//      return tag + 1;
//    return tag;
//  }*/
//  
//}
//
//int GMSH_AnalyseCurvedMeshPlugin::division
//  (const bezierBasis *jfs, const fullVector<double> &jacobian, int depth)
//{
//  if (jfs->subDivisor.size2() != jacobian.size()) {
//    Msg::Error("Wrong sizes in division : [%d,%d] * [%d]",
//      jfs->subDivisor.size1(), jfs->subDivisor.size2(), jacobian.size());
//    Msg::Info(" ");
//    return 0;
//  }
//
//  fullVector<double> newJacobian(jfs->subDivisor.size1());
//  jfs->subDivisor.mult(jacobian, newJacobian);
//  
//  for (int i = 0; i < jfs->numDivisions; i++) {
//    for (int j = 0; j < jfs->numLagPts; j++)
//      if (newJacobian(i * jfs->points.size1() + j) <= 0.) return -1;
//  }
//
//  bool allPtPositive = true;
//  for (int i = 0; i < newJacobian.size(); i++) {
//    if (newJacobian(i) <= 0.) allPtPositive = false;
//  }
//  if (allPtPositive) return 1;
//
//
//   We don't know if the jacobian is positif everywhere or not
//   We subdivide if we still can do it (if depth > 0).
//  if (depth <= 0) {
//    return 0;
//  }
//  else{
//    fullVector<double> subJacobian;
//    std::vector<int> negTag, posTag;
//    bool zeroTag = false;
//
//    for (int i = 0; i < jfs->numDivisions; i++)
//    {
//      subJacobian.setAsProxy(newJacobian, i * jacobian.size(), jacobian.size());
//      int tag = division(jfs, subJacobian, depth-1);
//      
//      if (tag < 0)
//        negTag.push_back(tag);
//      else if (tag > 0)
//        posTag.push_back(tag);
//      else 
//        zeroTag = true;
//    }
//
//    if (negTag.size() > 0) return max(negTag) - 1;
//    
//    if (zeroTag) return 0;
//
//    return max(posTag) - 1;
//  }
//}
//
//
//
//  
  /*{
    Msg::Info("Printing matrix %s :", "nodesX");
    int ni = nodesX.size1();
    int nj = nodesX.size2();
    for(int I = 0; I < ni; I++){
      Msg::Info("  ");
      for(int J = 0; J < nj; J++){
        Msg::Info("%lf ", nodesX(I, J));
      }
    }
    Msg::Info(" ");
  }*/
