
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
		SDL_Point* obtenerBarra(int);
		void desplazamientoBarra(int,int);
		void set_limites(int,int);
		void inicializar_barras();
	private:
		vector<SDL_Point> barraJ1; // inferior
		vector<SDL_Point> barraJ2; // derecha
		vector<SDL_Point> barraJ3; // izquierda
		int limiteX,limiteY;
};


#endif