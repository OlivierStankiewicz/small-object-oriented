#include "Book.h"

Book::Book(const string& author, const string& title, const string& date)
{
	this->author = author;
	this->title = title;
	this->date = date;
}

Book::Book(string&& author, string&& title, string&& date)
{
	this->author = author;
	this->title = title;
	this->date = date;
}

Book::Book(const Book& other)
{
	author = other.getAuthor();
	title = other.getTitle();
	date = other.getDate();

}

Book::Book(Book&& other)
{
	author = other.author;
	title = other.title;
	date = other.date;
	other.title = nullptr;
	other.author = nullptr;
	other.date = nullptr;
}

ostream& operator<<(ostream& os, const Book& book) {
	os << "Title: " << book.title << ", Author: " << book.author << ", Date: " << book.date << endl;
	return os;
}

Book& Book::operator=(Book& right)
{
	swap(title, right.title);
	swap(author, right.author);
	swap(date, right.date);
	return *this;
}
Book& Book::operator=(Book && right)
{
	title = move(right.title);
	author = move(right.author);
	date = move(right.date);
	return *this;
}