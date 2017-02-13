#include <stdio.h>

/* counting characters */

int main( int argc, char* argv[])
{
    int c, nc;
    nc = 0;
    c = getchar();
    while (c != EOF) {
        ++nc;
        c = getchar();
    }
    printf("%d\n", nc);
    return 0;
}
