#include "BlendOperator.h"

using namespace FM;

bool BlendOperator::GetPointOnPatch_
(int i, double u, double v, int j, double &x, double &y, double &z)
{
  double h = 1.e-8;
  double tol = 1.e-12;

  u = GetPatch(i)->RescaleU(u);
  v = GetPatch(i)->RescaleV(v);

  double P[3], d[3];
  GetPatch(i)->GetProjectionSurface()->F(u,v,P[0],P[1],P[2]);
  GetPatch(i)->GetProjectionSurface()->GetUnitNormal(u,v,d[0],d[1],d[2]);

  u = GetPatch(i)->UnscaleU(u);
  v = GetPatch(i)->UnscaleV(v);

  double e1[3],e2[3];

  if (std::abs(1.-std::abs(d[0])) < tol) {
    e1[0] = 0.;
    e1[1] = 1.;
    e1[2] = 0.;
  }
  else if (std::abs(1.-std::abs(d[1])) < tol) {
    e1[0] = 0.;
    e1[1] = 0.;
    e1[2] = 1.;
  }
  else if (std::abs(1.-std::abs(d[2])) < tol) {
    e1[0] = 1.;
    e1[1] = 0.;
    e1[2] = 0.;
  }
  else {
    e1[0] = - d[1] * d[2];
    e1[1] = 2 * d[2] * d[0];
    e1[2] = - d[0] * d[1];
  }
  double value = 0.;
  for (int l=0;l<3;l++)
    value += e1[l] * e1[l];
  value = sqrt(value);
  for (int l=0;l<3;l++)
    e1[l] /= value;

  e2[0] = d[1] * e1[2] - d[2] * e1[1];
  e2[1] = d[2] * e1[0] - d[0] * e1[2];
  e2[2] = d[0] * e1[1] - d[1] * e1[0];

  bool converged = false;

  double R[3];
  GetPatch(i)->F(u,v,R[0],R[1],R[2]);

  double Qu,Qv;
  GetPatch(j)->GetProjectionSurface()->
    OrthoProjectionOnSurface(R[0],R[1],R[2],Qu,Qv);

  Qu = GetPatch(j)->UnscaleU(Qu);
  Qv = GetPatch(j)->UnscaleV(Qv);

  double Q[3];
  GetPatch(j)->F(Qu,Qv,Q[0],Q[1],Q[2]);

  int maxTotalIteration = 10;
  int totalIterationCounter = 0;

  while ((!converged) && (totalIterationCounter < maxTotalIteration)) {
    totalIterationCounter++;
    double QminusP[3];
    for (int l=0;l<3;l++)
      QminusP[l] = Q[l] - P[l];

    double f[2];
    f[0] = (QminusP[0] * e1[0] + QminusP[1] * e1[1] + QminusP[2] * e1[2]);
    f[1] = (QminusP[0] * e2[0] + QminusP[1] * e2[1] + QminusP[2] * e2[2]);

    //printf("(%g,%g) :: f = (%g,%g)\n",u,v,f[0],f[1]);

    if ((std::abs(f[0]) < tol) && (std::abs(f[1]) < tol)) {
      //bool IsGood = true;
      
      bool IsGood = GetPatch(i)->GetProjectionSurface()->
      OrthoProjectionOnSurface(Q[0],Q[1],Q[2],u,v);
      if (IsGood) {
	double RR[3];
	//printf("(u,v) = (%g,%g); (Qu,Qv) = (%g,%g)\n",u,v,Qu,Qv);
	u = GetPatch(i)->UnscaleU(u);
	v = GetPatch(i)->UnscaleV(v);
	GetPatch(i)->F(u,v,RR[0],RR[1],RR[2]);
	double dist = 0.;
	for (int l=0;l<3;l++)
	  dist += (RR[l] - R[l]) * (RR[l] - R[l]);
	dist = sqrt(dist);
	if (dist > 1.e-2)
	  break;
	else {
	  //printf("R = (%g,%g,%g); RR = (%g,%g,%g)\n\n",
	  // R[0],R[1],R[2],RR[0],RR[1],RR[2]);
	  converged = true;
	  x = Q[0]; y = Q[1]; z = Q[2];
	}
	converged = true;
	x = Q[0]; y = Q[1]; z = Q[2];
      }
      else
	break;
    }
    else {
      double QuPlus = Qu + h;
      double QvPlus = Qv + h;
      if (GetPatch(j)->IsUPeriodic())
	QuPlus -= std::floor(QuPlus);
      if (GetPatch(j)->IsVPeriodic())
	QvPlus -= std::floor(QvPlus);

      double QplusU[3], QplusV[3];
      GetPatch(j)->F(QuPlus,Qv,QplusU[0],QplusU[1],QplusU[2]);
      GetPatch(j)->F(Qu,QvPlus,QplusV[0],QplusV[1],QplusV[2]);

      double QplusUminusP[3], QplusVminusP[3];
      for (int l=0;l<3;l++) {
	QplusUminusP[l] = QplusU[l] - P[l];
	QplusVminusP[l] = QplusV[l] - P[l];
      }

      double fuPlus[2], fvPlus[2];
      fuPlus[0] = (QplusUminusP[0] * e1[0] + QplusUminusP[1] * e1[1] + 
		   QplusUminusP[2] * e1[2]);
      fuPlus[1] = (QplusUminusP[0] * e2[0] + QplusUminusP[1] * e2[1] + 
		   QplusUminusP[2] * e2[2]);
      fvPlus[0] = (QplusVminusP[0] * e1[0] + QplusVminusP[1] * e1[1] + 
		   QplusVminusP[2] * e1[2]);
      fvPlus[1] = (QplusVminusP[0] * e2[0] + QplusVminusP[1] * e2[1] + 
		   QplusVminusP[2] * e2[2]);

      double D[2][2];
      D[0][0] = (fuPlus[0] - f[0]) / h;
      D[0][1] = (fvPlus[0] - f[0]) / h;
      D[1][0] = (fuPlus[1] - f[1]) / h;
      D[1][1] = (fvPlus[1] - f[1]) / h;

      double det = D[0][0] * D[1][1] - D[0][1] * D[1][0];
      double update[2];
      update[0] = (D[1][1] * f[0] - D[0][1] * f[1]) / det;
      update[1] = (D[0][0] * f[1] - D[1][0] * f[0]) / det;

      //printf("update = (%g,%g)\n",update[0],update[1]);

      Qu -= update[0];
      Qv -= update[1];

      //printf("Q1 = (%g,%g)\n",Qu,Qv);

      if (GetPatch(j)->IsUPeriodic())
	Qu -= std::floor(Qu);
      if (GetPatch(j)->IsVPeriodic())
	Qv -= std::floor(Qv);

      //printf("Q2 = (%g,%g)\n",Qu,Qv);

      GetPatch(j)->F(Qu,Qv,Q[0],Q[1],Q[2]);
    }
  }
    
  return converged;
}

bool BlendOperator::E
(int i, int j, double u, double v, double &x, double &y, double &z)
{
  bool found = false;

  if (DoPatchesOverlap(i,j)) {
    GetPatch(i)->F(u,v,x,y,z);
    //if (1) {
    if (IsPointInIntersectionBoundingBox(i,j,x,y,z)) {
      if (GetPatch(i)->GetProjectionSurface()->GetTag() == 
	  GetPatch(j)->GetProjectionSurface()->GetTag()) {
	found = GetPatch(j)->Inverse(x,y,z,u,v);
      }
      else {
	int tag = GetProjectionSurfaceTagForOverlap(i,j);
	if (GetPatch(i)->GetProjectionSurface()->GetTag() == tag) {
	  found = GetPointOnPatch_(i,u,v,j,x,y,z);
	  if (!GetPatch(j)->Inverse(x,y,z,u,v))
	    found = false;
	}
	else if (GetPatch(j)->GetProjectionSurface()->GetTag() == tag) {
	  found = GetPatch(j)->GetProjectionSurface()->
	    OrthoProjectionOnSurface(x,y,z,u,v);
	  if (found) {
	    u = GetPatch(j)->UnscaleU(u);
	    v = GetPatch(j)->UnscaleV(v);
	    double tol = 1.e-12;
	    if ((u > - tol)&&(u < 1. + tol)&&(v > - tol)&&(v < 1. + tol)) {
	      found = true;
	      GetPatch(j)->F(u,v,x,y,z);
	    }
	    else
	      found = false;
	  }
	}
	else {
	  found = E(i,tag,u,v,x,y,z);
	  if (found) {
	    found = GetPatch(tag)->Inverse(x,y,z,u,v);
	    if (found)
	      found = E(tag,j,u,v,x,y,z);
	  }
	}
      }
    }
  }
  return found;
}

double BlendOperator::GetBlendingPou
(int patchTag, double u, double v)
{
  double x,y,z;
  double pouNumerator = GetPatch(patchTag)->GetPou(u,v);

  double pouDenominator = 0.;
  for (int otherPatchTag = 0;otherPatchTag < patch_.size();otherPatchTag++) {
    if (E(patchTag,otherPatchTag,u,v,x,y,z)) {
      double uu,vv;
      GetPatch(otherPatchTag)->Inverse(x,y,z,uu,vv);
      if (GetPatch(otherPatchTag)->Inverse(x,y,z,uu,vv)) {
	pouDenominator += GetPatch(otherPatchTag)->GetPou(uu,vv);
      }
    }
  }
  if (pouDenominator)
    return pouNumerator / pouDenominator;
  else {
    printf("%d(%g,%g) :: %g %g\n",patchTag,u,v,pouNumerator,pouDenominator);
    return 1.;
  }
}

Patch* BlendOperator::GetPatch
(int tag) {
  for (int i=0;i<patch_.size();i++) {
    if (patch_[i]->GetTag() == tag)
      return patch_[i];
  }
}

ProjectionSurface* BlendOperator::GetProjectionSurface
(int tag) {
  for (int i=0;i<ps_.size();i++) {
    if (ps_[i]->GetTag() == tag)
      return ps_[i];
  }
}

bool BlendOperator::DoPatchesOverlap
(int patchTag1, int patchTag2) {
  bool result;
  if (overlapChart_[patchTag1][patchTag2]->doesIntersect)
    result = true;
  else 
    result = false;
  
  return result;
}

int BlendOperator::GetProjectionSurfaceTagForOverlap
(int patchTag1, int patchTag2) {
  return overlapChart_[patchTag1][patchTag2]->psTag;
}

bool BlendOperator::IsPointInIntersectionBoundingBox
(int patchTag1, int patchTag2, double x, double y, double z) {
  bool result = true;
  double tol = 1.e-2;
  double xMin = overlapChart_[patchTag1][patchTag2]->xMin - tol;
  double xMax = overlapChart_[patchTag1][patchTag2]->xMax + tol;
  double yMin = overlapChart_[patchTag1][patchTag2]->yMin - tol;
  double yMax = overlapChart_[patchTag1][patchTag2]->yMax + tol;
  double zMin = overlapChart_[patchTag1][patchTag2]->zMin - tol;
  double zMax = overlapChart_[patchTag1][patchTag2]->zMax + tol;

  //printf("%d %d :: %g %g %g :: %g %g %g :: %g %g %g\n",
  // patchTag1,patchTag2, xMin,x,xMax,yMin,y,yMax,zMin,z,zMax);

  if ((x < xMin)||(x > xMax)||(y < yMin)||(y > yMax)||(z < zMin)||(z > zMax))
    result = false;

  return result;
}

int BlendOperator::GetNumPatches
() { 
  return patch_.size();
}

bool BlendOperator::GetPointOnPatch
(int patchTag, double d[3], double &x, double &y, double &z)
{
  double h = 1.e-6;
  double tol = 1.e-12;

  double P[3], R[3];
  P[0] = R[0] = x; 
  P[1] = R[1] = y; 
  P[2] = R[2] = z;

  double e1[3],e2[3];

  if (std::abs(1.-std::abs(d[0])) < tol) {
    e1[0] = 0.;
    e1[1] = 1.;
    e1[2] = 0.;
  }
  else if (std::abs(1.-std::abs(d[1])) < tol) {
    e1[0] = 0.;
    e1[1] = 0.;
    e1[2] = 1.;
  }
  else if (std::abs(1.-std::abs(d[2])) < tol) {
    e1[0] = 1.;
    e1[1] = 0.;
    e1[2] = 0.;
  }
  else {
    e1[0] = - d[1] * d[2];
    e1[1] = 2 * d[2] * d[0];
    e1[2] = - d[0] * d[1];
  }
  double value = 0.;
  for (int l=0;l<3;l++)
    value += e1[l] * e1[l];
  value = sqrt(value);
  for (int l=0;l<3;l++)
    e1[l] /= value;

  e2[0] = d[1] * e1[2] - d[2] * e1[1];
  e2[1] = d[2] * e1[0] - d[0] * e1[2];
  e2[2] = d[0] * e1[1] - d[1] * e1[0];

  bool converged = false;

  double Qu,Qv;
  GetPatch(patchTag)->GetProjectionSurface()->
    OrthoProjectionOnSurface(P[0],P[1],P[2],Qu,Qv);


  //printf("Q1 = (%g,%g)\n",Qu,Qv);

  Qu = GetPatch(patchTag)->UnscaleU(Qu);
  Qv = GetPatch(patchTag)->UnscaleV(Qv);

  if (Qu < 0.)
    Qu = 0.;
  if (Qu > 1.)
    Qu = 1.;

  if (Qv < 0.)
    Qv = 0.;
  if (Qv > 1.)
    Qv = 1.;

  double Q[3];
  GetPatch(patchTag)->F(Qu,Qv,Q[0],Q[1],Q[2]);
      
  int maxTotalIteration = 10;
  int totalIterationCounter = 0;

  while ((!converged) && (totalIterationCounter < maxTotalIteration)) {
    totalIterationCounter++;
    double QminusP[3];
    for (int l=0;l<3;l++)
      QminusP[l] = Q[l] - P[l];

    double f[2];
    f[0] = (QminusP[0] * e1[0] + QminusP[1] * e1[1] + QminusP[2] * e1[2]);
    f[1] = (QminusP[0] * e2[0] + QminusP[1] * e2[1] + QminusP[2] * e2[2]);

    //printf("Q2 = (%g,%g) -> %g -> %g\n",Qu,Qv,f[0],f[1]);

    if ((std::abs(f[0]) < tol) && (std::abs(f[1]) < tol)) {
      //printf("here too\n");
      converged = true;
      for (int l=0;l<3;l++)
	R[l] = Q[l];
    }
    else {
      double QuPlus = Qu + h;
      double QvPlus = Qv + h;
      if (GetPatch(patchTag)->IsUPeriodic())
	QuPlus -= std::floor(QuPlus);
      if (GetPatch(patchTag)->IsVPeriodic())
	QvPlus -= std::floor(QvPlus);
      
      double QplusU[3], QplusV[3];
      GetPatch(patchTag)->F(QuPlus,Qv,QplusU[0],QplusU[1],QplusU[2]);
      GetPatch(patchTag)->F(Qu,QvPlus,QplusV[0],QplusV[1],QplusV[2]);
      
      double QplusUminusP[3], QplusVminusP[3];
      for (int l=0;l<3;l++) {
	QplusUminusP[l] = QplusU[l] - P[l];
	QplusVminusP[l] = QplusV[l] - P[l];
      }
      
      double fuPlus[2], fvPlus[2];
      fuPlus[0] = (QplusUminusP[0] * e1[0] + QplusUminusP[1] * e1[1] + 
		   QplusUminusP[2] * e1[2]);
      fuPlus[1] = (QplusUminusP[0] * e2[0] + QplusUminusP[1] * e2[1] + 
		   QplusUminusP[2] * e2[2]);
      fvPlus[0] = (QplusVminusP[0] * e1[0] + QplusVminusP[1] * e1[1] + 
		   QplusVminusP[2] * e1[2]);
      fvPlus[1] = (QplusVminusP[0] * e2[0] + QplusVminusP[1] * e2[1] + 
		   QplusVminusP[2] * e2[2]);
      
      double D[2][2];
      D[0][0] = (fuPlus[0] - f[0]) / h;
      D[0][1] = (fvPlus[0] - f[0]) / h;
      D[1][0] = (fuPlus[1] - f[1]) / h;
      D[1][1] = (fvPlus[1] - f[1]) / h;
      
      double det = D[0][0] * D[1][1] - D[0][1] * D[1][0];
      double update[2];
      update[0] = (D[1][1] * f[0] - D[0][1] * f[1]) / det;
      update[1] = (D[0][0] * f[1] - D[1][0] * f[0]) / det;
      
      //printf("update = (%g,%g)\n",update[0],update[1]);
      
      Qu -= update[0];
      Qv -= update[1];
      
      //printf("Q1 = (%g,%g)\n",Qu,Qv);
      
      //if (GetPatch(patchTag)->_PI->periodic[0] == 1)
      //Qu -= std::floor(Qu);
      //if (GetPatch(patchTag)->_PI->periodic[1] == 1)
      //Qv -= std::floor(Qv);
      
      //printf("Q2 = (%g,%g)\n",Qu,Qv);
      
      GetPatch(patchTag)->F(Qu,Qv,Q[0],Q[1],Q[2]);
    }
  }
  x = R[0];
  y = R[1];
  z = R[2];
  return converged;
}
