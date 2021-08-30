/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_char_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/26 15:16:32 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/01 14:53:51 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	p_c_mwidth_result(t_vars vars, t_data data)
{
	if (vars.number == '\0' && data.left == true)
	{
		data.result = print_char('\0');
		data.result = data.result + print_str(vars.str);
	}
	else if (vars.number == '\0' && data.left == false)
	{
		data.result = print_str(vars.str);
		data.result = data.result + print_char('\0');
	}
	else
	{
		data.result = print_str(vars.str);
	}
	return (data.result);
}

t_data		p_c_mwidth(const char *format, t_data data, va_list args)
{
	t_vars vars;

	vars.i = 0;
	vars = vars_init(vars);
	vars.number = va_arg(args, int);
	vars.min_width = ft_atoi(format + data.i_mwidth.i);
	vars.str = ft_strdup("");
	if (vars.number != '\0')
		vars.str = ft_chrjoin(vars.str, vars.number);
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
	data.result = p_c_mwidth_result(vars, data);
	free(vars.str);
	return (data);
}

t_data		p_c_star(t_data data, va_list args)
{
	t_vars vars;

	vars.i = 0;
	vars = vars_init(vars);
	vars.min_width = va_arg(args, int);
	if (vars.min_width < 0)
		data = switch_negative(&vars.min_width, data);
	vars.number = va_arg(args, int);
	vars.str = ft_strdup("");
	if (vars.number != '\0')
		vars.str = ft_chrjoin(vars.str, vars.number);
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
	data.result = p_c_mwidth_result(vars, data);
	free(vars.str);
	return (data);
}

t_data	p_c_dot_num(t_data data, va_list args, int n)
{
	char	c;
	t_vars	vars;

	vars.i = 0;
	vars = vars_init(vars);
	vars.str = ft_strdup("");
	if (n == 1)
		va_arg(args, int);
	c = va_arg(args, int);
	vars.str = ft_chrjoin(vars.str, c);
	data.result = print_str(vars.str);
	if (c == 0)
		data.result = data.result + 1;
	if (vars.str == NULL)
		data.result = -1;
	free(vars.str);
	return (data);
}
