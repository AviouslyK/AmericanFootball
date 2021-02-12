// Description: Main Program

#include <iostream>

#include "Team.hpp"
#include "Game.hpp"
#include "Field.hpp"

// Prints out some details on a Team
void printDetails(Team* t) {
	std::cout << "The " << t->getName() << " have Off: " << t->getOff();
	std::cout << ", Def: " << t->getDef() << std::endl;

	if (t->setHomeField()) std::cout << "The " << t->getName() << " have home field advantage"  << std::endl;
}

// Prints Matchup's Offensive and Defensive Stats
void showStats(Team& h, Team& a){
	std::cout << h.getName() << ":\t" << "Offense: " << h.getOff() << "\tDefense: " << h.getDef() << std::endl;
	std::cout << a.getName() << ":\t" << "Offense: " << a.getOff() << "\tDefense: " << a.getDef() << std::endl;
}

void kickOff(Field& f, Team& offense, Team& defense){
	defense.loseBall();
	offense.giveBall();
	f.setYard(25);
	f.setDown(1);
}

void startGame(Game& g, Field& f, Team& h, Team& a){ 
	g.setHomeTeam(h);
	g.setAwayTeam(a);
	
	std::cout << "Welcome Ladies and Gentlemen! Join us tonight, as the " << a.getName();
	std::cout << " take on the " << h.getName() << std::endl;

	showStats(h,a);
	std::cout << "The Home Team Starts with the Ball!" << std::endl;
}

void readPlay(int& down, int& yard){
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

void doPlay(Field& f, Team& offense, Team& defense){

	int down = f.getDown();
	int yard = f.getYard();
	// Read Play
	readPlay(down, yard);
	// decide if pass or run

	// calculate yards gained

	// move ball up/down field
	
	if (f.getDown() > 4) { // turnover
		offense.loseBall();
		defense.giveBall();
		f.setDown(1);
		f.turnover();
		std::cout << "turnover on downs!" << std::endl;
	}

	// set down
	f.setDown(down + 1);

}

int main() {
	// Start the Game!
	Game game;
	Field fop; // field of play
	Team Rav = Team("Ravens", 89, 93);
	Team Steel = Team("Steelers", 77, 90);
	startGame(game, fop, Rav, Steel);

	kickOff(fop,Rav,Steel);

	while (fop.checkTurnover() == false){
		doPlay(fop,Rav,Steel);
	}
	// run transition function, which resets turnover
	return 0;
}
