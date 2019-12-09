#include<iostream>
using namespace std;
class Animal
{
public:
	virtual void Eat() = 0;
	virtual void Drink() = 0;
};
class Dog : public Animal
{
public:
	void Eat() {
		cout << "Eat dog food" << endl;
	}
	void Drink() {
		cout << "Drink dog milk" << endl;
	}
};
class Cat : public Animal
{
public:
	void Eat() {
		cout << "Eat cat food" << endl;
	}
	void Drink() {
		cout << "Drink cat milk" << endl;
	}
};
class AnimalFactory
{
public:
	AnimalFactory() { }
	virtual Cat* createCat() = 0;
	virtual Dog* createDog() = 0;
	~AnimalFactory() { }
};
class WhiteAnimalFactory : public AnimalFactory
{
public:
	WhiteAnimalFactory() { };
	Cat* createCat() {
		cout << "This is white cat" << endl;
		return new Cat;
	}
	Dog* createDog() {
		cout << "This is white dog" << endl;
		return new Dog;
	}
	~WhiteAnimalFactory() { }
};
class BlackAnimalFactory : public AnimalFactory
{
public:
	BlackAnimalFactory() { }
	Cat* createCat() {
		cout << "This is black cat" << endl;
		return new Cat;
	}
	Dog* createDog() {
		cout << "This is black dog" << endl;
		return new Dog;
	}
	~BlackAnimalFactory() { }
};
int main()
{
	cout << "                                     White Animal                       " << endl;
	WhiteAnimalFactory* whiteAnimal = new WhiteAnimalFactory;
	whiteAnimal->createCat()->Eat();
	whiteAnimal->createCat()->Drink();
	cout << endl;
	whiteAnimal->createDog()->Eat();
	whiteAnimal->createDog()->Drink();
	cout << endl;

	cout << "                                     Black Animal                       " << endl;
	BlackAnimalFactory* blackAnimal = new BlackAnimalFactory;
	blackAnimal->createCat()->Eat();
	blackAnimal->createCat()->Drink();
	cout << endl;
	blackAnimal->createDog()->Eat();
	blackAnimal->createDog()->Drink();
	cout << endl;

	return 0;
}