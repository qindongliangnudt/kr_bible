#include <stdio.h>
#include <stdlib.h>

/* copy input to output */

int main(int argc, char* argv[])
{
    int c;
    FILE* fp = fopen("text.txt", "r");
    if (!fp) {
        perror("File opening failed");
        return EXIT_FAILURE;
    } 
    while ((c = fgetc(fp)) != EOF) {
        printf("%d ", c);
        if (c == '\n')
            printf("\n");
    }
    printf("%d\n", c);

    if (ferror(fp))

        puts("I/O error when reading");
    else if (feof(fp))
        puts("End of file reached successfully");

    fclose(fp);
    return 0;
}
