
/* SCOURCE FILE FOR THE MAIN FUNCTION  */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TITLE_LEN 100
#define NAME_LEN 30
#define ROOM_LEN 20

#include "readline.h" // include the header for readline function
#include "book.h"     // include the header to run the other functions file 


/*
the main function askes the user to enter the code for th eoperation that he needs and call the function for it
it repeats again and again until the user enter the code q for clearing the list and exit
 */
int main(void)
{
  char code;

  struct book *book_list = NULL;
  printf("Operation Code: a for adding to the list, s for searching a book"
	  ", p for printing the list; q for quit.\n");
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'a': book_list = add_to_end(book_list);
                break;
      case 's': search(book_list);
                break;
      case 'p': print_list(book_list);
                break;
      case 'q': clear_list(book_list);
		return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}