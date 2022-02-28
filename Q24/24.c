#include "../common.h"

int main() {

    pid_t childPID;
    FCALL( fork(), childPID );

    if( childPID ) {

        exit(0);

    } else {

        sleep(100);
    }

    return 0;
}
