// Description: Main Program

#include <iostream>

#include "Team.hpp"
#include "Game.hpp"

// Prints out some details on a Team
void printDetails(Team* t) {
	std::cout << "The " << t->getName() << " have Off: " << t->getOff();
	std::cout << ", Def: " << t->getDef() << std::endl;

	if (t->setHomeField()) std::cout << "The " << t->getName() << " have home field advantage"  << std::endl;
}

// Prints Matchup's Offensive and Defensive Stats
void showStats(Team h, Team a){
	std::cout << h.getName() << ":\t" << "Offense: " << h.getOff() << "\tDefense: " << h.getDef() << std::endl;
	std::cout << a.getName() << ":\t" << "Offense: " << a.getOff() << "\tDefense: " << a.getDef() << std::endl;
}

void startGame(Game g, Team h, Team a){ 
	g.setHomeTeam(h);
	g.setAwayTeam(a);

	std::cout << "Welcome Ladies and Gentlemen! Join us tonight, as the " << a.getName();
	std::cout << " take on the " << h.getName() << std::endl;

	showStats(h,a);
}


int main() {
	// Start the Game!
	Game game;
	Team Rav = Team("Ravens", 89, 93);
	Team Steel = Team("Steelers", 77, 90);
	startGame(game, Rav, Steel);
	
	return 0;
}
