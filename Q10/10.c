#include "../common.h"

int main() {

    int fd;
    FCALL( open( "./temp", O_RDWR ), fd );

    write( fd, "abcdefghij", 10 );

    int res;
    CALL( lseek( fd, 10, SEEK_CUR ), res );

    printf( "Return value of lseek: %d\n", res );

    write( fd, "klmnopqrst", 10 );

    close( fd );
}