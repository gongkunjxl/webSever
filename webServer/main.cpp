#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/SocketStream.h>
#include <Poco/Net/StreamSocket.h>


#include <stdio.h>
#include <iostream>
#include "ClientResponse.h"
#include "SqlHandle.h"
#include "LogHandle.h"
#include "FutuHandle.h"

int main(int argc, char **arg)
{
    try
    {
        utility::string_t address = U("http://0.0.0.0:8080");
        uri_builder uri(address);
        auto addr = uri.to_uri().to_string();
        ClientResponse handler(addr);
        handler.open().wait();
        
        ucout << utility::string_t(U("Listening for requests at: ")) << addr << std::endl;
        ucout << U("Press ENTER key to quit...") << std::endl;
        std::string line;
        std::getline(std::cin, line);
        handler.close().wait();
    }
    catch (std::exception& ex)
    {
        ucout << U("Exception: ") << ex.what() << std::endl;
        ucout << U("Press ENTER key to quit...") << std::endl;
        std::string line;
        std::getline(std::cin, line);
    }
    return 0;
}






















