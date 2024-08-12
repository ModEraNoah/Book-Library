#include<stdio.h>
#include<string.h>

struct Author
{
	char firstname[18];
	char lastname[20];
	int id;
};

typedef struct
{
	char name[20];
	double priceFactor;
} Publisher;

typedef struct
{
	struct Author author;
	char isbn[14];
	Publisher publisher;
} Book;

struct Author createAuthor(char first[], char last[])
{
	struct Author author;
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

Book createBook(struct Author author, char isbn[], Publisher publisher)
{
	Book book;
	book.author = author;
	strcpy(book.isbn, isbn);
	book.publisher = publisher;

	return book;
}

int main(void)
{
	// struct Author uncleBob;// = {"Robert", "Martin"};
	// strcpy(uncleBob.firstname, "Robert");
	// strcpy(uncleBob.lastname, "Martin");
	struct Author uncleBob = createAuthor("Robert", "Martin");

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

	return 0;
}
