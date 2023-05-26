#include <initializer_list>
#include <iostream>
class Vector {
	double* array;
	std::size_t size;
public:
	//Parametr typu std::initializer_list pozwoli na uruchomienie
	//konstruktora z dowolna liczba wystapien liczb typu double.
	// Bedzie to wygladalo jak inicjalizacja tablicy. Przyklad:
	//Vector v1({1,2,3,4,5,5.5});
	//lub
	//Vector v1{1,2,3,4,5,5.5};
	//lub
	//Vector v1 = {1,2,3,4,5,5.5};
	//Jest to cecha C++11
	Vector(std::initializer_list<double> initList)
		: size{ initList.size() }, array{ new double[initList.size()] }
	{
		std::size_t i = 0;
		for (double v : initList)
		{
			array[i] = v;
			i++;
		}
	}

	Vector(const Vector& other) //Konstruktor kopiujacy
		: size(other.size), array{ new double[other.size] } {
		//Informacja diagnostyczna
		std::cout << "Vector(const Vector&)" << std::endl;
		for (std::size_t i = 0; i < size; i++)
			array[i] = other.array[i];
	}

	//Implementacja operatora przypisania z wykorzystaniem copy-swap
	Vector& operator=(const Vector& right) {
		//Informacja diagnostyczna
		std::cout << "operator=(const Vector&)" << std::endl;
		Vector tmp = right; //Tworzenie obiektu tymczasowego
		//Zamiana wskaznikow na tablice miejscami
		std::swap(array, tmp.array);
		//Zamiana informacji o wielkosci tablicy
		std::swap(size, tmp.size);
		return *this;
	}

	std::size_t GetSize() const {
		return size;
	}

	const double& operator[](std::size_t i) const {
		return array[i];
	}

	double& operator[](std::size_t i)
	{
		return array[i];
	}

	~Vector()
	{
		//Informacja diagnostyczna
		std::cout << "~Vector()" << std::endl;
		if (array != nullptr)
		{
			std::cout << "Releasing memory " << array << std::endl;
			delete[] array;
		}
	}
};
std::ostream& operator<<(std::ostream& ostr, const Vector& v) {
	ostr << "Vector{";
	for (std::size_t i = 0; i < v.GetSize(); i++)
	{
		if (i > 0)
			ostr << ',';
		ostr << v[i];
	}
	ostr << '}';
	return ostr;
}

void wypisz1(Vector v)
{
	std::cout << v << std::endl;
}
void wypisz2(Vector& v)
{
	std::cout << v << std::endl;
}

Vector podzielPrzez2(const Vector& arg)
{
	std::cout << "podzielPrzez2(const Vector&)" << std::endl;
	Vector result = arg;
	for (std::size_t i = 0; i < result.GetSize(); i++)
	{
		result[i] = result[i] / 2;
	}
	return result;
}

Vector podzielPrzez2(Vector&& arg)
{
	std::cout << "podzielPrzez2(Vector&&)" << std::endl;
	/*
	* Mimo iz arg jest R-referencja, nalezy zastosowac std::move,
	* aby wykorzystac jej wlasciwosci. Bez tego zostanie wywolany
	* konstruktor kopiujacy. Jest to cecha jezyka wymuszajaca na
	* programiscie jawne okreslenie miejsca w ktorym zostaja uzyte
	* specjalne wlasciwosci R-referencji.
	*/
	Vector result = std::move(arg);
	for (std::size_t i = 0; i < result.GetSize(); i++)
	{
		result[i] = result[i] / 2;
	}
	return result;
}

class Envelope
{
	Vector vector;
	friend std::ostream& operator<<(std::ostream&, const Envelope&);
public:
	Envelope(const Vector& vector) :
		vector{ vector } {
		std::cout << "Envelope(const Vector&)" << std::endl;
	}
	Envelope(Vector&& vector) :
		vector{ std::move(vector) } {
		std::cout << "Envelope(Vector&&)" << std::endl;
	}
	Envelope(const Envelope& other) :
		vector{ other.vector } {
		std::cout << "Envelope(const Envelope&)" << std::endl;
	}
	Envelope(Envelope&& other) :
		vector{ std::move(other.vector) } {
		std::cout << "Envelope(Envelope&&)" << std::endl;
	}
	Envelope& operator=(const Envelope& right) {
		std::cout << "operator=(const Envelope&)" << std::endl;
		Envelope tmp(right);
		std::cout << "operator=(const Envelope&) swap poczatek" <<
			std::endl;
		std::swap(vector, tmp.vector);
		std::cout << "operator=(const Envelope&) swap koniec" <<
			std::endl;
		return *this;
	}
	Envelope& operator=(Envelope&& right) {
		std::cout << "operator=(Envelope&&)" << std::endl;
		vector = std::move(right.vector);
		return *this;
	}
	~Envelope() {
		std::cout << "~Envelope()" << std::endl;
	}
};

std::ostream& operator<<(std::ostream& ostr, const Envelope& e)
{
	ostr << "Envelope{vector: " << e.vector << '}';
	return ostr;
}
int main3() {
	std::cout << "Konstruktor z r-referencja" << std::endl;
	Envelope e1{ Vector{1,2,3} };
	std::cout << "e1: " << e1 << std::endl;
	std::cout << "Konstrukor przenoszacy" << std::endl;
	Envelope e2 = std::move(e1);
	std::cout << "e1: " << e1 << std::endl;
	std::cout << "e2: " << e2 << std::endl;
	std::cout << "Przenoszacy operator przypisania" << std::endl;
	e1 = std::move(e2);
	std::cout << "e1: " << e1 << std::endl;
	std::cout << "e2: " << e2 << std::endl;
	std::cout << "operator przypisania copy-swap poczatek" << std::endl;
	e2 = e1;
	std::cout << "operator przypisania copy-swap koniec" << std::endl;
	std::cout << "e1: " << e1 << std::endl;
	std::cout << "e2: " << e2 << std::endl;

	return 0;
}

/*int main() {
	Vector v1 = { 1,2,3 };
	Vector v2 = podzielPrzez2(v1);
	Vector v3 = podzielPrzez2(Vector{ 6,5,4 });
	Vector v4 = { 10,9,8 };
	Vector v5 = podzielPrzez2(std::move(v4));
	std::cout << "v1: " << v1 << std::endl;
	std::cout << "v2: " << v2 << std::endl;
	std::cout << "v3: " << v3 << std::endl;
	std::cout << "v4: " << v4 << std::endl;
	std::cout << "v5: " << v5 << std::endl;
}*/