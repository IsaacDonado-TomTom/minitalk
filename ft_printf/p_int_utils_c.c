/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_int_utils_c.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/26 15:35:15 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/01 22:33:25 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_vars	int_num_dot_num_c(t_vars vars)
{
	if (vars.number == 0)
		vars.str = ft_strdup("");
	else
		vars.str = ft_itoa(vars.number);
	if (vars.str == NULL)
	{
		vars.print_fail = true;
		return (vars);
	}
	vars.str_width = ft_strlen(vars.str);
	if (vars.str_width < vars.precision)
	{
		vars.zeroes = ft_strdup("");
		if (vars.zeroes == NULL)
			vars.print_fail = true;
		vars = int_num_dot_num_a(vars);
		if (vars.str == NULL)
			vars.print_fail = true;
	}
	else if (vars.is_negative == true && vars.str[0] != '-')
		vars.str = ft_chrrjoin('-', vars.str);
	return (vars);
}

t_vars	is_int_negative(t_vars vars)
{
	if (vars.number < 0 && vars.number > -2147483648)
	{
		vars.number = vars.number * -1;
		vars.is_negative = true;
	}
	return (vars);
}

t_data	p_int_mwidth(const char *format, t_data data, va_list args)
{
	t_vars	vars;

	data.format_detected = true;
	vars.i = 0;
	vars = vars_init(vars);
	vars.number = va_arg(args, int);
	vars = is_int_negative(vars);
	vars.str = ft_itoa(vars.number);
	vars.min_width = ft_atoi(format + data.i_mwidth.i);
	vars.str_width = vars.is_negative == false \
	? ft_strlen(vars.str) : ft_strlen(vars.str) + 1;
	if (vars.min_width > vars.str_width)
	{
		vars.spaces = ft_strdup("");
		if (vars.spaces == NULL)
			return (print_fail(data, vars));
		vars = int_mwidth(data, vars);
		if (vars.str == NULL)
			return (print_fail(data, vars));
	}
	else if (vars.is_negative == true && vars.str[0] != '-')
		vars.str = ft_chrrjoin('-', vars.str);
	data.result = print_str(vars.str);
	free(vars.str);
	return (data);
}

t_data	p_int_star(t_data data, va_list args)
{
	t_vars	vars;

	data.format_detected = true;
	vars.i = 0;
	vars = vars_init(vars);
	vars.min_width = va_arg(args, int);
	data = switch_negative(&vars.min_width, data);
	vars = int_star_vars(vars, args);
	if (vars.str == NULL)
		return (print_fail(data, vars));
	vars.str_width = vars.is_negative == false \
	? ft_strlen(vars.str) : ft_strlen(vars.str) + 1;
	if (vars.str_width < vars.min_width)
	{
		vars.spaces = ft_strdup("");
		if (vars.spaces == NULL)
			return (print_fail(data, vars));
		vars = int_mwidth(data, vars);
		if (vars.str == NULL)
			return (print_fail(data, vars));
		data.result = print_str(vars.str);
	}
	else
	{
		if (vars.is_negative == true)
			vars.str = ft_chrrjoin('-', vars.str);
		data.result = print_str(vars.str);
	}
	free(vars.str);
	return (data);
}

t_data	p_int_dot_star(t_data data, va_list args)
{
	t_vars vars;

	data.format_detected = true;
	vars.i = 0;
	vars = int_ds_vars(vars, args);
	if (vars.str == NULL)
		return (print_fail(data, vars));
	vars.str_width = ft_strlen(vars.str);
	if (vars.number == 0 && vars.precision == 0)
		vars.str[0] = '\0';
	else if (vars.str_width < vars.precision)
	{
		vars.spaces = ft_strdup("");
		if (vars.spaces == NULL)
			return (print_fail(data, vars));
		vars = int_dot_num(vars);
		if (vars.str == NULL)
			return (print_fail(data, vars));
	}
	else if (vars.is_negative == true && vars.str[0] != '-')
		vars.str = ft_chrrjoin('-', vars.str);
	data.result = print_str(vars.str);
	free(vars.str);
	return (data);
}
