#include "../common.h"

void GetSchd( int pid ) {

    int s = sched_getscheduler( pid );

    if( s == SCHED_FIFO )
        printf( "FIFO!\n" );

    else if( s == SCHED_RR )
        printf( "Round Robin!\n" );

    else
        printf( "Others!\n" );
}

int main() {

    int pid;
    FCALL( getpid(), pid );

    GetSchd( pid );

    struct sched_param param;
    param.sched_priority = 99;
    sched_setscheduler( pid, SCHED_RR, &param );

    GetSchd( pid );
}