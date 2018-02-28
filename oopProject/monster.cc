#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include "living.h"
#include "monster.h"
#include "enum_types.h"
#include "fightFunctions.h"

Monster::Monster(std::string nm, int lvl, int hp, int dR, int dfnc, int aglt, MonsterType tp) : Living(nm, lvl, hp), damageRange(dR), defence(dfnc), agility(aglt), type(tp){
  // std::cout << "\033[1;31mA monster was born...\033[0m" << std::endl;
}

Monster::Monster(const Monster &s):Living(s){
  damageRange=s.damageRange;
  defence=s.defence;
  agility=s.agility;
  type=s.type;
}

Monster::Monster():Living(){
  damageRange=-1;
  defence=-1;
  agility=-1;
  type=Spirit;
}

Monster::~Monster(){
  // std::cout << "\033[1;36mA monster died!\033[0m" << std::endl;
}

int Monster::getDamageRange() const {
  return damageRange;
}

int Monster::getDefence() const {
  return defence;
}

int Monster::getAgility() const {
  return agility;
}

MonsterType Monster::getType() const {
  return type;
}

void Monster::setDamageRange(int dR){
  damageRange = dR;
}

void Monster::setDefence(int dfnc){
  defence = dfnc;
}

void Monster::setAgility(int aglt){
  agility = aglt;
}

void Monster::setType(MonsterType tp){
  type = tp;
}

void Monster::print() const {
  std::cout << "\033[1;3;31m";
  Living::print();
  std::cout << "\033[0m";
  std::cout << "\033[1;31mis a Monster [";
  switch (type) {
    case Dragon : std::cout << "Dragon"; break;
    case Exoskeleton : std::cout << "Exoskeleton"; break;
    case Spirit : std::cout << "Spirit"; break;
  }
  std::cout << "] with the following stats:" << std::endl;
  std::cout << " Level:        " << getLevel() << std::endl;
  std::cout << " Health Power: " << getHealthPower() << std::endl;
  std::cout << " Attack:       " << damageRange << std::endl;
  std::cout << " Defence:      " << defence << std::endl;
  std::cout << " Agility:      " << agility << "\033[0m" << std::endl;
}

int Monster::attack(){
  srand(time(NULL));
  int damage;
  damage = randomMinToMax(damageRange - 1, damageRange + 1);
  return damage;
}
