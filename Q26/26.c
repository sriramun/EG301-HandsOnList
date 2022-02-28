#include "../common.h"

int main() {

    int res;

    char *path = "/bin/ls";
    char *args[] = { "ls", "-l", NULL };

    FCALL( execv( path, args ), res );

    return 0;
}