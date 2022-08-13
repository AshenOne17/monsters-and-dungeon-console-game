#pragma once
#include <string>

// Parent class for Class Player and Class Monster
class Creature {
// Protected because parent class 
protected:
	std::string m_name;
	char m_ch;
	int m_health;
	int m_damage;
	int m_gold;

public:

	Creature(std::string name, char ch, int health, int damage, int gold);

	std::string getName() { return m_name; }

	char getSymbol() { return m_ch; }

	int getHealth() { return m_health; }

	int getDamage() { return m_damage; }

	int getGold() { return m_gold; }

	void reduceHealth(int value) { m_health -= value; }

	void damageIncrease(int value) { m_damage += value; }

	void addGold(int value) { m_gold += value; }

	void reduceGold(int value) { m_gold -= value; }

	bool isDead();
};