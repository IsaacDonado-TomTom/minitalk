/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_star_dot_num.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/22 17:32:36 by idonado       #+#    #+#                 */
/*   Updated: 2020/06/22 17:32:38 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	check_star_dot_num(const char *format, t_data data)
{
	size_t i;

	i = data.i;
	if (format[i] == '*' && format[i + 1] == '.' && ft_isdigit(format[i + 2]))
	{
		data.i = data.i + 2;
		data.i_star_dot_num.i = i + 2;
		while (ft_isdigit(format[data.i]))
			data.i++;
		data.star_dot_num = true;
		data.check_combo = true;
		return (data);
	}
	return (data);
}
