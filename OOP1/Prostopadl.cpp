#include "Prostopadl.h"

#include <iostream>

using namespace std;

Prostopadl::Prostopadl(double a, double b, double h)
	: a(a), b(b), h(h)
{
	cout << "Konstruktor prostopadloscianu(" << a << "," << b << "," << h << ")" << endl;
	
	ab = new Prostokat(a, b);
	ah = new Prostokat(a, h);
	bh = new Prostokat(b, h);
}

Prostopadl::Prostopadl(double a)
	: a(a), b(a), h(a)
{
	cout << "Konstruktor szescianu(" << a << "," << b << "," << h << ")" << endl;

	ab = new Prostokat(a, b);
	ah = new Prostokat(a, h);
	bh = new Prostokat(b, h);
}

Prostopadl::Prostopadl()
	: a(1), b(1), h(1)
{
	cout << "Konstruktor szescianu(" << a << "," << b << "," << h << ")" << endl;

	ab = new Prostokat(a, b);
	ah = new Prostokat(a, h);
	bh = new Prostokat(b, h);
}

double Prostopadl::GetA() const {
	return a;
}

double Prostopadl::GetB() const {
	return b;
}

double Prostopadl::GetH() const {
	return h;
}

void Prostopadl::SetA(double a) {
	this->a = a;
}

void Prostopadl::SetB(double b) {
	this->b = b;
}

void Prostopadl::SetH(double h) {
	this->h = h;
}

double Prostopadl::PoleB() {
	return 2 * (ah->Pole()) + 2 * (bh->Pole());
}

double Prostopadl::PoleC() {
	return PoleB() + 2*(ab->Pole());
}

void Prostopadl::Wypisz(std::ostream& out) const {
	out << "Prostopadloscian o wymiarach " << a << " na " << b << " na " << h << endl;
}

Prostopadl::~Prostopadl() {
	cout << "Prostopadloscian " << a << " na " << b << " na " << h << " jest usuwany" << endl;
	delete ab;
	delete ah;
	delete bh;
}