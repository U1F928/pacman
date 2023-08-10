# $^ means names of all dependencies
# $< means names of first dependency
# $@ means name of target

LD=g++

CXX=g++

CXXFLAGS=-Wall -Wfatal-errors -pedantic -std=c++17 -g -D=LOGGING_ON

LIBS=-lncurses 

DOXYFILE=Doxyfile

PACMAN_PREREQUISITES=\
       src/GameEntities/Player/Player.o                                \
       src/GameEntities/Player/PlayerCanShareTile.o                    \
       src/GameEntities/Player/PlayerShareTile.o                       \
       src/GameEntities/Player/PlayerCanBeEaten.o                      \
       src/GameEntities/Coin/Coin.o                                    \
       src/GameEntities/Coin/CoinCanBeEaten.o                          \
       src/GameEntities/Wall/Wall.o                                    \
       src/GameEntities/RespawnPoint/RespawnPoint.o                    \
       src/GameEntities/PowerPellet/PowerPellet.o                      \
       src/GameEntities/PowerPellet/PowerPelletCanBeEaten.o            \
       src/GameEntities/Teleport/Teleport.o                            \
       src/GameEntities/Teleport/TeleportCanConnect.o                  \
       src/GameEntities/Imitator/Imitator.o                            \
       src/GameEntities/Imitator/ImitatorCanShareTile.o                \
       src/GameEntities/Imitator/ImitatorShareTile.o                   \
       src/GameEntities/Imitator/ImitatorCanBeEaten.o                  \
       src/GameEntities/Imitator/ImitatorCanBeEaten.o                  \
       src/GameEntities/Imitator/ImitatorCanBeRespawned.o              \
       src/GameEntities/Wanderer/Wanderer.o                            \
       src/GameEntities/Mimic/Mimic.o                                  \
       src/GameState.o                                                 \
       src/LevelLoader.o                                               \
       src/Renderer.o                                                  \
       src/Game.o                                                      \
       src/main.o

.PHONY: run
run:
	./pacman

.PHONY: all
all : compile doc

doc:
	doxygen $(DOXYFILE)

.PHONY: compile
compile: $(PACMAN_PREREQUISITES)
	$(LD) $^ -o pacman $(LIBS)

%.cpp:
	$(CXX) $(CXXFLAGS) -c $@

.PHONY: clean
clean:
	rm pacman src/*.o; rm src/GameEntities/*/*.o; rm -r doc; rm logFile.txt;

src/Game.o: src/Game.cpp src/Game.h src/GameState.h src/Renderer.h \
 src/GameEntity.h src/LevelLoader.h src/GameEntities/Player/Player.h \
 src/GameEntities/Coin/Coin.h

src/GameState.o: src/GameState.cpp src/GameState.h src/GameEntity.h \
 src/GameEntities/Player/Player.h src/Logger.h

src/LevelLoader.o: src/LevelLoader.cpp src/LevelLoader.h src/GameState.h \
 src/GameEntity.h src/GameEntities/Player/Player.h \
 src/GameEntities/Coin/Coin.h src/GameEntities/Wall/Wall.h \
 src/GameEntities/PowerPellet/PowerPellet.h \
 src/GameEntities/Teleport/Teleport.h \
 src/GameEntities/RespawnPoint/RespawnPoint.h \
 src/GameEntities/Imitator/Imitator.h \
 src/GameEntities/Wanderer/Wanderer.h src/GameEntities/Mimic/Mimic.h

src/main.o: src/main.cpp src/Game.h src/GameState.h src/Renderer.h \
 src/GameEntity.h

src/Renderer.o: src/Renderer.cpp src/Renderer.h src/GameState.h \
 src/GameEntity.h

src/GameEntities/Coin/CoinCanBeEaten.o: src/GameEntities/Coin/CoinCanBeEaten.cpp \
 src/GameEntities/Coin/CoinCanBeEaten.h \
 src/GameEntities/Coin/../../Interaction.h

src/GameEntities/Coin/Coin.o: src/GameEntities/Coin/Coin.cpp src/GameEntities/Coin/Coin.h \
 src/GameEntities/Coin/../../GameEntity.h \
 src/GameEntities/Coin/../../GameState.h \
 src/GameEntities/Coin/CoinCanBeEaten.h \
 src/GameEntities/Coin/../../Interaction.h \
 src/GameEntities/Coin/../../Logger.h

src/GameEntities/Imitator/ImitatorCanBeEaten.o: src/GameEntities/Imitator/ImitatorCanBeEaten.cpp \
 src/GameEntities/Imitator/ImitatorCanBeEaten.h \
 src/GameEntities/Imitator/../../Interaction.h \
 src/GameEntities/Imitator/../Player/Player.h \
 src/GameEntities/Imitator/../Player/../../GameEntity.h \
 src/GameEntities/Imitator/../Player/../../GameState.h

src/GameEntities/Imitator/ImitatorCanBeRespawned.o: \
 src/GameEntities/Imitator/ImitatorCanBeRespawned.cpp \
 src/GameEntities/Imitator/ImitatorCanBeRespawned.h \
 src/GameEntities/Imitator/../../Interaction.h

src/GameEntities/Imitator/ImitatorCanShareTile.o: \
 src/GameEntities/Imitator/ImitatorCanShareTile.cpp \
 src/GameEntities/Imitator/ImitatorCanShareTile.h \
 src/GameEntities/Imitator/../../Interaction.h \
 src/GameEntities/Imitator/../../Logger.h

src/GameEntities/Imitator/Imitator.o: src/GameEntities/Imitator/Imitator.cpp \
 src/GameEntities/Imitator/../../GameEntity.h \
 src/GameEntities/Imitator/../../GameState.h \
 src/GameEntities/Imitator/Imitator.h \
 src/GameEntities/Imitator/ImitatorShareTile.h \
 src/GameEntities/Imitator/../../Interaction.h \
 src/GameEntities/Imitator/ImitatorCanShareTile.h \
 src/GameEntities/Imitator/ImitatorCanBeEaten.h \
 src/GameEntities/Imitator/ImitatorCanBeRespawned.h \
 src/GameEntities/Imitator/../../Logger.h

src/GameEntities/Imitator/ImitatorShareTile.o: src/GameEntities/Imitator/ImitatorShareTile.cpp \
 src/GameEntities/Imitator/ImitatorShareTile.h \
 src/GameEntities/Imitator/../../Interaction.h \
 src/GameEntities/Imitator/Imitator.h \
 src/GameEntities/Imitator/../../GameEntity.h \
 src/GameEntities/Imitator/../../GameState.h \
 src/GameEntities/Imitator/../Teleport/Teleport.h

src/GameEntities/Mimic/Mimic.o: src/GameEntities/Mimic/Mimic.cpp \
 src/GameEntities/Mimic/../../GameEntity.h \
 src/GameEntities/Mimic/../../GameState.h src/GameEntities/Mimic/Mimic.h \
 src/GameEntities/Mimic/../Imitator/Imitator.h \
 src/GameEntities/Mimic/../../Logger.h

src/GameEntities/Player/PlayerCanBeEaten.o: src/GameEntities/Player/PlayerCanBeEaten.cpp \
 src/GameEntities/Player/PlayerCanBeEaten.h \
 src/GameEntities/Player/../../Interaction.h \
 src/GameEntities/Player/Player.h \
 src/GameEntities/Player/../../GameEntity.h \
 src/GameEntities/Player/../../GameState.h

src/GameEntities/Player/PlayerCanShareTile.o: src/GameEntities/Player/PlayerCanShareTile.cpp \
 src/GameEntities/Player/PlayerCanShareTile.h \
 src/GameEntities/Player/../../Interaction.h \
 src/GameEntities/Player/../../Logger.h

src/GameEntities/Player/Player.o: src/GameEntities/Player/Player.cpp \
 src/GameEntities/Player/../../GameEntity.h \
 src/GameEntities/Player/../../GameState.h \
 src/GameEntities/Player/Player.h \
 src/GameEntities/Player/PlayerShareTile.h \
 src/GameEntities/Player/../../Interaction.h \
 src/GameEntities/Player/PlayerCanShareTile.h \
 src/GameEntities/Player/PlayerCanBeEaten.h \
 src/GameEntities/Player/../../Logger.h

src/GameEntities/Player/PlayerShareTile.o: src/GameEntities/Player/PlayerShareTile.cpp \
 src/GameEntities/Player/PlayerShareTile.h \
 src/GameEntities/Player/../../Interaction.h \
 src/GameEntities/Player/Player.h \
 src/GameEntities/Player/../../GameEntity.h \
 src/GameEntities/Player/../../GameState.h \
 src/GameEntities/Player/../Teleport/Teleport.h

src/GameEntities/Player/PowerPelletCanBeEaten.o: \
 src/GameEntities/PowerPellet/PowerPelletCanBeEaten.cpp \
 src/GameEntities/PowerPellet/PowerPelletCanBeEaten.h \
 src/GameEntities/PowerPellet/../../Interaction.h

src/GameEntities/Player/PowerPellet.o: src/GameEntities/PowerPellet/PowerPellet.cpp \
 src/GameEntities/PowerPellet/PowerPellet.h \
 src/GameEntities/PowerPellet/../../GameEntity.h \
 src/GameEntities/PowerPellet/../../GameState.h \
 src/GameEntities/PowerPellet/PowerPelletCanBeEaten.h \
 src/GameEntities/PowerPellet/../../Interaction.h \
 src/GameEntities/PowerPellet/../../Logger.h

src/GameEntities/RespawnPoint/RespawnPoint.o: src/GameEntities/RespawnPoint/RespawnPoint.cpp \
 src/GameEntities/RespawnPoint/RespawnPoint.h \
 src/GameEntities/RespawnPoint/../../GameEntity.h \
 src/GameEntities/RespawnPoint/../../GameState.h \
 src/GameEntities/RespawnPoint/../../Logger.h \
 src/GameEntities/RespawnPoint/../../Interaction.h

src/GameEntities/Teleport/TeleportCanConnect.o: src/GameEntities/Teleport/TeleportCanConnect.cpp \
 src/GameEntities/Teleport/TeleportCanConnect.h \
 src/GameEntities/Teleport/../../Interaction.h

src/GameEntities/Teleport/Teleport.o: src/GameEntities/Teleport/Teleport.cpp \
 src/GameEntities/Teleport/Teleport.h \
 src/GameEntities/Teleport/../../GameEntity.h \
 src/GameEntities/Teleport/../../GameState.h \
 src/GameEntities/Teleport/TeleportCanConnect.h \
 src/GameEntities/Teleport/../../Interaction.h \
 src/GameEntities/Teleport/../../Logger.h

src/GameEntities/Wall/Wall.o: src/GameEntities/Wall/Wall.cpp src/GameEntities/Wall/Wall.h \
 src/GameEntities/Wall/../../GameEntity.h \
 src/GameEntities/Wall/../../GameState.h \
 src/GameEntities/Wall/../../Logger.h \
 src/GameEntities/Wall/../../Interaction.h

src/GameEntities/Wanderer/Wanderer.o: src/GameEntities/Wanderer/Wanderer.cpp \
 src/GameEntities/Wanderer/../../GameEntity.h \
 src/GameEntities/Wanderer/../../GameState.h \
 src/GameEntities/Wanderer/Wanderer.h \
 src/GameEntities/Wanderer/../Imitator/Imitator.h \
 src/GameEntities/Wanderer/../../Logger.h
