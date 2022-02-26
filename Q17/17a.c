#include "../common.h"

// 
// open file, store ticket, close
// 
int main() {

    int fd;
    FCALL( open( "./temp", O_WRONLY ), fd );

    int ticketNumber = 33;

    write( fd, &ticketNumber, sizeof ticketNumber );

    close( fd );

    return 0;
}