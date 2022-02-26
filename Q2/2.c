#include "../common.h"

int main() {

    pid_t currPID;
    CALL( getpid(), currPID );

    printf( "pid: %d\n", currPID );

    while( 1 ) {

        sleep(10);

    }

    return 0;
}