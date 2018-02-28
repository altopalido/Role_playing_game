OBJS	= rpg.o item.o weapon.o armor.o potion.o spell.o living.o hero.o monster.o grid.o square.o fightFunctions.o
SOURCE	= rpg.cc item.cc weapon.cc armor.cc potion.cc spell.cc living.cc hero.cc monster.cc grid.cc square.cc fightFunctions.cc
HEADER	= item.h weapon.h armor.h potion.h enum_types.h spell.h living.h hero.h monster.h grid.h square.h fightFunctions.h
OUT	= rpg
CC	= g++
FLAGS	= -g -c -Wall

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT)


art.o: rpg.cc
	$(CC) $(FLAGS) rpg.cc

item.o: item.cc
	$(CC) $(FLAGS) item.cc

weapon.o: weapon.cc
	$(CC) $(FLAGS) weapon.cc

armor.o: armor.cc
	$(CC) $(FLAGS) armor.cc

potion.o: potion.cc
	$(CC) $(FLAGS) potion.cc

spell.o: spell.cc
	$(CC) $(FLAGS) spell.cc

living.o: living.cc
	$(CC) $(FLAGS) living.cc

hero.o: hero.cc
	$(CC) $(FLAGS) hero.cc

monster.o: monster.cc
	$(CC) $(FLAGS) monster.cc

square.o: square.cc
	$(CC) $(FLAGS) square.cc

grid.o: grid.cc
	$(CC) $(FLAGS) grid.cc

fightFunctions.o: fightFunctions.cc
	$(CC) $(FLAGS) fightFunctions.cc

clean:
	rm -f $(OBJS) $(OUT)
