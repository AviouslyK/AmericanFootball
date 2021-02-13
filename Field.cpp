// Description: Field class

#include "Field.hpp"

#include <string>

// Constructor for Field
Field::Field():
	m_down(0), m_yard(0), m_turnover(false)
{
}

// Destructor
Field::~Field() {}

int Field::getDown() { return m_down; } 
int Field::getYard() { return m_yard; } 

int Field::setDown(int d) { return m_down = d; } 
int Field::setYard(int y) { return m_yard = y; } 

void Field::turnover() { m_turnover = true; }
bool Field::checkTurnover() {return m_turnover; }

