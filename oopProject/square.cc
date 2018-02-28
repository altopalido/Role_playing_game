#include "enum_types.h"
#include "square.h"
#include "fightFunctions.h"


square::square(int row, int column){
	// srand(time(NULL));
	heroNum=0;
	monsterNum=0;
	// std::cout<<"A new square was created"<<std::endl;
	squareRow = row;
	squareColumn = column;
	// the squares of diagonal (from [0,0]) and the squares at [0,1], [1,0] are not nonAccessible
	if ((row == 0 && column ==1) || (row == 1 && column ==0) || (row == column)){
		SqrType=static_cast<SquareType>(randomMinToMax(1,2));
	}
	else {
		SqrType=static_cast<SquareType>(randomMinToMax(0,2));
	}
}

square::square(const square &a){
	heroNum=a.heroNum;
	monsterNum=a.monsterNum;
	SqrType=a.SqrType;
}

/*square::square(){
	heroNum=-1;
	monsterNum=-1;
	sqrType=market;
}*/

square::~square(){
	// std::cout<<"A square was destroyed"<<std::endl;
}

int square::getHeroNum(){
	return heroNum;
}

int square::getMonsterNum(){
	return monsterNum;
}

void square::setHeroNum(char addOrRemove){
  if(heroNum>3)
  	std::cout<<"Hero does not fit in this square"; //to tetragwno xwraei mexri 3 hrwes
  else
  	if(addOrRemove=='+'){
  		heroNum=heroNum+1;
	}
	if(addOrRemove=='-'){
		if(heroNum!=0)
			heroNum=heroNum-1;
		else if(heroNum==0)
			heroNum=0;
	}
}

void square::setMonsterNum(int num){
	monsterNum=num;
}

SquareType square::getSqrType(){
	return SqrType;
}

std::vector<Weapon>* square::getWeapons(){
	return &weapons;
}

std::vector<Spell>* square::getSpells(){
	return &spells;
}

std::vector<Potion>* square::getPotions(){
	return &potions;
}

std::vector<Armor>* square::getArmors(){
	return &armors;
}

void square::createMonsters(int monsterLevel, Living** heroArray, int numberOfHeroes){
	srand(time(NULL));
	bool fightResult;
	std::stringstream ss;
	int i;
	int numberOfMonsters;
	numberOfMonsters = 1+rand()%3;
	//******* pinakes gia apothhkeush twn tuxewn arxikopoihsewn twn antikeimenwn *******
	std::string monsterName_array[numberOfMonsters];
	int level_array[numberOfMonsters];
	//int hp_array[3];
	//int damageRange_array[3];
	//int defence_array[3];
	//int agility_array[3];
	MonsterType monsterType_array[numberOfMonsters];
	// **********
	// Monster* monstersOnSquare = new Monster[3]; //pinakas me monsters pou dhmhourghthhkan me tuxaia xarakthristika
	// **********
	if(SqrType==common){
		Monster monsterArray[numberOfMonsters];
		monsterNum=numberOfMonsters;
		for(i=0;i<numberOfMonsters;i++){
			//std::cout<<"eimai edw"<<std::endl;
			if(monsterLevel>2) //an to level den ginetai mikrotero tou 1
				level_array[i]=randomMinToMax(monsterLevel-2, monsterLevel+2); //rand from monsterLevel-2 to monsterLevel+2
			else // an to level ginetai mikrotero tou 1
				level_array[i]=1;
			ss<<(1+(rand()%100));
			std::string str=ss.str();
			monsterName_array[i]="Monster " + str;
			ss.str("");//katharisma
			monsterType_array[i]=static_cast<MonsterType>(rand()%3);
			//std::cout<<"eimai edw"<<std::endl;
			//std::cout<<monsterType_array[i]<<std::endl;
			//Monster thisMonster(monsterName_array[i],level_array[i],5*monsterLevel,3*monsterLevel,3*monsterLevel+monsterLevel,2*monsterLevel,monsterType_array[i]);

			//----------------------
			// Monster create policy
			//----------------------
			// hp = 5*monsterLevel
			// damage range = 3 * level
			// defence = level
			// agility = 5 + 3 * level
			// + to extra opou xreiazetai
			Monster thisMonster(monsterName_array[i], level_array[i], 5 * monsterLevel, 3 * monsterLevel, monsterLevel, 5 + 3 * monsterLevel,monsterType_array[i]);
			monsterArray[i] = thisMonster;
			if(monsterType_array[i]==Dragon){
				//std::cout<<"edw"<<std::endl;
				monsterArray[i].setType(Dragon);
				monsterArray[i].setDamageRange(monsterArray[i].getDamageRange() + monsterArray[i].getLevel());
			}
			else if(monsterType_array[i]==Exoskeleton){
				//std::cout<<"edww"<<std::endl;
				monsterArray[i].setType(Exoskeleton);
				monsterArray[i].setDefence(monsterArray[i].getDefence() + monsterArray[i].getLevel());
			}
			else if(monsterType_array[i]==Spirit){
				//std::cout<<"edwww"<<std::endl;
				monsterArray[i].setType(Spirit);
				monsterArray[i].setAgility(monsterArray[i].getAgility() + monsterArray[i].getLevel());
			}
			monsters.push_back(monsterArray[i]);
		}
		Living **livingArray = new Living*[numberOfMonsters]; // allocate memory, else segmentation fault!!!
	  for (i = 0 ; i < numberOfMonsters ; i++){
	    livingArray[i] = &monsterArray[i];
	  }

		// store original HP in case heroes lose the fight
		int *heroOriginalHP = new int[numberOfHeroes];
		for (i = 0 ; i < numberOfHeroes ; i++){
	    heroOriginalHP[i] = heroArray[i]->getHealthPower();
	  }
		fightResult = fight(heroArray, numberOfHeroes, livingArray, numberOfMonsters);
		afterFight(fightResult, heroArray, numberOfHeroes, livingArray, numberOfMonsters, heroOriginalHP);
	}

}

void square::createItemsForSell(){
	srand(time(NULL));
	std::stringstream ss;
	int i;
	//******* pinakes gia apothhkeush twn tuxewn arxikopoihsewn twn antikeimenwn *******
	int cost_array[50];
	int minLevel_array[50];
	int damage_array[50];
	bool bothHands_array[50];
	int reduceDamage_array[50];
	int amount_array[50];
	Statistic statistic_array[50];
	SpellType spellType_array[50];
	int magicPower_array[50];
	int rounds_array[50];
	int minDamage_array[50];
	int maxDamage_array[50];
	std::string itemName_array[50];
	// **********
	Weapon weaponsForSell[50]; //pinakas me opla pou dhmiourghthhkan tuxaia
	Armor armorsForSell[50]; //pinakas me armors pou dhmiourghthhkan tuxaia
	Potion potionsForSell[50]; //pinakas me potions pou dhmiourghthkan tuxaia
	Spell spellsForSell[50]; //pinakas me spells pou dhmiourghthhkan tuxaia
	// **********
	//std::cout<<std::endl;
	if(SqrType==market){ //an to square einai market tha gemisoume tous vectors me ta antikeimena pou diatithentai pros pwlhsh
		for(i=0;i<50;i++){
			//std::cout << i<<std::endl;
			cost_array[i]=randomMinToMax(2,100);//random cost from 2-100
			minLevel_array[i]=randomMinToMax(cost_array[i]/2, cost_array[i]/2 + 5); // level depends on cost
			damage_array[i]=randomMinToMax(minLevel_array[i], minLevel_array[i] + 2); // damage depends on level
			bothHands_array[i]=static_cast<bool>(rand()%2);
			ss<<(1+(rand()%100));
			std::string str=ss.str();
			itemName_array[i]="Weapon " + str;
			ss.str("");//katharisma
			Weapon weaponToSell(itemName_array[i],cost_array[i],minLevel_array[i],damage_array[i],bothHands_array[i]);
			weaponsForSell[i]=weaponToSell;
			//weaponsForSell[i].print();
			//std::cout<<std::endl;
			//std::cout<<sizeof(weapons.at(0))<<std::endl<<std::endl;
			weapons.push_back(weaponsForSell[i]);
			//weapons.at(i).print();
		}//gemisame ton vector twn oplwn me 50 opla pros pwlhsh me tuxaia xarakthristika

		for(i=0;i<50;i++){
			//std::cout << i<<std::endl;
			cost_array[i]=randomMinToMax(2,100);//random cost from 2-100
			minLevel_array[i]=randomMinToMax(cost_array[i]/2, cost_array[i]/2 + 5); // level depends on cost
			reduceDamage_array[i]=randomMinToMax(minLevel_array[i], minLevel_array[i] + 2); // damage depends on level
			ss<<(1+(rand()%100));
			std::string str=ss.str();
			itemName_array[i]="Armor " + str;
			ss.str("");//katharisma
			Armor armorToSell(itemName_array[i],cost_array[i],minLevel_array[i],reduceDamage_array[i]);
			armorsForSell[i]=armorToSell;
			armors.push_back(armorsForSell[i]);
			//armors.at(i).print();
			//std::cout<<std::endl;
		}//gemisame ton vector twn armor me 50 armors pros pwlhsh me tuxaia xarakthristika

		for(i=0;i<50;i++){
			//std::cout << i<<std::endl;
			cost_array[i]=randomMinToMax(2,100);//random cost from 2-100
			minLevel_array[i]=randomMinToMax(cost_array[i]/2, cost_array[i]/2 + 5); // level depends on cost
			amount_array[i]=randomMinToMax(minLevel_array[i], minLevel_array[i] + 2); // damage depends on level
			statistic_array[i]=static_cast<Statistic>(rand()%5);
			ss<<(1+(rand()%100));
			std::string str=ss.str();
			itemName_array[i]="Potion " + str;
			ss.str("");//katharisma
			Potion potionToSell(itemName_array[i],cost_array[i],minLevel_array[i],statistic_array[i],amount_array[i]);
			potionsForSell[i]=potionToSell;
			potions.push_back(potionsForSell[i]);
			//armors.at(i).print();
			//std::cout<<std::endl;
		}//gemisame ton vector twn potion me 50 potions pros pwlhsh me tuxaia xarakthristika

		for(i=0;i<50;i++){
			//std::cout << i<<std::endl;
			cost_array[i]=randomMinToMax(2,100);//random cost from 2-100
			minLevel_array[i]=randomMinToMax(cost_array[i]/2, cost_array[i]/2 + 5); // level depends on cost
			magicPower_array[i]=randomMinToMax(minLevel_array[i], minLevel_array[i] + 2);
			rounds_array[i]=1+rand()%4;
			amount_array[i]=1+rand()%11;
			minDamage_array[i]=1+rand()%3;
			maxDamage_array[i]=1+rand()%6+minDamage_array[i]; //random from minDamage to minDamage+5
			spellType_array[i]=static_cast<SpellType>(rand()%3);
			ss<<(1+(rand()%100));
			std::string str=ss.str();
			itemName_array[i]="Spell " + str;
			ss.str("");//katharisma
			Spell spellToSell(itemName_array[i],cost_array[i],minLevel_array[i],minDamage_array[i],maxDamage_array[i],magicPower_array[i],spellType_array[i],amount_array[i],rounds_array[i]);
			spellsForSell[i]=spellToSell;
			spells.push_back(spellsForSell[i]);
			//armors.at(i).print();
			//std::cout<<std::endl;
		}//gemisame ton vector twn spells me 50 spells pros pwlhsh me tuxaia xarakthristika
	}
	else
		std::cout<<"no items to create for sell because the square is not a market"<<std::endl;

		/*std::vector<Weapon> weapons1(weaponsForSell, weaponsForSell + sizeof(weaponsForSell)/sizeof(Weapon));
		for(i=0;i<50;i++){
			weapons1.at(i).print();
		}*/

}

void square::printWeaponsForSell(){
	if(SqrType==market){
		unsigned int i;
		unsigned int j=weapons.size();
		for(i=0;i<j;i++){
			std::cout<<"Weapon for sell No "<<i+1<<std::endl;
			weapons.at(i).print();
			std::cout<<std::endl;
		}
	}
	else
		std::cout<<"no weapons for sell"<<std::endl;
}

void square::printArmorsForSell(){
	if(SqrType==market){
		unsigned int i;
		unsigned int j=armors.size();
		for(i=0;i<j;i++){
			std::cout<<"Armor for sell No "<<i+1<<std::endl;
			armors.at(i).print();
			std::cout<<std::endl;
		}
	}
	else
		std::cout<<"no armors for sell"<<std::endl;
}

void square::printPotionsForSell(){
	if(SqrType==market){
		unsigned int i;
		unsigned int j=potions.size();
		for(i=0;i<j;i++){
			std::cout<<"Potion for sell No "<<i+1<<std::endl;
			potions.at(i).print();
			std::cout<<std::endl;
		}
	}
	else
		std::cout<<"no potions for sell"<<std::endl;
}

void square::printSpellsForSell(){
	if(SqrType==market){
		unsigned int i;
		unsigned int j=spells.size();
		for(i=0;i<j;i++){
			std::cout<<"Spell for sell No "<<i+1<<std::endl;
			spells.at(i).print();
			std::cout<<std::endl;
		}
	}
	else
		std::cout<<"no spells for sell"<<std::endl;
}

void square::printMonstersOnSquare(){
	if(SqrType==common){
		unsigned int i;
		unsigned int j=monsters.size();
		for(i=0;i<j;i++){
			std::cout<<"Monsters on square below:"<<std::endl;
			monsters.at(i).print();
			std::cout<<std::endl;
		}
	}
}

void square::setSquareRow(int row){
	squareRow = row;
}
void square::setSquareColumn(int column){
	squareColumn = column;
}

int square::getSquareRow(){
	return squareRow;
}
int square::getSquareColumn(){
	return squareColumn;
}

void square::print(){
	std::cout << "Square is at row = " << squareRow << " and column = " << squareColumn << std::endl;
}
