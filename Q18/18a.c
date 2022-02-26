#include "18.h"

int WriteLock( int fd ) {

    struct flock lock;

    lock.l_len = 0;
    lock.l_pid = getpid();
    lock.l_start = 0;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;

    fcntl( fd, F_SETLK, &lock );

    return 0;
}

int WriteUnlock( int fd ) {

    struct flock lock;

    lock.l_len = 0;
    lock.l_pid = getpid();
    lock.l_start = 0;
    lock.l_type = F_UNLCK;
    lock.l_whence = SEEK_SET;

    fcntl( fd, F_SETLK, &lock );

    return 0;
}