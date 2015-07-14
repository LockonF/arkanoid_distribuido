//
//  TCPServer.cpp
//  Poco_Server
//
//  Created by Daniel Franco on 7/13/15.
//  Copyright (c) 2015 Daniel. All rights reserved.
//

#include "TCPServer.h"

TCPServer::TCPServer(boost::asio::io_service& io_service, int port)
: acceptor_(io_service, tcp::endpoint(tcp::v4(), port))
{
    start_accept();
}

void TCPServer::start_accept()
{
    //Generamos una nueva conexión tcp
    tcp_connection::pointer new_connection = tcp_connection::create(acceptor_.get_io_service());
}

void TCPServer::handle_accept(tcp_connection::pointer new_connection, const boost::system::error_code& error)
{
    if (!error)
    {
        new_connection->start();
        start_accept();
    }
}