
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
		void inicializar_barras();
		SDL_Point* obtenerSuperior();
	private:
		vector<SDL_Point> barraJ1; // inferior
		vector<SDL_Point> barraJ2; // derecha
		vector<SDL_Point> barraJ3; // izquierda

		vector<SDL_Point> barraS; // superior
		int limiteX=800,limiteY=600;
};


#endif