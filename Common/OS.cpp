// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
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
#include "GmshConfig.h"
#include "StringUtils.h"

#if defined(__APPLE__)
#include <sys/sysctl.h>
#endif

#if defined(__linux__)
#include <sys/sysinfo.h>
#endif

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

#include "GmshMessage.h"

#if defined(WIN32) && !defined(__CYGWIN__)

// Unicode utility routines borrowed from FLTK

static unsigned utf8decode(const char* p, const char* end, int* len)
{
  static unsigned short cp1252[32] = {
    0x20ac, 0x0081, 0x201a, 0x0192, 0x201e, 0x2026, 0x2020, 0x2021,
    0x02c6, 0x2030, 0x0160, 0x2039, 0x0152, 0x008d, 0x017d, 0x008f,
    0x0090, 0x2018, 0x2019, 0x201c, 0x201d, 0x2022, 0x2013, 0x2014,
    0x02dc, 0x2122, 0x0161, 0x203a, 0x0153, 0x009d, 0x017e, 0x0178
  };
  unsigned char c = *(unsigned char*)p;
  if (c < 0x80) {
    if (len) *len = 1;
    return c;
  } else if (c < 0xa0) {
    if (len) *len = 1;
    return cp1252[c-0x80];
  } else if (c < 0xc2) {
    goto FAIL;
  }
  if ( (end && p+1 >= end) || (p[1]&0xc0) != 0x80) goto FAIL;
  if (c < 0xe0) {
    if (len) *len = 2;
    return
      ((p[0] & 0x1f) << 6) +
      ((p[1] & 0x3f));
  } else if (c == 0xe0) {
    if (((unsigned char*)p)[1] < 0xa0) goto FAIL;
    goto UTF8_3;
  } else if (c < 0xf0) {
  UTF8_3:
    if ( (end && p+2 >= end) || (p[2]&0xc0) != 0x80) goto FAIL;
    if (len) *len = 3;
    return
      ((p[0] & 0x0f) << 12) +
      ((p[1] & 0x3f) << 6) +
      ((p[2] & 0x3f));
  } else if (c == 0xf0) {
    if (((unsigned char*)p)[1] < 0x90) goto FAIL;
    goto UTF8_4;
  } else if (c < 0xf4) {
  UTF8_4:
    if ( (end && p+3 >= end) || (p[2]&0xc0) != 0x80 || (p[3]&0xc0) != 0x80) goto FAIL;
    if (len) *len = 4;
    return
      ((p[0] & 0x07) << 18) +
      ((p[1] & 0x3f) << 12) +
      ((p[2] & 0x3f) << 6) +
      ((p[3] & 0x3f));
  } else if (c == 0xf4) {
    if (((unsigned char*)p)[1] > 0x8f) goto FAIL; // after 0x10ffff
    goto UTF8_4;
  } else {
  FAIL:
    if (len) *len = 1;
    return c;
  }
}

static unsigned utf8toUtf16(const char* src, unsigned srclen,
                            unsigned short* dst, unsigned dstlen)
{
  const char* p = src;
  const char* e = src+srclen;
  unsigned count = 0;
  if (dstlen) for (;;) {
    if (p >= e) {dst[count] = 0; return count;}
    if (!(*p & 0x80)) { // ascii
      dst[count] = *p++;
    } else {
      int len; unsigned ucs = utf8decode(p,e,&len);
      p += len;
      if (ucs < 0x10000) {
	dst[count] = ucs;
      } else {
	// make a surrogate pair:
	if (count+2 >= dstlen) {dst[count] = 0; count += 2; break;}
	dst[count] = (((ucs-0x10000u)>>10)&0x3ff) | 0xd800;
	dst[++count] = (ucs&0x3ff) | 0xdc00;
      }
    }
    if (++count == dstlen) {dst[count-1] = 0; break;}
  }
  // we filled dst, measure the rest:
  while (p < e) {
    if (!(*p & 0x80)) p++;
    else {
      int len; unsigned ucs = utf8decode(p,e,&len);
      p += len;
      if (ucs >= 0x10000) ++count;
    }
    ++count;
  }
  return count;
}

static wchar_t *wbuf[3] = {NULL, NULL, NULL};

static void setwbuf(int i, const char *f)
{
  // all strings in Gmsh are supposed to be UTF8-encoded, which is natively
  // supported by Mac and Linux. Windows does not support UTF-8, but UTF-16
  // (through wchar_t), so we need to convert.
  if(i < 0 || i > 2) return;
  size_t l = strlen(f);
  unsigned wn = utf8toUtf16(f, (unsigned) l, NULL, 0) + 1;
  wbuf[i] = (wchar_t*)realloc(wbuf[i], sizeof(wchar_t)*wn);
  wn = utf8toUtf16(f, (unsigned) l, (unsigned short *)wbuf[i], wn);
  wbuf[i][wn] = 0;
}

#endif

FILE *Fopen(const char *f, const char *mode)
{
#if defined (WIN32) && !defined(__CYGWIN__)
  setwbuf(0, f);
  setwbuf(1, mode);
  return _wfopen(wbuf[0], wbuf[1]);
#else
  return fopen(f, mode);
#endif
}

const char *GetEnvironmentVar(const char *var)
{
#if defined(WIN32) && !defined(__CYGWIN__)
  // Should probably use the Unicode version
  const char *tmp = getenv(var);
  // Don't accept top dir or anything partially expanded like
  // c:\Documents and Settings\%USERPROFILE%, etc.
  if(!tmp || !strcmp(tmp, "/") || strstr(tmp, "%") || strstr(tmp, "$"))
    return 0;
  else
    return tmp;
#else
  return getenv(var);
#endif
}

const void SetEnvironmentVar(const char *var, const char *val)
{
#if defined(WIN32) && !defined(__CYGWIN__)
  // should probably use Unicode version here
  _putenv((std::string(var) + "=" + std::string(val)).c_str());
#else
  setenv(var, val, 1);
#endif
}

double GetTimeInSeconds()
{
#if defined(WIN32) && !defined(__CYGWIN__)
  FILETIME ft;
  GetSystemTimeAsFileTime(&ft);
  double t =  1.e-7 * 4294967296. * (double)ft.dwHighDateTime +
              1.e-7 * (double)ft.dwLowDateTime;
  return t;
#else
  struct timeval tp;
  gettimeofday(&tp, (struct timezone *)0);
  double t = (double)tp.tv_sec + 1.e-6 * (double)tp.tv_usec;
  return t;
#endif
}

void SleepInSeconds(double s)
{
#if defined(WIN32) && !defined(__CYGWIN__)
  Sleep((long)(1.e3 * s));
#else
  usleep((long)(1.e6 * s));
#endif
}

static void GetResources(double *s, long *mem)
{
#if defined(WIN32) && !defined(__CYGWIN__)
  FILETIME creation, exit, kernel, user;
  if(GetProcessTimes(GetCurrentProcess(), &creation, &exit, &kernel, &user)){
    *s = 1.e-7 * 4294967296. * (double)user.dwHighDateTime +
         1.e-7 * (double)user.dwLowDateTime;
  }
  PROCESS_MEMORY_COUNTERS info;
  GetProcessMemoryInfo(GetCurrentProcess(), &info, sizeof(info));
  *mem = (long)info.PeakWorkingSetSize;
#else
  static struct rusage r;
  getrusage(RUSAGE_SELF, &r);
  *s = (double)r.ru_utime.tv_sec + 1.e-6 * (double)r.ru_utime.tv_usec;
#if defined(__APPLE__)
  *mem = (long)r.ru_maxrss;
#else
  *mem = (long)(r.ru_maxrss * 1024L);
#endif
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

double TotalRam()
{
  double ram = 0;
#if defined(__APPLE__)
  int name[] = {CTL_HW, HW_MEMSIZE};
  int64_t value;
  size_t len = sizeof(value);
  if(sysctl(name, 2, &value, &len, NULL, 0) != -1)
    ram = value / (1024 * 1024);
#elif defined (WIN32)
  MEMORYSTATUSEX status;
  status.dwLength = sizeof(status);
  GlobalMemoryStatusEx(&status);
  ram = status.ullTotalPhys  / ((double)1024 * 1024);
#elif defined(__linux__)
  struct sysinfo infos;
  if(sysinfo(&infos) != -1)
    ram = infos.totalram * (unsigned long)infos.mem_unit / ((double)1024 * 1024);
#endif
  return ram;
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
#if defined(WIN32) && !defined(__CYGWIN__)
  return _getpid();
#else
  return getpid();
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
#if defined(WIN32) && !defined(__CYGWIN__)
  setwbuf(0, fileName.c_str());
  return _wunlink(wbuf[0]);
#else
  return unlink(fileName.c_str());
#endif
}

int StatFile(const std::string &fileName)
{
#if defined(WIN32) && !defined(__CYGWIN__)
  struct _stat buf;
  setwbuf(0, fileName.c_str());
  int ret = _wstat(wbuf[0], &buf);
#else
  struct stat buf;
  int ret = stat(fileName.c_str(), &buf);
#endif
  return ret;
}

int CreateDirectory(const std::string &dirName)
{
#if defined(WIN32) && !defined(__CYGWIN__)
  setwbuf(0, dirName.c_str());
  if(_wmkdir(wbuf[0])) return 0;
#else
  if(mkdir(dirName.c_str(), 0777)) return 0;
#endif
  return 1;
}

void CreatePath(const std::string &fullPath)
{
  size_t lastp = fullPath.find_last_of('/'); // TODO: handle backslash for win?
  if(lastp == std::string::npos) return;
  std::string dirname = std::string(fullPath, 0, lastp);
  size_t cur = 0;
  while(cur != std::string::npos) {
    cur = dirname.find("/", cur + 1);
    CreateDirectory(dirname.substr(0, cur));
  }
}

int KillProcess(int pid)
{
#if defined(WIN32) && !defined(__CYGWIN__)
  HANDLE hProc = OpenProcess(PROCESS_TERMINATE, FALSE, pid);
  if(!TerminateProcess(hProc, 0)){
    CloseHandle(hProc);
    return 0;
  }
#else
  if(kill(pid, 9))
    return 0;
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

#if defined(WIN32) && !defined(__CYGWIN__)
  if(isPython){
    Msg::Info("Shell opening '%s' with arguments '%s'", exe.c_str(),
              args.c_str());
    setwbuf(0, "open");
    setwbuf(1, exe.c_str());
    setwbuf(2, args.c_str());
    ShellExecuteW(NULL, wbuf[0], wbuf[1], wbuf[2], NULL, 0);
  }
  else{
    STARTUPINFOW suInfo;
    PROCESS_INFORMATION prInfo;
    memset(&suInfo, 0, sizeof(suInfo));
    suInfo.cb = sizeof(suInfo);
    Msg::Info("Calling '%s'", command.c_str());
    setwbuf(0, command.c_str());
    if(blocking){
      CreateProcessW(NULL, wbuf[0], NULL, NULL, FALSE,
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
      CreateProcessW(NULL, wbuf[0], NULL, NULL, FALSE,
		    NORMAL_PRIORITY_CLASS|DETACHED_PROCESS, NULL, NULL,
		    &suInfo, &prInfo);
    }
  }
#else
  std::string cmd(command);
  if(isPython || isExe){
    if(access(exe.c_str(), X_OK)){
      if(isPython){
        Msg::Info("Script '%s' is not executable: running with python",
		  exe.c_str());
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

#if defined(WIN32) && !defined(__CYGWIN__)
  // should use Unicode version
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
  // attaching to parent console, which allows to use the DOS shell to work with
  // Gmsh on the command line (without this hack, you need to either use a
  // better shell (e.g. bash), or compile a /subsystem:console version
  if(!AttachConsole(ATTACH_PARENT_PROCESS)) return;
  // redirect unbuffered stdout, stdin and stderr to the console
  {
    intptr_t lStdHandle = (intptr_t)GetStdHandle(STD_OUTPUT_HANDLE);
    if(lStdHandle != (intptr_t)INVALID_HANDLE_VALUE){
      int hConHandle = _open_osfhandle(lStdHandle, _O_TEXT);
      if(hConHandle >= 0){
        FILE *fp = _fdopen(hConHandle, "w");
        if(fp){
          *stdout = *fp;
          setvbuf(stdout, NULL, _IONBF, 0);
        }
      }
    }
  }
  {
    intptr_t lStdHandle = (intptr_t)GetStdHandle(STD_INPUT_HANDLE);
    if(lStdHandle != (intptr_t)INVALID_HANDLE_VALUE){
      int hConHandle = _open_osfhandle(lStdHandle, _O_TEXT);
      if(hConHandle >= 0){
        FILE *fp = _fdopen(hConHandle, "r");
        if(fp){
          *stdin = *fp;
          setvbuf(stdin, NULL, _IONBF, 0);
        }
      }
    }
  }
  {
    intptr_t lStdHandle = (intptr_t)GetStdHandle(STD_ERROR_HANDLE);
    if(lStdHandle != (intptr_t)INVALID_HANDLE_VALUE){
      int hConHandle = _open_osfhandle(lStdHandle, _O_TEXT);
      if(hConHandle >= 0){
        FILE *fp = _fdopen(hConHandle, "w");
        if(fp){
          *stderr = *fp;
          setvbuf(stderr, NULL, _IONBF, 0);
        }
      }
    }
  }
  // make cout, wcout, cin, wcin, wcerr, cerr, wclog and clog point to console
  // as well
  std::ios::sync_with_stdio();
#endif
}
