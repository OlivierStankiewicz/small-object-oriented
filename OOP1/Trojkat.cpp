#include "Trojkat.h"
#include <cmath>
#include <iostream>

using namespace std;

Trojkat::Trojkat(double a, double b, double c)
	: a(a), b(b), c(c)
{
	cout << "Konstruktor Trojkata(" << a << "," << b << "," << c << ")" << endl;
}

double Trojkat::GetA() const {
	return a;
}

double Trojkat::GetB() const {
	return b;
}

double Trojkat::GetC() const {
	return c;
}

void Trojkat::SetA(double a) {
	this->a = a;
}

void Trojkat::SetB(double b) {
	this->b = b;
}

void Trojkat::SetC(double c) {
	this->c = c;
}

double Trojkat::Obwod() {
	return a+b+c;
}

double Trojkat::Pole() {
	float p = Obwod() / 2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}

void Trojkat::Wypisz(std::ostream& out) const {
	out << "Trojkat o wymiarach " << a << " na " << b << " na " << c << endl;
}

Trojkat::~Trojkat() {
	cout << "Trojkat " << a << " na " << b << " na " << " jest usuwany" << endl;
}