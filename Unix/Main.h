/* $Id: Main.h,v 1.2 2000-11-23 14:11:41 geuzaine Exp $ */
#ifndef _MAIN_H_
#define _MAIN_H_

#include "Const.h"

void OpenProblem(char *name);
void MergeProblem(char *name);

extern char TheFileName[NAME_STR_L], TheBaseFileName[NAME_STR_L];

#endif
