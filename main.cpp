// main.cpp
// Este archivo contiene la ejecucion principal del programa, hace uso de la clase Game, la cual contiene todos los metodos necesarios para la generacion de la aplicacion, asi como el uso de la funcion SDL_Delay para un optimo desplazamiento de los objetos.

#include <iostream>
#include "udp_client.h"




int main(int argc, char* argv[])
{

    
    std::string host = "127.0.0.1";
    std::string port = "7200";
    
    boost::asio::io_service io_service;
    
    
    //Nos conectamos al servicio. Los parámetros son del host al cual vamos a bindear
    udp::resolver resolver(io_service);
    udp_client c(io_service, host, port);
    

    //Separamos el thread, esto para poder escribir con cin, pero en el caso del juego es para que pueda seguir ejecutándose en su propio demonio. Con el método write de TCPClient podemos escribir sin problemas dentro del hilo principal
    boost::thread t(boost::bind(&boost::asio::io_service::run, &io_service));
    
    //Se queda recibiendo del servidor
    c.run_game(io_service);

    c.keep_receiving();

    t.join();
    
    
	
}