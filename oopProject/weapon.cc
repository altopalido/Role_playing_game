#include <iostream>
#include <string>
#include "item.h"
#include "weapon.h"

Weapon::Weapon(std::string nm, int cst, int minLvl, int dmg, bool bH) : Item(nm, cst, minLvl), damage(dmg), bothHands(bH){
  // std::cout << "A new weapon was constructed!" << std::endl;
}

Weapon::Weapon(const Weapon &s):Item(s){
  damage=s.damage;
  bothHands=s.bothHands;
}

Weapon::Weapon():Item(){
  damage=-1;
  bothHands=true;
}

Weapon::~Weapon(){
  // std::cout << "A weapon was destroyed..." << std::endl;
}

int Weapon::getDamage() const {
  return damage;
}

bool Weapon::getBothHands() const {
  return bothHands;
}

void Weapon::setDamage(int dmg){
  damage = dmg;
}

void Weapon::setBothHands(bool bH){
  bothHands = bH;
}

void Weapon::print() const {
  Item::print();
  std::cout << "a weapon that inflicts " << damage << "HP damage and needs ";
  if (getBothHands()) std::cout << "both hands to hold it" << std::endl;
  else std::cout << "one hand to hold it" << std::endl;
}
