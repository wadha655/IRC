

#ifndef SERVER_H
#define SERVER_H

#include "irc.hpp"
class Server
{
    private:
        std::string     m_host;
        std::string     m_port;
        std::string     m_password;
        int             m_serverfd; //listening socket 
        std::vector<pollfd> m_fds;
        std::vector<Client*>		m_clientsVec; 
        std::vector<Channel*>	m_channelsVec; 
	    void				_checkPoll(void);
	    void				_createClient(void);
        void				_messageReceived(int fd);
    public:
        Server(std::string m_host, std::string port, std::string pass);
        void initialize_server(); 
        void receive();
        Client *getClientByFd(int fd);
        std::string getpass();
        std::string getport();
		std::vector<Client *>	getClients(void);
		bool	checkOperators( void );
		void	messageAllclients(std::string message);
		void	messageToServer(std::string msg, int userFd);
		void	deleteClient(int fd);
		Client	*getClientByNick(std::string nick);
		Channel*				getChannelByName(std::string name);
		void	addChannel( Channel *channel );
		int	getServerFd( void );
		~Server();

};
#endif