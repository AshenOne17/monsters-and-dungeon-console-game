#pragma once
#include "Creature.h"
// ***** IMPORTANT INFO *****
// INCLUDING MONSTER.H TO BREAK CIRCULAR DEPENDANCY BETWEEN MONSTER.H AND GAMEFUNCTIONS.H
// SPECIFICALLY FUNCTION getRandomNumber() IN GAMEFUNCTIONS.H AND Monster CLASS IN GAMEFUNCTIONS.H WHICH
// GENERATE CIRCULAR DEPENDANCY. AND SINCE PLAYER OBJECTS ARE PASSED IN FUNCTIONS' FORWARD DECLARATIONS
// IN GAMEFUNCTIONS.H, INCLUDING MONSTER.H IN PLAYER.H INCLUDES Monster CLASS FORWARD DECLARATION USED IN FUNCTIONS
// FORWARD DECLARATION PARAMETERS' WITH USING PLAYER.H
#include "Monster.h"

// Inhereting from parent Creature class
class Player : public Creature {
private:
	int m_level{ 1 };

public:
	Player(std::string name);

	void levelUp();

	bool hasWon();

	int getLevel() { return m_level; }

};