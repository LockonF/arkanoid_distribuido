//
//  udp_client.cpp
//  Arkanoid_Message_Client
//
//  Created by Daniel Franco on 7/15/15.
//  Copyright (c) 2015 Daniel. All rights reserved.
//


#include "udp_client.h"

udp_client::udp_client(boost::asio::io_service &io_service, std::string host, std::string port): receiver_endpoint(boost::asio::ip::address::from_string(host.c_str()), std::atoi(port.c_str())), socket(io_service),timer1_(io_service, boost::posix_time::seconds(1)),timer2_(io_service, boost::posix_time::seconds(1)),strand_(io_service)

{
    
    timer2_.async_wait(strand_.wrap(boost::bind(&udp_client::keep_receiving, this)));
    socket.open(udp::v4());
    g_game = 0;
    
    
    g_game = new Game();
    
    g_game->init("Proyecto Final: Arkanoid", 100, 100, 600, 800, SDL_WINDOW_SHOWN);
    
    tab.inicializar_juego();
    

}

void udp_client::run_game(){
    
    const int FPS = 60; //Cuantos frames por segundo queremos, 60 es el que utilizan los televisores
    const int DELAY_TIME = 1000.0f / FPS;  //1000 ms entre los fps da el numero de milisegundos entre cada frame
    bool m_bRunning = true;
    srand (time(NULL));
    
    Uint32 frameStart, frameTime;

    
    while(g_game->running())
    {
        
        frameStart = SDL_GetTicks(); //Numero de ms desde el inicio del programa
        
        g_game->handleEvents();
        tab.tab = g_game->update(tab.tab);
        g_game->render();
        std:string serialized(Serializador::serializarTablero(tab));
        send(serialized);
        frameTime = SDL_GetTicks() - frameStart;  //Tiempo que ha tardado en presentarse el frame
        if(frameTime< DELAY_TIME)  //Si es menor al tiempo que debería ser
        {
            SDL_Delay((int)(DELAY_TIME - frameTime)); //Espera un tiempo
        }
        

    }
    
    g_game->clean();
    
}


void udp_client::close()
{
    socket.close();
}

void udp_client::send(std::string message)
{
    boost::shared_ptr<std::string> send_message(new std::string(message));
    socket.send_to(boost::asio::buffer(*send_message), receiver_endpoint);
}

std::string udp_client::receive()
{
    boost::array<char, 9000> recv_buf;
    recv_buf.assign('\0');
    size_t len = socket.receive_from(boost::asio::buffer(recv_buf), sender_endpoint);
    return std::string(recv_buf.data());

}


void udp_client::keep_receiving()
{
    std::string msg("jugador");
    //Construimos el mensaje
    this->send(msg);

    while (g_game->running()) {

        std::string deserialized(receive());
        std::cout<<"Recibi "<<std::endl<<deserialized<<std::endl;
        std::cout<<"Soy el jugador "<<tab.tab.num_jugador<<std::endl;
        Tablero::tablero tabSync= Serializador::deserializarTablero(deserialized);
        if(tabSync.num_jugador!=0)
        {
            tab.tab.num_jugador = tabSync.num_jugador;
            std::cout<<"Soy el jugador "<<tab.tab.num_jugador<<std::endl;

        }
        else{
            switch (tab.tab.num_jugador) {
                case 1:
                    tab.tab.barraJ2=tabSync.barraJ2;
                    tab.tab.barraJ3=tabSync.barraJ3;
                    break;
                case 2:
                    tab.tab.barraJ1=tabSync.barraJ1;
                    tab.tab.barraJ3=tabSync.barraJ3;
                    break;
                case 3:
                    tab.tab.barraJ1=tabSync.barraJ1;
                    tab.tab.barraJ2=tabSync.barraJ2;
                    break;
                default:
                    break;
            }
        }
        timer1_.expires_at(timer1_.expires_at() + boost::posix_time::millisec(10));
        timer1_.async_wait(strand_.wrap(boost::bind(&udp_client::keep_receiving, this)));

    }
    
}
