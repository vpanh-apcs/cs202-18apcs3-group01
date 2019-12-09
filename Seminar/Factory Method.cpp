//Factory Method
#include<iostream>
using namespace std;

class LogisticsManagement
{
public:

	LogisticsManagement() { }
	virtual void deliver() = 0;
	virtual void printVehicle() = 0;
};
class RoadLogistics : public LogisticsManagement
{
public:
	RoadLogistics() { }
	void printVehicle() {
		cout << "This is a truck" << endl;
	}
	void deliver() { }
	~RoadLogistics() { }
};

class SeaLogistics : public LogisticsManagement
{
public:
	SeaLogistics() { }
	void printVehicle() {
		cout << "This is a ship" << endl;
	}
	void deliver() { }
	~SeaLogistics() { }
};

int main()
{
	RoadLogistics* truck = new RoadLogistics;
	truck->printVehicle();
	cout << endl;
	SeaLogistics* ship = new SeaLogistics;
	ship->printVehicle();
	cout << endl;
	return 0;
}
