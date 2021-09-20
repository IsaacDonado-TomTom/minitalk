/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minitalk_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/01 17:55:22 by idonado       #+#    #+#                 */
/*   Updated: 2021/09/04 19:58:26 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

static char	*ft_joinchr_b(char c)
{
	char	*add;

	add = (char *)malloc(sizeof(char) * 2);
	if (!add)
		return (NULL);
	add[0] = c;
	add[1] = '\0';
	return (add);
}

/*
*/
char	*ft_joinchr(char *str, char c)
{
	char	*new_str;
	int		i;

	if (!c)
		return (NULL);
	if (!str)
		return (ft_joinchr_b(c));
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!new_str)
	{
		free(str);
		return (NULL);
	}
	i = -1;
	while (str[++i])
		new_str[i] = str[i];
	free(str);
	new_str[i++] = c;
	new_str[i] = '\0';
	return (new_str);
}
