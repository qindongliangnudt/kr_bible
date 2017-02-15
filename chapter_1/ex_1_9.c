#include <stdio.h>
#include <stdlib.h>

#define YES 1
#define NO  0

int main( int argc, char* argv[])
{
    int c, state;
    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        perror("File opening failure");
        return EXIT_FAILURE;
    }
    state = YES;
    while ((c = fgetc(fp)) != EOF) {
        if (c != ' ') {
            putchar(c);
            state = YES;
        }
        else if (state == YES) {
            putchar(c);
            putchar('\\');
            putchar('b');
            putchar(c);
            state = NO;
        }
        else 
            ;
    } 
    printf("%d\n", c);
    if (ferror(fp))
        puts("I/O error when reading");
    else if (feof(fp))
        puts("End of file reached successfully");

    fclose(fp);
    return 0;
}
