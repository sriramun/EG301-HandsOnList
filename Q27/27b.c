#include "../common.h"

int main() {

    int res;

    char *path = "/bin/ls";

    FCALL( execlp( path, "-R", "-l", NULL ), res );

    return 0;
}