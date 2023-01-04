#include "Channel.hpp"
#include "../../User/User.hpp"

irc::Channel::Channel(): mode("n") {}

void irc::Channel::setName(std::string name) { this->name = name; }
std::string irc::Channel::getName() { return (name); }

void irc::Channel::setTopic(std::string topic) { this->topic = topic; }
std::string irc::Channel::getTopic() { return (topic); }

