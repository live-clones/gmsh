
#include "Gmsh.h"
#include "Const.h"
#include "Mesh.h"
#include "2D_Mesh.h"
#include "Create.h"
#include "Numeric.h"

extern Mesh     *THEM; 

Tree_T    *RecEdges,*Triangles;
Tree_T    *RecSimplex,*TREEELM;
double     ALPHA;
int        RECNUM;

void addTriangles(void *data, void *dum){
  Simplex *S;
  S = *(Simplex**)data;
  if(S->V[2] && !S->V[3])Tree_Add(Triangles,&S);
}

void addrecedges (void *a, void *b){
  Edge *ed;
  ed = (Edge*)a;
  if(ed->a < ALPHA)Tree_Add(RecEdges,ed);
}

void CalculeAngles (void *a, void *b){
  Edge *ed;
  double Angle;

  ed = (Edge*)a;
  if(List_Nbr(ed->Simplexes) != 2){
    ed->a = 90.;
    return;
  }
  
  Angle = fabs(90. - angle_3pts(ed->O[0],ed->V[0],ed->O[1]));
  Angle = DMAX(fabs(90. - angle_3pts(ed->V[0],ed->O[1],ed->V[1])),Angle);
  Angle = DMAX(fabs(90. - angle_3pts(ed->O[1],ed->V[1],ed->O[0])),Angle);
  Angle = DMAX(fabs(90. - angle_3pts(ed->V[0],ed->O[0],ed->V[1])),Angle);
  ed->a = Angle;
}


void Recombine_Farce (void *a, void *b){
  Edge *ed;
  Simplex *s1,*s2;
  ed = (Edge*)a;

  if (ed->a < ALPHA){
    List_Read(ed->Simplexes,0,&s1);
    List_Read(ed->Simplexes,1,&s2);
    if(Tree_Search(RecSimplex,&s1)) return;
    if(s1->V[3]) return;
    if(Tree_Search(RecSimplex,&s2)) return;
    if(s2->V[3]) return;
    Tree_Add(RecSimplex,&s1);
    Tree_Suppress(TREEELM,&s1);
    s2->V[0] = ed->V[0];
    s2->V[1] = ed->O[0];
    s2->V[2] = ed->V[1];
    s2->V[3] = ed->O[1];
    RECNUM++;
  }
}

void Recombine (Tree_T *TreeAllVert, Tree_T *TreeAllElg, double a){
  Tree_T *TreeEdges,*tnxe;
  int ntot;

  ALPHA = a;
  TREEELM = TreeAllElg;
  ntot = 0;

  while(1){

    /* Initialisation */
    RECNUM = 0;
    TreeEdges   = Tree_Create(sizeof(Edge),compareedge);
    RecEdges    = Tree_Create(sizeof(Edge),compareedge_angle);
    RecSimplex  = Tree_Create(sizeof(Simplex*),compareSimplex);
    Triangles   = Tree_Create(sizeof(Simplex*),compareSimplex);

    /* Recombinaison */
    Tree_Action(TreeAllElg,addTriangles);
    crEdges(Triangles,TreeEdges);
    Tree_Action(TreeEdges,CalculeAngles);
    Tree_Action(TreeEdges,addrecedges);
    Tree_Action(RecEdges,Recombine_Farce);

    /* Lissage */
    tnxe = Tree_Create(sizeof(NXE),compareNXE);
    create_NXE(TreeAllVert,TreeAllElg,tnxe);
    Tree_Action(tnxe,ActionLissSurf);
    Tree_Action(tnxe,ActionLissSurf);
    Tree_Action(tnxe,ActionLissSurf);
    Tree_Delete(tnxe);

    /* Destruction */
    Tree_Delete(TreeEdges);
    Tree_Delete(RecEdges);
    Tree_Delete(RecSimplex);
    Tree_Delete(Triangles);

    /* Si aucune recombinaison -> fin */
    ntot += RECNUM;
    if(!RECNUM)break;
  }

  Msg(INFO, "Recombining: %d quadrangles",ntot); 

  THEM->Statistics[7] -= ntot/2; 
  THEM->Statistics[8] += ntot; 
  
}



