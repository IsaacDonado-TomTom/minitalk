/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils_b.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/26 15:12:44 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/01 21:51:00 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_vars		vars_init(t_vars vars)
{
	vars.ptr_trigger = 0;
	vars.is_negative = false;
	vars.prec_negative = false;
	vars.str = NULL;
	vars.spaces = NULL;
	vars.zeroes = NULL;
	vars.ptr = NULL;
	vars.print_fail = false;
	return (vars);
}

int			type_check(const char *format, size_t end)
{
	if (format[end] == 'c')
		return (1);
	else if (format[end] == 's')
		return (2);
	else if (format[end] == 'p')
		return (3);
	else if (format[end] == 'd' || format[end] == 'i')
		return (4);
	else if (format[end] == 'u')
		return (5);
	else if (format[end] == 'x')
		return (6);
	else if (format[end] == 'X')
		return (7);
	else if (format[end] == '%')
		return (8);
	return (0);
}

t_data		switch_negative(int *mwidth, t_data data)
{
	if (*mwidth < 0)
	{
		*mwidth = *mwidth * -1;
		data.left = true;
	}
	return (data);
}

t_data		print_fail(t_data data, t_vars vars)
{
	data.result = -1;
	if (vars.spaces != NULL)
		free(vars.spaces);
	if (vars.str != NULL)
		free(vars.str);
	if (vars.zeroes != NULL)
		free(vars.zeroes);
	if (vars.ptr != NULL)
		free(vars.zeroes);
	return (data);
}
