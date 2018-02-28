#ifndef GRID_H
#define GRID_H

#include <string>
#include "enum_types.h"
#include "square.h"
#include "hero.h"
#include <vector>
#include "weapon.h"

class grid{
private:
	int length;
	int width;
	square ***gridarray;
public:
	grid(int length,int width);
	//grid(const grid &a);
	//grid();
	~grid();
	square* move(Living** thisHero, int numberOfHeroes);
	void buyWeapon(Hero* thisHero,int thisItem);// o hrwas thisHero agorazei to antikeimeno pou vrisketai sth thesh thisItem
	void buyArmor(Hero* thisHero,int thisItem);
	void buySpell(Hero* thisHero,int thisItem);
	void buyPotion(Hero* thisHero,int thisItem);
	void sellWeapon(Hero* thisHero,int thisItem);
	void sellArmor(Hero* thisHero,int thisItem);
	void sellSpell(Hero* thisHero,int thisItem);
	void sellPotion(Hero* thisHero,int thisItem);
	void displayMap();
};




#endif
