#include "../common.h"

// 
// usage: 7.out FILE_SOURCE FILE_TARGET 
// 

int main( int argc, char *argv[] ) {

    if( argc != 3 ) {

        printf("Need two file names as arguments!\n");
    }

    int fd1, fd2;

    CALL( open( argv[1], O_RDONLY ) , fd1 );
    CALL( creat( argv[2], S_IRWXU ) , fd2 );

    char ch;
    while( read( fd1, &ch, 1 ) > 0 ) {

        write( fd2, &ch, 1 );
        
    } 

    int res;
    CALL( close( fd1 ), res );
    CALL( close( fd2 ), res );

    return 0;
}