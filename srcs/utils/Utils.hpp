#ifndef UTILS_HPP
# define UTILS_HPP

# include <string>
# include <vector>

# ifndef DEBUG
#  define DEBUG 0
# endif

namespace irc
{
    std::string currentTime();

    void error(std::string message, bool stop);

    std::vector<std::string> split(std::string str, std::string delimeter);

    bool isLetter(char c);
    bool isSpecial(char c);
    bool isDigit(char c);

    std::string toString(size_t var);

    bool strmatch(std::string str, std::string pattern);
}

#endif