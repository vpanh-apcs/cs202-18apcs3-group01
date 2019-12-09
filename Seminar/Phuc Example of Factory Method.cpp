//Factory Method
#include<iostream>
using namespace std;
class DessertFactory
{
public:
	DessertFactory() { }
	virtual void print() = 0;
	~DessertFactory() { }
};
class CupCake : public DessertFactory 
{
public:
	CupCake() { }
	void print() { cout << "They are cupcake" << endl; }
	~CupCake() { }
};
class Cookies : public DessertFactory
{
public:
	Cookies() { }
	void print() { cout << "They are cookies" << endl; }
	~Cookies() { }
};

int main()
{
	CupCake* cupcake = new CupCake;
	cupcake->print();
	cout << endl;

	Cookies* cookies = new Cookies;
	cookies->print();
	cout << endl;
	return 0;
}