/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_ptr_utils_d.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/26 16:27:18 by idonado       #+#    #+#                 */
/*   Updated: 2020/06/26 17:42:01 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_vars	ptr_nds_vars(char *str, t_vars vars, t_data data, va_list args)
{
	vars = vars_init(vars);
	vars.min_width = ft_atoi(str + data.i_num_dot_num.i);
	vars.precision = va_arg(args, int);
	vars.ulnumber = va_arg(args, unsigned long);
	vars.ptr = ft_strdup("0x");
	if (vars.ulnumber == 0)
		vars.str = ft_strdup("");
	else
		vars.str = ft_hexgen_long(vars.ulnumber);
	return (vars);
}

t_vars	ptr_sdn_vars(char *str, t_vars vars, t_data data, va_list args)
{
	vars = vars_init(vars);
	vars.min_width = va_arg(args, int);
	vars.precision = ft_atoi(str + data.i_num_dot_num.j);
	vars.ulnumber = va_arg(args, unsigned long);
	vars.ptr = ft_strdup("0x");
	if (vars.ulnumber == 0)
		vars.str = ft_strdup("");
	else
		vars.str = ft_hexgen_long(vars.ulnumber);
	return (vars);
}

t_vars	ptr_sds_vars(t_vars vars, va_list args)
{
	vars = vars_init(vars);
	vars.min_width = va_arg(args, int);
	vars.precision = va_arg(args, int);
	vars.ulnumber = va_arg(args, unsigned long);
	vars.ptr = ft_strdup("0x");
	if (vars.ulnumber == 0)
		vars.str = ft_strdup("");
	else
		vars.str = ft_hexgen_long(vars.ulnumber);
	return (vars);
}

t_vars	ptr_ds_vars(t_vars vars, va_list args)
{
	vars = vars_init(vars);
	vars.precision = va_arg(args, int);
	if (vars.precision < 0)
		vars.precision = 1;
	vars.ulnumber = va_arg(args, unsigned long);
	vars.ptr = ft_strdup("0x");
	if (vars.ulnumber == 0)
		vars.str = ft_strdup("");
	else
		vars.str = ft_hexgen_long(vars.ulnumber);
	return (vars);
}
