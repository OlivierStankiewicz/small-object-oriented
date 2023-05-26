#include "Library.h"

Library::Library()
{
	size = 0;
	array = new Book[size];
}

Library::Library(size_t size)
{
	this->size = size;
	array = new Book[size];
}

Library::Library(initializer_list<Book> list)
{
	size = list.size();
	array = new Book[list.size()];
	size_t i = 0;
	for (Book b : list)
	{
		array[i] = b;
		i++;
	}
}

Library::Library(const Library& orig)
{
	size = orig.size;
	array = new Book[orig.size];
	for (size_t i = 0; i < orig.size; i++)
	{
		array[i] = orig.array[i];
	}
}

Library::Library(Library&& orig)
{
	size = orig.size;
	array = exchange(orig.array, nullptr);
	orig.size = 0;
}

Library& Library::operator=(const Library& right)
{
	this->array = right.array;
	this->size = right.size;
	return *this;
}

Library& Library::operator=(Library&& right)
{
	swap(this->size, right.size);
	swap(this->array, right.array);
	return *this;
}

Book& Library::operator[](size_t index)
{
	return array[index];
}

const Book& Library::operator[](size_t index) const
{
	return array[index];
}

Library::~Library() {
	delete[] array;
}

std::ostream& operator<<(ostream& out, const Library& library) {
	out << "[";
	for (size_t i = 0; i < library.size; i++)
	{
		out << library.array[i] << ", ";
	}
	out << "]";
	return out;
}

void Library::AddBook(const Book& book)
{
	Book tmp = book;
	Book* array2 = new Book[++size];
	for (int i = 0; i < size - 1; i++)
		array2[i] = array[i];
	array2[size - 1] = tmp;
	swap(array, array2);
}

void Library::BookList()
{
	for (int i = 0; i < size; i++)
	{
		cout << "Ksiazka o numerze index: " << i << " | Autor: " << array[i].getAuthor() << " | Tytul: " << array[i].getTitle() << " | Dodana do biblioteki: " << array[i].getDate() << endl;
	}
}

void Library::FindBookByNam(const string& title) const
{
	bool found = false;
	for (int i = 0; i < size; i++)
	{
		if (array[i].getTitle() == title)
		{
			cout << "Autorem szukanej ksiazki jest: " << array[i].getAuthor() << endl;
			found = true;
			break;
		}
	}
	if (!found)
		cout << "Nie mamy szukanej przez ciebie ksiazki" << endl;
}
