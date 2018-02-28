#include <iostream>
#include <string>
#include "spell.h"
#include "enum_types.h"

Spell::Spell(std::string nm, int cst, int minLvl, int minDmg, int maxDmg, int mgcPwr, SpellType tp, int rdcAmnt, int rnds):name(nm), cost(cst), minLevel(minLvl), minDamage(minDmg), maxDamage(maxDmg), magicPower(mgcPwr), type(tp), reduceAmount(rdcAmnt), rounds(rnds){
  // std::cout << "A new spell was constructed!" << std::endl;
}

Spell::Spell(const Spell &a){
  name=a.name;
  cost=a.cost;
  minLevel=a.minLevel;
  minDamage=a.minDamage;
  maxDamage=a.maxDamage;
  magicPower=a.magicPower;
  type=a.type;
  reduceAmount=a.reduceAmount;
  rounds=a.rounds;
}

Spell::Spell(){
  name="AAAA";
  cost=-1;
  minLevel=-1;
  minDamage=-1;
  maxDamage=-1;
  magicPower=-1;
  type=IceSpell;
  reduceAmount=-1;
  rounds=-1;
}

Spell::~Spell(){
  // std::cout << "A spell was destroyed..." << std::endl;
}

std::string Spell::getName() const {
  return name;
}

int Spell::getCost() const {
  return cost;
}

int Spell::getMinLevel() const {
  return minLevel;
}

int Spell::getMinDamage() const {
  return minDamage;
}

int Spell::getMaxDamage() const {
  return maxDamage;
}

int Spell::getMagicPower() const {
  return magicPower;
}

SpellType Spell::getType() const {
  return type;
}

int Spell::getReduceAmount() const {
  return reduceAmount;
}

int Spell::getRounds() const {
  return rounds;
}

void Spell::setName(std::string nm){
  name = nm;
}

void Spell::setCost(int cst){
  cost = cst;
}

void Spell::setMinLevel(int minLvl){
  minLevel = minLvl;
}

void Spell::setMinDamage(int minDmg){
  minDamage = minDmg;
}

void Spell::setMaxDamage(int maxDmg){
  maxDamage = maxDmg;
}

void Spell::setMagicPower(int mgcPwr){
  magicPower = mgcPwr;
}

void Spell::setType(SpellType tp){
  type = tp;
}

void Spell::setReduceAmount(int rdcAmnt){
  reduceAmount = rdcAmnt;
}

void Spell::setRounds(int rnds){
  rounds = rnds;
}

void Spell::print() const {
  std::cout << name << " is ";
  switch (type) {
    case IceSpell : std::cout << "an Ice"; break;
    case FireSpell : std::cout << "a Fire"; break;
    case LightningSpell : std::cout << "a Lightning"; break;
  }
  std::cout << "Spell, costs " << cost << " units, requires minimum lvl" << minLevel <<
  ", minimum magic power " << magicPower << ", does damage between " << minDamage <<
  "HP and " << maxDamage << "HP and reduces ";
  switch (type) {
    case IceSpell : std::cout << "damage range"; break;
    case FireSpell : std::cout << "defence"; break;
    case LightningSpell : std::cout << "agility"; break;
  }
  std::cout << " by " << reduceAmount << " points for " << rounds << " rounds" << std::endl;
}

void Spell::printName() const {
  std::cout << name << " ";
}
