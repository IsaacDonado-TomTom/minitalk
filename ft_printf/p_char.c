/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_char.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/18 17:50:48 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/01 14:40:39 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_data	p_c_num_dot(const char *format, t_data data, va_list args)
{
	char	c;
	char	*str;
	char	*str_spaces;
	int		i;
	int		mwidth;

	c = va_arg(args, int);
	mwidth = ft_atoi(format + data.i_num_dot.i);
	str = ft_strdup("");
	str = ft_chrjoin(str, c);
	str_spaces = ft_strdup("");
	i = 0;
	while (i < mwidth - 1)
	{
		str_spaces = (data.zeroes == true && data.left == false) \
		? ft_chrjoin(str_spaces, '0') : ft_chrjoin(str_spaces, ' ');
		i++;
	}
	if (data.left == true)
		str = smart_join(str, str_spaces);
	else
		str = smart_join(str_spaces, str);
	data.result = print_str(str);
	if (c == 0)
		data.result = data.result + 1;
	free(str);
	return (data);
}

static t_data	p_c_star_dot(t_data data, va_list args)
{
	char	c;
	char	*str;
	char	*str_spaces;
	int		i;
	int		mwidth;

	mwidth = va_arg(args, int);
	c = va_arg(args, int);
	str = ft_strdup("");
	str = ft_chrjoin(str, c);
	str_spaces = ft_strdup("");
	i = 0;
	while (i < mwidth - 1)
	{
		str_spaces = (data.zeroes == true && data.left == false) \
		? ft_chrjoin(str_spaces, '0') : ft_chrjoin(str_spaces, ' ');
		i++;
	}
	if (data.left == true)
		str = smart_join(str, str_spaces);
	else
		str = smart_join(str_spaces, str);
	data.result = print_str(str);
	if (c == 0)
		data.result = data.result + 1;
	free(str);
	return (data);
}

static t_data	p_c_num_dot_star(const char *format, t_data data, va_list args)
{
	char	c;
	t_vars	vars;

	vars.i = 0;
	vars = vars_init(vars);
	va_arg(args, int);
	c = va_arg(args, int);
	vars.min_width = ft_atoi(format + data.i_num_dot.i);
	vars.str = ft_strdup("");
	vars.str = ft_chrjoin(vars.str, c);
	vars.spaces = ft_strdup("");
	while (vars.i < vars.min_width - 1)
	{
		vars.spaces = (data.zeroes == true && data.left == false) \
		? ft_chrjoin(vars.spaces, '0') : ft_chrjoin(vars.spaces, ' ');
		vars.i++;
	}
	if (data.left == true)
		vars.str = smart_join(vars.str, vars.spaces);
	else
		vars.str = smart_join(vars.spaces, vars.str);
	data.result = print_str(vars.str);
	if (c == 0)
		data.result = data.result + 1;
	free(vars.str);
	return (data);
}

static t_data	p_c_star_dot_star(t_data data, va_list args)
{
	char	c;
	t_vars	vars;

	vars.i = 0;
	vars.min_width = va_arg(args, int);
	va_arg(args, int);
	c = va_arg(args, int);
	vars.str = ft_strdup("");
	vars.str = ft_chrjoin(vars.str, c);
	vars.spaces = ft_strdup("");
	while (vars.i < vars.min_width - 1)
	{
		vars.spaces = (data.zeroes == true && data.left == false) \
		? ft_chrjoin(vars.spaces, '0') : ft_chrjoin(vars.spaces, ' ');
		vars.i++;
	}
	if (data.left == true)
		vars.str = smart_join(vars.str, vars.spaces);
	else
		vars.str = smart_join(vars.spaces, vars.str);
	data.result = print_str(vars.str);
	if (c == 0)
		data.result = data.result + 1;
	free(vars.str);
	return (data);
}

t_data			p_char(const char *format, t_data data, va_list args)
{
	if (data.mwidth == true)
		data = p_c_mwidth(format, data, args);
	else if (data.star == true)
		data = p_c_star(data, args);
	else if (data.num_dot == true)
		data = p_c_num_dot(format, data, args);
	else if (data.star_dot == true)
		data = p_c_star_dot(data, args);
	else if (data.star_dot_num == true)
		data = p_c_star_dot(data, args);
	else if (data.num_dot_star == true)
		data = p_c_num_dot_star(format, data, args);
	else if (data.star_dot_star == true)
		data = p_c_star_dot_star(data, args);
	else if (data.dot_star == true || data.dot_num == true)
		data = data.dot_star == true \
		? p_c_dot_num(data, args, 1) : p_c_dot_num(data, args, 0);
	else if (data.num_dot_num == true)
	{
		data.i_num_dot.i = data.i_num_dot_num.i;
		data = p_c_num_dot(format, data, args);
	}
	else
		data.result = print_char(va_arg(args, int));
	return (data);
}
