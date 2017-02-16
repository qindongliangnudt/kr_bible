#include <stdio.h>
#include <stdlib.h>

/* count digits, white space, others */

void printStar(void) {
    putchar('*');
}

int main( int argc, char* argv[])
{
    int c;
    int ndigit[10];
    int nalpha[26];
    int nwhite, nothers;

    int i;
    for (i = 0; i < 10; i++) {
        ndigit[i] = 0;
    }
    for (i = 0; i < 26; ++i) {
        nalpha[i] = 0;
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
        else if (c >= 'a' && c <= 'z' ) {
            nalpha[c-'a'] += 1;
        }
        else if (c >= 'A' && c <= 'Z' ) {
            nalpha[c-'A'] += 1;
        }
        else if (c == ' ' || c == '\t' || c == '\n') {
            nwhite += 1;
        }
        else
            nothers += 1;
    }
    printf("%d\n", c);
    
    int j;
    for (i = 0; i < 10; ++i) {
        putchar('0'+i);
        putchar('\t');
        putchar('\t');
        j = ndigit[i];
        while (j > 0) {
            printStar();
            j--;
        }
        putchar('\n');
    }

    for (i = 0; i < 26; ++i) {
        putchar('a'+i);
        putchar('\t');
        putchar('\t');
        j = nalpha[i];
        while (j > 0) {
            printStar();
            j--;
        }
        putchar('\n');
    }

    printf("white:");
    putchar('\t');
    putchar('\t');
    j = nwhite;
    while (j > 0) {
        printStar();
        j--;
    }
    putchar('\n');

    printf("others:");
    putchar('\t');
    putchar('\t');
    j = nothers;
    while (j > 0) {
        printStar();
        j--;
    }
    putchar('\n');

    if (ferror(fp)) {
        puts("I/O error when reading"); 
    }
    else if (feof(fp)) {
        puts("End of file reached successfully");
    }
    fclose(fp);

    return 0;
}
