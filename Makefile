SRC_SERVER = 	minitalk_server.c\

SRC_MAP_SERVER = srcs_server/

SRCS_SERVER = $(addprefix $(SRC_MAP_SERVER), $(SRC_SERVER))

OBJS_SERVER=$(SRCS_SERVER:.c=.o)

SRC_CLIENT = 	minitalk_client.c\

SRC_MAP_CLIENT = srcs_client/

SRCS_CLIENT = $(addprefix $(SRC_MAP_CLIENT), $(SRC_CLIENT))

OBJS_CLIENT=$(SRCS_CLIENT:.c=.o)

HDRS = -I hdrs/ -I libft/hdrs -I ft_printf/

LIBS = libft/libft.a ft_printf/libftprintf.a

FLAGS = -Wall -Werror -Wextra -g -fsanitize=address

all: libft ft_printf server client
	@echo "\033[1m\033[32mAll rule fulfilled ( Makefile )...\033[39m"

server : $(OBJS_SERVER)
	@clang -o $@ $^ $(LIBS) $(HDRS) $(FLAGS)
	@echo "\033[1m\033[32mServer Successfully Compiled\033[39m"
	
client : $(OBJS_CLIENT)
	@clang -o $@ $^ $(LIBS) $(HDRS) $(FLAGS)
	@echo "\033[1m\033[32mClient Successfully Compiled\033[39m"

%.o: %.c
	@clang -c $(FLAGS) -o $@ -c $< $(HDRS)

ft_printf:
	@$(MAKE) -C ft_printf/ all
	@echo "\033[1m\033[32mft_printf library successfully built\033[39m"

libft:
	@$(MAKE) -C libft/ all
	@echo "\033[1m\033[32mLibft library successfully built\033[39m"

clean:
	@$(RM) $(OBJS_SERVER) $(OBJS_CLIENT)
	@$(MAKE) -C libft/ clean
	@$(MAKE) -C ft_printf/ clean
	@echo "\033[1m\033[33mDeleted  Object Files\033[39m"

fclean: clean
	@$(RM) server client
	@$(MAKE) -C libft/ fclean
	@$(MAKE) -C ft_printf/ fclean
	@echo "\033[1m\033[31mDeleted Objects and Executables\033[39m"

re: fclean all

.PHONY: libft ft_printf minitalk all clean fclean re
