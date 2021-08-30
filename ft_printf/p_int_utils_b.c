/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_int_utils_b.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 15:51:07 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/01 21:50:45 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	p_int_num_dot_num(const char *format, t_data data, va_list args)
{
	t_vars vars;

	data.format_detected = true;
	vars.i = 0;
	vars = vars_init(vars);
	vars.min_width = ft_atoi(format + data.i_num_dot_num.i);
	vars.precision = ft_atoi(format + data.i_num_dot_num.j);
	vars.number = va_arg(args, int);
	vars = is_int_negative(vars);
	vars = int_num_dot_num_c(vars);
	if (vars.print_fail == true)
		return (print_fail(data, vars));
	vars.str_width = ft_strlen(vars.str);
	vars.i = 0;
	if (vars.str_width < vars.min_width)
	{
		vars.spaces = ft_strdup("");
		if (vars.spaces == NULL)
			return (print_fail(data, vars));
		vars = int_num_dot_num_b(data, vars);
		if (vars.str == NULL)
			return (print_fail(data, vars));
	}
	data.result = print_str(vars.str);
	return (data);
}

t_data	p_int_num_dot_star(const char *format, t_data data, va_list args)
{
	t_vars vars;

	data.format_detected = true;
	vars.i = 0;
	vars = vars_init(vars);
	vars.min_width = ft_atoi(format + data.i_num_dot_star.i);
	vars.precision = va_arg(args, int);
	vars.number = va_arg(args, int);
	vars = is_int_negative(vars);
	vars = int_num_dot_num_c(vars);
	if (vars.print_fail == true)
		return (print_fail(data, vars));
	vars.str_width = ft_strlen(vars.str);
	vars.i = 0;
	if (vars.str_width < vars.min_width)
	{
		vars.spaces = ft_strdup("");
		if (vars.spaces == NULL)
			return (print_fail(data, vars));
		vars = int_num_dot_num_b(data, vars);
		if (vars.str == NULL)
			return (print_fail(data, vars));
	}
	data.result = print_str(vars.str);
	return (data);
}

t_data	p_int_star_dot_num(const char *format, t_data data, va_list args)
{
	t_vars vars;

	data.format_detected = true;
	vars.i = 0;
	vars = vars_init(vars);
	vars.min_width = va_arg(args, int);
	vars.precision = ft_atoi(format + data.i_star_dot_num.j);
	vars.number = va_arg(args, int);
	vars = is_int_negative(vars);
	vars = int_num_dot_num_c(vars);
	if (vars.print_fail == true)
		return (print_fail(data, vars));
	vars.str_width = ft_strlen(vars.str);
	vars.i = 0;
	if (vars.str_width < vars.min_width)
	{
		vars.spaces = ft_strdup("");
		if (vars.spaces == NULL)
			return (print_fail(data, vars));
		vars = int_num_dot_num_b(data, vars);
		if (vars.str == NULL)
			return (print_fail(data, vars));
	}
	data.result = print_str(vars.str);
	return (data);
}

t_data	p_int_star_dot_star(t_data data, va_list args)
{
	t_vars vars;

	data.format_detected = true;
	vars.i = 0;
	vars = vars_init(vars);
	vars.min_width = va_arg(args, int);
	data = switch_negative(&vars.min_width, data);
	vars.precision = va_arg(args, int);
	vars.number = va_arg(args, int);
	vars = is_int_negative(vars);
	if (vars.precision < 0)
	{
		vars.prec_negative = true;
		vars.precision = 1;
	}
	vars = int_num_dot_num_c(vars);
	if (vars.print_fail == true)
		return (print_fail(data, vars));
	vars.str_width = ft_strlen(vars.str);
	vars.i = 0;
	if (vars.str_width < vars.min_width)
	{
		vars.spaces = ft_strdup("");
		if (vars.spaces == NULL)
			return (print_fail(data, vars));
		vars = int_num_dot_num_b(data, vars);
		if (vars.str == NULL)
			return (print_fail(data, vars));
	}
	data.result = print_str(vars.str);
	return (data);
}
