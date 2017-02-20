/* This is the first program exercise where the spec isn't entirely
 * clear. The spec says, 'Revise the main routine', but the true
 * length of an input line can only be determined by modifying
 * getline. So that's what we'll do. getline will now return the
 * actual length of the line rather than the number of characters
 * read into the array passed to it.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000 /* maximum input line size */

int mgetline(char line[], int maxline, FILE* fp);
void mcopy(char to[], char from[]);

/* print longest input line */
int main(int argc, char* argv[])
{
  int len;               /* current line length */
  int max;               /* maximum length seen so far */
  char line[MAXLINE];    /* current input line */
  char longest[MAXLINE]; /* longest line saved here */

  FILE* fp = fopen(argv[1], "r");
  if (!fp) {
    perror("File opening failed");
    return EXIT_FAILURE;
  }

  max = 0;

  while((len = mgetline(line, MAXLINE, fp)) > 0)
  {
    printf("%d: %s", len, line);

    if(len > max)
    {
      max = len;
      mcopy(longest, line);
    }
  }
  if(max > 0)
  {
    printf("Longest is %d characters:\n%s", max, longest);
  }
  printf("\n");

  if (ferror(fp)) {
    puts("I/O reading error");
  }
  else if (feof(fp)) {
    puts("End of file reached successfully");
  }

  fclose(fp);
  return 0;
}

/* mgetline: read a line into s, return length */
int mgetline(char s[], int lim, FILE* fp)
{
  int c, i, j;

  for(i = 0, j = 0; (c = fgetc(fp))!=EOF && c != '\n'; ++i)
  {
    if(i < lim - 1)
    {
      s[j++] = c;
    }
  }
  if(c == '\n')
  {
    if(i <= lim - 1)
    {
      s[j++] = c;
    }
    ++i;
  }
  s[j] = '\0';
  return i;
}

/* copy: copy 'from' into 'to'; assume 'to' is big enough */
void mcopy(char to[], char from[])
{
  int i;

  i = 0;
  while((to[i] = from[i]) != '\0')
  {
    ++i;
  }
}
