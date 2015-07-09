//logger.cpp
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include "logger.h"


#define DEFAULT_LOG 0

static int log_level = DEFAULT_LOG;

char* print_time()
{
    time_t t;
    char *buf;
     
    time(&t);
    buf = (char*)malloc(strlen(ctime(&t))+ 1);
     
    snprintf(buf,strlen(ctime(&t)),"%s ", ctime(&t));
    
    return buf;
}

void log_print(int level, char *fmt,...) {
    va_list         list;
    char            *p, *r;
    int             e;
 
    if (level <= log_level) { 
        printf("%s ",print_time());
        va_start( list, fmt );
     
        for ( p = fmt ; *p ; ++p )
        {
            if ( *p != '%' )//If simple string
            {
                putchar( *p );
            }
            else
            {
                switch ( *++p )
                {
                    /* string */
                case 's':
                {
                    r = va_arg( list, char * );
     
                    printf("%s", r);
                    continue;
                }
     
                /* integer */
                case 'd':
                {
                    e = va_arg( list, int );
     
                    printf("%d", e);
                    continue;
                }
     
                default:
                    putchar( *p );
                }
            }
        }
        va_end( list );
        //printf(" [%s][line: %d]\n",filename,line);
    }
}
