#include "tablero.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include <stdlib.h>
using namespace std;

Tablero::Tablero()
{
	inicializar_barras();
}

Tablero::~Tablero() 
{
	
}

SDL_Point* Tablero::obtenerBarra(int i)
{
	if(i==1)
	{
		return &barraJ1[0];
	}
	else if(i==2)
	{
		return &barraJ2[0];
	}
	else if(i==3)
	{
		return &barraJ3[0];
	}
}

void Tablero::desplazamientoBarra(int cantidad,int barra)
{
	if(barra==1)
	{
		if((barraJ1[0].x+cantidad!=0) && (barraJ1[1].x+cantidad!=limiteX))
		{
			for(int i=0;i<=barraJ1.size();i++)
			{
				barraJ1[i].x=barraJ1[i].x+cantidad;
			}
		}
	}
	if(barra==2)
	{
		if((barraJ2[0].y+cantidad!=0) && (barraJ2[1].y+cantidad!=limiteY))
		{
			for(int i=0;i<=barraJ2.size();i++)
			{
				barraJ2[i].y=barraJ2[i].y+cantidad;
			}
		}
	}
	if(barra==3)
	{
		if((barraJ3[0].y+cantidad!=0) && (barraJ3[1].y+cantidad!=limiteY))
		{
			for(int i=0;i<=barraJ3.size();i++)
			{
				barraJ3[i].y=barraJ3[i].y+cantidad;
			}
		}
	}
}

void Tablero::set_limites(int x,int y)
{
	limiteX=x;
	limiteY=y;
}

void Tablero::inicializar_barras()
{
	//inferior
	SDL_Point cN;
	cN.x=350;
	cN.y=585;
	barraJ1.push_back(cN);
	cN.x=450;
	cN.y=585;
	barraJ1.push_back(cN);
	cN.x=450;
	cN.y=595;
	barraJ1.push_back(cN);
	cN.x=350;
	cN.y=595;
	barraJ1.push_back(cN);

	barraJ1.push_back(barraJ1.front());

	//Derecha
	cN.x=795;
	cN.y=250;
	barraJ2.push_back(cN);
	cN.x=795;
	cN.y=350;
	barraJ2.push_back(cN);
	cN.x=785;
	cN.y=350;
	barraJ2.push_back(cN);
	cN.x=785;
	cN.y=250;
	barraJ2.push_back(cN);
	

	barraJ2.push_back(barraJ2.front());

	//izquierda
	cN.x=5;
	cN.y=250;
	barraJ3.push_back(cN);
	cN.x=5;
	cN.y=350;
	barraJ3.push_back(cN);
	cN.x=15;
	cN.y=350;
	barraJ3.push_back(cN);
	cN.x=15;
	cN.y=250;
	barraJ3.push_back(cN);
	

	barraJ3.push_back(barraJ3.front());


	//Superior: barra fija

}
