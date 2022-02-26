#include "../common.h"

int main() {

    int fd;
    FCALL( open( "./temp", O_RDWR ), fd );

    int res;
    CALL( fcntl( fd, F_GETFL ), res );

    switch ( res ) {

        case 32768:
            printf("O_RDONLY\n");

        case 32769:
            printf("O_WRONLY\n");

        case 32770:
            printf("O_RDRW\n");
        
        default:
            break;
    }
}