/* https://github.com/adamesque/k-r/blob/master/ex1-16.c */
/* ex-16 description:
   Revise the main routine of the longest-line program
   so it will correctly print the length of arbitrarily
   long input lines, and as much as possible of the text.

   The tricky part is ONLY modifying main() and not getline() */

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 100

int mgetline(char line[], int lim, FILE* fp);
void mycopy(char to[], char from[]);

int main(int argc, char* argv[])
{
    int len, prevlen;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];
    char temp[MAXLINE];
    
    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        perror("File opening failed");
        return EXIT_FAILURE;
    }

    max = prevlen = 0;
    while ( (len = mgetline(line, MAXLINE, fp)) > 0 ) {
        if (prevlen + len > max) {
            max = prevlen + len;
            if (!prevlen)
                mycopy(longest, line);
            else
                mycopy(longest, temp);
        }
        
        if (line[len-1] != '\n') {
            if (!prevlen)
                mycopy(temp, line);
            prevlen = prevlen + len;
        }
        else
            prevlen = 0;
    }
    if (max > 0) {
        printf("%d\n", max);
        printf("%s", longest);
        if (max > MAXLINE)
            printf("...");
    }

    if (ferror(fp)) {
        puts("I/O reading error");
    }
    else if (feof(fp)) {
        printf("\n");
        puts("End of file reached successfully");
    }
    fclose(fp);
    
    return 0;
}
/* getaline: read a line into s, return length */
int mgetline(char s[], int lim, FILE* fp)
{
    int c, i;

    for (i=0; i<lim-1 && (c=fgetc(fp))!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void mycopy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
