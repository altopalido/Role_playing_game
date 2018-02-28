#include <iostream>
#include <string>
#include "living.h"
#include "enum_types.h"
#include "item.h"
#include "weapon.h"
#include "armor.h"

Living::Living(std::string nm, int lvl, int hp):name(nm), level(lvl), healthPower(hp){
  // std::cout << "A living being was born!" << std::endl;
}

Living::Living(const Living &a){
	name=a.name;
	level=a.level;
	healthPower=a.healthPower;
}

Living::Living(){
  level=-1;
  healthPower=-1;
  name="AAAAA";
}

Living::~Living(){
  // std::cout << "A living being died..." << std::endl;
}

std::string Living::getName() const {
  return name;
}

int Living::getLevel() const {
  return level;
}

int Living::getHealthPower() const {
  return healthPower;
}

void Living::setName(std::string nm){
  name = nm;
}

void Living::setLevel(int lvl){
  level = lvl;
}

void Living::setHealthPower(int hp){
  healthPower = hp;
}

void Living::print() const {
  std::cout << name << " ";
}


// virtual for monsters and heroes
int Living::getMagicPower() const{ return 0; //do nothing
}
int Living::getStrength() const{ return 0; //do nothing
}
int Living::getDexterity() const{ return 0; //do nothing
}
int Living::getMoney() const{ return 0; //do nothing
}
int Living::getExperience() const{ return 0; //do nothing
}
// HeroType Living::getType() const{ //do nothing
//}
void Living::setMagicPower(int mgcPwr){ //do nothing
}
void Living::setStrength(int strn){ //do nothing
}
void Living::setDexterity(int dxt){ //do nothing
}
void Living::setMoney(int gold){ //do nothing
}
void Living::setExperience(int xp){ //do nothing
}
void Living::setType(HeroType tp){ //do nothing
}
void Living::gainExperience(int xp) { // do nothing
}
void Living::levelUp(){ // do nothing
}
int Living::attack(){ return 0; // do nothing
}
void Living::castSpell(){ // do nothing
}
void Living::use(){ // do nothing
}
void Living::checkInventory(){ // do nothing
}
int Living::getHeroLengthOnGridArray() const{ return 0; // do nothing
}

int Living::getHeroWidthOnGridArray() const{ return 0; // do nothing
}
void Living::setHeroLengthOnGridArray(char addorSubtract){ // do nothing
}
void Living::setHeroWidthOnGridArray(char addorSubtract){ // do nothing
}

int Living::getAttack() const{ return 0; // do nothing
}
int Living::getDefence() const{ return 0; // do nothing
}
// MonsterType Living::getType() const{ // do nothing
//}
void Living::setAttack(int attck){ // do nothing
}
void Living::setDefence(int dfnc){ // do nothing
}
void Living::setType(MonsterType tp){ // do nothing
}
int Living::getAgility() const{ return 0; // do nothing
}
void Living::setAgility(int aglt){ // do nothing
}
// Weapon Living::getHoldingWeapon () const{ return NULL; //do nothing
// }
// Armor Living::getWearingArmor () const{ return NULL; //do nothing
// }
void Living::setHoldingWeapon (int numberOfWeapon){ // do nothing
}
void Living::setWearingWeapon (int numberOfArmor){ // do nothing
}
int Living::reducedDamage(){
  return 0;
}
