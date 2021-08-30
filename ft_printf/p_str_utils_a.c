/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_str_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 20:59:04 by idonado       #+#    #+#                 */
/*   Updated: 2020/06/26 15:06:08 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_vars	str_double_precision(t_data data, t_vars vars)
{
	vars.str[vars.precision] = '\0';
	if ((int)ft_strlen(vars.str) < vars.min_width)
	{
		vars.min_width = vars.min_width - (int)ft_strlen(vars.str);
		vars.spaces = ft_strdup("");
		while (vars.i < vars.min_width)
		{
			vars.spaces = ft_chrjoin(vars.spaces, ' ');
			vars.i++;
		}
		if (data.left == true)
			vars.str = smart_join(vars.str, vars.spaces);
		else
			vars.str = smart_join(vars.spaces, vars.str);
	}
	return (vars);
}

t_vars	str_double_mwidth(t_data data, t_vars vars)
{
	vars.min_width = vars.min_width - (int)ft_strlen(vars.str);
	vars.i = 0;
	vars.spaces = ft_strdup("");
	while (vars.i < vars.min_width)
	{
		vars.spaces = ft_chrjoin(vars.spaces, ' ');
		vars.i++;
	}
	if (data.left == true)
		vars.str = smart_join(vars.str, vars.spaces);
	else
		vars.str = smart_join(vars.spaces, vars.str);
	return (vars);
}

t_data	str_mwidth(t_vars vars, t_data data)
{
	vars.str_width = vars.min_width - vars.str_width;
	vars.spaces = ft_strdup("");
	while (vars.i < vars.str_width)
	{
		vars.spaces = data.zeroes == true && data.left == false \
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
