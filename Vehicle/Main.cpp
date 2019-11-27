#include "Vehicle.h"
int Vehicle::Count = 0;
int main()
{
	cout << Vehicle::GetCount();
	Position p;
	p.x = 30;
	p.y = 30;	
	Vehicle* v1 = new Truck(p);
	Vehicle* v2 = new Truck(p);
	v1->Left(5);
	v2->Right(10);
	v1->Display();
	v2->Display();
	_getch();
	return 0;
}