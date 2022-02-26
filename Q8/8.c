#include "../common.h"

// 
// usage: 8.out FILE_SOURCE 
// 
int main( int argc, char *argv[] ) {

    if( argc != 2 ) {

        printf("Need one file name as arguments!\n");
        return 1;
    }

    int fd1;

    CALL( open( argv[1], O_RDONLY ) , fd1 );
    
    char s[1000] = "", ch;
    int i = 0;

    while( read( fd1, &ch, 1 ) > 0 ) {

        if( ch == '\n' ) {

            STR_APPEND( s, '\n', i );
            
            write( STDOUT_FILENO, s, i+1 );

            STR_DELETE( s );
            i = 0;

        } else {

            STR_APPEND( s, ch, i );
        }
    }
    write( STDOUT_FILENO, s, i+1 );


    int res;
    CALL( close( fd1 ), res );
    
    return 0;
}