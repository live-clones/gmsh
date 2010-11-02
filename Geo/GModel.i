%module gmshPython
%include std_string.i
%{
  #include "GModel.h"
  void GmshInitialize(int argc=0, char **argv=NULL);
%}

void GmshInitialize(int argc=0, char **argv=NULL);
%include "GModel.h"
