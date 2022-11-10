#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"

class Triangle : public Shape
{
public:
	//	Square constructor
	Triangle(double baseParam, double heightParam, string colourParam);

	//  Get the base of the triangle
	double getBase() const;

	//  Set the base of the triangle
	void setBase(double baseParam);

	//  Get the height of the triangle
	double getHeight() const;

	//  Set the base of the triangle
	void setHeight(double heightParam);

	// Prints the details of the shape
	virtual void printDetails() const;

	// Calculates and returns the area of the shape
	virtual double calculateArea() const;

private:

	double base;
	double height;
};

#endif // TRIANGLE_H
