// Description: Field class

#include "Field.hpp"

#include <string>
#include <iostream>

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

void Field::readPlay(int& down, int& yard){
        switch(down)
        {
        case 1:
                std::cout << "It's 1st and " << "TODO" << "on the " << yard << std::endl;
                break;
        case 2:
                std::cout << "It's 2nd and " << "TODO" << "on the " << yard << std::endl;
                break;
        case 3:
                std::cout << "It's 3rd and " << "TODO" << "on the " << yard << std::endl;
                break;
        case 4:
                std::cout << "It's 4th and " << "TODO" << "on the " << yard << std::endl;
                break;
        default:
                std::cout << "invalid down" << std::endl;
        }
}
