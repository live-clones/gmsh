#ifndef _SWAP_PATTERNS_H_
#define _SWAP_PATTERNS_H_

int swap_patterns_3 [1][1][3] = {
  {
    {0,1,2}
  }
};

int swap_patterns_4 [1][2][3] = {
  {
    {0,1,3},
    {1,2,3}
  }
};

int swap_patterns_5 [1][3][3] = {
  {
    {0,1,2},
    {0,2,4},
    {2,3,4}
  }
};

int swap_patterns_6 [4][4][3] = {
  {
    {0,1,2},
    {0,2,5},
    {5,2,4},
    {4,2,3}
  },
  {
    {0,1,2},
    {0,2,3},
    {5,2,3},
    {5,3,4}
  },
  {
    {0,1,5},
    {5,1,2},
    {5,2,4},
    {4,2,3}
  },
  {
    {0,1,2},
    {4,0,2},
    {4,2,3},
    {0,4,5}
  }
};

int swap_patterns_7 [6][5][3] = {
  {
    {0,1,3},
    {1,2,3},
    {0,3,6},
    {6,3,5},
    {5,3,4}
  },
  {
    {0,1,3},
    {1,2,3},
    {0,3,4},
    {0,4,6},
    {6,4,5}
  },
  {
    {0,1,3},
    {1,2,3},
    {0,3,6},
    {6,3,4},
    {6,4,5}
  },
  {
    {0,1,2},
    {0,2,3},
    {0,3,6},
    {6,3,5},
    {5,3,4}
  },
  {
    {0,1,6},
    {1,2,3},
    {6,1,3},
    {6,3,5},
    {5,3,4}
  },
  {
    {0,1,3},
    {1,2,3},
    {0,3,5},
    {5,3,4},
    {0,5,6}
  }
};


class SwapPattern{
protected :
  int NbPatterns;
  int NbNod;
  int Rot;
  virtual void GetTriangleWithoutRot(int iPattern, int iTriangle,int tri[3])=0;
public :
  SwapPattern(){Rot = 0;}
  int GetNbPatterns() {return NbPatterns;}
  virtual int GetNbRotations(int iPattern) = 0;
  int GetNbTriangles(){return NbNod-2;}
  void GetTriangle(int iPattern, int iTriangle,int tri[3]){
    GetTriangleWithoutRot(iPattern,iTriangle,tri);
    for(int i=0;i<3;i++){
      tri[i] = (tri[i]+Rot)%NbNod;
    }
  }
  void Rotate (){Rot++;};
};

class SwapPattern3 : public SwapPattern{
  void GetTriangleWithoutRot(int iPattern, int iTriangle,int tri[3]){
    tri[0] = swap_patterns_3[iPattern][iTriangle][0];
    tri[1] = swap_patterns_3[iPattern][iTriangle][1];
    tri[2] = swap_patterns_3[iPattern][iTriangle][2];
  }
public :
  SwapPattern3(){NbPatterns = 1;NbNod = 3;}
  int GetNbRotations (int iPattern){
    return 1;
  };
};

class SwapPattern4 : public SwapPattern{
  void GetTriangleWithoutRot(int iPattern, int iTriangle,int tri[3]){
    tri[0] = swap_patterns_4[iPattern][iTriangle][0];
    tri[1] = swap_patterns_4[iPattern][iTriangle][1];
    tri[2] = swap_patterns_4[iPattern][iTriangle][2];
  }
public :
  SwapPattern4(){NbPatterns = 1;NbNod = 4;}
  int GetNbRotations (int iPattern){
    return 2;
  };
};

class SwapPattern5 : public SwapPattern{
  void GetTriangleWithoutRot(int iPattern, int iTriangle,int tri[3]){
    tri[0] = swap_patterns_5[iPattern][iTriangle][0];
    tri[1] = swap_patterns_5[iPattern][iTriangle][1];
    tri[2] = swap_patterns_5[iPattern][iTriangle][2];
  }
public :
  SwapPattern5(){NbPatterns = 1;NbNod = 5;}
  int GetNbRotations (int iPattern){
    return 5;
  };
};

class SwapPattern6 : public SwapPattern{
  void GetTriangleWithoutRot(int iPattern, int iTriangle,int tri[3]){
    tri[0] = swap_patterns_6[iPattern][iTriangle][0];
    tri[1] = swap_patterns_6[iPattern][iTriangle][1];
    tri[2] = swap_patterns_6[iPattern][iTriangle][2];
  }
public :
  SwapPattern6(){NbPatterns = 4;NbNod = 6;}
  int GetNbRotations (int iPattern){
    switch(iPattern){
    case 0:return 6;
    case 1:return 3;
    case 2:return 3;
    case 3:return 2;
    default: return 0;
    }
  }
};

class SwapPattern7 : public SwapPattern{
  void GetTriangleWithoutRot(int iPattern, int iTriangle,int tri[3]){
    tri[0] = swap_patterns_7[iPattern][iTriangle][0];
    tri[1] = swap_patterns_7[iPattern][iTriangle][1];
    tri[2] = swap_patterns_7[iPattern][iTriangle][2];
  }
public :
  SwapPattern7(){NbPatterns = 6;NbNod = 7;}
  int GetNbRotations (int iPattern){
    return 7;
  }
};

class SwapPatternN : public SwapPattern{
  void GetTriangleWithoutRot(int iPattern, int iTriangle,int tri[3]){
    tri[0] = 0;
    tri[1] = iTriangle+1;
    tri[2] = iTriangle+2;
  }
public :
  SwapPatternN(int N){NbPatterns = 1;NbNod = N;}
  int GetNbRotations (int iPattern){
    return 8;
  }
};


#endif
