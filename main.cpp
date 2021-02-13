// Description: Main Program

#include <iostream>
#include <vector>
#include <random>
#include <cmath>

#include "Team.hpp"
#include "Game.hpp"
#include "Field.hpp"
#include "Season.hpp"

void startGame(Game& g, Field& f, Team& h, Team& a){ 
	g.setHomeTeam(h);
	g.setAwayTeam(a);
	
	std::cout << "Welcome Ladies and Gentlemen! Join us tonight, as the " << a.getName();
	std::cout << " take on the " << h.getName() << std::endl;

	h.printDetails();
	a.printDetails();
	
	std::cout << "The Home Team Starts with the Ball!" << std::endl;
}


void doPlay(Field& f, Team& offense, Team& defense){

	int down = f.getDown();
	int yard = f.getYard();
	// Read Play
	f.readPlay(down, yard);
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

std::vector<int> playGame(Team& t1, Team& t2){

	
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

	//* TODO fix negative scores *//
	
	// calculate score
	int td1; int td2; int fg1; int fg2;
	std::vector<int> scores;
	td1 = td1_dist(gen)*7;
	td2 = td2_dist(gen)*7;
	fg1 = fg1_dist(gen)*3;
	fg2 = fg2_dist(gen)*3;
	scores.push_back(td1 + fg1);
	scores.push_back(td2 + fg2);

	return scores;
}

void simSeason(Team& myTeam){
	Season s = Season(myTeam);
	s.readTeams();	
	s.setSchedule(myTeam);
	std::cout << "2020 Schedule:" << std::endl; // todo add year, maybe new Franchise class, for multiple seasons
	s.printSchedule(); 

	std::vector<int> score;
	int wins = 0;
	int losses = 0;
	for(int i=0; i<16; i++) // week loop
	{
		std::cout << "WEEK " << i+1 << std::endl;
		Team op = s.getOpponent(i);
		score = playGame(myTeam, op);
		if(score[0] > score[1]) 
		{
			wins += 1;
			s.setWins(wins);
		}
		else
		{
			losses += 1;
			s.setLosses(losses);
		}
		std::cout << "Final Score:\t" << myTeam.getName() << " " << score[0] << " " << op.getName() << " " << score[1] << std::endl;
		std::cout << "After Week " << i+1 << " the " << myTeam.getName() << " are " << wins << "-" << losses << "\n\n";
	}
	
}

int main() {
	// Start the Game!
	Game game;
	Field fop; // field of play
	Team Rav = Team("Ravens", 90, 90);
	Team Steel = Team("Steelers", 77, 85);
	Rav.setName("BALTIMORE RAVENS");
	simSeason(Rav);
	//startGame(game, fop, Rav, Steel);

	//game.kickOff(fop,Rav,Steel);
	//playGame(Rav,Steel);
	/*
	while (fop.checkTurnover() == false){
		doPlay(fop,Rav,Steel);
	}
	// run transition function, which resets turnover
	*/
	
	return 0;
}
