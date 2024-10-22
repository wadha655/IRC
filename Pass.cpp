#include "Command.hpp"


void	Command::Pass_cmd( void )
 {
	if (this->userN.isAuthntec())
		return (sendMessage(RED "Error: User already registered!" RESET, "462"));
	if (this->_args.empty() || this->_args.size() != 1)
		return (sendMessage(RED "Error: usage: /PASS <password>" RESET, "461"));
	if (this->_args[0] == this->_ircServer.getpass()) {
		this->userN.Authn();
		return (sendMessage(GREEN "successfully Password Correct!" RESET, "338"));
	} else
		return (sendMessage(RED "Error: Incorrect Password!" RESET, "339"));
}

