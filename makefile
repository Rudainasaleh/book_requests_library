

book_requests: book_requests.o book.o readline.o
	gcc -o book_requests book_requests.o book.o readline.o 
readline.o: readline.c readline.h
	gcc -c readline.c
book.o: book.c book.h
	gcc -c book.c
book_requests.o: book_requests.c book.h
	gcc -c book_requests.c
 
