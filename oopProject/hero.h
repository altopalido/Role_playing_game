#ifndef HERO_H
#define HERO_H

#include <string>
#include "enum_types.h"
#include "living.h"
#include "item.h"
#include "weapon.h"
#include "spell.h"
#include "potion.h"
#include "armor.h"
#include <vector>


class Hero : public Living {
private:
  int magicPower; // maximum Magic Power
  int strength;
  int dexterity;
  int agility;
  int money;
  int experience;
  int HeroLengthOnGridArray;
  int HeroWidthOnGridArray;
  Weapon holdingWeapon;
  Armor wearingArmor;
  HeroType type;
  std::vector<Weapon> ownWeapons; //vector pou krataei ta opla pou katexei o hrwas
  std::vector<Spell> ownSpells; //vector pou krataei ta spells pou katexei o hrwas
  std::vector<Potion> ownPotions;
  std::vector<Armor> ownArmors;
public:
  // constructors
  Hero(std::string nm, int lvl, int hp, int mgcPwr, int strn, int dxt, int aglt, int gold, int xp, HeroType tp);
  Hero(const Hero &a);
  Hero();
  // destructor
  ~Hero();
  // accessors
  int getMagicPower() const;
  int getStrength() const;
  int getDexterity() const;
  int getAgility() const;
  int getMoney() const;
  int getExperience() const;
  HeroType getType() const;
  int getHeroLengthOnGridArray() const;
  int getHeroWidthOnGridArray() const;
  Weapon getHoldingWeapon () const;
  Armor getWearingArmor () const;
  // mutators
  void setMagicPower(int mgcPwr);
  void setStrength(int strn);
  void setDexterity(int dxt);
  void setAgility(int aglt);
  void setMoney(int gold);
  void setExperience(int xp);
  void setType(HeroType tp);
  void setHeroLengthOnGridArray(char addorSubtract);
  void setHeroWidthOnGridArray(char addorSubtract);
  void setHoldingWeapon (int numberOfWeapon);
  void setWearingWeapon (int numberOfArmor);
  // methods
  void print() const;
  void printStats() const;
  void gainExperience(int xp);
  void levelUp();
  std::vector<Weapon>* getOwnWeapons();
  std::vector<Spell>* getOwnSpells();
  std::vector<Potion>* getOwnPotions();
  std::vector<Armor>* getOwnArmors();
  int attack();
  void castSpell();
  void use();
  void checkInventory();
  int reducedDamage();
};

#endif
