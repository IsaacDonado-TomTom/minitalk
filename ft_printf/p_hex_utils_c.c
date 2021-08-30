/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_hex_utils_c.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/26 15:14:45 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/01 15:45:55 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_vars	hex_capital_check(t_vars vars, int capital)
{
	if (capital == 0)
		vars.str = ft_hexgen(vars.unumber, 0);
	else
		vars.str = ft_hexgen(vars.unumber, 1);
	return (vars);
}

t_vars	hex_sds_var(t_vars vars, va_list args, t_data data, int cap)
{
	vars = vars_init(vars);
	vars.min_width = va_arg(args, int);
	data = switch_negative(&vars.min_width, data);
	vars.precision = va_arg(args, int);
	if (vars.precision < 0)
		vars.precision = 1;
	vars.unumber = va_arg(args, unsigned int);
	if (vars.unumber == 0)
		vars.str = ft_strdup("");
	else
		vars = hex_capital_check(vars, cap);
	return (vars);
}

t_vars	hex_sdn_var(const char *format, t_vars vars, va_list args, t_data data)
{
	vars = vars_init(vars);
	vars.min_width = va_arg(args, int);
	data = switch_negative(&vars.min_width, data);
	vars.precision = ft_atoi(format + data.i_star_dot_num.i);
	vars.unumber = va_arg(args, unsigned int);
	return (vars);
}

t_vars	hex_nds_var(const char *format, t_vars vars, va_list args, t_data data)
{
	vars = vars_init(vars);
	vars.min_width = ft_atoi(format + data.i_num_dot_star.i);
	vars.precision = va_arg(args, int);
	if (vars.precision < 0)
		vars.precision = 1;
	vars.unumber = va_arg(args, unsigned int);
	return (vars);
}

t_vars	hex_ndn_var(const char *format, t_vars vars, va_list args, t_data data)
{
	vars = vars_init(vars);
	vars.min_width = ft_atoi(format + data.i_num_dot_num.i);
	vars.precision = ft_atoi(format + data.i_num_dot_num.j);
	vars.unumber = va_arg(args, unsigned int);
	return (vars);
}
