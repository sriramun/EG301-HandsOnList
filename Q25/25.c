#include "../common.h"

int MultiFork( int n ) {

    pid_t childPID;
    FCALL( fork(), childPID );

    if( !n ) return 0;

    if( childPID ) {

        int wstatus;
        waitpid( childPID, &wstatus, 0 );

        return MultiFork( n-1 );

    } else {

        printf( "Child process ID: %d\n", getpid() );
    }

    return -1;
}   

int main() {

    MultiFork(3);

    return 0;
}
// 
// ps x | grep 25.out
// to verify processes
// 