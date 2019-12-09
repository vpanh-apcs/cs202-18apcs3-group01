//Abstract Factory
#include<iostream>
using namespace std;
class TypeofJuice
{
public: 
	TypeofJuice() { }
	virtual void printJuice() = 0;
	~TypeofJuice() { }
};
class GrapeJuice : public TypeofJuice
{
public: 
	GrapeJuice() { }
	void printJuice() { }
	~GrapeJuice() { }
};
class OrangeJuice : public TypeofJuice
{
public: 
	OrangeJuice() { }
	void printJuice() { }
	~OrangeJuice() { }
};
class AppleJuice : public TypeofJuice
{
public:
	AppleJuice() { }
	void printJuice() { }
	~AppleJuice() { }
};
class JuiceFactory
{
public:
	JuiceFactory() { }
	virtual GrapeJuice* createGrapeJuice() = 0;
	virtual OrangeJuice* createOrangeJuice() = 0;
	virtual AppleJuice* createAppleJuice() = 0;
	~JuiceFactory() { }
};
class createSmallJuice  : public JuiceFactory
{
public:
	GrapeJuice* createGrapeJuice()
	{
		cout << "This is small grape juice" << endl;
		return new GrapeJuice;
	}
	OrangeJuice* createOrangeJuice()
	{
		cout << "This is small orange juice" << endl;
		return new OrangeJuice;
	}
	AppleJuice* createAppleJuice()
	{
		cout << "This is small apple juice" << endl;
		return new AppleJuice;
	}
};
class createMediumJuice : public JuiceFactory
{
public:
	GrapeJuice* createGrapeJuice()
	{
		cout << "This is medium grape juice" << endl;
		return new GrapeJuice;
	}
	OrangeJuice* createOrangeJuice()
	{
		cout << "This is medium orange juice" << endl;
		return new OrangeJuice;
	}
	AppleJuice* createAppleJuice()
	{
		cout << "This is medium apple juice" << endl;
		return new AppleJuice;
	}
};
class createBigJuice : public JuiceFactory
{
public:
	GrapeJuice* createGrapeJuice()
	{
		cout << "This is big grape juice" << endl;
		return new GrapeJuice;
	}
	OrangeJuice* createOrangeJuice()
	{
		cout << "This is big orange juice" << endl;
		return new OrangeJuice;
	}
	AppleJuice* createAppleJuice()
	{
		cout << "This is big apple juice" << endl;
		return new AppleJuice;
	}
};
int main()
{
	cout << "                                  Small Juice                   " << endl;
	createSmallJuice* smalljuice = new createSmallJuice;
	smalljuice->createGrapeJuice();
	smalljuice->createOrangeJuice();
	smalljuice->createAppleJuice();
	cout << endl;

	cout << "                                  Medium Juice                   " << endl;
	createMediumJuice* mediumjuice = new createMediumJuice;
	mediumjuice->createGrapeJuice();
	mediumjuice->createOrangeJuice();
	mediumjuice->createAppleJuice();
	cout << endl;

	cout << "                                  Big Juice                   " << endl;
	createBigJuice* bigjuice = new createBigJuice;
	bigjuice->createGrapeJuice();
	bigjuice->createOrangeJuice();
	bigjuice->createAppleJuice();
	cout << endl;
	return 0;
}