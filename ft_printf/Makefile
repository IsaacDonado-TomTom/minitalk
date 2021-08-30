# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: idonado <idonado@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/28 12:23:24 by idonado       #+#    #+#                  #
#    Updated: 2021/08/30 20:45:09 by idonado       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = 	check_all.c\
		check_dot_num.c\
		check_dot_star.c\
		check_dot.c\
		check_left.c\
		check_mwidth.c\
		check_num_dot_num.c\
		check_num_dot_star.c\
		check_star_dot.c\
		check_star.c\
		check_num_dot.c\
		check_star_dot_num.c\
		check_star_dot_star.c\
		check_zeroes.c\
		print_data.c\
		ft_atoi.c\
		ft_chrjoin.c\
		ft_chrrjoin.c\
		ft_hexgen_long.c\
		ft_isdigit.c\
		ft_hexgen.c\
		ft_itoa_unsigned.c\
		ft_itoa.c\
		ft_printf_utils_a.c\
		ft_printf_utils_b.c\
		ft_printf.c\
		ft_strdup.c\
		ft_strlen.c\
		p_char.c\
		p_char_utils.c\
		p_hex.c\
		p_hex_utils_a.c\
		p_hex_utils_b.c\
		p_hex_utils_c.c\
		p_hex_utils_d.c\
		p_int.c\
		p_int_utils_a.c\
		p_int_utils_b.c\
		p_int_utils_c.c\
		p_int_utils_d.c\
		p_pct.c\
		p_ptr.c\
		p_ptr_utils_a.c\
		p_ptr_utils_b.c\
		p_ptr_utils_c.c\
		p_ptr_utils_d.c\
		p_str.c\
		p_str_utils_a.c\
		p_str_utils_b.c\
		p_str_utils_c.c\
		p_uint.c\
		p_uint_utils_a.c\
		p_uint_utils_b.c\
		p_uint_utils_c.c\
		wipe_struct.c

OBJ		= $(SRC:.c=.o)
CFLAG	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAG) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re ft_printf