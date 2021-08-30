/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/26 21:13:33 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/01 21:49:28 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef	enum
{
	false, true
}	t_bool;

typedef	struct	s_locate
{
	size_t i;
	size_t j;
}				t_index;

typedef	struct	s_flags
{
	t_bool	left;
	t_bool	zeroes;
	t_bool	dot_num;
	t_index	i_dot_num;
	t_bool	dot_star;
	t_bool	dot;
	t_bool	star;
	t_bool	star_dot;
	t_bool	star_dot_num;
	t_index	i_star_dot_num;
	t_bool	star_dot_star;
	t_bool	num_dot_star;
	t_index	i_num_dot_star;
	t_bool	num_dot;
	t_index	i_num_dot;
	t_bool	num_dot_num;
	t_index	i_num_dot_num;
	t_bool	check_combo;
	t_bool	check_all;
	t_bool	mwidth;
	t_index	i_mwidth;
	int		type_id;
	int		result;
	size_t	i;
	t_bool	format_detected;
}				t_data;

typedef	struct	s_vars
{
	char			*str;
	char			*spaces;
	char			*zeroes;
	char			*ptr;
	int				str_width;
	int				min_width;
	int				precision;
	int				i;
	int				number;
	unsigned int	unumber;
	unsigned long	ulnumber;
	int				ptr_trigger;
	t_bool			is_negative;
	t_bool			prec_negative;
	t_bool			print_fail;
}				t_vars;

int				ft_printf(const char *format, ...);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *str);
char			*ft_itoa(int n);
char			*ft_itoa_unsigned(unsigned int n);
char			*ft_strchr(const char *s, int c);
char			*ft_chrjoin(char *str, int c);
char			*ft_chrrjoin(int c, char *str);
int				ft_isdigit(int c);
int				ft_atoi(const char *num);
char			*ft_hexgen(unsigned int number, int capital);
char			*ft_hexgen_long(unsigned long number);
t_data			wipe_struct(t_data flags_struct);
t_data			print_fail(t_data data, t_vars vars);
t_vars			vars_init(t_vars vars);
int				type_check(const char *format, size_t end);
int				check_all(t_data data);
t_data			print_data(const char *format, t_data data, va_list args);
t_data			check_zeroes(const char *format, t_data data);
t_data			check_left(const char *format, t_data data);
t_data			check_mwidth(const char *format, t_data data);
t_data			check_dot(const char *format, t_data data);
t_data			check_dot_num(const char *format, t_data data);
t_data			check_dot_star(const char *format, t_data data);
t_data			check_star(const char *format, t_data data);
t_data			check_star_dot(const char *format, t_data data);
t_data			check_star_dot_star(const char *format, t_data data);
t_data			check_star_dot_num(const char *format, t_data data);
t_data			check_num_dot(const char *format, t_data data);
t_data			check_num_dot_num(const char *format, t_data data);
t_data			check_num_dot_star(const char *format, t_data data);
t_data			str_mwidth(t_vars vars, t_data data);
t_vars			str_double_precision(t_data data, t_vars vars);
t_vars			str_double_mwidth(t_data data, t_vars vars);
t_data			p_str(const char *format, t_data data, va_list args);
t_data			p_str_star_dot(t_data data, va_list args);
t_data			p_str_star_dot_num(const char *format, \
t_data data, va_list args);
t_data			p_str_num_dot_num(const char *format, \
t_data data, va_list args);
t_data			p_str_num_dot_star(const char *format, \
t_data data, va_list args);
t_data			p_str_star_dot_star(t_data data, va_list args);
t_data			p_str_num_dot(const char *format, t_data data, va_list args);
t_data			p_str_dot_num(const char *format, t_data data, va_list args);
t_data			p_str_dot(t_data data, va_list args);
t_data			p_char(const char *format, t_data data, va_list args);
t_data			p_c_dot_num(t_data data, va_list args, int n);
t_data			p_c_star(t_data data, va_list args);
t_data			p_c_mwidth(const char *format, t_data data, va_list args);
t_vars			int_mwidth(t_data data, t_vars vars);
t_vars			int_dot_num(t_vars vars);
t_vars			int_num_dot(t_data data, t_vars vars);
t_vars			int_num_dot_num_a(t_vars vars);
t_vars			int_num_dot_num_b(t_data data, t_vars vars);
t_vars			int_num_dot_num_c(t_vars vars);
t_vars			is_int_negative(t_vars vars);
t_vars			int_star_vars(t_vars vars, va_list args);
t_vars			int_ds_vars(t_vars vars, va_list args);
t_data			p_int(const char *format, t_data data, va_list args);
t_data			p_int_num_dot_num(const char *format, \
t_data data, va_list args);
t_data			p_int_num_dot_star(const char *format, \
t_data data, va_list args);
t_data			p_int_star_dot_num(const char *format, \
t_data data, va_list args);
t_data			p_int_star_dot_star(t_data data, va_list args);
t_data			p_int_dot_num(const char *format, t_data data, va_list args);
t_data			p_int_dot_star(t_data data, va_list args);
t_data			p_int_star(t_data data, va_list args);
t_data			p_int_mwidth(const char *format, t_data data, va_list args);
t_vars			uint_num_dot_num_c(t_vars vars);
t_vars			uint_mwidth(t_data data, t_vars vars);
t_vars			uint_dot_num(t_vars vars);
t_vars			uint_num_dot(t_data data, t_vars vars);
t_vars			uint_num_dot_num(t_vars vars);
t_data			p_uint(const char *format, t_data data, va_list args);
t_data			p_uint_num_dot_num(const char *format, \
t_data data, va_list args);
t_data			p_uint_num_dot_star(const char *format, \
t_data data, va_list args);
t_data			p_uint_star_dot_num(const char *format, \
t_data data, va_list args);
t_data			p_uint_star_dot_star(t_data data, va_list args);
t_data			p_uint_mwidth(const char *format, t_data data, va_list args);
t_data			p_uint_star(t_data data, va_list args);
t_data			p_uint_dot_star(t_data data, va_list args);
t_data			p_uint_dot_num(const char *format, t_data data, va_list args);
t_vars			uint_sd_vars(t_vars vars, t_data data, va_list args);
char			*ft_hexgen_xl(unsigned int number);
t_vars			hex_capital_check(t_vars vars, int capital);
t_vars			hex_sds_var(t_vars vars, va_list args, t_data data, int cap);
t_vars			hex_sdn_var(const char *format, \
t_vars vars, va_list args, t_data data);
t_vars			hex_nds_var(const char *format, \
t_vars vars, va_list args, t_data data);
t_vars			hex_ndn_var(const char *format, \
t_vars vars, va_list args, t_data data);
t_vars			hex_double_precision(t_vars vars);
t_vars			hex_double_mwidth(t_data data, t_vars vars);
t_vars			hex_mwidth(t_data data, t_vars vars);
t_vars			hex_dn(t_vars vars);
t_vars			hex_nd(t_data data, t_vars vars);
t_data			p_hex(const char *format, t_data data, va_list args, int cap);
t_data			p_hex_ndn(const char *format, \
t_data data, va_list args, int cap);
t_data			p_hex_nds(const char *format, \
t_data data, va_list args, int cap);
t_data			p_hex_sdn(const char *format, \
t_data data, va_list args, int cap);
t_data			p_hex_sds(t_data data, va_list args, int cap);
t_data			p_hex_nd(const char *format, \
t_data data, va_list args, int cap);
t_data			p_hex_ds(t_data data, va_list args, int cap);
t_data			p_hex_mwidth(const char *format, \
t_data data, va_list args, int cap);
t_data			p_hex_star(t_data data, va_list args, int cap);
t_data			p_hex_dn(const char *format, \
t_data data, va_list args, int cap);
t_vars			ptr_double_check(t_data data, t_vars vars);
t_vars			ptr_double_mwidth(t_data data, t_vars vars);
t_vars			ptr_double_precision(t_vars vars);
t_vars			ptr_dot_num(t_vars vars);
t_vars			ptr_mwidth(t_data data, t_vars vars);
t_vars			ptr_mwidth_if(t_vars vars, t_data data);
t_data			p_ptr(const char *format, t_data data, va_list args);
t_data			p_ptr_mwidth(const char *format, t_data data, va_list args);
t_data			p_ptr_star(t_data data, va_list args);
t_data			p_ptr_num_dot(const char *format, t_data data, va_list args);
t_data			p_ptr_num_star(t_data data, va_list args);
t_data			p_ptr_num_dot_num(const char *format, \
t_data data, va_list args);
t_vars			ptr_ndn_vars(char *str, t_vars vars, t_data data, va_list args);
t_vars			ptr_nds_vars(char *str, t_vars vars, t_data data, va_list args);
t_vars			ptr_sdn_vars(char *str, t_vars vars, t_data data, va_list args);
t_vars			ptr_sds_vars(t_vars vars, va_list args);
t_vars			ptr_ds_vars(t_vars vars, va_list args);
t_data			p_ptr_dot_star(t_data data, va_list args);
t_data			p_ptr_dot_num(const char *format, t_data data, va_list args);
t_data			p_ptr_dot(t_data data, va_list args);
t_data			p_pct(const char *format, t_data data, va_list args);
int				print_char(char c);
int				print_str(char *s);
char			*smart_join(char *s1, char *s2);
t_data			switch_negative(int *mwidth, t_data data);

#endif
