#include "../common.h"

// 
// write lock, increment, print
// 
int main() {

    struct flock lock;

    int fd;
    FCALL( open( "./temp", O_RDWR ), fd );

    lock.l_len = 0;
    lock.l_pid = getpid();
    lock.l_start = 0;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;

    fcntl( fd, F_SETLK, &lock );

    int ticketNumber;
    read( fd, &ticketNumber, sizeof ticketNumber );

    ticketNumber++;
    printf( "Ticket number: %d\n", ticketNumber );

    lock.l_type = F_UNLCK;
    fcntl( fd, F_SETLK, &lock );
    
    return 0;
}