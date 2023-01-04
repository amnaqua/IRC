#include "Display.hpp"
#include "../../utils/Utils.hpp"
#include <iostream>

//? "\033[2J" - код очистки терминала
void irc::Display::clearScreen() { std::cout << "\033[2J" << std::flush; }

void irc::Display::update() 
{
    clearScreen();

    for (std::map<unsigned char, std::string>::iterator it = lines.begin(); it != lines.end(); ++it)
        std::cout << it->second << "\033[0m" << std::endl;
}

void irc::Display::set(unsigned char pos, std::string line) 
{
    if (lines[pos] == line)
        return;
    lines[pos] = line;
    update();
}

void irc::Display::remove(unsigned char pos) 
{
    lines.erase(pos);
    update();
}