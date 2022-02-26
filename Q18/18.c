#include "18.h"

struct Sample {

    int id;
    int power;
};


int CreateRecord( struct Sample sample, int fd ) {

    WriteLock( fd );
    ReadLock( fd );

    int res;
    CALL( write( fd, &sample, sizeof( struct Sample ) ) , res );

    WriteUnlock( fd );
    ReadUnlock( fd );
}

int main() {

    int fd;
    FCALL( open( "./temp", O_RDWR ), fd );

    struct Sample s1 = { 1, 3}, s2 = {5, 10}, s3 = {19, 20}, s4;

    CreateRecord( s1, fd );
    CreateRecord( s2, fd );
    CreateRecord( s3, fd );

    // lseek( fd, 0, SEEK_SET);

    // read( fd, &s4, sizeof( struct Sample ) );
    // printf("%d\n", s4.id);

    close( fd );

    return 0;
}   