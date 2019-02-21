
#include "HierarchicalBasisH1Line.h"
#include "HierarchicalBasisH1Tria.h"
using namespace std;


int main() // test

{
  try{
  /*

  cout << "test Evallobatto" << endl;
  double a=OrthogonalPoly::EvalLobatto(15, 0);
  cout<<a<<endl;

  for(int i=0;i<=16;i++){
    cout<<"i"<<endl;
    cout<<i<<endl;
    
    cout<<OrthogonalPoly::EvalLobatto(i,-1)<<'|';
    cout<<OrthogonalPoly::EvalLobatto(i,0)<<'|';
    cout<<OrthogonalPoly::EvalLobatto(i,1)<<'|'<<endl;
    
    
  }
 
 */
   //test line basis :
    /*   HierarchicalBasisH1Line basetest1(3);
   int taillevertex1 = basetest1.getnVertexFunction();
   double tablever1[taillevertex1];
   int taillebubble1=basetest1.getnBubbleFunction();
   double tablebubble1[taillebubble1];
   basetest1.generateBasis(0,tablever1,tablebubble1,taillevertex1,taillebubble1);
   basetest1.generateGradientBasis(0,tablever1,tablebubble1,taillevertex1,taillebubble1);
   
  
*/
    /*   HierarchicalBasisH1Quad basetest2(6,5,4,3,4,5);
   int taillevertex2 = basetest2.getnVertexFunction();
   double tablever2[taillevertex2];
      int taillebubble2=basetest2.getnBubbleFunction();
   double tablebubble2[taillebubble2];
      int tailleedge2=basetest2.getnEdgeFunction();
   double tableedge2[tailleedge2];
   basetest2.generateBasis(-1,-1,tablever2,tableedge2,tablebubble2,taillevertex2,tailleedge2,taillebubble2);
    */
 
    /* 
  //test HierarchicalBasisH1Tria
    HierarchicalBasisH1Tria  basetest3(4,2,3,2);
    
   int taillevertex3 = basetest3.getnVertexFunction();
   double tablever3[taillevertex3];
      int taillebubble3=basetest3.getnBubbleFunction();
   double tablebubble3[taillebubble3];
      int tailleedge3=basetest3.getnEdgeFunction();
   double tableedge3[tailleedge3];


   basetest3.generateBasis(0,0,tablever3,tableedge3,tablebubble3,taillevertex3,tailleedge3,taillebubble3);
  
  }
  catch(string e){
    cout<<e<<endl;
    }*/
   return 0;
} 
