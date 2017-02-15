#include <stdio.h>
#include <stdlib.h>

/* count blanks, tabs and newlines */

int main( int argc, char* argv[])
{
    int c, nb, nt, nl;
    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        perror("File opening failure");
        return EXIT_FAILURE;
    }
    nb = nt = nl = 0;
    while ((c = fgetc(fp)) != EOF) {
        if (c == ' ')
            nb += 1;
        else if (c == '\t')
            nt += 1;
        else if (c == '\n')
            nl += 1;
        putchar(c);
    }
    printf("%d\n%d\n%d\n%d\n", nb, nt, nl, c);
    
    if (ferror(fp))
        puts("I/O error when reading");
    else if (feof(fP))
        puts("End of file reached successfully");
    fclose(fp);
    return 0;
}
