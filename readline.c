
/* SCOURCE FILE FOR READLINE FUNCTION */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TITLE_LEN 100
#define NAME_LEN 30
#define ROOM_LEN 20

int read_line(char str[], int n)
{
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;
  str[i++] = ch;
  while ((ch = getchar()) != '\n') {
    if (i < n)
      str[i++] = ch;

   }
   str[i] = '\0';
   return i;
}