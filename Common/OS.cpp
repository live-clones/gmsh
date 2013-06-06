// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

// This file contains a bunch of functions that depend on OS-dependent
// features and/or system calls

// these are available on all OSes
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <time.h>
#include <math.h>
#include "StringUtils.h"

#if !defined(WIN32) || defined(__CYGWIN__)
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#endif

#if defined(WIN32)
#include <windows.h>
#include <process.h>
#include <psapi.h>
#include <io.h>
#include <direct.h>
#include <fcntl.h>
#include <iostream>
#include <fstream>
#endif

#if defined(__APPLE__)
#define RUSAGE_SELF      0
#define RUSAGE_CHILDREN -1
#endif

#include "GmshMessage.h"

const char *GetEnvironmentVar(const char *var)
{
#if !defined(WIN32)
  return getenv(var);
#else
  const char *tmp = getenv(var);
  // Don't accept top dir or anything partially expanded like
  // c:\Documents and Settings\%USERPROFILE%, etc.
  if(!tmp || !strcmp(tmp, "/") || strstr(tmp, "%") || strstr(tmp, "$"))
    return 0;
  else
    return tmp;
#endif
}

const void SetEnvironmentVar(const char *var, const char *val)
{
#if !defined(WIN32)
  setenv(var, val, 1);
#else
  _putenv((std::string(var) + "=" + std::string(val)).c_str());
#endif
}

double GetTimeInSeconds()
{
#if !defined(WIN32) || defined(__CYGWIN__)
  struct timeval tp;
  gettimeofday(&tp, (struct timezone *)0);
  double t = (double)tp.tv_sec + 1.e-6 * (double)tp.tv_usec;
  return t;
#else
  FILETIME ft;
  GetSystemTimeAsFileTime(&ft);
  double t =  1.e-7 * 4294967296. * (double)ft.dwHighDateTime +
              1.e-7 * (double)ft.dwLowDateTime;
  return t;
#endif
}

void SleepInSeconds(double s)
{
#if !defined(WIN32) || defined(__CYGWIN__)
  usleep((long)(1.e6 * s));
#else
  Sleep((long)(1.e3 * s));
#endif
}

static void GetResources(double *s, long *mem)
{
#if !defined(WIN32) || defined(__CYGWIN__)
  static struct rusage r;
  getrusage(RUSAGE_SELF, &r);
  *s = (double)r.ru_utime.tv_sec + 1.e-6 * (double)r.ru_utime.tv_usec;
#if defined(__APPLE__)
  *mem = (long)r.ru_maxrss;
#else
  *mem = (long)(r.ru_maxrss * 1024L);
#endif
#else
  FILETIME creation, exit, kernel, user;
  if(GetProcessTimes(GetCurrentProcess(), &creation, &exit, &kernel, &user)){
    *s = 1.e-7 * 4294967296. * (double)user.dwHighDateTime +
         1.e-7 * (double)user.dwLowDateTime;
  }
  PROCESS_MEMORY_COUNTERS info;
  GetProcessMemoryInfo(GetCurrentProcess(), &info, sizeof(info));
  *mem = (long)info.PeakWorkingSetSize;
#endif
}

void CheckResources()
{
#if !defined (WIN32) || defined(__CYGWIN__)
  static struct rlimit r;

  getrlimit(RLIMIT_STACK, &r);

  // Try to get at least 16 MB of stack. Running with too small a stack
  // can cause crashes in the recursive calls (e.g. for tet
  // classification in 3D Delaunay)
  if(r.rlim_cur < 16 * 1024 * 1024){
    Msg::Info("Increasing process stack size (%d kB < 16 MB)", r.rlim_cur / 1024);
    r.rlim_cur = r.rlim_max;
    setrlimit(RLIMIT_STACK, &r);
  }
#endif
}

double Cpu()
{
  long mem = 0;
  double s = 0.;
  GetResources(&s, &mem);
  return s;
}

long GetMemoryUsage()
{
  long mem = 0;
  double s = 0.;
  GetResources(&s, &mem);
  return mem;
}

int GetProcessId()
{
#if !defined(WIN32) || defined(__CYGWIN__)
  return getpid();
#else
  return _getpid();
#endif
}

std::string GetHostName()
{
  char host[256];
  gethostname(host, sizeof(host));
  return std::string(host);
}

int UnlinkFile(const std::string &fileName)
{
#if !defined(WIN32) || defined(__CYGWIN__)
  return unlink(fileName.c_str());
#else
  return _unlink(fileName.c_str());
#endif
}

int StatFile(const std::string &fileName)
{
#if !defined(WIN32) || defined(__CYGWIN__)
  struct stat buf;
  int ret = stat(fileName.c_str(), &buf);
  // could get file modification time from buf
#else
  struct _stat buf;
  int ret = _stat(fileName.c_str(), &buf);
#endif
  return ret;
}

int CreateDirectory(const std::string &dirName)
{
#if !defined(WIN32) || defined(__CYGWIN__)
  if(mkdir(dirName.c_str(), 0777))
    return 0;
#else
  if(_mkdir(dirName.c_str()))
    return 0;
#endif
  return 1;
}

int KillProcess(int pid)
{
#if !defined(WIN32) || defined(__CYGWIN__)
  if(kill(pid, 9))
    return 0;
#else
  HANDLE hProc = OpenProcess(PROCESS_TERMINATE, FALSE, pid);
  if(!TerminateProcess(hProc, 0)){
    CloseHandle(hProc);
    return 0;
  }
#endif
  return 1;
}

int SystemCall(const std::string &command, bool blocking)
{
  // separate (potential) executable from arguments
  std::string exe, args;
  std::string::size_type pos = command.find_first_of(" ");
  if(pos != std::string::npos){
    exe = command.substr(0, pos);
    args = command.substr(pos, command.size() - pos);
  }
  else
    exe = command;

  // get executable extension
  std::vector<std::string> split = SplitFileName(exe);

  // do we try to run a .py script or a .exe?
  bool isPython = (split[2] == ".py" || split[2] == ".PY");
  bool isExe = (split[2] == ".exe" || split[2] == ".EXE");

  if(isPython || isExe){
    if(StatFile(exe)){
      Msg::Error("Unable to open file '%s'", exe.c_str());
      return 1;
    }
  }

#if defined(WIN32)
  if(isPython){
    Msg::Info("Shell opening '%s' with arguments '%s'", exe.c_str(),
              args.c_str());
    ShellExecute(NULL, (char*)"open", (char*)exe.c_str(),
                 (char*)args.c_str(), NULL, 0);
  }
  else{
    STARTUPINFO suInfo;
    PROCESS_INFORMATION prInfo;
    memset(&suInfo, 0, sizeof(suInfo));
    suInfo.cb = sizeof(suInfo);
    Msg::Info("Calling '%s'", command.c_str());
    if(blocking){
      CreateProcess(NULL, (char*)command.c_str(), NULL, NULL, FALSE,
		    NORMAL_PRIORITY_CLASS, NULL, NULL,
		    &suInfo, &prInfo);
      // wait until child process exits.
      WaitForSingleObject(prInfo.hProcess, INFINITE);
      // close process and thread handles.
      CloseHandle(prInfo.hProcess);
      CloseHandle(prInfo.hThread);
    }
    else{
      // DETACHED_PROCESS removes the console (useful if the program to launch
      // is a console-mode exe)
      CreateProcess(NULL, (char*)command.c_str(), NULL, NULL, FALSE,
		    NORMAL_PRIORITY_CLASS|DETACHED_PROCESS, NULL, NULL,
		    &suInfo, &prInfo);
    }
  }
#else
  std::string cmd(command);
  if(isPython || isExe){
    if(access(exe.c_str(), X_OK)){
      if(isPython){
        Msg::Info("Script '%s' is not executable: running with python", exe.c_str());
        cmd = "python " + cmd;
      }
      else
        Msg::Warning("File '%s' is not executable", exe.c_str());
    }
    else if(split[0].empty()){
      // workaround if pwd is not in PATH
      cmd = "./" + cmd;
    }
  }
  if(!system(NULL)) {
    Msg::Error("Could not find /bin/sh: aborting system call");
    return 1;
  }
  if(!blocking) cmd += " &";
  Msg::Info("Calling '%s'", cmd.c_str());
  if(!system(cmd.c_str())) return 1;
#endif
  return 0;
}

std::string GetCurrentWorkdir()
{
  char path[1024];
#if defined(WIN32)
  if(!_getcwd(path, sizeof(path))) return "";
#else
  if(!getcwd(path, sizeof(path))) return "";
#endif
  std::string str(path);
  // match the convention of SplitFileName that delivers directory path
  // ending with a directory separator
#if defined(WIN32)
  str.append("\\");
#else
  str.append("/");
#endif
  return str;
}

void RedirectIOToConsole()
{
#if defined(WIN32) && !defined(__CYGWIN__)
  // Win32 GUI apps do not write to the DOS console; make it work again by
  // attaching to parent console, which allows to use the DOS shell to work
  // with Gmsh on the command line (without this hack, you need to either use
  // a better shell (e.g. bash), or compile a /subsystem:console version
  if(!AttachConsole(ATTACH_PARENT_PROCESS)) return;
  // redirect unbuffered stdout, stdin and stderr to the console
  intptr_t lStdHandle = (intptr_t)GetStdHandle(STD_OUTPUT_HANDLE);
  int hConHandle = _open_osfhandle(lStdHandle, _O_TEXT);
  FILE *fp = _fdopen(hConHandle, "w");
  *stdout = *fp;
  setvbuf(stdout, NULL, _IONBF, 0);
  lStdHandle = (intptr_t)GetStdHandle(STD_INPUT_HANDLE);
  hConHandle = _open_osfhandle(lStdHandle, _O_TEXT);
  fp = _fdopen(hConHandle, "r");
  *stdin = *fp;
  setvbuf(stdin, NULL, _IONBF, 0);
  lStdHandle = (intptr_t)GetStdHandle(STD_ERROR_HANDLE);
  hConHandle = _open_osfhandle(lStdHandle, _O_TEXT);
  fp = _fdopen(hConHandle, "w");
  *stderr = *fp;
  setvbuf(stderr, NULL, _IONBF, 0);
  // make cout, wcout, cin, wcin, wcerr, cerr, wclog and clog point to
  // console as well
  std::ios::sync_with_stdio();
#endif
}
