/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_data.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 15:42:48 by idonado       #+#    #+#                 */
/*   Updated: 2020/06/26 16:39:15 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	print_data(const char *format, t_data data, va_list args)
{
	if (data.type_id == 2)
		data = p_str(format, data, args);
	else if (data.type_id == 1)
		data = p_char(format, data, args);
	else if (data.type_id == 3)
		data = p_ptr(format, data, args);
	else if (data.type_id == 4)
		data = p_int(format, data, args);
	else if (data.type_id == 5)
		data = p_uint(format, data, args);
	else if (data.type_id == 6)
		data = p_hex(format, data, args, 0);
	else if (data.type_id == 7)
		data = p_hex(format, data, args, 1);
	else if (data.type_id == 8)
		data = p_pct(format, data, args);
	return (data);
}
