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
	m_myTeam(me)
{
}

// Destructor
Season::~Season() {}

int Season::getWins(){ return m_wins; } 
int Season::getLosses(){ return m_losses; } 

void Season::setWins(int& w){ m_wins = w; }
void Season::setLosses(int& l){ m_losses = l; }

Team Season::getOpponent(int& i){ return m_schedule[i]; }
void Season::setSchedule(Team& t)
{
	m_schedule.clear();
	int i = 0;
	int j = 0;
	while(m_schedule.size() <=16)
	{
		i++;
		std::cout << "loop ran " << i << " times." << std::endl;
		std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> d(1,31);
		int r = d(gen);
		if (m_teams[r].getName() != t.getName())
		{
			m_schedule.push_back(m_teams[r]);
			j++;
			std::cout << "teams added = " << j << std::endl;
		}
	}
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
		// debug
		//std::cout << "team name from infile: " << teamName << std::endl;
		//std::cout << "team from Team Object: " << t.getName() << std::endl;
	}
}

