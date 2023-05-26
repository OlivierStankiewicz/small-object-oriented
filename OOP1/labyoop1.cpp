#include <iostream>
#include "Prostokat.h"
#include "Trojkat.h"
#include "Kolo.h"
#include "Prostopadl.h"

using namespace std;

void przyklad()
{
	cout << "To jest przykladowa funkcja korzystajaca z mechanizmu overridingu" << endl;
}

void przyklad(string a)
{
	cout << "To jest przykladowa funkcja korzystajaca z mechanizmu overridingu, jednak zostala ona uzupelniona o wiadomosc od wywolujacego ja: " << a << endl;
}

int main()
{
	Prostopadl* p2 = new Prostopadl(2, 4, 6);
	cout << endl;
	cout << *p2;
	cout << "Pole powierzchni bocznej prostopadloscianu: " << p2->PoleB() << endl;
	cout << "Pole powierzchni calkowitej prostopadloscianu: " << p2->PoleC() << endl;
	cout << endl;
	delete p2;
	cout << endl;

	Prostopadl p1(3);
	Bryla* b1 = &p1;
	
	cout << endl;
	cout << *b1;
	cout << "Pole powierzchni bocznej prostopadloscianu: " << b1->PoleB() << endl;
	cout << "Pole powierzchni calkowitej prostopadloscianu: " << b1->PoleC() << endl;
	cout << endl;

	/* 3.1 
	Prostokat p1(5, 4);
	cout << p1;
	cout << "Pole p1: " << p1.Pole() << endl;
	cout << "Obwod p1: " << p1.Obwod() << endl;
	p1.SetA(10);
	p1.SetB(12);
	cout << p1;
	Prostokat* p2 = new Prostokat(2, 4);
	delete p2;
	cout << endl;


	/* 3.2
	FiguraPlaska* t[3];

	Trojkat t1(3, 4, 5);
	Kolo k1(2);

	t[0] = &p1;
	t[1] = &t1;
	t[2] = &k1;

	for (int i = 0; i < 3; i++)
	{
		cout << "Pole: " << t[i]->Pole() <<endl;
		cout << "Obwod: " << t[i]->Obwod() << endl;
	}

	/* 3.3
	przyklad();
	przyklad("witam serdecznie");*/

	return 0;
}