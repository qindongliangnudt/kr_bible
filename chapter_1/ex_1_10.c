#include <stdio.h>
#include <stdlib.h>

int main( int argc, char* argv[])
{
    int c;
    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        perror("File opening fail");
        return EXIT_FAILURE;
    }
    while ((c = fgetc(fp)) != EOF) {
        if (c == '\t') {
            putchar('\\');
            putchar('t');
        }
        else if (c == '\\') {
            putchar('\\');
            putchar('\\');
        }
        else if (c == '\b') {
            putchar('\\');
            putchar('b');
        }
        else
            putchar(c);
    }
    printf("%d\n", c);
    if (ferror(fp))
        puts("I/O error when reading");
    else if (feof(fp))
        puts("End of file reached successfully");

    fclose(fp);
    return 0;
}
