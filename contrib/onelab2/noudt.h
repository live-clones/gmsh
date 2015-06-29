#include <set>
#include <cstddef>

#ifdef WIN32
   #ifndef __MINGW__
      typedef SOCKET SYSSOCKET;
   #else
      typedef int SYSSOCKET;
   #endif
#else
   typedef int SYSSOCKET;
#endif


namespace UDT {
  const int ERROR = -1;

  int startup();
  int cleanup();
  int epoll_create();
  int epoll_add_ssock(int eid, SYSSOCKET s);
  int epoll_remove_ssock(int eid, SYSSOCKET s);
  int epoll_wait(int eid, void* readfds, void* writefds, long msTimeOut,
                       std::set<SYSSOCKET>* lrfds = NULL, std::set<SYSSOCKET>* wrfds = NULL);
}
