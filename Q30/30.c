#include "../common.h"

int CreateDaemon() {

    pid_t child1;
    FCALL( fork(), child1 );

    if( child1 ) {

        exit(0);
    } 
    
    int res;
    FCALL( setsid(), res );

    pid_t child2;
    FCALL( fork(), child2 );

    if( child2 ) {

        exit(0);
    }

    chdir("/");
    umask(0);

    int x;
    for( x = sysconf(_SC_OPEN_MAX); x >= 0; x-- ) {

        close( x );
    }

    return 0;
}

int main() {

    CreateDaemon();

    timer_t tid;
    struct sigevent sev;
    struct itimerspec its;
    long long freq_ns;

    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = SIGRTMIN;
    sev.sigev_value.sival_ptr = &tid;

    int res;
    FCALL( timer_create( CLOCK_REALTIME, &sev, &tid ), res );

    its.it_value.tv_sec = 100 / 1000000000;
    its.it_value.tv_nsec = 100 % 1000000000;
    its.it_interval.tv_sec = its.it_value.tv_sec;
    its.it_interval.tv_nsec = its.it_value.tv_nsec;

    FCALL( timer_settime( tid, 0, &its, NULL ), res );

    while( 1 ) {

        if( timer_gettime( tid, &its ) > 100 ) {

            printf( "ok!\n" );
            break;
        }

        sleep(20);
    }

    timer_delete( tid );

    return 0;
}