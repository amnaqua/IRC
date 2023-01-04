#include "Server/Server.hpp"
#include <iostream>
#include <csignal>

bool stop = false;

void handler(int) { stop = true; }

int main (int argc, char **argv) 
{
    if (argc != 3) 
    {
        std::cout << "./ircserv <port> <password>" << std::endl;
        return (1);
    }
}