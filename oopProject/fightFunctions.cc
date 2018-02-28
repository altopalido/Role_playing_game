#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "fightFunctions.h"
#include "hero.h"
#include "monster.h"

int showOptions(Living* hero){
  unsigned int i = 0;
  int playerOption;
  std::string output = "It's hero(es) move!";
  std::cout << "\033[1;35m" << output << std::endl;
  for (i = 0 ; i < output.length() ; i++){
    std::cout << "-";
  }
  std::cout << std::endl;
  std::cout << "Press: 1. Attack" << std::endl;
  std::cout << "       2. Cast a spell" << std::endl;
  std::cout << "       3. Use potion" << std::endl;
  std::cout << "       4. Change weapons - armor" << std::endl;
  std::cout << "       5. Check inventory" << std::endl;
  std::cout << "       6. Display hero(es) & monster(s) stats" << std::endl;
  std::cout << "       7. Exit game\033[0m" << std::endl;
  std::cin >> playerOption;
  return playerOption;
}


int randomMinToMax (int min, int max){
  int i = max - min + 1;
	return rand()%i+min;
}


// if agility <= 10: success attack 100%
// else if agility <= 20: success attack 90% - avoid attack 10%
// else if agility <= 30: success attack 80% - avoid attack 20%
// else if agility <= 40: success attack 70% - avoid attack 30%
// else if agility <= 60: success attack 60% - avoid attack 40%
// else: success 50% - avoid attack 50%
bool avoidAttack(Living* livingBeing){
  srand(time(NULL));
  int randResult;
  if (livingBeing->getAgility() <= 10) {
    return false;
  } else {
    randResult = randomMinToMax(1,10);
    if (livingBeing->getAgility() <= 20) {
      if (randResult > 9) return true;
    } else if (livingBeing->getAgility() <= 30) {
      if (randResult > 8) return true;
    } else if (livingBeing->getAgility() <= 40) {
      if (randResult > 7) return true;
    } else if (livingBeing->getAgility() <= 60){
      if (randResult > 6) return true;
    } else {
      if (randResult > 5) return true;
    }
    return false;
  }
}


// True: heroes won, False: monster won
bool fight (Living** heroArray, int numberOfHeroes, Living** monsterArray, int numberOfMonsters){
  int i;
  int damage;
  bool avoid;
  int *initialHeroHP = new int[numberOfHeroes];
  int *initialHeroMP = new int[numberOfHeroes];
  for (i = 0 ; i < numberOfHeroes ; i++){
    initialHeroHP[i] = heroArray[i]->getHealthPower();
    initialHeroMP[i] = heroArray[i]->getMagicPower();
  }
  int *initialMonsterHP = new int[numberOfMonsters];
  for (i = 0 ; i < numberOfMonsters ; i++){
    initialMonsterHP[i] = monsterArray[i]->getHealthPower();
  }
  int heroToAttack = 0;
  int monsterToBeAttacked = 0;
  int monsterToAttack = 0;
  int heroToBeAttacked = 0;
  int totalHeroHP = 0;

  do {
    int playerOption;
    for (i = 0 ; i < numberOfHeroes ; i++){
      // Regenerate hp heroes setHealthPower(round(0.2*initialHeroHP + getHealthPower))
      // we regenerate 20% of initial HP every round
      if ((heroArray[i]->getHealthPower() < initialHeroHP[i]) && (heroArray[i]->getHealthPower() != 0)){
        if (round(0.2*initialHeroHP[i] + heroArray[i]->getHealthPower()) > initialHeroHP[i]) heroArray[i]->setHealthPower(initialHeroHP[i]);
        else heroArray[i]->setHealthPower(round(0.2*initialHeroHP[i] + heroArray[i]->getHealthPower()));
      }

      // Regenerate mp hero - same logic
      if ((heroArray[i]->getMagicPower() < initialHeroMP[i]) && (heroArray[i]->getHealthPower() != 0)){
        if (round(0.2*initialHeroMP[i] + heroArray[i]->getMagicPower()) > initialHeroMP[i]) heroArray[i]->setMagicPower(initialHeroMP[i]);
        else heroArray[i]->setMagicPower(round(0.2*initialHeroMP[i] + heroArray[i]->getMagicPower()));
      }
    }

    for (i = 0 ; i < numberOfMonsters ; i++){
      // Regenerate hp monsters - same logic
      if ((monsterArray[i]->getHealthPower() < initialMonsterHP[i])  && (monsterArray[i]->getHealthPower() != 0)){
        if (round(0.2*initialMonsterHP[i] + monsterArray[i]->getHealthPower()) > initialMonsterHP[i]) monsterArray[i]->setHealthPower(initialMonsterHP[i]);
        else monsterArray[i]->setHealthPower(round(0.2*initialMonsterHP[i] + monsterArray[i]->getHealthPower()));
      }
    }

    do {
      do{
        playerOption = showOptions(heroArray[0]);
        if ((playerOption != 1) && (playerOption != 2) && (playerOption != 3) && (playerOption != 4) && (playerOption != 5) && (playerOption != 6) && (playerOption != 7)){
          std::cout << "Please choose a valid move!" << std::endl;
        }
      } while ((playerOption != 1) && (playerOption != 2) && (playerOption != 3) && (playerOption != 4) && (playerOption != 5) && (playerOption != 6) && (playerOption != 7));

        // PLAYER'S MOVE
        if (playerOption == 1){
          // for multiple heroes - multiple monsters
          if (numberOfHeroes > 1){
            do {
              std::cout << "\033[1;35mWhich hero do you want to attack?" << std::endl;
              std::cout << "Press:" << std::endl;
              for (i = 0 ; i < numberOfHeroes ; i++){
                if (heroArray[i]->getHealthPower()){
                  std::cout << i << ". " << heroArray[i]->getName() << std::endl;
                }
              }
              std::cin >> heroToAttack;
              if ((heroToAttack < 0) || (heroToAttack > numberOfHeroes-1)) {
                std::cout << "Please choose an existing hero!" << std::endl;
              }
            } while((heroToAttack < 0) || (heroToAttack > numberOfHeroes-1));
            std::cout << "\033[0m";
          }
          if (numberOfMonsters > 1){
            do {
              std::cout << "\033[1;35mWhich monster do you want to get attacked?" << std::endl;
              std::cout << "Press:" << std::endl;
              for (i = 0 ; i < numberOfMonsters ; i++){
                if (monsterArray[i]->getHealthPower() > 0){ // monster already dead - cannot get attacked
                  std::cout << i << ". " << monsterArray[i]->getName() << std::endl;
                }
              }
              std::cin >> monsterToBeAttacked;
              if ((monsterToBeAttacked < 0) || (monsterToBeAttacked > numberOfMonsters-1)) {
                std::cout << "Please choose an existing monster!" << std::endl;
              }
            } while((monsterToBeAttacked < 0) || (monsterToBeAttacked > numberOfMonsters-1));
            std::cout << "\033[0m";
          }

          damage = heroArray[heroToAttack]->attack() - monsterArray[monsterToBeAttacked]->getDefence();
          avoid = avoidAttack(monsterArray[monsterToBeAttacked]);
          if (damage <= 0 ){
            avoid = true;
          }
          if (!(avoid)){
            std::cout << heroArray[heroToAttack]->getName() << " hits " << monsterArray[monsterToBeAttacked]->getName() << "!" << std::endl;
            monsterArray[monsterToBeAttacked]->setHealthPower((monsterArray[monsterToBeAttacked]->getHealthPower() - damage));
            if (monsterArray[monsterToBeAttacked]->getHealthPower() < 0){
              monsterArray[monsterToBeAttacked]->setHealthPower(0);
            }
            std::cout << monsterArray[monsterToBeAttacked]->getName() << " has " << monsterArray[monsterToBeAttacked]->getHealthPower() << "HP" <<std::endl;
          } else {
            std::cout << monsterArray[monsterToBeAttacked]->getName() << " avoided the attack!" << std::endl;
          }
        } else if (playerOption == 2){
          heroArray[0]->castSpell(); // not fully completed
        } else if (playerOption == 3){
          heroArray[0]->use(); // not fully completed
        } else if (playerOption == 4){
          // change weapon - armor - not fully completed
        } else if (playerOption == 5){
          for (i = 0 ; i < numberOfHeroes ; i++) {
            heroArray[i]->checkInventory();
          }
        } else if (playerOption == 6){
          for (i = 0 ; i < numberOfHeroes ; i++) {
            heroArray[i]->print();
          }
          for (i = 0 ; i < numberOfMonsters ; i++) {
            monsterArray[i]->print();
          }
        } else if (playerOption == 7){
          // deleting with reverse order ; doesn't matter ; just to keep consistency
          for (i = numberOfHeroes-1 ; i > -1 ; i--) {
            delete heroArray[i];
          }
          std::cout << "Exiting game..." << std::endl;
          exit(0);
        }
      } while((playerOption != 1) && (playerOption != 2) && (playerOption != 3) && (playerOption != 4));

      int totalMonstersHP = 0;
      for (i = 0 ; i < numberOfMonsters ; i++){
        totalMonstersHP = totalMonstersHP + monsterArray[i]->getHealthPower();
      }
      if (totalMonstersHP == 0){
        return true; // fight is over - hero win
      }

      // MONSTER ATTACK
      // multiple monsters - multiple heroes
      if (numberOfMonsters > 1){
        do {
          monsterToAttack = randomMinToMax(0, numberOfMonsters-1);
        } while(monsterArray[monsterToAttack]->getHealthPower() == 0);
      }
      if (numberOfHeroes > 1){
        do {
          heroToBeAttacked = randomMinToMax(0, numberOfHeroes-1);
        } while(heroArray[heroToBeAttacked]->getHealthPower() == 0);
      }
      damage = monsterArray[monsterToAttack]->attack() - heroArray[heroToBeAttacked]->reducedDamage(); // subtract hero's armor!!!
      avoid = avoidAttack(heroArray[heroToBeAttacked]);
      if (!(avoid)){
        std::cout << monsterArray[monsterToAttack]->getName() << " hits " << heroArray[heroToBeAttacked]->getName() << "!" << std::endl;
        heroArray[heroToBeAttacked]->setHealthPower((heroArray[heroToBeAttacked]->getHealthPower() - damage));
        if (heroArray[heroToBeAttacked]->getHealthPower() < 0){ // if heroes' HP < 0 then is equal to 0 - no negative HP
          heroArray[heroToBeAttacked]->setHealthPower(0);
        }
        std::cout << heroArray[heroToBeAttacked]->getName() << " has " << heroArray[heroToBeAttacked]->getHealthPower() << "HP" <<std::endl;
      } else {
        std::cout << heroArray[heroToBeAttacked]->getName() << " avoided the attack!" << std::endl;
      }
      // check if all heroes have 0HP
      totalHeroHP = 0;
      for (i = 0 ; i < numberOfHeroes ; i++){
        totalHeroHP = totalHeroHP + heroArray[i]->getHealthPower();
      }
  } while(totalHeroHP > 0);
  return false; // fight is over - monster win
}


void afterFight(int fightResult, Living** heroArray, int numberOfHeroes, Living** monsterArray, int numberOfMonsters, int* heroOriginalHP){
  int i, maxMonsterLevel, experienceToGain, moneyToGain;

  if (fightResult){
    std::cout << "Hero(es) won the fight!!!" << std::endl;

    maxMonsterLevel = monsterArray[0]->getLevel();
    for (i = 1 ; i < numberOfMonsters ; i++){
      if (monsterArray[i]->getLevel() > maxMonsterLevel){
        maxMonsterLevel = monsterArray[i]->getLevel();
      }
    }

    int beforeFightHeroLevel[numberOfHeroes]; // for better input ; if it levels up don't print again
    for (i = 0 ; i < numberOfHeroes ; i++){
      beforeFightHeroLevel[i] = heroArray[i]->getLevel();
      // ours money policy
      moneyToGain = (50*numberOfMonsters + 5*(maxMonsterLevel - heroArray[i]->getLevel()))/numberOfHeroes;
      heroArray[i]->setMoney(heroArray[i]->getMoney() + moneyToGain);

      // ours xp policy
      experienceToGain = 20*numberOfMonsters + 2*(maxMonsterLevel - heroArray[i]->getLevel());
      heroArray[i]->gainExperience(experienceToGain);
      // A hero must be able to level up multiple times if the amount of xp
      // received from a battle allows that
      while (heroArray[i]->getExperience() >= 50 * heroArray[i]->getLevel() ){
        heroArray[i]->levelUp();
      }
      if (beforeFightHeroLevel[i] == heroArray[i]->getLevel()){
              heroArray[i]->print();
      }
    }
  } else {
    std::cout << "Monster(s) won the fight..." << std::endl;
    for (i = 0 ; i < numberOfHeroes ; i++){
      heroArray[i]->setMoney(heroArray[i]->getMoney()/2);
      heroArray[i]->setHealthPower(heroOriginalHP[i]/2);
    }
  }
}
