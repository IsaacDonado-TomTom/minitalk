/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_hex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 18:16:40 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/01 15:42:48 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_data	p_hex_sd(t_data data, va_list args, int cap)
{
	t_vars vars;

	data.format_detected = true;
	vars.i = 0;
	vars = vars_init(vars);
	vars.min_width = va_arg(args, int);
	data = switch_negative(&vars.min_width, data);
	vars.unumber = va_arg(args, unsigned int);
	if (vars.unumber == 0)
		vars.str = ft_strdup("");
	else
		vars = hex_capital_check(vars, cap);
	if (vars.str == NULL)
		return (print_fail(data, vars));
	vars.str_width = ft_strlen(vars.str);
	if (vars.str_width < vars.min_width)
		vars = hex_nd(data, vars);
	if (vars.str == NULL)
		return (print_fail(data, vars));
	data.result = print_str(vars.str);
	free(vars.str);
	return (data);
}

static t_data	p_hex_dot(t_data data, va_list args, int cap)
{
	t_vars vars;

	data.format_detected = true;
	vars.i = 0;
	vars = vars_init(vars);
	vars.unumber = va_arg(args, unsigned int);
	if (vars.unumber == 0)
		vars.str = ft_strdup("");
	else
		vars = hex_capital_check(vars, cap);
	if (vars.str == NULL)
		return (print_fail(data, vars));
	data.result = print_str(vars.str);
	free(vars.str);
	return (data);
}

static	t_data	check_a(const char *format, t_data data, va_list args, int cap)
{
	if (data.mwidth == true)
		data = p_hex_mwidth(format, data, args, cap);
	else if (data.star == true)
		data = p_hex_star(data, args, cap);
	else if (data.dot_star == true)
		data = p_hex_ds(data, args, cap);
	else if (data.dot_num == true)
		data = p_hex_dn(format, data, args, cap);
	else if (data.num_dot == true)
		data = p_hex_nd(format, data, args, cap);
	else if (data.star_dot == true)
		data = p_hex_sd(data, args, cap);
	else if (data.dot == true)
		data = p_hex_dot(data, args, cap);
	return (data);
}

t_data			p_hex(const char *format, t_data data, va_list args, int cap)
{
	char	*str;

	data.format_detected = false;
	data = check_a(format, data, args, cap);
	if (data.num_dot_num == true)
		data = p_hex_ndn(format, data, args, cap);
	else if (data.num_dot_star == true)
		data = p_hex_nds(format, data, args, cap);
	else if (data.star_dot_num == true)
		data = p_hex_sdn(format, data, args, cap);
	else if (data.star_dot_star == true)
		data = p_hex_sds(data, args, cap);
	else if (data.format_detected == false)
	{
		if (cap == 0)
			str = ft_hexgen(va_arg(args, unsigned int), 0);
		else
			str = ft_hexgen(va_arg(args, unsigned int), 1);
		data.result = print_str(str);
		free(str);
	}
	return (data);
}
