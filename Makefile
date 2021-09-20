SRC_SERVER = 	minitalk_server.c\
				server_utils.c

SRC_MAP = srcs/

SRCS_SERVER = $(addprefix $(SRC_MAP), $(SRC_SERVER))

OBJS_SERVER=$(SRCS_SERVER:.c=.o)

SRC_CLIENT = 	minitalk_client.c\
				client_utils.c

SRCS_CLIENT = $(addprefix $(SRC_MAP), $(SRC_CLIENT))

OBJS_CLIENT=$(SRCS_CLIENT:.c=.o)

HDRS = -I hdrs/ -I libft/hdrs

LIBS = libft/libft.a

FLAGS = -Wall -Werror -Wextra

all: libft server client
	@echo "\033[1m\033[32mAll rule fulfilled ( Makefile )...\033[39m"

server : $(OBJS_SERVER)
	@clang -o $@ $^ $(LIBS) $(HDRS) $(FLAGS)
	@echo "\033[1m\033[32mServer Successfully Compiled\033[39m"
	
client : $(OBJS_CLIENT)
	@clang -o $@ $^ $(LIBS) $(HDRS) $(FLAGS)
	@echo "\033[1m\033[32mClient Successfully Compiled\033[39m"

%.o: %.c
	@clang -c $(FLAGS) -o $@ -c $< $(HDRS)

libft:
	@$(MAKE) -C libft/ all
	@echo "\033[1m\033[32mLibft library successfully built\033[39m"

clean:
	@$(RM) $(OBJS_SERVER) $(OBJS_CLIENT)
	@$(MAKE) -C libft/ clean
	@echo "\033[1m\033[33mDeleted  Object Files\033[39m"

fclean: clean
	@$(RM) server client
	@$(MAKE) -C libft/ fclean
	@echo "\033[1m\033[31mDeleted Objects and Executables\033[39m"

re: fclean all

.PHONY: libft minitalk all clean fclean re
