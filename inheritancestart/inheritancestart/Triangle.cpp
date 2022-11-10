#include "triangle.h"
#include <iostream>
using namespace std;

Triangle::Triangle(double baseParam, double heightParam, string colourParam)
    : Shape(colourParam)
{
    base = baseParam;
    height = heightParam;
}

double Triangle::getBase() const
{
    return base;
}

void Triangle::setBase(double baseParam)
{
    base = baseParam;
}

double Triangle::getHeight() const
{
    return height;
}

void Triangle::setHeight(double heightParam)
{
    height = heightParam;
}

void Triangle::printDetails() const
{
    cout << "The is a triangle." << endl;

    // Print the colour of the shape
    Shape::printDetails();

    // Print the base and height of the triangle
    cout << "The base is: " << base << endl;

    // Print the base and height of the triangle
    cout << "The height is: " << height << endl;
}

double Triangle::calculateArea() const
{
    return 0.5 * base * height;
}