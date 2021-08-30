/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_uint_utils_c.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/26 15:42:57 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/01 17:56:26 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	p_uint_star(t_data data, va_list args)
{
	t_vars	vars;

	data.format_detected = true;
	vars.i = 0;
	vars = vars_init(vars);
	vars.min_width = va_arg(args, int);
	data = switch_negative(&vars.min_width, data);
	vars.unumber = va_arg(args, unsigned int);
	vars.str = ft_itoa_unsigned(vars.unumber);
	if (vars.str == NULL)
		return (print_fail(data, vars));
	vars.str_width = ft_strlen(vars.str);
	if (vars.str_width < vars.min_width)
	{
		vars.spaces = ft_strdup("");
		if (vars.spaces == NULL)
			return (print_fail(data, vars));
		vars.min_width = vars.min_width - vars.str_width;
		vars = uint_mwidth(data, vars);
		if (vars.str == NULL)
			return (print_fail(data, vars));
	}
	data.result = print_str(vars.str);
	free(vars.str);
	return (data);
}

t_data	p_uint_dot_star(t_data data, va_list args)
{
	t_vars vars;

	data.format_detected = true;
	vars.i = 0;
	vars = vars_init(vars);
	vars.precision = va_arg(args, int);
	if (vars.precision < 0)
		vars.precision = 1;
	vars.unumber = va_arg(args, unsigned int);
	vars.str = ft_itoa_unsigned(vars.unumber);
	if (vars.str == NULL)
		return (print_fail(data, vars));
	vars.str_width = ft_strlen(vars.str);
	if (vars.unumber == 0 && vars.precision == 0)
		vars.str[0] = '\0';
	else if (vars.str_width < vars.precision)
	{
		vars.spaces = ft_strdup("");
		if (vars.spaces == NULL)
			return (print_fail(data, vars));
		vars = uint_dot_num(vars);
		if (vars.str == NULL)
			return (print_fail(data, vars));
	}
	data.result = print_str(vars.str);
	free(vars.str);
	return (data);
}

t_data	p_uint_dot_num(const char *format, t_data data, va_list args)
{
	t_vars vars;

	data.format_detected = true;
	vars.i = 0;
	vars = vars_init(vars);
	vars.precision = ft_atoi(format + data.i_dot_num.i);
	vars.unumber = va_arg(args, unsigned int);
	vars.str = ft_itoa_unsigned(vars.unumber);
	if (vars.str == NULL)
		return (print_fail(data, vars));
	vars.str_width = ft_strlen(vars.str);
	if (vars.unumber == 0 && vars.precision == 0)
		vars.str[0] = '\0';
	else if (vars.str_width < vars.precision)
	{
		vars.spaces = ft_strdup("");
		if (vars.spaces == NULL)
			return (print_fail(data, vars));
		vars = uint_dot_num(vars);
		if (vars.str == NULL)
			return (print_fail(data, vars));
	}
	data.result = print_str(vars.str);
	free(vars.str);
	return (data);
}

t_vars	uint_sd_vars(t_vars vars, t_data data, va_list args)
{
	vars = vars_init(vars);
	vars.min_width = va_arg(args, int);
	data = switch_negative(&vars.min_width, data);
	vars.unumber = va_arg(args, unsigned int);
	vars.str = ft_itoa_unsigned(vars.unumber);
	if (vars.unumber == 0)
		vars.str[0] = '\0';
	return (vars);
}
