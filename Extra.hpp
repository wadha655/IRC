
#ifndef EXTRA_HPP
#define EXTRA_HPP

#include "irc.hpp"


class Client;
class Extra
{
	public:
    static bool invalidChar(std::string s);
    void startM(void);
    static std::vector<std::string> split(std::string s, char c);
    static std::string	joinSplitItr( std::vector<std::string>::iterator first, std::vector<std::string>::iterator last );
	static std::string	joinSplit( std::vector<Client *> users);
    static std::string	toupper( std::string s );
    
};





#endif