/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_pct.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/21 18:55:01 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/01 17:12:59 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	t_data	p_pct_mwidth(char *format, t_data data, va_list args, int star)
{
	t_vars vars;

	data.format_detected = true;
	vars.i = 0;
	vars = vars_init(vars);
	vars.min_width = ft_atoi(format + data.i_mwidth.i);
	if (star == 1)
		vars.precision = va_arg(args, int);
	vars.str = ft_strdup("%");
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
	free(vars.str);
	return (data);
}

static	t_data	p_pct_star(t_data data, va_list args, int star)
{
	t_vars vars;

	data.format_detected = true;
	vars.i = 0;
	vars = vars_init(vars);
	vars.min_width = va_arg(args, int);
	if (star == 1)
		vars.precision = va_arg(args, int);
	data = switch_negative(&vars.min_width, data);
	vars.str = ft_strdup("%");
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
	free(vars.str);
	return (data);
}

static	t_data	p_pct_ds(t_data data, va_list args)
{
	data.format_detected = true;
	va_arg(args, int);
	data.result = print_char('%');
	return (data);
}

static	t_data	p_check_pct(const char *format, t_data data, va_list args)
{
	if (data.mwidth == true)
		data = p_pct_mwidth((char*)format, data, args, 0);
	else if (data.star == true)
		data = p_pct_star(data, args, 0);
	else if (data.dot_star == true)
		data = p_pct_ds(data, args);
	else if (data.num_dot == true)
	{
		data.i_mwidth.i = data.i_num_dot.i;
		data = p_pct_mwidth((char*)format, data, args, 0);
	}
	else if (data.num_dot_num == true)
	{
		data.i_mwidth.i = data.i_num_dot_num.i;
		data = p_pct_mwidth((char*)format, data, args, 0);
	}
	return (data);
}

t_data			p_pct(const char *format, t_data data, va_list args)
{
	data.format_detected = false;
	data = p_check_pct(format, data, args);
	if (data.star_dot == true)
		data = p_pct_star(data, args, 0);
	else if (data.star_dot_num == true)
		data = p_pct_star(data, args, 0);
	else if (data.num_dot_star == true)
	{
		data.i_mwidth.i = data.i_num_dot_star.i;
		data = p_pct_mwidth((char*)format, data, args, 1);
	}
	else if (data.star_dot_star == true)
		data = p_pct_star(data, args, 1);
	else if (data.format_detected == false)
		data.result = print_char('%');
	return (data);
}
