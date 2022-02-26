#include "../common.h"

int main() {

    int fd;
    CALL( creat( "./temp1", S_IRWXU ), fd );
    CALL( creat( "./temp2", S_IRWXU ), fd );
    CALL( creat( "./temp3", S_IRWXU ), fd );
    CALL( creat( "./temp4", S_IRWXU ), fd );
    CALL( creat( "./temp5", S_IRWXU ), fd );

    while( 1 ) {

        sleep(10);

    }

    return 0;
}

// ./5.out &