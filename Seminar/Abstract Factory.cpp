//Abstract Factory
#include<iostream>
using namespace std;
class TypeofFurniture
{
public:
	virtual void sitOn() = 0;
	virtual void hasLeg() = 0;
};

class Chair : public TypeofFurniture
{
public:
	void sitOn() { cout << "There are 1 sit" << endl; }
	void hasLeg() { cout << "There are 2 legs" << endl; }
};
class Sofa : public TypeofFurniture
{
public:
	void sitOn() { cout << "There are 3 sits" << endl; }
	void hasLeg() { cout << "There are 4 legs" << endl; }
};
class CoffeeTable : public TypeofFurniture
{
public:
	void sitOn() { cout << "There are 6 sits" << endl; }
	void hasLeg() { cout << "There are 4 legs" << endl; }
};

class FurnitureFactory {
public:
	virtual Chair* createChair() = 0;
	virtual Sofa* createSofa() = 0;
	virtual CoffeeTable* createCoffeeTable() = 0;
};
class ArtDecoFurnitureFactory : public FurnitureFactory
{
public:
	Chair* createChair()
	{
		cout << "This is art deco chair" << endl;
		return new Chair;
	}
	Sofa* createSofa()
	{
		cout << "This is art deco sofa" << endl;
		return new Sofa;
	}
	CoffeeTable* createCoffeeTable()
	{
		cout << "This is art deco coffee table" << endl;
		return new CoffeeTable;
	}
};
class ModernFurnitureFactory : public FurnitureFactory
{
public:
	Chair* createChair()
	{
		cout << "This is mordern chair" << endl;
		return new Chair;
	}
	Sofa* createSofa()
	{
		cout << "This is mordern sofa" << endl;
		return new Sofa;
	}
	CoffeeTable* createCoffeeTable()
	{
		cout << "This is mordern coffee table" << endl;
		return new CoffeeTable;
	}
};
class VictorianFurnitureFactory : public FurnitureFactory
{
public:
	Chair* createChair()
	{
		cout << "This is victorian chair" << endl;
		return new Chair;
	}
	Sofa* createSofa()
	{
		cout << "This is victorian sofa" << endl;
		return new Sofa;
	}
	CoffeeTable* createCoffeeTable()
	{
		cout << "This is coffee table" << endl;
		return new CoffeeTable;
	}
};

int main()
{
	cout << "              Art Deco Furniture               " << endl;
	ArtDecoFurnitureFactory* furniture1 = new ArtDecoFurnitureFactory;
	furniture1->createChair()->hasLeg();
	furniture1->createChair()->sitOn();
	cout << endl;
	furniture1->createSofa()->hasLeg();
	furniture1->createSofa()->sitOn();
	cout << endl;
	furniture1->createCoffeeTable()->hasLeg();
	furniture1->createCoffeeTable()->sitOn();
	cout << endl;

	cout << "              Modern Furniture               " << endl;
	ModernFurnitureFactory* furniture2 = new ModernFurnitureFactory;
	furniture2->createChair()->hasLeg();
	furniture2->createChair()->sitOn();
	cout << endl;
	furniture2->createSofa()->hasLeg();
	furniture2->createSofa()->sitOn();
	cout << endl;
	furniture2->createCoffeeTable()->hasLeg();
	furniture2->createCoffeeTable()->sitOn();
	cout << endl;

	cout << "              Victorian Furniture               " << endl;
	VictorianFurnitureFactory* furniture3 = new VictorianFurnitureFactory;
	furniture3->createChair()->hasLeg();
	furniture3->createChair()->sitOn();
	cout << endl;
	furniture3->createSofa()->hasLeg();
	furniture3->createSofa()->sitOn();
	cout << endl;
	furniture3->createCoffeeTable()->hasLeg();
	furniture3->createCoffeeTable()->sitOn();
	cout << endl;
	cout << endl;

	return 0;
}