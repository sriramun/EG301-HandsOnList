#include "../common.h"

int main() {

    int res;

    char *args[] = { "/bin/ls", "-l", NULL };

    FCALL( execv( args[0], args ), res );

    return 0;
}