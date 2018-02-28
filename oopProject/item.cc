#include <iostream>
#include <string>
#include "item.h"

Item::Item(std::string nm, int cst, int minLvl):name(nm),cost(cst),minLevel(minLvl){
  // std::cout << "A new item was constructed!" << std::endl;
}

Item::Item(const Item &a){
  name=a.name;
  cost=a.cost;
  minLevel=a.minLevel;
}

Item::Item(){
  name="AAAA";
  cost=-1;
  minLevel=-1;
}

Item::~Item(){
  //std::cout << "An item was destroyed..." << std::endl;
}

std::string Item::getName() const {
  return name;
}

int Item::getCost() const {
  return cost;
}

int Item::getMinLevel() const {
  return minLevel;
}

void Item::setName(std::string nm){
  name = nm;
}

void Item::setCost(int cst){
  cost = cst;
}

void Item::setMinLevel(int minLvl){
  minLevel = minLvl;
}

void Item::print() const {
  std::cout << name << " costs " << cost << " units, requires minimum lvl" << minLevel << " to use it and is ";
}

void Item::printName() const {
  std::cout << name << " ";
}
