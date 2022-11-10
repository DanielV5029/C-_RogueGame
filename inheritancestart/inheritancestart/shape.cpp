// Include the shape header file.
#include "shape.h"
#include <iostream>
using namespace std;

Shape::Shape()
{
	colour = "No Colour";
}

Shape::Shape(std::string colourParam)
{
	colour = colourParam;
}

std::string Shape::getColour() const
{
	return colour;
}

void Shape::setColour(std::string colourParam)
{
	colour = colourParam;
}

void Shape::printDetails()
{
	cout << "The colour of the shape is: " << colour << endl;

}

double Shape::calculateArea()
{
	return 0.0;
}




