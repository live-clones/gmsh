#ifndef _OPENFILE_H_
#define _OPENFILE_H_

#define MAX_OPEN_FILES  256

int  ParseFile(char *filename, int silent);
void ParseString(char *str);
void OpenProblem(char *filename);
void MergeProblem(char *filename);

#endif
