// Description: Main Program

#include <iostream>
#include <vector>
#include <random>
#include <cmath>

#include "Team.hpp"
#include "Game.hpp"
#include "Field.hpp"


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

	h.printDetails();
	a.printDetails();
	
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

void playGame(Team& t1, Team& t2){

	
	/* Get Team Strength */
	std::vector <int> pow1 = {t1.getOff(), t1.getDef()};
	std::vector <int> pow2 = {t2.getOff(), t2.getDef()};
	float adv1 = (float)(pow1[0] - pow2[1])/10;
	float adv2 = (float)(pow2[0] - pow1[1])/10;

	/* Set Random Numbers */
	std::random_device rd;
	std::mt19937 gen(rd());
	std::normal_distribution<float> td1_dist(3+adv1, 1.5);
	std::normal_distribution<float> td2_dist(3+adv2, 1.5);
	std::normal_distribution<float> fg1_dist(3+adv1, 1.5);
	std::normal_distribution<float> fg2_dist(3+adv2, 1.5);

	// calculate score
	int td1; int td2; int fg1; int fg2; int score1; int score2;
	td1 = td1_dist(gen)*7;
	td2 = td2_dist(gen)*7;
	fg1 = fg1_dist(gen)*3;
	fg2 = fg2_dist(gen)*3;
	score1 = td1 + fg1;
	score2 = td2 + fg2;
	// print score
	std::cout << "Final Score:\n" << t1.getName() << " " << score1 << " " << t2.getName() << " " << score2 << std::endl;
}
void simSeason(Team& myTeam){
	// maybe have season class, with record and schedule attribute?
}

int main() {
	// Start the Game!
	Game game;
	Field fop; // field of play
	Team Rav = Team("Ravens", 95, 93);
	Team Steel = Team("Steelers", 77, 85);
	startGame(game, fop, Rav, Steel);

	kickOff(fop,Rav,Steel);
	playGame(Rav,Steel);
	/*
	while (fop.checkTurnover() == false){
		doPlay(fop,Rav,Steel);
	}
	// run transition function, which resets turnover
	*/
	
	return 0;
}
