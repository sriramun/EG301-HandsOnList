#ifndef _COMMON_H_
#define _COMMON_H_

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>

#define PRINT( msg ) \
    write( STDOUT_FILENO, msg, sizeof( msg ) - 1 );

#define CALL( fn, val ) \
    val = fn; \
    if( val == -1 ) { \
        printf("error!  %d\n", errno); }

#endif