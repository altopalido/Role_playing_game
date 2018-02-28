#include <iostream>
#include <string>
#include "item.h"
#include "enum_types.h"
#include "potion.h"

Potion::Potion(std::string nm, int cst, int minLvl, Statistic st, int amnt) : Item(nm, cst, minLvl), stat(st), amount(amnt){
  // std::cout << "A new potion was constructed!" << std::endl;
}

Potion::Potion(const Potion &s):Item(s){
  stat=s.stat;
  amount=s.amount;
}

Potion::Potion():Item(){
  amount=-1;
  stat=strength;
}

Potion::~Potion(){
  // std::cout << "A potion was destroyed..." << std::endl;
}

Statistic Potion::getStat() const {
  return stat;
}

int Potion::getAmount() const {
  return amount;
}

void Potion::setStat(Statistic st){
  stat = st;
}

void Potion::setAmount(int amnt){
  amount = amnt;
}

void Potion::print() const {
  Item::print();
  std::cout << "a potion that raises ";
  switch (stat) {
    case healthPower : std::cout << "HP"; break;
    case strength : std::cout << "strength"; break;
    case dexterity : std::cout << "dexterity"; break;
    case agility : std::cout << "agility"; break;
    case magicPower : std::cout << "magicPower"; break;
  }
  std::cout << " by " << amount << " points" << std::endl;
}
