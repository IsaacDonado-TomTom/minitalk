/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wipe_struct.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/11 15:23:35 by idonado       #+#    #+#                 */
/*   Updated: 2020/06/22 18:41:58 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	wipe_struct(t_data flags_struct)
{
	flags_struct.left = false;
	flags_struct.zeroes = false;
	flags_struct.mwidth = false;
	flags_struct.dot = false;
	flags_struct.dot_num = false;
	flags_struct.dot_star = false;
	flags_struct.star = false;
	flags_struct.star_dot = false;
	flags_struct.star_dot_num = false;
	flags_struct.star_dot_star = false;
	flags_struct.num_dot = false;
	flags_struct.num_dot_num = false;
	flags_struct.num_dot_star = false;
	flags_struct.check_combo = false;
	return (flags_struct);
}
