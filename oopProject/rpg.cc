#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include "item.h"
#include "weapon.h"
#include "armor.h"
#include "enum_types.h"
#include "potion.h"
#include "spell.h"
#include "living.h"
#include "hero.h"
#include "monster.h"
#include "grid.h"
#include "square.h"
#include "fightFunctions.h"


int userMenu(){
  unsigned int i = 0;
  int userOption;
  std::string yourOption = "Choose what to do:";
  std:: cout << "\033[1m" << yourOption << std::endl;
  for (i = 0 ; i < (yourOption).length() ; i++){
    std::cout << "-";
  }
  std::cout << std::endl;
  std::cout << "Press: 1. Move your hero(es)" << std::endl;
  std::cout << "       2. Display hero(es) stats" << std::endl;
  std::cout << "       3. Display grid" << std::endl;
  std::cout << "       4. Exit game\033[0m" << std::endl;
  std::cin >> userOption;
  return userOption;
}


int main (int argc, char* argv[]){
  bool fightResult;
  int i, heroType, numberOfHeroes, numberOfMonsters;
  std::string heroName;
  int userOption;

  if (argc == 2){
    numberOfHeroes = atoi(argv[1]);
    if (numberOfHeroes < 1 || numberOfHeroes > 3){
      std::cout << "The game supports 1-3 heroes for now!" << std::endl;
      return 1;
    }
  } else {
    std::cout << "Give the number of heroes as an argument!" << std::endl;
    return 1;
  }
  srand(time(NULL));

  Living **heroArray = new Living*[numberOfHeroes]; // allocate memory, else segmentation fault!!!
  for (i = 0 ; i < numberOfHeroes ; i++){  // initialize all pointers in array ; not necessery
    heroArray[i] = NULL;
  }

  numberOfMonsters = 1;
  Living **monsterArray = new Living*[numberOfMonsters]; // allocate memory, else segmentation fault!!!
  for (i = 0 ; i < numberOfMonsters ; i++){  // initialize all pointers in array ; not necessery
    monsterArray[i] = NULL;
  }

  // https://stackoverflow.com/questions/41952386/getline-removes-first-character-removal-of-cin-ignore-does-not-resolve
  std::string junk;
  for (i = 0 ; i < numberOfHeroes ; i++){
    std::cout << "Give hero values" << std::endl;
    std::cout << "Name: ";
    std::cin.clear(); // have to use cin.clear() else infinite loop
    // std::cin.ignore();
    getline(std::cin, heroName);
    do {
      std::cout << "Choose hero class (0: Warrior, 1:Sorcerer, 2:Paladin): ";
      std::cin >> heroType;
    } while((heroType != 0) && (heroType != 1) && (heroType != 2));
    if (heroType == 0) {
      heroArray[i] = new Hero(heroName, 1, 10, 6, 8, 6, 8, 0, 0, Warrior);
    } else if (heroType == 1) {
      heroArray[i] = new Hero(heroName, 1, 10, 6, 6, 8, 8, 0, 0, Sorcerer);
    } else {
      heroArray[i] = new Hero(heroName, 1, 10, 6, 8, 8, 6, 0, 0, Paladin);
    }
    heroArray[i]->print();
    // https://stackoverflow.com/questions/41952386/getline-removes-first-character-removal-of-cin-ignore-does-not-resolve
    getline(std::cin, junk);
  }

  grid grid1(6,10);
  grid1.displayMap();
  square square1(0,0);
  square* squareptr = &square1;

  // player chooses what to do
  do {
    do {
      userOption = userMenu();
      if ((userOption != 1) && (userOption != 2) && (userOption != 3) && (userOption != 4) && (userOption != 5)){
        std::cout << "Please make a valid choice!" << std::endl;
      }
    } while((userOption != 1) && (userOption != 2) && (userOption != 3) && (userOption != 4) && (userOption != 5));
    if (userOption == 1){
      squareptr = grid1.move(heroArray, numberOfHeroes);
      squareptr->print();
    } else if (userOption == 2){
      for (i = 0 ; i < numberOfHeroes ; i++) {
        heroArray[i]->print();
      }
    } else if (userOption == 3){
      grid1.displayMap();
    } else if (userOption == 4){
      // deleting with reverse order ; doesn't matter ; just to keep consistency
      for (i = numberOfHeroes-1 ; i > -1 ; i--) {
        delete heroArray[i];
      }
      std::cout << "Exiting game..." << std::endl;
      exit(0);
    }
  } while(true);


  // deleting with reverse order ; doesn't matter ; just to keep consistency
  for (i = numberOfHeroes-1 ; i > -1 ; i--) {
    delete heroArray[i];
  }

  return 0;
}
