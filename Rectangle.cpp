// Example Project
// Author: Jake Lane
// Student ID: a1686679
// Description: Rectangle class

#include "Rectangle.h"

// Constructor for Rectangle
Rectangle::Rectangle(int height, int width): Polygon(height, width) {}

// Destructor
Rectangle::~Rectangle() {}

// Returns the area of the square
float Rectangle::area() {
	return m_height * m_width;
}
