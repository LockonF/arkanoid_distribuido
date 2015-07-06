#include "tablero.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include <stdlib.h>
using namespace std;

Tablero::Tablero()
{

	SDL_Point cN;
	cN.x=350;
	cN.y=585;
	coordenadas.push_back(cN);
	cN.x=450;
	cN.y=585;
	coordenadas.push_back(cN);
	cN.x=450;
	cN.y=595;
	coordenadas.push_back(cN);
	cN.x=350;
	cN.y=595;
	coordenadas.push_back(cN);

	coordenadas.push_back(coordenadas.front());
	
}

Tablero::~Tablero() 
{
	
}

SDL_Point* Tablero::obtenerBarra()
{
	return &coordenadas[0];
}

void Tablero::desplazamientoBarra(int cantidad)
{
	if((coordenadas[0].x+cantidad!=0) && (coordenadas[1].x+cantidad!=limiteX))
	for(int i=0;i<=coordenadas.size();i++)
	{
		coordenadas[i].x=coordenadas[i].x+cantidad;
	}
}

void Tablero::set_limites(int x,int y)
{
	limiteX=x;
	limiteY=y;
}