#ifndef SPELL_H
#define SPELL_H

#include <string>
#include "enum_types.h"

class Spell{
private:
  std::string name;
  int cost;
  int minLevel;
  int minDamage;  // range of damage between
  int maxDamage;  // [minDamage, maxDamage]
  int magicPower;
  SpellType type;
  int reduceAmount;
  int rounds;
public:
  // constructors
  Spell(std::string nm, int cst, int minLvl, int minDmg, int maxDmg, int mgcPwrm, SpellType tp, int rdcAmnt, int rnds);
  Spell(const Spell &a);
  Spell();
  // destructor
  ~Spell();
  // accessors
  std::string getName() const;
  int getCost() const;
  int getMinLevel() const;
  int getMinDamage() const;
  int getMaxDamage() const;
  int getMagicPower() const;
  SpellType getType() const;
  int getReduceAmount() const;
  int getRounds() const;
  // mutators
  void setName(std::string nm);
  void setCost(int cost);
  void setMinLevel(int minLvl);
  void setMinDamage(int minDmg);
  void setMaxDamage(int maxDmg);
  void setMagicPower(int mgcPwr);
  void setType(SpellType tp);
  void setReduceAmount(int rdcAmnt);
  void setRounds(int rnds);
  // methods
  void print() const;
  void printName() const;
};

#endif
