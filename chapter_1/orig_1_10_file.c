#include <stdio.h>
#include <stdlib.h>

/* count digits, white space, others */

int main( int argc, char* argv[])
{
    int c;
    int ndigit[10];
    int nwhite, nothers;

    int i;
    for (i = 0; i < 10; i++) {
        ndigit[i] = 0;
    }
    nwhite = 0;
    nothers = 0;
    
    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        perror("File opening fail");
        return EXIT_FAILURE;
    }
    while ((c = fgetc(fp)) != EOF) {
        if (c >= '0' && c <= '9') {
            ndigit[c-'0'] += 1;
        }
        else if (c == ' ' || c == '\t' || c == '\n') {
            nwhite += 1;
        }
        else
            nothers += 1;
    }
    printf("%d\n", c);

    printf("digits:\n");

    for ( i = 0; i < 10; i++ ) {
        printf(" %d", ndigit[i]);
    }
    printf("\nwhite space: %d\nothers: %d\n", nwhite, nothers);

    if (ferror(fp)) {
        puts("I/O error when reading"); 
    }
    else if (feof(fp)) {
        puts("End of file reached successfully");
    }
    fclose(fp);

    return 0;
}
