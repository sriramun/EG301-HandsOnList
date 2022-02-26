#include "../common.h"

int main() {

    int res;

    const char target[] = "./temp";
    const char softCopy[] = "./temp_c_soft";
    const char hardCopy[] = "./temp_c_hard";
    const char pipeName[] = "temp_c_pipe";

    // soft link
    CALL( symlink( target, softCopy ), res );

    // hard link
    CALL( link( target, hardCopy ), res );

    // fifo
    CALL( mkfifo( pipeName, 0666 ), res ); 

    return 0;
}