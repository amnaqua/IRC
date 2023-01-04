#include "Utils.hpp"
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <sstream>

std::string irc::currentTime() 
{
    time_t t = std::time(0);
    struct tm *now = std::localtime(&t);
    std::string time(asctime(now));
    time.erase(--time.end());
    return (time);
}

//? stop - флаг для остановки работы программы в случае критической ошибки
void irc::error(std::string message, bool stop) 
{ 
    std::cerr << "Error: " << message << std::endl;
    if (stop) 
        exit(EXIT_FAILURE);
}

std::vector<std::string> irc::split(std::string str, std::string delimeter) 
{
    std::vector<std::string> values = std::vector<std::string>();

    size_t position;
    while((position = str.find(delimeter)) != std::string::npos) 
    {
        values.push_back(str.substr(0, position));
        str.erase(0, position + delimeter.length());
    }
    values.push_back(str);

    return (values);
}