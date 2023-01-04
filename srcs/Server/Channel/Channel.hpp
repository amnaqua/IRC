#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include <vector>
# include <map>
# include <string>

namespace irc 
{
    
    class User;

    class Channel 
    {
        
    private:
        std::string name;
        std::map<int, User *> users;
        std::string max_users;
        std::string mode;
        std::map<int, std::string> user_mode;
        std::string topic;

    public:
        Channel();

        void setName(std::string name);
        std::string getName();

        void setTopic(std::string topic);
        std::string getTopic();

        void addUser(User &user);
        void removeUser(User &user);
        void removeUser(std::string const &nickname);
        std::vector<User *> getUsers();

        void setMaxUsers(std::string max);
        std::string getMaxUsers();
    };
}

#endif