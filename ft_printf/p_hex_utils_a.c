/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_hex_utils_a.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 19:42:15 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/01 15:49:55 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	p_hex_ndn(const char *format, t_data data, va_list args, int cap)
{
	t_vars vars;

	data.format_detected = true;
	vars.i = 0;
	vars = hex_ndn_var(format, vars, args, data);
	if (vars.unumber == 0)
		vars.str = ft_strdup("");
	else
		vars = hex_capital_check(vars, cap);
	if (vars.str == NULL)
		return (print_fail(data, vars));
	vars.str_width = ft_strlen(vars.str);
	if (vars.str_width < vars.precision)
		vars = hex_double_precision(vars);
	if (vars.str != NULL)
		vars.str_width = ft_strlen(vars.str);
	vars.i = 0;
	if (vars.str_width < vars.min_width)
		vars = hex_double_mwidth(data, vars);
	if (vars.str == NULL)
		return (print_fail(data, vars));
	data.result = print_str(vars.str);
	free(vars.str);
	return (data);
}

t_data	p_hex_nds(const char *format, t_data data, va_list args, int cap)
{
	t_vars vars;

	data.format_detected = true;
	vars.i = 0;
	vars = hex_nds_var(format, vars, args, data);
	if (vars.unumber == 0)
		vars.str = ft_strdup("");
	else
		vars = hex_capital_check(vars, cap);
	if (vars.str == NULL)
		return (print_fail(data, vars));
	vars.str_width = ft_strlen(vars.str);
	if (vars.str_width < vars.precision)
		vars = hex_double_precision(vars);
	if (vars.str != NULL)
		vars.str_width = ft_strlen(vars.str);
	vars.i = 0;
	if (vars.str_width < vars.min_width)
		vars = hex_double_mwidth(data, vars);
	if (vars.str == NULL)
		return (print_fail(data, vars));
	data.result = print_str(vars.str);
	free(vars.str);
	return (data);
}

t_data	p_hex_sdn(const char *format, t_data data, va_list args, int cap)
{
	t_vars vars;

	data.format_detected = true;
	vars.i = 0;
	vars = hex_sdn_var(format, vars, args, data);
	if (vars.unumber == 0)
		vars.str = ft_strdup("");
	else
		vars = hex_capital_check(vars, cap);
	if (vars.str == NULL)
		return (print_fail(data, vars));
	vars.str_width = ft_strlen(vars.str);
	if (vars.str_width < vars.precision)
		vars = hex_double_precision(vars);
	if (vars.str != NULL)
		vars.str_width = ft_strlen(vars.str);
	vars.i = 0;
	if (vars.str_width < vars.min_width)
		vars = hex_double_mwidth(data, vars);
	if (vars.str == NULL)
		return (print_fail(data, vars));
	data.result = print_str(vars.str);
	free(vars.str);
	return (data);
}

t_data	p_hex_sds(t_data data, va_list args, int cap)
{
	t_vars vars;

	data.format_detected = true;
	vars.i = 0;
	vars = hex_sds_var(vars, args, data, cap);
	if (vars.str == NULL)
		return (print_fail(data, vars));
	vars.str_width = ft_strlen(vars.str);
	if (vars.str_width < vars.precision)
		vars = hex_double_precision(vars);
	if (vars.str != NULL)
		vars.str_width = ft_strlen(vars.str);
	vars.i = 0;
	if (vars.str_width < vars.min_width)
		vars = hex_double_mwidth(data, vars);
	if (vars.str == NULL)
		return (print_fail(data, vars));
	data.result = print_str(vars.str);
	free(vars.str);
	return (data);
}

t_data	p_hex_sd(t_data data, va_list args, int cap)
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
