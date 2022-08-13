#include "Player.h"

Player::Player(std::string name) :Creature(name, '@', 10, 1, 0) {}

void Player::levelUp()
{
	m_level++;
	m_damage++;
	m_health = 10;
	for (int count = 0; count < m_level; count++) { m_health += 5; }
}

bool Player::hasWon()
{
	if (m_level == 20) { return true; }
	else { return false; }
}