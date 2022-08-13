#include "Creature.h"
#include "Player.h"
#include "Monster.h"
#include "GameFunctions.h"
#include <iostream>
#include <string>
#include <cstdlib> // For rand() and srand()
#include <ctime> // For time()

int main()
{
	srand(static_cast<unsigned int>(time(0))); // Using system clock as starting value
	rand(); // Resetting first random number (for Visual Studio specifically)

	std::cout << "Enter your name: ";
	std::string name;
	std::getline(std::cin, name);

	std::cout << "*respawn sounds*\n";
	std::cout << "Welcome, " << name << ".\n";

	Player p(name);

	// Main game cycle until player has won or monster has died
	while (!p.hasWon() && !p.isDead()) { fightMonster(p); }

	if (p.isDead()) { std::cout << "You died at level " << p.getLevel() << " with " << p.getGold() << " gold." << std::endl; }
	else { std::cout << "You won the game with " << p.getGold() << " gold" << std::endl; }

	return 0;
}