/* $Id: Message.h,v 1.2 2000-11-23 14:11:28 geuzaine Exp $ */
#ifndef _MESSAGE_H_
#define _MESSAGE_H_

#include <stdarg.h>

#define ERROR           0
#define WARNING         1
#define INFO            2
#define INFOS           3
#define SELECT          4
#define STATUS          5
#define PARSER_ERROR    6
#define PARSER_INFO     7

void   Info (int level, char *arg0);
void   Signal (int signum);
void   Msg (int level, char *fmt, ...);
double Cpu (void);
void   Progress(int);

#endif
