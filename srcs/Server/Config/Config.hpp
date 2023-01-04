#ifndef CONFIG_HPP
# define CONFIG_HPP

# include <map>
# include <string>

namespace irc {
    class Config {
    
    private:
        std::map<std::string, std::string> values;

        void init(std::string config);

    public:
        Config();
        Config(std::string config);

        void set(std::string key, std::string value);
        std::string get(std::string key);
    };
}

#endif