//
//  file.c
//  MobileGmsh
//
//  Created by Maxime Graulich on 21/02/13.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>

int getrlimit$UNIX2003( int resource, struct rlimit *rlp)
{
    return getrlimit(resource, rlp);
}

FILE *fopen$UNIX2003(const char * filename, const char *mode)
{
    return fopen(filename, mode);
}

int fputs$UNIX2003(const char * filename, FILE *file)
{
  return fputs(filename, file);
}

int stat$INODE64(const char * filename, struct stat *buff)
{
    return stat(filename,buff);
}

DIR *opendir$INODE64$UNIX2003(const char *name)
{
    return opendir(name);
}

struct dirent *readdir$INODE64(DIR *dirp)
{
    return readdir(dirp);
}

int closedir$UNIX2003(DIR *dirp)
{
    return closedir(dirp);
}

int socketpair$UNIX2003(int domain, int type, int protocol, int socket_vector[2])
{
    return socketpair(domain, type, protocol, socket_vector);
}

int fcntl$UNIX2003(int fd, int cmd)
{
    return fcntl(fd, cmd);
}

size_t write$UNIX2003(int fildes, const void *buf, size_t nbytes)
{
    return write(fildes, buf, nbytes);
}

int read$UNIX2003(int handle, void *buffer, int nbyte)
{
    return (int)read(handle, buffer, nbyte);
}

int close$UNIX2003(int handle)
{
    return close(handle);
}
int pthread_cond_init$UNIX2003(pthread_cond_t *cond, const pthread_condattr_t *attr)
{
    return pthread_cond_init(cond, attr);
}

int usleep$UNIX2003(useconds_t usec)
{
    return usleep(usec);
}

int bind$UNIX2003(int sockfd, struct sockaddr *my_addr, socklen_t addrlen)
{
    return bind(sockfd, my_addr, addrlen);
}

int getsockname$UNIX2003( int socket, struct sockaddr *restrict adress, socklen_t *restrict adress_len)
{
    return getsockname(socket, adress, adress_len);
}

int listen$UNIX2003(int socket, int backlog)
{
    return listen(socket, backlog);
}

int connect$UNIX2003(int socket, const struct sockaddr *address, socklen_t adress_len)
{
    return connect(socket, address, adress_len);
}

int select$UNIX2003(int nfds, fd_set *restrict readfds, fd_set *restrict writefds, fd_set *restrict errorfds, struct timeval *restrict timeout)
{
    return select(nfds, readfds, readfds, writefds, timeout);
}

ssize_t recv$UNIX2003(int socket, void*buffer, size_t len, int flag)
{
    return recv(socket, buffer, len, flag);
}

int setrlimit$UNIX2003(int ressource, struct rlimit *rlim)
{
    return setrlimit(ressource, rlim);
}
size_t fwrite$UNIX2003(const void *ptr, size_t size, size_t nmemb, FILE *stream)
{
    return fwrite(ptr, size, nmemb, stream);
}

int fstat$INODE64(int fildes, struct stat *buf)
{
    return fstat(fildes, buf);
}

ssize_t send$UNIX2003(int socket, const void *buffer, size_t length, int flags)
{
    return send(socket, buffer, length, flags);
}

clock_t clock$UNIX2003()
{
    return clock();
}

int creat$UNIX2003(const char *path, mode_t mode)
{
  return creat(path, mode);
}

int nanosleep$UNIX2003(const struct timespec *rqtp, struct timespec *rmtp)
{
  return nanosleep(rqtp, rmtp);
}

FILE *popen$UNIX2003(const char *command, const char *mode)
{
  return popen(command, mode);
}

int setenv$UNIX2003(const char *name, const char *value, int overwrite)
{
  return setenv(name, value, overwrite);
}

unsigned int sleep$UNIX2003(unsigned int seconds)
{
  return sleep(seconds);
}

char *strerror$UNIX2003(int errnum)
{
  return strerror(errnum);
}

double strtod$UNIX2003(const char *restrict nptr, char **restrict endptr)
{
  return strtod(nptr, endptr);
}
