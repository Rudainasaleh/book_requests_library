
/* SCOURCE FILE FOR THE OTHER FUNCTIONS */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TITLE_LEN 100
#define NAME_LEN 30
#define ROOM_LEN 20



#include "book.h"           // include the header to run the other functions file
#include "readline.h"       // include the header for readline function



 /*
add_to_end(struct book *list)

a function that asks the user t enter the:
    1. book title,  2, auther first name  3, auther last name,  4. class room 
 #if the book already in the list print a message that says its exists and exit the fun
 #if the book doesnt exists in the list then ask the user to enter a price for the book
    and store the data and add it to thelist  
 */

struct book *add_to_end(struct book *list){

    //add code

    struct book *prev_book = NULL, *end = list;
    struct book *new_book = NULL;

    new_book = malloc(1 * sizeof(struct book)); 
    if (new_book == NULL) {  // make sure that here is still a memory in allocate
        printf("Error: malloc failed in add_to_list\n"); 
        exit(EXIT_FAILURE);
    }
    
    printf("Enter the Book's title: ");    // Ask the user to enter the title,
    read_line(new_book->title,TITLE_LEN);  // read the input
    printf("Enter the Author's first name: "); // Ask the user to enter the author first name
    read_line(new_book->first,NAME_LEN);    // read the input
    printf("Enter the Author's last name: ");  // Ask the user to enter the author last name
    read_line(new_book->last,NAME_LEN); // read the input
    printf("Enter Classroom: ");              // Ask the user to enter classroom
    read_line(new_book->classroom,ROOM_LEN); // read the input
    new_book->next = NULL; // go for the next book

    
    // add the book yo the list
    if (!list) {
        // if the list is empty 
        printf("Enter the price of the book: ");
        scanf("%lf", &new_book->price);
        return new_book;
    }
    // if the list is not empty 
    while (end != NULL) { // cheack is the book is already there by comparing it
        if (!strncmp(new_book->title, end->title, TITLE_LEN + 1) &&
            !strncmp(new_book->first, end->first, NAME_LEN + 1) &&
            !strncmp(new_book->first, end->first, NAME_LEN + 1)) {
                printf("Book is already exists\n");  // if there is a book with the same title, author, classrom 
                free(new_book);
                return list;
        } else { // if nott we add it to the end
            prev_book = end;
            end = end->next;
        }
    }
    // if there is no book does not exists
    printf("Enter the price of the book: "); // ask the user to enter the price for it
    scanf("%lf", &new_book->price);
    prev_book->next = new_book; // the new book go next to the end of the linked list
    return list; // return to the list
}


/* 
search(struct book *list)
a function that search in the list by the book title and asks the user to enter it
find all the books with the entered title 
print: title, auther name, classrom, and price if its found
if not found: print a message that the book with the title didnt found
*/
void search(struct book *list)
{

    // add code
    char search_title[TITLE_LEN+1]; // string for the search input 
    struct book *p;
    printf("\nEnter title book: ");
    read_line(search_title, TITLE_LEN); // read the input
    /* a for loop that goes over all the list and search for the same title name 
        and stops when p == NULL */ 
    for (p = list; p != NULL; p = p->next) 
        // if statent  to compare the input title with the title in the lists
        if (!strncmp(search_title, p->title, TITLE_LEN + 1)){
            // if found it print the book name
            printf("%-18s       %s %-7s        %.2f        %s\n", p->title, p->first, p->last, p->price, p->classroom);
           
        }
        else
            // if not found print a message that didnt found
            printf("book dont found\n");

    return; // return empty 


}

/*
print_list(struct book *list)

a function that prints all books in the list:
print order:
  1. title (string)
  2. aouther first and last name (string)
  3. price (double)
  4. classroom (string)
*/
void print_list(struct book *list){

    //add code

    // print all lists 
    printf("Book Title              Auther Name          price       Classroom\n");
    struct book *p;
    // a for loop that make sure it goes over all the books and stop in NULL
	for(p= list; p!=NULL; p = p->next)
        // print: title, authors first and last name, price, and classroom 
		printf("%-18s          %s %-7s       %.2f      %s\n", p->title, p->first, p->last, p->price, p->classroom);
	printf("\n");

}

/*
clear_list(struct book *list)

a function that when the user exit the program it make
all the memory allocated in the linked list dellocated

*/

void clear_list(struct book *list)
{

    //add code
    struct book *p;
    // a while loop that free the list and go to the next till its empty 
    while(list != NULL)
    {
        p = list;
        list = list->next;
        if( p!= NULL)
            free(p);
    }



}