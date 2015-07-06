main: main.cpp Game.o tablero.o
	g++ -std=c++11 Game.o tablero.o main.cpp -o main -lSDL2
	rm Game.o tablero.o
Game.o: Game.cpp Game.h
	g++ -std=c++11 Game.cpp -lSDL2 -c
tablero.o: tablero.cpp tablero.h
	g++ -std=c++11 tablero.cpp -lSDL2 -c
	