#include "Creature.h"
#include <string>

Creature::Creature(std::string name, char ch, int health, int damage, int gold)
:m_name(name), m_ch(ch), m_health(health), m_damage(damage), m_gold(gold) {}

bool Creature::isDead()
{
	if (m_health <= 0) { return true; }
	else { return false; }
}