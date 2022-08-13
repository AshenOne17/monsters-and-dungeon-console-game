#pragma once
#include "Player.h"

int getRandomNumber(int min, int max);

void attackMonster(Player& p, Monster& m);

void attackPlayer(Player& p, Monster& m);

void storeCheck(Player& p);

void playerInfo(Player& p);

void fightMonster(Player& p);