#include "../common.h"

int main() {

    int fd;

    // behaviour of O_EXCL flag is undefined without O_CREAT
    CALL( open( "./temp", O_RDWR | O_EXCL ), fd );
}