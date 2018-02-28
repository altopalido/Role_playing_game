#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon : public Item {
private:
  int damage;
  bool bothHands;
public:
  // constructors
  Weapon(std::string nm, int cst, int minLvl, int dmg, bool bH);
  Weapon(const Weapon &a);
  Weapon();
  // destructor
  ~Weapon();
  // accessors
  int getDamage() const;
  bool getBothHands() const;
  // mutators
  void setDamage(int dmg);
  void setBothHands(bool bH);
  // methods
  void print() const;
};

#endif
