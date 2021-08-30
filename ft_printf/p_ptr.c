/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_ptr.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/28 16:37:13 by idonado       #+#    #+#                 */
/*   Updated: 2020/06/26 17:11:55 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	p_ptr_num_dot_star(const char *format, t_data data, va_list args)
{
	t_vars vars;

	data.format_detected = true;
	vars.i = 0;
	vars = ptr_nds_vars((char*)format, vars, data, args);
	if (vars.str == NULL || vars.ptr == NULL)
		return (print_fail(data, vars));
	vars.str_width = ft_strlen(vars.str);
	if (vars.str_width < vars.precision)
		vars = ptr_double_precision(vars);
	if (vars.str_width < vars.min_width)
		vars = ptr_double_mwidth(data, vars);
	if (vars.str != NULL && vars.ptr_trigger == 0)
		vars.str = smart_join(vars.ptr, vars.str);
	if (vars.str == NULL)
		return (print_fail(data, vars));
	data.result = print_str(vars.str);
	free(vars.str);
	return (data);
}

t_data	p_ptr_star_dot_num(const char *format, t_data data, va_list args)
{
	t_vars vars;

	data.format_detected = true;
	vars.i = 0;
	vars = ptr_sdn_vars((char*)format, vars, data, args);
	if (vars.str == NULL || vars.ptr == NULL)
		return (print_fail(data, vars));
	vars.str_width = ft_strlen(vars.str);
	if (vars.str_width < vars.precision)
		vars = ptr_double_precision(vars);
	if (vars.str_width < vars.min_width)
		vars = ptr_double_mwidth(data, vars);
	if (vars.str != NULL && vars.ptr_trigger == 0)
		vars.str = smart_join(vars.ptr, vars.str);
	if (vars.str == NULL)
		return (print_fail(data, vars));
	data.result = print_str(vars.str);
	free(vars.str);
	return (data);
}

t_data	p_ptr_star_dot_star(t_data data, va_list args)
{
	t_vars vars;

	data.format_detected = true;
	vars.i = 0;
	vars = ptr_sds_vars(vars, args);
	if (vars.str == NULL || vars.ptr == NULL)
		return (print_fail(data, vars));
	vars.str_width = ft_strlen(vars.str);
	if (vars.str_width < vars.precision)
		vars = ptr_double_precision(vars);
	if (vars.str_width < vars.min_width)
		vars = ptr_double_mwidth(data, vars);
	if (vars.str != NULL && vars.ptr_trigger == 0)
		vars.str = smart_join(vars.ptr, vars.str);
	if (vars.str == NULL)
		return (print_fail(data, vars));
	data.result = print_str(vars.str);
	free(vars.str);
	return (data);
}

t_data	check_ptr(const char *format, t_data data, va_list args)
{
	if (data.mwidth == true)
		data = p_ptr_mwidth(format, data, args);
	else if (data.star == true)
		data = p_ptr_star(data, args);
	else if (data.num_dot == true)
		data = p_ptr_num_dot(format, data, args);
	else if (data.num_dot_star == true)
		data = p_ptr_num_star(data, args);
	else if (data.dot == true)
		data = p_ptr_dot(data, args);
	else if (data.dot_num == true)
		data = p_ptr_dot_num(format, data, args);
	else if (data.dot_star == true)
		data = p_ptr_dot_star(data, args);
	else if (data.num_dot_num == true)
		data = p_ptr_num_dot_num(format, data, args);
	else if (data.num_dot_star == true)
		data = p_ptr_num_dot_star(format, data, args);
	return (data);
}

t_data	p_ptr(const char *format, t_data data, va_list args)
{
	t_vars vars;

	data.format_detected = false;
	vars.i = 0;
	vars = vars_init(vars);
	data = check_ptr(format, data, args);
	if (data.star_dot_num == true)
		data = p_ptr_star_dot_num(format, data, args);
	else if (data.star_dot_star == true)
		data = p_ptr_star_dot_star(data, args);
	else if (data.format_detected == false)
	{
		vars.ulnumber = va_arg(args, long unsigned);
		if (vars.ulnumber == 0)
			vars.str = ft_strdup("0");
		else
			vars.str = ft_hexgen_long(vars.ulnumber);
		vars.ptr = ft_strdup("0x");
		vars.str = smart_join(vars.ptr, vars.str);
		if (vars.str == NULL)
			return (print_fail(data, vars));
		data.result = print_str(vars.str);
	}
	return (data);
}
