#include "Monster.h"
#include "GameFunctions.h"

Monster::Monster(Type type)
:Creature(monsterData[type].name, monsterData[type].symbol, monsterData[type].health, monsterData[type].damage, monsterData[type].gold) {}

Monster Monster::getRandomMonster()
{
	int randomMonster{ getRandomNumber(0, MAX_TYPES - 1) };
	return Monster(static_cast<Type>(randomMonster));
}

// All monsters info
Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]
{
	{ "dragon", 'D', 20, 4, 100 },
	{ "orc", 'o', 4, 2, 25 },
	{ "slime", 's', 1, 1, 10 },
	{ "troll", 't', 10, 2, 35},
	{ "hound", 'h', 6, 2, 25},
	{ "rat", 'r', 1, 1, 5},
	{ "trent", 'tr', 3, 3, 30},
	{ "valkyrie", 'v', 3, 2, 20},
	{ "artorias", 'a', 50, 8, 250},
	{ "voidwoken", 'vw', 25, 5, 75},
	{ "foolish", 'f', 5, 2, 15},
	{ "giant", 'g', 15, 5, 50},


};