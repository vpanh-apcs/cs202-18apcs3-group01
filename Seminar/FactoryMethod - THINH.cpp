//Factory Method
#include<iostream>
using namespace std;
class AppleFactory
{
public:
	AppleFactory() { }
	virtual void print() = 0;
	~AppleFactory() { }
};
class RedApple : public AppleFactory
{
public:
	RedApple() { }
	void print() { cout << "This is red apple" << endl; }
	~RedApple() { }
};
class GreenApple : public AppleFactory
{
public:
	GreenApple() { }
	void print() { cout << "This is green apple" << endl; }
	~GreenApple() { }
};
int main()
{
	RedApple* redapple = new RedApple;
	redapple->print();
	cout << endl;

	GreenApple* greenapple = new GreenApple;
	greenapple->print();
	cout << endl;
	return 0;
}