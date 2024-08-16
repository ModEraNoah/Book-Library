#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
	char firstname[18];
	char lastname[20];
	int id;
} Author;

typedef struct
{
	char name[20];
	double priceFactor;
} Publisher;

typedef struct
{
	Author author;
	char isbn[14];
	Publisher publisher;
} Book;

typedef struct
{
	char *name;
	Book *books;
} Bookshelf;

Author createAuthor(char first[], char last[])
{
	Author author;
	strcpy(author.firstname, first);
	strcpy(author.lastname, last);

	return author;
}

Publisher createPublisher(char name[], double factor)
{
	Publisher publisher;
	strcpy(publisher.name, name);
	publisher.priceFactor = factor;

	return publisher;
}

Book createBook(Author author, char isbn[], Publisher publisher)
{
	Book book;
	book.author = author;
	strcpy(book.isbn, isbn);
	book.publisher = publisher;

	return book;
}

static int bookCounter = 0;
Bookshelf createBookshelf(char name[], Book *books)
{
	Bookshelf *shelf = malloc(sizeof(Bookshelf));
	// strcpy(shelf.name, name);
	shelf->name = name;
	shelf->books = books;
	// Book *b = malloc(sizeof(Book) * 5);
	// shelf.books = books;

	bookCounter++;
	return *shelf;
}

int main(void)
{
	// Author uncleBob;// = {"Robert", "Martin"};
	// strcpy(uncleBob.firstname, "Robert");
	// strcpy(uncleBob.lastname, "Martin");
	Author uncleBob = createAuthor("Robert", "Martin");

	// Publisher oreilly;// = {name = "O'Reilly", priceFactor = 2.0};
	// strcpy(oreilly.name, "O'Reilly");
	// oreilly.priceFactor = 2.0;
	Publisher oreilly = createPublisher("O'Reilly", 2.0);

	// Book cleanCode; // = {uncleBob, "123-56789-01", oreilly};
	// cleanCode.author = uncleBob;
	// strcpy(cleanCode.isbn, "123-56789-01");
	// cleanCode.publisher = oreilly;
	Book cleanCode = createBook(uncleBob, "123-56789-01", oreilly);

	printf("uncleBob's first: %s and last: %s\n", uncleBob.firstname, uncleBob.lastname);
	printf("oreilly's name: %s and factor: %lf\n", oreilly.name, oreilly.priceFactor);
	printf("cleanCode's author lastname: %s and isbn: %s and publisher name: %s\n", cleanCode.author.lastname, cleanCode.isbn, cleanCode.publisher.name);

	printf("\nCreating a Bookshelf\n");
	Bookshelf shelf = createBookshelf("specificBookshelfName", &cleanCode);
	*(shelf.books + 1)  = createBook(uncleBob, "321-56789-01", oreilly);
	bookCounter++;

	printf("Bookshelf name: %s\n", shelf.name);
	printf("size of booskhelf.books: %d\n", (sizeof(*shelf.books)/sizeof(Book)));
	printf("book #1: %s\n", (*shelf.books).isbn);
	printf("book #2: %s\n", (*(shelf.books + 1)).isbn);
	printf("book #3: %s\n", (*(shelf.books + 2)).isbn);

	printf("loop\n");
	int i = 0;
	while (i < bookCounter)
	{
		printf("book #%d: %s\n", i, (shelf.books + i)->isbn);
		i++;
	}

	Bookshelf bookShelfFromArray = {name : "someName"};
	Book otherBook = createBook(uncleBob, "321-56789-01", oreilly);
	Book bookArray[2] = {cleanCode, cleanCode};
	printf("lengt of bookArray: %d\n", (sizeof(bookArray)/sizeof(Book)));

	bookArray[2] = otherBook;

	printf("lengt of bookArray after adding a 3rd book: %d\n", (sizeof(bookArray)/sizeof(Book)));
	printf("bookArray at index 0 with array-notation: %s\n", bookArray[0].isbn);
	printf("bookArray at index 1 with array-notation: %s\n", bookArray[1].isbn);
	printf("bookArray at index 2 with array-notation: %s\n", bookArray[2].isbn);

	printf("bookArray at index 2 with pointer-notation: %s\n", (*(bookArray + 2)).isbn);
	printf("bookArray at index 2 with pointer-arrow-notation: %s\n", (bookArray + 2)->isbn);

	return 0;
}
