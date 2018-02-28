#ifndef FIGHTFUNCTIONS_H
#define FIGHTFUNCTIONS_H

#include "hero.h"
#include "monster.h"

int showOptions(Living* hero);
bool avoidAttack(Living* livingBeing);
int randomMinToMax (int min, int max);
bool fight (Living** heroArray, int numberOfHeroes, Living** monsterArray, int numberOfMonsters);
void afterFight(int fightResult, Living** heroArray, int numberOfHeroes, Living** monsterArray, int numberOfMonsters, int* heroOriginalHP);

#endif
