/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loginshell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 13:46:29 by sid-bell          #+#    #+#             */
/*   Updated: 2019/11/10 13:46:38 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

char	*ft_getloginshell(char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		if (ft_strnequ(env[i], "SHELL=", 6))
			return (env[i] + 6);
		i++;
	}
	return ("/bin/sh");
}
