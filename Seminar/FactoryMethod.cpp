//Factory Method
#include<iostream>
using namespace std;
class PizzaFactory
{
public:
	PizzaFactory() { }
	virtual void printPizza() = 0;
	~PizzaFactory() { }
};

class HamMushroomPizza : public PizzaFactory
{
public:
	HamMushroomPizza() { }
	void printPizza() { cout << "This is ham-mushroom pizza" << endl; }
	~HamMushroomPizza() { }
};
class DeluxePizza : public PizzaFactory
{
public:
	DeluxePizza() { }
	void printPizza() { cout << "This is Deluxe pizza" << endl; }
	~DeluxePizza() { }
};
class HawaiianPizza : public PizzaFactory
{
public:
	HawaiianPizza() { }
	void printPizza() { cout << "This is Hawaiian pizza" << endl; }
	~HawaiianPizza() { }
};

int main()
{
	HamMushroomPizza* hammushroompizza = new HamMushroomPizza;
	hammushroompizza->printPizza();
	cout << endl;

	DeluxePizza* deluxepizza = new DeluxePizza;
	deluxepizza->printPizza();
	cout << endl;

	HawaiianPizza* hawaiianpizza = new HawaiianPizza;
	hawaiianpizza->printPizza();
	cout << endl;
	return 0;
}