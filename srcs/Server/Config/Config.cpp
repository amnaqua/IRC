#include "Config.hpp"
#include "../../utils/Utils.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib>

void irc::Config::init(std::string config) 
{
    std::ifstream readConf(config.c_str(), std::ifstream::in); // читаем конфиг
    if (!readConf.good()) // проверяем статус ifstream
        error("Config error", true);

    size_t pos;
    std::string str;
    while (!readConf.eof()) 
    {
        str = "";
        std::getline(readConf, str);
        if ((pos = str.find('=')) == std::string::npos) //* если не найдено '=' в строке
            continue;
        std::string key = str.substr(0, pos); // сохраняем ключ
        str.erase(0, pos + 1); // удаляем ключ из строки

        if (str.find("./") == 0) //* если нужно считать значение из файла
        {
            std::ifstream file(str.c_str(), std::ifstream::in);
            std::stringstream buffer;
            buffer << file.rdbuf();
            str = buffer.str();
            file.close();
        }

        values[key] = str; // сохраняем значение переменной конфига в мапу
    }
    readConf.close();
}

irc::Config::Config() { init("./config/default.config"); }
irc::Config::Config(std::string config) { init(config); }

void irc::Config::set(std::string key, std::string value) { values[key] = value; }

std::string irc::Config::get(std::string key) { return (values[key]); }