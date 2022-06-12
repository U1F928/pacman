# $^ means names of all dependencies
# $< means names of first dependency
# $@ means name of target

LD=g++
CXX=g++
CXXFLAGS=-Wall -Wfatal-errors -pedantic -std=c++17 -g -D=LOGGING_ON
LIBS=-lncurses 

LOGIN=kuceralb

SOURCES=\
	src/GameEntities/Player/Player.o                  				\
	src/GameEntities/Player/PlayerCanShareTile.o          			\
	src/GameEntities/Player/PlayerShareTile.o                 		\
	src/GameEntities/Player/PlayerCanBeEaten.o                		\
	src/GameEntities/Coin/Coin.o                              		\
	src/GameEntities/Coin/CoinCanBeEaten.o                    		\
	src/GameEntities/Wall/Wall.o                              		\
	src/GameEntities/RespawnPoint/RespawnPoint.o                    \
	src/GameEntities/PowerPellet/PowerPellet.o                  	\
	src/GameEntities/PowerPellet/PowerPelletCanBeEaten.o  			\
	src/GameEntities/Teleport/Teleport.o  							\
	src/GameEntities/Teleport/TeleportCanConnect.o  				\
	src/GameEntities/Imitator/Imitator.o  							\
	src/GameEntities/Imitator/ImitatorCanShareTile.o          		\
	src/GameEntities/Imitator/ImitatorShareTile.o                 	\
	src/GameEntities/Imitator/ImitatorCanBeEaten.o                	\
	src/GameEntities/Imitator/ImitatorCanBeEaten.o                	\
	src/GameEntities/Imitator/ImitatorCanBeRespawned.o              \
	src/GameEntities/Wanderer/Wanderer.o  							\
	src/GameEntities/Mimic/Mimic.o  								\
	src/GameState.o                                           		\
	src/LevelLoader.o                                           	\
	src/Renderer.o                                           		\
	src/Game.o                                                		\
	src/main.cpp                                              

run:
	./$(LOGIN)

all : compile doc

doc:
	ls # make documentation
	
compile: $(SOURCES)

	$(LD) $^ -o $(LOGIN) $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o  $@

clean:
	rm kuceralb src/*.o src/GameEntities/*/*.o
