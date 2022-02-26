#include "../common.h"

int main() {

    fd_set readFds;

    FD_ZERO( &readFds );
    FD_SET( STDIN_FILENO, &readFds );

    struct timeval timeout;

    timeout.tv_sec = 3;
    timeout.tv_usec = 0;

    int res;
    FCALL( select( 1, &readFds, NULL, NULL, &timeout ), res );

    if( res == 0 ) {

        printf("No input detected!\n");
    } else {

        printf("Data available!\n");
    }
}