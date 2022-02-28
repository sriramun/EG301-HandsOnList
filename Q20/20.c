#include "../common.h"

int main() {

    int p;
    FCALL( getpriority( 0, 0 ), p );

    printf( "Priority of this process: %d\n", p );    

    int res;
    CALL( nice(-5), res );

    CALL( getpriority( 0, 0 ), p );
    printf( "New priority: %d\n", p );

    return 0;
}