// Description: Field class

#ifndef FIELD_H_
#define FIELD_H_

#include <string>

class Field {
public:
	// Constructor
	Field();
	// Destructor
	~Field();
	
	// Getters
	int getDown();
	int getYard();
	
	// Setters
	int setDown(int d);
	int setYard(int y);

	void turnover();
	bool checkTurnover();
protected:
	// Member variables
	int m_down; // 1st down, 2nd down, etc.
	int m_yard; // ball's position on the field
	bool m_turnover; // check's state of game, used for change of possesion
};

#endif // GAME_H_
