/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minitalk_client.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/01 19:29:06 by idonado       #+#    #+#                 */
/*   Updated: 2021/09/04 21:40:39 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H
# include <signal.h>
# include <stdlib.h>
# include <libft.h>
# include <unistd.h>

int		is_pid_digit(char *pid);
void	if_kill_returns_zero(int pid);

#endif