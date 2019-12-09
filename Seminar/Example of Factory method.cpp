#include<iostream>
using namespace std;
enum TypeofAnimals
{
	Elephants, Tigers
};
class ZooFactory
{
public:

	ZooFactory() { }
	virtual void Eat() = 0;
	virtual void printAnimals() = 0;
};
class ElephantsFactory : public ZooFactory
{
public:
	ElephantsFactory() { }
	void printAnimals() {
		cout << "They are elephants" << endl;
	}
	void Eat() { cout << "Elephants eat sugar cane" << endl; }
	~ElephantsFactory() { }
};
class TigersFactory : public ZooFactory
{
public:
	TigersFactory() { }
	void printAnimals() {
		cout << "They are tigers" << endl;
	}
	void Eat() { cout << "Tigers eat meat" << endl; }
	~TigersFactory() { }
};

int main()
{
	ElephantsFactory* elephant = new ElephantsFactory;
	elephant->printAnimals();
	elephant->Eat();
	cout << endl;

	TigersFactory* tiger = new TigersFactory;
	tiger->printAnimals();
	tiger->Eat();


	return 0;
}
