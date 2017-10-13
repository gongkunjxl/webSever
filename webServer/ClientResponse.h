//
//  ClientResponse.h
//  webServer
//
//  Created by 龚坤 on 2017/10/12.
//  Copyright © 2017年 龚坤. All rights reserved.
/*
  *主要用于和client建立连接和数据处理
*/

#ifndef ClientResponse_h
#define ClientResponse_h

#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/SocketStream.h>
#include <Poco/Net/StreamSocket.h>
#include <cpprest/uri.h>
#include <cpprest/http_listener.h>
#include <cpprest/asyncrt_utils.h>

using namespace web;
using namespace http;
using namespace utility;
using namespace http::experimental::listener;


class ClientResponse
{
public:
    ClientResponse(utility::string_t url);
    ~ClientResponse();
    
    //函数
    pplx::task<void> open() { return m_listener.open(); }
    pplx::task<void> close() { return m_listener.close(); }
private:
    void handle_get_or_post(http_request message);
    http_listener m_listener;
};





#endif /* ClientResponse_h */










