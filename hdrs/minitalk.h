/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minitalk.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/31 17:14:57 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/31 20:39:17 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define FALSE 0
# define TRUE 1
# define ERROR -1
# define MAX_CHARS 4096
# define _XOPEN_SOURCE 700
# define INT_BITS 32
# define CHAR_BITS 8

# include <libft.h>
# include <ft_printf.h>
# include <signal.h>

// For server
typedef struct s_sig_data
{
	char	buffer[MAX_CHARS];
	int		index;
}				t_sig_data;

#endif