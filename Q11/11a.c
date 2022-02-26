#include "../common.h"

int main() {

    int fd;
    FCALL( open( "./temp", O_RDWR ), fd );

    int newfd;
    FCALL( dup( fd ), newfd );

    printf("%d %d", fd, newfd);
    
    // please use hexdump to verify appended file descriptors
    write( newfd, &fd, sizeof fd );
    write( newfd, &newfd, sizeof newfd );

}

