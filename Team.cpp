// Description: Team class

#include "Team.hpp"

#include <string>
#include <iostream>

// Constructor for Team
Team::Team(std::string teamName, int off, int def):
	m_name(teamName),
	m_off(off),
	m_def(def)
{
}

// Destructor
Team::~Team() {}

int Team::getOff() { return m_off; } // get offensive strength
int Team::getDef() { return m_def; } // get defensive strength
std::string Team::getName() { return m_name; } // get team name
bool Team::getHome() { return m_home; } // Check for Home-Field advantage


void Team::setOff(int off) { m_off = off; } // set offensive strength
void Team::setDef(int def) { m_def = def; } // Set the defensive strength 
bool Team::setHomeField() { return m_home = true;}

bool Team::hasBall() { return m_hasBall; } // check if team has the ball
void Team::loseBall() { m_hasBall = false; } // take possesion from team
void Team::giveBall() { m_hasBall = false; } // give team possesion

// Prints out some details on a Team
void Team::printDetails() {
	std::cout << "The " << m_name << " have Off: " << m_off;
	std::cout << ", Def: " << m_def << std::endl;

	if (m_home) std::cout << "The " << m_name << " have home field advantage"  << std::endl;
}
