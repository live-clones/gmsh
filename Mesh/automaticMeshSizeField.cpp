#include "automaticMeshSizeField.h"



double automaticMeshSizeField:: operator()(double X, double Y, double Z, GEntity *ge) {  
  return _hbulk;
}

void automaticMeshSizeField:: update(){
}
