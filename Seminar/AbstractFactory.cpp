//Abstract Factory
#include<iostream>
using namespace std;
class TypeofElectronicDevice
{
public:
	TypeofElectronicDevice() { }
	virtual void printDevice() = 0;
	~TypeofElectronicDevice() { }
};
class IPhone : public TypeofElectronicDevice
{
public:
	IPhone() { }
	void printDevice() { }
	~IPhone() { }
};
class MacBook : public TypeofElectronicDevice
{
public:
	MacBook() { }
	void printDevice() { }
	~MacBook() { }
};
class IPad : public TypeofElectronicDevice
{
public:
	IPad() { }
	void printDevice() { }
	~IPad() { }
};
class DeviceFactory
{
public:
	virtual IPhone* createIphone() = 0;
	virtual IPad* createIpad() = 0;
	virtual MacBook* createMacBook() = 0;
};
class createPro : public DeviceFactory
{
public:
	IPhone* createIphone()
	{
		cout << "This is Iphone pro" << endl;
		return new IPhone;
	}
	IPad* createIpad()
	{
		cout << "This is Ipad pro" << endl;
		return new IPad;
	}
	MacBook* createMacBook()
	{
		cout << "This is MacBook pro" << endl;
		return new MacBook;
	}
};
class createPromax : public DeviceFactory
{
public:
	IPhone* createIphone()
	{
		cout << "This is Iphone pro max" << endl;
		return new IPhone;
	}
	IPad* createIpad()
	{
		cout << "This is Ipad pro max" << endl;
		return new IPad;
	}
	MacBook* createMacBook()
	{
		cout << "This is MacBook pro max" << endl;
		return new MacBook;
	}
};

int main()
{
	cout << "                              Pro Device" << endl;
	createPro* proDevice = new createPro;
	proDevice->createIphone();
	proDevice->createIpad();
	proDevice->createMacBook();
	cout << endl;
	cout << "                              Pro Max Device" << endl;
	createPromax* promaxDevice = new createPromax;
	promaxDevice->createIphone();
	promaxDevice->createIpad();
	promaxDevice->createMacBook();
	cout << endl;
}