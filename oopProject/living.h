#ifndef LIVING_H
#define LIVING_H

#include <string>
#include "enum_types.h"
#include "item.h"
#include "weapon.h"
#include "armor.h"

class Living{
private:
  std::string name;
  int level;
  int healthPower;
public:
  // constructors
  Living(std::string nm, int lvl, int hp);
  Living(const Living &a);
  Living();
  // destructor
  virtual ~Living();
  // accessors
  std::string getName() const;
  int getLevel() const;
  int getHealthPower() const;
  // mutators
  void setName(std::string nm);
  void setLevel(int lvl);
  void setHealthPower(int hp);
  // methods
  virtual void print() const;

  // virtual for hero
  virtual int getMagicPower() const;
  virtual int getStrength() const;
  virtual int getDexterity() const;
  virtual int getMoney() const;
  virtual int getExperience() const;
  // virtual HeroType getType() const;
  virtual void setMagicPower(int mgcPwr);
  virtual void setStrength(int strn);
  virtual void setDexterity(int dxt);
  virtual void setMoney(int gold);
  virtual void setExperience(int xp);
  virtual void setType(HeroType tp);
  virtual void gainExperience(int xp);
  virtual void levelUp();
  virtual int attack();
  virtual void castSpell();
  virtual void use();
  virtual void checkInventory();
  virtual int getHeroLengthOnGridArray() const;
  virtual int getHeroWidthOnGridArray() const;
  virtual void setHeroLengthOnGridArray(char addorSubtract);
  virtual void setHeroWidthOnGridArray(char addorSubtract);
//  virtual Weapon getHoldingWeapon () const;
//  virtual Armor getWearingArmor () const;
  virtual void setHoldingWeapon (int numberOfWeapon);
  virtual void setWearingWeapon (int numberOfArmor);
  virtual int reducedDamage();

  // virtual for monster
  virtual int getAttack() const;
  virtual int getDefence() const;
  // virtual MonsterType getType() const;
  virtual void setAttack(int attck);
  virtual void setDefence(int dfnc);
  virtual void setType(MonsterType tp);

  // virtual for both
  virtual int getAgility() const;
  virtual void setAgility(int aglt);
};

#endif
