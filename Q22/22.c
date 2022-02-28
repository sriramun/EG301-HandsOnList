#include "../common.h"

int main() {

    pid_t childPID;
    FCALL( fork(), childPID );

    int fd, res;
    FCALL( open( "./temp", O_WRONLY | O_APPEND ), fd );

    if( childPID ) {

        CALL( write( fd, "writing from the parent process!\n", sizeof( "writing from the parent process!\n" ) - 1 ), res );

        int wstatus;
        waitpid( childPID, &wstatus, 0 );

    } else {

        CALL( write( fd, "writing from the child process!\n", sizeof( "writing from the child process!\n" ) - 1 ), res );
    }

    return 0;
}