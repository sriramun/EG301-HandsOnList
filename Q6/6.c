#include "../common.h"

int main() {

    char inputChar;

    while( read( STDIN_FILENO, &inputChar, 1 ) > 0 ) {

        write( STDOUT_FILENO, &inputChar, 1 );

    }

    return 0;
}