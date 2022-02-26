#include "../common.h"

// 
// usage: 9.out FILE_SOURCE
// 
int main( int argc, char *argv[] ) {

    if( argc != 2 ) {

        printf("Need one file name as arguments!\n");
        return 1;
    }

    int fd;
    CALL( open( argv[1], O_RDONLY ), fd );
    if( fd < 0 ) return 1;

    int res;
    struct stat file_stat;

    CALL( fstat( fd, &file_stat ), res );
    if( res < 0 ) return 1;

    printf("Inode Number: %ld\nNumber of hard links: %ld \nUID: %d\nGID: %d\nSize: %ld\nBlock Size: %ld\nNumber of blocks: %ld\nTime of last access: %ld\nTime of last modification: %ld\nTime of last change: %ld\n",
        file_stat.st_ino, file_stat.st_nlink, file_stat.st_uid, file_stat.st_gid, file_stat.st_size,
        file_stat.st_blksize, file_stat.st_blocks, file_stat.st_atim.tv_sec, file_stat.st_mtim.tv_sec, file_stat.st_ctim.tv_sec );


    close( fd );
}