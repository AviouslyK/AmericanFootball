// Description: Team class

#ifndef TEAM_H_
#define TEAM_H_

#include <string>

class Team {
public:
	// Constructor
	Team(std::string teamName, int off, int def);
	// Destructor
	~Team();
	
	// Getters
	int getOff();
	int getDef();
	bool getHome();
	std::string getName();
	
	// Setters
	void setOff(int off);
	void setDef(int def);
	bool setHomeField();

protected:
	// Member variables
	int m_off;
	int m_def;
	bool m_home = false;
	std::string m_name;
};

#endif // TEAM_H_
