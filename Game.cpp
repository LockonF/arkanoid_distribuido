// Game.cpp
// Implementacion de la clase game, encargada de la constante actualizacion de la aplicacion

#include "Game.h"
#include <iostream>
#include <SDL2/SDL.h>
#include "tablero.h"
#include <cstdint>


Game::Game()
{
    m_bRunning = true;
    srand (time(NULL));
    tab.inicializar_juego();
}

Game::~Game()
{
    
}

void Game::init(const char * titulo,int xpos,int ypos,int alto,int ancho,int banderas)
{
    
    //inicializacion de subsistemas de SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        m_bRunning = false;
        return;
    }
    
    //Crea una ventana
    m_pWindow = SDL_CreateWindow(titulo, xpos, ypos, ancho, alto, banderas);
    
    if (m_pWindow == nullptr){
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        m_bRunning = false;
        return;
    }
    
    //Creacion del render: SDL_RENDERER_ACCELERATED-> aceleracion tarjeta video y SDL_RENDERER_PRESENTVSYNC -> sincronizar velocidad de refresco del monitor
    m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    if (m_pRenderer == nullptr){
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        m_bRunning = false;
        return;
    }
    m_bRunning = true;
    
    
    
    
    return;
}

void Game::render()
{
    SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
    SDL_RenderClear(m_pRenderer);
    //SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
    
    SDL_SetRenderDrawColor(m_pRenderer,0, 255,0, 255);//color de poligono
    
    SDL_RenderDrawLines(m_pRenderer, tab.obtenerBarra(1), 5);
    SDL_RenderDrawLines(m_pRenderer, tab.obtenerBarra(2), 5);
    SDL_RenderDrawLines(m_pRenderer, tab.obtenerBarra(3), 5);
    
    SDL_RenderDrawLines(m_pRenderer, tab.obtenerSuperior(), 5);
    
    for(int x=0;x<tab.get_size_tablero();x++)
    {
        SDL_RenderDrawLines(m_pRenderer, tab.get_element_tablero(x), 5);
    }
    
    SDL_RenderPresent(m_pRenderer);
    
}

Tablero::tablero Game::update(Tablero::tablero syncTab)
{

    
    
    keystate = SDL_GetKeyboardState(NULL);
    if (keystate[SDL_SCANCODE_RIGHT] ) {
        tab.desplazamientoBarra(2);
        
        
    }
    else if (keystate[SDL_SCANCODE_LEFT] ) {
        tab.desplazamientoBarra(-2);
    }
    else{
        switch (syncTab.num_jugador) {
            case 1:
                tab.tab.num_jugador=1;
                tab.tab.barraJ2 = syncTab.barraJ2;
                tab.tab.barraJ3 = syncTab.barraJ3;
                break;
            case 2:
                tab.tab.num_jugador=2;
                tab.tab.barraJ1 = syncTab.barraJ1;
                tab.tab.barraJ3 = syncTab.barraJ3;
                break;
            case 3:
                tab.tab.num_jugador=3;
                tab.tab.barraJ1 = syncTab.barraJ1;
                tab.tab.barraJ2 = syncTab.barraJ2;
                break;
            default:
                break;
        }
    }
    
    return tab.tab;
}

void Game::handleEvents()
{
    while(SDL_PollEvent(&event)) {
        if(event.type == SDL_WINDOWEVENT) {
            if(event.window.event == SDL_WINDOWEVENT_CLOSE) {
                m_bRunning = false;
                return;
            }
        }
    }	
    
}

void Game::clean()
{
    SDL_DestroyRenderer(m_pRenderer);
    SDL_DestroyWindow(m_pWindow);
    SDL_Quit();
}

bool Game::running()
{
    return m_bRunning;
}