#include "../common.h"

int main() {

    int fd;
    CALL( creat( "./temp", S_IRWXU ), fd );

    printf( "File Descriptor: %d\n", fd );

    return 0;
}