#pragma once
#include "Creature.h"

// Inhereting from parent Creature class
class Monster : public Creature {
public:
	// Types of monsters
	enum Type
	{
		DRAGON,
		ORC,
		SLIME,
		TROLL,
		HOUND,
		RAT,
		TRENT,
		VALKYRIE,
		ARTORIAS,
		VOIDWOKEN,
		FOOLISH,
		GIANT,
		MAX_TYPES,
	};

	// Monster info
	struct MonsterData
	{
		const char* name;
		char symbol;
		int health;
		int damage;
		int gold;
	};

	// static array for containing monster info
	static MonsterData monsterData[MAX_TYPES];

	Monster(Type type);

	// Generating random monster
	static Monster getRandomMonster();
};