#include "../common.h"

int main() {

    struct flock lock;

    int fd;
    FCALL( open( "./temp", O_WRONLY ), fd );

    lock.l_len = 0;
    lock.l_pid = getpid();
    lock.l_start = 0;
    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;

    fcntl( fd, F_SETLK, &lock );
    printf("Read locked this file! Press any key to continue!\n");

    getchar();

    lock.l_type = F_UNLCK;
    fcntl( fd, F_SETLK, &lock );
    printf("Unlocked!");

    return 0;
}