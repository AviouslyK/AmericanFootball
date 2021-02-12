// Description: Game class

#include "Game.hpp"

#include <string>

// Constructor for Game
Game::Game():
	m_homeScore(0), m_awayScore(0), m_time(0),
	m_homeTeam(Team("default_home",-1,-1)), m_awayTeam(Team("default_away",-1,-1))
{
}

// Destructor
Game::~Game() {}

int Game::getHomeScore() { return m_homeScore; } 
int Game::getAwayScore() { return m_awayScore; } 
int Game::getTime() { return m_time; } 
Team Game::getHomeTeam(){ return m_homeTeam;}
Team Game::getAwayTeam(){ return m_awayTeam;}

int Game::setHomeScore(int h) { return m_homeScore = h; } 
int Game::setAwayScore(int s) { return m_awayScore = s; } 
int Game::setTime(int t) { return m_time = t; } 
void Game::setHomeTeam(Team &h){
	m_homeTeam = h;
	m_homeTeam.setHomeField();
}
void Game::setAwayTeam(Team &a){ m_awayTeam = a; }
