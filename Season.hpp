// Description: Season class

#ifndef SEASON_H_
#define SEASON_H_

#include "Team.hpp"

#include <string>
#include <vector>

class Season {
public:
	// Constructor
	Season(Team me);
	// Destructor
	~Season();
	
	// Getters
	int getWins();
	int getLosses();
	Team getOpponent(int& i); 

	// Setters
	void setWins(int& w);
	void setLosses(int& l);
	void setSchedule(Team& t);

	void readTeams();
	
protected:
	// Member variables
	int m_wins;
	int m_losses;
	std::vector<Team> m_schedule;
	std::vector<Team> m_teams;
	Team m_myTeam;
	bool m_schedule_set; // check to see if schedule is set
};

#endif // TEAM_H_
