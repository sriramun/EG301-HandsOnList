#include "../common.h"

// 
// usage: 14.out FILE_SOURCE
// 
int main( int argc, char *argv[] ) {

    if( argc != 2 ) {

        printf("Need one file name as arguments!\n");
        return 1;
    }

    int fd;
    FCALL( open( argv[1], O_RDONLY ), fd );
    
    int res;
    struct stat file_stat;
    FCALL( stat( argv[1], &file_stat ), res );

    if( S_ISBLK( file_stat.st_mode ) )   printf("This is a block file!\n");
    if( S_ISCHR( file_stat.st_mode ) )   printf("This is a character file!\n");
    if( S_ISDIR( file_stat.st_mode ) )   printf("This is a directory!\n");
    if( S_ISFIFO( file_stat.st_mode ) )   printf("This is a FIFO file!\n");
    if( S_ISLNK( file_stat.st_mode ) )   printf("This is a link file!\n");
    if( S_ISREG( file_stat.st_mode ) )   printf("This is a regular file!\n");

    close( fd );

    return 0;
}