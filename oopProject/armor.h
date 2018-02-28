#ifndef ARMOR_H
#define ARMOR_H

#include <string>

class Armor : public Item {
private:
  int reduceDamage;
public:
  // constructors
  Armor(std::string nm, int cst, int minLvl, int rdDmg);
  Armor(const Armor &a);
  Armor();
  // destructor
  ~Armor();
  // accessors
  int getReduceDamage() const;
  // mutators
  void setReduceDamage(int dmg);
  // methods
  void print() const;
};

#endif
