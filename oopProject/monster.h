#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include "enum_types.h"

class Monster : public Living {
private:
  int damageRange;
  int defence;
  int agility;
  MonsterType type;
public:
  // constructors
  Monster(std::string nm, int lvl, int hp, int dR, int dfnc, int aglt, MonsterType tp);
  Monster(const Monster &a);
  Monster();
  // destructor
  ~Monster();
  // accessors
  int getDamageRange() const;
  int getDefence() const;
  int getAgility() const;
  MonsterType getType() const;
  // mutators
  void setDamageRange(int dR);
  void setDefence(int dfnc);
  void setAgility(int aglt);
  void setType(MonsterType tp);
  // methods
  void print() const;
  int attack();
};

#endif
