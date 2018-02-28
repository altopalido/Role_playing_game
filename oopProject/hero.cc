#include <iostream>
#include <string>
#include "living.h"
#include "hero.h"
#include "enum_types.h"
#include "armor.h"
#include "weapon.h"

Hero::Hero(std::string nm, int lvl, int hp, int mgcPwr, int strn, int dxt, int aglt, int gold, int xp, HeroType tp) : Living(nm, lvl, hp), magicPower(mgcPwr), strength(strn), dexterity(dxt), agility(aglt), money(gold), experience(xp), type(tp){
  HeroLengthOnGridArray=0;
  HeroWidthOnGridArray=0; //arxika o hrwas vrisketai sto prwto tetragwno toy grid
  std::cout << "\033[1;32mA hero was born!\033[0m" << std::endl;
}

Hero::Hero(const Hero &s):Living(s){
    magicPower=s.magicPower;
    strength=s.strength;
    dexterity=s.dexterity;
    agility=s.agility;
    money=s.money;
    experience=s.experience;
    type=s.type;
    HeroLengthOnGridArray=s.HeroLengthOnGridArray;
    HeroWidthOnGridArray=s.HeroWidthOnGridArray;
}

Hero::Hero():Living(){
  magicPower=-1;
  strength=-1;
  dexterity=-1;
  agility=-1;
  money=-1;
  experience=-1;
  type=Paladin;
  HeroLengthOnGridArray=-1;
  HeroWidthOnGridArray=-1;
}

Hero::~Hero(){
  std::cout << "\033[1;31mA hero died...\033[0m" << std::endl;
}

int Hero::getMagicPower() const {
  return magicPower;
}

int Hero::getStrength() const {
  return strength;
}

int Hero::getDexterity() const {
  return dexterity;
}

int Hero::getAgility() const {
  return agility;
}

int Hero::getMoney() const {
  return money;
}

int Hero::getExperience() const {
  return experience;
}

HeroType Hero::getType() const {
  return type;
}

int Hero::getHeroLengthOnGridArray() const{
  return HeroLengthOnGridArray;
}

int Hero::getHeroWidthOnGridArray() const{
  return HeroWidthOnGridArray;
}

void Hero::setMagicPower(int mgcPwr){
  magicPower = mgcPwr;
}

void Hero::setStrength(int strn){
  strength = strn;
}

void Hero::setDexterity(int dxt){
  dexterity = dxt;
}

void Hero::setAgility(int aglt){
  agility = aglt;
}

void Hero::setMoney(int gold){
  money = gold;
}

void Hero::setExperience(int xp){
  experience = xp;
}

void Hero::setType(HeroType tp){
  type = tp;
}

void Hero::setHeroLengthOnGridArray(char addorSubtract){
  if(addorSubtract=='+'){
    HeroLengthOnGridArray=HeroLengthOnGridArray+1;  }
  if(addorSubtract=='-'){
    HeroLengthOnGridArray=HeroLengthOnGridArray-1;  }
}

void Hero::setHeroWidthOnGridArray(char addorSubtract){
  if(addorSubtract=='+'){
    HeroWidthOnGridArray=HeroWidthOnGridArray+1;  }
  if(addorSubtract=='-'){
    HeroWidthOnGridArray=HeroWidthOnGridArray-1;  }
}

void Hero::print() const {
  std::cout << "\033[1;3;32m";
  Living::print();
  std::cout << "\033[0m";
  std::cout << "\033[1;32mis a Hero [";
  switch (type) {
    case Warrior : std::cout << "Warrior"; break;
    case Sorcerer : std::cout << "Sorcerer"; break;
    case Paladin : std::cout << "Paladin"; break;
  }
  std::cout << "] with the following stats:\033[0m" << std::endl;
  printStats();
}

void Hero::printStats() const {
  std::cout << " \033[1;32mLevel:        " << getLevel() << std::endl;
  std::cout << " Health Power: " << getHealthPower() << std::endl;
  std::cout << " Magic Power:  " << magicPower << std::endl;
  std::cout << " Strength:     " << strength << std::endl;
  std::cout << " Dexterity:    " << dexterity << std::endl;
  std::cout << " Agility:      " << agility << std::endl;
  std::cout << " Money:        " << money << std::endl;
  std::cout << " Experience:   " << experience << "\033[0m" << std::endl;
}

void Hero::gainExperience(int xp) {
  experience+=xp;
  std::cout << getName() << " gain +" << xp << "xp and now has " << experience << "xp" << std::endl;
}

// LEVEL UP policy:
// Level 1: <50xp
// Level 1 -> Level 2: >=50xp AND <100xp
// Level 2 -> Level 3: >=100xp AND <150xp
// Level 3 -> Level 4: >=150xp AND <200xp
// Level 4 -> Level 5: >=200xp AND <250xp...
void Hero::levelUp() {
  setLevel(getLevel()+1);
  setHealthPower(getHealthPower()+5);
  std::cout <<  "\033[1;32m" << getName() << " LEVEL UP!" << "\033[0m";
  magicPower+=2;
  strength+=3;
  dexterity+=3;
  agility+=3;
  switch (type) {
    case Warrior:
      strength+=2;
      agility+=2;
      break;
    case Sorcerer:
      dexterity+=2;
      agility+=2;
      break;
    case Paladin:
      strength+=2;
      dexterity+=2;
      break;
  }
  std::cout << " New stats:" << std::endl;
  printStats();
}

std::vector<Weapon>* Hero::getOwnWeapons(){
  return &ownWeapons;
}

std::vector<Spell>* Hero::getOwnSpells(){
  return &ownSpells;
}

std::vector<Potion>* Hero::getOwnPotions(){
  return &ownPotions;
}

std::vector<Armor>* Hero::getOwnArmors(){
  return &ownArmors;
}

int Hero::attack(){
  int damage;
  damage = strength + holdingWeapon.getDamage();
  return damage;
}

void Hero::castSpell(){
  unsigned int i;
  unsigned int j;
  unsigned int spellToUse = 0;

  if (ownSpells.size() == 0){
    std::cout << getName() << " has no spells!" << std::endl;
  } else {
    j=ownSpells.size();
    std::cout << getName() << " spells are: " << std::endl;
    for(i=0;i<j;i++){
      std::cout << i << ". ";
      ownSpells.at(i).print();
      std::cout<<std::endl;
    }
    do {
      std::cout << "Use spell: ";
      std::cin >> spellToUse;
      if ((spellToUse < 0) && (spellToUse > ownSpells.size())){
        std::cout << "That's not a valid choice!" << std::endl;
      }
    } while((spellToUse < 0) && (spellToUse > ownSpells.size()));
    // xrisi tou spell - den exei ulopoih8ei plirws
  }
}

void Hero::use(){
  unsigned int i;
  unsigned int j;
  unsigned int potionToUse = 0;

  if (ownPotions.size() == 0){
    std::cout << getName() << " has no potions!" << std::endl;
  } else {
    j=ownPotions.size();
    std::cout << getName() << " potions are: " << std::endl;
    for(i=0;i<j;i++){
      std::cout << i << ". ";
      ownPotions.at(i).print();
      std::cout<<std::endl;
    }
    do {
      std::cout << "Use potion: ";
      std::cin >> potionToUse;
      if ((potionToUse < 0) && (potionToUse > ownPotions.size())){
        std::cout << "That's not a valid choice!" << std::endl;
      }
    } while((potionToUse < 0) && (potionToUse > ownPotions.size()));
    // xrisi tou potion - den exei ulopoih8ei plirws
  }
}

void Hero::checkInventory(){
    unsigned int i;
    unsigned int j;

    if (ownWeapons.size() == 0){
      std::cout << getName() << " has no weapons!" << std::endl;
    } else {
      j=ownWeapons.size();
      std::cout << getName() << " weapons are: " << std::endl;
      for(i=0;i<j;i++){
        ownWeapons.at(i).print();
        std::cout<<std::endl;
      }
    }

    if (ownArmors.size() == 0){
      std::cout << getName() << " has no armors!" << std::endl;
    } else {
      j=ownArmors.size();
      std::cout << getName() << " armors are: " << std::endl;
      for(i=0;i<j;i++){
        ownArmors.at(i).print();
        std::cout<<std::endl;
      }
    }

    if (ownPotions.size() == 0){
      std::cout << getName() << " has no potions!" << std::endl;
    } else {
      j=ownPotions.size();
      std::cout << getName() << " potions are: " << std::endl;
      for(i=0;i<j;i++){
        ownPotions.at(i).print();
        std::cout<<std::endl;
      }
    }

    if (ownSpells.size() == 0){
      std::cout << getName() << " has no spells!" << std::endl;
    } else {
      j=ownSpells.size();
      std::cout << getName() << " spells are: " << std::endl;
      for(i=0;i<j;i++){
        ownSpells.at(i).print();
        std::cout<<std::endl;
      }
    }
}

Weapon Hero::getHoldingWeapon () const{
  return holdingWeapon;
}
Armor Hero::getWearingArmor () const{
  return wearingArmor;
}

int Hero::reducedDamage(){
  return wearingArmor.getReduceDamage();
}

void Hero::setHoldingWeapon (int numberOfWeapon){
  holdingWeapon = ownWeapons.at(numberOfWeapon);
}
void Hero::setWearingWeapon (int numberOfArmor){
  wearingArmor = ownArmors.at(numberOfArmor);
}
