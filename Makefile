NAME = ircserv
SRC =  Channel.cpp Command.cpp Client.cpp Server.cpp Extra.cpp  main.cpp\
		 Help.cpp Invite.cpp Join.cpp Kick.cpp\
		  Kill.cpp Mode.cpp Nick.cpp Oper.cpp Part.cpp\
		   Pass.cpp Privmsg.cpp Quit.cpp Topic.cpp User.cpp
OBJS = ${SRC:.cpp=.o}

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 

COLOR_RESET = \033[0m
COLOR_PINK = \033[95m
COLOR_YELLOW = \033[93m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CPPFLAGS) $(OBJS)  -o $(NAME)
	@echo "$(COLOR_PINK)Build successful$(COLOR_RESET)"

%.o: %.cpp
	@$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS)
	@echo "$(COLOR_YELLOW)Objects removed$(COLOR_RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(COLOR_YELLOW)Executable removed$(COLOR_RESET)"

re: fclean all

