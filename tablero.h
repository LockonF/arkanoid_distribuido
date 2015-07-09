
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

		struct barra
		{
			vector<SDL_Point> coordenadas;
		};

		struct tablero
		{
			barra barraSup;
			barra barraJ1;
			barra barraJ2;
			barra barraJ3;
			vector<barra> tablero;
			int num_jugador;
		};

		Tablero();
		~Tablero();
		SDL_Point* obtenerBarra(int);
		void desplazamientoBarra(int);
		void inicializar_barras();
		SDL_Point* obtenerSuperior();
		void set_num_jugador(int);
	private:
		struct tablero tab;
		int limiteX=800,limiteY=600;
};


#endif