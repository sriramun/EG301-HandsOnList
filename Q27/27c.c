#include "../common.h"

int main() {

    int res;

    char *path = "/bin/ls";

    FCALL( execle( path, "-R", "-l", NULL, NULL ), res );

    return 0;
}