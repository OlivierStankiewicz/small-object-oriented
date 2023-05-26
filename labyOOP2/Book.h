#pragma once
#include <string>
#include <iostream>
using namespace std;

class Book {
	string author, title, date;
public:
	Book() {}; //konstruktor bezparametrowy
	Book(const string& author, const string& title, const string& date); //konstruktor ze stalymi l-referencjami
	Book(string&& author, string&& title, string&& date); //konstruktor z r-referencjami
	Book(const Book& other); //Konstruktor kopiujacy
	Book(Book&& other); //Konstruktor przenoszacy

	string getAuthor() const{ return author; } //getter
	string getTitle() const{ return title; } //getter
	string getDate() const { return date; } //getter

	void setAuthor(const string& newAuthor) { author = newAuthor; } //setter z l-referencja
	void setAuthor(string&& newAuthor) { author = newAuthor; } //setter z r-referencja
	void setTitle(const string& newTitle) { title = newTitle; } //setter z l-referencja
	void setTitle(string&& newTitle) { title = newTitle; } //setter z r-referencja
	void setDate(const string& newDate) { date = newDate; } //setter z l-referencja
	void setDate(string&& newDate) { date = newDate; } //setter z r-referencja

	friend ostream& operator<<(std::ostream& os, const Book& book);

	Book& operator=(Book& right);
	Book& operator=(Book&& right);

	~Book() {};
};
