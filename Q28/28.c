#include "../common.h"

int main() {

    int minP, maxP;

    FCALL( sched_get_priority_min(SCHED_FIFO), minP ); 
    FCALL( sched_get_priority_max(SCHED_FIFO), maxP );

    printf( "Max priority: %d\n Min priority: %d\n", maxP, minP );

    return 0;
}