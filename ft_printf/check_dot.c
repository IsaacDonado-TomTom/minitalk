/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_dot.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/12 16:24:29 by idonado       #+#    #+#                 */
/*   Updated: 2020/06/22 17:28:52 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	check_dot(const char *format, t_data data)
{
	size_t i;

	i = data.i;
	if (format[i] == '.')
	{
		if (ft_isdigit(format[i + 1]))
			return (data);
		else if (format[i + 1] == '*')
			return (data);
		else
		{
			data.dot = true;
			data.check_combo = true;
			data.i = data.i + 1;
			return (data);
		}
	}
	return (data);
}
