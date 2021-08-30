/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_num_dot_num.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/22 18:39:15 by idonado       #+#    #+#                 */
/*   Updated: 2020/06/22 18:39:21 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	check_num_dot_num(const char *format, t_data data)
{
	size_t i;

	i = data.i;
	if (!ft_isdigit(format[i]))
		return (data);
	if (ft_isdigit(format[i]))
		data.i_num_dot_num.i = i;
	while (ft_isdigit(format[i]))
		i++;
	if (format[i] == '.' && ft_isdigit(format[i + 1]))
	{
		i = i + 1;
		data.i_num_dot_num.j = i;
		while (ft_isdigit(format[i]))
			i++;
		data.i = i;
		data.num_dot_num = true;
		data.check_combo = true;
		return (data);
	}
	return (data);
}
