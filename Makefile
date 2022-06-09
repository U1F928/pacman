# $^ means names of all dependencies
# $< means names of first dependency
# $@ means name of target

LD=g++
CXX=g++
CXXFLAGS=-Wall -Wfatal-errors -pedantic -std=c++17 -g -D=LOGGING_ON
LIBS=-lncurses

SOURCES=$(wildcard *.cpp) $(wildcard /*/*.cpp) 

kuceralb: 														\
	src/GameEntities/Player/Player.o                  			\
	src/GameEntities/Player/PlayerCanEat.o                		\
	src/GameEntities/Player/PlayerEat.o                   		\
	src/GameEntities/Player/PlayerCanShareTile.o          		\
	src/GameEntities/Player/PlayerShareTile.o                 	\
	src/GameEntities/Player/PlayerCanBeEaten.o                	\
	src/GameEntities/Coin/Coin.o                              	\
	src/GameEntities/Coin/CoinCanBeEaten.o                    	\
	src/GameState.o                                           	\
	src/LevelLoader.o                                           \
	src/Game.o                                                	\
	src/main.cpp                                              

	$(LD) $^ -o $@ $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o  $@

clean:
	rm kuceralb src/*.o src/GameEntities/*/*.o
