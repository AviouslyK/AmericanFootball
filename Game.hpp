// Description: Team class

#ifndef GAME_H_
#define GAME_H_

#include "Team.hpp"
#include <string>

class Game {
public:
	// Constructor
	Game();
	// Destructor
	~Game();
	
	// Getters
	int getHomeScore();
	int getAwayScore();
	int getTime();
	Team getHomeTeam();
	Team getAwayTeam();

	// Setters
	int setHomeScore(int s);
	int setAwayScore(int s);
	int setTime(int t);
	void setHomeTeam(Team h);
	void setAwayTeam(Team a);

	
protected:
	// Member variables
	int m_homeScore;
	int m_awayScore;
	int m_time;
    Team m_homeTeam;
	Team m_awayTeam;
};

#endif // GAME_H_
