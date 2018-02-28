#include <iostream>
#include <string>
#include <cstdlib>
#include "enum_types.h"
#include "grid.h"
#include "fightFunctions.h"

grid::grid(int length,int width): length(length), width(width){
	int i,j;
	std::cout<<"A new grid was created"<<std::endl;

	gridarray= new square**[length];
	for(i=0; i<length; i++){
		gridarray[i]=new square*[width];
		for(j=0; j<width; j++){
			gridarray[i][j]= new square(i, j);

		}
	}
}

grid::~grid(){
	int i,j;
	for (i = 0; i < length; i++) {
    	for (j = 0; j < width; j++) {
       	 delete gridarray[i][j]; // delete stored pointer
    	}
    delete[] gridarray[i]; // delete sub array
	}
	delete [] gridarray; //delete outer array
	gridarray = NULL;
	std::cout<<"A grid was destroyed"<<std::endl;
}

square* grid::move(Living** thisHero, int numberOfHeroes){
	srand(time(NULL));
	int i;
	int j = 0;
	int z;
	int k, HeroToPurchase = 0;
	// i = randomMinToMax(0,4);
	int HeroLength=thisHero[0]->getHeroLengthOnGridArray();
	int HeroWidth=thisHero[0]->getHeroWidthOnGridArray();
	square* sqrBefore=gridarray[HeroLength][HeroWidth]; //to tetragwno sto opoio vriskotan prin o hrwas
	square* sqrAfter=gridarray[HeroLength][HeroWidth]; //to tetragwno sto opoio vrisketai o hrwas meta thn kinhsh
	SquareType checkSqType;
	std::cout << "Move: 0. Up" << std::endl;
	std::cout << "      1. Down" << std::endl;
	std::cout << "      2. Left" << std::endl;
	std::cout << "      3. Right" << std::endl;
	std::cin>>i;
	if(i==0){
		if(HeroLength!=0){
			checkSqType=gridarray[HeroLength-1][HeroWidth]->getSqrType();
			if(checkSqType!=nonAccessible){
				sqrAfter=gridarray[HeroLength-1][HeroWidth];
				for (j = 0 ; j < numberOfHeroes ; j++){
					sqrBefore->setHeroNum('-');//edw meiwnw to prin tetragwno kata enan hrwa
					sqrAfter->setHeroNum('+');//edw auksanw to twrino tetragwno kata enan hrwa
					thisHero[j]->setHeroLengthOnGridArray('-');//allazw ston hrwa th thesh sto grid
				}
				if(checkSqType==common){//an to tetragwno einai common dimiourgountai ta terata sto tetragwno
					sqrAfter->createMonsters(thisHero[0]->getLevel(), thisHero, numberOfHeroes);
				}
				else {
					std::cout << "Welcome to Market!" << std::endl;
					sqrAfter->createItemsForSell();
						std::cout << "Items for sale are:"<< std::endl;
						std::cout << "Weapons:"<<std::endl;
						sqrAfter->printWeaponsForSell();
						std::cout <<std::endl;
						std::cout << "Armors:"<<std::endl;
						sqrAfter->printArmorsForSell();
						std::cout <<std::endl;
						std::cout << "Spells:"<<std::endl;
						sqrAfter->printSpellsForSell();
						std::cout <<std::endl;
						std::cout << "Potions:"<<std::endl;
						sqrAfter->printPotionsForSell();
						std::cout <<std::endl;
						std::cout << "Press: 1. to buy weapon" << std::endl;
  					std::cout << "       2. to buy armor" << std::endl;
  					std::cout << "       3. to buy spell" << std::endl;
 						std::cout << "       0. if you don't want to buy anything" << std::endl;
						std::cin>>z;
						if(z==1){
							if (numberOfHeroes > 1){
								std::cout << "Choose a hero to buy weapon: " << std::endl;
								for (k = 0 ; k < numberOfHeroes ; k++){
									std::cout << k << ". " << thisHero[k]->getName() << std::endl;
								}
								std::cin >> HeroToPurchase;
							}
						}
					// buyWeapon(thisHero[HeroToPurchase], 0);
					}
			}
			else
				std::cout<<"The up square is not Accessible"<<std::endl;
		}
		else
			std::cout<<"The Hero(es) can't move up. Reached the end of the grid"<<std::endl;
	} //moving a square up if possible
	else if(i==1){
		if(HeroLength!=length-1){
			checkSqType=gridarray[HeroLength+1][HeroWidth]->getSqrType();
			if(checkSqType!=nonAccessible){
				sqrAfter=gridarray[HeroLength+1][HeroWidth];
				for (j = 0 ; j < numberOfHeroes ; j++){
					sqrBefore->setHeroNum('-');
					sqrAfter->setHeroNum('+');
					thisHero[j]->setHeroLengthOnGridArray('+');
				}
				if(checkSqType==common){//an to tetragwno einai common dimiourgounte ta terata sto tetragwno
					sqrAfter->createMonsters(thisHero[0]->getLevel(), thisHero, numberOfHeroes);
				}
				else {
					std::cout << "Welcome to Market!" << std::endl;
					sqrAfter->createItemsForSell();
						std::cout << "Items for sale are:"<< std::endl;
						std::cout << "Weapons:"<<std::endl;
						sqrAfter->printWeaponsForSell();
						std::cout <<std::endl;
						std::cout << "Armors:"<<std::endl;
						sqrAfter->printArmorsForSell();
						std::cout <<std::endl;
						std::cout << "Spells:"<<std::endl;
						sqrAfter->printSpellsForSell();
						std::cout <<std::endl;
						std::cout << "Potions:"<<std::endl;
						sqrAfter->printPotionsForSell();
						std::cout <<std::endl;
						std::cout << "Press: 1. to buy weapon" << std::endl;
  					std::cout << "       2. to buy armor" << std::endl;
  					std::cout << "       3. to buy spell" << std::endl;
 						std::cout << "       0. if you don't want to buy anything" << std::endl;
						std::cin>>z;
						if(z==1){
						if (numberOfHeroes > 1){
							std::cout << "Choose a hero to buy weapon: " << std::endl;
						for (k = 0 ; k < numberOfHeroes ; k++){
							std::cout << k << ". " << thisHero[k]->getName() << std::endl;
						}
						std::cin >> HeroToPurchase;
						}
					}
					// buyWeapon(thisHero[HeroToPurchase], 0);
				}
			}
			else
				std::cout<<"The down square is not Accessible"<<std::endl;
		}
		else
			std::cout<<"The Hero(es) can't move down. Reached the end of the grid"<<std::endl;
	} //moving a square down
	else if(i==2){
		if(HeroWidth!=0){
			checkSqType=gridarray[HeroLength][HeroWidth-1]->getSqrType();
			if(checkSqType!=nonAccessible){
				sqrAfter=gridarray[HeroLength][HeroWidth-1];
				for (j = 0 ; j < numberOfHeroes ; j++){
					sqrBefore->setHeroNum('-');
					sqrAfter->setHeroNum('+');
					thisHero[j]->setHeroWidthOnGridArray('-');
				}
				if(checkSqType==common){//an to tetragwno einai common dimiourgounte ta terata sto tetragwno
					sqrAfter->createMonsters(thisHero[0]->getLevel(), thisHero, numberOfHeroes);
				}
				else {
					std::cout << "Welcome to Market!" << std::endl;
					sqrAfter->createItemsForSell();

						std::cout << "Items for sale are:"<< std::endl;
						std::cout << "Weapons:"<<std::endl;
						sqrAfter->printWeaponsForSell();
						std::cout <<std::endl;
						std::cout << "Armors:"<<std::endl;
						sqrAfter->printArmorsForSell();
						std::cout <<std::endl;
						std::cout << "Spells:"<<std::endl;
						sqrAfter->printSpellsForSell();
						std::cout <<std::endl;
						std::cout << "Potions:"<<std::endl;
						sqrAfter->printPotionsForSell();
						std::cout <<std::endl;
						std::cout << "Press: 1. to buy weapon" << std::endl;
  					std::cout << "       2. to buy armor" << std::endl;
  					std::cout << "       3. to buy spell" << std::endl;
 						std::cout << "       0. if you don't want to buy anything" << std::endl;
						std::cin>>z;
						if(z==1){
							if (numberOfHeroes > 1){
							std::cout << "Choose a hero to buy weapon: " << std::endl;
							for (k = 0 ; k < numberOfHeroes ; k++){
								std::cout << k << ". " << thisHero[k]->getName() << std::endl;
							}
							std::cin >> HeroToPurchase;
						}
					}
					// buyWeapon(thisHero[HeroToPurchase], 0);
				}
			}
			else
				std::cout<<"The left square is not Accessible"<<std::endl;
		}
		else
			std::cout<<"The Hero(es) can't move left. Reached the end of the grid"<<std::endl;
	} //moving a square left
	else if(i==3){
		if(HeroWidth!=width-1){
			checkSqType=gridarray[HeroLength][HeroWidth+1]->getSqrType();
			if(checkSqType!=nonAccessible){
				sqrAfter=gridarray[HeroLength][HeroWidth+1];
				for (j = 0 ; j < numberOfHeroes ; j++){
					sqrBefore->setHeroNum('-');
					sqrAfter->setHeroNum('+');
					thisHero[j]->setHeroWidthOnGridArray('+');
				}
				if(checkSqType==common){//an to tetragwno einai common dimiourgountai ta terata sto tetragwno
					sqrAfter->createMonsters(thisHero[0]->getLevel(), thisHero, numberOfHeroes);
				}
				else {
					std::cout << "Welcome to Market!" << std::endl;
					sqrAfter->createItemsForSell();

						std::cout << "Items for sale are:"<< std::endl;
						std::cout << "Weapons:"<<std::endl;
						sqrAfter->printWeaponsForSell();
						std::cout <<std::endl;
						std::cout << "Armors:"<<std::endl;
						sqrAfter->printArmorsForSell();
						std::cout <<std::endl;
						std::cout << "Spells:"<<std::endl;
						sqrAfter->printSpellsForSell();
						std::cout <<std::endl;
						std::cout << "Potions:"<<std::endl;
						sqrAfter->printPotionsForSell();
						std::cout <<std::endl;
						std::cout << "Press: 1. to buy weapon" << std::endl;
  					std::cout << "       2. to buy armor" << std::endl;
  					std::cout << "       3. to buy spell" << std::endl;
 						std::cout << "       0. if you don't want to buy anything" << std::endl;
						std::cin>>z;
						if(z==1){
							if (numberOfHeroes > 1){
								std::cout << "Choose a hero to buy weapon: " << std::endl;
							for (k = 0 ; k < numberOfHeroes ; k++){
								std::cout << k << ". " << thisHero[k]->getName() << std::endl;
							}
							std::cin >> HeroToPurchase;
						}
					}
					// buyWeapon(thisHero[HeroToPurchase], 0);
				}
			}
			else
				std::cout<<"The right square is not Accessible"<<std::endl;
		}
		else
			std::cout<<"The Hero(es) can't move right. Reached the end of the grid"<<std::endl;

	} //moving a square right
	else{
		std::cout<<"Wrong move"<<std::endl;
		sqrAfter=gridarray[-1][-1];
	}

			return sqrAfter;
}

void grid::buyWeapon(Hero* thisHero,int thisItem){
	Weapon thisWeapon;
	int HeroLength=thisHero->getHeroLengthOnGridArray();
	int HeroWidth=thisHero->getHeroWidthOnGridArray();
	square* herosSquare=gridarray[HeroLength][HeroWidth];
	herosSquare->createItemsForSell();//sto tetragwno tou hrwa dhmiourgountai ta antikeimena pou einai pros pwlhsh
	SquareType checkSqType;
	checkSqType=herosSquare->getSqrType();
	if(checkSqType==market){
		std::vector<Weapon>* squareWeaponsVector=(herosSquare->getWeapons());//deikths sto prwto stoixei tou vector me ta opla tou tetragwnou pou einai pros pwlhsh
		std::vector<Weapon>* heroWeaponsVector=thisHero->getOwnWeapons();//deikths sto prwto stoixeio tou vector me ta opla tou hrwa
		thisWeapon=squareWeaponsVector->at(thisItem-1); // sth metavlhth thisWeapon kratame to oplo pou theloume na agorasoume gia na to prosthesoume ston pinaka me ta opla tou hrwa
		if(thisHero->getMoney()>=thisWeapon.getCost()){
			//std::cout<<"---------------prin-------------"<<std::endl;
			//herosSquare->printWeaponsForSell();
			squareWeaponsVector->erase(squareWeaponsVector->begin()+thisItem-1); //diagrafei to noumero thisItem antikeimeno apo ton pinaka me ta opla tou square pou vrisketai o hrwas kathws to antikeimeno agorasthke
			//std::cout<<"---------------meta-------------"<<std::endl;
			//herosSquare->printWeaponsForSell();
			heroWeaponsVector->push_back(thisWeapon); // pairnoume to oplo pou agorasthke kai na to prosthesoume ston vector me ta opla tou hrwa
			//thisHero.checkInventory();
			thisHero->setMoney(thisHero->getMoney()-thisWeapon.getCost());//se auth th grammh na aferesw ta lefta apo ton hrwa
		}
		else
			std::cout<<"Not enough money to buy"<<std::endl;
	}
	else
		std::cout<<"You can't buy because the square is not a market"<<std::endl;

}

void grid::buyArmor(Hero* thisHero,int thisItem){
	Armor thisArmor;
	int HeroLength=thisHero->getHeroLengthOnGridArray();
	int HeroWidth=thisHero->getHeroWidthOnGridArray();
	square* herosSquare=gridarray[HeroLength][HeroWidth];
	herosSquare->createItemsForSell();//sto tetragwno tou hrwa dhmiourgountai ta antikeimena pou einai pros pwlhsh
	SquareType checkSqType;
	checkSqType=herosSquare->getSqrType();
	if(checkSqType==market){
		std::vector<Armor>* squareArmorsVector=(herosSquare->getArmors());//deikths sto prwto stoixei tou vector me ta armors tou tetragwnou pou einai pros pwlhsh
		std::vector<Armor>* heroArmorsVector=thisHero->getOwnArmors();//deikths sto prwto stoixeio tou vector me ta armors tou hrwa
		thisArmor=squareArmorsVector->at(thisItem-1); // sth metavlhth thisArmor kratame to armor pou theloume na agorasoume gia na to prosthesoume ston pinaka me ta armor tou hrwa
		if(thisHero->getMoney()>=thisArmor.getCost()){
			//std::cout<<"---------------prin-------------"<<std::endl;
			//herosSquare->printArmorsForSell();
			squareArmorsVector->erase(squareArmorsVector->begin()+thisItem-1); //diagrafei to noumero thisItem antikeimeno apo ton pinaka me ta armors tou square pou vrisketai o hrwas kathws to antikeimeno agorasthke
			//std::cout<<"---------------meta-------------"<<std::endl;
			//herosSquare->printArmorsForSell();
			heroArmorsVector->push_back(thisArmor); // pairnoume to armor pou agorasthke kai na to prosthesoume ston vector me ta armor tou hrwa
			//thisHero.checkInventory();
			thisHero->setMoney(thisHero->getMoney()-thisArmor.getCost());//se auth th grammh na aferesw ta lefta apo ton hrwa
		}
		else
			std::cout<<"Not enough money to buy"<<std::endl;
	}
	else
		std::cout<<"You can't buy because the square is not a market"<<std::endl;

}

void grid::buySpell(Hero* thisHero,int thisItem){
	Spell thisSpell;
	int HeroLength=thisHero->getHeroLengthOnGridArray();
	int HeroWidth=thisHero->getHeroWidthOnGridArray();
	square* herosSquare=gridarray[HeroLength][HeroWidth];
	herosSquare->createItemsForSell();//sto tetragwno tou hrwa dhmiourgountai ta antikeimena pou einai pros pwlhsh
	SquareType checkSqType;
	checkSqType=herosSquare->getSqrType();
	if(checkSqType==market){
		std::vector<Spell>* squareSpellsVector=(herosSquare->getSpells());//deikths sto prwto stoixei tou vector me ta spells tou tetragwnou pou einai pros pwlhsh
		std::vector<Spell>* heroSpellsVector=thisHero->getOwnSpells();//deikths sto prwto stoixeio tou vector me ta Spells tou hrwa
		thisSpell=squareSpellsVector->at(thisItem-1); // sth metavlhth thisSpell kratame to spell pou theloume na agorasoume gia na to prosthesoume ston pinaka me ta spell tou hrwa
		if(thisHero->getMoney()>=thisSpell.getCost()){
			//std::cout<<"---------------prin-------------"<<std::endl;
			//herosSquare->printSpellsForSell();
			squareSpellsVector->erase(squareSpellsVector->begin()+thisItem-1); //diagrafei to noumero thisItem antikeimeno apo ton pinaka me ta spells tou square pou vrisketai o hrwas kathws to antikeimeno agorasthke
			//std::cout<<"---------------meta-------------"<<std::endl;
			//herosSquare->printSpellsForSell();
			heroSpellsVector->push_back(thisSpell); // pairnoume to spell pou agorasthke kai na to prosthesoume ston vector me ta spell tou hrwa
			//thisHero.checkInventory();
			thisHero->setMoney(thisHero->getMoney()-thisSpell.getCost());//se auth th grammh na aferesw ta lefta apo ton hrwa
		}
		else
			std::cout<<"Not enough money to buy"<<std::endl;
	}
	else
		std::cout<<"You can't buy because the square is not a market"<<std::endl;

}

void grid::buyPotion(Hero* thisHero,int thisItem){
	Potion thisPotion;
	int HeroLength=thisHero->getHeroLengthOnGridArray();
	int HeroWidth=thisHero->getHeroWidthOnGridArray();
	square* herosSquare=gridarray[HeroLength][HeroWidth];
	herosSquare->createItemsForSell();//sto tetragwno tou hrwa dhmiourgountai ta antikeimena pou einai pros pwlhsh
	SquareType checkSqType;
	checkSqType=herosSquare->getSqrType();
	if(checkSqType==market){
		std::vector<Potion>* squarePotionsVector=(herosSquare->getPotions());//deikths sto prwto stoixei tou vector me ta potions tou tetragwnou pou einai pros pwlhsh
		std::vector<Potion>* heroPotionsVector=thisHero->getOwnPotions();//deikths sto prwto stoixeio tou vector me ta Potions tou hrwa
		thisPotion=squarePotionsVector->at(thisItem-1); // sth metavlhth thisPotion kratame to potion pou theloume na agorasoume gia na to prosthesoume ston pinaka me ta potion tou hrwa
		if(thisHero->getMoney()>=thisPotion.getCost()){
			//std::cout<<"---------------prin-------------"<<std::endl;
			//herosSquare->printPotionsForSell();
			squarePotionsVector->erase(squarePotionsVector->begin()+thisItem-1); //diagrafei to noumero thisItem antikeimeno apo ton pinaka me ta potions tou square pou vrisketai o hrwas kathws to antikeimeno agorasthke
			//std::cout<<"---------------meta-------------"<<std::endl;
			//herosSquare->printPotionsForSell();
			heroPotionsVector->push_back(thisPotion); // pairnoume to potion pou agorasthke kai na to prosthesoume ston vector me ta potion tou hrwa
			//thisHero.checkInventory();
			thisHero->setMoney(thisHero->getMoney()-thisPotion.getCost());//se auth th grammh na aferesw ta lefta apo ton hrwa
			//std::cout<<thisHero.getMoney()<<std::endl;
			//thisHero.printStats();
		}
		else
			std::cout<<"Not enough money to buy"<<std::endl;
	}
	else
		std::cout<<"You can't buy because the square is not a market"<<std::endl;
}

void grid::sellWeapon(Hero* thisHero,int thisItem){
	Weapon thisWeapon;
	int HeroLength=thisHero->getHeroLengthOnGridArray();
	int HeroWidth=thisHero->getHeroWidthOnGridArray();
	square* herosSquare=gridarray[HeroLength][HeroWidth];//to tetragwno sto opoio vrisketai o hrwas
	SquareType checkSqType;
	checkSqType=herosSquare->getSqrType();
	if(checkSqType==market){//an to tetragwno pou vrisketai o hrwas einai agora
		std::vector<Weapon>* heroWeaponsVector=thisHero->getOwnWeapons();//deikths sto prwto stoixeio tou vector me ta Weapons tou hrwa
		thisWeapon=heroWeaponsVector->at(thisItem-1);
		if(!heroWeaponsVector->empty()){
			heroWeaponsVector->erase(heroWeaponsVector->begin()+thisItem-1);//diagrafei to antikeimeno pou tha poulhthei
			thisHero->setMoney(thisHero->getMoney()+thisWeapon.getCost()/2);//prosthetei sta xrhmata tou hrwa to poso
		}
	}
}

void grid::sellArmor(Hero* thisHero,int thisItem){
	Armor thisArmor;
	int HeroLength=thisHero->getHeroLengthOnGridArray();
	int HeroWidth=thisHero->getHeroWidthOnGridArray();
	square* herosSquare=gridarray[HeroLength][HeroWidth];//to tetragwno sto opoio vrisketai o hrwas
	SquareType checkSqType;
	checkSqType=herosSquare->getSqrType();
	if(checkSqType==market){//an to tetragwno pou vrisketai o hrwas einai agora
		std::vector<Armor>* heroArmorsVector=thisHero->getOwnArmors();//deikths sto prwto stoixeio tou vector me ta Armors tou hrwa
		thisArmor=heroArmorsVector->at(thisItem-1);
		if(!heroArmorsVector->empty()){
			heroArmorsVector->erase(heroArmorsVector->begin()+thisItem-1);//diagrafei to antikeimeno pou tha poulhthei
			thisHero->setMoney(thisHero->getMoney()+thisArmor.getCost()/2);//prosthetei sta xrhmata tou hrwa to poso
		}
	}
}

void grid::sellSpell(Hero* thisHero,int thisItem){
	Spell thisSpell;
	int HeroLength=thisHero->getHeroLengthOnGridArray();
	int HeroWidth=thisHero->getHeroWidthOnGridArray();
	square* herosSquare=gridarray[HeroLength][HeroWidth];//to tetragwno sto opoio vrisketai o hrwas
	SquareType checkSqType;
	checkSqType=herosSquare->getSqrType();
	if(checkSqType==market){//an to tetragwno pou vrisketai o hrwas einai agora
		std::vector<Spell>* heroSpellsVector=thisHero->getOwnSpells();//deikths sto prwto stoixeio tou vector me ta Spells tou hrwa
		thisSpell=heroSpellsVector->at(thisItem-1);
		if(!heroSpellsVector->empty()){
			heroSpellsVector->erase(heroSpellsVector->begin()+thisItem-1);//diagrafei to antikeimeno pou tha poulhthei
			thisHero->setMoney(thisHero->getMoney()+thisSpell.getCost()/2);//prosthetei sta xrhmata tou hrwa to poso
		}
	}
}

void grid::sellPotion(Hero* thisHero,int thisItem){
	Potion thisPotion;
	int HeroLength=thisHero->getHeroLengthOnGridArray();
	int HeroWidth=thisHero->getHeroWidthOnGridArray();
	square* herosSquare=gridarray[HeroLength][HeroWidth];//to tetragwno sto opoio vrisketai o hrwas
	SquareType checkSqType;
	checkSqType=herosSquare->getSqrType();
	if(checkSqType==market){//an to tetragwno pou vrisketai o hrwas einai agora
		std::vector<Potion>* heroPotionsVector=thisHero->getOwnPotions();//deikths sto prwto stoixeio tou vector me ta Potions tou hrwa
		thisPotion=heroPotionsVector->at(thisItem-1);
		if(!heroPotionsVector->empty()){
			heroPotionsVector->erase(heroPotionsVector->begin()+thisItem-1);//diagrafei to antikeimeno pou tha poulhthei
			thisHero->setMoney(thisHero->getMoney()+thisPotion.getCost()/2);//prosthetei sta xrhmata tou hrwa to poso
		}
	}
}

void grid::displayMap(){
	int i,j;
	std::cout<<std::endl;
	std::cout<<"Grids length is: "<<length<<std::endl;
	std::cout<<"Grids width is: "<<width<<std::endl;
	std::cout<<"Further information below about each grids square"<<std::endl<<std::endl;
	for(i=0;i<length;i++){
		for(j=0;j<width;j++){
			std::cout<<"The square at row "<<i<<" and column "<<j<<" has the following characteristics: "<<std::endl;
			std::cout<<"The number of heroes in this square are "<<gridarray[i][j]->getHeroNum()<<std::endl;
			std::cout<<"The number of monsters in this square are "<<gridarray[i][j]->getMonsterNum()<<std::endl;
			std::cout<<"The type of this square is: ";
			if(gridarray[i][j]->getSqrType()==0)
				std::cout<<"nonAccessible";
			else if(gridarray[i][j]->getSqrType()==1)
				std::cout<<"market";
			else
				std::cout<<"common";
			std::cout<<std::endl<<std::endl;
		}
	}
	// Optical representation of grid
	for(i=0;i<4*width+1;i++){
		std::cout << "-";
	}
	std::cout << std::endl;
	for(i=0;i<length;i++){
		std::cout << "|";
		for(j=0;j<width;j++){
			if(gridarray[i][j]->getSqrType()==0) std::cout<<" N";
			else if(gridarray[i][j]->getSqrType()==1) std::cout<<" M";
			else std::cout<<" C";
			std::cout << " |";
		}
		std::cout << std::endl;
		for(j=0;j<4*width+1;j++){
			std::cout << "-";
		}
		std::cout << std::endl;
	}
	std::cout << "C: Common, M: Market, N: Non-accesible" << std::endl << std::endl;
}
