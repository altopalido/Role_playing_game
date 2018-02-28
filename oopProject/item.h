#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item{
private:
  std::string name;
  int cost;
  int minLevel;
public:
  // constructor
  Item(std::string nm, int cst, int minLvl);
  Item(const Item &a);
  Item();
  // destructor
  ~Item();
  // accessors
  std::string getName() const;
  int getCost() const;
  int getMinLevel() const;
  // mutators
  void setName(std::string nm);
  void setCost(int cost);
  void setMinLevel(int minLvl);
  // methods
  virtual void print() const;
  void printName() const;
};

#endif
