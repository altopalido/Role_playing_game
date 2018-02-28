#ifndef POTION_H
#define POTION_H

#include <string>
#include "enum_types.h"

class Potion : public Item {
private:
  Statistic stat;
  int amount;
public:
  // constructor
  Potion(std::string nm, int cst, int minLvl, Statistic st, int amnt);
  Potion(const  Potion &a);
  Potion();
  // destructor
  ~Potion();
  // accessors
  Statistic getStat() const;
  int getAmount() const;
  // mutators
  void setStat(Statistic st);
  void setAmount(int amnt);
  // methods
  void print() const;
};

#endif
