#ifndef _COMMON_H_
#define _COMMON_H_

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>

#define STR_DELETE( str ) \
    str[0] = '\0';

#define STR_APPEND( str, ch, i ) \
    while( str[i] != '\0' ) i++; \
    str[i] = ch; str[i+1] = '\0';

#define CALL( fn, val ) \
    val = fn; \
    if( val == -1 ) { \
        printf("error!  %d\n", errno); }

#endif