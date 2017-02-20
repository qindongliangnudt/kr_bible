#include <stdio.h>
#include <stdlib.h>


#define MAXLINE 1000

int mgetline(char line[], int maxlen, FILE* fp);
void mcopy(char to[], char from[]);

/* print the longest input line */

int main( int argc, char* argv[]) 
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        perror("File opening failed");
        return EXIT_FAILURE;
    }
    
    max = 0;
    while ((len = mgetline(line, MAXLINE, fp)) > 0) {
        if (len > max) {
            max = len;
            mcopy(longest, line);
        }
    }
    if (max > 0)
        printf("%s", longest);

    if (ferror(fp)) {
        puts("I/O reading error");
    }
    else if (feof(fp)) {
        puts("End of file reached successfully");
    }
    fclose(fp);
    return 0;
}

int mgetline(char line[], int maxlen, FILE* fp)
{
    int c, i;

    for (i = 0;i < maxlen - 1 && (c = fgetc(fp)) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') 
        line[i++] = c;
    line[i] = '\0';
    line[i-1] = '\n';
    return i;
}

void mcopy( char to[], char from[] )
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
