
#ifndef __Tablero__
#define __Tablero__

#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include <stdlib.h>
using namespace std;

class Tablero
{
	public:
		Tablero();
		~Tablero();
		SDL_Point* obtenerBarra();
		void desplazamientoBarra(int);
		void set_limites(int,int);
	private:
		vector<SDL_Point> coordenadas;
		SDL_Point p1, p2, p3 ,p4;
		int limiteX,limiteY;
};


#endif