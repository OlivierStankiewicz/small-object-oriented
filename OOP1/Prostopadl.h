#include "Bryla.h"
#include "Prostokat.h"

class Prostopadl : public Bryla {
private:
	double a, b, h;
	Prostokat *ab, *ah, *bh;

protected:
	void Wypisz(std::ostream& out) const override;
public:
	Prostopadl(double a, double b, double h);
	Prostopadl(double a);
	Prostopadl();

	double GetA() const;

	void SetA(double a);

	double GetB() const;

	void SetB(double b);

	double GetH() const;

	void SetH(double h);

	double PoleB() override;
	double PoleC() override;

	~Prostopadl() override;
};
