#ifndef _GET_OPTIONS_H_
#define _GET_OPTIONS_H_

extern char gmsh_progname[], gmsh_copyright[], gmsh_version[], gmsh_os[];
extern char gmsh_date[], gmsh_host[], gmsh_packager[], gmsh_url[];
extern char gmsh_email[], gmsh_gui[];

extern char *TheFileNameTab[MAX_OPEN_FILES], *TheBgmFileName, *TheOptString;

void Get_Options(int argc, char *argv[], int *nbfiles);
void Print_Usage(char *name);

#endif
