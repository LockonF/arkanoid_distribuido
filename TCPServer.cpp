//
//  TCPServer.cpp
//  Poco_Server
//
//  Created by Daniel Franco on 7/13/15.
//  Copyright (c) 2015 Daniel. All rights reserved.
//

#include "TCPServer.h"

void TCPServer::do_accept()
{
    acceptor_.async_accept(socket_,
    [this](boost::system::error_code ec)
    {
        if (!ec)
        {
        std::make_shared<game_session>(std::move(socket_), room_)->start();
        }
        do_accept();
    });

    
}