// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// This file contains a bunch of functions that depend on OS-dependent
// features and/or system calls

// these are available on all OSes
#include <chrono>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <time.h>
#include <math.h>
#include "GmshConfig.h"
#include "StringUtils.h"
#include "Context.h"

#if defined(HAVE_ZIPPER)
#include <iostream>
#include <fstream>
#include "zipper.h"
#include "unzipper.h"
#endif

#if defined(__APPLE__)
#include <sys/sysctl.h>
#include <mach-o/dyld.h>
#endif

#if defined(__linux__) && !defined(BUILD_ANDROID)
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
#include <sys/timeb.h>
#include <wchar.h>
#endif

#include "GmshMessage.h"

#if defined(WIN32) && !defined(__CYGWIN__)

// Unicode utility routines borrowed from FLTK

static unsigned int utf8decode(const char *p, const char *end, int *len)
{
  static unsigned short cp1252[32] = {
    0x20ac, 0x0081, 0x201a, 0x0192, 0x201e, 0x2026, 0x2020, 0x2021,
    0x02c6, 0x2030, 0x0160, 0x2039, 0x0152, 0x008d, 0x017d, 0x008f,
    0x0090, 0x2018, 0x2019, 0x201c, 0x201d, 0x2022, 0x2013, 0x2014,
    0x02dc, 0x2122, 0x0161, 0x203a, 0x0153, 0x009d, 0x017e, 0x0178};
  unsigned char c = *(unsigned char *)p;
  if(c < 0x80) {
    if(len) *len = 1;
    return c;
  }
  else if(c < 0xa0) {
    if(len) *len = 1;
    return cp1252[c - 0x80];
  }
  else if(c < 0xc2) {
    goto FAIL;
  }
  if((end && p + 1 >= end) || (p[1] & 0xc0) != 0x80) goto FAIL;
  if(c < 0xe0) {
    if(len) *len = 2;
    return ((p[0] & 0x1f) << 6) + ((p[1] & 0x3f));
  }
  else if(c == 0xe0) {
    if(((unsigned char *)p)[1] < 0xa0) goto FAIL;
    goto UTF8_3;
  }
  else if(c < 0xf0) {
  UTF8_3:
    if((end && p + 2 >= end) || (p[2] & 0xc0) != 0x80) goto FAIL;
    if(len) *len = 3;
    return ((p[0] & 0x0f) << 12) + ((p[1] & 0x3f) << 6) + ((p[2] & 0x3f));
  }
  else if(c == 0xf0) {
    if(((unsigned char *)p)[1] < 0x90) goto FAIL;
    goto UTF8_4;
  }
  else if(c < 0xf4) {
  UTF8_4:
    if((end && p + 3 >= end) || (p[2] & 0xc0) != 0x80 || (p[3] & 0xc0) != 0x80)
      goto FAIL;
    if(len) *len = 4;
    return ((p[0] & 0x07) << 18) + ((p[1] & 0x3f) << 12) +
           ((p[2] & 0x3f) << 6) + ((p[3] & 0x3f));
  }
  else if(c == 0xf4) {
    if(((unsigned char *)p)[1] > 0x8f) goto FAIL; // after 0x10ffff
    goto UTF8_4;
  }
  else {
  FAIL:
    if(len) *len = 1;
    return c;
  }
}

static unsigned int utf8toUtf16(const char *src, unsigned int srclen,
                                unsigned short *dst, unsigned int dstlen)
{
  const char *p = src;
  const char *e = src + srclen;
  unsigned int count = 0;
  if(dstlen)
    for(;;) {
      if(p >= e) {
        dst[count] = 0;
        return count;
      }
      if(!(*p & 0x80)) { // ascii
        dst[count] = *p++;
      }
      else {
        int len;
        unsigned int ucs = utf8decode(p, e, &len);
        p += len;
        if(ucs < 0x10000) {
          dst[count] = ucs;
        }
        else {
          // make a surrogate pair:
          if(count + 2 >= dstlen) {
            dst[count] = 0;
            count += 2;
            break;
          }
          dst[count] = (((ucs - 0x10000u) >> 10) & 0x3ff) | 0xd800;
          dst[++count] = (ucs & 0x3ff) | 0xdc00;
        }
      }
      if(++count == dstlen) {
        dst[count - 1] = 0;
        break;
      }
    }
  // we filled dst, measure the rest:
  while(p < e) {
    if(!(*p & 0x80))
      p++;
    else {
      int len;
      unsigned int ucs = utf8decode(p, e, &len);
      p += len;
      if(ucs >= 0x10000) ++count;
    }
    ++count;
  }
  return count;
}

static unsigned int utf8FromUtf16(char *dst, unsigned int dstlen,
                                  const wchar_t *src, unsigned int srclen)
{
  unsigned int i = 0;
  unsigned int count = 0;
  if(dstlen) {
    for(;;) {
      unsigned int ucs;
      if(i >= srclen) {
        dst[count] = 0;
        return count;
      }
      ucs = src[i++];
      if(ucs < 0x80U) {
        dst[count++] = ucs;
        if(count >= dstlen) {
          dst[count - 1] = 0;
          break;
        }
      }
      else if(ucs < 0x800U) { /* 2 bytes */
        if(count + 2 >= dstlen) {
          dst[count] = 0;
          count += 2;
          break;
        }
        dst[count++] = 0xc0 | (ucs >> 6);
        dst[count++] = 0x80 | (ucs & 0x3F);
      }
      else if(ucs >= 0xd800 && ucs <= 0xdbff && i < srclen &&
              src[i] >= 0xdc00 && src[i] <= 0xdfff) {
        /* surrogate pair */
        unsigned int ucs2 = src[i++];
        ucs = 0x10000U + ((ucs & 0x3ff) << 10) + (ucs2 & 0x3ff);
        /* all surrogate pairs turn into 4-byte utf8 */
        if(count + 4 >= dstlen) {
          dst[count] = 0;
          count += 4;
          break;
        }
        dst[count++] = 0xf0 | (ucs >> 18);
        dst[count++] = 0x80 | ((ucs >> 12) & 0x3F);
        dst[count++] = 0x80 | ((ucs >> 6) & 0x3F);
        dst[count++] = 0x80 | (ucs & 0x3F);
      }
      else {
        /* all others are 3 bytes: */
        if(count + 3 >= dstlen) {
          dst[count] = 0;
          count += 3;
          break;
        }
        dst[count++] = 0xe0 | (ucs >> 12);
        dst[count++] = 0x80 | ((ucs >> 6) & 0x3F);
        dst[count++] = 0x80 | (ucs & 0x3F);
      }
    }
  }
  /* we filled dst, measure the rest: */
  while(i < srclen) {
    unsigned int ucs = src[i++];
    if(ucs < 0x80U) {
      count++;
    }
    else if(ucs < 0x800U) { /* 2 bytes */
      count += 2;
    }
    else if(ucs >= 0xd800 && ucs <= 0xdbff && i < srclen - 1 &&
            src[i + 1] >= 0xdc00 && src[i + 1] <= 0xdfff) {
      /* surrogate pair */
      ++i;
      count += 4;
    }
    else {
      count += 3;
    }
  }
  return count;
}

static wchar_t *wbuf[3] = {nullptr, nullptr, nullptr};

static void setwbuf(int i, const char *f)
{
  // all strings in Gmsh are supposed to be UTF8-encoded, which is natively
  // supported by Mac and Linux. Windows does not support UTF-8, but UTF-16
  // (through wchar_t), so we need to convert.
  if(i < 0 || i > 2) {
    Msg::Error("Wrong buffer index in setwbuf");
    return;
  }
  size_t l = strlen(f);
  unsigned int wn = utf8toUtf16(f, (unsigned int)l, nullptr, 0) + 1;
  wbuf[i] = (wchar_t *)realloc(wbuf[i], sizeof(wchar_t) * wn);
  wn = utf8toUtf16(f, (unsigned)l, (unsigned short *)wbuf[i], wn);
  wbuf[i][wn] = 0;
}

#endif

FILE *Fopen(const char *f, const char *mode)
{
#if defined(WIN32) && !defined(__CYGWIN__)
  setwbuf(0, f);
  setwbuf(1, mode);
  return _wfopen(wbuf[0], wbuf[1]);
#else
  return fopen(f, mode);
#endif
}

std::string GetEnvironmentVar(const std::string &var)
{
#if defined(WIN32) && !defined(__CYGWIN__)
  setwbuf(0, var.c_str());
  const wchar_t *wtmp = _wgetenv(wbuf[0]);
  if(!wtmp) return "";
  char tmp[MAX_PATH];
  utf8FromUtf16(tmp, MAX_PATH, wtmp, wcslen(wtmp));
  // Don't accept top dir or anything partially expanded like
  // Settings\%USERPROFILE%, etc.
  if(!strcmp(tmp, "/") || strstr(tmp, "%") || strstr(tmp, "$"))
    return "";
  else
    return std::string(tmp);
#else
  const char *tmp = getenv(var.c_str());
  if(!tmp) return "";
  return std::string(tmp);
#endif
}

void SetEnvironmentVar(const std::string &var, const std::string &val)
{
#if defined(WIN32) && !defined(__CYGWIN__)
  setwbuf(0, (var + "=" + val).c_str());
  _wputenv(wbuf[0]);
#else
  setenv(var.c_str(), val.c_str(), 1);
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

static void GetResources(double &s, std::size_t &mem)
{
#if defined(WIN32) && !defined(__CYGWIN__)
  FILETIME creation, exit, kernel, user;
  if(GetProcessTimes(GetCurrentProcess(), &creation, &exit, &kernel, &user)) {
    s = 1.e-7 * 4294967296. * (double)user.dwHighDateTime +
        1.e-7 * (double)user.dwLowDateTime;
  }
  PROCESS_MEMORY_COUNTERS info;
  GetProcessMemoryInfo(GetCurrentProcess(), &info, sizeof(info));
  mem = (std::size_t)info.PeakWorkingSetSize;
#else
  static struct rusage r;
  getrusage(RUSAGE_SELF, &r);
  s = (double)r.ru_utime.tv_sec + 1.e-6 * (double)r.ru_utime.tv_usec;
#if defined(__APPLE__)
  mem = (std::size_t)r.ru_maxrss;
#else
  mem = (std::size_t)(r.ru_maxrss * 1024L);
#endif
#endif
}

void CheckResources()
{
#if !defined(WIN32) || defined(__CYGWIN__)
  static struct rlimit r;

  getrlimit(RLIMIT_STACK, &r);

  // Try to get at least 16 MB of stack. Running with too small a stack
  // can cause crashes in the recursive calls (e.g. for tet
  // classification in 3D Delaunay)
  if(r.rlim_cur < 16 * 1024 * 1024) {
    Msg::Info("Increasing process stack size (%d kB < 16 MB)",
              r.rlim_cur / 1024);
    r.rlim_cur = r.rlim_max;
    setrlimit(RLIMIT_STACK, &r);
  }
#endif
}

double Cpu()
{
  double s = 0.;
  std::size_t mem = 0;
  GetResources(s, mem);
  return s;
}

double TotalRam()
{
  double ram = 0;
#if defined(__APPLE__)
  int name[] = {CTL_HW, HW_MEMSIZE};
  int64_t value;
  size_t len = sizeof(value);
  if(sysctl(name, 2, &value, &len, nullptr, 0) != -1)
    ram = value / (1024 * 1024);
#elif defined(WIN32)
  MEMORYSTATUSEX status;
  status.dwLength = sizeof(status);
  GlobalMemoryStatusEx(&status);
  ram = status.ullTotalPhys / ((double)1024 * 1024);
#elif defined(BUILD_ANDROID)
  ram = 1024;
#elif defined(__linux__)
  struct sysinfo infos;
  if(sysinfo(&infos) != -1)
    ram =
      infos.totalram * (unsigned long)infos.mem_unit / ((double)1024 * 1024);
#endif
  return ram;
}

double TimeOfDay()
{
  //auto t = std::chrono::system_clock::now();
  auto t = std::chrono::steady_clock::now(); // guaranteed monotonic
  return std::chrono::duration<double>(t.time_since_epoch()).count();
}

std::size_t GetMemoryUsage()
{
  double s = 0.;
  std::size_t mem = 0;
  GetResources(s, mem);
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

std::string GetExecutableFileName()
{
  std::string name = "";
#if defined(WIN32) && !defined(__CYGWIN__)
  wchar_t src[MAX_PATH];
  unsigned long size = GetModuleFileNameW(nullptr, src, MAX_PATH);
  if(size) {
    char dst[MAX_PATH];
    utf8FromUtf16(dst, MAX_PATH, src, size);
    name = std::string(dst);
  }
#elif defined(__APPLE__)
  char path[PATH_MAX];
  uint32_t size = sizeof(path);
  if(_NSGetExecutablePath(path, &size) == 0) {
    char real[PATH_MAX];
    if(realpath(path, real)) {
      name = std::string(real);
    }
  }
#elif defined(__linux__)
  char path[4096];
  int n = readlink("/proc/self/exe", path, sizeof(path));
  if(n > 0 && n < (int)sizeof(path)) {
    path[n] = '\0';
    name = std::string(path);
  }
#endif
  return name;
}

std::string GetAbsolutePath(const std::string &fileName)
{
#if defined(WIN32) && !defined(__CYGWIN__)
  setwbuf(0, fileName.c_str());
  wchar_t path[MAX_PATH];
  unsigned long size = GetFullPathNameW(wbuf[0], MAX_PATH, path, nullptr);
  if(size) {
    char dst[MAX_PATH];
    utf8FromUtf16(dst, MAX_PATH, path, size);
    return std::string(dst);
  }
#else
  char path[4096];
  if(realpath(fileName.c_str(), path)) return path;
#endif
  return fileName;
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

int CreateSingleDir(const std::string &dirName)
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
    cur = dirname.find('/', cur + 1);
    CreateSingleDir(dirname.substr(0, cur));
  }
}

int KillProcess(int pid)
{
#if defined(WIN32) && !defined(__CYGWIN__)
  HANDLE hProc = OpenProcess(PROCESS_TERMINATE, FALSE, pid);
  if(!TerminateProcess(hProc, 0)) {
    CloseHandle(hProc);
    return 0;
  }
#else
  if(kill(pid, 9)) return 0;
#endif
  return 1;
}

int SystemCallExe(const std::string &exe, const std::string &argsOrCommand,
                  bool blocking)
{
  // do we try to run a .py script, .m script or an .exe?
  std::vector<std::string> split = SplitFileName(exe);
  bool isPython = (split[2] == ".py" || split[2] == ".PY");
  bool isOctave = (split[2] == ".m" || split[2] == ".M");
  bool isExe = (split[2] == ".exe" || split[2] == ".EXE");

  if(isPython || isOctave || isExe) {
    if(StatFile(exe)) {
      Msg::Error("Unable to open file '%s'", exe.c_str());
      return 1;
    }
  }

  std::string command;
  if(exe.size()) {
    command.append("\"" + exe + "\""); // allows exe with white space
    if(argsOrCommand.size()) command.append(" ");
  }
  command.append(argsOrCommand);

#if defined(WIN32) && !defined(__CYGWIN__)
  if(isPython || isOctave) {
    Msg::Info("Shell opening '%s' with arguments '%s'", exe.c_str(),
              argsOrCommand.c_str());
    setwbuf(0, "open");
    setwbuf(1, exe.c_str());
    setwbuf(2, argsOrCommand.c_str());
    ShellExecuteW(nullptr, wbuf[0], wbuf[1], wbuf[2], nullptr, 0);
  }
  else {
    STARTUPINFOW suInfo;
    PROCESS_INFORMATION prInfo;
    memset(&suInfo, 0, sizeof(suInfo));
    suInfo.cb = sizeof(suInfo);
    Msg::Info("Calling '%s'", command.c_str());
    setwbuf(0, command.c_str());
    if(blocking) {
      CreateProcessW(nullptr, wbuf[0], nullptr, nullptr, FALSE,
                     NORMAL_PRIORITY_CLASS, nullptr, nullptr, &suInfo, &prInfo);
      // wait until child process exits.
      WaitForSingleObject(prInfo.hProcess, INFINITE);
      // close process and thread handles.
      CloseHandle(prInfo.hProcess);
      CloseHandle(prInfo.hThread);
    }
    else {
      // DETACHED_PROCESS removes the console (useful if the program to launch
      // is a console-mode exe)
      DWORD dwCreationFlags;
      if(CTX::instance()->detachedProcess)
        dwCreationFlags = NORMAL_PRIORITY_CLASS | DETACHED_PROCESS;
      else
        dwCreationFlags = NORMAL_PRIORITY_CLASS;

      CreateProcessW(nullptr, wbuf[0], nullptr, nullptr, FALSE,
                     dwCreationFlags, nullptr, nullptr, &suInfo, &prInfo);
    }
  }
#elif(BUILD_IOS)
  Msg::Warning("SystemCall is not supported on iOS");
#else
  std::string cmd(command);
  if(isPython || isOctave || isExe) {
    if(access(exe.c_str(), X_OK)) {
      if(isPython) {
        Msg::Info("Script '%s' is not executable: running with `%s'",
                  exe.c_str(),
                  CTX::instance()->solver.pythonInterpreter.c_str());
        cmd = CTX::instance()->solver.pythonInterpreter + " " + cmd;
      }
      else if(isOctave) {
        Msg::Info("Script '%s' is not executable: running with `%s'",
                  exe.c_str(),
                  CTX::instance()->solver.octaveInterpreter.c_str());
        cmd = CTX::instance()->solver.octaveInterpreter + " " + cmd;
      }
      else
        Msg::Warning("File '%s' is not executable", exe.c_str());
    }
    else if(split[0].empty()) {
      // workaround if pwd is not in PATH
      cmd = "./" + cmd;
    }
  }
  if(!system(nullptr)) {
    Msg::Error("Could not find /bin/sh: aborting system call");
    return 1;
  }
  if(!blocking) cmd += " &";
  Msg::Info("Calling '%s'", cmd.c_str());
  return system(cmd.c_str());
#endif
  return 0;
}

int SystemCall(const std::string &command, bool blocking)
{
  return SystemCallExe("", command, blocking);
}

void RedirectIOToConsole()
{
#if defined(WIN32) && !defined(__CYGWIN__)
  // Win32 GUI apps do not write to the DOS console; make it work again by
  // attaching to parent console, which allows one to use the DOS shell to work
  // with Gmsh on the command line (without this hack, you need to either use a
  // better shell (e.g. bash), or compile a /subsystem:console version
  if(!AttachConsole(ATTACH_PARENT_PROCESS)) return;
  // redirect unbuffered stdout, stdin and stderr to the console
  {
    intptr_t lStdHandle = (intptr_t)GetStdHandle(STD_OUTPUT_HANDLE);
    if(lStdHandle != (intptr_t)INVALID_HANDLE_VALUE) {
      int hConHandle = _open_osfhandle(lStdHandle, _O_TEXT);
      if(hConHandle >= 0) {
        FILE *fp = _fdopen(hConHandle, "w");
        if(fp) {
          *stdout = *fp;
          setvbuf(stdout, nullptr, _IONBF, 0);
        }
      }
    }
  }
  {
    intptr_t lStdHandle = (intptr_t)GetStdHandle(STD_INPUT_HANDLE);
    if(lStdHandle != (intptr_t)INVALID_HANDLE_VALUE) {
      int hConHandle = _open_osfhandle(lStdHandle, _O_TEXT);
      if(hConHandle >= 0) {
        FILE *fp = _fdopen(hConHandle, "r");
        if(fp) {
          *stdin = *fp;
          setvbuf(stdin, nullptr, _IONBF, 0);
        }
      }
    }
  }
  {
    intptr_t lStdHandle = (intptr_t)GetStdHandle(STD_ERROR_HANDLE);
    if(lStdHandle != (intptr_t)INVALID_HANDLE_VALUE) {
      int hConHandle = _open_osfhandle(lStdHandle, _O_TEXT);
      if(hConHandle >= 0) {
        FILE *fp = _fdopen(hConHandle, "w");
        if(fp) {
          *stderr = *fp;
          setvbuf(stderr, nullptr, _IONBF, 0);
        }
      }
    }
  }
  // make cout, wcout, cin, wcin, wcerr, cerr, wclog and clog point to console
  // as well
  std::ios::sync_with_stdio();
#endif
}

void UnzipFile(const std::string &fileName, const std::string &prependDir)
{
#if defined(HAVE_ZIPPER)
  std::string dir = prependDir;
  if(dir.size() && dir[dir.size() - 1] != '/' && dir[dir.size() - 1] != '\\')
    dir.push_back('/');

  ziputils::unzipper zipFile;
  zipFile.open(fileName.c_str());
  std::vector<std::string> dirnames = zipFile.getFolders();
  for(auto it = dirnames.begin(); it != dirnames.end(); it++) {
    std::string folder = dir + *it;
    Msg::Info("Creating folder `%s'", folder.c_str());
    CreatePath(folder);
  }
  std::vector<std::string> filenames = zipFile.getFilenames();
  for(auto it = filenames.begin(); it != filenames.end(); it++) {
    zipFile.openEntry(it->c_str());
    std::string name = dir + *it;
    Msg::Info("Extracting file `%s'", name.c_str());
    std::ofstream ofs;
    ofs.open(name.c_str());
    if(ofs.is_open()) {
      zipFile >> ofs;
      ofs.close();
    }
    else
      Msg::Error("Could not create file `%s'", name.c_str());
  }
#else
  Msg::Error("Gmsh must be compiled with Zipper support to extract zip files");
#endif
}
