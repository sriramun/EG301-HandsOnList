#include "../common.h"

int main() {

    pid_t childPID;
    FCALL( fork(), childPID );

    if( childPID ) {

        sleep(100);

    } else {

        exit(0);
    }

    return 0;
}

// 
// ps x | grep defunct
// for zombie process info
// 