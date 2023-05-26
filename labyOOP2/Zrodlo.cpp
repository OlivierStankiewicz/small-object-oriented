#include <iostream>
#include <string>
#include "Book.h"
#include "Library.h"
using namespace std;

int main(){

	Library l1 = {};

	while (1)
	{
		cout << "a - dodanie nowej ksiazki" << endl;
		cout << "l - lista ksiazek" << endl;
		cout << "f - znajdz autora ksiazki o danym tytule" << endl;
		cout << "q - wyjscie z programu" << endl;

		char input;
		cin >> input;

		string autor, tytul, data;
		Book b1 = {};

		switch (input)
		{
		case 'q':
			return 0;
		
		case 'a':
			cout << "Podaj autora: ";
			cin >> autor;
			cout << "Podaj tytul: ";
			cin >> tytul;
			cout << "Podaj date dodania ksiazki: ";
			cin >> data;
			b1 = { autor, tytul, data };
			l1.AddBook(b1);
			break;
		case 'l':
			l1.BookList();
			break;
		case 'f':
			cout << "Podaj tytul ktorego autora szukasz: ";
			cin >> tytul;
			l1.FindBookByNam(tytul);
			break;
		}
	}
}