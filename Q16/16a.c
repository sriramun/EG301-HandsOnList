#include "../common.h"

int main() {

    struct flock lock;

    int fd;
    FCALL( open( "./temp", O_WRONLY ), fd );

    lock.l_len = 0;
    lock.l_pid = getpid();
    lock.l_start = 0;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;

    fcntl( fd, F_SETLK, &lock );
    printf("Write locked this file! Press any key to continue!\n");

    getchar();

    lock.l_type = F_UNLCK;
    fcntl( fd, F_SETLK, &lock );
    printf("Unlocked!");

    return 0;
}