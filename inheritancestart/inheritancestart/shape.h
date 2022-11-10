#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape
{
public:
	//	Shape constuctors
	Shape();
	Shape(std::string colourParam);

    //  Get the colour of the shape
	std::string getColour() const;

    //  Set the colour of the shape
    void setColour(std::string colourParam);

	// Prints the details of the shape
	virtual void printDetails() const;

	// Calculates and returns the area of the shape
	virtual double calculateArea() const;

private:

	std::string colour;
};

#endif // SHAPE_H