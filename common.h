#ifndef _COMMON_H_
#define _COMMON_H_

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <signal.h>
#include <sched.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define STR_DELETE( str ) \
    str[0] = '\0';

#define STR_APPEND( str, ch, i ) \
    while( str[i++] != '\0' ) ; \
    str[i] = ch; str[i+1] = '\0';

#define CALL( fn, val ) \
    val = fn; \
    if( val == -1 ) { \
        printf("error!  %d\n", errno); }

#define FCALL( fn, val ) \
    val = fn; \
    if( val == -1 ) { \
        printf("error!  %d\n", errno); return 1; }

#endif