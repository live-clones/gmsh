#include "noudt.h"

#include <sys/select.h>
#include <sys/types.h>

namespace UDT {

  class Epoll
  {
   private:
    std::set<SYSSOCKET> _fds;
    static Epoll *_instance;

   public:
    Epoll() {}
    static Epoll* epoll() {
      if(!_instance) _instance = new Epoll();
      return _instance;
    }

    void add_ssock(SYSSOCKET s) {_fds.insert(s);}
    void remove_ssock(SYSSOCKET s) {
      _fds.erase(s);
    }
    std::set<int>::iterator begin() {return _fds.begin();}
    std::set<int>::iterator end() {return _fds.end();}
  };

  Epoll *Epoll::_instance = NULL;

  int startup()
  {
    return 1;
  }

  int cleanup()
  {
    return 1;
  }

  int epoll_create()
  {
    return 1;
  }

  int epoll_add_ssock(int eid, SYSSOCKET s)
  {
    Epoll::epoll()->add_ssock(s);
    return 1;
  }

  int epoll_remove_ssock(int eid, SYSSOCKET s)
  {
    Epoll::epoll()->remove_ssock(s);
    return 1;
  }
  int epoll_wait(int eid, void* readfds, void* writefds, long msTimeOut,
                       std::set<SYSSOCKET>* lrfds, std::set<SYSSOCKET>* wrfds)
  {
    fd_set fds;
    FD_ZERO(&fds);
    for(std::set<SYSSOCKET>::const_iterator i = Epoll::epoll()->begin(); i != Epoll::epoll()->end(); i++)
      FD_SET(*i, &fds);
    struct timeval timeout;
    timeout.tv_sec = 0;
    timeout.tv_usec = 0;
    if(select(*Epoll::epoll()->begin()+1, &fds, NULL, NULL, /*&timeout*/NULL) > 0) {
      for(std::set<SYSSOCKET>::const_iterator i = Epoll::epoll()->begin(); i != Epoll::epoll()->end(); i++) {
        lrfds->insert(*i);
      }
    }
    return 1;
  }
}
