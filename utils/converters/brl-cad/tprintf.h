#ifndef TPRINTF_H_INCLUDED
#define TPRINTF_H_INCLUDED

#include <stdarg.h>
#include <stdio.h>

class tprintf {
        char *buffer;
public:
        tprintf(const char *fmt, ...);
        ~tprintf() { delete buffer; }
        operator const char* () const { return buffer; }
};

inline tprintf::tprintf(const char *fmt, ...)
{
        va_list ap;
        int size=100;
        for(;;)  {
                buffer=new char[size];
                va_start(ap,fmt);
                int new_size=vsnprintf(buffer,size,fmt,ap);
                va_end(ap);
                if(new_size<size) 
                        break;
                size=new_size+1;
                delete buffer;
        }
}
#endif // TPRINTF_H_INCLUDED
