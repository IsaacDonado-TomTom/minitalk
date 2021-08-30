/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_mwidth.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/14 15:40:03 by idonado       #+#    #+#                 */
/*   Updated: 2020/06/22 17:31:22 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	check_mwidth(const char *format, t_data data)
{
	size_t i;

	i = data.i;
	if (ft_isdigit(format[i]))
	{
		data.i_mwidth.i = i;
		while (ft_isdigit(format[i]))
			i++;
	}
	if (i != data.i)
	{
		data.mwidth = true;
		data.i = i;
	}
	return (data);
}
