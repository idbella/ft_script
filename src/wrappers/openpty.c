/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openpty.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 23:05:26 by sid-bell          #+#    #+#             */
/*   Updated: 2019/11/10 00:49:56 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

int		ft_openpty(int *master, int *slave)
{
	char	name[256];

	if ((*master = open("/dev/ptmx", O_RDWR)) < 0)
	{
		ft_printf_fd(2, "cannot create a new pty master\n");
		return (0);
	}
	if (!ft_grantpt(*master))
		return (0);
	if (!ft_unlockpt(*master))
		return (0);
	if ((ft_ptsname(*master, name)))
	{
		if ((*slave = open(name, O_RDWR)) < 0)
		{
			ft_printf_fd(2, "cannot open ttys %s\n", name);
			return (0);
		}
	}
	return (1);
}
