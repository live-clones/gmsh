//File for handling warnings, errors, messages
#include <meshing.hpp>

namespace netgen
{

int printmessage_importance = 5;
int printwarnings = 1;
int printerrors = 1;
int printdots = 1;
int printfnstart = 0;

// extern void Ng_PrintDest(const MyStr& s);
extern void Ng_PrintDest(const char * s);

//the dots for progression of program
void PrintDot(char ch)
{
  if (printdots)
    {
      char st[2];
      st[0] = ch;
      st[1] = 0;
      Ng_PrintDest(st);
    }
}

void PrintMessage(int importance, 
		  const MyStr& s1, const MyStr& s2, const MyStr& s3, const MyStr& s4, 
		  const MyStr& s5, const MyStr& s6, const MyStr& s7, const MyStr& s8)
{
  if (importance <= printmessage_importance)
    {
      Ng_PrintDest(MyStr(" ")+s1+s2+s3+s4+s5+s6+s7+s8+MyStr("\n"));
    }
}

void PrintMessageCR(int importance, 
		    const MyStr& s1, const MyStr& s2, const MyStr& s3, const MyStr& s4, 
		    const MyStr& s5, const MyStr& s6, const MyStr& s7, const MyStr& s8)
{
  if (importance <= printmessage_importance)
    {
      Ng_PrintDest(MyStr(" ")+s1+s2+s3+s4+s5+s6+s7+s8+MyStr("\r"));
    }
}

void PrintFnStart(const MyStr& s1, const MyStr& s2, const MyStr& s3, const MyStr& s4, 
		  const MyStr& s5, const MyStr& s6, const MyStr& s7, const MyStr& s8)
{
  if (printfnstart)
    Ng_PrintDest(MyStr(" Start Function: ")+s1+s2+s3+s4+s5+s6+s7+s8+MyStr("\n"));
}

void PrintWarning(const MyStr& s1, const MyStr& s2, const MyStr& s3, const MyStr& s4, 
		  const MyStr& s5, const MyStr& s6, const MyStr& s7, const MyStr& s8)
{
  if (printwarnings)
    Ng_PrintDest(MyStr(" WARNING: ")+s1+s2+s3+s4+s5+s6+s7+s8+MyStr("\n"));
}

void PrintError(const MyStr& s1, const MyStr& s2, const MyStr& s3, const MyStr& s4, 
		const MyStr& s5, const MyStr& s6, const MyStr& s7, const MyStr& s8)
{
  if (printerrors)
    Ng_PrintDest(MyStr(" ERROR: ")+s1+s2+s3+s4+s5+s6+s7+s8+MyStr("\n"));
}

void PrintFileError(const MyStr& s1, const MyStr& s2, const MyStr& s3, const MyStr& s4, 
		    const MyStr& s5, const MyStr& s6, const MyStr& s7, const MyStr& s8)
{
  if (printerrors)
    Ng_PrintDest(MyStr(" FILE ERROR: ")+s1+s2+s3+s4+s5+s6+s7+s8+MyStr("\n"));
}

void PrintUserError(const MyStr& s1, const MyStr& s2, const MyStr& s3, const MyStr& s4, 
		const MyStr& s5, const MyStr& s6, const MyStr& s7, const MyStr& s8)
{
  Ng_PrintDest(MyStr(" USER ERROR: ")+s1+s2+s3+s4+s5+s6+s7+s8+MyStr("\n"));
}

void PrintSysError(const MyStr& s1, const MyStr& s2, const MyStr& s3, const MyStr& s4, 
		const MyStr& s5, const MyStr& s6, const MyStr& s7, const MyStr& s8)
{
  if (printerrors)
    Ng_PrintDest(MyStr(" SYSTEM ERROR: ")+s1+s2+s3+s4+s5+s6+s7+s8+MyStr("\n"));
}

void PrintTime(const MyStr& s1, const MyStr& s2, const MyStr& s3, const MyStr& s4, 
	       const MyStr& s5, const MyStr& s6, const MyStr& s7, const MyStr& s8)
{
  if (printmessage_importance >= 3)
    Ng_PrintDest(MyStr(" Time = ")+s1+s2+s3+s4+s5+s6+s7+s8+MyStr("\n"));
}

ARRAY<MyStr*> msgstatus_stack(0);
MyStr* msgstatus = NULL;

void ResetStatus()
{
  SetStatMsg("idle");

  if (msgstatus != NULL)
    {
      delete msgstatus;
    } 
  int i;
  for (i = 1; i <= msgstatus_stack.Size(); i++)
    {
      delete msgstatus_stack.Get(i);
    }
  
  msgstatus_stack.SetSize(0);
  msgstatus = NULL;
  multithread.task = "";
  multithread.percent = 100.;
}

void PushStatus(const MyStr& s)
{
  if (msgstatus == NULL)
    {
      SetStatMsg("idle");
    } 
  msgstatus_stack.Append(msgstatus);
  msgstatus = NULL;

  SetStatMsg(s);
  //  multithread.task = "";
}
void PushStatusF(const MyStr& s)
{
  if (msgstatus == NULL)
    {
      SetStatMsg("idle");
    } 
  msgstatus_stack.Append(msgstatus);
  msgstatus = NULL;

  SetStatMsg(s);
  //  multithread.task = "";
  PrintFnStart(s);
}

void PopStatus()
{
  SetThreadPercent(100.);
  if (msgstatus_stack.Size())
    {
      if (msgstatus != NULL) 
	{
	  delete msgstatus;
	}
      msgstatus = msgstatus_stack.Get(msgstatus_stack.Size());
      msgstatus_stack.SetSize(msgstatus_stack.Size()-1);
      multithread.task = msgstatus->c_str();
    }
  else
    {
      PrintSysError("PopStatus failed");
    }
}
/*
void SetStatMsgF(const MyStr& s)
{
  PrintFnStart(s);
  SetStatMsg(s);
}
*/
void SetStatMsg(const MyStr& s)
{
  if (msgstatus != NULL)
    {
      delete msgstatus;
    }
  msgstatus = new MyStr(s);
  multithread.task = msgstatus->c_str();  
}

void SetThreadPercent(double percent)
{
  multithread.percent = percent;
}


}
