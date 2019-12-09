//Abstract Factory
#include<iostream>
using namespace std;
class TypeofCake
{
public:
	TypeofCake() { }
	virtual void printCake() = 0;
	~TypeofCake() { }
};
class Souffle : public TypeofCake
{
public:
	Souffle() { };
	void printCake() { }
	~Souffle() { }
};
class Cupcake : public TypeofCake
{
public:
	Cupcake() { };
	void printCake() { }
	~Cupcake() { }
};
class FruitTart : public TypeofCake
{
public:
	FruitTart() { };
	void printCake() { }
	~FruitTart() { }
};
class CakeFactory
{
public:
	CakeFactory() { }
	virtual Souffle* createSouffle() = 0;
	virtual Cupcake* createCupcake() = 0;
	virtual FruitTart* createFruitTart() = 0;
	~CakeFactory() { }
};
class SmallCake : public CakeFactory
{
public:
	Souffle* createSouffle()
	{
		cout << "This is small souffle" << endl;
		return new Souffle;
	}
	Cupcake* createCupcake()
	{
		cout << "This is small cupcake" << endl;
		return new Cupcake;
	}
	FruitTart* createFruitTart()
	{
		cout << "This is small fruit tart" << endl;
		return new FruitTart;
	}
};
class MediumCake : public CakeFactory
{
public:
	Souffle* createSouffle()
	{
		cout << "This is medium souffle" << endl;
		return new Souffle;
	}
	Cupcake* createCupcake()
	{
		cout << "This is medium cupcake" << endl;
		return new Cupcake;
	}
	FruitTart* createFruitTart()
	{
		cout << "This is medium fruit tart" << endl;
		return new FruitTart;
	}
};
class BigCake : public CakeFactory
{
public:
	Souffle* createSouffle()
	{
		cout << "This is big souffle" << endl;
		return new Souffle;
	}
	Cupcake* createCupcake()
	{
		cout << "This is big cupcake" << endl;
		return new Cupcake;
	}
	FruitTart* createFruitTart()
	{
		cout << "This is big fruit tart" << endl;
		return new FruitTart;
	}
};
int main()
{
	cout << "                               Small Cake" << endl;
	SmallCake* smallCake = new SmallCake;
	smallCake->createSouffle();
	smallCake->createCupcake();
	smallCake->createFruitTart();
	cout << endl;

	cout << "                               Medium Cake" << endl;
	MediumCake* mediumCake = new MediumCake;
	mediumCake->createSouffle();
	mediumCake->createCupcake();
	mediumCake->createFruitTart();
	cout << endl;

	cout << "                               Big Cake" << endl;
	BigCake* bigCake = new BigCake;
	bigCake->createSouffle();
	bigCake->createCupcake();
	bigCake->createFruitTart();
	cout << endl;

	return 0;
}