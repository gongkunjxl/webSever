//
//  ClientResponse.cpp
//  webServer
//
//  Created by 龚坤 on 2017/10/12.
//  Copyright © 2017年 龚坤. All rights reserved.
//

#include <stdio.h>
#include "ClientResponse.h"

//客户端监听
ClientResponse::ClientResponse(utility::string_t url) : m_listener(url)
{
    m_listener.support(methods::GET, std::bind(&ClientResponse::handle_get_or_post, this, std::placeholders::_1));
    m_listener.support(methods::POST, std::bind(&ClientResponse::handle_get_or_post, this, std::placeholders::_1));
}

//url解析
void ClientResponse::handle_get_or_post(http_request message)
{
    
    ucout << "Method: " << message.method() << std::endl;
    ucout << "URI: " << http::uri::decode(message.relative_uri().path()) << std::endl;
//    ucout << "URL: " << http::uri::decode(message.request_uri().path()) << std::endl;
    
    ucout << "Query: " << http::uri::decode(message.relative_uri().query()) << std::endl << std::endl;
    message.reply(status_codes::OK, "ACCEPTED");
}

ClientResponse::~ClientResponse()
{
    
}






























