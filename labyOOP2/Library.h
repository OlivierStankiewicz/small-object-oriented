#pragma once
#include "Book.h"
#include <initializer_list>
using namespace std;

class Library {
	size_t size;
	Book* array = new Book[size];
public:
	Library();
	Library(size_t size);
	Library(initializer_list<Book> list);
	Library(const Library& orig);
	Library(Library&& orig);
	Library& operator=(const Library& right);
	Library& operator=(Library&& right);
	Book& operator[](size_t index);
	const Book& operator[](size_t index) const;
	size_t GetSize() const { return size; }
	~Library();
	friend ostream& operator<<(ostream& out, const Library& library);
	friend void SwapBooksInLibrary(Library& l1, Library& l2);

	void AddBook(const Book& book);
	void BookList();
	void FindBookByNam(const string& title) const;
};