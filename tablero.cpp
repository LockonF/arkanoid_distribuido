#include "tablero.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include <stdlib.h>
using namespace std;

Tablero::Tablero()
{
	inicializar_barras();
	set_num_jugador(1);
}

Tablero::~Tablero() 
{
	
}

SDL_Point* Tablero::obtenerSuperior()
{
	return &tab.barraSup.coordenadas[0];	
}

SDL_Point* Tablero::obtenerBarra(int i)
{
	if(i==1)
	{
		return &tab.barraJ1.coordenadas[0];
	}
	else if(i==2)
	{
		return &tab.barraJ2.coordenadas[0];
	}
	else if(i==3)
	{
		return &tab.barraJ3.coordenadas[0];
	}
}

void Tablero::desplazamientoBarra(int cantidad)
{
	if(tab.num_jugador==1)
	{
		if((tab.barraJ1.coordenadas[0].x+cantidad!=0) && (tab.barraJ1.coordenadas[1].x+cantidad!=limiteX))
		{
			for(int i=0;i<=tab.barraJ1.coordenadas.size();i++)
			{
				tab.barraJ1.coordenadas[i].x=tab.barraJ1.coordenadas[i].x+cantidad;
			}
		}
	}
	if(tab.num_jugador==2)
	{
		if((tab.barraJ2.coordenadas[0].y+cantidad!=10) && (tab.barraJ2.coordenadas[1].y+cantidad!=limiteY))
		{
			for(int i=0;i<=tab.barraJ2.coordenadas.size();i++)
			{
				tab.barraJ2.coordenadas[i].y=tab.barraJ2.coordenadas[i].y+cantidad;
			}
		}
	}
	if(tab.num_jugador==3)
	{
		if((tab.barraJ3.coordenadas[0].y+cantidad!=10) && (tab.barraJ3.coordenadas[1].y+cantidad!=limiteY))
		{
			for(int i=0;i<=tab.barraJ3.coordenadas.size();i++)
			{
				tab.barraJ3.coordenadas[i].y=tab.barraJ3.coordenadas[i].y+cantidad;
			}
		}
	}
}

void Tablero::inicializar_barras()
{
	//inferior
	SDL_Point cN;
	cN.x=350;
	cN.y=585;
	tab.barraJ1.coordenadas.push_back(cN);
	cN.x=450;
	cN.y=585;
	tab.barraJ1.coordenadas.push_back(cN);
	cN.x=450;
	cN.y=595;
	tab.barraJ1.coordenadas.push_back(cN);
	cN.x=350;
	cN.y=595;
	tab.barraJ1.coordenadas.push_back(cN);

	tab.barraJ1.coordenadas.push_back(tab.barraJ1.coordenadas.front());

	//Derecha
	cN.x=795;
	cN.y=250;
	tab.barraJ2.coordenadas.push_back(cN);
	cN.x=795;
	cN.y=350;
	tab.barraJ2.coordenadas.push_back(cN);
	cN.x=785;
	cN.y=350;
	tab.barraJ2.coordenadas.push_back(cN);
	cN.x=785;
	cN.y=250;
	tab.barraJ2.coordenadas.push_back(cN);
	

	tab.barraJ2.coordenadas.push_back(tab.barraJ2.coordenadas.front());

	//izquierda
	cN.x=5;
	cN.y=250;
	tab.barraJ3.coordenadas.push_back(cN);
	cN.x=5;
	cN.y=350;
	tab.barraJ3.coordenadas.push_back(cN);
	cN.x=15;
	cN.y=350;
	tab.barraJ3.coordenadas.push_back(cN);
	cN.x=15;
	cN.y=250;
	tab.barraJ3.coordenadas.push_back(cN);
	

	tab.barraJ3.coordenadas.push_back(tab.barraJ3.coordenadas.front());


	//Superior: barra fija
	cN.x=5;
	cN.y=0;
	tab.barraSup.coordenadas.push_back(cN);
	cN.x=795;
	cN.y=0;
	tab.barraSup.coordenadas.push_back(cN);
	cN.x=795;
	cN.y=10;
	tab.barraSup.coordenadas.push_back(cN);
	cN.x=5;
	cN.y=10;
	tab.barraSup.coordenadas.push_back(cN);

	tab.barraSup.coordenadas.push_back(tab.barraSup.coordenadas.front());
}


void Tablero::set_num_jugador(int i)
{
	tab.num_jugador=1;
}