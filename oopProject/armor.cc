#include <iostream>
#include <string>
#include "item.h"
#include "armor.h"

Armor::Armor(std::string nm, int cst, int minLvl, int rdDmg) : Item(nm, cst, minLvl), reduceDamage(rdDmg){
  // std::cout << "A new armor was constructed!" << std::endl;
}

Armor::Armor(const Armor &s):Item(s){
	reduceDamage=s.reduceDamage;
}

Armor::Armor():Item(){
	reduceDamage=-1;
}

Armor::~Armor(){
  // std::cout << "An armor was destroyed..." << std::endl;
}

int Armor::getReduceDamage() const {
  return reduceDamage;
}

void Armor::setReduceDamage(int rdDmg){
  reduceDamage = rdDmg;
}

void Armor::print() const {
  Item::print();
  std::cout << "an armor that reduces received damage by " << reduceDamage << "HP" << std::endl;
}
