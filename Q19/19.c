#include "../common.h"

int main() {

    clock_t x, y;

    FCALL( clock(), x );

        getpid();

    FCALL( clock(), y );

    double total = (double)( y - x )/CLOCKS_PER_SEC;

    printf( "Executed getpid() in %lf seconds!\n", total );

    return 0;
}