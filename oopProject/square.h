#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include <string>
#include "enum_types.h"
#include "item.h"
#include "living.h"
#include "monster.h"
#include "weapon.h"
#include "spell.h"
#include "potion.h"
#include "armor.h"
#include <vector>
#include <cstdlib>
#include <sstream>
#include <time.h>
#include <stdlib.h>

class square{
private:
	int heroNum;
	int monsterNum;
	int squareRow;
	int squareColumn;
	SquareType SqrType;
	std::vector<Weapon> weapons; //vector pou krataei ta opla pou vriskontai pros pwlhsh
	std::vector<Spell> spells; //vector pou krataei ta spells pou vriskontai pros pwlhsh
	std::vector<Potion> potions;
	std::vector<Armor> armors;
	std::vector<Monster> monsters;
public:
	square(int row, int column);
	square(const square &a);
	//square();
	~square();
	int getHeroNum();
	int getMonsterNum();
	void setHeroNum(char addOrRemove);//prosthetei h afairei enan hrwa sto tetragwno
	void setMonsterNum(int num);
	void setSquareRow(int row);
	void setSquareColumn(int column);
	SquareType getSqrType();
	std::vector<Weapon>* getWeapons();
	std::vector<Spell>* getSpells();
	std::vector<Potion>* getPotions();
	std::vector<Armor>* getArmors();
	int getSquareRow();
	int getSquareColumn();
	void createMonsters(int monsterLevel, Living** thisHero, int numberOfHeroes);
	void createItemsForSell();
	void printWeaponsForSell();
	void printArmorsForSell();
	void printPotionsForSell();
	void printSpellsForSell();
	void printMonstersOnSquare();
	void print();
};

#endif
