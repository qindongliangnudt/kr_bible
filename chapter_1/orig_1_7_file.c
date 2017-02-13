#include <stdio.h>
#include <stdlib.h>

/* count characterst */

int main(int argc, char* argv[])
{
    int c, nc;
    FILE* fp = fopen("aa.txt", "r");
    if (!fp) {
        perror("File opening failed");
        return EXIT_FAILURE;
    } 
    nc = 0;
    while ((c = fgetc(fp)) != EOF) {
        nc = nc + 1;
        printf("%d ", c);
        if (c == '\n')
            printf("\n");
    }
    printf("%d\n%d\n", c, nc);

    if (ferror(fp))

        puts("I/O error when reading");
    else if (feof(fp))
        puts("End of file reached successfully");

    fclose(fp);
    return 0;
}
