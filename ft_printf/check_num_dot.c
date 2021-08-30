/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_num_dot.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/12 17:36:04 by idonado       #+#    #+#                 */
/*   Updated: 2020/06/22 17:31:36 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	check_num_dot(const char *format, t_data data)
{
	size_t i;

	i = data.i;
	if (!ft_isdigit(format[i]))
		return (data);
	if (ft_isdigit(format[i]))
		data.i_num_dot.i = i;
	while (ft_isdigit(format[i]))
		i++;
	if (format[i] == '.' && format[i + 1] != '*' && !ft_isdigit(format[i + 1]))
	{
		data.i = i + 1;
		data.num_dot = true;
		data.check_combo = true;
		return (data);
	}
	return (data);
}
