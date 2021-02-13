// Description: Season class

#include "Season.hpp"
#include "Team.hpp"

#include <string>
#include <random>
#include <iostream>
#include <fstream>
#include <sstream>

// Constructor for Season
Season::Season(Team me):
	m_myTeam(me), m_schedule_set(false)
{
}

// Destructor
Season::~Season() {}

int Season::getWins(){ return m_wins; } 
int Season::getLosses(){ return m_losses; } 

void Season::setWins(int& w){ m_wins = w; }
void Season::setLosses(int& l){ m_losses = l; }

Team Season::getOpponent(int& i)
{
	if(m_schedule_set) return m_schedule[i];
	else
	{
		Team err = Team("Schedule Not Set", 0, 0);
		return err;
	}
}
void Season::setSchedule(Team& t)
{
	m_schedule.clear();
	while(m_schedule.size() <16)
	{
		std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> d(1,31);
		int r = d(gen);
		if (m_teams[r].getName() != t.getName()) m_schedule.push_back(m_teams[r]);
	}
	m_schedule_set = true;
}

void Season::readTeams(){
	std::ifstream infile("teams.txt");
    std::string str; 
	std::string city, city2, name, teamName;
	int off, def;
	while(infile >> city >> name >> off >> def)
	{
		teamName = city + " " + name;
		Team t = Team(teamName, off, def);
		m_teams.push_back(t);
	}

	//debug
	for(auto& team: m_teams)
	{
		std::cout << team.getName() << std::endl;
	}
}

