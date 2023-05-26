#include "Kolo.h"
#include <iostream>
#define PI 3.14

using namespace std;

Kolo::Kolo(double r)
	: r(r)
{
	cout << "Konstruktor Kola(" << r << ")" << endl;
}

double Kolo::GetR() const {
	return r;
}

void Kolo::SetR(double r) {
	this->r = r;
}

double Kolo::Obwod() {
	return 2*PI*r;
}

double Kolo::Pole() {
	return PI*r*r;
}

void Kolo::Wypisz(std::ostream& out) const {
	out << "Kolo o promieniu" << r << endl;
}

Kolo::~Kolo() {
	cout << "Kolo o promieniu" << r << " jest usuwane" << endl;
}