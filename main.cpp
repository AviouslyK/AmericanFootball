// Description: Main Program

#include <iostream>

#include "Team.hpp"

// Prints out some details on a Team
void printDetails(Team* t) {
	std::cout << "The " << t->getName() << " have Off: " << t->getOff();
	std::cout << ", Def: " << t->getDef() << std::endl;

	if (t->setHomeField()) std::cout << "The " << t->getName() << " have home field advantage"  << std::endl;
}

int main() {
	// Create Ravens Team
	Team* Rav = new Team("Ravens", 89, 93);
	// Print information using getters and method
	printDetails(Rav);
	// Set the offensive strength to 100 with a setter
	Rav->setOff(100);
	// Set the defensive strength to 100 with a setter
	Rav->setDef(100);
	// Print information using getters and method
	printDetails(Rav);
	// Cleanup the memory in the heap
	delete Rav;

	// Create Steelers Team
	Team* Steel = new Team("Steelers", 77, 90);
	// Print information using getters and method
	printDetails(Steel);
	// Set the offensive strength to 50 with a setter
	Steel->setOff(50);
	// Set the defensive strength to 50 with a setter
	Steel->setDef(50);
	// Print information using getters and method
	printDetails(Steel);
	// Cleanup the memory in the heap
	delete Steel;

	return 0;
}
