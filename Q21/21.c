#include "../common.h"

int main() {

    pid_t childPID;
    FCALL( fork(), childPID );

    if( childPID ) {

        printf("Parent process ID: %d\n", getpid() );

        int wstatus;
        waitpid( childPID, &wstatus, 0 );

    } else {

        printf("Child process ID: %d\n", getpid() );
    }

    return 0;
}