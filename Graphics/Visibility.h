#ifndef _VISIBILITY_H_
#define _VISIBILITY_H_

typedef struct{
  int n;
  char *s;
} NxS;

class Entity {
public :
  int type;
  union {
    Vertex *vertex;
    Curve *curve;
    Surface *surface;
    Volume *volume;
    PhysicalGroup *physical;
  } data;
  char *str;

  int   Num();
  char *Type();
  char *Name();
  int   Visible();
  void  Visible(int mode);
  void  RecurVisible();
  char *BrowserLine();
};

void    SetVisibilitySort(int sort);
List_T* GetVisibilityList(int type);
void    ClearVisibilityList(int type);
void    InitVisibilityThroughPhysical();

#endif
