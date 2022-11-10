#include "Triangle.h"
#include <iostream>

using namespace std;

int main()
{
	Shape* shapes[3];
	shapes[0] = new Triangle(1.0, 2.5, "Black");
	shapes[1] = new Triangle(5.0, 2.5, "Black");
	shapes[2] = new Triangle(2.0, 2.5, "Black");

	for (int i = 0; i < 3; i++)
	{
		shapes[i]->printDetails();
		cout << "The area of the shape is: " << shapes[i]->calculateArea() << "." << endl;
	}

	for (int i = 0; i < 3; i++)
	{
		delete shapes[i];
	}





	return 1;
}