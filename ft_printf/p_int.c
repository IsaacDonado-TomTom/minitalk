/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_int.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 13:42:47 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/01 15:33:40 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_data	p_int_num_dot(const char *format, t_data data, va_list args)
{
	t_vars vars;

	data.format_detected = true;
	vars.i = 0;
	vars = vars_init(vars);
	vars.min_width = ft_atoi(format + data.i_num_dot.i);
	vars.number = va_arg(args, int);
	vars.str = ft_itoa(vars.number);
	if (vars.number == 0)
		vars.str[0] = '\0';
	if (vars.str == NULL)
		return (print_fail(data, vars));
	vars.str_width = ft_strlen(vars.str);
	if (vars.str_width < vars.min_width)
	{
		vars.spaces = ft_strdup("");
		if (vars.spaces == NULL)
			return (print_fail(data, vars));
		vars = int_num_dot(data, vars);
		if (vars.str == NULL)
			return (print_fail(data, vars));
	}
	data.result = print_str(vars.str);
	free(vars.str);
	return (data);
}

static t_data	p_int_star_dot(t_data data, va_list args)
{
	t_vars vars;

	data.format_detected = true;
	vars.i = 0;
	vars = vars_init(vars);
	vars.min_width = va_arg(args, int);
	data = switch_negative(&vars.min_width, data);
	vars.number = va_arg(args, int);
	vars.str = ft_itoa(vars.number);
	if (vars.number == 0)
		vars.str[0] = '\0';
	if (vars.str == NULL)
		return (print_fail(data, vars));
	vars.str_width = ft_strlen(vars.str);
	if (vars.str_width < vars.min_width)
	{
		vars.spaces = ft_strdup("");
		if (vars.spaces == NULL)
			return (print_fail(data, vars));
		vars = int_num_dot(data, vars);
		if (vars.str == NULL)
			return (print_fail(data, vars));
	}
	data.result = print_str(vars.str);
	free(vars.str);
	return (data);
}

static t_data	p_int_dot(t_data data, va_list args)
{
	t_vars vars;

	data.format_detected = true;
	vars.i = 0;
	vars = vars_init(vars);
	vars.number = va_arg(args, int);
	if (vars.number == 0)
		vars.str = ft_strdup("");
	else
		vars.str = ft_itoa(vars.number);
	if (vars.str == NULL)
		return (print_fail(data, vars));
	data.result = print_str(vars.str);
	free(vars.str);
	return (data);
}

t_data			check_int(const char *format, t_data data, va_list args)
{
	if (data.mwidth == true)
		data = p_int_mwidth(format, data, args);
	else if (data.star == true)
		data = p_int_star(data, args);
	else if (data.dot_star == true)
		data = p_int_dot_star(data, args);
	else if (data.dot_num == true)
		data = p_int_dot_num(format, data, args);
	else if (data.num_dot == true)
		data = p_int_num_dot(format, data, args);
	else if (data.star_dot == true)
		data = p_int_star_dot(data, args);
	else if (data.dot == true)
		data = p_int_dot(data, args);
	return (data);
}

t_data			p_int(const char *format, t_data data, va_list args)
{
	char	*str;

	data.format_detected = false;
	data = check_int(format, data, args);
	if (data.num_dot_num == true)
		data = p_int_num_dot_num(format, data, args);
	else if (data.num_dot_star == true)
		data = p_int_num_dot_star(format, data, args);
	else if (data.star_dot_num == true)
		data = p_int_star_dot_num(format, data, args);
	else if (data.star_dot_star == true)
		data = p_int_star_dot_star(data, args);
	else if (data.format_detected == false)
	{
		str = ft_itoa(va_arg(args, int));
		data.result = print_str(str);
		free(str);
	}
	return (data);
}
