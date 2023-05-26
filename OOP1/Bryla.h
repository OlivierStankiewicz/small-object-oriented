#pragma once
#include <iostream>

class Bryla {
protected:
	virtual void Wypisz(std::ostream& out) const = 0;
	friend std::ostream& operator<<(std::ostream& os, const Bryla& figura);

public:
	virtual double PoleB() = 0;
	virtual double PoleC() = 0;
	virtual ~Bryla();
};