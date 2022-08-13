#include "GameFunctions.h"
#include "Monster.h"
#include "Player.h"
#include <cstdlib>
#include <iostream>

// Generating random number between min and max
int getRandomNumber(int min, int max)
{
	static const double fraction{ 1.0 / (static_cast<double>(RAND_MAX) + 1.0) };
	// Uniformly distributing calculation value from our range
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void attackMonster(Player& p, Monster& m)
{
	// Checking if player is alive
	if (p.isDead()) return;

	std::cout << "\nYou hit a(n) " << m.getName() << " for " << p.getDamage() << " damage" << std::endl;

	m.reduceHealth(p.getDamage());

	// Checking if monster is dead
	if (m.isDead()) {
		std::cout << "You killed " << m.getName() << std::endl;
		p.levelUp();
		std::cout << "You are now " << p.getLevel() << " level" << std::endl;
		std::cout << "You found " << m.getGold() << " gold\n" << std::endl;
		p.addGold(m.getGold());
	}
}

void attackPlayer(Player& p, Monster& m)
{
	// Checking if monster is dead
	if (m.isDead()) return;

	p.reduceHealth(m.getDamage());

	std::cout << "\nThe " << m.getName() << " hit you for " << m.getDamage() << " damage!\n" << std::endl;
}
// Store
void storeCheck(Player& p) {
	if (p.isDead()) return;

	std::cout << std::endl;
	std::cout << "-------------------" << std::endl;
	std::cout << "Welcome, Tarnished." << std::endl;

	std::cout << "You have " << p.getGold() << " gold.\n";
	std::cout << "\n1. Rusty sword (+1 dmg) - 75 gold\n 2. Iron Sword (+2 dmg) - 125 gold\n 3. Titanium Mace (+3 dmg) - 200 gold\n 4. Diamond Sword (+4 dmg) - 325 gold\n 5. Double - Edged Graphite Blade (+5 dmg) - 500 gold\n";
	std::cout << "Choose your weapon(You can buy any amount of any weapons)/'c' to close the shop: ";
	char buyInput;
	std::cin >> buyInput;
	std::cout << "-----------------------" << std::endl;

	// Shop closed
	if (buyInput == 'c')
	{
		std::cout << std::endl;
		return;
	}

	// Each weapon assigned to number
	if (buyInput == '1')
	{
		if (p.getGold() < 75)
		{
			std::cout << "You don't have enough gold!" << std::endl;
			return;
		}
		else
		{
			p.damageIncrease(1);
			p.reduceGold(75);
			std::cout << "You have succesfully bought Rusty Sword!" << std::endl;
			std::cout << "You current damage: " << p.getDamage() << std::endl;
		}

	}

	if (buyInput == '2')
	{
		if (p.getGold() < 125)
		{
			std::cout << "You don't have enough gold!" << std::endl;
			return;
		}
		else
		{
			p.damageIncrease(2);
			p.reduceGold(125);
			std::cout << "You have succesfully bought Iron Sword!" << std::endl;
			std::cout << "You current damage: " << p.getDamage() << std::endl;
		}

	}

	if (buyInput == '3')
	{
		if (p.getGold() < 200)
		{
			std::cout << "You don't have enough gold!" << std::endl;
			return;
		}
		else
		{
			p.damageIncrease(3);
			p.reduceGold(200);
			std::cout << "You have succesfully bought Titanium Mace!" << std::endl;
			std::cout << "You current damage: " << p.getDamage() << std::endl;
		}

	}

	if (buyInput == '4')
	{
		if (p.getGold() < 325)
		{
			std::cout << "You don't have enough gold!" << std::endl;
			return;
		}
		else
		{
			p.damageIncrease(4);
			p.reduceGold(325);
			std::cout << "You have succesfully bought Diamond Sword!" << std::endl;
			std::cout << "You current damage: " << p.getDamage() << std::endl;
		}

	}

	if (buyInput == '5')
	{
		if (p.getGold() < 500)
		{
			std::cout << "You don't have enough gold!" << std::endl;
			return;
		}
		else
		{
			p.damageIncrease(5);
			p.reduceGold(500);
			std::cout << "You have succesfully bought Double - Edged Graphite Blade!" << std::endl;
			std::cout << "You current damage: " << p.getDamage() << std::endl;
		}
	}
}

void playerInfo(Player& p)
{
	if (p.isDead()) return;
	std::cout << "---------------" << std::endl;
	std::cout << p.getName() << ": " << std::endl;
	std::cout << "Level: " << p.getLevel() << std::endl;
	std::cout << "Health: " << p.getHealth() << std::endl;
	std::cout << "Damage: " << p.getDamage() << std::endl;
	std::cout << "Gold: " << p.getGold() << std::endl;
	std::cout << "---------------" << std::endl;
}

void monsterInfo(Monster& m)
{
	std::cout << "---------------" << std::endl;
	std::cout << m.getName() << ": " << std::endl;
	std::cout << "Health: " << m.getHealth() << std::endl;
	std::cout << "Damage: " << m.getDamage() << std::endl;
	std::cout << "Gold: " << m.getGold() << std::endl;
	std::cout << "---------------" << std::endl;
}

void fightMonster(Player& p)
{
	// Getting random monster
	Monster m = Monster::getRandomMonster();
	std::cout << "\n-------------------------------------";
	std::cout << "\nYou have encountered a(n) " << m.getName() << " (" << m.getSymbol() << ")" << std::endl;

	// Main game cycle while player or/and monster is/are dead
	while (!p.isDead() && !m.isDead())
	{
		std::cout << "(R)un or (F)ight/Player(1) or Monster(2) info/(S)tore: ";
		char input;
		std::cin >> input;

		if (input == 'R' || input == 'r')
		{
			if (getRandomNumber(1, 2) == 1)
			{
				std::cout << "\nYou have succesfully ran." << std::endl;
				return;
			}
			else
			{
				std::cout << "\nYou failed to run!" << std::endl;
				attackPlayer(p, m);
				continue;
			}
		}

		if (input == 'F' || input == 'f')
		{
			attackMonster(p, m);
			attackPlayer(p, m);
		}

		if (input == '1')
		{
			playerInfo(p);
			continue;

		}

		if (input == '2')
		{
			monsterInfo(m);
			continue;
		}

		if (input == 'S' || input == 's')
		{
			storeCheck(p);
			continue;
		}
	}
}